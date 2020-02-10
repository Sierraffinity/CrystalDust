#include "constants/global.h"
#include "constants/battle_frontier.h"
#include "constants/battle_setup.h"
#include "constants/day_night.h"
#include "constants/easy_chat.h"
#include "constants/event_objects.h"
#include "constants/event_object_movement_constants.h"
#include "constants/field_effects.h"
#include "constants/flags.h"
#include "constants/fruit_trees.h"
#include "constants/decorations.h"
#include "constants/items.h"
#include "constants/heal_locations.h"
#include "constants/layouts.h"
#include "constants/map_scripts.h"
#include "constants/map_types.h"
#include "constants/maps.h"
#include "constants/moves.h"
#include "constants/radio.h"
#include "constants/region_map_sections.h"
#include "constants/songs.h"
#include "constants/species.h"
#include "constants/trainers.h"
#include "constants/text.h"
#include "constants/vars.h"
#include "constants/weather.h"
#include "constants/trainer_hill.h"
#include "constants/battle.h"
#include "constants/metatile_labels.h"
	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section script_data, "aw", %progbits

	.include "data/phone_script_cmd_table.inc"

PhoneScript_Mom::
	phone_goto_if_set FLAG_TALKED_TO_MOM_AFTER_MYSTERY_EGG_QUEST, PhoneScript_Mom_RegularCall
	phone_goto_if_set FLAG_DUDE_TALKED_TO_YOU, PhoneScript_Mom_BeginPhoneBanking
	phone_goto_if_set FLAG_GAVE_MYSTERY_EGG_TO_ELM, PhoneScript_Mom_GaveEggToElm
	phone_goto_if_set FLAG_SYS_POKEMON_GET, PhoneScript_Mom_GotMon
	phone_stdcall Text_Pokegear_Mom_Start
	phone_end

PhoneScript_Mom_RegularCall:
	phone_initcall
	phone_end_if_not_available
	phone_message Text_Pokegear_Mom_RegularCall_WorkingHard
	phone_getmapinfo
	phone_buffermapsecname 0, VAR_0x8005
	phone_compare VAR_0x8004, MAP_TYPE_TOWN
	phone_goto_if_eq PhoneScript_Mom_CityOrTown
	phone_compare VAR_0x8004, MAP_TYPE_CITY
	phone_goto_if_eq PhoneScript_Mom_CityOrTown
	phone_compare VAR_0x8004, MAP_TYPE_ROUTE
	phone_goto_if_eq PhoneScript_Mom_Route
	phone_compare VAR_0x8004, MAP_TYPE_OCEAN_ROUTE
	phone_goto_if_eq PhoneScript_Mom_Route
	phone_message Text_Pokegear_Mom_RegularCall_Determined
PhoneScript_Mom_PostLocationBanking:
	@ TODO: banking
PhoneScript_Mom_PostBanking:
	phone_message Text_Pokegear_Mom_RootingForYou
	phone_waitbuttonpress
	phone_hangup
	phone_end

PhoneScript_Mom_CityOrTown:
	phone_compare VAR_0x8005, MAPSEC_NEW_BARK_TOWN
	phone_goto_if_eq PhoneScript_Mom_NewBark
	phone_compare VAR_0x8005, MAPSEC_CHERRYGROVE_CITY
	phone_goto_if_eq PhoneScript_Mom_Cherrygrove
	phone_compare VAR_0x8005, MAPSEC_VIOLET_CITY
	phone_goto_if_eq PhoneScript_Mom_Violet
	phone_compare VAR_0x8005, MAPSEC_AZALEA_TOWN
	phone_goto_if_eq PhoneScript_Mom_Azalea
	phone_compare VAR_0x8005, MAPSEC_GOLDENROD_CITY
	phone_goto_if_eq PhoneScript_Mom_Goldenrod
	phone_message Text_Pokegear_Mom_RegularCall_NeverGoneThere
	phone_goto PhoneScript_Mom_PostLocationBanking

PhoneScript_Mom_NewBark:
	phone_message Text_Pokegear_Mom_RegularCall_NewBark
	phone_goto PhoneScript_Mom_PostLocationBanking

PhoneScript_Mom_Cherrygrove:
	phone_message Text_Pokegear_Mom_RegularCall_Cherrygrove
	phone_goto PhoneScript_Mom_PostLocationBanking

