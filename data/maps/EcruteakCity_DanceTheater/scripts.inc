EcruteakCity_DanceTheater_MapScripts::
	.byte 0


EcruteakCity_DanceTheater_Eventscript_PanelSign::
	msgbox EcruteakCity_DanceTheater_Eventscript_PanelSign_Text_0, MSGBOX_SIGN
	end


EcruteakCity_DanceTheater_Eventscript_OldLady::
	msgbox EcruteakCity_DanceTheater_Eventscript_OldLady_Text_0, MSGBOX_NPC
	end


EcruteakCity_DanceTheater_Eventscript_Boy::
	msgbox EcruteakCity_DanceTheater_Eventscript_Boy_Text_0, MSGBOX_NPC
	end


EcruteakCity_DanceTheater_Eventscript_Rhydon::
	lock
	faceplayer
	playmoncry SPECIES_RHYDON, 0
	msgbox EcruteakCity_DanceTheater_Eventscript_Rhydon_Text_0, MSGBOX_DEFAULT
	waitmoncry
	release
	end


EcruteakCity_DanceTheater_Eventscript_Gentleman::
	lock
	faceplayer
	message EcruteakCity_DanceTheater_Eventscript_Gentleman_Text_0
	waitmessage
	checkitem ITEM_HM03, 1
	copyvar VAR_0x8008, VAR_RESULT
	checkpcitem ITEM_HM03, 1
	compare VAR_0x8008, TRUE
	goto_if_eq EcruteakCity_DanceTheater_Eventscript_Gentleman_2
	compare VAR_RESULT, TRUE
	goto_if_eq EcruteakCity_DanceTheater_Eventscript_Gentleman_2
	checktrainerflag TRAINER_NAOKO
	goto_if 1, EcruteakCity_DanceTheater_Eventscript_Gentleman_9
EcruteakCity_DanceTheater_Eventscript_Gentleman_6:
	msgbox EcruteakCity_DanceTheater_Eventscript_Gentleman_Text_5, MSGBOX_DEFAULT
	giveitem ITEM_HM03
	msgbox EcruteakCity_DanceTheater_Eventscript_Gentleman_Text_6, MSGBOX_NPC
	end

EcruteakCity_DanceTheater_Eventscript_Gentleman_2:
	msgbox EcruteakCity_DanceTheater_Eventscript_Gentleman_Text_1, MSGBOX_NPC
	end

EcruteakCity_DanceTheater_Eventscript_Gentleman_7:
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq EcruteakCity_DanceTheater_Eventscript_Gentleman_18
	bufferstring 1, EcruteakCity_DanceTheater_Eventscript_Gentleman_Text_3
EcruteakCity_DanceTheater_Eventscript_Gentleman_17:
	msgbox EcruteakCity_DanceTheater_Eventscript_Gentleman_Text_4, MSGBOX_NPC
	end

EcruteakCity_DanceTheater_Eventscript_Gentleman_8:
	checktrainerflag TRAINER_ZUKI
	goto_if 1, EcruteakCity_DanceTheater_Eventscript_Gentleman_13
	goto EcruteakCity_DanceTheater_Eventscript_Gentleman_6

EcruteakCity_DanceTheater_Eventscript_Gentleman_9:
	checktrainerflag TRAINER_SAYO
	goto_if 1, EcruteakCity_DanceTheater_Eventscript_Gentleman_8
	goto EcruteakCity_DanceTheater_Eventscript_Gentleman_6

EcruteakCity_DanceTheater_Eventscript_Gentleman_12:
	checktrainerflag TRAINER_MIKI
	goto_if 1, EcruteakCity_DanceTheater_Eventscript_Gentleman_7
	goto EcruteakCity_DanceTheater_Eventscript_Gentleman_6

EcruteakCity_DanceTheater_Eventscript_Gentleman_13:
	checktrainerflag TRAINER_KUNI
	goto_if 1, EcruteakCity_DanceTheater_Eventscript_Gentleman_12
	goto EcruteakCity_DanceTheater_Eventscript_Gentleman_6

EcruteakCity_DanceTheater_Eventscript_Gentleman_18:
	bufferstring 0, EcruteakCity_DanceTheater_Eventscript_Gentleman_Text_2
	goto EcruteakCity_DanceTheater_Eventscript_Gentleman_17


EcruteakCity_DanceTheater_Eventscript_KimonoGirlNaoko::
	trainerbattle_single TRAINER_NAOKO, EcruteakCity_DanceTheater_Eventscript_KimonoGirlNaoko_Text_0, EcruteakCity_DanceTheater_Eventscript_KimonoGirlNaoko_Text_1
	msgbox EcruteakCity_DanceTheater_Eventscript_KimonoGirlNaoko_Text_2, MSGBOX_NPC
	end


EcruteakCity_DanceTheater_Eventscript_KimonoGirlSayo::
	trainerbattle_single TRAINER_SAYO, EcruteakCity_DanceTheater_Eventscript_KimonoGirlSayo_Text_0, EcruteakCity_DanceTheater_Eventscript_KimonoGirlSayo_Text_1
	msgbox EcruteakCity_DanceTheater_Eventscript_KimonoGirlSayo_Text_2, MSGBOX_NPC
	end


EcruteakCity_DanceTheater_Eventscript_KimonoGirlZuki::
	trainerbattle_single TRAINER_ZUKI, EcruteakCity_DanceTheater_Eventscript_KimonoGirlZuki_Text_0, EcruteakCity_DanceTheater_Eventscript_KimonoGirlZuki_Text_1
	msgbox EcruteakCity_DanceTheater_Eventscript_KimonoGirlZuki_Text_2, MSGBOX_NPC
	end


