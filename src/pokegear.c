#include "global.h"
#include "main.h"
#include "pokegear.h"
#include "bg.h"
#include "day_night.h"
#include "gpu_regs.h"
#include "international_string_util.h"
#include "malloc.h"
#include "menu.h"
#include "overworld.h"
#include "palette.h"
#include "scanline_effect.h"
#include "strings.h"
#include "text.h"
#include "text_window.h"
#include "window.h"

#define MENU_FRAME_BASE_TILE_NUM 532
#define MENU_FRAME_PALETTE_NUM 13

// Static RAM declarations

static EWRAM_DATA struct {
    MainCallback callback;
    u16 state;
} *sPokegearStruct = NULL;

// Static ROM declarations

static void CB2_InitPokegear(void);
static void VBlankCB(void);
static void CB2_Pokegear(void);
static void Task_Pokegear1(u8 taskId);
static void Task_Pokegear2(u8 taskId);

// .rodata
static const u16 gBGPals[] = INCBIN_U16("graphics/pokegear/bg.gbapal");
static const u8 gMainTiles[] = INCBIN_U8("graphics/pokegear/main.4bpp.lz");
static const u8 gBackgroundTilemap[] = INCBIN_U8("graphics/pokegear/background.bin.lz");
static const u8 gClockCardTilemap[] = INCBIN_U8("graphics/pokegear/clock.bin.lz");

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

static const struct WindowTemplate sWindowTemplates[] =
{
    { 0, 6, 15, 23, 4, 15, 0x0001 },
    { 0, 10, 2, 14, 3, 15, 0x0060 },
    { 0, 10, 11, 14, 3, 15, 0x0090 },
    DUMMY_WIN_TEMPLATE
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
        sPokegearStruct->callback = callback;
        SetMainCallback2(CB2_InitPokegear);
    }
}

void PokegearScriptHarness(void)
{
	PrepareToStartPokegear(CB2_ReturnToFieldContinueScript);
}

const u8 sTextColor[3] = {
	0x00, 0x02, 0x03
};

void ShowClockCard(void)
{
    const u8 *dayOfWeek = GetDayOfWeekString();

    LZ77UnCompVram(gClockCardTilemap, (void *)(VRAM + 0xF000));
    SetWindowBorderStyle(0, FALSE, MENU_FRAME_BASE_TILE_NUM, MENU_FRAME_PALETTE_NUM);
    PutWindowTilemap(1);
    PutWindowTilemap(2);
    PrintTextOnWindow(0, 1, gText_PokegearInstructions, 0, 1, 0, NULL);
    box_print(1, 1, GetStringCenterAlignXOffset(1, dayOfWeek, 0x70), 5, sTextColor, 0, dayOfWeek);
    box_print(2, 1, GetStringCenterAlignXOffset(1, gText_PokegearSelectToChangeMode, 0x70), 5, sTextColor, 0, gText_PokegearSelectToChangeMode);
    schedule_bg_copy_tilemap_to_vram(0);
}

void ShowMapCard(void)
{
    const u8 *dayOfWeek = GetDayOfWeekString();

    SetWindowBorderStyle(0, FALSE, MENU_FRAME_BASE_TILE_NUM, MENU_FRAME_PALETTE_NUM);
    PutWindowTilemap(1);
    PutWindowTilemap(2);
    PrintTextOnWindow(0, 1, gText_PokegearInstructions, 0, 1, 0, NULL);
    box_print(1, 1, GetStringCenterAlignXOffset(1, dayOfWeek, 0x70), 5, sTextColor, 0, dayOfWeek);
    box_print(2, 1, GetStringCenterAlignXOffset(1, gText_PokegearSelectToChangeMode, 0x70), 5, sTextColor, 0, gText_PokegearSelectToChangeMode);
    schedule_bg_copy_tilemap_to_vram(0);
}

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
    InitWindows(sWindowTemplates);
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
    ShowClockCard();
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

static void Task_Pokegear1(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        if (gMain.newKeys & B_BUTTON)
        {
            
        }
    }
}

static void Task_Pokegear2(u8 taskId)
{
    /*const u8 *dayOfWeek = GetDayOfWeekString();
    u8 offset;

    switch (sPokegearStruct->state)
    {
        case 0:
            SetWindowBorderStyle(0, FALSE, MENU_FRAME_BASE_TILE_NUM, MENU_FRAME_PALETTE_NUM);
            PutWindowTilemap(1);
            PutWindowTilemap(2);
            //offset = GetStringCenterAlignXOffset(1, gText_Hoenn, 0x38);
            PrintTextOnWindow(0, 1, gText_PokegearInstructions, 0, 1, 0, NULL);
            box_print(1, 1, GetStringCenterAlignXOffset(1, dayOfWeek, 0x70), 5, sTextColor, 0, dayOfWeek);
            box_print(2, 1, GetStringCenterAlignXOffset(1, gText_PokegearSelectToChangeMode, 0x70), 5, sTextColor, 0, gText_PokegearSelectToChangeMode);
            schedule_bg_copy_tilemap_to_vram(0);
            //SetWindowBorderStyle(0, FALSE, MENU_FRAME_BASE_TILE_NUM, MENU_FRAME_PALETTE_NUM);
            //PrintRegionMapSecName();
            sPokegearStruct->state++;
            break;
        case 1:
            SetGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_OBJ_1D_MAP | DISPCNT_OBJ_ON);
            ShowBg(0);
            ShowBg(1);
            ShowBg(3);
            sPokegearStruct->state++;
            break;
        case 2:
            if (!gPaletteFade.active)
            {
                sPokegearStruct->state++;
            }
            break;
        case 3:
            switch (sub_81230AC())
            {
                case INPUT_EVENT_MOVE_END:
                    PrintRegionMapSecName();
                    break;
                case INPUT_EVENT_A_BUTTON:
                case INPUT_EVENT_B_BUTTON:
                    sPokegearStruct->state++;
                    break;
            }
            break;
        case 4:
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 0x10, 0);
            sPokegearStruct->state++;
            break;
        case 5:
            if (!gPaletteFade.active)
            {
                //FreeRegionMapIconResources();
                SetMainCallback2(sPokegearStruct->callback);
                if (sPokegearStruct != NULL)
                {
                    free(sPokegearStruct);
                    sPokegearStruct = NULL;
                }
                FreeAllWindowBuffers();
            }
            break;
    }*/
}
