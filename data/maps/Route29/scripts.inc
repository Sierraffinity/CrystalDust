Route29_MapScripts:: @ 81EBCBA
	map_script 3, Route29_MapScript1_Type3
	map_script 2, Route29_MapScript2_1EBCCB
	.byte 0

Route29_MapScript1_Type3: @ 81EBCC5
	call Route29_MapScript1_CheckForTuscany
	end

Route29_MapScript1_CheckForTuscany:
	goto_if_unset FLAG_BADGE01_GET, Route29_EventScript_HideTuscany
	gettime
	compare VAR_0x8003, DAY_TUESDAY
	goto_if_eq Route29_EventScript_ShowTuscany
Route29_EventScript_HideTuscany:
	setflag FLAG_HIDE_ROUTE_29_TUSCANY
	return

Route29_EventScript_ShowTuscany:
	clearflag FLAG_HIDE_ROUTE_29_TUSCANY
	return

Route29_MapScript2_1EBCCB: @ 81EBCCB
	@map_script_2 VAR_0x4060, 0, Route29_EventScript_1EBCD5
	.2byte 0

Route29_EventScript_1EBCD5:: @ 81EBCD5
	setflag FLAG_SPECIAL_FLAG_0x4000
	setvar VAR_0x4060, 1
	end

Route29_EventScript_1EBCDE:: @ 81EBCDE
	lockall
	playbgm MUS_MOMENC, 1
	msgbox Route29_Text_1EBE8F, MSGBOX_DEFAULT
	closemessage
	setobjectxy 2, 0, 15
	setobjectxy 4, 0, 16
	applymovement EVENT_OBJ_ID_PLAYER, Route29_Movement_1EBDC2
	applymovement 2, Route29_Movement_1EBDE7
	applymovement 4, Route29_Movement_1EBDB5
	waitmovement 0
	applymovement 4, Route29_Movement_1EBD96
	applymovement 2, Route29_Movement_1EBDC8
	waitmovement 0
	applymovement 2, Route29_Movement_2725A8
	waitmovement 0
	applymovement 4, Route29_Movement_1EBDBD
	applymovement 2, Route29_Movement_1EBDEF
	waitmovement 0
	msgbox Route29_Text_1EBE9A, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x4060, 2
	releaseall
	end

Route29_EventScript_1EBD4E:: @ 81EBD4E
	lockall
	msgbox Route29_Text_1EBEDF, MSGBOX_DEFAULT
	closemessage
	applymovement EVENT_OBJ_ID_PLAYER, Route29_Movement_1EBD90
	waitmovement 0
	releaseall
	end

Route29_EventScript_1EBD64:: @ 81EBD64
	lockall
	msgbox Route29_Text_1EBEDF, MSGBOX_DEFAULT
	closemessage
	applymovement EVENT_OBJ_ID_PLAYER, Route29_Movement_1EBD92
	waitmovement 0
	releaseall
	end

Route29_EventScript_1EBD7A:: @ 81EBD7A
	lockall
	msgbox Route29_Text_1EBEDF, MSGBOX_DEFAULT
	closemessage
	applymovement EVENT_OBJ_ID_PLAYER, Route29_Movement_1EBD94
	waitmovement 0
	releaseall
	end

Route29_Movement_1EBD90: @ 81EBD90
	walk_up
	step_end

Route29_Movement_1EBD92: @ 81EBD92
	walk_right
	step_end

Route29_Movement_1EBD94: @ 81EBD94
	walk_down
	step_end

Route29_Movement_1EBD96: @ 81EBD96
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	step_end

Route29_Movement_1EBDB5: @ 81EBDB5
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	step_end

Route29_Movement_1EBDBC: @ 81EBDBC
	step_end

Route29_Movement_1EBDBD: @ 81EBDBD
	walk_in_place_fast_left
	walk_in_place_fast_left
	walk_in_place_fast_left
	walk_in_place_fast_left
	step_end

Route29_Movement_1EBDC2: @ 81EBDC2
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_in_place_fastest_left
	step_end

Route29_Movement_1EBDC8: @ 81EBDC8
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

Route29_Movement_1EBDE7: @ 81EBDE7
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	step_end

Route29_Movement_1EBDEE: @ 81EBDEE
	step_end

