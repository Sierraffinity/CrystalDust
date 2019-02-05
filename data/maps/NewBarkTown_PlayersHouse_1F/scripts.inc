NewBarkTown_PlayersHouse_1F_MapScripts:: @ 81F7755
	map_script 3, NewBarkTown_PlayersHouse_1F_MapScript1_Type3
	map_script 2, NewBarkTown_PlayersHouse_1F_MapScript2_1F77EA
	.byte 0

NewBarkTown_PlayersHouse_1F_MapScript1_Type3:
	compare VAR_0x4050, 0
	goto_if_eq NewBarkTown_PlayersHouse_1F_EventScript_MomDay
	gettime
	compare VAR_0x8002, TIME_MORNING
	goto_if_eq NewBarkTown_PlayersHouse_1F_EventScript_MomMorning
	compare VAR_0x8002, TIME_DAY
	goto_if_eq NewBarkTown_PlayersHouse_1F_EventScript_MomDay
	compare VAR_0x8002, TIME_NIGHT
	goto_if_eq NewBarkTown_PlayersHouse_1F_EventScript_MomNight
NewBarkTown_PlayersHouse_1F_EventScript_MomDay:
	end

NewBarkTown_PlayersHouse_1F_EventScript_MomMorning:
	setobjectxyperm 1, 2, 2
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_UP
	end

NewBarkTown_PlayersHouse_1F_EventScript_MomNight:
	setobjectxyperm 1, 1, 2
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_UP
	end

NewBarkTown_PlayersHouse_1F_MapScript2_1F77EA: @ 81F77EA
	map_script_2 VAR_0x4050, 0, NewBarkTown_PlayersHouse_1F_MomEncounter
	.2byte 0

NewBarkTown_PlayersHouse_1F_MomEncounter:
	lockall
	textcolor MSG_COLOR_RED
	playse SE_PIN
	applymovement 1, Movement_Emote_Exclamation_Mark
	waitmovement 0
	applymovement 1, Movement_Delay_48
	waitmovement 0
	playbgm MUS_MOMENC, 0
	applymovement EVENT_OBJ_ID_PLAYER, Move_WalkInPlaceFastestDown
	applymovement 1, NewBarkTown_PlayersHouse_1F_MomWalkToPlayer
	waitmovement 0
	delay 10
	msgbox NewBarkTown_PlayersHouse_1F_MomElmIntro
	call RestoreOriginalTextColor
	playfanfare MUS_FANFA4
	message NewBarkTown_PlayersHouse_1F_PlayerGetsPokegear
	waitfanfare
	setflag FLAG_SYS_POKEGEAR_GET
	textcolor MSG_COLOR_RED
	msgbox NewBarkTown_PlayersHouse_1F_MomPokegearEssential

NewBarkTown_PlayersHouse_1F_MomWhatDayOfWeek:
	message NewBarkTown_PlayersHouse_1F_WhatDayIsIt
	waitmessage
	setvar VAR_0x8004, 0
	setvar VAR_0x8005, 1
	special sub_813A128
	waitstate
	copyvar VAR_0x8004, VAR_RESULT
	special CopyDayOfWeekStringToVar1
	msgbox NewBarkTown_PlayersHouse_1F_DayConfirmation, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq NewBarkTown_PlayersHouse_1F_MomWhatDayOfWeek
	special SetDayOfWeek

NewBarkTown_PlayersHouse_1F_MomDaylightSaving:
	msgbox NewBarkTown_PlayersHouse_1F_DaylightSaving, MSGBOX_YESNO
	special WriteCurrentTimeStringToStrVar1
	compare VAR_RESULT, 0
	goto_if_eq NewBarkTown_PlayersHouse_1F_MomDaylightSavingNo
	setflag FLAG_SYS_DAYLIGHT_SAVING
	msgbox NewBarkTown_PlayersHouse_1F_DaylightSavingOn, MSGBOX_YESNO
	goto NewBarkTown_PlayersHouse_1F_MomDaylightSavingCheck
	
NewBarkTown_PlayersHouse_1F_MomDaylightSavingNo:
	clearflag FLAG_SYS_DAYLIGHT_SAVING
	msgbox NewBarkTown_PlayersHouse_1F_DaylightSavingOff, MSGBOX_YESNO

