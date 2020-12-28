GoldenrodCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, GoldenrodCity_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

GoldenrodCity_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	setflag FLAG_VISITED_GOLDENROD_CITY
	goto_if_unset FLAG_MET_FLORIA_ROUTE_36, GoldenrodCity_MapScripts_MAP_SCRIPT_ON_TRANSITION_2
GoldenrodCity_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
	goto_if_set FLAG_FLORIA_WENT_TO_ROUTE_36, GoldenrodCity_MapScripts_MAP_SCRIPT_ON_TRANSITION_4
	setflag FLAG_HIDE_ROUTE_36_FLORIA
	clearflag FLAG_HIDE_GOLDENROD_CITY_FLOWER_SHOP_FLORIA
	return

GoldenrodCity_MapScripts_MAP_SCRIPT_ON_TRANSITION_2:
	setflag FLAG_FLORIA_WENT_TO_ROUTE_36
	goto GoldenrodCity_MapScripts_MAP_SCRIPT_ON_TRANSITION_1

GoldenrodCity_MapScripts_MAP_SCRIPT_ON_TRANSITION_4:
	setflag FLAG_HIDE_GOLDENROD_CITY_FLOWER_SHOP_FLORIA
	clearflag FLAG_HIDE_ROUTE_36_FLORIA
	return


GoldenrodCity_EventScript_CreakyRadioTowerMan::
	msgbox GoldenrodCity_EventScript_CreakyRadioTowerMan_Text_0, MSGBOX_NPC
	return


GoldenrodCity_EventScript_NewBikeShopKid::
	msgbox GoldenrodCity_EventScript_NewBikeShopKid_Text_0, MSGBOX_NPC
	return


GoldenrodCity_EventScript_CuriousWoman::
	goto_if_set FLAG_CLEARED_RADIO_TOWER, GoldenrodCity_EventScript_CuriousWoman_1
	msgbox GoldenrodCity_EventScript_CuriousWoman_Text_1, MSGBOX_NPC
	return

GoldenrodCity_EventScript_CuriousWoman_1:
	msgbox GoldenrodCity_EventScript_CuriousWoman_Text_0, MSGBOX_NPC
	return


GoldenrodCity_EventScript_RadioWoman::
	goto_if_set FLAG_SYS_HAS_RADIO_CARD, GoldenrodCity_EventScript_RadioWoman_1
	msgbox GoldenrodCity_EventScript_RadioWoman_Text_1, MSGBOX_NPC
	return

GoldenrodCity_EventScript_RadioWoman_1:
	msgbox GoldenrodCity_EventScript_RadioWoman_Text_0, MSGBOX_NPC
	return


GoldenrodCity_EventScript_BasementKid::
	msgbox GoldenrodCity_EventScript_BasementKid_Text_0, MSGBOX_NPC
	return


GoldenrodCity_EventScript_NameRaterInformerGirl::
	msgbox GoldenrodCity_EventScript_NameRaterInformerGirl_Text_0, MSGBOX_NPC
	return


GoldenrodCity_EventScript_LostOldMan::
	msgbox GoldenrodCity_EventScript_LostOldMan_Text_0, MSGBOX_NPC
	return


GoldenrodCity_EventScript_RocketScout::
	lock
	msgbox GoldenrodCity_EventScript_RocketScout_Text_0
	faceplayer
	msgbox GoldenrodCity_EventScript_RocketScout_Text_1
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	release
	return


GoldenrodCity_EventScript_RocketGrunt1::
	msgbox GoldenrodCity_EventScript_RocketGrunt1_Text_0, MSGBOX_NPC
	return


GoldenrodCity_EventScript_RocketGrunt2::
	msgbox GoldenrodCity_EventScript_RocketGrunt2_Text_0, MSGBOX_NPC
	return


GoldenrodCity_EventScript_RocketGrunt3::
	msgbox GoldenrodCity_EventScript_RocketGrunt3_Text_0, MSGBOX_NPC
	return


GoldenrodCity_EventScript_RocketGrunt4::
	msgbox GoldenrodCity_EventScript_RocketGrunt4_Text_0, MSGBOX_NPC
	return


GoldenrodCity_EventScript_RocketGrunt5::
	msgbox GoldenrodCity_EventScript_RocketGrunt5_Text_0, MSGBOX_NPC
	return


GoldenrodCity_EventScript_RocketGrunt6::
	msgbox GoldenrodCity_EventScript_RocketGrunt6_Text_0, MSGBOX_NPC
	return


GoldenrodCity_EventScript_MagnetTrainStationSign::
	msgbox GoldenrodCity_EventScript_MagnetTrainStationSign_Text_0, MSGBOX_SIGN
	return


GoldenrodCity_EventScript_RadioTowerSign::
	msgbox GoldenrodCity_EventScript_RadioTowerSign_Text_0, MSGBOX_SIGN
	return


GoldenrodCity_EventScript_DeptStoreSign::
	msgbox GoldenrodCity_EventScript_DeptStoreSign_Text_0, MSGBOX_SIGN
	return


GoldenrodCity_EventScript_GymSign::
	msgbox GoldenrodCity_EventScript_GymSign_Text_0, MSGBOX_SIGN
	return


GoldenrodCity_EventScript_CitySloganSign::
	msgbox GoldenrodCity_EventScript_CitySloganSign_Text_0, MSGBOX_SIGN
	return


GoldenrodCity_EventScript_BikeShopSign::
	msgbox GoldenrodCity_EventScript_BikeShopSign_Text_0, MSGBOX_SIGN
	return


GoldenrodCity_EventScript_GameCornerSign::
	msgbox GoldenrodCity_EventScript_GameCornerSign_Text_0, MSGBOX_SIGN
	return


