RuinsOfAlph_Outside_MapScripts::
	.byte 0


RuinsOfAlph_Outside_EventScript_Boy1::
	msgbox RuinsOfAlph_Outside_EventScript_Boy1_Text_0, MSGBOX_NPC
	return


RuinsOfAlph_Outside_EventScript_Boy2::
	lock
	msgbox RuinsOfAlph_Outside_EventScript_Boy2_Text_0
	turnobject 1, DIR_NORTH
	release
	return


RuinsOfAlph_Outside_EventScript_ScaredMan::
	lock
	faceplayer
	goto_if_set FLAG_TALKED_TO_RUINS_COWARD, RuinsOfAlph_Outside_EventScript_ScaredMan_2
	msgbox RuinsOfAlph_Outside_EventScript_ScaredMan_Text_1
RuinsOfAlph_Outside_EventScript_ScaredMan_1:
	release
	return

RuinsOfAlph_Outside_EventScript_ScaredMan_2:
	msgbox RuinsOfAlph_Outside_EventScript_ScaredMan_Text_0
	goto RuinsOfAlph_Outside_EventScript_ScaredMan_1


RuinsOfAlph_Outside_EventScript_MysteryChamber::
	msgbox RuinsOfAlph_Outside_EventScript_MysteryChamber_Text_0, MSGBOX_SIGN
	return


RuinsOfAlph_Outside_EventScript_Welcome::
	msgbox RuinsOfAlph_Outside_EventScript_Welcome_Text_0, MSGBOX_SIGN
	return


RuinsOfAlph_Outside_EventScript_ResearchCenter::
	msgbox RuinsOfAlph_Outside_EventScript_ResearchCenter_Text_0, MSGBOX_SIGN
	return


RuinsOfAlph_Outside_EventScript_Boy1_Text_0:
	.string "There are many kinds of UNOWN, so\n"
	.string "we use them for our secret codes.$"

RuinsOfAlph_Outside_EventScript_Boy2_Text_0:
	.string "A… H… E… A… D…\n"
	.string "Hm?\p"
	.string "What?\n"
	.string "I'm decoding this message!$"

RuinsOfAlph_Outside_EventScript_ScaredMan_Text_0:
	.string "The RUINS hide a huge secret!\n"
	.string "…I think…$"

RuinsOfAlph_Outside_EventScript_ScaredMan_Text_1:
	.string "While exploring the RUINS, we\n"
	.string "suddenly noticed an odd presence.\p"
	.string "We all got scared and ran away.\n"
	.string "You should be careful, too.\p"
	.string "The RUINS hide a huge secret!\n"
	.string "…I think…$"

RuinsOfAlph_Outside_EventScript_MysteryChamber_Text_0:
	.string "MYSTERY STONE PANEL CHAMBER$"

RuinsOfAlph_Outside_EventScript_Welcome_Text_0:
	.string "RUINS OF ALPH\n"
	.string "VISITORS WELCOME$"

RuinsOfAlph_Outside_EventScript_ResearchCenter_Text_0:
	.string "RUINS OF ALPH RESEARCH CENTER\n"
	.string "THE AUTHORITY ON THE RUINS OF ALPH$"
