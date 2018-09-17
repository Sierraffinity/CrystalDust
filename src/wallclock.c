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
#include "day_night.h"
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
    DIGIT_MINUTES
};

// static declarations

static void WallClockMainCallback(void);
static void Task_SetClock1(u8 taskId);
static void Task_SetClock2(u8 taskId);
static void Task_SetClock3(u8 taskId);
static void Task_SetClock4(u8 taskId);
static void Task_SetClock5(u8 taskId);
static void Task_SetClock6(u8 taskId);
static void Task_SetClock7(u8 taskId);
static void ShowHelpBar(const u8 *string);
static void SpriteCallback_SetClockDigits(struct Sprite* sprite);
static void AddScrollArrows(u8 taskId);
static void RemoveScrollArrows(u8 taskId);
static void UpdateBlinkTimer(u8 taskId);

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
        .tilemapLeft = 5,
        .tilemapTop = 5,
        .width = 19,
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

#define tPosition   data[0]
#define tStoredVal  data[1]
#define tTask       data[2]

static const u8 sTextColor[3] = {
    0x00, 0x02, 0x03
};

void CB2_StartWallClock(void)
{
    u8 taskId;
    u8 spriteId;
    u8 i;

    static const u8 clockX[6] = {
        89, 103, 111, 120, 134, 146
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
    FillWindowPixelBuffer(2, 0x00);
    AddTextPrinterParameterized3(2, 1, GetStringCenterAlignXOffset(1, gText_SetClock_TimeNotSet, 0x98), 1, sTextColor, 0, gText_SetClock_TimeNotSet);
    NewMenuHelpers_DrawDialogueFrame(0, TRUE);
    AddTextPrinterParameterized(0, 1, gText_SetClock_WhatTime, 0, 1, 0, NULL);
    PutWindowTilemap(0);
    CopyWindowToVram(0, 3);

    ShowHelpBar(gText_LeftRightSelectUpDownChangeAConfirm);

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
    const u8 positions[] = {96, 126};

    RemoveScrollArrows(taskId);

    gTasks[taskId].tScrollTaskId = AddScrollIndicatorArrowPairParameterized(SCROLL_ARROW_UP,
                                                                        positions[gTasks[taskId].tWhichChanging],
                                                                        64,
                                                                        104,
                                                                        0,
                                                                        54545,
                                                                        54545,
                                                                        &(gTasks[taskId].tScrollOffset));
}

static void RemoveScrollArrows(u8 taskId)
{
    if (gTasks[taskId].tScrollTaskId != 0xFF)
    {
        RemoveScrollIndicatorArrowPair(gTasks[taskId].tScrollTaskId);
    }
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
    UpdateBlinkTimer(taskId);
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
        case DIGIT_MINUTES:
            newValue = gTasks[taskId].tMinutes + delta;
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
    }

    PlaySE(SE_TB_KARA);
}

static u8 ChangeDigitWithDelta(u8 taskId, s8 delta)
{
    int newValue = gTasks[taskId].tWhichChanging + delta;

    if (newValue >= 0 && newValue <= 1)
    {
        gTasks[taskId].tWhichChanging = newValue;
        AddScrollArrows(taskId);
        PlaySE(SE_SELECT);
    }
}

static u8 *BufferTimeString(u8 *dest, u8 hours, u8 minutes, bool8 twentyFourHourMode)
{
    if (!twentyFourHourMode)
    {
        if (hours == 0)
        {
            hours = 12;
        }
        else if (hours > 12)
        {
            hours -= 12;
        }
    }

    dest = ConvertIntToDecimalStringN(dest, hours, STR_CONV_MODE_LEFT_ALIGN, (hours >= 10) ? 2 : 1);
    *dest++ = CHAR_COLON;
    dest = ConvertIntToDecimalStringN(dest, minutes, STR_CONV_MODE_LEADING_ZEROS, 2);
    *dest = EOS;

    return dest;
}

static void Task_SetClock2_1(u8 taskId)
{
    if (!RunTextPrintersAndIsPrinter0Active())
    {
        AddScrollArrows(taskId);
        gTasks[taskId].func = Task_SetClock2;
    }
}

static void UpdateBlinkTimer(u8 taskId)
{
    if (gTasks[taskId].tBlinkTimer >= 60)
    {
        gTasks[taskId].tBlinkTimer = 0;
    }
    else if (gTasks[taskId].tBlinkTimer != -1)
    {
        gTasks[taskId].tBlinkTimer++;
    }
}

