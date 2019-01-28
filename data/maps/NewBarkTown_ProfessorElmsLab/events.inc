NewBarkTown_ProfessorElmsLab_EventObjects::
	object_event 1, EVENT_OBJ_GFX_SCIENTIST, 0, 3, 10, 3, MOVEMENT_TYPE_LOOK_AROUND, 1, 1, 0, 0, NewBarkTown_ProfessorElmsLab_EventScript_1F9F84, 0
	object_event 2, EVENT_OBJ_GFX_PROF_ELM, 0, 6, 4, 3, MOVEMENT_TYPE_FACE_DOWN, 0, 0, 0, 0, NewBarkTown_ProfessorElmsLab_EventScript_1FA25A, FLAG_HIDE_NEW_BARK_TOWN_BIRCHS_LAB_BIRCH
	object_event 3, EVENT_OBJ_GFX_OFFICER, 0, 6, 5, 3, MOVEMENT_TYPE_FACE_UP, 1, 1, 0, 0, NewBarkTown_ProfessorElmsLab_EventScript_1FA3EC, FLAG_HIDE_NEW_BARK_TOWN_ELMS_LAB_OFFICER
	object_event 4, EVENT_OBJ_GFX_ITEM_BALL, 0, 10, 4, 3, MOVEMENT_TYPE_FACE_DOWN, 1, 1, 0, 0, NewBarkTown_ProfessorElmsLab_EventScript_1F9FBB, FLAG_HIDE_NEW_BARK_TOWN_BIRCHS_LAB_POKEBALL_CYNDAQUIL
	object_event 5, EVENT_OBJ_GFX_ITEM_BALL, 0, 9, 4, 3, MOVEMENT_TYPE_FACE_DOWN, 1, 1, 0, 0, NewBarkTown_ProfessorElmsLab_EventScript_1F9FEF, FLAG_HIDE_NEW_BARK_TOWN_BIRCHS_LAB_POKEBALL_TOTODILE
	object_event 6, EVENT_OBJ_GFX_ITEM_BALL, 0, 8, 4, 3, MOVEMENT_TYPE_FACE_DOWN, 1, 1, 0, 0, NewBarkTown_ProfessorElmsLab_EventScript_1FA023, FLAG_HIDE_NEW_BARK_TOWN_BIRCHS_LAB_POKEBALL_CHIKORITA

NewBarkTown_ProfessorElmsLab_MapWarps::
	warp_def 6, 12, 0, 1, MAP_NEW_BARK_TOWN

NewBarkTown_ProfessorElmsLab_MapBGEvents::
	bg_event 2, 1, 0, BG_EVENT_PLAYER_FACING_ANY, NewBarkTown_ProfessorElmsLab_EventScript_1FA3E3
	bg_event 7, 1, 0, BG_EVENT_PLAYER_FACING_ANY, NewBarkTown_ProfessorElmsLab_EventScript_1FA3E3
	bg_event 11, 4, 0, BG_EVENT_PLAYER_FACING_ANY, NewBarkTown_ProfessorElmsLab_EventScript_1FA4CD
	bg_event 1, 8, 0, BG_EVENT_PLAYER_FACING_ANY, NewBarkTown_ProfessorElmsLab_EventScript_1FA4C4
	bg_event 2, 8, 0, BG_EVENT_PLAYER_FACING_ANY, NewBarkTown_ProfessorElmsLab_EventScript_1FA4C4
	bg_event 3, 8, 0, BG_EVENT_PLAYER_FACING_ANY, NewBarkTown_ProfessorElmsLab_EventScript_1FA4C4
	bg_event 4, 8, 0, BG_EVENT_PLAYER_FACING_ANY, NewBarkTown_ProfessorElmsLab_EventScript_1FA4C4

NewBarkTown_ProfessorElmsLab_MapEvents::
	map_events NewBarkTown_ProfessorElmsLab_EventObjects, NewBarkTown_ProfessorElmsLab_MapWarps, 0x0, NewBarkTown_ProfessorElmsLab_MapBGEvents
