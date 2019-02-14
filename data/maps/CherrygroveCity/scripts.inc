CherrygroveCity_MapScripts:: @ 81E8EA2
	map_script 3, CherrygroveCity_MapScript1_1E8EA8
	.byte 0

CherrygroveCity_MapScript1_1E8EA8: @ 81E8EA8
	setflag FLAG_VISITED_CHERRYGROVE_CITY
	@call_if_unset FLAG_ADVENTURE_STARTED, CherrygroveCity_EventScript_1E8ED2
	@call_if_unset FLAG_RECEIVED_POTION_OLDALE, CherrygroveCity_EventScript_1E8EDE
	@call_if_set FLAG_ADVENTURE_STARTED, CherrygroveCity_EventScript_1E8ECC
	end

CherrygroveCity_EventScript_1E8ECC:: @ 81E8ECC
	setvar VAR_0x4051, 1
	return

CherrygroveCity_EventScript_1E8ED2:: @ 81E8ED2
	setobjectxyperm 3, 1, 11
	setobjectmovementtype 3, MOVEMENT_TYPE_FACE_LEFT
	return

CherrygroveCity_EventScript_1E8EDE:: @ 81E8EDE
	setobjectxyperm 2, 13, 14
	setobjectmovementtype 2, MOVEMENT_TYPE_FACE_DOWN
	return

CherrygroveCity_EventScript_GuideGentsHouse::
	msgbox CherrygroveCity_Text_GuideGentsHouse, MSGBOX_SIGN
	end

CherrygroveCity_EventScript_Slogan::
	msgbox CherrygroveCity_Text_Slogan, MSGBOX_SIGN
	end

CherrygroveCity_EventScript_1E8EF3:: @ 81E8EF3
	msgbox CherrygroveCity_Text_1E918E, MSGBOX_NPC
	end

CherrygroveCity_EventScript_1E8EFC:: @ 81E8EFC
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_POTION_OLDALE, CherrygroveCity_EventScript_1E8FB9
	goto_if_set FLAG_TEMP_1, CherrygroveCity_EventScript_1E8FB9
	setflag FLAG_TEMP_1
	playbgm MUS_TSURETEK, 0
	msgbox CherrygroveCity_Text_1E91C0, MSGBOX_DEFAULT
	closemessage
	switch VAR_FACING
	case 1, CherrygroveCity_EventScript_1E8F47
	case 2, CherrygroveCity_EventScript_1E8F5E
	case 4, CherrygroveCity_EventScript_1E8F75
	end

CherrygroveCity_EventScript_1E8F47:: @ 81E8F47
	applymovement 2, CherrygroveCity_Movement_1E8FD7
	applymovement EVENT_OBJ_ID_PLAYER, CherrygroveCity_Movement_1E9001
	waitmovement 0
	goto CherrygroveCity_EventScript_1E8F8C
	end

CherrygroveCity_EventScript_1E8F5E:: @ 81E8F5E
	applymovement 2, CherrygroveCity_Movement_1E8FE2
	applymovement EVENT_OBJ_ID_PLAYER, CherrygroveCity_Movement_1E900B
	waitmovement 0
	goto CherrygroveCity_EventScript_1E8F8C
	end

CherrygroveCity_EventScript_1E8F75:: @ 81E8F75
	applymovement EVENT_OBJ_ID_PLAYER, CherrygroveCity_Movement_1E8FF9
	applymovement 2, CherrygroveCity_Movement_1E8FCE
	waitmovement 0
	goto CherrygroveCity_EventScript_1E8F8C
	end

CherrygroveCity_EventScript_1E8F8C:: @ 81E8F8C
	msgbox CherrygroveCity_Text_1E91FD, MSGBOX_DEFAULT
	giveitem_std ITEM_POTION
	compare VAR_RESULT, 0
	goto_if_eq CherrygroveCity_EventScript_1E8FC3
	msgbox CherrygroveCity_Text_1E92AF, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_POTION_OLDALE
	fadedefaultbgm
	release
	end

CherrygroveCity_EventScript_1E8FB9:: @ 81E8FB9
	msgbox CherrygroveCity_Text_1E92AF, MSGBOX_DEFAULT
	release
	end

