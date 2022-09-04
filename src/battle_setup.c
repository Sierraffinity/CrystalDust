#include "global.h"
#include "battle.h"
#include "battle_setup.h"
#include "battle_transition.h"
#include "bug_catching_contest.h"
#include "main.h"
#include "task.h"
#include "safari_zone.h"
#include "script.h"
#include "event_data.h"
#include "metatile_behavior.h"
#include "field_player_avatar.h"
#include "fieldmap.h"
#include "random.h"
#include "starter_choose.h"
#include "script_pokemon_util.h"
#include "palette.h"
#include "window.h"
#include "event_object_movement.h"
#include "event_scripts.h"
#include "tv.h"
#include "trainer_see.h"
#include "field_message_box.h"
#include "sound.h"
#include "strings.h"
#include "trainer_hill.h"
#include "script_pokemon_util.h"
#include "secret_base.h"
#include "string_util.h"
#include "overworld.h"
#include "field_weather.h"
#include "battle_tower.h"
#include "gym_leader_rematch.h"
#include "battle_pike.h"
#include "battle_pyramid.h"
#include "fldeff.h"
#include "fldeff_misc.h"
#include "field_control_avatar.h"
#include "mirage_tower.h"
#include "field_screen_effect.h"
#include "phone_contact.h"
#include "data.h"
#include "constants/battle_frontier.h"
#include "constants/battle_setup.h"
#include "constants/game_stat.h"
#include "constants/items.h"
#include "constants/songs.h"
#include "constants/map_types.h"
#include "constants/maps.h"
#include "constants/species.h"
#include "constants/trainers.h"
#include "constants/trainer_hill.h"
#include "constants/weather.h"

enum
{
    TRAINER_PARAM_LOAD_VAL_8BIT,
    TRAINER_PARAM_LOAD_VAL_16BIT,
    TRAINER_PARAM_LOAD_VAL_32BIT,
    TRAINER_PARAM_CLEAR_VAL_8BIT,
    TRAINER_PARAM_CLEAR_VAL_16BIT,
    TRAINER_PARAM_CLEAR_VAL_32BIT,
    TRAINER_PARAM_LOAD_SCRIPT_RET_ADDR,
};

struct TrainerBattleParameter
{
    void *varPtr;
    u8 ptrType;
};

// this file's functions
static void DoBattlePikeWildBattle(void);
static void DoSafariBattle(u32 flags);
static void DoBugCatchingContestBattle(u32 flags);
static void DoStandardWildBattle(u32 flags);
static void CB2_EndWildBattle(void);
static void CB2_EndScriptedWildBattle(void);
static u8 GetWildBattleTransition(void);
static u8 GetTrainerBattleTransition(void);
static void TryUpdateGymLeaderRematchFromWild(void);
static void TryUpdateGymLeaderRematchFromTrainer(void);
static void CB2_GiveStarter(void);
static void CB2_StartFirstBattle(void);
static void CB2_EndFirstBattle(void);
static void CB2_EndTrainerBattle(void);
static u16 GetRematchTrainerId(u16 trainerId);
static void RegisterTrainerInPhone(void);
static void HandleRematchVarsOnBattleEnd(void);
static const u8 *GetIntroSpeechOfApproachingTrainer(void);
static const u8 *GetTrainerCantBattleSpeech(void);

// ewram vars
EWRAM_DATA static u16 sTrainerBattleMode = 0;
EWRAM_DATA u16 gTrainerBattleOpponent_A = 0;
EWRAM_DATA u16 gTrainerBattleOpponent_B = 0;
EWRAM_DATA u16 gPartnerTrainerId = 0;
EWRAM_DATA static u16 sTrainerObjectEventLocalId = 0;
EWRAM_DATA static u8 *sTrainerAIntroSpeech = NULL;
EWRAM_DATA static u8 *sTrainerBIntroSpeech = NULL;
EWRAM_DATA static u8 *sTrainerADefeatSpeech = NULL;
EWRAM_DATA static u8 *sTrainerBDefeatSpeech = NULL;
EWRAM_DATA static u8 *sTrainerVictorySpeech = NULL;
EWRAM_DATA static u8 *sTrainerCannotBattleSpeech = NULL;
EWRAM_DATA static u8 *sTrainerBattleEndScript = NULL;
EWRAM_DATA static u8 *sTrainerABattleScriptRetAddr = NULL;
EWRAM_DATA static u8 *sTrainerBBattleScriptRetAddr = NULL;
EWRAM_DATA static bool8 sShouldCheckTrainerBScript = FALSE;
EWRAM_DATA static u8 sNoOfPossibleTrainerRetScripts = 0;
EWRAM_DATA static u16 sFirstBattleTutorialMode = 0;

// const rom data

// The first transition is used if the enemy pokemon are lower level than our pokemon.
// Otherwise, the second transition is used.
static const u8 sBattleTransitionTable_Wild[][2] =
{
    {B_TRANSITION_SLICE,               B_TRANSITION_WHITEFADE},     // Normal
    {B_TRANSITION_CLOCKWISE_BLACKFADE, B_TRANSITION_GRID_SQUARES},  // Cave
    {B_TRANSITION_BLUR,                B_TRANSITION_GRID_SQUARES},  // Cave with flash used
    {B_TRANSITION_WAVE,                B_TRANSITION_RIPPLE},        // Water
};

static const u8 sBattleTransitionTable_Trainer[][2] =
{
    {B_TRANSITION_POKEBALLS_TRAIL, B_TRANSITION_SHARDS},        // Normal
    {B_TRANSITION_SHUFFLE,         B_TRANSITION_BIG_POKEBALL},  // Cave
    {B_TRANSITION_BLUR,            B_TRANSITION_GRID_SQUARES},  // Cave with flash used
    {B_TRANSITION_SWIRL,           B_TRANSITION_RIPPLE},        // Water
};

// Battle Frontier (excluding Pyramid and Dome, which have their own tables below)
static const u8 sBattleTransitionTable_BattleFrontier[] =
{
    B_TRANSITION_FRONTIER_LOGO_WIGGLE, 
    B_TRANSITION_FRONTIER_LOGO_WAVE, 
    B_TRANSITION_FRONTIER_SQUARES, 
    B_TRANSITION_FRONTIER_SQUARES_SCROLL,
    B_TRANSITION_FRONTIER_CIRCLES_MEET, 
    B_TRANSITION_FRONTIER_CIRCLES_CROSS, 
    B_TRANSITION_FRONTIER_CIRCLES_ASYMMETRIC_SPIRAL, 
    B_TRANSITION_FRONTIER_CIRCLES_SYMMETRIC_SPIRAL,
    B_TRANSITION_FRONTIER_CIRCLES_MEET_IN_SEQ, 
    B_TRANSITION_FRONTIER_CIRCLES_CROSS_IN_SEQ, 
    B_TRANSITION_FRONTIER_CIRCLES_ASYMMETRIC_SPIRAL_IN_SEQ, 
    B_TRANSITION_FRONTIER_CIRCLES_SYMMETRIC_SPIRAL_IN_SEQ
};

static const u8 sBattleTransitionTable_BattlePyramid[] =
{
    B_TRANSITION_FRONTIER_SQUARES, 
    B_TRANSITION_FRONTIER_SQUARES_SCROLL, 
    B_TRANSITION_FRONTIER_SQUARES_SPIRAL
};

static const u8 sBattleTransitionTable_BattleDome[] =
{
    B_TRANSITION_FRONTIER_LOGO_WIGGLE, 
    B_TRANSITION_FRONTIER_SQUARES, 
    B_TRANSITION_FRONTIER_SQUARES_SCROLL, 
    B_TRANSITION_FRONTIER_SQUARES_SPIRAL
};

static const struct TrainerBattleParameter sOrdinaryBattleParams[] =
{
    {&sTrainerBattleMode,           TRAINER_PARAM_LOAD_VAL_8BIT},
    {&gTrainerBattleOpponent_A,     TRAINER_PARAM_LOAD_VAL_16BIT},
    {&sTrainerObjectEventLocalId,   TRAINER_PARAM_LOAD_VAL_16BIT},
    {&sTrainerAIntroSpeech,         TRAINER_PARAM_LOAD_VAL_32BIT},
    {&sTrainerADefeatSpeech,        TRAINER_PARAM_LOAD_VAL_32BIT},
    {&sTrainerVictorySpeech,        TRAINER_PARAM_CLEAR_VAL_32BIT},
    {&sTrainerCannotBattleSpeech,   TRAINER_PARAM_CLEAR_VAL_32BIT},
    {&sTrainerABattleScriptRetAddr, TRAINER_PARAM_CLEAR_VAL_32BIT},
    {&sTrainerBattleEndScript,      TRAINER_PARAM_LOAD_SCRIPT_RET_ADDR},
};

static const struct TrainerBattleParameter sContinueScriptBattleParams[] =
{
    {&sTrainerBattleMode,           TRAINER_PARAM_LOAD_VAL_8BIT},
    {&gTrainerBattleOpponent_A,     TRAINER_PARAM_LOAD_VAL_16BIT},
    {&sTrainerObjectEventLocalId,   TRAINER_PARAM_LOAD_VAL_16BIT},
    {&sTrainerAIntroSpeech,         TRAINER_PARAM_LOAD_VAL_32BIT},
    {&sTrainerADefeatSpeech,        TRAINER_PARAM_LOAD_VAL_32BIT},
    {&sTrainerVictorySpeech,        TRAINER_PARAM_CLEAR_VAL_32BIT},
    {&sTrainerCannotBattleSpeech,   TRAINER_PARAM_CLEAR_VAL_32BIT},
    {&sTrainerABattleScriptRetAddr, TRAINER_PARAM_LOAD_VAL_32BIT},
    {&sTrainerBattleEndScript,      TRAINER_PARAM_LOAD_SCRIPT_RET_ADDR},
};

static const struct TrainerBattleParameter sDoubleBattleParams[] =
{
    {&sTrainerBattleMode,           TRAINER_PARAM_LOAD_VAL_8BIT},
    {&gTrainerBattleOpponent_A,     TRAINER_PARAM_LOAD_VAL_16BIT},
    {&sTrainerObjectEventLocalId,   TRAINER_PARAM_LOAD_VAL_16BIT},
    {&sTrainerAIntroSpeech,         TRAINER_PARAM_LOAD_VAL_32BIT},
    {&sTrainerADefeatSpeech,        TRAINER_PARAM_LOAD_VAL_32BIT},
    {&sTrainerVictorySpeech,        TRAINER_PARAM_CLEAR_VAL_32BIT},
    {&sTrainerCannotBattleSpeech,   TRAINER_PARAM_LOAD_VAL_32BIT},
    {&sTrainerABattleScriptRetAddr, TRAINER_PARAM_CLEAR_VAL_32BIT},
    {&sTrainerBattleEndScript,      TRAINER_PARAM_LOAD_SCRIPT_RET_ADDR},
};

static const struct TrainerBattleParameter sOrdinaryNoIntroBattleParams[] =
{
    {&sTrainerBattleMode,           TRAINER_PARAM_LOAD_VAL_8BIT},
    {&gTrainerBattleOpponent_A,     TRAINER_PARAM_LOAD_VAL_16BIT},
    {&sTrainerObjectEventLocalId,   TRAINER_PARAM_LOAD_VAL_16BIT},
    {&sTrainerAIntroSpeech,         TRAINER_PARAM_CLEAR_VAL_32BIT},
    {&sTrainerADefeatSpeech,        TRAINER_PARAM_LOAD_VAL_32BIT},
    {&sTrainerVictorySpeech,        TRAINER_PARAM_CLEAR_VAL_32BIT},
    {&sTrainerCannotBattleSpeech,   TRAINER_PARAM_CLEAR_VAL_32BIT},
    {&sTrainerABattleScriptRetAddr, TRAINER_PARAM_CLEAR_VAL_32BIT},
    {&sTrainerBattleEndScript,      TRAINER_PARAM_LOAD_SCRIPT_RET_ADDR},
};

