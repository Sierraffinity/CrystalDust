#include "global.h"
#include "main.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "international_string_util.h"
#include "item.h"
#include "item_menu.h"
#include "list_menu.h"
#include "malloc.h"
#include "menu.h"
#include "menu_helpers.h"
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
    WIN_YESNO,
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
    u16 fakeIdForArrows;
    u8 windowIds[WIN_COUNT];
} *sApricornMenu = NULL;

// static functions
static void InitApricornMenu(u8 taskId);
static u8 AddWindowIfNotPresent(u8 whichWindow);
static void ApricornMenu_Main_ProcessInput(u8 taskId);
static void ApricornMenu_ItemPrint(u8 windowId, u16 index, s32 id, u8 yOffset);
static void ApricornMenu_RefreshListMenu(void);
static void ApricornMenu_AddMainScrollIndicator(void);
static void ApricornMenu_Exit(u8 taskId);
static void ApricornMenu_RemoveScrollIndicator(void);
static void ApricornMenu_KurtAsksQuantity(u8 taskId, s32 whichApricorn);
static void ApricornMenu_InitQuantityBox(u8 taskId);
static void ApricornMenu_PrintQuantity(int windowId, int numToGive);
static void ApricornMenu_ChangeQuantityToGive(u8 taskId);
static void ApricornMenu_ReturnToMain(u8 taskId);
static void ApricornMenu_InitConfirmGive(u8 taskId);
static void ApricornMenu_ConfirmGive(u8 taskId);
static void ApricornMenu_GiveApricornsToKurt(u8 taskId);

// const data
static const struct WindowTemplate sApricornMenuWindows[] =
{
    {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 1,
        .width = 14,
        .height = 12,
        .paletteNum = 15,
        .baseBlock = 0x0001
    },
    {
        .bg = 0,
        .tilemapLeft = 24,
        .tilemapTop = 9,
        .width = 5,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 0x242
    },
    {
        .bg = 0,
        .tilemapLeft = 23,
        .tilemapTop = 9,
        .width = 6,
        .height = 4,
        .paletteNum = 0xF,
        .baseBlock = 0x28a
    },
};

static const struct ListMenuTemplate sApricornListMenuTemplate =
{
    .items = NULL,
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
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
    .fontId = 2
};

static const struct YesNoFuncTable sYesNoFunctions = {ApricornMenu_GiveApricornsToKurt, ApricornMenu_ReturnToMain};

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

    ApricornMenu_RefreshListMenu();
    sApricornMenu->listMenuTaskId = ListMenuInit(&gMultiuseListMenuTemplate, sApricornMenu->itemsAbove, sApricornMenu->cursorPos);
    ApricornMenu_AddMainScrollIndicator();

    gTasks[taskId].func = ApricornMenu_Main_ProcessInput;
}

