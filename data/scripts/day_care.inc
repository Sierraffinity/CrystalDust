Route34_DayCare_EventScript_DaycareManInside::
	lock
	faceplayer
	clearflag FLAG_TEMP_1
	goto Route34_DayCare_EventScript_DaycareManCommon
	return


Route34_DayCare_EventScript_DaycareManOutside::
	lock
	faceplayer
	setflag FLAG_TEMP_1
	goto Route34_DayCare_EventScript_DaycareManCommon
	return


Route34_DayCare_EventScript_DaycareManCommon::
	goto_if_unset FLAG_RECEIVED_EGG_TICKET, Route34_DayCare_EventScript_DaycareManCommon_2
	special GetDaycareMonNicknames
	specialvar VAR_RESULT, GetDaycareState
	switch VAR_RESULT
	case DAYCARE_EGG_WAITING, Route34_DayCare_EventScript_DaycareManCommon_6
	case DAYCARE_ONE_MON, Route34_DayCare_EventScript_DaycareManCommon_7
	case DAYCARE_TWO_MONS, Route34_DayCare_EventScript_DaycareManCommon_8
	msgbox Route34_DayCare_EventScript_DaycareManCommon_Text_6, MSGBOX_DEFAULT
Route34_DayCare_EventScript_DaycareManCommon_1:
	release
	return

Route34_DayCare_EventScript_DaycareManCommon_2:
	msgbox Route34_DayCare_EventScript_DaycareManCommon_Text_0
	giveitem ITEM_EGG_TICKET
	setflag FLAG_RECEIVED_EGG_TICKET
	goto Route34_DayCare_EventScript_DaycareManCommon_1

Route34_DayCare_EventScript_DaycareManCommon_6:
	msgbox Route34_DayCare_EventScript_DaycareManCommon_Text_1, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Route34_DayCare_EventScript_DaycareManCommon_10
	msgbox Route34_DayCare_EventScript_DaycareManCommon_Text_2, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Route34_DayCare_EventScript_DaycareManCommon_13
	msgbox Route34_DayCare_EventScript_DaycareManCommon_Text_3, MSGBOX_DEFAULT
	closemessage
	clearflag FLAG_PENDING_DAYCARE_EGG
	special RejectEggFromDayCare
	call Route34_DayCare_EventScript_DaycareManWalkInsideAfterEggEvent
	goto Route34_DayCare_EventScript_DaycareManCommon_1

Route34_DayCare_EventScript_DaycareManCommon_7:
	special GetDaycareMonNicknames
	msgbox Route34_DayCare_EventScript_DaycareManCommon_Text_4, MSGBOX_DEFAULT
	setvar VAR_0x8004, 0
	call Route34_DayCare_EventScript_CheckMonReceivedMail
	goto Route34_DayCare_EventScript_DaycareManCommon_1

Route34_DayCare_EventScript_DaycareManCommon_8:
	special GetDaycareMonNicknames
	msgbox Route34_DayCare_EventScript_DaycareManCommon_Text_5, MSGBOX_DEFAULT
	special SetDaycareCompatibilityString
	special ShowFieldMessageStringVar4
	waitmessage
	waitbuttonpress
	setvar VAR_0x8004, 0
	call Route34_DayCare_EventScript_CheckMonReceivedMail
	setvar VAR_0x8004, 1
	call Route34_DayCare_EventScript_CheckMonReceivedMail
	goto Route34_DayCare_EventScript_DaycareManCommon_1

Route34_DayCare_EventScript_DaycareManCommon_10:
	call Route34_DayCare_EventScript_DaycareAcceptEgg
	goto Route34_DayCare_EventScript_DaycareManCommon_1

Route34_DayCare_EventScript_DaycareManCommon_13:
	call Route34_DayCare_EventScript_DaycareAcceptEgg
	goto Route34_DayCare_EventScript_DaycareManCommon_1


