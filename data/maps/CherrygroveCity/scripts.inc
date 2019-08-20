CherrygroveCity_MapScripts:: @ 81E8EA2
	map_script 3, CherrygroveCity_MapScript1_1E8EA8
	.byte 0

CherrygroveCity_MapScript1_1E8EA8: @ 81E8EA8
	setflag FLAG_VISITED_CHERRYGROVE_CITY
	end

CherrygroveCity_EventScript_GuideGentsHouse::
	msgbox CherrygroveCity_Text_GuideGentsHouse, MSGBOX_SIGN
	end

CherrygroveCity_EventScript_Slogan::
	msgbox CherrygroveCity_Text_Slogan, MSGBOX_SIGN
	end

CherrygroveCity_EventScript_GuideGent::
	lock
	faceplayer
	msgbox CherrygroveCity_Text_GuideGent_Intro, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq CherrygroveCity_EventScript_GuideGent_Rejected
	msgbox CherrygroveCity_Text_GuideGent_OkayThen
	closemessage
	playbgm MUS_FOLLOWME, 0
	compare VAR_FACING, 4
	call_if_eq CherrygroveCity_EventScript_GuideGentFromLeft
	compare VAR_FACING, 2
	call_if_eq CherrygroveCity_EventScript_GuideGentFromBelow
	compare VAR_FACING, 3
	call_if_eq CherrygroveCity_EventScript_GuideGentFromRight
	msgbox CherrygroveCity_Text_GuideGent_PokemonCenter
	closemessage
	applymovement 1, CherrygroveCity_Movement_ToMart
	applymovement EVENT_OBJ_ID_PLAYER, CherrygroveCity_Movement_ToMart
	waitmovement 0
	msgbox CherrygroveCity_Text_GuideGent_PokemonMart
	closemessage
	applymovement 1, CherrygroveCity_Movement_ToRoute30
	applymovement EVENT_OBJ_ID_PLAYER, CherrygroveCity_Movement_ToRoute30
	waitmovement 0
	msgbox CherrygroveCity_Text_GuideGent_Route30
	closemessage
	applymovement 1, CherrygroveCity_Movement_GuideGentToSea
	applymovement EVENT_OBJ_ID_PLAYER, CherrygroveCity_Movement_PlayerToSea
	waitmovement 0
	msgbox CherrygroveCity_Text_GuideGent_Sea
	closemessage
	applymovement 1, CherrygroveCity_Movement_GuideGentToGuideGentsHouse
	applymovement EVENT_OBJ_ID_PLAYER, CherrygroveCity_Movement_PlayerToGuideGentsHouse
	waitmovement 0
	delay 60
	turnobject 1, 3
	turnobject EVENT_OBJ_ID_PLAYER, 4
	msgbox CherrygroveCity_Text_GuideGent_ItsMyHouse
	textcolor MSG_COLOR_BLACK
	playfanfare MUS_FANFA4
	setflag FLAG_SYS_HAS_MAP_CARD
	message CherrygroveCity_Text_GuideGent_GetMapCard1
	waitfanfare
	msgbox CherrygroveCity_Text_GuideGent_GetMapCard2
	call RestoreOriginalTextColor
	msgbox CherrygroveCity_Text_GuideGent_Pokegear
	closemessage
	savebgm MUS_DUMMY
	fadedefaultbgm
	turnobject EVENT_OBJ_ID_PLAYER, 2
	applymovement 1, CherrygroveCity_Movement_WalkUp
	waitmovement 0
	opendoor 36, 12
	waitdooranim
	applymovement 1, CherrygroveCity_Movement_WalkUp
	waitmovement 0
	removeobject 1
	closedoor 36, 12
	waitdooranim
	clearflag FLAG_HIDE_CHERRYGROVE_CITY_GUIDE_GENT_INSIDE
	release
	end

CherrygroveCity_Movement_ToMart:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_fastest_up
	step_end

CherrygroveCity_Movement_ToRoute30:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_fastest_up
	step_end

CherrygroveCity_Movement_GuideGentToSea:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	walk_in_place_fastest_left
	step_end

CherrygroveCity_Movement_PlayerToSea:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_left
	walk_left
	walk_left
	step_end

CherrygroveCity_Movement_GuideGentToGuideGentsHouse:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_fastest_up
	step_end

CherrygroveCity_Movement_PlayerToGuideGentsHouse:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_fastest_up
	step_end

CherrygroveCity_Movement_WalkUp:
	walk_up
	step_end

CherrygroveCity_EventScript_GuideGentFromLeft:
	applymovement 1, CherrygroveCity_Movement_GuideGentFromLeft
	applymovement EVENT_OBJ_ID_PLAYER, CherrygroveCity_Movement_PlayerFromLeft
	waitmovement 0
	return

