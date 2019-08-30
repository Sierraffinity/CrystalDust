NewBarkTown_PlayersHouse_1F_MapScripts:: @ 81F7755
	map_script 3, NewBarkTown_PlayersHouse_1F_MapScript1_Type3
	map_script 2, NewBarkTown_PlayersHouse_1F_MapScript2_1F77EA
	.byte 0

NewBarkTown_PlayersHouse_1F_MapScript2_1F77EA: @ 81F77EA
	map_script_2 VAR_PLAYER_HOUSE_STATE, 0, NewBarkTown_PlayersHouse_1F_MomEncounter
	.2byte 0

NewBarkTown_PlayersHouse_1F_MapScript1_Type3:
	compare VAR_PLAYER_HOUSE_STATE, 0
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

NewBarkTown_PlayersHouse_1F_MomEncounter:
	lockall
	textcolor MSG_COLOR_RED
	playse SE_PIN
	applymovement 1, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	playbgm MUS_MOMENC, 0
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceDown
	applymovement 1, NewBarkTown_PlayersHouse_1F_MomWalkToPlayer
	waitmovement 0
	delay 10
	msgbox NewBarkTown_PlayersHouse_1F_MomElmIntro
	call RestoreOriginalTextColor
	playfanfare MUS_FANFA4
	message NewBarkTown_PlayersHouse_1F_PlayerGetsPokegear
	waitfanfare
	setflag FLAG_SYS_POKEGEAR_GET
	setflag FLAG_PHONE_CARD_MOM
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
	setvar VAR_PLAYER_HOUSE_STATE 1
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
	goto_if_set FLAG_PLAYER_MUST_LEAVE_HOUSE_TO_BANK_WITH_MOM, NewBarkTown_PlayersHouse_1F_EventScript_MomBehindYou
	goto_if_set FLAG_TALKED_TO_MOM_AFTER_MYSTERY_EGG_QUEST, NewBarkTown_PlayersHouse_1F_EventScript_MomBankingAndDST
	goto_if_set FLAG_GAVE_MYSTERY_EGG_TO_ELM, NewBarkTown_PlayersHouse_1F_EventScript_MomLetsYouBank
	goto_if_set FLAG_SYS_POKEMON_GET, NewBarkTown_PlayersHouse_1F_EventScript_MomWhatWasElmsErrand
	msgbox NewBarkTown_PlayersHouse_1F_MomProfElmWaiting
	release
	end

NewBarkTown_PlayersHouse_1F_EventScript_MomWhatWasElmsErrand:
	msgbox NewBarkTown_PlayersHouse_1F_Text_MomWhatWasElmsErrand
	release
	end

NewBarkTown_PlayersHouse_1F_EventScript_MomLetsYouBank:
	setflag FLAG_TALKED_TO_MOM_AFTER_MYSTERY_EGG_QUEST
	setflag FLAG_PLAYER_MUST_LEAVE_HOUSE_TO_BANK_WITH_MOM
	setvar VAR_ROUTE31_STATE, 1
	msgbox NewBarkTown_PlayersHouse_1F_Text_MomSaveMoneyQuestion, MSGBOX_YESNO
	compare VAR_RESULT, 1
	call_if_eq NewBarkTown_PlayersHouse_1F_EventScript_MomEnableBanking
	msgbox NewBarkTown_PlayersHouse_1F_Text_MomBeCarefulPokemonAreFriends
	release
	end

NewBarkTown_PlayersHouse_1F_EventScript_MomEnableBanking:
	setflag FLAG_SYS_MOM_SAVING_ENABLED
	msgbox NewBarkTown_PlayersHouse_1F_Text_MomIllTakeCareOfMoney
	return

NewBarkTown_PlayersHouse_1F_EventScript_MomBehindYou:
	msgbox NewBarkTown_PlayersHouse_1F_Text_MomBehindYou
	release
	end