Route34_DayCare_EventScript_DaycareAcceptEgg::
	specialvar VAR_RESULT, CalculatePlayerPartyCount
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne Route34_DayCare_EventScript_DaycareAcceptEgg_1
	msgbox Route34_DayCare_EventScript_DaycareAcceptEgg_Text_2, MSGBOX_DEFAULT
	return

Route34_DayCare_EventScript_DaycareAcceptEgg_1:
	textcolor MSG_COLOR_SYS
	message Route34_DayCare_EventScript_DaycareAcceptEgg_Text_0
	call EventScript_RestorePrevTextColor
	playfanfare MUS_FANFA1
	waitfanfare
	waitbuttonpress
	msgbox Route34_DayCare_EventScript_DaycareAcceptEgg_Text_1, MSGBOX_DEFAULT
	closemessage
	special GiveEggFromDaycare
	clearflag FLAG_PENDING_DAYCARE_EGG
	call Route34_DayCare_EventScript_DaycareManWalkInsideAfterEggEvent
	return


Route34_DayCare_EventScript_DaycareManWalkInsideAfterEggEvent::
	goto_if_set FLAG_TEMP_1, Route34_DayCare_EventScript_DaycareManWalkInsideAfterEggEvent_1
	return

Route34_DayCare_EventScript_DaycareManWalkInsideAfterEggEvent_1:
	compare VAR_FACING, DIR_WEST
	goto_if_eq Route34_DayCare_EventScript_DaycareManWalkInsideAfterEggEvent_4
	applymovement OBJ_EVENT_ID_PLAYER, Route34_DayCare_Movement_WatchManWalkBackInsideNorth
	applymovement 7, Route34_DayCare_Movement_WalkBackInsideNorth
	waitmovement 0
Route34_DayCare_EventScript_DaycareManWalkInsideAfterEggEvent_3:
	removeobject 7
	playse SE_KAIDAN
	waitse
	return

Route34_DayCare_EventScript_DaycareManWalkInsideAfterEggEvent_4:
	applymovement OBJ_EVENT_ID_PLAYER, Route34_DayCare_Movement_WatchManWalkBackInsideWest
	applymovement 7, Route34_DayCare_Movement_WalkBackInsideWest
	waitmovement 0
	goto Route34_DayCare_EventScript_DaycareManWalkInsideAfterEggEvent_3


Route34_DayCare_Movement_WalkBackInsideWest:
	walk_slow_down
	walk_slow_down
	walk_slow_right
	delay_8
	set_invisible
	step_end

Route34_DayCare_Movement_WatchManWalkBackInsideWest:
	delay_16
	walk_in_place_fastest_down
	step_end

Route34_DayCare_Movement_WalkBackInsideNorth:
	walk_slow_right
	walk_slow_down
	walk_slow_down
	face_right
	delay_8
	set_invisible
	step_end

Route34_DayCare_Movement_WatchManWalkBackInsideNorth:
	delay_16
	delay_4
	walk_in_place_fastest_right
	step_end

Route34_DayCare_EventScript_CheckMonReceivedMail::
	specialvar VAR_RESULT, CheckDaycareMonReceivedMail
	compare VAR_RESULT, TRUE
	goto_if_eq Route34_DayCare_EventScript_CheckMonReceivedMail_1
	return

Route34_DayCare_EventScript_CheckMonReceivedMail_1:
	msgbox Route34_DayCare_EventScript_CheckMonReceivedMail_Text_0, MSGBOX_DEFAULT
	return


Route34_DayCare_EventScript_DaycareWoman::
	lock
	faceplayer
	goto_if_unset FLAG_RECEIVED_EGG_TICKET, Route34_DayCare_EventScript_DaycareWoman_2
	specialvar VAR_RESULT, GetDaycareState
	switch VAR_RESULT
	case DAYCARE_EGG_WAITING, Route34_DayCare_EventScript_DaycareWoman_6
	case DAYCARE_ONE_MON, Route34_DayCare_EventScript_DaycareWoman_7
	case DAYCARE_TWO_MONS, Route34_DayCare_EventScript_DaycareWoman_8
	goto_if_set FLAG_TALKED_TO_DAYCARE_LADY, Route34_DayCare_EventScript_DaycareWoman_17
	setflag FLAG_TALKED_TO_DAYCARE_LADY
	msgbox Route34_DayCare_EventScript_DaycareWoman_Text_3, MSGBOX_YESNO
