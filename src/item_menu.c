#include "global.h"
#include "item_menu.h"
#include "battle.h"
#include "battle_controllers.h"
#include "battle_pyramid.h"
#include "frontier_util.h"
#include "battle_pyramid_bag.h"
#include "berry_tag_screen.h"
#include "bg.h"
#include "constants/items.h"
#include "constants/songs.h"
#include "data.h"
#include "decompress.h"
#include "event_data.h"
#include "event_scripts.h"
#include "event_object_movement.h"
#include "field_player_avatar.h"
#include "field_specials.h"
#include "graphics.h"
#include "gpu_regs.h"
#include "international_string_util.h"
#include "item.h"
#include "item_menu_icons.h"
#include "item_use.h"
#include "lilycove_lady.h"
#include "list_menu.h"
#include "link.h"
#include "mail.h"
#include "main.h"
#include "malloc.h"
#include "map_name_popup.h"
#include "menu.h"
#include "money.h"
#include "overworld.h"
#include "palette.h"
#include "party_menu.h"
#include "player_pc.h"
#include "pokemon.h"
#include "pokemon_summary_screen.h"
#include "scanline_effect.h"
#include "script.h"
#include "shop.h"
#include "sound.h"
#include "sprite.h"
#include "strings.h"
#include "string_util.h"
#include "task.h"
#include "text_window.h"
#include "menu_helpers.h"
#include "window.h"
#include "apprentice.h"
#include "battle_pike.h"
#include "constants/rgb.h"

#define TAG_POCKET_SCROLL_ARROW 110
#define TAG_BAG_SCROLL_ARROW    111

// The buffer for the bag item list needs to be large enough to hold the maximum
// number of item slots that could fit in a single pocket, + 1 for Cancel.
// This constant picks the max of the existing pocket sizes.
// By default, the largest pocket is BAG_TMHM_COUNT at 64.
#define MAX_POCKET_ITEMS  ((max(BAG_TMHM_COUNT,              \
                            max(BAG_BERRIES_COUNT,           \
                            max(BAG_ITEMS_COUNT,             \
                            max(BAG_KEYITEMS_COUNT,          \
                                BAG_POKEBALLS_COUNT))))) + 1)

#define FREE_IF_SET(ptr)            \
{                                   \
    if (ptr)                        \
    {                               \
        Free(ptr);                  \
        ptr = NULL;                 \
    }                               \
}

// Up to 6 item slots can be visible at a time
#define MAX_ITEMS_SHOWN 6 // Was 8 in Emerald

// Item list ID for toSwapPos to indicate an item is not currently being swapped
#define NOT_SWAPPING 0xFF

enum
{
    SWITCH_POCKET_NONE,
    SWITCH_POCKET_LEFT,
    SWITCH_POCKET_RIGHT
};

enum {
    ACTION_USE,
    ACTION_TOSS,
    ACTION_REGISTER,
    ACTION_GIVE,
    ACTION_CANCEL,
    ACTION_BATTLE_USE,
    ACTION_CHECK,
    ACTION_WALK,
    ACTION_DESELECT,
    ACTION_VIEW_TAG,
    ACTION_CONFIRM,
    ACTION_SHOW,
    ACTION_DUMMY
};

struct BagSlots
{
    struct ItemSlot bagPocket_Items[BAG_ITEMS_COUNT];
    struct ItemSlot bagPocket_PokeBalls[BAG_POKEBALLS_COUNT];
    u16 cursorPosition[POCKETS_COUNT];
    u16 scrollPosition[POCKETS_COUNT];
    u16 pocket;
};

EWRAM_DATA struct BagPosition gBagPosition = {};
EWRAM_DATA struct BagMenu *gBagMenu = NULL;
static EWRAM_DATA struct ListMenuItem * sListMenuItems = NULL;
static EWRAM_DATA u8 (*sListMenuItemStrings)[ITEM_NAME_LENGTH + 19] = NULL;
static EWRAM_DATA struct BagSlots *sBackupPlayerBag = 0;
EWRAM_DATA u16 gSpecialVar_ItemId = ITEM_NONE;

static void FadeOutOfBagMenu(void);
static void Task_WaitFadeOutOfBagMenu(u8 taskId);
static void NullBagMenuBufferPtrs(void);
static void CB2_Bag(void);
static bool8 SetupBagMenu(void);
static void BagMenu_InitBGs(void);
static bool8 LoadBagMenu_Graphics(void);
static bool8 AllocateBagItemListBuffers(void);
static void LoadBagItemListBuffers(u8);
static void PrintPocketNames(void);
static void CreatePocketScrollArrowPair(void);
static void CreatePocketSwitchArrowPair(void);
static bool8 BagIsTutorial(void);
static void Task_Bag_WallyTutorialBagMenu(u8);
static void Task_BagMenu_HandleInput(u8);
static void GetItemName(s8 *dest, u16 itemId);
static void PrintItemDescription(s32 itemIndex);
static void BagMenu_PrintCursor(u8 listTaskId, u8 colorIndex);
static void BagMenu_PrintCursorAtPos(u8 y, u8 colorIndex);
static void DestroyPocketSwitchArrowPair(void);
static void Task_ItemMenu_WaitFadeAndSwitchToExitCallback(u8 taskId);
static void Task_AnimateWin0v(u8 taskId);
static void ReturnToItemList(u8);
static u8 GetSwitchBagPocketDirection(void);
static void SwitchPockets(u8, s16, u16);
static bool8 CanSwapItems(void);
static void StartItemSwap(u8);
static void Task_SwitchBagPocket(u8);
static void Task_HandleSwappingItemsInput(u8);
static void DoItemSwap(u8, u32);
static void CancelItemSwap(u8, u32);
static void Task_ItemContext_SingleRow(u8);
static void Task_PrintThereIsNoPokemon(u8);
static void Task_SelectQuantityToToss(u8);
static void Task_ConfirmTossItems(u8);
static void Task_RemoveItemFromBag(u8);
static void HandleErrorMessage(u8);
static void Task_PrintItemCantBeHeld(u8);
static void DisplaySellItemPriceAndConfirm(u8);
static void InitSellHowManyInput(u8);
static void AskSellItems(u8);
//static void RemoveMoneyWindow(void);
static void Task_ChooseHowManyToSell(u8);
static void SellItem(u8);
static void WaitAfterItemSell(u8);
static void TryDepositItem(u8);
static void Task_ChooseHowManyToDeposit(u8 taskId);
static void WaitDepositErrorMessage(u8);
static void CB2_ApprenticeExitBagMenu(void);
static void UpdatePocketItemLists(void);
static void InitPocketListPositions(void);
static void InitPocketScrollPositions(void);
static u8 CreateBagInputHandlerTask(u8);
static void DrawItemListBgRow(u8);
static void BagMenu_MoveCursorCallback(s32 itemIndex, bool8 onInit, struct ListMenu *unused);
void BagMenu_ItemPrintCallback(u8 windowId, u16 index, s32 itemIndex, u8 a);
static void ItemMenu_UseOutOfBattle(u8 taskId);
static void ItemMenu_Toss(u8 taskId);
static void ItemMenu_Register(u8 taskId);
static void ItemMenu_Give(u8 taskId);
static void ItemMenu_Cancel(u8 taskId);
static void ItemMenu_UseInBattle(u8 taskId);
static void ItemMenu_ViewTag(u8 taskId);
static void ItemMenu_Show(u8 taskId);
static void Task_ItemContext_Normal(u8 taskId);
static void Task_ItemContext_GiveToParty(u8 taskId);
static void Task_ItemContext_Sell(u8 taskId);
static void Task_ItemContext_Deposit(u8 taskId);
static void Task_ItemContext_PcBoxGive(u8 taskId);
static void Task_TossItem_Yes(u8 taskId);
static void Task_TossItem_No(u8 taskId);
static void ConfirmSell(u8 taskId);
static void CancelSell(u8 taskId);
static void ShowBagOrBeginWin0OpenTask(void);
static void FreeBagMenu(void);
static void Bag_FillMessageBoxWithPalette(u32 a0);

static const struct BgTemplate sBgTemplates[] =
{
    {
        .bg = 0,
        .charBaseIndex = 0,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0,
    },
    {
        .bg = 1,
        .charBaseIndex = 3,
        .mapBaseIndex = 30,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0,
    }
};

static const u8 *const sPocketNames[] =
{
    gText_ItemsPocket,
    gText_PokeBallsPocket,
    gText_TMHMPocket,
    gText_BerriesPocket,
    gText_KeyItemsPocket
};

static const u16 sBagListBgTiles[][18] =
{
    INCBIN_U16("graphics/item_menu/bagmap_0.bin"),
    INCBIN_U16("graphics/item_menu/bagmap_1.bin"),
    INCBIN_U16("graphics/item_menu/bagmap_2.bin"),
    INCBIN_U16("graphics/item_menu/bagmap_3.bin"),
    INCBIN_U16("graphics/item_menu/bagmap_4.bin"),
    INCBIN_U16("graphics/item_menu/bagmap_5.bin"),
    INCBIN_U16("graphics/item_menu/bagmap_6.bin"),
    INCBIN_U16("graphics/item_menu/bagmap_7.bin"),
    INCBIN_U16("graphics/item_menu/bagmap_8.bin"),
    INCBIN_U16("graphics/item_menu/bagmap_9.bin"),
    INCBIN_U16("graphics/item_menu/bagmap_A.bin"),
    INCBIN_U16("graphics/item_menu/bagmap_B.bin")
};

static const struct MenuAction sItemMenuActions[] =
{
    [ACTION_USE]               = {gMenuText_Use,                   ItemMenu_UseOutOfBattle},
    [ACTION_TOSS]              = {gMenuText_Toss,                  ItemMenu_Toss},
    [ACTION_REGISTER]          = {gMenuText_Register,              ItemMenu_Register},
    [ACTION_GIVE]              = {gMenuText_Give,                  ItemMenu_Give},
    [ACTION_CANCEL]            = {gText_Cancel,                    ItemMenu_Cancel},
    [ACTION_BATTLE_USE]        = {gMenuText_Use,                   ItemMenu_UseInBattle},
    [ACTION_CHECK]             = {gMenuText_Check,                 ItemMenu_UseOutOfBattle},
    [ACTION_WALK]              = {gMenuText_Walk,                  ItemMenu_UseOutOfBattle},
    [ACTION_DESELECT]          = {gMenuText_Deselect,              ItemMenu_Register},
    [ACTION_VIEW_TAG]          = {gMenuText_CheckTag,              ItemMenu_ViewTag},
    [ACTION_CONFIRM]           = {gMenuText_Confirm,               Task_FadeAndCloseBagMenu},
    [ACTION_SHOW]              = {gMenuText_Show,                  ItemMenu_Show},
    [ACTION_DUMMY]             = {gText_ExpandedPlaceholder_Empty, NULL}
};

// ACTION_DUMMY is used to represent blank spaces
static const u8 sContextMenuItems_Field[][POCKETS_COUNT] =
{
    [ITEMS_POCKET] = {
        ACTION_USE,
        ACTION_GIVE,
        ACTION_TOSS,
        ACTION_CANCEL,
        ACTION_DUMMY
    },
    [BALLS_POCKET] = {
        ACTION_GIVE,
        ACTION_TOSS,
        ACTION_CANCEL,
        ACTION_DUMMY,
        ACTION_DUMMY
    },
    [TMHM_POCKET] = {
        ACTION_USE,
        ACTION_GIVE,
        ACTION_CANCEL,
        ACTION_DUMMY,
        ACTION_DUMMY
    },
    [BERRIES_POCKET] = {
        ACTION_VIEW_TAG,
        ACTION_USE,
        ACTION_GIVE,
        ACTION_TOSS,
        ACTION_CANCEL
    },
    [KEYITEMS_POCKET] = {
        ACTION_USE,
        ACTION_REGISTER,
        ACTION_CANCEL,
        ACTION_DUMMY,
        ACTION_DUMMY
    }
};

static const u8 sContextMenuItems_CheckGiveTossCancel[] =
{
    ACTION_CHECK,
    ACTION_GIVE,
    ACTION_TOSS,
    ACTION_CANCEL
};

static const u8 sContextMenuItems_TossCancel[] =
{
    ACTION_TOSS,
    ACTION_CANCEL
};

static const u8 sContextMenuItems_BattleUse[] =
{
    ACTION_BATTLE_USE,
    ACTION_CANCEL
};

static const u8 sContextMenuItems_Give[] =
{
    ACTION_GIVE,
    ACTION_CANCEL
};

static const u8 sContextMenuItems_Cancel[] =
{
    ACTION_CANCEL
};

static const u8 sContextMenuItems_BerryCrush[] =
{
    ACTION_CONFIRM,
    ACTION_VIEW_TAG,
    ACTION_CANCEL
};

static const u8 sContextMenuItems_Apprentice[] =
{
    ACTION_SHOW,
    ACTION_CANCEL
};

