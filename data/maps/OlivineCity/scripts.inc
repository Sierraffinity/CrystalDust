OlivineCity_MapScripts::
	.byte 0


OlivineCity_EventScript_CitySign::
	msgbox OlivineCity_EventScript_CitySign_Text_0, MSGBOX_SIGN
	end


OlivineCity_EventScript_GymSign::
	msgbox OlivineCity_EventScript_GymSign_Text_0, MSGBOX_SIGN
	end


OlivineCity_EventScript_PortSign::
	msgbox OlivineCity_EventScript_PortSign_Text_0, MSGBOX_SIGN
	end


OlivineCity_EventScript_LighthouseSign::
	msgbox OlivineCity_EventScript_LighthouseSign_Text_0, MSGBOX_SIGN
	end


OlivineCity_EventScript_BattleTowerSign::
	msgbox OlivineCity_EventScript_BattleTowerSign_Text_0, MSGBOX_SIGN
	end


OlivineCity_EventScript_Boy::
	random 2
	compare VAR_RESULT, 0
	goto_if_eq OlivineCity_EventScript_Boy_2
	msgbox OlivineCity_EventScript_Boy_Text_1, MSGBOX_NPC
	end

OlivineCity_EventScript_Boy_2:
	msgbox OlivineCity_EventScript_Boy_Text_0, MSGBOX_NPC
	end


OlivineCity_EventScript_Sailor1::
	msgbox OlivineCity_EventScript_Sailor1_Text_0, MSGBOX_NPC
	end


OlivineCity_EventScript_Sailor2::
	msgbox OlivineCity_EventScript_Sailor2_Text_0, MSGBOX_NPC
	end


OlivineCity_EventScript_CitySign_Text_0:
	.string "OLIVINE CITY\nThe Port Closest to Foreign Lands$"

OlivineCity_EventScript_GymSign_Text_0:
	.string "OLIVINE CITY POKéMON GYM\nLEADER: JASMINE\pThe Steel-Clad Defense Girl$"

OlivineCity_EventScript_PortSign_Text_0:
	.string "OLIVINE PORT\nFAST SHIP PIER$"

OlivineCity_EventScript_LighthouseSign_Text_0:
	.string "OLIVINE LIGHTHOUSE\nAlso known as the GLITTER LIGHTHOUSE$"

OlivineCity_EventScript_BattleTowerSign_Text_0:
	.string "BATTLE TOWER AHEAD\nOpening Now!$"

OlivineCity_EventScript_Boy_Text_0:
	.string "That thing you have--it's a POKéGEAR,\nright? Wow, that's cool.$"

OlivineCity_EventScript_Boy_Text_1:
	.string "Wow, you have a POKéDEX!\nThat is just so awesome.$"

OlivineCity_EventScript_Sailor1_Text_0:
	.string "The sea is sweet!\nSunsets on the sea are marvelous!\pSing with me!\nYo-ho! Blow the man down!…$"

OlivineCity_EventScript_Sailor2_Text_0:
	.string "Dark roads are dangerous at night.\pBut in the pitch-black of night, the\nsea is even more treacherous!\pWithout the beacon of the LIGHTHOUSE\nto guide it, no ship can sail.$"
