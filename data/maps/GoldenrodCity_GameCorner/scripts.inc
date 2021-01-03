GoldenrodCity_GameCorner_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, GoldenrodCity_GameCorner_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

GoldenrodCity_GameCorner_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	gettime
	compare VAR_0x8002, TIME_MORNING
	goto_if_eq GoldenrodCity_GameCorner_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	clearflag FLAG_HIDE_GOLDENROD_CITY_GAME_CORNER_NERD
	return

GoldenrodCity_GameCorner_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
	setflag FLAG_HIDE_GOLDENROD_CITY_GAME_CORNER_NERD
	return


GoldenrodCity_GameCorner_EventScript_CoinClerk::
	lock
	faceplayer
	showmoneybox 0, 0, FALSE
	showcoinsbox 0, 5
	msgbox GoldenrodCity_GameCorner_EventScript_CoinClerk_Text_0
	checkitem ITEM_COIN_CASE, 1
	compare VAR_RESULT, 0
	goto_if_eq GoldenrodCity_GameCorner_EventScript_CoinClerk_2
	message GoldenrodCity_GameCorner_EventScript_CoinClerk_Text_2
	waitmessage
	multichoicedefault 13, 0, MULTI_GAME_CORNER_COINS, 0, 0
	call GoldenrodCity_GameCorner_EventScript_CoinClerk_ShowChoice
GoldenrodCity_GameCorner_EventScript_CoinClerk_1:
	hidemoneybox
	hidecoinsbox 0, 5
	release
	return

GoldenrodCity_GameCorner_EventScript_CoinClerk_2:
	msgbox GoldenrodCity_GameCorner_EventScript_CoinClerk_Text_1
	goto GoldenrodCity_GameCorner_EventScript_CoinClerk_1


GoldenrodCity_GameCorner_EventScript_CoinClerk_ShowChoice::
	switch VAR_RESULT
	case 0, GoldenrodCity_GameCorner_EventScript_CoinClerk_ShowChoice_2
	case 1, GoldenrodCity_GameCorner_EventScript_CoinClerk_ShowChoice_3
	msgbox GoldenrodCity_GameCorner_EventScript_CoinClerk_ShowChoice_Text_2
	return

GoldenrodCity_GameCorner_EventScript_CoinClerk_ShowChoice_2:
	checkcoins VAR_TEMP_1
	compare VAR_TEMP_1, MAX_COINS + 1 - 50
	goto_if_ge GoldenrodCity_GameCorner_EventScript_CoinClerk_ShowChoice_5
	checkmoney 1000, FALSE
	compare VAR_RESULT, FALSE
	goto_if_eq GoldenrodCity_GameCorner_EventScript_CoinClerk_ShowChoice_11
	addcoins 50
	removemoney 1000, FALSE
	updatemoneybox 0, 0
	updatecoinsbox 0, 5
	playse SE_RG_SHOP
	message GoldenrodCity_GameCorner_EventScript_CoinClerk_ShowChoice_Text_0
	waitmessage
	multichoicedefault 13, 0, MULTI_GAME_CORNER_COINS, 0, 0
	goto GoldenrodCity_GameCorner_EventScript_CoinClerk_ShowChoice
	return

GoldenrodCity_GameCorner_EventScript_CoinClerk_ShowChoice_3:
	checkcoins VAR_TEMP_1
	compare VAR_TEMP_1, MAX_COINS + 1 - 500
	goto_if_ge GoldenrodCity_GameCorner_EventScript_CoinClerk_ShowChoice_8
	checkmoney 10000, FALSE
	compare VAR_RESULT, FALSE
	goto_if_eq GoldenrodCity_GameCorner_EventScript_CoinClerk_ShowChoice_14
	addcoins 500
	removemoney 10000, FALSE
	updatemoneybox 0, 0
	updatecoinsbox 0, 5
	playse SE_RG_SHOP
	message GoldenrodCity_GameCorner_EventScript_CoinClerk_ShowChoice_Text_1
	waitmessage
	multichoicedefault 13, 0, MULTI_GAME_CORNER_COINS, 1, 0
	goto GoldenrodCity_GameCorner_EventScript_CoinClerk_ShowChoice
	return

GoldenrodCity_GameCorner_EventScript_CoinClerk_ShowChoice_5:
	call GoldenrodCity_GameCorner_EventScript_CoinClerk_NoRoom
	return

