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
	msgbox VioletCity_PokemonCenter_1F_EventScript_Aide_Text_10
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
	msgbox VioletCity_PokemonCenter_1F_EventScript_Aide_Text_9
	goto VioletCity_PokemonCenter_1F_EventScript_Aide_5

VioletCity_PokemonCenter_1F_EventScript_Aide_9:
	textcolor MSG_COLOR_SYS
	setflag FLAG_GOT_ELMS_EGG
	playfanfare MUS_OBTAIN_EGG
	message VioletCity_PokemonCenter_1F_EventScript_Aide_Text_2
	waitfanfare
	giveegg SPECIES_TOGEPI
	textcolor MSG_COLOR_PREV
	msgbox VioletCity_PokemonCenter_1F_EventScript_Aide_Text_3
	closemessage
	compare VAR_FACING, DIR_NORTH
	goto_if_eq VioletCity_PokemonCenter_1F_EventScript_Aide_13
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestDown
	applymovement 5, VioletCity_PokemonCenter_1F_Movement_AideStraightOut
	waitmovement 0
VioletCity_PokemonCenter_1F_EventScript_Aide_12:
	playse SE_PIN
	applymovement 5, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	switch VAR_FACING
	case DIR_NORTH, VioletCity_PokemonCenter_1F_EventScript_Aide_18
	case DIR_WEST, VioletCity_PokemonCenter_1F_EventScript_Aide_19
	case DIR_EAST, VioletCity_PokemonCenter_1F_EventScript_Aide_20
VioletCity_PokemonCenter_1F_EventScript_Aide_16:
	msgbox VioletCity_PokemonCenter_1F_EventScript_Aide_Text_4
	textcolor MSG_COLOR_SYS
	playfanfare MUS_OBTAIN_ITEM
	message VioletCity_PokemonCenter_1F_EventScript_Aide_Text_5
	waitmessage
	waitfanfare
	msgbox VioletCity_PokemonCenter_1F_EventScript_Aide_Text_6
	setflag FLAG_RECEIVED_RUNNING_SHOES
	signmsg
	msgbox VioletCity_PokemonCenter_1F_EventScript_Aide_Text_7
	normalmsg
	textcolor MSG_COLOR_PREV
	msgbox VioletCity_PokemonCenter_1F_EventScript_Aide_Text_8
	closemessage
	switch VAR_FACING
	case DIR_NORTH, VioletCity_PokemonCenter_1F_EventScript_Aide_23
	case DIR_WEST, VioletCity_PokemonCenter_1F_EventScript_Aide_24
	case DIR_EAST, VioletCity_PokemonCenter_1F_EventScript_Aide_25
VioletCity_PokemonCenter_1F_EventScript_Aide_21:
	playse SE_EXIT
	removeobject 5
	waitse
	clearflag FLAG_HIDE_NEW_BARK_TOWN_ELMS_LAB_AIDE
	setvar VAR_ROUTE32_STATE, 1
	setflag FLAG_SYS_B_DASH
	goto VioletCity_PokemonCenter_1F_EventScript_Aide_5

VioletCity_PokemonCenter_1F_EventScript_Aide_13:
	applymovement OBJ_EVENT_ID_PLAYER, VioletCity_PokemonCenter_1F_Movement_PlayerWatchesAide
	applymovement 5, VioletCity_PokemonCenter_1F_Movement_AideAroundPlayer
	waitmovement 0
	goto VioletCity_PokemonCenter_1F_EventScript_Aide_12

VioletCity_PokemonCenter_1F_EventScript_Aide_18:
	applymovement 5, VioletCity_PokemonCenter_1F_Movement_AideToPlayerCenter
	waitmovement 0
	goto VioletCity_PokemonCenter_1F_EventScript_Aide_16

VioletCity_PokemonCenter_1F_EventScript_Aide_19:
	applymovement 5, VioletCity_PokemonCenter_1F_Movement_AideToPlayerRight
	waitmovement 0
	goto VioletCity_PokemonCenter_1F_EventScript_Aide_16

