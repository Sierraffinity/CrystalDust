#include "global.h"
#include "alloc.h"
#include "bg.h"
#include "card_flip.h"
#include "coins.h"
#include "decompress.h"
#include "gpu_regs.h"
#include "main.h"
#include "main_menu.h"
#include "menu.h"
#include "menu_helpers.h"
#include "overworld.h"
#include "palette.h"
#include "scanline_effect.h"
#include "script.h"
#include "sprite.h"
#include "string_util.h"
#include "task.h"
#include "text.h"
#include "text_window.h"
#include "window.h"
#include "constants/rgb.h"

#define CARD_FLIP_BG_TEXT 0
#define CARD_FLIP_BG_BASE 2
#define WIN_TEXT 0
#define TAG_COIN_DIGIT 500

enum
{
    CARD_FLIP_STATE_INIT,
    CARD_FLIP_STATE_PLAY_PROMPT,
    CARD_FLIP_STATE_PLAY_PROMPT_GET_INPUT,
    CARD_FLIP_STATE_PLAY_SHUFFLE_CARDS,

    CARD_FLIP_STATE_START_EXIT,
    CARD_FLIP_STATE_EXIT,
};

struct CardFlip
{
    u8 state;
    u8 coinDigitSpriteIds[4];
    MainCallback returnMainCallback;
};

static void FadeToCardFlipScreen(u8 taskId);
static void InitCardFlipScreen(void);
static void CardFlipMainCallback(void);
static void CardFlipVBlankCallback(void);
static void InitCoinDigitSprites(void);
static void CardFlipMain(u8 taskId);
static void InitCardFlipTable(u8 taskId);
static void DisplayInitialPlayPrompt(u8 taskId);
static void ProcessPlayPromptInput(u8 taskId);
static void ChangeCoinAmount(int delta);
static void ChangeCoinAmountFixedDuration(int delta, int duration);
static void UpdateCoinDigitSprites(u8 taskId);
static void StartExitCardFlip();
static void ExitCardFlip();

static EWRAM_DATA struct CardFlip *sCardFlip = NULL;

static const u8 sPlayTheGamePromptText[] = _("Play CARD FLIP for 3 COINS?");

const u32 sCardFlipBaseBgGfx[] = INCBIN_U32("graphics/card_flip/card_flip_base_bg_tiles.4bpp.lz");
const u16 sCardFlipBaseBgPalette[] = INCBIN_U16("graphics/card_flip/card_flip_base_bg_tiles.gbapal");
const u32 sCardFlipBaseBgTilemap[] = INCBIN_U32("graphics/card_flip/card_flip_base_bg_tilemap.bin.lz");
const u32 sCoinDigitsGfx[] = INCBIN_U32("graphics/card_flip/coin_digits.4bpp.lz");
const u16 sCoinDigitsPalette[] = INCBIN_U16("graphics/card_flip/coin_digits.gbapal");

static const struct WindowTemplate sCardFlipWinTemplates[] =
{
    {
        .bg = CARD_FLIP_BG_TEXT,
        .tilemapLeft = 2,
        .tilemapTop = 15,
        .width = 26,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 0x14,
    },
    DUMMY_WIN_TEMPLATE,
};

static const struct BgTemplate sCardFlipBgTemplates[] =
{
    {
       .bg = CARD_FLIP_BG_TEXT,
       .charBaseIndex = 2,
       .mapBaseIndex = 31,
       .screenSize = 0,
       .paletteMode = 0,
       .priority = 0,
       .baseTile = 0
   },
   {
       .bg = CARD_FLIP_BG_BASE,
       .charBaseIndex = 0,
       .mapBaseIndex = 30,
       .screenSize = 0,
       .paletteMode = 0,
       .priority = 2,
       .baseTile = 0
   }
};

static const struct SpritePalette sCoinFlipSpritePalettes[] =
{
    {sCoinDigitsPalette, TAG_COIN_DIGIT},
    {0},
};

static const struct CompressedSpriteSheet sCoinDigitsSpriteSheet =
{
    .data = sCoinDigitsGfx,
    .size = 0x280,
    .tag = TAG_COIN_DIGIT,
};

static const struct OamData sCoinDigitOamData =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = 0,
    .bpp = ST_OAM_4BPP,
    .shape = ST_OAM_V_RECTANGLE,
    .x = 0,
    .matrixNum = 0,
    .size = 0,
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0,
};

#define COIN_DIGIT_ANIMCMD(n) \
static const union AnimCmd sCoinDigitAnimCmd_##n[] =\
{\
    ANIMCMD_FRAME((n) * 2, 0),\
    ANIMCMD_END,\
};