NewBarkTown_PlayersHouse_1F_MomDaylightSavingCheck:
	compare VAR_RESULT, 0
	goto_if_eq NewBarkTown_PlayersHouse_1F_MomDaylightSaving
	msgbox NewBarkTown_PlayersHouse_1F_ComeHomeToAdjustClock, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq NewBarkTown_PlayersHouse_1F_NoGearInstructions
	msgbox NewBarkTown_PlayersHouse_1F_GearInstructionsYes
	goto NewBarkTown_PlayersHouse_1F_PostGearInstructions

NewBarkTown_PlayersHouse_1F_NoGearInstructions:
	msgbox NewBarkTown_PlayersHouse_1F_GearInstructionsNo

NewBarkTown_PlayersHouse_1F_PostGearInstructions:
	closemessage
	savebgm MUS_DUMMY
	fadedefaultbgm
	applymovement 1, NewBarkTown_PlayersHouse_1F_MomWalkAwayFromPlayer
	waitmovement 0
	setvar VAR_0x4050 1
	setrespawn HEAL_LOCATION_NEW_BARK_TOWN	@ TODO: This should really be for player's room 2F, or do the FR approach
	releaseall
	end

NewBarkTown_PlayersHouse_1F_MomWalkToPlayer:
	walk_up
	walk_right
	walk_up
	step_end

NewBarkTown_PlayersHouse_1F_MomWalkAwayFromPlayer:
	walk_down
	walk_left
	walk_down
	walk_in_place_fastest_left
	step_end

NewBarkTown_PlayersHouse_1F_MomTalk::
	lock
	faceplayer
	goto_if_set FLAG_SYS_POKEMON_GET, NewBarkTown_PlayersHouse_1F_EventScript_MomWhatWasElmsErrand
	msgbox NewBarkTown_PlayersHouse_1F_MomProfElmWaiting
	release
	end

NewBarkTown_PlayersHouse_1F_EventScript_MomWhatWasElmsErrand::
	msgbox NewBarkTown_PlayersHouse_1F_Text_MomWhatWasElmsErrand
	release
	end

NewBarkTown_PlayersHouse_1F_NeighborTalk::
	lock
	faceplayer
	gettime
	compare VAR_0x8002, TIME_MORNING
	goto_if_eq NewBarkTown_PlayersHouse_1F_NeighborTalkIntroMorning
	compare VAR_0x8002, TIME_DAY
	goto_if_eq NewBarkTown_PlayersHouse_1F_NeighborTalkIntroDay
	compare VAR_0x8002, TIME_NIGHT
	goto_if_eq NewBarkTown_PlayersHouse_1F_NeighborTalkIntroNight
	end

NewBarkTown_PlayersHouse_1F_NeighborTalkIntroMorning:
	msgbox NewBarkTown_PlayersHouse_1F_NeighborMorning
	goto NewBarkTown_PlayersHouse_1F_NeighborMain

NewBarkTown_PlayersHouse_1F_NeighborTalkIntroDay:
	msgbox NewBarkTown_PlayersHouse_1F_NeighborDay
	goto NewBarkTown_PlayersHouse_1F_NeighborMain

NewBarkTown_PlayersHouse_1F_NeighborTalkIntroNight:
	msgbox NewBarkTown_PlayersHouse_1F_NeighborNight
	goto NewBarkTown_PlayersHouse_1F_NeighborMain

NewBarkTown_PlayersHouse_1F_NeighborMain:
	msgbox NewBarkTown_PlayersHouse_1F_Text_NeighborMain
	applymovement VAR_LAST_TALKED, Move_WalkInPlaceFastestRight
	waitmovement 0
	release
	end

NewBarkTown_PlayersHouse_1F_TV::
	msgbox NewBarkTown_PlayersHouse_1F_TVText, MSGBOX_SIGN
	end

NewBarkTown_PlayersHouse_1F_Stove::
	msgbox NewBarkTown_PlayersHouse_1F_StoveText, MSGBOX_SIGN
	end

NewBarkTown_PlayersHouse_1F_Sink::
	msgbox NewBarkTown_PlayersHouse_1F_SinkText, MSGBOX_SIGN
	end

NewBarkTown_PlayersHouse_1F_Fridge::
	msgbox NewBarkTown_PlayersHouse_1F_FridgeText, MSGBOX_SIGN
	end

