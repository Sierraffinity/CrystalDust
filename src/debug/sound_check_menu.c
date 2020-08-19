#include "global.h"
#include "bg.h"
#include "sprite.h"
#include "palette.h"
#include "task.h"
#include "m4a.h"
#include "main.h"
#include "text.h"
#include "menu.h"
#include "gpu_regs.h"
#include "scanline_effect.h"
#include "string_util.h"
#include "constants/rgb.h"
#include "constants/songs.h"
#include "title_screen.h"
#include "sound.h"
#include "trainer_pokemon_sprites.h"

#define tWindowSelected data[0]
#define tBgmIndex data[1]
#define tSeIndex data[2]
#define tBgmIndexOld data[3]
#define tSeIndexOld data[4]
#define tWhichSubmenu data[14]
#define tState data[15]

// wonky dim access macro
#define MULTI_DIM_ARR(x, dim, y) ((x) * dim + (y))

// dim access enums
enum
{
    B_8 = 1,
    B_16 = 2,
    B_32 = 4
};

// windows
enum
{
    WIN_INFO,
    WIN_MUS,
    WIN_SE,
    WIN_COUNT
};

// selected test
enum
{
    TEST_MUS,
    TEST_SE
};

// driver test cry enums
enum
{
    CRY_TEST_VOICE,
    CRY_TEST_VOLUME,
    CRY_TEST_PANPOT,
    CRY_TEST_PITCH,
    CRY_TEST_LENGTH,
    CRY_TEST_RELEASE,
    CRY_TEST_PROGRESS,
    CRY_TEST_CHORUS,
    CRY_TEST_PRIORITY
};

// minmax range enums
enum
{
    MIN,
    MAX
};

extern struct ToneData gCryTable[];
extern struct ToneData gCryTable2[];

static EWRAM_DATA u8 sIsFastForwarding = 0;
static EWRAM_DATA u8 sDriverTest_IsCryPlaying = 0;
static EWRAM_DATA u8 sDriverTest_IsCryPlayingOld = 0;
static EWRAM_DATA int sSoundTestParams[9] = {0};
static EWRAM_DATA u8 sDriverTest_Reverse = 0;
static EWRAM_DATA u8 sDriverTest_Stereo = 0;

struct MusicPlayerInfo *sMPlayInfo_Cry;
extern struct MusicPlayerInfo gMPlayInfo_BGM;

static const struct BgTemplate sSoundCheckMenuBgTemplates[] =
{
    {
        .bg = 0,
        .charBaseIndex = 0,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    },
};

static const struct WindowTemplate sSoundCheckMenuWindowTemplates[] =
{
    {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 1,
        .width = 28,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 20,
    },
    {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 8,
        .width = 28,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 132,
    },
    {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 15,
        .width = 28,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 244,
    },
    DUMMY_WIN_TEMPLATE,
};

static const struct WindowTemplate sSoundCheckMenuDriverTestWindowTemplates[] =
{
    {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 1,
        .width = 28,
        .height = 18,
        .paletteNum = 15,
        .baseBlock = 20,
    },
    DUMMY_WIN_TEMPLATE,
};

static void Task_InitSoundCheckMenu(u8 taskId);
static void Task_InitSoundCheckMenu_CreateWindows(u8);
static void Task_HandleDrawingSoundCheckMenuText(u8);
static void Task_ProcessSoundCheckMenuInputAndRedraw(u8);
static void Task_ExitToTitleScreen(u8);
static void HighlightSelectedWindow(u8);
static void PrintSoundNumber(u16, u8);
static void PrintPaddedString(const u8 *const, u8);
static void Task_DrawSubmenu(u8);
static void Task_ProcessDriverTestInput(u8);
static void AdjustSelectedDriverParam(s8);
static void PrintDriverTestMenuText(void);
static void PrintSignedNumber(int, u16, u16, u8);
static void Task_DrawDriverTestMenu(u8);
static void Task_DrawPanTestMenu(u8);
static void Task_ProcessPanTestInput(u8);
static void PrintPanTestMenuText(void);
static void InitGpuRegs(void);
static void ClearTasksAndGraphicalStructs(void);
static void SetupDispcnt(void);
static void DestroyWindow(u8 windowId);
static void PutWindowTilemapAndCopyWindowToVram(u8 windowId);

static void CB2_SoundCheckMenu(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

static void VBlankCB_SoundCheckMenu(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();

    if (sIsFastForwarding != 0)
    {
        m4aSoundMain();
        m4aSoundMain();
        m4aSoundMain();
    }
}

void CB2_StartSoundCheckMenu(void) // sub_080E8320
{
    u8 taskId;

    switch (gMain.state)
    {
    case 0:
        SetVBlankCallback(NULL);
        InitGpuRegs();
        gMain.state++;
        break;
    case 1:
        ClearTasksAndGraphicalStructs();
        gMain.state++;
        break;
    case 2:
        ResetBgsAndClearDma3BusyFlags(0);
        InitBgsFromTemplates(0, sSoundCheckMenuBgTemplates, ARRAY_COUNT(sSoundCheckMenuBgTemplates));
        ResetBgPositions();
        gMain.state++;
        break;
    case 3:
        if (IsDma3ManagerBusyWithBgCopy() == TRUE)
            return;
        ShowBg(0);
        gMain.state++;
        break;
    case 4:
        InitWindows(sSoundCheckMenuWindowTemplates);
        DeactivateAllTextPrinters();
        LoadMessageBoxAndBorderGfx();
        gMain.state++;
        break;
    case 5:
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, RGB(0, 0, 0));
        gMain.state++;
        break;
    case 6:
        SetupDispcnt();
        SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG0 |
                                    WININ_WIN0_OBJ |
                                    WININ_WIN1_BG0 |
                                    WININ_WIN1_OBJ);
        SetGpuReg(REG_OFFSET_WINOUT, WINOUT_WIN01_BG0 |
                                     WINOUT_WIN01_OBJ |
                                     WINOUT_WIN01_CLR);
        SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG0 |
                                     BLDCNT_TGT1_BD |
                                     BLDCNT_EFFECT_DARKEN);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        SetGpuReg(REG_OFFSET_BLDY, 7);
        EnableInterrupts(INTR_FLAG_VBLANK);
        SetVBlankCallback(VBlankCB_SoundCheckMenu);
        SetMainCallback2(CB2_SoundCheckMenu);
        taskId = CreateTask(Task_InitSoundCheckMenu_CreateWindows, 0);
        gTasks[taskId].tWindowSelected = TEST_MUS;
        gTasks[taskId].tBgmIndex = 0;
        gTasks[taskId].tSeIndex = 0;
        gTasks[taskId].tBgmIndexOld = 0;
        gTasks[taskId].tSeIndexOld = 0;
        sIsFastForwarding = 0;
        m4aSoundInit();
        gMain.state++;
        break;
    }
}

static void Task_InitSoundCheckMenu_CreateWindows(u8 taskId) // SanitizeDayCareMailForRuby
{
    const u8 soundcheckStr[] = _("SOUND TEST  A: PLAY  B: EXIT");
    const u8 bgmStr[] = _("MUSIC");
    const u8 seStr[] = _("SOUND EFFECTS");
    const u8 upDownStr[] = _("{LEFT_ARROW}DOWN {RIGHT_ARROW}UP");
    const u8 driverStr[] = _("R: CRY TEST");

    if (!gPaletteFade.active)
    {
        SetStandardWindowBorderStyle(WIN_INFO, FALSE);
        AddTextPrinterParameterized(WIN_INFO, 1, soundcheckStr, 0, 0, TEXT_SPEED_FF, NULL);
        AddTextPrinterParameterized(WIN_INFO, 1, driverStr, 100, 14, TEXT_SPEED_FF, NULL);
        PutWindowTilemapAndCopyWindowToVram(WIN_INFO);
        SetStandardWindowBorderStyle(WIN_MUS, FALSE);
        AddTextPrinterParameterized(WIN_MUS, 1, bgmStr, 0, 0, TEXT_SPEED_FF, NULL);
        AddTextPrinterParameterized(WIN_MUS, 1, upDownStr, 100, 0, TEXT_SPEED_FF, NULL);
        PutWindowTilemapAndCopyWindowToVram(WIN_MUS);
        SetStandardWindowBorderStyle(WIN_SE, FALSE);
        AddTextPrinterParameterized(WIN_SE, 1, seStr, 0, 0, TEXT_SPEED_FF, NULL);
        AddTextPrinterParameterized(WIN_SE, 1, upDownStr, 100, 0, TEXT_SPEED_FF, NULL);
        PutWindowTilemapAndCopyWindowToVram(WIN_SE);
        SetGpuReg(REG_OFFSET_WIN0H, WIN_RANGE(0, 239));
        SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE(0, 48));
        HighlightSelectedWindow(WIN_INFO);
        gTasks[taskId].func = Task_HandleDrawingSoundCheckMenuText;
    }
}

static const u8 *const gBGMNames[];
static const u8 *const gSENames[];

static void Task_HandleDrawingSoundCheckMenuText(u8 taskId) // sub_080E85F4
{
    FillWindowPixelRect(WIN_MUS, PIXEL_FILL(1), 0, 14, 224, 12);
    PrintSoundNumber(gTasks[taskId].tBgmIndex + (MUS_TETSUJI - 1), WIN_MUS); // print by BGM index
    PrintPaddedString(gBGMNames[gTasks[taskId].tBgmIndex], WIN_MUS);
    FillWindowPixelRect(WIN_SE, PIXEL_FILL(1), 0, 14, 224, 12);
    PrintSoundNumber(gTasks[taskId].tSeIndex, WIN_SE);
    PrintPaddedString(gSENames[gTasks[taskId].tSeIndex], WIN_SE);
    gTasks[taskId].func = Task_ProcessSoundCheckMenuInputAndRedraw;
}

