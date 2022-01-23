RuinsOfAlph_KabutoChamber_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RuinsOfAlph_KabutoChamber_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_LOAD, RuinsOfAlph_KabutoChamber_MapScripts_MAP_SCRIPT_ON_LOAD
	map_script MAP_SCRIPT_ON_FRAME_TABLE, RuinsOfAlph_KabutoChamber_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

RuinsOfAlph_KabutoChamber_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	goto_if_set FLAG_SYS_BRAILLE_DIG, RuinsOfAlph_KabutoChamber_MapScripts_MAP_SCRIPT_ON_TRANSITION_2
	return

RuinsOfAlph_KabutoChamber_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
	setflag FLAG_HIDE_MAP_NAME_POPUP
	setvar VAR_TEMP_0, 1
	return

RuinsOfAlph_KabutoChamber_MapScripts_MAP_SCRIPT_ON_TRANSITION_2:
	goto_if_unset FLAG_OPENED_WALL_IN_KABUTO_CHAMBER, RuinsOfAlph_KabutoChamber_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	return

RuinsOfAlph_KabutoChamber_MapScripts_MAP_SCRIPT_ON_LOAD:
	goto_if_set FLAG_SOLVED_KABUTO_PUZZLE, RuinsOfAlph_KabutoChamber_MapScripts_MAP_SCRIPT_ON_LOAD_2
RuinsOfAlph_KabutoChamber_MapScripts_MAP_SCRIPT_ON_LOAD_1:
	goto_if_set FLAG_OPENED_WALL_IN_KABUTO_CHAMBER, RuinsOfAlph_KabutoChamber_MapScripts_MAP_SCRIPT_ON_LOAD_4
	return

RuinsOfAlph_KabutoChamber_MapScripts_MAP_SCRIPT_ON_LOAD_2:
	setmetatile 4, 5, METATILE_RuinsOfAlph_Puzzle_Hole_Left, FALSE
	setmetatile 5, 5, METATILE_RuinsOfAlph_Puzzle_Hole_Center, FALSE
	setmetatile 6, 5, METATILE_RuinsOfAlph_Puzzle_Hole_Right, FALSE
	goto RuinsOfAlph_KabutoChamber_MapScripts_MAP_SCRIPT_ON_LOAD_1

RuinsOfAlph_KabutoChamber_MapScripts_MAP_SCRIPT_ON_LOAD_4:
	setmetatile 5, 1, METATILE_RuinsOfAlph_HoleInWall, FALSE
	return

RuinsOfAlph_KabutoChamber_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_TEMP_0, 1, RuinsOfAlph_KabutoChamber_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0
	.2byte 0

RuinsOfAlph_KabutoChamber_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0:
	lockall
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 1
	setvar VAR_0x8006, 20
	setvar VAR_0x8007, 3
	special ShakeCamera
	waitstate
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	delay 4
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 2
	setvar VAR_0x8006, 20
	setvar VAR_0x8007, 3
	special ShakeCamera
	delay 30
	setmetatile 5, 1, METATILE_RuinsOfAlph_HoleInWall, FALSE
	special DrawWholeMapView
	playse SE_M_ROCK_THROW
	waitstate
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	setflag FLAG_OPENED_WALL_IN_KABUTO_CHAMBER
	setvar VAR_TEMP_0, 0
	releaseall
	return


RuinsOfAlph_KabutoChamber_EventScript_KabutoDescription::
	msgbox RuinsOfAlph_KabutoChamber_EventScript_KabutoDescription_Text_0, MSGBOX_SIGN
	return


RuinsOfAlph_KabutoChamber_EventScript_BackWall::
	lockall
	goto_if_set FLAG_OPENED_WALL_IN_KABUTO_CHAMBER, RuinsOfAlph_KabutoChamber_EventScript_BackWall_2
	message RuinsOfAlph_KabutoChamber_EventScript_BackWall_Text_1
	waitmessage
	unownmessage RuinsOfAlph_KabutoChamber_Unown_Escape
	waitbuttonpress
	closeunownmessage
RuinsOfAlph_KabutoChamber_EventScript_BackWall_1:
	releaseall
	return

RuinsOfAlph_KabutoChamber_EventScript_BackWall_2:
	msgbox RuinsOfAlph_KabutoChamber_EventScript_BackWall_Text_0, MSGBOX_SIGN
	goto RuinsOfAlph_KabutoChamber_EventScript_BackWall_1


RuinsOfAlph_KabutoChamber_Unown_Escape:
.unown "ESCAPE$"

RuinsOfAlph_KabutoChamber_EventScript_KabutoPuzzle::
	lockall
	setvar VAR_0x8004, 0
	special DoRuinsOfAlphPuzzle
	waitstate
	compare VAR_RESULT, 1
	goto_if_eq RuinsOfAlph_KabutoChamber_EventScript_KabutoPuzzle_2
RuinsOfAlph_KabutoChamber_EventScript_KabutoPuzzle_1:
	releaseall
	return

RuinsOfAlph_KabutoChamber_EventScript_KabutoPuzzle_2:
	setflag FLAG_SOLVED_KABUTO_PUZZLE
	setflag FLAG_HIDE_RUINS_OF_ALPH_KABUTO_CHAMBER_RECEPTIONIST
	call RuinsOfAlph_Chambers_EventScript_SolvePuzzle
	setwarp MAP_RUINS_OF_ALPH_INNER_CHAMBER, 2, 0, 0
	special DoFallWarp
	waitstate
	goto RuinsOfAlph_KabutoChamber_EventScript_KabutoPuzzle_1


