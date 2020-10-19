RadioTower_2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RadioTower_2F_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

RadioTower_2F_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	setrespawn HEAL_LOCATION_GOLDENROD_CITY
	goto_if_set FLAG_CLEARED_RADIO_TOWER, RadioTower_2F_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	return

RadioTower_2F_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
	setobjectxyperm 7, 4, 3
	return


RadioTower_2F_EventScript_RadioAnywhereGuy::
	msgbox RadioTower_2F_EventScript_RadioAnywhereGuy_Text_0, MSGBOX_NPC
	return


RadioTower_2F_EventScript_LullabyWoman::
	lock
	faceplayer
	goto_if_set FLAG_ROCKETS_IN_RADIO_TOWER, RadioTower_2F_EventScript_LullabyWoman_2
	msgbox RadioTower_2F_EventScript_LullabyWoman_Text_1
RadioTower_2F_EventScript_LullabyWoman_1:
	release
	return

RadioTower_2F_EventScript_LullabyWoman_2:
	msgbox RadioTower_2F_EventScript_LullabyWoman_Text_0
	goto RadioTower_2F_EventScript_LullabyWoman_1


RadioTower_2F_EventScript_Guard::
	lock
	faceplayer
	goto_if_set FLAG_CLEARED_RADIO_TOWER, RadioTower_2F_EventScript_Guard_2
	msgbox RadioTower_2F_EventScript_Guard_Text_1
RadioTower_2F_EventScript_Guard_1:
	release
	return

RadioTower_2F_EventScript_Guard_2:
	msgbox RadioTower_2F_EventScript_Guard_Text_0
	goto RadioTower_2F_EventScript_Guard_1


RadioTower_2F_EventScript_Jigglypuff::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_JIGGLYPUFF, 0
	msgbox RadioTower_2F_EventScript_Jigglypuff_Text_0
	waitmoncry
	release
	return


RadioTower_2F_EventScript_Buena::
	lock
	faceplayer
	dotimebasedevents
	gettime
	goto_if_set FLAG_ROCKETS_IN_RADIO_TOWER, RadioTower_2F_EventScript_Buena_2
	goto_if_unset FLAG_MET_BUENA, RadioTower_2F_EventScript_Buena_3
	goto_if_set FLAG_DAILY_PLAYED_BUENAS_PASSWORD, RadioTower_2F_EventScript_Buena_4
	compare VAR_0x8000, BUENAS_PASSWORD_START_HOUR
	goto_if_lt RadioTower_2F_EventScript_Buena_5
	goto_if_unset FLAG_BUENAS_PASSWORD_SET, RadioTower_2F_EventScript_Buena_6
	checkitem ITEM_BLUE_CARD, 1
	compare VAR_RESULT, 0
	goto_if_eq RadioTower_2F_EventScript_Buena_13
	compare VAR_BLUE_CARD_BALANCE, BUENAS_PASSWORD_MAX_POINTS
	goto_if_ge RadioTower_2F_EventScript_Buena_14
	playbgm MUS_SAILING, 0
	msgbox RadioTower_2F_EventScript_Buena_Text_6, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq RadioTower_2F_EventScript_Buena_18
	msgbox RadioTower_2F_EventScript_Buena_Text_14
	fadedefaultbgm
	closemessage
	applymovement 9, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
RadioTower_2F_EventScript_Buena_1:
	release
	return

RadioTower_2F_EventScript_Buena_2:
	msgbox RadioTower_2F_EventScript_Buena_Text_0
	goto RadioTower_2F_EventScript_Buena_1

RadioTower_2F_EventScript_Buena_3:
	setflag FLAG_MET_BUENA
	msgbox RadioTower_2F_EventScript_Buena_Text_1
	giveitem ITEM_BLUE_CARD
	call RadioTower_2F_EventScript_Buena_TuneIn
	goto RadioTower_2F_EventScript_Buena_1

RadioTower_2F_EventScript_Buena_4:
	msgbox RadioTower_2F_EventScript_Buena_Text_2
	call RadioTower_2F_EventScript_Buena_OfferNumberIfNotGiven
	goto RadioTower_2F_EventScript_Buena_1

RadioTower_2F_EventScript_Buena_5:
	msgbox RadioTower_2F_EventScript_Buena_Text_3
	call RadioTower_2F_EventScript_Buena_OfferNumberIfNotGiven
	goto RadioTower_2F_EventScript_Buena_1

RadioTower_2F_EventScript_Buena_6:
	call RadioTower_2F_EventScript_Buena_TuneIn
	goto RadioTower_2F_EventScript_Buena_1