Route34_DayCare_EventScript_DaycareWoman_16:
	compare VAR_RESULT, YES
	goto_if_eq Route34_DayCare_EventScript_DaycareWoman_23
	msgbox Route34_DayCare_EventScript_DaycareWoman_Text_4, MSGBOX_DEFAULT
Route34_DayCare_EventScript_DaycareWoman_1:
	release
	return

Route34_DayCare_EventScript_DaycareWoman_2:
	msgbox Route34_DayCare_EventScript_DaycareWoman_Text_0
	goto Route34_DayCare_EventScript_DaycareWoman_1

Route34_DayCare_EventScript_DaycareWoman_6:
	msgbox Route34_DayCare_EventScript_DaycareWoman_Text_1, MSGBOX_DEFAULT
	goto Route34_DayCare_EventScript_DaycareWoman_1

Route34_DayCare_EventScript_DaycareWoman_7:
	msgbox Route34_DayCare_Text_GoodToSeeYou, MSGBOX_DEFAULT
	setvar VAR_0x8004, 0
	call Route34_DayCare_EventScript_DisplayLevelsGained
	msgbox Route34_DayCare_Text_WeCanRaiseOneMore, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Route34_DayCare_EventScript_DaycareWoman_11
Route34_DayCare_EventScript_DaycareWoman_10:
	msgbox Route34_DayCare_Text_TakeYourMonBack, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Route34_DayCare_EventScript_DaycareWoman_21
Route34_DayCare_EventScript_DaycareWoman_20:
	goto Route34_DayCare_EventScript_ComeAgain
	goto Route34_DayCare_EventScript_DaycareWoman_1

Route34_DayCare_EventScript_DaycareWoman_8:
	msgbox Route34_DayCare_Text_GoodToSeeYou, MSGBOX_DEFAULT
	setvar VAR_0x8004, 0
	call Route34_DayCare_EventScript_DisplayLevelsGained
	setvar VAR_0x8004, 1
	call Route34_DayCare_EventScript_DisplayLevelsGained
	msgbox Route34_DayCare_Text_TakeYourMonBack, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Route34_DayCare_EventScript_DaycareWoman_14
Route34_DayCare_EventScript_DaycareWoman_13:
	goto Route34_DayCare_EventScript_ComeAgain
	goto Route34_DayCare_EventScript_DaycareWoman_1

Route34_DayCare_EventScript_DaycareWoman_11:
	goto Route34_DayCare_EventScript_GiveMonToRaise
	goto Route34_DayCare_EventScript_DaycareWoman_10

Route34_DayCare_EventScript_DaycareWoman_14:
	goto Route34_DayCare_EventScript_TryRetrieveMon
	goto Route34_DayCare_EventScript_DaycareWoman_13

Route34_DayCare_EventScript_DaycareWoman_17:
	msgbox Route34_DayCare_EventScript_DaycareWoman_Text_2, MSGBOX_YESNO
	goto Route34_DayCare_EventScript_DaycareWoman_16

Route34_DayCare_EventScript_DaycareWoman_21:
	goto Route34_DayCare_EventScript_TryRetrieveMon
	goto Route34_DayCare_EventScript_DaycareWoman_20

Route34_DayCare_EventScript_DaycareWoman_23:
	goto Route34_DayCare_EventScript_GiveMonToRaise
	goto Route34_DayCare_EventScript_DaycareWoman_1