VioletCity_PokemonCenter_1F_EventScript_Aide_20:
	applymovement 5, VioletCity_PokemonCenter_1F_Movement_AideToPlayerLeft
	waitmovement 0
	goto VioletCity_PokemonCenter_1F_EventScript_Aide_16

VioletCity_PokemonCenter_1F_EventScript_Aide_23:
	applymovement 5, VioletCity_PokemonCenter_1F_Movement_AideFromPlayerCenter
	waitmovement 0
	goto VioletCity_PokemonCenter_1F_EventScript_Aide_21

VioletCity_PokemonCenter_1F_EventScript_Aide_24:
	applymovement 5, VioletCity_PokemonCenter_1F_Movement_AideFromPlayerRight
	waitmovement 0
	goto VioletCity_PokemonCenter_1F_EventScript_Aide_21

VioletCity_PokemonCenter_1F_EventScript_Aide_25:
	applymovement 5, VioletCity_PokemonCenter_1F_Movement_AideFromPlayerLeft
	waitmovement 0
	goto VioletCity_PokemonCenter_1F_EventScript_Aide_21


VioletCity_PokemonCenter_1F_Movement_AideStraightOut:
	walk_down
	walk_right
	walk_down
	walk_down
	step_end

VioletCity_PokemonCenter_1F_Movement_AideAroundPlayer:
	walk_right
	walk_down
	walk_down
	walk_down
	step_end

VioletCity_PokemonCenter_1F_Movement_AideToPlayerCenter:
	walk_up
	walk_left
	face_up
	step_end

VioletCity_PokemonCenter_1F_Movement_AideToPlayerRight:
	walk_up
	walk_up
	step_end

VioletCity_PokemonCenter_1F_Movement_AideToPlayerLeft:
	walk_up
	walk_up
	walk_left
	walk_left
	face_up
	step_end

VioletCity_PokemonCenter_1F_Movement_AideFromPlayerCenter:
	walk_down
	walk_right
	walk_down
	delay_4
	step_end

VioletCity_PokemonCenter_1F_Movement_AideFromPlayerRight:
	walk_down
	walk_down
	walk_down
	delay_4
	step_end

VioletCity_PokemonCenter_1F_Movement_AideFromPlayerLeft:
	walk_right
	walk_right
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
	.string "{PLAYER} received the EGG\n"
	.string "from ELM's AIDE.$"

VioletCity_PokemonCenter_1F_EventScript_Aide_Text_3:
	.string "We discovered that a POKéMON won't\n"
	.string "hatch until it grows in the EGG.\p"
	.string "It also has to be with other active\n"
	.string "POKéMON to hatch.\p"
	.string "{PLAYER}, you're the only person\n"
	.string "we can rely on.\p"
	.string "Please call PROF. ELM when that\n"
	.string "EGG hatches!$"

VioletCity_PokemonCenter_1F_EventScript_Aide_Text_4:
	.string "Oh, that's right!\n"
	.string "I have something else with me.\p"
	.string "Your mom asked me to deliver these\n"
	.string "when I saw you.$"

VioletCity_PokemonCenter_1F_EventScript_Aide_Text_5:
	.string "{PLAYER} received the\n"
	.string "RUNNING SHOES from the AIDE.$"

VioletCity_PokemonCenter_1F_EventScript_Aide_Text_6:
	.string "{PLAYER} switched shoes with the\n"
	.string "RUNNING SHOES.$"

VioletCity_PokemonCenter_1F_EventScript_Aide_Text_7:
	.string "Press the B Button to run.\n"
	.string "There's almost always room to run!$"

VioletCity_PokemonCenter_1F_EventScript_Aide_Text_8:
	.string "I need to head back to the lab now.\n"
	.string "Good luck with the EGG!$"

VioletCity_PokemonCenter_1F_EventScript_Aide_Text_9:
	.string "Oh, no. You can't carry any more\n"
	.string "POKéMON with you.\p"
	.string "I'll wait here while you make\n"
	.string "room for the EGG.$"

VioletCity_PokemonCenter_1F_EventScript_Aide_Text_10:
	.string "B-but…\n"
	.string "PROF. ELM asked for you…$"
