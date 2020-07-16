#ifndef GUARD_BUENAS_PASSWORD_H
#define GUARD_BUENAS_PASSWORD_H

void BuenasPasswordMultichoice(void);
u16 GenerateRandomBuenasPassword(void);
const u8 *GetBuenasPassword(u8 category, u8 index);

#endif
