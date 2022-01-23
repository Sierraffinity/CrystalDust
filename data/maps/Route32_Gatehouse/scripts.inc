Route32_Gatehouse_MapScripts::
	.byte 0


Route32_Gatehouse_Officer::
	msgbox Route32_Gatehouse_Officer_Text_0, MSGBOX_NPC
	return


Route32_Gatehouse_Man::
	msgbox Route32_Gatehouse_Man_Text_0, MSGBOX_NPC
	return


Route32_Gatehouse_Boy::
	msgbox Route32_Gatehouse_Boy_Text_0, MSGBOX_NPC
	return


Route32_Gatehouse_Officer_Text_0:
	.string "RUINS OF ALPH: a look-and-touch\n"
	.string "tourist site.\p"
	.string "Try the sliding stone panels!$"

Route32_Gatehouse_Man_Text_0:
	.string "You're studying the RUINS?\n"
	.string "I see a scientist in the making.$"

Route32_Gatehouse_Boy_Text_0:
	.string "There are drawings on stone panels.\n"
	.string "I tried moving them.\l"
	.string "I wonder what they are.$"
