NewBarkTown_ProfessorElmsLab_MapScripts:: @ 81F9C91
	map_script 3, NewBarkTown_ProfessorElmsLab_MapScript1_Type3
	map_script 2, NewBarkTown_ProfessorElmsLab_MapScript2_Type2
	.byte 0

NewBarkTown_ProfessorElmsLab_MapScript1_Type3:
	compare VAR_NEWBARK_STATE, 1
	call_if_eq NewBarkTown_ProfessorElmsLab_EventScript_MoveElmToPC
	end

NewBarkTown_ProfessorElmsLab_EventScript_MoveElmToPC:
	setobjectxyperm 2, 4, 5
	return

NewBarkTown_ProfessorElmsLab_MapScript2_Type2:
	map_script_2 VAR_NEWBARK_STATE, 1, NewBarkTown_ProfessorElmsLab_EventScript_ElmIntroduction
	.2byte 0

NewBarkTown_ProfessorElmsLab_EventScript_ElmIntroduction:
	lockall
	textcolor MSG_COLOR_BLUE
	applymovement EVENT_OBJ_ID_PLAYER, NewBarkTown_ProfessorElmsLab_Movement_PlayerStepToElm
	waitmovement 0
	playse SE_PIN
	applymovement 2, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	applymovement 2, Common_Movement_WalkInPlaceRight
	waitmovement 0
	msgbox NewBarkTown_ProfessorElmsLab_Text_ElmIntro, MSGBOX_YESNO
NewBarkTown_ProfessorElmsLab_EventScript_ElmBegs:
	compare VAR_RESULT, 1
	goto_if_eq NewBarkTown_ProfessorElmsLab_EventScript_ElmAccepted
	msgbox NewBarkTown_ProfessorElmsLab_Text_ElmBegs, MSGBOX_YESNO
	goto NewBarkTown_ProfessorElmsLab_EventScript_ElmBegs

NewBarkTown_ProfessorElmsLab_EventScript_ElmAccepted:
	msgbox NewBarkTown_ProfessorElmsLab_Text_ElmAccepted
	closemessage
	delay 20
	playse SE_SEIKAI
	waitse
	delay 20
	playse SE_PIN
	applymovement 2, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	applymovement 2, Common_Movement_WalkInPlaceDown
	waitmovement 0
	msgbox NewBarkTown_ProfessorElmsLab_Text_ElmGotAnEmail
	closemessage
	delay 30
	applymovement 2, Common_Movement_WalkInPlaceRight
	waitmovement 0
	msgbox NewBarkTown_ProfessorElmsLab_Text_ElmsAcquaintance
	closemessage
	applymovement EVENT_OBJ_ID_PLAYER, NewBarkTown_ProfessorElmsLab_Movement_PlayerWatchElmWalk
	applymovement 2, NewBarkTown_ProfessorElmsLab_Movement_ElmWalkToPokeBalls
	waitmovement 0
	msgbox NewBarkTown_ProfessorElmsLab_Text_RaiseAPokemon
	closemessage
	setvar VAR_NEWBARK_STATE, 2
	releaseall
	end

NewBarkTown_ProfessorElmsLab_Movement_PlayerStepToElm:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	step_end

NewBarkTown_ProfessorElmsLab_Movement_PlayerWatchElmWalk:
	delay_16
	walk_in_place_fastest_up
	delay_16
	walk_in_place_fastest_right
	step_end

NewBarkTown_ProfessorElmsLab_Movement_ElmWalkToPokeBalls:
	walk_up
	walk_up
	walk_right
	walk_right
	face_down
	step_end

NewBarkTown_ProfessorElmsLab_EventScript_ElmWaitDontGo::
	lockall
	textcolor MSG_COLOR_BLUE
	turnobject 2, 1
	msgbox NewBarkTown_ProfessorElmsLab_Text_ElmWaitWhereAreYouGoing
	closemessage
	applymovement EVENT_OBJ_ID_PLAYER, NewBarkTown_ProfessorElmsLab_Movement_PlayerComeBack
	waitmovement 0
	releaseall
	end

NewBarkTown_ProfessorElmsLab_Movement_PlayerComeBack:
	walk_up
	step_end

NewBarkTown_ProfessorElmsLab_EventScript_Elm::
	lock
	faceplayer
	goto_if_set FLAG_GAVE_MYSTERY_EGG_TO_ELM, NewBarkTown_ProfessorElmsLab_EventScript_ElmWithEgg
	goto_if_set FLAG_RECEIVED_MYSTERY_EGG, NewBarkTown_ProfessorElmsLab_EventScript_ElmPostTheft
	goto_if_set FLAG_SYS_POKEMON_GET, NewBarkTown_ProfessorElmsLab_EventScript_ElmMrPokemon
	msgbox NewBarkTown_ProfessorElmsLab_Text_ElmWildMonAdvice
	release
	end

NewBarkTown_ProfessorElmsLab_EventScript_ElmMrPokemon:
	msgbox NewBarkTown_ProfessorElmsLab_Text_ElmMrPokemon
	release
	end

