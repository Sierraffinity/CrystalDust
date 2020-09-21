RadioTower_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RadioTower_1F_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

RadioTower_1F_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	setflag FLAG_LANDMARK_RADIO_TOWER
	return


RadioTower_1F_EventScript_Receptionist::
	lock
	faceplayer
	goto_if_set FLAG_ROCKETS_IN_RADIO_TOWER, RadioTower_1F_EventScript_Receptionist_2
	msgbox RadioTower_1F_EventScript_Receptionist_Text_1
RadioTower_1F_EventScript_Receptionist_1:
	release
	return

RadioTower_1F_EventScript_Receptionist_2:
	msgbox RadioTower_1F_EventScript_Receptionist_Text_0
	goto RadioTower_1F_EventScript_Receptionist_1


RadioTower_1F_EventScript_LuckyNumberMan::
	lock
	faceplayer
	dotimebasedevents
	compare VAR_POKELOT_PRIZE_ITEM, ITEM_NONE
	goto_if_ne RadioTower_1F_EventScript_LuckyNumberMan_2
	goto_if_set FLAG_DAILY_PICKED_LOTO_TICKET, RadioTower_1F_EventScript_LuckyNumberMan_3
	msgbox RadioTower_1F_EventScript_LuckyNumberMan_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq RadioTower_1F_EventScript_LuckyNumberMan_7
	msgbox RadioTower_1F_EventScript_LuckyNumberMan_Text_11
RadioTower_1F_EventScript_LuckyNumberMan_1:
	release
	return

RadioTower_1F_EventScript_LuckyNumberMan_2:
	goto RadioTower_1F_EventScript_LuckyNumberMan_GivePrizeFromEarlier
	goto RadioTower_1F_EventScript_LuckyNumberMan_1

RadioTower_1F_EventScript_LuckyNumberMan_3:
	goto RadioTower_1F_EventScript_LuckyNumberMan_GameEnded
	goto RadioTower_1F_EventScript_LuckyNumberMan_1

RadioTower_1F_EventScript_LuckyNumberMan_7:
	setflag FLAG_DAILY_PICKED_LOTO_TICKET
	special RetrieveLotteryNumber
	copyvar VAR_0x8008, VAR_RESULT
	special BufferLottoTicketNumber
	msgbox RadioTower_1F_EventScript_LuckyNumberMan_Text_1
	closemessage
	applymovement 5, RadioTower_1F_Movement_LuckyNumberManToPC
	waitmovement 0
	msgbox RadioTower_1F_EventScript_LuckyNumberMan_Text_2
	closemessage
	playse SE_PC_ON
	waitse
	message RadioTower_1F_EventScript_LuckyNumberMan_Text_3
	playfanfare MUS_RG_DEX_RATING
	waitfanfare
	special PickLotteryCornerTicket
	waitmessage
	closemessage
	playse SE_PC_OFF
	waitse
	applymovement 5, RadioTower_1F_Movement_LuckyNumberManToPlayer
	waitmovement 0
	compare VAR_0x8004, 0
	goto_if_eq RadioTower_1F_EventScript_LuckyNumberMan_10
	incrementgamestat GAME_STAT_WON_POKEMON_LOTTERY
	compare VAR_0x8006, 0
	goto_if_eq RadioTower_1F_EventScript_LuckyNumberMan_14
	compare VAR_0x8006, 1
	goto_if_eq RadioTower_1F_EventScript_LuckyNumberMan_15
RadioTower_1F_EventScript_LuckyNumberMan_13:
	bufferitemname 0, VAR_0x8005
	switch VAR_0x8004
	case 1, RadioTower_1F_EventScript_LuckyNumberMan_20
	case 2, RadioTower_1F_EventScript_LuckyNumberMan_21
	case 3, RadioTower_1F_EventScript_LuckyNumberMan_22
	case 4, RadioTower_1F_EventScript_LuckyNumberMan_23
RadioTower_1F_EventScript_LuckyNumberMan_18:
	giveitem VAR_0x8005
	compare VAR_RESULT, FALSE
	goto_if_eq RadioTower_1F_EventScript_LuckyNumberMan_24
	goto RadioTower_1F_EventScript_LuckyNumberMan_GameEnded
	goto RadioTower_1F_EventScript_LuckyNumberMan_1

RadioTower_1F_EventScript_LuckyNumberMan_10:
	msgbox RadioTower_1F_EventScript_LuckyNumberMan_Text_4
	goto RadioTower_1F_EventScript_LuckyNumberMan_1

RadioTower_1F_EventScript_LuckyNumberMan_14:
	msgbox RadioTower_1F_EventScript_LuckyNumberMan_Text_5
	goto RadioTower_1F_EventScript_LuckyNumberMan_13

