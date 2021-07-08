Route45_MapScripts::
	.byte 0


Route45_Eventscript_RouteSign::
	msgbox Route45_Eventscript_RouteSign_Text_0, MSGBOX_SIGN
	end


Route45_Eventscript_HikerErik::
	trainerbattle_single TRAINER_ERIK, Route45_Eventscript_HikerErik_Text_0, Route45_Eventscript_HikerErik_Text_1
	msgbox Route45_Eventscript_HikerErik_Text_2, MSGBOX_AUTOCLOSE
	end


Route45_Eventscript_CooltrainerRyan::
	trainerbattle_single TRAINER_RYAN, Route45_Eventscript_CooltrainerRyan_Text_0, Route45_Eventscript_CooltrainerRyan_Text_1
	msgbox Route45_Eventscript_CooltrainerRyan_Text_2, MSGBOX_AUTOCLOSE
	end


Route44_Eventscript_HikerParry::
	trainerbattle_single TRAINER_PARRY_1, Route44_Eventscript_HikerParry_Text_0, Route44_Eventscript_HikerParry_Text_1
	msgbox Route44_Eventscript_HikerParry_Text_2, MSGBOX_AUTOCLOSE
	end


Route45_Eventscript_CooltrainerKelly::
	trainerbattle_single TRAINER_KELLY, Route45_Eventscript_CooltrainerKelly_Text_0, Route45_Eventscript_CooltrainerKelly_Text_1
	msgbox Route45_Eventscript_CooltrainerKelly_Text_2, MSGBOX_AUTOCLOSE
	end


Route45_Eventscript_BlackBeltKenji::
	trainerbattle_single TRAINER_KENJI, Route45_Eventscript_BlackBeltKenji_Text_0, Route45_Eventscript_BlackBeltKenji_Text_1
	msgbox Route45_Eventscript_BlackBeltKenji_Text_2, MSGBOX_AUTOCLOSE
	end


Route45_Eventscript_HikerTimothy::
	trainerbattle_single TRAINER_TIMOTHY, Route45_Eventscript_HikerTimothy_Text_0, Route45_Eventscript_HikerTimothy_Text_1
	msgbox Route45_Eventscript_HikerTimothy_Text_2, MSGBOX_AUTOCLOSE
	end


Route45_Eventscript_HikerMichael::
	trainerbattle_single TRAINER_MICHAEL, Route45_Eventscript_HikerMichael_Text_0, Route45_Eventscript_HikerMichael_Text_1
	msgbox Route45_Eventscript_HikerMichael_Text_2, MSGBOX_AUTOCLOSE
	end


Route45_Eventscript_CamperQuentin::
	trainerbattle_single TRAINER_QUENTIN, Route45_Eventscript_CamperQuentin_Text_0, Route45_Eventscript_CamperQuentin_Text_1
	msgbox Route45_Eventscript_CamperQuentin_Text_2, MSGBOX_AUTOCLOSE
	end


Route45_Eventscript_RouteSign_Text_0:
	.string "ROUTE 45\nMOUNTAIN ROAD AHEAD$"

Route45_Eventscript_HikerErik_Text_0:
	.string "Be prepared for anything!\pLet me see if your POKéMON have been\nraised properly!$"

Route45_Eventscript_HikerErik_Text_1:
	.string "Oh, I lost that!$"

Route45_Eventscript_HikerErik_Text_2:
	.string "I'll head back to BLACKTHORN's ICE\nPATH and train some more.$"

Route45_Eventscript_CooltrainerRyan_Text_0:
	.string "What are your thoughts on raising\nPOKéMON?$"

Route45_Eventscript_CooltrainerRyan_Text_1:
	.string "You've won my respect.$"

Route45_Eventscript_CooltrainerRyan_Text_2:
	.string "I see you're raising your POKéMON\nwith care.\pThe bond you build will save you in\ntough situations.$"

Route44_Eventscript_HikerParry_Text_0:
	.string "My POKéMON are power packed!$"

Route44_Eventscript_HikerParry_Text_1:
	.string "Wahahah! I'm the big loser!$"

Route44_Eventscript_HikerParry_Text_2:
	.string "I'm not much good at thinking, see?\nSo, I just plow ahead with power!$"

Route45_Eventscript_CooltrainerKelly_Text_0:
	.string "What is your battle strategy?\pIt is foolish to use strong moves\nindiscriminately.$"

Route45_Eventscript_CooltrainerKelly_Text_1:
	.string "Fine. I lost.$"

Route45_Eventscript_CooltrainerKelly_Text_2:
	.string "I'm not in favor of overly powerful\nmoves.\pI want to win, but I also don't want\nto harm POKéMON.$"

Route45_Eventscript_BlackBeltKenji_Text_0:
	.string "I was training here alone.\nBehold the fruits of my labor!$"

Route45_Eventscript_BlackBeltKenji_Text_1:
	.string "Waaaargh!$"

Route45_Eventscript_BlackBeltKenji_Text_2:
	.string "This calls for extreme measures.\pI must take to the hills and train\nin solitude.$"

Route45_Eventscript_HikerTimothy_Text_0:
	.string "Why do I climb mountains?\nBecause they're there.\pWhy do I train POKéMON?\nBecause they're there!$"

Route45_Eventscript_HikerTimothy_Text_1:
	.string "Losses…\nThey're there too!$"

Route45_Eventscript_HikerTimothy_Text_2:
	.string "The best thing to ever happen to me\nwas discovering POKéMON.$"

Route45_Eventscript_HikerMichael_Text_0:
	.string "Yo! You're spunky!\nBut you know what?\pWhen it comes to sheer spunkiness,\nI'm the man!$"

Route45_Eventscript_HikerMichael_Text_1:
	.string "My POKéMON weren't spunky enough!$"

Route45_Eventscript_HikerMichael_Text_2:
	.string "Boy, do I love HP UP! Mmmm, yum!\pI keep drinking my POKéMON's!\nI can't help it!$"

Route45_Eventscript_CamperQuentin_Text_0:
	.string "I'm really, really tough!$"

Route45_Eventscript_CamperQuentin_Text_1:
	.string "I was tough at the BATTLE TOWER…$"

Route45_Eventscript_CamperQuentin_Text_2:
	.string "Have you been to the BATTLE TOWER?\nI never, ever lose there, but…$"
