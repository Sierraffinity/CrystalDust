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

static const u8 sPhoneContactName_Mom[] = _("MOM");
static const u8 sPhoneContactName_ProfessorElm[] = _("PROF. ELM");
static const u8 sPhoneContactName_BikeShop[] = _("BIKE SHOP");
static const u8 sPhoneContactName_Bill[] = _("BILL");
static const u8 sPhoneContactName_Buena[] = _("BUENA");
static const u8 sPhoneContactName_Youngster_Joey[] = _("YOUNGSTER JOEY");
static const u8 sPhoneContactName_Bug_Catcher_Wade[] = _("BUG CATCHER WADE");
static const u8 sPhoneContactName_Picnicker_Liz[] = _("PICNICKER LIZ");
static const u8 sPhoneContactName_Fisher_Ralph[] = _("FISHERMAN RALPH");
static const u8 sPhoneContactName_Hiker_Anthony[] = _("HIKER ANTHONY");
static const u8 sPhoneContactName_Camper_Todd[] = _("CAMPER TODD");
static const u8 sPhoneContactName_Picnicker_Gina[] = _("PICNICKER GINA");
static const u8 sPhoneContactName_Bug_Catcher_Arnie[] = _("BUG CATCHER ARNIE");
static const u8 sPhoneContactName_Juggler_Irwin[] = _("JUGGLER IRWIN");
static const u8 sPhoneContactName_Schoolboy_Jack[] = _("SCHOOLBOY JACK");
static const u8 sPhoneContactName_Pokefan_Beverly[] = _("POKEFAN BEVERLY");
static const u8 sPhoneContactName_Schoolboy_Alan[] = _("SCHOOLBOY ALAN");
static const u8 sPhoneContactName_Lass_Dana[] = _("LASS DANA");
static const u8 sPhoneContactName_Schoolboy_Chad[] = _("SCHOOLBOY CHAD");
static const u8 sPhoneContactName_Pokefan_Derek[] = _("POKEFAN DEREK");
static const u8 sPhoneContactName_Sailor_Huey[] = _("SAILOR HUEY");
static const u8 sPhoneContactName_Fisher_Tully[] = _("FISHERMAN TULLY");
static const u8 sPhoneContactName_Picnicker_Tiffany[] = _("PICNICKER TIFFANY");
static const u8 sPhoneContactName_Pokemaniac_Brent[] = _("POKEMANIAC BRENT");
static const u8 sPhoneContactName_Fisher_Wilton[] = _("FISHERMAN WILTON");
static const u8 sPhoneContactName_Bird_Keeper_Vance[] = _("BIRD KEEPER VANCE");
static const u8 sPhoneContactName_Hiker_Parry[] = _("HIKER PARRY");
static const u8 sPhoneContactName_Blackbelt_Kenji[] = _("BLACKBELT KENJI");
static const u8 sPhoneContactName_Picnicker_Erin[] = _("PICNICKER ERIN");
static const u8 sPhoneContactName_Bird_Keeper_Jose[] = _("BIRD KEEPER JOSE");
static const u8 sPhoneContactName_Cooltrainer_Reena[] = _("COOLTRAINER REENA");
static const u8 sPhoneContactName_Cooltrainer_Gaven[] = _("COOLTRAINER GAVEN");
static const u8 sPhoneContactName_Cooltrainer_Beth[] = _("COOLTRAINER BETH");