NewBarkTown_PlayersHouse_1F_EventScript_MomBankingAndDST:
	msgbox NewBarkTown_PlayersHouse_1F_Text_MomWelcomeHome, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq NewBarkTown_PlayersHouse_1F_EventScript_MomBank
	gettime
	goto_if_set FLAG_SYS_DAYLIGHT_SAVING, NewBarkTown_PlayersHouse_1F_EventScript_MomDSTCurrentlySet
	compare VAR_0x8000, 23
	goto_if_eq NewBarkTown_PlayersHouse_1F_EventScript_MomLostBooklet
	msgbox NewBarkTown_PlayersHouse_1F_Text_MomSetDST, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq NewBarkTown_PlayersHouse_1F_EventScript_MomJustDoWhatYouCan
	special SwitchDSTMode
	msgbox NewBarkTown_PlayersHouse_1F_Text_MomSetClockForward
NewBarkTown_PlayersHouse_1F_EventScript_MomJustDoWhatYouCan:
	msgbox NewBarkTown_PlayersHouse_1F_Text_MomJustDoWhatYouCan
	release
	end

NewBarkTown_PlayersHouse_1F_EventScript_MomBank:
	@ TODO: Banking
	msgbox NewBarkTown_PlayersHouse_1F_Text_MomBankPlaceholder
	release
	end

NewBarkTown_PlayersHouse_1F_EventScript_MomDSTCurrentlySet:
	compare VAR_0x8000, 0
	goto_if_eq NewBarkTown_PlayersHouse_1F_EventScript_MomLostBooklet
	msgbox NewBarkTown_PlayersHouse_1F_Text_MomClearDST, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq NewBarkTown_PlayersHouse_1F_EventScript_MomJustDoWhatYouCan
	special SwitchDSTMode
	msgbox NewBarkTown_PlayersHouse_1F_Text_MomSetClockBack
	goto NewBarkTown_PlayersHouse_1F_EventScript_MomJustDoWhatYouCan

NewBarkTown_PlayersHouse_1F_EventScript_MomLostBooklet:
	msgbox NewBarkTown_PlayersHouse_1F_Text_MomAdjustClock, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq NewBarkTown_PlayersHouse_1F_EventScript_MomJustDoWhatYouCan
	msgbox NewBarkTown_PlayersHouse_1F_Text_MomLostBooklet
	goto NewBarkTown_PlayersHouse_1F_EventScript_MomJustDoWhatYouCan

NewBarkTown_PlayersHouse_1F_NeighborTalk::
	lock
	faceplayer
	gettime
	compare VAR_0x8002, TIME_MORNING
	call_if_eq NewBarkTown_PlayersHouse_1F_NeighborTalkIntroMorning
	compare VAR_0x8002, TIME_DAY
	call_if_eq NewBarkTown_PlayersHouse_1F_NeighborTalkIntroDay
	compare VAR_0x8002, TIME_NIGHT
	call_if_eq NewBarkTown_PlayersHouse_1F_NeighborTalkIntroNight
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceRight
	waitmovement 0
	release
	end

NewBarkTown_PlayersHouse_1F_NeighborTalkIntroMorning:
	msgbox NewBarkTown_PlayersHouse_1F_NeighborMorning
	closemessage
	return

NewBarkTown_PlayersHouse_1F_NeighborTalkIntroDay:
	msgbox NewBarkTown_PlayersHouse_1F_NeighborDay
	closemessage
	return

NewBarkTown_PlayersHouse_1F_NeighborTalkIntroNight:
	msgbox NewBarkTown_PlayersHouse_1F_NeighborNight
	closemessage
	return

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
	.string "Our neighbor, PROF. ELM, was just\l"
	.string "looking for you.\p"
	.string "He said he wanted you to do\n"
	.string "something for him.\p"
	.string "Oh, I almost forgot! Your POKéMON\n"
	.string "GEAR is back from the repair shop.\l"
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
	.string "Just choose who you want to call.”\p"
	.string "Gee, isn't that convenient?$"

NewBarkTown_PlayersHouse_1F_GearInstructionsNo:
	.string "I'll read the instructions.\p"
	.string "“Turn the POKéGEAR on and select\n"
	.string "the PHONE icon by scrolling to it.\p"
	.string "“Phone numbers are stored in memory.\n"
	.string "Just choose who you want to call.”\p"
	.string "Gee, isn't that convenient?$"

NewBarkTown_PlayersHouse_1F_MomProfElmWaiting:
	.string "MOM: PROF. ELM is waiting for you.\n"
	.string "Hurry up, baby!$"

