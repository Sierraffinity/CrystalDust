GoldenrodCity_Underground_NorthEntrance_MapScripts:: @ 8211245
	map_script MAP_SCRIPT_ON_TRANSITION, GoldenrodCity_Underground_NorthEntrance_OnTransition
	.byte 0

GoldenrodCity_Underground_NorthEntrance_OnTransition: @ 821124B
	call_if_unset FLAG_CLEARED_RADIO_TOWER, GoldenrodCity_Underground_NorthEntrance_EventScript_BlockStairs
	end

GoldenrodCity_Underground_NorthEntrance_EventScript_BlockStairs:: @ 8211255
	setobjectxyperm 2, 14, 2
	setobjectmovementtype 2, MOVEMENT_TYPE_FACE_DOWN
	return

GoldenrodCity_Underground_NorthEntrance_EventScript_Employee:: @ 8211261
	lock
	faceplayer
	goto_if_set FLAG_CLEARED_RADIO_TOWER, GoldenrodCity_Underground_NorthEntrance_EventScript_GoodsRecovered
	goto_if_set FLAG_RECEIVED_EGG_TICKET, GoldenrodCity_Underground_NorthEntrance_EventScript_RobberWasntBright
	msgbox GoldenrodCity_Underground_NorthEntrance_Text_ThoseShoesAreOurProduct, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_Underground_NorthEntrance_EventScript_RobberWasntBright:: @ 821127F
	msgbox GoldenrodCity_Underground_NorthEntrance_Text_RobberWasntVeryBright, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_Underground_NorthEntrance_EventScript_GoodsRecovered:: @ 8211289
	msgbox GoldenrodCity_Underground_NorthEntrance_Text_SoundsLikeStolenGoodsRecovered, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_Underground_NorthEntrance_EventScript_StairGuard:: @ 8211293
	lock
	faceplayer
	goto_if_set FLAG_CLEARED_RADIO_TOWER, GoldenrodCity_Underground_NorthEntrance_EventScript_AlwaysWelcome
	goto_if_set FLAG_TALKED_TO_DAYCARE_LADY, GoldenrodCity_Underground_NorthEntrance_EventScript_GotRobbed
	goto_if_set FLAG_RECEIVED_EGG_TICKET, GoldenrodCity_Underground_NorthEntrance_EventScript_GotRobbed
	msgbox GoldenrodCity_Underground_NorthEntrance_Text_OnlyAuthorizedPeopleEnter, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_Underground_NorthEntrance_EventScript_AlwaysWelcome:: @ 82112BA
	msgbox GoldenrodCity_Underground_NorthEntrance_Text_YoureAlwaysWelcomeHere, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_Underground_NorthEntrance_EventScript_GotRobbed:: @ 82112C4
	msgbox GoldenrodCity_Underground_NorthEntrance_Text_HowCouldWeGetRobbed, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_Underground_NorthEntrance_EventScript_Greeter:: @ 82112CE
	lock
	faceplayer
	goto_if_set FLAG_CLEARED_RADIO_TOWER, GoldenrodCity_Underground_NorthEntrance_EventScript_WelcomeToDevonCorp
	goto_if_set FLAG_TALKED_TO_DAYCARE_LADY, GoldenrodCity_Underground_NorthEntrance_EventScript_StaffGotRobbed
	goto_if_set FLAG_RECEIVED_EGG_TICKET, GoldenrodCity_Underground_NorthEntrance_EventScript_StaffGotRobbed
	msgbox GoldenrodCity_Underground_NorthEntrance_Text_WelcomeToDevonCorp, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_Underground_NorthEntrance_EventScript_WelcomeToDevonCorp:: @ 82112F5
	msgbox GoldenrodCity_Underground_NorthEntrance_Text_WelcomeToDevonCorp, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_Underground_NorthEntrance_EventScript_StaffGotRobbed:: @ 82112FF
	msgbox GoldenrodCity_Underground_NorthEntrance_Text_StaffGotRobbed, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_Underground_NorthEntrance_EventScript_RocksMetalDisplay:: @ 8211309
	msgbox GoldenrodCity_Underground_NorthEntrance_Text_RocksMetalDisplay, MSGBOX_SIGN
	end

GoldenrodCity_Underground_NorthEntrance_EventScript_ProductsDisplay:: @ 8211312
	msgbox GoldenrodCity_Underground_NorthEntrance_Text_ProductDisplay, MSGBOX_SIGN
	end

GoldenrodCity_Underground_NorthEntrance_Text_WelcomeToDevonCorp: @ 821131B
	.string "Hello and welcome to the DEVON\n"
	.string "CORPORATION.\p"
	.string "We're proud producers of items and\n"
	.string "medicine that enhance your life.$"

GoldenrodCity_Underground_NorthEntrance_Text_StaffGotRobbed: @ 821138B
	.string "One of our research staff stupidly\n"
	.string "got robbed of an important parcel.$"

GoldenrodCity_Underground_NorthEntrance_Text_ThoseShoesAreOurProduct: @ 82113D1
	.string "Hey, those RUNNING SHOES!\n"
	.string "They're one of our products!\p"
	.string "It makes me happy when I see someone\n"
	.string "using something we made.$"

GoldenrodCity_Underground_NorthEntrance_Text_RobberWasntVeryBright: @ 8211446
	.string "That stolen parcel…\p"
	.string "Well, sure it's important, but it's not\n"
	.string "anything that anyone can use.\p"
	.string "In my estimation, that robber must not\n"
	.string "have been very bright.$"

GoldenrodCity_Underground_NorthEntrance_Text_SoundsLikeStolenGoodsRecovered: @ 82114DE
	.string "It sounds like they've recovered\n"
	.string "the ripped-off DEVON GOODS.$"

GoldenrodCity_Underground_NorthEntrance_Text_OnlyAuthorizedPeopleEnter: @ 821151B
	.string "I'm sorry, only authorized people\n"
	.string "are allowed to enter here.$"

GoldenrodCity_Underground_NorthEntrance_Text_HowCouldWeGetRobbed: @ 8211558
	.string "It's beyond stupid.\n"
	.string "How could we get robbed?$"

GoldenrodCity_Underground_NorthEntrance_Text_YoureAlwaysWelcomeHere: @ 8211585
	.string "Hi, there!\n"
	.string "You're always welcome here!$"

GoldenrodCity_Underground_NorthEntrance_Text_RocksMetalDisplay: @ 82115AC
	.string "Samples of rocks and metal are\n"
	.string "displayed in the glass case.\p"
	.string "There's a panel with some writing\n"
	.string "on it…\p"
	.string "“DEVON CORPORATION got its start as\n"
	.string "a producer of stones from quarries.\p"
	.string "“The company also produced iron from\n"
	.string "filings in the sand.\p"
	.string "“From that humble start as a producer\n"
	.string "of raw materials, DEVON developed.\p"
	.string "“DEVON is now a manufacturer of a wide\n"
	.string "range of industrial products.”$"

GoldenrodCity_Underground_NorthEntrance_Text_ProductDisplay: @ 8211722
	.string "Prototypes and test products fill\n"
	.string "the glass display case.\p"
	.string "There's a panel with a description…\p"
	.string "“In addition to industrial products,\n"
	.string "DEVON now markets sundries and\l"
	.string "pharmaceuticals for better lifestyles.\p"
	.string "“Recently, DEVON has begun marketing\n"
	.string "tools for POKéMON TRAINERS, including\l"
	.string "POKé BALLS and POKéNAV systems.”$"

