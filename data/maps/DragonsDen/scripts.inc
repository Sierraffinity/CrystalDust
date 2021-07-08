DragonsDen_MapScripts::
	.byte 0


DragonsDen_Eventscript_Sign::
	msgbox DragonsDen_Eventscript_Sign_Text_0, MSGBOX_SIGN
	end


DragonsDen_Eventscript_CooltrainerDarin::
	trainerbattle_single TRAINER_DARIN, DragonsDen_Eventscript_CooltrainerDarin_Text_0, DragonsDen_Eventscript_CooltrainerDarin_Text_1
	msgbox DragonsDen_Eventscript_CooltrainerDarin_Text_2, MSGBOX_AUTOCLOSE
	end


DragonsDen_Eventscript_CooltrainerCara::
	trainerbattle_single TRAINER_CARA, DragonsDen_Eventscript_CooltrainerCara_Text_0, DragonsDen_Eventscript_CooltrainerCara_Text_1
	msgbox DragonsDen_Eventscript_CooltrainerCara_Text_2, MSGBOX_AUTOCLOSE
	end


DragonsDen_Eventscript_TwinTop::
	trainerbattle_single TRAINER_LEA_AND_PIA, DragonsDen_Eventscript_TwinTop_Text_0, DragonsDen_Eventscript_TwinTop_Text_1
	msgbox DragonsDen_Eventscript_TwinTop_Text_2, MSGBOX_AUTOCLOSE
	end


DragonsDen_Eventscript_TwinBottom::
	trainerbattle_single TRAINER_LEA_AND_PIA, DragonsDen_Eventscript_TwinBottom_Text_0, DragonsDen_Eventscript_TwinBottom_Text_1
	msgbox DragonsDen_Eventscript_TwinBottom_Text_2, MSGBOX_AUTOCLOSE
	end


DragonsDen_Eventscript_Sign_Text_0:
	.string "DRAGON SHRINE\pA shrine honoring the dragon POKéMON\nsaid to have lived in the DRAGON'S\lDEN.$"

DragonsDen_Eventscript_CooltrainerDarin_Text_0:
	.string "You! How dare you enter uninvited!$"

DragonsDen_Eventscript_CooltrainerDarin_Text_1:
	.string "S-strong!$"

DragonsDen_Eventscript_CooltrainerDarin_Text_2:
	.string "The SHRINE ahead is home to the\nMASTER of our dragon-user clan.\pYou're not allowed to just go in!$"

DragonsDen_Eventscript_CooltrainerCara_Text_0:
	.string "You shouldn't be in here!$"

DragonsDen_Eventscript_CooltrainerCara_Text_1:
	.string "Oh yikes, I lost!$"

DragonsDen_Eventscript_CooltrainerCara_Text_2:
	.string "Soon, I'm going to get permission\nfrom our MASTER to use dragons.\pWhen I do, I'm going to become an\nadmirable dragon TRAINER and gain\lour MASTER's approval.$"

DragonsDen_Eventscript_TwinTop_Text_0:
	.string "It's a stranger we don't know.$"

DragonsDen_Eventscript_TwinTop_Text_1:
	.string "Ouchies.$"

DragonsDen_Eventscript_TwinTop_Text_2:
	.string "It was like having to battle LANCE.$"

DragonsDen_Eventscript_TwinBottom_Text_0:
	.string "Who are you?$"

DragonsDen_Eventscript_TwinBottom_Text_1:
	.string "Meanie.$"

DragonsDen_Eventscript_TwinBottom_Text_2:
	.string "We'll tell on you.\nMASTER will be angry with you.$"
