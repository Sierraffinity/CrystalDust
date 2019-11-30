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


VioletCity_EarlsAcademy_EventScript_204251:: @ 8204251
	lockall
	msgbox VioletCity_EarlsAcademy_Text_20446E, MSGBOX_DEFAULT
	giveitem_std ITEM_HM03
	setflag FLAG_RECEIVED_HM03
	msgbox VioletCity_EarlsAcademy_Text_20461A, MSGBOX_DEFAULT
	setvar VAR_VIOLET_CITY_STATE, 5
	releaseall
	end

VioletCity_EarlsAcademy_EventScript_204278:: @ 8204278
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_WALLY_VICTORY_ROAD, VioletCity_EarlsAcademy_EventScript_2042AC
	goto_if_set FLAG_RECEIVED_HM03, VioletCity_EarlsAcademy_EventScript_2042A2
	goto_if_set FLAG_THANKED_FOR_PLAYING_WITH_WALLY, VioletCity_EarlsAcademy_EventScript_2042B6
	msgbox VioletCity_EarlsAcademy_Text_2042DF, MSGBOX_DEFAULT
	setflag FLAG_THANKED_FOR_PLAYING_WITH_WALLY
	release
	end

VioletCity_EarlsAcademy_EventScript_2042A2:: @ 82042A2
	msgbox VioletCity_EarlsAcademy_Text_204661, MSGBOX_DEFAULT
	release
	end

VioletCity_EarlsAcademy_EventScript_2042AC:: @ 82042AC
	msgbox VioletCity_EarlsAcademy_Text_204698, MSGBOX_DEFAULT
	release
	end

VioletCity_EarlsAcademy_EventScript_2042B6:: @ 82042B6
	msgbox VioletCity_EarlsAcademy_Text_20444D, MSGBOX_DEFAULT
	release
	end

VioletCity_EarlsAcademy_EventScript_2042C0:: @ 82042C0
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM03, VioletCity_EarlsAcademy_EventScript_2042D5
	msgbox VioletCity_EarlsAcademy_Text_204732, MSGBOX_DEFAULT
	release
	end

VioletCity_EarlsAcademy_EventScript_2042D5:: @ 82042D5
	msgbox VioletCity_EarlsAcademy_Text_2047A7, MSGBOX_DEFAULT
	release
	end

VioletCity_EarlsAcademy_Text_2042DF: @ 82042DF
	.string "You're…\n"
	.string "Ah, you must be {PLAYER}{KUN}, right?\p"
	.string "Thank you for playing with WALLY a\n"
	.string "little while ago.\p"
	.string "He's been frail and sickly ever\n"
	.string "since he was a baby.\p"
	.string "We've sent him to stay with my relatives\n"
	.string "in VERDANTURF TOWN for a while.\p"
	.string "The air is a lot cleaner there\n"
	.string "than it is here.\p"
	.string "What's that? Where's WALLY?\n"
	.string "He's already left, our WALLY.\p"
	.string "I wonder where he could have\n"
	.string "gotten by now?$"

VioletCity_EarlsAcademy_Text_20444D: @ 820444D
	.string "I wonder how our WALLY is doing?$"

VioletCity_EarlsAcademy_Text_20446E: @ 820446E
	.string "{PLAYER}{KUN}! Please excuse us for\n"
	.string "dragging you here this way.\p"
	.string "But our WALLY's become very healthy\n"
	.string "since he went to VERDANTURF TOWN.\p"
	.string "We owe it all to you!\p"
	.string "When WALLY left town, you helped\n"
	.string "him catch a POKéMON, right?\p"
	.string "I think that made WALLY really\n"
	.string "happy.\p"
	.string "Actually, not just WALLY.\n"
	.string "It made me, his father, happy too.\p"
	.string "Happy that he's gained such a great\n"
	.string "friend as you.\p"
	.string "This isn't a bribe or anything, but\n"
	.string "I'd really like you to have this.$"

VioletCity_EarlsAcademy_Text_20461A: @ 820461A
	.string "If your POKéMON can SURF, you'll be\n"
	.string "able to go to all sorts of places.$"

VioletCity_EarlsAcademy_Text_204661: @ 8204661
	.string "WALLY's coming home soon.\n"
	.string "I'm looking forward to that.$"

VioletCity_EarlsAcademy_Text_204698: @ 8204698
	.string "Oh? You met WALLY in\n"
	.string "EVER GRANDE CITY?\p"
	.string "Oh, {PLAYER}{KUN}, don't be silly.\p"
	.string "He may have gotten healthy, but he\n"
	.string "can't go somewhere far away like\l"
	.string "that all by himself.$"

VioletCity_EarlsAcademy_Text_204732: @ 8204732
	.string "WALLY was really happy when he told\n"
	.string "us that he caught a POKéMON.\p"
	.string "It's been ages since I've seen him\n"
	.string "smile like that.$"

VioletCity_EarlsAcademy_Text_2047A7: @ 82047A7
	.string "I want you to keep this a secret\n"
	.string "from my husband…\p"
	.string "But our WALLY left VERDANTURF TOWN\n"
	.string "without telling anyone.\p"
	.string "You know, WALLY is frail, but\n"
	.string "he's surprisingly strong-willed.\p"
	.string "I'm sure that he'll come back safe\n"
	.string "and sound one day!$"

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
