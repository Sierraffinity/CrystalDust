#include "global.h"
#include "battle_pyramid.h"
#include "bg.h"
#include "event_data.h"
#include "gpu_regs.h"
#include "international_string_util.h"
#include "menu.h"
#include "map_name_popup.h"
#include "palette.h"
#include "region_map.h"
#include "start_menu.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "text.h"
#include "text_window.h"
#include "constants/layouts.h"
#include "constants/region_map_sections.h"
#include "constants/weather.h"

// static functions
static void Task_MapNamePopup(u8 taskId);
static u8 MapNamePopupCreateWindow(bool32 palintoFadedBuffer);
static void MapNamePopupPrintMapNameOnWindow(u16 windowId);
static u8 *MapNamePopupAppendFloorNum(u8 *dest, s8 flags);

static const u8 gText_PyramidFloor1[] = _("PYRAMID FLOOR 1");
static const u8 gText_PyramidFloor2[] = _("PYRAMID FLOOR 2");
static const u8 gText_PyramidFloor3[] = _("PYRAMID FLOOR 3");
static const u8 gText_PyramidFloor4[] = _("PYRAMID FLOOR 4");
static const u8 gText_PyramidFloor5[] = _("PYRAMID FLOOR 5");
static const u8 gText_PyramidFloor6[] = _("PYRAMID FLOOR 6");
static const u8 gText_PyramidFloor7[] = _("PYRAMID FLOOR 7");
static const u8 gText_Pyramid[] = _("PYRAMID");

static const u8 * const gBattlePyramid_MapHeaderStrings[] =
{
    gText_PyramidFloor1,
    gText_PyramidFloor2,
    gText_PyramidFloor3,
    gText_PyramidFloor4,
    gText_PyramidFloor5,
    gText_PyramidFloor6,
    gText_PyramidFloor7,
    gText_Pyramid,
};

#define tState              data[0]
#define tTimer              data[1]
#define tPos                data[2]
#define tReshow             data[3]
#define tWindowId           data[4]
#define tWindowExists       data[5]
#define tWindowCleared      data[6]
#define tPalIntoFadedBuffer data[7]

// text
void ShowMapNamePopup(bool32 palIntoFadedBuffer)
{
    u8 taskId;
    if (FlagGet(FLAG_HIDE_MAP_NAME_POPUP) != TRUE)
    {
        taskId = FindTaskIdByFunc(Task_MapNamePopup);
        if (taskId == 0xFF)
        {
            taskId = CreateTask(Task_MapNamePopup, 90);
            ChangeBgX(0,  0x0000, 0);
            ChangeBgY(0, -0x1081, 0);
            gTasks[taskId].tState = 0;
            gTasks[taskId].tPos = 0;
            gTasks[taskId].tPalIntoFadedBuffer = palIntoFadedBuffer;
        }
        else
        {
            if (gTasks[taskId].tState != 4)
                gTasks[taskId].tState = 4;
            gTasks[taskId].tReshow = TRUE;
        }
    }
}

void Special_ShowMapNamePopup(void)
{
    ShowMapNamePopup(TRUE);
}

static void Task_MapNamePopup(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    switch (task->tState)
    {
    case 0:
        task->tWindowId = MapNamePopupCreateWindow(task->tPalIntoFadedBuffer);
        task->tWindowExists = TRUE;
        task->tState++;
        break;
    case 1:
        if (IsDma3ManagerBusyWithBgCopy())
            break;
        // fallthrough
    case 2:
        task->tPos -= 2;
        if (task->tPos <= -24)
        {
            task->tTimer = 0;
            task->tState++;
        }
        break;
    case 3:
        task->tTimer++;
        if (task->tTimer > 120)
        {
            task->tTimer = 0;
            task->tState++;
        }
        break;
    case 4:
        task->tPos += 2;
        if (task->tPos >= 0)
        {
            if (task->tReshow)
            {
                MapNamePopupPrintMapNameOnWindow(task->tWindowId);
                CopyWindowToVram(task->tWindowId, COPYWIN_GFX);
                task->tState = 1;
                task->tReshow = FALSE;
            }
            else
            {
                task->tState++;
                return;
            }
        }
        break;
    case 5:
        if (task->tWindowExists && !task->tWindowCleared)
        {
            rbox_fill_rectangle(task->tWindowId);
            CopyWindowToVram(task->tWindowId, COPYWIN_MAP);
            task->tWindowCleared = TRUE;
        }
        task->tState++;
        return;
    case 6:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            if (task->tWindowExists)
            {
                RemoveWindow(task->tWindowId);
                task->tWindowExists = FALSE;
            }
            task->tState++;
            ChangeBgY(0, 0, 0);
        }
        return;
    case 7:
        DestroyTask(taskId);
        return;
    }
    SetGpuReg(REG_OFFSET_BG0VOFS, task->tPos);
}

