BlackthornCity_Gym_1F_MapScripts::
	.byte 0


BlackthornCity_Gym_1F_Eventscript_Statues::
	goto_if_set FLAG_BADGE08_GET, BlackthornCity_Gym_1F_Eventscript_Statues_2
	msgbox BlackthornCity_Gym_1F_Eventscript_Statues_Text_1, MSGBOX_SIGN
	end

BlackthornCity_Gym_1F_Eventscript_Statues_2:
	msgbox BlackthornCity_Gym_1F_Eventscript_Statues_Text_0, MSGBOX_SIGN
	end


BlackthornCity_Gym_1F_Eventscript_GymGuy::
	goto_if_set FLAG_BADGE08_GET, BlackthornCity_Gym_1F_Eventscript_GymGuy_2
	msgbox BlackthornCity_Gym_1F_Eventscript_GymGuy_Text_1, MSGBOX_NPC
	end

BlackthornCity_Gym_1F_Eventscript_GymGuy_2:
	msgbox BlackthornCity_Gym_1F_Eventscript_GymGuy_Text_0, MSGBOX_NPC
	end


BlackthornCity_Gym_1F_Eventscript_CooltrainerPaul::
	trainerbattle_single TRAINER_PAUL, BlackthornCity_Gym_1F_Eventscript_CooltrainerPaul_Text_0, BlackthornCity_Gym_1F_Eventscript_CooltrainerPaul_Text_1
	msgbox BlackthornCity_Gym_1F_Eventscript_CooltrainerPaul_Text_2, MSGBOX_AUTOCLOSE
	end


BlackthornCity_Gym_1F_Eventscript_CooltrainerMike::
	trainerbattle_single TRAINER_MIKE, BlackthornCity_Gym_1F_Eventscript_CooltrainerMike_Text_0, BlackthornCity_Gym_1F_Eventscript_CooltrainerMike_Text_1
	msgbox BlackthornCity_Gym_1F_Eventscript_CooltrainerMike_Text_2, MSGBOX_AUTOCLOSE
	end


BlackthornCity_Gym_1F_Eventscript_CooltrainerLola::
	trainerbattle_single TRAINER_LOLA, BlackthornCity_Gym_1F_Eventscript_CooltrainerLola_Text_0, BlackthornCity_Gym_1F_Eventscript_CooltrainerLola_Text_1
	msgbox BlackthornCity_Gym_1F_Eventscript_CooltrainerLola_Text_2, MSGBOX_AUTOCLOSE
	end


BlackthornCity_Gym_1F_Eventscript_Statues_Text_0:
	.string "BLACKTHORN CITY POKéMON GYM\nLEADER: CLAIR\pWINNING TRAINERS:\n{PLAYER}$"

BlackthornCity_Gym_1F_Eventscript_Statues_Text_1:
	.string "BLACKTHORN CITY POKéMON GYM$"

BlackthornCity_Gym_1F_Eventscript_GymGuy_Text_0:
	.string "You were great to beat CLAIR!\pAll that's left is the POKéMON LEAGUE\nchallenge.\pYou're on the way to becoming the\nPOKéMON CHAMPION!$"

BlackthornCity_Gym_1F_Eventscript_GymGuy_Text_1:
	.string "Yo! CHAMP in making!\pIt's been a long journey, but we are\nalmost done! Count on me!\pCLAIR uses the mythical and sacred\nDRAGON-type POKéMON.\pYou can't damage them very easily.\pBut you know, they're supposed to be\nweak against ICE-type moves.$"

BlackthornCity_Gym_1F_Eventscript_CooltrainerPaul_Text_0:
	.string "Your first battle against dragons?\nI'll show you how tough they are!$"

BlackthornCity_Gym_1F_Eventscript_CooltrainerPaul_Text_1:
	.string "My dragon POKéMON lost?$"

BlackthornCity_Gym_1F_Eventscript_CooltrainerPaul_Text_2:
	.string "LANCE told you that he'd like to see\nyou again? Not a chance!$"

BlackthornCity_Gym_1F_Eventscript_CooltrainerMike_Text_0:
	.string "My chance of losing?\nNot even one percent!$"

BlackthornCity_Gym_1F_Eventscript_CooltrainerMike_Text_1:
	.string "That's odd.$"

BlackthornCity_Gym_1F_Eventscript_CooltrainerMike_Text_2:
	.string "I know my shortcomings now.\nThanks for showing me!$"

BlackthornCity_Gym_1F_Eventscript_CooltrainerLola_Text_0:
	.string "Dragons are sacred POKéMON.\nThey are full of life energy.\pIf you're not serious, you won't be\nable to beat them.$"

BlackthornCity_Gym_1F_Eventscript_CooltrainerLola_Text_1:
	.string "Way to go!$"

BlackthornCity_Gym_1F_Eventscript_CooltrainerLola_Text_2:
	.string "Dragons are weak against DRAGON-\ntype moves.$"
