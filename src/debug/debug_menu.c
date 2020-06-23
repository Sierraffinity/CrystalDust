#if DEBUG
#include "global.h"
#include "battle_transition.h"
#include "clock.h"
#include "daycare.h"
#include "day_night.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "event_object_lock.h"
#include "field_message_box.h"
#include "field_player_avatar.h"
#include "field_screen_effect.h"
#include "international_string_util.h"
#include "item.h"
#include "main.h"
#include "overworld.h"
#include "rtc.h"
#include "script.h"
#include "script_menu.h"
#include "sound.h"
#include "strings.h"
#include "string_util.h"
#include "task.h"
#include "window.h"
#include "constants/items.h"
#include "constants/flags.h"
#include "constants/heal_locations.h"
#include "constants/species.h"
#include "constants/songs.h"
#include "constants/vars.h"

struct DebugMenuAction;

struct DebugMenuBouncer
{
    u8 count;
    const struct DebugMenuAction *actions;
    const struct DebugMenuBouncer *prev;
};

struct DebugMenuAction
{
    const u8 *text;
    union {
        void (*void_u8)(u8);
        u8 (*u8_void)(void);
        void (*bounce)(u8, const struct DebugMenuBouncer *);
    } func;
    const struct DebugMenuBouncer *bouncer;
};

