Route36_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route36_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_RESUME, Route36_MapScripts_MAP_SCRIPT_ON_RESUME
	.byte 0

Route36_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	gettime
	compare VAR_0x8003, DAY_THURSDAY
	goto_if_eq Route36_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	setflag FLAG_HIDE_ROUTE_36_ARTHUR
	return

Route36_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
	clearflag FLAG_HIDE_ROUTE_36_ARTHUR
	return

Route36_MapScripts_MAP_SCRIPT_ON_RESUME:
	goto_if_set FLAG_SYS_CTRL_OBJ_DELETE, Route36_MapScripts_MAP_SCRIPT_ON_RESUME_1
	return

Route36_MapScripts_MAP_SCRIPT_ON_RESUME_1:
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq Route36_MapScripts_MAP_SCRIPT_ON_RESUME_3
	return

Route36_MapScripts_MAP_SCRIPT_ON_RESUME_3:
	removeobject VAR_LAST_TALKED
	return


Route36_EventScript_Arthur::
	lock
	faceplayer
	goto_if_unset FLAG_RECEIVED_HARD_STONE_FROM_ARTHUR, Route36_EventScript_Arthur_2
	msgbox Route36_EventScript_Arthur_Text_4
Route36_EventScript_Arthur_1:
	release
	return

Route36_EventScript_Arthur_2:
	gettime
	compare VAR_0x8003, DAY_THURSDAY
	goto_if_eq Route36_EventScript_Arthur_5
	msgbox Route36_EventScript_Arthur_Text_3
	goto Route36_EventScript_Arthur_1

Route36_EventScript_Arthur_5:
	goto_if_unset FLAG_MET_ARTHUR_OF_THURSDAY, Route36_EventScript_Arthur_9
	msgbox Route36_EventScript_Arthur_Text_1
Route36_EventScript_Arthur_8:
	giveitem ITEM_HARD_STONE
	compare VAR_RESULT, 0
	goto_if_eq Route36_EventScript_Arthur_13
Route36_EventScript_Arthur_12:
	setflag FLAG_RECEIVED_HARD_STONE_FROM_ARTHUR
	msgbox Route36_EventScript_Arthur_Text_2
	goto Route36_EventScript_Arthur_1

Route36_EventScript_Arthur_9:
	msgbox Route36_EventScript_Arthur_Text_0
	setflag FLAG_MET_ARTHUR_OF_THURSDAY
	goto Route36_EventScript_Arthur_8

Route36_EventScript_Arthur_13:
	goto Common_EventScript_ShowBagIsFull
	goto Route36_EventScript_Arthur_12


Route36_EventScript_BlockedGirl::
	lock
	faceplayer
	goto_if_unset FLAG_DEFEATED_SUDOWOODO, Route36_EventScript_BlockedGirl_2
	msgbox Route36_EventScript_BlockedGirl_Text_1
Route36_EventScript_BlockedGirl_1:
	release
	return

Route36_EventScript_BlockedGirl_2:
	msgbox Route36_EventScript_BlockedGirl_Text_0
	goto Route36_EventScript_BlockedGirl_1


Route36_EventScript_RockSmashGuy::
	lock
	faceplayer
	goto_if_unset FLAG_RECEIVED_HM06, Route36_EventScript_RockSmashGuy_2
	msgbox Route36_Text_RockSmashGuy_PostHM
Route36_EventScript_RockSmashGuy_1:
	release
	return

Route36_EventScript_RockSmashGuy_2:
	goto_if_unset FLAG_DEFEATED_SUDOWOODO, Route36_EventScript_RockSmashGuy_5
	msgbox Route36_EventScript_RockSmashGuy_Text_1
	giveitem ITEM_HM06
	setflag FLAG_RECEIVED_HM06
	msgbox Route36_Text_RockSmashGuy_PostHM
	goto Route36_EventScript_RockSmashGuy_1

Route36_EventScript_RockSmashGuy_5:
	msgbox Route36_EventScript_RockSmashGuy_Text_0
	release
	end


Route36_EventScript_Sudowoodo::
	lock
	checkitem ITEM_SQUIRTBOTTLE, 1
	compare VAR_RESULT, TRUE
	goto_if_eq Route36_EventScript_Sudowoodo_2
	waitse
	playse SE_SUDOWOODO_SHAKE
	applymovement 3, Route36_Movement_Sudowoodo
	waitmovement 0
Route36_EventScript_Sudowoodo_1:
	release
	return

Route36_EventScript_Sudowoodo_2:
	msgbox Route36_EventScript_Sudowoodo_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Route36_EventScript_Sudowoodo_5
	goto Route36_EventScript_Sudowoodo_1

