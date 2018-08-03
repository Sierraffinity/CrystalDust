#ifndef GUARD_DAY_NIGHT_H
#define GUARD_DAY_NIGHT_H

#define PALOVER_LIST_TERM 0xFF

enum
{
    TIME_NIGHT,
    TIME_MORNING,
    TIME_DAY,
    TIME_AFTERNOON
};

enum
{
    DAY_SUNDAY,
    DAY_MONDAY,
    DAY_TUESDAY,
    DAY_WEDNESDAY,
    DAY_THURSDAY,
    DAY_FRIDAY,
    DAY_SATURDAY
};

struct PaletteOverride
{
    u8 slot;
    u8 timeOfDay;
    void *palette;
};

#define TIME_MORNING_HOUR 4
#define TIME_DAY_HOUR 10
#define TIME_AFTERNOON_HOUR 17
#define TIME_NIGHT_HOUR 18

extern EWRAM_DATA u16 gPlttBufferPreDN[];
extern EWRAM_DATA struct PaletteOverride *gPaletteOverrides[];

u8 GetTimeOfDay(void);
void LoadCompressedPaletteDayNight(const void *src, u16 offset, u16 size);
void LoadPaletteDayNight(const void *src, u16 offset, u16 size);
void TintForDayNight(void);
void DoLoadSpritePaletteDayNight(const u16 *src, u16 paletteOffset);
const u8 *GetDayOfWeekString(void);

#endif // GUARD_DAY_NIGHT_H
