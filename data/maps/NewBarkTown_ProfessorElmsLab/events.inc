NewBarkTown_ProfessorElmsLab_EventObjects::
	object_event 1, EVENT_OBJ_GFX_SCIENTIST, 0, 3, 10, 3, MOVEMENT_TYPE_LOOK_AROUND, 1, 1, 0, 0, NewBarkTown_ProfessorElmsLab_EventScript_Aide, 0
	object_event 2, EVENT_OBJ_GFX_PROF_ELM, 0, 6, 3, 3, MOVEMENT_TYPE_FACE_DOWN, 0, 0, 0, 0, NewBarkTown_ProfessorElmsLab_EventScript_Elm, 0
	object_event 3, EVENT_OBJ_GFX_OFFICER, 0, 6, 4, 3, MOVEMENT_TYPE_FACE_UP, 1, 1, 0, 0, NULL, FLAG_HIDE_NEW_BARK_TOWN_ELMS_LAB_OFFICER
	object_event 4, EVENT_OBJ_GFX_ITEM_BALL, 0, 8, 4, 3, MOVEMENT_TYPE_FACE_DOWN, 1, 1, 0, 0, NewBarkTown_ProfessorElmsLab_EventScript_Cyndaquil, FLAG_HIDE_NEW_BARK_TOWN_ELMS_LAB_POKEBALL_CYNDAQUIL
	object_event 5, EVENT_OBJ_GFX_ITEM_BALL, 0, 9, 4, 3, MOVEMENT_TYPE_FACE_DOWN, 1, 1, 0, 0, NewBarkTown_ProfessorElmsLab_EventScript_Totodile, FLAG_HIDE_NEW_BARK_TOWN_ELMS_LAB_POKEBALL_TOTODILE
	object_event 6, EVENT_OBJ_GFX_ITEM_BALL, 0, 10, 4, 3, MOVEMENT_TYPE_FACE_DOWN, 1, 1, 0, 0, NewBarkTown_ProfessorElmsLab_EventScript_Chikorita, FLAG_HIDE_NEW_BARK_TOWN_ELMS_LAB_POKEBALL_CHIKORITA

NewBarkTown_ProfessorElmsLab_MapWarps::
	warp_def 6, 12, 0, 1, MAP_NEW_BARK_TOWN

NewBarkTown_ProfessorElmsLab_MapCoordEvents::
	coord_event 5, 8, 3, VAR_0x4050, 2, NewBarkTown_ProfessorElmsLab_EventScript_ElmWaitDontGo
	coord_event 6, 8, 3, VAR_0x4050, 2, NewBarkTown_ProfessorElmsLab_EventScript_ElmWaitDontGo
	coord_event 7, 8, 3, VAR_0x4050, 2, NewBarkTown_ProfessorElmsLab_EventScript_ElmWaitDontGo
	coord_event 5, 9, 3, VAR_0x4051, 0, NewBarkTown_ProfessorElmsLab_EventScript_AidePotion1
	coord_event 6, 9, 3, VAR_0x4051, 0, NewBarkTown_ProfessorElmsLab_EventScript_AidePotion2
	coord_event 7, 9, 3, VAR_0x4051, 0, NewBarkTown_ProfessorElmsLab_EventScript_AidePotion3

NewBarkTown_ProfessorElmsLab_MapBGEvents::
	bg_event 2, 1, 0, BG_EVENT_PLAYER_FACING_ANY, NewBarkTown_ProfessorElmsLab_EventScript_HealingMachine
	bg_event 3, 1, 0, BG_EVENT_PLAYER_FACING_ANY, NewBarkTown_ProfessorElmsLab_EventScript_HealingMachine
	bg_event 7, 1, 0, BG_EVENT_PLAYER_FACING_ANY, NewBarkTown_ProfessorElmsLab_EventScript_OpenWindow
	bg_event 11, 4, 0, BG_EVENT_PLAYER_FACING_ANY, NewBarkTown_ProfessorElmsLab_EventScript_TrashCan
	bg_event 3, 6, 0, BG_EVENT_PLAYER_FACING_SOUTH, NewBarkTown_ProfessorElmsLab_EventScript_ElmsPC
	bg_event 4, 6, 0, BG_EVENT_PLAYER_FACING_SOUTH, NewBarkTown_ProfessorElmsLab_EventScript_ElmsPC
	bg_event 2, 8, 0, BG_EVENT_PLAYER_FACING_ANY, NewBarkTown_ProfessorElmsLab_EventScript_Shelf2
	bg_event 1, 8, 3, BG_EVENT_PLAYER_FACING_ANY, NewBarkTown_ProfessorElmsLab_EventScript_Shelf1
	bg_event 3, 8, 3, BG_EVENT_PLAYER_FACING_ANY, NewBarkTown_ProfessorElmsLab_EventScript_Shelf3
	bg_event 4, 8, 3, BG_EVENT_PLAYER_FACING_ANY, NewBarkTown_ProfessorElmsLab_EventScript_Shelf4

NewBarkTown_ProfessorElmsLab_MapEvents::
	map_events NewBarkTown_ProfessorElmsLab_EventObjects, NewBarkTown_ProfessorElmsLab_MapWarps, NewBarkTown_ProfessorElmsLab_MapCoordEvents, NewBarkTown_ProfessorElmsLab_MapBGEvents
