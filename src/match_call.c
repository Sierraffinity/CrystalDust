#include "global.h"
#include "malloc.h"
#include "battle.h"
#include "battle_setup.h"
#include "bg.h"
#include "day_night.h"
#include "data.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "field_player_avatar.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "item.h"
#include "main.h"
#include "match_call.h"
#include "menu.h"
#include "money.h"
#include "new_game.h"
#include "overworld.h"
#include "palette.h"
#include "phone_contact.h"
#include "phone_script.h"
#include "phone_scripts.h"
#include "pokedex.h"
#include "pokemon.h"
#include "random.h"
#include "region_map.h"
#include "rtc.h"
#include "scanline_effect.h"
#include "script.h"
#include "script_movement.h"
#include "sound.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "wild_encounter.h"
#include "window.h"
#include "constants/abilities.h"
#include "constants/battle_frontier.h"
#include "constants/event_objects.h"
#include "constants/items.h"
#include "constants/maps.h"
#include "constants/region_map_sections.h"
#include "constants/room_decor.h"
#include "constants/songs.h"
#include "constants/trainers.h"

// Each match call message has variables that can be populated randomly or
// dependent on the trainer. The below are IDs for how to populate the vars
// in a given message.
// Each message may have up to 3 vars in it
enum {
    STR_TRAINER_NAME,
    STR_MAP_NAME,
    STR_SPECIES_IN_ROUTE,
    STR_SPECIES_IN_PARTY,
    STR_FACILITY_NAME,
    STR_FRONTIER_STREAK,
    STR_NONE = -1,
};
#define STRS_NORMAL_MSG      {STR_TRAINER_NAME, STR_NONE,             STR_NONE}
#define STRS_WILD_BATTLE     {STR_TRAINER_NAME, STR_SPECIES_IN_ROUTE, STR_NONE}
#define STRS_BATTLE_NEGATIVE {STR_TRAINER_NAME, STR_NONE,             STR_NONE}
#define STRS_BATTLE_POSITIVE {STR_TRAINER_NAME, STR_SPECIES_IN_PARTY, STR_NONE}
#define STRS_BATTLE_REQUEST  {STR_TRAINER_NAME, STR_MAP_NAME,         STR_NONE}
#define STRS_SWARM_MSG		 {STR_TRAINER_NAME, STR_MAP_NAME,         STR_NONE}
#define STRS_GIFT_MSG		 {STR_TRAINER_NAME, STR_MAP_NAME,         STR_NONE}
#define STRS_FRONTIER        {STR_TRAINER_NAME, STR_FACILITY_NAME,    STR_FRONTIER_STREAK}

// Topic IDs for sMatchCallGeneralTopics
enum {
    GEN_TOPIC_STREAK = 1,
    GEN_TOPIC_STREAK_RECORD,
    GEN_TOPIC_B_DOME,
    GEN_TOPIC_B_PIKE,
    GEN_TOPIC_B_PYRAMID,
};

// Each trainer has a text id for 1 of each of the 3 battle topics
// The msgId is the index into the respective topic's message table
// For all but 2 trainers this index is the same for each topic
#define BATTLE_TEXT_IDS(msgId) {TEXT_ID(B_TOPIC_WILD, (msgId)), TEXT_ID(B_TOPIC_NEGATIVE, (msgId)), TEXT_ID(B_TOPIC_POSITIVE, (msgId))}

// Topic IDs for sMatchCallBattleRequestTopics
enum {
    REQ_TOPIC_SAME_ROUTE = 1,
    REQ_TOPIC_DIFF_ROUTE,
};

struct MatchCallState
{
    u32 minutes;
    u16 callerId;
    u8 stepCounter;
    u8 triggeredFromScript:1;
    u8 forcedPhoneCallId:7;
    const u8 *script;
};

struct MultiTrainerMatchCallText
{
    u16 trainerId;
    const u8 *text;
};

struct BattleFrontierStreakInfo
{
    u16 facilityId;
    u16 streak;
};

struct ForcedPhoneCall
{
    u16 flag;
    u16 phoneContactId;
    bool8 (*callCondition)(void);
    const u8 *script;
};

EWRAM_DATA struct MatchCallState sMatchCallState = {0};
EWRAM_DATA struct BattleFrontierStreakInfo sBattleFrontierStreakInfo = {0};

static u32 GetNumRegisteredNPCs(void);
static u32 GetActiveMatchCallPhoneContactId(u32);
static u16 GetRematchTrainerLocation(int);
static bool32 TrainerIsEligibleForRematch(int);
static void StartMatchCall(void);
static const struct MatchCallText *GetGenericMatchCallText(int, u8 *);
static bool32 ShouldTrainerRequestBattle(u32, u32);
static void BuildMatchCallString(int, const struct MatchCallText *, u8 *);
static u16 GetFrontierStreakInfo(u16, u32 *);
static void PopulateMatchCallStringVars(int, const s8 *);
static void PopulateMatchCallStringVar(int, int, u8 *);
static bool32 LoadMatchCallWindowGfx(u8);
static bool32 MatchCall_DrawWindow(u8);
static bool32 MatchCall_ReadyIntro(u8);
static bool32 SlideMatchCallWindowsOntoScreen(u8);
static bool32 RunMatchCallIntroEllipsis(u8);
static void PopulateTrainerName(int, u8 *);
static void PopulateMapName(int, u8 *);
static void PopulateSpeciesFromTrainerLocation(int, u8 *);
static void PopulateSpeciesFromTrainerParty(int, u8 *);
static void PopulateBattleFrontierFacilityName(int, u8 *);
static void PopulateBattleFrontierStreak(int, u8 *);



#define TEXT_ID(topic, id) (((topic) << 8) | ((id) & 0xFF))

const struct massOutbreakPhoneCallData qwilfishOutbreakData = {
	.species = SPECIES_QWILFISH,
	.location_map_num = MAP_NUM(ROUTE32),
	.location_map_group = MAP_NUM(ROUTE32),
	.probability = 90,
	.level = 20,
	.wildState = OUTBREAK_FISHING,
	.specialLevel1 = 5,
	.specialLevel2 = 40,
};

const struct massOutbreakPhoneCallData dunsparceOutbreakData = {
	.species = SPECIES_DUNSPARCE,
	.location_map_num = MAP_NUM(DARK_CAVE_SOUTH),
	.location_map_group = MAP_NUM(DARK_CAVE_SOUTH),
	.probability = 60,
	.level = 3,
	.wildState = OUTBREAK_WALKING,
	.specialLevel1 = 0,
	.specialLevel2 = 0,
};

const struct massOutbreakPhoneCallData yanmaOutbreakData = {
	.species = SPECIES_YANMA,
	.location_map_num = MAP_NUM(ROUTE35),
	.location_map_group = MAP_NUM(ROUTE35),
	.probability = 30,
	.level = 13,
	.wildState = OUTBREAK_WALKING,
	.specialLevel1 = 0,
	.specialLevel2 = 0,
};

const struct massOutbreakPhoneCallData outbreakNone = {
	.species = SPECIES_NONE,
	.location_map_num = 0,
	.location_map_group = 0,
	.probability = 0,
	.level = 0,
	.wildState = 0,
	.specialLevel1 = 0,
	.specialLevel2 = 0,
};

