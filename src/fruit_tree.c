#include "global.h"
#include "clock.h"
#include "event_data.h"
#include "constants/items.h"

void GetFruitTreeItem(void)
{
    static const u16 fruits[] = 
    {
        ITEM_ORAN_BERRY
    };

    u8 treeId = gSpecialVar_0x8004;

    DoTimeBasedEvents();

    if (!FlagGet(FLAG_FRUIT_TREES_START + treeId))
        gSpecialVar_Result = fruits[treeId];
    else
        gSpecialVar_Result = 0;
}
