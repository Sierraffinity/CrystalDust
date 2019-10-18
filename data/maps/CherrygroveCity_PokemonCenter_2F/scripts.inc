CherrygroveCity_PokemonCenter_2F_MapScripts:: @ 81FC218
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CableClub_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, CableClub_OnWarp
	map_script MAP_SCRIPT_ON_LOAD, CableClub_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, CableClub_OnTransition
	.byte 0

@ The below 3 are unused and leftover from RS
CherrygroveCity_PokemonCenter_2F_EventScript_1FC22D:: @ 81FC22D
	call CableClub_EventScript_Colosseum
	end

CherrygroveCity_PokemonCenter_2F_EventScript_1FC233:: @ 81FC233
	call CableClub_EventScript_TradeCenter
	end

CherrygroveCity_PokemonCenter_2F_EventScript_1FC239:: @ 81FC239
	call CableClub_EventScript_RecordCorner
	end

