Route34_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route34_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

Route34_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	goto_if_set FLAG_PENDING_DAYCARE_EGG, Route34_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	setflag FLAG_HIDE_ROUTE_34_DAYCARE_MAN_OUTSIDE
	return

Route34_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
	clearflag FLAG_HIDE_ROUTE_34_DAYCARE_MAN_OUTSIDE
	return


Route34_EventScript_Todd::
	trainerbattle_single TRAINER_TODD, Route34_Text_ToddIntro, Route34_Text_ToddDefeated
	msgbox Route34_Text_ToddPostBattle, MSGBOX_AUTOCLOSE
	return


Route34_EventScript_Samuel::
	trainerbattle_single TRAINER_SAMUEL, Route34_Text_SamuelIntro, Route34_Text_SamuelDefeated
	msgbox Route34_Text_SamuelPostBattle, MSGBOX_AUTOCLOSE
	return


Route34_EventScript_Ian::
	trainerbattle_single TRAINER_IAN, Route34_Text_IanIntro, Route34_Text_IanDefeated
	msgbox Route34_Text_IanPostBattle, MSGBOX_AUTOCLOSE
	return


Route34_EventScript_Gina::
	trainerbattle_single TRAINER_GINA, Route34_Text_GinaIntro, Route34_Text_GinaDefeated
	msgbox Route34_Text_GinaPostBattle, MSGBOX_AUTOCLOSE
	return


Route34_EventScript_Keith::
	lock
	faceplayer
	gettime
	compare VAR_0x8002, TIME_NIGHT
	goto_if_eq Route34_EventScript_Keith_2
	msgbox Route34_EventScript_Keith_Text_0
Route34_EventScript_Keith_1:
	release
	return

Route34_EventScript_Keith_2:
	trainerbattle_single TRAINER_KEITH, Route34_Text_KeithIntro, Route34_Text_KeithDefeated
	msgbox Route34_Text_KeithPostBattle
	goto Route34_EventScript_Keith_1


Route34_EventScript_Brandon::
	trainerbattle_single TRAINER_BRANDON, Route34_Text_BrandonIntro, Route34_Text_BrandonDefeated
	msgbox Route34_Text_BrandonPostBattle, MSGBOX_AUTOCLOSE
	return


Route34_EventScript_Irene::
	trainerbattle_single TRAINER_IRENE, Route34_Text_IreneIntro, Route34_Text_IreneDefeated
	checktrainerflag TRAINER_KATE
	goto_if 0, Route34_EventScript_Irene_2
	msgbox Route34_Text_IrenePostBattle
Route34_EventScript_Irene_1:
	release
	return

Route34_EventScript_Irene_2:
	msgbox Route34_EventScript_Irene_Text_0
	goto Route34_EventScript_Irene_1


Route34_EventScript_Jenn::
	trainerbattle_single TRAINER_JENN, Route34_Text_JennIntro, Route34_Text_JennDefeated
	checktrainerflag TRAINER_KATE
	goto_if 0, Route34_EventScript_Jenn_2
	msgbox Route34_Text_JennPostBattle
Route34_EventScript_Jenn_1:
	release
	return

Route34_EventScript_Jenn_2:
	msgbox Route34_EventScript_Jenn_Text_0
	goto Route34_EventScript_Jenn_1


Route34_EventScript_Kate::
	trainerbattle_single TRAINER_KATE, Route34_Text_KateIntro, Route34_Text_KateDefeated
	goto_if_unset FLAG_RECEIVED_SOFT_SAND_FROM_KATE, Route34_EventScript_Kate_2
Route34_EventScript_Kate_1:
	msgbox Route34_Text_KatePostBattle, MSGBOX_AUTOCLOSE
	return

Route34_EventScript_Kate_2:
	msgbox Route34_EventScript_Kate_Text_0
	giveitem ITEM_SOFT_SAND
	compare VAR_RESULT, 0
	goto_if_eq Route34_EventScript_Kate_5
