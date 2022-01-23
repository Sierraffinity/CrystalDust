AzaleaTown_CharcoalKiln_MapScripts::
	.byte 0


AzaleaTown_CharcoalKiln_EventScript_Master::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM01, AzaleaTown_CharcoalKiln_EventScript_Master_2
	goto_if_set FLAG_CLEARED_SLOWPOKE_WELL, AzaleaTown_CharcoalKiln_EventScript_Master_3
	msgbox AzaleaTown_CharcoalKiln_EventScript_Master_Text_2
AzaleaTown_CharcoalKiln_EventScript_Master_1:
	release
	return

AzaleaTown_CharcoalKiln_EventScript_Master_2:
	msgbox AzaleaTown_CharcoalKiln_EventScript_Master_Text_0
	goto AzaleaTown_CharcoalKiln_EventScript_Master_1

AzaleaTown_CharcoalKiln_EventScript_Master_3:
	msgbox AzaleaTown_CharcoalKiln_EventScript_Master_Text_1
	goto AzaleaTown_CharcoalKiln_EventScript_Master_1


AzaleaTown_CharcoalKiln_EventScript_Apprentice::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_CHARCOAL_AZALEA, AzaleaTown_CharcoalKiln_EventScript_Apprentice_2
	goto_if_set FLAG_RECEIVED_HM01, AzaleaTown_CharcoalKiln_EventScript_Apprentice_3
	msgbox AzaleaTown_CharcoalKiln_EventScript_Apprentice_Text_2
AzaleaTown_CharcoalKiln_EventScript_Apprentice_1:
	release
	return

AzaleaTown_CharcoalKiln_EventScript_Apprentice_2:
	msgbox AzaleaTown_CharcoalKiln_EventScript_Apprentice_Text_0
	goto AzaleaTown_CharcoalKiln_EventScript_Apprentice_1

AzaleaTown_CharcoalKiln_EventScript_Apprentice_3:
	msgbox AzaleaTown_CharcoalKiln_EventScript_Apprentice_Text_1
	giveitem ITEM_CHARCOAL
	compare VAR_RESULT, 0
	goto_if_eq AzaleaTown_CharcoalKiln_EventScript_Apprentice_7
	setflag FLAG_RECEIVED_CHARCOAL_AZALEA
	goto AzaleaTown_CharcoalKiln_EventScript_Apprentice_1

AzaleaTown_CharcoalKiln_EventScript_Apprentice_7:
	goto Common_EventScript_ShowBagIsFull
	goto AzaleaTown_CharcoalKiln_EventScript_Apprentice_1


AzaleaTown_CharcoalKiln_EventScript_Farfetchd::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_FARFETCHD, 0
	msgbox AzaleaTown_CharcoalKiln_EventScript_Farfetchd_Text_0
	waitmoncry
	release
	return


AzaleaTown_CharcoalKiln_EventScript_Master_Text_0:
	.string "You chased off TEAM ROCKET and\n"
	.string "went to ILEX FOREST alone?\p"
	.string "That takes guts! I like that.\n"
	.string "Come train with us.$"

AzaleaTown_CharcoalKiln_EventScript_Master_Text_1:
	.string "The SLOWPOKE have returned…\n"
	.string "But my APPRENTICE hasn't come\l"
	.string "back from ILEX FOREST.\p"
	.string "Where in the world could that\n"
	.string "lazy guy be?$"

AzaleaTown_CharcoalKiln_EventScript_Master_Text_2:
	.string "All the SLOWPOKE have disappeared\n"
	.string "from the town.\p"
	.string "The forest's protector may be\n"
	.string "angry with us…\p"
	.string "It may be a bad omen.\n"
	.string "We should stay in.$"

AzaleaTown_CharcoalKiln_EventScript_Apprentice_Text_0:
	.string "The SLOWPOKE came back, and you\n"
	.string "even found FARFETCH'D.\p"
	.string "You're the coolest, man!$"

AzaleaTown_CharcoalKiln_EventScript_Apprentice_Text_1:
	.string "I'm sorry--I forgot to thank you\n"
	.string "for helping me with FARFETCH'D.\p"
	.string "This is CHARCOAL that I made.\n"
	.string "FIRE-type POKéMON would be happy\l"
	.string "to hold that.$"

AzaleaTown_CharcoalKiln_EventScript_Apprentice_Text_2:
	.string "Where have all the SLOWPOKE gone?\n"
	.string "Are they out playing somewhere?$"

AzaleaTown_CharcoalKiln_EventScript_Farfetchd_Text_0:
	.string "FARFETCH'D: Kwaa!$"
