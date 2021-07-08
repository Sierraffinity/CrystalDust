OlivineCity_Gym_MapScripts::
	.byte 0


OlivineCity_Gym_Eventscript_Statues::
	goto_if_set FLAG_BADGE06_GET, OlivineCity_Gym_Eventscript_Statues_2
	msgbox OlivineCity_Gym_Eventscript_Statues_Text_1, MSGBOX_SIGN
	end

OlivineCity_Gym_Eventscript_Statues_2:
	msgbox OlivineCity_Gym_Eventscript_Statues_Text_0, MSGBOX_SIGN
	end


OlivineCity_Gym_Eventscript_Statues_Text_0:
	.string "OLIVINE CITY POKéMON GYM\nLEADER: JASMINE\pWINNING TRAINERS:\n{PLAYER}$"

OlivineCity_Gym_Eventscript_Statues_Text_1:
	.string "OLIVINE CITY POKéMON GYM$"
