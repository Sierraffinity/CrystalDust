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
static const u8 sphonecontactname_Bug_Catcher_Wader[] = _("BUG CATCHER WADER");
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
static const u8 sphonecontactname_Bug_Catcher_Wade[] = _("BUG CATCHER WADE");
static const u8 sphonecontactname_Picnicker_Liz[] = _("PICNICKER LIZ");
static const u8 sphonecontactname_Juggler_Irwin[] = _("JUGGLER IRWIN");
static const u8 sphonecontactname_Pokefan_Derek[] = _("POKEFAN DEREK");
static const u8 sphonecontactname_Fisher_Chris[] = _("FISHERMAN CHRIS");
static const u8 sphonecontactname_Pokemaniac_Brent[] = _("POKEMANIAC BRENT");


const struct PhoneContact gPhoneContacts[PHONE_CONTACT_COUNT] =
{
    [PHONE_CONTACT_MOM] = {
        .customDisplayName = sPhoneContactName_Mom,
        .phoneScript = PhoneScript_Mom,
        .canAcceptRematch = CanAcceptRematch_Always,
        .mapNum = MAP_NUM(NEW_BARK_TOWN_PLAYERS_HOUSE_1F),
        .mapGroup = MAP_GROUP(NEW_BARK_TOWN_PLAYERS_HOUSE_1F),
        .registeredFlag = FLAG_PHONE_CARD_MOM,
        .rematchTrainerId = 0xFF,
        .availability = PHONE_AVAILABILITY_ALWAYS,
        .isPermanent = TRUE,
    },
    [PHONE_CONTACT_ELM] = {
        .customDisplayName = sPhoneContactName_ProfessorElm,
        .phoneScript = PhoneScript_Elm,
        .canAcceptRematch = CanAcceptRematch_Always,
        .mapNum = MAP_NUM(NEW_BARK_TOWN_PROFESSOR_ELMS_LAB),
        .mapGroup = MAP_GROUP(NEW_BARK_TOWN_PROFESSOR_ELMS_LAB),
        .registeredFlag = FLAG_PHONE_CARD_ELM,
        .rematchTrainerId = 0xFF,
        .availability = PHONE_AVAILABILITY_ALWAYS,
        .isPermanent = TRUE,
    },
    [PHONE_CONTACT_BIKE_SHOP] = {
        .customDisplayName = sPhoneContactName_BikeShop,
        .phoneScript = PhoneScript_BikeShop,
        .canAcceptRematch = CanAcceptRematch_Always,
        .mapNum = MAP_NUM(GOLDENROD_CITY_BIKE_SHOP),
        .mapGroup = MAP_GROUP(GOLDENROD_CITY_BIKE_SHOP),
        .registeredFlag = 0,
        .rematchTrainerId = 0xFF,
        .availability = PHONE_AVAILABILITY_ALWAYS,
        .isPermanent = TRUE,
    },
    [PHONE_CONTACT_BILL] = {
        .customDisplayName = sPhoneContactName_Bill,
        .phoneScript = PhoneScript_Bill,
        .canAcceptRematch = CanAcceptRematch_Always,
        .mapNum = MAP_NUM(UNDEFINED),
        .mapGroup = MAP_GROUP(UNDEFINED),
        .registeredFlag = FLAG_PHONE_CARD_BILL,
        .rematchTrainerId = 0xFF,
        .availability = PHONE_AVAILABILITY_ALWAYS,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_HIKER_ANTHONY] = {
        .customDisplayName = sphonecontactname_Hiker_Anthony,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Always,
        .mapNum = MAP_NUM(ROUTE33),
        .mapGroup = MAP_GROUP(ROUTE33),
        .registeredFlag = FLAG_PHONE_CARD_HIKER_ANTHONY,
        .rematchTrainerId = REMATCH_ANTHONY,
        .availability = PHONE_AVAILABILITY_ALWAYS,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_FISHER_RALPH] = {
        .customDisplayName = sphonecontactname_Fisher_Ralph,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Always,
        .mapNum = MAP_NUM(ROUTE32),
        .mapGroup = MAP_GROUP(ROUTE32),
        .registeredFlag = FLAG_PHONE_CARD_FISHER_RALPH,
        .rematchTrainerId = REMATCH_RALPH,
        .availability = PHONE_AVAILABILITY_ALWAYS,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_BUG_CATCHER_ARNIE] = {
        .customDisplayName = sphonecontactname_Bug_Catcher_Arnie,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Always,
        .mapNum = MAP_NUM(ROUTE35),
        .mapGroup = MAP_GROUP(ROUTE35),
        .registeredFlag = FLAG_PHONE_CARD_BUG_CATCHER_ARNIE,
        .rematchTrainerId = REMATCH_ARNIE,
        .availability = PHONE_AVAILABILITY_ALWAYS,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_LASS_DANA] = {
        .customDisplayName = sphonecontactname_Lass_Dana,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Always,
        .mapNum = MAP_NUM(ROUTE38),
        .mapGroup = MAP_GROUP(ROUTE38),
        .registeredFlag = FLAG_PHONE_CARD_LASS_DANA,
        .rematchTrainerId = REMATCH_DANA,
        .availability = PHONE_AVAILABILITY_ALWAYS,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_BUENA] = {
        .customDisplayName = sphonecontactname_Buena,
        .phoneScript = PhoneScript_StandardMatchCallTrainer, //Replace with unique script
        .canAcceptRematch = CanAcceptRematch_Always,
        .mapNum = MAP_NUM(RADIO_TOWER_2F),
        .mapGroup = MAP_GROUP(RADIO_TOWER_2F),
        .registeredFlag = FLAG_PHONE_CARD_BUENA,
        .rematchTrainerId = 0xFF,
        .availability = PHONE_AVAILABILITY_ALWAYS,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_YOUNGSTER_JOEY] = {
        .customDisplayName = sphonecontactname_Youngster_Joey,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Always,
        .mapNum = MAP_NUM(ROUTE3),
        .mapGroup = MAP_GROUP(ROUTE3),
        .registeredFlag = FLAG_PHONE_CARD_YOUNGSTER_JOEY,
        .rematchTrainerId = REMATCH_JOEY,
        .availability = PHONE_AVAILABILITY_ALWAYS,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_BUG_CATCHER_WADER] = {
        .customDisplayName = sphonecontactname_Bug_Catcher_Wader,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Always,
        .mapNum = MAP_NUM(ROUTE31),
        .mapGroup = MAP_GROUP(ROUTE31),
        .registeredFlag = FLAG_PHONE_CARD_BUG_CATCHER_WADER,
        .rematchTrainerId = REMATCH_WADER,
        .availability = PHONE_AVAILABILITY_ALWAYS,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_CAMPER_TODD] = {
        .customDisplayName = sphonecontactname_Camper_Todd,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Always,
        .mapNum = MAP_NUM(ROUTE34),
        .mapGroup = MAP_GROUP(ROUTE34),
        .registeredFlag = FLAG_PHONE_CARD_CAMPER_TODD,
        .rematchTrainerId = REMATCH_TODD,
        .availability = PHONE_AVAILABILITY_ALWAYS,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_PICNICKER_GINA] = {
        .customDisplayName = sphonecontactname_Picnicker_Gina,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Always,
        .mapNum = MAP_NUM(ROUTE34),
        .mapGroup = MAP_GROUP(ROUTE34),
        .registeredFlag = FLAG_PHONE_CARD_PICNICKER_GINA,
        .rematchTrainerId = REMATCH_GINA,
        .availability = PHONE_AVAILABILITY_ALWAYS,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_POKEFAN_BEVERLY] = {
        .customDisplayName = sphonecontactname_Pokefan_Beverly,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Always,
        .mapNum = MAP_NUM(NATIONAL_PARK),
        .mapGroup = MAP_GROUP(NATIONAL_PARK),
        .registeredFlag = FLAG_PHONE_CARD_POKEFAN_BEVERLY,
        .rematchTrainerId = 0xFF,
        .availability = PHONE_AVAILABILITY_ALWAYS,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_SCHOOLBOY_ALAN] = {
        .customDisplayName = sphonecontactname_Schoolboy_Alan,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Always,
        .mapNum = MAP_NUM(ROUTE36),
        .mapGroup = MAP_GROUP(ROUTE36),
        .registeredFlag = FLAG_PHONE_CARD_SCHOOLBOY_ALAN,
        .rematchTrainerId = REMATCH_ALAN,
        .availability = PHONE_AVAILABILITY_ALWAYS,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_BIRD_KEEPER_VANCE] = {
        .customDisplayName = sphonecontactname_Bird_Keeper_Vance,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Always,
        .mapNum = MAP_NUM(ROUTE44),
        .mapGroup = MAP_GROUP(ROUTE44),
        .registeredFlag = FLAG_PHONE_CARD_BIRD_KEEPER_VANCE,
        .rematchTrainerId = REMATCH_VANCE,
        .availability = PHONE_AVAILABILITY_ALWAYS,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_FISHER_TULLY] = {
        .customDisplayName = sphonecontactname_Fisher_Tully,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Always,
        .mapNum = MAP_NUM(ROUTE42),
        .mapGroup = MAP_GROUP(ROUTE42),
        .registeredFlag = FLAG_PHONE_CARD_FISHER_TULLY,
        .rematchTrainerId = REMATCH_TULLY,
        .availability = PHONE_AVAILABILITY_ALWAYS,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_SAILOR_HUEY] = {
        .customDisplayName = sphonecontactname_Sailor_Huey,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Always,
        .mapNum = MAP_NUM(LIGHTHOUSE_2F),
        .mapGroup = MAP_GROUP(LIGHTHOUSE_2F),
        .registeredFlag = FLAG_PHONE_CARD_SAILOR_HUEY,
        .rematchTrainerId = REMATCH_HUEY,
        .availability = PHONE_AVAILABILITY_ALWAYS,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_PICNICKER_TIFFANY] = {
        .customDisplayName = sphonecontactname_Picnicker_Tiffany,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Always,
        .mapNum = MAP_NUM(ROUTE43),
        .mapGroup = MAP_GROUP(ROUTE43),
        .registeredFlag = FLAG_PHONE_CARD_PICNICKER_TIFFANY,
        .rematchTrainerId = REMATCH_TIFFANY,
        .availability = PHONE_AVAILABILITY_ALWAYS,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_BLACKBELT_KENJI] = {
        .customDisplayName = sphonecontactname_Blackbelt_Kenji,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Always,
        .mapNum = MAP_NUM(ROUTE45),
        .mapGroup = MAP_GROUP(ROUTE45),
        .registeredFlag = FLAG_PHONE_CARD_BLACKBELT_KENJI,
        .rematchTrainerId = 0xFF,
        .availability = PHONE_AVAILABILITY_ALWAYS,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_PICNICKER_ERIN] = {
        .customDisplayName = sphonecontactname_Picnicker_Erin,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Always,
        .mapNum = MAP_NUM(ROUTE46),
        .mapGroup = MAP_GROUP(ROUTE46),
        .registeredFlag = FLAG_PHONE_CARD_PICNICKER_ERIN,
        .rematchTrainerId = REMATCH_ERIN,
        .availability = PHONE_AVAILABILITY_ALWAYS,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_BIRD_KEEPER_JOSE] = {
        .customDisplayName = sphonecontactname_Bird_Keeper_Jose,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Always,
        .mapNum = MAP_NUM(ROUTE27),
        .mapGroup = MAP_GROUP(ROUTE27),
        .registeredFlag = FLAG_PHONE_CARD_BIRD_KEEPER_JOSE,
        .rematchTrainerId = REMATCH_JOSE,
        .availability = PHONE_AVAILABILITY_ALWAYS,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_SCHOOLBOY_JACK] = {
        .customDisplayName = sphonecontactname_Schoolboy_Jack,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Always,
        .mapNum = MAP_NUM(NATIONAL_PARK),
        .mapGroup = MAP_GROUP(NATIONAL_PARK),
        .registeredFlag = FLAG_PHONE_CARD_SCHOOLBOY_JACK,
        .rematchTrainerId = REMATCH_JACK,
        .availability = PHONE_AVAILABILITY_ALWAYS,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_COOLTRAINER_REENA] = {
        .customDisplayName = sphonecontactname_Cooltrainer_Reena,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Always,
        .mapNum = MAP_NUM(ROUTE26),
        .mapGroup = MAP_GROUP(ROUTE26),
        .registeredFlag = FLAG_PHONE_CARD_COOLTRAINER_REENA,
        .rematchTrainerId = REMATCH_REENA,
        .availability = PHONE_AVAILABILITY_ALWAYS,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_COOLTRAINER_GAVEN] = {
        .customDisplayName = sphonecontactname_Cooltrainer_Gaven,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Always,
        .mapNum = MAP_NUM(ROUTE26),
        .mapGroup = MAP_GROUP(ROUTE26),
        .registeredFlag = FLAG_PHONE_CARD_COOLTRAINER_GAVEN,
        .rematchTrainerId = REMATCH_GAVEN,
        .availability = PHONE_AVAILABILITY_ALWAYS,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_COOLTRAINER_BETH] = {
        .customDisplayName = sphonecontactname_Cooltrainer_Beth,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Always,
        .mapNum = MAP_NUM(ROUTE26),
        .mapGroup = MAP_GROUP(ROUTE26),
        .registeredFlag = FLAG_PHONE_CARD_COOLTRAINER_BETH,
        .rematchTrainerId = REMATCH_BETH,
        .availability = PHONE_AVAILABILITY_ALWAYS,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_BUG_CATCHER_WADE] = {
        .customDisplayName = sphonecontactname_Bug_Catcher_Wade,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Always,
        .mapNum = MAP_NUM(ROUTE31),
        .mapGroup = MAP_GROUP(ROUTE31),
        .registeredFlag = FLAG_PHONE_CARD_BUG_CATCHER_WADE,
        .rematchTrainerId = REMATCH_WADE,
        .availability = PHONE_AVAILABILITY_ALWAYS,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_PICNICKER_LIZ] = {
        .customDisplayName = sphonecontactname_Picnicker_Liz,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Always,
        .mapNum = MAP_NUM(ROUTE32),
        .mapGroup = MAP_GROUP(ROUTE32),
        .registeredFlag = FLAG_PHONE_CARD_PICNICKER_LIZ,
        .rematchTrainerId = REMATCH_LIZ,
        .availability = PHONE_AVAILABILITY_ALWAYS,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_JUGGLER_IRWIN] = {
        .customDisplayName = sphonecontactname_Juggler_Irwin,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Always,
        .mapNum = MAP_NUM(ROUTE35),
        .mapGroup = MAP_GROUP(ROUTE35),
        .registeredFlag = FLAG_PHONE_CARD_JUGGLER_IRWIN,
        .rematchTrainerId = 0xFF,
        .availability = PHONE_AVAILABILITY_ALWAYS,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_POKEFAN_DEREK] = {
        .customDisplayName = sphonecontactname_Pokefan_Derek,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Always,
        .mapNum = MAP_NUM(ROUTE38),
        .mapGroup = MAP_GROUP(ROUTE38),
        .registeredFlag = FLAG_PHONE_CARD_POKEFAN_DEREK,
        .rematchTrainerId = 0xFF,
        .availability = PHONE_AVAILABILITY_ALWAYS,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_FISHER_CHRIS] = {
        .customDisplayName = sphonecontactname_Fisher_Chris,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Always,
        .mapNum = MAP_NUM(ROUTE42),
        .mapGroup = MAP_GROUP(ROUTE42),
        .registeredFlag = FLAG_PHONE_CARD_FISHER_CHRIS,
        .rematchTrainerId = 0xFF,
        .availability = PHONE_AVAILABILITY_ALWAYS,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_POKEMANIAC_BRENT] = {
        .customDisplayName = sphonecontactname_Pokemaniac_Brent,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Always,
        .mapNum = MAP_NUM(ROUTE43),
        .mapGroup = MAP_GROUP(ROUTE43),
        .registeredFlag = FLAG_PHONE_CARD_POKEMANIAC_BRENT,
        .rematchTrainerId = REMATCH_BRENT,
        .availability = PHONE_AVAILABILITY_ALWAYS,
        .isPermanent = FALSE,
    }, //Unused Phone Contacts After This Point
    [PHONE_CONTACT_ANNA_AND_MEG] = {
        .customDisplayName = NULL,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Always,
        .mapNum = MAP_NUM(UNDEFINED),
        .mapGroup = MAP_GROUP(UNDEFINED),
        .registeredFlag = FLAG_PHONE_CARD_ANNA_AND_MEG,
        .rematchTrainerId = REMATCH_ANNA_AND_MEG,
        .availability = PHONE_AVAILABILITY_ALWAYS,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_ISABEL] = {
        .customDisplayName = NULL,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Always,
        .mapNum = MAP_NUM(UNDEFINED),
        .mapGroup = MAP_GROUP(UNDEFINED),
        .registeredFlag = FLAG_PHONE_CARD_ISABEL,
        .rematchTrainerId = REMATCH_ISABEL,
        .availability = PHONE_AVAILABILITY_ALWAYS,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_MIGUEL] = {
        .customDisplayName = NULL,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Always,
        .mapNum = MAP_NUM(UNDEFINED),
        .mapGroup = MAP_GROUP(UNDEFINED),
        .registeredFlag = FLAG_PHONE_CARD_MIGUEL,
        .rematchTrainerId = REMATCH_MIGUEL,
        .availability = PHONE_AVAILABILITY_ALWAYS,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_TIMOTHY] = {
        .customDisplayName = NULL,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Always,
        .mapNum = MAP_NUM(UNDEFINED),
        .mapGroup = MAP_GROUP(UNDEFINED),
        .registeredFlag = FLAG_PHONE_CARD_TIMOTHY,
        .rematchTrainerId = REMATCH_TIMOTHY,
        .availability = PHONE_AVAILABILITY_ALWAYS,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_SHELBY] = {
        .customDisplayName = NULL,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Always,
        .mapNum = MAP_NUM(UNDEFINED),
        .mapGroup = MAP_GROUP(UNDEFINED),
        .registeredFlag = FLAG_PHONE_CARD_SHELBY,
        .rematchTrainerId = REMATCH_SHELBY,
        .availability = PHONE_AVAILABILITY_ALWAYS,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_CALVIN] = {
        .customDisplayName = NULL,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Always,
        .mapNum = MAP_NUM(UNDEFINED),
        .mapGroup = MAP_GROUP(UNDEFINED),
        .registeredFlag = FLAG_PHONE_CARD_CALVIN,
        .rematchTrainerId = REMATCH_CALVIN,
        .availability = PHONE_AVAILABILITY_ALWAYS,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_ELLIOT] = {
        .customDisplayName = NULL,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Always,
        .mapNum = MAP_NUM(UNDEFINED),
        .mapGroup = MAP_GROUP(UNDEFINED),
        .registeredFlag = FLAG_PHONE_CARD_ELLIOT,
        .rematchTrainerId = REMATCH_ELLIOT,
        .availability = PHONE_AVAILABILITY_ALWAYS,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_ISAIAH] = {
        .customDisplayName = NULL,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Always,
        .mapNum = MAP_NUM(UNDEFINED),
        .mapGroup = MAP_GROUP(UNDEFINED),
        .registeredFlag = FLAG_PHONE_CARD_ISAIAH,
        .rematchTrainerId = REMATCH_ISAIAH,
        .availability = PHONE_AVAILABILITY_ALWAYS,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_MARIA] = {
        .customDisplayName = NULL,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Always,
        .mapNum = MAP_NUM(UNDEFINED),
        .mapGroup = MAP_GROUP(UNDEFINED),
        .registeredFlag = FLAG_PHONE_CARD_MARIA,
        .rematchTrainerId = REMATCH_MARIA,
        .availability = PHONE_AVAILABILITY_ALWAYS,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_ABIGAIL] = {
        .customDisplayName = NULL,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Always,
        .mapNum = MAP_NUM(UNDEFINED),
        .mapGroup = MAP_GROUP(UNDEFINED),
        .registeredFlag = FLAG_PHONE_CARD_ABIGAIL,
        .rematchTrainerId = REMATCH_ABIGAIL,
        .availability = PHONE_AVAILABILITY_ALWAYS,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_DYLAN] = {
        .customDisplayName = NULL,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Always,
        .mapNum = MAP_NUM(UNDEFINED),
        .mapGroup = MAP_GROUP(UNDEFINED),
        .registeredFlag = FLAG_PHONE_CARD_DYLAN,
        .rematchTrainerId = REMATCH_DYLAN,
        .availability = PHONE_AVAILABILITY_ALWAYS,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_KATELYN] = {
        .customDisplayName = NULL,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Always,
        .mapNum = MAP_NUM(UNDEFINED),
        .mapGroup = MAP_GROUP(UNDEFINED),
        .registeredFlag = FLAG_PHONE_CARD_KATELYN,
        .rematchTrainerId = REMATCH_KATELYN,
        .availability = PHONE_AVAILABILITY_ALWAYS,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_BENJAMIN] = {
        .customDisplayName = NULL,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Always,
        .mapNum = MAP_NUM(UNDEFINED),
        .mapGroup = MAP_GROUP(UNDEFINED),
        .registeredFlag = FLAG_PHONE_CARD_BENJAMIN,
        .rematchTrainerId = REMATCH_BENJAMIN,
        .availability = PHONE_AVAILABILITY_ALWAYS,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_PABLO] = {
        .customDisplayName = NULL,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Always,
        .mapNum = MAP_NUM(UNDEFINED),
        .mapGroup = MAP_GROUP(UNDEFINED),
        .registeredFlag = FLAG_PHONE_CARD_PABLO,
        .rematchTrainerId = REMATCH_PABLO,
        .availability = PHONE_AVAILABILITY_ALWAYS,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_NICOLAS] = {
        .customDisplayName = NULL,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Always,
        .mapNum = MAP_NUM(UNDEFINED),
        .mapGroup = MAP_GROUP(UNDEFINED),
        .registeredFlag = FLAG_PHONE_CARD_NICOLAS,
        .rematchTrainerId = REMATCH_NICOLAS,
        .availability = PHONE_AVAILABILITY_ALWAYS,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_ROBERT] = {
        .customDisplayName = NULL,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Always,
        .mapNum = MAP_NUM(UNDEFINED),
        .mapGroup = MAP_GROUP(UNDEFINED),
        .registeredFlag = FLAG_PHONE_CARD_ROBERT,
        .rematchTrainerId = REMATCH_ROBERT,
        .availability = PHONE_AVAILABILITY_ALWAYS,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_LAO] = {
        .customDisplayName = NULL,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Always,
        .mapNum = MAP_NUM(UNDEFINED),
        .mapGroup = MAP_GROUP(UNDEFINED),
        .registeredFlag = FLAG_PHONE_CARD_LAO,
        .rematchTrainerId = REMATCH_LAO,
        .availability = PHONE_AVAILABILITY_ALWAYS,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_CYNDY] = {
        .customDisplayName = NULL,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Always,
        .mapNum = MAP_NUM(UNDEFINED),
        .mapGroup = MAP_GROUP(UNDEFINED),
        .registeredFlag = FLAG_PHONE_CARD_CYNDY,
        .rematchTrainerId = REMATCH_CYNDY,
        .availability = PHONE_AVAILABILITY_ALWAYS,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_MADELINE] = {
        .customDisplayName = NULL,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Always,
        .mapNum = MAP_NUM(UNDEFINED),
        .mapGroup = MAP_GROUP(UNDEFINED),
        .registeredFlag = FLAG_PHONE_CARD_MADELINE,
        .rematchTrainerId = REMATCH_MADELINE,
        .availability = PHONE_AVAILABILITY_ALWAYS,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_JENNY] = {
        .customDisplayName = NULL,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Always,
        .mapNum = MAP_NUM(UNDEFINED),
        .mapGroup = MAP_GROUP(UNDEFINED),
        .registeredFlag = FLAG_PHONE_CARD_JENNY,
        .rematchTrainerId = REMATCH_JENNY,
        .availability = PHONE_AVAILABILITY_ALWAYS,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_DIANA] = {
        .customDisplayName = NULL,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Always,
        .mapNum = MAP_NUM(UNDEFINED),
        .mapGroup = MAP_GROUP(UNDEFINED),
        .registeredFlag = FLAG_PHONE_CARD_DIANA,
        .rematchTrainerId = REMATCH_DIANA,
        .availability = PHONE_AVAILABILITY_ALWAYS,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_AMY_AND_LIV] = {
        .customDisplayName = NULL,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Always,
        .mapNum = MAP_NUM(UNDEFINED),
        .mapGroup = MAP_GROUP(UNDEFINED),
        .registeredFlag = FLAG_PHONE_CARD_AMY_AND_LIV,
        .rematchTrainerId = REMATCH_AMY_AND_LIV,
        .availability = PHONE_AVAILABILITY_ALWAYS,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_ERNEST] = {
        .customDisplayName = NULL,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Always,
        .mapNum = MAP_NUM(UNDEFINED),
        .mapGroup = MAP_GROUP(UNDEFINED),
        .registeredFlag = FLAG_PHONE_CARD_ERNEST,
        .rematchTrainerId = REMATCH_ERNEST,
        .availability = PHONE_AVAILABILITY_ALWAYS,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_CORY] = {
        .customDisplayName = NULL,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Always,
        .mapNum = MAP_NUM(UNDEFINED),
        .mapGroup = MAP_GROUP(UNDEFINED),
        .registeredFlag = FLAG_PHONE_CARD_CORY,
        .rematchTrainerId = REMATCH_CORY,
        .availability = PHONE_AVAILABILITY_ALWAYS,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_EDWIN] = {
        .customDisplayName = NULL,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Always,
        .mapNum = MAP_NUM(UNDEFINED),
        .mapGroup = MAP_GROUP(UNDEFINED),
        .registeredFlag = FLAG_PHONE_CARD_EDWIN,
        .rematchTrainerId = REMATCH_EDWIN,
        .availability = PHONE_AVAILABILITY_ALWAYS,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_LYDIA] = {
        .customDisplayName = NULL,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Always,
        .mapNum = MAP_NUM(UNDEFINED),
        .mapGroup = MAP_GROUP(UNDEFINED),
        .registeredFlag = FLAG_PHONE_CARD_LYDIA,
        .rematchTrainerId = REMATCH_LYDIA,
        .availability = PHONE_AVAILABILITY_ALWAYS,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_ISAAC] = {
        .customDisplayName = NULL,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Always,
        .mapNum = MAP_NUM(UNDEFINED),
        .mapGroup = MAP_GROUP(UNDEFINED),
        .registeredFlag = FLAG_PHONE_CARD_ISAAC,
        .rematchTrainerId = REMATCH_ISAAC,
        .availability = PHONE_AVAILABILITY_ALWAYS,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_GABRIELLE] = {
        .customDisplayName = NULL,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Always,
        .mapNum = MAP_NUM(UNDEFINED),
        .mapGroup = MAP_GROUP(UNDEFINED),
        .registeredFlag = FLAG_PHONE_CARD_GABRIELLE,
        .rematchTrainerId = REMATCH_GABRIELLE,
        .availability = PHONE_AVAILABILITY_ALWAYS,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_CATHERINE] = {
        .customDisplayName = NULL,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Always,
        .mapNum = MAP_NUM(UNDEFINED),
        .mapGroup = MAP_GROUP(UNDEFINED),
        .registeredFlag = FLAG_PHONE_CARD_CATHERINE,
        .rematchTrainerId = REMATCH_CATHERINE,
        .availability = PHONE_AVAILABILITY_ALWAYS,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_JACKSON] = {
        .customDisplayName = NULL,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Always,
        .mapNum = MAP_NUM(UNDEFINED),
        .mapGroup = MAP_GROUP(UNDEFINED),
        .registeredFlag = FLAG_PHONE_CARD_JACKSON,
        .rematchTrainerId = REMATCH_JACKSON,
        .availability = PHONE_AVAILABILITY_ALWAYS,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_HALEY] = {
        .customDisplayName = NULL,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Always,
        .mapNum = MAP_NUM(UNDEFINED),
        .mapGroup = MAP_GROUP(UNDEFINED),
        .registeredFlag = FLAG_PHONE_CARD_HALEY,
        .rematchTrainerId = REMATCH_HALEY,
        .availability = PHONE_AVAILABILITY_ALWAYS,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_JAMES] = {
        .customDisplayName = NULL,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Always,
        .mapNum = MAP_NUM(UNDEFINED),
        .mapGroup = MAP_GROUP(UNDEFINED),
        .registeredFlag = FLAG_PHONE_CARD_JAMES,
        .rematchTrainerId = REMATCH_JAMES,
        .availability = PHONE_AVAILABILITY_ALWAYS,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_TRENT] = {
        .customDisplayName = NULL,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Always,
        .mapNum = MAP_NUM(UNDEFINED),
        .mapGroup = MAP_GROUP(UNDEFINED),
        .registeredFlag = FLAG_PHONE_CARD_TRENT,
        .rematchTrainerId = REMATCH_TRENT,
        .availability = PHONE_AVAILABILITY_ALWAYS,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_SAWYER] = {
        .customDisplayName = NULL,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Always,
        .mapNum = MAP_NUM(UNDEFINED),
        .mapGroup = MAP_GROUP(UNDEFINED),
        .registeredFlag = FLAG_PHONE_CARD_SAWYER,
        .rematchTrainerId = REMATCH_SAWYER,
        .availability = PHONE_AVAILABILITY_ALWAYS,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_KIRA_AND_DAN] = {
        .customDisplayName = NULL,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Always,
        .mapNum = MAP_NUM(UNDEFINED),
        .mapGroup = MAP_GROUP(UNDEFINED),
        .registeredFlag = FLAG_PHONE_CARD_KIRA_AND_DAN,
        .rematchTrainerId = REMATCH_KIRA_AND_DAN,
        .availability = PHONE_AVAILABILITY_ALWAYS,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_WALLY] = {
        .customDisplayName = NULL,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Never,
        .mapNum = MAP_NUM(UNDEFINED),
        .mapGroup = MAP_GROUP(UNDEFINED),
        .registeredFlag = FLAG_PHONE_CARD_WALLY,
        .rematchTrainerId = REMATCH_WALLY_3,
        .availability = PHONE_AVAILABILITY_ALWAYS,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_ROXANNE] = {
        .customDisplayName = NULL,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Never,
        .mapNum = MAP_NUM(UNDEFINED),
        .mapGroup = MAP_GROUP(UNDEFINED),
        .registeredFlag = FLAG_PHONE_CARD_ROXANNE,
        .rematchTrainerId = REMATCH_ROXANNE,
        .availability = PHONE_AVAILABILITY_ALWAYS,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_BRAWLY] = {
        .customDisplayName = NULL,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Never,
        .mapNum = MAP_NUM(UNDEFINED),
        .mapGroup = MAP_GROUP(UNDEFINED),
        .registeredFlag = FLAG_PHONE_CARD_BRAWLY,
        .rematchTrainerId = REMATCH_BRAWLY,
        .availability = PHONE_AVAILABILITY_ALWAYS,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_WATTSON] = {
        .customDisplayName = NULL,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Never,
        .mapNum = MAP_NUM(UNDEFINED),
        .mapGroup = MAP_GROUP(UNDEFINED),
        .registeredFlag = FLAG_PHONE_CARD_WATTSON,
        .rematchTrainerId = REMATCH_WATTSON,
        .availability = PHONE_AVAILABILITY_ALWAYS,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_FLANNERY] = {
        .customDisplayName = NULL,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Never,
        .mapNum = MAP_NUM(UNDEFINED),
        .mapGroup = MAP_GROUP(UNDEFINED),
        .registeredFlag = FLAG_PHONE_CARD_FLANNERY,
        .rematchTrainerId = REMATCH_FLANNERY,
        .availability = PHONE_AVAILABILITY_ALWAYS,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_NORMAN] = {
        .customDisplayName = NULL,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Never,
        .mapNum = MAP_NUM(UNDEFINED),
        .mapGroup = MAP_GROUP(UNDEFINED),
        .registeredFlag = FLAG_PHONE_CARD_NORMAN,
        .rematchTrainerId = REMATCH_NORMAN,
        .availability = PHONE_AVAILABILITY_ALWAYS,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_WINONA] = {
        .customDisplayName = NULL,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Never,
        .mapNum = MAP_NUM(UNDEFINED),
        .mapGroup = MAP_GROUP(UNDEFINED),
        .registeredFlag = FLAG_PHONE_CARD_WINONA,
        .rematchTrainerId = REMATCH_WINONA,
        .availability = PHONE_AVAILABILITY_ALWAYS,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_TATE_AND_LIZA] = {
        .customDisplayName = NULL,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Never,
        .mapNum = MAP_NUM(UNDEFINED),
        .mapGroup = MAP_GROUP(UNDEFINED),
        .registeredFlag = FLAG_PHONE_CARD_TATE_AND_LIZA,
        .rematchTrainerId = REMATCH_TATE_AND_LIZA,
        .availability = PHONE_AVAILABILITY_ALWAYS,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_JUAN] = {
        .customDisplayName = NULL,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Never,
        .mapNum = MAP_NUM(UNDEFINED),
        .mapGroup = MAP_GROUP(UNDEFINED),
        .registeredFlag = FLAG_PHONE_CARD_JUAN,
        .rematchTrainerId = REMATCH_JUAN,
        .availability = PHONE_AVAILABILITY_ALWAYS,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_SIDNEY] = {
        .customDisplayName = NULL,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Never,
        .mapNum = MAP_NUM(UNDEFINED),
        .mapGroup = MAP_GROUP(UNDEFINED),
        .registeredFlag = FLAG_PHONE_CARD_SIDNEY,
        .rematchTrainerId = REMATCH_SIDNEY,
        .availability = PHONE_AVAILABILITY_ALWAYS,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_PHOEBE] = {
        .customDisplayName = NULL,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Never,
        .mapNum = MAP_NUM(UNDEFINED),
        .mapGroup = MAP_GROUP(UNDEFINED),
        .registeredFlag = FLAG_PHONE_CARD_PHOEBE,
        .rematchTrainerId = REMATCH_PHOEBE,
        .availability = PHONE_AVAILABILITY_ALWAYS,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_GLACIA] = {
        .customDisplayName = NULL,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Never,
        .mapNum = MAP_NUM(UNDEFINED),
        .mapGroup = MAP_GROUP(UNDEFINED),
        .registeredFlag = FLAG_PHONE_CARD_GLACIA,
        .rematchTrainerId = REMATCH_GLACIA,
        .availability = PHONE_AVAILABILITY_ALWAYS,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_DRAKE] = {
        .customDisplayName = NULL,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Never,
        .mapNum = MAP_NUM(UNDEFINED),
        .mapGroup = MAP_GROUP(UNDEFINED),
        .registeredFlag = FLAG_PHONE_CARD_DRAKE,
        .rematchTrainerId = REMATCH_DRAKE,
        .availability = PHONE_AVAILABILITY_ALWAYS,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_WALLACE] = {
        .customDisplayName = NULL,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Never,
        .mapNum = MAP_NUM(UNDEFINED),
        .mapGroup = MAP_GROUP(UNDEFINED),
        .registeredFlag = FLAG_PHONE_CARD_WALLACE,
        .rematchTrainerId = REMATCH_WALLACE,
        .availability = PHONE_AVAILABILITY_ALWAYS,
        .isPermanent = FALSE,
    },
};

void SelectMessage_StandardMatchCallTrainer(const struct PhoneContact *phoneContact, bool8 isCallingPlayer)
{
    int rematchTrainerId = gRematchTable[phoneContact->rematchTrainerId].trainerIds[0];
    SelectMatchCallMessage(rematchTrainerId, gStringVar4, isCallingPlayer);
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
