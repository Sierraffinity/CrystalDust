SproutTower_3F_MapScripts::
	.byte 0


SproutTower_3F_EventScript_Painting::
	msgbox SproutTower_3F_EventScript_Painting_Text_0, MSGBOX_SIGN
	return


SproutTower_3F_EventScript_RivalScene::
	lockall
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	fadeoutbgm 0
	waitmovement 0
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 2
	setvar VAR_0x8006, 8
	setvar VAR_0x8007, 4
	special ShakeCamera
	waitstate
	delay 10
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 2
	setvar VAR_0x8006, 8
	setvar VAR_0x8007, 4
	special ShakeCamera
	waitstate
	applymovement OBJ_EVENT_ID_PLAYER, SproutTower_3F_Movement_PlayerToRival
	waitmovement 0
	applymovement 7, SproutTower_3F_Movement_RivalToSage
	waitmovement 0
	textcolor MSG_COLOR_BLUE
	msgbox SproutTower_3F_EventScript_RivalScene_Text_0
	closemessage
	playse SE_PIN
	applymovement 7, SproutTower_3F_Movement_RivalExclamationFaceSouth
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	playbgm MUS_ENCOUNTER_RIVAL, 0
	applymovement 7, SproutTower_3F_Movement_RivalToPlayer
	waitmovement 0
	msgbox SproutTower_3F_EventScript_RivalScene_Text_1
	applymovement 7, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	textcolor MSG_COLOR_PREV
	msgbox SproutTower_3F_EventScript_RivalScene_Text_2
	closemessage
	applymovement 7, SproutTower_3F_Movement_RivalSpin
	waitmovement 0
	playse SE_WARP_IN
	applymovement 7, SproutTower_3F_Movement_RivalFlyAway
	waitmovement 0
	removeobject 7
	fadedefaultbgm
	setvar VAR_SPROUT_TOWER_STATE, 1
	releaseall
	return


SproutTower_3F_EventScript_Elder::
	trainerbattle_single TRAINER_LI, SproutTower_3F_Text_Li_Prebattle, SproutTower_3F_Text_Li_Beat, SproutTower_3F_EventScript_Li_PostBattle, NO_MUSIC
	msgbox SproutTower_3F_EventScript_Elder_Text_0
	release
	return


SproutTower_3F_EventScript_Li_PostBattle::
	msgbox SproutTower_3F_EventScript_Li_PostBattle_Text_0
	givetmhm_msg SproutTower_3F_EventScript_Li_PostBattle_Text_1, ITEM_HM05
	setflag FLAG_RECEIVED_HM05
	msgbox SproutTower_3F_EventScript_Li_PostBattle_Text_2
	release
	return


SproutTower_3F_Movement_PlayerToRival:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

SproutTower_3F_Movement_RivalToSage:
	walk_up
	step_end

SproutTower_3F_Movement_RivalExclamationFaceSouth:
	emote_exclamation_mark
	walk_in_place_fastest_down
	step_end

SproutTower_3F_Movement_RivalToPlayer:
	walk_down
	walk_right
	walk_right
	walk_down
	step_end

SproutTower_3F_Movement_RivalSpin:
	face_up
	delay_4
	face_left
	delay_4
	face_down
	delay_4
	face_right
	delay_4
	step_end

SproutTower_3F_Movement_RivalFlyAway:
	face_up
	disable_anim
	slide_up
	slide_up
	slide_up
	slide_up
	slide_up
	slide_up
	step_end

SproutTower_3F_EventScript_SageJin::
	trainerbattle_single TRAINER_JIN, Trainer_Text_Jin_See, Trainer_Text_Jin_Beat
	msgbox Trainer_Text_Jin_After, MSGBOX_DEFAULT
	release
	return


SproutTower_3F_EventScript_SageTroy::
	trainerbattle_single TRAINER_TROY, Trainer_Text_Troy_See, Trainer_Text_Troy_Beat
	msgbox Trainer_Text_Troy_After, MSGBOX_DEFAULT
	release
	return


SproutTower_3F_EventScript_SageNeal::
	trainerbattle_single TRAINER_NEAL, Trainer_Text_Neal_See, Trainer_Text_Neal_Beat
	msgbox Trainer_Text_Neal_After, MSGBOX_DEFAULT
	release
	return


SproutTower_3F_EventScript_Painting_Text_0:
	.string "It's a powerful painting of a\n"
	.string "BELLSPROUT.$"

SproutTower_3F_EventScript_RivalScene_Text_0:
	.string "ELDER: You are indeed skilled as a\n"
	.string "TRAINER.\l"
	.string "As promised, here is your HM.\p"
	.string "But let me say this: You should\n"
	.string "treat your POKéMON better.\p"
	.string "The way you battle is far too harsh.\n"
	.string "POKéMON are not tools of war…$"

SproutTower_3F_EventScript_RivalScene_Text_1:
	.string "…\n"
	.string "…Humph!\p"
	.string "He claims to be the ELDER, but\n"
	.string "he's weak.\p"
	.string "It stands to reason.\p"
	.string "I'd never lose to fools who babble\n"
	.string "about being nice to POKéMON.\p"
	.string "I only care about strong POKéMON\n"
	.string "that can win.\p"
	.string "I really couldn't care less about\n"
	.string "weak POKéMON.$"

SproutTower_3F_EventScript_RivalScene_Text_2:
	.string "{RIVAL} used the\n"
	.string "ESCAPE ROPE.$"

SproutTower_3F_EventScript_Elder_Text_0:
	.string "I hope you learn and grow from\n"
	.string "your journey.$"

SproutTower_3F_EventScript_Li_PostBattle_Text_0:
	.string "You and your POKéMON should have\n"
	.string "no problem using this move.\l"
	.string "Take this FLASH HM.$"

SproutTower_3F_EventScript_Li_PostBattle_Text_1:
	.string "{PLAYER} received HM05\n"
	.string "from the ELDER.$"

SproutTower_3F_EventScript_Li_PostBattle_Text_2:
	.string "FLASH illuminates even the darkest\n"
	.string "of all places.\p"
	.string "But to use it out of battle, you\n"
	.string "need the BADGE from VIOLET's GYM.$"

SproutTower_3F_Text_Li_Prebattle::
	.string "So good of you to come here!\p"
	.string "SPROUT TOWER is a place of training\n"
	.string "and learning.\p"
	.string "Here, people and POKéMON test\n"
	.string "their bonds to build a bright\l"
	.string "future together.\p"
	.string "I am the final test.\p"
	.string "Allow me to check the ties between\n"
	.string "your POKéMON and you!$"

SproutTower_3F_Text_Li_Beat::
	.string "Ah, excellent!$"
