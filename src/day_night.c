#include "global.h"
#include "day_night.h"
#include "decompress.h"
#include "event_data.h"
#include "field_weather.h"
#include "overworld.h"
#include "palette.h"
#include "rtc.h"
#include "strings.h"
#include "string_util.h"
#include "constants/day_night.h"
#include "constants/rgb.h"

#define TINT_MORNING Q_8_8(0.8), Q_8_8(0.7), Q_8_8(0.9)
#define TINT_DAY Q_8_8(1.0), Q_8_8(1.0), Q_8_8(1.0)
#define TINT_NIGHT Q_8_8(0.6), Q_8_8(0.55), Q_8_8(1.0)

EWRAM_DATA u16 gPlttBufferPreDN[PLTT_BUFFER_SIZE] = {0};
static EWRAM_DATA s8 sOldHour = 0;
static EWRAM_DATA bool8 sRetintPhase = FALSE;
EWRAM_DATA struct PaletteOverride *gPaletteOverrides[4] = {NULL};
#ifdef DEBUG
EWRAM_DATA bool8 gPaletteOverrideDisabled = 0;
EWRAM_DATA s8 gDNHourOverride = 0;
#endif

static const u16 sTimeOfDayTints[][3] = {
    {TINT_NIGHT},       // Midnight
    {TINT_NIGHT},       // 1 AM
    {TINT_NIGHT},       // 2 AM
    {TINT_NIGHT},       // 3 AM
    {Q_8_8(0.6), Q_8_8(0.6), Q_8_8(1.0)},     // 4 AM
    {TINT_MORNING},     // 5 AM
    {TINT_MORNING},     // 6 AM
    {TINT_MORNING},     // 7 AM
    {Q_8_8(0.9), Q_8_8(0.8), Q_8_8(1.0)},     // 8 AM
    {Q_8_8(1.0), Q_8_8(0.9), Q_8_8(1.0)},     // 9 AM
    {TINT_DAY},     // 10 AM
    {TINT_DAY},     // 11 AM
    {TINT_DAY},     // 12 PM
    {TINT_DAY},         // 1 PM
    {TINT_DAY},         // 2 PM
    {TINT_DAY},         // 3 PM
    {TINT_DAY},         // 4 PM
    {Q_8_8(1.0), Q_8_8(0.9), Q_8_8(0.8)},   // 5 PM
    {Q_8_8(0.9), Q_8_8(0.6), Q_8_8(0.67)},       // 6 PM
    {Q_8_8(0.7), Q_8_8(0.6), Q_8_8(0.9)},       // 7 PM
    {TINT_NIGHT},       // 8 PM
    {TINT_NIGHT},       // 9 PM
    {TINT_NIGHT},       // 10 PM
    {TINT_NIGHT},       // 11 PM
};

const u8 *const gDayOfWeekTable[] = 
{
    gText_Sunday,
    gText_Monday,
    gText_Tuesday,
    gText_Wednesday,
    gText_Thursday,
    gText_Friday,
    gText_Saturday
};

u8 GetCurrentTimeOfDay(void)
{
    return GetTimeOfDay(gLocalTime.hours);
}

u8 GetTimeOfDay(s8 hours)
{
    if (hours < TIME_MORNING_HOUR)
        return TIME_NIGHT;
    else if (hours < TIME_DAY_HOUR)
        return TIME_MORNING;
    else if (hours < TIME_NIGHT_HOUR)
        return TIME_DAY;
    else
        return TIME_NIGHT;
}

const u8 *GetDayOfWeekString(u8 dayOfWeek)
{
    return gDayOfWeekTable[dayOfWeek];
}

void CopyDayOfWeekStringToVar1(void)
{
    if (gSpecialVar_0x8004 <= DAY_SATURDAY)
        StringCopy(gStringVar1, gDayOfWeekTable[gSpecialVar_0x8004]);
    else
        StringCopy(gStringVar1, gText_None);
}

void CopyCurrentDayOfWeekStringToVar1(void)
{
    RtcCalcLocalTime();
    if (gLocalTime.dayOfWeek <= DAY_SATURDAY)
        StringCopy(gStringVar1, gDayOfWeekTable[gLocalTime.dayOfWeek]);
    else
        StringCopy(gStringVar1, gText_None);
}

