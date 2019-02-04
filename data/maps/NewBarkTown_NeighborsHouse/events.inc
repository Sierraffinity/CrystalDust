NewBarkTown_NeighborsHouse_EventObjects:
	object_event 1, EVENT_OBJ_GFX_GIRL_1, 0, 4, 4, 3, MOVEMENT_TYPE_FACE_RIGHT, 0, 0, 0, 0, NewBarkTown_NeighborsHouse_EventScript_Girl, 0
	object_event 2, EVENT_OBJ_GFX_WOMAN_4, 0, 7, 4, 3, MOVEMENT_TYPE_FACE_LEFT, 0, 0, 0, 0, NewBarkTown_NeighborsHouse_EventScript_Woman, FLAG_HIDE_NEW_BARK_TOWN_NEIGHBORS_HOUSE_NEIGHBOR

NewBarkTown_NeighborsHouse_MapWarps:
	warp_def 4, 7, 0, 3, MAP_NEW_BARK_TOWN

NewBarkTown_NeighborsHouse_MapBGEvents:
	bg_event 10, 1, 3, BG_EVENT_PLAYER_FACING_ANY, NewBarkTown_PlayersHouse_2F_Radio

NewBarkTown_NeighborsHouse_MapEvents::
	map_events NewBarkTown_NeighborsHouse_EventObjects, NewBarkTown_NeighborsHouse_MapWarps, 0x0, NewBarkTown_NeighborsHouse_MapBGEvents

