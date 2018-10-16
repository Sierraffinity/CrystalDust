LittlerootTown_BrendansHouse_1F_EventObjects::
	object_event 1, EVENT_OBJ_GFX_MOM, 0, 8, 6, 3, MOVEMENT_TYPE_FACE_RIGHT, 0, 0, 0, 0, LittlerootTown_BrendansHouse_1F_EventScript_2929C5, 758
	object_event 2, EVENT_OBJ_GFX_MOM, 0, 0, 2, 3, MOVEMENT_TYPE_FACE_UP, 3, 0, 0, 0, LittlerootTown_BrendansHouse_1F_EventScript_292ACD, 755
	object_event 3, EVENT_OBJ_GFX_VIGOROTH_FACING_AWAY, 0, 2, 2, 3, MOVEMENT_TYPE_FACE_UP, 0, 0, 0, 0, LittlerootTown_BrendansHouse_1F_EventScript_292ABA, 754
	object_event 4, EVENT_OBJ_GFX_WOMAN_5, 0, 5, 6, 3, MOVEMENT_TYPE_FACE_RIGHT, 0, 0, 0, 0, LittlerootTown_BrendansHouse_1F_EventScript_1F89F3, 784

LittlerootTown_BrendansHouse_1F_MapWarps::
	warp_def 8, 8, 0, 1, MAP_LITTLEROOT_TOWN
	warp_def 7, 8, 0, 1, MAP_LITTLEROOT_TOWN
	warp_def 9, 2, 0, 0, MAP_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F

LittlerootTown_BrendansHouse_1F_MapCoordEvents::
	coord_event 8, 8, 0, VAR_0x4092, 4, LittlerootTown_BrendansHouse_1F_EventScript_1F78A3
	coord_event 7, 3, 0, VAR_0x408D, 2, LittlerootTown_BrendansHouse_1F_EventScript_1F78BE
	coord_event 9, 6, 0, VAR_0x408D, 2, LittlerootTown_BrendansHouse_1F_EventScript_1F78CA
	coord_event 10, 6, 0, VAR_0x408D, 2, LittlerootTown_BrendansHouse_1F_EventScript_1F78D6

LittlerootTown_BrendansHouse_1F_MapEvents::
	map_events LittlerootTown_BrendansHouse_1F_EventObjects, LittlerootTown_BrendansHouse_1F_MapWarps, LittlerootTown_BrendansHouse_1F_MapCoordEvents, 0x0
