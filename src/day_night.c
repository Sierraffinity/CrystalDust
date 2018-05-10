#include "global.h"
#include "day_night.h"
#include "rtc.h"

u8 GetTimeOfDay(void)
{
    if (gLocalTime.hours < 6)
        return TIME_NIGHT;
    else if (gLocalTime.hours < 10)
        return TIME_MORNING;
    else if (gLocalTime.hours < 17)
        return TIME_DAY;
    else if (gLocalTime.hours < 19)
        return TIME_AFTERNOON;
    else
        return TIME_NIGHT;
}
