VioletCity_Gym_MapScripts::
	.byte 0


VioletCity_Gym_EventScript_Falkner::
	trainerbattle_single TRAINER_FALKNER, VioletCity_Gym_Text_FalknerPreBattle, VioletCity_Gym_Text_FalknerDefeat, VioletCity_Gym_EventScript_FalknerDefeated, NO_MUSIC
	goto_if_unset FLAG_GOT_TM40_FROM_FALKNER, VioletCity_Gym_EventScript_Falkner_2
VioletCity_Gym_EventScript_Falkner_1:
	msgbox VioletCity_Gym_EventScript_Falkner_Text_0
	release
	return

VioletCity_Gym_EventScript_Falkner_2:
	goto VioletCity_Gym_EventScript_GiveAerialAce
	goto VioletCity_Gym_EventScript_Falkner_1


VioletCity_Gym_EventScript_FalknerDefeated::
	textcolor MSG_COLOR_MISC
	message VioletCity_Gym_EventScript_FalknerDefeated_Text_0
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	call Common_RestoreOriginalTextColor
	setflag FLAG_DEFEATED_VIOLET_GYM
	setflag FLAG_BADGE01_GET
	setvar VAR_VIOLET_CITY_STATE, 1
	set_gym_trainers 1
	goto VioletCity_Gym_EventScript_GiveAerialAce
	return


VioletCity_Gym_EventScript_GiveAerialAce::
	msgbox VioletCity_Gym_EventScript_GiveAerialAce_Text_0
	checkitemspace ITEM_TM40, 1
	compare VAR_RESULT, 0
	goto_if_eq VioletCity_Gym_EventScript_GiveAerialAce_2
	givetmhm_msg VioletCity_Gym_EventScript_GiveAerialAce_Text_2, ITEM_TM40
	setflag FLAG_GOT_TM40_FROM_FALKNER
	msgbox VioletCity_Gym_EventScript_GiveAerialAce_Text_3
VioletCity_Gym_EventScript_GiveAerialAce_1:
	release
	return

VioletCity_Gym_EventScript_GiveAerialAce_2:
	msgbox VioletCity_Gym_EventScript_GiveAerialAce_Text_1
	goto VioletCity_Gym_EventScript_GiveAerialAce_1


VioletCity_Gym_EventScript_Abe::
	trainerbattle_single TRAINER_ABE, VioletCity_Gym_Text_AbeIntro, VioletCity_Gym_Text_AbeDefeat
	msgbox VioletCity_Gym_Text_AbePostBattle, MSGBOX_DEFAULT
	release
	return


VioletCity_Gym_EventScript_Rod::
	trainerbattle_single TRAINER_ROD, VioletCity_Gym_Text_RodIntro, VioletCity_Gym_Text_RodDefeat
	msgbox VioletCity_Gym_Text_RodPostBattle, MSGBOX_DEFAULT
	release
	return


VioletCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE01_GET, VioletCity_Gym_EventScript_GymStatue_2
	msgbox VioletCity_Gym_EventScript_GymStatue_Text_1
VioletCity_Gym_EventScript_GymStatue_1:
	releaseall
	return

VioletCity_Gym_EventScript_GymStatue_2:
	msgbox VioletCity_Gym_EventScript_GymStatue_Text_0
	goto VioletCity_Gym_EventScript_GymStatue_1


VioletCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_VIOLET_GYM, VioletCity_Gym_EventScript_GymGuide_2
	msgbox VioletCity_Gym_EventScript_GymGuide_Text_1
VioletCity_Gym_EventScript_GymGuide_1:
	release
	return

VioletCity_Gym_EventScript_GymGuide_2:
	msgbox VioletCity_Gym_EventScript_GymGuide_Text_0
	goto VioletCity_Gym_EventScript_GymGuide_1


VioletCity_Gym_EventScript_Falkner_Text_0:
	.string "There are POKéMON GYMS in cities\n"
	.string "and towns ahead.\p"
	.string "You should test your skills at\n"
	.string "these GYMS.\p"
	.string "I'm going to train harder to become\n"
	.string "the greatest bird master!$"

VioletCity_Gym_EventScript_FalknerDefeated_Text_0:
	.string "{PLAYER} received the ZEPHYRBADGE\n"
	.string "from FALKNER.$"

VioletCity_Gym_EventScript_GiveAerialAce_Text_0:
	.string "The ZEPHYRBADGE raises the ATTACK\n"
	.string "power of POKéMON.\p"
	.string "It also enables POKéMON to use\n"
	.string "FLASH, if they have it, anytime.\p"
	.string "Here--take this too.$"

VioletCity_Gym_EventScript_GiveAerialAce_Text_1:
	.string "It seems you don't have room\n"
	.string "for this.$"

VioletCity_Gym_EventScript_GiveAerialAce_Text_2:
	.string "{PLAYER} received TM40\n"
	.string "from FALKNER.$"

VioletCity_Gym_EventScript_GiveAerialAce_Text_3:
	.string "By using a TM, a POKéMON will\n"
	.string "instantly learn a new move.\p"
	.string "Think before you act--a TM can\n"
	.string "be used only once.\p"
	.string "TM40 contains AERIAL ACE.\p"
	.string "It lets you attack with unparalleled\n"
	.string "speed and precision.\p"
	.string "In other words, it never misses.$"

VioletCity_Gym_EventScript_GymStatue_Text_0:
	.string "VIOLET POKéMON GYM\n"
	.string "LEADER: FALKNER\p"
	.string "WINNING TRAINERS:\n"
	.string "{PLAYER}$"

VioletCity_Gym_EventScript_GymStatue_Text_1:
	.string "VIOLET POKéMON GYM$"

VioletCity_Gym_EventScript_GymGuide_Text_0:
	.string "Nice battle! Keep it up, and you'll\n"
	.string "be the CHAMP in no time at all!$"

VioletCity_Gym_EventScript_GymGuide_Text_1:
	.string "Hey! I'm no TRAINER, but I can\n"
	.string "give some advice!\p"
	.string "Believe me!\n"
	.string "If you believe, a championship\l"
	.string "dream can come true.\p"
	.string "You believe?\n"
	.string "Then listen.\p"
	.string "GRASS-type POKéMON are weak\n"
	.string "against FLYING-type POKéMON.\l"
	.string "Keep this in mind.$"

VioletCity_Gym_Text_FalknerPreBattle::
	.string "I'm FALKNER, the VIOLET CITY\n"
	.string "POKéMON GYM LEADER!\p"
	.string "People say you can clip FLYING-\n"
	.string "type POKéMON's wings with a jolt\l"
	.string "of electricity…\p"
	.string "I won't allow such insults to\n"
	.string "bird POKéMON!\p"
	.string "I'll show you the real power of\n"
	.string "the magnificent bird POKéMON!$"

VioletCity_Gym_Text_FalknerDefeat::
	.string "…Darn! My dad's cherished bird\n"
	.string "POKéMON…\p"
	.string "All right.\n"
	.string "Take this.\p"
	.string "It's the official POKéMON LEAGUE\n"
	.string "ZEPHYRBADGE.$"
