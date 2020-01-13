SproutTower_2F_MapScripts::
	.byte 0


SproutTower_2F_EventScript_SageNico::
	trainerbattle_single TRAINER_NICO, Trainer_Text_Nico_See, Trainer_Text_Nico_Beat
	msgbox Trainer_Text_Nico_After, MSGBOX_DEFAULT
	release
	return