NewBarkTown_ProfessorElmsLab_EventScript_ElmPostTheft:
	msgbox NewBarkTown_ProfessorElmsLab_Text_ElmThisIsTerrible
	textcolor MSG_COLOR_MISC
	msgbox NewBarkTown_ProfessorElmsLab_Text_ElmHandedMysteryEgg
	closemessage
	call RestoreOriginalTextColor
	takeitem ITEM_MYSTERY_EGG, 1
	delay 10
	compare VAR_FACING, 1
	call_if_eq NewBarkTown_ProfessorElmsLab_EventScript_ElmJumpsDown
	compare VAR_FACING, 2
	call_if_eq NewBarkTown_ProfessorElmsLab_EventScript_ElmJumpsUp
	compare VAR_FACING, 3
	call_if_eq NewBarkTown_ProfessorElmsLab_EventScript_ElmJumpsLeft
	compare VAR_FACING, 4
	call_if_eq NewBarkTown_ProfessorElmsLab_EventScript_ElmJumpsRight
	msgbox NewBarkTown_ProfessorElmsLab_Text_ElmIsThisAnEgg
	setflag FLAG_ADVENTURE_STARTED
	setflag FLAG_GAVE_MYSTERY_EGG_TO_ELM
	setflag FLAG_HIDE_ROUTE_30_YOUNGSTER_BATTLE_OBJECTS
	clearflag FLAG_HIDE_ROUTE_30_YOUNGSTER_DEFEATED
	setvar VAR_LAVARIDGE_TOWN_STATE, 1
	setvar VAR_NEWBARK_STATE, 7
	setvar VAR_CABLE_CLUB_TUTORIAL_STATE, 1
	release
	end

NewBarkTown_ProfessorElmsLab_EventScript_ElmJumpsDown:
	playse SE_DANSA
	applymovement 2, NewBarkTown_ProfessorElmsLab_Movement_ElmJumpsDown
	waitmovement 0
	msgbox NewBarkTown_ProfessorElmsLab_Text_ElmThis
	closemessage
	applymovement 2, NewBarkTown_ProfessorElmsLab_Movement_ElmStepsUp
	waitmovement 0
	return

NewBarkTown_ProfessorElmsLab_Movement_ElmJumpsDown:
	lock_facing_direction
	disable_jump_landing_ground_effect
	jump_down
	unlock_facing_direction
	step_end

NewBarkTown_ProfessorElmsLab_Movement_ElmStepsUp:
	walk_up
	step_end

NewBarkTown_ProfessorElmsLab_EventScript_ElmJumpsUp:
	playse SE_DANSA
	applymovement 2, NewBarkTown_ProfessorElmsLab_Movement_ElmJumpsUp
	waitmovement 0
	msgbox NewBarkTown_ProfessorElmsLab_Text_ElmThis
	closemessage
	applymovement 2, NewBarkTown_ProfessorElmsLab_Movement_ElmStepsDown
	waitmovement 0
	return

NewBarkTown_ProfessorElmsLab_Movement_ElmJumpsUp:
	lock_facing_direction
	disable_jump_landing_ground_effect
	jump_up
	unlock_facing_direction
	step_end

NewBarkTown_ProfessorElmsLab_Movement_ElmStepsDown:
	walk_down
	step_end

NewBarkTown_ProfessorElmsLab_EventScript_ElmJumpsLeft:
	playse SE_DANSA
	applymovement 2, NewBarkTown_ProfessorElmsLab_Movement_ElmJumpsLeft
	waitmovement 0
	msgbox NewBarkTown_ProfessorElmsLab_Text_ElmThis
	closemessage
	applymovement 2, NewBarkTown_ProfessorElmsLab_Movement_ElmStepsRight
	waitmovement 0
	return

NewBarkTown_ProfessorElmsLab_Movement_ElmJumpsLeft:
	lock_facing_direction
	disable_jump_landing_ground_effect
	jump_left
	unlock_facing_direction
	step_end

NewBarkTown_ProfessorElmsLab_Movement_ElmStepsRight:
	walk_right
	step_end

NewBarkTown_ProfessorElmsLab_EventScript_ElmJumpsRight:
	playse SE_DANSA
	applymovement 2, NewBarkTown_ProfessorElmsLab_Movement_ElmJumpsRight
	waitmovement 0
	msgbox NewBarkTown_ProfessorElmsLab_Text_ElmThis
	closemessage
	applymovement 2, NewBarkTown_ProfessorElmsLab_Movement_ElmStepsLeft
	waitmovement 0
	return

NewBarkTown_ProfessorElmsLab_Movement_ElmJumpsRight:
	lock_facing_direction
	disable_jump_landing_ground_effect
	jump_right
	unlock_facing_direction
	step_end

NewBarkTown_ProfessorElmsLab_Movement_ElmStepsLeft:
	walk_left
	step_end

NewBarkTown_ProfessorElmsLab_EventScript_ElmWithEgg:
	msgbox NewBarkTown_ProfessorElmsLab_Text_ElmDontGiveUp
	release
	end

NewBarkTown_ProfessorElmsLab_EventScript_Chikorita::
	lock
	faceplayer
	setvar VAR_TEMP_1, 0
	setvar VAR_TEMP_2, SPECIES_CHIKORITA
	goto NewBarkTown_EventScript_PokeBallMain

NewBarkTown_ProfessorElmsLab_EventScript_Totodile::
	lock
	faceplayer
	setvar VAR_TEMP_1, 1
	setvar VAR_TEMP_2, SPECIES_TOTODILE
	goto NewBarkTown_EventScript_PokeBallMain

NewBarkTown_ProfessorElmsLab_EventScript_Cyndaquil::
	lock
	faceplayer
	setvar VAR_TEMP_1, 2
	setvar VAR_TEMP_2, SPECIES_CYNDAQUIL
	goto NewBarkTown_EventScript_PokeBallMain

NewBarkTown_EventScript_PokeBallMain:
	goto_if_unset FLAG_SYS_POKEMON_GET, NewBarkTown_EventScript_PokeBallChoice
	msgbox NewBarkTown_ProfessorElmsLab_Text_ItContainsAMon
	release
	end

