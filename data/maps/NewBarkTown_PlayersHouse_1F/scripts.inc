NewBarkTown_PlayersHouse_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, NewBarkTown_PlayersHouse_1F_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_FRAME_TABLE, NewBarkTown_PlayersHouse_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

NewBarkTown_PlayersHouse_1F_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	compare VAR_PLAYER_HOUSE_STATE, 0
	goto_if_ne NewBarkTown_PlayersHouse_1F_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	return

NewBarkTown_PlayersHouse_1F_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
	gettime
	compare VAR_0x8002, TIME_MORNING
	goto_if_eq NewBarkTown_PlayersHouse_1F_MapScripts_MAP_SCRIPT_ON_TRANSITION_3
	compare VAR_0x8002, TIME_NIGHT
	goto_if_eq NewBarkTown_PlayersHouse_1F_MapScripts_MAP_SCRIPT_ON_TRANSITION_4
	return

NewBarkTown_PlayersHouse_1F_MapScripts_MAP_SCRIPT_ON_TRANSITION_3:
	setobjectxyperm 1, 2, 2
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_UP
	return

NewBarkTown_PlayersHouse_1F_MapScripts_MAP_SCRIPT_ON_TRANSITION_4:
	setobjectxyperm 1, 1, 2
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_UP
	return

NewBarkTown_PlayersHouse_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_PLAYER_HOUSE_STATE, 0, NewBarkTown_PlayersHouse_1F_MomEncounter
	.2byte 0


NewBarkTown_PlayersHouse_1F_MomEncounter::
	lockall
	textcolor MSG_COLOR_RED
	playse SE_PIN
	applymovement 1, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	playbgm MUS_MOMS_THEME, 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestDown
	applymovement 1, NewBarkTown_PlayersHouse_1F_MomWalkToPlayer
	waitmovement 0
	delay 20
	msgbox NewBarkTown_PlayersHouse_1F_MomEncounter_Text_0
	textcolor MSG_COLOR_PREV
	playfanfare MUS_OBTAIN_ITEM
	message NewBarkTown_PlayersHouse_1F_MomEncounter_Text_1
	waitfanfare
	setflag FLAG_SYS_POKEGEAR_GET
	setflag FLAG_PHONE_CARD_MOM
	textcolor MSG_COLOR_RED
	msgbox NewBarkTown_PlayersHouse_1F_MomEncounter_Text_2
	call NewBarkTown_PlayersHouse_1F_MomWhatDayOfWeek
	call NewBarkTown_PlayersHouse_1F_MomDaylightSaving
	msgbox NewBarkTown_PlayersHouse_1F_MomEncounter_Text_3, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq NewBarkTown_PlayersHouse_1F_MomEncounter_2
	msgbox NewBarkTown_PlayersHouse_1F_MomEncounter_Text_5
NewBarkTown_PlayersHouse_1F_MomEncounter_1:
	closemessage
	savebgm MUS_DUMMY
	fadedefaultbgm
	applymovement 1, NewBarkTown_PlayersHouse_1F_MomWalkAwayFromPlayer
	waitmovement 0
	setvar VAR_PLAYER_HOUSE_STATE, 1
	setrespawn HEAL_LOCATION_NEW_BARK_TOWN
	releaseall
	return

NewBarkTown_PlayersHouse_1F_MomEncounter_2:
	msgbox NewBarkTown_PlayersHouse_1F_MomEncounter_Text_4
	goto NewBarkTown_PlayersHouse_1F_MomEncounter_1


NewBarkTown_PlayersHouse_1F_MomWhatDayOfWeek::
	message NewBarkTown_PlayersHouse_1F_MomWhatDayOfWeek_Text_0
	waitmessage
	setvar VAR_0x8004, SCROLL_MULTI_DAY_OF_WEEK
	setvar VAR_0x8005, 0
	special ShowScrollableMultichoice
	waitstate
	copyvar VAR_0x8004, VAR_RESULT
	special CopyDayOfWeekStringToVar1
	msgbox NewBarkTown_PlayersHouse_1F_MomWhatDayOfWeek_Text_1, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq NewBarkTown_PlayersHouse_1F_MomWhatDayOfWeek_2
