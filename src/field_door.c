#include "global.h"
#include "event_data.h"
#include "field_door.h"
#include "field_camera.h"
#include "fieldmap.h"
#include "metatile_behavior.h"
#include "task.h"
#include "constants/maps.h"
#include "constants/songs.h"
#include "constants/metatile_labels.h"

#define DOOR_SOUND_NORMAL  0
#define DOOR_SOUND_SLIDING 1
#define DOOR_SOUND_ARENA   2

struct DoorGraphics
{
    u16 metatileNum;
    u8 sound;
    u8 size;
    const void *tiles;
    const void *palette;
};

struct DoorAnimFrame
{
    u8 time;
    u16 offset;
};

static bool8 ShouldUseMultiCorridorDoor(void);

static const u8 sDoorAnimTiles_General[] = INCBIN_U8("graphics/door_anims/general.4bpp");
static const u8 sDoorAnimTiles_PokeCenter[] = INCBIN_U8("graphics/door_anims/poke_center.4bpp");
static const u8 sDoorAnimTiles_Gym[] = INCBIN_U8("graphics/door_anims/gym.4bpp");
static const u8 sDoorAnimTiles_NewBark[] = INCBIN_U8("graphics/door_anims/new_bark.4bpp");
static const u8 sDoorAnimTiles_ElmsLab[] = INCBIN_U8("graphics/door_anims/elms_lab.4bpp");
static const u8 sDoorAnimTiles_Violet[] = INCBIN_U8("graphics/door_anims/violet.4bpp");
static const u8 sDoorAnimTiles_SproutTower[] = INCBIN_U8("graphics/door_anims/sprout_tower.4bpp");
static const u8 sDoorAnimTiles_RuinsLab[] = INCBIN_U8("graphics/door_anims/ruins_lab.4bpp");
static const u8 sDoorAnimTiles_Azalea[] = INCBIN_U8("graphics/door_anims/azalea.4bpp");
static const u8 sDoorAnimTiles_Goldenrod[] = INCBIN_U8("graphics/door_anims/goldenrod.4bpp");
static const u8 sDoorAnimTiles_RadioTower[] = INCBIN_U8("graphics/door_anims/radio_tower.4bpp");
static const u8 sDoorAnimTiles_GoldenrodDeptStore[] = INCBIN_U8("graphics/door_anims/goldenrod_dept_store.4bpp");
static const u8 sDoorAnimTiles_PokecomCenter[] = INCBIN_U8("graphics/door_anims/pokecom_center.4bpp");
static const u8 sDoorAnimTiles_LilycoveWooden[] = INCBIN_U8("graphics/door_anims/lilycove_wooden.4bpp");
static const u8 sDoorAnimTiles_UnusedTops[] = INCBIN_U8("graphics/door_anims/unused_top.4bpp");
static const u8 sDoorAnimTiles_UnusedBottoms[] = INCBIN_U8("graphics/door_anims/unused_bottom.4bpp");
static const u8 sDoorAnimTiles_Dewford[] = INCBIN_U8("graphics/door_anims/dewford.4bpp");
static const u8 sDoorAnimTiles_Contest[] = INCBIN_U8("graphics/door_anims/contest.4bpp");
static const u8 sDoorAnimTiles_SootopolisPeakedRoof[] = INCBIN_U8("graphics/door_anims/sootopolis_peaked_roof.4bpp");
static const u8 sDoorAnimTiles_Sootopolis[] = INCBIN_U8("graphics/door_anims/sootopolis.4bpp");
static const u8 sDoorAnimTiles_PokemonLeague[] = INCBIN_U8("graphics/door_anims/pokemon_league.4bpp");
static const u8 sDoorAnimTiles_Pacifidlog[] = INCBIN_U8("graphics/door_anims/pacifidlog.4bpp");
static const u8 sDoorAnimTiles_BattleTowerCorridor[] = INCBIN_U8("graphics/door_anims/battle_tower_corridor.4bpp");
static const u8 sDoorAnimTiles_CyclingRoad[] = INCBIN_U8("graphics/door_anims/cycling_road.4bpp");
static const u8 sDoorAnimTiles_LilycoveDeptStore[] = INCBIN_U8("graphics/door_anims/lilycove_dept_store.4bpp");
static const u8 sDoorAnimTiles_SafariZone[] = INCBIN_U8("graphics/door_anims/safari_zone.4bpp");
static const u8 sDoorAnimTiles_CableClub[] = INCBIN_U8("graphics/door_anims/cable_club.4bpp");
static const u8 sDoorAnimTiles_FastShip[] = INCBIN_U8("graphics/door_anims/fast_ship.4bpp");
static const u8 sDoorAnimTiles_FallarborDarkRoof[] = INCBIN_U8("graphics/door_anims/fallarbor_dark_roof.4bpp");
static const u8 sDoorAnimTiles_DeptStoreElevator[] = INCBIN_U8("graphics/door_anims/dept_store_elevator.4bpp");
static const u8 sDoorAnimTiles_RadioTowerElevatorBlueWall[] = INCBIN_U8("graphics/door_anims/facility_blue_wall_elevator.4bpp");
static const u8 sDoorAnimTiles_RadioTowerElevatorPinkWall[] = INCBIN_U8("graphics/door_anims/facility_pink_wall_elevator.4bpp");
static const u8 sDoorAnimTiles_BattleTowerOld[] = INCBIN_U8("graphics/door_anims/battle_tower_old.4bpp");
static const u8 sDoorAnimTiles_BattleTowerElevator[] = INCBIN_U8("graphics/door_anims/battle_tower_elevator.4bpp");
static const u8 sDoorAnimTiles_34[] = INCBIN_U8("graphics/door_anims/unknown.4bpp");
static const u8 sDoorAnimTiles_BattleDome[] = INCBIN_U8("graphics/door_anims/battle_dome.4bpp");
static const u8 sDoorAnimTiles_BattleFactory[] = INCBIN_U8("graphics/door_anims/battle_factory.4bpp");
static const u8 sDoorAnimTiles_BattleTower[] = INCBIN_U8("graphics/door_anims/battle_tower.4bpp");
static const u8 sDoorAnimTiles_BattleArena[] = INCBIN_U8("graphics/door_anims/battle_arena.4bpp");
static const u8 sDoorAnimTiles_BattleArenaLobby[] = INCBIN_U8("graphics/door_anims/battle_arena_lobby.4bpp");
static const u8 sDoorAnimTiles_BattleDomeLobby[] = INCBIN_U8("graphics/door_anims/battle_dome_lobby.4bpp");
static const u8 sDoorAnimTiles_BattlePalaceLobby[] = INCBIN_U8("graphics/door_anims/battle_palace_lobby.4bpp");
static const u8 sDoorAnimTiles_BattleTent[] = INCBIN_U8("graphics/door_anims/battle_tent.4bpp");
static const u8 sDoorAnimTiles_BattleDomeCorridor[] = INCBIN_U8("graphics/door_anims/battle_dome_corridor.4bpp");
static const u8 sDoorAnimTiles_BattleTowerMultiCorridor[] = INCBIN_U8("graphics/door_anims/battle_tower_multi_corridor.4bpp");
static const u8 sDoorAnimTiles_BattleFrontier[] = INCBIN_U8("graphics/door_anims/battle_frontier.4bpp");
static const u8 sDoorAnimTiles_BattleFrontierSliding[] = INCBIN_U8("graphics/door_anims/battle_frontier_sliding.4bpp");
static const u8 sDoorAnimTiles_BattleDomePreBattleRoom[] = INCBIN_U8("graphics/door_anims/battle_dome_pre_battle_room.4bpp");
static const u8 sDoorAnimTiles_BattleTentInterior[] = INCBIN_U8("graphics/door_anims/battle_tent_interior.4bpp");
static const u8 sDoorAnimTiles_TrainerHillLobbyElevator[] = INCBIN_U8("graphics/door_anims/trainer_hill_lobby_elevator.4bpp");
static const u8 sDoorAnimTiles_TrainerHillRoofElevator[] = INCBIN_U8("graphics/door_anims/trainer_hill_roof_elevator.4bpp");
static const u8 sDoorAnimTiles_EcruteakCity[] = INCBIN_U8("graphics/door_anims/ecruteak.4bpp");
static const u8 sDoorAnimTiles_Vermilion[] = INCBIN_U8("graphics/door_anims/vermilion.4bpp");
static const u8 sDoorAnimTiles_Saffron[] = INCBIN_U8("graphics/door_anims/saffron.4bpp");
static const u8 sDoorAnimTiles_PalletHouse[] = INCBIN_U8("graphics/door_anims/pallet_house.4bpp");
static const u8 sDoorAnimTiles_PalletLab[] = INCBIN_U8("graphics/door_anims/pallet_lab.4bpp");
static const u8 sDoorAnimTiles_FuchsiaLit[] = INCBIN_U8("graphics/door_anims/fuchsia_lit.4bpp");
static const u8 sDoorAnimTiles_FuchsiaUnlit[] = INCBIN_U8("graphics/door_anims/fuchsia_unlit.4bpp");
static const u8 sDoorAnimTiles_Viridian[] = INCBIN_U8("graphics/door_anims/viridian.4bpp");
static const u8 sDoorAnimTiles_Pewter[] = INCBIN_U8("graphics/door_anims/pewter.4bpp");
static const u8 sDoorAnimTiles_Lavender[] = INCBIN_U8("graphics/door_anims/lavender.4bpp");
static const u8 sDoorAnimTiles_Barn[] = INCBIN_U8("graphics/door_anims/moo_moo_barn.4bpp");
static const u8 sDoorAnimTiles_Cianwood[] = INCBIN_U8("graphics/door_anims/cianwood.4bpp");
static const u8 sDoorAnimTiles_Olivine[] = INCBIN_U8("graphics/door_anims/olivine.4bpp");
static const u8 sDoorAnimTiles_Lighthouse[] = INCBIN_U8("graphics/door_anims/lighthouse.4bpp");
static const u8 sDoorAnimTiles_GoldenrodUnderground[] = INCBIN_U8("graphics/door_anims/goldenrod_underground.4bpp");

