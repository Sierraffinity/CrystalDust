Route31_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route31_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

Route31_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_ROUTE31_STATE, 0, Route31_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0
	.2byte 0

Route31_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0:
	lockall
	setflag FLAG_HIDE_MAP_NAME_POPUP
	pokegearcall PhoneScript_Mom, 0
	waitstate
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	setvar VAR_ROUTE31_STATE, 1
	releaseall
	return


Route31_EventScript_Explorer::
	msgbox Route31_EventScript_Explorer_Text_0, MSGBOX_NPC
	return


Route31_EventScript_SleepyMan::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM44_REST, Route31_EventScript_SleepyMan_2
	goto_if_set FLAG_GAVE_KENYA_TO_RANDYS_FRIEND, Route31_EventScript_SleepyMan_3
	goto_if_set FLAG_GOT_KENYA_FROM_RANDY, Route31_EventScript_SleepyMan_4
	msgbox Route31_EventScript_SleepyMan_Text_10
Route31_EventScript_SleepyMan_1:
	release
	return

Route31_EventScript_SleepyMan_2:
	msgbox Route31_Text_SleepyMan_TMDescription
	goto Route31_EventScript_SleepyMan_1

Route31_EventScript_SleepyMan_3:
	msgbox Route31_EventScript_SleepyMan_Text_0
	call Route31_EventScript_SleepyMan_TryGiveTM
	goto Route31_EventScript_SleepyMan_1

Route31_EventScript_SleepyMan_4:
	msgbox Route31_EventScript_SleepyMan_Text_1
	special ChoosePartyMon
	waitstate
	lock
	faceplayer
	compare VAR_0x8004, 0xFF
	goto_if_ne Route31_EventScript_SleepyMan_9
	msgbox Route31_EventScript_SleepyMan_Text_9
	goto Route31_EventScript_SleepyMan_1

Route31_EventScript_SleepyMan_9:
	setvar VAR_0x8005, INGAME_TRADE_GIFT_SPEAROW
	special CheckForGiftMonAndTakeMail
	switch VAR_RESULT
	case GIFTMON_NO_MAIL, Route31_EventScript_SleepyMan_13
	case GIFTMON_LAST_MON, Route31_EventScript_SleepyMan_14
	case GIFTMON_WRONG_MAIL, Route31_EventScript_SleepyMan_15
	compare VAR_RESULT, GIFTMON_WRONG_MON
	goto_if_eq Route31_EventScript_SleepyMan_18
	textcolor MSG_COLOR_SYS
	playfanfare MUS_OBTAIN_ITEM
	msgbox Route31_EventScript_SleepyMan_Text_7
Route31_EventScript_SleepyMan_17:
	setflag FLAG_GAVE_KENYA_TO_RANDYS_FRIEND
	waitmessage
	waitfanfare
	textcolor MSG_COLOR_PREV
	msgbox Route31_EventScript_SleepyMan_Text_8
	call Route31_EventScript_SleepyMan_TryGiveTM
	goto Route31_EventScript_SleepyMan_1

Route31_EventScript_SleepyMan_13:
	msgbox Route31_EventScript_SleepyMan_Text_2
	goto Route31_EventScript_SleepyMan_1

Route31_EventScript_SleepyMan_14:
	msgbox Route31_EventScript_SleepyMan_Text_3
	goto Route31_EventScript_SleepyMan_1

Route31_EventScript_SleepyMan_15:
	msgbox Route31_EventScript_SleepyMan_Text_4
	goto Route31_EventScript_SleepyMan_1

Route31_EventScript_SleepyMan_18:
	msgbox Route31_EventScript_SleepyMan_Text_5
	textcolor MSG_COLOR_SYS
	playfanfare MUS_OBTAIN_ITEM
	message Route31_EventScript_SleepyMan_Text_6
	goto Route31_EventScript_SleepyMan_17


Route31_EventScript_SleepyMan_TryGiveTM::
	giveitem ITEM_TM44
	compare VAR_RESULT, 0
	goto_if_eq Route31_EventScript_SleepyMan_TryGiveTM_2
Route31_EventScript_SleepyMan_TryGiveTM_1:
	setflag FLAG_RECEIVED_TM44_REST
	msgbox Route31_Text_SleepyMan_TMDescription
	return

Route31_EventScript_SleepyMan_TryGiveTM_2:
	goto Common_EventScript_ShowBagIsFull
	goto Route31_EventScript_SleepyMan_TryGiveTM_1