RadioTower_2F_EventScript_Buena_13:
	msgbox RadioTower_2F_EventScript_Buena_Text_4
	call RadioTower_2F_EventScript_Buena_OfferNumberIfNotGiven
	goto RadioTower_2F_EventScript_Buena_1

RadioTower_2F_EventScript_Buena_14:
	msgbox RadioTower_2F_EventScript_Buena_Text_5
	call RadioTower_2F_EventScript_Buena_OfferNumberIfNotGiven
	goto RadioTower_2F_EventScript_Buena_1

RadioTower_2F_EventScript_Buena_18:
	msgbox RadioTower_2F_EventScript_Buena_Text_7
	closemessage
	applymovement 9, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	compare VAR_FACING, DIR_EAST
	goto_if_eq RadioTower_2F_EventScript_Buena_22
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
RadioTower_2F_EventScript_Buena_21:
	msgbox RadioTower_2F_EventScript_Buena_Text_8
	applymovement 9, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	message RadioTower_2F_EventScript_Buena_Text_9
	waitmessage
	special BuenasPasswordMultichoice
	waitstate
	setflag FLAG_DAILY_PLAYED_BUENAS_PASSWORD
	compare VAR_RESULT, FALSE
	goto_if_eq RadioTower_2F_EventScript_Buena_26
	message RadioTower_2F_EventScript_Buena_Text_11
	waitmessage
	addvar VAR_BLUE_CARD_BALANCE, 1
	playse SE_SHOP
	waitse
	waitbuttonpress
RadioTower_2F_EventScript_Buena_25:
	applymovement 9, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	msgbox RadioTower_2F_EventScript_Buena_Text_12
	fadedefaultbgm
	closemessage
	compare VAR_BLUE_CARD_BALANCE, BUENAS_PASSWORD_MAX_POINTS
	goto_if_ge RadioTower_2F_EventScript_Buena_29
	goto RadioTower_2F_EventScript_Buena_1

RadioTower_2F_EventScript_Buena_22:
	applymovement OBJ_EVENT_ID_PLAYER, RadioTower_2F_Movement_PlayerToBuenasMic
	waitmovement 0
	goto RadioTower_2F_EventScript_Buena_21

RadioTower_2F_EventScript_Buena_26:
	msgbox RadioTower_2F_EventScript_Buena_Text_10
	goto RadioTower_2F_EventScript_Buena_25

RadioTower_2F_EventScript_Buena_29:
	delay 20
	applymovement 9, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	goto_if_unset FLAG_BUENA_OFFERED_NUMBER, RadioTower_2F_EventScript_Buena_32
	call RadioTower_2F_EventScript_Buena_OfferNumberAgain
RadioTower_2F_EventScript_Buena_31:
	closemessage
	applymovement 9, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	goto RadioTower_2F_EventScript_Buena_1

RadioTower_2F_EventScript_Buena_32:
	playse SE_PIN
	applymovement 9, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	setflag FLAG_BUENA_OFFERED_NUMBER
	msgbox RadioTower_2F_EventScript_Buena_Text_13, MSGBOX_YESNO
	call RadioTower_2F_EventScript_Buena_OfferNumber
	goto RadioTower_2F_EventScript_Buena_31


RadioTower_2F_Movement_PlayerToBuenasMic:
	walk_down
	walk_right
	step_end

RadioTower_2F_EventScript_Buena_TuneIn::
	msgbox RadioTower_2F_EventScript_Buena_TuneIn_Text_0
	call RadioTower_2F_EventScript_Buena_OfferNumberIfNotGiven
	return


RadioTower_2F_EventScript_Buena_OfferNumberIfNotGiven::
	goto_if_set FLAG_BUENA_OFFERED_NUMBER, RadioTower_2F_EventScript_Buena_OfferNumberIfNotGiven_2
RadioTower_2F_EventScript_Buena_OfferNumberIfNotGiven_1:
	closemessage
	applymovement 9, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	return

RadioTower_2F_EventScript_Buena_OfferNumberIfNotGiven_2:
	call RadioTower_2F_EventScript_Buena_OfferNumberAgain
	goto RadioTower_2F_EventScript_Buena_OfferNumberIfNotGiven_1


RadioTower_2F_EventScript_Buena_OfferNumberAgain::
	msgbox RadioTower_2F_EventScript_Buena_OfferNumberAgain_Text_0, MSGBOX_YESNO
	goto RadioTower_2F_EventScript_Buena_OfferNumber
	return


RadioTower_2F_EventScript_Buena_OfferNumber::
	compare VAR_RESULT, NO
	goto_if_eq RadioTower_2F_EventScript_Buena_OfferNumber_1
	return

