Route34_IlexNorthGatehouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route34_IlexNorthGatehouse_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

Route34_IlexNorthGatehouse_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	goto_if_set FLAG_FOREST_IS_RESTLESS, Route34_IlexNorthGatehouse_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	return

Route34_IlexNorthGatehouse_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
	setobjectxyperm 1, 4, 9
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_UP
	return


Route34_IlexNorthGatehouse_EventScript_TauntWoman::
	lock
	faceplayer
	goto_if_set FLAG_FOREST_IS_RESTLESS, Route34_IlexNorthGatehouse_EventScript_TauntWoman_2
	goto_if_unset FLAG_RECEIVED_TM12_TAUNT, Route34_IlexNorthGatehouse_EventScript_TauntWoman_3
Route34_IlexNorthGatehouse_EventScript_TauntWoman_1:
	msgbox Route34_IlexNorthGatehouse_EventScript_TauntWoman_Text_2
	release
	return

Route34_IlexNorthGatehouse_EventScript_TauntWoman_2:
	msgbox Route34_IlexNorthGatehouse_EventScript_TauntWoman_Text_0
	goto Route34_IlexNorthGatehouse_EventScript_TauntWoman_1

Route34_IlexNorthGatehouse_EventScript_TauntWoman_3:
	msgbox Route34_IlexNorthGatehouse_EventScript_TauntWoman_Text_1
	giveitem ITEM_TM12
	compare VAR_RESULT, 0
	goto_if_eq Route34_IlexNorthGatehouse_EventScript_TauntWoman_6
	setflag FLAG_RECEIVED_TM12_TAUNT
	goto Route34_IlexNorthGatehouse_EventScript_TauntWoman_1

Route34_IlexNorthGatehouse_EventScript_TauntWoman_6:
	goto Common_EventScript_ShowBagIsFull
	goto Route34_IlexNorthGatehouse_EventScript_TauntWoman_1


Route34_IlexNorthGatehouse_EventScript_Girl::
	msgbox Route34_IlexNorthGatehouse_EventScript_Girl_Text_0, MSGBOX_NPC
	return


Route34_IlexNorthGatehouse_EventScript_Butterfree::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_BUTTERFREE, 0
	msgbox Route34_IlexNorthGatehouse_EventScript_Butterfree_Text_0
	waitmoncry
	release
	return


Route34_IlexNorthGatehouse_EventScript_TauntWoman_Text_0:
	.string "Something's wrong in ILEX FOREST…\n"
	.string "You should stay away right now.$"

Route34_IlexNorthGatehouse_EventScript_TauntWoman_Text_1:
	.string "Oh, honey.\n"
	.string "You're making a POKéDEX?\p"
	.string "It must be hard battling so many\n"
	.string "different kinds of POKéMON.\p"
	.string "Try using this TM on them.$"

Route34_IlexNorthGatehouse_EventScript_TauntWoman_Text_2:
	.string "It's TAUNT, which I think is a\n"
	.string "pretty sweet move.\p"
	.string "Use it in battle, and the opponent\n"
	.string "can only use moves that damage\l"
	.string "your POKéMON for a bit.$"

Route34_IlexNorthGatehouse_EventScript_Girl_Text_0:
	.string "Did you see the shrine honoring\n"
	.string "the protector?\p"
	.string "It watches over the FOREST from\n"
	.string "across time.\p"
	.string "I think that it must be a GRASS-\n"
	.string "type POKéMON.$"

Route34_IlexNorthGatehouse_EventScript_Butterfree_Text_0:
	.string "BUTTERFREE: Freeh!$"