static const TaskFunc sContextMenuFuncs[] =
{
    [ITEMMENULOCATION_FIELD] =                  Task_ItemContext_Normal,
    [ITEMMENULOCATION_BATTLE] =                 Task_ItemContext_Normal,
    [ITEMMENULOCATION_PARTY] =                  Task_ItemContext_GiveToParty,
    [ITEMMENULOCATION_SHOP] =                   Task_ItemContext_Sell,
    [ITEMMENULOCATION_BERRY_TREE] =             Task_FadeAndCloseBagMenu,
    [ITEMMENULOCATION_BERRY_BLENDER_CRUSH] =    Task_ItemContext_Normal,
    [ITEMMENULOCATION_ITEMPC] =                 Task_ItemContext_Deposit,
    [ITEMMENULOCATION_WALLY] =                  NULL,
    [ITEMMENULOCATION_PCBOX] =                  Task_ItemContext_PcBoxGive
};

static const struct YesNoFuncTable sYesNoTossFunctions =
{
    Task_TossItem_Yes,
    Task_TossItem_No
};

static const struct YesNoFuncTable sYesNoSellItemFunctions =
{
    ConfirmSell,
    CancelSell
};

static const struct ScrollArrowsTemplate sBagScrollArrowsTemplate =
{
    .firstArrowType = SCROLL_ARROW_LEFT,
    .firstX = 8,
    .firstY = 72,
    .secondArrowType = SCROLL_ARROW_RIGHT,
    .secondX = 72,
    .secondY = 72,
    .fullyUpThreshold = 0,
    .fullyDownThreshold = 2,
    .tileTag = 111,
    .palTag = 111,
    .palNum = 0,
};

static const u8 sBlit_SelectButton[] = INCBIN_U8("graphics/item_menu/select_button.4bpp");

static void ItemMenu_GiveFavorLady(u8 taskId)
{
    RemoveBagItem(gSpecialVar_ItemId, 1);
    gSpecialVar_Result = TRUE;
    BagMenu_RemoveWindow(ITEMWIN_LIST);
    Task_FadeAndCloseBagMenu(taskId);
}

static void CB2_FavorLadyExitBagMenu(void)
{
    gFieldCallback = FieldCallback_FavorLadyEnableScriptContexts;
    SetMainCallback2(CB2_ReturnToField);
}

// This action is used to confirm which item to use as
// a prize for a custom quiz with the Lilycove Quiz Lady
static void ItemMenu_ConfirmQuizLady(u8 taskId)
{
    gSpecialVar_Result = TRUE;
    BagMenu_RemoveWindow(ITEMWIN_LIST);
    Task_FadeAndCloseBagMenu(taskId);
}

static void CB2_QuizLadyExitBagMenu(void)
{
    gFieldCallback = FieldCallback_QuizLadyEnableScriptContexts;
    SetMainCallback2(CB2_ReturnToField);
}

void FavorLadyOpenBagMenu(void)
{
    GoToBagMenu(ITEMMENULOCATION_FAVOR_LADY, POCKETS_COUNT, CB2_FavorLadyExitBagMenu);
    gSpecialVar_Result = FALSE;
}

void QuizLadyOpenBagMenu(void)
{
    GoToBagMenu(ITEMMENULOCATION_QUIZ_LADY, POCKETS_COUNT, CB2_QuizLadyExitBagMenu);
    gSpecialVar_Result = FALSE;
}

void GoToBagMenu(u8 location, u8 pocket, void ( *exitCallback)())
{
    NullBagMenuBufferPtrs();
    gBagMenu = AllocZeroed(sizeof(*gBagMenu));
    if (gBagMenu)
    {
        if (location != ITEMMENULOCATION_LAST)
            gBagPosition.location = location;
        if (exitCallback)
            gBagPosition.exitCallback = exitCallback;
        gBagMenu->newScreenCallback = NULL;
        gBagMenu->toSwapPos = NOT_SWAPPING;
        gBagMenu->itemIconSlot = 0;
        gBagMenu->inhibitItemDescriptionPrint = FALSE;
        gBagMenu->pocketScrollArrowsTask = TASK_NONE;
        gBagMenu->pocketSwitchArrowsTask = TASK_NONE;
        if (gBagPosition.location == ITEMMENULOCATION_BERRY_TREE
         || gBagPosition.location == ITEMMENULOCATION_BERRY_BLENDER_CRUSH)
            gBagMenu->pocketSwitchDisabled = TRUE;
        else
            gBagMenu->pocketSwitchDisabled = FALSE;
        if (pocket < POCKETS_COUNT)
            gBagPosition.pocket = pocket;
        gSpecialVar_ItemId = ITEM_NONE;
        SetMainCallback2(CB2_Bag);
    }
    else
        // Alloc failed, exit
        SetMainCallback2(exitCallback);
}

void CB2_BagMenuFromStartMenu(void)
{
    GoToBagMenu(ITEMMENULOCATION_FIELD, POCKETS_COUNT, CB2_ReturnToFieldWithOpenMenu);
}

void CB2_BagMenuFromBattle(void)
{
    if (InBattlePyramid())
        GoToBattlePyramidBagMenu(PYRAMIDBAG_LOC_BATTLE, CB2_SetUpReshowBattleScreenAfterMenu2);
    else
        GoToBagMenu(ITEMMENULOCATION_BATTLE, POCKETS_COUNT, CB2_SetUpReshowBattleScreenAfterMenu2);
}

static void CB2_BagMenuRun(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    DoScheduledBgTilemapCopiesToVram();
    UpdatePaletteFade();
}

static void VBlankCB_BagMenuRun(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

#define tListTaskId        data[0]
#define tListPosition      data[1]
#define tQuantity          data[2]
#define tItemCount         data[8]
#define tMsgWindowId       data[10]
#define tPocketSwitchDir   data[11]
#define tPocketSwitchTimer data[12]
#define tPocketSwitchState data[13]

static void CB2_Bag(void)
{
    while (!MenuHelpers_CallLinkSomething() && !SetupBagMenu() && !MenuHelpers_LinkSomething()) {};
}

static bool8 SetupBagMenu(void)
{
    u8 taskId;

    switch (gMain.state)
    {
    case 0:
        SetVBlankHBlankCallbacksToNull();
        ClearScheduledBgCopiesToVram();
        gMain.state++;
        break;
    case 1:
        ScanlineEffect_Stop();
        gMain.state++;
        break;
    case 2:
        FreeAllSpritePalettes();
        gMain.state++;
        break;
    case 3:
        ResetPaletteFade();
        gPaletteFade.bufferTransferDisabled = TRUE;
        gMain.state++;
        break;
    case 4:
        ResetSpriteData();
        gMain.state++;
        break;
    case 5:
        ResetItemMenuIconState();
        gMain.state++;
        break;
    case 6:
        if (!MenuHelpers_LinkSomething())
            ResetTasks();
        gMain.state++;
        break;
    case 7:
        BagMenu_InitBGs();
        gBagMenu->graphicsLoadState = 0;
        gMain.state++;
        break;
    case 8:
        if (LoadBagMenu_Graphics())
            gMain.state++;
        break;
    case 9:
        LoadBagMenuTextWindows();
        gMain.state++;
        break;
    case 10:
        UpdatePocketItemLists();
        InitPocketListPositions();
        InitPocketScrollPositions();
        gMain.state++;
        break;
    case 11:
        if (!AllocateBagItemListBuffers())
        {
            FadeOutOfBagMenu();
            return TRUE;
        }
        gMain.state++;
        break;
    case 12:
        LoadBagItemListBuffers(gBagPosition.pocket);
        gMain.state++;
        break;
    case 13:
        PrintPocketNames();
        gMain.state++;
        break;
    case 14:
        taskId = CreateBagInputHandlerTask(gBagPosition.location);
        gTasks[taskId].tListTaskId = ListMenuInit(&gMultiuseListMenuTemplate, gBagPosition.scrollPosition[gBagPosition.pocket], gBagPosition.cursorPosition[gBagPosition.pocket]);
        gTasks[taskId].tItemCount = 0;
        gMain.state++;
        break;
    case 15:
        AddBagVisualSprite(gBagPosition.pocket);
        gMain.state++;
        break;
    case 16:
        ItemMenuIcons_CreateInsertIndicatorBarHidden();
        gMain.state++;
        break;
    case 17:
        CreatePocketScrollArrowPair();
        CreatePocketSwitchArrowPair();
        gMain.state++;
        break;
    case 18:
        ShowBagOrBeginWin0OpenTask();
        gMain.state++;
        break;
    case 19:
        gPaletteFade.bufferTransferDisabled = FALSE;
        gMain.state++;
        break;
    default:
        SetVBlankCallback(VBlankCB_BagMenuRun);
        SetMainCallback2(CB2_BagMenuRun);
        return TRUE;
    }
    return FALSE;
}

static void FadeOutOfBagMenu(void)
{
    BeginNormalPaletteFade(PALETTES_ALL, -2, 0, 16, RGB_BLACK);
    CreateTask(Task_WaitFadeOutOfBagMenu, 0);
    SetVBlankCallback(VBlankCB_BagMenuRun);
    SetMainCallback2(CB2_BagMenuRun);
}

static void Task_WaitFadeOutOfBagMenu(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        SetMainCallback2(gBagPosition.exitCallback);
        FreeBagMenu();
        DestroyTask(taskId);
    }
}

static void NullBagMenuBufferPtrs(void)
{
    gBagMenu = NULL;
    sListMenuItems = NULL;
    sListMenuItemStrings = NULL;
}

static void BagMenu_InitBGs(void)
{
    ResetVramOamAndBgCntRegs();
    ResetAllBgsCoordinates();
    memset(gBagMenu->tilemapBuffer, 0, sizeof(gBagMenu->tilemapBuffer));
    ResetBgsAndClearDma3BusyFlags(FALSE);
    InitBgsFromTemplates(0, sBgTemplates, ARRAY_COUNT(sBgTemplates));
    SetBgTilemapBuffer(1, gBagMenu->tilemapBuffer);
    ScheduleBgCopyTilemapToVram(1);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_1D_MAP | DISPCNT_OBJ_ON | DISPCNT_WIN0_ON);
    ShowBg(0);
    ShowBg(1);
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
}

static bool8 LoadBagMenu_Graphics(void)
{
    switch (gBagMenu->graphicsLoadState)
    {
    case 0:
        ResetTempTileDataBuffers();
        DecompressAndCopyTileDataToVram(1, gBagScreen_Gfx, 0, 0, 0);
        gBagMenu->graphicsLoadState++;
        break;
    case 1:
        if (!FreeTempTileDataBuffersIfPossible())
        {
            LZDecompressWram(gBagScreen_GfxTileMap, gBagMenu->tilemapBuffer);
            gBagMenu->graphicsLoadState++;
        }
        break;
    case 2:
        LoadCompressedPalette(gBagScreenMale_Pal, 0, 0x60);
        if (!BagIsTutorial() && gSaveBlock2Ptr->playerGender)
            LoadCompressedPalette(gBagScreenFemale_Pal, 0, 0x20);
        gBagMenu->graphicsLoadState++;
        break;
    case 3:
        if (BagIsTutorial() || !gSaveBlock2Ptr->playerGender)
            LoadCompressedSpriteSheet(&gBagMaleSpriteSheet);
        else
            LoadCompressedSpriteSheet(&gBagFemaleSpriteSheet);
        gBagMenu->graphicsLoadState++;
        break;
    case 4:
        if (BagIsTutorial() == TRUE || gSaveBlock2Ptr->playerGender == MALE)
            LoadCompressedSpritePalette(&gBagMalePaletteTable);
        else
            LoadCompressedSpritePalette(&gBagFemalePaletteTable);
        gBagMenu->graphicsLoadState++;
        break;
    default:
        LoadListMenuSwapLineGfx();
        gBagMenu->graphicsLoadState = 0;
        return TRUE;
    }
    return FALSE;
}

static u8 CreateBagInputHandlerTask(u8 location)
{
    u8 taskId;

    if (location == ITEMMENULOCATION_WALLY)
        taskId = CreateTask(Task_Bag_WallyTutorialBagMenu, 0);
    else
        taskId = CreateTask(Task_BagMenu_HandleInput, 0);
    return taskId;
}

static bool8 AllocateBagItemListBuffers(void)
{
    sListMenuItems = Alloc((MAX_POCKET_ITEMS) * sizeof(*sListMenuItems));
    if (!sListMenuItems)
        return FALSE;
    sListMenuItemStrings = Alloc((MAX_POCKET_ITEMS) * sizeof(*sListMenuItemStrings));
    if (!sListMenuItemStrings)
        return FALSE;
    return TRUE;
}

