#include "global.h"
#include "decoration.h"
#include "event_scripts.h"
#include "field_screen_effect.h"
#include "field_weather.h"
#include "international_string_util.h"
#include "item.h"
#include "item_menu.h"
#include "item_pc.h"
#include "mail.h"
#include "menu.h"
#include "menu_specialized.h"
#include "overworld.h"
#include "palette.h"
#include "party_menu.h"
#include "player_pc.h"
#include "script.h"
#include "sound.h"
#include "strings.h"
#include "string_util.h"
#include "task.h"
//#include "gflib.h"
//#include "menu_indicators.h"
//#include "new_menu_helpers.h"
//#include "mail_data.h"
//#include "help_system.h"
//#include "mailbox_pc.h"
//#include "field_fadetransition.h"
#include "constants/items.h"
#include "constants/songs.h"
#include "constants/field_weather.h"

#define tCount          data[2]
#define tPageItems      data[4]
#define tItemPcParam    data[6]
#define tWindowId       data[10]
#define tListMenuTaskId data[11]

static EWRAM_DATA const u8 *sItemOrder = NULL;
static EWRAM_DATA u8 sTopMenuItemCount = 0;
EWRAM_DATA struct PlayerPCItemPageStruct gPlayerPCItemPageInfo = {};

#define SELECTED_MAIL (gSaveBlock1Ptr->mail[PC_MAIL_NUM(gPlayerPCItemPageInfo.itemsAbove) + gPlayerPCItemPageInfo.cursorPos])

static void Task_DrawPlayerPcTopMenu(u8 taskId);
static void Task_TopMenuHandleInput(u8 taskId);
static void Task_PlayerPcItemStorage(u8 taskId);
static void Task_PlayerPcMailbox(u8 taskId);
static void Task_PlayerPcDecoration(u8 taskId);
static void Task_PlayerPcTurnOff(u8 taskId);
static void Task_CreateItemStorageSubmenu(u8 taskId, u8 cursorPos);
static void PrintStringOnWindow0WithDialogueFrame(const u8 *str);
static void Task_TopMenu_ItemStorageSubmenu_HandleInput(u8 taskId);
static void Task_PlayerPcDepositItem(u8 taskId);
static void Task_DepositItem_WaitFadeAndGoToBag(u8 taskId);
static void CB2_ReturnFromDepositMenu(void);
static void Task_PlayerPcWithdrawItem(u8 taskId);
static void CB2_ReturnFromWithdrawMenu(void);
static void Task_WithdrawItemBeginFade(u8 taskId);
static void Task_PlayerPcCancel(u8 taskId);
static void Task_SetPageItemVars(u8 taskId);
static u8 CountPCMail(void);
static void PCMailCompaction(void);
static void Task_DrawMailboxPcMenu(u8 taskId);
static void Task_MailboxPcHandleInput(u8 taskId);
static void Task_PrintWhatToDoWithSelectedMail(u8 taskId);
static void Task_DestroyMailboxPcViewAndCancel(u8 taskId);
static void Task_DrawMailSubmenu(u8 taskId);
static void Task_MailSubmenuHandleInput(u8 taskId);
static void Task_PlayerPcReadMail(u8 taskId);
static void Task_WaitFadeAndReadSelectedMail(u8 taskId);
static void CB2_SetCbToReturnToMailbox(void);
static void Task_PlayerPcMoveMailToBag(u8 taskId);
static void Task_DrawYesNoMenuToConfirmMoveToBag(u8 taskId);
static void Task_MoveToBagYesNoMenuHandleInput(u8 taskId);
static void Task_TryPutMailInBag_DestroyMsgIfSuccessful(u8 taskId);
static void Task_DeclinedMoveMailToBag(u8 taskId);
static void Task_PlayerPcGiveMailToMon(u8 taskId);
static void Task_WaitFadeAndGoToPartyMenu(u8 taskId);
static void Task_Error_NoPokemon(u8 taskId);
static void Task_PlayerPcExitMailSubmenu(u8 taskId);

static const u8 *const sItemStorageActionDescriptionPtrs[] = {
    gText_TakeOutItemsFromPC,
    gText_StoreItemsInPC,
    gText_GoBackPrevMenu
};

