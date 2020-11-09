Route35_GoldenrodGatehouse_MapScripts::
	.byte 0


Route35_GoldenrodGatehouse_EventScript_Officer::
	lock
	faceplayer
	goto_if_set FLAG_GOT_HP_UP_FROM_RANDY, Route35_GoldenrodGatehouse_EventScript_Officer_2
	goto_if_set FLAG_GAVE_KENYA_TO_RANDYS_FRIEND, Route35_GoldenrodGatehouse_EventScript_Officer_3
	goto_if_set FLAG_GOT_KENYA_FROM_RANDY, Route35_GoldenrodGatehouse_EventScript_Officer_4
	msgbox Route35_GoldenrodGatehouse_EventScript_Officer_Text_1, MSGBOX_YESNO
	compare VAR_RESULT, TRUE
	goto_if_eq Route35_GoldenrodGatehouse_EventScript_Officer_12
	msgbox Route35_GoldenrodGatehouse_EventScript_Officer_Text_5
Route35_GoldenrodGatehouse_EventScript_Officer_1:
	release
	return

Route35_GoldenrodGatehouse_EventScript_Officer_2:
	msgbox Route35_GoldenrodGatehouse_Text_Officer_PalWasSnoozing
	goto Route35_GoldenrodGatehouse_EventScript_Officer_1

Route35_GoldenrodGatehouse_EventScript_Officer_3:
	msgbox Route35_GoldenrodGatehouse_EventScript_Officer_Text_0
	giveitem ITEM_HP_UP, 1
	compare VAR_RESULT, 0
	goto_if_eq Route35_GoldenrodGatehouse_EventScript_Officer_10
Route35_GoldenrodGatehouse_EventScript_Officer_9:
	msgbox Route35_GoldenrodGatehouse_Text_Officer_PalWasSnoozing
	setflag FLAG_GOT_HP_UP_FROM_RANDY
	goto Route35_GoldenrodGatehouse_EventScript_Officer_1

Route35_GoldenrodGatehouse_EventScript_Officer_4:
	msgbox Route35_GoldenrodGatehouse_Text_Officer_ReadItButDontLoseIt
	goto Route35_GoldenrodGatehouse_EventScript_Officer_1

Route35_GoldenrodGatehouse_EventScript_Officer_10:
	goto Common_EventScript_ShowBagIsFull
	goto Route35_GoldenrodGatehouse_EventScript_Officer_9

Route35_GoldenrodGatehouse_EventScript_Officer_12:
	msgbox Route35_GoldenrodGatehouse_EventScript_Officer_Text_2
	setvar VAR_0x8004, INGAME_TRADE_GIFT_KENYA
	special GivePlayerSpecialGiftMon
	compare VAR_RESULT, 0
	goto_if_eq Route35_GoldenrodGatehouse_EventScript_Officer_15
	textcolor MSG_COLOR_SYS
	playfanfare MUS_OBTAIN_ITEM
	message Route35_GoldenrodGatehouse_EventScript_Officer_Text_4
	waitmessage
	waitfanfare
	call EventScript_RestorePrevTextColor
	msgbox Route35_GoldenrodGatehouse_Text_Officer_ReadItButDontLoseIt
	setflag FLAG_GOT_KENYA_FROM_RANDY
	goto Route35_GoldenrodGatehouse_EventScript_Officer_1

Route35_GoldenrodGatehouse_EventScript_Officer_15:
	msgbox Route35_GoldenrodGatehouse_EventScript_Officer_Text_3
	goto Route35_GoldenrodGatehouse_EventScript_Officer_1


Route35_GoldenrodGatehouse_EventScript_ConcernedWoman::
	return


Route35_GoldenrodGatehouse_EventScript_CuriousMan::
	return


Route35_GoldenrodGatehouse_EventScript_Officer_Text_0:
	.string "Thanks, kid! You made the delivery\n"
	.string "for me!\p"
	.string "Here's something for your trouble!$"

Route35_GoldenrodGatehouse_EventScript_Officer_Text_1:
	.string "Excuse me, kid!\n"
	.string "Can you do a guy a favor?\p"
	.string "Can you take this POKéMON with MAIL\n"
	.string "to my friend? He's on ROUTE 31.$"

Route35_GoldenrodGatehouse_EventScript_Officer_Text_2:
	.string "You will? Perfect!\n"
	.string "Thanks, kid!\p"
	.string "My pal's a chubby guy who snoozes\n"
	.string "all the time.\p"
	.string "You'll recognize him right away!$"

Route35_GoldenrodGatehouse_EventScript_Officer_Text_3:
	.string "You can't carry another POKéMON…$"

Route35_GoldenrodGatehouse_EventScript_Officer_Text_4:
	.string "{PLAYER} received a POKéMON with MAIL.$"

Route35_GoldenrodGatehouse_EventScript_Officer_Text_5:
	.string "Oh…\n"
	.string "Never mind, then…$"

Route35_GoldenrodGatehouse_Text_Officer_ReadItButDontLoseIt::
	.string "You can read it, but don't lose it!\n"
	.string "ROUTE 31!\p"
	.string "Oh, yeah. There was a weird tree\n"
	.string "blocking the road.\p"
	.string "I wonder if it's been cleared?$"

Route35_GoldenrodGatehouse_Text_Officer_PalWasSnoozing::
	.string "My pal was snoozing, right?\n"
	.string "Heh, what'd I say?$"
