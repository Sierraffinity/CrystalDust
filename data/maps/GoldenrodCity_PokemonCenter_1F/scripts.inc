GoldenrodCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, GoldenrodCity_PokemonCenter_1F_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

GoldenrodCity_PokemonCenter_1F_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	setrespawn HEAL_LOCATION_GOLDENROD_CITY
	goto_if_set FLAG_POKECOM_CENTER_ENABLED, GoldenrodCity_PokemonCenter_1F_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	return

GoldenrodCity_PokemonCenter_1F_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
	setobjectmovementtype 2, MOVEMENT_TYPE_FACE_LEFT
	setobjectxyperm 2, 22, 14
	setobjectxyperm 4, 16, 5
	setobjectmovementtype 7, MOVEMENT_TYPE_LOOK_AROUND
	setobjectxyperm 7, 21, 9
	setobjectmovementtype 8, MOVEMENT_TYPE_FACE_LEFT
	setobjectxyperm 8, 32, 4
	setobjectmovementtype 9, MOVEMENT_TYPE_FACE_RIGHT
	setobjectmovementtype 10, MOVEMENT_TYPE_FACE_LEFT
	setobjectxyperm 10, 32, 8
	return


GoldenrodCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, 1
	call GoldenrodCity_PokemonCenter_1F_EventScript_PokecomNurse
	waitmessage
	waitbuttonpress
	release
	return


GoldenrodCity_PokemonCenter_1F_EventScript_PokecomNurse::
	lock
	faceplayer
	setvar VAR_0x8004, 0
	specialvar VAR_RESULT, CountPlayerTrainerStars
	compare VAR_RESULT, 4
	goto_if_eq GoldenrodCity_PokemonCenter_1F_EventScript_PokecomNurse_1
	gettime
	switch VAR_0x8002
	case TIME_MORNING, GoldenrodCity_PokemonCenter_1F_EventScript_PokecomNurse_9
	case TIME_DAY, GoldenrodCity_PokemonCenter_1F_EventScript_PokecomNurse_10
	case TIME_NIGHT, GoldenrodCity_PokemonCenter_1F_EventScript_PokecomNurse_11
GoldenrodCity_PokemonCenter_1F_EventScript_PokecomNurse_7:
	goto Common_EventScript_PkmnCenterNurse_Common
	return

GoldenrodCity_PokemonCenter_1F_EventScript_PokecomNurse_1:
	goto_if_set FLAG_NURSE_MENTIONS_GOLD_CARD, GoldenrodCity_PokemonCenter_1F_EventScript_PokecomNurse_4
	msgbox GoldenrodCity_PokemonCenter_1F_EventScript_PokecomNurse_Text_0, MSGBOX_DEFAULT
	goto EventScript_PkmnCenterNurse_GoldCard_Notice
	return

GoldenrodCity_PokemonCenter_1F_EventScript_PokecomNurse_4:
	goto EventScript_PkmnCenterNurse_AskForUsual
	return

GoldenrodCity_PokemonCenter_1F_EventScript_PokecomNurse_9:
	message GoldenrodCity_PokemonCenter_1F_EventScript_PokecomNurse_Text_1
	goto GoldenrodCity_PokemonCenter_1F_EventScript_PokecomNurse_7

GoldenrodCity_PokemonCenter_1F_EventScript_PokecomNurse_10:
	message GoldenrodCity_PokemonCenter_1F_EventScript_PokecomNurse_Text_2
	goto GoldenrodCity_PokemonCenter_1F_EventScript_PokecomNurse_7

GoldenrodCity_PokemonCenter_1F_EventScript_PokecomNurse_11:
	message GoldenrodCity_PokemonCenter_1F_EventScript_PokecomNurse_Text_3
	goto GoldenrodCity_PokemonCenter_1F_EventScript_PokecomNurse_7


GoldenrodCity_PokemonCenter_1F_EventScript_OldMan::
	goto_if_set FLAG_POKECOM_CENTER_ENABLED, GoldenrodCity_PokemonCenter_1F_EventScript_OldMan_1
	msgbox GoldenrodCity_PokemonCenter_1F_EventScript_OldMan_Text_1, MSGBOX_NPC
	return

GoldenrodCity_PokemonCenter_1F_EventScript_OldMan_1:
	msgbox GoldenrodCity_PokemonCenter_1F_EventScript_OldMan_Text_0, MSGBOX_NPC
	return


GoldenrodCity_PokemonCenter_1F_EventScript_TypeAdvantageGirl::
	msgbox GoldenrodCity_PokemonCenter_1F_EventScript_TypeAdvantageGirl_Text_0, MSGBOX_NPC
	return


