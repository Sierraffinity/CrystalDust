#include "global.h"
#include "event_data.h"
#include "rtc.h"
#include "time_events.h"
#include "field_specials.h"
#include "lottery_corner.h"
#include "dewford_trend.h"
#include "tv.h"
#include "field_weather.h"
#include "berry.h"
#include "main.h"
#include "overworld.h"
#include "string_util.h"
#include "text.h"
#include "wallclock.h"

static void UpdatePerDay(struct Time *localTime);
static void UpdatePerMinute(struct Time *localTime);

// needs to not be static because of how calling from OW differs from calling from main menu
void InitTimeBasedEvents(void)
{
    FlagSet(FLAG_SYS_CLOCK_SET);
    RtcCalcLocalTime();
    gSaveBlock2Ptr->lastBerryTreeUpdate = gLocalTime;
    VarSet(VAR_DAYS, gLocalTime.days);
}

void DoTimeBasedEvents(void)
{
    if (FlagGet(FLAG_SYS_CLOCK_SET) && !sub_813B9C0())
    {
        RtcCalcLocalTime();
        UpdatePerDay(&gLocalTime);
        UpdatePerMinute(&gLocalTime);
    }
}

static void UpdatePerDay(struct Time *localTime)
{
    u16 *days = GetVarPointer(VAR_DAYS);
    u16 daysSince;

    if (*days != localTime->days && *days <= localTime->days)
    {
        daysSince = localTime->days - *days;
        ClearUpperFlags();
        UpdateDewfordTrendPerDay(daysSince);
        UpdateTVShowsPerDay(daysSince);
        UpdateWeatherPerDay(daysSince);
        UpdatePartyPokerusTime(daysSince);
        UpdateMirageRnd(daysSince);
        UpdateBirchState(daysSince);
        UpdateFrontierManiac(daysSince);
        UpdateFrontierGambler(daysSince);
        SetShoalItemFlag(daysSince);
        SetRandomLotteryNumber(daysSince);
        *days = localTime->days;
    }
}

static void UpdatePerMinute(struct Time *localTime)
{
    struct Time difference;
    int minutes;

    CalcTimeDifference(&difference, &gSaveBlock2Ptr->lastBerryTreeUpdate, localTime);
    minutes = 24 * 60 * difference.days + 60 * difference.hours + difference.minutes;
    if (minutes != 0)
    {
        if (minutes >= 0)
        {
            BerryTreeTimeUpdate(minutes);
            gSaveBlock2Ptr->lastBerryTreeUpdate = *localTime;
        }
    }
}

static void ReturnFromStartWallClock(void)
{
    InitTimeBasedEvents();
    SetMainCallback2(CB2_ReturnToFieldContinueScriptPlayMapMusic);
}

void StartWallClock(void)
{
    SetMainCallback2(CB2_StartWallClock);
    gMain.savedCallback = ReturnFromStartWallClock;
}

u8* WriteTimeString(u8 *dest, u8 hours, u8 minutes, bool8 twentyFourHourMode, bool8 shouldWriteAMPM)
{
    bool8 isPM = FALSE;

    if (!twentyFourHourMode)
    {
        if (hours == 0)
        {
            hours = 12;
        }
        else if (hours == 12)
        {
            isPM = TRUE;
        }
        else if (hours > 12)
        {
            isPM = TRUE;
            hours -= 12;
        }
    }

    dest = ConvertIntToDecimalStringN(dest, hours, STR_CONV_MODE_LEFT_ALIGN, (hours >= 10) ? 2 : 1);
    *dest++ = CHAR_COLON;
    dest = ConvertIntToDecimalStringN(dest, minutes, STR_CONV_MODE_LEADING_ZEROS, 2);

    if (!twentyFourHourMode && shouldWriteAMPM)
    {
        *dest++ = CHAR_SPACE;

        if (isPM)
            *dest++ = CHAR_P;
        else
            *dest++ = CHAR_A;

        *dest++ = CHAR_M;
    }
    *dest = EOS;

    return dest;
}

void WriteCurrentTimeStringToStrVar1(void)
{
    WriteTimeString(gStringVar1, gLocalTime.hours, gLocalTime.minutes, FlagGet(FLAG_SYS_POKEGEAR_24HR), TRUE);
}

void SetDayOfWeek(void)
{
    RtcSetDayOfWeek(gSpecialVar_0x8004);
}