GoldenrodCity_EventScript_NameRaterSign::
	msgbox GoldenrodCity_EventScript_NameRaterSign_Text_0, MSGBOX_SIGN
	return


GoldenrodCity_EventScript_UndergroundEntranceSign::
	msgbox GoldenrodCity_EventScript_UndergroundEntranceSign_Text_0, MSGBOX_SIGN
	return


GoldenrodCity_EventScript_PokecomCenterSign::
	msgbox GoldenrodCity_EventScript_PokecomCenterSign_Text_0, MSGBOX_SIGN
	return


GoldenrodCity_EventScript_FlowerShopSign::
	msgbox GoldenrodCity_EventScript_FlowerShopSign_Text_0, MSGBOX_SIGN
	return


GoldenrodCity_EventScript_CreakyRadioTowerMan_Text_0:
	.string "They built the RADIO TOWER to\n"
	.string "replace the old, creaky one.$"

GoldenrodCity_EventScript_NewBikeShopKid_Text_0:
	.string "I know there's a new BIKE SHOP,\n"
	.string "but I can't find it anywhere.$"

GoldenrodCity_EventScript_CuriousWoman_Text_0:
	.string "Was that man in black really part\n"
	.string "of TEAM ROCKET?\l"
	.string "I can't believe it!$"

GoldenrodCity_EventScript_CuriousWoman_Text_1:
	.string "Is that man in black dressed up\n"
	.string "like a TEAM ROCKET member?\l"
	.string "How silly!$"

GoldenrodCity_EventScript_RadioWoman_Text_0:
	.string "Oh, your POKéGEAR works as a radio!\n"
	.string "How useful!$"

GoldenrodCity_EventScript_RadioWoman_Text_1:
	.string "The RADIO TOWER in GOLDENROD CITY\n"
	.string "is a landmark.\p"
	.string "They're running a promotional\n"
	.string "campaign right now.\p"
	.string "They'll modify your POKéGEAR, so\n"
	.string "it can also serve as a radio.$"

GoldenrodCity_EventScript_BasementKid_Text_0:
	.string "Ehehehe…\p"
	.string "I got in trouble for playing in the\n"
	.string "basement of the DEPT. STORE.$"

GoldenrodCity_EventScript_NameRaterInformerGirl_Text_0:
	.string "The man at that house rates your\n"
	.string "POKéMON names.\p"
	.string "He can even help you rename your\n"
	.string "POKéMON.$"

GoldenrodCity_EventScript_LostOldMan_Text_0:
	.string "Whew! This is one big town.\n"
	.string "I don't know where anything is.$"

GoldenrodCity_EventScript_RocketScout_Text_0:
	.string "So this is the RADIO TOWER…$"

GoldenrodCity_EventScript_RocketScout_Text_1:
	.string "What do you want, you pest?\n"
	.string "Scram!$"

GoldenrodCity_EventScript_RocketGrunt1_Text_0:
	.string "Stay out of the way!\n"
	.string "Beat it!$"

GoldenrodCity_EventScript_RocketGrunt2_Text_0:
	.string "Take over the RADIO TOWER…\p"
	.string "What?\n"
	.string "It's none of your business!$"

GoldenrodCity_EventScript_RocketGrunt3_Text_0:
	.string "POKéMON? They're nothing more than\n"
	.string "tools for making money!$"

GoldenrodCity_EventScript_RocketGrunt4_Text_0:
	.string "Our dream will soon come true…\n"
	.string "It was such a long struggle…$"

GoldenrodCity_EventScript_RocketGrunt5_Text_0:
	.string "Hey, brat!\n"
	.string "You don't belong here!\l"
	.string "Get lost!$"

GoldenrodCity_EventScript_RocketGrunt6_Text_0:
	.string "Come taste the true terror of\n"
	.string "TEAM ROCKET!$"

GoldenrodCity_EventScript_MagnetTrainStationSign_Text_0:
	.string "GOLDENROD CITY STATION$"

GoldenrodCity_EventScript_RadioTowerSign_Text_0:
	.string "GOLDENROD CITY RADIO TOWER$"

GoldenrodCity_EventScript_DeptStoreSign_Text_0:
	.string "Full Selection of POKéMON Goods!\n"
	.string "GOLDENROD CITY DEPT. STORE$"

GoldenrodCity_EventScript_GymSign_Text_0:
	.string "GOLDENROD CITY POKéMON GYM\n"
	.string "LEADER: WHITNEY\p"
	.string "The Incredibly Pretty Girl!$"

GoldenrodCity_EventScript_CitySloganSign_Text_0:
	.string "GOLDENROD CITY\n"
	.string "The Festive City of Opulent Charm$"

GoldenrodCity_EventScript_BikeShopSign_Text_0:
	.string "The World is a Cycle Path!\n"
	.string "BIKE SHOP$"

GoldenrodCity_EventScript_GameCornerSign_Text_0:
	.string "Your Playground!\n"
	.string "GOLDENROD CITY GAME CORNER$"

GoldenrodCity_EventScript_NameRaterSign_Text_0:
	.string "NAME RATER\n"
	.string "Get Your POKéMON Nicknames Rated$"

GoldenrodCity_EventScript_UndergroundEntranceSign_Text_0:
	.string "UNDERGROUND ENTRANCE$"

GoldenrodCity_EventScript_PokecomCenterSign_Text_0:
	.string "For Mobile Tips!\n"
	.string "POKéCOM CENTER$"

GoldenrodCity_EventScript_FlowerShopSign_Text_0:
	.string "Blooming Beautiful\n"
	.string "FLOWER SHOP$"
