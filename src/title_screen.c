#include "global.h"
#include "title_screen.h"
#include "sprite.h"
#include "gba/m4a_internal.h"
#include "clear_save_data_menu.h"
#include "decompress.h"
#include "event_data.h"
#include "intro.h"
#include "m4a.h"
#include "main.h"
#include "main_menu.h"
#include "palette.h"
#include "reset_rtc_screen.h"
#include "berry_fix_program.h"
#include "sound.h"
#include "sprite.h"
#include "task.h"
#include "scanline_effect.h"
#include "gpu_regs.h"
#include "trig.h"
#include "graphics.h"
#include "constants/rgb.h"
#include "constants/songs.h"

#define VERSION_BANNER_RIGHT_TILEOFFSET 64
#define VERSION_BANNER_BYTES 0x1000
#define VERSION_BANNER_LEFT_X 98
#define VERSION_BANNER_RIGHT_X 162
#define VERSION_BANNER_Y 2
#define VERSION_BANNER_Y_GOAL 66
#define START_BANNER_X 128

#define CLEAR_SAVE_BUTTON_COMBO (B_BUTTON | SELECT_BUTTON | DPAD_UP)
#define RESET_RTC_BUTTON_COMBO (B_BUTTON | SELECT_BUTTON | DPAD_LEFT)
#define BERRY_UPDATE_BUTTON_COMBO (B_BUTTON | SELECT_BUTTON)
#define A_B_START_SELECT (A_BUTTON | B_BUTTON | START_BUTTON | SELECT_BUTTON)

extern struct MusicPlayerInfo gMPlayInfo_BGM;
EWRAM_DATA vu8 sVBlank_DMA = 0;

extern const u32 gTitleScreenPressStartGfx[];
extern const u32 gTitleScreenPokemonLogoGfx[];
extern const u32 gTitleScreenPokemonLogoTilemap[];
extern const u32 sTitleScreenCloudsTilemap[];
extern const u16 gTitleScreenBgPalettes[];
extern const u16 gTitleScreenPressStartPal[];

// this file's functions
static void MainCB2(void);
static void Task_TitleScreenDoIntro(u8);
static void Task_TitleScreenProcessInput(u8);
static void CB2_GoToMainMenu(void);
static void CB2_GoToClearSaveDataScreen(void);
static void CB2_GoToResetRtcScreen(void);
static void CB2_GoToBerryFixScreen(void);
static void CB2_GoToCopyrightScreen(void);
static void UpdatePressStartColor(u8);

static void SpriteCB_PokemonLogoShine(struct Sprite *sprite);

// const rom data
static const u32 sTitleScreenRayquazaGfx[] = INCBIN_U32("graphics/title_screen/rayquaza.4bpp.lz");
static const u32 sTitleScreenRayquazaTilemap[] = INCBIN_U32("graphics/title_screen/rayquaza.bin.lz");
static const u32 sTitleScreenLogoShineGfx[] = INCBIN_U32("graphics/title_screen/logo_shine.4bpp.lz");
static const u32 sTitleScreenCloudsGfx[] = INCBIN_U32("graphics/title_screen/press_start.4bpp.lz");
static const u32 sTitleScreenEmblemGfx[] = INCBIN_U32("graphics/title_screen/emblem.4bpp.lz");
static const u32 sTitleScreenEmblemTilemap[] = INCBIN_U32("graphics/title_screen/emblem.bin.lz");
static const u32 sTitleScreenSuicuneGfx[] = INCBIN_U32("graphics/title_screen/suicune.4bpp.lz");
static const u16 sTitleScreenSuicunePal[] = INCBIN_U16("graphics/title_screen/suicune.gbapal");

static const struct OamData sOamData_Suicune =
{
    .y = 0,
    .affineMode = 0,
    .objMode = 0,
    .mosaic = 0,
    .bpp = 0,
    .shape = 0,
    .x = 0,
    .matrixNum = 0,
    .size = 3,
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0,
};

static const union AnimCmd sSuicuneAnim0[] =
{
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(64, 8),
    ANIMCMD_FRAME(128, 8),
    ANIMCMD_FRAME(192, 8),
    ANIMCMD_JUMP(0),
};
static const union AnimCmd *const sSuicuneAnimTable[] =
{
    sSuicuneAnim0,
};

