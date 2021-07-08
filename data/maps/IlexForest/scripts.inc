IlexForest_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, IlexForest_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

IlexForest_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	setflag FLAG_LANDMARK_ILEX_FOREST
	switch VAR_ILEX_FARFETCHD_STATE
	case 2, IlexForest_MapScripts_MAP_SCRIPT_ON_TRANSITION_3
	case 3, IlexForest_MapScripts_MAP_SCRIPT_ON_TRANSITION_4
	case 4, IlexForest_MapScripts_MAP_SCRIPT_ON_TRANSITION_5
	case 5, IlexForest_MapScripts_MAP_SCRIPT_ON_TRANSITION_6
	case 6, IlexForest_MapScripts_MAP_SCRIPT_ON_TRANSITION_7
	case 7, IlexForest_MapScripts_MAP_SCRIPT_ON_TRANSITION_8
	case 8, IlexForest_MapScripts_MAP_SCRIPT_ON_TRANSITION_9
	case 9, IlexForest_MapScripts_MAP_SCRIPT_ON_TRANSITION_10
	case 10, IlexForest_MapScripts_MAP_SCRIPT_ON_TRANSITION_11
	setobjectxyperm 1, 27, 41
	return

IlexForest_MapScripts_MAP_SCRIPT_ON_TRANSITION_3:
	setobjectxyperm 1, 28, 35
	return

IlexForest_MapScripts_MAP_SCRIPT_ON_TRANSITION_4:
	setobjectxyperm 1, 38, 34
	return

IlexForest_MapScripts_MAP_SCRIPT_ON_TRANSITION_5:
	setobjectxyperm 1, 50, 31
	return

IlexForest_MapScripts_MAP_SCRIPT_ON_TRANSITION_6:
	setobjectxyperm 1, 47, 41
	return

IlexForest_MapScripts_MAP_SCRIPT_ON_TRANSITION_7:
	setobjectxyperm 1, 41, 45
	return

IlexForest_MapScripts_MAP_SCRIPT_ON_TRANSITION_8:
	setobjectxyperm 1, 39, 41
	return

IlexForest_MapScripts_MAP_SCRIPT_ON_TRANSITION_9:
	setobjectxyperm 1, 28, 39
	return

IlexForest_MapScripts_MAP_SCRIPT_ON_TRANSITION_10:
	setobjectxyperm 1, 21, 46
	return

IlexForest_MapScripts_MAP_SCRIPT_ON_TRANSITION_11:
	setobjectxyperm 1, 14, 37
	return


IlexForest_EventScript_Farfetchd::
	lock
	faceplayer
	switch VAR_ILEX_FARFETCHD_STATE
	case 2, IlexForest_EventScript_Farfetchd_4
	case 3, IlexForest_EventScript_Farfetchd_5
	case 4, IlexForest_EventScript_Farfetchd_6
	case 5, IlexForest_EventScript_Farfetchd_7
	case 6, IlexForest_EventScript_Farfetchd_8
	case 7, IlexForest_EventScript_Farfetchd_9
	case 8, IlexForest_EventScript_Farfetchd_10
	case 9, IlexForest_EventScript_Farfetchd_11
	case 10, IlexForest_EventScript_Farfetchd_12
	msgbox IlexForest_EventScript_Farfetchd_Text_0
	call IlexForest_EventScript_FarfetchdCry
	applymovement 1, IlexForest_Movement_Farfetchd_1to2
	waitmovement 0
	setobjectxy 1, 28, 35
	setobjectxyperm 1, 28, 35
	setvar VAR_ILEX_FARFETCHD_STATE, 2
IlexForest_EventScript_Farfetchd_1:
	release
	return

IlexForest_EventScript_Farfetchd_4:
	call IlexForest_EventScript_FarfetchdCry
	compare VAR_FACING, DIR_SOUTH
	goto_if_eq IlexForest_EventScript_Farfetchd_13
	applymovement 1, IlexForest_Movement_Farfetchd_2to3
	waitmovement 0
	setobjectxy 1, 38, 34
	setobjectxyperm 1, 38, 34
	setvar VAR_ILEX_FARFETCHD_STATE, 3
	goto IlexForest_EventScript_Farfetchd_1