CherrygroveCity_EventScript_1E8FC3:: @ 81E8FC3
	msgbox gUnknown_08272AD0, MSGBOX_DEFAULT
	fadedefaultbgm
	release
	end

CherrygroveCity_Movement_1E8FCE: @ 81E8FCE
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_in_place_fastest_down
	step_end

CherrygroveCity_Movement_1E8FD7: @ 81E8FD7
	walk_left
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_in_place_fastest_down
	step_end

CherrygroveCity_Movement_1E8FE2: @ 81E8FE2
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_in_place_fastest_down
	step_end

CherrygroveCity_Movement_1E8FEB: @ 81E8FEB
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	delay_8
	walk_in_place_fastest_down
	step_end

CherrygroveCity_Movement_1E8FF9: @ 81E8FF9
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

CherrygroveCity_Movement_1E9001: @ 81E9001
	delay_16
	delay_16
	delay_16
	delay_16
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

CherrygroveCity_Movement_1E900B: @ 81E900B
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

CherrygroveCity_Movement_1E9013: @ 81E9013
	walk_left
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

CherrygroveCity_EventScript_Youngster::
	lock
	faceplayer
	goto_if_set FLAG_SYS_POKEDEX_GET, CherrygroveCity_EventScript_YoungsterPostDex
	msgbox CherrygroveCity_Text_PreDex
	release
	end

CherrygroveCity_EventScript_YoungsterPostDex:
	msgbox CherrygroveCity_Text_PostDex
	release
	end

CherrygroveCity_Text_PreDex:
	.string "MR. POKéMON's house is still farther\n"
	.string "up ahead.$"

CherrygroveCity_Text_PostDex:
	.string "I battled the trainers on the road.\n"
	.string "My POKéMON lost. They're a mess!\p"
	.string "I need to take them to a POKéMON\n"
	.string "CENTER.$"

CherrygroveCity_Text_1E918E: @ 81E918E
	.string "I want to take a rest, so I'm saving my\n"
	.string "progress.$"

CherrygroveCity_Text_1E91C0: @ 81E91C0
	.string "Hi!\n"
	.string "I work at a POKéMON MART.\p"
	.string "Can I get you to come with me?$"

CherrygroveCity_Text_1E91FD: @ 81E91FD
	.string "This is a POKéMON MART.\n"
	.string "Just look for our blue roof.\p"
	.string "We sell a variety of goods including\n"
	.string "POKé BALLS for catching POKéMON.\p"
	.string "Here, I'd like you to have this as\n"
	.string "a promotional item.$"

CherrygroveCity_Text_1E92AF: @ 81E92AF
	.string "A POTION can be used anytime, so it's\n"
	.string "even more useful than a POKéMON CENTER\l"
	.string "in certain situations.$"

CherrygroveCity_Text_1E9313: @ 81E9313
	.string "Aaaaah! Wait!\n"
	.string "Please don't come in here.\p"
	.string "I just discovered the footprints of\n"
	.string "a rare POKéMON!\p"
	.string "Wait until I finish sketching\n"
	.string "them, okay?$"

CherrygroveCity_Text_1E939A: @ 81E939A
	.string "I just discovered the footprints of\n"
	.string "a rare POKéMON!\p"
	.string "Wait until I finish sketching\n"
	.string "them, okay?$"

CherrygroveCity_Text_1E93F8: @ 81E93F8
	.string "I finished sketching the footprints of\n"
	.string "a rare POKéMON.\p"
	.string "But it turns out they were only my\n"
	.string "own footprints…$"

CherrygroveCity_Text_1E9462: @ 81E9462
	.string "MAY: {PLAYER}{KUN}!\n"
	.string "Over here!\l"
	.string "Let's hurry home!$"

CherrygroveCity_Text_1E948A: @ 81E948A
	.string "BRENDAN: I'm heading back to my dad's\n"
	.string "LAB now.\l"
	.string "{PLAYER}, you should hustle back, too.$"

CherrygroveCity_Text_GuideGentsHouse:
	.string "GUIDE GENT'S HOUSE$"

CherrygroveCity_Text_Slogan:
	.string "CHERRYGROVE CITY\n"
	.string "The City of Cute, Fragrant Flowers$"
