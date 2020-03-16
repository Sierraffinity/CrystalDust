AzaleaTown_KurtsHouse_MapScripts::
	.byte 0


AzaleaTown_KurtsHouse_EventScript_Kurt::
	lock
	faceplayer
	msgbox AzaleaTown_KurtsHouse_EventScript_Kurt_Text_0
	release
	return


AzaleaTown_KurtsHouse_EventScript_KurtsGranddaughter::
	lock
	faceplayer
	msgbox AzaleaTown_KurtsHouse_EventScript_KurtsGranddaughter_Text_0
	release
	return


AzaleaTown_KurtsHouse_EventScript_OakPhoto::
	msgbox AzaleaTown_KurtsHouse_EventScript_OakPhoto_Text_0, MSGBOX_SIGN
	return


AzaleaTown_KurtsHouse_EventScript_CelebiStatue::
	msgbox AzaleaTown_KurtsHouse_EventScript_CelebiStatue_Text_0, MSGBOX_SIGN
	return


AzaleaTown_KurtsHouse_EventScript_Slowpoke::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SLOWPOKE, 0
	msgbox AzaleaTown_KurtsHouse_EventScript_Slowpoke_Text_0
	waitmoncry
	release
	return


AzaleaTown_KurtsHouse_EventScript_Kurt_Text_0:
	.string "Hi! I'm KURT.$"

AzaleaTown_KurtsHouse_EventScript_KurtsGranddaughter_Text_0:
	.string "Hi! I'm not KURT.$"

AzaleaTown_KurtsHouse_EventScript_OakPhoto_Text_0:
	.string "…A young PROF. OAK?$"

AzaleaTown_KurtsHouse_EventScript_CelebiStatue_Text_0:
	.string "It's a statue of the forest's\n"
	.string "protector.$"

AzaleaTown_KurtsHouse_EventScript_Slowpoke_Text_0:
	.string "SLOWPOKE: …\n"
	.string "Yawn?$"
