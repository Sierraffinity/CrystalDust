GoldenrodCity_BillsFamilysHouse_MapScripts::
	.byte 0


GoldenrodCity_BillsFamilysHouse_EventScript_Bill::
	lock
	faceplayer
	goto_if_set FLAG_GOT_EEVEE_FROM_BILL, GoldenrodCity_BillsFamilysHouse_EventScript_Bill_2
	msgbox GoldenrodCity_BillsFamilysHouse_EventScript_Bill_Text_1, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq GoldenrodCity_BillsFamilysHouse_EventScript_Bill_5
	msgbox GoldenrodCity_BillsFamilysHouse_EventScript_Bill_Text_4
GoldenrodCity_BillsFamilysHouse_EventScript_Bill_1:
	release
	return

GoldenrodCity_BillsFamilysHouse_EventScript_Bill_2:
	msgbox GoldenrodCity_BillsFamilysHouse_EventScript_Bill_Text_0
	goto GoldenrodCity_BillsFamilysHouse_EventScript_Bill_1

GoldenrodCity_BillsFamilysHouse_EventScript_Bill_5:
	msgbox GoldenrodCity_BillsFamilysHouse_EventScript_Bill_Text_2
	textcolor MSG_COLOR_SYS
	givemon SPECIES_EEVEE, 20, ITEM_NONE
	compare VAR_RESULT, 0
	goto_if_eq GoldenrodCity_BillsFamilysHouse_EventScript_Bill_9
	compare VAR_RESULT, 1
	goto_if_eq GoldenrodCity_BillsFamilysHouse_EventScript_Bill_10
	goto GoldenrodCity_BillsFamilysHouse_EventScript_Bill_PartyFull
GoldenrodCity_BillsFamilysHouse_EventScript_Bill_8:
	call EventScript_RestorePrevTextColor
	setflag FLAG_GOT_EEVEE_FROM_BILL
	msgbox GoldenrodCity_BillsFamilysHouse_EventScript_Bill_Text_3
	goto GoldenrodCity_BillsFamilysHouse_EventScript_Bill_1

GoldenrodCity_BillsFamilysHouse_EventScript_Bill_9:
	call GoldenrodCity_BillsFamilysHouse_EventScript_ReceivedEeveeFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq GoldenrodCity_BillsFamilysHouse_EventScript_Bill_14
	goto GoldenrodCity_BillsFamilysHouse_EventScript_Bill_8

GoldenrodCity_BillsFamilysHouse_EventScript_Bill_10:
	call GoldenrodCity_BillsFamilysHouse_EventScript_ReceivedEeveeFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq GoldenrodCity_BillsFamilysHouse_EventScript_Bill_17
GoldenrodCity_BillsFamilysHouse_EventScript_Bill_16:
	call Common_EventScript_TransferredToPC
	goto GoldenrodCity_BillsFamilysHouse_EventScript_Bill_8

GoldenrodCity_BillsFamilysHouse_EventScript_Bill_14:
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto GoldenrodCity_BillsFamilysHouse_EventScript_Bill_8

GoldenrodCity_BillsFamilysHouse_EventScript_Bill_17:
	call Common_EventScript_NameReceivedBoxMon
	goto GoldenrodCity_BillsFamilysHouse_EventScript_Bill_16


GoldenrodCity_BillsFamilysHouse_EventScript_Bill_PartyFull::
	call EventScript_RestorePrevTextColor
	msgbox GoldenrodCity_BillsFamilysHouse_EventScript_Bill_PartyFull_Text_0
	release
	return


GoldenrodCity_BillsFamilysHouse_EventScript_ReceivedEeveeFanfare::
	bufferspeciesname 0, SPECIES_EEVEE
	playfanfare MUS_OBTAIN_ITEM
	message GoldenrodCity_BillsFamilysHouse_EventScript_ReceivedEeveeFanfare_Text_0
	waitmessage
	waitfanfare
	return


GoldenrodCity_BillsFamilysHouse_EventScript_BillsMom::
	lock
	faceplayer
	goto_if_set FLAG_MET_BILL_IN_ECRUTEAK, GoldenrodCity_BillsFamilysHouse_EventScript_BillsMom_2
	msgbox GoldenrodCity_BillsFamilysHouse_EventScript_BillsMom_Text_1
GoldenrodCity_BillsFamilysHouse_EventScript_BillsMom_1:
	release
	return

GoldenrodCity_BillsFamilysHouse_EventScript_BillsMom_2:
	msgbox GoldenrodCity_BillsFamilysHouse_EventScript_BillsMom_Text_0
	goto GoldenrodCity_BillsFamilysHouse_EventScript_BillsMom_1


