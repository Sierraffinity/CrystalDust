NewBarkTown_MapScripts::
	map_script 3, NewBarkTown_MapScript1_1E7DDB
	map_script 2, NewBarkTown_MapScript2_1E7EC1
	map_script 4, NewBarkTown_MapScript2_1E7FE2
	.byte 0

NewBarkTown_MapScript1_1E7DDB:
	setflag FLAG_VISITED_NEW_BARK_TOWN
	clearflag FLAG_PLAYER_MUST_LEAVE_HOUSE_TO_BANK_WITH_MOM
	end

NewBarkTown_MapScript2_1E7EC1:
	@map_script_2 VAR_0x4092, 1, NewBarkTown_EventScript_1E7EDB
	@map_script_2 VAR_0x4092, 2, NewBarkTown_EventScript_1E7EF9
	@map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 1, NewBarkTown_EventScript_1E7FB1
	.2byte 0

NewBarkTown_MapScript2_1E7FE2:
	@map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 1, NewBarkTown_EventScript_1E7FEC
	.2byte 0

NewBarkTown_EventScript_FatMan::
	msgbox NewBarkTown_Text_FatMan, MSGBOX_NPC
	end

NewBarkTown_EventScript_Teacher::
	lock
	faceplayer
	goto_if_set FLAG_TALKED_TO_MOM_AFTER_MYSTERY_EGG_QUEST, NewBarkTown_EventScript_Teacher_CallMom
	goto_if_set FLAG_GAVE_MYSTERY_EGG_TO_ELM, NewBarkTown_EventScript_Teacher_TellMomYoureLeaving
	goto_if_set FLAG_SYS_POKEMON_GET, NewBarkTown_EventScript_Teacher_MonIsAdorable
	msgbox NewBarkTown_Text_GearImpressive
	release
	end

NewBarkTown_EventScript_Teacher_MonIsAdorable::
	msgbox NewBarkTown_Text_MonIsAdorable
	release
	end

NewBarkTown_EventScript_Teacher_TellMomYoureLeaving::
	msgbox NewBarkTown_Text_TellMomYoureLeaving
	release
	end

NewBarkTown_EventScript_Teacher_CallMom::
	msgbox NewBarkTown_Text_CallMom
	release
	end

NewBarkTown_EventScript_Rival::
	lockall
	msgbox NewBarkTown_Text_RivalText1
	closemessage
	delay 20
	faceplayer
	delay 20
	msgbox NewBarkTown_Text_RivalText2
	closemessage
	delay 10
	compare VAR_FACING, 2
	call_if_eq NewBarkTown_EventScript_Rival_FacingNorth
	compare VAR_FACING, 2
	call_if_ne NewBarkTown_EventScript_Rival_FacingRight
	delay 10
	playse SE_NOT_EFFECTIVE
	applymovement 3, NewBarkTown_Movement_RivalEncounter_RivalKicksPlayer
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_Movement_RivalEncounter_PlayerJumpsBack
	waitmovement 0
	applymovement 3, NewBarkTown_Movement_RivalEncounter_RivalStepsToWindow
	waitmovement 0
	releaseall
	end

NewBarkTown_EventScript_Rival_FacingNorth:
	applymovement 3, NewBarkTown_Movement_RivalEncounter_RivalStepsDown
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_Movement_RivalEncounter_PlayerStepsBackDown
	waitmovement 0
	return

NewBarkTown_EventScript_Rival_FacingRight:
	applymovement 3, NewBarkTown_Movement_RivalEncounter_RivalStepsLeft
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_Movement_RivalEncounter_PlayerStepsBackLeft
	waitmovement 0
	return

NewBarkTown_Movement_RivalEncounter_RivalStepsLeft:
	walk_left
	walk_down
	step_end

NewBarkTown_Movement_RivalEncounter_RivalStepsDown:
	walk_down
	walk_left
	face_down
	step_end

