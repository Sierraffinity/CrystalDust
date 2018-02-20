#include "global.h"
#include "main.h"
#include "palette.h"
#include "scanline_effect.h"
#include "task.h"
#include "title_screen.h"
#include "libgcnmultiboot.h"
#include "malloc.h"
#include "gpu_regs.h"
#include "link.h"
#include "multiboot_pokemon_colosseum.h"
#include "load_save.h"
#include "save.h"
#include "new_game.h"
#include "m4a.h"
#include "random.h"
#include "decompress.h"
#include "constants/songs.h"
#include "intro_credits_graphics.h"
#include "trig.h"
#include "intro.h"
#include "graphics.h"
#include "sound.h"
#include "constants/species.h"
#include "blend_palette.h"
#include "title_screen.h"
#include "constants/rgb.h"
#include "battle_dome_cards.h"

extern const struct CompressedSpriteSheet gBattleAnimPicTable[];
extern const struct CompressedSpritePalette gBattleAnimPaletteTable[];
extern const struct SpriteTemplate gUnknown_08596C10[];

//ewram
EWRAM_DATA u16 gUnknown_0203BCC8 = 0;
EWRAM_DATA u16 gUnknown_0203BCCA = 0;
EWRAM_DATA u16 gUnknown_0203BCCC = 0;

//iwram
u32 gIntroFrameCounter;
struct GcmbStruct gMultibootProgramStruct;

//.rodata
static const u16 gIntro1BGPals[] = INCBIN_U16("graphics/intro/intro1_background.gbapal");
static const u8 gIntro1BG2_Tilemap[] = INCBIN_U8("graphics/intro/intro1_bg2.bin.lz");
static const u8 gIntro1BG2_LogoTilemap[] = INCBIN_U8("graphics/intro/intro1_bg2_logo.bin.lz");
static const u8 gIntro1BG3_Tilemap[] = INCBIN_U8("graphics/intro/intro1_bg3.bin.lz");
static const u8 gIntro1BG0_Tiles[] = INCBIN_U8("graphics/intro/intro1_background.4bpp.lz");
static const u8 gIntro1BG0_LogoTiles[] = INCBIN_U8("graphics/intro/intro1_logotiles.4bpp.lz");
static const u8 gIntroDittoTiles[] = INCBIN_U8("graphics/intro/intro1_ditto.4bpp.lz");
static const u8 gIntroPresentsTiles[] = INCBIN_U8("graphics/intro/intro1_presents.4bpp.lz");
static const u16 gIntro1DittoPalette[] = INCBIN_U16("graphics/intro/intro1_ditto.gbapal");
static const u16 gIntro2BGPals[][16] = {
    INCBIN_U16("graphics/intro/intro2_bg3.gbapal"),
    INCBIN_U16("graphics/intro/intro2_bg1.gbapal")
};
static const u8 gIntro2Tiles[] = INCBIN_U8("graphics/intro/intro2.4bpp.lz");
static const u8 gIntro2BG1_Tilemap[] = INCBIN_U8("graphics/intro/intro2_bg1.bin.lz");
static const u8 gIntro2BG2_Tilemap[] = INCBIN_U8("graphics/intro/intro2_bg2.bin.lz");
static const u8 gIntro2BG3_Tilemap[] = INCBIN_U8("graphics/intro/intro2_bg3.bin.lz");
static const u8 gIntro2UnownATiles[] = INCBIN_U8("graphics/intro/intro2_unownA.4bpp.lz");
static const u16 gIntro2UnownPalette[] = INCBIN_U16("graphics/intro/intro2_unownA.gbapal");
static const u8 gIntro2UnownPulseTiles[] = INCBIN_U8("graphics/intro/intro2_unown_pulse.4bpp.lz");
static const u16 gIntro2UnownPulsePalette[] = INCBIN_U16("graphics/intro/intro2_unown_pulse.gbapal");

