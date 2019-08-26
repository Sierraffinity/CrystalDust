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
#include "constants/maps.h"
#include "constants/moves.h"
#include "constants/radio.h"
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
	phone_stdcall Text_Pokegear_Mom_RegularCallPlaceholder
	phone_end

PhoneScript_Mom_BeginPhoneBanking:
	phone_setflag FLAG_TALKED_TO_MOM_AFTER_MYSTERY_EGG_QUEST
	phone_stdcall Text_Pokegear_Mom_PhoneBankingPlaceholder
	phone_end

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

Text_Pokegear_Mom_PhoneBankingPlaceholder:
	.string "Hello?\n"
	.string "…… {PLAYER}?\p"
	.string "I heard from PROF. ELM that you\n"
	.string "went on a long trip.\p"
	.string "I wish you would have told me…\p"
	.string "What about money?\n"
	.string "Do you want me to save it?\p"
	.string "…insert yesno box here…\p"
	.string "Okay. I'll save your money.\p"
	.string "Okay. I won't save your money.\p"
	.string "{PLAYER}, keep it up!\n"
	.string "I'm rooting for you, baby!$"

Text_Pokegear_Mom_RegularCallPlaceholder:
	.string "Hello?\n"
	.string "Oh, hi, {PLAYER}! Working hard?\p"
	.string "…insert location stuff here…\p"
	.string "…insert money stuff here…\p"
	.string "{PLAYER}, keep it up!\n"
	.string "I'm rooting for you, baby!$"

PhoneScript_Elm::
	phone_goto_if_set FLAG_GAVE_MYSTERY_EGG_TO_ELM, PhoneScript_Elm_CheckingEgg
	phone_goto_if_set FLAG_ELM_CALLED_ABOUT_STOLEN_MON, PhoneScript_Elm_MonWasStolen
	phone_goto_if_set FLAG_RECEIVED_MYSTERY_EGG, PhoneScript_Elm_SawMrPokemon
	phone_stdcall Text_Pokegear_Elm_Start
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

PhoneScript_StandardMatchCallTrainer::
	phone_callnativecontext SelectMessage_StandardMatchCallTrainer
	phone_stdcall gStringVar4
	phone_end
