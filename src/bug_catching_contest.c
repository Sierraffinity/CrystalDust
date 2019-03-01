#include "global.h"
#include "alloc.h"
#include "battle.h"
#include "battle_setup.h"
#include "bg.h"
#include "bug_catching_contest.h"
#include "decompress.h"
#include "field_screen_effect.h"
#include "gpu_regs.h"
#include "main.h"
#include "menu.h"
#include "menu_helpers.h"
#include "overworld.h"
#include "palette.h"
#include "pokemon_icon.h"
#include "script.h"
#include "sprite.h"
#include "string_util.h"
#include "text.h"
#include "text_window.h"
#include "window.h"
#include "constants/flags.h"
#include "constants/rgb.h"

struct BugCatchingContestSwapScreen
{
    u8 cursorPos;
    u8 stockMonWindowId;
    u8 newMonWindowId;
    u8 textWindowId;
    struct Pokemon *newMon;
    MainCallback returnCallback;
    struct Sprite *cursorSprite;
    struct Sprite *monIconSprites[2];
};

EWRAM_DATA u8 gNumParkBalls = 0;
EWRAM_DATA u8 gBugCatchingContestStatus = 0;
EWRAM_DATA struct Pokemon gCaughtBugCatchingContestMon = {0};
EWRAM_DATA struct BugCatchingContestSwapScreen *sSwapScreen = NULL;

extern const u8 EventScript_RanOutOfParkBalls[];
extern const u8 EventScript_CaughtButRanOutOfParkBalls[];
extern const u8 BugCatchingContest_StartMenuPrompt[];

static void InitBugCatchingContestSwapScreen(void);
static void MainCallback_BugCatchingContestSwapScreen(void);
static void VBlank_BugCatchingContestSwapScreen(void);
static void InitSwapScreenSprites(void);
static void InitSwapScreenWindows(void);
static void SwapScreenWaitFadeIn(u8 taskId);
static void SwapScreenHandleInput(u8 taskId);
static void SwapScreenWaitFinalText(u8 taskId);
static void SwapScreenExit(u8 taskId);

static const u32 sSwapScreenBackgroundGfx[] = INCBIN_U32("graphics/bug_catching_contest/background_tiles.4bpp.lz");
static const u16 sSwapScreenBackgroundPalette[] = INCBIN_U16("graphics/bug_catching_contest/background_tiles.gbapal");
static const u32 sSwapScreenBackgroundTilemap[] = INCBIN_U32("graphics/bug_catching_contest/background_tilemap.bin.lz");

static const struct BgTemplate sSwapScreenBgTemplates[] = {
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
       .charBaseIndex = 1,
       .mapBaseIndex = 29,
       .screenSize = 0,
       .paletteMode = 0,
       .priority = 1,
       .baseTile = 0
   },
};

static const struct WindowTemplate sStockMonWindowTemplate = {
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 3,
    .width = 12,
    .height = 8,
    .paletteNum = 12,
    .baseBlock = 1,
};

static const struct WindowTemplate sNewMonWindowTemplate = {
    .bg = 0,
    .tilemapLeft = 17,
    .tilemapTop = 3,
    .width = 12,
    .height = 8,
    .paletteNum = 14,
    .baseBlock = 0x61,
};

static const struct WindowTemplate sTextWindowTemplate = {
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 15,
    .width = 20,
    .height = 4,
    .paletteNum = 12,
    .baseBlock = 0xC1,
};

static const struct WindowTemplate sYesNoWindowTemplate = {
    .bg = 0,
    .tilemapLeft = 23,
    .tilemapTop = 15,
    .width = 6,
    .height = 4,
    .paletteNum = 12,
    .baseBlock = 0x111,  
};