static const struct CompressedSpriteSheet gSpriteSheet_Ditto[] =
{
    {gIntroDittoTiles, 0x1800, 2000},
    {NULL},
};
static const struct SpritePalette gSpritePalette_Ditto[] =
{
    {gIntro1DittoPalette, 2000},
    {NULL},
};
static const struct OamData gOamData_Ditto =
{
    .y = 160,
    .affineMode = 1,
    .objMode = 0,
    .mosaic = TRUE,
    .bpp = 0,
    .shape = 0,
    .x = 0,
    .matrixNum = 0,
    .size = 3,
    .tileNum = 0,
    .priority = 3,
    .paletteNum = 0,
    .affineParam = 0,
};
static const union AnimCmd gSpriteAnim1_Ditto[] =
{
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_END,
};
static const union AnimCmd gSpriteAnim2_Ditto[] =
{
    ANIMCMD_FRAME(0, 48),
    ANIMCMD_FRAME(64, 8),
    ANIMCMD_END,
};
static const union AnimCmd gSpriteAnim3_Ditto[] =
{
    ANIMCMD_FRAME(128, 8),
    ANIMCMD_END,
};
static const union AnimCmd *const gSpriteAnimTable_Ditto[] =
{
    gSpriteAnim1_Ditto,
    gSpriteAnim2_Ditto,
    gSpriteAnim3_Ditto,
};
static const union AffineAnimCmd gSpriteAffineAnim1_Ditto[] = 
{
    AFFINEANIMCMD_SIZE(1, 1, 0),
    AFFINEANIMCMD_END,
};
static const union AffineAnimCmd gSpriteAffineAnim2_Ditto[] = 
{
    AFFINEANIMCMD_SIZE(0.75, 1.5, 0),
    AFFINEANIMCMD_FRAME(0, 0, 0, 8),
    AFFINEANIMCMD_FRAME(64, -64, 0, 3),
    AFFINEANIMCMD_FRAME(-24, 24, 0, 8),
    AFFINEANIMCMD_FRAME(3, -6, 0, 24),
    AFFINEANIMCMD_FRAME(24, -24, 0, 3),
    AFFINEANIMCMD_FRAME(-24, 24, 0, 3),
    AFFINEANIMCMD_SIZE(1, 1, 0),
    AFFINEANIMCMD_END,
};
static const union AffineAnimCmd *const gSpriteAffineAnimTable_Ditto[] =
{
    gSpriteAffineAnim1_Ditto,
    gSpriteAffineAnim2_Ditto,
};
static void SpriteCallback_Ditto(struct Sprite *sprite);
static const struct SpriteTemplate gSpriteTemplate_Ditto =
{
    .tileTag = 2000,
    .paletteTag = 2000,
    .oam = &gOamData_Ditto,
    .anims = gSpriteAnimTable_Ditto,
    .images = NULL,
    .affineAnims = gSpriteAffineAnimTable_Ditto,
    .callback = SpriteCallback_Ditto,
};
static const struct CompressedSpriteSheet gSpriteSheet_Presents[] =
{
    {gIntroPresentsTiles, 0x100, 2001},
    {NULL},
};
static const struct OamData gOamData_Presents =
{
    .y = 0,
    .affineMode = 0,
    .objMode = 1,
    .mosaic = 0,
    .bpp = 0,
    .shape = 1,
    .x = 0,
    .matrixNum = 0,
    .size = 1,
    .tileNum = 0,
    .priority = 3,
    .paletteNum = 0,
    .affineParam = 0,
};
static const struct SpriteTemplate gSpriteTemplate_Presents =
{
    .tileTag = 2001,
    .paletteTag = 2000,
    .oam = &gOamData_Presents,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};
