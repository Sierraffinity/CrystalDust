DarkCave_B1F_MapScripts:: @ 822DC5E
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CaveHole_CheckFallDownHole
	map_script MAP_SCRIPT_ON_TRANSITION, CaveHole_FixCrackedGround
	map_script MAP_SCRIPT_ON_RESUME, DarkCave_B1F_SetHoleWarp
	.byte 0

DarkCave_B1F_SetHoleWarp: @ 822DC6E
	setstepcallback 7
	setholewarp MAP_UNION_CAVE_B1F, 255, 0, 0
	end

