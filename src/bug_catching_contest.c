#include "global.h"
#include "alloc.h"
#include "battle.h"
#include "battle_setup.h"
#include "bg.h"
#include "bug_catching_contest.h"
#include "decompress.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "field_screen_effect.h"
#include "frontier_util.h"
#include "gpu_regs.h"
#include "item.h"
#include "load_save.h"
#include "main.h"
#include "menu.h"
#include "menu_helpers.h"
#include "overworld.h"
#include "palette.h"
#include "pokemon_icon.h"
#include "day_night.h"
#include "random.h"
#include "rtc.h"
#include "script.h"
#include "sprite.h"
#include "string_util.h"
#include "text.h"
#include "text_window.h"
#include "wild_encounter.h"
#include "window.h"
#include "constants/event_objects.h"
#include "constants/event_object_movement_constants.h"
#include "constants/flags.h"
#include "constants/items.h"
#include "constants/maps.h"
#include "constants/rgb.h"
#include "constants/species.h"
#include "constants/trainers.h"

extern const u8 NationalParkContest_Nick[];
extern const u8 NationalParkContest_William[];
extern const u8 NationalParkContest_Samuel[];
extern const u8 NationalParkContest_Barry[];
extern const u8 NationalParkContest_Ed[];
extern const u8 NationalParkContest_Benny[];
extern const u8 NationalParkContest_Josh[];
extern const u8 NationalParkContest_Don[];
extern const u8 NationalParkContest_Kipp[];
extern const u8 NationalParkContest_Cindy[];
extern const u8 NationalParkGateEast_NickPlayerWon[];
extern const u8 NationalParkGateEast_NickPlayerLost[];
extern const u8 NationalParkGateEast_WilliamPlayerWon[];
extern const u8 NationalParkGateEast_WilliamPlayerLost[];
extern const u8 NationalParkGateEast_SamuelPlayerWon[];
extern const u8 NationalParkGateEast_SamuelPlayerLost[];
extern const u8 NationalParkGateEast_BarryPlayerWon[];
extern const u8 NationalParkGateEast_BarryPlayerLost[];
extern const u8 NationalParkGateEast_EdPlayerWon[];
extern const u8 NationalParkGateEast_EdPlayerLost[];
extern const u8 NationalParkGateEast_BennyPlayerWon[];
extern const u8 NationalParkGateEast_BennyPlayerLost[];
extern const u8 NationalParkGateEast_JoshPlayerWon[];
extern const u8 NationalParkGateEast_JoshPlayerLost[];
extern const u8 NationalParkGateEast_DonPlayerWon[];
extern const u8 NationalParkGateEast_DonPlayerLost[];
extern const u8 NationalParkGateEast_KippPlayerWon[];
extern const u8 NationalParkGateEast_KippPlayerLost[];
extern const u8 NationalParkGateEast_CindyPlayerWon[];
extern const u8 NationalParkGateEast_CindyPlayerLost[];
extern const u8 EventScript_BugContest_WhiteOut[];
extern const u8 EventScript_RanOutOfParkBalls[];
extern const u8 EventScript_BugCatchingContestTimeExpired[];
extern const u8 EventScript_CaughtButRanOutOfParkBalls[];
extern const u8 BugCatchingContest_StartMenuPrompt[];
extern const u8 gTrainerClassNames[][13];

#define NUM_BUG_CONTEST_NPCS 5

// The maximum score for a mon is only 400, so shiny mmons trump normal mons.
#define SHINY_SCORE_INCREASE 500
#define BUG_CONTEST_DURATION_SECONDS 1200

enum
{
    BUG_CONTEST_NPC_TRAIT_NORMAL,
    BUG_CONTEST_NPC_TRAIT_STRONG,
    BUG_CONTEST_NPC_TRAIT_SHINY,
    BUG_CONTEST_NPC_TRAIT_RARE,
};

struct BugCatchingContestNPCTemplate
{
    u8 graphicsId;
    u8 trainerClass;
    const u8 *name;
    const u8 *script;
    const u8 *awardsScriptPlayerWon;
    const u8 *awardsScriptPlayerLost;
};

struct BugCatchingContestNPC
{
    u8 templateId;
    u8 trait;
    u8 caughtLevel;
    u8 caughtShiny;
    u16 caughtSpecies;
    u16 score;
};

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
EWRAM_DATA u16 gPlayerBugCatchingContestScore = 0;
EWRAM_DATA struct Pokemon gCaughtBugCatchingContestMon = {0};
EWRAM_DATA struct BugCatchingContestNPC gBugCatchingContestNPCs[NUM_BUG_CONTEST_NPCS] = {0};
EWRAM_DATA struct BugCatchingContestSwapScreen *sSwapScreen = NULL;
EWRAM_DATA u8 gBugCatchingContestStandings[NUM_BUG_CONTEST_NPCS + 1] = {0};
EWRAM_DATA u32 gBugCatchingContestStartSeconds = 0;

