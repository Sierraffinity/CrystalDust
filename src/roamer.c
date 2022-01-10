#include "global.h"
#include "event_data.h"
#include "pokemon.h"
#include "random.h"
#include "roamer.h"
#include "constants/maps.h"

enum
{
    MAP_GRP = 0, // map group
    MAP_NUM = 1, // map number
};

EWRAM_DATA static u8 sLocationHistory[NUM_ROAMERS][3][2] = {0};
EWRAM_DATA static u8 sRoamerLocation[NUM_ROAMERS][2] = {0};

static const u8 sRoamerLocations[][5] =
{
    { MAP_NUM(ROUTE29), MAP_NUM(ROUTE30), MAP_NUM(ROUTE46), 0xFF, 0xFF },
    { MAP_NUM(ROUTE30), MAP_NUM(ROUTE29), MAP_NUM(ROUTE31), 0xFF, 0xFF },
    { MAP_NUM(ROUTE31), MAP_NUM(ROUTE30), MAP_NUM(ROUTE32), MAP_NUM(ROUTE36), 0xFF },
    { MAP_NUM(ROUTE32), MAP_NUM(ROUTE36), MAP_NUM(ROUTE31), MAP_NUM(ROUTE33), 0xFF },
    { MAP_NUM(ROUTE33), MAP_NUM(ROUTE32), MAP_NUM(ROUTE34), 0xFF, 0xFF },
    { MAP_NUM(ROUTE34), MAP_NUM(ROUTE33), MAP_NUM(ROUTE35), 0xFF, 0xFF },
    { MAP_NUM(ROUTE35), MAP_NUM(ROUTE34), MAP_NUM(ROUTE36), 0xFF, 0xFF },
    { MAP_NUM(ROUTE36), MAP_NUM(ROUTE35), MAP_NUM(ROUTE31), MAP_NUM(ROUTE32), MAP_NUM(ROUTE37) },
    { MAP_NUM(ROUTE37), MAP_NUM(ROUTE36), MAP_NUM(ROUTE38), MAP_NUM(ROUTE42), 0xFF },
    { MAP_NUM(ROUTE38), MAP_NUM(ROUTE37), MAP_NUM(ROUTE39), MAP_NUM(ROUTE42), 0xFF },
    { MAP_NUM(ROUTE39), MAP_NUM(ROUTE38), 0xFF, 0xFF, 0xFF },
    { MAP_NUM(ROUTE42), MAP_NUM(ROUTE43), MAP_NUM(ROUTE44), MAP_NUM(ROUTE37), MAP_NUM(ROUTE38) },
    { MAP_NUM(ROUTE43), MAP_NUM(ROUTE42), MAP_NUM(ROUTE44), 0xFF, 0xFF },
    { MAP_NUM(ROUTE44), MAP_NUM(ROUTE42), MAP_NUM(ROUTE43), MAP_NUM(ROUTE45), 0xFF },
    { MAP_NUM(ROUTE45), MAP_NUM(ROUTE44), MAP_NUM(ROUTE45), 0xFF, 0xFF },
    { MAP_NUM(ROUTE46), MAP_NUM(ROUTE45), MAP_NUM(ROUTE29), 0xFF, 0xFF },
    { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF },
};

void ClearRoamerData(void)
{
    memset(&gSaveBlock1Ptr->roamer, 0, sizeof(gSaveBlock1Ptr->roamer));
}

void ClearRoamerLocationData(void)
{
    u32 i;
    u32 j;

    for (j = 0; j < NUM_ROAMERS; j++)
    {
        for (i = 0; i < 3; i++)
        {
            sLocationHistory[j][i][MAP_GRP] = 0;
            sLocationHistory[j][i][MAP_NUM] = 0;
        }
    }

    for(i = 0; i < NUM_ROAMERS; i++)
    {
        sRoamerLocation[i][MAP_GRP] = 0;
        sRoamerLocation[i][MAP_NUM] = 0;
    }
}

