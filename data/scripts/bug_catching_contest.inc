EventScript_BugContest_WhiteOut::
	special HealPlayerParty
EventScript_RanOutOfParkBalls::
	setvar VAR_BUG_CATCHING_CONTEST_STATE, 2
	setwarp MAP_NATIONAL_PARK_GATE_EAST, 0, -1, -1
	end

EventScript_CaughtButRanOutOfParkBalls::
	lockall
	message Text_BugCatchingContestRanOutOfParkBalls
	waitmessage
	waitbuttonpress
	releaseall
	goto EventScript_WarpOutOfBugCatchingContest

EventScript_BugCatchingContestTimeExpired::
	lockall
	message Text_BugCatchingContestTimeExpired
	waitmessage
	waitbuttonpress
	releaseall
	goto EventScript_WarpOutOfBugCatchingContest

EventScript_WarpOutOfBugCatchingContest::
	setvar VAR_BUG_CATCHING_CONTEST_STATE, 2
	warp MAP_NATIONAL_PARK_GATE_EAST, 0, -1, -1
	waitstate
	end

EventScript_ReturnBugCatchingContestMons::
	setvar VAR_0x8004, 6
	special CallFrontierUtilFunc
	special LoadPlayerParty
	return

BugCatchingContest_StartMenuPrompt::
	lockall
	msgbox Text_StartMenu_ExitBugCatchingContest, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq EventScript_WarpOutOfBugCatchingContest
	releaseall
	end

BugContestOfficer_EnterContest::
	compare VAR_BUG_CONTEST_PRIZE, ITEM_NONE
	goto_if_ne BugContestOfficer_GivePrizeItem
	goto_if_set FLAG_DAILY_BUG_CATCHING_CONTEST, BugContestOfficer_ContestIsOver
	special CopyCurrentDayOfWeekStringToVar1
	msgbox BugContestOfficer_Text_ContestIntro, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq BugContestOfficer_SaidNoToParticipating
	specialvar VAR_RESULT, IsPlayerPartyAndPokemonStorageFull
	compare VAR_RESULT, 1
	goto_if_eq BugContestOfficer_PartyAndBoxFull
	msgbox BugContestOfficer_Text_ChoosePokemon, MSGBOX_DEFAULT
	special SavePlayerParty
	fadescreen 1
	special SelectBugCatchingContestMon
	waitstate
	compare VAR_RESULT, 0
	goto_if_ne NationalParkGateSouth_BugContestOfficer_ChosePokemon
	special LoadPlayerParty
	msgbox BugContestOfficer_Text_ComeSeeMeLater, MSGBOX_DEFAULT
	setvar VAR_RESULT, 0
	return

BugContestOfficer_GivePrizeItem::
	bufferitemname 0, VAR_BUG_CONTEST_PRIZE
	msgbox BugContestOfficer_Text_GivePrizeItem, MSGBOX_DEFAULT
	giveitem_std VAR_BUG_CONTEST_PRIZE
	compare VAR_RESULT, 0
	goto_if_eq BugContestOfficer_NoRoomForPrize
	setvar VAR_BUG_CONTEST_PRIZE, ITEM_NONE
	return

BugContestOfficer_NoRoomForPrize:
	msgbox BugContestOfficer_Text_NoRoomInBag, MSGBOX_DEFAULT
	return

NationalParkGateSouth_BugContestOfficer_ChosePokemon:
	special ReducePlayerPartyToSelectedMons
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 4
	special CallFrontierUtilFunc
	msgbox BugContestOfficer_Text_HereAreTheParkBalls, MSGBOX_DEFAULT
	playfanfare MUS_FANFA4
	message BugContestOfficer_Text_ReceivedParkBalls
	waitfanfare
	msgbox BugContestOfficer_Text_SendOff, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_DAILY_BUG_CATCHING_CONTEST
	setvar VAR_BUG_CATCHING_CONTEST_STATE, 1
	special EnterBugCatchingContest
	setvar VAR_RESULT, 1
	return

BugContestOfficer_ContestIsOver::
	msgbox BugContestOfficer_Text_ContestIsOver, MSGBOX_DEFAULT
	setvar VAR_RESULT, 0
	return

BugContestOfficer_SaidNoToParticipating:
	msgbox BugContestOfficer_Text_TakePartInFuture, MSGBOX_DEFAULT
	setvar VAR_RESULT, 0
	return

BugContestOfficer_PartyAndBoxFull:
	msgbox BugContestOfficer_Text_PartyAndBoxFull, MSGBOX_DEFAULT
	setvar VAR_RESULT, 0
	return

Text_BugCatchingContestRanOutOfParkBalls:
	.string "You ran out of PARK BALLs.$"

Text_BugCatchingContestTimeExpired:
	.string "Time's up for the Bug-Catching\n"
	.string "Contest!\p"
	.string "All contestants should report to\n"
	.string "to the North Gate.$"

Text_StartMenu_ExitBugCatchingContest:
	.string "Would you like to end the Bug\n"
	.string "Catching Contest right now?$"

BugContestOfficer_Text_ContestIntro:
	.string "Today is {STR_VAR_1}.\p"
	.string "That means the Bug-Catching Contest\n"
	.string "is on today.\p"
	.string "The rules are simple.\p"
	.string "Using one of your POKéMON, catch a\n"
	.string "bug POKéMON to be judged.\p"
	.string "Would you like to give it a try?$"

BugContestOfficer_Text_ChoosePokemon:
	.string "Please choose one POKéMON to bring\n"
	.string "into the contest.\p"
	.string "We'll hold onto the others until the\n"
	.string "contest is finshed.$"

BugContestOfficer_Text_ComeSeeMeLater:
	.string "Come see me again if you decide\n"
	.string "to participate in the contest.$"

BugContestOfficer_Text_HereAreTheParkBalls:
	.string "Here are the PARK BALLS for the\n"
	.string "contest.$"

BugContestOfficer_Text_ReceivedParkBalls:
	.string "{PLAYER} received 20 PARK BALLS.$"

BugContestOfficer_Text_SendOff:
	.string "The person who catches the best bug\n"
	.string "POKéMON will be the winner.\p"
	.string "You have 20 minutes.\p"
	.string "If you run out of PARK BALLS,\n"
	.string "you're done.\p"
	.string "You can keep the last POKéMON you\n"
	.string "catch as your own.\p"
	.string "Go out and catch the best bug\n"
	.string "POKéMON you can find!$"

BugContestOfficer_Text_ContestIsOver::
	.string "Today's bug catching contest is\n"
	.string "over.\p"
	.string "We hope you will participate\n"
	.string "in the future.$"

BugContestOfficer_Text_TakePartInFuture:
	.string "Ok. We hope you'll take part in the\n"
	.string "future.$"

BugContestOfficer_Text_PartyAndBoxFull:
	.string "Sorry, but you have no more room in\n"
	.string "your party or PC, so you won't be\l"
	.string "able to catch any bug POKéMON!\p"
	.string "Come back later when you have\n"
	.string "room.$"

BugContestOfficer_Text_GivePrizeItem:
	.string "{PLAYER}, I have your prize\n"
	.string "{STR_VAR_1} from the last contest\l"
	.string "right here.$"

BugContestOfficer_Text_NoRoomInBag:
	.string "Your BAG is still full…\n"
	.string "Please make room for your prize.$"
