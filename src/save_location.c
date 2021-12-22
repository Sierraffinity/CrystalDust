#include "global.h"
#include "save_location.h"
#include "constants/maps.h"

static bool32 IsCurMapInLocationList(const u16 *list)
{
    s32 i;
    u16 locSum = (gSaveBlock1Ptr->location.mapGroup << 8) + (gSaveBlock1Ptr->location.mapNum);

    for (i = 0; list[i] != 0xFFFF; i++)
    {
        if (list[i] == locSum)
            return TRUE;
    }

    return FALSE;
}

static const u16 sSaveLocationPokeCenterList[] =
{
    MAP_CHERRYGROVE_CITY_POKEMON_CENTER_1F,
    MAP_CHERRYGROVE_CITY_POKEMON_CENTER_2F,
    MAP_VIOLET_CITY_POKEMON_CENTER_1F,
    MAP_VIOLET_CITY_POKEMON_CENTER_2F,
    MAP_ROUTE32_POKEMON_CENTER_1F,
    MAP_ROUTE32_POKEMON_CENTER_2F,
    MAP_AZALEA_TOWN_POKEMON_CENTER_1F,
    MAP_AZALEA_TOWN_POKEMON_CENTER_2F,
    MAP_GOLDENROD_CITY_POKEMON_CENTER_1F,
    MAP_GOLDENROD_CITY_POKEMON_CENTER_2F,
    MAP_ECRUTEAK_CITY_POKEMON_CENTER_1F,
    MAP_ECRUTEAK_CITY_POKEMON_CENTER_2F,
    MAP_OLIVINE_CITY_POKEMON_CENTER_1F,
    MAP_OLIVINE_CITY_POKEMON_CENTER_2F,
    MAP_CIANWOOD_CITY_POKEMON_CENTER_1F,
    MAP_CIANWOOD_CITY_POKEMON_CENTER_2F,
    MAP_MAHOGANY_TOWN_POKEMON_CENTER_1F,
    MAP_MAHOGANY_TOWN_POKEMON_CENTER_2F,
    MAP_BLACKTHORN_CITY_POKEMON_CENTER_1F,
    MAP_BLACKTHORN_CITY_POKEMON_CENTER_2F,
    MAP_BATTLE_FRONTIER_POKEMON_CENTER_1F,
    MAP_BATTLE_FRONTIER_POKEMON_CENTER_2F,
    MAP_BATTLE_COLOSSEUM_2P,
    MAP_TRADE_CENTER,
    MAP_RECORD_CORNER,
    MAP_BATTLE_COLOSSEUM_4P,
    0xFFFF,
};

static bool32 IsCurMapPokeCenter(void)
{
    return IsCurMapInLocationList(sSaveLocationPokeCenterList);
}

static const u16 sSaveLocationReloadLocList[] = // There's only 1 location, and it's presumed its for the save reload feature for battle tower.
{
    MAP_BATTLE_FRONTIER_BATTLE_TOWER_LOBBY,
    0xFFFF,
};

static bool32 IsCurMapReloadLocation(void)
{
    return IsCurMapInLocationList(sSaveLocationReloadLocList);
}

// Nulled out list. Unknown what this would have been.
static const u16 sUnknown_0861440E[] =
{
    0xFFFF,
};

static bool32 sub_81AFCEC(void)
{
    return IsCurMapInLocationList(sUnknown_0861440E);
}

static void TrySetPokeCenterWarpStatus(void)
{
    if (IsCurMapPokeCenter() == FALSE)
        gSaveBlock2Ptr->specialSaveWarpFlags &= ~(POKECENTER_SAVEWARP);
    else
        gSaveBlock2Ptr->specialSaveWarpFlags |= POKECENTER_SAVEWARP;
}

static void TrySetReloadWarpStatus(void)
{
    if (!IsCurMapReloadLocation())
        gSaveBlock2Ptr->specialSaveWarpFlags &= ~(LOBBY_SAVEWARP);
    else
        gSaveBlock2Ptr->specialSaveWarpFlags |= LOBBY_SAVEWARP;
}

// this function definitely sets a warp status, but because the list is empty, it's unknown what this does yet.
static void sub_81AFD5C(void)
{
    if (!sub_81AFCEC())
        gSaveBlock2Ptr->specialSaveWarpFlags &= ~(UNK_SPECIAL_SAVE_WARP_FLAG_3);
    else
        gSaveBlock2Ptr->specialSaveWarpFlags |= UNK_SPECIAL_SAVE_WARP_FLAG_3;
}

void TrySetMapSaveWarpStatus(void)
{
    TrySetPokeCenterWarpStatus();
    TrySetReloadWarpStatus();
    sub_81AFD5C();
}

// In FRLG, only 0x1, 0x10, and 0x20 are set when the pokedex is received
// 0x2, 0x4, 0x8, and 0x8000 are instead set by SetPostgameFlags
// These flags are read by Pokemon Colosseum/XD for linking. XD Additionally requires FLAG_SYS_GAME_CLEAR
void SetUnlockedPokedexFlags(void)
{
    gSaveBlock2Ptr->gcnLinkFlags |= 0x8000;
    gSaveBlock2Ptr->gcnLinkFlags |= 0x1;
    gSaveBlock2Ptr->gcnLinkFlags |= 0x2;
    gSaveBlock2Ptr->gcnLinkFlags |= 0x4;
    gSaveBlock2Ptr->gcnLinkFlags |= 0x10;
    gSaveBlock2Ptr->gcnLinkFlags |= 0x20;
    gSaveBlock2Ptr->gcnLinkFlags |= 0x8;
}

void SetChampionSaveWarp(void)
{
    gSaveBlock2Ptr->specialSaveWarpFlags |= CHAMPION_SAVEWARP;
}