static const struct DoorAnimFrame sDoorOpenAnimFrames[] =
{
    {4, -1},
    {4, 0},
    {4, 0x80},
    {4, 0x100},
    {0, 0},
};

static const struct DoorAnimFrame sDoorCloseAnimFrames[] =
{
    {4, 0x100},
    {4, 0x80},
    {4, 0},
    {4, -1},
    {0, 0},
};

static const struct DoorAnimFrame sTallDoorOpenAnimFrames[] =
{
    {4, -1},
    {4, 0},
    {4, 0x100},
    {4, 0x200},
    {0, 0},
};

static const struct DoorAnimFrame sTallDoorCloseAnimFrames[] =
{
    {4, 0x200},
    {4, 0x100},
    {4, 0},
    {4, -1},
    {0, 0},
};

static const struct DoorAnimFrame sBigDoorOpenAnimFrames[] =
{
    {4, -1},
    {4, 0},
    {4, 0x200},
    {4, 0x400},
    {0, 0},
};

static const struct DoorAnimFrame sBigDoorCloseAnimFrames[] =
{
    {4, 0x400},
    {4, 0x200},
    {4, 0},
    {4, -1},
    {0, 0},
};

static const u8 sDoorAnimPalettes_General[] = {2, 2, 2, 2};
static const u8 sDoorAnimPalettes_PokeCenter[] = {7, 7, 7, 7};
static const u8 sDoorAnimPalettes_Gym[] = {7, 7, 7, 7};
static const u8 sDoorAnimPalettes_NewBark[] = {12, 12, 12, 12};
static const u8 sDoorAnimPalettes_ElmsLab[] = {9, 9, 9, 9};
static const u8 sDoorAnimPalettes_Violet[] = {12, 12, 12, 12};
static const u8 sDoorAnimPalettes_SproutTower[] = {9, 9, 9, 9};
static const u8 sDoorAnimPalettes_RuinsLab[] = {7, 7, 7, 7};
static const u8 sDoorAnimPalettes_Azalea[] = {8, 8, 8, 8};
static const u8 sDoorAnimPalettes_Goldenrod[] = {10, 10, 10, 10};
static const u8 sDoorAnimPalettes_RadioTower[] = {9, 9, 9, 9};
static const u8 sDoorAnimPalettes_GoldenrodDeptStore[] = {7, 7, 7, 7};
static const u8 sDoorAnimPalettes_Pokecomcenter[] = {7, 7, 7, 7};
static const u8 sDoorAnimPalettes_DeptStoreElevator[] = {8, 8, 8, 8, 8, 8, 8, 8};
static const u8 sDoorAnimPalettes_RadioTowerElevatorBlueWall[] = {12, 12, 2, 2, 2, 2, 2, 2};
static const u8 sDoorAnimPalettes_RadioTowerElevatorPinkWall[] = {8, 8, 2, 2, 2, 2, 2, 2};
static const u8 sDoorAnimPalettes_PokemonLeague[] = {8, 8, 8, 8, 8, 8, 8, 8};
static const u8 sDoorAnimPalettes_Pacifidlog[] = {9, 9, 9, 9, 9, 9, 9, 9};
static const u8 sDoorAnimPalettes_SootopolisPeakedRoof[] = {6, 6, 6, 6, 6, 6, 6, 6};
static const u8 sDoorAnimPalettes_Sootopolis[] = {6, 6, 6, 6, 6, 6, 6, 6};
static const u8 sDoorAnimPalettes_Dewford[] = {0, 0, 5, 5, 5, 5, 5, 5};
static const u8 sDoorAnimPalettes_LilycoveWooden[] = {5, 5, 5, 5, 5, 5, 5, 5};
static const u8 sDoorAnimPalettes_Contest[] = {1, 1, 1, 1, 1, 1, 1, 1};
static const u8 sDoorAnimPalettes_BattleTowerCorridor[] = {6, 6, 6, 6, 6, 6, 6, 6};
static const u8 sDoorAnimPalettes_CyclingRoad[] = {7, 7, 7, 7, 7, 7, 7, 7};
static const u8 sDoorAnimPalettes_LilycoveDeptStore[] = {5, 5, 5, 5, 5, 5, 5, 5};
static const u8 sDoorAnimPalettes_SafariZone[] = {9, 9, 9, 9, 9, 9, 9, 9};
static const u8 sDoorAnimPalettes_CableClub[] = {8, 8, 8, 8, 8, 8, 8, 8};
static const u8 sDoorAnimPalettes_FastShip[] = {7, 7, 7, 7, 7, 7, 7, 7};
static const u8 sDoorAnimPalettes_FallarborDarkRoof[] = {11, 11, 7, 7, 7, 7, 7, 7};
static const u8 sDoorAnimPalettes_BattleTowerOld[] = {9, 9, 9, 9, 9, 9, 9, 9};
static const u8 sDoorAnimPalettes_BattleTowerElevator[] = {7, 7, 7, 7};
static const u8 sDoorAnimPalettes_34[] = {9, 9, 9, 9, 9, 9, 9, 9};
static const u8 sDoorAnimPalettes_BattleDome[] = {2, 2, 2, 2, 3, 3, 3, 3};
static const u8 sDoorAnimPalettes_BattleFactory[] = {9, 9, 9, 9, 9, 9, 9, 9};
static const u8 sDoorAnimPalettes_BattleTower[] = {3, 3, 3, 3};
static const u8 sDoorAnimPalettes_BattleArena[] = {7, 7, 7, 7, 7, 7, 7, 7};
static const u8 sDoorAnimPalettes_BattleArenaLobby[] = {7, 7, 7, 7, 7, 7, 7, 7};
static const u8 sDoorAnimPalettes_BattleDomeLobby[] = {7, 7, 7, 7, 7, 7, 7, 7};
static const u8 sDoorAnimPalettes_BattlePalaceLobby[] = {7, 7, 7, 7, 7, 7, 7, 7};
static const u8 sDoorAnimPalettes_BattleTent[] = {1, 1, 1, 1, 1, 1, 1, 1};
static const u8 sDoorAnimPalettes_BattleDomeCorridor[] = {7, 7, 7, 7, 7, 7, 7, 7};
static const u8 sDoorAnimPalettes_BattleTowerMultiCorridor[] = {7, 7, 7, 7, 7, 7, 7, 7};
static const u8 sDoorAnimPalettes_Unused[] = {1, 1, 1, 1, 1, 1, 1, 1};
static const u8 sDoorAnimPalettes_BattleFrontier[] = {1, 1, 1, 1, 1, 1, 1, 1};
static const u8 sDoorAnimPalettes_BattleDomePreBattleRoom[] = {9, 9, 7, 7, 7, 7, 7, 7};
static const u8 sDoorAnimPalettes_BattleTentInterior[] = {9, 9, 9, 9, 9, 9, 9, 9};
static const u8 sDoorAnimPalettes_TrainerHillLobbyElevator[] = {7, 7, 7, 7, 7, 7, 7, 7};
static const u8 sDoorAnimPalettes_TrainerHillRoofElevator[] = {9, 9, 7, 7, 7, 7, 7, 7};
static const u8 sDoorAnimPalettes_Ecruteak[] = {8, 8, 8, 8};
static const u8 sDoorAnimPalettes_Vermilion[] = {9, 9, 9, 9};
static const u8 sDoorAnimPalettes_Saffron[] = {8, 8, 8, 8};
static const u8 sDoorAnimPalettes_PalletHouse[] = {8, 8, 8, 8};
static const u8 sDoorAnimPalettes_PalletLab[] = {10, 10, 10, 10};
static const u8 sDoorAnimPalettes_Fuchsia[] = {8, 8, 8, 8};
static const u8 sDoorAnimPalettes_Viridian[] = {8, 8, 8, 8};
static const u8 sDoorAnimPalettes_Pewter[] = {8, 8, 8, 8};
static const u8 sDoorAnimPalettes_Lavender[] = {9, 9, 9, 9};
static const u8 sDoorAnimPalettes_BarnFarm[] = {10, 10, 10, 10};
static const u8 sDoorAnimPalettes_Cianwood[] = {3, 3, 3, 3};
static const u8 sDoorAnimPalettes_Olivine[] = {5, 5, 5, 5};
static const u8 sDoorAnimPalettes_Lighthouse[] = {11, 11, 11, 11};
static const u8 sDoorAnimPalettes_GoldenrodUnderground[] = {8, 8, 8, 8};

