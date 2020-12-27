FieryPath_MapScripts:: @ 8230F24
	map_script MAP_SCRIPT_ON_TRANSITION, FieryPath_OnTransition
	.byte 0

FieryPath_OnTransition: @ 8230F2A
	call_if_unset FLAG_LANDMARK_LAKE_OF_RAGE, FieryPath_EventScript_MoveScottToFallarbor
	setflag FLAG_LANDMARK_LAKE_OF_RAGE
	end

FieryPath_EventScript_MoveScottToFallarbor:: @ 8230F37
	setflag FLAG_HIDE_GOLDENROD_CITY_GAME_CORNER_NERD
	clearflag FLAG_HIDE_GOLDENROD_CITY_UNDERGROUND_BARGAIN_MAN
	return