static void GenerateBugCatchingContestNPCMons();
static void InitBugContestNPCs(void);
static void GenerateBugCatchingContestNPCMon(struct BugCatchingContestNPC *npc);
static int CalculateBugCatchingContestMonScore(struct Pokemon *mon, bool8 isNPC);
static int GetMaxBugCatchingContestLevel(void);
static const struct WildPokemon *GetBugCatchingContestWildMons(void);
static int CalculateLevelScore(int level, int maxLevel);
static int CalculateIVScore(int hpIV, int attackIV, int defenseIV, int speedIV, int spAttackIV, int spDefenseIV);
static int CalculateHPScore(int curHP, int maxHP);
static int CalculateRarityScore(u16 species);
static void SetAwardsCeremonyBugContestEventObjectScripts(void);
static void MainCallback_BugCatchingContestSwapScreen(void);
static void InitBugCatchingContestSwapScreen(void);
static void VBlank_BugCatchingContestSwapScreen(void);
static void InitSwapScreenSprites(void);
static void InitSwapScreenWindows(void);
static void SwapScreenWaitFadeIn(u8 taskId);
static void SwapScreenDisplayAlreadyCaughtMessage(u8 taskId);
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
static const u8 sTextReleasedNewlyCaughtMon[] = _("Released the newly-caught\n{STR_VAR_1}.\p");
static const u8 sTextReleasedPreviousCaughtMon[] = _("Released the previously-\ncaught {STR_VAR_1}.\p");
static const u8 sTextAlreadyCaught[] = _("You already caught a\n{STR_VAR_1}.\pSwitch POKéMON?");

static const u16 sCommonBugContestMons[] = {
    SPECIES_CATERPIE,
    SPECIES_METAPOD,
    SPECIES_WEEDLE,
    SPECIES_KAKUNA,
    SPECIES_WURMPLE,
    SPECIES_SILCOON,
    SPECIES_CASCOON,
};

static const u16 sRareBugContestMons[] = {
    SPECIES_SCYTHER,
    SPECIES_PINSIR,
};

static const u8 sName_Nick[] = _("NICK");
static const u8 sName_William[] = _("WILLIAM");
static const u8 sName_Samuel[] = _("SAMUEL");
static const u8 sName_Barry[] = _("BARRY");
static const u8 sName_Ed[] = _("ED");
static const u8 sName_Benny[] = _("BENNY");
static const u8 sName_Josh[] = _("JOSH");
static const u8 sName_Don[] = _("DON");
static const u8 sName_Kipp[] = _("KIPP");
static const u8 sName_Cindy[] = _("CINDY");

static const struct BugCatchingContestNPCTemplate sBugContestNPCTemplates[] = {
    {
        .graphicsId = EVENT_OBJ_GFX_BOY_1,
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .name = sName_Nick,
        .script = NationalParkContest_Nick,
        .awardsScriptPlayerWon = NationalParkGateEast_NickPlayerWon,
        .awardsScriptPlayerLost = NationalParkGateEast_NickPlayerLost,
    },
    {
        .graphicsId = EVENT_OBJ_GFX_POKEFAN_M,
        .trainerClass = TRAINER_CLASS_POKEFAN,
        .name = sName_William,
        .script = NationalParkContest_William,
        .awardsScriptPlayerWon = NationalParkGateEast_WilliamPlayerWon,
        .awardsScriptPlayerLost = NationalParkGateEast_WilliamPlayerLost,
    },
    {
        .graphicsId = EVENT_OBJ_GFX_YOUNGSTER,
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .name = sName_Samuel,
        .script = NationalParkContest_Samuel,
        .awardsScriptPlayerWon = NationalParkGateEast_SamuelPlayerWon,
        .awardsScriptPlayerLost = NationalParkGateEast_SamuelPlayerLost,
    },
    {
        .graphicsId = EVENT_OBJ_GFX_CAMPER,
        .trainerClass = TRAINER_CLASS_CAMPER,
        .name = sName_Barry,
        .script = NationalParkContest_Barry,
        .awardsScriptPlayerWon = NationalParkGateEast_BarryPlayerWon,
        .awardsScriptPlayerLost = NationalParkGateEast_BarryPlayerLost,
    },
    {
        .graphicsId = EVENT_OBJ_GFX_BUG_CATCHER,
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
        .name = sName_Ed,
        .script = NationalParkContest_Ed,
        .awardsScriptPlayerWon = NationalParkGateEast_EdPlayerWon,
        .awardsScriptPlayerLost = NationalParkGateEast_EdPlayerLost,
    },
    {
        .graphicsId = EVENT_OBJ_GFX_BUG_CATCHER,
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
        .name = sName_Benny,
        .script = NationalParkContest_Benny,
        .awardsScriptPlayerWon = NationalParkGateEast_BennyPlayerWon,
        .awardsScriptPlayerLost = NationalParkGateEast_BennyPlayerLost,
    },
    {
        .graphicsId = EVENT_OBJ_GFX_BUG_CATCHER,
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
        .name = sName_Josh,
        .script = NationalParkContest_Josh,
        .awardsScriptPlayerWon = NationalParkGateEast_JoshPlayerWon,
        .awardsScriptPlayerLost = NationalParkGateEast_JoshPlayerLost,
    },
    {
        .graphicsId = EVENT_OBJ_GFX_BUG_CATCHER,
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
        .name = sName_Don,
        .script = NationalParkContest_Don,
        .awardsScriptPlayerWon = NationalParkGateEast_DonPlayerWon,
        .awardsScriptPlayerLost = NationalParkGateEast_DonPlayerLost,
    },
    {
        .graphicsId = EVENT_OBJ_GFX_SCHOOL_KID_M,
        .trainerClass = TRAINER_CLASS_SCHOOL_KID,
        .name = sName_Kipp,
        .script = NationalParkContest_Kipp,
        .awardsScriptPlayerWon = NationalParkGateEast_KippPlayerWon,
        .awardsScriptPlayerLost = NationalParkGateEast_KippPlayerLost,
    },
    {
        .graphicsId = EVENT_OBJ_GFX_PICNICKER,
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .name = sName_Cindy,
        .script = NationalParkContest_Cindy,
        .awardsScriptPlayerWon = NationalParkGateEast_CindyPlayerWon,
        .awardsScriptPlayerLost = NationalParkGateEast_CindyPlayerLost,
    },
};

