Route32_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route32_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

Route32_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	gettime
	compare VAR_0x8003, DAY_FRIDAY
	goto_if_eq Route32_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	setflag FLAG_HIDE_ROUTE_32_FRIEDA
	return

Route32_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
	clearflag FLAG_HIDE_ROUTE_32_FRIEDA
	return


Route32_EventScript_RoadblockManTrigger_1::
	lockall
	setvar VAR_TEMP_1, 0
	goto Route32_EventScript_RoadblockManTrigger_All
	return


Route32_EventScript_RoadblockManTrigger_2::
	lockall
	setvar VAR_TEMP_1, 1
	goto Route32_EventScript_RoadblockManTrigger_All
	return


Route32_EventScript_RoadblockManTrigger_All::
	playse SE_PIN
	applymovement 1, Route32_Movement_RoadblockMan_NoticePlayer
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	textcolor MSG_COLOR_BLUE
	msgbox Route32_EventScript_RoadblockManTrigger_All_Text_0
	closemessage
	compare VAR_TEMP_1, 0
	goto_if_eq Route32_EventScript_RoadblockManTrigger_All_2
	applymovement OBJ_EVENT_ID_PLAYER, Route32_Movement_RoadblockMan_PlayerFromRight
	applymovement 1, Route32_Movement_RoadblockMan_ManFromRight
	waitmovement 0
Route32_EventScript_RoadblockManTrigger_All_1:
	call Route32_EventScript_RoadblockMan_Common
	closemessage
	compare VAR_TEMP_1, 0
	goto_if_eq Route32_EventScript_RoadblockManTrigger_All_6
	applymovement 1, Route32_Movement_RoadblockMan_ManResetFromRight
	waitmovement 0
Route32_EventScript_RoadblockManTrigger_All_5:
	releaseall
	return

Route32_EventScript_RoadblockManTrigger_All_2:
	applymovement OBJ_EVENT_ID_PLAYER, Route32_Movement_RoadblockMan_PlayerFromLeft
	applymovement 1, Route32_Movement_RoadblockMan_ManFromLeft
	waitmovement 0
	goto Route32_EventScript_RoadblockManTrigger_All_1

Route32_EventScript_RoadblockManTrigger_All_6:
	applymovement 1, Route32_Movement_RoadblockMan_ManResetFromLeft
	waitmovement 0
	goto Route32_EventScript_RoadblockManTrigger_All_5


Route32_EventScript_RoadblockMan::
	lock
	faceplayer
	call Route32_EventScript_RoadblockMan_Common
	release
	return


Route32_EventScript_RoadblockMan_Common::
	goto_if_set FLAG_GOT_MIRACLE_SEED_ROUTE_32, Route32_EventScript_RoadblockMan_Common_1
	goto_if_unset FLAG_BADGE01_GET, Route32_EventScript_RoadblockMan_Common_2
	goto_if_set FLAG_GOT_ELMS_EGG, Route32_EventScript_RoadblockMan_Common_3
	msgbox Route32_EventScript_RoadblockMan_Common_Text_2
	return

Route32_EventScript_RoadblockMan_Common_1:
	call Route32_EventScript_RoadblockMan_AfterItem
	return

Route32_EventScript_RoadblockMan_Common_2:
	msgbox Route32_EventScript_RoadblockMan_Common_Text_0
	return

Route32_EventScript_RoadblockMan_Common_3:
	msgbox Route32_EventScript_RoadblockMan_Common_Text_1
	giveitem ITEM_MIRACLE_SEED
	compare VAR_RESULT, 0
	goto_if_eq Route32_EventScript_RoadblockMan_Common_8
	setflag FLAG_GOT_MIRACLE_SEED_ROUTE_32
	call Route32_EventScript_RoadblockMan_AfterItem
	return

Route32_EventScript_RoadblockMan_Common_8:
	goto Common_EventScript_ShowBagIsFull
	return


Route32_EventScript_RoadblockMan_AfterItem::
	msgbox Route32_EventScript_RoadblockMan_AfterItem_Text_0
	return


Route32_Movement_RoadblockMan_NoticePlayer:
	emote_exclamation_mark
	face_left
	step_end

