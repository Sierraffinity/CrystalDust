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
#include "string.h"
#include "strings.h"
#include "string_util.h"
#include "task.h"
#include "text_window.h"
#include "menu_helpers.h"
#include "window.h"
#include "apprentice.h"
#include "battle_pike.h"
#include "constants/rgb.h"

#define FREE_IF_SET(ptr) ({ if (ptr) Free(ptr); })

void GoToBagMenu(u8 bagMenuType, u8 pocketId, void ( *postExitMenuMainCallback2)());
static void FadeOutOfBagMenu(void);
static void Task_WaitFadeOutOfBagMenu(u8 taskId);
static void NullBagMenuBufferPtrs(void);
void CB2_Bag(void);
bool8 SetupBagMenu(void);
void BagMenu_InitBGs(void);
bool8 LoadBagMenu_Graphics(void);
void SetupBagMenu_Textboxes(void);
bool8 AllocateBagItemListBuffers(void);
void LoadBagItemListBuffers(u8);
void BagMenu_PrintPocketName(void);
void BagDrawDepositItemTextBox(void);
void CreatePocketScrollArrowPair(void);
void CreatePocketSwitchArrowPair(void);
void BagMenu_PrepareTMHMMoveWindow(void);
bool8 IsWallysBag(void);
void Task_WallyTutorialBagMenu(u8);
void Task_BagMenu(u8);
void GetItemName(s8*, u16);
u16 ItemIdToBattleMoveId(u16);
u16 BagGetItemIdByPocketPosition(u8, u16);
void BagMenu_PrintDescription(int);
void BagMenu_PrintCursor(u8, u8);
void BagMenu_Print(u8, u8, const u8*, u8, u8, u8, u8, u8, u8);
bool8 ItemId_GetImportance(u16);
u16 BagGetQuantityByPocketPosition(u8, u16);
void BagDestroyPocketSwitchArrowPair(void);
void TaskCloseBagMenu_2(u8);
static void Task_AnimateWin0v(u8 taskId);
u8 AddItemMessageWindow(u8);
void bag_menu_RemoveBagItem_message_window(u8);
void set_callback3_to_bag(u8);
void PrintItemDepositAmount(u8, s16);
u8 BagMenu_AddWindow(u8, u8);
u8 GetSwitchBagPocketDirection(void);
void SwitchBagPocket(u8, s16, u16);
bool8 sub_81AC2C0(void);
void BagMenu_SwapItems(u8);
void sub_81AC10C(u8);
void sub_81AC3C0(u8);
void sub_81AC498(u8);
void sub_81AC590(u8);
void PrintTMHMMoveData(u16);
void sub_81ACAF8(u8);
void sub_81ACB54(u8, u8, u8);
void Task_HandleInBattleItemMenuInput(u8);
void Task_HandleOutOfBattleItemMenuInput(u8);
bool8 sub_81ACDFC(s8);
void BagMenu_RemoveWindow(u8);
void BagMenu_PrintThereIsNoPokemon(u8);
void Task_ChooseHowManyToToss(u8);
void BagMenu_TossItems(u8);
void BagCreateYesNoMenuBottomRight(u8 taskId, const struct YesNoFuncTable * ptrs);
void BagCreateYesNoMenuTopRight(u8 taskId, const struct YesNoFuncTable * ptrs);
void Task_ActuallyToss(u8);
void ItemMenu_Cancel(u8);
void sub_81AD350(u8);
void BagMenu_PrintItemCantBeHeld(u8);
void DisplayCurrentMoneyWindow(void);
void BagDrawTextBoxOnWindow(u8);
void DisplaySellItemPriceAndConfirm(u8);
void sub_81AD730(u8);
void sub_81AD6E4(u8);
void bag_menu_RemoveBagItem_message_window(u8);
void Task_BuyHowManyDialogueHandleInput(u8);
void sub_81AD8C8(u8);
void sub_81AD9C0(u8);
void Task_TryDoItemDeposit(u8);
void sub_81ADA7C(u8);
void sub_81ADC0C(u8);
void CB2_ApprenticeExitBagMenu(void);
void CB2_FavorLadyExitBagMenu(void);
void CB2_QuizLadyExitBagMenu(void);
void sub_81ABA6C(void);
static void SetPocketListPositions(void);
void sub_81ABAE0(void);
u8 CreateBagInputHandlerTask(u8);
void sub_81AC23C(u8);
void BagMenu_MoveCursorCallback(s32 a, bool8 b, struct ListMenu*);
void PrintItemQuantityPlusGFX(u8 rboxId, s32 item_index_in_pocket, u8 a);
void ItemMenu_UseOutOfBattle(u8 taskId);
void ItemMenu_Toss(u8 taskId);
void ItemMenu_Register(u8 taskId);
void ItemMenu_Give(u8 taskId);
void ItemMenu_Cancel(u8 taskId);
void ItemMenu_UseInBattle(u8 taskId);
void ItemMenu_CheckTag(u8 taskId);
void Task_FadeAndCloseBagMenu(u8 taskId);
static void Task_Dude_FadeFromBag(u8 taskId);
static void Task_Dude_WaitFadeAndExitBag(u8 taskId);
void unknown_ItemMenu_Show(u8 taskId);
void unknown_ItemMenu_Give2(u8 taskId);
void unknown_ItemMenu_Confirm2(u8 taskId);
void unknown_item_menu_type(u8 taskId);
void item_menu_type_2(u8 taskId);
void DisplaySellItemAskString(u8 taskId);
void DisplayDepositItemAskString(u8 taskId);
void item_menu_type_b(u8 taskId);
void BagMenu_ConfirmToss(u8 taskId);
void BagMenu_CancelToss(u8 taskId);
void BagMenu_ConfirmSell(u8 taskId);
void BagMenu_CancelSell(u8 taskId);
static void ShowBagOrBeginWin0OpenTask(void);
void FreeBagItemListBuffers(void);
u8 GetBagWindow(u8 a);
static void Task_ItemContextMenuByLocation(u8 taskId);
static void Bag_FillMessageBoxWithPalette(u32 a0);

// .rodata

static const struct BgTemplate sBgTemplates_ItemMenu[2] =
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

static const struct ListMenuTemplate sItemListMenu =
{
    .items = NULL,
    .moveCursorFunc = BagMenu_MoveCursorCallback,
    .itemPrintFunc = PrintItemQuantityPlusGFX,
    .totalItems = 0,
    .maxShowed = 0,
    .windowId = 0,
    .header_X = 0,
    .item_X = 9,
    .cursor_X = 1,
    .upText_Y = 2,
    .cursorPal = 2,
    .fillValue = 0,
    .cursorShadowPal = 3,
    .lettersSpacing = 0,
    .itemVerticalPadding = 2,
    .scrollMultiple = 0,
    .fontId = 1,
    .cursorKind = 0
};

