#include "global.h"
#include "clock.h"
#include "event_data.h"
#include "constants/items.h"
#include "constants/fruit_trees.h"

void GetFruitTreeItem(void)
{
    static const u16 fruits[] = 
    {
        [FRUITTREE_ROUTE_29]    = ITEM_ORAN_BERRY,
        [FRUITTREE_ROUTE_30_1]  = ITEM_ORAN_BERRY,
        [FRUITTREE_ROUTE_30_2]  = ITEM_PECHA_BERRY,
    };

    u8 treeId = gSpecialVar_0x8004;

    DoTimeBasedEvents();

    if (!FlagGet(FLAG_FRUIT_TREES_START + treeId))
        gSpecialVar_Result = fruits[treeId];
    else
        gSpecialVar_Result = 0;
}
