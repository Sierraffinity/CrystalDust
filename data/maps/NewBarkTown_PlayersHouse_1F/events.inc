NewBarkTown_PlayersHouse_1F_EventObjects:
	object_event 1, EVENT_OBJ_GFX_MOM, 0, 8, 5, 3, MOVEMENT_TYPE_FACE_LEFT, 0, 0, 0, 0, NewBarkTown_PlayersHouse_1F_MomTalk, FLAG_HIDE_NEW_BARK_TOWN_PLAYERS_HOUSE_MOM
	object_event 2, EVENT_OBJ_GFX_WOMAN_4, 0, 5, 5, 3, MOVEMENT_TYPE_FACE_RIGHT, 3, 0, 0, 0, NewBarkTown_PlayersHouse_1F_NeighborTalk, 0

NewBarkTown_PlayersHouse_1F_MapWarps:
	warp_def 8, 8, 3, 0, MAP_NEW_BARK_TOWN
	warp_def 9, 2, 3, 0, MAP_NEW_BARK_TOWN_PLAYERS_HOUSE_2F

NewBarkTown_PlayersHouse_1F_MapBGEvents:
	bg_event 0, 1, 3, BG_EVENT_PLAYER_FACING_ANY, NewBarkTown_PlayersHouse_1F_Sink
	bg_event 1, 1, 3, BG_EVENT_PLAYER_FACING_ANY, NewBarkTown_PlayersHouse_1F_Stove
	bg_event 2, 1, 3, BG_EVENT_PLAYER_FACING_ANY, NewBarkTown_PlayersHouse_1F_Fridge
	bg_event 6, 1, 3, BG_EVENT_PLAYER_FACING_ANY, NewBarkTown_PlayersHouse_1F_TV

NewBarkTown_PlayersHouse_1F_MapEvents::
	map_events NewBarkTown_PlayersHouse_1F_EventObjects, NewBarkTown_PlayersHouse_1F_MapWarps, 0x0, NewBarkTown_PlayersHouse_1F_MapBGEvents

