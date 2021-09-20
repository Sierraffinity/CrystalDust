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
#include "text_window.h"
#include "trig.h"
#include "util.h"
#include "constants/items.h"
#include "constants/songs.h"
#include "constants/vars.h"

// static functions
static void InitMomBankMenu(u8 taskId);
static void MomBank_PrintMainWindow(u8 windowId, u32 depositedMoney, u32 heldMoney);
static void MomBank_PrintTransactionQuantity(u8 windowId, u32 amount, bool32 isDeposit);
static void MomBank_Print(u8 windowId, u32 depositedMoney, u32 heldMoney);
static void MomBank_CreateCursor(u8 taskId);
static void MomBank_ProcessInput(u8 taskId);
static void MomBank_Exit(u8 taskId);
static void MomBank_AcceptTransaction(u8 taskId);
static void MomBank_RemoveWindows(u8 taskId);
static void SpriteCB_DigitSelectorCursor(struct Sprite *sprite);

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
        .tilemapLeft = 17,
        .tilemapTop = 10,
        .width = 12,
        .height = 3,
        .paletteNum = 15,
        .baseBlock = 0x004C
    }
};

static const struct OamData sOamData_Arrow =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = 0,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(8x8),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(8x8),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0,
};

static const u8 sArrowGfx[] = INCBIN_U8("graphics/misc/mom_bank_digit_selector_arrow.4bpp");
static const u16 sArrowPal[] = INCBIN_U16("graphics/misc/mom_bank_digit_selector_arrow.gbapal");

static const struct SpriteFrameImage sSpriteImageTable_Arrow[] =
{
    obj_frame_tiles(sArrowGfx)
};

static const struct SpritePalette sSpritePalette_Arrow =
{
    sArrowPal, 0x1000
};

