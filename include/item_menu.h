#ifndef GUARD_ITEM_MENU_H
#define GUARD_ITEM_MENU_H

#include "item.h"
#include "menu_helpers.h"

// IDs for text colors
enum {
    COLORID_DESCRIPTION,
    COLORID_NORMAL,
    COLORID_GRAY_CURSOR,
    COLORID_NONE = 0xFF
};

enum {
    ITEMMENULOCATION_FIELD,
    ITEMMENULOCATION_BATTLE,
    ITEMMENULOCATION_PARTY,
    ITEMMENULOCATION_SHOP,
    ITEMMENULOCATION_BERRY_TREE,
    ITEMMENULOCATION_BERRY_BLENDER_CRUSH,
    ITEMMENULOCATION_ITEMPC,
    ITEMMENULOCATION_FAVOR_LADY,
    ITEMMENULOCATION_QUIZ_LADY,
    ITEMMENULOCATION_APPRENTICE,
    ITEMMENULOCATION_WALLY,
    ITEMMENULOCATION_PCBOX,
    ITEMMENULOCATION_LAST,
};

// Window IDs for the item menu
// TODO: These are possibly different in FRLG
enum {
    ITEMWIN_QUANTITY,
    ITEMWIN_MONEY,
    ITEMWIN_2x2,
    ITEMWIN_YESNO_LOW,
    ITEMWIN_YESNO_HIGH,
    ITEMWIN_MESSAGE,
    ITEMWIN_6,
    ITEMWIN_7,
    ITEMWIN_8,
    ITEMWIN_9,
    ITEMWIN_LIST,
    ITEMWIN_COUNT
};

// There is one for the TM Case and Berry Pouch in FRLG but those aren't being used
// TODO: These are also possibly different
enum {
    WIN_ITEM_LIST,
    WIN_DESCRIPTION,
    WIN_POCKET_NAME
};

#define ITEMMENU_SWAP_LINE_LENGTH 9  // Swap line is 9 sprites long

enum {
    ITEMMENUSPRITE_BAG,
    ITEMMENUSPRITE_SWAP_LINE,
    ITEMMENUSPRITE_ITEM = ITEMMENUSPRITE_SWAP_LINE + ITEMMENU_SWAP_LINE_LENGTH,
    ITEMMENUSPRITE_ITEM_ALT, // Need two when selecting new item
    ITEMMENUSPRITE_COUNT
};

struct BagPosition
{
    void (*exitCallback)(void);
    u8 location;
    bool8 bagOpen;
    u8 pocket;
    u16 cursorPosition[POCKETS_COUNT];
    u16 scrollPosition[POCKETS_COUNT];
};

extern struct BagPosition gBagPosition;

struct BagMenu
{
    void (*newScreenCallback)(void);
    u8 tilemapBuffer[BG_SCREEN_SIZE];
    u8 windowIds[ITEMWIN_COUNT];
    u8 toSwapPos;
    u8 pocketSwitchDisabled:4;
    u8 itemIconSlot:2;
    u8 inhibitItemDescriptionPrint:2;
    u16 contextMenuSelectedItem;
    u8 pocketScrollArrowsTask;
    u8 pocketSwitchArrowsTask;
    const u8* contextMenuItemsPtr;
    u8 contextMenuItemsBuffer[4];
    u8 contextMenuNumItems;
    u8 numItemStacks[POCKETS_COUNT];
    u8 numShownItems[POCKETS_COUNT];
    s16 graphicsLoadState;
};

extern struct BagMenu *gBagMenu;
extern u16 gSpecialVar_ItemId;

void CB2_GoToItemDepositMenu(void);
void FavorLadyOpenBagMenu(void);
void QuizLadyOpenBagMenu(void);
void ApprenticeOpenBagMenu(void);
void CB2_BagMenuFromBattle(void);
void PocketCalculateInitialCursorPosAndItemsAbove(u8 pocketId);
void UpdatePocketListPosition(u8 pocketId);
void CB2_ReturnToBagMenuPocket(void);
void CB2_BagMenuFromStartMenu(void);
void Bag_BeginCloseWin0Animation(void);
u8 GetItemListPosition(u8 pocketId);
bool8 UseRegisteredKeyItemOnField(void);
void CB2_GoToSellMenu(void);
void GoToBagMenu(u8 bagMenuType, u8 pocketId, void ( *exitCallback)());
void DoWallyTutorialBagMenu(void);
void ResetBagCursorPositions(void);
void ChooseBerryForMachine(void (*exitCallback)(void));
void CB2_ChooseBerry(void);
void Task_FadeAndCloseBagMenu(u8 taskId);
void UpdatePocketItemList(u8 pocketId);
void DisplayItemMessage(u8 taskId, u8 fontId, const u8 *str, void ( *callback)(u8 taskId));
void DisplayItemMessageOnField(u8 taskId, const u8 *src, TaskFunc callback);
void CloseItemMessage(u8 taskId);

// bag.c functions
void LoadBagMenuTextWindows(void);
void BagMenu_Print(u8 windowId, u8 fontId, const u8 *str, u8 left, u8 top, u8 letterSpacing, u8 lineSpacing, u8 speed, u8 colorIndex);
/*void BagDrawDepositItemTextBox(void);*/
u8 BagMenu_AddWindow(u8 windowType, u8 nItems);
void BagMenu_RemoveWindow(u8 windowType);
u8 OpenBagWindow(u8 windowType);
void RemoveItemMessageWindow(u8 windowType);
u8 BagMenu_GetWindowId(u8 windowType);
void BagMenu_YesNo(u8 taskId, const struct YesNoFuncTable * ptrs);
void BagMenu_YesNoTopRight(u8 taskId, const struct YesNoFuncTable * ptrs);
void DisplayCurrentMoneyWindow(void);
void BagDrawTextBoxOnWindow(u8 windowId);

#endif //GUARD_ITEM_MENU_H

