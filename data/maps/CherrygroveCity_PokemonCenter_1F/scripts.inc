CherrygroveCity_PokemonCenter_1F_MapScripts:: @ 81FC006
	map_script 3, CherrygroveCity_PokemonCenter_1F_MapScript1_1FC011
	map_script 5, CherrygroveCity_PokemonCenter_1F_MapScript1_277C30
	.byte 0

CherrygroveCity_PokemonCenter_1F_MapScript1_1FC011: @ 81FC011
	setrespawn HEAL_LOCATION_CHERRYGROVE_CITY
	call CherrygroveCity_PokemonCenter_1F_EventScript_2718DE
	end

CherrygroveCity_PokemonCenter_1F_EventScript_1FC01A:: @ 81FC01A
	setvar VAR_0x800B, 1
	call CherrygroveCity_PokemonCenter_1F_EventScript_27191E
	waitmessage
	waitbuttonpress
	release
	end

CherrygroveCity_PokemonCenter_1F_EventScript_1FC028:: @ 81FC028
	msgbox CherrygroveCity_PokemonCenter_1F_Text_1FC059, MSGBOX_NPC
	end

CherrygroveCity_PokemonCenter_1F_EventScript_1FC031:: @ 81FC031
	msgbox CherrygroveCity_PokemonCenter_1F_Text_1FC0CD, MSGBOX_NPC
	end

CherrygroveCity_PokemonCenter_1F_EventScript_1FC03A:: @ 81FC03A
	lock
	faceplayer
	goto_if_set FLAG_SYS_POKEDEX_GET, CherrygroveCity_PokemonCenter_1F_EventScript_1FC04F
	msgbox CherrygroveCity_PokemonCenter_1F_Text_1FC148, MSGBOX_DEFAULT
	release
	end

CherrygroveCity_PokemonCenter_1F_EventScript_1FC04F:: @ 81FC04F
	msgbox CherrygroveCity_PokemonCenter_1F_Text_1FC1B9, MSGBOX_DEFAULT
	release
	end

CherrygroveCity_PokemonCenter_1F_Text_1FC059: @ 81FC059
	.string "That PC in the corner there is\n"
	.string "for any POKéMON TRAINER to use.\p"
	.string "Naturally, that means you're welcome\n"
	.string "to use it, too.$"

CherrygroveCity_PokemonCenter_1F_Text_1FC0CD: @ 81FC0CD
	.string "POKéMON CENTERS are great!\p"
	.string "You can use their services as much\n"
	.string "as you like, and it's all for free.\l"
	.string "You never have to worry!$"

CherrygroveCity_PokemonCenter_1F_Text_1FC148: @ 81FC148
	.string "The POKéMON WIRELESS CLUB on\n"
	.string "the second floor was built recently.\p"
	.string "But they say they're still making\n"
	.string "adjustments.$"

CherrygroveCity_PokemonCenter_1F_Text_1FC1B9: @ 81FC1B9
	.string "The POKéMON WIRELESS CLUB on\n"
	.string "the second floor was built recently.\p"
	.string "I traded POKéMON right away.$"