#define CREATE_EXIT_BOUNCER(actions) \
static const struct DebugMenuBouncer sDebugMenu_Bouncer_##actions = \
{\
    ARRAY_COUNT(sDebugMenu_##actions), sDebugMenu_##actions, NULL\
};

#define CREATE_BOUNCER(actions, prev) \
static const struct DebugMenuBouncer sDebugMenu_Bouncer_##actions = \
{\
    ARRAY_COUNT(sDebugMenu_##actions), sDebugMenu_##actions, &sDebugMenu_Bouncer_##prev\
};

static void HandleDebugMenuInput(u8 taskId);
static void DebugMenu_Exit(u8 taskId);
static void DebugMenu_PlayerInfo(u8 taskId);
static void DebugMenu_PlayerInfo_ProcessInput(u8 taskId);
static void DebugMenu_SetFlag(u8 taskId);
static void DebugMenu_SetFlag_ProcessInput(u8 taskId);
static void DebugMenu_SetVar(u8 taskId);
static void DebugMenu_SetVar_ProcessInputVar(u8 taskId);
static void DebugMenu_SetVar_ProcessInputVal(u8 taskId);
static void DebugMenu_AddItem(u8 taskId);
static void DebugMenu_AddItem_ProcessInput(u8 taskId);
static void DebugMenu_DN(u8 taskId);
static void DebugMenu_DN_ProcessInput(u8 taskId);
static void DebugMenu_Misc(u8 taskId);
static void DebugMenu_Misc_ProcessInput(u8 taskId);
static void DebugMenu_TimeCycle(u8 taskId);
static void DebugMenu_TimeCycle_ProcessInput(u8 taskId);
static void DebugMenu_ToggleRunningShoes(u8 taskId);
static void DebugMenu_EnableResetRTC(u8 taskId);
static void DebugMenu_TestBattleTransition(u8 taskId);
static void DebugMenu_SwapGender(u8 taskId);
static void DebugMenu_ToggleWalkThroughWalls(u8 taskId);
static void DebugMenu_ToggleOverride(u8 taskId);
static void DebugMenu_Pokedex_ProfOakRating(u8 taskId);
static void DebugMenu_Pokedex_ProfOakRating_ProcessInput(u8 taskId);
static void DebugMenu_Pokegear(u8 taskId);
static void DebugMenu_Pokegear_ProcessInput(u8 taskId);
static void DebugMenu_EnableMapCard(u8 taskId);
static void DebugMenu_EnableRadioCard(u8 taskId);
static void DebugMenu_SetRespawn(u8 taskId);
static void DebugMenu_SetRespawn_ProcessInput(u8 taskId);
static void DebugMenu_RemoveMenu(u8 taskId);
static void DebugMenu_InitNewSubmenu(u8 taskId, const struct DebugMenuBouncer *bouncer);
static void DebugMenu_Submenu_ProcessInput(u8 taskId);
static void ReturnToPreviousMenu(u8 taskId, const struct DebugMenuBouncer *bouncer);
static void DebugMenu_AddItem_ProcessInputNum(u8 taskId);
static void DebugMenu_AddItem_ProcessInputCount(u8 taskId);

extern bool8 gWalkThroughWalls;
extern bool8 gPaletteTintDisabled;
extern bool8 gPaletteOverrideDisabled;
extern s8 gDNHourOverride;

static const u8 sText_PlayerInfo[] = _("Player info");
static const u8 sText_SetFlag[] = _("Set flag");
static const u8 sText_SetVar[] = _("Set variable");
static const u8 sText_AddItem[] = _("Add item");
static const u8 sText_DayNight[] = _("Day/night");
static const u8 sText_Pokedex[] = _("Pokédex");
static const u8 sText_Pokegear[] = _("Pokégear");
static const u8 sText_SetRespawn[] = _("Set respawn");
static const u8 sText_Misc[] = _("Misc");
static const u8 sText_ToggleRunningShoes[] = _("Toggle running shoes");
static const u8 sText_EnableResetRTC[] = _("Enable reset RTC (B+SEL+LEFT)");
static const u8 sText_TestBattleTransition[] = _("Test battle transition");
static const u8 sText_CreateDaycareEgg[] = _("Create daycare egg");
static const u8 sText_GenderBender[] = _("Gender bender");
static const u8 sText_ToggleWalkThroughWalls[] = _("Toggle walk through walls");
static const u8 sText_ToggleDNPalOverride[] = _("Toggle pal override");
static const u8 sText_DNTimeCycle[] = _("Time cycle");
static const u8 sText_ProfOakRating[] = _("Prof. Oak rating");
static const u8 sText_EnableMapCard[] = _("Enable map card");
static const u8 sText_EnableRadioCard[] = _("Enable radio card");
static const u8 sText_DexCount[] = _("Count: {STR_VAR_1}");
static const u8 sText_FlagStatus[] = _("Flag: {STR_VAR_1}\nStatus: {STR_VAR_2}");
static const u8 sText_VarStatus[] = _("Var: {STR_VAR_1}\nValue: {STR_VAR_2}\nAddress: {STR_VAR_3}");
static const u8 sText_ItemStatus[] = _("Item: {STR_VAR_1}\nCount: {STR_VAR_2}");
static const u8 sText_ClockStatus[] = _("Time: {STR_VAR_1}");
static const u8 sText_RespawnStatus[] = _("Respawn point:\n{STR_VAR_1}");
static const u8 sText_On[] = _("{COLOR GREEN}ON");
static const u8 sText_Off[] = _("{COLOR RED}OFF");

extern u8 PokedexRating_EventScript_ShowRatingMessage[];

static const struct DebugMenuBouncer sDebugMenu_Bouncer_PlayerInfoActions;
static const struct DebugMenuBouncer sDebugMenu_Bouncer_DNActions;
static const struct DebugMenuBouncer sDebugMenu_Bouncer_PokedexActions;
static const struct DebugMenuBouncer sDebugMenu_Bouncer_PokegearActions;
static const struct DebugMenuBouncer sDebugMenu_Bouncer_MiscActions;

static const struct DebugMenuAction sDebugMenu_MainActions[] =
{
    { sText_PlayerInfo, { .bounce = DebugMenu_InitNewSubmenu }, &sDebugMenu_Bouncer_PlayerInfoActions },
    { sText_DayNight, { .bounce = DebugMenu_InitNewSubmenu }, &sDebugMenu_Bouncer_DNActions },
    { sText_Pokedex, { .bounce = DebugMenu_InitNewSubmenu }, &sDebugMenu_Bouncer_PokedexActions },
    { sText_Pokegear, { .bounce = DebugMenu_InitNewSubmenu }, &sDebugMenu_Bouncer_PokegearActions },
    { sText_SetRespawn, DebugMenu_SetRespawn, NULL },
    { sText_Misc, { .bounce = DebugMenu_InitNewSubmenu }, &sDebugMenu_Bouncer_MiscActions },
    { gText_MenuOptionExit, DebugMenu_Exit, NULL }
};

CREATE_EXIT_BOUNCER(MainActions);

static const struct DebugMenuAction sDebugMenu_PlayerInfoActions[] = 
{
    { sText_SetFlag, DebugMenu_SetFlag, NULL },
    { sText_SetVar, DebugMenu_SetVar, NULL },
    { sText_AddItem, DebugMenu_AddItem, NULL },
    { sText_GenderBender, DebugMenu_SwapGender, NULL },
};

CREATE_BOUNCER(PlayerInfoActions, MainActions);

static const struct DebugMenuAction sDebugMenu_DNActions[] =
{
    { sText_ToggleDNPalOverride, DebugMenu_ToggleOverride, NULL },
    { sText_DNTimeCycle, DebugMenu_TimeCycle, NULL },
};

CREATE_BOUNCER(DNActions, MainActions);

static const struct DebugMenuAction sDebugMenu_PokedexActions[] =
{
    { sText_ProfOakRating, DebugMenu_Pokedex_ProfOakRating, NULL },
};

CREATE_BOUNCER(PokedexActions, MainActions);

static const struct DebugMenuAction sDebugMenu_PokegearActions[] =
{
    { sText_EnableMapCard, DebugMenu_EnableMapCard, NULL },
    { sText_EnableRadioCard, DebugMenu_EnableRadioCard, NULL },
};

CREATE_BOUNCER(PokegearActions, MainActions);

static const struct DebugMenuAction sDebugMenu_MiscActions[] =
{
    { sText_ToggleWalkThroughWalls, DebugMenu_ToggleWalkThroughWalls, NULL },
    { sText_ToggleRunningShoes, DebugMenu_ToggleRunningShoes, NULL },
    { sText_EnableResetRTC, DebugMenu_EnableResetRTC, NULL },
    { sText_TestBattleTransition, DebugMenu_TestBattleTransition, NULL },
    { sText_CreateDaycareEgg, TriggerPendingDaycareEgg, NULL },
};

CREATE_BOUNCER(MiscActions, MainActions);

static const struct WindowTemplate sDebugMenu_Window_SetFlag = 
{
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 1,
    .width = 10,
    .height = 4,
    .paletteNum = 15,
    .baseBlock = 0x120
};

static const struct WindowTemplate sDebugMenu_Window_AddItem = 
{
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 1,
    .width = 10,
    .height = 4,
    .paletteNum = 15,
    .baseBlock = 0x120
};

static const struct WindowTemplate sDebugMenu_Window_SetVar = 
{
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 1,
    .width = 16,
    .height = 6,
    .paletteNum = 15,
    .baseBlock = 0x120
};

static const struct WindowTemplate sDebugMenu_Window_SetDexCount = 
{
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 1,
    .width = 8,
    .height = 2,
    .paletteNum = 15,
    .baseBlock = 0x120
};

static const struct WindowTemplate sDebugMenu_Window_TimeCycle = 
{
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 1,
    .width = 10,
    .height = 2,
    .paletteNum = 15,
    .baseBlock = 0x120
};

static const struct WindowTemplate sDebugMenu_Window_SetRespawn = 
{
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 1,
    .width = 10,
    .height = 4,
    .paletteNum = 15,
    .baseBlock = 0x120
};

#define tWindowId data[0]
#define SET_BOUNCER(x) (*((u32 *)(&data[14])) = (u32)(x))
#define GET_BOUNCER (const struct DebugMenuBouncer *)*((u32 *)(&data[14]))

static void DebugMenu_InitMainMenu(void)
{
    u8 taskId = CreateTask(DebugMenu_Submenu_ProcessInput, 80);
    s16 *data = gTasks[taskId].data;

    tWindowId = -1;
    DebugMenu_InitNewSubmenu(taskId, &sDebugMenu_Bouncer_MainActions);
}

void ShowDebugMenu(void)
{
    if (!IsUpdateLinkStateCBActive())
    {
        FreezeObjectEvents();
        sub_808B864();
        sub_808BCF4();
    }
    LoadMessageBoxAndBorderGfx();
    DebugMenu_InitMainMenu();
    ScriptContext2_Enable();
}

static int GetMaxWidthInDebugMenuTable(const struct DebugMenuAction *str, int arg1)
{
    int i, var;

    for (var = 0, i = 0; i < arg1; i++)
    {
        int stringWidth = GetStringWidth(1, str[i].text, 0);
        if (stringWidth > var)
            var = stringWidth;
    }

    return ConvertPixelWidthToTileWidth(var);
}

static void MultichoiceList_PrintDebugItems(u8 windowId, u8 fontId, u8 left, u8 top, u8 lineHeight, u8 itemCount, const struct DebugMenuAction *strs, u8 letterSpacing, u8 lineSpacing)
{
    u8 i;

    for (i = 0; i < itemCount; i++)
        AddTextPrinterParameterized5(windowId, fontId, strs[i].text, left, (lineHeight * i) + top, 0xFF, NULL, letterSpacing, lineSpacing);
    CopyWindowToVram(windowId, 2);
}

static void DebugMenu_InitNewSubmenu(u8 taskId, const struct DebugMenuBouncer *bouncer)
{
    s16 *data = gTasks[taskId].data;
    struct WindowTemplate windowTemplate = {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 1,
        .width = 0,
        .height = 0,
        .paletteNum = 15, 
        .baseBlock = 0x120
    };

    DebugMenu_RemoveMenu(taskId);
    windowTemplate.width = GetMaxWidthInDebugMenuTable(bouncer->actions, bouncer->count);
    windowTemplate.height = bouncer->count * 2;
    tWindowId = AddWindow(&windowTemplate);
    SetStandardWindowBorderStyle(tWindowId, FALSE);
    MultichoiceList_PrintDebugItems(tWindowId, 1, 8, 2, 16, bouncer->count, bouncer->actions, 0, 2);
    InitMenuInUpperLeftCornerPlaySoundWhenAPressed(tWindowId, 1, 0, 1, 16, bouncer->count, 0);
    schedule_bg_copy_tilemap_to_vram(0);
    SET_BOUNCER(bouncer);
    gTasks[taskId].func = DebugMenu_Submenu_ProcessInput;
}

static void ReturnToPreviousMenu(u8 taskId, const struct DebugMenuBouncer *bouncer)
{
    s16 *data = gTasks[taskId].data;

    if (bouncer)
    {
        DebugMenu_InitNewSubmenu(taskId, bouncer);
    }
    else
    {
        DebugMenu_Exit(taskId);
    }
}

static void DebugMenu_Submenu_ProcessInput(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    s8 inputOptionId = Menu_ProcessInput();

    const struct DebugMenuBouncer *bouncer = GET_BOUNCER;

    switch (inputOptionId)
    {
        case MENU_NOTHING_CHOSEN:
            break;
        case MENU_B_PRESSED:
            PlaySE(SE_SELECT);
            ReturnToPreviousMenu(taskId, bouncer->prev);
            break;
        default:
        {
            const struct DebugMenuAction *action = &bouncer->actions[inputOptionId];
            PlaySE(SE_SELECT);
            if (action->bouncer)
            {
                action->func.bounce(taskId, action->bouncer);
            }
            else
            {
                action->func.void_u8(taskId);
            }
            break;
        }
    }
}

static void DebugMenu_RemoveMenu(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (tWindowId >= 0)
    {
        ClearStdWindowAndFrameToTransparent(tWindowId, TRUE);
        RemoveWindow(tWindowId);
    }
}

static void DebugMenu_Exit(u8 taskId)
{
    DebugMenu_RemoveMenu(taskId);
    ScriptUnfreezeObjectEvents();
    ScriptContext2_Disable();
    DestroyTask(taskId);
}

static void DebugMenu_SetFlag_PrintStatus(u8 windowId, u16 flagId)
{
    FillWindowPixelBuffer(windowId, 0x11);
    ConvertIntToHexStringN(gStringVar1, flagId, STR_CONV_MODE_LEADING_ZEROS, 3);

    if (FlagGet(flagId))
        StringCopy(gStringVar2, sText_On);
    else
        StringCopy(gStringVar2, sText_Off);

    StringExpandPlaceholders(gStringVar4, sText_FlagStatus);
    AddTextPrinterParameterized5(windowId, 1, gStringVar4, 0, 1, 0, NULL, 0, 2);
}

#define tFlagNum data[1]
#define tWhichDigit data[2]

static void DebugMenu_SetFlag(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    DebugMenu_RemoveMenu(taskId);
    tWindowId = AddWindow(&sDebugMenu_Window_SetFlag);
    SetStandardWindowBorderStyle(tWindowId, FALSE);
    DebugMenu_SetFlag_PrintStatus(tWindowId, FLAG_TEMP_1);
    schedule_bg_copy_tilemap_to_vram(0);
    tFlagNum = FLAG_TEMP_1;
    tWhichDigit = 0;
    gTasks[taskId].func = DebugMenu_SetFlag_ProcessInput;
}

static void DebugMenu_SetFlag_ProcessInput(u8 taskId)
{
    u32 temp, shifter;
    u16 *data = gTasks[taskId].data;

    if (gMain.newAndRepeatedKeys & DPAD_UP)
    {
        shifter = tWhichDigit * 4;
        temp = (((tFlagNum >> shifter) & 0xF) + 1) & 0xF;
        temp = (tFlagNum & ~(0xF << shifter)) | (temp << shifter);

        if (temp >= FLAG_TEMP_1 && temp <= DAILY_FLAGS_END)
        {
            PlaySE(SE_SELECT);
            tFlagNum = temp;
            DebugMenu_SetFlag_PrintStatus(tWindowId, temp);
        }
    }

    if (gMain.newAndRepeatedKeys & DPAD_DOWN)
    {
        shifter = tWhichDigit * 4;
        temp = (((tFlagNum >> shifter) & 0xF) - 1) & 0xF;
        temp = (tFlagNum & ~(0xF << shifter)) | (temp << shifter);

        if (temp >= FLAG_TEMP_1 && temp <= DAILY_FLAGS_END)
        {
            PlaySE(SE_SELECT);
            tFlagNum = temp;
            DebugMenu_SetFlag_PrintStatus(tWindowId, temp);
        }
    }

    if (gMain.newAndRepeatedKeys & DPAD_LEFT)
    {
        if (++tWhichDigit > 2)
            tWhichDigit = 2;
        else
            PlaySE(SE_SELECT);
    }

    if (gMain.newAndRepeatedKeys & DPAD_RIGHT)
    {
        if (--tWhichDigit > 2)
            tWhichDigit = 0;
        else
            PlaySE(SE_SELECT);
    }

    if (gMain.newKeys & A_BUTTON)
    {
        PlaySE(SE_SELECT);

        if (FlagGet(tFlagNum))
            FlagClear(tFlagNum);
        else
            FlagSet(tFlagNum);

        DebugMenu_SetFlag_PrintStatus(tWindowId, tFlagNum);
    }

    if (gMain.newKeys & B_BUTTON)
    {
        PlaySE(SE_SELECT);
        ReturnToPreviousMenu(taskId, GET_BOUNCER);
    }
}

#undef tFlagNum
#undef tWhichDigit

static void DebugMenu_SetVar_PrintStatus(u8 windowId, u16 varId, u16 varVal)
{
    FillWindowPixelBuffer(windowId, 0x11);
    ConvertIntToHexStringN(gStringVar1, varId, STR_CONV_MODE_LEADING_ZEROS, 4);
    ConvertIntToHexStringN(gStringVar2, varVal, STR_CONV_MODE_LEADING_ZEROS, 4);
    ConvertIntToHexStringN(gStringVar3, (u32)GetVarPointer(varId), STR_CONV_MODE_LEADING_ZEROS, 8);
    StringExpandPlaceholders(gStringVar4, sText_VarStatus);
    AddTextPrinterParameterized5(windowId, 1, gStringVar4, 0, 1, 0, NULL, 0, 2);
}

#define tVarNum data[1]
#define tVarVal data[2]
#define tWhichDigit data[3]

static void DebugMenu_SetVar(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    DebugMenu_RemoveMenu(taskId);
    tWindowId = AddWindow(&sDebugMenu_Window_SetVar);
    SetStandardWindowBorderStyle(tWindowId, FALSE);
    tVarNum = VAR_TEMP_0;
    tVarVal = VarGet(VAR_TEMP_0);
    DebugMenu_SetVar_PrintStatus(tWindowId, tVarNum, tVarVal);
    schedule_bg_copy_tilemap_to_vram(0);
    tWhichDigit = 0;
    gTasks[taskId].func = DebugMenu_SetVar_ProcessInputVar;
}

static void DebugMenu_SetVar_ProcessInputVar(u8 taskId)
{
    u32 temp, shifter;
    u16 *data = gTasks[taskId].data;

    if (gMain.newAndRepeatedKeys & DPAD_UP)
    {
        shifter = tWhichDigit * 4;
        temp = (((tVarNum >> shifter) & 0xF) + 1) & 0xF;
        temp = (tVarNum & ~(0xF << shifter)) | (temp << shifter);

        if (temp >= VAR_TEMP_0 && temp <= VAR_UNUSED_0x40FF)
        {
            PlaySE(SE_SELECT);
            tVarNum = temp;
            tVarVal = VarGet(tVarNum);
            DebugMenu_SetVar_PrintStatus(tWindowId, tVarNum, tVarVal);
        }
    }

    if (gMain.newAndRepeatedKeys & DPAD_DOWN)
    {
        shifter = tWhichDigit * 4;
        temp = (((tVarNum >> shifter) & 0xF) - 1) & 0xF;
        temp = (tVarNum & ~(0xF << shifter)) | (temp << shifter);

        if (temp >= VAR_TEMP_0 && temp <= VAR_UNUSED_0x40FF)
        {
            PlaySE(SE_SELECT);
            tVarNum = temp;
            tVarVal = VarGet(tVarNum);
            DebugMenu_SetVar_PrintStatus(tWindowId, tVarNum, tVarVal);
        }
    }

    if (gMain.newAndRepeatedKeys & DPAD_LEFT)
    {
        if (++tWhichDigit > 3)
            tWhichDigit = 3;
        else
            PlaySE(SE_SELECT);
    }

    if (gMain.newAndRepeatedKeys & DPAD_RIGHT)
    {
        if (--tWhichDigit > 3)
            tWhichDigit = 0;
        else
            PlaySE(SE_SELECT);
    }

    if (gMain.newKeys & A_BUTTON)
    {
        PlaySE(SE_SELECT);
        tWhichDigit = 0;
        gTasks[taskId].func = DebugMenu_SetVar_ProcessInputVal;
    }

    if (gMain.newKeys & B_BUTTON)
    {
        PlaySE(SE_SELECT);
        ReturnToPreviousMenu(taskId, GET_BOUNCER);
    }
}

static void DebugMenu_SetVar_ProcessInputVal(u8 taskId)
{
    u32 temp, shifter;
    u16 *data = gTasks[taskId].data;

    if (gMain.newAndRepeatedKeys & DPAD_UP)
    {
        shifter = tWhichDigit * 4;
        temp = (((tVarVal >> shifter) & 0xF) + 1) & 0xF;
        temp = (tVarVal & ~(0xF << shifter)) | (temp << shifter);
        PlaySE(SE_SELECT);
        tVarVal = temp;
        DebugMenu_SetVar_PrintStatus(tWindowId, tVarNum, tVarVal);
    }

    if (gMain.newAndRepeatedKeys & DPAD_DOWN)
    {
        shifter = tWhichDigit * 4;
        temp = (((tVarVal >> shifter) & 0xF) - 1) & 0xF;
        temp = (tVarVal & ~(0xF << shifter)) | (temp << shifter);
        PlaySE(SE_SELECT);
        tVarVal = temp;
        DebugMenu_SetVar_PrintStatus(tWindowId, tVarNum, tVarVal);
    }

    if (gMain.newAndRepeatedKeys & DPAD_LEFT)
    {
        if (++tWhichDigit > 3)
            tWhichDigit = 3;
        else
            PlaySE(SE_SELECT);
    }

    if (gMain.newAndRepeatedKeys & DPAD_RIGHT)
    {
        if (--tWhichDigit > 3)
            tWhichDigit = 0;
        else
            PlaySE(SE_SELECT);
    }

    if (gMain.newKeys & A_BUTTON)
    {
        PlaySE(SE_SELECT);
        VarSet(tVarNum, tVarVal);
        DebugMenu_SetVar_PrintStatus(tWindowId, tVarNum, tVarVal);
        tWhichDigit = 0;
        gTasks[taskId].func = DebugMenu_SetVar_ProcessInputVar;
    }

    if (gMain.newKeys & B_BUTTON)
    {
        PlaySE(SE_SELECT);
        tWhichDigit = 0;
        gTasks[taskId].func = DebugMenu_SetVar_ProcessInputVar;
    }
}

#undef tVarNum
#undef tVarVal
#undef tWhichDigit

static void DebugMenu_AddItem_PrintStatus(u8 windowId, u16 itemId, u16 itemCount)
{
    FillWindowPixelBuffer(windowId, 0x11);
    ConvertIntToDecimalStringN(gStringVar1, itemId, STR_CONV_MODE_LEADING_ZEROS, 4);
    ConvertIntToDecimalStringN(gStringVar2, itemCount, STR_CONV_MODE_LEADING_ZEROS, 4);
    StringExpandPlaceholders(gStringVar4, sText_ItemStatus);
    AddTextPrinterParameterized5(windowId, 1, gStringVar4, 0, 1, 0, NULL, 0, 2);
}

#define tItemNum data[1]
#define tItemCount data[2]
#define tWhichDigit data[3]

static void DebugMenu_AddItem(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    DebugMenu_RemoveMenu(taskId);
    tWindowId = AddWindow(&sDebugMenu_Window_AddItem);
    SetStandardWindowBorderStyle(tWindowId, FALSE);
    tItemNum = ITEM_NONE;
    tItemCount = 1;
    DebugMenu_AddItem_PrintStatus(tWindowId, tItemNum, tItemCount);
    schedule_bg_copy_tilemap_to_vram(0);
    tWhichDigit = 0;
    gTasks[taskId].func = DebugMenu_AddItem_ProcessInputNum;
}

static const s32 powersOfTen[] =
{
    1,
    10,
    100,
    1000,
};

static void DebugMenu_AddItem_ProcessInputNum(u8 taskId)
{
    u32 temp, temp2, shifter;
    u16 *data = gTasks[taskId].data;

    if (gMain.newAndRepeatedKeys & DPAD_UP)
    {
        shifter = powersOfTen[tWhichDigit];

        temp = (tItemNum % powersOfTen[tWhichDigit]) + ((tItemNum / powersOfTen[tWhichDigit + 1]) * powersOfTen[tWhichDigit + 1]);
        temp2 = ((tItemNum - temp) / shifter) + 1;
        temp += (temp2 > 9) ? 0 : temp2 * shifter;
        
        if (temp <= ITEMS_COUNT)
        {
            PlaySE(SE_SELECT);
            tItemNum = temp;
            DebugMenu_AddItem_PrintStatus(tWindowId, tItemNum, tItemCount);
        }
    }

    if (gMain.newAndRepeatedKeys & DPAD_DOWN)
    {
        shifter = powersOfTen[tWhichDigit];

        temp = (tItemNum % powersOfTen[tWhichDigit]) + ((tItemNum / powersOfTen[tWhichDigit + 1]) * powersOfTen[tWhichDigit + 1]);
        temp2 = ((tItemNum - temp) / shifter) - 1;
        temp += (temp2 > 9) ? 9 * shifter : temp2 * shifter;
        
        if (temp <= ITEMS_COUNT)
        {
            PlaySE(SE_SELECT);
            tItemNum = temp;
            DebugMenu_AddItem_PrintStatus(tWindowId, tItemNum, tItemCount);
        }
    }

    if (gMain.newAndRepeatedKeys & DPAD_LEFT)
    {
        if (++tWhichDigit > 3)
            tWhichDigit = 3;
        else
            PlaySE(SE_SELECT);
    }

    if (gMain.newAndRepeatedKeys & DPAD_RIGHT)
    {
        if (--tWhichDigit > 3)
            tWhichDigit = 0;
        else
            PlaySE(SE_SELECT);
    }

    if (gMain.newKeys & A_BUTTON)
    {
        PlaySE(SE_SELECT);
        tWhichDigit = 0;
        gTasks[taskId].func = DebugMenu_AddItem_ProcessInputCount;
    }

    if (gMain.newKeys & B_BUTTON)
    {
        PlaySE(SE_SELECT);
        ReturnToPreviousMenu(taskId, GET_BOUNCER);
    }
}

static void DebugMenu_AddItem_ProcessInputCount(u8 taskId)
{
    u32 temp, shifter;
    u16 *data = gTasks[taskId].data;

    if (gMain.newAndRepeatedKeys & DPAD_UP)
    {
        shifter = tWhichDigit * 4;
        temp = (((tItemCount >> shifter) & 0xF) + 1) & 0xF;
        temp = (tItemCount & ~(0xF << shifter)) | (temp << shifter);
        if (temp > 255)
            temp = 1;
        PlaySE(SE_SELECT);
        tItemCount = temp;
        DebugMenu_AddItem_PrintStatus(tWindowId, tItemNum, tItemCount);
    }

    if (gMain.newAndRepeatedKeys & DPAD_DOWN)
    {
        shifter = tWhichDigit * 4;
        temp = (((tItemCount >> shifter) & 0xF) - 1) & 0xF;
        temp = (tItemCount & ~(0xF << shifter)) | (temp << shifter);
        if (temp < 1)
            temp = 255;
        PlaySE(SE_SELECT);
        tItemCount = temp;
        DebugMenu_AddItem_PrintStatus(tWindowId, tItemNum, tItemCount);
    }

    if (gMain.newAndRepeatedKeys & DPAD_LEFT)
    {
        if (++tWhichDigit > 3)
            tWhichDigit = 3;
        else
            PlaySE(SE_SELECT);
    }

    if (gMain.newAndRepeatedKeys & DPAD_RIGHT)
    {
        if (--tWhichDigit > 3)
            tWhichDigit = 0;
        else
            PlaySE(SE_SELECT);
    }

    if (gMain.newKeys & A_BUTTON)
    {
        PlaySE(SE_SELECT);
        AddBagItem(tItemNum, (u8)tItemCount);
        DebugMenu_AddItem_PrintStatus(tWindowId, tItemNum, tItemCount);
        tWhichDigit = 0;
        gTasks[taskId].func = DebugMenu_AddItem_ProcessInputNum;
    }

    if (gMain.newKeys & B_BUTTON)
    {
        PlaySE(SE_SELECT);
        tWhichDigit = 0;
        gTasks[taskId].func = DebugMenu_AddItem_ProcessInputNum;
    }
}

#undef tItemNum
#undef tItemCount
#undef tWhichDigit

static void DebugMenu_ToggleRunningShoes(u8 taskId)
{
    if (FlagGet(FLAG_SYS_B_DASH))
        FlagClear(FLAG_SYS_B_DASH);
    else
        FlagSet(FLAG_SYS_B_DASH);
}

static void DebugMenu_EnableResetRTC(u8 taskId)
{
    EnableResetRTC();
}

static void DebugMenu_TestBattleTransition(u8 taskId)
{
    TestBattleTransition(VarGet(0x4000));
}

static void DebugMenu_SwapGender(u8 taskId)
{
    gSaveBlock2Ptr->playerGender = !gSaveBlock2Ptr->playerGender;
    SetWarpDestination(gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum, -1, gSaveBlock1Ptr->pos.x, gSaveBlock1Ptr->pos.y);
    DoDiveWarp();
    ResetInitialPlayerAvatarState();
}

static void DebugMenu_ToggleWalkThroughWalls(u8 taskId)
{
    gWalkThroughWalls = !gWalkThroughWalls;
}

static void DebugMenu_ToggleOverride(u8 taskId)
{
    gPaletteOverrideDisabled = !gPaletteOverrideDisabled;
    ProcessImmediateTimeEvents();
}

static void DebugMenu_TimeCycle_PrintStatus(u8 windowId, u16 hour)
{
    FillWindowPixelBuffer(windowId, 0x11);
    WriteTimeString(gStringVar1, hour, 0, FALSE, TRUE);
    StringExpandPlaceholders(gStringVar4, sText_ClockStatus);
    AddTextPrinterParameterized5(windowId, 1, gStringVar4, 0, 1, 0, NULL, 0, 2);
}

static void DebugMenu_TimeCycle(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    DebugMenu_RemoveMenu(taskId);
    tWindowId = AddWindow(&sDebugMenu_Window_TimeCycle);
    SetStandardWindowBorderStyle(tWindowId, FALSE);
    DebugMenu_TimeCycle_PrintStatus(tWindowId, gLocalTime.hours);
    schedule_bg_copy_tilemap_to_vram(0);
    gDNHourOverride = gLocalTime.hours + 1;
    gTasks[taskId].func = DebugMenu_TimeCycle_ProcessInput;
}

static void DebugMenu_TimeCycle_ProcessInput(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (gMain.newAndRepeatedKeys & DPAD_UP)
    {
        PlaySE(SE_SELECT);
        if (++gDNHourOverride > 24)
            gDNHourOverride = 1;
        ProcessImmediateTimeEvents();
        DebugMenu_TimeCycle_PrintStatus(tWindowId, gDNHourOverride - 1);
    }

    if (gMain.newAndRepeatedKeys & DPAD_DOWN)
    {
        PlaySE(SE_SELECT);
        if (--gDNHourOverride < 1)
            gDNHourOverride = 24;
        ProcessImmediateTimeEvents();
        DebugMenu_TimeCycle_PrintStatus(tWindowId, gDNHourOverride - 1);
    }

    if (gMain.newKeys & A_BUTTON)
    {
        PlaySE(SE_SELECT);
        ReturnToPreviousMenu(taskId, GET_BOUNCER);
    }

    if (gMain.newKeys & B_BUTTON)
    {
        gDNHourOverride = 0;
        PlaySE(SE_SELECT);
        ReturnToPreviousMenu(taskId, GET_BOUNCER);
    }
}

static void DebugMenu_Pokedex_ProfOakRating_PrintStatus(u8 windowId, u16 flagId)
{
    FillWindowPixelBuffer(windowId, 0x11);
    ConvertUIntToDecimalStringN(gStringVar1, flagId, STR_CONV_MODE_LEADING_ZEROS, 3);

    StringExpandPlaceholders(gStringVar4, sText_DexCount);
    AddTextPrinterParameterized5(windowId, 1, gStringVar4, 0, 1, 0, NULL, 0, 2);
}

#define tDexCount data[1]
#define tWhichDigit data[2]

static void DebugMenu_Pokedex_ProfOakRating(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    DebugMenu_RemoveMenu(taskId);
    tWindowId = AddWindow(&sDebugMenu_Window_SetDexCount);
    SetStandardWindowBorderStyle(tWindowId, FALSE);
    DebugMenu_Pokedex_ProfOakRating_PrintStatus(tWindowId, 1);
    schedule_bg_copy_tilemap_to_vram(0);
    tDexCount = 1;
    tWhichDigit = 0;
    gTasks[taskId].func = DebugMenu_Pokedex_ProfOakRating_ProcessInput;
}

static void WaitForScript(u8 taskId)
{
    if (ScriptContext1_IsScriptSetUp() != TRUE)
    {
        PlaySE(SE_SELECT);
        HideFieldMessageBox();
        ScriptContext2_Enable();
        gTasks[taskId].func = *(void **)(&gTasks[taskId].data[4]);
    }
}

static void DebugMenu_Pokedex_ProfOakRating_ProcessInput(u8 taskId)
{
    u32 temp, temp2, shifter;
    u16 *data = gTasks[taskId].data;

    if (gMain.newAndRepeatedKeys & DPAD_UP)
    {
        shifter = powersOfTen[tWhichDigit];

        temp = (tDexCount % powersOfTen[tWhichDigit]) + ((tDexCount / powersOfTen[tWhichDigit + 1]) * powersOfTen[tWhichDigit + 1]);
        temp2 = ((tDexCount - temp) / shifter) + 1;
        temp += (temp2 > 9) ? 0 : temp2 * shifter;
        
        if (temp >= 1 && temp <= JOHTO_DEX_COUNT)
        {
            PlaySE(SE_SELECT);
            tDexCount = temp;
            DebugMenu_Pokedex_ProfOakRating_PrintStatus(tWindowId, temp);
        }
    }

    if (gMain.newAndRepeatedKeys & DPAD_DOWN)
    {
        shifter = powersOfTen[tWhichDigit];

        temp = (tDexCount % powersOfTen[tWhichDigit]) + ((tDexCount / powersOfTen[tWhichDigit + 1]) * powersOfTen[tWhichDigit + 1]);
        temp2 = ((tDexCount - temp) / shifter) - 1;
        temp += (temp2 > 9) ? 9 * shifter : temp2 * shifter;
        
        if (temp >= 1 && temp <= JOHTO_DEX_COUNT)
        {
            PlaySE(SE_SELECT);
            tDexCount = temp;
            DebugMenu_Pokedex_ProfOakRating_PrintStatus(tWindowId, temp);
        }
    }

    if (gMain.newAndRepeatedKeys & DPAD_LEFT)
    {
        if (++tWhichDigit > 2)
            tWhichDigit = 2;
        else
            PlaySE(SE_SELECT);
    }

    if (gMain.newAndRepeatedKeys & DPAD_RIGHT)
    {
        if (--tWhichDigit > 2)
            tWhichDigit = 0;
        else
            PlaySE(SE_SELECT);
    }

    if (gMain.newKeys & A_BUTTON)
    {
        PlaySE(SE_SELECT);
        VarSet(VAR_0x8009, tDexCount);

        gTasks[taskId].func = WaitForScript;
        *(void **)(&gTasks[taskId].data[4]) = DebugMenu_Pokedex_ProfOakRating_ProcessInput;
        ScriptContext1_SetupScript(PokedexRating_EventScript_ShowRatingMessage);
    }

    if (gMain.newKeys & B_BUTTON)
    {
        PlaySE(SE_SELECT);
        ReturnToPreviousMenu(taskId, GET_BOUNCER);
    }
}

#undef tDexCount
#undef tWhichDigit

static void DebugMenu_EnableMapCard(u8 taskId)
{
    FlagSet(FLAG_SYS_HAS_MAP_CARD);
}

static void DebugMenu_EnableRadioCard(u8 taskId)
{
    FlagSet(FLAG_SYS_HAS_RADIO_CARD);
}

static void DebugMenu_SetRespawn_PrintStatus(u8 windowId, u8 respawnPoint)
{
    FillWindowPixelBuffer(windowId, 0x11);
    ConvertIntToDecimalStringN(gStringVar1, respawnPoint, STR_CONV_MODE_LEFT_ALIGN, 2);
    StringExpandPlaceholders(gStringVar4, sText_RespawnStatus);
    AddTextPrinterParameterized5(windowId, 1, gStringVar4, 0, 1, 0, NULL, 0, 2);
}

#define tRespawnNum data[1]

static void DebugMenu_SetRespawn(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    DebugMenu_RemoveMenu(taskId);
    tWindowId = AddWindow(&sDebugMenu_Window_SetRespawn);
    SetStandardWindowBorderStyle(tWindowId, FALSE);
    DebugMenu_SetRespawn_PrintStatus(tWindowId, 1);
    schedule_bg_copy_tilemap_to_vram(0);
    tRespawnNum = HEAL_LOCATION_NEW_BARK_TOWN;
    gTasks[taskId].func = DebugMenu_SetRespawn_ProcessInput;
}

static void DebugMenu_SetRespawn_ProcessInput(u8 taskId)
{
    u32 temp, shifter;
    u16 *data = gTasks[taskId].data;

    if (gMain.newAndRepeatedKeys & DPAD_UP)
    {
        temp = tRespawnNum + 1;

        if (temp >= HEAL_LOCATION_NEW_BARK_TOWN && temp <= HEAL_LOCATION_BATTLE_FRONTIER_OUTSIDE_EAST)
        {
            PlaySE(SE_SELECT);
            tRespawnNum = temp;
            DebugMenu_SetRespawn_PrintStatus(tWindowId, tRespawnNum);
        }
    }

    if (gMain.newAndRepeatedKeys & DPAD_DOWN)
    {
        temp = tRespawnNum - 1;

        if (temp >= HEAL_LOCATION_NEW_BARK_TOWN && temp <= HEAL_LOCATION_BATTLE_FRONTIER_OUTSIDE_EAST)
        {
            PlaySE(SE_SELECT);
            tRespawnNum = temp;
            DebugMenu_SetRespawn_PrintStatus(tWindowId, tRespawnNum);
        }
    }

    if (gMain.newKeys & A_BUTTON)
    {
        PlaySE(SE_SELECT);
        SetLastHealLocationWarp(tRespawnNum);
    }

    if (gMain.newKeys & B_BUTTON)
    {
        PlaySE(SE_SELECT);
        ReturnToPreviousMenu(taskId, GET_BOUNCER);
    }
}

#endif
