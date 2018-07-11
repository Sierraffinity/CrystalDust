#include "global.h"
#include "main.h"
#include "pokegear.h"
#include "bg.h"
#include "day_night.h"
#include "event_data.h"
#include "gpu_regs.h"
#include "international_string_util.h"
#include "malloc.h"
#include "menu.h"
#include "overworld.h"
#include "palette.h"
#include "rtc.h"
#include "scanline_effect.h"
#include "sound.h"
#include "strings.h"
#include "text.h"
#include "text_window.h"
#include "window.h"
#include "constants/flags.h"
#include "constants/songs.h"

#define MENU_FRAME_BASE_TILE_NUM 532
#define MENU_FRAME_PALETTE_NUM 13

// Static RAM declarations

enum CardType {
    ClockCard,
    MapCard,
    PhoneCard,
    RadioCard,
    CardCount
};

static EWRAM_DATA struct {
    MainCallback callback;
    u8 currentCard;
    bool8 scrollEnabled;
    bool8 twentyFourHourMode;
} *sPokegearStruct = NULL;

// Static ROM declarations

static void CB2_InitPokegear(void);
static void VBlankCB(void);
static void CB2_Pokegear(void);
static void Task_Pokegear1(u8 taskId);
static void Task_Pokegear2(u8 taskId);
static void Task_ExitPokegear1(u8 taskId);
static void Task_ExitPokegear2(u8 taskId);
static void Task_ClockCard(u8 taskId);
static void LoadClockCard(void);
static void LoadMapCard(void);
static void LoadPhoneCard(void);
static void LoadRadioCard(void);
static void CB2_Pokegear(void);
static void LoadCard(enum CardType type);
static void SpriteCB_ClockDigits(struct Sprite* sprite);
static void UnloadClockCard(void);

// .rodata
static const u16 gBGPals[] = INCBIN_U16("graphics/pokegear/bg.gbapal");
static const u16 sMenuSpritesPalette[] = INCBIN_U16("graphics/pokegear/menu_sprites.gbapal");
static const u8 gMainTiles[] = INCBIN_U8("graphics/pokegear/main.4bpp.lz");
static const u8 sDigitTiles[] = INCBIN_U8("graphics/pokegear/digits.4bpp");
static const u8 gBackgroundTilemap[] = INCBIN_U8("graphics/pokegear/background.bin.lz");
static const u8 gClockCardTilemap[] = INCBIN_U8("graphics/pokegear/clock.bin.lz");
static const u8 gMapCardTilemap[] = INCBIN_U8("graphics/pokegear/map.bin.lz");
static const u8 gPhoneCardTilemap[] = INCBIN_U8("graphics/pokegear/phone.bin.lz");
static const u8 gRadioCardTilemap[] = INCBIN_U8("graphics/pokegear/radio.bin.lz");

static const struct BgTemplate sBgTemplates[] =
{
    {
        .bg = 0,
        .charBaseIndex = 2,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    },
    {
        .bg = 1,
        .charBaseIndex = 0,
        .mapBaseIndex = 30,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    },
    {
        .bg = 2,
        .charBaseIndex = 0,
        .mapBaseIndex = 29,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    },
    {
        .bg = 3,
        .charBaseIndex = 0,
        .mapBaseIndex = 28,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    },
};

static const struct WindowTemplate sClockCardWindowTemplates[] =
{
    { 0, 6, 15, 23, 4, 15, 0x0001 },
    { 0, 10, 2, 14, 3, 15, 0x0060 },
    { 0, 10, 11, 14, 3, 15, 0x0090 },
    DUMMY_WIN_TEMPLATE
};

static const struct WindowTemplate sPhoneCardWindowTemplates[] =
{
    { 0, 6, 15, 23, 4, 15, 0x0001 },
    DUMMY_WIN_TEMPLATE
};

static const struct SpriteSheet sSpriteSheet_DigitTiles =
{
    .data = sDigitTiles,
    .size = 2176,
    .tag = 12345,
};

static const struct SpritePalette sSpritePalette_MenuSprites =
{
    .data = sMenuSpritesPalette,
    .tag = 54321
};

