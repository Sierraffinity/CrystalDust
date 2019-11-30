VioletCity_EarlsAcademy_MapScripts::
	.byte 0


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
