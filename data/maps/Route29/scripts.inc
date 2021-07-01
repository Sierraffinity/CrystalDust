Route29_EventScript_Tuscany::
	lock
	faceplayer
	goto_if_unset FLAG_RECEIVED_SILK_SCARF_FROM_TUSCANY, Route29_EventScript_Tuscany_2
	msgbox Route29_EventScript_Tuscany_Text_4
Route29_EventScript_Tuscany_1:
	release
	return

Route29_EventScript_Tuscany_2:
	gettime
	compare VAR_0x8003, DAY_TUESDAY
	goto_if_eq Route29_EventScript_Tuscany_5
	msgbox Route29_EventScript_Tuscany_Text_3
	goto Route29_EventScript_Tuscany_1

Route29_EventScript_Tuscany_5:
	goto_if_unset FLAG_MET_TUSCANY_OF_TUESDAY, Route29_EventScript_Tuscany_9
	msgbox Route29_EventScript_Tuscany_Text_1
Route29_EventScript_Tuscany_8:
	giveitem ITEM_SILK_SCARF
	compare VAR_RESULT, 0
	goto_if_eq Route29_EventScript_Tuscany_13
Route29_EventScript_Tuscany_12:
	setflag FLAG_RECEIVED_SILK_SCARF_FROM_TUSCANY
	msgbox Route29_EventScript_Tuscany_Text_2
	goto Route29_EventScript_Tuscany_1

Route29_EventScript_Tuscany_9:
	msgbox Route29_EventScript_Tuscany_Text_0
	setflag FLAG_MET_TUSCANY_OF_TUESDAY
	goto Route29_EventScript_Tuscany_8

Route29_EventScript_Tuscany_13:
	goto Common_EventScript_ShowBagIsFull
	goto Route29_EventScript_Tuscany_12


Route29_MapScripts:: @ 81EBCBA
	map_script 3, Route29_MapScript1_Type3
	map_script 2, Route29_MapScript2_Type2
	.byte 0

Route29_MapScript1_Type3: @ 81EBCC5
	call Route29_MapScript1_CheckForTuscany
	end

Route29_MapScript1_CheckForTuscany:
	goto_if_unset FLAG_BADGE01_GET, Route29_EventScript_HideTuscany
	gettime
	compare VAR_0x8003, DAY_TUESDAY
	goto_if_ne Route29_EventScript_HideTuscany
	clearflag FLAG_HIDE_ROUTE_29_TUSCANY
	return

Route29_EventScript_HideTuscany:
	setflag FLAG_HIDE_ROUTE_29_TUSCANY
	return

Route29_MapScript2_Type2:
	.2byte 0

Route29_EventScript_Youngster::
	msgbox Route29_Text_Youngster, MSGBOX_NPC
	end

Route29_EventScript_LedgeGirl::
	msgbox Route29_Text_LedgeGirl, MSGBOX_NPC
	end

Route29_EventScript_FatMan::
	msgbox Route29_Text_FatMan, MSGBOX_NPC
	end

Route29_EventScript_WaitingMan::
	lock
	faceplayer
	gettime
	compare VAR_0x8002, TIME_NIGHT
	goto_if_eq Route29_EventScript_ManWaitingForMorning
	msgbox Route29_Text_WaitingForNight
	release
	end

Route29_EventScript_ManWaitingForMorning::
	msgbox Route29_Text_WaitingForMorning
	release
	end

Route29_EventScript_DirectionSign::
	msgbox Route29_Text_DirectionSign, MSGBOX_SIGN
	end

Route29_EventScript_Dude::
	lock
	faceplayer
	goto_if_set FLAG_LEARNED_TO_CATCH_POKEMON, Route29_EventScript_Dude_NothingToTeach
	goto_if_unset FLAG_GAVE_MYSTERY_EGG_TO_ELM, Route29_EventScript_Dude_NothingToTeach
	msgbox Route29_Text_Dude_HowAboutNow, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq Route29_EventScript_Dude_CatchingTutorialRejected
	closemessage
	special StartDudeTutorialBattle
	waitstate
	lock @ hack
	msgbox Route29_Text_Dude_CatchingOutro
	setflag FLAG_LEARNED_TO_CATCH_POKEMON
	release
	end

Route29_EventScript_Dude_CatchingTutorialRejected:
	msgbox Route29_Text_Dude_CatchingTutRejected
	release
	end

Route29_EventScript_Dude_NothingToTeach:
	msgbox Route29_Text_PokemonInTheGrass
	release
	end