static const struct TrainerBattleParameter sWinLoseNoIntroBattleParams[] =
{
    {&sTrainerBattleMode,           TRAINER_PARAM_LOAD_VAL_8BIT},
    {&gTrainerBattleOpponent_A,     TRAINER_PARAM_LOAD_VAL_16BIT},
    {&sFirstBattleTutorialMode,     TRAINER_PARAM_LOAD_VAL_16BIT},
    {&sTrainerAIntroSpeech,         TRAINER_PARAM_CLEAR_VAL_32BIT},
    {&sTrainerADefeatSpeech,        TRAINER_PARAM_LOAD_VAL_32BIT},
    {&sTrainerVictorySpeech,        TRAINER_PARAM_LOAD_VAL_32BIT},
    {&sTrainerCannotBattleSpeech,   TRAINER_PARAM_CLEAR_VAL_32BIT},
    {&sTrainerABattleScriptRetAddr, TRAINER_PARAM_CLEAR_VAL_32BIT},
    {&sTrainerBattleEndScript,      TRAINER_PARAM_LOAD_SCRIPT_RET_ADDR},
};

static const struct TrainerBattleParameter sContinueScriptDoubleBattleParams[] =
{
    {&sTrainerBattleMode,           TRAINER_PARAM_LOAD_VAL_8BIT},
    {&gTrainerBattleOpponent_A,     TRAINER_PARAM_LOAD_VAL_16BIT},
    {&sTrainerObjectEventLocalId,   TRAINER_PARAM_LOAD_VAL_16BIT},
    {&sTrainerAIntroSpeech,         TRAINER_PARAM_LOAD_VAL_32BIT},
    {&sTrainerADefeatSpeech,        TRAINER_PARAM_LOAD_VAL_32BIT},
    {&sTrainerVictorySpeech,        TRAINER_PARAM_CLEAR_VAL_32BIT},
    {&sTrainerCannotBattleSpeech,   TRAINER_PARAM_LOAD_VAL_32BIT},
    {&sTrainerABattleScriptRetAddr, TRAINER_PARAM_LOAD_VAL_32BIT},
    {&sTrainerBattleEndScript,      TRAINER_PARAM_LOAD_SCRIPT_RET_ADDR},
};

static const struct TrainerBattleParameter sTrainerBOrdinaryBattleParams[] =
{
    {&sTrainerBattleMode,           TRAINER_PARAM_LOAD_VAL_8BIT},
    {&gTrainerBattleOpponent_B,     TRAINER_PARAM_LOAD_VAL_16BIT},
    {&sTrainerObjectEventLocalId,   TRAINER_PARAM_LOAD_VAL_16BIT},
    {&sTrainerBIntroSpeech,         TRAINER_PARAM_LOAD_VAL_32BIT},
    {&sTrainerBDefeatSpeech,        TRAINER_PARAM_LOAD_VAL_32BIT},
    {&sTrainerVictorySpeech,        TRAINER_PARAM_CLEAR_VAL_32BIT},
    {&sTrainerCannotBattleSpeech,   TRAINER_PARAM_CLEAR_VAL_32BIT},
    {&sTrainerBBattleScriptRetAddr, TRAINER_PARAM_CLEAR_VAL_32BIT},
    {&sTrainerBattleEndScript,      TRAINER_PARAM_LOAD_SCRIPT_RET_ADDR},
};

static const struct TrainerBattleParameter sTrainerBContinueScriptBattleParams[] =
{
    {&sTrainerBattleMode,           TRAINER_PARAM_LOAD_VAL_8BIT},
    {&gTrainerBattleOpponent_B,     TRAINER_PARAM_LOAD_VAL_16BIT},
    {&sTrainerObjectEventLocalId,   TRAINER_PARAM_LOAD_VAL_16BIT},
    {&sTrainerBIntroSpeech,         TRAINER_PARAM_LOAD_VAL_32BIT},
    {&sTrainerBDefeatSpeech,        TRAINER_PARAM_LOAD_VAL_32BIT},
    {&sTrainerVictorySpeech,        TRAINER_PARAM_CLEAR_VAL_32BIT},
    {&sTrainerCannotBattleSpeech,   TRAINER_PARAM_CLEAR_VAL_32BIT},
    {&sTrainerBBattleScriptRetAddr, TRAINER_PARAM_LOAD_VAL_32BIT},
    {&sTrainerBattleEndScript,      TRAINER_PARAM_LOAD_SCRIPT_RET_ADDR},
};

#define REMATCH(trainer1, trainer2, trainer3, trainer4, trainer5, map, contactId)  \
{                                                                       \
    .trainerIds = {trainer1, trainer2, trainer3, trainer4, trainer5},   \
    .mapGroup = MAP_GROUP(map),                                         \
    .mapNum = MAP_NUM(map),                                             \
    .phoneContactId = contactId,                                        \
}

