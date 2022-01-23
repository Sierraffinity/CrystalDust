GoldenrodCity_DeptStore_B1F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, GoldenrodCity_DeptStore_B1F_MapScripts_MAP_SCRIPT_ON_LOAD
	.byte 0

GoldenrodCity_DeptStore_B1F_MapScripts_MAP_SCRIPT_ON_LOAD:
	setflag FLAG_VISITED_GOLDENROD_DEPT_STORE_B1F
	switch VAR_GOLDENROD_DEPT_STORE_B1F_LAYOUT
	case 0, GoldenrodCity_DeptStore_B1F_MapScripts_MAP_SCRIPT_ON_LOAD_2
	case 1, GoldenrodCity_DeptStore_B1F_MapScripts_MAP_SCRIPT_ON_LOAD_3
	case 2, GoldenrodCity_DeptStore_B1F_MapScripts_MAP_SCRIPT_ON_LOAD_4
	return

GoldenrodCity_DeptStore_B1F_MapScripts_MAP_SCRIPT_ON_LOAD_2:
	setmetatile 12, 11, METATILE_RadioTower_EmptyFloor, FALSE
	setmetatile 13, 11, METATILE_RadioTower_EmptyFloor, FALSE
	setmetatile 12, 12, METATILE_RadioTower_EmptyFloor, FALSE
	setmetatile 13, 12, METATILE_RadioTower_EmptyFloor, FALSE
	setmetatile 14, 12, METATILE_RadioTower_Floor_AboveLeftWallEdge, FALSE
	setmetatile 12, 13, METATILE_RadioTower_EmptyFloor, FALSE
	setmetatile 13, 13, METATILE_RadioTower_EmptyFloor, FALSE
	return

GoldenrodCity_DeptStore_B1F_MapScripts_MAP_SCRIPT_ON_LOAD_3:
	setmetatile 5, 13, METATILE_RadioTower_EmptyFloor_FullShadow, FALSE
	setmetatile 6, 13, METATILE_RadioTower_EmptyFloor, FALSE
	setmetatile 5, 14, METATILE_RadioTower_EmptyFloor, FALSE
	setmetatile 6, 14, METATILE_RadioTower_EmptyFloor, FALSE
	setmetatile 6, 15, METATILE_RadioTower_EmptyFloor, FALSE
	setmetatile 7, 15, METATILE_RadioTower_EmptyFloor_AngledShadow, FALSE
	return

GoldenrodCity_DeptStore_B1F_MapScripts_MAP_SCRIPT_ON_LOAD_4:
	setmetatile 12, 16, METATILE_RadioTower_EmptyFloor, FALSE
	setmetatile 13, 16, METATILE_RadioTower_EmptyFloor, FALSE
	setmetatile 12, 17, METATILE_RadioTower_Floor_AboveWall, FALSE
	setmetatile 13, 17, METATILE_RadioTower_Floor_AboveWall, FALSE
	return


GoldenrodCity_DeptStore_B1F_EventScript_UnseenMan::
	msgbox GoldenrodCity_DeptStore_B1F_EventScript_UnseenMan_Text_0, MSGBOX_NPC
	return


GoldenrodCity_DeptStore_B1F_EventScript_PassionlessMan::
	msgbox GoldenrodCity_DeptStore_B1F_EventScript_PassionlessMan_Text_0, MSGBOX_NPC
	return


GoldenrodCity_DeptStore_B1F_EventScript_JunkMan::
	msgbox GoldenrodCity_DeptStore_B1F_EventScript_JunkMan_Text_0, MSGBOX_NPC
	return


GoldenrodCity_DeptStore_B1F_EventScript_Machoke::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MACHOKE, 0
	msgbox GoldenrodCity_DeptStore_B1F_EventScript_Machoke_Text_0
	waitmoncry
	release
	return


GoldenrodCity_DeptStore_B1F_EventScript_UnseenMan_Text_0:
	.string "Hey, kid!\n"
	.string "You're holding us up!\p"
	.string "Our policy is to work behind the\n"
	.string "scenes where no one can see us!$"

GoldenrodCity_DeptStore_B1F_EventScript_PassionlessMan_Text_0:
	.string "I lose my passion for work if\n"
	.string "someone's watching.\l"
	.string "Come on, kid, scoot!$"

GoldenrodCity_DeptStore_B1F_EventScript_JunkMan_Text_0:
	.string "Oohah!\n"
	.string "Oohah!\p"
	.string "The stuff on the ground's junk.\n"
	.string "Take it if you want it!$"

GoldenrodCity_DeptStore_B1F_EventScript_Machoke_Text_0:
	.string "MACHOKE: Maaacho!$"
