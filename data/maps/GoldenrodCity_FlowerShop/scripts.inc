GoldenrodCity_FlowerShop_MapScripts::
	.byte 0


GoldenrodCity_FlowerShop_EventScript_OlderSister::
	lock
	goto_if_set FLAG_DEFEATED_SUDOWOODO, GoldenrodCity_FlowerShop_EventScript_OlderSister_2
	goto_if_set FLAG_GOT_SQUIRTBOTTLE, GoldenrodCity_FlowerShop_EventScript_OlderSister_3
	goto_if_unset FLAG_MET_FLORIA_ROUTE_36, GoldenrodCity_FlowerShop_EventScript_OlderSister_4
	goto_if_unset FLAG_TALKED_TO_FLORIA_FLOWER_SHOP, GoldenrodCity_FlowerShop_EventScript_OlderSister_5
	goto_if_unset FLAG_BADGE03_GET, GoldenrodCity_FlowerShop_EventScript_OlderSister_6
	faceplayer
	msgbox GoldenrodCity_FlowerShop_EventScript_OlderSister_Text_3
	giveitem_msg GoldenrodCity_FlowerShop_EventScript_OlderSister_Text_4, ITEM_SQUIRTBOTTLE
	setflag FLAG_GOT_SQUIRTBOTTLE
	clearflag FLAG_FLORIA_WENT_TO_ROUTE_36
GoldenrodCity_FlowerShop_EventScript_OlderSister_1:
	release
	return

GoldenrodCity_FlowerShop_EventScript_OlderSister_2:
	call GoldenrodCity_FlowerShop_EventScript_OlderSister_Lalala
	goto GoldenrodCity_FlowerShop_EventScript_OlderSister_1

GoldenrodCity_FlowerShop_EventScript_OlderSister_3:
	faceplayer
	msgbox GoldenrodCity_FlowerShop_EventScript_OlderSister_Text_0
	goto GoldenrodCity_FlowerShop_EventScript_OlderSister_1

GoldenrodCity_FlowerShop_EventScript_OlderSister_4:
	faceplayer
	msgbox GoldenrodCity_FlowerShop_EventScript_OlderSister_Text_1
	goto GoldenrodCity_FlowerShop_EventScript_OlderSister_1

GoldenrodCity_FlowerShop_EventScript_OlderSister_5:
	call GoldenrodCity_FlowerShop_EventScript_OlderSister_Lalala
	goto GoldenrodCity_FlowerShop_EventScript_OlderSister_1

GoldenrodCity_FlowerShop_EventScript_OlderSister_6:
	faceplayer
	msgbox GoldenrodCity_FlowerShop_EventScript_OlderSister_Text_2
	goto GoldenrodCity_FlowerShop_EventScript_OlderSister_1


GoldenrodCity_FlowerShop_EventScript_OlderSister_Lalala::
	turnobject 1, DIR_WEST
	msgbox GoldenrodCity_FlowerShop_EventScript_OlderSister_Lalala_Text_0
	return


GoldenrodCity_FlowerShop_EventScript_Floria::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_SUDOWOODO, GoldenrodCity_FlowerShop_EventScript_Floria_2
	goto_if_set FLAG_GOT_SQUIRTBOTTLE, GoldenrodCity_FlowerShop_EventScript_Floria_3
	msgbox GoldenrodCity_FlowerShop_EventScript_Floria_Text_2
	setflag FLAG_TALKED_TO_FLORIA_FLOWER_SHOP
	setflag FLAG_FLORIA_WENT_TO_ROUTE_36
GoldenrodCity_FlowerShop_EventScript_Floria_1:
	release
	return

GoldenrodCity_FlowerShop_EventScript_Floria_2:
	msgbox GoldenrodCity_FlowerShop_EventScript_Floria_Text_0
	goto GoldenrodCity_FlowerShop_EventScript_Floria_1

GoldenrodCity_FlowerShop_EventScript_Floria_3:
	msgbox GoldenrodCity_FlowerShop_EventScript_Floria_Text_1
	goto GoldenrodCity_FlowerShop_EventScript_Floria_1


GoldenrodCity_FlowerShop_EventScript_OlderSister_Text_0:
	.string "Don't do anything too dangerous!$"

GoldenrodCity_FlowerShop_EventScript_OlderSister_Text_1:
	.string "Have you seen that wiggly tree\n"
	.string "that's growing on ROUTE 36?\p"
	.string "My little sister got all excited\n"
	.string "and went to see it…\p"
	.string "I'm worried…\n"
	.string "Isn't it dangerous?$"

GoldenrodCity_FlowerShop_EventScript_OlderSister_Text_2:
	.string "Do you want to borrow the water\n"
	.string "bottle too?\p"
	.string "I don't want you doing anything\n"
	.string "dangerous with it.$"

GoldenrodCity_FlowerShop_EventScript_OlderSister_Text_3:
	.string "Oh, you're better than WHITNEY…\p"
	.string "You'll be okay, then.\n"
	.string "Here's the SQUIRTBOTTLE.$"

GoldenrodCity_FlowerShop_EventScript_OlderSister_Text_4:
	.string "{PLAYER} received the SQUIRTBOTTLE\n"
	.string "from the lady.$"

GoldenrodCity_FlowerShop_EventScript_OlderSister_Lalala_Text_0:
	.string "Lalala lalalala.\n"
	.string "Have plenty of water, my lovely!$"

GoldenrodCity_FlowerShop_EventScript_Floria_Text_0:
	.string "So it really was a POKéMON!$"

GoldenrodCity_FlowerShop_EventScript_Floria_Text_1:
	.string "Wow, you beat WHITNEY?\n"
	.string "Cool!$"

GoldenrodCity_FlowerShop_EventScript_Floria_Text_2:
	.string "When I told my sis about the jiggly\n"
	.string "tree, she told me it's dangerous.\p"
	.string "If I beat WHITNEY, I wonder if\n"
	.string "she'll lend me her water bottle…$"
