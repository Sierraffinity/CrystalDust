NewBarkTown_ProfessorElmsLab_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, NewBarkTown_ProfessorElmsLab_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_FRAME_TABLE, NewBarkTown_ProfessorElmsLab_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

NewBarkTown_ProfessorElmsLab_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	compare VAR_ELM_LAB_STATE, 0
	goto_if_eq NewBarkTown_ProfessorElmsLab_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	return

NewBarkTown_ProfessorElmsLab_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
	setobjectxyperm 2, 4, 5
	return

NewBarkTown_ProfessorElmsLab_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_ELM_LAB_STATE, 0, NewBarkTown_ProfessorElmsLab_EventScript_ElmIntroduction
	.2byte 0


NewBarkTown_ProfessorElmsLab_EventScript_Elm::
	lock
	faceplayer
	goto_if_set FLAG_GOT_EVERSTONE_FROM_ELM, NewBarkTown_ProfessorElmsLab_EventScript_Elm_2
	goto_if_set FLAG_SHOWED_TOGEPI_TO_ELM, NewBarkTown_ProfessorElmsLab_EventScript_Elm_3
	goto_if_set FLAG_GOT_ELMS_EGG, NewBarkTown_ProfessorElmsLab_EventScript_Elm_4
	goto_if_set FLAG_ELM_CALLED_ABOUT_ASSISTANT_IN_VIOLET, NewBarkTown_ProfessorElmsLab_EventScript_Elm_5
	goto_if_set FLAG_GAVE_MYSTERY_EGG_TO_ELM, NewBarkTown_ProfessorElmsLab_EventScript_Elm_6
	goto_if_set FLAG_RECEIVED_MYSTERY_EGG, NewBarkTown_ProfessorElmsLab_EventScript_Elm_7
	goto_if_set FLAG_SYS_POKEMON_GET, NewBarkTown_ProfessorElmsLab_EventScript_Elm_8
	msgbox NewBarkTown_ProfessorElmsLab_EventScript_Elm_Text_9
NewBarkTown_ProfessorElmsLab_EventScript_Elm_1:
	release
	return

NewBarkTown_ProfessorElmsLab_EventScript_Elm_2:
	msgbox NewBarkTown_ProfessorElmsLab_EventScript_Elm_Text_0
	goto NewBarkTown_ProfessorElmsLab_EventScript_Elm_1

NewBarkTown_ProfessorElmsLab_EventScript_Elm_3:
	call NewBarkTown_ProfessorElmsLab_EventScript_Elm_GiveEverstone
	goto NewBarkTown_ProfessorElmsLab_EventScript_Elm_1

NewBarkTown_ProfessorElmsLab_EventScript_Elm_4:
	goto_if_unset FLAG_HATCHED_ELMS_EGG, NewBarkTown_ProfessorElmsLab_EventScript_Elm_17
	setvar VAR_0x8004, SPECIES_TOGEPI
	special IsPlayersMonOfSpeciesInParty
	compare VAR_RESULT, 0
	goto_if_eq NewBarkTown_ProfessorElmsLab_EventScript_Elm_27
NewBarkTown_ProfessorElmsLab_EventScript_Elm_26:
	msgbox NewBarkTown_ProfessorElmsLab_EventScript_Elm_Text_1
	closemessage
	playse SE_PIN
	applymovement 2, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	msgbox NewBarkTown_ProfessorElmsLab_EventScript_Elm_Text_2, MSGBOX_CONTINUE
	setflag FLAG_SHOWED_TOGEPI_TO_ELM
	call NewBarkTown_ProfessorElmsLab_EventScript_Elm_GiveEverstone
	goto NewBarkTown_ProfessorElmsLab_EventScript_Elm_1

NewBarkTown_ProfessorElmsLab_EventScript_Elm_5:
	msgbox NewBarkTown_ProfessorElmsLab_EventScript_Elm_Text_3
	goto NewBarkTown_ProfessorElmsLab_EventScript_Elm_1

NewBarkTown_ProfessorElmsLab_EventScript_Elm_6:
	msgbox NewBarkTown_ProfessorElmsLab_EventScript_Elm_Text_4
	goto NewBarkTown_ProfessorElmsLab_EventScript_Elm_1

NewBarkTown_ProfessorElmsLab_EventScript_Elm_7:
	msgbox NewBarkTown_ProfessorElmsLab_EventScript_Elm_Text_5
	textcolor MSG_COLOR_SYS
	playfanfare MUS_OBTAIN_ITEM
	message NewBarkTown_ProfessorElmsLab_EventScript_Elm_Text_6
	waitmessage
	waitfanfare
	closemessage
	textcolor MSG_COLOR_PREV
	removeitem ITEM_MYSTERY_EGG
	delay 10
	playse SE_LEDGE
	switch VAR_FACING
	case DIR_SOUTH, NewBarkTown_ProfessorElmsLab_EventScript_Elm_22
	case DIR_NORTH, NewBarkTown_ProfessorElmsLab_EventScript_Elm_23
	case DIR_WEST, NewBarkTown_ProfessorElmsLab_EventScript_Elm_24
	case DIR_EAST, NewBarkTown_ProfessorElmsLab_EventScript_Elm_25
NewBarkTown_ProfessorElmsLab_EventScript_Elm_20:
	msgbox NewBarkTown_ProfessorElmsLab_EventScript_Elm_Text_7
	setflag FLAG_ADVENTURE_STARTED
	special SetUnlockedPokedexFlags
	setflag FLAG_GAVE_MYSTERY_EGG_TO_ELM
	setflag FLAG_HIDE_ROUTE_30_YOUNGSTER_BATTLE_OBJECTS
	clearflag FLAG_HIDE_ROUTE_30_YOUNGSTER_DEFEATED
	setvar VAR_ROUTE29_STATE, 1
	setvar VAR_ELM_LAB_STATE, 6
	setvar VAR_CABLE_CLUB_TUTORIAL_STATE, 1
	goto NewBarkTown_ProfessorElmsLab_EventScript_Elm_1

NewBarkTown_ProfessorElmsLab_EventScript_Elm_8:
	msgbox NewBarkTown_ProfessorElmsLab_EventScript_Elm_Text_8
	goto NewBarkTown_ProfessorElmsLab_EventScript_Elm_1

NewBarkTown_ProfessorElmsLab_EventScript_Elm_17:
	msgbox NewBarkTown_ProfessorElmsLab_Text_Elm_HasThatEggHatched
	goto NewBarkTown_ProfessorElmsLab_EventScript_Elm_1

NewBarkTown_ProfessorElmsLab_EventScript_Elm_22:
	applymovement 2, NewBarkTown_ProfessorElmsLab_Movement_ElmJumpsDown
	waitmovement 0
	msgbox NewBarkTown_ProfessorElmsLab_Text_ElmThis
	closemessage
	applymovement 2, NewBarkTown_ProfessorElmsLab_Movement_ElmStepsUp
	waitmovement 0
	goto NewBarkTown_ProfessorElmsLab_EventScript_Elm_20