static const struct MenuAction sMenuActions_TopMenu[] = {
    { gText_ItemStorage, Task_PlayerPcItemStorage },
    { gText_Mailbox, Task_PlayerPcMailbox },
    { gText_Decoration, Task_PlayerPcDecoration },
    { gText_TurnOff, Task_PlayerPcTurnOff }
};

static const u8 gBedroomPC_OptionOrder[] = {
    PLAYERPC_MENU_ITEMSTORAGE,
    PLAYERPC_MENU_MAILBOX,
    PLAYERPC_MENU_DECORATION,
    PLAYERPC_MENU_TURNOFF
};
static const u8 gPlayerPC_OptionOrder[] = {
    PLAYERPC_MENU_ITEMSTORAGE,
    PLAYERPC_MENU_MAILBOX,
    PLAYERPC_MENU_TURNOFF
};
#define NUM_PLAYER_PC_OPTIONS ARRAY_COUNT(sPlayerPC_OptionOrder)

static const struct MenuAction sMenuActions_ItemPc[] = {
    { gText_WithdrawItem, Task_PlayerPcWithdrawItem },
    { gText_DepositItem, Task_PlayerPcDepositItem },
    { gText_Cancel, Task_PlayerPcCancel }
};

const struct MenuAction gMenuActions_MailSubmenu[] = {
    { gText_Read, Task_PlayerPcReadMail },
    { gText_MoveToBag, Task_PlayerPcMoveMailToBag },
    { gText_Give2, Task_PlayerPcGiveMailToMon },
    { gText_Cancel2, Task_PlayerPcExitMailSubmenu }
};

static const struct WindowTemplate sWindowTemplate_TopMenu_3Items = {
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 1,
    .width = 13,
    .height = 6,
    .paletteNum = 15,
    .baseBlock = 0x008
};

static const struct WindowTemplate sWindowTemplate_TopMenu_4Items = {
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 1,
    .width = 13,
    .height = 8,
    .paletteNum = 15,
    .baseBlock = 0x008
};

static const struct WindowTemplate sWindowTemplate_ItemStorageSubmenu = {
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 1,
    .width = 14,
    .height = 6,
    .paletteNum = 15,
    .baseBlock = 0x008
};

void NewGameInitPCItems(void)
{
    ClearItemSlots(gSaveBlock1Ptr->pcItems, ARRAY_COUNT(gSaveBlock1Ptr->pcItems));
}
#undef GET_QUANTITY

void BedroomPC(void)
{
    u8 taskId;

    sItemOrder = gBedroomPC_OptionOrder;
    sTopMenuItemCount = ARRAY_COUNT(gBedroomPC_OptionOrder);
    taskId = CreateTask(TaskDummy, 0);
    DisplayItemMessageOnField(taskId, gText_WhatWouldYouLike, Task_DrawPlayerPcTopMenu);
}

void PlayerPC(void)
{
    u8 taskId;

    sItemOrder = gPlayerPC_OptionOrder;
    sTopMenuItemCount = ARRAY_COUNT(gPlayerPC_OptionOrder);
    taskId = CreateTask(TaskDummy, 0);
    DisplayItemMessageOnField(taskId, gText_WhatWouldYouLike, Task_DrawPlayerPcTopMenu);
}

static void Task_DrawPlayerPcTopMenu(u8 taskId)
{
    struct WindowTemplate windowTemplate;
    s16 *data = gTasks[taskId].data;

    if (sTopMenuItemCount == 3)
        windowTemplate = sWindowTemplate_TopMenu_3Items;
    else
        windowTemplate = sWindowTemplate_TopMenu_4Items;
    windowTemplate.width = sub_81DB3D8(sMenuActions_TopMenu, sItemOrder, sTopMenuItemCount);
    tWindowId = AddWindow(&windowTemplate);
    SetStandardWindowBorderStyle(tWindowId, 0);
    AddItemMenuActionTextPrinters(tWindowId, 2, GetMenuCursorDimensionByFont(2, 0), 2, GetFontAttribute(2, FONTATTR_LETTER_SPACING), 16, sTopMenuItemCount, sMenuActions_TopMenu, sItemOrder);
    InitMenuInUpperLeftCornerPlaySoundWhenAPressed(tWindowId, 2, 0, 2, 16, sTopMenuItemCount, 0);
    ScheduleBgCopyTilemapToVram(0);
    gTasks[taskId].func = Task_TopMenuHandleInput;
}

