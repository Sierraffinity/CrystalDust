CianwoodCity_MapScripts::
	.byte 0


CianwoodCity_Eventscript_CitySign::
	msgbox CianwoodCity_Eventscript_CitySign_Text_0, MSGBOX_SIGN
	end


CianwoodCity_Eventscript_PharmacySign::
	msgbox CianwoodCity_Eventscript_PharmacySign_Text_0, MSGBOX_SIGN
	end


CianwoodCity_Eventscript_GymSign::
	msgbox CianwoodCity_Eventscript_GymSign_Text_0, MSGBOX_SIGN
	end


CianwoodCity_Eventscript_StudioSign::
	msgbox CianwoodCity_Eventscript_StudioSign_Text_0, MSGBOX_SIGN
	end


CianwoodCity_Eventscript_PokeSeerSign::
	msgbox CianwoodCity_Eventscript_PokeSeerSign_Text_0, MSGBOX_SIGN
	end


CianwoodCity_Eventscript_FatMan::
	msgbox CianwoodCity_Eventscript_FatMan_Text_0, MSGBOX_NPC
	end


CianwoodCity_Eventscript_Boy::
	msgbox CianwoodCity_Eventscript_Boy_Text_0, MSGBOX_NPC
	end


CianwoodCity_Eventscript_Girl::
	msgbox CianwoodCity_Eventscript_Girl_Text_0, MSGBOX_NPC
	end


CianwoodCity_Eventscript_ChucksWife::
	checkitem ITEM_HM02, 1
	copyvar VAR_0x8008, VAR_RESULT
	checkpcitem ITEM_HM02, 1
	compare VAR_0x8008, TRUE
	goto_if_eq CianwoodCity_Eventscript_ChucksWife_2
	compare VAR_RESULT, TRUE
	goto_if_eq CianwoodCity_Eventscript_ChucksWife_2
	lock
	faceplayer
	msgbox CianwoodCity_Eventscript_ChucksWife_Text_0, MSGBOX_DEFAULT
	goto_if_unset FLAG_BADGE05_GET, CianwoodCity_Eventscript_ChucksWife_7
	msgbox CianwoodCity_Eventscript_ChucksWife_Text_2, MSGBOX_DEFAULT
	giveitem ITEM_HM04
	message CianwoodCity_Eventscript_ChucksWife_Text_3
	waitmessage
	msgbox CianwoodCity_Text_GotFly, MSGBOX_DEFAULT
	release
	end

CianwoodCity_Eventscript_ChucksWife_2:
	msgbox CianwoodCity_Text_GotFly, MSGBOX_NPC
	end

CianwoodCity_Eventscript_ChucksWife_7:
	msgbox CianwoodCity_Eventscript_ChucksWife_Text_1, MSGBOX_DEFAULT
	release
	end


CianwoodCity_Eventscript_CitySign_Text_0:
	.string "CIANWOOD CITY\nA Port Surrounded by Rough Seas$"

CianwoodCity_Eventscript_PharmacySign_Text_0:
	.string "500 Years of Tradition\pCIANWOOD CITY PHARMACY\nWe Await your Medicinal Queries$"

CianwoodCity_Eventscript_GymSign_Text_0:
	.string "CIANWOOD CITY POKéMON GYM\nLEADER: CHUCK\pHis Roaring Fists Do the Talking$"

CianwoodCity_Eventscript_StudioSign_Text_0:
	.string "CIANWOOD CITY PHOTO STUDIO\nTake a Snapshot as a Keepsake!$"

CianwoodCity_Eventscript_PokeSeerSign_Text_0:
	.string "THE POKé SEER AHEAD$"

CianwoodCity_Eventscript_FatMan_Text_0:
	.string "Boulders to the north of town can be\ncrushed.\pThey may be hiding something.\pYour POKéMON could use ROCK SMASH to\nbreak them.$"

CianwoodCity_Eventscript_Boy_Text_0:
	.string "If you use FLY, you can get back to\nOLIVINE instantly.$"

CianwoodCity_Eventscript_Girl_Text_0:
	.string "CHUCK, the GYM LEADER, spars with\nhis FIGHTING-type POKéMON.$"

CianwoodCity_Eventscript_ChucksWife_Text_0:
	.string "You crossed the sea to get here?\nThat must have been hard.\pIt would be much easier if your\nPOKéMON knew how to FLY…\p$"

CianwoodCity_Eventscript_ChucksWife_Text_1:
	.string "But you can't use FLY without this\ncity's GYM BADGE.\pIf you beat the GYM LEADER here,\ncome see me.\pI'll have a nice gift for you.$"

CianwoodCity_Eventscript_ChucksWife_Text_2:
	.string "That's CIANWOOD's GYM BADGE!\nThen you should take this HM.$"

CianwoodCity_Eventscript_ChucksWife_Text_3:
	.string "Teach FLY to your POKéMON.\pYou will be able to FLY instantly to\nanywhere you have visited.\p$"

CianwoodCity_Text_GotFly:
	.string "My husband lost to you, so he needs\nto train harder.\pThat's good, since he was getting a\nlittle chubby.$"