static const struct DoorGraphics sDoorAnimGraphicsTable[] =
{
    {METATILE_General_Door,                                 DOOR_SOUND_NORMAL,  0, sDoorAnimTiles_General, sDoorAnimPalettes_General},
    {METATILE_General_Door_PokeCenter,                      DOOR_SOUND_SLIDING, 0, sDoorAnimTiles_PokeCenter, sDoorAnimPalettes_PokeCenter},
    {METATILE_General_Door_Gym,                             DOOR_SOUND_SLIDING, 0, sDoorAnimTiles_Gym, sDoorAnimPalettes_Gym},
    {METATILE_NewBark_Door_NewBark,                         DOOR_SOUND_NORMAL,  0, sDoorAnimTiles_NewBark, sDoorAnimPalettes_ElmsLab},
    {METATILE_NewBark_Door_ElmsLab,                         DOOR_SOUND_NORMAL,  0, sDoorAnimTiles_ElmsLab, sDoorAnimPalettes_ElmsLab},
    {METATILE_Violet_Door_House,                            DOOR_SOUND_NORMAL,  0, sDoorAnimTiles_Violet, sDoorAnimPalettes_Violet},
    {METATILE_Violet_Door_SproutTower,                      DOOR_SOUND_NORMAL,  0, sDoorAnimTiles_EcruteakCity, sDoorAnimPalettes_SproutTower},
    {METATILE_Violet_Door_Lab,                              DOOR_SOUND_NORMAL,  0, sDoorAnimTiles_RuinsLab, sDoorAnimPalettes_RuinsLab},
    {METATILE_Azalea_Door,                                  DOOR_SOUND_NORMAL,  0, sDoorAnimTiles_Azalea, sDoorAnimPalettes_Azalea},
    {METATILE_Goldenrod_Door_House,                         DOOR_SOUND_NORMAL,  0, sDoorAnimTiles_Goldenrod, sDoorAnimPalettes_Goldenrod},
    {METATILE_Goldenrod_Door_RadioTower,                    DOOR_SOUND_SLIDING, 0, sDoorAnimTiles_RadioTower, sDoorAnimPalettes_RadioTower},
    {METATILE_Goldenrod_Door_DeptStore,                     DOOR_SOUND_SLIDING, 0, sDoorAnimTiles_GoldenrodDeptStore, sDoorAnimPalettes_GoldenrodDeptStore},
    {METATILE_Goldenrod_Door_PokecomCenter,                 DOOR_SOUND_SLIDING, 0, sDoorAnimTiles_PokecomCenter, sDoorAnimPalettes_Pokecomcenter},
    {METATILE_DepartmentStore_Door_Elevator,                DOOR_SOUND_SLIDING, 1, sDoorAnimTiles_DeptStoreElevator, sDoorAnimPalettes_DeptStoreElevator},
    {METATILE_RadioTower_Door_Elevator_BlueWall,            DOOR_SOUND_SLIDING, 1, sDoorAnimTiles_RadioTowerElevatorBlueWall, sDoorAnimPalettes_RadioTowerElevatorBlueWall},
    {METATILE_RadioTower_Door_Elevator_PinkWall,            DOOR_SOUND_SLIDING, 1, sDoorAnimTiles_RadioTowerElevatorPinkWall, sDoorAnimPalettes_RadioTowerElevatorPinkWall},
    {METATILE_Dewford_Door,                                 DOOR_SOUND_NORMAL,  1, sDoorAnimTiles_Dewford, sDoorAnimPalettes_Dewford},
    {METATILE_General_Door_Contest,                         DOOR_SOUND_SLIDING, 1, sDoorAnimTiles_Contest, sDoorAnimPalettes_Contest},
    {METATILE_Sootopolis_Door_PeakedRoof,                   DOOR_SOUND_NORMAL,  1, sDoorAnimTiles_SootopolisPeakedRoof, sDoorAnimPalettes_SootopolisPeakedRoof},
    {METATILE_Sootopolis_Door,                              DOOR_SOUND_NORMAL,  1, sDoorAnimTiles_Sootopolis, sDoorAnimPalettes_Sootopolis},
    {METATILE_EverGrande_Door_PokemonLeague,                DOOR_SOUND_SLIDING, 1, sDoorAnimTiles_PokemonLeague, sDoorAnimPalettes_PokemonLeague},
    {METATILE_Pacifidlog_Door,                              DOOR_SOUND_NORMAL,  1, sDoorAnimTiles_Pacifidlog, sDoorAnimPalettes_Pacifidlog},
    {METATILE_BattleFrontier_Door_Corridor,                 DOOR_SOUND_NORMAL,  1, sDoorAnimTiles_BattleTowerCorridor, sDoorAnimPalettes_BattleTowerCorridor},
    {METATILE_Lilycove_Door_DeptStore,                      DOOR_SOUND_SLIDING, 1, sDoorAnimTiles_LilycoveDeptStore, sDoorAnimPalettes_LilycoveDeptStore},
    {METATILE_Lilycove_Door_SafariZone,                     DOOR_SOUND_SLIDING, 1, sDoorAnimTiles_SafariZone, sDoorAnimPalettes_SafariZone},
    {METATILE_PokemonCenter_Door_CableClub,                 DOOR_SOUND_SLIDING, 1, sDoorAnimTiles_CableClub, sDoorAnimPalettes_CableClub},
    {METATILE_InsideShip_IntactDoor_Bottom_Unlocked,        DOOR_SOUND_NORMAL,  1, sDoorAnimTiles_FastShip, sDoorAnimPalettes_FastShip},
    {METATILE_Fallarbor_Door_DarkRoof,                      DOOR_SOUND_NORMAL,  1, sDoorAnimTiles_FallarborDarkRoof, sDoorAnimPalettes_FallarborDarkRoof},
    {METATILE_Dewford_Door_BattleTower,                     DOOR_SOUND_SLIDING, 1, sDoorAnimTiles_BattleTowerOld, sDoorAnimPalettes_BattleTowerOld},
    {METATILE_BattleFrontier_Door_Elevator,                 DOOR_SOUND_SLIDING, 0, sDoorAnimTiles_BattleTowerElevator, sDoorAnimPalettes_BattleTowerElevator},
    {0x3B0, /* TODO: Missing metatile ID */                 DOOR_SOUND_SLIDING, 1, sDoorAnimTiles_34, sDoorAnimPalettes_34},
    {METATILE_BattleFrontierOutsideWest_Door_BattleDome,    DOOR_SOUND_SLIDING, 1, sDoorAnimTiles_BattleDome, sDoorAnimPalettes_BattleDome},
    {METATILE_BattleFrontierOutsideWest_Door_BattleFactory, DOOR_SOUND_SLIDING, 1, sDoorAnimTiles_BattleFactory, sDoorAnimPalettes_BattleFactory},
    {METATILE_BattleFrontierOutsideEast_Door_BattleTower,   DOOR_SOUND_SLIDING, 0, sDoorAnimTiles_BattleTower, sDoorAnimPalettes_BattleTower},
    {METATILE_BattleFrontierOutsideEast_Door_BattleArena,   DOOR_SOUND_NORMAL,  1, sDoorAnimTiles_BattleArena, sDoorAnimPalettes_BattleArena},
    {METATILE_BattleArena_Door,                             DOOR_SOUND_ARENA,   1, sDoorAnimTiles_BattleArenaLobby, sDoorAnimPalettes_BattleArenaLobby},
    {METATILE_BattleDome_Door_Lobby,                        DOOR_SOUND_SLIDING, 1, sDoorAnimTiles_BattleDomeLobby, sDoorAnimPalettes_BattleDomeLobby},
    {METATILE_BattlePalace_Door,                            DOOR_SOUND_NORMAL,  1, sDoorAnimTiles_BattlePalaceLobby, sDoorAnimPalettes_BattlePalaceLobby},
    {METATILE_Slateport_Door_BattleTent,                    DOOR_SOUND_SLIDING, 1, sDoorAnimTiles_BattleTent, sDoorAnimPalettes_BattleTent},
    {METATILE_Mauville_Door_BattleTent,                     DOOR_SOUND_SLIDING, 1, sDoorAnimTiles_BattleTent, sDoorAnimPalettes_BattleTent},
    {METATILE_Fallarbor_Door_BattleTent,                    DOOR_SOUND_SLIDING, 1, sDoorAnimTiles_BattleTent, sDoorAnimPalettes_BattleTent},
    {METATILE_BattleDome_Door_Corridor,                     DOOR_SOUND_SLIDING, 1, sDoorAnimTiles_BattleDomeCorridor, sDoorAnimPalettes_BattleDomeCorridor},
    {METATILE_BattleFrontier_Door_MultiCorridor,            DOOR_SOUND_SLIDING, 2, sDoorAnimTiles_BattleTowerMultiCorridor, sDoorAnimPalettes_BattleTowerMultiCorridor},
    {METATILE_BattleFrontierOutsideWest_Door_Sliding,       DOOR_SOUND_SLIDING, 1, sDoorAnimTiles_BattleFrontierSliding, sDoorAnimPalettes_BattleFrontier},
    {METATILE_BattleDome_Door_PreBattleRoom,                DOOR_SOUND_SLIDING, 1, sDoorAnimTiles_BattleDomePreBattleRoom, sDoorAnimPalettes_BattleDomePreBattleRoom},
    {METATILE_BattleTent_Door,                              DOOR_SOUND_SLIDING, 1, sDoorAnimTiles_BattleTentInterior, sDoorAnimPalettes_BattleTentInterior},
    {METATILE_TrainerHill_Door_Elevator_Lobby,              DOOR_SOUND_SLIDING, 1, sDoorAnimTiles_TrainerHillLobbyElevator, sDoorAnimPalettes_TrainerHillLobbyElevator},
    {METATILE_TrainerHill_Door_Elevator_Roof,               DOOR_SOUND_SLIDING, 1, sDoorAnimTiles_TrainerHillRoofElevator, sDoorAnimPalettes_TrainerHillRoofElevator},
    {METATILE_EcruteakCity_Door,                            DOOR_SOUND_NORMAL,  0, sDoorAnimTiles_EcruteakCity, sDoorAnimPalettes_Ecruteak},
    {METATILE_VermilionCity_Door,                           DOOR_SOUND_NORMAL,  0, sDoorAnimTiles_Vermilion, sDoorAnimPalettes_Vermilion},
    {METATILE_SaffronCity_Door,                             DOOR_SOUND_NORMAL,  0, sDoorAnimTiles_Saffron, sDoorAnimPalettes_Saffron},
    {METATILE_PalletTown_Door_House,                        DOOR_SOUND_NORMAL,  0, sDoorAnimTiles_PalletHouse, sDoorAnimPalettes_PalletHouse},
    {METATILE_PalletTown_Door_Lab,                          DOOR_SOUND_NORMAL,  0, sDoorAnimTiles_PalletLab, sDoorAnimPalettes_PalletLab},
    {METATILE_FuchsiaCity_Door_Lit,                         DOOR_SOUND_NORMAL,  0, sDoorAnimTiles_FuchsiaLit, sDoorAnimPalettes_Fuchsia},
    {METATILE_FuchsiaCity_Door_Unlit,                       DOOR_SOUND_NORMAL,  0, sDoorAnimTiles_FuchsiaUnlit, sDoorAnimPalettes_Fuchsia},
    {METATILE_ViridianCity_Door,                            DOOR_SOUND_NORMAL,  0, sDoorAnimTiles_Viridian, sDoorAnimPalettes_Viridian},
    {METATILE_PewterCity_Door,                              DOOR_SOUND_NORMAL,  0, sDoorAnimTiles_Pewter, sDoorAnimPalettes_Pewter},
    {METATILE_LavenderTown_Door,                            DOOR_SOUND_NORMAL,  0, sDoorAnimTiles_Lavender, sDoorAnimPalettes_Lavender},
    {METATILE_OlivineCity_Barn_Door,                        DOOR_SOUND_NORMAL,  0, sDoorAnimTiles_Barn, sDoorAnimPalettes_BarnFarm},
    {METATILE_OlivineCity_Farm_Door,                        DOOR_SOUND_NORMAL,  0, sDoorAnimTiles_Violet, sDoorAnimPalettes_BarnFarm},
    {METATILE_OlivineCity_Cianwood_Door,                    DOOR_SOUND_NORMAL,  0, sDoorAnimTiles_Cianwood, sDoorAnimPalettes_Cianwood},
    {METATILE_OlivineCity_Olivine_Door,                     DOOR_SOUND_NORMAL,  0, sDoorAnimTiles_Olivine, sDoorAnimPalettes_Olivine},
    {METATILE_OlivineCity_Lighthouse_Door,                  DOOR_SOUND_NORMAL,  0, sDoorAnimTiles_Lighthouse, sDoorAnimPalettes_Lighthouse},
    {METATILE_Underground_Door_Open,                        DOOR_SOUND_NORMAL,  0, sDoorAnimTiles_GoldenrodUnderground, sDoorAnimPalettes_GoldenrodUnderground},
    {},
};

