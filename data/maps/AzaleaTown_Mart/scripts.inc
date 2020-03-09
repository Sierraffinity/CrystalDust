AzaleaTown_Mart_MapScripts::
	.byte 0


AzaleaTown_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIHelpYou
	waitmessage
	pokemart AzaleaTown_Mart_Pokemart
	msgbox gText_PleaseComeAgain
	release
	return


AzaleaTown_Mart_Pokemart:
	.2byte ITEM_CHARCOAL
	.2byte ITEM_POKE_BALL
	.2byte ITEM_POTION
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_REPEL
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_WOOD_MAIL
	.2byte ITEM_NONE

AzaleaTown_Mart_EventScript_Cooltrainer::
	msgbox AzaleaTown_Mart_EventScript_Cooltrainer_Text_0, MSGBOX_NPC
	return


AzaleaTown_Mart_EventScript_BugCatcher::
	msgbox AzaleaTown_Mart_EventScript_BugCatcher_Text_0, MSGBOX_NPC
	return


AzaleaTown_Mart_EventScript_Cooltrainer_Text_0:
	.string "They don't sell GREAT BALLS here.\n"
	.string "POKé BALLS will have to do.\p"
	.string "I wish KURT would make me some of\n"
	.string "his custom BALLS.$"

AzaleaTown_Mart_EventScript_BugCatcher_Text_0:
	.string "A GREAT BALL is better for catching\n"
	.string "POKéMON than a POKé BALL.\p"
	.string "But KURT's might be even better\n"
	.string "than those sometimes.$"