static const struct SpriteTemplate sSuicuneSpriteTemplate =
{
    .tileTag = 1001,
    .paletteTag = 1001,
    .oam = &sOamData_Suicune,
    .anims = sSuicuneAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct CompressedSpriteSheet sSpriteSheet_Suicune[] =
{
    {sTitleScreenSuicuneGfx, 0x2000, 1001},
    {NULL},
};

static const struct SpritePalette sSpritePalette_Suicune[] =
{
    {sTitleScreenSuicunePal, 1001},
    {NULL},
};

static const struct OamData sPokemonLogoShineOamData =
{
    .y = 160,
    .affineMode = 0,
    .objMode = 0,
    .mosaic = 0,
    .bpp = 0,
    .shape = 0,
    .x = 0,
    .matrixNum = 0,
    .size = 3,
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0,
};

static const union AnimCmd sPokemonLogoShineAnimSequence[] =
{
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_END,
};

static const union AnimCmd *const sPokemonLogoShineAnimTable[] =
{
    sPokemonLogoShineAnimSequence,
};

static const struct SpriteTemplate sPokemonLogoShineSpriteTemplate =
{
    .tileTag = 1002,
    .paletteTag = 1001,
    .oam = &sPokemonLogoShineOamData,
    .anims = sPokemonLogoShineAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_PokemonLogoShine,
};

static const struct CompressedSpriteSheet sPokemonLogoShineSpriteSheet[] =
{
    {sTitleScreenLogoShineGfx, 0x800, 1002},
    {NULL},
};

// code
static void SpriteCB_PokemonLogoShine(struct Sprite *sprite)
{
    if (sprite->pos1.x < 272)
    {
        if (sprite->data[0]) // Flash background
        {
            u16 backgroundColor;

            if (sprite->pos1.x < DISPLAY_WIDTH / 2)
            {
                // Brighten background color
                if (sprite->data[1] < 31)
                    sprite->data[1]++;
                if (sprite->data[1] < 31)
                    sprite->data[1]++;
            }
            else
            {
                // Darken background color
                if (sprite->data[1] != 0)
                    sprite->data[1]--;
                if (sprite->data[1] != 0)
                    sprite->data[1]--;
            }

            backgroundColor = _RGB(sprite->data[1], sprite->data[1], sprite->data[1]);
            if (sprite->pos1.x == DISPLAY_WIDTH / 2 + 12
                || sprite->pos1.x == DISPLAY_WIDTH / 2 + 16
                || sprite->pos1.x == DISPLAY_WIDTH / 2 + 20
                || sprite->pos1.x == DISPLAY_WIDTH / 2 + 24)
                gPlttBufferFaded[0] = RGB(24, 31, 12);
            else
                gPlttBufferFaded[0] = backgroundColor;
        }
        sprite->pos1.x += 4;
    }
    else
    {
        gPlttBufferFaded[0] = RGB_BLACK;
        DestroySprite(sprite);
    }
}

static void SpriteCB_PokemonLogoShine2(struct Sprite *sprite)
{
    if (sprite->pos1.x < 272)
        sprite->pos1.x += 8;
    else
        DestroySprite(sprite);
}

static void StartPokemonLogoShine(u8 flashBg)
{
    u8 spriteId;

    switch (flashBg)
    {
    case 0:
    case 2:
        spriteId = CreateSprite(&sPokemonLogoShineSpriteTemplate, 0, 68, 0);
        gSprites[spriteId].oam.objMode = 2;
        gSprites[spriteId].data[0] = flashBg;
        break;
    case 1:
        spriteId = CreateSprite(&sPokemonLogoShineSpriteTemplate, 0, 68, 0);
        gSprites[spriteId].oam.objMode = 2;
        gSprites[spriteId].data[0] = flashBg;
        gSprites[spriteId].invisible = TRUE;

        spriteId = CreateSprite(&sPokemonLogoShineSpriteTemplate, 0, 68, 0);
        gSprites[spriteId].callback = SpriteCB_PokemonLogoShine2;
        gSprites[spriteId].oam.objMode = 2;

        spriteId = CreateSprite(&sPokemonLogoShineSpriteTemplate, -80, 68, 0);
        gSprites[spriteId].callback = SpriteCB_PokemonLogoShine2;
        gSprites[spriteId].oam.objMode = 2;
        break;
    }
}

static void VBlankCB(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

void CB2_InitTitleScreen(void)
{
    switch (gMain.state)
    {
    default:
    case 0:
        SetVBlankCallback(NULL);
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        SetGpuReg(REG_OFFSET_BLDY, 0);
        *((u16 *)PLTT) = RGB_WHITE;
        SetGpuReg(REG_OFFSET_DISPCNT, 0);
        SetGpuReg(REG_OFFSET_BG2CNT, 0);
        SetGpuReg(REG_OFFSET_BG1CNT, 0);
        SetGpuReg(REG_OFFSET_BG0CNT, 0);
        SetGpuReg(REG_OFFSET_BG2HOFS, 0);
        SetGpuReg(REG_OFFSET_BG2VOFS, 0);
        SetGpuReg(REG_OFFSET_BG1HOFS, 0);
        SetGpuReg(REG_OFFSET_BG1VOFS, 140);
        SetGpuReg(REG_OFFSET_BG0HOFS, 0);
        SetGpuReg(REG_OFFSET_BG0VOFS, 0);
        DmaFill16(3, 0, (void *)VRAM, VRAM_SIZE);
        DmaFill32(3, 0, (void *)OAM, OAM_SIZE);
        DmaFill16(3, 0, (void *)(PLTT + 2), PLTT_SIZE - 2);
        ResetPaletteFade();
        gMain.state = 1;
        break;
    case 1:
        LZ77UnCompVram(gTitleScreenPokemonLogoGfx, (void *)VRAM);
        LZ77UnCompVram(gTitleScreenPokemonLogoTilemap, (void *)(VRAM + 0xF800));
        LoadPalette(gTitleScreenBgPalettes, 0, 0x200);
        LZ77UnCompVram(sTitleScreenCloudsGfx, (void *)(VRAM + 0x8000));
        LZ77UnCompVram(sTitleScreenCloudsTilemap, (void *)(VRAM + 0xE000));
        LZ77UnCompVram(sTitleScreenEmblemGfx, (void *)(VRAM + 0x4000));
        LZ77UnCompVram(sTitleScreenEmblemTilemap, (void *)(VRAM + 0xE800));
        ScanlineEffect_Stop();
        ResetTasks();
        ResetSpriteData();
        FreeAllSpritePalettes();
        gReservedSpritePaletteCount = 9;
        LoadCompressedObjectPic(&sSpriteSheet_Suicune[0]);
        LoadCompressedObjectPic(&sPokemonLogoShineSpriteSheet[0]);
        LoadSpritePalette(&sSpritePalette_Suicune[0]);
        gMain.state = 2;
        break;
    case 2:
    {
        u8 taskId = CreateTask(Task_TitleScreenDoIntro, 0);

        CreateSprite(&sSuicuneSpriteTemplate, 120, 118, 0);
        gMain.state = 3;
        break;
    }
    case 3:
        BeginNormalPaletteFade(0xFFFFFFFF, 1, 0x10, 0, 0xFFFF);
        gMain.state = 4;
        break;
    case 4:
        sub_816F2A8(0x78, 0x50, 0x100, 0);
        SetGpuReg(REG_OFFSET_WIN0H, 0);
        SetGpuReg(REG_OFFSET_WIN0V, 160);
        SetGpuReg(REG_OFFSET_WININ, 0x3F);
        SetGpuReg(REG_OFFSET_WINOUT, 0x3E);
        SetGpuReg(REG_OFFSET_BG0CNT, BGCNT_PRIORITY(0) | BGCNT_CHARBASE(0) | BGCNT_SCREENBASE(31) | BGCNT_256COLOR | BGCNT_TXT256x256);
        SetGpuReg(REG_OFFSET_BG1CNT, BGCNT_PRIORITY(1) | BGCNT_CHARBASE(1) | BGCNT_SCREENBASE(29) | BGCNT_16COLOR | BGCNT_TXT256x512);
        SetGpuReg(REG_OFFSET_BG2CNT, BGCNT_PRIORITY(2) | BGCNT_CHARBASE(2) | BGCNT_SCREENBASE(28) | BGCNT_16COLOR | BGCNT_TXT256x256);
        EnableInterrupts(INTR_FLAG_VBLANK);
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0
                                    | DISPCNT_OBJ_1D_MAP
                                    | DISPCNT_BG0_ON
                                    | DISPCNT_BG1_ON
                                    | DISPCNT_BG2_ON
                                    | DISPCNT_OBJ_ON
                                    | DISPCNT_WIN0_ON);
        m4aSongNumStart(MUS_TITLE3);
        gMain.state = 5;
        break;
    case 5:
        SetMainCallback2(MainCB2);
        break;
    }
}

static void MainCB2(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

static void VBlankCB_Comb(void)
{
    DmaStop(0);
    VBlankCB();
    if (sVBlank_DMA)
        DmaCopy16(3, gScanlineEffectRegBuffers[0], gScanlineEffectRegBuffers[1], 640);
    DmaSet(0, &gScanlineEffectRegBuffers[1][160], &REG_WIN0H, 0xA2400001);
}

static void HBlankCB_Comb(void)
{
    if (REG_VCOUNT < 160)
        REG_BG0HOFS = gScanlineEffectRegBuffers[1][REG_VCOUNT] + 3;
}

static bool8 LogoComb_Func1(struct Task *task);
static bool8 LogoComb_Func2(struct Task *task);
static bool8 LogoComb_Func3(struct Task *task);

static bool8 (*const sLogoCombFuncs[])(struct Task *task) =
{
    LogoComb_Func1,
    LogoComb_Func2,
    LogoComb_Func3
};

#define tState data[0]
#define tLogoPos data[1]
#define tEmblemPos data[2]

static void Task_TitleScreenDoIntro(u8 taskId)
{
    while (sLogoCombFuncs[gTasks[taskId].tState](&gTasks[taskId]));
}

static bool8 LogoComb_Func1(struct Task *task)
{
    u16 i;

    ScanlineEffect_Clear();

    task->tLogoPos = 240;
    task->tEmblemPos = 140;
    sVBlank_DMA = FALSE;

    for (i = 0; i < 160; i++)
    {
        gScanlineEffectRegBuffers[1][i] = 240;
        gScanlineEffectRegBuffers[1][160 + i] = 0;
    }

    EnableInterrupts(INTR_FLAG_HBLANK);
    SetGpuRegBits(REG_OFFSET_DISPSTAT, DISPSTAT_HBLANK_INTR);

    SetVBlankCallback(VBlankCB_Comb);
    SetHBlankCallback(HBlankCB_Comb);

    task->tState++;
    return TRUE;
}

static bool8 LogoComb_Func2(struct Task *task)
{
    u16 i;

    sVBlank_DMA = FALSE;

    task->tLogoPos -= 8;
    if (task->tLogoPos <= 0)
        task->tLogoPos = 0;

    task->tEmblemPos -= 4;
    if (task->tEmblemPos <= 20)
        task->tEmblemPos = 20;

    SetGpuReg(REG_OFFSET_BG1VOFS, task->tEmblemPos);

    for (i = 0; i < 160; i++)
    {
        u16 *storeLoc1 = &gScanlineEffectRegBuffers[0][i];
        u16 *storeLoc2 = &gScanlineEffectRegBuffers[0][i + 160];
        if (i & 1)
        {
            *storeLoc1 = task->tLogoPos;
            *storeLoc2 = 240 - task->tLogoPos;
        }
        else
        {
            *storeLoc1 = -task->tLogoPos;
            *storeLoc2 = (task->tLogoPos << 8) | (0xF1);
        }
    }

    if (task->tLogoPos == 0 && task->tEmblemPos == 20)
        task->tState++;

    sVBlank_DMA++;
    return FALSE;
}

static bool8 LogoComb_Func3(struct Task *task)
{
    DmaStop(0);
    SetGpuReg(REG_OFFSET_BG0HOFS, 3);
    SetVBlankCallback(VBlankCB);
    SetHBlankCallback(NULL);
    DisableInterrupts(INTR_FLAG_HBLANK);
    ClearGpuRegBits(REG_OFFSET_DISPSTAT, DISPSTAT_HBLANK_INTR);
    task->func = Task_TitleScreenProcessInput;
    return FALSE;
}

// Process title screen input
static void Task_TitleScreenProcessInput(u8 taskId)
{
    if ((gMain.newKeys & A_BUTTON) || (gMain.newKeys & START_BUTTON))
    {
        FadeOutBGM(4);
        BeginNormalPaletteFade(0xFFFFFFFF, 1, 0, 0x10, RGB_WHITEALPHA);
        SetMainCallback2(CB2_GoToMainMenu);
    }
    else if ((gMain.heldKeys & CLEAR_SAVE_BUTTON_COMBO) == CLEAR_SAVE_BUTTON_COMBO)
    {
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 0x10, RGB_WHITEALPHA);
        SetMainCallback2(CB2_GoToClearSaveDataScreen);
    }
    else if ((gMain.heldKeys & RESET_RTC_BUTTON_COMBO) == RESET_RTC_BUTTON_COMBO
      && CanResetRTC() == TRUE)
    {
        FadeOutBGM(4);
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 0x10, RGB_BLACK);
        SetMainCallback2(CB2_GoToResetRtcScreen);
    }
    else if ((gMain.heldKeys & BERRY_UPDATE_BUTTON_COMBO) == BERRY_UPDATE_BUTTON_COMBO)
    {
        FadeOutBGM(4);
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 0x10, RGB_BLACK);
        SetMainCallback2(CB2_GoToBerryFixScreen);
    }
    else
    {
        UpdatePressStartColor(taskId);
        if (IsBGMStopped())
        {
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 0x10, 0xFFFF);
            SetMainCallback2(CB2_GoToCopyrightScreen);
        }
    }
}

