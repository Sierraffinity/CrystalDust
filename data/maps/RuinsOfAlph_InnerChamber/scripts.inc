RuinsOfAlph_InnerChamber_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RuinsOfAlph_InnerChamber_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_FRAME_TABLE, RuinsOfAlph_InnerChamber_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

RuinsOfAlph_InnerChamber_MapScripts_MAP_SCRIPT_ON_TRANSITION:
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