NewBarkTown_PlayersHouse_1F_MomWhatDayOfWeek_1:
	special SetDayOfWeek
	return

NewBarkTown_PlayersHouse_1F_MomWhatDayOfWeek_2:
	goto NewBarkTown_PlayersHouse_1F_MomWhatDayOfWeek
	goto NewBarkTown_PlayersHouse_1F_MomWhatDayOfWeek_1


NewBarkTown_PlayersHouse_1F_MomDaylightSaving::
	msgbox NewBarkTown_PlayersHouse_1F_MomDaylightSaving_Text_0, MSGBOX_YESNO
	special WriteCurrentTimeStringToStrVar1
	compare VAR_RESULT, NO
	goto_if_eq NewBarkTown_PlayersHouse_1F_MomDaylightSaving_2
	copyvar VAR_0x8004, VAR_RESULT
	special SetInitialDSTMode
	msgbox NewBarkTown_PlayersHouse_1F_MomDaylightSaving_Text_2, MSGBOX_YESNO
NewBarkTown_PlayersHouse_1F_MomDaylightSaving_1:
	compare VAR_RESULT, NO
	goto_if_eq NewBarkTown_PlayersHouse_1F_MomDaylightSaving_5
	return

NewBarkTown_PlayersHouse_1F_MomDaylightSaving_2:
	copyvar VAR_0x8004, VAR_RESULT
	special SetInitialDSTMode
	msgbox NewBarkTown_PlayersHouse_1F_MomDaylightSaving_Text_1, MSGBOX_YESNO
	goto NewBarkTown_PlayersHouse_1F_MomDaylightSaving_1

NewBarkTown_PlayersHouse_1F_MomDaylightSaving_5:
	goto NewBarkTown_PlayersHouse_1F_MomDaylightSaving
	return


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
	goto_if_set FLAG_PLAYER_MUST_LEAVE_HOUSE_TO_BANK_WITH_MOM, NewBarkTown_PlayersHouse_1F_MomTalk_2
	goto_if_set FLAG_TALKED_TO_MOM_AFTER_MYSTERY_EGG_QUEST, NewBarkTown_PlayersHouse_1F_MomTalk_3
	goto_if_set FLAG_GAVE_MYSTERY_EGG_TO_ELM, NewBarkTown_PlayersHouse_1F_MomTalk_4
	goto_if_set FLAG_SYS_POKEMON_GET, NewBarkTown_PlayersHouse_1F_MomTalk_5
	msgbox NewBarkTown_PlayersHouse_1F_MomTalk_Text_10
NewBarkTown_PlayersHouse_1F_MomTalk_1:
	release
	return

NewBarkTown_PlayersHouse_1F_MomTalk_2:
	msgbox NewBarkTown_PlayersHouse_1F_MomTalk_Text_0
	goto NewBarkTown_PlayersHouse_1F_MomTalk_1

NewBarkTown_PlayersHouse_1F_MomTalk_3:
	msgbox NewBarkTown_PlayersHouse_1F_MomTalk_Text_1, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq NewBarkTown_PlayersHouse_1F_MomTalk_12
	gettime
	special GetDSTMode
	compare VAR_RESULT, TRUE
	goto_if_eq NewBarkTown_PlayersHouse_1F_MomTalk_18
	compare VAR_0x8000, 23
	goto_if_eq NewBarkTown_PlayersHouse_1F_MomTalk_24
	msgbox NewBarkTown_PlayersHouse_1F_MomTalk_Text_4, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq NewBarkTown_PlayersHouse_1F_MomTalk_29
NewBarkTown_PlayersHouse_1F_MomTalk_11:
	msgbox NewBarkTown_PlayersHouse_1F_EventScript_MomJustDoWhatYouCan
	goto NewBarkTown_PlayersHouse_1F_MomTalk_1