IlexForest_EventScript_Farfetchd_5:
	call IlexForest_EventScript_FarfetchdCry
	compare VAR_FACING, DIR_WEST
	goto_if_eq IlexForest_EventScript_Farfetchd_16
	applymovement 1, IlexForest_Movement_Farfetchd_3to4
	waitmovement 0
	setobjectxy 1, 50, 31
	setobjectxyperm 1, 50, 31
	setvar VAR_ILEX_FARFETCHD_STATE, 4
	goto IlexForest_EventScript_Farfetchd_1

IlexForest_EventScript_Farfetchd_6:
	call IlexForest_EventScript_FarfetchdCry
	compare VAR_FACING, DIR_NORTH
	goto_if_eq IlexForest_EventScript_Farfetchd_19
	applymovement 1, IlexForest_Movement_Farfetchd_4to5
	waitmovement 0
	setobjectxy 1, 47, 41
	setobjectxyperm 1, 47, 41
	setvar VAR_ILEX_FARFETCHD_STATE, 5
	goto IlexForest_EventScript_Farfetchd_1

IlexForest_EventScript_Farfetchd_7:
	call IlexForest_EventScript_FarfetchdCry
	switch VAR_FACING
	case DIR_NORTH, IlexForest_EventScript_Farfetchd_24
	case DIR_WEST, IlexForest_EventScript_Farfetchd_25
	case DIR_EAST, IlexForest_EventScript_Farfetchd_26
	applymovement 1, IlexForest_Movement_Farfetchd_5to6
	waitmovement 0
	setobjectxy 1, 41, 45
	setobjectxyperm 1, 41, 45
	setvar VAR_ILEX_FARFETCHD_STATE, 6
	goto IlexForest_EventScript_Farfetchd_1

IlexForest_EventScript_Farfetchd_8:
	call IlexForest_EventScript_FarfetchdCry
	compare VAR_FACING, DIR_EAST
	goto_if_eq IlexForest_EventScript_Farfetchd_27
	applymovement 1, IlexForest_Movement_Farfetchd_6to7
	waitmovement 0
	setobjectxy 1, 39, 41
	setobjectxyperm 1, 39, 41
	setvar VAR_ILEX_FARFETCHD_STATE, 7
	goto IlexForest_EventScript_Farfetchd_1

IlexForest_EventScript_Farfetchd_9:
	call IlexForest_EventScript_FarfetchdCry
	switch VAR_FACING
	case DIR_SOUTH, IlexForest_EventScript_Farfetchd_32
	case DIR_WEST, IlexForest_EventScript_Farfetchd_33
	applymovement 1, IlexForest_Movement_Farfetchd_7to8
	waitmovement 0
	setobjectxy 1, 28, 39
	setobjectxyperm 1, 28, 39
	setvar VAR_ILEX_FARFETCHD_STATE, 8
	goto IlexForest_EventScript_Farfetchd_1

IlexForest_EventScript_Farfetchd_10:
	call IlexForest_EventScript_FarfetchdCry
	switch VAR_FACING
	case DIR_NORTH, IlexForest_EventScript_Farfetchd_36
	case DIR_WEST, IlexForest_EventScript_Farfetchd_36
	case DIR_EAST, IlexForest_EventScript_Farfetchd_37
	applymovement 1, IlexForest_Movement_Farfetchd_8to9
	waitmovement 0
	setobjectxy 1, 21, 46
	setobjectxyperm 1, 21, 46
	setvar VAR_ILEX_FARFETCHD_STATE, 9
	goto IlexForest_EventScript_Farfetchd_1

