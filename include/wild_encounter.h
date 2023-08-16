#ifndef GUARD_WILD_ENCOUNTER_H
#define GUARD_WILD_ENCOUNTER_H

#include "constants/day_night.h"

#define LAND_WILD_COUNT     12
#define WATER_WILD_COUNT    5
#define ROCK_WILD_COUNT     5
#define FISH_WILD_COUNT     10

struct WildPokemon
{
    u8 minLevel;
    u8 maxLevel;
    u16 species;
};

struct WildPokemonInfo
{
    u8 encounterRate;
    const struct WildPokemon *wildPokemon[TIMES_OF_DAY_COUNT];
};

struct WildPokemonHeader
{
    u8 mapGroup;
    u8 mapNum;
    const struct WildPokemonInfo *landMonsInfo;
    const struct WildPokemonInfo *waterMonsInfo;
    const struct WildPokemonInfo *rockSmashMonsInfo;
    const struct WildPokemonInfo *fishingMonsInfo;
    const struct WildPokemonInfo *headbuttMonsInfo;
};

extern const struct WildPokemonHeader gWildMonHeaders[];

void DisableWildEncounters(bool8 disabled);
bool8 StandardWildEncounter(u16 currMetaTileBehavior, u16 previousMetaTileBehavior);
void ScrSpecial_RockSmashWildEncounter(void);
bool8 SweetScentWildEncounter(void);
bool8 DoesCurrentMapHaveFishingMons(void);
void FishingWildEncounter(u8 rod, s16 outbreakCaught);
u16 GetLocalWildMon(bool8 *isWaterMon);
u16 GetLocalWaterMon(void);
bool8 UpdateRepelCounter(void);
u16 GetMapWildMonFromIndex(u8, u8, u8);
u8 ChooseWildMonIndex_Land(void);
u8 ChooseWildMonLevelWithAbility(const struct WildPokemon *wildPokemon, bool8 useAbility);
u8 GetUnownLetterByPersonalityLoByte(u32 personality);
void Debug_StartWildBattle(u16 species, u8 level, u32 flags, bool8 forceShiny);
void Debug_StartWildBattleWithMoves(u16 species, u8 level, u32 flags, bool8 forceShiny, u16 move1, u16 move2, u16 move3, u16 move4);
bool8 DoMassOutbreakEncounterTest(void);

#endif // GUARD_WILD_ENCOUNTER_H