NewBarkTown_PlayersHouse_1F_MomTalk_4:
	setflag FLAG_TALKED_TO_MOM_AFTER_MYSTERY_EGG_QUEST
	setflag FLAG_PLAYER_MUST_LEAVE_HOUSE_TO_BANK_WITH_MOM
	setvar VAR_ROUTE31_STATE, 1
	msgbox NewBarkTown_PlayersHouse_1F_MomTalk_Text_6, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq NewBarkTown_PlayersHouse_1F_MomTalk_16
NewBarkTown_PlayersHouse_1F_MomTalk_15:
	msgbox NewBarkTown_PlayersHouse_1F_MomTalk_Text_8
	goto NewBarkTown_PlayersHouse_1F_MomTalk_1

NewBarkTown_PlayersHouse_1F_MomTalk_5:
	msgbox NewBarkTown_PlayersHouse_1F_MomTalk_Text_9
	goto NewBarkTown_PlayersHouse_1F_MomTalk_1

NewBarkTown_PlayersHouse_1F_MomTalk_12:
	goto NewBarkTown_PlayersHouse_1F_EventScript_MomBank
	goto NewBarkTown_PlayersHouse_1F_MomTalk_11

NewBarkTown_PlayersHouse_1F_MomTalk_16:
	setflag FLAG_SYS_MOM_BANKING_ENABLED
	msgbox NewBarkTown_PlayersHouse_1F_MomTalk_Text_7
	goto NewBarkTown_PlayersHouse_1F_MomTalk_15

NewBarkTown_PlayersHouse_1F_MomTalk_18:
	compare VAR_0x8000, 0
	goto_if_eq NewBarkTown_PlayersHouse_1F_MomTalk_21
	msgbox NewBarkTown_PlayersHouse_1F_MomTalk_Text_2, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq NewBarkTown_PlayersHouse_1F_MomTalk_27
	goto NewBarkTown_PlayersHouse_1F_MomTalk_11

NewBarkTown_PlayersHouse_1F_MomTalk_21:
	call NewBarkTown_PlayersHouse_1F_EventScript_MomLostBooklet
	goto NewBarkTown_PlayersHouse_1F_MomTalk_11

NewBarkTown_PlayersHouse_1F_MomTalk_24:
	call NewBarkTown_PlayersHouse_1F_EventScript_MomLostBooklet
	goto NewBarkTown_PlayersHouse_1F_MomTalk_11

NewBarkTown_PlayersHouse_1F_MomTalk_27:
	special SwitchDSTMode
	msgbox NewBarkTown_PlayersHouse_1F_MomTalk_Text_3
	goto NewBarkTown_PlayersHouse_1F_MomTalk_11

NewBarkTown_PlayersHouse_1F_MomTalk_29:
	special SwitchDSTMode
	msgbox NewBarkTown_PlayersHouse_1F_MomTalk_Text_5
	goto NewBarkTown_PlayersHouse_1F_MomTalk_11


NewBarkTown_PlayersHouse_1F_EventScript_MomBank::
	message NewBarkTown_PlayersHouse_1F_EventScript_MomBank_Text_0
	waitmessage
	multichoice 0, 0, MULTI_MOM_BANK, FALSE
	switch VAR_RESULT
	case 0, NewBarkTown_PlayersHouse_1F_EventScript_MomBank_3
	case 1, NewBarkTown_PlayersHouse_1F_EventScript_MomBank_4
	case 2, NewBarkTown_PlayersHouse_1F_EventScript_MomBank_5
	msgbox NewBarkTown_PlayersHouse_1F_EventScript_MomJustDoWhatYouCan
NewBarkTown_PlayersHouse_1F_EventScript_MomBank_1:
	release
	return

NewBarkTown_PlayersHouse_1F_EventScript_MomBank_3:
	call NewBarkTown_PlayersHouse_1F_EventScript_MomBankWithdraw
	goto NewBarkTown_PlayersHouse_1F_EventScript_MomBank_1