NewBarkTown_EventScript_PokeBallChoice:
	turnobject 2, 4
	drawmonpic VAR_TEMP_2, 10, 3
	textcolor MSG_COLOR_BLUE
	compare VAR_TEMP_1, 0
	goto_if_eq NewBarkTown_EventScript_ChoosingChikorita
	compare VAR_TEMP_1, 1
	goto_if_eq NewBarkTown_EventScript_ChoosingTotodile
	compare VAR_TEMP_1, 2
	goto_if_eq NewBarkTown_EventScript_ChoosingCyndaquil
	end

NewBarkTown_EventScript_ChoosingCyndaquil:
	msgbox NewBarkTown_ProfessorElmsLab_Text_Cyndaquil, MSGBOX_YESNO
	goto NewBarkTown_EventScript_ChoosingMon

NewBarkTown_EventScript_ChoosingTotodile:
	msgbox NewBarkTown_ProfessorElmsLab_Text_Totodile, MSGBOX_YESNO
	goto NewBarkTown_EventScript_ChoosingMon

NewBarkTown_EventScript_ChoosingChikorita:
	msgbox NewBarkTown_ProfessorElmsLab_Text_Chikorita, MSGBOX_YESNO
	goto NewBarkTown_EventScript_ChoosingMon

NewBarkTown_EventScript_ChoosingMon:
	compare VAR_RESULT, 1
	goto_if_eq NewBarkTown_EventScript_ChoseMon
	erasemonpic
	msgbox NewBarkTown_ProfessorElmsLab_Text_ThinkItOver
	release
	end

NewBarkTown_EventScript_ChoseMon:
	erasemonpic
	removeobject VAR_LAST_TALKED
	msgbox NewBarkTown_ProfessorElmsLab_Text_GreatMonToo
	call RestoreOriginalTextColor
	setflag FLAG_SYS_POKEMON_GET
	givemon VAR_TEMP_2, 5, ITEM_ORAN_BERRY, 0, 0, 0
	copyvar VAR_STARTER_MON, VAR_TEMP_1
	bufferspeciesname 0, VAR_TEMP_2
	message NewBarkTown_ProfessorElmsLab_Text_GotMonFromElm
	waitmessage
	playfanfare MUS_RG_FAN5
	waitfanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	compare VAR_RESULT, 1
	call_if_eq NewBarkTown_ProfessorElmsLab_EventScript_Nickname
	closemessage
	compare VAR_FACING, 1
	goto_if_eq NewBarkTown_ProfessorElmsLab_EventScript_BallFromAbove
	compare VAR_FACING, 2
	goto_if_eq NewBarkTown_ProfessorElmsLab_EventScript_BallFromBelow
	compare VAR_FACING, 4
	goto_if_eq NewBarkTown_ProfessorElmsLab_EventScript_BallFromLeft
	end

NewBarkTown_ProfessorElmsLab_EventScript_BallFromAbove:
	compare VAR_TEMP_1, 0
	goto_if_eq NewBarkTown_ProfessorElmsLab_EventScript_ChikoritaFromAbove
	compare VAR_TEMP_1, 1
	goto_if_eq NewBarkTown_ProfessorElmsLab_EventScript_TotodileFromAbove
	compare VAR_TEMP_1, 2
	goto_if_eq NewBarkTown_ProfessorElmsLab_EventScript_CyndaquilFromAbove
	end

NewBarkTown_ProfessorElmsLab_EventScript_ChikoritaFromAbove:
	applymovement 2, NewBarkTown_ProfessorElmsLab_Movement_Delay32FaceDown
	applymovement EVENT_OBJ_ID_PLAYER, NewBarkTown_ProfessorElmsLab_Movement_WalkToElmFrom83
	goto NewBarkTown_ProfessorElmsLab_EventScript_AfterMonGet

NewBarkTown_ProfessorElmsLab_Movement_Delay32FaceDown:
	delay_16
	delay_16
	walk_in_place_fastest_down
	step_end

NewBarkTown_ProfessorElmsLab_Movement_WalkToElmFrom83:
	walk_left
	walk_down
	walk_left
	face_up
	step_end

NewBarkTown_ProfessorElmsLab_EventScript_TotodileFromAbove:
	applymovement 2, NewBarkTown_ProfessorElmsLab_Movement_Delay48FaceDown
	applymovement EVENT_OBJ_ID_PLAYER, NewBarkTown_ProfessorElmsLab_Movement_WalkToElmFrom93
	goto NewBarkTown_ProfessorElmsLab_EventScript_AfterMonGet

NewBarkTown_ProfessorElmsLab_Movement_Delay48FaceDown:
	delay_16
	delay_16
	delay_16
	walk_in_place_fastest_down
	step_end

NewBarkTown_ProfessorElmsLab_Movement_WalkToElmFrom93:
	walk_left
	walk_left
	walk_down
	walk_left
	face_up
	step_end

NewBarkTown_ProfessorElmsLab_EventScript_CyndaquilFromAbove:
	applymovement 2, NewBarkTown_ProfessorElmsLab_Movement_Delay64FaceDown
	applymovement EVENT_OBJ_ID_PLAYER, NewBarkTown_ProfessorElmsLab_Movement_WalkToElmFrom103
	goto NewBarkTown_ProfessorElmsLab_EventScript_AfterMonGet

NewBarkTown_ProfessorElmsLab_Movement_Delay64FaceDown:
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_fastest_down
	step_end

NewBarkTown_ProfessorElmsLab_Movement_WalkToElmFrom103:
	walk_left
	walk_left
	walk_left
	walk_down
	walk_left
	face_up
	step_end

