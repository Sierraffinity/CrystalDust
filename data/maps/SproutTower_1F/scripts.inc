SproutTower_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SproutTower_1F_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

SproutTower_1F_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	setflag FLAG_LANDMARK_SPROUT_TOWER
	return


SproutTower_1F_EventScript_SageHM::
	msgbox SproutTower_1F_EventScript_SageHM_Text_0, MSGBOX_NPC
	return


SproutTower_1F_EventScript_SageHistorian::
	msgbox SproutTower_1F_EventScript_SageHistorian_Text_0, MSGBOX_NPC
	return


SproutTower_1F_EventScript_OldWoman::
	msgbox SproutTower_1F_EventScript_OldWoman_Text_0, MSGBOX_NPC
	return


SproutTower_1F_EventScript_Woman::
	msgbox SproutTower_1F_EventScript_Woman_Text_0, MSGBOX_NPC
	return


SproutTower_1F_EventScript_SageChow::
	trainerbattle_single TRAINER_CHOW, Trainer_Text_Chow_See, Trainer_Text_Chow_Beat
	msgbox Trainer_Text_Chow_After, MSGBOX_DEFAULT
	release
	return


SproutTower_1F_EventScript_SageHM_Text_0:
	.string "Only if you reach the top will you\n"
	.string "obtain an HM.$"

SproutTower_1F_EventScript_SageHistorian_Text_0:
	.string "SPROUT TOWER was built long ago\n"
	.string "as a place for POKéMON training.$"

SproutTower_1F_EventScript_OldWoman_Text_0:
	.string "A BELLSPROUT over a hundred feet\n"
	.string "tall…\p"
	.string "People say that it became the center\n"
	.string "pillar here.$"

SproutTower_1F_EventScript_Woman_Text_0:
	.string "See the pillar shaking?\n"
	.string "People are training upstairs.$"
