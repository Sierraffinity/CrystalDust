GoldenrodCity_DeptStore_Rooftop_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, GoldenrodCity_DeptStore_Rooftop_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

GoldenrodCity_DeptStore_Rooftop_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	goto_if_set FLAG_GOLDENROD_DEPT_STORE_SALE_HAPPENING, GoldenrodCity_DeptStore_Rooftop_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	setflag FLAG_HIDE_GOLDENROD_DEPT_STORE_ROOFTOP_SALE_OFF
	clearflag FLAG_HIDE_GOLDENROD_DEPT_STORE_ROOFTOP_SALE_ON
	return

GoldenrodCity_DeptStore_Rooftop_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
	setflag FLAG_HIDE_GOLDENROD_DEPT_STORE_ROOFTOP_SALE_ON
	clearflag FLAG_HIDE_GOLDENROD_DEPT_STORE_ROOFTOP_SALE_OFF
	return


GoldenrodCity_DeptStore_Rooftop_EventScript_Clerk::
	return


GoldenrodCity_DeptStore_Rooftop_EventScript_TiredWoman::
	msgbox GoldenrodCity_DeptStore_Rooftop_EventScript_TiredWoman_Text_0, MSGBOX_NPC
	return


GoldenrodCity_DeptStore_Rooftop_EventScript_GatchaGuy::
	lock
	faceplayer
	msgbox GoldenrodCity_DeptStore_Rooftop_EventScript_GatchaGuy_Text_0
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	release
	return


GoldenrodCity_DeptStore_Rooftop_EventScript_LittleGirl::
	msgbox GoldenrodCity_DeptStore_Rooftop_EventScript_LittleGirl_Text_0, MSGBOX_NPC
	return


GoldenrodCity_DeptStore_Rooftop_EventScript_BinocularJerk::
	lock
	msgbox GoldenrodCity_DeptStore_Rooftop_EventScript_BinocularJerk_Text_0
	faceplayer
	msgbox GoldenrodCity_DeptStore_Rooftop_EventScript_BinocularJerk_Text_1
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	release
	return


GoldenrodCity_DeptStore_Rooftop_EventScript_BerryCollector::
	msgbox GoldenrodCity_DeptStore_Rooftop_EventScript_BerryCollector_Text_0, MSGBOX_NPC
	return


GoldenrodCity_DeptStore_Rooftop_EventScript_CheapTeacher::
	msgbox GoldenrodCity_DeptStore_Rooftop_EventScript_CheapTeacher_Text_0, MSGBOX_NPC
	return


GoldenrodCity_DeptStore_Rooftop_EventScript_ParalyzedBugCatcher::
	msgbox GoldenrodCity_DeptStore_Rooftop_EventScript_ParalyzedBugCatcher_Text_0, MSGBOX_NPC
	return


GoldenrodCity_DeptStore_Rooftop_EventScript_Binoculars1::
	msgbox GoldenrodCity_DeptStore_Rooftop_EventScript_Binoculars1_Text_0, MSGBOX_SIGN
	return


GoldenrodCity_DeptStore_Rooftop_EventScript_Binoculars2::
	msgbox GoldenrodCity_DeptStore_Rooftop_EventScript_Binoculars2_Text_0, MSGBOX_SIGN
	return


GoldenrodCity_DeptStore_Rooftop_EventScript_Binoculars3::
	msgbox GoldenrodCity_DeptStore_Rooftop_EventScript_Binoculars3_Text_0, MSGBOX_SIGN
	return


GoldenrodCity_DeptStore_Rooftop_EventScript_PokeDollGachaMachine::
	msgbox GoldenrodCity_DeptStore_Rooftop_EventScript_PokeDollGachaMachine_Text_0, MSGBOX_SIGN
	return


GoldenrodCity_DeptStore_Rooftop_EventScript_TiredWoman_Text_0:
	.string "Whew, I'm tired.\p"
	.string "I sometimes come up to the rooftop\n"
	.string "to take a break from shopping.$"

GoldenrodCity_DeptStore_Rooftop_EventScript_GatchaGuy_Text_0:
	.string "Pardon? Who says an adult can't get\n"
	.string "into this?\p"
	.string "I'm going to be back every day to\n"
	.string "collect all the dolls!$"

GoldenrodCity_DeptStore_Rooftop_EventScript_LittleGirl_Text_0:
	.string "They have bargain sales here every\n"
	.string "so often.$"

GoldenrodCity_DeptStore_Rooftop_EventScript_BinocularJerk_Text_0:
	.string "Oh, wow!$"

GoldenrodCity_DeptStore_Rooftop_EventScript_BinocularJerk_Text_1:
	.string "Will you quit bothering me?$"

GoldenrodCity_DeptStore_Rooftop_EventScript_BerryCollector_Text_0:
	.string "There's something I really want, but\n"
	.string "I don't have the necessary cash…\p"
	.string "Maybe I'll sell off the BERRIES\n"
	.string "I've collected…$"

GoldenrodCity_DeptStore_Rooftop_EventScript_CheapTeacher_Text_0:
	.string "Oh, everything is so cheap!\n"
	.string "I bought so much, my BAG's crammed!$"

GoldenrodCity_DeptStore_Rooftop_EventScript_ParalyzedBugCatcher_Text_0:
	.string "My POKéMON always get paralyzed or\n"
	.string "poisoned when the chips are down…\l"
	.string "So I came to buy some FULL HEAL.\p"
	.string "I wonder if there's any left?$"

GoldenrodCity_DeptStore_Rooftop_EventScript_Binoculars1_Text_0:
	.string "These binoculars let me see far away.\n"
	.string "Maybe I can see my own house.\p"
	.string "Is it the one with the green roof?$"

GoldenrodCity_DeptStore_Rooftop_EventScript_Binoculars2_Text_0:
	.string "Hey! Some TRAINERS are battling on\n"
	.string "the road!\p"
	.string "A POKéMON fired a flurry of\n"
	.string "leaves!\p"
	.string "That makes me feel like battling\n"
	.string "right now!$"

GoldenrodCity_DeptStore_Rooftop_EventScript_Binoculars3_Text_0:
	.string "A FISHERMAN caught many MAGIKARP…\n"
	.string "They're SPLASHing at the same time!\p"
	.string "Look at the water going everywhere!$"

GoldenrodCity_DeptStore_Rooftop_EventScript_PokeDollGachaMachine_Text_0:
	.string "A vending machine for POKéMON dolls?\n"
	.string "Insert money, then turn the crank…\p"
	.string "But it's almost empty…$"
