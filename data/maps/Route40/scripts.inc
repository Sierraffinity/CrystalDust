Route40_MapScripts::
	.byte 0


Route40_Eventscript_RouteSign::
	msgbox Route40_Eventscript_RouteSign_Text_0, MSGBOX_SIGN
	end


Route40_Eventscript_FenceGirl::
	msgbox Route40_Eventscript_FenceGirl_Text_0, MSGBOX_NPC
	end


Route40_Eventscript_GateMan::
	msgbox Route40_Eventscript_GateMan_Text_0, MSGBOX_NPC
	end


Route40_Eventscript_OceanBoy::
	msgbox Route40_Eventscript_OceanBoy_Text_0, MSGBOX_NPC
	end


Route40_Eventscript_BeachGirl::
	msgbox Route40_Eventscript_BeachGirl_Text_0, MSGBOX_NPC
	end


Route40_Eventscript_MonicaOfMonday::
	lock
	faceplayer
	goto_if_unset FLAG_RECEIVED_SHARP_BEAK_FROM_MONICA, Route40_Eventscript_MonicaOfMonday_2
	msgbox Route40_Eventscript_MonicaOfMonday_Text_4
Route40_Eventscript_MonicaOfMonday_1:
	release
	return

Route40_Eventscript_MonicaOfMonday_2:
	gettime
	compare VAR_0x8003, DAY_MONDAY
	goto_if_eq Route40_Eventscript_MonicaOfMonday_5
	msgbox Route40_Eventscript_MonicaOfMonday_Text_3
	goto Route40_Eventscript_MonicaOfMonday_1

Route40_Eventscript_MonicaOfMonday_5:
	goto_if_unset FLAG_MET_MONICA_OF_MONDAY, Route40_Eventscript_MonicaOfMonday_9
	msgbox Route40_Eventscript_MonicaOfMonday_Text_1
Route40_Eventscript_MonicaOfMonday_8:
	giveitem ITEM_SHARP_BEAK
	compare VAR_RESULT, 0
	goto_if_eq Route40_Eventscript_MonicaOfMonday_13
Route40_Eventscript_MonicaOfMonday_12:
	setflag FLAG_RECEIVED_SHARP_BEAK_FROM_MONICA
	msgbox Route40_Eventscript_MonicaOfMonday_Text_2
	goto Route40_Eventscript_MonicaOfMonday_1

Route40_Eventscript_MonicaOfMonday_9:
	msgbox Route40_Eventscript_MonicaOfMonday_Text_0
	setflag FLAG_MET_MONICA_OF_MONDAY
	goto Route40_Eventscript_MonicaOfMonday_8

Route40_Eventscript_MonicaOfMonday_13:
	goto Common_EventScript_ShowBagIsFull
	goto Route40_Eventscript_MonicaOfMonday_12


Route39_Eventscript_SwimmerSimon::
	trainerbattle_single TRAINER_SIMON, Route39_Eventscript_SwimmerSimon_Text_0, Route39_Eventscript_SwimmerSimon_Text_1
	msgbox Route39_Eventscript_SwimmerSimon_Text_2, MSGBOX_AUTOCLOSE
	end


Route39_Eventscript_SwimmerElaine::
	trainerbattle_single TRAINER_ELAINE, Route39_Eventscript_SwimmerElaine_Text_0, Route39_Eventscript_SwimmerElaine_Text_1
	msgbox Route39_Eventscript_SwimmerElaine_Text_2, MSGBOX_AUTOCLOSE
	end


Route39_Eventscript_SwimmerPaula::
	trainerbattle_single TRAINER_PAULA, Route39_Eventscript_SwimmerPaula_Text_0, Route39_Eventscript_SwimmerPaula_Text_1
	msgbox Route39_Eventscript_SwimmerPaula_Text_2, MSGBOX_AUTOCLOSE
	end


Route39_Eventscript_SwimmerRandall::
	trainerbattle_single TRAINER_RANDALL, Route39_Eventscript_SwimmerRandall_Text_0, Route39_Eventscript_SwimmerRandall_Text_1
	msgbox Route39_Eventscript_SwimmerRandall_Text_2, MSGBOX_AUTOCLOSE
	end


Route40_Eventscript_RouteSign_Text_0:
	.string "ROUTE 40\nCIANWOOD CITY - OLIVINE CITY$"

Route40_Eventscript_FenceGirl_Text_0:
	.string "I came to OLIVINE by ship to see the\nsights and soak up the atmosphere.\pBeing a port, it feels so different\nfrom a big city.$"

Route40_Eventscript_GateMan_Text_0:
	.string "Hm! There's a big building up ahead!\nWhat is it?$"

Route40_Eventscript_OceanBoy_Text_0:
	.string "Have you gone to the BATTLE TOWER?\pI think a lot of tough TRAINERS have\ngathered there already.\pBut since you have so many BADGES,\nyou shouldn't do badly at all.$"

Route40_Eventscript_BeachGirl_Text_0:
	.string "Although you can't see it from here,\nCIANWOOD is across the sea.$"

Route40_Eventscript_MonicaOfMonday_Text_0:
	.string "MONICA: Glad to meet you.\nI'm MONICA of MONDAY.\pAs a token of our frendship, I have\na gift for you.$"

Route40_Eventscript_MonicaOfMonday_Text_1:
	.string "MONICA: As a token of our frendship, I have\na gift for you.$"

Route40_Eventscript_MonicaOfMonday_Text_2:
	.string "MONICA: It's an item that raises the\npower of FLYING-type moves.\pYou should equip a bird POKéMON with\nthat item.$"

Route40_Eventscript_MonicaOfMonday_Text_3:
	.string "MONICA: I don't think today is\nMONDAY. How sad…$"

Route40_Eventscript_MonicaOfMonday_Text_4:
	.string "MONICA: My brothers and sisters are\nall over the place.\pSee if you can find them all!$"

Route39_Eventscript_SwimmerSimon_Text_0:
	.string "You have to warm up before going\ninto the water. That's basic.$"

Route39_Eventscript_SwimmerSimon_Text_1:
	.string "Okay! Uncle! I give!$"

Route39_Eventscript_SwimmerSimon_Text_2:
	.string "CIANWOOD CITY is a good distance\naway from here.$"

Route39_Eventscript_SwimmerElaine_Text_0:
	.string "Are you going to CIANWOOD?\nHow about a quick battle first?$"

Route39_Eventscript_SwimmerElaine_Text_1:
	.string "I lost that one!$"

Route39_Eventscript_SwimmerElaine_Text_2:
	.string "I'd say I'm a better swimmer than you.\nYeah!$"

Route39_Eventscript_SwimmerPaula_Text_0:
	.string "No inner tube for me.\nI'm hanging onto a sea POKéMON!$"

Route39_Eventscript_SwimmerPaula_Text_1:
	.string "Ooh, I'm feeling dizzy!$"

Route39_Eventscript_SwimmerPaula_Text_2:
	.string "While I float like this, the waves\ncarry me along.$"

Route39_Eventscript_SwimmerRandall_Text_0:
	.string "Hey, you're young and fit!\nDon't ride your POKéMON! Swim!$"

Route39_Eventscript_SwimmerRandall_Text_1:
	.string "Uh-oh. I lost…$"

Route39_Eventscript_SwimmerRandall_Text_2:
	.string "Swimming exercises your entire body.\nIt's healthy.$"