const struct RematchTrainer gRematchTable[REMATCH_TABLE_ENTRIES] =
{
    [REMATCH_ANDRES] = REMATCH(TRAINER_ANDRES_1, TRAINER_ANDRES_2, TRAINER_ANDRES_3, TRAINER_ANDRES_4, TRAINER_ANDRES_5, ROUTE33, PHONE_CONTACT_ANDRES),
    [REMATCH_DUSTY] = REMATCH(TRAINER_GINA, TRAINER_IRENE, TRAINER_JENN, TRAINER_KATE, TRAINER_CARRIE, ROUTE111, PHONE_CONTACT_DUSTY),
    [REMATCH_LOLA] = REMATCH(TRAINER_DONALD, TRAINER_BROOKE, TRAINER_KIM, TRAINER_BRYAN, TRAINER_WALT, ROUTE109, PHONE_CONTACT_LOLA),
    [REMATCH_RICKY] = REMATCH(TRAINER_ARNIE, TRAINER_JACK, TRAINER_BEVERLY, TRAINER_WILLIAM, TRAINER_KRISE, ROUTE109, PHONE_CONTACT_RICKY),
    [REMATCH_LILA_AND_ROY] = REMATCH(TRAINER_LILA_AND_ROY_1, TRAINER_LILA_AND_ROY_2, TRAINER_LILA_AND_ROY_3, TRAINER_LILA_AND_ROY_4, TRAINER_LILA_AND_ROY_5, ROUTE124, PHONE_CONTACT_LILA_AND_ROY),
    [REMATCH_CRISTIN] = REMATCH(TRAINER_CRISTIN_1, TRAINER_CRISTIN_2, TRAINER_CRISTIN_3, TRAINER_CRISTIN_4, TRAINER_CRISTIN_5, ROUTE121, PHONE_CONTACT_CRISTIN),
    [REMATCH_BROOKE] = REMATCH(TRAINER_BROOKE_OLD_1, TRAINER_BROOKE_OLD_2, TRAINER_BROOKE_OLD_3, TRAINER_BROOKE_OLD_4, TRAINER_BROOKE_OLD_5, ROUTE111, PHONE_CONTACT_BROOKE),
    [REMATCH_WILTON] = REMATCH(TRAINER_WILTON_1, TRAINER_WILTON_2, TRAINER_WILTON_3, TRAINER_WILTON_4, TRAINER_WILTON_5, ROUTE111, PHONE_CONTACT_WILTON),
    [REMATCH_VALERIE] = REMATCH(TRAINER_VALERIE_1, TRAINER_VALERIE_2, TRAINER_VALERIE_3, TRAINER_VALERIE_4, TRAINER_VALERIE_5, MT_PYRE_6F, PHONE_CONTACT_VALERIE),
    [REMATCH_CINDY] = REMATCH(TRAINER_CINDY_1, TRAINER_CINDY_3, TRAINER_CINDY_4, TRAINER_CINDY_5, TRAINER_CINDY_6, ROUTE32, PHONE_CONTACT_CINDY),
    [REMATCH_THALIA] = REMATCH(TRAINER_THALIA_1, TRAINER_THALIA_2, TRAINER_THALIA_3, TRAINER_THALIA_4, TRAINER_THALIA_5, SPROUT_TOWER_3F, PHONE_CONTACT_THALIA),
    [REMATCH_JESSICA] = REMATCH(TRAINER_JESSICA_1, TRAINER_JESSICA_2, TRAINER_JESSICA_3, TRAINER_JESSICA_4, TRAINER_JESSICA_5, ROUTE121, PHONE_CONTACT_JESSICA),
    [REMATCH_WINSTON] = REMATCH(TRAINER_WINSTON_1, TRAINER_WINSTON_2, TRAINER_WINSTON_3, TRAINER_WINSTON_4, TRAINER_WINSTON_5, ROUTE32, PHONE_CONTACT_WINSTON),
    [REMATCH_STEVE] = REMATCH(TRAINER_STEVE_1, TRAINER_STEVE_2, TRAINER_STEVE_3, TRAINER_STEVE_4, TRAINER_STEVE_5, ROUTE114, PHONE_CONTACT_STEVE),
    [REMATCH_TONY] = REMATCH(TRAINER_TONY_1, TRAINER_TONY_2, TRAINER_TONY_3, TRAINER_TONY_4, TRAINER_TONY_5, ROUTE35, PHONE_CONTACT_TONY),
    [REMATCH_NOB] = REMATCH(TRAINER_NOB_1, TRAINER_NOB_2, TRAINER_NOB_3, TRAINER_NOB_4, TRAINER_NOB_5, ROUTE115, PHONE_CONTACT_NOB),
    [REMATCH_KOJI] = REMATCH(TRAINER_KOJI_1, TRAINER_KOJI_2, TRAINER_KOJI_3, TRAINER_KOJI_4, TRAINER_KOJI_5, ROUTE127, PHONE_CONTACT_KOJI),
    [REMATCH_FERNANDO] = REMATCH(TRAINER_FERNANDO_1, TRAINER_FERNANDO_2, TRAINER_FERNANDO_3, TRAINER_FERNANDO_4, TRAINER_FERNANDO_5, ROUTE123, PHONE_CONTACT_FERNANDO),
    [REMATCH_DALTON] = REMATCH(TRAINER_DALTON_1, TRAINER_DALTON_2, TRAINER_DALTON_3, TRAINER_DALTON_4, TRAINER_DALTON_5, ROUTE46, PHONE_CONTACT_DALTON),
    [REMATCH_BERNIE] = REMATCH(TRAINER_BERNIE_1, TRAINER_BERNIE_2, TRAINER_BERNIE_3, TRAINER_BERNIE_4, TRAINER_BERNIE_5, ROUTE114, PHONE_CONTACT_BERNIE),
    [REMATCH_ETHAN] = REMATCH(TRAINER_ETHAN_1, TRAINER_ETHAN_2, TRAINER_ETHAN_3, TRAINER_ETHAN_4, TRAINER_ETHAN_5, JAGGED_PASS, PHONE_CONTACT_ETHAN),
    [REMATCH_JOHN_AND_JAY] = REMATCH(TRAINER_JOHN_AND_JAY_1, TRAINER_JOHN_AND_JAY_2, TRAINER_JOHN_AND_JAY_3, TRAINER_JOHN_AND_JAY_4, TRAINER_JOHN_AND_JAY_5, RADIO_TOWER_2F, PHONE_CONTACT_JOHN_AND_JAY),
    [REMATCH_JEFFREY] = REMATCH(TRAINER_JEFFREY_1, TRAINER_JEFFREY_2, TRAINER_JEFFREY_3, TRAINER_JEFFREY_4, TRAINER_JEFFREY_5, ROUTE120, PHONE_CONTACT_JEFFREY),
    [REMATCH_CAMERON] = REMATCH(TRAINER_CAMERON_1, TRAINER_CAMERON_2, TRAINER_CAMERON_3, TRAINER_CAMERON_4, TRAINER_CAMERON_5, ROUTE123, PHONE_CONTACT_CAMERON),
    [REMATCH_JACKI] = REMATCH(TRAINER_JACKI_1, TRAINER_JACKI_2, TRAINER_JACKI_3, TRAINER_JACKI_4, TRAINER_JACKI_5, ROUTE123, PHONE_CONTACT_JACKI),
    [REMATCH_WALTER] = REMATCH(TRAINER_WALTER_1, TRAINER_WALTER_2, TRAINER_WALTER_3, TRAINER_WALTER_4, TRAINER_WALTER_5, ROUTE121, PHONE_CONTACT_WALTER),
    [REMATCH_KAREN] = REMATCH(TRAINER_KAREN_1, TRAINER_KAREN_2, TRAINER_KAREN_3, TRAINER_KAREN_4, TRAINER_KAREN_5, ROUTE116, PHONE_CONTACT_KAREN),
    [REMATCH_JERRY] = REMATCH(TRAINER_JERRY_1, TRAINER_JERRY_2, TRAINER_JERRY_3, TRAINER_JERRY_4, TRAINER_JERRY_5, ROUTE116, PHONE_CONTACT_JERRY),
    [REMATCH_ANNA_AND_MEG] = REMATCH(TRAINER_ANNA_AND_MEG_1, TRAINER_ANNA_AND_MEG_2, TRAINER_ANNA_AND_MEG_3, TRAINER_ANNA_AND_MEG_4, TRAINER_ANNA_AND_MEG_5, ROUTE45, PHONE_CONTACT_ANNA_AND_MEG),
    [REMATCH_ISABEL] = REMATCH(TRAINER_ISABEL_1, TRAINER_ISABEL_2, TRAINER_ISABEL_3, TRAINER_ISABEL_4, TRAINER_ISABEL_5, ROUTE110, PHONE_CONTACT_ISABEL),
    [REMATCH_MIGUEL] = REMATCH(TRAINER_MIGUEL_1, TRAINER_MIGUEL_2, TRAINER_MIGUEL_3, TRAINER_MIGUEL_4, TRAINER_MIGUEL_5, ROUTE31, PHONE_CONTACT_MIGUEL),
    [REMATCH_TIMOTHY] = REMATCH(TRAINER_TIMOTHY_1, TRAINER_TIMOTHY_2, TRAINER_TIMOTHY_3, TRAINER_TIMOTHY_4, TRAINER_TIMOTHY_5, ROUTE115, PHONE_CONTACT_TIMOTHY),
    [REMATCH_SHELBY] = REMATCH(TRAINER_SHELBY_1, TRAINER_SHELBY_2, TRAINER_SHELBY_3, TRAINER_SHELBY_4, TRAINER_SHELBY_5, SLOWPOKE_WELL_B1F, PHONE_CONTACT_SHELBY),
    [REMATCH_CALVIN] = REMATCH(TRAINER_CALVIN_1, TRAINER_CALVIN_2, TRAINER_CALVIN_3, TRAINER_CALVIN_4, TRAINER_CALVIN_5, ROUTE30, PHONE_CONTACT_CALVIN),
    [REMATCH_ELLIOT] = REMATCH(TRAINER_ELLIOT_OLD_1, TRAINER_ELLIOT_OLD_2, TRAINER_ELLIOT_OLD_3, TRAINER_ELLIOT_OLD_4, TRAINER_ELLIOT_OLD_5, ROUTE34, PHONE_CONTACT_ELLIOT),
    [REMATCH_ISAIAH] = REMATCH(TRAINER_ISAIAH_1, TRAINER_ISAIAH_2, TRAINER_ISAIAH_3, TRAINER_ISAIAH_4, TRAINER_ISAIAH_5, ROUTE128, PHONE_CONTACT_ISAIAH),
    [REMATCH_MARIA] = REMATCH(TRAINER_MARIA_1, TRAINER_MARIA_2, TRAINER_MARIA_3, TRAINER_MARIA_4, TRAINER_MARIA_5, ROUTE45, PHONE_CONTACT_MARIA),
    [REMATCH_ABIGAIL] = REMATCH(TRAINER_ABIGAIL_1, TRAINER_ABIGAIL_2, TRAINER_ABIGAIL_3, TRAINER_ABIGAIL_4, TRAINER_ABIGAIL_5, ROUTE110, PHONE_CONTACT_ABIGAIL),
    [REMATCH_DYLAN] = REMATCH(TRAINER_DYLAN_1, TRAINER_DYLAN_2, TRAINER_DYLAN_3, TRAINER_DYLAN_4, TRAINER_DYLAN_5, ROUTE45, PHONE_CONTACT_DYLAN),
    [REMATCH_KATELYN] = REMATCH(TRAINER_KATELYN_1, TRAINER_KATELYN_2, TRAINER_KATELYN_3, TRAINER_KATELYN_4, TRAINER_KATELYN_5, ROUTE128, PHONE_CONTACT_KATELYN),
    [REMATCH_BENJAMIN] = REMATCH(TRAINER_BENJAMIN_1, TRAINER_BENJAMIN_2, TRAINER_BENJAMIN_3, TRAINER_BENJAMIN_4, TRAINER_BENJAMIN_5, ROUTE110, PHONE_CONTACT_BENJAMIN),
    [REMATCH_PABLO] = REMATCH(TRAINER_PABLO_1, TRAINER_PABLO_2, TRAINER_PABLO_3, TRAINER_PABLO_4, TRAINER_PABLO_5, ROUTE126, PHONE_CONTACT_PABLO),
    [REMATCH_NICOLAS] = REMATCH(TRAINER_NICOLAS_1, TRAINER_NICOLAS_2, TRAINER_NICOLAS_3, TRAINER_NICOLAS_4, TRAINER_NICOLAS_5, RADIO_TOWER_2F, PHONE_CONTACT_NICOLAS),
    [REMATCH_ROBERT] = REMATCH(TRAINER_ROBERT_1, TRAINER_ROBERT_2, TRAINER_ROBERT_3, TRAINER_ROBERT_4, TRAINER_ROBERT_5, ROUTE120, PHONE_CONTACT_ROBERT),
    [REMATCH_LAO] = REMATCH(TRAINER_LAO_1, TRAINER_LAO_2, TRAINER_LAO_3, TRAINER_LAO_4, TRAINER_LAO_5, ROUTE113, PHONE_CONTACT_LAO),
    [REMATCH_CYNDY] = REMATCH(TRAINER_CYNDY_1, TRAINER_CYNDY_2, TRAINER_CYNDY_3, TRAINER_CYNDY_4, TRAINER_CYNDY_5, ROUTE115, PHONE_CONTACT_CYNDY),
    [REMATCH_MADELINE] = REMATCH(TRAINER_MADELINE_1, TRAINER_MADELINE_2, TRAINER_MADELINE_3, TRAINER_MADELINE_4, TRAINER_MADELINE_5, ROUTE113, PHONE_CONTACT_MADELINE),
    [REMATCH_JENNY] = REMATCH(TRAINER_JENNY_1, TRAINER_JENNY_2, TRAINER_JENNY_3, TRAINER_JENNY_4, TRAINER_JENNY_5, ROUTE124, PHONE_CONTACT_JENNY),
    [REMATCH_DIANA] = REMATCH(TRAINER_DIANA_1, TRAINER_DIANA_2, TRAINER_DIANA_3, TRAINER_DIANA_4, TRAINER_DIANA_5, JAGGED_PASS, PHONE_CONTACT_DIANA),
    [REMATCH_AMY_AND_LIV] = REMATCH(TRAINER_AMY_AND_LIV_1, TRAINER_AMY_AND_LIV_2, TRAINER_AMY_AND_LIV_4, TRAINER_AMY_AND_LIV_5, TRAINER_AMY_AND_LIV_6, ROUTE31, PHONE_CONTACT_AMY_AND_LIV),
    [REMATCH_ERNEST] = REMATCH(TRAINER_ERNEST_1, TRAINER_ERNEST_2, TRAINER_ERNEST_3, TRAINER_ERNEST_4, TRAINER_ERNEST_5, ROUTE125, PHONE_CONTACT_ERNEST),
    [REMATCH_CORY] = REMATCH(TRAINER_CORY_1, TRAINER_CORY_2, TRAINER_CORY_3, TRAINER_CORY_4, TRAINER_CORY_5, ROUTE36, PHONE_CONTACT_CORY),
    [REMATCH_EDWIN] = REMATCH(TRAINER_EDWIN_1, TRAINER_EDWIN_2, TRAINER_EDWIN_3, TRAINER_EDWIN_4, TRAINER_EDWIN_5, ROUTE110, PHONE_CONTACT_EDWIN),
    [REMATCH_LYDIA] = REMATCH(TRAINER_LYDIA_1, TRAINER_LYDIA_2, TRAINER_LYDIA_3, TRAINER_LYDIA_4, TRAINER_LYDIA_5, ROUTE45, PHONE_CONTACT_LYDIA),
    [REMATCH_ISAAC] = REMATCH(TRAINER_ISAAC_1, TRAINER_ISAAC_2, TRAINER_ISAAC_3, TRAINER_ISAAC_4, TRAINER_ISAAC_5, ROUTE45, PHONE_CONTACT_ISAAC),
    [REMATCH_GABRIELLE] = REMATCH(TRAINER_TROY, TRAINER_GABRIELLE_2, TRAINER_GABRIELLE_3, TRAINER_GABRIELLE_4, TRAINER_GABRIELLE_5, MT_PYRE_3F, PHONE_CONTACT_GABRIELLE),
    [REMATCH_CATHERINE] = REMATCH(TRAINER_CATHERINE_1, TRAINER_CATHERINE_2, TRAINER_CATHERINE_3, TRAINER_CATHERINE_4, TRAINER_CATHERINE_5, ROUTE119, PHONE_CONTACT_CATHERINE),
    [REMATCH_JACKSON] = REMATCH(TRAINER_JACKSON_1, TRAINER_JACKSON_2, TRAINER_JACKSON_3, TRAINER_JACKSON_4, TRAINER_JACKSON_5, ROUTE119, PHONE_CONTACT_JACKSON),
    [REMATCH_HALEY] = REMATCH(TRAINER_HALEY_1, TRAINER_HALEY_2, TRAINER_HALEY_3, TRAINER_HALEY_4, TRAINER_HALEY_5, ROUTE32, PHONE_CONTACT_HALEY),
    [REMATCH_JAMES] = REMATCH(TRAINER_JAMES_1, TRAINER_JAMES_2, TRAINER_JAMES_3, TRAINER_JAMES_4, TRAINER_JAMES_5, ILEX_FOREST, PHONE_CONTACT_JAMES),
    [REMATCH_TRENT] = REMATCH(TRAINER_TRENT_1, TRAINER_TRENT_2, TRAINER_TRENT_3, TRAINER_TRENT_4, TRAINER_TRENT_5, ROUTE112, PHONE_CONTACT_TRENT),
    [REMATCH_SAWYER] = REMATCH(TRAINER_JOEY_1, TRAINER_SAWYER_2, TRAINER_SAWYER_3, TRAINER_SAWYER_4, TRAINER_SAWYER_5, SLOWPOKE_WELL_B1F, PHONE_CONTACT_SAWYER),
    [REMATCH_KIRA_AND_DAN] = REMATCH(TRAINER_KIRA_AND_DAN_1, TRAINER_KIRA_AND_DAN_2, TRAINER_KIRA_AND_DAN_3, TRAINER_KIRA_AND_DAN_4, TRAINER_KIRA_AND_DAN_5, RUINS_OF_ALPH_KABUTO_ITEM_ROOM, PHONE_CONTACT_KIRA_AND_DAN),
    [REMATCH_WALLY_3] = REMATCH(TRAINER_WALLY_VR_2, TRAINER_WALLY_VR_3, TRAINER_WALLY_VR_4, TRAINER_WALLY_VR_5, TRAINER_WALLY_VR_5, VICTORY_ROAD_1F, PHONE_CONTACT_WALLY),
    [REMATCH_ROXANNE] = REMATCH(TRAINER_FALKNER, TRAINER_ROXANNE_2, TRAINER_ROXANNE_3, TRAINER_ROXANNE_4, TRAINER_ROXANNE_5, GOLDENROD_CITY, PHONE_CONTACT_ROXANNE),
    [REMATCH_BRAWLY] = REMATCH(TRAINER_BUGSY, TRAINER_BRAWLY_2, TRAINER_BRAWLY_3, TRAINER_BRAWLY_4, TRAINER_BRAWLY_5, AZALEA_TOWN, PHONE_CONTACT_BRAWLY),
    [REMATCH_WATTSON] = REMATCH(TRAINER_WHITNEY, TRAINER_WATTSON_2, TRAINER_WATTSON_3, TRAINER_WATTSON_4, TRAINER_WATTSON_5, MAUVILLE_CITY, PHONE_CONTACT_WATTSON),
    [REMATCH_FLANNERY] = REMATCH(TRAINER_FLANNERY_1, TRAINER_FLANNERY_2, TRAINER_FLANNERY_3, TRAINER_FLANNERY_4, TRAINER_FLANNERY_5, LAVARIDGE_TOWN, PHONE_CONTACT_FLANNERY),
    [REMATCH_NORMAN] = REMATCH(TRAINER_NORMAN_1, TRAINER_NORMAN_2, TRAINER_NORMAN_3, TRAINER_NORMAN_4, TRAINER_NORMAN_5, VIOLET_CITY, PHONE_CONTACT_NORMAN),
    [REMATCH_WINONA] = REMATCH(TRAINER_WINONA_1, TRAINER_WINONA_2, TRAINER_WINONA_3, TRAINER_WINONA_4, TRAINER_WINONA_5, FORTREE_CITY, PHONE_CONTACT_WINONA),
    [REMATCH_TATE_AND_LIZA] = REMATCH(TRAINER_TATE_AND_LIZA_1, TRAINER_TATE_AND_LIZA_2, TRAINER_TATE_AND_LIZA_3, TRAINER_TATE_AND_LIZA_4, TRAINER_TATE_AND_LIZA_5, MOSSDEEP_CITY, PHONE_CONTACT_TATE_AND_LIZA),
    [REMATCH_JUAN] = REMATCH(TRAINER_JUAN_1, TRAINER_JUAN_2, TRAINER_JUAN_3, TRAINER_JUAN_4, TRAINER_JUAN_5, SOOTOPOLIS_CITY, PHONE_CONTACT_JUAN),
    [REMATCH_SIDNEY] = REMATCH(TRAINER_SIDNEY, TRAINER_SIDNEY, TRAINER_SIDNEY, TRAINER_SIDNEY, TRAINER_SIDNEY, EVER_GRANDE_CITY, PHONE_CONTACT_SIDNEY),
    [REMATCH_PHOEBE] = REMATCH(TRAINER_PHOEBE, TRAINER_PHOEBE, TRAINER_PHOEBE, TRAINER_PHOEBE, TRAINER_PHOEBE, EVER_GRANDE_CITY, PHONE_CONTACT_PHOEBE),
    [REMATCH_GLACIA] = REMATCH(TRAINER_GLACIA, TRAINER_GLACIA, TRAINER_GLACIA, TRAINER_GLACIA, TRAINER_GLACIA, EVER_GRANDE_CITY, PHONE_CONTACT_GLACIA),
    [REMATCH_DRAKE] = REMATCH(TRAINER_DRAKE, TRAINER_DRAKE, TRAINER_DRAKE, TRAINER_DRAKE, TRAINER_DRAKE, EVER_GRANDE_CITY, PHONE_CONTACT_DRAKE),
    [REMATCH_WALLACE] = REMATCH(TRAINER_WALLACE, TRAINER_WALLACE, TRAINER_WALLACE, TRAINER_WALLACE, TRAINER_WALLACE, EVER_GRANDE_CITY, PHONE_CONTACT_WALLACE),
};

