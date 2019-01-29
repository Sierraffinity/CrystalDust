NewBarkTown_ProfessorElmsLab_MapScripts:: @ 81F9C91
	map_script 3, NewBarkTown_ProfessorElmsLab_MapScript1_Type3
	map_script 2, NewBarkTown_ProfessorElmsLab_MapScript2_Type2
	.byte 0

NewBarkTown_ProfessorElmsLab_MapScript1_Type3:
	compare VAR_0x4050, 1
	call_if_eq NewBarkTown_ProfessorElmsLab_EventScript_MoveElmToPC
	end

NewBarkTown_ProfessorElmsLab_EventScript_MoveElmToPC:
	setobjectxyperm 2, 4, 5
	return

NewBarkTown_ProfessorElmsLab_MapScript2_Type2:
	map_script_2 VAR_0x4050, 1, NewBarkTown_ProfessorElmsLab_EventScript_ElmIntroduction
	.2byte 0

NewBarkTown_ProfessorElmsLab_EventScript_ElmIntroduction:
	lockall
	textcolor MSG_COLOR_BLUE
	applymovement EVENT_OBJ_ID_PLAYER, NewBarkTown_ProfessorElmsLab_Movement_PlayerStepToElm
	waitmovement 0
	playse SE_PIN
	applymovement 2, Movement_Emote_Exclamation_Mark
	waitmovement 0
	applymovement 2, Movement_Delay_48
	waitmovement 0
	applymovement 2, Move_WalkInPlaceFastestRight
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
	applymovement 2, Movement_Emote_Exclamation_Mark
	waitmovement 0
	applymovement 2, Movement_Delay_48
	waitmovement 0
	applymovement 2, Move_WalkInPlaceFastestDown
	waitmovement 0
	msgbox NewBarkTown_ProfessorElmsLab_Text_ElmGotAnEmail
	closemessage
	delay 30
	applymovement 2, Move_WalkInPlaceFastestRight
	waitmovement 0
	msgbox NewBarkTown_ProfessorElmsLab_Text_ElmsAcquaintance
	closemessage
	applymovement EVENT_OBJ_ID_PLAYER, NewBarkTown_ProfessorElmsLab_Movement_PlayerWatchElmWalk
	applymovement 2, NewBarkTown_ProfessorElmsLab_Movement_ElmWalkToPokeBalls
	waitmovement 0
	msgbox NewBarkTown_ProfessorElmsLab_Text_RaiseAPokemon
	closemessage
	setvar VAR_0x4050, 2
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
	walk_right
	walk_right
	face_down
	step_end

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
	.string "POKéMON contained in these BALLS.\p"
	.string "You'll be that POKéMON's first\n"
	.string "partner, {PLAYER}!\p"
	.string "Go on. Pick one!$"
