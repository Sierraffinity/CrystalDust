#include "global.h"
#include "rtc.h"
#include "event_data.h"
#include "constants/items.h"

void GetFruitTreeItem(void)
{
    static const u16 fruits[] = 
    {
        ITEM_ORAN_BERRY
    };

    RtcCalcLocalTime();


}