static const u16 sBadgeFlags[NUM_BADGES] =
{
    FLAG_BADGE01_GET, FLAG_BADGE02_GET, FLAG_BADGE03_GET, FLAG_BADGE04_GET,
    FLAG_BADGE05_GET, FLAG_BADGE06_GET, FLAG_BADGE07_GET, FLAG_BADGE08_GET,
};

#define tState data[0]
#define tTransition data[1]

static void Task_BattleStart(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    switch (tState)
    {
    case 0:
        if (!FldEffPoison_IsActive()) // is poison not active?
        {
            BattleTransition_StartOnField(tTransition);
            ClearMirageTowerPulseBlendEffect();
            tState++; // go to case 1.
        }
        break;
    case 1:
        if (IsBattleTransitionDone() == TRUE)
        {
            CleanupOverworldWindowsAndTilemaps();
            SetMainCallback2(CB2_InitBattle);
            RestartWildEncounterImmunitySteps();
            ClearPoisonStepCounter();
            DestroyTask(taskId);
        }
        break;
    }
}

static void CreateBattleStartTask(u8 transition, u16 song)
{
    u8 taskId = CreateTask(Task_BattleStart, 1);

    gTasks[taskId].tTransition = transition;
    PlayMapChosenOrBattleBGM(song);
}

#undef tState
#undef tTransition

void BattleSetup_StartWildBattle(u32 flags)
{
    if (GetSafariZoneFlag())
        DoSafariBattle(flags);
    else if (InBugCatchingContest())
        DoBugCatchingContestBattle(flags);
    else
        DoStandardWildBattle(flags);
}

void BattleSetup_StartBattlePikeWildBattle(void)
{
    DoBattlePikeWildBattle();
}

static void DoStandardWildBattle(u32 flags)
{
    ScriptContext2_Enable();
    FreezeObjectEvents();
    sub_808BCF4();
    gMain.savedCallback = CB2_EndWildBattle;
    gBattleTypeFlags = flags;
    if (InBattlePyramid())
    {
        VarSet(VAR_TEMP_E, 0);
        gBattleTypeFlags |= BATTLE_TYPE_PYRAMID;
    }
    CreateBattleStartTask(GetWildBattleTransition(), 0);
    IncrementGameStat(GAME_STAT_TOTAL_BATTLES);
    IncrementGameStat(GAME_STAT_WILD_BATTLES);
    IncrementDailyWildBattles();
    TryUpdateGymLeaderRematchFromWild();
}

void BattleSetup_StartRoamerBattle(void)
{
    ScriptContext2_Enable();
    FreezeObjectEvents();
    sub_808BCF4();
    gMain.savedCallback = CB2_EndWildBattle;
    gBattleTypeFlags = BATTLE_TYPE_ROAMER;
    CreateBattleStartTask(GetWildBattleTransition(), 0);
    IncrementGameStat(GAME_STAT_TOTAL_BATTLES);
    IncrementGameStat(GAME_STAT_WILD_BATTLES);
    IncrementDailyWildBattles();
    TryUpdateGymLeaderRematchFromWild();
}

static void DoSafariBattle(u32 flags)
{
    ScriptContext2_Enable();
    FreezeObjectEvents();
    sub_808BCF4();
    gMain.savedCallback = CB2_EndSafariBattle;
    gBattleTypeFlags = BATTLE_TYPE_SAFARI | flags;
    CreateBattleStartTask(GetWildBattleTransition(), 0);
}

static void DoBattlePikeWildBattle(void)
{
    ScriptContext2_Enable();
    FreezeObjectEvents();
    sub_808BCF4();
    gMain.savedCallback = CB2_EndWildBattle;
    gBattleTypeFlags = BATTLE_TYPE_PIKE;
    CreateBattleStartTask(GetWildBattleTransition(), 0);
    IncrementGameStat(GAME_STAT_TOTAL_BATTLES);
    IncrementGameStat(GAME_STAT_WILD_BATTLES);
    IncrementDailyWildBattles();
    TryUpdateGymLeaderRematchFromWild();
}

static void DoTrainerBattle(void)
{
    CreateBattleStartTask(GetTrainerBattleTransition(), 0);
    IncrementGameStat(GAME_STAT_TOTAL_BATTLES);
    IncrementGameStat(GAME_STAT_TRAINER_BATTLES);
    TryUpdateGymLeaderRematchFromTrainer();
}

static void DoBugCatchingContestBattle(u32 flags)
{
    ScriptContext2_Enable();
    FreezeObjectEvents();
    sub_808BCF4();
    gMain.savedCallback = CB2_EndBugCatchingContestBattle;
    gBattleTypeFlags = BATTLE_TYPE_BUG_CATCHING_CONTEST | flags;
    CreateBattleStartTask(GetWildBattleTransition(), 0);
    IncrementGameStat(GAME_STAT_TOTAL_BATTLES);
    IncrementGameStat(GAME_STAT_WILD_BATTLES);
    IncrementDailyWildBattles();
    TryUpdateGymLeaderRematchFromWild();
}

static void sub_80B0828(void)
{
    if (InBattlePyramid())
        CreateBattleStartTask(GetSpecialBattleTransition(10), 0);
    else
        CreateBattleStartTask(GetSpecialBattleTransition(11), 0);

    IncrementGameStat(GAME_STAT_TOTAL_BATTLES);
    IncrementGameStat(GAME_STAT_TRAINER_BATTLES);
    TryUpdateGymLeaderRematchFromTrainer();
}

// Initiates battle where Dude catches Rattata
void StartDudeTutorialBattle(void)
{
    CreateMon(&gEnemyParty[0], SPECIES_RATTATA, 5, 32, 0, 0, 0, 0);
    ScriptContext2_Enable();
    gMain.savedCallback = CB2_ReturnToFieldContinueScriptPlayMapMusic;
    gBattleTypeFlags = BATTLE_TYPE_DUDE_TUTORIAL;
    CreateBattleStartTask(B_TRANSITION_SLICE, 0);
}

void BattleSetup_StartScriptedWildBattle(void)
{
    ScriptContext2_Enable();
    gMain.savedCallback = CB2_EndScriptedWildBattle;
    gBattleTypeFlags = 0;
    CreateBattleStartTask(GetWildBattleTransition(), 0);
    IncrementGameStat(GAME_STAT_TOTAL_BATTLES);
    IncrementGameStat(GAME_STAT_WILD_BATTLES);
    IncrementDailyWildBattles();
    TryUpdateGymLeaderRematchFromWild();
}

void BattleSetup_StartLatiBattle(void)
{
    ScriptContext2_Enable();
    gMain.savedCallback = CB2_EndScriptedWildBattle;
    gBattleTypeFlags = BATTLE_TYPE_LEGENDARY;
    CreateBattleStartTask(GetWildBattleTransition(), 0);
    IncrementGameStat(GAME_STAT_TOTAL_BATTLES);
    IncrementGameStat(GAME_STAT_WILD_BATTLES);
    IncrementDailyWildBattles();
    TryUpdateGymLeaderRematchFromWild();
}

void BattleSetup_StartLegendaryBattle(void)
{
    ScriptContext2_Enable();
    gMain.savedCallback = CB2_EndScriptedWildBattle;
    gBattleTypeFlags = BATTLE_TYPE_LEGENDARY;

    switch (GetMonData(&gEnemyParty[0], MON_DATA_SPECIES, NULL))
    {
    default:
    case SPECIES_GROUDON:
        //gBattleTypeFlags |= BATTLE_TYPE_GROUDON;
        CreateBattleStartTask(B_TRANSITION_GROUDON, MUS_VS_KYOGRE_GROUDON);
        break;
    case SPECIES_KYOGRE:
        //gBattleTypeFlags |= BATTLE_TYPE_KYOGRE;
        CreateBattleStartTask(B_TRANSITION_KYOGRE, MUS_VS_KYOGRE_GROUDON);
        break;
    case SPECIES_RAYQUAZA:
        gBattleTypeFlags |= BATTLE_TYPE_RAYQUAZA;
        CreateBattleStartTask(B_TRANSITION_RAYQUAZA, MUS_VS_RAYQUAZA);
        break;
    case SPECIES_DEOXYS:
        CreateBattleStartTask(B_TRANSITION_BLUR, MUS_RG_VS_DEOXYS);
        break;
    case SPECIES_LUGIA:
    case SPECIES_HO_OH:
        CreateBattleStartTask(B_TRANSITION_BLUR, MUS_RG_VS_LEGEND);
        break;
    case SPECIES_MEW:
        CreateBattleStartTask(B_TRANSITION_GRID_SQUARES, MUS_VS_MEW);
        break;
    }

    IncrementGameStat(GAME_STAT_TOTAL_BATTLES);
    IncrementGameStat(GAME_STAT_WILD_BATTLES);
    IncrementDailyWildBattles();
    TryUpdateGymLeaderRematchFromWild();
}