const struct PhoneContact gPhoneContacts[PHONE_CONTACT_COUNT] =
{
    [PHONE_CONTACT_MOM] = {
        .customDisplayName = sPhoneContactName_Mom,
        .phoneScript = PhoneScript_Mom,
        .mapNum = MAP_NUM(NEW_BARK_TOWN_PLAYERS_HOUSE_1F),
        .mapGroup = MAP_GROUP(NEW_BARK_TOWN_PLAYERS_HOUSE_1F),
        .registeredFlag = FLAG_PHONE_CARD_MOM,
        .rematchTrainerId = 0xFF,
		.trainerId = TRAINER_NONE,
        .isPermanent = TRUE,
    },
    [PHONE_CONTACT_ELM] = {
        .customDisplayName = sPhoneContactName_ProfessorElm,
        .phoneScript = PhoneScript_Elm,
        .mapNum = MAP_NUM(NEW_BARK_TOWN_PROFESSOR_ELMS_LAB),
        .mapGroup = MAP_GROUP(NEW_BARK_TOWN_PROFESSOR_ELMS_LAB),
        .registeredFlag = FLAG_PHONE_CARD_ELM,
        .rematchTrainerId = 0xFF,
		.trainerId = TRAINER_NONE,
        .isPermanent = TRUE,
    },
    [PHONE_CONTACT_BIKE_SHOP] = {
        .customDisplayName = sPhoneContactName_BikeShop,
        .phoneScript = PhoneScript_BikeShop,
        .mapNum = MAP_NUM(GOLDENROD_CITY_BIKE_SHOP),
        .mapGroup = MAP_GROUP(GOLDENROD_CITY_BIKE_SHOP),
        .registeredFlag = 0,
        .rematchTrainerId = 0xFF,
		.trainerId = TRAINER_NONE,
        .isPermanent = TRUE,
    },
    [PHONE_CONTACT_BILL] = {
        .customDisplayName = sPhoneContactName_Bill,
        .phoneScript = PhoneScript_Bill,
        .mapNum = MAP_NUM(UNDEFINED),
        .mapGroup = MAP_GROUP(UNDEFINED),
        .registeredFlag = FLAG_PHONE_CARD_BILL,
        .rematchTrainerId = 0xFF,
		.trainerId = TRAINER_NONE,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_BUENA] = {
        .customDisplayName = sPhoneContactName_Buena,
        .phoneScript = PhoneScript_Buena,
        .mapNum = MAP_NUM(RADIO_TOWER_2F),
        .mapGroup = MAP_GROUP(RADIO_TOWER_2F),
        .registeredFlag = FLAG_PHONE_CARD_BUENA,
        .rematchTrainerId = 0xFF,
		.trainerId = TRAINER_NONE,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_YOUNGSTER_JOEY] = {
        .customDisplayName = sPhoneContactName_Youngster_Joey,
        .phoneScript = PhoneScript_Youngster_Joey,
        .mapNum = MAP_NUM(ROUTE30),
        .mapGroup = MAP_GROUP(ROUTE30),
        .registeredFlag = FLAG_PHONE_CARD_YOUNGSTER_JOEY,
        .rematchTrainerId = REMATCH_JOEY,
		.trainerId = TRAINER_JOEY_1,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_BUG_CATCHER_WADE] = {
		.customDisplayName = sPhoneContactName_Bug_Catcher_Wade,
		.phoneScript = PhoneScript_StandardMatchCallTrainer,
		.mapNum = MAP_NUM(ROUTE31),
		.mapGroup = MAP_GROUP(ROUTE31),
		.registeredFlag = FLAG_PHONE_CARD_BUG_CATCHER_WADE,
		.rematchTrainerId = REMATCH_WADE,
		.trainerId = TRAINER_WADE_1,
		.isPermanent = FALSE,
	    },
    [PHONE_CONTACT_PICNICKER_LIZ] = {
        .customDisplayName = sPhoneContactName_Picnicker_Liz,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .mapNum = MAP_NUM(ROUTE32),
        .mapGroup = MAP_GROUP(ROUTE32),
        .registeredFlag = FLAG_PHONE_CARD_PICNICKER_LIZ,
        .rematchTrainerId = REMATCH_LIZ,
		.trainerId = TRAINER_LIZ_1,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_FISHER_RALPH] = {
        .customDisplayName = sPhoneContactName_Fisher_Ralph,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .mapNum = MAP_NUM(ROUTE32),
        .mapGroup = MAP_GROUP(ROUTE32),
        .registeredFlag = FLAG_PHONE_CARD_FISHER_RALPH,
        .rematchTrainerId = REMATCH_RALPH,
		.trainerId = TRAINER_RALPH_1,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_HIKER_ANTHONY] = {
        .customDisplayName = sPhoneContactName_Hiker_Anthony,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .mapNum = MAP_NUM(ROUTE33),
        .mapGroup = MAP_GROUP(ROUTE33),
        .registeredFlag = FLAG_PHONE_CARD_HIKER_ANTHONY,
        .rematchTrainerId = REMATCH_ANTHONY,
		.trainerId = TRAINER_ANTHONY_1,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_CAMPER_TODD] = {
        .customDisplayName = sPhoneContactName_Camper_Todd,
        .phoneScript = PhoneScript_Todd,
        .mapNum = MAP_NUM(ROUTE34),
        .mapGroup = MAP_GROUP(ROUTE34),
        .registeredFlag = FLAG_PHONE_CARD_CAMPER_TODD,
        .rematchTrainerId = REMATCH_TODD,
		.trainerId = TRAINER_TODD_1,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_PICNICKER_GINA] = {
        .customDisplayName = sPhoneContactName_Picnicker_Gina,
        .phoneScript = PhoneScript_Gina,
        .mapNum = MAP_NUM(ROUTE34),
        .mapGroup = MAP_GROUP(ROUTE34),
        .registeredFlag = FLAG_PHONE_CARD_PICNICKER_GINA,
        .rematchTrainerId = REMATCH_GINA,
		.trainerId = TRAINER_GINA_1,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_BUG_CATCHER_ARNIE] = {
        .customDisplayName = sPhoneContactName_Bug_Catcher_Arnie,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .mapNum = MAP_NUM(ROUTE35),
        .mapGroup = MAP_GROUP(ROUTE35),
        .registeredFlag = FLAG_PHONE_CARD_BUG_CATCHER_ARNIE,
        .rematchTrainerId = REMATCH_ARNIE,
		.trainerId = TRAINER_ARNIE_1,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_JUGGLER_IRWIN] = {
        .customDisplayName = sPhoneContactName_Juggler_Irwin,
        .phoneScript = PhoneScript_Irwin,
        .mapNum = MAP_NUM(ROUTE35),
        .mapGroup = MAP_GROUP(ROUTE35),
        .registeredFlag = FLAG_PHONE_CARD_JUGGLER_IRWIN,
        .rematchTrainerId = 0xFF,
		.trainerId = TRAINER_IRWIN,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_SCHOOLBOY_JACK] = {
        .customDisplayName = sPhoneContactName_Schoolboy_Jack,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .mapNum = MAP_NUM(NATIONAL_PARK),
        .mapGroup = MAP_GROUP(NATIONAL_PARK),
        .registeredFlag = FLAG_PHONE_CARD_SCHOOLBOY_JACK,
        .rematchTrainerId = REMATCH_JACK,
		.trainerId = TRAINER_JACK_1,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_POKEFAN_BEVERLY] = {
        .customDisplayName = sPhoneContactName_Pokefan_Beverly,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .mapNum = MAP_NUM(NATIONAL_PARK),
        .mapGroup = MAP_GROUP(NATIONAL_PARK),
        .registeredFlag = FLAG_PHONE_CARD_POKEFAN_BEVERLY,
        .rematchTrainerId = 0xFF,
		.trainerId = TRAINER_BEVERLY,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_SCHOOLBOY_ALAN] = {
        .customDisplayName = sPhoneContactName_Schoolboy_Alan,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .mapNum = MAP_NUM(ROUTE36),
        .mapGroup = MAP_GROUP(ROUTE36),
        .registeredFlag = FLAG_PHONE_CARD_SCHOOLBOY_ALAN,
        .rematchTrainerId = REMATCH_ALAN,
		.trainerId = TRAINER_ALAN_1,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_LASS_DANA] = {
        .customDisplayName = sPhoneContactName_Lass_Dana,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .mapNum = MAP_NUM(ROUTE38),
        .mapGroup = MAP_GROUP(ROUTE38),
        .registeredFlag = FLAG_PHONE_CARD_LASS_DANA,
        .rematchTrainerId = REMATCH_DANA,
		.trainerId = TRAINER_DANA_1,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_SCHOOLBOY_CHAD] = {
        .customDisplayName = sPhoneContactName_Schoolboy_Chad,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .mapNum = MAP_NUM(ROUTE38),
        .mapGroup = MAP_GROUP(ROUTE38),
        .registeredFlag = FLAG_PHONE_CARD_SCHOOLBOY_CHAD,
        .rematchTrainerId = REMATCH_CHAD,
		.trainerId = TRAINER_CHAD_1,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_POKEFAN_DEREK] = {
        .customDisplayName = sPhoneContactName_Pokefan_Derek,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .mapNum = MAP_NUM(ROUTE38),
        .mapGroup = MAP_GROUP(ROUTE38),
        .registeredFlag = FLAG_PHONE_CARD_POKEFAN_DEREK,
        .rematchTrainerId = 0xFF,
		.trainerId = TRAINER_DEREK,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_SAILOR_HUEY] = {
        .customDisplayName = sPhoneContactName_Sailor_Huey,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .mapNum = MAP_NUM(LIGHTHOUSE_2F),
        .mapGroup = MAP_GROUP(LIGHTHOUSE_2F),
        .registeredFlag = FLAG_PHONE_CARD_SAILOR_HUEY,
        .rematchTrainerId = REMATCH_HUEY,
		.trainerId = TRAINER_HUEY_1,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_FISHER_TULLY] = {
        .customDisplayName = sPhoneContactName_Fisher_Tully,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .mapNum = MAP_NUM(ROUTE42),
        .mapGroup = MAP_GROUP(ROUTE42),
        .registeredFlag = FLAG_PHONE_CARD_FISHER_TULLY,
        .rematchTrainerId = REMATCH_TULLY,
		.trainerId = TRAINER_TULLY_1,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_PICNICKER_TIFFANY] = {
        .customDisplayName = sPhoneContactName_Picnicker_Tiffany,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .mapNum = MAP_NUM(ROUTE43),
        .mapGroup = MAP_GROUP(ROUTE43),
        .registeredFlag = FLAG_PHONE_CARD_PICNICKER_TIFFANY,
        .rematchTrainerId = REMATCH_TIFFANY,
		.trainerId = TRAINER_TIFFANY_1,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_POKEMANIAC_BRENT] = {
        .customDisplayName = sPhoneContactName_Pokemaniac_Brent,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .mapNum = MAP_NUM(ROUTE43),
        .mapGroup = MAP_GROUP(ROUTE43),
        .registeredFlag = FLAG_PHONE_CARD_POKEMANIAC_BRENT,
        .rematchTrainerId = REMATCH_BRENT,
		.trainerId = TRAINER_BRENT_1,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_FISHER_WILTON] = {
        .customDisplayName = sPhoneContactName_Fisher_Wilton,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .mapNum = MAP_NUM(ROUTE44),
        .mapGroup = MAP_GROUP(ROUTE44),
        .registeredFlag = FLAG_PHONE_CARD_FISHER_WILTON,
        .rematchTrainerId = REMATCH_WILTON,
		.trainerId = TRAINER_WILTON_1,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_BIRD_KEEPER_VANCE] = {
        .customDisplayName = sPhoneContactName_Bird_Keeper_Vance,
        .phoneScript = PhoneScript_BirdKeeper_Vance,
        .mapNum = MAP_NUM(ROUTE44),
        .mapGroup = MAP_GROUP(ROUTE44),
        .registeredFlag = FLAG_PHONE_CARD_BIRD_KEEPER_VANCE,
        .rematchTrainerId = REMATCH_VANCE,
		.trainerId = TRAINER_VANCE_1,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_HIKER_PARRY] = {
        .customDisplayName = sPhoneContactName_Hiker_Parry,
        .phoneScript = PhoneScript_Hiker_Parry,
        .mapNum = MAP_NUM(ROUTE45),
        .mapGroup = MAP_GROUP(ROUTE45),
        .registeredFlag = FLAG_PHONE_CARD_HIKER_PARRY,
        .rematchTrainerId = REMATCH_PARRY,
		.trainerId = TRAINER_PARRY_1,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_BLACKBELT_KENJI] = {
        .customDisplayName = sPhoneContactName_Blackbelt_Kenji,
        .phoneScript = PhoneScript_Kenji,
        .mapNum = MAP_NUM(ROUTE45),
        .mapGroup = MAP_GROUP(ROUTE45),
        .registeredFlag = FLAG_PHONE_CARD_BLACKBELT_KENJI,
        .rematchTrainerId = 0xFF,
		.trainerId = TRAINER_KENJI,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_PICNICKER_ERIN] = {
        .customDisplayName = sPhoneContactName_Picnicker_Erin,
        .phoneScript = PhoneScript_Picnicker_Erin,
        .mapNum = MAP_NUM(ROUTE46),
        .mapGroup = MAP_GROUP(ROUTE46),
        .registeredFlag = FLAG_PHONE_CARD_PICNICKER_ERIN,
        .rematchTrainerId = REMATCH_ERIN,
		.trainerId = TRAINER_ERIN_1,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_BIRD_KEEPER_JOSE] = {
        .customDisplayName = sPhoneContactName_Bird_Keeper_Jose,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .mapNum = MAP_NUM(ROUTE27),
        .mapGroup = MAP_GROUP(ROUTE27),
        .registeredFlag = FLAG_PHONE_CARD_BIRD_KEEPER_JOSE,
        .rematchTrainerId = REMATCH_JOSE,
		.trainerId = TRAINER_JOSE_1,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_COOLTRAINER_REENA] = {
        .customDisplayName = sPhoneContactName_Cooltrainer_Reena,
        .phoneScript = PhoneScript_Cooltrainer_Reena,
        .mapNum = MAP_NUM(ROUTE26),
        .mapGroup = MAP_GROUP(ROUTE26),
        .registeredFlag = FLAG_PHONE_CARD_COOLTRAINER_REENA,
        .rematchTrainerId = REMATCH_REENA,
		.trainerId = TRAINER_REENA_1,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_COOLTRAINER_GAVEN] = {
        .customDisplayName = sPhoneContactName_Cooltrainer_Gaven,
        .phoneScript = PhoneScript_Cooltrainer_Gaven,
        .mapNum = MAP_NUM(ROUTE26),
        .mapGroup = MAP_GROUP(ROUTE26),
        .registeredFlag = FLAG_PHONE_CARD_COOLTRAINER_GAVEN,
        .rematchTrainerId = REMATCH_GAVEN,
		.trainerId = TRAINER_GAVEN_1,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_COOLTRAINER_BETH] = {
        .customDisplayName = sPhoneContactName_Cooltrainer_Beth,
        .phoneScript = PhoneScript_Cooltrainer_Beth,
        .mapNum = MAP_NUM(ROUTE26),
        .mapGroup = MAP_GROUP(ROUTE26),
        .registeredFlag = FLAG_PHONE_CARD_COOLTRAINER_BETH,
        .rematchTrainerId = REMATCH_BETH,
		.trainerId = TRAINER_BETH_1,
        .isPermanent = FALSE,
    },
};

