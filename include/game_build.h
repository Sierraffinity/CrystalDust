#ifndef GUARD_GAME_BUILD_H
#define GUARD_GAME_BUILD_H

#define GAME_BUILD      1

void SetBuildNumber(void);
bool32 CheckBuildNumber(void);
u8 *GetGameVersionString(u8 *str);
u8 *GetSaveVersionString(u8 *str);

#endif // GUARD_GAME_BUILD_H
