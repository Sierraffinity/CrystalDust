GoldenrodCity_Gym_MapScripts::
	.byte 0


GoldenrodCity_Gym_EventScript_Whitney::
	trainerbattle_single TRAINER_WHITNEY, GoldenrodCity_Gym_Text_WhitneyPreBattle, GoldenrodCity_Gym_Text_WhitneyDefeat, GoldenrodCity_Gym_EventScript_WhitneyDefeated, NO_MUSIC
	compare VAR_GOLDENROD_GYM_STATE, 2
	goto_if_lt GoldenrodCity_Gym_EventScript_Whitney_2
	goto_if_unset FLAG_BADGE03_GET, GoldenrodCity_Gym_EventScript_Whitney_3
	goto_if_unset FLAG_GOT_TM45_FROM_WHITNEY, GoldenrodCity_Gym_EventScript_Whitney_4
GoldenrodCity_Gym_EventScript_Whitney_1:
	msgbox GoldenrodCity_Gym_EventScript_Whitney_Text_2
	release
	return

GoldenrodCity_Gym_EventScript_Whitney_2:
	goto GoldenrodCity_Gym_EventScript_WhitneyCrying
	goto GoldenrodCity_Gym_EventScript_Whitney_1

GoldenrodCity_Gym_EventScript_Whitney_3:
	msgbox GoldenrodCity_Gym_EventScript_Whitney_Text_0
	textcolor MSG_COLOR_SYS
	message GoldenrodCity_Gym_EventScript_Whitney_Text_1
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	call EventScript_RestorePrevTextColor
	setflag FLAG_BADGE03_GET
	goto GoldenrodCity_Gym_EventScript_GiveAttract
	goto GoldenrodCity_Gym_EventScript_Whitney_1

GoldenrodCity_Gym_EventScript_Whitney_4:
	goto GoldenrodCity_Gym_EventScript_GiveAttract
	goto GoldenrodCity_Gym_EventScript_Whitney_1


GoldenrodCity_Gym_EventScript_WhitneyDefeated::
	setvar VAR_GOLDENROD_GYM_STATE, 1
	setflag FLAG_DEFEATED_GOLDENROD_GYM
	setgymtrainers 3
	goto GoldenrodCity_Gym_EventScript_WhitneyCrying
	return


GoldenrodCity_Gym_EventScript_WhitneyCrying::
	msgbox GoldenrodCity_Gym_EventScript_WhitneyCrying_Text_0
	release
	return


GoldenrodCity_Gym_EventScript_WhitneyCries::
	lockall
	playse SE_PIN
	applymovement 3, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	applymovement 3, GoldenrodCity_Gym_Movement_BridgetToPlayer
	waitmovement 0
	textcolor MSG_COLOR_RED
	msgbox GoldenrodCity_Gym_EventScript_WhitneyCries_Text_0
	closemessage
	applymovement 3, GoldenrodCity_Gym_Movement_BridgetReturns
	waitmovement 0
	setvar VAR_GOLDENROD_GYM_STATE, 2
	releaseall
	return


GoldenrodCity_Gym_Movement_BridgetToPlayer:
	walk_left
	face_up
	step_end

GoldenrodCity_Gym_Movement_BridgetReturns:
	walk_right
	face_left
	step_end

GoldenrodCity_Gym_EventScript_GiveAttract::
	msgbox GoldenrodCity_Gym_EventScript_GiveAttract_Text_0
	checkitemspace ITEM_TM45, 1
	compare VAR_RESULT, 0
	goto_if_eq GoldenrodCity_Gym_EventScript_GiveAttract_2
	givetmhm_msg GoldenrodCity_Gym_EventScript_GiveAttract_Text_1, ITEM_TM45
	setflag FLAG_GOT_TM45_FROM_WHITNEY
	msgbox GoldenrodCity_Gym_EventScript_GiveAttract_Text_2
GoldenrodCity_Gym_EventScript_GiveAttract_1:
	release
	return

GoldenrodCity_Gym_EventScript_GiveAttract_2:
	goto Common_EventScript_ShowBagIsFull
	goto GoldenrodCity_Gym_EventScript_GiveAttract_1


GoldenrodCity_Gym_EventScript_Guide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_GOLDENROD_GYM, GoldenrodCity_Gym_EventScript_Guide_2
	msgbox GoldenrodCity_Gym_EventScript_Guide_Text_1
GoldenrodCity_Gym_EventScript_Guide_1:
	release
	return

GoldenrodCity_Gym_EventScript_Guide_2:
	msgbox GoldenrodCity_Gym_EventScript_Guide_Text_0
	goto GoldenrodCity_Gym_EventScript_Guide_1


GoldenrodCity_Gym_EventScript_Statue::
	lock
	faceplayer
	goto_if_set FLAG_BADGE03_GET, GoldenrodCity_Gym_EventScript_Statue_2
	msgbox GoldenrodCity_Gym_EventScript_Statue_Text_1
GoldenrodCity_Gym_EventScript_Statue_1:
	release
	return