void StartRegiBattle(void)
{
    u8 transitionId;
    u16 species;

    ScriptContext2_Enable();
    gMain.savedCallback = CB2_EndScriptedWildBattle;
    gBattleTypeFlags = BATTLE_TYPE_LEGENDARY | BATTLE_TYPE_REGI;

    species = GetMonData(&gEnemyParty[0], MON_DATA_SPECIES);
    switch (species)
    {
    case SPECIES_REGIROCK:
        transitionId = B_TRANSITION_REGIROCK;
        break;
    case SPECIES_REGICE:
        transitionId = B_TRANSITION_REGICE;
        break;
    case SPECIES_REGISTEEL:
        transitionId = B_TRANSITION_REGISTEEL;
        break;
    default:
        transitionId = B_TRANSITION_GRID_SQUARES;
        break;
    }
    CreateBattleStartTask(transitionId, MUS_VS_REGI);

    IncrementGameStat(GAME_STAT_TOTAL_BATTLES);
    IncrementGameStat(GAME_STAT_WILD_BATTLES);
    IncrementDailyWildBattles();
    TryUpdateGymLeaderRematchFromWild();
}

static void CB2_EndWildBattle(void)
{
    CpuFill16(0, (void*)(BG_PLTT), BG_PLTT_SIZE);
    ResetOamRange(0, 128);

    if (IsPlayerDefeated(gBattleOutcome) == TRUE && !InBattlePyramid() && !InBattlePike())
    {
        SetMainCallback2(CB2_WhiteOut);
    }
    else
    {
        SetMainCallback2(CB2_ReturnToField);
        gFieldCallback = sub_80AF6F0;
    }
}

static void CB2_EndScriptedWildBattle(void)
{
    CpuFill16(0, (void*)(BG_PLTT), BG_PLTT_SIZE);
    ResetOamRange(0, 128);

    if (IsPlayerDefeated(gBattleOutcome) == TRUE)
    {
        if (InBattlePyramid())
            SetMainCallback2(CB2_ReturnToFieldContinueScriptPlayMapMusic);
        else
            SetMainCallback2(CB2_WhiteOut);
    }
    else
    {
        SetMainCallback2(CB2_ReturnToFieldContinueScriptPlayMapMusic);
    }
}

u8 BattleSetup_GetTerrainId(void)
{
    u16 tileBehavior;
    s16 x, y;

    PlayerGetDestCoords(&x, &y);
    tileBehavior = MapGridGetMetatileBehaviorAt(x, y);

    if (MetatileBehavior_IsTallGrass(tileBehavior))
        return BATTLE_TERRAIN_GRASS;
    if (MetatileBehavior_IsAnyLongGrass(tileBehavior))
        return BATTLE_TERRAIN_LONG_GRASS;
    if (MetatileBehavior_IsSandOrDeepSand(tileBehavior))
        return BATTLE_TERRAIN_SAND;

    switch (gMapHeader.mapType)
    {
    case MAP_TYPE_TOWN:
    case MAP_TYPE_CITY:
    case MAP_TYPE_ROUTE:
        break;
    case MAP_TYPE_UNDERGROUND:
        if (MetatileBehavior_IsIndoorEncounter(tileBehavior))
            return BATTLE_TERRAIN_BUILDING;
        if (MetatileBehavior_IsSurfableWaterOrUnderwater(tileBehavior))
            return BATTLE_TERRAIN_POND;
        return BATTLE_TERRAIN_CAVE;
    case MAP_TYPE_INDOOR:
    case MAP_TYPE_SECRET_BASE:
        return BATTLE_TERRAIN_BUILDING;
    case MAP_TYPE_UNDERWATER:
        return BATTLE_TERRAIN_UNDERWATER;
    case MAP_TYPE_OCEAN_ROUTE:
        if (MetatileBehavior_IsSurfableWaterOrUnderwater(tileBehavior))
            return BATTLE_TERRAIN_WATER;
        return BATTLE_TERRAIN_PLAIN;
    }
    if (MetatileBehavior_IsDeepOrOceanWater(tileBehavior))
        return BATTLE_TERRAIN_WATER;
    if (MetatileBehavior_IsSurfableWaterOrUnderwater(tileBehavior))
        return BATTLE_TERRAIN_POND;
    if (MetatileBehavior_IsMountain(tileBehavior))
        return BATTLE_TERRAIN_MOUNTAIN;
    if (TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_SURFING))
    {
        if (MetatileBehavior_GetBridgeType(tileBehavior))
            return BATTLE_TERRAIN_POND;
        if (MetatileBehavior_IsBridge(tileBehavior) == TRUE)
            return BATTLE_TERRAIN_WATER;
    }
    /*if (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(ROUTE113) && gSaveBlock1Ptr->location.mapNum == MAP_NUM(ROUTE113))
        return BATTLE_TERRAIN_SAND;*/
    if (GetSav1Weather() == WEATHER_SANDSTORM)
        return BATTLE_TERRAIN_SAND;

    return BATTLE_TERRAIN_PLAIN;
}

static u8 GetBattleTransitionTypeByMap(void)
{
    u16 tileBehavior;
    s16 x, y;

    PlayerGetDestCoords(&x, &y);
    tileBehavior = MapGridGetMetatileBehaviorAt(x, y);
    if (Overworld_GetFlashLevel())
        return B_TRANSITION_SHUFFLE;
    if (!MetatileBehavior_IsSurfableWaterOrUnderwater(tileBehavior))
    {
        switch (gMapHeader.mapType)
        {
        case MAP_TYPE_UNDERGROUND:
            return B_TRANSITION_SWIRL;
        case MAP_TYPE_UNDERWATER:
            return B_TRANSITION_BIG_POKEBALL;
        default:
            return B_TRANSITION_BLUR;
        }
    }
    return B_TRANSITION_BIG_POKEBALL;
}

static u16 GetSumOfPlayerPartyLevel(u8 numMons)
{
    u8 sum = 0;
    int i;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        u32 species = GetMonData(&gPlayerParty[i], MON_DATA_SPECIES2);

        if (species != SPECIES_EGG && species != SPECIES_NONE && GetMonData(&gPlayerParty[i], MON_DATA_HP) != 0)
        {
            sum += GetMonData(&gPlayerParty[i], MON_DATA_LEVEL);
            if (--numMons == 0)
                break;
        }
    }
    return sum;
}

static u8 GetSumOfEnemyPartyLevel(u16 opponentId, u8 numMons)
{
    u8 i;
    u8 sum;
    u32 count = numMons;

    if (gTrainers[opponentId].partySize < count)
        count = gTrainers[opponentId].partySize;

    sum = 0;

    switch (gTrainers[opponentId].partyFlags)
    {
    case 0:
        {
            const struct TrainerMonNoItemDefaultMoves *party;
            party = gTrainers[opponentId].party.NoItemDefaultMoves;
            for (i = 0; i < count; i++)
                sum += party[i].lvl;
        }
        break;
    case F_TRAINER_PARTY_CUSTOM_MOVESET:
        {
            const struct TrainerMonNoItemCustomMoves *party;
            party = gTrainers[opponentId].party.NoItemCustomMoves;
            for (i = 0; i < count; i++)
                sum += party[i].lvl;
        }
        break;
    case F_TRAINER_PARTY_HELD_ITEM:
        {
            const struct TrainerMonItemDefaultMoves *party;
            party = gTrainers[opponentId].party.ItemDefaultMoves;
            for (i = 0; i < count; i++)
                sum += party[i].lvl;
        }
        break;
    case F_TRAINER_PARTY_CUSTOM_MOVESET | F_TRAINER_PARTY_HELD_ITEM:
        {
            const struct TrainerMonItemCustomMoves *party;
            party = gTrainers[opponentId].party.ItemCustomMoves;
            for (i = 0; i < count; i++)
                sum += party[i].lvl;
        }
        break;
    }

    return sum;
}

static u8 GetWildBattleTransition(void)
{
    u8 transitionType = GetBattleTransitionTypeByMap();
    u8 enemyLevel = GetMonData(&gEnemyParty[0], MON_DATA_LEVEL);
    u8 playerLevel = GetSumOfPlayerPartyLevel(1);

    if (enemyLevel < playerLevel)
    {
        if (InBattlePyramid())
            return B_TRANSITION_BLUR;
        else
            return sBattleTransitionTable_Wild[transitionType][0];
    }
    else
    {
        if (InBattlePyramid())
            return B_TRANSITION_GRID_SQUARES;
        else
            return sBattleTransitionTable_Wild[transitionType][1];
    }
}

static u8 GetTrainerBattleTransition(void)
{
    u8 minPartyCount;
    u8 transitionType;
    u8 enemyLevel;
    u8 playerLevel;

    if (gTrainerBattleOpponent_A == TRAINER_SECRET_BASE)
        return B_TRANSITION_CHAMPION;

    if (gTrainers[gTrainerBattleOpponent_A].trainerClass == TRAINER_CLASS_ELITE_FOUR)
    {
        if (gTrainerBattleOpponent_A == TRAINER_SIDNEY)
            return B_TRANSITION_SIDNEY;
        if (gTrainerBattleOpponent_A == TRAINER_PHOEBE)
            return B_TRANSITION_PHOEBE;
        if (gTrainerBattleOpponent_A == TRAINER_GLACIA)
            return B_TRANSITION_GLACIA;
        if (gTrainerBattleOpponent_A == TRAINER_DRAKE)
            return B_TRANSITION_DRAKE;
        return B_TRANSITION_CHAMPION;
    }

    if (gTrainers[gTrainerBattleOpponent_A].trainerClass == TRAINER_CLASS_CHAMPION)
        return B_TRANSITION_CHAMPION;

    /*if (gTrainers[gTrainerBattleOpponent_A].trainerClass == TRAINER_CLASS_SUPER_NERD
        || gTrainers[gTrainerBattleOpponent_A].trainerClass == TRAINER_CLASS_MAGMA_LEADER
        || gTrainers[gTrainerBattleOpponent_A].trainerClass == TRAINER_CLASS_MAGMA_ADMIN)
        return B_TRANSITION_MAGMA;*/

    if (gTrainers[gTrainerBattleOpponent_A].trainerClass == TRAINER_CLASS_TEAM_ROCKET
        || gTrainers[gTrainerBattleOpponent_A].trainerClass == TRAINER_CLASS_AQUA_LEADER
        || gTrainers[gTrainerBattleOpponent_A].trainerClass == TRAINER_CLASS_AQUA_ADMIN)
        return B_TRANSITION_ROCKET;

    if (gTrainers[gTrainerBattleOpponent_A].doubleBattle == TRUE)
        minPartyCount = 2; // double battles always at least have 2 pokemon.
    else
        minPartyCount = 1;

    transitionType = GetBattleTransitionTypeByMap();
    enemyLevel = GetSumOfEnemyPartyLevel(gTrainerBattleOpponent_A, minPartyCount);
    playerLevel = GetSumOfPlayerPartyLevel(minPartyCount);

    if (enemyLevel < playerLevel)
        return sBattleTransitionTable_Trainer[transitionType][0];
    else
        return sBattleTransitionTable_Trainer[transitionType][1];
}

// 0: Battle Tower
// 3: Battle Dome
// 4: Battle Palace
// 5: Battle Arena
// 6: Battle Factory
// 7: Battle Pike
// 10: Battle Pyramid
// 11: Trainer Hill
// 12: Secret Base
// 13: E-Reader
u8 GetSpecialBattleTransition(s32 id)
{
    u16 var;
    u8 enemyLevel = GetMonData(&gEnemyParty[0], MON_DATA_LEVEL);
    u8 playerLevel = GetSumOfPlayerPartyLevel(1);

    if (enemyLevel < playerLevel)
    {
        switch (id)
        {
        case 11:
        case 12:
        case 13:
            return B_TRANSITION_POKEBALLS_TRAIL;
        case 10:
            return sBattleTransitionTable_BattlePyramid[Random() % ARRAY_COUNT(sBattleTransitionTable_BattlePyramid)];
        case 3:
            return sBattleTransitionTable_BattleDome[Random() % ARRAY_COUNT(sBattleTransitionTable_BattleDome)];
        }

        if (VarGet(VAR_FRONTIER_BATTLE_MODE) != FRONTIER_MODE_LINK_MULTIS)
            return sBattleTransitionTable_BattleFrontier[Random() % ARRAY_COUNT(sBattleTransitionTable_BattleFrontier)];
    }
    else
    {
        switch (id)
        {
        case 11:
        case 12:
        case 13:
            return B_TRANSITION_BIG_POKEBALL;
        case 10:
            return sBattleTransitionTable_BattlePyramid[Random() % ARRAY_COUNT(sBattleTransitionTable_BattlePyramid)];
        case 3:
            return sBattleTransitionTable_BattleDome[Random() % ARRAY_COUNT(sBattleTransitionTable_BattleDome)];
        }

        if (VarGet(VAR_FRONTIER_BATTLE_MODE) != FRONTIER_MODE_LINK_MULTIS)
            return sBattleTransitionTable_BattleFrontier[Random() % ARRAY_COUNT(sBattleTransitionTable_BattleFrontier)];
    }

    var = gSaveBlock2Ptr->frontier.trainerIds[gSaveBlock2Ptr->frontier.curChallengeBattleNum * 2 + 0]
        + gSaveBlock2Ptr->frontier.trainerIds[gSaveBlock2Ptr->frontier.curChallengeBattleNum * 2 + 1];

    return sBattleTransitionTable_BattleFrontier[var % ARRAY_COUNT(sBattleTransitionTable_BattleFrontier)];
}

