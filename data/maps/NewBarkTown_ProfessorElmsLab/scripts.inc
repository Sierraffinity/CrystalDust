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
	msgbox NewBarkTown_ProfessorElmsLab_Text_ElmWildMonAdvice
	release
	end

NewBarkTown_ProfessorElmsLab_EventScript_Cyndaquil::
	lock
	faceplayer
	setvar VAR_TEMP_1, 0
	setvar VAR_TEMP_2, SPECIES_CYNDAQUIL
	goto NewBarkTown_EventScript_PokeBallMain

NewBarkTown_ProfessorElmsLab_EventScript_Totodile::
	lock
	faceplayer
	setvar VAR_TEMP_1, 1
	setvar VAR_TEMP_2, SPECIES_TOTODILE
	goto NewBarkTown_EventScript_PokeBallMain

NewBarkTown_ProfessorElmsLab_EventScript_Chikorita::
	lock
	faceplayer
	setvar VAR_TEMP_1, 2
	setvar VAR_TEMP_2, SPECIES_CHIKORITA
	goto NewBarkTown_EventScript_PokeBallMain

NewBarkTown_EventScript_PokeBallMain:
	compare VAR_0x4050, 2
	goto_if_le NewBarkTown_EventScript_PokeBallChoice
	msgbox NewBarkTown_ProfessorElmsLab_Text_ItContainsAMon
	release
	end

NewBarkTown_EventScript_PokeBallChoice:
	turnobject 2, 4
	drawmonpic VAR_TEMP_2, 10, 3
	textcolor MSG_COLOR_BLUE
	compare VAR_TEMP_1, 0
	goto_if_eq NewBarkTown_EventScript_ChoosingCyndaquil
	compare VAR_TEMP_1, 1
	goto_if_eq NewBarkTown_EventScript_ChoosingTotodile
	compare VAR_TEMP_1, 2
	goto_if_eq NewBarkTown_EventScript_ChoosingChikorita
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
	call_if_eq NewBarkTown_EventScript_ChoseMon
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
	givemon VAR_TEMP_2, 5, ITEM_NONE, 0, 0, 0
	copyvar VAR_STARTER_MON, VAR_TEMP_1
	bufferspeciesname 0, VAR_TEMP_2
	message NewBarkTown_ProfessorElmsLab_Text_GotMonFromElm
	waitmessage
	playfanfare MUS_RG_FAN5
	waitfanfare
	msgbox gUnknown_08273374, MSGBOX_YESNO
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
	goto_if_eq NewBarkTown_ProfessorElmsLab_EventScript_CyndaquilFromAbove
	compare VAR_TEMP_1, 1
	goto_if_eq NewBarkTown_ProfessorElmsLab_EventScript_TotodileFromAbove
	compare VAR_TEMP_1, 2
	goto_if_eq NewBarkTown_ProfessorElmsLab_EventScript_ChikoritaFromAbove
	end

NewBarkTown_ProfessorElmsLab_EventScript_CyndaquilFromAbove:
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

NewBarkTown_ProfessorElmsLab_EventScript_ChikoritaFromAbove:
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
	applymovement 2, Move_WalkInPlaceFastestDown
	applymovement EVENT_OBJ_ID_PLAYER, NewBarkTown_ProfessorElmsLab_Movement_WalkToElmFrom74
	goto NewBarkTown_ProfessorElmsLab_EventScript_AfterMonGet

NewBarkTown_ProfessorElmsLab_Movement_WalkToElmFrom74:
	walk_left
	face_up
	step_end

NewBarkTown_ProfessorElmsLab_EventScript_BallFromBelow:
	compare VAR_TEMP_1, 0
	goto_if_eq NewBarkTown_ProfessorElmsLab_EventScript_CyndaquilFromBelow
	compare VAR_TEMP_1, 1
	goto_if_eq NewBarkTown_ProfessorElmsLab_EventScript_TotodileFromBelow
	compare VAR_TEMP_1, 2
	goto_if_eq NewBarkTown_ProfessorElmsLab_EventScript_ChikoritaFromBelow
	end

NewBarkTown_ProfessorElmsLab_EventScript_CyndaquilFromBelow:
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

NewBarkTown_ProfessorElmsLab_EventScript_ChikoritaFromBelow:
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
	call EventScript_ChangePokemonNickname
	return

NewBarkTown_ProfessorElmsLab_EventScript_AfterMonGet:
	waitmovement 0
	textcolor MSG_COLOR_BLUE
	msgbox NewBarkTown_ProfessorElmsLab_Text_ElmDirectionsToMrPokemon
	closemessage
	delay 20
	setflag FLAG_ENABLE_PROF_ELM_MATCH_CALL
	playfanfare MUS_ME_TORE_EYE
	call RestoreOriginalTextColor
	msgbox NewBarkTown_ProfessorElmsLab_Text_GotElmsNumber, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 10
	applymovement 2, Move_WalkInPlaceFastestLeft
	waitmovement 0
	textcolor MSG_COLOR_BLUE
	msgbox NewBarkTown_ProfessorElmsLab_Text_ElmMachineDirections, MSGBOX_DEFAULT
	applymovement 2, Move_WalkInPlaceFastestDown
	waitmovement 0
	msgbox NewBarkTown_ProfessorElmsLab_Text_ElmCountingOnYou, MSGBOX_DEFAULT
	setvar VAR_0x4050, 3
	release
	end

NewBarkTown_ProfessorElmsLab_EventScript_Aide::
	lock
	faceplayer
	msgbox NewBarkTown_ProfessorElmsLab_Text_Aide_AlwaysBusy
	release
	end

NewBarkTown_ProfessorElmsLab_EventScript_OpenWindow::
	msgbox NewBarkTown_ProfessorElmsLab_Text_OpenWindow, MSGBOX_SIGN
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
	call EventScript_HealParty
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
	.string "POKéMON contained in these BALLS.\p"
	.string "You'll be that POKéMON's first\n"
	.string "partner, {PLAYER}!\p"
	.string "Go on. Pick one!$"

NewBarkTown_ProfessorElmsLab_Text_ElmWaitWhereAreYouGoing:
	.string "ELM: Wait!\n"
	.string "Where are you going?$"

NewBarkTown_ProfessorElmsLab_Text_ElmWildMonAdvice:
	.string "ELM: If a wild POKéMON appears, let\n"
	.string "your POKéMON battle it!$"

NewBarkTown_ProfessorElmsLab_Text_Cyndaquil:
	.string "ELM: Oh! CYNDAQUIL is your choice.\n"
	.string "Raising it would be a breeze.\p"
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

NewBarkTown_ProfessorElmsLab_Text_Aide_AlwaysBusy:
	.string "There are only two of us, so we're\n"
	.string "always busy.$"

NewBarkTown_ProfessorElmsLab_Text_OpenWindow:
	.string "The window is open.\n"
	.string "A pleasant breeze is blowing in.$"

NewBarkTown_ProfessorElmsLab_Text_LikeToHealMon:
	.string "Would you like to heal your POKéMON?$"

NewBarkTown_ProfessorElmsLab_Text_WonderWhatThisDoes:
	.string "Wonder what this machine does?$"

NewBarkTown_ProfessorElmsLab_Text_Observations:
	.string "“OBSERVATIONS ON POKéMON\n"
	.string "EVOLUTION”, it says on the screen…$"

NewBarkTown_ProfessorElmsLab_Text_TrashCan:
	.string "The wrapper from the snack\n"
	.string "PROF. ELM ate is in there…$"

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