NewBarkTown_ProfessorElmsLab_EventScript_BallFromLeft:
	applymovement 2, Common_Movement_WalkInPlaceDown
	applymovement EVENT_OBJ_ID_PLAYER, NewBarkTown_ProfessorElmsLab_Movement_WalkToElmFrom74
	goto NewBarkTown_ProfessorElmsLab_EventScript_AfterMonGet

NewBarkTown_ProfessorElmsLab_Movement_WalkToElmFrom74:
	walk_left
	face_up
	step_end

NewBarkTown_ProfessorElmsLab_EventScript_BallFromBelow:
	compare VAR_TEMP_1, 0
	goto_if_eq NewBarkTown_ProfessorElmsLab_EventScript_ChikoritaFromBelow
	compare VAR_TEMP_1, 1
	goto_if_eq NewBarkTown_ProfessorElmsLab_EventScript_TotodileFromBelow
	compare VAR_TEMP_1, 2
	goto_if_eq NewBarkTown_ProfessorElmsLab_EventScript_CyndaquilFromBelow
	end

NewBarkTown_ProfessorElmsLab_EventScript_ChikoritaFromBelow:
	applymovement 2, NewBarkTown_ProfessorElmsLab_Movement_Delay16FaceDown
	applymovement EVENT_OBJ_ID_PLAYER, NewBarkTown_ProfessorElmsLab_Movement_WalkToElmFrom85
	goto NewBarkTown_ProfessorElmsLab_EventScript_AfterMonGet

NewBarkTown_ProfessorElmsLab_Movement_Delay16FaceDown:
	delay_16
	walk_in_place_fastest_down
	step_end

NewBarkTown_ProfessorElmsLab_Movement_WalkToElmFrom85:
	walk_left
	walk_left
	walk_up
	step_end

NewBarkTown_ProfessorElmsLab_EventScript_TotodileFromBelow:
	applymovement 2, NewBarkTown_ProfessorElmsLab_Movement_Delay32FaceDown
	applymovement EVENT_OBJ_ID_PLAYER, NewBarkTown_ProfessorElmsLab_Movement_WalkToElmFrom95
	goto NewBarkTown_ProfessorElmsLab_EventScript_AfterMonGet

NewBarkTown_ProfessorElmsLab_Movement_WalkToElmFrom95:
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

NewBarkTown_ProfessorElmsLab_EventScript_CyndaquilFromBelow:
	applymovement 2, NewBarkTown_ProfessorElmsLab_Movement_Delay48FaceDown
	applymovement EVENT_OBJ_ID_PLAYER, NewBarkTown_ProfessorElmsLab_Movement_WalkToElmFrom105
	goto NewBarkTown_ProfessorElmsLab_EventScript_AfterMonGet

NewBarkTown_ProfessorElmsLab_Movement_WalkToElmFrom105:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

NewBarkTown_ProfessorElmsLab_EventScript_Nickname:
	setvar VAR_0x8004, 0
	call Common_EventScript_NameReceivedPokemon
	return

NewBarkTown_ProfessorElmsLab_EventScript_AfterMonGet:
	waitmovement 0
	textcolor MSG_COLOR_BLUE
	msgbox NewBarkTown_ProfessorElmsLab_Text_ElmDirectionsToMrPokemon
	closemessage
	delay 20
	setflag FLAG_PHONE_CARD_ELM
	playfanfare MUS_ME_TORE_EYE
	call RestoreOriginalTextColor
	msgbox NewBarkTown_ProfessorElmsLab_Text_GotElmsNumber, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 10
	applymovement 2, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	textcolor MSG_COLOR_BLUE
	msgbox NewBarkTown_ProfessorElmsLab_Text_ElmMachineDirections, MSGBOX_DEFAULT
	applymovement 2, Common_Movement_WalkInPlaceDown
	waitmovement 0
	msgbox NewBarkTown_ProfessorElmsLab_Text_ElmCountingOnYou, MSGBOX_DEFAULT
	setvar VAR_NEWBARK_STATE, 3
	release
	end

NewBarkTown_ProfessorElmsLab_EventScript_AidePotion1::
	lockall
	setvar VAR_TEMP_1, 0
	applymovement 1, NewBarkTown_ProfessorElmsLab_Movement_AideToLeftTrigger
	waitmovement 0
	goto NewBarkTown_ProfessorElmsLab_EventScript_AidePotionMain

NewBarkTown_ProfessorElmsLab_Movement_AideToLeftTrigger:
	walk_right
	walk_right
	face_up
	step_end

NewBarkTown_ProfessorElmsLab_EventScript_AidePotion2::
	lockall
	setvar VAR_TEMP_1, 1
	applymovement 1, NewBarkTown_ProfessorElmsLab_Movement_AideToMiddleTrigger
	waitmovement 0
	goto NewBarkTown_ProfessorElmsLab_EventScript_AidePotionMain

NewBarkTown_ProfessorElmsLab_Movement_AideToMiddleTrigger:
	walk_right
	walk_right
	walk_right
	face_up
	step_end

NewBarkTown_ProfessorElmsLab_EventScript_AidePotion3::
	lockall
	setvar VAR_TEMP_1, 2
	applymovement 1, NewBarkTown_ProfessorElmsLab_Movement_AideToRightTrigger
	waitmovement 0
	goto NewBarkTown_ProfessorElmsLab_EventScript_AidePotionMain

NewBarkTown_ProfessorElmsLab_Movement_AideToRightTrigger:
	walk_right
	walk_right
	walk_right
	walk_right
	face_up
	step_end