void IsAvailabileForRematch(const struct PhoneContact *phoneContact, bool8 isCallingPlayer)
{
    gSpecialVar_Result = IsMatchCallRematchTime(phoneContact->trainerId);
}

void SelectMessage_StandardMatchCallTrainer_Opening(const struct PhoneContact *phoneContact, bool8 isCallingPlayer)
{
	SelectMatchCallMessage_Opening(phoneContact->trainerId, gStringVar4, isCallingPlayer, phoneContact);
}

void SelectMessage_StandardMatchCallTrainer_Hangup(const struct PhoneContact *phoneContact, bool8 isCallingPlayer)
{
	SelectMatchCallMessage_Hangup(phoneContact->trainerId, gStringVar4, isCallingPlayer, phoneContact);
}

void SelectMessage_StandardMatchCallTrainer_HangupOutgoing(const struct PhoneContact *phoneContact, bool8 isCallingPlayer)
{
	SelectMatchCallMessage_HangupOutgoing(phoneContact->trainerId, gStringVar4, isCallingPlayer, phoneContact);
}

void SelectMessage_StandardMatchCallTrainer_Rematch(const struct PhoneContact *phoneContact, bool8 isCallingPlayer)
{
	SelectMatchCallMessage_Rematch(phoneContact->trainerId, gStringVar4, isCallingPlayer, phoneContact);
}

