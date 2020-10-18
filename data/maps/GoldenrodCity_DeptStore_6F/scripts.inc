GoldenrodCity_DeptStore_6F_MapScripts::
	.byte 0


GoldenrodCity_DeptStore_6F_EventScript_VendingMachine::
	lockall
	message GoldenrodCity_DeptStore_6F_Text_AVendingMachine
	waitmessage
	showmoneybox 0, 0, FALSE
	goto GoldenrodCity_DeptStore_6F_EventScript_ChooseDrink
	return


GoldenrodCity_DeptStore_6F_EventScript_ChooseDrink::
	multichoice 16, 0, MULTI_VENDING_MACHINE, 0
	switch VAR_RESULT
	case 0, GoldenrodCity_DeptStore_6F_EventScript_ChooseDrink_3
	case 1, GoldenrodCity_DeptStore_6F_EventScript_ChooseDrink_4
	case 2, GoldenrodCity_DeptStore_6F_EventScript_ChooseDrink_5
	goto GoldenrodCity_DeptStore_6F_EventScript_ExitVendingMachine
GoldenrodCity_DeptStore_6F_EventScript_ChooseDrink_1:
	checkmoney VAR_TEMP_1, TRUE
	compare VAR_RESULT, FALSE
	goto_if_eq GoldenrodCity_DeptStore_6F_EventScript_ChooseDrink_8
	checkitemspace VAR_TEMP_0, 1
	compare VAR_RESULT, FALSE
	goto_if_eq GoldenrodCity_DeptStore_6F_EventScript_ChooseDrink_11
	removemoney VAR_TEMP_1, TRUE
	updatemoneybox 0, 0
	bufferitemname 0, VAR_TEMP_0
	playse SE_VEND
	msgbox GoldenrodCity_DeptStore_6F_EventScript_ChooseDrink_Text_2
	additem VAR_TEMP_0
	bufferitemname 1, VAR_TEMP_0
	bufferstdstring 2, STDSTRING_ITEMS
	msgbox gText_PutItemInPocket
	message GoldenrodCity_DeptStore_6F_Text_AVendingMachine
	waitmessage
	goto GoldenrodCity_DeptStore_6F_EventScript_ChooseDrink
GoldenrodCity_DeptStore_6F_EventScript_ChooseDrink_7:
	hidemoneybox
	releaseall
	return

GoldenrodCity_DeptStore_6F_EventScript_ChooseDrink_3:
	setvar VAR_TEMP_0, ITEM_FRESH_WATER
	setvar VAR_TEMP_1, 200
	goto GoldenrodCity_DeptStore_6F_EventScript_ChooseDrink_1

GoldenrodCity_DeptStore_6F_EventScript_ChooseDrink_4:
	setvar VAR_TEMP_0, ITEM_SODA_POP
	setvar VAR_TEMP_1, 300
	goto GoldenrodCity_DeptStore_6F_EventScript_ChooseDrink_1

GoldenrodCity_DeptStore_6F_EventScript_ChooseDrink_5:
	setvar VAR_TEMP_0, ITEM_LEMONADE
	setvar VAR_TEMP_1, 350
	goto GoldenrodCity_DeptStore_6F_EventScript_ChooseDrink_1

GoldenrodCity_DeptStore_6F_EventScript_ChooseDrink_8:
	msgbox GoldenrodCity_DeptStore_6F_EventScript_ChooseDrink_Text_0
	goto GoldenrodCity_DeptStore_6F_EventScript_ChooseDrink_7

GoldenrodCity_DeptStore_6F_EventScript_ChooseDrink_11:
	msgbox GoldenrodCity_DeptStore_6F_EventScript_ChooseDrink_Text_1
	goto GoldenrodCity_DeptStore_6F_EventScript_ChooseDrink_7


GoldenrodCity_DeptStore_6F_EventScript_ExitVendingMachine::
	hidemoneybox
	releaseall
	return


GoldenrodCity_DeptStore_6F_EventScript_Boy::
	msgbox GoldenrodCity_DeptStore_6F_EventScript_Boy_Text_0, MSGBOX_NPC
	return


GoldenrodCity_DeptStore_6F_EventScript_Girl::
	msgbox GoldenrodCity_DeptStore_6F_EventScript_Girl_Text_0, MSGBOX_NPC
	return


GoldenrodCity_DeptStore_6F_EventScript_FloorNumber::
	msgbox GoldenrodCity_DeptStore_6F_EventScript_FloorNumber_Text_0, MSGBOX_SIGN
	return


GoldenrodCity_DeptStore_6F_EventScript_ChooseDrink_Text_0:
	.string "Oops, not enough money.$"

GoldenrodCity_DeptStore_6F_EventScript_ChooseDrink_Text_1:
	.string "There's no more room for stuff.$"

GoldenrodCity_DeptStore_6F_EventScript_ChooseDrink_Text_2:
	.string "Clang!\n"
	.string "A can of {STR_VAR_1} popped out!$"

GoldenrodCity_DeptStore_6F_EventScript_Boy_Text_0:
	.string "If you're tired, try the vending\n"
	.string "machine's drinks.\p"
	.string "Your POKéMON will love them too.$"

GoldenrodCity_DeptStore_6F_EventScript_Girl_Text_0:
	.string "Do you listen to LUCKY CHANNEL?\p"
	.string "If you want to win, trade POKéMON\n"
	.string "with as many people as possible to\l"
	.string "get different ID numbers.$"

GoldenrodCity_DeptStore_6F_EventScript_FloorNumber_Text_0:
	.string "Take a Break from Shopping!\p"
	.string "6F TRANQUIL SQUARE$"

GoldenrodCity_DeptStore_6F_Text_AVendingMachine::
	.string "A vending machine!\n"
	.string "Here's the menu.$"