static const struct CompressedSpriteSheet gIntro2UnownASpriteSheet[] =
{
    {gIntro2UnownATiles, 0x400, 2002},
    {NULL},
};
static const struct SpritePalette gIntro2SpritePalettes[] =
{
    {gIntro2UnownPalette, 2002},
    {gIntro2UnownPulsePalette, 2003},
    {NULL},
};
static const struct OamData gOamData_UnownA =
{
    .y = 0,
    .affineMode = 3,
    .objMode = 0,
    .mosaic = 0,
    .bpp = 0,
    .shape = 2,
    .x = 0,
    .matrixNum = 0,
    .size = 3,
    .tileNum = 0,
    .priority = 3,
    .paletteNum = 0,
    .affineParam = 0,
};
static const union AffineAnimCmd gSpriteAffineAnim_UnownA1[] = 
{
    AFFINEANIMCMD_SIZE(1, 1, 0),
    AFFINEANIMCMD_END,
};
static const union AffineAnimCmd gSpriteAffineAnim_UnownA2[] = 
{
    AFFINEANIMCMD_SIZE(1, 1, 0),
    AFFINEANIMCMD_FRAME(8, 8, 0, 8),
    AFFINEANIMCMD_FRAME(-8, -8, 0, 8),
    AFFINEANIMCMD_END,
};
static const union AffineAnimCmd *const gSpriteAffineAnimTable_UnownA[] =
{
    gSpriteAffineAnim_UnownA1,
    gSpriteAffineAnim_UnownA2,
};
static const struct SpriteTemplate gSpriteTemplate_UnownA =
{
    .tileTag = 2002,
    .paletteTag = 2002,
    .oam = &gOamData_UnownA,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gSpriteAffineAnimTable_UnownA,
    .callback = SpriteCallbackDummy,
};
static const struct CompressedSpriteSheet gIntro2UnownPulseSpriteSheet[] =
{
    {gIntro2UnownPulseTiles, 0x800, 2003},
    {NULL},
};
static const struct OamData gOamData_UnownPulse =
{
    .y = 0,
    .affineMode = 0,
    .objMode = 0,
    .mosaic = 0,
    .bpp = 0,
    .shape = 0,
    .x = 0,
    .matrixNum = 0,
    .size = 2,
    .tileNum = 0,
    .priority = 3,
    .paletteNum = 0,
    .affineParam = 0,
};
static const union AnimCmd gSpriteAnim_UnownPulse1[] =
{
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(16, 2),
    ANIMCMD_FRAME(32, 4),
    ANIMCMD_FRAME(48, 8),
    ANIMCMD_END,
};
static const union AnimCmd *const gSpriteAnimTable_UnownPulse[] =
{
    gSpriteAnim_UnownPulse1,
};
static void SpriteCallback_UnownPulse(struct Sprite *sprite);
static const struct SpriteTemplate gSpriteTemplate_UnownPulse =
{
    .tileTag = 2003,
    .paletteTag = 2003,
    .oam = &gOamData_UnownPulse,
    .anims = gSpriteAnimTable_UnownPulse,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallback_UnownPulse,
};

// this file's functions
static void MainCB2_EndIntro(void);
static void Task_IntroLoadPart1Graphics(u8);
static void Task_IntroGameFreakStart(u8);
static void intro_reset_and_hide_bgs(void);
static void Task_GameFreakWindowOpen(u8);
static void Task_ShowGameFreakScreen(u8);
static void Task_MosaicToGameFreakLogo(u8);
static void Task_FadeInOutGameFreakText(u8);
static void Task_WaitToStartUnownSequence(u8);
static void Task_IntroLoadPart2Graphics(u8);
static void Task_IntroStartUnownSequence(u8);
static void Task_IntroDoUnownASequence(u8);

static void VBlankCB_Intro(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
    ScanlineEffect_InitHBlankDmaTransfer();
}

static void MainCB2_Intro(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
    if (gMain.newKeys && !gPaletteFade.active)
        SetMainCallback2(MainCB2_EndIntro);
    else if (gIntroFrameCounter != -1)
        gIntroFrameCounter++;
}

static void MainCB2_EndIntro(void)
{
    if (!UpdatePaletteFade())
        SetMainCallback2(CB2_InitTitleScreen);
}

static void LoadCopyrightGraphics(u16 tilesetAddress, u16 tilemapAddress, u16 paletteAddress)
{
    LZ77UnCompVram(gIntroCopyright_Gfx, (void *)(VRAM + tilesetAddress));
    LZ77UnCompVram(gIntroCopyright_Tilemap, (void *)(VRAM + tilemapAddress));
    LoadPalette(gIntroCopyright_Pal, paletteAddress, 0x20);
}

static void SerialCB_CopyrightScreen(void)
{
    GameCubeMultiBoot_HandleSerialInterrupt(&gMultibootProgramStruct);
}

