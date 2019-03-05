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
	msgbox NationalParkGate_Text_DoYouWantToFinish, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_ne NationalParkGateSouth_EndContest
	msgbox NationalParkGate_Text_GetBackOutside, MSGBOX_DEFAULT
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
	warp MAP_NATIONAL_PARK_GATE_EAST, 0, -1, -1
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
	call BugContestOfficer_EnterContest
	compare VAR_RESULT, 1
	goto_if_eq NationalParkGateSouth_BugContestOfficer_EnterDoor
	release
	end

NationalParkGateSouth_BugContestOfficer_EnterDoor:
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
	msgbox NationalParkGate_Text_WeHoldContests, MSGBOX_NPC
	end

NationalParkGate_ContestSign::
	msgbox NationalParkGateSouth_Text_ContestInfo, MSGBOX_SIGN
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

NationalParkGate_Text_DoYouWantToFinish:
	.string "The contest is still going for\n"
	.string "another XX minutes.\p"
	.string "Do you want to finish now?$"

NationalParkGateSouth_Text_WaitAtNorthGate:
	.string "Ok. Please wait at the North Gate\n"
	.string "for the awards ceremony.$"

NationalParkGate_Text_GetBackOutside:
	.string "Ok. Please get back outside and\n"
	.string "finish up.$"

NationalParkGateSouth_Text_WhenIsContest:
	.string "When is the next Bug-Catching\n"
	.string "Contest going to be?$"

NationalParkGate_Text_WeHoldContests::
	.string "We hold Contests regularly in the\n"
	.string "PARK.\p"
	.string "You should give it a shot.$"

NationalParkGateSouth_Text_ContestInfo:
	.string "The Bug-Catching Contest is held\n"
	.string "on Tuesday, Thursday and Saturday.\p"
	.string "Not only do you earn a prize just\n"
	.string "for participating, you also get\l"
	.string "to keep the bug POKéMON you caught\l"
	.string "at the end of the contest.$"