COIN_DIGIT_ANIMCMD(0)
COIN_DIGIT_ANIMCMD(1)
COIN_DIGIT_ANIMCMD(2)
COIN_DIGIT_ANIMCMD(3)
COIN_DIGIT_ANIMCMD(4)
COIN_DIGIT_ANIMCMD(5)
COIN_DIGIT_ANIMCMD(6)
COIN_DIGIT_ANIMCMD(7)
COIN_DIGIT_ANIMCMD(8)
COIN_DIGIT_ANIMCMD(9)

const union AnimCmd *const sCoinDigitAnimCmds[] =
{
    sCoinDigitAnimCmd_0,
    sCoinDigitAnimCmd_1,
    sCoinDigitAnimCmd_2,
    sCoinDigitAnimCmd_3,
    sCoinDigitAnimCmd_4,
    sCoinDigitAnimCmd_5,
    sCoinDigitAnimCmd_6,
    sCoinDigitAnimCmd_7,
    sCoinDigitAnimCmd_8,
    sCoinDigitAnimCmd_9,
};

static const struct SpriteTemplate sCoinDigitSpriteTemplate =
{
    .tileTag = TAG_COIN_DIGIT,
    .paletteTag = TAG_COIN_DIGIT,
    .oam = &sCoinDigitOamData,
    .anims = sCoinDigitAnimCmds,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

void PlayCardFlip(void)
{
    u8 taskId;

    ScriptContext1_Stop();
    sCardFlip = AllocZeroed(sizeof(*sCardFlip));
    sCardFlip->returnMainCallback = CB2_ReturnToFieldContinueScriptPlayMapMusic;
    taskId = CreateTask(FadeToCardFlipScreen, 0);
}

static void FadeToCardFlipScreen(u8 taskId)
{
    switch (gTasks[taskId].data[0])
    {
    case 0:
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
        gTasks[taskId].data[0]++;
        break;
    case 1:
        if (!gPaletteFade.active)
        {
            SetMainCallback2(InitCardFlipScreen);
            DestroyTask(taskId);
        }
        break;
    }
}

static void InitCardFlipScreen(void)
{
    switch (gMain.state)
    {
    case 0:
        SetVBlankCallback(NULL);
        ResetAllBgsCoordinates();
        gMain.state++;
        break;
    case 1:
        ResetVramOamAndBgCntRegs();
        ResetBgsAndClearDma3BusyFlags(0);
        InitBgsFromTemplates(0, sCardFlipBgTemplates, ARRAY_COUNT(sCardFlipBgTemplates));
        SetBgTilemapBuffer(CARD_FLIP_BG_BASE, AllocZeroed(BG_SCREEN_SIZE));
        DecompressAndLoadBgGfxUsingHeap(CARD_FLIP_BG_BASE, sCardFlipBaseBgGfx, 0x22E0, 0, 0);
        CopyToBgTilemapBuffer(CARD_FLIP_BG_BASE, sCardFlipBaseBgTilemap, 0, 0);
        ResetPaletteFade();
        LoadPalette(sCardFlipBaseBgPalette, 0, sizeof(sCardFlipBaseBgPalette));
        InitWindows(sCardFlipWinTemplates);
        DeactivateAllTextPrinters();
        LoadMessageBoxGfx(0, 0x200, 0xF0);
        LoadUserWindowBorderGfx(0, 0x214, 0xE0);
        PutWindowTilemap(0);
        gMain.state++;
        break;
    case 2:
        ResetSpriteData();
        FreeAllSpritePalettes();
        gMain.state++;
        break;
    case 3:
        CopyBgTilemapBufferToVram(CARD_FLIP_BG_BASE);
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 | DISPCNT_OBJ_1D_MAP | DISPCNT_OBJ_ON);
        ShowBg(CARD_FLIP_BG_TEXT);
        ShowBg(CARD_FLIP_BG_BASE);
        gMain.state++;
        break;
    case 4:
        LoadCompressedSpriteSheet(&sCoinDigitsSpriteSheet);
        LoadSpritePalettes(sCoinFlipSpritePalettes);
        InitCoinDigitSprites();
        gMain.state++;
    case 5:
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, RGB_BLACK);
        SetVBlankCallback(CardFlipVBlankCallback);
        SetMainCallback2(CardFlipMainCallback);
        CreateTask(CardFlipMain, 0);
        return;
    }
}

