#include "global.h"
#include "day_night.h"
#include "constants/rgb.h"
#include "decompress.h"
#include "overworld.h"
#include "palette.h"
#include "rtc.h"
#include "strings.h"

#define TINT_MORNING Q_8_8(0.9), Q_8_8(0.8), Q_8_8(1.0)
#define TINT_AFTERNOON Q_8_8(1.0), Q_8_8(0.6), Q_8_8(0.67)
#define TINT_NIGHT Q_8_8(0.5), Q_8_8(0.5), Q_8_8(1.0)

EWRAM_DATA u16 gPlttBufferPreDN[PLTT_BUFFER_SIZE] = {0};
static EWRAM_DATA u8 sOldTimeOfDay = TIME_NIGHT;
//static EWRAM_DATA u8 sDemo = 0;
EWRAM_DATA struct PaletteOverride *gPaletteOverrides[4] = {NULL};

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
    /*if (++sDemo > 240)
    {
        sDemo = 0;
        return TIME_NIGHT;
    }
    else if (sDemo > 180)
    {
        return TIME_AFTERNOON;
    }
    else if (sDemo > 120)
    {
        return TIME_DAY;
    }
    else if (sDemo > 60)
    {
        return TIME_MORNING;
    }
    else
    {
        return TIME_NIGHT;
    }*/
    RtcSlowUpdate();
    if (gLocalTime.hours < 4)
        return TIME_NIGHT;
    else if (gLocalTime.hours < 10)
        return TIME_MORNING;
    else if (gLocalTime.hours < 17)
        return TIME_DAY;
    else if (gLocalTime.hours < 18)
        return TIME_AFTERNOON;
    else
        return TIME_NIGHT;
}

const u8 *GetDayOfWeekString(void)
{
    return gDayOfWeekTable[gLocalTime.dayOfWeek];
}

u8 GetTimeOfDayWithModifiers(void)
{
    if (Overworld_MapTypeIsIndoors(gMapHeader.mapType))
        return TIME_DAY;
    
    return GetTimeOfDay();
}

static void LoadPaletteOverrides(void)
{
    u8 i, j;
    const u16* src;
    u16* dest;
    u8 timeOfDay = GetTimeOfDay();

    for (i = 0; i < ARRAY_COUNT(gPaletteOverrides); i++)
    {
        const struct PaletteOverride *curr = gPaletteOverrides[i];
        if (curr != NULL)
        {
            while (curr->slot != PALOVER_LIST_TERM && curr->palette != NULL)
            {
                if (curr->timeOfDay == timeOfDay)
                {
                    for (j = 0, src = curr->palette, dest = gPlttBufferUnfaded + (curr->slot * 16); j < 16; j++, src++, dest++)
                    {
                        if (*src == RGB_BLACK)
                            continue;
                        
                        *dest = *src;
                    }
                }
                curr++;
            }
        }
    }
}

static void TintForDayNightOnLoad(u16 offset, u16 size)
{
    switch (GetTimeOfDayWithModifiers())
    {
        case TIME_MORNING:
            TintPalette_CustomToneWithCopy(gPlttBufferPreDN + offset, gPlttBufferUnfaded + offset, size / 2, TINT_MORNING, FALSE);
            break;
        case TIME_AFTERNOON:
            TintPalette_CustomToneWithCopy(gPlttBufferPreDN + offset, gPlttBufferUnfaded + offset, size / 2, TINT_AFTERNOON, FALSE);
            break;
        case TIME_NIGHT:
            TintPalette_CustomToneWithCopy(gPlttBufferPreDN + offset, gPlttBufferUnfaded + offset, size / 2, TINT_NIGHT, FALSE);
            break;
        default:
            CpuCopy16(gPlttBufferPreDN + offset, gPlttBufferUnfaded + offset, size);
            break;
    }
    LoadPaletteOverrides();
}

void LoadCompressedPaletteDayNight(const void *src, u16 offset, u16 size)
{
    LZDecompressWram(src, gPaletteDecompressionBuffer);
    CpuCopy16(gPaletteDecompressionBuffer, gPlttBufferPreDN + offset, size);
    TintForDayNightOnLoad(offset, size);
    CpuCopy16(gPlttBufferUnfaded + offset, gPlttBufferFaded + offset, size);
}

void LoadPaletteDayNight(const void *src, u16 offset, u16 size)
{
    CpuCopy16(src, gPlttBufferPreDN + offset, size);
    TintForDayNightOnLoad(offset, size);
    CpuCopy16(gPlttBufferUnfaded + offset, gPlttBufferFaded + offset, size);
}

void TintForDayNight(void)
{
    u32 i;
    const u16* src;
    u16* dest;
    u8 timeOfDay = GetTimeOfDayWithModifiers();

    if (timeOfDay != sOldTimeOfDay)
    {
        sOldTimeOfDay = timeOfDay;
        switch (timeOfDay)
        {
            case TIME_MORNING:
                TintPalette_CustomToneWithCopy(gPlttBufferPreDN, gPlttBufferUnfaded, PLTT_BUFFER_SIZE, TINT_MORNING, TRUE);
                break;
            case TIME_AFTERNOON:
                TintPalette_CustomToneWithCopy(gPlttBufferPreDN, gPlttBufferUnfaded, PLTT_BUFFER_SIZE, TINT_AFTERNOON, TRUE);
                break;
            case TIME_NIGHT:
                TintPalette_CustomToneWithCopy(gPlttBufferPreDN, gPlttBufferUnfaded, PLTT_BUFFER_SIZE, TINT_NIGHT, TRUE);
                break;
            default:
                for (i = 0, src = gPlttBufferPreDN, dest = gPlttBufferUnfaded; i < PLTT_BUFFER_SIZE; i++, src++, dest++)
                {
                    if (*src == RGB_BLACK)
                        continue;
                    
                    *dest = *src;
                }
                break;
        }
        LoadPaletteOverrides();
        if (!gPaletteFade.active && gPaletteFade.yDec)  // HACK
            CpuCopy16(gPlttBufferUnfaded, gPlttBufferFaded, PLTT_BUFFER_SIZE * 2);
    }
}

void DoLoadSpritePaletteDayNight(const u16 *src, u16 paletteOffset)
{
    LoadPaletteDayNight(src, paletteOffset + 0x100, 32);
}
