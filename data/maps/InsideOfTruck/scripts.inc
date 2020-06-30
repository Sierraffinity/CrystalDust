InsideOfTruck_MapScripts:: @ 823BEDA
	map_script MAP_SCRIPT_ON_LOAD, InsideOfTruck_OnLoad
	map_script MAP_SCRIPT_ON_RESUME, InsideOfTruck_OnResume
	.byte 0

InsideOfTruck_OnLoad: @ 823BEE5
	setmetatile 4, 1, METATILE_InsideOfTruck_ExitLight_Top, 0
	setmetatile 4, 2, METATILE_InsideOfTruck_ExitLight_Mid, 0
	setmetatile 4, 3, METATILE_InsideOfTruck_ExitLight_Bottom, 0
	end

InsideOfTruck_OnResume: @ 823BF01
	setstepcallback STEP_CB_TRUCK
	end

InsideOfTruck_EventScript_SetIntroFlags:: @ 823BF04
	lockall
	setflag FLAG_HIDE_MAP_NAME_POPUP
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq InsideOfTruck_EventScript_SetIntroFlagsMale
	compare VAR_RESULT, FEMALE
	goto_if_eq InsideOfTruck_EventScript_SetIntroFlagsFemale
	end

InsideOfTruck_EventScript_SetIntroFlagsMale:: @ 823BF20
	setrespawn HEAL_LOCATION_NEW_BARK_TOWN
	setvar VAR_LITTLEROOT_INTRO_STATE, 1
	setflag FLAG_HIDE_GOLDENROD_CITY_ROCKET_SCOUT
	setflag FLAG_HIDE_NEW_BARK_TOWN_MAYS_HOUSE_TRUCK
	setflag FLAG_HIDE_NEW_BARK_TOWN_PLAYERS_HOUSE_RIVAL_MOM
	setflag FLAG_HIDE_RUINS_OF_ALPH_OUTSIDE_COWARD
	setflag FLAG_HIDE_NEW_BARK_TOWN_PLAYERS_HOUSE_2F_POKE_BALL
	setvar VAR_KURT_GIVEN_APRICORN, 1
	setdynamicwarp MAP_NEW_BARK_TOWN, 255, 3, 10
	releaseall
	end

InsideOfTruck_EventScript_SetIntroFlagsFemale:: @ 823BF46
	setrespawn HEAL_LOCATION_NEW_BARK_TOWN
	setvar VAR_LITTLEROOT_INTRO_STATE, 2
	setflag FLAG_HIDE_GOLDENROD_CITY_CIVILIANS
	setflag FLAG_HIDE_GOLDENROD_CITY_MOVE_TUTOR
	setflag FLAG_HIDE_NEW_BARK_TOWN_MAYS_HOUSE_RIVAL_MOM
	setflag FLAG_HIDE_RUINS_OF_ALPH_OUTSIDE_YOUNGSTERS
	setflag FLAG_HIDE_NEW_BARK_TOWN_OTHER_HOUSE_POKE_BALL
	setvar VAR_PLAYER_HOUSE_STATE, 1
	setdynamicwarp MAP_NEW_BARK_TOWN, 255, 12, 10
	releaseall
	end

InsideOfTruck_EventScript_MovingBox:: @ 823BF6C
	msgbox InsideOfTruck_Text_BoxPrintedWithMonLogo, MSGBOX_SIGN
	end

InsideOfTruck_Text_BoxPrintedWithMonLogo: @ 823BF75
	.string "The box is printed with a POKéMON logo.\p"
	.string "It's a POKéMON brand moving and\n"
	.string "delivery service.$"