static const u16 sBagListBgTiles[][18] = {
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

const struct MenuAction sItemMenuActions[] = {
    {gMenuText_Use, ItemMenu_UseOutOfBattle},
    {gMenuText_Toss, ItemMenu_Toss},
    {gMenuText_Register, ItemMenu_Register},
    {gMenuText_Give, ItemMenu_Give},
    {gText_Cancel2, ItemMenu_Cancel},
    {gMenuText_Use, ItemMenu_UseInBattle},
    {gMenuText_Check, ItemMenu_UseOutOfBattle},
    {gMenuText_Walk, ItemMenu_UseOutOfBattle},
    {gMenuText_Deselect, ItemMenu_Register},
    {gMenuText_CheckTag, ItemMenu_CheckTag},
    {gMenuText_Confirm, Task_FadeAndCloseBagMenu},
    {gMenuText_Show, unknown_ItemMenu_Show},
    {gMenuText_Give2, unknown_ItemMenu_Give2},
    {gMenuText_Confirm, unknown_ItemMenu_Confirm2},
    {gText_EmptyString2, NULL}
};

const u8 gUnknown_0861402C[] = {0, 3, 1, 4};
const u8 gUnknown_08614030[] = {0, 2, 4};
const u8 gUnknown_08614034[] = {3, 1, 4};
const u8 gUnknown_08614038[] = {0, 3, 4};
const u8 gUnknown_0861403C[] = {9, 0, 3, 1, 4};
const u8 gUnknown_08614042[] = {5, 4};
const u8 gUnknown_08614044[] = {3, 4};
const u8 gUnknown_08614046[] = {4};
const u8 gUnknown_08614047[] = {10, 9, 4};
const u8 gUnknown_0861404B[] = {11, 4};
const u8 gUnknown_0861404D[] = {12, 4};
const u8 gUnknown_0861404F[] = {13, 4};
const u8 gItemMenu_TossCancel[] = {1, 4};

const TaskFunc gUnknown_08614054[] = {
    unknown_item_menu_type,
    unknown_item_menu_type,
    item_menu_type_2,
    DisplaySellItemAskString,
    Task_FadeAndCloseBagMenu,
    unknown_item_menu_type,
    DisplayDepositItemAskString,
    unknown_item_menu_type,
    unknown_item_menu_type,
    unknown_item_menu_type,
    NULL,
    item_menu_type_b
};

const struct YesNoFuncTable sYesNoTossFunctions = {BagMenu_ConfirmToss, BagMenu_CancelToss};

const struct YesNoFuncTable sYesNoSellItemFunctions = {BagMenu_ConfirmSell, BagMenu_CancelSell};

const struct ScrollArrowsTemplate gBagScrollArrowsTemplate = {
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

static const u8 gRegisteredSelect_Gfx[] = INCBIN_U8("graphics/item_menu/select_button.4bpp");
static const u16 sBagWindowPalF[] = INCBIN_U16("graphics/item_menu/bag_window_pal.gbapal");
static const u16 sPal3Override[] = {RGB(8, 8, 8), RGB(30, 16, 6)};

static const u8 sFontColorTable[][3] = {
// bgColor, textColor, shadowColor
    {0, 1, 2},
    {0, 2, 3},
    {0, 3, 2},
    {0, 8, 9}
};

const struct WindowTemplate sDefaultBagWindowsStd[] =
{
    {
        .bg = 0,
        .tilemapLeft = 0x0b,
        .tilemapTop = 0x01,
        .width = 0x12,
        .height = 0x0c,
        .paletteNum = 0x0f,
        .baseBlock = 0x008a
    }, {
        .bg = 0,
        .tilemapLeft = 0x05,
        .tilemapTop = 0x0e,
        .width = 0x19,
        .height = 0x06,
        .paletteNum = 0x0f,
        .baseBlock = 0x0162
    }, {
        .bg = 0,
        .tilemapLeft = 0x01,
        .tilemapTop = 0x01,
        .width = 0x09,
        .height = 0x02,
        .paletteNum = 0x0f,
        .baseBlock = 0x01f8
    }, DUMMY_WIN_TEMPLATE
};

const struct WindowTemplate sDefaultBagWindowsDeposit[] =
{
    {
        .bg = 0,
        .tilemapLeft = 0x0b,
        .tilemapTop = 0x01,
        .width = 0x12,
        .height = 0x0c,
        .paletteNum = 0x0f,
        .baseBlock = 0x008a
    }, {
        .bg = 0,
        .tilemapLeft = 0x05,
        .tilemapTop = 0x0e,
        .width = 0x19,
        .height = 0x06,
        .paletteNum = 0x0f,
        .baseBlock = 0x0162
    }, {
        .bg = 0,
        .tilemapLeft = 0x01,
        .tilemapTop = 0x01,
        .width = 0x09,
        .height = 0x02,
        .paletteNum = 0x0f,
        .baseBlock = 0x01f8
    }, DUMMY_WIN_TEMPLATE
};

const struct WindowTemplate gUnknown_086141AC[] =
{
    {
        .bg = 0,
        .tilemapLeft = 24,
        .tilemapTop = 15,
        .width = 5,
        .height = 4,
        .paletteNum = 0xF,
        .baseBlock = 0x242
    }, {
        .bg = 0,
        .tilemapLeft = 17,
        .tilemapTop = 9,
        .width = 12,
        .height = 4,
        .paletteNum = 0xF,
        .baseBlock = 0x242
    }, {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 1,
        .width = 8,
        .height = 3,
        .paletteNum = 0xC,
        .baseBlock = 0x272
    }, {
        .bg = 0,
        .tilemapLeft = 23,
        .tilemapTop = 15,
        .width = 6,
        .height = 4,
        .paletteNum = 0xF,
        .baseBlock = 0x28a
    }, {
        .bg = 0,
        .tilemapLeft = 21,
        .tilemapTop = 9,
        .width = 6,
        .height = 4,
        .paletteNum = 0xF,
        .baseBlock = 0x28a
    }, {
        .bg = 0,
        .tilemapLeft = 2,
        .tilemapTop = 15,
        .width = 26,
        .height = 4,
        .paletteNum = 0xF,
        .baseBlock = 0x2a2
    }, {
        .bg = 0,
        .tilemapLeft = 6,
        .tilemapTop = 15,
        .width = 14,
        .height = 4,
        .paletteNum = 0xC,
        .baseBlock = 0x2a2
    }, {
        .bg = 0,
        .tilemapLeft = 6,
        .tilemapTop = 15,
        .width = 15,
        .height = 4,
        .paletteNum = 0xC,
        .baseBlock = 0x2da
    }, {
        .bg = 0,
        .tilemapLeft = 6,
        .tilemapTop = 15,
        .width = 16,
        .height = 4,
        .paletteNum = 0xC,
        .baseBlock = 0x316
    }, {
        .bg = 0,
        .tilemapLeft = 6,
        .tilemapTop = 15,
        .width = 23,
        .height = 4,
        .paletteNum = 0xC,
        .baseBlock = 0x356
    }, {
        .bg = 0,
        .tilemapLeft = 22,
        .tilemapTop = 17,
        .width = 7,
        .height = 2,
        .paletteNum = 0xF,
        .baseBlock = 0x20a
    }, {
        .bg = 0,
        .tilemapLeft = 22,
        .tilemapTop = 15,
        .width = 7,
        .height = 4,
        .paletteNum = 0xF,
        .baseBlock = 0x20a
    }, {
        .bg = 0,
        .tilemapLeft = 22,
        .tilemapTop = 13,
        .width = 7,
        .height = 6,
        .paletteNum = 0xF,
        .baseBlock = 0x20a
    }, {
        .bg = 0,
        .tilemapLeft = 22,
        .tilemapTop = 11,
        .width = 7,
        .height = 8,
        .paletteNum = 0xF,
        .baseBlock = 0x20a
    }, {
        .bg = 0,
        .tilemapLeft = 22,
        .tilemapTop = 9,
        .width = 7,
        .height = 10,
        .paletteNum = 0xF,
        .baseBlock = 0x20a
    }
};

// .text
// The items pocket has the highest capacity, + 1 for CLOSE BAG
struct ListBuffer1 {
    struct ListMenuItem subBuffers[BAG_ITEMS_COUNT + 1];
};

struct ListBuffer2 {
    s8 name[BAG_ITEMS_COUNT + 1][14 + ITEM_NAME_LENGTH];
};

struct TempWallyStruct {
    struct ItemSlot bagPocket_Items[BAG_ITEMS_COUNT];
    struct ItemSlot bagPocket_PokeBalls[BAG_POKEBALLS_COUNT];
    u16 cursorPosition[POCKETS_COUNT];
    u16 scrollPosition[POCKETS_COUNT];
    u8 filler[0x2];
    u16 pocket;
};

EWRAM_DATA struct BagMenuStruct *gBagMenu = 0;
EWRAM_DATA struct BagStruct gBagPositionStruct = {0};
static EWRAM_DATA struct ListBuffer1 *sListBuffer1 = 0;
static EWRAM_DATA struct ListBuffer2 *sListBuffer2 = 0;
EWRAM_DATA u16 gSpecialVar_ItemId = 0;
static EWRAM_DATA struct TempWallyStruct *sTempWallyBag = 0;

extern u8 *const gPocketNamesStringsTable[];
extern u8* gReturnToXStringsTable[];
extern const u8 EventScript_SelectWithoutRegisteredItem[];

void ResetBagScrollPositions(void)
{
    gBagPositionStruct.pocket = ITEMS_POCKET;
    memset(gBagPositionStruct.cursorPosition, 0, 10);
    memset(gBagPositionStruct.scrollPosition, 0, 10);
}

void CB2_BagMenuFromStartMenu(void)
{
    GoToBagMenu(RETURN_LOCATION_FIELD, POCKETS_COUNT, CB2_ReturnToFieldWithOpenMenu);
}

void sub_81AABB0(void)
{
    if (!InBattlePyramid())
        GoToBagMenu(RETURN_LOCATION_BATTLE, POCKETS_COUNT, CB2_SetUpReshowBattleScreenAfterMenu2);
    else
        GoToBattlePyramidBagMenu(1, CB2_SetUpReshowBattleScreenAfterMenu2);
}

void CB2_ChooseBerry(void)
{
    GoToBagMenu(RETURN_LOCATION_FIELD_2, BERRIES_POCKET, CB2_ReturnToFieldContinueScript);
}

void ChooseBerrySetCallback(void (*callback)(void))
{
    GoToBagMenu(RETURN_LOCATION_FIELD_3, BERRIES_POCKET, callback);
}

void CB2_GoToSellMenu(void)
{
    GoToBagMenu(RETURN_LOCATION_SHOP, POCKETS_COUNT, CB2_ExitSellMenu);
}

void sub_81AAC14(void)
{
    GoToBagMenu(RETURN_LOCATION_PC, POCKETS_COUNT, sub_816B31C);
}

void ApprenticeOpenBagMenu(void)
{
    GoToBagMenu(RETURN_LOCATION_FIELD_6, POCKETS_COUNT, CB2_ApprenticeExitBagMenu);
    gSpecialVar_0x8005 = ITEM_NONE;
    gSpecialVar_Result = FALSE;
}

void FavorLadyOpenBagMenu(void)
{
    GoToBagMenu(RETURN_LOCATION_FIELD_4, POCKETS_COUNT, CB2_FavorLadyExitBagMenu);
    gSpecialVar_Result = FALSE;
}

void QuizLadyOpenBagMenu(void)
{
    GoToBagMenu(RETURN_LOCATION_FIELD_5, POCKETS_COUNT, CB2_QuizLadyExitBagMenu);
    gSpecialVar_Result = FALSE;
}

void GoToBagMenu(u8 bagMenuType, u8 pocketId, void ( *postExitMenuMainCallback2)())
{
    u8 temp;

    NullBagMenuBufferPtrs();
    gBagMenu = AllocZeroed(sizeof(struct BagMenuStruct));
    if (gBagMenu == NULL)
    {
        SetMainCallback2(postExitMenuMainCallback2);
    }
    else
    {
        if (bagMenuType != RETURN_LOCATION_UNCHANGED)
            gBagPositionStruct.location = bagMenuType;
        if (postExitMenuMainCallback2)
            gBagPositionStruct.bagCallback = postExitMenuMainCallback2;
        if (pocketId < POCKETS_COUNT)
            gBagPositionStruct.pocket = pocketId;
        temp = gBagPositionStruct.location - (POCKETS_COUNT - 1);
        if (temp <= 1)
            gBagMenu->pocketSwitchMode = 1;
        gBagMenu->mainCallback2 = 0;
        gBagMenu->itemOriginalLocation = 0xFF;
        gBagMenu->itemMenuIcon = 0;
        gBagMenu->inhibitItemDescriptionPrint = FALSE;
        gBagMenu->pocketScrollArrowsTask = -1;
        gBagMenu->pocketSwitchArrowsTask = -1;
        SetMainCallback2(CB2_Bag);
    }
}

void c2_bag_3(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    do_scheduled_bg_tilemap_copies_to_vram();
    UpdatePaletteFade();
}

void vblank_cb_bag_menu(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

#define tItemCount data[8]

void CB2_Bag(void)
{
    while(sub_81221EC() != TRUE && SetupBagMenu() != TRUE && sub_81221AC() != TRUE) {};
}

bool8 SetupBagMenu(void)
{
    u32 index;
    u8 taskId;

    switch (gMain.state)
    {
    case 0:
        SetVBlankHBlankCallbacksToNull();
        clear_scheduled_bg_copies_to_vram();
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
        if (sub_81221AC() == FALSE)
            ResetTasks();
        gMain.state++;
        break;
    case 7:
        BagMenu_InitBGs();
        gBagMenu->unk834 = 0;
        gMain.state++;
        break;
    case 8:
        if (!LoadBagMenu_Graphics())
            break;
        gMain.state++;
        break;
    case 9:
        SetupBagMenu_Textboxes();
        gMain.state++;
        break;
    case 10:
        sub_81ABA6C();
        SetPocketListPositions();
        sub_81ABAE0();
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
        LoadBagItemListBuffers(gBagPositionStruct.pocket);
        gMain.state++;
        break;
    case 13:
        BagMenu_PrintPocketName();
        gMain.state++;
        break;
    case 14:
        taskId = CreateBagInputHandlerTask(gBagPositionStruct.location);
        gTasks[taskId].data[0] = ListMenuInit(&gMultiuseListMenuTemplate, gBagPositionStruct.scrollPosition[gBagPositionStruct.pocket], gBagPositionStruct.cursorPosition[gBagPositionStruct.pocket]);
        gTasks[taskId].data[3] = 0;
        gTasks[taskId].tItemCount = 0;
        gMain.state++;
        break;
    case 15:
        AddBagVisualSprite(gBagPositionStruct.pocket);
        gMain.state++;
        break;
    case 16:
        CreatePocketScrollArrowPair();
        CreatePocketSwitchArrowPair();
        gMain.state++;
        break;
    case 17:
        sub_80D4FAC();
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
        SetVBlankCallback(vblank_cb_bag_menu);
        SetMainCallback2(c2_bag_3);
        return TRUE;
    }
    return FALSE;
}

static void FadeOutOfBagMenu(void)
{
    BeginNormalPaletteFade(0xFFFFFFFF, -2, 0, 16, RGB_BLACK);
    CreateTask(Task_WaitFadeOutOfBagMenu, 0);
    SetVBlankCallback(vblank_cb_bag_menu);
    SetMainCallback2(c2_bag_3);
}

static void Task_WaitFadeOutOfBagMenu(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        SetMainCallback2(gBagPositionStruct.bagCallback);
        FreeBagItemListBuffers();
        DestroyTask(taskId);
    }
}

static void NullBagMenuBufferPtrs(void)
{
    sListBuffer1 = NULL;
    sListBuffer2 = NULL;
}

void BagMenu_InitBGs(void)
{
    ResetVramOamAndBgCntRegs();
    ResetAllBgsCoordinates();
    memset(gBagMenu->tilemapBuffer, 0, 0x800);
    ResetBgsAndClearDma3BusyFlags(FALSE);
    InitBgsFromTemplates(0, sBgTemplates_ItemMenu, NELEMS(sBgTemplates_ItemMenu));
    SetBgTilemapBuffer(1, gBagMenu->tilemapBuffer);
    schedule_bg_copy_tilemap_to_vram(1);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP | DISPCNT_WIN0_ON);
    ShowBg(0);
    ShowBg(1);
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
}

bool8 LoadBagMenu_Graphics(void)
{
    switch (gBagMenu->unk834)
    {
        case 0:
            reset_temp_tile_data_buffers();
            decompress_and_copy_tile_data_to_vram(1, gBagScreen_Gfx, 0, 0, 0);
            gBagMenu->unk834++;
            break;
        case 1:
            if (free_temp_tile_data_buffers_if_possible() != TRUE)
            {
                LZDecompressWram(gBagScreen_GfxTileMap, gBagMenu->tilemapBuffer);
                gBagMenu->unk834++;
            }
            break;
        case 2:
            LoadCompressedPalette(gBagScreenMale_Pal, 0, 0x60);
            if (!IsWallysBag() && gSaveBlock2Ptr->playerGender != MALE)
                LoadCompressedPalette(gBagScreenFemale_Pal, 0, 0x20);
            gBagMenu->unk834++;
            break;
        case 3:
            if (IsWallysBag() == TRUE || gSaveBlock2Ptr->playerGender == MALE)
                LoadCompressedSpriteSheet(&gBagMaleSpriteSheet);
            else
                LoadCompressedSpriteSheet(&gBagFemaleSpriteSheet);
            gBagMenu->unk834++;
            break;
        case 4:
            if (IsWallysBag() == TRUE || gSaveBlock2Ptr->playerGender == MALE)
                LoadCompressedSpritePalette(&gBagMalePaletteTable);
            else
                LoadCompressedSpritePalette(&gBagFemalePaletteTable);
            gBagMenu->unk834++;
            break;
        default:
            LoadListMenuArrowsGfx();
            gBagMenu->unk834 = 0;
            return TRUE;
    }
    return FALSE;
}

u8 CreateBagInputHandlerTask(u8 location)
{
    u8 taskId;
    if (location == RETURN_LOCATION_BATTLE_2)
        taskId = CreateTask(Task_WallyTutorialBagMenu, 0);
    else
        taskId = CreateTask(Task_BagMenu, 0);
    return taskId;
}

bool8 AllocateBagItemListBuffers(void)
{
    sListBuffer1 = Alloc(sizeof(struct ListBuffer1));
    if (sListBuffer1 == NULL)
        return FALSE;
    sListBuffer2 = Alloc(sizeof(struct ListBuffer2));
    if (sListBuffer2 == NULL)
        return FALSE;
    return TRUE;
}

void LoadBagItemListBuffers(u8 pocketId)
{
    u16 i;
    struct BagPocket *pocket = &gBagPockets[pocketId];
    struct ListMenuItem *subBuffer;

    if (!gBagMenu->hideCloseBagText)
    {
        for (i = 0; i < gBagMenu->totalItems[pocketId]; i++)
        {
            GetItemName(sListBuffer2->name[i], pocket->itemSlots[i].itemId);
            subBuffer = sListBuffer1->subBuffers;
            subBuffer[i].name = sListBuffer2->name[i];
            subBuffer[i].id = i;
        }
        StringCopy(sListBuffer2->name[i], gText_CloseBag);
        subBuffer = sListBuffer1->subBuffers;
        subBuffer[i].name = sListBuffer2->name[i];
        subBuffer[i].id = -2;
    }
    else
    {
        for (i = 0; i < gBagMenu->totalItems[pocketId]; i++)
        {
            GetItemName(sListBuffer2->name[i], pocket->itemSlots[i].itemId);
            subBuffer = sListBuffer1->subBuffers;
            subBuffer[i].name = sListBuffer2->name[i];
            subBuffer[i].id = i;
        }
    }
    gMultiuseListMenuTemplate = sItemListMenu;
    gMultiuseListMenuTemplate.totalItems = gBagMenu->totalItems[pocketId] + 1;
    gMultiuseListMenuTemplate.items = sListBuffer1->subBuffers;
    gMultiuseListMenuTemplate.maxShowed = gBagMenu->maxShowed[pocketId];
}

void GetItemName(s8 *dest, u16 itemId)
{
    switch (gBagPositionStruct.pocket)
    {
        case TMHM_POCKET:
            StringCopy(gStringVar2, gMoveNames[ItemIdToBattleMoveId(itemId)]);
            if (itemId >= ITEM_HM01)
            {
                ConvertIntToDecimalStringN(gStringVar1, itemId - ITEM_HM01 + 1, STR_CONV_MODE_LEADING_ZEROS, 1);
                StringExpandPlaceholders(dest, gText_ClearTo11Var1Clear5Var2);
            }
            else
            {
                ConvertIntToDecimalStringN(gStringVar1, itemId - ITEM_TM01 + 1, STR_CONV_MODE_LEADING_ZEROS, 2);
                StringExpandPlaceholders(dest, gText_NumberVar1Clear7Var2);
            }
            break;
        case BERRIES_POCKET:
            ConvertIntToDecimalStringN(gStringVar1, itemId - ITEM_CHERI_BERRY + 1, STR_CONV_MODE_LEADING_ZEROS, 2);
            CopyItemName(itemId, gStringVar2);
            StringExpandPlaceholders(dest, gText_NumberVar1Clear7Var2);
            break;
        default:
            CopyItemName(itemId, dest);
            break;
    }
}

void BagMenu_MoveCursorCallback(s32 itemIndex, bool8 onInit, struct ListMenu *unused)
{
    if (onInit != TRUE)
    {
        PlaySE(SE_RG_BAG1);
        ShakeBagVisual();
    }
    if (gBagMenu->itemOriginalLocation == 0xFF)
    {
        if (itemIndex != LIST_CANCEL)
           AddBagItemIconSprite(BagGetItemIdByPocketPosition(gBagPositionStruct.pocket + 1, itemIndex), gBagMenu->itemMenuIcon);
        else
           AddBagItemIconSprite(-1, gBagMenu->itemMenuIcon);
        RemoveBagItemIconSprite(gBagMenu->itemMenuIcon ^= 1);
        if (!gBagMenu->inhibitItemDescriptionPrint)
            BagMenu_PrintDescription(itemIndex);
    }
}

void PrintItemQuantityPlusGFX(u8 rboxId, s32 item_index_in_pocket, u8 y)
{
    u16 itemId;
    u16 itemQuantity;
    if (item_index_in_pocket != LIST_CANCEL)
    {
        if (gBagMenu->itemOriginalLocation != 0xFF)
        {
            if (gBagMenu->itemOriginalLocation == (u8)item_index_in_pocket)
                BagMenu_PrintCursor(y, 2);
            else
                BagMenu_PrintCursor(y, -1);
        }
        itemId = BagGetItemIdByPocketPosition(gBagPositionStruct.pocket + 1, item_index_in_pocket);
        itemQuantity = BagGetQuantityByPocketPosition(gBagPositionStruct.pocket + 1, item_index_in_pocket);
        if (itemId >= ITEM_HM01 && itemId <= ITEM_HM08)
            BlitBitmapToWindow(rboxId, gBagMenuHMIcon_Gfx, 9, y, 16, 12);
        if (gBagPositionStruct.pocket == BERRIES_POCKET)
        {
            ConvertIntToDecimalStringN(gStringVar1, itemQuantity, STR_CONV_MODE_RIGHT_ALIGN, 3);
            StringExpandPlaceholders(gStringVar4, gText_xVar1);
            BagMenu_Print(rboxId, 0, gStringVar4, 110, y, 0, 0, -1, 1);
        }
        else if (gBagPositionStruct.pocket != KEYITEMS_POCKET && ItemId_GetImportance(itemId) < 2)
        {
            ConvertIntToDecimalStringN(gStringVar1, itemQuantity, STR_CONV_MODE_RIGHT_ALIGN, 3);
            StringExpandPlaceholders(gStringVar4, gText_xVar1);
            BagMenu_Print(rboxId, 0, gStringVar4, 110, y, 0, 0, -1, 1);
        }
        else
        {
            if (gSaveBlock1Ptr->registeredItem && gSaveBlock1Ptr->registeredItem == itemId)
                BlitBitmapToWindow(rboxId, gRegisteredSelect_Gfx, 0x70, y, 0x18, 16);
        }
    }
}

void BagMenu_PrintDescription(int a)
{
    const u8 *str;
    if (a != LIST_CANCEL)
    {
        str = ItemId_GetDescription(BagGetItemIdByPocketPosition(gBagPositionStruct.pocket + 1, a));
    }
    else
    {
        StringCopy(gStringVar1, gReturnToXStringsTable[gBagPositionStruct.location]);
        StringExpandPlaceholders(gStringVar4, gText_ReturnToVar1);
        str = gStringVar4;
    }
    FillWindowPixelBuffer(1, PIXEL_FILL(0));
    BagMenu_Print(1, 1, str, 0, 3, 2, 0, 0, 0);
}

void BagMenu_PrintCursor_(u8 a, u8 b)
{
    BagMenu_PrintCursor(ListMenuGetYCoordForPrintingArrowCursor(a), b);
}

void BagMenu_PrintCursor(u8 a, u8 b)
{
    if (b == 0xFF)
        FillWindowPixelRect(0, PIXEL_FILL(0), 1, a, GetMenuCursorDimensionByFont(1, 0), GetMenuCursorDimensionByFont(1, 1));
    else
        BagMenu_Print(0, 1, gText_SelectorArrow2, 1, a, 0, 0, 0, b);

}

void CreatePocketScrollArrowPair(void)
{
    if (gBagMenu->pocketScrollArrowsTask == 0xFF)
        gBagMenu->pocketScrollArrowsTask = AddScrollIndicatorArrowPairParameterized(
            SCROLL_ARROW_UP,
            160,
            8,
            104,
            gBagMenu->totalItems[gBagPositionStruct.pocket] - gBagMenu->maxShowed[gBagPositionStruct.pocket] + 1,
            110,
            110,
            &gBagPositionStruct.scrollPosition[gBagPositionStruct.pocket]);
}

void CreatePocketSwitchArrowPair(void)
{
    if (gBagMenu->pocketSwitchMode != 1 && gBagMenu->pocketSwitchArrowsTask == 0xFF)
    {
        gBagMenu->contextMenuSelectedItem = 1;
        gBagMenu->pocketSwitchArrowsTask = AddScrollIndicatorArrowPair(
            &gBagScrollArrowsTemplate, 
            &gBagMenu->contextMenuSelectedItem);
    }
}

static void CreatePocketScrollArrowPair_SellQuantity(void)
{
    if (gBagMenu->pocketScrollArrowsTask == 0xFF)
    {
        gBagMenu->contextMenuSelectedItem = 1;
        gBagMenu->pocketScrollArrowsTask = AddScrollIndicatorArrowPairParameterized(
            SCROLL_ARROW_UP,
            152,
            72,
            104,
            2,
            110,
            110,
            &gBagMenu->contextMenuSelectedItem
        );
    }
}

static void CreateArrowPair_QuantitySelect(void)
{
    if (gBagMenu->pocketScrollArrowsTask == 0xFF)
    {
        gBagMenu->contextMenuSelectedItem = 1;
        gBagMenu->pocketScrollArrowsTask = AddScrollIndicatorArrowPairParameterized(
            SCROLL_ARROW_UP,
            212,
            120,
            152,
            2,
            110,
            110,
            &gBagMenu->contextMenuSelectedItem
        );
    }
}

void BagDestroyPocketScrollArrowPair(void)
{
    if (gBagMenu->pocketScrollArrowsTask != 0xFF)
    {
        RemoveScrollIndicatorArrowPair(gBagMenu->pocketScrollArrowsTask);
        gBagMenu->pocketScrollArrowsTask = 0xFF;
    }
    BagDestroyPocketSwitchArrowPair();
}

void BagDestroyPocketSwitchArrowPair(void)
{
    if (gBagMenu->pocketSwitchArrowsTask != 0xFF)
    {
        RemoveScrollIndicatorArrowPair(gBagMenu->pocketSwitchArrowsTask);
        gBagMenu->pocketSwitchArrowsTask = 0xFF;
    }
}

void FreeBagItemListBuffers(void)
{
    FREE_IF_SET(sListBuffer2);
    FREE_IF_SET(sListBuffer1);
    FREE_IF_SET(gBagMenu);
    FreeAllWindowBuffers();
}

void Task_FadeAndCloseBagMenu(u8 taskId)
{
    BeginNormalPaletteFade(0xFFFFFFFF, -2, 0, 16, RGB_BLACK);
    gTasks[taskId].func = TaskCloseBagMenu_2;
}

void TaskCloseBagMenu_2(u8 taskId)
{
    s16* data = gTasks[taskId].data;
    if (!gPaletteFade.active && FuncIsActiveTask(Task_AnimateWin0v) != TRUE)
    {
        DestroyListMenuTask(data[0], &gBagPositionStruct.scrollPosition[gBagPositionStruct.pocket], &gBagPositionStruct.cursorPosition[gBagPositionStruct.pocket]);
        if (gBagMenu->mainCallback2 != 0)
            SetMainCallback2(gBagMenu->mainCallback2);
        else
            SetMainCallback2(gBagPositionStruct.bagCallback);
        BagDestroyPocketScrollArrowPair();
        ResetSpriteData();
        FreeAllSpritePalettes();
        FreeBagItemListBuffers();
        DestroyTask(taskId);
    }
}

static void ShowBagOrBeginWin0OpenTask(void)
{
    u16 paldata = RGB_BLACK;
    u8 taskId;

    LoadPalette(&paldata, 0x00, 0x02);
    SetGpuReg(REG_OFFSET_WININ, 0);
    SetGpuReg(REG_OFFSET_WINOUT, WININ_WIN0_BG_ALL | WININ_WIN0_OBJ | WININ_WIN0_CLR);
    BlendPalettes(0xFFFFFFFF, 16, RGB_BLACK);
    BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, RGB_BLACK);
    if (gBagPositionStruct.bagOpen == TRUE)
    {
        SetGpuReg(REG_OFFSET_WIN0H, WIN_RANGE(0, 240));
        SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE(0, 0));
    }
    else
    {
        SetGpuReg(REG_OFFSET_WIN0H, WIN_RANGE(0, 240));
        SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE(0, 160));
        taskId = CreateTask(Task_AnimateWin0v, 0);
        gTasks[taskId].data[0] = 192;
        gTasks[taskId].data[1] = -16;
        gBagPositionStruct.bagOpen = TRUE;
    }
}

