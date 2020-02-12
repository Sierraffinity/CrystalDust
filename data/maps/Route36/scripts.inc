Route36_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route36_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

Route36_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	gettime
	compare VAR_0x8003, DAY_THURSDAY
	goto_if_eq Route36_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	setflag FLAG_HIDE_ROUTE_36_ARTHUR
	return

Route36_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
	clearflag FLAG_HIDE_ROUTE_36_ARTHUR
	return


Route36_EventScript_BlockedGirl::
	lock
	faceplayer
	goto_if_unset FLAG_DEFEATED_SUDOWOODO, Route36_EventScript_BlockedGirl_2
	msgbox Route36_EventScript_BlockedGirl_Text_1
Route36_EventScript_BlockedGirl_1:
	release
	return

Route36_EventScript_BlockedGirl_2:
	msgbox Route36_EventScript_BlockedGirl_Text_0
	goto Route36_EventScript_BlockedGirl_1


Route36_EventScript_RockSmashGuy::
	lock
	faceplayer
	goto_if_unset FLAG_RECEIVED_HM06, Route36_EventScript_RockSmashGuy_2
Route36_EventScript_RockSmashGuy_1:
	msgbox Route36_EventScript_RockSmashGuy_Text_2
	release
	return

Route36_EventScript_RockSmashGuy_2:
	goto_if_unset FLAG_DEFEATED_SUDOWOODO, Route36_EventScript_RockSmashGuy_4
	msgbox Route36_EventScript_RockSmashGuy_Text_1
	giveitem ITEM_HM06
	setflag FLAG_RECEIVED_HM06
	goto Route36_EventScript_RockSmashGuy_1

Route36_EventScript_RockSmashGuy_4:
	msgbox Route36_EventScript_RockSmashGuy_Text_0
	release
	end


Route36_EventScript_Sudowoodo::
	lock
	waitse
	playse SE_USSOKI
	applymovement 3, Route36_Movement_Sudowoodo
	waitmovement 0
	release
	return


Route36_Movement_Sudowoodo:
	face_right
	delay_8
	face_down
	delay_8
	face_left
	delay_8
	face_down
	delay_8
	face_right
	delay_8
	face_down
	delay_8
	face_left
	delay_8
	face_down
	step_end

Route36_EventScript_DirectionsSign::
	msgbox Route36_EventScript_DirectionsSign_Text_0, MSGBOX_SIGN
	return


Route36_EventScript_RuinsOfAlphSign::
	msgbox Route36_EventScript_RuinsOfAlphSign_Text_0, MSGBOX_SIGN
	return


Route36_EventScript_Jerome:: @ 81EE68A
	trainerbattle_single TRAINER_JEROME, Route36_Text_JeromeIntro, Route36_Text_JeromeDefeated
	msgbox Route36_Text_JeromePostBattle, MSGBOX_AUTOCLOSE
	end

Route36_EventScript_Matthew:: @ 81EE6A1
	trainerbattle_single TRAINER_MATTHEW, Route36_Text_MatthewIntro, Route36_Text_MatthewDefeated
	msgbox Route36_Text_MatthewPostBattle, MSGBOX_AUTOCLOSE
	end

Route36_EventScript_Tara:: @ 81EE6B8
	trainerbattle_single TRAINER_TARA, Route36_Text_TaraIntro, Route36_Text_TaraDefeated
	msgbox Route36_Text_TaraPostBattle, MSGBOX_AUTOCLOSE
	end

Route36_EventScript_Missy:: @ 81EE6CF
	trainerbattle_single TRAINER_MISSY, Route36_Text_MissyIntro, Route36_Text_MissyDefeated
	msgbox Route36_Text_MissyPostBattle, MSGBOX_AUTOCLOSE
	end

Route36_EventScript_Carolina:: @ 81EE6E6
	trainerbattle_single TRAINER_CAROLINA, Route36_Text_CarolinaIntro, Route36_Text_CarolinaDefeated
	msgbox Route36_Text_CarolinaPostBattle, MSGBOX_AUTOCLOSE
	end

Route36_EventScript_Cory:: @ 81EE6FD
	trainerbattle_single TRAINER_CORY_1, Route36_Text_CoryIntro, Route36_Text_CoryDefeated, Route36_EventScript_CoryRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq Route36_EventScript_CoryRematch
	msgbox Route36_Text_CoryPostBattle, MSGBOX_DEFAULT
	release
	end

Route36_EventScript_CoryRegisterMatchCallAfterBattle:: @ 81EE729
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route36_Text_CoryRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_CORY_1
	release
	end

Route36_EventScript_CoryRematch:: @ 81EE748
	trainerbattle_rematch TRAINER_CORY_1, Route36_Text_CoryRematchIntro, Route36_Text_CoryRematchDefeated
	msgbox Route36_Text_CoryRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route36_EventScript_BlockedGirl_Text_0:
	.string "An odd tree is blocking the way\n"
	.string "to GOLDENROD CITY.\p"
	.string "I wanted to go see the huge\n"
	.string "POKéMON CENTER they just opened…$"

Route36_EventScript_BlockedGirl_Text_1:
	.string "That odd tree disappeared without\n"
	.string "a trace.\p"
	.string "Oh!\n"
	.string "That tree was really a POKéMON?$"

Route36_EventScript_RockSmashGuy_Text_0:
	.string "Wa-hey!\p"
	.string "I was going to snap that tree with\n"
	.string "my straight-arm punch.\p"
	.string "But I couldn't!\n"
	.string "I'm a failure!$"

Route36_EventScript_RockSmashGuy_Text_1:
	.string "Did you clear that wretched tree?\n"
	.string "I'm impressed!\l"
	.string "I want you to have this.$"

Route36_EventScript_RockSmashGuy_Text_2:
	.string "That HM happens to be ROCK SMASH.\n"
	.string "You can shatter rocks with just a\l"
	.string "single well-aimed smack.\p"
	.string "If any rocks are in your way, just\n"
	.string "smash 'em up!$"

Route36_EventScript_DirectionsSign_Text_0:
	.string "ROUTE 36$"

Route36_EventScript_RuinsOfAlphSign_Text_0:
	.string "RUINS OF ALPH\n"
	.string "NORTH ENTRANCE$"
