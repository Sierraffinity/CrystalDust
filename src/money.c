#include "global.h"
#include "money.h"
#include "graphics.h"
#include "event_data.h"
#include "string_util.h"
#include "text.h"
#include "menu.h"
#include "window.h"
#include "sprite.h"
#include "strings.h"
#include "text_window.h"
#include "decompress.h"

EWRAM_DATA static u8 sMoneyBoxWindowId = 0;

u32 GetMoney(u32* moneyPtr)
{
    return *moneyPtr ^ gSaveBlock2Ptr->encryptionKey;
}

void SetMoney(u32* moneyPtr, u32 newValue)
{
    *moneyPtr = gSaveBlock2Ptr->encryptionKey ^ newValue;
}

bool8 IsEnoughMoney(u32* moneyPtr, u32 cost)
{
    if (GetMoney(moneyPtr) >= cost)
        return TRUE;
    else
        return FALSE;
}

u32 AddMoney(u32* moneyPtr, u32 toAdd)
{
    u32 remainder = 0;
    u32 toSet = GetMoney(moneyPtr) + toAdd;

    // can't have more money than MAX
    // check overflow, can't have less money after you receive more
    if ((toSet > MAX_MONEY) || (toSet < GetMoney(moneyPtr)))
    {
        remainder = toSet - MAX_MONEY;
        toSet = MAX_MONEY;
    }

    SetMoney(moneyPtr, toSet);

    return remainder;
}

void RemoveMoney(u32* moneyPtr, u32 toSub)
{
    u32 toSet = GetMoney(moneyPtr);

    // can't subtract more than you already have
    if (toSet < toSub)
        toSet = 0;
    else
        toSet -= toSub;

    SetMoney(moneyPtr, toSet);
}

bool8 IsEnoughForCostInVar0x8005(void)
{
    return IsEnoughMoney(&gSaveBlock1Ptr->money, gSpecialVar_0x8005);
}

void SubtractMoneyFromVar0x8005(void)
{
    RemoveMoney(&gSaveBlock1Ptr->money, gSpecialVar_0x8005);
}

void PrintMoneyAmountInMoneyBox(u8 windowId, int amount, u8 speed)
{
    u8 *txtPtr;
    s32 strLength;

    ConvertIntToDecimalStringN(gStringVar1, amount, STR_CONV_MODE_LEFT_ALIGN, 6);

    strLength = 6 - StringLength(gStringVar1);
    txtPtr = gStringVar4;

    while (strLength-- != 0)
        *(txtPtr++) = 0;

    StringExpandPlaceholders(txtPtr, gText_PokedollarVar1);
    AddTextPrinterParameterized(windowId, 0, gStringVar4, 64 - GetStringWidth(0, gStringVar4, 0), 0xC, speed, NULL);
}

void PrintMoneyAmount(u8 windowId, u8 x, u8 y, int amount, u8 speed)
{
    u8 *txtPtr;
    s32 strLength;

    ConvertIntToDecimalStringN(gStringVar1, amount, STR_CONV_MODE_LEFT_ALIGN, 6);

    strLength = 6 - StringLength(gStringVar1);
    txtPtr = gStringVar4;

    while (strLength-- > 0)
        *(txtPtr++) = 0;

    StringExpandPlaceholders(txtPtr, gText_PokedollarVar1);
    AddTextPrinterParameterized(windowId, 0, gStringVar4, x, y, speed, NULL);
}

void PrintMoneyAmountInMoneyBoxWithBorder(u8 windowId, u16 tileStart, u8 palette, int amount)
{
    DrawStdFrameWithCustomTileAndPalette(windowId, FALSE, tileStart, palette);
    AddTextPrinterParameterized(windowId, 2, gText_TrainerCardMoney, 0, 0, 0xFF, 0);
    PrintMoneyAmountInMoneyBox(windowId, amount, 0);
}

void ChangeAmountInMoneyBox(int amount)
{
    PrintMoneyAmountInMoneyBox(sMoneyBoxWindowId, amount, 0);
}

void DrawMoneyBox(int amount, u8 x, u8 y)
{
    struct WindowTemplate template;

    SetWindowTemplateFields(&template, 0, x + 1, y + 1, 8, 3, 15, 8);
    sMoneyBoxWindowId = AddWindow(&template);
    FillWindowPixelBuffer(sMoneyBoxWindowId, PIXEL_FILL(0));
    PutWindowTilemap(sMoneyBoxWindowId);
    //CopyWindowToVram(sMoneyBoxWindowId, 3);
    LoadThinWindowBorderGfx(sMoneyBoxWindowId, 0x21D, 0xD0);
    PrintMoneyAmountInMoneyBoxWithBorder(sMoneyBoxWindowId, 0x21D, 13, amount);
}

void HideMoneyBox(void)
{
    ClearStdWindowAndFrameToTransparent(sMoneyBoxWindowId, TRUE);
    RemoveWindow(sMoneyBoxWindowId);
}
