AzaleaTown_KurtsHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, AzaleaTown_KurtsHouse_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

AzaleaTown_KurtsHouse_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	goto_if_set FLAG_CLEARED_SLOWPOKE_WELL, AzaleaTown_KurtsHouse_MapScripts_MAP_SCRIPT_ON_TRANSITION_3
	return

AzaleaTown_KurtsHouse_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
	setobjectxyperm 1, 15, 3
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_UP
	setobjectxyperm 2, 12, 4
	setobjectmovementtype 2, MOVEMENT_TYPE_FACE_RIGHT
	return

AzaleaTown_KurtsHouse_MapScripts_MAP_SCRIPT_ON_TRANSITION_2:
	goto_if_set FLAG_DAILY_KURT_MAKING_BALLS, AzaleaTown_KurtsHouse_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	return

AzaleaTown_KurtsHouse_MapScripts_MAP_SCRIPT_ON_TRANSITION_3:
	goto_if_unset FLAG_FOREST_IS_RESTLESS, AzaleaTown_KurtsHouse_MapScripts_MAP_SCRIPT_ON_TRANSITION_2
	return


AzaleaTown_KurtsHouse_EventScript_Kurt::
	lock
	faceplayer
	goto_if_unset FLAG_TEMP_1, AzaleaTown_KurtsHouse_EventScript_Kurt_8
AzaleaTown_KurtsHouse_EventScript_Kurt_7:
	goto_if_set FLAG_KURT_GAVE_LURE_BALL, AzaleaTown_KurtsHouse_EventScript_Kurt_3
	goto_if_set FLAG_CLEARED_SLOWPOKE_WELL, AzaleaTown_KurtsHouse_EventScript_Kurt_4
	msgbox AzaleaTown_KurtsHouse_EventScript_Kurt_Text_3
	closemessage
	setflag FLAG_HIDE_AZALEA_TOWN_SLOWPOKE_WELL_GUARD
	playse SE_FLEE
	compare VAR_FACING, DIR_NORTH
	goto_if_eq AzaleaTown_KurtsHouse_EventScript_Kurt_19
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestDown
	applymovement 1, AzaleaTown_KurtsHouse_Movement_KurtStraightOut
	waitmovement 0
AzaleaTown_KurtsHouse_EventScript_Kurt_18:
	playse SE_EXIT
	removeobject 1
	waitse
AzaleaTown_KurtsHouse_EventScript_Kurt_1:
	release
	return

AzaleaTown_KurtsHouse_EventScript_Kurt_2:
	goto_if_set FLAG_BUGGING_KURT_TOO_MUCH, AzaleaTown_KurtsHouse_EventScript_Kurt_12
	msgbox AzaleaTown_KurtsHouse_EventScript_Kurt_Text_1
	setflag FLAG_BUGGING_KURT_TOO_MUCH
AzaleaTown_KurtsHouse_EventScript_Kurt_11:
	turnobject 1, DIR_NORTH
	goto AzaleaTown_KurtsHouse_EventScript_Kurt_1

AzaleaTown_KurtsHouse_EventScript_Kurt_3:
	goto AzaleaTown_KurtsHouse_EventScript_Kurt_ApricornChecks
	goto AzaleaTown_KurtsHouse_EventScript_Kurt_1

AzaleaTown_KurtsHouse_EventScript_Kurt_4:
	msgbox AzaleaTown_KurtsHouse_EventScript_Kurt_Text_2
	giveitem ITEM_LURE_BALL
	compare VAR_RESULT, 0
	goto_if_eq AzaleaTown_KurtsHouse_EventScript_Kurt_15
	setflag FLAG_KURT_GAVE_LURE_BALL
	goto AzaleaTown_KurtsHouse_EventScript_Kurt_ApricornChecks
	goto AzaleaTown_KurtsHouse_EventScript_Kurt_1

