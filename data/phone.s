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
	phone_stdcall PhoneScript_Mom_Text
	phone_end

PhoneScript_Mom_Text:
	.string "Hi, I'm MOM.$"

PhoneScript_Elm::
	phone_stdcall PhoneScript_Elm_Text
	phone_end

PhoneScript_Elm_Text:
	.string "Hi, I'm ELM.$"

PhoneScript_StandardMatchCallTrainer::
	phone_callnativecontext SelectMessage_StandardMatchCallTrainer
	phone_stdcall gStringVar4
	phone_end
