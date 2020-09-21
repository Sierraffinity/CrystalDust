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
    PrintSoundNumber(gTasks[taskId].tBgmIndex + (MUS_LITTLEROOT_TEST - 1), WIN_MUS); // print by BGM index
    PrintPaddedString(gBGMNames[gTasks[taskId].tBgmIndex], WIN_MUS);
    FillWindowPixelRect(WIN_SE, PIXEL_FILL(1), 0, 14, 224, 12);
    PrintSoundNumber(gTasks[taskId].tSeIndex, WIN_SE);
    PrintPaddedString(gSENames[gTasks[taskId].tSeIndex], WIN_SE);
    gTasks[taskId].func = Task_ProcessSoundCheckMenuInputAndRedraw;
}

static bool8 Task_ProcessSoundCheckMenuInput(u8 taskId) // sub_080E8688
{
    if (JOY_NEW(R_BUTTON)) // driver test
    {
        gTasks[taskId].tWhichSubmenu = 1;
        gTasks[taskId].tState = 0;
        gTasks[taskId].func = Task_DrawSubmenu;
    }
    else if (JOY_NEW(L_BUTTON))
    {
        gTasks[taskId].tWhichSubmenu = 0;
        gTasks[taskId].tState = 0;
        gTasks[taskId].func = Task_DrawSubmenu;
    }
    else if (JOY_NEW(A_BUTTON))
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
                    m4aSongNumStop(gTasks[taskId].tBgmIndexOld + (MUS_LITTLEROOT_TEST - 1));
                    m4aSongNumStart(gTasks[taskId].tBgmIndex + (MUS_LITTLEROOT_TEST - 1));
                    gTasks[taskId].tBgmIndexOld = gTasks[taskId].tBgmIndex;
                }
                else
                {
                    m4aSongNumStop(gTasks[taskId].tBgmIndexOld + (MUS_LITTLEROOT_TEST - 1));
                    gTasks[taskId].tBgmIndexOld = 0;
                }
            }
            else if (gTasks[taskId].tBgmIndex != 0)
            {
                m4aSongNumStart(gTasks[taskId].tBgmIndex + (MUS_LITTLEROOT_TEST - 1));
                gTasks[taskId].tBgmIndexOld = gTasks[taskId].tBgmIndex;
            }
        }
    }
    else if (JOY_NEW(B_BUTTON))
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
                gTasks[taskId].tSeIndex = SE_SUDOWOODO_SHAKE;
        }
        else
        {
            if (gTasks[taskId].tBgmIndex > 0)
                gTasks[taskId].tBgmIndex--;
            else
                gTasks[taskId].tBgmIndex = (PH_NURSE_SOLO - (MUS_LITTLEROOT_TEST - 1));
        }
        return TRUE;
    }
    else if (gMain.newAndRepeatedKeys & DPAD_RIGHT)
    {
        if (gTasks[taskId].tWindowSelected != TEST_MUS)
        {
            if (gTasks[taskId].tSeIndex < SE_SUDOWOODO_SHAKE)
                gTasks[taskId].tSeIndex++;
            else
                gTasks[taskId].tSeIndex = 0;
        }
        else
        {
            if (gTasks[taskId].tBgmIndex < (PH_NURSE_SOLO - (MUS_LITTLEROOT_TEST - 1)))
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
    if (JOY_NEW(B_BUTTON))
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
    if (JOY_NEW(START_BUTTON))
    {
        sDriverTest_Reverse ^= 1;
        PrintDriverTestMenuText();
        return;
    }
    if (JOY_NEW(SELECT_BUTTON))
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
    if (JOY_NEW(A_BUTTON))
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

    if (JOY_NEW(B_BUTTON))
    {
        gTasks[taskId].tState = 0;
        gTasks[taskId].func = Task_InitSoundCheckMenu;
        return;
    }
    if (JOY_NEW(A_BUTTON))
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
    if (JOY_NEW(L_BUTTON))
    {
        sSoundTestParams[CRY_TEST_PANPOT]++;
        if (sSoundTestParams[CRY_TEST_PANPOT] > 4)
            sSoundTestParams[CRY_TEST_PANPOT] = 0;
        PrintPanTestMenuText();
    }
    if (JOY_NEW(R_BUTTON))
    {
        sSoundTestParams[CRY_TEST_PANPOT]--;
        if (sSoundTestParams[CRY_TEST_PANPOT] < 0)
            sSoundTestParams[CRY_TEST_PANPOT] = 4;
        PrintPanTestMenuText();
    }
    if (gMain.newAndRepeatedKeys & DPAD_RIGHT)
    {
        sSoundTestParams[CRY_TEST_VOICE]++;
        if (sSoundTestParams[CRY_TEST_VOICE] > SE_SUDOWOODO_SHAKE)
            sSoundTestParams[CRY_TEST_VOICE] = MUS_DUMMY;
        PrintPanTestMenuText();
    }
    else if (gMain.newAndRepeatedKeys & DPAD_LEFT)
    {
        sSoundTestParams[CRY_TEST_VOICE]--;
        if (sSoundTestParams[CRY_TEST_VOICE] < MUS_DUMMY)
            sSoundTestParams[CRY_TEST_VOICE] = SE_SUDOWOODO_SHAKE;
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
    X(MUS_LITTLEROOT_TEST, "MUS-TETSUJI") \
    X(MUS_GSC_ROUTE38, "MUS-FIELD13") \
    X(MUS_CAUGHT, "MUS-WILDPOSTCATCH") \
    X(MUS_VICTORY_WILD, "MUS-WILDDEFEAT") \
    X(MUS_VICTORY_GYM_LEADER, "MUS-KACHI3") \
    X(MUS_VICTORY_LEAGUE, "MUS-KACHI5") \
    X(MUS_C_COMM_CENTER, "MUS-PCC") \
    X(MUS_GSC_PEWTER, "MUS-NIBI") \
    X(MUS_C_VS_LEGEND_BEAST, "MUS-SUIKUN") \
    X(MUS_ROUTE29, "MUS-ROUTE29") \
    X(MUS_ROUTE34, "MUS-ROUTE34") \
    X(MUS_ROUTE120, "MUS-DOORO-X3") \
    X(MUS_VIOLET, "MUS-VIOLET") \
    X(MUS_CHERRYGROVE, "MUS-CHERRYGROVE") \
    X(MUS_GYM, "MUS-GYM") \
    X(MUS_SURF, "MUS-NAMINORI") \
    X(MUS_ILEXFOREST, "MUS-ILEXFOREST") \
    X(MUS_LEVEL_UP, "MUS-FANFA1") \
    X(MUS_HEAL, "MUS-ME-ASA") \
    X(MUS_OBTAIN_BADGE, "MUS-ME-BACHI") \
    X(MUS_OBTAIN_ITEM, "MUS-FANFA4") \
    X(MUS_EVOLVED, "MUS-FANFA5") \
    X(MUS_OBTAIN_TMHM, "MUS-ME-WAZA") \
    X(MUS_RUINSOFALPH, "MUS-RUINSOFALPH") \
    X(MUS_ROUTE30, "MUS-ROUTE30") \
    X(MUS_BUENA, "MUS-BUENA") \
    X(MUS_EVOLUTION_INTRO, "MUS-ME-SHINKA") \
    X(MUS_EVOLUTION, "MUS-SHINKA") \
    X(MUS_MOVE_DELETED, "MUS-ME-WASURE") \
    X(MUS_ENCOUNTER_LASS, "MUS-ENCFEMALECLASSIC") \
    X(MUS_ENCOUNTER_MALE, "MUS-ENCMALE") \
    X(MUS_DARKCAVE, "MUS-DARKCAVE") \
    X(MUS_FORTREE, "MUS-MACHI-S3") \
    X(MUS_ELMSLAB, "MUS-ELMSLAB") \
    X(MUS_B_TOWER_RS, "MUS-B-TOWER") \
    X(MUS_ENCOUNTER_SWIMMER, "MUS-SWIMEYE") \
    X(MUS_CAVE_OF_ORIGIN, "MUS-DAN03") \
    X(MUS_FANFAREEGG, "MUS-FANFAREEGG") \
    X(MUS_AWAKEN_LEGEND, "MUS-ME-TAMA") \
    X(MUS_SLOTS_JACKPOT, "MUS-ME-B-BIG") \
    X(MUS_SLOTS_WIN, "MUS-ME-B-SMALL") \
    X(MUS_TOO_BAD, "MUS-ME-ZANNEN") \
    X(MUS_ROULETTE, "MUS-BD-TIME") \
    X(MUS_LINK_CONTEST_P1, "MUS-TEST1") \
    X(MUS_LINK_CONTEST_P2, "MUS-TEST2") \
    X(MUS_LINK_CONTEST_P3, "MUS-TEST3") \
    X(MUS_LINK_CONTEST_P4, "MUS-TEST4") \
    X(MUS_POKEMONMARCH, "MUS-POKEMONMARCH") \
    X(MUS_VERDANTURF, "MUS-GOMACHI0") \
    X(MUS_GOLDENROD, "MUS-GOTOWN") \
    X(MUS_POKE_CENTER, "MUS-POKECEN") \
    X(MUS_ROUTE104, "MUS-NEXTROAD") \
    X(MUS_ROUTE119, "MUS-GRANROAD") \
    X(MUS_CYCLING, "MUS-CYCLING") \
    X(MUS_PKMNLULLABY, "MUS-FRIENDLY") \
    X(MUS_NEWBARK, "MUS-NEWBARK") \
    X(MUS_MT_CHIMNEY, "MUS-TOZAN") \
    X(MUS_ENCOUNTER_FEMALE, "MUS-ENCFEMALE") \
    X(MUS_LILYCOVE, "MUS-MINAMO") \
    X(MUS_ROUTE111, "MUS-ASHROAD") \
    X(MUS_MOMSTHEME, "MUS-MOMENC") \
    X(MUS_UNDERWATER, "MUS-DEEPDEEP") \
    X(MUS_VICTORY_TRAINER, "MUS-KACHI1") \
    X(MUS_TITLE, "MUS-TITLE3") \
    X(MUS_INTRO, "MUS-DEMO1") \
    X(MUS_ENCOUNTER_RIVAL, "MUS-RIVALENC") \
    X(MUS_ENCOUNTER_SAGE, "MUS-ENCSAGE") \
    X(MUS_ENCOUNTER_OFFICER, "MUS-ENCMALECLASSIC") \
    X(MUS_MAINMENU, "MUS-MAINMENU") \
    X(MUS_ENCOUNTER_ROCKET, "MUS-ENCROCKET") \
    X(MUS_FOLLOW_ME, "MUS-FOLLOWME") \
    X(MUS_RIVALEXIT, "MUS-RIVALEXIT") \
    X(MUS_EVER_GRANDE, "MUS-RAINBOW") \
    X(MUS_ENCOUNTER_SUSPICIOUS, "MUS-ENCSUSPICIOUS") \
    X(MUS_VICTORY_AQUA_MAGMA, "MUS-KACHI4") \
    X(MUS_CABLE_CAR, "MUS-ROPEWAY") \
    X(MUS_GAME_CORNER, "MUS-CASINO") \
    X(MUS_AZALEA, "MUS-AZALEA") \
    X(MUS_SAFARI_ZONE, "MUS-SAFARI") \
    X(MUS_VICTORY_ROAD, "MUS-C-ROAD") \
    X(MUS_AQUA_MAGMA_HIDEOUT, "MUS-AJITO") \
    X(MUS_SAILING, "MUS-M-BOAT") \
    X(MUS_SPROUTTOWER, "MUS-SPROUTTOWER") \
    X(MUS_SLATEPORT, "MUS-FINECITY") \
    X(MUS_MT_PYRE_EXTERIOR, "MUS-MACHUPI") \
    X(MUS_OAKSTHEME, "MUS-OAKSTHEME") \
    X(MUS_HALL_OF_FAME, "MUS-DENDOU") \
    X(MUS_FALLARBOR, "MUS-TONEKUSA") \
    X(MUS_SEALED_CHAMBER, "MUS-MABOROSI") \
    X(MUS_CONTEST_WINNER, "MUS-CON-FAN") \
    X(MUS_CONTEST, "MUS-CONTEST0") \
    X(MUS_OAKSLAB, "MUS-OAKSLAB") \
    X(MUS_ROCKETTAKEOVER, "MUS-ROCKETTAKEOVER") \
    X(MUS_ABNORMAL_WEATHER, "MUS-OOAME") \
    X(MUS_WEATHER_GROUDON, "MUS-HIDERI") \
    X(MUS_SOOTOPOLIS, "MUS-RUNECITY") \
    X(MUS_CONTEST_RESULTS, "MUS-CON-K") \
    X(MUS_HALL_OF_FAME_ROOM, "MUS-EIKOU-R") \
    X(MUS_TRICK_HOUSE, "MUS-KARAKURI") \
    X(MUS_ENCOUNTER_TWINS, "MUS-HUTAGO") \
    X(MUS_ENCOUNTER_ELITE_FOUR, "MUS-SITENNOU") \
    X(MUS_ENCOUNTER_FISHERMAN, "MUS-ENCSUSPICIOUSCLASSIC") \
    X(MUS_CONTEST_LOBBY, "MUS-CONLOBBY") \
    X(MUS_ENCOUNTER_KIMONO, "MUS-ENCKIMONO") \
    X(MUS_ENCOUNTER_CHAMPION, "MUS-DAIGO") \
    X(MUS_CREDITS, "MUS-THANKFOR") \
    X(MUS_END, "MUS-END") \
    X(MUS_B_FRONTIER, "MUS-B-FRONTIER") \
    X(MUS_B_ARENA, "MUS-B-ARENA") \
    X(MUS_OBTAIN_B_POINTS, "MUS-ME-POINTGET") \
    X(MUS_REGISTER_MATCH_CALL, "MUS-ME-TORE-EYE") \
    X(MUS_B_PYRAMID, "MUS-PYRAMID") \
    X(MUS_B_PYRAMID_TOP, "MUS-PYRAMID-TOP") \
    X(MUS_B_PALACE, "MUS-B-PALACE") \
    X(MUS_RAYQUAZA_APPEARS, "MUS-REKKUU-KOURIN") \
    X(MUS_B_TOWER, "MUS-SATTOWER") \
    X(MUS_OBTAIN_SYMBOL, "MUS-ME-SYMBOLGET") \
    X(MUS_B_DOME, "MUS-B-DOME") \
    X(MUS_B_PIKE, "MUS-B-TUBE") \
    X(MUS_B_FACTORY, "MUS-B-FACTORY") \
    X(MUS_VS_RAYQUAZA, "MUS-VS-REKKU") \
    X(MUS_VS_FRONTIER_BRAIN, "MUS-VS-FRONT") \
    X(MUS_VS_MEW, "MUS-VS-MEW") \
    X(MUS_B_DOME_LOBBY, "MUS-B-DOME1") \
    X(MUS_VS_JOHTO_WILD, "MUS-BTLJOHTOWILD") \
    X(MUS_VS_ROCKET, "MUS-BTLROCKET") \
    X(MUS_VS_JOHTO_TRAINER, "MUS-BTLJOHTOTRN") \
    X(MUS_VS_JOHTO_LEADER, "MUS-BTLJOHTOLDR") \
    X(MUS_VS_CHAMPION, "MUS-BATTLE33") \
    X(MUS_VS_REGI, "MUS-BATTLE36") \
    X(MUS_VS_KYOGRE_GROUDON, "MUS-BATTLE34") \
    X(MUS_VS_RIVAL, "MUS-BTLRIVAL") \
    X(MUS_VS_ELITE_FOUR, "MUS-BATTLE38") \
    X(MUS_VS_AQUA_MAGMA_LEADER, "MUS-BATTLE30") \
    X(MUS_RG_FOLLOW_ME, "MUS-RG-ANNAI") \
    X(MUS_RG_GAME_CORNER, "MUS-RG-SLOT") \
    X(MUS_RG_ROCKET_HIDEOUT, "MUS-RG-AJITO") \
    X(MUS_RG_GYM, "MUS-RG-GYM") \
    X(MUS_RG_JIGGLYPUFF, "MUS-RG-PURIN") \
    X(MUS_RG_INTRO_FIGHT, "MUS-RG-DEMO") \
    X(MUS_RG_TITLE, "MUS-RG-TITLE") \
    X(MUS_RG_CINNABAR, "MUS-RG-GUREN") \
    X(MUS_RG_LAVENDER, "MUS-RG-SHION") \
    X(MUS_RG_HEAL, "MUS-RG-KAIHUKU") \
    X(MUS_RG_CYCLING, "MUS-RG-CYCLING") \
    X(MUS_RG_ENCOUNTER_ROCKET, "MUS-RG-ROCKET") \
    X(MUS_RG_ENCOUNTER_GIRL, "MUS-RG-SHOUJO") \
    X(MUS_RG_ENCOUNTER_BOY, "MUS-RG-SHOUNEN") \
    X(MUS_RG_HALL_OF_FAME, "MUS-RG-DENDOU") \
    X(MUS_RG_VIRIDIAN_FOREST, "MUS-RG-T-MORI") \
    X(MUS_RG_MT_MOON, "MUS-RG-OTSUKIMI") \
    X(MUS_RG_POKE_MANSION, "MUS-RG-POKEYASHI") \
    X(MUS_RG_CREDITS, "MUS-RG-ENDING") \
    X(MUS_RG_ROUTE1, "MUS-RG-LOAD01") \
    X(MUS_RG_ROUTE24, "MUS-RG-OPENING") \
    X(MUS_RG_ROUTE3, "MUS-RG-LOAD02") \
    X(MUS_RG_ROUTE11, "MUS-RG-LOAD03") \
    X(MUS_RG_VICTORY_ROAD, "MUS-RG-CHAMP-R") \
    X(MUS_RG_VS_GYM_LEADER, "MUS-RG-VS-GYM") \
    X(MUS_RG_VS_TRAINER, "MUS-RG-VS-TORE") \
    X(MUS_RG_VS_WILD, "MUS-RG-VS-YASEI") \
    X(MUS_RG_VS_CHAMPION, "MUS-RG-VS-LAST") \
    X(MUS_RG_PALLET, "MUS-RG-MASARA") \
    X(MUS_RG_OAK_LAB, "MUS-RG-KENKYU") \
    X(MUS_RG_OAK, "MUS-RG-OHKIDO") \
    X(MUS_RG_POKE_CENTER, "MUS-RG-POKECEN") \
    X(MUS_RG_SS_ANNE, "MUS-RG-SANTOAN") \
    X(MUS_RG_SURF, "MUS-RG-NAMINORI") \
    X(MUS_RG_POKE_TOWER, "MUS-RG-P-TOWER") \
    X(MUS_RG_SILPH, "MUS-RG-SHIRUHU") \
    X(MUS_RG_FUCHSIA, "MUS-RG-HANADA") \
    X(MUS_RG_CELADON, "MUS-RG-TAMAMUSI") \
    X(MUS_RG_VICTORY_TRAINER, "MUS-RG-WIN-TRE") \
    X(MUS_RG_VICTORY_WILD, "MUS-RG-WIN-YASEI") \
    X(MUS_RG_VICTORY_GYM_LEADER, "MUS-RG-WIN-GYM") \
    X(MUS_RG_VERMILLION, "MUS-RG-KUCHIBA") \
    X(MUS_RG_PEWTER, "MUS-RG-NIBI") \
    X(MUS_RG_ENCOUNTER_RIVAL, "MUS-RG-RIVAL1") \
    X(MUS_RG_RIVAL_EXIT, "MUS-RG-RIVAL2") \
    X(MUS_RG_DEX_RATING, "MUS-RG-FAN2") \
    X(MUS_RG_OBTAIN_KEY_ITEM, "MUS-RG-FAN5") \
    X(MUS_RG_CAUGHT_INTRO, "MUS-RG-FAN6") \
    X(MUS_RG_PHOTO, "MUS-ME-RG-PHOTO") \
    X(MUS_RG_GAME_FREAK, "MUS-RG-TITLEROG") \
    X(MUS_RG_CAUGHT, "MUS-RG-GET-YASEI") \
    X(MUS_RG_NEW_GAME_INSTRUCT, "MUS-RG-SOUSA") \
    X(MUS_RG_NEW_GAME_INTRO, "MUS-RG-SEKAIKAN") \
    X(MUS_RG_NEW_GAME_EXIT, "MUS-RG-SEIBETU") \
    X(MUS_RG_POKE_JUMP, "MUS-RG-JUMP") \
    X(MUS_RG_UNION_ROOM, "MUS-RG-UNION") \
    X(MUS_RG_NET_CENTER, "MUS-RG-NETWORK") \
    X(MUS_RG_MYSTERY_GIFT, "MUS-RG-OKURIMONO") \
    X(MUS_RG_BERRY_PICK, "MUS-RG-KINOMIKUI") \
    X(MUS_RG_SEVII_CAVE, "MUS-RG-NANADUNGEON") \
    X(MUS_RG_TEACHY_TV_SHOW, "MUS-RG-OSHIE-TV") \
    X(MUS_RG_SEVII_ROUTE, "MUS-RG-NANASHIMA") \
    X(MUS_RG_SEVII_DUNGEON, "MUS-RG-NANAISEKI") \
    X(MUS_RG_SEVII_123, "MUS-RG-NANA123") \
    X(MUS_RG_SEVII_45, "MUS-RG-NANA45") \
    X(MUS_RG_SEVII_67, "MUS-RG-NANA67") \
    X(MUS_RG_POKE_FLUTE, "MUS-RG-POKEFUE") \
    X(MUS_RG_VS_DEOXYS, "MUS-RG-VS-DEO") \
    X(MUS_RG_VS_MEWTWO, "MUS-RG-VS-MYU2") \
    X(MUS_RG_VS_LEGEND, "MUS-RG-VS-DEN") \
    X(MUS_RG_ENCOUNTER_GYM_LEADER, "MUS-RG-EXEYE") \
    X(MUS_RG_ENCOUNTER_DEOXYS, "MUS-RG-DEOEYE") \
    X(MUS_RG_TRAINER_TOWER, "MUS-RG-T-TOWER") \
    X(MUS_RG_SLOW_PALLET, "MUS-RG-SLOWMASARA") \
    X(MUS_RG_TEACHY_TV_MENU, "MUS-RG-TVNOIZE") \
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
    X(SE_USE_ITEM, "SE-KAIFUKU") \
    X(SE_PC_LOGIN, "SE-PC-LOGIN") \
    X(SE_PC_OFF, "SE-PC-OFF") \
    X(SE_PC_ON, "SE-PC-ON") \
    X(SE_SELECT, "SE-SELECT") \
    X(SE_WIN_OPEN, "SE-WIN-OPEN") \
    X(SE_WALL_HIT, "SE-WALL-HIT") \
    X(SE_DOOR, "SE-DOOR") \
    X(SE_EXIT, "SE-KAIDAN") \
    X(SE_LEDGE, "SE-DANSA") \
    X(SE_BIKE_BELL, "SE-JITENSYA") \
    X(SE_NOT_EFFECTIVE, "SE-KOUKA-L") \
    X(SE_EFFECTIVE, "SE-KOUKA-M") \
    X(SE_SUPER_EFFECTIVE, "SE-KOUKA-H") \
    X(SE_BALL_OPEN, "SE-BOWA2") \
    X(SE_FAINT, "SE-POKE-DEAD") \
    X(SE_FLEE, "SE-NIGERU") \
    X(SE_SLIDING_DOOR, "SE-JIDO-DOA") \
    X(SE_SHIP, "SE-NAMINORI") \
    X(SE_BANG, "SE-BAN") \
    X(SE_PIN, "SE-PIN") \
    X(SE_BOO, "SE-BOO") \
    X(SE_BALL, "SE-BOWA") \
    X(SE_CONTEST_PLACE, "SE-JYUNI") \
    X(SE_A, "SE-A") \
    X(SE_I, "SE-I") \
    X(SE_U, "SE-U") \
    X(SE_E, "SE-E") \
    X(SE_O, "SE-O") \
    X(SE_N, "SE-N") \
    X(SE_SUCCESS, "SE-SEIKAI") \
    X(SE_FAILURE, "SE-HAZURE") \
    X(SE_EXP, "SE-EXP") \
    X(SE_BIKE_HOP, "SE-JITE-PYOKO") \
    X(SE_SWITCH, "SE-MU-PACHI") \
    X(SE_CLICK, "SE-TK-KASYA") \
    X(SE_FU_ZAKU, "SE-FU-ZAKU") \
    X(SE_CONTEST_CONDITION_LOSE, "SE-FU-ZAKU2") \
    X(SE_LAVARIDGE_FALL_WARP, "SE-FU-ZUZUZU") \
    X(SE_ICE_STAIRS, "SE-RU-GASHIN") \
    X(SE_ICE_BREAK, "SE-RU-GASYAN") \
    X(SE_ICE_CRACK, "SE-RU-BARI") \
    X(SE_FALL, "SE-RU-HYUU") \
    X(SE_UNLOCK, "SE-KI-GASYAN") \
    X(SE_WARP_IN, "SE-TK-WARPIN") \
    X(SE_WARP_OUT, "SE-TK-WARPOUT") \
    X(SE_REPEL, "SE-TU-SAA") \
    X(SE_ROTATING_GATE, "SE-HI-TURUN") \
    X(SE_TRUCK_MOVE, "SE-TRACK-MOVE") \
    X(SE_TRUCK_STOP, "SE-TRACK-STOP") \
    X(SE_TRUCK_UNLOAD, "SE-TRACK-HAIKI") \
    X(SE_TRUCK_DOOR, "SE-TRACK-DOOR") \
    X(SE_BERRY_BLENDER, "SE-MOTER") \
    X(SE_CARD, "SE-CARD") \
    X(SE_SAVE, "SE-SAVE") \
    X(SE_BALL_BOUNCE_1, "SE-KON") \
    X(SE_BALL_BOUNCE_2, "SE-KON2") \
    X(SE_BALL_BOUNCE_3, "SE-KON3") \
    X(SE_BALL_BOUNCE_4, "SE-KON4") \
    X(SE_BALL_TRADE, "SE-SUIKOMU") \
    X(SE_BALL_THROW, "SE-NAGERU") \
    X(SE_NOTE_C, "SE-TOY-C") \
    X(SE_NOTE_D, "SE-TOY-D") \
    X(SE_NOTE_E, "SE-TOY-E") \
    X(SE_NOTE_F, "SE-TOY-F") \
    X(SE_NOTE_G, "SE-TOY-G") \
    X(SE_NOTE_A, "SE-TOY-A") \
    X(SE_NOTE_B, "SE-TOY-B") \
    X(SE_NOTE_C_HIGH, "SE-TOY-C1") \
    X(SE_PUDDLE, "SE-MIZU") \
    X(SE_BRIDGE_WALK, "SE-HASHI") \
    X(SE_ITEMFINDER, "SE-DAUGI") \
    X(SE_DING_DONG, "SE-PINPON") \
    X(SE_BALLOON_RED, "SE-FUUSEN1") \
    X(SE_BALLOON_BLUE, "SE-FUUSEN2") \
    X(SE_BALLOON_YELLOW, "SE-FUUSEN3") \
    X(SE_BREAKABLE_DOOR, "SE-TOY-KABE") \
    X(SE_MUD_BALL, "SE-TOY-DANGO") \
    X(SE_FIELD_POISON, "SE-DOKU") \
    X(SE_ESCALATOR, "SE-ESUKA") \
    X(SE_THUNDERSTORM, "SE-T-AME") \
    X(SE_THUNDERSTORM_STOP, "SE-T-AME-E") \
    X(SE_DOWNPOUR, "SE-T-OOAME") \
    X(SE_DOWNPOUR_STOP, "SE-T-OOAME-E") \
    X(SE_RAIN, "SE-T-KOAME") \
    X(SE_RAIN_STOP, "SE-T-KOAME-E") \
    X(SE_THUNDER, "SE-T-KAMI") \
    X(SE_THUNDER2, "SE-T-KAMI2") \
    X(SE_ELEVATOR, "SE-ELEBETA") \
    X(SE_LOW_HEALTH, "SE-HINSI") \
    X(SE_EXP_MAX, "SE-EXPMAX") \
    X(SE_ROULETTE_BALL, "SE-TAMAKORO") \
    X(SE_ROULETTE_BALL2, "SE-TAMAKORO-E") \
    X(SE_TAILLOW_WING_FLAP, "SE-BASABASA") \
    X(SE_SHOP, "SE-REGI") \
    X(SE_CONTEST_HEART, "SE-C-GAJI") \
    X(SE_CONTEST_CURTAIN_RISE, "SE-C-MAKU-U") \
    X(SE_CONTEST_CURTAIN_FALL, "SE-C-MAKU-D") \
    X(SE_CONTEST_ICON_CHANGE, "SE-C-PASI") \
    X(SE_CONTEST_ICON_CLEAR, "SE-C-SYU") \
    X(SE_CONTEST_MONS_TURN, "SE-C-PIKON") \
    X(SE_SHINY, "SE-REAPOKE") \
    X(SE_INTRO_BLAST, "SE-OP-BASYU") \
    X(SE_MUGSHOT, "SE-BT-START") \
    X(SE_APPLAUSE, "SE-DENDOU") \
    X(SE_VEND, "SE-JIHANKI") \
    X(SE_ORB, "SE-TAMA") \
    X(SE_DEX_SCROLL, "SE-Z-SCROLL") \
    X(SE_DEX_PAGE, "SE-Z-PAGE") \
    X(SE_POKENAV_ON, "SE-PN-ON") \
    X(SE_POKENAV_OFF, "SE-PN-OFF") \
    X(SE_DEX_SEARCH, "SE-Z-SEARCH") \
    X(SE_EGG_HATCH, "SE-TAMAGO") \
    X(SE_BALL_TRAY_ENTER, "SE-TB-START") \
    X(SE_BALL_TRAY_BALL, "SE-TB-KON") \
    X(SE_BALL_TRAY_EXIT, "SE-TB-KARA") \
    X(SE_GLASS_FLUTE, "SE-BIDORO") \
    X(SE_M_THUNDERBOLT, "SE-W085") \
    X(SE_M_THUNDERBOLT2, "SE-W085B") \
    X(SE_M_HARDEN, "SE-W231") \
    X(SE_M_NIGHTMARE, "SE-W171") \
    X(SE_M_VITAL_THROW, "SE-W233") \
    X(SE_M_VITAL_THROW2, "SE-W233B") \
    X(SE_M_BUBBLE, "SE-W145") \
    X(SE_M_BUBBLE2, "SE-W145B") \
    X(SE_M_BUBBLE3, "SE-W145C") \
    X(SE_M_RAIN_DANCE, "SE-W240") \
    X(SE_M_CUT, "SE-W015") \
    X(SE_M_STRING_SHOT, "SE-W081") \
    X(SE_M_STRING_SHOT2, "SE-W081B") \
    X(SE_M_ROCK_THROW, "SE-W088") \
    X(SE_M_GUST, "SE-W016") \
    X(SE_M_GUST2, "SE-W016B") \
    X(SE_M_DOUBLE_SLAP, "SE-W003") \
    X(SE_M_DOUBLE_TEAM, "SE-W104") \
    X(SE_M_RAZOR_WIND, "SE-W013") \
    X(SE_M_ICY_WIND, "SE-W196") \
    X(SE_M_THUNDER_WAVE, "SE-W086") \
    X(SE_M_COMET_PUNCH, "SE-W004") \
    X(SE_M_MEGA_KICK, "SE-W025") \
    X(SE_M_MEGA_KICK2, "SE-W025B") \
    X(SE_M_CRABHAMMER, "SE-W152") \
    X(SE_M_JUMP_KICK, "SE-W026") \
    X(SE_M_FLAME_WHEEL, "SE-W172") \
    X(SE_M_FLAME_WHEEL2, "SE-W172B") \
    X(SE_M_FLAMETHROWER, "SE-W053") \
    X(SE_M_FIRE_PUNCH, "SE-W007") \
    X(SE_M_TOXIC, "SE-W092") \
    X(SE_M_SACRED_FIRE, "SE-W221") \
    X(SE_M_SACRED_FIRE2, "SE-W221B") \
    X(SE_M_EMBER, "SE-W052") \
    X(SE_M_TAKE_DOWN, "SE-W036") \
    X(SE_M_BLIZZARD, "SE-W059") \
    X(SE_M_BLIZZARD2, "SE-W059B") \
    X(SE_M_SCRATCH, "SE-W010") \
    X(SE_M_VICEGRIP, "SE-W011") \
    X(SE_M_WING_ATTACK, "SE-W017") \
    X(SE_M_FLY, "SE-W019") \
    X(SE_M_SAND_ATTACK, "SE-W028") \
    X(SE_M_RAZOR_WIND2, "SE-W013B") \
    X(SE_M_BITE, "SE-W044") \
    X(SE_M_HEADBUTT, "SE-W029") \
    X(SE_M_SURF, "SE-W057") \
    X(SE_M_HYDRO_PUMP, "SE-W056") \
    X(SE_M_WHIRLPOOL, "SE-W250") \
    X(SE_M_HORN_ATTACK, "SE-W030") \
    X(SE_M_TAIL_WHIP, "SE-W039") \
    X(SE_M_MIST, "SE-W054") \
    X(SE_M_POISON_POWDER, "SE-W077") \
    X(SE_M_BIND, "SE-W020") \
    X(SE_M_DRAGON_RAGE, "SE-W082") \
    X(SE_M_SING, "SE-W047") \
    X(SE_M_PERISH_SONG, "SE-W195") \
    X(SE_M_PAY_DAY, "SE-W006") \
    X(SE_M_DIG, "SE-W091") \
    X(SE_M_DIZZY_PUNCH, "SE-W146") \
    X(SE_M_SELF_DESTRUCT, "SE-W120") \
    X(SE_M_EXPLOSION, "SE-W153") \
    X(SE_M_ABSORB_2, "SE-W071B") \
    X(SE_M_ABSORB, "SE-W071") \
    X(SE_M_SCREECH, "SE-W103") \
    X(SE_M_BUBBLE_BEAM, "SE-W062") \
    X(SE_M_BUBBLE_BEAM2, "SE-W062B") \
    X(SE_M_SUPERSONIC, "SE-W048") \
    X(SE_M_BELLY_DRUM, "SE-W187") \
    X(SE_M_METRONOME, "SE-W118") \
    X(SE_M_BONEMERANG, "SE-W155") \
    X(SE_M_LICK, "SE-W122") \
    X(SE_M_PSYBEAM, "SE-W060") \
    X(SE_M_FAINT_ATTACK, "SE-W185") \
    X(SE_M_SWORDS_DANCE, "SE-W014") \
    X(SE_M_LEER, "SE-W043") \
    X(SE_M_SWAGGER, "SE-W207") \
    X(SE_M_SWAGGER2, "SE-W207B") \
    X(SE_M_HEAL_BELL, "SE-W215") \
    X(SE_M_CONFUSE_RAY, "SE-W109") \
    X(SE_M_SNORE, "SE-W173") \
    X(SE_M_BRICK_BREAK, "SE-W280") \
    X(SE_M_GIGA_DRAIN, "SE-W202") \
    X(SE_M_PSYBEAM2, "SE-W060B") \
    X(SE_M_SOLAR_BEAM, "SE-W076") \
    X(SE_M_PETAL_DANCE, "SE-W080") \
    X(SE_M_TELEPORT, "SE-W100") \
    X(SE_M_MINIMIZE, "SE-W107") \
    X(SE_M_SKETCH, "SE-W166") \
    X(SE_M_SWIFT, "SE-W129") \
    X(SE_M_REFLECT, "SE-W115") \
    X(SE_M_BARRIER, "SE-W112") \
    X(SE_M_DETECT, "SE-W197") \
    X(SE_M_LOCK_ON, "SE-W199") \
    X(SE_M_MOONLIGHT, "SE-W236") \
    X(SE_M_CHARM, "SE-W204") \
    X(SE_M_CHARGE, "SE-W268") \
    X(SE_M_STRENGTH, "SE-W070") \
    X(SE_M_HYPER_BEAM, "SE-W063") \
    X(SE_M_WATERFALL, "SE-W127") \
    X(SE_M_REVERSAL, "SE-W179") \
    X(SE_M_ACID_ARMOR, "SE-W151") \
    X(SE_M_SANDSTORM, "SE-W201") \
    X(SE_M_TRI_ATTACK, "SE-W161") \
    X(SE_M_TRI_ATTACK2, "SE-W161B") \
    X(SE_M_ENCORE, "SE-W227") \
    X(SE_M_ENCORE2, "SE-W227B") \
    X(SE_M_BATON_PASS, "SE-W226") \
    X(SE_M_MILK_DRINK, "SE-W208") \
    X(SE_M_ATTRACT, "SE-W213") \
    X(SE_M_ATTRACT2, "SE-W213B") \
    X(SE_M_MORNING_SUN, "SE-W234") \
    X(SE_M_FLATTER, "SE-W260") \
    X(SE_M_SAND_TOMB, "SE-W328") \
    X(SE_M_GRASSWHISTLE, "SE-W320") \
    X(SE_M_SPIT_UP, "SE-W255") \
    X(SE_M_DIVE, "SE-W291") \
    X(SE_M_EARTHQUAKE, "SE-W089") \
    X(SE_M_TWISTER, "SE-W239") \
    X(SE_M_SWEET_SCENT, "SE-W230") \
    X(SE_M_YAWN, "SE-W281") \
    X(SE_M_SKY_UPPERCUT, "SE-W327") \
    X(SE_M_STAT_INCREASE, "SE-W287") \
    X(SE_M_HEAT_WAVE, "SE-W257") \
    X(SE_M_UPROAR, "SE-W253") \
    X(SE_M_HAIL, "SE-W258") \
    X(SE_M_COSMIC_POWER, "SE-W322") \
    X(SE_M_TEETER_DANCE, "SE-W298") \
    X(SE_M_STAT_DECREASE, "SE-W287B") \
    X(SE_M_HAZE, "SE-W114") \
    X(SE_M_HYPER_BEAM2, "SE-W063B") \
    X(SE_RG_DOOR, "SE-RG-W-DOOR") \
    X(SE_RG_CARD_FLIP, "SE-RG-CARD1") \
    X(SE_RG_CARD_FLIPPING, "SE-RG-CARD2") \
    X(SE_RG_CARD_OPEN, "SE-RG-CARD3") \
    X(SE_RG_BAG_CURSOR, "SE-RG-BAG1") \
    X(SE_RG_BAG_POCKET, "SE-RG-BAG2") \
    X(SE_RG_BALL_CLICK, "SE-RG-GETTING") \
    X(SE_RG_SHOP, "SE-RG-SHOP") \
    X(SE_RG_SS_ANNE_HORN, "SE-RG-KITEKI") \
    X(SE_RG_HELP_OPEN, "SE-RG-HELP-OP") \
    X(SE_RG_HELP_CLOSE, "SE-RG-HELP-CL") \
    X(SE_RG_HELP_ERROR, "SE-RG-HELP-NG") \
    X(SE_RG_DEOXYS_MOVE, "SE-RG-DEOMOV") \
    X(SE_RG_POKE_JUMP_SUCCESS, "SE-RG-EXCELLENT") \
    X(SE_RG_POKE_JUMP_FAILURE, "SE-RG-NAWAMISS") \
    X(SE_POKENAV_CALL, "SE-TOREEYE") \
    X(SE_POKENAV_HANG_UP, "SE-TOREOFF") \
    X(SE_ARENA_TIMEUP1, "SE-HANTEI1") \
    X(SE_ARENA_TIMEUP2, "SE-HANTEI2") \
    X(SE_PIKE_CURTAIN_CLOSE, "SE-CURTAIN") \
    X(SE_PIKE_CURTAIN_OPEN, "SE-CURTAIN1") \
    X(SE_SUDOWOODO_SHAKE, "SE-USSOKI")

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