RadioTower_1F_EventScript_LuckyNumberMan_15:
	msgbox RadioTower_1F_EventScript_LuckyNumberMan_Text_6
	goto RadioTower_1F_EventScript_LuckyNumberMan_13

RadioTower_1F_EventScript_LuckyNumberMan_20:
	msgbox RadioTower_1F_EventScript_LuckyNumberMan_Text_7
	goto RadioTower_1F_EventScript_LuckyNumberMan_18

RadioTower_1F_EventScript_LuckyNumberMan_21:
	msgbox RadioTower_1F_EventScript_LuckyNumberMan_Text_8
	goto RadioTower_1F_EventScript_LuckyNumberMan_18

RadioTower_1F_EventScript_LuckyNumberMan_22:
	msgbox RadioTower_1F_EventScript_LuckyNumberMan_Text_9
	goto RadioTower_1F_EventScript_LuckyNumberMan_18

RadioTower_1F_EventScript_LuckyNumberMan_23:
	msgbox RadioTower_1F_EventScript_LuckyNumberMan_Text_10
	goto RadioTower_1F_EventScript_LuckyNumberMan_18

RadioTower_1F_EventScript_LuckyNumberMan_24:
	copyvar VAR_POKELOT_PRIZE_PLACE, VAR_0x8004
	copyvar VAR_POKELOT_PRIZE_ITEM, VAR_0x8005
	goto RadioTower_1F_EventScript_LuckyNumberMan_NoRoomForPrize
	goto RadioTower_1F_EventScript_LuckyNumberMan_1


RadioTower_1F_Movement_LuckyNumberManToPC:
	walk_right
	face_up
	step_end

RadioTower_1F_Movement_LuckyNumberManToPlayer:
	walk_left
	face_up
	step_end

RadioTower_1F_EventScript_LuckyNumberMan_GivePrizeFromEarlier::
	msgbox RadioTower_1F_EventScript_LuckyNumberMan_GivePrizeFromEarlier_Text_0
	giveitem VAR_POKELOT_PRIZE_ITEM
	compare VAR_RESULT, FALSE
	goto_if_eq RadioTower_1F_EventScript_LuckyNumberMan_GivePrizeFromEarlier_1
	setvar VAR_POKELOT_PRIZE_ITEM, ITEM_NONE
	setvar VAR_POKELOT_PRIZE_PLACE, 0
	goto RadioTower_1F_EventScript_LuckyNumberMan_GameEnded
	return

RadioTower_1F_EventScript_LuckyNumberMan_GivePrizeFromEarlier_1:
	goto RadioTower_1F_EventScript_LuckyNumberMan_NoRoomForPrize
	return


RadioTower_1F_EventScript_LuckyNumberMan_NoRoomForPrize::
	msgbox RadioTower_1F_EventScript_LuckyNumberMan_NoRoomForPrize_Text_0
	release
	return


RadioTower_1F_EventScript_LuckyNumberMan_GameEnded::
	msgbox RadioTower_1F_EventScript_LuckyNumberMan_GameEnded_Text_0
	release
	return


RadioTower_1F_EventScript_RadioCardWoman::
	lock
	faceplayer
	goto_if_set FLAG_SYS_HAS_RADIO_CARD, RadioTower_1F_EventScript_RadioCardWoman_2
RadioTower_1F_EventScript_RadioCardWoman_1:
	msgbox RadioTower_1F_EventScript_RadioCardWoman_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq RadioTower_1F_EventScript_RadioCardWoman_5
	msgbox RadioTower_1F_EventScript_RadioCardWoman_Text_10
RadioTower_1F_EventScript_RadioCardWoman_4:
	release
	return

RadioTower_1F_EventScript_RadioCardWoman_2:
	goto RadioTower_1F_EventScript_RadioCardWoman_EndQuiz
	goto RadioTower_1F_EventScript_RadioCardWoman_1

RadioTower_1F_EventScript_RadioCardWoman_5:
	msgbox RadioTower_1F_EventScript_RadioCardWoman_Text_1, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq RadioTower_1F_EventScript_RadioCardWoman_9
RadioTower_1F_EventScript_RadioCardWoman_8:
	msgbox RadioTower_1F_EventScript_RadioCardWoman_Text_9
	goto RadioTower_1F_EventScript_RadioCardWoman_4

RadioTower_1F_EventScript_RadioCardWoman_9:
	playse SE_DING_DONG
	waitse
	msgbox RadioTower_1F_EventScript_RadioCardWoman_Text_2, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq RadioTower_1F_EventScript_RadioCardWoman_11
	goto RadioTower_1F_EventScript_RadioCardWoman_8

RadioTower_1F_EventScript_RadioCardWoman_11:
	playse SE_DING_DONG
	waitse
	msgbox RadioTower_1F_EventScript_RadioCardWoman_Text_3, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq RadioTower_1F_EventScript_RadioCardWoman_13
	goto RadioTower_1F_EventScript_RadioCardWoman_8

