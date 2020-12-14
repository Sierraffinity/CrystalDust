EventScript_BugContest_WhiteOut::
	special HealPlayerParty
	goto EventScript_RanOutOfParkBalls
	return


EventScript_RanOutOfParkBalls::
	setvar VAR_BUG_CATCHING_CONTEST_STATE, 2
	setwarp MAP_ROUTE36_NATIONAL_PARK_GATEHOUSE, 0, -1, -1
	return


EventScript_CaughtButRanOutOfParkBalls::
	lockall
	playse SE_DING_DONG
	msgbox EventScript_CaughtButRanOutOfParkBalls_Text_0
	call EventScript_WarpOutOfBugCatchingContest
	releaseall
	return


EventScript_BugCatchingContestTimeExpired::
	lockall
	playse SE_DING_DONG
	msgbox EventScript_BugCatchingContestTimeExpired_Text_0
	goto EventScript_WarpOutOfBugCatchingContest
	return


EventScript_WarpOutOfBugCatchingContestHeal::
	special HealPlayerParty
	setvar VAR_BUG_CATCHING_CONTEST_STATE, 2
	warpsilent MAP_ROUTE36_NATIONAL_PARK_GATEHOUSE, 0, -1, -1
	waitstate
	return


EventScript_ReturnBugCatchingContestMons::
	frontier_saveparty
	special LoadPlayerParty
	return


BugCatchingContest_StartMenuPrompt::
	lockall
	msgbox BugCatchingContest_StartMenuPrompt_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq BugCatchingContest_StartMenuPrompt_2
BugCatchingContest_StartMenuPrompt_1:
	releaseall
	return

BugCatchingContest_StartMenuPrompt_2:
	goto EventScript_WarpOutOfBugCatchingContest
	goto BugCatchingContest_StartMenuPrompt_1


EventScript_WarpOutOfBugCatchingContest::
	setvar VAR_BUG_CATCHING_CONTEST_STATE, 2
	warp MAP_ROUTE36_NATIONAL_PARK_GATEHOUSE, 0, -1, -1
	waitstate
	return


BugCatchingContest_EventScript_Officer_EnterContest::
	special CopyCurrentDayOfWeekStringToVar1
	msgbox BugCatchingContest_EventScript_Officer_EnterContest_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq BugCatchingContest_EventScript_Officer_EnterContest_1
	goto BugCatchingContest_EventScript_Officer_DeclinedToParticipate
	return

BugCatchingContest_EventScript_Officer_EnterContest_1:
	specialvar VAR_RESULT, IsPlayerPartyAndPokemonStorageFull
	compare VAR_RESULT, TRUE
	goto_if_eq BugCatchingContest_EventScript_Officer_EnterContest_4
	specialvar VAR_RESULT, CalculatePlayerPartyCount
	compare VAR_RESULT, 1
	goto_if_ne BugCatchingContest_EventScript_Officer_EnterContest_8
BugCatchingContest_EventScript_Officer_EnterContest_7:
	playbgm MUS_BUG_CONTEST_PREP, 0
	msgbox BugCatchingContest_EventScript_Officer_EnterContest_Text_4
	textcolor MSG_COLOR_SYS
	playfanfare MUS_OBTAIN_ITEM
	message BugCatchingContest_EventScript_Officer_EnterContest_Text_5
	waitfanfare
	textcolor MSG_COLOR_PREV
	msgbox BugCatchingContest_EventScript_Officer_EnterContest_Text_6
	closemessage
	setflag FLAG_DAILY_BUG_CATCHING_CONTEST
	setflag FLAG_IN_BUG_CATCHING_CONTEST
	setvar VAR_BUG_CATCHING_CONTEST_STATE, 1
	special EnterBugCatchingContest
	setvar VAR_RESULT, 1
	return

BugCatchingContest_EventScript_Officer_EnterContest_4:
	msgbox BugCatchingContest_EventScript_Officer_EnterContest_Text_1
	setvar VAR_RESULT, 0
	return

BugCatchingContest_EventScript_Officer_EnterContest_8:
	msgbox BugCatchingContest_EventScript_Officer_EnterContest_Text_2
	special SavePlayerParty
	fadescreen 1
	special SelectBugCatchingContestMon
	waitstate
	compare VAR_RESULT, 0
	goto_if_eq BugCatchingContest_EventScript_Officer_EnterContest_11
	special ReducePlayerPartyToSelectedMons
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
BugCatchingContest_EventScript_Officer_EnterContest_10:
	textcolor MSG_COLOR_SYS
	playse SE_ROTATING_GATE
	msgbox BugCatchingContest_EventScript_Officer_EnterContest_Text_3
	textcolor MSG_COLOR_PREV
	setflag FLAG_LEFT_MONS_WITH_CONTEST_OFFICER
	goto BugCatchingContest_EventScript_Officer_EnterContest_7

BugCatchingContest_EventScript_Officer_EnterContest_11:
	special LoadPlayerParty
	goto BugCatchingContest_EventScript_Officer_DeclinedToParticipate
	goto BugCatchingContest_EventScript_Officer_EnterContest_10