static void Task_TopMenuHandleInput(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    s8 input = Menu_ProcessInputNoWrap();
    switch (input)
    {
    case MENU_NOTHING_CHOSEN:
        break;
    case MENU_B_PRESSED:
        PlaySE(SE_SELECT);
        ClearStdWindowAndFrameToTransparent(tWindowId, FALSE);
        ClearWindowTilemap(tWindowId);
        RemoveWindow(tWindowId);
        ScheduleBgCopyTilemapToVram(0);
        gTasks[taskId].func = Task_PlayerPcTurnOff;
        break;
    default:
        ClearStdWindowAndFrameToTransparent(tWindowId, FALSE);
        ClearWindowTilemap(tWindowId);
        RemoveWindow(tWindowId);
        ScheduleBgCopyTilemapToVram(0);
        gTasks[taskId].func = sMenuActions_TopMenu[sItemOrder[input]].func.void_u8;
        break;
    }
}

void ReshowPlayerPC(u8 taskId)
{
    DisplayItemMessageOnField(taskId, gText_WhatWouldYouLike, Task_DrawPlayerPcTopMenu);
}

static void Task_PlayerPcItemStorage(u8 taskId)
{
    Task_CreateItemStorageSubmenu(taskId, FALSE);
    gTasks[taskId].func = Task_TopMenu_ItemStorageSubmenu_HandleInput;
}

static void Task_PlayerPcMailbox(u8 taskId)
{
    gPlayerPCItemPageInfo.count = CountPCMail();
    if (gPlayerPCItemPageInfo.count == 0)
    {
        DisplayItemMessageOnField(taskId, gText_NoMailHere, ReshowPlayerPC);
    }
    else
    {
        gPlayerPCItemPageInfo.cursorPos = 0;
        gPlayerPCItemPageInfo.itemsAbove = 0;
        PCMailCompaction();
        Task_SetPageItemVars(taskId);
        if (MailboxMenu_Alloc(gPlayerPCItemPageInfo.count) == TRUE)
        {
            ClearDialogWindowAndFrame(0, FALSE);
            Task_DrawMailboxPcMenu(taskId);
            gTasks[taskId].func = Task_MailboxPcHandleInput;
        }
        else
        {
            DisplayItemMessageOnField(taskId, gText_NoMailHere, ReshowPlayerPC);
        }
    }
}

static void Task_PlayerPcDecoration(u8 taskId)
{
    DoPlayerRoomDecorationMenu(taskId);
}

static void Task_PlayerPcTurnOff(u8 taskId)
{
    if (sTopMenuItemCount == ARRAY_COUNT(gBedroomPC_OptionOrder))
        ScriptContext1_SetupScript(NewBarkTown_PlayersHouse_2F_EventScript_TurnOffPlayerPC);
    else
        EnableBothScriptContexts();
    DestroyTask(taskId);
}

static void Task_CreateItemStorageSubmenu(u8 taskId, u8 cursorPos)
{
    s16 *data = gTasks[taskId].data;
    tWindowId = AddWindow(&sWindowTemplate_ItemStorageSubmenu);
    SetStandardWindowBorderStyle(tWindowId, FALSE);
    PrintTextArray(tWindowId, 2, GetMenuCursorDimensionByFont(2, 0), 2, 16, 3, sMenuActions_ItemPc);
    InitMenuInUpperLeftCornerPlaySoundWhenAPressed(tWindowId, 2, 0, 2, 16, 3, cursorPos);
    ScheduleBgCopyTilemapToVram(0);
    PrintStringOnWindow0WithDialogueFrame(sItemStorageActionDescriptionPtrs[cursorPos]);
}

