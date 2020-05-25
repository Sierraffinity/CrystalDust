AzaleaTown_Gym_MapScripts::
	.byte 0


AzaleaTown_Gym_EventScript_Bugsy::
	trainerbattle_single TRAINER_BUGSY, AzaleaTown_Gym_Text_BugsyPreBattle, AzaleaTown_Gym_Text_BugsyDefeat, AzaleaTown_Gym_EventScript_BugsyDefeated, NO_MUSIC
	goto_if_unset FLAG_GOT_TM47_FROM_BUGSY, AzaleaTown_Gym_EventScript_Bugsy_2
AzaleaTown_Gym_EventScript_Bugsy_1:
	msgbox AzaleaTown_Gym_EventScript_Bugsy_Text_0
	release
	return

AzaleaTown_Gym_EventScript_Bugsy_2:
	goto AzaleaTown_Gym_EventScript_GiveSteelWing
	goto AzaleaTown_Gym_EventScript_Bugsy_1


AzaleaTown_Gym_EventScript_BugsyDefeated::
	textcolor MSG_COLOR_SYS
	message AzaleaTown_Gym_EventScript_BugsyDefeated_Text_0
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	call EventScript_RestorePrevTextColor
	setflag FLAG_DEFEATED_AZALEA_GYM
	setflag FLAG_BADGE02_GET
	set_gym_trainers 2
	goto AzaleaTown_Gym_EventScript_GiveSteelWing
	return


AzaleaTown_Gym_EventScript_GiveSteelWing::
	msgbox AzaleaTown_Gym_EventScript_GiveSteelWing_Text_0
	checkitemspace ITEM_TM47, 1
	compare VAR_RESULT, 0
	goto_if_eq AzaleaTown_Gym_EventScript_GiveSteelWing_2
	givetmhm_msg AzaleaTown_Gym_EventScript_GiveSteelWing_Text_1, ITEM_TM47
	setflag FLAG_GOT_TM47_FROM_BUGSY
	msgbox AzaleaTown_Gym_EventScript_GiveSteelWing_Text_2
AzaleaTown_Gym_EventScript_GiveSteelWing_1:
	release
	return

AzaleaTown_Gym_EventScript_GiveSteelWing_2:
	goto Common_EventScript_ShowBagIsFull
	goto AzaleaTown_Gym_EventScript_GiveSteelWing_1


AzaleaTown_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_AZALEA_GYM, AzaleaTown_Gym_EventScript_GymGuide_2
	msgbox AzaleaTown_Gym_EventScript_GymGuide_Text_1
AzaleaTown_Gym_EventScript_GymGuide_1:
	release
	return

AzaleaTown_Gym_EventScript_GymGuide_2:
	msgbox AzaleaTown_Gym_EventScript_GymGuide_Text_0
	goto AzaleaTown_Gym_EventScript_GymGuide_1


AzaleaTown_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE02_GET, AzaleaTown_Gym_EventScript_GymStatue_2
	msgbox AzaleaTown_Gym_EventScript_GymStatue_Text_1
AzaleaTown_Gym_EventScript_GymStatue_1:
	releaseall
	return

AzaleaTown_Gym_EventScript_GymStatue_2:
	msgbox AzaleaTown_Gym_EventScript_GymStatue_Text_0
	goto AzaleaTown_Gym_EventScript_GymStatue_1


AzaleaTown_Gym_EventScript_Benny::
	trainerbattle_single TRAINER_BENNY, AzaleaTown_Gym_Text_BennyIntro, AzaleaTown_Gym_Text_BennyDefeat
	msgbox AzaleaTown_Gym_Text_BennyPostBattle, MSGBOX_DEFAULT
	release
	return


AzaleaTown_Gym_EventScript_Al::
	trainerbattle_single TRAINER_AL, AzaleaTown_Gym_Text_AlIntro, AzaleaTown_Gym_Text_AlDefeat
	msgbox AzaleaTown_Gym_Text_AlPostBattle, MSGBOX_DEFAULT
	release
	return


