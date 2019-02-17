CherrygroveCity_House1_MapScripts::
	.byte 0

CherrygroveCity_House1_EventScript_Pokefan::
	msgbox CherrygroveCity_House1_Text_Pokefan, MSGBOX_NPC
	end

CherrygroveCity_House1_EventScript_Child::
	msgbox CherrygroveCity_House1_Text_Child, MSGBOX_NPC
	end

CherrygroveCity_House1_Text_Pokefan:
	.string "You're trying to see how good you\n"
	.string "are as a POKéMON TRAINER?\p"
	.string "You better visit the POKéMON GYMS\n"
	.string "all over JOHTO and collect BADGES.$"

CherrygroveCity_House1_Text_Child:
	.string "When I get older, I'm going to be a\n"
	.string "GYM LEADER!\p"
	.string "I make my POKéMON battle with my\n"
	.string "friend's to make them tougher!$"