RadioTower_1F_EventScript_RadioCardWoman_13:
	playse SE_DING_DONG
	waitse
	msgbox RadioTower_1F_EventScript_RadioCardWoman_Text_4, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq RadioTower_1F_EventScript_RadioCardWoman_15
	goto RadioTower_1F_EventScript_RadioCardWoman_8

RadioTower_1F_EventScript_RadioCardWoman_15:
	playse SE_DING_DONG
	waitse
	msgbox RadioTower_1F_EventScript_RadioCardWoman_Text_5, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq RadioTower_1F_EventScript_RadioCardWoman_17
	goto RadioTower_1F_EventScript_RadioCardWoman_8

RadioTower_1F_EventScript_RadioCardWoman_17:
	playse SE_DING_DONG
	waitse
	msgbox RadioTower_1F_EventScript_RadioCardWoman_Text_6
	textcolor MSG_COLOR_BLACK
	playfanfare MUS_OBTAIN_ITEM
	setflag FLAG_SYS_HAS_RADIO_CARD
	message RadioTower_1F_EventScript_RadioCardWoman_Text_7
	waitfanfare
	msgbox RadioTower_1F_EventScript_RadioCardWoman_Text_8
	call EventScript_RestorePrevTextColor
	goto RadioTower_1F_EventScript_RadioCardWoman_EndQuiz
	goto RadioTower_1F_EventScript_RadioCardWoman_8


RadioTower_1F_EventScript_RadioCardWoman_EndQuiz::
	msgbox RadioTower_1F_EventScript_RadioCardWoman_EndQuiz_Text_0
	release
	return


RadioTower_1F_EventScript_MaryLoverBoy::
	msgbox RadioTower_1F_EventScript_MaryLoverBoy_Text_0, MSGBOX_NPC
	return


RadioTower_1F_EventScript_BenLoverGirl::
	msgbox RadioTower_1F_EventScript_BenLoverGirl_Text_0, MSGBOX_NPC
	return


RadioTower_1F_EventScript_DirectorySign::
	msgbox RadioTower_1F_EventScript_DirectorySign_Text_0, MSGBOX_SIGN
	return


RadioTower_1F_EventScript_LuckyChannelSign::
	msgbox RadioTower_1F_EventScript_LuckyChannelSign_Text_0, MSGBOX_SIGN
	return


RadioTower_1F_EventScript_Receptionist_Text_0:
	.string "Hello. I'm sorry, but we're not\n"
	.string "offering any tours today.$"

RadioTower_1F_EventScript_Receptionist_Text_1:
	.string "Welcome!$"

RadioTower_1F_EventScript_LuckyNumberMan_Text_0:
	.string "Hi, are you here for the LUCKY\n"
	.string "NUMBER SHOW?\p"
	.string "Want me to check the ID numbers\n"
	.string "of your POKéMON?\p"
	.string "If you get lucky, you win a prize.\n"
	.string "How about it?$"

RadioTower_1F_EventScript_LuckyNumberMan_Text_1:
	.string "Today's ID number is {STR_VAR_1}.$"

RadioTower_1F_EventScript_LuckyNumberMan_Text_2:
	.string "Let's see if you have a match.$"

RadioTower_1F_EventScript_LuckyNumberMan_Text_3:
	.string "…{PAUSE 0x0F}{PAUSE 0x0F}{PAUSE 0x0F}{PAUSE 0x0F}…{PAUSE 0x0F}{PAUSE 0x0F}{PAUSE 0x0F}{PAUSE 0x0F}…{PAUSE 0x0F}{PAUSE 0x0F}{PAUSE 0x0F}{PAUSE 0x0F}$"

RadioTower_1F_EventScript_LuckyNumberMan_Text_4:
	.string "Nope, none of your ID numbers match.\n"
	.string "Please try again tomorrow!$"

RadioTower_1F_EventScript_LuckyNumberMan_Text_5:
	.string "Congratulations!\p"
	.string "The ID number of your team's\n"
	.string "{STR_VAR_1} matches today's\l"
	.string "LUCKY NUMBER!$"

RadioTower_1F_EventScript_LuckyNumberMan_Text_6:
	.string "Congratulations!\p"
	.string "The ID number of your PC-boxed\n"
	.string "{STR_VAR_1} matches today's\l"
	.string "LUCKY NUMBER!$"

RadioTower_1F_EventScript_LuckyNumberMan_Text_7:
	.string "Ooh, two digits matched.\p"
	.string "You've won the third prize,\n"
	.string "the {STR_VAR_1}!$"

RadioTower_1F_EventScript_LuckyNumberMan_Text_8:
	.string "Hey!\n"
	.string "You matched three digits!\p"
	.string "You've won the second prize,\n"
	.string "the {STR_VAR_1}!$"

