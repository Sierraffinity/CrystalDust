NewBarkTown_EventObjects:
	object_event 1, EVENT_OBJ_GFX_FAT_MAN, 0, 15, 11, 3, MOVEMENT_TYPE_WANDER_UP_AND_DOWN, 0, 1, 0, 0, NewBarkTown_EventScript_FatMan, 0
	object_event 2, EVENT_OBJ_GFX_WOMAN_1, 0, 7, 10, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, NewBarkTown_EventScript_Teacher, 0
	object_event 3, EVENT_OBJ_GFX_RIVAL, 0, 4, 3, 3, MOVEMENT_TYPE_FACE_RIGHT, 0, 0, 0, 0, NewBarkTown_EventScript_Rival, 0

NewBarkTown_MapWarps:
	warp_def 16, 7, 3, 0, MAP_NEW_BARK_TOWN_PLAYERS_HOUSE_1F
	warp_def 8, 5, 3, 0, MAP_NEW_BARK_TOWN_PROFESSOR_ELMS_LAB
	warp_def 13, 16, 3, 0, MAP_NEW_BARK_TOWN_ELMS_HOUSE
	warp_def 3, 15, 3, 0, MAP_NEW_BARK_TOWN_NEIGHBORS_HOUSE

NewBarkTown_MapCoordEvents:
	coord_event 1, 10, 3, VAR_0x4050, 1, NewBarkTown_EventScript_Teacher2
	coord_event 1, 11, 3, VAR_0x4050, 1, NewBarkTown_EventScript_Teacher2
	coord_event 1, 12, 3, VAR_0x4050, 1, NewBarkTown_EventScript_Teacher3

NewBarkTown_MapBGEvents:
	bg_event 9, 10, 0, BG_EVENT_PLAYER_FACING_ANY, NewBarkTown_EventScript_Slogan
	bg_event 4, 5, 0, BG_EVENT_PLAYER_FACING_ANY, NewBarkTown_EventScript_ElmLab
	bg_event 14, 7, 0, BG_EVENT_PLAYER_FACING_ANY, NewBarkTown_EventScript_PlayersHouse
	bg_event 11, 16, 0, BG_EVENT_PLAYER_FACING_ANY, NewBarkTown_EventScript_ElmsHouse

NewBarkTown_MapEvents::
	map_events NewBarkTown_EventObjects, NewBarkTown_MapWarps, NewBarkTown_MapCoordEvents, NewBarkTown_MapBGEvents

