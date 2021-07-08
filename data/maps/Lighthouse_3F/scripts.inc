Lighthouse_3F_MapScripts::
	.byte 0


Lighthouse_3F_EventScript_GentlemanPreston::
	trainerbattle_single TRAINER_PRESTON, Lighthouse_3F_EventScript_GentlemanPreston_Text_0, Lighthouse_3F_EventScript_GentlemanPreston_Text_1
	msgbox Lighthouse_3F_EventScript_GentlemanPreston_Text_2, MSGBOX_AUTOCLOSE
	end


Lighthouse_3F_Eventscript_SailorTerrell::
	trainerbattle_single TRAINER_TERRELL, Lighthouse_3F_Eventscript_SailorTerrell_Text_0, Lighthouse_3F_Eventscript_SailorTerrell_Text_1
	msgbox Lighthouse_3F_Eventscript_SailorTerrell_Text_2, MSGBOX_AUTOCLOSE
	end


Lighthouse_3F_Eventscript_BirdKeeperTheo::
	trainerbattle_single TRAINER_THEO, Lighthouse_3F_Eventscript_BirdKeeperTheo_Text_0, Lighthouse_3F_Eventscript_BirdKeeperTheo_Text_1
	msgbox Lighthouse_3F_Eventscript_BirdKeeperTheo_Text_2, MSGBOX_AUTOCLOSE
	end


Lighthouse_3F_EventScript_GentlemanPreston_Text_0:
	.string "I travel the world to train my\nPOKéMON. I wish to battle with you.$"

Lighthouse_3F_EventScript_GentlemanPreston_Text_1:
	.string "…sigh… I must train some more…$"

Lighthouse_3F_EventScript_GentlemanPreston_Text_2:
	.string "JASMINE used to use rock POKéMON\nlike ONIX.$"

Lighthouse_3F_Eventscript_SailorTerrell_Text_0:
	.string "SAILORS are both kind and strong.\nHow about you?$"

Lighthouse_3F_Eventscript_SailorTerrell_Text_1:
	.string "You are both kind and strong…$"

Lighthouse_3F_Eventscript_SailorTerrell_Text_2:
	.string "Every time I come back to OLIVINE, I\nvisit the GYM.\pThe GYM LEADER's POKéMON type has\nchanged without me noticing.$"

Lighthouse_3F_Eventscript_BirdKeeperTheo_Text_0:
	.string "Why are you here? Are you just going\nto gawk? I suggest that you leave!$"

Lighthouse_3F_Eventscript_BirdKeeperTheo_Text_1:
	.string "You really are concerned…$"

Lighthouse_3F_Eventscript_BirdKeeperTheo_Text_2:
	.string "How the heck do you go up?\pI want to visit the sick POKéMON,\nbut I can't get up there…$"
