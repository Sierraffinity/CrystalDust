Route36_NationalParkGatehouse_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Route36_NationalParkGatehouse_MapScripts_MAP_SCRIPT_ON_LOAD
	map_script MAP_SCRIPT_ON_TRANSITION, Route36_NationalParkGatehouse_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route36_NationalParkGatehouse_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

Route36_NationalParkGatehouse_MapScripts_MAP_SCRIPT_ON_LOAD:
	gettime
	compare VAR_BUG_CATCHING_CONTEST_STATE, 2
	goto_if_eq Route36_NationalParkGatehouse_MapScripts_MAP_SCRIPT_ON_LOAD_1
	compare VAR_BUG_CATCHING_CONTEST_STATE, 1
	goto_if_eq Route36_NationalParkGatehouse_MapScripts_MAP_SCRIPT_ON_LOAD_2
	compare VAR_0x8003, DAY_TUESDAY
	goto_if_eq Route36_NationalParkGatehouse_MapScripts_MAP_SCRIPT_ON_LOAD_6
	compare VAR_0x8003, DAY_THURSDAY
	goto_if_eq Route36_NationalParkGatehouse_MapScripts_MAP_SCRIPT_ON_LOAD_6
	compare VAR_0x8003, DAY_SATURDAY
	goto_if_eq Route36_NationalParkGatehouse_MapScripts_MAP_SCRIPT_ON_LOAD_6
Route36_NationalParkGatehouse_MapScripts_MAP_SCRIPT_ON_LOAD_3:
	setflag FLAG_TEMP_12
	setflag FLAG_TEMP_13
	return

Route36_NationalParkGatehouse_MapScripts_MAP_SCRIPT_ON_LOAD_1:
	setflag FLAG_TEMP_12
	return

Route36_NationalParkGatehouse_MapScripts_MAP_SCRIPT_ON_LOAD_2:
	setflag FLAG_TEMP_11
	setflag FLAG_TEMP_13
	return

Route36_NationalParkGatehouse_MapScripts_MAP_SCRIPT_ON_LOAD_6:
	goto_if_unset FLAG_DAILY_BUG_CATCHING_CONTEST, Route36_NationalParkGatehouse_MapScripts_MAP_SCRIPT_ON_LOAD_2
	goto Route36_NationalParkGatehouse_MapScripts_MAP_SCRIPT_ON_LOAD_3

Route36_NationalParkGatehouse_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	compare VAR_BUG_CATCHING_CONTEST_STATE, 0
	goto_if_ne Route36_NationalParkGatehouse_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	return

Route36_NationalParkGatehouse_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
	special SetAwardsCeremonyBugContestObjectEventGraphics
	return

Route36_NationalParkGatehouse_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_BUG_CATCHING_CONTEST_STATE, 1, Route36_NationalParkGatehouse_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0
	map_script_2 VAR_BUG_CATCHING_CONTEST_STATE, 2, Route36_NationalParkGatehouse_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_1
	.2byte 0

Route36_NationalParkGatehouse_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0:
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Route36_NationalParkGatehouse_Movement_EndContestPlayerMovement
	waitmovement 0
	textcolor MSG_COLOR_BLUE
	specialvar VAR_RESULT, CopyBugCatchingContestRemainingMinutesToVar1
	compare VAR_RESULT, 0
	goto_if_eq Route36_NationalParkGatehouse_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_2
	compare VAR_RESULT, 1
	goto_if_eq Route36_NationalParkGatehouse_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_3
Route36_NationalParkGatehouse_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_1:
	compare VAR_RESULT, YES
	goto_if_eq Route36_NationalParkGatehouse_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_7
	msgbox BugCatchingContest_Text_Officer_GetBackOutside
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Route36_NationalParkGatehouse_Movement_EnterContestFromBelow
	waitmovement 0
	warp MAP_NATIONAL_PARK_BUG_CATCHING_CONTEST, 2, -1, -1
	waitstate
Route36_NationalParkGatehouse_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_6:
	releaseall
	return

Route36_NationalParkGatehouse_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_2:
	msgbox BugCatchingContest_Text_Officer_DoYouWantToFinishOneMinute, MSGBOX_YESNO
	goto Route36_NationalParkGatehouse_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_1

