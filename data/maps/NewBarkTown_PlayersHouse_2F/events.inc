NewBarkTown_PlayersHouse_2F_EventObjects:
	object_event 1, EVENT_OBJ_GFX_VAR_0, 0, 0, 0, 0, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, 0x0, FLAG_DECORATION_1
	object_event 2, EVENT_OBJ_GFX_VAR_1, 0, 0, 1, 0, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, 0x0, FLAG_DECORATION_2
	object_event 3, EVENT_OBJ_GFX_VAR_2, 0, 0, 2, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, 0x0, FLAG_DECORATION_3
	object_event 4, EVENT_OBJ_GFX_VAR_3, 0, 0, 3, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, 0x0, FLAG_DECORATION_4
	object_event 5, EVENT_OBJ_GFX_VAR_4, 0, 0, 4, 0, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, 0x0, FLAG_DECORATION_5
	object_event 6, EVENT_OBJ_GFX_VAR_5, 0, 0, 5, 4, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, 0x0, FLAG_DECORATION_6
	object_event 7, EVENT_OBJ_GFX_VAR_6, 0, 1, 0, 0, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, 0x0, FLAG_DECORATION_7
	object_event 8, EVENT_OBJ_GFX_VAR_7, 0, 1, 1, 0, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, 0x0, FLAG_DECORATION_8
	object_event 9, EVENT_OBJ_GFX_VAR_8, 0, 1, 2, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, 0x0, FLAG_DECORATION_9
	object_event 10, EVENT_OBJ_GFX_VAR_9, 0, 1, 3, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, 0x0, FLAG_DECORATION_10
	object_event 11, EVENT_OBJ_GFX_VAR_A, 0, 1, 4, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, 0x0, FLAG_DECORATION_11
	object_event 12, EVENT_OBJ_GFX_VAR_B, 0, 1, 5, 0, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, 0x0, FLAG_DECORATION_12

NewBarkTown_PlayersHouse_2F_MapWarps:
	warp_def 9, 2, 0, 1, MAP_NEW_BARK_TOWN_PLAYERS_HOUSE_1F

NewBarkTown_PlayersHouse_2F_MapBGEvents:
	bg_event 1, 1, 0, BG_EVENT_PLAYER_FACING_NORTH, EventScript_PlayerPC
	bg_event 2, 1, 0, BG_EVENT_PLAYER_FACING_ANY, NewBarkTown_PlayersHouse_2F_Radio
	bg_event 5, 1, 0, BG_EVENT_PLAYER_FACING_ANY, EventScript_PictureBookShelf
	bg_event 6, 1, 0, BG_EVENT_PLAYER_FACING_ANY, EventScript_PictureBookShelf

NewBarkTown_PlayersHouse_2F_MapEvents::
	map_events NewBarkTown_PlayersHouse_2F_EventObjects, NewBarkTown_PlayersHouse_2F_MapWarps, 0x0, NewBarkTown_PlayersHouse_2F_MapBGEvents

