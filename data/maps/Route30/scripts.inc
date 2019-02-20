Route30_MapScripts:: @ 81EC0E0
	.byte 0

Route30_EventScript_1EC0E1:: @ 81EC0E1
	msgbox Route30_Text_1EC2C0, MSGBOX_NPC
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

Route30_EventScript_1EC0FC:: @ 81EC0FC
	msgbox Route30_Text_1EC32E, MSGBOX_NPC
	end

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
