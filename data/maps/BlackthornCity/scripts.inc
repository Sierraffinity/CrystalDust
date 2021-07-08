BlackthornCity_MapScripts::
	.byte 0


BlackthornCity_Eventscript_CitySign::
	msgbox BlackthornCity_Eventscript_CitySign_Text_0, MSGBOX_SIGN
	end


BlackthornCity_Eventscript_MoveDeleterSign::
	msgbox BlackthornCity_Eventscript_MoveDeleterSign_Text_0, MSGBOX_SIGN
	end


BlackthornCity_Eventscript_TrainerTipsSign::
	msgbox BlackthornCity_Eventscript_TrainerTipsSign_Text_0, MSGBOX_SIGN
	end


BlackthornCity_Eventscript_GymSign::
	msgbox BlackthornCity_Eventscript_GymSign_Text_0, MSGBOX_SIGN
	end


BlackthornCity_Eventscript_DragonsDenSign::
	msgbox BlackthornCity_Eventscript_DragonsDenSign_Text_0, MSGBOX_SIGN
	end


BlackthornCity_Eventscript_Woman::
	msgbox BlackthornCity_Eventscript_Woman_Text_0, MSGBOX_NPC
	end


BlackthornCity_Eventscript_BlackBelt::
	msgbox BlackthornCity_Eventscript_BlackBelt_Text_0, MSGBOX_NPC
	end


BlackthornCity_Eventscript_Girl::
	msgbox BlackthornCity_Eventscript_Girl_Text_0, MSGBOX_NPC
	end


BlackthornCity_Eventscript_Boy::
	msgbox BlackthornCity_Eventscript_Boy_Text_0, MSGBOX_NPC
	end


BlackthornCity_Eventscript_SantosOfSaturday::
	lock
	faceplayer
	goto_if_unset FLAG_RECEIVED_SPELL_TAG_FROM_SANTOS, BlackthornCity_Eventscript_SantosOfSaturday_2
	msgbox BlackthornCity_Eventscript_SantosOfSaturday_Text_4
BlackthornCity_Eventscript_SantosOfSaturday_1:
	release
	return

BlackthornCity_Eventscript_SantosOfSaturday_2:
	gettime
	compare VAR_0x8003, DAY_SATURDAY
	goto_if_eq BlackthornCity_Eventscript_SantosOfSaturday_5
	msgbox BlackthornCity_Eventscript_SantosOfSaturday_Text_3
	goto BlackthornCity_Eventscript_SantosOfSaturday_1

BlackthornCity_Eventscript_SantosOfSaturday_5:
	goto_if_unset FLAG_MET_SANTOS_OF_SATURDAY, BlackthornCity_Eventscript_SantosOfSaturday_9
	msgbox BlackthornCity_Eventscript_SantosOfSaturday_Text_1
BlackthornCity_Eventscript_SantosOfSaturday_8:
	giveitem ITEM_SPELL_TAG
	compare VAR_RESULT, 0
	goto_if_eq BlackthornCity_Eventscript_SantosOfSaturday_13
BlackthornCity_Eventscript_SantosOfSaturday_12:
	setflag FLAG_RECEIVED_SPELL_TAG_FROM_SANTOS
	msgbox BlackthornCity_Eventscript_SantosOfSaturday_Text_2
	goto BlackthornCity_Eventscript_SantosOfSaturday_1

BlackthornCity_Eventscript_SantosOfSaturday_9:
	msgbox BlackthornCity_Eventscript_SantosOfSaturday_Text_0
	setflag FLAG_MET_SANTOS_OF_SATURDAY
	goto BlackthornCity_Eventscript_SantosOfSaturday_8

BlackthornCity_Eventscript_SantosOfSaturday_13:
	goto Common_EventScript_ShowBagIsFull
	goto BlackthornCity_Eventscript_SantosOfSaturday_12


BlackthornCity_Eventscript_CitySign_Text_0:
	.string "BLACKTHORN CITY\nA Quiet Mountain Retreat$"

BlackthornCity_Eventscript_MoveDeleterSign_Text_0:
	.string "MOVE DELETER's HOUSE$"

BlackthornCity_Eventscript_TrainerTipsSign_Text_0:
	.string "TRAINER TIPS\pA POKéMON holding a LUM BERRY will\ncure itself of any status problem.$"

BlackthornCity_Eventscript_GymSign_Text_0:
	.string "BLACKTHORN CITY POKéMON GYM\nLEADER: CLAIR\pThe Blessed User of Dragon POKéMON$"

BlackthornCity_Eventscript_DragonsDenSign_Text_0:
	.string "DRAGON'S DEN AHEAD$"

BlackthornCity_Eventscript_Woman_Text_0:
	.string "Wow, you came through the ICE PATH?\nYou must be a real hotshot TRAINER!$"

BlackthornCity_Eventscript_BlackBelt_Text_0:
	.string "Arooo! Voices in my head!\nHuh? I'm listening to my radio!$"

BlackthornCity_Eventscript_Girl_Text_0:
	.string "Are you going to make your POKéMON\nforget some moves?$"

BlackthornCity_Eventscript_Boy_Text_0:
	.string "Dragon masters all come from the\ncity of BLACKTHORN.$"

BlackthornCity_Eventscript_SantosOfSaturday_Text_0:
	.string "SANTOS: …\nIt's SATURDAY…\pI'm SANTOS of SATURDAY…\pYou can have this…$"

BlackthornCity_Eventscript_SantosOfSaturday_Text_1:
	.string "SANTOS: You can have this…$"

BlackthornCity_Eventscript_SantosOfSaturday_Text_2:
	.string "SANTOS: …\nSPELL TAG…\pGHOST-type moves get stronger…\pIt will frighten you…$"

BlackthornCity_Eventscript_SantosOfSaturday_Text_3:
	.string "SANTOS: Today's not SATURDAY…$"

BlackthornCity_Eventscript_SantosOfSaturday_Text_4:
	.string "SANTOS: …\pSee you again on another SATURDAY…\pI won't have any more gifts…$"
