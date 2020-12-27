GoldenrodCity_BikeShop_MapScripts::
	.byte 0


GoldenrodCity_BikeShop_EventScript_Owner::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_BIKE, GoldenrodCity_BikeShop_EventScript_Owner_2
	msgbox GoldenrodCity_BikeShop_EventScript_Owner_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq GoldenrodCity_BikeShop_EventScript_Owner_5
	msgbox GoldenrodCity_BikeShop_EventScript_Owner_Text_2
	giveitem_msg GoldenrodCity_BikeShop_EventScript_Owner_Text_3, ITEM_BICYCLE
	setflag FLAG_RECEIVED_BIKE
	setflag FLAG_BIKE_SHOP_LOAN_ACTIVE
	msgbox GoldenrodCity_BikeShop_Text_OwnerPostGiveBike
GoldenrodCity_BikeShop_EventScript_Owner_1:
	release
	return

GoldenrodCity_BikeShop_EventScript_Owner_2:
	msgbox GoldenrodCity_BikeShop_Text_OwnerPostGiveBike
	goto GoldenrodCity_BikeShop_EventScript_Owner_1

GoldenrodCity_BikeShop_EventScript_Owner_5:
	msgbox GoldenrodCity_BikeShop_EventScript_Owner_Text_1
	goto GoldenrodCity_BikeShop_EventScript_Owner_1


GoldenrodCity_BikeShop_EventScript_Bicycles::
	msgbox GoldenrodCity_BikeShop_EventScript_Bicycles_Text_0, MSGBOX_SIGN
	return


GoldenrodCity_BikeShop_EventScript_Owner_Text_0:
	.string "…sigh… I moved here, but I can't\n"
	.string "sell my BICYCLES. Why is that?\p"
	.string "Could you ride a BICYCLE and\n"
	.string "advertise for me?$"

GoldenrodCity_BikeShop_EventScript_Owner_Text_1:
	.string "…sigh…\n"
	.string "Oh, for the kindness of people…$"

GoldenrodCity_BikeShop_EventScript_Owner_Text_2:
	.string "Really? Great!\p"
	.string "Give me your name and phone number,\n"
	.string "and I'll loan you a BICYCLE.$"

GoldenrodCity_BikeShop_EventScript_Owner_Text_3:
	.string "{PLAYER} borrowed a BICYCLE\n"
	.string "from the owner.$"

GoldenrodCity_BikeShop_EventScript_Bicycles_Text_0:
	.string "It's a shiny new BICYCLE!$"

GoldenrodCity_BikeShop_Text_OwnerPostGiveBike::
	.string "My BICYCLES are first-rate!\n"
	.string "You can ride them anywhere.$"
