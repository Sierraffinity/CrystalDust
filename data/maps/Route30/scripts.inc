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

Route30_EventScript_1EC105:: @ 81EC105
	trainerbattle_single TRAINER_CALVIN_1, Route30_Text_294513, Route30_Text_29457C, Route30_EventScript_1EC146
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq Route30_EventScript_1EC19C
	setvar VAR_0x8004, 318
	specialvar VAR_RESULT, sub_813B4E0
	compare VAR_RESULT, 0
	goto_if_eq Route30_EventScript_1EC170
	msgbox Route30_Text_2945AC, MSGBOX_DEFAULT
	release
	end

Route30_EventScript_1EC146:: @ 81EC146
	special sub_80B4808
	waitmovement 0
	goto_if_set FLAG_HAS_MATCH_CALL, Route30_EventScript_1EC157
	release
	end

Route30_EventScript_1EC157:: @ 81EC157
	msgbox Route30_Text_294668, MSGBOX_DEFAULT
	register_matchcall TRAINER_CALVIN_1
	release
	end

Route30_EventScript_1EC170:: @ 81EC170
	goto_if_set FLAG_HAS_MATCH_CALL, Route30_EventScript_1EC183
	msgbox Route30_Text_2945AC, MSGBOX_DEFAULT
	release
	end

Route30_EventScript_1EC183:: @ 81EC183
	msgbox Route30_Text_2945EB, MSGBOX_DEFAULT
	register_matchcall TRAINER_CALVIN_1
	release
	end

Route30_EventScript_1EC19C:: @ 81EC19C
	trainerbattle_rematch TRAINER_CALVIN_1, Route30_Text_2946AE, Route30_Text_29470C
	msgbox Route30_Text_29473C, MSGBOX_AUTOCLOSE
	end

Route30_EventScript_1EC1B3:: @ 81EC1B3
	trainerbattle_single TRAINER_RICK, Route30_Text_29480C, Route30_Text_294847
	msgbox Route30_Text_294859, MSGBOX_AUTOCLOSE
	end

Route30_EventScript_1EC1CA:: @ 81EC1CA
	trainerbattle_single TRAINER_TIANA, Route30_Text_29489E, Route30_Text_2948F3
	msgbox Route30_Text_294916, MSGBOX_AUTOCLOSE
	end

Route30_EventScript_1EC1E1:: @ 81EC1E1
	trainerbattle_single TRAINER_ALLEN, Route30_Text_294775, Route30_Text_2947AA
	msgbox Route30_Text_2947DB, MSGBOX_AUTOCLOSE
	end

PetalburgCity_Text_1EC1F8: @ 81EC1F8
	.string "WALLY: {PLAYER}…\n"
	.string "POKéMON hide in tall grass like this,\l"
	.string "don't they?\p"
	.string "Please watch me and see if I can\n"
	.string "catch one properly.\p"
	.string "…Whoa!$"

PetalburgCity_Text_1EC271: @ 81EC271
	.string "WALLY: I did it… It's my…\n"
	.string "My POKéMON!$"

PetalburgCity_Text_1EC297: @ 81EC297
	.string "{PLAYER}, thank you!\n"
	.string "Let's go back to the GYM!$"

Route30_Text_1EC2C0: @ 81EC2C0
	.string "I'm…not very tall, so I sink right\n"
	.string "into tall grass.\p"
	.string "The grass goes up my nose and…\n"
	.string "Fwafwafwafwafwa…\p"
	.string "Fwatchoo!$"

Route30_Text_1EC32E: @ 81EC32E
	.string "I'm going to catch a whole bunch of\n"
	.string "POKéMON!$"

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
	.string "No stealing other people's POKéMON!\p"
	.string "POKé BALLS are to be thrown only at\n"
	.string "wild POKéMON!$"

Route30_Text_ElmCall:
	.string "H-hello? {PLAYER}?\n"
	.string "It's a disaster!\p"
	.string "Uh, um, it's just terrible!\p"
	.string "What should I do?\n"
	.string "It… Oh, no…\p"
	.string "Please get back here now!$"