Route34_DayCare_EventScript_GiveMonToRaise::
	specialvar VAR_RESULT, CountPartyNonEggMons
	compare VAR_RESULT, 1
	goto_if_eq Route34_DayCare_EventScript_GiveMonToRaise_2
	specialvar VAR_RESULT, CountPartyAliveNonEggMons
	compare VAR_RESULT, 2
	goto_if_eq Route34_DayCare_EventScript_GiveMonToRaise_5
	msgbox Route34_DayCare_EventScript_GiveMonToRaise_Text_2, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	special ChooseSendDaycareMon
	waitstate
	compare VAR_0x8004, 0xFF
	goto_if_eq Route34_DayCare_EventScript_GiveMonToRaise_9
Route34_DayCare_EventScript_GiveMonToRaise_8:
	specialvar VAR_RESULT, CountPartyAliveNonEggMons_IgnoreVar0x8004Slot
	compare VAR_RESULT, 0
	goto_if_eq Route34_DayCare_EventScript_GiveMonToRaise_11
	specialvar VAR_0x8005, GetSelectedMonNicknameAndSpecies
	waitse
	playmoncry VAR_0x8005, 0
	msgbox Route34_DayCare_EventScript_GiveMonToRaise_Text_4, MSGBOX_DEFAULT
	waitmoncry
	special StoreSelectedPokemonInDaycare
	incrementgamestat GAME_STAT_USED_DAYCARE
	specialvar VAR_RESULT, GetDaycareState
	compare VAR_RESULT, DAYCARE_ONE_MON
	goto_if_eq Route34_DayCare_EventScript_GiveMonToRaise_14
Route34_DayCare_EventScript_GiveMonToRaise_1:
	release
	return

Route34_DayCare_EventScript_GiveMonToRaise_2:
	msgbox Route34_DayCare_EventScript_GiveMonToRaise_Text_0, MSGBOX_DEFAULT
	goto Route34_DayCare_EventScript_GiveMonToRaise_1

Route34_DayCare_EventScript_GiveMonToRaise_5:
	msgbox Route34_DayCare_EventScript_GiveMonToRaise_Text_1, MSGBOX_DEFAULT
	goto Route34_DayCare_EventScript_GiveMonToRaise_1

Route34_DayCare_EventScript_GiveMonToRaise_9:
	goto Route34_DayCare_EventScript_ComeAgain
	goto Route34_DayCare_EventScript_GiveMonToRaise_8

Route34_DayCare_EventScript_GiveMonToRaise_11:
	msgbox Route34_DayCare_EventScript_GiveMonToRaise_Text_3, MSGBOX_DEFAULT
	goto Route34_DayCare_EventScript_GiveMonToRaise_1

Route34_DayCare_EventScript_GiveMonToRaise_14:
	msgbox Route34_DayCare_Text_WeCanRaiseOneMore, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Route34_DayCare_EventScript_GiveMonToRaise_17
Route34_DayCare_EventScript_GiveMonToRaise_16:
	goto Route34_DayCare_EventScript_ComeAgain
	goto Route34_DayCare_EventScript_GiveMonToRaise_1

Route34_DayCare_EventScript_GiveMonToRaise_17:
	goto Route34_DayCare_EventScript_GiveMonToRaise
	goto Route34_DayCare_EventScript_GiveMonToRaise_16


Route34_DayCare_EventScript_DisplayLevelsGained::
	specialvar VAR_RESULT, GetNumLevelsGainedFromDaycare
	compare VAR_RESULT, 0
	goto_if_ne Route34_DayCare_EventScript_DisplayLevelsGained_1
	msgbox Route34_DayCare_EventScript_DisplayLevelsGained_Text_1, MSGBOX_DEFAULT
	return

Route34_DayCare_EventScript_DisplayLevelsGained_1:
	msgbox Route34_DayCare_EventScript_DisplayLevelsGained_Text_0, MSGBOX_DEFAULT
	return


