#include "global.h"
#include "main.h"
#include "battle.h"
#include "battle_anim.h"
#include "frontier_util.h"
#include "battle_message.h"
#include "battle_tent.h"
#include "battle_factory.h"
#include "bg.h"
#include "contest.h"
#include "contest_effect.h"
#include "data.h"
#include "daycare.h"
#include "decompress.h"
#include "dynamic_placeholder_text_util.h"
#include "event_data.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "international_string_util.h"
#include "item.h"
#include "link.h"
#include "m4a.h"
#include "malloc.h"
#include "menu.h"
#include "menu_helpers.h"
#include "mon_markings.h"
#include "party_menu.h"
#include "palette.h"
#include "pokeball.h"
#include "pokemon.h"
#include "pokemon_storage_system.h"
#include "pokemon_summary_screen.h"
#include "region_map.h"
#include "scanline_effect.h"
#include "sound.h"
#include "sprite.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "text.h"
#include "tv.h"
#include "window.h"
#include "constants/items.h"
#include "constants/layouts.h"
#include "constants/moves.h"
#include "constants/party_menu.h"
#include "constants/region_map_sections.h"
#include "constants/rgb.h"
#include "constants/songs.h"
#include "item_icon.h"
#include "pokemon_icon.h"
#include "constants/flags.h"
#include "battle_interface.h"

// Config options - should be changed to a flag
#define CONFIG_CONTEST_MOVES_ENABLED TRUE

enum {
    PSS_PAGE_INFO,
    PSS_PAGE_SKILLS,
    PSS_PAGE_BATTLE_MOVES,
    PSS_PAGE_CONTEST_MOVES,
    PSS_PAGE_COUNT,
};

enum {
    PP_SOME,
    PP_FEW,
    PP_NO_PP,
    PP_MANY
};

// Text Windows
enum
{
    WINDOW_ARR_ID_TITLE_BAR,
    WINDOW_ARR_ID_LVL_NICK_GENDER,
    WINDOW_ARR_ID_BEGIN_TRANSIENT,

    WINDOW_ARR_ID_INFO_RIGHT = WINDOW_ARR_ID_BEGIN_TRANSIENT,
    WINDOW_ARR_ID_INFO_MEMO,

    WINDOW_ARR_ID_SKILLS_RIGHT,
    WINDOW_ARR_ID_SKILLS_EXP_NEXT_ABILITY_NAME,
    WINDOW_ARR_ID_SKILLS_ABILITY_TEXT,

    WINDOW_ARR_ID_MOVES_WINDOW_TOP_FOUR_MOVES,
    WINDOW_ARR_ID_MOVES_WINDOW_LAST_MOVE,
    WINDOW_ARR_ID_MOVES_WINDOW_LEFT,

    WINDOW_ARR_ID_COUNT
};

#define MOVE_SELECTOR_SPRITES_COUNT 15
#define HP_BAR_SPRITES_COUNT        9
#define EXP_BAR_SPRITES_COUNT       11

// for the spriteIds field in PokemonSummaryScreenData
enum
{
    SPRITE_ARR_ID_MON,
    SPRITE_ARR_ID_BALL,
    SPRITE_ARR_ID_STATUS,
    SPRITE_ARR_ID_SHINY_ICON,
    SPRITE_ARR_ID_BEGIN_TRANSIENT,

    SPRITE_ARR_ID_MON_ICON = SPRITE_ARR_ID_BEGIN_TRANSIENT,
    SPRITE_ARR_ID_TYPE, // 2 for mon types, 5 for move types(4 moves and 1 to learn)
    SPRITE_ARR_ID_MOVE_SELECTOR1 = SPRITE_ARR_ID_TYPE + 7,
    SPRITE_ARR_ID_MOVE_SELECTOR2 = SPRITE_ARR_ID_MOVE_SELECTOR1 + MOVE_SELECTOR_SPRITES_COUNT,
    SPRITE_ARR_ID_COUNT = SPRITE_ARR_ID_MOVE_SELECTOR2 + MOVE_SELECTOR_SPRITES_COUNT
};

#define TILE_EMPTY_HEART            93
#define TILE_EMPTY_HEART_2         109
#define TILE_EMPTY_HEART_3         125
#define TILE_EMPTY_HEART_4         141
#define TILE_FILLED_APPEAL_HEART    94
#define TILE_FILLED_APPEAL_HEART_2 110
#define TILE_FILLED_JAM_HEART      127
#define TILE_FILLED_JAM_HEART_2    143

#define POWER_AND_ACCURACY_Y    9
#define POWER_AND_ACCURACY_Y_2  POWER_AND_ACCURACY_Y + 14

static EWRAM_DATA struct PokemonSummaryScreenData
{
    /*0x00*/ union {
        struct Pokemon *mons;
        struct BoxPokemon *boxMons;
    } monList;
    /*0x04*/ MainCallback callback;
    /*0x08*/ struct Sprite *markingsSprite;
    /*0x0C*/ struct Pokemon currentMon;
    /*0x70*/ struct PokeSummary
    {
        u16 species;
        u16 species2;
        u8 isEgg:1; // 0x4
        u8 locationBit:1;
        u8 filler:6;
        u8 level;
        u8 ribbonCount;
        u8 ailment;
        u8 abilityNum;
        u8 metLocation;
        u8 metLevel;
        u8 metGame;
        u32 pid;
        u32 exp;
        u16 moves[MAX_MON_MOVES];
        u8 pp[MAX_MON_MOVES];
        u16 currentHP;
        u16 maxHP;
        u16 atk;
        u16 def;
        u16 spatk;
        u16 spdef;
        u16 speed;
        u16 item;
        u8 friendship;
        u8 OTGender;
        u8 nature;
        u8 ppBonuses;
        u8 sanity;
        bool8 fatefulEncounter;
        u8 OTName[17];
        u32 OTID;
    } summary;
    u16 bgTilemapBufferPage[0x400];
    u16 bgTilemapBufferBG[0x400];
    u16 moveDetailTilemapBuffer[0x800];
    u8 mode;
    bool8 isBoxMon;
    bool8 lastWasEgg;
    u8 curMonIndex;
    u8 maxMonIndex;
    u8 currPageIndex;
    u8 minPageIndex;
    u8 maxPageIndex;
    u8 trueMinPageIndex;
    u8 trueMaxPageIndex;
    u8 currStatIndex;
    bool8 lockMonFlag; // This is used to prevent the player from changing pokemon in the move deleter select, etc, but it is not needed because the input is handled differently there
    bool8 lockMovesFlag; // This is used to prevent the player from changing position of moves in a battle or when trading.
    u8 firstMoveIndex;
    u8 secondMoveIndex;
    u16 newMove;
    u8 spriteIds[SPRITE_ARR_ID_COUNT];
    bool8 unk40EF;
    s16 switchCounter; // Used for various switch statement cases that decompress/load graphics or pokemon data
} *sMonSummaryScreen = NULL;

EWRAM_DATA u8 gLastViewedMonIndex = 0;
static EWRAM_DATA u8 sMoveSlotToReplace = 0;
ALIGNED(4) static EWRAM_DATA u8 sAnimDelayTaskId = 0;

static EWRAM_DATA struct HealthBar
{
    struct Sprite *sprites[HP_BAR_SPRITES_COUNT];
    u16 spritePositions[HP_BAR_SPRITES_COUNT];
    u16 tileTag;
    u16 palTag;
} *sHealthBar = NULL;

static EWRAM_DATA struct ExpBar
{
    struct Sprite *sprites[EXP_BAR_SPRITES_COUNT];
    u16 spritePositions[EXP_BAR_SPRITES_COUNT];
    u16 tileTag;
    u16 palTag;
} *sExpBar = NULL;

// forward declarations
static bool8 LoadGraphics(void);
static void CB2_InitSummaryScreen(void);
static void InitBGs(void);
static bool8 DecompressGraphics(void);
static void CopyMonToSummaryStruct(struct Pokemon* a);
static bool8 ExtractMonDataToSummaryStruct(struct Pokemon* a);
static void UpdateInfoPageType(void);
static void CloseSummaryScreen(u8 taskId);
static void Task_HandleInput(u8 taskId);
static void ChangeSummaryPokemon(u8 taskId, s8 a);
static void Task_ChangeSummaryMon(u8 taskId);
static s8 AdvanceMonIndex(s8 delta);
static s8 AdvanceMultiBattleMonIndex(s8 delta);
static bool8 IsValidToViewInMulti(struct Pokemon* mon);
static void ChangePage(u8 taskId, s8 a);
static void ChangePageTask(u8 taskId);
static void SwitchToMoveSelection(u8 taskId);
static void Task_SwitchToMoveDetails(u8 taskId);
static void Task_HandleInput_MoveSelect(u8 taskId);
static void Task_SwitchPageInMoveSelect(u8 taskId);
static bool8 HasMoreThanOneMove(void);
static void ChangeSelectedMove(s16 *taskData, s8 direction, u8 *moveIndexPtr);
static void CloseMoveSelectMode(u8 taskId);
static void Task_SwitchFromMoveDetails(u8 taskId);
static void SwitchToMovePositionSwitchMode(u8 a);
static void Task_HandleInput_MovePositionSwitch(u8 taskId);
static void ExitMovePositionSwitchMode(u8 taskId, bool8 swapMoves);
static void SwapMonMoves(struct Pokemon *mon, u8 moveIndex1, u8 moveIndex2);
static void SwapBoxMonMoves(struct BoxPokemon *mon, u8 moveIndex1, u8 moveIndex2);
static void Task_SetHandleReplaceMoveInput(u8 taskId);
static void Task_HandleReplaceMoveInput(u8 taskId);
static void Task_SwitchPageInReplaceMove(u8 taskId);
static bool8 CanReplaceMove(void);
static void ShowCantForgetHMs(u8 taskId);
static void DrawPagination(bool8 currentPagePressed);
static void SetMonPicBackgroundPalette(bool8 isMonShiny);
static void SetSmallMonPicBackgroundPalette(void);
static void PrintMonInfo(bool8 smallWindow);
static void RemoveWindowByIndex(u8 a);
static void PrintPageSpecificText(u8 a);
static void PrintInfoPage(void);
static void PrintInfoPageEgg(void);
static void PrintInfoPageMon(void);
static void BufferMonTrainerMemo(void);
static void BufferNatureString(void);
static void GetMetLevelString(u8 *a);
static bool8 DoesMonOTMatchOwner(void);
static bool8 DidMonComeFromOfficialGBAGames(void);
static bool8 DidMonComeFromCrystalDust(void);
static bool8 DidMonComeFromAnyGBAGame(void);
static bool8 DidMonComeFromRSE(void);
static bool8 DidMonComeFromFRLG(void);
static bool8 DidMonComeFromCD(void);
static bool8 IsInGamePartnerMon(void);
static void BufferEggMemo(void);
static void PrintSkillsPage(void);
static void PrintBattleMoves(void);
static void PrintMoveNameAndPP(u8 a);
static void PrintContestMoves(void);
static void PrintMoveDetails(u16 a);
static void PrintNewMoveDetailsOrCancelText(void);
static void SwapMovesNamesPP(u8 moveIndex1, u8 moveIndex2);
static void ResetSpriteIds(void);
static void SetSpriteInvisibility(u8 spriteArrayId, bool8 invisible);
static void HidePageSpecificSprites(void);
static void SetTypeIcons(void);
static void CreateMoveTypeIcons(void);
static void SetMonTypeIcons(void);
static void SetMoveTypeIcons(void);
static void SetContestMoveTypeIcons(void);
static void SetNewMoveTypeIcon(void);
static void SwapMovesTypeSprites(u8 moveIndex1, u8 moveIndex2);
static u8 LoadMonGfxAndSprite(struct Pokemon *a, s16 *b);
static u8 CreateMonSprite(struct Pokemon *unused);
static void SpriteCB_Pokemon(struct Sprite *);
static void StopPokemonAnimations(void);
static void CreateMonMarkingsSprite(struct Pokemon *mon);
static void RemoveAndCreateMonMarkingsSprite(struct Pokemon *mon);
static void CreateCaughtBallSprite(struct Pokemon *mon);
static void CreateSetStatusSprite(void);
static void CreateMoveSelectorSprites(u8 idArrayStart);
static void SpriteCb_MoveSelector(struct Sprite *sprite);
static void DestroyMoveSelectorSprites(u8 firstArrayId);
static void SetMainMoveSelectorColor(u8 whichColor);
static void KeepMoveSelectorVisible(u8 firstSpriteId);
static void SummaryScreen_DestroyAnimDelayTask(void);
static void CreateUpdateShinyIconSprite(bool8 smallWindow);
static void DestroyShinyIconSprite(void);
static void CreateHealthBarSprites(u16 tileTag, u16 palTag);
static void ConfigureHealthBarSprites(void);
static void DestroyHealthBarSprites(void);
static void SetHealthBarSprites(void);
static void CreateExpBarSprites(u16 tileTag, u16 palTag);
static void ConfigureExpBarSprites(void);
static void DestroyExpBarSprites(void);
static void SetExpBarSprites(void);
static void PrintTitleBar(u8 pageIndex, bool8 detailsShown);

// const rom data
#include "data/text/move_descriptions.h"
#include "data/text/nature_names.h"

static const struct BgTemplate sBgTemplates[] =
{
    {
        .bg = 0,
        .charBaseIndex = 0,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0,
    },
    {
        .bg = 1,
        .charBaseIndex = 2,
        .mapBaseIndex = 27,
        .screenSize = 1,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0,
    },
    {
        .bg = 2,
        .charBaseIndex = 2,
        .mapBaseIndex = 25,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0,
    },
    {
        .bg = 3,
        .charBaseIndex = 2,
        .mapBaseIndex = 29,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 3,
        .baseTile = 0,
    },
};

static const s8 sMultiBattleOrder[] = {0, 2, 3, 1, 4, 5};

static const struct WindowTemplate sSummaryTemplate[] =
{
    [WINDOW_ARR_ID_TITLE_BAR] = {
        .bg = 0,
        .tilemapLeft = 0,
        .tilemapTop = 0,
        .width = 30,
        .height = 2,
        .paletteNum = 8,
        .baseBlock = 1,
    },
    [WINDOW_ARR_ID_LVL_NICK_GENDER] = {
        .bg = 0,
        .tilemapLeft = 0,
        .tilemapTop = 2,
        .width = 15,
        .height = 2,
        .paletteNum = 8,
        .baseBlock = 61,
    },

    [WINDOW_ARR_ID_INFO_RIGHT] = {
        .bg = 0,
        .tilemapLeft = 15,
        .tilemapTop = 2,
        .width = 15,
        .height = 12,
        .paletteNum = 8,
        .baseBlock = 91,
    },
    [WINDOW_ARR_ID_INFO_MEMO] = {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 14,
        .width = 28,
        .height = 6,
        .paletteNum = 8,
        .baseBlock = 271,
    },

    [WINDOW_ARR_ID_SKILLS_RIGHT] = {
        .bg = 0,
        .tilemapLeft = 21,
        .tilemapTop = 2,
        .width = 9,
        .height = 14,
        .paletteNum = 8,
        .baseBlock = 91,
    },
    [WINDOW_ARR_ID_SKILLS_EXP_NEXT_ABILITY_NAME] = {
        .bg = 0,
        .tilemapLeft = 9,
        .tilemapTop = 12,
        .width = 9,
        .height = 4,
        .paletteNum = 8,
        .baseBlock = 217,
    },
    [WINDOW_ARR_ID_SKILLS_ABILITY_TEXT] = {
        .bg = 0,
        .tilemapLeft = 0,
        .tilemapTop = 16,
        .width = 30,
        .height = 4,
        .paletteNum = 8,
        .baseBlock = 253,
    },

    [WINDOW_ARR_ID_MOVES_WINDOW_TOP_FOUR_MOVES] = {
        .bg = 0,
        .tilemapLeft = 20,
        .tilemapTop = 2,
        .width = 10,
        .height = 14,
        .paletteNum = 9,
        .baseBlock = 91,
    },
    [WINDOW_ARR_ID_MOVES_WINDOW_LAST_MOVE] = {
        .bg = 0,
        .tilemapLeft = 20,
        .tilemapTop = 16,
        .width = 10,
        .height = 4,
        .paletteNum = 9,
        .baseBlock = 231,
    },
    [WINDOW_ARR_ID_MOVES_WINDOW_LEFT] = {
        .bg = 0,
        .tilemapLeft = 0,
        .tilemapTop = 6,
        .width = 16,
        .height = 14,
        .paletteNum = 8,
        .baseBlock = 271,
    },

    [WINDOW_ARR_ID_COUNT] = DUMMY_WIN_TEMPLATE
};

enum
{
    PSS_COLOR_WHITE_BLACK_SHADOW,
    PSS_COLOR_BLACK_GRAY_SHADOW,
    PSS_COLOR_PP_MANY,
    PSS_COLOR_PP_SOME,
    PSS_COLOR_PP_FEW,
    PSS_COLOR_PP_NO_PP,
    PSS_COLOR_FEMALE_GENDER_SYMBOL,
    PSS_COLOR_MALE_GENDER_SYMBOL,
};

static const u8 sTextColors[][3] =
{
    [PSS_COLOR_WHITE_BLACK_SHADOW]   = {0, 1, 2},
    [PSS_COLOR_BLACK_GRAY_SHADOW]    = {0, 3, 5},
    [PSS_COLOR_PP_MANY]              = {0, 3, 5},
    [PSS_COLOR_PP_SOME]              = {0, 6, 7},
    [PSS_COLOR_PP_FEW]               = {0, 8, 9},
    [PSS_COLOR_PP_NO_PP]             = {0, 10, 11},
    [PSS_COLOR_FEMALE_GENDER_SYMBOL] = {0, 12, 13},
    [PSS_COLOR_MALE_GENDER_SYMBOL]   = {0, 14, 15}
};

static void (*const sTextPrinterFunctions[])(void) =
{
    [PSS_PAGE_INFO] = PrintInfoPage,
    [PSS_PAGE_SKILLS] = PrintSkillsPage,
    [PSS_PAGE_BATTLE_MOVES] = PrintBattleMoves,
    [PSS_PAGE_CONTEST_MOVES] = PrintContestMoves
};

static const u8 sBlackTextColor[] = _("{COLOR 3}{SHADOW 5}");

enum
{
    TAG_MOVE_SELECTOR = 30000,
    TAG_MON_STATUS,
    TAG_SHINY_ICON,
    TAG_MOVE_TYPES,
    TAG_MON_MARKINGS,
    TAG_SPLIT_ICONS,
    TAG_EXP_BAR,
    TAG_HEALTH_BAR,
};

