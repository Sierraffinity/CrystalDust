#include "global.h"
#include "day_night.h"
#include "decoration_inventory.h"
#include "event_data.h"
#include "item.h"
#include "main.h"
#include "match_call.h"
#include "menu.h"
#include "phone_script.h"
#include "pokegear.h"
#include "random.h"
#include "rtc.h"
#include "script.h"
#include "string_util.h"
#include "task.h"
#include "text.h"

typedef void (*PhoneNativeFunc)(const struct PhoneContact *phoneContact, bool8 isCallingPlayer);

EWRAM_DATA u16 gPhoneCallWindowId = 0;
EWRAM_DATA u16 gPhoneCallerNameWindowId = 0;
EWRAM_DATA u8 gPhoneCallSpriteId = 0;
static EWRAM_DATA u16 sPauseCounter = 0;

static u8 sPhoneScriptContextStatus;
static bool8 sPhoneScriptContextEnabled;
static struct ScriptContext sPhoneScriptContext;

extern ScrCmdFunc gPhoneScriptCmdTable[];
extern ScrCmdFunc gPhoneScriptCmdTableEnd[];

static const u8 sScriptConditionTable[6][3] =
{
//  <  =  >
    1, 0, 0, // <
    0, 1, 0, // =
    0, 0, 1, // >
    1, 1, 0, // <=
    0, 1, 1, // >=
    1, 0, 1, // !=
};

static void HangupPhoneCall(u32 phoneContext);
static bool8 WaitForHangupAnimation(void);

void PhoneScriptContext_Enable(void)
{
    sPhoneScriptContextEnabled = TRUE;
}

void PhoneScriptContext_Disable(void)
{
    sPhoneScriptContextEnabled = FALSE;
}

bool8 PhoneScriptContext_IsEnabled(void)
{
    return sPhoneScriptContextEnabled;
}

bool8 PhoneScriptContext_RunScript(void)
{
    if (sPhoneScriptContextStatus == 2)
        return 0;

    if (sPhoneScriptContextStatus == 1)
        return 0;

    PhoneScriptContext_Enable();

    if (!RunScriptCommand(&sPhoneScriptContext))
    {
        sPhoneScriptContextStatus = 2;
        PhoneScriptContext_Disable();
        return 0;
    }

    return 1;
}

void PhoneScriptContext_SetupPhoneScript(const struct PhoneContact *contact, u32 callContext)
{
    InitScriptContext(&sPhoneScriptContext, gPhoneScriptCmdTable, gPhoneScriptCmdTableEnd);
    SetupBytecodeScript(&sPhoneScriptContext, contact->phoneScript);
    PhoneScriptContext_Enable();
    sPhoneScriptContext.data[0] = callContext;
    sPhoneScriptContext.data[1] = (u32)contact;
    sPhoneScriptContext.data[2] = 0;
    sPhoneScriptContext.data[3] = 0;
    sPhoneScriptContextStatus = 0;
}

void PhoneScriptContext_SetupCustomPhoneScript(const u8 *script, u32 callContext)
{
    InitScriptContext(&sPhoneScriptContext, gPhoneScriptCmdTable, gPhoneScriptCmdTableEnd);
    SetupBytecodeScript(&sPhoneScriptContext, script);
    PhoneScriptContext_Enable();
    sPhoneScriptContext.data[0] = callContext;
    sPhoneScriptContext.data[1] = 0;
    sPhoneScriptContext.data[2] = 0;
    sPhoneScriptContext.data[3] = 0;
    sPhoneScriptContextStatus = 0;
}

static bool8 StopPhoneScript(struct ScriptContext *ctx)
{
    StopScript(ctx);
    if (ctx->data[0] == PHONE_SCRIPT_OVERWORLD)
    {
        SetupNativeScript(ctx, WaitForHangupAnimation);
        return TRUE;
    }
    return FALSE;
}

bool8 PhoneScrCmd_nop(struct ScriptContext *ctx)
{
    return FALSE;
}

bool8 PhoneScrCmd_end(struct ScriptContext *ctx)
{
    return StopPhoneScript(ctx);
}

static bool8 IsPokegearPhoneInitFinished(void)
{
    if (!FuncIsActiveTask(InitPokegearPhoneCall))
        return TRUE;
    else
        return FALSE;
}

static bool8 IsOverworldPhoneInitFinished(void)
{
    if (!FuncIsActiveTask(InitOverworldPhoneCall))
        return TRUE;
    else
        return FALSE;
}

