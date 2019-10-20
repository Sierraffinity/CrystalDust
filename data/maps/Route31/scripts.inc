Route31_MapScripts:: @ 81EC38E
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route31_MapScript2_FrameTable
	.byte 0

Route31_MapScript2_FrameTable:
	map_script_2 VAR_ROUTE31_STATE, 0, Route31_EventScript_MomCall
	.2byte 0

Route31_EventScript_MomCall:
	lockall
	setflag FLAG_HIDE_MAP_NAME_POPUP
	pokegearcall PhoneScript_Mom, 0
	waitstate
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	addvar VAR_ROUTE31_STATE, 1
	releaseall
	end

Route31_EventScript_Explorer::
	msgbox Route31_Text_Explorer, MSGBOX_NPC
	end

Route31_EventScript_SleepyMan::
	@ TODO: Post-Kenya stuff
	msgbox Route31_Text_SleepyMan, MSGBOX_NPC
	end

Route31_EventScript_Youngster::
	msgbox Route31_Text_Youngster, MSGBOX_NPC
	end

Route31_EventScript_Trainer_Wade::
	trainerbattle_single TRAINER_WADE_1, Trainer_Text_Wade_See, Trainer_Text_Wade_Beat
	@TODO: Rematch
	msgbox Trainer_Text_Wade_After, MSGBOX_DEFAULT
	release
	end

Route31_EventScript_Directions::
	msgbox Route31_Text_Directions, MSGBOX_SIGN
	end

Route31_EventScript_DarkCave::
	msgbox Route31_Text_DarkCave, MSGBOX_SIGN
	end

Route31_Text_Explorer:
	.string "DARK CAVE…\p"
	.string "If POKéMON could light it up, I'd\n"
	.string "explore it.$"

Route31_Text_SleepyMan:
	.string "… Hnuurg… Huh?\p"
	.string "I walked too far today looking\n"
	.string "for POKéMON.\p"
	.string "My feet hurt and I'm sleepy…\p"
	.string "If I were a wild POKéMON, I'd be\n"
	.string "easy to catch…\p"
	.string "…Zzzz…$"

Route31_Text_Youngster:
	.string "I found a good POKéMON in\n"
	.string "DARK CAVE.\p"
	.string "I'm going to raise it to take on\n"
	.string "FALKNER, the leader of VIOLET\l"
	.string "CITY's GYM.$"

Route31_Text_Directions:
	.string "ROUTE 31\n"
	.string "VIOLET CITY - CHERRYGROVE CITY$"

Route31_Text_DarkCave:
	.string "DARK CAVE$"
