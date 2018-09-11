#include "global.h"
#include "main.h"
#include "palette.h"
#include "gpu_regs.h"
#include "bg.h"
#include "rtc.h"
#include "clock.h"
#include "wallclock.h"
#include "event_data.h"
#include "graphics.h"
#include "text.h"
#include "window.h"
#include "text_window.h"
#include "menu.h"
#include "scanline_effect.h"
#include "task.h"
#include "strings.h"
#include "sound.h"
#include "constants/songs.h"
#include "trig.h"
#include "decompress.h"

// static types

#define tMinuteHandAngle data[0]
#define tHourHandAngle   data[1]
#define tHours           data[2]
#define tMinutes         data[3]
#define tMvmtDir         data[4]
#define tPeriod          data[5]
#define tMvmtSpeed       data[6]

#define TAG_GFX_WALL_CLOCK_HAND 0x1000
#define TAG_PAL_WALL_CLOCK_HAND 0x1000

// static declarations

static void WallClockMainCallback(void);
static void Task_SetClock1(u8 taskId);
static void Task_SetClock2(u8 taskId);
static void Task_SetClock3(u8 taskId);
static void Task_SetClock4(u8 taskId);
static void Task_SetClock5(u8 taskId);
static void Task_SetClock6(u8 taskId);
static void Task_ViewClock1(u8 taskId);
static void Task_ViewClock2(u8 taskId);
static void Task_ViewClock3(u8 taskId);
static void Task_ViewClock4(u8 taskId);
static u16 CalcNewMinHandAngle(u16 a0, u8 command, u8 a2);
static bool32 AdvanceClock(u8 taskId, u8 command);
static void UpdateClockPeriod(u8 taskId, u8 command);
static void InitClockWithRtc(u8 taskId);
static void SpriteCB_MinuteHand(struct Sprite *sprite);
static void SpriteCB_HourHand(struct Sprite *sprite);
static void SpriteCB_AMIndicator(struct Sprite *sprite);
static void SpriteCB_PMIndicator(struct Sprite *sprite);

// rodata

static const u8 sUnknown_085B1F58[] = INCBIN_U8("graphics/wallclock/graphics_85b1f58.4bpp.lz");
static const u16 sUnknown_085B21D4[] = INCBIN_U16("graphics/wallclock/palette_85b21d4.gbapal");