static const u8 sStockMonText[] = _("Stock {PKMN}\n{STR_VAR_1}\nLevel: {STR_VAR_2}\nHealth: {STR_VAR_3}");
static const u8 sNewMonText[] = _("New {PKMN}\n{STR_VAR_1}\nLevel: {STR_VAR_2}\nHealth: {STR_VAR_3}");
static const u8 sTextSwapMonsPrompt[] = _("Switch POKéMON?");
static const u8 sTextReleasedNewlyCaughtMon[] = _("Released the newly-caught\n{STR_VAR_1}.\p");
static const u8 sTextCaughtMon[] = _("Caught {STR_VAR_1}!\p");

bool8 InBugCatchingContest(void)
{
    return gBugCatchingContestStatus != BUG_CATCHING_CONTEST_STATUS_OFF;
}

bool8 CaughtBugCatchingContestMon(void)
{
    return gBugCatchingContestStatus == BUG_CATCHING_CONTEST_STATUS_CAUGHT;
}

void SetCaughtBugCatchingContestMon(struct Pokemon *caughtMon)
{
    gBugCatchingContestStatus = BUG_CATCHING_CONTEST_STATUS_CAUGHT;
    memcpy(&gCaughtBugCatchingContestMon, caughtMon, sizeof(gCaughtBugCatchingContestMon));
}

void EnterBugCatchingContest(void)
{
    gBugCatchingContestStatus = BUG_CATCHING_CONTEST_STATUS_NOT_CAUGHT;
    gNumParkBalls = 20;
    CreateMon(&gCaughtBugCatchingContestMon, 214, 15, 1, 0, 0, OT_ID_PLAYER_ID, 0);
}

void EndBugCatchingContest(void)
{
    gBugCatchingContestStatus = BUG_CATCHING_CONTEST_STATUS_OFF;
    gNumParkBalls = 0;
    memset(&gCaughtBugCatchingContestMon, 0, sizeof(gCaughtBugCatchingContestMon));
}

void BugCatchingContestQuitPrompt(void)
{
    ScriptContext1_SetupScript(BugCatchingContest_StartMenuPrompt);
}

void CB2_EndBugCatchingContestBattle(void)
{
    CpuFill16(0, (void*)(BG_PLTT), BG_PLTT_SIZE);
    ResetOamRange(0, 128);

    if (IsPlayerDefeated(gBattleOutcome))
    {
        SetMainCallback2(CB2_WhiteOut);
    }
    else if (gNumParkBalls > 0)
    {
        SetMainCallback2(CB2_ReturnToField);
    }
    else if (gBattleOutcome == B_OUTCOME_NO_PARK_BALLS)
    {
        ScriptContext2_RunNewScript(EventScript_RanOutOfParkBalls);
        WarpIntoMap();
        gFieldCallback = sub_80AF6F0;
        SetMainCallback2(CB2_LoadMap);
    }
    else if (gBattleOutcome == B_OUTCOME_CAUGHT)
    {
        // Player caught mon, but has no more Park Balls.
        ScriptContext1_SetupScript(EventScript_CaughtButRanOutOfParkBalls);
        ScriptContext1_Stop();
        SetMainCallback2(CB2_ReturnToFieldContinueScriptPlayMapMusic);
    }
}

void DoSwapBugContestMonScreen(struct Pokemon *newMon, MainCallback returnCallback)
{
    sSwapScreen = AllocZeroed(sizeof(*sSwapScreen));
    if (sSwapScreen)
    {
        sSwapScreen->newMon = newMon;
        sSwapScreen->returnCallback = returnCallback;
        SetMainCallback2(InitBugCatchingContestSwapScreen);
    }
    else
    {
        SetMainCallback2(returnCallback);
    }
}

