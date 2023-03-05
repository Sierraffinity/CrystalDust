#include "global.h"
#include "scanline_effect.h"
#include "palette.h"
#include "task.h"
#include "main.h"
#include "window.h"
#include "malloc.h"
#include "link.h"
#include "bg.h"
#include "sound.h"
#include "frontier_pass.h"
#include "overworld.h"
#include "mail.h"
#include "menu.h"
#include "text.h"
#include "event_data.h"
#include "easy_chat.h"
#include "money.h"
#include "strings.h"
#include "string_util.h"
#include "trainer_card.h"
#include "gpu_regs.h"
#include "international_string_util.h"
#include "pokedex.h"
#include "pokemon_icon.h"
#include "graphics.h"
#include "pokemon_icon.h"
#include "trainer_pokemon_sprites.h"
#include "contest_util.h"
#include "constants/songs.h"
#include "constants/game_stat.h"
#include "constants/battle_frontier.h"
#include "constants/rgb.h"
#include "constants/trainers.h"

struct TrainerCardData
{
    u8 mainState;
    u8 printState;
    u8 gfxLoadState;
    u8 bgPalLoadState;
    u8 flipDrawState;
    bool8 isLink;
    u8 timeColonBlinkTimer;
    bool8 timeColonInvisible;
    bool8 onBack;
    bool8 allowDMACopy;
    bool8 hasPokedex;
    bool8 hasHofResult;
    bool8 hasLinkResults;
    bool8 hasBattleTowerWins;
    bool8 unused_E;
    bool8 unused_F;
    bool8 hasTrades;
    u8 badgeCount[NUM_BADGES];
    u8 easyChatProfile[TRAINER_CARD_PROFILE_LENGTH][13];
    u8 textPlayersCard[70];
    u8 textHofTime[70];
    u8 textLinkBattleType[140];
    u8 textLinkBattleWins[70];
    u8 textLinkBattleLosses[140];
    u8 textNumTrades[140];
    u8 textBerryCrushPts[140];
    u8 textUnionRoomStats[70];
    u8 textNumLinkPokeblocks[70];
    u8 textNumLinkContests[70];
    u8 textBattleTowerWins[70];
    u8 textBattleTowerStreak[70];
    u8 textBattlePoints[70];
    u16 monIconPal[16 * PARTY_SIZE];
    s8 flipBlendY;
    bool8 timeColonNeedDraw;
    u8 cardType;
    u8 region;
    u16 blendColor;
    void (*callback2)(void);
    struct TrainerCard trainerCard;
    u16 frontTilemap[600];
    u16 backTilemap[600];
    u16 bgTilemap[600];
    u8 badgeTiles[0x80 * NUM_BADGES];
    u8 stickerTiles[0x200];
    u8 cardTiles[0x2300];
    u16 cardTilemapBuffer[0x1000];
    u16 bgTilemapBuffer[0x1000];
    u16 cardTop;
    u8 language;
    u8 stats[STAT_COUNT];
};

// EWRAM
EWRAM_DATA struct TrainerCard gTrainerCards[4] = {0};
EWRAM_DATA static struct TrainerCardData *sData = NULL;

//this file's functions
static void VblankCb_TrainerCard(void);
static void HblankCb_TrainerCard(void);
static void BlinkTimeColon(void);
static void CB2_TrainerCard(void);
static void CloseTrainerCard(u8 task);
static bool8 PrintAllOnCardFront(void);
static void DrawTrainerCardWindow(u8);
static void CreateTrainerCardTrainerPic(void);
static void DrawCardScreenBackground(u16*);
static void DrawCardFrontOrBack(u16*);
static void DrawStarsAndBadgesOnCard(void);
static void PrintTimeOnCard(void);
static void FlipTrainerCard(void);
static bool8 IsCardFlipTaskActive(void);
static bool8 LoadCardGfx(void);
static void CB2_InitTrainerCard(void);
static u32 GetCappedGameStat(u8 statId, u32 maxValue);
static bool8 HasAllFrontierSymbols(void);
static u8 GetRubyTrainerStars(struct TrainerCard*);
static u16 GetCaughtMonsCount(void);
static void SetPlayerCardData(struct TrainerCard*, u8);
static void TrainerCard_GenerateCardToShowLocally(struct TrainerCard*);
static u8 VersionToCardType(u8);
static void SetDataFromTrainerCard(void);
static void InitGpuRegs(void);
static void ResetGpuRegs(void);
static void InitBgsAndWindows(void);
static void SetTrainerCardCb2(void);
static void SetUpTrainerCardTask(void);
static void InitTrainerCardData(void);
static u8 GetSetCardType(void);
static void PrintNameOnCardFront(void);
static void PrintIdOnCard(void);
static void PrintMoneyOnCard(void);
static void PrintPokedexOnCard(void);
static void PrintProfilePhraseOnCard(void);
static bool8 PrintAllOnCardBack(void);
static void PrintNameOnCardBack(void);
static void PrintHofDebutTimeOnCard(u8 slot);
static void PrintLinkBattleResultsOnCard(u8 slot);
static void PrintTradesStringOnCard(u8 slot);
static void PrintBerryCrushStringOnCard(u8 slot);
static void PrintPokeblockStringOnCard(u8 slot);
static void PrintUnionStringOnCard(u8 slot);
static void PrintContestStringOnCard(u8 slot);
static void PrintPokemonIconsOnCard(void);
static void PrintBattlePointsStringOnCard(u8 slot);
static void PrintBattleTowerStringOnCard(u8 slot);
static void PrintStickersOnCard(void);
static void BufferTextsVarsForCardPage2(void);
static void BufferNameForCardBack(void);
static void BufferHofDebutTime(void);
static void BufferLinkBattleResults(void);
static void BufferNumTrades(void);
static void BufferBerryCrushPoints(void);
static void BufferUnionRoomStats(void);
static void BufferLinkPokeblocksNum(void);
static void BufferLinkContestNum(void);
static void BufferBattlePoints(void);
static void BufferBattleTowerWins(void);
static void PrintStatOnBackOfCard(u8 top, const u8* str1, u8* str2, const u8* color);
static void LoadStickerGfx(void);
static u8 SetCardBgsAndPals(void);
static void DrawCardBackStats(void);
static void Task_DoCardFlipTask(u8);
static bool8 Task_BeginCardFlip(struct Task* task);
static bool8 Task_AnimateCardFlipDown(struct Task* task);
static bool8 Task_DrawFlippedCardSide(struct Task* task);
static bool8 Task_SetCardFlipped(struct Task* task);
static bool8 Task_AnimateCardFlipUp(struct Task* task);
static bool8 Task_EndCardFlip(struct Task* task);
static void UpdateCardFlipRegs(u16);
static void LoadMonIconGfx(void);
static u8 GetSetCardStats(void);

static const u32 sTrainerCardStickers_Gfx[]      = INCBIN_U32("graphics/trainer_card/stickers_fr.4bpp.lz");
static const u16 sUnused_Pal[]                   = INCBIN_U16("graphics/trainer_card/unused.gbapal");
static const u16 sHoennTrainerCard1Star_Pal[]    = INCBIN_U16("graphics/trainer_card/one_star.gbapal");
static const u16 sKantoTrainerCard1Star_Pal[]    = INCBIN_U16("graphics/trainer_card/one_star_fr.gbapal");
static const u16 sJohtoTrainerCard1Star_Pal[]    = INCBIN_U16("graphics/trainer_card/one_star_cd.gbapal");
static const u16 sHoennTrainerCard2Star_Pal[]    = INCBIN_U16("graphics/trainer_card/two_stars.gbapal");
static const u16 sKantoTrainerCard2Star_Pal[]    = INCBIN_U16("graphics/trainer_card/two_stars_fr.gbapal");
static const u16 sJohtoTrainerCard2Star_Pal[]    = INCBIN_U16("graphics/trainer_card/two_stars_cd.gbapal");
static const u16 sHoennTrainerCard3Star_Pal[]    = INCBIN_U16("graphics/trainer_card/three_stars.gbapal");
static const u16 sKantoTrainerCard3Star_Pal[]    = INCBIN_U16("graphics/trainer_card/three_stars_fr.gbapal");
static const u16 sJohtoTrainerCard3Star_Pal[]    = INCBIN_U16("graphics/trainer_card/three_stars_cd.gbapal");
static const u16 sHoennTrainerCard4Star_Pal[]    = INCBIN_U16("graphics/trainer_card/four_stars.gbapal");
static const u16 sKantoTrainerCard4Star_Pal[]    = INCBIN_U16("graphics/trainer_card/four_stars_fr.gbapal");
static const u16 sJohtoTrainerCard4Star_Pal[]    = INCBIN_U16("graphics/trainer_card/four_stars_cd.gbapal");
static const u16 sHoennTrainerCardFemaleBg_Pal[] = INCBIN_U16("graphics/trainer_card/female_bg.gbapal");
static const u16 sKantoTrainerCardFemaleBg_Pal[] = INCBIN_U16("graphics/trainer_card/female_bg_fr.gbapal");
static const u16 sJohtoTrainerCardFemaleBg_Pal[] = INCBIN_U16("graphics/trainer_card/female_bg_cd.gbapal");
static const u16 sJohtoTrainerCardBadges_Pal[] = INCBIN_U16("graphics/trainer_card/badges_johto.gbapal");
static const u16 sHoennTrainerCardBadges_Pal[] = INCBIN_U16("graphics/trainer_card/badges_hoenn.gbapal");
static const u16 sKantoTrainerCardBadges_Pal[] = INCBIN_U16("graphics/trainer_card/badges_kanto.gbapal");
static const u16 sTrainerCardGold_Pal[] = INCBIN_U16("graphics/trainer_card/gold.gbapal");
static const u16 sTrainerCardSticker1_Pal[] = INCBIN_U16("graphics/trainer_card/stickers_fr1.gbapal");
static const u16 sTrainerCardSticker2_Pal[] = INCBIN_U16("graphics/trainer_card/stickers_fr2.gbapal");
static const u16 sTrainerCardSticker3_Pal[] = INCBIN_U16("graphics/trainer_card/stickers_fr3.gbapal");
static const u16 sTrainerCardSticker4_Pal[] = INCBIN_U16("graphics/trainer_card/stickers_fr4.gbapal");
static const u32 sJohtoTrainerCardBadges_Gfx[] = INCBIN_U32("graphics/trainer_card/badges_johto.4bpp.lz");
static const u32 sHoennTrainerCardBadges_Gfx[] = INCBIN_U32("graphics/trainer_card/badges_hoenn.4bpp.lz");
static const u32 sKantoTrainerCardBadges_Gfx[] = INCBIN_U32("graphics/trainer_card/badges_kanto.4bpp.lz");

static const struct BgTemplate sTrainerCardBgTemplates[4] =
{
    {
        .bg = 0,
        .charBaseIndex = 0,
        .mapBaseIndex = 27,
        .screenSize = 2,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0
    },
    {
        .bg = 1,
        .charBaseIndex = 2,
        .mapBaseIndex = 29,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    },
    {
        .bg = 2,
        .charBaseIndex = 0,
        .mapBaseIndex = 30,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 3,
        .baseTile = 0
    },
    {
        .bg = 3,
        .charBaseIndex = 0,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 192
    },
};