static const struct WindowTemplate gUnknown_085B21DC[] = 
{
    {
        .priority = 0,
        .tilemapLeft = 3,
        .tilemapTop = 17,
        .width = 24,
        .height = 2,
        .paletteNum = 14,
        .baseBlock = 512
    },
    {
        .priority = 2,
        .tilemapLeft = 24,
        .tilemapTop = 16,
        .width = 6,
        .height = 2,
        .paletteNum = 12,
        .baseBlock = 560
    },
    DUMMY_WIN_TEMPLATE
};
static const struct WindowTemplate gUnknown_085B21F4 =
{
    .priority = 0,
    .tilemapLeft = 24,
    .tilemapTop = 9,
    .width = 5,
    .height = 4,
    .paletteNum = 14,
    .baseBlock = 572
};
static const struct BgTemplate gUnknown_085B21FC[] = {
    {
        .bg = 0,
        .charBaseIndex = 2,
        .mapBaseIndex = 31,
        .priority = 0
    },
    {
        .bg = 2,
        .charBaseIndex = 1,
        .mapBaseIndex = 8,
        .priority = 1
    },
    {
        .bg = 3,
        .charBaseIndex = 0,
        .mapBaseIndex = 7,
        .priority = 2
    }
};
/*static const struct CompressedSpriteSheet gUnknown_085B2208 = {
    sUnknown_085B1F58, 0x2000, TAG_GFX_WALL_CLOCK_HAND
};
static const u32 filler_85B2210[2] = {};
static const struct SpritePalette gUnknown_085B2218[] = {
    { gWallclockMale_Pal, TAG_PAL_WALL_CLOCK_HAND },
    { gWallclockFemale_Pal, 0x1001 },
    {}
};
static const struct OamData Unknown_085B2230 = {
    .y = 0xa0,
    .size = 3,
    .priority = 1
};
static const union AnimCmd Unknown_085B2238[] = {
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_END
};
static const union AnimCmd Unknown_085B2240[] = {
    ANIMCMD_FRAME(64, 30),
    ANIMCMD_END
};
static const union AnimCmd *const gUnknown_085B2248[] = {
    Unknown_085B2238
};
static const union AnimCmd *const gUnknown_085B224C[] = {
    Unknown_085B2240
};
static const struct SpriteTemplate gUnknown_085B2250 =
{
    .tileTag = TAG_GFX_WALL_CLOCK_HAND,
    .paletteTag = TAG_PAL_WALL_CLOCK_HAND,
    .oam = &Unknown_085B2230,
    .anims = gUnknown_085B2248,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_MinuteHand
};
static const struct SpriteTemplate gUnknown_085B2268 =
{
    .tileTag = TAG_GFX_WALL_CLOCK_HAND,
    .paletteTag = TAG_PAL_WALL_CLOCK_HAND,
    .oam = &Unknown_085B2230,
    .anims = gUnknown_085B224C,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_HourHand
};
static const struct OamData Unknown_085B2280 = {
    .y = 0xa0,
    .size = 1,
    .priority = 3
};
static const union AnimCmd Unknown_085B2288[] = {
    ANIMCMD_FRAME(0x84, 30),
    ANIMCMD_END
};
static const union AnimCmd Unknown_085B2290[] = {
    ANIMCMD_FRAME(0x80, 30),
    ANIMCMD_END
};
static const union AnimCmd *const gUnknown_085B2298[] = {
    Unknown_085B2288
};
static const union AnimCmd *const gUnknown_085B229C[] = {
    Unknown_085B2290
};
static const struct SpriteTemplate gUnknown_085B22A0 =
{
    .tileTag = TAG_GFX_WALL_CLOCK_HAND,
    .paletteTag = TAG_PAL_WALL_CLOCK_HAND,
    .oam = &Unknown_085B2280,
    .anims = gUnknown_085B2298,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_AMIndicator
};
static const struct SpriteTemplate gUnknown_085B22B8 =
{
    .tileTag = TAG_GFX_WALL_CLOCK_HAND,
    .paletteTag = TAG_PAL_WALL_CLOCK_HAND,
    .oam = &Unknown_085B2280,
    .anims = gUnknown_085B229C,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_PMIndicator
};*/

// text

static void WallClockVblankCallback(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void LoadWallClockGraphics(void)
{
    SetVBlankCallback(NULL);
    SetGpuReg(REG_OFFSET_DISPCNT, 0x0000);
    SetGpuReg(REG_OFFSET_BG3CNT, 0x0000);
    SetGpuReg(REG_OFFSET_BG2CNT, 0x0000);
    SetGpuReg(REG_OFFSET_BG1CNT, 0x0000);
    SetGpuReg(REG_OFFSET_BG0CNT, 0x0000);
    ChangeBgX(0, 0, 0);
    ChangeBgY(0, 0, 0);
    ChangeBgX(1, 0, 0);
    ChangeBgY(1, 0, 0);
    ChangeBgX(2, 0, 0);
    ChangeBgY(2, 0, 0);
    ChangeBgX(3, 0, 0);
    ChangeBgY(3, 0, 0);
    DmaFillLarge16(3, 0, (void *)VRAM, VRAM_SIZE, 0x1000);
    DmaClear32(3, (void *)OAM, OAM_SIZE);
    DmaClear16(3, (void *)PLTT, PLTT_SIZE);
    LZ77UnCompVram(gWallclock_Gfx, (void *)VRAM);
    if (gSpecialVar_0x8004 == 0)
    {
        LoadPalette(gWallclockMale_Pal, 0x00, 0x20);
    }
    else
    {
        LoadPalette(gWallclockFemale_Pal, 0x00, 0x20);
    }
    LoadPalette(GetOverworldTextboxPalettePtr(), 0xe0, 0x20);
    LoadPalette(sUnknown_085B21D4, 0xc0, 0x08);
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, gUnknown_085B21FC, 3);
    InitWindows(gUnknown_085B21DC);
    DeactivateAllTextPrinters();
    LoadUserWindowBorderGfx(0, 0x250, 0xd0);
    clear_scheduled_bg_copies_to_vram();
    ScanlineEffect_Stop();
    ResetTasks();
    ResetSpriteData();
    ResetPaletteFade();
    FreeAllSpritePalettes();
    //LoadCompressedObjectPic(&gUnknown_085B2208);
    //LoadSpritePalettes(gUnknown_085B2218);
}