static void Task_SetClock2(u8 taskId)
{
    bool8 shouldStopBlinking = FALSE;

    UpdateBlinkTimer(taskId);

    if (gMain.newKeys & A_BUTTON)
    {
        u8 *string;
        shouldStopBlinking = TRUE;
        PlaySE(SE_SELECT);

        RemoveScrollArrows(taskId);

        string = BufferTimeString(gStringVar1, gTasks[taskId].tHours, gTasks[taskId].tMinutes, gTasks[taskId].tTwentyFourHourMode);

        if (!gTasks[taskId].tTwentyFourHourMode)
        {
            *string++ = CHAR_SPACE;
            if (gTasks[taskId].tHours < 12)
            {
                *string++ = CHAR_A;
            }
            else
            {
                *string++ = CHAR_P;
            }
            *string++ = CHAR_M;
            *string = EOS;
        }

        ShowHelpBar(gText_UpDownPickAOk);
        FillWindowPixelBuffer(0, 0x11);
        StringExpandPlaceholders(gStringVar4, gText_SetClock_Whoa);
        AddTextPrinterForMessage(1);
        gTasks[taskId].func = Task_SetClock3;
    }
    else if (gMain.newKeys & SELECT_BUTTON)
    {
        gTasks[taskId].tTwentyFourHourMode = !gTasks[taskId].tTwentyFourHourMode;
        PlaySE(SE_SELECT);
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
    if (!RunTextPrintersAndIsPrinter0Active())
    {
        CreateYesNoMenu(&gUnknown_085B21F4, 0x250, 13, 0);
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
            ShowHelpBar(gText_LeftRightSelectUpDownChangeAConfirm);
            //sub_8197434(0, FALSE);
            //ClearWindowTilemap(0);
            FillWindowPixelBuffer(0, 0x11);
            StringExpandPlaceholders(gStringVar4, gText_SetClock_WhatTime);
            AddTextPrinterForMessage(1);
            gTasks[taskId].func = Task_SetClock2_1;
            break;
    }
}

static void Task_SetClock5(u8 taskId)
{
    static const u8 *const timeOfDayStrings[] = {gText_SetClock_InTheMorning, gText_SetClock_InTheAfternoon, gText_SetClock_InTheEvening, gText_SetClock_AtNight};
    const u8 *string = NULL;
    u8 *dest = gStringVar1;

    gTasks[taskId].tBlinkTimer = -2;

    ShowHelpBar(gText_ANext);
    
    RtcInitLocalTimeOffset(gTasks[taskId].tHours, gTasks[taskId].tMinutes);
    FillWindowPixelBuffer(2, 0x00);
    AddTextPrinterParameterized3(2, 1, GetStringCenterAlignXOffset(1, gText_SetClock_TimeSet, 0x98), 1, sTextColor, 0, gText_SetClock_TimeSet);
    
    if (gTasks[taskId].tMinutes == 0)
    {
        if (gTasks[taskId].tHours == 0)
        {
            string = gText_SetClock_Midnight;
        }
        else if (gTasks[taskId].tHours == 12)
        {
            string = gText_SetClock_Noon;
        }
        else
        {
            u8 hours = gTasks[taskId].tHours;

            if (!gTasks[taskId].tTwentyFourHourMode)
            {
                if (hours == 0)
                {
                    hours = 12;
                }
                else if (hours > 12)
                {
                    hours -= 12;
                }
            }

            dest = ConvertIntToDecimalStringN(dest, hours, STR_CONV_MODE_LEFT_ALIGN, (hours >= 10) ? 2 : 1);
            *dest++ = CHAR_SPACE;
        }
    }
    else
    {
        dest = BufferTimeString(dest, gTasks[taskId].tHours, gTasks[taskId].tMinutes, gTasks[taskId].tTwentyFourHourMode);
        *dest++ = CHAR_SPACE;
    }
    
    if (string == NULL)
    {
        if (gTasks[taskId].tHours < 12)
        {
            string = gText_SetClock_InTheMorning;
        }
        else if (gTasks[taskId].tHours < TIME_AFTERNOON_HOUR)
        {
            string = gText_SetClock_InTheAfternoon;
        }
        else if (gTasks[taskId].tHours < TIME_NIGHT_HOUR)
        {
            string = gText_SetClock_InTheEvening;
        }
        else
        {
            string = gText_SetClock_AtNight;
        }
    }

    StringCopy(dest, string);

    if (gTasks[taskId].tHours < TIME_MORNING_HOUR)
    {
        string = gText_SetClock_SoDark;
    }
    else if (gTasks[taskId].tHours < TIME_DAY_HOUR + 1)
    {
        string = gText_SetClock_IOverslept;
    }
    else if (gTasks[taskId].tHours < TIME_NIGHT_HOUR)
    {
        string = gText_SetClock_YikesIOverslept;
    }
    else
    {
        string = gText_SetClock_SoDark;
    }
    
    FillWindowPixelBuffer(0, 0x11);
    StringExpandPlaceholders(gStringVar4, string);
    AddTextPrinterForMessage(1);
    gTasks[taskId].func = Task_SetClock6;
}

static void Task_SetClock6(u8 taskId)
{
    RtcCalcLocalTime();
    if (!RunTextPrintersAndIsPrinter0Active() && gMain.newKeys & (A_BUTTON | B_BUTTON))
    {
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, 0);
        gTasks[taskId].func = Task_SetClock7;
    }
}

static void Task_SetClock7(u8 taskId)
{
    RtcCalcLocalTime();
    if (!gPaletteFade.active)
    {
        FreeAllWindowBuffers();
        SetMainCallback2(gMain.savedCallback);
    }
}

static void SpriteCB_ClockDigits(struct Sprite* sprite)
{
    u8 value;
    s16 *data = gTasks[sprite->tTask].data;

    switch (sprite->tPosition)
    {
        case 0:
            value = gLocalTime.hours;
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
            value = gLocalTime.hours;
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
            if (tTwentyFourHourMode)
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

    if (tBlinkTimer == -2)
    {
        sprite->callback = SpriteCB_ClockDigits;
    }
}

static void ShowHelpBar(const u8 *string)
{
    const u8 color[3] = { 15, 1, 2 };

    FillWindowPixelBuffer(1, 0xFF);
    AddTextPrinterParameterized3(1, 0, GetStringRightAlignXOffset(0, string, 240) - 4, 0, color, 0, string);
    PutWindowTilemap(1);
    CopyWindowToVram(1, 3);
}