void Bag_BeginCloseWin0Animation(void)
{

    u8 taskId = CreateTask(Task_AnimateWin0v, 0);
    gTasks[taskId].data[0] = -16;
    gTasks[taskId].data[1] =  16;
    gBagPositionStruct.bagOpen = FALSE;
}

static void Task_AnimateWin0v(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    data[0] += data[1];
    if (data[0] > 160)
        SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE(0, 160));
    else
        SetGpuReg(REG_OFFSET_WIN0V, data[0]);
    if ((data[1] == 16 && data[0] == 160) || (data[1] == -16 && data[0] == 0))
        DestroyTask(taskId);
}

void UpdatePocketItemList(u8 pocketId)
{
    u16 i;
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
    gBagMenu->totalItems[pocketId] = 0;
    for (i = 0; i < pocket->capacity && pocket->itemSlots[i].itemId; i++)
        gBagMenu->totalItems[pocketId]++;

    if (gBagMenu->totalItems[pocketId] + 1 > 6)
        gBagMenu->maxShowed[pocketId] = 6;
    else
        gBagMenu->maxShowed[pocketId] = gBagMenu->totalItems[pocketId] + 1;
}

void sub_81ABA6C(void)
{
    u8 i;
    for (i = 0; i < POCKETS_COUNT; i++)
        UpdatePocketItemList(i);
}

