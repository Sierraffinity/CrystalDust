EcruteakCity_Gym_MapScripts::
	.byte 0


EcruteakCity_Gym_Eventscript_Statues::
	goto_if_set FLAG_BADGE04_GET, EcruteakCity_Gym_Eventscript_Statues_2
	msgbox EcruteakCity_Gym_Eventscript_Statues_Text_1, MSGBOX_SIGN
	end

EcruteakCity_Gym_Eventscript_Statues_2:
	msgbox EcruteakCity_Gym_Eventscript_Statues_Text_0, MSGBOX_SIGN
	end


EcruteakCity_Gym_Eventscript_GymGuy::
	goto_if_set FLAG_BADGE04_GET, EcruteakCity_Gym_Eventscript_GymGuy_2
	msgbox EcruteakCity_Gym_Eventscript_GymGuy_Text_1, MSGBOX_NPC
	end

EcruteakCity_Gym_Eventscript_GymGuy_2:
	msgbox EcruteakCity_Gym_Eventscript_GymGuy_Text_0, MSGBOX_NPC
	end


EcruteakCity_Gym_Eventscript_SagePing::
	trainerbattle_single TRAINER_PING, EcruteakCity_Gym_Eventscript_SagePing_Text_0, EcruteakCity_Gym_Eventscript_SagePing_Text_1
	msgbox EcruteakCity_Gym_Eventscript_SagePing_Text_2, MSGBOX_AUTOCLOSE
	end


EcruteakCity_Gym_Eventscript_MediumGrace::
	trainerbattle_single TRAINER_GRACE, EcruteakCity_Gym_Eventscript_MediumGrace_Text_0, EcruteakCity_Gym_Eventscript_MediumGrace_Text_1
	msgbox EcruteakCity_Gym_Eventscript_MediumGrace_Text_2, MSGBOX_AUTOCLOSE
	end


EcruteakCity_Gym_Eventscript_SageJeffrey::
	trainerbattle_single TRAINER_JEFFREY, EcruteakCity_Gym_Eventscript_SageJeffrey_Text_0, EcruteakCity_Gym_Eventscript_SageJeffrey_Text_1
	msgbox EcruteakCity_Gym_Eventscript_SageJeffrey_Text_2, MSGBOX_AUTOCLOSE
	end


EcruteakCity_Gym_Eventscript_MediumMartha::
	trainerbattle_single TRAINER_MARTHA, EcruteakCity_Gym_Eventscript_MediumMartha_Text_0, EcruteakCity_Gym_Eventscript_MediumMartha_Text_1
	msgbox EcruteakCity_Gym_Eventscript_MediumMartha_Text_2, MSGBOX_AUTOCLOSE
	end


EcruteakCity_Gym_Eventscript_Statues_Text_0:
	.string "ECRUTEAK CITY POKéMON GYM\nLEADER: MORTY\pWINNING TRAINERS:\n{PLAYER}$"

EcruteakCity_Gym_Eventscript_Statues_Text_1:
	.string "ECRUTEAK CITY POKéMON GYM$"

EcruteakCity_Gym_Eventscript_GymGuy_Text_0:
	.string "Whew, {PLAYER}.\nYou did great!\pI was cowering in the corner out of\npure terror!$"

EcruteakCity_Gym_Eventscript_GymGuy_Text_1:
	.string "The TRAINERS here have secret\nmotives.\pIf you win, they may tell you some\ndeep secrets about ECRUTEAK.$"

EcruteakCity_Gym_Eventscript_SagePing_Text_0:
	.string "Can you inflict any damage on our\nPOKéMON?$"

EcruteakCity_Gym_Eventscript_SagePing_Text_1:
	.string "Ah! Well done!$"

EcruteakCity_Gym_Eventscript_SagePing_Text_2:
	.string "We use only GHOST-type POKéMON.\nNo NORMAL-type attack can harm them!$"

EcruteakCity_Gym_Eventscript_MediumGrace_Text_0:
	.string "Stumped by our invisible floor?\nDefeat me if you want a hint!$"

EcruteakCity_Gym_Eventscript_MediumGrace_Text_1:
	.string "Wha-what?$"

EcruteakCity_Gym_Eventscript_MediumGrace_Text_2:
	.string "Fine. I shall tell you the secret of\nthe invisible floor.\pThe path is right before our eyes!$"

EcruteakCity_Gym_Eventscript_SageJeffrey_Text_0:
	.string "I spent the spring with my POKéMON.\nThen summer, fall, and winter…\pThen spring came again. We have\nlived together for a long time.$"

EcruteakCity_Gym_Eventscript_SageJeffrey_Text_1:
	.string "Wins and losses, I experienced both.$"

EcruteakCity_Gym_Eventscript_SageJeffrey_Text_2:
	.string "Where did POKéMON come from?$"

EcruteakCity_Gym_Eventscript_MediumMartha_Text_0:
	.string "I shall win!$"

EcruteakCity_Gym_Eventscript_MediumMartha_Text_1:
	.string "I, I, I lost!$"

EcruteakCity_Gym_Eventscript_MediumMartha_Text_2:
	.string "The one who wants to win most--will!$"