AzaleaTown_KurtsHouse_EventScript_Kurt_8:
	goto_if_set FLAG_DAILY_KURT_MAKING_BALLS, AzaleaTown_KurtsHouse_EventScript_Kurt_2
	goto AzaleaTown_KurtsHouse_EventScript_Kurt_7

AzaleaTown_KurtsHouse_EventScript_Kurt_12:
	msgbox AzaleaTown_KurtsHouse_EventScript_Kurt_Text_0
	goto AzaleaTown_KurtsHouse_EventScript_Kurt_11

AzaleaTown_KurtsHouse_EventScript_Kurt_15:
	goto Common_EventScript_ShowBagIsFull
	goto AzaleaTown_KurtsHouse_EventScript_Kurt_1

AzaleaTown_KurtsHouse_EventScript_Kurt_19:
	applymovement OBJ_EVENT_ID_PLAYER, AzaleaTown_KurtsHouse_Movement_PlayerWatchesKurt
	applymovement 1, AzaleaTown_KurtsHouse_Movement_KurtAroundPlayer
	waitmovement 0
	goto AzaleaTown_KurtsHouse_EventScript_Kurt_18


AzaleaTown_KurtsHouse_EventScript_Kurt_ApricornChecks::
	goto_if_set FLAG_TEMP_1, AzaleaTown_KurtsHouse_EventScript_Kurt_ApricornChecks_2
	compare VAR_KURT_GIVEN_APRICORN, 0
	goto_if_ne AzaleaTown_KurtsHouse_EventScript_Kurt_ApricornChecks_3
	goto_if_unset FLAG_TEMP_2, AzaleaTown_KurtsHouse_EventScript_Kurt_ApricornChecks_11
AzaleaTown_KurtsHouse_EventScript_Kurt_ApricornChecks_9:
	checkitem ITEM_RED_APRICORN, 1
	compare VAR_RESULT, 0
	goto_if_ne AzaleaTown_KurtsHouse_EventScript_Kurt_ApricornChecks_15
AzaleaTown_KurtsHouse_EventScript_Kurt_ApricornChecks_14:
	checkitem ITEM_BLU_APRICORN, 1
	compare VAR_RESULT, 0
	goto_if_ne AzaleaTown_KurtsHouse_EventScript_Kurt_ApricornChecks_18
AzaleaTown_KurtsHouse_EventScript_Kurt_ApricornChecks_17:
	checkitem ITEM_YLW_APRICORN, 1
	compare VAR_RESULT, 0
	goto_if_ne AzaleaTown_KurtsHouse_EventScript_Kurt_ApricornChecks_21
AzaleaTown_KurtsHouse_EventScript_Kurt_ApricornChecks_20:
	checkitem ITEM_GRN_APRICORN, 1
	compare VAR_RESULT, 0
	goto_if_ne AzaleaTown_KurtsHouse_EventScript_Kurt_ApricornChecks_24
AzaleaTown_KurtsHouse_EventScript_Kurt_ApricornChecks_23:
	checkitem ITEM_WHT_APRICORN, 1
	compare VAR_RESULT, 0
	goto_if_ne AzaleaTown_KurtsHouse_EventScript_Kurt_ApricornChecks_27
AzaleaTown_KurtsHouse_EventScript_Kurt_ApricornChecks_26:
	checkitem ITEM_BLK_APRICORN, 1
	compare VAR_RESULT, 0
	goto_if_ne AzaleaTown_KurtsHouse_EventScript_Kurt_ApricornChecks_30
AzaleaTown_KurtsHouse_EventScript_Kurt_ApricornChecks_29:
	checkitem ITEM_PNK_APRICORN, 1
	compare VAR_RESULT, 0
	goto_if_ne AzaleaTown_KurtsHouse_EventScript_Kurt_ApricornChecks_33