BugCatchingContest_EventScript_Officer_DeclinedToParticipate::
	msgbox BugCatchingContest_EventScript_Officer_DeclinedToParticipate_Text_0
	setvar VAR_RESULT, 0
	return


BugCatchingContest_EventScript_Officer_GivePrizeItem::
	bufferitemname 0, VAR_BUG_CONTEST_PRIZE
	msgbox BugCatchingContest_EventScript_Officer_GivePrizeItem_Text_0
	giveitem VAR_BUG_CONTEST_PRIZE
	compare VAR_RESULT, FALSE
	goto_if_eq BugCatchingContest_EventScript_Officer_GivePrizeItem_1
	setvar VAR_BUG_CONTEST_PRIZE, ITEM_NONE
	return

BugCatchingContest_EventScript_Officer_GivePrizeItem_1:
	msgbox BugCatchingContest_EventScript_Officer_GivePrizeItem_Text_1
	return


BugCatchingContest_EventScript_ContestSign::
	msgbox BugCatchingContest_EventScript_ContestSign_Text_0, MSGBOX_SIGN
	return


EventScript_CaughtButRanOutOfParkBalls_Text_0:
	.string "ANNOUNCER: The Contest is over!$"

EventScript_BugCatchingContestTimeExpired_Text_0:
	.string "ANNOUNCER: BEEEP!\n"
	.string "Time's up!$"

BugCatchingContest_StartMenuPrompt_Text_0:
	.string "Would you like to end the Bug\n"
	.string "Catching Contest right now?$"

BugCatchingContest_EventScript_Officer_EnterContest_Text_0:
	.string "Today's {STR_VAR_1}, which means the\n"
	.string "Bug-Catching Contest is on today.\p"
	.string "The rules are simple.\p"
	.string "Using one of your POKéMON, catch a\n"
	.string "BUG POKéMON to be judged.\p"
	.string "Would you like to give it a try?$"

BugCatchingContest_EventScript_Officer_EnterContest_Text_1:
	.string "Uh-oh… Both your party and your PC\n"
	.string "BOX are full.\p"
	.string "You have no room to put the BUG\n"
	.string "POKéMON you catch.\p"
	.string "Please make room in your party or PC\n"
	.string "BOX, then come see me.$"

BugCatchingContest_EventScript_Officer_EnterContest_Text_2:
	.string "Please choose a POKéMON to bring\n"
	.string "into the contest.\p"
	.string "We'll hold onto your other POKéMON\n"
	.string "while you compete.$"

BugCatchingContest_EventScript_Officer_EnterContest_Text_3:
	.string "{PLAYER}'s POKéMON were left with\n"
	.string "the CONTEST HELPER.$"

BugCatchingContest_EventScript_Officer_EnterContest_Text_4:
	.string "Here are the PARK BALLS for the\n"
	.string "Contest.$"

BugCatchingContest_EventScript_Officer_EnterContest_Text_5:
	.string "{PLAYER} received 20 PARK BALLS\n"
	.string "from the CONTEST HELPER.$"

BugCatchingContest_EventScript_Officer_EnterContest_Text_6:
	.string "The person who catches the best\n"
	.string "BUG POKéMON will be the winner.\p"
	.string "You have 20 minutes, and if you run\n"
	.string "out of PARK BALLS, you're done.\p"
	.string "You can keep the last POKéMON you\n"
	.string "catch as your own.\p"
	.string "Go out and catch the best BUG\n"
	.string "POKéMON you can find!$"

BugCatchingContest_EventScript_Officer_DeclinedToParticipate_Text_0:
	.string "Okay. We hope you'll take part in\n"
	.string "the future.$"

BugCatchingContest_EventScript_Officer_GivePrizeItem_Text_0:
	.string "{PLAYER}? Here's your prize\n"
	.string "{STR_VAR_1} from the last Contest.$"

BugCatchingContest_EventScript_Officer_GivePrizeItem_Text_1:
	.string "Your BAG is still full…\n"
	.string "Please make room for your prize.$"

BugCatchingContest_EventScript_ContestSign_Text_0:
	.string "The Bug-Catching Contest is held on\n"
	.string "TUESDAY, THURSDAY and SATURDAY.\p"
	.string "Not only do you earn a prize just\n"
	.string "for participating, you also get to\l"
	.string "keep the BUG POKéMON you may\l"
	.string "have at the end of the contest.$"

BugCatchingContest_Text_Officer_DoYouWantToFinishOneMinute::
	.string "The Contest is still going for\n"
	.string "another minute or so.\p"
	.string "Do you want to finish now?$"

BugCatchingContest_Text_Officer_DoYouWantToFinishMinutes::
	.string "The Contest is still going for\n"
	.string "another {STR_VAR_1} minutes.\p"
	.string "Do you want to finish now?$"

BugCatchingContest_Text_Officer_GetBackOutside::
	.string "Okay. Please get back outside and\n"
	.string "finish up.$"

BugCatchingContest_Text_Officer_ContestIsOver::
	.string "Today's Bug-Catching Contest is\n"
	.string "over.\p"
	.string "We hope you will participate\n"
	.string "in the future.$"