RadioTower_2F_EventScript_Buena_OfferNumber_1:
	msgbox RadioTower_2F_EventScript_Buena_OfferNumber_Text_0
	return


RadioTower_2F_EventScript_BuenasAssistant::
	lock
	faceplayer
	checkitem ITEM_BLUE_CARD, 1
	compare VAR_RESULT, 0
	goto_if_ne RadioTower_2F_EventScript_BuenasAssistant_2
	msgbox RadioTower_2F_EventScript_BuenasAssistant_Text_1
RadioTower_2F_EventScript_BuenasAssistant_1:
	release
	return

RadioTower_2F_EventScript_BuenasAssistant_2:
	special ShowPointsWindowAtTopLeft
	msgbox RadioTower_2F_EventScript_BuenasAssistant_Text_0
	call RadioTower_2F_EventScript_BuenasAssistantMenu
	goto RadioTower_2F_EventScript_BuenasAssistant_1


RadioTower_2F_EventScript_BuenasAssistantMenu::
	message RadioTower_2F_EventScript_BuenasAssistantMenu_Text_0
	waitmessage
	setvar VAR_0x8004, SCROLL_MULTI_BLUE_CARD_PRIZES
	setvar VAR_0x8005, 0
	setvar VAR_0x8006, FALSE
	special ShowScrollableMultichoice
	waitstate
	switch VAR_RESULT
	case 0, RadioTower_2F_EventScript_BuenasAssistantMenu_3
	case 1, RadioTower_2F_EventScript_BuenasAssistantMenu_4
	case 2, RadioTower_2F_EventScript_BuenasAssistantMenu_5
	case 3, RadioTower_2F_EventScript_BuenasAssistantMenu_6
	case 4, RadioTower_2F_EventScript_BuenasAssistantMenu_7
	case 5, RadioTower_2F_EventScript_BuenasAssistantMenu_8
	case 6, RadioTower_2F_EventScript_BuenasAssistantMenu_9
	case 7, RadioTower_2F_EventScript_BuenasAssistantMenu_10
	case 8, RadioTower_2F_EventScript_BuenasAssistantMenu_11
	case 9, RadioTower_2F_EventScript_BuenasAssistantMenu_12
	case MULTI_B_PRESSED, RadioTower_2F_EventScript_BuenasAssistantMenu_12
RadioTower_2F_EventScript_BuenasAssistantMenu_1:
	bufferitemname 0, VAR_TEMP_1
	msgbox RadioTower_2F_EventScript_BuenasAssistantMenu_Text_2, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq RadioTower_2F_EventScript_BuenasAssistantMenu_14
RadioTower_2F_EventScript_BuenasAssistantMenu_13:
	goto RadioTower_2F_EventScript_BuenasAssistantMenu
	return

RadioTower_2F_EventScript_BuenasAssistantMenu_3:
	setvar VAR_TEMP_1, ITEM_ULTRA_BALL
	setvar VAR_TEMP_2, 2
	goto RadioTower_2F_EventScript_BuenasAssistantMenu_1

RadioTower_2F_EventScript_BuenasAssistantMenu_4:
	setvar VAR_TEMP_1, ITEM_FULL_RESTORE
	setvar VAR_TEMP_2, 2
	goto RadioTower_2F_EventScript_BuenasAssistantMenu_1

RadioTower_2F_EventScript_BuenasAssistantMenu_5:
	setvar VAR_TEMP_1, ITEM_NUGGET
	setvar VAR_TEMP_2, 3
	goto RadioTower_2F_EventScript_BuenasAssistantMenu_1

RadioTower_2F_EventScript_BuenasAssistantMenu_6:
	setvar VAR_TEMP_1, ITEM_RARE_CANDY
	setvar VAR_TEMP_2, 3
	goto RadioTower_2F_EventScript_BuenasAssistantMenu_1

RadioTower_2F_EventScript_BuenasAssistantMenu_7:
	setvar VAR_TEMP_1, ITEM_PROTEIN
	setvar VAR_TEMP_2, 5
	goto RadioTower_2F_EventScript_BuenasAssistantMenu_1

RadioTower_2F_EventScript_BuenasAssistantMenu_8:
	setvar VAR_TEMP_1, ITEM_IRON
	setvar VAR_TEMP_2, 5
	goto RadioTower_2F_EventScript_BuenasAssistantMenu_1

RadioTower_2F_EventScript_BuenasAssistantMenu_9:
	setvar VAR_TEMP_1, ITEM_CARBOS
	setvar VAR_TEMP_2, 5
	goto RadioTower_2F_EventScript_BuenasAssistantMenu_1

