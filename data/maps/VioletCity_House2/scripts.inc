VioletCity_House2_MapScripts::
	.byte 0


VioletCity_House2_EventScript_Man::
	msgbox VioletCity_House2_EventScript_Man_Text_0, MSGBOX_NPC
	return


VioletCity_House2_EventScript_Kyle::
	lock
	faceplayer
	setvar VAR_0x8008, INGAME_TRADE_ONIX
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	goto_if_unset FLAG_VIOLET_NPC_TRADE_COMPLETED, VioletCity_House2_EventScript_Kyle_2
	bufferspeciesname 0, VAR_0x8009
	msgbox VioletCity_House2_EventScript_Kyle_Text_3
VioletCity_House2_EventScript_Kyle_1:
	release
	return

VioletCity_House2_EventScript_Kyle_2:
	msgbox VioletCity_House2_EventScript_Kyle_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_ne VioletCity_House2_EventScript_Kyle_5
	msgbox VioletCity_House2_Text_Kyle_NoTrade
	goto VioletCity_House2_EventScript_Kyle_1

VioletCity_House2_EventScript_Kyle_5:
	special ChoosePartyMon
	waitstate
	lock
	faceplayer
	copyvar VAR_0x800A, VAR_0x8004
	compare VAR_0x8004, 0xFF
	goto_if_ne VioletCity_House2_EventScript_Kyle_8
	msgbox VioletCity_House2_Text_Kyle_NoTrade
	goto VioletCity_House2_EventScript_Kyle_1

VioletCity_House2_EventScript_Kyle_8:
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	compare VAR_RESULT, VAR_0x8009
	goto_if_eq VioletCity_House2_EventScript_Kyle_11
	bufferspeciesname 0, VAR_0x8009
	msgbox VioletCity_House2_EventScript_Kyle_Text_2
	goto VioletCity_House2_EventScript_Kyle_1

VioletCity_House2_EventScript_Kyle_11:
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	lock
	faceplayer
	bufferspeciesname 0, VAR_0x8009
	msgbox VioletCity_House2_EventScript_Kyle_Text_1
	setflag FLAG_VIOLET_NPC_TRADE_COMPLETED
	goto VioletCity_House2_EventScript_Kyle_1


VioletCity_House2_EventScript_Man_Text_0:
	.string "A POKéMON you get in a trade\n"
	.string "grows quickly.\p"
	.string "But if you don't have the right\n"
	.string "GYM BADGE, they may disobey you.$"

VioletCity_House2_EventScript_Kyle_Text_0:
	.string "I collect POKéMON.\n"
	.string "Do you have {STR_VAR_1}?\p"
	.string "Want to trade it for my {STR_VAR_2}?$"

VioletCity_House2_EventScript_Kyle_Text_1:
	.string "Yay! I got myself {STR_VAR_1}!\n"
	.string "Thanks!$"

VioletCity_House2_EventScript_Kyle_Text_2:
	.string "Huh? That's not {STR_VAR_1}.\n"
	.string "What a letdown…$"

VioletCity_House2_EventScript_Kyle_Text_3:
	.string "Hi, how's my old {STR_VAR_2} doing?$"

VioletCity_House2_Text_Kyle_NoTrade::
	.string "You don't want to trade?\n"
	.string "Aww…$"
