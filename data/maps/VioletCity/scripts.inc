VioletCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VioletCity_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_FRAME_TABLE, VioletCity_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

VioletCity_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	setflag FLAG_VISITED_VIOLET_CITY
	compare VAR_VIOLET_CITY_STATE, 1
	goto_if_eq VioletCity_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	return

VioletCity_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
	setflag FLAG_HIDE_MAP_NAME_POPUP
	return

VioletCity_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_VIOLET_CITY_STATE, 1, VioletCity_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0
	.2byte 0

VioletCity_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0:
	lockall
	pokegearcall VioletCity_PhoneScript_ElmCall, 1
	waitstate
	setflag FLAG_ELM_CALLED_ABOUT_ASSISTANT_IN_VIOLET
	setflag FLAG_HIDE_NEW_BARK_TOWN_ELMS_LAB_AIDE
	clearflag FLAG_HIDE_VIOLET_CITY_POKEMON_CENTER_1F_ELMS_AIDE
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	setvar VAR_VIOLET_CITY_STATE, 2
	releaseall
	return


VioletCity_Earl::
	lockall
	applymovement 1, VioletCity_Movement_EarlSpin
	waitmovement 0
	faceplayer
	msgbox VioletCity_Earl_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq VioletCity_Earl_1
	msgbox VioletCity_Earl_Text_2
	closemessage
	playbgm MUS_FOLLOWME, 0
	switch VAR_FACING
	case DIR_SOUTH, VioletCity_Earl_6
	case DIR_NORTH, VioletCity_Earl_7
	case DIR_WEST, VioletCity_Earl_8
	case DIR_EAST, VioletCity_Earl_9
VioletCity_Earl_4:
	applymovement 1, VioletCity_Movement_EarlSpin
	waitmovement 0
	fadedefaultbgm
	msgbox VioletCity_Earl_Text_3
	closemessage
	applymovement 1, VioletCity_Movement_EarlSpin
	waitmovement 0
	applymovement 1, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	opendoor 37, 19
	waitdooranim
	applymovement 1, VioletCity_Movement_EarlIntoDoor
	waitmovement 0
	removeobject 1
	closedoor 37, 19
	waitdooranim
	clearflag FLAG_HIDE_VIOLET_CITY_ACADEMY_EARL
	releaseall
	return

VioletCity_Earl_1:
	msgbox VioletCity_Earl_Text_1
	releaseall
	return

VioletCity_Earl_6:
	applymovement 1, VioletCity_Movement_EarlToAcademy
	applymovement EVENT_OBJ_ID_PLAYER, VioletCity_Movement_PlayerToAcademySouth
	waitmovement 0
	goto VioletCity_Earl_4

VioletCity_Earl_7:
	applymovement 1, VioletCity_Movement_EarlToAcademy
	applymovement EVENT_OBJ_ID_PLAYER, VioletCity_Movement_PlayerToAcademyNorth
	waitmovement 0
	goto VioletCity_Earl_4

VioletCity_Earl_8:
	applymovement 1, VioletCity_Movement_EarlToAcademy
	applymovement EVENT_OBJ_ID_PLAYER, VioletCity_Movement_PlayerToAcademyWest
	waitmovement 0
	goto VioletCity_Earl_4

VioletCity_Earl_9:
	applymovement 1, VioletCity_Movement_EarlToAcademy
	applymovement EVENT_OBJ_ID_PLAYER, VioletCity_Movement_PlayerToAcademyEast
	waitmovement 0
	goto VioletCity_Earl_4


VioletCity_Movement_EarlSpin:
	face_down
	delay_1
	face_left
	delay_1
	face_up
	delay_1
	face_right
	delay_1
	face_down
	delay_1
	face_left
	delay_1
	face_up
	delay_1
	face_right
	delay_1
	face_down
	delay_1
	face_left
	delay_1
	face_up
	delay_1
	face_right
	delay_1
	face_down
	step_end

VioletCity_Movement_EarlToAcademy:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	face_down
	delay_1
	face_left
	delay_1
	face_up
	delay_1
	face_right
	delay_1
	face_down
	delay_1
	face_left
	delay_1
	face_up
	delay_1
	face_right
	delay_1
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	face_down
	delay_1
	face_left
	delay_1
	face_up
	delay_1
	face_right
	delay_1
	face_down
	delay_1
	face_left
	delay_1
	face_up
	delay_1
	face_right
	delay_1
	walk_fast_down
	face_down
	delay_1
	face_left
	delay_1
	face_up
	delay_1
	face_right
	delay_1
	face_down
	delay_1
	face_left
	delay_1
	face_up
	delay_1
	face_right
	delay_1
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	face_down
	delay_1
	face_left
	delay_1
	face_up
	delay_1
	face_right
	delay_1
	face_down
	delay_1
	face_left
	delay_1
	face_up
	delay_1
	face_right
	delay_1
	walk_fast_up
	walk_fast_up
	step_end

