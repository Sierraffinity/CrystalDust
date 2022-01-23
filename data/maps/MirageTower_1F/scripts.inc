MirageTower_1F_MapScripts:: @ 823AD01
	map_script MAP_SCRIPT_ON_TRANSITION, MirageTower_1F_OnTransition
	.byte 0

MirageTower_1F_OnTransition: @ 823AD07
	setflag FLAG_ENTERED_MIRAGE_TOWER
	setflag FLAG_FORCED_CALL_ELM_STOLEN_MON
	setflag FLAG_RECEIVED_SPELL_TAG_FROM_SANTOS
	end