void ChooseStarter(void)
{
    SetMainCallback2(CB2_ChooseStarter);
    gMain.savedCallback = CB2_GiveStarter;
}

static void CB2_GiveStarter(void)
{
    u16 starterMon;

    *GetVarPointer(VAR_STARTER_MON) = gSpecialVar_Result;
    starterMon = GetStarterPokemon(gSpecialVar_Result);
    ScriptGiveMon(starterMon, 5, ITEM_NONE, 0, 0, 0);
    ResetTasks();
    PlayBattleBGM();
    SetMainCallback2(CB2_StartFirstBattle);
    BattleTransition_Start(B_TRANSITION_BLUR);
}

static void CB2_StartFirstBattle(void)
{
    UpdatePaletteFade();
    RunTasks();

    if (IsBattleTransitionDone() == TRUE)
    {
        gBattleTypeFlags = BATTLE_TYPE_FIRST_BATTLE;
        gMain.savedCallback = CB2_EndFirstBattle;
        FreeAllWindowBuffers();
        SetMainCallback2(CB2_InitBattle);
        RestartWildEncounterImmunitySteps();
        ClearPoisonStepCounter();
        IncrementGameStat(GAME_STAT_TOTAL_BATTLES);
        IncrementGameStat(GAME_STAT_WILD_BATTLES);
        IncrementDailyWildBattles();
        TryUpdateGymLeaderRematchFromWild();
    }
}

static void CB2_EndFirstBattle(void)
{
    Overworld_ClearSavedMusic();
    SetMainCallback2(CB2_ReturnToFieldContinueScriptPlayMapMusic);
}

static void TryUpdateGymLeaderRematchFromWild(void)
{
    if (GetGameStat(GAME_STAT_WILD_BATTLES) % 60 == 0)
        UpdateGymLeaderRematch();
}

static void TryUpdateGymLeaderRematchFromTrainer(void)
{
    if (GetGameStat(GAME_STAT_TRAINER_BATTLES) % 20 == 0)
        UpdateGymLeaderRematch();
}

// why not just use the macros? maybe its because they didnt want to uncast const every time?
static u32 TrainerBattleLoadArg32(const u8 *ptr)
{
    return T1_READ_32(ptr);
}

static u16 TrainerBattleLoadArg16(const u8 *ptr)
{
    return T1_READ_16(ptr);
}

static u8 TrainerBattleLoadArg8(const u8 *ptr)
{
    return T1_READ_8(ptr);
}

static u16 GetTrainerAFlag(void)
{
    return TRAINER_FLAGS_START + gTrainerBattleOpponent_A;
}

static u16 GetTrainerBFlag(void)
{
    return TRAINER_FLAGS_START + gTrainerBattleOpponent_B;
}

bool32 IsPlayerDefeated(u32 battleOutcome)
{
    switch (battleOutcome)
    {
    case B_OUTCOME_LOST:
    case B_OUTCOME_DREW:
        return TRUE;
    case B_OUTCOME_WON:
    case B_OUTCOME_RAN:
    case B_OUTCOME_PLAYER_TELEPORTED:
    case B_OUTCOME_MON_FLED:
    case B_OUTCOME_CAUGHT:
        return FALSE;
    default:
        return FALSE;
    }
}

void ResetTrainerOpponentIds(void)
{
    gTrainerBattleOpponent_A = 0;
    gTrainerBattleOpponent_B = 0;
}

static void InitTrainerBattleVariables(void)
{
    sTrainerBattleMode = 0;
    if (gApproachingTrainerId == 0)
    {
        sTrainerAIntroSpeech = NULL;
        sTrainerADefeatSpeech = NULL;
        sTrainerABattleScriptRetAddr = NULL;
    }
    else
    {
        sTrainerBIntroSpeech = NULL;
        sTrainerBDefeatSpeech = NULL;
        sTrainerBBattleScriptRetAddr = NULL;
    }
    sTrainerObjectEventLocalId = 0;
    sTrainerVictorySpeech = NULL;
    sTrainerCannotBattleSpeech = NULL;
    sTrainerBattleEndScript = NULL;
    sFirstBattleTutorialMode = 0;
}

static inline void SetU8(void *ptr, u8 value)
{
    *(u8*)(ptr) = value;
}

static inline void SetU16(void *ptr, u16 value)
{
    *(u16*)(ptr) = value;
}

static inline void SetU32(void *ptr, u32 value)
{
    *(u32*)(ptr) = value;
}

static inline void SetPtr(const void *ptr, const void* value)
{
    *(const void**)(ptr) = value;
}

static void TrainerBattleLoadArgs(const struct TrainerBattleParameter *specs, const u8 *data)
{
    while (1)
    {
        switch (specs->ptrType)
        {
        case TRAINER_PARAM_LOAD_VAL_8BIT:
            SetU8(specs->varPtr, TrainerBattleLoadArg8(data));
            data += 1;
            break;
        case TRAINER_PARAM_LOAD_VAL_16BIT:
            SetU16(specs->varPtr, TrainerBattleLoadArg16(data));
            data += 2;
            break;
        case TRAINER_PARAM_LOAD_VAL_32BIT:
            SetU32(specs->varPtr, TrainerBattleLoadArg32(data));
            data += 4;
            break;
        case TRAINER_PARAM_CLEAR_VAL_8BIT:
            SetU8(specs->varPtr, 0);
            break;
        case TRAINER_PARAM_CLEAR_VAL_16BIT:
            SetU16(specs->varPtr, 0);
            break;
        case TRAINER_PARAM_CLEAR_VAL_32BIT:
            SetU32(specs->varPtr, 0);
            break;
        case TRAINER_PARAM_LOAD_SCRIPT_RET_ADDR:
            SetPtr(specs->varPtr, data);
            return;
        }
        specs++;
    }
}

void SetMapVarsToTrainer(void)
{
    if (sTrainerObjectEventLocalId != 0)
    {
        gSpecialVar_LastTalked = sTrainerObjectEventLocalId;
        gSelectedObjectEvent = GetObjectEventIdByLocalIdAndMap(sTrainerObjectEventLocalId, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup);
    }
}

const u8 *BattleSetup_ConfigureTrainerBattle(const u8 *data)
{
    InitTrainerBattleVariables();
    sTrainerBattleMode = TrainerBattleLoadArg8(data);

    switch (sTrainerBattleMode)
    {
    case TRAINER_BATTLE_SINGLE_NO_INTRO_TEXT:
        TrainerBattleLoadArgs(sOrdinaryNoIntroBattleParams, data);
        return EventScript_DoNoIntroTrainerBattle;
    case TRAINER_BATTLE_DOUBLE:
        TrainerBattleLoadArgs(sDoubleBattleParams, data);
        SetMapVarsToTrainer();
        return EventScript_TryDoDoubleTrainerBattle;
    case TRAINER_BATTLE_CONTINUE_SCRIPT:
        if (gApproachingTrainerId == 0)
        {
            TrainerBattleLoadArgs(sContinueScriptBattleParams, data);
            SetMapVarsToTrainer();
        }
        else
        {
            TrainerBattleLoadArgs(sTrainerBContinueScriptBattleParams, data);
        }
        return EventScript_TryDoNormalTrainerBattle;
    case TRAINER_BATTLE_CONTINUE_SCRIPT_NO_MUSIC:
        TrainerBattleLoadArgs(sContinueScriptBattleParams, data);
        SetMapVarsToTrainer();
        return EventScript_TryDoNormalTrainerBattle;
    case TRAINER_BATTLE_CONTINUE_SCRIPT_DOUBLE:
    case TRAINER_BATTLE_CONTINUE_SCRIPT_DOUBLE_NO_MUSIC:
        TrainerBattleLoadArgs(sContinueScriptDoubleBattleParams, data);
        SetMapVarsToTrainer();
        return EventScript_TryDoDoubleTrainerBattle;
    case TRAINER_BATTLE_REMATCH_DOUBLE:
        TrainerBattleLoadArgs(sDoubleBattleParams, data);
        SetMapVarsToTrainer();
        gTrainerBattleOpponent_A = GetRematchTrainerId(gTrainerBattleOpponent_A);
        return EventScript_TryDoDoubleRematchBattle;
    case TRAINER_BATTLE_REMATCH:
        TrainerBattleLoadArgs(sOrdinaryBattleParams, data);
        SetMapVarsToTrainer();
        gTrainerBattleOpponent_A = GetRematchTrainerId(gTrainerBattleOpponent_A);
        return EventScript_TryDoRematchBattle;
    case TRAINER_BATTLE_PYRAMID:
        if (gApproachingTrainerId == 0)
        {
            TrainerBattleLoadArgs(sOrdinaryBattleParams, data);
            SetMapVarsToTrainer();
            gTrainerBattleOpponent_A = LocalIdToPyramidTrainerId(gSpecialVar_LastTalked);
        }
        else
        {
            TrainerBattleLoadArgs(sTrainerBOrdinaryBattleParams, data);
            gTrainerBattleOpponent_B = LocalIdToPyramidTrainerId(gSpecialVar_LastTalked);
        }
        return EventScript_TryDoNormalTrainerBattle;
    case TRAINER_BATTLE_SET_TRAINER_A:
        TrainerBattleLoadArgs(sOrdinaryBattleParams, data);
        return NULL;
    case TRAINER_BATTLE_SET_TRAINER_B:
        TrainerBattleLoadArgs(sTrainerBOrdinaryBattleParams, data);
        return NULL;
    case TRAINER_BATTLE_HILL:
        if (gApproachingTrainerId == 0)
        {
            TrainerBattleLoadArgs(sOrdinaryBattleParams, data);
            SetMapVarsToTrainer();
            gTrainerBattleOpponent_A = LocalIdToHillTrainerId(gSpecialVar_LastTalked);
        }
        else
        {
            TrainerBattleLoadArgs(sTrainerBOrdinaryBattleParams, data);
            gTrainerBattleOpponent_B = LocalIdToHillTrainerId(gSpecialVar_LastTalked);
        }
        return EventScript_TryDoNormalTrainerBattle;
    case TRAINER_BATTLE_CONTINUE_SCRIPT_WINTEXT:
        TrainerBattleLoadArgs(sWinLoseNoIntroBattleParams, data);
        return EventScript_DoNoIntroTrainerBattle;
    default:
        if (gApproachingTrainerId == 0)
        {
            TrainerBattleLoadArgs(sOrdinaryBattleParams, data);
            SetMapVarsToTrainer();
        }
        else
        {
            TrainerBattleLoadArgs(sTrainerBOrdinaryBattleParams, data);
        }
        return EventScript_TryDoNormalTrainerBattle;
    }
}

