Route35_NationalParkGatehouse_MapScripts::
	map_script 1, Route35_NationalParkGatehouse_OnLoad
	map_script 2, Route35_NationalParkGatehouse_OnFrame_Table
	.byte 0

Route35_NationalParkGatehouse_OnLoad:
	compare	VAR_BUG_CATCHING_CONTEST_STATE, 1
	goto_if_eq Route35_NationalParkGatehouse_OnLoad_SetObjectVisibility_BugContest
	gettime
	switch VAR_0x8003
	case DAY_TUESDAY, Route35_NationalParkGatehouse_OnLoad_SetObjectVisibility_BugContest
	case DAY_THURSDAY, Route35_NationalParkGatehouse_OnLoad_SetObjectVisibility_BugContest
	case DAY_SATURDAY, Route35_NationalParkGatehouse_OnLoad_SetObjectVisibility_BugContest
	setflag FLAG_TEMP_2
	end

Route35_NationalParkGatehouse_OnLoad_SetObjectVisibility_BugContest:
	setflag FLAG_TEMP_1
	end

Route35_NationalParkGatehouse_OnFrame_Table:
	map_script_2 VAR_BUG_CATCHING_CONTEST_STATE, 1, Route35_NationalParkGatehouse_OnFrame_EndContestPrompt
	.2byte 0

Route35_NationalParkGatehouse_OnFrame_EndContestPrompt:
	lock
	applymovement OBJ_EVENT_ID_PLAYER, Route35_NationalParkGatehouse_Movement_EndContestPlayerMovement
	applymovement 3, Route35_NationalParkGatehouse_Movement_EndContestOfficerMovement
	waitmovement 0
	textcolor MSG_COLOR_BLUE
	specialvar VAR_RESULT, CopyBugCatchingContestRemainingMinutesToVar1
	compare VAR_RESULT, 0
	call_if_eq NationalParkGate_DoYouWantToFinishOneMinute
	compare VAR_RESULT, 1
	call_if_eq NationalParkGate_DoYouWantToFinishMinutes
	compare VAR_RESULT, 0
	goto_if_ne Route35_NationalParkGatehouse_EndContest
	msgbox NationalParkGate_Text_GetBackOutside, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Route35_NationalParkGatehouse_Movement_ReEnterContest
	waitmovement 0
	warp MAP_NATIONAL_PARK_BUG_CATCHING_CONTEST, 0, -1, -1
	waitstate
	release
	end

NationalParkGate_DoYouWantToFinishMinutes:
	msgbox NationalParkGate_Text_DoYouWantToFinish, MSGBOX_YESNO
	return

NationalParkGate_DoYouWantToFinishOneMinute:
	msgbox NationalParkGate_Text_DoYouWantToFinishOneMinute, MSGBOX_YESNO
	return

Route35_NationalParkGatehouse_EndContest:
	msgbox Route35_NationalParkGatehouse_Text_WaitAtNorthGate, MSGBOX_DEFAULT
	closemessage
	setvar VAR_BUG_CATCHING_CONTEST_STATE, 2
	warp MAP_ROUTE36_NATIONAL_PARK_GATEHOUSE, 0, -1, -1
	waitstate
	release
	end

Route35_NationalParkGatehouse_Movement_EndContestPlayerMovement:
	face_left
	step_end

Route35_NationalParkGatehouse_Movement_EndContestOfficerMovement:
	face_player
	step_end

Route35_NationalParkGatehouse_Movement_ReEnterContest:
	walk_up
	step_end

Route35_NationalParkGatehouse_BugContestOfficer::
	lock
	faceplayer
	call BugContestOfficer_EnterContest
	compare VAR_RESULT, 1
	goto_if_eq Route35_NationalParkGatehouse_BugContestOfficer_EnterDoor
	release
	end