static void CreateInitialRoamerMon()
{
    u32 i;
    u16 species = SPECIES_RAIKOU;
    for(i = 0; i < NUM_ROAMERS; i++)
    {
        species += i;
        
        CreateMon(&gEnemyParty[0], species, 40, 0x20, 0, 0, OT_ID_PLAYER_ID, 0);
        (&gSaveBlock1Ptr->roamer[i])->status = 0;
        (&gSaveBlock1Ptr->roamer[i])->active = TRUE;
        (&gSaveBlock1Ptr->roamer[i])->ivs = GetMonData(&gEnemyParty[0], MON_DATA_IVS);
        (&gSaveBlock1Ptr->roamer[i])->personality = GetMonData(&gEnemyParty[0], MON_DATA_PERSONALITY);
        (&gSaveBlock1Ptr->roamer[i])->hp = GetMonData(&gEnemyParty[0], MON_DATA_MAX_HP);
        sRoamerLocation[i][MAP_GRP] = 0;
        sRoamerLocation[i][MAP_NUM] = sRoamerLocations[Random() % (ARRAY_COUNT(sRoamerLocations) - 1)][0];
    }
}

void InitRoamer(void)
{
    ClearRoamerData();
    ClearRoamerLocationData();
    CreateInitialRoamerMon();
}

void RegenerateRaikou(void)
{
    struct Pokemon *mon;
    struct Roamer *roamer = &gSaveBlock1Ptr->roamer[ROAMER_RAIKOU];

    CreateMonWithIVsPersonality(mon, SPECIES_RAIKOU, 40, roamer->ivs, roamer->personality);

    roamer->hp = GetMonData(&mon, MON_DATA_MAX_HP);
    roamer->status = 0;
    roamer->active = TRUE;
}

void RegenerateEntei(void)
{
    struct Pokemon *mon;
    struct Roamer *roamer = &gSaveBlock1Ptr->roamer[ROAMER_ENTEI];

    CreateMonWithIVsPersonality(mon, SPECIES_ENTEI, 40, roamer->ivs, roamer->personality);

    roamer->hp = GetMonData(&mon, MON_DATA_MAX_HP);
    roamer->status = 0;
    roamer->active = TRUE;
}

void IsRaikouActive(void)
{
    gSpecialVar_Result = gSaveBlock1Ptr->roamer[ROAMER_RAIKOU].active;
}

void IsEnteiActive(void)
{
    gSpecialVar_Result = gSaveBlock1Ptr->roamer[ROAMER_ENTEI].active;
}

void UpdateLocationHistoryForRoamer(void)
{
    u32 i;
    for(i = 0; i < NUM_ROAMERS; i++)
    {
        sLocationHistory[i][2][MAP_GRP] = sLocationHistory[i][1][MAP_GRP];
        sLocationHistory[i][2][MAP_NUM] = sLocationHistory[i][1][MAP_NUM];

        sLocationHistory[i][1][MAP_GRP] = sLocationHistory[i][0][MAP_GRP];
        sLocationHistory[i][1][MAP_NUM] = sLocationHistory[i][0][MAP_NUM];

        sLocationHistory[i][0][MAP_GRP] = gSaveBlock1Ptr->location.mapGroup;
        sLocationHistory[i][0][MAP_NUM] = gSaveBlock1Ptr->location.mapNum;
    }
}

void RoamerMoveToOtherLocationSet(void)
{
    u32 i;
    u8 mapNum = 0;

    for(i = 0; i < NUM_ROAMERS; i++)
    {
        struct Roamer *roamer = &gSaveBlock1Ptr->roamer[i];

        if (!roamer->active)
            break;

        sRoamerLocation[i][MAP_GRP] = 0;

        while (1)
        {
            mapNum = sRoamerLocations[Random() % (ARRAY_COUNT(sRoamerLocations) - 1)][0];
            if (sRoamerLocation[i][MAP_NUM] != mapNum)
            {
                sRoamerLocation[i][MAP_NUM] = mapNum;
                break;
            }
        }
    }
}

void RoamerMove(void)
{
    u32 i;
    u8 locSet = 0;

    if ((Random() % 16) == 0)
    {
        RoamerMoveToOtherLocationSet();
    }
    else
    {
        for(i = 0; i < NUM_ROAMERS; i++)
        {
            struct Roamer *roamer = &gSaveBlock1Ptr->roamer[i];

            if (!roamer->active)
                break;

            while (locSet < (ARRAY_COUNT(sRoamerLocations) - 1))
            {
                if (sRoamerLocation[i][MAP_NUM] == sRoamerLocations[locSet][0])
                {
                    u8 mapNum;
                    while (1)
                    {
                        mapNum = sRoamerLocations[locSet][(Random() % 5) + 1];
                        if (!(sLocationHistory[i][2][MAP_GRP] == 0 && sLocationHistory[i][2][MAP_NUM] == mapNum) && mapNum != 0xFF)
                            break;
                    }
                    sRoamerLocation[i][MAP_NUM] = mapNum;
                    break;
                }
                locSet++;
            }
        }
    }
}

