IndigoPlateau_PokemonCenter_1F_MapScripts::
	.byte 0


IndigoPlateau_PokemonCenter_1F_Eventscript_Guy::
	msgbox IndigoPlateau_PokemonCenter_1F_Eventscript_Guy_Text_0, MSGBOX_NPC
	end


IndigoPlateau_PokemonCenter_1F_Eventscript_OldMan::
	lock
	faceplayer
	msgbox IndigoPlateau_PokemonCenter_1F_Eventscript_OldMan_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq IndigoPlateau_PokemonCenter_1F_Eventscript_OldMan_2
	msgbox IndigoPlateau_PokemonCenter_1F_Eventscript_OldMan_Text_2, MSGBOX_DEFAULT
	delay 16
	warpteleport MAP_NEW_BARK_TOWN, 255, 16, 8
	waitstate
	release
	end

IndigoPlateau_PokemonCenter_1F_Eventscript_OldMan_2:
	msgbox IndigoPlateau_PokemonCenter_1F_Eventscript_OldMan_Text_1, MSGBOX_DEFAULT
	release
	end


IndigoPlateau_PokemonCenter_1F_Eventscript_Abra::
	lock
	faceplayer
	playmoncry SPECIES_ABRA, 0
	msgbox IndigoPlateau_PokemonCenter_1F_Eventscript_Abra_Text_0, MSGBOX_DEFAULT
	waitmoncry
	release
	end


IndigoPlateau_PokemonCenter_1F_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIHelpYou
	waitmessage
	pokemart IndigoPlateau_PokemonCenter_1F_Pokemart_Clerk
	msgbox gText_PleaseComeAgain
	release
	return


IndigoPlateau_PokemonCenter_1F_Pokemart_Clerk:
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_MAX_POTION
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_REVIVE
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_NONE

IndigoPlateau_PokemonCenter_1F_Eventscript_Guy_Text_0:
	.string "At the POKéMON LEAGUE, you'll get\ntested by the ELITE FOUR.\pYou have to beat them all. If you\nlose, you have to start all over!$"

IndigoPlateau_PokemonCenter_1F_Eventscript_OldMan_Text_0:
	.string "Ah! You're challenging the ELITE\nFOUR? Are you sure you're ready?\pIf you need to train some more, my\nABRA can help you.\pIt can TELEPORT you home.\nWould you like to go home now?$"

IndigoPlateau_PokemonCenter_1F_Eventscript_OldMan_Text_1:
	.string "Okay, okay. The best of luck to you!$"

IndigoPlateau_PokemonCenter_1F_Eventscript_OldMan_Text_2:
	.string "Okay, okay. Picture your house in\nyour mind…$"

IndigoPlateau_PokemonCenter_1F_Eventscript_Abra_Text_0:
	.string "ABRA: Aabra…$"