Route32_Movement_RoadblockMan_PlayerFromLeft:
	delay_16
	walk_up
	walk_up
	face_down
	step_end

Route32_Movement_RoadblockMan_ManFromLeft:
	walk_left
	walk_left
	walk_up
	step_end

Route32_Movement_RoadblockMan_PlayerFromRight:
	walk_up
	walk_up
	face_down
	step_end

Route32_Movement_RoadblockMan_ManFromRight:
	walk_left
	walk_up
	step_end

Route32_Movement_RoadblockMan_ManResetFromLeft:
	walk_down
	walk_right
	walk_right
	face_left
	step_end

Route32_Movement_RoadblockMan_ManResetFromRight:
	walk_down
	walk_right
	face_left
	step_end

Route32_EventScript_SlowpokeTailManTrigger1::
	lockall
	setvar VAR_TEMP_1, 0
	goto Route32_EventScript_SlowpokeTailManTrigger_All
	return


Route32_EventScript_SlowpokeTailManTrigger2::
	lockall
	setvar VAR_TEMP_1, 1
	goto Route32_EventScript_SlowpokeTailManTrigger_All
	return


Route32_EventScript_SlowpokeTailManTrigger_All::
	textcolor MSG_COLOR_BLUE
	playse SE_PIN
	applymovement 12, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 12, Common_Movement_Delay48
	waitmovement 0
	msgbox Route32_EventScript_SlowpokeTailManTrigger_All_Text_0
	compare VAR_TEMP_1, 0
	goto_if_eq Route32_EventScript_SlowpokeTailManTrigger_All_2
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Route32_Movement_StepUp
	waitmovement 0
Route32_EventScript_SlowpokeTailManTrigger_All_1:
	call Route32_EventScript_SlowpokeTailMan_Common
	releaseall
	return

Route32_EventScript_SlowpokeTailManTrigger_All_2:
	applymovement OBJ_EVENT_ID_PLAYER, Route32_Movement_FaceUp
	waitmovement 0
	goto Route32_EventScript_SlowpokeTailManTrigger_All_1


Route32_Movement_FaceUp:
	walk_in_place_fastest_up
	step_end

Route32_Movement_StepUp:
	walk_up
	step_end

Route32_EventScript_SlowpokeTailMan::
	lock
	faceplayer
	call Route32_EventScript_SlowpokeTailMan_Common
	release
	return


Route32_EventScript_SlowpokeTailMan_Common::
	setvar VAR_ROUTE32_STATE, 2
	showmoneybox 0, 0, 0
	msgbox Route32_EventScript_SlowpokeTailMan_Common_Text_0, MSGBOX_YESNO
	hidemoneybox
	compare VAR_RESULT, YES
	goto_if_eq Route32_EventScript_SlowpokeTailMan_Common_1
	msgbox Route32_EventScript_SlowpokeTailMan_Common_Text_2
	return

Route32_EventScript_SlowpokeTailMan_Common_1:
	msgbox Route32_EventScript_SlowpokeTailMan_Common_Text_1
	return


Route32_EventScript_RoarTMGuy::
	lock
	faceplayer
	goto_if_unset FLAG_RECEIVED_TM05_ROAR, Route32_EventScript_RoarTMGuy_2
Route32_EventScript_RoarTMGuy_1:
	msgbox Route32_EventScript_RoarTMGuy_Text_1
	release
	return

Route32_EventScript_RoarTMGuy_2:
	msgbox Route32_EventScript_RoarTMGuy_Text_0
	giveitem ITEM_TM05
	compare VAR_RESULT, 0
	goto_if_eq Route32_EventScript_RoarTMGuy_4
	setflag FLAG_RECEIVED_TM05_ROAR
	goto Route32_EventScript_RoarTMGuy_1

Route32_EventScript_RoarTMGuy_4:
	goto Common_EventScript_ShowBagIsFull
	goto Route32_EventScript_RoarTMGuy_1


Route32_EventScript_Frieda::
	lock
	faceplayer
	goto_if_unset FLAG_RECEIVED_POISON_BARB_FROM_FRIEDA, Route32_EventScript_Frieda_2
	msgbox Route32_EventScript_Frieda_Text_4
