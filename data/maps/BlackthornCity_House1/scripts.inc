BlackthornCity_House1_MapScripts::
	.byte 0


BlackthornCity_House1_Eventscript_OldWoman::
	msgbox BlackthornCity_House1_Eventscript_OldWoman_Text_0, MSGBOX_NPC
	end


BlackthornCity_House1_Eventscript_Dratini::
	lock
	faceplayer
	playmoncry SPECIES_DRATINI, 0
	msgbox BlackthornCity_House1_Eventscript_Dratini_Text_0, MSGBOX_DEFAULT
	waitmoncry
	release
	end


BlackthornCity_House1_Eventscript_OldWoman_Text_0:
	.string "A clan of TRAINERS who can freely\ncommand dragons live right here in\lBLACKTHORN.\pAs a result, there are many legends\nabout dragons in this town.$"

BlackthornCity_House1_Eventscript_Dratini_Text_0:
	.string "DRATINI: Draa!$"