NewBarkTown_ProfessorElmsLab_EventScript_Elm_23:
	applymovement 2, NewBarkTown_ProfessorElmsLab_Movement_ElmJumpsUp
	waitmovement 0
	msgbox NewBarkTown_ProfessorElmsLab_Text_ElmThis
	closemessage
	applymovement 2, NewBarkTown_ProfessorElmsLab_Movement_ElmStepsDown
	waitmovement 0
	goto NewBarkTown_ProfessorElmsLab_EventScript_Elm_20

NewBarkTown_ProfessorElmsLab_EventScript_Elm_24:
	applymovement 2, NewBarkTown_ProfessorElmsLab_Movement_ElmJumpsLeft
	waitmovement 0
	msgbox NewBarkTown_ProfessorElmsLab_Text_ElmThis
	closemessage
	applymovement 2, NewBarkTown_ProfessorElmsLab_Movement_ElmStepsRight
	waitmovement 0
	goto NewBarkTown_ProfessorElmsLab_EventScript_Elm_20

NewBarkTown_ProfessorElmsLab_EventScript_Elm_25:
	applymovement 2, NewBarkTown_ProfessorElmsLab_Movement_ElmJumpsRight
	waitmovement 0
	msgbox NewBarkTown_ProfessorElmsLab_Text_ElmThis
	closemessage
	applymovement 2, NewBarkTown_ProfessorElmsLab_Movement_ElmStepsLeft
	waitmovement 0
	goto NewBarkTown_ProfessorElmsLab_EventScript_Elm_20

NewBarkTown_ProfessorElmsLab_EventScript_Elm_27:
	setvar VAR_0x8004, SPECIES_TOGETIC
	special IsPlayersMonOfSpeciesInParty
	compare VAR_RESULT, 0
	goto_if_eq NewBarkTown_ProfessorElmsLab_EventScript_Elm_29
	goto NewBarkTown_ProfessorElmsLab_EventScript_Elm_26

NewBarkTown_ProfessorElmsLab_EventScript_Elm_29:
	goto NewBarkTown_ProfessorElmsLab_EventScript_Elm_NoHatchedEggMon
	goto NewBarkTown_ProfessorElmsLab_EventScript_Elm_26


NewBarkTown_ProfessorElmsLab_EventScript_Elm_NoHatchedEggMon::
	goto_if_set FLAG_CALLED_ELM_ABOUT_HATCHED_EGG, NewBarkTown_ProfessorElmsLab_EventScript_Elm_NoHatchedEggMon_2
	msgbox NewBarkTown_ProfessorElmsLab_Text_Elm_HasThatEggHatched
NewBarkTown_ProfessorElmsLab_EventScript_Elm_NoHatchedEggMon_1:
	release
	return

NewBarkTown_ProfessorElmsLab_EventScript_Elm_NoHatchedEggMon_2:
	msgbox NewBarkTown_ProfessorElmsLab_EventScript_Elm_NoHatchedEggMon_Text_0
	goto NewBarkTown_ProfessorElmsLab_EventScript_Elm_NoHatchedEggMon_1


NewBarkTown_ProfessorElmsLab_EventScript_Elm_GiveEverstone::
	msgbox NewBarkTown_ProfessorElmsLab_EventScript_Elm_GiveEverstone_Text_0
	checkitemspace ITEM_EVERSTONE, 1
	compare VAR_RESULT, 0
	goto_if_eq NewBarkTown_ProfessorElmsLab_EventScript_Elm_GiveEverstone_2
	giveitem_msg NewBarkTown_ProfessorElmsLab_EventScript_Elm_GiveEverstone_Text_2, ITEM_EVERSTONE
	msgbox NewBarkTown_ProfessorElmsLab_EventScript_Elm_GiveEverstone_Text_3
	setflag FLAG_GOT_EVERSTONE_FROM_ELM
NewBarkTown_ProfessorElmsLab_EventScript_Elm_GiveEverstone_1:
	release
	return

NewBarkTown_ProfessorElmsLab_EventScript_Elm_GiveEverstone_2:
	msgbox NewBarkTown_ProfessorElmsLab_EventScript_Elm_GiveEverstone_Text_1
	goto NewBarkTown_ProfessorElmsLab_EventScript_Elm_GiveEverstone_1


NewBarkTown_ProfessorElmsLab_Movement_ElmJumpsDown:
	lock_facing_direction
	disable_jump_landing_ground_effect
	jump_down
	unlock_facing_direction
	step_end

NewBarkTown_ProfessorElmsLab_Movement_ElmStepsUp:
	walk_up
	step_end

NewBarkTown_ProfessorElmsLab_Movement_ElmJumpsUp:
	lock_facing_direction
	disable_jump_landing_ground_effect
	jump_up
	unlock_facing_direction
	step_end

NewBarkTown_ProfessorElmsLab_Movement_ElmStepsDown:
	walk_down
	step_end

NewBarkTown_ProfessorElmsLab_Movement_ElmJumpsLeft:
	lock_facing_direction
	disable_jump_landing_ground_effect
	jump_left
	unlock_facing_direction
	step_end

NewBarkTown_ProfessorElmsLab_Movement_ElmStepsRight:
	walk_right
	step_end

NewBarkTown_ProfessorElmsLab_Movement_ElmJumpsRight:
	lock_facing_direction
	disable_jump_landing_ground_effect
	jump_right
	unlock_facing_direction
	step_end

NewBarkTown_ProfessorElmsLab_Movement_ElmStepsLeft:
	walk_left
	step_end

NewBarkTown_ProfessorElmsLab_EventScript_ElmIntroduction::
	lockall
	textcolor MSG_COLOR_BLUE
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_ProfessorElmsLab_Movement_PlayerStepToElm
	waitmovement 0
	playse SE_PIN
	applymovement 2, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	applymovement 2, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	msgbox NewBarkTown_ProfessorElmsLab_EventScript_ElmIntroduction_Text_0, MSGBOX_YESNO
	goto NewBarkTown_ProfessorElmsLab_EventScript_ElmBeggingLoop
	return


NewBarkTown_ProfessorElmsLab_EventScript_ElmBeggingLoop::
	compare VAR_RESULT, YES
	goto_if_eq NewBarkTown_ProfessorElmsLab_EventScript_ElmBeggingLoop_2
NewBarkTown_ProfessorElmsLab_EventScript_ElmBeggingLoop_1:
	msgbox NewBarkTown_ProfessorElmsLab_EventScript_ElmBeggingLoop_Text_0, MSGBOX_YESNO
	goto NewBarkTown_ProfessorElmsLab_EventScript_ElmBeggingLoop
	return

NewBarkTown_ProfessorElmsLab_EventScript_ElmBeggingLoop_2:
	goto NewBarkTown_ProfessorElmsLab_EventScript_ElmPostBegging
	goto NewBarkTown_ProfessorElmsLab_EventScript_ElmBeggingLoop_1