static u8 AddWindowIfNotPresent(u8 whichWindow)
{
    u8 *windowIdPtr = &(sApricornMenu->windowIds[whichWindow]);
    if (*windowIdPtr == 0xFF)
    {
        *windowIdPtr = AddWindow(&sApricornMenuWindows[whichWindow]);
        DrawStdFrameWithCustomTileAndPalette(*windowIdPtr, FALSE, STD_WINDOW_BASE_TILE_NUM, STD_WINDOW_PALETTE_NUM);
        ScheduleBgCopyTilemapToVram(0);
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
        ScheduleBgCopyTilemapToVram(0);
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

static void ApricornMenu_AddMainScrollIndicator(void)
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

static void ApricornMenu_AddQuantityScrollIndicator(void)
{
    if (sApricornMenu->scrollIndicatorId == 0xFF)
    {
        sApricornMenu->fakeIdForArrows = 1;
        sApricornMenu->scrollIndicatorId = AddScrollIndicatorArrowPairParameterized(SCROLL_ARROW_UP,
                                                                                    212,
                                                                                    70,
                                                                                    106,
                                                                                    2,
                                                                                    5112,
                                                                                    5112,
                                                                                    &sApricornMenu->fakeIdForArrows);
    }
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
        ApricornMenu_RemoveScrollIndicator();
        ApricornMenu_KurtAsksQuantity(taskId, sApricornMenu->itemsAbove + sApricornMenu->cursorPos);
        break;
    }
}

static void ApricornMenu_ItemPrint(u8 windowId, u16 index, s32 id, u8 yOffset)
{
    if (id != LIST_CANCEL)
    {
        ConvertIntToDecimalStringN(gStringVar1, sApricornMenu->apricorns[id].quantity, STR_CONV_MODE_RIGHT_ALIGN, 3);
        StringExpandPlaceholders(gStringVar4, gText_xVar1);
        AddTextPrinterParameterized(windowId, 0, gStringVar4, GetStringRightAlignXOffset(0, gStringVar4, 112), yOffset, TEXT_SPEED_FF, NULL);
    }
}

#define tApricornIdx    data[0]
#define tItemId         data[1]
#define tItemCount      data[2]

static void ApricornMenu_KurtAsksQuantity(u8 taskId, s32 whichApricorn)
{
    s16 *data = gTasks[taskId].data;

    tItemCount = 1;
    tApricornIdx = whichApricorn;
    
    if (sApricornMenu->apricorns[whichApricorn].quantity <= 1)
    {
        ApricornMenu_InitConfirmGive(taskId);
    }
    else
    {
        DisplayItemMessageOnField(taskId, gText_HowManyApricorns, ApricornMenu_InitQuantityBox);
    }
}

static void ApricornMenu_InitQuantityBox(u8 taskId)
{
    u8 windowId = AddWindowIfNotPresent(WIN_QUANTITY);
    ApricornMenu_AddQuantityScrollIndicator();
    ApricornMenu_PrintQuantity(windowId, gTasks[taskId].tItemCount);
    gTasks[taskId].func = ApricornMenu_ChangeQuantityToGive;
}

static void ApricornMenu_ChangeQuantityToGive(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    u16 totalInBag = sApricornMenu->apricorns[tApricornIdx].quantity;

    if (AdjustQuantityAccordingToDPadInput(&tItemCount, totalInBag) == TRUE)
    {
        ApricornMenu_PrintQuantity(sApricornMenu->windowIds[WIN_QUANTITY], tItemCount);
    }
    else if (JOY_NEW(A_BUTTON))
    {
        PlaySE(SE_SELECT);
        RemoveWindowIfPresent(WIN_QUANTITY);
        ApricornMenu_RemoveScrollIndicator();
        ApricornMenu_InitConfirmGive(taskId);
    }
    else if (JOY_NEW(B_BUTTON))
    {
        PlaySE(SE_SELECT);
        RemoveWindowIfPresent(WIN_QUANTITY);
        ApricornMenu_RemoveScrollIndicator();
        ApricornMenu_ReturnToMain(taskId);
    }
}

static void ApricornMenu_ReturnToMain(u8 taskId)
{
    ApricornMenu_AddMainScrollIndicator();
    DisplayMessageAndContinueTask(taskId, 0, DLG_WINDOW_BASE_TILE_NUM, DLG_WINDOW_PALETTE_NUM, 2, 0, gText_WhichApricorn, ApricornMenu_Main_ProcessInput);
}

static void ApricornMenu_PrintQuantity(int windowId, int numToGive)
{
    u8 colors[] = {0, 2, 3};
    FillWindowPixelBuffer(windowId, PIXEL_FILL(1));
    ConvertIntToDecimalStringN(gStringVar1, numToGive, STR_CONV_MODE_LEADING_ZEROS, 3);
    StringExpandPlaceholders(gStringVar4, gText_xVar1);
    AddTextPrinterParameterized4(windowId, 0, 4, 10, 1, 0, colors, TEXT_SPEED_FF, gStringVar4);
    CopyWindowToVram(windowId, 2);
}

static void ApricornMenu_InitConfirmGive(u8 taskId)
{
    u8 *str;
    s16 *data = gTasks[taskId].data;
    tItemCount = (tItemCount > sApricornMenu->apricorns[tApricornIdx].quantity)
                        ? sApricornMenu->apricorns[tApricornIdx].quantity : tItemCount;
    tItemId = sApricornMenu->apricorns[tApricornIdx].itemId;

    if (tItemCount > 1)
    {
        str = CopyItemName(tItemId, gStringVar2);
        *str++ = CHAR_S;
        *str = EOS;
        ConvertIntToDecimalStringN(gStringVar1, tItemCount, STR_CONV_MODE_LEFT_ALIGN, 3);
    }
    else
    {
        CopyItemName(tItemId, gStringVar2);
        str = gStringVar1;
        *str++ = CHAR_a;
        *str = EOS;
    }

    StringExpandPlaceholders(gStringVar4, gText_ConfirmApricorns);

    DisplayItemMessageOnField(taskId, gStringVar4, ApricornMenu_ConfirmGive);
}

static void ApricornMenu_ConfirmGive(u8 taskId)
{
    CreateYesNoMenuWithCallbacks(taskId, &sApricornMenuWindows[WIN_YESNO], 2, 0, 2, 532, 14, &sYesNoFunctions);
}

static void ApricornMenu_GiveApricornsToKurt(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    VarSet(VAR_KURT_GIVEN_APRICORN, tItemId);
    VarSet(VAR_KURT_GIVEN_APRICORN_QTY, tItemCount);
    RemoveBagItem(tItemId, tItemCount);
    gTasks[taskId].func = ApricornMenu_Exit;
}

#undef tItemCount
#undef tApricornIdx

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
