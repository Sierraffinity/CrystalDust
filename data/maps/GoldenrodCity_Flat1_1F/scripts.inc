GoldenrodCity_GameCorner_MapScripts:: @ 82150CD
	.byte 0

GoldenrodCity_GameCorner_EventScript_Man:: @ 82150CE
	msgbox GoldenrodCity_GameCorner_Text_EveryPokemonHasAbility, MSGBOX_NPC
	end

GoldenrodCity_GameCorner_EventScript_Woman:: @ 82150D7
	msgbox GoldenrodCity_GameCorner_Text_PokemonStrange, MSGBOX_NPC
	end

GoldenrodCity_GameCorner_Text_EveryPokemonHasAbility: @ 82150E0
	.string "Every POKéMON has a special ability\n"
	.string "that it can use.$"

GoldenrodCity_GameCorner_Text_PokemonStrange: @ 8215115
	.string "POKéMON are such strange creatures.$"