void SetInitialScrollAndCursorPositions(u8 pocketId)
{
    sub_812225C(&gBagPositionStruct.scrollPosition[pocketId], &gBagPositionStruct.cursorPosition[pocketId], gBagMenu->maxShowed[pocketId], gBagMenu->totalItems[pocketId] + 1);
}

static void SetPocketListPositions(void)
{
    u8 i;
    for (i = 0; i < POCKETS_COUNT; i++)
        SetInitialScrollAndCursorPositions(i);
}

void sub_81ABAE0(void)
{
    u8 i;
    for (i = 0; i < POCKETS_COUNT; i++)
        sub_8122298(&gBagPositionStruct.scrollPosition[i], &gBagPositionStruct.cursorPosition[i], gBagMenu->maxShowed[i], gBagMenu->totalItems[i] + 1, 6);
}

u8 GetItemListPosition(u8 pocketId)
{
    return gBagPositionStruct.scrollPosition[pocketId] + gBagPositionStruct.cursorPosition[pocketId];
}

void DisplayItemMessage(u8 taskId, u8 fontId, const u8 *str, void ( *callback)(u8 taskId))
{
    s16* data = gTasks[taskId].data;

    data[10] = AddItemMessageWindow(5);
    FillWindowPixelBuffer(data[10], PIXEL_FILL(1));
    DisplayMessageAndContinueTask(taskId, data[10], 109, 13, fontId, GetPlayerTextSpeedDelay(), str, callback);
    schedule_bg_copy_tilemap_to_vram(0);
}

void BagMenu_InitListsMenu(u8 taskId)
{
    s16* data = gTasks[taskId].data;
    u16* scrollPos = &gBagPositionStruct.scrollPosition[gBagPositionStruct.pocket];
    u16* cursorPos = &gBagPositionStruct.cursorPosition[gBagPositionStruct.pocket];
    bag_menu_RemoveBagItem_message_window(5);
    DestroyListMenuTask(data[0], scrollPos, cursorPos);
    UpdatePocketItemList(gBagPositionStruct.pocket);
    SetInitialScrollAndCursorPositions(gBagPositionStruct.pocket);
    LoadBagItemListBuffers(gBagPositionStruct.pocket);
    data[0] = ListMenuInit(&gMultiuseListMenuTemplate, *scrollPos, *cursorPos);
    schedule_bg_copy_tilemap_to_vram(0);
    BagMenu_PrintCursor_(data[0], 1);
    set_callback3_to_bag(taskId);
}

void PrintItemDepositAmount(u8 windowId, s16 numDeposited)
{
    u8 numDigits = (gBagPositionStruct.pocket == BERRIES_POCKET) ? 3 : 2;
    ConvertIntToDecimalStringN(gStringVar1, numDeposited, STR_CONV_MODE_LEADING_ZEROS, numDigits);
    StringExpandPlaceholders(gStringVar4, gText_xVar1);
    AddTextPrinterParameterized(windowId, 1, gStringVar4, GetStringCenterAlignXOffset(1, gStringVar4, 0x28), 2, 0, 0);
}

void PrintItemSoldAmount(int windowId, int numSold, int moneyEarned)
{
    u8 numDigits = (gBagPositionStruct.pocket == BERRIES_POCKET) ? 3 : 2;
    FillWindowPixelBuffer(windowId, PIXEL_FILL(1));
    ConvertIntToDecimalStringN(gStringVar1, numSold, STR_CONV_MODE_LEADING_ZEROS, numDigits);
    StringExpandPlaceholders(gStringVar4, gText_xVar1);
    BagMenu_Print(windowId, 0, gStringVar4, 4, 10, 1, 0, -1, 1);
    PrintMoneyAmount(windowId, 56, 10, moneyEarned, 0);
}

void Task_BagMenu(u8 taskId)
{
    s16* data = gTasks[taskId].data;
    u16* scrollPos = &gBagPositionStruct.scrollPosition[gBagPositionStruct.pocket];
    u16* cursorPos = &gBagPositionStruct.cursorPosition[gBagPositionStruct.pocket];
    u16 select;

    if (gPaletteFade.active)
        return;
    if (FuncIsActiveTask(Task_AnimateWin0v) == TRUE)
        return;
    if (sub_81221EC() == TRUE)
        return;

    switch (GetSwitchBagPocketDirection())
    {
        case 1:
            SwitchBagPocket(taskId, -1, 0);
            return;
        case 2:
            SwitchBagPocket(taskId, 1, 0);
            return;
    }
    if ((select = (gMain.newKeys & SELECT_BUTTON)))
    {
        if (sub_81AC2C0() == 1)
        {
            ListMenuGetScrollAndRow(data[0], scrollPos, cursorPos);
            if ((*scrollPos + *cursorPos) != gBagMenu->totalItems[gBagPositionStruct.pocket] - 1)
            {
                PlaySE(SE_SELECT);
                BagMenu_SwapItems(taskId);
            }
        }
        return;
    }
    else
    {
        int listPosition = ListMenu_ProcessInput(data[0]);
        ListMenuGetScrollAndRow(data[0], scrollPos, cursorPos);
        switch (listPosition)
        {
            case LIST_NOTHING_CHOSEN:
                break;
            case LIST_CANCEL:
                if (gBagPositionStruct.location == RETURN_LOCATION_FIELD_3)
                {
                    PlaySE(SE_HAZURE);
                    break;
                }
                PlaySE(SE_SELECT);
                gSpecialVar_ItemId = select;
                Bag_BeginCloseWin0Animation();
                gTasks[taskId].func = Task_FadeAndCloseBagMenu;
                break;
            default: // A_BUTTON
                PlaySE(SE_SELECT);
                BagDestroyPocketScrollArrowPair();
                BagMenu_PrintCursor_(data[0], 2);
                data[1] = listPosition;
                data[2] = BagGetQuantityByPocketPosition(gBagPositionStruct.pocket + 1, listPosition);
                gSpecialVar_ItemId = BagGetItemIdByPocketPosition(gBagPositionStruct.pocket + 1, listPosition);
                gTasks[taskId].func = Task_ItemContextMenuByLocation;
                break;
        }
    }
}

static void Task_ItemContextMenuByLocation(u8 taskId)
{
    Bag_FillMessageBoxWithPalette(1);
    gUnknown_08614054[gBagPositionStruct.location](taskId);
}

void set_callback3_to_bag(u8 taskId)
{
    Bag_FillMessageBoxWithPalette(0);
    CreatePocketScrollArrowPair();
    CreatePocketSwitchArrowPair();
    gTasks[taskId].func = Task_BagMenu;
}

static void Bag_FillMessageBoxWithPalette(u32 a0)
{
    SetBgTilemapPalette(1, 0, 14, 30, 6, a0 + 1);
    schedule_bg_copy_tilemap_to_vram(1);
}

u8 GetSwitchBagPocketDirection(void)
{
    u8 LRKeys;
    if (gBagMenu->pocketSwitchMode != 0)
        return 0;
    LRKeys = GetLRKeysPressed();
    if ((gMain.newKeys & DPAD_LEFT) || LRKeys == MENU_L_PRESSED)
    {
        PlaySE(SE_RG_BAG2);
        return 1;
    }
    if ((gMain.newKeys & DPAD_RIGHT) || LRKeys == MENU_R_PRESSED)
    {
        PlaySE(SE_RG_BAG2);
        return 2;
    }
    return 0;
}

void ChangeBagPocketId(u8 *bagPocketId, s8 deltaBagPocketId)
{
    if (deltaBagPocketId == 1 && *bagPocketId == POCKETS_COUNT - 1)
        *bagPocketId = 0;
    else if (deltaBagPocketId == -1 && *bagPocketId == 0)
        *bagPocketId = POCKETS_COUNT - 1;
    else
        *bagPocketId += deltaBagPocketId;
}

void SwitchBagPocket(u8 taskId, s16 deltaBagPocketId, u16 a3)
{
    s16* data = gTasks[taskId].data;
    u8 pocketId;

    data[13] = 0;
    data[12] = 0;
    data[11] = deltaBagPocketId;
    if (a3 == 0)
    {
        ClearWindowTilemap(0);
        ClearWindowTilemap(1);
        ClearWindowTilemap(2);
        DestroyListMenuTask(data[0], &gBagPositionStruct.scrollPosition[gBagPositionStruct.pocket], &gBagPositionStruct.cursorPosition[gBagPositionStruct.pocket]);
        schedule_bg_copy_tilemap_to_vram(0);
        RemoveBagItemIconSprite(gBagMenu->itemMenuIcon ^ 1);
        BagDestroyPocketScrollArrowPair();
    }
    FillBgTilemapBufferRect_Palette0(1, 0x02D, 11, 1, 18, 12);
    schedule_bg_copy_tilemap_to_vram(1);
    pocketId = gBagPositionStruct.pocket;
    ChangeBagPocketId(&pocketId, deltaBagPocketId);
    SetBagVisualPocketId(pocketId);
    SetTaskFuncWithFollowupFunc(taskId, sub_81AC10C, gTasks[taskId].func);
}

void sub_81AC10C(u8 taskId)
{
    s16* data = gTasks[taskId].data;

    if (!sub_81221AC() && !IsWallysBag())
    {
        switch (GetSwitchBagPocketDirection())
        {
            case 1:
                ChangeBagPocketId(&gBagPositionStruct.pocket, data[11]);
                SwitchTaskToFollowupFunc(taskId);
                SwitchBagPocket(taskId, -1, 1);
                return;
            case 2:
                ChangeBagPocketId(&gBagPositionStruct.pocket, data[11]);
                SwitchTaskToFollowupFunc(taskId);
                SwitchBagPocket(taskId, 1, 1);
                return;
        }
    }
    switch (data[13])
    {
        case 0:
            if (data[12] != 0x7FFF)
            {
                data[12]++;
                sub_81AC23C(data[12]);
                if (data[12] == 12)
                    data[12] = 0x7FFF;
            }
            if (data[12] == 0x7FFF)
                data[13]++;
            break;
        case 1:
            ChangeBagPocketId(&gBagPositionStruct.pocket, data[11]);
            BagMenu_PrintPocketName();
            LoadBagItemListBuffers(gBagPositionStruct.pocket);
            data[0] = ListMenuInit(&gMultiuseListMenuTemplate, gBagPositionStruct.scrollPosition[gBagPositionStruct.pocket], gBagPositionStruct.cursorPosition[gBagPositionStruct.pocket]);
            PutWindowTilemap(1);
            PutWindowTilemap(2);
            schedule_bg_copy_tilemap_to_vram(0);
            CreatePocketScrollArrowPair();
            CreatePocketSwitchArrowPair();
            SwitchTaskToFollowupFunc(taskId);
            break;
    }
}

void sub_81AC23C(u8 frame)
{
    CopyToBgTilemapBufferRect(1, sBagListBgTiles[12 - frame], 11, 13 - frame, 18, 1);
    schedule_bg_copy_tilemap_to_vram(1);
}

bool8 sub_81AC2C0(void)
{
    if (gBagPositionStruct.location <= 1)
    {
        u8 temp = gBagPositionStruct.pocket - 2;
        if (temp > 1)
            return TRUE;
    }
    return FALSE;
}

void BagMenu_SwapItems(u8 taskId)
{
    u16 itemsAbove;
    u16 cursorPos;
    s16 *data = gTasks[taskId].data;
    ListMenuGetScrollAndRow(data[0], &cursorPos, &itemsAbove);
    ListMenuSetUnkIndicatorsStructField(data[0], 16, 1);
    data[1] = gBagPositionStruct.scrollPosition[gBagPositionStruct.pocket] + gBagPositionStruct.cursorPosition[gBagPositionStruct.pocket];
    gBagMenu->itemOriginalLocation = data[1];
    CopyItemName(BagGetItemIdByPocketPosition(gBagPositionStruct.pocket + 1, data[1]), gStringVar1);
    StringExpandPlaceholders(gStringVar4, gText_MoveVar1Where);
    FillWindowPixelBuffer(1, PIXEL_FILL(0));
    BagMenu_Print(1, 1, gStringVar4, 0, 3, 2, 0, 0, 0);
    sub_80D4FEC(data[0]);
    sub_80D4FC8(FALSE);
    BagDestroyPocketSwitchArrowPair();
    BagMenu_PrintCursor_(data[0], 2);
    gTasks[taskId].func = sub_81AC3C0;
}