static u8 SetUpCopyrightScreen(void)
{
    u16 ime;

    switch (gMain.state)
    {
    case 0:
        SetVBlankCallback(NULL);
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        SetGpuReg(REG_OFFSET_BLDY, 0);
        *(u16 *)PLTT = 0x7FFF;
        SetGpuReg(REG_OFFSET_DISPCNT, 0);
        SetGpuReg(REG_OFFSET_BG0HOFS, 0);
        SetGpuReg(REG_OFFSET_BG0VOFS, 0);
        CpuFill32(0, (void *)VRAM, VRAM_SIZE);
        CpuFill32(0, (void *)OAM, OAM_SIZE);
        CpuFill16(0, (void *)(PLTT + 2), PLTT_SIZE - 2);
        ResetPaletteFade();
        LoadCopyrightGraphics(0, 0x3800, 0);
        ScanlineEffect_Stop();
        ResetTasks();
        ResetSpriteData();
        FreeAllSpritePalettes();
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0x10, 0, RGB_WHITEALPHA);
        SetGpuReg(REG_OFFSET_BG0CNT, BGCNT_PRIORITY(0)
                                   | BGCNT_CHARBASE(0)
                                   | BGCNT_SCREENBASE(7)
                                   | BGCNT_16COLOR
                                   | BGCNT_TXT256x256);
        EnableInterrupts(INTR_FLAG_VBLANK);
        SetVBlankCallback(VBlankCB_Intro);
        REG_DISPCNT = DISPCNT_MODE_0 | DISPCNT_OBJ_1D_MAP | DISPCNT_BG0_ON;
        SetSerialCallback(SerialCB_CopyrightScreen);
        GameCubeMultiBoot_Init(&gMultibootProgramStruct);
    default:
        UpdatePaletteFade();
        gMain.state++;
        GameCubeMultiBoot_Main(&gMultibootProgramStruct);
        break;
    case 140:
        GameCubeMultiBoot_Main(&gMultibootProgramStruct);
        if (gMultibootProgramStruct.gcmb_field_2 != 1)
        {
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 0x10, RGB_BLACK);
            gMain.state++;
        }
        break;
    case 141:
        if (UpdatePaletteFade())
            break;
        CreateTask(Task_IntroLoadPart1Graphics, 0);
        SetMainCallback2(MainCB2_Intro);
        if (gMultibootProgramStruct.gcmb_field_2 != 0)
        {
            if (gMultibootProgramStruct.gcmb_field_2 == 2)
            {
                // check the multiboot ROM header game code to see if we already did this
                if (*(u32 *)(EWRAM_START + 0xAC) == 0x65366347) // "Gc6e" in ASCII
                {
                    CpuCopy16(&gMultiBootProgram_PokemonColosseum_Start, (void *)EWRAM_START, sizeof(gMultiBootProgram_PokemonColosseum_Start));
                    *(u32 *)(EWRAM_START + 0xAC) = 0x65366347;
                }
                GameCubeMultiBoot_ExecuteProgram(&gMultibootProgramStruct);
            }
        }
        else
        {
            GameCubeMultiBoot_Quit();
            SetSerialCallback(SerialCB);
        }
        return 0;
    }

    return 1;
}

void CB2_InitCopyrightScreenAfterBootup(void)
{
    if (!SetUpCopyrightScreen())
    {
        SetSaveBlocksPointers(sub_815355C());
        sub_808447C();
        Save_ResetSaveCounters();
        Save_LoadGameData(SAVE_NORMAL);
        if (gSaveFileStatus == 0 || gSaveFileStatus == 2)
            Sav2_ClearSetDefault();
        SetPokemonCryStereo(gSaveBlock2Ptr->optionsSound);
        InitHeap(gHeap, HEAP_SIZE);
    }
}

void CB2_InitCopyrightScreenAfterTitleScreen(void)
{
    SetUpCopyrightScreen();
}