static void LoadPaletteOverrides(void)
{
    u8 i, j;
    const u16* src;
    u16* dest;
    s8 hour;

#ifdef DEBUG
    if (gPaletteOverrideDisabled)
        return;
#endif

    hour = gLocalTime.hours;
#ifdef DEBUG
    if (gDNHourOverride != 0)
        hour = gDNHourOverride - 1;
#endif

    for (i = 0; i < ARRAY_COUNT(gPaletteOverrides); i++)
    {
        const struct PaletteOverride *curr = gPaletteOverrides[i];
        if (curr != NULL)
        {
            while (curr->slot != PALOVER_LIST_TERM && curr->palette != NULL)
            {
                if ((curr->startHour < curr->endHour && hour >= curr->startHour && hour < curr->endHour) ||
                    (curr->startHour > curr->endHour && (hour >= curr->startHour || hour < curr->endHour)))
                {
                    for (j = 0, src = curr->palette, dest = gPlttBufferUnfaded + (curr->slot * 16); j < 16; j++, src++, dest++)
                    {
                        if (*src != RGB_BLACK)
                            *dest = *src;
                    }
                }
                curr++;
            }
        }
    }
}

static bool8 ShouldTintOverworld(void)
{
    if (Overworld_MapTypeIsIndoors(gMapHeader.mapType))
        return FALSE;

    return TRUE;
}

static void TintPaletteForDayNight(u16 offset, u16 size)
{
    if (ShouldTintOverworld())
    {
        s8 hour;
        RtcCalcLocalTimeFast();
        
        hour = gLocalTime.hours;
#ifdef DEBUG
        if (gDNHourOverride != 0)
            hour = gDNHourOverride - 1;
#endif

        TintPalette_CustomToneWithCopy(gPlttBufferPreDN + offset, gPlttBufferUnfaded + offset, size / 2, sTimeOfDayTints[hour][0], sTimeOfDayTints[hour][1], sTimeOfDayTints[hour][2], FALSE);
    }
    else
    {
        CpuCopy16(gPlttBufferPreDN + offset, gPlttBufferUnfaded + offset, size);
    }
    LoadPaletteOverrides();
}

void LoadCompressedPaletteDayNight(const void *src, u16 offset, u16 size)
{
    LZDecompressWram(src, gPaletteDecompressionBuffer);
    CpuCopy16(gPaletteDecompressionBuffer, gPlttBufferPreDN + offset, size);
    TintPaletteForDayNight(offset, size);
    CpuCopy16(gPlttBufferUnfaded + offset, gPlttBufferFaded + offset, size);
}

void LoadPaletteDayNight(const void *src, u16 offset, u16 size)
{
    CpuCopy16(src, gPlttBufferPreDN + offset, size);
    TintPaletteForDayNight(offset, size);
    CpuCopy16(gPlttBufferUnfaded + offset, gPlttBufferFaded + offset, size);
}

void CheckClockToRetintForDayNight(void)
{
    if (ShouldTintOverworld() && !sRetintPhase)
        RtcCalcLocalTimeFast();
}

void RetintPalettesForDayNight(void)
{
    s8 hour;

    if (ShouldTintOverworld())
    {
        if (!sRetintPhase)
        {
            hour = gLocalTime.hours;

#ifdef DEBUG
            if (gDNHourOverride != 0)
                hour = gDNHourOverride - 1;
#endif

            if (hour != sOldHour)
            {
                sOldHour = hour;
                sRetintPhase = 1;
                TintPalette_CustomToneWithCopy(gPlttBufferPreDN, gPlttBufferUnfaded, BG_PLTT_SIZE / 2, sTimeOfDayTints[hour][0], sTimeOfDayTints[hour][1], sTimeOfDayTints[hour][2], TRUE);
            }
        }
        else
        {
            sRetintPhase = 0;
            TintPalette_CustomToneWithCopy(gPlttBufferPreDN + (BG_PLTT_SIZE / 2), gPlttBufferUnfaded + (BG_PLTT_SIZE / 2), OBJ_PLTT_SIZE / 2, sTimeOfDayTints[sOldHour][0], sTimeOfDayTints[sOldHour][1], sTimeOfDayTints[sOldHour][2], TRUE);
            LoadPaletteOverrides();
            ChooseAmbientCrySpecies();  // so a time-of-day appropriate mon is chosen
            
            if (gWeatherPtr->palProcessingState != WEATHER_PAL_STATE_SCREEN_FADING_IN &&
                gWeatherPtr->palProcessingState != WEATHER_PAL_STATE_SCREEN_FADING_OUT)
                CpuCopy16(gPlttBufferUnfaded, gPlttBufferFaded, PLTT_SIZE);
        }
    }
}

void DoLoadSpritePaletteDayNight(const u16 *src, u16 paletteOffset)
{
    LoadPaletteDayNight(src, paletteOffset + 0x100, 32);
}