static bool8 Task_ProcessSoundCheckMenuInput(u8 taskId) // sub_080E8688
{
    if (gMain.newKeys & R_BUTTON) // driver test
    {
        gTasks[taskId].tWhichSubmenu = 1;
        gTasks[taskId].tState = 0;
        gTasks[taskId].func = Task_DrawSubmenu;
    }
    else if (gMain.newKeys & L_BUTTON)
    {
        gTasks[taskId].tWhichSubmenu = 0;
        gTasks[taskId].tState = 0;
        gTasks[taskId].func = Task_DrawSubmenu;
    }
    else if (gMain.newKeys & A_BUTTON)
    {
        if (gTasks[taskId].tWindowSelected != TEST_MUS)
        {
            if (gTasks[taskId].tSeIndexOld != 0)
            {
                if (gTasks[taskId].tSeIndex != 0)
                {
                    m4aSongNumStop(gTasks[taskId].tSeIndexOld);
                    m4aSongNumStart(gTasks[taskId].tSeIndex);
                    gTasks[taskId].tSeIndexOld = gTasks[taskId].tSeIndex;
                }
                else
                {
                    m4aSongNumStop(gTasks[taskId].tSeIndexOld);
                    gTasks[taskId].tSeIndexOld = 0;
                }
            }
            else if (gTasks[taskId].tSeIndex != 0)
            {
                m4aSongNumStart(gTasks[taskId].tSeIndex);
                gTasks[taskId].tSeIndexOld = gTasks[taskId].tSeIndex;
            }
        }
        else
        {
            if (gTasks[taskId].tBgmIndexOld != 0)
            {
                if (gTasks[taskId].tBgmIndex != 0)
                {
                    m4aSongNumStop(gTasks[taskId].tBgmIndexOld + (MUS_TETSUJI - 1));
                    m4aSongNumStart(gTasks[taskId].tBgmIndex + (MUS_TETSUJI - 1));
                    gTasks[taskId].tBgmIndexOld = gTasks[taskId].tBgmIndex;
                }
                else
                {
                    m4aSongNumStop(gTasks[taskId].tBgmIndexOld + (MUS_TETSUJI - 1));
                    gTasks[taskId].tBgmIndexOld = 0;
                }
            }
            else if (gTasks[taskId].tBgmIndex != 0)
            {
                m4aSongNumStart(gTasks[taskId].tBgmIndex + (MUS_TETSUJI - 1));
                gTasks[taskId].tBgmIndexOld = gTasks[taskId].tBgmIndex;
            }
        }
    }
    else if (gMain.newKeys & B_BUTTON)
    {
        m4aSongNumStart(SE_SELECT);
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB(0, 0, 0));
        gTasks[taskId].func = Task_ExitToTitleScreen;
    }
    else if (gMain.newAndRepeatedKeys & (DPAD_UP | DPAD_DOWN))
    {
        gTasks[taskId].tWindowSelected ^= 1;
        HighlightSelectedWindow(gTasks[taskId].tWindowSelected);
        return FALSE;
    }
    else if (gMain.newAndRepeatedKeys & DPAD_LEFT)
    {
        if (gTasks[taskId].tWindowSelected != TEST_MUS)
        {
            if (gTasks[taskId].tSeIndex > 0)
                gTasks[taskId].tSeIndex--;
            else
                gTasks[taskId].tSeIndex = SE_USSOKI;
        }
        else
        {
            if (gTasks[taskId].tBgmIndex > 0)
                gTasks[taskId].tBgmIndex--;
            else
                gTasks[taskId].tBgmIndex = (PH_NURSE_SOLO - (MUS_TETSUJI - 1));
        }
        return TRUE;
    }
    else if (gMain.newAndRepeatedKeys & DPAD_RIGHT)
    {
        if (gTasks[taskId].tWindowSelected != TEST_MUS)
        {
            if (gTasks[taskId].tSeIndex < SE_USSOKI)
                gTasks[taskId].tSeIndex++;
            else
                gTasks[taskId].tSeIndex = 0;
        }
        else
        {
            if (gTasks[taskId].tBgmIndex < (PH_NURSE_SOLO - (MUS_TETSUJI - 1)))
                gTasks[taskId].tBgmIndex++;
            else
                gTasks[taskId].tBgmIndex = 0;
        }
        return TRUE;
    }
    else if (gMain.heldKeys & SELECT_BUTTON)
    {
        sIsFastForwarding = 1;
    }
    else
    {
        sIsFastForwarding = 0;
    }
    return FALSE;
}

static void Task_ProcessSoundCheckMenuInputAndRedraw(u8 taskId) // sub_080E8878
{
    if (Task_ProcessSoundCheckMenuInput(taskId) != FALSE)
        gTasks[taskId].func = Task_HandleDrawingSoundCheckMenuText;
}

static void Task_ExitToTitleScreen(u8 taskId) // sub_080E88A8
{
    u8 windowId;

    if (!gPaletteFade.active)
    {
        for (windowId = WIN_INFO; windowId < WIN_COUNT; windowId++)
        {
            DestroyWindow(windowId);
        }
        DestroyTask(taskId);
        SetMainCallback2(CB2_InitTitleScreen);
    }
}

static void HighlightSelectedWindow(u8 windowType) // sub_080E88E8
{
    switch (windowType)
    {
    case WIN_INFO:
        SetGpuReg(REG_OFFSET_WIN1H, WIN_RANGE(0, 239));
        SetGpuReg(REG_OFFSET_WIN1V, WIN_RANGE(56, 104));
        break;
    case WIN_MUS:
        SetGpuReg(REG_OFFSET_WIN1H, WIN_RANGE(0, 239));
        SetGpuReg(REG_OFFSET_WIN1V, WIN_RANGE(112, 160));
        break;
    }
}

static void PrintSoundNumber(u16 soundIndex, u8 windowId) // sub_080E8928
{
    ConvertIntToDecimalStringN(gStringVar1, soundIndex, STR_CONV_MODE_RIGHT_ALIGN, 3);
    
    gStringVar1[3] = CHAR_COLON;
    gStringVar1[4] = EOS;
    
    AddTextPrinterParameterized(windowId, 1, gStringVar1, 0, 14, TEXT_SPEED_FF, NULL);
    PutWindowTilemapAndCopyWindowToVram(windowId);
}

static void PrintPaddedString(const u8 *const string, u8 windowId) // sub_080E8978
{
    u8 i;
    u8 str[16];

    for (i = 0; i < 15; i++)
        str[i] = CHAR_SPACE; // pad string.

    str[15] = EOS;

    for (i = 0; string[i] != EOS && i < 15; i++)
        str[i] = string[i];

    AddTextPrinterParameterized(windowId, 1, str, 40, 14, TEXT_SPEED_FF, NULL);
    PutWindowTilemapAndCopyWindowToVram(windowId);
}

static void Task_DrawSubmenu(u8 taskId) // sub_080E89EC
{
    u8 windowId;

    switch (gTasks[taskId].tState)
    {
    case 0:
        for (windowId = WIN_INFO; windowId < WIN_COUNT; windowId++)
        {
            DestroyWindow(windowId);
        }
        FreeAllWindowBuffers();
        ResetBgsAndClearDma3BusyFlags(0);
        InitBgsFromTemplates(0, sSoundCheckMenuBgTemplates, ARRAY_COUNT(sSoundCheckMenuBgTemplates));
        gTasks[taskId].tState++;
        break;
    case 1:
        if (IsDma3ManagerBusyWithBgCopy() == TRUE)
            return;
        InitWindows(sSoundCheckMenuDriverTestWindowTemplates);
        SetStandardWindowBorderStyle(0, TRUE);
        gTasks[taskId].tState++;
        break;
    case 2:
        ShowBg(0);
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 |
                                      DISPCNT_OBJ_1D_MAP |
                                      DISPCNT_BG0_ON |
                                      DISPCNT_OBJ_ON |
                                      DISPCNT_WIN0_ON);
        if (gTasks[taskId].tWhichSubmenu == 0)
        {
            gTasks[taskId].func = Task_DrawPanTestMenu;
        }
        else
        {
            gTasks[taskId].func = Task_DrawDriverTestMenu;
        }
        break;
    }
}