NewBarkTown_ProfessorElmsLab_EventScript_ElmPostBegging::
	msgbox NewBarkTown_ProfessorElmsLab_EventScript_ElmPostBegging_Text_0
	closemessage
	delay 20
	playse SE_SUCCESS
	waitse
	delay 20
	playse SE_PIN
	applymovement 2, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	applymovement 2, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	msgbox NewBarkTown_ProfessorElmsLab_EventScript_ElmPostBegging_Text_1
	closemessage
	delay 30
	applymovement 2, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	msgbox NewBarkTown_ProfessorElmsLab_EventScript_ElmPostBegging_Text_2
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_ProfessorElmsLab_Movement_PlayerWatchElmWalk
	applymovement 2, NewBarkTown_ProfessorElmsLab_Movement_ElmWalkToPokeBalls
	waitmovement 0
	msgbox NewBarkTown_ProfessorElmsLab_EventScript_ElmPostBegging_Text_3
	closemessage
	setvar VAR_ELM_LAB_STATE, 1
	releaseall
	return


NewBarkTown_ProfessorElmsLab_Movement_PlayerStepToElm:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	step_end

NewBarkTown_ProfessorElmsLab_Movement_PlayerWatchElmWalk:
	delay_16
	walk_in_place_fastest_up
	delay_16
	walk_in_place_fastest_right
	step_end

NewBarkTown_ProfessorElmsLab_Movement_ElmWalkToPokeBalls:
	walk_up
	walk_up
	walk_right
	walk_right
	face_down
	step_end

NewBarkTown_ProfessorElmsLab_EventScript_ElmWaitDontGo::
	lockall
	textcolor MSG_COLOR_BLUE
	turnobject 2, DIR_SOUTH
	msgbox NewBarkTown_ProfessorElmsLab_EventScript_ElmWaitDontGo_Text_0
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_ProfessorElmsLab_Movement_PlayerComeBack
	waitmovement 0
	releaseall
	return


NewBarkTown_ProfessorElmsLab_Movement_PlayerComeBack:
	walk_up
	step_end

NewBarkTown_ProfessorElmsLab_EventScript_Chikorita::
	lock
	faceplayer
	setvar VAR_TEMP_1, STARTER_CHIKORITA
	setvar VAR_TEMP_2, SPECIES_CHIKORITA
	goto NewBarkTown_EventScript_PokeBallMain
	return


NewBarkTown_ProfessorElmsLab_EventScript_Totodile::
	lock
	faceplayer
	setvar VAR_TEMP_1, STARTER_TOTODILE
	setvar VAR_TEMP_2, SPECIES_TOTODILE
	goto NewBarkTown_EventScript_PokeBallMain
	return


NewBarkTown_ProfessorElmsLab_EventScript_Cyndaquil::
	lock
	faceplayer
	setvar VAR_TEMP_1, STARTER_CYNDAQUIL
	setvar VAR_TEMP_2, SPECIES_CYNDAQUIL
	goto NewBarkTown_EventScript_PokeBallMain
	return


NewBarkTown_EventScript_PokeBallMain::
	goto_if_set FLAG_SYS_POKEMON_GET, NewBarkTown_EventScript_PokeBallMain_2
	turnobject 2, DIR_EAST
	showmonpic VAR_TEMP_2, 10, 3
	playmoncry VAR_TEMP_2, 0
	textcolor MSG_COLOR_BLUE
	switch VAR_TEMP_1
	case STARTER_CHIKORITA, NewBarkTown_EventScript_PokeBallMain_7
	case STARTER_TOTODILE, NewBarkTown_EventScript_PokeBallMain_8
	case STARTER_CYNDAQUIL, NewBarkTown_EventScript_PokeBallMain_9
NewBarkTown_EventScript_PokeBallMain_5:
	hidemonpic
	compare VAR_RESULT, YES
	goto_if_ne NewBarkTown_EventScript_PokeBallMain_10
	removeobject VAR_LAST_TALKED
	msgbox NewBarkTown_EventScript_PokeBallMain_Text_5
	textcolor MSG_COLOR_PREV
	setflag FLAG_SYS_POKEMON_GET
	givemon VAR_TEMP_2, 5, ITEM_ORAN_BERRY
	copyvar VAR_STARTER_MON, VAR_TEMP_1
	bufferspeciesname 0, VAR_TEMP_2
	message NewBarkTown_EventScript_PokeBallMain_Text_6
	waitmessage
	goto_if_set FLAG_SYS_GBS_ENABLED, NewBarkTown_EventScript_PokeBallMain_14
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
NewBarkTown_EventScript_PokeBallMain_13:
	waitfanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq NewBarkTown_EventScript_PokeBallMain_18
NewBarkTown_EventScript_PokeBallMain_17:
	closemessage
	switch VAR_FACING
	case DIR_SOUTH, NewBarkTown_EventScript_PokeBallMain_22
	case DIR_NORTH, NewBarkTown_EventScript_PokeBallMain_23
	case DIR_EAST, NewBarkTown_EventScript_PokeBallMain_24
NewBarkTown_EventScript_PokeBallMain_20:
	waitmovement 0
	delay 20
	textcolor MSG_COLOR_BLUE
	msgbox NewBarkTown_EventScript_PokeBallMain_Text_7
	setflag FLAG_PHONE_CARD_ELM
	playfanfare MUS_REGISTER_PHONE
	textcolor MSG_COLOR_PREV
	msgbox NewBarkTown_EventScript_PokeBallMain_Text_8
	waitfanfare
	applymovement 2, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	textcolor MSG_COLOR_BLUE
	msgbox NewBarkTown_EventScript_PokeBallMain_Text_9
	applymovement 2, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	msgbox NewBarkTown_EventScript_PokeBallMain_Text_10
	setvar VAR_ELM_LAB_STATE, 2
	setvar VAR_NEW_BARK_TOWN_STATE, 1
NewBarkTown_EventScript_PokeBallMain_1:
	release
	return

NewBarkTown_EventScript_PokeBallMain_2:
	msgbox NewBarkTown_EventScript_PokeBallMain_Text_0
	goto NewBarkTown_EventScript_PokeBallMain_1

NewBarkTown_EventScript_PokeBallMain_7:
	msgbox NewBarkTown_EventScript_PokeBallMain_Text_1, MSGBOX_YESNO
	goto NewBarkTown_EventScript_PokeBallMain_5

NewBarkTown_EventScript_PokeBallMain_8:
	msgbox NewBarkTown_EventScript_PokeBallMain_Text_2, MSGBOX_YESNO
	goto NewBarkTown_EventScript_PokeBallMain_5

NewBarkTown_EventScript_PokeBallMain_9:
	msgbox NewBarkTown_EventScript_PokeBallMain_Text_3, MSGBOX_YESNO
	goto NewBarkTown_EventScript_PokeBallMain_5

NewBarkTown_EventScript_PokeBallMain_10:
	msgbox NewBarkTown_EventScript_PokeBallMain_Text_4
	goto NewBarkTown_EventScript_PokeBallMain_1

