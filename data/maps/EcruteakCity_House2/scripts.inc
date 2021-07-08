EcruteakCity_House2_MapScripts::
	.byte 0


EcruteakCity_House2_Eventscript_Fisherman::
	checkitem ITEM_ITEMFINDER, 1
	copyvar VAR_0x8008, VAR_RESULT
	checkpcitem ITEM_ITEMFINDER, 1
	compare VAR_0x8008, TRUE
	goto_if_eq EcruteakCity_House2_Eventscript_Fisherman_2
	compare VAR_RESULT, TRUE
	goto_if_eq EcruteakCity_House2_Eventscript_Fisherman_2
	lock
	faceplayer
	msgbox EcruteakCity_House2_Eventscript_Fisherman_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq EcruteakCity_House2_Eventscript_Fisherman_7
	msgbox EcruteakCity_House2_Eventscript_Fisherman_Text_2, MSGBOX_AUTOCLOSE
	release
	end

EcruteakCity_House2_Eventscript_Fisherman_2:
	msgbox EcruteakCity_House2_Text_GotItemfinder, MSGBOX_NPC
	end

EcruteakCity_House2_Eventscript_Fisherman_7:
	msgbox EcruteakCity_House2_Eventscript_Fisherman_Text_1, MSGBOX_DEFAULT
	giveitem ITEM_ITEMFINDER
	msgbox EcruteakCity_House2_Text_GotItemfinder, MSGBOX_AUTOCLOSE
	release
	end


EcruteakCity_House2_Eventscript_Book::
	lock
	msgbox EcruteakCity_House2_Eventscript_Book_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq EcruteakCity_House2_Eventscript_Book_2
	release
	end

EcruteakCity_House2_Eventscript_Book_2:
	msgbox EcruteakCity_House2_Eventscript_Book_Text_1, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq EcruteakCity_House2_Eventscript_Book_5
	release
	end

EcruteakCity_House2_Eventscript_Book_5:
	msgbox EcruteakCity_House2_Eventscript_Book_Text_2, MSGBOX_DEFAULT
	release
	end


EcruteakCity_House2_Eventscript_Fisherman_Text_0:
	.string "Ah. You're on an adventure with your\nPOKéMON?\pWell, what's an adventure without\ntreasure hunting?\pAm I right, or am I right?$"

EcruteakCity_House2_Eventscript_Fisherman_Text_1:
	.string "Good! You understand the true spirit\nof adventure.\pI like that!\nTake this with you.$"

EcruteakCity_House2_Eventscript_Fisherman_Text_2:
	.string "Oh… To each his own, I suppose…$"

EcruteakCity_House2_Eventscript_Book_Text_0:
	.string "“HISTORY OF ECRUTEAK”\nWant to read it?$"

EcruteakCity_House2_Eventscript_Book_Text_1:
	.string "In ECRUTEAK, there were two towers.\pEach tower was the roost of powerful\nflying POKéMON.\pBut one of the towers burned to the\nground.\pThe two POKéMON haven't been seen\nsince…\pKeep reading?$"

EcruteakCity_House2_Eventscript_Book_Text_2:
	.string "ECRUTEAK was also home to three\nPOKéMON that raced around the town.\pThey were said to have been born of\nwater, lightning and fire.\pBut they could not contain their\nexcessive power.\pSo they say the three ran like the\nwind of into the grassland…$"

EcruteakCity_House2_Text_GotItemfinder:
	.string "There are many items lying about\nthat aren't obvious.\pUse the ITEMFINDER to check if there\nis an item on the ground near you.\pIt doesn't show the exact spot, so\nyou'll have to look yourself.\pOh yeah--I heard there are items in\nECRUTEAK's BURNED TOWER.$"