static void Task_DrawDriverTestMenu(u8 taskId) // sub_080E8AA0
{
    const u8 bbackStr[] = _("B BUTTON: BACK");
    const u8 aplayStr[] = _("A BUTTON: PLAY");
    const u8 voiceStr[] = _("VOICE…………");
    const u8 volumeStr[] = _("VOLUME………");
    const u8 panpotStr[] = _("PANPOT………");
    const u8 pitchStr[] = _("PITCH…………");
    const u8 lengthStr[] = _("LENGTH………");
    const u8 releaseStr[] = _("RELEASE……");
    const u8 progressStr[] = _("PROGRESS…");
    const u8 chorusStr[] = _("CHORUS………");
    const u8 priorityStr[] = _("PRIORITY…");
    const u8 playingStr[] = _("PLAYING");
    const u8 reverseStr[] = _("REVERSE");
    const u8 stereoStr[] = _("STEREO");

    SetStandardWindowBorderStyle(WIN_INFO, FALSE);
    AddTextPrinterParameterized(WIN_INFO, 1, bbackStr, 136, 16, TEXT_SPEED_FF, NULL);
    AddTextPrinterParameterized(WIN_INFO, 1, aplayStr, 136, 32, TEXT_SPEED_FF, NULL);
    AddTextPrinterParameterized(WIN_INFO, 1, playingStr, 136, 80, TEXT_SPEED_FF, NULL);
    AddTextPrinterParameterized(WIN_INFO, 1, reverseStr, 136, 96, TEXT_SPEED_FF, NULL);
    AddTextPrinterParameterized(WIN_INFO, 1, stereoStr, 136, 112, TEXT_SPEED_FF, NULL);
    AddTextPrinterParameterized(WIN_INFO, 1, voiceStr, 8, 0, TEXT_SPEED_FF, NULL);
    AddTextPrinterParameterized(WIN_INFO, 1, volumeStr, 8, 16, TEXT_SPEED_FF, NULL);
    AddTextPrinterParameterized(WIN_INFO, 1, panpotStr, 8, 32, TEXT_SPEED_FF, NULL);
    AddTextPrinterParameterized(WIN_INFO, 1, pitchStr, 8, 48, TEXT_SPEED_FF, NULL);
    AddTextPrinterParameterized(WIN_INFO, 1, lengthStr, 8, 64, TEXT_SPEED_FF, NULL);
    AddTextPrinterParameterized(WIN_INFO, 1, releaseStr, 8, 80, TEXT_SPEED_FF, NULL);
    AddTextPrinterParameterized(WIN_INFO, 1, progressStr, 8, 96, TEXT_SPEED_FF, NULL);
    AddTextPrinterParameterized(WIN_INFO, 1, chorusStr, 8, 112, TEXT_SPEED_FF, NULL);
    AddTextPrinterParameterized(WIN_INFO, 1, priorityStr, 8, 128, TEXT_SPEED_FF, NULL);
    SetGpuReg(REG_OFFSET_WIN0H, WIN_RANGE(0, DISPLAY_WIDTH));
    SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE(0, DISPLAY_HEIGHT));
    sDriverTest_IsCryPlaying = 0;
    sDriverTest_IsCryPlayingOld = 0;
    sMPlayInfo_Cry = NULL;
    sDriverTest_Reverse = 0;
    sDriverTest_Stereo = 1;
    sSoundTestParams[CRY_TEST_VOICE] = 0;
    sSoundTestParams[CRY_TEST_VOLUME] = 120;
    sSoundTestParams[CRY_TEST_PANPOT] = 0;
    sSoundTestParams[CRY_TEST_PITCH] = 15360;
    sSoundTestParams[CRY_TEST_LENGTH] = 180;
    sSoundTestParams[CRY_TEST_PROGRESS] = 0;
    sSoundTestParams[CRY_TEST_RELEASE] = 0;
    sSoundTestParams[CRY_TEST_CHORUS] = 0;
    sSoundTestParams[CRY_TEST_PRIORITY] = 2;
    PrintDriverTestMenuText();
    sub_81983AC(WIN_INFO, 1, 0, 0, 16, 9, 0);
    gTasks[taskId].func = Task_ProcessDriverTestInput;
}

static void Task_ProcessDriverTestInput(u8 taskId) // sub_080E8D68
{
    if (gMain.newKeys & B_BUTTON)
    {
        gTasks[taskId].tState = 0;
        gTasks[taskId].func = Task_InitSoundCheckMenu;
        return;
    }
    if (gMain.newAndRepeatedKeys & DPAD_UP)
    {
        Menu_MoveCursorNoWrapAround(-1);
        return;
    }
    if (gMain.newAndRepeatedKeys & DPAD_DOWN)
    {
        Menu_MoveCursorNoWrapAround(1);
        return;
    }
    if (gMain.newKeys & START_BUTTON)
    {
        sDriverTest_Reverse ^= 1;
        PrintDriverTestMenuText();
        return;
    }
    if (gMain.newKeys & SELECT_BUTTON)
    {
        sDriverTest_Stereo ^= 1;
        PrintDriverTestMenuText();
        SetPokemonCryStereo(sDriverTest_Stereo);
        return;
    }
    if (gMain.newAndRepeatedKeys & R_BUTTON)
    {
        AdjustSelectedDriverParam(10);
        PrintDriverTestMenuText();
        return;
    }
    if (gMain.newAndRepeatedKeys & L_BUTTON)
    {
        AdjustSelectedDriverParam(-10);
        PrintDriverTestMenuText();
        return;
    }
    if (gMain.newAndRepeatedKeys & DPAD_LEFT)
    {
        AdjustSelectedDriverParam(-1);
        PrintDriverTestMenuText();
        return;
    }
    if (gMain.newAndRepeatedKeys & DPAD_RIGHT)
    {
        AdjustSelectedDriverParam(1);
        PrintDriverTestMenuText();
        return;
    }
    if (gMain.newKeys & A_BUTTON)
    {
        u8 divide, remaining;

        SetPokemonCryVolume(sSoundTestParams[CRY_TEST_VOLUME]);
        SetPokemonCryPanpot(sSoundTestParams[CRY_TEST_PANPOT]);
        SetPokemonCryPitch(sSoundTestParams[CRY_TEST_PITCH]);
        SetPokemonCryLength(sSoundTestParams[CRY_TEST_LENGTH]);
        SetPokemonCryProgress(sSoundTestParams[CRY_TEST_PROGRESS]);
        SetPokemonCryRelease(sSoundTestParams[CRY_TEST_RELEASE]);
        SetPokemonCryChorus(sSoundTestParams[CRY_TEST_CHORUS]);
        SetPokemonCryPriority(sSoundTestParams[CRY_TEST_PRIORITY]);

        remaining = sSoundTestParams[CRY_TEST_VOICE] % 128;
        divide = sSoundTestParams[CRY_TEST_VOICE] / 128;

        switch (divide)
        {
        case 0:
            if (sDriverTest_Reverse)
                sMPlayInfo_Cry = SetPokemonCryTone(&gCryTable2[(128 * 0) + remaining]);
            else
                sMPlayInfo_Cry = SetPokemonCryTone(&gCryTable[(128 * 0) + remaining]);
            break;
        case 1:
            if (sDriverTest_Reverse)
                sMPlayInfo_Cry = SetPokemonCryTone(&gCryTable2[(128 * 1) + remaining]);
            else
                sMPlayInfo_Cry = SetPokemonCryTone(&gCryTable[(128 * 1) + remaining]);
            break;
        case 2:
            if (sDriverTest_Reverse)
                sMPlayInfo_Cry = SetPokemonCryTone(&gCryTable2[(128 * 2) + remaining]);
            else
                sMPlayInfo_Cry = SetPokemonCryTone(&gCryTable[(128 * 2) + remaining]);
            break;
        case 3:
            if (sDriverTest_Reverse)
                sMPlayInfo_Cry = SetPokemonCryTone(&gCryTable2[(128 * 3) + remaining]);
            else
                sMPlayInfo_Cry = SetPokemonCryTone(&gCryTable[(128 * 3) + remaining]);
            break;
        }
    }

    if (sMPlayInfo_Cry != NULL)
    {
        sDriverTest_IsCryPlaying = IsPokemonCryPlaying(sMPlayInfo_Cry);

        if (sDriverTest_IsCryPlaying != sDriverTest_IsCryPlayingOld)
            PrintDriverTestMenuText();

        sDriverTest_IsCryPlayingOld = sDriverTest_IsCryPlaying;
    }
}

static void AdjustSelectedDriverParam(s8 delta) // sub_080E8FA4
{
    // also ideally should be a MinMax struct, but any attempt to make this into a struct causes it to not match due to the weird multi dim access.
    const int paramRanges[] =
    {
        0, 387,         // Voice
        0, 127,         // Volume
        -127, 127,      // Panpot
        -128, 32639,    // Pitch
        0, 65535,       // Length
        0, 255,         // Release
        0, 65535,       // Progress
        -64, 63,        // Chorus
        0, 65535        // Priority
    };

    u8 cursorPos = Menu_GetCursorPos();

    sSoundTestParams[cursorPos] += delta;

    if (sSoundTestParams[cursorPos] > paramRanges[MULTI_DIM_ARR(cursorPos, B_16, MAX)])
        sSoundTestParams[cursorPos] = paramRanges[MULTI_DIM_ARR(cursorPos, B_16, MIN)];

    if (sSoundTestParams[cursorPos] < paramRanges[MULTI_DIM_ARR(cursorPos, B_16, MIN)])
        sSoundTestParams[cursorPos] = paramRanges[MULTI_DIM_ARR(cursorPos, B_16, MAX)];
}

static void PrintDriverTestMenuText(void) // sub_080E900C
{
    PrintSignedNumber(sSoundTestParams[CRY_TEST_VOICE] + 1, 80, 0, 5);
    PrintSignedNumber(sSoundTestParams[CRY_TEST_VOLUME], 80, 16, 5);
    PrintSignedNumber(sSoundTestParams[CRY_TEST_PANPOT], 80, 32, 5);
    PrintSignedNumber(sSoundTestParams[CRY_TEST_PITCH], 80, 48, 5);
    PrintSignedNumber(sSoundTestParams[CRY_TEST_LENGTH], 80, 64, 5);
    PrintSignedNumber(sSoundTestParams[CRY_TEST_RELEASE], 80, 80, 5);
    PrintSignedNumber(sSoundTestParams[CRY_TEST_PROGRESS], 80, 96, 5);
    PrintSignedNumber(sSoundTestParams[CRY_TEST_CHORUS], 80, 112, 5);
    PrintSignedNumber(sSoundTestParams[CRY_TEST_PRIORITY], 80, 128, 5);
    PrintSignedNumber(sDriverTest_IsCryPlaying, 200, 80, 1);
    PrintSignedNumber(sDriverTest_Reverse, 200, 96, 1);
    PrintSignedNumber(sDriverTest_Stereo, 200, 112, 1);
}

