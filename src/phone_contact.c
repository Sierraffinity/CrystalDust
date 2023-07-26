#include "global.h"
#include "battle.h"
#include "battle_setup.h"
#include "data.h"
#include "day_night.h"
#include "event_data.h"
#include "international_string_util.h"
#include "match_call.h"
#include "phone_contact.h"
#include "phone_scripts.h"
#include "text.h"
#include "strings.h"
#include "string_util.h"
#include "constants/day_night.h"
#include "constants/flags.h"
#include "constants/maps.h"

extern const u8 gTrainerClassNames[][13];

static bool8 CanAcceptRematch_Always(s8 dayOfWeek, s8 hour);
static bool8 CanAcceptRematch_Never(s8 dayOfWeek, s8 hour);
static bool8 CanAcceptRematch_MondayDaytime(s8 dayOfWeek, s8 hour);

static const u8 sPhoneContactName_Mom[] = _("MOM");
static const u8 sPhoneContactName_ProfessorElm[] = _("PROF. ELM");
static const u8 sPhoneContactName_BikeShop[] = _("BIKE SHOP");
static const u8 sPhoneContactName_Bill[] = _("BILL");
static const u8 sphonecontactname_Hiker_Anthony[] = _("HIKER ANTHONY");
static const u8 sphonecontactname_Fisher_Ralph[] = _("FISHERMAN RALPH");
static const u8 sphonecontactname_Bug_Catcher_Arnie[] = _("BUG CATCHER ARNIE");
static const u8 sphonecontactname_Lass_Dana[] = _("LASS DANA");
static const u8 sphonecontactname_Buena[] = _("BUENA");
static const u8 sphonecontactname_Youngster_Joey[] = _("YOUNGSTER JOEY");
static const u8 sphonecontactname_Bug_Catcher_Wade[] = _("BUG CATCHER WADE");
static const u8 sphonecontactname_Camper_Todd[] = _("CAMPER TODD");
static const u8 sphonecontactname_Picnicker_Gina[] = _("PICNICKER GINA");
static const u8 sphonecontactname_Pokefan_Beverly[] = _("POKEFAN BEVERLY");
static const u8 sphonecontactname_Schoolboy_Alan[] = _("SCHOOLBOY ALAN");
static const u8 sphonecontactname_Bird_Keeper_Vance[] = _("BIRD KEEPER VANCE");
static const u8 sphonecontactname_Fisher_Tully[] = _("FISHERMAN TULLY");
static const u8 sphonecontactname_Sailor_Huey[] = _("SAILOR HUEY");
static const u8 sphonecontactname_Picnicker_Tiffany[] = _("PICNICKER TIFFANY");
static const u8 sphonecontactname_Blackbelt_Kenji[] = _("BLACKBELT KENJI");
static const u8 sphonecontactname_Picnicker_Erin[] = _("PICNICKER ERIN");
static const u8 sphonecontactname_Bird_Keeper_Jose[] = _("BIRD KEEPER JOSE");
static const u8 sphonecontactname_Schoolboy_Jack[] = _("SCHOOLBOY JACK");
static const u8 sphonecontactname_Cooltrainer_Reena[] = _("COOLTRAINER REENA");
static const u8 sphonecontactname_Cooltrainer_Gaven[] = _("COOLTRAINER GAVEN");
static const u8 sphonecontactname_Cooltrainer_Beth[] = _("COOLTRAINER BETH");
static const u8 sphonecontactname_Picnicker_Liz[] = _("PICNICKER LIZ");
static const u8 sphonecontactname_Juggler_Irwin[] = _("JUGGLER IRWIN");
static const u8 sphonecontactname_Pokefan_Derek[] = _("POKEFAN DEREK");
static const u8 sphonecontactname_Pokemaniac_Brent[] = _("POKEMANIAC BRENT");
static const u8 sphonecontactname_Schoolboy_Chad[] = _("SCHOOLBOY CHAD");
static const u8 sphonecontactname_Fisher_Wilton[] = _("FISHERMAN WILTON");
static const u8 sphonecontactname_Hiker_Parry[] = _("HIKER PARRY");