NewBarkTown_ProfessorElmsLab_EventScript_AidePotionMain:
	textcolor MSG_COLOR_BLUE
	msgbox NewBarkTown_ProfessorElmsLab_Text_Aide_TakeThisForErrand
	giveitem_std ITEM_POTION
	msgbox NewBarkTown_ProfessorElmsLab_Text_Aide_AlwaysBusy
	closemessage
	compare VAR_TEMP_1, 0
	call_if_eq NewBarkTown_ProfessorElmsLab_EventScript_AidePotionReturnFromLeft
	compare VAR_TEMP_1, 1
	call_if_eq NewBarkTown_ProfessorElmsLab_EventScript_AidePotionReturnFromMiddle
	compare VAR_TEMP_1, 2
	call_if_eq NewBarkTown_ProfessorElmsLab_EventScript_AidePotionReturnFromRight
	setvar VAR_NEWBARK_STATE, 4
	releaseall
	end

NewBarkTown_ProfessorElmsLab_EventScript_AidePotionReturnFromLeft:
	applymovement 1, NewBarkTown_ProfessorElmsLab_Movement_AideFromLeftTrigger
	waitmovement 0
	return

NewBarkTown_ProfessorElmsLab_Movement_AideFromLeftTrigger:
	walk_left
	walk_left
	step_end

NewBarkTown_ProfessorElmsLab_EventScript_AidePotionReturnFromMiddle:
	applymovement 1, NewBarkTown_ProfessorElmsLab_Movement_AideFromMiddleTrigger
	waitmovement 0
	return

NewBarkTown_ProfessorElmsLab_Movement_AideFromMiddleTrigger:
	walk_left
	walk_left
	walk_left
	step_end

NewBarkTown_ProfessorElmsLab_EventScript_AidePotionReturnFromRight:
	applymovement 1, NewBarkTown_ProfessorElmsLab_Movement_AideFromMiddleTrigger
	waitmovement 0
	return

NewBarkTown_ProfessorElmsLab_Movement_AideFromRightTrigger:
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

NewBarkTown_ProfessorElmsLab_EventScript_AideBalls1::
	lockall
	setvar VAR_TEMP_1, 0
	applymovement 1, NewBarkTown_ProfessorElmsLab_Movement_AideToLeftTrigger
	waitmovement 0
	goto NewBarkTown_ProfessorElmsLab_EventScript_AideBallsMain

NewBarkTown_ProfessorElmsLab_EventScript_AideBalls2::
	lockall
	setvar VAR_TEMP_1, 1
	applymovement 1, NewBarkTown_ProfessorElmsLab_Movement_AideToMiddleTrigger
	waitmovement 0
	goto NewBarkTown_ProfessorElmsLab_EventScript_AideBallsMain

NewBarkTown_ProfessorElmsLab_EventScript_AideBalls3::
	lockall
	setvar VAR_TEMP_1, 2
	applymovement 1, NewBarkTown_ProfessorElmsLab_Movement_AideToRightTrigger
	waitmovement 0
	goto NewBarkTown_ProfessorElmsLab_EventScript_AideBallsMain

NewBarkTown_ProfessorElmsLab_EventScript_AideBallsMain:
	textcolor MSG_COLOR_BLUE
	msgbox NewBarkTown_ProfessorElmsLab_Text_Aide_TakeBalls
	giveitem_std ITEM_POKE_BALL, 5
	msgbox NewBarkTown_ProfessorElmsLab_Text_Aide_BallExplanation
	closemessage
	compare VAR_TEMP_1, 0
	call_if_eq NewBarkTown_ProfessorElmsLab_EventScript_AidePotionReturnFromLeft
	compare VAR_TEMP_1, 1
	call_if_eq NewBarkTown_ProfessorElmsLab_EventScript_AidePotionReturnFromMiddle
	compare VAR_TEMP_1, 2
	call_if_eq NewBarkTown_ProfessorElmsLab_EventScript_AidePotionReturnFromRight
	setvar VAR_NEWBARK_STATE, 8
	releaseall
	end

NewBarkTown_ProfessorElmsLab_EventScript_Officer1::
	lockall
	setvar VAR_TEMP_1, 0
	applymovement 3, NewBarkTown_ProfessorElmsLab_Movement_OfficerWaitFaceLeft
	applymovement EVENT_OBJ_ID_PLAYER, NewBarkTown_ProfessorElmsLab_Movement_PlayerToOfficerFromLeft
	waitmovement 0
	goto NewBarkTown_ProfessorElmsLab_EventScript_OfficerMain

NewBarkTown_ProfessorElmsLab_Movement_OfficerWaitFaceLeft:
	delay_16
	delay_16
	delay_16
	walk_in_place_fastest_left
	step_end

NewBarkTown_ProfessorElmsLab_Movement_PlayerToOfficerFromLeft:
	walk_up
	walk_up
	walk_up
	face_right
	step_end

NewBarkTown_ProfessorElmsLab_EventScript_Officer2::
	lockall
	setvar VAR_TEMP_1, 1
	applymovement 3, NewBarkTown_ProfessorElmsLab_Movement_OfficerWaitFaceLeftFromCenter
	applymovement EVENT_OBJ_ID_PLAYER, NewBarkTown_ProfessorElmsLab_Movement_PlayerToOfficerFromCenter
	waitmovement 0
	goto NewBarkTown_ProfessorElmsLab_EventScript_OfficerMain

NewBarkTown_ProfessorElmsLab_Movement_OfficerWaitFaceLeftFromCenter:
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_fastest_left
	step_end

NewBarkTown_ProfessorElmsLab_Movement_PlayerToOfficerFromCenter:
	walk_left
	walk_up
	walk_up
	walk_up
	face_right
	step_end