AzaleaTown_KurtsHouse_EventScript_Kurt_ApricornChecks_32:
	goto_if_set FLAG_TEMP_2, AzaleaTown_KurtsHouse_EventScript_Kurt_ApricornChecks_35
	goto_if_set FLAG_TEMP_3, AzaleaTown_KurtsHouse_EventScript_Kurt_ApricornChecks_36
AzaleaTown_KurtsHouse_EventScript_Kurt_ApricornChecks_1:
	release
	return

AzaleaTown_KurtsHouse_EventScript_Kurt_ApricornChecks_2:
	call AzaleaTown_KurtsHouse_EventScript_Kurt_ItllTakeADay
	goto AzaleaTown_KurtsHouse_EventScript_Kurt_ApricornChecks_1

AzaleaTown_KurtsHouse_EventScript_Kurt_ApricornChecks_3:
	copyvar VAR_RESULT, VAR_KURT_GIVEN_APRICORN
	addvar VAR_RESULT, APRICORN_COUNT
	msgbox AzaleaTown_KurtsHouse_EventScript_Kurt_ApricornChecks_Text_0
	giveitem VAR_RESULT, VAR_KURT_GIVEN_APRICORN_QTY
	compare VAR_RESULT, 0
	goto_if_ne AzaleaTown_KurtsHouse_EventScript_Kurt_ApricornChecks_7
	goto AzaleaTown_KurtsHouse_EventScript_Kurt_ApricornChecks_1

AzaleaTown_KurtsHouse_EventScript_Kurt_ApricornChecks_7:
	msgbox AzaleaTown_KurtsHouse_Text_Kurt_TurnedOutGreat
	setvar VAR_KURT_GIVEN_APRICORN, 0
	setvar VAR_KURT_GIVEN_APRICORN_QTY, 0
	setflag FLAG_TEMP_2
	goto AzaleaTown_KurtsHouse_EventScript_Kurt_ApricornChecks_1

AzaleaTown_KurtsHouse_EventScript_Kurt_ApricornChecks_10:
	msgbox AzaleaTown_KurtsHouse_Text_Kurt_ApricornMissionStatement
	goto AzaleaTown_KurtsHouse_EventScript_Kurt_ApricornChecks_9

AzaleaTown_KurtsHouse_EventScript_Kurt_ApricornChecks_11:
	goto_if_unset FLAG_TEMP_3, AzaleaTown_KurtsHouse_EventScript_Kurt_ApricornChecks_10
	goto AzaleaTown_KurtsHouse_EventScript_Kurt_ApricornChecks_9

AzaleaTown_KurtsHouse_EventScript_Kurt_ApricornChecks_15:
	goto AzaleaTown_KurtsHouse_EventScript_Kurt_ApricornMenu
	goto AzaleaTown_KurtsHouse_EventScript_Kurt_ApricornChecks_14

AzaleaTown_KurtsHouse_EventScript_Kurt_ApricornChecks_18:
	goto AzaleaTown_KurtsHouse_EventScript_Kurt_ApricornMenu
	goto AzaleaTown_KurtsHouse_EventScript_Kurt_ApricornChecks_17

AzaleaTown_KurtsHouse_EventScript_Kurt_ApricornChecks_21:
	goto AzaleaTown_KurtsHouse_EventScript_Kurt_ApricornMenu
	goto AzaleaTown_KurtsHouse_EventScript_Kurt_ApricornChecks_20

AzaleaTown_KurtsHouse_EventScript_Kurt_ApricornChecks_24:
	goto AzaleaTown_KurtsHouse_EventScript_Kurt_ApricornMenu
	goto AzaleaTown_KurtsHouse_EventScript_Kurt_ApricornChecks_23

AzaleaTown_KurtsHouse_EventScript_Kurt_ApricornChecks_27:
	goto AzaleaTown_KurtsHouse_EventScript_Kurt_ApricornMenu
	goto AzaleaTown_KurtsHouse_EventScript_Kurt_ApricornChecks_26