GoldenrodCity_GameCorner_EventScript_CoinClerk_ShowChoice_8:
	call GoldenrodCity_GameCorner_EventScript_CoinClerk_NoRoom
	return

GoldenrodCity_GameCorner_EventScript_CoinClerk_ShowChoice_11:
	call GoldenrodCity_GameCorner_EventScript_CoinClerk_NotEnoughMoney
	return

GoldenrodCity_GameCorner_EventScript_CoinClerk_ShowChoice_14:
	call GoldenrodCity_GameCorner_EventScript_CoinClerk_NotEnoughMoney
	return


GoldenrodCity_GameCorner_EventScript_CoinClerk_NoRoom::
	msgbox GoldenrodCity_GameCorner_EventScript_CoinClerk_NoRoom_Text_0
	return


GoldenrodCity_GameCorner_EventScript_CoinClerk_NotEnoughMoney::
	msgbox GoldenrodCity_GameCorner_EventScript_CoinClerk_NotEnoughMoney_Text_0
	return


GoldenrodCity_GameCorner_EventScript_TMClerk::
	lock
	faceplayer
	msgbox GoldenrodCity_GameCorner_Text_PrizeVendorIntro
	checkitem ITEM_COIN_CASE, 1
	compare VAR_RESULT, 0
	goto_if_eq GoldenrodCity_GameCorner_EventScript_TMClerk_2
	message GoldenrodCity_GameCorner_Text_PrizeClerk_WhichPrize
	waitmessage
	showcoinsbox 0, 0
	call GoldenrodCity_GameCorner_EventScript_TMClerk_ShowChoice
	hidecoinsbox 0, 0
GoldenrodCity_GameCorner_EventScript_TMClerk_1:
	release
	return

GoldenrodCity_GameCorner_EventScript_TMClerk_2:
	msgbox GoldenrodCity_GameCorner_Text_PrizeVendorNoCoinCase
	goto GoldenrodCity_GameCorner_EventScript_TMClerk_1


GoldenrodCity_GameCorner_EventScript_TMClerk_ReturnToShowChoice::
	message GoldenrodCity_GameCorner_Text_PrizeClerk_WhichPrize
	waitmessage
	goto GoldenrodCity_GameCorner_EventScript_TMClerk_ShowChoice
	return


GoldenrodCity_GameCorner_EventScript_TMClerk_ShowChoice::
	multichoice 11, 0, MULTI_GAME_CORNER_TMS, 0
	switch VAR_RESULT
	case 0, GoldenrodCity_GameCorner_EventScript_TMClerk_ShowChoice_2
	case 1, GoldenrodCity_GameCorner_EventScript_TMClerk_ShowChoice_3
	case 2, GoldenrodCity_GameCorner_EventScript_TMClerk_ShowChoice_4
	msgbox GoldenrodCity_GameCorner_Text_PrizeVendorOutro
	return

GoldenrodCity_GameCorner_EventScript_TMClerk_ShowChoice_2:
	setvar VAR_TEMP_1, ITEM_TM24_THUNDERBOLT
	call GoldenrodCity_GameCorner_EventScript_TMClerk_ConfirmPrize
	return

GoldenrodCity_GameCorner_EventScript_TMClerk_ShowChoice_3:
	setvar VAR_TEMP_1, ITEM_TM13_ICE_BEAM
	call GoldenrodCity_GameCorner_EventScript_TMClerk_ConfirmPrize
	return

GoldenrodCity_GameCorner_EventScript_TMClerk_ShowChoice_4:
	setvar VAR_TEMP_1, ITEM_TM35_FLAMETHROWER
	call GoldenrodCity_GameCorner_EventScript_TMClerk_ConfirmPrize
	return


GoldenrodCity_GameCorner_EventScript_TMClerk_ConfirmPrize::
	bufferitemname 0, VAR_TEMP_1
	copyvar VAR_0x8004, VAR_TEMP_1
	special BufferTMHMMoveName
	msgbox GoldenrodCity_GameCorner_EventScript_TMClerk_ConfirmPrize_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq GoldenrodCity_GameCorner_EventScript_TMClerk_ConfirmPrize_1
	goto GoldenrodCity_GameCorner_EventScript_TMClerk_ReturnToShowChoice
	return