Route36_NationalParkGatehouse_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_3:
	msgbox BugCatchingContest_Text_Officer_DoYouWantToFinishMinutes, MSGBOX_YESNO
	goto Route36_NationalParkGatehouse_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_1

Route36_NationalParkGatehouse_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_7:
	msgbox Route36_NationalParkGatehouse_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_0
	closemessage
	setvar VAR_BUG_CATCHING_CONTEST_STATE, 3
	fadescreen 1
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_PLAYER, Route36_NationalParkGatehouse_Movement_MoveToPlayerSpot
	addobject 1
	addobject 2
	addobject 3
	addobject 4
	addobject 5
	addobject 6
	removeobject 7
	applymovement OBJ_EVENT_ID_CAMERA, Route36_NationalParkGatehouse_Movement_CameraPanRight
	waitmovement 0
	special RemoveCameraObject
	fadescreen 0
	call Route36_NationalParkGatehouse_EventScript_AwardsCeremony
	goto Route36_NationalParkGatehouse_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_6

Route36_NationalParkGatehouse_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_1:
	lockall
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_PLAYER, Route36_NationalParkGatehouse_Movement_EnterAwardsCeremony
	applymovement OBJ_EVENT_ID_CAMERA, Route36_NationalParkGatehouse_Movement_CameraPanRight
	waitmovement 0
	special RemoveCameraObject
	call Route36_NationalParkGatehouse_EventScript_AwardsCeremony
	releaseall
	return


Route36_NationalParkGatehouse_Movement_EndContestPlayerMovement:
	face_up
	step_end

Route36_NationalParkGatehouse_Movement_MoveToPlayerSpot:
	walk_fast_right
	face_up
	step_end

Route36_NationalParkGatehouse_Movement_EnterAwardsCeremony:
	walk_right
	face_up
	step_end

Route36_NationalParkGatehouse_Movement_CameraPanRight:
	walk_right
	walk_right
	walk_right
	step_end

Route36_NationalParkGatehouse_EventScript_AwardsCeremony::
	special DetermineBugCatchingContestStandings
	textcolor MSG_COLOR_BLUE
	message Route36_NationalParkGatehouse_EventScript_AwardsCeremony_Text_0
	waitmessage
	msgbox Route36_NationalParkGatehouse_EventScript_AwardsCeremony_Text_1
	setvar VAR_0x8004, 3
	special BuildBugContestPlacementString
	message gStringVar4
	waitmessage
	playfanfare MUS_SLOTS_WIN
	waitfanfare
	special CopyBugContestPlacementScoreToVar1
	msgbox Route36_NationalParkGatehouse_Text_TheScoreWas
	setvar VAR_0x8004, 2
	special BuildBugContestPlacementString
	message gStringVar4
	waitmessage
	playfanfare MUS_SLOTS_WIN
	waitfanfare
	special CopyBugContestPlacementScoreToVar1
	msgbox Route36_NationalParkGatehouse_Text_TheScoreWas
	setvar VAR_0x8004, 1
	special BuildBugContestPlacementString
	message gStringVar4
	waitmessage
	special GetWinningBugContestSpecies
	compare VAR_0x8005, FALSE
	goto_if_eq Route36_NationalParkGatehouse_EventScript_AwardsCeremony_2
	delay 10
	playse SE_SHINY
	showmonpic VAR_0x8004, 10, 3, TRUE
	waitse
	message Route36_NationalParkGatehouse_EventScript_AwardsCeremony_Text_2
	waitmessage
Route36_NationalParkGatehouse_EventScript_AwardsCeremony_1:
	playfanfare MUS_EVOLVED
	waitfanfare
	waitbuttonpress
	setvar VAR_0x8004, 1
	special CopyBugContestPlacementScoreToVar1
	msgbox Route36_NationalParkGatehouse_EventScript_AwardsCeremony_Text_3
	hidemonpic
	specialvar VAR_RESULT, GetPlayerBugContestPlace
	switch VAR_RESULT
	case 1, Route36_NationalParkGatehouse_EventScript_AwardsCeremony_7
	case 2, Route36_NationalParkGatehouse_EventScript_AwardsCeremony_8
	case 3, Route36_NationalParkGatehouse_EventScript_AwardsCeremony_9
	setvar VAR_BUG_CONTEST_PRIZE, ITEM_ORAN_BERRY
	bufferitemname 0, VAR_BUG_CONTEST_PRIZE
	msgbox Route36_NationalParkGatehouse_EventScript_AwardsCeremony_Text_7