AzaleaTown_KurtsHouse_EventScript_Kurt_ApricornChecks_30:
	goto AzaleaTown_KurtsHouse_EventScript_Kurt_ApricornMenu
	goto AzaleaTown_KurtsHouse_EventScript_Kurt_ApricornChecks_29

AzaleaTown_KurtsHouse_EventScript_Kurt_ApricornChecks_33:
	goto AzaleaTown_KurtsHouse_EventScript_Kurt_ApricornMenu
	goto AzaleaTown_KurtsHouse_EventScript_Kurt_ApricornChecks_32

AzaleaTown_KurtsHouse_EventScript_Kurt_ApricornChecks_35:
	msgbox AzaleaTown_KurtsHouse_Text_Kurt_TurnedOutGreat
	goto AzaleaTown_KurtsHouse_EventScript_Kurt_ApricornChecks_1

AzaleaTown_KurtsHouse_EventScript_Kurt_ApricornChecks_36:
	msgbox AzaleaTown_KurtsHouse_Text_Kurt_ApricornMissionStatement
	goto AzaleaTown_KurtsHouse_EventScript_Kurt_ApricornChecks_1


AzaleaTown_KurtsHouse_EventScript_Kurt_ApricornMenu::
	goto_if_unset FLAG_TEMP_2, AzaleaTown_KurtsHouse_EventScript_Kurt_ApricornMenu_4
AzaleaTown_KurtsHouse_EventScript_Kurt_ApricornMenu_3:
	msgbox AzaleaTown_KurtsHouse_EventScript_Kurt_ApricornMenu_Text_1
AzaleaTown_KurtsHouse_EventScript_Kurt_ApricornMenu_1:
	setflag FLAG_TEMP_3
	special SelectApricornForKurt
	waitstate
	compare VAR_KURT_GIVEN_APRICORN, 0
	goto_if_ne AzaleaTown_KurtsHouse_EventScript_Kurt_ApricornMenu_8
	msgbox AzaleaTown_KurtsHouse_EventScript_Kurt_ApricornMenu_Text_2
AzaleaTown_KurtsHouse_EventScript_Kurt_ApricornMenu_7:
	release
	return

AzaleaTown_KurtsHouse_EventScript_Kurt_ApricornMenu_2:
	msgbox AzaleaTown_KurtsHouse_EventScript_Kurt_ApricornMenu_Text_0
	goto AzaleaTown_KurtsHouse_EventScript_Kurt_ApricornMenu_1

AzaleaTown_KurtsHouse_EventScript_Kurt_ApricornMenu_4:
	goto_if_unset FLAG_TEMP_3, AzaleaTown_KurtsHouse_EventScript_Kurt_ApricornMenu_2
	goto AzaleaTown_KurtsHouse_EventScript_Kurt_ApricornMenu_3

AzaleaTown_KurtsHouse_EventScript_Kurt_ApricornMenu_8:
	setflag FLAG_TEMP_1
	setflag FLAG_DAILY_KURT_MAKING_BALLS
	call AzaleaTown_KurtsHouse_EventScript_Kurt_ItllTakeADay
	goto AzaleaTown_KurtsHouse_EventScript_Kurt_ApricornMenu_7


AzaleaTown_KurtsHouse_EventScript_Kurt_ItllTakeADay::
	msgbox AzaleaTown_KurtsHouse_EventScript_Kurt_ItllTakeADay_Text_0
	return


AzaleaTown_KurtsHouse_Movement_PlayerWatchesKurt:
	delay_8
	walk_in_place_fastest_right
	delay_8
	walk_in_place_fastest_down
	step_end

AzaleaTown_KurtsHouse_Movement_KurtAroundPlayer:
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

AzaleaTown_KurtsHouse_Movement_KurtStraightOut:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