static void PrintStringOnWindow0WithDialogueFrame(const u8 *str)
{
    DrawDialogueFrame(0, FALSE);
    AddTextPrinterParameterized(0, 2, str, 0, 1, 0, NULL);
}

static void Task_TopMenu_ItemStorageSubmenu_HandleInput(u8 taskId)
{
    if (JOY_REPEAT(DPAD_UP))
    {
        if (Menu_GetCursorPos() != 0)
        {
            PlaySE(SE_SELECT);
            Menu_MoveCursor(MENU_B_PRESSED);
            PrintStringOnWindow0WithDialogueFrame(sItemStorageActionDescriptionPtrs[Menu_GetCursorPos()]);
        }
    }
    else if (JOY_REPEAT(DPAD_DOWN))
    {
        if (Menu_GetCursorPos() != 2)
        {
            PlaySE(SE_SELECT);
            Menu_MoveCursor(+1);
            PrintStringOnWindow0WithDialogueFrame(sItemStorageActionDescriptionPtrs[Menu_GetCursorPos()]);
        }
    }
    else if (JOY_NEW(A_BUTTON))
    {
        PlaySE(SE_SELECT);
        sMenuActions_ItemPc[Menu_GetCursorPos()].func.void_u8(taskId);
    }
    else if (JOY_NEW(B_BUTTON))
    {
        PlaySE(SE_SELECT);
        sMenuActions_ItemPc[2].func.void_u8(taskId);
    }
}

static void Task_DepositItem_WaitFadeAndGoToBag(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        CleanupOverworldWindowsAndTilemaps();
        CB2_GoToItemDepositMenu();
        DestroyTask(taskId);
    }
}

static void Task_PlayerPcDepositItem(u8 taskId)
{
    gTasks[taskId].func = Task_DepositItem_WaitFadeAndGoToBag;
    FadeScreen(FADE_TO_BLACK, 0);
}

static void Task_ReturnToItemStorageSubmenu(u8 taskId)
{
    if (IsWeatherNotFadingIn() == TRUE)
        gTasks[taskId].func = Task_TopMenu_ItemStorageSubmenu_HandleInput;
}

void CB2_PlayerPCExitBagMenu(void)
{
    gFieldCallback = CB2_ReturnFromDepositMenu;
    SetMainCallback2(CB2_ReturnToField);
}

static void CB2_ReturnFromDepositMenu(void)
{
    u8 taskId;
    LoadMessageBoxAndBorderGfx();
    DrawDialogueFrame(0, TRUE);
    taskId = CreateTask(Task_ReturnToItemStorageSubmenu, 0);
    Task_CreateItemStorageSubmenu(taskId, 1);
    FadeInFromBlack();
}

static void Task_PlayerPcWithdrawItem(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    tCount = CountUsedPCItemSlots();
    if (tCount != 0)
    {
        tItemPcParam = 0;
        gTasks[taskId].func = Task_WithdrawItemBeginFade;
        gFieldCallback = CB2_ReturnFromWithdrawMenu;
    }
    else
    {
        ClearStdWindowAndFrameToTransparent(tWindowId, FALSE);
        ClearWindowTilemap(tWindowId);
        RemoveWindow(tWindowId);
        DisplayItemMessageOnField(taskId, gText_NoItems, Task_PlayerPcItemStorage);
    }
}

static void CB2_ReturnFromWithdrawMenu(void)
{
    u8 taskId;
    LoadMessageBoxAndBorderGfx();
    DrawDialogueFrame(0, TRUE);
    taskId = CreateTask(Task_ReturnToItemStorageSubmenu, 0);
    Task_CreateItemStorageSubmenu(taskId, 0);
    FadeInFromBlack();
}

static void Task_WithdrawItem_WaitFadeAndGoToItemStorage(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    if (!gPaletteFade.active)
    {
        CleanupOverworldWindowsAndTilemaps();
        ItemPc_Init(tItemPcParam, CB2_ReturnToField);
        DestroyTask(taskId);
    }
}

static void Task_WithdrawItemBeginFade(u8 taskId)
{
    gTasks[taskId].func = Task_WithdrawItem_WaitFadeAndGoToItemStorage;
    ItemPc_SetInitializedFlag(FALSE);
    FadeScreen(FADE_TO_BLACK, 0);
}