NewBarkTown_EventScript_PokeBallMain_14:
	playfanfare MUS_RG_CAUGHT_INTRO
	goto NewBarkTown_EventScript_PokeBallMain_13

NewBarkTown_EventScript_PokeBallMain_18:
	setvar VAR_0x8004, 0
	call Common_EventScript_NameReceivedPartyMon
	goto NewBarkTown_EventScript_PokeBallMain_17

NewBarkTown_EventScript_PokeBallMain_22:
	switch VAR_TEMP_1
	case STARTER_CHIKORITA, NewBarkTown_EventScript_PokeBallMain_26
	case STARTER_TOTODILE, NewBarkTown_EventScript_PokeBallMain_27
	case STARTER_CYNDAQUIL, NewBarkTown_EventScript_PokeBallMain_28
	goto NewBarkTown_EventScript_PokeBallMain_20

NewBarkTown_EventScript_PokeBallMain_23:
	switch VAR_TEMP_1
	case STARTER_CHIKORITA, NewBarkTown_EventScript_PokeBallMain_30
	case STARTER_TOTODILE, NewBarkTown_EventScript_PokeBallMain_31
	case STARTER_CYNDAQUIL, NewBarkTown_EventScript_PokeBallMain_32
	goto NewBarkTown_EventScript_PokeBallMain_20

NewBarkTown_EventScript_PokeBallMain_24:
	applymovement 2, Common_Movement_WalkInPlaceFastestDown
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_ProfessorElmsLab_Movement_WalkToElmFrom74
	goto NewBarkTown_EventScript_PokeBallMain_20

NewBarkTown_EventScript_PokeBallMain_26:
	applymovement 2, NewBarkTown_ProfessorElmsLab_Movement_Delay32FaceDown
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_ProfessorElmsLab_Movement_WalkToElmFrom83
	goto NewBarkTown_EventScript_PokeBallMain_20

NewBarkTown_EventScript_PokeBallMain_27:
	applymovement 2, NewBarkTown_ProfessorElmsLab_Movement_Delay48FaceDown
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_ProfessorElmsLab_Movement_WalkToElmFrom93
	goto NewBarkTown_EventScript_PokeBallMain_20

NewBarkTown_EventScript_PokeBallMain_28:
	applymovement 2, NewBarkTown_ProfessorElmsLab_Movement_Delay64FaceDown
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_ProfessorElmsLab_Movement_WalkToElmFrom103
	goto NewBarkTown_EventScript_PokeBallMain_20

NewBarkTown_EventScript_PokeBallMain_30:
	applymovement 2, NewBarkTown_ProfessorElmsLab_Movement_Delay16FaceDown
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_ProfessorElmsLab_Movement_WalkToElmFrom85
	goto NewBarkTown_EventScript_PokeBallMain_20

NewBarkTown_EventScript_PokeBallMain_31:
	applymovement 2, NewBarkTown_ProfessorElmsLab_Movement_Delay32FaceDown
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_ProfessorElmsLab_Movement_WalkToElmFrom95
	goto NewBarkTown_EventScript_PokeBallMain_20

NewBarkTown_EventScript_PokeBallMain_32:
	applymovement 2, NewBarkTown_ProfessorElmsLab_Movement_Delay48FaceDown
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_ProfessorElmsLab_Movement_WalkToElmFrom105
	goto NewBarkTown_EventScript_PokeBallMain_20


NewBarkTown_ProfessorElmsLab_Movement_Delay32FaceDown:
	delay_16
	delay_16
	walk_in_place_fastest_down
	step_end

NewBarkTown_ProfessorElmsLab_Movement_WalkToElmFrom83:
	walk_left
	walk_down
	walk_left
	face_up
	step_end

NewBarkTown_ProfessorElmsLab_Movement_Delay48FaceDown:
	delay_16
	delay_16
	delay_16
	walk_in_place_fastest_down
	step_end

NewBarkTown_ProfessorElmsLab_Movement_WalkToElmFrom93:
	walk_left
	walk_left
	walk_down
	walk_left
	face_up
	step_end

NewBarkTown_ProfessorElmsLab_Movement_Delay64FaceDown:
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_fastest_down
	step_end

NewBarkTown_ProfessorElmsLab_Movement_WalkToElmFrom103:
	walk_left
	walk_left
	walk_left
	walk_down
	walk_left
	face_up
	step_end

NewBarkTown_ProfessorElmsLab_Movement_WalkToElmFrom74:
	walk_left
	face_up
	step_end

NewBarkTown_ProfessorElmsLab_Movement_Delay16FaceDown:
	delay_16
	walk_in_place_fastest_down
	step_end

NewBarkTown_ProfessorElmsLab_Movement_WalkToElmFrom85:
	walk_left
	walk_left
	walk_up
	step_end

NewBarkTown_ProfessorElmsLab_Movement_WalkToElmFrom95:
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

NewBarkTown_ProfessorElmsLab_Movement_WalkToElmFrom105:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

NewBarkTown_ProfessorElmsLab_EventScript_AidePotion1::
	lockall
	setvar VAR_TEMP_1, 0
	applymovement 1, NewBarkTown_ProfessorElmsLab_Movement_AideToLeftTrigger
	goto NewBarkTown_ProfessorElmsLab_EventScript_AidePotionMain
	return


NewBarkTown_ProfessorElmsLab_Movement_AideToLeftTrigger:
	walk_right
	walk_right
	face_up
	step_end

NewBarkTown_ProfessorElmsLab_EventScript_AidePotion2::
	lockall
	setvar VAR_TEMP_1, 1
	applymovement 1, NewBarkTown_ProfessorElmsLab_Movement_AideToMiddleTrigger
	goto NewBarkTown_ProfessorElmsLab_EventScript_AidePotionMain
	return


NewBarkTown_ProfessorElmsLab_Movement_AideToMiddleTrigger:
	walk_right
	walk_right
	walk_right
	face_up
	step_end

NewBarkTown_ProfessorElmsLab_EventScript_AidePotion3::
	lockall
	setvar VAR_TEMP_1, 2
	applymovement 1, NewBarkTown_ProfessorElmsLab_Movement_AideToRightTrigger
	goto NewBarkTown_ProfessorElmsLab_EventScript_AidePotionMain
	return


NewBarkTown_ProfessorElmsLab_Movement_AideToRightTrigger:
	walk_right
	walk_right
	walk_right
	walk_right
	face_up
	step_end

NewBarkTown_ProfessorElmsLab_EventScript_AidePotionMain::
	waitmovement 0
	textcolor MSG_COLOR_BLUE
	msgbox NewBarkTown_ProfessorElmsLab_EventScript_AidePotionMain_Text_0
	giveitem_msg NewBarkTown_ProfessorElmsLab_EventScript_AidePotionMain_Text_1, ITEM_POTION
	msgbox NewBarkTown_ProfessorElmsLab_Text_Aide_AlwaysBusy
	closemessage
	switch VAR_TEMP_1
	case 0, NewBarkTown_ProfessorElmsLab_EventScript_AidePotionMain_3
	case 1, NewBarkTown_ProfessorElmsLab_EventScript_AidePotionMain_4
	case 2, NewBarkTown_ProfessorElmsLab_EventScript_AidePotionMain_5