void sub_81AC3C0(u8 taskId)
{
    s16* data = gTasks[taskId].data;
    int input;

    if (sub_81221EC() != TRUE)
    {
        if (gMain.newKeys & SELECT_BUTTON)
        {
            PlaySE(SE_SELECT);
            gBagMenu->itemOriginalLocation = 0xFF;
            sub_80D4FEC(gBagPositionStruct.cursorPosition[gBagPositionStruct.pocket]);
            ListMenuGetScrollAndRow(data[0], &gBagPositionStruct.scrollPosition[gBagPositionStruct.pocket], &gBagPositionStruct.cursorPosition[gBagPositionStruct.pocket]);
            sub_81AC498(taskId);
        }
        else
        {
            input = ListMenu_ProcessInput(data[0]);
            ListMenuGetScrollAndRow(data[0], &gBagPositionStruct.scrollPosition[gBagPositionStruct.pocket], &gBagPositionStruct.cursorPosition[gBagPositionStruct.pocket]);
            sub_80D4FEC(gBagPositionStruct.cursorPosition[gBagPositionStruct.pocket]);
            switch (input)
            {
                case LIST_NOTHING_CHOSEN:
                    break;
                case LIST_CANCEL:
                    PlaySE(SE_SELECT);
                    gBagMenu->itemOriginalLocation = 0xFF;
                    if (gMain.newKeys & A_BUTTON)
                        sub_81AC498(taskId);
                    else
                        sub_81AC590(taskId);
                    break;
                default:
                    PlaySE(SE_SELECT);
                    gBagMenu->itemOriginalLocation = 0xFF;
                    sub_81AC498(taskId);
            }
        }
    }
}

void sub_81AC498(u8 taskId)
{
    s16* data = gTasks[taskId].data;
    u16* scrollPos = &gBagPositionStruct.scrollPosition[gBagPositionStruct.pocket];
    u16* cursorPos = &gBagPositionStruct.cursorPosition[gBagPositionStruct.pocket];
    u16 realPos = (*scrollPos + *cursorPos);

    if (data[1] == realPos || data[1] == (realPos - 1))
        sub_81AC590(taskId);
    else
    {
        MoveItemSlotInList(gBagPockets[gBagPositionStruct.pocket].itemSlots, data[1], realPos);
        DestroyListMenuTask(data[0], scrollPos, cursorPos);
        if (data[1] < realPos)
            gBagPositionStruct.cursorPosition[gBagPositionStruct.pocket]--;
        LoadBagItemListBuffers(gBagPositionStruct.pocket);
        data[0] = ListMenuInit(&gMultiuseListMenuTemplate, *scrollPos, *cursorPos);
        sub_80D4FC8(1);
        CreatePocketSwitchArrowPair();
        gTasks[taskId].func = Task_BagMenu;
    }
}

void sub_81AC590(u8 taskId)
{
    s16* data = gTasks[taskId].data;
    u16* scrollPos = &gBagPositionStruct.scrollPosition[gBagPositionStruct.pocket];
    u16* cursorPos = &gBagPositionStruct.cursorPosition[gBagPositionStruct.pocket];

    DestroyListMenuTask(data[0], scrollPos, cursorPos);
    if (data[1] < (*scrollPos + *cursorPos))
        gBagPositionStruct.cursorPosition[gBagPositionStruct.pocket]--;
    LoadBagItemListBuffers(gBagPositionStruct.pocket);
    data[0] = ListMenuInit(&gMultiuseListMenuTemplate, *scrollPos, *cursorPos);
    sub_80D4FC8(1);
    CreatePocketSwitchArrowPair();
    gTasks[taskId].func = Task_BagMenu;
}

static void InitQuantityToTossOrDeposit(u16 cursorPos, const u8 *str)
{
    u8 r4;
    u8 r5 = BagMenu_AddWindow(6, 2);
    CopyItemName(BagGetItemIdByPocketPosition(gBagPositionStruct.pocket + 1, cursorPos), gStringVar1);
    StringExpandPlaceholders(gStringVar4, str);
    BagMenu_Print(r5, 1, gStringVar4, 0, 2, 1, 0, 0, 1);
    r4 = BagMenu_AddWindow(0, 0);
    ConvertIntToDecimalStringN(gStringVar1, 1, STR_CONV_MODE_LEADING_ZEROS, 3);
    StringExpandPlaceholders(gStringVar4, gText_xVar1);
    BagMenu_Print(r4, 0, gStringVar4, 4, 10, 1, 0, 0, 1);
    CreateArrowPair_QuantitySelect();
}

static void UpdateQuantityToTossOrDeposit(s16 value, u8 ndigits)
{
    u8 r6 = GetBagWindow(0);
    FillWindowPixelBuffer(r6, PIXEL_FILL(1));
    ConvertIntToDecimalStringN(gStringVar1, value, STR_CONV_MODE_LEADING_ZEROS, ndigits);
    StringExpandPlaceholders(gStringVar4, gText_xVar1);
    BagMenu_Print(r6, 0, gStringVar4, 4, 10, 1, 0, 0, 1);
}

void sub_81AC644(u8 unused)
{
    u8 windowId;

    switch (gBagPositionStruct.location)
    {
        case RETURN_LOCATION_BATTLE:
        case RETURN_LOCATION_BATTLE_2:
            if (ItemId_GetBattleUsage(gSpecialVar_ItemId))
            {
                gBagMenu->contextMenuItemsPtr = gUnknown_08614042;
                gBagMenu->contextMenuNumItems = ARRAY_COUNT(gUnknown_08614042);
            }
            else
            {
                gBagMenu->contextMenuItemsPtr = gUnknown_08614046;
                gBagMenu->contextMenuNumItems = ARRAY_COUNT(gUnknown_08614046);
            }
            break;
        case RETURN_LOCATION_FIELD_3:
            gBagMenu->contextMenuItemsPtr = gUnknown_08614047;
            gBagMenu->contextMenuNumItems = ARRAY_COUNT(gUnknown_08614047);
            break;
        case RETURN_LOCATION_FIELD_6:
            if (!ItemId_GetImportance(gSpecialVar_ItemId) && gSpecialVar_ItemId != ITEM_ENIGMA_BERRY)
            {
                gBagMenu->contextMenuItemsPtr = gUnknown_0861404B;
                gBagMenu->contextMenuNumItems = ARRAY_COUNT(gUnknown_0861404B);
            }
            else
            {
                gBagMenu->contextMenuItemsPtr = gUnknown_08614046;
                gBagMenu->contextMenuNumItems = ARRAY_COUNT(gUnknown_08614046);
            }
            break;
        case RETURN_LOCATION_FIELD_4:
            if (!ItemId_GetImportance(gSpecialVar_ItemId) && gSpecialVar_ItemId != ITEM_ENIGMA_BERRY)
            {
                gBagMenu->contextMenuItemsPtr = gUnknown_0861404D;
                gBagMenu->contextMenuNumItems = ARRAY_COUNT(gUnknown_0861404D);
            }
            else
            {
                gBagMenu->contextMenuItemsPtr = gUnknown_08614046;
                gBagMenu->contextMenuNumItems = ARRAY_COUNT(gUnknown_08614046);
            }
            break;
        case RETURN_LOCATION_FIELD_5:
            if (!ItemId_GetImportance(gSpecialVar_ItemId) && gSpecialVar_ItemId != ITEM_ENIGMA_BERRY)
            {
                gBagMenu->contextMenuItemsPtr = gUnknown_0861404F;
                gBagMenu->contextMenuNumItems = ARRAY_COUNT(gUnknown_0861404F);
            }
            else
            {
                gBagMenu->contextMenuItemsPtr = gUnknown_08614046;
                gBagMenu->contextMenuNumItems = ARRAY_COUNT(gUnknown_08614046);
            }
            break;
        case RETURN_LOCATION_POKEMON_LIST:
        case RETURN_LOCATION_SHOP:
        case RETURN_LOCATION_FIELD_2:
        case RETURN_LOCATION_PC:
        default:
            if (sub_81221AC() == TRUE || InUnionRoom() == TRUE)
            {
                if (gBagPositionStruct.pocket == KEYITEMS_POCKET || !sub_8122148(gSpecialVar_ItemId))
                {
                    gBagMenu->contextMenuItemsPtr = gUnknown_08614046;
                    gBagMenu->contextMenuNumItems = ARRAY_COUNT(gUnknown_08614046);
                }
                else
                {
                    gBagMenu->contextMenuItemsPtr = gUnknown_08614044;
                    gBagMenu->contextMenuNumItems = ARRAY_COUNT(gUnknown_08614044);
                }
            }
            else if (ItemId_GetImportance(gSpecialVar_ItemId) == 1)
            {
                gBagMenu->contextMenuItemsPtr = gItemMenu_TossCancel;
                gBagMenu->contextMenuNumItems = ARRAY_COUNT(gItemMenu_TossCancel);
            }
            else
            {
                switch (gBagPositionStruct.pocket)
                {
                    case ITEMS_POCKET:
                        gBagMenu->contextMenuItemsPtr = gBagMenu->unk824;
                        gBagMenu->contextMenuNumItems = ARRAY_COUNT(gUnknown_0861402C);
                        memcpy(&gBagMenu->unk824, &gUnknown_0861402C, sizeof(gUnknown_0861402C));
                        if (ItemIsMail(gSpecialVar_ItemId) == TRUE)
                            gBagMenu->unk824[0] = 6;
                        break;
                    case KEYITEMS_POCKET:
                        gBagMenu->contextMenuItemsPtr = gBagMenu->unk824;
                        gBagMenu->contextMenuNumItems = ARRAY_COUNT(gUnknown_08614030);
                        memcpy(&gBagMenu->unk824, &gUnknown_08614030, sizeof(gUnknown_08614030));
                        if (gSaveBlock1Ptr->registeredItem == gSpecialVar_ItemId)
                            gBagMenu->unk824[1] = 8;
                        if (gSpecialVar_ItemId == ITEM_MACH_BIKE || gSpecialVar_ItemId == ITEM_ACRO_BIKE)
                        {
                            if (TestPlayerAvatarFlags(6))
                                gBagMenu->unk824[0] = 7;
                        }
                        break;
                    case BALLS_POCKET:
                        gBagMenu->contextMenuItemsPtr = gUnknown_08614034;
                        gBagMenu->contextMenuNumItems = ARRAY_COUNT(gUnknown_08614034);
                        break;
                    case TMHM_POCKET:
                        gBagMenu->contextMenuItemsPtr = gUnknown_08614038;
                        gBagMenu->contextMenuNumItems = ARRAY_COUNT(gUnknown_08614038);
                        break;
                    case BERRIES_POCKET:
                        gBagMenu->contextMenuItemsPtr = gUnknown_0861403C;
                        gBagMenu->contextMenuNumItems = ARRAY_COUNT(gUnknown_0861403C);
                        break;
                }
            }
    }

    windowId = BagMenu_AddWindow(10, gBagMenu->contextMenuNumItems - 1);
    AddItemMenuActionTextPrinters(
        windowId,
        1,
        GetMenuCursorDimensionByFont(1, 0),
        2,
        GetFontAttribute(1, FONTATTR_LETTER_SPACING),
        GetFontAttribute(1, FONTATTR_MAX_LETTER_HEIGHT) + 2,
        gBagMenu->contextMenuNumItems,
        sItemMenuActions,
        gBagMenu->contextMenuItemsPtr
    );
    sub_81983AC(windowId, 1, 0, 2, GetFontAttribute(1, FONTATTR_MAX_LETTER_HEIGHT) + 2, gBagMenu->contextMenuNumItems, 0);
    windowId = BagMenu_AddWindow(6, 0);
    CopyItemName(gSpecialVar_ItemId, gStringVar1);
    StringExpandPlaceholders(gStringVar4, gText_Var1IsSelected);
    BagMenu_Print(windowId, 1, gStringVar4, 0, 2, 1, 0, 0, 1);

    /*if (gBagPositionStruct.pocket == TMHM_POCKET)
    {
        ClearWindowTilemap(1);
        PrintTMHMMoveData(gSpecialVar_ItemId);
        PutWindowTilemap(3);
        PutWindowTilemap(4);
        schedule_bg_copy_tilemap_to_vram(0);
    }
    else
    {
        CopyItemName(gSpecialVar_ItemId, gStringVar1);
        StringExpandPlaceholders(gStringVar4, gText_Var1IsSelected);
        FillWindowPixelBuffer(1, PIXEL_FILL(0));
        BagMenu_Print(1, 1, gStringVar4, 3, 1, 0, 0, 0, 0);
    }
    if (gBagMenu->contextMenuNumItems == 1)
        sub_81ACAF8(BagMenu_AddWindow(0, 0));
    else if (gBagMenu->contextMenuNumItems == 2)
        sub_81ACAF8(BagMenu_AddWindow(1, 0));
    else if (gBagMenu->contextMenuNumItems == 4)
        sub_81ACB54(BagMenu_AddWindow(2, 0), 2, 2);
    else
        sub_81ACB54(BagMenu_AddWindow(3, 0), 2, 3);*/
}

