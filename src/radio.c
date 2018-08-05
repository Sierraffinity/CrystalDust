#include "global.h"
#include "main.h"
#include "clock.h"
#include "data2.h"
#include "day_night.h"
#include "event_data.h"
#include "lottery_corner.h"
#include "malloc.h"
#include "pokedex.h"
#include "radio.h"
#include "random.h"
#include "region_map.h"
#include "rtc.h"
#include "sound.h"
#include "strings.h"
#include "string_util.h"
#include "task.h"
#include "text.h"
#include "wild_encounter.h"
#include "window.h"
#include "constants/flags.h"
#include "constants/maps.h"
#include "constants/region_map_sections.h"
#include "constants/songs.h"
#include "constants/species.h"

#define tCurrentLine data[0]
#define tNextLine data[1]
#define tNumLinesPrinted data[2]
#define tScrollDistance data[3]
#define tTextDelay data[4]
#define tMiscValue data[5]

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

static void PlayStationMusic(u8 taskId)
{
    if (gTasks[taskId].tNumLinesPrinted == 0)
    {
        PlayNewMapMusic(sRadioChannelSongs[gTasks[taskId].tCurrentLine]);
    }
}

static bool8 BuenasPassword_CheckTime(void)
{
    RtcCalcLocalTime();
    if (gLocalTime.hours >= TIME_NIGHT_HOUR)
    {
        return TRUE;
    }
    return FALSE;
}

static void NextRadioLine(u8 taskId, u8 windowId, u8 nextLine, const u8 *lineToPrint)
{
    u8 yPos = 1;
    u8 lineHeight = GetFontAttribute(1, FONTATTR_MAX_LETTER_HEIGHT) + GetFontAttribute(1, FONTATTR_LINE_SPACING);
    
    if (gTasks[taskId].tNumLinesPrinted != 0)
    {
        yPos += lineHeight;
    }

    PrintTextOnWindow(windowId, 1, lineToPrint, 0, yPos, 0, NULL);
    gTasks[taskId].tNumLinesPrinted++;
    gTasks[taskId].tNextLine = nextLine;
    gTasks[taskId].tCurrentLine = RADIO_SCROLL;
    gTasks[taskId].tTextDelay = 100;
    gTasks[taskId].tScrollDistance = lineHeight;
}

extern void DrawStationTitle(const u8 *title);

void PlayPokemonMusic(void)
{
    u16 song = MUS_AYASII;  // Sunday, Tuesday, Thursday, Saturday
    RtcCalcLocalTime();
    if (gLocalTime.dayOfWeek & 1)   // Monday, Wednesday, Friday
    {
        song = MUS_ASHROAD;
    }
    PlayNewMapMusic(song);
}