GoldenrodCity_PokemonCenter_1F_EventScript_HugeCenterBoy::
	goto_if_set FLAG_POKECOM_CENTER_ENABLED, GoldenrodCity_PokemonCenter_1F_EventScript_HugeCenterBoy_1
	msgbox GoldenrodCity_PokemonCenter_1F_EventScript_HugeCenterBoy_Text_1, MSGBOX_NPC
	return

GoldenrodCity_PokemonCenter_1F_EventScript_HugeCenterBoy_1:
	msgbox GoldenrodCity_PokemonCenter_1F_EventScript_HugeCenterBoy_Text_0, MSGBOX_NPC
	return


GoldenrodCity_PokemonCenter_1F_EventScript_GameBoyKid::
	msgbox GoldenrodCity_PokemonCenter_1F_EventScript_GameBoyKid_Text_0, MSGBOX_NPC
	return


GoldenrodCity_PokemonCenter_1F_EventScript_TradingGirl::
	goto_if_set FLAG_POKECOM_CENTER_ENABLED, GoldenrodCity_PokemonCenter_1F_EventScript_TradingGirl_1
	msgbox GoldenrodCity_PokemonCenter_1F_EventScript_TradingGirl_Text_1, MSGBOX_NPC
	return

GoldenrodCity_PokemonCenter_1F_EventScript_TradingGirl_1:
	msgbox GoldenrodCity_PokemonCenter_1F_EventScript_TradingGirl_Text_0, MSGBOX_NPC
	return


GoldenrodCity_PokemonCenter_1F_EventScript_BugCatcher::
	goto_if_set FLAG_POKECOM_CENTER_ENABLED, GoldenrodCity_PokemonCenter_1F_EventScript_BugCatcher_1
	msgbox GoldenrodCity_PokemonCenter_1F_EventScript_BugCatcher_Text_1, MSGBOX_NPC
	return

GoldenrodCity_PokemonCenter_1F_EventScript_BugCatcher_1:
	msgbox GoldenrodCity_PokemonCenter_1F_EventScript_BugCatcher_Text_0, MSGBOX_NPC
	return


GoldenrodCity_PokemonCenter_1F_EventScript_Youngster::
	goto_if_set FLAG_POKECOM_CENTER_ENABLED, GoldenrodCity_PokemonCenter_1F_EventScript_Youngster_1
	msgbox GoldenrodCity_PokemonCenter_1F_EventScript_Youngster_Text_1, MSGBOX_NPC
	return

GoldenrodCity_PokemonCenter_1F_EventScript_Youngster_1:
	msgbox GoldenrodCity_PokemonCenter_1F_EventScript_Youngster_Text_0, MSGBOX_NPC
	return


GoldenrodCity_PokemonCenter_1F_EventScript_NewsWoman::
	goto_if_set FLAG_POKECOM_CENTER_ENABLED, GoldenrodCity_PokemonCenter_1F_EventScript_NewsWoman_1
	msgbox GoldenrodCity_PokemonCenter_1F_EventScript_NewsWoman_Text_1, MSGBOX_NPC
	return

GoldenrodCity_PokemonCenter_1F_EventScript_NewsWoman_1:
	msgbox GoldenrodCity_PokemonCenter_1F_EventScript_NewsWoman_Text_0, MSGBOX_NPC
	return


GoldenrodCity_PokemonCenter_1F_EventScript_InfoSign::
	msgbox GoldenrodCity_PokemonCenter_1F_EventScript_InfoSign_Text_0, MSGBOX_SIGN
	return


GoldenrodCity_PokemonCenter_1F_EventScript_NewsMachine::
	goto_if_set FLAG_POKECOM_CENTER_ENABLED, GoldenrodCity_PokemonCenter_1F_EventScript_NewsMachine_1
	msgbox GoldenrodCity_PokemonCenter_1F_EventScript_NewsMachine_Text_1, MSGBOX_SIGN
	return

GoldenrodCity_PokemonCenter_1F_EventScript_NewsMachine_1:
	msgbox GoldenrodCity_PokemonCenter_1F_EventScript_NewsMachine_Text_0, MSGBOX_SIGN
	return


GoldenrodCity_PokemonCenter_1F_EventScript_PokecomNurse_Text_0:
	.string "Hello!\p"
	.string "This is the POKéMON COMMUNICATION\n"
	.string "CENTER--or the POKéCOM CENTER.\p"
	.string "We can heal your POKéMON to\n"
	.string "perfect health.\p"
	.string "Shall we…$"

GoldenrodCity_PokemonCenter_1F_EventScript_PokecomNurse_Text_1:
	.string "Good morning!\p"
	.string "This is the POKéMON COMMUNICATION\n"
	.string "CENTER--or the POKéCOM CENTER.\p$"

GoldenrodCity_PokemonCenter_1F_EventScript_PokecomNurse_Text_2:
	.string "Hello!\p"
	.string "This is the POKéMON COMMUNICATION\n"
	.string "CENTER--or the POKéCOM CENTER.\p$"

