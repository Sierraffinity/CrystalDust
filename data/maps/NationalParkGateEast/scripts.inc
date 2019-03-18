NationalParkGateEast_MapScripts::
	map_script 1, NationalParkGateEast_OnLoad
	map_script 2, NationalParkGateEast_OnFrame_Table
	map_script 3, NationalParkGateEast_OnTransition
	.byte 0

NationalParkGateEast_OnLoad:
	compare	VAR_BUG_CATCHING_CONTEST_STATE, 1
	goto_if_eq NationalParkGateEast_OnLoad_SetObjectVisibility_BugContest
	compare	VAR_BUG_CATCHING_CONTEST_STATE, 2
	goto_if_eq NationalParkGateEast_OnLoad_SetObjectVisibility_BugContestAwardsCeremony
	gettime
	switch VAR_0x8003
	case DAY_TUESDAY, NationalParkGateEast_OnLoad_SetObjectVisibility_BugContest
	case DAY_THURSDAY, NationalParkGateEast_OnLoad_SetObjectVisibility_BugContest
	case DAY_SATURDAY, NationalParkGateEast_OnLoad_SetObjectVisibility_BugContest
	setflag FLAG_TEMP_2
	setflag FLAG_TEMP_3
	end

NationalParkGateEast_OnLoad_SetObjectVisibility_BugContest:
	setflag FLAG_TEMP_1
	setflag FLAG_TEMP_3
	end

NationalParkGateEast_OnLoad_SetObjectVisibility_BugContestAwardsCeremony:
	setflag FLAG_TEMP_2
	end

NationalParkGateEast_OnFrame_Table:
	map_script_2 VAR_BUG_CATCHING_CONTEST_STATE, 1, NationalParkGateEast_OnFrame_EndContestPrompt
	map_script_2 VAR_BUG_CATCHING_CONTEST_STATE, 2, NationalParkGateEast_OnFrame_EnterAwardsCeremony
	map_script_2 VAR_BUG_CATCHING_CONTEST_STATE, 3, NationalParkGateEast_OnFrame_AwardsCeremony
	.2byte 0

NationalParkGateEast_OnFrame_EndContestPrompt:
	lock
	applymovement EVENT_OBJ_ID_PLAYER, NationalParkGateEast_Movement_EndContestPlayerMovement
	waitmovement 0
	textcolor MSG_COLOR_BLUE
	specialvar VAR_RESULT, CopyBugCatchingContestRemainingMinutesToVar1
	compare VAR_RESULT, 0
	call_if_eq NationalParkGate_DoYouWantToFinishOneMinute
	compare VAR_RESULT, 1
	call_if_eq NationalParkGate_DoYouWantToFinishMinutes
	compare VAR_RESULT, 0
	goto_if_ne NationalParkGateEast_EndContest
	msgbox NationalParkGate_Text_GetBackOutside, MSGBOX_DEFAULT
	closemessage
	applymovement EVENT_OBJ_ID_PLAYER, NationalParkGateEast_Movement_EnterContest
	waitmovement 0
	warp MAP_NATIONAL_PARK_CONTEST, 1, -1, -1
	waitstate
	release
	end

NationalParkGateEast_EndContest:
	msgbox NationalParkGateEast_Text_WaitHere, MSGBOX_DEFAULT
	closemessage
	setvar VAR_BUG_CATCHING_CONTEST_STATE, 3
	fadescreen 1
	applymovement EVENT_OBJ_ID_PLAYER, NationalParkGateEast_Movement_MoveToPlayerSpot
	addobject 1
	addobject 2
	addobject 3
	addobject 4
	addobject 5
	addobject 6
	removeobject 7
	waitmovement 0
	special SpawnCameraObject
	applymovement EVENT_OBJ_ID_CAMERA, NationalParkGateEast_Movement_CameraPanRight
	waitmovement 0
	special RemoveCameraObject
	fadescreen 0
	release
	end

NationalParkGateEast_Movement_EndContestPlayerMovement:
	walk_up
	step_end

