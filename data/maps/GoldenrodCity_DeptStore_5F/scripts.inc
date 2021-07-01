GoldenrodCity_DeptStore_5F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, GoldenrodCity_DeptStore_5F_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

GoldenrodCity_DeptStore_5F_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	gettime
	compare VAR_0x8003, DAY_SUNDAY
	goto_if_eq GoldenrodCity_DeptStore_5F_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	setflag FLAG_HIDE_GOLDENROD_DEPT_STORE_RETURN_FRUSTRATION_LADY
	return

GoldenrodCity_DeptStore_5F_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
	clearflag FLAG_HIDE_GOLDENROD_DEPT_STORE_RETURN_FRUSTRATION_LADY
	return


GoldenrodCity_DeptStore_5F_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIHelpYou
	waitmessage
	pokemart GoldenrodCity_DeptStore_5F_Pokemart_Clerk
	msgbox gText_PleaseComeAgain
	release
	return


GoldenrodCity_DeptStore_5F_Pokemart_Clerk:
	.2byte ITEM_TM25_THUNDER
	.2byte ITEM_TM38_FIRE_BLAST
	.2byte ITEM_TM14_BLIZZARD
	.2byte ITEM_NONE

GoldenrodCity_DeptStore_5F_EventScript_ReturnFrustrationLady::
	lock
	faceplayer
	gettime
	compare VAR_0x8003, DAY_SUNDAY
	goto_if_eq GoldenrodCity_DeptStore_5F_EventScript_ReturnFrustrationLady_4
GoldenrodCity_DeptStore_5F_EventScript_ReturnFrustrationLady_3:
	msgbox GoldenrodCity_DeptStore_5F_EventScript_ReturnFrustrationLady_Text_6
GoldenrodCity_DeptStore_5F_EventScript_ReturnFrustrationLady_1:
	release
	return

GoldenrodCity_DeptStore_5F_EventScript_ReturnFrustrationLady_2:
	msgbox GoldenrodCity_DeptStore_5F_EventScript_ReturnFrustrationLady_Text_0
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	compare VAR_RESULT, 4
	goto_if_ge GoldenrodCity_DeptStore_5F_EventScript_ReturnFrustrationLady_7
	compare VAR_RESULT, 2
	goto_if_ge GoldenrodCity_DeptStore_5F_EventScript_ReturnFrustrationLady_8
	msgbox GoldenrodCity_DeptStore_5F_EventScript_ReturnFrustrationLady_Text_4
	checkitemspace ITEM_TM21_FRUSTRATION, 1
	compare VAR_RESULT, 0
	goto_if_eq GoldenrodCity_DeptStore_5F_EventScript_ReturnFrustrationLady_15
	givetmhm_msg GoldenrodCity_DeptStore_5F_EventScript_ReturnFrustrationLady_Text_5, ITEM_TM21_FRUSTRATION
	setflag FLAG_DAILY_GOLDENROD_DEPT_STORE_RETURN_FRUSTRATION_EVENT
	goto GoldenrodCity_DeptStore_5F_EventScript_ReturnFrustrationLady_1

GoldenrodCity_DeptStore_5F_EventScript_ReturnFrustrationLady_4:
	goto_if_unset FLAG_DAILY_GOLDENROD_DEPT_STORE_RETURN_FRUSTRATION_EVENT, GoldenrodCity_DeptStore_5F_EventScript_ReturnFrustrationLady_2
	goto GoldenrodCity_DeptStore_5F_EventScript_ReturnFrustrationLady_3

GoldenrodCity_DeptStore_5F_EventScript_ReturnFrustrationLady_7:
	msgbox GoldenrodCity_DeptStore_5F_EventScript_ReturnFrustrationLady_Text_1
	checkitemspace ITEM_TM27_RETURN, 1
	compare VAR_RESULT, 0
	goto_if_eq GoldenrodCity_DeptStore_5F_EventScript_ReturnFrustrationLady_12
	givetmhm_msg GoldenrodCity_DeptStore_5F_EventScript_ReturnFrustrationLady_Text_2, ITEM_TM27_RETURN
	setflag FLAG_DAILY_GOLDENROD_DEPT_STORE_RETURN_FRUSTRATION_EVENT
	goto GoldenrodCity_DeptStore_5F_EventScript_ReturnFrustrationLady_1

GoldenrodCity_DeptStore_5F_EventScript_ReturnFrustrationLady_8:
	msgbox GoldenrodCity_DeptStore_5F_EventScript_ReturnFrustrationLady_Text_3
	goto GoldenrodCity_DeptStore_5F_EventScript_ReturnFrustrationLady_1

GoldenrodCity_DeptStore_5F_EventScript_ReturnFrustrationLady_12:
	goto Common_EventScript_ShowBagIsFull
	goto GoldenrodCity_DeptStore_5F_EventScript_ReturnFrustrationLady_1

GoldenrodCity_DeptStore_5F_EventScript_ReturnFrustrationLady_15:
	goto Common_EventScript_ShowBagIsFull
	goto GoldenrodCity_DeptStore_5F_EventScript_ReturnFrustrationLady_1


GoldenrodCity_DeptStore_5F_EventScript_Mike::
	lock
	faceplayer
	setvar VAR_0x8008, INGAME_TRADE_MACHOP
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	goto_if_unset FLAG_GOLDENROD_NPC_TRADE_COMPLETED, GoldenrodCity_DeptStore_5F_EventScript_Mike_2
	bufferspeciesname 0, VAR_0x8009
	msgbox GoldenrodCity_DeptStore_5F_EventScript_Mike_Text_3
GoldenrodCity_DeptStore_5F_EventScript_Mike_1:
	release
	return