static void Task_IntroLoadPart1Graphics(u8 taskId)
{
    u8 spriteId;
    SetVBlankCallback(NULL);
    intro_reset_and_hide_bgs();
    SetGpuReg(REG_OFFSET_BG3VOFS, 0);
    SetGpuReg(REG_OFFSET_BG2VOFS, 0);
    LZ77UnCompVram(gIntro1BG0_Tiles, (void *)(VRAM + 0xC000));
    LZ77UnCompVram(gIntro1BG0_LogoTiles, (void *)(VRAM + 0xC200));
    LZ77UnCompVram(gIntro1BG2_Tilemap, (void *)(VRAM + 0xF000));
    LZ77UnCompVram(gIntro1BG3_Tilemap, (void *)(VRAM + 0xF800));
    LoadPalette(gIntro1BGPals, 0, sizeof(gIntro1BGPals));
    SetGpuReg(REG_OFFSET_BG3CNT, BGCNT_PRIORITY(3)
                               | BGCNT_CHARBASE(3)
                               | BGCNT_SCREENBASE(31)
                               | BGCNT_16COLOR
                               | BGCNT_TXT256x256);
    SetGpuReg(REG_OFFSET_BG2CNT, BGCNT_PRIORITY(2)
                               | BGCNT_CHARBASE(3)
                               | BGCNT_SCREENBASE(30)
                               | BGCNT_16COLOR
                               | BGCNT_TXT256x256);
    LoadCompressedObjectPic(gSpriteSheet_Ditto);
    LoadCompressedObjectPic(gSpriteSheet_Presents);
    LoadSpritePalettes(gSpritePalette_Ditto);
    CpuCopy16(gPlttBufferUnfaded + 0x100, gPlttBufferUnfaded + 0x1F0, 0x20);
    CpuCopy16(gPlttBufferUnfaded + 0x100, gPlttBufferUnfaded + 0x1E1, 0x1E);
    CpuCopy16(gPlttBufferUnfaded + 0x100, gPlttBufferUnfaded + 0x1D2, 0x1C);
    CpuCopy16(gPlttBufferUnfaded + 0x100, gPlttBufferUnfaded + 0x1C3, 0x1A);
    CpuCopy16(gPlttBufferUnfaded + 0x100, gPlttBufferUnfaded + 0x1B4, 0x18);
    CpuCopy16(gPlttBufferUnfaded + 0x100, gPlttBufferUnfaded + 0x1A5, 0x16);
    CpuCopy16(gPlttBufferUnfaded + 0x100, gPlttBufferUnfaded + 0x196, 0x14);
    spriteId = CreateSprite(&gSpriteTemplate_Ditto, 120, -48, 0);
    gSprites[spriteId].data[0] = 0;
    StartSpriteAnim(&gSprites[spriteId], 1);
    StartSpriteAffineAnim(&gSprites[spriteId], 1);
    gTasks[taskId].data[1] = spriteId;
    gTasks[taskId].func = Task_IntroGameFreakStart;
}

static void Task_IntroGameFreakStart(u8 taskId)
{
    SetVBlankCallback(VBlankCB_Intro);
    SetGpuReg(REG_OFFSET_WIN0H, 0xF0);
    SetGpuReg(REG_OFFSET_WIN0V, 0x50);
    SetGpuReg(REG_OFFSET_WININ, 0x3F);
    SetGpuReg(REG_OFFSET_WINOUT, 0x10);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0
                                | DISPCNT_OBJ_1D_MAP
                                | DISPCNT_BG3_ON
                                | DISPCNT_OBJ_ON
                                | DISPCNT_WIN0_ON);
    gTasks[taskId].func = Task_GameFreakWindowOpen;
    gTasks[taskId].data[0] = 0x50;
    gIntroFrameCounter = 0;
    m4aSongNumStart(MUS_DEMO1);
    ResetSerial();
}

static void Task_GameFreakWindowOpen(u8 taskId)
{
    u16 foo = gTasks[taskId].data[0];

    if (gTasks[taskId].data[0] != 32)
    {
        gTasks[taskId].data[0] -= 8;
        SetGpuReg(REG_OFFSET_WIN0V, (gTasks[taskId].data[0] * 256) - (foo -= 0x9C));
    }
    else
    {
        SetGpuReg(REG_OFFSET_WIN0V, 0x2080);
        gTasks[taskId].func = Task_ShowGameFreakScreen;
    }
}