Route29_EventScript_CatchingTutorial1::
	lockall
	setvar VAR_TEMP_1, 0
	turnobject 1, 2
	playse SE_PIN
	applymovement 1, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	applymovement 1, Route29_Movement_DudeToPlayerTop
	waitmovement 0
	goto Route29_EventScript_CatchingTutorialMain

Route29_Movement_DudeToPlayerTop:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	step_end

Route29_EventScript_CatchingTutorial2::
	lockall
	setvar VAR_TEMP_1, 1
	turnobject 1, 2
	playse SE_PIN
	applymovement 1, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	applymovement 1, Route29_Movement_DudeToPlayerMiddleTop
	waitmovement 0
	goto Route29_EventScript_CatchingTutorialMain

Route29_Movement_DudeToPlayerMiddleTop:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	step_end

Route29_EventScript_CatchingTutorial3::
	lockall
	setvar VAR_TEMP_1, 2
	turnobject 1, 2
	playse SE_PIN
	applymovement 1, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	applymovement 1, Route29_Movement_DudeToPlayerMiddleBottom
	waitmovement 0
	goto Route29_EventScript_CatchingTutorialMain

Route29_Movement_DudeToPlayerMiddleBottom:
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	step_end

Route29_EventScript_CatchingTutorial4::
	lockall
	setvar VAR_TEMP_1, 3
	turnobject 1, 2
	playse SE_PIN
	applymovement 1, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	applymovement 1, Route29_Movement_DudeToPlayerBottom
	waitmovement 0
	goto Route29_EventScript_CatchingTutorialMain

Route29_Movement_DudeToPlayerBottom:
	walk_up
	walk_up
	walk_right
	walk_right
	step_end

Route29_EventScript_CatchingTutorialMain:
	textcolor MSG_COLOR_BLUE
	setflag FLAG_DUDE_TALKED_TO_YOU
	setvar VAR_ROUTE29_STATE, 2
	msgbox Route29_Text_Dude_CatchingIntro, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq Route29_EventScript_CatchingTutorialRejected
	closemessage
	compare VAR_TEMP_1, 0
	call_if_eq Route29_EventScript_DudeAndPlayerWalkFromTop
	compare VAR_TEMP_1, 1
	call_if_eq Route29_EventScript_DudeAndPlayerWalkFromMiddleTop
	compare VAR_TEMP_1, 2
	call_if_eq Route29_EventScript_DudeAndPlayerWalkFromMiddleBottom
	compare VAR_TEMP_1, 3
	call_if_eq Route29_EventScript_DudeAndPlayerWalkFromBottom
	special StartDudeTutorialBattle
	waitstate
	turnobject 1, 2
	msgbox Route29_Text_Dude_CatchingOutro
	setflag FLAG_LEARNED_TO_CATCH_POKEMON
	releaseall
	end

Route29_EventScript_DudeAndPlayerWalkFromTop:
	applymovement OBJ_EVENT_ID_PLAYER, Route29_Movement_PlayerFromTop
	applymovement 1, Route29_Movement_DudeFromTop
	waitmovement 0
	return

Route29_Movement_PlayerFromTop:
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Route29_EventScript_DudeAndPlayerWalkFromMiddleTop:
	applymovement OBJ_EVENT_ID_PLAYER, Route29_Movement_PlayerFromMiddleTop
	applymovement 1, Route29_Movement_DudeFromMiddleTop
	waitmovement 0
	return

Route29_Movement_PlayerFromMiddleTop:
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	step_end

Route29_EventScript_DudeAndPlayerWalkFromMiddleBottom:
	applymovement OBJ_EVENT_ID_PLAYER, Route29_Movement_PlayerFromMiddleBottom
	applymovement 1, Route29_Movement_DudeFromMiddleBottom
	waitmovement 0
	return

Route29_Movement_PlayerFromMiddleBottom:
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	step_end

Route29_EventScript_DudeAndPlayerWalkFromBottom:
	applymovement OBJ_EVENT_ID_PLAYER, Route29_Movement_PlayerFromBottom
	applymovement 1, Route29_Movement_DudeFromBottom
	waitmovement 0
	return

Route29_Movement_PlayerFromBottom:
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

