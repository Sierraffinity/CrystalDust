#ifndef GUARD_DAY_NIGHT_H
#define GUARD_DAY_NIGHT_H

#define PALOVER_LIST_TERM 0xFF

struct PaletteOverride
{
    u8 slot;
    u8 startHour;
    u8 endHour;
    void *palette;
};

extern EWRAM_DATA u16 gPlttBufferPreDN[];
extern EWRAM_DATA struct PaletteOverride *gPaletteOverrides[];
#ifdef DEBUG
extern EWRAM_DATA bool8 gPaletteTintDisabled;
extern EWRAM_DATA bool8 gPaletteOverrideDisabled;
extern EWRAM_DATA s8 gDNHourOverride;
#endif

u8 GetTimeOfDay(void);
void LoadCompressedPaletteDayNight(const void *src, u16 offset, u16 size);
void LoadPaletteDayNight(const void *src, u16 offset, u16 size);
void CheckClockToRetintForDayNight(void);
void RetintPalettesForDayNight(void);
void DoLoadSpritePaletteDayNight(const u16 *src, u16 paletteOffset);
const u8 *GetDayOfWeekString(u8 timeOfDay);

#endif // GUARD_DAY_NIGHT_H
