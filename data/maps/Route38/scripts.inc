Route38_MapScripts::
	.byte 0


Route38_Eventscript_RouteSign::
	msgbox Route38_Eventscript_RouteSign_Text_0, MSGBOX_SIGN
	end


Route38_Eventscript_TrainerTipsSign::
	msgbox Route38_Eventscript_TrainerTipsSign_Text_0, MSGBOX_SIGN
	end


Route38_Eventscript_SailorHarry::
	trainerbattle_single TRAINER_HARRY, Route38_Eventscript_SailorHarry_Text_0, Route38_Eventscript_SailorHarry_Text_1
	msgbox Route38_Eventscript_SailorHarry_Text_2, MSGBOX_AUTOCLOSE
	end


Route38_Eventscript_LassDana::
	trainerbattle_single TRAINER_DANA_1, Route38_Eventscript_LassDana_Text_0, Route38_Eventscript_LassDana_Text_1
	msgbox Route38_Eventscript_LassDana_Text_2, MSGBOX_AUTOCLOSE
	end


Route38_Eventscript_BeautyValerie::
	trainerbattle_single TRAINER_VALERIE, Route38_Eventscript_BeautyValerie_Text_0, Route38_Eventscript_BeautyValerie_Text_1
	msgbox Route38_Eventscript_BeautyValerie_Text_2, MSGBOX_AUTOCLOSE
	end


Route38_Eventscript_BirdKeeperToby::
	trainerbattle_single TRAINER_TOBY, Route38_Eventscript_BirdKeeperToby_Text_0, Route38_Eventscript_BirdKeeperToby_Text_1
	msgbox Route38_Eventscript_BirdKeeperToby_Text_2, MSGBOX_AUTOCLOSE
	end


Route38_Eventscript_SchoolboyChad::
	trainerbattle_single TRAINER_CHAD_1, Route38_Eventscript_SchoolboyChad_Text_0, Route38_Eventscript_SchoolboyChad_Text_1
	msgbox Route38_Eventscript_SchoolboyChad_Text_2, MSGBOX_AUTOCLOSE
	end


Route38_Eventscript_BeautyOlivia::
	trainerbattle_single TRAINER_OLIVIA, Route38_Eventscript_BeautyOlivia_Text_0, Route38_Eventscript_BeautyOlivia_Text_1
	msgbox Route38_Eventscript_BeautyOlivia_Text_2, MSGBOX_AUTOCLOSE
	end


Route38_Eventscript_RouteSign_Text_0:
	.string "ROUTE 38\nOLIVINE CITY - ECRUTEAK CITY$"

Route38_Eventscript_TrainerTipsSign_Text_0:
	.string "TRAINER TIPS\pIf a POKéMON is trying to evolve,\nyou can stop it.\pPress the B button during evolution.\pThat startles the POKéMON and stops\nits evolution.$"

Route38_Eventscript_SailorHarry_Text_0:
	.string "I've been overseas, so I know about\nall sorts of POKéMON!$"

Route38_Eventscript_SailorHarry_Text_1:
	.string "Your skill is world class!$"

Route38_Eventscript_SailorHarry_Text_2:
	.string "All kinds of people around the world\nlive happily with POKéMON.$"

Route38_Eventscript_LassDana_Text_0:
	.string "You seem to be good at POKéMON.\pIf you are, how about giving me some\nadvice?$"

Route38_Eventscript_LassDana_Text_1:
	.string "I see. So you can battle that way.$"

Route38_Eventscript_LassDana_Text_2:
	.string "I know something good!\pThe MOOMOO FARM's milk is famous for\nits flavor.$"

Route38_Eventscript_BeautyValerie_Text_0:
	.string "Hi! Aren't you a cute TRAINER!\nMay I see your POKéMON?$"

Route38_Eventscript_BeautyValerie_Text_1:
	.string "I'm glad I got to see your POKéMON!$"

Route38_Eventscript_BeautyValerie_Text_2:
	.string "When I see POKéMON, they seem to\nsoothe my nerves.$"

Route38_Eventscript_BirdKeeperToby_Text_0:
	.string "Fly high into the sky, my beloved\nbird POKéMON!$"

Route38_Eventscript_BirdKeeperToby_Text_1:
	.string "I feel like just flying away now.$"

Route38_Eventscript_BirdKeeperToby_Text_2:
	.string "I plan to train in CIANWOOD CITY to\nteach my POKéMON how to FLY.$"

Route38_Eventscript_SchoolboyChad_Text_0:
	.string "Let me try something I learned today.$"

Route38_Eventscript_SchoolboyChad_Text_1:
	.string "I didn't study enough, I guess.$"

Route38_Eventscript_SchoolboyChad_Text_2:
	.string "I have to take so many tests, I\ndon't have much time for POKéMON.\pSo when I do get to play, I really\nconcentrate.$"

Route38_Eventscript_BeautyOlivia_Text_0:
	.string "Don't you think my POKéMON and I are\nbeautiful?$"

Route38_Eventscript_BeautyOlivia_Text_1:
	.string "We drink MOOMOO MILK every day.$"

Route38_Eventscript_BeautyOlivia_Text_2:
	.string "MOOMOO MILK is good for beauty and\nhealth, but inconveniently, they\lonly sell a bottle at a time.$"