Route35_NationalParkGatehouse_BugContestOfficer_EnterDoor:
	switch VAR_FACING
	case 2, Route35_NationalParkGatehouse_BugContestOfficer_EnterContestFromBelow
	case 3, Route35_NationalParkGatehouse_BugContestOfficer_EnterContestFromRight
	goto Route35_NationalParkGatehouse_BugContestOfficer_EnterContestFromLeft

Route35_NationalParkGatehouse_BugContestOfficer_EnterContestFromBelow:
	applymovement OBJ_EVENT_ID_PLAYER, Route35_NationalParkGatehouse_Movement_EnterContestFromBelow
	goto Route35_NationalParkGatehouse_BugContestOfficer_EnterContest

Route35_NationalParkGatehouse_BugContestOfficer_EnterContestFromRight:
	applymovement OBJ_EVENT_ID_PLAYER, Route35_NationalParkGatehouse_Movement_EnterContestFromRight
	goto Route35_NationalParkGatehouse_BugContestOfficer_EnterContest

Route35_NationalParkGatehouse_BugContestOfficer_EnterContestFromLeft:
	applymovement OBJ_EVENT_ID_PLAYER, Route35_NationalParkGatehouse_Movement_EnterContestFromLeft
Route35_NationalParkGatehouse_BugContestOfficer_EnterContest:
	waitmovement 0
	warp MAP_NATIONAL_PARK_BUG_CATCHING_CONTEST, 0, -1, -1
	waitstate
	release
	end

Route35_NationalParkGatehouse_Youngster::
	msgbox Route35_NationalParkGatehouse_Text_WhenIsContest, MSGBOX_NPC
	end

Route35_NationalParkGatehouse_NoContestOfficer::
	lock
	faceplayer
	compare VAR_BUG_CONTEST_PRIZE, ITEM_NONE
	goto_if_ne Route35_NationalParkGatehouse_NoContestOfficer_GivePrize
	msgbox NationalParkGate_Text_WeHoldContests, MSGBOX_DEFAULT
	release
	end

Route35_NationalParkGatehouse_NoContestOfficer_GivePrize:
	call BugContestOfficer_GivePrizeItem
	release
	end

Route35_NationalParkGatehouse_ContestSign::
	msgbox Route35_NationalParkGatehouse_Text_ContestInfo, MSGBOX_SIGN
	end

Route35_NationalParkGatehouse_Movement_EnterContestFromBelow:
	walk_right
	walk_up
	walk_up
	step_end

Route35_NationalParkGatehouse_Movement_EnterContestFromRight:
	walk_up
	step_end

Route35_NationalParkGatehouse_Movement_EnterContestFromLeft:
	walk_down
	walk_right
	walk_right
	walk_up
	walk_up
	step_end

NationalParkGate_Text_DoYouWantToFinish:
	.string "The contest is still going for\n"
	.string "another {STR_VAR_1} minutes.\p"
	.string "Do you want to finish now?$"

NationalParkGate_Text_DoYouWantToFinishOneMinute:
	.string "The contest is still going for\n"
	.string "another minute or so.\p"
	.string "Do you want to finish now?$"

Route35_NationalParkGatehouse_Text_WaitAtNorthGate:
	.string "Ok. Please wait at the North Gate\n"
	.string "for the awards ceremony.$"

NationalParkGate_Text_GetBackOutside:
	.string "Ok. Please get back outside and\n"
	.string "finish up.$"

Route35_NationalParkGatehouse_Text_WhenIsContest:
	.string "When is the next Bug-Catching\n"
	.string "Contest going to be?$"

NationalParkGate_Text_WeHoldContests::
	.string "We hold Contests regularly in the\n"
	.string "PARK.\p"
	.string "You should give it a shot.$"

Route35_NationalParkGatehouse_Text_ContestInfo:
	.string "The Bug-Catching Contest is held\n"
	.string "on Tuesday, Thursday and Saturday.\p"
	.string "Not only do you earn a prize just\n"
	.string "for participating, you also get\l"
	.string "to keep the bug POKéMON you caught\l"
	.string "at the end of the contest.$"
