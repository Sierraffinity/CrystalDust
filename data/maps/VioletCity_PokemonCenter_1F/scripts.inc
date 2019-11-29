VioletCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VioletCity_PokemonCenter_1F_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

VioletCity_PokemonCenter_1F_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	setrespawn HEAL_LOCATION_VIOLET_CITY
	return


VioletCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, 1
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	return


VioletCity_PokemonCenter_1F_EventScript_Gameboy_Kid::
	msgbox VioletCity_PokemonCenter_1F_EventScript_Gameboy_Kid_Text_0, MSGBOX_NPC
	return


VioletCity_PokemonCenter_1F_EventScript_Gentleman::
	msgbox VioletCity_PokemonCenter_1F_EventScript_Gentleman_Text_0, MSGBOX_NPC
	return


VioletCity_PokemonCenter_1F_EventScript_Youngster::
	msgbox VioletCity_PokemonCenter_1F_EventScript_Youngster_Text_0, MSGBOX_NPC
	return


VioletCity_PokemonCenter_1F_EventScript_Aide::
	lock
	faceplayer
	goto_if_unset FLAG_REFUSED_ELMS_EGG, VioletCity_PokemonCenter_1F_EventScript_Aide_2
	msgbox VioletCity_PokemonCenter_1F_EventScript_Aide_Text_1, MSGBOX_YESNO
VioletCity_PokemonCenter_1F_EventScript_Aide_1:
	compare VAR_RESULT, YES
	goto_if_eq VioletCity_PokemonCenter_1F_EventScript_Aide_6
	msgbox VioletCity_PokemonCenter_1F_EventScript_Aide_Text_5
	setflag FLAG_REFUSED_ELMS_EGG
VioletCity_PokemonCenter_1F_EventScript_Aide_5:
	release
	return

VioletCity_PokemonCenter_1F_EventScript_Aide_2:
	msgbox VioletCity_PokemonCenter_1F_EventScript_Aide_Text_0, MSGBOX_YESNO
	goto VioletCity_PokemonCenter_1F_EventScript_Aide_1

VioletCity_PokemonCenter_1F_EventScript_Aide_6:
	getpartysize
	compare VAR_RESULT, 6
	goto_if_ne VioletCity_PokemonCenter_1F_EventScript_Aide_9
	msgbox VioletCity_PokemonCenter_1F_EventScript_Aide_Text_4
	goto VioletCity_PokemonCenter_1F_EventScript_Aide_5

VioletCity_PokemonCenter_1F_EventScript_Aide_9:
	delay 5
	textcolor MSG_COLOR_MISC
	setflag FLAG_GOT_ELMS_EGG
	playfanfare MUS_FANFA4
	message VioletCity_PokemonCenter_1F_EventScript_Aide_Text_2
	waitfanfare
	giveegg SPECIES_TOGEPI
	call RestoreOriginalTextColor
	msgbox VioletCity_PokemonCenter_1F_EventScript_Aide_Text_3
	closemessage
	compare VAR_FACING, DIR_NORTH
	goto_if_eq VioletCity_PokemonCenter_1F_EventScript_Aide_13
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceFastestDown
	applymovement 5, VioletCity_PokemonCenter_1F_Movement_AideStraightOut
	waitmovement 0
VioletCity_PokemonCenter_1F_EventScript_Aide_12:
	playse SE_KAIDAN
	removeobject 5
	clearflag FLAG_HIDE_NEW_BARK_TOWN_ELMS_LAB_AIDE
	goto VioletCity_PokemonCenter_1F_EventScript_Aide_5

VioletCity_PokemonCenter_1F_EventScript_Aide_13:
	applymovement EVENT_OBJ_ID_PLAYER, VioletCity_PokemonCenter_1F_Movement_PlayerWatchesAide
	applymovement 5, VioletCity_PokemonCenter_1F_Movement_AideAroundPlayer
	waitmovement 0
	goto VioletCity_PokemonCenter_1F_EventScript_Aide_12


VioletCity_PokemonCenter_1F_Movement_AideStraightOut:
	walk_down
	walk_right
	walk_down
	walk_down
	walk_down
	delay_4
	step_end

VioletCity_PokemonCenter_1F_Movement_AideAroundPlayer:
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	delay_4
	step_end

VioletCity_PokemonCenter_1F_Movement_PlayerWatchesAide:
	delay_16
	walk_in_place_fastest_right
	delay_16
	walk_in_place_fastest_down
	step_end

VioletCity_PokemonCenter_1F_EventScript_Gameboy_Kid_Text_0:
	.string "A guy named BILL made the POKéMON\n"
	.string "PC storage system.$"

VioletCity_PokemonCenter_1F_EventScript_Gentleman_Text_0:
	.string "Around three years ago, TEAM ROCKET\n"
	.string "was up to no good with POKéMON.\p"
	.string "But justice prevailed--a young kid\n"
	.string "broke 'em up.$"

VioletCity_PokemonCenter_1F_EventScript_Youngster_Text_0:
	.string "POKéMON are smart. They won't obey\n"
	.string "a TRAINER they don't respect.\p"
	.string "Without the right GYM BADGES,\n"
	.string "they'll do just as they please.$"

VioletCity_PokemonCenter_1F_EventScript_Aide_Text_0:
	.string "{PLAYER}!\n"
	.string "Long time, no see.\p"
	.string "PROF. ELM asked me to find you.\n"
	.string "He has another favor to ask.\p"
	.string "Would you take the POKéMON EGG?$"

VioletCity_PokemonCenter_1F_EventScript_Aide_Text_1:
	.string "{PLAYER}, will you take the EGG?$"

VioletCity_PokemonCenter_1F_EventScript_Aide_Text_2:
	.string "{PLAYER} received the EGG.$"

VioletCity_PokemonCenter_1F_EventScript_Aide_Text_3:
	.string "We discovered that a POKéMON won't\n"
	.string "hatch until it grows in the EGG.\p"
	.string "It also has to be with other active\n"
	.string "POKéMON to hatch.\p"
	.string "{PLAYER}, you're the only person we can\n"
	.string "rely on.\p"
	.string "Please call PROF. ELM when that\n"
	.string "EGG hatches!$"

VioletCity_PokemonCenter_1F_EventScript_Aide_Text_4:
	.string "Oh, no. You can't carry any more\n"
	.string "POKéMON with you.\p"
	.string "I'll wait here while you make\n"
	.string "room for the EGG.$"

VioletCity_PokemonCenter_1F_EventScript_Aide_Text_5:
	.string "B-but…\n"
	.string "PROF. ELM asked for you…$"
