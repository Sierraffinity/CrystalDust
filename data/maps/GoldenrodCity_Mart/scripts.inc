GoldenrodCity_MagnetTrainStation_MapScripts:: @ 8214F05
	.byte 0

GoldenrodCity_MagnetTrainStation_EventScript_Clerk:: @ 8214F06
	lock
	faceplayer
	message gText_HowMayIHelpYou
	waitmessage
	goto_if_unset FLAG_MET_DEVON_EMPLOYEE, GoldenrodCity_MagnetTrainStation_EventScript_PokemartBasic
	goto_if_set FLAG_MET_DEVON_EMPLOYEE, GoldenrodCity_MagnetTrainStation_EventScript_PokemartExpanded
	end

GoldenrodCity_MagnetTrainStation_EventScript_PokemartBasic:: @ 8214F21
	pokemart GoldenrodCity_MagnetTrainStation_Pokemart_Basic
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_MagnetTrainStation_Pokemart_Basic: @ 8214F30
	.2byte ITEM_POKE_BALL
	.2byte ITEM_POTION
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_REPEL
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFEND
	.2byte ITEM_NONE
	release
	end

GoldenrodCity_MagnetTrainStation_EventScript_PokemartExpanded:: @ 8214F48
	pokemart GoldenrodCity_MagnetTrainStation_Pokemart_Expanded
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
GoldenrodCity_MagnetTrainStation_Pokemart_Expanded: @ 8214F58
	.2byte ITEM_POKE_BALL
	.2byte ITEM_TIMER_BALL
	.2byte ITEM_REPEAT_BALL
	.2byte ITEM_POTION
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_REPEL
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFEND
	.2byte ITEM_NONE
	release
	end

GoldenrodCity_MagnetTrainStation_EventScript_PokefanF:: @ 8214F74
	msgbox GoldenrodCity_MagnetTrainStation_Text_BuyingHealsInCaseOfShroomish, MSGBOX_NPC
	end

GoldenrodCity_MagnetTrainStation_EventScript_Boy:: @ 8214F7D
	msgbox GoldenrodCity_MagnetTrainStation_Text_ShouldBuySuperPotionsInstead, MSGBOX_NPC
	end

GoldenrodCity_MagnetTrainStation_EventScript_BugCatcher:: @ 8214F86
	msgbox GoldenrodCity_MagnetTrainStation_Text_GettingEscapeRopeJustInCase, MSGBOX_NPC
	end

GoldenrodCity_MagnetTrainStation_Text_BuyingHealsInCaseOfShroomish: @ 8214F8F
	.string "I'm buying some PARLYZ HEALS and\n"
	.string "ANTIDOTES.\p"
	.string "Just in case I run into SHROOMISH\n"
	.string "in PETALBURG WOODS.$"

GoldenrodCity_MagnetTrainStation_Text_ShouldBuySuperPotionsInstead: @ 8214FF1
	.string "My POKéMON evolved.\n"
	.string "It has a lot of HP now.\p"
	.string "I should buy SUPER POTIONS for it\n"
	.string "instead of ordinary POTIONS.$"

GoldenrodCity_MagnetTrainStation_Text_GettingEscapeRopeJustInCase: @ 821505C
	.string "I'm getting an ESCAPE ROPE just in\n"
	.string "case I get lost in a cave.\p"
	.string "I just need to use it to get back to\n"
	.string "the entrance.$"

