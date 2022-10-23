#include "constants/global.h"
#include "constants/apprentice.h"
#include "constants/battle.h"
#include "constants/battle_arena.h"
#include "constants/battle_dome.h"
#include "constants/battle_factory.h"
#include "constants/battle_frontier.h"
#include "constants/battle_palace.h"
#include "constants/battle_pike.h"
#include "constants/battle_pyramid.h"
#include "constants/battle_setup.h"
#include "constants/battle_tent.h"
#include "constants/battle_tower.h"
#include "constants/berry.h"
#include "constants/cable_club.h"
#include "constants/coins.h"
#include "constants/contest.h"
#include "constants/daycare.h"
#include "constants/day_night.h"
#include "constants/decorations.h"
#include "constants/easy_chat.h"
#include "constants/event_objects.h"
#include "constants/event_object_movement.h"
#include "constants/field_effects.h"
#include "constants/field_poison.h"
#include "constants/field_specials.h"
#include "constants/field_tasks.h"
#include "constants/field_weather.h"
#include "constants/flags.h"
#include "constants/frontier_util.h"
#include "constants/fruit_trees.h"
#include "constants/game_stat.h"
#include "constants/item.h"
#include "constants/items.h"
#include "constants/heal_locations.h"
#include "constants/layouts.h"
#include "constants/lilycove_lady.h"
#include "constants/map_scripts.h"
#include "constants/maps.h"
#include "constants/mauville_old_man.h"
#include "constants/metatile_labels.h"
#include "constants/moves.h"
#include "constants/party_menu.h"
#include "constants/phone_contact.h"
#include "constants/pokemon.h"
#include "constants/radio.h"
#include "constants/room_decor.h"
#include "constants/roulette.h"
#include "constants/script_menu.h"
#include "constants/secret_bases.h"
#include "constants/songs.h"
#include "constants/species.h"
#include "constants/trade.h"
#include "constants/trainer_hill.h"
#include "constants/trainers.h"
#include "constants/text.h"
#include "constants/tv.h"
#include "constants/union_room.h"
#include "constants/vars.h"
#include "constants/weather.h"
	.include "asm/macros.inc"
	.include "asm/macros/event.inc"
	.include "constants/constants.inc"

	.section script_data, "aw", %progbits

@ 81DB67C
	.include "data/script_cmd_table.inc"

gSpecialVars::
	.4byte gSpecialVar_0x8000
	.4byte gSpecialVar_0x8001
	.4byte gSpecialVar_0x8002
	.4byte gSpecialVar_0x8003
	.4byte gSpecialVar_0x8004
	.4byte gSpecialVar_0x8005
	.4byte gSpecialVar_0x8006
	.4byte gSpecialVar_0x8007
	.4byte gSpecialVar_0x8008
	.4byte gSpecialVar_0x8009
	.4byte gSpecialVar_0x800A
	.4byte gSpecialVar_0x800B
	.4byte gSpecialVar_Facing
	.4byte gSpecialVar_Result
	.4byte gSpecialVar_ItemId
	.4byte gSpecialVar_LastTalked
	.4byte gSpecialVar_ContestRank
	.4byte gSpecialVar_ContestCategory
	.4byte gSpecialVar_MonBoxId
	.4byte gSpecialVar_MonBoxPos
	.4byte gSpecialVar_TextColor
	.4byte gSpecialVar_TextColorBackup
	.4byte gSpecialVar_Unused_0x8014
	.4byte gTrainerBattleOpponent_A

	.include "data/specials.inc"

gStdScripts::
	.4byte Std_ObtainItem              @ STD_OBTAIN_ITEM
	.4byte Std_FindItem                @ STD_FIND_ITEM
	.4byte Std_MsgboxNPC               @ MSGBOX_NPC
	.4byte Std_MsgboxSign              @ MSGBOX_SIGN
	.4byte Std_MsgboxDefault           @ MSGBOX_DEFAULT
	.4byte Std_MsgboxYesNo             @ MSGBOX_YESNO
	.4byte Std_MsgboxAutoclose         @ MSGBOX_AUTOCLOSE
	.4byte Std_ObtainDecoration        @ STD_OBTAIN_DECORATION
	.4byte Std_RegisteredInMatchCall   @ STD_REGISTER_MATCH_CALL
	.4byte Std_MsgboxGetPoints         @ MSGBOX_GETPOINTS
	.4byte Std_MsgboxContinue		   @ MSGBOX_CONTINUE
	.4byte Std_PutItemAway			   @ STD_PUT_ITEM_AWAY
	.4byte Std_ReceivedItem			   @ STD_RECEIVED_ITEM
	.4byte Std_MsgboxContinue		   @ MSGBOX_CONTINUE
	.4byte Std_10
