Route46_MapScripts:: @ 81F3DBC
	map_script 3, Route46_MapScript1_1F3DCC
	map_script 1, Route46_MapScript1_1F3DF3
	map_script 2, Route46_MapScript2_1F3E0A
	.byte 0

Route46_MapScript1_1F3DCC: @ 81F3DCC
	call GabbyAndTy_EventScript_UpdateLocation
	compare VAR_SHOULD_END_ABNORMAL_WEATHER, 1
	call_if_eq AbnormalWeather_EventScript_HideMapNamePopup
	compare VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_118_EAST
	call_if_eq AbnormalWeather_StartGroudonWeather
	compare VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_118_WEST
	call_if_eq AbnormalWeather_StartGroudonWeather
	end

Route46_MapScript1_1F3DF3: @ 81F3DF3
	compare VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_118_EAST
	call_if_eq AbnormalWeather_EventScript_PlaceTilesRoute46East
	compare VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_118_WEST
	call_if_eq AbnormalWeather_EventScript_PlaceTilesRoute46West
	end

Route46_MapScript2_1F3E0A: @ 81F3E0A
	map_script_2 VAR_SHOULD_END_ABNORMAL_WEATHER, 1, AbnormalWeather_EventScript_EndEventAndCleanup_1
	.2byte 0

Route46_EventScript_GoodRodFisherman:: @ 81F3E14
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_GOOD_ROD, Route46_EventScript_ReceivedGoodRod
	msgbox Route46_Text_YouAgreeGoodRodIsGood, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Route46_EventScript_ReceiveGoodRod
	compare VAR_RESULT, NO
	goto_if_eq Route46_EventScript_DeclineGoodRod
	end

Route46_EventScript_ReceiveGoodRod:: @ 81F3E3E
	msgbox Route46_Text_IdenticalMindsTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_GOOD_ROD
	setflag FLAG_RECEIVED_GOOD_ROD
	msgbox Route46_Text_TryYourLuckFishing, MSGBOX_DEFAULT
	release
	end

Route46_EventScript_DeclineGoodRod:: @ 81F3E5F
	msgbox Route46_Text_DontYouLikeToFish, MSGBOX_DEFAULT
	release
	end

Route46_EventScript_ReceivedGoodRod:: @ 81F3E69
	msgbox Route46_Text_TryCatchingMonWithGoodRod, MSGBOX_DEFAULT
	release
	end

Route46_EventScript_Girl:: @ 81F3E73
	msgbox Route46_Text_CanCrossRiversWithSurf, MSGBOX_NPC
	end

Route46_EventScript_RouteSign:: @ 81F3E7C
	msgbox Route46_Text_RouteSign, MSGBOX_SIGN
	end

Route46_EventScript_RouteSign119:: @ 81F3E85
	msgbox Route46_Text_RouteSign119, MSGBOX_SIGN
	end

Route46_EventScript_StevenTrigger0:: @ 81F3E8E
	lockall
	setvar VAR_0x8008, 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	applymovement 19, Route46_Movement_StevenApproachLedge0
	waitmovement 0
	goto Route46_EventScript_StevenTrigger
	end

Route46_EventScript_StevenTrigger1:: @ 81F3EAE
	lockall
	setvar VAR_0x8008, 1
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	goto Route46_EventScript_StevenTrigger
	end

Route46_EventScript_StevenTrigger2:: @ 81F3EC4
	lockall
	setvar VAR_0x8008, 2
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	applymovement 19, Route46_Movement_StevenApproachLedge2
	waitmovement 0
	goto Route46_EventScript_StevenTrigger
	end

Route46_EventScript_StevenTrigger:: @ 81F3EE4
	playse SE_LEDGE
	applymovement 19, Route46_Movement_StevenJumpLedge
	waitmovement 0
	delay 30
	msgbox Route46_Text_StevenQuestions, MSGBOX_DEFAULT
	closemessage
	compare VAR_0x8008, 0
	call_if_eq Route46_EventScript_StevenExit0
	compare VAR_0x8008, 1
	call_if_eq Route46_EventScript_StevenExit1
	compare VAR_0x8008, 2
	call_if_eq Route46_EventScript_StevenExit2
	setvar VAR_ROUTE46_STATE, 1
	removeobject 19
	releaseall
	end

Route46_EventScript_StevenExit0:: @ 81F3F28
	applymovement OBJ_EVENT_ID_PLAYER, Route46_Movement_PlayerWatchStevenExit
	applymovement 19, Route46_Movement_StevenExit0
	waitmovement 0
	return

Route46_EventScript_StevenExit1:: @ 81F3F3A
	applymovement OBJ_EVENT_ID_PLAYER, Route46_Movement_PlayerWatchStevenExit
	applymovement 19, Route46_Movement_StevenExit1
	waitmovement 0
	return

Route46_EventScript_StevenExit2:: @ 81F3F4C
	applymovement OBJ_EVENT_ID_PLAYER, Route46_Movement_PlayerWatchStevenExit
	applymovement 19, Route46_Movement_StevenExit2
	waitmovement 0
	return

Route46_Movement_PlayerWatchStevenExit: @ 81F3F5E
	delay_16
	walk_in_place_fastest_right
	step_end

Route46_Movement_StevenApproachLedge0: @ 81F3F61
	walk_left
	step_end

Route46_Movement_StevenApproachLedge2: @ 81F3F63
	walk_right
	step_end

Route46_Movement_StevenJumpLedge: @ 81F3F65
	jump_2_down
	delay_16
	walk_down
	step_end

Route46_Movement_StevenExit0: @ 81F3F69
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

