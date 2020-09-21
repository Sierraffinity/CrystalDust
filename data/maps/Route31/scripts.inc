Route31_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route31_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

Route31_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_ROUTE31_STATE, 0, Route31_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0
	.2byte 0

Route31_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0:
	lockall
	setflag FLAG_HIDE_MAP_NAME_POPUP
	pokegearcall PhoneScript_Mom, 0
	waitstate
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	setvar VAR_ROUTE31_STATE, 1
	releaseall
	return


Route31_EventScript_Explorer::
	msgbox Route31_EventScript_Explorer_Text_0, MSGBOX_NPC
	return


Route31_EventScript_SleepyMan::
	msgbox Route31_EventScript_SleepyMan_Text_0, MSGBOX_NPC
	return


Route31_EventScript_Youngster::
	msgbox Route31_EventScript_Youngster_Text_0, MSGBOX_NPC
	return


Route31_EventScript_Trainer_Wade::
	trainerbattle_single TRAINER_WADE_1, Trainer_Text_Wade_See, Trainer_Text_Wade_Beat
	msgbox Trainer_Text_Wade_After, MSGBOX_DEFAULT
	release
	return


Route31_EventScript_Directions::
	msgbox Route31_EventScript_Directions_Text_0, MSGBOX_SIGN
	return


Route31_EventScript_DarkCave::
	msgbox Route31_EventScript_DarkCave_Text_0, MSGBOX_SIGN
	return


Route31_EventScript_Explorer_Text_0:
	.string "DARK CAVE…\p"
	.string "If POKéMON could light it up, I'd\n"
	.string "explore it.$"

Route31_EventScript_SleepyMan_Text_0:
	.string "… Hnuurg… Huh?\p"
	.string "I walked too far today looking\n"
	.string "for POKéMON.\p"
	.string "My feet hurt and I'm sleepy…\p"
	.string "If I were a wild POKéMON, I'd be\n"
	.string "easy to catch…\p"
	.string "…Zzzz…$"

Route31_EventScript_Youngster_Text_0:
	.string "I found a good POKéMON in\n"
	.string "DARK CAVE.\p"
	.string "I'm going to raise it to take on\n"
	.string "FALKNER, the leader of VIOLET\l"
	.string "CITY's GYM.$"

Route31_EventScript_Directions_Text_0:
	.string "ROUTE 31\n"
	.string "VIOLET CITY - CHERRYGROVE CITY$"

Route31_EventScript_DarkCave_Text_0:
	.string "DARK CAVE$"