static void InitBugCatchingContestSwapScreen(void)
{
    SetVBlankCallback(NULL);
    ResetAllBgsCoordinates();
    ResetVramOamAndBgCntRegs();
    ResetBgsAndClearDma3BusyFlags(0);

    InitBgsFromTemplates(0, sSwapScreenBgTemplates, ARRAY_COUNT(sSwapScreenBgTemplates));
    SetBgTilemapBuffer(1, AllocZeroed(BG_SCREEN_SIZE));
    DecompressAndLoadBgGfxUsingHeap(1, sSwapScreenBackgroundGfx, 0x80, 0, 0);
    CopyToBgTilemapBuffer(1, sSwapScreenBackgroundTilemap, 0, 0);
    ResetPaletteFade();
    LoadPalette(sSwapScreenBackgroundPalette, 0, sizeof(sSwapScreenBackgroundPalette));
    DeactivateAllTextPrinters();
    InitSwapScreenWindows();

    ResetSpriteData();
    FreeAllSpritePalettes();

    LoadMonIconPalettes();
    InitSwapScreenSprites();
    CopyBgTilemapBufferToVram(1);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 | DISPCNT_OBJ_1D_MAP | DISPCNT_OBJ_ON);
    ShowBg(0);
    ShowBg(1);
    BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, RGB_BLACK);
    SetVBlankCallback(VBlank_BugCatchingContestSwapScreen);
    SetMainCallback2(MainCallback_BugCatchingContestSwapScreen);
    CreateTask(SwapScreenWaitFadeIn, 0);
}

static void MainCallback_BugCatchingContestSwapScreen(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    RunTextPrinters();
    UpdatePaletteFade();
}

