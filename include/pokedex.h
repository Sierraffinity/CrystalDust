#ifndef GUARD_POKEDEX_H
#define GUARD_POKEDEX_H

extern u8 gUnusedPokedexU8;
extern void (*gPokedexVBlankCB)(void);

enum
{
    DEX_MODE_JOHTO,
    DEX_MODE_NATIONAL
};

enum
{
    FLAG_GET_SEEN,
    FLAG_GET_CAUGHT,
    FLAG_SET_SEEN,
    FLAG_SET_CAUGHT
};

struct PokedexEntry
{
    /*0x00*/ u8 categoryName[12];
    /*0x0C*/ u16 height; //in decimeters
    /*0x0E*/ u16 weight; //in hectograms
    /*0x10*/ const u8 *description;
             const u8 *pokedexShowEntry;
    /*0x14*/ u8 unused;
    /*0x16*/ u16 pokemonScale;
    /*0x18*/ u16 pokemonOffset;
    /*0x1A*/ u16 trainerScale;
    /*0x1C*/ u16 trainerOffset;
};  /*size = 0x20*/

void ResetPokedex(void);
u16 GetPokedexHeightWeight(u16 dexNum, u8 data);
u16 GetNationalPokedexCount(u8);
u16 GetJohtoPokedexCount(u8);
u8 DisplayCaughtMonDexPage(u16 dexNum, u32 otId, u32 personality);
s8 GetSetPokedexFlag(u16 nationalNum, u8 caseId);
u16 CreateMonSpriteFromNationalDexNumber(u16, s16, s16, u16);
bool16 HasAllJohtoMons(void);
void ResetPokedexScrollPositions(void);
bool16 HasAllMons(void);
void CB2_OpenPokedex(void);
const u8 *sub_80C0620(u16 dexNum);

extern const struct PokedexEntry gPokedexEntries[];

#endif // GUARD_POKEDEX_H
