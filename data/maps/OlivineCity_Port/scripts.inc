OlivineCity_Port_MapScripts::
	.byte 0


OlivineCity_Port_Eventscript_Fisherman1::
	msgbox OlivineCity_Port_Eventscript_Fisherman1_Text_0, MSGBOX_NPC
	end


OlivineCity_Port_Eventscript_Fisherman2::
	msgbox OlivineCity_Port_Eventscript_Fisherman2_Text_0, MSGBOX_NPC
	end


OlivineCity_Port_Eventscript_Boy::
	msgbox OlivineCity_Port_Eventscript_Boy_Text_0, MSGBOX_NPC
	turnobject VAR_LAST_TALKED, DIR_SOUTH
	end


OlivineCity_Port_Eventscript_Girl::
	msgbox OlivineCity_Port_Eventscript_Girl_Text_0, MSGBOX_NPC
	turnobject VAR_LAST_TALKED, DIR_SOUTH
	end


OlivineCity_Port_Eventscript_Fisherman1_Text_0:
	.string "How many RODS do you have?\pDifferent rods catch different\nPOKéMON.$"

OlivineCity_Port_Eventscript_Fisherman2_Text_0:
	.string "SHELLDER are easy to catch here.\nThey're kind of rare elsewhere.$"

OlivineCity_Port_Eventscript_Boy_Text_0:
	.string "The S.S. AQUA uses jets to skim\nover the waves!$"

OlivineCity_Port_Eventscript_Girl_Text_0:
	.string "There are lots of POKéMON in KANTO.\nI wish I could go…$"
