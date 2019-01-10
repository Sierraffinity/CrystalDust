NewBarkTown_HirosHouse_1F_EventObjects::
	object_event 1, EVENT_OBJ_GFX_MOM, 0, 2, 6, 3, MOVEMENT_TYPE_FACE_RIGHT, 0, 0, 0, 0, NewBarkTown_HirosHouse_1F_EventScript_2929C5, FLAG_HIDE_NEW_BARK_TOWN_HIROS_HOUSE_MOM
	object_event 2, EVENT_OBJ_GFX_VIGOROTH_CARRYING_BOX, 0, 1, 3, 3, MOVEMENT_TYPE_WALK_RIGHT_AND_LEFT, 3, 0, 0, 0, NewBarkTown_HirosHouse_1F_EventScript_292ACD, FLAG_HIDE_NEW_BARK_TOWN_PLAYERS_HOUSE_VIGOROTH_2
	object_event 3, EVENT_OBJ_GFX_VIGOROTH_FACING_AWAY, 0, 4, 5, 3, MOVEMENT_TYPE_WALK_IN_PLACE_UP, 0, 0, 0, 0, NewBarkTown_HirosHouse_1F_EventScript_292ABA, FLAG_HIDE_NEW_BARK_TOWN_PLAYERS_HOUSE_VIGOROTH_1
	object_event 4, EVENT_OBJ_GFX_WOMAN_4, 0, 2, 7, 3, MOVEMENT_TYPE_FACE_RIGHT, 0, 0, 0, 0, NewBarkTown_HirosHouse_1F_EventScript_1F89F3, FLAG_HIDE_NEW_BARK_TOWN_HIROS_HOUSE_RIVAL_MOM
	object_event 5, EVENT_OBJ_GFX_NORMAN, 0, 5, 6, 3, MOVEMENT_TYPE_FACE_LEFT, 1, 1, 0, 0, 0x0, FLAG_HIDE_PLAYERS_HOUSE_DAD
	object_event 6, EVENT_OBJ_GFX_NINJA_BOY, 0, 1, 5, 3, MOVEMENT_TYPE_WANDER_LEFT_AND_RIGHT, 1, 1, 0, 0, NewBarkTown_HirosHouse_1F_EventScript_1F8A3D, FLAG_HIDE_NEW_BARK_TOWN_HIROS_HOUSE_RIVAL_SIBLING
	object_event 7, EVENT_OBJ_GFX_RIVAL_BRENDAN_NORMAL, 0, 9, 8, 3, MOVEMENT_TYPE_FACE_UP, 1, 1, 0, 0, 0x0, FLAG_HIDE_NEW_BARK_TOWN_HIROS_HOUSE_BRENDAN

NewBarkTown_HirosHouse_1F_MapWarps::
	warp_def 8, 8, 3, 0, MAP_NEW_BARK_TOWN
	warp_def 9, 2, 3, 0, MAP_NEW_BARK_TOWN_HIROS_HOUSE_2F

NewBarkTown_HirosHouse_1F_MapCoordEvents::
	coord_event 6, 8, 0, VAR_0x4092, 4, NewBarkTown_HirosHouse_1F_EventScript_1F78A3
	coord_event 7, 3, 0, VAR_0x408D, 2, NewBarkTown_HirosHouse_1F_EventScript_1F78BE
	coord_event 9, 6, 0, VAR_0x408D, 2, NewBarkTown_HirosHouse_1F_EventScript_1F78CA
	coord_event 10, 6, 0, VAR_0x408D, 2, NewBarkTown_HirosHouse_1F_EventScript_1F78D6

NewBarkTown_HirosHouse_1F_MapEvents::
	map_events NewBarkTown_HirosHouse_1F_EventObjects, NewBarkTown_HirosHouse_1F_MapWarps, NewBarkTown_HirosHouse_1F_MapCoordEvents, 0x0
