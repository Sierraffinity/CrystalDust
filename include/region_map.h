#ifndef GUARD_REGION_MAP_H
#define GUARD_REGION_MAP_H

#include "bg.h"

// Exported type declarations

enum
{
    INPUT_EVENT_NONE,
    INPUT_EVENT_MOVE_START,
    INPUT_EVENT_MOVE_CONT,
    INPUT_EVENT_MOVE_END,
    INPUT_EVENT_A_BUTTON,
    INPUT_EVENT_B_BUTTON,
    INPUT_EVENT_LANDMARK,
    INPUT_EVENT_SWITCH
};

enum {
    MAPSECTYPE_NONE,
    MAPSECTYPE_PLAIN,
    MAPSECTYPE_CITY_CANFLY,
    MAPSECTYPE_CITY_CANTFLY,
    MAPSECTYPE_BATTLE_FRONTIER
};

enum {
    REGION_JOHTO,
    REGION_KANTO,
    REGION_SEVII1,
    REGION_SEVII2,
    REGION_SEVII3
};

struct RegionMap {
    u8 primaryMapSecId;
    u8 secondaryMapSecId;
    u8 primaryWindowId;
    u8 secondaryWindowId;
    u8 primaryMapSecStatus;
    u8 secondaryMapSecStatus;
    u8 posWithinMapSec;
    u8 currentRegion;
    bool8 canChangeRegion;
    u8 primaryMapSecName[0x14];
    u8 secondaryMapSecName[0x14];
    u8 (*inputCallback)(void);
    u8 spriteIds[20];
    u16 regionNameCurveTileTag;
    u16 regionNameMainTileTag;
    u16 dotsTileTag;
    u16 miscSpritesPaletteTag;
    s32 unk_03c;
    s32 unk_040;
    s32 unk_044;
    s32 unk_048;
    s32 unk_04c;
    s32 unk_050;
    s16 cursorPosX;
    s16 cursorPosY;
    u16 cursorTileTag;
    u16 cursorPaletteTag;
    s16 scrollX;
    s16 scrollY;
    s16 unk_060;
    s16 unk_062;
    u16 unk_06e;
    u16 playerIconTileTag;
    u16 playerIconPaletteTag;
    u16 playerIconSpritePosX;
    u16 playerIconSpritePosY;
    u8 initStep;
    s8 cursorMovementFrameCounter;
    s8 cursorDeltaX;
    s8 cursorDeltaY;
    bool8 needUpdateVideoRegs;
    bool8 blinkPlayerIcon;
    bool8 playerIsInCave;
    u8 bgNum;
    u8 charBaseIdx;
    u8 mapBaseIdx;
    bool8 bgManaged;
    s8 xOffset;
    u32 alignFiller;
    u8 cursorImage[0x100];
}; // size = 0x884

struct RegionMapLocation
{
    u8 x;
    u8 y;
    u8 width;
    u8 height;
    const u8 *name;
};

// Exported RAM declarations

// Exported ROM declarations
extern const struct RegionMapLocation gRegionMapEntries[];

void sub_8122CF8(struct RegionMap *regionMap, const struct BgTemplate *template, s8 xOffset);
bool8 sub_8122DB0(void);
void UpdateRegionMapVideoRegs(void);
void InitRegionMap(struct RegionMap *regionMap, s8 xOffset);
u8 sub_81230AC(void);
bool8 sub_8123514(void);
void FreeRegionMapResources(void);
u16 GetRegionMapSectionIdAt(u16 x, u16 y);
void CreateRegionMapPlayerIcon(u16 x, u16 y);
void CreateRegionMapCursor(u16 tileTag, u16 paletteTag, bool8 visible);
u8 *GetMapName(u8 *, u16, u16);
bool32 sub_8124668(u8 mapSecId);
u8 *sub_81245DC(u8 *dest, u16 mapSecId);
u8 *sub_8124610(u8 *dest, u16 mapSecId);
u8 GetCurrentRegion(void);
void ShowRegionMapCursorSprite(void);
void HideRegionMapCursorSprite(void);
void CreateRegionMapName(u16 tileTagCurve, u16 tileTagMain);
void CreateSecondaryLayerDots(u16 tileTag, u16 paletteTag);

#endif //GUARD_REGION_MAP_H