NationalParkGateEast_Movement_MoveToPlayerSpot:
	walk_fast_down
	walk_fast_right
	face_up
	step_end

NationalParkGateEast_OnFrame_EnterAwardsCeremony:
	lock
	applymovement EVENT_OBJ_ID_PLAYER, NationalParkGateEast_Movement_EnterAwardsCeremony
	waitmovement 0
	special SpawnCameraObject
	applymovement EVENT_OBJ_ID_CAMERA, NationalParkGateEast_Movement_CameraPanRight
	waitmovement 0
	special RemoveCameraObject
	setvar VAR_BUG_CATCHING_CONTEST_STATE, 3
	release
	end

NationalParkGateEast_Movement_EnterAwardsCeremony:
	walk_right
	face_up
	step_end

NationalParkGateEast_Movement_CameraPanRight:
	walk_right
	walk_right
	step_end

NationalParkGateEast_OnFrame_AwardsCeremony:
	lock
	special DetermineBugCatchingContestStandings
	textcolor MSG_COLOR_BLUE
	message NationalParkGateEast_Text_AwardsIntro
	waitmessage
	setvar VAR_0x8004, 3
	special BuildBugContestPlacementString
	message gStringVar4
	waitmessage
	playfanfare MUS_ME_B_SMALL
	waitfanfare
	special CopyBugContestPlacementScoreToVar1
	message NationalParkGateEast_Text_TheScoreWas
	waitmessage
	setvar VAR_0x8004, 2
	special BuildBugContestPlacementString
	message gStringVar4
	waitmessage
	playfanfare MUS_ME_B_SMALL
	waitfanfare
	special CopyBugContestPlacementScoreToVar1
	message NationalParkGateEast_Text_TheScoreWas
	waitmessage
	setvar VAR_0x8004, 1
	special BuildBugContestPlacementString
	message gStringVar4
	waitmessage
	specialvar VAR_RESULT, GetWinningBugContestSpecies
	compare VAR_0x8005, 0
	call_if_eq NationalParkGateEast_DrawNormalMonPic
	compare VAR_0x8005, 1
	call_if_eq NationalParkGateEast_DrawShinyMonPic
	playfanfare MUS_FANFA5
	waitfanfare
	special CopyBugContestPlacementScoreToVar1
	message NationalParkGateEast_Text_TheWinningScoreWas
	waitmessage
	erasemonpic
	specialvar VAR_0x8004, DetermineBugCatchingContestPrize
	copyvar VAR_BUG_CONTEST_PRIZE, VAR_0x8004
	specialvar VAR_RESULT, GetPlayerBugContestPlace
	switch VAR_RESULT
	case 1, NationalParkGateEast_AwardPlayerFirstPlace
	case 2, NationalParkGateEast_AwardPlayerSecondPlace
	case 3, NationalParkGateEast_AwardPlayerThirdPlace
	message NationalParkGateEast_Text_ConsolationPrize
	goto NationalParkGateEast_GivePrize

NationalParkGateEast_AwardPlayerFirstPlace:
	message NationalParkGateEast_Text_FirstPrize
	goto NationalParkGateEast_GivePrize

NationalParkGateEast_AwardPlayerSecondPlace:
	message NationalParkGateEast_Text_SecondPrize
	goto NationalParkGateEast_GivePrize

NationalParkGateEast_AwardPlayerThirdPlace:
	message NationalParkGateEast_Text_ThirdPrize
NationalParkGateEast_GivePrize:
	waitmessage
	giveitem_std VAR_0x8004
	compare VAR_RESULT, 0
	goto_if_eq NationalParkGateEast_NoRoomForPrize
	setvar VAR_BUG_CONTEST_PRIZE, ITEM_NONE
	message NationalParkGateEast_Text_JoinUseNextTime
	goto NationalParkGateEast_ConcludeAwardsCeremony

NationalParkGateEast_NoRoomForPrize:
	message NationalParkGateEast_Text_NoRoomInBag,
	waitmessage
	message NationalParkGateEast_Text_JoinUseNextTime
