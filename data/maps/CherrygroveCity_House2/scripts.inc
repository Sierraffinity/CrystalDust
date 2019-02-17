CherrygroveCity_House2_MapScripts::
	.byte 0

CherrygroveCity_House1_EventScript_Boy::
	lock
	msgbox CherrygroveCity_House1_Text_Boy
	release
	end

CherrygroveCity_House1_EventScript_Girl::
	lock
	msgbox CherrygroveCity_House1_Text_Girl
	release
	end

CherrygroveCity_House1_Text_Boy:
	.string "POKéMON gain experience in battle\n"
	.string "and change their form.$"

CherrygroveCity_House1_Text_Girl:
	.string "POKéMON change?\n"
	.string "I would be shocked if one did that!$"