static const struct OamData sOamData_MoveTypes =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = 0,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x16),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(32x16),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0,
};
static const union AnimCmd sSpriteAnim_TypeNormal[] = {
    ANIMCMD_FRAME(TYPE_NORMAL * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TypeFighting[] = {
    ANIMCMD_FRAME(TYPE_FIGHTING * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TypeFlying[] = {
    ANIMCMD_FRAME(TYPE_FLYING * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TypePoison[] = {
    ANIMCMD_FRAME(TYPE_POISON * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TypeGround[] = {
    ANIMCMD_FRAME(TYPE_GROUND * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TypeRock[] = {
    ANIMCMD_FRAME(TYPE_ROCK * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TypeBug[] = {
    ANIMCMD_FRAME(TYPE_BUG * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TypeGhost[] = {
    ANIMCMD_FRAME(TYPE_GHOST * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TypeSteel[] = {
    ANIMCMD_FRAME(TYPE_STEEL * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TypeMystery[] = {
    ANIMCMD_FRAME(TYPE_MYSTERY * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TypeFire[] = {
    ANIMCMD_FRAME(TYPE_FIRE * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TypeWater[] = {
    ANIMCMD_FRAME(TYPE_WATER * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TypeGrass[] = {
    ANIMCMD_FRAME(TYPE_GRASS * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TypeElectric[] = {
    ANIMCMD_FRAME(TYPE_ELECTRIC * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TypePsychic[] = {
    ANIMCMD_FRAME(TYPE_PSYCHIC * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TypeIce[] = {
    ANIMCMD_FRAME(TYPE_ICE * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TypeDragon[] = {
    ANIMCMD_FRAME(TYPE_DRAGON * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TypeDark[] = {
    ANIMCMD_FRAME(TYPE_DARK * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_CategoryCool[] = {
    ANIMCMD_FRAME((CONTEST_CATEGORY_COOL + NUMBER_OF_MON_TYPES) * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_CategoryBeauty[] = {
    ANIMCMD_FRAME((CONTEST_CATEGORY_BEAUTY + NUMBER_OF_MON_TYPES) * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_CategoryCute[] = {
    ANIMCMD_FRAME((CONTEST_CATEGORY_CUTE + NUMBER_OF_MON_TYPES) * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_CategorySmart[] = {
    ANIMCMD_FRAME((CONTEST_CATEGORY_SMART + NUMBER_OF_MON_TYPES) * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_CategoryTough[] = {
    ANIMCMD_FRAME((CONTEST_CATEGORY_TOUGH + NUMBER_OF_MON_TYPES) * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd *const sSpriteAnimTable_MoveTypes[NUMBER_OF_MON_TYPES + CONTEST_CATEGORIES_COUNT] = {
    sSpriteAnim_TypeNormal,
    sSpriteAnim_TypeFighting,
    sSpriteAnim_TypeFlying,
    sSpriteAnim_TypePoison,
    sSpriteAnim_TypeGround,
    sSpriteAnim_TypeRock,
    sSpriteAnim_TypeBug,
    sSpriteAnim_TypeGhost,
    sSpriteAnim_TypeSteel,
    sSpriteAnim_TypeMystery,
    sSpriteAnim_TypeFire,
    sSpriteAnim_TypeWater,
    sSpriteAnim_TypeGrass,
    sSpriteAnim_TypeElectric,
    sSpriteAnim_TypePsychic,
    sSpriteAnim_TypeIce,
    sSpriteAnim_TypeDragon,
    sSpriteAnim_TypeDark,
    sSpriteAnim_CategoryCool,
    sSpriteAnim_CategoryBeauty,
    sSpriteAnim_CategoryCute,
    sSpriteAnim_CategorySmart,
    sSpriteAnim_CategoryTough,
};
static const struct CompressedSpriteSheet sSpriteSheet_MoveTypes =
{
    .data = gMoveTypes_Gfx,
    .size = (NUMBER_OF_MON_TYPES + CONTEST_CATEGORIES_COUNT) * 0x100,
    .tag = TAG_MOVE_TYPES
};
static const struct SpriteTemplate sSpriteTemplate_MoveTypes =
{
    .tileTag = TAG_MOVE_TYPES,
    .paletteTag = TAG_MOVE_TYPES,
    .oam = &sOamData_MoveTypes,
    .anims = sSpriteAnimTable_MoveTypes,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};
static const struct OamData sOamData_MoveSelector =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = 0,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(8x32),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(8x32),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0,
};
static const union AnimCmd sSpriteAnim_MoveSelectorLeftRed[] = {
    ANIMCMD_FRAME(0, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_MoveSelectorCenterRed[] = {
    ANIMCMD_FRAME(8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_MoveSelectorRightRed[] = {
    ANIMCMD_FRAME(0, 0, TRUE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_MoveSelectorLeftWhite[] = {
    ANIMCMD_FRAME(4, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_MoveSelectorCenterWhite[] = {
    ANIMCMD_FRAME(12, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_MoveSelectorRightWhite[] = {
    ANIMCMD_FRAME(4, 0, TRUE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd *const sSpriteAnimTable_MoveSelector[] = {
    sSpriteAnim_MoveSelectorLeftRed,
    sSpriteAnim_MoveSelectorCenterRed,
    sSpriteAnim_MoveSelectorRightRed,
    sSpriteAnim_MoveSelectorLeftWhite,
    sSpriteAnim_MoveSelectorCenterWhite,
    sSpriteAnim_MoveSelectorRightWhite
};
static const struct CompressedSpriteSheet sMoveSelectorSpriteSheet =
{
    .data = gSummaryMoveSelect_Gfx,
    .size = 0x800,
    .tag = TAG_MOVE_SELECTOR
};
static const struct CompressedSpritePalette sMoveSelectorSpritePal =
{
    .data = gSummaryMoveSelect_Pal,
    .tag = TAG_MOVE_SELECTOR
};
static const struct SpriteTemplate sMoveSelectorSpriteTemplate =
{
    .tileTag = TAG_MOVE_SELECTOR,
    .paletteTag = TAG_MOVE_SELECTOR,
    .oam = &sOamData_MoveSelector,
    .anims = sSpriteAnimTable_MoveSelector,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct OamData sOamData_StatusCondition =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = 0,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x8),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(32x8),
    .tileNum = 0,
    .priority = 3,
    .paletteNum = 0,
    .affineParam = 0,
};
static const union AnimCmd sSpriteAnim_StatusPoison[] = {
    ANIMCMD_FRAME(0, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_StatusParalyzed[] = {
    ANIMCMD_FRAME(4, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_StatusSleep[] = {
    ANIMCMD_FRAME(8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_StatusFrozen[] = {
    ANIMCMD_FRAME(12, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_StatusBurn[] = {
    ANIMCMD_FRAME(16, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_StatusPokerus[] = {
    ANIMCMD_FRAME(20, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_StatusFaint[] = {
    ANIMCMD_FRAME(24, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd *const sSpriteAnimTable_StatusCondition[] = {
    sSpriteAnim_StatusPoison,
    sSpriteAnim_StatusParalyzed,
    sSpriteAnim_StatusSleep,
    sSpriteAnim_StatusFrozen,
    sSpriteAnim_StatusBurn,
    sSpriteAnim_StatusPokerus,
    sSpriteAnim_StatusFaint,
};
static const struct CompressedSpriteSheet sStatusIconsSpriteSheet =
{
    .data = gStatusGfx_Icons,
    .size = 0x380,
    .tag = TAG_MON_STATUS
};
static const struct CompressedSpritePalette sStatusIconsSpritePalette =
{
    .data = gStatusPal_Icons,
    .tag = TAG_MON_STATUS
};
static const struct SpriteTemplate sSpriteTemplate_StatusCondition =
{
    .tileTag = TAG_MON_STATUS,
    .paletteTag = TAG_MON_STATUS,
    .oam = &sOamData_StatusCondition,
    .anims = sSpriteAnimTable_StatusCondition,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct OamData sOamData_ShinyIcon =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(8x8),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(8x8),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0
};
static const union AnimCmd sSpriteAnim_ShinyIcon[] =
{
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_JUMP(0),
};
static const union AnimCmd *const sSpriteAnimTable_ShinyIcon[] =
{
    sSpriteAnim_ShinyIcon
};
static const struct SpritePalette sShinyIconSpritePalette =
{
    .data = gShinyIcon_Pal,
    .tag = TAG_SHINY_ICON
};
static const struct SpriteTemplate sSpriteTemplate_ShinyIcon = {
    .tileTag = TAG_SHINY_ICON,
    .paletteTag = TAG_SHINY_ICON,
    .oam = &sOamData_ShinyIcon,
    .anims = sSpriteAnimTable_ShinyIcon,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const u16 sSummaryMarkings_Pal[] = INCBIN_U16("graphics/summary_screen/markings.gbapal");

static const struct OamData sOamData_ExpHealthBars = {
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(8x8),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(8x8),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0
};

static const union AnimCmd sSpriteAnim_ExpHealthBarDivisionEmpty[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sSpriteAnim_ExpHealthBarDivision1[] =
{
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sSpriteAnim_ExpHealthBarDivision2[] =
{
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sSpriteAnim_ExpHealthBarDivision3[] =
{
    ANIMCMD_FRAME(3, 20),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sSpriteAnim_ExpHealthBarDivision4[] =
{
    ANIMCMD_FRAME(4, 20),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sSpriteAnim_ExpHealthBarDivision5[] =
{
    ANIMCMD_FRAME(5, 20),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sSpriteAnim_ExpHealthBarDivision6[] =
{
    ANIMCMD_FRAME(6, 20),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sSpriteAnim_ExpHealthBarDivision7[] =
{
    ANIMCMD_FRAME(7, 20),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sSpriteAnim_ExpHealthBarDivisionFull[] =
{
    ANIMCMD_FRAME(8, 20),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sSpriteAnim_ExpHealthBarNameLeft[] =
{
    ANIMCMD_FRAME(9, 20),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sSpriteAnim_ExpHealthBarNameRight[] =
{
    ANIMCMD_FRAME(10, 20),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sSpriteAnim_ExpHealthBarEnd[] =
{
    ANIMCMD_FRAME(11, 20),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd * const sSpriteAnimTable_ExpHealthBars[] =
{
    sSpriteAnim_ExpHealthBarDivisionEmpty,
    sSpriteAnim_ExpHealthBarDivision1,
    sSpriteAnim_ExpHealthBarDivision2,
    sSpriteAnim_ExpHealthBarDivision3,
    sSpriteAnim_ExpHealthBarDivision4,
    sSpriteAnim_ExpHealthBarDivision5,
    sSpriteAnim_ExpHealthBarDivision6,
    sSpriteAnim_ExpHealthBarDivision7,
    sSpriteAnim_ExpHealthBarDivisionFull,
    sSpriteAnim_ExpHealthBarNameLeft,
    sSpriteAnim_ExpHealthBarNameRight,
    sSpriteAnim_ExpHealthBarEnd
};

static const u32 * const sPageTilemaps[] =
{
    gSummaryScreenPageInfoTilemap,
    gSummaryScreenPageSkillsTilemap,
    gSummaryScreenPageMovesTilemap,
    gSummaryScreenPageContestMovesTilemap,
};

const u8 sText_PP[] = _("PP");
const u8 sText_TitlePageCancel[] = _("{DPAD_RIGHT}PAGE {A_BUTTON}CANCEL");
const u8 sText_TitlePage[] = _("{DPAD_LEFTRIGHT}PAGE");
const u8 sText_TitlePageDetailL[] = _("{DPAD_LEFT}PAGE {A_BUTTON}DETAIL");
const u8 sText_TitlePageDetailLR[] = _("{DPAD_LEFTRIGHT}PAGE {A_BUTTON}DETAIL");
const u8 sText_TitlePickSwitch[] = _("{DPAD_UPDOWN}PICK {A_BUTTON}SWITCH");

// code
void ShowPokemonSummaryScreen(u8 mode, void *mons, u8 monIndex, u8 maxMonIndex, void (*callback)(void))
{
    sMonSummaryScreen = AllocZeroed(sizeof(*sMonSummaryScreen));
    sMonSummaryScreen->mode = mode;
    sMonSummaryScreen->monList.mons = mons;
    sMonSummaryScreen->curMonIndex = monIndex;
    sMonSummaryScreen->maxMonIndex = maxMonIndex;
    sMonSummaryScreen->callback = callback;

    if (mode == SUMMARY_MODE_BOX)
        sMonSummaryScreen->isBoxMon = TRUE;
    else
        sMonSummaryScreen->isBoxMon = FALSE;

    switch (mode)
    {
    case SUMMARY_MODE_LOCK_MOVES:
        sMonSummaryScreen->lockMovesFlag = TRUE;
        /* fallthrough */
    case SUMMARY_MODE_NORMAL:
    case SUMMARY_MODE_BOX:
        sMonSummaryScreen->trueMinPageIndex = PSS_PAGE_INFO;
        if (CONFIG_CONTEST_MOVES_ENABLED)
            sMonSummaryScreen->trueMaxPageIndex = PSS_PAGE_CONTEST_MOVES;
        else
            sMonSummaryScreen->trueMaxPageIndex = PSS_PAGE_BATTLE_MOVES;
        break;
    case SUMMARY_MODE_SELECT_MOVE:
        sMonSummaryScreen->trueMinPageIndex = PSS_PAGE_BATTLE_MOVES;
        sMonSummaryScreen->trueMaxPageIndex = PSS_PAGE_CONTEST_MOVES;
        sMonSummaryScreen->lockMonFlag = TRUE;
        break;
    }

    sMonSummaryScreen->minPageIndex = sMonSummaryScreen->trueMinPageIndex;
    sMonSummaryScreen->maxPageIndex = sMonSummaryScreen->trueMaxPageIndex;
    sMonSummaryScreen->currPageIndex = sMonSummaryScreen->minPageIndex;
    sMonSummaryScreen->currStatIndex = 0;
    SummaryScreen_SetAnimDelayTaskId(TASK_NONE);

    if (gMonSpritesGfxPtr == NULL)
        sub_806F2AC(0, 0);

    SetMainCallback2(CB2_InitSummaryScreen);
}

void ShowSelectMovePokemonSummaryScreen(struct Pokemon *mons, u8 monIndex, u8 maxMonIndex, void (*callback)(void), u16 newMove)
{
    ShowPokemonSummaryScreen(SUMMARY_MODE_SELECT_MOVE, mons, monIndex, maxMonIndex, callback);
    sMonSummaryScreen->newMove = newMove;
}

void ShowPokemonSummaryScreenSet40EF(u8 mode, struct BoxPokemon *mons, u8 monIndex, u8 maxMonIndex, void (*callback)(void))
{
    ShowPokemonSummaryScreen(mode, mons, monIndex, maxMonIndex, callback);
    sMonSummaryScreen->unk40EF = TRUE;
}

static void MainCB2(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    DoScheduledBgTilemapCopiesToVram();
    UpdatePaletteFade();
}

static void VBlank(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void CB2_InitSummaryScreen(void)
{
    while (!MenuHelpers_CallLinkSomething() && !LoadGraphics() && !MenuHelpers_LinkSomething());
}

static bool8 LoadGraphics(void)
{
    switch (gMain.state)
    {
    case 0:
        SetVBlankHBlankCallbacksToNull();
        ResetVramOamAndBgCntRegs();
        ClearScheduledBgCopiesToVram();
        gMain.state++;
        break;
    case 1:
        ScanlineEffect_Stop();
        gMain.state++;
        break;
    case 2:
        ResetPaletteFade();
        gPaletteFade.bufferTransferDisabled = 1;
        gMain.state++;
        break;
    case 3:
        ResetSpriteData();
        gMain.state++;
        break;
    case 4:
        FreeAllSpritePalettes();
        gMain.state++;
        break;
    case 5:
        InitBGs();
        sMonSummaryScreen->switchCounter = 0;
        gMain.state++;
        break;
    case 6:
        if (DecompressGraphics() != FALSE)
            gMain.state++;
        break;
    case 7:
        InitWindows(sSummaryTemplate);
        gMain.state++;
        break;
    case 8:
        CopyMonToSummaryStruct(&sMonSummaryScreen->currentMon);
        sMonSummaryScreen->switchCounter = 0;
        gMain.state++;
        break;
    case 9:
        if (ExtractMonDataToSummaryStruct(&sMonSummaryScreen->currentMon) != 0)
            gMain.state++;
        break;
    case 10:
        PrintMonInfo(sMonSummaryScreen->mode == SUMMARY_MODE_SELECT_MOVE);
        gMain.state++;
        break;
    case 11:
        SetSmallMonPicBackgroundPalette();
        ScheduleBgCopyTilemapToVram(1);
        gMain.state++;
        break;
    case 12:
        DrawPagination(sMonSummaryScreen->mode == SUMMARY_MODE_SELECT_MOVE);
        UpdateInfoPageType();
        gMain.state++;
        break;
    case 13:
        PrintPageSpecificText(sMonSummaryScreen->currPageIndex);
        gMain.state++;
        break;
    case 14:
        ResetSpriteIds();
        CreateMoveTypeIcons();
        sMonSummaryScreen->switchCounter = 0;
        gMain.state++;
        break;
    case 15:
        sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_MON] = LoadMonGfxAndSprite(&sMonSummaryScreen->currentMon, &sMonSummaryScreen->switchCounter);
        if (sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_MON] != SPRITE_NONE)
        {
            sMonSummaryScreen->switchCounter = 0;
            gMain.state++;
        }
        break;
    case 16:
        CreateMonMarkingsSprite(&sMonSummaryScreen->currentMon);
        gMain.state++;
        break;
    case 17:
        CreateUpdateShinyIconSprite(sMonSummaryScreen->mode == SUMMARY_MODE_SELECT_MOVE);
        gMain.state++;
        break;
    case 18:
        CreateCaughtBallSprite(&sMonSummaryScreen->currentMon);
        gMain.state++;
        break;
    case 19:
        CreateSetStatusSprite();
        gMain.state++;
        break;
    case 20:
        LoadMonIconPalette(sMonSummaryScreen->summary.species2);
        sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_MON_ICON] = CreateMonIcon(sMonSummaryScreen->summary.species2, SpriteCB_MonIcon, 24, 32, 1, sMonSummaryScreen->summary.pid, TRUE);
        gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_MON_ICON]].hFlip = !IsMonSpriteNotFlipped(sMonSummaryScreen->summary.species2);
        SetSpriteInvisibility(SPRITE_ARR_ID_MON_ICON, TRUE);
        gMain.state++;
        break;
    case 21:
        CreateHealthBarSprites(TAG_HEALTH_BAR, TAG_HEALTH_BAR);
        gMain.state++;
        break;
    case 22:
        CreateExpBarSprites(TAG_EXP_BAR, TAG_HEALTH_BAR);
        gMain.state++;
        break;
    case 23:
        SetTypeIcons();
        gMain.state++;
        break;
    case 24:
        if (sMonSummaryScreen->mode == SUMMARY_MODE_SELECT_MOVE)
        {
            SetSpriteInvisibility(SPRITE_ARR_ID_MON, TRUE);
            SetSpriteInvisibility(SPRITE_ARR_ID_STATUS, TRUE);
            StopPokemonAnimations();
            sMonSummaryScreen->markingsSprite->invisible = TRUE;
        }
        gMain.state++;
        break;
    case 25:
        if (sMonSummaryScreen->mode != SUMMARY_MODE_SELECT_MOVE)
        {
            if (sMonSummaryScreen->summary.isEgg)
                LZDecompressWram(gSummaryScreenPageInfoEggTilemap, sMonSummaryScreen->bgTilemapBufferPage);
            else
                LZDecompressWram(sPageTilemaps[sMonSummaryScreen->currPageIndex], sMonSummaryScreen->bgTilemapBufferPage);
            SetBgTilemapBuffer(2, sMonSummaryScreen->bgTilemapBufferPage);
            ScheduleBgCopyTilemapToVram(2);
            CreateTask(Task_HandleInput, 0);
        }
        else
        {
            LZDecompressWram(gSummaryScreenPageMovesTilemap, sMonSummaryScreen->bgTilemapBufferPage);
            SetBgTilemapBuffer(2, sMonSummaryScreen->bgTilemapBufferPage);
            ScheduleBgCopyTilemapToVram(2);
            DoScheduledBgTilemapCopiesToVram();
            PrintTitleBar(sMonSummaryScreen->currPageIndex, TRUE);
            PrintNewMoveDetailsOrCancelText();
            PutWindowTilemap(WINDOW_ARR_ID_MOVES_WINDOW_LAST_MOVE);
            PrintMoveDetails(sMonSummaryScreen->summary.moves[sMonSummaryScreen->firstMoveIndex]);
            ChangeBgX(1, 0, 0);
            CreateTask(Task_SetHandleReplaceMoveInput, 0);
        }
        gMain.state++;
        break;
    case 26:
        BlendPalettes(PALETTES_ALL, 16, 0);
        gMain.state++;
        break;
    case 27:
        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
        gPaletteFade.bufferTransferDisabled = 0;
        gMain.state++;
        break;
    default:
        SetVBlankCallback(VBlank);
        SetMainCallback2(MainCB2);
        return TRUE;
    }
    return FALSE;
}

static void InitBGs(void)
{
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, sBgTemplates, ARRAY_COUNT(sBgTemplates));
    SetBgTilemapBuffer(1, sMonSummaryScreen->moveDetailTilemapBuffer);
    SetBgTilemapBuffer(3, sMonSummaryScreen->bgTilemapBufferBG);
    ResetAllBgsCoordinates();
    ChangeBgX(1, 0x10000, 0);
    ScheduleBgCopyTilemapToVram(1);
    ScheduleBgCopyTilemapToVram(3);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    ShowBg(0);
    ShowBg(1);
    ShowBg(2);
    ShowBg(3);
}

static bool8 DecompressGraphics(void)
{
    switch (sMonSummaryScreen->switchCounter)
    {
    case 0:
        ResetTempTileDataBuffers();
        DecompressAndCopyTileDataToVram(1, &gSummaryScreenTiles, 0, 0, 0);
        sMonSummaryScreen->switchCounter++;
        break;
    case 1:
        if (FreeTempTileDataBuffersIfPossible() != 1)
        {
            LZDecompressWram(gSummaryScreenBackgroundTilemap, sMonSummaryScreen->bgTilemapBufferBG);
            sMonSummaryScreen->switchCounter++;
        }
        break;
    case 2:
        LZDecompressWram(gSummaryScreenPageMoveDetailsTilemap, sMonSummaryScreen->moveDetailTilemapBuffer);
        sMonSummaryScreen->switchCounter++;
        break;
    case 3:
        LoadCompressedPalette(gSummaryScreenPalette, 0, 0x140);
        sMonSummaryScreen->switchCounter++;
        break;
    case 4:
        LoadCompressedSpriteSheet(&sSpriteSheet_MoveTypes);
        sMonSummaryScreen->switchCounter++;
        break;
    case 5:
        LoadCompressedSpriteSheet(&sMoveSelectorSpriteSheet);
        sMonSummaryScreen->switchCounter++;
        break;
    case 6:
        LoadCompressedSpriteSheet(&sStatusIconsSpriteSheet);
        sMonSummaryScreen->switchCounter++;
        break;
    case 7:
        LoadCompressedSpritePalette(&sStatusIconsSpritePalette);
        sMonSummaryScreen->switchCounter++;
        break;
    case 8:
        LoadCompressedSpritePalette(&sMoveSelectorSpritePal);
        sMonSummaryScreen->switchCounter++;
        break;
    case 9:
        LoadCompressedPalette(gMoveTypes_Pal, 0x1D0, 0x60);
        sMonSummaryScreen->switchCounter = 0;
        return TRUE;
    }
    return FALSE;
}

static void CopyMonToSummaryStruct(struct Pokemon *mon)
{
    if (!sMonSummaryScreen->isBoxMon)
    {
        struct Pokemon *partyMon = sMonSummaryScreen->monList.mons;
        *mon = partyMon[sMonSummaryScreen->curMonIndex];
    }
    else
    {
        struct BoxPokemon *boxMon = sMonSummaryScreen->monList.boxMons;
        BoxMonToMon(&boxMon[sMonSummaryScreen->curMonIndex], mon);
    }
}

static bool8 ExtractMonDataToSummaryStruct(struct Pokemon *mon)
{
    u32 i;
    struct PokeSummary *sum = &sMonSummaryScreen->summary;
    // Spread the data extraction over multiple frames.
    switch (sMonSummaryScreen->switchCounter)
    {
    case 0:
        sum->species = GetMonData(mon, MON_DATA_SPECIES);
        sum->species2 = GetMonData(mon, MON_DATA_SPECIES2);
        sum->exp = GetMonData(mon, MON_DATA_EXP);
        sum->level = GetMonData(mon, MON_DATA_LEVEL);
        sum->abilityNum = GetMonData(mon, MON_DATA_ABILITY_NUM);
        sum->item = GetMonData(mon, MON_DATA_HELD_ITEM);
        sum->pid = GetMonData(mon, MON_DATA_PERSONALITY);
        sum->sanity = GetMonData(mon, MON_DATA_SANITY_IS_BAD_EGG);

        if (sum->sanity)
            sum->isEgg = TRUE;
        else
            sum->isEgg = GetMonData(mon, MON_DATA_IS_EGG);

        sum->locationBit = GetMonData(mon, MON_DATA_LOCATION_BIT);
        break;
    case 1:
        for (i = 0; i < MAX_MON_MOVES; i++)
        {
            sum->moves[i] = GetMonData(mon, MON_DATA_MOVE1+i);
            sum->pp[i] = GetMonData(mon, MON_DATA_PP1+i);
        }
        sum->ppBonuses = GetMonData(mon, MON_DATA_PP_BONUSES);
        break;
    case 2:
        if (sMonSummaryScreen->monList.mons == gPlayerParty || sMonSummaryScreen->mode == SUMMARY_MODE_BOX || sMonSummaryScreen->unk40EF == TRUE)
        {
            sum->nature = GetNature(mon);
            sum->currentHP = GetMonData(mon, MON_DATA_HP);
            sum->maxHP = GetMonData(mon, MON_DATA_MAX_HP);
            sum->atk = GetMonData(mon, MON_DATA_ATK);
            sum->def = GetMonData(mon, MON_DATA_DEF);
            sum->spatk = GetMonData(mon, MON_DATA_SPATK);
            sum->spdef = GetMonData(mon, MON_DATA_SPDEF);
            sum->speed = GetMonData(mon, MON_DATA_SPEED);
        }
        else
        {
            sum->nature = GetNature(mon);
            sum->currentHP = GetMonData(mon, MON_DATA_HP);
            sum->maxHP = GetMonData(mon, MON_DATA_MAX_HP);
            sum->atk = GetMonData(mon, MON_DATA_ATK2);
            sum->def = GetMonData(mon, MON_DATA_DEF2);
            sum->spatk = GetMonData(mon, MON_DATA_SPATK2);
            sum->spdef = GetMonData(mon, MON_DATA_SPDEF2);
            sum->speed = GetMonData(mon, MON_DATA_SPEED2);
        }
        break;
    case 3:
        GetMonData(mon, MON_DATA_OT_NAME, sum->OTName);
        ConvertInternationalString(sum->OTName, GetMonData(mon, MON_DATA_LANGUAGE));
        sum->ailment = GetMonAilment(mon);
        sum->OTGender = GetMonData(mon, MON_DATA_OT_GENDER);
        sum->OTID = GetMonData(mon, MON_DATA_OT_ID);
        sum->metLocation = GetMonData(mon, MON_DATA_MET_LOCATION);
        sum->metLevel = GetMonData(mon, MON_DATA_MET_LEVEL);
        sum->metGame = GetMonData(mon, MON_DATA_MET_GAME);
        sum->friendship = GetMonData(mon, MON_DATA_FRIENDSHIP);
        break;
    default:
        sum->ribbonCount = GetMonData(mon, MON_DATA_RIBBON_COUNT);
        sum->fatefulEncounter = GetMonData(mon, MON_DATA_EVENT_LEGAL);
        if (sum->isEgg)
        {
            sMonSummaryScreen->minPageIndex = PSS_PAGE_INFO;
            sMonSummaryScreen->maxPageIndex = PSS_PAGE_INFO;
            sMonSummaryScreen->currPageIndex = PSS_PAGE_INFO;
        }
        else
        {
            sMonSummaryScreen->minPageIndex = sMonSummaryScreen->trueMinPageIndex;
            sMonSummaryScreen->maxPageIndex = sMonSummaryScreen->trueMaxPageIndex;
        }
        return TRUE;
    }
    sMonSummaryScreen->switchCounter++;
    return FALSE;
}

static void UpdateInfoPageType(void)
{
    if (sMonSummaryScreen->currPageIndex != PSS_PAGE_INFO)
        return;

    if (sMonSummaryScreen->lastWasEgg == sMonSummaryScreen->summary.isEgg)
        return;

    DrawPagination(FALSE);
    PrintTitleBar(sMonSummaryScreen->currPageIndex, TRUE);
    PrintMonInfo(FALSE);
    SetTypeIcons();

    if (sMonSummaryScreen->summary.isEgg)
    {
        PrintInfoPageEgg();
        LZDecompressWram(gSummaryScreenPageInfoEggTilemap, sMonSummaryScreen->bgTilemapBufferPage);
    }
    else
    {
        PrintInfoPageMon();
        LZDecompressWram(gSummaryScreenPageInfoTilemap, sMonSummaryScreen->bgTilemapBufferPage);
    }

    SetBgTilemapBuffer(2, sMonSummaryScreen->bgTilemapBufferPage);
    ScheduleBgCopyTilemapToVram(2);
}

static void FreeSummaryScreen(void)
{
    FreeAllWindowBuffers();
    Free(sMonSummaryScreen);
}

static void BeginCloseSummaryScreen(u8 taskId)
{
    BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
    gTasks[taskId].func = CloseSummaryScreen;
}

static void CloseSummaryScreen(u8 taskId)
{
    if (MenuHelpers_CallLinkSomething() || gPaletteFade.active)
        return;

    SetMainCallback2(sMonSummaryScreen->callback);
    gLastViewedMonIndex = sMonSummaryScreen->curMonIndex;
    SummaryScreen_DestroyAnimDelayTask();
    DestroyHealthBarSprites();
    DestroyExpBarSprites();
    ResetSpriteData();
    FreeAllSpritePalettes();
    StopCryAndClearCrySongs();
    m4aMPlayVolumeControl(&gMPlayInfo_BGM, 0xFFFF, 0x100);
    if (gMonSpritesGfxPtr == NULL)
        sub_806F47C(0);
    FreeSummaryScreen();
    DestroyTask(taskId);
}

static void Task_HandleInput(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    data[0] = 0;

    if (MenuHelpers_CallLinkSomething() || gPaletteFade.active)
        return;

    if (JOY_NEW(DPAD_UP))
    {
        ChangeSummaryPokemon(taskId, -1);
    }
    else if (JOY_NEW(DPAD_DOWN))
    {
        ChangeSummaryPokemon(taskId, 1);
    }
    else if ((JOY_NEW(DPAD_LEFT)) || GetLRKeysPressed() == MENU_L_PRESSED)
    {
        ChangePage(taskId, -1);
    }
    else if ((JOY_NEW(DPAD_RIGHT)) || GetLRKeysPressed() == MENU_R_PRESSED)
    {
        ChangePage(taskId, 1);
    }
    else if (JOY_NEW(A_BUTTON))
    {
        if (sMonSummaryScreen->currPageIndex == PSS_PAGE_INFO)
        {
            StopPokemonAnimations();
            PlaySE(SE_SELECT);
            BeginCloseSummaryScreen(taskId);
        }
        else if (sMonSummaryScreen->currPageIndex == PSS_PAGE_BATTLE_MOVES || sMonSummaryScreen->currPageIndex == PSS_PAGE_CONTEST_MOVES)
        {
            PlaySE(SE_SELECT);
            SwitchToMoveSelection(taskId);
        }
    }
    else if (JOY_NEW(B_BUTTON))
    {
        StopPokemonAnimations();
        PlaySE(SE_SELECT);
        BeginCloseSummaryScreen(taskId);
    }
}

static void ChangeSummaryPokemon(u8 taskId, s8 delta)
{
    s8 monId;
    sMonSummaryScreen->lastWasEgg = sMonSummaryScreen->summary.isEgg;

    if (sMonSummaryScreen->maxMonIndex == 0)
        return;

    if (sMonSummaryScreen->lockMonFlag)
        return;

    if (sMonSummaryScreen->isBoxMon == TRUE)
    {
        if (delta == 1)
            delta = 0;
        else
            delta = 2;
        monId = AdvanceStorageMonIndex(sMonSummaryScreen->monList.boxMons, sMonSummaryScreen->curMonIndex, sMonSummaryScreen->maxMonIndex, delta);
    }
    else if (IsMultiBattle() == TRUE)
    {
        monId = AdvanceMultiBattleMonIndex(delta);
    }
    else
    {
        monId = AdvanceMonIndex(delta);
    }

    if (monId == -1)
        return;

    PlaySE(SE_SELECT);
    if (sMonSummaryScreen->summary.ailment != AILMENT_NONE)
        SetSpriteInvisibility(SPRITE_ARR_ID_STATUS, TRUE);
    sMonSummaryScreen->curMonIndex = monId;
    gTasks[taskId].data[0] = 0;
    gTasks[taskId].func = Task_ChangeSummaryMon;
}

static void Task_ChangeSummaryMon(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    switch (data[0])
    {
    case 0:
        StopCryAndClearCrySongs();
        break;
    case 1:
        SummaryScreen_DestroyAnimDelayTask();
        DestroySpriteAndFreeResources(&gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_MON]]);
        break;
    case 2:
        DestroySpriteAndFreeResources(&gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_BALL]]);
        break;
    case 3:
        FreeAndDestroyMonIconSprite(&gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_MON_ICON]]);
        break;
    case 4:
        CopyMonToSummaryStruct(&sMonSummaryScreen->currentMon);
        sMonSummaryScreen->switchCounter = 0;
        break;
    case 5:
        if (ExtractMonDataToSummaryStruct(&sMonSummaryScreen->currentMon) == FALSE)
            return;
        break;
    case 6:
        PrintMonInfo(FALSE);
        break;
    case 7:
        UpdateInfoPageType();
        break;
    case 8:
        RemoveAndCreateMonMarkingsSprite(&sMonSummaryScreen->currentMon);
        break;
    case 9:
        CreateSetStatusSprite();
        break;
    case 10:
        CreateCaughtBallSprite(&sMonSummaryScreen->currentMon);
        break;
    case 11:
        CreateUpdateShinyIconSprite(sMonSummaryScreen->mode == SUMMARY_MODE_SELECT_MOVE);
        break;
    case 12:
        FreeMonIconPalettes();
        LoadMonIconPalette(sMonSummaryScreen->summary.species2);
        sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_MON_ICON] = CreateMonIcon(sMonSummaryScreen->summary.species2, SpriteCB_MonIcon, 24, 32, 1, sMonSummaryScreen->summary.pid, TRUE);
        gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_MON_ICON]].hFlip = !IsMonSpriteNotFlipped(sMonSummaryScreen->summary.species2);
        SetSpriteInvisibility(SPRITE_ARR_ID_MON_ICON, TRUE);
        break;
    case 13:
        SetSmallMonPicBackgroundPalette();
        ScheduleBgCopyTilemapToVram(1);
        data[1] = 0;
        break;
    case 14:
        sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_MON] = LoadMonGfxAndSprite(&sMonSummaryScreen->currentMon, &data[1]);
        if (sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_MON] == SPRITE_NONE)
            return;
        gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_MON]].data[2] = 1;
        data[1] = 0;
        break;
    case 15:
        ConfigureHealthBarSprites();
        break;
    case 16:
        ConfigureExpBarSprites();
        break;
    case 17:
        SetTypeIcons();
        break;
    case 18:
        PrintPageSpecificText(sMonSummaryScreen->currPageIndex);
        break;
    case 19:
        gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_MON]].data[2] = 0;
        break;
    default:
        if (MenuHelpers_CallLinkSomething() == 0)
        {
            data[0] = 0;
            gTasks[taskId].func = Task_HandleInput;
        }
        return;
    }
    data[0]++;
}

static s8 AdvanceMonIndex(s8 delta)
{
    struct Pokemon *mon = sMonSummaryScreen->monList.mons;

    if (sMonSummaryScreen->currPageIndex == PSS_PAGE_INFO)
    {
        if (delta == -1 && sMonSummaryScreen->curMonIndex == 0)
            return -1;
        else if (delta == 1 && sMonSummaryScreen->curMonIndex >= sMonSummaryScreen->maxMonIndex)
            return -1;
        else
            return sMonSummaryScreen->curMonIndex + delta;
    }
    else
    {
        s8 index = sMonSummaryScreen->curMonIndex;

        do
        {
            index += delta;
            if (index < 0 || index > sMonSummaryScreen->maxMonIndex)
                return -1;
        } while (GetMonData(&mon[index], MON_DATA_IS_EGG));
        return index;
    }
}

static s8 AdvanceMultiBattleMonIndex(s8 delta)
{
    struct Pokemon *mons = sMonSummaryScreen->monList.mons;
    s8 index, arrId = 0;
    u8 i;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (sMultiBattleOrder[i] == sMonSummaryScreen->curMonIndex)
        {
            arrId = i;
            break;
        }
    }

    while (TRUE)
    {
        const s8 *order = sMultiBattleOrder;

        arrId += delta;
        if (arrId < 0)
            arrId = PARTY_SIZE;
        else if (arrId >= PARTY_SIZE)
            arrId = 0;
        index = order[arrId];
        if (IsValidToViewInMulti(&mons[index]) == TRUE)
            return index;
    }
}

static bool8 IsValidToViewInMulti(struct Pokemon* mon)
{
    if (GetMonData(mon, MON_DATA_SPECIES) == SPECIES_NONE)
        return FALSE;
    else if (sMonSummaryScreen->curMonIndex != 0 || !GetMonData(mon, MON_DATA_IS_EGG))
        return TRUE;
    else
        return FALSE;
}

static void ChangePage(u8 taskId, s8 delta)
{
    u8 i;
    struct PokeSummary *summary = &sMonSummaryScreen->summary;
    s16 *data = gTasks[taskId].data;

    if (sMonSummaryScreen->minPageIndex == sMonSummaryScreen->maxPageIndex)
        return;
    else if (delta == -1 && sMonSummaryScreen->currPageIndex == sMonSummaryScreen->minPageIndex)
        return;
    else if (delta == 1 && sMonSummaryScreen->currPageIndex == sMonSummaryScreen->maxPageIndex)
        return;
    else
        sMonSummaryScreen->currPageIndex += delta;

    for (i = WINDOW_ARR_ID_BEGIN_TRANSIENT; i < WINDOW_ARR_ID_COUNT; i++)
        ClearWindowTilemap(i);

    if (sMonSummaryScreen->currPageIndex == PSS_PAGE_BATTLE_MOVES)
        LZDecompressWram(gSummaryScreenPageMoveDetailsTilemap, sMonSummaryScreen->moveDetailTilemapBuffer);
    else
        LZDecompressWram(gSummaryScreenPageContestMoveDetailsTilemap, sMonSummaryScreen->moveDetailTilemapBuffer);

    LZDecompressWram(sPageTilemaps[sMonSummaryScreen->currPageIndex], sMonSummaryScreen->bgTilemapBufferPage);
    PlaySE(SE_SELECT);
    ScheduleBgCopyTilemapToVram(0);
    data[0] = 0;
    SetTaskFuncWithFollowupFunc(taskId, ChangePageTask, gTasks[taskId].func);
}

static void ChangePageTask(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    switch (data[0])
    {
        case 0:
            HidePageSpecificSprites();
            data[0]++;
            break;
        case 1:
            SetBgTilemapBuffer(2, sMonSummaryScreen->bgTilemapBufferPage);
            ScheduleBgCopyTilemapToVram(2);
            data[0]++;
            break;
        case 2:
            SetHealthBarSprites();
            SetExpBarSprites();
            SetTypeIcons();
            data[0]++;
            break;
        case 3:
            PrintPageSpecificText(sMonSummaryScreen->currPageIndex);
            data[0]++;
            break;
        case 4:
            SetBgTilemapBuffer(1, sMonSummaryScreen->moveDetailTilemapBuffer);
            SetSmallMonPicBackgroundPalette();
            ScheduleBgCopyTilemapToVram(1);
            data[0]++;
            break;
        case 5:
            DrawPagination(FALSE);
            data[0]++;
            break;
        case 6:
            data[0] = 0;
            SwitchTaskToFollowupFunc(taskId);
            break;
    }
}

static void SwitchToMoveSelection(u8 taskId)
{
    u32 i;
    s16 *data = gTasks[taskId].data;

    sMonSummaryScreen->firstMoveIndex = 0;
    data[1] = sMonSummaryScreen->summary.moves[sMonSummaryScreen->firstMoveIndex];

    gTasks[taskId].func = Task_HandleInput_MoveSelect;
    SetTaskFuncWithFollowupFunc(taskId, Task_SwitchToMoveDetails, gTasks[taskId].func);
}

static void Task_SwitchToMoveDetails(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    switch (data[0])
    {
        case 0:
            SetSpriteInvisibility(SPRITE_ARR_ID_MON, TRUE);
            SetSpriteInvisibility(SPRITE_ARR_ID_STATUS, TRUE);
            StopPokemonAnimations();
            sMonSummaryScreen->markingsSprite->invisible = TRUE;
            ClearWindowTilemap(WINDOW_ARR_ID_MOVES_WINDOW_LEFT);
            ScheduleBgCopyTilemapToVram(0);
            data[0]++;
            break;
        case 1:
            PrintNewMoveDetailsOrCancelText();
            PutWindowTilemap(WINDOW_ARR_ID_MOVES_WINDOW_LAST_MOVE);
            SetNewMoveTypeIcon();
            PrintTitleBar(sMonSummaryScreen->currPageIndex, TRUE);
            CreateMoveSelectorSprites(SPRITE_ARR_ID_MOVE_SELECTOR1);
            data[0]++;
            break;
        case 2:
            DrawPagination(TRUE);
            ChangeBgX(1, 0, 0);
            PrintMoveDetails(data[1]);
            PrintMonInfo(TRUE);
            PutWindowTilemap(WINDOW_ARR_ID_MOVES_WINDOW_LEFT);
            data[0]++;
            break;
        case 3:
            CreateUpdateShinyIconSprite(TRUE);
            data[0] = 0;
            SwitchTaskToFollowupFunc(taskId);
            break;
    }
}

static void Task_HandleInput_MoveSelect(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (MenuHelpers_CallLinkSomething())
        return;

    if (JOY_NEW(DPAD_UP))
    {
        data[0] = 4;
        ChangeSelectedMove(data, -1, &sMonSummaryScreen->firstMoveIndex);
    }
    else if (JOY_NEW(DPAD_DOWN))
    {
        data[0] = 4;
        ChangeSelectedMove(data, 1, &sMonSummaryScreen->firstMoveIndex);
    }
    else if (JOY_NEW(DPAD_LEFT) || GetLRKeysPressed() == MENU_L_PRESSED || JOY_NEW(DPAD_RIGHT) || GetLRKeysPressed() == MENU_R_PRESSED)
    {
        if (sMonSummaryScreen->maxPageIndex > PSS_PAGE_BATTLE_MOVES)
        {
            if (sMonSummaryScreen->currPageIndex == PSS_PAGE_BATTLE_MOVES)
                sMonSummaryScreen->currPageIndex = PSS_PAGE_CONTEST_MOVES;
            else
                sMonSummaryScreen->currPageIndex = PSS_PAGE_BATTLE_MOVES;

            DrawPagination(TRUE);
            LZDecompressWram(sPageTilemaps[sMonSummaryScreen->currPageIndex], sMonSummaryScreen->bgTilemapBufferPage);
            PlaySE(SE_SELECT);
            data[0] = 0;
            gTasks[taskId].func = Task_SwitchPageInMoveSelect;
        }
    }
    else if (JOY_NEW(A_BUTTON))
    {
        if (sMonSummaryScreen->lockMovesFlag == TRUE
         || (sMonSummaryScreen->newMove == MOVE_NONE && sMonSummaryScreen->firstMoveIndex == MAX_MON_MOVES))
        {
            PlaySE(SE_SELECT);
            CloseMoveSelectMode(taskId);
        }
        else if (HasMoreThanOneMove() == TRUE)
        {
            PlaySE(SE_SELECT);
            SwitchToMovePositionSwitchMode(taskId);
        }
        else
        {
            PlaySE(SE_FAILURE);
        }
    }
    else if (JOY_NEW(B_BUTTON))
    {
        PlaySE(SE_SELECT);
        CloseMoveSelectMode(taskId);
    }
}

void Task_SwitchPageInMoveSelect(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    switch (data[0])
    {
        case 0:
            ClearWindowTilemap(WINDOW_ARR_ID_MOVES_WINDOW_TOP_FOUR_MOVES);
            ClearWindowTilemap(WINDOW_ARR_ID_MOVES_WINDOW_LEFT);
            ScheduleBgCopyTilemapToVram(0);
            data[0]++;
            break;
        case 1:
            if (sMonSummaryScreen->currPageIndex == PSS_PAGE_BATTLE_MOVES)
            {
                LZDecompressWram(gSummaryScreenPageMovesTilemap, sMonSummaryScreen->bgTilemapBufferPage);
                LZDecompressWram(gSummaryScreenPageMoveDetailsTilemap, sMonSummaryScreen->moveDetailTilemapBuffer);
            }
            else
            {
                LZDecompressWram(gSummaryScreenPageContestMovesTilemap, sMonSummaryScreen->bgTilemapBufferPage);
                LZDecompressWram(gSummaryScreenPageContestMoveDetailsTilemap, sMonSummaryScreen->moveDetailTilemapBuffer);
            }
            SetBgTilemapBuffer(2, sMonSummaryScreen->bgTilemapBufferPage);
            SetBgTilemapBuffer(1, sMonSummaryScreen->moveDetailTilemapBuffer);
            SetSmallMonPicBackgroundPalette();
            ScheduleBgCopyTilemapToVram(1);
            ScheduleBgCopyTilemapToVram(2);
            data[0]++;
            break;
        case 2:
            if (sMonSummaryScreen->currPageIndex == PSS_PAGE_BATTLE_MOVES)
                PrintBattleMoves();
            else
                PrintContestMoves();
            data[0]++;
            break;
        case 3:
            PrintNewMoveDetailsOrCancelText();
            PutWindowTilemap(WINDOW_ARR_ID_MOVES_WINDOW_LAST_MOVE);
            SetTypeIcons();
            PrintTitleBar(sMonSummaryScreen->currPageIndex, TRUE);
            data[0]++;
            break;
        case 4:
            if (sMonSummaryScreen->firstMoveIndex != MAX_MON_MOVES)
                PrintMoveDetails(sMonSummaryScreen->summary.moves[sMonSummaryScreen->firstMoveIndex]);
            else if (sMonSummaryScreen->newMove != MOVE_NONE)
                PrintMoveDetails(sMonSummaryScreen->newMove);
            PutWindowTilemap(WINDOW_ARR_ID_MOVES_WINDOW_LEFT);
            data[0]++;
            break;
        case 5:
            data[0] = 0;
            gTasks[taskId].func = Task_HandleInput_MoveSelect;
            break;
    }
}

static bool8 HasMoreThanOneMove(void)
{
    u8 i;
    for (i = 1; i < MAX_MON_MOVES; i++)
        if (sMonSummaryScreen->summary.moves[i] != 0)
            return TRUE;
    return FALSE;
}

static void ChangeSelectedMove(s16 *taskData, s8 direction, u8 *moveIndexPtr)
{
    s8 i, newMoveIndex;
    u16 move;

    PlaySE(SE_SELECT);
    newMoveIndex = *moveIndexPtr;
    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        newMoveIndex += direction;
        if (newMoveIndex > taskData[0])
            newMoveIndex = 0;
        else if (newMoveIndex < 0)
            newMoveIndex = taskData[0];

        if (newMoveIndex == MAX_MON_MOVES)
        {
            move = sMonSummaryScreen->newMove;
            break;
        }
        move = sMonSummaryScreen->summary.moves[newMoveIndex];
        if (move != 0)
            break;
    }
    ScheduleBgCopyTilemapToVram(1);
    ScheduleBgCopyTilemapToVram(2);
    PrintMoveDetails(move);

    if ((*moveIndexPtr == MAX_MON_MOVES && sMonSummaryScreen->newMove == MOVE_NONE) || taskData[1] == 1)
        ScheduleBgCopyTilemapToVram(0);

    if (*moveIndexPtr != MAX_MON_MOVES && newMoveIndex == MAX_MON_MOVES && sMonSummaryScreen->newMove == MOVE_NONE)
        ScheduleBgCopyTilemapToVram(0);

    *moveIndexPtr = newMoveIndex;
    // Get rid of the 'flicker' effect(while idle) when scrolling.
    if (moveIndexPtr == &sMonSummaryScreen->firstMoveIndex)
        KeepMoveSelectorVisible(SPRITE_ARR_ID_MOVE_SELECTOR1);
    else
        KeepMoveSelectorVisible(SPRITE_ARR_ID_MOVE_SELECTOR2);
}

static void CloseMoveSelectMode(u8 taskId)
{
    u32 i;
    s16 *data = gTasks[taskId].data;
    data[0] = 0;
    gTasks[taskId].func = Task_HandleInput;
    SetTaskFuncWithFollowupFunc(taskId, Task_SwitchFromMoveDetails, gTasks[taskId].func);
}

static void Task_SwitchFromMoveDetails(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    switch (data[0])
    {
        case 0:
            DestroyMoveSelectorSprites(SPRITE_ARR_ID_MOVE_SELECTOR1);
            PrintMoveDetails(0);
            SetSpriteInvisibility(SPRITE_ARR_ID_TYPE, TRUE);
            SetSpriteInvisibility(SPRITE_ARR_ID_TYPE + 1, TRUE);
            SetSpriteInvisibility(SPRITE_ARR_ID_MON_ICON, TRUE);
            data[0]++;
            break;
        case 1:
            ChangeBgX(1, 0x10000, 0);
            data[0]++;
            break;
        case 2:
            DrawPagination(FALSE);
            ClearWindowTilemap(WINDOW_ARR_ID_MOVES_WINDOW_LAST_MOVE);
            SetSpriteInvisibility(SPRITE_ARR_ID_MON, FALSE);
            PrintMonInfo(FALSE);
            gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_MON]].oam.affineMode = ST_OAM_AFFINE_NORMAL;
            CalcCenterToCornerVec(&gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_MON]], gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_MON]].oam.shape, gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_MON]].oam.size, gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_MON]].oam.affineMode);
            gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_MON]].hFlip = !gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_MON]].data[1];
            FreeOamMatrix(gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_MON]].oam.matrixNum);
            gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_MON]].oam.matrixNum |= (gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_MON]].hFlip << 3);
            gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_MON]].oam.affineMode = ST_OAM_AFFINE_OFF;
            RequestSpriteFrameImageCopy(gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_MON]].anims[0][0].frame.imageValue, gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_MON]].oam.tileNum, gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_MON]].images);
            gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_MON]].x2 = 0;
            gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_MON]].y2 = 0;
            gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_MON]].oam.x = gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_MON]].x + gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_MON]].centerToCornerVecX;
            gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_MON]].oam.y = gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_MON]].y + gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_MON]].centerToCornerVecY;
            CreateSetStatusSprite();
            if (GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_MARKINGS) != 0)
                sMonSummaryScreen->markingsSprite->invisible = FALSE;
            PrintTitleBar(sMonSummaryScreen->currPageIndex, FALSE);
            data[0]++;
            break;
        case 3:
            CreateUpdateShinyIconSprite(FALSE);
            ScheduleBgCopyTilemapToVram(0);
            SetSmallMonPicBackgroundPalette();
            ScheduleBgCopyTilemapToVram(1);
            ScheduleBgCopyTilemapToVram(2);
            data[0] = 0;
            SwitchTaskToFollowupFunc(taskId);
            break;
    }
}

static void SwitchToMovePositionSwitchMode(u8 taskId)
{
    sMonSummaryScreen->secondMoveIndex = sMonSummaryScreen->firstMoveIndex;
    SetMainMoveSelectorColor(1);
    CreateMoveSelectorSprites(SPRITE_ARR_ID_MOVE_SELECTOR2);
    gTasks[taskId].func = Task_HandleInput_MovePositionSwitch;
}

static void Task_HandleInput_MovePositionSwitch(u8 taskId)
{
    s16* data = gTasks[taskId].data;

    if (MenuHelpers_CallLinkSomething())
        return;

    if (JOY_NEW(DPAD_UP))
    {
        data[0] = 3;
        ChangeSelectedMove(&data[0], -1, &sMonSummaryScreen->secondMoveIndex);
    }
    else if (JOY_NEW(DPAD_DOWN))
    {
        data[0] = 3;
        ChangeSelectedMove(&data[0], 1, &sMonSummaryScreen->secondMoveIndex);
    }
    else if (JOY_NEW(A_BUTTON))
    {
        if (sMonSummaryScreen->firstMoveIndex == sMonSummaryScreen->secondMoveIndex)
            ExitMovePositionSwitchMode(taskId, FALSE);
        else
            ExitMovePositionSwitchMode(taskId, TRUE);
    }
    else if (JOY_NEW(B_BUTTON))
    {
        ExitMovePositionSwitchMode(taskId, FALSE);
    }
}

static void ExitMovePositionSwitchMode(u8 taskId, bool8 swapMoves)
{
    u16 move;

    PlaySE(SE_SELECT);
    SetMainMoveSelectorColor(0);
    DestroyMoveSelectorSprites(SPRITE_ARR_ID_MOVE_SELECTOR2);

    if (swapMoves)
    {
        if (!sMonSummaryScreen->isBoxMon)
        {
            struct Pokemon *mon = sMonSummaryScreen->monList.mons;
            SwapMonMoves(&mon[sMonSummaryScreen->curMonIndex], sMonSummaryScreen->firstMoveIndex, sMonSummaryScreen->secondMoveIndex);
        }
        else
        {
            struct BoxPokemon *boxMon = sMonSummaryScreen->monList.boxMons;
            SwapBoxMonMoves(&boxMon[sMonSummaryScreen->curMonIndex], sMonSummaryScreen->firstMoveIndex, sMonSummaryScreen->secondMoveIndex);
        }
        CopyMonToSummaryStruct(&sMonSummaryScreen->currentMon);
        SwapMovesNamesPP(sMonSummaryScreen->firstMoveIndex, sMonSummaryScreen->secondMoveIndex);
        SwapMovesTypeSprites(sMonSummaryScreen->firstMoveIndex, sMonSummaryScreen->secondMoveIndex);
        sMonSummaryScreen->firstMoveIndex = sMonSummaryScreen->secondMoveIndex;
    }

    move = sMonSummaryScreen->summary.moves[sMonSummaryScreen->firstMoveIndex];
    PrintMoveDetails(move);
    ScheduleBgCopyTilemapToVram(1);
    ScheduleBgCopyTilemapToVram(2);
    gTasks[taskId].func = Task_HandleInput_MoveSelect;
}

static void SwapMonMoves(struct Pokemon *mon, u8 moveIndex1, u8 moveIndex2)
{
    struct PokeSummary* summary = &sMonSummaryScreen->summary;

    u16 move1 = summary->moves[moveIndex1];
    u16 move2 = summary->moves[moveIndex2];
    u8 move1pp = summary->pp[moveIndex1];
    u8 move2pp = summary->pp[moveIndex2];
    u8 ppBonuses = summary->ppBonuses;

    // Calculate PP bonuses
    u8 ppUpMask1 = gPPUpGetMask[moveIndex1];
    u8 ppBonusMove1 = (ppBonuses & ppUpMask1) >> (moveIndex1 * 2);
    u8 ppUpMask2 = gPPUpGetMask[moveIndex2];
    u8 ppBonusMove2 = (ppBonuses & ppUpMask2) >> (moveIndex2 * 2);
    ppBonuses &= ~ppUpMask1;
    ppBonuses &= ~ppUpMask2;
    ppBonuses |= (ppBonusMove1 << (moveIndex2 * 2)) + (ppBonusMove2 << (moveIndex1 * 2));

    // Swap the moves
    SetMonData(mon, MON_DATA_MOVE1 + moveIndex1, &move2);
    SetMonData(mon, MON_DATA_MOVE1 + moveIndex2, &move1);
    SetMonData(mon, MON_DATA_PP1 + moveIndex1, &move2pp);
    SetMonData(mon, MON_DATA_PP1 + moveIndex2, &move1pp);
    SetMonData(mon, MON_DATA_PP_BONUSES, &ppBonuses);

    summary->moves[moveIndex1] = move2;
    summary->moves[moveIndex2] = move1;

    summary->pp[moveIndex1] = move2pp;
    summary->pp[moveIndex2] = move1pp;

    summary->ppBonuses = ppBonuses;
}

static void SwapBoxMonMoves(struct BoxPokemon *mon, u8 moveIndex1, u8 moveIndex2)
{
    struct PokeSummary* summary = &sMonSummaryScreen->summary;

    u16 move1 = summary->moves[moveIndex1];
    u16 move2 = summary->moves[moveIndex2];
    u8 move1pp = summary->pp[moveIndex1];
    u8 move2pp = summary->pp[moveIndex2];
    u8 ppBonuses = summary->ppBonuses;

    // Calculate PP bonuses
    u8 ppUpMask1 = gPPUpGetMask[moveIndex1];
    u8 ppBonusMove1 = (ppBonuses & ppUpMask1) >> (moveIndex1 * 2);
    u8 ppUpMask2 = gPPUpGetMask[moveIndex2];
    u8 ppBonusMove2 = (ppBonuses & ppUpMask2) >> (moveIndex2 * 2);
    ppBonuses &= ~ppUpMask1;
    ppBonuses &= ~ppUpMask2;
    ppBonuses |= (ppBonusMove1 << (moveIndex2 * 2)) + (ppBonusMove2 << (moveIndex1 * 2));

    // Swap the moves
    SetBoxMonData(mon, MON_DATA_MOVE1 + moveIndex1, &move2);
    SetBoxMonData(mon, MON_DATA_MOVE1 + moveIndex2, &move1);
    SetBoxMonData(mon, MON_DATA_PP1 + moveIndex1, &move2pp);
    SetBoxMonData(mon, MON_DATA_PP1 + moveIndex2, &move1pp);
    SetBoxMonData(mon, MON_DATA_PP_BONUSES, &ppBonuses);

    summary->moves[moveIndex1] = move2;
    summary->moves[moveIndex2] = move1;

    summary->pp[moveIndex1] = move2pp;
    summary->pp[moveIndex2] = move1pp;

    summary->ppBonuses = ppBonuses;
}

static void Task_SetHandleReplaceMoveInput(u8 taskId)
{
    SetNewMoveTypeIcon();
    CreateMoveSelectorSprites(SPRITE_ARR_ID_MOVE_SELECTOR1);
    gTasks[taskId].func = Task_HandleReplaceMoveInput;
}

static void Task_HandleReplaceMoveInput(u8 taskId)
{
    s16* data = gTasks[taskId].data;

    if (MenuHelpers_CallLinkSomething() || gPaletteFade.active)
        return;

    if (JOY_NEW(DPAD_UP))
    {
        data[0] = 4;
        ChangeSelectedMove(data, -1, &sMonSummaryScreen->firstMoveIndex);
    }
    else if (JOY_NEW(DPAD_DOWN))
    {
        data[0] = 4;
        ChangeSelectedMove(data, 1, &sMonSummaryScreen->firstMoveIndex);
    }
    else if (JOY_NEW(DPAD_LEFT) || GetLRKeysPressed() == MENU_L_PRESSED || JOY_NEW(DPAD_RIGHT) || GetLRKeysPressed() == MENU_R_PRESSED)
    {
        if (sMonSummaryScreen->maxPageIndex > PSS_PAGE_BATTLE_MOVES)
        {
            if (sMonSummaryScreen->currPageIndex == PSS_PAGE_BATTLE_MOVES)
                sMonSummaryScreen->currPageIndex = PSS_PAGE_CONTEST_MOVES;
            else
                sMonSummaryScreen->currPageIndex = PSS_PAGE_BATTLE_MOVES;

            LZDecompressWram(sPageTilemaps[sMonSummaryScreen->currPageIndex], sMonSummaryScreen->bgTilemapBufferPage);
            PlaySE(SE_SELECT);
            data[0] = 0;
            gTasks[taskId].func = Task_SwitchPageInReplaceMove;
        }
    }
    else if (JOY_NEW(A_BUTTON))
    {
        if (CanReplaceMove())
        {
            StopPokemonAnimations();
            PlaySE(SE_SELECT);
            sMoveSlotToReplace = sMonSummaryScreen->firstMoveIndex;
            gSpecialVar_0x8005 = sMoveSlotToReplace;
            BeginCloseSummaryScreen(taskId);
        }
        else
        {
            PlaySE(SE_FAILURE);
            ShowCantForgetHMs(taskId);
        }
    }
    else if (JOY_NEW(B_BUTTON))
    {
        StopPokemonAnimations();
        PlaySE(SE_SELECT);
        sMoveSlotToReplace = MAX_MON_MOVES;
        gSpecialVar_0x8005 = MAX_MON_MOVES;
        BeginCloseSummaryScreen(taskId);
    }
}

static void Task_SwitchPageInReplaceMove(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    switch (data[0])
    {
        case 0:
            ClearWindowTilemap(WINDOW_ARR_ID_MOVES_WINDOW_TOP_FOUR_MOVES);
            ClearWindowTilemap(WINDOW_ARR_ID_MOVES_WINDOW_LEFT);
            ScheduleBgCopyTilemapToVram(0);
            data[0]++;
            break;
        case 1:
            if (sMonSummaryScreen->currPageIndex == PSS_PAGE_BATTLE_MOVES)
            {
                LZDecompressWram(gSummaryScreenPageMovesTilemap, sMonSummaryScreen->bgTilemapBufferPage);
                LZDecompressWram(gSummaryScreenPageMoveDetailsTilemap, sMonSummaryScreen->moveDetailTilemapBuffer);
            }
            else
            {
                LZDecompressWram(gSummaryScreenPageContestMovesTilemap, sMonSummaryScreen->bgTilemapBufferPage);
                LZDecompressWram(gSummaryScreenPageContestMoveDetailsTilemap, sMonSummaryScreen->moveDetailTilemapBuffer);
            }
            SetBgTilemapBuffer(2, sMonSummaryScreen->bgTilemapBufferPage);
            SetBgTilemapBuffer(1, sMonSummaryScreen->moveDetailTilemapBuffer);
            SetSmallMonPicBackgroundPalette();
            ScheduleBgCopyTilemapToVram(1);
            ScheduleBgCopyTilemapToVram(2);
            data[0]++;
            break;
        case 2:
            if (sMonSummaryScreen->currPageIndex == PSS_PAGE_BATTLE_MOVES)
                PrintBattleMoves();
            else
                PrintContestMoves();
            data[0]++;
            break;
        case 3:
            PrintNewMoveDetailsOrCancelText();
            PutWindowTilemap(WINDOW_ARR_ID_MOVES_WINDOW_LAST_MOVE);
            SetTypeIcons();
            PrintTitleBar(sMonSummaryScreen->currPageIndex, TRUE);
            data[0]++;
            break;
        case 4:
            if (sMonSummaryScreen->firstMoveIndex == MAX_MON_MOVES)
                PrintMoveDetails(sMonSummaryScreen->newMove);
            else
                PrintMoveDetails(sMonSummaryScreen->summary.moves[sMonSummaryScreen->firstMoveIndex]);
            PutWindowTilemap(WINDOW_ARR_ID_MOVES_WINDOW_LEFT);
            data[0]++;
            break;
        case 5:
            DrawPagination(TRUE);
            data[0] = 0;
            gTasks[taskId].func = Task_HandleReplaceMoveInput;
            break;
    }
}

static bool8 CanReplaceMove(void)
{
    return (sMonSummaryScreen->firstMoveIndex == MAX_MON_MOVES
        || sMonSummaryScreen->newMove == MOVE_NONE
        || !IsMoveHm(sMonSummaryScreen->summary.moves[sMonSummaryScreen->firstMoveIndex]));
}

static void PrintTextOnWindow(u8 windowId, const u8 *string, u8 x, u8 y, u8 lineSpacing, u8 colorId)
{
    AddTextPrinterParameterized4(windowId, 2, x, y, 0, lineSpacing, sTextColors[colorId], 0, string);
}

static void PrintTextOnWindowSmall(u8 windowId, const u8 *string, u8 x, u8 y, u8 lineSpacing, u8 colorId)
{
    AddTextPrinterParameterized4(windowId, 0, x, y, 0, lineSpacing, sTextColors[colorId], 0, string);
}

static void SetSmallMonPicBackgroundPalette(void)
{
    u8 i;
    u16 left = 0x13;
    u16 middle = 0xA9;
    u16 right = 0xAA;
    bool8 shiny = IsMonShiny(&sMonSummaryScreen->currentMon);
    u8 topPal = shiny ? 7 : 0;
    u8 bottomPal = (sMonSummaryScreen->currPageIndex == PSS_PAGE_BATTLE_MOVES) ? 4 : 5;
    SetBgTilemapPalette(1, 0, 2, 80, 2, topPal);

    if (shiny)
    {
        left = 0x17C;
        middle = 0x18C;
        right = 0x19C;
    }

    FillBgTilemapBufferRect(1, left, 0, 6, 1, 1, bottomPal);

    for (i = 1; i < 14; i++)
        FillBgTilemapBufferRect(1, middle, i, 6, 1, 1, bottomPal);

    FillBgTilemapBufferRect(1, right, 14, 6, 1, 1, bottomPal);
    ScheduleBgCopyTilemapToVram(1);
}

static void SetMonPicBackgroundPalette(bool8 isMonShiny)
{
    u8 palOutside = isMonShiny ? 7 : 0;
    u8 palInside = isMonShiny ? 6 : 1;
    SetBgTilemapPalette(3, 0, 2, 15, 2, palOutside);
    SetBgTilemapPalette(3, 0, 4, 15, 8, palInside);
    SetBgTilemapPalette(3, 0, 12, 15, 1, palOutside);
    ScheduleBgCopyTilemapToVram(3);
}

static void PrintMonInfo(bool8 smallWindow)
{
    struct Pokemon *mon = &sMonSummaryScreen->currentMon;
    struct PokeSummary *summary = &sMonSummaryScreen->summary;
    FillWindowPixelBuffer(WINDOW_ARR_ID_LVL_NICK_GENDER, PIXEL_FILL(0));

    if (CheckPartyPokerus(mon, 0) || !CheckPartyHasHadPokerus(mon, 0))
        FillBgTilemapBufferRect(3, 0x1BF, 14, 11, 1, 1, 5);
    else
        FillBgTilemapBufferRect(3, 0x198, 14, 11, 1, 1, 5);

    CopyBgTilemapBufferToVram(3);
    SetMonPicBackgroundPalette(!summary->isEgg && IsMonShiny(mon));

    if (summary->isEgg)
    {
        ClearWindowTilemap(WINDOW_ARR_ID_LVL_NICK_GENDER);
        CopyBgTilemapBufferToVram(0);
        return;
    }

    if (!smallWindow)
    {
        StringCopy(gStringVar1, gText_LevelSymbol);
        ConvertIntToDecimalStringN(gStringVar2, summary->level, STR_CONV_MODE_LEFT_ALIGN, 3);
        StringAppend(gStringVar1, gStringVar2);
        PrintTextOnWindow(WINDOW_ARR_ID_LVL_NICK_GENDER, gStringVar1, 4, 2, 0, PSS_COLOR_WHITE_BLACK_SHADOW);
    }

    GetMonNickname(mon, gStringVar1);
    PrintTextOnWindow(WINDOW_ARR_ID_LVL_NICK_GENDER, gStringVar1, 40, 2, 0, PSS_COLOR_WHITE_BLACK_SHADOW);

    if (summary->species2 != SPECIES_NIDORAN_M && summary->species2 != SPECIES_NIDORAN_F)
    {
        switch (GetMonGender(mon))
        {
        case MON_MALE:
            PrintTextOnWindow(WINDOW_ARR_ID_LVL_NICK_GENDER, gText_MaleSymbol, 105, 2, 0, PSS_COLOR_MALE_GENDER_SYMBOL);
            break;
        case MON_FEMALE:
            PrintTextOnWindow(WINDOW_ARR_ID_LVL_NICK_GENDER, gText_FemaleSymbol, 105, 2, 0, PSS_COLOR_FEMALE_GENDER_SYMBOL);
            break;
        }
    }

    PutWindowTilemap(WINDOW_ARR_ID_LVL_NICK_GENDER);
}

static void ShowCantForgetHMs(u8 taskId)
{
    FillWindowPixelBuffer(WINDOW_ARR_ID_MOVES_WINDOW_LEFT, PIXEL_FILL(0));

    if (sMonSummaryScreen->currPageIndex == PSS_PAGE_CONTEST_MOVES)
    {
        FillBgTilemapBufferRect(1, TILE_EMPTY_HEART, 6, 7, 8, 1, 5);
        FillBgTilemapBufferRect(1, TILE_EMPTY_HEART_2, 6, 8, 8, 1, 5);
        FillBgTilemapBufferRect(1, TILE_EMPTY_HEART_3, 6, 9, 8, 1, 5);
        FillBgTilemapBufferRect(1, TILE_EMPTY_HEART_4, 6, 10, 8, 1, 5);
        CopyBgTilemapBufferToVram(1);
    }

    PrintTextOnWindow(WINDOW_ARR_ID_MOVES_WINDOW_LEFT, gText_HMMovesCantBeForgotten2, 7, 50, 0, PSS_COLOR_BLACK_GRAY_SHADOW);
    PutWindowTilemap(WINDOW_ARR_ID_MOVES_WINDOW_LEFT);
}

u8 GetMoveSlotToReplace(void)
{
    return sMoveSlotToReplace;
}

static void DrawPagination(bool8 currentPagePressed) // Updates the pagination dots at the top of the summary screen
{
    u16 *alloced = Alloc(32);
    u8 i;

    for (i = 0; i < 4; i++)
    {
        u8 j = i * 2;

        if (i < sMonSummaryScreen->minPageIndex)
        {
            alloced[j + 0] = 0x15A;
            alloced[j + 1] = 0x15A;
            alloced[j + 8] = 0x16C;
            alloced[j + 9] = 0x16C;
        }
        else if (i > sMonSummaryScreen->maxPageIndex)
        {
            alloced[j + 0] = 0x15B;
            alloced[j + 1] = 0x15B;
            alloced[j + 8] = 0x15B;
            alloced[j + 9] = 0x15B;
        }
        else if (i < sMonSummaryScreen->currPageIndex)
        {
            alloced[j + 0] = 0x18A;
            alloced[j + 1] = 0x15A;
            alloced[j + 8] = 0x19A;
            alloced[j + 9] = 0x16C;
        }
        else if (i == sMonSummaryScreen->currPageIndex)
        {
            if (currentPagePressed)
            {
                alloced[j + 0] = 0x18B;
                alloced[j + 8] = 0x19B;
            }
            else
            {
                alloced[j + 0] = 0x16A;
                alloced[j + 8] = 0x17A;
            }

            if (i != sMonSummaryScreen->maxPageIndex)
            {
                alloced[j + 1] = 0x169;
                alloced[j + 9] = 0x179;
            }
            else
            {
                alloced[j + 1] = 0x189;
                alloced[j + 9] = 0x199;
            }
        }
        else if (i != sMonSummaryScreen->maxPageIndex)
        {
            alloced[j + 0] = 0x16B;
            alloced[j + 1] = 0x16D;
            alloced[j + 8] = 0x17B;
            alloced[j + 9] = 0x17D;
        }
        else
        {
            alloced[j + 0] = 0x16B;
            alloced[j + 1] = 0x16E;
            alloced[j + 8] = 0x17B;
            alloced[j + 9] = 0x17E;
        }
    }
    CopyToBgTilemapBufferRect_ChangePalette(3, alloced, 12, 0, 8, 2, 16);
    ScheduleBgCopyTilemapToVram(3);
    Free(alloced);
}

static void PrintPageSpecificText(u8 pageIndex)
{
    PrintTitleBar(pageIndex, FALSE);
    sTextPrinterFunctions[pageIndex]();
}

static void SetTypeSpritePosAndPal(u8 typeId, u8 x, u8 y, u8 spriteArrayId)
{
    struct Sprite *sprite = &gSprites[sMonSummaryScreen->spriteIds[spriteArrayId]];
    StartSpriteAnim(sprite, typeId);
    sprite->oam.paletteNum = 13;
    sprite->x = x + 16;
    sprite->y = y + 8;
    SetSpriteInvisibility(spriteArrayId, FALSE);
}

static void PrintInfoPage(void)
{
    if (!sMonSummaryScreen->lastWasEgg && sMonSummaryScreen->summary.isEgg)
        return;

    if (sMonSummaryScreen->summary.isEgg)
        PrintInfoPageEgg();
    else
        PrintInfoPageMon();
}

static void PrintInfoPageEgg(void)
{
    const u8 *text;
    struct Pokemon *mon = &sMonSummaryScreen->currentMon;
    struct PokeSummary *sum = &sMonSummaryScreen->summary;
    u16 dexNum = SpeciesToPokedexNum(sum->species);
    FillWindowPixelBuffer(WINDOW_ARR_ID_INFO_RIGHT, PIXEL_FILL(0));
    FillWindowPixelBuffer(WINDOW_ARR_ID_INFO_MEMO, PIXEL_FILL(0));

    GetMonNickname(mon, gStringVar1);
    PrintTextOnWindow(WINDOW_ARR_ID_INFO_RIGHT, gStringVar1, 47, 19, 0, PSS_COLOR_BLACK_GRAY_SHADOW);

    if (sum->sanity || sum->friendship > 40)
        text = gText_EggWillTakeALongTime;
    else if (sum->friendship > 10)
        text = gText_EggWillTakeSomeTime;
    else if (sum->friendship > 5)
        text = gText_EggWillHatchSoon;
    else
        text = gText_EggAboutToHatch;
    PrintTextOnWindow(WINDOW_ARR_ID_INFO_RIGHT, text, 7, 45, 0, PSS_COLOR_BLACK_GRAY_SHADOW);

    text = gText_OddEggFoundByCouple;
    if (sum->sanity != 1)
    {
        if (sum->metLocation == METLOC_FATEFUL_ENCOUNTER)
            text = gText_PeculiarEggNicePlace;
        else if (DidMonComeFromAnyGBAGame() == FALSE || DoesMonOTMatchOwner() == FALSE)
            text = gText_PeculiarEggTrade;
        else if (sum->metLocation == METLOC_SPECIAL_EGG)
            text = (DidMonComeFromRSE() == TRUE) ? gText_EggFromHotSprings : gText_EggFromTraveler;
        else if (sum->metLocation == METLOC_GOLDENROD_CITY)
            text = gText_EggFromPokecomCenter;
        else if (sum->metLocation == METLOC_VIOLET_CITY)
            text = gText_EggFromElm;
    }
    PrintTextOnWindow(WINDOW_ARR_ID_INFO_MEMO, text, 0, 3, 0, PSS_COLOR_BLACK_GRAY_SHADOW);

    ScheduleBgCopyTilemapToVram(0);
    PutWindowTilemap(WINDOW_ARR_ID_INFO_RIGHT);
    PutWindowTilemap(WINDOW_ARR_ID_INFO_MEMO);
}

static void PrintInfoPageMon(void)
{
    struct Pokemon *mon = &sMonSummaryScreen->currentMon;
    struct PokeSummary *summary = &sMonSummaryScreen->summary;
    u16 dexNum = SpeciesToPokedexNum(summary->species);
    FillWindowPixelBuffer(WINDOW_ARR_ID_INFO_RIGHT, PIXEL_FILL(0));
    FillWindowPixelBuffer(WINDOW_ARR_ID_INFO_MEMO, PIXEL_FILL(0));

    if (dexNum == 0xFFFF)
        StringCopy(gStringVar1, gText_ThreeMarks);
    else
        ConvertIntToDecimalStringN(gStringVar1, dexNum, STR_CONV_MODE_LEADING_ZEROS, 3);
    PrintTextOnWindow(WINDOW_ARR_ID_INFO_RIGHT, gStringVar1, 47, 5, 0, PSS_COLOR_BLACK_GRAY_SHADOW);

    PrintTextOnWindow(WINDOW_ARR_ID_INFO_RIGHT, gSpeciesNames[summary->species2], 47, 19, 0, PSS_COLOR_BLACK_GRAY_SHADOW);

    PrintTextOnWindow(WINDOW_ARR_ID_INFO_RIGHT, summary->OTName, 47, 49, 0, PSS_COLOR_BLACK_GRAY_SHADOW);

    ConvertIntToDecimalStringN(gStringVar1, (u16)summary->OTID, STR_CONV_MODE_LEADING_ZEROS, 5);
    PrintTextOnWindow(WINDOW_ARR_ID_INFO_RIGHT, gStringVar1, 47, 64, 0, PSS_COLOR_BLACK_GRAY_SHADOW);

    if (sMonSummaryScreen->summary.item == ITEM_NONE)
        StringCopy(gStringVar1, gText_None);
    else
        CopyItemName(sMonSummaryScreen->summary.item, gStringVar1);
    PrintTextOnWindow(WINDOW_ARR_ID_INFO_RIGHT, gStringVar1, 47, 79, 0, PSS_COLOR_BLACK_GRAY_SHADOW);

    BufferMonTrainerMemo();
    PrintTextOnWindow(WINDOW_ARR_ID_INFO_MEMO, gStringVar4, 0, 3, 0, PSS_COLOR_BLACK_GRAY_SHADOW);

    ScheduleBgCopyTilemapToVram(0);
    PutWindowTilemap(WINDOW_ARR_ID_INFO_RIGHT);
    PutWindowTilemap(WINDOW_ARR_ID_INFO_MEMO);
}

static void BufferMonTrainerMemo(void)
{
    struct PokeSummary *sum = &sMonSummaryScreen->summary;
    const u8 *text;
    u16 metlocation = sum->metLocation;

    DynamicPlaceholderTextUtil_Reset();
    DynamicPlaceholderTextUtil_SetPlaceholderPtr(0, sBlackTextColor);
    DynamicPlaceholderTextUtil_SetPlaceholderPtr(1, sBlackTextColor);
    BufferNatureString();

    if (InBattleFactory() == TRUE || InSlateportBattleTent() == TRUE || IsInGamePartnerMon() == TRUE)
    {
        DynamicPlaceholderTextUtil_ExpandPlaceholders(gStringVar4, gText_XNature);
    }
    else
    {
        u16 mapsecShift = MAPSEC_NEW_BARK_TOWN;
        u16 maxMapsec = MAPSEC_NONE;
        u8 *metLevelString = Alloc(32);
        u8 *metLocationString = Alloc(32);
        GetMetLevelString(metLevelString);

        if (metlocation >= MAPSEC_NONE)
        {   // johto location
            if(sum->locationBit)
                metlocation += 39;
            mapsecShift = EMERALD_MAPSEC_START;
            maxMapsec = MAPSEC_NONE + NUM_NEW_MAPSECS; // should be 0x107 and down
        }
        else
        {   //mon from vanilla mapsecs
            mapsecShift = EMERALD_MAPSEC_START;
            maxMapsec = EMERALD_MAPSEC_END - EMERALD_MAPSEC_START;
        }

        if (metlocation < maxMapsec)
        {
            GetMapNameForSummaryScreen(metLocationString, metlocation + mapsecShift);
            DynamicPlaceholderTextUtil_SetPlaceholderPtr(4, metLocationString);
        }

        if (DoesMonOTMatchOwner() == TRUE)
        {
            if (sum->metLevel == 0)
                text = (metlocation >= maxMapsec) ? gText_XNatureHatchedSomewhereAt : gText_XNatureHatchedAtYZ;
            else
                text = (metlocation >= maxMapsec) ? gText_XNatureMetSomewhereAt : gText_XNatureMetAtYZ;
        }
        else if (metlocation == METLOC_FATEFUL_ENCOUNTER)
        {
            text = gText_XNatureFatefulEncounter;
        }
        else if (metlocation != METLOC_IN_GAME_TRADE && DidMonComeFromAnyGBAGame())
        {
            text = (metlocation >= maxMapsec) ? gText_XNatureObtainedInTrade : gText_XNatureProbablyMetAt;
        }
        else
        {
            text = gText_XNatureObtainedInTrade;
        }

        DynamicPlaceholderTextUtil_ExpandPlaceholders(gStringVar4, text);
        Free(metLevelString);
        Free(metLocationString);
    }
}

static void BufferNatureString(void)
{
    struct PokemonSummaryScreenData *sumStruct = sMonSummaryScreen;
    DynamicPlaceholderTextUtil_SetPlaceholderPtr(2, gNatureNamePointers[sumStruct->summary.nature]);
}

static void GetMetLevelString(u8 *output)
{
    u8 level = sMonSummaryScreen->summary.metLevel;
    if (level == 0)
        level = EGG_HATCH_LEVEL;
    ConvertIntToDecimalStringN(output, level, STR_CONV_MODE_LEFT_ALIGN, 3);
    DynamicPlaceholderTextUtil_SetPlaceholderPtr(3, output);
}

static bool8 DoesMonOTMatchOwner(void)
{
    struct PokeSummary *sum = &sMonSummaryScreen->summary;
    u32 trainerId;
    u8 gender;

    if (sMonSummaryScreen->monList.mons == gEnemyParty)
    {
        u8 multiID = GetMultiplayerId() ^ 1;
        trainerId = gLinkPlayers[multiID].trainerId & 0xFFFF;
        gender = gLinkPlayers[multiID].gender;
        StringCopy(gStringVar1, gLinkPlayers[multiID].name);
    }
    else
    {
        trainerId = GetPlayerIDAsU32() & 0xFFFF;
        gender = gSaveBlock2Ptr->playerGender;
        StringCopy(gStringVar1, gSaveBlock2Ptr->playerName);
    }

    if (gender != sum->OTGender || trainerId != (sum->OTID & 0xFFFF) || StringCompareWithoutExtCtrlCodes(gStringVar1, sum->OTName))
        return FALSE;
    else
        return TRUE;
}

static bool8 DidMonComeFromOfficialGBAGames(void)
{
    struct PokeSummary *sum = &sMonSummaryScreen->summary;
    if (sum->metGame > 0 && sum->metGame <= VERSION_LEAF_GREEN)
        return TRUE;
    return FALSE;
}

static bool8 DidMonComeFromCrystalDust(void)
{
    struct PokeSummary *sum = &sMonSummaryScreen->summary;
    return sum->metGame == VERSION_CRYSTAL_DUST;
}

static bool8 DidMonComeFromAnyGBAGame(void)
{
    return DidMonComeFromOfficialGBAGames() || DidMonComeFromCrystalDust();
}

static bool8 DidMonComeFromRSE(void)
{
    struct PokeSummary *sum = &sMonSummaryScreen->summary;
    if (sum->metGame >= VERSION_SAPPHIRE && sum->metGame <= VERSION_EMERALD)
        return TRUE;
    return FALSE;
}

static bool8 DidMonComeFromFRLG(void)
{
    struct PokeSummary *sum = &sMonSummaryScreen->summary;
    if (sum->metGame == VERSION_FIRE_RED || sum->metGame == VERSION_LEAF_GREEN)
        return TRUE;
    return FALSE;
}

static bool8 IsInGamePartnerMon(void)
{
    if ((gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER) && gMain.inBattle && gMapHeader.mapLayoutId != LAYOUT_TEAM_ROCKET_BASE_B2F)
        if (sMonSummaryScreen->curMonIndex == 1 || sMonSummaryScreen->curMonIndex == 4 || sMonSummaryScreen->curMonIndex == 5)
            return TRUE;
    return FALSE;
}

static void PrintSkillsPage(void)
{
    u8 x, i;
    u16 *dst;
    struct Pokemon *mon = &sMonSummaryScreen->currentMon;
    struct PokeSummary *summary = &sMonSummaryScreen->summary;
    FillWindowPixelBuffer(WINDOW_ARR_ID_SKILLS_RIGHT, PIXEL_FILL(0));
    FillWindowPixelBuffer(WINDOW_ARR_ID_SKILLS_EXP_NEXT_ABILITY_NAME, PIXEL_FILL(0));
    FillWindowPixelBuffer(WINDOW_ARR_ID_SKILLS_ABILITY_TEXT, PIXEL_FILL(0));

    ConvertIntToDecimalStringN(gStringVar1, summary->currentHP, STR_CONV_MODE_LEFT_ALIGN, 3);
    StringAppend(gStringVar1, gText_Slash);
    ConvertIntToDecimalStringN(gStringVar2, summary->maxHP, STR_CONV_MODE_LEFT_ALIGN, 3);
    StringAppend(gStringVar1, gStringVar2);
    x = GetStringRightAlignXOffset(1, gStringVar1, 69);
    PrintTextOnWindow(WINDOW_ARR_ID_SKILLS_RIGHT, gStringVar1, x, 4, 0, PSS_COLOR_BLACK_GRAY_SHADOW);

    ConvertIntToDecimalStringN(gStringVar1, summary->atk, STR_CONV_MODE_LEFT_ALIGN, 3);
    x = GetStringRightAlignXOffset(1, gStringVar1, 69);
    PrintTextOnWindow(WINDOW_ARR_ID_SKILLS_RIGHT, gStringVar1, x, 22, 0, PSS_COLOR_BLACK_GRAY_SHADOW);

    ConvertIntToDecimalStringN(gStringVar1, summary->def, STR_CONV_MODE_LEFT_ALIGN, 3);
    x = GetStringRightAlignXOffset(1, gStringVar1, 69);
    PrintTextOnWindow(WINDOW_ARR_ID_SKILLS_RIGHT, gStringVar1, x, 35, 0, PSS_COLOR_BLACK_GRAY_SHADOW);

    ConvertIntToDecimalStringN(gStringVar1, summary->spatk, STR_CONV_MODE_LEFT_ALIGN, 3);
    x = GetStringRightAlignXOffset(1, gStringVar1, 69);
    PrintTextOnWindow(WINDOW_ARR_ID_SKILLS_RIGHT, gStringVar1, x, 48, 0, PSS_COLOR_BLACK_GRAY_SHADOW);

    ConvertIntToDecimalStringN(gStringVar1, summary->spdef, STR_CONV_MODE_LEFT_ALIGN, 3);
    x = GetStringRightAlignXOffset(1, gStringVar1, 69);
    PrintTextOnWindow(WINDOW_ARR_ID_SKILLS_RIGHT, gStringVar1, x, 61, 0, PSS_COLOR_BLACK_GRAY_SHADOW);

    ConvertIntToDecimalStringN(gStringVar1, summary->speed, STR_CONV_MODE_LEFT_ALIGN, 3);
    x = GetStringRightAlignXOffset(1, gStringVar1, 69);
    PrintTextOnWindow(WINDOW_ARR_ID_SKILLS_RIGHT, gStringVar1, x, 74, 0, PSS_COLOR_BLACK_GRAY_SHADOW);

    ConvertIntToDecimalStringN(gStringVar1, summary->exp, STR_CONV_MODE_RIGHT_ALIGN, 7);
    x = GetStringRightAlignXOffset(1, gStringVar1, 70);
    PrintTextOnWindow(WINDOW_ARR_ID_SKILLS_RIGHT, gStringVar1, x, 87, 0, PSS_COLOR_BLACK_GRAY_SHADOW);

    if (summary->level < MAX_LEVEL)
        ConvertIntToDecimalStringN(gStringVar1, gExperienceTables[gBaseStats[summary->species].growthRate][summary->level + 1] - summary->exp, STR_CONV_MODE_RIGHT_ALIGN, 6);
    else
        ConvertIntToDecimalStringN(gStringVar1, 0, STR_CONV_MODE_RIGHT_ALIGN, 6);
    x = GetStringRightAlignXOffset(1, gStringVar1, 70);
    PrintTextOnWindow(WINDOW_ARR_ID_SKILLS_RIGHT, gStringVar1, x, 100, 0, PSS_COLOR_BLACK_GRAY_SHADOW);

    PrintTextOnWindow(WINDOW_ARR_ID_SKILLS_EXP_NEXT_ABILITY_NAME, gText_ExpPoints, 2, 7, 0, PSS_COLOR_BLACK_GRAY_SHADOW);
    PrintTextOnWindow(WINDOW_ARR_ID_SKILLS_EXP_NEXT_ABILITY_NAME, gText_NextLv, 2, 20, 0, PSS_COLOR_BLACK_GRAY_SHADOW);

    PrintTextOnWindow(WINDOW_ARR_ID_SKILLS_ABILITY_TEXT, gAbilityNames[GetAbilityBySpecies(sMonSummaryScreen->summary.species, summary->abilityNum)], 74, 1, 0, PSS_COLOR_BLACK_GRAY_SHADOW);

    PrintTextOnWindow(WINDOW_ARR_ID_SKILLS_ABILITY_TEXT, gAbilityDescriptionPointers[GetAbilityBySpecies(sMonSummaryScreen->summary.species, summary->abilityNum)], 10, 15, 0, PSS_COLOR_BLACK_GRAY_SHADOW);

    ScheduleBgCopyTilemapToVram(0);
    PutWindowTilemap(WINDOW_ARR_ID_SKILLS_RIGHT);
    PutWindowTilemap(WINDOW_ARR_ID_SKILLS_EXP_NEXT_ABILITY_NAME);
    PutWindowTilemap(WINDOW_ARR_ID_SKILLS_ABILITY_TEXT);
}

static void PrintBattleMoves(void)
{
    u32 i;
    FillWindowPixelBuffer(WINDOW_ARR_ID_MOVES_WINDOW_TOP_FOUR_MOVES, PIXEL_FILL(0));

    for (i = 0; i < MAX_MON_MOVES; i++)
        PrintMoveNameAndPP(i);

    ScheduleBgCopyTilemapToVram(0);
    PutWindowTilemap(WINDOW_ARR_ID_MOVES_WINDOW_TOP_FOUR_MOVES);
}

static void PrintMoveNameAndPP(u8 moveIndex)
{
    u32 pp, color, x;
    struct PokeSummary *summary = &sMonSummaryScreen->summary;
    struct Pokemon *mon = &sMonSummaryScreen->currentMon;

    if (summary->moves[moveIndex] != MOVE_NONE)
    {
        pp = CalculatePPWithBonus(summary->moves[moveIndex], summary->ppBonuses, moveIndex);
        PrintTextOnWindow(WINDOW_ARR_ID_MOVES_WINDOW_TOP_FOUR_MOVES, gMoveNames[summary->moves[moveIndex]], 3, moveIndex * 28 + 5, 0, PSS_COLOR_BLACK_GRAY_SHADOW);
        ConvertIntToDecimalStringN(gStringVar1, summary->pp[moveIndex], STR_CONV_MODE_RIGHT_ALIGN, 2);
        ConvertIntToDecimalStringN(gStringVar2, pp, STR_CONV_MODE_RIGHT_ALIGN, 2);
        StringAppend(gStringVar1, gText_Slash);
        StringAppend(gStringVar1, gStringVar2);
        switch (GetCurrentPpToMaxPpState(summary->pp[moveIndex], pp))
        {
            case PP_MANY:
                color = PSS_COLOR_PP_MANY;
                break;
            case PP_SOME:
                color = PSS_COLOR_PP_SOME;
                break;
            case PP_FEW:
                color = PSS_COLOR_PP_FEW;
                break;
            case PP_NO_PP:
                color = PSS_COLOR_PP_NO_PP;
                break;
        }

        PrintTextOnWindowSmall(WINDOW_ARR_ID_MOVES_WINDOW_TOP_FOUR_MOVES, sText_PP, 36, moveIndex * 28 + 16, 0, PSS_COLOR_BLACK_GRAY_SHADOW);
        PrintTextOnWindow(WINDOW_ARR_ID_MOVES_WINDOW_TOP_FOUR_MOVES, gStringVar1, 46, moveIndex * 28 + 16, 0, color);
    }
    else
    {
        PrintTextOnWindow(WINDOW_ARR_ID_MOVES_WINDOW_TOP_FOUR_MOVES, gText_OneDash, 3, moveIndex * 28 + 5, 0, PSS_COLOR_BLACK_GRAY_SHADOW);

        PrintTextOnWindowSmall(WINDOW_ARR_ID_MOVES_WINDOW_TOP_FOUR_MOVES, sText_PP, 36, moveIndex * 28 + 16, 0, PSS_COLOR_BLACK_GRAY_SHADOW);
        PrintTextOnWindow(WINDOW_ARR_ID_MOVES_WINDOW_TOP_FOUR_MOVES, gText_TwoDashes, 46, moveIndex * 28 + 16, 0, PSS_COLOR_BLACK_GRAY_SHADOW);
    }
}

static void PrintContestMoves(void)
{
    u32 i;
    FillWindowPixelBuffer(WINDOW_ARR_ID_MOVES_WINDOW_TOP_FOUR_MOVES, PIXEL_FILL(0));

    for (i = 0; i < MAX_MON_MOVES; i++)
        PrintMoveNameAndPP(i);

    ScheduleBgCopyTilemapToVram(0);
    PutWindowTilemap(WINDOW_ARR_ID_MOVES_WINDOW_TOP_FOUR_MOVES);
}

static void PrintMoveDetails(u16 move)
{
    u32 appealCount, jamCount;
    struct Pokemon *mon = &sMonSummaryScreen->currentMon;
    struct PokeSummary *summary = &sMonSummaryScreen->summary;

    SetSpriteInvisibility(SPRITE_ARR_ID_MON, TRUE);
    SetSpriteInvisibility(SPRITE_ARR_ID_STATUS, TRUE);
    sMonSummaryScreen->markingsSprite->invisible = TRUE;
    FillWindowPixelBuffer(WINDOW_ARR_ID_MOVES_WINDOW_LEFT, PIXEL_FILL(0));

    SetSpriteInvisibility(SPRITE_ARR_ID_MON_ICON, FALSE);
    SetTypeSpritePosAndPal(gBaseStats[summary->species].type1, 48, 33, SPRITE_ARR_ID_TYPE);

    if (gBaseStats[summary->species].type1 != gBaseStats[summary->species].type2)
    {
        SetTypeSpritePosAndPal(gBaseStats[summary->species].type2, 84, 33, SPRITE_ARR_ID_TYPE + 1);
        SetSpriteInvisibility(SPRITE_ARR_ID_TYPE + 1, FALSE);
    }
    else
    {
        SetSpriteInvisibility(SPRITE_ARR_ID_TYPE + 1, TRUE);
    }

    if (move != MOVE_NONE)
    {
        if (sMonSummaryScreen->currPageIndex == PSS_PAGE_BATTLE_MOVES)
        {
            if (gBattleMoves[move].power < 2)
                StringCopy(gStringVar1, gText_ThreeDashes);
            else
                ConvertIntToDecimalStringN(gStringVar1, gBattleMoves[move].power, STR_CONV_MODE_RIGHT_ALIGN, 3);

            PrintTextOnWindow(WINDOW_ARR_ID_MOVES_WINDOW_LEFT, gStringVar1, 57, POWER_AND_ACCURACY_Y, 0, PSS_COLOR_BLACK_GRAY_SHADOW);

            if (gBattleMoves[move].accuracy == 0)
                StringCopy(gStringVar1, gText_ThreeDashes);
            else
                ConvertIntToDecimalStringN(gStringVar1, gBattleMoves[move].accuracy, STR_CONV_MODE_RIGHT_ALIGN, 3);

            PrintTextOnWindow(WINDOW_ARR_ID_MOVES_WINDOW_LEFT, gStringVar1, 57, POWER_AND_ACCURACY_Y_2, 0, PSS_COLOR_BLACK_GRAY_SHADOW);

            PrintTextOnWindow(WINDOW_ARR_ID_MOVES_WINDOW_LEFT, gMoveDescriptionPointers[move - 1], 7, 50, 0, PSS_COLOR_BLACK_GRAY_SHADOW);
        }
        else
        {
            FillBgTilemapBufferRect(1, TILE_EMPTY_HEART, 6, 7, 8, 1, 5);
            FillBgTilemapBufferRect(1, TILE_EMPTY_HEART_2, 6, 8, 8, 1, 5);
            FillBgTilemapBufferRect(1, TILE_EMPTY_HEART_3, 6, 9, 8, 1, 5);
            FillBgTilemapBufferRect(1, TILE_EMPTY_HEART_4, 6, 10, 8, 1, 5);

            appealCount = gContestEffects[gContestMoves[move].effect].appeal / 10;
            FillBgTilemapBufferRect(1, TILE_FILLED_APPEAL_HEART, 6, 7, appealCount, 1, 5);
            FillBgTilemapBufferRect(1, TILE_FILLED_APPEAL_HEART_2, 6, 8, appealCount, 1, 5);

            jamCount = gContestEffects[gContestMoves[move].effect].jam / 10;
            FillBgTilemapBufferRect(1, TILE_FILLED_JAM_HEART, 6, 9, jamCount, 1, 5);
            FillBgTilemapBufferRect(1, TILE_FILLED_JAM_HEART_2, 6, 10, jamCount, 1, 5);

            PrintTextOnWindow(WINDOW_ARR_ID_MOVES_WINDOW_LEFT, gContestEffectDescriptionPointers[gContestMoves[move].effect], 7, 50, 0, PSS_COLOR_BLACK_GRAY_SHADOW);
            CopyBgTilemapBufferToVram(1);
        }

        PutWindowTilemap(WINDOW_ARR_ID_MOVES_WINDOW_LEFT);
    }
    else
    {
        if (sMonSummaryScreen->currPageIndex == PSS_PAGE_CONTEST_MOVES)
        {
            FillBgTilemapBufferRect(1, TILE_EMPTY_HEART, 6, 7, 8, 1, 5);
            FillBgTilemapBufferRect(1, TILE_EMPTY_HEART_2, 6, 8, 8, 1, 5);
            FillBgTilemapBufferRect(1, TILE_EMPTY_HEART_3, 6, 9, 8, 1, 5);
            FillBgTilemapBufferRect(1, TILE_EMPTY_HEART_4, 6, 10, 8, 1, 5);
            CopyBgTilemapBufferToVram(1);
        }

        ClearWindowTilemap(WINDOW_ARR_ID_MOVES_WINDOW_LEFT);
    }

    ScheduleBgCopyTilemapToVram(0);
}

static void PrintNewMoveDetailsOrCancelText(void)
{
    u32 pp, x;
    FillWindowPixelBuffer(WINDOW_ARR_ID_MOVES_WINDOW_LAST_MOVE, PIXEL_FILL(0));

    if (sMonSummaryScreen->newMove != MOVE_NONE)
    {
        pp = gBattleMoves[sMonSummaryScreen->newMove].pp;
        PrintTextOnWindow(WINDOW_ARR_ID_MOVES_WINDOW_LAST_MOVE, gMoveNames[sMonSummaryScreen->newMove], 3, 5, 0, PSS_COLOR_BLACK_GRAY_SHADOW);
        ConvertIntToDecimalStringN(gStringVar1, pp, STR_CONV_MODE_RIGHT_ALIGN, 2);
        ConvertIntToDecimalStringN(gStringVar2, pp, STR_CONV_MODE_RIGHT_ALIGN, 2);
        StringAppend(gStringVar1, gText_Slash);
        StringAppend(gStringVar1, gStringVar2);
        PrintTextOnWindowSmall(WINDOW_ARR_ID_MOVES_WINDOW_LAST_MOVE, sText_PP, 36, 16, 0, PSS_COLOR_BLACK_GRAY_SHADOW);
        PrintTextOnWindow(WINDOW_ARR_ID_MOVES_WINDOW_LAST_MOVE, gStringVar1, 46, 16, 0, PSS_COLOR_BLACK_GRAY_SHADOW);
    }
    else
    {
        PrintTextOnWindow(WINDOW_ARR_ID_MOVES_WINDOW_LAST_MOVE, gText_Cancel, 3, 5, 0, PSS_COLOR_BLACK_GRAY_SHADOW);
    }
}

static void SwapMovesNamesPP(u8 moveIndex1, u8 moveIndex2)
{
    u32 i;
    FillWindowPixelBuffer(WINDOW_ARR_ID_MOVES_WINDOW_TOP_FOUR_MOVES, PIXEL_FILL(0));

    for (i = 0; i < MAX_MON_MOVES; i++)
        PrintMoveNameAndPP(i);
}

static void ResetSpriteIds(void)
{
    u8 i;
    for (i = 0; i < ARRAY_COUNT(sMonSummaryScreen->spriteIds); i++)
        sMonSummaryScreen->spriteIds[i] = SPRITE_NONE;
}

static void DestroySpriteInArray(u8 spriteArrayId)
{
    if (sMonSummaryScreen->spriteIds[spriteArrayId] == SPRITE_NONE)
        return;

    DestroySprite(&gSprites[sMonSummaryScreen->spriteIds[spriteArrayId]]);
    sMonSummaryScreen->spriteIds[spriteArrayId] = SPRITE_NONE;
}

static void SetSpriteInvisibility(u8 spriteArrayId, bool8 invisible)
{
    gSprites[sMonSummaryScreen->spriteIds[spriteArrayId]].invisible = invisible;
}

static void HidePageSpecificSprites(void)
{
    // Keeps Pokémon, caught ball and status sprites visible.
    u8 i;

    for (i = SPRITE_ARR_ID_BEGIN_TRANSIENT; i < ARRAY_COUNT(sMonSummaryScreen->spriteIds); i++)
        if (sMonSummaryScreen->spriteIds[i] != SPRITE_NONE)
            SetSpriteInvisibility(i, TRUE);

    for (i = 0; i < HP_BAR_SPRITES_COUNT; i++)
        sHealthBar->sprites[i]->invisible = TRUE;

    for (i = 0; i < EXP_BAR_SPRITES_COUNT; i++)
        sExpBar->sprites[i]->invisible = TRUE;
}

static void SetTypeIcons(void)
{
    switch (sMonSummaryScreen->currPageIndex)
    {
    case PSS_PAGE_INFO:
        SetMonTypeIcons();
        break;
    case PSS_PAGE_BATTLE_MOVES:
        SetMoveTypeIcons();
        SetNewMoveTypeIcon();
        break;
    case PSS_PAGE_CONTEST_MOVES:
        SetContestMoveTypeIcons();
        SetNewMoveTypeIcon();
        break;
    }
}

static void CreateMoveTypeIcons(void)
{
    u8 i;

    for (i = SPRITE_ARR_ID_TYPE; i < SPRITE_ARR_ID_TYPE + 7; i++)
    {
        if (sMonSummaryScreen->spriteIds[i] == SPRITE_NONE)
            sMonSummaryScreen->spriteIds[i] = CreateSprite(&sSpriteTemplate_MoveTypes, 0, 0, 2);

        SetSpriteInvisibility(i, TRUE);
    }
}

static void SetMonTypeIcons(void)
{
    struct PokeSummary *summary = &sMonSummaryScreen->summary;

    if (summary->isEgg)
    {
        SetSpriteInvisibility(SPRITE_ARR_ID_TYPE, TRUE);
        SetSpriteInvisibility(SPRITE_ARR_ID_TYPE + 1, TRUE);
        return;
    }

    SetTypeSpritePosAndPal(gBaseStats[summary->species].type1, 167, 49, SPRITE_ARR_ID_TYPE);
    SetSpriteInvisibility(SPRITE_ARR_ID_TYPE, FALSE);

    if (gBaseStats[summary->species].type1 != gBaseStats[summary->species].type2)
    {
        SetTypeSpritePosAndPal(gBaseStats[summary->species].type2, 203, 49, SPRITE_ARR_ID_TYPE + 1);
        SetSpriteInvisibility(SPRITE_ARR_ID_TYPE + 1, FALSE);
    }
    else
    {
        SetSpriteInvisibility(SPRITE_ARR_ID_TYPE + 1, TRUE);
    }
}

static void SetMoveTypeIcons(void)
{
    u8 i;
    struct PokeSummary *summary = &sMonSummaryScreen->summary;
    struct Pokemon *mon = &sMonSummaryScreen->currentMon;
    u16 species = GetMonData(mon, MON_DATA_SPECIES);

    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if (summary->moves[i] != MOVE_NONE)
            SetTypeSpritePosAndPal(gBattleMoves[summary->moves[i]].type, 123, i * 28 + 19, SPRITE_ARR_ID_TYPE + 2 + i);
        else
            SetSpriteInvisibility(SPRITE_ARR_ID_TYPE + 2 + i, TRUE);
    }
}

static void SetContestMoveTypeIcons(void)
{
    u8 i;
    struct PokeSummary *summary = &sMonSummaryScreen->summary;

    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if (summary->moves[i] != MOVE_NONE)
            SetTypeSpritePosAndPal(NUMBER_OF_MON_TYPES + gContestMoves[summary->moves[i]].contestCategory, 123, i * 28 + 19, SPRITE_ARR_ID_TYPE + 2 + i);
        else
            SetSpriteInvisibility(SPRITE_ARR_ID_TYPE + 2 + i, TRUE);
    }
}

static void SetNewMoveTypeIcon(void)
{
    struct Pokemon *mon = &sMonSummaryScreen->currentMon;
    u16 species = GetMonData(mon, MON_DATA_SPECIES);

    if (sMonSummaryScreen->newMove == MOVE_NONE)
        SetSpriteInvisibility(SPRITE_ARR_ID_TYPE + 6, TRUE);
    else if (sMonSummaryScreen->currPageIndex == PSS_PAGE_BATTLE_MOVES)
        SetTypeSpritePosAndPal(gBattleMoves[sMonSummaryScreen->newMove].type, 123, 131, SPRITE_ARR_ID_TYPE + 6);
    else
        SetTypeSpritePosAndPal(NUMBER_OF_MON_TYPES + gContestMoves[sMonSummaryScreen->newMove].contestCategory, 123, 131, SPRITE_ARR_ID_TYPE + 6);
}

static void SwapMovesTypeSprites(u8 moveIndex1, u8 moveIndex2)
{
    struct Sprite *sprite1 = &gSprites[sMonSummaryScreen->spriteIds[moveIndex1 + SPRITE_ARR_ID_TYPE + 2]];
    struct Sprite *sprite2 = &gSprites[sMonSummaryScreen->spriteIds[moveIndex2 + SPRITE_ARR_ID_TYPE + 2]];

    u8 temp = sprite1->animNum;
    sprite1->animNum = sprite2->animNum;
    sprite2->animNum = temp;

    temp = sprite1->oam.paletteNum;
    sprite1->oam.paletteNum = sprite2->oam.paletteNum;
    sprite2->oam.paletteNum = temp;

    sprite1->animBeginning = TRUE;
    sprite1->animEnded = FALSE;
    sprite2->animBeginning = TRUE;
    sprite2->animEnded = FALSE;
}

static u8 LoadMonGfxAndSprite(struct Pokemon *mon, s16 *state)
{
    const struct CompressedSpritePalette *pal;
    struct PokeSummary *summary = &sMonSummaryScreen->summary;

    switch (*state)
    {
    case 0:
        if (gMain.inBattle)
        {
            if (ShouldIgnoreDeoxysForm(3, sMonSummaryScreen->curMonIndex))
                HandleLoadSpecialPokePic_DontHandleDeoxys(&gMonFrontPicTable[summary->species2], gMonSpritesGfxPtr->sprites.ptr[1], summary->species2, summary->pid);
            else
                HandleLoadSpecialPokePic_2(&gMonFrontPicTable[summary->species2], gMonSpritesGfxPtr->sprites.ptr[1], summary->species2, summary->pid);
        }
        else
        {
            if (gMonSpritesGfxPtr != NULL)
            {
                if (sMonSummaryScreen->monList.mons == gPlayerParty || sMonSummaryScreen->mode == SUMMARY_MODE_BOX || sMonSummaryScreen->unk40EF == TRUE)
                    HandleLoadSpecialPokePic_2(&gMonFrontPicTable[summary->species2], gMonSpritesGfxPtr->sprites.ptr[1], summary->species2, summary->pid);
                else
                    HandleLoadSpecialPokePic_DontHandleDeoxys(&gMonFrontPicTable[summary->species2], gMonSpritesGfxPtr->sprites.ptr[1], summary->species2, summary->pid);
            }
            else
            {
                if (sMonSummaryScreen->monList.mons == gPlayerParty || sMonSummaryScreen->mode == SUMMARY_MODE_BOX || sMonSummaryScreen->unk40EF == TRUE)
                    HandleLoadSpecialPokePic_2(&gMonFrontPicTable[summary->species2], sub_806F4F8(0, 1), summary->species2, summary->pid);
                else
                    HandleLoadSpecialPokePic_DontHandleDeoxys(&gMonFrontPicTable[summary->species2], sub_806F4F8(0, 1), summary->species2, summary->pid);
            }
        }
        (*state)++;
        return 0xFF;
    case 1:
        pal = GetMonSpritePalStructFromOtIdPersonality(summary->species2, summary->OTID, summary->pid);
        LoadCompressedSpritePalette(pal);
        SetMultiuseSpriteTemplateToPokemon(pal->tag, 1);
        (*state)++;
        return 0xFF;
    default:
        return CreateMonSprite(mon);
    }
}

static void PlayMonCry(void)
{
    struct PokeSummary *summary = &sMonSummaryScreen->summary;

    if (summary->isEgg)
        return;

    if (ShouldPlayNormalMonCry(&sMonSummaryScreen->currentMon) == TRUE)
        PlayCry3(summary->species2, 0, 0);
    else
        PlayCry3(summary->species2, 0, 11);
}

static u8 CreateMonSprite(struct Pokemon *unused)
{
    struct PokeSummary *summary = &sMonSummaryScreen->summary;
    u8 spriteId = CreateSprite(&gMultiuseSpriteTemplate, 60, 65, 5);
    FreeSpriteOamMatrix(&gSprites[spriteId]);
    gSprites[spriteId].data[0] = summary->species2;
    gSprites[spriteId].data[2] = 0;
    gSprites[spriteId].callback = SpriteCB_Pokemon;
    gSprites[spriteId].oam.priority = 0;

    if (!IsMonSpriteNotFlipped(summary->species2))
        gSprites[spriteId].hFlip = TRUE;
    else
        gSprites[spriteId].hFlip = FALSE;

    return spriteId;
}

static void SpriteCB_Pokemon(struct Sprite *sprite)
{
    struct PokeSummary *summary = &sMonSummaryScreen->summary;

    if (gPaletteFade.active || sprite->data[2] == 1)
        return;

    sprite->data[1] = IsMonSpriteNotFlipped(sprite->data[0]);
    PlayMonCry();
    PokemonSummaryDoMonAnimation(sprite, sprite->data[0], summary->isEgg);
}

// Track and then destroy Task_PokemonSummaryAnimateAfterDelay
// Normally destroys itself but it can be interrupted before the animation starts
void SummaryScreen_SetAnimDelayTaskId(u8 taskId)
{
    sAnimDelayTaskId = taskId;
}

static void SummaryScreen_DestroyAnimDelayTask(void)
{
    if (sAnimDelayTaskId == TASK_NONE)
        return;

    DestroyTask(sAnimDelayTaskId);
    sAnimDelayTaskId = TASK_NONE;
}

static void StopPokemonAnimations(void)  // A subtle effect, this function stops pokemon animations when leaving the PSS
{
    u16 i;
    u16 paletteIndex = (gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_MON]].oam.paletteNum * 16) | 0x100;
    gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_MON]].animPaused = TRUE;
    gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_MON]].callback = SpriteCallbackDummy;
    StopPokemonAnimationDelayTask();

    for (i = 0; i < 16; i++)
    {
        u16 id = i + paletteIndex;
        gPlttBufferUnfaded[id] = gPlttBufferFaded[id];
    }
}

static void CreateMonMarkingsSprite(struct Pokemon *mon)
{
    struct Sprite *sprite;

    if (sMonSummaryScreen->summary.isEgg)
        return;

    sprite = CreateMonMarkingAllCombosSprite(TAG_MON_MARKINGS, TAG_MON_MARKINGS, sSummaryMarkings_Pal);
    sMonSummaryScreen->markingsSprite = sprite;

    if (sprite == NULL)
        return;

    StartSpriteAnim(sprite, GetMonData(mon, MON_DATA_MARKINGS));
    sMonSummaryScreen->markingsSprite->x = 20;
    sMonSummaryScreen->markingsSprite->y = 91;
    sMonSummaryScreen->markingsSprite->oam.priority = 1;

    if (GetMonData(mon, MON_DATA_MARKINGS) == 0)
        sMonSummaryScreen->markingsSprite->invisible = TRUE;
}

static void RemoveAndCreateMonMarkingsSprite(struct Pokemon *mon)
{
    DestroySprite(sMonSummaryScreen->markingsSprite);
    FreeSpriteTilesByTag(TAG_MON_MARKINGS);
    CreateMonMarkingsSprite(mon);
}

static void CreateCaughtBallSprite(struct Pokemon *mon)
{
    u8 ball = BallIdToGfxId(GetMonData(mon, MON_DATA_POKEBALL));
    LoadBallGfx(ball);
    sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_BALL] = CreateSprite(&gBallSpriteTemplates[ball], 106, 88, 0);
    gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_BALL]].callback = SpriteCallbackDummy;
    gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_BALL]].oam.priority = 3;
}

static void CreateSetStatusSprite(void)
{
    u8 *spriteId = &sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_STATUS];
    u8 statusAnim = GetMonAilment(&sMonSummaryScreen->currentMon);

    if (*spriteId == SPRITE_NONE)
        *spriteId = CreateSprite(&sSpriteTemplate_StatusCondition, 16, 38, 0);

    if (statusAnim != 0)
    {
        StartSpriteAnim(&gSprites[*spriteId], statusAnim - 1);
        SetSpriteInvisibility(SPRITE_ARR_ID_STATUS, FALSE);
    }
    else
    {
        SetSpriteInvisibility(SPRITE_ARR_ID_STATUS, TRUE);
    }
}

static void CreateMoveSelectorSprites(u8 idArrayStart)
{
    u8 i;
    u8 *spriteIds = &sMonSummaryScreen->spriteIds[idArrayStart];

    if (sMonSummaryScreen->currPageIndex >= PSS_PAGE_BATTLE_MOVES)
    {
        u8 subpriority = 0;
        if (idArrayStart == SPRITE_ARR_ID_MOVE_SELECTOR1)
            subpriority = 1;

        for (i = 0; i < MOVE_SELECTOR_SPRITES_COUNT; i++)
        {
            spriteIds[i] = CreateSprite(&sMoveSelectorSpriteTemplate, i * 8 + 124, 34, subpriority);
            if (i == 0)
                StartSpriteAnim(&gSprites[spriteIds[i]], 0); // left
            else if (i != MOVE_SELECTOR_SPRITES_COUNT - 1)
                StartSpriteAnim(&gSprites[spriteIds[i]], 1); // middle
            else
                StartSpriteAnim(&gSprites[spriteIds[i]], 2); // right, actually the same as left, but flipped
            gSprites[spriteIds[i]].callback = SpriteCb_MoveSelector;
            gSprites[spriteIds[i]].data[0] = idArrayStart;
            gSprites[spriteIds[i]].data[1] = 0;
        }
    }
}

static void SpriteCb_MoveSelector(struct Sprite *sprite)
{
    if (sprite->animNum >= 0 && sprite->animNum <= 2 && sprite->data[0] == SPRITE_ARR_ID_MOVE_SELECTOR2)
    {
        sprite->data[1] = (sprite->data[1] + 1) & 0x1F;
        if (sprite->data[1] > 24)
            sprite->invisible = TRUE;
        else
            sprite->invisible = FALSE;
    }
    else
    {
        sprite->data[1] = 0;
        sprite->invisible = FALSE;
    }

    if (sprite->data[0] == SPRITE_ARR_ID_MOVE_SELECTOR1)
        sprite->y2 = sMonSummaryScreen->firstMoveIndex * 28;
    else
        sprite->y2 = sMonSummaryScreen->secondMoveIndex * 28;
}

static void DestroyMoveSelectorSprites(u8 firstArrayId)
{
    u8 i;

    for (i = 0; i < MOVE_SELECTOR_SPRITES_COUNT; i++)
        DestroySpriteInArray(firstArrayId + i);
}

static void SetMainMoveSelectorColor(u8 which)
{
    u8 i;
    u8 *spriteIds = &sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_MOVE_SELECTOR1];
    which *= 3;
    StartSpriteAnim(&gSprites[spriteIds[0]], which);
    for (i = 1; i < MOVE_SELECTOR_SPRITES_COUNT; i++)
        StartSpriteAnim(&gSprites[spriteIds[i]], which + 1);
    StartSpriteAnim(&gSprites[spriteIds[MOVE_SELECTOR_SPRITES_COUNT - 1]], which + 2);
}

static void KeepMoveSelectorVisible(u8 firstSpriteId)
{
    u8 i;
    u8 *spriteIds = &sMonSummaryScreen->spriteIds[firstSpriteId];

    for (i = 0; i < MOVE_SELECTOR_SPRITES_COUNT; i++)
    {
        gSprites[spriteIds[i]].data[1] = 0;
        gSprites[spriteIds[i]].invisible = FALSE;
    }
}

static void WhenShinyShowStarIcon(bool8 smallWindow)
{
    struct Sprite *sprite = &gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_SHINY_ICON]];

    if (!sMonSummaryScreen->summary.isEgg && IsMonShiny(&sMonSummaryScreen->currentMon))
        sprite->invisible = FALSE;
    else
        sprite->invisible = TRUE;

    if (smallWindow)
    {
        sprite->x = 8;
        sprite->y = 24;
    }
    else
    {
        sprite->x = 106;
        sprite->y = 40;
    }
}

