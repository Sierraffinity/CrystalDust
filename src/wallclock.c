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
#include "international_string_util.h"
#include "string_util.h"
#include "list_menu.h"
#include "pokegear.h"
#include "constants/rgb.h"

// static types

#define tHours              data[0]
#define tMinutes            data[1]
#define tWhichChanging      data[2]
#define tTwentyFourHourMode data[3]
#define tScrollTaskId       data[4]
#define tScrollOffset       data[5]
#define tBlinkTimer         data[6]

#define TAG_GFX_WALL_CLOCK_HAND 0x1000
#define TAG_PAL_WALL_CLOCK_HAND 0x1000

enum {
    DIGIT_HOURS,
    DIGIT_MINUTESTENS,
    DIGIT_MINUTESONES
};

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
static void ShowHelpBar(void);
static void SpriteCallback_BlinkTwelve(struct Sprite* sprite);
static void SpriteCallback_SetClockDigits(struct Sprite* sprite);
static void AddScrollArrows(u8 taskId);

// rodata
static const struct WindowTemplate gUnknown_085B21DC[] = 
{
    {
        .priority = 0,
        .tilemapLeft = 2,
        .tilemapTop = 15,
        .width = 27,
        .height = 4,
        .paletteNum = 14,
        .baseBlock = 1
    },
    {
        .priority = 0,
        .tilemapLeft = 0,
        .tilemapTop = 0,
        .width = 30,
        .height = 2,
        .paletteNum = 11,
        .baseBlock = 0x70
    },
    {
        .priority = 0,
        .tilemapLeft = 8,
        .tilemapTop = 5,
        .width = 14,
        .height = 3,
        .paletteNum = 14,
        .baseBlock = 0xB0
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
        .charBaseIndex = 0,
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
    LZ77UnCompVram(gSetClock_Gfx, (void *)VRAM);
    LZ77UnCompVram(gSetClock_Map, (u16 *)BG_SCREEN_ADDR(8));
    //LZ77UnCompVram(gPokegear_GridMap, (u16 *)BG_SCREEN_ADDR(7));
    LoadPalette(gSetClock_Pal, 0x00, 0x20);
    LoadPalette(stdpal_get(2), 0xB0, 0x20);
    gPlttBufferUnfaded[0] = RGB_BLACK;
    gPlttBufferFaded[0] = RGB_BLACK;
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, gUnknown_085B21FC, 3);
    InitWindows(gUnknown_085B21DC);
    DeactivateAllTextPrinters();
    LoadMessageBoxGfx(0, 0x200, 0xE0);
    LoadUserWindowBorderGfx(0, 0x250, 0xd0);
    clear_scheduled_bg_copies_to_vram();
    ScanlineEffect_Stop();
    ResetTasks();
    ResetSpriteData();
    ResetPaletteFade();
    FreeAllSpritePalettes();
    LoadSpriteSheet(&sSpriteSheet_DigitTiles);
    LoadSpritePalette(&gSpritePalette_PokegearMenuSprites);

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

#define tTask       data[0]
#define tPosition   data[1]
#define tStoredVal  data[2]

void CB2_StartWallClock(void)
{
    u8 taskId;
    u8 spriteId;
    u8 i;

    static const u8 clockX[6] = {
        92, 106, 114, 123, 137, 149
    };

    const u8 textColor[3] = {
        0x00, 0x02, 0x03
    };

    LoadWallClockGraphics();

    taskId = CreateTask(Task_SetClock1, 0);
    gTasks[taskId].tHours = 10;
    gTasks[taskId].tMinutes = 0;
    gTasks[taskId].tWhichChanging = DIGIT_HOURS;
    gTasks[taskId].tTwentyFourHourMode = FALSE;
    gTasks[taskId].tScrollTaskId = 0xFF;
    gTasks[taskId].tScrollOffset = 0xFFFF;  // dummy value to disable turning off arrows
    gTasks[taskId].tBlinkTimer = 0;

    WallClockInit();
    PutWindowTilemap(2);
    box_print(2, 1, GetStringCenterAlignXOffset(1, gText_SetClock_TimeNotSet, 0x70), 1, textColor, 0, gText_SetClock_TimeNotSet);
    NewMenuHelpers_DrawDialogueFrame(0, TRUE);
    PrintTextOnWindow(0, 1, gText_SetClock_WhatTime, 0, 1, 0, NULL);
    PutWindowTilemap(0);
    CopyWindowToVram(0, 3);

    ShowHelpBar();

    AddScrollArrows(taskId);

    for (i = 0; i < 6; i++)
    {
        spriteId = CreateSprite(&sSpriteTemplate_Digits, clockX[i], 84, 0);
        gSprites[spriteId].callback = SpriteCallback_SetClockDigits;
        gSprites[spriteId].tTask = taskId;
        gSprites[spriteId].tPosition = i;
        gSprites[spriteId].tStoredVal = -1;
        gSprites[spriteId].invisible = TRUE;
    }
}

static void AddScrollArrows(u8 taskId)
{
    const u8 positions[] = {106, 123, 136};

    if (gTasks[taskId].tScrollTaskId != 0xFF)
    {
        RemoveScrollIndicatorArrowPair(gTasks[taskId].tScrollTaskId);
    }

    gTasks[taskId].tScrollTaskId = AddScrollIndicatorArrowPairParameterized(SCROLL_ARROW_UP,
                                                                        positions[gTasks[taskId].tWhichChanging],
                                                                        64,
                                                                        104,
                                                                        0,
                                                                        54545,
                                                                        54545,
                                                                        &(gTasks[taskId].tScrollOffset));
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

static u8 ChangeTimeWithDelta(u8 taskId, s8 delta)
{
    int newValue;

    switch (gTasks[taskId].tWhichChanging)
    {
        case DIGIT_HOURS:
            newValue = gTasks[taskId].tHours + delta;
            if (newValue < 0)
            {
                newValue = 23;
            }
            else if (newValue > 23)
            {
                newValue = 0;
            }
            gTasks[taskId].tHours = newValue;
            break;
        case DIGIT_MINUTESTENS:
            newValue = gTasks[taskId].tMinutes + (delta * 10);
            if (newValue < 0)
            {
                newValue += 60;
            }
            else if (newValue > 59)
            {
                newValue -= 60;
            }
            gTasks[taskId].tMinutes = newValue;
            break;
        case DIGIT_MINUTESONES:
        {
            u8 oldMinutes = gTasks[taskId].tMinutes % 10;
            newValue = oldMinutes + delta;
            if (newValue < 0)
            {
                newValue = 9;
            }
            else if (newValue > 9)
            {
                newValue = 0;
            }
            gTasks[taskId].tMinutes += newValue - oldMinutes;
            break;
        }
    }

    PlaySE(SE_TB_KARA);
}

static u8 ChangeDigitWithDelta(u8 taskId, s8 delta)
{
    int newValue = gTasks[taskId].tWhichChanging + delta;

    if (newValue >= 0 && newValue <= 2)
    {
        gTasks[taskId].tWhichChanging = newValue;
        AddScrollArrows(taskId);
        PlaySE(SE_SELECT);
    }
}

static void Task_SetClock2(u8 taskId)
{
    bool8 shouldStopBlinking = FALSE;

    if (gTasks[taskId].tBlinkTimer >= 60)
    {
        gTasks[taskId].tBlinkTimer = 0;
    }
    else if (gTasks[taskId].tBlinkTimer != -1)
    {
        gTasks[taskId].tBlinkTimer++;
    }

    if (gMain.newKeys & A_BUTTON)
    {
        shouldStopBlinking = TRUE;
        PlaySE(SE_SELECT);
        FillWindowPixelBuffer(0, 0x11);
        StringExpandPlaceholders(gStringVar4, gText_SetClock_IOverslept);
        AddTextPrinterForMessage(1);
        gTasks[taskId].func = Task_SetClock3;
    }
    else if (gMain.newKeys & SELECT_BUTTON)
    {
        gTasks[taskId].tTwentyFourHourMode = !gTasks[taskId].tTwentyFourHourMode;
    }
    else if (gMain.newAndRepeatedKeys & DPAD_UP)
    {
        ChangeTimeWithDelta(taskId, 1);
        shouldStopBlinking = TRUE;
    }
    else if (gMain.newAndRepeatedKeys & DPAD_LEFT)
    {
        ChangeDigitWithDelta(taskId, -1);
    }
    else if (gMain.newAndRepeatedKeys & DPAD_DOWN)
    {
        ChangeTimeWithDelta(taskId, -1);
        shouldStopBlinking = TRUE;
    }
    else if (gMain.newAndRepeatedKeys & DPAD_RIGHT)
    {
        ChangeDigitWithDelta(taskId, 1);
    }

    if (shouldStopBlinking && gTasks[taskId].tBlinkTimer != -1)
    {
        gTasks[taskId].tBlinkTimer = -1;
    }
}

static void Task_SetClock3(u8 taskId)
{
    if (!sub_8197224())
    {
        CreateYesNoMenu(&gUnknown_085B21F4, 0x250, 0x0d, 1);
        gTasks[taskId].func = Task_SetClock4;
    }
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
            //sub_8197434(0, FALSE);
            //ClearWindowTilemap(0);
            FillWindowPixelBuffer(0, 0x11);
            PrintTextOnWindow(0, 1, gText_SetClock_WhatTime, 0, 1, 0, NULL);
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

static void SpriteCallback_SetClockDigits(struct Sprite* sprite)
{
    u8 value;
    s16 *data = gTasks[sprite->tTask].data;

    switch (sprite->tPosition)
    {
        case 0:
            value = tHours;
            if (!tTwentyFourHourMode)
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
            value = tHours;
            if (!tTwentyFourHourMode)
            {
                if (value > 12)
                    value -= 12;
                else if (value == 0)
                    value = 12;
            }
            value = value % 10 + 1;
            break;
        case 2:
            value = 12;
            break;
        case 3:
            value = tMinutes / 10 + 1;
            break;
        case 4:
            value = tMinutes % 10 + 1;
            break;
        case 5:
            if (tTwentyFourHourMode)
                value = 13;
            else if (tHours < 12)
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

    if (tBlinkTimer > 30)
    {
        sprite->invisible = TRUE;
    }
    else
    {
        sprite->invisible = FALSE;
    }
}

static void ShowHelpBar(void)
{
    const u8 color[3] = { 15, 1, 2 };

    FillWindowPixelBuffer(1, 0xFF);
    box_print(1, 0, GetStringRightAlignXOffset(0, gText_LeftRightSelectUpDownChangeAConfirm, 240) - 4, 0, color, 0, gText_LeftRightSelectUpDownChangeAConfirm);
    PutWindowTilemap(1);
    CopyWindowToVram(1, 3);
}
