#include "global.h"
#include "malloc.h"
#include "bg.h"
#include "card_flip.h"
#include "coins.h"
#include "decompress.h"
#include "event_data.h"
#include "gpu_regs.h"
#include "international_string_util.h"
#include "main.h"
#include "main_menu.h"
#include "menu.h"
#include "menu_helpers.h"
#include "overworld.h"
#include "palette.h"
#include "pokemon_icon.h"
#include "scanline_effect.h"
#include "script.h"
#include "sound.h"
#include "sprite.h"
#include "string_util.h"
#include "random.h"
#include "task.h"
#include "text.h"
#include "text_window.h"
#include "window.h"
#include "constants/rgb.h"
#include "constants/songs.h"
#include "constants/species.h"

// In order to invoke the Card Flip game, it should be launched via a normal script like the example below.
// The number of coins required to play each round is specified by VAR_0x8004.
//
// ...
// setvar VAR_0x8004, 3
// callnative PlayCardFlip
// waitstate
// ...


#define CARD_FLIP_BG_TEXT        0
#define CARD_FLIP_BG_BET_OUTLINE 1
#define CARD_FLIP_BG_BASE        2

#define WIN_TEXT 0
#define WIN_HELP 1

#define TAG_COIN_DIGIT          500
#define TAG_CARD_NUMBER         501
#define TAG_CARD_FRONT              502
#define TAG_CARD_2              503
#define TAG_CARD_BACK           504
#define TAG_CARD_SELECTION      505
#define TAG_BET_OUTLINE_HORIZONTAL 506
#define TAG_BET_OUTLINE_VERTICAL   507
#define TAG_BET_OUTLINE_VERTICAL_SMALL 508
#define TAG_ROUND_COUNTERS      509

#define NUM_NUMBERS 6
#define NUM_SUITS 4
#define NUM_CARDS (NUM_NUMBERS * NUM_SUITS)
#define CARD(n, suit) (((suit & 0x3) << 5) | (n & 0x1F))
#define CARD_ID(card) (CARD_NUMBER((card)) + (CARD_SUIT((card))) * NUM_NUMBERS)
#define CARD_NUMBER(n) ((n) & 0x1F)
#define CARD_SUIT(n) (((n) & 0x60) >> 5)

enum
{
    CARD_FLIP_STATE_INIT,
    CARD_FLIP_STATE_PLAY_MESSAGE,
    CARD_FLIP_STATE_PLAY_PROMPT,
    CARD_FLIP_STATE_PLAY_PROMPT_GET_INPUT,
    CARD_FLIP_STATE_PLAY_DEAL_CARDS,
    CARD_FLIP_STATE_CHOOSE_CARD,
    CARD_FLIP_STATE_PLACE_BET,
    CARD_FLIP_STATE_REVEAL_CARD,
    CARD_FLIP_STATE_DISPLAY_OUTCOME_MESSAGE,
    CARD_FLIP_STATE_DISPLAY_OUTCOME_MESSAGE_INPUT,
    CARD_FLIP_STATE_PLAY_AGAIN_MESSAGE,
    CARD_FLIP_STATE_PLAY_AGAIN_PROMPT,
    CARD_FLIP_STATE_PLAY_AGAIN_PROMPT_INPUT,
    CARD_FLIP_STATE_SHUFFLE_DECK_MESSAGE,
    CARD_FLIP_STATE_SHUFFLE_DECK_INPUT,
    CARD_FLIP_NOT_ENOUGH_COINS,
    CARD_FLIP_NOT_ENOUGH_COINS_INPUT,
    CARD_FLIP_STATE_START_EXIT,
    CARD_FLIP_STATE_EXIT,
    CARD_FLIP_WAIT_ANIM,
};

enum
{
    BET_TYPE_PIKACHU_1,
    BET_TYPE_PIKACHU_2,
    BET_TYPE_PIKACHU_3,
    BET_TYPE_PIKACHU_4,
    BET_TYPE_PIKACHU_5,
    BET_TYPE_PIKACHU_6,
    BET_TYPE_JIGGLYPUFF_1,
    BET_TYPE_JIGGLYPUFF_2,
    BET_TYPE_JIGGLYPUFF_3,
    BET_TYPE_JIGGLYPUFF_4,
    BET_TYPE_JIGGLYPUFF_5,
    BET_TYPE_JIGGLYPUFF_6,
    BET_TYPE_POLIWAG_1,
    BET_TYPE_POLIWAG_2,
    BET_TYPE_POLIWAG_3,
    BET_TYPE_POLIWAG_4,
    BET_TYPE_POLIWAG_5,
    BET_TYPE_POLIWAG_6,
    BET_TYPE_ODDISH_1,
    BET_TYPE_ODDISH_2,
    BET_TYPE_ODDISH_3,
    BET_TYPE_ODDISH_4,
    BET_TYPE_ODDISH_5,
    BET_TYPE_ODDISH_6,
    BET_TYPE_PIKACHU,
    BET_TYPE_JIGGLYPUFF,
    BET_TYPE_POLIWAG,
    BET_TYPE_ODDISH,
    BET_TYPE_LEVEL_1,
    BET_TYPE_LEVEL_2,
    BET_TYPE_LEVEL_3,
    BET_TYPE_LEVEL_4,
    BET_TYPE_LEVEL_5,
    BET_TYPE_LEVEL_6,
    BET_TYPE_PIKACHU_JIGGLYPUFF,
    BET_TYPE_POLIWAG_ODDISH,
    BET_TYPE_LEVEL_1_2,
    BET_TYPE_LEVEL_3_4,
    BET_TYPE_LEVEL_5_6,
};

struct CardFlip
{
    u8 state;
    u8 numCoinsEntry;
    u8 coinDigitSpriteIds[4];
    u8 suitSpriteIds[NUM_SUITS];
    u8 cardNumberSpriteIds[NUM_CARDS];
    u8 cardDeck[NUM_CARDS];
    u8 deckTop;
    u8 cardBackSpriteIds[2];
    u8 cardFrontSpriteId;
    u8 selectedCardIndex;
    u8 drawnCard;
    u8 betType;
    u8 betOutlineSpriteIds[16];
    u8 roundCounterSpriteIds[12];
    u8 cardSelectionSoundTaskId;
    MainCallback returnMainCallback;
};

struct BetOutlinePosition
{
    u8 type;
    u8 x;
    u8 y;
};

static void FadeToCardFlipScreen(u8 taskId);
static void InitCardFlipScreen(void);
static void CardFlipMainCallback(void);
static void CardFlipVBlankCallback(void);
static void InitCoinDigitSprites(void);
static void InitMonIcons(void);
static void InitCardNumberSprites(void);
static void InitRoundCounterSprites(void);
static void CardFlipMain(u8 taskId);
static void InitCardFlipTable(u8 taskId);
static void DisplayInitialPlayMessage(void);
static void DisplayInitialPlayPrompt();
static void ProcessPlayPromptInput(void);
static void PlaceBet(void);
static bool8 IsValidBetType(u8 betType);
static void DrawBetType(u8 betType);
static void RevealCard(u8 taskId);
static void DisplayBetOutcomeMessage(void);
static void DisplayBetOutcomeMessage_WaitButtonPress(void);
static void AwardCoins(void);
static void PlayAgainMessage(void);
static void PlayAgainPrompt(void);
static void ProcessPlayAgainPromptInput(u8 taskId);
static void ShuffleDeckMessage(void);
static void ProcessShuffleDeckInput(void);
static void DisplayNotEnoughCoinsMessage(void);
static void ProcessNotEnoughCoinsInput(void);
static void DealCards(u8 taskId);
static void ChooseCard(u8 taskId);
static void ChangeCoinAmount(int delta, int startDelay);
static void ChangeCoinAmountFixedDuration(int delta, int duration, int startDelay);
static void UpdateCoinDigitSprites(u8 taskId);
static void StartExitCardFlip(void);
static void ExitCardFlip(void);
static void ResetAndShuffleCardDeck(void);
static void StartUIAnim(u8 taskId, s16 nextState);
static void WaitForUIAnimToFinish(u8 taskId);
static void RemoveCardNumberFromBoard(int cardId);
static void ShowAllCardNumbers(void);
static void ResetAllRoundCounters(void);
static void LoadCardBackGfx(void);
static void LoadCardSelectionGfx(void);
static void LoadCardGfx(int cardId);
static void CardEntry_SpriteCallback(struct Sprite *sprite);
static void ChooseCard_SpriteCallback(struct Sprite *sprite);
static void SlideBottomCardUp(struct Sprite *sprite);
static void SlideOutCard(struct Sprite *sprite);
static void FlipOverCardStart(struct Sprite *sprite);
static void FlipOverCardEnd(struct Sprite *sprite);
static void ShowHelpBar(const u8 *str);
static void HighlightCardNumber(struct Sprite *sprite);

static EWRAM_DATA struct CardFlip *sCardFlip = NULL;

static const u8 sPlayTheGamePromptText[] = _("Play CARD FLIP for {STR_VAR_1} COINS?");
static const u8 sYeahText[] = _("Yeah!");
static const u8 sDarnText[] = _("Darn…");
static const u8 sPlayAgainText[] = _("Want to play again?");
static const u8 sShuffledCardsText[] = _("The cards have been shuffled.");
static const u8 sNotEnoughCoinsText[] = _("You don't have enough COINS to\nplay.");
static const u8 sHelpBar_Select[] = _("{A_BUTTON}SELECT");
static const u8 sHelpBar_SelectExit[] = _("{A_BUTTON}SELECT {B_BUTTON}EXIT");
static const u8 sHelpBar_MoveSelect[] = _("{DPAD_ALL}MOVE {A_BUTTON}SELECT");
static const u8 sHelpBar_BetPlace[] = _("{DPAD_ALL}BET {A_BUTTON}PLACE");
static const u8 sHelpBar_Next[] = _("{A_BUTTON}NEXT");

static const u32 sCardFlipBaseBgGfx[] = INCBIN_U32("graphics/card_flip/card_flip_base_bg_tiles.4bpp.lz");
static const u16 sCardFlipBaseBgPalette[] = INCBIN_U16("graphics/card_flip/card_flip_base_bg_tiles.gbapal");
static const u32 sCardFlipBaseBgTilemap[] = INCBIN_U32("graphics/card_flip/card_flip_base_bg_tilemap.bin.lz");
static const u32 sCoinDigitsGfx[] = INCBIN_U32("graphics/card_flip/coin_digits.4bpp.lz");
static const u16 sCoinDigitsPalette[] = INCBIN_U16("graphics/card_flip/coin_digits.gbapal");
static const u32 sCardNumbersGfx[] = INCBIN_U32("graphics/card_flip/card_numbers.4bpp.lz");
static const u16 sCardNumbersPalette[] = INCBIN_U16("graphics/card_flip/card_numbers.gbapal");