const struct MatchCallTrainerTextInfo gMatchCallTrainers[MATCH_CALL_COUNT] =
{
    {
        .trainerId = TRAINER_ANTHONY_1,
        .unused = 0,
        .battleFrontierRecordStreakTextIndex = 12,
	    .rematchOfferedFlag = FLAG_ANTHONY_OFFERED_REMATCH,
		.rematchCheckFlags = {FLAG_VISITED_OLIVINE_CITY, FLAG_CLEARED_RADIO_TOWER, FLAG_IS_CHAMPION, FLAG_RETURNED_MACHINE_PART},
	    .giftFlag = 0,
	    .genericStartIndex = 5,
	    .genericTextsAmount = 5,
		.outbreakData = dunsparceOutbreakData,
	    .callTexts = {{Matchcall_Anthony_Call_Morn, STRS_NORMAL_MSG},
	    				 {Matchcall_Anthony_Call_Day, STRS_NORMAL_MSG},
						 {Matchcall_Anthony_Call_Night, STRS_NORMAL_MSG}},
	    .answerTexts = {{Matchcall_Anthony_Answer_Morn, STRS_NORMAL_MSG},
	    				   {Matchcall_Anthony_Answer_Day, STRS_NORMAL_MSG},
						   {Matchcall_Anthony_Answer_Night, STRS_NORMAL_MSG}},
	    .giftText = 0,
	    .rematchText = {Matchcall_Anthony_Rematch, STRS_BATTLE_REQUEST},
	    .outbreakText = {Matchcall_Anthony_Swarm, STRS_SWARM_MSG},
	    .remindGiftText = 0,
	    .remindRematchText = {Matchcall_Anthony_Remind_Rematch, STRS_BATTLE_REQUEST},
	    .remindoutbreakText = {Matchcall_Anthony_Remind_Swarm, STRS_SWARM_MSG},
		.hangupText = {Matchcall_Anthony_Hangup, STRS_NORMAL_MSG},
		.rematchAvailability = {DAY_FRIDAY, TIME_NIGHT},
    },
    {
        .trainerId = TRAINER_RALPH_1,
        .unused = 0,
        .battleFrontierRecordStreakTextIndex = 12,
	    .rematchOfferedFlag = FLAG_RALPH_OFFERED_REMATCH,
		.rematchCheckFlags = {FLAG_VISITED_ECRUTEAK_CITY, FLAG_LANDMARK_LAKE_OF_RAGE, FLAG_IS_CHAMPION, FLAG_RETURNED_MACHINE_PART},
	    .giftFlag = 0,
	    .genericStartIndex = 129,
	    .genericTextsAmount = 5,
		.outbreakData = qwilfishOutbreakData,
	    .callTexts = {{Matchcall_Ralph_Call, STRS_NORMAL_MSG},
	    				 {Matchcall_Ralph_Call, STRS_NORMAL_MSG},
						 {Matchcall_Ralph_Call, STRS_NORMAL_MSG}},
	    .answerTexts = {{Matchcall_Ralph_Answer, STRS_NORMAL_MSG},
	    				   {Matchcall_Ralph_Answer, STRS_NORMAL_MSG},
						   {Matchcall_Ralph_Answer, STRS_NORMAL_MSG}},
	    .giftText = 0,
	    .rematchText = {Matchcall_Ralph_Rematch, STRS_BATTLE_REQUEST},
	    .outbreakText = {Matchcall_Ralph_Swarm, STRS_SWARM_MSG},
	    .remindGiftText = 0,
	    .remindRematchText = {Matchcall_Ralph_Remind_Rematch, STRS_BATTLE_REQUEST},
	    .remindoutbreakText = {Matchcall_Ralph_Remind_Swarm, STRS_SWARM_MSG},
		.hangupText = {Matchcall_Ralph_Hangup, STRS_NORMAL_MSG},
		.rematchAvailability = {DAY_WEDNESDAY, TIME_MORNING},

    },
    {
        .trainerId = TRAINER_ARNIE_1,
        .unused = 0,
        .battleFrontierRecordStreakTextIndex = 2,
	    .rematchOfferedFlag = FLAG_ARNIE_OFFERED_REMATCH,
		.rematchCheckFlags = {FLAG_VISITED_BLACKTHORN_CITY, FLAG_IS_CHAMPION, FLAG_RETURNED_MACHINE_PART, FALSE},
	    .giftFlag = 0,
	    .genericStartIndex = 11,
	    .genericTextsAmount = 5,
		.outbreakData = yanmaOutbreakData,
	    .callTexts = {{Matchcall_Arnie_Call_Morn, STRS_NORMAL_MSG},
	    				 {Matchcall_Arnie_Call_Day, STRS_NORMAL_MSG},
						 {Matchcall_Arnie_Call_Night, STRS_NORMAL_MSG}},
	    .answerTexts = {{Matchcall_Arnie_Answer_Morn, STRS_NORMAL_MSG},
	    				   {Matchcall_Arnie_Answer_Day, STRS_NORMAL_MSG},
						   {Matchcall_Arnie_Answer_Night, STRS_NORMAL_MSG}},
	    .giftText = 0,
	    .rematchText = {Matchcall_Arnie_Rematch, STRS_BATTLE_REQUEST},
	    .outbreakText = {Matchcall_Arnie_Swarm, STRS_SWARM_MSG},
	    .remindGiftText = 0,
	    .remindRematchText = {Matchcall_Arnie_Remind_Rematch, STRS_BATTLE_REQUEST},
	    .remindoutbreakText = {Matchcall_Arnie_Remind_Swarm, STRS_SWARM_MSG},
		.hangupText = {Matchcall_Arnie_Hangup, STRS_NORMAL_MSG},
		.rematchAvailability = {DAY_TUESDAY, TIME_MORNING},
    },
    {
        .trainerId = TRAINER_DANA_1,
        .unused = 0,
        .battleFrontierRecordStreakTextIndex = 1,
	    .rematchOfferedFlag = FLAG_DANA_OFFERED_REMATCH,
		.rematchCheckFlags = {FLAG_VISITED_CIANWOOD_CITY, FLAG_CLEARED_RADIO_TOWER, FLAG_IS_CHAMPION, FLAG_RETURNED_MACHINE_PART},
	    .giftFlag = FLAG_CALL_DANA_GIFT,
	    .genericStartIndex = 55,
	    .genericTextsAmount = 5,
		.outbreakData = outbreakNone,
	    .callTexts = {{Matchcall_Dana_Call, STRS_NORMAL_MSG},
	    				 {Matchcall_Dana_Call, STRS_NORMAL_MSG},
						 {Matchcall_Dana_Call, STRS_NORMAL_MSG}},
	    .answerTexts = {{Matchcall_Dana_Answer_Morn, STRS_NORMAL_MSG},
	    				   {Matchcall_Dana_Answer_Day, STRS_NORMAL_MSG},
						   {Matchcall_Dana_Answer_Night, STRS_NORMAL_MSG}},
	    .giftText = {Matchcall_Dana_Gift, STRS_GIFT_MSG},
	    .rematchText = {Matchcall_Dana_Rematch, STRS_BATTLE_REQUEST},
	    .outbreakText = 0,
	    .remindGiftText = {Matchcall_Dana_Remind_Gift, STRS_GIFT_MSG},
	    .remindRematchText = {Matchcall_Anthony_Remind_Rematch, STRS_BATTLE_REQUEST},
	    .remindoutbreakText = 0,
		.hangupText = {Matchcall_Dana_Hangup, STRS_NORMAL_MSG},
		.rematchAvailability = {DAY_THURSDAY, TIME_NIGHT},
    },
    {
        .trainerId = TRAINER_JOEY_1,
        .unused = 4,
        .battleFrontierRecordStreakTextIndex = 1,
	    .rematchOfferedFlag = FLAG_JOEY_OFFERED_REMATCH,
		.rematchCheckFlags = {FLAG_VISITED_CIANWOOD_CITY, FLAG_VISITED_OLIVINE_CITY, FLAG_CLEARED_RADIO_TOWER, FLAG_IS_CHAMPION},
	    .giftFlag = 0,
	    .genericStartIndex = 97,
	    .genericTextsAmount = 5,
		.outbreakData = outbreakNone,
	    .callTexts = {{Matchcall_Joey_Call_Morn, STRS_NORMAL_MSG},
	    				 {Matchcall_Joey_Call_Day, STRS_NORMAL_MSG},
						 {Matchcall_Joey_Call_Night, STRS_NORMAL_MSG}},
	    .answerTexts = {{Matchcall_Joey_Answer, STRS_NORMAL_MSG},
	    				   {Matchcall_Joey_Answer, STRS_NORMAL_MSG},
						   {Matchcall_Joey_Answer, STRS_NORMAL_MSG}},
	    .giftText = 0,
	    .rematchText = {Matchcall_Joey_Rematch, STRS_BATTLE_REQUEST},
	    .outbreakText = 0,
	    .remindGiftText = 0,
	    .remindRematchText = {Matchcall_Joey_Remind_Rematch, STRS_BATTLE_REQUEST},
	    .remindoutbreakText = 0,
		.hangupText = {Matchcall_Joey_Hangup, STRS_NORMAL_MSG},
		.rematchAvailability = {DAY_MONDAY, TIME_DAY},
    },
    {
        .trainerId = TRAINER_TODD_1,
        .unused = 0,
        .battleFrontierRecordStreakTextIndex = 10,
	    .rematchOfferedFlag = FLAG_TODD_OFFERED_REMATCH,
		.rematchCheckFlags = {FLAG_VISITED_CIANWOOD_CITY, FLAG_VISITED_BLACKTHORN_CITY, FLAG_IS_CHAMPION, FLAG_RETURNED_MACHINE_PART},
	    .giftFlag = 0,
	    .genericStartIndex = 165,
	    .genericTextsAmount = 5,
		.outbreakData = outbreakNone,
	    .callTexts = {{Matchcall_Todd_Call_Morn, STRS_NORMAL_MSG},
	    				 {Matchcall_Todd_Call_Day, STRS_NORMAL_MSG},
						 {Matchcall_Todd_Call_Night, STRS_NORMAL_MSG}},
	    .answerTexts = {{Matchcall_Todd_Answer_Morn, STRS_NORMAL_MSG},
	    				   {Matchcall_Todd_Answer_Day, STRS_NORMAL_MSG},
						   {Matchcall_Todd_Answer_Night, STRS_NORMAL_MSG}},
	    .giftText = 0,
	    .rematchText = {Matchcall_Todd_Rematch, STRS_BATTLE_REQUEST},
	    .outbreakText = 0,
	    .remindGiftText = 0,
	    .remindRematchText = {Matchcall_Todd_Remind_Rematch, STRS_BATTLE_REQUEST},
	    .remindoutbreakText = 0,
		.hangupText = {Matchcall_Todd_Hangup, STRS_NORMAL_MSG},
		.rematchAvailability = {DAY_SUNDAY, TIME_MORNING},
    },
    {
        .trainerId = TRAINER_GINA_1,
        .unused = 0,
        .battleFrontierRecordStreakTextIndex = 9,
	    .rematchOfferedFlag = FLAG_GINA_OFFERED_REMATCH,
		.rematchCheckFlags = {FLAG_VISITED_MAHOGANY_TOWN, FLAG_CLEARED_RADIO_TOWER, FLAG_IS_CHAMPION, FLAG_RETURNED_MACHINE_PART},
	    .giftFlag = FLAG_CALL_GINA_GIFT,
	    .genericStartIndex = 75,
	    .genericTextsAmount = 5,
		.outbreakData = outbreakNone,
	    .callTexts = {{Matchcall_Gina_Call_Morn, STRS_NORMAL_MSG},
	    				 {Matchcall_Gina_Call_Day, STRS_NORMAL_MSG},
						 {Matchcall_Gina_Call_Night, STRS_NORMAL_MSG}},
	    .answerTexts = {{Matchcall_Gina_Answer_Morn, STRS_NORMAL_MSG},
	    				   {Matchcall_Gina_Answer_Day, STRS_NORMAL_MSG},
						   {Matchcall_Gina_Answer_Night, STRS_NORMAL_MSG}},
	    .giftText = {Matchcall_Gina_Gift, STRS_GIFT_MSG},
	    .rematchText = {Matchcall_Gina_Rematch, STRS_BATTLE_REQUEST},
	    .outbreakText = 0,
	    .remindGiftText = {Matchcall_Gina_Remind_Gift, STRS_GIFT_MSG},
	    .remindRematchText = {Matchcall_Gina_Remind_Rematch, STRS_BATTLE_REQUEST},
	    .remindoutbreakText = 0,
		.hangupText = {Matchcall_Gina_Hangup, STRS_NORMAL_MSG},
		.rematchAvailability = {DAY_SUNDAY, TIME_DAY},
    },
    {
        .trainerId = TRAINER_ALAN_1,
        .unused = 0,
        .battleFrontierRecordStreakTextIndex = 8,
	    .rematchOfferedFlag = FLAG_ALAN_OFFERED_REMATCH,
		.rematchCheckFlags = {FLAG_VISITED_OLIVINE_CITY, FLAG_VISITED_BLACKTHORN_CITY, FLAG_IS_CHAMPION, FLAG_RETURNED_MACHINE_PART},
	    .giftFlag = FLAG_CALL_ALAN_GIFT,
	    .genericStartIndex = 0,
	    .genericTextsAmount = 5,
		.outbreakData = outbreakNone,
	    .callTexts = {{Matchcall_Alan_Call, STRS_NORMAL_MSG},
	    				 {Matchcall_Alan_Call, STRS_NORMAL_MSG},
						 {Matchcall_Alan_Call, STRS_NORMAL_MSG}},
	    .answerTexts = {{Matchcall_Alan_Answer_Morn, STRS_NORMAL_MSG},
	    				   {Matchcall_Alan_Answer_Day, STRS_NORMAL_MSG},
						   {Matchcall_Alan_Answer_Night, STRS_NORMAL_MSG}},
	    .giftText = {Matchcall_Alan_Gift, STRS_GIFT_MSG},
	    .rematchText = {Matchcall_Alan_Rematch, STRS_BATTLE_REQUEST},
	    .outbreakText = 0,
	    .remindGiftText = {Matchcall_Alan_Remind_Gift, STRS_GIFT_MSG},
	    .remindRematchText = {Matchcall_Alan_Remind_Rematch, STRS_BATTLE_REQUEST},
	    .remindoutbreakText = 0,
		.hangupText = {Matchcall_Alan_Hangup, STRS_NORMAL_MSG},
		.rematchAvailability = {DAY_WEDNESDAY, TIME_DAY},
    },
    {
        .trainerId = TRAINER_VANCE_1,
        .unused = 0,
        .battleFrontierRecordStreakTextIndex = 8,
	    .rematchOfferedFlag = FLAG_VANCE_OFFERED_REMATCH,
		.rematchCheckFlags = {FLAG_IS_CHAMPION, FLAG_RETURNED_MACHINE_PART, FALSE, FALSE},
	    .giftFlag = 0,
	    .genericStartIndex = 150,
	    .genericTextsAmount = 5,
		.outbreakData = outbreakNone,
	    .callTexts = {{Matchcall_Vance_Call_Morn, STRS_NORMAL_MSG},
	    				 {Matchcall_Vance_Call_Day, STRS_NORMAL_MSG},
						 {Matchcall_Vance_Call_Night, STRS_NORMAL_MSG}},
	    .answerTexts = {{Matchcall_Vance_Answer_Morn, STRS_NORMAL_MSG},
	    				   {Matchcall_Vance_Answer_Day, STRS_NORMAL_MSG},
						   {Matchcall_Vance_Answer_Night, STRS_NORMAL_MSG}},
	    .giftText = 0,
	    .rematchText = {Matchcall_Vance_Rematch, STRS_BATTLE_REQUEST},
	    .outbreakText = 0,
	    .remindGiftText = 0,
	    .remindRematchText = {Matchcall_Vance_Remind_Rematch, STRS_BATTLE_REQUEST},
	    .remindoutbreakText = 0,
		.hangupText = {Matchcall_Vance_Hangup, STRS_NORMAL_MSG},
		.rematchAvailability = {DAY_WEDNESDAY, TIME_NIGHT},
    },
    {
        .trainerId = TRAINER_TULLY_1,
        .unused = 0,
        .battleFrontierRecordStreakTextIndex = 10,
	    .rematchOfferedFlag = FLAG_TULLY_OFFERED_REMATCH,
		.rematchCheckFlags = {FLAG_CLEARED_RADIO_TOWER, FLAG_IS_CHAMPION, FLAG_RETURNED_MACHINE_PART, FALSE},
	    .giftFlag = FLAG_CALL_TULLY_GIFT,
	    .genericStartIndex = 145,
	    .genericTextsAmount = 5,
		.outbreakData = outbreakNone,
	    .callTexts = {{Matchcall_Tully_Call_Morn, STRS_NORMAL_MSG},
	    				 {Matchcall_Tully_Call_Day, STRS_NORMAL_MSG},
						 {Matchcall_Tully_Call_Night, STRS_NORMAL_MSG}},
	    .answerTexts = {{Matchcall_Tully_Answer_Morn, STRS_NORMAL_MSG},
	    				   {Matchcall_Tully_Answer_Day, STRS_NORMAL_MSG},
						   {Matchcall_Tully_Answer_Night, STRS_NORMAL_MSG}},
	    .giftText = {Matchcall_Tully_Gift, STRS_GIFT_MSG},
	    .rematchText = {Matchcall_Tully_Rematch, STRS_BATTLE_REQUEST},
	    .outbreakText = 0,
	    .remindGiftText = {Matchcall_Tully_Remind_Gift, STRS_GIFT_MSG},
	    .remindRematchText = {Matchcall_Tully_Remind_Rematch, STRS_BATTLE_REQUEST},
	    .remindoutbreakText = 0,
		.hangupText = {Matchcall_Tully_Hangup, STRS_NORMAL_MSG},
		.rematchAvailability = {DAY_SUNDAY, TIME_NIGHT},
    },
    {
        .trainerId = TRAINER_HUEY_1,
        .unused = 0,
        .battleFrontierRecordStreakTextIndex = 10,
	    .rematchOfferedFlag = FLAG_HUEY_OFFERED_REMATCH,
		.rematchCheckFlags = {FLAG_CLEARED_RADIO_TOWER, FLAG_IS_CHAMPION, FLAG_RETURNED_MACHINE_PART, FALSE},
	    .giftFlag = 0,
	    .genericStartIndex = 80,
	    .genericTextsAmount = 1,
		.outbreakData = outbreakNone,
	    .callTexts = {{Matchcall_Huey_Call_Morn, STRS_NORMAL_MSG},
	    				 {Matchcall_Huey_Call_Day, STRS_NORMAL_MSG},
						 {Matchcall_Huey_Call_Night, STRS_NORMAL_MSG}},
	    .answerTexts = {{Matchcall_Huey_Answer, STRS_NORMAL_MSG},
	    				   {Matchcall_Huey_Answer, STRS_NORMAL_MSG},
						   {Matchcall_Huey_Answer, STRS_NORMAL_MSG}},
	    .giftText = 0,
	    .rematchText = {Matchcall_Huey_Rematch, STRS_BATTLE_REQUEST},
	    .outbreakText = 0,
	    .remindGiftText = 0,
	    .remindRematchText = {Matchcall_Huey_Remind_Rematch, STRS_BATTLE_REQUEST},
	    .remindoutbreakText = 0,
		.hangupText = {Matchcall_Huey_Hangup, STRS_NORMAL_MSG},
		.rematchAvailability = {DAY_WEDNESDAY, TIME_NIGHT},
    },
    {
        .trainerId = TRAINER_TIFFANY_1,
        .unused = 0,
        .battleFrontierRecordStreakTextIndex = 4,
	    .rematchOfferedFlag = FLAG_TIFFANY_OFFERED_REMATCH,
		.rematchCheckFlags = {FLAG_CLEARED_RADIO_TOWER, FLAG_IS_CHAMPION, FLAG_RETURNED_MACHINE_PART, FALSE},
	    .giftFlag = FLAG_CALL_TIFFANY_GIFT,
	    .genericStartIndex = 139,
	    .genericTextsAmount = 5,
		.outbreakData = outbreakNone,
	    .callTexts = {{Matchcall_Tiffany_Call_Morn, STRS_NORMAL_MSG},
	    				 {Matchcall_Tiffany_Call_Day, STRS_NORMAL_MSG},
						 {Matchcall_Tiffany_Call_Night, STRS_NORMAL_MSG}},
	    .answerTexts = {{Matchcall_Tiffany_Answer_Morn, STRS_NORMAL_MSG},
	    				   {Matchcall_Tiffany_Answer_Day, STRS_NORMAL_MSG},
						   {Matchcall_Tiffany_Answer_Night, STRS_NORMAL_MSG}},
	    .giftText = {Matchcall_Tiffany_Gift, STRS_GIFT_MSG},
	    .rematchText = {Matchcall_Tiffany_Rematch, STRS_BATTLE_REQUEST},
	    .outbreakText = 0,
	    .remindGiftText = {Matchcall_Tiffany_Remind_Gift, STRS_GIFT_MSG},
	    .remindRematchText = 0,
	    .remindoutbreakText = 0,
		.hangupText = {Matchcall_Tiffany_Hangup, STRS_NORMAL_MSG},
		.rematchAvailability = {DAY_TUESDAY, TIME_DAY},
    },
    {
        .trainerId = TRAINER_ERIN_1,
        .unused = 0,
        .battleFrontierRecordStreakTextIndex = 5,
	    .rematchOfferedFlag = FLAG_ERIN_OFFERED_REMATCH,
		.rematchCheckFlags = {FLAG_IS_CHAMPION, FLAG_RETURNED_MACHINE_PART, FALSE, FALSE},
	    .giftFlag = 0,
	    .genericStartIndex = 65,
	    .genericTextsAmount = 5,
		.outbreakData = outbreakNone,
	    .callTexts = {{Matchcall_Erin_Call_Morn, STRS_NORMAL_MSG},
	    				 {Matchcall_Erin_Call_Day, STRS_NORMAL_MSG},
						 {Matchcall_Erin_Call_Night, STRS_NORMAL_MSG}},
	    .answerTexts = {{Matchcall_Erin_Answer_Morn, STRS_NORMAL_MSG},
	    				   {Matchcall_Erin_Answer_Day, STRS_NORMAL_MSG},
						   {Matchcall_Erin_Answer_Night, STRS_NORMAL_MSG}},
	    .giftText = 0,
	    .rematchText = {Matchcall_Erin_Rematch, STRS_BATTLE_REQUEST},
	    .outbreakText = 0,
	    .remindGiftText = 0,
	    .remindRematchText = {Matchcall_Erin_Remind_Rematch, STRS_BATTLE_REQUEST},
	    .remindoutbreakText = 0,
		.hangupText = {Matchcall_Erin_Hangup, STRS_NORMAL_MSG},
		.rematchAvailability = {DAY_SATURDAY, TIME_NIGHT},
    },
    {
        .trainerId = TRAINER_JOSE_1,
        .unused = 0,
        .battleFrontierRecordStreakTextIndex = 3,
	    .rematchOfferedFlag = FLAG_JOSE_OFFERED_REMATCH,
		.rematchCheckFlags = {FLAG_IS_CHAMPION, FLAG_RETURNED_MACHINE_PART, FALSE, FALSE},
	    .giftFlag = FLAG_CALL_JOSE_GIFT,
	    .genericStartIndex = 102,
	    .genericTextsAmount = 5,
		.outbreakData = outbreakNone,
	    .callTexts = {{Matchcall_Jose_Call, STRS_NORMAL_MSG},
	    				 {Matchcall_Jose_Call, STRS_NORMAL_MSG},
						 {Matchcall_Jose_Call, STRS_NORMAL_MSG}},
	    .answerTexts = {{Matchcall_Jose_Answer_Morn, STRS_NORMAL_MSG},
	    				   {Matchcall_Jose_Answer_Day, STRS_NORMAL_MSG},
						   {Matchcall_Jose_Answer_Night, STRS_NORMAL_MSG}},
	    .giftText = {Matchcall_Jose_Gift, STRS_GIFT_MSG},
	    .rematchText = {Matchcall_Jose_Rematch, STRS_BATTLE_REQUEST},
	    .outbreakText = 0,
	    .remindGiftText = {Matchcall_Jose_Remind_Gift, STRS_GIFT_MSG},
	    .remindRematchText = {Matchcall_Jose_Remind_Rematch, STRS_BATTLE_REQUEST},
	    .remindoutbreakText = 0,
		.hangupText = {Matchcall_Jose_Hangup, STRS_NORMAL_MSG},
		.rematchAvailability = {DAY_SATURDAY, TIME_NIGHT},
    },
    {
        .trainerId = TRAINER_JACK_1,
        .unused = 0,
        .battleFrontierRecordStreakTextIndex = 3,
	    .rematchOfferedFlag = FLAG_JACK_OFFERED_REMATCH,
		.rematchCheckFlags = {FLAG_VISITED_OLIVINE_CITY, FLAG_IS_CHAMPION, FLAG_RETURNED_MACHINE_PART, FALSE},
	    .giftFlag = 0,
	    .genericStartIndex = 81,
	    .genericTextsAmount = 16,
		.outbreakData = outbreakNone,
	    .callTexts = {{Matchcall_Jack_Call_Morn, STRS_NORMAL_MSG},
	    				 {Matchcall_Jack_Call_Day, STRS_NORMAL_MSG},
						 {Matchcall_Jack_Call_Night, STRS_NORMAL_MSG}},
	    .answerTexts = {{Matchcall_Jack_Answer_Morn, STRS_NORMAL_MSG},
	    				   {Matchcall_Jack_Answer_Day, STRS_NORMAL_MSG},
						   {Matchcall_Jack_Answer_Night, STRS_NORMAL_MSG}},
	    .giftText = 0,
	    .rematchText = {Matchcall_Jack_Rematch, STRS_BATTLE_REQUEST},
	    .outbreakText = 0,
	    .remindGiftText = 0,
	    .remindRematchText = {Matchcall_Jack_Remind_Rematch, STRS_BATTLE_REQUEST},
	    .remindoutbreakText = 0,
		.hangupText = {Matchcall_Jack_Hangup, STRS_NORMAL_MSG},
		.rematchAvailability = {DAY_MONDAY, TIME_MORNING},
    },
    {
        .trainerId = TRAINER_REENA_1,
        .unused = 0,
        .battleFrontierRecordStreakTextIndex = 6,
	    .rematchOfferedFlag = FLAG_REENA_OFFERED_REMATCH,
		.rematchCheckFlags = {FLAG_IS_CHAMPION, FLAG_RETURNED_MACHINE_PART, FALSE, FALSE},
	    .giftFlag = 0,
	    .genericStartIndex = 134,
	    .genericTextsAmount = 5,
		.outbreakData = outbreakNone,
	    .callTexts = {{Matchcall_Reena_Call, STRS_NORMAL_MSG},
	    				 {Matchcall_Reena_Call, STRS_NORMAL_MSG},
						 {Matchcall_Reena_Call, STRS_NORMAL_MSG}},
	    .answerTexts = {{Matchcall_Reena_Answer, STRS_NORMAL_MSG},
	    				   {Matchcall_Reena_Answer, STRS_NORMAL_MSG},
						   {Matchcall_Reena_Answer, STRS_NORMAL_MSG}},
	    .giftText = 0,
	    .rematchText = {Matchcall_Reena_Rematch, STRS_BATTLE_REQUEST},
	    .outbreakText = 0,
	    .remindGiftText = 0,
	    .remindRematchText = {Matchcall_Reena_Remind_Rematch, STRS_BATTLE_REQUEST},
	    .remindoutbreakText = 0,
		.hangupText = {Matchcall_Reena_Hangup, STRS_NORMAL_MSG},
		.rematchAvailability = {DAY_SUNDAY, TIME_MORNING},
    },
    {
        .trainerId = TRAINER_GAVEN_1,
        .unused = 0,
        .battleFrontierRecordStreakTextIndex = 4,
	    .rematchOfferedFlag = FLAG_GAVEN_OFFERED_REMATCH,
		.rematchCheckFlags = {FLAG_IS_CHAMPION, FLAG_RETURNED_MACHINE_PART, FALSE, FALSE},
	    .giftFlag = 0,
	    .genericStartIndex = 70,
	    .genericTextsAmount = 5,
		.outbreakData = outbreakNone,
	    .callTexts = {{Matchcall_Gaven_Call_Morn, STRS_NORMAL_MSG},
	    				 {Matchcall_Gaven_Call_Day, STRS_NORMAL_MSG},
						 {Matchcall_Gaven_Call_Night, STRS_NORMAL_MSG}},
	    .answerTexts = {{Matchcall_Gaven_Answer_Morn, STRS_NORMAL_MSG},
	    				   {Matchcall_Gaven_Answer_Day, STRS_NORMAL_MSG},
						   {Matchcall_Gaven_Answer_Night, STRS_NORMAL_MSG}},
	    .giftText = 0,
	    .rematchText = {Matchcall_Gaven_Rematch, STRS_BATTLE_REQUEST},
	    .outbreakText = 0,
	    .remindGiftText = 0,
	    .remindRematchText = {Matchcall_Gaven_Remind_Rematch, STRS_BATTLE_REQUEST},
	    .remindoutbreakText = 0,
		.hangupText = {Matchcall_Gaven_Hangup, STRS_NORMAL_MSG},
		.rematchAvailability = {DAY_THURSDAY, TIME_MORNING},
    },
    {
        .trainerId = TRAINER_BETH_1,
        .unused = 0,
        .battleFrontierRecordStreakTextIndex = 11,
	    .rematchOfferedFlag = FLAG_BETH_OFFERED_REMATCH,
		.rematchCheckFlags = {FLAG_IS_CHAMPION, FLAG_RETURNED_MACHINE_PART, FALSE, FALSE},
	    .giftFlag = 0,
	    .genericStartIndex = 15,
	    .genericTextsAmount = 5,
		.outbreakData = outbreakNone,
	    .callTexts = {{Matchcall_Beth_Call_Morn, STRS_NORMAL_MSG},
	    				 {Matchcall_Beth_Call_Day, STRS_NORMAL_MSG},
						 {Matchcall_Beth_Call_Night, STRS_NORMAL_MSG}},
	    .answerTexts = {{Matchcall_Beth_Answer_Morn, STRS_NORMAL_MSG},
	    				   {Matchcall_Beth_Answer_Day, STRS_NORMAL_MSG},
						   {Matchcall_Beth_Answer_Night, STRS_NORMAL_MSG}},
	    .giftText = 0,
	    .rematchText = {Matchcall_Beth_Rematch, STRS_BATTLE_REQUEST},
	    .outbreakText = 0,
	    .remindGiftText = {Matchcall_Beth_Remind_Gift, STRS_GIFT_MSG},
	    .remindRematchText = 0,
	    .remindoutbreakText = 0,
		.hangupText = {Matchcall_Beth_Hangup, STRS_NORMAL_MSG},
		.rematchAvailability = {DAY_FRIDAY, TIME_DAY},
    },
    {
        .trainerId = TRAINER_WADE_1,
        .unused = 0,
        .battleFrontierRecordStreakTextIndex = 1,
	    .rematchOfferedFlag = FLAG_WADE_OFFERED_REMATCH,
		.rematchCheckFlags = {FLAG_VISITED_CIANWOOD_CITY, FLAG_VISITED_MAHOGANY_TOWN, FLAG_CLEARED_RADIO_TOWER, FLAG_IS_CHAMPION},
	    .giftFlag = FLAG_CALL_WADE_GIFT,
	    .genericStartIndex = 155,
	    .genericTextsAmount = 5,
		.outbreakData = outbreakNone,
	    .callTexts = {{Matchcall_Wade_Call_Morn, STRS_NORMAL_MSG},
	    				 {Matchcall_Wade_Call_Day, STRS_NORMAL_MSG},
						 {Matchcall_Wade_Call_Night, STRS_NORMAL_MSG}},
	    .answerTexts = {{Matchcall_Wade_Answer_Morn, STRS_NORMAL_MSG},
	    				   {Matchcall_Wade_Answer_Day, STRS_NORMAL_MSG},
						   {Matchcall_Wade_Answer_Night, STRS_NORMAL_MSG}},
	    .giftText = {Matchcall_Wade_Gift, STRS_GIFT_MSG},
	    .rematchText = {Matchcall_Wade_Rematch, STRS_BATTLE_REQUEST},
	    .outbreakText = 0,
	    .remindGiftText = {Matchcall_Wade_Remind_Gift, STRS_GIFT_MSG},
	    .remindRematchText = {Matchcall_Wade_Remind_Rematch, STRS_BATTLE_REQUEST},
	    .remindoutbreakText = 0,
		.hangupText = {Matchcall_Wade_Hangup, STRS_NORMAL_MSG},
		.rematchAvailability = {DAY_TUESDAY, TIME_NIGHT},
    },
    {
        .trainerId = TRAINER_LIZ_1,
        .unused = 3,
        .battleFrontierRecordStreakTextIndex = 12,
	    .rematchOfferedFlag = FLAG_LIZ_OFFERED_REMATCH,
		.rematchCheckFlags = {FLAG_VISITED_ECRUTEAK_CITY, FLAG_VISITED_MAHOGANY_TOWN, FLAG_CLEARED_RADIO_TOWER, FLAG_IS_CHAMPION},
	    .giftFlag = 0,
	    .genericStartIndex = 107,
	    .genericTextsAmount = 16,
		.outbreakData = outbreakNone,
	    .callTexts = {{Matchcall_Liz_Call_Morn, STRS_NORMAL_MSG},
	    				 {Matchcall_Liz_Call_Day, STRS_NORMAL_MSG},
						 {Matchcall_Liz_Call_Night, STRS_NORMAL_MSG}},
	    .answerTexts = {{Matchcall_Liz_Answer_Morn, STRS_NORMAL_MSG},
	    				   {Matchcall_Liz_Answer_Day, STRS_NORMAL_MSG},
						   {Matchcall_Liz_Answer_Night, STRS_NORMAL_MSG}},
	    .giftText = 0,
	    .rematchText = {Matchcall_Liz_Rematch, STRS_BATTLE_REQUEST},
	    .outbreakText = 0,
	    .remindGiftText = 0,
	    .remindRematchText = {Matchcall_Liz_Remind_Rematch, STRS_BATTLE_REQUEST},
	    .remindoutbreakText = 0,
		.hangupText = {Matchcall_Liz_Hangup, STRS_NORMAL_MSG},
		.rematchAvailability = {DAY_THURSDAY, TIME_DAY},
    },
    {
        .trainerId = TRAINER_BRENT_1,
        .unused = 0,
        .battleFrontierRecordStreakTextIndex = 12,
	    .rematchOfferedFlag = FLAG_BRENT_OFFERED_REMATCH,
		.rematchCheckFlags = {FLAG_VISITED_MAHOGANY_TOWN, FLAG_IS_CHAMPION, FLAG_RETURNED_MACHINE_PART, FALSE},
	    .giftFlag = 0,
	    .genericStartIndex = 25,
	    .genericTextsAmount = 15,
		.outbreakData = outbreakNone,
	    .callTexts = {{Matchcall_Brent_Call, STRS_NORMAL_MSG},
	    				 {Matchcall_Brent_Call, STRS_NORMAL_MSG},
						 {Matchcall_Brent_Call, STRS_NORMAL_MSG}},
	    .answerTexts = {{Matchcall_Brent_Answer, STRS_NORMAL_MSG},
	    				   {Matchcall_Brent_Answer, STRS_NORMAL_MSG},
						   {Matchcall_Brent_Answer, STRS_NORMAL_MSG}},
	    .giftText = 0,
	    .rematchText = {Matchcall_Brent_Rematch, STRS_BATTLE_REQUEST},
	    .outbreakText = 0,
	    .remindGiftText = 0,
	    .remindRematchText = {Matchcall_Brent_Remind_Rematch, STRS_BATTLE_REQUEST},
	    .remindoutbreakText = 0,
		.hangupText = {Matchcall_Brent_Hangup, STRS_NORMAL_MSG},
		.rematchAvailability = {DAY_MONDAY, TIME_MORNING},
    },
	{
	    .trainerId = TRAINER_CHAD_1,
	    .unused = 0,
	    .battleFrontierRecordStreakTextIndex = 8,
	    .rematchOfferedFlag = FLAG_CHAD_OFFERED_REMATCH,
		.rematchCheckFlags = {FLAG_VISITED_MAHOGANY_TOWN, FLAG_CLEARED_RADIO_TOWER, FLAG_IS_CHAMPION, FLAG_RETURNED_MACHINE_PART},
	    .giftFlag = 0,
	    .genericStartIndex = 40,
	    .genericTextsAmount = 15,
		.outbreakData = outbreakNone,
	    .callTexts = {{Matchcall_Chad_Call_Morn, STRS_NORMAL_MSG},
	    				 {Matchcall_Chad_Call_Day, STRS_NORMAL_MSG},
						 {Matchcall_Chad_Call_Night, STRS_NORMAL_MSG}},
	    .answerTexts = {{Matchcall_Chad_Answer_Morn, STRS_NORMAL_MSG},
	    				   {Matchcall_Chad_Answer_Day, STRS_NORMAL_MSG},
						   {Matchcall_Chad_Answer_Night, STRS_NORMAL_MSG}},
	    .giftText = 0,
	    .rematchText = {Matchcall_Chad_Rematch, STRS_BATTLE_REQUEST},
	    .outbreakText = 0,
	    .remindGiftText = 0,
	    .remindRematchText = {Matchcall_Chad_Remind_Rematch, STRS_BATTLE_REQUEST},
	    .remindoutbreakText = 0,
		.hangupText = {Matchcall_Chad_Hangup, STRS_NORMAL_MSG},
		.rematchAvailability = {DAY_FRIDAY, TIME_MORNING},
	},
    {
        .trainerId = TRAINER_WILTON_1,
        .unused = 0,
        .battleFrontierRecordStreakTextIndex = 2,
	    .rematchOfferedFlag = FLAG_WILTON_OFFERED_REMATCH,
		.rematchCheckFlags = {FLAG_IS_CHAMPION, FLAG_RETURNED_MACHINE_PART, FALSE, FALSE},
	    .giftFlag = FLAG_CALL_WILTON_GIFT,
	    .genericStartIndex = 160,
	    .genericTextsAmount = 5,
		.outbreakData = outbreakNone,
	    .callTexts = {{Matchcall_Wilton_Call_Morn, STRS_NORMAL_MSG},
	    				 {Matchcall_Wilton_Call_Day, STRS_NORMAL_MSG},
						 {Matchcall_Wilton_Call_Night, STRS_NORMAL_MSG}},
	    .answerTexts = {{Matchcall_Wilton_Answer_Morn, STRS_NORMAL_MSG},
	    				   {Matchcall_Wilton_Answer_Day, STRS_NORMAL_MSG},
						   {Matchcall_Wilton_Answer_Night, STRS_NORMAL_MSG}},
	    .giftText = {Matchcall_Wilton_Gift, STRS_GIFT_MSG},
	    .rematchText = {Matchcall_Wilton_Rematch, STRS_BATTLE_REQUEST},
	    .outbreakText = 0,
	    .remindGiftText = {Matchcall_Wilton_Remind_Gift, STRS_GIFT_MSG},
	    .remindRematchText = {Matchcall_Wilton_Remind_Rematch, STRS_BATTLE_REQUEST},
	    .remindoutbreakText = 0,
		.hangupText = {Matchcall_Wilton_Hangup, STRS_NORMAL_MSG},
		.rematchAvailability = {DAY_THURSDAY, TIME_MORNING},
    },
    {
        .trainerId = TRAINER_PARRY_1,
        .unused = 0,
        .battleFrontierRecordStreakTextIndex = 1,
	    .rematchOfferedFlag = FLAG_PARRY_OFFERED_REMATCH,
		.rematchCheckFlags = {FLAG_IS_CHAMPION, FLAG_RETURNED_MACHINE_PART, FALSE, FALSE},
	    .giftFlag = 0,
	    .genericStartIndex = 123,
	    .genericTextsAmount = 5,
		.outbreakData = outbreakNone,
	    .callTexts = {{Matchcall_Parry_Call_Morn, STRS_NORMAL_MSG},
	    				 {Matchcall_Parry_Call_Day, STRS_NORMAL_MSG},
						 {Matchcall_Parry_Call_Night, STRS_NORMAL_MSG}},
	    .answerTexts = {{Matchcall_Parry_Answer, STRS_NORMAL_MSG},
	    				   {Matchcall_Parry_Answer, STRS_NORMAL_MSG},
						   {Matchcall_Parry_Answer, STRS_NORMAL_MSG}},
	    .giftText = 0,
	    .rematchText = {Matchcall_Parry_Rematch, STRS_BATTLE_REQUEST},
	    .outbreakText = 0,
	    .remindGiftText = 0,
	    .remindRematchText = {Matchcall_Parry_Remind_Rematch, STRS_BATTLE_REQUEST},
	    .remindoutbreakText = 0,
		.hangupText = {Matchcall_Parry_Hangup, STRS_NORMAL_MSG},
		.rematchAvailability = {DAY_FRIDAY, TIME_DAY},
    },{
		.trainerId = TRAINER_BEVERLY,
		.unused = 0,
		.battleFrontierRecordStreakTextIndex = 6,
		.rematchOfferedFlag = 0,
		.rematchCheckFlags = 0,
		.giftFlag = FLAG_CALL_BEVERLY_GIFT,
		.genericStartIndex = 20,
		.genericTextsAmount = 5,
		.outbreakData = outbreakNone,
		.callTexts = {{Matchcall_Beverly_Call_Morn, STRS_NORMAL_MSG},
						 {Matchcall_Beverly_Call_Day, STRS_NORMAL_MSG},
						 {Matchcall_Beverly_Call_Night, STRS_NORMAL_MSG}},
		.answerTexts = {{Matchcall_Beverly_Answer_Morn, STRS_NORMAL_MSG},
						   {Matchcall_Beverly_Answer_Day, STRS_NORMAL_MSG},
						   {Matchcall_Beverly_Answer_Night, STRS_NORMAL_MSG}},
		.giftText = {Matchcall_Beverly_Gift, STRS_GIFT_MSG},
		.rematchText = 0,
		.outbreakText = 0,
		.remindGiftText = {Matchcall_Beverly_Remind_Gift, STRS_GIFT_MSG},
		.remindRematchText = 0,
		.remindoutbreakText = 0,
		.hangupText = {Matchcall_Beverly_Hangup, STRS_NORMAL_MSG},
		.rematchAvailability = {DAY_NEVER, TIME_NEVER},
	},{
		.trainerId = TRAINER_DEREK,
		.unused = 0,
		.battleFrontierRecordStreakTextIndex = 1,
		.rematchOfferedFlag = 0,
		.rematchCheckFlags = 0,
		.giftFlag = FLAG_CALL_DEREK_GIFT,
		.genericStartIndex = 60,
		.genericTextsAmount = 5,
		.outbreakData = outbreakNone,
		.callTexts = {{Matchcall_Derek_Call_Morn, STRS_NORMAL_MSG},
						 {Matchcall_Derek_Call_Day, STRS_NORMAL_MSG},
						 {Matchcall_Derek_Call_Night, STRS_NORMAL_MSG}},
		.answerTexts = {{Matchcall_Derek_Answer_Morn, STRS_NORMAL_MSG},
						   {Matchcall_Derek_Answer_Day, STRS_NORMAL_MSG},
						   {Matchcall_Derek_Answer_Night, STRS_NORMAL_MSG}},
		.giftText = {Matchcall_Derek_Gift, STRS_GIFT_MSG},
		.rematchText = 0,
		.outbreakText = 0,
		.remindGiftText = {Matchcall_Derek_Remind_Gift, STRS_GIFT_MSG},
		.remindRematchText = 0,
		.remindoutbreakText =  0,
		.hangupText = {Matchcall_Derek_Hangup, STRS_NORMAL_MSG},
		.rematchAvailability = {DAY_NEVER, TIME_NEVER},
	},
};