GoldenrodCity_PokemonCenter_1F_EventScript_PokecomNurse_Text_3:
	.string "Good to see you working so late.\p"
	.string "This is the POKéMON COMMUNICATION\n"
	.string "CENTER--or the POKéCOM CENTER.\p$"

GoldenrodCity_PokemonCenter_1F_EventScript_OldMan_Text_0:
	.string "Just seeing all these new things\n"
	.string "here makes me feel younger!$"

GoldenrodCity_PokemonCenter_1F_EventScript_OldMan_Text_1:
	.string "I came over here when I got word\n"
	.string "that GOLDENROD's POKéMON CENTER\l"
	.string "has new machines that no one's\l"
	.string "ever seen before.\p"
	.string "But it looks like they're still busy\n"
	.string "with all their preparations…$"

GoldenrodCity_PokemonCenter_1F_EventScript_TypeAdvantageGirl_Text_0:
	.string "A higher level POKéMON doesn't\n"
	.string "always win.\p"
	.string "After all, it may have a type\n"
	.string "disadvantage.\p"
	.string "I don't think there is a single\n"
	.string "POKéMON that is the toughest.$"

GoldenrodCity_PokemonCenter_1F_EventScript_HugeCenterBoy_Text_0:
	.string "I thought up a fun new thing for\n"
	.string "the TRADE CORNER!\p"
	.string "I make a PIDGEY hold MAIL, then put\n"
	.string "it up for trade for another one!\p"
	.string "If everyone did that, MAIL could be\n"
	.string "traded with all sorts of people!\p"
	.string "I call it PIDGEY MAIL!\p"
	.string "If it becomes popular, I might make\n"
	.string "lots of new friends!$"

GoldenrodCity_PokemonCenter_1F_EventScript_HugeCenterBoy_Text_1:
	.string "Whoa, this POKéMON CENTER is huge.\n"
	.string "They just built this place.\p"
	.string "They installed lots of new machines\n"
	.string "too.$"

GoldenrodCity_PokemonCenter_1F_EventScript_GameBoyKid_Text_0:
	.string "The COLOSSEUM upstairs is for\n"
	.string "link battles.\p"
	.string "Battle records are posted on the\n"
	.string "wall, so I can't afford to lose.$"

GoldenrodCity_PokemonCenter_1F_EventScript_TradingGirl_Text_0:
	.string "I received a female HOPPIP, but\n"
	.string "it's named STANLEY!\l"
	.string "That's my dad's name!$"

GoldenrodCity_PokemonCenter_1F_EventScript_TradingGirl_Text_1:
	.string "They said you can trade POKéMON\n"
	.string "with total strangers up here.\p"
	.string "But they're still adjusting things.$"

GoldenrodCity_PokemonCenter_1F_EventScript_BugCatcher_Text_0:
	.string "If I get in the NEWS and become\n"
	.string "famous, I bet I'll be adored.\p"
	.string "I wonder how I could get myself\n"
	.string "in the NEWS?$"

GoldenrodCity_PokemonCenter_1F_EventScript_BugCatcher_Text_1:
	.string "The machines here can't be used\n"
	.string "right now.\p"
	.string "Still, it's nice coming to a trendy\n"
	.string "place before other people.$"

GoldenrodCity_PokemonCenter_1F_EventScript_Youngster_Text_0:
	.string "My friend was in the NEWS a while\n"
	.string "back. I was really surprised!$"

GoldenrodCity_PokemonCenter_1F_EventScript_Youngster_Text_1:
	.string "What is the NEWS MACHINE?\p"
	.string "Does it get news from a wider area\n"
	.string "than the radio?$"

GoldenrodCity_PokemonCenter_1F_EventScript_NewsWoman_Text_0:
	.string "I get anxious if I don't check out\n"
	.string "the latest NEWS!$"

GoldenrodCity_PokemonCenter_1F_EventScript_NewsWoman_Text_1:
	.string "The POKéCOM CENTER will link with all\n"
	.string "POKéMON CENTERS in a wireless net.\p"
	.string "That must mean I'll be able to\n"
	.string "link with all sorts of people.$"

GoldenrodCity_PokemonCenter_1F_EventScript_InfoSign_Text_0:
	.string "POKéCOM CENTER\n"
	.string "1F INFORMATION\p"
	.string "Left: ADMINISTRATION\n"
	.string "Center: TRADE CORNER\l"
	.string "Right: POKéMON NEWS$"

GoldenrodCity_PokemonCenter_1F_EventScript_NewsMachine_Text_0:
	.string "It's a POKéMON NEWS MACHINE.\n"
	.string "…and? Why are you here?\l"
	.string "Just to suffer?$"

GoldenrodCity_PokemonCenter_1F_EventScript_NewsMachine_Text_1:
	.string "It's a POKéMON NEWS MACHINE!\n"
	.string "It's not in operation yet…$"