Route34_DayCare_EventScript_TryRetrieveMon::
	specialvar VAR_RESULT, CalculatePlayerPartyCount
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq Route34_DayCare_EventScript_TryRetrieveMon_2
	specialvar VAR_RESULT, GetDaycareState
	setvar VAR_0x8004, 0
	compare VAR_RESULT, DAYCARE_ONE_MON
	goto_if_eq Route34_DayCare_EventScript_TryRetrieveMon_6
Route34_DayCare_EventScript_TryRetrieveMon_5:
	special ShowDaycareLevelMenu
	waitstate
	copyvar VAR_0x8004, VAR_RESULT
	compare VAR_RESULT, DAYCARE_EXITED_LEVEL_MENU
	goto_if_eq Route34_DayCare_EventScript_TryRetrieveMon_9
Route34_DayCare_EventScript_TryRetrieveMon_8:
	goto Route34_DayCare_EventScript_CostPrompt
Route34_DayCare_EventScript_TryRetrieveMon_1:
	release
	return

Route34_DayCare_EventScript_TryRetrieveMon_2:
	msgbox Route34_DayCare_EventScript_TryRetrieveMon_Text_0, MSGBOX_DEFAULT
	goto Route34_DayCare_EventScript_TryRetrieveMon_1

Route34_DayCare_EventScript_TryRetrieveMon_6:
	goto Route34_DayCare_EventScript_CostPrompt
	goto Route34_DayCare_EventScript_TryRetrieveMon_5

Route34_DayCare_EventScript_TryRetrieveMon_9:
	goto Route34_DayCare_EventScript_ComeAgain
	goto Route34_DayCare_EventScript_TryRetrieveMon_8


Route34_DayCare_EventScript_CostPrompt::
	special GetDaycareCost
	msgbox Route34_DayCare_EventScript_CostPrompt_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Route34_DayCare_EventScript_CostPrompt_2
	goto Route34_DayCare_EventScript_ComeAgain
Route34_DayCare_EventScript_CostPrompt_1:
	release
	return

Route34_DayCare_EventScript_CostPrompt_2:
	specialvar VAR_RESULT, IsEnoughForCostInVar0x8005
	compare VAR_RESULT, TRUE
	goto_if_eq Route34_DayCare_EventScript_CostPrompt_5
	msgbox Route34_DayCare_EventScript_CostPrompt_Text_4, MSGBOX_DEFAULT
	goto Route34_DayCare_EventScript_CostPrompt_1

Route34_DayCare_EventScript_CostPrompt_5:
	closemessage
	applymovement 1, Route34_DayCare_Movement_RetrieveDaycareMon
	delay 128
	playse SE_KAIDAN
	delay 72
	playse SE_KAIDAN
	waitmovement 0
	specialvar VAR_RESULT, TakePokemonFromDaycare
	special SubtractMoneyFromVar0x8005
	playse SE_REGI
	msgbox Route34_DayCare_EventScript_CostPrompt_Text_1, MSGBOX_DEFAULT
	waitse
	playmoncry VAR_RESULT, 0
	textcolor MSG_COLOR_SYS
	msgbox Route34_DayCare_EventScript_CostPrompt_Text_2, MSGBOX_DEFAULT
	call EventScript_RestorePrevTextColor
	waitmoncry
	specialvar VAR_RESULT, GetDaycareState
	compare VAR_RESULT, DAYCARE_ONE_MON
	goto_if_eq Route34_DayCare_EventScript_CostPrompt_9
Route34_DayCare_EventScript_CostPrompt_8:
	goto Route34_DayCare_EventScript_ComeAgain
	goto Route34_DayCare_EventScript_CostPrompt_1

Route34_DayCare_EventScript_CostPrompt_9:
	msgbox Route34_DayCare_EventScript_CostPrompt_Text_3, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Route34_DayCare_EventScript_CostPrompt_11
	goto Route34_DayCare_EventScript_CostPrompt_8

