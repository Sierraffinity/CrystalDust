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

Text_BugCatchingContestRanOutOfParkBalls:
	.string "You ran out of PARK BALLs.$"

Text_BugCatchingContestTimeExpired:
	.string "Time's up for the bug\n"
	.string "catching contest.$"

Text_BugCatchingContestStart::
	.string "Start contest.$"

Text_StartMenu_ExitBugCatchingContest:
	.string "Would you like to end the Bug\n"
	.string "Catching Contest right now?$"