static void WallClockInit(void)
{
    BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, 0);
    EnableInterrupts(INTR_FLAG_VBLANK);
    SetVBlankCallback(WallClockVblankCallback);
    SetMainCallback2(WallClockMainCallback);
    SetGpuReg(REG_OFFSET_BLDCNT, 0x0000);
    SetGpuReg(REG_OFFSET_BLDALPHA, 0x0000);
    SetGpuReg(REG_OFFSET_BLDY, 0x0000);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_1D_MAP | DISPCNT_OBJ_ON);
    ShowBg(0);
    ShowBg(2);
    ShowBg(3);
}

void CB2_StartWallClock(void)
{
    u8 taskId;
    u8 spriteId;

    LoadWallClockGraphics();
    LZ77UnCompVram(gUnknown_08DCC648, (u16 *)BG_SCREEN_ADDR(7));

    taskId = CreateTask(Task_SetClock1, 0);
    gTasks[taskId].tHours = 10;
    gTasks[taskId].tMinutes = 0;
    gTasks[taskId].tMvmtDir = 0;
    gTasks[taskId].tPeriod = 0;
    gTasks[taskId].tMvmtSpeed = 0;
    gTasks[taskId].tMinuteHandAngle = 0;
    gTasks[taskId].tHourHandAngle = 300;

    /*spriteId = CreateSprite(&gUnknown_085B2250, 0x78, 0x50, 1);
    gSprites[spriteId].data[0] = taskId;
    gSprites[spriteId].oam.affineMode = ST_OAM_AFFINE_NORMAL;
    gSprites[spriteId].oam.matrixNum = 0;

    spriteId = CreateSprite(&gUnknown_085B2268, 0x78, 0x50, 0);
    gSprites[spriteId].data[0] = taskId;
    gSprites[spriteId].oam.affineMode = ST_OAM_AFFINE_NORMAL;
    gSprites[spriteId].oam.matrixNum = 1;

    spriteId = CreateSprite(&gUnknown_085B22A0, 0x78, 0x50, 2);
    gSprites[spriteId].data[0] = taskId;
    gSprites[spriteId].data[1] = 45;

    spriteId = CreateSprite(&gUnknown_085B22B8, 0x78, 0x50, 2);
    gSprites[spriteId].data[0] = taskId;
    gSprites[spriteId].data[1] = 90;*/

    WallClockInit();

    PrintTextOnWindow(1, 1, gText_Confirm3, 0, 1, 0, NULL);
    PutWindowTilemap(1);
    schedule_bg_copy_tilemap_to_vram(2);
}

static void WallClockMainCallback(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    do_scheduled_bg_tilemap_copies_to_vram();
    UpdatePaletteFade();
}

static void Task_SetClock1(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        gTasks[taskId].func = Task_SetClock2;
    }
}

static void Task_SetClock2(u8 taskId)
{
    if (gMain.newKeys & A_BUTTON)
    {
        gTasks[taskId].func = Task_SetClock3;
    }
}

static void Task_SetClock3(u8 taskId)
{
    SetWindowBorderStyle(0, FALSE, 0x250, 0x0d);
    PrintTextOnWindow(0, 1, gText_IsThisTheCorrectTime, 0, 1, 0, NULL);
    PutWindowTilemap(0);
    schedule_bg_copy_tilemap_to_vram(0);
    CreateYesNoMenu(&gUnknown_085B21F4, 0x250, 0x0d, 1);
    gTasks[taskId].func = Task_SetClock4;
}

static void Task_SetClock4(u8 taskId)
{
    switch (Menu_ProcessInputNoWrap_())
    {
        case 0:
            PlaySE(SE_SELECT);
            gTasks[taskId].func = Task_SetClock5;
            break;
        case 1:
        case -1:
            PlaySE(SE_SELECT);
            sub_8198070(0, FALSE);
            ClearWindowTilemap(0);
            gTasks[taskId].func = Task_SetClock2;
            break;
    }
}

static void Task_SetClock5(u8 taskId)
{
    RtcInitLocalTimeOffset(gTasks[taskId].tHours, gTasks[taskId].tMinutes);
    BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, 0);
    gTasks[taskId].func = Task_SetClock6;
}

static void Task_SetClock6(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        FreeAllWindowBuffers();
        SetMainCallback2(gMain.savedCallback);
    }
}

static void InitClockWithRtc(u8 taskId)
{
    RtcCalcLocalTime();

}