void DismissMapNamePopup(void)
{
    u8 taskId = FindTaskIdByFunc(Task_MapNamePopup);

    if (taskId != 0xFF)
    {
        if (gTasks[taskId].tState < 5)
            gTasks[taskId].tState = 5;
    }
}

static u8 MapNamePopupCreateWindow(bool32 palintoFadedBuffer)
{
    struct WindowTemplate windowTemplate = {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 29,
        .width = 14,
        .height = 2,
        .paletteNum = 0xD,
        .baseBlock = 0x001
    };

    u16 windowId;
    u16 borderTileNum = 29;

    if (gMapHeader.floorNum != 0)
    {
        if (gMapHeader.floorNum != 0x7F)
        {
            windowTemplate.width += 5;
            borderTileNum = 39;
        }
        else
        {
            // ROOFTOP
            windowTemplate.width += 8;
            borderTileNum = 45;
        }
    }

    windowId = AddWindow(&windowTemplate);

    if (palintoFadedBuffer)
    {
        LoadPalette(GetTextWindowPalette(3), 0xD0, 0x20);
    }
    else
    {
        CpuCopy16(GetTextWindowPalette(3), &gPlttBufferUnfaded[0xD0], 0x20);
    }

    LoadThinWindowBorderTiles(windowId, borderTileNum);
    DrawTextBorderOuter(windowId, borderTileNum, 13);
    PutWindowTilemap(windowId);
    MapNamePopupPrintMapNameOnWindow(windowId);
    CopyWindowToVram(windowId, COPYWIN_BOTH);
    return windowId;
}

static void MapNamePopupPrintMapNameOnWindow(u16 windowId)
{
    u8 mapName[25];
    u32 maxWidth = 112;
    u32 xpos;
    u8 *ptr;
    
    const u8* mapDisplayHeaderSource;

    if (InBattlePyramid())
    {
        if (gMapHeader.mapLayoutId == LAYOUT_BATTLE_FRONTIER_BATTLE_PYRAMID_TOP)
        {
            mapDisplayHeaderSource = gBattlePyramid_MapHeaderStrings[7];
        }
        else
        {
            mapDisplayHeaderSource = gBattlePyramid_MapHeaderStrings[gSaveBlock2Ptr->frontier.curChallengeBattleNum];
        }
        ptr = StringCopy(mapName, mapDisplayHeaderSource);
    }
    else
    {
        ptr = GetMapNameHandleSpecialMaps(mapName, gMapHeader.regionMapSectionId);
    }

    if (gMapHeader.floorNum)
    {
        ptr = MapNamePopupAppendFloorNum(ptr, gMapHeader.floorNum);
        maxWidth = gMapHeader.floorNum != 0x7F ? 152 : 176;
    }

    xpos = (maxWidth - GetStringWidth(2, mapName, -1)) / 2;
    FillWindowPixelBuffer(windowId, PIXEL_FILL(1));
    AddTextPrinterParameterized(windowId, 2, mapName, xpos, 2, TEXT_SPEED_FF, NULL);
}

static u8 *MapNamePopupAppendFloorNum(u8 *dest, s8 floorNum)
{
    if (floorNum == 0)
        return dest;
    *dest++ = CHAR_SPACE;
    if (floorNum == 0x7F)
        return StringCopy(dest, gText_Rooftop);
    if (floorNum < 0)
    {
        *dest++ = CHAR_B;
        floorNum *= -1;
    }
    dest = ConvertIntToDecimalStringN(dest, floorNum, STR_CONV_MODE_LEFT_ALIGN, 2);
    *dest++ = CHAR_F;
    *dest = EOS;
    return dest;
}

#undef tPalIntoFadedBuffer
#undef tWindowCleared
#undef tWindowExists
#undef tWindowId
#undef tReshow
#undef tPos
#undef tTimer
#undef tState