GoldenrodCity_GameCorner_EventScript_TMClerk_ConfirmPrize_1:
	checkcoins VAR_RESULT
	compare VAR_RESULT, 5500
	goto_if_lt GoldenrodCity_GameCorner_EventScript_TMClerk_ConfirmPrize_4
	checkitemspace VAR_TEMP_1, 1
	compare VAR_RESULT, FALSE
	goto_if_eq GoldenrodCity_GameCorner_EventScript_TMClerk_ConfirmPrize_7
	removecoins 5500
	additem VAR_TEMP_1
	updatecoinsbox 0, 0
	playse SE_SHOP
	msgbox GoldenrodCity_GameCorner_EventScript_PrizeVendorHereYouGo
	return

GoldenrodCity_GameCorner_EventScript_TMClerk_ConfirmPrize_4:
	msgbox GoldenrodCity_GameCorner_Text_PrizeVendorNotEnoughCoins
	return

GoldenrodCity_GameCorner_EventScript_TMClerk_ConfirmPrize_7:
	call Common_EventScript_BagIsFull
	goto GoldenrodCity_GameCorner_EventScript_TMClerk_ReturnToShowChoice
	return


GoldenrodCity_GameCorner_EventScript_MonClerk::
	lock
	faceplayer
	msgbox GoldenrodCity_GameCorner_Text_PrizeVendorIntro
	checkitem ITEM_COIN_CASE, 1
	compare VAR_RESULT, 0
	goto_if_eq GoldenrodCity_GameCorner_EventScript_MonClerk_2
	message GoldenrodCity_GameCorner_Text_PrizeClerk_WhichPrize
	waitmessage
	showcoinsbox 0, 0
	call GoldenrodCity_GameCorner_EventScript_MonClerk_ShowChoice
	hidecoinsbox 0, 0
GoldenrodCity_GameCorner_EventScript_MonClerk_1:
	release
	return

GoldenrodCity_GameCorner_EventScript_MonClerk_2:
	msgbox GoldenrodCity_GameCorner_Text_PrizeVendorNoCoinCase
	goto GoldenrodCity_GameCorner_EventScript_MonClerk_1


GoldenrodCity_GameCorner_EventScript_MonClerk_ReturnToShowChoice::
	message GoldenrodCity_GameCorner_Text_PrizeClerk_WhichPrize
	waitmessage
	goto GoldenrodCity_GameCorner_EventScript_MonClerk_ShowChoice
	return


GoldenrodCity_GameCorner_EventScript_MonClerk_ShowChoice::
	multichoice 11, 0, MULTI_GAME_CORNER_MONS, 0
	switch VAR_RESULT
	case 0, GoldenrodCity_GameCorner_EventScript_MonClerk_ShowChoice_2
	case 1, GoldenrodCity_GameCorner_EventScript_MonClerk_ShowChoice_3
	case 2, GoldenrodCity_GameCorner_EventScript_MonClerk_ShowChoice_4
	msgbox GoldenrodCity_GameCorner_Text_PrizeVendorOutro
	return

GoldenrodCity_GameCorner_EventScript_MonClerk_ShowChoice_2:
	setvar VAR_TEMP_1, SPECIES_ABRA
	setvar VAR_TEMP_2, 100
	call GoldenrodCity_GameCorner_EventScript_MonClerk_ConfirmPrize
	return

GoldenrodCity_GameCorner_EventScript_MonClerk_ShowChoice_3:
	setvar VAR_TEMP_1, SPECIES_CUBONE
	setvar VAR_TEMP_2, 800
	call GoldenrodCity_GameCorner_EventScript_MonClerk_ConfirmPrize
	return

GoldenrodCity_GameCorner_EventScript_MonClerk_ShowChoice_4:
	setvar VAR_TEMP_1, SPECIES_WOBBUFFET
	setvar VAR_TEMP_2, 1500
	call GoldenrodCity_GameCorner_EventScript_MonClerk_ConfirmPrize
	return


GoldenrodCity_GameCorner_EventScript_MonClerk_ConfirmPrize::
	bufferspeciesname 0, VAR_TEMP_1
	msgbox GoldenrodCity_GameCorner_EventScript_MonClerk_ConfirmPrize_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq GoldenrodCity_GameCorner_EventScript_MonClerk_ConfirmPrize_2
GoldenrodCity_GameCorner_EventScript_MonClerk_ConfirmPrize_1:
	textcolor MSG_COLOR_PREV
	goto GoldenrodCity_GameCorner_EventScript_MonClerk_ReturnToShowChoice
	return

