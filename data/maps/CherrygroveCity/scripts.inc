CherrygroveCity_MapScripts:: @ 81E8EA2
	map_script 3, CherrygroveCity_MapScript1_1E8EA8
	.byte 0

CherrygroveCity_MapScript1_1E8EA8: @ 81E8EA8
	setflag FLAG_VISITED_CHERRYGROVE_CITY
	end

CherrygroveCity_EventScript_GuideGentsHouse::
	msgbox CherrygroveCity_Text_GuideGentsHouse, MSGBOX_SIGN
	end

CherrygroveCity_EventScript_Slogan::
	msgbox CherrygroveCity_Text_Slogan, MSGBOX_SIGN
	end

CherrygroveCity_EventScript_GuideGent::
	lock
	faceplayer
	msgbox CherrygroveCity_Text_GuideGent_Intro, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq CherrygroveCity_EventScript_GuideGent_Accepted
	msgbox CherrygroveCity_Text_GuideGent_Rejected
	release
	end

CherrygroveCity_EventScript_GuideGent_Accepted:
	setflag FLAG_HIDE_CHERRYGROVE_CITY_GUIDE_GENT
	release
	end

CherrygroveCity_EventScript_Teacher::
	lock
	faceplayer
	goto_if_set FLAG_SYS_HAS_MAP_CARD, CherrygroveCity_EventScript_TeacherPostMapCard
	msgbox CherrygroveCity_Text_TeacherPreMapCard
	release
	end

CherrygroveCity_EventScript_TeacherPostMapCard:
	msgbox CherrygroveCity_Text_TeacherPostMapCard
	release
	end

CherrygroveCity_EventScript_Youngster::
	lock
	faceplayer
	goto_if_set FLAG_SYS_POKEDEX_GET, CherrygroveCity_EventScript_YoungsterPostDex
	msgbox CherrygroveCity_Text_YoungsterPreDex
	release
	end

CherrygroveCity_EventScript_YoungsterPostDex:
	msgbox CherrygroveCity_Text_YoungsterPostDex
	release
	end

CherrygroveCity_Text_GuideGent_Intro:
	.string "You're a rookie trainer, aren't you?\n"
	.string "I can tell!\p"
	.string "That's okay!\n"
	.string "Everyone is a rookie at some point!\p"
	.string "If you'd like, I can teach you a\n"
	.string "few things.$"

CherrygroveCity_Text_GuideGent_Rejected:
	.string "Oh…\n"
	.string "It's something I enjoy doing…\p"
	.string "Fine. Come see me when you like.$"

CherrygroveCity_Text_TeacherPreMapCard:
	.string "Did you talk to the old man by the\n"
	.string "POKéMON CENTER?\p"
	.string "He'll put a map of JOHTO on your\n"
	.string "POKéGEAR.$"

CherrygroveCity_Text_TeacherPostMapCard:
	.string "When you're with POKéMON, going\n"
	.string "anywhere is fun.$"

CherrygroveCity_Text_YoungsterPreDex:
	.string "MR. POKéMON's house is still farther\n"
	.string "up ahead.$"

CherrygroveCity_Text_YoungsterPostDex:
	.string "I battled the trainers on the road.\n"
	.string "My POKéMON lost. They're a mess!\p"
	.string "I need to take them to a POKéMON\n"
	.string "CENTER.$"

CherrygroveCity_Text_GuideGentsHouse:
	.string "GUIDE GENT'S HOUSE$"

CherrygroveCity_Text_Slogan:
	.string "CHERRYGROVE CITY\n"
	.string "The City of Cute, Fragrant Flowers$"