static const struct WindowTemplate sTrainerCardWindowTemplates[] =
{
    {
        .bg = 1,
        .tilemapLeft = 2,
        .tilemapTop = 15,
        .width = 27,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 0x253,
    },
    {
        .bg = 1,
        .tilemapLeft = 1,
        .tilemapTop = 1,
        .width = 28,
        .height = 18,
        .paletteNum = 15,
        .baseBlock = 0x1,
    },
    {
        .bg = 3,
        .tilemapLeft = 19,
        .tilemapTop = 5,
        .width = 9,
        .height = 10,
        .paletteNum = 8,
        .baseBlock = 0x150,
    },
    DUMMY_WIN_TEMPLATE
};

static const u16 *const sHoennTrainerCardStarPals[] =
{
    gHoennTrainerCard0Star_Pal,
    sHoennTrainerCard1Star_Pal,
    sHoennTrainerCard2Star_Pal,
    sHoennTrainerCard3Star_Pal,
    sHoennTrainerCard4Star_Pal,
};

static const u16 *const sKantoTrainerCardStarPals[] =
{
    gKantoTrainerCard0Star_Pal,
    sKantoTrainerCard1Star_Pal,
    sKantoTrainerCard2Star_Pal,
    sKantoTrainerCard3Star_Pal,
    sKantoTrainerCard4Star_Pal,
};

static const u16 *const sJohtoTrainerCardStarPals[] =
{
    gJohtoTrainerCard0Star_Pal,
    sJohtoTrainerCard1Star_Pal,
    sJohtoTrainerCard2Star_Pal,
    sJohtoTrainerCard3Star_Pal,
    sJohtoTrainerCard4Star_Pal,
};

static const u8 sTrainerCardTextColors[] = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_DARK_GRAY, TEXT_COLOR_LIGHT_GRAY};
static const u8 sTrainerCardStatColors[] = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_RED, TEXT_COLOR_LIGHT_RED};
static const u8 sTrainerCardRSTextColors[] = {TEXT_COLOR_TRANSPARENT, TEXT_DYNAMIC_COLOR_1, TEXT_DYNAMIC_COLOR_2};
static const u8 sTrainerCardRSStatColors[] = {TEXT_COLOR_TRANSPARENT, TEXT_DYNAMIC_COLOR_5, TEXT_DYNAMIC_COLOR_6};
static const u8 sTrainerCardRSContentColors[] = {TEXT_COLOR_TRANSPARENT, TEXT_DYNAMIC_COLOR_3, TEXT_DYNAMIC_COLOR_4};
static const u8 sTimeColonInvisibleTextColors[6] = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_TRANSPARENT, TEXT_COLOR_TRANSPARENT};

static const u8 sTrainerPicOffset[][GENDER_COUNT][2] =
{
    [CARD_REGION_KANTO] =
    {
        [MALE]   = {13, 4}, 
        [FEMALE] = {13, 4}
    },
    [CARD_REGION_HOENN] =
    {
        [MALE]   = {1, 0}, 
        [FEMALE] = {1, 0}
    },
    [CARD_REGION_JOHTO] =
    {
        [MALE]   = {13, 4}, 
        [FEMALE] = {13, 4}
    },

};

static const u8 sTrainerPicFacilityClass[][GENDER_COUNT] = 
{
    [CARD_TYPE_FRLG] = 
    {
        [MALE]   = FACILITY_CLASS_RED, 
        [FEMALE] = FACILITY_CLASS_LEAF
    }, 
    [CARD_TYPE_RS] = 
    {
        [MALE]   = FACILITY_CLASS_RS_BRENDAN, 
        [FEMALE] = FACILITY_CLASS_RS_MAY
    }, 
    [CARD_TYPE_EMERALD] = 
    {
        [MALE]   = FACILITY_CLASS_EM_BRENDAN, 
        [FEMALE] = FACILITY_CLASS_EM_MAY
    },
    [CARD_TYPE_CRYSTALDUST] = 
    {
        [MALE]   = FACILITY_CLASS_GOLD, 
        [FEMALE] = FACILITY_CLASS_KRIS
    }
};

static const u8 *const sTrainerCardBackStatColors[2] =
{
    sTrainerCardStatColors,
    sTrainerCardRSStatColors
};

static const u8 *const sTrainerCardHoFTexts[2] =
{
    gText_HallOfFameDebut,
    gText_FirstHallOfFame
};

static const u8 *const sTrainerCardLinkBattleTexts[2] =
{
    gText_LinkBattles,
    gText_LinkCableBattles
};

static const u8 *const sTrainerCardContestTexts[2] =
{
    gText_WonContestsWFriends,
    gText_ContestsWFriends
};

static const u8 *const sTrainerCardTextWindowColors[2][2] =
{
    {sTrainerCardTextColors, sTrainerCardTextColors},
    {sTrainerCardRSTextColors, sTrainerCardRSContentColors}
};

static const u8 *const sTrainerCardIDNoTexts[2] =
{
    gText_IDNumber,
    gText_RSTrainerCardIDNo
};

static const u8 *const sTrainerCardTimeTexts[2][2] =
{
    {gText_Time, gText_Colon2},
    {gText_RSTrainerCardTime, gText_RSTrainerCardColon}
};

static const u8 *const sTrainerCardBackNameTextWindowColors[CARD_TYPE_COUNT] =
{
    [CARD_TYPE_RS]       = sTrainerCardRSContentColors,
    [CARD_TYPE_FRLG]     = sTrainerCardTextColors,
    [CARD_TYPE_CRYSTALDUST]     = sTrainerCardTextColors,
    [CARD_TYPE_EMERALD]  = sTrainerCardTextColors,
};

// First three stats on the trainer card are the same in all versions
// so it wouldn't make much sense to add them here.
static const u8 sTrainerCardStats[CARD_TYPE_COUNT][STAT_COUNT - 3] =
{
    [CARD_TYPE_RS]             = {CARD_STAT_POKEBLOCKS, CARD_STAT_CONTESTS, CARD_STAT_BATTLE_TOWER},
    [CARD_TYPE_EMERALD]        = {CARD_STAT_POKEBLOCKS, CARD_STAT_CONTESTS, CARD_STAT_BATTLE_POINTS},
    [CARD_TYPE_FRLG]           = {CARD_STAT_UNION_ROOM, CARD_STAT_BERRY_CRUSH, CARD_STAT_NONE},
    [CARD_TYPE_CRYSTALDUST]    = {CARD_STAT_CONTESTS, CARD_STAT_BATTLE_POINTS, CARD_STAT_NONE}
};

static const u8 sTrainerCardFonts[4] =
{
    [CARD_TYPE_RS]           = 3,
    [CARD_TYPE_FRLG]         = 2,
    [CARD_TYPE_EMERALD]      = 1,
    [CARD_TYPE_CRYSTALDUST]  = 2,
};

static const u8 sTrainerCardNameMoneyPokedexXOffsets[CARD_TYPE_COUNT] =
{
    [CARD_TYPE_RS]       = 16,
    [CARD_TYPE_FRLG]     = 20,
    [CARD_TYPE_CRYSTALDUST]     = 20,
    [CARD_TYPE_EMERALD]  = 16
};

static const u8 sTrainerCardFrontNameYOffsets[CARD_TYPE_COUNT] =
{
    [CARD_TYPE_RS]       = 32,
    [CARD_TYPE_FRLG]     = 29,
    [CARD_TYPE_CRYSTALDUST]     = 29,
    [CARD_TYPE_EMERALD]  = 33
};

static const u32 sTrainerCardFrontIdXOffsets[CARD_TYPE_COUNT][2] =
{
    [CARD_TYPE_RS]       = {96, 107},
    [CARD_TYPE_FRLG]     = {80, 132},
    [CARD_TYPE_CRYSTALDUST]     = {80, 132},
    [CARD_TYPE_EMERALD]  = {96, 120}
};

static const u32 sTrainerCardFrontIdYOffsets[CARD_TYPE_COUNT] =
{
    [CARD_TYPE_RS]       = 8,
    [CARD_TYPE_FRLG]     = 10,
    [CARD_TYPE_CRYSTALDUST]     = 10,
    [CARD_TYPE_EMERALD]  = 9
};

static const u32 sTrainerCardFrontStatsXOffsets[CARD_TYPE_COUNT] =
{
    [CARD_TYPE_RS]       = 120,
    [CARD_TYPE_FRLG]     = 136,
    [CARD_TYPE_CRYSTALDUST]     = 136,
    [CARD_TYPE_EMERALD]  = 128
};

static const u8 sTrainerCardProfilePhraseYOffsets[CARD_TYPE_COUNT][2] =
{
    [CARD_TYPE_RS]       = {104, 120},
    [CARD_TYPE_FRLG]     = {115, 130},
    [CARD_TYPE_CRYSTALDUST]     = {115, 130},
    [CARD_TYPE_EMERALD]  = {104, 120}
};

static const u8 sTrainerCardBackNameYOffsets[CARD_TYPE_COUNT] =
{
    [CARD_TYPE_RS]       = 8,
    [CARD_TYPE_FRLG]     = 11,
    [CARD_TYPE_CRYSTALDUST]     = 11,
    [CARD_TYPE_EMERALD]  = 9
};

static const u8 sTrainerCardBackStatsYOffsets[CARD_TYPE_COUNT] =
{
    [CARD_TYPE_RS]           = 32,
    [CARD_TYPE_FRLG]         = 35,
    [CARD_TYPE_CRYSTALDUST]  = 35,
    [CARD_TYPE_EMERALD]      = 33
};

static bool8 (*const sTrainerCardFlipTasks[])(struct Task *) =
{
    Task_BeginCardFlip,
    Task_AnimateCardFlipDown,
    Task_DrawFlippedCardSide,
    Task_SetCardFlipped,
    Task_AnimateCardFlipUp,
    Task_EndCardFlip,
};

static void VblankCb_TrainerCard(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
    BlinkTimeColon();
    if (sData->allowDMACopy)
        DmaCopy16(3, &gScanlineEffectRegBuffers[0], &gScanlineEffectRegBuffers[1], 0x140);
}

static void HblankCb_TrainerCard(void)
{
    u16 backup;
    u16 bgVOffset;

    backup = REG_IME;
    REG_IME = 0;
    bgVOffset = gScanlineEffectRegBuffers[1][REG_VCOUNT & 0xFF];
    REG_BG0VOFS = bgVOffset;
    REG_IME = backup;
}

