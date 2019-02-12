Route29_EventObjects:
	object_event 1, EVENT_OBJ_GFX_PSYCHIC_M, 0, 62, 16, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, Route29_EventScript_Dude, 0
	object_event 2, EVENT_OBJ_GFX_BOY_1, 0, 34, 18, 0, MOVEMENT_TYPE_WANDER_UP_AND_DOWN, 1, 2, 0, 0, Route29_EventScript_Youngster, 0
	object_event 3, EVENT_OBJ_GFX_GIRL_1, 0, 19, 15, 3, MOVEMENT_TYPE_WANDER_LEFT_AND_RIGHT, 1, 0, 0, 0, Route29_EventScript_LedgeGirl, 0
	object_event 4, EVENT_OBJ_GFX_FAT_MAN, 0, 31, 5, 0, MOVEMENT_TYPE_FACE_UP, 0, 0, 0, 0, Route29_EventScript_FatMan, 0
	object_event 5, EVENT_OBJ_GFX_MAN_4, 0, 16, 6, 3, MOVEMENT_TYPE_FACE_DOWN, 0, 0, 0, 0, Route29_EventScript_WaitingMan, 0
	object_event 6, EVENT_OBJ_GFX_WOMAN_2, 0, 37, 14, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, 0, FLAG_HIDE_ROUTE_29_TUSCANY
	object_event 7, EVENT_OBJ_GFX_ITEM_BALL, 0, 60, 2, 3, MOVEMENT_TYPE_FACE_DOWN, 0, 0, 0, 0, Route29_EventScript_ItemBall_Potion, FLAG_ITEM_ROUTE_29_POTION
	object_event 8, EVENT_OBJ_GFX_CUTTABLE_TREE, 0, 26, 13, 3, MOVEMENT_TYPE_FACE_DOWN, 0, 0, 0, 0, EventScript_CutTree, FLAG_TEMP_11
	object_event 9, EVENT_OBJ_GFX_CUTTABLE_TREE, 0, 39, 11, 3, MOVEMENT_TYPE_FACE_DOWN, 0, 0, 0, 0, EventScript_CutTree, FLAG_TEMP_12

Route29_MapWarps:
	warp_def 34, 3, 3, 1, MAP_ROUTE29_GATEHOUSE
	warp_def 35, 3, 3, 1, MAP_ROUTE29_GATEHOUSE

Route29_MapCoordEvents:
	coord_event 65, 10, 3, VAR_0x4060, 0, NULL
	coord_event 65, 11, 3, VAR_0x4060, 0, NULL
	coord_event 65, 12, 3, VAR_0x4060, 0, NULL
	coord_event 65, 13, 3, VAR_0x4060, 0, NULL

Route29_MapBGEvents:
	bg_event 3, 5, 0, BG_EVENT_PLAYER_FACING_ANY, Route29_EventScript_DirectionSign
	bg_event 63, 9, 3, BG_EVENT_PLAYER_FACING_ANY, Route29_EventScript_DirectionSign
	bg_event 14, 4, 3, BG_EVENT_PLAYER_FACING_ANY, NULL

Route29_MapEvents::
	map_events Route29_EventObjects, Route29_MapWarps, Route29_MapCoordEvents, Route29_MapBGEvents