IlexForest_EventScript_Farfetchd_11:
	call IlexForest_EventScript_FarfetchdCry
	switch VAR_FACING
	case DIR_SOUTH, IlexForest_EventScript_Farfetchd_40
	case DIR_NORTH, IlexForest_EventScript_Farfetchd_40
	case DIR_EAST, IlexForest_EventScript_Farfetchd_41
	applymovement 1, IlexForest_Movement_Farfetchd_9to10
	delay 18
	playse SE_WALL_HIT
	waitmovement 0
	setobjectxy 1, 14, 37
	setobjectxyperm 1, 14, 37
	setvar VAR_ILEX_FARFETCHD_STATE, 10
	addobject 3
	clearflag FLAG_HIDE_ILEX_FOREST_MASTER
	setflag FLAG_HIDE_AZALEA_TOWN_CHARCOAL_KILN_MASTER
	setflag FLAG_FETCHED_FARFETCHD
	goto IlexForest_EventScript_Farfetchd_1

IlexForest_EventScript_Farfetchd_12:
	call IlexForest_EventScript_FarfetchdCry
	goto IlexForest_EventScript_Farfetchd_1

IlexForest_EventScript_Farfetchd_13:
	applymovement 1, IlexForest_Movement_Farfetchd_2to8
	waitmovement 0
	setobjectxy 1, 28, 39
	setobjectxyperm 1, 28, 39
	setvar VAR_ILEX_FARFETCHD_STATE, 8
	goto IlexForest_EventScript_Farfetchd_1

IlexForest_EventScript_Farfetchd_16:
	applymovement 1, IlexForest_Movement_Farfetchd_3to2
	waitmovement 0
	setobjectxy 1, 28, 35
	setobjectxyperm 1, 28, 35
	setvar VAR_ILEX_FARFETCHD_STATE, 2
	goto IlexForest_EventScript_Farfetchd_1

IlexForest_EventScript_Farfetchd_19:
	applymovement 1, IlexForest_Movement_Farfetchd_4to3
	delay 4
	playse SE_LEDGE
	waitmovement 0
	setobjectxy 1, 38, 34
	setobjectxyperm 1, 38, 34
	setvar VAR_ILEX_FARFETCHD_STATE, 3
	goto IlexForest_EventScript_Farfetchd_1

IlexForest_EventScript_Farfetchd_24:
	applymovement 1, IlexForest_Movement_Farfetchd_5to4North
	waitmovement 0
	setobjectxy 1, 50, 31
	setobjectxyperm 1, 50, 31
	setvar VAR_ILEX_FARFETCHD_STATE, 4
	goto IlexForest_EventScript_Farfetchd_1

IlexForest_EventScript_Farfetchd_25:
	applymovement 1, IlexForest_Movement_Farfetchd_5to7
	waitmovement 0
	setobjectxy 1, 39, 41
	setobjectxyperm 1, 39, 41
	setvar VAR_ILEX_FARFETCHD_STATE, 7
	goto IlexForest_EventScript_Farfetchd_1

IlexForest_EventScript_Farfetchd_26:
	applymovement 1, IlexForest_Movement_Farfetchd_5to4East
	delay 60
	playse SE_WALL_HIT
	waitmovement 0
	setobjectxy 1, 50, 31
	setobjectxyperm 1, 50, 31
	setvar VAR_ILEX_FARFETCHD_STATE, 4
	goto IlexForest_EventScript_Farfetchd_1

IlexForest_EventScript_Farfetchd_27:
	applymovement 1, IlexForest_Movement_Farfetchd_6to5
	waitmovement 0
	setobjectxy 1, 47, 41
	setobjectxyperm 1, 47, 41
	setvar VAR_ILEX_FARFETCHD_STATE, 5
	goto IlexForest_EventScript_Farfetchd_1

IlexForest_EventScript_Farfetchd_32:
	applymovement 1, IlexForest_Movement_Farfetchd_7to5
	waitmovement 0
	setobjectxy 1, 47, 41
	setobjectxyperm 1, 47, 41
	setvar VAR_ILEX_FARFETCHD_STATE, 5
	goto IlexForest_EventScript_Farfetchd_1

IlexForest_EventScript_Farfetchd_33:
	applymovement 1, IlexForest_Movement_Farfetchd_7to6
	waitmovement 0
	setobjectxy 1, 41, 45
	setobjectxyperm 1, 41, 45
	setvar VAR_ILEX_FARFETCHD_STATE, 6
	goto IlexForest_EventScript_Farfetchd_1

