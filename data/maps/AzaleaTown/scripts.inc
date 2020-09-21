AzaleaTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, AzaleaTown_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

AzaleaTown_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	setflag FLAG_VISITED_AZALEA_TOWN
	return


AzaleaTown_EventScript_RivalTrigger_1::
	lockall
	setvar VAR_TEMP_1, 0
	setobjectxyperm 9, 19, 10
	goto AzaleaTown_EventScript_RivalTrigger_All
	return


AzaleaTown_EventScript_RivalTrigger_2::
	lockall
	setvar VAR_TEMP_1, 1
	goto AzaleaTown_EventScript_RivalTrigger_All
	return


AzaleaTown_EventScript_RivalTrigger_3::
	lockall
	setvar VAR_TEMP_1, 2
	setobjectxyperm 9, 19, 10
	goto AzaleaTown_EventScript_RivalTrigger_All
	return


AzaleaTown_EventScript_RivalTrigger_4::
	lockall
	setvar VAR_TEMP_1, 3
	goto AzaleaTown_EventScript_RivalTrigger_All
	return


AzaleaTown_EventScript_RivalTrigger_All::
	addobject 9
	fadenewbgm 0
	textcolor MSG_COLOR_BLUE
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	compare VAR_TEMP_1, 1
	goto_if_le AzaleaTown_EventScript_RivalTrigger_All_2
	applymovement OBJ_EVENT_ID_PLAYER, AzaleaTown_Movement_PlayerWatchRivalUp
	applymovement 9, AzaleaTown_Movement_RivalToPlayerDown
	waitmovement 0
AzaleaTown_EventScript_RivalTrigger_All_1:
	playbgm MUS_ENCOUNTER_RIVAL, 0
	savebgm MUS_RIVALEXIT
	msgbox AzaleaTown_EventScript_RivalTrigger_All_Text_0
	setvar VAR_LAST_TALKED, 9
	compare VAR_STARTER_MON, STARTER_CHIKORITA
	goto_if_eq AzaleaTown_EventScript_RivalTrigger_All_6
	compare VAR_STARTER_MON, STARTER_TOTODILE
	goto_if_eq AzaleaTown_EventScript_RivalTrigger_All_7
	compare VAR_STARTER_MON, STARTER_CYNDAQUIL
	goto_if_eq AzaleaTown_EventScript_RivalTrigger_All_8
AzaleaTown_EventScript_RivalTrigger_All_5:
	msgbox AzaleaTown_EventScript_RivalTrigger_All_Text_1
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
	compare VAR_TEMP_1, 0
	goto_if_eq AzaleaTown_EventScript_RivalTrigger_All_13
	compare VAR_TEMP_1, 2
	goto_if_eq AzaleaTown_EventScript_RivalTrigger_All_13
	applymovement 9, AzaleaTown_Movement_RivalExitLower
	waitmovement 0
AzaleaTown_EventScript_RivalTrigger_All_12:
	playse SE_EXIT
	removeobject 9
	waitse
	savebgm MUS_DUMMY
	fadedefaultbgm
	setvar VAR_AZALEA_TOWN_STATE, 2
	releaseall
	return

AzaleaTown_EventScript_RivalTrigger_All_2:
	applymovement OBJ_EVENT_ID_PLAYER, AzaleaTown_Movement_PlayerWatchRivalDown
	applymovement 9, AzaleaTown_Movement_RivalToPlayerUp
	waitmovement 0
	goto AzaleaTown_EventScript_RivalTrigger_All_1

AzaleaTown_EventScript_RivalTrigger_All_6:
	trainerbattle_wintext TRAINER_RIVAL_AZALEA_CHIKORITA, 0, AzaleaTown_Text_RivalLost, AzaleaTown_Text_RivalWon
	goto AzaleaTown_EventScript_RivalTrigger_All_5

AzaleaTown_EventScript_RivalTrigger_All_7:
	trainerbattle_wintext TRAINER_RIVAL_AZALEA_TOTODILE, 0, AzaleaTown_Text_RivalLost, AzaleaTown_Text_RivalWon
	goto AzaleaTown_EventScript_RivalTrigger_All_5