static void CB2_TrainerCard(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

static void CloseTrainerCard(u8 taskId)
{
    SetMainCallback2(sData->callback2);
    FreeAllWindowBuffers();
    FREE_AND_SET_NULL(sData);
    DestroyTask(taskId);
}

// States for Task_TrainerCard. Skips the initial states, which are done once in order
#define STATE_HANDLE_INPUT_FRONT  10
#define STATE_HANDLE_INPUT_BACK   11
#define STATE_WAIT_FLIP_TO_BACK   12
#define STATE_WAIT_FLIP_TO_FRONT  13
#define STATE_CLOSE_CARD          14
#define STATE_WAIT_LINK_PARTNER   15
#define STATE_CLOSE_CARD_LINK     16

static void Task_TrainerCard(u8 taskId)
{
    switch (sData->mainState)
    {
    // Draw card initially
    case 0:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            FillWindowPixelBuffer(1, PIXEL_FILL(0));
            sData->mainState++;
        }
        break;
    case 1:
        if (PrintAllOnCardFront())
            sData->mainState++;
        break;
    case 2:
        DrawTrainerCardWindow(1);
        sData->mainState++;
        break;
    case 3:
        FillWindowPixelBuffer(2, PIXEL_FILL(0));
        CreateTrainerCardTrainerPic();
        DrawTrainerCardWindow(2);
        sData->mainState++;
        break;
    case 4:
        DrawCardScreenBackground(sData->bgTilemap);
        sData->mainState++;
        break;
    case 5:
        DrawCardFrontOrBack(sData->frontTilemap);
        sData->mainState++;
        break;
    case 6:
        DrawStarsAndBadgesOnCard();
        sData->mainState++;
        break;
    // Fade in
    case 7:
        if (gWirelessCommType == 1 && gReceivedRemoteLinkPlayers == TRUE)
        {
            LoadWirelessStatusIndicatorSpriteGfx();
            CreateWirelessStatusIndicatorSprite(230, 150);
        }
        BlendPalettes(PALETTES_ALL, 16, sData->blendColor);
        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, sData->blendColor);
        SetVBlankCallback(VblankCb_TrainerCard);
        sData->mainState++;
        break;
    case 8:
        if (!UpdatePaletteFade() && !IsDma3ManagerBusyWithBgCopy())
        {
            PlaySE(SE_RG_CARD_OPEN);
            sData->mainState = STATE_HANDLE_INPUT_FRONT;
        }
        break;
    case 9:
        if (!IsSEPlaying())
            sData->mainState++;
        break;
    case STATE_HANDLE_INPUT_FRONT:
        // Blink the : in play time
        if (!gReceivedRemoteLinkPlayers && sData->timeColonNeedDraw)
        {
            PrintTimeOnCard();
            DrawTrainerCardWindow(1);
            sData->timeColonNeedDraw = FALSE;
        }
        if (JOY_NEW(A_BUTTON))
        {
            FlipTrainerCard();
            PlaySE(SE_RG_CARD_FLIP);
            sData->mainState = STATE_WAIT_FLIP_TO_BACK;
        }
        else if (JOY_NEW(B_BUTTON))
        {
            if (gReceivedRemoteLinkPlayers && sData->isLink && InUnionRoom() == TRUE)
            {
                sData->mainState = STATE_WAIT_LINK_PARTNER;
            }
            else
            {
                BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, sData->blendColor);
                sData->mainState = STATE_CLOSE_CARD;
            }
        }
        break;
    case STATE_WAIT_FLIP_TO_BACK:
        if (IsCardFlipTaskActive() && Overworld_LinkRecvQueueLengthMoreThan2() != TRUE)
        {
            PlaySE(SE_RG_CARD_OPEN);
            sData->mainState = STATE_HANDLE_INPUT_BACK;
        }
        break;
    case STATE_HANDLE_INPUT_BACK:
        if (JOY_NEW(B_BUTTON))
        {
            if (gReceivedRemoteLinkPlayers && sData->isLink && InUnionRoom() == TRUE)
            {
                sData->mainState = STATE_WAIT_LINK_PARTNER;
            }
            else if (gReceivedRemoteLinkPlayers)
            {
                BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, sData->blendColor);
                sData->mainState = STATE_CLOSE_CARD;
            }
            else
            {
                FlipTrainerCard();
                sData->mainState = STATE_WAIT_FLIP_TO_FRONT;
                PlaySE(SE_RG_CARD_FLIP);
            }
        }
        else if (JOY_NEW(A_BUTTON))
        {
           if (gReceivedRemoteLinkPlayers && sData->isLink && InUnionRoom() == TRUE)
           {
               sData->mainState = STATE_WAIT_LINK_PARTNER;
           }
           else
           {
               BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, sData->blendColor);
               sData->mainState = STATE_CLOSE_CARD;
           }
        }
        break;
    case STATE_WAIT_LINK_PARTNER:
        SetCloseLinkCallback();
        DrawDialogueFrame(0, 1);
        AddTextPrinterParameterized(0, 2, gText_WaitingTrainerFinishReading, 0, 1, 255, 0);
        CopyWindowToVram(0, 3);
        sData->mainState = STATE_CLOSE_CARD_LINK;
        break;
    case STATE_CLOSE_CARD_LINK:
        if (!gReceivedRemoteLinkPlayers)
        {
            BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, sData->blendColor);
            sData->mainState = STATE_CLOSE_CARD;
        }
        break;
    case STATE_CLOSE_CARD:
        if (!UpdatePaletteFade())
            CloseTrainerCard(taskId);
        break;
    case STATE_WAIT_FLIP_TO_FRONT:
        if (IsCardFlipTaskActive() && Overworld_LinkRecvQueueLengthMoreThan2() != TRUE)
        {
            sData->mainState = STATE_HANDLE_INPUT_FRONT;
            PlaySE(SE_RG_CARD_OPEN);
        }
        break;
   }
}

static bool8 LoadCardGfx(void)
{
    switch (sData->gfxLoadState)
    {
    case 0:
        if (sData->cardType == CARD_TYPE_CRYSTALDUST)
            LZ77UnCompWram(gJohtoTrainerCardBg_Tilemap, sData->bgTilemap);
        else if (sData->cardType == CARD_TYPE_FRLG)
            LZ77UnCompWram(gKantoTrainerCardBg_Tilemap, sData->bgTilemap);
        else
            LZ77UnCompWram(gHoennTrainerCardBg_Tilemap, sData->bgTilemap);
        break;
    case 1:
        if (sData->cardType == CARD_TYPE_CRYSTALDUST)
            LZ77UnCompWram(gJohtoTrainerCardBack_Tilemap, sData->backTilemap);
        else if (sData->cardType == CARD_TYPE_FRLG)
            LZ77UnCompWram(gKantoTrainerCardBack_Tilemap, sData->backTilemap);
        else
            LZ77UnCompWram(gHoennTrainerCardBack_Tilemap, sData->backTilemap);
        break;
    case 2:
        if (!sData->isLink)
        {
            if (sData->cardType == CARD_TYPE_CRYSTALDUST)
                LZ77UnCompWram(gJohtoTrainerCardFront_Tilemap, sData->frontTilemap);
            else if (sData->cardType == CARD_TYPE_FRLG)
                LZ77UnCompWram(gKantoTrainerCardFront_Tilemap, sData->frontTilemap);
            else
                LZ77UnCompWram(gHoennTrainerCardFront_Tilemap, sData->frontTilemap);
        }
        else
        {
            if (sData->cardType == CARD_TYPE_CRYSTALDUST)
                LZ77UnCompWram(gJohtoTrainerCardFrontLink_Tilemap, sData->frontTilemap);
            else if (sData->cardType == CARD_TYPE_FRLG)
                LZ77UnCompWram(gKantoTrainerCardFrontLink_Tilemap, sData->frontTilemap);
            else
                LZ77UnCompWram(gHoennTrainerCardFrontLink_Tilemap, sData->frontTilemap);
        }
        break;
    case 3:
        if (sData->cardType == CARD_TYPE_CRYSTALDUST)
            LZ77UnCompWram(sJohtoTrainerCardBadges_Gfx, sData->badgeTiles);
        else if (sData->cardType == CARD_TYPE_FRLG)
            LZ77UnCompWram(sKantoTrainerCardBadges_Gfx, sData->badgeTiles);
        else
            LZ77UnCompWram(sHoennTrainerCardBadges_Gfx, sData->badgeTiles);
        break;
    case 4:
        if (sData->cardType == CARD_TYPE_CRYSTALDUST)
            LZ77UnCompWram(gJohtoTrainerCard_Gfx, sData->cardTiles);
        else if (sData->cardType == CARD_TYPE_FRLG)
            LZ77UnCompWram(gKantoTrainerCard_Gfx, sData->cardTiles);
        else
            LZ77UnCompWram(gHoennTrainerCard_Gfx, sData->cardTiles);
        break;
    case 5:
        if (sData->cardType == CARD_TYPE_FRLG)
            LZ77UnCompWram(sTrainerCardStickers_Gfx, sData->stickerTiles);
        break;
    default:
        sData->gfxLoadState = 0;
        return TRUE;
    }
    sData->gfxLoadState++;
    return FALSE;
}

static void CB2_InitTrainerCard(void)
{
    switch (gMain.state)
    {
    case 0:
        ResetGpuRegs();
        SetUpTrainerCardTask();
        gMain.state++;
        break;
    case 1:
        DmaClear32(3, (void *)OAM, OAM_SIZE);
        gMain.state++;
        break;
    case 2:
        if (!sData->blendColor)
            DmaClear16(3, (void *)PLTT, PLTT_SIZE);
        gMain.state++;
        break;
    case 3:
        ResetSpriteData();
        FreeAllSpritePalettes();
        ResetPaletteFade();
        gMain.state++;
    case 4:
        InitBgsAndWindows();
        gMain.state++;
        break;
    case 5:
        LoadMonIconGfx();
        gMain.state++;
        break;
    case 6:
        if (LoadCardGfx() == TRUE)
            gMain.state++;
        break;
    case 7:
        LoadStickerGfx();
        gMain.state++;
        break;
    case 8:
        InitGpuRegs();
        gMain.state++;
        break;
    case 9:
        BufferTextsVarsForCardPage2();
        gMain.state++;
        break;
    case 10:
        if (SetCardBgsAndPals() == TRUE)
            gMain.state++;
        break;
    default:
        SetTrainerCardCb2();
        break;
    }
}

static u32 GetCappedGameStat(u8 statId, u32 maxValue)
{
    u32 statValue = GetGameStat(statId);

    return min(maxValue, statValue);
}

static bool8 HasAllFrontierSymbols(void)
{
    u8 i;
    for (i = 0; i < NUM_FRONTIER_FACILITIES; i++)
    {
        if (!FlagGet(FLAG_SYS_TOWER_SILVER + 2 * i) || !FlagGet(FLAG_SYS_TOWER_GOLD + 2 * i))
            return FALSE;
    }
    return TRUE;
}

u32 CountPlayerTrainerStars(void)
{
    u8 stars = 0;

    if (GetGameStat(GAME_STAT_ENTERED_HOF))
        stars++;
    if (HasAllJohtoMons())
        stars++;
    if (CountPlayerMuseumPaintings() >= CONTEST_CATEGORIES_COUNT)
        stars++;
    if (HasAllFrontierSymbols())
        stars++;

    return stars;
}

static u8 GetRubyTrainerStars(struct TrainerCard *trainerCard)
{
    u8 stars = 0;

    if (trainerCard->hofDebutHours || trainerCard->hofDebutMinutes || trainerCard->hofDebutSeconds)
        stars++;
    if (trainerCard->caughtAllJohto)
        stars++;
    if (trainerCard->battleTowerStraightWins > 49)
        stars++;
    if (trainerCard->hasAllPaintings)
        stars++;

    return stars;
}

