NewBarkTown_EventObjects::
	object_event 1, EVENT_OBJ_GFX_FAT_MAN, 0, 16, 11, 3, MOVEMENT_TYPE_WANDER_AROUND, 0, 0, FALSE, 0, NULL, 0
	object_event 2, EVENT_OBJ_GFX_BOY_1, 0, 7, 10, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, FALSE, 0, NULL, 0
	object_event 3, EVENT_OBJ_GFX_AQUA_MEMBER_M, 0, 4, 4, 3, MOVEMENT_TYPE_FACE_RIGHT, 0, 0, FALSE, 0, NULL, 0

NewBarkTown_MapWarps::
	warp_def 16, 7, 3, 0, MAP_NEW_BARK_TOWN_HIROS_HOUSE_1F
	warp_def 8, 5, 3, 0, MAP_NEW_BARK_TOWN
	warp_def 13, 16, 3, 0, MAP_NEW_BARK_TOWN_ELMS_HOUSE
	warp_def 3, 15, 3, 0, MAP_NEW_BARK_TOWN_OTHER_HOUSE

NewBarkTown_MapCoordEvents::
	coord_event 1, 10, 3, VAR_0x4050, 0, NewBarkTown_EventScript_1E8091
	coord_event 1, 11, 3, VAR_0x4050, 0, NewBarkTown_EventScript_1E80EF
	coord_event 1, 12, 3, VAR_0x4050, 1, NewBarkTown_EventScript_1E811F
	coord_event 1, 13, 3, VAR_0x4050, 3, NewBarkTown_EventScript_1E81F9

NewBarkTown_MapBGEvents::
	bg_event 9, 10, 0, BG_EVENT_PLAYER_FACING_ANY, NewBarkTown_EventScript_1E8151
	bg_event 4, 5, 0, BG_EVENT_PLAYER_FACING_ANY, NewBarkTown_EventScript_1E815A
	bg_event 14, 7, 3, BG_EVENT_PLAYER_FACING_ANY, NewBarkTown_EventScript_1E8163
	bg_event 11, 16, 3, BG_EVENT_PLAYER_FACING_ANY, NewBarkTown_EventScript_1E818F

NewBarkTown_MapEvents::
	map_events NewBarkTown_EventObjects, NewBarkTown_MapWarps, NewBarkTown_MapCoordEvents, NewBarkTown_MapBGEvents
