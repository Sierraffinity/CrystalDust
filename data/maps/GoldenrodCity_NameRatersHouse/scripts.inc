GoldenrodCity_NameRatersHouse_MapScripts::
	.byte 0


GoldenrodCity_NameRatersHouse_EventScript_NameRater::
	lock
	faceplayer
	msgbox GoldenrodCity_NameRatersHouse_EventScript_NameRater_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq GoldenrodCity_NameRatersHouse_EventScript_NameRater_2
	goto GoldenrodCity_NameRatersHouse_EventScript_NameRater_Cancel
GoldenrodCity_NameRatersHouse_EventScript_NameRater_1:
	release
	return

GoldenrodCity_NameRatersHouse_EventScript_NameRater_2:
	msgbox GoldenrodCity_NameRatersHouse_EventScript_NameRater_Text_1
	special ChoosePartyMon
	waitstate
	compare VAR_0x8004, 0xFF
	goto_if_ne GoldenrodCity_NameRatersHouse_EventScript_NameRater_5
	goto GoldenrodCity_NameRatersHouse_EventScript_NameRater_Cancel
	goto GoldenrodCity_NameRatersHouse_EventScript_NameRater_1

GoldenrodCity_NameRatersHouse_EventScript_NameRater_5:
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	compare VAR_RESULT, SPECIES_EGG
	goto_if_eq GoldenrodCity_NameRatersHouse_EventScript_NameRater_8
	bufferpartymonnick 0, VAR_0x8004
	special IsMonOTIDNotPlayers
	compare VAR_RESULT, TRUE
	goto_if_eq GoldenrodCity_NameRatersHouse_EventScript_NameRater_11
	specialvar VAR_RESULT, MonOTNameNotPlayer
	bufferpartymonnick 0, VAR_0x8004
	compare VAR_RESULT, TRUE
	goto_if_eq GoldenrodCity_NameRatersHouse_EventScript_NameRater_14
	msgbox GoldenrodCity_NameRatersHouse_EventScript_NameRater_Text_3, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq GoldenrodCity_NameRatersHouse_EventScript_NameRater_17
	goto GoldenrodCity_NameRatersHouse_EventScript_NameRater_Cancel
	goto GoldenrodCity_NameRatersHouse_EventScript_NameRater_1

GoldenrodCity_NameRatersHouse_EventScript_NameRater_8:
	msgbox GoldenrodCity_NameRatersHouse_EventScript_NameRater_Text_2
	goto GoldenrodCity_NameRatersHouse_EventScript_NameRater_1

GoldenrodCity_NameRatersHouse_EventScript_NameRater_11:
	goto GoldenrodCity_NameRatersHouse_EventScript_NameRater_OTMismatch
	goto GoldenrodCity_NameRatersHouse_EventScript_NameRater_1

GoldenrodCity_NameRatersHouse_EventScript_NameRater_14:
	goto GoldenrodCity_NameRatersHouse_EventScript_NameRater_OTMismatch
	goto GoldenrodCity_NameRatersHouse_EventScript_NameRater_1

GoldenrodCity_NameRatersHouse_EventScript_NameRater_17:
	msgbox GoldenrodCity_NameRatersHouse_EventScript_NameRater_Text_4
	call Common_EventScript_NameReceivedPartyMon
	bufferpartymonnick 0, VAR_0x8004
	specialvar VAR_RESULT, NameRaterWasNicknameChanged
	compare VAR_RESULT, TRUE
	goto_if_eq GoldenrodCity_NameRatersHouse_EventScript_NameRater_20
	msgbox GoldenrodCity_NameRatersHouse_EventScript_NameRater_Text_6
	goto GoldenrodCity_NameRatersHouse_EventScript_NameRater_1

GoldenrodCity_NameRatersHouse_EventScript_NameRater_20:
	msgbox GoldenrodCity_NameRatersHouse_EventScript_NameRater_Text_5
	goto GoldenrodCity_NameRatersHouse_EventScript_NameRater_1


GoldenrodCity_NameRatersHouse_EventScript_NameRater_Cancel::
	msgbox GoldenrodCity_NameRatersHouse_EventScript_NameRater_Cancel_Text_0
	release
	return


GoldenrodCity_NameRatersHouse_EventScript_NameRater_OTMismatch::
	msgbox GoldenrodCity_NameRatersHouse_EventScript_NameRater_OTMismatch_Text_0
	release
	return


GoldenrodCity_NameRatersHouse_EventScript_NameRater_Text_0:
	.string "Hello, hello!\n"
	.string "I'm the NAME RATER.\p"
	.string "I rate the names of POKéMON.\n"
	.string "Would you like me to rate names?$"

GoldenrodCity_NameRatersHouse_EventScript_NameRater_Text_1:
	.string "Which POKéMON's nickname should\n"
	.string "I rate for you?$"

GoldenrodCity_NameRatersHouse_EventScript_NameRater_Text_2:
	.string "Whoa…\n"
	.string "That's just an EGG.$"

GoldenrodCity_NameRatersHouse_EventScript_NameRater_Text_3:
	.string "Hm… {STR_VAR_1}…\n"
	.string "That's a fairly decent name.\p"
	.string "But, how about a slightly better\n"
	.string "nickname?\p"
	.string "Want me to give it a better name?$"

GoldenrodCity_NameRatersHouse_EventScript_NameRater_Text_4:
	.string "All right.\n"
	.string "What name should we give it, then?$"

GoldenrodCity_NameRatersHouse_EventScript_NameRater_Text_5:
	.string "Done! From now on, this POKéMON\n"
	.string "shall be known as {STR_VAR_1}!\p"
	.string "That's a better name than before!\n"
	.string "Well done!$"

GoldenrodCity_NameRatersHouse_EventScript_NameRater_Text_6:
	.string "Done! From now on, this POKéMON\n"
	.string "shall be known as {STR_VAR_1}!\p"
	.string "It might look the same as before,\n"
	.string "but this new name is much better!\l"
	.string "Well done!$"

GoldenrodCity_NameRatersHouse_EventScript_NameRater_Cancel_Text_0:
	.string "Okay, then.\n"
	.string "Come again sometime.$"

GoldenrodCity_NameRatersHouse_EventScript_NameRater_OTMismatch_Text_0:
	.string "Hm… {STR_VAR_1}?\n"
	.string "What a great name!\p"
	.string "It's perfect. Treat {STR_VAR_1}\n"
	.string "with loving care.$"