NationalParkGateEast_ConcludeAwardsCeremony:
	waitmessage
	setvar VAR_BUG_CATCHING_CONTEST_STATE, 0
	call EventScript_ReturnBugCatchingContestMons
	special GiveCaughtBugCatchingContestMon
	compare VAR_RESULT, 0
	call_if_eq NationalParkGateEast_MonAddedToParty
	compare VAR_RESULT, 1
	call_if_eq NationalParkGateEast_MonSentToPC
	special EndBugCatchingContest
	closemessage
	special SpawnCameraObject
	applymovement EVENT_OBJ_ID_CAMERA, NationalParkGateEast_Movement_CameraPanLeft
	waitmovement 0
	special RemoveCameraObject
	release
	end

NationalParkGateEast_DrawNormalMonPic:
	drawmonpic VAR_RESULT, 10, 3
	return

NationalParkGateEast_DrawShinyMonPic:
	drawmonpic VAR_RESULT, 10, 3, 1
	return

NationalParkGateEast_MonAddedToParty:
	msgbox NationalParkGateEast_Text_AddedToParty, MSGBOX_DEFAULT
	return

NationalParkGateEast_MonSentToPC:
	msgbox NationalParkGateEast_Text_SentToPC, MSGBOX_DEFAULT
	return

NationalParkGateEast_Movement_CameraPanLeft:
	walk_left
	walk_left
	step_end

NationalParkGateEast_OnTransition:
	compare VAR_BUG_CATCHING_CONTEST_STATE, 0
	goto_if_eq NationalParkGateEast_OnTransition_End
	special SetAwardsCeremonyBugContestEventObjectGraphics
NationalParkGateEast_OnTransition_End:
	end

NationalParkGateEast_BugContestOfficer::
	lock
	faceplayer
	call BugContestOfficer_EnterContest
	compare VAR_RESULT, 1
	goto_if_eq NationalParkGateEast_BugContestOfficer_EnterDoor
	release
	end

NationalParkGateEast_BugContestOfficer_EnterDoor:
	applymovement EVENT_OBJ_ID_PLAYER, NationalParkGateEast_Movement_EnterContest
	waitmovement 0
	warp MAP_NATIONAL_PARK_CONTEST, 1, -1, -1
	waitstate
	release
	end

NationalParkGateEast_Movement_EnterContest:
	walk_down
	face_left
	step_end

NationalParkGateEast_BehindCounterOfficer::
	lock
	faceplayer
	compare VAR_BUG_CONTEST_PRIZE, ITEM_NONE
	goto_if_ne NationalParkGateEast_BehindCounterOfficer_GivePrize
	goto_if_set FLAG_DAILY_BUG_CATCHING_CONTEST, NationalParkGateEast_BehindCounterOfficer_ContestOver
	msgbox NationalParkGate_Text_WeHoldContests, MSGBOX_DEFAULT
	release
	end

NationalParkGateEast_BehindCounterOfficer_GivePrize:
	call BugContestOfficer_GivePrizeItem
	release
	end

NationalParkGateEast_BehindCounterOfficer_ContestOver:
	msgbox BugContestOfficer_Text_ContestIsOver, MSGBOX_DEFAULT
	release
	end

NationalParkGateEast_NickPlayerWon::
	msgbox NationalParkGateEast_Text_NickPlayerWon, MSGBOX_NPC
	end

NationalParkGateEast_NickPlayerLost::
	msgbox NationalParkGateEast_Text_NickPlayerLost, MSGBOX_NPC
	end

NationalParkGateEast_WilliamPlayerWon::
	msgbox NationalParkGateEast_Text_WilliamPlayerWon, MSGBOX_NPC
	end

NationalParkGateEast_WilliamPlayerLost::
	msgbox NationalParkGateEast_Text_WilliamPlayerLost, MSGBOX_NPC
	end