NewBarkTown_Movement_RivalEncounter_PlayerStepsBackLeft:
	face_up
	lock_facing_direction
	walk_down
	walk_down
	unlock_facing_direction
	step_end

NewBarkTown_Movement_RivalEncounter_PlayerStepsBackDown:
	face_right
	lock_facing_direction
	walk_left
	unlock_facing_direction
	face_up
	lock_facing_direction
	walk_down
	unlock_facing_direction
	step_end

NewBarkTown_Movement_RivalEncounter_RivalKicksPlayer:
	walk_in_place_down
	step_end

NewBarkTown_Movement_RivalEncounter_PlayerJumpsBack:
	lock_facing_direction
	jump_2_down
	unlock_facing_direction
	step_end

NewBarkTown_Movement_RivalEncounter_RivalStepsToWindow:
	walk_up
	walk_right
	step_end

NewBarkTown_EventScript_Teacher1::
	lockall
	setvar VAR_TEMP_1, 0
	goto NewBarkTown_EventScript_TeacherMain

NewBarkTown_EventScript_Teacher2::
	lockall
	setvar VAR_TEMP_1, 1
	goto NewBarkTown_EventScript_TeacherMain

NewBarkTown_EventScript_Teacher3::
	lockall
	setvar VAR_TEMP_1, 2
	goto NewBarkTown_EventScript_TeacherMain

NewBarkTown_EventScript_TeacherMain:
	textcolor MSG_COLOR_RED
	playbgm MUS_MOMS_THEME, 0
	turnobject 2, 3
	msgbox NewBarkTown_Text_WaitPlayer
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	delay 10
	compare VAR_TEMP_1, 0
	goto_if_eq  NewBarkTown_EventScript_TeacherToTopSpot
	compare VAR_TEMP_1, 1
	goto_if_eq  NewBarkTown_EventScript_TeacherToMiddleSpot
	compare VAR_TEMP_1, 2
	goto_if_eq  NewBarkTown_EventScript_TeacherToBottomSpot
	end

NewBarkTown_EventScript_TeacherToTopSpot:
	applymovement 2, NewBarkTown_Movement_TeacherToTopSpot
	goto NewBarkTown_EventScript_TeacherPostMoveToPlayer

NewBarkTown_Movement_TeacherToTopSpot:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

NewBarkTown_EventScript_TeacherToMiddleSpot:
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_Movement_PlayerTurnAfterWaitingForTeacher
	applymovement 2, NewBarkTown_Movement_TeacherToMiddleSpot
	goto NewBarkTown_EventScript_TeacherPostMoveToPlayer

NewBarkTown_Movement_PlayerTurnAfterWaitingForTeacher:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_fastest_up
	step_end

NewBarkTown_Movement_TeacherToMiddleSpot:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	face_down
	step_end

NewBarkTown_EventScript_TeacherToBottomSpot:
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_Movement_PlayerTurnAfterWaitingForTeacher
	applymovement 2, NewBarkTown_Movement_TeacherToBottomSpot
	goto NewBarkTown_EventScript_TeacherPostMoveToPlayer

NewBarkTown_Movement_TeacherToBottomSpot:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

NewBarkTown_EventScript_TeacherPostMoveToPlayer:
	waitmovement 0
	msgbox NewBarkTown_Text_WhatDoYouThinkYoureDoing
	closemessage
	compare VAR_TEMP_1, 0
	goto_if_eq  NewBarkTown_EventScript_TeacherAndPlayerFromTopSpot
	compare VAR_TEMP_1, 1
	goto_if_eq  NewBarkTown_EventScript_TeacherAndPlayerFromMiddleSpot
	compare VAR_TEMP_1, 2
	goto_if_eq  NewBarkTown_EventScript_TeacherAndPlayerFromBottomSpot
	end

NewBarkTown_EventScript_TeacherAndPlayerFromTopSpot:
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_Movement_PlayerFromTopSpot
	applymovement 2, NewBarkTown_Movement_TeacherFromTopSpot
	goto NewBarkTown_EventScript_TeacherPostReturn

