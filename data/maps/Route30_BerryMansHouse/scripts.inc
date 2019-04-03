Route30_BerryMansHouse_MapScripts::
	.byte 0

Route30_BerryMansHouse_EventScript_Man::
	lock
	faceplayer
	goto_if_set FLAG_ROUTE_30_RECEIVED_BERRY_MAN, Route30_BerryMansHouse_EventScript_Man_AlreadyGot
	msgbox Route30_BerryMansHouse_Text_PokemonEatBerries, MSGBOX_DEFAULT
	giveitem_std ITEM_ORAN_BERRY
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_ROUTE_30_RECEIVED_BERRY_MAN
Route30_BerryMansHouse_EventScript_Man_AlreadyGot::
	msgbox Route30_BerryMansHouse_Text_CheckTrees, MSGBOX_DEFAULT
	release
	end

Route30_BerryMansHouse_Text_PokemonEatBerries:
	.string "You know, POKéMON eat BERRIES.\n"
	.string "Well, my POKéMON got healthier by\l"
	.string "eating a BERRY.\p"
	.string "Here, I'll share one with you!$"

Route30_BerryMansHouse_Text_CheckTrees:
	.string "Check trees for BERRIES.\n"
	.string "They just drop right off.$"
