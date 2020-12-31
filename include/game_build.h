#ifndef GUARD_GAME_BUILD_H
#define GUARD_GAME_BUILD_H

// 8 bits major, 8 bits minor, 16 bits patch (cannot go beyond 999)
// major 0: v3.0.0-alpha
// major 1: v3.0.0-beta
// major 2: v3.0.0-gamma
// major 3 and beyond: v3

// v3.0.0-alpha.0.1
#define GAME_VER_MAJOR      0
#define GAME_VER_MINOR      0
#define GAME_VER_PATCH      4
#define GAME_BUILD          ((GAME_VER_MAJOR << 24) | (GAME_VER_MINOR << 16) | GAME_VER_PATCH)

// byteswapped CDMA
#define SAVE_BLOCK_MAGIC    0x414D4443

#define GET_VER_MAJOR(x)    (((x) & 0xFF000000) >> 24)
#define GET_VER_MINOR(x)    (((x) & 0xFF0000) >> 16)
#define GET_VER_PATCH(x)    ((x) & 0xFFFF)

void SetBuildNumber(void);
bool32 CheckBuildNumber(void);
bool32 CheckSaveBlockMagic(void);
u8 *GetGameVersionString(u8 *str);
u8 *GetSaveVersionString(u8 *str);

#endif // GUARD_GAME_BUILD_H