AzaleaTown_EventScript_RivalTrigger_All_8:
	trainerbattle_wintext TRAINER_RIVAL_AZALEA_CYNDAQUIL, 0, AzaleaTown_Text_RivalLost, AzaleaTown_Text_RivalWon
	goto AzaleaTown_EventScript_RivalTrigger_All_5

AzaleaTown_EventScript_RivalTrigger_All_13:
	applymovement 9, AzaleaTown_Movement_RivalExitUpper
	waitmovement 0
	goto AzaleaTown_EventScript_RivalTrigger_All_12


AzaleaTown_Movement_PlayerWatchRivalDown:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_fastest_down
	step_end

AzaleaTown_Movement_PlayerWatchRivalUp:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_fastest_up
	step_end

AzaleaTown_Movement_RivalToPlayerUp:
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

AzaleaTown_Movement_RivalToPlayerDown:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_fastest_down
	step_end

AzaleaTown_Movement_RivalExitUpper:
	walk_left
	walk_down
	walk_left
	walk_left
	step_end

AzaleaTown_Movement_RivalExitLower:
	walk_left
	walk_left
	walk_left
	step_end

AzaleaTown_EventScript_SlowpokeWell_B1FGuard::
	msgbox AzaleaTown_EventScript_SlowpokeWell_B1FGuard_Text_0, MSGBOX_NPC
	return


AzaleaTown_EventScript_OldMan::
	lock
	faceplayer
	goto_if_set FLAG_CLEARED_SLOWPOKE_WELL, AzaleaTown_EventScript_OldMan_2
	msgbox AzaleaTown_EventScript_OldMan_Text_1
AzaleaTown_EventScript_OldMan_1:
	release
	return

AzaleaTown_EventScript_OldMan_2:
	msgbox AzaleaTown_EventScript_OldMan_Text_0
	goto AzaleaTown_EventScript_OldMan_1


AzaleaTown_EventScript_Woman::
	msgbox AzaleaTown_EventScript_Woman_Text_0, MSGBOX_NPC
	return


AzaleaTown_EventScript_Youngster::
	msgbox AzaleaTown_EventScript_Youngster_Text_0, MSGBOX_NPC
	return


AzaleaTown_EventScript_Slowpoke::
	lock
	faceplayer
	message AzaleaTown_EventScript_Slowpoke_Text_0
	waitmessage
	delay 60
	waitse
	playmoncry SPECIES_SLOWPOKE, 0
	msgbox AzaleaTown_EventScript_Slowpoke_Text_1
	waitmoncry
	release
	return


AzaleaTown_EventScript_GymRocket::
	msgbox AzaleaTown_EventScript_GymRocket_Text_0, MSGBOX_NPC
	return


AzaleaTown_EventScript_TownSign::
	msgbox AzaleaTown_EventScript_TownSign_Text_0, MSGBOX_SIGN
	return


AzaleaTown_EventScript_KurtsHouseSign::
	msgbox AzaleaTown_EventScript_KurtsHouseSign_Text_0, MSGBOX_SIGN
	return


AzaleaTown_EventScript_GymSign::
	msgbox AzaleaTown_EventScript_GymSign_Text_0, MSGBOX_SIGN
	return


AzaleaTown_EventScript_SlowpokeWell_B1FSign::
	msgbox AzaleaTown_EventScript_SlowpokeWell_B1FSign_Text_0, MSGBOX_SIGN
	return


AzaleaTown_EventScript_CharcoalKilnSign::
	msgbox AzaleaTown_EventScript_CharcoalKilnSign_Text_0, MSGBOX_SIGN
	return


AzaleaTown_EventScript_IlexForestSign::
	msgbox AzaleaTown_EventScript_IlexForestSign_Text_0, MSGBOX_SIGN
	return