static void Task_PlayerPcCancel(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    ClearStdWindowAndFrameToTransparent(tWindowId, FALSE);
    ClearWindowTilemap(tWindowId);
    CopyWindowToVram(tWindowId, COPYWIN_MAP);
    RemoveWindow(tWindowId);
    ReshowPlayerPC(taskId);
}

static void Task_SetPageItemVars(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    if (tCount >= 8)
        tPageItems = 8;
    else
        tPageItems = tCount + 1;
    if (gPlayerPCItemPageInfo.count >= 8)
        gPlayerPCItemPageInfo.pageItems = 8;
    else
        gPlayerPCItemPageInfo.pageItems = gPlayerPCItemPageInfo.count + 1;
}

static u8 CountPCMail(void)
{
    u8 count = 0;
    u8 i;

    for (i = PC_MAIL_NUM(0); i < MAIL_COUNT; i++)
    {
        if (gSaveBlock1Ptr->mail[i].itemId != ITEM_NONE)
            count++;
    }
    return count;
}

static void PCMailCompaction(void)
{
    u8 i;
    u8 j;
    for (i = PC_MAIL_NUM(0); i < MAIL_COUNT - 1; i++)
    {
        for (j = i + 1; j < MAIL_COUNT; j++)
        {
            if (gSaveBlock1Ptr->mail[i].itemId == ITEM_NONE)
            {
                struct MailStruct mail = gSaveBlock1Ptr->mail[i];
                gSaveBlock1Ptr->mail[i] = gSaveBlock1Ptr->mail[j];
                gSaveBlock1Ptr->mail[j] = mail;
            }
        }
    }
}

static void Task_DrawMailboxPcMenu(u8 taskId)
{
    u8 windowId = MailboxMenu_AddWindow(0);
    s32 width = GetStringWidth(2, gText_Mailbox, 0);
    MailboxMenu_AddWindow(1);
    AddTextPrinterParameterized(windowId, 2, gText_Mailbox, (80 - width) / 2, 2, 0, NULL);
    ScheduleBgCopyTilemapToVram(0);
    gTasks[taskId].tListMenuTaskId = MailboxMenu_CreateList(&gPlayerPCItemPageInfo);
    MailboxMenu_AddScrollArrows(&gPlayerPCItemPageInfo);
}

static void Task_MailboxPcHandleInput(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    s32 input;
    if (!gPaletteFade.active)
    {
        input = ListMenu_ProcessInput(tListMenuTaskId);
        ListMenuGetScrollAndRow(tListMenuTaskId, &gPlayerPCItemPageInfo.itemsAbove, &gPlayerPCItemPageInfo.cursorPos);
        switch (input)
        {
        case MENU_B_PRESSED:
            break;
        case MENU_NOTHING_CHOSEN:
            PlaySE(SE_SELECT);
            RemoveScrollIndicatorArrowPair(gPlayerPCItemPageInfo.scrollIndicatorTaskId);
            Task_DestroyMailboxPcViewAndCancel(taskId);
            break;
        default:
            PlaySE(SE_SELECT);
            MailboxMenu_RemoveWindow(0);
            MailboxMenu_RemoveWindow(1);
            DestroyListMenuTask(tListMenuTaskId, &gPlayerPCItemPageInfo.itemsAbove, &gPlayerPCItemPageInfo.cursorPos);
            ScheduleBgCopyTilemapToVram(0);
            RemoveScrollIndicatorArrowPair(gPlayerPCItemPageInfo.scrollIndicatorTaskId);
            gTasks[taskId].func = Task_PrintWhatToDoWithSelectedMail;
            break;
        }
    }
}

