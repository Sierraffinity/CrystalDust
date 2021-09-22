#include "global.h"
#include "clock.h"
#include "event_data.h"
#include "fieldmap.h"
#include "field_camera.h"
#include "field_player_avatar.h"
#include "item.h"
#include "constants/event_bg.h"
#include "constants/fruit_trees.h"
#include "constants/items.h"
#include "constants/metatile_labels.h"

// Fruit tree IDs are 1-indexed so field_control_avatar code doesn't have a fit
// with a "NULL script pointer" (AKA zero in the ID field)

static const u16 sFruitTrees[] = 
{
    [FRUIT_TREE_ROUTE_29 - 1]       = ITEM_ORAN_BERRY,
    [FRUIT_TREE_ROUTE_30_1 - 1]     = ITEM_ORAN_BERRY,
    [FRUIT_TREE_ROUTE_30_2 - 1]     = ITEM_PECHA_BERRY,
    [FRUIT_TREE_ROUTE_31 - 1]       = ITEM_PERSIM_BERRY,
    [FRUIT_TREE_VIOLET_CITY - 1]    = ITEM_CHERI_BERRY,
    [FRUIT_TREE_ROUTE_33 - 1]       = ITEM_PECHA_BERRY,
    [FRUIT_TREE_AZALEA_TOWN - 1]    = ITEM_WHT_APRICORN,
    [FRUIT_TREE_ROUTE_35 - 1]       = ITEM_LEPPA_BERRY,
    [FRUIT_TREE_ROUTE_36 - 1]       = ITEM_RAWST_BERRY,
    [FRUIT_TREE_ROUTE_46_1 - 1]     = ITEM_ORAN_BERRY,
    [FRUIT_TREE_ROUTE_46_2 - 1]     = ITEM_CHERI_BERRY,
    [FRUIT_TREE_ROUTE_37_1 - 1]     = ITEM_RED_APRICORN,   // Westernmost tree
    [FRUIT_TREE_ROUTE_37_2 - 1]     = ITEM_BLK_APRICORN,   // Middle tree
    [FRUIT_TREE_ROUTE_37_3 - 1]     = ITEM_BLU_APRICORN,   // Easternmost tree
    [FRUIT_TREE_ROUTE_38 - 1]       = ITEM_ORAN_BERRY,
    [FRUIT_TREE_ROUTE_39 - 1]       = ITEM_CHESTO_BERRY,
    [FRUIT_TREE_ROUTE_42_1 - 1]     = ITEM_PNK_APRICORN,   // Westernmost tree
    [FRUIT_TREE_ROUTE_42_2 - 1]     = ITEM_GRN_APRICORN,   // Middle tree
    [FRUIT_TREE_ROUTE_42_3 - 1]     = ITEM_YLW_APRICORN,   // Easternmost tree
    [FRUIT_TREE_ROUTE_43 - 1]       = ITEM_PERSIM_BERRY,
    [FRUIT_TREE_ROUTE_44 - 1]       = ITEM_ASPEAR_BERRY,
    [FRUIT_TREE_ROUTE_45 - 1]       = ITEM_LEPPA_BERRY,
    [FRUIT_TREE_PEWTER_CITY_1 - 1]  = ITEM_CHESTO_BERRY,   // Westernmost tree
    [FRUIT_TREE_PEWTER_CITY_2 - 1]  = ITEM_RAWST_BERRY,    // Easternmost tree
    [FRUIT_TREE_FUCHSIA_CITY - 1]   = ITEM_ASPEAR_BERRY,
    [FRUIT_TREE_ROUTE_1 - 1]        = ITEM_PERSIM_BERRY,
    [FRUIT_TREE_ROUTE_2 - 1]        = ITEM_PECHA_BERRY,
    [FRUIT_TREE_ROUTE_8 - 1]        = ITEM_CHERI_BERRY,
    [FRUIT_TREE_ROUTE_11 - 1]       = ITEM_ORAN_BERRY,
    [FRUIT_TREE_ROUTE_26 - 1]       = ITEM_RAWST_BERRY,
};

