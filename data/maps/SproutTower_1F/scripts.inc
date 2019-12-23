SproutTower_1F_MapScripts:: @ 823799A
	map_script MAP_SCRIPT_ON_TRANSITION, SproutTower_1F_OnTransition
	.byte 0

SproutTower_1F_OnTransition: @ 82379A0
	setflag FLAG_LANDMARK_ABANDONED_SHIP
	end