CherrygroveCity_Movement_GuideGentFromLeft:
	delay_16
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_left
	walk_in_place_fastest_up
	step_end

CherrygroveCity_Movement_PlayerFromLeft:
	walk_down
	walk_in_place_fastest_up
	delay_8
	delay_4
	walk_up
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

CherrygroveCity_EventScript_GuideGentFromBelow:
	applymovement 1, CherrygroveCity_Movement_GuideGentFromBelow
	applymovement EVENT_OBJ_ID_PLAYER, CherrygroveCity_Movement_PlayerFromBelow
	waitmovement 0
	return

CherrygroveCity_Movement_GuideGentFromBelow:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_left
	walk_in_place_fastest_up
	step_end

CherrygroveCity_Movement_PlayerFromBelow:
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

CherrygroveCity_EventScript_GuideGentFromRight:
	applymovement 1, CherrygroveCity_Movement_GuideGentFromRight
	applymovement EVENT_OBJ_ID_PLAYER, CherrygroveCity_Movement_PlayerFromRight
	waitmovement 0
	return

CherrygroveCity_Movement_GuideGentFromRight:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_left
	walk_in_place_fastest_up
	step_end

CherrygroveCity_Movement_PlayerFromRight:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

CherrygroveCity_EventScript_GuideGent_Rejected:
	msgbox CherrygroveCity_Text_GuideGent_Rejected
	release
	end

CherrygroveCity_EventScript_Rival1::
	lockall
	setvar VAR_TEMP_1, 0
	goto CherrygroveCity_EventScript_RivalMain

CherrygroveCity_EventScript_Rival2::
	lockall
	setvar VAR_TEMP_1, 1
	setobjectxyperm 2, 55, 9
	goto CherrygroveCity_EventScript_RivalMain

CherrygroveCity_EventScript_Rival3::
	lockall
	setvar VAR_TEMP_1, 2
	setobjectxyperm 2, 55, 10
	goto CherrygroveCity_EventScript_RivalMain

CherrygroveCity_EventScript_RivalMain:
	addobject 2
	textcolor MSG_COLOR_BLUE
	fadenewbgm 0
	turnobject EVENT_OBJ_ID_PLAYER, 4
	playse SE_PIN
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	applymovement 2, CherrygroveCity_Movement_RivalToPlayer
	waitmovement 0
	playbgm MUS_RIVALENC, 0
	savebgm MUS_RIVALEXIT
	msgbox CherrygroveCity_Text_Rival_GotAMon
	setvar VAR_LAST_TALKED, 2
	compare VAR_STARTER_MON, 0
	call_if_eq CherrygroveCity_EventScript_RivalCyndaquil
	compare VAR_STARTER_MON, 1
	call_if_eq CherrygroveCity_EventScript_RivalChikorita
	compare VAR_STARTER_MON, 2
	call_if_eq CherrygroveCity_EventScript_RivalTotodile
	special HealPlayerParty
	msgbox CherrygroveCity_Text_Rival_PostBattle
	closemessage
	delay 10
	playse SE_KOUKA_L
	applymovement EVENT_OBJ_ID_PLAYER, CherrygroveCity_Movement_RivalPushesPlayer
	applymovement 2, CherrygroveCity_Movement_RivalRunsAway
	waitmovement 0
	fadedefaultbgm
	removeobject 2
	setvar VAR_CHERRYGROVE_CITY_STATE, 2
	releaseall
	end

CherrygroveCity_Movement_RivalPushesPlayer:
	face_up
	lock_facing_direction
	walk_fast_down
	unlock_facing_direction
	walk_in_place_fastest_left
	step_end

CherrygroveCity_Movement_RivalRunsAway:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

CherrygroveCity_EventScript_RivalCyndaquil:
	trainerbattle_wintext TRAINER_RIVAL_1, 1, CherrygroveCity_Text_Rival_BattleWin, CherrygroveCity_Text_Rival_BattleLose
	return

CherrygroveCity_EventScript_RivalChikorita:
	trainerbattle_wintext TRAINER_RIVAL_2, 1, CherrygroveCity_Text_Rival_BattleWin, CherrygroveCity_Text_Rival_BattleLose
	return

CherrygroveCity_EventScript_RivalTotodile:
	trainerbattle_wintext TRAINER_RIVAL_3, 1, CherrygroveCity_Text_Rival_BattleWin, CherrygroveCity_Text_Rival_BattleLose
	return

CherrygroveCity_Movement_RivalToPlayer:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

CherrygroveCity_EventScript_Teacher::
	lock
	faceplayer
	goto_if_set FLAG_SYS_HAS_MAP_CARD, CherrygroveCity_EventScript_TeacherPostMapCard
	msgbox CherrygroveCity_Text_TeacherPreMapCard
	release
	end

