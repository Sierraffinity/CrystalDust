Route32_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route32_PokemonCenter_1F_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

Route32_PokemonCenter_1F_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	setflag FLAG_LANDMARK_ROUTE_32_POKEMON_CENTER
	setrespawn HEAL_LOCATION_ROUTE32
	return


Route32_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, 1
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	return


Route32_PokemonCenter_1F_EventScript_FishingGuru::
	lock
	faceplayer
	goto_if_unset FLAG_RECEIVED_OLD_ROD, Route32_PokemonCenter_1F_EventScript_FishingGuru_2
	msgbox Route32_PokemonCenter_1F_EventScript_FishingGuru_Text_4
Route32_PokemonCenter_1F_EventScript_FishingGuru_1:
	release
	return

Route32_PokemonCenter_1F_EventScript_FishingGuru_2:
	msgbox Route32_PokemonCenter_1F_EventScript_FishingGuru_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_ne Route32_PokemonCenter_1F_EventScript_FishingGuru_5
	msgbox Route32_PokemonCenter_1F_EventScript_FishingGuru_Text_3
	goto Route32_PokemonCenter_1F_EventScript_FishingGuru_1

Route32_PokemonCenter_1F_EventScript_FishingGuru_5:
	msgbox Route32_PokemonCenter_1F_EventScript_FishingGuru_Text_1
	giveitem ITEM_OLD_ROD
	msgbox Route32_PokemonCenter_1F_EventScript_FishingGuru_Text_2
	setflag FLAG_RECEIVED_OLD_ROD
	goto Route32_PokemonCenter_1F_EventScript_FishingGuru_1


Route32_PokemonCenter_1F_EventScript_HoldItemGirl::
	msgbox Route32_PokemonCenter_1F_EventScript_HoldItemGirl_Text_0, MSGBOX_NPC
	return


Route32_PokemonCenter_1F_EventScript_FishingGuru_Text_0:
	.string "This is a great fishing spot.\n"
	.string "Oh, you saw people fishing?\p"
	.string "How about you?\n"
	.string "Would you like one of my RODS?$"

Route32_PokemonCenter_1F_EventScript_FishingGuru_Text_1:
	.string "Heh, that's good to hear.\n"
	.string "Now you're an angler too!$"

Route32_PokemonCenter_1F_EventScript_FishingGuru_Text_2:
	.string "Fishing is great!\n"
	.string "If there's water, be it the sea or\l"
	.string "a stream, try out your ROD.$"

Route32_PokemonCenter_1F_EventScript_FishingGuru_Text_3:
	.string "Oh.\n"
	.string "That's rather disappointing…$"

Route32_PokemonCenter_1F_EventScript_FishingGuru_Text_4:
	.string "Yo, kid.\n"
	.string "How are they biting?$"

Route32_PokemonCenter_1F_EventScript_HoldItemGirl_Text_0:
	.string "What item should I make my\n"
	.string "POKéMON hold?\p"
	.string "Maybe something that increases the\n"
	.string "power of its attacks…$"
