GoldenrodCity_DeptStore_2F_MapScripts::
	.byte 0


GoldenrodCity_DeptStore_2F_EventScript_TopClerk::
	lock
	faceplayer
	message gText_HowMayIHelpYou
	waitmessage
	pokemart GoldenrodCity_DeptStore_2F_Pokemart_TopClerk
	msgbox gText_PleaseComeAgain
	release
	return


GoldenrodCity_DeptStore_2F_Pokemart_TopClerk:
	.2byte ITEM_POTION
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_ICE_HEAL
	.2byte ITEM_NONE

GoldenrodCity_DeptStore_2F_EventScript_LeftClerk::
	lock
	faceplayer
	message gText_HowMayIHelpYou
	waitmessage
	pokemart GoldenrodCity_DeptStore_2F_Pokemart_LeftClerk
	msgbox gText_PleaseComeAgain
	release
	return


GoldenrodCity_DeptStore_2F_Pokemart_LeftClerk:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_REPEL
	.2byte ITEM_REVIVE
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_POKE_DOLL
	.2byte ITEM_FAB_MAIL
	.2byte ITEM_NONE

GoldenrodCity_DeptStore_2F_EventScript_Youngster::
	msgbox GoldenrodCity_DeptStore_2F_EventScript_Youngster_Text_0, MSGBOX_NPC
	return


GoldenrodCity_DeptStore_2F_EventScript_AbraWoman::
	msgbox GoldenrodCity_DeptStore_2F_EventScript_AbraWoman_Text_0, MSGBOX_NPC
	return


GoldenrodCity_DeptStore_2F_EventScript_Gentleman::
	msgbox GoldenrodCity_DeptStore_2F_EventScript_Gentleman_Text_0, MSGBOX_NPC
	return


GoldenrodCity_DeptStore_2F_EventScript_FloorNumber::
	msgbox GoldenrodCity_DeptStore_2F_EventScript_FloorNumber_Text_0, MSGBOX_SIGN
	return


GoldenrodCity_DeptStore_2F_EventScript_Youngster_Text_0:
	.string "The POKéGEAR can store up to ten\n"
	.string "phone numbers.\p"
	.string "It's hard to decide which numbers\n"
	.string "to keep.$"

GoldenrodCity_DeptStore_2F_EventScript_AbraWoman_Text_0:
	.string "I got my ABRA at the GAME CORNER.\n"
	.string "Now it's my best partner.$"

GoldenrodCity_DeptStore_2F_EventScript_Gentleman_Text_0:
	.string "This DEPT. STORE makes me realize\n"
	.string "that GOLDENROD is a big city.\p"
	.string "The selection here is unmatched\n"
	.string "anywhere else.$"

GoldenrodCity_DeptStore_2F_EventScript_FloorNumber_Text_0:
	.string "Your Travel Companion\p"
	.string "2F TRAINER'S MARKET$"