Route36_NationalParkGatehouse_EventScript_AwardsCeremony_5:
	giveitem VAR_BUG_CONTEST_PRIZE
	compare VAR_RESULT, FALSE
	goto_if_eq Route36_NationalParkGatehouse_EventScript_AwardsCeremony_12
	setvar VAR_BUG_CONTEST_PRIZE, ITEM_NONE
Route36_NationalParkGatehouse_EventScript_AwardsCeremony_11:
	specialvar VAR_RESULT, GetPlayerBugContestPlace
	switch VAR_RESULT
	case 1, Route36_NationalParkGatehouse_EventScript_AwardsCeremony_17
	case 2, Route36_NationalParkGatehouse_EventScript_AwardsCeremony_17
	case 3, Route36_NationalParkGatehouse_EventScript_AwardsCeremony_17
	msgbox Route36_NationalParkGatehouse_EventScript_AwardsCeremony_Text_10
Route36_NationalParkGatehouse_EventScript_AwardsCeremony_15:
	goto_if_set FLAG_LEFT_MONS_WITH_CONTEST_OFFICER, Route36_NationalParkGatehouse_EventScript_AwardsCeremony_20
Route36_NationalParkGatehouse_EventScript_AwardsCeremony_19:
	special GiveCaughtBugCatchingContestMon
	bufferspeciesname 0, VAR_0x8004
	textcolor MSG_COLOR_SYS
	compare VAR_RESULT, 0
	goto_if_eq Route36_NationalParkGatehouse_EventScript_AwardsCeremony_23
	compare VAR_RESULT, 1
	goto_if_eq Route36_NationalParkGatehouse_EventScript_AwardsCeremony_24
Route36_NationalParkGatehouse_EventScript_AwardsCeremony_22:
	special EndBugCatchingContest
	clearflag FLAG_IN_BUG_CATCHING_CONTEST
	setvar VAR_BUG_CATCHING_CONTEST_STATE, 0
	closemessage
	fadedefaultbgm
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, Route36_NationalParkGatehouse_Movement_CameraPanLeft
	waitmovement 0
	special RemoveCameraObject
	return

Route36_NationalParkGatehouse_EventScript_AwardsCeremony_2:
	showmonpic VAR_0x8004, 10, 3
	goto Route36_NationalParkGatehouse_EventScript_AwardsCeremony_1

Route36_NationalParkGatehouse_EventScript_AwardsCeremony_7:
	setvar VAR_BUG_CONTEST_PRIZE, ITEM_SUN_STONE
	bufferitemname 0, VAR_BUG_CONTEST_PRIZE
	msgbox Route36_NationalParkGatehouse_EventScript_AwardsCeremony_Text_4
	setflag FLAG_TEMP_1
	goto Route36_NationalParkGatehouse_EventScript_AwardsCeremony_5

Route36_NationalParkGatehouse_EventScript_AwardsCeremony_8:
	setvar VAR_BUG_CONTEST_PRIZE, ITEM_EVERSTONE
	bufferitemname 0, VAR_BUG_CONTEST_PRIZE
	msgbox Route36_NationalParkGatehouse_EventScript_AwardsCeremony_Text_5
	goto Route36_NationalParkGatehouse_EventScript_AwardsCeremony_5

Route36_NationalParkGatehouse_EventScript_AwardsCeremony_9:
	setvar VAR_BUG_CONTEST_PRIZE, ITEM_SITRUS_BERRY
	bufferitemname 0, VAR_BUG_CONTEST_PRIZE
	msgbox Route36_NationalParkGatehouse_EventScript_AwardsCeremony_Text_6
	goto Route36_NationalParkGatehouse_EventScript_AwardsCeremony_5

Route36_NationalParkGatehouse_EventScript_AwardsCeremony_12:
	msgbox Route36_NationalParkGatehouse_EventScript_AwardsCeremony_Text_8
	goto Route36_NationalParkGatehouse_EventScript_AwardsCeremony_11