static void CreateUpdateShinyIconSprite(bool8 smallWindow)
{
    u16 spriteId;
    struct Sprite *sprite;
    void *gfxBufferPtr;

    if (sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_SHINY_ICON] == SPRITE_NONE)
    {
        gfxBufferPtr = AllocZeroed(0x20 * 2);

        struct SpriteSheet spritesheet = {
            .data = gfxBufferPtr,
            .size = 0x20 * 2,
            .tag = TAG_SHINY_ICON
        };

        LZ77UnCompWram(gShinyIcon_Gfx, gfxBufferPtr);
        LoadSpriteSheet(&spritesheet);
        LoadSpritePalette(&sShinyIconSpritePalette);
        sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_SHINY_ICON] = CreateSprite(&sSpriteTemplate_ShinyIcon, 106, 40, 0);
        sprite = &gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_SHINY_ICON]];
        sprite->oam.priority = 1;
    }

    WhenShinyShowStarIcon(smallWindow);

    if (gfxBufferPtr != NULL)
        FREE_AND_SET_NULL(gfxBufferPtr);
}

static void DestroyShinyIconSprite(void)
{
    if (sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_SHINY_ICON] == SPRITE_NONE)
        return;

    DestroySpriteAndFreeResources(&gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_SHINY_ICON]]);
    sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_SHINY_ICON] == SPRITE_NONE;
}

