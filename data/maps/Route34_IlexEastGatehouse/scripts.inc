Route34_IlexEastGatehouse_MapScripts:: @ 822AF28
	map_script MAP_SCRIPT_ON_TRANSITION, Route34_IlexEastGatehouse_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, Route34_IlexEastGatehouse_OnLoad
	.byte 0

Route34_IlexEastGatehouse_OnTransition: @ 822AF33
	call_if_set FLAG_SYS_GAME_CLEAR, Route34_IlexEastGatehouse_EventScript_MoveFossilManiac
	end

Route34_IlexEastGatehouse_EventScript_MoveFossilManiac:: @ 822AF3D
	setobjectxyperm 1, 6, 5
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_DOWN
	return

Route34_IlexEastGatehouse_OnLoad: @ 822AF49
	call_if_unset FLAG_SYS_GAME_CLEAR, Route34_IlexEastGatehouse_EventScript_CloseDesertUnderpass
	end

Route34_IlexEastGatehouse_EventScript_CloseDesertUnderpass:: @ 822AF53
	setmetatile 6, 1, METATILE_Fallarbor_RedRockWall, 1
	setmetatile 6, 2, METATILE_Fallarbor_RedRockWall, 1
	return

Route34_IlexEastGatehouse_EventScript_ManiacMentionCaveIn:: @ 822AF66
	lockall
	applymovement 1, Common_Movement_WalkInPlaceFastestUp
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	msgbox Route34_IlexEastGatehouse_Text_NotSafeThatWay, MSGBOX_DEFAULT
	setvar VAR_FOSSIL_MANIAC_STATE, 2
	releaseall
	end

Route34_IlexEastGatehouse_EventScript_FossilManiac:: @ 822AF87
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_REVIVED_FOSSIL_MON, Route34_IlexEastGatehouse_EventScript_PlayerRevivedFossil
	checkitem ITEM_ROOT_FOSSIL, 1
	compare VAR_RESULT, TRUE
	goto_if_eq Route34_IlexEastGatehouse_EventScript_PlayerHasFossil
	checkitem ITEM_CLAW_FOSSIL, 1
	compare VAR_RESULT, TRUE
	goto_if_eq Route34_IlexEastGatehouse_EventScript_PlayerHasFossil
	msgbox Route34_IlexEastGatehouse_Text_LookInDesertForFossils, MSGBOX_DEFAULT
	release
	end

Route34_IlexEastGatehouse_EventScript_PlayerHasFossil:: @ 822AFBC
	msgbox Route34_IlexEastGatehouse_Text_DevonCorpRevivingFossils, MSGBOX_DEFAULT
	release
	end

Route34_IlexEastGatehouse_EventScript_PlayerRevivedFossil:: @ 822AFC6
	msgbox Route34_IlexEastGatehouse_Text_FossilsAreWonderful, MSGBOX_DEFAULT
	release
	end

Route34_IlexEastGatehouse_Text_LookInDesertForFossils: @ 822AFD0
	.string "I'm the FOSSIL MANIAC…\n"
	.string "I'm a nice guy who loves FOSSILS…\p"
	.string "Do you want a FOSSIL?\p"
	.string "But the FOSSILS around these parts all\n"
	.string "belong to me… None for you…\p"
	.string "If you can't bear to go without\n"
	.string "a FOSSIL, look in a desert where there\l"
	.string "are boulders and sand that may hide\l"
	.string "FOSSILS…$"

Route34_IlexEastGatehouse_Text_DevonCorpRevivingFossils: @ 822B0D6
	.string "You found a FOSSIL, didn't you?\n"
	.string "That's so nice… It's so dreamy…\p"
	.string "What are you going to do with that\n"
	.string "FOSSIL?\p"
	.string "From what I've heard, DEVON is doing\n"
	.string "research on reviving POKéMON from\l"
	.string "FOSSILS…\p"
	.string "I love my FOSSILS, so I would never\n"
	.string "do anything like that…$"

Route34_IlexEastGatehouse_Text_FossilsAreWonderful: @ 822B1CC
	.string "FOSSILS are so… Wonderful…\n"
	.string "It's so dreamy…$"

Route34_IlexEastGatehouse_Text_NotSafeThatWay: @ 822B1F7
	.string "Oh…\n"
	.string "It's not safe that way…\p"
	.string "I was digging away, you see…\n"
	.string "When the whole wall collapsed…\p"
	.string "I think there's a giant cavern\n"
	.string "underneath now…\p"
	.string "But I've left it alone because I don't\n"
	.string "think there are any FOSSILS there…$"

