Route31_Gatehouse_MapScripts::
	.byte 0

Route31_Gatehouse_EventScript_Officer::
	msgbox Route31_Gatehouse_Text_Officer, MSGBOX_NPC
	end

Route31_Gatehouse_EventScript_Girl::
	msgbox Route31_Gatehouse_Text_Girl, MSGBOX_NPC
	end

Route31_Gatehouse_Text_Officer:
	.string "Hi there!\n"
	.string "Did you visit SPROUT TOWER?$"

Route31_Gatehouse_Text_Girl:
	.string "I came too far out.\n"
	.string "I'd better phone home!$"