Route34_DayCare_EventScript_CostPrompt_11:
	goto Route34_DayCare_EventScript_TryRetrieveMon
	goto Route34_DayCare_EventScript_CostPrompt_8


Route34_DayCare_Movement_RetrieveDaycareMon:
	delay_16
	delay_16
	face_left
	delay_16
	delay_16
	face_right
	delay_16
	delay_16
	face_down
	walk_slow_down
	set_invisible
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	face_up
	set_visible
	walk_slow_up
	step_end

Route34_DayCare_EventScript_ComeAgain::
	msgbox Route34_DayCare_EventScript_ComeAgain_Text_0, MSGBOX_DEFAULT
	release
	return


EventScript_EggHatch::
	lockall
	msgbox EventScript_EggHatch_Text_0, MSGBOX_DEFAULT
	special EggHatch
	waitstate
	releaseall
	return


Route34_DayCare_EventScript_DaycareManCommon_Text_0:
	.string "I'm the DAY-CARE MAN.\p"
	.string "There's something new in GOLDENROD\n"
	.string "called the TRADE CORNER.\p"
	.string "I was given an EGG TICKET that can\n"
	.string "be traded in for an ODD EGG.\p"
	.string "But as we run a DAY-CARE, we don't\n"
	.string "need it. You may as well have it.$"

Route34_DayCare_EventScript_DaycareManCommon_Text_1:
	.string "Ah, it's you!\p"
	.string "We were raising your POKéMON, and\n"
	.string "my goodness, were we surprised!\p"
	.string "Your POKéMON had an EGG!\p"
	.string "We don't know how it got there,\n"
	.string "but your POKéMON had it.\p"
	.string "You do want it, yes?$"

Route34_DayCare_EventScript_DaycareManCommon_Text_2:
	.string "I really will keep it.\n"
	.string "You do want this, yes?$"

Route34_DayCare_EventScript_DaycareManCommon_Text_3:
	.string "Well then, I'll keep it.\n"
	.string "Thanks!$"

Route34_DayCare_EventScript_DaycareManCommon_Text_4:
	.string "Ah, it's you! Good to see you.\n"
	.string "Your {STR_VAR_1}'s doing fine.$"

Route34_DayCare_EventScript_DaycareManCommon_Text_5:
	.string "Ah, it's you! Your {STR_VAR_1} and\n"
	.string "{STR_VAR_2} are doing fine.$"

Route34_DayCare_EventScript_DaycareManCommon_Text_6:
	.string "I'm the DAY-CARE MAN.\p"
	.string "I help take care of the precious\n"
	.string "POKéMON of TRAINERS.\p"
	.string "If you'd like me to raise your\n"
	.string "POKéMON, have a word with my wife.$"

Route34_DayCare_EventScript_DaycareAcceptEgg_Text_0:
	.string "{PLAYER} received the EGG from\n"
	.string "the DAY-CARE MAN.$"

Route34_DayCare_EventScript_DaycareAcceptEgg_Text_1:
	.string "Take good care of it.$"

Route34_DayCare_EventScript_DaycareAcceptEgg_Text_2:
	.string "You have no room for it…\n"
	.string "Come back when you've made room.$"

Route34_DayCare_EventScript_CheckMonReceivedMail_Text_0:
	.string "By the way, about your {STR_VAR_1},\n"
	.string "it seemed to be friendly with\l"
	.string "{STR_VAR_2}'s {STR_VAR_3}.\p"
	.string "I may even have seen it receiving\n"
	.string "a piece of MAIL.$"

Route34_DayCare_EventScript_DaycareWoman_Text_0:
	.string "I'm the DAY-CARE LADY.\p"
	.string "Have you been to GOLDENROD's new\n"
	.string "POKéMON CENTER?\p"
	.string "My husband went there recently\n"
	.string "and got this promotional item.\p"
	.string "We don't need it, since we have\n"
	.string "enough on our plates already…\p"
	.string "Oh, would you like it?\p"
	.string "My husband should still have it,\n"
	.string "so go talk to him.$"