Route29_EventScript_CatchingTutorialRejected:
	msgbox Route29_Text_Dude_CatchingTutRejected
	closemessage
	compare VAR_TEMP_1, 0
	call_if_eq Route29_EventScript_DudeWalkBackFromTop
	compare VAR_TEMP_1, 1
	call_if_eq Route29_EventScript_DudeWalkBackFromMiddleTop
	compare VAR_TEMP_1, 2
	call_if_eq Route29_EventScript_DudeWalkBackFromMiddleBottom
	compare VAR_TEMP_1, 3
	call_if_eq Route29_EventScript_DudeWalkBackFromBottom
	releaseall
	end

Route29_EventScript_DudeWalkBackFromTop:
	applymovement 1, Route29_Movement_DudeFromTop
	waitmovement 0
	return

Route29_Movement_DudeFromTop:
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Route29_EventScript_DudeWalkBackFromMiddleTop:
	applymovement 1, Route29_Movement_DudeFromMiddleTop
	waitmovement 0
	return

Route29_Movement_DudeFromMiddleTop:
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Route29_EventScript_DudeWalkBackFromMiddleBottom:
	applymovement 1, Route29_Movement_DudeFromMiddleBottom
	waitmovement 0
	return

Route29_Movement_DudeFromMiddleBottom:
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	step_end

Route29_EventScript_DudeWalkBackFromBottom:
	applymovement 1, Route29_Movement_DudeFromBottom
	waitmovement 0
	return

Route29_Movement_DudeFromBottom:
	walk_left
	walk_left
	walk_down
	walk_down
	step_end

Route29_Text_Youngster:
	.string "Yo.\n"
	.string "How are your POKéMON?\p"
	.string "If they're weak and not ready for\n"
	.string "battle, keep out of the grass.$"

Route29_Text_LedgeGirl:
	.string "See those ledges?\n"
	.string "It's scary to jump off them.\p"
	.string "But you can go to NEW BARK without\n"
	.string "walking through the grass.$"

Route29_Text_FatMan:
	.string "I wanted to take a break, so I\n"
	.string "saved to record my progress.$"

Route29_Text_WaitingForNight:
	.string "I'm waiting for POKéMON that appear\n"
	.string "only at night.$"

Route29_Text_WaitingForMorning:
	.string "I'm waiting for POKéMON that appear\n"
	.string "only in the morning.$"

Route29_Text_PokemonInTheGrass:
	.string "POKéMON hide in the grass.\n"
	.string "Who knows when they'll pop out…$"

Route29_Text_Dude_CatchingIntro:
	.string "I've seen you a couple times.\n"
	.string "How many POKéMON have you caught?\p"
	.string "Would you like me to show you how\n"
	.string "to catch POKéMON?$"

Route29_Text_Dude_CatchingOutro:
	.string "That's how you do it.\p"
	.string "If you weaken them first, POKéMON\n"
	.string "are easier to catch.$"

Route29_Text_Dude_HowAboutNow:
	.string "Huh? You want me to show you how\n"
	.string "to catch POKéMON?$"

Route29_Text_Dude_CatchingTutRejected:
	.string "Oh.\n"
	.string "Fine, then.\p"
	.string "Anyway, if you want to catch\n"
	.string "POKéMON, you have to walk a lot.$"

Route29_Text_DirectionSign:
	.string "ROUTE 29\n"
	.string "CHERRYGROVE CITY - NEW BARK TOWN$"

Route29_EventScript_Tuscany_Text_0:
	.string "TUSCANY: I do believe that this\n"
	.string "is the first time we've met?\p"
	.string "Please allow me to introduce\n"
	.string "myself.\p"
	.string "I am TUSCANY of TUESDAY.\p"
	.string "By way of introduction, please\n"
	.string "accept this gift, a SILK SCARF.$"

Route29_EventScript_Tuscany_Text_1:
	.string "TUSCANY: By way of introduction,\n"
	.string "please accept this gift, a\l"
	.string "SILK SCARF.$"

Route29_EventScript_Tuscany_Text_2:
	.string "TUSCANY: Wouldn't you agree that\n"
	.string "it is most adorable?\p"
	.string "It strengthens NORMAL-type moves.\n"
	.string "I am certain it will be of use.$"

Route29_EventScript_Tuscany_Text_3:
	.string "TUSCANY: Today is not TUESDAY.\n"
	.string "That is unfortunate…$"

Route29_EventScript_Tuscany_Text_4:
	.string "TUSCANY: Have you met MONICA,\n"
	.string "my older sister?\l"
	.string "Or my younger brother, WESLEY?\p"
	.string "I am the second of seven children.$"
