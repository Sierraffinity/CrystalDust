Lighthouse_5F_MapScripts::
	.byte 0


Lighthouse_5F_EventScript_BirdKeeperDenis::
	trainerbattle_single TRAINER_DENIS, Lighthouse_5F_EventScript_BirdKeeperDenis_Text_0, Lighthouse_5F_EventScript_BirdKeeperDenis_Text_1
	msgbox Lighthouse_5F_EventScript_BirdKeeperDenis_Text_2, MSGBOX_AUTOCLOSE
	end


Lighthouse_5F_Eventscript_SailorErnest::
	trainerbattle_single TRAINER_ERNEST, Lighthouse_5F_Eventscript_SailorErnest_Text_0, Lighthouse_5F_Eventscript_SailorErnest_Text_1
	msgbox Lighthouse_5F_Eventscript_SailorErnest_Text_2, MSGBOX_AUTOCLOSE
	end


Lighthouse_5F_EventScript_BirdKeeperDenis_Text_0:
	.string "We're pretty high up here.\nMy bird POKéMON are in prime form.$"

Lighthouse_5F_EventScript_BirdKeeperDenis_Text_1:
	.string "Oops… They crashed…$"

Lighthouse_5F_EventScript_BirdKeeperDenis_Text_2:
	.string "My POKéMON learned how to use FLY in\nCIANWOOD.\pWell, since I'm a loser, I'll FLY\nacross the sea…$"

Lighthouse_5F_Eventscript_SailorErnest_Text_0:
	.string "I wanted to battle JASMINE, but she's\nnot up to it now. So, how about you?$"

Lighthouse_5F_Eventscript_SailorErnest_Text_1:
	.string "Whoa, whoa.\nYou're overwhelming!$"

Lighthouse_5F_Eventscript_SailorErnest_Text_2:
	.string "Being a GYM LEADER isn't just about\nbeing strong.\pA LEADER also needs to be\ncompassionate.$"