#if DEBUG
void Debug_StartTrainerBattle(u16 trainer)
{
    static const u8 battleText[] = _("Oh no I lost?");
    static u8 battleConfig[9] = { 0 };

    battleConfig[0] = TRAINER_BATTLE_SINGLE_NO_INTRO_TEXT;
    battleConfig[1] = trainer & 0xFF;
    battleConfig[2] = (trainer & 0xFF00) >> 8;
    battleConfig[3] = 0;
    battleConfig[4] = 0;
    battleConfig[5] = ((u32)battleText) & 0xFF;
    battleConfig[6] = (((u32)battleText) & 0xFF00) >> 8;
    battleConfig[7] = (((u32)battleText) & 0xFF0000) >> 16;
    battleConfig[8] = (((u32)battleText) & 0xFF000000) >> 24;
    BattleSetup_ConfigureTrainerBattle(battleConfig);
    BattleSetup_StartTrainerBattle();
}
#endif

void ConfigureAndSetUpOneTrainerBattle(u8 trainerObjEventId, const u8 *trainerScript)
{
    gSelectedObjectEvent = trainerObjEventId;
    gSpecialVar_LastTalked = gObjectEvents[trainerObjEventId].localId;
    BattleSetup_ConfigureTrainerBattle(trainerScript + 1);
    ScriptContext1_SetupScript(EventScript_ShowTrainerIntro);
    ScriptContext2_Enable();
}

void ConfigureTwoTrainersBattle(u8 trainerObjEventId, const u8 *trainerScript)
{
    gSelectedObjectEvent = trainerObjEventId;
    gSpecialVar_LastTalked = gObjectEvents[trainerObjEventId].localId;
    BattleSetup_ConfigureTrainerBattle(trainerScript + 1);
}

void SetUpTwoTrainersBattle(void)
{
    ScriptContext1_SetupScript(EventScript_ShowTrainerIntro);
    ScriptContext2_Enable();
}

bool32 GetTrainerFlagFromScriptPointer(const u8 *data)
{
    u32 flag = TrainerBattleLoadArg16(data + 2);
    return FlagGet(TRAINER_FLAGS_START + flag);
}

void SetUpTrainerMovement(void)
{
    struct ObjectEvent *objectEvent = &gObjectEvents[gSelectedObjectEvent];

    SetTrainerMovementType(objectEvent, GetTrainerFacingDirectionMovementType(objectEvent->facingDirection));
}

u8 GetTrainerBattleMode(void)
{
    return sTrainerBattleMode;
}

u8 GetFirstBattleTutorialMode(void)
{
    return sFirstBattleTutorialMode;
}

bool8 GetTrainerFlag(void)
{
    if (InBattlePyramid())
        return GetBattlePyramidTrainerFlag(gSelectedObjectEvent);
    else if (InTrainerHill())
        return GetHillTrainerFlag(gSelectedObjectEvent);
    else
        return FlagGet(GetTrainerAFlag());
}

static void SetBattledTrainersFlags(void)
{
    if (gTrainerBattleOpponent_B != 0)
        FlagSet(GetTrainerBFlag());
    FlagSet(GetTrainerAFlag());
}

static void SetBattledTrainerFlag(void)
{
    FlagSet(GetTrainerAFlag());
}

bool8 HasTrainerBeenFought(u16 trainerId)
{
    return FlagGet(TRAINER_FLAGS_START + trainerId);
}

void SetTrainerFlag(u16 trainerId)
{
    FlagSet(TRAINER_FLAGS_START + trainerId);
}

void ClearTrainerFlag(u16 trainerId)
{
    FlagClear(TRAINER_FLAGS_START + trainerId);
}

void BattleSetup_StartTrainerBattle(void)
{
    if (gNoOfApproachingTrainers == 2)
        gBattleTypeFlags = (BATTLE_TYPE_DOUBLE | BATTLE_TYPE_TWO_OPPONENTS | BATTLE_TYPE_TRAINER);
    else
        gBattleTypeFlags = (BATTLE_TYPE_TRAINER);

    if (InBattlePyramid())
    {
        VarSet(VAR_TEMP_E, 0);
        gBattleTypeFlags |= BATTLE_TYPE_PYRAMID;

        if (gNoOfApproachingTrainers == 2)
        {
            FillFrontierTrainersParties(1);
            ZeroMonData(&gEnemyParty[1]);
            ZeroMonData(&gEnemyParty[2]);
            ZeroMonData(&gEnemyParty[4]);
            ZeroMonData(&gEnemyParty[5]);
        }
        else
        {
            FillFrontierTrainerParty(1);
            ZeroMonData(&gEnemyParty[1]);
            ZeroMonData(&gEnemyParty[2]);
        }

        MarkApproachingPyramidTrainersAsBattled();
    }
    else if (InTrainerHillChallenge())
    {
        gBattleTypeFlags |= BATTLE_TYPE_TRAINER_HILL;

        if (gNoOfApproachingTrainers == 2)
            FillHillTrainersParties();
        else
            FillHillTrainerParty();

        SetHillTrainerFlag();
    }

    sNoOfPossibleTrainerRetScripts = gNoOfApproachingTrainers;
    gNoOfApproachingTrainers = 0;
    sShouldCheckTrainerBScript = FALSE;
    gWhichTrainerToFaceAfterBattle = 0;
    gMain.savedCallback = CB2_EndTrainerBattle;

    if (InBattlePyramid() || InTrainerHillChallenge())
        sub_80B0828();
    else
        DoTrainerBattle();

    ScriptContext1_Stop();
}

static void CB2_EndTrainerBattle(void)
{
    if (sTrainerBattleMode == TRAINER_BATTLE_CONTINUE_SCRIPT_WINTEXT)
    {
        if (IsPlayerDefeated(gBattleOutcome) == TRUE)
        {
            gSpecialVar_Result = TRUE;
            if (sFirstBattleTutorialMode & TUTORIAL_BATTLE_HEAL_AFTER)
            {
                HealPlayerParty();
                SetMainCallback2(CB2_ReturnToFieldContinueScriptPlayMapMusic);
                SetBattledTrainersFlags();
            }
            else
            {
                SetMainCallback2(CB2_WhiteOut);
            }
        }
        else
        {
            gSpecialVar_Result = FALSE;
            SetMainCallback2(CB2_ReturnToFieldContinueScriptPlayMapMusic);
            SetBattledTrainersFlags();
        }
    }
    else
    {
        if (gTrainerBattleOpponent_A == TRAINER_SECRET_BASE)
        {
            SetMainCallback2(CB2_ReturnToFieldContinueScriptPlayMapMusic);
        }
        else if (IsPlayerDefeated(gBattleOutcome) == TRUE)
        {
            if (InBattlePyramid() || InTrainerHillChallenge())
                SetMainCallback2(CB2_ReturnToFieldContinueScriptPlayMapMusic);
            else
                SetMainCallback2(CB2_WhiteOut);
        }
        else
        {
            SetMainCallback2(CB2_ReturnToFieldContinueScriptPlayMapMusic);
            if (!InBattlePyramid() && !InTrainerHillChallenge())
            {
                //RegisterTrainerInPhone();
                SetBattledTrainersFlags();
            }
        }
    }
}

static void CB2_EndRematchBattle(void)
{
    if (gTrainerBattleOpponent_A == TRAINER_SECRET_BASE)
    {
        SetMainCallback2(CB2_ReturnToFieldContinueScriptPlayMapMusic);
    }
    else if (IsPlayerDefeated(gBattleOutcome) == TRUE)
    {
        SetMainCallback2(CB2_WhiteOut);
    }
    else
    {
        SetMainCallback2(CB2_ReturnToFieldContinueScriptPlayMapMusic);
        RegisterTrainerInPhone();
        SetBattledTrainersFlags();
        HandleRematchVarsOnBattleEnd();
    }
}

void BattleSetup_StartRematchBattle(void)
{
    gBattleTypeFlags = BATTLE_TYPE_TRAINER;
    gMain.savedCallback = CB2_EndRematchBattle;
    DoTrainerBattle();
    ScriptContext1_Stop();
}

void ShowTrainerIntroSpeech(void)
{
    if (InBattlePyramid())
    {
        if (gNoOfApproachingTrainers == 0 || gNoOfApproachingTrainers == 1)
            CopyPyramidTrainerSpeechBefore(LocalIdToPyramidTrainerId(gSpecialVar_LastTalked));
        else
            CopyPyramidTrainerSpeechBefore(LocalIdToPyramidTrainerId(gObjectEvents[gApproachingTrainers[gApproachingTrainerId].objectEventId].localId));

        ShowFieldMessageFromBuffer();
    }
    else if (InTrainerHillChallenge())
    {
        if (gNoOfApproachingTrainers == 0 || gNoOfApproachingTrainers == 1)
            CopyTrainerHillTrainerText(TRAINER_HILL_TEXT_INTRO, LocalIdToHillTrainerId(gSpecialVar_LastTalked));
        else
            CopyTrainerHillTrainerText(TRAINER_HILL_TEXT_INTRO, LocalIdToHillTrainerId(gObjectEvents[gApproachingTrainers[gApproachingTrainerId].objectEventId].localId));

        ShowFieldMessageFromBuffer();
    }
    else
    {
        ShowFieldMessage(GetIntroSpeechOfApproachingTrainer());
    }
}

const u8 *BattleSetup_GetScriptAddrAfterBattle(void)
{
    if (sTrainerBattleEndScript != NULL)
        return sTrainerBattleEndScript;
    else
        return EventScript_TestSignpostMsg;
}

const u8 *BattleSetup_GetTrainerPostBattleScript(void)
{
    if (sShouldCheckTrainerBScript)
    {
        sShouldCheckTrainerBScript = FALSE;
        if (sTrainerBBattleScriptRetAddr != NULL)
        {
            gWhichTrainerToFaceAfterBattle = 1;
            return sTrainerBBattleScriptRetAddr;
        }
    }
    else
    {
        if (sTrainerABattleScriptRetAddr != NULL)
        {
            gWhichTrainerToFaceAfterBattle = 0;
            return sTrainerABattleScriptRetAddr;
        }
    }

    return EventScript_TryGetTrainerScript;
}

void ShowTrainerCantBattleSpeech(void)
{
    ShowFieldMessage(GetTrainerCantBattleSpeech());
}

void SetUpTrainerEncounterMusic(void)
{
    u16 trainerId;
    u16 music;

    if (gApproachingTrainerId == 0)
        trainerId = gTrainerBattleOpponent_A;
    else
        trainerId = gTrainerBattleOpponent_B;

    if (sTrainerBattleMode != TRAINER_BATTLE_CONTINUE_SCRIPT_NO_MUSIC
        && sTrainerBattleMode != TRAINER_BATTLE_CONTINUE_SCRIPT_DOUBLE_NO_MUSIC)
    {
        switch (GetTrainerEncounterMusicId(trainerId))
        {
        case TRAINER_ENCOUNTER_MUSIC_MALE:
            music = MUS_ENCOUNTER_MALE;
            break;
        case TRAINER_ENCOUNTER_MUSIC_FEMALE:
            music = MUS_ENCOUNTER_FEMALE;
            break;
        case TRAINER_ENCOUNTER_MUSIC_LASS:
            music = MUS_ENCOUNTER_LASS;
            break;
        case TRAINER_ENCOUNTER_MUSIC_SAGE:
            music = MUS_ENCOUNTER_SAGE;
            break;
        case TRAINER_ENCOUNTER_MUSIC_OFFICER:
            music = MUS_ENCOUNTER_OFFICER;
            break;
        case TRAINER_ENCOUNTER_MUSIC_ROCKET:
            music = MUS_ENCOUNTER_ROCKET;
            break;
        case TRAINER_ENCOUNTER_MUSIC_ELITE_FOUR:
            music = MUS_ENCOUNTER_ELITE_FOUR;
            break;
        case TRAINER_ENCOUNTER_MUSIC_FISHERMAN:
            music = MUS_ENCOUNTER_FISHERMAN;
            break;
        case TRAINER_ENCOUNTER_MUSIC_KIMONO:
            music = MUS_ENCOUNTER_KIMONO;
            break;
        default:
            music = MUS_ENCOUNTER_SUSPICIOUS;
        }
        PlayNewMapMusic(music);
    }
}

static const u8 *ReturnEmptyStringIfNull(const u8 *string)
{
    if (string == NULL)
        return gText_EmptyString2;
    else
        return string;
}