static const struct MatchCallText sMatchCallGenericTexts[] =
{
		{ .text = Matchcall_Alan_Generic5,    .stringVarFuncIds = STRS_NORMAL_MSG},
		{ .text = Matchcall_Alan_Generic4,    .stringVarFuncIds = STRS_BATTLE_POSITIVE},
		{ .text = Matchcall_Alan_Generic3,    .stringVarFuncIds = STRS_WILD_BATTLE},
		{ .text = Matchcall_Alan_Generic2,    .stringVarFuncIds = STRS_WILD_BATTLE},
		{ .text = Matchcall_Alan_Generic1,    .stringVarFuncIds = STRS_NORMAL_MSG},
		{ .text = Matchcall_Anthony_Generic5,    .stringVarFuncIds = STRS_BATTLE_POSITIVE},
		{ .text = Matchcall_Anthony_Generic4,    .stringVarFuncIds = STRS_BATTLE_POSITIVE},
		{ .text = Matchcall_Anthony_Generic3,    .stringVarFuncIds = STRS_WILD_BATTLE},
		{ .text = Matchcall_Anthony_Generic2,    .stringVarFuncIds = STRS_WILD_BATTLE},
		{ .text = Matchcall_Anthony_Generic1,    .stringVarFuncIds = STRS_NORMAL_MSG},
		{ .text = Matchcall_Arnie_Generic5,    .stringVarFuncIds = STRS_NORMAL_MSG},
		{ .text = Matchcall_Arnie_Generic4,    .stringVarFuncIds = STRS_BATTLE_POSITIVE},
		{ .text = Matchcall_Arnie_Generic3,    .stringVarFuncIds = STRS_WILD_BATTLE},
		{ .text = Matchcall_Arnie_Generic2,    .stringVarFuncIds = STRS_WILD_BATTLE},
		{ .text = Matchcall_Arnie_Generic1,    .stringVarFuncIds = STRS_NORMAL_MSG},
		{ .text = Matchcall_Beth_Generic5,    .stringVarFuncIds = STRS_NORMAL_MSG},
		{ .text = Matchcall_Beth_Generic4,    .stringVarFuncIds = STRS_BATTLE_POSITIVE},
		{ .text = Matchcall_Beth_Generic3,    .stringVarFuncIds = STRS_WILD_BATTLE},
		{ .text = Matchcall_Beth_Generic2,    .stringVarFuncIds = STRS_WILD_BATTLE},
		{ .text = Matchcall_Beth_Generic1,    .stringVarFuncIds = STRS_NORMAL_MSG},
		{ .text = Matchcall_Beverly_Generic5,    .stringVarFuncIds = STRS_BATTLE_POSITIVE},
		{ .text = Matchcall_Beverly_Generic4,    .stringVarFuncIds = STRS_BATTLE_POSITIVE},
		{ .text = Matchcall_Beverly_Generic3,    .stringVarFuncIds = STRS_BATTLE_POSITIVE},
		{ .text = Matchcall_Beverly_Generic2,    .stringVarFuncIds = STRS_WILD_BATTLE},
		{ .text = Matchcall_Beverly_Generic1,    .stringVarFuncIds = STRS_NORMAL_MSG},
		{ .text = Matchcall_Brent_Generic15,    .stringVarFuncIds = STRS_BATTLE_POSITIVE},
		{ .text = Matchcall_Brent_Generic14,    .stringVarFuncIds = STRS_NORMAL_MSG},
		{ .text = Matchcall_Brent_Generic13,    .stringVarFuncIds = STRS_WILD_BATTLE},
		{ .text = Matchcall_Brent_Generic12,    .stringVarFuncIds = STRS_NORMAL_MSG},
		{ .text = Matchcall_Brent_Generic11,    .stringVarFuncIds = STRS_NORMAL_MSG},
		{ .text = Matchcall_Brent_Generic10,    .stringVarFuncIds = STRS_NORMAL_MSG},
		{ .text = Matchcall_Brent_Generic9,    .stringVarFuncIds = STRS_NORMAL_MSG},
		{ .text = Matchcall_Brent_Generic8,    .stringVarFuncIds = STRS_NORMAL_MSG},
		{ .text = Matchcall_Brent_Generic7,    .stringVarFuncIds = STRS_NORMAL_MSG},
		{ .text = Matchcall_Brent_Generic6,    .stringVarFuncIds = STRS_NORMAL_MSG},
		{ .text = Matchcall_Brent_Generic5,    .stringVarFuncIds = STRS_NORMAL_MSG},
		{ .text = Matchcall_Brent_Generic4,    .stringVarFuncIds = STRS_NORMAL_MSG},
		{ .text = Matchcall_Brent_Generic3,    .stringVarFuncIds = STRS_NORMAL_MSG},
		{ .text = Matchcall_Brent_Generic2,    .stringVarFuncIds = STRS_NORMAL_MSG},
		{ .text = Matchcall_Brent_Generic1,    .stringVarFuncIds = STRS_NORMAL_MSG},
		{ .text = Matchcall_Chad_Generic15,    .stringVarFuncIds = STRS_NORMAL_MSG},
		{ .text = Matchcall_Chad_Generic14,    .stringVarFuncIds = STRS_WILD_BATTLE},
		{ .text = Matchcall_Chad_Generic13,    .stringVarFuncIds = STRS_WILD_BATTLE},
		{ .text = Matchcall_Chad_Generic12,    .stringVarFuncIds = STRS_WILD_BATTLE},
		{ .text = Matchcall_Chad_Generic11,    .stringVarFuncIds = STRS_NORMAL_MSG},
		{ .text = Matchcall_Chad_Generic10,    .stringVarFuncIds = STRS_NORMAL_MSG},
		{ .text = Matchcall_Chad_Generic9,    .stringVarFuncIds = STRS_NORMAL_MSG},
		{ .text = Matchcall_Chad_Generic8,    .stringVarFuncIds = STRS_NORMAL_MSG},
		{ .text = Matchcall_Chad_Generic7,    .stringVarFuncIds = STRS_NORMAL_MSG},
		{ .text = Matchcall_Chad_Generic6,    .stringVarFuncIds = STRS_NORMAL_MSG},
		{ .text = Matchcall_Chad_Generic5,    .stringVarFuncIds = STRS_NORMAL_MSG},
		{ .text = Matchcall_Chad_Generic4,    .stringVarFuncIds = STRS_NORMAL_MSG},
		{ .text = Matchcall_Chad_Generic3,    .stringVarFuncIds = STRS_NORMAL_MSG},
		{ .text = Matchcall_Chad_Generic2,    .stringVarFuncIds = STRS_NORMAL_MSG},
		{ .text = Matchcall_Chad_Generic1,    .stringVarFuncIds = STRS_NORMAL_MSG},
		{ .text = Matchcall_Dana_Generic5,    .stringVarFuncIds = STRS_BATTLE_POSITIVE},
		{ .text = Matchcall_Dana_Generic4,    .stringVarFuncIds = STRS_BATTLE_POSITIVE},
		{ .text = Matchcall_Dana_Generic3,    .stringVarFuncIds = STRS_WILD_BATTLE},
		{ .text = Matchcall_Dana_Generic2,    .stringVarFuncIds = STRS_WILD_BATTLE},
		{ .text = Matchcall_Dana_Generic1,    .stringVarFuncIds = STRS_NORMAL_MSG},
		{ .text = Matchcall_Derek_Generic5,    .stringVarFuncIds = STRS_BATTLE_POSITIVE},
		{ .text = Matchcall_Derek_Generic4,    .stringVarFuncIds = STRS_BATTLE_POSITIVE},
		{ .text = Matchcall_Derek_Generic3,    .stringVarFuncIds = STRS_WILD_BATTLE},
		{ .text = Matchcall_Derek_Generic2,    .stringVarFuncIds = STRS_WILD_BATTLE},
		{ .text = Matchcall_Derek_Generic1,    .stringVarFuncIds = STRS_NORMAL_MSG},
		{ .text = Matchcall_Erin_Generic5,    .stringVarFuncIds = STRS_BATTLE_POSITIVE},
		{ .text = Matchcall_Erin_Generic4,    .stringVarFuncIds = STRS_BATTLE_POSITIVE},
		{ .text = Matchcall_Erin_Generic3,    .stringVarFuncIds = STRS_WILD_BATTLE},
		{ .text = Matchcall_Erin_Generic2,    .stringVarFuncIds = STRS_WILD_BATTLE},
		{ .text = Matchcall_Erin_Generic1,    .stringVarFuncIds = STRS_NORMAL_MSG},
		{ .text = Matchcall_Gaven_Generic5,    .stringVarFuncIds = STRS_BATTLE_POSITIVE},
		{ .text = Matchcall_Gaven_Generic4,    .stringVarFuncIds = STRS_BATTLE_POSITIVE},
		{ .text = Matchcall_Gaven_Generic3,    .stringVarFuncIds = STRS_WILD_BATTLE},
		{ .text = Matchcall_Gaven_Generic2,    .stringVarFuncIds = STRS_WILD_BATTLE},
		{ .text = Matchcall_Gaven_Generic1,    .stringVarFuncIds = STRS_NORMAL_MSG},
		{ .text = Matchcall_Gina_Generic5,    .stringVarFuncIds = STRS_BATTLE_POSITIVE},
		{ .text = Matchcall_Gina_Generic4,    .stringVarFuncIds = STRS_BATTLE_POSITIVE},
		{ .text = Matchcall_Gina_Generic3,    .stringVarFuncIds = STRS_WILD_BATTLE},
		{ .text = Matchcall_Gina_Generic2,    .stringVarFuncIds = STRS_WILD_BATTLE},
		{ .text = Matchcall_Gina_Generic1,    .stringVarFuncIds = STRS_NORMAL_MSG},
		{ .text = Matchcall_Huey_Generic1,    .stringVarFuncIds = STRS_NORMAL_MSG},
		{ .text = Matchcall_Jack_Generic16,    .stringVarFuncIds = STRS_BATTLE_POSITIVE},
		{ .text = Matchcall_Jack_Generic15,    .stringVarFuncIds = STRS_BATTLE_POSITIVE},
		{ .text = Matchcall_Jack_Generic14,    .stringVarFuncIds = STRS_WILD_BATTLE},
		{ .text = Matchcall_Jack_Generic13,    .stringVarFuncIds = STRS_WILD_BATTLE},
		{ .text = Matchcall_Jack_Generic12,    .stringVarFuncIds = STRS_NORMAL_MSG},
		{ .text = Matchcall_Jack_Generic11,    .stringVarFuncIds = STRS_NORMAL_MSG},
		{ .text = Matchcall_Jack_Generic10,    .stringVarFuncIds = STRS_NORMAL_MSG},
		{ .text = Matchcall_Jack_Generic9,    .stringVarFuncIds = STRS_NORMAL_MSG},
		{ .text = Matchcall_Jack_Generic8,    .stringVarFuncIds = STRS_NORMAL_MSG},
		{ .text = Matchcall_Jack_Generic7,    .stringVarFuncIds = STRS_NORMAL_MSG},
		{ .text = Matchcall_Jack_Generic6,    .stringVarFuncIds = STRS_NORMAL_MSG},
		{ .text = Matchcall_Jack_Generic5,    .stringVarFuncIds = STRS_NORMAL_MSG},
		{ .text = Matchcall_Jack_Generic4,    .stringVarFuncIds = STRS_NORMAL_MSG},
		{ .text = Matchcall_Jack_Generic3,    .stringVarFuncIds = STRS_NORMAL_MSG},
		{ .text = Matchcall_Jack_Generic2,    .stringVarFuncIds = STRS_NORMAL_MSG},
		{ .text = Matchcall_Jack_Generic1,    .stringVarFuncIds = STRS_NORMAL_MSG},
		{ .text = Matchcall_Joey_Generic5,    .stringVarFuncIds = STRS_NORMAL_MSG},
		{ .text = Matchcall_Joey_Generic4,    .stringVarFuncIds = STRS_BATTLE_POSITIVE},
		{ .text = Matchcall_Joey_Generic3,    .stringVarFuncIds = STRS_WILD_BATTLE},
		{ .text = Matchcall_Joey_Generic2,    .stringVarFuncIds = STRS_WILD_BATTLE},
		{ .text = Matchcall_Joey_Generic1,    .stringVarFuncIds = STRS_BATTLE_POSITIVE},
		{ .text = Matchcall_Jose_Generic5,    .stringVarFuncIds = STRS_BATTLE_POSITIVE},
		{ .text = Matchcall_Jose_Generic4,    .stringVarFuncIds = STRS_BATTLE_POSITIVE},
		{ .text = Matchcall_Jose_Generic3,    .stringVarFuncIds = STRS_WILD_BATTLE},
		{ .text = Matchcall_Jose_Generic2,    .stringVarFuncIds = STRS_WILD_BATTLE},
		{ .text = Matchcall_Jose_Generic1,    .stringVarFuncIds = STRS_NORMAL_MSG},
		{ .text = Matchcall_Liz_Generic16,    .stringVarFuncIds = STRS_BATTLE_POSITIVE},
		{ .text = Matchcall_Liz_Generic15,    .stringVarFuncIds = STRS_BATTLE_POSITIVE},
		{ .text = Matchcall_Liz_Generic14,    .stringVarFuncIds = STRS_WILD_BATTLE},
		{ .text = Matchcall_Liz_Generic13,    .stringVarFuncIds = STRS_WILD_BATTLE},
		{ .text = Matchcall_Liz_Generic12,    .stringVarFuncIds = STRS_NORMAL_MSG},
		{ .text = Matchcall_Liz_Generic11,    .stringVarFuncIds = STRS_NORMAL_MSG},
		{ .text = Matchcall_Liz_Generic10,    .stringVarFuncIds = STRS_NORMAL_MSG},
		{ .text = Matchcall_Liz_Generic9,    .stringVarFuncIds = STRS_NORMAL_MSG},
		{ .text = Matchcall_Liz_Generic8,    .stringVarFuncIds = STRS_NORMAL_MSG},
		{ .text = Matchcall_Liz_Generic7,    .stringVarFuncIds = STRS_NORMAL_MSG},
		{ .text = Matchcall_Liz_Generic6,    .stringVarFuncIds = STRS_NORMAL_MSG},
		{ .text = Matchcall_Liz_Generic5,    .stringVarFuncIds = STRS_NORMAL_MSG},
		{ .text = Matchcall_Liz_Generic4,    .stringVarFuncIds = STRS_NORMAL_MSG},
		{ .text = Matchcall_Liz_Generic3,    .stringVarFuncIds = STRS_WILD_BATTLE},
		{ .text = Matchcall_Liz_Generic2,    .stringVarFuncIds = STRS_NORMAL_MSG},
		{ .text = Matchcall_Liz_Generic1,    .stringVarFuncIds = STRS_BATTLE_POSITIVE},
		{ .text = Matchcall_Parry_Generic5,    .stringVarFuncIds = STRS_BATTLE_POSITIVE},
		{ .text = Matchcall_Parry_Generic4,    .stringVarFuncIds = STRS_BATTLE_POSITIVE},
		{ .text = Matchcall_Parry_Generic3,    .stringVarFuncIds = STRS_WILD_BATTLE},
		{ .text = Matchcall_Parry_Generic2,    .stringVarFuncIds = STRS_WILD_BATTLE},
		{ .text = Matchcall_Parry_Rematch,    .stringVarFuncIds = STRS_NORMAL_MSG},
		{ .text = Matchcall_Parry_Generic1,    .stringVarFuncIds = STRS_NORMAL_MSG},
		{ .text = Matchcall_Ralph_Generic5,    .stringVarFuncIds = STRS_NORMAL_MSG},
		{ .text = Matchcall_Ralph_Generic4,    .stringVarFuncIds = STRS_BATTLE_POSITIVE},
		{ .text = Matchcall_Ralph_Generic3,    .stringVarFuncIds = STRS_BATTLE_POSITIVE},
		{ .text = Matchcall_Ralph_Generic2,    .stringVarFuncIds = STRS_WILD_BATTLE},
		{ .text = Matchcall_Ralph_Generic1,    .stringVarFuncIds = STRS_NORMAL_MSG},
		{ .text = Matchcall_Reena_Generic5,    .stringVarFuncIds = STRS_NORMAL_MSG},
		{ .text = Matchcall_Reena_Generic4,    .stringVarFuncIds = STRS_BATTLE_POSITIVE},
		{ .text = Matchcall_Reena_Generic3,    .stringVarFuncIds = STRS_WILD_BATTLE},
		{ .text = Matchcall_Reena_Generic2,    .stringVarFuncIds = STRS_WILD_BATTLE},
		{ .text = Matchcall_Reena_Generic1,    .stringVarFuncIds = STRS_NORMAL_MSG},
		{ .text = Matchcall_Tiffany_Generic5,    .stringVarFuncIds = STRS_BATTLE_POSITIVE},
		{ .text = Matchcall_Tiffany_Generic4,    .stringVarFuncIds = STRS_BATTLE_POSITIVE},
		{ .text = Matchcall_Tiffany_Generic3,    .stringVarFuncIds = {STR_TRAINER_NAME, STR_SPECIES_IN_ROUTE, STR_SPECIES_IN_PARTY}},
		{ .text = Matchcall_Tiffany_Generic2,    .stringVarFuncIds = {STR_TRAINER_NAME, STR_SPECIES_IN_ROUTE, STR_SPECIES_IN_PARTY}},
		{ .text = Matchcall_Tiffany_Generic1,    .stringVarFuncIds = STRS_BATTLE_POSITIVE},
		{ .text = Matchcall_Tiffany_Generic6,    .stringVarFuncIds = STRS_NORMAL_MSG},
		{ .text = Matchcall_Tully_Generic5,    .stringVarFuncIds = STRS_NORMAL_MSG},
		{ .text = Matchcall_Tully_Generic4,    .stringVarFuncIds = STRS_BATTLE_POSITIVE},
		{ .text = Matchcall_Tully_Generic3,    .stringVarFuncIds = STRS_WILD_BATTLE},
		{ .text = Matchcall_Tully_Generic2,    .stringVarFuncIds = STRS_WILD_BATTLE},
		{ .text = Matchcall_Tully_Generic1,    .stringVarFuncIds = STRS_NORMAL_MSG},
		{ .text = Matchcall_Vance_Generic5,    .stringVarFuncIds = STRS_BATTLE_POSITIVE},
		{ .text = Matchcall_Vance_Generic4,    .stringVarFuncIds = STRS_BATTLE_POSITIVE},
		{ .text = Matchcall_Vance_Generic3,    .stringVarFuncIds = STRS_BATTLE_POSITIVE},
		{ .text = Matchcall_Vance_Generic2,    .stringVarFuncIds = STRS_BATTLE_POSITIVE},
		{ .text = Matchcall_Vance_Generic1,    .stringVarFuncIds = STRS_NORMAL_MSG},
		{ .text = Matchcall_Wade_Generic5,    .stringVarFuncIds = STRS_BATTLE_POSITIVE},
		{ .text = Matchcall_Wade_Generic4,    .stringVarFuncIds = STRS_BATTLE_POSITIVE},
		{ .text = Matchcall_Wade_Generic3,    .stringVarFuncIds = STRS_WILD_BATTLE},
		{ .text = Matchcall_Wade_Generic2,    .stringVarFuncIds = STRS_WILD_BATTLE},
		{ .text = Matchcall_Wade_Generic1,    .stringVarFuncIds = STRS_NORMAL_MSG},
		{ .text = Matchcall_Wilton_Generic2,    .stringVarFuncIds = STRS_BATTLE_POSITIVE},
		{ .text = Matchcall_Wilton_Generic5,    .stringVarFuncIds = STRS_BATTLE_POSITIVE},
		{ .text = Matchcall_Wilton_Generic4,    .stringVarFuncIds = STRS_BATTLE_POSITIVE},
		{ .text = Matchcall_Wilton_Generic3,    .stringVarFuncIds = STRS_WILD_BATTLE},
		{ .text = Matchcall_Wilton_Generic1,    .stringVarFuncIds = STRS_NORMAL_MSG},
		{ .text = Matchcall_Todd_Generic5,    .stringVarFuncIds = STRS_NORMAL_MSG},
		{ .text = Matchcall_Todd_Generic4,    .stringVarFuncIds = STRS_WILD_BATTLE},
		{ .text = Matchcall_Todd_Generic3,    .stringVarFuncIds = STRS_BATTLE_POSITIVE},
		{ .text = Matchcall_Todd_Generic2,    .stringVarFuncIds = STRS_BATTLE_POSITIVE},
		{ .text = Matchcall_Todd_Generic1,    .stringVarFuncIds = STRS_NORMAL_MSG},
};