NewBarkTown_ProfessorElmsLab_EventScript_AidePotionMain_1:
	waitmovement 0
	setvar VAR_ELM_LAB_STATE, 3
	releaseall
	return

NewBarkTown_ProfessorElmsLab_EventScript_AidePotionMain_3:
	applymovement 1, NewBarkTown_ProfessorElmsLab_Movement_AideFromLeftTrigger
	goto NewBarkTown_ProfessorElmsLab_EventScript_AidePotionMain_1

NewBarkTown_ProfessorElmsLab_EventScript_AidePotionMain_4:
	applymovement 1, NewBarkTown_ProfessorElmsLab_Movement_AideFromMiddleTrigger
	goto NewBarkTown_ProfessorElmsLab_EventScript_AidePotionMain_1

NewBarkTown_ProfessorElmsLab_EventScript_AidePotionMain_5:
	applymovement 1, NewBarkTown_ProfessorElmsLab_Movement_AideFromRightTrigger
	goto NewBarkTown_ProfessorElmsLab_EventScript_AidePotionMain_1


NewBarkTown_ProfessorElmsLab_Movement_AideFromLeftTrigger:
	walk_left
	walk_left
	step_end

NewBarkTown_ProfessorElmsLab_Movement_AideFromMiddleTrigger:
	walk_left
	walk_left
	walk_left
	step_end

NewBarkTown_ProfessorElmsLab_Movement_AideFromRightTrigger:
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

NewBarkTown_ProfessorElmsLab_EventScript_Officer1::
	lockall
	setvar VAR_TEMP_1, 0
	applymovement 3, NewBarkTown_ProfessorElmsLab_Movement_OfficerWaitFaceLeft
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_ProfessorElmsLab_Movement_PlayerToOfficerFromLeft
	goto NewBarkTown_ProfessorElmsLab_EventScript_OfficerMain
	return


NewBarkTown_ProfessorElmsLab_Movement_OfficerWaitFaceLeft:
	delay_16
	delay_16
	delay_16
	walk_in_place_fastest_left
	step_end

NewBarkTown_ProfessorElmsLab_Movement_PlayerToOfficerFromLeft:
	walk_up
	walk_up
	walk_up
	face_right
	step_end

NewBarkTown_ProfessorElmsLab_EventScript_Officer2::
	lockall
	setvar VAR_TEMP_1, 1
	applymovement 3, NewBarkTown_ProfessorElmsLab_Movement_OfficerWaitFaceLeftFromCenter
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_ProfessorElmsLab_Movement_PlayerToOfficerFromCenter
	goto NewBarkTown_ProfessorElmsLab_EventScript_OfficerMain
	return


NewBarkTown_ProfessorElmsLab_Movement_OfficerWaitFaceLeftFromCenter:
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_fastest_left
	step_end

NewBarkTown_ProfessorElmsLab_Movement_PlayerToOfficerFromCenter:
	walk_left
	walk_up
	walk_up
	walk_up
	face_right
	step_end

NewBarkTown_ProfessorElmsLab_EventScript_Officer3::
	lockall
	setvar VAR_TEMP_1, 2
	applymovement 3, NewBarkTown_ProfessorElmsLab_Movement_OfficerWaitFaceRight
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_ProfessorElmsLab_Movement_PlayerToOfficerFromRight
	goto NewBarkTown_ProfessorElmsLab_EventScript_OfficerMain
	return


NewBarkTown_ProfessorElmsLab_Movement_OfficerWaitFaceRight:
	delay_16
	delay_16
	delay_16
	walk_in_place_fastest_right
	step_end

NewBarkTown_ProfessorElmsLab_Movement_PlayerToOfficerFromRight:
	walk_up
	walk_up
	walk_up
	face_left
	step_end

NewBarkTown_ProfessorElmsLab_EventScript_OfficerMain::
	waitmovement 0
	textcolor MSG_COLOR_BLUE
	msgbox NewBarkTown_ProfessorElmsLab_EventScript_OfficerMain_Text_0
	goto NewBarkTown_ProfessorElmsLab_EventScript_Officer_NameRival
	return


NewBarkTown_ProfessorElmsLab_EventScript_Officer_NameRival::
	fadescreen FADE_TO_BLACK
	special SetRivalNickname
	waitstate
	msgbox NewBarkTown_ProfessorElmsLab_EventScript_Officer_NameRival_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq NewBarkTown_ProfessorElmsLab_EventScript_Officer_NameRival_2
NewBarkTown_ProfessorElmsLab_EventScript_Officer_NameRival_1:
	msgbox NewBarkTown_ProfessorElmsLab_EventScript_Officer_NameRival_Text_1
	closemessage
	applymovement 3, NewBarkTown_ProfessorElmsLab_Movement_OfficerLeaves
	waitmovement 0
	removeobject 3
	setvar VAR_ELM_LAB_STATE, 5
	releaseall
	return

NewBarkTown_ProfessorElmsLab_EventScript_Officer_NameRival_2:
	goto NewBarkTown_ProfessorElmsLab_EventScript_Officer_NameRival
	goto NewBarkTown_ProfessorElmsLab_EventScript_Officer_NameRival_1


NewBarkTown_ProfessorElmsLab_Movement_OfficerLeaves:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

NewBarkTown_ProfessorElmsLab_EventScript_AideBalls1::
	lockall
	setvar VAR_TEMP_1, 0
	applymovement 1, NewBarkTown_ProfessorElmsLab_Movement_AideToLeftTrigger
	goto NewBarkTown_ProfessorElmsLab_EventScript_AideBallsMain
	return


NewBarkTown_ProfessorElmsLab_EventScript_AideBalls2::
	lockall
	setvar VAR_TEMP_1, 1
	applymovement 1, NewBarkTown_ProfessorElmsLab_Movement_AideToMiddleTrigger
	goto NewBarkTown_ProfessorElmsLab_EventScript_AideBallsMain
	return


NewBarkTown_ProfessorElmsLab_EventScript_AideBalls3::
	lockall
	setvar VAR_TEMP_1, 2
	applymovement 1, NewBarkTown_ProfessorElmsLab_Movement_AideToRightTrigger
	goto NewBarkTown_ProfessorElmsLab_EventScript_AideBallsMain
	return


NewBarkTown_ProfessorElmsLab_EventScript_AideBallsMain::
	waitmovement 0
	textcolor MSG_COLOR_BLUE
	msgbox NewBarkTown_ProfessorElmsLab_EventScript_AideBallsMain_Text_0
	giveitem_msg NewBarkTown_ProfessorElmsLab_EventScript_AideBallsMain_Text_1, ITEM_POKE_BALL, 5
	msgbox NewBarkTown_ProfessorElmsLab_EventScript_AideBallsMain_Text_2
	closemessage
	switch VAR_TEMP_1
	case 0, NewBarkTown_ProfessorElmsLab_EventScript_AideBallsMain_3
	case 1, NewBarkTown_ProfessorElmsLab_EventScript_AideBallsMain_4
	case 2, NewBarkTown_ProfessorElmsLab_EventScript_AideBallsMain_5