static void PrintSignedNumber(int n, u16 x, u16 y, u8 digits) // sub_080E90C0
{
    const int powersOfTen[6] =
    {
              1,
             10,
            100,
           1000,
          10000,
         100000
    };

    u8 str[8];
    s8 i;
    s8 negative;
    s8 someVar2;

    for (i = 0; i <= digits; i++)
        str[i] = CHAR_SPACE;
    str[digits + 1] = EOS;

    negative = FALSE;
    if (n < 0)
    {
        n = -n;
        negative = TRUE;
    }

    if (digits == 1)
        someVar2 = TRUE;
    else
        someVar2 = FALSE;

    for (i = digits - 1; i >= 0; i--)
    {
        s8 d = n / powersOfTen[i];

        if (d != 0 || someVar2 || i == 0)
        {
            if (negative && !someVar2)
                str[digits - i - 1] = CHAR_HYPHEN;
            str[digits - i] = CHAR_0 + d;
            someVar2 = TRUE;
        }
        n %= powersOfTen[i];
    }

    AddTextPrinterParameterized(WIN_INFO, 1, str, x, y, TEXT_SPEED_FF, NULL);
    PutWindowTilemapAndCopyWindowToVram(WIN_INFO);
}

static const s8 gUnknown_08566E58[5] = { 0x3F, 0x00, 0xC0, 0x7F, 0x80 };

static void Task_DrawPanTestMenu(u8 taskId) // sub_080E91E4
{
    const u8 seStr[] = _("SOUND EFFECT");
    const u8 panStr[] = _("PAN");

    AddTextPrinterParameterized(WIN_INFO, 1, seStr, 10, 14, TEXT_SPEED_FF, NULL);
    AddTextPrinterParameterized(WIN_INFO, 1, panStr, 10, 28, TEXT_SPEED_FF, NULL);

    SetGpuReg(REG_OFFSET_WIN0H, WIN_RANGE(0, DISPLAY_WIDTH));
    SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE(0, DISPLAY_HEIGHT));
    sSoundTestParams[CRY_TEST_VOICE] = 1;
    sSoundTestParams[CRY_TEST_PANPOT] = 0;
    sSoundTestParams[CRY_TEST_CHORUS] = 0;
    sSoundTestParams[CRY_TEST_PROGRESS] = 0;
    sSoundTestParams[CRY_TEST_RELEASE] = 0;
    PrintPanTestMenuText();
    gTasks[taskId].func = Task_ProcessPanTestInput;
}

static void Task_ProcessPanTestInput(u8 taskId) // sub_080E9284
{
    if (sSoundTestParams[CRY_TEST_PROGRESS])
    {
        if (sSoundTestParams[CRY_TEST_RELEASE])
        {
            sSoundTestParams[CRY_TEST_RELEASE]--;
        }
        else
        {
            s8 panpot = gUnknown_08566E58[sSoundTestParams[CRY_TEST_PANPOT]];
            if (panpot != -128)
            {
                if (panpot == 127)
                {
                    sSoundTestParams[CRY_TEST_CHORUS] += 2;
                    if (sSoundTestParams[CRY_TEST_CHORUS] < 63)
                        SE12PanpotControl(sSoundTestParams[CRY_TEST_CHORUS]);
                }
            }
            else
            {
                sSoundTestParams[CRY_TEST_CHORUS] -= 2;
                if (sSoundTestParams[CRY_TEST_CHORUS] > -64)
                    SE12PanpotControl(sSoundTestParams[CRY_TEST_CHORUS]);
            }
        }
    }

    if (gMain.newKeys & B_BUTTON)
    {
        gTasks[taskId].tState = 0;
        gTasks[taskId].func = Task_InitSoundCheckMenu;
        return;
    }
    if (gMain.newKeys & A_BUTTON)
    {
        s8 panpot = gUnknown_08566E58[sSoundTestParams[CRY_TEST_PANPOT]];
        if (panpot != -128)
        {
            if (panpot == 127)
            {
                PlaySE12WithPanning(sSoundTestParams[CRY_TEST_VOICE], -64);
                sSoundTestParams[CRY_TEST_CHORUS] = -64;
                sSoundTestParams[CRY_TEST_PROGRESS] = 1;
                sSoundTestParams[CRY_TEST_RELEASE] = 30;
                return;
            }
        }
        else
        {
            PlaySE12WithPanning(sSoundTestParams[CRY_TEST_VOICE], 63);
            sSoundTestParams[CRY_TEST_CHORUS] = 63;
            sSoundTestParams[CRY_TEST_PROGRESS] = 1;
            sSoundTestParams[CRY_TEST_RELEASE] = 30;
            return;
        }

        PlaySE12WithPanning(sSoundTestParams[CRY_TEST_VOICE], panpot);
        sSoundTestParams[CRY_TEST_PROGRESS] = 0;
        return;
    }
    if (gMain.newKeys & L_BUTTON)
    {
        sSoundTestParams[CRY_TEST_PANPOT]++;
        if (sSoundTestParams[CRY_TEST_PANPOT] > 4)
            sSoundTestParams[CRY_TEST_PANPOT] = 0;
        PrintPanTestMenuText();
    }
    if (gMain.newKeys & R_BUTTON)
    {
        sSoundTestParams[CRY_TEST_PANPOT]--;
        if (sSoundTestParams[CRY_TEST_PANPOT] < 0)
            sSoundTestParams[CRY_TEST_PANPOT] = 4;
        PrintPanTestMenuText();
    }
    if (gMain.newAndRepeatedKeys & DPAD_RIGHT)
    {
        sSoundTestParams[CRY_TEST_VOICE]++;
        if (sSoundTestParams[CRY_TEST_VOICE] > SE_USSOKI)
            sSoundTestParams[CRY_TEST_VOICE] = MUS_DUMMY;
        PrintPanTestMenuText();
    }
    else if (gMain.newAndRepeatedKeys & DPAD_LEFT)
    {
        sSoundTestParams[CRY_TEST_VOICE]--;
        if (sSoundTestParams[CRY_TEST_VOICE] < MUS_DUMMY)
            sSoundTestParams[CRY_TEST_VOICE] = SE_USSOKI;
        PrintPanTestMenuText();
    }
}

static void Task_InitSoundCheckMenu(u8 taskId) // sub_080E9410
{
    switch (gTasks[taskId].tState)
    {
    case 0:
        DestroyWindow(WIN_INFO);
        FreeAllWindowBuffers();
        ResetBgsAndClearDma3BusyFlags(0);
        InitBgsFromTemplates(0, sSoundCheckMenuBgTemplates, ARRAY_COUNT(sSoundCheckMenuBgTemplates));
        gTasks[taskId].tState++;
        break;
    case 1:
        if (IsDma3ManagerBusyWithBgCopy() == TRUE)
            return;
        InitWindows(sSoundCheckMenuWindowTemplates);
        gTasks[taskId].tState++;
        break;
    case 2:
        ShowBg(0);
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 |
                                      DISPCNT_OBJ_1D_MAP |
                                      DISPCNT_BG0_ON |
                                      DISPCNT_OBJ_ON |
                                      DISPCNT_WIN0_ON |
                                      DISPCNT_WIN1_ON);
        SetGpuReg(REG_OFFSET_WIN0H, WIN_RANGE(17, 223));
        SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE(1, 31));
        gTasks[taskId].func = Task_InitSoundCheckMenu_CreateWindows;
        break;
    }
}

static void PrintPanTestMenuText(void) // sub_080E94B8
{
    u8 lrStr[] = _("   L");
    u8 rlStr[] = _("   R");

    FillWindowPixelRect(WIN_INFO, PIXEL_FILL(1), 100, 14, 3, 28);
    PrintSignedNumber(sSoundTestParams[CRY_TEST_VOICE], 100, 14, 3);

    switch (gUnknown_08566E58[sSoundTestParams[CRY_TEST_PANPOT]])
    {
    case 127:
        AddTextPrinterParameterized(WIN_INFO, 1, lrStr, 100, 28, TEXT_SPEED_FF, NULL);
        break;
    case -128:
        AddTextPrinterParameterized(WIN_INFO, 1, rlStr, 100, 28, TEXT_SPEED_FF, NULL);
        break;
    default:
        PrintSignedNumber(gUnknown_08566E58[sSoundTestParams[CRY_TEST_PANPOT]], 100, 28, 3);
        break;
    }
}

