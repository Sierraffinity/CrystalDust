RuinsOfAlph_InnerChamber_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, RuinsOfAlph_InnerChamber_MapScripts_MAP_SCRIPT_ON_LOAD
	map_script MAP_SCRIPT_ON_TRANSITION, RuinsOfAlph_InnerChamber_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_FRAME_TABLE, RuinsOfAlph_InnerChamber_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

RuinsOfAlph_InnerChamber_MapScripts_MAP_SCRIPT_ON_LOAD:
	goto_if_set FLAG_SOLVED_KABUTO_PUZZLE, RuinsOfAlph_InnerChamber_MapScripts_MAP_SCRIPT_ON_LOAD_2
RuinsOfAlph_InnerChamber_MapScripts_MAP_SCRIPT_ON_LOAD_1:
	goto_if_set FLAG_SOLVED_OMANYTE_PUZZLE, RuinsOfAlph_InnerChamber_MapScripts_MAP_SCRIPT_ON_LOAD_5
RuinsOfAlph_InnerChamber_MapScripts_MAP_SCRIPT_ON_LOAD_4:
	goto_if_set FLAG_SOLVED_AERODACTYL_PUZZLE, RuinsOfAlph_InnerChamber_MapScripts_MAP_SCRIPT_ON_LOAD_8
RuinsOfAlph_InnerChamber_MapScripts_MAP_SCRIPT_ON_LOAD_7:
	goto_if_set FLAG_SOLVED_HOOH_PUZZLE, RuinsOfAlph_InnerChamber_MapScripts_MAP_SCRIPT_ON_LOAD_10
	return

RuinsOfAlph_InnerChamber_MapScripts_MAP_SCRIPT_ON_LOAD_2:
	setmetatile 4, 1, METATILE_RuinsOfAlph_Pillar_Green, TRUE
	goto RuinsOfAlph_InnerChamber_MapScripts_MAP_SCRIPT_ON_LOAD_1

RuinsOfAlph_InnerChamber_MapScripts_MAP_SCRIPT_ON_LOAD_5:
	setmetatile 9, 1, METATILE_RuinsOfAlph_Pillar_Green, TRUE
	goto RuinsOfAlph_InnerChamber_MapScripts_MAP_SCRIPT_ON_LOAD_4

RuinsOfAlph_InnerChamber_MapScripts_MAP_SCRIPT_ON_LOAD_8:
	setmetatile 13, 1, METATILE_RuinsOfAlph_Pillar_Green, TRUE
	goto RuinsOfAlph_InnerChamber_MapScripts_MAP_SCRIPT_ON_LOAD_7

RuinsOfAlph_InnerChamber_MapScripts_MAP_SCRIPT_ON_LOAD_10:
	setmetatile 18, 1, METATILE_RuinsOfAlph_Pillar_Green, TRUE
	return

RuinsOfAlph_InnerChamber_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	setflag FLAG_LANDMARK_ALPH_CHAMBERS
	compare VAR_RUINS_OF_ALPH_STATE, 1
	goto_if_eq RuinsOfAlph_InnerChamber_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	return

RuinsOfAlph_InnerChamber_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
	setflag FLAG_HIDE_MAP_NAME_POPUP
	return

RuinsOfAlph_InnerChamber_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_RUINS_OF_ALPH_STATE, 1, RuinsOfAlph_InnerChamber_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0
	.2byte 0

RuinsOfAlph_InnerChamber_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0:
	lockall
	delay 5
	msgbox RuinsOfAlph_InnerChamber_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_0
	setvar VAR_RUINS_OF_ALPH_STATE, 0
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	releaseall
	return


RuinsOfAlph_InnerChamber_Coward::
	msgbox RuinsOfAlph_InnerChamber_Coward_Text_0, MSGBOX_NPC
	return


RuinsOfAlph_InnerChamber_Woman::
	msgbox RuinsOfAlph_InnerChamber_Woman_Text_0, MSGBOX_NPC
	return


RuinsOfAlph_InnerChamber_OldMan::
	msgbox RuinsOfAlph_InnerChamber_OldMan_Text_0, MSGBOX_NPC
	return


RuinsOfAlph_InnerChamber_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_0:
	.string "There is a strange presence here…$"

RuinsOfAlph_InnerChamber_Coward_Text_0:
	.string "This is a big room, but there's\n"
	.string "nothing here.$"

RuinsOfAlph_InnerChamber_Woman_Text_0:
	.string "This place has a mystical quality\n"
	.string "to it.\p"
	.string "It feels sort of ethereal, even.$"

RuinsOfAlph_InnerChamber_OldMan_Text_0:
	.string "Ancient buildings are often tombs\n"
	.string "of kings.\p"
	.string "Like the pyramids, for instance.$"