static void CreateHealthBarSprites(u16 tileTag, u16 palTag)
{
    u8 i;
    u8 spriteId;
    u32 curHp = GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_HP);
    u32 maxHp = GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_MAX_HP);
    void *gfxBufferPtr = AllocZeroed(0x20 * 12);
    sHealthBar = AllocZeroed(sizeof(struct HealthBar));
    LZ77UnCompWram(gSummaryHealthBar_Tiles, gfxBufferPtr);

    if (gfxBufferPtr != NULL)
    {
        struct SpriteSheet sheet = {
            .data = gfxBufferPtr,
            .size = 0x20 * 12,
            .tag = tileTag
        };

        struct SpritePalette palHigh   = {.data = gExpBarHighHealthBar_Pal,   .tag = palTag};
        struct SpritePalette palMedium = {.data = gExpBarMediumHealthBar_Pal, .tag = palTag + 1};
        struct SpritePalette palLow    = {.data = gExpBarLowHealthBar_Pal,    .tag = palTag + 2};
        LoadSpritePalette(&palHigh);
        LoadSpritePalette(&palMedium);
        LoadSpritePalette(&palLow);
        LoadSpriteSheet(&sheet);
    }

    for (i = 0; i < HP_BAR_SPRITES_COUNT; i++)
    {
        struct SpriteTemplate template = {
            .tileTag = tileTag,
            .paletteTag = palTag,
            .oam = &sOamData_ExpHealthBars,
            .anims = sSpriteAnimTable_ExpHealthBars,
            .images = NULL,
            .affineAnims = gDummySpriteAffineAnimTable,
            .callback = SpriteCallbackDummy,
        };

        sHealthBar->spritePositions[i] = i * 8 + 172;
        spriteId = CreateSprite(&template, sHealthBar->spritePositions[i], 36, 0);
        sHealthBar->sprites[i] = &gSprites[spriteId];
        sHealthBar->sprites[i]->oam.priority = 1;
        sHealthBar->sprites[i]->invisible = TRUE;
        sHealthBar->tileTag = tileTag;
        sHealthBar->palTag = palTag;
        StartSpriteAnim(sHealthBar->sprites[i], 8);
    }

    ConfigureHealthBarSprites();
    SetHealthBarSprites();
    FREE_AND_SET_NULL(gfxBufferPtr);
}