void PlayRadioShow(u8 taskId, u8 windowId)
{
    s16 *data = gTasks[taskId].data;

    if (tCurrentLine < UNOWN_RADIO && GetCurrentRegion() == REGION_JOHTO && FlagGet(FLAG_ROCKET_TAKEOVER))
    {
        tCurrentLine = ROCKET_RADIO;
    }

    switch (tCurrentLine)
    {
    case OAKS_POKEMON_TALK:
        tMiscValue = 5;   // play five Oak segments then channel interlude
        PlayStationMusic(taskId);
        NextRadioLine(taskId, windowId, OAKS_POKEMON_TALK_2, gText_OaksPkmnTalkIntro1);
        break;
    case POKEDEX_SHOW:
        {
            // TODO: Suboptimal here, should hold onto caughtMons until show unload (but we don't have a hook for that yet)
            u16 *caughtMons = AllocZeroed(sizeof(u16[386]));
            u16 species, caughtMonCount;
            PlayStationMusic(taskId);
            tMiscValue = SPECIES_NONE;
            
            if (caughtMons)
            {
                for (species = 1, caughtMonCount = 0; species <= 386; species++)
                {
                    if (GetSetPokedexFlag(species, 1))
                    {
                        caughtMons[caughtMonCount] = species;
                        caughtMonCount++;
                    }
                }

                if (caughtMonCount > 0)
                {
                    tMiscValue = caughtMons[Random() % caughtMonCount];
                }

                FREE_AND_SET_NULL(caughtMons);
            }

            StringCopy10(gStringVar4, gSpeciesNames[NationalPokedexNumToSpecies(tMiscValue)]);
            NextRadioLine(taskId, windowId, POKEDEX_SHOW_2, gStringVar4);
        }
        break;
    case POKEMON_MUSIC:
        PlayPokemonMusic();
        NextRadioLine(taskId, windowId, POKEMON_MUSIC_2, gText_PkmnMusicBen1);
        break;
    case LUCKY_CHANNEL:
        PlayStationMusic(taskId);
        DoTimeBasedEvents();
        ConvertUIntToDecimalStringN(gStringVar1, GetLotteryNumber(), STR_CONV_MODE_LEADING_ZEROS, 5);
        NextRadioLine(taskId, windowId, LUCKY_NUMBER_SHOW_2, gText_LuckyChannel1);
        break;
    case BUENAS_PASSWORD:
        if (BuenasPassword_CheckTime())
        {
            DrawStationTitle(gText_BuenasPassword); // Buena's Password will never play on a regular radio so this should be okay
            PlayStationMusic(taskId);
            NextRadioLine(taskId, windowId, BUENAS_PASSWORD_2, gText_BuenasPassword1);
        }
        else
        {
            if (tNumLinesPrinted == 0)
            {
                tCurrentLine = BUENAS_PASSWORD_20;
            }
            else
            {
                tCurrentLine = BUENAS_PASSWORD_8;
            }
        }
        break;
    case PLACES_AND_PEOPLE:
        PlayStationMusic(taskId);
        NextRadioLine(taskId, windowId, PLACES_AND_PEOPLE_2, gText_PlacesAndPeople1);
        break;
    case LETS_ALL_SING:
        PlayPokemonMusic();
        NextRadioLine(taskId, windowId, LETS_ALL_SING_2, gText_PkmnMusicFernIntro1);
        break;
    case ROCKET_RADIO:
        PlayStationMusic(taskId);
        NextRadioLine(taskId, windowId, ROCKET_RADIO_2, gText_RocketRadio1);
        break;
    case POKE_FLUTE_RADIO:
    case UNOWN_RADIO:
    case EVOLUTION_RADIO:
        PlayStationMusic(taskId);
        tNumLinesPrinted = 1;
        break;
    case OAKS_POKEMON_TALK_2:
        NextRadioLine(taskId, windowId, OAKS_POKEMON_TALK_3, gText_OaksPkmnTalkIntro2);
        break;
    case OAKS_POKEMON_TALK_3:
        NextRadioLine(taskId, windowId, OAKS_POKEMON_TALK_4, gText_OaksPkmnTalkIntro3);
        break;
    case OAKS_POKEMON_TALK_4:
        {
            static const struct {
                u8 mapSec;
                u8 group;
                u8 num;
            } oaksTalkRoutes[] = {
                { MAPSEC_ROUTE_101, MAP_GROUP(ROUTE101), MAP_NUM(ROUTE101) },
                { MAPSEC_ROUTE_102, MAP_GROUP(ROUTE102), MAP_NUM(ROUTE102) },
                { MAPSEC_ROUTE_103, MAP_GROUP(ROUTE103), MAP_NUM(ROUTE103) },
                { MAPSEC_ROUTE_104, MAP_GROUP(ROUTE104), MAP_NUM(ROUTE104) },
                { MAPSEC_ROUTE_110, MAP_GROUP(ROUTE110), MAP_NUM(ROUTE110) },
                { MAPSEC_ROUTE_111, MAP_GROUP(ROUTE111), MAP_NUM(ROUTE111) },
                { MAPSEC_ROUTE_112, MAP_GROUP(ROUTE112), MAP_NUM(ROUTE112) },
                { MAPSEC_ROUTE_113, MAP_GROUP(ROUTE113), MAP_NUM(ROUTE113) },
                { MAPSEC_ROUTE_114, MAP_GROUP(ROUTE114), MAP_NUM(ROUTE114) },
                { MAPSEC_ROUTE_115, MAP_GROUP(ROUTE116), MAP_NUM(ROUTE116) },
                { MAPSEC_ROUTE_101, MAP_GROUP(ROUTE101), MAP_NUM(ROUTE101) },
                { MAPSEC_ROUTE_102, MAP_GROUP(ROUTE102), MAP_NUM(ROUTE102) },
                { MAPSEC_ROUTE_103, MAP_GROUP(ROUTE103), MAP_NUM(ROUTE103) },
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

            NextRadioLine(taskId, windowId, OAKS_POKEMON_TALK_5, gStringVar4);
        }
        break;
    case OAKS_POKEMON_TALK_5:
        NextRadioLine(taskId, windowId, OAKS_POKEMON_TALK_6, gText_OaksPkmnTalk2);
        break;
    case OAKS_POKEMON_TALK_6:
        StringExpandPlaceholders(gStringVar4, gText_OaksPkmnTalk3);
        NextRadioLine(taskId, windowId, OAKS_POKEMON_TALK_7, gStringVar4);
        break;
    case OAKS_POKEMON_TALK_7:
        StringExpandPlaceholders(gStringVar4, gText_OaksPkmnTalk4);
        NextRadioLine(taskId, windowId, OAKS_POKEMON_TALK_8, gStringVar4);
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
            NextRadioLine(taskId, windowId, OAKS_POKEMON_TALK_9, adverbs[Random() % 16]);
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
                NextRadioLine(taskId, windowId, OAKS_POKEMON_TALK_4, adverbs[Random() % 16]);
            }
            else
            {
                tMiscValue = 5;
                NextRadioLine(taskId, windowId, PKMN_CHANNEL_INTERLUDE_1, adverbs[Random() % 16]);
                tCurrentLine = PKMN_CHANNEL_INTERLUDE_1;
                tNextLine = NO_RADIO_SHOW;
                tTextDelay = 100;
            }
        }
        break;
    case POKEDEX_SHOW_2:
        CopyMonCategoryText(tMiscValue, gStringVar4);
        NextRadioLine(taskId, windowId, POKEDEX_SHOW_3, gStringVar4);
        break;
    case POKEDEX_SHOW_3:
        StringCopy(gStringVar4, gPokedexEntries[tMiscValue].description);
        tMiscValue = 0;
    case POKEDEX_SHOW_4:
        {
            u8 index;
            for (index = tMiscValue; index < 0x3E8; index++)
            {
                if (gStringVar4[index] == 0xFE)
                {
                    gStringVar4[index] = 0xFF;
                    NextRadioLine(taskId, windowId, POKEDEX_SHOW_4, &gStringVar4[tMiscValue]);
                    tMiscValue = index + 1;
                    break;
                }
                else if (gStringVar4[index] == 0xFF)
                {
                    NextRadioLine(taskId, windowId, POKEDEX_SHOW, &gStringVar4[tMiscValue]);
                    break;
                }
            }
        }
        break;
    case POKEDEX_SHOW_5:
        break;
    case POKEMON_MUSIC_2:
        NextRadioLine(taskId, windowId, POKEMON_MUSIC_3, gText_PkmnMusicBen2);
        break;
    case POKEMON_MUSIC_3:
        NextRadioLine(taskId, windowId, POKEMON_MUSIC_4, gText_PkmnMusicBen3);
        break;
    case POKEMON_MUSIC_4:
        StringCopy(gStringVar1, GetDayOfWeekString());
        StringExpandPlaceholders(gStringVar4, gText_PkmnMusicBenFern1);
        NextRadioLine(taskId, windowId, POKEMON_MUSIC_5, gStringVar4);
        break;
    case POKEMON_MUSIC_5:
        {
            const u8 *string = gText_PkmnMusicBenFern2A;    // Sunday, Tuesday, Thursday, Saturday
            if (gLocalTime.dayOfWeek & 1)   // Monday, Wednesday, Friday
            {
                string = gText_PkmnMusicBenFern2B;
            }
            NextRadioLine(taskId, windowId, POKEMON_MUSIC_6, string);
        }
        break;
    case POKEMON_MUSIC_6:
        {
            const u8 *string = gText_PkmnMusicBenFern3A;    // Sunday, Tuesday, Thursday, Saturday
            if (gLocalTime.dayOfWeek & 1)   // Monday, Wednesday, Friday
            {
                string = gText_PkmnMusicBenFern3B;
            }
            NextRadioLine(taskId, windowId, POKEMON_MUSIC_7, string);
        }
        break;
    case POKEMON_MUSIC_7:
        break;
    case LETS_ALL_SING_2:
        NextRadioLine(taskId, windowId, POKEMON_MUSIC_4, gText_PkmnMusicFern2);
        break;
    case LUCKY_NUMBER_SHOW_2:
        NextRadioLine(taskId, windowId, LUCKY_NUMBER_SHOW_3, gText_LuckyChannel2);
        break;
    case LUCKY_NUMBER_SHOW_3:
        NextRadioLine(taskId, windowId, LUCKY_NUMBER_SHOW_4, gText_LuckyChannel3);
        break;
    case LUCKY_NUMBER_SHOW_4:
        NextRadioLine(taskId, windowId, LUCKY_NUMBER_SHOW_5, gText_LuckyChannel4);
        break;
    case LUCKY_NUMBER_SHOW_5:
        NextRadioLine(taskId, windowId, LUCKY_NUMBER_SHOW_6, gText_LuckyChannel5);
        break;
    case LUCKY_NUMBER_SHOW_6:
        NextRadioLine(taskId, windowId, LUCKY_NUMBER_SHOW_7, gText_LuckyChannel6);
        break;
    case LUCKY_NUMBER_SHOW_7:
        NextRadioLine(taskId, windowId, LUCKY_NUMBER_SHOW_8, gText_LuckyChannel7);
        break;
    case LUCKY_NUMBER_SHOW_8:
        StringExpandPlaceholders(gStringVar4, gText_LuckyChannel8);
        NextRadioLine(taskId, windowId, LUCKY_NUMBER_SHOW_9, gStringVar4);
        break;
    case LUCKY_NUMBER_SHOW_9:
        NextRadioLine(taskId, windowId, LUCKY_NUMBER_SHOW_10, gText_LuckyChannel9);
        break;
    case LUCKY_NUMBER_SHOW_10:
        NextRadioLine(taskId, windowId, LUCKY_NUMBER_SHOW_11, gText_LuckyChannel7);
        break;
    case LUCKY_NUMBER_SHOW_11:
        StringExpandPlaceholders(gStringVar4, gText_LuckyChannel8);
        NextRadioLine(taskId, windowId, LUCKY_NUMBER_SHOW_12, gStringVar4);
        break;
    case LUCKY_NUMBER_SHOW_12:
        NextRadioLine(taskId, windowId, LUCKY_NUMBER_SHOW_13, gText_LuckyChannel10);
        break;
    case LUCKY_NUMBER_SHOW_13:
        {
            u8 nextLine = LUCKY_CHANNEL;
            if (Random() % 16 == 0)
            {
                nextLine = LUCKY_NUMBER_SHOW_14;
            }
            NextRadioLine(taskId, windowId, nextLine, gText_LuckyChannel11);
        }
        break;
    case LUCKY_NUMBER_SHOW_14:
        NextRadioLine(taskId, windowId, LUCKY_NUMBER_SHOW_3, gText_LuckyChannel12);
        break;
    case LUCKY_NUMBER_SHOW_15:
        NextRadioLine(taskId, windowId, LUCKY_CHANNEL, gText_LuckyChannel13);
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
        NextRadioLine(taskId, windowId, ROCKET_RADIO_3, gText_RocketRadio2);
        break;
    case ROCKET_RADIO_3:
        NextRadioLine(taskId, windowId, ROCKET_RADIO_4, gText_RocketRadio3);
        break;
    case ROCKET_RADIO_4:
        NextRadioLine(taskId, windowId, ROCKET_RADIO_5, gText_RocketRadio4);
        break;
    case ROCKET_RADIO_5:
        NextRadioLine(taskId, windowId, ROCKET_RADIO_6, gText_RocketRadio5);
        break;
    case ROCKET_RADIO_6:
        NextRadioLine(taskId, windowId, ROCKET_RADIO_7, gText_RocketRadio6);
        break;
    case ROCKET_RADIO_7:
        NextRadioLine(taskId, windowId, ROCKET_RADIO_8, gText_RocketRadio7);
        break;
    case ROCKET_RADIO_8:
        NextRadioLine(taskId, windowId, ROCKET_RADIO_9, gText_RocketRadio8);
        break;
    case ROCKET_RADIO_9:
        NextRadioLine(taskId, windowId, ROCKET_RADIO_10, gText_RocketRadio9);
        break;
    case ROCKET_RADIO_10:
        NextRadioLine(taskId, windowId, ROCKET_RADIO, gText_RocketRadio10);
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
        FillWindowPixelBuffer(windowId, 0x11);
        PrintTextOnWindow(windowId, 1, gText_PokemonChannel1, 0, 1, 0, NULL);
        PlayFanfare(MUS_ME_TAMA);
        tCurrentLine = PKMN_CHANNEL_INTERLUDE_3;
        break;
    case PKMN_CHANNEL_INTERLUDE_3:
        if (IsFanfareTaskInactive())
        {
            FillWindowPixelBuffer(windowId, 0x11);
            tCurrentLine = OAKS_POKEMON_TALK;
            tNumLinesPrinted = 0;
        }
        break;
    case BUENAS_PASSWORD_2:
        break;
    case BUENAS_PASSWORD_3:
        break;
    case BUENAS_PASSWORD_4:
        break;
    case BUENAS_PASSWORD_5:
        break;
    case BUENAS_PASSWORD_6:
        break;
    case BUENAS_PASSWORD_7:
        break;
    case BUENAS_PASSWORD_8:
        break;
    case BUENAS_PASSWORD_9:
        break;
    case BUENAS_PASSWORD_10:
        break;
    case BUENAS_PASSWORD_11:
        break;
    case BUENAS_PASSWORD_12:
        break;
    case BUENAS_PASSWORD_13:
        break;
    case BUENAS_PASSWORD_14:
        break;
    case BUENAS_PASSWORD_15:
        break;
    case BUENAS_PASSWORD_16:
        break;
    case BUENAS_PASSWORD_17:
        break;
    case BUENAS_PASSWORD_18:
        break;
    case BUENAS_PASSWORD_19:
        break;
    case BUENAS_PASSWORD_20:
        PlayNewMapMusic(MUS_DUMMY);
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
                    ScrollWindow(windowId, 0, tScrollDistance, 0x11);
                    tScrollDistance = 0;
                    tCurrentLine = tNextLine;
                }
                else
                {
                    ScrollWindow(windowId, 0, RADIO_SCROLL_SPEED, 0x11);
                    tScrollDistance -= RADIO_SCROLL_SPEED;
                }
                CopyWindowToVram(windowId, 2);
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
    case POKEDEX_SHOW_6:
        break;
    case POKEDEX_SHOW_7:
        break;
    case POKEDEX_SHOW_8:
        break;
    default:
        FillWindowPixelBuffer(windowId, 0x11);
        CopyWindowToVram(windowId, 2);
        PlayNewMapMusic(MUS_DUMMY);
        break;
    }
}