Route36_NationalParkGatehouse_EventScript_AwardsCeremony_17:
	msgbox Route36_NationalParkGatehouse_EventScript_AwardsCeremony_Text_9
	goto Route36_NationalParkGatehouse_EventScript_AwardsCeremony_15

Route36_NationalParkGatehouse_EventScript_AwardsCeremony_20:
	msgbox Route36_NationalParkGatehouse_EventScript_AwardsCeremony_Text_11
	call EventScript_ReturnBugCatchingContestMons
	clearflag FLAG_LEFT_MONS_WITH_CONTEST_OFFICER
	goto Route36_NationalParkGatehouse_EventScript_AwardsCeremony_19

Route36_NationalParkGatehouse_EventScript_AwardsCeremony_23:
	msgbox Route36_NationalParkGatehouse_Text_NicknameCaughtMon, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Route36_NationalParkGatehouse_EventScript_AwardsCeremony_27
	goto Route36_NationalParkGatehouse_EventScript_AwardsCeremony_22

Route36_NationalParkGatehouse_EventScript_AwardsCeremony_24:
	msgbox Route36_NationalParkGatehouse_Text_NicknameCaughtMon, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Route36_NationalParkGatehouse_EventScript_AwardsCeremony_30
Route36_NationalParkGatehouse_EventScript_AwardsCeremony_29:
	copyvar VAR_TEMP_1, VAR_0x8004
	call Common_EventScript_TransferredToPC
	goto Route36_NationalParkGatehouse_EventScript_AwardsCeremony_22

Route36_NationalParkGatehouse_EventScript_AwardsCeremony_27:
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto Route36_NationalParkGatehouse_EventScript_AwardsCeremony_22

Route36_NationalParkGatehouse_EventScript_AwardsCeremony_30:
	call Common_EventScript_NameReceivedBoxMon
	goto Route36_NationalParkGatehouse_EventScript_AwardsCeremony_29


Route36_NationalParkGatehouse_Movement_CameraPanLeft:
	walk_left
	walk_left
	step_end

Route36_NationalParkGatehouse_EventScript_BugContestOfficer::
	lock
	faceplayer
	compare VAR_BUG_CONTEST_PRIZE, ITEM_NONE
	goto_if_ne Route36_NationalParkGatehouse_EventScript_BugContestOfficer_2
	goto_if_set FLAG_DAILY_BUG_CATCHING_CONTEST, Route36_NationalParkGatehouse_EventScript_BugContestOfficer_3
	gettime
	compare VAR_0x8003, DAY_TUESDAY
	goto_if_eq Route36_NationalParkGatehouse_EventScript_BugContestOfficer_7
	compare VAR_0x8003, DAY_THURSDAY
	goto_if_eq Route36_NationalParkGatehouse_EventScript_BugContestOfficer_7
	compare VAR_0x8003, DAY_SATURDAY
	goto_if_eq Route36_NationalParkGatehouse_EventScript_BugContestOfficer_7
	msgbox Route36_NationalParkGatehouse_Text_Officer_NoContest
Route36_NationalParkGatehouse_EventScript_BugContestOfficer_1:
	release
	return

Route36_NationalParkGatehouse_EventScript_BugContestOfficer_2:
	call BugCatchingContest_EventScript_Officer_GivePrizeItem
	goto Route36_NationalParkGatehouse_EventScript_BugContestOfficer_1

Route36_NationalParkGatehouse_EventScript_BugContestOfficer_3:
	msgbox BugCatchingContest_Text_Officer_ContestIsOver
	goto Route36_NationalParkGatehouse_EventScript_BugContestOfficer_1

Route36_NationalParkGatehouse_EventScript_BugContestOfficer_7:
	call BugCatchingContest_EventScript_Officer_EnterContest
	compare VAR_RESULT, TRUE
	goto_if_eq Route36_NationalParkGatehouse_EventScript_BugContestOfficer_14
	goto Route36_NationalParkGatehouse_EventScript_BugContestOfficer_1

Route36_NationalParkGatehouse_EventScript_BugContestOfficer_14:
	switch VAR_FACING
	case DIR_NORTH, Route36_NationalParkGatehouse_EventScript_BugContestOfficer_18
	applymovement 7, Route36_NationalParkGatehouse_Movement_OfficerWatchPlayerEnterFromRight
	applymovement OBJ_EVENT_ID_PLAYER, Route36_NationalParkGatehouse_Movement_EnterContestFromRight