RadioTower_1F_EventScript_LuckyNumberMan_Text_9:
	.string "Nice!\n"
	.string "Four digits matched up!\p"
	.string "You've won the first prize,\n"
	.string "the {STR_VAR_1}!$"

RadioTower_1F_EventScript_LuckyNumberMan_Text_10:
	.string "Wow! You have a perfect match\n"
	.string "of all five digits!\p"
	.string "We have a grand prize winner!\n"
	.string "You've won the {STR_VAR_1}!$"

RadioTower_1F_EventScript_LuckyNumberMan_Text_11:
	.string "Please do visit again.$"

RadioTower_1F_EventScript_LuckyNumberMan_GivePrizeFromEarlier_Text_0:
	.string "Ah, {PLAYER}!\n"
	.string "Yes, I've been expecting you.\p"
	.string "This is the prize we've been holding\n"
	.string "for you.$"

RadioTower_1F_EventScript_LuckyNumberMan_NoRoomForPrize_Text_0:
	.string "You've got no room for your prize.\n"
	.string "Make room and come back right away!$"

RadioTower_1F_EventScript_LuckyNumberMan_GameEnded_Text_0:
	.string "Please come back tomorrow for\n"
	.string "the next LUCKY NUMBER.$"

RadioTower_1F_EventScript_RadioCardWoman_Text_0:
	.string "We have a special quiz campaign\n"
	.string "going on right now.\p"
	.string "Answer five questions correctly\n"
	.string "to win a RADIO CARD.\p"
	.string "Slide it into your POKéGEAR to play\n"
	.string "the radio anytime, anywhere.\p"
	.string "Would you like to take the quiz?$"

RadioTower_1F_EventScript_RadioCardWoman_Text_1:
	.string "Question 1:\p"
	.string "Is there a POKéMON that appears\n"
	.string "only in the morning?$"

RadioTower_1F_EventScript_RadioCardWoman_Text_2:
	.string "Correct!\n"
	.string "Question 2:\p"
	.string "Is this statement correct?\n"
	.string "“You can't buy a BERRY at a MART.”$"

RadioTower_1F_EventScript_RadioCardWoman_Text_3:
	.string "Bull's-eye!\n"
	.string "Question 3:\p"
	.string "Does HM01 contain the move FLASH?$"

RadioTower_1F_EventScript_RadioCardWoman_Text_4:
	.string "So far so good!\n"
	.string "Question 4:\p"
	.string "Is FALKNER the VIOLET GYM LEADER\n"
	.string "who uses BIRD POKéMON?$"

RadioTower_1F_EventScript_RadioCardWoman_Text_5:
	.string "Wow! Right again!\n"
	.string "Here's the final question:\p"
	.string "Do GOLDENROD GAME CORNER's slots\n"
	.string "have CHARMANDER on their reels?$"

RadioTower_1F_EventScript_RadioCardWoman_Text_6:
	.string "Bingo! You got it!\n"
	.string "Congratulations!\p"
	.string "Here's your prize, a RADIO CARD!$"

RadioTower_1F_EventScript_RadioCardWoman_Text_7:
	.string "{PLAYER} received the RADIO CARD\n"
	.string "from the receptionist.$"

RadioTower_1F_EventScript_RadioCardWoman_Text_8:
	.string "{PLAYER}'s POKéGEAR can now double\n"
	.string "as a radio!$"

RadioTower_1F_EventScript_RadioCardWoman_Text_9:
	.string "Oh, dear.\n"
	.string "Sorry, but you got it wrong.\l"
	.string "Please try again!$"

RadioTower_1F_EventScript_RadioCardWoman_Text_10:
	.string "Oh.\n"
	.string "I see.\p"
	.string "Please come back and see me if\n"
	.string "you change your mind.$"

RadioTower_1F_EventScript_RadioCardWoman_EndQuiz_Text_0:
	.string "Please tune in to our radio shows.$"

RadioTower_1F_EventScript_MaryLoverBoy_Text_0:
	.string "I love MARY, from POKéMON TALK.\p"
	.string "I only know what she sounds like,\n"
	.string "though.$"

RadioTower_1F_EventScript_BenLoverGirl_Text_0:
	.string "BEN is a fabulous DJ.\n"
	.string "His sweet voice makes me melt!$"

RadioTower_1F_EventScript_DirectorySign_Text_0:
	.string "1F RECEPTION\n"
	.string "2F SALES\l"
	.string "3F PERSONNEL\l"
	.string "4F PRODUCTION\l"
	.string "5F DIRECTOR'S OFFICE$"

RadioTower_1F_EventScript_LuckyChannelSign_Text_0:
	.string "LUCKY CHANNEL!\n"
	.string "Win with POKéMON ID numbers!\p"
	.string "Trade your POKéMON to collect\n"
	.string "different ID numbers!$"
