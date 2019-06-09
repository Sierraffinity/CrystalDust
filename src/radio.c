#include "global.h"
#include "main.h"
#include "alloc.h"
#include "battle_main.h"
#include "clock.h"
#include "data.h"
#include "day_night.h"
#include "event_data.h"
#include "international_string_util.h"
#include "item.h"
#include "lottery_corner.h"
#include "pokedex.h"
#include "pokegear.h"
#include "radio.h"
#include "random.h"
#include "region_map.h"
#include "rtc.h"
#include "script.h"
#include "sound.h"
#include "strings.h"
#include "string_util.h"
#include "task.h"
#include "text.h"
#include "wild_encounter.h"
#include "window.h"
#include "constants/day_night.h"
#include "constants/flags.h"
#include "constants/items.h"
#include "constants/maps.h"
#include "constants/moves.h"
#include "constants/region_map_sections.h"
#include "constants/songs.h"
#include "constants/species.h"

#define tShowNameId data[0]
#define tWindowId data[1]
#define tCurrentLine data[2]
#define tNextLine data[3]
#define tNumLinesPrinted data[4]
#define tScrollDistance data[5]
#define tTextDelay data[6]
#define tMiscValue data[7]
#define tMiscValue2 data[8]
#define tMiscPtr data[14]

static const u16 sRadioChannelSongs[] = 
{
    MUS_RG_KENKYU,
    MUS_POKECEN,
    MUS_DUMMY,  // Music channel
    MUS_CASINO,
    MUS_M_BOAT,
    MUS_FINECITY,
    MUS_MACHUPI,
    MUS_AJITO,
    MUS_RG_POKEFUE,
    MUS_RG_VS_DEO,
    MUS_RG_VS_MYU2
};

enum {
    PASS_SPECIES,
    PASS_ITEM,
    PASS_MAPSEC,
    PASS_TYPE,
    PASS_MOVE,
    PASS_STATION
};

const u8 *const gRadioShowNames[] = 
{
    gText_OaksPkmnTalk,
    gText_PokedexShow,
    gText_PokemonMusic,
    gText_LuckyChannel,
    gText_BuenasPassword,
    gText_PlacesAndPeople,
    gText_LetsAllSing,
    gText_FiveMarks,
    gText_PokeFlute,
    gText_FiveMarks,
    gText_FiveMarks,
};

#define FREQ(a) (u8)(a * 2 - 1)

u8 LoadStation_PokemonChannel(void);
u8 LoadStation_PokemonMusic(void);
u8 LoadStation_LuckyChannel(void);
u8 LoadStation_BuenasPassword(void);
u8 LoadStation_UnownRadio(void);
u8 LoadStation_EvolutionRadio(void);

const struct RadioStation gRadioStationData[] = {
    { FREQ(4.5), REGION_JOHTO, LoadStation_PokemonChannel },
    { FREQ(7.5), REGION_JOHTO, LoadStation_PokemonMusic },
    { FREQ(8.5), REGION_JOHTO, LoadStation_LuckyChannel },
    { FREQ(10.5), REGION_JOHTO, LoadStation_BuenasPassword },
    { FREQ(13.5), REGION_JOHTO, LoadStation_UnownRadio },
    { FREQ(20.5), REGION_JOHTO, LoadStation_EvolutionRadio },
    { 0xFF, 0xFF, NULL }
};

static void PlayStationMusic(u8 taskId)
{
    if (gTasks[taskId].tNumLinesPrinted == 0)
        PlayNewMapMusic(sRadioChannelSongs[gTasks[taskId].tCurrentLine]);
}

static bool8 BuenasPassword_CheckTime(void)
{
    RtcCalcLocalTime();
    if (gLocalTime.hours >= 18) // 6 PM
        return TRUE;
    return FALSE;
}

static void NextRadioLine(u8 taskId, u8 nextLine, const u8 *lineToPrint, bool8 shouldScroll)
{
    s16 *data = gTasks[taskId].data;
    u8 yPos = 1;
    u8 lineHeight = GetFontAttribute(1, FONTATTR_MAX_LETTER_HEIGHT) + GetFontAttribute(1, FONTATTR_LINE_SPACING);
    
    if (tNumLinesPrinted != 0)
        yPos += lineHeight;

    if (lineToPrint)
        AddTextPrinterParameterized(tWindowId, 1, lineToPrint, 0, yPos, 0, NULL);

    tNumLinesPrinted += lineToPrint ? 1 : 0;
    tNextLine = nextLine;
    tCurrentLine = RADIO_SCROLL;
    tTextDelay = 100;
    tScrollDistance = shouldScroll ? lineHeight : 0;
}