Route36_NationalParkGatehouse_EventScript_BugContestOfficer_16:
	waitmovement 0
	warp MAP_NATIONAL_PARK_BUG_CATCHING_CONTEST, 2, -1, -1
	waitstate
	goto Route36_NationalParkGatehouse_EventScript_BugContestOfficer_1

Route36_NationalParkGatehouse_EventScript_BugContestOfficer_18:
	applymovement OBJ_EVENT_ID_PLAYER, Route36_NationalParkGatehouse_Movement_EnterContestFromBelow
	goto Route36_NationalParkGatehouse_EventScript_BugContestOfficer_16


Route36_NationalParkGatehouse_Movement_EnterContestFromBelow:
	face_left
	step_end

Route36_NationalParkGatehouse_Movement_EnterContestFromRight:
	walk_down
	walk_left
	step_end

Route36_NationalParkGatehouse_Movement_OfficerWatchPlayerEnterFromRight:
	walk_in_place_fastest_down
	step_end

Route36_NationalParkGatehouse_BehindCounterOfficer::
	lock
	faceplayer
	compare VAR_BUG_CONTEST_PRIZE, ITEM_NONE
	goto_if_ne Route36_NationalParkGatehouse_BehindCounterOfficer_2
	goto_if_set FLAG_DAILY_BUG_CATCHING_CONTEST, Route36_NationalParkGatehouse_BehindCounterOfficer_3
	msgbox Route36_NationalParkGatehouse_Text_Officer_NoContest
Route36_NationalParkGatehouse_BehindCounterOfficer_1:
	release
	return

Route36_NationalParkGatehouse_BehindCounterOfficer_2:
	call BugCatchingContest_EventScript_Officer_GivePrizeItem
	goto Route36_NationalParkGatehouse_BehindCounterOfficer_1

Route36_NationalParkGatehouse_BehindCounterOfficer_3:
	msgbox BugCatchingContest_Text_Officer_ContestIsOver
	goto Route36_NationalParkGatehouse_BehindCounterOfficer_1


Route36_NationalParkGatehouse_Nick::
	goto_if_set FLAG_TEMP_1, Route36_NationalParkGatehouse_Nick_1
	msgbox Route36_NationalParkGatehouse_Nick_Text_1, MSGBOX_NPC
	return

Route36_NationalParkGatehouse_Nick_1:
	msgbox Route36_NationalParkGatehouse_Nick_Text_0, MSGBOX_NPC
	return


Route36_NationalParkGatehouse_William::
	goto_if_set FLAG_TEMP_1, Route36_NationalParkGatehouse_William_1
	msgbox Route36_NationalParkGatehouse_William_Text_1, MSGBOX_NPC
	return

Route36_NationalParkGatehouse_William_1:
	msgbox Route36_NationalParkGatehouse_William_Text_0, MSGBOX_NPC
	return


Route36_NationalParkGatehouse_Samuel::
	goto_if_set FLAG_TEMP_1, Route36_NationalParkGatehouse_Samuel_1
	msgbox Route36_NationalParkGatehouse_Samuel_Text_1, MSGBOX_NPC
	return

Route36_NationalParkGatehouse_Samuel_1:
	msgbox Route36_NationalParkGatehouse_Samuel_Text_0, MSGBOX_NPC
	return


Route36_NationalParkGatehouse_Barry::
	goto_if_set FLAG_TEMP_1, Route36_NationalParkGatehouse_Barry_1
	msgbox Route36_NationalParkGatehouse_Barry_Text_1, MSGBOX_NPC
	return

Route36_NationalParkGatehouse_Barry_1:
	msgbox Route36_NationalParkGatehouse_Barry_Text_0, MSGBOX_NPC
	return


Route36_NationalParkGatehouse_Ed::
	goto_if_set FLAG_TEMP_1, Route36_NationalParkGatehouse_Ed_1
	msgbox Route36_NationalParkGatehouse_Ed_Text_1, MSGBOX_NPC
	return

Route36_NationalParkGatehouse_Ed_1:
	msgbox Route36_NationalParkGatehouse_Ed_Text_0, MSGBOX_NPC
	return


