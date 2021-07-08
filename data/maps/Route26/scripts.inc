Route26_MapScripts::
	.byte 0


Route26_Eventscript_Sign::
	msgbox Route26_Eventscript_Sign_Text_0, MSGBOX_SIGN
	end


Route26_Eventscript_FishermanScott::
	trainerbattle_single TRAINER_SCOTT, Route26_Eventscript_FishermanScott_Text_0, Route26_Eventscript_FishermanScott_Text_1
	msgbox Route26_Eventscript_FishermanScott_Text_2, MSGBOX_AUTOCLOSE
	end


Route26_Eventscript_PsychicRichard::
	trainerbattle_single TRAINER_RICHARD, Route26_Eventscript_PsychicRichard_Text_0, Route26_Eventscript_PsychicRichard_Text_1
	msgbox Route26_Eventscript_PsychicRichard_Text_2, MSGBOX_AUTOCLOSE
	end


Route26_Eventscript_CooltrainerJoyce::
	trainerbattle_single TRAINER_JOYCE, Route26_Eventscript_CooltrainerJoyce_Text_0, Route26_Eventscript_CooltrainerJoyce_Text_1
	msgbox Route26_Eventscript_CooltrainerJoyce_Text_2, MSGBOX_AUTOCLOSE
	end


Route26_Eventscript_CooltrainerGaven::
	trainerbattle_single TRAINER_GAVEN_1, Route26_Eventscript_CooltrainerGaven_Text_0, Route26_Eventscript_CooltrainerGaven_Text_1
	msgbox Route26_Eventscript_CooltrainerGaven_Text_2, MSGBOX_AUTOCLOSE
	end


Route26_Eventscript_CooltrainerJake::
	trainerbattle_single TRAINER_JAKE, Route26_Eventscript_CooltrainerJake_Text_0, Route26_Eventscript_CooltrainerJake_Text_1
	msgbox Route26_Eventscript_CooltrainerJake_Text_2, MSGBOX_AUTOCLOSE
	end


Route26_Eventscript_CooltrainerBeth::
	trainerbattle_single TRAINER_BETH_1, Route26_Eventscript_CooltrainerBeth_Text_0, Route26_Eventscript_CooltrainerBeth_Text_1
	msgbox Route26_Eventscript_CooltrainerBeth_Text_2, MSGBOX_AUTOCLOSE
	end


Route26_Eventscript_Sign_Text_0:
	.string "ROUTE 26\nPOKéMON LEAGUE RECEPTION GATE$"

Route26_Eventscript_FishermanScott_Text_0:
	.string "I'm feeling great today!\pI feel like I could boot even the\nLEAGUE CHAMP!$"

Route26_Eventscript_FishermanScott_Text_1:
	.string "No! Not in this battle!$"

Route26_Eventscript_FishermanScott_Text_2:
	.string "Just like in fishing, it's all over\nin POKéMON if you give up.$"

Route26_Eventscript_PsychicRichard_Text_0:
	.string "Wow, look at all those BADGES!\nI'm impressed.\pBut you're not satisfied by just\ncollecting them, right?$"

Route26_Eventscript_PsychicRichard_Text_1:
	.string "Good battle!$"

Route26_Eventscript_PsychicRichard_Text_2:
	.string "People and POKéMON grow from their\nexperiences.\pDon't get lazy and complacent.$"

Route26_Eventscript_CooltrainerJoyce_Text_0:
	.string "Since you've come this far, you must\nbe good.\pI'm going to give this battle\neverything I've got!$"

Route26_Eventscript_CooltrainerJoyce_Text_1:
	.string "No! I don't believe this!$"

Route26_Eventscript_CooltrainerJoyce_Text_2:
	.string "I've defeated eight GYM LEADERS, so\nI was feeling confident.\pI'll have to try harder next time.$"

Route26_Eventscript_CooltrainerGaven_Text_0:
	.string "By experiencing tough battles, you\ngain power.$"

Route26_Eventscript_CooltrainerGaven_Text_1:
	.string "Gaah! Life is even tougher!$"

Route26_Eventscript_CooltrainerGaven_Text_2:
	.string "To get to the POKéMON LEAGUE, you\nhave to get through VICTORY ROAD.\pBut VICTORY ROAD is tough.\nPractically nobody goes there!$"

Route26_Eventscript_CooltrainerJake_Text_0:
	.string "I'm making my final preparations for\nthe POKéMON LEAGUE.$"

Route26_Eventscript_CooltrainerJake_Text_1:
	.string "I blew it!$"

Route26_Eventscript_CooltrainerJake_Text_2:
	.string "It's going to be tough to win at the\nLEAGUE.\pI need to do some more training.\pI hear that the LEAGUE's ELITE FOUR\nare tougher than GYM LEADERS.$"

Route26_Eventscript_CooltrainerBeth_Text_0:
	.string "I lost to a TRAINER named {RIVAL}.\nHe was really strong, but…\pIt was as if he absolutely had to\nwin at any cost.\pI feel sorry for his POKéMON.$"

Route26_Eventscript_CooltrainerBeth_Text_1:
	.string "POKéMON aren't tools of war.$"

Route26_Eventscript_CooltrainerBeth_Text_2:
	.string "POKéMON are invaluable, lifelong\npartners.$"