bool8 PhoneScrCmd_initcall(struct ScriptContext *ctx)
{
    gSpecialVar_Result = TRUE;

    switch (ctx->data[0])
    {
    case PHONE_SCRIPT_POKEGEAR:
        CreateTask(InitPokegearPhoneCall, 3);
        SetupNativeScript(ctx, IsPokegearPhoneInitFinished);
        break;
    case PHONE_SCRIPT_OVERWORLD:
        CreateTask(InitOverworldPhoneCall, 3);
        SetupNativeScript(ctx, IsOverworldPhoneInitFinished);
        break;
    default:
        // Invalid phone context
        return FALSE;
    }

    return TRUE;
}

static bool8 IsPokegearPhoneMessageFinished(void)
{
    if (!IsTextPrinterActive(gPhoneCallWindowId))
        return TRUE;
    else
        return FALSE;
}

static bool8 IsOverworldPhoneMessageFinished(void)
{
    if (!ExecuteMatchCallTextPrinter(gPhoneCallWindowId))
        return TRUE;
    else
        return FALSE;
}

static void AddPhoneTextPrinter(struct ScriptContext *ctx, u8 *str)
{
    switch (ctx->data[0])
    {
    case PHONE_SCRIPT_POKEGEAR:
        AddTextPrinterParameterized(gPhoneCallWindowId, 1, str, 32, 1, GetPlayerTextSpeedDelay(), NULL);
        SetupNativeScript(ctx, IsPokegearPhoneMessageFinished);
        break;
    case PHONE_SCRIPT_OVERWORLD:
        InitMatchCallTextPrinter(gPhoneCallWindowId, str);
        SetupNativeScript(ctx, IsOverworldPhoneMessageFinished);
        break;
    }
}

bool8 PhoneScrCmd_message(struct ScriptContext *ctx)
{
    const u8 *str = (const u8 *)ScriptReadWord(ctx);
    StringExpandPlaceholders(gStringVar4, str);
    AddPhoneTextPrinter(ctx, gStringVar4);
    return TRUE;
}

bool8 PhoneScrCmd_hangup(struct ScriptContext *ctx)
{
    HangupPhoneCall(ctx->data[0]);
    return FALSE;
}

bool8 PhoneScrCmd_setflag(struct ScriptContext *ctx)
{
    FlagSet(ScriptReadHalfword(ctx));
    return FALSE;
}

bool8 PhoneScrCmd_clearflag(struct ScriptContext *ctx)
{
    FlagClear(ScriptReadHalfword(ctx));
    return FALSE;
}

bool8 PhoneScrCmd_checkflag(struct ScriptContext *ctx)
{
    ctx->comparisonResult = FlagGet(ScriptReadHalfword(ctx));
    return FALSE;
}

bool8 PhoneScrCmd_setvar(struct ScriptContext *ctx)
{
    u16 *ptr = GetVarPointer(ScriptReadHalfword(ctx));
    *ptr = ScriptReadHalfword(ctx);
    return FALSE;
}

bool8 PhoneScrCmd_addvar(struct ScriptContext *ctx)
{
    u16 *ptr = GetVarPointer(ScriptReadHalfword(ctx));
    *ptr += ScriptReadHalfword(ctx);
    return FALSE;
}

bool8 PhoneScrCmd_subvar(struct ScriptContext *ctx)
{
    u16 *ptr = GetVarPointer(ScriptReadHalfword(ctx));
    *ptr -= VarGet(ScriptReadHalfword(ctx));
    return FALSE;
}

bool8 PhoneScrCmd_copyvar(struct ScriptContext *ctx)
{
    u16 *ptr = GetVarPointer(ScriptReadHalfword(ctx));
    *ptr = *GetVarPointer(ScriptReadHalfword(ctx));
    return FALSE;
}

bool8 PhoneScrCmd_random(struct ScriptContext *ctx)
{
    u16 max = VarGet(ScriptReadHalfword(ctx));
    gSpecialVar_Result = Random() % max;
    return FALSE;
}

bool8 PhoneScrCmd_givepcitem(struct ScriptContext *ctx)
{
    u16 itemId = VarGet(ScriptReadHalfword(ctx));
    u16 quantity = VarGet(ScriptReadHalfword(ctx));

    gSpecialVar_Result = AddPCItem(itemId, quantity);
    return FALSE;
}

bool8 PhoneScrCmd_checkpcitem(struct ScriptContext *ctx)
{
    u16 itemId = VarGet(ScriptReadHalfword(ctx));
    u16 quantity = VarGet(ScriptReadHalfword(ctx));

    gSpecialVar_Result = CheckPCHasItem(itemId, quantity);
    return FALSE;
}

bool8 PhoneScrCmd_givedecoration(struct ScriptContext *ctx)
{
    u32 decorId = VarGet(ScriptReadHalfword(ctx));

    gSpecialVar_Result = DecorationAdd(decorId);
    return FALSE;
}