static void SetPlayerCardData(struct TrainerCard *trainerCard, u8 cardType)
{
    u32 playTime;
    u8 i;

    trainerCard->gender = gSaveBlock2Ptr->playerGender;
    trainerCard->playTimeHours = gSaveBlock2Ptr->playTimeHours;
    trainerCard->playTimeMinutes = gSaveBlock2Ptr->playTimeMinutes;

    playTime = GetGameStat(GAME_STAT_FIRST_HOF_PLAY_TIME);
    if (!GetGameStat(GAME_STAT_ENTERED_HOF))
        playTime = 0;

    trainerCard->hofDebutHours = playTime >> 16;
    trainerCard->hofDebutMinutes = (playTime >> 8) & 0xFF;
    trainerCard->hofDebutSeconds = playTime & 0xFF;
    if ((playTime >> 16) > 999)
    {
        trainerCard->hofDebutHours = 999;
        trainerCard->hofDebutMinutes = 59;
        trainerCard->hofDebutSeconds = 59;
    }

    trainerCard->hasPokedex = FlagGet(FLAG_SYS_POKEDEX_GET);
    trainerCard->caughtAllJohto = HasAllJohtoMons();
    trainerCard->caughtMonsCount = GetCaughtMonsCount();

    trainerCard->trainerId = (gSaveBlock2Ptr->playerTrainerId[1] << 8) | gSaveBlock2Ptr->playerTrainerId[0];

    trainerCard->linkBattleWins = GetCappedGameStat(GAME_STAT_LINK_BATTLE_WINS, 9999);
    trainerCard->linkBattleLosses = GetCappedGameStat(GAME_STAT_LINK_BATTLE_LOSSES, 9999);

    trainerCard->pokemonTrades = GetCappedGameStat(GAME_STAT_POKEMON_TRADES, 0xFFFF);

    trainerCard->money = GetMoney(&gSaveBlock1Ptr->money);

    for (i = 0; i < TRAINER_CARD_PROFILE_LENGTH; i++)
        trainerCard->easyChatProfile[i] = gSaveBlock1Ptr->easyChatProfile[i];

    StringCopy(trainerCard->playerName, gSaveBlock2Ptr->playerName);

    switch (cardType)
    {
    case CARD_TYPE_CRYSTALDUST:
    case CARD_TYPE_EMERALD:
        trainerCard->battleTowerWins = 0;
        trainerCard->battleTowerStraightWins = 0;
    case CARD_TYPE_RS:
        trainerCard->contestsWithFriends = GetCappedGameStat(GAME_STAT_WON_LINK_CONTEST, 999);
        trainerCard->pokeblocksWithFriends = GetCappedGameStat(GAME_STAT_POKEBLOCKS_WITH_FRIENDS, 0xFFFF);
        if (CountPlayerMuseumPaintings() >= CONTEST_CATEGORIES_COUNT)
            trainerCard->hasAllPaintings = TRUE;
        trainerCard->stars = GetRubyTrainerStars(trainerCard);
        break;
    case CARD_TYPE_FRLG:
        trainerCard->battleTowerWins = 0;
        trainerCard->battleTowerStraightWins = 0;
        trainerCard->contestsWithFriends = 0;
        trainerCard->pokeblocksWithFriends = 0;
        trainerCard->hasAllPaintings = 0;
        trainerCard->stars = 0;
        break;
    }
}

static void TrainerCard_GenerateCardToShowLocally(struct TrainerCard *trainerCard)
{
    memset(trainerCard, 0, sizeof(struct TrainerCard));
    trainerCard->version = GAME_VERSION;
    trainerCard->realVersion = GAME_VERSION;
    SetPlayerCardData(trainerCard, CARD_TYPE_CRYSTALDUST);
    trainerCard->hasAllSymbols = HasAllFrontierSymbols();
    trainerCard->frontierBP = gSaveBlock2Ptr->frontier.cardBattlePoints;
    if (trainerCard->hasAllSymbols)
        trainerCard->stars++;

    if (trainerCard->gender == FEMALE)
        trainerCard->facilityClass = gLinkPlayerFacilityClasses[(trainerCard->trainerId % NUM_FEMALE_LINK_FACILITY_CLASSES) + NUM_MALE_LINK_FACILITY_CLASSES];
    else
        trainerCard->facilityClass = gLinkPlayerFacilityClasses[trainerCard->trainerId % NUM_MALE_LINK_FACILITY_CLASSES];

    trainerCard->monIconTint = VarGet(VAR_TRAINER_CARD_MON_ICON_TINT_IDX);

    trainerCard->monSpecies[0] = GetIconSpeciesNoPersonality(VarGet(VAR_TRAINER_CARD_MON_ICON_1));
    trainerCard->monSpecies[1] = GetIconSpeciesNoPersonality(VarGet(VAR_TRAINER_CARD_MON_ICON_2));
    trainerCard->monSpecies[2] = GetIconSpeciesNoPersonality(VarGet(VAR_TRAINER_CARD_MON_ICON_3));
    trainerCard->monSpecies[3] = GetIconSpeciesNoPersonality(VarGet(VAR_TRAINER_CARD_MON_ICON_4));
    trainerCard->monSpecies[4] = GetIconSpeciesNoPersonality(VarGet(VAR_TRAINER_CARD_MON_ICON_5));
    trainerCard->monSpecies[5] = GetIconSpeciesNoPersonality(VarGet(VAR_TRAINER_CARD_MON_ICON_6));
}

void TrainerCard_GenerateCardToSendInLink(struct TrainerCard *trainerCard)
{
    memset(trainerCard, 0, 0x60);
    trainerCard->version = VERSION_FIRE_RED;
    trainerCard->realVersion = GAME_VERSION;
    SetPlayerCardData(trainerCard, CARD_TYPE_CRYSTALDUST);
    trainerCard->hasAllFrontierSymbols = HasAllFrontierSymbols();
    *((u16*)&trainerCard->berryCrushPoints) = gSaveBlock2Ptr->frontier.cardBattlePoints;
    if (trainerCard->hasAllFrontierSymbols)
        trainerCard->stars++;

    if (trainerCard->gender == FEMALE)
        trainerCard->facilityClass = gLinkPlayerFacilityClasses[(trainerCard->trainerId % NUM_FEMALE_LINK_FACILITY_CLASSES) + NUM_MALE_LINK_FACILITY_CLASSES];
    else
        trainerCard->facilityClass = gLinkPlayerFacilityClasses[trainerCard->trainerId % NUM_MALE_LINK_FACILITY_CLASSES];

    trainerCard->monIconTint = VarGet(VAR_TRAINER_CARD_MON_ICON_TINT_IDX);

    trainerCard->monSpecies[0] = GetIconSpeciesNoPersonality(VarGet(VAR_TRAINER_CARD_MON_ICON_1));
    trainerCard->monSpecies[1] = GetIconSpeciesNoPersonality(VarGet(VAR_TRAINER_CARD_MON_ICON_2));
    trainerCard->monSpecies[2] = GetIconSpeciesNoPersonality(VarGet(VAR_TRAINER_CARD_MON_ICON_3));
    trainerCard->monSpecies[3] = GetIconSpeciesNoPersonality(VarGet(VAR_TRAINER_CARD_MON_ICON_4));
    trainerCard->monSpecies[4] = GetIconSpeciesNoPersonality(VarGet(VAR_TRAINER_CARD_MON_ICON_5));
    trainerCard->monSpecies[5] = GetIconSpeciesNoPersonality(VarGet(VAR_TRAINER_CARD_MON_ICON_6));
}

void CopyTrainerCardData(struct TrainerCard *dst, u16 *src, u8 gameVersion)
{
    memset(dst, 0, sizeof(struct TrainerCard));
    dst->version = gameVersion;

    switch (VersionToCardType(gameVersion))
    {
    case CARD_TYPE_FRLG:
        memcpy(dst, src, 0x60);
        break;
    case CARD_TYPE_RS:
        memcpy(dst, src, 0x38);
        break;
    case CARD_TYPE_EMERALD:
    case CARD_TYPE_CRYSTALDUST:
        memcpy(dst, src, 0x60);
        if (dst->realVersion != 0)
        {
            dst->version = dst->realVersion;
            dst->realVersion = 0;
        }
        dst->berryCrushPoints = 0;
        dst->hasAllSymbols = src[29];
        dst->frontierBP = src[30];
        break;
    }
}

static void SetDataFromTrainerCard(void)
{
    u8 i;
    u32 badgeFlag;

    sData->hasPokedex = FALSE;
    sData->hasHofResult = FALSE;
    sData->hasLinkResults = FALSE;
    sData->hasBattleTowerWins = FALSE;
    sData->unused_E = FALSE;
    sData->unused_F = FALSE;
    sData->hasTrades = FALSE;
    memset(sData->badgeCount, 0, sizeof(sData->badgeCount));
    if (sData->trainerCard.hasPokedex)
        sData->hasPokedex++;

    if (sData->trainerCard.hofDebutHours
     || sData->trainerCard.hofDebutMinutes
     || sData->trainerCard.hofDebutSeconds)
        sData->hasHofResult++;

    if (sData->trainerCard.linkBattleWins || sData->trainerCard.linkBattleLosses)
        sData->hasLinkResults++;
    if (sData->trainerCard.pokemonTrades)
        sData->hasTrades++;
    if (sData->trainerCard.battleTowerWins || sData->trainerCard.battleTowerStraightWins)
        sData->hasBattleTowerWins++;

    for (i = 0, badgeFlag = FLAG_BADGE01_GET; badgeFlag < FLAG_BADGE01_GET + NUM_BADGES; badgeFlag++, i++)
    {
        if (FlagGet(badgeFlag))
            sData->badgeCount[i]++;
    }
}

static void InitGpuRegs(void)
{
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON | DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
    ShowBg(0);
    ShowBg(1);
    ShowBg(2);
    ShowBg(3);
    SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG0 | BLDCNT_EFFECT_DARKEN);
    SetGpuReg(REG_OFFSET_BLDY, 0);
    SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG_ALL | WININ_WIN0_OBJ | WININ_WIN0_CLR);
    SetGpuReg(REG_OFFSET_WINOUT, WINOUT_WIN01_BG1 | WINOUT_WIN01_BG2 | WINOUT_WIN01_BG3 | WINOUT_WIN01_OBJ);
    SetGpuReg(REG_OFFSET_WIN0V, DISPLAY_HEIGHT);
    SetGpuReg(REG_OFFSET_WIN0H, DISPLAY_WIDTH);
    if (gReceivedRemoteLinkPlayers)
        EnableInterrupts(INTR_FLAG_VBLANK | INTR_FLAG_HBLANK | INTR_FLAG_VCOUNT | INTR_FLAG_TIMER3 | INTR_FLAG_SERIAL);
    else
        EnableInterrupts(INTR_FLAG_VBLANK | INTR_FLAG_HBLANK);
}

static void UpdateCardFlipRegs(u16 cardTop)
{
    s8 blendY = (cardTop + 40) / 10;

    if (blendY <= 4)
        blendY = 0;
    sData->flipBlendY = blendY;
    SetGpuReg(REG_OFFSET_BLDY, sData->flipBlendY);
    SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE(sData->cardTop, DISPLAY_HEIGHT - sData->cardTop));
}

static void ResetGpuRegs(void)
{
    SetVBlankCallback(NULL);
    SetHBlankCallback(NULL);
    SetGpuReg(REG_OFFSET_DISPCNT, 0);
    SetGpuReg(REG_OFFSET_BG0CNT, 0);
    SetGpuReg(REG_OFFSET_BG1CNT, 0);
    SetGpuReg(REG_OFFSET_BG2CNT, 0);
    SetGpuReg(REG_OFFSET_BG3CNT, 0);
}

static void InitBgsAndWindows(void)
{
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, sTrainerCardBgTemplates, ARRAY_COUNT(sTrainerCardBgTemplates));
    ChangeBgX(0, 0, 0);
    ChangeBgY(0, 0, 0);
    ChangeBgX(1, 0, 0);
    ChangeBgY(1, 0, 0);
    ChangeBgX(2, 0, 0);
    ChangeBgY(2, 0, 0);
    ChangeBgX(3, 0, 0);
    ChangeBgY(3, 0, 0);
    InitWindows(sTrainerCardWindowTemplates);
    DeactivateAllTextPrinters();
    LoadMessageBoxAndBorderGfx();
}

