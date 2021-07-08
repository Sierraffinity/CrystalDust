CianwoodCity_Gym_MapScripts::
	.byte 0


CianwoodCity_Gym_Eventscript_Statues::
	goto_if_set FLAG_BADGE05_GET, CianwoodCity_Gym_Eventscript_Statues_2
	msgbox CianwoodCity_Gym_Eventscript_Statues_Text_1, MSGBOX_SIGN
	end

CianwoodCity_Gym_Eventscript_Statues_2:
	msgbox CianwoodCity_Gym_Eventscript_Statues_Text_0, MSGBOX_SIGN
	end


CianwoodCity_Gym_Eventscript_BlackBeltYoshi::
	trainerbattle_single TRAINER_YOSHI, CianwoodCity_Gym_Eventscript_BlackBeltYoshi_Text_0, CianwoodCity_Gym_Eventscript_BlackBeltYoshi_Text_1
	msgbox CianwoodCity_Gym_Eventscript_BlackBeltYoshi_Text_2, MSGBOX_AUTOCLOSE
	end


CianwoodCity_Gym_Eventscript_BlackBeltLao::
	trainerbattle_single TRAINER_LAO, CianwoodCity_Gym_Eventscript_BlackBeltLao_Text_0, CianwoodCity_Gym_Eventscript_BlackBeltLao_Text_1
	msgbox CianwoodCity_Gym_Eventscript_BlackBeltLao_Text_2, MSGBOX_AUTOCLOSE
	end


CianwoodCity_Gym_Eventscript_BlackBeltNob::
	trainerbattle_single TRAINER_NOB, CianwoodCity_Gym_Eventscript_BlackBeltNob_Text_0, CianwoodCity_Gym_Eventscript_BlackBeltNob_Text_1
	msgbox CianwoodCity_Gym_Eventscript_BlackBeltNob_Text_2, MSGBOX_AUTOCLOSE
	end


CianwoodCity_Gym_Eventscript_BlackBeltLung::
	trainerbattle_single TRAINER_LUNG, CianwoodCity_Gym_Eventscript_BlackBeltLung_Text_0, CianwoodCity_Gym_Eventscript_BlackBeltLung_Text_1
	msgbox CianwoodCity_Gym_Eventscript_BlackBeltLung_Text_2, MSGBOX_AUTOCLOSE
	end


CianwoodCity_Gym_Eventscript_Statues_Text_0:
	.string "CIANWOOD CITY POKéMON GYM\nLEADER: CHUCK\pWINNING TRAINERS:\n{PLAYER}$"

CianwoodCity_Gym_Eventscript_Statues_Text_1:
	.string "CIANWOOD CITY POKéMON GYM$"

CianwoodCity_Gym_Eventscript_BlackBeltYoshi_Text_0:
	.string "My POKéMON and I are bound together\nby friendship.\pOur bond will never be broken!$"

CianwoodCity_Gym_Eventscript_BlackBeltYoshi_Text_1:
	.string "This isn't real!$"

CianwoodCity_Gym_Eventscript_BlackBeltYoshi_Text_2:
	.string "You seem to have a strong bond with\nyour POKéMON too!$"

CianwoodCity_Gym_Eventscript_BlackBeltLao_Text_0:
	.string "We martial artists fear nothing!$"

CianwoodCity_Gym_Eventscript_BlackBeltLao_Text_1:
	.string "That's shocking!$"

CianwoodCity_Gym_Eventscript_BlackBeltLao_Text_2:
	.string "FIGHTING-type POKéMON are afraid of\nPSYCHIC-types…$"

CianwoodCity_Gym_Eventscript_BlackBeltNob_Text_0:
	.string "Words are useless.\nLet your fists do the talking!$"

CianwoodCity_Gym_Eventscript_BlackBeltNob_Text_1:
	.string "…$"

CianwoodCity_Gym_Eventscript_BlackBeltNob_Text_2:
	.string "I lost!\nI'm speechless!$"

CianwoodCity_Gym_Eventscript_BlackBeltLung_Text_0:
	.string "My raging fists will shatter your\nPOKéMON!$"

CianwoodCity_Gym_Eventscript_BlackBeltLung_Text_1:
	.string "I got shattered!$"

CianwoodCity_Gym_Eventscript_BlackBeltLung_Text_2:
	.string "My POKéMON lost…\nMy… my pride is shattered…$"