void SelectMessage_StandardMatchCallTrainer_RemindRematch(const struct PhoneContact *phoneContact, bool8 isCallingPlayer)
{
	SelectMatchCallMessage_RemindRematch(phoneContact->trainerId, gStringVar4, isCallingPlayer, phoneContact);
}

void SelectMessage_StandardMatchCallTrainer_Bragging(const struct PhoneContact *phoneContact, bool8 isCallingPlayer)
{
	SelectMatchCallMessage_Bragging(phoneContact->trainerId, gStringVar4, isCallingPlayer, phoneContact);
}

void SelectMessage_StandardMatchCallTrainer_FoundAMon(const struct PhoneContact *phoneContact, bool8 isCallingPlayer)
{
	SelectMatchCallMessage_FoundAMon(phoneContact->trainerId, gStringVar4, isCallingPlayer, phoneContact);
}

void SelectMessage_StandardMatchCallTrainer(const struct PhoneContact *phoneContact, bool8 isCallingPlayer)
{
    SelectMatchCallMessage(phoneContact->trainerId, gStringVar4, isCallingPlayer, phoneContact);
}

bool8 DummiedOut_IsPhoneContactAvailable(const struct PhoneContact *phoneContact, s8 dayOfWeek, s8 hour)
{
	return TRUE;
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

u32 GetPhoneContactFromTrainerId(int trainerId)
{
	int i;

	for(i=0;i<PHONE_CONTACT_COUNT;i++){
		if(gPhoneContacts[i].trainerId == trainerId){
			return i;
		}
	}
	return 0;
}

u32 GetPhoneContactFromRematchTrainerId(int trainerId)
{
	int i;

	for(i=0;i<PHONE_CONTACT_COUNT;i++){
		if(gPhoneContacts[i].rematchTrainerId == trainerId){
			return i;
		}
	}
	return 0;
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
