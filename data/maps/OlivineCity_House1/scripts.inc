OlivineCity_House1_MapScripts::
	.byte 0


OlivineCity_House1_Eventscript_Fisherman::
	checkitem ITEM_GOOD_ROD, 1
	copyvar VAR_0x8008, VAR_RESULT
	checkpcitem ITEM_GOOD_ROD, 1
	compare VAR_0x8008, TRUE
	goto_if_eq OlivineCity_House1_Eventscript_Fisherman_2
	compare VAR_RESULT, TRUE
	goto_if_eq OlivineCity_House1_Eventscript_Fisherman_2
	lock
	faceplayer
	msgbox OlivineCity_House1_Eventscript_Fisherman_Text_1, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq OlivineCity_House1_Eventscript_Fisherman_7
	msgbox OlivineCity_House1_Eventscript_Fisherman_Text_4, MSGBOX_AUTOCLOSE
	release
	end

OlivineCity_House1_Eventscript_Fisherman_2:
	msgbox OlivineCity_House1_Eventscript_Fisherman_Text_0, MSGBOX_NPC
	end

OlivineCity_House1_Eventscript_Fisherman_7:
	msgbox OlivineCity_House1_Eventscript_Fisherman_Text_2, MSGBOX_DEFAULT
	giveitem ITEM_GOOD_ROD
	msgbox OlivineCity_House1_Eventscript_Fisherman_Text_3, MSGBOX_AUTOCLOSE
	release
	end


OlivineCity_House1_Eventscript_Fisherman_Text_0:
	.string "How are things?\nLand the big one?$"

OlivineCity_House1_Eventscript_Fisherman_Text_1:
	.string "OLIVINE is on the sea!\pAnd if it's on the sea, there are\nbound to be fish!\pI've fished here for 30 years.\pWould you like to face the sea and\nfish?$"

OlivineCity_House1_Eventscript_Fisherman_Text_2:
	.string "Ah, hahah!\nWe have ourselves a new angler!$"

OlivineCity_House1_Eventscript_Fisherman_Text_3:
	.string "Fish aren't found in the sea alone.\nThey go wherever there is water.$"

OlivineCity_House1_Eventscript_Fisherman_Text_4:
	.string "Whaaat? You don't like to fish!?\nIncomprehensible!$"
