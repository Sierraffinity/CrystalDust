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

struct PaletteOverride
{
    u8 slot;
    u8 timeOfDay;
    void *palette;
};

extern EWRAM_DATA u16 gPlttBufferPreDN[];
extern EWRAM_DATA struct PaletteOverride *gPaletteOverrides[];

u8 GetTimeOfDay(void);
void LoadCompressedPaletteDayNight(const void *src, u16 offset, u16 size);
void LoadPaletteDayNight(const void *src, u16 offset, u16 size);
void TintForDayNight(void);
void DoLoadSpritePaletteDayNight(const u16 *src, u16 paletteOffset);

#endif // GUARD_DAY_NIGHT_H