RadioTower_2F_EventScript_BuenasAssistantMenu_10:
	setvar VAR_TEMP_1, ITEM_CALCIUM
	setvar VAR_TEMP_2, 5
	goto RadioTower_2F_EventScript_BuenasAssistantMenu_1

RadioTower_2F_EventScript_BuenasAssistantMenu_11:
	setvar VAR_TEMP_1, ITEM_HP_UP
	setvar VAR_TEMP_2, 5
	goto RadioTower_2F_EventScript_BuenasAssistantMenu_1

RadioTower_2F_EventScript_BuenasAssistantMenu_12:
	special HidePointsWindow
	msgbox RadioTower_2F_EventScript_BuenasAssistantMenu_Text_1
	return

RadioTower_2F_EventScript_BuenasAssistantMenu_14:
	compare VAR_BLUE_CARD_BALANCE, VAR_TEMP_2
	goto_if_lt RadioTower_2F_EventScript_BuenasAssistantMenu_16
	additem VAR_TEMP_1
	compare VAR_RESULT, FALSE
	goto_if_eq RadioTower_2F_EventScript_BuenasAssistantMenu_19
	subvar VAR_BLUE_CARD_BALANCE, VAR_TEMP_2
	special UpdatePointsWindow
	playse SE_SHOP
	msgbox RadioTower_2F_EventScript_BuenasAssistantMenu_Text_5
	waitse
	goto RadioTower_2F_EventScript_BuenasAssistantMenu_13

RadioTower_2F_EventScript_BuenasAssistantMenu_16:
	msgbox RadioTower_2F_EventScript_BuenasAssistantMenu_Text_3
	goto RadioTower_2F_EventScript_BuenasAssistantMenu_13

RadioTower_2F_EventScript_BuenasAssistantMenu_19:
	msgbox RadioTower_2F_EventScript_BuenasAssistantMenu_Text_4
	goto RadioTower_2F_EventScript_BuenasAssistantMenu_13


RadioTower_2F_EventScript_PokemonRadioSign::
	msgbox RadioTower_2F_EventScript_PokemonRadioSign_Text_0, MSGBOX_SIGN
	return


RadioTower_2F_EventScript_OaksPkmnTalkSign::
	msgbox RadioTower_2F_EventScript_OaksPkmnTalkSign_Text_0, MSGBOX_SIGN
	return


RadioTower_2F_EventScript_2FSalesSign::
	msgbox RadioTower_2F_EventScript_2FSalesSign_Text_0, MSGBOX_SIGN
	return


RadioTower_2F_EventScript_RadioAnywhereGuy_Text_0:
	.string "You can listen to the radio anywhere.\n"
	.string "Tune in!$"

RadioTower_2F_EventScript_LullabyWoman_Text_0:
	.string "Why would they want to take over\n"
	.string "the RADIO TOWER?$"

RadioTower_2F_EventScript_LullabyWoman_Text_1:
	.string "Lullabies on the radio may make\n"
	.string "POKéMON sleep.$"

RadioTower_2F_EventScript_Guard_Text_0:
	.string "Feel free to look around anywhere.\p"
	.string "The DIRECTOR is nice again, just\n"
	.string "as he was before.$"

RadioTower_2F_EventScript_Guard_Text_1:
	.string "Sorry. Authorized personnel only\n"
	.string "beyond this point.\p"
	.string "It wasn't that way before.\p"
	.string "There's something wrong with the\n"
	.string "DIRECTOR…$"

RadioTower_2F_EventScript_Jigglypuff_Text_0:
	.string "JIGGLYPUFF: Jiggly…$"

RadioTower_2F_EventScript_Buena_Text_0:
	.string "BUENA: Huh?\n"
	.string "Today's password?\p"
	.string "HELP, of course!$"

RadioTower_2F_EventScript_Buena_Text_1:
	.string "BUENA: Hi!\n"
	.string "I'm BUENA!\p"
	.string "Do you know about a radio program\n"
	.string "called PASSWORD?\p"
	.string "If you can tell me the password from\n"
	.string "the program, you will earn points.\p"
	.string "Save up those points and trade them\n"
	.string "to that sweet young lady over\l"
	.string "there for some choice prizes!\p"
	.string "Here you go!\n"
	.string "It's your very own point card!$"

RadioTower_2F_EventScript_Buena_Text_2:
	.string "BUENA: Sorry…\n"
	.string "You get just one chance each day.\p"
	.string "Come back tomorrow for another try!$"

RadioTower_2F_EventScript_Buena_Text_3:
	.string "BUENA: Tune in to PASSWORD every\n"
	.string "night from six to midnight!\p"
	.string "Tune in, then drop in for a visit!$"