void PlayPokemonMusic(void)
{
    u16 song = MUS_AYASII;  // Sunday, Tuesday, Thursday, Saturday
    RtcCalcLocalTime();
    if (gLocalTime.dayOfWeek & 1)   // Monday, Wednesday, Friday
        song = MUS_ASHROAD;
    PlayNewMapMusic(song);
}

const u8 *GetBuenasPassword(u8 category, u8 index)
{
    const u8 *string;
    u16 value;

    // TODO: Proper widths
    const struct {
        u8 width;
        u8 type;
        u16 values[3];
    } passwords[] = {
        { 10, PASS_SPECIES, { SPECIES_CYNDAQUIL,    SPECIES_TOTODILE,           SPECIES_CHIKORITA } },
        { 12, PASS_ITEM,    { ITEM_FRESH_WATER,     ITEM_SODA_POP,              ITEM_LEMONADE } },
        { 12, PASS_ITEM,    { ITEM_POTION,          ITEM_ANTIDOTE,              ITEM_PARALYZE_HEAL } },
        { 12, PASS_ITEM,    { ITEM_POKE_BALL,       ITEM_GREAT_BALL,            ITEM_ULTRA_BALL } },
        { 10, PASS_SPECIES, { SPECIES_PIKACHU,      SPECIES_RATTATA,            SPECIES_GEODUDE } },
        { 10, PASS_SPECIES, { SPECIES_HOOTHOOT,     SPECIES_SPINARAK,           SPECIES_DROWZEE } },
        { 16, PASS_MAPSEC,  { MAPSEC_NEW_BARK_TOWN, MAPSEC_CHERRYGROVE_CITY,    MAPSEC_AZALEA_TOWN } },
        { 6,  PASS_TYPE,    { TYPE_FLYING,          TYPE_BUG,                   TYPE_GRASS } },
        { 12, PASS_MOVE,    { MOVE_TACKLE,          MOVE_GROWL,                 MOVE_MUD_SLAP } },
        { 12, PASS_ITEM,    { ITEM_X_ATTACK,        ITEM_X_DEFEND,              ITEM_X_SPEED } },
        { 13, PASS_STATION, { OAKS_POKEMON_TALK,    POKEMON_MUSIC,              LUCKY_CHANNEL } }
    };

    value = passwords[category].values[index];

    switch (passwords[category].type)
    {
        case PASS_SPECIES:
            string = gSpeciesNames[value];
            break;
        case PASS_ITEM:
            string = gItems[value].name;
            break;
        case PASS_MAPSEC:
            string = gRegionMapEntries[value].name;
            break;
        case PASS_TYPE:
            string = gTypeNames[value];
            break;
        case PASS_MOVE:
            string = gMoveNames[value];
            break;
        case PASS_STATION:
            string = gRadioShowNames[value];
            break;
    }

    return string;
}

