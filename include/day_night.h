#ifndef GUARD_DAY_NIGHT_H
#define GUARD_DAY_NIGHT_H

enum
{
    TIME_NIGHT,
    TIME_MORNING,
    TIME_DAY,
    TIME_AFTERNOON
};

extern EWRAM_DATA u16 gPlttBufferPreDN[];

u8 GetTimeOfDay(void);
void LoadCompressedPaletteDayNight(const void *src, u16 offset, u16 size);
void LoadPaletteDayNight(const void *src, u16 offset, u16 size);
void TintForDayNight(void);
void DoLoadSpritePaletteDayNight(const u16 *src, u16 paletteOffset);

#endif // GUARD_DAY_NIGHT_H