static const struct MatchCallText sMatchCallBattleFrontierStreakTexts[] =
{
    { .text = MatchCall_BattleFrontierStreakText1,  .stringVarFuncIds = STRS_FRONTIER },
    { .text = MatchCall_BattleFrontierStreakText2,  .stringVarFuncIds = STRS_FRONTIER },
    { .text = MatchCall_BattleFrontierStreakText3,  .stringVarFuncIds = STRS_FRONTIER },
    { .text = MatchCall_BattleFrontierStreakText4,  .stringVarFuncIds = STRS_FRONTIER },
    { .text = MatchCall_BattleFrontierStreakText5,  .stringVarFuncIds = STRS_FRONTIER },
    { .text = MatchCall_BattleFrontierStreakText6,  .stringVarFuncIds = STRS_FRONTIER },
    { .text = MatchCall_BattleFrontierStreakText7,  .stringVarFuncIds = STRS_FRONTIER },
    { .text = MatchCall_BattleFrontierStreakText8,  .stringVarFuncIds = STRS_FRONTIER },
    { .text = MatchCall_BattleFrontierStreakText9,  .stringVarFuncIds = STRS_FRONTIER },
    { .text = MatchCall_BattleFrontierStreakText10, .stringVarFuncIds = STRS_FRONTIER },
    { .text = MatchCall_BattleFrontierStreakText11, .stringVarFuncIds = STRS_FRONTIER },
    { .text = MatchCall_BattleFrontierStreakText12, .stringVarFuncIds = STRS_FRONTIER },
    { .text = MatchCall_BattleFrontierStreakText13, .stringVarFuncIds = STRS_FRONTIER },
    { .text = MatchCall_BattleFrontierStreakText14, .stringVarFuncIds = STRS_FRONTIER },
};

