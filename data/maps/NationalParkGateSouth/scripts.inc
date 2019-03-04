NationalParkGateSouth_MapScripts::
	map_script 1, NationalParkGateSouth_OnLoad
	map_script 2, NationalParkGateSouth_OnFrame_Table
	.byte 0

NationalParkGateSouth_OnLoad:
	compare	VAR_BUG_CATCHING_CONTEST_STATE, 1
	goto_if_eq NationalParkGateSouth_OnLoad_SetObjectVisibility_BugContest
	gettime
	switch VAR_0x8003
	case DAY_TUESDAY, NationalParkGateSouth_OnLoad_SetObjectVisibility_BugContest
	case DAY_THURSDAY, NationalParkGateSouth_OnLoad_SetObjectVisibility_BugContest
	case DAY_SATURDAY, NationalParkGateSouth_OnLoad_SetObjectVisibility_BugContest
	setflag FLAG_TEMP_2
	end

NationalParkGateSouth_OnLoad_SetObjectVisibility_BugContest:
	setflag FLAG_TEMP_1
	end

NationalParkGateSouth_OnFrame_Table:
	map_script_2 VAR_BUG_CATCHING_CONTEST_STATE, 1, NationalParkGateSouth_OnFrame_EndContestPrompt
	.2byte 0

NationalParkGateSouth_OnFrame_EndContestPrompt:
	lock
	applymovement EVENT_OBJ_ID_PLAYER, NationalParkGateSouth_Movement_EndContestPlayerMovement
	applymovement 3, NationalParkGateSouth_Movement_EndContestOfficerMovement
	waitmovement 0
	textcolor MSG_COLOR_BLUE
	msgbox NationalParkGateSouth_Text_DoYouWantToFinish, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_ne NationalParkGateSouth_EndContest
	msgbox NationalParkGateSouth_Text_GetBackOutside, MSGBOX_DEFAULT
	closemessage
	applymovement EVENT_OBJ_ID_PLAYER, NationalParkGateSouth_Movement_ReEnterContest
	waitmovement 0
	warp MAP_NATIONAL_PARK_CONTEST, 0, -1, -1
	waitstate
	release
	end

NationalParkGateSouth_EndContest:
	msgbox NationalParkGateSouth_Text_WaitAtNorthGate, MSGBOX_DEFAULT
	closemessage
	setvar VAR_BUG_CATCHING_CONTEST_STATE, 2
	warp MAP_NATIONAL_PARK_CONTEST, 0, -1, -1
	waitstate
	release
	end

NationalParkGateSouth_Movement_EndContestPlayerMovement:
	face_left
	step_end

NationalParkGateSouth_Movement_EndContestOfficerMovement:
	face_player
	step_end

NationalParkGateSouth_Movement_ReEnterContest:
	walk_up
	step_end

NationalParkGateSouth_BugContestOfficer::
	lock
	faceplayer
	goto_if_set FLAG_DAILY_BUG_CATCHING_CONTEST, NationalParkGateSouth_BugContestOfficer_ContestIfOver
	special CopyCurrentDayOfWeekStringToVar1
	msgbox NationalParkGateSouth_Text_ContestIntro, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq NationalParkGateSouth_BugContestOfficer_SaidNoToParticipating
	msgbox NationalParkGateSouth_Text_ChoosePokemon, MSGBOX_DEFAULT
	special SavePlayerParty
	fadescreen 1
	special SelectBugCatchingContestMon
	waitstate
	compare VAR_RESULT, 0
	goto_if_ne NationalParkGateSouth_BugContestOfficer_ChosePokemon
	special LoadPlayerParty
	msgbox NationalParkGateSouth_Text_ComeSeeMeLater, MSGBOX_DEFAULT
	release
	end

NationalParkGateSouth_BugContestOfficer_ChosePokemon:
	special ReducePlayerPartyToSelectedMons
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 4
	special CallFrontierUtilFunc
	msgbox NationalParkGateSouth_Text_HereAreTheParkBalls, MSGBOX_DEFAULT
	playfanfare MUS_FANFA4
	message NationalParkGateSouth_Text_ReceivedParkBalls
	waitfanfare
	msgbox NationalParkGateSouth_Text_SendOff, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_DAILY_BUG_CATCHING_CONTEST
	setvar VAR_BUG_CATCHING_CONTEST_STATE, 1
	special EnterBugCatchingContest
	switch VAR_FACING
	case 2, NationalParkGateSouth_BugContestOfficer_EnterContestFromBelow
	case 3, NationalParkGateSouth_BugContestOfficer_EnterContestFromRight
	goto NationalParkGateSouth_BugContestOfficer_EnterContestFromLeft

NationalParkGateSouth_BugContestOfficer_EnterContestFromBelow:
	applymovement EVENT_OBJ_ID_PLAYER, NationalParkGateSouth_Movement_EnterContestFromBelow
	goto NationalParkGateSouth_BugContestOfficer_EnterContest