static void VBlank_BugCatchingContestSwapScreen(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void InitSwapScreenSprites(void)
{
    u8 spriteId;
    u32 personality;
    u16 species;

    species = GetMonData(&gCaughtBugCatchingContestMon, MON_DATA_SPECIES);
    personality = GetMonData(&gCaughtBugCatchingContestMon, MON_DATA_PERSONALITY);
    spriteId = CreateMonIcon(species, SpriteCallbackDummy, 88, 40, 0, personality, 0);
    sSwapScreen->monIconSprites[0] = &gSprites[spriteId];
    sSwapScreen->monIconSprites[0]->oam.priority = 0;

    species = GetMonData(sSwapScreen->newMon, MON_DATA_SPECIES);
    personality = GetMonData(sSwapScreen->newMon, MON_DATA_PERSONALITY);
    spriteId = CreateMonIcon(species, SpriteCallbackDummy, 216, 40, 0, personality, 0);
    sSwapScreen->monIconSprites[1] = &gSprites[spriteId];
    sSwapScreen->monIconSprites[1]->oam.priority = 0;
}

static void InitSwapScreenWindows(void)
{
    sSwapScreen->stockMonWindowId = AddWindow(&sStockMonWindowTemplate);
    sSwapScreen->newMonWindowId = AddWindow(&sNewMonWindowTemplate);
    LoadMessageBoxGfx(sSwapScreen->stockMonWindowId, 0x200, 0xC0);
    LoadUserWindowBorderGfx(sSwapScreen->stockMonWindowId, 0x214, 0xC0);
    LoadMessageBoxGfx(sSwapScreen->newMonWindowId, 0x200, 0xE0);
    LoadUserWindowBorderGfx(sSwapScreen->newMonWindowId, 0x21D, 0xE0);
    PutWindowTilemap(sSwapScreen->stockMonWindowId);
    PutWindowTilemap(sSwapScreen->newMonWindowId);
    NewMenuHelpers_DrawStdWindowFrame(sSwapScreen->stockMonWindowId, FALSE);
    NewMenuHelpers_DrawStdWindowFrame(sSwapScreen->newMonWindowId, FALSE);
    CopyWindowToVram(sSwapScreen->stockMonWindowId, 3);
    CopyWindowToVram(sSwapScreen->newMonWindowId, 3);

    GetSpeciesName(gStringVar1, GetMonData(&gCaughtBugCatchingContestMon, MON_DATA_SPECIES));
    ConvertIntToDecimalStringN(gStringVar2, GetMonData(&gCaughtBugCatchingContestMon, MON_DATA_LEVEL), STR_CONV_MODE_LEFT_ALIGN, 3);
    ConvertIntToDecimalStringN(gStringVar3, GetMonData(&gCaughtBugCatchingContestMon, MON_DATA_MAX_HP), STR_CONV_MODE_LEFT_ALIGN, 3);
    StringExpandPlaceholders(gStringVar4, sStockMonText);
    AddTextPrinterParameterized(sSwapScreen->stockMonWindowId, 1, gStringVar4, 0, 1, 0, NULL);

    GetSpeciesName(gStringVar1, GetMonData(sSwapScreen->newMon, MON_DATA_SPECIES));
    ConvertIntToDecimalStringN(gStringVar2, GetMonData(sSwapScreen->newMon, MON_DATA_LEVEL), STR_CONV_MODE_LEFT_ALIGN, 3);
    ConvertIntToDecimalStringN(gStringVar3, GetMonData(sSwapScreen->newMon, MON_DATA_MAX_HP), STR_CONV_MODE_LEFT_ALIGN, 3);
    StringExpandPlaceholders(gStringVar4, sNewMonText);
    AddTextPrinterParameterized(sSwapScreen->newMonWindowId, 1, gStringVar4, 0, 1, 0, NULL);

    sSwapScreen->textWindowId = AddWindow(&sTextWindowTemplate);
    LoadMessageBoxGfx(sSwapScreen->textWindowId, 0x200, 0xC0);
    LoadUserWindowBorderGfx(sSwapScreen->textWindowId, 0x214, 0xC0);
    PutWindowTilemap(sSwapScreen->textWindowId);
    NewMenuHelpers_DrawStdWindowFrame(sSwapScreen->textWindowId, FALSE);
    CopyWindowToVram(sSwapScreen->textWindowId, 3);
    AddTextPrinterParameterized(sSwapScreen->textWindowId, 1, sTextSwapMonsPrompt, 0, 1, 0, NULL);

    CreateYesNoMenu(&sYesNoWindowTemplate, 0x214, 14, 0);
}

static void SwapScreenWaitFadeIn(u8 taskId)
{
    if (!gPaletteFade.active)
        gTasks[taskId].func = SwapScreenHandleInput;
}

static void SwapScreenHandleInput(u8 taskId)
{
    int selection = Menu_ProcessInputNoWrapClearOnChoose();
    if (selection == 0)
    {
        FillWindowPixelBuffer(sSwapScreen->textWindowId, 0x11);
        GetSpeciesName(gStringVar1, GetMonData(sSwapScreen->newMon, MON_DATA_SPECIES));
        StringExpandPlaceholders(gStringVar4, sTextCaughtMon);
        AddTextPrinterParameterized(sSwapScreen->textWindowId, 1, gStringVar4, 0, 1, GetPlayerTextSpeedDelay(), NULL);
        gCaughtBugCatchingContestMon = *sSwapScreen->newMon;
        gTasks[taskId].func = SwapScreenWaitFinalText;
    }
    else if (selection == 1 || selection == MENU_B_PRESSED)
    {
        FillWindowPixelBuffer(sSwapScreen->textWindowId, 0x11);
        GetSpeciesName(gStringVar1, GetMonData(sSwapScreen->newMon, MON_DATA_SPECIES));
        StringExpandPlaceholders(gStringVar4, sTextReleasedNewlyCaughtMon);
        AddTextPrinterParameterized(sSwapScreen->textWindowId, 1, gStringVar4, 0, 1, GetPlayerTextSpeedDelay(), NULL);
        gTasks[taskId].func = SwapScreenWaitFinalText;
    }
}

static void SwapScreenWaitFinalText(u8 taskId)
{
    if (!IsTextPrinterActive(sSwapScreen->textWindowId))
    {
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
        gTasks[taskId].func = SwapScreenExit;
    }
}

static void SwapScreenExit(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        DestroyTask(taskId);
        SetMainCallback2(sSwapScreen->returnCallback);
        FreeAllWindowBuffers();
        FREE_AND_SET_NULL(sSwapScreen);
    }
}