NewBarkTown_Movement_PlayerFromTopSpot:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

NewBarkTown_Movement_TeacherFromTopSpot:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	face_left
	step_end

NewBarkTown_EventScript_TeacherAndPlayerFromMiddleSpot:
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_Movement_PlayerFromMiddleSpot
	applymovement 2, NewBarkTown_Movement_TeacherFromMiddleSpot
	goto NewBarkTown_EventScript_TeacherPostReturn

NewBarkTown_Movement_PlayerFromMiddleSpot:
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

NewBarkTown_Movement_TeacherFromMiddleSpot:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	face_left
	step_end

NewBarkTown_EventScript_TeacherAndPlayerFromBottomSpot:
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_Movement_PlayerFromBottomSpot
	applymovement 2, NewBarkTown_Movement_TeacherFromBottomSpot
	goto NewBarkTown_EventScript_TeacherPostReturn

NewBarkTown_Movement_PlayerFromBottomSpot:
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

NewBarkTown_Movement_TeacherFromBottomSpot:
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	face_left
	step_end

NewBarkTown_EventScript_TeacherPostReturn:
	waitmovement 0
	msgbox NewBarkTown_Text_ItsDangerousToGoAlone
	closemessage
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

NewBarkTown_EventScript_Slogan::
	msgbox NewBarkTown_Text_TownSlogan, MSGBOX_SIGN
	end

NewBarkTown_EventScript_ElmLab::
	msgbox NewBarkTown_Text_ElmLab, MSGBOX_SIGN
	end

NewBarkTown_EventScript_PlayersHouse::
	msgbox NewBarkTown_Text_PlayersHouse, MSGBOX_SIGN
	end

NewBarkTown_EventScript_ElmsHouse::
	msgbox NewBarkTown_Text_ElmsHouse, MSGBOX_SIGN
	end

NewBarkTown_Text_RivalText1:
	.string "… … …\p"
	.string "So this is the famous ELM POKéMON\n"
	.string "LAB…$"

NewBarkTown_Text_RivalText2:
	.string "…What are you staring at?$"

NewBarkTown_Text_FatMan:
	.string "Yo, {PLAYER}! I hear PROF. ELM\n"
	.string "discovered some new POKéMON.$"

NewBarkTown_Text_GearImpressive:
	.string "Wow, your POKéGEAR is impressive!\n"
	.string "Did your mom get it for you?$"

NewBarkTown_Text_MonIsAdorable:
	.string "Oh! Your POKéMON is adorable!\n"
	.string "I wish I had one!$"

NewBarkTown_Text_TellMomYoureLeaving:
	.string "Hi, {PLAYER}!\n"
	.string "Leaving again?\p"
	.string "You should tell your mom if you're\n"
	.string "leaving town.$"

NewBarkTown_Text_CallMom:
	.string "Call your mom on your POKéGEAR to\n"
	.string "let her know how you're doing.$"

NewBarkTown_Text_WaitPlayer:
	.string "Wait, {PLAYER}!$"

NewBarkTown_Text_WhatDoYouThinkYoureDoing:
	.string "What do you think you're doing?$"

NewBarkTown_Text_ItsDangerousToGoAlone:
	.string "It's dangerous to go out without a\n"
	.string "POKéMON!\p"
	.string "Wild POKéMON jump out of the grass\n"
	.string "on the way to the next town.$"

NewBarkTown_Text_TownSlogan:
	.string "NEW BARK TOWN\n"
	.string "The Town Where the Winds of a\l"
	.string "New Beginning Blow$"

NewBarkTown_Text_ElmLab:
	.string "ELM POKéMON LAB$"

NewBarkTown_Text_PlayersHouse:
	.string "{PLAYER}'s house$"

NewBarkTown_Text_ElmsHouse:
	.string "PROF. ELM'S HOUSE$"