const struct PhoneContact gPhoneContacts[PHONE_CONTACT_COUNT] =
{
    [PHONE_CONTACT_MOM] = {
        .customDisplayName = sPhoneContactName_Mom,
        .phoneScript = PhoneScript_Mom,
        .canAcceptRematch = CanAcceptRematch_Always,
        .mapNum = MAP_NUM(NEW_BARK_TOWN_PLAYERS_HOUSE_1F),
        .mapGroup = MAP_GROUP(NEW_BARK_TOWN_PLAYERS_HOUSE_1F),
        .registeredFlag = FLAG_PHONE_CARD_MOM,
		.rematchFlags = {FALSE, FALSE, FALSE, FALSE},
		.rematchOfferedFlag = FALSE,
        .rematchTrainerId = 0xFF,
		.trainerId = TRAINER_NONE,
        .availability = PHONE_AVAILABILITY_ALWAYS,
		.rematchAvailability = {DAY_NEVER, TIME_NEVER},
        .isPermanent = TRUE,
    },
    [PHONE_CONTACT_ELM] = {
        .customDisplayName = sPhoneContactName_ProfessorElm,
        .phoneScript = PhoneScript_Elm,
        .canAcceptRematch = CanAcceptRematch_Always,
        .mapNum = MAP_NUM(NEW_BARK_TOWN_PROFESSOR_ELMS_LAB),
        .mapGroup = MAP_GROUP(NEW_BARK_TOWN_PROFESSOR_ELMS_LAB),
        .registeredFlag = FLAG_PHONE_CARD_ELM,
		.rematchFlags = {FALSE, FALSE, FALSE, FALSE},
		.rematchOfferedFlag = FALSE,
        .rematchTrainerId = 0xFF,
		.trainerId = TRAINER_NONE,
        .availability = PHONE_AVAILABILITY_ALWAYS,
		.rematchAvailability = {DAY_NEVER, TIME_NEVER},
        .isPermanent = TRUE,
    },
    [PHONE_CONTACT_BIKE_SHOP] = {
        .customDisplayName = sPhoneContactName_BikeShop,
        .phoneScript = PhoneScript_BikeShop,
        .canAcceptRematch = CanAcceptRematch_Always,
        .mapNum = MAP_NUM(GOLDENROD_CITY_BIKE_SHOP),
        .mapGroup = MAP_GROUP(GOLDENROD_CITY_BIKE_SHOP),
        .registeredFlag = 0, //Why is this zero?
		.rematchFlags = {FALSE, FALSE, FALSE, FALSE},
		.rematchOfferedFlag = FALSE,
        .rematchTrainerId = 0xFF,
		.trainerId = TRAINER_NONE,
        .availability = PHONE_AVAILABILITY_ALWAYS,
		.rematchAvailability = {DAY_NEVER, TIME_NEVER},
        .isPermanent = TRUE,
    },
    [PHONE_CONTACT_BILL] = {
        .customDisplayName = sPhoneContactName_Bill,
        .phoneScript = PhoneScript_Bill,
        .canAcceptRematch = CanAcceptRematch_Always,
        .mapNum = MAP_NUM(UNDEFINED),
        .mapGroup = MAP_GROUP(UNDEFINED),
        .registeredFlag = FLAG_PHONE_CARD_BILL,
		.rematchFlags = {FALSE, FALSE, FALSE, FALSE},
		.rematchOfferedFlag = FALSE,
        .rematchTrainerId = 0xFF,
		.trainerId = TRAINER_NONE,
        .availability = PHONE_AVAILABILITY_ALWAYS,
		.rematchAvailability = {DAY_NEVER, TIME_NEVER},
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_HIKER_ANTHONY] = {
        .customDisplayName = sphonecontactname_Hiker_Anthony,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Always,
        .mapNum = MAP_NUM(ROUTE33),
        .mapGroup = MAP_GROUP(ROUTE33),
        .registeredFlag = FLAG_PHONE_CARD_HIKER_ANTHONY,
		.rematchFlags = {FLAG_VISITED_OLIVINE_CITY, FLAG_CLEARED_RADIO_TOWER, FLAG_IS_CHAMPION, FLAG_RETURNED_MACHINE_PART},
		.rematchOfferedFlag = FLAG_ANTHONY_OFFERED_REMATCH,
        .rematchTrainerId = REMATCH_ANTHONY,
		.trainerId = TRAINER_ANTHONY_1,
        .availability = PHONE_AVAILABILITY_ALWAYS,
		.rematchAvailability = {DAY_FRIDAY, TIME_NIGHT},
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_FISHER_RALPH] = {
        .customDisplayName = sphonecontactname_Fisher_Ralph,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Always,
        .mapNum = MAP_NUM(ROUTE32),
        .mapGroup = MAP_GROUP(ROUTE32),
        .registeredFlag = FLAG_PHONE_CARD_FISHER_RALPH,
		.rematchFlags = {FLAG_VISITED_ECRUTEAK_CITY, FLAG_LANDMARK_LAKE_OF_RAGE, FLAG_IS_CHAMPION, FLAG_RETURNED_MACHINE_PART},
		.rematchOfferedFlag = FLAG_RALPH_OFFERED_REMATCH,
        .rematchTrainerId = REMATCH_RALPH,
		.trainerId = TRAINER_RALPH_1,
        .availability = PHONE_AVAILABILITY_ALWAYS,
		.rematchAvailability = {DAY_WEDNESDAY, TIME_MORNING},
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_BUG_CATCHER_ARNIE] = {
        .customDisplayName = sphonecontactname_Bug_Catcher_Arnie,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Always,
        .mapNum = MAP_NUM(ROUTE35),
        .mapGroup = MAP_GROUP(ROUTE35),
        .registeredFlag = FLAG_PHONE_CARD_BUG_CATCHER_ARNIE,
		.rematchFlags = {FLAG_VISITED_BLACKTHORN_CITY, FLAG_IS_CHAMPION, FLAG_RETURNED_MACHINE_PART, FALSE},
		.rematchOfferedFlag = FLAG_ARNIE_OFFERED_REMATCH,
        .rematchTrainerId = REMATCH_ARNIE,
		.trainerId = TRAINER_ARNIE_1,
        .availability = PHONE_AVAILABILITY_ALWAYS,
		.rematchAvailability = {DAY_TUESDAY, TIME_MORNING},
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_LASS_DANA] = {
        .customDisplayName = sphonecontactname_Lass_Dana,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Always,
        .mapNum = MAP_NUM(ROUTE38),
        .mapGroup = MAP_GROUP(ROUTE38),
        .registeredFlag = FLAG_PHONE_CARD_LASS_DANA,
		.rematchFlags = {FLAG_VISITED_CIANWOOD_CITY, FLAG_CLEARED_RADIO_TOWER, FLAG_IS_CHAMPION, FLAG_RETURNED_MACHINE_PART},
		.rematchOfferedFlag = FLAG_DANA_OFFERED_REMATCH,
        .rematchTrainerId = REMATCH_DANA,
		.trainerId = TRAINER_DANA_1,
        .availability = PHONE_AVAILABILITY_ALWAYS,
		.rematchAvailability = {DAY_THURSDAY, TIME_NIGHT},
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_BUENA] = {
        .customDisplayName = sphonecontactname_Buena,
        .phoneScript = PhoneScript_Buena, //Replace with unique script
        .canAcceptRematch = CanAcceptRematch_Always,
        .mapNum = MAP_NUM(RADIO_TOWER_2F),
        .mapGroup = MAP_GROUP(RADIO_TOWER_2F),
        .registeredFlag = FLAG_PHONE_CARD_BUENA,
		.rematchFlags = {FALSE, FALSE, FALSE, FALSE},
		.rematchOfferedFlag = FALSE,
        .rematchTrainerId = 0xFF,
		.trainerId = TRAINER_NONE,
        .availability = PHONE_AVAILABILITY_ALWAYS,
		.rematchAvailability = {DAY_NEVER, TIME_NEVER},
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_YOUNGSTER_JOEY] = {
        .customDisplayName = sphonecontactname_Youngster_Joey,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Always,
        .mapNum = MAP_NUM(ROUTE3),
        .mapGroup = MAP_GROUP(ROUTE3),
        .registeredFlag = FLAG_PHONE_CARD_YOUNGSTER_JOEY,
		.rematchFlags = {FLAG_VISITED_CIANWOOD_CITY, FLAG_VISITED_OLIVINE_CITY, FLAG_CLEARED_RADIO_TOWER, FLAG_IS_CHAMPION},
		.rematchOfferedFlag = FLAG_JOEY_OFFERED_REMATCH,
        .rematchTrainerId = REMATCH_JOEY,
		.trainerId = TRAINER_JOEY_1,
        .availability = PHONE_AVAILABILITY_ALWAYS,
		.rematchAvailability = {DAY_MONDAY, TIME_DAY},
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_BUG_CATCHER_WADE] = {
        .customDisplayName = sphonecontactname_Bug_Catcher_Wade,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Always,
        .mapNum = MAP_NUM(ROUTE31),
        .mapGroup = MAP_GROUP(ROUTE31),
        .registeredFlag = FLAG_PHONE_CARD_BUG_CATCHER_WADE,
		.rematchFlags = {FLAG_VISITED_CIANWOOD_CITY, FLAG_VISITED_MAHOGANY_TOWN, FLAG_CLEARED_RADIO_TOWER, FLAG_IS_CHAMPION},
		.rematchOfferedFlag = FLAG_WADE_OFFERED_REMATCH,
        .rematchTrainerId = REMATCH_WADE,
		.trainerId = TRAINER_WADE_1,
        .availability = PHONE_AVAILABILITY_ALWAYS,
		.rematchAvailability = {DAY_TUESDAY, TIME_NIGHT},
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_CAMPER_TODD] = {
        .customDisplayName = sphonecontactname_Camper_Todd,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Always,
        .mapNum = MAP_NUM(ROUTE34),
        .mapGroup = MAP_GROUP(ROUTE34),
        .registeredFlag = FLAG_PHONE_CARD_CAMPER_TODD,
		.rematchFlags = {FLAG_VISITED_CIANWOOD_CITY, FLAG_VISITED_BLACKTHORN_CITY, FLAG_IS_CHAMPION, FLAG_RETURNED_MACHINE_PART},
		.rematchOfferedFlag = FLAG_TODD_OFFERED_REMATCH,
        .rematchTrainerId = REMATCH_TODD,
		.trainerId = TRAINER_TODD_1,
        .availability = PHONE_AVAILABILITY_ALWAYS,
		.rematchAvailability = {DAY_SUNDAY, TIME_MORNING},
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_PICNICKER_GINA] = {
        .customDisplayName = sphonecontactname_Picnicker_Gina,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Always,
        .mapNum = MAP_NUM(ROUTE34),
        .mapGroup = MAP_GROUP(ROUTE34),
        .registeredFlag = FLAG_PHONE_CARD_PICNICKER_GINA,
		.rematchFlags = {FLAG_VISITED_MAHOGANY_TOWN, FLAG_CLEARED_RADIO_TOWER, FLAG_IS_CHAMPION, FLAG_RETURNED_MACHINE_PART},
		.rematchOfferedFlag = FLAG_GINA_OFFERED_REMATCH,
        .rematchTrainerId = REMATCH_GINA,
		.trainerId = TRAINER_GINA_1,
        .availability = PHONE_AVAILABILITY_ALWAYS,
		.rematchAvailability = {DAY_SUNDAY, TIME_DAY},
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_POKEFAN_BEVERLY] = {
        .customDisplayName = sphonecontactname_Pokefan_Beverly,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Never,
        .mapNum = MAP_NUM(NATIONAL_PARK),
        .mapGroup = MAP_GROUP(NATIONAL_PARK),
        .registeredFlag = FLAG_PHONE_CARD_POKEFAN_BEVERLY,
		.rematchFlags = {FALSE, FALSE, FALSE, FALSE},
		.rematchOfferedFlag = FALSE,
        .rematchTrainerId = 0xFF,
		.trainerId = TRAINER_BEVERLY,
        .availability = PHONE_AVAILABILITY_ALWAYS,
		.rematchAvailability = {DAY_NEVER, TIME_NEVER},
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_SCHOOLBOY_ALAN] = {
        .customDisplayName = sphonecontactname_Schoolboy_Alan,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Always,
        .mapNum = MAP_NUM(ROUTE36),
        .mapGroup = MAP_GROUP(ROUTE36),
        .registeredFlag = FLAG_PHONE_CARD_SCHOOLBOY_ALAN,
		.rematchFlags = {FLAG_VISITED_OLIVINE_CITY, FLAG_VISITED_BLACKTHORN_CITY, FLAG_IS_CHAMPION, FLAG_RETURNED_MACHINE_PART},
		.rematchOfferedFlag = FLAG_ALAN_OFFERED_REMATCH,
        .rematchTrainerId = REMATCH_ALAN,
		.trainerId = TRAINER_ALAN_1,
        .availability = PHONE_AVAILABILITY_ALWAYS,
		.rematchAvailability = {DAY_WEDNESDAY, TIME_DAY},
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_BIRD_KEEPER_VANCE] = {
        .customDisplayName = sphonecontactname_Bird_Keeper_Vance,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Always,
        .mapNum = MAP_NUM(ROUTE44),
        .mapGroup = MAP_GROUP(ROUTE44),
        .registeredFlag = FLAG_PHONE_CARD_BIRD_KEEPER_VANCE,
		.rematchFlags = {FLAG_IS_CHAMPION, FLAG_RETURNED_MACHINE_PART, FALSE, FALSE},
		.rematchOfferedFlag = FLAG_VANCE_OFFERED_REMATCH,
        .rematchTrainerId = REMATCH_VANCE,
		.trainerId = TRAINER_VANCE_1,
        .availability = PHONE_AVAILABILITY_ALWAYS,
		.rematchAvailability = {DAY_WEDNESDAY, TIME_NIGHT},
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_FISHER_TULLY] = {
        .customDisplayName = sphonecontactname_Fisher_Tully,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Always,
        .mapNum = MAP_NUM(ROUTE42),
        .mapGroup = MAP_GROUP(ROUTE42),
        .registeredFlag = FLAG_PHONE_CARD_FISHER_TULLY,
		.rematchFlags = {FLAG_CLEARED_RADIO_TOWER, FLAG_IS_CHAMPION, FLAG_RETURNED_MACHINE_PART, FALSE},
		.rematchOfferedFlag = FLAG_TULLY_OFFERED_REMATCH,
        .rematchTrainerId = REMATCH_TULLY,
		.trainerId = TRAINER_TULLY_1,
        .availability = PHONE_AVAILABILITY_ALWAYS,
		.rematchAvailability = {DAY_SUNDAY, TIME_NIGHT},
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_SAILOR_HUEY] = {
        .customDisplayName = sphonecontactname_Sailor_Huey,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Always,
        .mapNum = MAP_NUM(LIGHTHOUSE_2F),
        .mapGroup = MAP_GROUP(LIGHTHOUSE_2F),
        .registeredFlag = FLAG_PHONE_CARD_SAILOR_HUEY,
		.rematchFlags = {FLAG_CLEARED_RADIO_TOWER, FLAG_IS_CHAMPION, FLAG_RETURNED_MACHINE_PART, FALSE},
		.rematchOfferedFlag = FLAG_HUEY_OFFERED_REMATCH,
        .rematchTrainerId = REMATCH_HUEY,
		.trainerId = TRAINER_HUEY_1,
        .availability = PHONE_AVAILABILITY_ALWAYS,
		.rematchAvailability = {DAY_WEDNESDAY, TIME_NIGHT},
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_PICNICKER_TIFFANY] = {
        .customDisplayName = sphonecontactname_Picnicker_Tiffany,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Always,
        .mapNum = MAP_NUM(ROUTE43),
        .mapGroup = MAP_GROUP(ROUTE43),
        .registeredFlag = FLAG_PHONE_CARD_PICNICKER_TIFFANY,
		.rematchFlags = {FLAG_CLEARED_RADIO_TOWER, FLAG_IS_CHAMPION, FLAG_RETURNED_MACHINE_PART, FALSE},
		.rematchOfferedFlag = FLAG_TIFFANY_OFFERED_REMATCH,
        .rematchTrainerId = REMATCH_TIFFANY,
		.trainerId = TRAINER_TIFFANY_1,
        .availability = PHONE_AVAILABILITY_ALWAYS,
		.rematchAvailability = {DAY_TUESDAY, TIME_DAY},
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_BLACKBELT_KENJI] = {
        .customDisplayName = sphonecontactname_Blackbelt_Kenji,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Never,
        .mapNum = MAP_NUM(ROUTE45),
        .mapGroup = MAP_GROUP(ROUTE45),
        .registeredFlag = FLAG_PHONE_CARD_BLACKBELT_KENJI,
		.rematchFlags = {FALSE, FALSE, FALSE, FALSE},
		.rematchOfferedFlag = FALSE,
        .rematchTrainerId = 0xFF,
		.trainerId = TRAINER_KENJI,
        .availability = PHONE_AVAILABILITY_ALWAYS,
		.rematchAvailability = {DAY_NEVER, TIME_NEVER},
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_PICNICKER_ERIN] = {
        .customDisplayName = sphonecontactname_Picnicker_Erin,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Always,
        .mapNum = MAP_NUM(ROUTE46),
        .mapGroup = MAP_GROUP(ROUTE46),
        .registeredFlag = FLAG_PHONE_CARD_PICNICKER_ERIN,
		.rematchFlags = {FLAG_IS_CHAMPION, FLAG_RETURNED_MACHINE_PART, FALSE, FALSE},
		.rematchOfferedFlag = FLAG_ERIN_OFFERED_REMATCH,
        .rematchTrainerId = REMATCH_ERIN,
		.trainerId = TRAINER_ERIN_1,
        .availability = PHONE_AVAILABILITY_ALWAYS,
		.rematchAvailability = {DAY_SATURDAY, TIME_NIGHT},
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_BIRD_KEEPER_JOSE] = {
        .customDisplayName = sphonecontactname_Bird_Keeper_Jose,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Always,
        .mapNum = MAP_NUM(ROUTE27),
        .mapGroup = MAP_GROUP(ROUTE27),
        .registeredFlag = FLAG_PHONE_CARD_BIRD_KEEPER_JOSE,
		.rematchFlags = {FLAG_IS_CHAMPION, FLAG_RETURNED_MACHINE_PART, FALSE, FALSE},
		.rematchOfferedFlag = FLAG_JOSE_OFFERED_REMATCH,
        .rematchTrainerId = REMATCH_JOSE,
		.trainerId = TRAINER_JOSE_1,
        .availability = PHONE_AVAILABILITY_ALWAYS,
		.rematchAvailability = {DAY_SATURDAY, TIME_NIGHT},
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_SCHOOLBOY_JACK] = {
        .customDisplayName = sphonecontactname_Schoolboy_Jack,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Always,
        .mapNum = MAP_NUM(NATIONAL_PARK),
        .mapGroup = MAP_GROUP(NATIONAL_PARK),
        .registeredFlag = FLAG_PHONE_CARD_SCHOOLBOY_JACK,
		.rematchFlags = {FLAG_VISITED_OLIVINE_CITY, FLAG_IS_CHAMPION, FLAG_RETURNED_MACHINE_PART, FALSE},
		.rematchOfferedFlag = FLAG_JACK_OFFERED_REMATCH,
        .rematchTrainerId = REMATCH_JACK,
		.trainerId = TRAINER_JACK_1,
        .availability = PHONE_AVAILABILITY_ALWAYS,
		.rematchAvailability = {DAY_MONDAY, TIME_MORNING},
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_COOLTRAINER_REENA] = {
        .customDisplayName = sphonecontactname_Cooltrainer_Reena,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Always,
        .mapNum = MAP_NUM(ROUTE26),
        .mapGroup = MAP_GROUP(ROUTE26),
        .registeredFlag = FLAG_PHONE_CARD_COOLTRAINER_REENA,
		.rematchFlags = {FALSE, FALSE, FALSE, FALSE},
		.rematchOfferedFlag = FLAG_REENA_OFFERED_REMATCH,
        .rematchTrainerId = REMATCH_REENA,
		.trainerId = TRAINER_REENA_1,
        .availability = PHONE_AVAILABILITY_ALWAYS,
		.rematchAvailability = {DAY_SUNDAY, TIME_MORNING},
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_COOLTRAINER_GAVEN] = {
        .customDisplayName = sphonecontactname_Cooltrainer_Gaven,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Always,
        .mapNum = MAP_NUM(ROUTE26),
        .mapGroup = MAP_GROUP(ROUTE26),
        .registeredFlag = FLAG_PHONE_CARD_COOLTRAINER_GAVEN,
		.rematchFlags = {FLAG_IS_CHAMPION, FLAG_RETURNED_MACHINE_PART, FALSE, FALSE},
		.rematchOfferedFlag = FLAG_GAVEN_OFFERED_REMATCH,
        .rematchTrainerId = REMATCH_GAVEN,
		.trainerId = TRAINER_GAVEN_1,
        .availability = PHONE_AVAILABILITY_ALWAYS,
		.rematchAvailability = {DAY_THURSDAY, TIME_MORNING},
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_COOLTRAINER_BETH] = {
        .customDisplayName = sphonecontactname_Cooltrainer_Beth,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Always,
        .mapNum = MAP_NUM(ROUTE26),
        .mapGroup = MAP_GROUP(ROUTE26),
        .registeredFlag = FLAG_PHONE_CARD_COOLTRAINER_BETH,
		.rematchFlags = {FLAG_IS_CHAMPION, FLAG_RETURNED_MACHINE_PART, FALSE, FALSE},
		.rematchOfferedFlag = FLAG_BETH_OFFERED_REMATCH,
        .rematchTrainerId = REMATCH_BETH,
		.trainerId = TRAINER_BETH_1,
        .availability = PHONE_AVAILABILITY_ALWAYS,
		.rematchAvailability = {DAY_FRIDAY, TIME_DAY},
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_PICNICKER_LIZ] = {
        .customDisplayName = sphonecontactname_Picnicker_Liz,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Always,
        .mapNum = MAP_NUM(ROUTE32),
        .mapGroup = MAP_GROUP(ROUTE32),
        .registeredFlag = FLAG_PHONE_CARD_PICNICKER_LIZ,
		.rematchFlags = {FLAG_VISITED_ECRUTEAK_CITY, FLAG_VISITED_MAHOGANY_TOWN, FLAG_CLEARED_RADIO_TOWER, FLAG_IS_CHAMPION},
		.rematchOfferedFlag = FLAG_LIZ_OFFERED_REMATCH,
        .rematchTrainerId = REMATCH_LIZ,
		.trainerId = TRAINER_LIZ_1,
        .availability = PHONE_AVAILABILITY_ALWAYS,
		.rematchAvailability = {DAY_THURSDAY, TIME_DAY},
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_JUGGLER_IRWIN] = {
        .customDisplayName = sphonecontactname_Juggler_Irwin,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Never,
        .mapNum = MAP_NUM(ROUTE35),
        .mapGroup = MAP_GROUP(ROUTE35),
        .registeredFlag = FLAG_PHONE_CARD_JUGGLER_IRWIN,
		.rematchFlags = {FALSE, FALSE, FALSE, FALSE},
		.rematchOfferedFlag = FALSE,
        .rematchTrainerId = 0xFF,
		.trainerId = TRAINER_IRWIN,
        .availability = PHONE_AVAILABILITY_ALWAYS,
		.rematchAvailability = {DAY_NEVER, TIME_NEVER},
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_POKEFAN_DEREK] = {
        .customDisplayName = sphonecontactname_Pokefan_Derek,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Never,
        .mapNum = MAP_NUM(ROUTE38),
        .mapGroup = MAP_GROUP(ROUTE38),
        .registeredFlag = FLAG_PHONE_CARD_POKEFAN_DEREK,
		.rematchFlags = {FALSE, FALSE, FALSE, FALSE},
		.rematchOfferedFlag = FALSE,
        .rematchTrainerId = 0xFF,
		.trainerId = TRAINER_DEREK,
        .availability = PHONE_AVAILABILITY_ALWAYS,
		.rematchAvailability = {DAY_NEVER, TIME_NEVER},
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_POKEMANIAC_BRENT] = {
        .customDisplayName = sphonecontactname_Pokemaniac_Brent,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Always,
        .mapNum = MAP_NUM(ROUTE43),
        .mapGroup = MAP_GROUP(ROUTE43),
        .registeredFlag = FLAG_PHONE_CARD_POKEMANIAC_BRENT,
		.rematchFlags = {FLAG_VISITED_MAHOGANY_TOWN, FLAG_IS_CHAMPION, FLAG_RETURNED_MACHINE_PART, FALSE},
		.rematchOfferedFlag = FLAG_BRENT_OFFERED_REMATCH,
        .rematchTrainerId = REMATCH_BRENT,
		.trainerId = TRAINER_BRENT_1,
        .availability = PHONE_AVAILABILITY_ALWAYS,
		.rematchAvailability = {DAY_MONDAY, TIME_MORNING},
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_SCHOOLBOY_CHAD] = {
        .customDisplayName = sphonecontactname_Schoolboy_Chad,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Always,
        .mapNum = MAP_NUM(ROUTE38),
        .mapGroup = MAP_GROUP(ROUTE38),
        .registeredFlag = FLAG_PHONE_CARD_SCHOOLBOY_CHAD,
		.rematchFlags = {FLAG_VISITED_MAHOGANY_TOWN, FLAG_CLEARED_RADIO_TOWER, FLAG_IS_CHAMPION, FLAG_RETURNED_MACHINE_PART},
		.rematchOfferedFlag = FLAG_CHAD_OFFERED_REMATCH,
        .rematchTrainerId = REMATCH_CHAD,
		.trainerId = TRAINER_CHAD_1,
        .availability = PHONE_AVAILABILITY_ALWAYS,
		.rematchAvailability = {DAY_FRIDAY, TIME_MORNING},
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_FISHER_WILTON] = {
        .customDisplayName = sphonecontactname_Fisher_Wilton,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Always,
        .mapNum = MAP_NUM(ROUTE44),
        .mapGroup = MAP_GROUP(ROUTE44),
        .registeredFlag = FLAG_PHONE_CARD_FISHER_WILTON,
		.rematchFlags = {FLAG_IS_CHAMPION, FLAG_RETURNED_MACHINE_PART, FALSE, FALSE},
		.rematchOfferedFlag = FLAG_WILTON_OFFERED_REMATCH,
        .rematchTrainerId = REMATCH_WILTON,
		.trainerId = TRAINER_WILTON_1,
        .availability = PHONE_AVAILABILITY_ALWAYS,
		.rematchAvailability = {DAY_THURSDAY, TIME_MORNING},
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_HIKER_PARRY] = {
        .customDisplayName = sphonecontactname_Hiker_Parry,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Always,
        .mapNum = MAP_NUM(ROUTE45),
        .mapGroup = MAP_GROUP(ROUTE45),
        .registeredFlag = FLAG_PHONE_CARD_HIKER_PARRY,
		.rematchFlags = {FLAG_IS_CHAMPION, FLAG_RETURNED_MACHINE_PART, FALSE, FALSE},
		.rematchOfferedFlag = FLAG_PARRY_OFFERED_REMATCH,
        .rematchTrainerId = REMATCH_PARRY,
		.trainerId = TRAINER_PARRY_1,
        .availability = PHONE_AVAILABILITY_ALWAYS,
		.rematchAvailability = {DAY_FRIDAY, TIME_DAY},
        .isPermanent = FALSE,
    },
};