static void SetTrainerCardCb2(void)
{
    SetMainCallback2(CB2_TrainerCard);
}

static void SetUpTrainerCardTask(void)
{
    ResetTasks();
    ScanlineEffect_Stop();
    CreateTask(Task_TrainerCard, 0);
    InitTrainerCardData();
    SetDataFromTrainerCard();
}

static bool8 PrintAllOnCardFront(void)
{
    u16 palette;

    switch (sData->printState)
    {
    case 0:
        if (sData->cardType == CARD_TYPE_RS)
        {
            palette = RGB(0, 0, 0);
            LoadPalette(&palette, 250, 2);
            palette = RGB(25, 25, 25);
            LoadPalette(&palette, 251, 2);
            palette = RGB(9, 9, 9);
            LoadPalette(&palette, 252, 2);
            palette = RGB(26, 26, 25);
            LoadPalette(&palette, 253, 2);
            palette = RGB(31, 0, 0);
            LoadPalette(&palette, 254, 2);
            palette = RGB(31, 0, 31);
            LoadPalette(&palette, 255, 2);
        }
        else
        {
            palette = RGB(15, 28, 27);
            LoadPalette(&palette, 250, 2);
            palette = RGB(13, 25, 24);
            LoadPalette(&palette, 251, 2);
            palette = RGB(30, 26, 17);
            LoadPalette(&palette, 252, 2);
            palette = RGB(15, 18, 18);
            LoadPalette(&palette, 253, 2);
            palette = RGB(30, 25, 18);
            LoadPalette(&palette, 254, 2);
            palette = RGB(31, 30, 23);
            LoadPalette(&palette, 255, 2);
        }
        PrintNameOnCardFront();
        break;
    case 1:
        PrintIdOnCard();
        break;
    case 2:
        PrintMoneyOnCard();
        break;
    case 3:
        PrintPokedexOnCard();
        break;
    case 4:
        PrintTimeOnCard();
        break;
    case 5:
        PrintProfilePhraseOnCard();
        break;
    default:
        sData->printState = 0;
        return TRUE;
    }
    sData->printState++;
    return FALSE;
}

static void PrintStatBySlot(u8 slot)
{
    switch (sData->stats[slot])
    {
    case CARD_STAT_HOF_DEBUT:
        PrintHofDebutTimeOnCard(slot);
        break;
    case CARD_STAT_LINK_BATTLES:
        PrintLinkBattleResultsOnCard(slot);
        break;
    case CARD_STAT_TRADES:
        PrintTradesStringOnCard(slot);
        break;
    case CARD_STAT_POKEBLOCKS:
        PrintPokeblockStringOnCard(slot);
        break;
    case CARD_STAT_CONTESTS:
        PrintContestStringOnCard(slot);
        break;
    case CARD_STAT_BATTLE_TOWER:
        PrintBattleTowerStringOnCard(slot);
        break;
    case CARD_STAT_UNION_ROOM:
        PrintUnionStringOnCard(slot);
        break;
    case CARD_STAT_BERRY_CRUSH:
        PrintBerryCrushStringOnCard(slot);
        break;
    case CARD_STAT_BATTLE_POINTS:
        PrintBattlePointsStringOnCard(slot);
        break;
    }
}

static bool8 PrintAllOnCardBack(void)
{
    switch (sData->printState)
    {
    case 0:
        PrintNameOnCardBack();
        break;
    case 1 ... 6:
        if (sData->stats[sData->printState - 1])
            PrintStatBySlot(sData->printState - 1);
        break;
    case 7:
        PrintPokemonIconsOnCard();
        break;
    case 8:
        PrintStickersOnCard();
        break;
    default:
        sData->printState = 0;
        return TRUE;
    }
    sData->printState++;
    return FALSE;
}

static void BufferTextsVarsForCardPage2(void)
{
    BufferNameForCardBack();
    BufferHofDebutTime();
    BufferLinkBattleResults();
    BufferNumTrades();
    BufferBerryCrushPoints();
    BufferUnionRoomStats();
    BufferLinkPokeblocksNum();
    BufferLinkContestNum();
    BufferBattlePoints();
    BufferBattleTowerWins();
}

static void PrintNameOnCardFront(void)
{
    u8 buffer[32];
    u8* txtPtr;
    u8 x = sTrainerCardNameMoneyPokedexXOffsets[sData->cardType];
    if (sData->cardType == CARD_TYPE_RS)
    {
        AddTextPrinterParameterized3(1, 3, x, 32, sTrainerCardRSTextColors, TEXT_SPEED_FF, gText_Name);
        txtPtr = StringCopy(buffer, sData->trainerCard.playerName);
        x += 32;
    }
    else
    {
        txtPtr = StringCopy(buffer, gText_TrainerCardName);
        StringCopy(txtPtr, sData->trainerCard.playerName);
    }
    ConvertInternationalString(txtPtr, sData->language);
    AddTextPrinterParameterized3(1, sTrainerCardFonts[sData->cardType], x, sTrainerCardFrontNameYOffsets[sData->cardType], sTrainerCardTextWindowColors[sData->cardType == CARD_TYPE_RS][0], TEXT_SPEED_FF, buffer);
}

static void PrintIdOnCard(void)
{
    u8 buffer[32];
    u8* txtPtr;
    s32 xPos;

    txtPtr = StringCopy(buffer, sTrainerCardIDNoTexts[sData->cardType == CARD_TYPE_RS]);
    ConvertIntToDecimalStringN(txtPtr, sData->trainerCard.trainerId, STR_CONV_MODE_LEADING_ZEROS, 5);
    xPos = GetStringCenterAlignXOffset(sTrainerCardFonts[sData->cardType], buffer, sTrainerCardFrontIdXOffsets[sData->cardType][0]) + sTrainerCardFrontIdXOffsets[sData->cardType][1];

    AddTextPrinterParameterized3(1, sTrainerCardFonts[sData->cardType], xPos, sTrainerCardFrontIdYOffsets[sData->cardType], sTrainerCardTextColors, TEXT_SPEED_FF, buffer);
}

static void PrintMoneyOnCard(void)
{
    s32 xOffset;
    u8 top = 56;

    if (sData->cardType == CARD_TYPE_EMERALD)
        top = 57;
    AddTextPrinterParameterized3(1, sTrainerCardFonts[sData->cardType], sTrainerCardNameMoneyPokedexXOffsets[sData->cardType], top, sTrainerCardTextWindowColors[sData->cardType == CARD_TYPE_RS][0], TEXT_SPEED_FF, gText_TrainerCardMoney);

    ConvertIntToDecimalStringN(gStringVar1, sData->trainerCard.money, STR_CONV_MODE_LEFT_ALIGN, 6);
    StringExpandPlaceholders(gStringVar4, gText_PokedollarVar1);
    xOffset = GetStringRightAlignXOffset(sTrainerCardFonts[sData->cardType], gStringVar4, sTrainerCardFrontStatsXOffsets[sData->cardType]);
    AddTextPrinterParameterized3(1, sTrainerCardFonts[sData->cardType], xOffset, top, sTrainerCardTextWindowColors[sData->cardType == CARD_TYPE_RS][1], TEXT_SPEED_FF, gStringVar4);
}

static u16 GetCaughtMonsCount(void)
{
    if (IsNationalPokedexEnabled())
        return GetNationalPokedexCount(FLAG_GET_CAUGHT);
    else
        return GetJohtoPokedexCount(FLAG_GET_CAUGHT);
}

static void PrintPokedexOnCard(void)
{
    if (FlagGet(FLAG_SYS_POKEDEX_GET))
    {
        s32 xOffset;
        u8 top = 72;

        if (sData->cardType == CARD_TYPE_EMERALD)
            top = 73;
        AddTextPrinterParameterized3(1, sTrainerCardFonts[sData->cardType], sTrainerCardNameMoneyPokedexXOffsets[sData->cardType], top, sTrainerCardTextWindowColors[sData->cardType == CARD_TYPE_RS][0], TEXT_SPEED_FF, gText_MenuOptionPokedex);
        StringCopy(ConvertIntToDecimalStringN(gStringVar4, sData->trainerCard.caughtMonsCount, STR_CONV_MODE_LEFT_ALIGN, 3), gText_ExpandedPlaceholder_Empty);

        xOffset = GetStringRightAlignXOffset(sTrainerCardFonts[sData->cardType], gStringVar4, sTrainerCardFrontStatsXOffsets[sData->cardType]);
        AddTextPrinterParameterized3(1, sTrainerCardFonts[sData->cardType], xOffset, top, sTrainerCardTextWindowColors[sData->cardType == CARD_TYPE_RS][1], TEXT_SPEED_FF, gStringVar4);
    }
}

static const u8 *const sTimeColonTextColors[][2] =
{
    {sTrainerCardTextColors, sTimeColonInvisibleTextColors},
    {sTrainerCardRSContentColors, sTimeColonInvisibleTextColors}
};

static void PrintTimeOnCard(void)
{
    u16 hours;
    u16 minutes;
    s32 width;
    u32 x, y, totalWidth;

    if (sData->cardType == CARD_TYPE_EMERALD)
        y = 89;
    else
        y = 88;
    AddTextPrinterParameterized3(1, sTrainerCardFonts[sData->cardType], sTrainerCardNameMoneyPokedexXOffsets[sData->cardType], y, sTrainerCardTextWindowColors[sData->cardType == CARD_TYPE_RS][0], TEXT_SPEED_FF, sTrainerCardTimeTexts[sData->cardType == CARD_TYPE_RS][0]);

    if (sData->isLink)
    {
        hours = sData->trainerCard.playTimeHours;
        minutes = sData->trainerCard.playTimeMinutes;
    }
    else
    {
        hours = gSaveBlock2Ptr->playTimeHours;
        minutes = gSaveBlock2Ptr->playTimeMinutes;
    }

    if (hours > 999)
        hours = 999;
    if (minutes > 59)
        minutes = 59;
    width = GetStringWidth(sTrainerCardFonts[sData->cardType], sTrainerCardTimeTexts[sData->cardType == CARD_TYPE_RS][1], 0);

    x = sTrainerCardFrontStatsXOffsets[sData->cardType];
    totalWidth = width + 30;
    x -= totalWidth;

    FillWindowPixelRect(1, PIXEL_FILL(0), x, y, totalWidth, 15);
    ConvertIntToDecimalStringN(gStringVar4, hours, STR_CONV_MODE_RIGHT_ALIGN, 3);

    AddTextPrinterParameterized3(1, sTrainerCardFonts[sData->cardType], x, y, sTrainerCardTextWindowColors[sData->cardType == CARD_TYPE_RS][1], TEXT_SPEED_FF, gStringVar4);
    x += 18;
    AddTextPrinterParameterized3(1, sTrainerCardFonts[sData->cardType], x, y, sTimeColonTextColors[sData->cardType == CARD_TYPE_RS][sData->timeColonInvisible], TEXT_SPEED_FF, sTrainerCardTimeTexts[sData->cardType == CARD_TYPE_RS][1]);
    x += width;
    ConvertIntToDecimalStringN(gStringVar4, minutes, STR_CONV_MODE_LEADING_ZEROS, 2);
    AddTextPrinterParameterized3(1, sTrainerCardFonts[sData->cardType], x, y, sTrainerCardTextWindowColors[sData->cardType == CARD_TYPE_RS][1], TEXT_SPEED_FF, gStringVar4);
}

