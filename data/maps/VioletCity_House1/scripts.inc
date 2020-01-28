VioletCity_House1_MapScripts::
	.byte 0


VioletCity_House1_EventScript_Woman::
	msgbox VioletCity_House1_EventScript_Woman_Text_0, MSGBOX_NPC
	return


VioletCity_House1_EventScript_Girl::
	msgbox VioletCity_House1_EventScript_Girl_Text_0, MSGBOX_NPC
	return


VioletCity_House1_EventScript_Strawberry::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SPEAROW, 0
	msgbox VioletCity_House1_EventScript_Strawberry_Text_0
	waitmoncry
	release
	return


VioletCity_House1_EventScript_Woman_Text_0:
	.string "She uses the names of her favorite\n"
	.string "things to eat.\p"
	.string "For the nicknames she gives to her\n"
	.string "POKéMON, I mean.$"

VioletCity_House1_EventScript_Girl_Text_0:
	.string "I call my PIDGEY STRAWBERRY!$"

VioletCity_House1_EventScript_Strawberry_Text_0:
	.string "STRAWBERRY: Pijji!$"
