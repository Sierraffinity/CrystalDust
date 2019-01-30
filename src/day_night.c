#include "global.h"
#include "day_night.h"
#include "decompress.h"
#include "event_data.h"
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
EWRAM_DATA struct PaletteOverride *gPaletteOverrides[4] = {NULL};
#ifdef DEBUG
EWRAM_DATA bool8 gPaletteTintDisabled = 0;
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

u8 GetTimeOfDay(void)
{
    if (gLocalTime.hours < TIME_MORNING_HOUR)
        return TIME_NIGHT;
    else if (gLocalTime.hours < TIME_DAY_HOUR)
        return TIME_MORNING;
    else if (gLocalTime.hours < TIME_NIGHT_HOUR)
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

u8 GetTimeOfDayForTinting(void)
{
    s8 hour;

#ifdef DEBUG
    if (gPaletteTintDisabled)
        return TIME_DAY;
#endif
    if (Overworld_MapTypeIsIndoors(gMapHeader.mapType))
        return TIME_DAY;

    hour = gLocalTime.hours;
#ifdef DEBUG
    if (gDNHourOverride != 0)
        hour = gDNHourOverride - 1;
#endif
    
    if (hour < TIME_MORNING_HOUR)
        return TIME_NIGHT;
    else if (hour < TIME_DAY_HOUR)
        return TIME_MORNING;
    else if (hour < TIME_AFTERNOON_HOUR)
        return TIME_DAY;
    else if (hour < TIME_NIGHT_HOUR)
        return TIME_AFTERNOON;
    else
        return TIME_NIGHT;
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

static void TintPaletteForDayNight(u16 offset, u16 size)
{
    s8 hour;
    RtcCalcLocalTime();
    
    hour = gLocalTime.hours;
#ifdef DEBUG
    if (gDNHourOverride != 0)
        hour = gDNHourOverride - 1;
#endif

    TintPalette_CustomToneWithCopy(gPlttBufferPreDN + offset, gPlttBufferUnfaded + offset, size / 2, sTimeOfDayTints[hour][0], sTimeOfDayTints[hour][1], sTimeOfDayTints[hour][2], FALSE);
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

void RetintPalettesForDayNight(void)
{
    u32 i;
    const u16* src;
    u16* dest;
    s8 hour;

    RtcSlowUpdate();
    hour = gLocalTime.hours;
#ifdef DEBUG
    if (gDNHourOverride != 0)
        hour = gDNHourOverride - 1;
#endif

    if (hour != sOldHour)
    {
        sOldHour = hour;
        TintPalette_CustomToneWithCopy(gPlttBufferPreDN, gPlttBufferUnfaded, PLTT_BUFFER_SIZE, sTimeOfDayTints[hour][0], sTimeOfDayTints[hour][1], sTimeOfDayTints[hour][2], TRUE);
        LoadPaletteOverrides();
        if (!gPaletteFade.active && gPaletteFade.yDec)  // HACK
            CpuCopy16(gPlttBufferUnfaded, gPlttBufferFaded, PLTT_BUFFER_SIZE * 2);
    }
}

void DoLoadSpritePaletteDayNight(const u16 *src, u16 paletteOffset)
{
    LoadPaletteDayNight(src, paletteOffset + 0x100, 32);
}