NewBarkTown_PlayersHouse_1F_Text_MomWhatWasElmsErrand:
	.string "MOM: So, what was PROF. ELM's\n"
	.string "errand?\p"
	.string "…\n"
	.string "That does sound challenging.\p"
	.string "But, you should be proud that\n"
	.string "people rely on you.$"

NewBarkTown_PlayersHouse_1F_Text_MomSaveMoneyQuestion:
	.string "MOM: Wow, that's a cute POKéMON.\n"
	.string "Where did you get it?\p"
	.string "…\n"
	.string "So, you're leaving on an adventure…\p"
	.string "Okay! I'll help too.\n"
	.string "But what can I do for you?\p"
	.string "I know!\n"
	.string "I'll save money for you.\p"
	.string "On a long journey, money is very\n"
	.string "important.\p"
	.string "Do you want me to save your money?$"

NewBarkTown_PlayersHouse_1F_Text_MomIllTakeCareOfMoney:
	.string "Okay, I'll take care of your money.\n"
	.string "………………$"

NewBarkTown_PlayersHouse_1F_Text_MomBeCarefulPokemonAreFriends:
	.string "Be careful.\p"
	.string "POKéMON are your friends.\n"
	.string "You need to work as a team.\p"
	.string "Now, go on!$"

NewBarkTown_PlayersHouse_1F_Text_MomBehindYou:
	.string "MOM: {PLAYER}, do it!\n"
	.string "I'm behind you all the way!$"

NewBarkTown_PlayersHouse_1F_Text_MomWelcomeHome:
	.string "MOM: Hi! Welcome home!\n"
	.string "You're trying very hard, I see.\p"
	.string "I've kept your room tidy.\p"
	.string "Or is this about your money?$"

NewBarkTown_PlayersHouse_1F_Text_MomSetDST:
	.string "Do you want to switch to Daylight\n"
	.string "Saving Time?$"

NewBarkTown_PlayersHouse_1F_Text_MomSetClockForward:
	.string "I set the clock forward by one hour.$"

NewBarkTown_PlayersHouse_1F_Text_MomClearDST:
	.string "Is Daylight Saving Time over?$"

NewBarkTown_PlayersHouse_1F_Text_MomSetClockBack:
	.string "I put the clock back one hour.$"

NewBarkTown_PlayersHouse_1F_Text_MomAdjustClock:
	.string "Do you want to adjust your clock for\n"
	.string "Daylight Saving Time?$"

NewBarkTown_PlayersHouse_1F_Text_MomLostBooklet:
	.string "I seem to have lost the instruction\n"
	.string "booklet for the POKéGEAR…\p"
	.string "I need to go look for it.\n"
	.string "Come back again in a while.$"

NewBarkTown_PlayersHouse_1F_Text_MomJustDoWhatYouCan:
	.string "Just do what you can.$"

NewBarkTown_PlayersHouse_1F_Text_MomBankPlaceholder:
	.string "If you see this text, remind Diego to\n"
	.string "add the bank functionality.$"

NewBarkTown_PlayersHouse_1F_NeighborMorning:
	.string "Good morning, {PLAYER}!\n"
	.string "I'm visiting!\p"
	.string "{PLAYER}, have you heard?\p"
	.string "My daughter is adamant about\n"
	.string "becoming PROF. ELM's assistant.\l"
	.string "She really loves POKéMON!$"

NewBarkTown_PlayersHouse_1F_NeighborDay:
	.string "Hello, {PLAYER}!\n"
	.string "I'm visiting!\p"
	.string "{PLAYER}, have you heard?\p"
	.string "My daughter is adamant about\n"
	.string "becoming PROF. ELM's assistant.\l"
	.string "She really loves POKéMON!$"

NewBarkTown_PlayersHouse_1F_NeighborNight:
	.string "Good evening, {PLAYER}!\n"
	.string "I'm visiting!\p"
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
	.string "It's MOM's specialty, the\n"
	.string "CINNABAR VOLCANO BURGER!$"

NewBarkTown_PlayersHouse_1F_SinkText:
	.string "The sink is spotless.\n"
	.string "MOM likes to keep it clean.$"

NewBarkTown_PlayersHouse_1F_FridgeText:
	.string "Let's see what's in the fridge…\p"
	.string "FRESH WATER and tasty LEMONADE!$"
