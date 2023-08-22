#ifndef GUARD_REGION_MAP_H
#define GUARD_REGION_MAP_H

#include "bg.h"

#define CORNER_BUTTON_X 21
#define CORNER_BUTTON_Y 13

#define MAP_NAME_LENGTH 16

// Exported type declarations
enum
{
    MAP_INPUT_NONE,
    MAP_INPUT_MOVE_START,
    MAP_INPUT_MOVE_CONT,
    MAP_INPUT_MOVE_END,
    MAP_INPUT_A_BUTTON,
    MAP_INPUT_SWITCH,
    MAP_INPUT_CANCEL
};

enum {
    MAPSECTYPE_NONE,
    MAPSECTYPE_ROUTE,
    MAPSECTYPE_VISITED,
    MAPSECTYPE_NOT_VISITED,
    MAPSECTYPE_BATTLE_FRONTIER
};

enum {
    MAPPERM_CLOSE,
    MAPPERM_SWITCH,
    MAPPERM_LANDMARKINFO,
    MAPPERM_FLY
};

enum {
    REGION_JOHTO,
    REGION_KANTO,
    REGION_SEVII1,
    REGION_SEVII2,
    REGION_SEVII3
};

enum {
    MAPMODE_POKEGEAR,
    MAPMODE_FIELD,
    MAPMODE_FLY
};

enum {
    LANDMARK_STATE_NONE,
    LANDMARK_STATE_INFO,
    LANDMARK_STATE_CLOSE,
    LANDMARK_STATE_SWITCH
};

struct RegionMap {
    u8 primaryMapSecId;
    u8 secondaryMapSecId;
    u8 primaryWindowId;
    u8 secondaryWindowId;
    u8 primaryMapSecStatus;
    u8 secondaryMapSecStatus;
    u8 posWithinMapSec;
    u8 enteredSecondary;
    u8 currentRegion;
    u8 mapMode;
    bool8 permissions[4];
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
    s8 yOffset;
    bool8 onButton;
    u8 ALIGNED(4) cursorImage[0x100];
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
void InitRegionMapData(struct RegionMap *regionMap, const struct BgTemplate *template, u8 mapMode, s8 xOffset, s8 yOffset);
bool8 ChangeDecompressedRegionMapGfx(u16* ptr, bool8* permissions);
bool8 LoadRegionMapGfx(bool8 shouldBuffer);
bool8 LoadRegionMapGfx_Pt2(void);
void UpdateRegionMapVideoRegs(void);
void InitRegionMap(struct RegionMap *regionMap, u8 mode, s8 xOffset, s8 yOffset);
u8 DoRegionMapInputCallback(void);
bool8 UpdateRegionMapZoom(void);
void FreeRegionMapResources(void);
bool8 MapsecWasVisited(u16 mapSecId);
u16 GetRegionMapSectionIdAt(u16 x, u16 y, u8 region);
void CreateRegionMapPlayerIcon(u16 x, u16 y);
void CreateRegionMapCursor(u16 tileTag, u16 paletteTag, bool8 visible);
bool32 IsEventIslandMapSecId(u8 mapSecId);
u8 *GetMapName(u8 *, u16, u16);
u8 *GetMapNameHandleFerrySecretBase(u8 *dest, u16 mapSecId);
u8 *GetMapNameForSummaryScreen(u8 *dest, u16 mapSecId);
u8 *GetMapNameHandleSpecialMaps(u8 *dest, u16 mapSecId);
u8 GetMapRegion(u16 mapSectionId);
u8 GetCurrentRegion(void);
void ShowRegionMapCursorSprite(void);
void HideRegionMapCursorSprite(void);
void CreateRegionMapName(u16 tileTagCurve, u16 tileTagMain);
void CreateSecondaryLayerDots(u16 tileTag, u16 paletteTag);
u16 CorrectSpecialMapSecId(u16 mapSecId);
void ShowRegionMapForPokedexAreaScreen(struct RegionMap *regionMap);
void PokedexAreaScreen_UpdateRegionMapVariablesAndVideoRegs(s16 x, s16 y);
void CB2_OpenFlyMap(void);
bool8 IsRegionMapZoomed(void);
void TrySetPlayerIconBlink(void);
const u16 *GetRegionMapPalette(void);
const u32 *GetRegionMapTileset(void);
const u32 *GetRegionMapTilemap(u8 region);
void BlendRegionMap(u16 color, u32 coeff);
void SetRegionMapDataForZoom(void);
void PlaySEForSelectedMapsec(void);
u8 GetSelectedMapsecLandmarkState(void);

extern const struct RegionMapLocation gRegionMapEntries[];

#endif //GUARD_REGION_MAP_H