static const u8 *GetIntroSpeechOfApproachingTrainer(void)
{
    if (gApproachingTrainerId == 0)
        return ReturnEmptyStringIfNull(sTrainerAIntroSpeech);
    else
        return ReturnEmptyStringIfNull(sTrainerBIntroSpeech);
}

const u8 *GetTrainerALoseText(void)
{
    const u8 *string;

    if (gTrainerBattleOpponent_A == TRAINER_SECRET_BASE)
        string = GetSecretBaseTrainerLoseText();
    else
        string = sTrainerADefeatSpeech;

    StringExpandPlaceholders(gStringVar4, ReturnEmptyStringIfNull(string));
    return gStringVar4;
}

const u8 *GetTrainerBLoseText(void)
{
    StringExpandPlaceholders(gStringVar4, ReturnEmptyStringIfNull(sTrainerBDefeatSpeech));
    return gStringVar4;
}

const u8 *GetTrainerWonSpeech(void)
{
    StringExpandPlaceholders(gStringVar4, ReturnEmptyStringIfNull(sTrainerVictorySpeech));
    return gStringVar4;
}

static const u8 *GetTrainerCantBattleSpeech(void)
{
    return ReturnEmptyStringIfNull(sTrainerCannotBattleSpeech);
}

static s32 FirstBattleTrainerIdToRematchTableId(const struct RematchTrainer *table, u16 trainerId)
{
    s32 i;

    for (i = 0; i < REMATCH_TABLE_ENTRIES; i++)
    {
        if (table[i].trainerIds[0] == trainerId)
            return i;
    }

    return -1;
}

static s32 TrainerIdToRematchTableId(const struct RematchTrainer *table, u16 trainerId)
{
    s32 i, j;

    for (i = 0; i < REMATCH_TABLE_ENTRIES; i++)
    {
        for (j = 0; j < REMATCHES_COUNT; j++)
        {
            if (table[i].trainerIds[j] == 0)
                break;
            if (table[i].trainerIds[j] == trainerId)
                return i;
        }
    }

    return -1;
}

static bool32 sub_80B1D94(s32 rematchTableId)
{
    if (rematchTableId >= REMATCH_SIDNEY)
        return TRUE;
    else if (rematchTableId == REMATCH_WALLY_3)
        return (FlagGet(FLAG_MET_FRIEDA_OF_FRIDAY) == FALSE);
    else
        return FALSE;
}

static void SetRematchIdForTrainer(const struct RematchTrainer *table, u32 tableId)
{
    s32 i;

    for (i = 1; i < REMATCHES_COUNT; i++)
    {
        u16 trainerId = table[tableId].trainerIds[i];

        if (trainerId == 0)
            break;
        if (!HasTrainerBeenFought(trainerId))
            break;
    }

    gSaveBlock1Ptr->trainerRematches[tableId] = i;
}

static bool32 UpdateRandomTrainerRematches(const struct RematchTrainer *table, u16 mapGroup, u16 mapNum)
{
    s32 i;
    bool32 ret = FALSE;

    for (i = 0; i <= REMATCH_SPECIAL_TRAINER_START; i++)
    {
        if (table[i].mapGroup == mapGroup && table[i].mapNum == mapNum && !sub_80B1D94(i))
        {
            if (gSaveBlock1Ptr->trainerRematches[i] != 0)
            {
                // Trainer already wants a rematch. Don't bother updating it.
                ret = TRUE;
            }
            else if (FlagGet(gPhoneContacts[table[i].phoneContactId].registeredFlag)
             && (Random() % 100) <= 30)  // 31% chance of getting a rematch.
            {
                SetRematchIdForTrainer(table, i);
                ret = TRUE;
            }
        }
    }

    return ret;
}

void UpdateRematchIfDefeated(s32 rematchTableId)
{
    if (HasTrainerBeenFought(gRematchTable[rematchTableId].trainerIds[0]) == TRUE)
        SetRematchIdForTrainer(gRematchTable, rematchTableId);
}

static bool32 DoesSomeoneWantRematchIn_(const struct RematchTrainer *table, u16 mapGroup, u16 mapNum)
{
    s32 i;

    for (i = 0; i < REMATCH_TABLE_ENTRIES; i++)
    {
        if (table[i].mapGroup == mapGroup && table[i].mapNum == mapNum && gSaveBlock1Ptr->trainerRematches[i] != 0)
            return TRUE;
    }

    return FALSE;
}

static bool32 IsRematchTrainerIn_(const struct RematchTrainer *table, u16 mapGroup, u16 mapNum)
{
    s32 i;

    for (i = 0; i < REMATCH_TABLE_ENTRIES; i++)
    {
        if (table[i].mapGroup == mapGroup && table[i].mapNum == mapNum)
            return TRUE;
    }

    return FALSE;
}

static bool8 IsFirstTrainerIdReadyForRematch(const struct RematchTrainer *table, u16 firstBattleTrainerId)
{
    s32 tableId = FirstBattleTrainerIdToRematchTableId(table, firstBattleTrainerId);

    if (tableId == -1)
        return FALSE;
    if (tableId >= MAX_REMATCH_ENTRIES)
        return FALSE;
    if (gSaveBlock1Ptr->trainerRematches[tableId] == 0)
        return FALSE;

    return TRUE;
}

static bool8 IsTrainerReadyForRematch_(const struct RematchTrainer *table, u16 trainerId)
{
    s32 tableId = TrainerIdToRematchTableId(table, trainerId);

    if (tableId == -1)
        return FALSE;
    if (tableId >= MAX_REMATCH_ENTRIES)
        return FALSE;
    if (gSaveBlock1Ptr->trainerRematches[tableId] == 0)
        return FALSE;

    return TRUE;
}

static u16 GetRematchTrainerIdFromTable(const struct RematchTrainer *table, u16 firstBattleTrainerId)
{
    const struct RematchTrainer *trainerEntry;
    s32 i;
    s32 tableId = FirstBattleTrainerIdToRematchTableId(table, firstBattleTrainerId);

    if (tableId == -1)
        return FALSE;

    trainerEntry = &table[tableId];
    for (i = 1; i < REMATCHES_COUNT; i++)
    {
        if (trainerEntry->trainerIds[i] == 0) // previous entry was this trainer's last one
            return trainerEntry->trainerIds[i - 1];
        if (!HasTrainerBeenFought(trainerEntry->trainerIds[i]))
            return trainerEntry->trainerIds[i];
    }

    return trainerEntry->trainerIds[REMATCHES_COUNT - 1]; // already beaten at max stage
}

static u16 GetLastBeatenRematchTrainerIdFromTable(const struct RematchTrainer *table, u16 firstBattleTrainerId)
{
    const struct RematchTrainer *trainerEntry;
    s32 i;
    s32 tableId = FirstBattleTrainerIdToRematchTableId(table, firstBattleTrainerId);

    if (tableId == -1)
        return FALSE;

    trainerEntry = &table[tableId];
    for (i = 1; i < REMATCHES_COUNT; i++)
    {
        if (trainerEntry->trainerIds[i] == 0) // previous entry was this trainer's last one
            return trainerEntry->trainerIds[i - 1];
        if (!HasTrainerBeenFought(trainerEntry->trainerIds[i]))
            return trainerEntry->trainerIds[i - 1];
    }

    return trainerEntry->trainerIds[REMATCHES_COUNT - 1]; // already beaten at max stage
}

static void ClearTrainerWantRematchState(const struct RematchTrainer *table, u16 firstBattleTrainerId)
{
    s32 tableId = TrainerIdToRematchTableId(table, firstBattleTrainerId);

    if (tableId != -1)
        gSaveBlock1Ptr->trainerRematches[tableId] = 0;
}

static u32 GetTrainerPhoneContactFlag(u32 trainerId)
{
    s32 i;

    for (i = 0; i < REMATCH_TABLE_ENTRIES; i++)
    {
        if (gRematchTable[i].trainerIds[0] == trainerId)
            return gPhoneContacts[gRematchTable[i].phoneContactId].registeredFlag;
    }

    return 0xFFFF;
}

static void RegisterTrainerInPhone(void)
{
    u32 matchCallFlagId = GetTrainerPhoneContactFlag(gTrainerBattleOpponent_A);
    if (matchCallFlagId != 0xFFFF)
        FlagSet(matchCallFlagId);
}

static bool8 WasSecondRematchWon(const struct RematchTrainer *table, u16 firstBattleTrainerId)
{
    s32 tableId = FirstBattleTrainerIdToRematchTableId(table, firstBattleTrainerId);

    if (tableId == -1)
        return FALSE;
    if (!HasTrainerBeenFought(table[tableId].trainerIds[1]))
        return FALSE;

    return TRUE;
}

static bool32 HasAtLeastFiveBadges(void)
{
    s32 i, count;

    for (count = 0, i = 0; i < ARRAY_COUNT(sBadgeFlags); i++)
    {
        if (FlagGet(sBadgeFlags[i]) == TRUE)
        {
            if (++count >= 5)
                return TRUE;
        }
    }

    return FALSE;
}

#define STEP_COUNTER_MAX 255

void IncrementRematchStepCounter(void)
{
    if (HasAtLeastFiveBadges())
    {
        if (gSaveBlock1Ptr->trainerRematchStepCounter >= STEP_COUNTER_MAX)
            gSaveBlock1Ptr->trainerRematchStepCounter = STEP_COUNTER_MAX;
        else
            gSaveBlock1Ptr->trainerRematchStepCounter++;
    }
}

static bool32 IsRematchStepCounterMaxed(void)
{
    if (HasAtLeastFiveBadges() && gSaveBlock1Ptr->trainerRematchStepCounter >= STEP_COUNTER_MAX)
        return TRUE;
    else
        return FALSE;
}

void TryUpdateRandomTrainerRematches(u16 mapGroup, u16 mapNum)
{
    if (IsRematchStepCounterMaxed() && UpdateRandomTrainerRematches(gRematchTable, mapGroup, mapNum) == TRUE)
        gSaveBlock1Ptr->trainerRematchStepCounter = 0;
}

bool32 DoesSomeoneWantRematchIn(u16 mapGroup, u16 mapNum)
{
    return DoesSomeoneWantRematchIn_(gRematchTable, mapGroup, mapNum);
}

bool32 IsRematchTrainerIn(u16 mapGroup, u16 mapNum)
{
    return IsRematchTrainerIn_(gRematchTable, mapGroup, mapNum);
}

static u16 GetRematchTrainerId(u16 trainerId)
{
    return GetRematchTrainerIdFromTable(gRematchTable, trainerId);
}

u16 GetLastBeatenRematchTrainerId(u16 trainerId)
{
    return GetLastBeatenRematchTrainerIdFromTable(gRematchTable, trainerId);
}

bool8 ShouldTryRematchBattle(void)
{
    if (IsFirstTrainerIdReadyForRematch(gRematchTable, gTrainerBattleOpponent_A))
        return TRUE;

    return WasSecondRematchWon(gRematchTable, gTrainerBattleOpponent_A);
}

bool8 IsTrainerReadyForRematch(void)
{
    return IsTrainerReadyForRematch_(gRematchTable, gTrainerBattleOpponent_A);
}

static void HandleRematchVarsOnBattleEnd(void)
{
    ClearTrainerWantRematchState(gRematchTable, gTrainerBattleOpponent_A);
    SetBattledTrainersFlags();
}

void ShouldTryGetTrainerScript(void)
{
    if (sNoOfPossibleTrainerRetScripts > 1)
    {
        sNoOfPossibleTrainerRetScripts = 0;
        sShouldCheckTrainerBScript = TRUE;
        gSpecialVar_Result = TRUE;
    }
    else
    {
        sShouldCheckTrainerBScript = FALSE;
        gSpecialVar_Result = FALSE;
    }
}

u16 CountBattledRematchTeams(u16 trainerId)
{
    s32 i;

    if (HasTrainerBeenFought(gRematchTable[trainerId].trainerIds[0]) != TRUE)
        return 0;

    for (i = 1; i < REMATCHES_COUNT; i++)
    {
        if (gRematchTable[trainerId].trainerIds[i] == 0)
            break;
        if (!HasTrainerBeenFought(gRematchTable[trainerId].trainerIds[i]))
            break;
    }

    return i;
}
