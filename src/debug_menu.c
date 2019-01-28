#include "global.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "event_obj_lock.h"
#include "field_player_avatar.h"
#include "international_string_util.h"
#include "main.h"
#include "overworld.h"
#include "script.h"
#include "sound.h"
#include "strings.h"
#include "string_util.h"
#include "task.h"
#include "window.h"
#include "constants/flags.h"
#include "constants/songs.h"
#include "constants/vars.h"

static void HandleDebugMenuInput(u8 taskId);
static void DebugMenu_Exit(u8 taskId);
static void DebugMenu_SetFlag(u8 taskId);
static void DebugMenu_SetFlag_ProcessInput(u8 taskId);
static void DebugMenu_SetFlag_RemoveMenu(u8 taskId);
static void DebugMenu_SetVar(u8 taskId);
static void DebugMenu_SetVar_ProcessInput(u8 taskId);
static void DebugMenu_SetVar_RemoveMenu(u8 taskId);

static const u8 sText_SetFlag[] = _("Set flag");
static const u8 sText_SetVar[] = _("Set variable");
static const u8 sText_FlagStatus[] = _("Flag: {STR_VAR_1}\nStatus: {STR_VAR_2}");
static const u8 sText_VarStatus[] = _("Var: {STR_VAR_1}\nValue: {STR_VAR_2}\nAddress: {STR_VAR_3}");
static const u8 sText_On[] = _("{COLOR GREEN}ON");
static const u8 sText_Off[] = _("{COLOR RED}OFF");

static const struct MenuAction sDebugMenu_MainActions[] =
{
    { sText_SetFlag, DebugMenu_SetFlag },
    { sText_SetVar, DebugMenu_SetVar },
    { gText_MenuOptionExit, DebugMenu_Exit }
};

static const struct WindowTemplate sDebugMenu_Window_Main = 
{
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 1,
    .width = 0,
    .height = ARRAY_COUNT(sDebugMenu_MainActions) * 2,
    .paletteNum = 15,
    .baseBlock = 0x120
};

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

#define tWindowId data[0]

static void InitDebugMenu(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    struct WindowTemplate windowTemplate = sDebugMenu_Window_Main;

    windowTemplate.width = GetMaxWidthInMenuTable(sDebugMenu_MainActions, ARRAY_COUNT(sDebugMenu_MainActions));
    tWindowId = AddWindow(&windowTemplate);
    SetStandardWindowBorderStyle(tWindowId, FALSE);
    PrintMenuTable(tWindowId, ARRAY_COUNT(sDebugMenu_MainActions), sDebugMenu_MainActions);
    InitMenuInUpperLeftCornerPlaySoundWhenAPressed(tWindowId, ARRAY_COUNT(sDebugMenu_MainActions), 0);
    schedule_bg_copy_tilemap_to_vram(0);
}

void ShowDebugMenu(void)
{
    u8 taskId;

    if (!is_c1_link_related_active())
    {
        FreezeEventObjects();
        sub_808B864();
        sub_808BCF4();
    }
    taskId = CreateTask(HandleDebugMenuInput, 80);
    sub_81973A4();
    InitDebugMenu(taskId);
    ScriptContext2_Enable();
}

static void ReturnToMainMenu(u8 taskId)
{
    gTasks[taskId].func = HandleDebugMenuInput;
    InitDebugMenu(taskId);
}

static void HandleDebugMenuInput(u8 taskId)
{
    s8 inputOptionId = Menu_ProcessInput();

    switch (inputOptionId)
    {
        case MENU_NOTHING_CHOSEN:
            break;
        case MENU_B_PRESSED:
            PlaySE(SE_SELECT);
            DebugMenu_Exit(taskId);
            break;
        default:
            PlaySE(SE_SELECT);
            sDebugMenu_MainActions[inputOptionId].func.void_u8(taskId);
            break;
    }
}

static void DebugMenu_RemoveMainMenu(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    sub_8198070(tWindowId, TRUE);
    RemoveWindow(tWindowId);
}

