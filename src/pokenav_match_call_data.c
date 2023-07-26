#include "global.h"
#include "battle_setup.h"
#include "data.h"
#include "event_data.h"
#include "phone_contact.h"
#include "string_util.h"
#include "battle.h"
#include "gym_leader_rematch.h"
#include "match_call.h"
#include "pokenav.h"
#include "strings.h"
#include "constants/region_map_sections.h"
#include "constants/trainers.h"


// NPC below means non-trainer character (no rematch or check page)
// Steven also uses this type but has a check page by using a MatchCallCheckPageOverride
enum
{
    MC_TYPE_NPC,
    MC_TYPE_TRAINER,
    MC_TYPE_WALLY,
    MC_TYPE_BIRCH,
    MC_TYPE_RIVAL,
    MC_TYPE_LEADER
};

// Static type declarations

typedef struct MatchCallTextDataStruct {
    const u8 *text;
    u16 flag;
    u16 flag2;
} match_call_text_data_t;

struct MatchCallStructCommon {
    u8 type;
    u8 mapSec;
    u16 flag;
};

struct MatchCallStructNPC {
    u8 type;
    u8 mapSec;
    u16 flag;
    const u8 *desc;
    const u8 *name;
    const match_call_text_data_t *textData;
};

// Shared by MC_TYPE_TRAINER and MC_TYPE_LEADER
struct MatchCallStructTrainer {
    u8 type;
    u8 mapSec;
    u16 flag;
    u16 rematchTableIdx;
    const u8 *desc;
    const u8 *name;
    const match_call_text_data_t *textData;
};

struct MatchCallLocationOverride {
    u16 flag;
    u8 mapSec;
};

struct MatchCallWally {
    u8 type;
    u8 mapSec;
    u16 flag;
    u16 rematchTableIdx;
    const u8 *desc;
    const match_call_text_data_t *textData;
    const struct MatchCallLocationOverride *locationData;
};

struct MatchCallBirch {
    u8 type;
    u8 mapSec;
    u16 flag;
    const u8 *desc;
    const u8 *name;
};

struct MatchCallRival {
    u8 type;
    u8 playerGender;
    u16 flag;
    const u8 *desc;
    const u8 *name;
    const match_call_text_data_t *textData;
};

typedef union {
    const struct MatchCallStructCommon *common;
    const struct MatchCallStructNPC *npc;
    const struct MatchCallStructTrainer *trainer;
    const struct MatchCallWally *wally;
    const struct MatchCallBirch *birch;
    const struct MatchCallRival *rival;
    const struct MatchCallStructTrainer *leader;
} match_call_t;

struct MatchCallCheckPageOverride {
    u16 idx;
    u16 facilityClass;
    u32 flag;
    const u8 *flavorTexts[CHECK_PAGE_ENTRY_COUNT];
};

static void sub_81D1920(const match_call_text_data_t *, u8 *);
static void sub_81D199C(const match_call_text_data_t *, u16, u8 *);
static void MatchCall_GetNameAndDescByRematchIdx(u32, const u8 **, const u8 **);

// .rodata

static const match_call_text_data_t sMrStoneTextScripts[] = {
    { MatchCall_Text_MrStone1,  0xFFFF, 0xFFFF },
    { MatchCall_Text_MrStone2,  0xFFFF, 0xFFFF },
    { MatchCall_Text_MrStone3,  FLAG_TALKED_TO_FLORIA_FLOWER_SHOP,        0xFFFF },
    { MatchCall_Text_MrStone4,  0xFFFF,             0xFFFF },
    { MatchCall_Text_MrStone5,  FLAG_RECEIVED_MAGNET_FROM_SUNNY,                  0xFFFF },
    { MatchCall_Text_MrStone6,  FLAG_DEFEATED_PETALBURG_GYM,         0xFFFF },
    { MatchCall_Text_MrStone7,  FLAG_BIKE_SHOP_LOAN_ACTIVE,              0xFFFF },
    { MatchCall_Text_MrStone8,  FLAG_RECEIVED_HM06, 0xFFFF },
    { MatchCall_Text_MrStone9,  FLAG_RECEIVED_HM07, 0xFFFF },
    { MatchCall_Text_MrStone10, FLAG_DEFEATED_SOOTOPOLIS_GYM,        0xFFFF },
    { MatchCall_Text_MrStone11, FLAG_SYS_GAME_CLEAR,                 0xFFFF },
    { NULL,                     0xFFFF,                              0xFFFF }
};