static void LoadBagItemListBuffers(u8 pocketId)
{
    u32 i;
    struct BagPocket *pocket = &gBagPockets[pocketId];

    for (i = 0; i < gBagMenu->numItemStacks[pocketId]; i++)
    {
        GetItemName(sListMenuItemStrings[i], pocket->itemSlots[i].itemId);
        sListMenuItems[i].name = sListMenuItemStrings[i];
        sListMenuItems[i].id = i;
    }
    StringCopy(sListMenuItemStrings[i], gText_CloseBag);
    sListMenuItems[i].name = sListMenuItemStrings[i];
    sListMenuItems[i].id = i;
    gMultiuseListMenuTemplate.items = sListMenuItems;
    gMultiuseListMenuTemplate.totalItems = gBagMenu->numItemStacks[pocketId] + 1;
    gMultiuseListMenuTemplate.windowId = 0;
    gMultiuseListMenuTemplate.header_X = 0;
    gMultiuseListMenuTemplate.item_X = 9;
    gMultiuseListMenuTemplate.cursor_X = 1;
    gMultiuseListMenuTemplate.lettersSpacing = 0;
    gMultiuseListMenuTemplate.itemVerticalPadding = 2;
    gMultiuseListMenuTemplate.upText_Y = 2;
    gMultiuseListMenuTemplate.maxShowed = gBagMenu->numShownItems[pocketId];
    gMultiuseListMenuTemplate.fontId = 2;
    gMultiuseListMenuTemplate.cursorPal = 2;
    gMultiuseListMenuTemplate.fillValue = 0;
    gMultiuseListMenuTemplate.cursorShadowPal = 3;
    gMultiuseListMenuTemplate.moveCursorFunc = BagMenu_MoveCursorCallback;
    gMultiuseListMenuTemplate.itemPrintFunc = BagMenu_ItemPrintCallback;
    gMultiuseListMenuTemplate.cursorKind = 0;
    gMultiuseListMenuTemplate.scrollMultiple = 0;
}

static void GetItemName(s8 *dest, u16 itemId)
{
    switch (gBagPosition.pocket)
    {
        case TMHM_POCKET:
            StringCopy(gStringVar2, gMoveNames[ItemIdToBattleMoveId(itemId)]);
            if (itemId >= ITEM_HM01)
            {
                // Get HM number
                ConvertIntToDecimalStringN(gStringVar1, itemId - ITEM_HM01 + 1, STR_CONV_MODE_LEADING_ZEROS, 1);
                StringExpandPlaceholders(dest, gText_NumberItem_HM);
            }
            else
            {
                // Get TM number
                ConvertIntToDecimalStringN(gStringVar1, itemId - ITEM_TM01 + 1, STR_CONV_MODE_LEADING_ZEROS, 2);
                StringExpandPlaceholders(dest, gText_NumberItem_TMBerry);
            }
            break;
        case BERRIES_POCKET:
            ConvertIntToDecimalStringN(gStringVar1, itemId - FIRST_BERRY_INDEX + 1, STR_CONV_MODE_LEADING_ZEROS, 2);
            CopyItemName(itemId, gStringVar2);
            StringExpandPlaceholders(dest, gText_NumberItem_TMBerry);
            break;
        default:
            CopyItemName(itemId, dest);
            break;
    }
}

static void BagMenu_MoveCursorCallback(s32 itemIndex, bool8 onInit, struct ListMenu *unused)
{
    if (!onInit)
    {
        PlaySE(SE_RG_BAG_CURSOR);
        ShakeBagSprite();
    }
    if (gBagMenu->toSwapPos == NOT_SWAPPING)
    {
        HideBagItemIconSprite(gBagMenu->itemIconSlot ^ 1);
        RemoveBagItemIconSprite(gBagMenu->itemIconSlot);
        if (gBagMenu->numItemStacks[gBagPosition.pocket] != itemIndex)
           AddBagItemIconSprite(BagGetItemIdByPocketPosition(gBagPosition.pocket + 1, itemIndex), gBagMenu->itemIconSlot);
        else
           AddBagItemIconSprite(-1, gBagMenu->itemIconSlot);
        gBagMenu->itemIconSlot ^= 1;
        if (!gBagMenu->inhibitItemDescriptionPrint)
            PrintItemDescription(itemIndex);
    }
}

void BagMenu_ItemPrintCallback(u8 windowId, u16 index, s32 itemIndex, u8 y)
{
    u16 itemId, itemQuantity;

    if (gBagMenu->toSwapPos != NOT_SWAPPING)
    {
        // Swapping items, draw cursor at original item's location
        if (gBagMenu->toSwapPos == (u8)itemIndex)
            BagMenu_PrintCursorAtPos(y, COLORID_GRAY_CURSOR);
        else
            BagMenu_PrintCursorAtPos(y, COLORID_NONE);
    }
    if (itemIndex != LIST_CANCEL && gBagMenu->numItemStacks[gBagPosition.pocket] != itemIndex)
    {
        itemId = BagGetItemIdByPocketPosition(gBagPosition.pocket + 1, itemIndex);
        itemQuantity = BagGetQuantityByPocketPosition(gBagPosition.pocket + 1, itemIndex);

        // Draw HM icon
        if (itemId >= ITEM_HM01 && itemId <= ITEM_HM09)
            BlitBitmapToWindow(windowId, gBagMenuHMIcon_Gfx, 9, y, 16, 12);

        if (gBagPosition.pocket == BERRIES_POCKET || (gBagPosition.pocket != KEYITEMS_POCKET && ItemId_GetImportance(itemId) < 2))
        {
            // Print item or berry quantity
            ConvertIntToDecimalStringN(gStringVar1, itemQuantity, STR_CONV_MODE_RIGHT_ALIGN, 3);
            StringExpandPlaceholders(gStringVar4, gText_xVar1);
            BagMenu_Print(windowId, 4, gStringVar4, 110, y, 0, 0, -1, 1);
        }
        // Print registered icon
        else if (gSaveBlock1Ptr->registeredItem && gSaveBlock1Ptr->registeredItem == itemId)
            BlitBitmapToWindow(windowId, sBlit_SelectButton, 112, y, 24, 16);
    }
}

static void BagMenu_PrintCursor(u8 listTaskId, u8 colorIndex)
{
    BagMenu_PrintCursorAtPos(ListMenuGetYCoordForPrintingArrowCursor(listTaskId), colorIndex);
}

static void BagMenu_PrintCursorAtPos(u8 y, u8 colorIndex)
{
    if (colorIndex == COLORID_NONE)
        FillWindowPixelRect(WIN_ITEM_LIST, PIXEL_FILL(0), 1, y, GetMenuCursorDimensionByFont(2, 0), GetMenuCursorDimensionByFont(2, 1));
    else
        BagMenu_Print(WIN_ITEM_LIST, 2, gText_SelectorArrow2, 1, y, 0, 0, 0, colorIndex);
}

static void PrintPocketNames(void)
{
    u32 x;

    FillWindowPixelBuffer(WIN_POCKET_NAME, PIXEL_FILL(0));
    x = GetStringCenterAlignXOffset(2, sPocketNames[gBagPosition.pocket], 0x48);
    BagMenu_Print(WIN_POCKET_NAME, 2, sPocketNames[gBagPosition.pocket], x, 1, GetFontAttribute(2, FONTATTR_LETTER_SPACING), GetFontAttribute(2, FONTATTR_LINE_SPACING), 0, COLORID_DESCRIPTION);
}

static void PrintItemDescription(s32 itemIndex)
{
    const u8 *description;

    if (itemIndex != gBagMenu->numItemStacks[gBagPosition.pocket])
        description = ItemId_GetDescription(BagGetItemIdByPocketPosition(gBagPosition.pocket + 1, itemIndex));
    else
    {
        // Print 'Cancel' description
        StringCopy(gStringVar1, gBagMenu_ReturnToStrings[gBagPosition.location]);
        StringExpandPlaceholders(gStringVar4, gText_ReturnToVar1);
        description = gStringVar4;
    }
    FillWindowPixelBuffer(WIN_DESCRIPTION, PIXEL_FILL(0));
    BagMenu_Print(WIN_DESCRIPTION, 2, description, 0, 3, 2, 0, 0, COLORID_DESCRIPTION);
}

static void CreatePocketScrollArrowPair(void)
{
    gBagMenu->pocketScrollArrowsTask = AddScrollIndicatorArrowPairParameterized(
        SCROLL_ARROW_UP,
        160,
        8,
        104,
        gBagMenu->numItemStacks[gBagPosition.pocket] - gBagMenu->numShownItems[gBagPosition.pocket] + 1,
        TAG_POCKET_SCROLL_ARROW,
        TAG_POCKET_SCROLL_ARROW,
        &gBagPosition.scrollPosition[gBagPosition.pocket]
    );
}

static void CreatePocketSwitchArrowPair(void)
{
    if (!gBagMenu->pocketSwitchDisabled)
    {
        gBagMenu->contextMenuSelectedItem = 1;
        gBagMenu->pocketSwitchArrowsTask = AddScrollIndicatorArrowPair(&sBagScrollArrowsTemplate, &gBagMenu->contextMenuSelectedItem);
    }
}

static void CreatePocketScrollArrowPair_SellQuantity(void)
{
    gBagMenu->contextMenuSelectedItem = 1;
    gBagMenu->pocketScrollArrowsTask = AddScrollIndicatorArrowPairParameterized(
        SCROLL_ARROW_UP,
        152,
        72,
        104,
        2,
        TAG_POCKET_SCROLL_ARROW,
        TAG_POCKET_SCROLL_ARROW,
        &gBagMenu->contextMenuSelectedItem
    );
}

static void CreateArrowPair_QuantitySelect(void)
{
    gBagMenu->contextMenuSelectedItem = 1;
    gBagMenu->pocketScrollArrowsTask = AddScrollIndicatorArrowPairParameterized(
        SCROLL_ARROW_UP,
        212,
        120,
        152,
        2,
        TAG_POCKET_SCROLL_ARROW,
        TAG_POCKET_SCROLL_ARROW,
        &gBagMenu->contextMenuSelectedItem
    );
}

static void DestroyPocketScrollArrowPair(void)
{
    if (gBagMenu->pocketScrollArrowsTask != TASK_NONE)
    {
        RemoveScrollIndicatorArrowPair(gBagMenu->pocketScrollArrowsTask);
        gBagMenu->pocketScrollArrowsTask = TASK_NONE;
    }
    DestroyPocketSwitchArrowPair();
}

static void DestroyPocketSwitchArrowPair(void)
{
    if (gBagMenu->pocketSwitchArrowsTask != TASK_NONE)
    {
        RemoveScrollIndicatorArrowPair(gBagMenu->pocketSwitchArrowsTask);
        gBagMenu->pocketSwitchArrowsTask = TASK_NONE;
    }
}

void ResetBagCursorPositions(void)
{
    gBagPosition.pocket = ITEMS_POCKET;
    memset(gBagPosition.cursorPosition, 0, sizeof(gBagPosition.cursorPosition));
    memset(gBagPosition.scrollPosition, 0, sizeof(gBagPosition.scrollPosition));
}

void UpdatePocketListPosition(u8 pocketId)
{
    SetCursorWithinListBounds(&gBagPosition.scrollPosition[pocketId], &gBagPosition.cursorPosition[pocketId], gBagMenu->numShownItems[pocketId], gBagMenu->numItemStacks[pocketId] + 1);
}

static void InitPocketListPositions(void)
{
    u32 i;

    for (i = 0; i < POCKETS_COUNT; i++)
        UpdatePocketListPosition(i);
}

static void InitPocketScrollPositions(void)
{
    u32 i, j;

    for (i = 0; i < POCKETS_COUNT; i++)
    {
        if (gBagPosition.cursorPosition[i] > 3)
        {
            for (j = 0; j <= gBagPosition.cursorPosition[i] - 3; gBagPosition.cursorPosition[i]--, gBagPosition.scrollPosition[i]++, j++)
            {
                if (gBagPosition.scrollPosition[i] + gBagMenu->numShownItems[i] == gBagMenu->numItemStacks[i] + 1)
                    break;
            }
        }
    }
}

static void FreeBagMenu(void)
{
    FREE_IF_SET(gBagMenu);
    FREE_IF_SET(sListMenuItems);
    FREE_IF_SET(sListMenuItemStrings);
    FreeAllWindowBuffers();
}

void Task_FadeAndCloseBagMenu(u8 taskId)
{
    BeginNormalPaletteFade(PALETTES_ALL, -2, 0, 16, RGB_BLACK);
    gTasks[taskId].func = Task_ItemMenu_WaitFadeAndSwitchToExitCallback;
}

static void Task_ItemMenu_WaitFadeAndSwitchToExitCallback(u8 taskId)
{
    s16* data = gTasks[taskId].data;

    if (!gPaletteFade.active && !FuncIsActiveTask(Task_AnimateWin0v))
    {
        DestroyListMenuTask(tListTaskId, &gBagPosition.scrollPosition[gBagPosition.pocket], &gBagPosition.cursorPosition[gBagPosition.pocket]);
        // If ready for a new screen (e.g. party menu for giving an item) go to that screen
        // Otherwise exit the bag and use callback set up when the bag was first opened
        if (gBagMenu->newScreenCallback)
            SetMainCallback2(gBagMenu->newScreenCallback);
        else
            SetMainCallback2(gBagPosition.exitCallback);
        DestroyPocketScrollArrowPair();
        FreeBagMenu();
        DestroyTask(taskId);
    }
}