static const union AnimCmd sSpriteAnim_ArrowDown[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sSpriteAnim_ArrowUp[] =
{
    ANIMCMD_FRAME(0, 30, .vFlip = TRUE),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd *const sSpriteAnimTable_Arrow[] =
{
    sSpriteAnim_ArrowDown,
    sSpriteAnim_ArrowUp
};

static const struct SpriteTemplate sSpriteTemplate_85104F0 =
{
    .tileTag = SPRITE_INVALID_TAG,
    .paletteTag = 0x1000,
    .oam = &sOamData_Arrow,
    .anims = sSpriteAnimTable_Arrow,
    .images = sSpriteImageTable_Arrow,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_DigitSelectorCursor,
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

#define tIsDeposit data[0]
#define tMainWindowId data[1]
#define tValueWindowId data[2]
#define tArrowPos data[3]
#define tMoneyLo data[4]
#define tMoneyHi data[5]

#define tMoney (*((u32 *)&tMoneyLo))

#define spTaskId data[0]
#define spCurPos data[1]
#define spMultiplier data[2]
#define spFrequency data[3]
#define spSinePos data[4]

static void InitMomBankMenu(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    gSpecialVar_Result = 0xFF;
    tIsDeposit = !!VarGet(gSpecialVar_0x8004);
    tMoney = 0;
    tArrowPos = 0;

    tMainWindowId = AddWindow(&sMomBankWindows[0]);
    tValueWindowId = AddWindow(&sMomBankWindows[1]);
    LoadThinWindowBorderGfx(tMainWindowId, 0x21D, 0xD0);
    DrawStdFrameWithCustomTileAndPalette(tMainWindowId, FALSE, 0x21D, 13);
    DrawStdFrameWithCustomTileAndPalette(tValueWindowId, FALSE, STD_WINDOW_BASE_TILE_NUM, STD_WINDOW_PALETTE_NUM);
    ScheduleBgCopyTilemapToVram(0);

    MomBank_PrintMainWindow(tMainWindowId, GetMoney(&gSaveBlock1Ptr->bankedMoney), GetMoney(&gSaveBlock1Ptr->money));
    MomBank_PrintTransactionQuantity(tValueWindowId, ConvertBcdToBinary(tMoney), tIsDeposit);
    MomBank_CreateCursor(taskId);

    gTasks[taskId].func = MomBank_ProcessInput;
}

static void MomBank_PrintMainWindow(u8 windowId, u32 depositedMoney, u32 heldMoney)
{
    FillWindowPixelBuffer(windowId, PIXEL_FILL(1));
    PrintMoneyAmount(windowId, 58, 12, depositedMoney, 0);
    PrintMoneyAmount(windowId, 58, 36, heldMoney, 0);
    AddTextPrinterParameterized5(windowId, 2, gText_DepositedMoney, 0, 1, 0, NULL, 0, 2);
    AddTextPrinterParameterized5(windowId, 2, gText_HeldMoney, 0, 25, 0, NULL, 0, 2);
}

void MomBank_PrintMoneyAmountLeadingZeroes(u8 windowId, u8 x, u8 y, u32 amount, u8 speed)
{
    ConvertIntToDecimalStringN(gStringVar1, amount, STR_CONV_MODE_LEADING_ZEROS, 6);
    StringExpandPlaceholders(gStringVar4, gText_PokedollarVar1);
    AddTextPrinterParameterized(windowId, 2, gStringVar4, x, y, speed, NULL);
}

static void MomBank_PrintTransactionQuantity(u8 windowId, u32 amount, bool32 isDeposit)
{
    u8 colors[] = {0, 2, 3};
    FillWindowPixelBuffer(windowId, PIXEL_FILL(1));

    if (isDeposit)
    {
        AddTextPrinterParameterized5(windowId, 0, gText_Deposit, 0, 5, 0, NULL, 0, 2);
    }
    else
    {
        AddTextPrinterParameterized5(windowId, 0, gText_Withdraw, 0, 5, 0, NULL, 0, 2);
    }

    MomBank_PrintMoneyAmountLeadingZeroes(windowId, 52, 5, amount, 0);
    CopyWindowToVram(windowId, 3);
}

static void SpriteCB_DigitSelectorCursor(struct Sprite *sprite)
{
    int state = gTasks[sprite->spTaskId].tArrowPos;

    sprite->y2 = (gSineTable[(u8)(sprite->spSinePos)] * sprite->spMultiplier) / 256;
    sprite->spSinePos += sprite->spFrequency;

    if (state != sprite->spCurPos)
    {
        sprite->spCurPos = state;
        if (state < 6)
        {
            sprite->x = 229 - (state * 6);
        }
        else
        {
            DestroySprite(sprite);
        }
    }
}

static void MomBank_CreateCursor(u8 taskId)
{
    u32 spriteId;

    LoadSpritePalette(&sSpritePalette_Arrow);

    spriteId = CreateSpriteAtEnd(&sSpriteTemplate_85104F0, 101, 81, 0);
    gSprites[spriteId].callback = SpriteCB_DigitSelectorCursor;
    StartSpriteAnim(&gSprites[spriteId], 1);
    gSprites[spriteId].spTaskId = taskId;
    gSprites[spriteId].spCurPos = -1;
    gSprites[spriteId].spMultiplier = 2;
    gSprites[spriteId].spFrequency = -8;

    spriteId = CreateSpriteAtEnd(&sSpriteTemplate_85104F0, 101, 102, 0);
    gSprites[spriteId].callback = SpriteCB_DigitSelectorCursor;
    StartSpriteAnim(&gSprites[spriteId], 0);
    gSprites[spriteId].spTaskId = taskId;
    gSprites[spriteId].spCurPos = -1;
    gSprites[spriteId].spMultiplier = 2;
    gSprites[spriteId].spFrequency = 8;
}

static void MomBank_DestroyCursor(u8 taskId)
{
    gTasks[taskId].tArrowPos = 6;
    FreeSpritePaletteByTag(sSpritePalette_Arrow.tag);
}

static void MomBank_ProcessInput(u8 taskId)
{
    u32 money;
    s16 *data = gTasks[taskId].data;

    if (JOY_NEW(DPAD_RIGHT) && (tArrowPos > 0))
    {
        PlaySE(SE_SELECT);
        tArrowPos--;
    }
    else if (JOY_NEW(DPAD_LEFT) && (tArrowPos < 5))
    {
        PlaySE(SE_SELECT);
        tArrowPos++;
    }
    else if (JOY_NEW(DPAD_UP))
    {
        PlaySE(SE_SELECT);
        tMoney = ChangeBcdDigit(tMoney, tArrowPos, 1);
        MomBank_PrintTransactionQuantity(tValueWindowId, ConvertBcdToBinary(tMoney), tIsDeposit);
    }
    else if (JOY_NEW(DPAD_DOWN))
    {
        PlaySE(SE_SELECT);
        tMoney = ChangeBcdDigit(tMoney, tArrowPos, -1);
        MomBank_PrintTransactionQuantity(tValueWindowId, ConvertBcdToBinary(tMoney), tIsDeposit);
    }
    else if (JOY_NEW(A_BUTTON))
    {
        PlaySE(SE_SELECT);
        gTasks[taskId].func = MomBank_AcceptTransaction;
    }
    else if (JOY_NEW(B_BUTTON))
    {
        PlaySE(SE_SELECT);
        tMoney = 0;
        gTasks[taskId].func = MomBank_AcceptTransaction;
    }
}

static void MomBank_RemoveWindows(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    ClearStdWindowAndFrameToTransparent(tMainWindowId, FALSE);
    ClearStdWindowAndFrameToTransparent(tValueWindowId, FALSE);
    RemoveWindow(tMainWindowId);
    RemoveWindow(tValueWindowId);
    ScheduleBgCopyTilemapToVram(0);
}

static void MomBank_AcceptTransaction(u8 taskId)
{
    u32 money;
    s16 *data = gTasks[taskId].data;

    money = ConvertBcdToBinary(tMoney);

    if (money > 0)
    {
        if (tIsDeposit)
        {
            if (GetMoney(&gSaveBlock1Ptr->money) >= money)
            {
                if (GetMoney(&gSaveBlock1Ptr->bankedMoney) < (MAX_MONEY - money))
                {
                    // deposit success
                    RemoveMoney(&gSaveBlock1Ptr->money, money);
                    AddMoney(&gSaveBlock1Ptr->bankedMoney, money);
                    gSpecialVar_Result = 0;
                }
                else
                {
                    // too much in bank
                    gSpecialVar_Result = 2;
                }
            }
            else
            {
                // not enough in wallet
                gSpecialVar_Result = 1;
            }
        }
        else
        {
            if (GetMoney(&gSaveBlock1Ptr->bankedMoney) >= money)
            {
                if (GetMoney(&gSaveBlock1Ptr->money) < (MAX_MONEY - money))
                {
                    // withdraw success
                    RemoveMoney(&gSaveBlock1Ptr->bankedMoney, money);
                    AddMoney(&gSaveBlock1Ptr->money, money);
                    gSpecialVar_Result = 0;
                }
                else
                {
                    // too much in wallet
                    gSpecialVar_Result = 2;
                }
            }
            else
            {
                // not enough in bank
                gSpecialVar_Result = 1;
            }
        }
    }

    MomBank_DestroyCursor(taskId);
    MomBank_RemoveWindows(taskId);

    // Run exit/destroy on next frame, so cursor callbacks have time to run and self-destruct
    gTasks[taskId].func = MomBank_Exit;
}

static void MomBank_Exit(u8 taskId)
{
    EnableBothScriptContexts();
    DestroyTask(taskId);
}

#undef tIsDeposit
#undef tMainWindowId
#undef tValueWindowId
#undef tArrowPos
#undef tMoneyLo
#undef tMoneyHi

#undef tMoney

#undef spTaskId
#undef spCurPos
#undef spMultiplier
#undef spFrequency
#undef spSinePos
