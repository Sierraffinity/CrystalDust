GoldenrodCity_DeptStore_4F_MapScripts::
	.byte 0


GoldenrodCity_DeptStore_4F_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIHelpYou
	waitmessage
	pokemart GoldenrodCity_DeptStore_4F_Pokemart_Clerk
	msgbox gText_PleaseComeAgain
	release
	return


GoldenrodCity_DeptStore_4F_Pokemart_Clerk:
	.2byte ITEM_PROTEIN
	.2byte ITEM_IRON
	.2byte ITEM_CARBOS
	.2byte ITEM_CALCIUM
	.2byte ITEM_HP_UP
	.2byte ITEM_NONE

GoldenrodCity_DeptStore_4F_EventScript_ProteinGuy::
	msgbox GoldenrodCity_DeptStore_4F_EventScript_ProteinGuy_Text_0, MSGBOX_NPC
	return


GoldenrodCity_DeptStore_4F_EventScript_BugCatcher::
	msgbox GoldenrodCity_DeptStore_4F_EventScript_BugCatcher_Text_0, MSGBOX_NPC
	return


GoldenrodCity_DeptStore_4F_EventScript_GameboyKid::
	msgbox GoldenrodCity_DeptStore_4F_EventScript_GameboyKid_Text_0, MSGBOX_NPC
	return


GoldenrodCity_DeptStore_4F_EventScript_FloorNumber::
	msgbox GoldenrodCity_DeptStore_4F_EventScript_FloorNumber_Text_0, MSGBOX_SIGN
	return


GoldenrodCity_DeptStore_4F_EventScript_ProteinGuy_Text_0:
	.string "Hey.\n"
	.string "I love strong POKéMON.\p"
	.string "I feed them PROTEIN to crank up\n"
	.string "their ATTACK.$"

GoldenrodCity_DeptStore_4F_EventScript_BugCatcher_Text_0:
	.string "IRON adds to your POKéMON's\n"
	.string "DEFENSE.$"

GoldenrodCity_DeptStore_4F_EventScript_GameboyKid_Text_0:
	.string "Some POKéMON evolve only by being\n"
	.string "traded via a Wireless Adapter or\l"
	.string "a GBA Game Link cable.\p"
	.string "I know of four: MACHOKE, KADABRA,\n"
	.string "HAUNTER and, um, GRAVELER.\p"
	.string "I heard there are others too.$"

GoldenrodCity_DeptStore_4F_EventScript_FloorNumber_Text_0:
	.string "Let Us Pump Up Your POKéMON!\p"
	.string "4F MEDICINE BOX$"