void Task_PlayRadioShow(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (tCurrentLine < UNOWN_RADIO && GetCurrentRegion() == REGION_JOHTO && FlagGet(FLAG_ROCKET_TAKEOVER))
    {
        tShowNameId = tCurrentLine; // always show show title when Rockets are taking over
        tCurrentLine = ROCKET_RADIO;
    }

    switch (tCurrentLine)
    {
    case OAKS_POKEMON_TALK:
        tShowNameId = tCurrentLine;
        tMiscValue = 5;   // play five Oak segments then channel interlude
        PlayStationMusic(taskId);
        NextRadioLine(taskId, OAKS_POKEMON_TALK_2, gText_OaksPkmnTalkIntro1, TRUE);
        break;
    case POKEDEX_SHOW:
        {
            u16 species;
            u16 **caughtMons = (u16 **)&tMiscPtr;
            tShowNameId = tCurrentLine;
            PlayStationMusic(taskId);
            tMiscValue = SPECIES_NONE;
            
            if (*caughtMons == NULL)
            {
                *caughtMons = AllocZeroed(sizeof(u16) * 386);
                if (*caughtMons)
                {
                    for (species = 1, tMiscValue2 = 0; species <= 386; species++)
                    {
                        if (GetSetPokedexFlag(species, FLAG_GET_CAUGHT))
                        {
                            *caughtMons[tMiscValue2] = species;
                            tMiscValue2++;
                        }
                    }
                }
            }

            if (*caughtMons && tMiscValue2 > 0)
                tMiscValue = *caughtMons[Random() % tMiscValue2];

            StringCopy10(gStringVar4, gSpeciesNames[NationalPokedexNumToSpecies(tMiscValue)]);
            NextRadioLine(taskId, POKEDEX_SHOW_2, gStringVar4, TRUE);
        }
        break;
    case POKEMON_MUSIC:
        tShowNameId = tCurrentLine;
        PlayPokemonMusic();
        NextRadioLine(taskId, POKEMON_MUSIC_2, gText_PkmnMusicBen1, TRUE);
        break;
    case LUCKY_CHANNEL:
        tShowNameId = tCurrentLine;
        PlayStationMusic(taskId);
        DoTimeBasedEvents();
        ConvertIntToDecimalStringN(gStringVar1, (u16)GetLotteryNumber(), STR_CONV_MODE_LEADING_ZEROS, 5);
        NextRadioLine(taskId, LUCKY_NUMBER_SHOW_2, gText_LuckyChannel1, TRUE);
        break;
    case BUENAS_PASSWORD:
        if (BuenasPassword_CheckTime())
        {
            tShowNameId = tCurrentLine;
            PlayStationMusic(taskId);
            NextRadioLine(taskId, BUENAS_PASSWORD_2, gText_BuenasPassword1, TRUE);
        }
        else
        {
            if (tNumLinesPrinted == 0)
            {
                PlayNewMapMusic(MUS_DUMMY);
                tCurrentLine = BUENAS_PASSWORD_21;
            }
            else
            {
                tCurrentLine = BUENAS_PASSWORD_8;
            }
        }
        break;
    case PLACES_AND_PEOPLE:
        tShowNameId = tCurrentLine;
        PlayStationMusic(taskId);
        NextRadioLine(taskId, PLACES_AND_PEOPLE_2, gText_PlacesAndPeople1, TRUE);
        break;
    case LETS_ALL_SING:
        tShowNameId = tCurrentLine;
        PlayPokemonMusic();
        NextRadioLine(taskId, LETS_ALL_SING_2, gText_PkmnMusicFern1, TRUE);
        break;
    case ROCKET_RADIO:
        tShowNameId = tCurrentLine;
        PlayStationMusic(taskId);
        NextRadioLine(taskId, ROCKET_RADIO_2, gText_RocketRadio1, TRUE);
        break;
    case POKE_FLUTE_RADIO:
    case UNOWN_RADIO:
    case EVOLUTION_RADIO:
        tShowNameId = tCurrentLine;
        PlayStationMusic(taskId);
        tNumLinesPrinted = 1;
        break;
    case OAKS_POKEMON_TALK_2:
        NextRadioLine(taskId, OAKS_POKEMON_TALK_3, gText_OaksPkmnTalkIntro2, TRUE);
        break;
    case OAKS_POKEMON_TALK_3:
        NextRadioLine(taskId, OAKS_POKEMON_TALK_4, gText_OaksPkmnTalkIntro3, TRUE);
        break;
    case OAKS_POKEMON_TALK_4:
        {
            static const struct {
                u8 mapSec;
                u8 group;
                u8 num;
            } oaksTalkRoutes[] = {
                { MAPSEC_ROUTE_29, MAP_GROUP(ROUTE29), MAP_NUM(ROUTE29) },
                { MAPSEC_ROUTE_30, MAP_GROUP(ROUTE30), MAP_NUM(ROUTE30) },
                { MAPSEC_ROUTE_31, MAP_GROUP(ROUTE31), MAP_NUM(ROUTE31) },
                { MAPSEC_ROUTE_104, MAP_GROUP(ROUTE104), MAP_NUM(ROUTE104) },
                { MAPSEC_ROUTE_110, MAP_GROUP(ROUTE110), MAP_NUM(ROUTE110) },
                { MAPSEC_ROUTE_111, MAP_GROUP(ROUTE111), MAP_NUM(ROUTE111) },
                { MAPSEC_ROUTE_112, MAP_GROUP(ROUTE112), MAP_NUM(ROUTE112) },
                { MAPSEC_ROUTE_113, MAP_GROUP(ROUTE113), MAP_NUM(ROUTE113) },
                { MAPSEC_ROUTE_114, MAP_GROUP(ROUTE114), MAP_NUM(ROUTE114) },
                { MAPSEC_ROUTE_115, MAP_GROUP(ROUTE116), MAP_NUM(ROUTE116) },
                { MAPSEC_ROUTE_29, MAP_GROUP(ROUTE29), MAP_NUM(ROUTE29) },
                { MAPSEC_ROUTE_30, MAP_GROUP(ROUTE30), MAP_NUM(ROUTE30) },
                { MAPSEC_ROUTE_31, MAP_GROUP(ROUTE31), MAP_NUM(ROUTE31) },
                { MAPSEC_ROUTE_104, MAP_GROUP(ROUTE104), MAP_NUM(ROUTE104) },
                { MAPSEC_ROUTE_110, MAP_GROUP(ROUTE110), MAP_NUM(ROUTE110) },
            };

            u8 map = Random() % 15;
            u8 timeOfDay = Random() % 3;
            u8 monNum = Random() % 3;
            u16 species = GetMapWildMonFromIndex(oaksTalkRoutes[map].group, oaksTalkRoutes[map].num, monNum + 1);
            
            StringCopy(gStringVar1, gSpeciesNames[species]);
            StringCopy(gStringVar2, gRegionMapEntries[oaksTalkRoutes[map].mapSec].name);
            StringExpandPlaceholders(gStringVar4, gText_OaksPkmnTalk1);

            NextRadioLine(taskId, OAKS_POKEMON_TALK_5, gStringVar4, TRUE);
        }
        break;
    case OAKS_POKEMON_TALK_5:
        NextRadioLine(taskId, OAKS_POKEMON_TALK_6, gText_OaksPkmnTalk2, TRUE);
        break;
    case OAKS_POKEMON_TALK_6:
        StringExpandPlaceholders(gStringVar4, gText_OaksPkmnTalk3);
        NextRadioLine(taskId, OAKS_POKEMON_TALK_7, gStringVar4, TRUE);
        break;
    case OAKS_POKEMON_TALK_7:
        StringExpandPlaceholders(gStringVar4, gText_OaksPkmnTalk4);
        NextRadioLine(taskId, OAKS_POKEMON_TALK_8, gStringVar4, TRUE);
        break;
    case OAKS_POKEMON_TALK_8:
        {
            static const u8 *const adverbs[] = {
                gText_OPTAdverbSweetAndAdorably,
                gText_OPTAdverbWigglyAndSlickly,
                gText_OPTAdverbAptlyNamedAnd,
                gText_OPTAdverbUndeniablyKindOf,
                gText_OPTAdverbSoSoUnbearably,
                gText_OPTAdverbWowImpressively,
                gText_OPTAdverbAlmostPoisonously,
                gText_OPTAdverbOohSoSensually,
                gText_OPTAdverbSoMischievously,
                gText_OPTAdverbSoVeryTopically,
                gText_OPTAdverbSureAddictively,
                gText_OPTAdverbLooksInWaterIs,
                gText_OPTAdverbEvolutionMustBe,
                gText_OPTAdverbProvocatively,
                gText_OPTAdverbSoFlippedOutAnd,
                gText_OPTAdverbHeartMeltingly,
            };
            NextRadioLine(taskId, OAKS_POKEMON_TALK_9, adverbs[Random() % 16], TRUE);
        }
        break;
    case OAKS_POKEMON_TALK_9:
        {
            static const u8 *const adverbs[] = {
                gText_OPTAdjectiveCute,
                gText_OPTAdjectiveWeird,
                gText_OPTAdjectivePleasant,
                gText_OPTAdjectiveBoldSortOf,
                gText_OPTAdjectiveFrightening,
                gText_OPTAdjectiveSuaveAndDebonair,
                gText_OPTAdjectivePowerful,
                gText_OPTAdjectiveExciting,
                gText_OPTAdjectiveGroovy,
                gText_OPTAdjectiveInspiring,
                gText_OPTAdjectiveFriendly,
                gText_OPTAdjectiveHotHotHot,
                gText_OPTAdjectiveStimulating,
                gText_OPTAdjectiveGuarded,
                gText_OPTAdjectiveLovely,
                gText_OPTAdjectiveSpeedy
            };
            if (--tMiscValue > 0)
            {
                NextRadioLine(taskId, OAKS_POKEMON_TALK_4, adverbs[Random() % 16], TRUE);
            }
            else
            {
                tMiscValue = 5;
                NextRadioLine(taskId, PKMN_CHANNEL_INTERLUDE_1, adverbs[Random() % 16], TRUE);
                tCurrentLine = PKMN_CHANNEL_INTERLUDE_1;
                tNextLine = NO_RADIO_SHOW;
                tTextDelay = 100;
            }
        }
        break;
    case POKEDEX_SHOW_2:
        CopyMonCategoryText(tMiscValue, gStringVar4);
        NextRadioLine(taskId, POKEDEX_SHOW_3, gStringVar4, TRUE);
        break;
    case POKEDEX_SHOW_3:
        StringCopy(gStringVar4, gPokedexEntries[tMiscValue].description);
        tMiscValue = 0;
    case POKEDEX_SHOW_4:
        {
            u8 index;
            for (index = tMiscValue; index < 0x3E8; index++)
            {
                if (gStringVar4[index] == CHAR_NEWLINE)
                {
                    gStringVar4[index] = EOS;
                    NextRadioLine(taskId, POKEDEX_SHOW_4, &gStringVar4[tMiscValue], TRUE);
                    tMiscValue = index + 1;
                    break;
                }
                else if (gStringVar4[index] == EOS)
                {
                    NextRadioLine(taskId, POKEDEX_SHOW, &gStringVar4[tMiscValue], TRUE);
                    break;
                }
            }
        }
        break;
    case POKEDEX_SHOW_5:
        break;
    case POKEMON_MUSIC_2:
        NextRadioLine(taskId, POKEMON_MUSIC_3, gText_PkmnMusicBen2, TRUE);
        break;
    case POKEMON_MUSIC_3:
        NextRadioLine(taskId, POKEMON_MUSIC_4, gText_PkmnMusicBen3, TRUE);
        break;
    case POKEMON_MUSIC_4:
        StringCopy(gStringVar1, GetDayOfWeekString(gLocalTime.dayOfWeek));
        StringExpandPlaceholders(gStringVar4, gText_PkmnMusicBenFern1);
        NextRadioLine(taskId, POKEMON_MUSIC_5, gStringVar4, TRUE);
        break;
    case POKEMON_MUSIC_5:
        {
            const u8 *string = gText_PkmnMusicBenFern2A;    // Sunday, Tuesday, Thursday, Saturday
            if (gLocalTime.dayOfWeek & 1)   // Monday, Wednesday, Friday
            {
                string = gText_PkmnMusicBenFern2B;
            }
            NextRadioLine(taskId, POKEMON_MUSIC_6, string, TRUE);
        }
        break;
    case POKEMON_MUSIC_6:
        {
            const u8 *string = gText_PkmnMusicBenFern3A;    // Sunday, Tuesday, Thursday, Saturday
            if (gLocalTime.dayOfWeek & 1)   // Monday, Wednesday, Friday
            {
                string = gText_PkmnMusicBenFern3B;
            }
            NextRadioLine(taskId, POKEMON_MUSIC_7, string, TRUE);
        }
        break;
    case POKEMON_MUSIC_7:
        break;
    case LETS_ALL_SING_2:
        NextRadioLine(taskId, POKEMON_MUSIC_4, gText_PkmnMusicFern2, TRUE);
        break;
    case LUCKY_NUMBER_SHOW_2:
        NextRadioLine(taskId, LUCKY_NUMBER_SHOW_3, gText_LuckyChannel2, TRUE);
        break;
    case LUCKY_NUMBER_SHOW_3:
        NextRadioLine(taskId, LUCKY_NUMBER_SHOW_4, gText_LuckyChannel3, TRUE);
        break;
    case LUCKY_NUMBER_SHOW_4:
        NextRadioLine(taskId, LUCKY_NUMBER_SHOW_5, gText_LuckyChannel4, TRUE);
        break;
    case LUCKY_NUMBER_SHOW_5:
        NextRadioLine(taskId, LUCKY_NUMBER_SHOW_6, gText_LuckyChannel5, TRUE);
        break;
    case LUCKY_NUMBER_SHOW_6:
        NextRadioLine(taskId, LUCKY_NUMBER_SHOW_7, gText_LuckyChannel6, TRUE);
        break;
    case LUCKY_NUMBER_SHOW_7:
        NextRadioLine(taskId, LUCKY_NUMBER_SHOW_8, gText_LuckyChannel7, TRUE);
        break;
    case LUCKY_NUMBER_SHOW_8:
        StringExpandPlaceholders(gStringVar4, gText_LuckyChannel8);
        NextRadioLine(taskId, LUCKY_NUMBER_SHOW_9, gStringVar4, TRUE);
        break;
    case LUCKY_NUMBER_SHOW_9:
        NextRadioLine(taskId, LUCKY_NUMBER_SHOW_10, gText_LuckyChannel9, TRUE);
        break;
    case LUCKY_NUMBER_SHOW_10:
        NextRadioLine(taskId, LUCKY_NUMBER_SHOW_11, gText_LuckyChannel7, TRUE);
        break;
    case LUCKY_NUMBER_SHOW_11:
        StringExpandPlaceholders(gStringVar4, gText_LuckyChannel8);
        NextRadioLine(taskId, LUCKY_NUMBER_SHOW_12, gStringVar4, TRUE);
        break;
    case LUCKY_NUMBER_SHOW_12:
        NextRadioLine(taskId, LUCKY_NUMBER_SHOW_13, gText_LuckyChannel10, TRUE);
        break;
    case LUCKY_NUMBER_SHOW_13:
        {
            u8 nextLine = LUCKY_CHANNEL;
            if (Random() % 16 == 0)
            {
                nextLine = LUCKY_NUMBER_SHOW_14;
            }
            NextRadioLine(taskId, nextLine, gText_LuckyChannel11, TRUE);
        }
        break;
    case LUCKY_NUMBER_SHOW_14:
        NextRadioLine(taskId, LUCKY_NUMBER_SHOW_3, gText_LuckyChannel12, TRUE);
        break;
    case LUCKY_NUMBER_SHOW_15:
        NextRadioLine(taskId, LUCKY_CHANNEL, gText_LuckyChannel13, TRUE);
        break;
    case PLACES_AND_PEOPLE_2:
        break;
    case PLACES_AND_PEOPLE_3:
        break;
    case PLACES_AND_PEOPLE_4:
        break;
    case PLACES_AND_PEOPLE_5:
        break;
    case PLACES_AND_PEOPLE_6:
        break;
    case PLACES_AND_PEOPLE_7:
        break;
    case ROCKET_RADIO_2:
        NextRadioLine(taskId, ROCKET_RADIO_3, gText_RocketRadio2, TRUE);
        break;
    case ROCKET_RADIO_3:
        NextRadioLine(taskId, ROCKET_RADIO_4, gText_RocketRadio3, TRUE);
        break;
    case ROCKET_RADIO_4:
        NextRadioLine(taskId, ROCKET_RADIO_5, gText_RocketRadio4, TRUE);
        break;
    case ROCKET_RADIO_5:
        NextRadioLine(taskId, ROCKET_RADIO_6, gText_RocketRadio5, TRUE);
        break;
    case ROCKET_RADIO_6:
        NextRadioLine(taskId, ROCKET_RADIO_7, gText_RocketRadio6, TRUE);
        break;
    case ROCKET_RADIO_7:
        NextRadioLine(taskId, ROCKET_RADIO_8, gText_RocketRadio7, TRUE);
        break;
    case ROCKET_RADIO_8:
        NextRadioLine(taskId, ROCKET_RADIO_9, gText_RocketRadio8, TRUE);
        break;
    case ROCKET_RADIO_9:
        NextRadioLine(taskId, ROCKET_RADIO_10, gText_RocketRadio9, TRUE);
        break;
    case ROCKET_RADIO_10:
        NextRadioLine(taskId, ROCKET_RADIO, gText_RocketRadio10, TRUE);
        break;
    case PKMN_CHANNEL_INTERLUDE_1:
        if (tTextDelay == 0)
        {
            tCurrentLine = PKMN_CHANNEL_INTERLUDE_2;
        }
        else
        {
            tTextDelay--;
        }
        break;
    case PKMN_CHANNEL_INTERLUDE_2:
        FillWindowPixelBuffer(tWindowId, 0x11);
        AddTextPrinterParameterized(tWindowId, 1, gText_PokemonChannel1, 0, 1, 0, NULL);
        PlayFanfare(MUS_ME_TAMA);
        tCurrentLine = PKMN_CHANNEL_INTERLUDE_3;
        break;
    case PKMN_CHANNEL_INTERLUDE_3:
        if (IsFanfareTaskInactive())
        {
            FillWindowPixelBuffer(tWindowId, 0x11);
            tCurrentLine = OAKS_POKEMON_TALK;
            tNumLinesPrinted = 0;
        }
        break;
    case BUENAS_PASSWORD_2:
        NextRadioLine(taskId, BUENAS_PASSWORD_3, gText_BuenasPassword2, TRUE);
        break;
    case BUENAS_PASSWORD_3:
        {
            u8 nextLine = BUENAS_PASSWORD_4;
            if (!BuenasPassword_CheckTime())
            {
                nextLine = BUENAS_PASSWORD_8;
            }
            NextRadioLine(taskId, nextLine, gText_BuenasPassword3, TRUE);
        }
        break;
    case BUENAS_PASSWORD_4:
        {
            if (!BuenasPassword_CheckTime())
            {
                tCurrentLine = BUENAS_PASSWORD_8;
            }
            else
            {
                u16 password = 0;
                DoTimeBasedEvents();

                if (!FlagGet(FLAG_BUENAS_PASSWORD))
                {
                    password = (Random() % 11) << 8 | (Random() % 3);
                    VarSet(VAR_BUENAS_PASSWORD, password);
                    FlagSet(FLAG_BUENAS_PASSWORD);
                }
                else
                {
                    password = VarGet(VAR_BUENAS_PASSWORD);
                }

                StringCopy(gStringVar1, GetBuenasPassword(password >> 8, password & 0xFF));
                StringExpandPlaceholders(gStringVar4, gText_BuenasPassword4);
                NextRadioLine(taskId, BUENAS_PASSWORD_5, gStringVar4, TRUE);
            }
        }
        break;
    case BUENAS_PASSWORD_5:
        NextRadioLine(taskId, BUENAS_PASSWORD_6, gText_BuenasPassword5, TRUE);
        break;
    case BUENAS_PASSWORD_6:
        NextRadioLine(taskId, BUENAS_PASSWORD_7, gText_BuenasPassword6, TRUE);
        break;
    case BUENAS_PASSWORD_7:
        {
            u8 nextLine = BUENAS_PASSWORD;
            if (!BuenasPassword_CheckTime())
                nextLine = BUENAS_PASSWORD_8;
            NextRadioLine(taskId, nextLine, gText_BuenasPassword7, TRUE);
        }
        break;
    case BUENAS_PASSWORD_8:
        NextRadioLine(taskId, BUENAS_PASSWORD_9, gText_BuenasPassword17, TRUE);
        break;
    case BUENAS_PASSWORD_9:
        NextRadioLine(taskId, BUENAS_PASSWORD_10, gText_BuenasPassword8, TRUE);
        break;
    case BUENAS_PASSWORD_10:
        NextRadioLine(taskId, BUENAS_PASSWORD_11, gText_BuenasPassword9, TRUE);
        break;
    case BUENAS_PASSWORD_11:
        NextRadioLine(taskId, BUENAS_PASSWORD_12, gText_BuenasPassword10, TRUE);
        break;
    case BUENAS_PASSWORD_12:
        NextRadioLine(taskId, BUENAS_PASSWORD_13, gText_BuenasPassword11, TRUE);
        break;
    case BUENAS_PASSWORD_13:
        NextRadioLine(taskId, BUENAS_PASSWORD_14, gText_BuenasPassword12, TRUE);
        break;
    case BUENAS_PASSWORD_14:
        NextRadioLine(taskId, BUENAS_PASSWORD_15, gText_BuenasPassword13, TRUE);
        break;
    case BUENAS_PASSWORD_15:
        NextRadioLine(taskId, BUENAS_PASSWORD_16, gText_BuenasPassword14, TRUE);
        break;
    case BUENAS_PASSWORD_16:
        NextRadioLine(taskId, BUENAS_PASSWORD_17, gText_BuenasPassword15, TRUE);
        break;
    case BUENAS_PASSWORD_17:
        NextRadioLine(taskId, BUENAS_PASSWORD_18, gText_BuenasPassword16, FALSE);
        break;
    case BUENAS_PASSWORD_18:
        FillWindowPixelBuffer(tWindowId, 0x11);
        tNumLinesPrinted = 0;
        NextRadioLine(taskId, BUENAS_PASSWORD_19, gText_BuenasPassword17, FALSE);
        break;
    case BUENAS_PASSWORD_19:
        NextRadioLine(taskId, BUENAS_PASSWORD_20, NULL, FALSE);
        break;
    case BUENAS_PASSWORD_20:
        gTasks[taskId].tShowNameId = NO_RADIO_SHOW;
        FlagClear(FLAG_BUENAS_PASSWORD);
        FadeOutAndPlayNewMapMusic(MUS_DUMMY, 4);
        tCurrentLine = BUENAS_PASSWORD_21;
        tNumLinesPrinted = 0;
        break;
    case BUENAS_PASSWORD_21:
        if (BuenasPassword_CheckTime())
            tCurrentLine = BUENAS_PASSWORD;
        break;
    case RADIO_SCROLL:
        if (tTextDelay == 0)
        {
            if (tNumLinesPrinted > 1 && tScrollDistance)
            {
                #define RADIO_SCROLL_SPEED 2
                if (tScrollDistance < RADIO_SCROLL_SPEED)
                {
                    ScrollWindow(tWindowId, 0, tScrollDistance, 0x11);
                    tScrollDistance = 0;
                    tCurrentLine = tNextLine;
                }
                else
                {
                    ScrollWindow(tWindowId, 0, RADIO_SCROLL_SPEED, 0x11);
                    tScrollDistance -= RADIO_SCROLL_SPEED;
                }
                CopyWindowToVram(tWindowId, 2);
            }
            else
            {
                tCurrentLine = tNextLine;
            }
        }
        else
        {
            tTextDelay--;
        }
        break;
    default:
        FillWindowPixelBuffer(tWindowId, 0x11);
        CopyWindowToVram(tWindowId, 2);
        PlayNewMapMusic(MUS_DUMMY);
        break;
    }
}