GoldenrodCity_GameCorner_EventScript_MonClerk_ConfirmPrize_2:
	checkcoins VAR_RESULT
	compare VAR_RESULT, VAR_TEMP_2
	goto_if_lt GoldenrodCity_GameCorner_EventScript_MonClerk_ConfirmPrize_4
	switch VAR_TEMP_1
	case SPECIES_ABRA, GoldenrodCity_GameCorner_EventScript_MonClerk_ConfirmPrize_9
	givemon VAR_TEMP_1, 15, ITEM_NONE
GoldenrodCity_GameCorner_EventScript_MonClerk_ConfirmPrize_7:
	copyvar VAR_TEMP_3, VAR_RESULT
	switch VAR_TEMP_3
	case 2, GoldenrodCity_GameCorner_EventScript_MonClerk_ConfirmPrize_12
	removecoins VAR_TEMP_2
	updatecoinsbox 0, 0
	playse SE_SHOP
	msgbox GoldenrodCity_GameCorner_EventScript_PrizeVendorHereYouGo
	textcolor MSG_COLOR_SYS
	bufferspeciesname 0, VAR_TEMP_1
	playfanfare MUS_LEVEL_UP
	message gText_PlayerObtainedTheMon
	waitmessage
	waitfanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	switch VAR_TEMP_3
	case 0, GoldenrodCity_GameCorner_EventScript_MonClerk_ConfirmPrize_15
	case 1, GoldenrodCity_GameCorner_EventScript_MonClerk_ConfirmPrize_16
	goto GoldenrodCity_GameCorner_EventScript_MonClerk_ConfirmPrize_1

GoldenrodCity_GameCorner_EventScript_MonClerk_ConfirmPrize_4:
	msgbox GoldenrodCity_GameCorner_Text_PrizeVendorNotEnoughCoins
	goto GoldenrodCity_GameCorner_EventScript_MonClerk_ConfirmPrize_1

GoldenrodCity_GameCorner_EventScript_MonClerk_ConfirmPrize_9:
	givemon VAR_TEMP_1, 5, ITEM_NONE
	goto GoldenrodCity_GameCorner_EventScript_MonClerk_ConfirmPrize_7

GoldenrodCity_GameCorner_EventScript_MonClerk_ConfirmPrize_12:
	call Common_EventScript_BagIsFull
	goto GoldenrodCity_GameCorner_EventScript_MonClerk_ReturnToShowChoice
	goto GoldenrodCity_GameCorner_EventScript_MonClerk_ConfirmPrize_1

GoldenrodCity_GameCorner_EventScript_MonClerk_ConfirmPrize_15:
	compare VAR_RESULT, YES
	goto_if_eq GoldenrodCity_GameCorner_EventScript_MonClerk_ConfirmPrize_17
	goto GoldenrodCity_GameCorner_EventScript_MonClerk_ConfirmPrize_1

GoldenrodCity_GameCorner_EventScript_MonClerk_ConfirmPrize_16:
	compare VAR_RESULT, YES
	goto_if_eq GoldenrodCity_GameCorner_EventScript_MonClerk_ConfirmPrize_20
GoldenrodCity_GameCorner_EventScript_MonClerk_ConfirmPrize_19:
	call Common_EventScript_TransferredToPC
	goto GoldenrodCity_GameCorner_EventScript_MonClerk_ConfirmPrize_1

GoldenrodCity_GameCorner_EventScript_MonClerk_ConfirmPrize_17:
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	showcoinsbox 0, 0
	goto GoldenrodCity_GameCorner_EventScript_MonClerk_ConfirmPrize_1

GoldenrodCity_GameCorner_EventScript_MonClerk_ConfirmPrize_20:
	call Common_EventScript_NameReceivedBoxMon
	showcoinsbox 0, 0
	goto GoldenrodCity_GameCorner_EventScript_MonClerk_ConfirmPrize_19


GoldenrodCity_GameCorner_EventScript_Nerd::
	lock
	faceplayer
	msgbox GoldenrodCity_GameCorner_EventScript_Nerd_Text_0
	call GoldenrodCity_GameCorner_EventScript_FaceSlotMachine
	release
	return


GoldenrodCity_GameCorner_EventScript_PokefanM::
	lock
	faceplayer
	msgbox GoldenrodCity_GameCorner_EventScript_PokefanM_Text_0
	call GoldenrodCity_GameCorner_EventScript_FaceSlotMachine
	release
	return