NewBarkTown_PlayersHouse_1F_EventScript_MomBank_4:
	call NewBarkTown_PlayersHouse_1F_EventScript_MomBankDeposit
	goto NewBarkTown_PlayersHouse_1F_EventScript_MomBank_1

NewBarkTown_PlayersHouse_1F_EventScript_MomBank_5:
	msgbox NewBarkTown_PlayersHouse_1F_EventScript_MomBank_Text_1, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq NewBarkTown_PlayersHouse_1F_EventScript_MomBank_7
	clearflag FLAG_SYS_MOM_BANKING_ENABLED
	msgbox NewBarkTown_PlayersHouse_1F_EventScript_MomJustDoWhatYouCan
	goto NewBarkTown_PlayersHouse_1F_EventScript_MomBank_1

NewBarkTown_PlayersHouse_1F_EventScript_MomBank_7:
	setflag FLAG_SYS_MOM_BANKING_ENABLED
	msgbox NewBarkTown_PlayersHouse_1F_EventScript_MomBank_Text_2
	goto NewBarkTown_PlayersHouse_1F_EventScript_MomBank_1


NewBarkTown_PlayersHouse_1F_EventScript_MomBankWithdraw::
	setvar VAR_0x8004, 0
	special MomBank
	waitstate
	switch VAR_RESULT
	case 0, NewBarkTown_PlayersHouse_1F_EventScript_MomBankWithdraw_2
	case 1, NewBarkTown_PlayersHouse_1F_EventScript_MomBankWithdraw_3
	case 2, NewBarkTown_PlayersHouse_1F_EventScript_MomBankWithdraw_4
	msgbox NewBarkTown_PlayersHouse_1F_EventScript_MomJustDoWhatYouCan
	return

NewBarkTown_PlayersHouse_1F_EventScript_MomBankWithdraw_2:
	playse SE_SHOP
	waitse
	msgbox NewBarkTown_PlayersHouse_1F_EventScript_MomBankWithdraw_Text_0
	return

NewBarkTown_PlayersHouse_1F_EventScript_MomBankWithdraw_3:
	msgbox NewBarkTown_PlayersHouse_1F_EventScript_MomBankWithdraw_Text_1
	goto NewBarkTown_PlayersHouse_1F_EventScript_MomBankWithdraw
	return

NewBarkTown_PlayersHouse_1F_EventScript_MomBankWithdraw_4:
	msgbox NewBarkTown_PlayersHouse_1F_EventScript_MomBankWithdraw_Text_2
	goto NewBarkTown_PlayersHouse_1F_EventScript_MomBankWithdraw
	return


NewBarkTown_PlayersHouse_1F_EventScript_MomBankDeposit::
	setvar VAR_0x8004, 1
	special MomBank
	waitstate
	switch VAR_RESULT
	case 0, NewBarkTown_PlayersHouse_1F_EventScript_MomBankDeposit_2
	case 1, NewBarkTown_PlayersHouse_1F_EventScript_MomBankDeposit_3
	case 2, NewBarkTown_PlayersHouse_1F_EventScript_MomBankDeposit_4
	msgbox NewBarkTown_PlayersHouse_1F_EventScript_MomJustDoWhatYouCan
	return

NewBarkTown_PlayersHouse_1F_EventScript_MomBankDeposit_2:
	playse SE_SHOP
	waitse
	msgbox NewBarkTown_PlayersHouse_1F_EventScript_MomBankDeposit_Text_0
	return

NewBarkTown_PlayersHouse_1F_EventScript_MomBankDeposit_3:
	msgbox NewBarkTown_PlayersHouse_1F_EventScript_MomBankDeposit_Text_1
	goto NewBarkTown_PlayersHouse_1F_EventScript_MomBankDeposit
	return

NewBarkTown_PlayersHouse_1F_EventScript_MomBankDeposit_4:
	msgbox NewBarkTown_PlayersHouse_1F_EventScript_MomBankDeposit_Text_2
	goto NewBarkTown_PlayersHouse_1F_EventScript_MomBankDeposit
	return