IlexForest_EventScript_Farfetchd_36:
	applymovement 1, IlexForest_Movement_Farfetchd_8to2
	waitmovement 0
	setobjectxy 1, 28, 35
	setobjectxyperm 1, 28, 35
	setvar VAR_ILEX_FARFETCHD_STATE, 2
	goto IlexForest_EventScript_Farfetchd_1

IlexForest_EventScript_Farfetchd_37:
	applymovement 1, IlexForest_Movement_Farfetchd_8to7
	waitmovement 0
	setobjectxy 1, 39, 41
	setobjectxyperm 1, 39, 41
	setvar VAR_ILEX_FARFETCHD_STATE, 7
	goto IlexForest_EventScript_Farfetchd_1

IlexForest_EventScript_Farfetchd_40:
	applymovement 1, IlexForest_Movement_Farfetchd_9to8NorthSouth
	delay 18
	playse SE_WALL_HIT
	waitmovement 0
	setobjectxy 1, 28, 39
	setobjectxyperm 1, 28, 39
	setvar VAR_ILEX_FARFETCHD_STATE, 8
	goto IlexForest_EventScript_Farfetchd_1

IlexForest_EventScript_Farfetchd_41:
	applymovement 1, IlexForest_Movement_Farfetchd_9to8East
	waitmovement 0
	setobjectxy 1, 28, 39
	setobjectxyperm 1, 28, 39
	setvar VAR_ILEX_FARFETCHD_STATE, 8
	goto IlexForest_EventScript_Farfetchd_1


IlexForest_EventScript_FarfetchdCry::
	waitse
	playmoncry SPECIES_FARFETCHD, 0
	msgbox IlexForest_EventScript_FarfetchdCry_Text_0
	waitmoncry
	closemessage
	return


IlexForest_Movement_Farfetchd_1to2:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

IlexForest_Movement_Farfetchd_2to3:
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

IlexForest_Movement_Farfetchd_2to8:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

IlexForest_Movement_Farfetchd_3to4:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

IlexForest_Movement_Farfetchd_3to2:
	walk_fast_up
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

IlexForest_Movement_Farfetchd_4to5:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

IlexForest_Movement_Farfetchd_4to3:
	walk_fast_left
	jump_2_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

IlexForest_Movement_Farfetchd_5to6:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

IlexForest_Movement_Farfetchd_5to4North:
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

IlexForest_Movement_Farfetchd_5to7:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

IlexForest_Movement_Farfetchd_5to4East:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_in_place_fastest_up
	delay_4
	walk_in_place_fastest_down
	delay_4
	walk_in_place_fastest_up
	delay_4
	walk_fast_down
	walk_fast_down
	lock_facing_direction
	jump_2_up
	delay_16
	unlock_facing_direction
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

IlexForest_Movement_Farfetchd_6to7:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_up
	walk_fast_up
	step_end

IlexForest_Movement_Farfetchd_6to5:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

IlexForest_Movement_Farfetchd_7to8:
	walk_fast_up
	walk_fast_up
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

IlexForest_Movement_Farfetchd_7to5:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

IlexForest_Movement_Farfetchd_7to6:
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_down
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

IlexForest_Movement_Farfetchd_8to9:
	walk_fast_down
	walk_fast_left
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

IlexForest_Movement_Farfetchd_8to2:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

IlexForest_Movement_Farfetchd_8to7:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

IlexForest_Movement_Farfetchd_9to10:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	lock_facing_direction
	jump_2_right
	delay_16
	unlock_facing_direction
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

IlexForest_Movement_Farfetchd_9to8NorthSouth:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	lock_facing_direction
	jump_2_right
	delay_16
	unlock_facing_direction
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

IlexForest_Movement_Farfetchd_9to8East:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

IlexForest_EventScript_Apprentice::
	lock
	faceplayer
	goto_if_set FLAG_FETCHED_FARFETCHD, IlexForest_EventScript_Apprentice_2
	msgbox IlexForest_EventScript_Apprentice_Text_1
IlexForest_EventScript_Apprentice_1:
	release
	return

