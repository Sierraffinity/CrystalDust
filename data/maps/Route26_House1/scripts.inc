Route26_House1_MapScripts::
	.byte 0


Route26_House1_Eventscript_Woman::
	lock
	faceplayer
	msgbox Route26_House1_Eventscript_Woman_Text_0, MSGBOX_NPC
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox Route26_House1_Eventscript_Woman_Text_1, MSGBOX_NPC
	end


Route26_House1_Eventscript_Woman_Text_0:
	.string "Your POKéMON look a little tired.\nYou should rest them a while.$"

Route26_House1_Eventscript_Woman_Text_1:
	.string "There! Your POKéMON are looking good!\nKeep at it!$"