Route36_EventScript_Sudowoodo_5:
	goto Route36_EventScript_UseSquirtbottleOnSudowoodo
	goto Route36_EventScript_Sudowoodo_1


Route36_EventScript_UseSquirtbottleOnSudowoodo::
	lock
	msgbox Route36_EventScript_UseSquirtbottleOnSudowoodo_Text_0
	closemessage
	waitse
	playse SE_SUDOWOODO_SHAKE
	applymovement 3, Route36_Movement_Sudowoodo
	waitmovement 0
	msgbox Route36_EventScript_UseSquirtbottleOnSudowoodo_Text_1
	closemessage
	waitse
	playmoncry SPECIES_SUDOWOODO, 2
	delay 40
	waitmoncry
	setvar VAR_LAST_TALKED, 3
	setwildbattle SPECIES_SUDOWOODO, 20, ITEM_NONE
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	switch VAR_RESULT
	case B_OUTCOME_WON, Route36_EventScript_UseSquirtbottleOnSudowoodo_3
	case B_OUTCOME_RAN, Route36_EventScript_UseSquirtbottleOnSudowoodo_3
	case B_OUTCOME_PLAYER_TELEPORTED, Route36_EventScript_UseSquirtbottleOnSudowoodo_3
Route36_EventScript_UseSquirtbottleOnSudowoodo_1:
	setflag FLAG_DEFEATED_SUDOWOODO
	release
	return

Route36_EventScript_UseSquirtbottleOnSudowoodo_3:
	call Common_EventScript_RemoveStaticPokemon
	goto Route36_EventScript_UseSquirtbottleOnSudowoodo_1


Route36_Movement_Sudowoodo:
	face_right
	delay_8
	face_down
	delay_8
	face_left
	delay_8
	face_down
	delay_8
	face_right
	delay_8
	face_down
	delay_8
	face_left
	delay_8
	face_down
	step_end

Route36_EventScript_DirectionsSign::
	msgbox Route36_EventScript_DirectionsSign_Text_0, MSGBOX_SIGN
	return


Route36_EventScript_RuinsOfAlphSign::
	msgbox Route36_EventScript_RuinsOfAlphSign_Text_0, MSGBOX_SIGN
	return


Route36_EventScript_TrainerTipsStatsSign::
	msgbox Route36_EventScript_TrainerTipsStatsSign_Text_0, MSGBOX_SIGN
	return


Route36_EventScript_Mark::
	trainerbattle_single TRAINER_MARK, Route36_Text_MarkIntro, Route36_Text_MarkDefeated
	msgbox Route36_Text_MarkPostBattle, MSGBOX_AUTOCLOSE
	return


Route36_EventScript_Alan::
	trainerbattle_single TRAINER_ALAN, Route36_Text_AlanIntro, Route36_Text_AlanDefeated
	msgbox Route36_Text_AlanPostBattle, MSGBOX_AUTOCLOSE
	return


Route36_EventScript_Floria::
	lock
	faceplayer
	goto_if_set FLAG_TALKED_TO_FLORIA_FLOWER_SHOP, Route36_EventScript_Floria_2
	msgbox Route36_EventScript_Floria_Text_1
	closemessage
	switch VAR_FACING
	case DIR_EAST, Route36_EventScript_Floria_7
	case DIR_WEST, Route36_EventScript_Floria_8
	applymovement OBJ_EVENT_ID_PLAYER, Route36_Movement_PlayerWatchFloriaFromBelow
	applymovement 7, Route36_Movement_FloriaLeaveFromBelow
Route36_EventScript_Floria_5:
	waitmovement 0
	setflag FLAG_MET_FLORIA_ROUTE_36
	clearflag FLAG_HIDE_GOLDENROD_CITY_FLOWER_SHOP_FLORIA
	removeobject 7
Route36_EventScript_Floria_1:
	release
	return

Route36_EventScript_Floria_2:
	msgbox Route36_EventScript_Floria_Text_0
	goto Route36_EventScript_Floria_1

Route36_EventScript_Floria_7:
	applymovement OBJ_EVENT_ID_PLAYER, Route36_Movement_PlayerWatchFloriaLeftRight
	applymovement 7, Route36_Movement_FloriaLeaveFromLeft
	goto Route36_EventScript_Floria_5

Route36_EventScript_Floria_8:
	applymovement OBJ_EVENT_ID_PLAYER, Route36_Movement_PlayerWatchFloriaLeftRight
	applymovement 7, Route36_Movement_FloriaLeaveFromRight
	goto Route36_EventScript_Floria_5


Route36_Movement_PlayerWatchFloriaLeftRight:
	walk_in_place_fastest_down
	step_end

Route36_Movement_FloriaLeaveFromLeft:
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

Route36_Movement_FloriaLeaveFromRight:
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