Route36_NationalParkGatehouse_Benny::
	goto_if_set FLAG_TEMP_1, Route36_NationalParkGatehouse_Benny_1
	msgbox Route36_NationalParkGatehouse_Benny_Text_1, MSGBOX_NPC
	return

Route36_NationalParkGatehouse_Benny_1:
	msgbox Route36_NationalParkGatehouse_Benny_Text_0, MSGBOX_NPC
	return


Route36_NationalParkGatehouse_Josh::
	goto_if_set FLAG_TEMP_1, Route36_NationalParkGatehouse_Josh_1
	msgbox Route36_NationalParkGatehouse_Josh_Text_1, MSGBOX_NPC
	return

Route36_NationalParkGatehouse_Josh_1:
	msgbox Route36_NationalParkGatehouse_Josh_Text_0, MSGBOX_NPC
	return


Route36_NationalParkGatehouse_Don::
	goto_if_set FLAG_TEMP_1, Route36_NationalParkGatehouse_Don_1
	msgbox Route36_NationalParkGatehouse_Don_Text_1, MSGBOX_NPC
	return

Route36_NationalParkGatehouse_Don_1:
	msgbox Route36_NationalParkGatehouse_Don_Text_0, MSGBOX_NPC
	return


Route36_NationalParkGatehouse_Kipp::
	goto_if_set FLAG_TEMP_1, Route36_NationalParkGatehouse_Kipp_1
	msgbox Route36_NationalParkGatehouse_Kipp_Text_1, MSGBOX_NPC
	return

Route36_NationalParkGatehouse_Kipp_1:
	msgbox Route36_NationalParkGatehouse_Kipp_Text_0, MSGBOX_NPC
	return


Route36_NationalParkGatehouse_Cindy::
	goto_if_set FLAG_TEMP_1, Route36_NationalParkGatehouse_Cindy_1
	msgbox Route36_NationalParkGatehouse_Cindy_Text_1, MSGBOX_NPC
	return

Route36_NationalParkGatehouse_Cindy_1:
	msgbox Route36_NationalParkGatehouse_Cindy_Text_0, MSGBOX_NPC
	return


Route36_NationalParkGatehouse_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_0:
	.string "Okay. Please wait here for the\n"
	.string "announcement of the winners.$"

Route36_NationalParkGatehouse_EventScript_AwardsCeremony_Text_0:
	.string "We will now judge the POKéMON\n"
	.string "you've caught.\p"
	.string "…{PAUSE 15}…{PAUSE 15}…{PAUSE 15}\n"
	.string "…{PAUSE 15}…{PAUSE 15}…{PAUSE 15}$"

Route36_NationalParkGatehouse_EventScript_AwardsCeremony_Text_1:
	.string "We have chosen the winners!\n"
	.string "Are you ready for this?$"

Route36_NationalParkGatehouse_EventScript_AwardsCeremony_Text_2:
	.string "Amazing! The POKéMON has an unusual\n"
	.string "and rare coloration!\p"
	.string "I've never seen such a beautiful\n"
	.string "BUG POKéMON!$"

Route36_NationalParkGatehouse_EventScript_AwardsCeremony_Text_3:
	.string "The winning score was a whopping\n"
	.string "{STR_VAR_1} points!$"

Route36_NationalParkGatehouse_EventScript_AwardsCeremony_Text_4:
	.string "{PLAYER}, your champion, wins a\n"
	.string "fabulous {STR_VAR_1}!$"

Route36_NationalParkGatehouse_EventScript_AwardsCeremony_Text_5:
	.string "{PLAYER}, the runner-up, wins a\n"
	.string "nifty {STR_VAR_1}!$"

Route36_NationalParkGatehouse_EventScript_AwardsCeremony_Text_6:
	.string "{PLAYER} wins the third-place prize\n"
	.string "of a sweet {STR_VAR_1}!$"

Route36_NationalParkGatehouse_EventScript_AwardsCeremony_Text_7:
	.string "Everyone else gets an {STR_VAR_1}\n"
	.string "as a consolation prize!$"

Route36_NationalParkGatehouse_EventScript_AwardsCeremony_Text_8:
	.string "Uh-oh… Your BAG is full.\n"
	.string "We'll hold onto your prize for now.\p"
	.string "Please make room in your BAG, then\n"
	.string "come see me.$"

