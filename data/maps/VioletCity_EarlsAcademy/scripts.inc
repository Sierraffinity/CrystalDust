VioletCity_EarlsAcademy_MapScripts::
	.byte 0


VioletCity_EarlsAcademy_EventScript_StatusInfoBoard::
	lockall
	msgbox VioletCity_EarlsAcademy_EventScript_StatusInfoBoard_Text_0
	goto StatusBoard_Loop
	return


StatusBoard_Loop:
	message StatusBoard_Loop_Text_0
	waitmessage
	multichoicegrid 8, 1, MULTI_STATUS_INFO, 3, FALSE
	switch VAR_RESULT
	case 0, StatusBoard_Loop_2
	case 1, StatusBoard_Loop_3
	case 2, StatusBoard_Loop_4
	case 3, StatusBoard_Loop_5
	case 4, StatusBoard_Loop_6
	case 5, StatusBoard_Loop_7
	case MULTI_B_PRESSED, StatusBoard_Loop_7
	return

StatusBoard_Loop_2:
	msgbox StatusBoard_Loop_Text_1
	goto StatusBoard_Loop
	return

StatusBoard_Loop_3:
	msgbox StatusBoard_Loop_Text_2
	goto StatusBoard_Loop
	return

StatusBoard_Loop_4:
	msgbox StatusBoard_Loop_Text_3
	goto StatusBoard_Loop
	return

StatusBoard_Loop_5:
	msgbox StatusBoard_Loop_Text_4
	goto StatusBoard_Loop
	return

StatusBoard_Loop_6:
	msgbox StatusBoard_Loop_Text_5
	goto StatusBoard_Loop
	return

StatusBoard_Loop_7:
	releaseall
	end


VioletCity_EarlsAcademy_EventScript_Notes::
	lockall
	msgbox VioletCity_EarlsAcademy_EventScript_Notes_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq VioletCity_EarlsAcademy_EventScript_Notes_2
VioletCity_EarlsAcademy_EventScript_Notes_1:
	releaseall
	return

VioletCity_EarlsAcademy_EventScript_Notes_2:
	msgbox VioletCity_EarlsAcademy_EventScript_Notes_Text_1, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq VioletCity_EarlsAcademy_EventScript_Notes_4
	goto VioletCity_EarlsAcademy_EventScript_Notes_1

VioletCity_EarlsAcademy_EventScript_Notes_4:
	msgbox VioletCity_EarlsAcademy_EventScript_Notes_Text_2, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq VioletCity_EarlsAcademy_EventScript_Notes_6
	goto VioletCity_EarlsAcademy_EventScript_Notes_1

VioletCity_EarlsAcademy_EventScript_Notes_6:
	msgbox VioletCity_EarlsAcademy_EventScript_Notes_Text_3
	applymovement 2, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	textcolor MSG_COLOR_BLUE
	msgbox VioletCity_EarlsAcademy_EventScript_Notes_Text_4
	goto VioletCity_EarlsAcademy_EventScript_Notes_1


VioletCity_EarlsAcademy_Earl::
	lockall
	applymovement 1, VioletCity_Movement_EarlSpin
	waitmovement 0
	faceplayer
	msgbox VioletCity_EarlsAcademy_Earl_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq VioletCity_EarlsAcademy_Earl_2
VioletCity_EarlsAcademy_Earl_1:
	msgbox VioletCity_EarlsAcademy_Earl_Text_2, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq VioletCity_EarlsAcademy_Earl_5
	goto Earl_End
VioletCity_EarlsAcademy_Earl_4:
	releaseall
	return

VioletCity_EarlsAcademy_Earl_2:
	msgbox VioletCity_EarlsAcademy_Earl_Text_1, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq VioletCity_EarlsAcademy_Earl_8
	goto VioletCity_EarlsAcademy_Earl_1

VioletCity_EarlsAcademy_Earl_5:
	msgbox VioletCity_EarlsAcademy_Earl_Text_3
	goto VioletCity_EarlsAcademy_Earl_4

VioletCity_EarlsAcademy_Earl_8:
	goto Earl_End
	goto VioletCity_EarlsAcademy_Earl_1


Earl_End:
	msgbox Earl_End_Text_0
	releaseall
	return


VioletCity_EarlsAcademy_Movement_EarlSpin:
	face_down
	delay_1
	face_left
	delay_1
	face_up
	delay_1
	face_right
	delay_1
	face_down
	delay_1
	face_left
	delay_1
	face_up
	delay_1
	face_right
	delay_1
	face_down
	delay_1
	face_left
	delay_1
	face_up
	delay_1
	face_right
	delay_1
	face_down
	step_end

VioletCity_EarlsAcademy_EventScript_NoteTakingKid::
	msgbox VioletCity_EarlsAcademy_EventScript_NoteTakingKid_Text_0, MSGBOX_NPC
	return


VioletCity_EarlsAcademy_EventScript_TradingKid1::
	lock
	faceplayer
	msgbox VioletCity_EarlsAcademy_EventScript_TradingKid1_Text_0
	closemessage
	applymovement 4, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	release
	return


VioletCity_EarlsAcademy_EventScript_TradingKid2::
	lock
	faceplayer
	msgbox VioletCity_EarlsAcademy_EventScript_TradingKid2_Text_0
	closemessage
	applymovement 5, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	release
	return