Route29_Movement_1EBDEF: @ 81EBDEF
	walk_in_place_fast_right
	walk_in_place_fast_right
	walk_in_place_fast_right
	walk_in_place_fast_right
	step_end

Route29_Movement_1EBDF4: @ 81EBDF4
	walk_up
	walk_up
	step_end

Route29_Movement_1EBDF7: @ 81EBDF7
	walk_up
	walk_left
	walk_up
	step_end

Route29_EventScript_1EBDFB:: @ 81EBDFB
	msgbox Route29_Text_1EBFDD, MSGBOX_NPC
	end

Route29_EventScript_1EBE04:: @ 81EBE04
	msgbox Route29_Text_1EC04A, MSGBOX_NPC
	end

Route29_EventScript_DirectionSign:: @ 81EBE0D
	msgbox Route29_Text_DirectionSign, MSGBOX_SIGN
	end

Route29_EventScript_1EBE16:: @ 81EBE16
	lock
	faceplayer
	setflag FLAG_SYS_POKEMON_GET
	setflag FLAG_RESCUED_BIRCH
	fadescreen 1
	removeobject 4
	setobjectxy EVENT_OBJ_ID_PLAYER, 6, 13
	applymovement EVENT_OBJ_ID_PLAYER, Route29_Movement_2725A4
	waitmovement 0
	special ChooseStarter
	waitstate
	applymovement 2, Route29_Movement_1EBE8D
	waitmovement 0
	msgbox Route29_Text_1EBF12, MSGBOX_DEFAULT
	special HealPlayerParty
	clearflag FLAG_HIDE_ROUTE_29_TUSCANY
	setflag FLAG_HIDE_NEW_BARK_TOWN_RIVAL
	setvar VAR_0x4084, 2
	setvar VAR_0x4060, 3
	clearflag FLAG_SPECIAL_FLAG_0x4000
	checkplayergender
	compare VAR_RESULT, MALE
	call_if_eq Route29_EventScript_1EBE85
	compare VAR_RESULT, FEMALE
	call_if_eq Route29_EventScript_1EBE89
	warp MAP_NEW_BARK_TOWN_PROFESSOR_ELMS_LAB, 255, 6, 5
	waitstate
	release
	end

Route29_EventScript_1EBE85:: @ 81EBE85
	setflag FLAG_HIDE_NEW_BARK_TOWN_MAYS_HOUSE_RIVAL_BEDROOM
	return

Route29_EventScript_1EBE89:: @ 81EBE89
	setflag FLAG_HIDE_NEW_BARK_TOWN_PLAYERS_HOUSE_RIVAL_BEDROOM
	return

Route29_Movement_1EBE8D: @ 81EBE8D
	walk_right
	step_end

Route29_Text_1EBE8F: @ 81EBE8F
	.string "H-help me!$"

Route29_Text_1EBE9A: @ 81EBE9A
	.string "Hello! You over there!\n"
	.string "Please! Help!\p"
	.string "In my BAG!\n"
	.string "There's a POKé BALL!$"

Route29_Text_1EBEDF: @ 81EBEDF
	.string "Wh-Where are you going?!\n"
	.string "Don't leave me like this!$"

Route29_Text_1EBF12: @ 81EBF12
	.string "PROF. BIRCH: Whew…\p"
	.string "I was in the tall grass studying wild\n"
	.string "POKéMON when I was jumped.\p"
	.string "You saved me.\n"
	.string "Thanks a lot!\p"
	.string "Oh?\p"
	.string "Hi, you're {PLAYER}{KUN}!\p"
	.string "This is not the place to chat, so come\n"
	.string "by my POKéMON LAB later, okay?$"

Route29_Text_1EBFDD: @ 81EBFDD
	.string "If POKéMON get tired, take them to\n"
	.string "a POKéMON CENTER.\p"
	.string "There's a POKéMON CENTER in OLDALE\n"
	.string "TOWN right close by.$"

Route29_Text_1EC04A: @ 81EC04A
	.string "Wild POKéMON will jump out at you in\n"
	.string "tall grass.\p"
	.string "If you want to catch POKéMON, you have\n"
	.string "to go into the tall grass and search.$"

Route29_Text_DirectionSign: @ 81EC0C8
	.string "ROUTE 29\n"
	.string "CHERRYGROVE CITY - NEW BARK TOWN$"