static const union AnimCmd sSpriteAnim_Digit0[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_Digit1[] =
{
    ANIMCMD_FRAME(4, 5),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_Digit2[] =
{
    ANIMCMD_FRAME(8, 5),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_Digit3[] =
{
    ANIMCMD_FRAME(12, 5),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_Digit4[] =
{
    ANIMCMD_FRAME(16, 5),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_Digit5[] =
{
    ANIMCMD_FRAME(20, 5),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_Digit6[] =
{
    ANIMCMD_FRAME(24, 5),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_Digit7[] =
{
    ANIMCMD_FRAME(28, 5),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_Digit8[] =
{
    ANIMCMD_FRAME(32, 5),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_Digit9[] =
{
    ANIMCMD_FRAME(36, 5),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_DigitOff[] =
{
    ANIMCMD_FRAME(40, 5),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_ColonOff[] =
{
    ANIMCMD_FRAME(44, 5),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_ColonOn[] =
{
    ANIMCMD_FRAME(48, 5),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_AM[] =
{
    ANIMCMD_FRAME(52, 5),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_PM[] =
{
    ANIMCMD_FRAME(56, 5),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_AMPMOff[] =
{
    ANIMCMD_FRAME(60, 5),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_Point[] =
{
    ANIMCMD_FRAME(64, 5),
    ANIMCMD_END
};

static const union AnimCmd *const sSpriteAnimTable_Digits[] =
{
    sSpriteAnim_Digit0,
    sSpriteAnim_Digit1,
    sSpriteAnim_Digit2,
    sSpriteAnim_Digit3,
    sSpriteAnim_Digit4,
    sSpriteAnim_Digit5,
    sSpriteAnim_Digit6,
    sSpriteAnim_Digit7,
    sSpriteAnim_Digit8,
    sSpriteAnim_Digit9,
    sSpriteAnim_DigitOff,
    sSpriteAnim_ColonOff,
    sSpriteAnim_ColonOn,
    sSpriteAnim_AM,
    sSpriteAnim_PM,
    sSpriteAnim_AMPMOff,
    sSpriteAnim_Point,
};

static const struct OamData sOamData_Digits =
{
    .y = 0,
    .affineMode = 0,
    .objMode = 0,
    .mosaic = 0,
    .bpp = 0,
    .shape = 0,
    .x = 0,
    .matrixNum = 0,
    .size = 1,
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0,
};

const struct SpriteTemplate sSpriteTemplate_Digits = {
    .tileTag = 12345,
    .paletteTag = 54321,
    .oam = &sOamData_Digits,
    .anims = sSpriteAnimTable_Digits,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

// .text

void PrepareToStartPokegear(MainCallback callback)
{
    SetVBlankCallback(NULL);
    sPokegearStruct = AllocZeroed(sizeof(*sPokegearStruct));
    if (sPokegearStruct == NULL)
    {
        SetMainCallback2(callback);
    }
    else
    {
        //sPokegearStruct->callback = callback;
        SetMainCallback2(CB2_InitPokegear);
        gMain.savedCallback = callback;
    }
}

void PokegearScriptHarness(void)
{
	PrepareToStartPokegear(CB2_ReturnToFieldContinueScript);
}

const u8 sTextColor[3] = {
	0x00, 0x02, 0x03
};

static void CB2_InitPokegear(void)
{
    SetGpuReg(REG_OFFSET_DISPCNT, 0);
    SetGpuReg(REG_OFFSET_BG3CNT, 0);
    SetGpuReg(REG_OFFSET_BG2CNT, 0);
    SetGpuReg(REG_OFFSET_BG1CNT, 0);
    SetGpuReg(REG_OFFSET_BG0CNT, 0);
    SetGpuReg(REG_OFFSET_BG0HOFS, 0);
    SetGpuReg(REG_OFFSET_BG0VOFS, 0);
    SetGpuReg(REG_OFFSET_BG1HOFS, 0);
    SetGpuReg(REG_OFFSET_BG1VOFS, 0);
    SetGpuReg(REG_OFFSET_BG2HOFS, 0);
    SetGpuReg(REG_OFFSET_BG2VOFS, 0);
    SetGpuReg(REG_OFFSET_BG3HOFS, 0);
    SetGpuReg(REG_OFFSET_BG3VOFS, 0);
    DmaFillLarge16(3, 0, (void *)VRAM, VRAM_SIZE, 0x1000);
    DmaClear32(3, (void *)OAM, OAM_SIZE);
    DmaClear16(3, (void *)PLTT, PLTT_SIZE);
    LZ77UnCompVram(gMainTiles, (void *)(VRAM + 0x0000));
    LZ77UnCompVram(gBackgroundTilemap, (void *)(VRAM + 0xE000));
    LoadPalette(gBGPals, 0, sizeof(gBGPals));
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, sBgTemplates, ARRAY_COUNT(sBgTemplates));
    DeactivateAllTextPrinters();
    sub_809882C(0, MENU_FRAME_BASE_TILE_NUM, MENU_FRAME_PALETTE_NUM * 0x10);
    clear_scheduled_bg_copies_to_vram();
    ScanlineEffect_Stop();
    ResetTasks();
    ResetSpriteData();
    ResetPaletteFade();
    FreeAllSpritePalettes();
    CreateTask(Task_Pokegear1, 0);
    BeginNormalPaletteFade(0xFFFFFFFF, 0, 0x10, 0, 0);
    EnableInterrupts(INTR_FLAG_VBLANK);
    SetVBlankCallback(VBlankCB);
    SetMainCallback2(CB2_Pokegear);

    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    SetGpuReg(REG_OFFSET_BLDALPHA, 0);
    SetGpuReg(REG_OFFSET_BLDY, 0);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_1D_MAP | DISPCNT_OBJ_ON);

    ShowBg(0);
    ShowBg(1);
    ShowBg(2);
    ShowBg(3);

    LoadCard(ClockCard);
    PlaySE(SE_PN_ON);
}

static void VBlankCB(void)
{
    ProcessSpriteCopyRequests();
    LoadOam();
    TransferPlttBuffer();
}

static void CB2_Pokegear(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    do_scheduled_bg_tilemap_copies_to_vram();
    UpdatePaletteFade();
}

static void LoadCard(enum CardType cardId)
{
    switch (cardId)
    {
        case ClockCard:
            LoadClockCard();
            break;
        case MapCard:
            LoadMapCard();
            break;
        case PhoneCard:
            LoadPhoneCard();
            break;
        case RadioCard:
            LoadRadioCard();
            break;
    }

    sPokegearStruct->currentCard = cardId;
}

static void UnloadCard(enum CardType cardId)
{
    switch (cardId)
    {
        case ClockCard:
            UnloadClockCard();
            break;
        case MapCard:
            //UnloadMapCard();
            break;
        case PhoneCard:
            //UnloadPhoneCard();
            break;
        case RadioCard:
            //UnloadRadioCard();
            break;
    }

    sPokegearStruct->currentCard = cardId;
}

static void Task_Pokegear1(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        sPokegearStruct->scrollEnabled = TRUE;
        gTasks[taskId].func = Task_Pokegear2;
    }
}

// TEMP
#define FLAG_MAP_CARD FLAG_SYS_POKEMON_GET
#define FLAG_RADIO_CARD FLAG_SYS_POKEMON_GET

u8 ChangeCardWithDelta(s8 delta)
{
    int newCard = sPokegearStruct->currentCard + delta;

    while (TRUE)
    {
        if (newCard < 0 || newCard >= CardCount)
        {
            newCard = sPokegearStruct->currentCard;
            break;
        }
        
        if ((newCard == MapCard && !FlagGet(FLAG_MAP_CARD)) ||
            (newCard == RadioCard && !FlagGet(FLAG_RADIO_CARD)))
        {
            newCard += delta;
        }
        else
        {
            break;
        }
    }

    return newCard;
}

#define tNewCard data[0]

static void Task_Pokegear2(u8 taskId)
{
    if (sPokegearStruct->scrollEnabled)
    {
        u8 newCard = sPokegearStruct->currentCard;

        if (gMain.newKeys & B_BUTTON)
        {
            gTasks[taskId].func = Task_ExitPokegear1;
		    PlaySE(SE_PN_OFF);
            return;
        }
        else if (gMain.newKeys & DPAD_UP)
        {
            newCard = ChangeCardWithDelta(-1);
        }
        else if (gMain.newKeys & DPAD_DOWN)
        {
            newCard = ChangeCardWithDelta(1);
        }

        if (sPokegearStruct->currentCard != newCard)
        {
            PlaySE(SE_SELECT);
            UnloadCard(sPokegearStruct->currentCard);
            sPokegearStruct->currentCard = newCard;
            LoadCard(newCard);
        }
    }
}

static void Task_ExitPokegear1(u8 taskId)
{
    BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, 0);
    gTasks[taskId].func = Task_ExitPokegear2;
}

static void Task_ExitPokegear2(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        FreeAllWindowBuffers();
        SetMainCallback2(gMain.savedCallback);
    }
}

#define tDayOfWeek data[0]
#define tHourTens data[1]
#define tHourOnes data[2]
#define tColon data[3]
#define tMinuteTens data[4]
#define tMinuteOnes data[5]
#define tAMPM data[6]

#define tPosition data[0]
#define tStoredVal data[1]

#define WIN_DIALOG 0
#define WIN_TOP 1
#define WIN_BOTTOM 2

static void LoadClockCard(void)
{
    static const u8 clockX[6] = {
        108, 122, 130, 139, 153, 165
    };

    int i;
    u8 newTask, spriteId;
    const u8 *dayOfWeek = GetDayOfWeekString();

    LZ77UnCompVram(gClockCardTilemap, (void *)(VRAM + 0xF000));
    InitWindows(sClockCardWindowTemplates);
    SetWindowBorderStyle(WIN_DIALOG, FALSE, MENU_FRAME_BASE_TILE_NUM, MENU_FRAME_PALETTE_NUM);
    PutWindowTilemap(WIN_TOP);
    PutWindowTilemap(WIN_BOTTOM);
    PrintTextOnWindow(WIN_DIALOG, 1, gText_PokegearInstructions, 0, 1, 0, NULL);
    box_print(WIN_TOP, 1, GetStringCenterAlignXOffset(1, dayOfWeek, 0x70), 5, sTextColor, 0, dayOfWeek);
    box_print(WIN_BOTTOM, 1, GetStringCenterAlignXOffset(1, gText_PokegearSelectToChangeMode, 0x70), 5, sTextColor, 0, gText_PokegearSelectToChangeMode);
    schedule_bg_copy_tilemap_to_vram(0);
    
    LoadSpriteSheet(&sSpriteSheet_DigitTiles);
    LoadSpritePalette(&sSpritePalette_MenuSprites);

    newTask = CreateTask(Task_ClockCard, 0);
    gTasks[newTask].tDayOfWeek = gLocalTime.dayOfWeek;

    for (i = 0; i < 6; i++)
    {
        spriteId = CreateSprite(&sSpriteTemplate_Digits, clockX[i], 64, 0);
        gSprites[spriteId].tPosition = i;
        gSprites[spriteId].callback = SpriteCB_ClockDigits;
        gTasks[newTask].data[i + 1] = spriteId;
    }
}

void Task_ClockCard(u8 taskId)
{
    RtcCalcLocalTime();
    if (gMain.newKeys & SELECT_BUTTON)
    {
        PlaySE(SE_SELECT);
        sPokegearStruct->twentyFourHourMode = !sPokegearStruct->twentyFourHourMode;
        //FlagSet(FLAG_POKEGEAR_24HR);
    }

    if (gTasks[taskId].tDayOfWeek != gLocalTime.dayOfWeek)
    {
        const u8 *dayOfWeek = GetDayOfWeekString();
        gTasks[taskId].tDayOfWeek = gLocalTime.dayOfWeek;
        FillWindowPixelBuffer(WIN_TOP, 0);
        box_print(WIN_TOP, 1, GetStringCenterAlignXOffset(1, dayOfWeek, 0x70), 5, sTextColor, 0, dayOfWeek);
    }
}

static void SpriteCB_ClockDigits(struct Sprite* sprite)
{
    u8 value;

    switch (sprite->tPosition)
    {
        case 0:
            value = gLocalTime.hours;
            if (!sPokegearStruct->twentyFourHourMode)
            {
                if (value > 12)
                    value -= 12;
                else if (value == 0)
                    value = 12;
            }
            value = value / 10;
            if (value != 0)
                value += 1;
            break;
        case 1:
            value = gLocalTime.hours;
            if (!sPokegearStruct->twentyFourHourMode)
            {
                if (value > 12)
                    value -= 12;
                else if (value == 0)
                    value = 12;
            }
            value = value % 10 + 1;
            break;
        case 2:
            if (gLocalTime.seconds & 1)
                value = 11;
            else
                value = 12;
            break;
        case 3:
            value = gLocalTime.minutes / 10 + 1;
            break;
        case 4:
            value = gLocalTime.minutes % 10 + 1;
            break;
        case 5:
            if (sPokegearStruct->twentyFourHourMode)
                value = 13;
            else if (gLocalTime.hours < 12)
                value = 14;
            else
                value = 15;
            break;
        default:
            value = 0;
            break;
    }

    if (sprite->tStoredVal != value)
    {
        sprite->tStoredVal = value;
        StartSpriteAnim(sprite, value);
    }
}

static void UnloadClockCard(void)
{
    u8 taskId = FindTaskIdByFunc(Task_ClockCard);
    int i;

    sub_8198070(WIN_DIALOG, TRUE);
    CopyWindowToVram(WIN_DIALOG, 2);
    
    FillWindowPixelBuffer(WIN_TOP, 0);
    ClearWindowTilemap(WIN_TOP);
    CopyWindowToVram(WIN_TOP, 2);

    FillWindowPixelBuffer(WIN_BOTTOM, 0);
    ClearWindowTilemap(WIN_BOTTOM);
    CopyWindowToVram(WIN_BOTTOM, 2);

    for (i = 0; i < 6; i++)
    {
        DestroySpriteAndFreeResources(&gSprites[gTasks[taskId].data[i + 1]]);
    }

    DestroyTask(taskId);
}

#undef tDayOfWeek
#undef tHourTens
#undef tHourOnes
#undef tColon
#undef tMinuteTens
#undef tMinuteOnes
#undef tAMPM

#undef tPosition
#undef tStoredVal

void LoadMapCard(void)
{
    LZ77UnCompVram(gMapCardTilemap, (void *)(VRAM + 0xF000));
}

void LoadPhoneCard(void)
{
    /*int i;
    u8 newTask;
    const u8 *dayOfWeek = GetDayOfWeekString();*/

    LZ77UnCompVram(gPhoneCardTilemap, (void *)(VRAM + 0xF000));
    InitWindows(sPhoneCardWindowTemplates);
    SetWindowBorderStyle(WIN_DIALOG, FALSE, MENU_FRAME_BASE_TILE_NUM, MENU_FRAME_PALETTE_NUM);
    FillWindowPixelBuffer(WIN_DIALOG, 0x11);
    CopyWindowToVram(WIN_DIALOG, 2);
    /*PutWindowTilemap(WIN_TOP);
    PutWindowTilemap(WIN_BOTTOM);
    PrintTextOnWindow(WIN_DIALOG, 1, gText_PokegearInstructions, 0, 1, 0, NULL);
    box_print(WIN_TOP, 1, GetStringCenterAlignXOffset(1, dayOfWeek, 0x70), 5, sTextColor, 0, dayOfWeek);
    box_print(WIN_BOTTOM, 1, GetStringCenterAlignXOffset(1, gText_PokegearSelectToChangeMode, 0x70), 5, sTextColor, 0, gText_PokegearSelectToChangeMode);*/
    schedule_bg_copy_tilemap_to_vram(0);
    
    /*LoadSpriteSheet(&sSpriteSheet_DigitTiles);
    LoadSpritePalette(&sSpritePalette_MenuSprites);

    newTask = CreateTask(Task_ClockCard, 0);
    gTasks[newTask].tDayOfWeek = gLocalTime.dayOfWeek;

    for (i = 0; i < 6; i++)
    {
        gTasks[newTask].data[i + 1] = CreateSprite(&sSpriteTemplate_Digits, clockX[i], 64, 0);
        gSprites[gTasks[newTask].data[i + 1]].tPosition = i;
    }*/
}

#define tPosition data[0]

void LoadRadioCard(void)
{
    static const u8 radioX[6] = {
        114, 128, 142, 150, 159
    };

    int i;
    u8 spriteId;

    LZ77UnCompVram(gRadioCardTilemap, (void *)(VRAM + 0xF000));
    InitWindows(sClockCardWindowTemplates);
    NewMenuHelpers_DrawStdWindowFrame(WIN_DIALOG, TRUE);
    SetWindowBorderStyle(WIN_DIALOG, FALSE, MENU_FRAME_BASE_TILE_NUM, MENU_FRAME_PALETTE_NUM);
    FillWindowPixelBuffer(WIN_DIALOG, 0x11);
    CopyWindowToVram(WIN_DIALOG, 2);
    PutWindowTilemap(WIN_TOP);
    PutWindowTilemap(WIN_BOTTOM);
    //PrintTextOnWindow(WIN_DIALOG, 1, gText_PokegearInstructions, 0, 1, 0, NULL);
    box_print(WIN_TOP, 1, GetStringCenterAlignXOffset(1, gText_PokegearRadioTuning, 0x70), 5, sTextColor, 0, gText_PokegearRadioTuning);
    //box_print(WIN_BOTTOM, 1, GetStringCenterAlignXOffset(1, gText_PokegearSelectToChangeMode, 0x70), 5, sTextColor, 0, gText_PokegearSelectToChangeMode);
    schedule_bg_copy_tilemap_to_vram(0);

    LoadSpriteSheet(&sSpriteSheet_DigitTiles);
    LoadSpritePalette(&sSpritePalette_MenuSprites);

    for (i = 0; i < 5; i++)
    {
        spriteId = CreateSprite(&sSpriteTemplate_Digits, radioX[i], 64, 0);
        gSprites[spriteId].tPosition = i;
    }
}

#undef WIN_DIALOG
#undef WIN_TOP
#undef WIN_BOTTOM