static const struct MatchCallStructNPC sMrStoneMatchCallHeader =
{
    .type = MC_TYPE_NPC,
    .mapSec = MAPSEC_GOLDENROD_CITY,
    .flag = 0xFFFF,
    .desc = gText_MrStoneMatchCallDesc,
    .name = gText_MrStoneMatchCallName,
    .textData = sMrStoneTextScripts
};

static const match_call_text_data_t sNormanTextScripts[] = {
    { MatchCall_Text_Norman1, 0xFFF, 0xFFFF },
    { MatchCall_Text_Norman2, FLAG_DEFEATED_AZALEA_GYM,     0xFFFF },
    { MatchCall_Text_Norman3, FLAG_DEFEATED_LAVARIDGE_GYM,   0xFFFF },
    { MatchCall_Text_Norman4, FLAG_DEFEATED_PETALBURG_GYM,   0xFFFF },
    { MatchCall_Text_Norman5, FLAG_UNUSED_0x2BB, 0xFFFF },
    { MatchCall_Text_Norman6, 0xFFFE,                        0xFFFF },
    { MatchCall_Text_Norman7, FLAG_SYS_GAME_CLEAR,           0xFFFF },
    { MatchCall_Text_Norman8, FLAG_SYS_GAME_CLEAR,           0xFFFF },
    { MatchCall_Text_Norman9, FLAG_SYS_GAME_CLEAR,           0xFFFF },
    { NULL,                   0xFFFF,                        0xFFFF }
};

static const struct MatchCallStructTrainer sNormanMatchCallHeader =
{
    .type = MC_TYPE_LEADER,
    .mapSec = MAPSEC_VIOLET_CITY,
    .flag = 0xFFF,
    .rematchTableIdx = 0,
    .desc = gText_NormanMatchCallDesc,
    .name = gText_NormanMatchCallName,
    .textData = sNormanTextScripts
};

static const struct MatchCallBirch sProfBirchMatchCallHeader =
{
    .type = MC_TYPE_BIRCH,
    .mapSec = 0,
    .flag = FLAG_ENABLE_PROF_ELM_MATCH_CALL,
    .desc = gText_ProfBirchMatchCallDesc,
    .name = gText_ProfBirchMatchCallName
};

static const match_call_text_data_t sMomTextScripts[] = {
    { MatchCall_Text_Mom1, 0xFFFF,                      0xFFFF },
    { MatchCall_Text_Mom2, FLAG_DEFEATED_PETALBURG_GYM, 0xFFFF },
    { MatchCall_Text_Mom3, FLAG_SYS_GAME_CLEAR,         0xFFFF },
    { NULL,                0xFFFF,                      0xFFFF }
};

static const struct MatchCallStructNPC sMomMatchCallHeader =
{
    .type = MC_TYPE_NPC,
    .mapSec = MAPSEC_NEW_BARK_TOWN,
    .flag = FLAG_ENABLE_MOM_MATCH_CALL,
    .desc = gText_MomMatchCallDesc,
    .name = gText_MomMatchCallName,
    .textData = sMomTextScripts
};

static const match_call_text_data_t sStevenTextScripts[] = {
    { MatchCall_Text_Steven1, 0xFFFF,                              0xFFFF },
    { MatchCall_Text_Steven2, FLAG_IN_BUG_CATCHING_CONTEST,          0xFFFF },
    { MatchCall_Text_Steven3, FLAG_UNUSED_0x2BB,       0xFFFF },
    { MatchCall_Text_Steven4, FLAG_RECEIVED_HM07, 0xFFFF },
    { MatchCall_Text_Steven5, FLAG_DEFEATED_MOSSDEEP_GYM,          0xFFFF },
    { MatchCall_Text_Steven6, FLAG_RECEIVED_TM05_ROAR, 0xFFFF },
    { MatchCall_Text_Steven7, FLAG_SYS_GAME_CLEAR,                 0xFFFF },
    { NULL,                   0xFFFF,                              0xFFFF },
};