static void ShowBagOrBeginWin0OpenTask(void)
{
    u16 paldata = RGB_BLACK;
    u8 taskId;

    LoadPalette(&paldata, 0x00, 0x02);
    SetGpuReg(REG_OFFSET_WININ, 0);
    SetGpuReg(REG_OFFSET_WINOUT, WININ_WIN0_ALL);
    BlendPalettes(PALETTES_ALL, 16, RGB_BLACK);
    BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
    if (gBagPosition.bagOpen)
    {
        SetGpuReg(REG_OFFSET_WIN0H, WIN_RANGE(0, 240));
        SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE(0, 0));
    }
    else
    {
        SetGpuReg(REG_OFFSET_WIN0H, WIN_RANGE(0, 240));
        SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE(0, 160));
        taskId = CreateTask(Task_AnimateWin0v, 0);
        gTasks[taskId].tListTaskId = 192;
        gTasks[taskId].tListPosition = -16;
        gBagPosition.bagOpen = TRUE;
    }
}

void Bag_BeginCloseWin0Animation(void)
{
    u8 taskId = CreateTask(Task_AnimateWin0v, 0);

    gTasks[taskId].tListTaskId = -16;
    gTasks[taskId].tListPosition = 16;
    gBagPosition.bagOpen = FALSE;
}

static void Task_AnimateWin0v(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    tListTaskId += tListPosition;
    if (tListTaskId > 160)
        SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE(0, 160));
    else
        SetGpuReg(REG_OFFSET_WIN0V, tListTaskId);
    if ((tListPosition == 16 && tListTaskId == 160) || (tListPosition == -16 && !tListTaskId))
        DestroyTask(taskId);
}

void UpdatePocketItemList(u8 pocketId)
{
    u32 i;
    struct BagPocket *pocket = &gBagPockets[pocketId];

    switch (pocketId)
    {
        case TMHM_POCKET:
        case BERRIES_POCKET:
            SortBerriesOrTMHMs(pocket);
            break;
        default:
            CompactItemsInBagPocket(pocket);
            break;
    }

    gBagMenu->numItemStacks[pocketId] = 0;

    for (i = 0; i < pocket->capacity && pocket->itemSlots[i].itemId; i++)
        gBagMenu->numItemStacks[pocketId]++;

    if (gBagMenu->numItemStacks[pocketId] + 1 > MAX_ITEMS_SHOWN)
        gBagMenu->numShownItems[pocketId] = MAX_ITEMS_SHOWN;
    else
        gBagMenu->numShownItems[pocketId] = gBagMenu->numItemStacks[pocketId] + 1;
}

static void UpdatePocketItemLists(void)
{
    u32 i;

    for (i = 0; i < POCKETS_COUNT; i++)
        UpdatePocketItemList(i);
}

void DisplayItemMessage(u8 taskId, u8 fontId, const u8 *str, void (*callback)(u8 taskId))
{
    s16* data = gTasks[taskId].data;

    tMsgWindowId = OpenBagWindow(ITEMWIN_MESSAGE);
    FillWindowPixelBuffer(tMsgWindowId, PIXEL_FILL(1));
    DisplayMessageAndContinueTask(taskId, tMsgWindowId, 0x6D, 0xD, fontId, GetPlayerTextSpeedDelay(), str, callback);
    ScheduleBgCopyTilemapToVram(0);
}

u8 GetItemListPosition(u8 pocketId)
{
    return gBagPosition.cursorPosition[pocketId] + gBagPosition.scrollPosition[pocketId];
}

// Prints the quantity of items to be sold and the amount that would be earned
static void PrintItemSoldAmount(int windowId, int numSold, int moneyEarned)
{
    u8 numDigits = (gBagPosition.pocket == BERRIES_POCKET) ? BERRY_CAPACITY_DIGITS : BAG_ITEM_CAPACITY_DIGITS;

    FillWindowPixelBuffer(windowId, PIXEL_FILL(1));
    ConvertIntToDecimalStringN(gStringVar1, numSold, STR_CONV_MODE_LEADING_ZEROS, numDigits);
    StringExpandPlaceholders(gStringVar4, gText_xVar1);
    BagMenu_Print(windowId, 4, gStringVar4, 4, 10, 1, 0, TEXT_SPEED_FF, COLORID_NORMAL);
    PrintMoneyAmount(windowId, 56, 10, moneyEarned, 0);
}

static bool8 CanSwapItems(void)
{
    // Swaps can only be done from the field or in battle (as opposed to while selling items, for example)
    if (gBagPosition.location < ITEMMENULOCATION_PARTY)
    {
        // TMHMs and berries are numbered, and so may not be swapped
        if (gBagPosition.pocket != TMHM_POCKET
         && gBagPosition.pocket != BERRIES_POCKET)
            return TRUE;
    }
    return FALSE;
}

static void Task_BagMenu_HandleInput(u8 taskId)
{
    s16* data = gTasks[taskId].data;
    u16 scrollPos, cursorPos;
    s32 listPosition = ListMenu_ProcessInput(tListTaskId);

    if (gPaletteFade.active
     || FuncIsActiveTask(Task_AnimateWin0v)
     || MenuHelpers_CallLinkSomething())
        return;

    switch (GetSwitchBagPocketDirection())
    {
    case SWITCH_POCKET_LEFT:
        SwitchPockets(taskId, MENU_CURSOR_DELTA_LEFT, FALSE);
        return;
    case SWITCH_POCKET_RIGHT:
        SwitchPockets(taskId, MENU_CURSOR_DELTA_RIGHT, FALSE);
        return;
    default:
        if (JOY_NEW(SELECT_BUTTON) && CanSwapItems())
        {
            ListMenuGetScrollAndRow(tListTaskId, &cursorPos, &scrollPos);
            if (cursorPos + scrollPos != gBagMenu->numItemStacks[gBagPosition.pocket])
            {
                PlaySE(SE_SELECT);
                StartItemSwap(taskId);
                return;
            }
        }
        break;
    }
    ListMenuGetScrollAndRow(tListTaskId, &gBagPosition.scrollPosition[gBagPosition.pocket], &gBagPosition.cursorPosition[gBagPosition.pocket]);
    switch (listPosition)
    {
    case LIST_CANCEL:
        if (gBagPosition.location == ITEMMENULOCATION_BERRY_BLENDER_CRUSH)
        {
            PlaySE(SE_FAILURE);
            break;
        }
        PlaySE(SE_SELECT);
        gSpecialVar_ItemId = ITEM_NONE;
        Bag_BeginCloseWin0Animation();
        gTasks[taskId].func = Task_FadeAndCloseBagMenu;
        break;
    case LIST_NOTHING_CHOSEN:
        return;
    default: // A_BUTTON
        PlaySE(SE_SELECT);
        if (listPosition == gBagMenu->numItemStacks[gBagPosition.pocket])
        {
            gSpecialVar_ItemId = ITEM_NONE;
            Bag_BeginCloseWin0Animation();
            gTasks[taskId].func = Task_FadeAndCloseBagMenu;
        }
        else
        {
            DestroyPocketScrollArrowPair();
            BagMenu_PrintCursor(tListTaskId, COLORID_GRAY_CURSOR);
            tListPosition = listPosition;
            tQuantity = BagGetQuantityByPocketPosition(gBagPosition.pocket + 1, listPosition);
            gSpecialVar_ItemId = BagGetItemIdByPocketPosition(gBagPosition.pocket + 1, listPosition);
            Bag_FillMessageBoxWithPalette(1);
            sContextMenuFuncs[gBagPosition.location](taskId);
        }
        break;
    }
}

static void ReturnToItemList(u8 taskId)
{
    Bag_FillMessageBoxWithPalette(0);
    CreatePocketScrollArrowPair();
    CreatePocketSwitchArrowPair();
    gTasks[taskId].func = Task_BagMenu_HandleInput;
}

static void Bag_FillMessageBoxWithPalette(u32 a0)
{
    SetBgTilemapPalette(1, 0, 14, 30, 6, a0 + 1);
    ScheduleBgCopyTilemapToVram(1);
}

static u8 GetSwitchBagPocketDirection(void)
{
    u8 LRKeys;

    if (gBagMenu->pocketSwitchDisabled)
        return SWITCH_POCKET_NONE;

    LRKeys = GetLRKeysPressed();
    if (JOY_NEW(DPAD_LEFT) || LRKeys == MENU_L_PRESSED)
    {
        PlaySE(SE_RG_BAG_POCKET);
        return SWITCH_POCKET_LEFT;
    }
    if (JOY_NEW(DPAD_RIGHT) || LRKeys == MENU_R_PRESSED)
    {
        PlaySE(SE_RG_BAG_POCKET);
        return SWITCH_POCKET_RIGHT;
    }
    return SWITCH_POCKET_NONE;
}

static void ChangeBagPocketId(u8 *bagPocketId, s8 deltaBagPocketId)
{
    if (deltaBagPocketId == MENU_CURSOR_DELTA_RIGHT && *bagPocketId == POCKETS_COUNT - 1)
        *bagPocketId = 0;
    else if (deltaBagPocketId == MENU_CURSOR_DELTA_LEFT && *bagPocketId == 0)
        *bagPocketId = POCKETS_COUNT - 1;
    else
        *bagPocketId += deltaBagPocketId;
}

static void SwitchPockets(u8 taskId, s16 deltaBagPocketId, bool16 skipEraseList)
{
    s16* data = gTasks[taskId].data;
    u8 newPocket = gBagPosition.pocket;

    tPocketSwitchState = 0;
    tPocketSwitchTimer = 0;
    tPocketSwitchDir = deltaBagPocketId;

    if (!skipEraseList)
    {
        ClearWindowTilemap(WIN_ITEM_LIST);
        ClearWindowTilemap(WIN_DESCRIPTION);
        ClearWindowTilemap(WIN_POCKET_NAME);
        DestroyListMenuTask(tListTaskId, &gBagPosition.scrollPosition[gBagPosition.pocket], &gBagPosition.cursorPosition[gBagPosition.pocket]);
        ScheduleBgCopyTilemapToVram(0);
        RemoveBagItemIconSprite(gBagMenu->itemIconSlot ^ 1);
        DestroyPocketScrollArrowPair();
    }
    FillBgTilemapBufferRect_Palette0(1, 0x02D, 11, 1, 18, 12);
    ScheduleBgCopyTilemapToVram(1);
    ChangeBagPocketId(&newPocket, deltaBagPocketId);
    SetBagVisualPocketId(newPocket);
    SetTaskFuncWithFollowupFunc(taskId, Task_SwitchBagPocket, gTasks[taskId].func);
}

static void Task_SwitchBagPocket(u8 taskId)
{
    s16* data = gTasks[taskId].data;

    if (!MenuHelpers_LinkSomething() && !BagIsTutorial())
    {
        switch (GetSwitchBagPocketDirection())
        {
        case SWITCH_POCKET_LEFT:
            ChangeBagPocketId(&gBagPosition.pocket, tPocketSwitchDir);
            SwitchTaskToFollowupFunc(taskId);
            SwitchPockets(taskId, MENU_CURSOR_DELTA_LEFT, TRUE);
            return;
        case SWITCH_POCKET_RIGHT:
            ChangeBagPocketId(&gBagPosition.pocket, tPocketSwitchDir);
            SwitchTaskToFollowupFunc(taskId);
            SwitchPockets(taskId, MENU_CURSOR_DELTA_RIGHT, TRUE);
            return;
        }
    }
    switch (tPocketSwitchState)
    {
    case 0:
        if (tPocketSwitchTimer != 0x7FFF)
        {
            tPocketSwitchTimer++;
            DrawItemListBgRow(tPocketSwitchTimer);
            if (tPocketSwitchTimer == 12)
            tPocketSwitchTimer = 0x7FFF;
        }
        if (tPocketSwitchTimer == 0x7FFF)
            tPocketSwitchState++;
        break;
    case 1:
        ChangeBagPocketId(&gBagPosition.pocket, tPocketSwitchDir);
        PrintPocketNames();
        LoadBagItemListBuffers(gBagPosition.pocket);
        tListTaskId = ListMenuInit(&gMultiuseListMenuTemplate, gBagPosition.scrollPosition[gBagPosition.pocket], gBagPosition.cursorPosition[gBagPosition.pocket]);
        PutWindowTilemap(WIN_DESCRIPTION);
        PutWindowTilemap(WIN_POCKET_NAME);
        ScheduleBgCopyTilemapToVram(0);
        CreatePocketScrollArrowPair();
        CreatePocketSwitchArrowPair();
        SwitchTaskToFollowupFunc(taskId);
        break;
    }
}

static void StartItemSwap(u8 taskId)
{
    u16 cursorPos, itemsAbove;
    s16* data = gTasks[taskId].data;

    ListMenuGetScrollAndRow(tListTaskId, &cursorPos, &itemsAbove);
    ListMenuSetUnkIndicatorsStructField(tListTaskId, 16, 1);
    tListPosition = gBagPosition.scrollPosition[gBagPosition.pocket] + gBagPosition.cursorPosition[gBagPosition.pocket];
    gBagMenu->toSwapPos = tListPosition;
    CopyItemName(BagGetItemIdByPocketPosition(gBagPosition.pocket + 1, tListPosition), gStringVar1);
    StringExpandPlaceholders(gStringVar4, gText_MoveVar1Where);
    FillWindowPixelBuffer(WIN_DESCRIPTION, PIXEL_FILL(0));
    BagMenu_Print(WIN_DESCRIPTION, 2, gStringVar4, 0, 3, 2, 0, 0, COLORID_DESCRIPTION);
    ItemMenuIcons_MoveInsertIndicatorBar(0, ListMenuGetYCoordForPrintingArrowCursor(tListTaskId));
    ItemMenuIcons_ToggleInsertIndicatorBarVisibility(FALSE);
    DestroyPocketSwitchArrowPair();
    BagMenu_PrintCursor(tListTaskId, COLORID_GRAY_CURSOR);
    gTasks[taskId].func = Task_HandleSwappingItemsInput;
}

