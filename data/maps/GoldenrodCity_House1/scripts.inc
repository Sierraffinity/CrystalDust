GoldenrodCity_House1_MapScripts::
	.byte 0


GoldenrodCity_House1_EventScript_HappinessRater::
	lock
	faceplayer
	bufferpartymonnick 0, 0
	msgbox GoldenrodCity_House1_EventScript_HappinessRater_Text_0
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	switch VAR_RESULT
	case 6, GoldenrodCity_House1_EventScript_HappinessRater_3
	case 5, GoldenrodCity_House1_EventScript_HappinessRater_4
	case 4, GoldenrodCity_House1_EventScript_HappinessRater_5
	case 3, GoldenrodCity_House1_EventScript_HappinessRater_6
	case 2, GoldenrodCity_House1_EventScript_HappinessRater_7
	msgbox GoldenrodCity_House1_EventScript_HappinessRater_Text_6
GoldenrodCity_House1_EventScript_HappinessRater_1:
	release
	return

GoldenrodCity_House1_EventScript_HappinessRater_3:
	msgbox GoldenrodCity_House1_EventScript_HappinessRater_Text_1
	goto GoldenrodCity_House1_EventScript_HappinessRater_1

GoldenrodCity_House1_EventScript_HappinessRater_4:
	msgbox GoldenrodCity_House1_EventScript_HappinessRater_Text_2
	goto GoldenrodCity_House1_EventScript_HappinessRater_1

GoldenrodCity_House1_EventScript_HappinessRater_5:
	msgbox GoldenrodCity_House1_EventScript_HappinessRater_Text_3
	goto GoldenrodCity_House1_EventScript_HappinessRater_1

GoldenrodCity_House1_EventScript_HappinessRater_6:
	msgbox GoldenrodCity_House1_EventScript_HappinessRater_Text_4
	goto GoldenrodCity_House1_EventScript_HappinessRater_1

GoldenrodCity_House1_EventScript_HappinessRater_7:
	msgbox GoldenrodCity_House1_EventScript_HappinessRater_Text_5
	goto GoldenrodCity_House1_EventScript_HappinessRater_1


GoldenrodCity_House1_EventScript_LoserWoman::
	msgbox GoldenrodCity_House1_EventScript_LoserWoman_Text_0, MSGBOX_NPC
	return


GoldenrodCity_House1_EventScript_ItemGirl::
	msgbox GoldenrodCity_House1_EventScript_ItemGirl_Text_0, MSGBOX_NPC
	return


GoldenrodCity_House1_EventScript_HappinessRater_Text_0:
	.string "If you treat your POKéMON nicely,\n"
	.string "they will love you in return.\p"
	.string "Oh?\n"
	.string "Let me see your {STR_VAR_1}…$"

GoldenrodCity_House1_EventScript_HappinessRater_Text_1:
	.string "It looks really happy!\n"
	.string "It must love you a lot.$"

GoldenrodCity_House1_EventScript_HappinessRater_Text_2:
	.string "I get the feeling that it really\n"
	.string "trusts you.$"

GoldenrodCity_House1_EventScript_HappinessRater_Text_3:
	.string "It's friendly toward you.\n"
	.string "It looks sort of happy.$"

GoldenrodCity_House1_EventScript_HappinessRater_Text_4:
	.string "It's quite cute.$"

GoldenrodCity_House1_EventScript_HappinessRater_Text_5:
	.string "You should treat it better.\n"
	.string "It's not used to you.$"

GoldenrodCity_House1_EventScript_HappinessRater_Text_6:
	.string "It doesn't seem to like you at all.\n"
	.string "It looks mean.$"

GoldenrodCity_House1_EventScript_LoserWoman_Text_0:
	.string "I keep losing in battles, and my\n"
	.string "POKéMON end up fainting…\p"
	.string "Maybe that's why my POKéMON don't\n"
	.string "like me much…$"

GoldenrodCity_House1_EventScript_ItemGirl_Text_0:
	.string "When I use an item on my POKéMON,\n"
	.string "it acts really glad!$"
