Route43_MapScripts::
	.byte 0


Route43_Eventscript_RouteSign::
	msgbox Route43_Eventscript_RouteSign_Text_0, MSGBOX_SIGN
	end


Route43_Eventscript_TrainerTipsSign::
	msgbox Route43_Eventscript_TrainerTipsSign_Text_0, MSGBOX_SIGN
	end


Route43_Eventscript_CamperSpencer::
	trainerbattle_single TRAINER_SPENCER, Route43_Eventscript_CamperSpencer_Text_0, Route43_Eventscript_CamperSpencer_Text_1
	msgbox Route43_Eventscript_CamperSpencer_Text_2, MSGBOX_AUTOCLOSE
	end


Route43_Eventscript_PicnickerTiffany::
	trainerbattle_single TRAINER_TIFFANY_1, Route43_Eventscript_PicnickerTiffany_Text_0, Route43_Eventscript_PicnickerTiffany_Text_1
	msgbox Route43_Eventscript_PicnickerTiffany_Text_2, MSGBOX_AUTOCLOSE
	end


Route43_Eventscript_PokemaniacBrent::
	trainerbattle_single TRAINER_BRENT_1, Route43_Eventscript_PokemaniacBrent_Text_0, Route43_Eventscript_PokemaniacBrent_Text_1
	msgbox Route43_Eventscript_PokemaniacBrent_Text_2, MSGBOX_AUTOCLOSE
	end


Route43_Eventscript_FishermanMarvin::
	trainerbattle_single TRAINER_MARVIN, Route43_Eventscript_FishermanMarvin_Text_0, Route43_Eventscript_FishermanMarvin_Text_1
	msgbox Route43_Eventscript_FishermanMarvin_Text_2, MSGBOX_AUTOCLOSE
	end


Route43_Eventscript_PokemaniacRon::
	trainerbattle_single TRAINER_RON, Route43_Eventscript_PokemaniacRon_Text_0, Route43_Eventscript_PokemaniacRon_Text_1
	msgbox Route43_Eventscript_PokemaniacRon_Text_2, MSGBOX_AUTOCLOSE
	end


Route43_Eventscript_PokemaniacBen::
	trainerbattle_single TRAINER_BEN, Route43_Eventscript_PokemaniacBen_Text_0, Route43_Eventscript_PokemaniacBen_Text_1
	msgbox Route43_Eventscript_PokemaniacBen_Text_2, MSGBOX_AUTOCLOSE
	end


Route43_Eventscript_RouteSign_Text_0:
	.string "ROUTE 43\nLAKE OF RAGE - MAHOGANY TOWN$"

Route43_Eventscript_TrainerTipsSign_Text_0:
	.string "TRAINER TIPS\pAll POKéMON have pros and cons\ndepending on their types.\pIf their types differ, a higher-\nlevel POKéMON may lose in battle.\pLearn which types are strong and\nweak against your POKéMON's type.$"

Route43_Eventscript_CamperSpencer_Text_0:
	.string "I can do so much with my POKéMON--\nit's super-fun!$"

Route43_Eventscript_CamperSpencer_Text_1:
	.string "Losing isn't fun at all…$"

Route43_Eventscript_CamperSpencer_Text_2:
	.string "What is going on at the LAKE OF RAGE?\nWe were planning to camp there.$"

Route43_Eventscript_PicnickerTiffany_Text_0:
	.string "Are you going to the LAKE OF RAGE\ntoo? Let's play for a little while!$"

Route43_Eventscript_PicnickerTiffany_Text_1:
	.string "I played too much!$"

Route43_Eventscript_PicnickerTiffany_Text_2:
	.string "Isn't my CLEFAIRY just the most\nadorable thing?$"

Route43_Eventscript_PokemaniacBrent_Text_0:
	.string "Hey! Do you have any rare POKéMON?$"

Route43_Eventscript_PokemaniacBrent_Text_1:
	.string "Oh, my poor POKéMON!\nDarlings!$"

Route43_Eventscript_PokemaniacBrent_Text_2:
	.string "I'd be happy just to own a single\nrare POKéMON.$"

Route43_Eventscript_FishermanMarvin_Text_0:
	.string "I'm in a slump.\nMaybe it's the gear I'm using.\pLet's battle for a change of pace!$"

Route43_Eventscript_FishermanMarvin_Text_1:
	.string "I lost, but I feel better anyway.$"

Route43_Eventscript_FishermanMarvin_Text_2:
	.string "KURT's LURE BALL is the best for\ncatching hooked POKéMON.\pIt's much more effective than an\nULTRA BALL.$"

Route43_Eventscript_PokemaniacRon_Text_0:
	.string "Would you get this? Some {RIVAL} guy\nmade fun of my POKéMON!\pDarn it! My POKéMON's great!$"

Route43_Eventscript_PokemaniacRon_Text_1:
	.string "My NIDOKING did pretty right on!$"

Route43_Eventscript_PokemaniacRon_Text_2:
	.string "It's okay for people to like\ndifferent types of POKéMON.\pPOKéMON isn't just about having the\nmost powerful one.$"

Route43_Eventscript_PokemaniacBen_Text_0:
	.string "I love POKéMON!\pThat's why I started--and why I'll\nkeep on collecting POKéMON!$"

Route43_Eventscript_PokemaniacBen_Text_1:
	.string "How could you do this to me?$"

Route43_Eventscript_PokemaniacBen_Text_2:
	.string "What else do I like besides POKéMON?\nMARY on the radio. I bet she's cute!$"