static const struct MatchCallText sMatchCallBattleFrontierRecordStreakTexts[] =
{
    { .text = MatchCall_BattleFrontierRecordStreakText1,  .stringVarFuncIds = STRS_FRONTIER },
    { .text = MatchCall_BattleFrontierRecordStreakText2,  .stringVarFuncIds = STRS_FRONTIER },
    { .text = MatchCall_BattleFrontierRecordStreakText3,  .stringVarFuncIds = STRS_FRONTIER },
    { .text = MatchCall_BattleFrontierRecordStreakText4,  .stringVarFuncIds = STRS_FRONTIER },
    { .text = MatchCall_BattleFrontierRecordStreakText5,  .stringVarFuncIds = STRS_FRONTIER },
    { .text = MatchCall_BattleFrontierRecordStreakText6,  .stringVarFuncIds = STRS_FRONTIER },
    { .text = MatchCall_BattleFrontierRecordStreakText7,  .stringVarFuncIds = STRS_FRONTIER },
    { .text = MatchCall_BattleFrontierRecordStreakText8,  .stringVarFuncIds = STRS_FRONTIER },
    { .text = MatchCall_BattleFrontierRecordStreakText9,  .stringVarFuncIds = STRS_FRONTIER },
    { .text = MatchCall_BattleFrontierRecordStreakText10, .stringVarFuncIds = STRS_FRONTIER },
    { .text = MatchCall_BattleFrontierRecordStreakText11, .stringVarFuncIds = STRS_FRONTIER },
    { .text = MatchCall_BattleFrontierRecordStreakText12, .stringVarFuncIds = STRS_FRONTIER },
    { .text = MatchCall_BattleFrontierRecordStreakText13, .stringVarFuncIds = STRS_FRONTIER },
    { .text = MatchCall_BattleFrontierRecordStreakText14, .stringVarFuncIds = STRS_FRONTIER },
};

static const struct MatchCallText sMatchCallBattleDomeTexts[] =
{
    { .text = MatchCall_BattleDomeText1,  .stringVarFuncIds = STRS_FRONTIER },
    { .text = MatchCall_BattleDomeText2,  .stringVarFuncIds = STRS_FRONTIER },
    { .text = MatchCall_BattleDomeText3,  .stringVarFuncIds = STRS_FRONTIER },
    { .text = MatchCall_BattleDomeText4,  .stringVarFuncIds = STRS_FRONTIER },
    { .text = MatchCall_BattleDomeText5,  .stringVarFuncIds = STRS_FRONTIER },
    { .text = MatchCall_BattleDomeText6,  .stringVarFuncIds = STRS_FRONTIER },
    { .text = MatchCall_BattleDomeText7,  .stringVarFuncIds = STRS_FRONTIER },
    { .text = MatchCall_BattleDomeText8,  .stringVarFuncIds = STRS_FRONTIER },
    { .text = MatchCall_BattleDomeText9,  .stringVarFuncIds = STRS_FRONTIER },
    { .text = MatchCall_BattleDomeText10, .stringVarFuncIds = STRS_FRONTIER },
    { .text = MatchCall_BattleDomeText11, .stringVarFuncIds = STRS_FRONTIER },
    { .text = MatchCall_BattleDomeText12, .stringVarFuncIds = STRS_FRONTIER },
    { .text = MatchCall_BattleDomeText13, .stringVarFuncIds = STRS_FRONTIER },
    { .text = MatchCall_BattleDomeText14, .stringVarFuncIds = STRS_FRONTIER },
};

static const struct MatchCallText sMatchCallBattlePikeTexts[] =
{
    { .text = MatchCall_BattlePikeText1,  .stringVarFuncIds = STRS_FRONTIER },
    { .text = MatchCall_BattlePikeText2,  .stringVarFuncIds = STRS_FRONTIER },
    { .text = MatchCall_BattlePikeText3,  .stringVarFuncIds = STRS_FRONTIER },
    { .text = MatchCall_BattlePikeText4,  .stringVarFuncIds = STRS_FRONTIER },
    { .text = MatchCall_BattlePikeText5,  .stringVarFuncIds = STRS_FRONTIER },
    { .text = MatchCall_BattlePikeText6,  .stringVarFuncIds = STRS_FRONTIER },
    { .text = MatchCall_BattlePikeText7,  .stringVarFuncIds = STRS_FRONTIER },
    { .text = MatchCall_BattlePikeText8,  .stringVarFuncIds = STRS_FRONTIER },
    { .text = MatchCall_BattlePikeText9,  .stringVarFuncIds = STRS_FRONTIER },
    { .text = MatchCall_BattlePikeText10, .stringVarFuncIds = STRS_FRONTIER },
    { .text = MatchCall_BattlePikeText11, .stringVarFuncIds = STRS_FRONTIER },
    { .text = MatchCall_BattlePikeText12, .stringVarFuncIds = STRS_FRONTIER },
    { .text = MatchCall_BattlePikeText13, .stringVarFuncIds = STRS_FRONTIER },
    { .text = MatchCall_BattlePikeText14, .stringVarFuncIds = STRS_FRONTIER },
};

static const struct MatchCallText sMatchCallBattlePyramidTexts[] =
{
    { .text = MatchCall_BattlePyramidText1,  .stringVarFuncIds = STRS_FRONTIER },
    { .text = MatchCall_BattlePyramidText2,  .stringVarFuncIds = STRS_FRONTIER },
    { .text = MatchCall_BattlePyramidText3,  .stringVarFuncIds = STRS_FRONTIER },
    { .text = MatchCall_BattlePyramidText4,  .stringVarFuncIds = STRS_FRONTIER },
    { .text = MatchCall_BattlePyramidText5,  .stringVarFuncIds = STRS_FRONTIER },
    { .text = MatchCall_BattlePyramidText6,  .stringVarFuncIds = STRS_FRONTIER },
    { .text = MatchCall_BattlePyramidText7,  .stringVarFuncIds = STRS_FRONTIER },
    { .text = MatchCall_BattlePyramidText8,  .stringVarFuncIds = STRS_FRONTIER },
    { .text = MatchCall_BattlePyramidText9,  .stringVarFuncIds = STRS_FRONTIER },
    { .text = MatchCall_BattlePyramidText10, .stringVarFuncIds = STRS_FRONTIER },
    { .text = MatchCall_BattlePyramidText11, .stringVarFuncIds = STRS_FRONTIER },
    { .text = MatchCall_BattlePyramidText12, .stringVarFuncIds = STRS_FRONTIER },
    { .text = MatchCall_BattlePyramidText13, .stringVarFuncIds = STRS_FRONTIER },
    { .text = MatchCall_BattlePyramidText14, .stringVarFuncIds = STRS_FRONTIER },
};

static const struct MatchCallText *const sMatchCallGeneralTopics[] =
{
    [GEN_TOPIC_STREAK - 1]        = sMatchCallBattleFrontierStreakTexts,
    [GEN_TOPIC_STREAK_RECORD - 1] = sMatchCallBattleFrontierRecordStreakTexts,
    [GEN_TOPIC_B_DOME - 1]        = sMatchCallBattleDomeTexts,
    [GEN_TOPIC_B_PIKE - 1]        = sMatchCallBattlePikeTexts,
    [GEN_TOPIC_B_PYRAMID - 1]     = sMatchCallBattlePyramidTexts,
};

static bool8 ReceiveCallWhenOutside(void);
static bool8 AlwaysTrue(void);