bool8 PhoneScrCmd_takedecoration(struct ScriptContext *ctx)
{
    u32 decorId = VarGet(ScriptReadHalfword(ctx));

    gSpecialVar_Result = DecorationRemove(decorId);
    return FALSE;
}

bool8 PhoneScrCmd_checkdecorspace(struct ScriptContext *ctx)
{
    u32 decorId = VarGet(ScriptReadHalfword(ctx));

    gSpecialVar_Result = DecorationCheckSpace(decorId);
    return FALSE;
}

bool8 PhoneScrCmd_checkdecor(struct ScriptContext *ctx)
{
    u32 decorId = VarGet(ScriptReadHalfword(ctx));

    gSpecialVar_Result = CheckHasDecoration(decorId);
    return FALSE;
}

static bool8 RunPauseTimer(void)
{
    sPauseCounter--;

    if (sPauseCounter == 0)
        return TRUE;
    else
        return FALSE;
}

bool8 PhoneScrCmd_delay(struct ScriptContext *ctx)
{
    sPauseCounter = ScriptReadHalfword(ctx);
    SetupNativeScript(ctx, RunPauseTimer);
    return TRUE;
}

bool8 PhoneScrCmd_goto(struct ScriptContext *ctx)
{
    const u8 *ptr = (const u8 *)ScriptReadWord(ctx);

    ScriptJump(ctx, ptr);
    return FALSE;
}

bool8 PhoneScrCmd_call(struct ScriptContext *ctx)
{
    const u8 *ptr = (const u8 *)ScriptReadWord(ctx);

    ScriptCall(ctx, ptr);
    return FALSE;
}

bool8 PhoneScrCmd_goto_if(struct ScriptContext *ctx)
{
    u8 condition = ScriptReadByte(ctx);
    const u8 *ptr = (const u8 *)ScriptReadWord(ctx);

    if (sScriptConditionTable[condition][ctx->comparisonResult] == 1)
        ScriptJump(ctx, ptr);
    return FALSE;
}

bool8 PhoneScrCmd_call_if(struct ScriptContext *ctx)
{
    u8 condition = ScriptReadByte(ctx);
    const u8 *ptr = (const u8 *)ScriptReadWord(ctx);

    if (sScriptConditionTable[condition][ctx->comparisonResult] == 1)
        ScriptCall(ctx, ptr);
    return FALSE;
}

bool8 PhoneScrCmd_return(struct ScriptContext *ctx)
{
    ScriptReturn(ctx);
    return FALSE;
}

bool8 PhoneScrCmd_gettime(struct ScriptContext *ctx)
{
    RtcCalcLocalTime();
    gSpecialVar_0x8000 = gLocalTime.hours;
    gSpecialVar_0x8001 = gLocalTime.minutes;
    gSpecialVar_0x8002 = GetCurrentTimeOfDay();
    gSpecialVar_0x8003 = gLocalTime.dayOfWeek;
    return FALSE;
}

static bool8 WaitForAorBPress(void)
{
    if (gMain.newKeys & (A_BUTTON | B_BUTTON))
        return TRUE;
    else
        return FALSE;
}

bool8 PhoneScrCmd_waitbuttonpress(struct ScriptContext *ctx)
{
    SetupNativeScript(ctx, WaitForAorBPress);
    return TRUE;
}

bool8 PhoneScrCmd_end_if_not_available(struct ScriptContext *ctx)
{
    if (!gSpecialVar_Result)
    {
        HangupPhoneCall(ctx->data[0]);
        return StopPhoneScript(ctx);
    }
    return FALSE;
}

static bool8 WaitForHangupAnimation(void)
{
    if (!IsHangupAnimationTaskActive())
    {
        EnableBothScriptContexts();
        return TRUE;
    }
    return FALSE;
}

static void HangupPhoneCall(u32 phoneContext)
{
    switch (phoneContext)
    {
    case PHONE_SCRIPT_POKEGEAR:
        HangupPokegearPhoneCall();
        break;
    case PHONE_SCRIPT_OVERWORLD:
        HangupOverworldPhoneCall();
        break;
    }
}

bool8 PhoneScrCmd_callnativecontext(struct ScriptContext *ctx)
{
    struct PhoneScriptExtraContext *phoneCtx = (void *)ctx->data[0];

    PhoneNativeFunc func = (PhoneNativeFunc)ScriptReadWord(ctx);
    bool8 isCallingPlayer = ctx->data[0] == PHONE_SCRIPT_OVERWORLD;
    func((const struct PhoneContact *)ctx->data[1], isCallingPlayer);
    return FALSE;
}