Route36_NationalParkGatehouse_EventScript_AwardsCeremony_Text_9:
	.string "Please join us for the next\n"
	.string "Bug-Catching Contest!$"

Route36_NationalParkGatehouse_EventScript_AwardsCeremony_Text_10:
	.string "We hope you do better next time.$"

Route36_NationalParkGatehouse_EventScript_AwardsCeremony_Text_11:
	.string "We'll return the POKéMON we kept for\n"
	.string "you. Here you go!$"

Route36_NationalParkGatehouse_Nick_Text_0:
	.string "NICK: Well done! I'm going to\n"
	.string "raise my POKéMON better.$"

Route36_NationalParkGatehouse_Nick_Text_1:
	.string "NICK: Maybe you get a higher score\n"
	.string "for POKéMON of an unusual color.$"

Route36_NationalParkGatehouse_William_Text_0:
	.string "WILLIAM: You're the winner?\n"
	.string "What did you catch?$"

Route36_NationalParkGatehouse_William_Text_1:
	.string "WILLIAM: Well, I'm satisfied because\n"
	.string "I caught a POKéMON that I wanted.$"

Route36_NationalParkGatehouse_Samuel_Text_0:
	.string "SAMUEL: Next time, I'm going to win.$"

Route36_NationalParkGatehouse_Samuel_Text_1:
	.string "SAMUEL: Huh, that's odd…\n"
	.string "I thought I would score higher.$"

Route36_NationalParkGatehouse_Barry_Text_0:
	.string "BARRY: That POKéMON you caught…\n"
	.string "It's awesome!$"

Route36_NationalParkGatehouse_Barry_Text_1:
	.string "BARRY: It's easier to win if you get\n"
	.string "a high-level BUG POKéMON.\p"
	.string "But I think they also consider some\n"
	.string "other points.$"

Route36_NationalParkGatehouse_Ed_Text_0:
	.string "ED: I envy you.\n"
	.string "I just couldn't do it this time.$"

Route36_NationalParkGatehouse_Ed_Text_1:
	.string "ED: Maybe you win with big POKéMON?$"

Route36_NationalParkGatehouse_Benny_Text_0:
	.string "BENNY: Congrats!\n"
	.string "You have earned my respect!$"

Route36_NationalParkGatehouse_Benny_Text_1:
	.string "BENNY: I caught a SCYTHER before,\n"
	.string "but I didn't win.$"

Route36_NationalParkGatehouse_Josh_Text_0:
	.string "JOSH: I… I can't believe I\n"
	.string "lost at BUG-catching…$"

Route36_NationalParkGatehouse_Josh_Text_1:
	.string "JOSH: I heard that somebody won\n"
	.string "with a CATERPIE!$"

Route36_NationalParkGatehouse_Don_Text_0:
	.string "DON: Wow, you beat me.\n"
	.string "You're pretty good.$"

Route36_NationalParkGatehouse_Don_Text_1:
	.string "DON: Luck plays a big part in this.\p"
	.string "You never know what POKéMON will\n"
	.string "appear.$"

Route36_NationalParkGatehouse_Kipp_Text_0:
	.string "KIPP: Could you give me some tips?\n"
	.string "I want to study your style.$"

Route36_NationalParkGatehouse_Kipp_Text_1:
	.string "KIPP: I study a lot, but that's not\n"
	.string "good enough to win.$"

Route36_NationalParkGatehouse_Cindy_Text_0:
	.string "CINDY: You won?\n"
	.string "That's great!\p"
	.string "Do you feel like looking for BUG\n"
	.string "POKéMON with me sometime?$"

Route36_NationalParkGatehouse_Cindy_Text_1:
	.string "CINDY: I really love BUG POKéMON!$"

Route36_NationalParkGatehouse_Text_TheScoreWas::
	.string "The score was {STR_VAR_1} points!$"

Route36_NationalParkGatehouse_Text_NicknameCaughtMon::
	.string "Do you want to give a nickname to\n"
	.string "the {STR_VAR_1} you caught?$"

Route36_NationalParkGatehouse_Text_Officer_NoContest::
	.string "Some POKéMON can only be seen in\n"
	.string "the PARK.$"