NationalParkGateSouth_BugContestOfficer_EnterContestFromRight:
	applymovement EVENT_OBJ_ID_PLAYER, NationalParkGateSouth_Movement_EnterContestFromRight
	goto NationalParkGateSouth_BugContestOfficer_EnterContest

NationalParkGateSouth_BugContestOfficer_EnterContestFromLeft:
	applymovement EVENT_OBJ_ID_PLAYER, NationalParkGateSouth_Movement_EnterContestFromLeft
NationalParkGateSouth_BugContestOfficer_EnterContest:
	waitmovement 0
	warp MAP_NATIONAL_PARK_CONTEST, 0, -1, -1
	waitstate
	release
	end

NationalParkGateSouth_Youngster::
	msgbox NationalParkGateSouth_Text_WhenIsContest, MSGBOX_NPC
	end

NationalParkGateSouth_NoContestOfficer::
	msgbox NationalParkGateSouth_Text_WeHoldContests, MSGBOX_NPC
	end

NationalParkGateSouth_ContestSign::
	msgbox NationalParkGateSouth_Text_ContestInfo, MSGBOX_SIGN
	end

NationalParkGateSouth_BugContestOfficer_SaidNoToParticipating:
	msgbox NationalParkGateSouth_Text_TakePartInFuture, MSGBOX_DEFAULT
	release
	end

NationalParkGateSouth_BugContestOfficer_ContestIfOver:
	msgbox NationalParkGateSouth_Text_ContestIsOver, MSGBOX_DEFAULT
	release
	end

NationalParkGateSouth_Movement_EnterContestFromBelow:
	walk_right
	walk_up
	walk_up
	step_end

NationalParkGateSouth_Movement_EnterContestFromRight:
	walk_up
	step_end

NationalParkGateSouth_Movement_EnterContestFromLeft:
	walk_down
	walk_right
	walk_right
	walk_up
	walk_up
	step_end

NationalParkGateSouth_Text_DoYouWantToFinish:
	.string "The contest is still going\n"
	.string "for another XX minutes.\p"
	.string "Do you want to finish now?$"

NationalParkGateSouth_Text_WaitAtNorthGate:
	.string "Ok. Please wait at the North Gate\n"
	.string "for the awards ceremony.$"

NationalParkGateSouth_Text_GetBackOutside:
	.string "Ok. Please get back outside\n"
	.string "and finish up.$"

NationalParkGateSouth_Text_ContestIntro:
	.string "Today is {STR_VAR_1}.\p"
	.string "That means the Bug-Catching\n"
	.string "Contest is on today.\p"
	.string "The rules are simple.\p"
	.string "Using one of your POKéMON,\n"
	.string "catch a bug POKéMON to be\l"
	.string "judged.\p"
	.string "Would you like to give it\n"
	.string "a try?$"

NationalParkGateSouth_Text_TakePartInFuture:
	.string "Ok. We hope you'll take part\n"
	.string "in the future.$"

NationalParkGateSouth_Text_ContestIsOver:
	.string "Today's bug catching contest is\n"
	.string "over.\p"
	.string "We hope you will participate\n"
	.string "in the future.$"

NationalParkGateSouth_Text_ChoosePokemon:
	.string "Please choose one POKéMON to\n"
	.string "bring into the contest.\p"
	.string "We'll hold onto the others\n"
	.string "until the contest is finshed.$"

NationalParkGateSouth_Text_ComeSeeMeLater:
	.string "Come see me again if you decide\n"
	.string "to participate in the contest.$"

NationalParkGateSouth_Text_HereAreTheParkBalls:
	.string "Here are the PARK BALLS for\n"
	.string "the contest.$"

NationalParkGateSouth_Text_ReceivedParkBalls:
	.string "{PLAYER} received 20 PARK BALLS.$"

NationalParkGateSouth_Text_SendOff:
	.string "The person who catches the\n"
	.string "best bug POKéMON will be\l"
	.string "the winner.\p"
	.string "You have 20 minutes.\p"
	.string "If you run out of PARK BALLS,\n"
	.string "you're done.\p"
	.string "You can keep the last POKéMON\n"
	.string "you catch as your own.\p"
	.string "Go out and catch the best bug\n"
	.string "POKéMON you can find!$"

NationalParkGateSouth_Text_WhenIsContest:
	.string "When is the next Bug-Catching\n"
	.string "Contest going to be?$"

NationalParkGateSouth_Text_WeHoldContests:
	.string "We hold Contests regularly in\n"
	.string "the PARK.\p"
	.string "You should give it a shot.$"

NationalParkGateSouth_Text_ContestInfo:
	.string "The Bug-Catching Contest is held\n"
	.string "on Tuesday, Thursday and Saturday.\p"
	.string "Not only do you earn a prize just\n"
	.string "for participating, you also get\l"
	.string "to keep the bug POKéMON you caught\l"
	.string "at the end of the contest.$"