static void DebugMenu_Exit(u8 taskId)
{
    DebugMenu_RemoveMainMenu(taskId);
    ScriptUnfreezeEventObjects();
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
    AddTextPrinterParameterized(windowId, 1, gStringVar4, 0, 1, 0, NULL);
}

#define tFlagNum data[1]
#define tWhichDigit data[2]

static void DebugMenu_SetFlag(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    DebugMenu_RemoveMainMenu(taskId);

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

        if (temp >= FLAG_TEMP_1 && temp <= FLAG_0x95F)
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

        if (temp >= FLAG_TEMP_1 && temp <= FLAG_0x95F)
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
        DebugMenu_SetFlag_RemoveMenu(taskId);
        ReturnToMainMenu(taskId);
    }
}

static void DebugMenu_SetFlag_RemoveMenu(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    sub_8198070(tWindowId, TRUE);
    RemoveWindow(tWindowId);
}

static void DebugMenu_SetVar_PrintStatus(u8 windowId, u16 varId)
{
    FillWindowPixelBuffer(windowId, 0x11);
    ConvertIntToHexStringN(gStringVar1, varId, STR_CONV_MODE_LEADING_ZEROS, 4);
    ConvertIntToHexStringN(gStringVar2, VarGet(varId), STR_CONV_MODE_LEADING_ZEROS, 4);
    ConvertIntToHexStringN(gStringVar3, (u32)GetVarPointer(varId), STR_CONV_MODE_LEADING_ZEROS, 8);
    StringExpandPlaceholders(gStringVar4, sText_VarStatus);
    AddTextPrinterParameterized(windowId, 1, gStringVar4, 0, 1, 0, NULL);
}

#define tVarNum data[1]
#define tWhichDigit data[2]

static void DebugMenu_SetVar(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    DebugMenu_RemoveMainMenu(taskId);

    tWindowId = AddWindow(&sDebugMenu_Window_SetVar);
    SetStandardWindowBorderStyle(tWindowId, FALSE);
    DebugMenu_SetVar_PrintStatus(tWindowId, VAR_TEMP_0);
    schedule_bg_copy_tilemap_to_vram(0);
    tVarNum = VAR_TEMP_0;
    tWhichDigit = 0;
    gTasks[taskId].func = DebugMenu_SetVar_ProcessInput;
}

static void DebugMenu_SetVar_ProcessInput(u8 taskId)
{
    u32 temp, shifter;
    u16 *data = gTasks[taskId].data;

    if (gMain.newAndRepeatedKeys & DPAD_UP)
    {
        shifter = tWhichDigit * 4;
        temp = (((tVarNum >> shifter) & 0xF) + 1) & 0xF;
        temp = (tVarNum & ~(0xF << shifter)) | (temp << shifter);

        if (temp >= VAR_TEMP_0 && temp <= VAR_0x40FF)
        {
            PlaySE(SE_SELECT);
            tVarNum = temp;
            DebugMenu_SetVar_PrintStatus(tWindowId, temp);
        }
    }

    if (gMain.newAndRepeatedKeys & DPAD_DOWN)
    {
        shifter = tWhichDigit * 4;
        temp = (((tVarNum >> shifter) & 0xF) - 1) & 0xF;
        temp = (tVarNum & ~(0xF << shifter)) | (temp << shifter);

        if (temp >= VAR_TEMP_0 && temp <= VAR_0x40FF)
        {
            PlaySE(SE_SELECT);
            tVarNum = temp;
            DebugMenu_SetVar_PrintStatus(tWindowId, temp);
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

        /*if (FlagGet(tVarNum))
            FlagClear(tVarNum);
        else
            FlagSet(tVarNum);*/

        DebugMenu_SetVar_PrintStatus(tWindowId, tVarNum);
    }

    if (gMain.newKeys & B_BUTTON)
    {
        PlaySE(SE_SELECT);
        DebugMenu_SetVar_RemoveMenu(taskId);
        ReturnToMainMenu(taskId);
    }
}

static void DebugMenu_SetVar_RemoveMenu(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    sub_8198070(tWindowId, TRUE);
    RemoveWindow(tWindowId);
}