gStdScripts_End::

	.include "data/maps/VioletCity/scripts.inc"
	.include "data/maps/GoldenrodCity/scripts.inc"
	.include "data/maps/NewBarkTown/scripts.inc"
	.include "data/maps/CherrygroveCity/scripts.inc"
	.include "data/maps/AzaleaTown/scripts.inc"
	.include "data/maps/Route29/scripts.inc"
	.include "data/maps/Route30/scripts.inc"
	.include "data/maps/Route31/scripts.inc"
	.include "data/maps/Route32/scripts.inc"
	.include "data/maps/Route33/scripts.inc"
	.include "data/maps/Route34/scripts.inc"
	.include "data/maps/Route35/scripts.inc"
	.include "data/maps/Route36/scripts.inc"
	.include "data/maps/Route45/scripts.inc"
	.include "data/maps/Route46/scripts.inc"
	.include "data/maps/NewBarkTown_PlayersHouse_1F/scripts.inc"
	.include "data/maps/NewBarkTown_PlayersHouse_2F/scripts.inc"
	.include "data/maps/NewBarkTown_ElmsHouse/scripts.inc"
	.include "data/maps/NewBarkTown_NeighborsHouse/scripts.inc"
	.include "data/maps/NewBarkTown_ProfessorElmsLab/scripts.inc"
	.include "data/maps/CherrygroveCity_House1/scripts.inc"
	.include "data/maps/CherrygroveCity_House2/scripts.inc"
	.include "data/maps/CherrygroveCity_GuideGentsHouse/scripts.inc"
	.include "data/maps/CherrygroveCity_PokemonCenter_1F/scripts.inc"
	.include "data/maps/CherrygroveCity_PokemonCenter_2F/scripts.inc"
	.include "data/maps/CherrygroveCity_Mart/scripts.inc"
	.include "data/maps/AzaleaTown_KurtsHouse/scripts.inc"
	.include "data/maps/AzaleaTown_PokemonCenter_1F/scripts.inc"
	.include "data/maps/AzaleaTown_PokemonCenter_2F/scripts.inc"
	.include "data/maps/AzaleaTown_Gym/scripts.inc"
	.include "data/maps/AzaleaTown_Mart/scripts.inc"
	.include "data/maps/AzaleaTown_CharcoalKiln/scripts.inc"
	.include "data/maps/FallarborTown_BattleTentLobby/scripts.inc"
	.include "data/maps/FallarborTown_BattleTentCorridor/scripts.inc"
	.include "data/maps/FallarborTown_BattleTentBattleRoom/scripts.inc"
	.include "data/maps/VerdanturfTown_BattleTentLobby/scripts.inc"
	.include "data/maps/VerdanturfTown_BattleTentCorridor/scripts.inc"
	.include "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.inc"
	.include "data/maps/VioletCity_EarlsAcademy/scripts.inc"
	.include "data/maps/VioletCity_Gym/scripts.inc"
	.include "data/maps/VioletCity_House1/scripts.inc"
	.include "data/maps/VioletCity_House2/scripts.inc"
	.include "data/maps/VioletCity_PokemonCenter_1F/scripts.inc"
	.include "data/maps/VioletCity_PokemonCenter_2F/scripts.inc"
	.include "data/maps/VioletCity_Mart/scripts.inc"
	.include "data/maps/GoldenrodCity_Underground_NorthEntrance/scripts.inc"
	.include "data/maps/GoldenrodCity_Underground_SouthEntrance/scripts.inc"
	.include "data/maps/GoldenrodCity_Underground/scripts.inc"
	.include "data/maps/GoldenrodCity_Gym/scripts.inc"
	.include "data/maps/GoldenrodCity_PokecomCenterAdminRoom/scripts.inc"
	.include "data/maps/GoldenrodCity_PokemonCenter_1F/scripts.inc"
	.include "data/maps/GoldenrodCity_PokemonCenter_2F/scripts.inc"
	.include "data/maps/GoldenrodCity_MagnetTrainStation/scripts.inc"
	.include "data/maps/GoldenrodCity_GameCorner/scripts.inc"
	.include "data/maps/GoldenrodCity_BikeShop/scripts.inc"
	.include "data/maps/GoldenrodCity_FlowerShop/scripts.inc"
	.include "data/maps/GoldenrodCity_NameRatersHouse/scripts.inc"
	.include "data/maps/GoldenrodCity_BillsFamilysHouse/scripts.inc"
	.include "data/maps/GoldenrodCity_House1/scripts.inc"
	.include "data/maps/GoldenrodCity_House2/scripts.inc"
	.include "data/maps/GoldenrodCity_DeptStore_1F/scripts.inc"
	.include "data/maps/GoldenrodCity_DeptStore_2F/scripts.inc"
	.include "data/maps/LilycoveCity_ContestLobby/scripts.inc"
	.include "data/maps/LilycoveCity_ContestHall/scripts.inc"
	.include "data/maps/Route29_Gatehouse/scripts.inc"
	.include "data/maps/Route30_BerryMansHouse/scripts.inc"
	.include "data/maps/Route30_MrPokemonsHouse/scripts.inc"
	.include "data/maps/Route31_Gatehouse/scripts.inc"
	.include "data/maps/Route32_Gatehouse/scripts.inc"
	.include "data/maps/Route32_PokemonCenter_1F/scripts.inc"
	.include "data/maps/Route32_PokemonCenter_2F/scripts.inc"
	.include "data/maps/Route34_IlexEastGatehouse/scripts.inc"
	.include "data/maps/Route34_IlexNorthGatehouse/scripts.inc"
	.include "data/maps/Route34_DayCare/scripts.inc"
	.include "data/maps/Route35_GoldenrodGatehouse/scripts.inc"
	.include "data/maps/Route35_NationalParkGatehouse/scripts.inc"
	.include "data/maps/Route36_RuinsOfAlphGatehouse/scripts.inc"
	.include "data/maps/RadioTower_1F/scripts.inc"
	.include "data/maps/RadioTower_2F/scripts.inc"
	.include "data/maps/RadioTower_3F/scripts.inc"
	.include "data/maps/RadioTower_4F/scripts.inc"
	.include "data/maps/AlteringCave/scripts.inc"
	.include "data/maps/UnionCave_1F/scripts.inc"
	.include "data/maps/UnionCave_B1F/scripts.inc"
	.include "data/maps/UnionCave_B2F/scripts.inc"
	.include "data/maps/DarkCave_South/scripts.inc"
	.include "data/maps/DarkCave_B1F/scripts.inc"
	.include "data/maps/IlexForest/scripts.inc"
	.include "data/maps/SlowpokeWell_B1F/scripts.inc"
	.include "data/maps/SproutTower_1F/scripts.inc"
	.include "data/maps/SproutTower_2F/scripts.inc"
	.include "data/maps/SproutTower_3F/scripts.inc"
	.include "data/maps/RuinsOfAlph_Outside/scripts.inc"
	.include "data/maps/RuinsOfAlph_ResearchCenter/scripts.inc"
	.include "data/maps/RuinsOfAlph_InnerChamber/scripts.inc"
	.include "data/maps/RuinsOfAlph_KabutoChamber/scripts.inc"
	.include "data/maps/RuinsOfAlph_OmanyteChamber/scripts.inc"
	.include "data/maps/RuinsOfAlph_AerodactylChamber/scripts.inc"
	.include "data/maps/RuinsOfAlph_HoOhChamber/scripts.inc"
	.include "data/maps/RuinsOfAlph_KabutoItemRoom/scripts.inc"
	.include "data/maps/RuinsOfAlph_OmanyteItemRoom/scripts.inc"
	.include "data/maps/RuinsOfAlph_AerodactylItemRoom/scripts.inc"
	.include "data/maps/RuinsOfAlph_HoOhItemRoom/scripts.inc"
	.include "data/maps/RuinsOfAlph_KabutoWordRoom/scripts.inc"
	.include "data/maps/RadioTower_5F/scripts.inc"
	.include "data/scripts/shared_secret_base.inc"
	.include "data/maps/BattleColosseum_2P/scripts.inc"
	.include "data/maps/TradeCenter/scripts.inc"
	.include "data/maps/RecordCorner/scripts.inc"
	.include "data/maps/BattleColosseum_4P/scripts.inc"
	.include "data/maps/ContestHall/scripts.inc"
	.include "data/maps/BattlePyramidSquare01/scripts.inc"
	.include "data/maps/UnionRoom/scripts.inc"
	.include "data/maps/BattleFrontier_OutsideWest/scripts.inc"
	.include "data/maps/BattleFrontier_BattleTowerLobby/scripts.inc"
	.include "data/maps/BattleFrontier_BattleTowerElevator/scripts.inc"
	.include "data/maps/BattleFrontier_BattleTowerCorridor/scripts.inc"
	.include "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.inc"
	.include "data/maps/SouthernIsland_Exterior/scripts.inc"
	.include "data/maps/SouthernIsland_Interior/scripts.inc"
	.include "data/maps/BattleFrontier_OutsideEast/scripts.inc"
	.include "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.inc"
	.include "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.inc"
	.include "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.inc"
	.include "data/maps/BattleFrontier_BattleDomeLobby/scripts.inc"
	.include "data/maps/BattleFrontier_BattleDomeCorridor/scripts.inc"
	.include "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.inc"
	.include "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.inc"
	.include "data/maps/BattleFrontier_BattlePalaceLobby/scripts.inc"
	.include "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.inc"
	.include "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.inc"
	.include "data/maps/BattleFrontier_BattlePyramidLobby/scripts.inc"
	.include "data/maps/BattleFrontier_BattlePyramidFloor/scripts.inc"
	.include "data/maps/BattleFrontier_BattlePyramidTop/scripts.inc"
	.include "data/maps/BattleFrontier_BattleArenaLobby/scripts.inc"
	.include "data/maps/BattleFrontier_BattleArenaCorridor/scripts.inc"
	.include "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.inc"
	.include "data/maps/BattleFrontier_BattleFactoryLobby/scripts.inc"
	.include "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.inc"
	.include "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.inc"
	.include "data/maps/BattleFrontier_BattlePikeLobby/scripts.inc"
	.include "data/maps/BattleFrontier_BattlePikeCorridor/scripts.inc"
	.include "data/maps/BattleFrontier_BattlePikeThreePathRoom/scripts.inc"
	.include "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.inc"
	.include "data/maps/BattleFrontier_BattlePikeRoomFinal/scripts.inc"
	.include "data/maps/BattleFrontier_BattlePikeRoomWildMons/scripts.inc"
	.include "data/maps/BattleFrontier_RankingHall/scripts.inc"
	.include "data/maps/BattleFrontier_Lounge1/scripts.inc"
	.include "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.inc"
	.include "data/maps/BattleFrontier_Lounge2/scripts.inc"
	.include "data/maps/BattleFrontier_Lounge3/scripts.inc"
	.include "data/maps/BattleFrontier_Lounge4/scripts.inc"
	.include "data/maps/BattleFrontier_ScottsHouse/scripts.inc"
	.include "data/maps/BattleFrontier_Lounge5/scripts.inc"
	.include "data/maps/BattleFrontier_Lounge6/scripts.inc"
	.include "data/maps/BattleFrontier_Lounge7/scripts.inc"
	.include "data/maps/BattleFrontier_ReceptionGate/scripts.inc"
	.include "data/maps/BattleFrontier_Lounge8/scripts.inc"
	.include "data/maps/BattleFrontier_Lounge9/scripts.inc"
	.include "data/maps/BattleFrontier_PokemonCenter_1F/scripts.inc"
	.include "data/maps/BattleFrontier_PokemonCenter_2F/scripts.inc"
	.include "data/maps/BattleFrontier_Mart/scripts.inc"
	.include "data/maps/FarawayIsland_Entrance/scripts.inc"
	.include "data/maps/FarawayIsland_Interior/scripts.inc"
	.include "data/maps/BirthIsland_Exterior/scripts.inc"
	.include "data/maps/BirthIsland_Harbor/scripts.inc"
	.include "data/maps/TrainerHill_Entrance/scripts.inc"
	.include "data/maps/TrainerHill_1F/scripts.inc"
	.include "data/maps/TrainerHill_2F/scripts.inc"
	.include "data/maps/TrainerHill_3F/scripts.inc"
	.include "data/maps/TrainerHill_4F/scripts.inc"
	.include "data/maps/TrainerHill_Roof/scripts.inc"
	.include "data/maps/NavelRock_Exterior/scripts.inc"
	.include "data/maps/NavelRock_Harbor/scripts.inc"
	.include "data/maps/NavelRock_Entrance/scripts.inc"
	.include "data/maps/NavelRock_B1F/scripts.inc"
	.include "data/maps/NavelRock_Fork/scripts.inc"
	.include "data/maps/NavelRock_Up1/scripts.inc"
	.include "data/maps/NavelRock_Up2/scripts.inc"
	.include "data/maps/NavelRock_Up3/scripts.inc"
	.include "data/maps/NavelRock_Up4/scripts.inc"
	.include "data/maps/NavelRock_Top/scripts.inc"
	.include "data/maps/NavelRock_Down01/scripts.inc"
	.include "data/maps/NavelRock_Down02/scripts.inc"
	.include "data/maps/NavelRock_Down03/scripts.inc"
	.include "data/maps/NavelRock_Down04/scripts.inc"
	.include "data/maps/NavelRock_Down05/scripts.inc"
	.include "data/maps/NavelRock_Down06/scripts.inc"
	.include "data/maps/NavelRock_Down07/scripts.inc"
	.include "data/maps/NavelRock_Down08/scripts.inc"
	.include "data/maps/NavelRock_Down09/scripts.inc"
	.include "data/maps/NavelRock_Down10/scripts.inc"
	.include "data/maps/NavelRock_Down11/scripts.inc"
	.include "data/maps/NavelRock_Bottom/scripts.inc"
	.include "data/maps/TrainerHill_Elevator/scripts.inc"
	.include "data/maps/NationalPark_BugCatchingContest/scripts.inc"
	.include "data/maps/NationalPark/scripts.inc"
	.include "data/maps/Route36_NationalParkGatehouse/scripts.inc"
	.include "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.inc"
	.include "data/maps/SootopolisCity_MysteryEventsHouse_B1F/scripts.inc"
	.include "data/maps/ArtisanCave_B1F/scripts.inc"
	.include "data/maps/ArtisanCave_1F/scripts.inc"
	.include "data/maps/MossdeepCity_GameCorner_1F/scripts.inc"
	.include "data/maps/MossdeepCity_GameCorner_B1F/scripts.inc"
	.include "data/maps/SlateportCity_BattleTentLobby/scripts.inc"
	.include "data/maps/SlateportCity_BattleTentCorridor/scripts.inc"
	.include "data/maps/SlateportCity_BattleTentBattleRoom/scripts.inc"

	.include "data/scripts/std_msgbox.inc"
	.include "data/scripts/trainer_battle.inc"
	.include "data/scripts/new_game.inc"