static const u8 sBugContestNPCCoords[][2] = {
    {1, 2},
    {3, 2},
    {5, 2},
    {7, 2},
    {9, 2},
    {11, 2},
    {12, 2},
    {13, 2},
    {15, 2},
    {17, 2},
};

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
    InitBugContestNPCs();
    RtcCalcLocalTime();
    gBugCatchingContestStartSeconds = GetTotalSeconds(&gLocalTime);
}

bool8 CheckBugCatchingContestTimerExpired(void)
{
    u32 curSeconds;

    if (gBugCatchingContestStatus != BUG_CATCHING_CONTEST_STATUS_OFF
     && gMain.vblankCounter1 % 60 == 0)
    {
        // Check if 20 minutes has passsed since the contest started.
        RtcCalcLocalTime();
        curSeconds = GetTotalSeconds(&gLocalTime);
        if (curSeconds - gBugCatchingContestStartSeconds > BUG_CONTEST_DURATION_SECONDS)
        {
            ScriptContext1_SetupScript(EventScript_BugCatchingContestTimeExpired);
            return TRUE;
        }
    }

    return FALSE;
}

bool8 CopyBugCatchingContestRemainingMinutesToVar1(void)
{
    u32 curSeconds;
    int remainingSeconds;
    int remainingMinutes;

    RtcCalcLocalTime();
    curSeconds = GetTotalSeconds(&gLocalTime);
    remainingSeconds = BUG_CONTEST_DURATION_SECONDS - (curSeconds - gBugCatchingContestStartSeconds);
    if (remainingSeconds % 60 >= 30)
        remainingSeconds += 30;

    remainingMinutes = remainingSeconds / 60;
    if (remainingMinutes < 0)
        remainingMinutes = 0;

    ConvertIntToDecimalStringN(gStringVar1, remainingMinutes, 0, 3);
    return remainingMinutes > 1;
}

void GiveCaughtBugCatchingContestMon(void)
{
    if (gBugCatchingContestStatus == BUG_CATCHING_CONTEST_STATUS_CAUGHT)
        gSpecialVar_Result = GiveMonToPlayer(&gCaughtBugCatchingContestMon);
    else
        gSpecialVar_Result = 3;
}

void EndBugCatchingContest(void)
{
    int i;
    u8 eventObjectId;

    gBugCatchingContestStatus = BUG_CATCHING_CONTEST_STATUS_OFF;
    gNumParkBalls = 0;
    memset(&gCaughtBugCatchingContestMon, 0, sizeof(gCaughtBugCatchingContestMon));
    for (i = 0; i < ARRAY_COUNT(gBugCatchingContestNPCs); i++)
        memset(&gBugCatchingContestNPCs[i], 0, sizeof(gBugCatchingContestNPCs[i]));

    for (i = 0; i < NUM_BUG_CONTEST_NPCS; i++)
    {
        if (!TryGetEventObjectIdByLocalIdAndMap(i + 1, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup, &eventObjectId))
            SetTrainerMovementType(&gEventObjects[eventObjectId], MOVEMENT_TYPE_LOOK_AROUND);
    }
}

void TryEndBugCatchingContest(void)
{
    if (gBugCatchingContestStatus != BUG_CATCHING_CONTEST_STATUS_OFF)
    {
        EndBugCatchingContest();
        // Restore the rest of the player's party.
        gSpecialVar_0x8004 = 6;
        CallFrontierUtilFunc();
        LoadPlayerParty();
        VarSet(VAR_BUG_CATCHING_CONTEST_STATE, 0);
    }
}

static int GetContestantScore(u32 id)
{
    if (id < NUM_BUG_CONTEST_NPCS)
        return gBugCatchingContestNPCs[id].score;
    else
        return gPlayerBugCatchingContestScore;
}

void DetermineBugCatchingContestStandings(void)
{
    int i, j;
    int playerId;

    if (gBugCatchingContestStatus == BUG_CATCHING_CONTEST_STATUS_CAUGHT)
        gPlayerBugCatchingContestScore = CalculateBugCatchingContestMonScore(&gCaughtBugCatchingContestMon, FALSE);
    else
        gPlayerBugCatchingContestScore = 0;

    GenerateBugCatchingContestNPCMons();
    for (i = 0; i < ARRAY_COUNT(gBugCatchingContestStandings); i++)
        gBugCatchingContestStandings[i] = i;

    // Sort the standings based on the contestants' scores from largest to smallest.
    playerId = NUM_BUG_CONTEST_NPCS;
    for (i = 0; i < ARRAY_COUNT(gBugCatchingContestStandings) - 1; i++)
    {
        for (j = i + 1; j < ARRAY_COUNT(gBugCatchingContestStandings); j++)
        {
            int scoreA = GetContestantScore(gBugCatchingContestStandings[i]);
            int scoreB = GetContestantScore(gBugCatchingContestStandings[j]);
            // Favor the player when score is tied with any NPC.
            if (scoreA < scoreB || (scoreA == scoreB && gBugCatchingContestStandings[j] == playerId))
            {
                int temp = gBugCatchingContestStandings[i];
                gBugCatchingContestStandings[i] = gBugCatchingContestStandings[j];
                gBugCatchingContestStandings[j] = temp;
            }
        }
    }

    SetAwardsCeremonyBugContestEventObjectScripts();
}