static void CopyDoorTilesToVram(const struct DoorGraphics *gfx, const struct DoorAnimFrame *frame)
{
    if (gfx->size == 2)
        CpuFastSet(gfx->tiles + frame->offset, (void *)(VRAM + 0x7E00), 0x80);
    else if (gfx->size == 1)
        CpuFastSet(gfx->tiles + frame->offset, (void *)(VRAM + 0x7F00), 0x40);
    else
        CpuFastSet(gfx->tiles + frame->offset, (void *)(VRAM + 0x7F80), 0x20);
}

static void door_build_blockdef(u16 *a, u16 b, const u8 *c)
{
    int i;
    u16 unk;

    for (i = 0; i < 4; i++)
    {
        unk = *(c++) << 12;
        a[i] = unk | (b + i);
    }
    for (; i < 8; i++)
    {
        unk = *(c++) << 12;
        a[i] = unk;
    }
}

static void DrawCurrentDoorAnimFrame(const struct DoorGraphics *gfx, u32 x, u32 y, const u8 *pal)
{
    u16 arr[24];
    
    if (gfx->size == 2)
    {
        door_build_blockdef(&arr[8], 0x3F0, pal);
        DrawDoorMetatileAt(x, y - 1, &arr[8]);
        door_build_blockdef(&arr[8], 0x3F4, pal + 4);
        DrawDoorMetatileAt(x, y, &arr[8]);
        door_build_blockdef(&arr[8], 0x3F8, pal);
        DrawDoorMetatileAt(x + 1, y - 1, &arr[8]);
        door_build_blockdef(&arr[8], 0x3FC, pal + 4);
        DrawDoorMetatileAt(x + 1, y, &arr[8]);
    }
    else if (gfx->size == 1)
    {
        door_build_blockdef(&arr[0], 0x3F8, pal);
        DrawDoorMetatileAt(x, y - 1, &arr[0]);
        door_build_blockdef(&arr[0], 0x3FC, pal + 4);
        DrawDoorMetatileAt(x, y, &arr[0]);
    }
    else
    {
        door_build_blockdef(&arr[0], 0x3FC, pal);
        DrawDoorMetatileAt(x, y, &arr[0]);
    }
}

