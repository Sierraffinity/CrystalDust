SlowpokeWell_B1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SlowpokeWell_B1F_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

SlowpokeWell_B1F_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	setflag FLAG_LANDMARK_SLOWPOKE_WELL
	return


SlowpokeWell_B1F_EventScript_Kurt::
	msgbox SlowpokeWell_B1F_EventScript_Kurt_Text_0, MSGBOX_NPC
	return


SlowpokeWell_B1F_EventScript_Rocket1::
	trainerbattle_single TRAINER_ROCKET_SLOWPOKE_WELL_1, SlowpokeWell_B1F_Text_Rocket1Intro, SlowpokeWell_B1F_Text_Rocket1Defeat
	msgbox SlowpokeWell_B1F_Text_Rocket1PostBattle
	release
	return


SlowpokeWell_B1F_EventScript_Rocket2::
	trainerbattle_single TRAINER_ROCKET_SLOWPOKE_WELL_2, SlowpokeWell_B1F_Text_Rocket2Intro, SlowpokeWell_B1F_Text_Rocket2Defeat
	msgbox SlowpokeWell_B1F_Text_Rocket2PostBattle
	release
	return


SlowpokeWell_B1F_EventScript_Rocket3::
	trainerbattle_single TRAINER_ROCKET_SLOWPOKE_WELL_3, SlowpokeWell_B1F_Text_Rocket3Intro, SlowpokeWell_B1F_Text_Rocket3Defeat
	msgbox SlowpokeWell_B1F_Text_Rocket3PostBattle
	release
	return


SlowpokeWell_B1F_EventScript_RocketBoss::
	trainerbattle_single TRAINER_ROCKET_SLOWPOKE_WELL_BOSS, SlowpokeWell_B1F_Text_RocketBossIntro, SlowpokeWell_B1F_Text_RocketBossDefeat, SlowpokeWell_B1F_EventScript_RocketBossDefeated
	release
	return


SlowpokeWell_B1F_EventScript_RocketBossDefeated::
	msgbox SlowpokeWell_B1F_EventScript_RocketBossDefeated_Text_0
	closemessage
	fadescreen FADE_TO_BLACK
	removeobject 1
	removeobject 4
	removeobject 3
	removeobject 2
	removeobject 7
	addobject 10
	fadescreen FADE_FROM_BLACK
	applymovement 5, SlowpokeWell_B1F_FirstSlowpokeWaitTurn
	applymovement 6, SlowpokeWell_B1F_SecondSlowpokeWaitTurn
	applymovement 10, SlowpokeWell_B1F_KurtToSlowpokes
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	msgbox SlowpokeWell_B1F_EventScript_RocketBossDefeated_Text_1
	setflag FLAG_CLEARED_SLOWPOKE_WELL
	setvar VAR_AZALEA_TOWN_STATE, 1
	clearflag FLAG_HIDE_ILEX_FOREST_APPRENTICE_FARFETCHD
	setflag FLAG_HIDE_AZALEA_TOWN_CHARCOAL_KILN_APPRENTICE_FARFETCHD
	setflag FLAG_HIDE_SLOWPOKE_WELL_B1F_ROCKETS
	setflag FLAG_HIDE_SLOWPOKE_WELL_B1F_KURT
	clearflag FLAG_HIDE_AZALEA_TOWN_SLOWPOKES
	clearflag FLAG_HIDE_AZALEA_TOWN_KURTS_HOUSE_KURT
	special HealPlayerParty
	warp MAP_AZALEA_TOWN_KURTS_HOUSE, -1, 4, 4
	waitstate
	release
	return


SlowpokeWell_B1F_FirstSlowpokeWaitTurn:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	face_down
	delay_16
	delay_16
	delay_16
	face_left
	step_end

SlowpokeWell_B1F_SecondSlowpokeWaitTurn:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	face_down
	step_end

SlowpokeWell_B1F_KurtToSlowpokes:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	delay_16
	delay_8
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	delay_16
	delay_8
	walk_in_place_fastest_left
	step_end

SlowpokeWell_B1F_EventScript_SlowpokeWithMail::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SLOWPOKE, 2
	msgbox SlowpokeWell_B1F_EventScript_SlowpokeWithMail_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq SlowpokeWell_B1F_EventScript_SlowpokeWithMail_2
SlowpokeWell_B1F_EventScript_SlowpokeWithMail_1:
	release
	return

SlowpokeWell_B1F_EventScript_SlowpokeWithMail_2:
	msgbox SlowpokeWell_B1F_EventScript_SlowpokeWithMail_Text_1
	goto SlowpokeWell_B1F_EventScript_SlowpokeWithMail_1


SlowpokeWell_B1F_EventScript_TaillessSlowpoke::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SLOWPOKE, 2
	msgbox SlowpokeWell_B1F_EventScript_TaillessSlowpoke_Text_0
	waitmoncry
	release
	return


SlowpokeWell_B1F_EventScript_Kurt_Text_0:
	.string "KURT: Hey there, {PLAYER}!\n"
	.string "The guard up top took off when I\l"
	.string "shouted at him.\p"
	.string "But then I took a tumble down the\n"
	.string "WELL.\p"
	.string "I slammed down hard on my back,\n"
	.string "so I can't move.\p"
	.string "Rats! If I were fit, my POKéMON\n"
	.string "would've punished them…\l"
	.string "Ah, it can't be helped.\p"
	.string "{PLAYER}, show them how gutsy you are\n"
	.string "in my place!$"

SlowpokeWell_B1F_EventScript_RocketBossDefeated_Text_0:
	.string "Yeah, TEAM ROCKET was broken up\n"
	.string "three years ago.\p"
	.string "But we continued our activities\n"
	.string "underground.\p"
	.string "Now you can have fun watching us\n"
	.string "stir up trouble!$"

SlowpokeWell_B1F_EventScript_RocketBossDefeated_Text_1:
	.string "KURT: Way to go, {PLAYER}!\n"
	.string "TEAM ROCKET has taken off.\p"
	.string "My back's feeling a lot better, too.\n"
	.string "Let's get out of here.$"

SlowpokeWell_B1F_EventScript_SlowpokeWithMail_Text_0:
	.string "It's a SLOWPOKE with its TAIL\n"
	.string "cut off…\p"
	.string "Huh? It has MAIL.\n"
	.string "Read it?$"

SlowpokeWell_B1F_EventScript_SlowpokeWithMail_Text_1:
	.string "{PLAYER} read the MAIL.\n"
	.string "……\p"
	.string "Be good and look after the house\n"
	.string "with Grandpa and SLOWPOKE.\l"
	.string "Love, Dad$"

SlowpokeWell_B1F_EventScript_TaillessSlowpoke_Text_0:
	.string "It's a SLOWPOKE with its TAIL\n"
	.string "cut off…$"

SlowpokeWell_B1F_Text_RocketBossIntro::
	.string "What do you want?\p"
	.string "If you interrupt our work, don't\n"
	.string "expect any mercy!$"

SlowpokeWell_B1F_Text_RocketBossDefeat::
	.string "You did okay today, but wait till\n"
	.string "next time!$"