void sub_81ACAF8(u8 a)
{
    AddItemMenuActionTextPrinters(a, 7, 8, 1, 0, 16, gBagMenu->contextMenuNumItems, sItemMenuActions, gBagMenu->contextMenuItemsPtr);
    InitMenuInUpperLeftCornerPlaySoundWhenAPressed(a, 1, 0, 1, 16, gBagMenu->contextMenuNumItems, 0);
}

void sub_81ACB54(u8 a, u8 b, u8 c)
{
    sub_8198DBC(a, 7, 8, 1, 0x38, b, c, sItemMenuActions, gBagMenu->contextMenuItemsPtr);
    sub_8199944(a, 0x38, b, c, 0);
}

void unknown_item_menu_type(u8 taskId)
{
    sub_81AC644(taskId);
    gTasks[taskId].func = Task_HandleInBattleItemMenuInput;
}

void Task_HandleInBattleItemMenuInput(u8 taskId)
{
    if (sub_81221EC() != TRUE)
    {
        s8 r4 = Menu_ProcessInputNoWrap();
        switch (r4)
        {
            case MENU_NOTHING_CHOSEN:
                break;
            case MENU_B_PRESSED:
                PlaySE(SE_SELECT);
                sItemMenuActions[4].func.void_u8(taskId);
                break;
            default:
                PlaySE(SE_SELECT);
                sItemMenuActions[gBagMenu->contextMenuItemsPtr[r4]].func.void_u8(taskId);
                break;
        }
    }
}

void Task_HandleOutOfBattleItemMenuInput(u8 taskId)
{
    if (sub_81221EC() != TRUE)
    {
        s8 cursorPos = Menu_GetCursorPos();
        if (gMain.newKeys & DPAD_UP)
        {
            if (cursorPos > 0 && sub_81ACDFC(cursorPos - 2))
            {
                PlaySE(SE_SELECT);
                sub_8199134(0, -1);
            }
        }
        else if (gMain.newKeys & DPAD_DOWN)
        {
            if (cursorPos < (gBagMenu->contextMenuNumItems - 2) && sub_81ACDFC(cursorPos + 2))
            {
                PlaySE(SE_SELECT);
                sub_8199134(0, 1);
            }
        }
        else if ((gMain.newKeys & DPAD_LEFT) || GetLRKeysPressed() == MENU_L_PRESSED)
        {
            if ((cursorPos & 1) && sub_81ACDFC(cursorPos - 1))
            {
                PlaySE(SE_SELECT);
                sub_8199134(-1, 0);
            }
        }
        else if ((gMain.newKeys & DPAD_RIGHT) || GetLRKeysPressed() == MENU_R_PRESSED)
        {
            if (!(cursorPos & 1) && sub_81ACDFC(cursorPos + 1))
            {
                PlaySE(SE_SELECT);
                sub_8199134(1, 0);
            }
        }
        else if (gMain.newKeys & A_BUTTON)
        {
            PlaySE(SE_SELECT);
            sItemMenuActions[gBagMenu->contextMenuItemsPtr[cursorPos]].func.void_u8(taskId);
        }
        else if (gMain.newKeys & B_BUTTON)
        {
            PlaySE(SE_SELECT);
            sItemMenuActions[4].func.void_u8(taskId);
        }
    }
}

bool8 sub_81ACDFC(s8 a)
{
    if (a < 0)
        return FALSE;
    if (a > gBagMenu->contextMenuNumItems)
        return FALSE;
    if (gBagMenu->contextMenuItemsPtr[a] == 14)
        return FALSE;
    return TRUE;
}

void BagMenu_RemoveSomeWindow(void)
{
    if (gBagMenu->contextMenuNumItems == 1)
        BagMenu_RemoveWindow(0);
    else if (gBagMenu->contextMenuNumItems == 2)
    {
        BagMenu_RemoveWindow(1);
    }
    else if (gBagMenu->contextMenuNumItems == 4)
    {
        BagMenu_RemoveWindow(2);
    }
    else
        BagMenu_RemoveWindow(3);
}

void ItemMenu_UseOutOfBattle(u8 taskId)
{
    if (ItemId_GetFieldFunc(gSpecialVar_ItemId))
    {
        BagMenu_RemoveWindow(10);
        BagMenu_RemoveWindow(6);
        PutWindowTilemap(0);
        PutWindowTilemap(1);
        if (CalculatePlayerPartyCount() == 0 && ItemId_GetType(gSpecialVar_ItemId) == 1)
            BagMenu_PrintThereIsNoPokemon(taskId);
        else
        {
            if (gBagPositionStruct.pocket != BERRIES_POCKET)
                ItemId_GetFieldFunc(gSpecialVar_ItemId)(taskId);
            else
                ItemUseOutOfBattle_Berry(taskId);
        }
    }
}

void ItemMenu_Toss(u8 taskId)
{
    s16* data = gTasks[taskId].data;
    ClearWindowTilemap(GetBagWindow(10));
    ClearWindowTilemap(GetBagWindow(6));
    BagMenu_RemoveWindow(10);
    BagMenu_RemoveWindow(6);
    PutWindowTilemap(0);
    tItemCount = 1;
    if (data[2] == 1)
    {
        BagMenu_TossItems(taskId);
    }
    else
    {
        InitQuantityToTossOrDeposit(data[1], gText_TossHowManyVar1s);
        gTasks[taskId].func = Task_ChooseHowManyToToss;
    }
}

void BagMenu_TossItems(u8 taskId)
{
    s16* data = gTasks[taskId].data;

    CopyItemName(gSpecialVar_ItemId, gStringVar1);
    ConvertIntToDecimalStringN(gStringVar2, tItemCount, STR_CONV_MODE_LEFT_ALIGN, 3);
    StringExpandPlaceholders(gStringVar4, gText_ConfirmTossItems);
    BagMenu_Print(BagMenu_AddWindow(6, 1), 1, gStringVar4, 0, 2, 1, 0, 0, 1);
    BagCreateYesNoMenuBottomRight(taskId, &sYesNoTossFunctions);
}

void BagMenu_CancelToss(u8 taskId)
{
    s16* data = gTasks[taskId].data;
    BagMenu_RemoveWindow(6);
    PutWindowTilemap(1);
    schedule_bg_copy_tilemap_to_vram(0);
    BagMenu_PrintCursor_(data[0], 1);
    set_callback3_to_bag(taskId);
}

void Task_ChooseHowManyToToss(u8 taskId)
{
    s16* data = gTasks[taskId].data;

    if (AdjustQuantityAccordingToDPadInput(&tItemCount, data[2]) == TRUE)
    {
        UpdateQuantityToTossOrDeposit(tItemCount, 3);
    }
    else if (gMain.newKeys & A_BUTTON)
    {
        PlaySE(SE_SELECT);
        ClearWindowTilemap(GetBagWindow(6));
        BagMenu_RemoveWindow(6);
        BagMenu_RemoveWindow(0);
        schedule_bg_copy_tilemap_to_vram(0);
        BagDestroyPocketScrollArrowPair();
        BagMenu_TossItems(taskId);
    }
    else if (gMain.newKeys & B_BUTTON)
    {
        PlaySE(SE_SELECT);
        BagMenu_RemoveWindow(6);
        BagMenu_RemoveWindow(0);
        PutWindowTilemap(0);
        PutWindowTilemap(1);
        schedule_bg_copy_tilemap_to_vram(0);
        BagMenu_PrintCursor_(data[0], 1);
        BagDestroyPocketScrollArrowPair();
        set_callback3_to_bag(taskId);
    }
}

void BagMenu_ConfirmToss(u8 taskId)
{
    s16* data = gTasks[taskId].data;
    BagMenu_RemoveWindow(6);
    CopyItemName(gSpecialVar_ItemId, gStringVar1);
    ConvertIntToDecimalStringN(gStringVar2, tItemCount, STR_CONV_MODE_LEFT_ALIGN, 3);
    StringExpandPlaceholders(gStringVar4, gText_ThrewAwayVar2Var1s);
    BagMenu_Print(BagMenu_AddWindow(6, 3), 1, gStringVar4, 0, 2, 1, 0, 0, 1);
    gTasks[taskId].func = Task_ActuallyToss;
}

void Task_ActuallyToss(u8 taskId)
{
    s16* data = gTasks[taskId].data;
    u16* scrollPos = &gBagPositionStruct.scrollPosition[gBagPositionStruct.pocket];
    u16* cursorPos = &gBagPositionStruct.cursorPosition[gBagPositionStruct.pocket];

    if (gMain.newKeys & (A_BUTTON | B_BUTTON))
    {
        PlaySE(SE_SELECT);
        RemoveBagItem(gSpecialVar_ItemId, tItemCount);
        BagMenu_RemoveWindow(6);
        DestroyListMenuTask(data[0], scrollPos, cursorPos);
        UpdatePocketItemList(gBagPositionStruct.pocket);
        SetInitialScrollAndCursorPositions(gBagPositionStruct.pocket);
        LoadBagItemListBuffers(gBagPositionStruct.pocket);
        data[0] = ListMenuInit(&gMultiuseListMenuTemplate, *scrollPos, *cursorPos);
        PutWindowTilemap(1);
        schedule_bg_copy_tilemap_to_vram(0);
        BagMenu_PrintCursor_(data[0], 1);
        set_callback3_to_bag(taskId);
    }
}

void ItemMenu_Register(u8 taskId)
{
    s16* data = gTasks[taskId].data;
    u16* scrollPos = &gBagPositionStruct.scrollPosition[gBagPositionStruct.pocket];
    u16* cursorPos = &gBagPositionStruct.cursorPosition[gBagPositionStruct.pocket];

    if (gSaveBlock1Ptr->registeredItem == gSpecialVar_ItemId)
        gSaveBlock1Ptr->registeredItem = ITEM_NONE;
    else
        gSaveBlock1Ptr->registeredItem = gSpecialVar_ItemId;

    DestroyListMenuTask(data[0], scrollPos, cursorPos);
    LoadBagItemListBuffers(gBagPositionStruct.pocket);
    data[0] = ListMenuInit(&gMultiuseListMenuTemplate, *scrollPos, *cursorPos);
    CopyWindowToVram(0, 1);
    ItemMenu_Cancel(taskId);
}

void ItemMenu_Give(u8 taskId)
{
    BagMenu_RemoveWindow(10);
    BagMenu_RemoveWindow(6);
    PutWindowTilemap(0);
    PutWindowTilemap(1);
    CopyWindowToVram(0, 1);
    if (!itemid_80BF6D8_mail_related(gSpecialVar_ItemId))
    {
        DisplayItemMessage(taskId, 1, gText_CantWriteMail, sub_81AD350);
    }
    else if (!ItemId_GetImportance(gSpecialVar_ItemId))
    {
        if (CalculatePlayerPartyCount() == 0)
            BagMenu_PrintThereIsNoPokemon(taskId);
        else
        {
            gBagMenu->mainCallback2 = CB2_ChooseMonToGiveItem;
            gTasks[taskId].func = Task_FadeAndCloseBagMenu;
        }
    }
    else
    {
        BagMenu_PrintItemCantBeHeld(taskId);
    }
}

void BagMenu_PrintThereIsNoPokemon(u8 taskId)
{
    DisplayItemMessage(taskId, 1, gText_NoPokemon, sub_81AD350);
}

void BagMenu_PrintItemCantBeHeld(u8 taskId)
{
    CopyItemName(gSpecialVar_ItemId, gStringVar1);
    StringExpandPlaceholders(gStringVar4, gText_Var1CantBeHeld);
    DisplayItemMessage(taskId, 1, gStringVar4, sub_81AD350);
}

void sub_81AD350(u8 taskId)
{
    if (gMain.newKeys & A_BUTTON)
    {
        PlaySE(SE_SELECT);
        BagMenu_InitListsMenu(taskId);
    }
}

void ItemMenu_CheckTag(u8 taskId)
{
    gBagMenu->mainCallback2 = DoBerryTagScreen;
    Task_FadeAndCloseBagMenu(taskId);
}

void ItemMenu_Cancel(u8 taskId)
{
    s16* data = gTasks[taskId].data;

    BagMenu_RemoveWindow(10);
    BagMenu_RemoveWindow(6);
    PutWindowTilemap(0);
    PutWindowTilemap(1);
    schedule_bg_copy_tilemap_to_vram(0);
    BagMenu_PrintCursor_(data[0], 1);
    set_callback3_to_bag(taskId);
}

