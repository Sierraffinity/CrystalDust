OlivineCity_PokemonCenter_1F_MapScripts::
	.byte 0


OlivineCity_PokemonCenter_1F_Eventscript_Woman::
	msgbox OlivineCity_PokemonCenter_1F_Eventscript_Woman_Text_0, MSGBOX_NPC
	end


OlivineCity_PokemonCenter_1F_Eventscript_FatMan::
	msgbox OlivineCity_PokemonCenter_1F_Eventscript_FatMan_Text_0, MSGBOX_NPC
	end


OlivineCity_PokemonCenter_1F_Eventscript_BugCatcher::
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	compare VAR_RESULT, 2
	goto_if_lt OlivineCity_PokemonCenter_1F_Eventscript_BugCatcher_2
	compare VAR_RESULT, 4
	goto_if_lt OlivineCity_PokemonCenter_1F_Eventscript_BugCatcher_5
	msgbox OlivineCity_PokemonCenter_1F_Eventscript_BugCatcher_Text_2, MSGBOX_NPC
	end

OlivineCity_PokemonCenter_1F_Eventscript_BugCatcher_2:
	msgbox OlivineCity_PokemonCenter_1F_Eventscript_BugCatcher_Text_0, MSGBOX_NPC
	end

OlivineCity_PokemonCenter_1F_Eventscript_BugCatcher_5:
	msgbox OlivineCity_PokemonCenter_1F_Eventscript_BugCatcher_Text_1, MSGBOX_NPC
	end


OlivineCity_PokemonCenter_1F_Eventscript_Woman_Text_0:
	.string "There's a person in CIANWOOD CITY\nacross the sea.\pI heard him bragging about his rare\nPOKéMON.$"

OlivineCity_PokemonCenter_1F_Eventscript_FatMan_Text_0:
	.string "The SAILOR in the OLIVINE CAFE next\ndoor is really generous.\pHe taught my POKéMON STRENGTH.\nNow it can move big boulders!$"

OlivineCity_PokemonCenter_1F_Eventscript_BugCatcher_Text_0:
	.string "You haven't tamed your POKéMON.\nIf you aren't nice, it'll pout.$"

OlivineCity_PokemonCenter_1F_Eventscript_BugCatcher_Text_1:
	.string "POKéMON get more friendly if you\nspend time with them.$"

OlivineCity_PokemonCenter_1F_Eventscript_BugCatcher_Text_2:
	.string "Wow! You and your POKéMON are really\nclose!$"