Route32_EventScript_Frieda_1:
	release
	return

Route32_EventScript_Frieda_2:
	gettime
	compare VAR_0x8003, DAY_FRIDAY
	goto_if_eq Route32_EventScript_Frieda_5
	msgbox Route32_EventScript_Frieda_Text_3
	goto Route32_EventScript_Frieda_1

Route32_EventScript_Frieda_5:
	goto_if_unset FLAG_MET_FRIEDA_OF_FRIDAY, Route32_EventScript_Frieda_9
	msgbox Route32_EventScript_Frieda_Text_1
Route32_EventScript_Frieda_8:
	giveitem ITEM_POISON_BARB
	compare VAR_RESULT, 0
	goto_if_eq Route32_EventScript_Frieda_13
Route32_EventScript_Frieda_12:
	setflag FLAG_RECEIVED_POISON_BARB_FROM_FRIEDA
	msgbox Route32_EventScript_Frieda_Text_2
	goto Route32_EventScript_Frieda_1

Route32_EventScript_Frieda_9:
	msgbox Route32_EventScript_Frieda_Text_0
	setflag FLAG_MET_FRIEDA_OF_FRIDAY
	goto Route32_EventScript_Frieda_8

Route32_EventScript_Frieda_13:
	goto Common_EventScript_ShowBagIsFull
	goto Route32_EventScript_Frieda_12


Route32_EventScript_Albert::
	trainerbattle_single TRAINER_ALBERT, Route32_Text_AlbertIntro, Route32_Text_AlbertDefeat
	msgbox Route32_Text_AlbertPostBattle, MSGBOX_DEFAULT
	release
	return


Route32_EventScript_Liz::
	trainerbattle_single TRAINER_LIZ_1, Route32_Text_LizIntro, Route32_Text_LizDefeat
	msgbox Route32_Text_LizPostBattle, MSGBOX_DEFAULT
	release
	return


Route32_EventScript_Roland::
	trainerbattle_single TRAINER_ROLAND, Route32_Text_RolandIntro, Route32_Text_RolandDefeat
	msgbox Route32_Text_RolandPostBattle, MSGBOX_DEFAULT
	release
	return


Route32_EventScript_Henry::
	trainerbattle_single TRAINER_HENRY, Route32_Text_HenryIntro, Route32_Text_HenryDefeat
	msgbox Route32_Text_HenryPostBattle, MSGBOX_DEFAULT
	release
	return


Route32_EventScript_Justin::
	trainerbattle_single TRAINER_JUSTIN, Route32_Text_JustinIntro, Route32_Text_JustinDefeat
	msgbox Route32_Text_JustinPostBattle, MSGBOX_DEFAULT
	release
	return


Route32_EventScript_Ralph::
	trainerbattle_single TRAINER_RALPH_1, Route32_Text_RalphIntro, Route32_Text_RalphDefeat
	msgbox Route32_Text_RalphPostBattle, MSGBOX_DEFAULT
	release
	return


Route32_EventScript_Gordon::
	trainerbattle_single TRAINER_GORDON, Route32_Text_GordonIntro, Route32_Text_GordonDefeat
	msgbox Route32_Text_GordonPostBattle, MSGBOX_DEFAULT
	release
	return


Route32_EventScript_Peter::
	trainerbattle_single TRAINER_PETER, Route32_Text_PeterIntro, Route32_Text_PeterDefeat
	msgbox Route32_Text_PeterPostBattle, MSGBOX_DEFAULT
	release
	return


Route32_EventScript_RuinsOfAlphSign::
	msgbox Route32_EventScript_RuinsOfAlphSign_Text_0, MSGBOX_SIGN
	return


Route32_EventScript_DirectionsSign::
	msgbox Route32_EventScript_DirectionsSign_Text_0, MSGBOX_SIGN
	return


Route32_EventScript_UnionCaveSign::
	msgbox Route32_EventScript_UnionCaveSign_Text_0, MSGBOX_SIGN
	return


Route32_EventScript_RoadblockManTrigger_All_Text_0:
	.string "Wait up!\n"
	.string "What's the hurry?$"