static void ConfigureHealthBarSprites(void)
{
    u8 i;
    u8 animNum;
    u32 curHp;
    u32 maxHp;
    s64 pointsPerTile;
    s64 totalPoints;
    u8 numWholeHpBarTiles = 0;
    u16 paletteTag = TAG_HEALTH_BAR;
    struct PokeSummary *summary = &sMonSummaryScreen->summary;

    if (summary->isEgg)
        return;

    curHp = GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_HP);
    maxHp = GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_MAX_HP);

    if (maxHp / 5 >= curHp)
        paletteTag += 2;
    else if (maxHp / 2 >= curHp)
        paletteTag += 1;

    for (i = 0; i < HP_BAR_SPRITES_COUNT; i++)
        sHealthBar->sprites[i]->oam.paletteNum = IndexOfSpritePaletteTag(paletteTag);

    if (curHp == maxHp)
    {
        for (i = 2; i < HP_BAR_SPRITES_COUNT - 1; i++)
            StartSpriteAnim(sHealthBar->sprites[i], 8);
    }
    else
    {
        pointsPerTile = (maxHp << 2) / 6;
        totalPoints = (curHp << 2);

        while (TRUE)
        {
            if (totalPoints <= pointsPerTile)
                break;
            totalPoints -= pointsPerTile;
            numWholeHpBarTiles++;
        }

        numWholeHpBarTiles += 2;

        for (i = 2; i < numWholeHpBarTiles; i++)
            StartSpriteAnim(sHealthBar->sprites[i], 8);

        animNum = (totalPoints * 8) / pointsPerTile;
        StartSpriteAnim(sHealthBar->sprites[numWholeHpBarTiles], animNum);

        for (i = numWholeHpBarTiles + 1; i < HP_BAR_SPRITES_COUNT - 1; i++)
            StartSpriteAnim(sHealthBar->sprites[i], 0);
    }

    StartSpriteAnim(sHealthBar->sprites[0], 9);
    StartSpriteAnim(sHealthBar->sprites[1], 10);
    StartSpriteAnim(sHealthBar->sprites[HP_BAR_SPRITES_COUNT - 1], 11);
}