Route34_EventScript_Kate_4:
	setflag FLAG_RECEIVED_SOFT_SAND_FROM_KATE
	goto Route34_EventScript_Kate_1

Route34_EventScript_Kate_5:
	goto Common_EventScript_ShowBagIsFull
	goto Route34_EventScript_Kate_4


Route34_EventScript_DirectionsSign::
	msgbox Route34_EventScript_DirectionsSign_Text_0, MSGBOX_SIGN
	return


Route34_EventScript_TrainerTipsSign::
	msgbox Route34_EventScript_TrainerTipsSign_Text_0, MSGBOX_SIGN
	return


Route34_EventScript_DaycareSign::
	msgbox Route34_EventScript_DaycareSign_Text_0, MSGBOX_SIGN
	return


Route34_EventScript_Douglas:: @ 81EE493
	trainerbattle_single TRAINER_DOUGLAS, Route34_Text_DouglasIntro, Route34_Text_DouglasDefeated
	msgbox Route34_Text_DouglasPostBattle, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_Kyla:: @ 81EE4AA
	trainerbattle_single TRAINER_KYLA, Route34_Text_KylaIntro, Route34_Text_KylaDefeated
	msgbox Route34_Text_KylaPostBattle, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_Elliot:: @ 81EE4C1
	trainerbattle_single TRAINER_ELLIOT_1, Route34_Text_ElliotIntro, Route34_Text_ElliotDefeated, Route34_EventScript_ElliotRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq Route34_EventScript_ElliotRematch
	msgbox Route34_Text_ElliotPostBattle, MSGBOX_DEFAULT
	release
	end

Route34_EventScript_ElliotRegisterMatchCallAfterBattle:: @ 81EE4ED
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route34_Text_ElliotRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_ELLIOT_1
	release
	end

Route34_EventScript_ElliotRematch:: @ 81EE50C
	trainerbattle_rematch TRAINER_ELLIOT_1, Route34_Text_ElliotRematchIntro, Route34_Text_ElliotRematchDefeated
	msgbox Route34_Text_ElliotRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_Ned:: @ 81EE523
	trainerbattle_single TRAINER_NED, Route34_Text_NedIntro, Route34_Text_NedDefeated
	msgbox Route34_Text_NedPostBattle, MSGBOX_AUTOCLOSE
	end

Route34_Text_TrainerTips: @ 81EE53A
	.string "TRAINER TIPS\p"
	.string "Advice on catching POKéMON with a ROD:\n"
	.string "Press the A Button if you get a bite.$"

Route34_EventScript_Keith_Text_0:
	.string "I'm on patrol for suspicious\n"
	.string "individuals.$"

Route34_EventScript_Irene_Text_0:
	.string "IRENE: My sister KATE will get\n"
	.string "you for this!$"

Route34_EventScript_Jenn_Text_0:
	.string "JENN: Don't get cocky!\n"
	.string "My sister KATE is tough!$"

Route34_EventScript_Kate_Text_0:
	.string "KATE: You're too strong.\n"
	.string "I didn't stand a chance.\p"
	.string "Here.\n"
	.string "You deserve this.$"

Route34_EventScript_DirectionsSign_Text_0:
	.string "ROUTE 34\n"
	.string "GOLDENROD CITY - AZALEA TOWN\p"
	.string "ILEX FOREST SOMEWHERE BETWEEN$"

Route34_EventScript_TrainerTipsSign_Text_0:
	.string "TRAINER TIPS\p"
	.string "BERRY trees grow new BERRIES\n"
	.string "every day.\p"
	.string "Make a note of which trees bear\n"
	.string "which BERRIES.$"

Route34_EventScript_DaycareSign_Text_0:
	.string "DAY-CARE\n"
	.string "LET US RAISE YOUR POKéMON FOR YOU!$"
