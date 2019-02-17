CherrygroveCity_PokemonCenter_1F_MapScripts::
	map_script 3, CherrygroveCity_PokemonCenter_1F_MapScript1_1FC011
	map_script 5, CherrygroveCity_PokemonCenter_1F_MapScript1_277C30
	.byte 0

CherrygroveCity_PokemonCenter_1F_MapScript1_1FC011:
	setrespawn HEAL_LOCATION_CHERRYGROVE_CITY
	call CherrygroveCity_PokemonCenter_1F_EventScript_2718DE
	end

CherrygroveCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, 1
	call EventScript_Nurse
	waitmessage
	waitbuttonpress
	release
	end

CherrygroveCity_PokemonCenter_1F_EventScript_FatMan::
	msgbox CherrygroveCity_PokemonCenter_1F_Text_FatMan, MSGBOX_NPC
	end

CherrygroveCity_PokemonCenter_1F_EventScript_Gentleman::
	msgbox CherrygroveCity_PokemonCenter_1F_Text_Gentleman, MSGBOX_NPC
	end

CherrygroveCity_PokemonCenter_1F_EventScript_Teacher::
	lock
	faceplayer
	goto_if_set FLAG_ADVENTURE_STARTED, CherrygroveCity_PokemonCenter_1F_EventScript_1FC04F
	msgbox CherrygroveCity_PokemonCenter_1F_Text_1FC148, MSGBOX_DEFAULT
	release
	end

CherrygroveCity_PokemonCenter_1F_EventScript_1FC04F::
	msgbox CherrygroveCity_PokemonCenter_1F_Text_1FC1B9, MSGBOX_DEFAULT
	release
	end

CherrygroveCity_PokemonCenter_1F_Text_FatMan:
	.string "It's great! I can store any number\n"
	.string "of POKéMON, and it's all free.$"

CherrygroveCity_PokemonCenter_1F_Text_Gentleman: @ 81FC0CD
	.string "That PC in the corner is free for\n"
	.string "any TRAINER to use.$"

CherrygroveCity_PokemonCenter_1F_Text_1FC148: @ 81FC148
	.string "The POKéMON WIRELESS CLUB upstairs\n"
	.string "was just built.\p"
	.string "But they're still finishing it up.$"

CherrygroveCity_PokemonCenter_1F_Text_1FC1B9: @ 81FC1B9
	.string "The POKéMON WIRELESS CLUB upstairs\n"
	.string "was just built.\p"
	.string "I traded POKéMON there already!$"