static void Task_HandleSwappingItemsInput(u8 taskId)
{
    s16* data = gTasks[taskId].data;
    int input;
    u16 itemsAbove, cursorPos;

    if (!MenuHelpers_CallLinkSomething())
    {
        input = ListMenu_ProcessInput(tListTaskId);
        ListMenuGetScrollAndRow(tListTaskId, &gBagPosition.scrollPosition[gBagPosition.pocket], &gBagPosition.cursorPosition[gBagPosition.pocket]);
        ItemMenuIcons_MoveInsertIndicatorBar(0, ListMenuGetYCoordForPrintingArrowCursor(tListTaskId));
        if (JOY_NEW(SELECT_BUTTON))
        {
            PlaySE(SE_SELECT);
            gBagMenu->toSwapPos = NOT_SWAPPING;
            ListMenuGetScrollAndRow(tListTaskId, &cursorPos, &itemsAbove);
            DoItemSwap(taskId, cursorPos + itemsAbove);
            return;
        }
        switch (input)
        {
            case LIST_CANCEL:
                PlaySE(SE_SELECT);
                gBagMenu->toSwapPos = NOT_SWAPPING;
                ListMenuGetScrollAndRow(tListTaskId, &cursorPos, &itemsAbove);
                CancelItemSwap(taskId, cursorPos + itemsAbove);
                break;
            case LIST_NOTHING_CHOSEN:
                return;
            default:
                PlaySE(SE_SELECT);
                gBagMenu->toSwapPos = NOT_SWAPPING;
                DoItemSwap(taskId, input);
                break;
        }
    }
}

static void DoItemSwap(u8 taskId, u32 itemIndex)
{
    s16* data = gTasks[taskId].data;

    if (tListPosition == itemIndex || tListPosition == itemIndex - 1)
        CancelItemSwap(taskId, itemIndex);
    else
    {
        MoveItemSlotInList(gBagPockets[gBagPosition.pocket].itemSlots, tListPosition, itemIndex);
        DestroyListMenuTask(tListTaskId, &gBagPosition.scrollPosition[gBagPosition.pocket], &gBagPosition.cursorPosition[gBagPosition.pocket]);
        if (tListPosition < itemIndex)
            gBagPosition.cursorPosition[gBagPosition.pocket]--;
        LoadBagItemListBuffers(gBagPosition.pocket);
        tListTaskId = ListMenuInit(&gMultiuseListMenuTemplate, gBagPosition.scrollPosition[gBagPosition.pocket], gBagPosition.cursorPosition[gBagPosition.pocket]);
        ItemMenuIcons_ToggleInsertIndicatorBarVisibility(TRUE);
        CreatePocketSwitchArrowPair();
        gTasks[taskId].func = Task_BagMenu_HandleInput;
    }
}

static void CancelItemSwap(u8 taskId, u32 itemIndex)
{
    s16* data = gTasks[taskId].data;

    DestroyListMenuTask(tListTaskId, &gBagPosition.scrollPosition[gBagPosition.pocket], &gBagPosition.cursorPosition[gBagPosition.pocket]);
    if (tListPosition < itemIndex)
        gBagPosition.cursorPosition[gBagPosition.pocket]--;
    LoadBagItemListBuffers(gBagPosition.pocket);
    tListTaskId = ListMenuInit(&gMultiuseListMenuTemplate, gBagPosition.scrollPosition[gBagPosition.pocket], gBagPosition.cursorPosition[gBagPosition.pocket]);
    ItemMenuIcons_ToggleInsertIndicatorBarVisibility(TRUE);
    CreatePocketSwitchArrowPair();
    gTasks[taskId].func = Task_BagMenu_HandleInput;
}

static void InitQuantityToTossOrDeposit(u16 cursorPos, const u8 *str)
{
    u8 itemQtyWindowId;
    u8 itemNameWindowId = BagMenu_AddWindow(ITEMWIN_6, 2);

    CopyItemName(BagGetItemIdByPocketPosition(gBagPosition.pocket + 1, cursorPos), gStringVar1);
    StringExpandPlaceholders(gStringVar4, str);
    BagMenu_Print(itemNameWindowId, 2, gStringVar4, 0, 2, 1, 0, 0, COLORID_NORMAL);
    itemQtyWindowId = BagMenu_AddWindow(ITEMWIN_QUANTITY, 0);
    ConvertIntToDecimalStringN(gStringVar1, 1, STR_CONV_MODE_LEADING_ZEROS, 3);
    StringExpandPlaceholders(gStringVar4, gText_xVar1);
    BagMenu_Print(itemQtyWindowId, 4, gStringVar4, 4, 10, 1, 0, 0, COLORID_NORMAL);
    CreateArrowPair_QuantitySelect();
}

static void UpdateQuantityToTossOrDeposit(s16 value, u8 ndigits)
{
    u8 windowId = BagMenu_GetWindowId(ITEMWIN_QUANTITY);

    FillWindowPixelBuffer(windowId, PIXEL_FILL(1));
    ConvertIntToDecimalStringN(gStringVar1, value, STR_CONV_MODE_LEADING_ZEROS, ndigits);
    StringExpandPlaceholders(gStringVar4, gText_xVar1);
    BagMenu_Print(windowId, 4, gStringVar4, 4, 10, 1, 0, 0, COLORID_NORMAL);
}

static void DrawItemListBgRow(u8 frame)
{
    CopyToBgTilemapBufferRect(1, sBagListBgTiles[12 - frame], 11, 13 - frame, 18, 1);
    ScheduleBgCopyTilemapToVram(1);
}

static void OpenContextMenu(u8 taskId)
{
    u8 windowId;

    switch (gBagPosition.location)
    {
    case ITEMMENULOCATION_BATTLE:
    case ITEMMENULOCATION_WALLY:
        if (ItemId_GetBattleUsage(gSpecialVar_ItemId))
        {
            gBagMenu->contextMenuItemsPtr = sContextMenuItems_BattleUse;
            gBagMenu->contextMenuNumItems = ARRAY_COUNT(sContextMenuItems_BattleUse);
        }
        else
        {
            gBagMenu->contextMenuItemsPtr = sContextMenuItems_Cancel;
            gBagMenu->contextMenuNumItems = ARRAY_COUNT(sContextMenuItems_Cancel);
        }
        break;
    case ITEMMENULOCATION_BERRY_BLENDER_CRUSH:
        gBagMenu->contextMenuItemsPtr = sContextMenuItems_BerryCrush;
        gBagMenu->contextMenuNumItems = ARRAY_COUNT(sContextMenuItems_BerryCrush);
        break;
    case ITEMMENULOCATION_APPRENTICE:
        if (!ItemId_GetImportance(gSpecialVar_ItemId) && gSpecialVar_ItemId != ITEM_ENIGMA_BERRY)
        {
            gBagMenu->contextMenuItemsPtr = sContextMenuItems_Apprentice;
            gBagMenu->contextMenuNumItems = ARRAY_COUNT(sContextMenuItems_Apprentice);
        }
        else
        {
            gBagMenu->contextMenuItemsPtr = sContextMenuItems_Cancel;
            gBagMenu->contextMenuNumItems = ARRAY_COUNT(sContextMenuItems_Cancel);
        }
        break;
    default:
        if (MenuHelpers_LinkSomething() || InUnionRoom())
        {
            if (gBagPosition.pocket == KEYITEMS_POCKET)
            {
                gBagMenu->contextMenuItemsPtr = sContextMenuItems_Cancel;
                gBagMenu->contextMenuNumItems = ARRAY_COUNT(sContextMenuItems_Cancel);
            }
            else
            {
                gBagMenu->contextMenuItemsPtr = sContextMenuItems_Give;
                gBagMenu->contextMenuNumItems = ARRAY_COUNT(sContextMenuItems_Give);
            }
        }
        else if (ItemId_GetImportance(gSpecialVar_ItemId) == 1)
        {
            gBagMenu->contextMenuItemsPtr = sContextMenuItems_TossCancel;
            gBagMenu->contextMenuNumItems = ARRAY_COUNT(sContextMenuItems_TossCancel);
        }
        else
        {
            switch (gBagPosition.pocket)
            {
            case ITEMS_POCKET:
                if (ItemIsMail(gSpecialVar_ItemId))
                {
                    gBagMenu->contextMenuItemsPtr = sContextMenuItems_CheckGiveTossCancel;
                    gBagMenu->contextMenuNumItems = ARRAY_COUNT(sContextMenuItems_CheckGiveTossCancel);
                }
                else
                {
                    gBagMenu->contextMenuItemsPtr = sContextMenuItems_Field[gBagPosition.pocket];
                    gBagMenu->contextMenuNumItems = ARRAY_COUNT(sContextMenuItems_Field[gBagPosition.pocket]) - 1;
                }
                break;
            case KEYITEMS_POCKET:
                gBagMenu->contextMenuItemsPtr = gBagMenu->contextMenuItemsBuffer;
                gBagMenu->contextMenuNumItems = ARRAY_COUNT(sContextMenuItems_Field[gBagPosition.pocket]) - 2;
                memcpy(&gBagMenu->contextMenuItemsBuffer, &sContextMenuItems_Field[gBagPosition.pocket], sizeof(sContextMenuItems_Field[gBagPosition.pocket] - 2));
                if (gSaveBlock1Ptr->registeredItem == gSpecialVar_ItemId)
                    gBagMenu->contextMenuItemsBuffer[1] = ACTION_DESELECT;
                if (gSpecialVar_ItemId == ITEM_BICYCLE && TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_BIKE))
                    gBagMenu->contextMenuItemsBuffer[0] = ACTION_WALK;
                break;
            case BERRIES_POCKET:
                gBagMenu->contextMenuItemsPtr = sContextMenuItems_Field[gBagPosition.pocket];
                gBagMenu->contextMenuNumItems = ARRAY_COUNT(sContextMenuItems_Field[gBagPosition.pocket]);
                break;
            default:
                gBagMenu->contextMenuItemsPtr = sContextMenuItems_Field[gBagPosition.pocket];
                gBagMenu->contextMenuNumItems = ARRAY_COUNT(sContextMenuItems_Field[gBagPosition.pocket]) - 2;
                break;
            }
        }
    }
    windowId = BagMenu_AddWindow(ITEMWIN_LIST, gBagMenu->contextMenuNumItems - 1);
    AddItemMenuActionTextPrinters(
        windowId,
        2,
        GetMenuCursorDimensionByFont(2, 0),
        2,
        GetFontAttribute(2, FONTATTR_LETTER_SPACING),
        GetFontAttribute(2, FONTATTR_MAX_LETTER_HEIGHT) + 2,
        gBagMenu->contextMenuNumItems,
        sItemMenuActions,
        gBagMenu->contextMenuItemsPtr
    );
    InitMenuInUpperLeftCorner(windowId, 2, 0, 2, GetFontAttribute(2, FONTATTR_MAX_LETTER_HEIGHT) + 2, gBagMenu->contextMenuNumItems, 0, 0);
    windowId = BagMenu_AddWindow(ITEMWIN_6, 0);
    CopyItemName(gSpecialVar_ItemId, gStringVar1);
    StringExpandPlaceholders(gStringVar4, gText_Var1IsSelected);
    BagMenu_Print(windowId, 2, gStringVar4, 0, 2, 1, 0, 0, COLORID_NORMAL);
}

static void Task_ItemContext_Normal(u8 taskId)
{
    OpenContextMenu(taskId);
    gTasks[taskId].func = Task_ItemContext_SingleRow;
}

static void Task_ItemContext_SingleRow(u8 taskId)
{
    if (!MenuHelpers_CallLinkSomething())
    {
        s8 selection = Menu_ProcessInputNoWrap();
        switch (selection)
        {
            case MENU_B_PRESSED:
                PlaySE(SE_SELECT);
                sItemMenuActions[ACTION_CANCEL].func.void_u8(taskId);
            case MENU_NOTHING_CHOSEN:
                break;
            default:
                PlaySE(SE_SELECT);
                sItemMenuActions[gBagMenu->contextMenuItemsPtr[selection]].func.void_u8(taskId);
                break;
        }
    }
}

static void ItemMenu_UseOutOfBattle(u8 taskId)
{
    if (ItemId_GetFieldFunc(gSpecialVar_ItemId))
    {
        BagMenu_RemoveWindow(ITEMWIN_LIST);
        BagMenu_RemoveWindow(ITEMWIN_6);
        PutWindowTilemap(WIN_ITEM_LIST);
        PutWindowTilemap(WIN_DESCRIPTION);
        ScheduleBgCopyTilemapToVram(0);
        if (!CalculatePlayerPartyCount() && ItemId_GetType(gSpecialVar_ItemId) == ITEM_USE_PARTY_MENU)
            Task_PrintThereIsNoPokemon(taskId);
        else
        {
            if (gBagPosition.pocket != BERRIES_POCKET)
                ItemId_GetFieldFunc(gSpecialVar_ItemId)(taskId);
            else
                ItemUseOutOfBattle_Berry(taskId);
        }
    }
}