AzaleaTown_KurtsHouse_EventScript_KurtsGranddaughter::
	lock
	faceplayer
	goto_if_set FLAG_TEMP_1, AzaleaTown_KurtsHouse_EventScript_KurtsGranddaughter_2
	goto_if_set FLAG_DAILY_KURT_MAKING_BALLS, AzaleaTown_KurtsHouse_EventScript_KurtsGranddaughter_2
	goto_if_set FLAG_TEMP_2, AzaleaTown_KurtsHouse_EventScript_KurtsGranddaughter_3
	goto_if_set FLAG_CLEARED_SLOWPOKE_WELL, AzaleaTown_KurtsHouse_EventScript_KurtsGranddaughter_4
	goto_if_set FLAG_HIDE_AZALEA_TOWN_SLOWPOKE_WELL_GUARD, AzaleaTown_KurtsHouse_EventScript_KurtsGranddaughter_5
	msgbox AzaleaTown_KurtsHouse_EventScript_KurtsGranddaughter_Text_4
AzaleaTown_KurtsHouse_EventScript_KurtsGranddaughter_1:
	release
	return

AzaleaTown_KurtsHouse_EventScript_KurtsGranddaughter_2:
	msgbox AzaleaTown_KurtsHouse_EventScript_KurtsGranddaughter_Text_0
	goto_if_unset FLAG_TEMP_1, AzaleaTown_KurtsHouse_EventScript_KurtsGranddaughter_13
	goto AzaleaTown_KurtsHouse_EventScript_KurtsGranddaughter_1

AzaleaTown_KurtsHouse_EventScript_KurtsGranddaughter_3:
	msgbox AzaleaTown_KurtsHouse_EventScript_KurtsGranddaughter_Text_1
	goto AzaleaTown_KurtsHouse_EventScript_KurtsGranddaughter_1

AzaleaTown_KurtsHouse_EventScript_KurtsGranddaughter_4:
	msgbox AzaleaTown_KurtsHouse_EventScript_KurtsGranddaughter_Text_2
	goto AzaleaTown_KurtsHouse_EventScript_KurtsGranddaughter_1

AzaleaTown_KurtsHouse_EventScript_KurtsGranddaughter_5:
	msgbox AzaleaTown_KurtsHouse_EventScript_KurtsGranddaughter_Text_3
	goto AzaleaTown_KurtsHouse_EventScript_KurtsGranddaughter_1

AzaleaTown_KurtsHouse_EventScript_KurtsGranddaughter_13:
	turnobject 2, DIR_EAST
	goto AzaleaTown_KurtsHouse_EventScript_KurtsGranddaughter_1


AzaleaTown_KurtsHouse_EventScript_OakPhoto::
	msgbox AzaleaTown_KurtsHouse_EventScript_OakPhoto_Text_0, MSGBOX_SIGN
	return


AzaleaTown_KurtsHouse_EventScript_CelebiStatue::
	msgbox AzaleaTown_KurtsHouse_EventScript_CelebiStatue_Text_0, MSGBOX_SIGN
	return


AzaleaTown_KurtsHouse_EventScript_Slowpoke::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SLOWPOKE, 0
	msgbox AzaleaTown_KurtsHouse_EventScript_Slowpoke_Text_0
	waitmoncry
	release
	return


AzaleaTown_KurtsHouse_EventScript_Kurt_Text_0:
	.string "KURT: I'm working!\n"
	.string "Don't bother me!$"

AzaleaTown_KurtsHouse_EventScript_Kurt_Text_1:
	.string "KURT: Now that my granddaughter is\n"
	.string "helping me, I can work much faster.$"

AzaleaTown_KurtsHouse_EventScript_Kurt_Text_2:
	.string "KURT: Hi, {PLAYER}!\p"
	.string "You handled yourself like a real\n"
	.string "hero at the WELL.\p"
	.string "I like your style!\p"
	.string "I would be honored to make some\n"
	.string "BALLS for a TRAINER like you.\p"
	.string "This is all I have now, but please\n"
	.string "take it.$"

