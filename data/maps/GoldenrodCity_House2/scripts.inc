GoldenrodCity_House2_MapScripts::
	.byte 0


GoldenrodCity_House2_EventScript_NoPPMan::
	msgbox GoldenrodCity_House2_EventScript_NoPPMan_Text_0, MSGBOX_NPC
	return


GoldenrodCity_House2_EventScript_PPTipGirl::
	msgbox GoldenrodCity_House2_EventScript_PPTipGirl_Text_0, MSGBOX_NPC
	return


GoldenrodCity_House2_EventScript_NoPPMan_Text_0:
	.string "Once while I was battling, my\n"
	.string "POKéMON couldn't make any moves.\p"
	.string "The POWER POINTS, or PP, of its\n"
	.string "moves were all gone.$"

GoldenrodCity_House2_EventScript_PPTipGirl_Text_0:
	.string "Sometimes, a healthy POKéMON\n"
	.string "may be unable to use its moves.\p"
	.string "If that happens, heal it at a\n"
	.string "POKéMON CENTER or use an item.$"
