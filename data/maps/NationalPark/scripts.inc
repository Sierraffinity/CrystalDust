NationalPark_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, NationalPark_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

NationalPark_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	setflag FLAG_LANDMARK_NATIONAL_PARK
	return


NationalPark_EventScript_CardsGirl::
	msgbox NationalPark_EventScript_CardsGirl_Text_0, MSGBOX_NPC
	return


NationalPark_EventScript_MailWoman::
	msgbox NationalPark_EventScript_MailWoman_Text_0, MSGBOX_NPC
	return


NationalPark_EventScript_QuickClawTeacher::
	lock
	faceplayer
	goto_if_unset FLAG_GOT_QUICK_CLAW, NationalPark_EventScript_QuickClawTeacher_2
NationalPark_EventScript_QuickClawTeacher_1:
	msgbox NationalPark_EventScript_QuickClawTeacher_Text_1
	release
	return

NationalPark_EventScript_QuickClawTeacher_2:
	msgbox NationalPark_EventScript_QuickClawTeacher_Text_0
	giveitem ITEM_QUICK_CLAW
	compare VAR_RESULT, 0
	goto_if_eq NationalPark_EventScript_QuickClawTeacher_4
	setflag FLAG_GOT_QUICK_CLAW
	goto NationalPark_EventScript_QuickClawTeacher_1

NationalPark_EventScript_QuickClawTeacher_4:
	goto Common_EventScript_ShowBagIsFull
	goto NationalPark_EventScript_QuickClawTeacher_1


NationalPark_EventScript_Youngster1::
	msgbox NationalPark_EventScript_Youngster1_Text_0, MSGBOX_NPC
	return


NationalPark_EventScript_Youngster2::
	msgbox NationalPark_EventScript_Youngster2_Text_0, MSGBOX_NPC
	return


NationalPark_EventScript_ScaredWoman::
	msgbox NationalPark_EventScript_ScaredWoman_Text_0, MSGBOX_NPC
	return


NationalPark_EventScript_Persian::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PERSIAN, 0
	msgbox NationalPark_EventScript_Persian_Text_0
	waitmoncry
	release
	return


NationalPark_EventScript_Jack::
	trainerbattle_single TRAINER_JACK, NationalPark_Text_JackIntro, NationalPark_Text_JackDefeated
	msgbox NationalPark_Text_JackPostBattle, MSGBOX_AUTOCLOSE
	return


NationalPark_EventScript_Beverly::
	trainerbattle_single TRAINER_BEVERLY, NationalPark_Text_BeverlyIntro, NationalPark_Text_BeverlyDefeated
	msgbox NationalPark_Text_BeverlyPostBattle, MSGBOX_AUTOCLOSE
	return


NationalPark_EventScript_William::
	trainerbattle_single TRAINER_WILLIAM, NationalPark_Text_WilliamIntro, NationalPark_Text_WilliamDefeated
	msgbox NationalPark_Text_WilliamPostBattle, MSGBOX_AUTOCLOSE
	return


NationalPark_EventScript_Krise::
	trainerbattle_single TRAINER_KRISE, NationalPark_Text_KriseIntro, NationalPark_Text_KriseDefeated
	msgbox NationalPark_Text_KrisePostBattle, MSGBOX_AUTOCLOSE
	return


NationalPark_EventScript_GameboyKid::
	lock
	faceplayer
	msgbox NationalPark_EventScript_GameboyKid_Text_0
	turnobject 13, DIR_SOUTH
	release
	return


NationalPark_EventScript_RelaxationSquare::
	msgbox NationalPark_EventScript_RelaxationSquare_Text_0, MSGBOX_SIGN
	return


NationalPark_EventScript_BattleNotice::
	msgbox NationalPark_EventScript_BattleNotice_Text_0, MSGBOX_SIGN
	return


NationalPark_EventScript_TrainerTips::
	msgbox NationalPark_EventScript_TrainerTips_Text_0, MSGBOX_SIGN
	return


NationalPark_EventScript_CardsGirl_Text_0:
	.string "Look!\n"
	.string "Check out my cards!\p"
	.string "They have special barcodes on them\n"
	.string "that you can scan with the e-Reader.$"

NationalPark_EventScript_MailWoman_Text_0:
	.string "This is MAIL I got from my daughter.\n"
	.string "It cheers me up.$"

NationalPark_EventScript_QuickClawTeacher_Text_0:
	.string "Pay attention, please!\p"
	.string "…Oops, I have to quit thinking like\n"
	.string "a teacher all the time.\p"
	.string "You must be a POKéMON TRAINER.\p"
	.string "Since you're working so hard, I\n"
	.string "want you to have this.$"

NationalPark_EventScript_QuickClawTeacher_Text_1:
	.string "Let one of your POKéMON hold that\n"
	.string "QUICK CLAW.\p"
	.string "Sometimes it will strike first\n"
	.string "during battle.$"

NationalPark_EventScript_Youngster1_Text_0:
	.string "I'm playing with cards that have\n"
	.string "a stripe down the side.\p"
	.string "You can scan them and see POKéMON\n"
	.string "stats on the screen!$"

NationalPark_EventScript_Youngster2_Text_0:
	.string "I get the other guy's POKéMON\n"
	.string "cards if I win.$"

NationalPark_EventScript_ScaredWoman_Text_0:
	.string "I take walks in the PARK, but I\n"
	.string "never go into the grass.\l"
	.string "TRAINERS always want to battle…$"

NationalPark_EventScript_Persian_Text_0:
	.string "PERSIAN: Fufushaa!$"

NationalPark_EventScript_GameboyKid_Text_0:
	.string "Hey, do you know how to get my\n"
	.string "e-Reader to read this card?\p"
	.string "I keep swiping and getting read\n"
	.string "errors and-{PLAY_SE SE_INTRO_LOGO_DING}{PAUSE 30}oh! It scanned!$"

NationalPark_EventScript_RelaxationSquare_Text_0:
	.string "RELAXATION SQUARE\n"
	.string "NATIONAL PARK$"

NationalPark_EventScript_BattleNotice_Text_0:
	.string "What is this notice?\p"
	.string "Please battle only in the grass.\n"
	.string "NATIONAL PARK WARDEN'S OFFICE$"

NationalPark_EventScript_TrainerTips_Text_0:
	.string "TRAINER TIPS\p"
	.string "Scan cards using your e-Reader to\n"
	.string "download exciting events with\l"
	.string "MYSTERY EVENT.$"