const u8 *LoadStation_PokemonChannel(u8 taskId, u8 windowId)
{
    const u8 *title = NULL;

    RtcCalcLocalTime();

    if (GetTimeOfDay() == TIME_MORNING)
    {
        gTasks[taskId].tCurrentLine = POKEDEX_SHOW;
        gTasks[taskId].tNumLinesPrinted = 0;
        PlayRadioShow(taskId, windowId);
        title = gText_PokedexShow;
    }
    else
    {
        gTasks[taskId].tCurrentLine = OAKS_POKEMON_TALK;
        gTasks[taskId].tNumLinesPrinted = 0;
        PlayRadioShow(taskId, windowId);
        title = gText_OaksPkmnTalk;
    }

    return title;
}

const u8 *LoadStation_PokemonMusic(u8 taskId, u8 windowId)
{
    gTasks[taskId].tCurrentLine = POKEMON_MUSIC;
    gTasks[taskId].tNumLinesPrinted = 0;
    PlayRadioShow(taskId, windowId);
    return gText_PokemonMusic;
}

const u8 *LoadStation_LuckyChannel(u8 taskId, u8 windowId)
{
    gTasks[taskId].tCurrentLine = LUCKY_CHANNEL;
    gTasks[taskId].tNumLinesPrinted = 0;
    PlayRadioShow(taskId, windowId);
    return gText_LuckyChannel;
}

