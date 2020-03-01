RuinsOfAlph_AerodactylItemRoom_MapScripts:: @ 82387E1
	.byte 0

RuinsOfAlph_AerodactylItemRoom_EventScript_CaptSternAide:: @ 82387E2
	lock
	faceplayer
	goto_if_set FLAG_EXCHANGED_SCANNER, RuinsOfAlph_AerodactylItemRoom_EventScript_ThisIsSSCactus
	checkitem ITEM_SCANNER, 1
	compare VAR_RESULT, 1
	goto_if_eq RuinsOfAlph_AerodactylItemRoom_EventScript_CanYouDeliverScanner
	goto_if_set FLAG_ITEM_ABANDONED_SHIP_HIDDEN_FLOOR_ROOM_4_SCANNER, RuinsOfAlph_AerodactylItemRoom_EventScript_ThisIsSSCactus
	msgbox RuinsOfAlph_AerodactylItemRoom_Text_NoSuccessFindingScanner, MSGBOX_DEFAULT
	release
	end

RuinsOfAlph_AerodactylItemRoom_EventScript_CanYouDeliverScanner:: @ 8238810
	msgbox RuinsOfAlph_AerodactylItemRoom_Text_OhCanYouDeliverScanner, MSGBOX_DEFAULT
	release
	end

RuinsOfAlph_AerodactylItemRoom_EventScript_ThisIsSSCactus:: @ 823881A
	msgbox RuinsOfAlph_AerodactylItemRoom_Text_ThisIsSSCactus, MSGBOX_DEFAULT
	release
	end

RuinsOfAlph_AerodactylItemRoom_Text_NoSuccessFindingScanner: @ 8238824
	.string "I'm investigating this ship on behalf\n"
	.string "of CAPT. STERN.\p"
	.string "He also asked me to find a SCANNER,\n"
	.string "but I haven't had any success…$"

RuinsOfAlph_AerodactylItemRoom_Text_OhCanYouDeliverScanner: @ 823889D
	.string "Oh! That's a SCANNER!\p"
	.string "Listen, can I get you to deliver that\n"
	.string "to CAPT. STERN?\p"
	.string "I want to investigate this ship a\n"
	.string "little more.$"

RuinsOfAlph_AerodactylItemRoom_Text_ThisIsSSCactus: @ 8238918
	.string "This ship is called S.S. CACTUS.\n"
	.string "It seems to be from an earlier era.$"

