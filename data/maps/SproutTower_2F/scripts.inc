SproutTower_2F_MapScripts:: @ 82379A4
	.byte 0

SproutTower_2F_EventScript_Youngster:: @ 82379A5
	msgbox SproutTower_2F_Text_IsntItFunHere, MSGBOX_NPC
	end

SproutTower_2F_EventScript_Charlie:: @ 82379AE
	trainerbattle_single TRAINER_CHARLIE, SproutTower_2F_Text_CharlieIntro, SproutTower_2F_Text_CharlieDefeat
	msgbox SproutTower_2F_Text_CharliePostBattle, MSGBOX_AUTOCLOSE
	end

SproutTower_2F_Text_CharlieIntro: @ 82379C5
	.string "What's so funny about having my inner\n"
	.string "tube aboard the ship?$"

SproutTower_2F_Text_CharlieDefeat: @ 8237A01
	.string "Whoa, you overwhelmed me!$"

SproutTower_2F_Text_CharliePostBattle: @ 8237A1B
	.string "It's not easy throwing POKé BALLS\n"
	.string "while hanging on to an inner tube!$"

SproutTower_2F_Text_IsntItFunHere: @ 8237A60
	.string "Isn't it fun here?\n"
	.string "I get excited just being here!$"