static void DrawClosedDoorTiles(const struct DoorGraphics *gfx, u32 x, u32 y)
{
    CurrentMapDrawMetatileAt(x, y);

    if (gfx->size >= 1)
    {
        CurrentMapDrawMetatileAt(x, y - 1);
    }

    if (gfx->size == 2)
    {
        CurrentMapDrawMetatileAt(x + 1, y - 1);
        CurrentMapDrawMetatileAt(x + 1, y);
    }
}

static void DrawDoor(const struct DoorGraphics *gfx, const struct DoorAnimFrame *frame, u32 x, u32 y)
{
    if (frame->offset == 0xFFFF)
    {
        DrawClosedDoorTiles(gfx, x, y);
        if (ShouldUseMultiCorridorDoor())
            DrawClosedDoorTiles(gfx, gSpecialVar_0x8004 + 7, gSpecialVar_0x8005 + 7);
    }
    else
    {
        CopyDoorTilesToVram(gfx, frame);
        DrawCurrentDoorAnimFrame(gfx, x, y, gfx->palette);
        if (ShouldUseMultiCorridorDoor())
            DrawCurrentDoorAnimFrame(gfx, gSpecialVar_0x8004 + 7, gSpecialVar_0x8005 + 7, gfx->palette);
    }
}

#define tFramesHi data[0]
#define tFramesLo data[1]
#define tGfxHi data[2]
#define tGfxLo data[3]
#define tFrameId data[4]
#define tCounter data[5]
#define tX data[6]
#define tY data[7]