static void Task_ShowGameFreakScreen(u8 taskId)
{
    u8 newTaskId;
    if (gIntroFrameCounter == 80)
        CreateTask(Task_MosaicToGameFreakLogo, 0);
    
    if (gIntroFrameCounter == 170)
    {
        SetGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_BG2_ON);
        SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG2
                                   | BLDCNT_EFFECT_BLEND
                                   | BLDCNT_TGT2_BG0
                                   | BLDCNT_TGT2_BG1
                                   | BLDCNT_TGT2_BG2
                                   | BLDCNT_TGT2_BG3
                                   | BLDCNT_TGT2_OBJ
                                   | BLDCNT_TGT2_BD);
        newTaskId = CreateTask(Task_FadeInOutGameFreakText, 0);
        gTasks[newTaskId].data[2] = 0;
    }
    
    if (gIntroFrameCounter == 200)
    {
        LZ77UnCompVram(gIntro1BG2_LogoTilemap, (void *)(VRAM + 0xF000));
        DestroySprite(&gSprites[gTasks[taskId].data[1]]);
        gTasks[taskId].data[0] = CreateSprite(&gSpriteTemplate_Presents, 104, 108, 5);
        gTasks[taskId].data[1] = CreateSprite(&gSpriteTemplate_Presents, 136, 108, 5);
        gSprites[gTasks[taskId].data[1]].oam.tileNum += 4;
    }
    
    if (gIntroFrameCounter == 320)
    {
        SetGpuRegBits(REG_OFFSET_BLDCNT, BLDCNT_TGT1_OBJ);
        newTaskId = CreateTask(Task_FadeInOutGameFreakText, 0);
        gTasks[newTaskId].data[2] = 1;
    }
    
    if (gIntroFrameCounter == 350)
    {
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
        gTasks[newTaskId].func = Task_WaitToStartUnownSequence;
    }
}

static void Task_MosaicToGameFreakLogo(u8 taskId)
{
    u16 temp;
    
    if (gIntroFrameCounter < 98)
    {
        temp = gTasks[taskId].data[0]++ >> 1;
        if (temp > 20)
            temp = 20;
        SetGpuReg(REG_OFFSET_MOSAIC, MOSAIC_SIZE(0, 0, temp, temp));
        return;
    }
    
    if (gIntroFrameCounter == 98)
    {
        // shift it up a tad pls
        gSprites[gTasks[taskId].data[1]].pos1.y = 70;
        StartSpriteAnim(&gSprites[gTasks[taskId].data[1]], 2);
    }
    
    if (gIntroFrameCounter < 116)
    {
        temp = gTasks[taskId].data[0]-- >> 1;
        if (temp > 20)
            temp = 20;
        SetGpuReg(REG_OFFSET_MOSAIC, MOSAIC_SIZE(0, 0, temp, temp));
        return;
    }
    
    if (gTasks[taskId].data[0] == 0)
    {
        SetGpuReg(REG_OFFSET_MOSAIC, 0);
        DestroyTask(taskId);
    }
}

static void Task_FadeInOutGameFreakText(u8 taskId)
{
    u16 temp;
    if (gTasks[taskId].data[1]++ < 16)
    {
        if (gTasks[taskId].data[2] == 0)
        {
            temp = gTasks[taskId].data[1];
            SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(temp, 16 - temp));
        }
        else
        {
            temp = gTasks[taskId].data[1];
            SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(16 - temp, temp));
        }
    }
    else
    {
        if (gTasks[taskId].data[2] == 0)
            SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(16, 0));
        else
            SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(0, 16));
        DestroyTask(taskId);
    }
}

static void Task_WaitToStartUnownSequence(u8 taskId)
{
    if (gIntroFrameCounter == 430)
    {
        gIntroFrameCounter = 0;
        gTasks[taskId].func = Task_IntroLoadPart2Graphics;
    }
}

