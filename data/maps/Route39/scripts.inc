Route39_MapScripts::
	.byte 0


Route39_Eventscript_RouteSign::
	msgbox Route39_Eventscript_RouteSign_Text_0, MSGBOX_SIGN
	end


Route39_Eventscript_FarmSign::
	msgbox Route39_Eventscript_FarmSign_Text_0, MSGBOX_SIGN
	end


Route39_Eventscript_TrainerTipsSign::
	msgbox Route39_Eventscript_TrainerTipsSign_Text_0, MSGBOX_SIGN
	end


Route39_Eventscript_Miltank::
	lock
	faceplayer
	playmoncry SPECIES_MILTANK, 0
	msgbox Route39_Eventscript_Miltank_Text_0, MSGBOX_DEFAULT
	waitmoncry
	release
	end


Route39_Eventscript_PsychicNorman::
	trainerbattle_single TRAINER_NORMAN, Route39_Eventscript_PsychicNorman_Text_0, Route39_Eventscript_PsychicNorman_Text_1
	msgbox Route39_Eventscript_PsychicNorman_Text_2, MSGBOX_AUTOCLOSE
	end


Route39_Eventscript_PokefanDerek::
	trainerbattle_single TRAINER_DEREK, Route39_Eventscript_PokefanDerek_Text_0, Route39_Eventscript_PokefanDerek_Text_1
	msgbox Route39_Eventscript_PokefanDerek_Text_2, MSGBOX_AUTOCLOSE
	end


Route39_Eventscript_PokefanRuth::
	trainerbattle_single TRAINER_RUTH, Route39_Eventscript_PokefanRuth_Text_0, Route39_Eventscript_PokefanRuth_Text_1
	msgbox Route39_Eventscript_PokefanRuth_Text_2, MSGBOX_AUTOCLOSE
	end


Route39_Eventscript_SailorEugene::
	trainerbattle_single TRAINER_EUGENE, Route39_Eventscript_SailorEugene_Text_0, Route39_Eventscript_SailorEugene_Text_1
	msgbox Route39_Eventscript_SailorEugene_Text_2, MSGBOX_AUTOCLOSE
	end


Route39_Eventscript_PokefanJaime::
	gettime
	compare VAR_0x8002, TIME_NIGHT
	goto_if_eq Route39_Eventscript_PokefanJaime_2
	msgbox Route39_Eventscript_PokefanJaime_Text_1, MSGBOX_NPC
	end

Route39_Eventscript_PokefanJaime_2:
	trainerbattle_single TRAINER_JAIME, Route39_Eventscript_PokefanJaime_Text_0, Route39_Eventscript_SailorEugene_Text_1
	msgbox Route39_Eventscript_SailorEugene_Text_2, MSGBOX_AUTOCLOSE
	end


Route39_Eventscript_RouteSign_Text_0:
	.string "ROUTE 39\nOLIVINE CITY - ECRUTEAK CITY$"

Route39_Eventscript_FarmSign_Text_0:
	.string "MOOMOO FARM\nEnjoy Our Fresh and Tasty Milk$"

Route39_Eventscript_TrainerTipsSign_Text_0:
	.string "TRAINER TIPS\pUse HEADBUTT on trees to shake\nPOKéMON out.\pDifferent kinds of POKéMON drop out\nof trees.\pUse HEADBUTT on any tree you see!$"

Route39_Eventscript_Miltank_Text_0:
	.string "MILTANK: Mooo!$"

Route39_Eventscript_PsychicNorman_Text_0:
	.string "Let me see what your POKéMON are\ncapable of!$"

Route39_Eventscript_PsychicNorman_Text_1:
	.string "Ooh, your POKéMON have potential.$"

Route39_Eventscript_PsychicNorman_Text_2:
	.string "You know how POKéMON have different\nabilities?\pPeople are like that too.\nEveryone has different potential.$"

Route39_Eventscript_PokefanDerek_Text_0:
	.string "This is a good time to brag about my\nPIKACHU!$"

Route39_Eventscript_PokefanDerek_Text_1:
	.string "I had no time to show off PIKACHU…$"

Route39_Eventscript_PokefanDerek_Text_2:
	.string "PIKACHU is it!\nDon't you agree?$"

Route39_Eventscript_PokefanRuth_Text_0:
	.string "Such darling POKéMON… Let's show our\nPOKéMON together at the same time.$"

Route39_Eventscript_PokefanRuth_Text_1:
	.string "I don't mind losing.$"

Route39_Eventscript_PokefanRuth_Text_2:
	.string "Do you know about baby POKéMON?\nI bet they're just adorable!$"

Route39_Eventscript_SailorEugene_Text_0:
	.string "I just got back to OLIVINE.\nSo how about a POKéMON battle?$"

Route39_Eventscript_SailorEugene_Text_1:
	.string "Awaaargh!$"

Route39_Eventscript_SailorEugene_Text_2:
	.string "My POKéMON were caught and raised\noverseas.\pThey're my companions on those long\nvoyages.$"

Route39_Eventscript_PokefanJaime_Text_0:
	.string "You came at just the right time.\nLet's battle!$"

Route39_Eventscript_PokefanJaime_Text_1:
	.string "Ufufufu…\nI hope it gets dark soon.$"
