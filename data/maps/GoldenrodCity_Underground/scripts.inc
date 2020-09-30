GoldenrodCity_Underground_MapScripts::
	.byte 0


GoldenrodCity_Underground_EventScript_BargainMerchant::
	lock
	faceplayer
	gettime
	compare VAR_0x8002, TIME_MORNING
	goto_if_eq GoldenrodCity_Underground_EventScript_BargainMerchant_5
GoldenrodCity_Underground_EventScript_BargainMerchant_4:
	goto_if_set FLAG_DAILY_GOLDENROD_UNDERGROUND_BARGAINS, GoldenrodCity_Underground_EventScript_BargainMerchant_2
	msgbox GoldenrodCity_Underground_EventScript_BargainMerchant_Text_2
	msgbox GoldenrodCity_Underground_EventScript_BargainMerchant_Text_3
	return

GoldenrodCity_Underground_EventScript_BargainMerchant_1:
	msgbox GoldenrodCity_Underground_EventScript_BargainMerchant_Text_0
	return

GoldenrodCity_Underground_EventScript_BargainMerchant_2:
	msgbox GoldenrodCity_Underground_EventScript_BargainMerchant_Text_1
	return

GoldenrodCity_Underground_EventScript_BargainMerchant_5:
	compare VAR_0x8003, DAY_MONDAY
	goto_if_eq GoldenrodCity_Underground_EventScript_BargainMerchant_1
	goto GoldenrodCity_Underground_EventScript_BargainMerchant_4


GoldenrodCity_Underground_EventScript_OlderHaircutBrother::
	gettime
	compare VAR_0x8003, DAY_TUESDAY
	goto_if_eq GoldenrodCity_Underground_EventScript_OlderHaircutBrother_1
	compare VAR_0x8003, DAY_THURSDAY
	goto_if_eq GoldenrodCity_Underground_EventScript_OlderHaircutBrother_1
	compare VAR_0x8003, DAY_SATURDAY
	goto_if_eq GoldenrodCity_Underground_EventScript_OlderHaircutBrother_1
	msgbox GoldenrodCity_Underground_EventScript_BargainMerchant_Text_0
	return

GoldenrodCity_Underground_EventScript_OlderHaircutBrother_1:
	goto_if_set FLAG_DAILY_GOLDENROD_UNDERGROUND_HAIRCUT, GoldenrodCity_Underground_EventScript_OlderHaircutBrother_8
	showmoneybox 0, 0, FALSE
	msgbox GoldenrodCity_Underground_EventScript_OlderHaircutBrother_Text_1, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq GoldenrodCity_Underground_EventScript_OlderHaircutBrother_11
	return

GoldenrodCity_Underground_EventScript_OlderHaircutBrother_8:
	msgbox GoldenrodCity_Underground_EventScript_OlderHaircutBrother_Text_0
	return

GoldenrodCity_Underground_EventScript_OlderHaircutBrother_11:
	checkmoney 500, FALSE
	compare VAR_RESULT, TRUE
	goto_if_eq GoldenrodCity_Underground_EventScript_OlderHaircutBrother_13
	return

GoldenrodCity_Underground_EventScript_OlderHaircutBrother_13:
	msgbox GoldenrodCity_Underground_EventScript_OlderHaircutBrother_Text_2
	special ChoosePartyMon
	waitstate
	compare VAR_0x8004, 0xFF
	goto_if_ne GoldenrodCity_Underground_EventScript_OlderHaircutBrother_15
	return

GoldenrodCity_Underground_EventScript_OlderHaircutBrother_15:
	removemoney 500, FALSE
	showmoneybox 0, 0, FALSE
	playse SE_RG_SHOP
	msgbox GoldenrodCity_Underground_EventScript_OlderHaircutBrother_Text_3
	fadescreen FADE_TO_BLACK
	playfanfare MUS_HEAL
	waitfanfare
	fadescreen FADE_FROM_BLACK
	msgbox GoldenrodCity_Underground_EventScript_OlderHaircutBrother_Text_4
	return


GoldenrodCity_Underground_EventScript_Eric::
	trainerbattle_single TRAINER_ERIC, GoldenrodCity_Underground_Text_EricIntro, GoldenrodCity_Underground_Text_EricDefeated
	msgbox GoldenrodCity_Underground_Text_EricPostBattle, MSGBOX_DEFAULT
	release
	return


GoldenrodCity_Underground_EventScript_Teru::
	trainerbattle_single TRAINER_TERU, GoldenrodCity_Underground_Text_TeruIntro, GoldenrodCity_Underground_Text_TeruDefeated
	msgbox GoldenrodCity_Underground_Text_TeruPostBattle, MSGBOX_DEFAULT
	release
	return


GoldenrodCity_Underground_EventScript_Isaac::
	trainerbattle_single TRAINER_ISAAC, GoldenrodCity_Underground_Text_IsaacIntro, GoldenrodCity_Underground_Text_IsaacDefeated
	msgbox GoldenrodCity_Underground_Text_IsaacPostBattle, MSGBOX_DEFAULT
	release
	return


GoldenrodCity_Underground_EventScript_Donald::
	trainerbattle_single TRAINER_DONALD, GoldenrodCity_Underground_Text_DonaldIntro, GoldenrodCity_Underground_Text_DonaldDefeated
	msgbox GoldenrodCity_Underground_Text_DonaldPostBattle, MSGBOX_DEFAULT
	release
	return


GoldenrodCity_Underground_EventScript_BargainMerchant_Text_0:
	.string "We're not open today.$"

GoldenrodCity_Underground_EventScript_BargainMerchant_Text_1:
	.string "Sorry, I'm closing up shop.\n"
	.string "Come back another time.$"

GoldenrodCity_Underground_EventScript_BargainMerchant_Text_2:
	.string "Hiya!\n"
	.string "Care to see some bargains?\p"
	.string "I sell rare items that nobody else\n"
	.string "carries--but only one of each item.$"

GoldenrodCity_Underground_EventScript_BargainMerchant_Text_3:
	.string "Come by again sometime.$"

GoldenrodCity_Underground_EventScript_OlderHaircutBrother_Text_0:
	.string "I do only one haircut a day.\n"
	.string "I'm done for today.$"

GoldenrodCity_Underground_EventScript_OlderHaircutBrother_Text_1:
	.string "Welcome!\n"
	.string "I run the POKéMON SALON!\p"
	.string "I'm the old and better of the two\n"
	.string "HAIRCUT BROTHERS.\p"
	.string "I can make your POKéMON beautiful\n"
	.string "for just ¥500.\p"
	.string "Would you like me to do that?$"

GoldenrodCity_Underground_EventScript_OlderHaircutBrother_Text_2:
	.string "Which POKéMON should I work on?$"

GoldenrodCity_Underground_EventScript_OlderHaircutBrother_Text_3:
	.string "Okay!\n"
	.string "Watch it become beautiful!$"

GoldenrodCity_Underground_EventScript_OlderHaircutBrother_Text_4:
	.string "There!\n"
	.string "All done!$"
