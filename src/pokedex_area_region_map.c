#include "global.h"
#include "main.h"
#include "menu.h"
#include "bg.h"
#include "malloc.h"
#include "palette.h"
#include "region_map.h"
#include "pokedex_area_region_map.h"

static EWRAM_DATA u8 *sPokedexAreaMapBgNum = NULL;

void LoadPokedexAreaMapGfx(const struct PokedexAreaMapTemplate *template, bool8* permissions, u8 region)
{
    u32 size;
    void *ptr;
    FreePokedexAreaMapBgNum();
    sPokedexAreaMapBgNum = Alloc(4);
    DecompressAndCopyTileDataToVram(template->bg, GetRegionMapTileset(), 0, template->offset, 0);
    ptr = malloc_and_decompress(GetRegionMapTilemap(region), &size);
    ChangeDecompressedRegionMapGfx(ptr, permissions);
    copy_decompressed_tile_data_to_vram(template->bg, ptr, size, 0, 1);
    sub_8199D3C(ptr, template->offset, 64, 64, TRUE);
    Free(ptr);
    CpuCopy32(GetRegionMapPalette(), &gPlttBufferUnfaded[0x70], 0x60);
    *sPokedexAreaMapBgNum = template->bg;
}

bool32 sub_81C4E90(void)
{
    return FreeTempTileDataBuffersIfPossible();
}

void FreePokedexAreaMapBgNum(void)
{
    if (sPokedexAreaMapBgNum != NULL)
        FREE_AND_SET_NULL(sPokedexAreaMapBgNum);
}

void PokedexAreaMapChangeBgY(u32 a0)
{
    ChangeBgY(*sPokedexAreaMapBgNum, a0 * 0x100, 0);
}