static void PrintProfilePhraseOnCard(void)
{
    if (sData->isLink)
    {
        u8 x = (sData->region == CARD_REGION_HOENN) ? 8 : 10;
        u8 space = (sData->cardType == CARD_TYPE_RS) ? 3 : 6;
        const u8* txtColor;

        txtColor = sTrainerCardTextWindowColors[sData->cardType == CARD_TYPE_RS][1];

        AddTextPrinterParameterized3(1, sTrainerCardFonts[sData->cardType], x, sTrainerCardProfilePhraseYOffsets[sData->cardType][0], txtColor, TEXT_SPEED_FF, sData->easyChatProfile[0]);
        AddTextPrinterParameterized3(1, sTrainerCardFonts[sData->cardType], GetStringWidth(sTrainerCardFonts[sData->cardType], sData->easyChatProfile[0], 0) + space + x, sTrainerCardProfilePhraseYOffsets[sData->cardType][0], txtColor, TEXT_SPEED_FF, sData->easyChatProfile[1]);
        AddTextPrinterParameterized3(1, sTrainerCardFonts[sData->cardType], x, sTrainerCardProfilePhraseYOffsets[sData->cardType][1], txtColor, TEXT_SPEED_FF, sData->easyChatProfile[2]);
        AddTextPrinterParameterized3(1, sTrainerCardFonts[sData->cardType], GetStringWidth(sTrainerCardFonts[sData->cardType], sData->easyChatProfile[2], 0) + space + x, sTrainerCardProfilePhraseYOffsets[sData->cardType][1], txtColor, TEXT_SPEED_FF, sData->easyChatProfile[3]);
    }
}

static void BufferNameForCardBack(void)
{
    StringCopy(sData->textPlayersCard, sData->trainerCard.playerName);
    ConvertInternationalString(sData->textPlayersCard, sData->language);
    if (sData->cardType == CARD_TYPE_RS || sData->cardType == CARD_TYPE_EMERALD)
    {
        StringCopy(gStringVar1, sData->textPlayersCard);
        StringExpandPlaceholders(sData->textPlayersCard, gText_Var1sTrainerCard);
    }
}

static void PrintNameOnCardBack(void)
{
    const u8* txtColor;
    u8 x;
    u8 buffer[32];
    u8* txtPtr;

    x = GetStringRightAlignXOffset(sTrainerCardFonts[sData->cardType], sData->textPlayersCard, 216);
    if (sData->cardType == CARD_TYPE_FRLG || sData->cardType == CARD_TYPE_CRYSTALDUST)
    {
        x = 138;
    }
    AddTextPrinterParameterized3(1, sTrainerCardFonts[sData->cardType], x, sTrainerCardBackNameYOffsets[sData->cardType], sTrainerCardBackNameTextWindowColors[sData->cardType], TEXT_SPEED_FF, sData->textPlayersCard);
}

static const u8 sText_RSHofTime[] = _("{STR_VAR_1} : {STR_VAR_2} : {STR_VAR_3}");
static const u8 sText_HofTime[] = _("{STR_VAR_1}:{STR_VAR_2}:{STR_VAR_3}");

static void BufferHofDebutTime(void)
{
    if (sData->hasHofResult)
    {
        ConvertIntToDecimalStringN(gStringVar1, sData->trainerCard.hofDebutHours, STR_CONV_MODE_RIGHT_ALIGN, 3);
        ConvertIntToDecimalStringN(gStringVar2, sData->trainerCard.hofDebutMinutes, STR_CONV_MODE_LEADING_ZEROS, 2);
        ConvertIntToDecimalStringN(gStringVar3, sData->trainerCard.hofDebutSeconds, STR_CONV_MODE_LEADING_ZEROS, 2);
        StringExpandPlaceholders(sData->textHofTime, (sData->cardType == CARD_TYPE_RS) ? sText_RSHofTime : sText_HofTime);
    }
}

static void PrintStatOnBackOfCard(u8 top, const u8* statName, u8* stat, const u8* color)
{
    u8 x = 10;

    if (sData->region == CARD_REGION_HOENN)
        x = 16;

    AddTextPrinterParameterized3(1, sTrainerCardFonts[sData->cardType], x, top * 16 + sTrainerCardBackStatsYOffsets[sData->cardType], sTrainerCardTextWindowColors[sData->cardType == CARD_TYPE_RS][1], TEXT_SPEED_FF, statName);
    AddTextPrinterParameterized3(1, sTrainerCardFonts[sData->cardType], GetStringRightAlignXOffset(sTrainerCardFonts[sData->cardType], stat, 216), top * 16 + sTrainerCardBackStatsYOffsets[sData->cardType], color, TEXT_SPEED_FF, stat);
}

static void PrintHofDebutTimeOnCard(u8 slot)
{
    if (sData->hasHofResult)
        PrintStatOnBackOfCard(slot, sTrainerCardHoFTexts[sData->cardType == CARD_TYPE_RS], sData->textHofTime, sTrainerCardBackStatColors[sData->cardType == CARD_TYPE_RS]);
}

static const u8 *const sLinkBattleTexts[] = 
{
    [CARD_TYPE_FRLG]        = gText_LinkBattles, 
    [CARD_TYPE_RS]          = gText_LinkCableBattles, 
    [CARD_TYPE_EMERALD]     = gText_LinkBattles,
    [CARD_TYPE_CRYSTALDUST] = gText_LinkBattles
};

static void BufferLinkBattleResults(void)
{
    if (sData->hasLinkResults)
    {
        u8 align = STR_CONV_MODE_RIGHT_ALIGN; 

        if (sData->cardType == CARD_TYPE_EMERALD)
            align = STR_CONV_MODE_LEFT_ALIGN;

        StringCopy(sData->textLinkBattleType, sTrainerCardLinkBattleTexts[sData->cardType == CARD_TYPE_RS]);
        ConvertIntToDecimalStringN(sData->textLinkBattleWins, sData->trainerCard.linkBattleWins, align, 4);
        ConvertIntToDecimalStringN(sData->textLinkBattleLosses, sData->trainerCard.linkBattleLosses, align, 4);
    }
}

static void PrintLinkBattleResultsOnCard(u8 slot)
{
    if (sData->hasLinkResults)
    {
        if (sData->cardType == CARD_TYPE_RS)
        {
            AddTextPrinterParameterized3(1, sTrainerCardFonts[sData->cardType], 16, slot * 16 + 32, sTrainerCardRSContentColors, TEXT_SPEED_FF, sData->textLinkBattleType);
            AddTextPrinterParameterized3(1, sTrainerCardFonts[sData->cardType], GetStringRightAlignXOffset(sTrainerCardFonts[sData->cardType], sData->textLinkBattleWins, 168), slot * 16 + 32, sTrainerCardRSStatColors, TEXT_SPEED_FF, sData->textLinkBattleWins);
            AddTextPrinterParameterized3(1, sTrainerCardFonts[sData->cardType], GetStringRightAlignXOffset(sTrainerCardFonts[sData->cardType], sData->textLinkBattleLosses, 216), slot * 16 + 32, sTrainerCardRSStatColors, TEXT_SPEED_FF, sData->textLinkBattleLosses);
        }
        else if (sData->region == CARD_REGION_KANTO || sData->region == CARD_REGION_JOHTO)
        {
            AddTextPrinterParameterized3(1, sTrainerCardFonts[sData->cardType], 10, slot * 16 + 35, sTrainerCardTextColors, TEXT_SPEED_FF, sData->textLinkBattleType);
            AddTextPrinterParameterized3(1, sTrainerCardFonts[sData->cardType], 130, slot * 16 + 35, sTrainerCardTextColors, TEXT_SPEED_FF, gText_FRLGWinsLosses);
            AddTextPrinterParameterized3(1, sTrainerCardFonts[sData->cardType], 144, slot * 16 + 35, sTrainerCardStatColors, TEXT_SPEED_FF, sData->textLinkBattleWins);
            AddTextPrinterParameterized3(1, sTrainerCardFonts[sData->cardType], 192, slot * 16 + 35, sTrainerCardStatColors, TEXT_SPEED_FF, sData->textLinkBattleLosses);
        }
        else
        {
            StringCopy(gStringVar1, sData->textLinkBattleWins);
            StringCopy(gStringVar2, sData->textLinkBattleLosses);
            StringExpandPlaceholders(gStringVar4, gText_WinsLosses);
            PrintStatOnBackOfCard(slot, sData->textLinkBattleType, gStringVar4, sTrainerCardTextColors);
        }
    }
}

static void BufferNumTrades(void)
{
    if (sData->hasTrades)
        ConvertIntToDecimalStringN(sData->textNumTrades, sData->trainerCard.pokemonTrades, STR_CONV_MODE_RIGHT_ALIGN, 5);
}

static void PrintTradesStringOnCard(u8 slot)
{
    if (sData->hasTrades)
        PrintStatOnBackOfCard(slot, gText_PokemonTrades, sData->textNumTrades, sTrainerCardBackStatColors[sData->cardType == CARD_TYPE_RS]);
}

static void BufferBerryCrushPoints(void)
{
    if (sData->cardType == CARD_TYPE_FRLG && sData->trainerCard.berryCrushPoints)
        ConvertIntToDecimalStringN(sData->textBerryCrushPts, sData->trainerCard.berryCrushPoints, STR_CONV_MODE_RIGHT_ALIGN, 5);
}

static void PrintBerryCrushStringOnCard(u8 slot)
{
    if (sData->cardType == CARD_TYPE_FRLG && sData->trainerCard.berryCrushPoints)
        PrintStatOnBackOfCard(4, gText_BerryCrush, sData->textBerryCrushPts, sTrainerCardStatColors);
}

static void BufferUnionRoomStats(void)
{
    if (sData->cardType == CARD_TYPE_FRLG && sData->trainerCard.unionRoomNum)
        ConvertIntToDecimalStringN(sData->textUnionRoomStats, sData->trainerCard.unionRoomNum, STR_CONV_MODE_RIGHT_ALIGN, 5);
}

static void PrintUnionStringOnCard(u8 slot)
{
    if (sData->cardType == CARD_TYPE_FRLG && sData->trainerCard.unionRoomNum)
        PrintStatOnBackOfCard(3, gText_UnionTradesAndBattles, sData->textUnionRoomStats, sTrainerCardStatColors);
}

static void BufferLinkPokeblocksNum(void)
{
    if (sData->cardType != CARD_TYPE_FRLG && sData->trainerCard.pokeblocksWithFriends)
    {
        ConvertIntToDecimalStringN(gStringVar1, sData->trainerCard.pokeblocksWithFriends, STR_CONV_MODE_RIGHT_ALIGN, 5);
        StringExpandPlaceholders(sData->textNumLinkPokeblocks, gText_NumPokeblocks);
    }
}

static void PrintPokeblockStringOnCard(u8 slot)
{
    if (sData->trainerCard.pokeblocksWithFriends)
        PrintStatOnBackOfCard(slot, gText_PokeblocksWithFriends, sData->textNumLinkPokeblocks, sTrainerCardBackStatColors[sData->cardType == CARD_TYPE_RS]);
}
static void BufferLinkContestNum(void)
{
    if (sData->cardType != CARD_TYPE_FRLG && sData->trainerCard.contestsWithFriends)
        ConvertIntToDecimalStringN(sData->textNumLinkContests, sData->trainerCard.contestsWithFriends, STR_CONV_MODE_RIGHT_ALIGN, 5);
}