void ItemMenu_UseInBattle(u8 taskId)
{
    if (ItemId_GetBattleFunc(gSpecialVar_ItemId))
    {
        BagMenu_RemoveWindow(10);
        BagMenu_RemoveWindow(6);
        PutWindowTilemap(0);
        PutWindowTilemap(1);
        CopyWindowToVram(0, 1);
        ItemId_GetBattleFunc(gSpecialVar_ItemId)(taskId);
    }
}

void CB2_ReturnToBagMenuPocket(void)
{
    GoToBagMenu(RETURN_LOCATION_UNCHANGED, POCKETS_COUNT, NULL);
}

void item_menu_type_2(u8 taskId)
{
    if (!itemid_80BF6D8_mail_related(gSpecialVar_ItemId))
    {
        DisplayItemMessage(taskId, 1, gText_CantWriteMail, sub_81AD350);
    }
    else if (!sub_8122148(gSpecialVar_ItemId))
    {
        CopyItemName(gSpecialVar_ItemId, gStringVar1);
        StringExpandPlaceholders(gStringVar4, gText_Var1CantBeHeldHere);
        DisplayItemMessage(taskId, 1, gStringVar4, sub_81AD350);
    }
    else if (gBagPositionStruct.pocket != KEYITEMS_POCKET && !ItemId_GetImportance(gSpecialVar_ItemId))
    {
        Task_FadeAndCloseBagMenu(taskId);
    }
    else
    {
        BagMenu_PrintItemCantBeHeld(taskId);
    }
}

void item_menu_type_b(u8 taskId)
{
    if (ItemIsMail(gSpecialVar_ItemId) == TRUE)
        DisplayItemMessage(taskId, 1, gText_CantWriteMail, sub_81AD350);
    else if (gBagPositionStruct.pocket != KEYITEMS_POCKET && !ItemId_GetImportance(gSpecialVar_ItemId))
        gTasks[taskId].func = Task_FadeAndCloseBagMenu;
    else
        BagMenu_PrintItemCantBeHeld(taskId);
}

#define tUsingRegisteredKeyItem data[3]

bool8 UseRegisteredKeyItemOnField(void)
{
    u8 taskId;

    if (InUnionRoom() == TRUE || InBattlePyramid() || InBattlePike() || InMultiPartnerRoom() == TRUE)
        return FALSE;
    HideMapNamePopUpWindow();
    ChangeBgY_ScreenOff(0, 0, 0);
    if (gSaveBlock1Ptr->registeredItem != ITEM_NONE)
    {
        if (CheckBagHasItem(gSaveBlock1Ptr->registeredItem, 1) == TRUE)
        {
            ScriptContext2_Enable();
            FreezeObjectEvents();
            sub_808B864();
            sub_808BCF4();
            gSpecialVar_ItemId = gSaveBlock1Ptr->registeredItem;
            taskId = CreateTask(ItemId_GetFieldFunc(gSaveBlock1Ptr->registeredItem), 8);
            gTasks[taskId].tUsingRegisteredKeyItem = TRUE;
            return TRUE;
        }
        else
        {
            gSaveBlock1Ptr->registeredItem = ITEM_NONE;
        }
    }
    ScriptContext1_SetupScript(EventScript_SelectWithoutRegisteredItem);
    return TRUE;
}

#undef tUsingRegisteredKeyItem

void DisplaySellItemAskString(u8 taskId)
{
    s16* data = gTasks[taskId].data;

    if (ItemId_GetPrice(gSpecialVar_ItemId) == 0)
    {
        CopyItemName(gSpecialVar_ItemId, gStringVar1);
        StringExpandPlaceholders(gStringVar4, gText_CantBuyKeyItem);
        DisplayItemMessage(taskId, 1, gStringVar4, BagMenu_InitListsMenu);
    }
    else
    {
        tItemCount = 1;
        if (data[2] == 1)
        {
            DisplayCurrentMoneyWindow();
            DisplaySellItemPriceAndConfirm(taskId);
        }
        else
        {
            CopyItemName(gSpecialVar_ItemId, gStringVar1);
            StringExpandPlaceholders(gStringVar4, gText_HowManyToSell);
            DisplayItemMessage(taskId, 1, gStringVar4, sub_81AD730);
        }
    }
}

void DisplaySellItemPriceAndConfirm(u8 taskId)
{
    s16* data = gTasks[taskId].data;

    ConvertIntToDecimalStringN(gStringVar3, (ItemId_GetPrice(gSpecialVar_ItemId) / 2) * tItemCount, STR_CONV_MODE_LEFT_ALIGN, 6);
    StringExpandPlaceholders(gStringVar4, gText_ICanPayVar1);
    DisplayItemMessage(taskId, 1, gStringVar4, sub_81AD6E4);
}

void sub_81AD6E4(u8 taskId)
{
    BagCreateYesNoMenuTopRight(taskId, &sYesNoSellItemFunctions);
}

void BagMenu_CancelSell(u8 taskId)
{
    s16* data = gTasks[taskId].data;
    BagMenu_RemoveWindow(2);
    bag_menu_RemoveBagItem_message_window(5);
    PutWindowTilemap(2);
    PutWindowTilemap(0);
    PutWindowTilemap(1);
    schedule_bg_copy_tilemap_to_vram(0);
    BagMenu_PrintCursor_(data[0], 1);
    set_callback3_to_bag(taskId);
}

void sub_81AD730(u8 taskId)
{
    s16* data = gTasks[taskId].data;
    u8 windowId = BagMenu_AddWindow(0, 1);

    PrintItemSoldAmount(windowId, 1, (ItemId_GetPrice(gSpecialVar_ItemId) / 2) * tItemCount);
    DisplayCurrentMoneyWindow();
    CreatePocketScrollArrowPair_SellQuantity();
    gTasks[taskId].func = Task_BuyHowManyDialogueHandleInput;
}

void Task_BuyHowManyDialogueHandleInput(u8 taskId)
{
    s16* data = gTasks[taskId].data;

    if (AdjustQuantityAccordingToDPadInput(&tItemCount, data[2]) == TRUE)
    {
        PrintItemSoldAmount(GetBagWindow(0), tItemCount, (ItemId_GetPrice(gSpecialVar_ItemId) / 2) * tItemCount);
    }
    else if (gMain.newKeys & A_BUTTON)
    {
        PlaySE(SE_SELECT);
        BagMenu_RemoveWindow(0);
        PutWindowTilemap(0);
        schedule_bg_copy_tilemap_to_vram(0);
        BagDestroyPocketScrollArrowPair();
        DisplaySellItemPriceAndConfirm(taskId);
    }
    else if (gMain.newKeys & B_BUTTON)
    {
        PlaySE(SE_SELECT);
        BagMenu_RemoveWindow(0);
        BagMenu_RemoveWindow(2);
        bag_menu_RemoveBagItem_message_window(5);
        PutWindowTilemap(2);
        PutWindowTilemap(0);
        PutWindowTilemap(1);
        schedule_bg_copy_tilemap_to_vram(0);
        BagDestroyPocketScrollArrowPair();
        BagMenu_PrintCursor_(data[0], 1);
        set_callback3_to_bag(taskId);
    }
}

void BagMenu_ConfirmSell(u8 taskId)
{
    s16* data = gTasks[taskId].data;
    PutWindowTilemap(0);
    schedule_bg_copy_tilemap_to_vram(0);
    CopyItemName(gSpecialVar_ItemId, gStringVar1);
    ConvertIntToDecimalStringN(gStringVar3, (ItemId_GetPrice(gSpecialVar_ItemId) / 2) * tItemCount, STR_CONV_MODE_LEFT_ALIGN, 6);
    StringExpandPlaceholders(gStringVar4, gText_TurnedOverVar1ForVar2);
    DisplayItemMessage(taskId, 1, gStringVar4, sub_81AD8C8);
}

void sub_81AD8C8(u8 taskId)
{
    s16* data = gTasks[taskId].data;
    u16* scrollPos = &gBagPositionStruct.scrollPosition[gBagPositionStruct.pocket];
    u16* cursorPos = &gBagPositionStruct.cursorPosition[gBagPositionStruct.pocket];

    PlaySE(SE_RG_SHOP);
    RemoveBagItem(gSpecialVar_ItemId, tItemCount);
    AddMoney(&gSaveBlock1Ptr->money, (ItemId_GetPrice(gSpecialVar_ItemId) / 2) * tItemCount);
    DestroyListMenuTask(data[0], scrollPos, cursorPos);
    UpdatePocketItemList(gBagPositionStruct.pocket);
    SetInitialScrollAndCursorPositions(gBagPositionStruct.pocket);
    gBagMenu->inhibitItemDescriptionPrint = TRUE;
    LoadBagItemListBuffers(gBagPositionStruct.pocket);
    data[0] = ListMenuInit(&gMultiuseListMenuTemplate, *scrollPos, *cursorPos);
    BagMenu_PrintCursor_(data[0], 2);
    BagDrawTextBoxOnWindow(GetBagWindow(2));
    PrintMoneyAmountInMoneyBox(GetBagWindow(2), GetMoney(&gSaveBlock1Ptr->money), 0);
    gTasks[taskId].func = sub_81AD9C0;
}

void sub_81AD9C0(u8 taskId)
{
    if (gMain.newKeys & (A_BUTTON | B_BUTTON))
    {
        PlaySE(SE_SELECT);
        BagMenu_RemoveWindow(2);
        PutWindowTilemap(2);
        gBagMenu->inhibitItemDescriptionPrint = FALSE;
        BagMenu_InitListsMenu(taskId);
    }
}

void DisplayDepositItemAskString(u8 taskId)
{
    s16* data = gTasks[taskId].data;

    tItemCount = 1;
    if (data[2] == 1)
    {
        Task_TryDoItemDeposit(taskId);
    }
    else
    {
        InitQuantityToTossOrDeposit(data[1], gText_DepositHowManyVar1);
        gTasks[taskId].func = sub_81ADA7C;
    }
}

void sub_81ADA7C(u8 taskId)
{
    s16* data = gTasks[taskId].data;

    if (AdjustQuantityAccordingToDPadInput(&tItemCount, data[2]) == TRUE)
    {
        PrintItemDepositAmount(gBagMenu->windowPointers[7], tItemCount);
    }
    else if (gMain.newKeys & A_BUTTON)
    {
        PlaySE(SE_SELECT);
        ClearWindowTilemap(GetBagWindow(6));
        BagMenu_RemoveWindow(6);
        BagMenu_RemoveWindow(0);
        schedule_bg_copy_tilemap_to_vram(0);
        BagDestroyPocketScrollArrowPair();
        Task_TryDoItemDeposit(taskId);
    }
    else if (gMain.newKeys & B_BUTTON)
    {
        PlaySE(SE_SELECT);
        BagMenu_RemoveWindow(6);
        BagMenu_RemoveWindow(0);
        PutWindowTilemap(1);
        schedule_bg_copy_tilemap_to_vram(0);
        BagMenu_PrintCursor_(data[0], 1);
        BagDestroyPocketScrollArrowPair();
        set_callback3_to_bag(taskId);
    }
}

void Task_TryDoItemDeposit(u8 taskId)
{
    s16* data = gTasks[taskId].data;

    FillWindowPixelBuffer(1, PIXEL_FILL(0));
    if (ItemId_GetImportance(gSpecialVar_ItemId) > 1)
    {
        DisplayItemMessage(taskId, 1, gText_CantStoreImportantItems, sub_81ADC0C);
    }
    else if (AddPCItem(gSpecialVar_ItemId, tItemCount) == TRUE)
    {
        CopyItemName(gSpecialVar_ItemId, gStringVar1);
        ConvertIntToDecimalStringN(gStringVar2, tItemCount, STR_CONV_MODE_LEFT_ALIGN, 3);
        StringExpandPlaceholders(gStringVar4, gText_DepositedVar2Var1s);
        BagMenu_Print(BagMenu_AddWindow(6, 3), 1, gStringVar4, 0, 2, 1, 0, 0, 1);
        gTasks[taskId].func = Task_ActuallyToss;
    }
    else
    {
        DisplayItemMessage(taskId, 1, gText_NoRoomForItems, sub_81ADC0C);
    }
}

void sub_81ADC0C(u8 taskId)
{
    s16* data = gTasks[taskId].data;

    if (gMain.newKeys & A_BUTTON)
    {
        PlaySE(SE_SELECT);
        BagMenu_InitListsMenu(taskId);
    }
}

bool8 IsWallysBag(void)
{
    if (gBagPositionStruct.location == 10)
        return TRUE;
    return FALSE;
}

