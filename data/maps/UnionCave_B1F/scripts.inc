UnionCave_B1F_MapScripts::
	.byte 0


UnionCave_B1F_EventScript_Phillip::
	trainerbattle_single TRAINER_PHILLIP, UnionCave_B1F_Text_PhillipIntro, UnionCave_B1F_Text_PhillipDefeat
	msgbox UnionCave_B1F_Text_PhillipPostBattle, MSGBOX_DEFAULT
	release
	return


UnionCave_B1F_EventScript_Leonard::
	trainerbattle_single TRAINER_LEONARD, UnionCave_B1F_Text_LeonardIntro, UnionCave_B1F_Text_LeonardDefeat
	msgbox UnionCave_B1F_Text_LeonardPostBattle, MSGBOX_DEFAULT
	release
	return


UnionCave_B1F_EventScript_Andrew::
	trainerbattle_single TRAINER_ANDREW, UnionCave_B1F_Text_AndrewIntro, UnionCave_B1F_Text_AndrewDefeat
	msgbox UnionCave_B1F_Text_AndrewPostBattle, MSGBOX_DEFAULT
	release
	return


UnionCave_B1F_EventScript_Calvin::
	trainerbattle_single TRAINER_CALVIN, UnionCave_B1F_Text_CalvinIntro, UnionCave_B1F_Text_CalvinDefeat
	msgbox UnionCave_B1F_Text_CalvinPostBattle, MSGBOX_DEFAULT
	release
	return

