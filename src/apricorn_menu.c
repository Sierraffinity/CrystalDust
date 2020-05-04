#include "global.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "international_string_util.h"
#include "item_menu.h"
#include "list_menu.h"
#include "malloc.h"
#include "menu.h"
#include "script.h"
#include "sound.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "constants/items.h"
#include "constants/songs.h"
#include "constants/vars.h"

enum {
    WIN_APRICORN,
    WIN_QUANTITY,
    WIN_COUNT
};

static EWRAM_DATA struct {
    struct ItemSlot apricorns[APRICORN_COUNT];
    struct ListMenuItem listItems[APRICORN_COUNT + 1];
    u8 listStrings[APRICORN_COUNT + 1][24];
    u16 cursorPos;
    u16 itemsAbove;
    u8 pageItems;
    u8 count;
    u8 listMenuTaskId;
    u8 scrollIndicatorId;
    u8 windowIds[WIN_COUNT];
} *sApricornMenu = NULL;

// static functions
static void InitApricornMenu(u8 taskId);
static u8 AddWindowIfNotPresent(u8 whichWindow);
static void ApricornMenu_Main_ProcessInput(u8 taskId);
static void ApricornMenu_ItemPrint(u8 windowId, s32 id, u8 yOffset);
static void ApricornMenu_RefreshListMenu(void);
static void ApricornMenu_AddScrollIndicator(void);
static void ApricornMenu_Exit(u8 taskId);
static void ApricornMenu_RemoveScrollIndicator(void);

// const data
static const struct WindowTemplate sApricornMenuWindows[] =
{
    {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 1,
        .width = 15,
        .height = 12,
        .paletteNum = 15,
        .baseBlock = 0x0001
    },
    DUMMY_WIN_TEMPLATE
};

static const struct ListMenuTemplate sApricornListMenuTemplate =
{
    .items = NULL,
    .moveCursorFunc = NULL,
    .itemPrintFunc = ApricornMenu_ItemPrint,
    .totalItems = 0,
    .maxShowed = 0,
    .windowId = 0,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 0,
    .cursorPal = 2,
    .fillValue = 1,
    .cursorShadowPal = 3,
    .lettersSpacing = FALSE,
    .itemVerticalPadding = 0,
    .scrollMultiple = FALSE,
    .fontId = 1
};

void SelectApricornForKurt(void)
{
    DisplayItemMessageOnField(CreateTask(TaskDummy, 0), gText_WhichApricorn, InitApricornMenu);
}

static void InitApricornMenu(u8 taskId)
{
    u8 i, curIdx;

    VarSet(VAR_KURT_GIVEN_APRICORN, 0);
    VarSet(VAR_KURT_GIVEN_APRICORN_QTY, 0);

    sApricornMenu = AllocZeroed(sizeof(*sApricornMenu));
    memset(sApricornMenu->windowIds, 0xFF, WIN_COUNT);
    sApricornMenu->cursorPos = 0;
    sApricornMenu->itemsAbove = 0;
    sApricornMenu->scrollIndicatorId = 0xFF;

    for (i = 0, curIdx = 0; i < APRICORN_COUNT; i++)
    {
        u16 count = CountTotalItemQuantityInBag(ITEM_RED_APRICORN + i);

        if (count > 0)
        {
            sApricornMenu->apricorns[curIdx].itemId = ITEM_RED_APRICORN + i;
            sApricornMenu->apricorns[curIdx].quantity = count;
            curIdx++;
        }
    }

    sApricornMenu->count = curIdx;
    if (sApricornMenu->count >= 7)
        sApricornMenu->pageItems = 7;
    else
        sApricornMenu->pageItems = sApricornMenu->count + 1;

    FreeAndReserveObjectSpritePalettes();
    LoadListMenuArrowsGfx();

    ApricornMenu_RefreshListMenu();
    sApricornMenu->listMenuTaskId = ListMenuInit(&gMultiuseListMenuTemplate, sApricornMenu->itemsAbove, sApricornMenu->cursorPos);
    ApricornMenu_AddScrollIndicator();

    gTasks[taskId].func = ApricornMenu_Main_ProcessInput;
}

static u8 AddWindowIfNotPresent(u8 whichWindow)
{
    u8 *windowIdPtr = &(sApricornMenu->windowIds[whichWindow]);
    if (*windowIdPtr == 0xFF)
    {
        *windowIdPtr = AddWindow(&sApricornMenuWindows[whichWindow]);
        DrawStdFrameWithCustomTileAndPalette(*windowIdPtr, FALSE, STD_WINDOW_BASE_TILE_NUM, STD_WINDOW_PALETTE_NUM);
        schedule_bg_copy_tilemap_to_vram(0);
    }
    return *windowIdPtr;
}