static void Task_PrintWhatToDoWithSelectedMail(u8 taskId)
{
    s32 length;
    s32 i;
    u8 *ptr;
    StringCopy(gStringVar1, SELECTED_MAIL.playerName);
    length = StringLength(gStringVar1);
    if (length > 5)
    {
        for (ptr = gStringVar1 + length - 1; ptr >= gStringVar1; ptr--)
        {
            if (*ptr)
                break;
            *ptr = EOS;
        }
    }
    else
    {
        ConvertInternationalString(gStringVar1, LANGUAGE_JAPANESE);
    }
    StringExpandPlaceholders(gStringVar4, gText_WhatToDoWithVar1sMail);
    DisplayItemMessageOnField(taskId, gStringVar4, Task_DrawMailSubmenu);
}

static void Task_DestroyMailboxPcViewAndCancel(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    MailboxMenu_RemoveWindow(0);
    MailboxMenu_RemoveWindow(1);
    DestroyListMenuTask(tListMenuTaskId, NULL, NULL);
    ScheduleBgCopyTilemapToVram(0);
    MailboxMenu_Free();
    ReshowPlayerPC(taskId);
}

static void Task_DrawMailSubmenu(u8 taskId)
{
    u8 windowId = MailboxMenu_AddWindow(2);
    PrintTextArray(windowId, 2, GetMenuCursorDimensionByFont(2, 0), 2, 16, 4, gMenuActions_MailSubmenu);
    InitMenuInUpperLeftCornerPlaySoundWhenAPressed(windowId, 2, 0, 2, 16, 4, 0);
    ScheduleBgCopyTilemapToVram(0);
    gTasks[taskId].func = Task_MailSubmenuHandleInput;
}

static void Task_MailSubmenuHandleInput(u8 taskId)
{
    s8 input = ProcessMenuInput_other();
    switch (input)
    {
    case MENU_B_PRESSED:
        PlaySE(SE_SELECT);
        Task_PlayerPcExitMailSubmenu(taskId);
        break;
    case MENU_NOTHING_CHOSEN:
        break;
    default:
        PlaySE(SE_SELECT);
        gMenuActions_MailSubmenu[input].func.void_u8(taskId);
        break;
    }
}

static void Task_PlayerPcReadMail(u8 taskId)
{
    FadeScreen(FADE_TO_BLACK, 0);
    gTasks[taskId].func = Task_WaitFadeAndReadSelectedMail;
}

static void Task_WaitFadeAndReadSelectedMail(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        MailboxMenu_Free();
        CleanupOverworldWindowsAndTilemaps();
        ReadMail(&SELECTED_MAIL, CB2_SetCbToReturnToMailbox, 1);
        DestroyTask(taskId);
    }
}

static void Task_WaitFadeAndReturnToMailboxPcInputHandler(u8 taskId)
{
    if (IsWeatherNotFadingIn() == TRUE)
        gTasks[taskId].func = Task_MailboxPcHandleInput;
}

static void CB2_ReturnToMailbox(void)
{
    u8 taskId;
    LoadMessageBoxAndBorderGfx();
    taskId = CreateTask(Task_WaitFadeAndReturnToMailboxPcInputHandler, 0);
    if (MailboxMenu_Alloc(gPlayerPCItemPageInfo.count) == TRUE)
        Task_DrawMailboxPcMenu(taskId);
    else
        DestroyTask(taskId);
    FadeInFromBlack();
}

static void CB2_SetCbToReturnToMailbox(void)
{
    gFieldCallback = CB2_ReturnToMailbox;
    SetMainCallback2(CB2_ReturnToField);
}

static void Task_PlayerPcMoveMailToBag(u8 taskId)
{
    DisplayItemMessageOnField(taskId, gText_MessageWillBeLost, Task_DrawYesNoMenuToConfirmMoveToBag);
}

static void Task_DrawYesNoMenuToConfirmMoveToBag(u8 taskId)
{
    DisplayYesNoMenuDefaultYes();
    gTasks[taskId].func = Task_MoveToBagYesNoMenuHandleInput;
}

static void Task_MoveToBagYesNoMenuHandleInput(u8 taskId)
{
    switch (Menu_ProcessInputNoWrapClearOnChoose())
    {
    case MENU_NOTHING_CHOSEN:
        break;
    case 0:
        Task_TryPutMailInBag_DestroyMsgIfSuccessful(taskId);
        break;
    case MENU_B_PRESSED:
        PlaySE(SE_SELECT);
        // fallthrough
    case 1:
        Task_DeclinedMoveMailToBag(taskId);
        break;
    }
}