NewBarkTown_ProfessorElmsLab_EventScript_AideBallsMain_1:
	waitmovement 0
	setvar VAR_ELM_LAB_STATE, 7
	releaseall
	return

NewBarkTown_ProfessorElmsLab_EventScript_AideBallsMain_3:
	applymovement 1, NewBarkTown_ProfessorElmsLab_Movement_AideFromLeftTrigger
	goto NewBarkTown_ProfessorElmsLab_EventScript_AideBallsMain_1

NewBarkTown_ProfessorElmsLab_EventScript_AideBallsMain_4:
	applymovement 1, NewBarkTown_ProfessorElmsLab_Movement_AideFromMiddleTrigger
	goto NewBarkTown_ProfessorElmsLab_EventScript_AideBallsMain_1

NewBarkTown_ProfessorElmsLab_EventScript_AideBallsMain_5:
	applymovement 1, NewBarkTown_ProfessorElmsLab_Movement_AideFromRightTrigger
	goto NewBarkTown_ProfessorElmsLab_EventScript_AideBallsMain_1


NewBarkTown_ProfessorElmsLab_EventScript_Aide::
	lock
	faceplayer
	goto_if_set FLAG_GOT_ELMS_EGG, NewBarkTown_ProfessorElmsLab_EventScript_Aide_2
	goto_if_set FLAG_GAVE_MYSTERY_EGG_TO_ELM, NewBarkTown_ProfessorElmsLab_EventScript_Aide_3
	goto_if_set FLAG_RECEIVED_MYSTERY_EGG, NewBarkTown_ProfessorElmsLab_EventScript_Aide_4
	msgbox NewBarkTown_ProfessorElmsLab_Text_Aide_AlwaysBusy
NewBarkTown_ProfessorElmsLab_EventScript_Aide_1:
	release
	return

NewBarkTown_ProfessorElmsLab_EventScript_Aide_2:
	msgbox NewBarkTown_ProfessorElmsLab_EventScript_Aide_Text_0
	goto NewBarkTown_ProfessorElmsLab_EventScript_Aide_1

NewBarkTown_ProfessorElmsLab_EventScript_Aide_3:
	msgbox NewBarkTown_ProfessorElmsLab_EventScript_AideBallsMain_Text_2
	goto NewBarkTown_ProfessorElmsLab_EventScript_Aide_1

NewBarkTown_ProfessorElmsLab_EventScript_Aide_4:
	msgbox NewBarkTown_ProfessorElmsLab_EventScript_Aide_Text_1
	goto NewBarkTown_ProfessorElmsLab_EventScript_Aide_1


NewBarkTown_ProfessorElmsLab_EventScript_OpenWindow::
	goto_if_set FLAG_VISITED_VIOLET_CITY, NewBarkTown_ProfessorElmsLab_EventScript_OpenWindow_1
	goto_if_unset FLAG_ELM_CALLED_ABOUT_STOLEN_MON, NewBarkTown_ProfessorElmsLab_EventScript_OpenWindow_1
	msgbox NewBarkTown_ProfessorElmsLab_EventScript_OpenWindow_Text_1, MSGBOX_SIGN
	return

NewBarkTown_ProfessorElmsLab_EventScript_OpenWindow_1:
	msgbox NewBarkTown_ProfessorElmsLab_EventScript_OpenWindow_Text_0, MSGBOX_SIGN
	return


NewBarkTown_ProfessorElmsLab_EventScript_HealingMachine::
	lockall
	goto_if_unset FLAG_SYS_POKEMON_GET, NewBarkTown_ProfessorElmsLab_EventScript_HealingMachine_2
	msgbox NewBarkTown_ProfessorElmsLab_EventScript_HealingMachine_Text_1, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq NewBarkTown_ProfessorElmsLab_EventScript_HealingMachine_5
NewBarkTown_ProfessorElmsLab_EventScript_HealingMachine_1:
	releaseall
	return

NewBarkTown_ProfessorElmsLab_EventScript_HealingMachine_2:
	msgbox NewBarkTown_ProfessorElmsLab_EventScript_HealingMachine_Text_0
	goto NewBarkTown_ProfessorElmsLab_EventScript_HealingMachine_1

NewBarkTown_ProfessorElmsLab_EventScript_HealingMachine_5:
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	goto NewBarkTown_ProfessorElmsLab_EventScript_HealingMachine_1


NewBarkTown_ProfessorElmsLab_EventScript_ElmsPC::
	msgbox NewBarkTown_ProfessorElmsLab_EventScript_ElmsPC_Text_0, MSGBOX_SIGN
	return


NewBarkTown_ProfessorElmsLab_EventScript_TrashCan::
	msgbox NewBarkTown_ProfessorElmsLab_EventScript_TrashCan_Text_0, MSGBOX_SIGN
	return


NewBarkTown_ProfessorElmsLab_EventScript_Shelf1::
	lockall
	msgbox NewBarkTown_ProfessorElmsLab_Text_ShelfIntro
	signmsg
	msgbox NewBarkTown_ProfessorElmsLab_EventScript_Shelf1_Text_0
	normalmsg
	releaseall
	return


NewBarkTown_ProfessorElmsLab_EventScript_Shelf2::
	lockall
	msgbox NewBarkTown_ProfessorElmsLab_Text_ShelfIntro
	signmsg
	msgbox NewBarkTown_ProfessorElmsLab_EventScript_Shelf2_Text_0
	normalmsg
	releaseall
	return


NewBarkTown_ProfessorElmsLab_EventScript_Shelf3::
	lockall
	msgbox NewBarkTown_ProfessorElmsLab_Text_ShelfIntro
	signmsg
	msgbox NewBarkTown_ProfessorElmsLab_EventScript_Shelf3_Text_0
	normalmsg
	releaseall
	return


NewBarkTown_ProfessorElmsLab_EventScript_Shelf4::
	lockall
	msgbox NewBarkTown_ProfessorElmsLab_Text_ShelfIntro
	signmsg
	msgbox NewBarkTown_ProfessorElmsLab_EventScript_Shelf4_Text_0
	normalmsg
	releaseall
	return


NewBarkTown_ProfessorElmsLab_EventScript_Elm_Text_0:
	.string "ELM: {PLAYER}, I'll call you if\n"
	.string "anything comes up.$"

NewBarkTown_ProfessorElmsLab_EventScript_Elm_Text_1:
	.string "ELM: {PLAYER}, you look great!$"

NewBarkTown_ProfessorElmsLab_EventScript_Elm_Text_2:
	.string "What? That POKéMON!?!\n"
	.string "The EGG hatched!\p"
	.string "So, POKéMON are born from EGGS…\n"
	.string "No, perhaps not all POKéMON are.\p"
	.string "Wow, there's still a lot of research\n"
	.string "to be done.\p$"

