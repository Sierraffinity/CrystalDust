Route30_MrPokemonsHouse_MapScripts::
	map_script 2, Route30_MrPokemonsHouse_MapScripts_Type2
	.byte 0

Route30_MrPokemonsHouse_MapScripts_Type2:
	map_script_2 VAR_MR_POKEMONS_HOUSE_STATE, 0, Route30_MrPokemonsHouse_MapScript_MrPokemonIntro
	.2byte 0

Route30_MrPokemonsHouse_MapScript_MrPokemonIntro:
	lockall
	textcolor MSG_COLOR_BLUE
	playse SE_PIN
	applymovement 1, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	applymovement 1, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	msgbox Route30_MrPokemonsHouse_Text_HelloHello
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Route30_MrPokemonsHouse_Movement_PlayerToMrPokemon
	waitmovement 0
	msgbox Route30_MrPokemonsHouse_Text_ThisIsWhatIWant
	giveitem ITEM_MYSTERY_EGG
	setflag FLAG_RECEIVED_MYSTERY_EGG
	msgbox Route30_MrPokemonsHouse_Text_IKnowACouple
	applymovement 1, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	msgbox Route30_MrPokemonsHouse_Text_EvenOakKnows
	applymovement 1, Common_Movement_WalkInPlaceFastestDown
	applymovement 2, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	msgbox Route30_MrPokemonsHouse_Text_IfMyAssumption
	closemessage
	playbgm MUS_OAKS_THEME, 0
	applymovement OBJ_EVENT_ID_PLAYER, Route30_MrPokemonsHouse_Movement_PauseThenTurnRight
	applymovement 2, Route30_MrPokemonsHouse_Movement_OakToPlayer
	waitmovement 0
	msgbox Route30_MrPokemonsHouse_Text_SoYourePlayer
	textcolor MSG_COLOR_SYS
	call_if_set FLAG_SYS_GBS_ENABLED, Route30_MrPokemonsHouse_EventScript_GetDexFanfareGBS
	call_if_unset FLAG_SYS_GBS_ENABLED, Route30_MrPokemonsHouse_EventScript_GetDexFanfareNoGBS
	message Route30_MrPokemonsHouse_Text_PlayerReceivedPokedex
	waitmessage
	waitfanfare
	textcolor MSG_COLOR_PREV
	setflag FLAG_SYS_POKEDEX_GET
	msgbox Route30_MrPokemonsHouse_Text_GoMeetManyPokemon
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Route30_MrPokemonsHouse_Movement_PauseThenTurnDown
	applymovement 2, Route30_MrPokemonsHouse_Movement_OakToDoor
	waitmovement 0
	delay 10
	playse SE_EXIT
	fadedefaultbgm
	removeobject 2
	waitse
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	msgbox Route30_MrPokemonsHouse_Text_ReturningToElm
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox Route30_MrPokemonsHouse_Text_DependingOnYou
	closemessage
	turnobject 1, 4
	setrespawn HEAL_LOCATION_CHERRYGROVE_CITY
	setflag FLAG_HIDE_NEW_BARK_TOWN_RIVAL
	setflag FLAG_HIDE_NEW_BARK_TOWN_PLAYERS_HOUSE_1F_NEIGHBOR
	clearflag FLAG_HIDE_NEW_BARK_TOWN_NEIGHBORS_HOUSE_NEIGHBOR
	clearflag FLAG_HIDE_NEW_BARK_TOWN_ELMS_LAB_OFFICER
	setvar VAR_CHERRYGROVE_CITY_STATE, 1
	setvar VAR_ELM_LAB_STATE, 4
	compare VAR_STARTER_MON, STARTER_CHIKORITA
	call_if_eq Route30_MrPokemonsHouse_EventScript_RivalGetsCyndaquil
	compare VAR_STARTER_MON, STARTER_TOTODILE
	call_if_eq Route30_MrPokemonsHouse_EventScript_RivalGetsChikorita
	compare VAR_STARTER_MON, STARTER_CYNDAQUIL
	call_if_eq Route30_MrPokemonsHouse_EventScript_RivalGetsTotodile
	setflag FLAG_FORCED_CALL_ELM_STOLEN_MON
	setvar VAR_MR_POKEMONS_HOUSE_STATE, 1
	releaseall
	end

Route30_MrPokemonsHouse_EventScript_GetDexFanfareGBS:
	playfanfare MUS_OBTAIN_ITEM
	return

Route30_MrPokemonsHouse_EventScript_GetDexFanfareNoGBS:
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	return

Route30_MrPokemonsHouse_EventScript_RivalGetsCyndaquil:
	setflag FLAG_HIDE_NEW_BARK_TOWN_ELMS_LAB_POKEBALL_CYNDAQUIL
	return

Route30_MrPokemonsHouse_EventScript_RivalGetsChikorita:
	setflag FLAG_HIDE_NEW_BARK_TOWN_ELMS_LAB_POKEBALL_CHIKORITA
	return

Route30_MrPokemonsHouse_EventScript_RivalGetsTotodile:
	setflag FLAG_HIDE_NEW_BARK_TOWN_ELMS_LAB_POKEBALL_TOTODILE
	return

Route30_MrPokemonsHouse_Movement_PlayerToMrPokemon:
	walk_right
	walk_up
	step_end

Route30_MrPokemonsHouse_Movement_OakToPlayer:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

Route30_MrPokemonsHouse_Movement_PauseThenTurnRight:
	delay_16
	walk_in_place_fastest_right
	step_end

