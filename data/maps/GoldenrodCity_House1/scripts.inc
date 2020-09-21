GoldenrodCity_House1_MapScripts:: @ 8215F76
	.byte 0

GoldenrodCity_House1_EventScript_OldWoman:: @ 8215F77
	msgbox GoldenrodCity_House1_Text_DevonWorkersLiveHere, MSGBOX_NPC
	end

GoldenrodCity_House1_EventScript_Skitty:: @ 8215F80
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SKITTY, 0
	msgbox GoldenrodCity_House1_Text_Skitty, MSGBOX_DEFAULT
	waitmoncry
	release
	end

GoldenrodCity_House1_Text_DevonWorkersLiveHere: @ 8215F93
	.string "DEVON CORPORATION's workers live in\n"
	.string "this building.$"

GoldenrodCity_House1_Text_Skitty: @ 8215FC6
	.string "SKITTY: Gyaaaah!$"