GoldenrodCity_BillsFamilysHouse_EventScript_BillsSister::
	lock
	faceplayer
	goto_if_unset FLAG_PHONE_CARD_BILL, GoldenrodCity_BillsFamilysHouse_EventScript_BillsSister_2
	msgbox GoldenrodCity_BillsFamilysHouse_Text_BillsSister_AfterPhoneNumber
GoldenrodCity_BillsFamilysHouse_EventScript_BillsSister_1:
	release
	return

GoldenrodCity_BillsFamilysHouse_EventScript_BillsSister_2:
	msgbox GoldenrodCity_BillsFamilysHouse_EventScript_BillsSister_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq GoldenrodCity_BillsFamilysHouse_EventScript_BillsSister_5
	msgbox GoldenrodCity_BillsFamilysHouse_EventScript_BillsSister_Text_2
	goto GoldenrodCity_BillsFamilysHouse_EventScript_BillsSister_1

GoldenrodCity_BillsFamilysHouse_EventScript_BillsSister_5:
	waitse
	setflag FLAG_PHONE_CARD_BILL
	playfanfare MUS_REGISTER_MATCH_CALL
	textcolor MSG_COLOR_SYS
	msgbox GoldenrodCity_BillsFamilysHouse_EventScript_BillsSister_Text_1
	waitfanfare
	closemessage
	delay 10
	call EventScript_RestorePrevTextColor
	msgbox GoldenrodCity_BillsFamilysHouse_Text_BillsSister_AfterPhoneNumber
	goto GoldenrodCity_BillsFamilysHouse_EventScript_BillsSister_1


GoldenrodCity_BillsFamilysHouse_EventScript_Bill_Text_0:
	.string "BILL: My pop, he won't work. All he\n"
	.string "does is goof off all day long.\p"
	.string "He's getting to be a real headache…$"

GoldenrodCity_BillsFamilysHouse_EventScript_Bill_Text_1:
	.string "BILL: Hi, {PLAYER}!\n"
	.string "Do us a favor and take this EEVEE.\p"
	.string "It came over when I was adjusting\n"
	.string "the Network Machine uplink.\p"
	.string "Someone has to take care of it,\n"
	.string "but I don't like being outside.\p"
	.string "Can I count on you to play with\n"
	.string "it, {PLAYER}?$"

GoldenrodCity_BillsFamilysHouse_EventScript_Bill_Text_2:
	.string "BILL: I knew you'd come through!\n"
	.string "Way to go! You're the real deal!\p"
	.string "Okay, I'm counting on you.\n"
	.string "Take good care of it!$"

GoldenrodCity_BillsFamilysHouse_EventScript_Bill_Text_3:
	.string "BILL: PROF. ELM claims EEVEE may\n"
	.string "evolve in new and unknown ways.$"

GoldenrodCity_BillsFamilysHouse_EventScript_Bill_Text_4:
	.string "Oh…\n"
	.string "Now what to do?$"

GoldenrodCity_BillsFamilysHouse_EventScript_Bill_PartyFull_Text_0:
	.string "Whoa, wait.\n"
	.string "You can't carry any more POKéMON.$"

GoldenrodCity_BillsFamilysHouse_EventScript_ReceivedEeveeFanfare_Text_0:
	.string "{PLAYER} received the {STR_VAR_1}\n"
	.string "from BILL.$"

GoldenrodCity_BillsFamilysHouse_EventScript_BillsMom_Text_0:
	.string "My husband was once known as a\n"
	.string "POKéMANIAC. BILL must have taken\l"
	.string "after his father.$"

GoldenrodCity_BillsFamilysHouse_EventScript_BillsMom_Text_1:
	.string "Oh, you collect POKéMON?\n"
	.string "My son BILL is an expert collector.\p"
	.string "He just got called to the POKéMON\n"
	.string "CENTER in ECRUTEAK CITY.\p"
	.string "My husband went off to the GAME\n"
	.string "CORNER without being called…$"

GoldenrodCity_BillsFamilysHouse_EventScript_BillsSister_Text_0:
	.string "Are you a TRAINER? I've got a\n"
	.string "useful phone number for you.\p"
	.string "Do you want it?$"

GoldenrodCity_BillsFamilysHouse_EventScript_BillsSister_Text_1:
	.string "{PLAYER} recorded BILL's number.$"

GoldenrodCity_BillsFamilysHouse_EventScript_BillsSister_Text_2:
	.string "My brother made the PC POKéMON\n"
	.string "storage system.\p"
	.string "I was going to give you BILL's\n"
	.string "number…$"

GoldenrodCity_BillsFamilysHouse_Text_BillsSister_AfterPhoneNumber::
	.string "My big brother BILL made the PC\n"
	.string "POKéMON storage system.$"