ClearPokepicAndTextboxForEarlyScriptExit::
	special PrintNullStringAndClearPokemonPicWindow
	release
	end

EventScript_WhiteOut::
	call EverGrandeCity_HallOfFame_EventScript_ResetEliteFour
	end

EverGrandeCity_HallOfFame_EventScript_ResetEliteFour::
	clearflag FLAG_DEFEATED_ELITE_4_SIDNEY
	clearflag FLAG_DEFEATED_ELITE_4_PHOEBE
	clearflag FLAG_DEFEATED_ELITE_4_GLACIA
	clearflag FLAG_DEFEATED_ELITE_4_DRAKE
	setvar VAR_ELITE_4_STATE, 0
	return

Common_EventScript_UpdateBrineyLocation:: @ 82718DE
	@goto_if_unset FLAG_MET_FLORIA_ROUTE_36, Common_EventScript_NopReturn
	@goto_if_set FLAG_DEFEATED_PETALBURG_GYM, Common_EventScript_NopReturn
	@goto_if_unset FLAG_HIDE_ROUTE_32_MR_BRINEY_BOAT, EventScript_SetBrineyLocation_House
	@goto_if_unset FLAG_HIDE_ROUTE_32_SLOWPOKE_MAN, EventScript_SetBrineyLocation_Dewford
	@goto_if_unset FLAG_HIDE_ROUTE_32_FRIEDA, EventScript_SetBrineyLocation_Route36
	return

EventScript_SetBrineyLocation_House::
	setvar VAR_BRINEY_LOCATION, 1
	return

EventScript_SetBrineyLocation_Dewford::
	setvar VAR_BRINEY_LOCATION, 2
	return

EventScript_SetBrineyLocation_Route36:: @ 8271918
	setvar VAR_BRINEY_LOCATION, 3
	return

	.include "data/scripts/pkmn_center_nurse.inc"
	.include "data/scripts/obtain_item.inc"
	.include "data/scripts/record_mix.inc"
	.include "data/scripts/pc.inc"