u8 LoadStation_PokemonChannel(void)
{
    RtcCalcLocalTime();

    if (GetCurrentTimeOfDay() == TIME_MORNING)
        return POKEDEX_SHOW;
    else
        return OAKS_POKEMON_TALK;
}

u8 LoadStation_PokemonMusic(void)
{
    return POKEMON_MUSIC;
}

u8 LoadStation_LuckyChannel(void)
{
    return LUCKY_CHANNEL;
}

u8 LoadStation_BuenasPassword(void)
{
    return BUENAS_PASSWORD;
}

u8 LoadStation_UnownRadio(void)
{
    if (gMapHeader.regionMapSectionId == MAPSEC_RUINS_OF_ALPH)
        return UNOWN_RADIO;

    return 0xFF;
}

u8 LoadStation_EvolutionRadio(void)
{
    if (gMapHeader.regionMapSectionId == MAPSEC_MAHOGANY_TOWN ||
        gMapHeader.regionMapSectionId == MAPSEC_ROUTE_43 ||
        gMapHeader.regionMapSectionId == MAPSEC_LAKE_OF_RAGE)
    {
        return EVOLUTION_RADIO;
    }

    return 0xFF;
}

#define tTimer data[0]
#define tShowId data[1]
#define tRadioShowTaskId data[1]