GoldenrodCity_Gym_EventScript_Statue_2:
	msgbox GoldenrodCity_Gym_EventScript_Statue_Text_0
	goto GoldenrodCity_Gym_EventScript_Statue_1


GoldenrodCity_Gym_EventScript_Carrie::
	trainerbattle_single TRAINER_CARRIE, GoldenrodCity_Gym_Text_CarrieIntro, GoldenrodCity_Gym_Text_CarrieDefeated
	msgbox GoldenrodCity_Gym_Text_CarriePostBattle, MSGBOX_AUTOCLOSE
	return


GoldenrodCity_Gym_EventScript_Bridget::
	trainerbattle_single TRAINER_BRIDGET, GoldenrodCity_Gym_Text_BridgetIntro, GoldenrodCity_Gym_Text_BridgetDefeated
	msgbox GoldenrodCity_Gym_Text_BridgetPostBattle, MSGBOX_AUTOCLOSE
	return


GoldenrodCity_Gym_EventScript_Victoria::
	trainerbattle_single TRAINER_VICTORIA, GoldenrodCity_Gym_Text_VictoriaIntro, GoldenrodCity_Gym_Text_VictoriaDefeated
	msgbox GoldenrodCity_Gym_Text_VictoriaPostBattle, MSGBOX_AUTOCLOSE
	return


GoldenrodCity_Gym_EventScript_Samantha::
	trainerbattle_single TRAINER_SAMANTHA, GoldenrodCity_Gym_Text_SamanthaIntro, GoldenrodCity_Gym_Text_SamanthaDefeated
	msgbox GoldenrodCity_Gym_Text_SamanthaPostBattle, MSGBOX_AUTOCLOSE
	return


GoldenrodCity_Gym_EventScript_Whitney_Text_0:
	.string "…Sniff…\p"
	.string "What? What do you want?\n"
	.string "A BADGE?\p"
	.string "Oh, right. I forgot.\n"
	.string "Here's the PLAINBADGE.$"

GoldenrodCity_Gym_EventScript_Whitney_Text_1:
	.string "{PLAYER} received the PLAINBADGE\n"
	.string "from WHITNEY.$"

GoldenrodCity_Gym_EventScript_Whitney_Text_2:
	.string "Ah, that was a good cry!\p"
	.string "Come for a visit again!\n"
	.string "Bye-bye!$"

GoldenrodCity_Gym_EventScript_WhitneyCrying_Text_0:
	.string "Waaaaah!\p"
	.string "Waaaaah!\p"
	.string "…Snivel, hic…\n"
	.string "…You meanie!$"

GoldenrodCity_Gym_EventScript_WhitneyCries_Text_0:
	.string "Oh, no.\n"
	.string "You made WHITNEY cry.\p"
	.string "It's okay.\n"
	.string "She'll stop soon.\l"
	.string "She always cries when she loses.$"

GoldenrodCity_Gym_EventScript_GiveAttract_Text_0:
	.string "The PLAINBADGE lets your POKéMON\n"
	.string "use STRENGTH outside of battle.\p"
	.string "It also boosts your POKéMON's\n"
	.string "SPEED.\p"
	.string "Oh, you can have this too!$"

GoldenrodCity_Gym_EventScript_GiveAttract_Text_1:
	.string "{PLAYER} received TM45\n"
	.string "from WHITNEY.$"

GoldenrodCity_Gym_EventScript_GiveAttract_Text_2:
	.string "It's ATTRACT! It makes full use\n"
	.string "of a POKéMON's charm.\p"
	.string "Isn't it just perfect for a cutie\n"
	.string "like me?$"

GoldenrodCity_Gym_EventScript_Guide_Text_0:
	.string "You won? Great!\n"
	.string "I was busy admiring the ladies here.$"

GoldenrodCity_Gym_EventScript_Guide_Text_1:
	.string "Yo!\n"
	.string "Champ in the making!\p"
	.string "This GYM is home to NORMAL-type\n"
	.string "POKéMON TRAINERS.\p"
	.string "I recommend you use FIGHTING-type\n"
	.string "POKéMON.$"

GoldenrodCity_Gym_EventScript_Statue_Text_0:
	.string "GOLDENROD CITY POKéMON GYM\n"
	.string "LEADER: WHITNEY\p"
	.string "WINNING TRAINERS:\n"
	.string "{PLAYER}$"

GoldenrodCity_Gym_EventScript_Statue_Text_1:
	.string "GOLDENROD CITY POKéMON GYM$"

GoldenrodCity_Gym_Text_WhitneyPreBattle::
	.string "Hi!\n"
	.string "I'm WHITNEY!\p"
	.string "Everyone was into POKéMON, so I got\n"
	.string "into it too!\p"
	.string "POKéMON are super-cute!\p"
	.string "You want to battle?\n"
	.string "I'm warning you--I'm good!$"

GoldenrodCity_Gym_Text_WhitneyDefeat::
	.string "Sob…\p"
	.string "…Waaaaaaah!\n"
	.string "You're mean!\p"
	.string "You shouldn't be so serious!\n"
	.string "You… you child, you!$"