Route31_EventScript_Youngster::
	msgbox Route31_EventScript_Youngster_Text_0, MSGBOX_NPC
	return


Route31_EventScript_Trainer_Wade::
	trainerbattle_single TRAINER_WADE_1, Trainer_Text_Wade_See, Trainer_Text_Wade_Beat
	msgbox Trainer_Text_Wade_After, MSGBOX_DEFAULT
	release
	return


Route31_EventScript_Directions::
	msgbox Route31_EventScript_Directions_Text_0, MSGBOX_SIGN
	return


Route31_EventScript_DarkCave::
	msgbox Route31_EventScript_DarkCave_Text_0, MSGBOX_SIGN
	return


Route31_EventScript_Explorer_Text_0:
	.string "DARK CAVE…\p"
	.string "If POKéMON could light it up, I'd\n"
	.string "explore it.$"

Route31_EventScript_SleepyMan_Text_0:
	.string "…Zzzz…\n"
	.string "Huh?\p"
	.string "Oh, it's you again! Thanks for\n"
	.string "bringing that MAIL to me.\p"
	.string "My friend's a good guy, and you're\n"
	.string "swell too!\p"
	.string "I'd like to do something good in\n"
	.string "return for your help!\p"
	.string "I know!\n"
	.string "I want you to have this!$"

Route31_EventScript_SleepyMan_Text_1:
	.string "…Zzzz…\n"
	.string "Huh?\p"
	.string "What's that?\n"
	.string "You have MAIL for me?$"

Route31_EventScript_SleepyMan_Text_2:
	.string "Why is this POKéMON so special?\n"
	.string "It doesn't have any MAIL.$"

Route31_EventScript_SleepyMan_Text_3:
	.string "If I take that POKéMON from you,\n"
	.string "what are you going to use in battle?$"

Route31_EventScript_SleepyMan_Text_4:
	.string "This MAIL isn't for me.$"

Route31_EventScript_SleepyMan_Text_5:
	.string "…Huh? Who's that POKéMON?\n"
	.string "It's not one I know.\p"
	.string "You can keep it, and I'll just\n"
	.string "take the MAIL.$"

Route31_EventScript_SleepyMan_Text_6:
	.string "{PLAYER} handed over the MAIL.$"

Route31_EventScript_SleepyMan_Text_7:
	.string "{PLAYER} handed over the POKéMON\n"
	.string "holding the MAIL.$"

Route31_EventScript_SleepyMan_Text_8:
	.string "Let's see…\p"
	.string "“There's a dark place near you.\n"
	.string "Let's go have an adventure there!”\p"
	.string "Does he mean DARK CAVE?\n"
	.string "That sounds like fun.\p"
	.string "You know, I heard that cave leads\n"
	.string "to another road.\p"
	.string "Anyway, thanks for bringing this\n"
	.string "to me.\p"
	.string "My friend's a good guy, and you're\n"
	.string "swell too!\p"
	.string "I'd like to do something good in\n"
	.string "return for your help!\p"
	.string "I know!\n"
	.string "I want you to have this!$"

Route31_EventScript_SleepyMan_Text_9:
	.string "What?\n"
	.string "You don't want anything?$"

Route31_EventScript_SleepyMan_Text_10:
	.string "… Hnuurg… Huh?\p"
	.string "I walked too far today looking\n"
	.string "for POKéMON.\p"
	.string "My feet hurt and I'm sleepy…\p"
	.string "If I were a wild POKéMON, I'd be\n"
	.string "easy to catch…\p"
	.string "…Zzzz…$"

Route31_EventScript_Youngster_Text_0:
	.string "I found a good POKéMON in\n"
	.string "DARK CAVE.\p"
	.string "I'm going to raise it to take on\n"
	.string "FALKNER, the leader of VIOLET\l"
	.string "CITY's GYM.$"

Route31_EventScript_Directions_Text_0:
	.string "ROUTE 31\n"
	.string "VIOLET CITY - CHERRYGROVE CITY$"

Route31_EventScript_DarkCave_Text_0:
	.string "DARK CAVE$"

Route31_Text_SleepyMan_TMDescription::
	.string "TM44 is REST.\p"
	.string "It's a wonderful move that lets a\n"
	.string "POKéMON sleep to recover HP.\p"
	.string "Ooooh…\n"
	.string "That's tempting…\p"
	.string "Hopefully I won't have any bad\n"
	.string "dreams…$"