static void PrintContestStringOnCard(u8 slot)
{
    if (sData->trainerCard.contestsWithFriends)
        PrintStatOnBackOfCard(slot, sTrainerCardContestTexts[sData->cardType == CARD_TYPE_RS], sData->textNumLinkContests, sTrainerCardBackStatColors[sData->cardType == CARD_TYPE_RS]);
}

static void BufferBattlePoints(void)
{
    if (sData->cardType > CARD_TYPE_RS && sData->trainerCard.frontierBP)
    {
        ConvertIntToDecimalStringN(gStringVar1, sData->trainerCard.frontierBP, STR_CONV_MODE_RIGHT_ALIGN, 5);
        StringExpandPlaceholders(sData->textBattlePoints, gText_NumBP);
    }
}

static void PrintBattlePointsStringOnCard(u8 slot)
{
    if (sData->trainerCard.frontierBP)
        PrintStatOnBackOfCard(slot, gText_BattlePtsWon, sData->textBattlePoints, sTrainerCardStatColors);
}

static void BufferBattleTowerWins(void)
{
    if (sData->cardType == CARD_TYPE_RS && sData->hasBattleTowerWins)
    {
        if (sData->cardType == CARD_TYPE_RS)
        {
            ConvertIntToDecimalStringN(gStringVar1, sData->trainerCard.battleTowerWins, STR_CONV_MODE_RIGHT_ALIGN, 4);
            ConvertIntToDecimalStringN(gStringVar2, sData->trainerCard.battleTowerStraightWins, STR_CONV_MODE_RIGHT_ALIGN, 4);
            StringExpandPlaceholders(sData->textBattleTowerWins, gText_RSCardTowerStats);
        }
        else
        {
            ConvertIntToDecimalStringN(sData->textBattleTowerWins, sData->trainerCard.battleTowerWins, STR_CONV_MODE_RIGHT_ALIGN, 4);
            ConvertIntToDecimalStringN(sData->textBattleTowerStreak, sData->trainerCard.battleTowerStraightWins, STR_CONV_MODE_RIGHT_ALIGN, 4);
        }
    }
}

static void PrintBattleTowerStringOnCard(u8 slot)
{
    if (sData->hasBattleTowerWins)
    {
        if (sData->cardType == CARD_TYPE_RS)
        {
            AddTextPrinterParameterized3(1, sTrainerCardFonts[sData->cardType], 16, slot * 16 + 32, sTrainerCardRSContentColors, TEXT_SPEED_FF, gText_RSBattleTower);
            AddTextPrinterParameterized3(1, sTrainerCardFonts[sData->cardType], 104, slot * 16 + 32, sTrainerCardRSStatColors, TEXT_SPEED_FF, sData->textBattleTowerWins);
        }
        else
        {
            AddTextPrinterParameterized3(1, sTrainerCardFonts[sData->cardType], 10, slot * 16 + 35, sTrainerCardTextColors, TEXT_SPEED_FF, gText_BattleTower);
            AddTextPrinterParameterized3(1, sTrainerCardFonts[sData->cardType], 127, slot * 16 + 35, sTrainerCardTextColors, TEXT_SPEED_FF, gText_WinsStraight);
            AddTextPrinterParameterized3(1, sTrainerCardFonts[sData->cardType], GetStringRightAlignXOffset(sTrainerCardFonts[sData->cardType], sData->textBattleTowerWins, 168), slot * 16 + 35, sTrainerCardStatColors, TEXT_SPEED_FF, sData->textBattleTowerWins);
            AddTextPrinterParameterized3(1, sTrainerCardFonts[sData->cardType], GetStringRightAlignXOffset(sTrainerCardFonts[sData->cardType], sData->textBattleTowerStreak, 216), slot * 16 + 35, sTrainerCardStatColors, TEXT_SPEED_FF, sData->textBattleTowerStreak);
        }
    }
}


static void PrintPokemonIconsOnCard(void)
{
    u8 i;
    u8 paletteSlots[PARTY_SIZE] = {5, 6, 7, 8, 9, 10};
    u8 xOffsets[PARTY_SIZE] = {0, 4, 8, 12, 16, 20};

    if (sData->cardType == CARD_TYPE_CRYSTALDUST || sData->cardType == CARD_TYPE_FRLG)
    {
        for (i = 0; i < PARTY_SIZE; i++)
        {
            if (sData->trainerCard.monSpecies[i])
            {
                u8 monSpecies = GetMonIconPaletteIndexFromSpecies(sData->trainerCard.monSpecies[i]);
                WriteSequenceToBgTilemapBuffer(3, 16 * i + 224, xOffsets[i] + 3, 15, 4, 4, paletteSlots[monSpecies], 1);
            }
        }
    }
}

static void LoadMonIconGfx(void)
{
    u8 i;

    CpuSet(gMonIconPalettes, sData->monIconPal, 0x60);
    switch (sData->trainerCard.monIconTint)
    {
    case MON_ICON_TINT_NORMAL:
        break;
    case MON_ICON_TINT_BLACK:
        TintPalette_CustomTone(sData->monIconPal, 96, 0, 0, 0);
        break;
    case MON_ICON_TINT_PINK:
        TintPalette_CustomTone(sData->monIconPal, 96, 500, 330, 310);
        break;
    case MON_ICON_TINT_SEPIA:
        TintPalette_SepiaTone(sData->monIconPal, 96);
        break;
    }
    LoadPalette(sData->monIconPal, 80, 192);

    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (sData->trainerCard.monSpecies[i])
            LoadBgTiles(3, GetMonIconTiles(sData->trainerCard.monSpecies[i], 0), 512, 16 * i + 32);
    }
}

static void PrintStickersOnCard(void)
{
    u8 i;
    u8 paletteSlots[4] = {11, 12, 13, 14};

    if ((sData->cardType == CARD_TYPE_CRYSTALDUST || sData->cardType == CARD_TYPE_FRLG) && sData->trainerCard.shouldDrawStickers == TRUE)
    {
        for (i = 0; i < TRAINER_CARD_STICKER_TYPES; i++)
        {
            u8 sticker = sData->trainerCard.stickers[i];
            if (sData->trainerCard.stickers[i])
                WriteSequenceToBgTilemapBuffer(3, i * 4 + 320, i * 3 + 2, 2, 2, 2, paletteSlots[sticker - 1], 1);
        }
    }
}

static void LoadStickerGfx(void)
{
    LoadPalette(sTrainerCardSticker1_Pal, 176, 32);
    LoadPalette(sTrainerCardSticker2_Pal, 192, 32);
    LoadPalette(sTrainerCardSticker3_Pal, 208, 32);
    LoadPalette(sTrainerCardSticker4_Pal, 224, 32);
    LoadBgTiles(3, sData->stickerTiles, 1024, 128);
}

static void DrawTrainerCardWindow(u8 windowId)
{
    PutWindowTilemap(windowId);
    CopyWindowToVram(windowId, 3);
}

static u8 SetCardBgsAndPals(void)
{
    switch (sData->bgPalLoadState)
    {
    case 0:
        LoadBgTiles(0, sData->cardTiles, 0x3200, 0);
        break;
    case 1:
        LoadBgTiles(3, sData->badgeTiles, ARRAY_COUNT(sData->badgeTiles), 0x3200);
        break;
    case 2:
        if (sData->cardType == CARD_TYPE_CRYSTALDUST)
        {
            LoadPalette(sJohtoTrainerCardStarPals[sData->trainerCard.stars], 0, 96);
            LoadPalette(sJohtoTrainerCardBadges_Pal, 48, 32);
            if (sData->trainerCard.gender != MALE)
                LoadPalette(sJohtoTrainerCardFemaleBg_Pal, 16, 32);
        }
        else if (sData->cardType == CARD_TYPE_FRLG)
        {
            LoadPalette(sKantoTrainerCardStarPals[sData->trainerCard.stars], 0, 96);
            LoadPalette(sKantoTrainerCardBadges_Pal, 48, 32);
            if (sData->trainerCard.gender != MALE)
                LoadPalette(sKantoTrainerCardFemaleBg_Pal, 16, 32);
        }
        else
        {
            LoadPalette(sHoennTrainerCardStarPals[sData->trainerCard.stars], 0, 96);
            LoadPalette(sHoennTrainerCardBadges_Pal, 48, 32);
            if (sData->trainerCard.gender != MALE)
                LoadPalette(sHoennTrainerCardFemaleBg_Pal, 16, 32);
        }
        LoadPalette(sTrainerCardGold_Pal, 64, 32);
        break;
    case 3:
        SetBgTilemapBuffer(0, sData->cardTilemapBuffer);
        SetBgTilemapBuffer(2, sData->bgTilemapBuffer);
        break;
    case 4:
        FillBgTilemapBufferRect_Palette0(0, 0, 0, 0, 32, 32);
        FillBgTilemapBufferRect_Palette0(2, 0, 0, 0, 32, 32);
        FillBgTilemapBufferRect_Palette0(3, 0, 0, 0, 32, 32);
    default:
        return 1;
    }
    sData->bgPalLoadState++;
    return 0;
}

static void DrawCardScreenBackground(u16 *ptr)
{
    s16 i, j;
    u16 *dst = sData->bgTilemapBuffer;

    for (i = 0; i < 20; i++)
    {
        for (j = 0; j < 32; j++)
        {
            if (j < 30)
                dst[32 * i + j] = ptr[30 * i + j];
            else
                dst[32 * i + j] = ptr[0];
        }
    }
    CopyBgTilemapBufferToVram(2);
}

static void DrawCardFrontOrBack(u16* ptr)
{
    s16 i, j;
    u16 *dst = sData->cardTilemapBuffer;

    for (i = 0; i < 20; i++)
    {
        for (j = 0; j < 32; j++)
        {
            if (j < 30)
                dst[32 * i + j] = ptr[30 * i + j];
            else
                dst[32 * i + j] = ptr[0];
        }
    }
    CopyBgTilemapBufferToVram(0);
}

static void DrawStarsAndBadgesOnCard(void)
{
    static const u8 starYOffsets[] = {7, 6, 7, 7};
    static const u8 badgeYOffsets[] = {16, 15, 16};

    s16 i, x;
    u16 tileNum = 704;
    u8 palNum = 3;

    FillBgTilemapBufferRect(3, 143, 15, starYOffsets[sData->cardType], sData->trainerCard.stars, 1, 4);
    if (!sData->isLink)
    {
        x = 4;
        for (i = 0; i < NUM_BADGES; i++, tileNum += 2, x += 3)
        {
            if (sData->badgeCount[i])
            {
                FillBgTilemapBufferRect(3, tileNum, x, badgeYOffsets[sData->region], 1, 1, palNum);
                FillBgTilemapBufferRect(3, tileNum + 1, x + 1, badgeYOffsets[sData->region], 1, 1, palNum);
                FillBgTilemapBufferRect(3, tileNum + 16, x, badgeYOffsets[sData->region] + 1, 1, 1, palNum);
                FillBgTilemapBufferRect(3, tileNum + 17, x + 1, badgeYOffsets[sData->region] + 1, 1, 1, palNum);
            }
        }
    }
    CopyBgTilemapBufferToVram(3);
}

static void DrawCardBackStats(void)
{
    CopyBgTilemapBufferToVram(3);
}

static void BlinkTimeColon(void)
{
    if (++sData->timeColonBlinkTimer > 60)
    {
        sData->timeColonBlinkTimer = 0;
        sData->timeColonInvisible ^= 1;
        sData->timeColonNeedDraw = TRUE;
    }
}

