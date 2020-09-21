GoldenrodCity_House3_MapScripts:: @ 8216190
	.byte 0

GoldenrodCity_House3_EventScript_OldMan:: @ 8216191
	msgbox GoldenrodCity_House3_Text_IGivePerfectlySuitedNicknames, MSGBOX_NPC
	end

GoldenrodCity_House3_EventScript_OldWoman:: @ 821619A
	msgbox GoldenrodCity_House3_Text_NamingPikachuPekachu, MSGBOX_NPC
	end

@ Misspelling on purpose, see nickname
GoldenrodCity_House3_EventScript_Pekachu:: @ 82161A3
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PIKACHU, 0
	msgbox GoldenrodCity_House3_Text_Pekachu, MSGBOX_DEFAULT
	waitmoncry
	release
	end

GoldenrodCity_House3_Text_IGivePerfectlySuitedNicknames: @ 82161B6
	.string "For my own POKéMON, I give them\n"
	.string "perfectly suited nicknames!\p"
	.string "It's my expression of, uh…\n"
	.string "originality, yes, that's it!$"

GoldenrodCity_House3_Text_NamingPikachuPekachu: @ 821622A
	.string "But giving the name PEKACHU to\n"
	.string "a PIKACHU? It seems pointless.\p"
	.string "I suppose it is good to use a name\n"
	.string "that's easy to understand, but…$"

GoldenrodCity_House3_Text_Pekachu: @ 82162AB
	.string "PEKACHU: Peka!$"

