RuinsOfAlph_OmanyteItemRoom_MapScripts:: @ 823895D
	map_script MAP_SCRIPT_ON_RESUME, RuinsOfAlph_OmanyteItemRoom_OnResume
	.byte 0

RuinsOfAlph_OmanyteItemRoom_OnResume: @ 8238963
	setdivewarp MAP_RUINS_OF_ALPH_KABUTO_CHAMBER, 255, 13, 7
	end