// Draws a single frame of the door animation, or skips drawing to wait between frames.
// Returns FALSE when the final frame has been reached
static bool32 AnimateDoorFrame(struct DoorGraphics *gfx, struct DoorAnimFrame *frames, s16 *data)
{
    if (tCounter == 0)
        DrawDoor(gfx, &frames[tFrameId], tX, tY);

    if (tCounter == frames[tFrameId].time)
    {
        tCounter = 0;
        tFrameId++;
        if (frames[tFrameId].time == 0)
            return FALSE;
        else
            return TRUE;
    }
    tCounter++;
    return TRUE;
}

static void Task_AnimateDoor(u8 taskId)
{
    u16 *data = gTasks[taskId].data;
    struct DoorAnimFrame *frames = (struct DoorAnimFrame *)(tFramesHi << 16 | tFramesLo);
    struct DoorGraphics *gfx = (struct DoorGraphics *)(tGfxHi << 16 | tGfxLo);

    if (AnimateDoorFrame(gfx, frames, data) == FALSE)
        DestroyTask(taskId);
}

static const struct DoorAnimFrame *GetLastDoorFrame(const struct DoorAnimFrame *frame, const void *unused)
{
    while (frame->time != 0)
        frame++;
    return frame - 1;
}

static const struct DoorGraphics *GetDoorGraphics(const struct DoorGraphics *gfx, u16 metatileNum)
{
    while (gfx->tiles != NULL)
    {
        if (gfx->metatileNum == metatileNum)
            return gfx;
        gfx++;
    }
    return NULL;
}

