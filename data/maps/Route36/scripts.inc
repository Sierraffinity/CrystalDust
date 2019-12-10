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
	giveitem_std ITEM_HM06
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


Route36_EventScript_1EE68A:: @ 81EE68A
	trainerbattle_single TRAINER_JEROME, Route36_Text_296D10, Route36_Text_296D3C
	msgbox Route36_Text_296D6E, MSGBOX_AUTOCLOSE
	end

Route36_EventScript_1EE6A1:: @ 81EE6A1
	trainerbattle_single TRAINER_MATTHEW, Route36_Text_296DAF, Route36_Text_296DEA
	msgbox Route36_Text_296E03, MSGBOX_AUTOCLOSE
	end

Route36_EventScript_1EE6B8:: @ 81EE6B8
	trainerbattle_single TRAINER_TARA, Route36_Text_296E33, Route36_Text_296E71
	msgbox Route36_Text_296E7A, MSGBOX_AUTOCLOSE
	end

Route36_EventScript_1EE6CF:: @ 81EE6CF
	trainerbattle_single TRAINER_MISSY, Route36_Text_296EC7, Route36_Text_296EFC
	msgbox Route36_Text_296F2A, MSGBOX_AUTOCLOSE
	end

Route36_EventScript_1EE6E6:: @ 81EE6E6
	trainerbattle_single TRAINER_CAROLINA, Route36_Text_297094, Route36_Text_2970D7
	msgbox Route36_Text_2970F0, MSGBOX_AUTOCLOSE
	end

Route36_EventScript_1EE6FD:: @ 81EE6FD
	trainerbattle_single TRAINER_CORY_1, Route36_Text_296F5D, Route36_Text_296F93, Route36_EventScript_1EE729
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq Route36_EventScript_1EE748
	msgbox Route36_Text_296FB0, MSGBOX_DEFAULT
	release
	end

Route36_EventScript_1EE729:: @ 81EE729
	special sub_80B4808
	waitmovement 0
	msgbox Route36_Text_296FD8, MSGBOX_DEFAULT
	register_matchcall TRAINER_CORY_1
	release
	end

Route36_EventScript_1EE748:: @ 81EE748
	trainerbattle_rematch TRAINER_CORY_1, Route36_Text_297011, Route36_Text_297036
	msgbox Route36_Text_297059, MSGBOX_AUTOCLOSE
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
