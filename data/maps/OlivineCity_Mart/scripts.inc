OlivineCity_Mart_MapScripts::
	.byte 0


OlivineCity_Mart_Eventscript_Girl1::
	msgbox OlivineCity_Mart_Eventscript_Girl1_Text_0, MSGBOX_NPC
	end


OlivineCity_Mart_Eventscript_Girl2::
	msgbox OlivineCity_Mart_Eventscript_Girl2_Text_0, MSGBOX_NPC
	end


OlivineCity_Mart_Eventscript_Clerk::
	lock
	faceplayer
	message gText_HowMayIHelpYou
	waitmessage
	pokemart OlivineCity_Mart_Pokemart_Clerk
	msgbox gText_PleaseComeAgain
	release
	return


OlivineCity_Mart_Pokemart_Clerk:
    .2byte ITEM_GREAT_BALL
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_HYPER_POTION
    .2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
    .2byte ITEM_AWAKENING
	.2byte ITEM_ICE_HEAL
    .2byte ITEM_SUPER_REPEL
	.2byte ITEM_NONE

OlivineCity_Mart_Eventscript_Girl1_Text_0:
	.string "Do your POKéMON already know the\nmove for carrying people on water?$"

OlivineCity_Mart_Eventscript_Girl2_Text_0:
	.string "My BUTTERFREE came from my boyfriend\noverseas.\pIt carried some MAIL from him.\nWant to know what it says?\pLet's see… Nope!\nIt's a secret!$"