GoldenrodCity_DeptStore_5F_EventScript_Mike_2:
	msgbox GoldenrodCity_DeptStore_5F_EventScript_Mike_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_ne GoldenrodCity_DeptStore_5F_EventScript_Mike_5
	msgbox GoldenrodCity_DeptStore_5F_Text_Mike_NoTrade
	goto GoldenrodCity_DeptStore_5F_EventScript_Mike_1

GoldenrodCity_DeptStore_5F_EventScript_Mike_5:
	special ChoosePartyMon
	waitstate
	lock
	faceplayer
	copyvar VAR_0x800A, VAR_0x8004
	compare VAR_0x8004, 0xFF
	goto_if_ne GoldenrodCity_DeptStore_5F_EventScript_Mike_8
	msgbox GoldenrodCity_DeptStore_5F_Text_Mike_NoTrade
	goto GoldenrodCity_DeptStore_5F_EventScript_Mike_1

GoldenrodCity_DeptStore_5F_EventScript_Mike_8:
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	compare VAR_RESULT, VAR_0x8009
	goto_if_eq GoldenrodCity_DeptStore_5F_EventScript_Mike_11
	bufferspeciesname 0, VAR_0x8009
	msgbox GoldenrodCity_DeptStore_5F_EventScript_Mike_Text_2
	goto GoldenrodCity_DeptStore_5F_EventScript_Mike_1

GoldenrodCity_DeptStore_5F_EventScript_Mike_11:
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	lock
	faceplayer
	bufferspeciesname 0, VAR_0x8009
	msgbox GoldenrodCity_DeptStore_5F_EventScript_Mike_Text_1
	setflag FLAG_GOLDENROD_NPC_TRADE_COMPLETED
	goto GoldenrodCity_DeptStore_5F_EventScript_Mike_1


GoldenrodCity_DeptStore_5F_EventScript_Lass::
	msgbox GoldenrodCity_DeptStore_5F_EventScript_Lass_Text_0, MSGBOX_NPC
	return


GoldenrodCity_DeptStore_5F_EventScript_RenameGuy::
	msgbox GoldenrodCity_DeptStore_5F_EventScript_RenameGuy_Text_0, MSGBOX_NPC
	return


GoldenrodCity_DeptStore_5F_EventScript_MysteryGiftGirl::
	msgbox GoldenrodCity_DeptStore_5F_EventScript_MysteryGiftGirl_Text_0, MSGBOX_NPC
	return


GoldenrodCity_DeptStore_5F_EventScript_FloorNumber::
	msgbox GoldenrodCity_DeptStore_5F_EventScript_FloorNumber_Text_0, MSGBOX_SIGN
	return


GoldenrodCity_DeptStore_5F_EventScript_ReturnFrustrationLady_Text_0:
	.string "Hello.\n"
	.string "Oh, your POKéMON…$"

GoldenrodCity_DeptStore_5F_EventScript_ReturnFrustrationLady_Text_1:
	.string "It's very attached to you.\p"
	.string "This move should be perfect for\n"
	.string "a pair like you.$"

GoldenrodCity_DeptStore_5F_EventScript_ReturnFrustrationLady_Text_2:
	.string "{PLAYER} received TM27\n"
	.string "from the woman.$"

GoldenrodCity_DeptStore_5F_EventScript_ReturnFrustrationLady_Text_3:
	.string "It's adorable!\n"
	.string "You should teach it good TM moves.$"

GoldenrodCity_DeptStore_5F_EventScript_ReturnFrustrationLady_Text_4:
	.string "It looks evil.\n"
	.string "How about this TM for it?$"

GoldenrodCity_DeptStore_5F_EventScript_ReturnFrustrationLady_Text_5:
	.string "{PLAYER} received TM21\n"
	.string "from the woman.$"

GoldenrodCity_DeptStore_5F_EventScript_ReturnFrustrationLady_Text_6:
	.string "There are sure to be TMs that are\n"
	.string "just perfect for your POKéMON.$"

GoldenrodCity_DeptStore_5F_EventScript_Mike_Text_0:
	.string "I collect POKéMON.\n"
	.string "Do you have {STR_VAR_1}?\p"
	.string "Want to trade it for my {STR_VAR_2}?$"

GoldenrodCity_DeptStore_5F_EventScript_Mike_Text_1:
	.string "Yay! I got myself {STR_VAR_1}!\n"
	.string "Thanks!$"

GoldenrodCity_DeptStore_5F_EventScript_Mike_Text_2:
	.string "Huh? That's not {STR_VAR_1}.\n"
	.string "What a letdown…$"

GoldenrodCity_DeptStore_5F_EventScript_Mike_Text_3:
	.string "Hi, how's my old {STR_VAR_2} doing?$"

GoldenrodCity_DeptStore_5F_EventScript_Lass_Text_0:
	.string "On SUNDAYS, a lady comes to check\n"
	.string "out POKéMON.\p"
	.string "She even gives away TMs!$"

GoldenrodCity_DeptStore_5F_EventScript_RenameGuy_Text_0:
	.string "You can't rename a POKéMON you get\n"
	.string "in a trade.\p"
	.string "The name is a reflection of the\n"
	.string "original TRAINER's feelings for it.$"

GoldenrodCity_DeptStore_5F_EventScript_MysteryGiftGirl_Text_0:
	.string "MYSTERY GIFT.\p"
	.string "With just a little beep, you get\n"
	.string "a gift.\p"
	.string "Use it to LINK TOGETHER WITH ALL!$"

GoldenrodCity_DeptStore_5F_EventScript_FloorNumber_Text_0:
	.string "Customize Your POKéMON\p"
	.string "5F TM CORNER$"

GoldenrodCity_DeptStore_5F_Text_Mike_NoTrade::
	.string "You don't want to trade?\n"
	.string "Aww…$"