NewBarkTown_PlayersHouse_1F_MomElmIntro:
	.string "MOM: Oh, {PLAYER}…!\n"
	.string "Our neighbor, PROF. ELM, was\l"
	.string "looking for you.\p"
	.string "He said he wanted you to do\n"
	.string "something for him.\p"
	.string "Oh, I almost forgot! Your POKéMON\n"
	.string "GEAR is back from the repair shop.\p"
	.string "Here you go!$"

NewBarkTown_PlayersHouse_1F_PlayerGetsPokegear:
	.string "{PLAYER} received the POKéGEAR.$"

NewBarkTown_PlayersHouse_1F_MomPokegearEssential:
	.string "POKéMON GEAR, or just POKéGEAR.\n"
	.string "It's essential if you want to be\l"
	.string "a good TRAINER.\p"
	.string "Oh, the day of the week isn't set.\n"
	.string "You mustn't forget that!$"

NewBarkTown_PlayersHouse_1F_WhatDayIsIt:
	.string "What day is it?$"

NewBarkTown_PlayersHouse_1F_DayConfirmation:
	.string "{STR_VAR_1}, is it?$"

NewBarkTown_PlayersHouse_1F_DaylightSaving:
	.string "Is it Daylight Saving Time now?$"

NewBarkTown_PlayersHouse_1F_DaylightSavingOff:
	.string "{STR_VAR_1}, is that correct?$"

NewBarkTown_PlayersHouse_1F_DaylightSavingOn:
	.string "{STR_VAR_1} DST, is that correct?$"

NewBarkTown_PlayersHouse_1F_ComeHomeToAdjustClock:
	.string "Come home to adjust your clock for\n"
	.string "Daylight Saving Time.\p"
	.string "By the way, do you know how to\n"
	.string "use the PHONE?$"

NewBarkTown_PlayersHouse_1F_GearInstructionsYes:
	.string "Don't you just turn the POKéGEAR on\n"
	.string "and select the PHONE icon?\p"
	.string "“Phone numbers are stored in memory.\n"
	.string "Just choose a name you want to\l"
	.string "call.”\p"
	.string "Gee, isn't that convenient?$"

NewBarkTown_PlayersHouse_1F_GearInstructionsNo:
	.string "I'll read the instructions.\p"
	.string "“Turn the POKéGEAR on and select\n"
	.string "the PHONE icon by scrolling to it.\p"
	.string "“Phone numbers are stored in memory.\n"
	.string "Just choose a name you want to\l"
	.string "call.”\p"
	.string "Gee, isn't that convenient?$"

NewBarkTown_PlayersHouse_1F_MomProfElmWaiting:
	.string "MOM: PROF. ELM is waiting for you.\n"
	.string "Hurry up, baby!$"

NewBarkTown_PlayersHouse_1F_Text_MomWhatWasElmsErrand:
	.string "MOM: So, what was PROF. ELM's\n"
	.string "errand?\p"
	.string "…\p"
	.string "That does sound challenging.\p"
	.string "But, you should be proud that\n"
	.string "people rely on you.$"

NewBarkTown_PlayersHouse_1F_NeighborMorning:
	.string "Good morning, {PLAYER}!\n"
	.string "I'm visiting!$"

NewBarkTown_PlayersHouse_1F_NeighborDay:
	.string "Hello, {PLAYER}!\n"
	.string "I'm visiting!$"

NewBarkTown_PlayersHouse_1F_NeighborNight:
	.string "Good evening, {PLAYER}!\n"
	.string "I'm visiting!$"

NewBarkTown_PlayersHouse_1F_Text_NeighborMain:
	.string "{PLAYER}, have you heard?\p"
	.string "My daughter is adamant about\n"
	.string "becoming PROF. ELM's assistant.\l"
	.string "She really loves POKéMON!$"

NewBarkTown_PlayersHouse_1F_TVText:
	.string "There's a movie on TV.\n"
	.string "Stars dot the sky as two boys\l"
	.string "ride on a train…\p"
	.string "I'd better get rolling too!$"

NewBarkTown_PlayersHouse_1F_StoveText:
	.string "It's mom's specialty, the\n"
	.string "CINNABAR VOLCANO BURGER!$"

NewBarkTown_PlayersHouse_1F_SinkText:
	.string "The sink is spotless.\n"
	.string "Mom likes to keep it clean.$"

NewBarkTown_PlayersHouse_1F_FridgeText:
	.string "Let's see what's in the fridge…\p"
	.string "FRESH WATER and tasty LEMONADE!$"