NationalParkGateEast_SamuelPlayerWon::
	msgbox NationalParkGateEast_Text_SamuelPlayerWon, MSGBOX_NPC
	end

NationalParkGateEast_SamuelPlayerLost::
	msgbox NationalParkGateEast_Text_SamuelPlayerLost, MSGBOX_NPC
	end

NationalParkGateEast_BarryPlayerWon::
	msgbox NationalParkGateEast_Text_BarryPlayerWon, MSGBOX_NPC
	end

NationalParkGateEast_BarryPlayerLost::
	msgbox NationalParkGateEast_Text_BarryPlayerLost, MSGBOX_NPC
	end

NationalParkGateEast_EdPlayerWon::
	msgbox NationalParkGateEast_Text_EdPlayerWon, MSGBOX_NPC
	end

NationalParkGateEast_EdPlayerLost::
	msgbox NationalParkGateEast_Text_EdPlayerLost, MSGBOX_NPC
	end

NationalParkGateEast_BennyPlayerWon::
	msgbox NationalParkGateEast_Text_BennyPlayerWon, MSGBOX_NPC
	end

NationalParkGateEast_BennyPlayerLost::
	msgbox NationalParkGateEast_Text_BennyPlayerLost, MSGBOX_NPC
	end

NationalParkGateEast_JoshPlayerWon::
	msgbox NationalParkGateEast_Text_JoshPlayerWon, MSGBOX_NPC
	end

NationalParkGateEast_JoshPlayerLost::
	msgbox NationalParkGateEast_Text_JoshPlayerLost, MSGBOX_NPC
	end

NationalParkGateEast_DonPlayerWon::
	msgbox NationalParkGateEast_Text_DonPlayerWon, MSGBOX_NPC
	end

NationalParkGateEast_DonPlayerLost::
	msgbox NationalParkGateEast_Text_DonPlayerLost, MSGBOX_NPC
	end

NationalParkGateEast_KippPlayerWon::
	msgbox NationalParkGateEast_Text_KippPlayerWon, MSGBOX_NPC
	end

NationalParkGateEast_KippPlayerLost::
	msgbox NationalParkGateEast_Text_KippPlayerLost, MSGBOX_NPC
	end

NationalParkGateEast_CindyPlayerWon::
	msgbox NationalParkGateEast_Text_CindyPlayerWon, MSGBOX_NPC
	end

NationalParkGateEast_CindyPlayerLost::
	msgbox NationalParkGateEast_Text_CindyPlayerLost, MSGBOX_NPC
	end

NationalParkGateEast_Text_WaitHere:
	.string "Ok. Wait here for the awards\n"
	.string "ceremony.$"

NationalParkGateEast_Text_AwardsIntro:
	.string "We will now judge the POKéMON\n"
	.string "you've caught.\p"
	.string "…{PAUSE 0x0F}…{PAUSE 0x0F}…{PAUSE 0x0F}\n"
	.string "…{PAUSE 0x0F}…{PAUSE 0x0F}…{PAUSE 0x0F}\p"
	.string "We have chosen the winners!\p"
	.string "Are you ready for this?\p$"

NationalParkGateEast_Text_TheScoreWas:
	.string "The score was {STR_VAR_1} points!\p$"

NationalParkGateEast_Text_TheWinningScoreWas:
	.string "The winning score was a whopping\n"
	.string "{STR_VAR_1} points!\p$"

NationalParkGateEast_Text_ConsolationPrize:
	.string "Everyone else gets an ORAN BERRY\n"
	.string "as a consolation prize!\p$"

NationalParkGateEast_Text_FirstPrize:
	.string "{PLAYER}, your champion, wins a\n"
	.string "fabulous {STR_VAR_1}!\p$"

NationalParkGateEast_Text_SecondPrize:
	.string "{PLAYER}, runner-up, wins a nifty\n"
	.string "{STR_VAR_1}!\p$"

NationalParkGateEast_Text_ThirdPrize:
	.string "{PLAYER} wins the third-place prize\n"
	.string "of a sweet {STR_VAR_1}!\p$"