Route46_Movement_StevenExit1: @ 81F3F74
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

Route46_Movement_StevenExit2: @ 81F3F7E
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

Route46_EventScript_Rose:: @ 81F3F87
	trainerbattle_single TRAINER_AMY_AND_MAY, Route46_Text_RoseIntro, Route46_Text_RoseDefeat, Route46_EventScript_RegisterRose
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq Route46_EventScript_RematchRose
	msgbox Route46_Text_RosePostBattle, MSGBOX_DEFAULT
	release
	end

Route46_EventScript_RegisterRose:: @ 81F3FB3
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route46_Text_RoseRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_AMY_AND_MAY
	release
	end

Route46_EventScript_RematchRose:: @ 81F3FD2
	trainerbattle_rematch TRAINER_AMY_AND_MAY, Route46_Text_RoseRematchIntro, Route46_Text_RoseRematchDefeat
	msgbox Route46_Text_RosePostRematch, MSGBOX_AUTOCLOSE
	end

Route46_EventScript_Barny:: @ 81F3FE9
	trainerbattle_single TRAINER_BARNY, Route46_Text_BarnyIntro, Route46_Text_BarnyDefeat
	msgbox Route46_Text_BarnyPostBattle, MSGBOX_AUTOCLOSE
	end

Route46_EventScript_Wade:: @ 81F4000
	trainerbattle_single TRAINER_WADE, Route46_Text_WadeIntro, Route46_Text_WadeDefeat
	msgbox Route46_Text_WadePostBattle, MSGBOX_AUTOCLOSE
	end

Route46_EventScript_Dalton:: @ 81F4017
	trainerbattle_single TRAINER_DALTON_1, Route46_Text_DaltonIntro, Route46_Text_DaltonDefeat, Route46_EventScript_RegisterDalton
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq Route46_EventScript_RematchDalton
	msgbox Route46_Text_DaltonPostBattle, MSGBOX_DEFAULT
	release
	end

Route46_EventScript_RegisterDalton:: @ 81F4043
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route46_Text_DaltonRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_DALTON_1
	release
	end

Route46_EventScript_RematchDalton:: @ 81F4062
	trainerbattle_rematch TRAINER_DALTON_1, Route46_Text_DaltonRematchIntro, Route46_Text_DaltonRematchDefeat
	msgbox Route46_Text_DaltonPostRematch, MSGBOX_AUTOCLOSE
	end

Route46_EventScript_Perry:: @ 81F4079
	trainerbattle_single TRAINER_PERRY, Route46_Text_PerryIntro, Route46_Text_PerryDefeat
	msgbox Route46_Text_PerryPostBattle, MSGBOX_AUTOCLOSE
	end

Route46_EventScript_Chester:: @ 81F4090
	trainerbattle_single TRAINER_CHESTER, Route46_Text_ChesterIntro, Route46_Text_ChesterDefeat
	msgbox Route46_Text_ChesterPostBattle, MSGBOX_AUTOCLOSE
	end

Route46_EventScript_Deandre:: @ 81F40A7
	trainerbattle_single TRAINER_DEANDRE, Route46_Text_DeandreIntro, Route46_Text_DeandreDefeat
	msgbox Route46_Text_DeandrePostBattle, MSGBOX_AUTOCLOSE
	end

Route46_Text_StevenQuestions: @ 81F40BE
	.string "STEVEN: Hi, {PLAYER}{KUN}!\p"
	.string "It's me, STEVEN!\n"
	.string "We met in the cave near DEWFORD.\p"
	.string "Have you met many kinds of POKéMON\n"
	.string "since I last saw you?\p"
	.string "There are many, many kinds of POKéMON\n"
	.string "in this wide world of ours.\p"
	.string "If you wanted to raise only your\n"
	.string "favorites, that's fine.\p"
	.string "Perhaps you find it more fun to raise\n"
	.string "all sorts of POKéMON.\p"
	.string "As a TRAINER of POKéMON,\n"
	.string "what do you think?\p"
	.string "Of course, it's not any of my business.\p"
	.string "It would be nice if we were to meet\n"
	.string "again somewhere.$"

Route46_Text_YouAgreeGoodRodIsGood: @ 81F427B
	.string "Hmm!\n"
	.string "A GOOD ROD is really good!\p"
	.string "Wouldn't you agree?$"

Route46_Text_IdenticalMindsTakeThis: @ 81F42AF
	.string "Hmm!\n"
	.string "We're of identical minds!\p"
	.string "Hmm!\n"
	.string "Take this GOOD ROD!$"

Route46_Text_TryYourLuckFishing: @ 81F42E7
	.string "Wherever there's water, try your luck\n"
	.string "at fishing.$"

Route46_Text_DontYouLikeToFish: @ 81F4319
	.string "Don't you like to fish?$"

Route46_Text_TryCatchingMonWithGoodRod: @ 81F4331
	.string "Try catching all sorts of POKéMON\n"
	.string "with your GOOD ROD.$"

Route46_Text_CanCrossRiversWithSurf: @ 81F4367
	.string "Even if there isn't a boat, you can\n"
	.string "cross rivers and the sea if you have\l"
	.string "a POKéMON that knows SURF.\p"
	.string "POKéMON can be counted on to do so\n"
	.string "much!$"

Route46_Text_RouteSign: @ 81F43F4
	.string "ROUTE 46\n"
	.string "MOUNTAIN ROAD AHEAD$"

Route46_Text_RouteSign119: @ 81F440E
	.string "ROUTE 118\n"
	.string "{UP_ARROW} ROUTE 119$"