u8 GetTrainerCardStars(u8 cardId)
{
    struct TrainerCard* trainerCards = gTrainerCards;
    return trainerCards[cardId].stars;
}

#define tFlipState data[0]
#define tCardTop   data[1]

static void FlipTrainerCard(void)
{
    u8 taskId = CreateTask(Task_DoCardFlipTask, 0);
    Task_DoCardFlipTask(taskId);
    SetHBlankCallback(HblankCb_TrainerCard);
}

static bool8 IsCardFlipTaskActive(void)
{
    if (FindTaskIdByFunc(Task_DoCardFlipTask) == TASK_NONE)
        return TRUE;
    else
        return FALSE;
}

static void Task_DoCardFlipTask(u8 taskId)
{
    while(sTrainerCardFlipTasks[gTasks[taskId].tFlipState](&gTasks[taskId]))
        ;
}

static bool8 Task_BeginCardFlip(struct Task* task)
{
    u32 i;

    HideBg(1);
    HideBg(3);
    ScanlineEffect_Stop();
    ScanlineEffect_Clear();
    for (i = 0; i < DISPLAY_HEIGHT; i++)
        gScanlineEffectRegBuffers[1][i] = 0;
    task->tFlipState++;
    return FALSE;
}

// Note: Cannot be DISPLAY_HEIGHT / 2, or cardHeight will be 0
#define CARD_FLIP_Y ((DISPLAY_HEIGHT / 2) - 3)

static bool8 Task_AnimateCardFlipDown(struct Task* task)
{
    u32 cardHeight, r5, r10, cardTop, r6, var_24, cardBottom, var;
    s16 i;

    sData->allowDMACopy = FALSE;
    if (task->tCardTop >= CARD_FLIP_Y)
        task->tCardTop = CARD_FLIP_Y;
    else
        task->tCardTop += 7;

    sData->cardTop = task->tCardTop;
    UpdateCardFlipRegs(task->tCardTop);

    cardTop = task->tCardTop;
    cardBottom = DISPLAY_HEIGHT - cardTop;
    cardHeight = cardBottom - cardTop;
    r6 = -cardTop << 16;
    r5 = (DISPLAY_HEIGHT << 16) / cardHeight;
    r5 -= 1 << 16;
    var_24 = r6;
    var_24 += r5 * cardHeight;
    r10 = r5 / cardHeight;
    r5 *= 2;

    for (i = 0; i < cardTop; i++)
        gScanlineEffectRegBuffers[0][i] = -i;
    for (; i < (s16)cardBottom; i++)
    {
        var = r6 >> 16;
        r6 += r5;
        r5 -= r10;
        gScanlineEffectRegBuffers[0][i] = var;
    }
    var = var_24 >> 16;
    for (; i < DISPLAY_HEIGHT; i++)
        gScanlineEffectRegBuffers[0][i] = var;

    sData->allowDMACopy = TRUE;
    if (task->tCardTop >= CARD_FLIP_Y)
        task->tFlipState++;

    return FALSE;
}

static bool8 Task_DrawFlippedCardSide(struct Task* task)
{
    sData->allowDMACopy = FALSE;
    if (Overworld_LinkRecvQueueLengthMoreThan2() == TRUE)
        return FALSE;

    do
    {
        switch (sData->flipDrawState)
        {
        case 0:
            FillWindowPixelBuffer(1, PIXEL_FILL(0));
            FillBgTilemapBufferRect_Palette0(3, 0, 0, 0, 0x20, 0x20);
            break;
        case 1:
            if (!sData->onBack)
            {
                if (!PrintAllOnCardBack())
                    return FALSE;
            }
            else
            {
                if (!PrintAllOnCardFront())
                    return FALSE;
            }
            break;
        case 2:
            if (!sData->onBack)
                DrawCardFrontOrBack(sData->backTilemap);
            else
                DrawTrainerCardWindow(1);
            break;
        case 3:
            if (!sData->onBack)
                DrawCardBackStats();
            else
                FillWindowPixelBuffer(2, PIXEL_FILL(0));
            break;
        case 4:
            if (sData->onBack)
                CreateTrainerCardTrainerPic();
            break;
        default:
            task->tFlipState++;
            sData->allowDMACopy = TRUE;
            sData->flipDrawState = 0;
            return FALSE;
        }
        sData->flipDrawState++;
    } while (gReceivedRemoteLinkPlayers == 0);

    return FALSE;
}

static bool8 Task_SetCardFlipped(struct Task* task)
{
    sData->allowDMACopy = FALSE;

    // If on back of card, draw front of card because its being flipped
    if (sData->onBack)
    {
        DrawTrainerCardWindow(2);
        DrawCardScreenBackground(sData->bgTilemap);
        DrawCardFrontOrBack(sData->frontTilemap);
        DrawStarsAndBadgesOnCard();
    }
    DrawTrainerCardWindow(1);
    sData->onBack ^= 1;
    task->tFlipState++;
    sData->allowDMACopy = TRUE;
    PlaySE(SE_RG_CARD_FLIPPING);
    return FALSE;
}

static bool8 Task_AnimateCardFlipUp(struct Task* task)
{
    u32 cardHeight, r5, r10, cardTop, r6, var_24, cardBottom, var;
    s16 i;

    sData->allowDMACopy = FALSE;
    if (task->tCardTop <= 5)
        task->tCardTop = 0;
    else
        task->tCardTop -= 5;

    sData->cardTop = task->tCardTop;
    UpdateCardFlipRegs(task->tCardTop);

    cardTop = task->tCardTop;
    cardBottom = DISPLAY_HEIGHT - cardTop;
    cardHeight = cardBottom - cardTop;
    r6 = -cardTop << 16;
    r5 = (DISPLAY_HEIGHT << 16) / cardHeight;
    r5 -= 1 << 16;
    var_24 = r6;
    var_24 += r5 * cardHeight;
    r10 = r5 / cardHeight;
    r5 /= 2;

    for (i = 0; i < cardTop; i++)
        gScanlineEffectRegBuffers[0][i] = -i;
    for (; i < (s16)cardBottom; i++)
    {
        var = r6 >> 16;
        r6 += r5;
        r5 += r10;
        gScanlineEffectRegBuffers[0][i] = var;
    }
    var = var_24 >> 16;
    for (; i < DISPLAY_HEIGHT; i++)
        gScanlineEffectRegBuffers[0][i] = var;

    sData->allowDMACopy = TRUE;
    if (task->tCardTop <= 0)
        task->tFlipState++;

    return FALSE;
}

static bool8 Task_EndCardFlip(struct Task *task)
{
    ShowBg(1);
    ShowBg(3);
    SetHBlankCallback(NULL);
    DestroyTask(FindTaskIdByFunc(Task_DoCardFlipTask));
    return FALSE;
}

void ShowPlayerTrainerCard(void (*callback)(void))
{
    sData = AllocZeroed(sizeof(*sData));
    sData->callback2 = callback;
    if (callback == CB2_ReshowFrontierPass)
        sData->blendColor = RGB_WHITE;
    else
        sData->blendColor = RGB_BLACK;

    if (InUnionRoom() == TRUE)
        sData->isLink = TRUE;
    else
        sData->isLink = FALSE;

    sData->language = GAME_LANGUAGE;
    TrainerCard_GenerateCardToShowLocally(&sData->trainerCard);
    SetMainCallback2(CB2_InitTrainerCard);
}

void ShowTrainerCardInLink(u8 cardId, void (*callback)(void))
{
    sData = AllocZeroed(sizeof(*sData));
    sData->callback2 = callback;
    sData->isLink = TRUE;
    sData->trainerCard = gTrainerCards[cardId];
    sData->language = gLinkPlayers[cardId].language;
    SetMainCallback2(CB2_InitTrainerCard);
}

static void InitTrainerCardData(void)
{
    u8 i;

    sData->mainState = 0;
    sData->timeColonBlinkTimer = gSaveBlock2Ptr->playTimeVBlanks;
    sData->timeColonInvisible = FALSE;
    sData->onBack = FALSE;
    sData->flipBlendY = 0;
    sData->cardType = GetSetCardType();
    GetSetCardStats();
    for (i = 0; i < TRAINER_CARD_PROFILE_LENGTH; i++)
        CopyEasyChatWord(sData->easyChatProfile[i], sData->trainerCard.easyChatProfile[i]);
}

static u8 GetSetCardType(void)
{
    if (sData == NULL)
    {
        if (gGameVersion == VERSION_CRYSTAL_DUST)
            return CARD_TYPE_CRYSTALDUST;
        else if (gGameVersion == VERSION_FIRE_RED || gGameVersion == VERSION_LEAF_GREEN)
            return CARD_TYPE_FRLG;
        else if (gGameVersion == VERSION_EMERALD)
            return CARD_TYPE_EMERALD;
        else
            return CARD_TYPE_RS;
    }
    else
    {
        if (sData->trainerCard.version == VERSION_CRYSTAL_DUST)
        {
            sData->region = CARD_REGION_JOHTO;
            return CARD_TYPE_CRYSTALDUST;
        }
        else if (sData->trainerCard.version == VERSION_FIRE_RED || sData->trainerCard.version == VERSION_LEAF_GREEN)
        {
            sData->region = CARD_REGION_KANTO;
            return CARD_TYPE_FRLG;
        }
        else if (sData->trainerCard.version == VERSION_EMERALD)
        {
            sData->region = CARD_REGION_HOENN;
            return CARD_TYPE_EMERALD;
        }
        else
        {
            sData->region = CARD_REGION_HOENN;
            return CARD_TYPE_RS;
        }
    }
}

static u8 VersionToCardType(u8 version)
{
    if (version == VERSION_CRYSTAL_DUST)
        return CARD_TYPE_CRYSTALDUST;
    else if (version == VERSION_FIRE_RED || version == VERSION_LEAF_GREEN)
        return CARD_TYPE_FRLG;
    else if (version == VERSION_EMERALD)
        return CARD_TYPE_EMERALD;
    else
        return CARD_TYPE_RS;
}

static u8 GetSetCardStats(void)
{
    {
        sData->stats[0] = CARD_STAT_HOF_DEBUT;
        sData->stats[1] = CARD_STAT_LINK_BATTLES;
        sData->stats[2] = CARD_STAT_TRADES;
        sData->stats[3] = sTrainerCardStats[sData->cardType][0];
        sData->stats[4] = sTrainerCardStats[sData->cardType][1];
        sData->stats[5] = sTrainerCardStats[sData->cardType][2];
    }
}

static void CreateTrainerCardTrainerPic(void)
{
    if (InUnionRoom() == TRUE && gReceivedRemoteLinkPlayers == 1)
    {
        CreateTrainerCardTrainerPicSprite(FacilityClassToPicIndex(sData->trainerCard.facilityClass),
                    TRUE,
                    sTrainerPicOffset[sData->region][sData->trainerCard.gender][0],
                    sTrainerPicOffset[sData->region][sData->trainerCard.gender][1],
                    8,
                    2);
    }
    else
    {
        CreateTrainerCardTrainerPicSprite(FacilityClassToPicIndex(sTrainerPicFacilityClass[sData->cardType][sData->trainerCard.gender]),
                    TRUE,
                    sTrainerPicOffset[sData->region][sData->trainerCard.gender][0],
                    sTrainerPicOffset[sData->region][sData->trainerCard.gender][1],
                    8,
                    2);
    }
}