AzaleaTown_Gym_EventScript_Josh::
	trainerbattle_single TRAINER_JOSH, AzaleaTown_Gym_Text_JoshIntro, AzaleaTown_Gym_Text_JoshDefeat
	msgbox AzaleaTown_Gym_Text_JoshPostBattle, MSGBOX_DEFAULT
	release
	return


AzaleaTown_Gym_EventScript_Amy::
	trainerbattle_double TRAINER_AMY_AND_MAY, AzaleaTown_Gym_Text_AmyIntro, AzaleaTown_Gym_Text_AmyAndMayDefeat, AzaleaTown_Gym_Text_AmyNotEnoughMons
	msgbox AzaleaTown_Gym_Text_AmyPostBattle, MSGBOX_DEFAULT
	release
	return


AzaleaTown_Gym_EventScript_May::
	trainerbattle_double TRAINER_AMY_AND_MAY, AzaleaTown_Gym_Text_MayIntro, AzaleaTown_Gym_Text_AmyAndMayDefeat, AzaleaTown_Gym_Text_MayNotEnoughMons
	msgbox AzaleaTown_Gym_Text_MayPostBattle, MSGBOX_DEFAULT
	release
	return


AzaleaTown_Gym_EventScript_Bugsy_Text_0:
	.string "BUG POKéMON are deep. There are\n"
	.string "many mysteries to be explored.\l"
	.string "Study your favorites thoroughly.$"

AzaleaTown_Gym_EventScript_BugsyDefeated_Text_0:
	.string "{PLAYER} received the HIVEBADGE\n"
	.string "from BUGSY.$"

AzaleaTown_Gym_EventScript_GiveSteelWing_Text_0:
	.string "Do you know the benefits of the\n"
	.string "HIVEBADGE?\p"
	.string "If you have it, POKéMON up to Lv.\n"
	.string "30 will obey you, even traded ones.\p"
	.string "POKéMON that know CUT will be able\n"
	.string "to use it outside of battle, too.\p"
	.string "Here, I also want you to have this.$"

AzaleaTown_Gym_EventScript_GiveSteelWing_Text_1:
	.string "{PLAYER} received TM47\n"
	.string "from BUGSY.$"

AzaleaTown_Gym_EventScript_GiveSteelWing_Text_2:
	.string "TM47 contains STEEL WING.\p"
	.string "After attacking, it has a one-in-ten\n"
	.string "chance of raising your DEFENSE.\l"
	.string "Isn't that great?$"

AzaleaTown_Gym_EventScript_GymGuide_Text_0:
	.string "Well done! That was a great clash\n"
	.string "of talented young TRAINERS.\p"
	.string "With people like you, the future of\n"
	.string "POKéMON is bright!$"

AzaleaTown_Gym_EventScript_GymGuide_Text_1:
	.string "Yo, challenger!\p"
	.string "BUGSY's young, but his knowledge of\n"
	.string "BUG POKéMON is for real.\p"
	.string "It's going to be tough without my\n"
	.string "advice. Let's see…\p"
	.string "BUG POKéMON can't stand being too\n"
	.string "close to fire.\p"
	.string "FLYING-type moves are super-\n"
	.string "effective too.$"

AzaleaTown_Gym_EventScript_GymStatue_Text_0:
	.string "AZALEA TOWN POKéMON GYM\n"
	.string "LEADER: BUGSY\p"
	.string "WINNING TRAINERS:\n"
	.string "{PLAYER}$"

AzaleaTown_Gym_EventScript_GymStatue_Text_1:
	.string "AZALEA TOWN POKéMON GYM$"

AzaleaTown_Gym_Text_BugsyPreBattle::
	.string "I'm BUGSY! I never lose when it\n"
	.string "comes to BUG POKéMON.\p"
	.string "My research is going to make me the\n"
	.string "authority on BUG POKéMON!\p"
	.string "Let me demonstrate what I've learned\n"
	.string "from my studies.$"

AzaleaTown_Gym_Text_BugsyDefeat::
	.string "Whoa, amazing!\n"
	.string "You're an expert on POKéMON!\l"
	.string "My research isn't complete yet.\p"
	.string "Okay, you win.\n"
	.string "Take this BADGE.$"