NewBarkTown_PlayersHouse_1F_EventScript_MomLostBooklet::
	msgbox NewBarkTown_PlayersHouse_1F_EventScript_MomLostBooklet_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq NewBarkTown_PlayersHouse_1F_EventScript_MomLostBooklet_1
	return

NewBarkTown_PlayersHouse_1F_EventScript_MomLostBooklet_1:
	msgbox NewBarkTown_PlayersHouse_1F_EventScript_MomLostBooklet_Text_1
	return


NewBarkTown_PlayersHouse_1F_NeighborTalk::
	lock
	faceplayer
	gettime
	compare VAR_0x8002, TIME_MORNING
	goto_if_eq NewBarkTown_PlayersHouse_1F_NeighborTalk_2
	compare VAR_0x8002, TIME_DAY
	goto_if_eq NewBarkTown_PlayersHouse_1F_NeighborTalk_3
	compare VAR_0x8002, TIME_NIGHT
	goto_if_eq NewBarkTown_PlayersHouse_1F_NeighborTalk_4
NewBarkTown_PlayersHouse_1F_NeighborTalk_1:
	msgbox NewBarkTown_PlayersHouse_1F_NeighborTalk_Text_3
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	release
	return

NewBarkTown_PlayersHouse_1F_NeighborTalk_2:
	msgbox NewBarkTown_PlayersHouse_1F_NeighborTalk_Text_0, MSGBOX_CONTINUE
	goto NewBarkTown_PlayersHouse_1F_NeighborTalk_1

NewBarkTown_PlayersHouse_1F_NeighborTalk_3:
	msgbox NewBarkTown_PlayersHouse_1F_NeighborTalk_Text_1, MSGBOX_CONTINUE
	goto NewBarkTown_PlayersHouse_1F_NeighborTalk_1

NewBarkTown_PlayersHouse_1F_NeighborTalk_4:
	msgbox NewBarkTown_PlayersHouse_1F_NeighborTalk_Text_2, MSGBOX_CONTINUE
	goto NewBarkTown_PlayersHouse_1F_NeighborTalk_1


NewBarkTown_PlayersHouse_1F_TV::
	msgbox NewBarkTown_PlayersHouse_1F_TV_Text_0, MSGBOX_SIGN
	return


NewBarkTown_PlayersHouse_1F_Stove::
	lock
	random 1000
	compare VAR_RESULT, 0
	goto_if_eq NewBarkTown_PlayersHouse_1F_Stove_2
	msgbox NewBarkTown_PlayersHouse_1F_Stove_Text_1
NewBarkTown_PlayersHouse_1F_Stove_1:
	release
	return

NewBarkTown_PlayersHouse_1F_Stove_2:
	msgbox NewBarkTown_PlayersHouse_1F_Stove_Text_0
	goto NewBarkTown_PlayersHouse_1F_Stove_1


NewBarkTown_PlayersHouse_1F_Sink::
	msgbox NewBarkTown_PlayersHouse_1F_Sink_Text_0, MSGBOX_SIGN
	return


NewBarkTown_PlayersHouse_1F_Fridge::
	msgbox NewBarkTown_PlayersHouse_1F_Fridge_Text_0, MSGBOX_SIGN
	return


NewBarkTown_PlayersHouse_1F_MomEncounter_Text_0:
	.string "MOM: Oh, {PLAYER}…!\p"
	.string "Our neighbor, PROF. ELM, was just\n"
	.string "looking for you.\p"
	.string "He said he wanted you to do\n"
	.string "something for him.\p"
	.string "Oh, I almost forgot! Your POKéMON\n"
	.string "GEAR is back from the repair shop.\l"
	.string "Here you go!$"

NewBarkTown_PlayersHouse_1F_MomEncounter_Text_1:
	.string "{PLAYER} received the POKéGEAR.$"