PhoneScript_Mom_Violet:
	phone_buffermapsecname 1, MAPSEC_SPROUT_TOWER
	phone_message Text_Pokegear_Mom_RegularCall_Landmark
	phone_goto PhoneScript_Mom_PostLocationBanking

PhoneScript_Mom_Azalea:
	phone_buffermapsecname 1, MAPSEC_RUSTURF_TUNNEL
	phone_message Text_Pokegear_Mom_RegularCall_Landmark
	phone_goto PhoneScript_Mom_PostLocationBanking

PhoneScript_Mom_Goldenrod:
	phone_buffermapsecname 1, MAPSEC_NEW_MAUVILLE
	phone_message Text_Pokegear_Mom_RegularCall_Landmark
	phone_goto PhoneScript_Mom_PostLocationBanking

PhoneScript_Mom_Route:
	phone_message Text_Pokegear_Mom_RegularCall_Route
	phone_goto PhoneScript_Mom_PostLocationBanking

PhoneScript_Mom_BeginPhoneBanking:
	phone_initcall
	phone_end_if_not_available
	phone_setflag FLAG_TALKED_TO_MOM_AFTER_MYSTERY_EGG_QUEST
	phone_message Text_Pokegear_Mom_PhoneBanking_Question
	phone_yesnobox
	phone_compare VAR_RESULT, 0
	phone_goto_if_eq PhoneScript_Mom_NoPhoneBanking
	phone_setflag FLAG_SYS_MOM_BANKING_ENABLED
	phone_message Text_Pokegear_Mom_PhoneBanking_Yes
	phone_goto PhoneScript_Mom_PostBanking

PhoneScript_Mom_NoPhoneBanking:
	phone_clearflag FLAG_SYS_MOM_BANKING_ENABLED
	phone_message Text_Pokegear_Mom_PhoneBanking_No
	phone_goto PhoneScript_Mom_PostBanking

PhoneScript_Mom_GaveEggToElm:
	phone_stdcall Text_Pokegear_Mom_GaveEggToElm
	phone_end

PhoneScript_Mom_GotMon:
	phone_stdcall Text_Pokegear_Mom_GotMon
	phone_end

Text_Pokegear_Mom_Start:
	.string "Hello?\n"
	.string "Oh, hi, {PLAYER}!\p"
	.string "Wasn't PROF. ELM waiting for you?$"

Text_Pokegear_Mom_GotMon:
	.string "Hello?\n"
	.string "Oh, hi, {PLAYER}!\p"
	.string "You're on a big mission for\n"
	.string "PROF. ELM? Be good!$"

Text_Pokegear_Mom_GaveEggToElm:
	.string "Hello?\n"
	.string "Oh, hi, {PLAYER}!\p"
	.string "If you're done with your errand,\n"
	.string "come on home, dear.$"

Text_Pokegear_Mom_PhoneBanking_Question:
	.string "Hello?\n"
	.string "…… {PLAYER}?\p"
	.string "I heard from PROF. ELM that you\n"
	.string "went on a long trip.\p"
	.string "I wish you would have told me…\p"
	.string "What about money?\n"
	.string "Do you want me to save it?$"

Text_Pokegear_Mom_PhoneBanking_Yes:
	.string "Okay. I'll save your money.\p$"

Text_Pokegear_Mom_PhoneBanking_No:
	.string "Okay. I won't save your money.\p$"

Text_Pokegear_Mom_RegularCall_WorkingHard:
	.string "Hello?\n"
	.string "Oh, hi, {PLAYER}! Working hard?\p$"

Text_Pokegear_Mom_RegularCall_NeverGoneThere:
	.string "Really, you're in {STR_VAR_1}?\p"
	.string "I've never gone there.\n"
	.string "That's kind of neat, {PLAYER}.\p$"

Text_Pokegear_Mom_RegularCall_NewBark:
	.string "What? You're in {STR_VAR_1}?\n"
	.string "Come see your MOM sometime!\p$"

Text_Pokegear_Mom_RegularCall_Cherrygrove:
	.string "You're visiting {STR_VAR_1}?\n"
	.string "How about coming home for a bit?\p$"

Text_Pokegear_Mom_RegularCall_Landmark:
	.string "Oh, so you're in {STR_VAR_1}?\p"
	.string "Isn't that where {STR_VAR_2}\n"
	.string "is? Did you go take a look?\p$"

