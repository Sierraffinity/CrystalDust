NewBarkTown_ElmsHouse_MapScripts::
	.byte 0

NewBarkTown_ElmsHouse_EventScript_ElmsWife::
	msgbox NewBarkTown_ElmsHouse_Text_ElmsWife, MSGBOX_NPC
	end

NewBarkTown_ElmsHouse_EventScript_ElmsSon::
	msgbox NewBarkTown_ElmsHouse_Text_ElmsSon, MSGBOX_NPC
	end

NewBarkTown_ElmsHouse_EventScript_ResearchPaper::
	msgbox NewBarkTown_ElmsHouse_Text_ResearchPaper, MSGBOX_SIGN
	end

NewBarkTown_ElmsHouse_Text_ElmsWife:
	.string "Hi, {PLAYER}! My husband's always\n"
	.string "so busy--I hope he's okay.\p"
	.string "When he's caught up in his {POKEMON}\n"
	.string "research, he even forgets to eat.$"

NewBarkTown_ElmsHouse_Text_ElmsSon:
	.string "When I grow up, I'm going to\n"
	.string "help my dad!\p"
	.string "I'm going to be a great {POKEMON}\n"
	.string "PROFESSOR!$"

NewBarkTown_ElmsHouse_Text_ResearchPaper:
	.string "{POKEMON}. Where do they come from?\n"
	.string "Where are they going?\p"
	.string "Why has no one ever witnessed a\n"
	.string "{POKEMON}'s birth?\p"
	.string "I want to know! I will dedicate my\n"
	.string "life to the study of {POKEMON}!\p"
	.string "…\p"
	.string "It's a part of PROF. ELM's research\n"
	.string "papers.$"
