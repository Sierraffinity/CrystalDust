#include "global.h"
#include "day_night.h"
#include "decoration_inventory.h"
#include "event_data.h"
#include "item.h"
#include "main.h"
#include "match_call.h"
#include "menu.h"
#include "money.h"
#include "phone_script.h"
#include "pokegear.h"
#include "pokemon_storage_system.h"
#include "random.h"
#include "region_map.h"
#include "rtc.h"
#include "script.h"
#include "script_menu.h"
#include "sound.h"
#include "string_util.h"
#include "task.h"
#include "text.h"
#include "tv.h"
#include "constants/songs.h"

typedef void (*PhoneNativeFunc)(const struct PhoneContact *phoneContact, bool8 isCallingPlayer);

EWRAM_DATA u16 gPhoneCallWindowId = 0;
EWRAM_DATA u16 gPhoneCallerNameWindowId = 0;
//EWRAM_DATA u8 gPhoneCallSpriteId = 0;
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

static const u8 sHangUpText[] = _("{PLAY_SE SE_PHONE_CLICK}Click!\n{PAUSE 25}{PLAY_SE SE_PHONE_BEEP}… {PAUSE 40}{PLAY_SE SE_PHONE_BEEP}… {PAUSE 40}{PLAY_SE SE_PHONE_BEEP}…{PAUSE 40}");

static bool8 HangupPhoneCall(struct ScriptContext *ctx, bool8 shouldEndNow);
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

void PhoneScriptContext_Stop(void)
{
    sPhoneScriptContextStatus = 1;
}

void PhoneScriptContext_Start(void)
{
    sPhoneScriptContextStatus = 0;
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
    if (!FuncIsActiveTask(Task_InitPokegearPhoneCall))
        return TRUE;
    else
        return FALSE;
}

static bool8 IsOverworldPhoneInitFinished(void)
{
    if (!FuncIsActiveTask(Task_InitOverworldPhoneCall))
        return TRUE;
    else
        return FALSE;
}