static void SpriteCallback_Ditto(struct Sprite *sprite)
{
    switch (sprite->data[0])
    {
    case 0:
        if (sprite->pos1.y < 80)
        {
            sprite->pos1.y += 10;
        }
        else
        {
            sprite->pos1.y = 79;
            sprite->data[1] = Q_8_8(-10);
            sprite->data[0]++;
        }
        break;
    case 1:
        if (sprite->pos1.y < 80)
        {
            sprite->pos1.y += Q_8_8_TO_INT(sprite->data[1]);
            sprite->data[1] += Q_8_8(0.65);
        }
        else
        {
            sprite->pos1.y = 80;
            sprite->callback = SpriteCallbackDummy;
        }
        break;
    }
}

static void Task_IntroLoadPart2Graphics(u8 taskId)
{
    intro_reset_and_hide_bgs();
    SetVBlankCallback(NULL);
    ResetSpriteData();
    FreeAllSpritePalettes();
    LZ77UnCompVram(gIntro2Tiles, (void *)(VRAM));
    LZ77UnCompVram(gIntro2BG1_Tilemap, (void *)(VRAM + 0xE800));
    LZ77UnCompVram(gIntro2BG2_Tilemap, (void *)(VRAM + 0xF000));
    LZ77UnCompVram(gIntro2BG3_Tilemap, (void *)(VRAM + 0xF800));
    LoadPalette(gIntro2BGPals, 0, sizeof(gIntro2BGPals));
    gTasks[taskId].func = Task_IntroStartUnownSequence;
}

static void Task_IntroStartUnownSequence(u8 taskId)
{
    LoadCompressedObjectPic(gIntro2UnownASpriteSheet);
    LoadCompressedObjectPic(gIntro2UnownPulseSpriteSheet);
    LoadCompressedObjectPic(gIntro2UnownOthersSpriteSheet);
    LoadSpritePalettes(gIntro2SpritePalettes);
    gTasks[taskId].data[1] = CreateSprite(&gSpriteTemplate_UnownA, 120, 80, 0);
    BeginNormalPaletteFade(0x00010000, 2, 16, 0, RGB_BLACK);
    SetVBlankCallback(VBlankCB_Intro);
    SetGpuReg(REG_OFFSET_BG3CNT, BGCNT_PRIORITY(3)
                               | BGCNT_CHARBASE(0)
                               | BGCNT_SCREENBASE(31)
                               | BGCNT_16COLOR
                               | BGCNT_TXT256x512);
    SetGpuReg(REG_OFFSET_BG2CNT, BGCNT_PRIORITY(2)
                               | BGCNT_CHARBASE(0)
                               | BGCNT_SCREENBASE(30)
                               | BGCNT_16COLOR
                               | BGCNT_TXT256x512);
    SetGpuReg(REG_OFFSET_BG1CNT, BGCNT_PRIORITY(1)
                               | BGCNT_CHARBASE(0)
                               | BGCNT_SCREENBASE(29)
                               | BGCNT_16COLOR
                               | BGCNT_TXT256x512);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0
                                | DISPCNT_OBJ_1D_MAP
                                | DISPCNT_OBJ_ON);
    gTasks[taskId].data[0] = 0;
    gTasks[taskId].func = Task_IntroDoUnownASequence;
}

static void CreateUnownPulse(s16 x, s16 y)
{
    u8 spriteId;
    
    CreateSprite(&gSpriteTemplate_UnownPulse, x - 16, y - 16, 0);
    spriteId = CreateSprite(&gSpriteTemplate_UnownPulse, x + 16, y - 16, 0);
    gSprites[spriteId].hFlip = TRUE;
    gSprites[spriteId].oam.matrixNum |= 0x8;
    spriteId = CreateSprite(&gSpriteTemplate_UnownPulse, x - 16, y + 16, 0);
    gSprites[spriteId].vFlip = TRUE;
    gSprites[spriteId].oam.matrixNum |= 0x10;
    spriteId = CreateSprite(&gSpriteTemplate_UnownPulse, x + 16, y + 16, 0);
    gSprites[spriteId].hFlip = TRUE;
    gSprites[spriteId].vFlip = TRUE;
    gSprites[spriteId].oam.matrixNum |= 0x18;
}