NewBarkTown_ProfessorElmsLab_EventScript_Officer3::
	lockall
	setvar VAR_TEMP_1, 2
	applymovement 3, NewBarkTown_ProfessorElmsLab_Movement_OfficerWaitFaceRight
	applymovement EVENT_OBJ_ID_PLAYER, NewBarkTown_ProfessorElmsLab_Movement_PlayerToOfficerFromRight
	waitmovement 0
	goto NewBarkTown_ProfessorElmsLab_EventScript_OfficerMain

NewBarkTown_ProfessorElmsLab_Movement_OfficerWaitFaceRight:
	delay_16
	delay_16
	delay_16
	walk_in_place_fastest_right
	step_end

NewBarkTown_ProfessorElmsLab_Movement_PlayerToOfficerFromRight:
	walk_up
	walk_up
	walk_up
	face_left
	step_end

NewBarkTown_ProfessorElmsLab_EventScript_OfficerMain:
	textcolor MSG_COLOR_BLUE
	msgbox NewBarkTown_ProfessorElmsLab_Text_Officer_MonStolen
NewBarkTown_ProfessorElmsLab_EventScript_Officer_NameRival:
	fadescreen 1
	special SetRivalNickname
	waitstate
	msgbox NewBarkTown_ProfessorElmsLab_Text_Officer_RivalNameConfirm, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq NewBarkTown_ProfessorElmsLab_EventScript_Officer_NameRival
	msgbox NewBarkTown_ProfessorElmsLab_Text_Officer_ThanksForTheHelp
	closemessage
	applymovement 3, NewBarkTown_ProfessorElmsLab_Movement_OfficerLeaves
	waitmovement 0
	removeobject 3
	setvar VAR_NEWBARK_STATE, 6
	releaseall
	end

NewBarkTown_ProfessorElmsLab_Movement_OfficerLeaves:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

NewBarkTown_ProfessorElmsLab_EventScript_Aide::
	lock
	faceplayer
	goto_if_set FLAG_GAVE_MYSTERY_EGG_TO_ELM, NewBarkTown_ProfessorElmsLab_EventScript_Aide_BallExplanation
	goto_if_set FLAG_RECEIVED_MYSTERY_EGG, NewBarkTown_ProfessorElmsLab_EventScript_Aide_Testimony
	msgbox NewBarkTown_ProfessorElmsLab_Text_Aide_AlwaysBusy
	release
	end

NewBarkTown_ProfessorElmsLab_EventScript_Aide_Testimony:
	msgbox NewBarkTown_ProfessorElmsLab_Text_Aide_Testimony
	release
	end

NewBarkTown_ProfessorElmsLab_EventScript_Aide_BallExplanation:
	msgbox NewBarkTown_ProfessorElmsLab_Text_Aide_BallExplanation
	release
	end

NewBarkTown_ProfessorElmsLab_EventScript_OpenWindow::
	goto_if_set FLAG_VISITED_PETALBURG_CITY, NewBarkTown_ProfessorElmsLab_EventScript_PleasantBreeze
	goto_if_set FLAG_ELM_CALLED_ABOUT_STOLEN_MON, NewBarkTown_ProfessorElmsLab_EventScript_BrokeInHere
NewBarkTown_ProfessorElmsLab_EventScript_PleasantBreeze:
	msgbox NewBarkTown_ProfessorElmsLab_Text_OpenWindow, MSGBOX_SIGN
	end

NewBarkTown_ProfessorElmsLab_EventScript_BrokeInHere::
	msgbox NewBarkTown_ProfessorElmsLab_Text_BrokeInHere, MSGBOX_SIGN
	end

NewBarkTown_ProfessorElmsLab_EventScript_HealingMachine::
	lockall
	goto_if_unset FLAG_SYS_POKEMON_GET, NewBarkTown_ProfessorElmsLab_EventScript_UnknownMachine
	msgbox NewBarkTown_ProfessorElmsLab_Text_LikeToHealMon, MSGBOX_YESNO
	compare VAR_RESULT, 1
	call_if_eq NewBarkTown_ProfessorElmsLab_EventScript_HealMon
	releaseall
	end

NewBarkTown_ProfessorElmsLab_EventScript_HealMon:
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	return

NewBarkTown_ProfessorElmsLab_EventScript_UnknownMachine:
	msgbox NewBarkTown_ProfessorElmsLab_Text_WonderWhatThisDoes
	releaseall
	end

NewBarkTown_ProfessorElmsLab_EventScript_ElmsPC::
	msgbox NewBarkTown_ProfessorElmsLab_Text_Observations, MSGBOX_SIGN
	end

NewBarkTown_ProfessorElmsLab_EventScript_TrashCan::
	msgbox NewBarkTown_ProfessorElmsLab_Text_TrashCan, MSGBOX_SIGN
	end

NewBarkTown_ProfessorElmsLab_EventScript_Shelf1::
	lockall
	msgbox NewBarkTown_ProfessorElmsLab_Text_ShelfIntro
	signmsg
	msgbox NewBarkTown_ProfessorElmsLab_Text_Shelf1
	normalmsg
	releaseall
	end

NewBarkTown_ProfessorElmsLab_EventScript_Shelf2::
	lockall
	msgbox NewBarkTown_ProfessorElmsLab_Text_ShelfIntro
	signmsg
	msgbox NewBarkTown_ProfessorElmsLab_Text_Shelf2
	normalmsg
	releaseall
	end

NewBarkTown_ProfessorElmsLab_EventScript_Shelf3::
	lockall
	msgbox NewBarkTown_ProfessorElmsLab_Text_ShelfIntro
	signmsg
	msgbox NewBarkTown_ProfessorElmsLab_Text_Shelf3
	normalmsg
	releaseall
	end

