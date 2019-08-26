#include "global.h"
#include "battle.h"
#include "battle_setup.h"
#include "data.h"
#include "day_night.h"
#include "event_data.h"
#include "international_string_util.h"
#include "match_call.h"
#include "phone_contact.h"
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

extern const u8 PhoneScript_Mom[];
extern const u8 PhoneScript_Elm[];
extern const u8 PhoneScript_StandardMatchCallTrainer[];

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
    [PHONE_CONTACT_ROSE] = {
        .customDisplayName = NULL,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Always,
        .mapNum = MAP_NUM(UNDEFINED),
        .mapGroup = MAP_GROUP(UNDEFINED),
        .registeredFlag = FLAG_PHONE_CARD_ROSE,
        .rematchTrainerId = REMATCH_ROSE,
        .availability = PHONE_AVAILABILITY_ALWAYS,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_ANDRES] = {
        .customDisplayName = NULL,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Always,
        .mapNum = MAP_NUM(UNDEFINED),
        .mapGroup = MAP_GROUP(UNDEFINED),
        .registeredFlag = FLAG_PHONE_CARD_ANDRES,
        .rematchTrainerId = REMATCH_ANDRES,
        .availability = PHONE_AVAILABILITY_ALWAYS,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_DUSTY] = {
        .customDisplayName = NULL,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Always,
        .mapNum = MAP_NUM(UNDEFINED),
        .mapGroup = MAP_GROUP(UNDEFINED),
        .registeredFlag = FLAG_PHONE_CARD_DUSTY,
        .rematchTrainerId = REMATCH_DUSTY,
        .availability = PHONE_AVAILABILITY_ALWAYS,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_LOLA] = {
        .customDisplayName = NULL,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Always,
        .mapNum = MAP_NUM(UNDEFINED),
        .mapGroup = MAP_GROUP(UNDEFINED),
        .registeredFlag = FLAG_PHONE_CARD_LOLA,
        .rematchTrainerId = REMATCH_LOLA,
        .availability = PHONE_AVAILABILITY_ALWAYS,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_RICKY] = {
        .customDisplayName = NULL,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Always,
        .mapNum = MAP_NUM(UNDEFINED),
        .mapGroup = MAP_GROUP(UNDEFINED),
        .registeredFlag = FLAG_PHONE_CARD_RICKY,
        .rematchTrainerId = REMATCH_RICKY,
        .availability = PHONE_AVAILABILITY_ALWAYS,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_LILA_AND_ROY] = {
        .customDisplayName = NULL,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Always,
        .mapNum = MAP_NUM(UNDEFINED),
        .mapGroup = MAP_GROUP(UNDEFINED),
        .registeredFlag = FLAG_PHONE_CARD_LILA_AND_ROY,
        .rematchTrainerId = REMATCH_LILA_AND_ROY,
        .availability = PHONE_AVAILABILITY_ALWAYS,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_CRISTIN] = {
        .customDisplayName = NULL,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Always,
        .mapNum = MAP_NUM(UNDEFINED),
        .mapGroup = MAP_GROUP(UNDEFINED),
        .registeredFlag = FLAG_PHONE_CARD_CRISTIN,
        .rematchTrainerId = REMATCH_CRISTIN,
        .availability = PHONE_AVAILABILITY_ALWAYS,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_BROOKE] = {
        .customDisplayName = NULL,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Always,
        .mapNum = MAP_NUM(UNDEFINED),
        .mapGroup = MAP_GROUP(UNDEFINED),
        .registeredFlag = FLAG_PHONE_CARD_BROOKE,
        .rematchTrainerId = REMATCH_BROOKE,
        .availability = PHONE_AVAILABILITY_ALWAYS,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_WILTON] = {
        .customDisplayName = NULL,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Always,
        .mapNum = MAP_NUM(UNDEFINED),
        .mapGroup = MAP_GROUP(UNDEFINED),
        .registeredFlag = FLAG_PHONE_CARD_WILTON,
        .rematchTrainerId = REMATCH_WILTON,
        .availability = PHONE_AVAILABILITY_ALWAYS,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_VALERIE] = {
        .customDisplayName = NULL,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Always,
        .mapNum = MAP_NUM(UNDEFINED),
        .mapGroup = MAP_GROUP(UNDEFINED),
        .registeredFlag = FLAG_PHONE_CARD_VALERIE,
        .rematchTrainerId = REMATCH_VALERIE,
        .availability = PHONE_AVAILABILITY_ALWAYS,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_CINDY] = {
        .customDisplayName = NULL,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Always,
        .mapNum = MAP_NUM(UNDEFINED),
        .mapGroup = MAP_GROUP(UNDEFINED),
        .registeredFlag = FLAG_PHONE_CARD_CINDY,
        .rematchTrainerId = REMATCH_CINDY,
        .availability = PHONE_AVAILABILITY_ALWAYS,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_THALIA] = {
        .customDisplayName = NULL,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Always,
        .mapNum = MAP_NUM(UNDEFINED),
        .mapGroup = MAP_GROUP(UNDEFINED),
        .registeredFlag = FLAG_PHONE_CARD_THALIA,
        .rematchTrainerId = REMATCH_THALIA,
        .availability = PHONE_AVAILABILITY_ALWAYS,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_JESSICA] = {
        .customDisplayName = NULL,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Always,
        .mapNum = MAP_NUM(UNDEFINED),
        .mapGroup = MAP_GROUP(UNDEFINED),
        .registeredFlag = FLAG_PHONE_CARD_JESSICA,
        .rematchTrainerId = REMATCH_JESSICA,
        .availability = PHONE_AVAILABILITY_ALWAYS,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_WINSTON] = {
        .customDisplayName = NULL,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Always,
        .mapNum = MAP_NUM(UNDEFINED),
        .mapGroup = MAP_GROUP(UNDEFINED),
        .registeredFlag = FLAG_PHONE_CARD_WINSTON,
        .rematchTrainerId = REMATCH_WINSTON,
        .availability = PHONE_AVAILABILITY_ALWAYS,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_STEVE] = {
        .customDisplayName = NULL,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Always,
        .mapNum = MAP_NUM(UNDEFINED),
        .mapGroup = MAP_GROUP(UNDEFINED),
        .registeredFlag = FLAG_PHONE_CARD_STEVE,
        .rematchTrainerId = REMATCH_STEVE,
        .availability = PHONE_AVAILABILITY_ALWAYS,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_TONY] = {
        .customDisplayName = NULL,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Always,
        .mapNum = MAP_NUM(UNDEFINED),
        .mapGroup = MAP_GROUP(UNDEFINED),
        .registeredFlag = FLAG_PHONE_CARD_TONY,
        .rematchTrainerId = REMATCH_TONY,
        .availability = PHONE_AVAILABILITY_ALWAYS,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_NOB] = {
        .customDisplayName = NULL,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Always,
        .mapNum = MAP_NUM(UNDEFINED),
        .mapGroup = MAP_GROUP(UNDEFINED),
        .registeredFlag = FLAG_PHONE_CARD_NOB,
        .rematchTrainerId = REMATCH_NOB,
        .availability = PHONE_AVAILABILITY_ALWAYS,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_KOJI] = {
        .customDisplayName = NULL,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Always,
        .mapNum = MAP_NUM(UNDEFINED),
        .mapGroup = MAP_GROUP(UNDEFINED),
        .registeredFlag = FLAG_PHONE_CARD_KOJI,
        .rematchTrainerId = REMATCH_KOJI,
        .availability = PHONE_AVAILABILITY_ALWAYS,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_FERNANDO] = {
        .customDisplayName = NULL,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Always,
        .mapNum = MAP_NUM(UNDEFINED),
        .mapGroup = MAP_GROUP(UNDEFINED),
        .registeredFlag = FLAG_PHONE_CARD_FERNANDO,
        .rematchTrainerId = REMATCH_FERNANDO,
        .availability = PHONE_AVAILABILITY_ALWAYS,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_DALTON] = {
        .customDisplayName = NULL,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Always,
        .mapNum = MAP_NUM(UNDEFINED),
        .mapGroup = MAP_GROUP(UNDEFINED),
        .registeredFlag = FLAG_PHONE_CARD_DALTON,
        .rematchTrainerId = REMATCH_DALTON,
        .availability = PHONE_AVAILABILITY_ALWAYS,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_BERNIE] = {
        .customDisplayName = NULL,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Always,
        .mapNum = MAP_NUM(UNDEFINED),
        .mapGroup = MAP_GROUP(UNDEFINED),
        .registeredFlag = FLAG_PHONE_CARD_BERNIE,
        .rematchTrainerId = REMATCH_BERNIE,
        .availability = PHONE_AVAILABILITY_ALWAYS,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_ETHAN] = {
        .customDisplayName = NULL,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Always,
        .mapNum = MAP_NUM(UNDEFINED),
        .mapGroup = MAP_GROUP(UNDEFINED),
        .registeredFlag = FLAG_PHONE_CARD_ETHAN,
        .rematchTrainerId = REMATCH_ETHAN,
        .availability = PHONE_AVAILABILITY_ALWAYS,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_JOHN_AND_JAY] = {
        .customDisplayName = NULL,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Always,
        .mapNum = MAP_NUM(UNDEFINED),
        .mapGroup = MAP_GROUP(UNDEFINED),
        .registeredFlag = FLAG_PHONE_CARD_JOHN_AND_JAY,
        .rematchTrainerId = REMATCH_JOHN_AND_JAY,
        .availability = PHONE_AVAILABILITY_ALWAYS,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_JEFFREY] = {
        .customDisplayName = NULL,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Always,
        .mapNum = MAP_NUM(UNDEFINED),
        .mapGroup = MAP_GROUP(UNDEFINED),
        .registeredFlag = FLAG_PHONE_CARD_JEFFREY,
        .rematchTrainerId = REMATCH_JEFFREY,
        .availability = PHONE_AVAILABILITY_ALWAYS,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_CAMERON] = {
        .customDisplayName = NULL,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Always,
        .mapNum = MAP_NUM(UNDEFINED),
        .mapGroup = MAP_GROUP(UNDEFINED),
        .registeredFlag = FLAG_PHONE_CARD_CAMERON,
        .rematchTrainerId = REMATCH_CAMERON,
        .availability = PHONE_AVAILABILITY_ALWAYS,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_JACKI] = {
        .customDisplayName = NULL,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Always,
        .mapNum = MAP_NUM(UNDEFINED),
        .mapGroup = MAP_GROUP(UNDEFINED),
        .registeredFlag = FLAG_PHONE_CARD_JACKI,
        .rematchTrainerId = REMATCH_JACKI,
        .availability = PHONE_AVAILABILITY_ALWAYS,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_WALTER] = {
        .customDisplayName = NULL,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Always,
        .mapNum = MAP_NUM(UNDEFINED),
        .mapGroup = MAP_GROUP(UNDEFINED),
        .registeredFlag = FLAG_PHONE_CARD_WALTER,
        .rematchTrainerId = REMATCH_WALTER,
        .availability = PHONE_AVAILABILITY_ALWAYS,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_KAREN] = {
        .customDisplayName = NULL,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Always,
        .mapNum = MAP_NUM(UNDEFINED),
        .mapGroup = MAP_GROUP(UNDEFINED),
        .registeredFlag = FLAG_PHONE_CARD_KAREN,
        .rematchTrainerId = REMATCH_KAREN,
        .availability = PHONE_AVAILABILITY_ALWAYS,
        .isPermanent = FALSE,
    },
    [PHONE_CONTACT_JERRY] = {
        .customDisplayName = NULL,
        .phoneScript = PhoneScript_StandardMatchCallTrainer,
        .canAcceptRematch = CanAcceptRematch_Always,
        .mapNum = MAP_NUM(UNDEFINED),
        .mapGroup = MAP_GROUP(UNDEFINED),
        .registeredFlag = FLAG_PHONE_CARD_JERRY,
        .rematchTrainerId = REMATCH_JERRY,
        .availability = PHONE_AVAILABILITY_ALWAYS,
        .isPermanent = FALSE,
    },
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
        dest[i++] = EXT_CTRL_CODE_SIZE;
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
        dest[i++] = EXT_CTRL_CODE_SIZE;
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