const u8 *LoadStation_BuenasPassword(u8 taskId, u8 windowId)
{
    const u8 *title = NULL;

    gTasks[taskId].tCurrentLine = BUENAS_PASSWORD;
    gTasks[taskId].tNumLinesPrinted = 0;
    PlayRadioShow(taskId, windowId);

    if (FlagGet(FLAG_ROCKET_TAKEOVER))  // always show title when Rockets in tower
        title = gText_BuenasPassword;

    return title;
}

const u8 *LoadStation_UnownRadio(u8 taskId, u8 windowId)
{
    const u8 *title = NULL;

    if (gMapHeader.regionMapSectionId == MAPSEC_RUINS_OF_ALPH)
    {
        gTasks[taskId].tCurrentLine = UNOWN_RADIO;
        gTasks[taskId].tNumLinesPrinted = 0;
        PlayRadioShow(taskId, windowId);
        title = gText_FiveMarks;
    }

    return title;
}

const u8 *LoadStation_EvolutionRadio(u8 taskId, u8 windowId)
{
    const u8 *title = NULL;

    if (gMapHeader.regionMapSectionId == MAPSEC_MAHOGANY_TOWN ||
        gMapHeader.regionMapSectionId == MAPSEC_ROUTE_43 ||
        gMapHeader.regionMapSectionId == MAPSEC_LAKE_OF_RAGE)
    {
        gTasks[taskId].tCurrentLine = EVOLUTION_RADIO;
        gTasks[taskId].tNumLinesPrinted = 0;
        PlayRadioShow(taskId, windowId);
        title = gText_FiveMarks;
    }

    return title;
}
