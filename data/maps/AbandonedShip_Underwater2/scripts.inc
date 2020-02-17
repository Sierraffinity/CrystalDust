AbandonedShip_Underwater2_MapScripts:: @ 823895D
	map_script MAP_SCRIPT_ON_RESUME, AbandonedShip_Underwater2_OnResume
	.byte 0

AbandonedShip_Underwater2_OnResume: @ 8238963
	setdivewarp MAP_RUINS_OF_ALPH_KABUTO_CHAMBER, 255, 13, 7
	end