AzaleaTown_KurtsHouse_EventScript_Kurt_Text_3:
	.string "Hm?\n"
	.string "Who are you?\p"
	.string "{PLAYER}, eh?\p"
	.string "You want me to make you some BALLS?\n"
	.string "Sorry, but that'll have to wait.\p"
	.string "Do you know who TEAM ROCKET is?\p"
	.string "Ah, don't worry.\n"
	.string "I'll tell you anyhow.\p"
	.string "TEAM ROCKET's an evil gang that\n"
	.string "uses POKéMON for their dirty work.\p"
	.string "They're supposed to have disbanded\n"
	.string "three years ago.\p"
	.string "Anyway, they're at the WELL, cutting\n"
	.string "off SLOWPOKETAILS for sale!\p"
	.string "So I'm going to go give them a\n"
	.string "lesson in pain!\p"
	.string "Hang on, SLOWPOKE!\n"
	.string "Old KURT is on his way!$"

AzaleaTown_KurtsHouse_EventScript_Kurt_ApricornChecks_Text_0:
	.string "KURT: Ah, {PLAYER}!\n"
	.string "I just finished your BALL. Here!$"

AzaleaTown_KurtsHouse_EventScript_Kurt_ApricornMenu_Text_0:
	.string "Oh, you have an APRICORN for me?\n"
	.string "Fine! I'll turn it into a BALL.$"

AzaleaTown_KurtsHouse_EventScript_Kurt_ApricornMenu_Text_1:
	.string "KURT: You have an APRICORN for me?\n"
	.string "Fine! I'll turn it into a BALL.$"

AzaleaTown_KurtsHouse_EventScript_Kurt_ApricornMenu_Text_2:
	.string "KURT: Oh…\n"
	.string "That's a letdown.$"

AzaleaTown_KurtsHouse_EventScript_Kurt_ItllTakeADay_Text_0:
	.string "KURT: It'll take a day to make you\n"
	.string "a BALL. Come back for it later.$"

AzaleaTown_KurtsHouse_EventScript_KurtsGranddaughter_Text_0:
	.string "I get to help Grandpa with his\n"
	.string "work now!\p"
	.string "We'll make good BALLS for you, so\n"
	.string "please wait!$"

AzaleaTown_KurtsHouse_EventScript_KurtsGranddaughter_Text_1:
	.string "It's fun to make BALLS!$"

AzaleaTown_KurtsHouse_EventScript_KurtsGranddaughter_Text_2:
	.string "The SLOWPOKE my dad gave me came\n"
	.string "back! Its TAIL is growing back too!$"

AzaleaTown_KurtsHouse_EventScript_KurtsGranddaughter_Text_3:
	.string "Grandpa's gone…\n"
	.string "I'm so lonely…$"

AzaleaTown_KurtsHouse_EventScript_KurtsGranddaughter_Text_4:
	.string "The SLOWPOKE are gone…\n"
	.string "Were they taken away by bad people?$"

AzaleaTown_KurtsHouse_EventScript_OakPhoto_Text_0:
	.string "…A young PROF. OAK?$"

AzaleaTown_KurtsHouse_EventScript_CelebiStatue_Text_0:
	.string "It's a statue of the forest's\n"
	.string "protector.$"

AzaleaTown_KurtsHouse_EventScript_Slowpoke_Text_0:
	.string "SLOWPOKE: …\n"
	.string "Yawn?$"

AzaleaTown_KurtsHouse_Text_Kurt_TurnedOutGreat::
	.string "KURT: That turned out great.\n"
	.string "Try catching POKéMON with it.$"

AzaleaTown_KurtsHouse_Text_Kurt_ApricornMissionStatement::
	.string "KURT: I make BALLS from the shells\n"
	.string "of APRICORNS.\p"
	.string "Collect them from trees and bring\n"
	.string "'em to me.\p"
	.string "I'll make BALLS out of them.$"