void BugCatchingContestQuitPrompt(void)
{
    ScriptContext1_SetupScript(BugCatchingContest_StartMenuPrompt);
}

u16 DetermineBugCatchingContestPrize(void)
{
    int i;
    u16 item;
    int playerPlace = GetPlayerBugContestPlace();

    if (playerPlace == 1)
        item = ITEM_SUN_STONE;
    else if (playerPlace == 2)
        item = ITEM_EVERSTONE;
    else if (playerPlace == 3)
        item = ITEM_SITRUS_BERRY;
    else
        item = ITEM_ORAN_BERRY;

    CopyItemName(item, gStringVar1);
    return item;
}

void CB2_EndBugCatchingContestBattle(void)
{
    CpuFill16(0, (void*)(BG_PLTT), BG_PLTT_SIZE);
    ResetOamRange(0, 128);

    if (IsPlayerDefeated(gBattleOutcome))
    {
        ScriptContext2_RunNewScript(EventScript_BugContest_WhiteOut);
        WarpIntoMap();
        gFieldCallback = sub_80AF6F0;
        SetMainCallback2(CB2_LoadMap);
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

static void InitBugContestNPCs(void)
{
    int i;
    int numSelected;
    int strongIndex, shinyIndex, rareIndex;
    u8 npcTraits[NUM_BUG_CONTEST_NPCS];
    u8 selectedNPCs[NUM_BUG_CONTEST_NPCS];
    u8 availableNPCs[ARRAY_COUNT(sBugContestNPCTemplates)] = {0};

    // First, assign traits to NPCs.
    for (i = 0; i < NUM_BUG_CONTEST_NPCS; i++)
        npcTraits[i] = BUG_CONTEST_NPC_TRAIT_NORMAL;

    // There is always one strong NPC, one that has an increased chance at catching rare
    // mons, and one that has increased chance at catching a shiny pokemon.
    strongIndex = Random() % NUM_BUG_CONTEST_NPCS;
    npcTraits[strongIndex] = BUG_CONTEST_NPC_TRAIT_STRONG;
    while (1)
    {
        shinyIndex = Random() % NUM_BUG_CONTEST_NPCS;
        if (shinyIndex != strongIndex)
        {
            npcTraits[shinyIndex] = BUG_CONTEST_NPC_TRAIT_SHINY;
            break;
        }
    };

    while (1)
    {
        rareIndex = Random() % NUM_BUG_CONTEST_NPCS;
        if (rareIndex != strongIndex && rareIndex != shinyIndex)
        {
            npcTraits[rareIndex] = BUG_CONTEST_NPC_TRAIT_RARE;
            break;
        }
    };

    // Select NPC templates.
    numSelected = 0;
    while (numSelected < NUM_BUG_CONTEST_NPCS)
    {
        int index = Random() % ARRAY_COUNT(sBugContestNPCTemplates);
        if (availableNPCs[index] == 0)
        {
            availableNPCs[index] = 1;
            selectedNPCs[numSelected] = index;
            numSelected++;
        }
    }

    // Initialize the NPC data.
    for (i = 0; i < NUM_BUG_CONTEST_NPCS; i++)
    {
        gBugCatchingContestNPCs[i].templateId = selectedNPCs[i];
        if (i == strongIndex)
            gBugCatchingContestNPCs[i].trait = BUG_CONTEST_NPC_TRAIT_STRONG;
        else if (i == shinyIndex)
            gBugCatchingContestNPCs[i].trait = BUG_CONTEST_NPC_TRAIT_SHINY;
        else if (i == rareIndex)
            gBugCatchingContestNPCs[i].trait = BUG_CONTEST_NPC_TRAIT_RARE;
        else
            gBugCatchingContestNPCs[i].trait = BUG_CONTEST_NPC_TRAIT_NORMAL;
    }
}

// This copy of the function is useful for calculating the average scores in a contest.
// Leaving it around for now.
// static void GenerateBugCatchingContestNPCMons(void)
// {
//     int i, j;
//     int num = 0;
//     int total = 0;
//     int numMax = 0;
//     int totalMax = 0;
//     int totalMin = 0;
//     int max = 0;
//     int min = 999999;
//     for (i = 0; i < 1000; i++)
//     {
//         int index = i % NUM_BUG_CONTEST_NPCS;
//         GenerateBugCatchingContestNPCMon(&gBugCatchingContestNPCs[index]);
//         num++;
//         total += gBugCatchingContestNPCs[index].score;
//         if (gBugCatchingContestNPCs[index].score > max)
//             max = gBugCatchingContestNPCs[index].score;
//         if (gBugCatchingContestNPCs[index].score < min)
//             min = gBugCatchingContestNPCs[index].score;

//         if (i % 5 == 0 && i > 0)
//         {
//             int localMax = 0;
//             int localMin = 999999;
//             for (j = 0; j < 5; j++)
//             {
//                 if (gBugCatchingContestNPCs[j].score > localMax)
//                     localMax = gBugCatchingContestNPCs[j].score;
//                 if (gBugCatchingContestNPCs[j].score < localMin)
//                     localMin = gBugCatchingContestNPCs[j].score;

//             }

//             numMax++;
//             totalMax += localMax;
//             totalMin += localMin;
//         }

//         if (i % 10 == 0 && i > 0)
//         {
//             AGBPrintf("i(%d) avg(%d) min/max(%d, %d) avg min/max(%d, %d)\n", i, total/num, min, max, totalMin/numMax, totalMax/numMax);
//         }
//     }
// }

static void GenerateBugCatchingContestNPCMons(void)
{
    int i;
    for (i = 0; i < NUM_BUG_CONTEST_NPCS; i++)
        GenerateBugCatchingContestNPCMon(&gBugCatchingContestNPCs[i]);
}

static void GenerateBugCatchingContestNPCMon(struct BugCatchingContestNPC *npc)
{
    int i, j;
    int maxHP, hp;
    int min, max;
    int trait;
    int numRareMons;
    int shinyOdds;
    struct Pokemon mon;
    u8 rareMonIndexes[12] = {0};
    const struct WildPokemon *wildMon;
    const struct WildPokemon *wildMons = GetBugCatchingContestWildMons();

    // Choose wild mon from the encounter tables.
    switch (npc->trait)
    {
    case BUG_CONTEST_NPC_TRAIT_RARE:
        // Mark the rare mons
        numRareMons = 0;
        for (i = 0; i < 12; i++)
        {
            for (j = 0; j < ARRAY_COUNT(sRareBugContestMons); j++)
            {
                if (wildMons[i].species == sRareBugContestMons[j])
                {
                    rareMonIndexes[numRareMons] = i;
                    numRareMons++;
                    break;
                }
            }
        }

        // 75% chance of guaranteeing a rare mon.
        if (Random() % 4 != 0)
            wildMon = &wildMons[rareMonIndexes[Random() % numRareMons]];
        else
            wildMon = &wildMons[ChooseWildMonIndex_Land()];
        break;
    default:
        wildMon = &wildMons[ChooseWildMonIndex_Land()];
        break;
    }

    npc->caughtSpecies = wildMon->species;
    npc->caughtLevel = ChooseWildMonLevelWithAbility(wildMon, FALSE);
    if (npc->trait == BUG_CONTEST_NPC_TRAIT_SHINY)
        shinyOdds = 4; // 4/8192 odds
    else
        shinyOdds = 1; // 1/8192 odds

    npc->caughtShiny = (Random() % 8192) < shinyOdds;

    // Generate the mon to  calculate the score.
    CreateMon(&mon, npc->caughtSpecies, npc->caughtLevel, 0, 1, 0, 0, 0);

    // Generate IVs
    if (npc->trait == BUG_CONTEST_NPC_TRAIT_STRONG)
    {
        // Strong NPCs get IVs >= 16
        u16 value = Random();
        u32 iv = (value & 0x000F) + 16;
        SetMonData(&mon, MON_DATA_HP_IV, &iv);
        iv = ((value & 0x00F0) >> 4) + 16;
        SetMonData(&mon, MON_DATA_ATK_IV, &iv);
        iv = ((value & 0x0F00) >> 8) + 16;
        SetMonData(&mon, MON_DATA_DEF_IV, &iv);
        value = Random();
        iv = (value & 0x000F) + 16;
        SetMonData(&mon, MON_DATA_SPEED_IV, &iv);
        iv = ((value & 0x00F0) >> 4) + 16;
        SetMonData(&mon, MON_DATA_SPATK_IV, &iv);
        iv = ((value & 0x0F00) >> 8) + 16;
        SetMonData(&mon, MON_DATA_SPDEF_IV, &iv);
    }
    else
    {
        // Normal NPCs get uniformly random IVs.
        u16 value = Random();
        u32 iv = value & 0x1F;
        SetMonData(&mon, MON_DATA_HP_IV, &iv);
        iv = (value & 0x3E0) >> 5;
        SetMonData(&mon, MON_DATA_ATK_IV, &iv);
        iv = (value & 0x7C00) >> 10;
        SetMonData(&mon, MON_DATA_DEF_IV, &iv);
        value = Random();
        iv = value & 0x1F;
        SetMonData(&mon, MON_DATA_SPEED_IV, &iv);
        iv = (value & 0x3E0) >> 5;
        SetMonData(&mon, MON_DATA_SPATK_IV, &iv);
        iv = (value & 0x7C00) >> 10;
        SetMonData(&mon, MON_DATA_SPDEF_IV, &iv);
    }

    CalculateMonStats(&mon);

    // Randomly select the mon's current HP.
    maxHP = GetMonData(&mon, MON_DATA_MAX_HP);
    hp = (Random() % maxHP) + 1;
    SetMonData(&mon, MON_DATA_HP, &hp);

    npc->score = CalculateBugCatchingContestMonScore(&mon, TRUE);
    if (npc->caughtShiny)
        npc->score += SHINY_SCORE_INCREASE;
}

static int CalculateBugCatchingContestMonScore(struct Pokemon *mon, bool8 isNPC)
{
    int maxLevel;
    int levelScore, ivScore, hpScore, rarityScore, shinyScore;

    maxLevel = GetMaxBugCatchingContestLevel();
    levelScore = CalculateLevelScore(GetMonData(mon, MON_DATA_LEVEL), maxLevel);
    ivScore = CalculateIVScore(
        GetMonData(mon, MON_DATA_HP_IV),
        GetMonData(mon, MON_DATA_ATK_IV),
        GetMonData(mon, MON_DATA_DEF_IV),
        GetMonData(mon, MON_DATA_SPEED_IV),
        GetMonData(mon, MON_DATA_SPATK_IV),
        GetMonData(mon, MON_DATA_SPDEF_IV));
    hpScore = CalculateHPScore(GetMonData(mon, MON_DATA_HP), GetMonData(mon, MON_DATA_MAX_HP));
    rarityScore = CalculateRarityScore(GetMonData(mon, MON_DATA_SPECIES));

    // A shiny mon trumps any non-shiny mon.
    // Can't rely on IsMonShiny() for NPC mons because it will use the
    // player's trainer Id to do the shiny check.
    if (!isNPC && IsMonShiny(mon))
        shinyScore = SHINY_SCORE_INCREASE;
    else
        shinyScore = 0;

    return levelScore + ivScore + hpScore + rarityScore + shinyScore;
}

static int GetMaxBugCatchingContestLevel(void)
{
    int i;
    int maxLevel = -1;
    const struct WildPokemon *wildMons = GetBugCatchingContestWildMons();
    if (!wildMons)
        return -1;

    for (i = 0; i < 12; i++)
    {
        if (wildMons[i].maxLevel > maxLevel)
            maxLevel = wildMons[i].maxLevel;
    }

    return maxLevel;
}

static const struct WildPokemon *GetBugCatchingContestWildMons(void)
{
    int i;
    u8 timeOfDay = GetCurrentTimeOfDay();

    for (i = 0; ; i++)
    {
        const struct WildPokemonHeader *wildHeader = &gWildMonHeaders[i];
        if (wildHeader->mapGroup == 0xFF)
            break;

        if (wildHeader->mapGroup == MAP_GROUP(BUG_CATCHING_CONTEST)
         && wildHeader->mapNum == MAP_NUM(BUG_CATCHING_CONTEST))
            return wildHeader->landMonsInfo->wildPokemon[timeOfDay];
    }

    return NULL;
}

static int CalculateLevelScore(int level, int maxLevel)
{
    if (maxLevel <= 0)
        return 100;

    // The level relative to the maximum possible level, as a percentage.
    // e.g. If level == 17, and maxLevel == 20, this return 85.
    return (level * 100) / maxLevel;
}

static int CalculateIVScore(int hpIV, int attackIV, int defenseIV, int speedIV, int spAttackIV, int spDefenseIV)
{
    // The sum of the IVs relative to the maximum possible sum, as a percentage.
    int maxPossibleIVs = 6 * 31;
    int ivSum = hpIV + attackIV + defenseIV + speedIV + spAttackIV + spDefenseIV;
    return (ivSum * 100) / maxPossibleIVs;
}

static int CalculateHPScore(int curHP, int maxHP)
{
    // The current HP relative to maximum HP, as a percentage.
    return (curHP * 100) / maxHP;
}

static int CalculateRarityScore(u16 species)
{
    int i;
    for (i = 0; i < ARRAY_COUNT(sCommonBugContestMons); i++)
    {
        if (species == sCommonBugContestMons[i])
            return 60;
    }

    for (i = 0; i < ARRAY_COUNT(sRareBugContestMons); i++)
    {
        if (species == sRareBugContestMons[i])
            return 100;
    }

    return 80;
}

void PlaceBugCatchingContestEventObjects(void)
{
    int i;
    u16 coordIndex;
    const struct BugCatchingContestNPCTemplate *npcTemplate;
    struct EventObjectTemplate *events = gSaveBlock1Ptr->eventObjectTemplates;
    u8 takenCoords[ARRAY_COUNT(sBugContestNPCCoords)] = {0};

    for (i = 0; i < NUM_BUG_CONTEST_NPCS; i++)
    {
        do {
            coordIndex = Random() % ARRAY_COUNT(sBugContestNPCCoords);
        } while (takenCoords[coordIndex] != 0);

        takenCoords[coordIndex] = 1;
        npcTemplate = &sBugContestNPCTemplates[gBugCatchingContestNPCs[i].templateId];
        events[i].x = sBugContestNPCCoords[coordIndex][0];
        events[i].y = sBugContestNPCCoords[coordIndex][1];
        events[i].graphicsId = npcTemplate->graphicsId;
        events[i].script = npcTemplate->script;
    }
}

void SetAwardsCeremonyBugContestEventObjectGraphics(void)
{
    int i;
    const struct BugCatchingContestNPCTemplate *npcTemplate;
    struct EventObjectTemplate *events = gSaveBlock1Ptr->eventObjectTemplates;

    for (i = 0; i < NUM_BUG_CONTEST_NPCS; i++)
    {
        npcTemplate = &sBugContestNPCTemplates[gBugCatchingContestNPCs[i].templateId];
        VarSet(VAR_OBJ_GFX_ID_0 + i, npcTemplate->graphicsId);
    }
}

static void SetAwardsCeremonyBugContestEventObjectScripts(void)
{
    int i;
    const struct BugCatchingContestNPCTemplate *npcTemplate;
    int playerId = NUM_BUG_CONTEST_NPCS;
    struct EventObjectTemplate *events = gSaveBlock1Ptr->eventObjectTemplates;

    for (i = 0; i < NUM_BUG_CONTEST_NPCS; i++)
    {
        npcTemplate = &sBugContestNPCTemplates[gBugCatchingContestNPCs[i].templateId];
        if (gBugCatchingContestStandings[0] == playerId)
            events[i].script = npcTemplate->awardsScriptPlayerWon;
        else
            events[i].script = npcTemplate->awardsScriptPlayerLost;
    }
}

static const u8 *GetContestantNamePrefix(int contestantId)
{
    static const u8 sNewBarkTownsText[] = _("NEW BARK TOWN's");
    if (contestantId == NUM_BUG_CONTEST_NPCS)
        return sNewBarkTownsText;
    else
        return gTrainerClassNames[sBugContestNPCTemplates[gBugCatchingContestNPCs[contestantId].templateId].trainerClass];
}

static const u8 *GetContestantName(int contestantId)
{
    if (contestantId == NUM_BUG_CONTEST_NPCS)
        return gSaveBlock2Ptr->playerName;
    else
        return sBugContestNPCTemplates[gBugCatchingContestNPCs[contestantId].templateId].name;
}

static u8 GetContestantCaughtLevel(int contestantId)
{
    if (contestantId == NUM_BUG_CONTEST_NPCS)
    {
        if (gBugCatchingContestStatus == BUG_CATCHING_CONTEST_STATUS_CAUGHT)
            return GetMonData(&gCaughtBugCatchingContestMon, MON_DATA_LEVEL);
        else
            return 0;
    }
    else
    {
        return gBugCatchingContestNPCs[contestantId].caughtLevel;
    }
}

static u16 GetContestantCaughtSpecies(int contestantId)
{
    if (contestantId == NUM_BUG_CONTEST_NPCS)
    {
        if (gBugCatchingContestStatus == BUG_CATCHING_CONTEST_STATUS_CAUGHT)
            return GetMonData(&gCaughtBugCatchingContestMon, MON_DATA_SPECIES);
        else
            return SPECIES_NONE;
    }
    else
    {
        return gBugCatchingContestNPCs[contestantId].caughtSpecies;
    }
}

static bool8 GetContestantCaughtShiny(int contestantId)
{
    if (contestantId == NUM_BUG_CONTEST_NPCS)
    {
        if (gBugCatchingContestStatus == BUG_CATCHING_CONTEST_STATUS_CAUGHT)
            return IsMonShiny(&gCaughtBugCatchingContestMon);
        else
            return FALSE;
    }
    else
    {
        return gBugCatchingContestNPCs[contestantId].caughtShiny;
    }
}

static void BuildBugContestPlacementString_FirstPlace(void)
{
    static const u8 sFirstPlaceString_Part1[] = _("The Bug-Catching Contest winner is\n{STR_VAR_1} {STR_VAR_2} who caught\la level {STR_VAR_3} ");
    static const u8 sFirstPlaceString_Part2[] = _("{STR_VAR_1}!");
    static const u8 sFirstPlaceString_Shiny[] = _("\pAmazing! The POKéMON is shiny!\pI've never seen such a beautiful\nbug POKéMON!\p");
    u8 *str;
    int contestantId = gBugCatchingContestStandings[0];

    StringCopy(gStringVar1, GetContestantNamePrefix(contestantId));
    StringCopy(gStringVar2, GetContestantName(contestantId));
    ConvertIntToDecimalStringN(gStringVar3, GetContestantCaughtLevel(contestantId), 0, 3);
    str = StringExpandPlaceholders(gStringVar4, sFirstPlaceString_Part1);
    GetSpeciesName(gStringVar1, GetContestantCaughtSpecies(contestantId));
    str = StringExpandPlaceholders(str, sFirstPlaceString_Part2);
    if (GetContestantCaughtShiny(contestantId))
        str = StringCopy(str, sFirstPlaceString_Shiny);
}

static void BuildBugContestPlacementString_SecondPlace(void)
{
    static const u8 sSecondPlaceString_Part1[] = _("The runner-up was {STR_VAR_1}\n{STR_VAR_2} who caught a level {STR_VAR_3}\l");
    static const u8 sSecondPlaceString_Part2[] = _("{STR_VAR_1}!");
    u8 *str;
    int contestantId = gBugCatchingContestStandings[1];

    StringCopy(gStringVar1, GetContestantNamePrefix(contestantId));
    StringCopy(gStringVar2, GetContestantName(contestantId));
    ConvertIntToDecimalStringN(gStringVar3, GetContestantCaughtLevel(contestantId), 0, 3);
    str = StringExpandPlaceholders(gStringVar4, sSecondPlaceString_Part1);
    GetSpeciesName(gStringVar1, GetContestantCaughtSpecies(contestantId));
    str = StringExpandPlaceholders(str, sSecondPlaceString_Part2);
}

static void BuildBugContestPlacementString_ThirdPlace(void)
{
    static const u8 sThirdPlaceString_Part1[] = _("Placing third was {STR_VAR_1}\n{STR_VAR_2} who caught a level {STR_VAR_3}\l");
    static const u8 sThirdPlaceString_Part2[] = _("{STR_VAR_1}!");
    u8 *str;
    int contestantId = gBugCatchingContestStandings[2];

    StringCopy(gStringVar1, GetContestantNamePrefix(contestantId));
    StringCopy(gStringVar2, GetContestantName(contestantId));
    ConvertIntToDecimalStringN(gStringVar3, GetContestantCaughtLevel(contestantId), 0, 3);
    str = StringExpandPlaceholders(gStringVar4, sThirdPlaceString_Part1);
    GetSpeciesName(gStringVar1, GetContestantCaughtSpecies(contestantId));
    str = StringExpandPlaceholders(str, sThirdPlaceString_Part2);
}

void BuildBugContestPlacementString(void)
{
    if (gSpecialVar_0x8004 == 1)
        BuildBugContestPlacementString_FirstPlace();
    else if (gSpecialVar_0x8004 == 2)
        BuildBugContestPlacementString_SecondPlace();
    else
        BuildBugContestPlacementString_ThirdPlace();
}

void CopyBugContestPlacementScoreToVar1(void)
{
    ConvertIntToDecimalStringN(gStringVar1, GetContestantScore(gBugCatchingContestStandings[gSpecialVar_0x8004 - 1]), 0, 3);
}

u8 GetPlayerBugContestPlace(void)
{
    int i;
    int playerId = NUM_BUG_CONTEST_NPCS;
    for (i = 0; i < ARRAY_COUNT(gBugCatchingContestStandings); i++)
    {
        if (gBugCatchingContestStandings[i] == playerId)
            return i + 1;
    }
}

u16 GetWinningBugContestSpecies(void)
{
    gSpecialVar_0x8005 = GetContestantCaughtShiny(gBugCatchingContestStandings[0]);
    return GetContestantCaughtSpecies(gBugCatchingContestStandings[0]);
}

/////////////////////////////////
// Swapping Screen             //
/////////////////////////////////

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
    u8 *hpStr;
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
    hpStr = ConvertIntToDecimalStringN(gStringVar3, GetMonData(&gCaughtBugCatchingContestMon, MON_DATA_HP), STR_CONV_MODE_LEFT_ALIGN, 3);
    *(hpStr++) = CHAR_SLASH;
    ConvertIntToDecimalStringN(hpStr, GetMonData(&gCaughtBugCatchingContestMon, MON_DATA_MAX_HP), STR_CONV_MODE_LEFT_ALIGN, 3);
    StringExpandPlaceholders(gStringVar4, sStockMonText);
    AddTextPrinterParameterized(sSwapScreen->stockMonWindowId, 1, gStringVar4, 0, 1, 0, NULL);

    GetSpeciesName(gStringVar1, GetMonData(sSwapScreen->newMon, MON_DATA_SPECIES));
    ConvertIntToDecimalStringN(gStringVar2, GetMonData(sSwapScreen->newMon, MON_DATA_LEVEL), STR_CONV_MODE_LEFT_ALIGN, 3);
    hpStr = ConvertIntToDecimalStringN(gStringVar3, GetMonData(sSwapScreen->newMon, MON_DATA_HP), STR_CONV_MODE_LEFT_ALIGN, 3);
    *(hpStr++) = CHAR_SLASH;
    ConvertIntToDecimalStringN(hpStr, GetMonData(sSwapScreen->newMon, MON_DATA_MAX_HP), STR_CONV_MODE_LEFT_ALIGN, 3);
    StringExpandPlaceholders(gStringVar4, sNewMonText);
    AddTextPrinterParameterized(sSwapScreen->newMonWindowId, 1, gStringVar4, 0, 1, 0, NULL);

    sSwapScreen->textWindowId = AddWindow(&sTextWindowTemplate);
    LoadMessageBoxGfx(sSwapScreen->textWindowId, 0x200, 0xC0);
    LoadUserWindowBorderGfx(sSwapScreen->textWindowId, 0x214, 0xC0);
    PutWindowTilemap(sSwapScreen->textWindowId);
    NewMenuHelpers_DrawStdWindowFrame(sSwapScreen->textWindowId, FALSE);
    CopyWindowToVram(sSwapScreen->textWindowId, 3);
}

static void SwapScreenWaitFadeIn(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        GetSpeciesName(gStringVar1, GetMonData(&gCaughtBugCatchingContestMon, MON_DATA_SPECIES));
        StringExpandPlaceholders(gStringVar4, sTextAlreadyCaught);
        AddTextPrinterParameterized(sSwapScreen->textWindowId, 1, gStringVar4, 0, 1, GetPlayerTextSpeedDelay(), NULL);
        gTasks[taskId].func = SwapScreenDisplayAlreadyCaughtMessage;
    }
}

static void SwapScreenDisplayAlreadyCaughtMessage(u8 taskId)
{
    if (!IsTextPrinterActive(sSwapScreen->textWindowId))
    {
        CreateYesNoMenu(&sYesNoWindowTemplate, 0x214, 14, 0);
        gTasks[taskId].func = SwapScreenHandleInput;
    }
}

static void SwapScreenHandleInput(u8 taskId)
{
    int selection = Menu_ProcessInputNoWrapClearOnChoose();
    if (selection == 0)
    {
        FillWindowPixelBuffer(sSwapScreen->textWindowId, 0x11);
        GetSpeciesName(gStringVar1, GetMonData(&gCaughtBugCatchingContestMon, MON_DATA_SPECIES));
        StringExpandPlaceholders(gStringVar4, sTextReleasedPreviousCaughtMon);
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