static void InitGpuRegs(void) // sub_080E9560
{
    DmaClear16(3, VRAM, VRAM_SIZE);
    DmaClear32(3, OAM, OAM_SIZE);
    DmaClear16(3, PLTT, PLTT_SIZE);
    SetGpuReg(REG_OFFSET_DISPCNT, 0);
    SetGpuReg(REG_OFFSET_BG0CNT, 0);
    SetGpuReg(REG_OFFSET_BG0HOFS, 0);
    SetGpuReg(REG_OFFSET_BG0VOFS, 0);
    SetGpuReg(REG_OFFSET_BG1CNT, 0);
    SetGpuReg(REG_OFFSET_BG1HOFS, 0);
    SetGpuReg(REG_OFFSET_BG1VOFS, 0);
    SetGpuReg(REG_OFFSET_BG2CNT, 0);
    SetGpuReg(REG_OFFSET_BG2HOFS, 0);
    SetGpuReg(REG_OFFSET_BG2VOFS, 0);
    SetGpuReg(REG_OFFSET_BG3CNT, 0);
    SetGpuReg(REG_OFFSET_BG3HOFS, 0);
    SetGpuReg(REG_OFFSET_BG3VOFS, 0);
    SetGpuReg(REG_OFFSET_WIN0H, 0);
    SetGpuReg(REG_OFFSET_WIN0V, 0);
    SetGpuReg(REG_OFFSET_WIN1H, 0);
    SetGpuReg(REG_OFFSET_WIN1V, 0);
    SetGpuReg(REG_OFFSET_WININ, 0);
    SetGpuReg(REG_OFFSET_WINOUT, 0);
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    SetGpuReg(REG_OFFSET_BLDALPHA, 0);
    SetGpuReg(REG_OFFSET_BLDY, 0);
}

static void ClearTasksAndGraphicalStructs(void) // sub_080E96A8
{
    ScanlineEffect_Stop();
    ResetTasks();
    ResetSpriteData();
    ResetAllPicSprites();
    ResetPaletteFade();
    FreeAllSpritePalettes();
}

static void SetupDispcnt(void) // sub_080E96C8
{
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 |
                                  DISPCNT_OBJ_1D_MAP |
                                  DISPCNT_BG0_ON |
                                  DISPCNT_OBJ_ON |
                                  DISPCNT_WIN0_ON |
                                  DISPCNT_WIN1_ON);
}

static void PutWindowTilemapAndCopyWindowToVram(u8 windowId) // sub_080E9734
{
    PutWindowTilemap(windowId);
    CopyWindowToVram(windowId, 3);
}

static void DestroyWindow(u8 windowId) // sub_080E9750
{
    FillWindowPixelBuffer(windowId, PIXEL_FILL(0));
    ClearWindowTilemap(windowId);
    CopyWindowToVram(windowId, 2);
    RemoveWindow(windowId);
}

