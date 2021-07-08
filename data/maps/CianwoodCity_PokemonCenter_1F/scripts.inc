CianwoodCity_PokemonCenter_1F_MapScripts::
	.byte 0


CianwoodCity_PokemonCenter_1F_Eventscript_Girl::
	msgbox CianwoodCity_PokemonCenter_1F_Eventscript_Girl_Text_0, MSGBOX_NPC
	end


CianwoodCity_PokemonCenter_1F_Eventscript_Boy::
	msgbox CianwoodCity_PokemonCenter_1F_Eventscript_Boy_Text_0, MSGBOX_NPC
	end


CianwoodCity_PokemonCenter_1F_Eventscript_GymGuy::
	goto_if_set FLAG_BADGE05_GET, CianwoodCity_PokemonCenter_1F_Eventscript_GymGuy_2
	msgbox CianwoodCity_PokemonCenter_1F_Eventscript_GymGuy_Text_1, MSGBOX_NPC
	end

CianwoodCity_PokemonCenter_1F_Eventscript_GymGuy_2:
	msgbox CianwoodCity_PokemonCenter_1F_Eventscript_GymGuy_Text_0, MSGBOX_NPC
	end


CianwoodCity_PokemonCenter_1F_Eventscript_Girl_Text_0:
	.string "Did you meet the POKéMANIAC?\nHe's always bragging about his rare\lPOKéMON.$"

CianwoodCity_PokemonCenter_1F_Eventscript_Boy_Text_0:
	.string "I love showing off the POKéMON that\nI've raised. Don't you?\pI'm going to get into a bunch of\nbattles and show off my POKéMON!$"

CianwoodCity_PokemonCenter_1F_Eventscript_GymGuy_Text_0:
	.string "{PLAYER}! You won!\nI could tell by looking at you!$"

CianwoodCity_PokemonCenter_1F_Eventscript_GymGuy_Text_1:
	.string "The POKéMON GYM TRAINERS here are\nmacho bullies.\pIf I stick around, they might come\nafter me.\pHere's some advice: the GYM LEADER\nuses the FIGHTING-type.\pYou should confound him with\nPSYCHIC-type POKéMON.\pWipe out his POKéMON before they can\nuse their physical strength!\pAnd those boulders in the middle of\nthe GYM?\pIf you don't move them correctly,\nyou won't reach the GYM LEADER.\pIf you get stuck, go outside and\ncome back in.$"
