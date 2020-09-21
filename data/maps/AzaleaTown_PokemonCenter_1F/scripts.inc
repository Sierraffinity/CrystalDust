AzaleaTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, AzaleaTown_PokemonCenter_1F_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

AzaleaTown_PokemonCenter_1F_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	setrespawn HEAL_LOCATION_AZALEA_TOWN
	return


AzaleaTown_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, 1
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	return


AzaleaTown_PokemonCenter_1F_EventScript_Gentleman::
	msgbox AzaleaTown_PokemonCenter_1F_EventScript_Gentleman_Text_0, MSGBOX_NPC
	return


AzaleaTown_PokemonCenter_1F_EventScript_Fisherman::
	msgbox AzaleaTown_PokemonCenter_1F_EventScript_Fisherman_Text_0, MSGBOX_NPC
	return


AzaleaTown_PokemonCenter_1F_EventScript_Woman::
	msgbox AzaleaTown_PokemonCenter_1F_EventScript_Woman_Text_0, MSGBOX_NPC
	return


AzaleaTown_PokemonCenter_1F_EventScript_Gentleman_Text_0:
	.string "Do your POKéMON know HM moves?\p"
	.string "Those moves can be used even if\n"
	.string "your POKéMON has fainted.$"

AzaleaTown_PokemonCenter_1F_EventScript_Fisherman_Text_0:
	.string "BILL's PC can store up to 30\n"
	.string "POKéMON per box.$"

AzaleaTown_PokemonCenter_1F_EventScript_Woman_Text_0:
	.string "Do you know about the fruits called\n"
	.string "APRICORNS?\p"
	.string "If you crack one open, hollow it out\n"
	.string "and fit it with a special device,\l"
	.string "you can catch POKéMON with it.\p"
	.string "Before POKé BALLS were invented,\n"
	.string "everyone used APRICORNS.$"
