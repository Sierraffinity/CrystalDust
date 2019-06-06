Route30_MapScripts:: @ 81EC0E0
	map_script 2, Route30_MapScripts_Type2
	.byte 0

Route30_MapScripts_Type2:
	map_script_2 VAR_ROUTE30_STATE, 1, Route30_MapScript_ElmCall
	.2byte 0

Route30_MapScript_ElmCall:
	lockall
	pokegearcall Route30_Text_ElmCall, 1
	waitmessage
	setflag FLAG_ELM_CALLED_ABOUT_STOLEN_MON
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	addvar VAR_ROUTE30_STATE, 1
	releaseall
	end

Route30_EventScript_Directions::
	msgbox Route30_Text_Directions, MSGBOX_SIGN
	end

Route30_EventScript_MrPokemonsHouseAhead::
	msgbox Route30_Text_MrPokemonsHouseAhead, MSGBOX_SIGN
	end

Route30_EventScript_MrPokemonsHouse::
	msgbox Route30_Text_MrPokemonsHouse, MSGBOX_SIGN
	end

Route30_EventScript_TrainerTips::
	msgbox Route30_Text_TrainerTips, MSGBOX_SIGN
	end

Route30_EventScript_NotATrainerGirl::
	msgbox Route30_Text_NotATrainerShh, MSGBOX_NPC
	end

Route30_EventScript_DirectionsBoy::
	lock
	faceplayer
	goto_if_set FLAG_ADVENTURE_STARTED, Route30_EventScript_DirectionsBoyPostEgg
	msgbox Route30_Text_DirectionsBoy
	release
	end

Route30_EventScript_DirectionsBoyPostEgg:
	msgbox Route30_Text_DirectionsBoyPostEgg
	release
	end

Route30_EventScript_BattlingYoungster::
	lock
	waitse
	playbgm MUS_BATTLE20, 0
	msgbox Route30_Text_BattlingYoungster_UseTackle
	closemessage
	delay 15
	applymovement 7, Route30_Movement_RattataTackle
	delay 5
	playse SE_W004
	waitmovement 0
	faceplayer
	msgbox Route30_Text_BattlingYoungster_LeaveMeAlone
	closemessage
	turnobject VAR_LAST_TALKED, 2
	delay 10
	applymovement 6, Route30_Movement_PidgeyTackle
	delay 5
	playse SE_W004
	waitmovement 0
	savebgm MUS_DUMMY
	fadedefaultbgm
	release
	end

Route30_Movement_RattataTackle:
	lock_facing_direction
	set_fixed_priority
	disable_jump_landing_ground_effect
	jump_up
	walk_fast_down
	unlock_facing_direction
	clear_fixed_priority
	enable_jump_landing_ground_effect
	step_end

Route30_Movement_PidgeyTackle:
	lock_facing_direction
	set_fixed_priority
	disable_jump_landing_ground_effect
	jump_down
	walk_fast_up
	unlock_facing_direction
	clear_fixed_priority
	enable_jump_landing_ground_effect
	step_end

Route30_EventScript_Trainer_Joey::
	trainerbattle_single TRAINER_JOEY_1, Trainer_Text_Joey_See, Trainer_Text_Joey_Beat
	@TODO: Rematch
	msgbox Trainer_Text_Joey_After, MSGBOX_DEFAULT
	release
	end

Route30_EventScript_Trainer_Mikey::
	trainerbattle_single TRAINER_MIKEY, Trainer_Text_Mikey_See, Trainer_Text_Mikey_Beat
	msgbox Trainer_Text_Mikey_After, MSGBOX_AUTOCLOSE
	end

Route30_EventScript_Trainer_Don::
	trainerbattle_single TRAINER_DON, Trainer_Text_Don_See, Trainer_Text_Don_Beat
	msgbox Trainer_Text_Don_After, MSGBOX_AUTOCLOSE
	end

Route30_Text_DirectionsBoy:
	.string "MR. POKéMON's house?\n"
	.string "It's a bit farther ahead.$"

Route30_Text_DirectionsBoyPostEgg:
	.string "Everyone's having fun battling!\n"
	.string "You should too!$"

Route30_Text_NotATrainerShh:
	.string "I'm not a TRAINER.\p"
	.string "But if you look one in the eyes,\n"
	.string "prepare to battle.$"

Route30_Text_BattlingYoungster_UseTackle:
	.string "Go, RATTATA!\n"
	.string "Use TACKLE!$"

Route30_Text_BattlingYoungster_LeaveMeAlone:
	.string "What? This is a big battle!\n"
	.string "Leave me alone!$"

Route30_Text_Directions:
	.string "ROUTE 30\n"
	.string "VIOLET CITY - CHERRYGROVE CITY$"

Route30_Text_MrPokemonsHouseAhead:
	.string "MR. POKéMON'S HOUSE\n"
	.string "STRAIGHT AHEAD!$"

Route30_Text_MrPokemonsHouse:
	.string "MR. POKéMON'S HOUSE$"

Route30_Text_TrainerTips:
	.string "TRAINER TIPS\p"
	.string "No stealing other people's\n"
	.string "POKéMON!\p"
	.string "POKé BALLS are to be thrown only\n"
	.string "at wild POKéMON!$"

Route30_Text_ElmCall:
	.string "H-hello? {PLAYER}?\n"
	.string "It's a disaster!\p"
	.string "Uh, um, it's just terrible!\p"
	.string "What should I do?\n"
	.string "It… Oh, no…\p"
	.string "Please get back here now!$"
