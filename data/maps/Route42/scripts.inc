Route42_MapScripts::
	.byte 0


Route42_Eventscript_RouteSign::
	msgbox Route42_Eventscript_RouteSign_Text_0, MSGBOX_SIGN
	end


Route42_Eventscript_MtMortarSign::
	msgbox Route42_Eventscript_MtMortarSign_Text_0, MSGBOX_SIGN
	end


Route42_Eventscript_FishermanTully::
	trainerbattle_single TRAINER_TULLY_1, Route42_Eventscript_FishermanTully_Text_0, Route42_Eventscript_FishermanTully_Text_1
	msgbox Route42_Eventscript_FishermanTully_Text_2, MSGBOX_AUTOCLOSE
	end


Route42_Eventscript_PokemaniacShane::
	trainerbattle_single TRAINER_SHANE, Route42_Eventscript_PokemaniacShane_Text_0, Route42_Eventscript_PokemaniacShane_Text_1
	msgbox Route42_Eventscript_PokemaniacShane_Text_2, MSGBOX_AUTOCLOSE
	end


Route42_Eventscript_HikerBenjamin::
	trainerbattle_single TRAINER_BENJAMIN, Route42_Eventscript_HikerBenjamin_Text_0, Route42_Eventscript_HikerBenjamin_Text_1
	msgbox Route42_Eventscript_HikerBenjamin_Text_2, MSGBOX_AUTOCLOSE
	end


Route42_Eventscript_RouteSign_Text_0:
	.string "ROUTE 42\nECRUTEAK CITY - MAHOGANY TOWN$"

Route42_Eventscript_MtMortarSign_Text_0:
	.string "MT. MORTAR\nWATERFALL CAVE INSIDE$"

Route42_Eventscript_FishermanTully_Text_0:
	.string "Let me demonstrate the power of the\nPOKéMON I caught!$"

Route42_Eventscript_FishermanTully_Text_1:
	.string "What? That's not right.$"

Route42_Eventscript_FishermanTully_Text_2:
	.string "I want to become the TRAINER CHAMP\nusing the POKéMON I caught.\pThat's the best part of fishing!$"

Route42_Eventscript_PokemaniacShane_Text_0:
	.string "HEY! This is my secret place!\nGet lost, you outsider!$"

Route42_Eventscript_PokemaniacShane_Text_1:
	.string "I should have used my MOON STONE…$"

Route42_Eventscript_PokemaniacShane_Text_2:
	.string "You're working on a POKéDEX?\pWow, you must know some pretty rare\nPOKéMON!\pMay I please see it?\nPlease?$"

Route42_Eventscript_HikerBenjamin_Text_0:
	.string "Ah, it's good to be outside!\nI feel so free!$"

Route42_Eventscript_HikerBenjamin_Text_1:
	.string "Gahahah!$"

Route42_Eventscript_HikerBenjamin_Text_2:
	.string "Losing feels insignificant if you\nlook up at the big sky!$"