u16 IsRoamerAt(u8 mapGroup, u8 mapNum)
{
    u32 i;
    u16 species = SPECIES_BLISSEY;
    for (i = 0; i < NUM_ROAMERS; i++)
    {
        struct Roamer *roamer = &gSaveBlock1Ptr->roamer[i];

        if (roamer->active && mapGroup == sRoamerLocation[i][MAP_GRP] && mapNum == sRoamerLocation[i][MAP_NUM])
            species += (i + 1);
    }
    return species; 
    // species will == SPECIES_SUICUNE if both Entei and Raikou are present on the route.
    // If only one, species will == the SPECIES_ of that one.
    // If neither, species will == SPECIES_BLISSEY.
}

void CreateRoamerMonInstance(u16 species)
{
    struct Pokemon *mon;
    struct Roamer *roamer;
    u32 whichRoamer;
    u32 status;

    if(species == SPECIES_SUICUNE) // both roamers on route, choose one
    {
        whichRoamer = (Random() % 2);
        species = SPECIES_RAIKOU + whichRoamer;
    }
    else if(species == SPECIES_RAIKOU)
    {
        whichRoamer = ROAMER_RAIKOU;
    }
    else
    {
        whichRoamer = ROAMER_ENTEI;
    }

    mon = &gEnemyParty[0];
    ZeroEnemyPartyMons();
    roamer = &gSaveBlock1Ptr->roamer[whichRoamer];
    status = gSaveBlock1Ptr->roamer[whichRoamer].status;
    CreateMonWithIVsPersonality(mon, species, 40, roamer->ivs, roamer->personality);
    SetMonData(mon, MON_DATA_STATUS, &status);
    SetMonData(mon, MON_DATA_HP, &gSaveBlock1Ptr->roamer[whichRoamer].hp);
}

bool8 TryStartRoamerEncounter(void)
{
    u16 species = IsRoamerAt(gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum);
    if(species == SPECIES_BLISSEY) // a roamer is not present
    {
        return FALSE;
    }
    if ((Random() % 4) == 0) // a roamer is present
    {
        CreateRoamerMonInstance(species);
        return TRUE;
    }
}

void UpdateRoamerHPStatus(struct Pokemon *mon)
{
    u32 whichRoamer;
    u16 species = GetMonData(mon, MON_DATA_SPECIES);

    if(species == SPECIES_RAIKOU)
        whichRoamer = ROAMER_RAIKOU;
    else
        whichRoamer = ROAMER_ENTEI;

    (&gSaveBlock1Ptr->roamer[whichRoamer])->hp = GetMonData(mon, MON_DATA_HP);
    (&gSaveBlock1Ptr->roamer[whichRoamer])->status = GetMonData(mon, MON_DATA_STATUS);

    RoamerMoveToOtherLocationSet();
}

void SetRoamerInactive(struct Pokemon *mon)
{
    u32 whichRoamer;
    u16 species = GetMonData(mon, MON_DATA_SPECIES);

    if(species == SPECIES_RAIKOU)
        whichRoamer = ROAMER_RAIKOU;
    else
        whichRoamer = ROAMER_ENTEI;

    struct Roamer *roamer = &gSaveBlock1Ptr->roamer[whichRoamer];
    roamer->active = FALSE;
}

void GetRoamerLocation(u16 species, u8 *mapGroup, u8 *mapNum)
{
    u32 whichRoamer;

    if(species == SPECIES_RAIKOU)
        whichRoamer = ROAMER_RAIKOU;
    else
        whichRoamer = ROAMER_ENTEI;
    
    *mapGroup = sRoamerLocation[whichRoamer][MAP_GRP];
    *mapNum = sRoamerLocation[whichRoamer][MAP_NUM];
}