GoldenrodCity_GameCorner_EventScript_GamblinMan::
	lock
	faceplayer
	msgbox GoldenrodCity_GameCorner_EventScript_GamblinMan_Text_0
	call GoldenrodCity_GameCorner_EventScript_FaceSlotMachine
	release
	return


GoldenrodCity_GameCorner_EventScript_CardFlipWoman::
	lock
	faceplayer
	msgbox GoldenrodCity_GameCorner_EventScript_CardFlipWoman_Text_0
	call GoldenrodCity_GameCorner_EventScript_FaceSlotMachine
	release
	return


GoldenrodCity_GameCorner_EventScript_WontStopWoman::
	msgbox GoldenrodCity_GameCorner_EventScript_WontStopWoman_Text_0, MSGBOX_NPC
	return


GoldenrodCity_GameCorner_EventScript_Gentleman::
	lock
	faceplayer
	msgbox GoldenrodCity_GameCorner_EventScript_Gentleman_Text_0
	call GoldenrodCity_GameCorner_EventScript_FaceSlotMachine
	release
	return


GoldenrodCity_GameCorner_EventScript_CoinCaseMan::
	msgbox GoldenrodCity_GameCorner_EventScript_CoinCaseMan_Text_0, MSGBOX_NPC
	return


GoldenrodCity_GameCorner_EventScript_MoveTutorInside::
	lock
	faceplayer
	msgbox GoldenrodCity_GameCorner_EventScript_MoveTutorInside_Text_0
	call GoldenrodCity_GameCorner_EventScript_FaceSlotMachine
	release
	return


GoldenrodCity_GameCorner_EventScript_Drink::
	msgbox GoldenrodCity_GameCorner_EventScript_Drink_Text_0, MSGBOX_SIGN
	return


GoldenrodCity_GameCorner_EventScript_FaceSlotMachine::
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	return


GoldenrodCity_GameCorner_EventScript_SlotMachine0::
	lockall
	setvar VAR_0x8004, 0
	goto GoldenrodCity_GameCorner_EventScript_SlotMachine
	return


GoldenrodCity_GameCorner_EventScript_SlotMachine1::
	lockall
	setvar VAR_0x8004, 1
	goto GoldenrodCity_GameCorner_EventScript_SlotMachine
	return


GoldenrodCity_GameCorner_EventScript_SlotMachine2::
	lockall
	setvar VAR_0x8004, 2
	goto GoldenrodCity_GameCorner_EventScript_SlotMachine
	return


GoldenrodCity_GameCorner_EventScript_SlotMachine3::
	lockall
	setvar VAR_0x8004, 3
	goto GoldenrodCity_GameCorner_EventScript_SlotMachine
	return


GoldenrodCity_GameCorner_EventScript_SlotMachine4::
	lockall
	setvar VAR_0x8004, 4
	goto GoldenrodCity_GameCorner_EventScript_SlotMachine
	return


GoldenrodCity_GameCorner_EventScript_SlotMachine5::
	lockall
	setvar VAR_0x8004, 5
	goto GoldenrodCity_GameCorner_EventScript_SlotMachine
	return


GoldenrodCity_GameCorner_EventScript_SlotMachine6::
	lockall
	setvar VAR_0x8004, 6
	goto GoldenrodCity_GameCorner_EventScript_SlotMachine
	return


GoldenrodCity_GameCorner_EventScript_SlotMachine7::
	lockall
	setvar VAR_0x8004, 7
	goto GoldenrodCity_GameCorner_EventScript_SlotMachine
	return


GoldenrodCity_GameCorner_EventScript_SlotMachine8::
	lockall
	setvar VAR_0x8004, 8
	goto GoldenrodCity_GameCorner_EventScript_SlotMachine
	return


GoldenrodCity_GameCorner_EventScript_SlotMachine9::
	lockall
	setvar VAR_0x8004, 9
	goto GoldenrodCity_GameCorner_EventScript_SlotMachine
	return


GoldenrodCity_GameCorner_EventScript_SlotMachine10::
	lockall
	setvar VAR_0x8004, 10
	goto GoldenrodCity_GameCorner_EventScript_SlotMachine
	return


GoldenrodCity_GameCorner_EventScript_SlotMachine11::
	lockall
	setvar VAR_0x8004, 11
	goto GoldenrodCity_GameCorner_EventScript_SlotMachine
	return