Route30_MrPokemonsHouse_Movement_PauseThenTurnDown:
	delay_16
	walk_in_place_fastest_down
	step_end

Route30_MrPokemonsHouse_Movement_OakToDoor:
	walk_down
	walk_left
	walk_left
	face_down
	step_end

Route30_MrPokemonsHouse_EventScript_MrPokemon::
	lock
	faceplayer
	@checkitem ITEM_RED_SCALE, 1
	@goto_if_true Route30_MrPokemonsHouse_EventScript_MrPokemon_RedScale
	goto_if_set FLAG_ADVENTURE_STARTED, Route30_MrPokemonsHouse_EventScript_MrPokemon_AlwaysNewDiscoveries
	msgbox Route30_MrPokemonsHouse_Text_DependingOnYou
	release
	end

Route30_MrPokemonsHouse_EventScript_MrPokemon_AlwaysNewDiscoveries:
	msgbox Route30_MrPokemonsHouse_Text_AlwaysNewDiscoveries
	release
	end

Route30_MrPokemonsHouse_EventScript_ForeignMagazines::
	msgbox Route30_MrPokemonsHouse_Text_ForeignMagazines, MSGBOX_SIGN
	end

Route30_MrPokemonsHouse_EventScript_BrokenComputer::
	msgbox Route30_MrPokemonsHouse_Text_BrokenComputer, MSGBOX_SIGN
	end

Route30_MrPokemonsHouse_EventScript_StrangeCoins::
	msgbox Route30_MrPokemonsHouse_Text_StrangeCoins, MSGBOX_SIGN
	end

Route30_MrPokemonsHouse_Text_HelloHello:
	.string "Hello, hello!\n"
	.string "You must be {PLAYER}.\p"
	.string "PROF. ELM said that you would visit.$"

Route30_MrPokemonsHouse_Text_ThisIsWhatIWant:
	.string "This is what I want PROF. ELM to\n"
	.string "examine.$"

Route30_MrPokemonsHouse_Text_IKnowACouple:
	.string "I know a couple who run a DAY-CARE\n"
	.string "service. They gave me that EGG.\p"
	.string "I was intrigued, so I sent mail to\n"
	.string "PROF. ELM.\p"
	.string "For POKéMON evolution, PROF. ELM is\n"
	.string "the authority.$"

Route30_MrPokemonsHouse_Text_EvenOakKnows:
	.string "Even PROF. OAK here recognizes that.$"

Route30_MrPokemonsHouse_Text_IfMyAssumption:
	.string "If my assumption is correct, PROF.\n"
	.string "ELM will know what to do.$"

Route30_MrPokemonsHouse_Text_SoYourePlayer:
	.string "OAK: Aha!\n"
	.string "So you're {PLAYER}!\p"
	.string "I'm PROF. OAK, a POKéMON researcher\n"
	.string "from the KANTO region.\p"
	.string "I was just visiting my old friend,\n"
	.string "MR. POKéMON.\p"
	.string "I heard you were running an errand\n"
	.string "for PROF. ELM, so I waited here.\p"
	.string "…Oh! What's this?\n"
	.string "You have a rare POKéMON with you!\p"
	.string "Let's see…\p"
	.string "Hm, I see!\p"
	.string "I understand why PROF. ELM gave you\n"
	.string "a POKéMON for this errand.\p"
	.string "To researchers like PROF. ELM and I,\n"
	.string "POKéMON are our friends.\p"
	.string "He saw that you would treat your\n"
	.string "POKéMON with love and care.\p"
	.string "…Ah!\p"
	.string "You seem to be dependable.\n"
	.string "How would you like to help me out?\p"
	.string "See? This is the latest version of\n"
	.string "the POKéDEX.\p"
	.string "It automatically records data on\n"
	.string "POKéMON you've seen or caught.\p"
	.string "It's a high-tech encyclopedia!$"

Route30_MrPokemonsHouse_Text_PlayerReceivedPokedex:
	.string "{PLAYER} received the POKéDEX\n"
	.string "from PROF. OAK.$"

Route30_MrPokemonsHouse_Text_GoMeetManyPokemon:
	.string "OAK: Go meet many kinds of POKéMON\n"
	.string "and complete that POKéDEX!\p"
	.string "But, I've stayed too long.\n"
	.string "I have to get to GOLDENROD for my\l"
	.string "usual radio show.\p"
	.string "{PLAYER}, I'm counting on you!$"

Route30_MrPokemonsHouse_Text_ReturningToElm:
	.string "You are returning to PROF. ELM?\p"
	.string "Here.\n"
	.string "Your POKéMON should have some rest.$"

Route30_MrPokemonsHouse_Text_DependingOnYou:
	.string "I'm depending on you!$"

Route30_MrPokemonsHouse_Text_AlwaysNewDiscoveries:
	.string "Life is delightful!\n"
	.string "Always, new discoveries to be made!$"

Route30_MrPokemonsHouse_Text_ForeignMagazines:
	.string "It's a bookshelf packed with foreign\n"
	.string "magazines.\p"
	.string "Can't even read their titles…$"

Route30_MrPokemonsHouse_Text_BrokenComputer:
	.string "It's a big mainframe computer.\n"
	.string "Hm… It seems to be broken.$"

Route30_MrPokemonsHouse_Text_StrangeCoins:
	.string "It's a whole pile of strange coins.\n"
	.string "Maybe they're from another country…$"