bool8 PhoneScrCmd_initcall(struct ScriptContext *ctx)
{
    gSpecialVar_Result = PHONE_CALL_SUCCESS;

    switch (ctx->data[0])
    {
    case PHONE_SCRIPT_POKEGEAR:
        CreateTask(Task_InitPokegearPhoneCall, 3);
        SetupNativeScript(ctx, IsPokegearPhoneInitFinished);
        break;
    case PHONE_SCRIPT_OVERWORLD:
        CreateTask(Task_InitOverworldPhoneCall, 3);
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
    AddTextPrinterParameterized5(gPhoneCallWindowId, 2, str, 2, 1, GetPlayerTextSpeedDelay(), NULL, 1, 2);

    switch (ctx->data[0])
    {
    case PHONE_SCRIPT_POKEGEAR:
        SetupNativeScript(ctx, IsPokegearPhoneMessageFinished);
        break;
    case PHONE_SCRIPT_OVERWORLD:
        SetupNativeScript(ctx, IsOverworldPhoneMessageFinished);
        break;
    }
}

bool8 PhoneScrCmd_message(struct ScriptContext *ctx)
{
    const u8 *str = (const u8 *)ScriptReadWord(ctx);
    FillWindowPixelBuffer(gPhoneCallWindowId, PIXEL_FILL(1));
    StringExpandPlaceholders(gStringVar4, str);
    AddPhoneTextPrinter(ctx, gStringVar4);
    return TRUE;
}

bool8 PhoneScrCmd_hangup(struct ScriptContext *ctx)
{
    return HangupPhoneCall(ctx, PHONE_CALL_SUCCESS);
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
    if (JOY_NEW(A_BUTTON | B_BUTTON))
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
    if (gSpecialVar_Result != PHONE_CALL_SUCCESS)
    {
        return HangupPhoneCall(ctx, gSpecialVar_Result);
    }
    return FALSE;
}

static bool8 WaitForHangupAnimation(void)
{
    if (CleanupAfterMatchCallHangup())
    {
        return TRUE;
    }
    return FALSE;
}

#define tState          data[0]
#define tPhoneCallState data[1]
#define tScriptCtx      ((struct ScriptContext **)&gTasks[taskId].data[2])

static void EndPhoneCall(u8 callLocation)
{
    switch (callLocation)
    {
    case PHONE_SCRIPT_POKEGEAR:
        EndPokegearPhoneCall();
        break;
    case PHONE_SCRIPT_OVERWORLD:
        EndOverworldPhoneCall();
        break;
    }
}

static void Task_HangupPhoneCall(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    struct ScriptContext *ctx = *tScriptCtx;

    switch (tState)
    {
    case 0:
        FillWindowPixelBuffer(gPhoneCallWindowId, PIXEL_FILL(1));
        AddTextPrinterParameterized5(gPhoneCallWindowId, 2, sHangUpText, 2, 1, 0, NULL, 1, 1);
        tState++;
        break;
    case 1:
        switch (ctx->data[0])
        {
        case PHONE_SCRIPT_POKEGEAR:
            if (IsPokegearPhoneMessageFinished())
            {
                tState++;
            }
            break;
        case PHONE_SCRIPT_OVERWORLD:
            if (IsOverworldPhoneMessageFinished())
            {
                tState++;
            }
            break;
        }
        break;
    default:
        EndPhoneCall(ctx->data[0]);
        if (tPhoneCallState == PHONE_CALL_FAIL)
        {
            StopPhoneScript(ctx);
        }
        DestroyTask(taskId);
        break;
    }
}

static bool8 WaitForHangupTask(void)
{
    return !FuncIsActiveTask(Task_HangupPhoneCall);
}

static bool8 HangupPhoneCall(struct ScriptContext *ctx, u8 phoneCallState)
{
    u8 taskId;

    if (phoneCallState != PHONE_CALL_FAIL_SILENT)
    {
        u8 taskId = CreateTask(Task_HangupPhoneCall, 80);

        if (taskId != 0xFF)
        {
            gTasks[taskId].tState = 0;
            gTasks[taskId].tPhoneCallState = phoneCallState;
            *tScriptCtx = ctx;
            SetupNativeScript(ctx, WaitForHangupTask);
            return TRUE;
        }
    }
    
    EndPhoneCall(ctx->data[0]);
    return StopPhoneScript(ctx);
}

#undef tState
#undef tCallLocation
#undef tPhoneCallState

bool8 PhoneScrCmd_callnativecontext(struct ScriptContext *ctx)
{
    //struct PhoneScriptExtraContext *phoneCtx = (void *)ctx->data[0];

    PhoneNativeFunc func = (PhoneNativeFunc)ScriptReadWord(ctx);
    bool8 isCallingPlayer = ctx->data[0] == PHONE_SCRIPT_OVERWORLD;
    func((const struct PhoneContact *)ctx->data[1], isCallingPlayer);
    return FALSE;
}

static void Task_HandlePhoneYesNoInput(u8 taskId)
{
    if (gTasks[taskId].data[2] < 5)
    {
        gTasks[taskId].data[2]++;
        return;
    }

    switch (Menu_ProcessInputNoWrapClearOnChoose())
    {
    case MENU_NOTHING_CHOSEN:
        return;
    case MENU_B_PRESSED:
    case 1:
        PlaySE(SE_SELECT);
        gSpecialVar_Result = 0;
        break;
    case 0:
        gSpecialVar_Result = 1;
        break;
    }

    DestroyTask(taskId);
    PhoneScriptContext_Start();
    PhoneCard_RefreshContactList();
}

static const struct WindowTemplate sPhoneYesNo_WindowTemplates[] =
{
    {
        .bg = 0,
        .tilemapLeft = 21,
        .tilemapTop = 9,
        .width = 6,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 0x289
    },
    {
        .bg = 0,
        .tilemapLeft = 21,
        .tilemapTop = 9,
        .width = 6,
        .height = 4,
        .paletteNum = 14,
        .baseBlock = 0x289
    }
};

static void DisplayPhoneYesNoMenu(u8 initialPos, u32 callType)
{
    switch (callType)
    {
    case PHONE_SCRIPT_OVERWORLD:
        CreatePhoneYesNoMenu(&sPhoneYesNo_WindowTemplates[0], 2, 0, 2, 0x270, 15, initialPos, TRUE);
        break;
    case PHONE_SCRIPT_POKEGEAR:
        CreatePhoneYesNoMenu(&sPhoneYesNo_WindowTemplates[1], 2, 0, 2, 0x143, 14, initialPos, FALSE);
        break;
    }
}

static bool8 DoPhoneYesNoBox(u8 left, u8 top, u32 callType)
{
    u8 taskId;

    if (FuncIsActiveTask(Task_HandlePhoneYesNoInput) == TRUE)
    {
        return FALSE;
    }
    else
    {
        gSpecialVar_Result = 0xFF;
        DisplayPhoneYesNoMenu(0, callType);
        taskId = CreateTask(Task_HandlePhoneYesNoInput, 0x50);
        return TRUE;
    }
}

bool8 PhoneScrCmd_yesnobox(struct ScriptContext *ctx)
{
    if (DoPhoneYesNoBox(20, 8, ctx->data[0]) == TRUE)
    {
        PhoneScriptContext_Stop();
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

static u8 DoCompare(u16 a1, u16 a2)
{
    if (a1 < a2)
        return 0;
    if (a1 == a2)
        return 1;
    return 2;
}

bool8 PhoneScrCmd_compare_local_to_local(struct ScriptContext *ctx)
{
    const u8 value1 = ctx->data[ScriptReadByte(ctx)];
    const u8 value2 = ctx->data[ScriptReadByte(ctx)];

    ctx->comparisonResult = DoCompare(value1, value2);
    return FALSE;
}

bool8 PhoneScrCmd_compare_local_to_value(struct ScriptContext *ctx)
{
    const u8 value1 = ctx->data[ScriptReadByte(ctx)];
    const u8 value2 = ScriptReadByte(ctx);

    ctx->comparisonResult = DoCompare(value1, value2);
    return FALSE;
}

bool8 PhoneScrCmd_compare_local_to_addr(struct ScriptContext *ctx)
{
    const u8 value1 = ctx->data[ScriptReadByte(ctx)];
    const u8 value2 = *(const u8 *)ScriptReadWord(ctx);

    ctx->comparisonResult = DoCompare(value1, value2);
    return FALSE;
}

bool8 PhoneScrCmd_compare_addr_to_local(struct ScriptContext *ctx)
{
    const u8 value1 = *(const u8 *)ScriptReadWord(ctx);
    const u8 value2 = ctx->data[ScriptReadByte(ctx)];

    ctx->comparisonResult = DoCompare(value1, value2);
    return FALSE;
}

bool8 PhoneScrCmd_compare_addr_to_value(struct ScriptContext *ctx)
{
    const u8 value1 = *(const u8 *)ScriptReadWord(ctx);
    const u8 value2 = ScriptReadByte(ctx);

    ctx->comparisonResult = DoCompare(value1, value2);
    return FALSE;
}

bool8 PhoneScrCmd_compare_addr_to_addr(struct ScriptContext *ctx)
{
    const u8 value1 = *(const u8 *)ScriptReadWord(ctx);
    const u8 value2 = *(const u8 *)ScriptReadWord(ctx);

    ctx->comparisonResult = DoCompare(value1, value2);
    return FALSE;
}

bool8 PhoneScrCmd_compare_var_to_value(struct ScriptContext *ctx)
{
    const u16 value1 = *GetVarPointer(ScriptReadHalfword(ctx));
    const u16 value2 = ScriptReadHalfword(ctx);

    ctx->comparisonResult = DoCompare(value1, value2);
    return FALSE;
}

bool8 PhoneScrCmd_compare_var_to_var(struct ScriptContext *ctx)
{
    const u16 *ptr1 = GetVarPointer(ScriptReadHalfword(ctx));
    const u16 *ptr2 = GetVarPointer(ScriptReadHalfword(ctx));

    ctx->comparisonResult = DoCompare(*ptr1, *ptr2);
    return FALSE;
}

bool8 PhoneScrCmd_getmapinfo(struct ScriptContext *ctx)
{
    gSpecialVar_0x8004 = gMapHeader.mapType;
    gSpecialVar_0x8005 = gMapHeader.regionMapSectionId;
    return FALSE;
}

bool8 PhoneScrCmd_buffermapsecname(struct ScriptContext *ctx)
{
    const u8 stringVarIndex = ScriptReadByte(ctx);
    const u16 mapSec = VarGet(ScriptReadHalfword(ctx));

    GetMapName(gScriptStringVars[stringVarIndex], mapSec, 0);

    return FALSE;
}

bool8 PhoneScrCmd_checkbankedmoney(struct ScriptContext *ctx)
{
    u32 amount = ScriptReadWord(ctx);

    gSpecialVar_Result = IsEnoughMoney(&gSaveBlock1Ptr->bankedMoney, amount);
    return FALSE;
}

bool8 PhoneScrCmd_bufferbankedmoney(struct ScriptContext *ctx)
{
    u8 stringVarIndex = ScriptReadByte(ctx);
    u32 num = GetMoney(&gSaveBlock1Ptr->bankedMoney);
    u8 numDigits = CountDigits(num);

    ConvertIntToDecimalStringN(gScriptStringVars[stringVarIndex], num, STR_CONV_MODE_LEFT_ALIGN, numDigits);
    return FALSE;
}

bool8 PhoneScrCmd_buffernumberstring(struct ScriptContext *ctx)
{
    u8 stringVarIndex = ScriptReadByte(ctx);
    u16 num = VarGet(ScriptReadHalfword(ctx));
    u8 numDigits = CountDigits(num);

    ConvertIntToDecimalStringN(gScriptStringVars[stringVarIndex], num, STR_CONV_MODE_LEFT_ALIGN, numDigits);
    return FALSE;
}

bool8 PhoneScrCmd_bufferboxname(struct ScriptContext *ctx)
{
    u8 stringVarIndex = ScriptReadByte(ctx);
    u16 boxId = VarGet(ScriptReadHalfword(ctx));

    StringCopy(gScriptStringVars[stringVarIndex], GetBoxNamePtr(boxId));
    return FALSE;
}
