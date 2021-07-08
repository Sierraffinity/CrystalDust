BlackthornCity_Mart_MapScripts::
	.byte 0


BlackthornCity_Mart_Eventscript_BlackBelt::
	msgbox BlackthornCity_Mart_Eventscript_BlackBelt_Text_0, MSGBOX_NPC
	end


BlackthornCity_Mart_Eventscript_Boy::
	msgbox BlackthornCity_Mart_Eventscript_Boy_Text_0, MSGBOX_NPC
	end


BlackthornCity_Mart_Eventscript_Clerk::
	lock
	faceplayer
	message gText_HowMayIHelpYou
	waitmessage
	pokemart BlackthornCity_Mart_Pokemart_Clerk
	msgbox gText_PleaseComeAgain
	release
	return


BlackthornCity_Mart_Pokemart_Clerk:
    .2byte ITEM_GREAT_BALL
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_MAX_POTION
    .2byte ITEM_FULL_HEAL
	.2byte ITEM_REVIVE
    .2byte ITEM_MAX_REPEL
    .2byte ITEM_X_DEFEND
    .2byte ITEM_X_ATTACK
	.2byte ITEM_NONE

BlackthornCity_Mart_Eventscript_BlackBelt_Text_0:
	.string "MAX REPEL keeps weak POKéMON away\nfrom you.\pIt's the longest lasting of the\nREPEL sprays.$"

BlackthornCity_Mart_Eventscript_Boy_Text_0:
	.string "You can't buy MAX REVIVE, but it\nfully restores a fainted POKéMON.\pBeware--it won't restore PP, the\nPOWER POINTS needed for moves.$"
