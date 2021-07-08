LakeOfRage_MapScripts::
	.byte 0


LakeOfRage_Eventscript_LakeSign::
	msgbox LakeOfRage_Eventscript_LakeSign_Text_0, MSGBOX_SIGN
	end


LakeOfRage_Eventscript_RightLakeGuy::
	msgbox LakeOfRage_Eventscript_RightLakeGuy_Text_0, MSGBOX_NPC
	end


LakeOfRage_Eventscript_Girl::
	msgbox LakeOfRage_Eventscript_Girl_Text_0, MSGBOX_NPC
	end


LakeOfRage_Eventscript_WesleyOfWednesday::
	lock
	faceplayer
	goto_if_unset FLAG_RECEIVED_BLACK_BELT_FROM_WESLEY, LakeOfRage_Eventscript_WesleyOfWednesday_2
	msgbox LakeOfRage_Eventscript_WesleyOfWednesday_Text_4
LakeOfRage_Eventscript_WesleyOfWednesday_1:
	release
	return

LakeOfRage_Eventscript_WesleyOfWednesday_2:
	gettime
	compare VAR_0x8003, DAY_WEDNESDAY
	goto_if_eq LakeOfRage_Eventscript_WesleyOfWednesday_5
	msgbox LakeOfRage_Eventscript_WesleyOfWednesday_Text_3
	goto LakeOfRage_Eventscript_WesleyOfWednesday_1

LakeOfRage_Eventscript_WesleyOfWednesday_5:
	goto_if_unset FLAG_MET_WESLEY_OF_WEDNESDAY, LakeOfRage_Eventscript_WesleyOfWednesday_9
	msgbox LakeOfRage_Eventscript_WesleyOfWednesday_Text_1
LakeOfRage_Eventscript_WesleyOfWednesday_8:
	giveitem ITEM_BLACK_BELT
	compare VAR_RESULT, 0
	goto_if_eq LakeOfRage_Eventscript_WesleyOfWednesday_13
LakeOfRage_Eventscript_WesleyOfWednesday_12:
	setflag FLAG_RECEIVED_BLACK_BELT_FROM_WESLEY
	msgbox LakeOfRage_Eventscript_WesleyOfWednesday_Text_2
	goto LakeOfRage_Eventscript_WesleyOfWednesday_1

LakeOfRage_Eventscript_WesleyOfWednesday_9:
	msgbox LakeOfRage_Eventscript_WesleyOfWednesday_Text_0
	setflag FLAG_MET_WESLEY_OF_WEDNESDAY
	goto LakeOfRage_Eventscript_WesleyOfWednesday_8

LakeOfRage_Eventscript_WesleyOfWednesday_13:
	goto Common_EventScript_ShowBagIsFull
	goto LakeOfRage_Eventscript_WesleyOfWednesday_12


LakeOfRage_Eventscript_CooltrainerAaron::
	trainerbattle_single TRAINER_AARON, LakeOfRage_Eventscript_CooltrainerAaron_Text_0, LakeOfRage_Eventscript_CooltrainerAaron_Text_1
	msgbox LakeOfRage_Eventscript_CooltrainerAaron_Text_2, MSGBOX_AUTOCLOSE
	end


LakeOfRage_Eventscript_CooltrainerLois::
	trainerbattle_single TRAINER_LOIS, LakeOfRage_Eventscript_CooltrainerLois_Text_0, LakeOfRage_Eventscript_CooltrainerLois_Text_1
	msgbox LakeOfRage_Eventscript_CooltrainerLois_Text_2, MSGBOX_AUTOCLOSE
	end


LakeOfRage_Eventscript_FishermanAndre::
	trainerbattle_single TRAINER_ANDRE, LakeOfRage_Eventscript_FishermanAndre_Text_0, LakeOfRage_Eventscript_FishermanAndre_Text_1
	msgbox LakeOfRage_Eventscript_FishermanAndre_Text_2, MSGBOX_AUTOCLOSE
	end


LakeOfRage_Eventscript_FishermanRaymond::
	trainerbattle_single TRAINER_RAYMOND, LakeOfRage_Eventscript_FishermanRaymond_Text_0, LakeOfRage_Eventscript_FishermanRaymond_Text_1
	msgbox LakeOfRage_Eventscript_FishermanRaymond_Text_2, MSGBOX_AUTOCLOSE
	end


LakeOfRage_Eventscript_LakeSign_Text_0:
	.string "The LAKE OF RAGE, also known as\nGYARADOS LAKE.$"

LakeOfRage_Eventscript_RightLakeGuy_Text_0:
	.string "I heard this lake was made by\nrampaging GYARADOS.\pI wonder if there is any connection\nto their mass outbreak now?$"

LakeOfRage_Eventscript_Girl_Text_0:
	.string "Did my eyes deceive me?\nI saw a red GYARADOS in the LAKE…\pBut I thought GYARADOS were usually\nblue?$"

LakeOfRage_Eventscript_WesleyOfWednesday_Text_0:
	.string "WESLEY: Well, how do you do?\pSeeing as how it's WEDNESDAY today,\nI'm WESLEY of WEDNESDAY.\pPleased to meet you.\nPlease take a souvenir.$"

LakeOfRage_Eventscript_WesleyOfWednesday_Text_1:
	.string "WESLEY: Pleased to meet you.\nPlease take a souvenir.$"

LakeOfRage_Eventscript_WesleyOfWednesday_Text_2:
	.string "WESLEY: The BLACKBELT beefs up the\npower of FIGHTING-type moves.$"

LakeOfRage_Eventscript_WesleyOfWednesday_Text_3:
	.string "WESLEY: Today's not WEDNESDAY.\nThat's too bad.$"

LakeOfRage_Eventscript_WesleyOfWednesday_Text_4:
	.string "WESLEY: Since you found me, you must\nhave met my brothers and sisters.\pOr did you just get lucky?$"

LakeOfRage_Eventscript_CooltrainerAaron_Text_0:
	.string "If a TRAINER spots another TRAINER,\nhe has to make a challenge.\pThat is our destiny.$"

LakeOfRage_Eventscript_CooltrainerAaron_Text_1:
	.string "Whew…\nGood battle.$"

LakeOfRage_Eventscript_CooltrainerAaron_Text_2:
	.string "POKéMON and their TRAINER become\npowerful through constant battling.$"

LakeOfRage_Eventscript_CooltrainerLois_Text_0:
	.string "What happened to the red GYARADOS?\nIt's gone?\pOh, darn. I came here for nothing?\nI know--let's battle!$"

LakeOfRage_Eventscript_CooltrainerLois_Text_1:
	.string "Good going!$"

LakeOfRage_Eventscript_CooltrainerLois_Text_2:
	.string "Come to think of it, I've seen a\npink BUTTERFREE.$"

LakeOfRage_Eventscript_FishermanAndre_Text_0:
	.string "Let me battle with the POKéMON I\njust caught!$"

LakeOfRage_Eventscript_FishermanAndre_Text_1:
	.string "I might be an expert angler, but I\nstink as a POKéMON TRAINER…$"

LakeOfRage_Eventscript_FishermanAndre_Text_2:
	.string "I won't lose as an angler!\nI catch POKéMON all day.$"

LakeOfRage_Eventscript_FishermanRaymond_Text_0:
	.string "No matter what I do, all I catch are\nthe same POKéMON…$"

LakeOfRage_Eventscript_FishermanRaymond_Text_1:
	.string "My line's all tangled up…$"

LakeOfRage_Eventscript_FishermanRaymond_Text_2:
	.string "Why can't I catch any good POKéMON?$"