static const struct MatchCallStructNPC sStevenMatchCallHeader =
{
    .type = MC_TYPE_NPC,
    .mapSec = MAPSEC_NONE,
    .flag = 0xFFFF,
    .desc = gText_StevenMatchCallDesc,
    .name = gText_StevenMatchCallName,
    .textData = sStevenTextScripts
};

static const match_call_text_data_t sMayTextScripts[] = {
    { MatchCall_Text_May1,  0xFFFF,                              0xFFFF },
    { MatchCall_Text_May2,  FLAG_DEFEATED_AZALEA_GYM,           0xFFFF },
    { MatchCall_Text_May3,  FLAG_MET_BUENA,          0xFFFF },
    { MatchCall_Text_May4,  0xFFFF,       0xFFFF },
    { MatchCall_Text_May5,  FLAG_RECEIVED_MAGNET_FROM_SUNNY,                  0xFFFF },
    { MatchCall_Text_May6,  FLAG_DEFEATED_LAVARIDGE_GYM,         0xFFFF },
    { MatchCall_Text_May7,  FLAG_DEFEATED_PETALBURG_GYM,         0xFFFF },
    { MatchCall_Text_May8,  FLAG_BIKE_SHOP_LOAN_ACTIVE,              0xFFFF },
    { MatchCall_Text_May9,  FLAG_UNUSED_0x2BB,       0xFFFF },
    { MatchCall_Text_May10, FLAG_RECEIVED_HM06, 0xFFFF },
    { MatchCall_Text_May11, FLAG_MADE_UNOWN_APPEAR_IN_RUINS,           0xFFFF },
    { MatchCall_Text_May12, FLAG_RECEIVED_HM07, 0xFFFF },
    { MatchCall_Text_May13, FLAG_RECEIVED_TM05_ROAR, 0xFFFF },
    { MatchCall_Text_May14, FLAG_DEFEATED_SOOTOPOLIS_GYM,        0xFFFF },
    { MatchCall_Text_May15, FLAG_SYS_GAME_CLEAR,                 0xFFFF },
    { NULL,                 0xFFFF,                              0xFFFF }
};

static const struct MatchCallRival sMayMatchCallHeader =
{
    .type = MC_TYPE_RIVAL,
    .playerGender = MALE,
    .flag = 0xFFFF,
    .desc = gText_MayBrendanMatchCallDesc,
    .name = gText_ExpandedPlaceholder_May,
    .textData = sMayTextScripts
};

static const match_call_text_data_t sBrendanTextScripts[] = {
    { MatchCall_Text_Brendan1,  0xFFFF,                              0xFFFF },
    { MatchCall_Text_Brendan2,  FLAG_DEFEATED_AZALEA_GYM,           0xFFFF },
    { MatchCall_Text_Brendan3,  FLAG_MET_BUENA,          0xFFFF },
    { MatchCall_Text_Brendan4,  0xFFFF,       0xFFFF },
    { MatchCall_Text_Brendan5,  FLAG_RECEIVED_MAGNET_FROM_SUNNY,                  0xFFFF },
    { MatchCall_Text_Brendan6,  FLAG_DEFEATED_LAVARIDGE_GYM,         0xFFFF },
    { MatchCall_Text_Brendan7,  FLAG_DEFEATED_PETALBURG_GYM,         0xFFFF },
    { MatchCall_Text_Brendan8,  FLAG_BIKE_SHOP_LOAN_ACTIVE,              0xFFFF },
    { MatchCall_Text_Brendan9,  FLAG_UNUSED_0x2BB,       0xFFFF },
    { MatchCall_Text_Brendan10, FLAG_RECEIVED_HM06, 0xFFFF },
    { MatchCall_Text_Brendan11, FLAG_MADE_UNOWN_APPEAR_IN_RUINS,           0xFFFF },
    { MatchCall_Text_Brendan12, FLAG_RECEIVED_HM07, 0xFFFF },
    { MatchCall_Text_Brendan13, FLAG_RECEIVED_TM05_ROAR, 0xFFFF },
    { MatchCall_Text_Brendan14, FLAG_DEFEATED_SOOTOPOLIS_GYM,        0xFFFF },
    { MatchCall_Text_Brendan15, FLAG_SYS_GAME_CLEAR,                 0xFFFF },
    { NULL,                     0xFFFF,                              0xFFFF }
};