static s8 StartDoorAnimationTask(const struct DoorGraphics *gfx, const struct DoorAnimFrame *frames, u32 x, u32 y)
{
    if (FuncIsActiveTask(Task_AnimateDoor) == TRUE)
        return -1;
    else
    {
        u8 taskId = CreateTask(Task_AnimateDoor, 0x50);
        s16 *data = gTasks[taskId].data;

        tX = x;
        tY = y;

        tFramesLo = (u32)frames;
        tFramesHi = (u32)frames >> 16;

        tGfxLo = (u32)gfx;
        tGfxHi = (u32)gfx >> 16;

        return taskId;
    }
}

static void DrawClosedDoor(const struct DoorGraphics *gfx, u32 x, u32 y)
{
    DrawClosedDoorTiles(gfx, x, y);
}

static void DrawOpenedDoor(const struct DoorGraphics *gfx, u32 x, u32 y)
{
    gfx = GetDoorGraphics(gfx, MapGridGetMetatileIdAt(x, y));
    if (gfx != NULL)
    {
        if (gfx->size == 2)
            DrawDoor(gfx, GetLastDoorFrame(sBigDoorOpenAnimFrames, sBigDoorOpenAnimFrames), x, y);
        else if (gfx->size == 1)
            DrawDoor(gfx, GetLastDoorFrame(sTallDoorOpenAnimFrames, sTallDoorOpenAnimFrames), x, y);
        else
            DrawDoor(gfx, GetLastDoorFrame(sDoorOpenAnimFrames, sDoorOpenAnimFrames), x, y);
    }
}