VioletCity_Movement_PlayerToAcademySouth:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	delay_16
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	delay_16
	walk_fast_right
	face_down
	delay_16
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	delay_16
	walk_fast_right
	walk_fast_up
	step_end

VioletCity_Movement_PlayerToAcademyNorth:
	walk_fast_left
	walk_fast_right
	walk_fast_down
	delay_16
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	delay_16
	walk_fast_right
	face_down
	delay_16
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	delay_16
	walk_fast_right
	walk_fast_up
	step_end

VioletCity_Movement_PlayerToAcademyWest:
	walk_fast_left
	walk_fast_down
	walk_fast_down
	delay_16
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	delay_16
	walk_fast_right
	face_down
	delay_16
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	delay_16
	walk_fast_right
	walk_fast_up
	step_end

VioletCity_Movement_PlayerToAcademyEast:
	walk_fast_right
	walk_fast_down
	walk_fast_down
	delay_16
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	delay_16
	walk_fast_right
	face_down
	delay_16
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	delay_16
	walk_fast_right
	walk_fast_up
	step_end

VioletCity_Movement_EarlIntoDoor:
	walk_up
	set_invisible
	step_end

VioletCity_GhostGirl::
	msgbox VioletCity_GhostGirl_Text_0, MSGBOX_NPC
	return


VioletCity_PrimeTimeGuy::
	msgbox VioletCity_PrimeTimeGuy_Text_0, MSGBOX_NPC
	return


VioletCity_Gramps::
	msgbox VioletCity_Gramps_Text_0, MSGBOX_NPC
	return


VioletCity_TreeBoy::
	msgbox VioletCity_TreeBoy_Text_0, MSGBOX_NPC
	return


VioletCity_TownSloganSign::
	msgbox VioletCity_TownSloganSign_Text_0, MSGBOX_SIGN
	return


VioletCity_GymSign::
	msgbox VioletCity_GymSign_Text_0, MSGBOX_SIGN
	return


VioletCity_SproutTowerSign::
	msgbox VioletCity_SproutTowerSign_Text_0, MSGBOX_SIGN
	return


VioletCity_EarlsAcademySign::
	msgbox VioletCity_EarlsAcademySign_Text_0, MSGBOX_SIGN
	return


VioletCity_Earl_Text_0:
	.string "Hello!\n"
	.string "You are TRAINER?\p"
	.string "Battle GYM LEADER, win you did?$"

VioletCity_Earl_Text_1:
	.string "Ooh, la la!\n"
	.string "Very indeed nice!$"

VioletCity_Earl_Text_2:
	.string "Is that so? Then study shall you!\n"
	.string "Follow me!$"

VioletCity_Earl_Text_3:
	.string "Here, teacher I am.\n"
	.string "Good it is you study here!$"

VioletCity_GhostGirl_Text_0:
	.string "Ghosts are rumored to appear in\n"
	.string "SPROUT TOWER.\p"
	.string "They said NORMAL-type POKéMON moves\n"
	.string "had no effect on ghosts.$"

VioletCity_PrimeTimeGuy_Text_0:
	.string "Hey, you're a POKéMON TRAINER?\p"
	.string "If you beat the GYM LEADER here,\n"
	.string "you'll be ready for prime time!$"

VioletCity_Gramps_Text_0:
	.string "FALKNER, from the VIOLET POKéMON\n"
	.string "GYM, is a fine TRAINER!\p"
	.string "He inherited his father's GYM and\n"
	.string "has done a great job with it.$"

VioletCity_TreeBoy_Text_0:
	.string "I saw a wiggly tree up ahead!\p"
	.string "If you touch it, it squirms and\n"
	.string "dances! Cool!$"

VioletCity_TownSloganSign_Text_0:
	.string "VIOLET CITY\n"
	.string "The City of Nostalgic Scents$"

VioletCity_GymSign_Text_0:
	.string "VIOLET CITY POKéMON GYM\n"
	.string "LEADER: FALKNER\l"
	.string "The Elegant FLYING POKéMON Master$"

VioletCity_SproutTowerSign_Text_0:
	.string "SPROUT TOWER\n"
	.string "Experience the Way of POKéMON$"

VioletCity_EarlsAcademySign_Text_0:
	.string "EARL'S POKéMON ACADEMY$"