static const struct MatchCallRival sBrendanMatchCallHeader =
{
    .type = MC_TYPE_RIVAL,
    .playerGender = FEMALE,
    .flag = 0xFFFF,
    .desc = gText_MayBrendanMatchCallDesc,
    .name = gText_ExpandedPlaceholder_Brendan,
    .textData = sBrendanTextScripts
};

static const match_call_text_data_t sWallyTextScripts[] = {
    { MatchCall_Text_Wally1, 0xFFFF,                              0xFFFF },
    { MatchCall_Text_Wally2, FLAG_IN_BUG_CATCHING_CONTEST,          0xFFFF },
    { MatchCall_Text_Wally3, FLAG_DEFEATED_LAVARIDGE_GYM,         0xFFFF },
    { MatchCall_Text_Wally4, FLAG_BIKE_SHOP_LOAN_ACTIVE,              0xFFFF },
    { MatchCall_Text_Wally5, FLAG_RECEIVED_HM06, 0xFFFF },
    { MatchCall_Text_Wally6, FLAG_RECEIVED_TM05_ROAR, 0xFFFF },
    { MatchCall_Text_Wally7, FLAG_MET_FRIEDA_OF_FRIDAY,    0xFFFF },
    { NULL,                  0xFFFF,                              0xFFFF }
};

const struct MatchCallLocationOverride sWallyLocationData[] = {
    { 0xFFFF,          MAPSEC_NONE },
    { 0xFFFF,    MAPSEC_NONE },
    { 0xFFFF,  MAPSEC_NONE },
    { 0xFFFF,                                 MAPSEC_NONE }
};

static const struct MatchCallWally sWallyMatchCallHeader =
{
    .type = MC_TYPE_WALLY,
    .mapSec = 0,
    .flag = FLAG_UNUSED_0x2BB,
    .rematchTableIdx = 0,
    .desc = gText_WallyMatchCallDesc,
    .textData = sWallyTextScripts,
    .locationData = sWallyLocationData
};

static const match_call_text_data_t sScottTextScripts[] = {
    { MatchCall_Text_Scott1, 0xFFFF,                              0xFFFF },
    { MatchCall_Text_Scott2, FLAG_HATCHED_ELMS_EGG,  0xFFFF },
    { MatchCall_Text_Scott3, FLAG_BIKE_SHOP_LOAN_ACTIVE,              0xFFFF },
    { MatchCall_Text_Scott4, FLAG_UNUSED_0x2BB,       0xFFFF },
    { MatchCall_Text_Scott5, FLAG_RECEIVED_HM07, 0xFFFF },
    { MatchCall_Text_Scott6, FLAG_DEFEATED_SOOTOPOLIS_GYM,        0xFFFF },
    { MatchCall_Text_Scott7, FLAG_SYS_GAME_CLEAR,                 0xFFFF },
    { NULL,                  0xFFFF,                              0xFFFF }
};


static const struct MatchCallStructNPC sScottMatchCallHeader =
{
    .type = 0,
    .mapSec = MAPSEC_NONE,
    .flag = FLAG_UNUSED_0x2BB,
    .desc = gText_ScottMatchCallDesc,
    .name = gText_ScottMatchCallName,
    .textData = sScottTextScripts
};

static const match_call_text_data_t sRoxanneTextScripts[] = {
    { MatchCall_Text_Roxanne1, 0xFFFE,              0xFFFF },
    { MatchCall_Text_Roxanne2, 0xFFFF,              0xFFFF },
    { MatchCall_Text_Roxanne3, 0xFFFF,              0xFFFF },
    { MatchCall_Text_Roxanne4, FLAG_SYS_GAME_CLEAR, 0xFFFF },
    { NULL,                    0xFFFF,              0xFFFF }
};

static const struct MatchCallStructTrainer sRoxanneMatchCallHeader =
{
    .type = MC_TYPE_LEADER,
    .mapSec = MAPSEC_GOLDENROD_CITY,
    .flag = FLAG_ENABLE_ROXANNE_MATCH_CALL,
    .rematchTableIdx = 0,
    .desc = gText_RoxanneMatchCallDesc,
    .name = NULL,
    .textData = sRoxanneTextScripts
};