static s8 StartDoorOpenAnimation(const struct DoorGraphics *gfx, u32 x, u32 y)
{
    gfx = GetDoorGraphics(gfx, MapGridGetMetatileIdAt(x, y));
    if (gfx == NULL)
    {
        return -1;
    }
    else
    {
        if (gfx->size == 2)
            return StartDoorAnimationTask(gfx, sBigDoorOpenAnimFrames, x, y);
        else if (gfx->size == 1)
            return StartDoorAnimationTask(gfx, sTallDoorOpenAnimFrames, x, y);
        else
            return StartDoorAnimationTask(gfx, sDoorOpenAnimFrames, x, y);
    }
}

static s8 StartDoorCloseAnimation(const struct DoorGraphics *gfx, u32 x, u32 y)
{
    gfx = GetDoorGraphics(gfx, MapGridGetMetatileIdAt(x, y));
    if (gfx == NULL)
    {
        return -1;
    }
    else
    {
        if (gfx->size == 2)
            return StartDoorAnimationTask(gfx, sBigDoorCloseAnimFrames, x, y);
        else if (gfx->size == 1)
            return StartDoorAnimationTask(gfx, sTallDoorCloseAnimFrames, x, y);
        else
            return StartDoorAnimationTask(gfx, sDoorCloseAnimFrames, x, y);
    }
}

static s8 GetDoorSoundType(const struct DoorGraphics *gfx, u32 x, u32 y)
{
    gfx = GetDoorGraphics(gfx, MapGridGetMetatileIdAt(x, y));
    if (gfx == NULL)
        return -1;
    else
        return gfx->sound;
}

// Unused. Debug? Same as FieldAnimateDoorOpen but doesnt return or check if metatile is actually a door
static void Debug_FieldAnimateDoorOpen(u32 x, u32 y)
{
    StartDoorOpenAnimation(sDoorAnimGraphicsTable, x, y);
}

void FieldSetDoorOpened(u32 x, u32 y)
{
    if (MetatileBehavior_IsDoor(MapGridGetMetatileBehaviorAt(x, y)))
        DrawOpenedDoor(sDoorAnimGraphicsTable, x, y);
}

void FieldSetDoorClosed(u32 x, u32 y)
{
    if (MetatileBehavior_IsDoor(MapGridGetMetatileBehaviorAt(x, y)))
        DrawClosedDoor(sDoorAnimGraphicsTable, x, y);
}

s8 FieldAnimateDoorClose(u32 x, u32 y)
{
    if (!MetatileBehavior_IsDoor(MapGridGetMetatileBehaviorAt(x, y)))
        return -1;
    else
        return StartDoorCloseAnimation(sDoorAnimGraphicsTable, x, y);
}

s8 FieldAnimateDoorOpen(u32 x, u32 y)
{
    if (!MetatileBehavior_IsDoor(MapGridGetMetatileBehaviorAt(x, y)))
        return -1;
    else
        return StartDoorOpenAnimation(sDoorAnimGraphicsTable, x, y);
}

bool8 FieldIsDoorAnimationRunning(void)
{
    return FuncIsActiveTask(Task_AnimateDoor);
}

u32 GetDoorSoundEffect(u32 x, u32 y)
{
    int sound = GetDoorSoundType(sDoorAnimGraphicsTable, x, y);
    
    if (sound == DOOR_SOUND_NORMAL)
        return SE_RG_DOOR;
    else if (sound == DOOR_SOUND_SLIDING)
        return SE_SLIDING_DOOR;
    else if (sound == DOOR_SOUND_ARENA)
        return SE_REPEL;
    else
        return SE_DOOR;
}

// Opens the Battle Tower multi partner's door in sync with the player's door
static bool8 ShouldUseMultiCorridorDoor(void)
{
    if (FlagGet(FLAG_ENABLE_MULTI_CORRIDOR_DOOR))
    {
        if (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(BATTLE_FRONTIER_BATTLE_TOWER_MULTI_CORRIDOR) 
            && gSaveBlock1Ptr->location.mapNum == MAP_NUM(BATTLE_FRONTIER_BATTLE_TOWER_MULTI_CORRIDOR))
        {
            return TRUE;
        }
    }
    return FALSE;
}