static const u32 sCard_Pikachu1Gfx[] = INCBIN_U32("graphics/card_flip/pikachu_1.4bpp.lz");
static const u16 sCard_Pikachu1Palette[] = INCBIN_U16("graphics/card_flip/pikachu_1.gbapal");
static const u32 sCard_Pikachu2Gfx[] = INCBIN_U32("graphics/card_flip/pikachu_2.4bpp.lz");
static const u16 sCard_Pikachu2Palette[] = INCBIN_U16("graphics/card_flip/pikachu_2.gbapal");
static const u32 sCard_Pikachu3Gfx[] = INCBIN_U32("graphics/card_flip/pikachu_3.4bpp.lz");
static const u16 sCard_Pikachu3Palette[] = INCBIN_U16("graphics/card_flip/pikachu_3.gbapal");
static const u32 sCard_Pikachu4Gfx[] = INCBIN_U32("graphics/card_flip/pikachu_4.4bpp.lz");
static const u16 sCard_Pikachu4Palette[] = INCBIN_U16("graphics/card_flip/pikachu_4.gbapal");
static const u32 sCard_Pikachu5Gfx[] = INCBIN_U32("graphics/card_flip/pikachu_5.4bpp.lz");
static const u16 sCard_Pikachu5Palette[] = INCBIN_U16("graphics/card_flip/pikachu_5.gbapal");
static const u32 sCard_Pikachu6Gfx[] = INCBIN_U32("graphics/card_flip/pikachu_6.4bpp.lz");
static const u16 sCard_Pikachu6Palette[] = INCBIN_U16("graphics/card_flip/pikachu_6.gbapal");
static const u32 sCard_JigglyPuff1Gfx[] = INCBIN_U32("graphics/card_flip/jigglypuff_1.4bpp.lz");
static const u16 sCard_JigglyPuff1Palette[] = INCBIN_U16("graphics/card_flip/jigglypuff_1.gbapal");
static const u32 sCard_JigglyPuff2Gfx[] = INCBIN_U32("graphics/card_flip/jigglypuff_2.4bpp.lz");
static const u16 sCard_JigglyPuff2Palette[] = INCBIN_U16("graphics/card_flip/jigglypuff_2.gbapal");
static const u32 sCard_JigglyPuff3Gfx[] = INCBIN_U32("graphics/card_flip/jigglypuff_3.4bpp.lz");
static const u16 sCard_JigglyPuff3Palette[] = INCBIN_U16("graphics/card_flip/jigglypuff_3.gbapal");
static const u32 sCard_JigglyPuff4Gfx[] = INCBIN_U32("graphics/card_flip/jigglypuff_4.4bpp.lz");
static const u16 sCard_JigglyPuff4Palette[] = INCBIN_U16("graphics/card_flip/jigglypuff_4.gbapal");
static const u32 sCard_JigglyPuff5Gfx[] = INCBIN_U32("graphics/card_flip/jigglypuff_5.4bpp.lz");
static const u16 sCard_JigglyPuff5Palette[] = INCBIN_U16("graphics/card_flip/jigglypuff_5.gbapal");
static const u32 sCard_JigglyPuff6Gfx[] = INCBIN_U32("graphics/card_flip/jigglypuff_6.4bpp.lz");
static const u16 sCard_JigglyPuff6Palette[] = INCBIN_U16("graphics/card_flip/jigglypuff_6.gbapal");
static const u32 sCard_Poliwag1Gfx[] = INCBIN_U32("graphics/card_flip/poliwag_1.4bpp.lz");
static const u16 sCard_Poliwag1Palette[] = INCBIN_U16("graphics/card_flip/poliwag_1.gbapal");
static const u32 sCard_Poliwag2Gfx[] = INCBIN_U32("graphics/card_flip/poliwag_2.4bpp.lz");
static const u16 sCard_Poliwag2Palette[] = INCBIN_U16("graphics/card_flip/poliwag_2.gbapal");
static const u32 sCard_Poliwag3Gfx[] = INCBIN_U32("graphics/card_flip/poliwag_3.4bpp.lz");
static const u16 sCard_Poliwag3Palette[] = INCBIN_U16("graphics/card_flip/poliwag_3.gbapal");
static const u32 sCard_Poliwag4Gfx[] = INCBIN_U32("graphics/card_flip/poliwag_4.4bpp.lz");
static const u16 sCard_Poliwag4Palette[] = INCBIN_U16("graphics/card_flip/poliwag_4.gbapal");
static const u32 sCard_Poliwag5Gfx[] = INCBIN_U32("graphics/card_flip/poliwag_5.4bpp.lz");
static const u16 sCard_Poliwag5Palette[] = INCBIN_U16("graphics/card_flip/poliwag_5.gbapal");
static const u32 sCard_Poliwag6Gfx[] = INCBIN_U32("graphics/card_flip/poliwag_6.4bpp.lz");
static const u16 sCard_Poliwag6Palette[] = INCBIN_U16("graphics/card_flip/poliwag_6.gbapal");
static const u32 sCard_Oddish1Gfx[] = INCBIN_U32("graphics/card_flip/oddish_1.4bpp.lz");
static const u16 sCard_Oddish1Palette[] = INCBIN_U16("graphics/card_flip/oddish_1.gbapal");
static const u32 sCard_Oddish2Gfx[] = INCBIN_U32("graphics/card_flip/oddish_2.4bpp.lz");
static const u16 sCard_Oddish2Palette[] = INCBIN_U16("graphics/card_flip/oddish_2.gbapal");
static const u32 sCard_Oddish3Gfx[] = INCBIN_U32("graphics/card_flip/oddish_3.4bpp.lz");
static const u16 sCard_Oddish3Palette[] = INCBIN_U16("graphics/card_flip/oddish_3.gbapal");
static const u32 sCard_Oddish4Gfx[] = INCBIN_U32("graphics/card_flip/oddish_4.4bpp.lz");
static const u16 sCard_Oddish4Palette[] = INCBIN_U16("graphics/card_flip/oddish_4.gbapal");
static const u32 sCard_Oddish5Gfx[] = INCBIN_U32("graphics/card_flip/oddish_5.4bpp.lz");
static const u16 sCard_Oddish5Palette[] = INCBIN_U16("graphics/card_flip/oddish_5.gbapal");
static const u32 sCard_Oddish6Gfx[] = INCBIN_U32("graphics/card_flip/oddish_6.4bpp.lz");
static const u16 sCard_Oddish6Palette[] = INCBIN_U16("graphics/card_flip/oddish_6.gbapal");

static const u32 sCardBackGfx[] = INCBIN_U32("graphics/card_flip/card_back.4bpp.lz");
static const u16 sCardBackPalette[] = INCBIN_U16("graphics/card_flip/card_back.gbapal");
static const u32 sCard_SelectionGfx[] = INCBIN_U32("graphics/card_flip/card_selection.4bpp.lz");
static const u16 sCard_SelectionPalette[] = INCBIN_U16("graphics/card_flip/card_selection.gbapal");

static const u32 sBetOutlineHorizontalGfx[] = INCBIN_U32("graphics/card_flip/bet_outline_horizontal.4bpp.lz");
static const u32 sBetOutlineVerticalGfx[] = INCBIN_U32("graphics/card_flip/bet_outline_vertical.4bpp.lz");
static const u32 sBetOutlineVerticalSmallGfx[] = INCBIN_U32("graphics/card_flip/bet_outline_vertical_small.4bpp.lz");
static const u16 sBetOutlineHorizontalPalette[] = INCBIN_U16("graphics/card_flip/bet_outline_horizontal.gbapal");
static const u16 sBetOutlineVerticalPalette[] = INCBIN_U16("graphics/card_flip/bet_outline_vertical.gbapal");
static const u16 sBetOutlineVerticalSmallPalette[] = INCBIN_U16("graphics/card_flip/bet_outline_vertical_small.gbapal");

static const u32 sRoundCountersGfx[] = INCBIN_U32("graphics/card_flip/round_counters.4bpp.lz");
static const u16 sRoundCountersPalette[] = INCBIN_U16("graphics/card_flip/round_counters.gbapal");

static const struct WindowTemplate sCardFlipWinTemplates[] = {
    {
        .bg = CARD_FLIP_BG_TEXT,
        .tilemapLeft = 2,
        .tilemapTop = 15,
        .width = 26,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 0x14,
    },
    {
        .bg = CARD_FLIP_BG_TEXT,
        .tilemapLeft = 15,
        .tilemapTop = 0,
        .width = 15,
        .height = 2,
        .paletteNum = 11,
        .baseBlock = 0x117,
    },
    DUMMY_WIN_TEMPLATE,
};

static const struct BgTemplate sCardFlipBgTemplates[] = {
    {
       .bg = CARD_FLIP_BG_TEXT,
       .charBaseIndex = 2,
       .mapBaseIndex = 31,
       .screenSize = 0,
       .paletteMode = 0,
       .priority = 0,
       .baseTile = 0
   },
   {
       .bg = CARD_FLIP_BG_BET_OUTLINE,
       .charBaseIndex = 1,
       .mapBaseIndex = 29,
       .screenSize = 0,
       .paletteMode = 0,
       .priority = 1,
       .baseTile = 0
   },
   {
       .bg = CARD_FLIP_BG_BASE,
       .charBaseIndex = 0,
       .mapBaseIndex = 30,
       .screenSize = 0,
       .paletteMode = 0,
       .priority = 2,
       .baseTile = 0
   }
};

static const struct CompressedSpriteSheet sCoinDigitsSpriteSheet = {
    .data = sCoinDigitsGfx,
    .size = 0x280,
    .tag = TAG_COIN_DIGIT,
};

static const struct CompressedSpriteSheet sCardNumbersSpriteSheet = {
    .data = sCardNumbersGfx,
    .size = 0x180,
    .tag = TAG_CARD_NUMBER,
};

static const struct OamData sCoinDigitOamData = {
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = 0,
    .bpp = ST_OAM_4BPP,
    .shape = ST_OAM_V_RECTANGLE,
    .x = 0,
    .matrixNum = 0,
    .size = 0,
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0,
};

#define COIN_DIGIT_ANIMCMD(n) \
static const union AnimCmd sCoinDigitAnimCmd_##n[] =\
{\
    ANIMCMD_FRAME((n) * 2, 0),\
    ANIMCMD_END,\
};

COIN_DIGIT_ANIMCMD(0)
COIN_DIGIT_ANIMCMD(1)
COIN_DIGIT_ANIMCMD(2)
COIN_DIGIT_ANIMCMD(3)
COIN_DIGIT_ANIMCMD(4)
COIN_DIGIT_ANIMCMD(5)
COIN_DIGIT_ANIMCMD(6)
COIN_DIGIT_ANIMCMD(7)
COIN_DIGIT_ANIMCMD(8)
COIN_DIGIT_ANIMCMD(9)

static const union AnimCmd *const sCoinDigitAnimCmds[] = {
    sCoinDigitAnimCmd_0,
    sCoinDigitAnimCmd_1,
    sCoinDigitAnimCmd_2,
    sCoinDigitAnimCmd_3,
    sCoinDigitAnimCmd_4,
    sCoinDigitAnimCmd_5,
    sCoinDigitAnimCmd_6,
    sCoinDigitAnimCmd_7,
    sCoinDigitAnimCmd_8,
    sCoinDigitAnimCmd_9,
};