Route34_DayCare_EventScript_DaycareWoman_Text_1:
	.string "My husband was looking for you.$"

Route34_DayCare_EventScript_DaycareWoman_Text_2:
	.string "I'm the DAY-CARE LADY.\p"
	.string "We can raise POKéMON for you.\p"
	.string "Would you like us to raise one?$"

Route34_DayCare_EventScript_DaycareWoman_Text_3:
	.string "I'm the DAY-CARE LADY.\p"
	.string "Do you know about EGGS?\p"
	.string "My husband and I were raising some\n"
	.string "POKéMON, you see.\p"
	.string "We were shocked to find an EGG!\n"
	.string "How incredible could that be?\p"
	.string "We can raise POKéMON for you, too.\p"
	.string "Would you like us to raise one?$"

Route34_DayCare_EventScript_DaycareWoman_Text_4:
	.string "Oh, fine, then.\n"
	.string "Come again.$"

Route34_DayCare_EventScript_GiveMonToRaise_Text_0:
	.string "Oh? But you have just one POKéMON.\n"
	.string "Come back another time.$"

Route34_DayCare_EventScript_GiveMonToRaise_Text_1:
	.string "Huh?\n"
	.string "Now, now.\p"
	.string "If you leave that POKéMON with\n"
	.string "me, you'll be left with just one.\p"
	.string "You will be better off if you catch\n"
	.string "some more, I dare say.$"

Route34_DayCare_EventScript_GiveMonToRaise_Text_2:
	.string "Which POKéMON should we raise for\n"
	.string "you?$"

Route34_DayCare_EventScript_GiveMonToRaise_Text_3:
	.string "If you leave me that POKéMON,\n"
	.string "what will you battle with?\p"
	.string "Come back another time.$"

Route34_DayCare_EventScript_GiveMonToRaise_Text_4:
	.string "Fine, we'll raise your {STR_VAR_1}\n"
	.string "for a while.\p"
	.string "Come back for it later.$"

Route34_DayCare_EventScript_DisplayLevelsGained_Text_0:
	.string "By level, your {STR_VAR_1} has\n"
	.string "grown by {STR_VAR_2}.$"

Route34_DayCare_EventScript_DisplayLevelsGained_Text_1:
	.string "Your {STR_VAR_1} needs a little\n"
	.string "more time with us…$"

Route34_DayCare_EventScript_TryRetrieveMon_Text_0:
	.string "Your POKéMON team is full.\n"
	.string "Make room, then come see me.$"

Route34_DayCare_EventScript_CostPrompt_Text_0:
	.string "If you want your {STR_VAR_1} back,\n"
	.string "it will cost ¥{STR_VAR_2}.$"

Route34_DayCare_EventScript_CostPrompt_Text_1:
	.string "Perfect!\n"
	.string "Here's your POKéMON.$"

Route34_DayCare_EventScript_CostPrompt_Text_2:
	.string "{PLAYER} took back {STR_VAR_1} from\n"
	.string "the DAY-CARE LADY.$"

Route34_DayCare_EventScript_CostPrompt_Text_3:
	.string "Will you take back the other one,\n"
	.string "too?$"

Route34_DayCare_EventScript_CostPrompt_Text_4:
	.string "You don't have enough money…$"

Route34_DayCare_EventScript_ComeAgain_Text_0:
	.string "Fine.\n"
	.string "Come again.$"

EventScript_EggHatch_Text_0:
	.string "Huh?$"

Route34_DayCare_Text_WeCanRaiseOneMore::
	.string "We can raise two of your POKéMON.\n"
	.string "Would you like us to raise one more?$"

Route34_DayCare_Text_GoodToSeeYou::
	.string "Ah, it's you! Good to see you.\n"
	.string "Your POKéMON can only be doing good!$"

Route34_DayCare_Text_TakeYourMonBack::
	.string "Will you take your POKéMON back?$"