RadioTower_2F_EventScript_Buena_Text_4:
	.string "BUENA: Oh? You forgot to bring\n"
	.string "your BLUE CARD?\p"
	.string "I can't give you points if you\n"
	.string "don't have it.$"

RadioTower_2F_EventScript_Buena_Text_5:
	.string "BUENA: Your BLUE CARD's full.\n"
	.string "Trade it in for a fabulous prize!$"

RadioTower_2F_EventScript_Buena_Text_6:
	.string "BUENA: Hi!\n"
	.string "Did you tune in to my radio show?\p"
	.string "Do you remember today's password?$"

RadioTower_2F_EventScript_Buena_Text_7:
	.string "BUENA: Oh, wow! Thank you!\n"
	.string "What was your name again?\p"
	.string "…{PLAYER}, okay!\p"
	.string "Come on, {PLAYER}.\n"
	.string "Join the show!$"

RadioTower_2F_EventScript_Buena_Text_8:
	.string "BUENA: Everyone ready?\p"
	.string "I want to hear you shout out today's\n"
	.string "password for {PLAYER}!$"

RadioTower_2F_EventScript_Buena_Text_9:
	.string "BUENA: So, how about it?\n"
	.string "What's my password?$"

RadioTower_2F_EventScript_Buena_Text_10:
	.string "BUENA: Aww…\n"
	.string "That's not it…\p"
	.string "Did you forget the password?$"

RadioTower_2F_EventScript_Buena_Text_11:
	.string "BUENA: YIPPEE!\n"
	.string "That's right!\p"
	.string "You did tune in!\n"
	.string "I'm so happy!\p"
	.string "You earned one point!\n"
	.string "Congrats!$"

RadioTower_2F_EventScript_Buena_Text_12:
	.string "BUENA: Yup!\n"
	.string "Our contestant was {PLAYER}.\l"
	.string "Thanks for coming!\p"
	.string "I hope all you listeners will\n"
	.string "come too! I'll be waiting!$"

RadioTower_2F_EventScript_Buena_Text_13:
	.string "BUENA: Oh! Your BLUE CARD reached\n"
	.string "30 points today! That's so wild!\p"
	.string "Hmm… There isn't a prize for hitting\n"
	.string "30 points, but…\p"
	.string "You came by so often, {PLAYER}.\n"
	.string "I'll make you a special deal!\p"
	.string "How would you like my phone number?$"

RadioTower_2F_EventScript_Buena_Text_14:
	.string "BUENA: Come back after you\n"
	.string "listen to my show, okay?\p"
	.string "Catch ya later!$"

RadioTower_2F_EventScript_Buena_TuneIn_Text_0:
	.string "BUENA: Tune in to my PASSWORD SHOW!$"

RadioTower_2F_EventScript_Buena_OfferNumberAgain_Text_0:
	.string "BUENA: {PLAYER}, do you want to\n"
	.string "register my phone number?$"

RadioTower_2F_EventScript_Buena_OfferNumber_Text_0:
	.string "BUENA: Aww…\n"
	.string "It's a special prize…$"

RadioTower_2F_EventScript_BuenasAssistant_Text_0:
	.string "You can cash in your saved points\n"
	.string "for a lovely prize of your choice!$"

RadioTower_2F_EventScript_BuenasAssistant_Text_1:
	.string "You can't trade in points without\n"
	.string "your BLUE CARD.\p"
	.string "Don't forget your BLUE CARD!$"

RadioTower_2F_EventScript_BuenasAssistantMenu_Text_0:
	.string "Which prize would you like?$"

RadioTower_2F_EventScript_BuenasAssistantMenu_Text_1:
	.string "Oh.\n"
	.string "Please come back again!$"

RadioTower_2F_EventScript_BuenasAssistantMenu_Text_2:
	.string "{STR_VAR_1}?\n"
	.string "Is that right?$"

RadioTower_2F_EventScript_BuenasAssistantMenu_Text_3:
	.string "You don't have enough points.$"

RadioTower_2F_EventScript_BuenasAssistantMenu_Text_4:
	.string "You have no room for it.$"

RadioTower_2F_EventScript_BuenasAssistantMenu_Text_5:
	.string "Here you go!$"

RadioTower_2F_EventScript_PokemonRadioSign_Text_0:
	.string "Anywhere, Anytime\n"
	.string "POKéMON Radio$"

RadioTower_2F_EventScript_OaksPkmnTalkSign_Text_0:
	.string "PROF. OAK'S POKéMON TALK\n"
	.string "The Hottest Show on the Air!$"

RadioTower_2F_EventScript_2FSalesSign_Text_0:
	.string "2F SALES$"