static void CB2_GoToMainMenu(void)
{
    if (!UpdatePaletteFade())// && gMPlayInfo_BGM.fadeOV < 0x40)
        SetMainCallback2(CB2_InitMainMenu);
    AnimateSprites();   // does having Suicune pause or continue running look better?
    BuildOamBuffer();
}

static void CB2_GoToCopyrightScreen(void)
{
    if (!UpdatePaletteFade())
        SetMainCallback2(CB2_InitCopyrightScreenAfterTitleScreen);
    AnimateSprites();
    BuildOamBuffer();
}

static void CB2_GoToClearSaveDataScreen(void)
{
    if (!UpdatePaletteFade())
        SetMainCallback2(CB2_InitClearSaveDataScreen);
    AnimateSprites();
    BuildOamBuffer();
}

static void CB2_GoToResetRtcScreen(void)
{
    if (!UpdatePaletteFade())
        SetMainCallback2(CB2_InitResetRtcScreen);
    AnimateSprites();
    BuildOamBuffer();
}

static void CB2_GoToBerryFixScreen(void)
{
    if (!UpdatePaletteFade())
    {
        m4aMPlayAllStop();
        SetMainCallback2(CB2_InitBerryFixProgram);
    }
    AnimateSprites();
    BuildOamBuffer();
}

static void UpdatePressStartColor(u8 taskId)
{
    int i;
    s16 timer;

    if (gTasks[taskId].data[1] == 0)
        timer = 60;
    else
        timer = 30;
    
    if (gTasks[taskId].data[0]++ >= timer)
    {
        gTasks[taskId].data[0] = 0;
        if ((gTasks[taskId].data[1] ^= 1) != 0)
        {
            for (i = 0; i < 5; i++)
            {
                gPlttBufferUnfaded[0xF1 + i] = gTitleScreenPressStartPal[6];
                gPlttBufferFaded[0xF1 + i] = gTitleScreenPressStartPal[6];
            }
        }
        else
        {
            for (i = 0; i < 5; i++)
            {
                gPlttBufferUnfaded[0xF1 + i] = gTitleScreenPressStartPal[i + 1];
                gPlttBufferFaded[0xF1 + i] = gTitleScreenPressStartPal[i + 1];
            }
        }
    }
}
