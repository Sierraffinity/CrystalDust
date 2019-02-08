Route29_Gatehouse_MapScripts::
	.byte 0

Route29_Gatehouse_EventScript_Officer::
	msgbox Route29_Gatehouse_Text_Officer, MSGBOX_NPC
	end

Route29_Gatehouse_EventScript_Youngster::
	msgbox Route29_Gatehouse_Text_Youngster, MSGBOX_NPC
	end

Route29_Gatehouse_Text_Officer:
	.string "You can't climb ledges.\p"
	.string "But you can jump down from them\n"
	.string "to take a shortcut.$"

Route29_Gatehouse_Text_Youngster:
	.string "Different kinds of POKéMON appear\n"
	.string "past here.\p"
	.string "If you want to catch them all, you\n"
	.string "have to look everywhere.$"
