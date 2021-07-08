MtMortar_2F_MapScripts::
	.byte 0


MtMortar_2F_Eventscript_SuperNerdHugh::
	trainerbattle_single TRAINER_HUGH, MtMortar_2F_Eventscript_SuperNerdHugh_Text_0, MtMortar_2F_Eventscript_SuperNerdHugh_Text_1
	msgbox MtMortar_2F_Eventscript_SuperNerdHugh_Text_2, MSGBOX_AUTOCLOSE
	end


MtMortar_2F_Eventscript_SuperNerdHugh_Text_0:
	.string "Yo! MARKUS!$"

MtMortar_2F_Eventscript_SuperNerdHugh_Text_1:
	.string "Sorry, my mistake.$"

MtMortar_2F_Eventscript_SuperNerdHugh_Text_2:
	.string "I'm investigating MT. MORTAR, but my\npal's gone AWOL.\pHave you seen a TRAINER who has a\nSLOWPOKE that can use STRENGTH?$"
