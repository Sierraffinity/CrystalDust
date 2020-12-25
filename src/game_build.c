#include "global.h"
#include "game_build.h"
#include "string_util.h"
#include "text.h"

void SetBuildNumber(void)
{
    gSaveBlock1Ptr->gameBuild = GAME_BUILD;
    gSaveBlock1Ptr->saveBlockMagic = SAVE_BLOCK_MAGIC;
}

bool32 CheckBuildNumber(void)
{
    return gSaveBlock1Ptr->gameBuild == GAME_BUILD;
}

bool32 CheckSaveBlockMagic(void)
{
    return gSaveBlock1Ptr->saveBlockMagic == SAVE_BLOCK_MAGIC;
}

static u8 *GetVersionString(u8 *str, u32 version)
{
    int i;
    u8 *afterStr = ConvertIntToDecimalStringN(str, version, STR_CONV_MODE_RIGHT_ALIGN, 6);

    while (*str == CHAR_UNK_SPACER)
    {
        str++;
    }
    *(str - 1) = CHAR_b;

    return afterStr;
}

u8 *GetGameVersionString(u8 *str)
{
    return GetVersionString(str, GAME_BUILD);
}

u8 *GetSaveVersionString(u8 *str)
{
    return GetVersionString(str, gSaveBlock1Ptr->gameBuild);
}