static void DestroyHealthBarSprites(void)
{
    u8 i;

    for (i = 0; i < HP_BAR_SPRITES_COUNT; i++)
        if (sHealthBar->sprites[i] != NULL)
            DestroySpriteAndFreeResources(sHealthBar->sprites[i]);

    FREE_AND_SET_NULL(sHealthBar);
}

static void SetHealthBarSprites(void)
{
    u8 i;

    if (sMonSummaryScreen->currPageIndex == PSS_PAGE_SKILLS)
        for (i = 0; i < HP_BAR_SPRITES_COUNT; i++)
            sHealthBar->sprites[i]->invisible = FALSE;
}

static void CreateExpBarSprites(u16 tileTag, u16 palTag)
{
    u8 i;
    u8 spriteId;
    void *gfxBufferPtr = AllocZeroed(0x20 * 12);
    sExpBar = AllocZeroed(sizeof(struct ExpBar));
    LZ77UnCompWram(gSummaryExpBar_Tiles, gfxBufferPtr);

    if (gfxBufferPtr != NULL)
    {
        struct SpriteSheet sheet = {
            .data = gfxBufferPtr,
            .size = 0x20 * 12,
            .tag = tileTag
        };

        struct SpritePalette palette = {.data = gExpBarHighHealthBar_Pal, .tag = palTag};
        LoadSpriteSheet(&sheet);
        LoadSpritePalette(&palette);
    }

    for (i = 0; i < EXP_BAR_SPRITES_COUNT; i++)
    {
        struct SpriteTemplate template = {
            .tileTag = tileTag,
            .paletteTag = palTag,
            .oam = &sOamData_ExpHealthBars,
            .anims = sSpriteAnimTable_ExpHealthBars,
            .images = NULL,
            .affineAnims = gDummySpriteAffineAnimTable,
            .callback = SpriteCallbackDummy,
        };

        sExpBar->spritePositions[i] = i * 8 + 156;
        spriteId = CreateSprite(&template, sExpBar->spritePositions[i], 132, 0);
        sExpBar->sprites[i] = &gSprites[spriteId];
        sExpBar->sprites[i]->oam.priority = 1;
        sExpBar->sprites[i]->invisible = TRUE;
        sExpBar->tileTag = tileTag;
        sExpBar->palTag = palTag;
    }

    ConfigureExpBarSprites();
    SetExpBarSprites();
    FREE_AND_SET_NULL(gfxBufferPtr);
}