@ scripts/notices.inc? signs.inc? See comment about text/notices.inc
Common_EventScript_ShowPokemartSign::
	msgbox gText_PokemartSign, MSGBOX_SIGN
	end

Common_EventScript_ShowPokemonCenterSign::
	msgbox gText_PokemonCenterSign, MSGBOX_SIGN
	end

Common_ShowEasyChatScreen::
	fadescreen FADE_TO_BLACK
	special ShowEasyChatScreen
	fadescreen FADE_FROM_BLACK
	return

Common_EventScript_BufferTrendyPhrase::
	dotimebasedevents
	setvar VAR_0x8004, 0
	special BufferTrendyPhraseString
	return

EventScript_BackupMrBrineyLocation::
	copyvar VAR_0x8008, VAR_BRINEY_LOCATION
	setvar VAR_BRINEY_LOCATION, 0
	return

	.include "data/scripts/surf.inc"
	.include "data/scripts/rival_graphics.inc"
	.include "data/scripts/set_gym_trainers.inc"

Common_EventScript_ShowBagIsFull::
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
	release
	end

Common_EventScript_BagIsFull::
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
	return

Common_EventScript_ShowNoRoomForDecor::
	msgbox gText_NoRoomLeftForAnother, MSGBOX_DEFAULT
	release
	end

Common_EventScript_NoRoomForDecor::
	msgbox gText_NoRoomLeftForAnother, MSGBOX_DEFAULT
	return

Common_EventScript_SetAbnormalWeather::
	setweather WEATHER_ABNORMAL
	return

Common_EventScript_PlayGymBadgeFanfare::
	playfanfare MUS_OBTAIN_BADGE
	waitfanfare
	return

Common_EventScript_OutOfCenterPartyHeal::
	fadescreen FADE_TO_BLACK
	playfanfare MUS_HEAL
	waitfanfare
	special HealPlayerParty
	fadescreen FADE_FROM_BLACK
	return

EventScript_RegionMap::
	lockall
	msgbox Common_Text_LookCloserAtMap, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	special FieldShowRegionMap
	waitstate
	releaseall
	end

Common_EventScript_PlayBrineysBoatMusic::
	setflag FLAG_DONT_TRANSITION_MUSIC
	playbgm MUS_SAILING, FALSE
	return

Common_EventScript_StopBrineysBoatMusic::
	clearflag FLAG_DONT_TRANSITION_MUSIC
	fadedefaultbgm
	return

	.include "data/scripts/pokedex_rating.inc"

@ Below could be split as ferry.inc aside from the Rusturf tunnel script
Common_EventScript_FerryDepart::
	delay 60
	applymovement VAR_0x8004, Movement_FerryDepart
	waitmovement 0
	return

Movement_FerryDepart:
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

EventScript_HideMrBriney::
	return

UnionCave_1F_EventScript_SetUnionCave_1FOpen::
	removeobject 1
	removeobject 10
	@clearflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WANDAS_BOYFRIEND
	@clearflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WANDA
	@setvar VAR_UNION_CAVE_STATE, 6
	@setflag FLAG_IN_BUG_CATCHING_CONTEST
	return

EventScript_UnusedBoardFerry::
	delay 30
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	showobjectat OBJ_EVENT_ID_PLAYER, 0
	delay 30
	applymovement OBJ_EVENT_ID_PLAYER, Movement_UnusedBoardFerry
	waitmovement 0
	delay 30
	return

Movement_UnusedBoardFerry:
	walk_up
	step_end

Common_EventScript_FerryDepartIsland::
	compare VAR_FACING, DIR_SOUTH
	call_if_eq Ferry_EventScript_DepartIslandSouth
	compare VAR_FACING, DIR_WEST
	call_if_eq Ferry_EventScript_DepartIslandWest
	delay 30
	hideobjectat OBJ_EVENT_ID_PLAYER, 0
	call Common_EventScript_FerryDepart
	return

	.include "data/scripts/cave_of_origin.inc"

Common_EventScript_NameReceivedPartyMon::
	fadescreen FADE_TO_BLACK
	special ChangePokemonNickname
	waitstate
	return

Common_EventScript_PlayerHandedOverTheItem::
	bufferitemname 0, VAR_0x8004
	playfanfare MUS_OBTAIN_TMHM
	message gText_PlayerHandedOverTheItem
	waitmessage
	waitfanfare
	removeitem VAR_0x8004
	return

	.include "data/scripts/elite_four.inc"
	.include "data/scripts/movement.inc"
	.include "data/scripts/check_furniture.inc"
	.include "data/text/record_mix.inc"
	.include "data/text/pc.inc"
	.include "data/text/pkmn_center_nurse.inc"
	.include "data/text/mart_clerk.inc"
	.include "data/text/obtain_item.inc"

@ The below and surf.inc could be split into some text/notices.inc
gText_PokemartSign::
	.string "For All Your {POKEMON} Needs\n"
	.string "{POKEMON} MART$"

gText_PokemonCenterSign::
	.string "Heal Your {POKEMON}!\n"
	.string "{POKEMON} CENTER$"

gText_MomOrDadMightLikeThisProgram::
	.string "{STR_VAR_1} might like this program.\n"
	.string "… … … … … … … … … … … … … … … …\p"
	.string "Better get going!$"

gText_WhichFloorWouldYouLike::
	.string "Welcome to LILYCOVE DEPARTMENT STORE.\p"
	.string "Which floor would you like?$"

gText_SandstormIsVicious::
	.string "The sandstorm is vicious.\n"
	.string "It's impossible to keep going.$"

gText_SelectWithoutRegisteredItem::
	.string "An item in the BAG can be\n"
	.string "registered to SELECT for easy use.$"

gText_PokemonTrainerSchoolEmail::
	.string "There's an e-mail from {POKEMON} TRAINER\n"
	.string "SCHOOL.\p"
	.string "… … … … … …\p"
	.string "A {POKEMON} may learn up to four moves.\p"
	.string "A TRAINER's expertise is tested on the\n"
	.string "move sets chosen for {POKEMON}.\p"
	.string "… … … … … …$"

gText_PlayerHouseBootPC::
	.string "{PLAYER} booted up the PC.$"

gText_PokeblockLinkCanceled::
	.string "The link was canceled.$"

gText_UnusedNicknameReceivedPokemon::
	.string "Want to give a nickname to\n"
	.string "the {STR_VAR_2} you received?$"

gText_WhitedOutLostMoney::
	.string "{PLAYER} is out of usable\n"
	.string "{POKEMON}!\p"
	.string "{PLAYER} panicked and lost ¥{STR_VAR_1}…\p"
	.string "… … … …\p"
	.string "{PLAYER} whited out!$"

gText_PlayerWhitedOut::
	.string "{PLAYER} is out of usable\n"
	.string "{POKEMON}!\p"
	.string "{PLAYER} whited out!$"

gText_RegisteredTrainerinPokeNav::
	.string "Registered {STR_VAR_1} {STR_VAR_2}\n"
	.string "in the {POKE}NAV.$"

gText_ComeBackWithSecretPower::
	.string "Do you know the TM SECRET POWER?\p"
	.string "Our group, we love the TM SECRET\n"
	.string "POWER.\p"
	.string "One of our members will give it to you.\n"
	.string "Come back and show me if you get it.\p"
	.string "We'll accept you as a member and sell\n"
	.string "you good stuff in secrecy.$"

