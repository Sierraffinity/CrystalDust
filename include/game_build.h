#ifndef GUARD_GAME_BUILD_H
#define GUARD_GAME_BUILD_H

#define GAME_BUILD          1
// byteswapped CDMA
#define SAVE_BLOCK_MAGIC    0x414D4443 

void SetBuildNumber(void);
bool32 CheckBuildNumber(void);
bool32 CheckSaveBlockMagic(void);
u8 *GetGameVersionString(u8 *str);
u8 *GetSaveVersionString(u8 *str);

#endif // GUARD_GAME_BUILD_H
