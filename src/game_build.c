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
    // only check most significant versions - patch can be changed arbitrarily
    return (gSaveBlock1Ptr->gameBuild & 0xFFFF0000) == (GAME_BUILD & 0xFFFF0000);
}

bool32 CheckSaveBlockMagic(void)
{
    return gSaveBlock1Ptr->saveBlockMagic == SAVE_BLOCK_MAGIC;
}

static u8 *GetVersionString(u8 *str, u32 version)
{
    static const u8 alpha[] = _("3.0.0-alpha");
    static const u8 beta[] = _("3.0.0-beta");
    static const u8 gamma[] = _("3.0.0-gamma");
    int i;
    u8 major = GET_VER_MAJOR(version);
    u8 minor = GET_VER_MINOR(version);
    u16 patch = GET_VER_PATCH(version);

    *(str++) = CHAR_v;
    switch (major)
    {
    case 0:
        // v3.0.0-alpha
        str = StringCopy(str, alpha);
        break;
    case 1:
        // v3.0.0-beta
        str = StringCopy(str, beta);
        break;
    case 2:
        // v3.0.0-gamma
        str = StringCopy(str, gamma);
        break;
    default:
        // v3
        str = ConvertIntToDecimalStringN(str, major, STR_CONV_MODE_LEFT_ALIGN, 3);
        break;
    }
    *(str++) = CHAR_PERIOD;
    str = ConvertIntToDecimalStringN(str, minor, STR_CONV_MODE_LEFT_ALIGN, 3);
    *(str++) = CHAR_PERIOD;
    str = ConvertIntToDecimalStringN(str, patch, STR_CONV_MODE_LEFT_ALIGN, 4);

    return str;
}

u8 *GetGameVersionString(u8 *str)
{
    return GetVersionString(str, GAME_BUILD);
}

u8 *GetSaveVersionString(u8 *str)
{
    return GetVersionString(str, gSaveBlock1Ptr->gameBuild);
}