IlexForest_EventScript_Apprentice_2:
	msgbox IlexForest_EventScript_Apprentice_Text_0
	goto IlexForest_EventScript_Apprentice_1


IlexForest_EventScript_Master::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM01, IlexForest_EventScript_Master_2
	msgbox IlexForest_EventScript_Master_Text_1
	giveitem ITEM_HM01
	setflag FLAG_RECEIVED_HM01
	msgbox IlexForest_EventScript_Master_Text_2
	setflag FLAG_HIDE_ILEX_FOREST_MASTER
	setflag FLAG_HIDE_ILEX_FOREST_APPRENTICE_FARFETCHD
	clearflag FLAG_HIDE_AZALEA_TOWN_CHARCOAL_KILN_MASTER
	clearflag FLAG_HIDE_AZALEA_TOWN_CHARCOAL_KILN_APPRENTICE_FARFETCHD
IlexForest_EventScript_Master_1:
	release
	return

IlexForest_EventScript_Master_2:
	msgbox IlexForest_EventScript_Master_Text_0
	goto IlexForest_EventScript_Master_1


IlexForest_EventScript_Wayne::
	trainerbattle_single TRAINER_WAYNE, IlexForest_Text_WayneIntro, IlexForest_Text_WayneDefeat
	msgbox IlexForest_Text_WaynePostBattle
	release
	return


IlexForest_EventScript_Lass::
	msgbox IlexForest_EventScript_Lass_Text_0, MSGBOX_NPC
	return


IlexForest_EventScript_DroppedItemsSign::
	msgbox IlexForest_EventScript_DroppedItemsSign_Text_0, MSGBOX_SIGN
	return


IlexForest_EventScript_Shrine::
	msgbox IlexForest_EventScript_Shrine_Text_0, MSGBOX_SIGN
	return


IlexForest_EventScript_Farfetchd_Text_0:
	.string "It's the missing POKéMON!$"

IlexForest_EventScript_FarfetchdCry_Text_0:
	.string "FARFETCH'D: Kwaa!$"

IlexForest_EventScript_Apprentice_Text_0:
	.string "Wow!\n"
	.string "Thanks a whole bunch!\p"
	.string "My boss's POKéMON won't obey me\n"
	.string "because I don't have a BADGE.$"

IlexForest_EventScript_Apprentice_Text_1:
	.string "Oh, man…\n"
	.string "My boss is going to be steaming…\p"
	.string "The FARFETCH'D that CUTS trees\n"
	.string "for CHARCOAL took off on me.\p"
	.string "I can't go looking for it here in\n"
	.string "the ILEX FOREST.\p"
	.string "It's too big, dark, and scary for\n"
	.string "me to go any further…$"

IlexForest_EventScript_Master_Text_0:
	.string "Do you want to apprentice as a\n"
	.string "CHARCOAL maker with me?\p"
	.string "You'll be first-rate in ten years!$"

IlexForest_EventScript_Master_Text_1:
	.string "Ah! My FARFETCH'D!\n"
	.string "You found it for us, kid?\p"
	.string "Without it, we wouldn't be able\n"
	.string "to CUT trees for CHARCOAL.\p"
	.string "Thanks, kid!\n"
	.string "Now, how can I thank you…\p"
	.string "I know!\n"
	.string "Here, take this.$"

IlexForest_EventScript_Master_Text_2:
	.string "That's the CUT HM. Teach that to a\n"
	.string "POKéMON to clear small trees.\p"
	.string "Of course, you have to have the\n"
	.string "GYM BADGE from AZALEA to use it.$"

IlexForest_EventScript_Lass_Text_0:
	.string "Did something happen to the\n"
	.string "forest's guardian?$"

IlexForest_EventScript_DroppedItemsSign_Text_0:
	.string "ILEX FOREST is so overgrown with\n"
	.string "trees that you can't see the sky.\p"
	.string "Please watch out for items that may\n"
	.string "have been dropped.$"

IlexForest_EventScript_Shrine_Text_0:
	.string "ILEX FOREST SHRINE…\p"
	.string "It's in honor of the forest's\n"
	.string "protector…$"
