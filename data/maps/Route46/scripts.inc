Route46_MapScripts::
	.byte 0


Route46_EventScript_Bailey::
	trainerbattle_single TRAINER_BAILEY, Route46_Text_BaileyIntro, Route46_Text_BaileyDefeated
	msgbox Route46_Text_BaileyPostBattle, MSGBOX_AUTOCLOSE
	return


Route46_EventScript_Ted::
	trainerbattle_single TRAINER_TED, Route46_Text_TedIntro, Route46_Text_TedDefeated
	msgbox Route46_Text_TedPostBattle, MSGBOX_AUTOCLOSE
	return


Route46_EventScript_Erin::
	trainerbattle_single TRAINER_ERIN_1, Route46_Text_ErinIntro, Route46_Text_ErinDefeated
	msgbox Route46_Text_ErinPostBattle, MSGBOX_AUTOCLOSE
	return


Route46_EventScript_RouteSign::
	msgbox Route46_EventScript_RouteSign_Text_0, MSGBOX_SIGN
	return


Route46_EventScript_RouteSign_Text_0:
	.string "ROUTE 46\n"
	.string "MOUNTAIN ROAD AHEAD$"