AzaleaTown_EventScript_RivalTrigger_All_Text_0:
	.string "…Tell me something.\p"
	.string "Is it true that TEAM ROCKET has\n"
	.string "returned?\p"
	.string "What? You beat them?\n"
	.string "Hah! Quit lying.\p"
	.string "You're not joking?\n"
	.string "Then let's see how good you are.$"

AzaleaTown_EventScript_RivalTrigger_All_Text_1:
	.string "I hate the weak.\p"
	.string "POKéMON, TRAINERS.\n"
	.string "It doesn't matter who or what.\p"
	.string "I'm going to be strong and wipe\n"
	.string "out the weak.\p"
	.string "That goes for TEAM ROCKET too.\p"
	.string "They act big and tough together, but\n"
	.string "get them alone and they're weak.\p"
	.string "I hate them all.\p"
	.string "You stay out of my way. A weakling\n"
	.string "like you is only a distraction.$"

AzaleaTown_EventScript_SlowpokeWell_B1FGuard_Text_0:
	.string "It's unsafe to go in there, so I'm\n"
	.string "standing guard.\p"
	.string "Aren't I a good Samaritan?$"

AzaleaTown_EventScript_OldMan_Text_0:
	.string "The SLOWPOKE have returned.\p"
	.string "Knowing them, they could've just\n"
	.string "been goofing off somewhere.$"

AzaleaTown_EventScript_OldMan_Text_1:
	.string "The SLOWPOKE have disappeared\n"
	.string "from town…\p"
	.string "I heard their TAILS are being\n"
	.string "sold somewhere.$"

AzaleaTown_EventScript_Woman_Text_0:
	.string "Did you come to get KURT to make\n"
	.string "some BALLS?\p"
	.string "A lot of people travel to AZALEA to\n"
	.string "do just that.$"

AzaleaTown_EventScript_Youngster_Text_0:
	.string "Cut through AZALEA and you'll be\n"
	.string "in ILEX FOREST.\p"
	.string "But these skinny trees make it\n"
	.string "impossible to get through.\p"
	.string "The CHARCOAL MAN's POKéMON can CUT\n"
	.string "down trees.$"

AzaleaTown_EventScript_Slowpoke_Text_0:
	.string "SLOWPOKE: …\n"
	.string "…… …… ……$"

AzaleaTown_EventScript_Slowpoke_Text_1:
	.string "…… ……Yawn?$"

AzaleaTown_EventScript_GymRocket_Text_0:
	.string "Do you know about SLOWPOKETAIL?\n"
	.string "I heard it's tasty!\p"
	.string "Aren't you glad I told you that?$"

AzaleaTown_EventScript_TownSign_Text_0:
	.string "AZALEA TOWN\n"
	.string "Where People and POKéMON Live in\l"
	.string "Happy Harmony$"

AzaleaTown_EventScript_KurtsHouseSign_Text_0:
	.string "KURT'S HOUSE$"

AzaleaTown_EventScript_GymSign_Text_0:
	.string "AZALEA TOWN POKéMON GYM\n"
	.string "LEADER: BUGSY\p"
	.string "The Walking BUG POKéMON\n"
	.string "Encyclopedia$"

AzaleaTown_EventScript_SlowpokeWell_B1FSign_Text_0:
	.string "SLOWPOKE WELL\n"
	.string "Also known as the RAINMAKER WELL.\p"
	.string "Locals believe that a SLOWPOKE's\n"
	.string "yawn summons rain.\p"
	.string "Records show that a SLOWPOKE's yawn\n"
	.string "ended a drought 400 years ago.$"

AzaleaTown_EventScript_CharcoalKilnSign_Text_0:
	.string "CHARCOAL KILN$"

AzaleaTown_EventScript_IlexForestSign_Text_0:
	.string "ILEX FOREST\n"
	.string "Enter through the gate.$"

AzaleaTown_Text_RivalLost::
	.string "… Humph!\n"
	.string "Useless POKéMON!\p"
	.string "Listen, you. You only won because\n"
	.string "my POKéMON were weak.$"

AzaleaTown_Text_RivalWon::
	.string "…Humph!\n"
	.string "I knew you were lying.$"
