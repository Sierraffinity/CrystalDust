OlivineCity_Cafe_MapScripts::
	.byte 0


OlivineCity_Cafe_EventScript_Chef::
	msgbox OlivineCity_Cafe_EventScript_Chef_Text_0, MSGBOX_NPC
	end


OlivineCity_Cafe_EventScript_Sailor::
	msgbox OlivineCity_Cafe_EventScript_Sailor_Text_0, MSGBOX_NPC
	end


OlivineCity_Cafe_EventScript_StrengthSailor::
	checkitem ITEM_HM04, 1
	copyvar VAR_0x8008, VAR_RESULT
	checkpcitem ITEM_HM04, 1
	compare VAR_0x8008, TRUE
	goto_if_eq OlivineCity_Cafe_EventScript_StrengthSailor_2
	compare VAR_RESULT, TRUE
	goto_if_eq OlivineCity_Cafe_EventScript_StrengthSailor_2
	msgbox OlivineCity_Cafe_EventScript_StrengthSailor_Text_1, MSGBOX_DEFAULT
	giveitem ITEM_HM04
	release
	end

OlivineCity_Cafe_EventScript_StrengthSailor_2:
	msgbox OlivineCity_Cafe_EventScript_StrengthSailor_Text_0, MSGBOX_NPC
	end


OlivineCity_Cafe_EventScript_Chef_Text_0:
	.string "OLIVINE CAFE's menu is chock full of\nhearty fare for beefy SAILORS!$"

OlivineCity_Cafe_EventScript_Sailor_Text_0:
	.string "Whenever I roll into this town, I\nalways visit the OLIVINE CAFE.\pEverything on the menu makes me feel\nstronger. I can't stop eating!$"

OlivineCity_Cafe_EventScript_StrengthSailor_Text_0:
	.string "On the sea, the only thing you can\ncount on is your own good self!\pI'm so proud of my buff bod!$"

OlivineCity_Cafe_EventScript_StrengthSailor_Text_1:
	.string "Hah! Your POKéMON sure look like\nlightweights!\pThey don't have the power to move\nboulders aside.\pHere, use this and teach them\nSTRENGTH!$"
