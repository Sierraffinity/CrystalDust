RuinsOfAlph_ResearchCenter_MapScripts::
	.byte 0


RuinsOfAlph_ResearchCenter_EventScript_Scientist1::
	lock
	faceplayer
	goto_if_set FLAG_MADE_UNOWN_APPEAR_IN_RUINS, RuinsOfAlph_ResearchCenter_EventScript_Scientist1_2
	msgbox RuinsOfAlph_ResearchCenter_EventScript_Scientist1_Text_1
RuinsOfAlph_ResearchCenter_EventScript_Scientist1_1:
	release
	return

RuinsOfAlph_ResearchCenter_EventScript_Scientist1_2:
	msgbox RuinsOfAlph_ResearchCenter_EventScript_Scientist1_Text_0
	goto RuinsOfAlph_ResearchCenter_EventScript_Scientist1_1


RuinsOfAlph_ResearchCenter_EventScript_Scientist2::
	lock
	faceplayer
	goto_if_set FLAG_MADE_UNOWN_APPEAR_IN_RUINS, RuinsOfAlph_ResearchCenter_EventScript_Scientist2_2
	msgbox RuinsOfAlph_ResearchCenter_EventScript_Scientist2_Text_1
RuinsOfAlph_ResearchCenter_EventScript_Scientist2_1:
	release
	return

RuinsOfAlph_ResearchCenter_EventScript_Scientist2_2:
	msgbox RuinsOfAlph_ResearchCenter_EventScript_Scientist2_Text_0
	goto RuinsOfAlph_ResearchCenter_EventScript_Scientist2_1


RuinsOfAlph_ResearchCenter_EventScript_Scientist3::
	lock
	faceplayer
	msgbox RuinsOfAlph_ResearchCenter_EventScript_Scientist3_Text_0
	release
	return


RuinsOfAlph_ResearchCenter_EventScript_Computer::
	msgbox RuinsOfAlph_ResearchCenter_EventScript_Computer_Text_0, MSGBOX_SIGN
	return


RuinsOfAlph_ResearchCenter_EventScript_Bookshelf::
	msgbox RuinsOfAlph_ResearchCenter_EventScript_Bookshelf_Text_0, MSGBOX_SIGN
	return


RuinsOfAlph_ResearchCenter_EventScript_Printer::
	msgbox RuinsOfAlph_ResearchCenter_EventScript_Printer_Text_0, MSGBOX_SIGN
	return


RuinsOfAlph_ResearchCenter_EventScript_Scientist1_Text_0:
	.string "POKéMON appeared in the RUINS?\n"
	.string "That's incredible news!\l"
	.string "We'll need to investigate this.$"

RuinsOfAlph_ResearchCenter_EventScript_Scientist1_Text_1:
	.string "The RUINS are about 1500\n"
	.string "years old.\p"
	.string "But it's not known why they were\n"
	.string "built--or by whom.$"

RuinsOfAlph_ResearchCenter_EventScript_Scientist2_Text_0:
	.string "The strange POKéMON you saw in\n"
	.string "the RUINS?\p"
	.string "They appear to be very much like the\n"
	.string "drawings on the walls there.\p"
	.string "Hmm…\p"
	.string "That must mean there are many\n"
	.string "kinds of them…$"

RuinsOfAlph_ResearchCenter_EventScript_Scientist2_Text_1:
	.string "There are odd patterns drawn on\n"
	.string "the walls of the RUINS.\p"
	.string "They must be the keys for unraveling\n"
	.string "the mystery of the RUINS.$"

RuinsOfAlph_ResearchCenter_EventScript_Scientist3_Text_0:
	.string "The UNOWN you catch will all be\n"
	.string "recorded in the UNOWN DEX.\p"
	.string "Check to see how many kinds of\n"
	.string "them exist.$"

RuinsOfAlph_ResearchCenter_EventScript_Computer_Text_0:
	.string "RUINS OF ALPH\n"
	.string "Exploration Year 10$"

RuinsOfAlph_ResearchCenter_EventScript_Bookshelf_Text_0:
	.string "There are many academic books on\n"
	.string "the shelves.\p"
	.string "Ancient Ruins…\n"
	.string "Mysteries of the Ancients…$"

RuinsOfAlph_ResearchCenter_EventScript_Printer_Text_0:
	.string "Looks like an old printer.\n"
	.string "It's dusty from disuse…$"
