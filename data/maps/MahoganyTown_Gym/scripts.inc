MahoganyTown_Gym_MapScripts::
	.byte 0


MahoganyTown_Gym_Eventscript_Statues::
	goto_if_set FLAG_BADGE07_GET, MahoganyTown_Gym_Eventscript_Statues_2
	msgbox MahoganyTown_Gym_Eventscript_Statues_Text_1, MSGBOX_SIGN
	end

MahoganyTown_Gym_Eventscript_Statues_2:
	msgbox MahoganyTown_Gym_Eventscript_Statues_Text_0, MSGBOX_SIGN
	end


MahoganyTown_Gym_Eventscript_GymGuy::
	goto_if_set FLAG_BADGE07_GET, MahoganyTown_Gym_Eventscript_GymGuy_2
	msgbox MahoganyTown_Gym_Eventscript_GymGuy_Text_1, MSGBOX_NPC
	end

MahoganyTown_Gym_Eventscript_GymGuy_2:
	msgbox MahoganyTown_Gym_Eventscript_GymGuy_Text_0, MSGBOX_NPC
	end


MahoganyTown_Gym_Eventscript_BoarderDouglas::
	trainerbattle_single TRAINER_DOUGLAS, MahoganyTown_Gym_Eventscript_BoarderDouglas_Text_0, MahoganyTown_Gym_Eventscript_BoarderDouglas_Text_1
	msgbox MahoganyTown_Gym_Eventscript_BoarderDouglas_Text_2, MSGBOX_AUTOCLOSE
	end


MahoganyTown_Gym_Eventscript_SkierRoxanne::
	trainerbattle_single TRAINER_ROXANNE, MahoganyTown_Gym_Eventscript_SkierRoxanne_Text_0, MahoganyTown_Gym_Eventscript_SkierRoxanne_Text_1
	msgbox MahoganyTown_Gym_Eventscript_SkierRoxanne_Text_2, MSGBOX_AUTOCLOSE
	end


MahoganyTown_Gym_Eventscript_BoarderBrad::
	trainerbattle_single TRAINER_BRAD, MahoganyTown_Gym_Eventscript_BoarderBrad_Text_0, MahoganyTown_Gym_Eventscript_BoarderBrad_Text_1
	msgbox MahoganyTown_Gym_Eventscript_BoarderBrad_Text_2, MSGBOX_AUTOCLOSE
	end


MahoganyTown_Gym_Eventscript_BoarderRonald::
	trainerbattle_single TRAINER_RONALD, MahoganyTown_Gym_Eventscript_BoarderRonald_Text_0, MahoganyTown_Gym_Eventscript_BoarderRonald_Text_1
	msgbox MahoganyTown_Gym_Eventscript_BoarderRonald_Text_2, MSGBOX_AUTOCLOSE
	end


MahoganyTown_Gym_Eventscript_SkierClarissa::
	trainerbattle_single TRAINER_CLARISSA, MahoganyTown_Gym_Eventscript_SkierClarissa_Text_0, MahoganyTown_Gym_Eventscript_SkierClarissa_Text_1
	msgbox MahoganyTown_Gym_Eventscript_SkierClarissa_Text_2, MSGBOX_AUTOCLOSE
	end


MahoganyTown_Gym_Eventscript_Statues_Text_0:
	.string "MAHOGANY TOWN POKéMON GYM\nLEADER: PRYCE\pWINNING TRAINERS:\n{PLAYER}$"

MahoganyTown_Gym_Eventscript_Statues_Text_1:
	.string "MAHOGANY TOWN POKéMON GYM$"

MahoganyTown_Gym_Eventscript_GymGuy_Text_0:
	.string "PRYCE is something, but you're\nsomething else!\pThat was a hot battle that bridged\nthe generation gap!$"

MahoganyTown_Gym_Eventscript_GymGuy_Text_1:
	.string "PRYCE is a veteran who has trained\nPOKéMON for some 50 years.\pHe's said to be good at freezing\nopponents with ICE-type moves.\pThat means you should melt him with\nyour burning ambition!$"

MahoganyTown_Gym_Eventscript_BoarderDouglas_Text_0:
	.string "I know PRYCE's secret.$"

MahoganyTown_Gym_Eventscript_BoarderDouglas_Text_1:
	.string "Okay, I'll tell you PRYCE's secret.$"

MahoganyTown_Gym_Eventscript_BoarderDouglas_Text_2:
	.string "The secret behind PRYCE's power…\pHe meditates under a waterfall daily\nto strengthen his mind and body.$"

MahoganyTown_Gym_Eventscript_SkierRoxanne_Text_0:
	.string "To get to PRYCE, our GYM LEADER, you\nneed to think before you skate.$"

MahoganyTown_Gym_Eventscript_SkierRoxanne_Text_1:
	.string "I wouldn't lose to you in skiing!$"

MahoganyTown_Gym_Eventscript_SkierRoxanne_Text_2:
	.string "If you don't skate with precision,\nyou won't get far in this GYM.$"

MahoganyTown_Gym_Eventscript_BoarderBrad_Text_0:
	.string "This GYM has a slippery floor.\nIt's fun, isn't it?\pBut hey--we're not playing games\nhere!$"

MahoganyTown_Gym_Eventscript_BoarderBrad_Text_1:
	.string "Do you see how serious we are?$"

MahoganyTown_Gym_Eventscript_BoarderBrad_Text_2:
	.string "This GYM is great.\nI love boarding with my POKéMON!$"

MahoganyTown_Gym_Eventscript_BoarderRonald_Text_0:
	.string "I'll freeze your POKéMON, so you\ncan't do a thing!$"

MahoganyTown_Gym_Eventscript_BoarderRonald_Text_1:
	.string "Darn. I couldn't do a thing.$"

MahoganyTown_Gym_Eventscript_BoarderRonald_Text_2:
	.string "I think there's a move a POKéMON can\nuse while it's frozen.$"

MahoganyTown_Gym_Eventscript_SkierClarissa_Text_0:
	.string "Check out my parallel turn!$"

MahoganyTown_Gym_Eventscript_SkierClarissa_Text_1:
	.string "No! You made me wipe out!$"

MahoganyTown_Gym_Eventscript_SkierClarissa_Text_2:
	.string "I shouldn't have been bragging about\nmy skiing…$"