Route36_Movement_PlayerWatchFloriaFromBelow:
	walk_in_place_fastest_left
	delay_16
	delay_16
	walk_in_place_fastest_down
	step_end

Route36_Movement_FloriaLeaveFromBelow:
	walk_left
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

Route36_EventScript_SierraPoopsTheParty::
	lockall
	setobjectxyperm 9, 25, 7
	addobject 9
	compare VAR_FACING, DIR_NORTH
	goto_if_eq Route36_EventScript_SierraPoopsTheParty_2
Route36_EventScript_SierraPoopsTheParty_1:
	applymovement 9, Route36_Movement_SierraToPlayerBelow
	waitmovement 0
	textcolor MSG_COLOR_RED
	msgbox Route36_EventScript_SierraPoopsTheParty_Text_0
	closemessage
	special SpawnCameraObject
	applymovement 9, Route36_Movement_SierraBulliesPlayer
	applymovement OBJ_EVENT_ID_PLAYER, Route36_Movement_PlayerStepsBack
	waitmovement 0
	playbgm MUS_RG_HALL_OF_FAME, 0
	msgbox Route36_EventScript_SierraPoopsTheParty_Text_1
	msgbox Route36_EventScript_SierraPoopsTheParty_Text_2
	msgbox Route36_EventScript_SierraPoopsTheParty_Text_3
	msgbox Route36_EventScript_SierraPoopsTheParty_Text_4
	closemessage
	applymovement 9, Route36_Movement_SierraToGuardPosition
	applymovement OBJ_EVENT_ID_CAMERA, Route36_Movement_CameraBackToPlayer
	waitmovement 0
	special RemoveCameraObject
	fadedefaultbgm
	setvar VAR_ROUTE36_STATE, 1
	clearflag FLAG_HIDE_ROUTE_36_SIERRA
	releaseall
	return

Route36_EventScript_SierraPoopsTheParty_2:
	applymovement OBJ_EVENT_ID_PLAYER, Route36_Movement_NoticeSierra
	goto Route36_EventScript_SierraPoopsTheParty_1


Route36_Movement_NoticeSierra:
	delay_16
	delay_16
	delay_16
	walk_in_place_fastest_left
	step_end

Route36_Movement_SierraToPlayerBelow:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	step_end

Route36_Movement_SierraBulliesPlayer:
	walk_right
	face_down
	step_end

Route36_Movement_PlayerStepsBack:
	lock_facing_direction
	walk_right
	unlock_facing_direction
	step_end

Route36_Movement_SierraToGuardPosition:
	walk_left
	face_right
	step_end

Route36_Movement_CameraBackToPlayer:
	walk_right
	step_end

Route36_EventScript_Sierra::
	msgbox Route36_EventScript_Sierra_Text_0, MSGBOX_NPC
	return


Route36_EventScript_Arthur_Text_0:
	.string "ARTHUR: Who are you?\n"
	.string "I'm ARTHUR of THURSDAY.\p"
	.string "Here.\n"
	.string "You can have this.$"

Route36_EventScript_Arthur_Text_1:
	.string "ARTHUR: Here.\n"
	.string "You can have this.$"

Route36_EventScript_Arthur_Text_2:
	.string "ARTHUR: A POKéMON that uses ROCK-\n"
	.string "type moves should hold onto that.\p"
	.string "It pumps up ROCK-type attacks.$"

Route36_EventScript_Arthur_Text_3:
	.string "ARTHUR: Today's not THURSDAY.\n"
	.string "How disappointing.$"

Route36_EventScript_Arthur_Text_4:
	.string "ARTHUR: I'm ARTHUR of THURSDAY.\n"
	.string "I'm the second son out of\l"
	.string "seven children.$"

Route36_EventScript_BlockedGirl_Text_0:
	.string "An odd tree is blocking the way\n"
	.string "to GOLDENROD CITY.\p"
	.string "I wanted to go see the huge\n"
	.string "POKéMON CENTER they just opened…$"

Route36_EventScript_BlockedGirl_Text_1:
	.string "That odd tree disappeared without\n"
	.string "a trace.\p"
	.string "Oh!\n"
	.string "That tree was really a POKéMON?$"

Route36_EventScript_RockSmashGuy_Text_0:
	.string "Wa-hey!\p"
	.string "I was going to snap that tree with\n"
	.string "my straight-arm punch.\p"
	.string "But I couldn't!\n"
	.string "I'm a failure!$"

Route36_EventScript_RockSmashGuy_Text_1:
	.string "Did you clear that wretched tree?\n"
	.string "I'm impressed!\l"
	.string "I want you to have this.$"

Route36_EventScript_Sudowoodo_Text_0:
	.string "It's a weird tree.\n"
	.string "Use the SQUIRTBOTTLE?$"