static void Task_TryPutMailInBag_DestroyMsgIfSuccessful(u8 taskId)
{
    struct MailStruct * mail = &SELECTED_MAIL;
    if (!AddBagItem(mail->itemId, 1))
    {
        DisplayItemMessageOnField(taskId, gText_BagIsFull, Task_PlayerPcExitMailSubmenu);
    }
    else
    {
        DisplayItemMessageOnField(taskId, gText_MailToBagMessageErased, Task_PlayerPcExitMailSubmenu);
        ClearMailStruct(mail);
        PCMailCompaction();
        gPlayerPCItemPageInfo.count--;
        if (gPlayerPCItemPageInfo.count < gPlayerPCItemPageInfo.pageItems + gPlayerPCItemPageInfo.itemsAbove)
        {
            if (gPlayerPCItemPageInfo.itemsAbove != 0)
                gPlayerPCItemPageInfo.itemsAbove--;
        }
        Task_SetPageItemVars(taskId);
    }
}

static void Task_DeclinedMoveMailToBag(u8 taskId)
{
    Task_PlayerPcExitMailSubmenu(taskId);
}

static void Task_PlayerPcGiveMailToMon(u8 taskId)
{
    if (CalculatePlayerPartyCount() == 0)
    {
        Task_Error_NoPokemon(taskId);
    }
    else
    {
        FadeScreen(FADE_TO_BLACK, 0);
        gTasks[taskId].func = Task_WaitFadeAndGoToPartyMenu;
    }
}

static void Task_WaitFadeAndGoToPartyMenu(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        MailboxMenu_Free();
        CleanupOverworldWindowsAndTilemaps();
        ChooseMonToGiveMailFromMailbox();
        DestroyTask(taskId);
    }
}

static void CB2_ReturnToMailboxPc_UpdateScrollVariables(void)
{
    u8 taskId;
    u8 count;
    taskId = CreateTask(Task_WaitFadeAndReturnToMailboxPcInputHandler, 0);
    count = gPlayerPCItemPageInfo.count;
    gPlayerPCItemPageInfo.count = CountPCMail();
    PCMailCompaction();
    if (count != gPlayerPCItemPageInfo.count)
    {
        if (gPlayerPCItemPageInfo.count < gPlayerPCItemPageInfo.pageItems + gPlayerPCItemPageInfo.itemsAbove)
        {
            if (gPlayerPCItemPageInfo.itemsAbove != 0)
                gPlayerPCItemPageInfo.itemsAbove--;
        }
    }
    Task_SetPageItemVars(taskId);
    LoadMessageBoxAndBorderGfx();
    if (MailboxMenu_Alloc(gPlayerPCItemPageInfo.count) == TRUE)
        Task_DrawMailboxPcMenu(taskId);
    else
        DestroyTask(taskId);
    FadeInFromBlack();
}

void Mailbox_ReturnToMailListAfterDeposit(void)
{
    gFieldCallback = CB2_ReturnToMailboxPc_UpdateScrollVariables;
    SetMainCallback2(CB2_ReturnToField);
}

static void Task_Error_NoPokemon(u8 taskId)
{
    DisplayItemMessageOnField(taskId, gText_NoPokemon, Task_PlayerPcExitMailSubmenu);
}

static void Task_RedrawPlayerPcMailboxAndSetUpInputHandler(u8 taskId)
{
    ClearDialogWindowAndFrame(0, FALSE);
    Task_DrawMailboxPcMenu(taskId);
    ScheduleBgCopyTilemapToVram(0);
    gTasks[taskId].func = Task_MailboxPcHandleInput;
}

static void Task_PlayerPcExitMailSubmenu(u8 taskId)
{
    MailboxMenu_RemoveWindow(2);
    ScheduleBgCopyTilemapToVram(0);
    gTasks[taskId].func = Task_RedrawPlayerPcMailboxAndSetUpInputHandler;
}

#undef tListMenuTaskId
#undef tWindowId
#undef tItemPcParam
#undef tPageItems
#undef tCount
