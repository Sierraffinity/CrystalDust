Route33_MapScripts::
	.byte 0


Route33_EventScript_Girl::
	msgbox Route33_EventScript_Girl_Text_0, MSGBOX_NPC
	return


Route33_EventScript_Anthony::
	trainerbattle_single TRAINER_ANTHONY_1, Route33_Text_AnthonyIntro, Route33_Text_AnthonyDefeat
	msgbox Route33_Text_AnthonyPostBattle
	release
	return


Route33_EventScript_DirectionsSign::
	msgbox Route33_EventScript_DirectionsSign_Text_0, MSGBOX_SIGN
	return


Route33_EventScript_Girl_Text_0:
	.string "Pant, pant…\n"
	.string "I finally got through that cave.\p"
	.string "It was so much bigger than I'd\n"
	.string "expected.\p"
	.string "I got too tired to explore the whole\n"
	.string "thing, so I came outside.$"

Route33_EventScript_DirectionsSign_Text_0:
	.string "ROUTE 33$"
