#include "global.h"
#include "event_data.h"
#include "field_message_box.h"
#include "pokedex.h"
#include "constants/species.h"

extern const u8 gPokedexRatingText_LessThan10[];
extern const u8 gPokedexRatingText_LessThan20[];
extern const u8 gPokedexRatingText_LessThan35[];
extern const u8 gPokedexRatingText_LessThan50[];
extern const u8 gPokedexRatingText_LessThan65[];
extern const u8 gPokedexRatingText_LessThan80[];
extern const u8 gPokedexRatingText_LessThan95[];
extern const u8 gPokedexRatingText_LessThan110[];
extern const u8 gPokedexRatingText_LessThan125[];
extern const u8 gPokedexRatingText_LessThan140[];
extern const u8 gPokedexRatingText_LessThan155[];
extern const u8 gPokedexRatingText_LessThan170[];
extern const u8 gPokedexRatingText_LessThan185[];
extern const u8 gPokedexRatingText_LessThan200[];
extern const u8 gPokedexRatingText_LessThan215[];
extern const u8 gPokedexRatingText_LessThan230[];
extern const u8 gPokedexRatingText_LessThan249[];
extern const u8 gPokedexRatingText_DexCompleted[];

bool16 ScriptGetPokedexInfo(void)
{
    if (gSpecialVar_0x8004 == 0) // is national dex not present?
    {
        gSpecialVar_0x8005 = GetJohtoPokedexCount(FLAG_GET_SEEN);
        gSpecialVar_0x8006 = GetJohtoPokedexCount(FLAG_GET_CAUGHT);
    }
    else
    {
        gSpecialVar_0x8005 = GetNationalPokedexCount(FLAG_GET_SEEN);
        gSpecialVar_0x8006 = GetNationalPokedexCount(FLAG_GET_CAUGHT);
    }

    return IsNationalPokedexEnabled();
}

// This shows your Hoenn Pokedex rating and not your National Dex.
const u8 *GetPokedexRatingText(u16 count)
{
    gSpecialVar_Result = FALSE;

    if (count < 10)
        return gPokedexRatingText_LessThan10;
    if (count < 20)
        return gPokedexRatingText_LessThan20;
    if (count < 35)
        return gPokedexRatingText_LessThan35;
    if (count < 50)
        return gPokedexRatingText_LessThan50;
    if (count < 65)
        return gPokedexRatingText_LessThan65;
    if (count < 80)
        return gPokedexRatingText_LessThan80;
    if (count < 95)
        return gPokedexRatingText_LessThan95;
    if (count < 110)
        return gPokedexRatingText_LessThan110;
    if (count < 125)
        return gPokedexRatingText_LessThan125;
    if (count < 140)
        return gPokedexRatingText_LessThan140;
    if (count < 155)
        return gPokedexRatingText_LessThan155;
    if (count < 170)
        return gPokedexRatingText_LessThan170;
    if (count < 185)
        return gPokedexRatingText_LessThan185;
    if (count < 200)
        return gPokedexRatingText_LessThan200;
    if (count < 215)
        return gPokedexRatingText_LessThan215;
    if (count < 230)
        return gPokedexRatingText_LessThan230;
    
    // Mew and Celebi don't count for completing the pokedex
    if (GetSetPokedexFlag(SpeciesToNationalPokedexNum(SPECIES_MEW), FLAG_GET_CAUGHT))
        count--;
    if (GetSetPokedexFlag(SpeciesToNationalPokedexNum(SPECIES_CELEBI), FLAG_GET_CAUGHT))
        count--;

    if (count < 249)
        return gPokedexRatingText_LessThan249;

    gSpecialVar_Result = TRUE;
    return gPokedexRatingText_DexCompleted;
}

void ShowPokedexRatingMessage(void)
{
    ShowFieldMessage(GetPokedexRatingText(gSpecialVar_0x8004));
}