Route36_EventScript_UseSquirtbottleOnSudowoodo_Text_0:
	.string "{PLAYER} used the SQUIRTBOTTLE.$"

Route36_EventScript_UseSquirtbottleOnSudowoodo_Text_1:
	.string "The weird tree doesn't like the\n"
	.string "SQUIRTBOTTLE!\p"
	.string "The weird tree attacked!$"

Route36_EventScript_DirectionsSign_Text_0:
	.string "ROUTE 36$"

Route36_EventScript_RuinsOfAlphSign_Text_0:
	.string "RUINS OF ALPH\n"
	.string "NORTH ENTRANCE$"

Route36_EventScript_TrainerTipsStatsSign_Text_0:
	.string "TRAINER TIPS\p"
	.string "POKéMON stats vary--even within\n"
	.string "the same species.\p"
	.string "Their stats may appear to be similar\n"
	.string "at first.\p"
	.string "However, differences will become\n"
	.string "pronounced as the POKéMON grow.$"

Route36_EventScript_Floria_Text_0:
	.string "When I told my sis about the jiggly\n"
	.string "tree, she said it's dangerous.\p"
	.string "If I beat WHITNEY, I wonder if she'll\n"
	.string "lend me her water bottle…$"

Route36_EventScript_Floria_Text_1:
	.string "I'm the FLOWER SHOP's FLORIA!\n"
	.string "Listen, listen!\p"
	.string "When I sprinkled water on that\n"
	.string "wiggly tree, it jumped right up!\l"
	.string "It just has to be a POKéMON.\p"
	.string "I bet it would be shocked out of\n"
	.string "its disguise if you soaked it!\p"
	.string "I know! I'll tell my sis and borrow\n"
	.string "her water bottle!$"

Route36_EventScript_SierraPoopsTheParty_Text_0:
	.string "SIERRA: Hey, whoa, now. The road up\n"
	.string "ahead is still under construction.\p"
	.string "It's going to take a while before\n"
	.string "you can come through safely.\p"
	.string "The construction crew is hard at\n"
	.string "work, doing… construction-y things.\p"
	.string "Taking things out of the ground…\n"
	.string "Putting other things in…\l"
	.string "It's a whole process.\p"
	.string "Hey, don't ask me, I'm just a simple\n"
	.string "programmer who do thing with code.\p"
	.string "Anyway…$"

Route36_EventScript_SierraPoopsTheParty_Text_1:
	.string "Thank you so much for playing!\p"
	.string "I know it's been a while, and I know\n"
	.string "this isn't much, but I'm proud of\l"
	.string "what I've done so far.\p"
	.string "Thank you to everyone who has stuck\n"
	.string "with me for the past decade!$"

Route36_EventScript_SierraPoopsTheParty_Text_2:
	.string "A particularly big thanks to all the\n"
	.string "people who have contributed to the\l"
	.string "project in one way or another, be\l"
	.string "it art or music or… well, anything.\p"
	.string "This project would not be where it\n"
	.string "is today without you.$"

Route36_EventScript_SierraPoopsTheParty_Text_3:
	.string "Of course, a huge shout-out to my\n"
	.string "Patrons and alpha testers, who are\l"
	.string "super cool and great and such.\p"
	.string "Thanks for putting up with my awful\n"
	.string "ability to get out alpha builds.$"

Route36_EventScript_SierraPoopsTheParty_Text_4:
	.string "And again, to you, the player…\p"
	.string "{PLAYER}…\p"
	.string "Thank you so much-a for to playing\n"
	.string "my game.\p"
	.string "Now, for my last task…\n"
	.string "To stand here, on guard.\l"
	.string "Until the end of time…$"

Route36_EventScript_Sierra_Text_0:
	.string "SIERRA: Hey, {PLAYER}!\n"
	.string "How goes the, erm, playing?\p"
	.string "The construction crew is definitely\n"
	.string "hard at work back here, yes.\p"
	.string "If you want to know when it's done\n"
	.string "as soon as possible, you should\l"
	.string "check out my website!\p"
	.string "https://domoreaweso.me\p"
	.string "It may not be updated frequently,\n"
	.string "but there's probably a link you can\l"
	.string "click there for a Discord server\l"
	.string "or whatever the kids use nowadays.\p"
	.string "Hopefully you don't bother the other\n"
	.string "SIERRA about the release this much…$"

Route36_Text_RockSmashGuy_PostHM::
	.string "That HM happens to be ROCK SMASH.\n"
	.string "You can shatter rocks with just a\l"
	.string "single well-aimed smack.\p"
	.string "If any rocks are in your way, just\n"
	.string "smash 'em up!$"