void SelectMessage_StandardMatchCallTrainer(const struct PhoneContact *phoneContact, bool8 isCallingPlayer)
{
    SelectMatchCallMessage(phoneContact->trainerId, gStringVar4, isCallingPlayer, phoneContact);
}

static bool8 CanAcceptRematch_Always(s8 dayOfWeek, s8 hour)
{
    return TRUE;
}

static bool8 CanAcceptRematch_Never(s8 dayOfWeek, s8 hour)
{
    return FALSE;
}

static bool8 CanAcceptRematch_MondayDaytime(s8 dayOfWeek, s8 hour)
{
    return dayOfWeek == DAY_MONDAY
        && GetTimeOfDay(hour) == TIME_DAY;
}

bool8 CanPhoneContactAcceptRematch(const struct PhoneContact *phoneContact, s8 dayOfWeek, s8 hour)
{
	return (phoneContact->rematchAvailability[0] == dayOfWeek) && (phoneContact->rematchAvailability[1] == hour) &&
			(!FlagGet(phoneContact->rematchOfferedFlag));
}

bool8 IsPhoneContactAvailable(const struct PhoneContact *phoneContact, s8 dayOfWeek, s8 hour)
{
    switch (phoneContact->availability)
    {
    case PHONE_AVAILABILITY_ALWAYS:
        return TRUE;
    default:
        return TRUE;
    }
}

