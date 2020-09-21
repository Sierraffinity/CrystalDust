GoldenrodCity_Flat2_3F_MapScripts:: @ 8216116
	.byte 0

GoldenrodCity_Flat2_3F_EventScript_DevonEmployee:: @ 8216117
	msgbox GoldenrodCity_Flat2_3F_Text_PresidentCollectsRareStones, MSGBOX_NPC
	end

GoldenrodCity_Flat2_3F_EventScript_Woman:: @ 8216120
	msgbox GoldenrodCity_Flat2_3F_Text_PresidentsSonAlsoCollectsRareStones, MSGBOX_NPC
	end

GoldenrodCity_Flat2_3F_Text_PresidentCollectsRareStones: @ 8216129
	.string "DEVON's PRESIDENT likes to collect\n"
	.string "rare stones.$"

GoldenrodCity_Flat2_3F_Text_PresidentsSonAlsoCollectsRareStones: @ 8216159
	.string "I think the PRESIDENT's son also\n"
	.string "collects rare stones.$"