static void ItemMenu_Toss(u8 taskId)
{
    s16* data = gTasks[taskId].data;

    ClearWindowTilemap(BagMenu_GetWindowId(ITEMWIN_LIST));
    ClearWindowTilemap(BagMenu_GetWindowId(ITEMWIN_6));
    BagMenu_RemoveWindow(ITEMWIN_LIST);
    BagMenu_RemoveWindow(ITEMWIN_6);
    PutWindowTilemap(WIN_ITEM_LIST);
    tItemCount = 1;
    if (tQuantity == 1)
        Task_ConfirmTossItems(taskId);
    else
    {
        InitQuantityToTossOrDeposit(tListPosition, gText_TossHowManyVar1s);
        gTasks[taskId].func = Task_SelectQuantityToToss;
    }
}

static void Task_ConfirmTossItems(u8 taskId)
{
    s16* data = gTasks[taskId].data;

    CopyItemName(gSpecialVar_ItemId, gStringVar1);
    ConvertIntToDecimalStringN(gStringVar2, tItemCount, STR_CONV_MODE_LEFT_ALIGN, MAX_ITEM_DIGITS);
    StringExpandPlaceholders(gStringVar4, gText_ConfirmTossItems);
    BagMenu_Print(BagMenu_AddWindow(ITEMWIN_6, 1), 2, gStringVar4, 0, 2, 1, 0, 0, COLORID_NORMAL);
    BagMenu_YesNo(taskId, &sYesNoTossFunctions);
}

static void Task_TossItem_No(u8 taskId)
{
    s16* data = gTasks[taskId].data;

    BagMenu_RemoveWindow(ITEMWIN_6);
    PutWindowTilemap(WIN_DESCRIPTION);
    ScheduleBgCopyTilemapToVram(0);
    BagMenu_PrintCursor(tListTaskId, COLORID_NORMAL);
    ReturnToItemList(taskId);
}

static void Task_SelectQuantityToToss(u8 taskId)
{
    s16* data = gTasks[taskId].data;

    if (AdjustQuantityAccordingToDPadInput(&tItemCount, tQuantity))
        UpdateQuantityToTossOrDeposit(tItemCount, 3);
    else if (JOY_NEW(A_BUTTON))
    {
        PlaySE(SE_SELECT);
        ClearWindowTilemap(BagMenu_GetWindowId(ITEMWIN_6));
        BagMenu_RemoveWindow(ITEMWIN_6);
        BagMenu_RemoveWindow(ITEMWIN_QUANTITY);
        ScheduleBgCopyTilemapToVram(0);
        DestroyPocketScrollArrowPair();
        Task_ConfirmTossItems(taskId);
    }
    else if (JOY_NEW(B_BUTTON))
    {
        PlaySE(SE_SELECT);
        BagMenu_RemoveWindow(ITEMWIN_6);
        BagMenu_RemoveWindow(ITEMWIN_QUANTITY);
        PutWindowTilemap(WIN_ITEM_LIST);
        PutWindowTilemap(WIN_DESCRIPTION);
        ScheduleBgCopyTilemapToVram(0);
        BagMenu_PrintCursor(tListTaskId, COLORID_NORMAL);
        DestroyPocketScrollArrowPair();
        ReturnToItemList(taskId);
    }
}

static void Task_TossItem_Yes(u8 taskId)
{
    s16* data = gTasks[taskId].data;

    BagMenu_RemoveWindow(ITEMWIN_6);
    CopyItemName(gSpecialVar_ItemId, gStringVar1);
    ConvertIntToDecimalStringN(gStringVar2, tItemCount, STR_CONV_MODE_LEFT_ALIGN, MAX_ITEM_DIGITS);
    StringExpandPlaceholders(gStringVar4, gText_ThrewAwayVar2Var1s);
    BagMenu_Print(BagMenu_AddWindow(ITEMWIN_6, 3), 2, gStringVar4, 0, 2, 1, 0, 0, COLORID_NORMAL);
    gTasks[taskId].func = Task_RemoveItemFromBag;
}

static void Task_RemoveItemFromBag(u8 taskId)
{
    s16* data = gTasks[taskId].data;
    u16* scrollPos = &gBagPosition.scrollPosition[gBagPosition.pocket];
    u16* cursorPos = &gBagPosition.cursorPosition[gBagPosition.pocket];

    if (JOY_NEW(A_BUTTON | B_BUTTON))
    {
        PlaySE(SE_SELECT);
        RemoveBagItem(gSpecialVar_ItemId, tItemCount);
        BagMenu_RemoveWindow(ITEMWIN_6);
        DestroyListMenuTask(tListTaskId, scrollPos, cursorPos);
        UpdatePocketItemList(gBagPosition.pocket);
        UpdatePocketListPosition(gBagPosition.pocket);
        LoadBagItemListBuffers(gBagPosition.pocket);
        tListTaskId = ListMenuInit(&gMultiuseListMenuTemplate, *scrollPos, *cursorPos);
        PutWindowTilemap(WIN_DESCRIPTION);
        ScheduleBgCopyTilemapToVram(0);
        BagMenu_PrintCursor(tListTaskId, COLORID_NORMAL);
        ReturnToItemList(taskId);
    }
}

static void ItemMenu_Register(u8 taskId)
{
    s16* data = gTasks[taskId].data;
    u16* scrollPos = &gBagPosition.scrollPosition[gBagPosition.pocket];
    u16* cursorPos = &gBagPosition.cursorPosition[gBagPosition.pocket];

    if (gSaveBlock1Ptr->registeredItem == gSpecialVar_ItemId)
        gSaveBlock1Ptr->registeredItem = ITEM_NONE;
    else
        gSaveBlock1Ptr->registeredItem = gSpecialVar_ItemId;

    DestroyListMenuTask(tListTaskId, scrollPos, cursorPos);
    LoadBagItemListBuffers(gBagPosition.pocket);
    tListTaskId = ListMenuInit(&gMultiuseListMenuTemplate, *scrollPos, *cursorPos);
    CopyWindowToVram(0, 1);
    ItemMenu_Cancel(taskId);
}

static void ItemMenu_Give(u8 taskId)
{
    BagMenu_RemoveWindow(ITEMWIN_LIST);
    BagMenu_RemoveWindow(ITEMWIN_6);
    PutWindowTilemap(WIN_ITEM_LIST);
    PutWindowTilemap(WIN_DESCRIPTION);
    CopyWindowToVram(0, 1);
    if (!IsWritingMailAllowed(gSpecialVar_ItemId))
        DisplayItemMessage(taskId, 2, gText_CantWriteMail, HandleErrorMessage);
    else if (!ItemId_GetImportance(gSpecialVar_ItemId) && (gSpecialVar_ItemId != ITEM_SLOWPOKE_TAIL && gSpecialVar_ItemId != ITEM_RAGE_CANDY_BAR))
    {
        if (CalculatePlayerPartyCount())
        {
            gBagMenu->newScreenCallback = CB2_ChooseMonToGiveItem;
            Task_FadeAndCloseBagMenu(taskId);
        }
        else
            Task_PrintThereIsNoPokemon(taskId);
    }
    else
        Task_PrintItemCantBeHeld(taskId);
}

static void Task_PrintThereIsNoPokemon(u8 taskId)
{
    DisplayItemMessage(taskId, 2, gText_NoPokemon, HandleErrorMessage);
}

static void Task_PrintItemCantBeHeld(u8 taskId)
{
    CopyItemName(gSpecialVar_ItemId, gStringVar1);
    StringExpandPlaceholders(gStringVar4, gText_Var1CantBeHeld);
    DisplayItemMessage(taskId, 2, gStringVar4, HandleErrorMessage);
}

static void HandleErrorMessage(u8 taskId)
{
    if (JOY_NEW(A_BUTTON))
    {
        PlaySE(SE_SELECT);
        CloseItemMessage(taskId);
    }
}

void CloseItemMessage(u8 taskId)
{
    s16* data = gTasks[taskId].data;
    u16* scrollPos = &gBagPosition.scrollPosition[gBagPosition.pocket];
    u16* cursorPos = &gBagPosition.cursorPosition[gBagPosition.pocket];

    RemoveItemMessageWindow(ITEMWIN_MESSAGE);
    DestroyListMenuTask(tListTaskId, scrollPos, cursorPos);
    UpdatePocketItemList(gBagPosition.pocket);
    UpdatePocketListPosition(gBagPosition.pocket);
    LoadBagItemListBuffers(gBagPosition.pocket);
    tListTaskId = ListMenuInit(&gMultiuseListMenuTemplate, *scrollPos, *cursorPos);
    ScheduleBgCopyTilemapToVram(0);
    //BagMenu_PrintCursorAtPos(tListTaskId, COLORID_NORMAL);
    ReturnToItemList(taskId);
}

static void ItemMenu_ViewTag(u8 taskId)
{
    gBagMenu->newScreenCallback = DoBerryTagScreen;
    Bag_BeginCloseWin0Animation();
    Task_FadeAndCloseBagMenu(taskId);
}

static void ItemMenu_Cancel(u8 taskId)
{
    BagMenu_RemoveWindow(ITEMWIN_LIST);
    BagMenu_RemoveWindow(ITEMWIN_6);
    PutWindowTilemap(WIN_ITEM_LIST);
    PutWindowTilemap(WIN_DESCRIPTION);
    ScheduleBgCopyTilemapToVram(0);
    BagMenu_PrintCursor(gTasks[taskId].tListTaskId, COLORID_NORMAL);
    ReturnToItemList(taskId);
}

static void ItemMenu_UseInBattle(u8 taskId)
{
    if (ItemId_GetBattleFunc(gSpecialVar_ItemId))
    {
        BagMenu_RemoveWindow(ITEMWIN_LIST);
        BagMenu_RemoveWindow(ITEMWIN_6);
        PutWindowTilemap(WIN_ITEM_LIST);
        PutWindowTilemap(WIN_DESCRIPTION);
        CopyWindowToVram(0, 1);
        ItemId_GetBattleFunc(gSpecialVar_ItemId)(taskId);
    }
}

static void Task_ItemContext_GiveToParty(u8 taskId)
{
    s16* data = gTasks[taskId].data;

    if (!IsWritingMailAllowed(gSpecialVar_ItemId))
        DisplayItemMessage(taskId, 2, gText_CantWriteMail, HandleErrorMessage);
    else if (!IsHoldingItemAllowed(gSpecialVar_ItemId))
    {
        CopyItemName(gSpecialVar_ItemId, gStringVar1);
        StringExpandPlaceholders(gStringVar4, gText_Var1CantBeHeldHere);
        DisplayItemMessage(taskId, 2, gStringVar4, HandleErrorMessage);
    }
    else if ((gBagPosition.pocket != KEYITEMS_POCKET && !ItemId_GetImportance(gSpecialVar_ItemId))
             && (gSpecialVar_ItemId != ITEM_SLOWPOKE_TAIL && gSpecialVar_ItemId != ITEM_RAGE_CANDY_BAR))
    {
        Bag_BeginCloseWin0Animation();
        gTasks[taskId].func = Task_FadeAndCloseBagMenu;
    }
    else
        Task_PrintItemCantBeHeld(taskId);
}

void CB2_ReturnToBagMenuPocket(void)
{
    GoToBagMenu(ITEMMENULOCATION_LAST, POCKETS_COUNT, NULL);
}

// Choosing berry to plant
void CB2_ChooseBerry(void)
{
    GoToBagMenu(ITEMMENULOCATION_BERRY_TREE, BERRIES_POCKET, CB2_ReturnToFieldContinueScript);
}

// Choosing berry for Berry Crush
void ChooseBerryForMachine(void (*exitCallback)(void))
{
    GoToBagMenu(ITEMMENULOCATION_BERRY_BLENDER_CRUSH, BERRIES_POCKET, exitCallback);
}

void CB2_GoToSellMenu(void)
{
    GoToBagMenu(ITEMMENULOCATION_SHOP, POCKETS_COUNT, CB2_ExitSellMenu);
}

void CB2_GoToItemDepositMenu(void)
{
    GoToBagMenu(ITEMMENULOCATION_ITEMPC, POCKETS_COUNT, CB2_PlayerPCExitBagMenu);
}

void ApprenticeOpenBagMenu(void)
{
    GoToBagMenu(ITEMMENULOCATION_APPRENTICE, POCKETS_COUNT, CB2_ApprenticeExitBagMenu);
    gSpecialVar_0x8005 = ITEM_NONE;
    gSpecialVar_Result = FALSE;
}

