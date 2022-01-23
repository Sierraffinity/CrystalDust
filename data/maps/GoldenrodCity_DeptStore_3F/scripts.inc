GoldenrodCity_DeptStore_3F_MapScripts::
	.byte 0


GoldenrodCity_DeptStore_3F_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIHelpYou
	waitmessage
	pokemart GoldenrodCity_DeptStore_3F_Pokemart_Clerk
	msgbox gText_PleaseComeAgain
	release
	return


GoldenrodCity_DeptStore_3F_Pokemart_Clerk:
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_SPECIAL
	.2byte ITEM_X_DEFEND
	.2byte ITEM_X_ATTACK
	.2byte ITEM_DIRE_HIT
	.2byte ITEM_GUARD_SPEC
	.2byte ITEM_X_ACCURACY
	.2byte ITEM_NONE

GoldenrodCity_DeptStore_3F_EventScript_Rocker::
	msgbox GoldenrodCity_DeptStore_3F_EventScript_Rocker_Text_0, MSGBOX_NPC
	return


GoldenrodCity_DeptStore_3F_EventScript_ImpatientNerd::
	msgbox GoldenrodCity_DeptStore_3F_EventScript_ImpatientNerd_Text_0, MSGBOX_NPC
	return


GoldenrodCity_DeptStore_3F_EventScript_FloorNumber::
	msgbox GoldenrodCity_DeptStore_3F_EventScript_FloorNumber_Text_0, MSGBOX_SIGN
	return


GoldenrodCity_DeptStore_3F_EventScript_Rocker_Text_0:
	.string "Hey! When you battle, do you\n"
	.string "use X SPECIAL?\p"
	.string "It's awesome. It really jacks\n"
	.string "up SP. ATK!$"

GoldenrodCity_DeptStore_3F_EventScript_ImpatientNerd_Text_0:
	.string "I, I, I'm really impatient!\n"
	.string "I use X SPEED in battle to speed\l"
	.string "up my POKéMON.$"

GoldenrodCity_DeptStore_3F_EventScript_FloorNumber_Text_0:
	.string "For Victory Seekers\p"
	.string "3F BATTLE COLLECTION$"
