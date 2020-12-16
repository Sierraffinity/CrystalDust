#ifndef GUARD_CLOCK_H
#define GUARD_CLOCK_H

void DoTimeBasedEvents(void);
void InitTimeBasedEvents(void);
u8* WriteTimeString(u8 *dest, u8 hours, u8 minutes, bool8 twentyFourHourMode, bool8 shouldWriteAMPM);

#endif // GUARD_CLOCK_H
