Route37_MapScripts::
	.byte 0


Route37_Eventscript_RouteSign::
	msgbox Route37_Eventscript_RouteSign_Text_0, MSGBOX_SIGN
	end


Route37_Eventscript_PsychicGreg::
	trainerbattle_single TRAINER_GREG, Route37_Eventscript_PsychicGreg_Text_0, Route37_Eventscript_PsychicGreg_Text_1
	msgbox Route37_Eventscript_PsychicGreg_Text_2, MSGBOX_AUTOCLOSE
	end


Route37_Eventscript_TwinAnn::
	trainerbattle_single TRAINER_ANN_AND_ANNE, Route37_Eventscript_TwinAnn_Text_0, Route37_Eventscript_TwinAnn_Text_1
	msgbox Route37_Eventscript_TwinAnn_Text_2, MSGBOX_AUTOCLOSE
	end


Route37_Eventscript_TwinAnne::
	trainerbattle_single TRAINER_ANN_AND_ANNE, Route37_Eventscript_TwinAnne_Text_0, Route37_Eventscript_TwinAnn_Text_1
	msgbox Route37_Eventscript_TwinAnne_Text_1, MSGBOX_AUTOCLOSE
	end


Route37_Eventscript_SunnyOfSunday::
	lock
	faceplayer
	goto_if_unset FLAG_RECEIVED_MAGNET_FROM_SUNNY, Route37_Eventscript_SunnyOfSunday_2
	msgbox Route37_Eventscript_SunnyOfSunday_Text_4
Route37_Eventscript_SunnyOfSunday_1:
	release
	return

Route37_Eventscript_SunnyOfSunday_2:
	gettime
	compare VAR_0x8003, DAY_SUNDAY
	goto_if_eq Route37_Eventscript_SunnyOfSunday_5
	msgbox Route37_Eventscript_SunnyOfSunday_Text_3
	goto Route37_Eventscript_SunnyOfSunday_1

Route37_Eventscript_SunnyOfSunday_5:
	goto_if_unset FLAG_MET_SUNNY_OF_SUNDAY, Route37_Eventscript_SunnyOfSunday_9
	msgbox Route37_Eventscript_SunnyOfSunday_Text_1
Route37_Eventscript_SunnyOfSunday_8:
	giveitem ITEM_MAGNET
	compare VAR_RESULT, 0
	goto_if_eq Route37_Eventscript_SunnyOfSunday_13
Route37_Eventscript_SunnyOfSunday_12:
	setflag FLAG_RECEIVED_MAGNET_FROM_SUNNY
	msgbox Route37_Eventscript_SunnyOfSunday_Text_2
	goto Route37_Eventscript_SunnyOfSunday_1

Route37_Eventscript_SunnyOfSunday_9:
	msgbox Route37_Eventscript_SunnyOfSunday_Text_0
	setflag FLAG_MET_SUNNY_OF_SUNDAY
	goto Route37_Eventscript_SunnyOfSunday_8

Route37_Eventscript_SunnyOfSunday_13:
	goto Common_EventScript_ShowBagIsFull
	goto Route37_Eventscript_SunnyOfSunday_12


Route37_Eventscript_RouteSign_Text_0:
	.string "ROUTE 37$"

Route37_Eventscript_PsychicGreg_Text_0:
	.string "POKéMON can't do a thing if they are\nasleep.\pI'll show you how scary that is!$"

Route37_Eventscript_PsychicGreg_Text_1:
	.string "I lost.\nThat's pretty sad…$"

Route37_Eventscript_PsychicGreg_Text_2:
	.string "Putting POKéMON to sleep or paralyzing\nthem are good battle techniques.$"

Route37_Eventscript_TwinAnn_Text_0:
	.string "ANN: ANNE and I are in this together!$"

Route37_Eventscript_TwinAnn_Text_1:
	.string "ANN & ANNE: Nnn…\nA little too strong.$"

Route37_Eventscript_TwinAnn_Text_2:
	.string "ANN: I can tell what my sister and my\nPOKéMON are thinking.$"

Route37_Eventscript_TwinAnne_Text_0:
	.string "ANNE: ANN and I are in this together!$"

Route37_Eventscript_TwinAnne_Text_1:
	.string "ANNE: We share the same feelings as\nour POKéMON.$"

Route37_Eventscript_SunnyOfSunday_Text_0:
	.string "SUNNY: Hi! I'm SUNNY of SUNDAY,\nmeaning it's SUNDAY today!\pI was told to give you this if I saw\nyou!$"

Route37_Eventscript_SunnyOfSunday_Text_1:
	.string "SUNNY: I was told to give you this if I saw\nyou!$"

Route37_Eventscript_SunnyOfSunday_Text_2:
	.string "SUNNY: That thing…\nUm…\p…What was it now…\p…\nOh! I remember now!\pA POKéMON that knows ELECTRIC-type\nmoves should hold it.\pMy sis MONICA said it powers up\nELECTRIC-type moves!$"

Route37_Eventscript_SunnyOfSunday_Text_3:
	.string "SUNNY: Isn't today SUNDAY?\nUm… I forgot!$"

Route37_Eventscript_SunnyOfSunday_Text_4:
	.string "SUNNY: My sisters and brothers are\nMONICA, TUSCANY, WESLEY, ARTHUR,\lFRIEDA, and SANTOS.\pThey're all older than me!$"