EcruteakCity_DanceTheater_Eventscript_KimonoGirlKuni::
	trainerbattle_single TRAINER_KUNI, EcruteakCity_DanceTheater_Eventscript_KimonoGirlKuni_Text_0, EcruteakCity_DanceTheater_Eventscript_KimonoGirlKuni_Text_1
	msgbox EcruteakCity_DanceTheater_Eventscript_KimonoGirlKuni_Text_2, MSGBOX_NPC
	end


EcruteakCity_DanceTheater_Eventscript_KimonoGirlMiki::
	trainerbattle_single TRAINER_MIKI, EcruteakCity_DanceTheater_Eventscript_KimonoGirlMiki_Text_0, EcruteakCity_DanceTheater_Eventscript_KimonoGirlMiki_Text_1
	msgbox EcruteakCity_DanceTheater_Eventscript_KimonoGirlMiki_Text_2, MSGBOX_NPC
	end


EcruteakCity_DanceTheater_Eventscript_PanelSign_Text_0:
	.string "It's a fancy panel that's decorated\nwith flowers.$"

EcruteakCity_DanceTheater_Eventscript_OldLady_Text_0:
	.string "The KIMONO GIRLS are so beautiful…\nBut they have to go through rigorous\ltraining.\pAnd they have to learn to follow\ncustoms before appearing in public.\pBut if you love something, anything\nis possible.$"

EcruteakCity_DanceTheater_Eventscript_Boy_Text_0:
	.string "That man's always with his RHYDON.\nSays he wants a POKéMON that can\lSURF and dance.\pIs he trying to make a synchronized\nswimming POKéMON?$"

EcruteakCity_DanceTheater_Eventscript_Rhydon_Text_0:
	.string "RHYDON: Gugooh gugogooh!$"

EcruteakCity_DanceTheater_Eventscript_Gentleman_Text_0:
	.string "Not only are the KIMONO GIRLS great\ndancers, they're also skilled at\lPOKéMON.\pI always challenge them, but I've\nnever even left a scratch…\p$"

EcruteakCity_DanceTheater_Eventscript_Gentleman_Text_1:
	.string "I wish my POKéMON were as elegant as\nthe KIMONO GIRLS…$"

EcruteakCity_DanceTheater_Eventscript_Gentleman_Text_2:
	.string "Lad$"

EcruteakCity_DanceTheater_Eventscript_Gentleman_Text_3:
	.string "Lassie$"

EcruteakCity_DanceTheater_Eventscript_Gentleman_Text_4:
	.string "{STR_VAR_1}, if you can defeat all the\nKIMONO GIRLS, I'll give you a gift.$"

EcruteakCity_DanceTheater_Eventscript_Gentleman_Text_5:
	.string "The way you battled, it was like\nwatching a dance.\pIt was a rare treat to see!\pI want you to have this.\nDon't worry--take it!$"

EcruteakCity_DanceTheater_Eventscript_Gentleman_Text_6:
	.string "That's SURF. It's a move that lets\nPOKéMON swim across water.$"

EcruteakCity_DanceTheater_Eventscript_KimonoGirlNaoko_Text_0:
	.string "You have lovely POKéMON.\nMay I see them in battle?$"

EcruteakCity_DanceTheater_Eventscript_KimonoGirlNaoko_Text_1:
	.string "Oh, you are very strong.$"

EcruteakCity_DanceTheater_Eventscript_KimonoGirlNaoko_Text_2:
	.string "I enjoyed that bout.\nI would like to see you again.$"

EcruteakCity_DanceTheater_Eventscript_KimonoGirlSayo_Text_0:
	.string "I always dance with my POKéMON.\nOf course, I also train them.$"

EcruteakCity_DanceTheater_Eventscript_KimonoGirlSayo_Text_1:
	.string "Oh, so close!\nI almost had you.$"

EcruteakCity_DanceTheater_Eventscript_KimonoGirlSayo_Text_2:
	.string "Rhythm is important for both dancing\nand POKéMON.$"

EcruteakCity_DanceTheater_Eventscript_KimonoGirlZuki_Text_0:
	.string "Isn't my barrette pretty?\nOh. A POKéMON battle?$"

EcruteakCity_DanceTheater_Eventscript_KimonoGirlZuki_Text_1:
	.string "I don't have any POKéMON left…$"

EcruteakCity_DanceTheater_Eventscript_KimonoGirlZuki_Text_2:
	.string "I put a different flower in my\nbarrette every month.$"

EcruteakCity_DanceTheater_Eventscript_KimonoGirlKuni_Text_0:
	.string "Oh, you're a cute TRAINER.\nWould you like to battle?$"

EcruteakCity_DanceTheater_Eventscript_KimonoGirlKuni_Text_1:
	.string "You're stronger than you look.$"

EcruteakCity_DanceTheater_Eventscript_KimonoGirlKuni_Text_2:
	.string "I trained a lot, so I thought I was\na capable TRAINER. I guess I'm not.$"

EcruteakCity_DanceTheater_Eventscript_KimonoGirlMiki_Text_0:
	.string "Do you like my dancing?\nI'm good at POKéMON too.$"

EcruteakCity_DanceTheater_Eventscript_KimonoGirlMiki_Text_1:
	.string "Ooh, you're good at POKéMON too.$"

EcruteakCity_DanceTheater_Eventscript_KimonoGirlMiki_Text_2:
	.string "I can keep dancing because there are\npeople who enjoy what I do.\pMy POKéMON keep my spirits up too.$"
