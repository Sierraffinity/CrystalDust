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
#include "money.h"
#include "script.h"
#include "sound.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "constants/items.h"
#include "constants/songs.h"
#include "constants/vars.h"

// static functions
static void InitMomBankMenu(u8 taskId);
static void MomBank_PrintMainWindow(u8 windowId, u32 depositedMoney, u32 heldMoney);
static void MomBank_Print(u8 windowId, u32 depositedMoney, u32 heldMoney);
static void MomBank_ProcessInput(u8 taskId);
static void MomBank_Exit(u8 taskId);

// const data
static const struct WindowTemplate sMomBankWindows[] =
{
    {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 1,
        .width = 12,
        .height = 6,
        .paletteNum = 15,
        .baseBlock = 0x0001
    },
    {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 10,
        .width = 12,
        .height = 3,
        .paletteNum = 15,
        .baseBlock = 0x004C
    }
};

#define MOM_BANK_WITHDRAW 0
#define MOM_BANK_DEPOSIT 1

void MomBank(void)
{
    if (VarGet(gSpecialVar_0x8004) == MOM_BANK_WITHDRAW)
    {
        DisplayItemMessageOnField(CreateTask(TaskDummy, 0), gText_HowMuchToTake, InitMomBankMenu);
    }
    else
    {
        DisplayItemMessageOnField(CreateTask(TaskDummy, 0), gText_HowMuchToSave, InitMomBankMenu);
    }
}

#define tMainWindowId data[0]
#define tValueWindowId data[1]
#define tMoneyLo data[2]
#define tMoneyHi data[3]

#define tMoney (*((u32 *)&tMoneyLo))

static void InitMomBankMenu(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    tMoney = 123456;

    tMainWindowId = AddWindow(&sMomBankWindows[0]);
    DrawStdFrameWithCustomTileAndPalette(tMainWindowId, FALSE, STD_WINDOW_BASE_TILE_NUM, STD_WINDOW_PALETTE_NUM);
    tValueWindowId = AddWindow(&sMomBankWindows[1]);
    DrawStdFrameWithCustomTileAndPalette(tValueWindowId, FALSE, STD_WINDOW_BASE_TILE_NUM, STD_WINDOW_PALETTE_NUM);
    schedule_bg_copy_tilemap_to_vram(0);

    MomBank_PrintMainWindow(tMainWindowId, GetMoney(&gSaveBlock1Ptr->bankedMoney), GetMoney(&gSaveBlock1Ptr->money));

    gTasks[taskId].func = MomBank_ProcessInput;
}

static void MomBank_PrintMainWindow(u8 windowId, u32 depositedMoney, u32 heldMoney)
{
    FillWindowPixelBuffer(windowId, PIXEL_FILL(1));
    PrintMoneyAmount(windowId, 58, 12, depositedMoney, 0);
    PrintMoneyAmount(windowId, 58, 36, heldMoney, 0);
    AddTextPrinterParameterized5(windowId, 1, gText_DepositedMoney, 0, 1, 0, NULL, 0, 2);
    AddTextPrinterParameterized5(windowId, 1, gText_HeldMoney, 0, 25, 0, NULL, 0, 2);
}

static void MomBank_PrintQuantity(int windowId, int amount)
{
    u8 colors[] = {0, 2, 3};
    FillWindowPixelBuffer(windowId, PIXEL_FILL(1));
    PrintMoneyAmount(windowId, 0, 0, amount, 0);
    CopyWindowToVram(windowId, 3);
}

static void MomBank_ProcessInput(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    //u16 totalInBag = sMomBank->apricorns[tApricornIdx].quantity;

    if (gMain.newKeys & DPAD_UP/*AdjustQuantityAccordingToDPadInput(&tItemCount, totalInBag) == TRUE*/)
    {
        MomBank_PrintQuantity(tValueWindowId, tMoney);
    }
    else if (gMain.newKeys & A_BUTTON)
    {
        /*PlaySE(SE_SELECT);
        RemoveWindowIfPresent(WIN_QUANTITY);
        MomBank_RemoveScrollIndicator();
        MomBank_InitConfirmGive(taskId);*/
        PlaySE(SE_SELECT);
        MomBank_Exit(taskId);
    }
    else if (gMain.newKeys & B_BUTTON)
    {
        PlaySE(SE_SELECT);
        /*RemoveWindowIfPresent(WIN_QUANTITY);
        MomBank_RemoveScrollIndicator();
        MomBank_ReturnToMain(taskId);*/
    }
}

static void MomBank_Exit(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    RemoveWindow(tMainWindowId);
    EnableBothScriptContexts();
    DestroyTask(taskId);
}