GoldenrodCity_GameCorner_EventScript_SlotMachine12::
	lockall
	setvar VAR_0x8004, 12
	goto GoldenrodCity_GameCorner_EventScript_SlotMachine
	return


GoldenrodCity_GameCorner_EventScript_SlotMachine13::
	lockall
	setvar VAR_0x8004, 13
	goto GoldenrodCity_GameCorner_EventScript_SlotMachine
	return


GoldenrodCity_GameCorner_EventScript_SlotMachine14::
	lockall
	setvar VAR_0x8004, 14
	goto GoldenrodCity_GameCorner_EventScript_SlotMachine
	return


GoldenrodCity_GameCorner_EventScript_SlotMachine15::
	lockall
	setvar VAR_0x8004, 15
	goto GoldenrodCity_GameCorner_EventScript_SlotMachine
	return


GoldenrodCity_GameCorner_EventScript_CardFlip0::
	lockall
	setvar VAR_0x8004, 0
	goto GoldenrodCity_GameCorner_EventScript_CardFlip
	return


GoldenrodCity_GameCorner_EventScript_CardFlip1::
	lockall
	setvar VAR_0x8004, 1
	goto GoldenrodCity_GameCorner_EventScript_CardFlip
	return


GoldenrodCity_GameCorner_EventScript_CardFlip2::
	lockall
	setvar VAR_0x8004, 2
	goto GoldenrodCity_GameCorner_EventScript_CardFlip
	return


GoldenrodCity_GameCorner_EventScript_CardFlip3::
	lockall
	setvar VAR_0x8004, 3
	goto GoldenrodCity_GameCorner_EventScript_CardFlip
	return


GoldenrodCity_GameCorner_EventScript_CardFlip4::
	lockall
	setvar VAR_0x8004, 4
	goto GoldenrodCity_GameCorner_EventScript_CardFlip
	return


GoldenrodCity_GameCorner_EventScript_CardFlip5::
	lockall
	setvar VAR_0x8004, 5
	goto GoldenrodCity_GameCorner_EventScript_CardFlip
	return


GoldenrodCity_GameCorner_EventScript_CardFlip6::
	lockall
	setvar VAR_0x8004, 6
	goto GoldenrodCity_GameCorner_EventScript_CardFlip
	return


GoldenrodCity_GameCorner_EventScript_CardFlip7::
	lockall
	setvar VAR_0x8004, 7
	goto GoldenrodCity_GameCorner_EventScript_CardFlip
	return


GoldenrodCity_GameCorner_EventScript_CardFlip8::
	lockall
	setvar VAR_0x8004, 8
	goto GoldenrodCity_GameCorner_EventScript_CardFlip
	return


GoldenrodCity_GameCorner_EventScript_CardFlip9::
	lockall
	setvar VAR_0x8004, 9
	goto GoldenrodCity_GameCorner_EventScript_CardFlip
	return


GoldenrodCity_GameCorner_EventScript_SlotMachine::
	checkitem ITEM_COIN_CASE, 1
	compare VAR_RESULT, 0
	goto_if_eq GoldenrodCity_GameCorner_EventScript_SlotMachine_2
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
GoldenrodCity_GameCorner_EventScript_SlotMachine_1:
	releaseall
	return

GoldenrodCity_GameCorner_EventScript_SlotMachine_2:
	msgbox GoldenrodCity_GameCorner_EventScript_SlotMachine_Text_0
	goto GoldenrodCity_GameCorner_EventScript_SlotMachine_1


GoldenrodCity_GameCorner_EventScript_CardFlip::
	checkitem ITEM_COIN_CASE, 1
	compare VAR_RESULT, 0
	goto_if_eq GoldenrodCity_GameCorner_EventScript_CardFlip_2
	special PlayCardFlip
	waitstate
GoldenrodCity_GameCorner_EventScript_CardFlip_1:
	releaseall
	return

GoldenrodCity_GameCorner_EventScript_CardFlip_2:
	msgbox GoldenrodCity_GameCorner_EventScript_SlotMachine_Text_0
	goto GoldenrodCity_GameCorner_EventScript_CardFlip_1


GoldenrodCity_GameCorner_EventScript_CoinClerk_Text_0:
	.string "Welcome to the GOLDENROD CITY\n"
	.string "GAME CORNER.$"