static const struct ForcedPhoneCall sForcedPhoneCalls[] = {
    {
        .flag = FLAG_FORCED_CALL_ELM_STOLEN_MON,
        .phoneContactId = PHONE_CONTACT_ELM,
        .callCondition = ReceiveCallWhenOutside,
        .script = Route30_PhoneScript_ElmCall
    },
    {
        .flag = FLAG_FORCED_CALL_ELM_AIDE_IN_VIOLET,
        .phoneContactId = PHONE_CONTACT_ELM,
        .callCondition = ReceiveCallWhenOutside,
        .script = VioletCity_PhoneScript_ElmCall
    },
    {
        .flag = FLAG_FORCED_CALL_BIKE_SHOP,
        .phoneContactId = PHONE_CONTACT_BIKE_SHOP,
        .callCondition = ReceiveCallWhenOutside,
        .script = PhoneScript_BikeShop
    },
    {
        .flag = FLAG_FORCED_CALL_BILL_PC_BOXES_FULL,
        .phoneContactId = PHONE_CONTACT_BILL,
        .callCondition = ReceiveCallWhenOutside,
        .script = PhoneScript_Bill_JustRanOutOfRoom
    },{
        .flag = FLAG_FORCED_CALL_RADIO_TOWER_TAKEOVER,
        .phoneContactId = PHONE_CONTACT_ELM,
        .callCondition = ReceiveCallWhenOutside,
        .script = RadioTower_PhoneScript_ElmCall
    },{
        .flag = FLAG_FORCED_CALL_MASTER_BALL,
        .phoneContactId = PHONE_CONTACT_ELM,
        .callCondition = ReceiveCallWhenOutside,
        .script = MasterBall_PhoneScript_ElmCall
    },{
        .flag = FLAG_FORCED_CALL_START_SEVII,
        .phoneContactId = PHONE_CONTACT_BILL,
        .callCondition = ReceiveCallWhenOutside,
        .script = PhoneScript_Bill_InviteToSevii
    },{
        .flag = FLAG_FORCED_CALL_MOM_ITEM,
        .phoneContactId = PHONE_CONTACT_MOM,
        .callCondition = AlwaysTrue, // MomTriesToBuySomething() in mom_item_calls.c makes sure the call conditions are right
        .script = PhoneScript_Mom_BoughtItem
    },{
		.flag = FLAG_BUG_CATCHING_CONTEST_WADE_FORCED_CALL,
		.phoneContactId = PHONE_CONTACT_BUG_CATCHER_WADE,
		.callCondition = ReceiveCallWhenOutside,
		.script = PhoneScript_Wade_BugCatching_Contest
	},{
		.flag = FLAG_BUG_CATCHING_CONTEST_DEREK_FORCED_CALL,
		.phoneContactId = PHONE_CONTACT_POKEFAN_DEREK,
		.callCondition = ReceiveCallWhenOutside,
		.script = PhoneScript_Derek_BugCatching_Contest
	},{
		.flag = FLAG_IRWIN_FORCED_CALL,
		.phoneContactId = PHONE_CONTACT_JUGGLER_IRWIN,
		.callCondition = ReceiveCallWhenOutside,
		.script = PhoneScript_Irwin_Right_Away
	},{
		.flag = FLAG_GOLDENROD_SALE_FORCED_CALL,
		.phoneContactId = PHONE_CONTACT_CAMPER_TODD,
		.callCondition = ReceiveCallWhenOutside,
		.script = PhoneScript_Todd_Goldenrod_Dept_Sale
	},
};

static const struct ScanlineEffectParams sScanlineParams =
{
    (void *)REG_ADDR_BG0VOFS, SCANLINE_EFFECT_DMACNT_16BIT, 1
};

extern const u8 gPokedexRatingText_AreYouCurious[];
extern const u8 gPokedexRatingText_SoYouveSeenAndCaught[];
extern const u8 gPokedexRatingText_OnANationwideBasis[];

void InitMatchCallCounters(void)
{
    RtcCalcLocalTime();
    sMatchCallState.minutes = GetTotalMinutes(&gLocalTime) + 10;
    sMatchCallState.stepCounter = 0;
}

static bool32 UpdateMatchCallMinutesCounter(void)
{
    int curMinutes;
    RtcCalcLocalTime();
    curMinutes = GetTotalMinutes(&gLocalTime);
    if (sMatchCallState.minutes > curMinutes || curMinutes - sMatchCallState.minutes > 9)
    {
        sMatchCallState.minutes = curMinutes;
        return TRUE;
    }

    return FALSE;
}

static bool32 CheckMatchCallChance(void)
{
    int callChance = 1;
    if (!GetMonData(&gPlayerParty[0], MON_DATA_SANITY_IS_EGG) && GetMonAbility(&gPlayerParty[0]) == ABILITY_LIGHTNING_ROD)
        callChance = 2;
    
    if (Random() % 10 < callChance * 3)
        return TRUE;
    else
        return FALSE;
	return TRUE;
}

bool32 MapAllowsMatchCall(void)
{
    return (gMapHeader.phoneService) != 0;
}