NewBarkTown_PlayersHouse_1F_MomEncounter_Text_2:
	.string "POKéMON GEAR, or just POKéGEAR.\n"
	.string "It's essential if you want to be\l"
	.string "a good TRAINER.\p"
	.string "Oh, the day of the week isn't set.\n"
	.string "You mustn't forget that!$"

NewBarkTown_PlayersHouse_1F_MomEncounter_Text_3:
	.string "Come home to adjust your clock for\n"
	.string "Daylight Saving Time.\p"
	.string "By the way, do you know how to\n"
	.string "use the PHONE?$"

NewBarkTown_PlayersHouse_1F_MomEncounter_Text_4:
	.string "I'll read the instructions.\p"
	.string "“Turn the POKéGEAR on and select\n"
	.string "the PHONE icon by scrolling to it.\p"
	.string "“Phone numbers are stored in memory.\n"
	.string "Just choose who you want to call.”\p"
	.string "Gee, isn't that convenient?$"

NewBarkTown_PlayersHouse_1F_MomEncounter_Text_5:
	.string "Don't you just turn the POKéGEAR on\n"
	.string "and select the PHONE icon?\p"
	.string "“Phone numbers are stored in memory.\n"
	.string "Just choose who you want to call.”\p"
	.string "Gee, isn't that convenient?$"

NewBarkTown_PlayersHouse_1F_MomWhatDayOfWeek_Text_0:
	.string "What day is it?$"

NewBarkTown_PlayersHouse_1F_MomWhatDayOfWeek_Text_1:
	.string "{STR_VAR_1}, is it?$"

NewBarkTown_PlayersHouse_1F_MomDaylightSaving_Text_0:
	.string "Is it Daylight Saving Time now?$"

NewBarkTown_PlayersHouse_1F_MomDaylightSaving_Text_1:
	.string "{STR_VAR_1}, is that correct?$"

NewBarkTown_PlayersHouse_1F_MomDaylightSaving_Text_2:
	.string "{STR_VAR_1} DST, is that correct?$"

NewBarkTown_PlayersHouse_1F_MomTalk_Text_0:
	.string "MOM: {PLAYER}, do it!\n"
	.string "I'm behind you all the way!$"

NewBarkTown_PlayersHouse_1F_MomTalk_Text_1:
	.string "MOM: Hi! Welcome home!\n"
	.string "You're trying very hard, I see.\p"
	.string "I've kept your room tidy…\n"
	.string "Or is this about your money?$"

NewBarkTown_PlayersHouse_1F_MomTalk_Text_2:
	.string "Is Daylight Saving Time over?$"

NewBarkTown_PlayersHouse_1F_MomTalk_Text_3:
	.string "I put the clock back one hour.$"

NewBarkTown_PlayersHouse_1F_MomTalk_Text_4:
	.string "Do you want to switch to Daylight\n"
	.string "Saving Time?$"

NewBarkTown_PlayersHouse_1F_MomTalk_Text_5:
	.string "I set the clock forward by one hour.$"

NewBarkTown_PlayersHouse_1F_MomTalk_Text_6:
	.string "MOM: Wow, that's a cute POKéMON.\n"
	.string "Where did you get it?\p"
	.string "…\p"
	.string "So, you're leaving on an adventure…\p"
	.string "Okay! I'll help too.\n"
	.string "But what can I do for you?\p"
	.string "I know!\n"
	.string "I'll save money for you.\p"
	.string "On a long journey, money is very\n"
	.string "important.\p"
	.string "Do you want me to save your money?$"

NewBarkTown_PlayersHouse_1F_MomTalk_Text_7:
	.string "Okay, I'll take care of your money.\n"
	.string "………………$"

NewBarkTown_PlayersHouse_1F_MomTalk_Text_8:
	.string "Be careful.\p"
	.string "POKéMON are your friends.\n"
	.string "You need to work as a team.\p"
	.string "Now, go on!$"

NewBarkTown_PlayersHouse_1F_MomTalk_Text_9:
	.string "MOM: So, what was PROF. ELM's\n"
	.string "errand?\p"
	.string "…\n"
	.string "That does sound challenging.\p"
	.string "But, you should be proud that\n"
	.string "people rely on you.$"