static const match_call_text_data_t sBrawlyTextScripts[] = {
    { MatchCall_Text_Brawly1, 0xFFFE,              0xFFFF },
    { MatchCall_Text_Brawly2, 0xFFFF,              0xFFFF },
    { MatchCall_Text_Brawly3, 0xFFFF,              0xFFFF },
    { MatchCall_Text_Brawly4, FLAG_SYS_GAME_CLEAR, 0xFFFF },
    { NULL,                   0xFFFF,              0xFFFF }
};

static const struct MatchCallStructTrainer sBrawlyMatchCallHeader =
{
    .type = MC_TYPE_LEADER,
    .mapSec = MAPSEC_AZALEA_TOWN,
    .flag = FLAG_ENABLE_BRAWLY_MATCH_CALL,
    .rematchTableIdx = 0,
    .desc = gText_BrawlyMatchCallDesc,
    .name = NULL,
    .textData = sBrawlyTextScripts
};

static const match_call_text_data_t sWattsonTextScripts[] = {
    { MatchCall_Text_Wattson1, 0xFFFE,              0xFFFF },
    { MatchCall_Text_Wattson2, 0xFFFF,              0xFFFF },
    { MatchCall_Text_Wattson3, 0xFFFF,              0xFFFF },
    { MatchCall_Text_Wattson4, FLAG_SYS_GAME_CLEAR, 0xFFFF },
    { NULL,                    0xFFFF,              0xFFFF }
};

static const struct MatchCallStructTrainer sWattsonMatchCallHeader =
{
    .type = MC_TYPE_LEADER,
    .mapSec = MAPSEC_OLIVINE_CITY,
    .flag = FLAG_ENABLE_WATTSON_MATCH_CALL,
    .rematchTableIdx = 0,
    .desc = gText_WattsonMatchCallDesc,
    .name = NULL,
    .textData = sWattsonTextScripts
};

static const match_call_text_data_t sFlanneryTextScripts[] = {
    { MatchCall_Text_Flannery1, 0xFFFE,              0xFFFF },
    { MatchCall_Text_Flannery2, 0xFFFF,              0xFFFF },
    { MatchCall_Text_Flannery3, 0xFFFF,              0xFFFF },
    { MatchCall_Text_Flannery4, FLAG_SYS_GAME_CLEAR, 0xFFFF },
    { NULL,                     0xFFFF,              0xFFFF }
};

static const struct MatchCallStructTrainer sFlanneryMatchCallHeader =
{
    .type = MC_TYPE_LEADER,
    .mapSec = MAPSEC_CIANWOOD_CITY,
    .flag = FLAG_ENABLE_FLANNERY_MATCH_CALL,
    .rematchTableIdx = 0,
    .desc = gText_FlanneryMatchCallDesc,
    .name = NULL,
    .textData = sFlanneryTextScripts
};

static const match_call_text_data_t sWinonaTextScripts[] = {
    { MatchCall_Text_Winona1, 0xFFFE,              0xFFFF },
    { MatchCall_Text_Winona2, 0xFFFF,              0xFFFF },
    { MatchCall_Text_Winona3, 0xFFFF,              0xFFFF },
    { MatchCall_Text_Winona4, FLAG_SYS_GAME_CLEAR, 0xFFFF },
    { NULL,                   0xFFFF,              0xFFFF }
};

static const struct MatchCallStructTrainer sWinonaMatchCallHeader =
{
    .type = MC_TYPE_LEADER,
    .mapSec = MAPSEC_FORTREE_CITY,
    .flag = FLAG_ENABLE_WINONA_MATCH_CALL,
    .rematchTableIdx = 0,
    .desc = gText_WinonaMatchCallDesc,
    .name = NULL,
    .textData = sWinonaTextScripts
};

static const match_call_text_data_t sTateLizaTextScripts[] = {
    { MatchCall_Text_TateLiza1, 0xFFFE,              0xFFFF },
    { MatchCall_Text_TateLiza2, 0xFFFF,              0xFFFF },
    { MatchCall_Text_TateLiza3, 0xFFFF,              0xFFFF },
    { MatchCall_Text_TateLiza4, FLAG_SYS_GAME_CLEAR, 0xFFFF },
    { NULL,                     0xFFFF,              0xFFFF }
};

static const struct MatchCallStructTrainer sTateLizaMatchCallHeader =
{
    .type = MC_TYPE_LEADER,
    .mapSec = MAPSEC_BURNED_TOWER,
    .flag = FLAG_ENABLE_TATE_AND_LIZA_MATCH_CALL,
    .rematchTableIdx = 0,
    .desc = gText_TateLizaMatchCallDesc,
    .name = NULL,
    .textData = sTateLizaTextScripts
};