gText_PokerusExplanation::
	.string "Your {POKEMON} may be infected with\n"
	.string "{POKE}RUS.\p"
	.string "Little is known about the {POKE}RUS\n"
	.string "except that they are microscopic life-\l"
	.string "forms that attach to {POKEMON}.\p"
	.string "While infected, {POKEMON} are said to\n"
	.string "grow exceptionally well.$"

	.include "data/text/surf.inc"

gText_DoorOpenedFarAway::
	.string "It sounded as if a door opened\n"
	.string "somewhere far away.$"

gText_BigHoleInTheWall::
	.string "There is a big hole in the wall.$"

gText_SorryWirelessClubAdjustments::
	.string "I'm terribly sorry.\n"
	.string "The {POKEMON} WIRELESS CLUB is\l"
	.string "undergoing adjustments now.$"

gText_UndergoingAdjustments::
	.string "It appears to be undergoing\n"
	.string "adjustments…$"

@ Unused
gText_SorryTradeCenterInspections::
	.string "I'm terribly sorry. The TRADE CENTER\n"
	.string "is undergoing inspections.$"

@ Unused
gText_SorryRecordCornerPreparation::
	.string "I'm terribly sorry. The RECORD CORNER\n"
	.string "is under preparation.$"

gText_PlayerHandedOverTheItem::
	.string "{PLAYER} handed over the\n"
	.string "{STR_VAR_1}.$"

	.string "Accessed PROF. OAK's PC…\p"
	.string "Accessed the {POKEDEX} Rating\n"
	.string "System…$"

gText_AccessedProfOaksPC:: @ 81A5BC6
	.string "Accessed PROF. OAK's PC…\p"
	.string "Accessed the {POKEDEX} Rating\n"
	.string "System…$"

gText_HavePokedexRated::
	.string "Would you like to have your\n"
	.string "{POKEDEX} rated?$"

gText_ClosedLinkToProfOaksPC::
	.string "Closed link to PROF. OAK's PC.$"

gText_ThankYouForAccessingMysteryGift::
	.string "Thank you for accessing the\n"
	.string "{PLAYER} found one {STR_VAR_1}\n"
	.string "{STR_VAR_2}!$"

gText_PlayerFoundOneTMHM::
	.string "{PLAYER} found one {STR_VAR_1}\n"
	.string "{STR_VAR_2}!$"

gText_Sudowoodo_Attacked::
	.string "The weird tree doesn't like the\n"
	.string "WAILMER PAIL!\p"
	.string "The weird tree attacked!$"

gText_LegendaryFlewAway::
	.string "The {STR_VAR_1} flew away!$"

	.include "data/text/pc_transfer.inc"
	.include "data/text/mevent.inc"
	.include "data/text/abnormal_weather.inc"

EventScript_SelectWithoutRegisteredItem::
	msgbox gText_SelectWithoutRegisteredItem, MSGBOX_SIGN
	end

	.include "data/scripts/field_poison.inc"

Common_EventScript_NopReturn::
	return

@ Unused
EventScript_CableClub_SetVarResult1::
	setvar VAR_RESULT, 1
	return

EventScript_CableClub_SetVarResult0::
	setvar VAR_RESULT, 0
	return

Common_EventScript_UnionRoomAttendant::
	call CableClub_EventScript_UnionRoomAttendant
	end

Common_EventScript_WirelessClubAttendant::
	call CableClub_EventScript_WirelessClubAttendant
	end

Common_EventScript_DirectCornerAttendant::
	call CableClub_EventScript_DirectCornerAttendant
	end

Common_EventScript_RemoveStaticPokemon::
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject VAR_LAST_TALKED
	fadescreenswapbuffers FADE_FROM_BLACK
	return

Common_EventScript_LegendaryFlewAway::
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject VAR_LAST_TALKED
	fadescreenswapbuffers FADE_FROM_BLACK
	bufferspeciesname 0, VAR_0x8004
	msgbox gText_LegendaryFlewAway, MSGBOX_DEFAULT
	release
	end

EventScript_ElevatorButton::
    delay 15
    playse SE_DING_DONG
    waitse
	end

	.include "data/scripts/pc_transfer.inc"
	.include "data/scripts/mevent.inc"
	.include "data/scripts/trainer_script.inc"
	.include "data/scripts/berry_tree.inc"
	.include "data/scripts/secret_base.inc"
	.include "data/scripts/cable_club.inc"
	.include "data/text/cable_club.inc"
	.include "data/scripts/contest_hall.inc"
	.include "data/text/contest_strings.inc"
	.include "data/text/contest_link.inc"
	.include "data/text/contest_painting.inc"
	.include "data/text/trick_house_mechadolls.inc"
	.include "data/text/tv.inc"
	.include "data/scripts/interview.inc"
	.include "data/text/pokemon_news.inc"
	.include "data/scripts/mauville_man.inc"
	.include "data/scripts/field_move_scripts.inc"

