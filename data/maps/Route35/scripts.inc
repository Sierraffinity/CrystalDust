Route35_MapScripts:: @ 81EE594
	.byte 0

Route35_EventScript_Darrin:: @ 81EE595
	trainerbattle_single TRAINER_DARRIN, Route35_Text_DarrinIntro, Route35_Text_DarrinDefeated
	msgbox Route35_Text_DarrinPostBattle, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_Tony:: @ 81EE5AC
	trainerbattle_single TRAINER_TONY_1, Route35_Text_TonyIntro, Route35_Text_TonyDefeated, Route35_EventScript_TonyRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq Route35_EventScript_TonyRematch
	msgbox Route35_Text_TonyPostBattle, MSGBOX_DEFAULT
	release
	end

Route35_EventScript_TonyRegisterMatchCallAfterBattle:: @ 81EE5D8
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route35_Text_TonyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_TONY_1
	release
	end

Route35_EventScript_TonyRematch:: @ 81EE5F7
	trainerbattle_rematch TRAINER_TONY_1, Route35_Text_TonyRematchIntro, Route35_Text_TonyRematchDefeated
	msgbox Route35_Text_TonyRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_Denise:: @ 81EE60E
	trainerbattle_single TRAINER_DENISE, Route35_Text_DeniseIntro, Route35_Text_DeniseDefeated
	msgbox Route35_Text_DenisePostBattle, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_Beth:: @ 81EE625
	trainerbattle_single TRAINER_BETH, Route35_Text_BethIntro, Route35_Text_BethDefeated
	msgbox Route35_Text_BethPostBattle, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_Lisa:: @ 81EE63C
	trainerbattle_double TRAINER_LISA_AND_RAY, Route35_Text_LisaIntro, Route35_Text_LisaDefeated, Route35_Text_LisaNotEnoughPokemon
	msgbox Route35_Text_LisaPostBattle, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_Ray:: @ 81EE657
	trainerbattle_double TRAINER_LISA_AND_RAY, Route35_Text_RayIntro, Route35_Text_RayDefeated, Route35_Text_RayNotEnoughPokemon
	msgbox Route35_Text_RayPostBattle, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_Camron:: @ 81EE672
	trainerbattle_single TRAINER_CAMRON, Route35_Text_CamronIntro, Route35_Text_CamronDefeated
	msgbox Route35_Text_CamronPostBattle, MSGBOX_AUTOCLOSE
	end