static void Task_IntroDoUnownASequence(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    
    switch (data[0])
    {
    case 0:
    case 3:
        if (!gPaletteFade.active)
        {
            BeginNormalPaletteFade(0x00010000, 2, 0, 16, RGB_BLACK);
            data[0]++;
        }
        break;
    case 1:
        if (!gPaletteFade.active)
        {
            BeginNormalPaletteFade(0x00010000, 2, 16, 0, RGB_BLACK);
            data[0]++;
        }
        break;
    case 2:
        if (gIntroFrameCounter == 100)
        {
            StartSpriteAffineAnim(&gSprites[data[1]], 1);
            CreateUnownPulse(120, 80);
            data[0]++;
        }
        break;
    case 4:
        if (!gPaletteFade.active)
        {
            DestroySprite(&gSprites[data[1]]);
            data[0]++;
        }
        break;
    case 5:
        if (gIntroFrameCounter == 180)
        {
            SetGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_BG1_ON
                                            | DISPCNT_BG2_ON
                                            | DISPCNT_BG3_ON);
            data[1] = 0;
            data[0]++;
        }
        break;
    case 6:
        if (gIntroFrameCounter < 310)
        {
            data[1]++;
            SetGpuReg(REG_OFFSET_BG1HOFS, data[1] * 2);
            SetGpuReg(REG_OFFSET_BG2HOFS, data[1]);
            SetGpuReg(REG_OFFSET_BG3HOFS, data[1]);
        }
        else
        {
            ClearGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_BG1_ON
                                              | DISPCNT_BG2_ON
                                              | DISPCNT_BG3_ON);
            data[0]++;
        }
        break;
    case 7:
        if (gIntroFrameCounter == 375)
        {
            BeginNormalPaletteFade(0x00010000, 2, 16, 0, RGB_BLACK);
            data[0]++;
        }
    }
}

static void SpriteCallback_UnownPulse(struct Sprite *sprite)
{
    if (sprite->hFlip)
        sprite->pos1.x += 2;
    else
        sprite->pos1.x -= 2;
    
    if (sprite->vFlip)
        sprite->pos1.y += 2;
    else
        sprite->pos1.y -= 2;
    
    if (sprite->animEnded)
        DestroySprite(sprite);
}

static void intro_reset_and_hide_bgs(void)
{
    SetGpuReg(REG_OFFSET_DISPCNT, 0);
    SetGpuReg(REG_OFFSET_BG3HOFS, 0);
    SetGpuReg(REG_OFFSET_BG3VOFS, 0);
    SetGpuReg(REG_OFFSET_BG2HOFS, 0);
    SetGpuReg(REG_OFFSET_BG2VOFS, 0);
    SetGpuReg(REG_OFFSET_BG1HOFS, 0);
    SetGpuReg(REG_OFFSET_BG1VOFS, 0);
    SetGpuReg(REG_OFFSET_BG0HOFS, 0);
    SetGpuReg(REG_OFFSET_BG0VOFS, 0);
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    SetGpuReg(REG_OFFSET_BLDALPHA, 0);
    SetGpuReg(REG_OFFSET_BLDY, 0);
}

void sub_816F2A8(u16 scrX, u16 scrY, u16 zoom, u16 alpha)
{
    struct BgAffineSrcData src;
    struct BgAffineDstData dest;

    src.texX = 0x8000;
    src.texY = 0x8000;
    src.scrX = scrX;
    src.scrY = scrY;
    src.sx = zoom;
    src.sy = zoom;
    src.alpha = alpha;
    BgAffineSet(&src, &dest, 1);
    SetGpuReg(REG_OFFSET_BG2PA, dest.pa);
    SetGpuReg(REG_OFFSET_BG2PB, dest.pb);
    SetGpuReg(REG_OFFSET_BG2PC, dest.pc);
    SetGpuReg(REG_OFFSET_BG2PD, dest.pd);
    SetGpuReg(REG_OFFSET_BG2X_L, dest.dx);
    SetGpuReg(REG_OFFSET_BG2X_H, dest.dx >> 16);
    SetGpuReg(REG_OFFSET_BG2Y_L, dest.dy);
    SetGpuReg(REG_OFFSET_BG2Y_H, dest.dy >> 16);
}