RuinsOfAlph_Chambers_EventScript_SolvePuzzle::
	setflag FLAG_HIDE_RUINS_OF_ALPH_INNER_CHAMBER_TOURISTS
	setflag FLAG_MADE_UNOWN_APPEAR_IN_RUINS
	setflag FLAG_HIDE_MAP_NAME_POPUP
	clearflag FLAG_HIDE_RUINS_OF_ALPH_OUTSIDE_COWARD
	setvar VAR_RUINS_OF_ALPH_STATE, 1
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 1
	setvar VAR_0x8006, 20
	setvar VAR_0x8007, 3
	special ShakeCamera
	waitstate
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	delay 4
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 2
	setvar VAR_0x8006, 20
	setvar VAR_0x8007, 3
	special ShakeCamera
	delay 40
	setmetatile 4, 5, METATILE_RuinsOfAlph_Puzzle_Hole_Left, FALSE
	setmetatile 5, 5, METATILE_RuinsOfAlph_Puzzle_Hole_Center, FALSE
	setmetatile 6, 5, METATILE_RuinsOfAlph_Puzzle_Hole_Right, FALSE
	special DrawWholeMapView
	playse SE_BANG
	waitstate
	applymovement OBJ_EVENT_ID_PLAYER, RuinsOfAlph_Chambers_Movement_PlayerFallsIn
	waitmovement 0
	playse SE_FALL
	delay 60
	return


RuinsOfAlph_Chambers_Movement_PlayerFallsIn:
	walk_in_place_fast_up
	walk_in_place_fast_up
	walk_in_place_fast_up
	walk_in_place_fast_up
	walk_in_place_fast_up
	set_invisible
	step_end

RuinsOfAlph_KabutoChamber_EventScript_Scientist::
	lock
	faceplayer
	goto_if_set FLAG_OPENED_WALL_IN_KABUTO_CHAMBER, RuinsOfAlph_KabutoChamber_EventScript_Scientist_2
	goto_if_set FLAG_SOLVED_KABUTO_PUZZLE, RuinsOfAlph_KabutoChamber_EventScript_Scientist_6
	msgbox RuinsOfAlph_KabutoChamber_EventScript_Scientist_Text_2
RuinsOfAlph_KabutoChamber_EventScript_Scientist_5:
	turnobject 1, DIR_NORTH
RuinsOfAlph_KabutoChamber_EventScript_Scientist_1:
	release
	return

RuinsOfAlph_KabutoChamber_EventScript_Scientist_2:
	msgbox RuinsOfAlph_KabutoChamber_EventScript_Scientist_Text_0
	goto RuinsOfAlph_KabutoChamber_EventScript_Scientist_1

RuinsOfAlph_KabutoChamber_EventScript_Scientist_6:
	msgbox RuinsOfAlph_KabutoChamber_EventScript_Scientist_Text_1
	goto RuinsOfAlph_KabutoChamber_EventScript_Scientist_5


RuinsOfAlph_KabutoChamber_EventScript_Receptionist::
	msgbox RuinsOfAlph_KabutoChamber_EventScript_Receptionist_Text_0, MSGBOX_NPC
	return


RuinsOfAlph_KabutoChamber_EventScript_KabutoDescription_Text_0:
	.string "A POKéMON that hid on the sea floor.\n"
	.string "Eyes on its back scanned the area.$"

RuinsOfAlph_KabutoChamber_EventScript_BackWall_Text_0:
	.string "There's a big hole in the wall!$"

RuinsOfAlph_KabutoChamber_EventScript_BackWall_Text_1:
	.string "Patterns appeared on the walls…$"

RuinsOfAlph_KabutoChamber_EventScript_Scientist_Text_0:
	.string "Ah! Here's another huge hole!\n"
	.string "It's big enough to go through!$"

RuinsOfAlph_KabutoChamber_EventScript_Scientist_Text_1:
	.string "That tremor was pretty scary!\n"
	.string "But I'm more concerned about\l"
	.string "this wall here…\p"
	.string "Recently, strange, cryptic patterns\n"
	.string "have appeared.\p"
	.string "It's odd. They weren't here a\n"
	.string "little while ago…\p"
	.string "You should take a look at the\n"
	.string "walls around the RUINS.$"

RuinsOfAlph_KabutoChamber_EventScript_Scientist_Text_2:
	.string "Recently, strange, cryptic patterns\n"
	.string "have appeared.\p"
	.string "It's odd. They weren't here a\n"
	.string "little while ago…\p"
	.string "You should take a look at the\n"
	.string "walls around the RUINS.$"

RuinsOfAlph_KabutoChamber_EventScript_Receptionist_Text_0:
	.string "Welcome to this chamber.\p"
	.string "There are sliding panels that depict\n"
	.string "a POKéMON drawn by the ancients.\p"
	.string "Slide the panels around to form\n"
	.string "the picture.\p"
	.string "To the sides are descriptions of\n"
	.string "the POKéMON.\p"
	.string "Scientists in the back are examining\n"
	.string "some newly found patterns.$"
