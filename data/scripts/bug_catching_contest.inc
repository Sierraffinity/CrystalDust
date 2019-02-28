EventScript_RanOutOfParkBalls::
	setwarp MAP_NEW_BARK_TOWN, -1, 3, 3
	end

EventScript_CaughtButRanOutOfParkBalls::
	lockall
	playse SE_PINPON
	message Text_BugCatchingContestRanOutOfParkBalls
	waitmessage
	waitbuttonpress
	releaseall
	goto EventScript_WarpOutOfBugCatchingContest

EventScript_BugCatchingContestTimeExpired::
	lockall
	playse SE_PINPON
	message Text_BugCatchingContestTimeExpired
	waitmessage
	waitbuttonpress
	releaseall
	goto EventScript_WarpOutOfBugCatchingContest

EventScript_WarpOutOfBugCatchingContest::
	warp MAP_NEW_BARK_TOWN, -1, 3, 3
	waitstate
	end

EventScript_SelectBugCatchingContestMon::
	special SavePlayerParty
	fadescreen 1
	callnative SelectBugCatchingContestMon
	waitstate
	compare VAR_RESULT, 0
	goto_if_ne BugCatchingContest_ChoseMon
	special LoadPlayerParty
	release
	end

BugCatchingContest_ChoseMon::
	special ReducePlayerPartyToSelectedMons
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 4
	special CallFrontierUtilFunc
	callnative EnterBugCatchingContest
	msgbox Text_BugCatchingContestStart, MSGBOX_DEFAULT
	release
	end

EventScript_ReturnBugCatchingContestMons::
	setvar VAR_0x8004, 6
	special CallFrontierUtilFunc
	special LoadPlayerParty
	return

Text_BugCatchingContestRanOutOfParkBalls:
	.string "You ran out of PARK BALLs.$"

Text_BugCatchingContestTimeExpired:
	.string "Time's up for the bug\n"
	.string "catching contest.$"

Text_BugCatchingContestStart::
	.string "Start contest.$"
