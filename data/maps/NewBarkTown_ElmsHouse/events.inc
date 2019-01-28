NewBarkTown_ElmsHouse_EventObjects::
	object_event 1, EVENT_OBJ_GFX_WOMAN_1, 0, 2, 5, 3, MOVEMENT_TYPE_WANDER_UP_AND_DOWN, 1, 1, 0, 0, NewBarkTown_ElmsHouse_EventScript_ElmsWife, 0
	object_event 2, EVENT_OBJ_GFX_LITTLE_BOY, 0, 7, 5, 3, MOVEMENT_TYPE_FACE_UP, 0, 0, FALSE, 0, NewBarkTown_ElmsHouse_EventScript_ElmsSon, 0

NewBarkTown_ElmsHouse_MapWarps::
	warp_def 4, 7, 0, 2, MAP_NEW_BARK_TOWN

NewBarkTown_ElmsHouse_MapBGEvents::
	bg_event 0, 1, 3, BG_EVENT_PLAYER_FACING_ANY, EventScript_DifficultBookShelf
	bg_event 1, 1, 3, BG_EVENT_PLAYER_FACING_ANY, NewBarkTown_ElmsHouse_EventScript_ResearchPaper
	bg_event 2, 1, 3, BG_EVENT_PLAYER_FACING_ANY, NewBarkTown_ElmsHouse_EventScript_ResearchPaper
	bg_event 9, 1, 3, BG_EVENT_PLAYER_FACING_ANY, EventScript_DifficultBookShelf
	bg_event 10, 1, 3, BG_EVENT_PLAYER_FACING_ANY, EventScript_DifficultBookShelf

NewBarkTown_ElmsHouse_MapEvents::
	map_events NewBarkTown_ElmsHouse_EventObjects, NewBarkTown_ElmsHouse_MapWarps, 0x0, NewBarkTown_ElmsHouse_MapBGEvents