NewBarkTown_ProfessorElmsLab_EventScript_Elm_Text_3:
	.string "ELM: {PLAYER}?\n"
	.string "Didn't you meet my assistant?\p"
	.string "He should have met you with the EGG\n"
	.string "at VIOLET CITY's POKéMON CENTER.\p"
	.string "You must have just missed him.\n"
	.string "Try to catch him there.$"

NewBarkTown_ProfessorElmsLab_EventScript_Elm_Text_4:
	.string "ELM: Don't give up! I'll call if I\n"
	.string "learn anything about that EGG!$"

NewBarkTown_ProfessorElmsLab_EventScript_Elm_Text_5:
	.string "ELM: {PLAYER}, this is terrible…\p"
	.string "Oh, yes, what was MR. POKéMON's big\n"
	.string "discovery?$"

NewBarkTown_ProfessorElmsLab_EventScript_Elm_Text_6:
	.string "{PLAYER} handed the MYSTERY EGG to\n"
	.string "PROF. ELM.$"

NewBarkTown_ProfessorElmsLab_EventScript_Elm_Text_7:
	.string "But… Is it a POKéMON EGG?\n"
	.string "If it is, it's a great discovery!\p"
	.string "What?!?\n"
	.string "PROF. OAK gave you a POKéDEX?\p"
	.string "{PLAYER}, is that true?\n"
	.string "Th-that's incredible!\p"
	.string "He is superb at seeing the potential\n"
	.string "of people as TRAINERS.\p"
	.string "Wow, {PLAYER}. You may have what it\n"
	.string "takes to become the CHAMPION.\p"
	.string "You seem to be getting on great with\n"
	.string "POKéMON too.\p"
	.string "You should take the POKéMON GYM\n"
	.string "challenge.\p"
	.string "The closest GYM would be the one in\n"
	.string "VIOLET CITY.\p"
	.string "…{PLAYER}. The road to the\n"
	.string "championship will be a long one.\p"
	.string "Before you leave, make sure that\n"
	.string "you talk to your mom.$"

NewBarkTown_ProfessorElmsLab_EventScript_Elm_Text_8:
	.string "ELM: MR. POKéMON goes everywhere\n"
	.string "and finds rarities.\p"
	.string "Too bad they're just rare and\n"
	.string "not very useful…$"

NewBarkTown_ProfessorElmsLab_EventScript_Elm_Text_9:
	.string "ELM: If a wild POKéMON appears,\n"
	.string "let your POKéMON battle it!$"

NewBarkTown_ProfessorElmsLab_EventScript_Elm_NoHatchedEggMon_Text_0:
	.string "ELM: {PLAYER}?\n"
	.string "I thought the EGG hatched.\l"
	.string "Where is the POKéMON?$"

NewBarkTown_ProfessorElmsLab_EventScript_Elm_GiveEverstone_Text_0:
	.string "Thanks, {PLAYER}! You're helping\n"
	.string "unravel POKéMON mysteries for us!\p"
	.string "I want you to have this as a token\n"
	.string "of our appreciation.$"

NewBarkTown_ProfessorElmsLab_EventScript_Elm_GiveEverstone_Text_1:
	.string "Oh? You don't have any room\n"
	.string "for the EVERSTONE…$"

NewBarkTown_ProfessorElmsLab_EventScript_Elm_GiveEverstone_Text_2:
	.string "{PLAYER} received the EVERSTONE\n"
	.string "from PROF. ELM.$"

NewBarkTown_ProfessorElmsLab_EventScript_Elm_GiveEverstone_Text_3:
	.string "That's an EVERSTONE.\p"
	.string "Some species of POKéMON evolve\n"
	.string "when they grow to certain levels.\p"
	.string "A POKéMON holding the EVERSTONE\n"
	.string "won't evolve.\p"
	.string "Give it to a POKéMON you don't want\n"
	.string "to evolve.$"

NewBarkTown_ProfessorElmsLab_EventScript_ElmIntroduction_Text_0:
	.string "ELM: {PLAYER}!\n"
	.string "There you are!\l"
	.string "I needed to ask you a favor.\p"
	.string "I'm conducting POKéMON research\n"
	.string "right now, and I was wondering if\l"
	.string "you could help me with it, {PLAYER}.\p"
	.string "You see…\p"
	.string "I'm writing a paper that I want to\n"
	.string "present at a conference.\p"
	.string "But there are some things I don't\n"
	.string "quite understand yet.\p"
	.string "So! I'd like you to raise a POKéMON\n"
	.string "that I recently caught.$"

NewBarkTown_ProfessorElmsLab_EventScript_ElmBeggingLoop_Text_0:
	.string "But…\n"
	.string "Please, I need your help!$"

NewBarkTown_ProfessorElmsLab_EventScript_ElmPostBegging_Text_0:
	.string "Thanks, {PLAYER}!\n"
	.string "You're a great help!\p"
	.string "When I announce my findings, I'm\n"
	.string "sure we'll delve a bit deeper into\l"
	.string "the many mysteries of POKéMON.\p"
	.string "You can count on it!$"

NewBarkTown_ProfessorElmsLab_EventScript_ElmPostBegging_Text_1:
	.string "Oh, hey!\n"
	.string "I got an e-mail!\p"
	.string "………………\n"
	.string "Hm… Uh-huh…\l"
	.string "Okay…$"

NewBarkTown_ProfessorElmsLab_EventScript_ElmPostBegging_Text_2:
	.string "Hey, listen.\p"
	.string "I have an acquaintance called\n"
	.string "MR. POKéMON.\p"
	.string "He keeps finding weird things and\n"
	.string "raving about his discoveries.\p"
	.string "Anyway, I just got an e-mail from\n"
	.string "him saying that this time it's real.\p"
	.string "It is intriguing, but we're busy with\n"
	.string "our POKéMON research…\p"
	.string "Wait!\n"
	.string "I know!\p"
	.string "{PLAYER}, can you go in our place?$"

NewBarkTown_ProfessorElmsLab_EventScript_ElmPostBegging_Text_3:
	.string "I want you to raise one of the\n"
	.string "POKéMON contained in these\l"
	.string "POKé BALLS.\p"
	.string "You'll be that POKéMON's first\n"
	.string "partner, {PLAYER}!\p"
	.string "Go on, then.\n"
	.string "Pick one!$"

NewBarkTown_ProfessorElmsLab_EventScript_ElmWaitDontGo_Text_0:
	.string "ELM: Wait!\n"
	.string "Where are you going?$"

NewBarkTown_EventScript_PokeBallMain_Text_0:
	.string "It contains a POKéMON caught by\n"
	.string "PROF. ELM.$"

NewBarkTown_EventScript_PokeBallMain_Text_1:
	.string "ELM: Hm! CHIKORITA is your choice.\n"
	.string "Take your time raising it.\p"
	.string "So, {PLAYER}, do you like CHIKORITA,\n"
	.string "the GRASS POKéMON?$"