static void CardFlipMainCallback(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

static void CardFlipVBlankCallback(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void CardFlipMain(u8 taskId)
{
    switch (sCardFlip->state)
    {
    case CARD_FLIP_STATE_INIT:
        InitCardFlipTable(taskId);
        break;
    case CARD_FLIP_STATE_PLAY_PROMPT:
        if (!gPaletteFade.active)
            DisplayInitialPlayPrompt(taskId);
        break;
    case CARD_FLIP_STATE_PLAY_PROMPT_GET_INPUT:
        ProcessPlayPromptInput(taskId);
        break;
    case CARD_FLIP_STATE_PLAY_SHUFFLE_CARDS:

        break;
    case CARD_FLIP_STATE_START_EXIT:
        StartExitCardFlip(taskId);
        break;
    case CARD_FLIP_STATE_EXIT:
        ExitCardFlip();
        break;
    }
}

static void InitCardFlipTable(u8 taskId)
{
    InitCoinDigitSprites();
    sCardFlip->state = CARD_FLIP_STATE_PLAY_PROMPT;
}

static void DisplayInitialPlayPrompt(u8 taskId)
{
    NewMenuHelpers_DrawDialogueFrame(WIN_TEXT, 0);
    AddTextPrinterParameterized(WIN_TEXT, 1, sPlayTheGamePromptText, 0, 1, 0, NULL);
    CopyWindowToVram(WIN_TEXT, 3);
    CreateYesNoMenuParameterized(21, 7, 0x214, 0x180, 0xE, 0xF);
    sCardFlip->state = CARD_FLIP_STATE_PLAY_PROMPT_GET_INPUT;
}

static void ProcessPlayPromptInput(u8 taskId)
{
    int selection = Menu_ProcessInputNoWrapClearOnChoose();
    if (selection == 0)
    {
        sub_8197434(0, TRUE);
        sCardFlip->state = CARD_FLIP_STATE_PLAY_SHUFFLE_CARDS;
    }
    else if (selection == 1 || selection == MENU_B_PRESSED)
    {
        sub_8197434(0, TRUE);
        sCardFlip->state = CARD_FLIP_STATE_START_EXIT;
    }
}

static void InitCoinDigitSprites(void)
{
    int i;
    int x, y, digit;
    int numCoins;

    numCoins = GetCoins();
    for (i = 0; i < 4; i++)
    {
        digit = numCoins % 10;
        numCoins /= 10;
        x = 61 - i * 7;
        y = 9;
        sCardFlip->coinDigitSpriteIds[i] = CreateSprite(&sCoinDigitSpriteTemplate, x, y, 3);
        StartSpriteAnim(&gSprites[sCardFlip->coinDigitSpriteIds[i]], digit);
    }
}

static void ChangeCoinAmount(int delta)
{
    ChangeCoinAmountFixedDuration(delta, 0);
}

static void ChangeCoinAmountFixedDuration(int delta, int duration)
{
    u8 taskId;
    int curCoins, targetCoins;

    if (delta == 0)
        return;

    curCoins = GetCoins();
    if (curCoins + delta < 0)
        delta = -curCoins;
    else if (curCoins + delta > 9999)
        delta = 9999 - curCoins;

    taskId = CreateTask(UpdateCoinDigitSprites, 3);
    gTasks[taskId].data[0] = curCoins;

    if (delta > 0)
        GiveCoins(delta);
    else
        TakeCoins(-delta);
    
    targetCoins = GetCoins();
    gTasks[taskId].data[1] = targetCoins;
    if (duration <= 0)
        gTasks[taskId].data[2] = 1;
    else
        gTasks[taskId].data[2] = max(1, abs((targetCoins - curCoins) / duration));
}

static void UpdateCoinDigitSprites(u8 taskId)
{
    int i;
    int coins;
    int currentCoins = gTasks[taskId].data[0];
    int targetCoins = gTasks[taskId].data[1];
    int delta = gTasks[taskId].data[2];

    if (currentCoins < targetCoins)
    {
        currentCoins += delta;
        if (currentCoins > targetCoins)
            currentCoins = targetCoins;
    }
    else
    {
        currentCoins -= delta;
        if (currentCoins < targetCoins)
            currentCoins = targetCoins;
    }

    coins = currentCoins;
    for (i = 0; i < 4; i++)
    {
        int digit = coins % 10;
        coins /= 10;
        StartSpriteAnim(&gSprites[sCardFlip->coinDigitSpriteIds[i]], digit);
    }

    if (currentCoins == targetCoins)
    {
        DestroyTask(taskId);
    }
    else
        gTasks[taskId].data[0] = currentCoins;
}

static void StartExitCardFlip()
{
    BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
    sCardFlip->state = CARD_FLIP_STATE_EXIT;
}

static void ExitCardFlip()
{
    if (!gPaletteFade.active)
    {
        SetMainCallback2(sCardFlip->returnMainCallback);
        FREE_AND_SET_NULL(sCardFlip);
    }
}

#undef CARD_FLIP_BG_BASE
#undef WIN_BASE
#undef TAG_COIN_DIGIT