VioletCity_EarlsAcademy_EventScript_HeldItemsKid::
	msgbox VioletCity_EarlsAcademy_EventScript_HeldItemsKid_Text_0, MSGBOX_NPC
	return


VioletCity_EarlsAcademy_EventScript_StatusInfoBoard_Text_0:
	.string "The blackboard lists POKéMON\n"
	.string "status problems in battle.$"

StatusBoard_Loop_Text_0:
	.string "Which topic do you want to read?$"

StatusBoard_Loop_Text_1:
	.string "If poisoned, a POKéMON steadily\n"
	.string "loses HP.\p"
	.string "Poison lingers after the battle,\n"
	.string "and HP is lost as you walk.\p"
	.string "To cure it, use an ANTIDOTE.$"

StatusBoard_Loop_Text_2:
	.string "Paralysis reduces SPEED and may\n"
	.string "prevent movement.\p"
	.string "It remains after battle, so use a\n"
	.string "PARLYZ HEAL.$"

StatusBoard_Loop_Text_3:
	.string "If asleep, your POKéMON can't make\n"
	.string "a move.\p"
	.string "A sleeping POKéMON doesn't wake up\n"
	.string "after battle, so wake it up with\l"
	.string "an AWAKENING.$"

StatusBoard_Loop_Text_4:
	.string "A burn steadily consumes HP.\n"
	.string "It also reduces ATTACK power.\p"
	.string "A burn lingers after battle.\n"
	.string "Use a BURN HEAL as the cure.$"

StatusBoard_Loop_Text_5:
	.string "If your POKéMON is frozen, it can't\n"
	.string "do a thing.\p"
	.string "It remains frozen after battle.\n"
	.string "Thaw it out with an ICE HEAL.$"

VioletCity_EarlsAcademy_EventScript_Notes_Text_0:
	.string "It's this kid's notebook…\p"
	.string "Catch POKéMON using POKé BALLS.\n"
	.string "Up to six can be in your party.\p"
	.string "Keep reading?$"

VioletCity_EarlsAcademy_EventScript_Notes_Text_1:
	.string "Before throwing a POKé BALL, weaken\n"
	.string "the target first.\p"
	.string "A poisoned or burned POKéMON is\n"
	.string "easier to catch.\p"
	.string "Keep reading?$"

VioletCity_EarlsAcademy_EventScript_Notes_Text_2:
	.string "Some moves may cause confusion.\p"
	.string "Confusion may make a POKéMON attack\n"
	.string "itself.\p"
	.string "Leaving battle clears up any\n"
	.string "confusion.\p"
	.string "Keep reading?$"

VioletCity_EarlsAcademy_EventScript_Notes_Text_3:
	.string "People who catch and use POKéMON\n"
	.string "in battle are POKéMON TRAINERS.\p"
	.string "They are expected to visit POKéMON\n"
	.string "GYMS and defeat other TRAINERS.\p"
	.string "The next page is…\n"
	.string "Blank!$"

VioletCity_EarlsAcademy_EventScript_Notes_Text_4:
	.string "BOY: Ehehe…\n"
	.string "I haven't written any more…$"

VioletCity_EarlsAcademy_Earl_Text_0:
	.string "EARL, I am!\n"
	.string "Wonderful are POKéMON, yes!\p"
	.string "Teach you I will to be a better\n"
	.string "TRAINER!\p"
	.string "What you want to know?\n"
	.string "Want to be a winner is you?$"

VioletCity_EarlsAcademy_Earl_Text_1:
	.string "Good!\n"
	.string "Teach you, I will!\p"
	.string "In battle, POKéMON left of list\n"
	.string "jump out first!\p"
	.string "Change order in list, make battle\n"
	.string "easy, maybe!\p"
	.string "More from me you want to hear?$"

VioletCity_EarlsAcademy_Earl_Text_2:
	.string "So, want to know how to raise\n"
	.string "POKéMON well?$"

VioletCity_EarlsAcademy_Earl_Text_3:
	.string "Fine!\n"
	.string "Teach you, I will!\p"
	.string "If POKéMON come out in battle even\n"
	.string "briefly, some EXP. Points it gets.\p"
	.string "At left of list put weak POKéMON.\n"
	.string "Switch in battle quick!\p"
	.string "This way, weak POKéMON strong\n"
	.string "become!$"

Earl_End_Text_0:
	.string "Oh! Smart student you are!\n"
	.string "Nothing more do I teach!$"

VioletCity_EarlsAcademy_EventScript_NoteTakingKid_Text_0:
	.string "I'm taking notes of the teacher's\n"
	.string "lecture.\p"
	.string "I'd better copy the stuff on the\n"
	.string "blackboard, too.$"

VioletCity_EarlsAcademy_EventScript_TradingKid1_Text_0:
	.string "I traded my best POKéMON to the\n"
	.string "guy beside me.$"

VioletCity_EarlsAcademy_EventScript_TradingKid2_Text_0:
	.string "Huh? The POKéMON I just got is\n"
	.string "holding something!$"

VioletCity_EarlsAcademy_EventScript_HeldItemsKid_Text_0:
	.string "A POKéMON holding a BERRY will heal\n"
	.string "itself in battle…\p"
	.string "Many other items can be held by\n"
	.string "POKéMON…\p"
	.string "It sure is tough taking notes…$"
