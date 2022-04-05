#include "global.h"
#include "main.h"
#include "malloc.h"
#include "battle_main.h"
#include "buenas_password.h"
#include "clock.h"
#include "data.h"
#include "day_night.h"
#include "event_data.h"
#include "international_string_util.h"
#include "item.h"
#include "lottery_corner.h"
#include "overworld.h"
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
#include "constants/radio.h"
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
#define tPokedexSeenMonsCount data[13]
#define tPokedexSeenMonsPtr data[14]

static const u16 sRadioChannelSongs[] = 
{
    [OAKS_POKEMON_TALK] = MUS_OAKS_LAB,
    [POKEDEX_SHOW] = MUS_POKE_CENTER,
    [POKEMON_MUSIC] = MUS_DUMMY,
    [LUCKY_CHANNEL] = MUS_GAME_CORNER,
    [BUENAS_PASSWORD] = MUS_BUENAS_THEME,
    [PLACES_AND_PEOPLE] = MUS_PEWTER,
    [LETS_ALL_SING] = MUS_POKEMON_MARCH,
    [ROCKET_RADIO] = MUS_ROCKET_TAKEOVER,
    [POKE_FLUTE_RADIO] = MUS_POKE_FLUTE_RADIO,
    [UNOWN_RADIO] = MUS_UNOWN_RADIO,
    [EVOLUTION_RADIO] = MUS_EVOLUTION_RADIO
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

u8 LoadStation_PokemonChannel(void);
u8 LoadStation_PokemonMusic(void);
u8 LoadStation_LuckyChannel(void);
u8 LoadStation_BuenasPassword(void);
u8 LoadStation_UnownRadio(void);
u8 LoadStation_EvolutionRadio(void);
u8 LoadStation_PlacesAndPeople(void);
u8 LoadStation_LetsAllSing(void);
u8 LoadStation_PokeFluteRadio(void);

const struct RadioStation gRadioStationData[] = {
    { RADIO_FREQ(4.5),  REGION_JOHTO, LoadStation_PokemonChannel },
    { RADIO_FREQ(7.5),  REGION_JOHTO, LoadStation_PokemonMusic },
    { RADIO_FREQ(8.5),  REGION_JOHTO, LoadStation_LuckyChannel },
    { RADIO_FREQ(10.5), REGION_JOHTO, LoadStation_BuenasPassword },
    { RADIO_FREQ(13.5), REGION_JOHTO, LoadStation_UnownRadio },
    { RADIO_FREQ(20.5), REGION_JOHTO, LoadStation_EvolutionRadio },
    { RADIO_FREQ(16.5), REGION_KANTO, LoadStation_PlacesAndPeople },
    { RADIO_FREQ(18.5), REGION_KANTO, LoadStation_LetsAllSing },
    { RADIO_FREQ(20.0), REGION_KANTO, LoadStation_PokeFluteRadio },
    { 0xFF, 0xFF, NULL }
};

static void PlayAndSaveMusic(u16 song)
{
    Overworld_SetSavedMusic(song);
    PlayNewMapMusic(song);
}

static void PlayStationMusic(u8 taskId)
{
    if (gTasks[taskId].tNumLinesPrinted == 0)
    {
        PlayAndSaveMusic(sRadioChannelSongs[gTasks[taskId].tCurrentLine]);
    }
}

static bool8 BuenasPassword_CheckTime(void)
{
    RtcCalcLocalTime();
    if (gLocalTime.hours >= BUENAS_PASSWORD_START_HOUR)
        return TRUE;
    return FALSE;
}

static void NextRadioLine(u8 taskId, u8 nextLine, const u8 *lineToPrint, bool8 shouldScroll)
{
    s16 *data = gTasks[taskId].data;
    u8 yPos = 1;
    u8 lineHeight = GetFontAttribute(1, FONTATTR_MAX_LETTER_HEIGHT) + 1;
    
    if (tNumLinesPrinted != 0)
        yPos += lineHeight;

    if (lineToPrint)
        AddTextPrinterParameterized(tWindowId, 2, lineToPrint, 0, yPos, 0, NULL);

    tNumLinesPrinted += lineToPrint ? 1 : 0;
    tNextLine = nextLine;
    tCurrentLine = RADIO_SCROLL;
    tTextDelay = 90;
    tScrollDistance = shouldScroll ? lineHeight : 0;
}

void PlayPokemonMusic(void)
{
    u16 song = MUS_POKEMON_MARCH;  // Sunday, Tuesday, Thursday, Saturday
    RtcCalcLocalTime();
    if (gLocalTime.dayOfWeek & 1)   // Monday, Wednesday, Friday
        song = MUS_POKEMON_LULLABY;
    PlayAndSaveMusic(song);
}

void Task_PlayRadioShow(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (tCurrentLine < UNOWN_RADIO && GetCurrentRegion() == REGION_JOHTO && FlagGet(FLAG_ROCKETS_IN_RADIO_TOWER))
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
            u16 species = SPECIES_NONE, i = 0;
            u16 **caughtMons = (u16 **)&tPokedexSeenMonsPtr;
            tShowNameId = tCurrentLine;
            PlayStationMusic(taskId);
            tMiscValue = SPECIES_NONE;
            
            if (*caughtMons == NULL)
            {
                *caughtMons = AllocZeroed(sizeof(u16) * JOHTO_DEX_COUNT);
                if (*caughtMons)
                {
                    for (species = NATIONAL_DEX_BULBASAUR, i = 0; species <= JOHTO_DEX_COUNT; species++)
                    {
                        if (GetSetPokedexFlag(species, FLAG_GET_CAUGHT))
                        {
                            (*caughtMons)[i] = species;
                            i++;
                        }
                    }
                    tPokedexSeenMonsCount = i;
                }
            }

            if (*caughtMons && tPokedexSeenMonsCount > 0)
                tMiscValue = (*caughtMons)[Random() % tPokedexSeenMonsCount];

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
                PlayAndSaveMusic(MUS_DUMMY);
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
        NextRadioLine(taskId, tCurrentLine + 1, gText_OaksPkmnTalkIntro2, TRUE);
        break;
    case OAKS_POKEMON_TALK_3:
        NextRadioLine(taskId, tCurrentLine + 1, gText_OaksPkmnTalkIntro3, TRUE);
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
                { MAPSEC_ROUTE_32, MAP_GROUP(ROUTE32), MAP_NUM(ROUTE32) },
                { MAPSEC_ROUTE_34, MAP_GROUP(ROUTE34), MAP_NUM(ROUTE34) },
                { MAPSEC_ROUTE_35, MAP_GROUP(ROUTE35), MAP_NUM(ROUTE35) },
                { MAPSEC_ROUTE_36, MAP_GROUP(ROUTE36), MAP_NUM(ROUTE36) },
                { MAPSEC_ROUTE_37, MAP_GROUP(ROUTE37), MAP_NUM(ROUTE37) },
                { MAPSEC_ROUTE_38, MAP_GROUP(ROUTE38), MAP_NUM(ROUTE38) },
                { MAPSEC_ROUTE_39, MAP_GROUP(ROUTE39), MAP_NUM(ROUTE39) },
                { MAPSEC_ROUTE_42, MAP_GROUP(ROUTE42), MAP_NUM(ROUTE42) },
                { MAPSEC_ROUTE_43, MAP_GROUP(ROUTE43), MAP_NUM(ROUTE43) },
                { MAPSEC_ROUTE_44, MAP_GROUP(ROUTE44), MAP_NUM(ROUTE44) },
                { MAPSEC_ROUTE_45, MAP_GROUP(ROUTE45), MAP_NUM(ROUTE45) },
                { MAPSEC_ROUTE_46, MAP_GROUP(ROUTE46), MAP_NUM(ROUTE46) },
            };

            u8 map = Random() % ARRAY_COUNT(oaksTalkRoutes);
            u8 timeOfDay = Random() % TIMES_OF_DAY_COUNT;
            u8 monNum = Random() % 6; // choose from middle 6
            u16 species = GetMapWildMonFromIndex(oaksTalkRoutes[map].group, oaksTalkRoutes[map].num, monNum + 4);
            
            StringCopy(gStringVar1, gSpeciesNames[species]);
            StringCopy(gStringVar2, gRegionMapEntries[oaksTalkRoutes[map].mapSec].name);
            StringExpandPlaceholders(gStringVar4, gText_OaksPkmnTalk1);

            NextRadioLine(taskId, tCurrentLine + 1, gStringVar4, TRUE);
        }
        break;
    case OAKS_POKEMON_TALK_5:
        NextRadioLine(taskId, tCurrentLine + 1, gText_OaksPkmnTalk2, TRUE);
        break;
    case OAKS_POKEMON_TALK_6:
        StringExpandPlaceholders(gStringVar4, gText_OaksPkmnTalk3);
        NextRadioLine(taskId, tCurrentLine + 1, gStringVar4, TRUE);
        break;
    case OAKS_POKEMON_TALK_7:
        StringExpandPlaceholders(gStringVar4, gText_OaksPkmnTalk4);
        NextRadioLine(taskId, tCurrentLine + 1, gStringVar4, TRUE);
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
            NextRadioLine(taskId, tCurrentLine + 1, adverbs[Random() % ARRAY_COUNT(adverbs)], TRUE);
        }
        break;
    case OAKS_POKEMON_TALK_9:
        {
            static const u8 *const adjectives[] = {
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
                NextRadioLine(taskId, OAKS_POKEMON_TALK_4, adjectives[Random() % ARRAY_COUNT(adjectives)], TRUE);
            }
            else
            {
                tMiscValue = 5;
                NextRadioLine(taskId, PKMN_CHANNEL_INTERLUDE_1, adjectives[Random() % ARRAY_COUNT(adjectives)], TRUE);
                tCurrentLine = PKMN_CHANNEL_INTERLUDE_1;
                tNextLine = NO_RADIO_SHOW;
                tTextDelay = 100;
            }
        }
        break;
    case POKEDEX_SHOW_2:
        CopyMonCategoryText(tMiscValue, gStringVar4);
        NextRadioLine(taskId, tCurrentLine + 1, gStringVar4, TRUE);
        break;
    case POKEDEX_SHOW_3:
        StringCopy(gStringVar4, gPokedexEntries[tMiscValue].pokedexShowEntry);
        tMiscValue = 0;
    case POKEDEX_SHOW_4:
        {
            u8 index;
            for (index = tMiscValue; index < 1000; index++) // prevent possible gStringVar4 overflow
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
    case POKEMON_MUSIC_2:
        NextRadioLine(taskId, tCurrentLine + 1, gText_PkmnMusicBen2, TRUE);
        break;
    case POKEMON_MUSIC_3:
        NextRadioLine(taskId, tCurrentLine + 1, gText_PkmnMusicBen3, TRUE);
        break;
    case POKEMON_MUSIC_4:
        StringCopy(gStringVar1, GetDayOfWeekString(gLocalTime.dayOfWeek));
        StringExpandPlaceholders(gStringVar4, gText_PkmnMusicBenFern1);
        NextRadioLine(taskId, tCurrentLine + 1, gStringVar4, TRUE);
        break;
    case POKEMON_MUSIC_5:
        {
            const u8 *string = gText_PkmnMusicBenFern2A;    // Sunday, Tuesday, Thursday, Saturday
            if (gLocalTime.dayOfWeek & 1)   // Monday, Wednesday, Friday
            {
                string = gText_PkmnMusicBenFern2B;
            }
            NextRadioLine(taskId, tCurrentLine + 1, string, TRUE);
        }
        break;
    case POKEMON_MUSIC_6:
        {
            const u8 *string = gText_PkmnMusicBenFern3A;    // Sunday, Tuesday, Thursday, Saturday
            if (gLocalTime.dayOfWeek & 1)   // Monday, Wednesday, Friday
            {
                string = gText_PkmnMusicBenFern3B;
            }
            NextRadioLine(taskId, tCurrentLine + 1, string, TRUE);
        }
        break;
    case POKEMON_MUSIC_7:
        break;
    case LETS_ALL_SING_2:
        NextRadioLine(taskId, POKEMON_MUSIC_4, gText_PkmnMusicFern2, TRUE);
        break;
    case LUCKY_NUMBER_SHOW_2:
        NextRadioLine(taskId, tCurrentLine + 1, gText_LuckyChannel2, TRUE);
        break;
    case LUCKY_NUMBER_SHOW_3:
        NextRadioLine(taskId, tCurrentLine + 1, gText_LuckyChannel3, TRUE);
        break;
    case LUCKY_NUMBER_SHOW_4:
        NextRadioLine(taskId, tCurrentLine + 1, gText_LuckyChannel4, TRUE);
        break;
    case LUCKY_NUMBER_SHOW_5:
        NextRadioLine(taskId, tCurrentLine + 1, gText_LuckyChannel5, TRUE);
        break;
    case LUCKY_NUMBER_SHOW_6:
        NextRadioLine(taskId, tCurrentLine + 1, gText_LuckyChannel6, TRUE);
        break;
    case LUCKY_NUMBER_SHOW_7:
    case LUCKY_NUMBER_SHOW_10:
        NextRadioLine(taskId, tCurrentLine + 1, gText_LuckyChannel7, TRUE);
        break;
    case LUCKY_NUMBER_SHOW_8:
    case LUCKY_NUMBER_SHOW_11:
        StringExpandPlaceholders(gStringVar4, gText_LuckyChannel8);
        NextRadioLine(taskId, tCurrentLine + 1, gStringVar4, TRUE);
        break;
    case LUCKY_NUMBER_SHOW_9:
        NextRadioLine(taskId, tCurrentLine + 1, gText_LuckyChannel9, TRUE);
        break;
    case LUCKY_NUMBER_SHOW_12:
        NextRadioLine(taskId, tCurrentLine + 1, gText_LuckyChannel10, TRUE);
        break;
    case LUCKY_NUMBER_SHOW_13:
        {
            u8 nextLine = LUCKY_CHANNEL;
            if (Random() % 16 == 0)
            {
                nextLine = tCurrentLine + 1;
            }
            NextRadioLine(taskId, nextLine, gText_LuckyChannel11, TRUE);
        }
        break;
    case LUCKY_NUMBER_SHOW_14:
        NextRadioLine(taskId, tCurrentLine + 1, gText_LuckyChannel12, TRUE);
        break;
    case LUCKY_NUMBER_SHOW_15:
        NextRadioLine(taskId, LUCKY_CHANNEL, gText_LuckyChannel13, TRUE);
        break;
    case PLACES_AND_PEOPLE_2:
        NextRadioLine(taskId, tCurrentLine + 1, gText_PlacesAndPeople2, TRUE);
        break;
    case PLACES_AND_PEOPLE_3:
        NextRadioLine(taskId, tCurrentLine + 1, gText_PlacesAndPeople3, TRUE);
        break;
    case PLACES_AND_PEOPLE_4:
        {
            if(Random() % 100 < 50) //place
            {
                static const u16 validMapSecs[] = 
                {
                    MAPSEC_PALLET_TOWN,
                    MAPSEC_ROUTE_22,
                    MAPSEC_PEWTER_CITY,
                    MAPSEC_CERULEAN_CITY,
                    MAPSEC_ROUTE_12,
                    MAPSEC_ROUTE_11,
                    MAPSEC_ROUTE_16,
                    MAPSEC_ROUTE_14,
                    MAPSEC_CINNABAR_ISLAND,
                };
                GetMapName(gStringVar2, validMapSecs[Random() % ARRAY_COUNT(validMapSecs)], 0);
                StringExpandPlaceholders(gStringVar4, gText_PlacesAndPeople4Place);
            }
            else //person
            {
                static const u16 validTrainers[] = 
                {
                    TRAINER_FALKNER,
                    TRAINER_WHITNEY,
                    TRAINER_BUGSY,
                    TRAINER_MORTY,
                    TRAINER_PRYCE,
                    TRAINER_JASMINE,
                    TRAINER_CHUCK,
                    TRAINER_CLAIR,
                    TRAINER_ROSS,
                    TRAINER_JOEY_1,
                    TRAINER_JACK_1,
                    TRAINER_ROD,
                    TRAINER_CARRIE,
                    TRAINER_NICK,
                    TRAINER_GWEN,
                    TRAINER_VICTORIA,
                    TRAINER_LARRY,
                    TRAINER_ROCKET_SLOWPOKE_WELL_1, // GruntM
                    TRAINER_PRESTON,
                    TRAINER_ROXANNE,
                    TRAINER_COLETTE,
                    TRAINER_DON,
                    TRAINER_JUSTIN,
                    TRAINER_HAROLD,
                    TRAINER_ELAINE,
                    TRAINER_EUGENE,
                    TRAINER_ERIC, // is unused Super Nerd Stan in Crystal
                    TRAINER_CLYDE,
                    TRAINER_ANTHONY_1,
                    TRAINER_DWAYNE, // is unused Biker Benny in Crystal
                    TRAINER_DUNCAN,
                    TRAINER_OTIS,
                    TRAINER_IRWIN,
                    TRAINER_YOSHI, // is unused Black Belt Kenji in Crystal
                    TRAINER_MAHOGANY_EXECUTIVE_M,
                    TRAINER_NATHAN,
                    TRAINER_LIZ_1,
                    TRAINER_ROLAND,
                    TRAINER_CHOW,
                    TRAINER_MARTHA,
                    TRAINER_RONALD,
                    TRAINER_WILLIAM,
                    TRAINER_NAOKO,
                    TRAINER_AMY_AND_MAY,
                    TRAINER_BEVERLY,
                    TRAINER_KEITH,
                    TRAINER_ROCKET_SLOWPOKE_WELL_2, // GruntF
                    // Below here are hidden if not Champion
                    TRAINER_WILL,
                    TRAINER_BRUNO,
                    TRAINER_KAREN,
                    TRAINER_KOGA,
                    TRAINER_LANCE, // 52
                    // Below here are hidden until have 8 Kanto Badges
                    TRAINER_BROCK,
                    TRAINER_MISTY,
                    TRAINER_LT_SURGE,
                    TRAINER_ERIKA,
                    TRAINER_JANINE,
                    TRAINER_SABRINA,
                    TRAINER_BLAINE,
                    TRAINER_BLUE, // 60
                };
                u32 numTrainers;
                if(!FlagGet(FLAG_SYS_GAME_CLEAR))
                    numTrainers = 47;
                else
                {
                    CountBadges();
                    if(gSpecialVar_Result == 16)
                        numTrainers = 60;
                    else
                        numTrainers = 52;
                }
                u32 rand = Random() % numTrainers;
                StringCopy(gStringVar1, GetTrainerClassNameFromId(validTrainers[rand]));
                StringCopy(gStringVar2, gTrainers[validTrainers[rand]].trainerName);
                StringExpandPlaceholders(gStringVar4, gText_PlacesAndPeople4Person);
            }
            NextRadioLine(taskId, tCurrentLine + 1, gStringVar4, TRUE);
        }
        break;
    case PLACES_AND_PEOPLE_5:
        {
            static const u8 *const descriptions[] = {
                gText_PNPDescriptionCute,
                gText_PNPDescriptionLazy,
                gText_PNPDescriptionHappy,
                gText_PNPDescriptionNoisy,
                gText_PNPDescriptionPrecocious,
                gText_PNPDescriptionBold,
                gText_PNPDescriptionPicky,
                gText_PNPDescriptionSortOfOK,
                gText_PNPDescriptionSoSo,
                gText_PNPDescriptionGreat,
                gText_PNPDescriptionMyType,
                gText_PNPDescriptionCool,
                gText_PNPDescriptionInspiring,
                gText_PNPDescriptionWeird,
                gText_PNPDescriptionRightForMe,
                gText_PNPDescriptionOdd
            };
            if (Random() % 100 >= 4) // 4% chance of redoing the radio intro
            {
                NextRadioLine(taskId, PLACES_AND_PEOPLE_4, descriptions[Random() % ARRAY_COUNT(descriptions)], TRUE);
            }
            else
            {
                NextRadioLine(taskId, PLACES_AND_PEOPLE, descriptions[Random() % ARRAY_COUNT(descriptions)], TRUE);
            }
        }
        break;
    case ROCKET_RADIO_2:
        NextRadioLine(taskId, tCurrentLine + 1, gText_RocketRadio2, TRUE);
        break;
    case ROCKET_RADIO_3:
        NextRadioLine(taskId, tCurrentLine + 1, gText_RocketRadio3, TRUE);
        break;
    case ROCKET_RADIO_4:
        NextRadioLine(taskId, tCurrentLine + 1, gText_RocketRadio4, TRUE);
        break;
    case ROCKET_RADIO_5:
        NextRadioLine(taskId, tCurrentLine + 1, gText_RocketRadio5, TRUE);
        break;
    case ROCKET_RADIO_6:
        NextRadioLine(taskId, tCurrentLine + 1, gText_RocketRadio6, TRUE);
        break;
    case ROCKET_RADIO_7:
        NextRadioLine(taskId, tCurrentLine + 1, gText_RocketRadio7, TRUE);
        break;
    case ROCKET_RADIO_8:
        NextRadioLine(taskId, tCurrentLine + 1, gText_RocketRadio8, TRUE);
        break;
    case ROCKET_RADIO_9:
        NextRadioLine(taskId, tCurrentLine + 1, gText_RocketRadio9, TRUE);
        break;
    case ROCKET_RADIO_10:
        NextRadioLine(taskId, ROCKET_RADIO, gText_RocketRadio10, TRUE);
        break;
    case PKMN_CHANNEL_INTERLUDE_1:
        if (tTextDelay == 0)
        {
            tCurrentLine = tCurrentLine + 1;
        }
        else
        {
            tTextDelay--;
        }
        break;
    case PKMN_CHANNEL_INTERLUDE_2:
        FillWindowPixelBuffer(tWindowId, 0x11);
        AddTextPrinterParameterized5(tWindowId, 2, gText_PokemonChannel1, 0, 1, 0, NULL, 1, 1);
        PlayFanfare(MUS_PKMNCHANNEL_INTERLUDE);
        tCurrentLine = tCurrentLine + 1;
        break;
    case PKMN_CHANNEL_INTERLUDE_3:
        if (IsFanfareTaskInactive())
        {
            FillWindowPixelBuffer(tWindowId, 0x11);
            tCurrentLine = OAKS_POKEMON_TALK_4;
            tNumLinesPrinted = 0;
            PlayNewMapMusic(sRadioChannelSongs[OAKS_POKEMON_TALK]);
        }
        break;
    case BUENAS_PASSWORD_2:
        NextRadioLine(taskId, tCurrentLine + 1, gText_BuenasPassword2, TRUE);
        break;
    case BUENAS_PASSWORD_3:
        {
            u8 nextLine = tCurrentLine + 1;
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

                if (!FlagGet(FLAG_BUENAS_PASSWORD_SET))
                {
                    password = GenerateRandomBuenasPassword();
                    VarSet(VAR_BUENAS_PASSWORD, password);
                    FlagSet(FLAG_BUENAS_PASSWORD_SET);
                }
                else
                {
                    password = VarGet(VAR_BUENAS_PASSWORD);
                }

                StringCopy(gStringVar1, GetBuenasPassword(password >> 8, password & 0xFF));
                StringExpandPlaceholders(gStringVar4, gText_BuenasPassword4);
                NextRadioLine(taskId, tCurrentLine + 1, gStringVar4, TRUE);
            }
        }
        break;
    case BUENAS_PASSWORD_5:
        NextRadioLine(taskId, tCurrentLine + 1, gText_BuenasPassword5, TRUE);
        break;
    case BUENAS_PASSWORD_6:
        NextRadioLine(taskId, tCurrentLine + 1, gText_BuenasPassword6, TRUE);
        break;
    case BUENAS_PASSWORD_7:
        {
            u8 nextLine = BUENAS_PASSWORD;
            if (!BuenasPassword_CheckTime())
                nextLine = tCurrentLine + 1;
            NextRadioLine(taskId, nextLine, gText_BuenasPassword7, TRUE);
        }
        break;
    case BUENAS_PASSWORD_8:
        NextRadioLine(taskId, tCurrentLine + 1, gText_BuenasPassword17, TRUE);
        break;
    case BUENAS_PASSWORD_9:
        NextRadioLine(taskId, tCurrentLine + 1, gText_BuenasPassword8, TRUE);
        break;
    case BUENAS_PASSWORD_10:
        NextRadioLine(taskId, tCurrentLine + 1, gText_BuenasPassword9, TRUE);
        break;
    case BUENAS_PASSWORD_11:
        NextRadioLine(taskId, tCurrentLine + 1, gText_BuenasPassword10, TRUE);
        break;
    case BUENAS_PASSWORD_12:
        NextRadioLine(taskId, tCurrentLine + 1, gText_BuenasPassword11, TRUE);
        break;
    case BUENAS_PASSWORD_13:
        NextRadioLine(taskId, tCurrentLine + 1, gText_BuenasPassword12, TRUE);
        break;
    case BUENAS_PASSWORD_14:
        NextRadioLine(taskId, tCurrentLine + 1, gText_BuenasPassword13, TRUE);
        break;
    case BUENAS_PASSWORD_15:
        NextRadioLine(taskId, tCurrentLine + 1, gText_BuenasPassword14, TRUE);
        break;
    case BUENAS_PASSWORD_16:
        NextRadioLine(taskId, tCurrentLine + 1, gText_BuenasPassword15, TRUE);
        break;
    case BUENAS_PASSWORD_17:
        NextRadioLine(taskId, tCurrentLine + 1, gText_BuenasPassword16, FALSE);
        break;
    case BUENAS_PASSWORD_18:
        FillWindowPixelBuffer(tWindowId, 0x11);
        tNumLinesPrinted = 0;
        NextRadioLine(taskId, tCurrentLine + 1, gText_BuenasPassword17, FALSE);
        break;
    case BUENAS_PASSWORD_19:
        NextRadioLine(taskId, tCurrentLine + 1, NULL, FALSE);
        break;
    case BUENAS_PASSWORD_20:
        tShowNameId = NO_RADIO_SHOW;
        FlagClear(FLAG_BUENAS_PASSWORD_SET);
        FadeOutAndPlayNewMapMusic(MUS_DUMMY, 4);
        Overworld_SetSavedMusic(MUS_DUMMY);
        tCurrentLine = tCurrentLine + 1;
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
                #define RADIO_SCROLL_SPEED 1
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
        PlayAndSaveMusic(MUS_DUMMY);
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