static void ConfigureExpBarSprites(void)
{
    u8 numWholeExpBarTiles = 0;
    u8 i;
    u32 totalExpToNextLevel;
    u32 curExpToNextLevel;
    s64 v0;
    s64 v1;
    u8 animNum;
    struct PokeSummary *summary = &sMonSummaryScreen->summary;
    u32 exp = GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_EXP);
    u8 level = GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_LEVEL);
    u16 species = GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_SPECIES);

    if (level < 100)
    {
        totalExpToNextLevel = gExperienceTables[gBaseStats[species].growthRate][level + 1] - gExperienceTables[gBaseStats[species].growthRate][level];
        curExpToNextLevel = exp - gExperienceTables[gBaseStats[species].growthRate][level];
        v0 = ((totalExpToNextLevel << 2) / 8);
        v1 = (curExpToNextLevel << 2);

        while (TRUE)
        {
            if (v1 <= v0)
                break;
            v1 -= v0;
            numWholeExpBarTiles++;
        }

        numWholeExpBarTiles += 2;

        for (i = 2; i < numWholeExpBarTiles; i++)
            StartSpriteAnim(sExpBar->sprites[i], 8);

        if (numWholeExpBarTiles >= EXP_BAR_SPRITES_COUNT - 1)
        {
            if (totalExpToNextLevel == curExpToNextLevel)
                return;
            else
                StartSpriteAnim(sExpBar->sprites[EXP_BAR_SPRITES_COUNT - 2], 7);
        }

        animNum = (v1 * 8) / v0;
        StartSpriteAnim(sExpBar->sprites[numWholeExpBarTiles], animNum);

        for (i = numWholeExpBarTiles + 1; i < EXP_BAR_SPRITES_COUNT - 1; i++)
            StartSpriteAnim(sExpBar->sprites[i], 0);
    }
    else
        for (i = 2; i < EXP_BAR_SPRITES_COUNT - 1; i++)
            StartSpriteAnim(sExpBar->sprites[i], 0);

    StartSpriteAnim(sExpBar->sprites[0], 9);
    StartSpriteAnim(sExpBar->sprites[1], 10);
    StartSpriteAnim(sExpBar->sprites[EXP_BAR_SPRITES_COUNT - 1], 11);
}