Common_EventScript_FindItem::
	callnative GetObjectEventTrainerRangeFromTemplate
	finditem VAR_RESULT
	end

	.include "data/scripts/mystery_event_club.inc"
	.include "data/scripts/day_care.inc"
	.include "data/scripts/flash.inc"
	.include "data/scripts/berry_blender.inc"
	.include "data/text/mauville_man.inc"
	.include "data/scripts/repel.inc"
	.include "data/scripts/safari_zone.inc"
	.include "data/scripts/bug_catching_contest.inc"
	.include "data/scripts/roulette.inc"
	.include "data/text/pokedex_rating.inc"
	.include "data/text/lottery_corner.inc"
	.include "data/text/event_ticket_1.inc"
	.include "data/text/shoal_cave.inc"
	.include "data/text/check_furniture.inc"
	.include "data/scripts/cave_hole.inc"
	.include "data/scripts/lilycove_lady.inc"
	.include "data/text/match_call.inc"
	.include "data/scripts/apprentice.inc"
	.include "data/text/apprentice.inc"
	.include "data/text/battle_dome.inc"
	.include "data/scripts/battle_pike.inc"
	.include "data/text/blend_master.inc"
	.include "data/text/battle_tent.inc"
	.include "data/text/event_ticket_2.inc"
	.include "data/scripts/move_tutors.inc"
	.include "data/scripts/trainer_hill.inc"
	.include "data/scripts/test_signpost.inc"
	.include "data/text/frontier_brain.inc"
	.include "data/text/save.inc"
	.include "data/text/oak_speech.inc"

	.include "data/maps/GoldenrodCity_DeptStore_3F/scripts.inc"
	.include "data/maps/GoldenrodCity_DeptStore_4F/scripts.inc"
	.include "data/maps/GoldenrodCity_DeptStore_5F/scripts.inc"
	.include "data/maps/GoldenrodCity_DeptStore_6F/scripts.inc"
	.include "data/maps/GoldenrodCity_DeptStore_Rooftop/scripts.inc"
	.include "data/maps/GoldenrodCity_DeptStore_Elevator/scripts.inc"
	.include "data/maps/GoldenrodCity_DeptStore_B1F/scripts.inc"
	.include "data/maps/EcruteakCity/scripts.inc"
	.include "data/maps/OlivineCity/scripts.inc"
	.include "data/maps/CianwoodCity/scripts.inc"
	.include "data/maps/MahoganyTown/scripts.inc"
	.include "data/maps/BlackthornCity/scripts.inc"
	.include "data/maps/LakeOfRage/scripts.inc"
	.include "data/maps/Route37/scripts.inc"
	.include "data/maps/Route38/scripts.inc"
	.include "data/maps/Route39/scripts.inc"
	.include "data/maps/Route40/scripts.inc"
	.include "data/maps/Route41/scripts.inc"
	.include "data/maps/Route42/scripts.inc"
	.include "data/maps/Route43/scripts.inc"
	.include "data/maps/Route44/scripts.inc"
	.include "data/maps/SilverCave_Outside/scripts.inc"
	.include "data/maps/Route26/scripts.inc"
	.include "data/maps/Route27/scripts.inc"
	.include "data/maps/Route28/scripts.inc"
	.include "data/maps/EcruteakCity_PokemonCenter_1F/scripts.inc"
	.include "data/maps/OlivineCity_PokemonCenter_1F/scripts.inc"
	.include "data/maps/CianwoodCity_PokemonCenter_1F/scripts.inc"
	.include "data/maps/MahoganyTown_PokemonCenter_1F/scripts.inc"
	.include "data/maps/BlackthornCity_PokemonCenter_1F/scripts.inc"
	.include "data/maps/ViridianCity_PokemonCenter_1F/scripts.inc"
	.include "data/maps/PewterCity_PokemonCenter_1F/scripts.inc"
	.include "data/maps/CeruleanCity_PokemonCenter_1F/scripts.inc"
	.include "data/maps/VermilionCity_PokemonCenter_1F/scripts.inc"
	.include "data/maps/LavenderTown_PokemonCenter_1F/scripts.inc"
	.include "data/maps/CeladonCity_PokemonCenter_1F/scripts.inc"
	.include "data/maps/SaffronCity_PokemonCenter_1F/scripts.inc"
	.include "data/maps/FuchsiaCity_PokemonCenter_1F/scripts.inc"
	.include "data/maps/CinnabarIsland_PokemonCenter_1F/scripts.inc"
	.include "data/maps/Route10_PokemonCenter_1F/scripts.inc"
	.include "data/maps/EcruteakCity_PokemonCenter_2F/scripts.inc"
	.include "data/maps/OlivineCity_PokemonCenter_2F/scripts.inc"
	.include "data/maps/CianwoodCity_PokemonCenter_2F/scripts.inc"
	.include "data/maps/MahoganyTown_PokemonCenter_2F/scripts.inc"
	.include "data/maps/BlackthornCity_PokemonCenter_2F/scripts.inc"
	.include "data/maps/SilverCave_Outside_PokemonCenter_1F/scripts.inc"
	.include "data/maps/SilverCave_Outside_PokemonCenter_2F/scripts.inc"
	.include "data/maps/ViridianCity_PokemonCenter_2F/scripts.inc"
	.include "data/maps/PewterCity_PokemonCenter_2F/scripts.inc"
	.include "data/maps/CeruleanCity_PokemonCenter_2F/scripts.inc"
	.include "data/maps/VermilionCity_PokemonCenter_2F/scripts.inc"
	.include "data/maps/LavenderTown_PokemonCenter_2F/scripts.inc"
	.include "data/maps/CeladonCity_PokemonCenter_2F/scripts.inc"
	.include "data/maps/SaffronCity_PokemonCenter_2F/scripts.inc"
	.include "data/maps/FuchsiaCity_PokemonCenter_2F/scripts.inc"
	.include "data/maps/CinnabarIsland_PokemonCenter_2F/scripts.inc"
	.include "data/maps/Route10_PokemonCenter_2F/scripts.inc"
	.include "data/maps/EcruteakCity_Mart/scripts.inc"
	.include "data/maps/OlivineCity_Mart/scripts.inc"
	.include "data/maps/BlackthornCity_Mart/scripts.inc"
	.include "data/maps/ViridianCity_Mart/scripts.inc"
	.include "data/maps/PewterCity_Mart/scripts.inc"
	.include "data/maps/CeruleanCity_Mart/scripts.inc"
	.include "data/maps/VermilionCity_Mart/scripts.inc"
	.include "data/maps/LavenderTown_Mart/scripts.inc"
	.include "data/maps/SaffronCity_Mart/scripts.inc"
	.include "data/maps/FuchsiaCity_Mart/scripts.inc"
	.include "data/maps/PalletTown/scripts.inc"
	.include "data/maps/ViridianCity/scripts.inc"
	.include "data/maps/PewterCity/scripts.inc"
	.include "data/maps/CeruleanCity/scripts.inc"
	.include "data/maps/LavenderTown/scripts.inc"
	.include "data/maps/VermilionCity/scripts.inc"
	.include "data/maps/CeladonCity/scripts.inc"
	.include "data/maps/FuchsiaCity/scripts.inc"
	.include "data/maps/CinnabarIsland/scripts.inc"
	.include "data/maps/SaffronCity/scripts.inc"
	.include "data/maps/Route1/scripts.inc"
	.include "data/maps/Route2/scripts.inc"
	.include "data/maps/Route3/scripts.inc"
	.include "data/maps/Route4/scripts.inc"
	.include "data/maps/Route5/scripts.inc"
	.include "data/maps/Route6/scripts.inc"
	.include "data/maps/Route7/scripts.inc"
	.include "data/maps/Route8/scripts.inc"
	.include "data/maps/Route9/scripts.inc"
	.include "data/maps/Route10/scripts.inc"
	.include "data/maps/Route11/scripts.inc"
	.include "data/maps/Route12/scripts.inc"
	.include "data/maps/Route13/scripts.inc"
	.include "data/maps/Route14/scripts.inc"
	.include "data/maps/Route15/scripts.inc"
	.include "data/maps/Route16/scripts.inc"
	.include "data/maps/Route17/scripts.inc"
	.include "data/maps/Route18/scripts.inc"
	.include "data/maps/Route19/scripts.inc"
	.include "data/maps/Route20/scripts.inc"
	.include "data/maps/Route21/scripts.inc"
	.include "data/maps/Route22/scripts.inc"
	.include "data/maps/Route23/scripts.inc"
	.include "data/maps/Route24/scripts.inc"
	.include "data/maps/Route25/scripts.inc"
	.include "data/maps/EcruteakCity_Gym/scripts.inc"
	.include "data/maps/EcruteakCity_DanceTheater/scripts.inc"
	.include "data/maps/EcruteakCity_TinTowerGate/scripts.inc"
	.include "data/maps/EcruteakCity_WiseTriosRoom/scripts.inc"
	.include "data/maps/EcruteakCity_House1/scripts.inc"
	.include "data/maps/EcruteakCity_House2/scripts.inc"
	.include "data/maps/OlivineCity_Gym/scripts.inc"
	.include "data/maps/OlivineCity_Cafe/scripts.inc"
	.include "data/maps/OlivineCity_PortPassage/scripts.inc"
	.include "data/maps/OlivineCity_Port/scripts.inc"
	.include "data/maps/OlivineCity_House1/scripts.inc"
	.include "data/maps/OlivineCity_House2/scripts.inc"
	.include "data/maps/OlivineCity_House3/scripts.inc"
	.include "data/maps/CianwoodCity_Gym/scripts.inc"
	.include "data/maps/CianwoodCity_Pharmacy/scripts.inc"
	.include "data/maps/CianwoodCity_House/scripts.inc"
	.include "data/maps/CianwoodCity_PhotoStudio/scripts.inc"
	.include "data/maps/CianwoodCity_ManiasHouse/scripts.inc"
	.include "data/maps/CianwoodCity_PokeSeersHouse/scripts.inc"
	.include "data/maps/MahoganyTown_Gym/scripts.inc"
	.include "data/maps/MahoganyTown_Shop/scripts.inc"
	.include "data/maps/MahoganyTown_House/scripts.inc"
	.include "data/maps/BlackthornCity_Gym_1F/scripts.inc"
	.include "data/maps/BlackthornCity_Gym_2F/scripts.inc"
	.include "data/maps/BlackthornCity_MoveDeletersHouse/scripts.inc"
	.include "data/maps/BlackthornCity_House1/scripts.inc"
	.include "data/maps/BlackthornCity_House2/scripts.inc"
	.include "data/maps/LakeOfRage_HiddenPowerHouse/scripts.inc"
	.include "data/maps/LakeOfRage_FishingGurusHouse/scripts.inc"
	.include "data/maps/RuinsOfAlph_OmanyteWordRoom/scripts.inc"
	.include "data/maps/RuinsOfAlph_AerodactylWordRoom/scripts.inc"
	.include "data/maps/RuinsOfAlph_HoOhWordRoom/scripts.inc"
	.include "data/maps/Route38_Gatehouse/scripts.inc"
	.include "data/maps/Route39_MooMooFarmHouse/scripts.inc"
	.include "data/maps/Route39_MooMooFarmBarn/scripts.inc"
	.include "data/maps/Route40_Gatehouse/scripts.inc"
	.include "data/maps/Route42_Gatehouse/scripts.inc"
	.include "data/maps/Route43_Gatehouse1/scripts.inc"
	.include "data/maps/Route43_Gatehouse2/scripts.inc"
	.include "data/maps/SlowpokeWell_B2F/scripts.inc"
	.include "data/maps/BurnedTower_1F/scripts.inc"
	.include "data/maps/BurnedTower_B1F/scripts.inc"
	.include "data/maps/TinTower_1F/scripts.inc"
	.include "data/maps/TinTower_2F/scripts.inc"
	.include "data/maps/TinTower_3F/scripts.inc"
	.include "data/maps/TinTower_4F/scripts.inc"
	.include "data/maps/TinTower_5F/scripts.inc"
	.include "data/maps/TinTower_6F/scripts.inc"
	.include "data/maps/TinTower_7F/scripts.inc"
	.include "data/maps/TinTower_8F/scripts.inc"
	.include "data/maps/TinTower_9F/scripts.inc"
	.include "data/maps/TinTower_Roof/scripts.inc"
	.include "data/maps/Lighthouse_1F/scripts.inc"
	.include "data/maps/Lighthouse_2F/scripts.inc"
	.include "data/maps/Lighthouse_3F/scripts.inc"
	.include "data/maps/Lighthouse_4F/scripts.inc"
	.include "data/maps/Lighthouse_5F/scripts.inc"
	.include "data/maps/Lighthouse_6F/scripts.inc"
	.include "data/maps/WhirlIslands_1F_NE/scripts.inc"
	.include "data/maps/WhirlIslands_1F_NW/scripts.inc"
	.include "data/maps/WhirlIslands_1F_SE/scripts.inc"
	.include "data/maps/WhirlIslands_1F_SW/scripts.inc"
	.include "data/maps/WhirlIslands_B1F/scripts.inc"
	.include "data/maps/WhirlIslands_B2F/scripts.inc"
	.include "data/maps/WhirlIslands_Cave/scripts.inc"
	.include "data/maps/WhirlIslands_LugiasChamber/scripts.inc"
	.include "data/maps/MtMortar_1F_Outer/scripts.inc"
	.include "data/maps/MtMortar_1F_Inner/scripts.inc"
	.include "data/maps/MtMortar_2F/scripts.inc"
	.include "data/maps/MtMortar_B1F/scripts.inc"
	.include "data/maps/TeamRocketBase_B1F/scripts.inc"
	.include "data/maps/TeamRocketBase_B2F/scripts.inc"
	.include "data/maps/TeamRocketBase_B3F/scripts.inc"
	.include "data/maps/IcePath_1F/scripts.inc"
	.include "data/maps/IcePath_B1F/scripts.inc"
	.include "data/maps/IcePath_B2F_Mahogany/scripts.inc"
	.include "data/maps/IcePath_B2F_Blackthorn/scripts.inc"
	.include "data/maps/IcePath_B3F/scripts.inc"
	.include "data/maps/DragonsDen_Entrance/scripts.inc"
	.include "data/maps/DragonsDen/scripts.inc"
	.include "data/maps/DragonsDen_Shrine/scripts.inc"
	.include "data/maps/FastShip_1F/scripts.inc"
	.include "data/maps/FastShip_B1F/scripts.inc"
	.include "data/maps/FastShip_Cabins_NNW_NNE_NE/scripts.inc"
	.include "data/maps/FastShip_Cabins_SE_SSE_Captains/scripts.inc"
	.include "data/maps/FastShip_Cabins_SW_SSW_NW/scripts.inc"
	.include "data/maps/SilverCave_Room1/scripts.inc"
	.include "data/maps/SilverCave_Room2/scripts.inc"
	.include "data/maps/SilverCave_Room3/scripts.inc"
	.include "data/maps/SilverCave_ItemRooms/scripts.inc"
	.include "data/maps/TohjoFalls/scripts.inc"
	.include "data/maps/VictoryRoad_Gatehouse/scripts.inc"
	.include "data/maps/VictoryRoad/scripts.inc"
	.include "data/maps/PalletTown_RedsHouse_1F/scripts.inc"
	.include "data/maps/PalletTown_RedsHouse_2F/scripts.inc"
	.include "data/maps/PalletTown_BluesHouse/scripts.inc"
	.include "data/maps/PalletTown_ProfessorOaksLab/scripts.inc"
	.include "data/maps/ViridianCity_Gym/scripts.inc"
	.include "data/maps/ViridianCity_House/scripts.inc"
	.include "data/maps/ViridianCity_TrainerHouse_1F/scripts.inc"
	.include "data/maps/ViridianCity_TrainerHouse_B1F/scripts.inc"
	.include "data/maps/PewterCity_Gym/scripts.inc"
	.include "data/maps/PewterCity_House1/scripts.inc"
	.include "data/maps/PewterCity_House2/scripts.inc"
	.include "data/maps/PewterCity_Museum_1F/scripts.inc"
	.include "data/maps/PewterCity_Museum_2F/scripts.inc"
	.include "data/maps/CeruleanCity_Gym/scripts.inc"
	.include "data/maps/CeruleanCity_House1/scripts.inc"
	.include "data/maps/CeruleanCity_House2/scripts.inc"
	.include "data/maps/CeruleanCity_House3/scripts.inc"
	.include "data/maps/VermilionCity_Gym/scripts.inc"
	.include "data/maps/VermilionCity_PokemonFanClub/scripts.inc"
	.include "data/maps/VermilionCity_PortPassage/scripts.inc"
	.include "data/maps/VermilionCity_Port/scripts.inc"
	.include "data/maps/VermilionCity_House1/scripts.inc"
	.include "data/maps/VermilionCity_House2/scripts.inc"
	.include "data/maps/VermilionCity_House3/scripts.inc"
	.include "data/maps/LavenderTown_RadioTower_1F/scripts.inc"
	.include "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.inc"
	.include "data/maps/LavenderTown_SoulHouse/scripts.inc"
	.include "data/maps/LavenderTown_NameRatersHouse/scripts.inc"
	.include "data/maps/LavenderTown_House/scripts.inc"
	.include "data/maps/CeladonCity_Gym/scripts.inc"
	.include "data/maps/CeladonCity_GameCorner/scripts.inc"
	.include "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.inc"
	.include "data/maps/CeladonCity_Restaurant/scripts.inc"
	.include "data/maps/CeladonCity_Mansion_1F/scripts.inc"
	.include "data/maps/CeladonCity_Mansion_2F/scripts.inc"
	.include "data/maps/CeladonCity_Mansion_3F/scripts.inc"
	.include "data/maps/CeladonCity_Mansion_Roof/scripts.inc"
	.include "data/maps/CeladonCity_Mansion_Penthouse/scripts.inc"
	.include "data/maps/CeladonCity_DepartmentStore_1F/scripts.inc"
	.include "data/maps/CeladonCity_DepartmentStore_2F/scripts.inc"
	.include "data/maps/CeladonCity_DepartmentStore_3F/scripts.inc"
	.include "data/maps/CeladonCity_DepartmentStore_4F/scripts.inc"
	.include "data/maps/CeladonCity_DepartmentStore_5F/scripts.inc"
	.include "data/maps/CeladonCity_DepartmentStore_Roof/scripts.inc"
	.include "data/maps/CeladonCity_DepartmentStore_Elevator/scripts.inc"
	.include "data/maps/SaffronCity_Gym/scripts.inc"
	.include "data/maps/SaffronCity_Dojo/scripts.inc"
	.include "data/maps/SaffronCity_CopycatsHouse_1F/scripts.inc"
	.include "data/maps/SaffronCity_CopycatsHouse_2F/scripts.inc"
	.include "data/maps/SaffronCity_MagnetTrainStation/scripts.inc"
	.include "data/maps/SaffronCity_SilphCo_1F/scripts.inc"
	.include "data/maps/SaffronCity_MrPsychicsHouse/scripts.inc"
	.include "data/maps/FuchsiaCity_Gym/scripts.inc"
	.include "data/maps/FuchsiaCity_SafariZoneOffice/scripts.inc"
	.include "data/maps/FuchsiaCity_WardensHouse/scripts.inc"
	.include "data/maps/FuchsiaCity_House/scripts.inc"
	.include "data/maps/IndigoPlateau_PokemonCenter_1F/scripts.inc"
	.include "data/maps/IndigoPlateau_PokemonCenter_2F/scripts.inc"
	.include "data/maps/IndigoPlateau_WillsRoom/scripts.inc"
	.include "data/maps/IndigoPlateau_KogasRoom/scripts.inc"
	.include "data/maps/IndigoPlateau_BrunosRoom/scripts.inc"
	.include "data/maps/IndigoPlateau_KarensRoom/scripts.inc"
	.include "data/maps/IndigoPlateau_LancesRoom/scripts.inc"
	.include "data/maps/IndigoPlateau_HallOfFame/scripts.inc"
	.include "data/maps/Route2_House/scripts.inc"
	.include "data/maps/Route2_Gatehouse/scripts.inc"
	.include "data/maps/Route5_House/scripts.inc"
	.include "data/maps/Route5_Gatehouse/scripts.inc"
	.include "data/maps/Route5_UndergroundPathEntrance/scripts.inc"
	.include "data/maps/Route6_UndergroundPathEntrance/scripts.inc"
	.include "data/maps/Route6_Gatehouse/scripts.inc"
	.include "data/maps/Route7_Gatehouse/scripts.inc"
	.include "data/maps/Route8_Gatehouse/scripts.inc"
	.include "data/maps/Route10_PowerPlant/scripts.inc"
	.include "data/maps/Route12_FishingHouse/scripts.inc"
	.include "data/maps/Route15_Gatehouse_1F/scripts.inc"
	.include "data/maps/Route15_Gatehouse_2F/scripts.inc"
	.include "data/maps/Route16_House/scripts.inc"
	.include "data/maps/Route16_Gatehouse_1F/scripts.inc"
	.include "data/maps/Route16_Gatehouse_2F/scripts.inc"
	.include "data/maps/Route17_Gatehouse_1F/scripts.inc"
	.include "data/maps/Route17_Gatehouse_2F/scripts.inc"
	.include "data/maps/Route19_Gatehouse/scripts.inc"
	.include "data/maps/Route20_SeafoamGym/scripts.inc"
	.include "data/maps/Route25_BillsHouse/scripts.inc"
	.include "data/maps/Route26_House1/scripts.inc"
	.include "data/maps/Route26_House2/scripts.inc"
	.include "data/maps/Route27_House/scripts.inc"
	.include "data/maps/Route28_House/scripts.inc"
	.include "data/maps/DiglettsCave/scripts.inc"
	.include "data/maps/MtMoon_1F/scripts.inc"
	.include "data/maps/MtMoon_Square/scripts.inc"
	.include "data/maps/MtMoon_GiftShop/scripts.inc"
	.include "data/maps/UndergroundPath/scripts.inc"
	.include "data/maps/RockTunnel_1F/scripts.inc"
	.include "data/maps/RockTunnel_B1F/scripts.inc"
	.include "data/maps/ViridianForest/scripts.inc"
	.include "data/maps/Route2_ViridianForest_SouthEntrance/scripts.inc"
	.include "data/maps/Route2_ViridianForest_NorthEntrance/scripts.inc"
	.include "data/maps/Route12_Gatehouse_1F/scripts.inc"
	.include "data/maps/Route12_Gatehouse_2F/scripts.inc"
	.include "data/maps/GoldenrodCity_Underground_SwitchRoom/scripts.inc"
	.include "data/maps/GoldenrodCity_Underground_Warehouse/scripts.inc"
	.include "data/maps/Route11_Gatehouse_1F/scripts.inc"
	.include "data/maps/Route11_Gatehouse_2F/scripts.inc"
	.include "data/maps/Route3_PokemonCenter_1F/scripts.inc"
	.include "data/maps/Route3_PokemonCenter_2F/scripts.inc"
	.include "data/maps/Route18_Gatehouse_1F/scripts.inc"
	.include "data/maps/Route18_Gatehouse_2F/scripts.inc"
	.include "data/maps/MtMoon_B1F/scripts.inc"
	.include "data/maps/MtMoon_B2F/scripts.inc"
	.include "data/maps/MtMoon_B3F/scripts.inc"
	.include "data/maps/CeruleanCity_BerryCrushHouse/scripts.inc"

	.include "data/maps/Route40_FrontierGate/scripts.inc"