Text_Pokegear_Mom_RegularCall_Route:
	.string "Wow, you're in {STR_VAR_1}?\n"
	.string "Good luck on your POKéMON quest!\p$"

Text_Pokegear_Mom_RegularCall_Determined:
	.string "That sounds really tough.\p"
	.string "But, {PLAYER}, I know you're really\n"
	.string "determined. You'll be okay, right?\p$"

Text_Pokegear_Mom_RootingForYou:
	.string "{PLAYER}, keep it up!\n"
	.string "I'm rooting for you, baby!$"

PhoneScript_Elm::
	phone_goto_if_set FLAG_GOT_ELMS_EGG, PhoneScript_Elm_EggUnhatched
	phone_goto_if_set FLAG_ELM_CALLED_ABOUT_ASSISTANT_IN_VIOLET, PhoneScript_Elm_SeeAssistant
	phone_goto_if_set FLAG_GAVE_MYSTERY_EGG_TO_ELM, PhoneScript_Elm_CheckingEgg
	phone_goto_if_set FLAG_ELM_CALLED_ABOUT_STOLEN_MON, PhoneScript_Elm_MonWasStolen
	phone_goto_if_set FLAG_RECEIVED_MYSTERY_EGG, PhoneScript_Elm_SawMrPokemon
	phone_stdcall Text_Pokegear_Elm_Start
	phone_end

PhoneScript_Elm_EggUnhatched::
	phone_stdcall Text_Pokegear_Elm_EggUnhatched
	phone_end

PhoneScript_Elm_SeeAssistant::
	phone_stdcall Text_Pokegear_Elm_SeeAssistant
	phone_end

PhoneScript_Elm_CheckingEgg::
	phone_stdcall Text_Pokegear_Elm_CheckingEgg
	phone_end

PhoneScript_Elm_MonWasStolen::
	phone_stdcall Text_Pokegear_Elm_MonWasStolen
	phone_end

PhoneScript_Elm_SawMrPokemon::
	phone_stdcall Text_Pokegear_Elm_SawMrPokemon
	phone_end

Text_Pokegear_Elm_Start::
	.string "Hello, {PLAYER}?\n"
	.string "Try not to overdo it.\p"
	.string "Be sure to heal your POKéMON if\n"
	.string "they are hurt.$"

Text_Pokegear_Elm_SawMrPokemon::
	.string "Hello, {PLAYER}?\n"
	.string "Did you meet MR. POKéMON?\p"
	.string "Great!\n"
	.string "Come back safely!$"

Text_Pokegear_Elm_MonWasStolen::
	.string "{PLAYER}?\n"
	.string "I'm very upset right now.\p"
	.string "We had a POKéMON stolen from\n"
	.string "here. How could anyone do that?$"

Text_Pokegear_Elm_CheckingEgg::
	.string "Hello, {PLAYER}?\n"
	.string "We're checking the EGG now.\p"
	.string "It does appear to be a POKéMON\n"
	.string "EGG.$"

Text_Pokegear_Elm_SeeAssistant::
	.string "Hello, {PLAYER}?\n"
	.string "Did you see my assistant?\p"
	.string "He's at the POKéMON CENTER in\n"
	.string "VIOLET CITY.$"

Text_Pokegear_Elm_EggUnhatched::
	.string "Hello, {PLAYER}?\n"
	.string "How's the EGG?\l"
	.string "Has anything changed?\p"
	.string "If anything happens, please call.$"

Route30_PhoneScript_ElmCall::
	phone_stdcall Route30_Text_ElmCall
	phone_end

Route30_Text_ElmCall:
	.string "H-hello? {PLAYER}?\n"
	.string "It's a disaster!\p"
	.string "Uh, um, it's just terrible!\p"
	.string "What should I do?\n"
	.string "It… Oh, no…\p"
	.string "Please get back here now!$"

VioletCity_PhoneScript_ElmCall::
	phone_stdcall VioletCity_Text_ElmCall
	phone_end

VioletCity_Text_ElmCall:
	.string "Hello, {PLAYER}?\n"
	.string "We discovered something about\l"
	.string "the EGG!\p"
	.string "My assistant is at the POKéMON\n"
	.string "CENTER in VIOLET CITY.\l"
	.string "Could you talk to him?$"

PhoneScript_StandardMatchCallTrainer::
	phone_callnativecontext SelectMessage_StandardMatchCallTrainer
	phone_stdcall gStringVar4
	phone_end