static const u8 sPhoneContactName_UnknownContact[] = _("UNKNOWN CONTACT");

const bool8 FindPhoneContactNameFromFlag(void){
	int i;
	u16 contactFlag = gSpecialVar_0x8003;

	for(i=0;i<PHONE_CONTACT_COUNT;i++){
		if(gPhoneContacts[i].registeredFlag == contactFlag){
			StringCopy(gStringVar1, gPhoneContacts[i].customDisplayName);
			return TRUE;
		}
	}
	StringCopy(gStringVar1, sPhoneContactName_UnknownContact);
	return FALSE;
}

const u8 *BuildPhoneContactDisplayName(const struct PhoneContact *phoneContact, u8 *dest)
{
    int i, j;
    int classXOffset;
    const u8 *src;

    if (phoneContact->customDisplayName)
    {
        return phoneContact->customDisplayName;
    }
    else if (phoneContact->rematchTrainerId != 0xFF)
    {
        int trainerId = gRematchTable[phoneContact->rematchTrainerId].trainerIds[0];
        src = gTrainers[trainerId].trainerName;
        i = 0;
        for (j = 0; src[j] != EOS; j++)
            dest[i++] = src[j];

        dest[i++] = CHAR_COLON;
        dest[i++] = EXT_CTRL_CODE_BEGIN;
        dest[i++] = EXT_CTRL_CODE_FONT;
        dest[i++] = 0;

        classXOffset = GetStringRightAlignXOffset(0, gTrainerClassNames[gTrainers[trainerId].trainerClass], 128);
        dest[i++] = EXT_CTRL_CODE_BEGIN;
        dest[i++] = EXT_CTRL_CODE_CLEAR_TO;
        dest[i++] = classXOffset;

        src = gTrainerClassNames[gTrainers[trainerId].trainerClass];
        for (j = 0; src[j] != EOS; j++)
            dest[i++] = src[j];

        dest[i++] = EOS;
        return dest;
    }
    else
    {
        return sPhoneContactName_UnknownContact;
    }
}

