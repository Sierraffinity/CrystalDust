Route35_MapScripts::
	.byte 0


Route35_EventScript_Ivan::
	trainerbattle_single TRAINER_IVAN, Route35_Text_IvanIntro, Route35_Text_IvanDefeated
	msgbox Route35_Text_IvanPostBattle, MSGBOX_AUTOCLOSE
	return


Route35_EventScript_Elliot::
	trainerbattle_single TRAINER_ELLIOT, Route35_Text_ElliotIntro, Route35_Text_ElliotDefeated
	msgbox Route35_Text_ElliotPostBattle, MSGBOX_AUTOCLOSE
	return


Route35_EventScript_Brooke::
	trainerbattle_single TRAINER_BROOKE, Route35_Text_BrookeIntro, Route35_Text_BrookeDefeated
	msgbox Route35_Text_BrookePostBattle, MSGBOX_AUTOCLOSE
	return


Route35_EventScript_Kim::
	trainerbattle_single TRAINER_KIM, Route35_Text_KimIntro, Route35_Text_KimDefeated
	msgbox Route35_Text_KimPostBattle, MSGBOX_AUTOCLOSE
	return


Route35_EventScript_Bryan::
	trainerbattle_single TRAINER_BRYAN, Route35_Text_BryanIntro, Route35_Text_BryanDefeated
	msgbox Route35_Text_BryanPostBattle, MSGBOX_AUTOCLOSE
	return


Route35_EventScript_Walt::
	trainerbattle_single TRAINER_WALT, Route35_Text_WaltIntro, Route35_Text_WaltDefeated
	msgbox Route35_Text_WaltPostBattle, MSGBOX_AUTOCLOSE
	return


Route35_EventScript_Arnie::
	trainerbattle_single TRAINER_ARNIE, Route35_Text_ArnieIntro, Route35_Text_ArnieDefeated
	msgbox Route35_Text_ArniePostBattle, MSGBOX_AUTOCLOSE
	return


Route35_EventScript_Irwin::
	trainerbattle_single TRAINER_IRWIN, Route35_Text_IrwinIntro, Route35_Text_IrwinDefeated
	msgbox Route35_Text_IrwinPostBattle, MSGBOX_AUTOCLOSE
	return


Route35_EventScript_Dirk::
	lock
	faceplayer
	gettime
	compare VAR_0x8002, TIME_NIGHT
	goto_if_eq Route35_EventScript_Dirk_2
	msgbox Route35_EventScript_Dirk_Text_0
Route35_EventScript_Dirk_1:
	release
	return

Route35_EventScript_Dirk_2:
	trainerbattle_single TRAINER_DIRK, Route35_Text_DirkIntro, Route35_Text_DirkDefeated
	msgbox Route35_Text_DirkPostBattle
	goto Route35_EventScript_Dirk_1


Route35_EventScript_RouteSign::
	msgbox Route35_EventScript_RouteSign_Text_0, MSGBOX_SIGN
	return


Route35_EventScript_Dirk_Text_0:
	.string "Your POKéMON look pretty tough.\n"
	.string "You could go anywhere safely.$"

Route35_EventScript_RouteSign_Text_0:
	.string "ROUTE 35$"