#define SOUND_LIST_BGM \
	X(MUS_STOP, "STOP") \
    X(MUS_TETSUJI, "MUS-TETSUJI") \
    X(MUS_FIELD13, "MUS-FIELD13") \
    X(MUS_WILDPOSTCATCH, "MUS-WILDPOSTCATCH") \
    X(MUS_WILDDEFEAT, "MUS-WILDDEFEAT") \
    X(MUS_KACHI3, "MUS-KACHI3") \
    X(MUS_KACHI5, "MUS-KACHI5") \
    X(MUS_PCC, "MUS-PCC") \
    X(MUS_NIBI, "MUS-NIBI") \
    X(MUS_SUIKUN, "MUS-SUIKUN") \
    X(MUS_ROUTE29, "MUS-ROUTE29") \
    X(MUS_ROUTE34, "MUS-ROUTE34") \
    X(MUS_DOORO_X3, "MUS-DOORO-X3") \
    X(MUS_VIOLET, "MUS-VIOLET") \
    X(MUS_CHERRYGROVE, "MUS-CHERRYGROVE") \
    X(MUS_GYM, "MUS-GYM") \
    X(MUS_NAMINORI, "MUS-NAMINORI") \
    X(MUS_ILEXFOREST, "MUS-ILEXFOREST") \
    X(MUS_FANFA1, "MUS-FANFA1") \
    X(MUS_ME_ASA, "MUS-ME-ASA") \
    X(MUS_ME_BACHI, "MUS-ME-BACHI") \
    X(MUS_FANFA4, "MUS-FANFA4") \
    X(MUS_FANFA5, "MUS-FANFA5") \
    X(MUS_ME_WAZA, "MUS-ME-WAZA") \
    X(MUS_RUINSOFALPH, "MUS-RUINSOFALPH") \
    X(MUS_ROUTE30, "MUS-ROUTE30") \
    X(MUS_BUENA, "MUS-BUENA") \
    X(MUS_ME_SHINKA, "MUS-ME-SHINKA") \
    X(MUS_SHINKA, "MUS-SHINKA") \
    X(MUS_ME_WASURE, "MUS-ME-WASURE") \
    X(MUS_ENCFEMALECLASSIC, "MUS-ENCFEMALECLASSIC") \
    X(MUS_ENCMALE, "MUS-ENCMALE") \
    X(MUS_DARKCAVE, "MUS-DARKCAVE") \
    X(MUS_MACHI_S3, "MUS-MACHI-S3") \
    X(MUS_ELMSLAB, "MUS-ELMSLAB") \
    X(MUS_B_TOWER, "MUS-B-TOWER") \
    X(MUS_SWIMEYE, "MUS-SWIMEYE") \
    X(MUS_DAN03, "MUS-DAN03") \
    X(MUS_FANFAREEGG, "MUS-FANFAREEGG") \
    X(MUS_ME_TAMA, "MUS-ME-TAMA") \
    X(MUS_ME_B_BIG, "MUS-ME-B-BIG") \
    X(MUS_ME_B_SMALL, "MUS-ME-B-SMALL") \
    X(MUS_ME_ZANNEN, "MUS-ME-ZANNEN") \
    X(MUS_BD_TIME, "MUS-BD-TIME") \
    X(MUS_TEST1, "MUS-TEST1") \
    X(MUS_TEST2, "MUS-TEST2") \
    X(MUS_TEST3, "MUS-TEST3") \
    X(MUS_TEST4, "MUS-TEST4") \
    X(MUS_POKEMONMARCH, "MUS-POKEMONMARCH") \
    X(MUS_GOMACHI0, "MUS-GOMACHI0") \
    X(MUS_GOLDENROD, "MUS-GOLDENROD") \
    X(MUS_POKECEN, "MUS-POKECEN") \
    X(MUS_NEXTROAD, "MUS-NEXTROAD") \
    X(MUS_GRANROAD, "MUS-GRANROAD") \
    X(MUS_CYCLING, "MUS-CYCLING") \
    X(MUS_PKMNLULLABY, "MUS-FRIENDLY") \
    X(MUS_NEWBARK, "MUS-NEWBARK") \
    X(MUS_TOZAN, "MUS-TOZAN") \
    X(MUS_ENCFEMALE, "MUS-ENCFEMALE") \
    X(MUS_MINAMO, "MUS-MINAMO") \
    X(MUS_ASHROAD, "MUS-ASHROAD") \
    X(MUS_MOMENC, "MUS-MOMENC") \
    X(MUS_DEEPDEEP, "MUS-DEEPDEEP") \
    X(MUS_KACHI1, "MUS-KACHI1") \
    X(MUS_TITLE3, "MUS-TITLE3") \
    X(MUS_DEMO1, "MUS-DEMO1") \
    X(MUS_RIVALTHEME, "MUS-RIVALENC") \
    X(MUS_ENCSAGE, "MUS-ENCSAGE") \
    X(MUS_ENCMALECLASSIC, "MUS-ENCMALECLASSIC") \
    X(MUS_MAINMENU, "MUS-MAINMENU") \
    X(MUS_ENCROCKET, "MUS-ENCROCKET") \
    X(MUS_FOLLOWME, "MUS-FOLLOWME") \
    X(MUS_RIVALEXIT, "MUS-RIVALEXIT") \
    X(MUS_RAINBOW, "MUS-RAINBOW") \
    X(MUS_ENCSUSPICIOUS, "MUS-ENCSUSPICIOUS") \
    X(MUS_KACHI4, "MUS-KACHI4") \
    X(MUS_ROPEWAY, "MUS-ROPEWAY") \
    X(MUS_CASINO, "MUS-CASINO") \
    X(MUS_AZALEA, "MUS-AZALEA") \
    X(MUS_SAFARI, "MUS-SAFARI") \
    X(MUS_C_ROAD, "MUS-C-ROAD") \
    X(MUS_AJITO, "MUS-AJITO") \
    X(MUS_M_BOAT, "MUS-M-BOAT") \
    X(MUS_SPROUTTOWER, "MUS-SPROUTTOWER") \
    X(MUS_FINECITY, "MUS-FINECITY") \
    X(MUS_MACHUPI, "MUS-MACHUPI") \
    X(MUS_OAKTHEME, "MUS-OAKSTHEME") \
    X(MUS_DENDOU, "MUS-DENDOU") \
    X(MUS_TONEKUSA, "MUS-TONEKUSA") \
    X(MUS_MABOROSI, "MUS-MABOROSI") \
    X(MUS_CON_FAN, "MUS-CON-FAN") \
    X(MUS_CONTEST0, "MUS-CONTEST0") \
    X(MUS_OAKSLAB, "MUS-OAKSLAB") \
    X(MUS_ROCKETTAKEOVER, "MUS-ROCKETTAKEOVER") \
    X(MUS_OOAME, "MUS-OOAME") \
    X(MUS_HIDERI, "MUS-HIDERI") \
    X(MUS_RUNECITY, "MUS-RUNECITY") \
    X(MUS_CON_K, "MUS-CON-K") \
    X(MUS_EIKOU_R, "MUS-EIKOU-R") \
    X(MUS_KARAKURI, "MUS-KARAKURI") \
    X(MUS_HUTAGO, "MUS-HUTAGO") \
    X(MUS_SITENNOU, "MUS-SITENNOU") \
    X(MUS_ENCSUSPICIOUSCLASSIC, "MUS-ENCSUSPICIOUSCLASSIC") \
    X(MUS_CONLOBBY, "MUS-CONLOBBY") \
    X(MUS_ENCKIMONO, "MUS-ENCKIMONO") \
    X(MUS_DAIGO, "MUS-DAIGO") \
    X(MUS_THANKFOR, "MUS-THANKFOR") \
    X(MUS_END, "MUS-END") \
    X(MUS_B_FRONTIER, "MUS-B-FRONTIER") \
    X(MUS_B_ARENA, "MUS-B-ARENA") \
    X(MUS_ME_POINTGET, "MUS-ME-POINTGET") \
    X(MUS_ME_TORE_EYE, "MUS-ME-TORE-EYE") \
    X(MUS_PYRAMID, "MUS-PYRAMID") \
    X(MUS_PYRAMID_TOP, "MUS-PYRAMID-TOP") \
    X(MUS_B_PALACE, "MUS-B-PALACE") \
    X(MUS_REKKUU_KOURIN, "MUS-REKKUU-KOURIN") \
    X(MUS_SATTOWER, "MUS-SATTOWER") \
    X(MUS_ME_SYMBOLGET, "MUS-ME-SYMBOLGET") \
    X(MUS_B_DOME, "MUS-B-DOME") \
    X(MUS_B_TUBE, "MUS-B-TUBE") \
    X(MUS_B_FACTORY, "MUS-B-FACTORY") \
    X(MUS_VS_REKKU, "MUS-VS-REKKU") \
    X(MUS_VS_FRONT, "MUS-VS-FRONT") \
    X(MUS_VS_MEW, "MUS-VS-MEW") \
    X(MUS_B_DOME1, "MUS-B-DOME1") \
    X(MUS_BTLJOHTOWILD, "MUS-BTLJOHTOWILD") \
    X(MUS_BTLROCKET, "MUS-BTLROCKET") \
    X(MUS_BTLJOHTOTRN, "MUS-BTLJOHTOTRN") \
    X(MUS_BTLJOHTOLDR, "MUS-BTLJOHTOLDR") \
    X(MUS_BATTLE33, "MUS-BATTLE33") \
    X(MUS_BATTLE36, "MUS-BATTLE36") \
    X(MUS_BATTLE34, "MUS-BATTLE34") \
    X(MUS_BTLRIVAL, "MUS-BTLRIVAL") \
    X(MUS_BATTLE38, "MUS-BATTLE38") \
    X(MUS_BATTLE30, "MUS-BATTLE30") \
    X(MUS_RG_ANNAI, "MUS-RG-ANNAI") \
    X(MUS_RG_SLOT, "MUS-RG-SLOT") \
    X(MUS_RG_AJITO, "MUS-RG-AJITO") \
    X(MUS_RG_GYM, "MUS-RG-GYM") \
    X(MUS_RG_PURIN, "MUS-RG-PURIN") \
    X(MUS_RG_DEMO, "MUS-RG-DEMO") \
    X(MUS_RG_TITLE, "MUS-RG-TITLE") \
    X(MUS_RG_GUREN, "MUS-RG-GUREN") \
    X(MUS_RG_SHION, "MUS-RG-SHION") \
    X(MUS_RG_KAIHUKU, "MUS-RG-KAIHUKU") \
    X(MUS_RG_CYCLING, "MUS-RG-CYCLING") \
    X(MUS_RG_ROCKET, "MUS-RG-ROCKET") \
    X(MUS_RG_SHOUJO, "MUS-RG-SHOUJO") \
    X(MUS_RG_SHOUNEN, "MUS-RG-SHOUNEN") \
    X(MUS_RG_DENDOU, "MUS-RG-DENDOU") \
    X(MUS_RG_T_MORI, "MUS-RG-T-MORI") \
    X(MUS_RG_OTSUKIMI, "MUS-RG-OTSUKIMI") \
    X(MUS_RG_POKEYASHI, "MUS-RG-POKEYASHI") \
    X(MUS_RG_ENDING, "MUS-RG-ENDING") \
    X(MUS_RG_LOAD01, "MUS-RG-LOAD01") \
    X(MUS_RG_OPENING, "MUS-RG-OPENING") \
    X(MUS_RG_LOAD02, "MUS-RG-LOAD02") \
    X(MUS_RG_LOAD03, "MUS-RG-LOAD03") \
    X(MUS_RG_CHAMP_R, "MUS-RG-CHAMP-R") \
    X(MUS_RG_VS_GYM, "MUS-RG-VS-GYM") \
    X(MUS_RG_VS_TORE, "MUS-RG-VS-TORE") \
    X(MUS_RG_VS_YASEI, "MUS-RG-VS-YASEI") \
    X(MUS_RG_VS_LAST, "MUS-RG-VS-LAST") \
    X(MUS_RG_MASARA, "MUS-RG-MASARA") \
    X(MUS_RG_KENKYU, "MUS-RG-KENKYU") \
    X(MUS_RG_OHKIDO, "MUS-RG-OHKIDO") \
    X(MUS_RG_POKECEN, "MUS-RG-POKECEN") \
    X(MUS_RG_SANTOAN, "MUS-RG-SANTOAN") \
    X(MUS_RG_NAMINORI, "MUS-RG-NAMINORI") \
    X(MUS_RG_P_TOWER, "MUS-RG-P-TOWER") \
    X(MUS_RG_SHIRUHU, "MUS-RG-SHIRUHU") \
    X(MUS_RG_HANADA, "MUS-RG-HANADA") \
    X(MUS_RG_TAMAMUSI, "MUS-RG-TAMAMUSI") \
    X(MUS_RG_WIN_TRE, "MUS-RG-WIN-TRE") \
    X(MUS_RG_WIN_YASEI, "MUS-RG-WIN-YASEI") \
    X(MUS_RG_WIN_GYM, "MUS-RG-WIN-GYM") \
    X(MUS_RG_KUCHIBA, "MUS-RG-KUCHIBA") \
    X(MUS_RG_NIBI, "MUS-RG-NIBI") \
    X(MUS_RG_RIVAL1, "MUS-RG-RIVAL1") \
    X(MUS_RG_RIVAL2, "MUS-RG-RIVAL2") \
    X(MUS_RG_FAN2, "MUS-RG-FAN2") \
    X(MUS_RG_FAN5, "MUS-RG-FAN5") \
    X(MUS_RG_FAN6, "MUS-RG-FAN6") \
    X(MUS_ME_RG_PHOTO, "MUS-ME-RG-PHOTO") \
    X(MUS_RG_TITLEROG, "MUS-RG-TITLEROG") \
    X(MUS_RG_GET_YASEI, "MUS-RG-GET-YASEI") \
    X(MUS_RG_SOUSA, "MUS-RG-SOUSA") \
    X(MUS_RG_SEKAIKAN, "MUS-RG-SEKAIKAN") \
    X(MUS_RG_SEIBETU, "MUS-RG-SEIBETU") \
    X(MUS_RG_JUMP, "MUS-RG-JUMP") \
    X(MUS_RG_UNION, "MUS-RG-UNION") \
    X(MUS_RG_NETWORK, "MUS-RG-NETWORK") \
    X(MUS_RG_OKURIMONO, "MUS-RG-OKURIMONO") \
    X(MUS_RG_KINOMIKUI, "MUS-RG-KINOMIKUI") \
    X(MUS_RG_NANADUNGEON, "MUS-RG-NANADUNGEON") \
    X(MUS_RG_OSHIE_TV, "MUS-RG-OSHIE-TV") \
    X(MUS_RG_NANASHIMA, "MUS-RG-NANASHIMA") \
    X(MUS_RG_NANAISEKI, "MUS-RG-NANAISEKI") \
    X(MUS_RG_NANA123, "MUS-RG-NANA123") \
    X(MUS_RG_NANA45, "MUS-RG-NANA45") \
    X(MUS_RG_NANA67, "MUS-RG-NANA67") \
    X(MUS_RG_POKEFUE, "MUS-RG-POKEFUE") \
    X(MUS_RG_VS_DEO, "MUS-RG-VS-DEO") \
    X(MUS_RG_VS_MYU2, "MUS-RG-VS-MYU2") \
    X(MUS_RG_VS_DEN, "MUS-RG-VS-DEN") \
    X(MUS_RG_EXEYE, "MUS-RG-EXEYE") \
    X(MUS_RG_DEOEYE, "MUS-RG-DEOEYE") \
    X(MUS_RG_T_TOWER, "MUS-RG-T-TOWER") \
    X(MUS_RG_SLOWMASARA, "MUS-RG-SLOWMASARA") \
    X(MUS_RG_TVNOIZE, "MUS-RG-TVNOIZE") \
    X(PH_TRAP_BLEND, "PH-TRAP-BLEND") \
    X(PH_TRAP_HELD, "PH-TRAP-HELD") \
    X(PH_TRAP_SOLO, "PH-TRAP-SOLO") \
    X(PH_FACE_BLEND, "PH-FACE-BLEND") \
    X(PH_FACE_HELD, "PH-FACE-HELD") \
    X(PH_FACE_SOLO, "PH-FACE-SOLO") \
    X(PH_CLOTH_BLEND, "PH-CLOTH-BLEND") \
    X(PH_CLOTH_HELD, "PH-CLOTH-HELD") \
    X(PH_CLOTH_SOLO, "PH-CLOTH-SOLO") \
    X(PH_DRESS_BLEND, "PH-DRESS-BLEND") \
    X(PH_DRESS_HELD, "PH-DRESS-HELD") \
    X(PH_DRESS_SOLO, "PH-DRESS-SOLO") \
    X(PH_FLEECE_BLEND, "PH-FLEECE-BLEND") \
    X(PH_FLEECE_HELD, "PH-FLEECE-HELD") \
    X(PH_FLEECE_SOLO, "PH-FLEECE-SOLO") \
    X(PH_KIT_BLEND, "PH-KIT-BLEND") \
    X(PH_KIT_HELD, "PH-KIT-HELD") \
    X(PH_KIT_SOLO, "PH-KIT-SOLO") \
    X(PH_PRICE_BLEND, "PH-PRICE-BLEND") \
    X(PH_PRICE_HELD, "PH-PRICE-HELD") \
    X(PH_PRICE_SOLO, "PH-PRICE-SOLO") \
    X(PH_LOT_BLEND, "PH-LOT-BLEND") \
    X(PH_LOT_HELD, "PH-LOT-HELD") \
    X(PH_LOT_SOLO, "PH-LOT-SOLO") \
    X(PH_GOAT_BLEND, "PH-GOAT-BLEND") \
    X(PH_GOAT_HELD, "PH-GOAT-HELD") \
    X(PH_GOAT_SOLO, "PH-GOAT-SOLO") \
    X(PH_THOUGHT_BLEND, "PH-THOUGHT-BLEND") \
    X(PH_THOUGHT_HELD, "PH-THOUGHT-HELD") \
    X(PH_THOUGHT_SOLO, "PH-THOUGHT-SOLO") \
    X(PH_CHOICE_BLEND, "PH-CHOICE-BLEND") \
    X(PH_CHOICE_HELD, "PH-CHOICE-HELD") \
    X(PH_CHOICE_SOLO, "PH-CHOICE-SOLO") \
    X(PH_MOUTH_BLEND, "PH-MOUTH-BLEND") \
    X(PH_MOUTH_HELD, "PH-MOUTH-HELD") \
    X(PH_MOUTH_SOLO, "PH-MOUTH-SOLO") \
    X(PH_FOOT_BLEND, "PH-FOOT-BLEND") \
    X(PH_FOOT_HELD, "PH-FOOT-HELD") \
    X(PH_FOOT_SOLO, "PH-FOOT-SOLO") \
    X(PH_GOOSE_BLEND, "PH-GOOSE-BLEND") \
    X(PH_GOOSE_HELD, "PH-GOOSE-HELD") \
    X(PH_GOOSE_SOLO, "PH-GOOSE-SOLO") \
    X(PH_STRUT_BLEND, "PH-STRUT-BLEND") \
    X(PH_STRUT_HELD, "PH-STRUT-HELD") \
    X(PH_STRUT_SOLO, "PH-STRUT-SOLO") \
    X(PH_CURE_BLEND, "PH-CURE-BLEND") \
    X(PH_CURE_HELD, "PH-CURE-HELD") \
    X(PH_CURE_SOLO, "PH-CURE-SOLO") \
    X(PH_NURSE_BLEND, "PH-NURSE-BLEND") \
    X(PH_NURSE_HELD, "PH-NURSE-HELD") \
    X(PH_NURSE_SOLO, "PH-NURSE-SOLO")