const u8 *BuildPhoneContactDisplayNameForCall(const struct PhoneContact *phoneContact, u8 *dest)
{
    int i, j;
    int classXOffset;
    const u8 *src;

    if (phoneContact->customDisplayName)
    {
        return phoneContact->customDisplayName;
    }
    else if (phoneContact->rematchTrainerId != 0xFF)
    {
        int trainerId = gRematchTable[phoneContact->rematchTrainerId].trainerIds[0];
        src = gTrainers[trainerId].trainerName;
        i = 0;
        for (j = 0; src[j] != EOS; j++)
            dest[i++] = src[j];

        dest[i++] = CHAR_COLON;
        dest[i++] = CHAR_NEWLINE;
        dest[i++] = EXT_CTRL_CODE_BEGIN;
        dest[i++] = EXT_CTRL_CODE_FONT;
        dest[i++] = 0;

        classXOffset = GetStringRightAlignXOffset(0, gTrainerClassNames[gTrainers[trainerId].trainerClass], 76);
        dest[i++] = EXT_CTRL_CODE_BEGIN;
        dest[i++] = EXT_CTRL_CODE_CLEAR_TO;
        dest[i++] = classXOffset;

        src = gTrainerClassNames[gTrainers[trainerId].trainerClass];
        for (j = 0; src[j] != EOS; j++)
            dest[i++] = src[j];

        dest[i++] = EOS;
        return dest;
    }
    else
    {
        return sPhoneContactName_UnknownContact;
    }
}
