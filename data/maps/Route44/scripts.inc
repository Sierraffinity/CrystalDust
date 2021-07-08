Route44_MapScripts::
	.byte 0


Route44_Eventscript_RouteSign::
	msgbox Route44_Eventscript_RouteSign_Text_0, MSGBOX_SIGN
	end


Route44_Eventscript_IcePathSign::
	msgbox Route44_Eventscript_IcePathSign_Text_0, MSGBOX_SIGN
	end


Route44_Eventscript_PsychicPhil::
	trainerbattle_single TRAINER_PHIL, Route44_Eventscript_PsychicPhil_Text_0, Route44_Eventscript_PsychicPhil_Text_1
	msgbox Route44_Eventscript_PsychicPhil_Text_2, MSGBOX_AUTOCLOSE
	end


Route44_Eventscript_FishermanEdgar::
	trainerbattle_single TRAINER_EDGAR, Route44_Eventscript_FishermanEdgar_Text_0, Route44_Eventscript_FishermanEdgar_Text_1
	msgbox Route44_Eventscript_FishermanEdgar_Text_2, MSGBOX_AUTOCLOSE
	end


Route44_Eventscript_FishermanWilton::
	trainerbattle_single TRAINER_WILTON_1, Route44_Eventscript_FishermanWilton_Text_0, Route44_Eventscript_FishermanWilton_Text_1
	msgbox Route44_Eventscript_FishermanWilton_Text_2, MSGBOX_AUTOCLOSE
	end


Route44_Eventscript_CooltrainerCybil::
	trainerbattle_single TRAINER_CYBIL, Route44_Eventscript_CooltrainerCybil_Text_0, Route44_Eventscript_CooltrainerCybil_Text_1
	msgbox Route44_Eventscript_CooltrainerCybil_Text_2, MSGBOX_AUTOCLOSE
	end


Route44_Eventscript_CooltrainerAllen::
	trainerbattle_single TRAINER_ALLEN, Route44_Eventscript_CooltrainerAllen_Text_0, Route44_Eventscript_CooltrainerAllen_Text_1
	msgbox Route44_Eventscript_CooltrainerAllen_Text_2, MSGBOX_AUTOCLOSE
	end


Route44_Eventscript_PokemaniacZach::
	trainerbattle_single TRAINER_ZACH, Route44_Eventscript_PokemaniacZach_Text_0, Route44_Eventscript_PokemaniacZach_Text_1
	msgbox Route44_Eventscript_PokemaniacZach_Text_2, MSGBOX_AUTOCLOSE
	end


Route44_Eventscript_BirdKeeperVance::
	trainerbattle_single TRAINER_VANCE_1, Route44_Eventscript_BirdKeeperVance_Text_0, Route44_Eventscript_BirdKeeperVance_Text_1
	msgbox Route44_Eventscript_BirdKeeperVance_Text_2, MSGBOX_AUTOCLOSE
	end


Route44_Eventscript_RouteSign_Text_0:
	.string "ROUTE 44\nMAHOGANY TOWN - BLACKTHORN CITY$"

Route44_Eventscript_IcePathSign_Text_0:
	.string "ROUTE 44\nICE PATH AHEAD$"

Route44_Eventscript_PsychicPhil_Text_0:
	.string "I'm gonna win, for sure!$"

Route44_Eventscript_PsychicPhil_Text_1:
	.string "Arrgh… That's a shocking loss…$"

Route44_Eventscript_PsychicPhil_Text_2:
	.string "It's important to have conviction on\nyour side.$"

Route44_Eventscript_FishermanEdgar_Text_0:
	.string "I fish until I can't anymore.\nI also battle until I drop.\pThat's my relationship with my\nPOKéMON.$"

Route44_Eventscript_FishermanEdgar_Text_1:
	.string "Hmmmm…\nThis isn't right.$"

Route44_Eventscript_FishermanEdgar_Text_2:
	.string "That's 100 wins to 101 losses.\nI won't battle again for a while.$"

Route44_Eventscript_FishermanWilton_Text_0:
	.string "Aack! You made me lose a POLIWAG!\nWhat are you going to do about it?$"

Route44_Eventscript_FishermanWilton_Text_1:
	.string "Just forget about it.$"

Route44_Eventscript_FishermanWilton_Text_2:
	.string "That POLIWAG that got away…\nIt was huge.\pI swear it must've been 16 feet long!$"

Route44_Eventscript_CooltrainerCybil_Text_0:
	.string "You look strong. Good TRAINERS seek\ntough opponents instinctively.$"

Route44_Eventscript_CooltrainerCybil_Text_1:
	.string "Nope! This won't do at all.$"

Route44_Eventscript_CooltrainerCybil_Text_2:
	.string "We all get better by experiencing\nmany battles.\pI battled a lot to become what I am\ntoday--an elite.$"

Route44_Eventscript_CooltrainerAllen_Text_0:
	.string "I can tell you're a good TRAINER by\nlooking at you.\pI'm good at POKéMON, and I can see\nthat you are too.$"

Route44_Eventscript_CooltrainerAllen_Text_1:
	.string "Tch! It's a total loss on my part.$"

Route44_Eventscript_CooltrainerAllen_Text_2:
	.string "Wow. You have a lot of BADGES.\nNo wonder you're so tough.\pI wonder if ECRUTEAK GYM's MORTY is\nstill in training?\pHe really hammered me.$"

Route44_Eventscript_PokemaniacZach_Text_0:
	.string "I'll do anything to get my hands on\nrare POKéMON!$"

Route44_Eventscript_PokemaniacZach_Text_1:
	.string "Oooh, your POKéMON are so appealing.$"

Route44_Eventscript_PokemaniacZach_Text_2:
	.string "If a POKéMON has different colors\nthan usual, it's more valuable.\pWhat? You mean that's not true?$"

Route44_Eventscript_BirdKeeperVance_Text_0:
	.string "Do you know about the legendary bird\nPOKéMON?$"

Route44_Eventscript_BirdKeeperVance_Text_1:
	.string "Whew! You're hot stuff.$"

Route44_Eventscript_BirdKeeperVance_Text_2:
	.string "ARTICUNO, ZAPDOS, and MOLTRES are\nthe three legendary bird POKéMON.\pI heard there are other legendary\nbirds, though.$"