NewBarkTown_EventScript_PokeBallMain_Text_2:
	.string "ELM: Ah! TOTODILE is your choice.\n"
	.string "It would be rewarding to raise.\p"
	.string "So, {PLAYER}, do you want TOTODILE,\n"
	.string "the WATER POKéMON?$"

NewBarkTown_EventScript_PokeBallMain_Text_3:
	.string "ELM: Oh! CYNDAQUIL is your choice.\n"
	.string "Raising it would be a cinch.\p"
	.string "So, {PLAYER}, you'll take CYNDAQUIL,\n"
	.string "the FIRE POKéMON?$"

NewBarkTown_EventScript_PokeBallMain_Text_4:
	.string "ELM: Think it over carefully.\n"
	.string "Your partner is important.$"

NewBarkTown_EventScript_PokeBallMain_Text_5:
	.string "ELM: I think that's a great\n"
	.string "POKéMON too!$"

NewBarkTown_EventScript_PokeBallMain_Text_6:
	.string "{PLAYER} received the {STR_VAR_1}\n"
	.string "from PROF. ELM!$"

NewBarkTown_EventScript_PokeBallMain_Text_7:
	.string "MR. POKéMON lives a bit beyond\n"
	.string "CHERRYGROVE, the next city over.\p"
	.string "It's almost a direct route there,\n"
	.string "so you can't miss it.\p"
	.string "But just in case, here's my number.\n"
	.string "Call me if anything comes up!$"

NewBarkTown_EventScript_PokeBallMain_Text_8:
	.string "{PLAYER} got PROF. ELM's phone\n"
	.string "number.$"

NewBarkTown_EventScript_PokeBallMain_Text_9:
	.string "If your POKéMON is hurt, you should\n"
	.string "heal it with this machine.\l"
	.string "Feel free to use it anytime.$"

NewBarkTown_EventScript_PokeBallMain_Text_10:
	.string "{PLAYER}, I'm counting on you!$"

NewBarkTown_ProfessorElmsLab_EventScript_AidePotionMain_Text_0:
	.string "{PLAYER}, I want you to have this\n"
	.string "for your errand.$"

NewBarkTown_ProfessorElmsLab_EventScript_AidePotionMain_Text_1:
	.string "{PLAYER} received the POTION\n"
	.string "from the AIDE.$"

NewBarkTown_ProfessorElmsLab_EventScript_OfficerMain_Text_0:
	.string "I heard a POKéMON was stolen from\n"
	.string "here…\p"
	.string "I was just getting some information\n"
	.string "from PROF. ELM.\p"
	.string "Apparently, it was a young male with\n"
	.string "long, red hair…\p"
	.string "What? You're saying you battled a\n"
	.string "TRAINER like that?\p"
	.string "Did you happen to get his name?$"

NewBarkTown_ProfessorElmsLab_EventScript_Officer_NameRival_Text_0:
	.string "Let me make sure I got that right…\n"
	.string "So his name is {RIVAL}?$"

NewBarkTown_ProfessorElmsLab_EventScript_Officer_NameRival_Text_1:
	.string "Okay! So {RIVAL} was his name.\n"
	.string "Thanks for helping my investigation!$"

NewBarkTown_ProfessorElmsLab_EventScript_AideBallsMain_Text_0:
	.string "{PLAYER}!\n"
	.string "Use these on your POKéDEX quest!$"

NewBarkTown_ProfessorElmsLab_EventScript_AideBallsMain_Text_1:
	.string "{PLAYER} received the POKé BALLS\n"
	.string "from the AIDE.$"

NewBarkTown_ProfessorElmsLab_EventScript_AideBallsMain_Text_2:
	.string "To add to your POKéDEX, you have\n"
	.string "to catch POKéMON.\p"
	.string "Throw POKé BALLS at wild POKéMON\n"
	.string "to get them.$"

NewBarkTown_ProfessorElmsLab_EventScript_Aide_Text_0:
	.string "…sigh… That stolen POKéMON.\n"
	.string "I wonder how it's doing.\p"
	.string "They say a POKéMON raised by a bad\n"
	.string "person turns bad itself.$"

NewBarkTown_ProfessorElmsLab_EventScript_Aide_Text_1:
	.string "There was a loud noise outside…\p"
	.string "When we went to look, someone stole\n"
	.string "a POKéMON off the table.\p"
	.string "It's unbelievable that anyone would\n"
	.string "do that!\p"
	.string "…sigh… That stolen POKéMON.\n"
	.string "I wonder how it's doing.\p"
	.string "They say a POKéMON raised by a bad\n"
	.string "person turns bad itself.$"

NewBarkTown_ProfessorElmsLab_EventScript_OpenWindow_Text_0:
	.string "The window is open.\n"
	.string "A pleasant breeze is blowing in.$"

NewBarkTown_ProfessorElmsLab_EventScript_OpenWindow_Text_1:
	.string "He must've broken in through here!$"

NewBarkTown_ProfessorElmsLab_EventScript_HealingMachine_Text_0:
	.string "Wonder what this machine does?$"

NewBarkTown_ProfessorElmsLab_EventScript_HealingMachine_Text_1:
	.string "Would you like to heal your POKéMON?$"

NewBarkTown_ProfessorElmsLab_EventScript_ElmsPC_Text_0:
	.string "“OBSERVATIONS ON POKéMON\n"
	.string "EVOLUTION”, it says on the screen…$"

NewBarkTown_ProfessorElmsLab_EventScript_TrashCan_Text_0:
	.string "The wrapper from the snack PROF.\n"
	.string "ELM ate is in there…$"

NewBarkTown_ProfessorElmsLab_EventScript_Shelf1_Text_0:
	.string "Travel Tip 1:\n"
	.string "Press START to open the MENU.$"

NewBarkTown_ProfessorElmsLab_EventScript_Shelf2_Text_0:
	.string "Travel Tip 2:\n"
	.string "Record your trip with SAVE!$"

NewBarkTown_ProfessorElmsLab_EventScript_Shelf3_Text_0:
	.string "Travel Tip 3:\n"
	.string "Open your BAG and press SELECT\l"
	.string "to move items.$"

NewBarkTown_ProfessorElmsLab_EventScript_Shelf4_Text_0:
	.string "Travel Tip 4:\n"
	.string "Check your POKéMON moves.\l"
	.string "Press the A Button to switch moves.$"

NewBarkTown_ProfessorElmsLab_Text_ElmThis::
	.string "ELM: This?$"

NewBarkTown_ProfessorElmsLab_Text_Elm_HasThatEggHatched::
	.string "ELM: Hey, has that EGG changed any?$"

NewBarkTown_ProfessorElmsLab_Text_Aide_AlwaysBusy::
	.string "There are only two of us, so we're\n"
	.string "always busy.$"

NewBarkTown_ProfessorElmsLab_Text_ShelfIntro::
	.string "{PLAYER} opened a book.$"