Route32_EventScript_RoadblockMan_Common_Text_0:
	.string "Have you gone to the POKéMON\n"
	.string "GYM in VIOLET yet?\p"
	.string "You can test your POKéMON and\n"
	.string "yourself there.\p"
	.string "It's a rite of passage for all\n"
	.string "TRAINERS!$"

Route32_EventScript_RoadblockMan_Common_Text_1:
	.string "Looks like you have some good\n"
	.string "POKéMON there.\p"
	.string "It must be from the training you\n"
	.string "gave them around VIOLET CITY.\p"
	.string "The training at the GYM must have\n"
	.string "been especially helpful.\p"
	.string "As a souvenir of VIOLET CITY,\n"
	.string "take this.\p"
	.string "It increases the power of GRASS-\n"
	.string "type moves.$"

Route32_EventScript_RoadblockMan_Common_Text_2:
	.string "{PLAYER}, right?\n"
	.string "Some guy wearing glasses was\l"
	.string "looking for you.\p"
	.string "Go see for yourself. He's waiting\n"
	.string "for you at the POKéMON CENTER.$"

Route32_EventScript_RoadblockMan_AfterItem_Text_0:
	.string "Your experiences in VIOLET CITY\n"
	.string "should be useful for your journey.$"

Route32_EventScript_SlowpokeTailManTrigger_All_Text_0:
	.string "Hey, kid!\n"
	.string "Hold on a sec!$"

Route32_EventScript_SlowpokeTailMan_Common_Text_0:
	.string "How would you like to have this\n"
	.string "tasty, nutritious SLOWPOKETAIL?\p"
	.string "For you right now, it costs just\n"
	.string "¥1,000,000!\p"
	.string "You'll want this!$"

Route32_EventScript_SlowpokeTailMan_Common_Text_1:
	.string "Tch! And here I thought kids these\n"
	.string "days were loaded…$"

Route32_EventScript_SlowpokeTailMan_Common_Text_2:
	.string "You don't want it? You're sure?\n"
	.string "Then scram. Shoo!$"

Route32_EventScript_RoarTMGuy_Text_0:
	.string "WROOOOAR!\p"
	.string "PEOPLE RUN WHEN I ROAR!\n"
	.string "BUT YOU CAME LOOKING!\p"
	.string "THAT PLEASES ME!\n"
	.string "NOW TAKE THIS!$"

Route32_EventScript_RoarTMGuy_Text_1:
	.string "WROOOAR!\n"
	.string "IT'S ROAR!\p"
	.string "EVEN POKéMON WILL RUN FROM A\n"
	.string "GOOD ROAR!$"

Route32_EventScript_Frieda_Text_0:
	.string "FRIEDA: Yahoo!\n"
	.string "It's FRIDAY!\p"
	.string "I'm FRIEDA of FRIDAY!\n"
	.string "Nice to meet you!\p"
	.string "Here's a POISON BARB for you!$"

Route32_EventScript_Frieda_Text_1:
	.string "FRIEDA:Here's a POISON BARB\n"
	.string "for you!$"

Route32_EventScript_Frieda_Text_2:
	.string "FRIEDA: Give it to a POKéMON that\n"
	.string "has POISON-type moves.\p"
	.string "Oh!\n"
	.string "It's wicked!\p"
	.string "You'll be shocked how good it makes\n"
	.string "POISON-type moves!$"

Route32_EventScript_Frieda_Text_3:
	.string "FRIEDA: Isn't it FRIDAY today?\n"
	.string "It's so boring when it's not!$"

Route32_EventScript_Frieda_Text_4:
	.string "FRIEDA: Hiya!\n"
	.string "What day do you like?\p"
	.string "I love FRIDAY.\n"
	.string "There's no doubt about it!\p"
	.string "Don't you think it's great too?$"

Route32_EventScript_RuinsOfAlphSign_Text_0:
	.string "RUINS OF ALPH\n"
	.string "EAST ENTRANCE$"

Route32_EventScript_DirectionsSign_Text_0:
	.string "ROUTE 32\n"
	.string "VIOLET CITY - AZALEA TOWN$"

Route32_EventScript_UnionCaveSign_Text_0:
	.string "UNION CAVE AHEAD$"