static void DestroyExpBarSprites(void)
{
    u8 i;

    for (i = 0; i < EXP_BAR_SPRITES_COUNT; i++)
        if (sExpBar->sprites[i] != NULL)
            DestroySpriteAndFreeResources(sExpBar->sprites[i]);

    FREE_AND_SET_NULL(sExpBar);
}

static void SetExpBarSprites(void)
{
    u8 i;

    if (sMonSummaryScreen->currPageIndex == PSS_PAGE_SKILLS)
        for (i = 0; i < EXP_BAR_SPRITES_COUNT; i++)
            sExpBar->sprites[i]->invisible = FALSE;
}

static void PrintTitleBar(u8 pageIndex, bool8 detailsShown)
{
    u8 x;
    FillWindowPixelBuffer(WINDOW_ARR_ID_TITLE_BAR, PIXEL_FILL(0));

    switch (pageIndex)
    {
        case PSS_PAGE_INFO:
            StringCopy(gStringVar1, gText_PkmnInfo);
            if (sMonSummaryScreen->summary.isEgg)
                StringCopy(gStringVar2, gText_ACancel);
            else
                StringCopy(gStringVar2, sText_TitlePageCancel);
            break;
        case PSS_PAGE_SKILLS:
            StringCopy(gStringVar1, gText_PkmnSkills);
            StringCopy(gStringVar2, sText_TitlePage);
            break;
        case PSS_PAGE_BATTLE_MOVES:
            StringCopy(gStringVar1, gText_BattleMoves);
            if (detailsShown)
                StringCopy(gStringVar2, sText_TitlePickSwitch);
            else if (CONFIG_CONTEST_MOVES_ENABLED)
                StringCopy(gStringVar2, sText_TitlePageDetailLR);
            else
                StringCopy(gStringVar2, sText_TitlePageDetailL);
            break;
        case PSS_PAGE_CONTEST_MOVES:
            StringCopy(gStringVar1, gText_ContestMoves);
            if (detailsShown)
                StringCopy(gStringVar2, sText_TitlePickSwitch);
            else
                StringCopy(gStringVar2, sText_TitlePageDetailL);
            break;
    }

    PrintTextOnWindow(WINDOW_ARR_ID_TITLE_BAR, gStringVar1, 4, 1, 0, PSS_COLOR_WHITE_BLACK_SHADOW);
    x = GetStringRightAlignXOffset(0, gStringVar2, 236);
    PrintTextOnWindowSmall(WINDOW_ARR_ID_TITLE_BAR, gStringVar2, x, 0, 0, PSS_COLOR_WHITE_BLACK_SHADOW);
    PutWindowTilemap(WINDOW_ARR_ID_TITLE_BAR);
}
