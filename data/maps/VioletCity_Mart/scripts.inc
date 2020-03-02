VioletCity_Mart_MapScripts::
	.byte 0


VioletCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIHelpYou
	waitmessage
	pokemart VioletCity_Mart_Pokemart
	msgbox gText_PleaseComeAgain
	release
	return


VioletCity_Mart_Pokemart:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_POTION
    .2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_X_DEFEND
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_SPEED
	.2byte ITEM_ORANGE_MAIL
	.2byte ITEM_NONE

VioletCity_Mart_EventScript_OldWoman::
	msgbox VioletCity_Mart_EventScript_OldWoman_Text_0, MSGBOX_NPC
	return


VioletCity_Mart_EventScript_Man::
	msgbox VioletCity_Mart_EventScript_Man_Text_0, MSGBOX_NPC
	return


VioletCity_Mart_EventScript_OldWoman_Text_0:
	.string "When you first catch a POKéMON,\n"
	.string "it may be weak.\p"
	.string "But it will eventually grow to\n"
	.string "be strong.\p"
	.string "It's important to treat POKéMON\n"
	.string "with love.$"

VioletCity_Mart_EventScript_Man_Text_0:
	.string "POKéMON can hold items like POTION\n"
	.string "and ANTIDOTE.\p"
	.string "But they don't appear to know how\n"
	.string "to use man-made items.$"