static const match_call_text_data_t sJuanTextScripts[] = {
    { MatchCall_Text_Juan1, 0xFFFE,              0xFFFF },
    { MatchCall_Text_Juan2, 0xFFFF,              0xFFFF },
    { MatchCall_Text_Juan3, 0xFFFF,              0xFFFF },
    { MatchCall_Text_Juan4, FLAG_SYS_GAME_CLEAR, 0xFFFF },
    { NULL,                 0xFFFF,              0xFFFF }
};

static const struct MatchCallStructTrainer sJuanMatchCallHeader =
{
    .type = MC_TYPE_LEADER,
    .mapSec = MAPSEC_TOHJO_FALLS,
    .flag = FLAG_ENABLE_JUAN_MATCH_CALL,
    .rematchTableIdx = 0,
    .desc = gText_JuanMatchCallDesc,
    .name = NULL,
    .textData = sJuanTextScripts
};

static const match_call_text_data_t sSidneyTextScripts[] = {
    { MatchCall_Text_Sidney, 0xFFFF, 0xFFFF },
    { NULL,                  0xFFFF, 0xFFFF }
};

static const struct MatchCallStructTrainer sSidneyMatchCallHeader =
{
    .type = MC_TYPE_LEADER,
    .mapSec = MAPSEC_FAST_SHIP,
    .flag = FLAG_PHONE_CARD_SIDNEY,
    .rematchTableIdx = 0,
    .desc = gText_EliteFourMatchCallDesc,
    .name = NULL,
    .textData = sSidneyTextScripts
};

static const match_call_text_data_t sPhoebeTextScripts[] = {
    { MatchCall_Text_Phoebe, 0xFFFF, 0xFFFF },
    { NULL,                  0xFFFF, 0xFFFF }
};

static const struct MatchCallStructTrainer sPhoebeMatchCallHeader =
{
    .type = MC_TYPE_LEADER,
    .mapSec = MAPSEC_FAST_SHIP,
    .flag = FLAG_PHONE_CARD_PHOEBE,
    .rematchTableIdx = 0,
    .desc = gText_EliteFourMatchCallDesc,
    .name = NULL,
    .textData = sPhoebeTextScripts
};

static const match_call_text_data_t sGlaciaTextScripts[] = {
    { MatchCall_Text_Glacia, 0xFFFF, 0xFFFF },
    { NULL,                  0xFFFF, 0xFFFF }
};

static const struct MatchCallStructTrainer sGlaciaMatchCallHeader =
{
    .type = MC_TYPE_LEADER,
    .mapSec = MAPSEC_FAST_SHIP,
    .flag = FLAG_PHONE_CARD_GLACIA,
    .rematchTableIdx = 0,
    .desc = gText_EliteFourMatchCallDesc,
    .name = NULL,
    .textData = sGlaciaTextScripts
};

static const match_call_text_data_t sDrakeTextScripts[] = {
    { MatchCall_Text_Drake, 0xFFFF, 0xFFFF },
    { NULL,                 0xFFFF, 0xFFFF }
};

static const struct MatchCallStructTrainer sDrakeMatchCallHeader =
{
    .type = MC_TYPE_LEADER,
    .mapSec = MAPSEC_FAST_SHIP,
    .flag = FLAG_PHONE_CARD_DRAKE,
    .rematchTableIdx = 0,
    .desc = gText_EliteFourMatchCallDesc,
    .name = NULL,
    .textData = sDrakeTextScripts
};

static const match_call_text_data_t sWallaceTextScripts[] = {
    { MatchCall_Text_Wallace, 0xFFFF, 0xFFFF },
    { NULL,                   0xFFFF, 0xFFFF }
};

static const struct MatchCallStructTrainer sWallaceMatchCallHeader =
{
    .type = MC_TYPE_LEADER,
    .mapSec = MAPSEC_FAST_SHIP,
    .flag = FLAG_PHONE_CARD_WALLACE,
    .rematchTableIdx = 0,
    .desc = gText_ChampionMatchCallDesc,
    .name = NULL,
    .textData = sWallaceTextScripts
};