static void Task_ItemContext_PcBoxGive(u8 taskId)
{
    if (ItemIsMail(gSpecialVar_ItemId))
        DisplayItemMessage(taskId, 2, gText_CantWriteMail, HandleErrorMessage);
    else if ((gBagPosition.pocket != KEYITEMS_POCKET && !ItemId_GetImportance(gSpecialVar_ItemId))
             && (gSpecialVar_ItemId != ITEM_SLOWPOKE_TAIL && gSpecialVar_ItemId != ITEM_RAGE_CANDY_BAR))
    {
        Bag_BeginCloseWin0Animation();
        gTasks[taskId].func = Task_FadeAndCloseBagMenu;
    }
    else
        Task_PrintItemCantBeHeld(taskId);
}

static void Task_ItemContext_Sell(u8 taskId)
{
    s16* data = gTasks[taskId].data;

    if (ItemId_GetPrice(gSpecialVar_ItemId))
    {
        tItemCount = 1;
        if (tQuantity == 1)
        {
            DisplayCurrentMoneyWindow();
            DisplaySellItemPriceAndConfirm(taskId);
        }
        else
        {
            CopyItemName(gSpecialVar_ItemId, gStringVar1);
            StringExpandPlaceholders(gStringVar4, gText_HowManyToSell);
            DisplayItemMessage(taskId, 2, gStringVar4, InitSellHowManyInput);
        }
    }
    else
    {
        CopyItemName(gSpecialVar_ItemId, gStringVar1);
        StringExpandPlaceholders(gStringVar4, gText_CantBuyKeyItem);
        DisplayItemMessage(taskId, 2, gStringVar4, CloseItemMessage);
    }
}

static void DisplaySellItemPriceAndConfirm(u8 taskId)
{
    s16* data = gTasks[taskId].data;

    ConvertIntToDecimalStringN(gStringVar3, (ItemId_GetPrice(gSpecialVar_ItemId) / 2) * tItemCount, STR_CONV_MODE_LEFT_ALIGN, 6);
    StringExpandPlaceholders(gStringVar4, gText_ICanPayVar1);
    DisplayItemMessage(taskId, 2, gStringVar4, AskSellItems);
}

static void AskSellItems(u8 taskId)
{
    BagMenu_YesNoTopRight(taskId, &sYesNoSellItemFunctions);
}

static void CancelSell(u8 taskId)
{
    s16* data = gTasks[taskId].data;

    BagMenu_RemoveWindow(2);
    RemoveItemMessageWindow(ITEMWIN_MESSAGE);
    PutWindowTilemap(2);
    PutWindowTilemap(0);
    PutWindowTilemap(1);
    ScheduleBgCopyTilemapToVram(0);
    BagMenu_PrintCursor(tListTaskId, COLORID_NORMAL);
    ReturnToItemList(taskId);
}

static void InitSellHowManyInput(u8 taskId)
{
    s16* data = gTasks[taskId].data;
    u8 windowId = BagMenu_AddWindow(ITEMWIN_QUANTITY, 1);

    PrintItemSoldAmount(windowId, 1, (ItemId_GetPrice(gSpecialVar_ItemId) / 2) * tItemCount);
    DisplayCurrentMoneyWindow();

    gTasks[taskId].func = Task_ChooseHowManyToSell;
}

static void Task_ChooseHowManyToSell(u8 taskId)
{
    s16* data = gTasks[taskId].data;

    if (AdjustQuantityAccordingToDPadInput(&tItemCount, tQuantity))
        PrintItemSoldAmount(BagMenu_GetWindowId(ITEMWIN_QUANTITY), tItemCount, (ItemId_GetPrice(gSpecialVar_ItemId) / 2) * tItemCount);
    else if (JOY_NEW(A_BUTTON))
    {
        PlaySE(SE_SELECT);
        BagMenu_RemoveWindow(ITEMWIN_QUANTITY);
        PutWindowTilemap(WIN_ITEM_LIST);
        ScheduleBgCopyTilemapToVram(0);
        DestroyPocketScrollArrowPair();
        DisplaySellItemPriceAndConfirm(taskId);
    }
    else if (JOY_NEW(B_BUTTON))
    {
        PlaySE(SE_SELECT);
        BagMenu_RemoveWindow(ITEMWIN_QUANTITY);
        BagMenu_RemoveWindow(2);
        RemoveItemMessageWindow(ITEMWIN_MESSAGE);
        PutWindowTilemap(WIN_POCKET_NAME);
        PutWindowTilemap(WIN_ITEM_LIST);
        PutWindowTilemap(WIN_DESCRIPTION);
        ScheduleBgCopyTilemapToVram(0);
        DestroyPocketScrollArrowPair();
        BagMenu_PrintCursor(tListTaskId, COLORID_GRAY_CURSOR);
        ReturnToItemList(taskId);
    }
}

static void ConfirmSell(u8 taskId)
{
    s16* data = gTasks[taskId].data;

    PutWindowTilemap(WIN_ITEM_LIST);
    ScheduleBgCopyTilemapToVram(0);
    CopyItemName(gSpecialVar_ItemId, gStringVar1);
    ConvertIntToDecimalStringN(gStringVar3, (ItemId_GetPrice(gSpecialVar_ItemId) / 2) * tItemCount, STR_CONV_MODE_LEFT_ALIGN, 6);
    StringExpandPlaceholders(gStringVar4, gText_TurnedOverVar1ForVar2);
    DisplayItemMessage(taskId, 2, gStringVar4, SellItem);
}

static void SellItem(u8 taskId)
{
    s16* data = gTasks[taskId].data;
    u16* scrollPos = &gBagPosition.scrollPosition[gBagPosition.pocket];
    u16* cursorPos = &gBagPosition.cursorPosition[gBagPosition.pocket];

    PlaySE(SE_RG_SHOP);
    RemoveBagItem(gSpecialVar_ItemId, tItemCount);
    AddMoney(&gSaveBlock1Ptr->money, (ItemId_GetPrice(gSpecialVar_ItemId) / 2) * tItemCount);
    DestroyListMenuTask(tListTaskId, scrollPos, cursorPos);
    UpdatePocketItemList(gBagPosition.pocket);
    UpdatePocketListPosition(gBagPosition.pocket);
    gBagMenu->inhibitItemDescriptionPrint = TRUE;
    LoadBagItemListBuffers(gBagPosition.pocket);
    tListTaskId = ListMenuInit(&gMultiuseListMenuTemplate, *scrollPos, *cursorPos);
    BagMenu_PrintCursor(tListTaskId, COLORID_GRAY_CURSOR);
    BagDrawTextBoxOnWindow(BagMenu_GetWindowId(ITEMWIN_2x2));
    PrintMoneyAmountInMoneyBox(BagMenu_GetWindowId(ITEMWIN_2x2), GetMoney(&gSaveBlock1Ptr->money), 0);
    gTasks[taskId].func = WaitAfterItemSell;
}

static void WaitAfterItemSell(u8 taskId)
{
    if (JOY_NEW(A_BUTTON | B_BUTTON))
    {
        PlaySE(SE_SELECT);
        BagMenu_RemoveWindow(2);
        PutWindowTilemap(WIN_POCKET_NAME);
        gBagMenu->inhibitItemDescriptionPrint = FALSE;
        CloseItemMessage(taskId);
    }
}

static void WaitDepositErrorMessage(u8 taskId)
{
    s16* data = gTasks[taskId].data;

    if (JOY_NEW(A_BUTTON | B_BUTTON))
    {
        PlaySE(SE_SELECT);
        CloseItemMessage(taskId);
    }
}

// This action is used to show the Apprentice an item when
// they ask what item they should make their Pokémon hold
static void ItemMenu_Show(u8 taskId)
{
    gSpecialVar_0x8005 = gSpecialVar_ItemId;
    gSpecialVar_Result = FALSE;
    Bag_BeginCloseWin0Animation();
    Task_FadeAndCloseBagMenu(taskId);
}

static void CB2_ApprenticeExitBagMenu(void)
{
    gFieldCallback = Apprentice_EnableBothScriptContexts;
    SetMainCallback2(CB2_ReturnToField);
}

static void Task_ItemContext_Deposit(u8 taskId)
{
    s16* data = gTasks[taskId].data;

    tItemCount = 1;
    if (tQuantity == 1)
        TryDepositItem(taskId);
    else
    {
        InitQuantityToTossOrDeposit(tListPosition, gText_DepositHowManyVar1);
        gTasks[taskId].func = Task_ChooseHowManyToDeposit;
    }
}

static void Task_ChooseHowManyToDeposit(u8 taskId)
{
    s16* data = gTasks[taskId].data;

    if (AdjustQuantityAccordingToDPadInput(&tItemCount, tQuantity))
        UpdateQuantityToTossOrDeposit(tItemCount, 3);
    else if (JOY_NEW(A_BUTTON))
    {
        PlaySE(SE_SELECT);
        ClearWindowTilemap(BagMenu_GetWindowId(ITEMWIN_6));
        BagMenu_RemoveWindow(ITEMWIN_6);
        BagMenu_RemoveWindow(ITEMWIN_QUANTITY);
        ScheduleBgCopyTilemapToVram(0);
        DestroyPocketScrollArrowPair();
        TryDepositItem(taskId);
    }
    else if (JOY_NEW(B_BUTTON))
    {
        PlaySE(SE_SELECT);
        BagMenu_RemoveWindow(ITEMWIN_6);
        BagMenu_RemoveWindow(ITEMWIN_QUANTITY);
        PutWindowTilemap(WIN_DESCRIPTION);
        ScheduleBgCopyTilemapToVram(0);
        BagMenu_PrintCursor(tListTaskId, COLORID_NORMAL);
        DestroyPocketScrollArrowPair();
        ReturnToItemList(taskId);
    }
}

static void TryDepositItem(u8 taskId)
{
    s16* data = gTasks[taskId].data;

    FillWindowPixelBuffer(WIN_DESCRIPTION, PIXEL_FILL(0));
    if (ItemId_GetImportance(gSpecialVar_ItemId) > 1)
        // Can't deposit important items
        DisplayItemMessage(taskId, 2, gText_CantStoreImportantItems, WaitDepositErrorMessage);
    else if (AddPCItem(gSpecialVar_ItemId, tItemCount))
    {
        // Successfully deposited
        CopyItemName(gSpecialVar_ItemId, gStringVar1);
        ConvertIntToDecimalStringN(gStringVar2, tItemCount, STR_CONV_MODE_LEFT_ALIGN, MAX_ITEM_DIGITS);
        StringExpandPlaceholders(gStringVar4, gText_DepositedVar2Var1s);
        BagMenu_Print(BagMenu_AddWindow(ITEMWIN_6, 3), 2, gStringVar4, 0, 2, 1, 0, 0, COLORID_NORMAL);
        gTasks[taskId].func = Task_RemoveItemFromBag;
    }
    else
        // No room to deposit
        DisplayItemMessage(taskId, 2, gText_NoRoomForItems, WaitDepositErrorMessage);
}

#undef tListPosition
#undef tQuantity
#undef tItemCount
#undef tMsgWindowId
#undef tPocketSwitchDir
#undef tPocketSwitchTimer
#undef tPocketSwitchState

#define tUsingRegisteredKeyItem data[3] // See usage in item_use.c

bool8 UseRegisteredKeyItemOnField(void)
{
    u8 taskId;

    if (InUnionRoom() || InBattlePyramid() || InBattlePike() || InMultiPartnerRoom())
        return FALSE;
    DismissMapNamePopup();
    ChangeBgY_ScreenOff(0, 0, 0);
    if (gSaveBlock1Ptr->registeredItem != ITEM_NONE)
    {
        if (CheckBagHasItem(gSaveBlock1Ptr->registeredItem, 1))
        {
            ScriptContext2_Enable();
            FreezeObjectEvents();
            PlayerFreeze();
            sub_808BCF4();
            gSpecialVar_ItemId = gSaveBlock1Ptr->registeredItem;
            taskId = CreateTask(ItemId_GetFieldFunc(gSaveBlock1Ptr->registeredItem), 8);
            gTasks[taskId].tUsingRegisteredKeyItem = TRUE;
            return TRUE;
        }
        gSaveBlock1Ptr->registeredItem = ITEM_NONE;
    }
    ScriptContext1_SetupScript(EventScript_SelectWithoutRegisteredItem);
    return TRUE;
}

#undef tUsingRegisteredKeyItem

static bool8 BagIsTutorial(void)
{
    if (gBagPosition.location == ITEMMENULOCATION_WALLY)
        return TRUE;
    return FALSE;
}

static void BackUpPlayerBag(void)
{
    u32 i;

    sBackupPlayerBag = AllocZeroed(sizeof(*sBackupPlayerBag));
    memcpy(sBackupPlayerBag->bagPocket_Items, gSaveBlock1Ptr->bagPocket_Items, sizeof(gSaveBlock1Ptr->bagPocket_Items));
    memcpy(sBackupPlayerBag->bagPocket_PokeBalls, gSaveBlock1Ptr->bagPocket_PokeBalls, sizeof(gSaveBlock1Ptr->bagPocket_PokeBalls));
    sBackupPlayerBag->pocket = gBagPosition.pocket;
    for (i = 0; i < POCKETS_COUNT; i++)
    {
        sBackupPlayerBag->cursorPosition[i] = gBagPosition.cursorPosition[i];
        sBackupPlayerBag->scrollPosition[i] = gBagPosition.scrollPosition[i];
    }
    ClearItemSlots(gSaveBlock1Ptr->bagPocket_Items, BAG_ITEMS_COUNT);
    ClearItemSlots(gSaveBlock1Ptr->bagPocket_PokeBalls, BAG_POKEBALLS_COUNT);
    ResetBagCursorPositions();
}

