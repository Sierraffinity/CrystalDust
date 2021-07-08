Lighthouse_2F_MapScripts::
	.byte 0


Lighthouse_2F_EventScript_GentlemanAlfred::
	trainerbattle_single TRAINER_ALFRED, Lighthouse_2F_EventScript_GentlemanAlfred_Text_0, Lighthouse_2F_EventScript_GentlemanAlfred_Text_1
	msgbox Lighthouse_2F_EventScript_GentlemanAlfred_Text_2, MSGBOX_AUTOCLOSE
	end


Lighthouse_2F_Eventscript_SailorHuey::
	trainerbattle_single TRAINER_HUEY_1, Lighthouse_2F_Eventscript_SailorHuey_Text_0, Lighthouse_2F_Eventscript_SailorHuey_Text_1
	msgbox Lighthouse_2F_Eventscript_SailorHuey_Text_2, MSGBOX_AUTOCLOSE
	end


Lighthouse_2F_EventScript_GentlemanAlfred_Text_0:
	.string "Hm? This is no place for playing.$"

Lighthouse_2F_EventScript_GentlemanAlfred_Text_1:
	.string "Ah! I can see that you're serious.$"

Lighthouse_2F_EventScript_GentlemanAlfred_Text_2:
	.string "Up top is a POKéMON that keeps the\nLIGHTHOUSE lit.\pBut I hear that it's sick now and\ncan't be cured by ordinary medicine.$"

Lighthouse_2F_Eventscript_SailorHuey_Text_0:
	.string "Men of the sea are always spoiling\nfor a good fight!$"

Lighthouse_2F_Eventscript_SailorHuey_Text_1:
	.string "Urf!\nI lose!$"

Lighthouse_2F_Eventscript_SailorHuey_Text_2:
	.string "What power! How would you like\nto sail the seas with me?$"