static const match_call_t sMatchCallHeaders[] = {
    [MC_HEADER_MR_STONE]   = {.npc    = &sMrStoneMatchCallHeader},
    [MC_HEADER_PROF_BIRCH] = {.birch  = &sProfBirchMatchCallHeader},
    [MC_HEADER_BRENDAN]    = {.rival  = &sBrendanMatchCallHeader},
    [MC_HEADER_MAY]        = {.rival  = &sMayMatchCallHeader},
    [MC_HEADER_WALLY]      = {.wally  = &sWallyMatchCallHeader},
    [MC_HEADER_NORMAN]     = {.leader = &sNormanMatchCallHeader},
    [MC_HEADER_MOM]        = {.npc    = &sMomMatchCallHeader},
    [MC_HEADER_STEVEN]     = {.npc    = &sStevenMatchCallHeader},
    [MC_HEADER_SCOTT]      = {.npc    = &sScottMatchCallHeader},
    [MC_HEADER_ROXANNE]    = {.leader = &sRoxanneMatchCallHeader},
    [MC_HEADER_BRAWLY]     = {.leader = &sBrawlyMatchCallHeader},
    [MC_HEADER_WATTSON]    = {.leader = &sWattsonMatchCallHeader},
    [MC_HEADER_FLANNERY]   = {.leader = &sFlanneryMatchCallHeader},
    [MC_HEADER_WINONA]     = {.leader = &sWinonaMatchCallHeader},
    [MC_HEADER_TATE_LIZA]  = {.leader = &sTateLizaMatchCallHeader},
    [MC_HEADER_JUAN]       = {.leader = &sJuanMatchCallHeader},
    [MC_HEADER_SIDNEY]     = {.leader = &sSidneyMatchCallHeader},
    [MC_HEADER_PHOEBE]     = {.leader = &sPhoebeMatchCallHeader},
    [MC_HEADER_GLACIA]     = {.leader = &sGlaciaMatchCallHeader},
    [MC_HEADER_DRAKE]      = {.leader = &sDrakeMatchCallHeader},
    [MC_HEADER_WALLACE]    = {.leader = &sWallaceMatchCallHeader}
};

static const struct MatchCallCheckPageOverride sCheckPageOverrides[] = {
    { 
        .idx = MC_HEADER_STEVEN,  
        .facilityClass = FACILITY_CLASS_STEVEN,  
        .flag = 0xFFFF,                     
        .flavorTexts = { 
            [CHECK_PAGE_STRATEGY] = gText_MatchCallSteven_Strategy, 
            [CHECK_PAGE_POKEMON]  = gText_MatchCallSteven_Pokemon, 
            [CHECK_PAGE_INTRO_1]  = gText_MatchCallSteven_Intro1_BeforeMeteorFallsBattle, 
            [CHECK_PAGE_INTRO_2]  = gText_MatchCallSteven_Intro2_BeforeMeteorFallsBattle 
        } 
    },
    { 
        .idx = MC_HEADER_STEVEN,  
        .facilityClass = FACILITY_CLASS_STEVEN,
        .flag = FLAG_DEFEATED_MOSSDEEP_GYM, 
        .flavorTexts = { 
            [CHECK_PAGE_STRATEGY] = gText_MatchCallSteven_Strategy, 
            [CHECK_PAGE_POKEMON]  = gText_MatchCallSteven_Pokemon, 
            [CHECK_PAGE_INTRO_1]  = gText_MatchCallSteven_Intro1_AfterMeteorFallsBattle, 
            [CHECK_PAGE_INTRO_2]  = gText_MatchCallSteven_Intro2_AfterMeteorFallsBattle 
        } 
    },
    { 
        .idx = MC_HEADER_BRENDAN, 
        .facilityClass = FACILITY_CLASS_GOLD, 
        .flag = 0xFFFF,                     
        .flavorTexts = MCFLAVOR(Brendan)
    },
    { 
        .idx = MC_HEADER_MAY,     
        .facilityClass = FACILITY_CLASS_KRIS,     
        .flag = 0xFFFF,                     
        .flavorTexts = MCFLAVOR(May)
    }
};

// .text