CherrygroveCity_EventScript_TeacherPostMapCard:
	msgbox CherrygroveCity_Text_TeacherPostMapCard
	release
	end

CherrygroveCity_EventScript_Youngster::
	lock
	faceplayer
	goto_if_set FLAG_SYS_POKEDEX_GET, CherrygroveCity_EventScript_YoungsterPostDex
	msgbox CherrygroveCity_Text_YoungsterPreDex
	release
	end

CherrygroveCity_EventScript_YoungsterPostDex:
	msgbox CherrygroveCity_Text_YoungsterPostDex
	release
	end

CherrygroveCity_Text_GuideGent_Intro:
	.string "You're a rookie TRAINER, aren't you?\n"
	.string "I can tell!\p"
	.string "That's okay!\n"
	.string "Everyone is a rookie at some point!\p"
	.string "If you'd like, I can teach you a\n"
	.string "few things.$"

CherrygroveCity_Text_GuideGent_OkayThen:
	.string "Okay, then!\n"
	.string "Follow me!$"

CherrygroveCity_Text_GuideGent_PokemonCenter:
	.string "This is a POKéMON CENTER.\p"
	.string "They heal your POKéMON in no time\n"
	.string "at all.\p"
	.string "You'll be relying on them a lot, so\n"
	.string "you better learn about them.$"

CherrygroveCity_Text_GuideGent_PokemonMart:
	.string "This is a POKéMON MART.\p"
	.string "They sell POKé BALLS for catching\n"
	.string "wild POKéMON and other useful items.$"

CherrygroveCity_Text_GuideGent_Route30:
	.string "ROUTE 30 is out this way.\p"
	.string "TRAINERS will be battling their\n"
	.string "prized POKéMON there.$"

CherrygroveCity_Text_GuideGent_Sea:
	.string "This is the sea, as you can see.\p"
	.string "Some POKéMON are found only in\n"
	.string "water.$"

CherrygroveCity_Text_GuideGent_ItsMyHouse:
	.string "Here…\p"
	.string "It's my house!\n"
	.string "Thanks for your company.\p"
	.string "Let me give you a small gift.$"

CherrygroveCity_Text_GuideGent_GetMapCard1:
	.string "{PLAYER} received the MAP CARD.$"

CherrygroveCity_Text_GuideGent_GetMapCard2:
	.string "{PLAYER}'s POKéGEAR now has a MAP!$"

CherrygroveCity_Text_GuideGent_Pokegear:
	.string "The POKéGEAR becomes more useful\n"
	.string "as you add CARDS.\p"
	.string "I wish you luck on your journey!$"

CherrygroveCity_Text_Rival_GotAMon:
	.string "…… …… ……\n"
	.string "You got a POKéMON at the lab.\p"
	.string "What a waste of a POKéMON.\n"
	.string "Given to a wimp like you.\p"
	.string "…… …… ……\n"
	.string "Don't you get what I'm saying?\p"
	.string "Well, I too have a good POKéMON.\n"
	.string "I'll show you what I mean!$"

CherrygroveCity_Text_Rival_BattleWin:
	.string "…Humph.\n"
	.string "Are you happy you won?$"

CherrygroveCity_Text_Rival_BattleLose:
	.string "…Humph.\n"
	.string "That was a waste of time.$"

CherrygroveCity_Text_Rival_PostBattle:
	.string "…… …… ……\n"
	.string "My name's ???.\p"
	.string "I'm going to be the world's greatest\n"
	.string "POKéMON TRAINER.$"

CherrygroveCity_Text_GuideGent_Rejected:
	.string "Oh…\n"
	.string "It's something I enjoy doing…\p"
	.string "Fine. Come see me when you like.$"

CherrygroveCity_Text_TeacherPreMapCard:
	.string "Did you talk to the old man by the\n"
	.string "POKéMON CENTER?\p"
	.string "He'll put a map of JOHTO on your\n"
	.string "POKéGEAR.$"

CherrygroveCity_Text_TeacherPostMapCard:
	.string "When you're with POKéMON, going\n"
	.string "anywhere is fun.$"

CherrygroveCity_Text_YoungsterPreDex:
	.string "MR. POKéMON's house is still farther\n"
	.string "up ahead.$"

CherrygroveCity_Text_YoungsterPostDex:
	.string "I battled the TRAINERS on the road.\n"
	.string "My POKéMON lost. They're a mess!\p"
	.string "I need to take them to a POKéMON\n"
	.string "CENTER.$"

CherrygroveCity_Text_GuideGentsHouse:
	.string "GUIDE GENT'S HOUSE$"

CherrygroveCity_Text_Slogan:
	.string "CHERRYGROVE CITY\n"
	.string "The City of Cute, Fragrant Flowers$"