static const struct SpriteTemplate sCoinDigitSpriteTemplate = {
    .tileTag = TAG_COIN_DIGIT,
    .paletteTag = TAG_COIN_DIGIT,
    .oam = &sCoinDigitOamData,
    .anims = sCoinDigitAnimCmds,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

#define CARD_NUMBER_ANIMCMD(n) \
static const union AnimCmd sCardNumberAnimCmd_##n[] =\
{\
    ANIMCMD_FRAME((n) * 2, 1),\
    ANIMCMD_END,\
};

CARD_NUMBER_ANIMCMD(0)
CARD_NUMBER_ANIMCMD(1)
CARD_NUMBER_ANIMCMD(2)
CARD_NUMBER_ANIMCMD(3)
CARD_NUMBER_ANIMCMD(4)
CARD_NUMBER_ANIMCMD(5)

static const union AnimCmd *const sCardNumberAnimCmds[] = {
    sCardNumberAnimCmd_0,
    sCardNumberAnimCmd_1,
    sCardNumberAnimCmd_2,
    sCardNumberAnimCmd_3,
    sCardNumberAnimCmd_4,
    sCardNumberAnimCmd_5,
};

const union AffineAnimCmd sCardNumberHighlight_AffineAnimCmd0[] = {
    AFFINEANIMCMD_FRAME(30, 30, 0, 10),
    AFFINEANIMCMD_FRAME(-30, -30, 0, 10),
    AFFINEANIMCMD_JUMP(0),
};

static const union AffineAnimCmd *const sCardNumberHighlight_AffineAnimCmds[] = {
    sCardNumberHighlight_AffineAnimCmd0,
};

static const struct SpriteTemplate sCardNumberSpriteTemplate = {
    .tileTag = TAG_CARD_NUMBER,
    .paletteTag = TAG_CARD_NUMBER,
    .oam = &sCoinDigitOamData,
    .anims = sCardNumberAnimCmds,
    .images = NULL,
    .affineAnims = sCardNumberHighlight_AffineAnimCmds,
    .callback = SpriteCallbackDummy,
};

static const struct OamData sRoundCounterOamData = {
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = 0,
    .bpp = ST_OAM_4BPP,
    .shape = ST_OAM_SQUARE,
    .x = 0,
    .matrixNum = 0,
    .size = 0,
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0,
};

static const union AnimCmd sRoundCounterAnimCmd_0[] = {
    ANIMCMD_FRAME(0, 0),
    ANIMCMD_END,
};

static const union AnimCmd sRoundCounterAnimCmd_1[] = {
    ANIMCMD_FRAME(1, 0),
    ANIMCMD_END,
};

static const union AnimCmd *const sRoundCounterAnimCmds[] = {
    sRoundCounterAnimCmd_0,
    sRoundCounterAnimCmd_1,
};

static const struct SpriteTemplate sRoundCounterSpriteTemplate = {
    .tileTag = TAG_ROUND_COUNTERS,
    .paletteTag = TAG_ROUND_COUNTERS,
    .oam = &sRoundCounterOamData,
    .anims = sRoundCounterAnimCmds,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const u32 *const sCardSpriteGfx[] = {
    sCard_Pikachu1Gfx,
    sCard_Pikachu2Gfx,
    sCard_Pikachu3Gfx,
    sCard_Pikachu4Gfx,
    sCard_Pikachu5Gfx,
    sCard_Pikachu6Gfx,
    sCard_JigglyPuff1Gfx,
    sCard_JigglyPuff2Gfx,
    sCard_JigglyPuff3Gfx,
    sCard_JigglyPuff4Gfx,
    sCard_JigglyPuff5Gfx,
    sCard_JigglyPuff6Gfx,
    sCard_Poliwag1Gfx,
    sCard_Poliwag2Gfx,
    sCard_Poliwag3Gfx,
    sCard_Poliwag4Gfx,
    sCard_Poliwag5Gfx,
    sCard_Poliwag6Gfx,
    sCard_Oddish1Gfx,
    sCard_Oddish2Gfx,
    sCard_Oddish3Gfx,
    sCard_Oddish4Gfx,
    sCard_Oddish5Gfx,
    sCard_Oddish6Gfx,
};

static const u16 *const sCardSpritePalettes[] = {
    sCard_Pikachu1Palette,
    sCard_Pikachu2Palette,
    sCard_Pikachu3Palette,
    sCard_Pikachu4Palette,
    sCard_Pikachu5Palette,
    sCard_Pikachu6Palette,
    sCard_JigglyPuff1Palette,
    sCard_JigglyPuff2Palette,
    sCard_JigglyPuff3Palette,
    sCard_JigglyPuff4Palette,
    sCard_JigglyPuff5Palette,
    sCard_JigglyPuff6Palette,
    sCard_Poliwag1Palette,
    sCard_Poliwag2Palette,
    sCard_Poliwag3Palette,
    sCard_Poliwag4Palette,
    sCard_Poliwag5Palette,
    sCard_Poliwag6Palette,
    sCard_Oddish1Palette,
    sCard_Oddish2Palette,
    sCard_Oddish3Palette,
    sCard_Oddish4Palette,
    sCard_Oddish5Palette,
    sCard_Oddish6Palette,
};

static const struct OamData sCardOamData = {
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = 0,
    .bpp = ST_OAM_4BPP,
    .shape = ST_OAM_SQUARE,
    .x = 0,
    .matrixNum = 0,
    .size = 3,
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0,
};

static const struct SpriteTemplate sCardSelectionSpriteTemplate = {
    .tileTag = TAG_CARD_SELECTION,
    .paletteTag = TAG_CARD_SELECTION,
    .oam = &sCardOamData,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = ChooseCard_SpriteCallback,
};

const union AffineAnimCmd sCardFlipOver_AffineAnimCmd0[] = {
    AFFINEANIMCMD_FRAME(-10, 0, 0, 1),
    AFFINEANIMCMD_FRAME(-10, 0, 0, 1),
    AFFINEANIMCMD_FRAME(-10, 1, 0, 1),
    AFFINEANIMCMD_FRAME(-20, 2, 0, 1),
    AFFINEANIMCMD_FRAME(-20, 2, 0, 1),
    AFFINEANIMCMD_FRAME(-20, 3, 0, 1),
    AFFINEANIMCMD_FRAME(-30, 3, 0, 1),
    AFFINEANIMCMD_FRAME(-30, 4, 0, 1),
    AFFINEANIMCMD_FRAME(-30, 4, 0, 1),
    AFFINEANIMCMD_FRAME(-70, 5, 0, 1),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd sCardFlipOver_AffineAnimCmd1[] = {
    AFFINEANIMCMD_FRAME(6, 0x118, 0, 0),
    AFFINEANIMCMD_FRAME(70, -5, 0, 1),
    AFFINEANIMCMD_FRAME(30, -4, 0, 1),
    AFFINEANIMCMD_FRAME(30, -4, 0, 1),
    AFFINEANIMCMD_FRAME(30, -3, 0, 1),
    AFFINEANIMCMD_FRAME(20, -3, 0, 1),
    AFFINEANIMCMD_FRAME(20, -2, 0, 1),
    AFFINEANIMCMD_FRAME(20, -2, 0, 1),
    AFFINEANIMCMD_FRAME(10, -1, 0, 1),
    AFFINEANIMCMD_FRAME(10, 0, 0, 1),
    AFFINEANIMCMD_FRAME(10, 0, 0, 1),
    AFFINEANIMCMD_FRAME(0x100, 0x100, 0, 0),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd *const sCardFlipOver_AffineAnimCmds[] = {
    sCardFlipOver_AffineAnimCmd0,
    sCardFlipOver_AffineAnimCmd1,
};

static const struct SpriteTemplate sCardBackSpriteTemplate = {
    .tileTag = TAG_CARD_BACK,
    .paletteTag = TAG_CARD_BACK,
    .oam = &sCardOamData,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = sCardFlipOver_AffineAnimCmds,
    .callback = CardEntry_SpriteCallback,
};

static const struct SpriteTemplate sCardFrontSpriteTemplate = {
    .tileTag = TAG_CARD_FRONT,
    .paletteTag = TAG_CARD_FRONT,
    .oam = &sCardOamData,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = sCardFlipOver_AffineAnimCmds,
    .callback = SpriteCallbackDummy,
};

// UP, RIGHT, DOWN, LEFT
static const u8 sBetTypeInputTransitions[][4] = {
    {BET_TYPE_PIKACHU, BET_TYPE_JIGGLYPUFF_1, BET_TYPE_PIKACHU_2, BET_TYPE_LEVEL_1},          // BET_TYPE_PIKACHU_1
    {BET_TYPE_PIKACHU_1, BET_TYPE_JIGGLYPUFF_2, BET_TYPE_PIKACHU_3, BET_TYPE_LEVEL_2},        // BET_TYPE_PIKACHU_2
    {BET_TYPE_PIKACHU_2, BET_TYPE_JIGGLYPUFF_3, BET_TYPE_PIKACHU_4, BET_TYPE_LEVEL_3},        // BET_TYPE_PIKACHU_3
    {BET_TYPE_PIKACHU_3, BET_TYPE_JIGGLYPUFF_4, BET_TYPE_PIKACHU_5, BET_TYPE_LEVEL_4},        // BET_TYPE_PIKACHU_4
    {BET_TYPE_PIKACHU_4, BET_TYPE_JIGGLYPUFF_5, BET_TYPE_PIKACHU_6, BET_TYPE_LEVEL_5},        // BET_TYPE_PIKACHU_5
    {BET_TYPE_PIKACHU_5, BET_TYPE_JIGGLYPUFF_6, 0xFF, BET_TYPE_LEVEL_6},                      // BET_TYPE_PIKACHU_6
    {BET_TYPE_JIGGLYPUFF, BET_TYPE_POLIWAG_1, BET_TYPE_JIGGLYPUFF_2, BET_TYPE_PIKACHU_1},     // BET_TYPE_JIGGLYPUFF_1
    {BET_TYPE_JIGGLYPUFF_1, BET_TYPE_POLIWAG_2, BET_TYPE_JIGGLYPUFF_3, BET_TYPE_PIKACHU_2},   // BET_TYPE_JIGGLYPUFF_2
    {BET_TYPE_JIGGLYPUFF_2, BET_TYPE_POLIWAG_3, BET_TYPE_JIGGLYPUFF_4, BET_TYPE_PIKACHU_3},   // BET_TYPE_JIGGLYPUFF_3
    {BET_TYPE_JIGGLYPUFF_3, BET_TYPE_POLIWAG_4, BET_TYPE_JIGGLYPUFF_5, BET_TYPE_PIKACHU_4},   // BET_TYPE_JIGGLYPUFF_4
    {BET_TYPE_JIGGLYPUFF_4, BET_TYPE_POLIWAG_5, BET_TYPE_JIGGLYPUFF_6, BET_TYPE_PIKACHU_5},   // BET_TYPE_JIGGLYPUFF_5
    {BET_TYPE_JIGGLYPUFF_5, BET_TYPE_POLIWAG_6, 0xFF, BET_TYPE_PIKACHU_6},                    // BET_TYPE_JIGGLYPUFF_6
    {BET_TYPE_POLIWAG, BET_TYPE_ODDISH_1, BET_TYPE_POLIWAG_2, BET_TYPE_JIGGLYPUFF_1},         // BET_TYPE_POLIWAG_1
    {BET_TYPE_POLIWAG_1, BET_TYPE_ODDISH_2, BET_TYPE_POLIWAG_3, BET_TYPE_JIGGLYPUFF_2},       // BET_TYPE_POLIWAG_2
    {BET_TYPE_POLIWAG_2, BET_TYPE_ODDISH_3, BET_TYPE_POLIWAG_4, BET_TYPE_JIGGLYPUFF_3},       // BET_TYPE_POLIWAG_3
    {BET_TYPE_POLIWAG_3, BET_TYPE_ODDISH_4, BET_TYPE_POLIWAG_5, BET_TYPE_JIGGLYPUFF_4},       // BET_TYPE_POLIWAG_4
    {BET_TYPE_POLIWAG_4, BET_TYPE_ODDISH_5, BET_TYPE_POLIWAG_6, BET_TYPE_JIGGLYPUFF_5},       // BET_TYPE_POLIWAG_5
    {BET_TYPE_POLIWAG_5, BET_TYPE_ODDISH_6, 0xFF, BET_TYPE_JIGGLYPUFF_6},                     // BET_TYPE_POLIWAG_6
    {BET_TYPE_ODDISH, 0xFF, BET_TYPE_ODDISH_2, BET_TYPE_POLIWAG_1},                           // BET_TYPE_ODDISH_1
    {BET_TYPE_ODDISH_1, 0xFF, BET_TYPE_ODDISH_3, BET_TYPE_POLIWAG_2},                         // BET_TYPE_ODDISH_2
    {BET_TYPE_ODDISH_2, 0xFF, BET_TYPE_ODDISH_4, BET_TYPE_POLIWAG_3},                         // BET_TYPE_ODDISH_3
    {BET_TYPE_ODDISH_3, 0xFF, BET_TYPE_ODDISH_5, BET_TYPE_POLIWAG_4},                         // BET_TYPE_ODDISH_4
    {BET_TYPE_ODDISH_4, 0xFF, BET_TYPE_ODDISH_6, BET_TYPE_POLIWAG_5},                         // BET_TYPE_ODDISH_5
    {BET_TYPE_ODDISH_5, 0xFF, 0xFF, BET_TYPE_POLIWAG_6},                                      // BET_TYPE_ODDISH_6
    {BET_TYPE_PIKACHU_JIGGLYPUFF, BET_TYPE_JIGGLYPUFF, BET_TYPE_PIKACHU_1, 0xFF},             // BET_TYPE_PIKACHU
    {BET_TYPE_PIKACHU_JIGGLYPUFF, BET_TYPE_POLIWAG, BET_TYPE_JIGGLYPUFF_1, BET_TYPE_PIKACHU}, // BET_TYPE_JIGGLYPUFF
    {BET_TYPE_POLIWAG_ODDISH, BET_TYPE_ODDISH, BET_TYPE_POLIWAG_1, BET_TYPE_JIGGLYPUFF},      // BET_TYPE_POLIWAG
    {BET_TYPE_POLIWAG_ODDISH, 0xFF, BET_TYPE_ODDISH_1, BET_TYPE_POLIWAG},                     // BET_TYPE_ODDISH
    {0xFF, BET_TYPE_PIKACHU_1, BET_TYPE_LEVEL_2, BET_TYPE_LEVEL_1_2},                         // BET_TYPE_LEVEL_1
    {BET_TYPE_LEVEL_1, BET_TYPE_PIKACHU_2, BET_TYPE_LEVEL_3, BET_TYPE_LEVEL_1_2},             // BET_TYPE_LEVEL_2
    {BET_TYPE_LEVEL_2, BET_TYPE_PIKACHU_3, BET_TYPE_LEVEL_4, BET_TYPE_LEVEL_3_4},             // BET_TYPE_LEVEL_3
    {BET_TYPE_LEVEL_3, BET_TYPE_PIKACHU_4, BET_TYPE_LEVEL_5, BET_TYPE_LEVEL_3_4},             // BET_TYPE_LEVEL_4
    {BET_TYPE_LEVEL_4, BET_TYPE_PIKACHU_5, BET_TYPE_LEVEL_6, BET_TYPE_LEVEL_5_6},             // BET_TYPE_LEVEL_5
    {BET_TYPE_LEVEL_5, BET_TYPE_PIKACHU_6, 0xFF, BET_TYPE_LEVEL_5_6},                         // BET_TYPE_LEVEL_6
    {0xFF, BET_TYPE_POLIWAG_ODDISH, BET_TYPE_PIKACHU, 0xFF},                                  // BET_TYPE_PIKACHU_JIGGLYPUFF
    {0xFF, 0xFF, BET_TYPE_POLIWAG, BET_TYPE_PIKACHU_JIGGLYPUFF},                            // BET_TYPE_POLIWAG_ODDISH
    {0xFF, BET_TYPE_LEVEL_1, BET_TYPE_LEVEL_3_4, 0xFF},                                       // BET_TYPE_LEVEL_1_2
    {BET_TYPE_LEVEL_1_2, BET_TYPE_LEVEL_3, BET_TYPE_LEVEL_5_6, 0xFF},                         // BET_TYPE_LEVEL_3_4
    {BET_TYPE_LEVEL_3_4, BET_TYPE_LEVEL_5, 0xFF, 0xFF},                                       // BET_TYPE_LEVEL_5_6
};

static const struct OamData sBetOutlineHorizontalOamData = {
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = 0,
    .bpp = ST_OAM_4BPP,
    .shape = ST_OAM_H_RECTANGLE,
    .x = 0,
    .matrixNum = 0,
    .size = 1,
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
    .affineParam = 0,
};

static const struct OamData sBetOutlineVerticalOamData = {
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = 0,
    .bpp = ST_OAM_4BPP,
    .shape = ST_OAM_V_RECTANGLE,
    .x = 0,
    .matrixNum = 0,
    .size = 1,
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
    .affineParam = 0,
};

static const struct SpriteTemplate sBetOutlineHorizontalSpriteTemplate = {
    .tileTag = TAG_BET_OUTLINE_HORIZONTAL,
    .paletteTag = TAG_BET_OUTLINE_HORIZONTAL,
    .oam = &sBetOutlineHorizontalOamData,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct SpriteTemplate sBetOutlineVerticalSpriteTemplate = {
    .tileTag = TAG_BET_OUTLINE_VERTICAL,
    .paletteTag = TAG_BET_OUTLINE_VERTICAL,
    .oam = &sBetOutlineVerticalOamData,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct SpriteTemplate sBetOutlineVerticalSmallSpriteTemplate = {
    .tileTag = TAG_BET_OUTLINE_VERTICAL_SMALL,
    .paletteTag = TAG_BET_OUTLINE_VERTICAL_SMALL,
    .oam = &sBetOutlineVerticalOamData,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct CompressedSpriteSheet sBetOutlineHorizontalSpriteSheet = {
    .data = sBetOutlineHorizontalGfx,
    .size = 0x80,
    .tag = TAG_BET_OUTLINE_HORIZONTAL,
};

static const struct CompressedSpriteSheet sBetOutlineVerticalSpriteSheet = {
    .data = sBetOutlineVerticalGfx,
    .size = 0x80,
    .tag = TAG_BET_OUTLINE_VERTICAL,
};

static const struct CompressedSpriteSheet sBetOutlineVerticalSmallSpriteSheet = {
    .data = sBetOutlineVerticalSmallGfx,
    .size = 0x80,
    .tag = TAG_BET_OUTLINE_VERTICAL_SMALL,
};

static const struct CompressedSpriteSheet sRoundCountersSpriteSheet = {
    .data = sRoundCountersGfx,
    .size = 0x40,
    .tag = TAG_ROUND_COUNTERS,
};

static const struct SpritePalette sCardFlipSpritePalettes[] = {
    {sCoinDigitsPalette, TAG_COIN_DIGIT},
    {sCardNumbersPalette, TAG_CARD_NUMBER},
    {sBetOutlineHorizontalPalette, TAG_BET_OUTLINE_HORIZONTAL},
    {sBetOutlineVerticalPalette, TAG_BET_OUTLINE_VERTICAL},
    {sBetOutlineVerticalSmallPalette, TAG_BET_OUTLINE_VERTICAL_SMALL},
    {sRoundCountersPalette, TAG_ROUND_COUNTERS},
    {0},
};

static const struct BetOutlinePosition sBetTypeOutlines_Pikachu1[] = {
    {0, 136, 57},
    {0, 136, 74},
    {2, 122, 65},
    {2, 151, 65},
    {0xFF, 0xFF, 0xFF},
};

static const struct BetOutlinePosition sBetTypeOutlines_Pikachu2[] = {
    {0, 136, 74},
    {0, 136, 91},
    {2, 122, 82},
    {2, 151, 82},
    {0xFF, 0xFF, 0xFF},
};

static const struct BetOutlinePosition sBetTypeOutlines_Pikachu3[] = {
    {0, 136, 91},
    {0, 136, 108},
    {2, 122, 99},
    {2, 151, 99},
    {0xFF, 0xFF, 0xFF},
};

static const struct BetOutlinePosition sBetTypeOutlines_Pikachu4[] = {
    {0, 136, 108},
    {0, 136, 125},
    {2, 122, 116},
    {2, 151, 116},
    {0xFF, 0xFF, 0xFF},
};

static const struct BetOutlinePosition sBetTypeOutlines_Pikachu5[] = {
    {0, 136, 125},
    {0, 136, 142},
    {2, 122, 133},
    {2, 151, 133},
    {0xFF, 0xFF, 0xFF},
};

static const struct BetOutlinePosition sBetTypeOutlines_Pikachu6[] = {
    {0, 136, 142},
    {0, 136, 160},
    {2, 122, 150},
    {2, 151, 150},
    {0xFF, 0xFF, 0xFF},
};

static const struct BetOutlinePosition sBetTypeOutlines_Jigglypuff1[] = {
    {0, 165, 57},
    {0, 165, 74},
    {2, 151, 65},
    {2, 181, 65},
    {0xFF, 0xFF, 0xFF},
};

static const struct BetOutlinePosition sBetTypeOutlines_Jigglypuff2[] = {
    {0, 165, 74},
    {0, 165, 91},
    {2, 151, 82},
    {2, 181, 82},
    {0xFF, 0xFF, 0xFF},
};

static const struct BetOutlinePosition sBetTypeOutlines_Jigglypuff3[] = {
    {0, 165, 91},
    {0, 165, 108},
    {2, 151, 99},
    {2, 181, 99},
    {0xFF, 0xFF, 0xFF},
};

static const struct BetOutlinePosition sBetTypeOutlines_Jigglypuff4[] = {
    {0, 165, 108},
    {0, 165, 125},
    {2, 151, 116},
    {2, 181, 116},
    {0xFF, 0xFF, 0xFF},
};

static const struct BetOutlinePosition sBetTypeOutlines_Jigglypuff5[] = {
    {0, 165, 125},
    {0, 165, 142},
    {2, 151, 133},
    {2, 181, 133},
    {0xFF, 0xFF, 0xFF},
};

static const struct BetOutlinePosition sBetTypeOutlines_Jigglypuff6[] = {
    {0, 165, 142},
    {0, 165, 160},
    {2, 151, 150},
    {2, 181, 150},
    {0xFF, 0xFF, 0xFF},
};

static const struct BetOutlinePosition sBetTypeOutlines_Poliwag1[] = {
    {0, 195, 57},
    {0, 195, 74},
    {2, 181, 65},
    {2, 211, 65},
    {0xFF, 0xFF, 0xFF},
};

static const struct BetOutlinePosition sBetTypeOutlines_Poliwag2[] = {
    {0, 195, 74},
    {0, 195, 91},
    {2, 181, 82},
    {2, 211, 82},
    {0xFF, 0xFF, 0xFF},
};

static const struct BetOutlinePosition sBetTypeOutlines_Poliwag3[] = {
    {0, 195, 91},
    {0, 195, 108},
    {2, 181, 99},
    {2, 211, 99},
    {0xFF, 0xFF, 0xFF},
};

static const struct BetOutlinePosition sBetTypeOutlines_Poliwag4[] = {
    {0, 195, 108},
    {0, 195, 125},
    {2, 181, 116},
    {2, 211, 116},
    {0xFF, 0xFF, 0xFF},
};

static const struct BetOutlinePosition sBetTypeOutlines_Poliwag5[] = {
    {0, 195, 125},
    {0, 195, 142},
    {2, 181, 133},
    {2, 211, 133},
    {0xFF, 0xFF, 0xFF},
};

static const struct BetOutlinePosition sBetTypeOutlines_Poliwag6[] = {
    {0, 195, 142},
    {0, 195, 160},
    {2, 181, 150},
    {2, 211, 150},
    {0xFF, 0xFF, 0xFF},
};

static const struct BetOutlinePosition sBetTypeOutlines_Oddish1[] = {
    {0, 225, 57},
    {0, 225, 74},
    {2, 211, 65},
    {2, 240, 65},
    {0xFF, 0xFF, 0xFF},
};

static const struct BetOutlinePosition sBetTypeOutlines_Oddish2[] = {
    {0, 225, 74},
    {0, 225, 91},
    {2, 211, 82},
    {2, 240, 82},
    {0xFF, 0xFF, 0xFF},
};

static const struct BetOutlinePosition sBetTypeOutlines_Oddish3[] = {
    {0, 225, 91},
    {0, 225, 108},
    {2, 211, 99},
    {2, 240, 99},
    {0xFF, 0xFF, 0xFF},
};

static const struct BetOutlinePosition sBetTypeOutlines_Oddish4[] = {
    {0, 225, 108},
    {0, 225, 125},
    {2, 211, 116},
    {2, 240, 116},
    {0xFF, 0xFF, 0xFF},
};

static const struct BetOutlinePosition sBetTypeOutlines_Oddish5[] = {
    {0, 225, 125},
    {0, 225, 142},
    {2, 211, 133},
    {2, 240, 133},
    {0xFF, 0xFF, 0xFF},
};

static const struct BetOutlinePosition sBetTypeOutlines_Oddish6[] = {
    {0, 225, 142},
    {0, 225, 160},
    {2, 211, 150},
    {2, 240, 150},
    {0xFF, 0xFF, 0xFF},
};

static const struct BetOutlinePosition sBetTypeOutlines_Pikachu[] = {
    {0, 136, 32},
    {0, 136, 160},
    {1, 122, 48},
    {1, 122, 80},
    {1, 122, 112},
    {1, 122, 143},
    {1, 151, 48},
    {1, 151, 80},
    {1, 151, 112},
    {1, 151, 143},
    {0xFF, 0xFF, 0xFF},
};

static const struct BetOutlinePosition sBetTypeOutlines_JigglyPuff[] = {
    {0, 165, 32},
    {0, 165, 160},
    {1, 151, 48},
    {1, 151, 80},
    {1, 151, 112},
    {1, 151, 143},
    {1, 181, 48},
    {1, 181, 80},
    {1, 181, 112},
    {1, 181, 143},
    {0xFF, 0xFF, 0xFF},
};

static const struct BetOutlinePosition sBetTypeOutlines_Poliwag[] = {
    {0, 195, 32},
    {0, 195, 160},
    {1, 181, 48},
    {1, 181, 80},
    {1, 181, 112},
    {1, 181, 143},
    {1, 211, 48},
    {1, 211, 80},
    {1, 211, 112},
    {1, 211, 143},
    {0xFF, 0xFF, 0xFF},
};

static const struct BetOutlinePosition sBetTypeOutlines_Oddish[] = {
    {0, 225, 32},
    {0, 225, 160},
    {1, 211, 48},
    {1, 211, 80},
    {1, 211, 112},
    {1, 211, 143},
    {1, 240, 48},
    {1, 240, 80},
    {1, 240, 112},
    {1, 240, 143},
    {0xFF, 0xFF, 0xFF},
};

static const struct BetOutlinePosition sBetTypeOutlines_Level1[] = {
    {0, 125, 57},
    {0, 155, 57},
    {0, 185, 57},
    {0, 215, 57},
    {0, 225, 57},
    {0, 125, 74},
    {0, 155, 74},
    {0, 185, 74},
    {0, 215, 74},
    {0, 225, 74},
    {2, 111, 65},
    {2, 240, 65},
    {0xFF, 0xFF, 0xFF},
};

static const struct BetOutlinePosition sBetTypeOutlines_Level2[] = {
    {0, 125, 74},
    {0, 155, 74},
    {0, 185, 74},
    {0, 215, 74},
    {0, 225, 74},
    {0, 125, 91},
    {0, 155, 91},
    {0, 185, 91},
    {0, 215, 91},
    {0, 225, 91},
    {2, 111, 82},
    {2, 240, 82},
    {0xFF, 0xFF, 0xFF},
};

static const struct BetOutlinePosition sBetTypeOutlines_Level3[] = {
    {0, 125, 91},
    {0, 155, 91},
    {0, 185, 91},
    {0, 215, 91},
    {0, 225, 91},
    {0, 125, 108},
    {0, 155, 108},
    {0, 185, 108},
    {0, 215, 108},
    {0, 225, 108},
    {2, 111, 99},
    {2, 240, 99},
    {0xFF, 0xFF, 0xFF},
};

static const struct BetOutlinePosition sBetTypeOutlines_Level4[] = {
    {0, 125, 108},
    {0, 155, 108},
    {0, 185, 108},
    {0, 215, 108},
    {0, 225, 108},
    {0, 125, 125},
    {0, 155, 125},
    {0, 185, 125},
    {0, 215, 125},
    {0, 225, 125},
    {2, 111, 116},
    {2, 240, 116},
    {0xFF, 0xFF, 0xFF},
};

static const struct BetOutlinePosition sBetTypeOutlines_Level5[] = {
    {0, 125, 125},
    {0, 155, 125},
    {0, 185, 125},
    {0, 215, 125},
    {0, 225, 125},
    {0, 125, 142},
    {0, 155, 142},
    {0, 185, 142},
    {0, 215, 142},
    {0, 225, 142},
    {2, 111, 133},
    {2, 240, 133},
    {0xFF, 0xFF, 0xFF},
};

static const struct BetOutlinePosition sBetTypeOutlines_Level6[] = {
    {0, 125, 142},
    {0, 155, 142},
    {0, 185, 142},
    {0, 215, 142},
    {0, 225, 142},
    {0, 125, 160},
    {0, 155, 160},
    {0, 185, 160},
    {0, 215, 160},
    {0, 225, 160},
    {2, 111, 151},
    {2, 240, 151},
    {0xFF, 0xFF, 0xFF},
};

static const struct BetOutlinePosition sBetTypeOutlines_PikachuJigglypuff[] = {
    {0, 136, 17},
    {0, 166, 17},
    {0, 136, 160},
    {0, 166, 160},
    {1, 122, 33},
    {1, 122, 65},
    {1, 122, 97},
    {1, 122, 129},
    {1, 122, 143},
    {1, 181, 33},
    {1, 181, 65},
    {1, 181, 97},
    {1, 181, 129},
    {1, 181, 143},
    {0xFF, 0xFF, 0xFF},
};

static const struct BetOutlinePosition sBetTypeOutlines_PoliwagOddish[] = {
    {0, 195, 17},
    {0, 225, 17},
    {0, 195, 160},
    {0, 225, 160},
    {1, 181, 33},
    {1, 181, 65},
    {1, 181, 97},
    {1, 181, 129},
    {1, 181, 143},
    {1, 240, 33},
    {1, 240, 65},
    {1, 240, 97},
    {1, 240, 129},
    {1, 240, 143},
    {0xFF, 0xFF, 0xFF},
};

static const struct BetOutlinePosition sBetTypeOutlines_Levels12[] = {
    {0, 115, 57},
    {0, 130, 57},
    {0, 155, 57},
    {0, 185, 57},
    {0, 215, 57},
    {0, 225, 57},
    {0, 115, 91},
    {0, 130, 91},
    {0, 155, 91},
    {0, 185, 91},
    {0, 215, 91},
    {0, 225, 91},
    {2, 100, 65},
    {2, 100, 82},
    {2, 240, 65},
    {2, 240, 82},
    {0xFF, 0xFF, 0xFF},
};

static const struct BetOutlinePosition sBetTypeOutlines_Levels34[] = {
    {0, 115, 91},
    {0, 130, 91},
    {0, 155, 91},
    {0, 185, 91},
    {0, 215, 91},
    {0, 225, 91},
    {0, 115, 125},
    {0, 130, 125},
    {0, 155, 125},
    {0, 185, 125},
    {0, 215, 125},
    {0, 225, 125},
    {2, 100, 99},
    {2, 100, 116},
    {2, 240, 99},
    {2, 240, 116},
    {0xFF, 0xFF, 0xFF},
};

static const struct BetOutlinePosition sBetTypeOutlines_Levels56[] = {
    {0, 115, 125},
    {0, 130, 125},
    {0, 155, 125},
    {0, 185, 125},
    {0, 215, 125},
    {0, 225, 125},
    {0, 115, 160},
    {0, 130, 160},
    {0, 155, 160},
    {0, 185, 160},
    {0, 215, 160},
    {0, 225, 160},
    {2, 100, 133},
    {2, 100, 151},
    {2, 240, 133},
    {2, 240, 151},
    {0xFF, 0xFF, 0xFF},
};

static const struct BetOutlinePosition *const sBetTypeOutlines[] = {
    sBetTypeOutlines_Pikachu1,          // BET_TYPE_PIKACHU_1
    sBetTypeOutlines_Pikachu2,          // BET_TYPE_PIKACHU_2
    sBetTypeOutlines_Pikachu3,          // BET_TYPE_PIKACHU_3
    sBetTypeOutlines_Pikachu4,          // BET_TYPE_PIKACHU_4
    sBetTypeOutlines_Pikachu5,          // BET_TYPE_PIKACHU_5
    sBetTypeOutlines_Pikachu6,          // BET_TYPE_PIKACHU_6
    sBetTypeOutlines_Jigglypuff1,       // BET_TYPE_JIGGLYPUFF_1
    sBetTypeOutlines_Jigglypuff2,       // BET_TYPE_JIGGLYPUFF_2
    sBetTypeOutlines_Jigglypuff3,       // BET_TYPE_JIGGLYPUFF_3
    sBetTypeOutlines_Jigglypuff4,       // BET_TYPE_JIGGLYPUFF_4
    sBetTypeOutlines_Jigglypuff5,       // BET_TYPE_JIGGLYPUFF_5
    sBetTypeOutlines_Jigglypuff6,       // BET_TYPE_JIGGLYPUFF_6
    sBetTypeOutlines_Poliwag1,          // BET_TYPE_POLIWAG_1
    sBetTypeOutlines_Poliwag2,          // BET_TYPE_POLIWAG_2
    sBetTypeOutlines_Poliwag3,          // BET_TYPE_POLIWAG_3
    sBetTypeOutlines_Poliwag4,          // BET_TYPE_POLIWAG_4
    sBetTypeOutlines_Poliwag5,          // BET_TYPE_POLIWAG_5
    sBetTypeOutlines_Poliwag6,          // BET_TYPE_POLIWAG_6
    sBetTypeOutlines_Oddish1,           // BET_TYPE_ODDISH_1
    sBetTypeOutlines_Oddish2,           // BET_TYPE_ODDISH_2
    sBetTypeOutlines_Oddish3,           // BET_TYPE_ODDISH_3
    sBetTypeOutlines_Oddish4,           // BET_TYPE_ODDISH_4
    sBetTypeOutlines_Oddish5,           // BET_TYPE_ODDISH_5
    sBetTypeOutlines_Oddish6,           // BET_TYPE_ODDISH_6
    sBetTypeOutlines_Pikachu,           // BET_TYPE_PIKACHU
    sBetTypeOutlines_JigglyPuff,        // BET_TYPE_JIGGLYPUFF
    sBetTypeOutlines_Poliwag,           // BET_TYPE_POLIWAG
    sBetTypeOutlines_Oddish,            // BET_TYPE_ODDISH
    sBetTypeOutlines_Level1,            // BET_TYPE_LEVEL_1
    sBetTypeOutlines_Level2,            // BET_TYPE_LEVEL_2
    sBetTypeOutlines_Level3,            // BET_TYPE_LEVEL_3
    sBetTypeOutlines_Level4,            // BET_TYPE_LEVEL_4
    sBetTypeOutlines_Level5,            // BET_TYPE_LEVEL_5
    sBetTypeOutlines_Level6,            // BET_TYPE_LEVEL_6
    sBetTypeOutlines_PikachuJigglypuff, // BET_TYPE_PIKACHU_JIGGLYPUFF
    sBetTypeOutlines_PoliwagOddish,     // BET_TYPE_POLIWAG_ODDISH
    sBetTypeOutlines_Levels12,          // BET_TYPE_LEVEL_1_2
    sBetTypeOutlines_Levels34,          // BET_TYPE_LEVEL_3_4
    sBetTypeOutlines_Levels56,          // BET_TYPE_LEVEL_5_6
};

// Lookup table to determine if a card is in a bet type.
static const u8 sBetTypeCards[][NUM_CARDS] = {
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // BET_TYPE_PIKACHU_1
    {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // BET_TYPE_PIKACHU_2
    {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // BET_TYPE_PIKACHU_3
    {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // BET_TYPE_PIKACHU_4
    {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // BET_TYPE_PIKACHU_5
    {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // BET_TYPE_PIKACHU_6
    {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // BET_TYPE_JIGGLYPUFF_1
    {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // BET_TYPE_JIGGLYPUFF_2
    {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // BET_TYPE_JIGGLYPUFF_3
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // BET_TYPE_JIGGLYPUFF_4
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // BET_TYPE_JIGGLYPUFF_5
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // BET_TYPE_JIGGLYPUFF_6
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // BET_TYPE_POLIWAG_1
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // BET_TYPE_POLIWAG_2
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // BET_TYPE_POLIWAG_3
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0}, // BET_TYPE_POLIWAG_4
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0}, // BET_TYPE_POLIWAG_5
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0}, // BET_TYPE_POLIWAG_6
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, // BET_TYPE_ODDISH_1
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0}, // BET_TYPE_ODDISH_2
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0}, // BET_TYPE_ODDISH_3
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, // BET_TYPE_ODDISH_4
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0}, // BET_TYPE_ODDISH_5
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, // BET_TYPE_ODDISH_6
    {1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // BET_TYPE_PIKACHU
    {0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // BET_TYPE_JIGGLYPUFF
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0}, // BET_TYPE_POLIWAG
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1}, // BET_TYPE_ODDISH
    {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, // BET_TYPE_LEVEL_1
    {0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0}, // BET_TYPE_LEVEL_2
    {0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0}, // BET_TYPE_LEVEL_3
    {0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0}, // BET_TYPE_LEVEL_4
    {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0}, // BET_TYPE_LEVEL_5
    {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1}, // BET_TYPE_LEVEL_6
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // BET_TYPE_PIKACHU_JIGGLYPUFF
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, // BET_TYPE_POLIWAG_ODDISH
    {1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}, // BET_TYPE_LEVEL_1_2
    {0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0}, // BET_TYPE_LEVEL_3_4
    {0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1}, // BET_TYPE_LEVEL_5_6
};

static const u8 sBetPayoutMultipliers[] = {
    24, // BET_TYPE_PIKACHU_1
    24, // BET_TYPE_PIKACHU_2
    24, // BET_TYPE_PIKACHU_3
    24, // BET_TYPE_PIKACHU_4
    24, // BET_TYPE_PIKACHU_5
    24, // BET_TYPE_PIKACHU_6
    24, // BET_TYPE_JIGGLYPUFF_1
    24, // BET_TYPE_JIGGLYPUFF_2
    24, // BET_TYPE_JIGGLYPUFF_3
    24, // BET_TYPE_JIGGLYPUFF_4
    24, // BET_TYPE_JIGGLYPUFF_5
    24, // BET_TYPE_JIGGLYPUFF_6
    24, // BET_TYPE_POLIWAG_1
    24, // BET_TYPE_POLIWAG_2
    24, // BET_TYPE_POLIWAG_3
    24, // BET_TYPE_POLIWAG_4
    24, // BET_TYPE_POLIWAG_5
    24, // BET_TYPE_POLIWAG_6
    24, // BET_TYPE_ODDISH_1
    24, // BET_TYPE_ODDISH_2
    24, // BET_TYPE_ODDISH_3
    24, // BET_TYPE_ODDISH_4
    24, // BET_TYPE_ODDISH_5
    24, // BET_TYPE_ODDISH_6
    4, // BET_TYPE_PIKACHU
    4, // BET_TYPE_JIGGLYPUFF
    4, // BET_TYPE_POLIWAG
    4, // BET_TYPE_ODDISH
    6, // BET_TYPE_LEVEL_1
    6, // BET_TYPE_LEVEL_2
    6, // BET_TYPE_LEVEL_3
    6, // BET_TYPE_LEVEL_4
    6, // BET_TYPE_LEVEL_5
    6, // BET_TYPE_LEVEL_6
    2, // BET_TYPE_PIKACHU_JIGGLYPUFF
    2, // BET_TYPE_POLIWAG_ODDISH
    3, // BET_TYPE_LEVEL_1_2
    3, // BET_TYPE_LEVEL_3_4
    3, // BET_TYPE_LEVEL_5_6
};

/*static u8 SanitizeNumCoinsEntry(int numCoinsEntry)
{
    if (numCoinsEntry <= 0)
        numCoinsEntry = 1;

    return numCoinsEntry;
}*/

void PlayCardFlip(void)
{
    u8 taskId;

    ScriptContext1_Stop();
    sCardFlip = AllocZeroed(sizeof(*sCardFlip));
    sCardFlip->returnMainCallback = CB2_ReturnToFieldContinueScriptPlayMapMusic;
    //sCardFlip->numCoinsEntry = SanitizeNumCoinsEntry(gSpecialVar_0x8004);
    sCardFlip->numCoinsEntry = 3;
    taskId = CreateTask(FadeToCardFlipScreen, 0);
}

static void FadeToCardFlipScreen(u8 taskId)
{
    switch (gTasks[taskId].data[0])
    {
    case 0:
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
        gTasks[taskId].data[0]++;
        break;
    case 1:
        if (!gPaletteFade.active)
        {
            SetMainCallback2(InitCardFlipScreen);
            DestroyTask(taskId);
        }
        break;
    }
}

static void InitCardFlipScreen(void)
{
    switch (gMain.state)
    {
    case 0:
        SetVBlankCallback(NULL);
        SetHBlankCallback(NULL);
        CpuFill32(0, (void *)VRAM, VRAM_SIZE);
        ResetBgsAndClearDma3BusyFlags(0);
        InitBgsFromTemplates(0, sCardFlipBgTemplates, ARRAY_COUNT(sCardFlipBgTemplates));
        InitWindows(sCardFlipWinTemplates);
        DeactivateAllTextPrinters();
        gMain.state++;
        break;
    case 1:
        DmaClearLarge16(3, (u16 *)(BG_VRAM), BG_VRAM_SIZE, 0x1000);
        gMain.state++;
        break;
    case 2:
        DmaClear16(3, (u16 *)OAM, OAM_SIZE);
        ResetVramOamAndBgCntRegs();
        ResetAllBgsCoordinates();
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 | DISPCNT_OBJ_1D_MAP | DISPCNT_OBJ_ON);
        gMain.state++;
        break;
    case 3:
        ResetPaletteFade();
        ResetSpriteData();
        FreeAllSpritePalettes();
        ResetTasks();
        gMain.state++;
        break;
    case 4:
        SetBgTilemapBuffer(CARD_FLIP_BG_BASE, AllocZeroed(BG_SCREEN_SIZE));
        DecompressAndLoadBgGfxUsingHeap(CARD_FLIP_BG_BASE, sCardFlipBaseBgGfx, 0x22E0, 0, 0);
        CopyToBgTilemapBuffer(CARD_FLIP_BG_BASE, sCardFlipBaseBgTilemap, 0, 0);
        LoadPalette(sCardFlipBaseBgPalette, 0, sizeof(sCardFlipBaseBgPalette));
        LoadMessageBoxGfx(WIN_TEXT, 0x200, 0xF0);
        LoadUserWindowBorderGfx(WIN_TEXT, 0x214, 0xE0);
        gMain.state++;
        break;
    case 5:
        CopyBgTilemapBufferToVram(CARD_FLIP_BG_BASE);
        ShowBg(CARD_FLIP_BG_TEXT);
        ShowBg(CARD_FLIP_BG_BET_OUTLINE);
        ShowBg(CARD_FLIP_BG_BASE);
        gMain.state++;
        break;
    case 6:
        LoadCompressedSpriteSheet(&sCoinDigitsSpriteSheet);
        LoadCompressedSpriteSheet(&sCardNumbersSpriteSheet);
        LoadCompressedSpriteSheet(&sBetOutlineHorizontalSpriteSheet);
        LoadCompressedSpriteSheet(&sBetOutlineVerticalSpriteSheet);
        LoadCompressedSpriteSheet(&sBetOutlineVerticalSmallSpriteSheet);
        LoadCompressedSpriteSheet(&sRoundCountersSpriteSheet);
        LoadSpritePalettes(sCardFlipSpritePalettes);
        LoadMonIconPalettes();
        LoadPalette(GetTextWindowPalette(2), 11 * 16, 32); // palette for WIN_HELP
        LoadCardBackGfx();
        LoadCardSelectionGfx();
        InitCoinDigitSprites();
        InitMonIcons();
        InitCardNumberSprites();
        InitRoundCounterSprites();
        ShowHelpBar(sHelpBar_SelectExit);
        gMain.state++;
    case 7:
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, RGB_BLACK);
        SetVBlankCallback(CardFlipVBlankCallback);
        SetMainCallback2(CardFlipMainCallback);
        CreateTask(CardFlipMain, 0);
        return;
    }
}

static void CardFlipMainCallback(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    RunTextPrinters();
    UpdatePaletteFade();
}

static void CardFlipVBlankCallback(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void CardFlipMain(u8 taskId)
{
    switch (sCardFlip->state)
    {
    case CARD_FLIP_STATE_INIT:
        InitCardFlipTable(taskId);
        break;
    case CARD_FLIP_STATE_PLAY_MESSAGE:
        if (!gPaletteFade.active)
            DisplayInitialPlayMessage();
        break;
    case CARD_FLIP_STATE_PLAY_PROMPT:
        DisplayInitialPlayPrompt();
        break;
    case CARD_FLIP_STATE_PLAY_PROMPT_GET_INPUT:
        ProcessPlayPromptInput();
        break;
    case CARD_FLIP_STATE_PLAY_DEAL_CARDS:
        DealCards(taskId);
        break;
    case CARD_FLIP_STATE_CHOOSE_CARD:
        ChooseCard(taskId);
        break;
    case CARD_FLIP_STATE_PLACE_BET:
        PlaceBet();
        break;
    case CARD_FLIP_STATE_REVEAL_CARD:
        RevealCard(taskId);
        break;
    case CARD_FLIP_STATE_DISPLAY_OUTCOME_MESSAGE:
        DisplayBetOutcomeMessage();
        break;
    case CARD_FLIP_STATE_DISPLAY_OUTCOME_MESSAGE_INPUT:
        DisplayBetOutcomeMessage_WaitButtonPress();
        break;
    case CARD_FLIP_STATE_PLAY_AGAIN_MESSAGE:
        PlayAgainMessage();
        break;
    case CARD_FLIP_STATE_PLAY_AGAIN_PROMPT:
        PlayAgainPrompt();
        break;
    case CARD_FLIP_STATE_PLAY_AGAIN_PROMPT_INPUT:
        ProcessPlayAgainPromptInput(taskId);
        break;
    case CARD_FLIP_STATE_SHUFFLE_DECK_MESSAGE:
        ShuffleDeckMessage();
        break;
    case CARD_FLIP_STATE_SHUFFLE_DECK_INPUT:
        ProcessShuffleDeckInput();
        break;
    case CARD_FLIP_NOT_ENOUGH_COINS:
        DisplayNotEnoughCoinsMessage();
        break;
    case CARD_FLIP_NOT_ENOUGH_COINS_INPUT:
        ProcessNotEnoughCoinsInput();
        break;
    case CARD_FLIP_STATE_START_EXIT:
        StartExitCardFlip();
        break;
    case CARD_FLIP_STATE_EXIT:
        ExitCardFlip();
        break;
    case CARD_FLIP_WAIT_ANIM:
        WaitForUIAnimToFinish(taskId);
        break;
    }
}

static void RemoveCardNumberFromBoard(int cardId)
{
    if (sCardFlip->cardNumberSpriteIds[cardId] != MAX_SPRITES)
        gSprites[sCardFlip->cardNumberSpriteIds[cardId]].invisible = 1;
}

static void ShowAllCardNumbers(void)
{
    int i;
    for (i = 0; i < NUM_CARDS; i++)
        gSprites[sCardFlip->cardNumberSpriteIds[i]].invisible = 0;
}

static void ResetAllRoundCounters(void)
{
    int i;
    for (i = 0; i < 12; i++)
        StartSpriteAnim(&gSprites[sCardFlip->roundCounterSpriteIds[i]], 0);
}

static void InitCardFlipTable(u8 taskId)
{
    int i;
    for (i = 0; i < ARRAY_COUNT(sCardFlip->betOutlineSpriteIds); i++)
        sCardFlip->betOutlineSpriteIds[i] = MAX_SPRITES;

    sCardFlip->state = CARD_FLIP_STATE_PLAY_MESSAGE;
}

static void DisplayInitialPlayMessage(void)
{
    DrawDialogueFrame(WIN_TEXT, 0);

    if (GetCoins() >= sCardFlip->numCoinsEntry)
    {
        ConvertIntToDecimalStringN(gStringVar1, sCardFlip->numCoinsEntry, 0, 3);
        StringExpandPlaceholders(gStringVar2, sPlayTheGamePromptText);
        AddTextPrinterParameterized(WIN_TEXT, 2, gStringVar2, 0, 1, 0, NULL);

        CopyWindowToVram(WIN_TEXT, 3);
        sCardFlip->state = CARD_FLIP_STATE_PLAY_PROMPT;
    }
    else
    {
        sCardFlip->state = CARD_FLIP_NOT_ENOUGH_COINS;
    }
}

static void DisplayInitialPlayPrompt(void)
{
    if (!IsTextPrinterActive(WIN_TEXT))
    {
        CreateYesNoMenuParameterized(21, 7, 0x214, 0x180, 0xE, 0xF);
        sCardFlip->state = CARD_FLIP_STATE_PLAY_PROMPT_GET_INPUT;
    }
}

static void ProcessPlayPromptInput(void)
{
    int selection = Menu_ProcessInputNoWrapClearOnChoose();
    if (selection == 0)
    {
        ClearDialogWindowAndFrame(0, TRUE);
        ResetAndShuffleCardDeck();
        sCardFlip->state = CARD_FLIP_STATE_PLAY_DEAL_CARDS;
    }
    else if (selection == 1 || selection == MENU_B_PRESSED)
    {
        ClearDialogWindowAndFrame(0, TRUE);
        PlaySE(SE_SELECT);
        sCardFlip->state = CARD_FLIP_STATE_START_EXIT;
    }
}

static void DealCards(u8 taskId)
{
    ShowHelpBar(sHelpBar_Select);
    ChangeCoinAmount(-sCardFlip->numCoinsEntry, 0);

    // Light up current round light.
    StartSpriteAnim(&gSprites[sCardFlip->roundCounterSpriteIds[sCardFlip->deckTop / 2]], 1);

    // Create two card sprites and slide them in.
    sCardFlip->cardBackSpriteIds[0] = CreateSprite(&sCardBackSpriteTemplate, -32, 61, 3);
    sCardFlip->cardBackSpriteIds[1] = CreateSprite(&sCardBackSpriteTemplate, -32, 123, 3);
    gSprites[sCardFlip->cardBackSpriteIds[0]].data[0] = taskId;
    gSprites[sCardFlip->cardBackSpriteIds[0]].data[1] = 0;
    gSprites[sCardFlip->cardBackSpriteIds[1]].data[0] = taskId;
    gSprites[sCardFlip->cardBackSpriteIds[0]].data[1] = 1;

    StartUIAnim(taskId, CARD_FLIP_STATE_CHOOSE_CARD);
}

static void ChooseCard(u8 taskId)
{
    u8 spriteId = CreateSprite(&sCardSelectionSpriteTemplate, 48, 61, 2);
    gSprites[spriteId].data[0] = taskId;

    StartUIAnim(taskId, CARD_FLIP_STATE_PLACE_BET);
}

static void PlaceBet(void)
{
    u8 nextBetType = 0xFF;

    if (JOY_NEW(A_BUTTON))
    {
        if (IsValidBetType(sCardFlip->betType))
        {
            PlaySE(SE_SELECT);
            sCardFlip->state = CARD_FLIP_STATE_REVEAL_CARD;
        }
        else
        {
            PlaySE(SE_FAILURE);
        }
        return;
    }

    if (JOY_NEW(DPAD_UP))
        nextBetType = sBetTypeInputTransitions[sCardFlip->betType][0];
    else if (JOY_NEW(DPAD_RIGHT))
        nextBetType = sBetTypeInputTransitions[sCardFlip->betType][1];
    else if (JOY_NEW(DPAD_DOWN))
        nextBetType = sBetTypeInputTransitions[sCardFlip->betType][2];
    else if (JOY_NEW(DPAD_LEFT))
        nextBetType = sBetTypeInputTransitions[sCardFlip->betType][3];

    if (nextBetType != 0xFF)
    {
        PlaySE(SE_BALL_TRAY_EXIT);
        sCardFlip->betType = nextBetType;
        DrawBetType(sCardFlip->betType);
    }
}

static bool8 IsValidBetType(u8 betType)
{
    int i;
    for (i = 0; i < NUM_CARDS; i++)
    {
        if (sBetTypeCards[betType][i] && !gSprites[sCardFlip->cardNumberSpriteIds[i]].invisible)
            return TRUE;
    }

    return FALSE;
}

static const struct SpriteTemplate *const sBetSpriteTemplates[] = {
    &sBetOutlineHorizontalSpriteTemplate,
    &sBetOutlineVerticalSpriteTemplate,
    &sBetOutlineVerticalSmallSpriteTemplate,
};

static void DrawBetType(u8 betType)
{
    int i;
    u8 spriteId;
    u8 normalPalIndex;
    u8 betPalIndex;
    const struct SpriteTemplate *template;
    const struct BetOutlinePosition *positions = sBetTypeOutlines[betType];

    for (i = 0; i < ARRAY_COUNT(sCardFlip->betOutlineSpriteIds); i++)
    {
        spriteId = sCardFlip->betOutlineSpriteIds[i];
        if (spriteId != MAX_SPRITES)
            DestroySprite(&gSprites[spriteId]);

        sCardFlip->betOutlineSpriteIds[i] = MAX_SPRITES;
    }

    i = 0;
    while (positions[i].type != 0xFF)
    {
        template = sBetSpriteTemplates[positions[i].type];
        sCardFlip->betOutlineSpriteIds[i] = CreateSprite(template, positions[i].x, positions[i].y, 3);;
        i++;
    }

    normalPalIndex = IndexOfSpritePaletteTag(TAG_CARD_NUMBER);
    betPalIndex = IndexOfSpritePaletteTag(TAG_BET_OUTLINE_HORIZONTAL);
    for (i = 0; i < NUM_CARDS; i++)
    {
        spriteId = sCardFlip->cardNumberSpriteIds[i];
        if (spriteId != MAX_SPRITES)
        {
            if (sBetTypeCards[betType][i])
                gSprites[spriteId].oam.paletteNum = betPalIndex;
            else
                gSprites[spriteId].oam.paletteNum = normalPalIndex;
        }
    }
}

static void RevealCard(u8 taskId)
{
    struct Sprite *sprite;

    sprite = &gSprites[sCardFlip->cardBackSpriteIds[sCardFlip->selectedCardIndex]];
    sprite->oam.affineMode = ST_OAM_AFFINE_NORMAL;
    StartSpriteAffineAnim(sprite, 0);
    sprite->callback = FlipOverCardStart;
    sprite->data[0] = taskId;
    StartUIAnim(taskId, CARD_FLIP_STATE_DISPLAY_OUTCOME_MESSAGE);
}

static void DisplayBetOutcomeMessage(void)
{
    if (!FuncIsActiveTask(UpdateCoinDigitSprites) && IsFanfareTaskInactive())
    {
        u8 wonBet = sBetTypeCards[sCardFlip->betType][CARD_ID(sCardFlip->drawnCard)];
        ShowHelpBar(sHelpBar_Next);
        DrawDialogueFrame(WIN_TEXT, 0);
        if (wonBet)
            AddTextPrinterParameterized(WIN_TEXT, 2, sYeahText, 0, 1, 0, NULL);
        else
            AddTextPrinterParameterized(WIN_TEXT, 2, sDarnText, 0, 1, 0, NULL);

        CopyWindowToVram(WIN_TEXT, 3);
        sCardFlip->state = CARD_FLIP_STATE_DISPLAY_OUTCOME_MESSAGE_INPUT;
    }
}

static void DisplayBetOutcomeMessage_WaitButtonPress(void)
{
    if (!IsTextPrinterActive(WIN_TEXT) && JOY_NEW(A_BUTTON | B_BUTTON))
    {
        PlaySE(SE_SELECT);
        sCardFlip->state = CARD_FLIP_STATE_PLAY_AGAIN_MESSAGE;
    }
}

static void AwardCoins(void)
{
    u8 multiplier = sBetPayoutMultipliers[sCardFlip->betType];
    int coinsToGive = sCardFlip->numCoinsEntry * multiplier;
    if (multiplier == 24)
        PlayFanfare(MUS_SLOTS_JACKPOT);
    else
        PlayFanfare(MUS_SLOTS_WIN);

    ChangeCoinAmount(coinsToGive, 100);
}

static void PlayAgainMessage(void)
{
    ShowHelpBar(sHelpBar_SelectExit);
    DrawDialogueFrame(WIN_TEXT, 0);
    AddTextPrinterParameterized(WIN_TEXT, 2, sPlayAgainText, 0, 1, 0, NULL);
    CopyWindowToVram(WIN_TEXT, 3);
    sCardFlip->state = CARD_FLIP_STATE_PLAY_AGAIN_PROMPT;
}

static void PlayAgainPrompt(void)
{
    if (!IsTextPrinterActive(WIN_TEXT))
    {
        CreateYesNoMenuParameterized(21, 7, 0x214, 0x180, 0xE, 0xF);
        sCardFlip->state = CARD_FLIP_STATE_PLAY_AGAIN_PROMPT_INPUT;
    }
}

static void ProcessPlayAgainPromptInput(u8 taskId)
{
    int selection = Menu_ProcessInputNoWrapClearOnChoose();
    if (selection == 0)
    {
        ClearDialogWindowAndFrame(0, TRUE);
        RemoveCardNumberFromBoard(CARD_ID(sCardFlip->drawnCard));
        if (GetCoins() >= sCardFlip->numCoinsEntry)
        {
            gSprites[sCardFlip->cardFrontSpriteId].data[0] = taskId;
            gSprites[sCardFlip->cardFrontSpriteId].callback = SlideOutCard;
            if (sCardFlip->deckTop >= NUM_CARDS)
                StartUIAnim(taskId, CARD_FLIP_STATE_SHUFFLE_DECK_MESSAGE);
            else
                StartUIAnim(taskId, CARD_FLIP_STATE_PLAY_DEAL_CARDS);
        }
        else
        {
            sCardFlip->state = CARD_FLIP_NOT_ENOUGH_COINS;
        }
    }
    else if (selection == 1 || selection == MENU_B_PRESSED)
    {
        ClearDialogWindowAndFrame(0, TRUE);
        PlaySE(SE_SELECT);
        sCardFlip->state = CARD_FLIP_STATE_START_EXIT;
    }
}

static void ShuffleDeckMessage(void)
{
    DrawDialogueFrame(WIN_TEXT, 0);
    AddTextPrinterParameterized(WIN_TEXT, 2, sShuffledCardsText, 0, 1, 0, NULL);
    CopyWindowToVram(WIN_TEXT, 3);
    ResetAndShuffleCardDeck();
    sCardFlip->state = CARD_FLIP_STATE_SHUFFLE_DECK_INPUT;   
}

static void ProcessShuffleDeckInput(void)
{
    if (!IsTextPrinterActive(WIN_TEXT) && JOY_NEW(A_BUTTON | B_BUTTON))
    {
        ClearDialogWindowAndFrame(0, TRUE);
        sCardFlip->state = CARD_FLIP_STATE_PLAY_DEAL_CARDS;
    }
}

static void DisplayNotEnoughCoinsMessage(void)
{
    DrawDialogueFrame(WIN_TEXT, 0);
    AddTextPrinterParameterized(WIN_TEXT, 2, sNotEnoughCoinsText, 0, 1, 0, NULL);
    CopyWindowToVram(WIN_TEXT, 3);
    sCardFlip->state = CARD_FLIP_NOT_ENOUGH_COINS_INPUT;
}

static void ProcessNotEnoughCoinsInput(void)
{
    if (!IsTextPrinterActive(WIN_TEXT) && JOY_NEW(A_BUTTON | B_BUTTON))
    {
        ClearDialogWindowAndFrame(0, TRUE);
        sCardFlip->state = CARD_FLIP_STATE_START_EXIT;
    }
}

static void InitCoinDigitSprites(void)
{
    int i;
    int x, y, digit;
    int numCoins;

    numCoins = GetCoins();
    for (i = 0; i < 4; i++)
    {
        digit = numCoins % 10;
        numCoins /= 10;
        x = 61 - i * 7;
        y = 9;
        sCardFlip->coinDigitSpriteIds[i] = CreateSprite(&sCoinDigitSpriteTemplate, x, y, 3);
        StartSpriteAnim(&gSprites[sCardFlip->coinDigitSpriteIds[i]], digit);
    }
}

static void InitMonIcons(void)
{
    sCardFlip->suitSpriteIds[2] = CreateMonIcon(SPECIES_PIKACHU, SpriteCallbackDummy, 136, 40, 3, 0, 0);
    sCardFlip->suitSpriteIds[1] = CreateMonIcon(SPECIES_JIGGLYPUFF, SpriteCallbackDummy, 166, 40, 3, 0, 0);
    sCardFlip->suitSpriteIds[2] = CreateMonIcon(SPECIES_POLIWAG, SpriteCallbackDummy, 196, 40, 3, 0, 0);
    sCardFlip->suitSpriteIds[3] = CreateMonIcon(SPECIES_ODDISH, SpriteCallbackDummy, 226, 40, 3, 0, 0);
}

static void InitCardNumberSprites(void)
{
    int i, suit;
    int x, y;

    for (i = 0; i < NUM_NUMBERS; i++)
    {
        for (suit = 0; suit < NUM_SUITS; suit++)
        {
            int index = suit * NUM_NUMBERS + i;
            x = 144 + 30 * suit;
            y = 65 + i * 17;
            if (i == NUM_NUMBERS - 1)
                y++;

            sCardFlip->cardNumberSpriteIds[index] = CreateSprite(&sCardNumberSpriteTemplate, x, y, 3);
            StartSpriteAnim(&gSprites[sCardFlip->cardNumberSpriteIds[index]], i);
        }
    }
}

static void InitRoundCounterSprites(void)
{
    int i;
    for (i = 0; i < 12; i++)
    {
        sCardFlip->roundCounterSpriteIds[i] = CreateSprite(&sRoundCounterSpriteTemplate, i * 8 + 5, 21, 3);
        StartSpriteAnim(&gSprites[sCardFlip->roundCounterSpriteIds[i]], 0);
    }
}

static void ChangeCoinAmount(int delta, int startDelay)
{
    ChangeCoinAmountFixedDuration(delta, 0, startDelay);
}

static void ChangeCoinAmountFixedDuration(int delta, int duration, int startDelay)
{
    u8 taskId;
    int curCoins, targetCoins;

    if (delta == 0)
        return;

    curCoins = GetCoins();
    if (curCoins + delta < 0)
        delta = -curCoins;
    else if (curCoins + delta > 9999)
        delta = 9999 - curCoins;

    taskId = CreateTask(UpdateCoinDigitSprites, 3);
    gTasks[taskId].data[0] = curCoins;
    gTasks[taskId].data[3] = startDelay;

    if (delta > 0)
        AddCoins(delta);
    else
        RemoveCoins(-delta);
    
    targetCoins = GetCoins();
    gTasks[taskId].data[1] = targetCoins;
    if (duration <= 0)
        gTasks[taskId].data[2] = 1;
    else
        gTasks[taskId].data[2] = max(1, abs((targetCoins - curCoins) / duration));
}

static void UpdateCoinDigitSprites(u8 taskId)
{
    int i;
    int coins;
    int currentCoins = gTasks[taskId].data[0];
    int targetCoins = gTasks[taskId].data[1];
    int delta = gTasks[taskId].data[2];
    int startDelay = gTasks[taskId].data[3];

    if (gTasks[taskId].data[4]++ < startDelay)
        return;

    if (startDelay > 0 && IsFanfareTaskInactive() && gTasks[taskId].data[4] % 3 == 0)
        PlaySE(SE_PIN);

    if (currentCoins < targetCoins)
    {
        currentCoins += delta;
        if (currentCoins > targetCoins)
            currentCoins = targetCoins;
    }
    else
    {
        currentCoins -= delta;
        if (currentCoins < targetCoins)
            currentCoins = targetCoins;
    }

    coins = currentCoins;
    for (i = 0; i < 4; i++)
    {
        int digit = coins % 10;
        coins /= 10;
        StartSpriteAnim(&gSprites[sCardFlip->coinDigitSpriteIds[i]], digit);
    }

    if (currentCoins == targetCoins)
        DestroyTask(taskId);
    else
        gTasks[taskId].data[0] = currentCoins;
}

static void StartExitCardFlip(void)
{
    BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
    sCardFlip->state = CARD_FLIP_STATE_EXIT;
}

static void ExitCardFlip(void)
{
    if (!gPaletteFade.active)
    {
        SetMainCallback2(sCardFlip->returnMainCallback);
        FREE_AND_SET_NULL(sCardFlip);
    }
}

static void ResetAndShuffleCardDeck(void)
{
    int i, suit;
    int cardIndex, swapIndex;
    u8 temp;

    for (i = 0; i < NUM_NUMBERS; i++)
    {
        for (suit = 0; suit < NUM_SUITS; suit++)
            sCardFlip->cardDeck[suit * NUM_NUMBERS + i] = CARD(i, suit);
    }

    // Swap the place of cards twice each.
    // This probably isn't the most sound shuffling algorithm, but
    // it's probably good enough.
    for (i = 0; i < NUM_CARDS * 2; i++)
    {
        cardIndex = i % NUM_CARDS;
        swapIndex = Random() % NUM_CARDS;
        temp = sCardFlip->cardDeck[cardIndex];
        sCardFlip->cardDeck[cardIndex] = sCardFlip->cardDeck[swapIndex];
        sCardFlip->cardDeck[swapIndex] = temp;
    }

    sCardFlip->deckTop = 0;

    ShowAllCardNumbers();
    ResetAllRoundCounters();
}

static void StartUIAnim(u8 taskId, s16 nextState)
{
    gTasks[taskId].data[0] = 1;
    gTasks[taskId].data[1] = nextState;
    sCardFlip->state = CARD_FLIP_WAIT_ANIM;
}

static void WaitForUIAnimToFinish(u8 taskId)
{
    s16 animRunning = gTasks[taskId].data[0];
    if (!animRunning)
    {
        s16 nextState = gTasks[taskId].data[1];
        gTasks[taskId].data[0] = 0;
        gTasks[taskId].data[1] = 0;
        sCardFlip->state = nextState;
    }
}

static void LoadCardBackGfx(void)
{
    struct CompressedSpriteSheet spriteSheet;
    struct SpritePalette spritePalette;

    spriteSheet.data = sCardBackGfx;
    spriteSheet.size = 0x800;
    spriteSheet.tag = TAG_CARD_BACK;
    LoadCompressedSpriteSheet(&spriteSheet);

    spritePalette.data = sCardBackPalette;
    spritePalette.tag = TAG_CARD_BACK;
    LoadSpritePalette(&spritePalette);
}

static void LoadCardSelectionGfx(void)
{
    struct CompressedSpriteSheet spriteSheet;
    struct SpritePalette spritePalette;

    spriteSheet.data = sCard_SelectionGfx;
    spriteSheet.size = 0x800;
    spriteSheet.tag = TAG_CARD_SELECTION;
    LoadCompressedSpriteSheet(&spriteSheet);

    spritePalette.data = sCard_SelectionPalette;
    spritePalette.tag = TAG_CARD_SELECTION;
    LoadSpritePalette(&spritePalette);
}

static void LoadCardGfx(int cardId)
{
    struct CompressedSpriteSheet spriteSheet;
    struct SpritePalette spritePalette;

    spriteSheet.data = sCardSpriteGfx[cardId];
    spriteSheet.size = 0x800;
    spriteSheet.tag = TAG_CARD_FRONT;
    LoadCompressedSpriteSheet(&spriteSheet);

    spritePalette.data = sCardSpritePalettes[cardId];
    spritePalette.tag = TAG_CARD_FRONT;
    LoadSpritePalette(&spritePalette);
}

static void CardEntry_SpriteCallback(struct Sprite *sprite)
{
    sprite->x += 5;
    if (sprite->x >= 48)
    {
        sprite->x = 48;
        // Signal that the UI animation is complete.
        gTasks[sprite->data[0]].data[0] = 0;
        sprite->callback = SpriteCallbackDummy;
    }
}

static void ChooseCard_SpriteCallback(struct Sprite *sprite)
{
    s16 selectedCard;
    s16 otherCard;

    switch (sprite->data[7])
    {
    case 0:
        if (JOY_NEW(A_BUTTON))
        {
            DestroyTask(sCardFlip->cardSelectionSoundTaskId);
            PlaySE(SE_USE_ITEM);
            selectedCard = sprite->data[1];
            otherCard = (selectedCard + 1) % 2;
            DestroySprite(&gSprites[sCardFlip->cardBackSpriteIds[otherCard]]);
            sprite->data[7] = 1;
            sprite->data[2] = 0;
            sCardFlip->selectedCardIndex = selectedCard;
            break;
        }

        if ((++sprite->data[2]) % 5 == 0)
        {
            sprite->data[1] ^= 1;
            if (sprite->data[1] == 0)
                sprite->y = 61;
            else
                sprite->y = 123;
            PlaySE(SE_BALL_BOUNCE_4);
        }
        break;
    case 1:
        // Blink for a few frames.
        if (++sprite->data[2] > 40)
        {
            if (sCardFlip->selectedCardIndex == 1)
            {
                u8 spriteId = sCardFlip->cardBackSpriteIds[sCardFlip->selectedCardIndex];
                gSprites[spriteId].callback = SlideBottomCardUp;
                gSprites[spriteId].data[0] = sprite->data[0];
            }
            else
            {
                // Signal that the UI animation is complete.
                ShowHelpBar(sHelpBar_BetPlace);
                DrawBetType(sCardFlip->betType);
                gTasks[sprite->data[0]].data[0] = 0;
            }

            DestroySprite(sprite);
        }
        else
        {
            if (sprite->data[2] % 3 == 0)
                sprite->invisible ^= 1;
        }
        break;
    }
}

static void SlideBottomCardUp(struct Sprite *sprite)
{
    sprite->y -= 8;
    if (sprite->y <= 61)
    {
        // Signal that the UI animation is complete.
        ShowHelpBar(sHelpBar_BetPlace);
        DrawBetType(sCardFlip->betType);
        gTasks[sprite->data[0]].data[0] = 0;
        sprite->y = 61;
        sprite->callback = SpriteCallbackDummy;
    }
}

static void SlideOutCard(struct Sprite *sprite)
{
    sprite->x -= 5;
    if (sprite->x <= -32)
    {
        // Signal that the UI animation is complete.            
        gTasks[sprite->data[0]].data[0] = 0;
        DestroySpriteAndFreeResources(sprite);
    }
}

static void FlipOverCardStart(struct Sprite *sprite)
{
    u8 card;
    struct Sprite *newSprite;

    if (sprite->affineAnimEnded)
    {
        // Randomly choose one of the top two cards.  The actual card the player
        // selected does not matter.
        card = sCardFlip->cardDeck[sCardFlip->deckTop + (Random() & 1)];
        sCardFlip->deckTop += 2; // Two cards were drawn fromm the deck.
        sCardFlip->drawnCard = card;
        LoadCardGfx(CARD_ID(card));

        sCardFlip->cardFrontSpriteId = CreateSprite(&sCardFrontSpriteTemplate, 48, 61, 3);
        newSprite = &gSprites[sCardFlip->cardFrontSpriteId];
        // Hack--make sprite invisible for one frame, because affine animation
        // sometimes doesn't immediately take aeffect. Not sure why.
        newSprite->invisible = 1;
        newSprite->callback = FlipOverCardEnd;
        newSprite->oam.affineMode = ST_OAM_AFFINE_NORMAL;
        newSprite->data[0] = sprite->data[0];
        StartSpriteAffineAnim(newSprite, 1);
        FreeSpriteOamMatrix(sprite);
        DestroySprite(sprite);
    }
}

static void FlipOverCardEnd(struct Sprite *sprite)
{
    u8 wonBet;
    struct Sprite *numberSprite;

    sprite->invisible = 0; // See above invisibility hack in FlipOverCardStart().
    if (sprite->affineAnimEnded)
    {
        wonBet = sBetTypeCards[sCardFlip->betType][CARD_ID(sCardFlip->drawnCard)];
        if (wonBet)
            AwardCoins();
        else
            PlayFanfare(MUS_TOO_BAD);

        numberSprite = &gSprites[sCardFlip->cardNumberSpriteIds[CARD_ID(sCardFlip->drawnCard)]];
        numberSprite->oam.affineMode = ST_OAM_AFFINE_DOUBLE;
        CalcCenterToCornerVec(numberSprite, numberSprite->oam.shape, numberSprite->oam.size, numberSprite->oam.affineMode);
        StartSpriteAffineAnim(numberSprite, 0);
        numberSprite->callback = HighlightCardNumber;

        // Signal that the UI animation is complete.
        gTasks[sprite->data[0]].data[0] = 0;
        sprite->oam.affineMode = ST_OAM_AFFINE_OFF;
        sprite->callback = SpriteCallbackDummy;
    }
}

static void ShowHelpBar(const u8 *str)
{
    const u8 color[3] = { 15, 1, 2 };

    FillWindowPixelBuffer(WIN_HELP, 0xFF);
    AddTextPrinterParameterized3(WIN_HELP, 0, GetStringRightAlignXOffset(0, str, 120) - 4, 0, color, 0, str);
    PutWindowTilemap(WIN_HELP);
    CopyWindowToVram(WIN_HELP, 3);
}

static void HighlightCardNumber(struct Sprite *sprite)
{
    if (IsFanfareTaskInactive())
    {
        sprite->oam.affineMode = ST_OAM_AFFINE_OFF;
        FreeSpriteOamMatrix(sprite);
        CalcCenterToCornerVec(sprite, sprite->oam.shape, sprite->oam.size, sprite->oam.affineMode);
        sprite->callback = SpriteCallbackDummy;
    }
}

#undef CARD_FLIP_BG_TEXT
#undef CARD_FLIP_BG_BET_OUTLINE
#undef CARD_FLIP_BG_BASE
#undef WIN_TEXT
#undef TAG_COIN_DIGIT
#undef TAG_CARD_NUMBER
#undef TAG_CARD_FRONT
#undef TAG_CARD_2
#undef TAG_CARD_BACK
#undef TAG_CARD_SELECTION
#undef TAG_BET_OUTLINE_HORIZONTAL
#undef TAG_BET_OUTLINE_VERTICAL
#undef TAG_BET_OUTLINE_VERTICAL_SMALL
#undef TAG_ROUND_COUNTERS
#undef NUM_NUMBERS
#undef NUM_SUITS
#undef NUM_CARDS
#undef CARD
#undef CARD_ID
#undef CARD_NUMBER
#undef CARD_SUIT