static u32 MatchCallGetFunctionIndex(match_call_t matchCall)
{
    switch (matchCall.common->type)
    {
        default:
        case MC_TYPE_NPC:
            return 0;
        case MC_TYPE_TRAINER:
        case MC_TYPE_LEADER:
            return 1;
        case MC_TYPE_WALLY:
            return 2;
        case MC_TYPE_RIVAL:
            return 3;
        case MC_TYPE_BIRCH:
            return 4;
    }
}

u32 GetTrainerIdxByRematchIdx(u32 rematchIdx)
{
    return gRematchTable[rematchIdx].trainerIds[0];
}

s32 GetRematchIdxByTrainerIdx(s32 trainerIdx)
{
    s32 rematchIdx;

    for (rematchIdx = 0; rematchIdx < REMATCH_TABLE_ENTRIES; rematchIdx++)
    {
        if (gRematchTable[rematchIdx].trainerIds[0] == trainerIdx)
            return rematchIdx;
    }
    return -1;
}

bool32 MatchCall_GetEnabled(u32 idx)
{
    return FALSE;
}

u8 MatchCall_GetMapSec(u32 idx)
{
    return MAPSEC_NONE;
}

bool32 MatchCall_IsRematchable(u32 idx)
{
    return FALSE;
}

bool32 MatchCall_HasCheckPage(u32 idx)
{
    return FALSE;
}

u32 MatchCall_GetRematchTableIdx(u32 idx)
{
    return REMATCH_TABLE_ENTRIES;
}

void MatchCall_GetMessage(u32 idx, u8 *dest)
{
    return;
}

static void MatchCall_BufferCallMessageText(const match_call_text_data_t *textData, u8 *dest)
{
    u32 i;
    for (i = 0; textData[i].text != NULL; i++)
        ;
    if (i)
        i--;
    while (i)
    {
        if (textData[i].flag != 0xFFFF && FlagGet(textData[i].flag) == TRUE)
            break;
        i--;
    }
    if (textData[i].flag2 != 0xFFFF)
        FlagSet(textData[i].flag2);
    StringExpandPlaceholders(dest, textData[i].text);
}

static void MatchCall_BufferCallMessageTextByRematchTeam(const match_call_text_data_t *textData, u16 idx, u8 *dest)
{
    u32 i;
    for (i = 0; textData[i].text != NULL; i++)
    {
        if (textData[i].flag == 0xFFFE)
            break;
        if (textData[i].flag != 0xFFFF && !FlagGet(textData[i].flag))
            break;
    }
    if (textData[i].flag != 0xFFFE)
    {
        if (i)
            i--;
        if (textData[i].flag2 != 0xFFFF)
            FlagSet(textData[i].flag2);
        StringExpandPlaceholders(dest, textData[i].text);
    }
    else
    {
        if (FlagGet(FLAG_SYS_GAME_CLEAR))
        {
            do
            {
                if (gSaveBlock1Ptr->trainerRematches[idx])
                    i += 2;
                else if (CountBattledRematchTeams(idx) >= 2)
                    i += 3;
                else
                    i++;
            } while (0);
        }

        StringExpandPlaceholders(dest, textData[i].text);
    }
}

void MatchCall_GetNameAndDesc(u32 idx, const u8 **desc, const u8 **name)
{
    return;
}

static void MatchCall_GetNameAndDescByRematchIdx(u32 idx, const u8 **desc, const u8 **name)
{
    const struct Trainer *trainer = gTrainers + GetTrainerIdxByRematchIdx(idx);
    *desc = gTrainerClassNames[trainer->trainerClass];
    *name = trainer->trainerName;
}

const u8 *MatchCall_GetOverrideFlavorText(u32 idx, u32 offset)
{
    return NULL;
}

int MatchCall_GetOverrideFacilityClass(u32 idx)
{
    return -1;
}

bool32 MatchCall_HasRematchId(u32 idx)
{
    int i;

    for (i = 0; i < (int)ARRAY_COUNT(sMatchCallHeaders); i++)
    {
        u32 id = MatchCall_GetRematchTableIdx(i);
        if (id != REMATCH_TABLE_ENTRIES && id == idx)
            return TRUE;
    }
    return FALSE;
}

void SetMatchCallRegisteredFlag(void)
{
    int r0 = GetRematchIdxByTrainerIdx(gSpecialVar_0x8004);
    if (r0 >= 0)
        FlagSet(gPhoneContacts[gRematchTable[r0].phoneContactId].registeredFlag);
}