void Task_FieldRadio_2(u8 taskId);

void Task_FieldRadio_1(u8 taskId)
{
    if (gTasks[taskId].tTimer == 0)
    {
        u8 *str = gStringVar4;
        
        u8 stationId = gSpecialVar_0x8004;

        if (stationId > ARRAY_COUNT(gRadioStationData) - 1)
            stationId = 0;

        gTasks[taskId].tShowId = gRadioStationData[stationId].loadFunc();

        if (gTasks[taskId].tShowId != 0xFF)
        {
            *(str++) = CHAR_DBL_QUOT_LEFT;
            str = StringCopy(str, gRadioShowNames[gTasks[taskId].tShowId]);
            *(str++) = CHAR_DBL_QUOT_RIGHT;
            *str = EOS;
        }
        AddTextPrinterParameterized(0, 1, gStringVar4, 0, 1, 0, NULL);
    }
    else if (gTasks[taskId].tTimer > 100)
    {
        u8 radioShowTaskId = CreateTask(Task_PlayRadioShow, 80);

        gTasks[radioShowTaskId].tWindowId = 0;
        gTasks[radioShowTaskId].tCurrentLine = gTasks[taskId].tShowId;

        gTasks[taskId].tRadioShowTaskId = radioShowTaskId;

        FillWindowPixelBuffer(0, 0x11);
        CopyWindowToVram(0, 2);

        gTasks[taskId].func = Task_FieldRadio_2;
    }
    gTasks[taskId].tTimer++;
}

void Task_FieldRadio_2(u8 taskId)
{
    RunTextPrinters();  // TODO: This is needed for the RADIO_PAUSE, but is this the right way to do it?
    if (gMain.newKeys & (A_BUTTON | B_BUTTON))
    {
        ClearDialogWindowAndFrame(0, TRUE);
        EnableBothScriptContexts();

        DestroyTask(gTasks[taskId].tRadioShowTaskId);
        DestroyTask(taskId);
    }
}

bool16 FieldRadio(void)
{
    if (FuncIsActiveTask(Task_FieldRadio_1) == TRUE)
        return FALSE;

    sub_81973A4();
    DrawDialogueFrame(0, 1);
    CreateTask(Task_FieldRadio_1, 3);
    return TRUE;
}

#undef tRadioShowTaskId