NewBarkTown_ProfessorElmsLab_EventScript_Shelf4::
	lockall
	msgbox NewBarkTown_ProfessorElmsLab_Text_ShelfIntro
	signmsg
	msgbox NewBarkTown_ProfessorElmsLab_Text_Shelf4
	normalmsg
	releaseall
	end

NewBarkTown_ProfessorElmsLab_Text_ElmIntro:
	.string "ELM: {PLAYER}!\n"
	.string "There you are!\l"
	.string "I needed to ask you a favor.\p"
	.string "I'm conducting POKéMON research right\n"
	.string "now, and I was wondering if you\l"
	.string "could help me with it, {PLAYER}.\p"
	.string "You see…\p"
	.string "I'm writing a paper that I want to\n"
	.string "present at a conference.\p"
	.string "But there are some things I don't\n"
	.string "quite understand yet.\p"
	.string "So!\p"
	.string "I'd like you to raise a POKéMON\n"
	.string "that I recently caught.$"

NewBarkTown_ProfessorElmsLab_Text_ElmBegs:
	.string "But…\n"
	.string "Please, I need your help!$"

NewBarkTown_ProfessorElmsLab_Text_ElmAccepted:
	.string "Thanks, {PLAYER}!\n"
	.string "You're a great help!\p"
	.string "When I announce my findings, I'm sure\n"
	.string "we'll delve a bit deeper into the\l"
	.string "many mysteries of POKéMON.\p"
	.string "You can count on it!$"

NewBarkTown_ProfessorElmsLab_Text_ElmGotAnEmail:
	.string "Oh, hey!\n"
	.string "I got an e-mail!\p"
	.string "………………\n"
	.string "Hm… Uh-huh…\l"
	.string "Okay…$"

NewBarkTown_ProfessorElmsLab_Text_ElmsAcquaintance:
	.string "Hey, listen.\p"
	.string "I have an acquaintance called\n"
	.string "MR. POKéMON.\p"
	.string "He keeps finding weird things and\n"
	.string "raving about his discoveries.\p"
	.string "Anyway, I just got an e-mail from\n"
	.string "him saying that this time it's real.\p"
	.string "It is intriguing, but we're busy with\n"
	.string "our POKéMON research…\p"
	.string "Wait!\n"
	.string "I know!\p"
	.string "{PLAYER}, can you go in our place?$"

NewBarkTown_ProfessorElmsLab_Text_RaiseAPokemon:
	.string "I want you to raise one of the\n"
	.string "POKéMON contained in these\l"
	.string "POKé BALLS.\p"
	.string "You'll be that POKéMON's first\n"
	.string "partner, {PLAYER}!\p"
	.string "Go on. Pick one!$"

NewBarkTown_ProfessorElmsLab_Text_ElmWaitWhereAreYouGoing:
	.string "ELM: Wait!\n"
	.string "Where are you going?$"

NewBarkTown_ProfessorElmsLab_Text_ElmWildMonAdvice:
	.string "ELM: If a wild POKéMON appears, let\n"
	.string "your POKéMON battle it!$"

NewBarkTown_ProfessorElmsLab_Text_ElmMrPokemon:
	.string "ELM: MR. POKéMON goes everywhere\n"
	.string "and finds rarities.\p"
	.string "Too bad they're just rare and not\n"
	.string "very useful…$"

NewBarkTown_ProfessorElmsLab_Text_ElmThisIsTerrible:
	.string "ELM: {PLAYER}, this is terrible…\p"
	.string "Oh, yes, what was MR. POKéMON's big\n"
	.string "discovery?$"

NewBarkTown_ProfessorElmsLab_Text_ElmHandedMysteryEgg:
	.string "{PLAYER} handed the MYSTERY EGG to\n"
	.string "PROF. ELM.$"

NewBarkTown_ProfessorElmsLab_Text_ElmThis:
	.string "ELM: This?$"

NewBarkTown_ProfessorElmsLab_Text_ElmIsThisAnEgg:
	.string "But… Is it a POKéMON EGG?\n"
	.string "If it is, it's a great discovery!\p"
	.string "What?!?\n"
	.string "PROF. OAK gave you a POKéDEX?\p"
	.string "{PLAYER}, is that true?\n"
	.string "Th-that's incredible!\p"
	.string "He is superb at seeing the potential\n"
	.string "of people as TRAINERS.\p"
	.string "Wow, {PLAYER}. You may have what it\n"
	.string "takes to become the CHAMPION.\p"
	.string "You seem to be getting on great with\n"
	.string "POKéMON too.\p"
	.string "You should take the POKéMON GYM\n"
	.string "challenge.\p"
	.string "The closest GYM would be the one in\n"
	.string "VIOLET CITY.\p"
	.string "…{PLAYER}. The road to the championship\n"
	.string "will be a long one.\p"
	.string "Before you leave, make sure that\n"
	.string "you talk to your mom.$"

NewBarkTown_ProfessorElmsLab_Text_ElmDontGiveUp:
	.string "ELM: Don't give up! I'll call if I\n"
	.string "learn anything about that EGG!$"

NewBarkTown_ProfessorElmsLab_Text_Cyndaquil:
	.string "ELM: Oh! CYNDAQUIL is your choice.\n"
	.string "Raising it would be a cinch.\p"
	.string "So, {PLAYER}, you'll take CYNDAQUIL,\n"
	.string "the FIRE POKéMON?$"

NewBarkTown_ProfessorElmsLab_Text_Totodile:
	.string "ELM: Ah! TOTODILE is your choice.\n"
	.string "Raising it would be rewarding.\p"
	.string "So, {PLAYER}, do you want TOTODILE,\n"
	.string "the WATER POKéMON?$"