void GetFruitTreeItem(void)
{
    u8 treeId = gSpecialVar_0x8004;

    DoTimeBasedEvents();

    if (!FlagGet(FLAG_FRUIT_TREES_START + treeId - 1))
        gSpecialVar_Result = sFruitTrees[treeId - 1];
    else
        gSpecialVar_Result = 0;
}

u16 GetFruitTreeMetatileTaken(u16 treeId)
{
    //MapGridSetMetatileIdAt(x, y, sFruitTrees[treeId].takenMetatileId | METATILE_COLLISION_MASK);
    return METATILE_General_FruitTreeTop_NoFruit;
}

u16 GetFruitTreeMetatileGrown(u16 treeId)
{
    //MapGridSetMetatileIdAt(x, y, sFruitTrees[treeId].grownMetatileId | METATILE_COLLISION_MASK);
    return METATILE_General_FruitTreeTop;
}

void SetFruitTreeMetatileTakenFromId(void)
{
    u16 bgId;
    const struct MapEvents *events = gMapHeader.events;
    u16 treeId = gSpecialVar_0x8004;
    
    for (bgId = 0; bgId < events->bgEventCount; bgId++)
    {
        if (events->bgEvents[bgId].kind == BG_EVENT_FRUIT_TREE &&
            events->bgEvents[bgId].bgUnion.berryTreeId == treeId)
        {
            s16 x = events->bgEvents[bgId].x + 7;
            s16 y = events->bgEvents[bgId].y + 6;
            MapGridSetMetatileIdAt(x, y, GetFruitTreeMetatileTaken(treeId));
            CurrentMapDrawMetatileAt(x, y);
            break;
        }
    }
}

void SetFruitTreeMetatiles(bool8 redrawMetatile)
{
    struct MapEvents const *events = gMapHeader.events;
    u16 bgId;
    u16 metatile;

    for (bgId = 0; bgId < events->bgEventCount; bgId++)
    {
        if (events->bgEvents[bgId].kind == BG_EVENT_FRUIT_TREE)
        {
            u16 treeId = events->bgEvents[bgId].bgUnion.berryTreeId;
            s16 x = events->bgEvents[bgId].x + 7;
            s16 y = events->bgEvents[bgId].y + 6;
            
            if (FlagGet(FLAG_FRUIT_TREES_START + treeId - 1))
                metatile = GetFruitTreeMetatileTaken(treeId);
            else
                metatile = GetFruitTreeMetatileGrown(treeId);

            MapGridSetMetatileIdAt(x, y, metatile);

            if (redrawMetatile)
                CurrentMapDrawMetatileAt(x, y);
        }
    }
}

void SetFruitTreeMetatilesOnConnectedMap(int x, int y, struct MapHeader const *connectedMapHeader, int x2, int y2, int width, int height)
{
    struct MapEvents const *events = connectedMapHeader->events;
    u16 bgId;
    u16 metatile;

    for (bgId = 0; bgId < events->bgEventCount; bgId++)
    {
        if (events->bgEvents[bgId].kind == BG_EVENT_FRUIT_TREE)
        {
            u16 treeId = events->bgEvents[bgId].bgUnion.berryTreeId;
            s16 treeX = events->bgEvents[bgId].x - x2;
            s16 treeY = events->bgEvents[bgId].y - y2 - 1; // adjust for top of tree

            if (treeX >= 0 && treeX < width
             && treeY >= 0 && treeY < height)
            {
                if (FlagGet(FLAG_FRUIT_TREES_START + treeId - 1))
                    metatile = GetFruitTreeMetatileTaken(treeId);
                else
                    metatile = GetFruitTreeMetatileGrown(treeId);

                MapGridSetMetatileIdAt(x + treeX, y + treeY, metatile);
            }
        }
    }
}