#define SOUND_LIST_SE \
	X(SE_STOP, "STOP") \
    X(SE_KAIFUKU, "SE-KAIFUKU") \
    X(SE_PC_LOGIN, "SE-PC-LOGIN") \
    X(SE_PC_OFF, "SE-PC-OFF") \
    X(SE_PC_ON, "SE-PC-ON") \
    X(SE_SELECT, "SE-SELECT") \
    X(SE_WIN_OPEN, "SE-WIN-OPEN") \
    X(SE_WALL_HIT, "SE-WALL-HIT") \
    X(SE_DOOR, "SE-DOOR") \
    X(SE_KAIDAN, "SE-KAIDAN") \
    X(SE_DANSA, "SE-DANSA") \
    X(SE_JITENSYA, "SE-JITENSYA") \
    X(SE_KOUKA_L, "SE-KOUKA-L") \
    X(SE_KOUKA_M, "SE-KOUKA-M") \
    X(SE_KOUKA_H, "SE-KOUKA-H") \
    X(SE_BOWA2, "SE-BOWA2") \
    X(SE_POKE_DEAD, "SE-POKE-DEAD") \
    X(SE_NIGERU, "SE-NIGERU") \
    X(SE_JIDO_DOA, "SE-JIDO-DOA") \
    X(SE_NAMINORI, "SE-NAMINORI") \
    X(SE_BAN, "SE-BAN") \
    X(SE_PIN, "SE-PIN") \
    X(SE_BOO, "SE-BOO") \
    X(SE_BOWA, "SE-BOWA") \
    X(SE_JYUNI, "SE-JYUNI") \
    X(SE_A, "SE-A") \
    X(SE_I, "SE-I") \
    X(SE_U, "SE-U") \
    X(SE_E, "SE-E") \
    X(SE_O, "SE-O") \
    X(SE_N, "SE-N") \
    X(SE_SEIKAI, "SE-SEIKAI") \
    X(SE_HAZURE, "SE-HAZURE") \
    X(SE_EXP, "SE-EXP") \
    X(SE_JITE_PYOKO, "SE-JITE-PYOKO") \
    X(SE_MU_PACHI, "SE-MU-PACHI") \
    X(SE_TK_KASYA, "SE-TK-KASYA") \
    X(SE_FU_ZAKU, "SE-FU-ZAKU") \
    X(SE_FU_ZAKU2, "SE-FU-ZAKU2") \
    X(SE_FU_ZUZUZU, "SE-FU-ZUZUZU") \
    X(SE_RU_GASHIN, "SE-RU-GASHIN") \
    X(SE_RU_GASYAN, "SE-RU-GASYAN") \
    X(SE_RU_BARI, "SE-RU-BARI") \
    X(SE_RU_HYUU, "SE-RU-HYUU") \
    X(SE_KI_GASYAN, "SE-KI-GASYAN") \
    X(SE_TK_WARPIN, "SE-TK-WARPIN") \
    X(SE_TK_WARPOUT, "SE-TK-WARPOUT") \
    X(SE_TU_SAA, "SE-TU-SAA") \
    X(SE_HI_TURUN, "SE-HI-TURUN") \
    X(SE_TRACK_MOVE, "SE-TRACK-MOVE") \
    X(SE_TRACK_STOP, "SE-TRACK-STOP") \
    X(SE_TRACK_HAIKI, "SE-TRACK-HAIKI") \
    X(SE_TRACK_DOOR, "SE-TRACK-DOOR") \
    X(SE_MOTER, "SE-MOTER") \
    X(SE_CARD, "SE-CARD") \
    X(SE_SAVE, "SE-SAVE") \
    X(SE_KON, "SE-KON") \
    X(SE_KON2, "SE-KON2") \
    X(SE_KON3, "SE-KON3") \
    X(SE_KON4, "SE-KON4") \
    X(SE_SUIKOMU, "SE-SUIKOMU") \
    X(SE_NAGERU, "SE-NAGERU") \
    X(SE_TOY_C, "SE-TOY-C") \
    X(SE_TOY_D, "SE-TOY-D") \
    X(SE_TOY_E, "SE-TOY-E") \
    X(SE_TOY_F, "SE-TOY-F") \
    X(SE_TOY_G, "SE-TOY-G") \
    X(SE_TOY_A, "SE-TOY-A") \
    X(SE_TOY_B, "SE-TOY-B") \
    X(SE_TOY_C1, "SE-TOY-C1") \
    X(SE_MIZU, "SE-MIZU") \
    X(SE_HASHI, "SE-HASHI") \
    X(SE_DAUGI, "SE-DAUGI") \
    X(SE_PINPON, "SE-PINPON") \
    X(SE_FUUSEN1, "SE-FUUSEN1") \
    X(SE_FUUSEN2, "SE-FUUSEN2") \
    X(SE_FUUSEN3, "SE-FUUSEN3") \
    X(SE_TOY_KABE, "SE-TOY-KABE") \
    X(SE_TOY_DANGO, "SE-TOY-DANGO") \
    X(SE_DOKU, "SE-DOKU") \
    X(SE_ESUKA, "SE-ESUKA") \
    X(SE_T_AME, "SE-T-AME") \
    X(SE_T_AME_E, "SE-T-AME-E") \
    X(SE_T_OOAME, "SE-T-OOAME") \
    X(SE_T_OOAME_E, "SE-T-OOAME-E") \
    X(SE_T_KOAME, "SE-T-KOAME") \
    X(SE_T_KOAME_E, "SE-T-KOAME-E") \
    X(SE_T_KAMI, "SE-T-KAMI") \
    X(SE_T_KAMI2, "SE-T-KAMI2") \
    X(SE_ELEBETA, "SE-ELEBETA") \
    X(SE_HINSI, "SE-HINSI") \
    X(SE_EXPMAX, "SE-EXPMAX") \
    X(SE_TAMAKORO, "SE-TAMAKORO") \
    X(SE_TAMAKORO_E, "SE-TAMAKORO-E") \
    X(SE_BASABASA, "SE-BASABASA") \
    X(SE_REGI, "SE-REGI") \
    X(SE_C_GAJI, "SE-C-GAJI") \
    X(SE_C_MAKU_U, "SE-C-MAKU-U") \
    X(SE_C_MAKU_D, "SE-C-MAKU-D") \
    X(SE_C_PASI, "SE-C-PASI") \
    X(SE_C_SYU, "SE-C-SYU") \
    X(SE_C_PIKON, "SE-C-PIKON") \
    X(SE_REAPOKE, "SE-REAPOKE") \
    X(SE_OP_BASYU, "SE-OP-BASYU") \
    X(SE_BT_START, "SE-BT-START") \
    X(SE_DENDOU, "SE-DENDOU") \
    X(SE_JIHANKI, "SE-JIHANKI") \
    X(SE_TAMA, "SE-TAMA") \
    X(SE_Z_SCROLL, "SE-Z-SCROLL") \
    X(SE_Z_PAGE, "SE-Z-PAGE") \
    X(SE_PN_ON, "SE-PN-ON") \
    X(SE_PN_OFF, "SE-PN-OFF") \
    X(SE_Z_SEARCH, "SE-Z-SEARCH") \
    X(SE_TAMAGO, "SE-TAMAGO") \
    X(SE_TB_START, "SE-TB-START") \
    X(SE_TB_KON, "SE-TB-KON") \
    X(SE_TB_KARA, "SE-TB-KARA") \
    X(SE_BIDORO, "SE-BIDORO") \
    X(SE_W085, "SE-W085") \
    X(SE_W085B, "SE-W085B") \
    X(SE_W231, "SE-W231") \
    X(SE_W171, "SE-W171") \
    X(SE_W233, "SE-W233") \
    X(SE_W233B, "SE-W233B") \
    X(SE_W145, "SE-W145") \
    X(SE_W145B, "SE-W145B") \
    X(SE_W145C, "SE-W145C") \
    X(SE_W240, "SE-W240") \
    X(SE_W015, "SE-W015") \
    X(SE_W081, "SE-W081") \
    X(SE_W081B, "SE-W081B") \
    X(SE_W088, "SE-W088") \
    X(SE_W016, "SE-W016") \
    X(SE_W016B, "SE-W016B") \
    X(SE_W003, "SE-W003") \
    X(SE_W104, "SE-W104") \
    X(SE_W013, "SE-W013") \
    X(SE_W196, "SE-W196") \
    X(SE_W086, "SE-W086") \
    X(SE_W004, "SE-W004") \
    X(SE_W025, "SE-W025") \
    X(SE_W025B, "SE-W025B") \
    X(SE_W152, "SE-W152") \
    X(SE_W026, "SE-W026") \
    X(SE_W172, "SE-W172") \
    X(SE_W172B, "SE-W172B") \
    X(SE_W053, "SE-W053") \
    X(SE_W007, "SE-W007") \
    X(SE_W092, "SE-W092") \
    X(SE_W221, "SE-W221") \
    X(SE_W221B, "SE-W221B") \
    X(SE_W052, "SE-W052") \
    X(SE_W036, "SE-W036") \
    X(SE_W059, "SE-W059") \
    X(SE_W059B, "SE-W059B") \
    X(SE_W010, "SE-W010") \
    X(SE_W011, "SE-W011") \
    X(SE_W017, "SE-W017") \
    X(SE_W019, "SE-W019") \
    X(SE_W028, "SE-W028") \
    X(SE_W013B, "SE-W013B") \
    X(SE_W044, "SE-W044") \
    X(SE_W029, "SE-W029") \
    X(SE_W057, "SE-W057") \
    X(SE_W056, "SE-W056") \
    X(SE_W250, "SE-W250") \
    X(SE_W030, "SE-W030") \
    X(SE_W039, "SE-W039") \
    X(SE_W054, "SE-W054") \
    X(SE_W077, "SE-W077") \
    X(SE_W020, "SE-W020") \
    X(SE_W082, "SE-W082") \
    X(SE_W047, "SE-W047") \
    X(SE_W195, "SE-W195") \
    X(SE_W006, "SE-W006") \
    X(SE_W091, "SE-W091") \
    X(SE_W146, "SE-W146") \
    X(SE_W120, "SE-W120") \
    X(SE_W153, "SE-W153") \
    X(SE_W071B, "SE-W071B") \
    X(SE_W071, "SE-W071") \
    X(SE_W103, "SE-W103") \
    X(SE_W062, "SE-W062") \
    X(SE_W062B, "SE-W062B") \
    X(SE_W048, "SE-W048") \
    X(SE_W187, "SE-W187") \
    X(SE_W118, "SE-W118") \
    X(SE_W155, "SE-W155") \
    X(SE_W122, "SE-W122") \
    X(SE_W060, "SE-W060") \
    X(SE_W185, "SE-W185") \
    X(SE_W014, "SE-W014") \
    X(SE_W043, "SE-W043") \
    X(SE_W207, "SE-W207") \
    X(SE_W207B, "SE-W207B") \
    X(SE_W215, "SE-W215") \
    X(SE_W109, "SE-W109") \
    X(SE_W173, "SE-W173") \
    X(SE_W280, "SE-W280") \
    X(SE_W202, "SE-W202") \
    X(SE_W060B, "SE-W060B") \
    X(SE_W076, "SE-W076") \
    X(SE_W080, "SE-W080") \
    X(SE_W100, "SE-W100") \
    X(SE_W107, "SE-W107") \
    X(SE_W166, "SE-W166") \
    X(SE_W129, "SE-W129") \
    X(SE_W115, "SE-W115") \
    X(SE_W112, "SE-W112") \
    X(SE_W197, "SE-W197") \
    X(SE_W199, "SE-W199") \
    X(SE_W236, "SE-W236") \
    X(SE_W204, "SE-W204") \
    X(SE_W268, "SE-W268") \
    X(SE_W070, "SE-W070") \
    X(SE_W063, "SE-W063") \
    X(SE_W127, "SE-W127") \
    X(SE_W179, "SE-W179") \
    X(SE_W151, "SE-W151") \
    X(SE_W201, "SE-W201") \
    X(SE_W161, "SE-W161") \
    X(SE_W161B, "SE-W161B") \
    X(SE_W227, "SE-W227") \
    X(SE_W227B, "SE-W227B") \
    X(SE_W226, "SE-W226") \
    X(SE_W208, "SE-W208") \
    X(SE_W213, "SE-W213") \
    X(SE_W213B, "SE-W213B") \
    X(SE_W234, "SE-W234") \
    X(SE_W260, "SE-W260") \
    X(SE_W328, "SE-W328") \
    X(SE_W320, "SE-W320") \
    X(SE_W255, "SE-W255") \
    X(SE_W291, "SE-W291") \
    X(SE_W089, "SE-W089") \
    X(SE_W239, "SE-W239") \
    X(SE_W230, "SE-W230") \
    X(SE_W281, "SE-W281") \
    X(SE_W327, "SE-W327") \
    X(SE_W287, "SE-W287") \
    X(SE_W257, "SE-W257") \
    X(SE_W253, "SE-W253") \
    X(SE_W258, "SE-W258") \
    X(SE_W322, "SE-W322") \
    X(SE_W298, "SE-W298") \
    X(SE_W287B, "SE-W287B") \
    X(SE_W114, "SE-W114") \
    X(SE_W063B, "SE-W063B") \
    X(SE_RG_W_DOOR, "SE-RG-W-DOOR") \
    X(SE_RG_CARD1, "SE-RG-CARD1") \
    X(SE_RG_CARD2, "SE-RG-CARD2") \
    X(SE_RG_CARD3, "SE-RG-CARD3") \
    X(SE_RG_BAG1, "SE-RG-BAG1") \
    X(SE_RG_BAG2, "SE-RG-BAG2") \
    X(SE_RG_GETTING, "SE-RG-GETTING") \
    X(SE_RG_SHOP, "SE-RG-SHOP") \
    X(SE_RG_KITEKI, "SE-RG-KITEKI") \
    X(SE_RG_HELP_OP, "SE-RG-HELP-OP") \
    X(SE_RG_HELP_CL, "SE-RG-HELP-CL") \
    X(SE_RG_HELP_NG, "SE-RG-HELP-NG") \
    X(SE_RG_DEOMOV, "SE-RG-DEOMOV") \
    X(SE_RG_EXCELLENT, "SE-RG-EXCELLENT") \
    X(SE_RG_NAWAMISS, "SE-RG-NAWAMISS") \
    X(SE_TOREEYE, "SE-TOREEYE") \
    X(SE_TOREOFF, "SE-TOREOFF") \
    X(SE_HANTEI1, "SE-HANTEI1") \
    X(SE_HANTEI2, "SE-HANTEI2") \
    X(SE_CURTAIN, "SE-CURTAIN") \
    X(SE_CURTAIN1, "SE-CURTAIN1") \
    X(SE_USSOKI, "SE-USSOKI")

// Create BGM list
#define X(songId, name) static const u8 sBGMName_##songId[] = _(name);
SOUND_LIST_BGM
#undef X

#define X(songId, name) sBGMName_##songId,
static const u8 *const gBGMNames[] =
{
SOUND_LIST_BGM
};
#undef X

// Create SE list
#define X(songId, name) static const u8 sSEName_##songId[] = _(name);
SOUND_LIST_SE
#undef X

#define X(songId, name) sSEName_##songId,
static const u8 *const gSENames[] =
{
SOUND_LIST_SE
};
#undef X

#undef tWindowSelected
#undef tBgmIndex
#undef tSeIndex
#undef tBgmIndexOld
#undef tSeIndexOld
#undef tWhichSubmenu
#undef tState