GoldenrodCity_GameCorner_EventScript_CoinClerk_Text_1:
	.string "Do you need game coins?\p"
	.string "Oh, you don't have a COIN CASE\n"
	.string "for your coins.$"

GoldenrodCity_GameCorner_EventScript_CoinClerk_Text_2:
	.string "Do you need some game coins?\p"
	.string "It costs ¥1000 for 50 coins.\n"
	.string "Do you want some?$"

GoldenrodCity_GameCorner_EventScript_CoinClerk_ShowChoice_Text_0:
	.string "Thank you!\n"
	.string "Here are 50 coins.$"

GoldenrodCity_GameCorner_EventScript_CoinClerk_ShowChoice_Text_1:
	.string "Thank you!\n"
	.string "Here are 500 coins.$"

GoldenrodCity_GameCorner_EventScript_CoinClerk_ShowChoice_Text_2:
	.string "No coins for you?\n"
	.string "Come again!$"

GoldenrodCity_GameCorner_EventScript_CoinClerk_NoRoom_Text_0:
	.string "Whoops!\n"
	.string "Your COIN CASE is full.$"

GoldenrodCity_GameCorner_EventScript_CoinClerk_NotEnoughMoney_Text_0:
	.string "You don't have enough money.$"

GoldenrodCity_GameCorner_EventScript_TMClerk_ConfirmPrize_Text_0:
	.string "So you want the {STR_VAR_1} {STR_VAR_2}.\n"
	.string "Is that right?$"

GoldenrodCity_GameCorner_EventScript_MonClerk_ConfirmPrize_Text_0:
	.string "So you want the {STR_VAR_1}.\n"
	.string "Is that right?$"

GoldenrodCity_GameCorner_EventScript_Nerd_Text_0:
	.string "I always play this slot machine. It\n"
	.string "pays out more than others, I think.$"

GoldenrodCity_GameCorner_EventScript_PokefanM_Text_0:
	.string "I just love this new slot machine.\p"
	.string "It's more of a challenge than the\n"
	.string "ones in CELADON.$"

GoldenrodCity_GameCorner_EventScript_GamblinMan_Text_0:
	.string "Life is a gamble.\n"
	.string "I'm going to flip cards till I drop!$"

GoldenrodCity_GameCorner_EventScript_CardFlipWoman_Text_0:
	.string "CARD FLIP…\p"
	.string "I prefer it over the slots because\n"
	.string "it's easier to figure out the odds.\p"
	.string "But the payout is much lower.$"

GoldenrodCity_GameCorner_EventScript_WontStopWoman_Text_0:
	.string "I won't quit until I win!$"

GoldenrodCity_GameCorner_EventScript_Gentleman_Text_0:
	.string "I taught BLIZZARD to my POKéMON.\p"
	.string "It was hard to get enough coins for\n"
	.string "it, but it was worth it.$"

GoldenrodCity_GameCorner_EventScript_CoinCaseMan_Text_0:
	.string "I couldn't win at the slots, and I\n"
	.string "blew it on card flipping…\p"
	.string "I got so furious, I tossed out my\n"
	.string "COIN CASE in the UNDERGROUND.$"

GoldenrodCity_GameCorner_EventScript_MoveTutorInside_Text_0:
	.string "Wahahah!\n"
	.string "The coins keep rolling in!$"

GoldenrodCity_GameCorner_EventScript_Drink_Text_0:
	.string "Someone left their drink.\n"
	.string "It smells sweet.$"

GoldenrodCity_GameCorner_EventScript_SlotMachine_Text_0:
	.string "You can't play without a COIN CASE.$"

GoldenrodCity_GameCorner_Text_PrizeClerk_WhichPrize::
	.string "Which prize would you like?$"

GoldenrodCity_GameCorner_Text_PrizeVendorIntro::
	.string "Welcome!\p"
	.string "We exchange your game coins for\n"
	.string "fabulous prizes!$"

GoldenrodCity_GameCorner_Text_PrizeVendorNoCoinCase::
	.string "Oh?\n"
	.string "You don't have a COIN CASE.$"

GoldenrodCity_GameCorner_Text_PrizeVendorNotEnoughCoins::
	.string "Sorry!\n"
	.string "You need more coins than that.$"

GoldenrodCity_GameCorner_EventScript_PrizeVendorHereYouGo::
	.string "Here you go!$"

GoldenrodCity_GameCorner_Text_PrizeVendorOutro::
	.string "Okay. Please save your coins\n"
	.string "and come again!$"