NationalParkGateEast_Text_NoRoomInBag:
	.string "Your BAG is full…\n"
	.string "Please make room for your prize.\p$"

NationalParkGateEast_Text_AddedToParty:
	.string "We'll return the POKéMON we kept for\n"
	.string "you. Here you go!\p"
	.string "The POKéMON you caught in the\n"
	.string "contest has been added to your party.$"

NationalParkGateEast_Text_SentToPC:
	.string "We'll return the POKéMON we kept for\n"
	.string "you. Here you go!\p"
	.string "The POKéMON you caught in the\n"
	.string "contest has been sent to your PC.$"

NationalParkGateEast_Text_JoinUseNextTime:
	.string "Please join us for the next\n"
	.string "Bug-Catching Contest!\p$"

NationalParkGateEast_Text_NickPlayerWon:
	.string "NICK: Well done!\n"
	.string "I'm going to raise my POKéMON\l"
	.string "better.$"

NationalParkGateEast_Text_NickPlayerLost:
	.string "NICK: Maybe you get a higher score\p"
	.string "for POKéMON of an unusual color.$"

NationalParkGateEast_Text_WilliamPlayerWon:
	.string "WILLIAM: You're the winner?\n"
	.string "What did you catch?$"

NationalParkGateEast_Text_WilliamPlayerLost:
	.string "WILLIAM: Well, I'm satisfied because\n"
	.string "I caught a POKéMON that I wanted.$"

NationalParkGateEast_Text_SamuelPlayerWon:
	.string "SAMUEL: Next time, I'm going to win.$"

NationalParkGateEast_Text_SamuelPlayerLost:
	.string "SAMUEL: Next time, I think I can\n"
	.string "score even higher.$"

NationalParkGateEast_Text_BarryPlayerWon:
	.string "BARRY: That POKéMON you caught…\n"
	.string "It's awesome!$"

NationalParkGateEast_Text_BarryPlayerLost:
	.string "BARRY: It's easier to win if you get\n"
	.string "a high-level bug POKéMON.\p"
	.string "But I think they also consider some\n"
	.string "other points.$"

NationalParkGateEast_Text_EdPlayerWon:
	.string "ED: I envy you.\n"
	.string "I just couldn't do it this time.$"

NationalParkGateEast_Text_EdPlayerLost:
	.string "ED: Maybe you win with rare POKéMON?$"

NationalParkGateEast_Text_BennyPlayerWon:
	.string "BENNY: Congrats!\n"
	.string "You have earned my respect!$"

NationalParkGateEast_Text_BennyPlayerLost:
	.string "BENNY: I caught a SCYTHER before,\n"
	.string "but I didn't win.$"

NationalParkGateEast_Text_JoshPlayerWon:
	.string "JOSH: I… I can't believe I\n"
	.string "lost at bug-catching…$"

NationalParkGateEast_Text_JoshPlayerLost:
	.string "JOSH: I heard that somebody won\n"
	.string "with a CATERPIE!$"

NationalParkGateEast_Text_DonPlayerWon:
	.string "DON: Wow, you beat me.\n"
	.string "You're pretty good.$"

NationalParkGateEast_Text_DonPlayerLost:
	.string "DON: Luck plays a big part in this.\p"
	.string "You never know what POKéMON will\n"
	.string "appear.$"

NationalParkGateEast_Text_KippPlayerWon:
	.string "KIPP: Could you give me some tips?\n"
	.string "I want to study your style.$"

NationalParkGateEast_Text_KippPlayerLost:
	.string "KIPP: I study a lot, but that's not\n"
	.string "good enough to win.$"

NationalParkGateEast_Text_CindyPlayerWon:
	.string "CINDY: You won?\n"
	.string "That's great!\p"
	.string "Do you feel like looking for more\n"
	.string "bug POKéMON with me?$"

NationalParkGateEast_Text_CindyPlayerLost:
	.string "CINDY: I really love bug POKéMON!$"