u8 LoadStation_PlacesAndPeople(void)
{
    if(FlagGet(FLAG_SYS_HAS_EXPN_CARD))
        return PLACES_AND_PEOPLE;
    return 0xFF;
}

u8 LoadStation_LetsAllSing(void)
{
    if(FlagGet(FLAG_SYS_HAS_EXPN_CARD))
        return LETS_ALL_SING;
    return 0xFF;
}

u8 LoadStation_PokeFluteRadio(void)
{
    if(FlagGet(FLAG_SYS_HAS_EXPN_CARD))
        return POKE_FLUTE_RADIO;
    return 0xFF;
}

u8 LoadStation_UnownRadio(void)
{
    if (gMapHeader.regionMapSectionId == MAPSEC_RUINS_OF_ALPH)
        return UNOWN_RADIO;

    return 0xFF;
}

u8 LoadStation_EvolutionRadio(void)
{
    if ((gMapHeader.regionMapSectionId == MAPSEC_MAHOGANY_TOWN ||
        gMapHeader.regionMapSectionId == MAPSEC_ROUTE_43 ||
        gMapHeader.regionMapSectionId == MAPSEC_LAKE_OF_RAGE) &&
        !FlagGet(FLAG_CLEARED_ROCKET_HIDEOUT))
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
        AddTextPrinterParameterized(0, 2, gStringVar4, 0, 1, 0, NULL);
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
    if (JOY_NEW(A_BUTTON | B_BUTTON))
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

    LoadMessageBoxAndBorderGfx();
    DrawDialogueFrame(0, 1);
    CreateTask(Task_FieldRadio_1, 3);
    return TRUE;
}

#undef tRadioShowTaskId
