EventScript_FieldPoison::
	lockall
	special TryFieldPoisonWhiteOut
	waitstate
	compare VAR_RESULT, FLDPSN_WHITEOUT
	goto_if_eq EventScript_FieldWhiteOut
	compare VAR_RESULT, FLDPSN_FRONTIER_WHITEOUT
	goto_if_eq EventScript_FrontierFieldWhiteOut
	compare VAR_RESULT, FLDPSN_BUGCONTEST_WHITEOUT
	goto_if_eq EventScript_BugCatchingContestFieldWhiteout
	releaseall
	end

EventScript_FrontierFieldWhiteOut::
	pike_inchallenge
	compare VAR_RESULT, TRUE
	goto_if_eq BattleFrontier_BattlePike_EventScript_Retire
	pyramid_inchallenge
	compare VAR_RESULT, 1  @ On Pyramid floor
	goto_if_eq BattleFrontier_BattlePyramid_EventScript_WarpToLobbyWhiteOut
	compare VAR_RESULT, 2  @ On Pyramid peak
	goto_if_eq BattleFrontier_BattlePyramid_EventScript_WarpToLobbyWhiteOut
	trainerhill_inchallenge
	compare VAR_RESULT, TRUE
	goto_if_eq TrainerHill_1F_EventScript_WhiteOut

	@ fallthrough
EventScript_FieldWhiteOut::
	checkmoney 1, 0
	compare VAR_RESULT, TRUE
	goto_if_eq EventScript_FieldWhiteOutHasMoney
	msgbox gText_PlayerWhitedOut
	goto EventScript_FieldWhiteOutFade

EventScript_FieldWhiteOutHasMoney::
	special OverworldWhiteOutGetMoneyLoss
	msgbox gText_WhitedOutLostMoney
EventScript_FieldWhiteOutFade::
	special Script_FadeOutMapMusic
	waitstate
	fadescreen FADE_TO_BLACK
	special SetCB2WhiteOut
	waitstate
	end

EventScript_BugCatchingContestFieldWhiteout::
	msgbox gText_PlayerWhitedOut
	goto EventScript_WarpOutOfBugCatchingContestHeal