static void RestorePlayerBag(void)
{
    u32 i;

    memcpy(gSaveBlock1Ptr->bagPocket_Items, sBackupPlayerBag->bagPocket_Items, sizeof(sBackupPlayerBag->bagPocket_Items));
    memcpy(gSaveBlock1Ptr->bagPocket_PokeBalls, sBackupPlayerBag->bagPocket_PokeBalls, sizeof(sBackupPlayerBag->bagPocket_PokeBalls));
    gBagPosition.pocket = sBackupPlayerBag->pocket;
    for (i = 0; i < POCKETS_COUNT; i++)
    {
        gBagPosition.cursorPosition[i] = sBackupPlayerBag->cursorPosition[i];
        gBagPosition.scrollPosition[i] = sBackupPlayerBag->scrollPosition[i];
    }
    Free(sBackupPlayerBag);
}

void DoWallyTutorialBagMenu(void)
{
    BackUpPlayerBag();
    AddBagItem(ITEM_POTION, 1);
    AddBagItem(ITEM_POKE_BALL, 1);
    GoToBagMenu(ITEMMENULOCATION_WALLY, ITEMS_POCKET, CB2_SetUpReshowBattleScreenAfterMenu2);
}

#define tTimer data[8]
#define WALLY_BAG_DELAY 102 // The number of frames between each action Wally takes in the bag

static void Task_Bag_WallyTutorialBagMenu(u8 taskId)
{
    s16* data = gTasks[taskId].data;

    if (!gPaletteFade.active)
    {
        switch (tTimer)
        {
        case WALLY_BAG_DELAY * 1:
            PlaySE(SE_RG_BAG_POCKET);
            SwitchPockets(taskId, MENU_CURSOR_DELTA_RIGHT, FALSE);
            tTimer++;
            break;
        case WALLY_BAG_DELAY * 2:
            PlaySE(SE_SELECT);
            BagMenu_PrintCursor(tListTaskId, COLORID_GRAY_CURSOR);
            Bag_FillMessageBoxWithPalette(1);
            gSpecialVar_ItemId = ITEM_POKE_BALL;
            OpenContextMenu(taskId);
        default:
            tTimer++;
            break;
        case WALLY_BAG_DELAY * 3:
            PlaySE(SE_SELECT);
            BagMenu_RemoveWindow(ITEMWIN_LIST);
            BagMenu_RemoveWindow(ITEMWIN_6);
            PutWindowTilemap(WIN_ITEM_LIST);
            PutWindowTilemap(WIN_DESCRIPTION);
            CopyWindowToVram(0, 1);
            DestroyListMenuTask(tListTaskId, 0, 0);
            RestorePlayerBag();
            Bag_BeginCloseWin0Animation();
            Task_FadeAndCloseBagMenu(taskId);
            break;
        }
    }
}

/*static void RemoveMoneyWindow(void)
{
    BagMenu_RemoveWindow(ITEMWIN_2x2);
    RemoveMoneyLabelObject();
}*/

#undef tListTaskId

// These functions are in bag.c in FRLG
static const u16 sBagWindowPalF[] = INCBIN_U16("graphics/item_menu/bag_window_pal.gbapal");
static const u16 sPal3Override[] = {RGB(8, 8, 8), RGB(30, 16, 6)};

static const u8 sFontColorTable[][3] =
{
    /*                       bgColor,                textColor,             shadowColor*/
    [COLORID_DESCRIPTION] = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_WHITE,      TEXT_COLOR_DARK_GRAY},
    [COLORID_NORMAL]      = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_DARK_GRAY,  TEXT_COLOR_LIGHT_GRAY},
    [COLORID_GRAY_CURSOR] = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_LIGHT_GRAY, TEXT_COLOR_DARK_GRAY}
};

static const struct WindowTemplate sDefaultBagWindows[] =
{
    [WIN_ITEM_LIST] = {
        .bg = 0,
        .tilemapLeft = 0xB,
        .tilemapTop = 0x1,
        .width = 0x12,
        .height = 0xC,
        .paletteNum = 0xF,
        .baseBlock = 0x8A
    },
    [WIN_DESCRIPTION] = {
        .bg = 0,
        .tilemapLeft = 0x5,
        .tilemapTop = 0xE,
        .width = 0x19,
        .height = 0x6,
        .paletteNum = 0xF,
        .baseBlock = 0x162
    },
    [WIN_POCKET_NAME] = {
        .bg = 0,
        .tilemapLeft = 0x1,
        .tilemapTop = 0x1,
        .width = 0x9,
        .height = 0x2,
        .paletteNum = 0xF,
        .baseBlock = 0x1F8
    },
    DUMMY_WIN_TEMPLATE
};

// Names and comments are rough guesses, not sure if they're accurate
static const struct WindowTemplate sContextMenuWindowTemplates[] =
{
    [ITEMWIN_QUANTITY] = { // Used for quantity of items to Toss/Deposit
        .bg = 0,
        .tilemapLeft = 24,
        .tilemapTop = 15,
        .width = 5,
        .height = 4,
        .paletteNum = 0xF,
        .baseBlock = 0x242
    },
    [ITEMWIN_MONEY] = { // Used for quantity and price of items to Sell
        .bg = 0,
        .tilemapLeft = 17,
        .tilemapTop = 9,
        .width = 12,
        .height = 4,
        .paletteNum = 0xF,
        .baseBlock = 0x242
    },
    [ITEMWIN_2x2] = {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 1,
        .width = 8,
        .height = 3,
        .paletteNum = 0xC,
        .baseBlock = 0x272
    },
    [ITEMWIN_YESNO_LOW] = { // Yes/No tucked in corner, for toss confirm
        .bg = 0,
        .tilemapLeft = 23,
        .tilemapTop = 15,
        .width = 6,
        .height = 4,
        .paletteNum = 0xF,
        .baseBlock = 0x28a
    },
    [ITEMWIN_YESNO_HIGH] = { // Yes/No higher up, positioned above a lower message box
        .bg = 0,
        .tilemapLeft = 21,
        .tilemapTop = 9,
        .width = 6,
        .height = 4,
        .paletteNum = 0xF,
        .baseBlock = 0x28a
    },
    [ITEMWIN_MESSAGE] = {
        .bg = 0,
        .tilemapLeft = 2,
        .tilemapTop = 15,
        .width = 26,
        .height = 4,
        .paletteNum = 0xF,
        .baseBlock = 0x2a2
    },
    [ITEMWIN_6] = {
        .bg = 0,
        .tilemapLeft = 6,
        .tilemapTop = 15,
        .width = 14,
        .height = 4,
        .paletteNum = 0xC,
        .baseBlock = 0x2a2
    },
    [ITEMWIN_7] = {
        .bg = 0,
        .tilemapLeft = 6,
        .tilemapTop = 15,
        .width = 15,
        .height = 4,
        .paletteNum = 0xC,
        .baseBlock = 0x2da
    },
    [ITEMWIN_8] = {
        .bg = 0,
        .tilemapLeft = 6,
        .tilemapTop = 15,
        .width = 16,
        .height = 4,
        .paletteNum = 0xC,
        .baseBlock = 0x316
    },
    [ITEMWIN_9] = {
        .bg = 0,
        .tilemapLeft = 6,
        .tilemapTop = 15,
        .width = 23,
        .height = 4,
        .paletteNum = 0xC,
        .baseBlock = 0x356
    },
    [ITEMWIN_LIST] = {
        .bg = 0,
        .tilemapLeft = 22,
        .tilemapTop = 17,
        .width = 7,
        .height = 2,
        .paletteNum = 0xF,
        .baseBlock = 0x20a
    },
    {
        .bg = 0,
        .tilemapLeft = 22,
        .tilemapTop = 15,
        .width = 7,
        .height = 4,
        .paletteNum = 0xF,
        .baseBlock = 0x20a
    },
    {
        .bg = 0,
        .tilemapLeft = 22,
        .tilemapTop = 13,
        .width = 7,
        .height = 6,
        .paletteNum = 0xF,
        .baseBlock = 0x20a
    },
    {
        .bg = 0,
        .tilemapLeft = 22,
        .tilemapTop = 11,
        .width = 7,
        .height = 8,
        .paletteNum = 0xF,
        .baseBlock = 0x20a
    },
    {
        .bg = 0,
        .tilemapLeft = 22,
        .tilemapTop = 9,
        .width = 7,
        .height = 10,
        .paletteNum = 0xF,
        .baseBlock = 0x20a
    }
};

void LoadBagMenuTextWindows(void)
{
    u32 i;

    InitWindows(sDefaultBagWindows);
    DeactivateAllTextPrinters();
    LoadUserWindowBorderGfx(0, 0x64, 0xE0);
    LoadMessageBoxGfx(0, 0x6D, 0xD0);
    LoadThinWindowBorderGfx(0, 0x81, 0xC0);
    LoadPalette(&sBagWindowPalF, 0xF0, 0x20);
    LoadPalette(sPal3Override, 0xF6, 0x04);
    for (i = 0; i < 3; i++)
    {
        FillWindowPixelBuffer(i, PIXEL_FILL(0));
        PutWindowTilemap(i);
    }
    ScheduleBgCopyTilemapToVram(0);
    memset(gBagMenu->windowIds, 0xFF, sizeof(gBagMenu->windowIds));
}

void BagMenu_Print(u8 windowId, u8 fontId, const u8 *str, u8 left, u8 top, u8 letterSpacing, u8 lineSpacing, u8 speed, u8 colorIndex)
{
    AddTextPrinterParameterized4(windowId, fontId, left, top, letterSpacing, lineSpacing, sFontColorTable[colorIndex], speed, str);
}

/*void BagDrawDepositItemTextBox(void)
{
    u32 x = GetStringCenterAlignXOffset(4, gText_DepositItem, 0x40);
    DrawStdFrameWithCustomTileAndPalette(2, FALSE, 0x81, 0xC);
    AddTextPrinterParameterized(2, 4, gText_DepositItem, x / 2, 1, 0, NULL);
}*/

u8 BagMenu_AddWindow(u8 windowType, u8 nItems)
{
    u8 *windowId = &gBagMenu->windowIds[windowType];

    if (*windowId == WINDOW_NONE)
    {
        *windowId = AddWindow(&sContextMenuWindowTemplates[windowType + nItems]);
        if (windowType != ITEMWIN_6)
            DrawStdFrameWithCustomTileAndPalette(*windowId, FALSE, 0x64, 0xE);
        else
            DrawStdFrameWithCustomTileAndPalette(*windowId, FALSE, 0x81, 0xC);
        ScheduleBgCopyTilemapToVram(0);
    }
    return *windowId;
}

void BagMenu_RemoveWindow(u8 windowType)
{
    u8 *windowId = &gBagMenu->windowIds[windowType];

    ClearStdWindowAndFrameToTransparent(*windowId, FALSE);
    ClearWindowTilemap(*windowId);
    RemoveWindow(*windowId);
    ScheduleBgCopyTilemapToVram(0);
    *windowId = WINDOW_NONE;
}

u8 OpenBagWindow(u8 windowType)
{
    u8 *windowId = &gBagMenu->windowIds[windowType];

    if (*windowId == WINDOW_NONE)
        *windowId = AddWindow(&sContextMenuWindowTemplates[windowType]);
    return *windowId;
}

void RemoveItemMessageWindow(u8 windowType)
{
    u8 *windowId = &gBagMenu->windowIds[windowType];

    ClearDialogWindowAndFrameToTransparent(*windowId, FALSE);
    ClearWindowTilemap(*windowId);
    RemoveWindow(*windowId);
    PutWindowTilemap(WIN_DESCRIPTION);
    ScheduleBgCopyTilemapToVram(0);
    *windowId = WINDOW_NONE;
}

u8 BagMenu_GetWindowId(u8 windowType)
{
    return gBagMenu->windowIds[windowType];
}

void BagMenu_YesNo(u8 taskId, const struct YesNoFuncTable * funcTable)
{
    CreateYesNoMenuWithCallbacks(taskId, &sContextMenuWindowTemplates[ITEMWIN_YESNO_LOW], 2, 0, 2, 0x64, 0xE, funcTable);
}

void BagMenu_YesNoTopRight(u8 taskId, const struct YesNoFuncTable * funcTable)
{
    CreateYesNoMenuWithCallbacks(taskId, &sContextMenuWindowTemplates[ITEMWIN_YESNO_HIGH], 2, 0, 2, 0x64, 0xE, funcTable);
}

void DisplayCurrentMoneyWindow(void)
{
    PrintMoneyAmountInMoneyBoxWithBorder(BagMenu_AddWindow(ITEMWIN_2x2, 0), 0x81, 0xC, GetMoney(&gSaveBlock1Ptr->money));
    //AddMoneyLabelObject(19, 11);
}

void BagDrawTextBoxOnWindow(u8 windowId)
{
    DrawTextBorderOuter(windowId, 0x64, 0xE);
}