static bool32 UpdateMatchCallStepCounter(void)
{
    if (++sMatchCallState.stepCounter >= 10)
    {
        sMatchCallState.stepCounter = 0;
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

static bool32 SelectMatchCallTrainer(void)
{
    u32 matchCallId;
    u32 numRegistered = GetNumRegisteredNPCs();
    if (numRegistered == 0)
        return FALSE;
    sMatchCallState.callerId = GetActiveMatchCallPhoneContactId(Random() % numRegistered);
    sMatchCallState.triggeredFromScript = FALSE;
    matchCallId = GetTrainerMatchCallId(gPhoneContacts[sMatchCallState.callerId].rematchTrainerId);
    if (sMatchCallState.callerId == PHONE_CONTACT_COUNT)
        return FALSE;

	if (Overworld_GetMapHeaderByGroupAndId(gPhoneContacts[sMatchCallState.callerId].mapGroup, gPhoneContacts[sMatchCallState.callerId].mapNum)->regionMapSectionId ==
			gMapHeader.regionMapSectionId)
		return FALSE;

    return TRUE;
}

static bool32 SelectForcedPhoneCall(void)
{
    int i;

    sMatchCallState.forcedPhoneCallId = 0;
    for (i = 0; i < ARRAY_COUNT(sForcedPhoneCalls); i++)
    {
    	sMatchCallState.callerId = sForcedPhoneCalls[i].phoneContactId;
        if (sForcedPhoneCalls[i].callCondition() &&
            FlagGet(sForcedPhoneCalls[i].flag) &&
			FlagGet(gPhoneContacts[sMatchCallState.callerId].registeredFlag))
        {
            FlagClear(sForcedPhoneCalls[i].flag);
            sMatchCallState.forcedPhoneCallId = i + 1;
            sMatchCallState.triggeredFromScript = 0;
            return TRUE;
        }
    }

    return FALSE;
}

static bool8 ReceiveCallWhenOutside(void)
{
    return IsMapTypeOutdoors(gMapHeader.mapType);
}

static bool8 AlwaysTrue(void)
{
    return TRUE;
}

static u32 GetNumRegisteredNPCs(void)
{
    u32 i, count;
    for (i = 0, count = 0; i < PHONE_CONTACT_COUNT; i++)
    {
    	if (FlagGet(gPhoneContacts[i].registeredFlag) && (i != PHONE_CONTACT_MOM &&  i != PHONE_CONTACT_BILL &&
    			i != PHONE_CONTACT_ELM && i != PHONE_CONTACT_BIKE_SHOP))
        {
            count++;
        }
    }

    return count;
}

static u32 GetActiveMatchCallPhoneContactId(u32 activeMatchCallId)
{
    u32 i;
    for (i = 0; i < PHONE_CONTACT_COUNT; i++)
    {
    	if(FlagGet(gPhoneContacts[i].registeredFlag) && (i > PHONE_CONTACT_NO_RANDOM_CALL_INDEX))
        {
            if (!activeMatchCallId)
                return i;

            activeMatchCallId--;
        }
    }

    return PHONE_CONTACT_COUNT;
}

bool32 TryStartForcedMatchCall(void)
{
    if (MapAllowsMatchCall() && SelectForcedPhoneCall())
    {
        StartMatchCall();
        return TRUE;
    }

    return FALSE;
}

bool32 TryStartMatchCall(void)
{

	if(UpdateMatchCallStepCounter())
	{
		if (TryStartForcedMatchCall())
			return TRUE;

		if (CheckMatchCallChance() && MapAllowsMatchCall() && SelectMatchCallTrainer() && UpdateMatchCallMinutesCounter())
		{
			StartMatchCall();
			return TRUE;
		}
	}

    return FALSE;
}

void StartMatchCallFromScript(const u8 *script, u8 callerId)
{
    sMatchCallState.triggeredFromScript = TRUE;
    sMatchCallState.callerId = callerId;
    sMatchCallState.script = script;
    StartMatchCall();
}

static void StartMatchCall(void)
{
    if (!sMatchCallState.triggeredFromScript)
    {
        ScriptContext2_Enable();
        FreezeObjectEvents();
        PlayerFreeze();
        sub_808BCF4();

        if (sMatchCallState.forcedPhoneCallId != 0 && sForcedPhoneCalls[sMatchCallState.forcedPhoneCallId - 1].script != NULL)
        {
            PhoneScriptContext_SetupCustomPhoneScript(sForcedPhoneCalls[sMatchCallState.forcedPhoneCallId - 1].script, PHONE_SCRIPT_OVERWORLD);
        }
        else
        {
            PhoneScriptContext_SetupPhoneScript(&gPhoneContacts[sMatchCallState.callerId], PHONE_SCRIPT_OVERWORLD);
        }
    }
    else
    {
        PhoneScriptContext_SetupCustomPhoneScript(sMatchCallState.script, PHONE_SCRIPT_OVERWORLD);
    }
}

static const struct WindowTemplate sMatchCallTextWindow =
{
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 15,
    .width = 28,
    .height = 4,
    .paletteNum = 15,
    .baseBlock = 0x200
};

static const struct WindowTemplate sPhoneCardNameTextWindow =
{
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 1,
    .width = 19,
    .height = 4,
    .paletteNum = 15,
    .baseBlock = 0x180
};

#define tState      data[0]
#define tWindowId   data[2]
#define tIconTaskId data[5]

static bool32 (*const sMatchCallTaskFuncs[])(u8) =
{
    LoadMatchCallWindowGfx,
    MatchCall_DrawWindow,
    MatchCall_ReadyIntro,
    SlideMatchCallWindowsOntoScreen,
    RunMatchCallIntroEllipsis,
};

void Task_InitOverworldPhoneCall(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    if (sMatchCallTaskFuncs[tState](taskId))
    {
        tState++;
        data[1] = 0;
        if ((u16)tState >= ARRAY_COUNT(sMatchCallTaskFuncs))
        {
            gSpecialVar_Result = PHONE_CALL_SUCCESS;
            DestroyTask(taskId);
        }
    }
}

static bool32 LoadMatchCallWindowGfx(u8 taskId)
{
    int i;
    s16 *taskData = gTasks[taskId].data;

    gPhoneCallWindowId = AddWindow(&sMatchCallTextWindow);
    if (gPhoneCallWindowId == 0xFF)
    {
        DestroyTask(taskId);
        return FALSE;
    }
    gPhoneCallerNameWindowId = AddWindow(&sPhoneCardNameTextWindow);
    if (gPhoneCallerNameWindowId == 0xFF)
    {
        DestroyTask(taskId);
        return FALSE;
    }

    if (LoadBgTiles(0, gPhoneCall_WindowGfx, sizeof(gPhoneCall_WindowGfx), 0x270) == 0xFFFF)
    {
        RemoveWindow(gPhoneCallWindowId);
        RemoveWindow(gPhoneCallerNameWindowId);
        DestroyTask(taskId);
        return FALSE;
    }

    if (!DecompressAndCopyTileDataToVram(0, gPhoneCall_IconGfx, 0, 0x279, 0))
    {
        RemoveWindow(gPhoneCallWindowId);
        RemoveWindow(gPhoneCallerNameWindowId);
        DestroyTask(taskId);
        return FALSE;
    }

    FillWindowPixelBuffer(gPhoneCallWindowId, PIXEL_FILL(1));
    FillWindowPixelBuffer(gPhoneCallerNameWindowId, PIXEL_FILL(1));
    LoadPalette(gPhoneCall_WindowPal, 0xF0, sizeof(gPhoneCall_WindowPal));

    ScanlineEffect_Clear();

    for (i = 0; i < 64; i++)
    {
        gScanlineEffectRegBuffers[0][i] = 40;
        gScanlineEffectRegBuffers[1][i] = 40;
    }

    for (; i < 96; i++)
    {
        gScanlineEffectRegBuffers[0][i] = 0;
        gScanlineEffectRegBuffers[1][i] = 0;
    }

    for (; i < 160; i++)
    {
        gScanlineEffectRegBuffers[0][i] = -40;
        gScanlineEffectRegBuffers[1][i] = -40;
    }

    ScanlineEffect_SetParams(sScanlineParams);

    taskData[4] = 32;
    return TRUE;
}

static bool32 MatchCall_DrawWindow(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    if (FreeTempTileDataBuffersIfPossible())
        return FALSE;

    PutWindowTilemap(gPhoneCallWindowId);
    PutWindowTilemap(gPhoneCallerNameWindowId);
    DrawMatchCallTextBoxBorder_Internal(gPhoneCallWindowId, 0x270, 15);
    DrawMatchCallTextBoxBorder_Internal(gPhoneCallerNameWindowId, 0x270, 15);
    WriteSequenceToBgTilemapBuffer(0, 0x279, 1, 1, 4, 4, 15, 1);
    CopyWindowToVram(gPhoneCallWindowId, 2);
    CopyWindowToVram(gPhoneCallerNameWindowId, 2);
    CopyBgTilemapBufferToVram(0);
    return TRUE;
}

static bool32 MatchCall_ReadyIntro(u8 taskId)
{
    const u8 *name;
    s16 *taskData = gTasks[taskId].data;
    if (!IsDma3ManagerBusyWithBgCopy())
    {
        name = BuildPhoneContactDisplayNameForCall(&gPhoneContacts[sMatchCallState.callerId], gStringVar1);
        AddTextPrinterParameterized5(gPhoneCallerNameWindowId, 2, name, 32, 2, 0, NULL, 1, 2);
        AddTextPrinterParameterized5(gPhoneCallWindowId, 2, gText_PokegearCallEllipsis, 2, 1, 0, NULL, 2, 1);
        CopyWindowToVram(gPhoneCallerNameWindowId, 3);
        return TRUE;
    }

    return FALSE;
}

static bool32 SlideMatchCallWindowsOntoScreen(u8 taskId)
{
    int i;

    gTasks[taskId].data[4] -= 6;

    if (gTasks[taskId].data[4] > 0)
    {
        for (i = 0; i < 80; i++)
            gScanlineEffectRegBuffers[gScanlineEffect.srcBuffer][i] = gTasks[taskId].data[4];

        for (; i < 160; i++)
            gScanlineEffectRegBuffers[gScanlineEffect.srcBuffer][i] = -gTasks[taskId].data[4];

        return FALSE;
    }
    else
    {
        SetGpuReg(REG_OFFSET_BG0VOFS, 0);
        gScanlineEffect.state = 3;
        return TRUE;
    }
}

static bool32 RunMatchCallIntroEllipsis(u8 taskId)
{
    s16 *taskData = gTasks[taskId].data;
    if (!ExecuteMatchCallTextPrinter(gPhoneCallWindowId))
    {
        return TRUE;
    }

    return FALSE;
}

static void PerformHangupAnimation(u8 taskId)
{
    int i;
    s16 *taskData = gTasks[taskId].data;
    
    gTasks[taskId].data[0] += 6;

    if (gTasks[taskId].data[0] < 40)
    {
        for (i = 0; i < 64; i++)
            gScanlineEffectRegBuffers[gScanlineEffect.srcBuffer][i] = gTasks[taskId].data[0];

        for (; i < 96; i++)
            gScanlineEffectRegBuffers[gScanlineEffect.srcBuffer][i] = 0;

        for (; i < 160; i++)
            gScanlineEffectRegBuffers[gScanlineEffect.srcBuffer][i] = -gTasks[taskId].data[0];
    }
    else
    {
        gScanlineEffect.state = 3;
        FillBgTilemapBufferRect_Palette0(0, 0, 0, 14, 30, 6);
        FillBgTilemapBufferRect_Palette0(0, 0, 0, 0, 25, 6);
        RemoveWindow(gPhoneCallWindowId);
        RemoveWindow(gPhoneCallerNameWindowId);
        CopyBgTilemapBufferToVram(0);
        DestroyTask(taskId);
    }
}

u8 EndOverworldPhoneCall(void)
{
    ScanlineEffect_Clear();
    ScanlineEffect_SetParams(sScanlineParams);
    return CreateTask(PerformHangupAnimation, 3);
}

bool32 CleanupAfterMatchCallHangup(void)
{
    u8 playerObjectId;
    if (!FuncIsActiveTask(PerformHangupAnimation) &&
        !IsDma3ManagerBusyWithBgCopy() &&
        !IsSEPlaying())
    {
        ChangeBgY(0, 0, 0);
        if (!sMatchCallState.triggeredFromScript)
        {
            LoadMessageBoxAndBorderGfx();
            playerObjectId = GetObjectEventIdByLocalIdAndMap(OBJ_EVENT_ID_PLAYER, 0, 0);
            ObjectEventClearHeldMovementIfFinished(&gObjectEvents[playerObjectId]);
            ScriptMovement_UnfreezeObjectEvents();
            UnfreezeObjectEvents();
            ScriptContext2_Disable();
        }
        else
        {
            // this allows waitstate to continue
            EnableBothScriptContexts();
        }
        sMatchCallState.triggeredFromScript = 0;

        return TRUE;
    }

    return FALSE;
}

void DrawMatchCallTextBoxBorder_Internal(u32 windowId, u32 tileOffset, u32 paletteId)
{
    int bg, x, y, width, height;
    int tileNum;

    bg = GetWindowAttribute(windowId, WINDOW_BG);
    x = GetWindowAttribute(windowId, WINDOW_TILEMAP_LEFT);
    y = GetWindowAttribute(windowId, WINDOW_TILEMAP_TOP);
    width = GetWindowAttribute(windowId, WINDOW_WIDTH);
    height = GetWindowAttribute(windowId, WINDOW_HEIGHT);
    tileNum = tileOffset + GetBgAttribute(bg, BG_ATTR_BASETILE);

    FillBgTilemapBufferRect_Palette0(bg, ((paletteId << 12) & 0xF000) | (tileNum + 0), x - 1, y - 1, 1, 1);
    FillBgTilemapBufferRect_Palette0(bg, ((paletteId << 12) & 0xF000) | (tileNum + 1), x, y - 1, width, 1);
    FillBgTilemapBufferRect_Palette0(bg, ((paletteId << 12) & 0xF000) | (tileNum + 2), x + width, y - 1, 1, 1);
    FillBgTilemapBufferRect_Palette0(bg, ((paletteId << 12) & 0xF000) | (tileNum + 3), x - 1, y, 1, height);
    FillBgTilemapBufferRect_Palette0(bg, ((paletteId << 12) & 0xF000) | (tileNum + 4), x + width, y, 1, height);
    FillBgTilemapBufferRect_Palette0(bg, ((paletteId << 12) & 0xF000) | (tileNum + 5), x - 1, y + height, 1, 1);
    FillBgTilemapBufferRect_Palette0(bg, ((paletteId << 12) & 0xF000) | (tileNum + 6), x, y + height, width, 1);
    FillBgTilemapBufferRect_Palette0(bg, ((paletteId << 12) & 0xF000) | (tileNum + 7), x + width, y + height, 1, 1);
}

bool32 ExecuteMatchCallTextPrinter(int windowId)
{
    if (JOY_HELD(A_BUTTON))
        gTextFlags.canABSpeedUpPrint = TRUE;
    else
        gTextFlags.canABSpeedUpPrint = FALSE;

    RunTextPrinters();
    return IsTextPrinterActive(windowId);
}

static bool32 TrainerIsEligibleForRematch(int matchCallId)
{
    return gSaveBlock1Ptr->trainerRematches[matchCallId] > 0;
}

static u16 GetRematchTrainerLocation(int matchCallId)
{
    const struct MapHeader *mapHeader = Overworld_GetMapHeaderByGroupAndId(gRematchTable[matchCallId].mapGroup, gRematchTable[matchCallId].mapNum);
    return mapHeader->regionMapSectionId;
}

static u32 GetNumRematchTrainersFought(void)
{
    u32 i, count;
    for (i = 0, count = 0; i < REMATCH_TABLE_ENTRIES; i++)
    {
        if (HasTrainerBeenFought(gRematchTable[i].trainerIds[0]))
            count++;
    }

    return count;
}

// Look through the rematch table for trainers that have been defeated once before.
// Return the index into the rematch table of the nth defeated trainer,
// or REMATCH_TABLE_ENTRIES if fewer than n rematch trainers have been defeated.
static u32 GetNthRematchTrainerFought(int n)
{
    u32 i, count;

    for (i = 0, count = 0; i < REMATCH_TABLE_ENTRIES; i++)
    {
        if (HasTrainerBeenFought(gRematchTable[i].trainerIds[0]))
        {
            if (count == n)
                return i;

            count++;
        }
    }

    return REMATCH_TABLE_ENTRIES;
}

u32 getRematchIdFromTrainerId(int trainerId)
{
	  u32 i;

	    for (i = 0; i < REMATCH_TABLE_ENTRIES; i++)
	    {
	        if (gRematchTable[i].trainerIds[0] == trainerId) return i;
	    }
	return -1;
}

void SelectMatchCallMessage_Hangup(int trainerId, u8 *str, bool8 isCallingPlayer, const struct PhoneContact *phoneContact)
{
	 u32 matchCallId;
	 u32 rematchId;
	 const struct MatchCallText *matchCallText;

	 matchCallId = GetTrainerMatchCallId(trainerId);

	 matchCallText = &gMatchCallTrainers[matchCallId].hangupText;

	 BuildMatchCallString(matchCallId, matchCallText, str);
}

void SelectMatchCallMessage_Opening(int trainerId, u8 *str, bool8 isCallingPlayer, const struct PhoneContact *phoneContact)
{
	 u32 matchCallId;
	 u32 rematchId;
	 const struct MatchCallText *matchCallText;

	 matchCallId = GetTrainerMatchCallId(trainerId);

	 u8 timeOfDay = GetTimeOfDay(gLocalTime.hours);
	 if(isCallingPlayer)
	 {
		 switch(timeOfDay){
			 case TIME_MORNING:
				 matchCallText = &gMatchCallTrainers[matchCallId].callTexts[0];
				 break;

			 case TIME_DAY:
				 matchCallText = &gMatchCallTrainers[matchCallId].callTexts[1];
				 break;

			 case TIME_NIGHT:
				 matchCallText = &gMatchCallTrainers[matchCallId].callTexts[2];
				 break;
		 }

	 }
	 else
	 {
		 switch(timeOfDay){
			 case TIME_MORNING:
				 matchCallText = &gMatchCallTrainers[matchCallId].answerTexts[0];
				 break;

			 case TIME_DAY:
				 matchCallText = &gMatchCallTrainers[matchCallId].answerTexts[1];
				 break;

			 case TIME_NIGHT:
				 matchCallText = &gMatchCallTrainers[matchCallId].answerTexts[2];
				 break;
		 }
	 }
	 BuildMatchCallString(matchCallId, matchCallText, str);
}

bool8 CanMatchCallIdAcceptRematch(int matchCallId, s8 dayOfWeek, s8 hour)
{
	return (gMatchCallTrainers[matchCallId].rematchAvailability[0] == dayOfWeek) && (gMatchCallTrainers[matchCallId].rematchAvailability[1] == hour) &&
			(!FlagGet(gMatchCallTrainers[matchCallId].rematchOfferedFlag));
}

bool32 SelectMatchCallMessage(int trainerId, u8 *str, bool8 isCallingPlayer, const struct PhoneContact *phoneContact)
{
    u32 matchCallId;
    u32 rematchId;
    const struct MatchCallText *matchCallText;
    bool32 retVal = FALSE;
    u16 randomNumber = Random() & 9;

    matchCallId = GetTrainerMatchCallId(trainerId);
    rematchId = getRematchIdFromTrainerId(trainerId);
    sBattleFrontierStreakInfo.facilityId = 0;

    if (FlagGet(gMatchCallTrainers[matchCallId].rematchOfferedFlag))
    {
    	matchCallText = &gMatchCallTrainers[matchCallId].remindRematchText;
    }
    else if (FlagGet(gMatchCallTrainers[matchCallId].giftFlag))
    {
    	matchCallText = &gMatchCallTrainers[matchCallId].remindGiftText;
    }
    else if (gMatchCallTrainers[matchCallId].outbreakData.species != SPECIES_NONE && gSaveBlock1Ptr->outbreakPokemonSpecies == gMatchCallTrainers[matchCallId].outbreakData.species)
    {
    	matchCallText = &gMatchCallTrainers[matchCallId].remindoutbreakText;
    }
    else if(gMatchCallTrainers[matchCallId].rematchOfferedFlag &&
    		((!isCallingPlayer && CanMatchCallIdAcceptRematch(matchCallId, gLocalTime.dayOfWeek, gLocalTime.hours)) ||
            (isCallingPlayer  && ShouldTrainerRequestBattle(rematchId, matchCallId))))
	{
		matchCallText = &gMatchCallTrainers[matchCallId].rematchText;
		retVal = TRUE;
		FlagSet(gMatchCallTrainers[matchCallId].rematchOfferedFlag);
		gSaveBlock1Ptr->trainerRematches[rematchId] = 1;
		UpdateRematchIfDefeated(rematchId);
	}
    else if (gMatchCallTrainers[matchCallId].giftFlag && (randomNumber == 1 || randomNumber == 2 || randomNumber == 3) && !FlagGet(gMatchCallTrainers[matchCallId].giftFlag) && isCallingPlayer)
    {
    	FlagSet(gMatchCallTrainers[matchCallId].giftFlag);
    	matchCallText = &gMatchCallTrainers[matchCallId].giftText;
    }
    else if (isCallingPlayer && gMatchCallTrainers[matchCallId].outbreakData.species != SPECIES_NONE && gSaveBlock1Ptr->outbreakPokemonSpecies == SPECIES_NONE
    		&& randomNumber == 4)
    {
        matchCallText = &gMatchCallTrainers[matchCallId].outbreakText;
        struct massOutbreakPhoneCallData* outbreakData = &gMatchCallTrainers[matchCallId].outbreakData;
        MatchCall_StartMassOutbreak(outbreakData);
    }
    else
    {
        // Message talking about something else
        matchCallText = GetGenericMatchCallText(matchCallId, str);
    }

    BuildMatchCallString(matchCallId, matchCallText, str);
    return retVal;
}

int GetTrainerMatchCallId(int trainerId)
{
    int i = 0;
    while (i <= MATCH_CALL_COUNT-1)
    {
        if (gMatchCallTrainers[i].trainerId == trainerId)
            return i;
        else
            i++;
    }
    return FALSE;
}

static const struct MatchCallText *GetGenericMatchCallText(int matchCallId, u8 *str)
{
	u32 randomNumber = Random() % (gMatchCallTrainers[matchCallId].genericTextsAmount - 1);

	return &sMatchCallGenericTexts[gMatchCallTrainers[matchCallId].genericStartIndex + randomNumber];
}

static void BuildMatchCallString(int matchCallId, const struct MatchCallText *matchCallText, u8 *str)
{
    PopulateMatchCallStringVars(matchCallId, matchCallText->stringVarFuncIds);
    StringExpandPlaceholders(str, matchCallText->text);
}

static u8 *const sMatchCallTextStringVars[] = { gStringVar1, gStringVar2, gStringVar3 };

static void PopulateMatchCallStringVars(int matchCallId, const s8 *stringVarFuncIds)
{
    int i;
    for (i = 0; i < NUM_STRVARS_IN_MSG; i++)
    {
        if (stringVarFuncIds[i] >= 0)
            PopulateMatchCallStringVar(matchCallId, stringVarFuncIds[i], sMatchCallTextStringVars[i]);
    }
}

static void (*const sPopulateMatchCallStringVarFuncs[])(int, u8 *) =
{
    [STR_TRAINER_NAME]     = PopulateTrainerName,
    [STR_MAP_NAME]         = PopulateMapName,
    [STR_SPECIES_IN_ROUTE] = PopulateSpeciesFromTrainerLocation,
    [STR_SPECIES_IN_PARTY] = PopulateSpeciesFromTrainerParty,
    [STR_FACILITY_NAME]    = PopulateBattleFrontierFacilityName,
    [STR_FRONTIER_STREAK]  = PopulateBattleFrontierStreak,
};

static void PopulateMatchCallStringVar(int matchCallId, int funcId, u8 *destStr)
{
    sPopulateMatchCallStringVarFuncs[funcId](matchCallId, destStr);
}

static const struct MultiTrainerMatchCallText sMultiTrainerMatchCallTexts[] =
{
    { .trainerId = TRAINER_NONE, .text = gText_Kira },
    { .trainerId = TRAINER_NONE,  .text = gText_Amy },
    { .trainerId = TRAINER_NONE, .text = gText_John },
    { .trainerId = TRAINER_NONE, .text = gText_Roy },
    { .trainerId = TRAINER_NONE, .text = gText_Gabby },
    { .trainerId = TRAINER_NONE, .text = gText_Anna },
};

static void PopulateTrainerName(int matchCallId, u8 *destStr)
{
    u32 i;
    u16 trainerId = gMatchCallTrainers[matchCallId].trainerId;
    for (i = 0; i < ARRAY_COUNT(sMultiTrainerMatchCallTexts); i++)
    {
        if (sMultiTrainerMatchCallTexts[i].trainerId == trainerId)
        {
            StringCopy(destStr, sMultiTrainerMatchCallTexts[i].text);
            return;
        }
    }

    StringCopy(destStr, gTrainers[trainerId].trainerName);
}

static void PopulateMapName(int matchCallId, u8 *destStr)
{
	u32 phoneContactId = GetPhoneContactFromTrainerId(gMatchCallTrainers[matchCallId].trainerId);
	const struct MapHeader *mapHeader = Overworld_GetMapHeaderByGroupAndId(gPhoneContacts[phoneContactId].mapGroup, gPhoneContacts[phoneContactId].mapNum);
    GetMapName(destStr, mapHeader->regionMapSectionId, 0);
}

static u8 GetLandEncounterSlot(void)
{
    int rand = Random() % 100;
    if (rand < 20)
        return 0;
    else if (rand >= 20 && rand < 40)
        return 1;
    else if (rand >= 40 && rand < 50)
        return 2;
    else if (rand >= 50 && rand < 60)
        return 3;
    else if (rand >= 60 && rand < 70)
        return 4;
    else if (rand >= 70 && rand < 80)
        return 5;
    else if (rand >= 80 && rand < 85)
        return 6;
    else if (rand >= 85 && rand < 90)
        return 7;
    else if (rand >= 90 && rand < 94)
        return 8;
    else if (rand >= 94 && rand < 98)
        return 9;
    else if (rand >= 98 && rand < 99)
        return 10;
    else
        return 11;
}

static u8 GetWaterEncounterSlot(void)
{
    int rand = Random() % 100;
    if (rand < 60)
        return 0;
    else if (rand >= 60 && rand < 90)
        return 1;
    else if (rand >= 90 && rand < 95)
        return 2;
    else if (rand >= 95 && rand < 99)
        return 3;
    else
        return 4;
}

static void PopulateSpeciesFromTrainerLocation(int matchCallId, u8 *destStr)
{
    u16 species[2];
    int numSpecies;
    u8 slot;
    int i = 0;
    u8 timeOfDay;
    
    RtcCalcLocalTime();
    timeOfDay = GetCurrentTimeOfDay();

    u32 phoneContactId = GetPhoneContactFromTrainerId(gMatchCallTrainers[matchCallId].trainerId);

    if (gWildMonHeaders[i].mapGroup != MAP_GROUP(UNDEFINED)) // ??? This check is nonsense.
    {
        while (gWildMonHeaders[i].mapGroup != MAP_GROUP(UNDEFINED))
        {
            if (gWildMonHeaders[i].mapGroup == gPhoneContacts[phoneContactId].mapGroup
             && gWildMonHeaders[i].mapNum == gPhoneContacts[phoneContactId].mapNum)
                break;

            i++;
        }

        if (gWildMonHeaders[i].mapGroup != MAP_GROUP(UNDEFINED))
        {
            numSpecies = 0;
            if (gWildMonHeaders[i].landMonsInfo)
            {
                slot = GetLandEncounterSlot();
                species[numSpecies] = gWildMonHeaders[i].landMonsInfo->wildPokemon[timeOfDay][slot].species;
                numSpecies++;
            }

            if (gWildMonHeaders[i].waterMonsInfo)
            {
                slot = GetWaterEncounterSlot();
                species[numSpecies] = gWildMonHeaders[i].waterMonsInfo->wildPokemon[timeOfDay][slot].species;
                numSpecies++;
            }

            if (numSpecies)
            {
                StringCopy(destStr, gSpeciesNames[species[Random() % numSpecies]]);
                return;
            }
        }
    }

    destStr[0] = EOS;
}

static void PopulateSpeciesFromTrainerParty(int matchCallId, u8 *destStr)
{
    u16 trainerId;
    union TrainerMonPtr party;
    u8 monId;
    const u8 *speciesName;

    trainerId = GetLastBeatenRematchTrainerId(gMatchCallTrainers[matchCallId].trainerId);
    if(trainerId == FALSE){ trainerId = gMatchCallTrainers[matchCallId].trainerId;}
    party = gTrainers[trainerId].party;
    monId = Random() % gTrainers[trainerId].partySize;

    switch (gTrainers[trainerId].partyFlags)
    {
    case 0:
    default:
        speciesName = gSpeciesNames[party.NoItemDefaultMoves[monId].species];
        break;
    case F_TRAINER_PARTY_CUSTOM_MOVESET:
        speciesName = gSpeciesNames[party.NoItemCustomMoves[monId].species];
        break;
    case F_TRAINER_PARTY_HELD_ITEM:
        speciesName = gSpeciesNames[party.ItemDefaultMoves[monId].species];
        break;
    case F_TRAINER_PARTY_CUSTOM_MOVESET | F_TRAINER_PARTY_HELD_ITEM:
        speciesName = gSpeciesNames[party.ItemCustomMoves[monId].species];
        break;
    }

    StringCopy(destStr, speciesName);
}

static const u8 *const sBattleFrontierFacilityNames[] =
{
    gText_BattleTower2,
    gText_BattleDome,
    gText_BattlePalace,
    gText_BattleArena,
    gText_BattlePike,
    gText_BattleFactory,
    gText_BattlePyramid,
};

static void PopulateBattleFrontierFacilityName(int matchCallId, u8 *destStr)
{
    StringCopy(destStr, sBattleFrontierFacilityNames[sBattleFrontierStreakInfo.facilityId]);
}

static void PopulateBattleFrontierStreak(int matchCallId, u8 *destStr)
{
    int i = 0;
    int streak = sBattleFrontierStreakInfo.streak;
    while (streak != 0)
    {
        streak /= 10;
        i++;
    }
    
    ConvertIntToDecimalStringN(destStr, sBattleFrontierStreakInfo.streak, STR_CONV_MODE_LEFT_ALIGN, i);
}

static const u16 sBadgeFlags[NUM_BADGES] =
{
    FLAG_BADGE01_GET,
    FLAG_BADGE02_GET,
    FLAG_BADGE03_GET,
    FLAG_BADGE04_GET,
    FLAG_BADGE05_GET,
    FLAG_BADGE06_GET,
    FLAG_BADGE07_GET,
    FLAG_BADGE08_GET,
};

static int GetNumOwnedBadges(void)
{
    u32 i;

    for (i = 0; i < NUM_BADGES; i++)
    {
        if (!FlagGet(sBadgeFlags[i]))
            break;
    }

    return i;
}

// Whether or not a trainer calling the player from a different route should request a battle
static bool32 ShouldTrainerRequestBattle(u32 rematchId, u32 matchCallId)
{
	for(int i = 1; i < 4; i++)
	{
		if(!HasTrainerBeenFought(gRematchTable[rematchId].trainerIds[i]) && FlagGet(gMatchCallTrainers[matchCallId].rematchCheckFlags[i-1]) &&
				!FlagGet(gMatchCallTrainers[matchCallId].rematchOfferedFlag))
		{
			return TRUE;
		}
	}
    return FALSE;
}

static u16 GetFrontierStreakInfo(u16 facilityId, u32 *topicTextId)
{
    int i;
    int j;
    u16 streak = 0;

    switch (facilityId)
    {
    case FRONTIER_FACILITY_DOME:
        for (i = 0; i < 2; i++)
        {
            for (j = 0; j < 2; j++)
            {
                if (streak < gSaveBlock2Ptr->frontier.domeRecordWinStreaks[i][j])
                    streak = gSaveBlock2Ptr->frontier.domeRecordWinStreaks[i][j];
            }
        }
        *topicTextId = GEN_TOPIC_B_DOME - 1;
        break;
    #ifdef BUGFIX
    case FRONTIER_FACILITY_PIKE:
    #else
    case FRONTIER_FACILITY_FACTORY:
    #endif
        for (i = 0; i < 2; i++)
        {
            if (streak < gSaveBlock2Ptr->frontier.pikeRecordStreaks[i])
                streak = gSaveBlock2Ptr->frontier.pikeRecordStreaks[i];
        }
        *topicTextId = GEN_TOPIC_B_PIKE - 1;
        break;
    case FRONTIER_FACILITY_TOWER:
        for (i = 0; i < 4; i++)
        {
            for (j = 0; j < 2; j++)
            {
                if (streak < gSaveBlock2Ptr->frontier.towerRecordWinStreaks[i][j])
                    streak = gSaveBlock2Ptr->frontier.towerRecordWinStreaks[i][j];
            }
        }
        *topicTextId = GEN_TOPIC_STREAK_RECORD - 1;
        break;
    case FRONTIER_FACILITY_PALACE:
        for (i = 0; i < 2; i++)
        {
            for (j = 0; j < 2; j++)
            {
                if (streak < gSaveBlock2Ptr->frontier.palaceRecordWinStreaks[i][j])
                    streak = gSaveBlock2Ptr->frontier.palaceRecordWinStreaks[i][j];
            }
        }
        *topicTextId = GEN_TOPIC_STREAK_RECORD - 1;
        break;
    #ifdef BUGFIX
    case FRONTIER_FACILITY_FACTORY:
    #else
    case FRONTIER_FACILITY_PIKE:
    #endif
        for (i = 0; i < 2; i++)
        {
            for (j = 0; j < 2; j++)
            {
                if (streak < gSaveBlock2Ptr->frontier.factoryRecordWinStreaks[i][j])
                    streak = gSaveBlock2Ptr->frontier.factoryRecordWinStreaks[i][j];
            }
        }
        *topicTextId = GEN_TOPIC_STREAK_RECORD - 1;
        break;
    case FRONTIER_FACILITY_ARENA:
        for (i = 0; i < 2; i++)
        {
            if (streak < gSaveBlock2Ptr->frontier.arenaRecordStreaks[i])
                streak = gSaveBlock2Ptr->frontier.arenaRecordStreaks[i];
        }
        *topicTextId = GEN_TOPIC_STREAK_RECORD - 1;
        break;
    case FRONTIER_FACILITY_PYRAMID:
        for (i = 0; i < 2; i++)
        {
            if (streak < gSaveBlock2Ptr->frontier.pyramidRecordStreaks[i])
                streak = gSaveBlock2Ptr->frontier.pyramidRecordStreaks[i];
        }
        *topicTextId = GEN_TOPIC_B_PYRAMID - 1;
        break;
    }

    return streak;
}

void LoadMatchCallWindowGfx2(u32 windowId, u32 destOffset, u32 paletteId)
{
    u8 bg = GetWindowAttribute(windowId, WINDOW_BG);
    LoadBgTiles(bg, gPhoneCall_WindowGfx, sizeof(gPhoneCall_WindowGfx), destOffset);
    LoadPalette(gPhoneCall_WindowPal, paletteId << 4, 0x20);
}

void DrawMatchCallTextBoxBorder(u32 windowId, u32 tileOffset, u32 paletteId)
{
    DrawMatchCallTextBoxBorder_Internal(windowId, tileOffset, paletteId);
}

static const struct MomItemTable MomItems_1[] = {
    {0, 600, FALSE, ITEM_SUPER_POTION},
    {0,  90, FALSE, ITEM_ANTIDOTE},
    {0, 180, FALSE, ITEM_POKE_BALL},
    {0, 450, FALSE, ITEM_ESCAPE_ROPE},
    {0, 500, FALSE, ITEM_GREAT_BALL},
};

static const struct MomItemTable MomItems_2[] = {
    {   900,   600, FALSE, ITEM_SUPER_POTION},
    {  4000,   270, FALSE, ITEM_REPEL},
    {  7000,   600, FALSE, ITEM_SUPER_POTION},
    { 10000,  1800, TRUE,  DOLL_CHARMANDER},
    { 15000,  3000, FALSE, ITEM_MOON_STONE},
    { 19000,   600, FALSE, ITEM_SUPER_POTION},
    { 30000,  4800, TRUE,  DOLL_CLEFAIRY},
    { 40000,   900, FALSE, ITEM_HYPER_POTION},
    { 50000,  8000, TRUE,  DOLL_PIKACHU},
    {100000, 22800, TRUE,  BIG_DOLL_SNORLAX + 1}, // BIG_DOLL_SNORLAX expands to 1, which is the same as DOLL_PIKACHU. Oops.
};

static void MomTriesToBuySomethingFromTable1(void)
{
    /*
    u32 i;
    u32 moneyMatch;
    
    // Determine the multiples of 2300 match here. If false, return.

    i = Random() % ARRAY_COUNT(MomItems_1);

    // will always have enough money, since this triggers for multiples of 2300
    // and nothing in MomItems_1 has a price > 2300

    if(AddPCItem(MomItems_1[i].item, 1))
    {
        FlagSet(FLAG_FORCED_CALL_MOM_ITEM);
        VarSet(VAR_0x8004, 0);
        RemoveMoney(&gSaveBlock1Ptr->bankedMoney, MomItems_1[i].price);
    }
    */
    return;
}

void MomTriesToBuySomething(void)
{
    if(MapAllowsMatchCall())
    {
        u32 i =  VarGet(VAR_MOM_BOUGHT_ITEMS);
        if(i >= ARRAY_COUNT(MomItems_2) || !IsEnoughMoney(&gSaveBlock1Ptr->bankedMoney, MomItems_2[i].threshold))
        {
            //secondary table
            MomTriesToBuySomethingFromTable1();
        }
        else
        {
            if(!MomItems_2[i].itemType)
            {   // regular item
                if(AddPCItem(MomItems_2[i].item, 1))
                {
                    FlagSet(FLAG_FORCED_CALL_MOM_ITEM);
                    VarSet(VAR_MOM_BOUGHT_ITEMS, i + 1);
                    VarSet(VAR_0x8004, 0);
                    RemoveMoney(&gSaveBlock1Ptr->bankedMoney, MomItems_2[i].price);
                }
                return;
            }
            else
            {   // doll
                switch(MomItems_2[i].item)
                {
                    case DOLL_CHARMANDER:
                        if(gSaveBlock1Ptr->roomDecorInventory.charmanderDoll < 2)
                            gSaveBlock1Ptr->roomDecorInventory.charmanderDoll += 1;
                        else // somehow already have 2, remove from Mom's buy list
                        {
                            VarSet(VAR_MOM_BOUGHT_ITEMS, i + 1);
                            return;
                        }
                        break;
                    case DOLL_CLEFAIRY:
                        if(gSaveBlock1Ptr->roomDecorInventory.clefairyDoll < 2)
                            gSaveBlock1Ptr->roomDecorInventory.clefairyDoll += 1;
                        else // somehow already have 2, remove from Mom's buy list
                        {
                            VarSet(VAR_MOM_BOUGHT_ITEMS, i + 1);
                            return;
                        }
                        break;
                    case DOLL_PIKACHU:
                        if(gSaveBlock1Ptr->roomDecorInventory.pikachuDoll < 2)
                            gSaveBlock1Ptr->roomDecorInventory.pikachuDoll += 1;
                        else // somehow already have 2, remove from Mom's buy list
                        {
                            VarSet(VAR_MOM_BOUGHT_ITEMS, i + 1);
                            return;
                        }
                        break;
                    case BIG_DOLL_SNORLAX + 1:
                        if(gSaveBlock1Ptr->roomDecorInventory.bigSnorlax != 1)
                            gSaveBlock1Ptr->roomDecorInventory.bigSnorlax = 1;
                        else // somehow already have 1, remove from Mom's buy list
                        {
                            VarSet(VAR_MOM_BOUGHT_ITEMS, i + 1);
                            return;
                        }
                        break;
                    default:
                        return;
                }
                FlagSet(FLAG_FORCED_CALL_MOM_ITEM);
                VarSet(VAR_0x8004, 1);
                VarSet(VAR_MOM_BOUGHT_ITEMS, i + 1);
                RemoveMoney(&gSaveBlock1Ptr->bankedMoney, MomItems_2[i].price);
            }
        }
    }
}

void isPlayerBeingCalled(const struct PhoneContact *phoneContact, bool8 isCallingPlayer)
{
	VarSet(VAR_RESULT, isCallingPlayer);
	return;
}

bool8 DetermineGoldenrodSale(int random_modulus)
{
	int chance = Random() % random_modulus;
	return chance == 0;
}

void UpdateForcedCallsPerDay()
{
	FlagClear(FLAG_BUG_CATCHING_CONTEST_DEREK_FORCED_CALL);
	FlagClear(FLAG_BUG_CATCHING_CONTEST_WADE_FORCED_CALL);
	FlagClear(FLAG_GOLDENROD_SALE_FORCED_CALL);
	FlagClear(FLAG_DAILY_GOLDENROD_DEPT_STORE_SALE_HAPPENING);

	switch(gLocalTime.dayOfWeek)
	{
		case DAY_SUNDAY:
			break;
		case DAY_MONDAY:
			break;
		case DAY_TUESDAY:
			if(FlagGet(gPhoneContacts[PHONE_CONTACT_BUG_CATCHER_WADE].registeredFlag))
			{
				FlagSet(FLAG_BUG_CATCHING_CONTEST_WADE_FORCED_CALL);
			}
			else if(FlagGet(gPhoneContacts[PHONE_CONTACT_POKEFAN_DEREK].registeredFlag))
			{
				FlagSet(FLAG_BUG_CATCHING_CONTEST_DEREK_FORCED_CALL);
			}
			break;
		case DAY_WEDNESDAY:
			break;
		case DAY_THURSDAY:
			if(FlagGet(gPhoneContacts[PHONE_CONTACT_POKEFAN_DEREK].registeredFlag))
			{
				FlagSet(FLAG_BUG_CATCHING_CONTEST_DEREK_FORCED_CALL);
			}
			else if(FlagGet(gPhoneContacts[PHONE_CONTACT_BUG_CATCHER_WADE].registeredFlag))
			{
				FlagSet(FLAG_BUG_CATCHING_CONTEST_WADE_FORCED_CALL);
			}
			break;
		case DAY_FRIDAY:
			break;
		case DAY_SATURDAY:
			if(FlagGet(gPhoneContacts[PHONE_CONTACT_POKEFAN_DEREK].registeredFlag))
			{
				FlagSet(FLAG_BUG_CATCHING_CONTEST_DEREK_FORCED_CALL);
			}
			else if(FlagGet(gPhoneContacts[PHONE_CONTACT_BUG_CATCHER_WADE].registeredFlag))
			{
				FlagSet(FLAG_BUG_CATCHING_CONTEST_WADE_FORCED_CALL);
			}
			if(DetermineGoldenrodSale(2)) FlagSet(FLAG_GOLDENROD_SALE_FORCED_CALL);
			break;
	}
}

void MatchCall_StartMassOutbreak(struct massOutbreakPhoneCallData *massOutbreak)
{
    gSaveBlock1Ptr->outbreakPokemonSpecies = massOutbreak->species;
    gSaveBlock1Ptr->outbreakLocationMapNum = massOutbreak->location_map_num;
    //gSaveBlock1Ptr->outbreakLocationMapGroup = massOutbreak->location_map_group;
    //Map group seems not to be used
    gSaveBlock1Ptr->outbreakPokemonLevel = massOutbreak->level;
    //gSaveBlock1Ptr->outbreakPokemonMoves[0] = massOutbreak->moves[0];
    //gSaveBlock1Ptr->outbreakPokemonMoves[1] = massOutbreak->moves[1];
    //gSaveBlock1Ptr->outbreakPokemonMoves[2] = massOutbreak->moves[2];
    //gSaveBlock1Ptr->outbreakPokemonMoves[3] = massOutbreak->moves[3];
    gSaveBlock1Ptr->outbreakPokemonProbability = massOutbreak->probability;
    gSaveBlock1Ptr->outbreakWildState = massOutbreak->wildState;
    gSaveBlock1Ptr->outbreakSpecialLevel1 = massOutbreak->specialLevel1;
    gSaveBlock1Ptr->outbreakSpecialLevel2 = massOutbreak->specialLevel2;
    gSaveBlock1Ptr->outbreakDaysLeft = 1;
}

void MatchCall_EndMassOutbreak(void)
{
    gSaveBlock1Ptr->outbreakPokemonSpecies = SPECIES_NONE;
    gSaveBlock1Ptr->outbreakLocationMapNum = 0;
    gSaveBlock1Ptr->outbreakLocationMapGroup = 0;
    gSaveBlock1Ptr->outbreakPokemonLevel = 0;
    gSaveBlock1Ptr->outbreakSpecialLevel1 = 0;
    gSaveBlock1Ptr->outbreakWildState = 0;
    gSaveBlock1Ptr->outbreakPokemonMoves[0] = MOVE_NONE;
    gSaveBlock1Ptr->outbreakPokemonMoves[1] = MOVE_NONE;
    gSaveBlock1Ptr->outbreakPokemonMoves[2] = MOVE_NONE;
    gSaveBlock1Ptr->outbreakPokemonMoves[3] = MOVE_NONE;
    gSaveBlock1Ptr->outbreakSpecialLevel2 = 0;
    gSaveBlock1Ptr->outbreakPokemonProbability = 0;
    gSaveBlock1Ptr->outbreakDaysLeft = 0;
}

void MatchCall_TryEndMassOutbreak(u16 days)
{
    if(gSaveBlock1Ptr->outbreakPokemonSpecies == SPECIES_NONE) return;

	if (gSaveBlock1Ptr->outbreakDaysLeft <= days)
        MatchCall_EndMassOutbreak();
    else
        gSaveBlock1Ptr->outbreakDaysLeft -= days;
}