static void RemoveWindowIfPresent(u8 a)
{
    u8 *windowIdLoc = &(sApricornMenu->windowIds[a]);
    if (*windowIdLoc != 0xFF)
    {
        ClearStdWindowAndFrameToTransparent(*windowIdLoc, FALSE);
        ClearWindowTilemap(*windowIdLoc);
        schedule_bg_copy_tilemap_to_vram(0);
        RemoveWindow(*windowIdLoc);
        *windowIdLoc = 0xFF;
    }
}

static void RemoveAllWindows(void)
{
    int i;

    for (i = 0; i < WIN_COUNT; i++)
    {
        RemoveWindowIfPresent(i);
    }
}

static void ApricornMenu_RefreshListMenu(void)
{
    u16 i;

    for (i = 0; i < sApricornMenu->count; i++)
    {
        CopyItemName(sApricornMenu->apricorns[i].itemId, sApricornMenu->listStrings[i]);
        sApricornMenu->listItems[i].name = sApricornMenu->listStrings[i];
        sApricornMenu->listItems[i].id = i;
    }

    StringCopy(sApricornMenu->listStrings[i], gText_Cancel2);
    sApricornMenu->listItems[i].name = sApricornMenu->listStrings[i];
    sApricornMenu->listItems[i].id = LIST_CANCEL;

    gMultiuseListMenuTemplate = sApricornListMenuTemplate;
    gMultiuseListMenuTemplate.windowId = AddWindowIfNotPresent(WIN_APRICORN);
    gMultiuseListMenuTemplate.totalItems = sApricornMenu->count + 1;
    gMultiuseListMenuTemplate.items = sApricornMenu->listItems;
    gMultiuseListMenuTemplate.maxShowed = sApricornMenu->pageItems;
}

static void ApricornMenu_AddScrollIndicator(void)
{
    if (sApricornMenu->scrollIndicatorId == 0xFF)
        sApricornMenu->scrollIndicatorId = AddScrollIndicatorArrowPairParameterized(SCROLL_ARROW_UP,
                                                                                    68,
                                                                                    8,
                                                                                    106,
                                                                                    sApricornMenu->count - sApricornMenu->pageItems + 1,
                                                                                    5112,
                                                                                    5112,
                                                                                    &sApricornMenu->itemsAbove);
}

static void ApricornMenu_RemoveScrollIndicator(void)
{
    if (sApricornMenu->scrollIndicatorId != 0xFF)
    {
        RemoveScrollIndicatorArrowPair(sApricornMenu->scrollIndicatorId);
        sApricornMenu->scrollIndicatorId = 0xFF;
    }
}

static void ApricornMenu_Main_ProcessInput(u8 taskId)
{
    s16 *data;
    s32 id;

    data = gTasks[taskId].data;
    id = ListMenu_ProcessInput(sApricornMenu->listMenuTaskId);
    ListMenuGetScrollAndRow(sApricornMenu->listMenuTaskId, &(sApricornMenu->itemsAbove), &(sApricornMenu->cursorPos));
    switch (id)
    {
    case LIST_NOTHING_CHOSEN:
        break;
    case LIST_CANCEL:
        PlaySE(SE_SELECT);
        ApricornMenu_Exit(taskId);
        break;
    default:
        PlaySE(SE_SELECT);
        VarSet(VAR_KURT_GIVEN_APRICORN, sApricornMenu->apricorns[id].itemId - ITEM_RED_APRICORN);
        VarSet(VAR_KURT_GIVEN_APRICORN_QTY, 1);
        ApricornMenu_Exit(taskId);
        break;
    }
}

static void ApricornMenu_ItemPrint(u8 windowId, s32 id, u8 yOffset)
{
    if (id != LIST_CANCEL)
    {
        ConvertIntToDecimalStringN(gStringVar1, sApricornMenu->apricorns[id].quantity, STR_CONV_MODE_RIGHT_ALIGN, 3);
        StringExpandPlaceholders(gStringVar4, gText_xVar1);
        AddTextPrinterParameterized(windowId, 0, gStringVar4, GetStringRightAlignXOffset(0, gStringVar4, 120), yOffset, TEXT_SPEED_FF, NULL);
    }
}

static void ApricornMenu_Exit(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    //sub_816C0C8();
    ApricornMenu_RemoveScrollIndicator();
    DestroyListMenuTask(sApricornMenu->listMenuTaskId, NULL, NULL);
    RemoveAllWindows();
    EnableBothScriptContexts();
    DestroyTask(taskId);
}