void PrepareBagForWallyTutorial(void)
{
    u32 i;

    sTempWallyBag = AllocZeroed(sizeof(struct TempWallyStruct));
    memcpy(sTempWallyBag->bagPocket_Items, gSaveBlock1Ptr->bagPocket_Items, sizeof(gSaveBlock1Ptr->bagPocket_Items));
    memcpy(sTempWallyBag->bagPocket_PokeBalls, gSaveBlock1Ptr->bagPocket_PokeBalls, sizeof(gSaveBlock1Ptr->bagPocket_PokeBalls));
    sTempWallyBag->pocket = gBagPositionStruct.pocket;
    for (i = 0; i <= 4; i++)
    {
        sTempWallyBag->cursorPosition[i] = gBagPositionStruct.cursorPosition[i];
        sTempWallyBag->scrollPosition[i] = gBagPositionStruct.scrollPosition[i];
    }
    ClearItemSlots(gSaveBlock1Ptr->bagPocket_Items, BAG_ITEMS_COUNT);
    ClearItemSlots(gSaveBlock1Ptr->bagPocket_PokeBalls, BAG_POKEBALLS_COUNT);
    ResetBagScrollPositions();
}

void RestoreBagAfterWallyTutorial(void)
{
    u32 i;

    memcpy(gSaveBlock1Ptr->bagPocket_Items, sTempWallyBag->bagPocket_Items, sizeof(sTempWallyBag->bagPocket_Items));
    memcpy(gSaveBlock1Ptr->bagPocket_PokeBalls, sTempWallyBag->bagPocket_PokeBalls, sizeof(sTempWallyBag->bagPocket_PokeBalls));
    gBagPositionStruct.pocket = sTempWallyBag->pocket;
    for (i = 0; i <= 4; i++)
    {
        gBagPositionStruct.cursorPosition[i] = sTempWallyBag->cursorPosition[i];
        gBagPositionStruct.scrollPosition[i] = sTempWallyBag->scrollPosition[i];
    }
    Free(sTempWallyBag);
}

void DoWallyTutorialBagMenu(void)
{
    PrepareBagForWallyTutorial();
    AddBagItem(ITEM_POTION, 1);
    AddBagItem(ITEM_POKE_BALL, 5);
    GoToBagMenu(RETURN_LOCATION_BATTLE_2, ITEMS_POCKET, CB2_SetUpReshowBattleScreenAfterMenu2);
}

void Task_WallyTutorialBagMenu(u8 taskId)
{
    s16* data = gTasks[taskId].data;

    if (!gPaletteFade.active)
    {
        switch (data[8])
        {
            case 0x66:
                PlaySE(SE_RG_BAG2);
                SwitchBagPocket(taskId, 1, 0);
                data[8]++;
                break;
            case 0xCC:
                PlaySE(SE_SELECT);
                BagMenu_PrintCursor_(data[0], 2);
                Bag_FillMessageBoxWithPalette(1);
                gSpecialVar_ItemId = ITEM_POKE_BALL;
                sub_81AC644(taskId);
                data[8]++;
                break;
            case 0x132:
                PlaySE(SE_SELECT);
                BagMenu_RemoveWindow(10);
                BagMenu_RemoveWindow(6);
                PutWindowTilemap(0);
                PutWindowTilemap(1);
                CopyWindowToVram(0, 1);
                DestroyListMenuTask(data[0], 0, 0);
                RestoreBagAfterWallyTutorial();
                Bag_BeginCloseWin0Animation();
                gTasks[taskId].func = Task_Dude_FadeFromBag;
                break;
            default:
                data[8]++;
                break;
        }
    }
}

static void Task_Dude_FadeFromBag(u8 taskId)
{
    BeginNormalPaletteFade(0xFFFFFFFF, -2, 0, 16, RGB_BLACK);
    gTasks[taskId].func = Task_Dude_WaitFadeAndExitBag;
}

static void Task_Dude_WaitFadeAndExitBag(u8 taskId)
{
    s16* data = gTasks[taskId].data;
    if (!gPaletteFade.active && FuncIsActiveTask(Task_AnimateWin0v) != TRUE)
    {
        DestroyListMenuTask(data[0], &gBagPositionStruct.scrollPosition[gBagPositionStruct.pocket], &gBagPositionStruct.cursorPosition[gBagPositionStruct.pocket]);
        if (gBagMenu->mainCallback2 != 0)
            SetMainCallback2(gBagMenu->mainCallback2);
        else
            SetMainCallback2(gBagPositionStruct.bagCallback);
        BagDestroyPocketScrollArrowPair();
        ResetSpriteData();
        FreeAllSpritePalettes();
        FreeBagItemListBuffers();
        DestroyTask(taskId);
    }
}

#undef tItemCount

void unknown_ItemMenu_Show(u8 taskId)
{
    gSpecialVar_0x8005 = gSpecialVar_ItemId;
    gSpecialVar_Result = 1;
    BagMenu_RemoveSomeWindow();
    Task_FadeAndCloseBagMenu(taskId);
}

void CB2_ApprenticeExitBagMenu(void)
{
    gFieldCallback = Apprentice_EnableBothScriptContexts;
    SetMainCallback2(CB2_ReturnToField);
}

void unknown_ItemMenu_Give2(u8 taskId)
{
    RemoveBagItem(gSpecialVar_ItemId, 1);
    gSpecialVar_Result = 1;
    BagMenu_RemoveSomeWindow();
    Task_FadeAndCloseBagMenu(taskId);
}

void CB2_FavorLadyExitBagMenu(void)
{
    gFieldCallback = FieldCallback_FavorLadyEnableScriptContexts;
    SetMainCallback2(CB2_ReturnToField);
}

void unknown_ItemMenu_Confirm2(u8 taskId)
{
    gSpecialVar_Result = 1;
    BagMenu_RemoveSomeWindow();
    Task_FadeAndCloseBagMenu(taskId);
}

void CB2_QuizLadyExitBagMenu(void)
{
    gFieldCallback = FieldCallback_QuizLadyEnableScriptContexts;
    SetMainCallback2(CB2_ReturnToField);
}

void BagMenu_PrintPocketName(void)
{
    int offset;

    FillWindowPixelBuffer(2, PIXEL_FILL(0));
    offset = GetStringCenterAlignXOffset(1, gPocketNamesStringsTable[gBagPositionStruct.pocket], 0x48);
    BagMenu_Print(2, 1, gPocketNamesStringsTable[gBagPositionStruct.pocket], offset, 1, GetFontAttribute(1, FONTATTR_LETTER_SPACING), GetFontAttribute(1, FONTATTR_LINE_SPACING), 0, 0);
}

void BagDrawDepositItemTextBox(void)
{
    u32 x;
    DrawStdFrameWithCustomTileAndPalette(2, FALSE, 129, 12);
    x = GetStringCenterAlignXOffset(0, gText_DepositItem, 0x40);
    AddTextPrinterParameterized(2, 0, gText_DepositItem, x, 1, 0, NULL);
}

void SetupBagMenu_Textboxes(void)
{
    u8 i;

    if (gBagPositionStruct.location != RETURN_LOCATION_PC)
        InitWindows(sDefaultBagWindowsStd);
    else
        InitWindows(sDefaultBagWindowsDeposit);
    DeactivateAllTextPrinters();
    LoadUserWindowBorderGfx(0, 100, 0xE0);
    LoadMessageBoxGfx(0, 109, 0xD0);
    LoadThinWindowBorderGfx(0, 129, 0xC0);
    //sub_819A2BC(0xC0, 1);
    LoadPalette(&sBagWindowPalF, 0xF0, 0x20);
    LoadPalette(sPal3Override, 0xF6, 0x04);
    for (i = 0; i < 3; i++)
    {
        FillWindowPixelBuffer(i, PIXEL_FILL(0));
        PutWindowTilemap(i);
    }
    schedule_bg_copy_tilemap_to_vram(0);
    memset(gBagMenu->windowPointers, 0xFF, 10);
}

void BagMenu_Print(u8 windowId, u8 fontId, const u8 *str, u8 left, u8 top, u8 letterSpacing, u8 lineSpacing, u8 speed, u8 h)
{
    AddTextPrinterParameterized4(windowId, fontId, left, top, letterSpacing, lineSpacing, sFontColorTable[h], speed, str);
}

u8 GetBagWindow(u8 a)
{
    return gBagMenu->windowPointers[a];
}

u8 BagMenu_AddWindow(u8 whichWindow, u8 nItems)
{
    u8 *ptr = &gBagMenu->windowPointers[whichWindow];
    if (*ptr == 0xFF)
    {
        *ptr = AddWindow(&gUnknown_086141AC[whichWindow + nItems]);
        if (whichWindow != 6)
        {
            DrawStdFrameWithCustomTileAndPalette(*ptr, FALSE, 100, 14);
        }
        else
        {
            DrawStdFrameWithCustomTileAndPalette(*ptr, FALSE, 129, 12);
        }
        schedule_bg_copy_tilemap_to_vram(0);
    }
    return *ptr;
}

void BagMenu_RemoveWindow(u8 a)
{
    u8 *ptr = &gBagMenu->windowPointers[a];
    if (*ptr != 0xFF)
    {
        ClearStdWindowAndFrameToTransparent(*ptr, FALSE);
        ClearWindowTilemap(*ptr);
        RemoveWindow(*ptr);
        schedule_bg_copy_tilemap_to_vram(0);
        *ptr = 0xFF;
    }
}

u8 AddItemMessageWindow(u8 a)
{
    u8 *ptr = &gBagMenu->windowPointers[a];
    if (*ptr == 0xFF)
        *ptr = AddWindow(&gUnknown_086141AC[a]);
    return *ptr;
}

void bag_menu_RemoveBagItem_message_window(u8 a)
{
    u8 *ptr = &gBagMenu->windowPointers[a];
    if (*ptr != 0xFF)
    {
        ClearDialogWindowAndFrameToTransparent(*ptr, FALSE);
        // This ClearWindowTilemap call is redundant, since ClearDialogWindowAndFrameToTransparent already calls it.
        ClearWindowTilemap(*ptr);
        RemoveWindow(*ptr);
        PutWindowTilemap(1);
        schedule_bg_copy_tilemap_to_vram(0);
        *ptr = 0xFF;
    }
}

void BagCreateYesNoMenuBottomRight(u8 taskId, const struct YesNoFuncTable * ptrs)
{
    CreateYesNoMenuWithCallbacks(taskId, &gUnknown_086141AC[3], 1, 0, 2, 100, 14, ptrs);
}

void BagCreateYesNoMenuTopRight(u8 taskId, const struct YesNoFuncTable * ptrs)
{
    CreateYesNoMenuWithCallbacks(taskId, &gUnknown_086141AC[4], 1, 0, 2, 100, 14, ptrs);
}

void DisplayCurrentMoneyWindow(void)
{
    PrintMoneyAmountInMoneyBoxWithBorder(BagMenu_AddWindow(2, 0), 129, 12, GetMoney(&gSaveBlock1Ptr->money));
}

void BagDrawTextBoxOnWindow(u8 windowId)
{
    DrawTextBorderOuter(windowId, 100, 14);
}

void BagMenu_PrepareTMHMMoveWindow(void)
{
    FillWindowPixelBuffer(3, PIXEL_FILL(0));
    blit_move_info_icon(3, 19, 0, 0);
    blit_move_info_icon(3, 20, 0, 12);
    blit_move_info_icon(3, 21, 0, 24);
    blit_move_info_icon(3, 22, 0, 36);
    CopyWindowToVram(3, 2);
}

void PrintTMHMMoveData(u16 itemId)
{
    u8 i;
    u16 moveId;
    const u8* text;

    FillWindowPixelBuffer(4, PIXEL_FILL(0));
    if (itemId == ITEM_NONE)
    {
        for (i = 0; i < 4; i++)
            BagMenu_Print(4, 1, gText_ThreeDashes, 7, i * 12, 0, 0, -1, 4);
        CopyWindowToVram(4, 2);
    }
    else
    {
        moveId = ItemIdToBattleMoveId(itemId);
        blit_move_info_icon(4, gBattleMoves[moveId].type + 1, 0, 0);
        if (gBattleMoves[moveId].power <= 1)
        {
            text = gText_ThreeDashes;
        }
        else
        {
            ConvertIntToDecimalStringN(gStringVar1, gBattleMoves[moveId].power, STR_CONV_MODE_RIGHT_ALIGN, 3);
            text = gStringVar1;
        }
        BagMenu_Print(4, 1, text, 7, 12, 0, 0, -1, 4);
        if (gBattleMoves[moveId].accuracy == 0)
        {
            text = gText_ThreeDashes;
        }
        else
        {
            ConvertIntToDecimalStringN(gStringVar1, gBattleMoves[moveId].accuracy, STR_CONV_MODE_RIGHT_ALIGN, 3);
            text = gStringVar1;
        }
        BagMenu_Print(4, 1, text, 7, 24, 0, 0, -1, 4);
        ConvertIntToDecimalStringN(gStringVar1, gBattleMoves[moveId].pp, STR_CONV_MODE_RIGHT_ALIGN, 3);
        BagMenu_Print(4, 1, gStringVar1, 7, 36, 0, 0, -1, 4);
        CopyWindowToVram(4, 2);
    }
}
