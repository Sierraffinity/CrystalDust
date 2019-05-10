#include "global.h"
#include "clock.h"
#include "event_data.h"
#include "fieldmap.h"
#include "field_camera.h"
#include "field_player_avatar.h"
#include "item.h"
#include "constants/bg_event_constants.h"
#include "constants/items.h"
#include "constants/fruit_trees.h"

// Fruit tree IDs are 1-indexed so field_control_avatar code doesn't have a fit
// with a "NULL script pointer" (AKA zero in the ID field)

static const u16 sFruitTrees[] = 
{
    [FRUIT_TREE_ROUTE_29]   = ITEM_ORAN_BERRY,
    [FRUIT_TREE_ROUTE_30_1] = ITEM_ORAN_BERRY,
    [FRUIT_TREE_ROUTE_30_2] = ITEM_PECHA_BERRY,
};

void GetFruitTreeItem(void)
{
    u8 treeId = gSpecialVar_0x8004;

    DoTimeBasedEvents();

    if (!FlagGet(FLAG_FRUIT_TREES_START + treeId - 1))
        gSpecialVar_Result = sFruitTrees[treeId];
    else
        gSpecialVar_Result = 0;
}

void SetFruitTreeMetatileTaken(u16 treeId, s16 x, s16 y)
{
    //MapGridSetMetatileIdAt(x, y, sFruitTrees[treeId].takenMetatileId | METATILE_COLLISION_MASK);
    MapGridSetMetatileIdAt(x, y, 0x22C);
}

void SetFruitTreeMetatileGrown(u16 treeId, s16 x, s16 y)
{
    //MapGridSetMetatileIdAt(x, y, sFruitTrees[treeId].grownMetatileId | METATILE_COLLISION_MASK);
    MapGridSetMetatileIdAt(x, y, 0x22D);
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
            SetFruitTreeMetatileTaken(treeId, x, y);
            CurrentMapDrawMetatileAt(x, y);
            break;
        }
    }
}

void SetFruitTreeMetatiles(bool8 redrawMetatile)
{
    struct MapEvents const *events = gMapHeader.events;
    u16 bgId;

    for (bgId = 0; bgId < events->bgEventCount; bgId++)
    {
        if (events->bgEvents[bgId].kind == BG_EVENT_FRUIT_TREE)
        {
            u16 treeId = events->bgEvents[bgId].bgUnion.berryTreeId;
            s16 x = events->bgEvents[bgId].x + 7;
            s16 y = events->bgEvents[bgId].y + 6;
            
            if (FlagGet(FLAG_FRUIT_TREES_START + treeId - 1))
                SetFruitTreeMetatileTaken(treeId, x, y);
            else
                SetFruitTreeMetatileGrown(treeId, x, y);

            if (redrawMetatile)
                CurrentMapDrawMetatileAt(x, y);
        }
    }
}