NewBarkTown_PlayersHouse_1F_MomTalk_Text_10:
	.string "MOM: PROF. ELM is waiting for you.\n"
	.string "Hurry up, baby!$"

NewBarkTown_PlayersHouse_1F_EventScript_MomBank_Text_0:
	.string "What do you want to do?$"

NewBarkTown_PlayersHouse_1F_EventScript_MomBank_Text_1:
	.string "Do you want to save some money?$"

NewBarkTown_PlayersHouse_1F_EventScript_MomBank_Text_2:
	.string "Okay, I'll save your money.\n"
	.string "Trust me!\p"
	.string "{PLAYER}, stick with it!$"

NewBarkTown_PlayersHouse_1F_EventScript_MomBankWithdraw_Text_0:
	.string "{PLAYER}, don't give up!$"

NewBarkTown_PlayersHouse_1F_EventScript_MomBankWithdraw_Text_1:
	.string "You haven't saved that much.$"

NewBarkTown_PlayersHouse_1F_EventScript_MomBankWithdraw_Text_2:
	.string "You can't take that much.$"

NewBarkTown_PlayersHouse_1F_EventScript_MomBankDeposit_Text_0:
	.string "Your money's safe here!\n"
	.string "Get going!$"

NewBarkTown_PlayersHouse_1F_EventScript_MomBankDeposit_Text_1:
	.string "You don't have that much.$"

NewBarkTown_PlayersHouse_1F_EventScript_MomBankDeposit_Text_2:
	.string "You can't save that much.$"

NewBarkTown_PlayersHouse_1F_EventScript_MomLostBooklet_Text_0:
	.string "Do you want to adjust your clock for\n"
	.string "Daylight Saving Time?$"

NewBarkTown_PlayersHouse_1F_EventScript_MomLostBooklet_Text_1:
	.string "I think I lost the instruction\n"
	.string "booklet for the POKéGEAR…\p"
	.string "I need to go look for it.\n"
	.string "Come back again in a while.$"

NewBarkTown_PlayersHouse_1F_NeighborTalk_Text_0:
	.string "Good morning, {PLAYER}!\n"
	.string "I'm visiting!\p$"

NewBarkTown_PlayersHouse_1F_NeighborTalk_Text_1:
	.string "Hello, {PLAYER}!\n"
	.string "I'm visiting!\p$"

NewBarkTown_PlayersHouse_1F_NeighborTalk_Text_2:
	.string "Good evening, {PLAYER}!\n"
	.string "I'm visiting!\p$"

NewBarkTown_PlayersHouse_1F_NeighborTalk_Text_3:
	.string "{PLAYER}, have you heard?\p"
	.string "My daughter is adamant about\n"
	.string "becoming PROF. ELM's assistant.\l"
	.string "She really loves POKéMON!$"

NewBarkTown_PlayersHouse_1F_TV_Text_0:
	.string "There's a movie on TV.\n"
	.string "Stars dot the sky as two boys\l"
	.string "ride on a train…\p"
	.string "I'd better get rolling too!$"

NewBarkTown_PlayersHouse_1F_Stove_Text_0:
	.string "A ADEPT ARRANGING FOR MOTHER\n"
	.string "VOLCANO BAKEMEAT.$"

NewBarkTown_PlayersHouse_1F_Stove_Text_1:
	.string "It's Mom's specialty, the\n"
	.string "CINNABAR VOLCANO BURGER!$"

NewBarkTown_PlayersHouse_1F_Sink_Text_0:
	.string "The sink is spotless.\n"
	.string "Mom likes to keep it clean.$"

NewBarkTown_PlayersHouse_1F_Fridge_Text_0:
	.string "Let's see what's in the fridge…\p"
	.string "FRESH WATER and tasty LEMONADE!$"

NewBarkTown_PlayersHouse_1F_EventScript_MomJustDoWhatYouCan::
	.string "Just do what you can.$"