NewBarkTown_ProfessorElmsLab_Text_Chikorita:
	.string "ELM: Hm! CHIKORITA is your choice.\n"
	.string "Take your time raising it.\p"
	.string "So, {PLAYER}, do you like CHIKORITA,\n"
	.string "the GRASS POKéMON?$"

NewBarkTown_ProfessorElmsLab_Text_ThinkItOver:
	.string "ELM: Think it over carefully.\n"
	.string "Your partner is important.$"

NewBarkTown_ProfessorElmsLab_Text_GreatMonToo:
	.string "ELM: I think that's a great\n"
	.string "POKéMON too!$"

NewBarkTown_ProfessorElmsLab_Text_GotMonFromElm:
	.string "{PLAYER} received the {STR_VAR_1}\n"
	.string "from PROF. ELM!$"

NewBarkTown_ProfessorElmsLab_Text_ElmDirectionsToMrPokemon:
	.string "MR. POKéMON lives a little bit beyond\n"
	.string "CHERRYGROVE, the next city over.\p"
	.string "It's almost a direct route there,\n"
	.string "so you can't miss it.\p"
	.string "But just in case, here's my phone\n"
	.string "number. Call me if anything comes up!$"

NewBarkTown_ProfessorElmsLab_Text_GotElmsNumber:
	.string "{PLAYER} got PROF. ELM's phone number.$"

NewBarkTown_ProfessorElmsLab_Text_ElmMachineDirections:
	.string "If your POKéMON is hurt, you should\n"
	.string "heal it with this machine.\l"
	.string "Feel free to use it anytime.$"

NewBarkTown_ProfessorElmsLab_Text_ElmCountingOnYou:
	.string "{PLAYER}, I'm counting on you!$"

NewBarkTown_ProfessorElmsLab_Text_ItContainsAMon:
	.string "It contains a POKéMON caught by\n"
	.string "PROF. ELM.$"

NewBarkTown_ProfessorElmsLab_Text_Aide_TakeThisForErrand:
	.string "{PLAYER}, I want you to have this\n"
	.string "for your errand.$"

NewBarkTown_ProfessorElmsLab_Text_Aide_AlwaysBusy:
	.string "There are only two of us, so we're\n"
	.string "always busy.$"

NewBarkTown_ProfessorElmsLab_Text_Aide_TakeBalls:
	.string "{PLAYER}!\n"
	.string "Use these on your POKéDEX quest!$"

NewBarkTown_ProfessorElmsLab_Text_Aide_BallExplanation:
	.string "To add to your POKéDEX, you have to\n"
	.string "catch POKéMON.\p"
	.string "Throw POKé BALLS at wild POKéMON to\n"
	.string "get them.$"

NewBarkTown_ProfessorElmsLab_Text_Aide_Testimony:
	.string "There was a loud noise outside…\p"
	.string "When we went to look, someone stole\n"
	.string "a POKéMON off the table.\p"
	.string "It's unbelievable that anyone would\n"
	.string "do that!\p"
	.string "…sigh… That stolen POKéMON.\n"
	.string "I wonder how it's doing.\p"
	.string "They say a POKéMON raised by a bad\n"
	.string "person turns bad itself.$"

NewBarkTown_ProfessorElmsLab_Text_Officer_MonStolen:
	.string "I heard a POKéMON was stolen from\n"
	.string "here…\p"
	.string "I was just getting some information\n"
	.string "from PROF. ELM.\p"
	.string "Apparently, it was a young male with\n"
	.string "long, red hair…\p"
	.string "What? You're saying you battled a\n"
	.string "TRAINER like that?\p"
	.string "Did you happen to get his name?$"

NewBarkTown_ProfessorElmsLab_Text_Officer_RivalNameConfirm:
	.string "Let me make sure I got that right…\n"
	.string "So you said his name was {RIVAL}?$"

NewBarkTown_ProfessorElmsLab_Text_Officer_ThanksForTheHelp:
	.string "Okay! So {RIVAL} was his name.\n"
	.string "Thanks for helping my investigation!$"

NewBarkTown_ProfessorElmsLab_Text_OpenWindow:
	.string "The window is open.\n"
	.string "A pleasant breeze is blowing in.$"

NewBarkTown_ProfessorElmsLab_Text_BrokeInHere:
	.string "He must've broken in through here!$"

NewBarkTown_ProfessorElmsLab_Text_LikeToHealMon:
	.string "Would you like to heal your POKéMON?$"

NewBarkTown_ProfessorElmsLab_Text_WonderWhatThisDoes:
	.string "Wonder what this machine does?$"

NewBarkTown_ProfessorElmsLab_Text_Observations:
	.string "“OBSERVATIONS ON POKéMON\n"
	.string "EVOLUTION”, it says on the screen…$"

NewBarkTown_ProfessorElmsLab_Text_TrashCan:
	.string "The wrapper from the snack PROF. ELM\n"
	.string "ate is in there…$"

NewBarkTown_ProfessorElmsLab_Text_ShelfIntro:
	.string "{PLAYER} opened a book.$"

NewBarkTown_ProfessorElmsLab_Text_Shelf1:
	.string "Travel Tip 1:\n"
	.string "Press START to open the MENU.$"

NewBarkTown_ProfessorElmsLab_Text_Shelf2:
	.string "Travel Tip 2:\n"
	.string "Record your trip with SAVE!$"

NewBarkTown_ProfessorElmsLab_Text_Shelf3:
	.string "Travel Tip 3:\n"
	.string "Open your BAG and press SELECT\l"
	.string "to move items.$"

NewBarkTown_ProfessorElmsLab_Text_Shelf4:
	.string "Travel Tip 4:\n"
	.string "Check your POKéMON moves.\l"
	.string "Press the A Button to switch moves.$"
