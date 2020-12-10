NationalPark_BugCatchingContest_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, NationalPark_BugCatchingContest_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

NationalPark_BugCatchingContest_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	setflag FLAG_LANDMARK_NATIONAL_PARK
	return

NationalPark_BugCatchingContest_Nick::
	msgbox NationalPark_BugCatchingContest_Text_Nick, MSGBOX_NPC
	end

NationalPark_BugCatchingContest_William::
	msgbox NationalPark_BugCatchingContest_Text_William, MSGBOX_NPC
	end

NationalPark_BugCatchingContest_Samuel::
	msgbox NationalPark_BugCatchingContest_Text_Samuel, MSGBOX_NPC
	end

NationalPark_BugCatchingContest_Barry::
	msgbox NationalPark_BugCatchingContest_Text_Barry, MSGBOX_NPC
	end

NationalPark_BugCatchingContest_Ed::
	msgbox NationalPark_BugCatchingContest_Text_Ed, MSGBOX_NPC
	end

NationalPark_BugCatchingContest_Benny::
	msgbox NationalPark_BugCatchingContest_Text_Benny, MSGBOX_NPC
	end

NationalPark_BugCatchingContest_Josh::
	msgbox NationalPark_BugCatchingContest_Text_Josh, MSGBOX_NPC
	end

NationalPark_BugCatchingContest_Don::
	msgbox NationalPark_BugCatchingContest_Text_Don, MSGBOX_NPC
	end

NationalPark_BugCatchingContest_Kipp::
	msgbox NationalPark_BugCatchingContest_Text_Kipp, MSGBOX_NPC
	end

NationalPark_BugCatchingContest_Cindy::
	msgbox NationalPark_BugCatchingContest_Text_Cindy, MSGBOX_NPC
	end

NationalPark_BugCatchingContest_Text_Nick:
	.string "NICK: I'm raising fast POKéMON\n"
	.string "for battles.$"

NationalPark_BugCatchingContest_Text_William::
	.string "WILLIAM: I'm not concerned about\n"
	.string "winning.\p"
	.string "I'm just looking for rare POKéMON.$"

NationalPark_BugCatchingContest_Text_Samuel::
	.string "SAMUEL: If you've got the time to\n"
	.string "chat, go find some BUG POKéMON.$"

NationalPark_BugCatchingContest_Text_Barry::
	.string "BARRY: You should weaken BUG\n"
	.string "POKéMON first, then throw a BALL.$"

NationalPark_BugCatchingContest_Text_Ed::
	.string "ED: My PARASECT puts POKéMON to\n"
	.string "sleep with SPORE.$"

NationalPark_BugCatchingContest_Text_Benny::
	.string "BENNY: Ssh! You'll scare off\n"
	.string "SCYTHER.\p"
	.string "I'll talk to you later.$"

NationalPark_BugCatchingContest_Text_Josh::
	.string "JOSH: I've been collecting BUG\n"
	.string "POKéMON since I was just a baby.\p"
	.string "Theres no way I'm going to lose!$"

NationalPark_BugCatchingContest_Text_Don::
	.string "DON: I'm going to win!\n"
	.string "Don't bother me.$"

NationalPark_BugCatchingContest_Text_Kipp::
	.string "KIPP: I've studied BUG POKéMON a\n"
	.string "lot.\p"
	.string "I'm going to win for sure.$"

NationalPark_BugCatchingContest_Text_Cindy::
	.string "CINDY: I love BUG POKéMON.\p"
	.string "I guess you must like them, too.$"
