#include "global.h"
#include "trainer_pokemon_sprites.h"
#include "bg.h"
#include "constants/flags.h"
#include "constants/rgb.h"
#include "constants/songs.h"
#include "constants/species.h"
#include "constants/trainers.h"
#include "util.h"
#include "clock.h"
#include "decompress.h"
#include "event_data.h"
#include "field_effect.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "international_string_util.h"
#include "link.h"
#include "math_util.h"
#include "main.h"
#include "menu.h"
#include "menu_helpers.h"
#include "list_menu.h"
#include "mystery_event_menu.h"
#include "mystery_gift.h"
#include "naming_screen.h"
#include "option_menu.h"
#include "overworld.h"
#include "palette.h"
#include "pokeball.h"
#include "pokedex.h"
#include "pokemon.h"
#include "random.h"
#include "rtc.h"
#include "save.h"
#include "scanline_effect.h"
#include "sound.h"
#include "sprite.h"
#include "string.h"
#include "strings.h"
#include "string_util.h"
#include "task.h"
#include "text.h"
#include "text_window.h"
#include "title_screen.h"
#include "window.h"
#include "wallclock.h"
#include "m4a.h"
#include "alloc.h"

extern struct MusicPlayerInfo gMPlayInfo_BGM;

/*
 * Main menu state machine
 * -----------------------
 * 
 * Entry point: CB2_InitMainMenu
 * 
 * Note: States advance sequentially unless otherwise stated.
 * 
 * CB2_InitMainMenu / CB2_ReinitMainMenu
 *  - Both of these states call InitMainMenu, which does all the work.
 *  - In the Reinit case, the init code will check if the user came from
 *    the options screen. If they did, then the options menu item is
 *    pre-selected.
 * 
 * Task_MainMenuCheckSaveFile
 *  - Determines how many menu options to show based on whether
 *    the save file is Ok, empty, corrupted, etc.
 *  - If there was an error loading the save file, advance to
 *    Task_WaitForSaveFileErrorWindow.
 *  - If there were no errors, advance to Task_MainMenuCheckBattery.
 *  - Note that the check to enable Mystery Events would normally happen
 *    here, but this version of Emerald has them disabled.
 * 
 * Task_WaitForSaveFileErrorWindow
 *  - Wait for the text to finish printing and then for the A button
 *    to be pressed.
 * 
 * Task_MainMenuCheckBattery
 *  - If the battery is OK, advance to Task_DisplayMainMenu.
 *  - If the battery is dry, advance to Task_WaitForBatteryDryErrorWindow.
 * 
 * Task_WaitForBatteryDryErrorWindow
 *  - Wait for the text to finish printing and then for the A button
 *    to be pressed.
 * 
 * Task_DisplayMainWindow
 *  - Display the buttons to the user. If the menu is in HAS_MYSTERY_EVENTS
 *    mode, there are too many buttons for one screen and a scrollbar is added,
 *    and the scrollbar task is spawned (Task_ScrollIndicatorArrowPairOnMainMenu).
 * 
 * Task_HighlightSelectedMainMenuItem
 *  - Update the UI to match the currently selected item.
 * 
 * Task_HandleMainMenuInput
 *  - If A is pressed, advance to Task_HandleMainMenuAPressed.
 *  - If B is pressed, return to the title screen via CB2_InitTitleScreen.
 *  - If Up or Down is pressed, handle scrolling if there is a scroll bar, change
 *    the selection, then go back to Task_HighlightSelectedMainMenuItem.
 * 
 * Task_HandleMainMenuAPressed
 *  - If the user selected New Game, advance to Task_NewGameBirchSpeech_Init.
 *  - If the user selected Continue, advance to CB2_ContinueSavedGame.
 *  - If the user selected the Options menu, advance to CB2_InitOptionMenu.
 *  - If the user selected Mystery Gift, advance to CB2_MysteryGift. However,
 *    if the wireless adapter was removed, instead advance to
 *    Task_DisplayMainMenuInvalidActionError.
 *  - Code to start a Mystery Event is present here, but is unreachable in this
 *    version.
 *    
 * Task_HandleMainMenuBPressed
 *  - Clean up the main menu and go back to CB2_InitTitleScreen.
 * 
 * Task_DisplayMainMenuInvalidActionError
 *  - Print one of three different error messages, wait for the text to stop
 *    printing, and then wait for A or B to be pressed.
 * - Then advance to Task_HandleMainMenuBPressed.
 * 
 * Task_NewGameBirchSpeechInit
 *  - Load the sprites for the intro speech, start playing music
 * Task_NewGameBirchSpeech_WaitToShowBirch
 *  - Spawn Task_NewGameBirchSpeech_FadeInTarget1OutTarget2
 *  - Spawn Task_NewGameBirchSpeech_FadePlatformOut
 *  - Both of these tasks destroy themselves when done.
 * Task_NewGameBirchSpeech_WaitForSpriteFadeInWelcome
 * Task_NewGameBirchSpeech_ThisIsAPokemon
 *  - When the text is done printing, spawns Task_NewGameBirchSpeechSub_InitPokeball
 * Task_NewGameBirchSpeech_MainSpeech
 * Task_NewGameBirchSpeech_AndYouAre
 * Task_NewGameBirchSpeech_StartBirchLotadPlatformFade
 * Task_NewGameBirchSpeech_StartBirchLotadPlatformFade
 * Task_NewGameBirchSpeech_SlidePlatformAway
 * Task_NewGameBirchSpeech_StartPlayerFadeIn
 * Task_NewGameBirchSpeech_WaitForPlayerFadeIn
 * Task_NewGameBirchSpeech_BoyOrGirl
 * Task_NewGameBirchSpeech_WaitToShowGenderMenu
 * Task_NewGameBirchSpeech_ChooseGender
 *  - Animates by advancing to Task_NewGameBirchSpeech_SlideOutOldGenderSprite
 *    whenever the player's selection changes.
 *  - Advances to Task_NewGameBirchSpeech_WhatsYourName when done.
 * 
 * Task_NewGameBirchSpeech_SlideOutOldGenderSprite
 * Task_NewGameBirchSpeech_SlideInNewGenderSprite
 *  - Returns back to Task_NewGameBirchSpeech_ChooseGender.
 * 
 * Task_NewGameBirchSpeech_WhatsYourName
 * Task_NewGameBirchSpeech_WaitForWhatsYourNameToPrint
 * Task_NewGameBirchSpeech_WaitPressBeforeNameChoice
 * Task_NewGameBirchSpeech_StartNamingScreen
 * C2_NamingScreen
 *  - Returns to CB2_NewGameBirchSpeech_ReturnFromNamingScreen when done
 * CB2_NewGameBirchSpeech_ReturnFromNamingScreen
 * Task_NewGameBirchSpeech_ReturnFromNamingScreenShowTextbox
 * Task_NewGameBirchSpeech_SoItsPlayerName
 * Task_NewGameBirchSpeech_CreateNameYesNo
 * Task_NewGameBirchSpeech_ProcessNameYesNoMenu
 *  - If confirmed, advance to Task_NewGameBirchSpeech_SlidePlatformAway2.
 *  - Otherwise, return to Task_NewGameBirchSpeech_BoyOrGirl.
 * 
 * Task_NewGameBirchSpeech_SlidePlatformAway2
 * Task_NewGameBirchSpeech_ReshowBirchLotad
 * Task_NewGameBirchSpeech_WaitForSpriteFadeInAndTextPrinter
 * Task_NewGameBirchSpeech_AreYouReady
 * Task_NewGameBirchSpeech_ShrinkPlayer
 * Task_NewGameBirchSpeech_WaitForPlayerShrink
 * Task_NewGameBirchSpeech_FadePlayerToWhite
 * Task_NewGameBirchSpeech_Cleanup
 *  - Advances to CB2_NewGame.
 * 
 * Task_NewGameBirchSpeechSub_InitPokeball
 *  - Advances to Task_NewGameBirchSpeechSub_WaitForLotad
 * Task_NewGameBirchSpeechSub_WaitForLotad
 *  - Destroys itself when done.
 */

// These two defines are used with the sCurrItemAndOptionsMenuCheck,
// to distinguish between its two parts.
#define OPTION_MENU_FLAG 0x8000
#define CURRENT_ITEM_MASK 0x7FFF

// Static type declarations

// Static RAM declarations

static EWRAM_DATA u8 *sOakIntro_BgBuffer = NULL;
static EWRAM_DATA u16 sCurrItemAndOptionMenuCheck = 0;

static IWRAM_DATA u8 sOakSpeechMainTaskId;

// Static ROM declarations

static u32 InitMainMenu(bool8);
static void Task_MainMenuCheckSaveFile(u8);
static void Task_MainMenuCheckBattery(u8);
static void Task_WaitForSaveFileErrorWindow(u8);
static void CreateMainMenuErrorWindow(const u8*);
static void ClearMainMenuWindowTilemap(const struct WindowTemplate*);
static void Task_DisplayMainMenu(u8);
static void Task_WaitForBatteryDryErrorWindow(u8);
static void MainMenu_FormatSavegameText(void);
static void HighlightSelectedMainMenuItem(u8, u8, s16);
static void Task_HandleMainMenuInput(u8);
static void Task_HandleMainMenuAPressed(u8);
static void Task_HandleMainMenuAPressed_(u8 taskId);
static void Task_HandleMainMenuBPressed(u8);
static void Task_NewGameClockSetIntro1(u8);
static void Task_NewGameClockSetIntro2(u8);
static void Task_NewGameClockSetIntro3(u8);
static void Task_NewGameClockSetIntro4(u8);
static void Task_NewGameClockSetIntro5(u8);
static void Task_NewGameClockSetIntro6(u8);
static void Task_NewGameOakSpeech_Init(u8);
static void Task_DisplayMainMenuInvalidActionError(u8);
static void AddOakSpeechObjects(u8);
static void Task_NewGameOakSpeech_WaitToShowBirch(u8);
static void NewGameOakSpeech_StartFadeInTarget1OutTarget2(u8, u8);
static void NewGameOakSpeech_StartFadePlatformOut(u8, u8);
static void Task_NewGameOakSpeech_WaitForTextToStart(u8);
static void NewGameOakSpeech_ShowDialogueWindow(u8, u8);
static void Task_NewGameOakSpeech_PrintThisEllipsis(u8);
static void Task_NewGameOakSpeech_CreatePokeBallToReleaseWooper(u8);
static void Task_NewGameOakSpeech_PrintIsPokemonWaitForAnimation(u8);
static void Task_NewGameOakSpeech_MainSpeech1(u8);
static void Task_NewGameOakSpeech_PutAwayWooper(u8);
static void Task_NewGameOakSpeech_MainSpeech2(u8);
static void Task_NewGameOakSpeech_AndYouAre(u8);
static void Task_NewGameOakSpeechSub_WaitForLotad(u8);
static void Task_NewGameOakSpeech_StartOakPlatformFade(u8);
static void NewGameOakSpeech_StartFadeOutTarget1InTarget2(u8, u8);
static void NewGameOakSpeech_StartFadePlatformIn(u8, u8);
static void Task_NewGameOakSpeech_SlidePlatformAway(u8);
static void Task_NewGameOakSpeech_WaitOakPlatformFade(u8);
static void Task_NewGameOakSpeech_StartPlayerFadeIn(u8);
static void Task_NewGameOakSpeech_WaitForPlayerFadeIn(u8);
static void Task_NewGameOakSpeech_BoyOrGirl(u8);
static void LoadMainMenuWindowFrameTiles(u8, u16);
static void DrawMainMenuWindowBorder(const struct WindowTemplate*, u16);
static void Task_HighlightSelectedMainMenuItem(u8);
static void Task_NewGameOakSpeech_WaitToShowGenderMenu(u8);
static void Task_NewGameOakSpeech_ChooseGender(u8);
static void NewGameOakSpeech_ShowGenderMenu(void);
static s8 NewGameOakSpeech_ProcessGenderMenuInput(void);
static void NewGameOakSpeech_ClearGenderWindow(u8, u8);
static void Task_NewGameOakSpeech_WhatsYourName(u8);
static void Task_NewGameOakSpeech_SlideOutOldGenderSprite(u8);
static void Task_NewGameOakSpeech_SlideInNewGenderSprite(u8);
static void Task_NewGameOakSpeech_WaitForWhatsYourNameToPrint(u8);
static void Task_NewGameOakSpeech_WaitPressBeforeNameChoice(u8);
static void Task_NewGameOakSpeech_StartNamingScreen(u8);
static void CB2_NewGameOakSpeech_ReturnFromNamingScreen(void);
static void NewGameOakSpeech_SetDefaultPlayerName(u8);
static void Task_NewGameOakSpeech_CreateNameYesNo(u8);
static void Task_NewGameOakSpeech_ProcessNameYesNoMenu(u8);
void CreateYesNoMenuParameterized(u8, u8, u16, u16, u8, u8);
static void Task_NewGameOakSpeech_SlidePlatformAway2(u8);
static void Task_NewGameOakSpeech_ReshowBirchLotad(u8);
static void Task_NewGameOakSpeech_WaitForSpriteFadeInAndTextPrinter(u8);
static void Task_NewGameOakSpeech_AreYouReady(u8);
static void Task_NewGameOakSpeech_PrepareToShrinkPlayer(u8);
static void Task_NewGameOakSpeech_StartFadePlayerToWhite(u8);
static void Task_NewGameOakSpeech_ShrinkPlayer(u8);
static void SpriteCB_MovePlayerDownWhileShrinking(struct Sprite*);
static void Task_NewGameOakSpeech_ShrinkBG2(u8);
static void Task_NewGameOakSpeech_FadePlayerToBlack(u8);
static void Task_NewGameOakSpeech_FadePlayerToWhite(u8);
static void Task_NewGameOakSpeech_Cleanup(u8);
static void SpriteCB_Null();
static void Task_NewGameOakSpeech_ReturnFromNamingScreenShowTextbox(u8);
static void MainMenu_FormatSavegamePlayer(void);
static void MainMenu_FormatSavegamePokedex(void);
static void MainMenu_FormatSavegameTime(void);
static void MainMenu_FormatSavegameBadges(void);
static void NewGameOakSpeech_CreateDialogueWindowBorder(u8, u8, u8, u8, u8, u8);
static void LoadOakIntroBigSprite(u16 which, u16 offset);
static void Task_NewGameOakSpeech_FadeEverythingButPlayerAndTextbox(u8 taskId);
static void Task_NewGameOakSpeech_StartShrinkPlayer(u8 taskId);
static void Task_NewGameOakSpeech_WaitToFadeTextbox(u8 taskId);

extern const union AffineAnimCmd *const gUnknown_082FF694[];

// .rodata

static const u16 sOakSpeechBgPal[] = INCBIN_U16("graphics/oak_speech/bg0.gbapal");

static const u32 sOakSpeechBgGfx[] = INCBIN_U32("graphics/oak_speech/bg0.4bpp.lz");
static const u32 sOakSpeechBgMap[] = INCBIN_U32("graphics/oak_speech/map.bin.lz");

static const u32 gOakIntroPlatformGfx[] = INCBIN_U32("graphics/oak_speech/platform.4bpp.lz");
static const u16 gOakIntroPlatformPal[] = INCBIN_U16("graphics/oak_speech/platform.gbapal");

static const u16 sOakIntro_GoldPal[] = INCBIN_U16("graphics/oak_speech/gold.gbapal");
static const u16 sOakIntro_KrisPal[] = INCBIN_U16("graphics/oak_speech/kris.gbapal");
static const u16 sOakIntro_OakPal[] = INCBIN_U16("graphics/oak_speech/oak.gbapal");
static const u32 sOakIntro_GoldTiles[] = INCBIN_U32("graphics/oak_speech/gold.8bpp.lz");
static const u32 sOakIntro_KrisTiles[] = INCBIN_U32("graphics/oak_speech/kris.8bpp.lz");
static const u32 sOakIntro_OakTiles[] = INCBIN_U32("graphics/oak_speech/oak.8bpp.lz");

#define MENU_LEFT 3
#define MENU_TOP_WIN0 1
#define MENU_TOP_WIN1 5
#define MENU_TOP_WIN2 1
#define MENU_TOP_WIN3 13
#define MENU_TOP_WIN4 17
#define MENU_TOP_WIN5 21
#define MENU_TOP_WIN6 25
#define MENU_WIDTH 24
#define MENU_HEIGHT_WIN0 2
#define MENU_HEIGHT_WIN1 2
#define MENU_HEIGHT_WIN2 10
#define MENU_HEIGHT_WIN3 2
#define MENU_HEIGHT_WIN4 2
#define MENU_HEIGHT_WIN5 2
#define MENU_HEIGHT_WIN6 2

#define MENU_LEFT_ERROR 2
#define MENU_TOP_ERROR 15
#define MENU_WIDTH_ERROR 26
#define MENU_HEIGHT_ERROR 4

#define MENU_SHADOW_PADDING 2

#define MENU_WIN_HCOORDS WIN_RANGE(((MENU_LEFT - 1) * 8) + MENU_SHADOW_PADDING, (MENU_LEFT + MENU_WIDTH + 1) * 8 - MENU_SHADOW_PADDING)
#define MENU_WIN_VCOORDS(n) WIN_RANGE(((MENU_TOP_WIN##n - 1) * 8) + MENU_SHADOW_PADDING, (MENU_TOP_WIN##n + MENU_HEIGHT_WIN##n + 1) * 8 - MENU_SHADOW_PADDING)
#define MENU_SCROLL_SHIFT WIN_RANGE(32, 32)

static const struct WindowTemplate sWindowTemplates_MainMenu[] =
{
    // No saved game
    // NEW GAME
    {
        .bg = 0,
        .tilemapLeft = MENU_LEFT,
        .tilemapTop = MENU_TOP_WIN0,
        .width = MENU_WIDTH,
        .height = MENU_HEIGHT_WIN0,
        .paletteNum = 15,
        .baseBlock = 1
    },
    // OPTIONS
    {
        .bg = 0,
        .tilemapLeft = MENU_LEFT,
        .tilemapTop = MENU_TOP_WIN1,
        .width = MENU_WIDTH,
        .height = MENU_HEIGHT_WIN1,
        .paletteNum = 15,
        .baseBlock = 0x35
    },
    // Has saved game
    // CONTINUE
    {
        .bg = 0,
        .tilemapLeft = MENU_LEFT,
        .tilemapTop = MENU_TOP_WIN2,
        .width = MENU_WIDTH,
        .height = MENU_HEIGHT_WIN2,
        .paletteNum = 15,
        .baseBlock = 1
    },
    // NEW GAME
    {
        .bg = 0,
        .tilemapLeft = MENU_LEFT,
        .tilemapTop = MENU_TOP_WIN3,
        .width = MENU_WIDTH,
        .height = MENU_HEIGHT_WIN3,
        .paletteNum = 15,
        .baseBlock = 0xF1
    },
    // OPTION / MYSTERY GIFT
    {
        .bg = 0,
        .tilemapLeft = MENU_LEFT,
        .tilemapTop = MENU_TOP_WIN4,
        .width = MENU_WIDTH,
        .height = MENU_HEIGHT_WIN4,
        .paletteNum = 15,
        .baseBlock = 0x121
    },
    // OPTION / MYSTERY EVENTS
    {
        .bg = 0,
        .tilemapLeft = MENU_LEFT,
        .tilemapTop = MENU_TOP_WIN5,
        .width = MENU_WIDTH,
        .height = MENU_HEIGHT_WIN5,
        .paletteNum = 15,
        .baseBlock = 0x151
    },
    // OPTION
    {
        .bg = 0,
        .tilemapLeft = MENU_LEFT,
        .tilemapTop = MENU_TOP_WIN6,
        .width = MENU_WIDTH,
        .height = MENU_HEIGHT_WIN6,
        .paletteNum = 15,
        .baseBlock = 0x181
    },
    // Error message window
    {
        .bg = 0,
        .tilemapLeft = MENU_LEFT_ERROR,
        .tilemapTop = MENU_TOP_ERROR,
        .width = MENU_WIDTH_ERROR,
        .height = MENU_HEIGHT_ERROR,
        .paletteNum = 15,
        .baseBlock = 1
    },
    DUMMY_WIN_TEMPLATE
};

const struct WindowTemplate sClockSetWindowTemplates[] = 
{
    {
        .bg = 0,
        .tilemapLeft = 2,
        .tilemapTop = 15,
        .width = 26,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 1
    },
    DUMMY_WIN_TEMPLATE
};

static const struct WindowTemplate gNewGameBirchSpeechTextWindows[] =
{
    {
        .bg = 0,
        .tilemapLeft = 2,
        .tilemapTop = 15,
        .width = 26,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 1
    },
    {
        .bg = 0,
        .tilemapLeft = 18,
        .tilemapTop = 9,
        .width = 9,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 0x6D
    },
    {
        .bg = 0,
        .tilemapLeft = 3,
        .tilemapTop = 2,
        .width = 9,
        .height = 10,
        .paletteNum = 15,
        .baseBlock = 0x85
    },
    DUMMY_WIN_TEMPLATE
};

static const u16 sMainMenuBgPal[] = INCBIN_U16("graphics/misc/main_menu_bg.gbapal");
static const u16 sMainMenuTextPal[] = INCBIN_U16("graphics/misc/main_menu_text.gbapal");

static const u8 sTextColor_Headers[] = {10, 11, 12};
static const u8 sTextColor_PlayerGenderColor[] = {10, 1, 12};

static const struct BgTemplate sMainMenuBgTemplates[] = {
    {
        .bg = 0,
        .charBaseIndex = 2,
        .mapBaseIndex = 30,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    },
    {
        .bg = 1,
        .charBaseIndex = 0,
        .mapBaseIndex = 7,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 3,
        .baseTile = 0
    }
};

static const struct BgTemplate sOakBgTemplates[] = {
    {
        .bg = 0,
        .charBaseIndex = 2,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    },
    {
        .bg = 1,
        .charBaseIndex = 0,
        .mapBaseIndex = 30,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0
    },
    {
        .bg = 2,
        .charBaseIndex = 0,
        .mapBaseIndex = 28,
        .screenSize = 1,
        .paletteMode = 1,
        .priority = 1,
        .baseTile = 0
    }
};

static const struct ScrollArrowsTemplate sScrollArrowsTemplate_MainMenu = {2, 0x78, 8, 3, 0x78, 0x98, 3, 4, 1, 1, 0};

static const union AffineAnimCmd sSpriteAffineAnim_PlayerShrink[] = {
    AFFINEANIMCMD_FRAME(-2, -2, 0, 0x30),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd *const sSpriteAffineAnimTable_PlayerShrink[] =
{
    sSpriteAffineAnim_PlayerShrink
};

static const struct MenuAction sMenuActions_Gender[] = {
    {gText_OakBoy, NULL},
    {gText_OakGirl, NULL}
};

static const u8 *const gMalePresetNames[] = {
    gText_DefaultNameChris,
	gText_DefaultNameMat,
	gText_DefaultNameAllan,
	gText_DefaultNameJon,
	gText_DefaultNameGold,
	gText_DefaultNameHiro,
	gText_DefaultNameTaylor,
	gText_DefaultNameKarl,
	gText_DefaultNameSilver,
	gText_DefaultNameKamon,
	gText_DefaultNameOscar,
	gText_DefaultNameMax,
	gText_DefaultNameJimmy,
	gText_DefaultNameDiego,
	gText_DefaultNameAdam,
	gText_DefaultNameRaymond,
	gText_DefaultNameIan,
	gText_DefaultNameRutvik,
	gText_DefaultNameKamron,
	gText_DefaultNameTanek
};

static const u8 *const gFemalePresetNames[] = {
    gText_DefaultNameKris,
    gText_DefaultNameAmanda,
    gText_DefaultNameJuana,
    gText_DefaultNameJodi,
    gText_DefaultNameCrystal,
    gText_DefaultNameMarina,
    gText_DefaultNameArianna,
    gText_DefaultNameJenny,
    gText_DefaultNameLorrie,
    gText_DefaultNameHannah,
    gText_DefaultNameGina,
    gText_DefaultNameColette,
    gText_DefaultNameMabel,
    gText_DefaultNameSarah,
    gText_DefaultNameAlyx,
    gText_DefaultNameEllie,
    gText_DefaultNameJoyce,
    gText_DefaultNameNancy,
    gText_DefaultNameBarbara,
    gText_DefaultNameJill
};

static const struct CompressedSpriteSheet sCompressedSpriteSheet_OakPlatform = 
{
    .data = gOakIntroPlatformGfx,
    .size = 0x600,
    .tag = 0x1000
};

static const struct SpritePalette sSpritePalette_OakPlatform = 
{
    .data = gOakIntroPlatformPal,
    .tag = 0x1000
};

static const union AnimCmd sSpriteAnim_OakPlatform1[] = 
{
    ANIMCMD_FRAME(0, 0),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_OakPlatform2[] = 
{
    ANIMCMD_FRAME(16, 0),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_OakPlatform3[] = 
{
    ANIMCMD_FRAME(32, 0),
    ANIMCMD_END
};

static const union AnimCmd *const sSpriteAnimTable_OakPlatform[] = 
{
    sSpriteAnim_OakPlatform1,
    sSpriteAnim_OakPlatform2,
    sSpriteAnim_OakPlatform3,
};

static const struct OamData sOamData_OakPlatform = 
{
    .objMode = ST_OAM_OBJ_BLEND,
    .size = 2,
    .priority = 2
};

static const struct SpriteTemplate sSpriteTemplate_OakPlatform = 
{
    .tileTag = 0x1000,
    .paletteTag = 0x1000,
    .oam = &sOamData_OakPlatform,
    .anims = sSpriteAnimTable_OakPlatform,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

// .text

enum
{
    HAS_NO_SAVED_GAME,  //NEW GAME, OPTION
    HAS_SAVED_GAME,     //CONTINUE, NEW GAME, OPTION
    HAS_MYSTERY_GIFT,   //CONTINUE, NEW GAME, MYSTERY GIFT, OPTION
    HAS_MYSTERY_EVENTS, //CONTINUE, NEW GAME, MYSTERY GIFT, MYSTERY EVENTS, OPTION
};

enum
{
    ACTION_NEW_GAME,
    ACTION_CONTINUE,
    ACTION_OPTION,
    ACTION_MYSTERY_GIFT,
    ACTION_MYSTERY_EVENTS,
    ACTION_EREADER,
    ACTION_INVALID
};

#define MAIN_MENU_BORDER_TILE   0x1D5

static void CB2_MainMenu(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

static void VBlankCB_MainMenu(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

void CB2_InitMainMenu(void)
{
    InitMainMenu(FALSE);
}

void CB2_ReinitMainMenu(void)
{
    InitMainMenu(TRUE);
}

#define tWirelessAdapterConnected data[15]

static u32 InitMainMenu(bool8 returningFromOptionsMenu)
{
    u8 taskId;
    bool8 link;
    SetVBlankCallback(NULL);

    if (IsWirelessAdapterConnected())
        link = TRUE;
    
    SetGpuReg(REG_OFFSET_DISPCNT, 0);
    SetGpuReg(REG_OFFSET_BG2CNT, 0);
    SetGpuReg(REG_OFFSET_BG1CNT, 0);
    SetGpuReg(REG_OFFSET_BG0CNT, 0);
    SetGpuReg(REG_OFFSET_BG2HOFS, 0);
    SetGpuReg(REG_OFFSET_BG2VOFS, 0);
    SetGpuReg(REG_OFFSET_BG1HOFS, 0);
    SetGpuReg(REG_OFFSET_BG1VOFS, 0);
    SetGpuReg(REG_OFFSET_BG0HOFS, 0);
    SetGpuReg(REG_OFFSET_BG0VOFS, 0);

    DmaFill16(3, 0, (void *)VRAM, VRAM_SIZE);
    DmaFill32(3, 0, (void *)OAM, OAM_SIZE);
    DmaFill16(3, 0, (void *)(PLTT + 2), PLTT_SIZE - 2);

    ResetPaletteFade();
    LoadPalette(sMainMenuBgPal, 0, 32);
    LoadPalette(sMainMenuTextPal, 0xF0, 32);
    ScanlineEffect_Stop();
    ResetTasks();
    ResetSpriteData();
    FreeAllSpritePalettes();
    if (returningFromOptionsMenu)
        gPlttBufferFaded[0] = RGB_BLACK;
    else
        gPlttBufferFaded[0] = RGB_WHITE;
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, sMainMenuBgTemplates, ARRAY_COUNT(sMainMenuBgTemplates));
    ChangeBgX(0, 0, 0);
    ChangeBgY(0, 0, 0);
    ChangeBgX(1, 0, 0);
    ChangeBgY(1, 0, 0);
    InitWindows(sWindowTemplates_MainMenu);
    DeactivateAllTextPrinters();
    LoadMainMenuWindowFrameTiles(0, MAIN_MENU_BORDER_TILE);

    SetGpuReg(REG_OFFSET_WIN0H, 0);
    SetGpuReg(REG_OFFSET_WIN0V, 0);
    SetGpuReg(REG_OFFSET_WININ, 0);
    SetGpuReg(REG_OFFSET_WINOUT, 0);
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    SetGpuReg(REG_OFFSET_BLDALPHA, 0);
    SetGpuReg(REG_OFFSET_BLDY, 0);

    EnableInterrupts(1);
    SetVBlankCallback(VBlankCB_MainMenu);
    SetMainCallback2(CB2_MainMenu);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON | DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
    ShowBg(0);
    HideBg(1);
    taskId = CreateTask(Task_MainMenuCheckSaveFile, 0);
    gTasks[taskId].tWirelessAdapterConnected = link;

    return 0;
}

#define tMenuType data[0]
#define tCurrItem data[1]
#define tCurrAction data[2]
#define tItemCount data[12]
#define tScrollArrowTaskId data[13]
#define tScrollCount data[14]

#define tArrowTaskScrollCount data[15]   // For scroll indicator arrow task

static void Task_MainMenuCheckSaveFile(u8 taskId)
{
    s16* data = gTasks[taskId].data;
    
    if (sCurrItemAndOptionMenuCheck & 0x8000)    // coming back from options screen
    {
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0x10, 0, 0x0000); // fade from black
    }
    else if (IsBGMStopped()) // coming from title screen, waiting for music to fade
    {
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0x10, 0, 0xFFFF); // fade from white
        m4aSongNumStart(MUS_MAINMENU);
    }
    else    // egads, music is not faded yet!
    {
        return;
    }

    //if (!gPaletteFade.active)
    {
        SetGpuReg(REG_OFFSET_WIN0H, 0);
        SetGpuReg(REG_OFFSET_WIN0V, 0);
        SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG0 | WININ_WIN0_OBJ);
        SetGpuReg(REG_OFFSET_WINOUT, WINOUT_WIN01_BG0 | WINOUT_WIN01_OBJ | WINOUT_WIN01_CLR);
        SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_EFFECT_DARKEN | BLDCNT_TGT1_BG0 | BLDCNT_TGT1_BG1 | BLDCNT_TGT1_BG2 | BLDCNT_TGT1_BG3 | BLDCNT_TGT1_OBJ | BLDCNT_TGT1_BD);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        SetGpuReg(REG_OFFSET_BLDY, 7);

        switch (gSaveFileStatus)
        {
            case 1:
                tMenuType = HAS_SAVED_GAME;
                if (IsMysteryGiftEnabled())
                    tMenuType = HAS_MYSTERY_GIFT;
                gTasks[taskId].func = Task_MainMenuCheckBattery;
                break;
            case 2:
                CreateMainMenuErrorWindow(gText_SaveFileErased);
                tMenuType = HAS_NO_SAVED_GAME;
                gTasks[taskId].func = Task_WaitForSaveFileErrorWindow;
                break;
            case 0xFF:
                CreateMainMenuErrorWindow(gText_SaveFileCorrupted);
                gTasks[taskId].func = Task_WaitForSaveFileErrorWindow;
                tMenuType = HAS_SAVED_GAME;
                if (IsMysteryGiftEnabled() == TRUE)
                    tMenuType++;
                break;
            case 0:
            default:
                tMenuType = HAS_NO_SAVED_GAME;
                gTasks[taskId].func = Task_MainMenuCheckBattery;
                break;
            case 4:
                CreateMainMenuErrorWindow(gJPText_No1MSubCircuit);
                gTasks[taskId].tMenuType = HAS_NO_SAVED_GAME;
                gTasks[taskId].func = Task_WaitForSaveFileErrorWindow;
                break;
        }
        if (sCurrItemAndOptionMenuCheck & OPTION_MENU_FLAG)   // are we returning from the options menu?
        {
            switch (tMenuType)  // if so, highlight the OPTIONS item
            {
                case HAS_NO_SAVED_GAME:
                case HAS_SAVED_GAME:
                    sCurrItemAndOptionMenuCheck = tMenuType + 1;
                    break;
                case HAS_MYSTERY_GIFT:
                    sCurrItemAndOptionMenuCheck = 3;
                    break;
                case HAS_MYSTERY_EVENTS:
                    sCurrItemAndOptionMenuCheck = 4;
                    break;
            }
        }
        sCurrItemAndOptionMenuCheck &= CURRENT_ITEM_MASK;  // turn off the "returning from options menu" flag
        tCurrItem = sCurrItemAndOptionMenuCheck;
        tItemCount = tMenuType + 2;
    }
}

static void Task_WaitForSaveFileErrorWindow(u8 taskId)
{
    RunTextPrinters();
    if (!IsTextPrinterActive(7) && (gMain.newKeys & A_BUTTON))
    {
        ClearWindowTilemap(7);
        ClearMainMenuWindowTilemap(&sWindowTemplates_MainMenu[7]);
        gTasks[taskId].func = Task_MainMenuCheckBattery;
    }
}

static void Task_MainMenuCheckBattery(u8 taskId)
{
    //if (!gPaletteFade.active)
    {
        SetGpuReg(REG_OFFSET_WIN0H, 0);
        SetGpuReg(REG_OFFSET_WIN0V, 0);
        SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG0 | WININ_WIN0_OBJ);
        SetGpuReg(REG_OFFSET_WINOUT, WINOUT_WIN01_BG0 | WINOUT_WIN01_OBJ | WINOUT_WIN01_CLR);
        SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_EFFECT_DARKEN | BLDCNT_TGT1_BG0 | BLDCNT_TGT1_BG1 | BLDCNT_TGT1_BG2 | BLDCNT_TGT1_BG3 | BLDCNT_TGT1_OBJ | BLDCNT_TGT1_BD);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        SetGpuReg(REG_OFFSET_BLDY, 7);
        if (!(RtcGetErrorStatus() & RTC_ERR_FLAG_MASK))
        {
            gTasks[taskId].func = Task_DisplayMainMenu;
        }
        else
        {
            CreateMainMenuErrorWindow(gText_BatteryRunDry);
            gTasks[taskId].func = Task_WaitForBatteryDryErrorWindow;
        }
    }
}

static void Task_WaitForBatteryDryErrorWindow(u8 taskId)
{
    RunTextPrinters();
    if (!IsTextPrinterActive(7) && (gMain.newKeys & A_BUTTON))
    {
        ClearWindowTilemap(7);
        ClearMainMenuWindowTilemap(&sWindowTemplates_MainMenu[7]);
        gTasks[taskId].func = Task_DisplayMainMenu;
    }
}

static void Task_DisplayMainMenu(u8 taskId)
{
    s16* data = gTasks[taskId].data;
    u16 palette;

    //if (!gPaletteFade.active)
    {
        SetGpuReg(REG_OFFSET_WIN0H, 0);
        SetGpuReg(REG_OFFSET_WIN0V, 0);
        SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG0 | WININ_WIN0_OBJ);
        SetGpuReg(REG_OFFSET_WINOUT, WINOUT_WIN01_BG0 | WINOUT_WIN01_OBJ | WINOUT_WIN01_CLR);
        SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_EFFECT_DARKEN | BLDCNT_TGT1_BG0 | BLDCNT_TGT1_BG1 | BLDCNT_TGT1_BG2 | BLDCNT_TGT1_BG3 | BLDCNT_TGT1_OBJ | BLDCNT_TGT1_BD);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        SetGpuReg(REG_OFFSET_BLDY, 7);
        
        gPlttBufferUnfaded[254] = RGB_BLACK;
        gPlttBufferUnfaded[250] = RGB_WHITE;
        gPlttBufferUnfaded[251] = RGB(12, 12, 12);
        gPlttBufferUnfaded[252] = RGB(26, 26, 25);

        // Note: If there is no save file, the save block is zeroed out,
        // so the default gender is MALE.
        if (gSaveBlock2Ptr->playerGender == MALE)
            gPlttBufferUnfaded[241] = RGB(4, 16, 31);
        else
            gPlttBufferUnfaded[241] = RGB(31, 3, 21);
        
        // Fixes weird fading stuff thanks to having loaded early (yes this is all quite hacky, why do you ask .-.)
        if (!gPaletteFade.active)
            UnfadePlttBuffer(0xFFFFFFFF);

        tScrollArrowTaskId = 0xFF;

        switch (gTasks[taskId].tMenuType)
        {
            case HAS_NO_SAVED_GAME:
            default:
                FillWindowPixelBuffer(0, PIXEL_FILL(0xA));
                FillWindowPixelBuffer(1, PIXEL_FILL(0xA));
                AddTextPrinterParameterized3(0, 1, 2, 2, sTextColor_Headers, -1, gText_MainMenuNewGame);
                AddTextPrinterParameterized3(1, 1, 2, 2, sTextColor_Headers, -1, gText_MainMenuOption);
                PutWindowTilemap(0);
                PutWindowTilemap(1);
                CopyWindowToVram(0, 2);
                CopyWindowToVram(1, 2);
                DrawMainMenuWindowBorder(&sWindowTemplates_MainMenu[0], MAIN_MENU_BORDER_TILE);
                DrawMainMenuWindowBorder(&sWindowTemplates_MainMenu[1], MAIN_MENU_BORDER_TILE);
                break;
            case HAS_SAVED_GAME:
                FillWindowPixelBuffer(2, PIXEL_FILL(0xA));
                FillWindowPixelBuffer(3, PIXEL_FILL(0xA));
                FillWindowPixelBuffer(4, PIXEL_FILL(0xA));
                AddTextPrinterParameterized3(2, 1, 2, 2, sTextColor_Headers, -1, gText_MainMenuContinue);
                AddTextPrinterParameterized3(3, 1, 2, 2, sTextColor_Headers, -1, gText_MainMenuNewGame);
                AddTextPrinterParameterized3(4, 1, 2, 2, sTextColor_Headers, -1, gText_MainMenuOption);
                MainMenu_FormatSavegameText();
                PutWindowTilemap(2);
                PutWindowTilemap(3);
                PutWindowTilemap(4);
                CopyWindowToVram(2, 2);
                CopyWindowToVram(3, 2);
                CopyWindowToVram(4, 2);
                DrawMainMenuWindowBorder(&sWindowTemplates_MainMenu[2], MAIN_MENU_BORDER_TILE);
                DrawMainMenuWindowBorder(&sWindowTemplates_MainMenu[3], MAIN_MENU_BORDER_TILE);
                DrawMainMenuWindowBorder(&sWindowTemplates_MainMenu[4], MAIN_MENU_BORDER_TILE);
                break;
            case HAS_MYSTERY_GIFT:
                FillWindowPixelBuffer(2, PIXEL_FILL(0xA));
                FillWindowPixelBuffer(3, PIXEL_FILL(0xA));
                FillWindowPixelBuffer(4, PIXEL_FILL(0xA));
                FillWindowPixelBuffer(5, PIXEL_FILL(0xA));
                AddTextPrinterParameterized3(2, 1, 2, 2, sTextColor_Headers, -1, gText_MainMenuContinue);
                AddTextPrinterParameterized3(3, 1, 2, 2, sTextColor_Headers, -1, gText_MainMenuNewGame);
                AddTextPrinterParameterized3(4, 1, 2, 2, sTextColor_Headers, -1, gText_MainMenuMysteryGift);
                AddTextPrinterParameterized3(5, 1, 2, 2, sTextColor_Headers, -1, gText_MainMenuOption);
                MainMenu_FormatSavegameText();
                PutWindowTilemap(2);
                PutWindowTilemap(3);
                PutWindowTilemap(4);
                PutWindowTilemap(5);
                CopyWindowToVram(2, 2);
                CopyWindowToVram(3, 2);
                CopyWindowToVram(4, 2);
                CopyWindowToVram(5, 2);
                DrawMainMenuWindowBorder(&sWindowTemplates_MainMenu[2], MAIN_MENU_BORDER_TILE);
                DrawMainMenuWindowBorder(&sWindowTemplates_MainMenu[3], MAIN_MENU_BORDER_TILE);
                DrawMainMenuWindowBorder(&sWindowTemplates_MainMenu[4], MAIN_MENU_BORDER_TILE);
                DrawMainMenuWindowBorder(&sWindowTemplates_MainMenu[5], MAIN_MENU_BORDER_TILE);
                tScrollArrowTaskId = AddScrollIndicatorArrowPair(&sScrollArrowsTemplate_MainMenu, &sCurrItemAndOptionMenuCheck);
                gTasks[tScrollArrowTaskId].func = Task_ScrollIndicatorArrowPairOnMainMenu;
                if (sCurrItemAndOptionMenuCheck == 3)
                {
                    ChangeBgY(0, 0x2000, 1);
                    ChangeBgY(1, 0x2000, 1);
                    tScrollCount = 1;
                    gTasks[tScrollArrowTaskId].tArrowTaskScrollCount = 2;
                }
                break;
            case HAS_MYSTERY_EVENTS:
                FillWindowPixelBuffer(2, PIXEL_FILL(0xA));
                FillWindowPixelBuffer(3, PIXEL_FILL(0xA));
                FillWindowPixelBuffer(4, PIXEL_FILL(0xA));
                FillWindowPixelBuffer(5, PIXEL_FILL(0xA));
                FillWindowPixelBuffer(6, PIXEL_FILL(0xA));
                AddTextPrinterParameterized3(2, 1, 2, 2, sTextColor_Headers, -1, gText_MainMenuContinue);
                AddTextPrinterParameterized3(3, 1, 2, 2, sTextColor_Headers, -1, gText_MainMenuNewGame);
                AddTextPrinterParameterized3(4, 1, 2, 2, sTextColor_Headers, -1, gText_MainMenuMysteryGift2);
                AddTextPrinterParameterized3(5, 1, 2, 2, sTextColor_Headers, -1, gText_MainMenuMysteryEvents);
                AddTextPrinterParameterized3(6, 1, 2, 2, sTextColor_Headers, -1, gText_MainMenuOption);
                MainMenu_FormatSavegameText();
                PutWindowTilemap(2);
                PutWindowTilemap(3);
                PutWindowTilemap(4);
                PutWindowTilemap(5);
                PutWindowTilemap(6);
                CopyWindowToVram(2, 2);
                CopyWindowToVram(3, 2);
                CopyWindowToVram(4, 2);
                CopyWindowToVram(5, 2);
                CopyWindowToVram(6, 2);
                DrawMainMenuWindowBorder(&sWindowTemplates_MainMenu[2], MAIN_MENU_BORDER_TILE);
                DrawMainMenuWindowBorder(&sWindowTemplates_MainMenu[3], MAIN_MENU_BORDER_TILE);
                DrawMainMenuWindowBorder(&sWindowTemplates_MainMenu[4], MAIN_MENU_BORDER_TILE);
                DrawMainMenuWindowBorder(&sWindowTemplates_MainMenu[5], MAIN_MENU_BORDER_TILE);
                DrawMainMenuWindowBorder(&sWindowTemplates_MainMenu[6], MAIN_MENU_BORDER_TILE);
                tScrollArrowTaskId = AddScrollIndicatorArrowPair(&sScrollArrowsTemplate_MainMenu, &sCurrItemAndOptionMenuCheck);
                gTasks[tScrollArrowTaskId].func = Task_ScrollIndicatorArrowPairOnMainMenu;
                if (sCurrItemAndOptionMenuCheck == 4)
                {
                    ChangeBgY(0, 0x4000, 1);
                    ChangeBgY(1, 0x4000, 1);
                    tScrollCount = 2;
                    gTasks[tScrollArrowTaskId].tArrowTaskScrollCount = 2;
                }
                break;
        }
        gTasks[taskId].func = Task_HighlightSelectedMainMenuItem;
    }
}

static void Task_HighlightSelectedMainMenuItem(u8 taskId)
{
    HighlightSelectedMainMenuItem(gTasks[taskId].tMenuType, gTasks[taskId].tCurrItem, gTasks[taskId].tScrollCount);
    gTasks[taskId].func = Task_HandleMainMenuInput;
}

static bool8 HandleMainMenuInput(u8 taskId)
{
    s16* data = gTasks[taskId].data;

    if (!gPaletteFade.active)
    {
        if (gMain.newKeys & A_BUTTON)
        {
            PlaySE(SE_SELECT);
            //IsWirelessAdapterConnected();   // why bother calling this here? debug? Task_HandleMainMenuAPressed will check too
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 0x10, RGB_BLACK);
            gTasks[taskId].func = Task_HandleMainMenuAPressed;
        }
        else if (gMain.newKeys & B_BUTTON)
        {
            PlaySE(SE_SELECT);
            FadeOutBGM(2);
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 0x10, RGB_WHITEALPHA);
            SetGpuReg(REG_OFFSET_WIN0H, WIN_RANGE(0, 240));
            SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE(0, 160));
            gTasks[taskId].func = Task_HandleMainMenuBPressed;
        }
        else if ((gMain.newKeys & DPAD_UP) && tCurrItem > 0)
        {
            if (tMenuType >= HAS_MYSTERY_GIFT && tCurrItem == 1)
            {
                if (tScrollCount == 1)
                {
                    ChangeBgY(0, 0x2000, 2);
                    ChangeBgY(1, 0x2000, 2);
                }
                else if (tScrollCount == 2)
                {
                    ChangeBgY(0, 0x4000, 2);
                    ChangeBgY(1, 0x4000, 2);
                }
                gTasks[tScrollArrowTaskId].tArrowTaskScrollCount = tScrollCount = 0;
            }
            sCurrItemAndOptionMenuCheck = --tCurrItem;
            return TRUE;
        }
        else if ((gMain.newKeys & DPAD_DOWN) && tCurrItem < tItemCount - 1)
        {
            if (tMenuType >= HAS_MYSTERY_GIFT && ((tCurrItem == 2 && tScrollCount == 0) || (tCurrItem == 3 && tScrollCount == 1)))
            {
                ChangeBgY(0, 0x2000, 1);
                ChangeBgY(1, 0x2000, 1);
                gTasks[tScrollArrowTaskId].tArrowTaskScrollCount = ++tScrollCount;
            }

            if (tMenuType == HAS_MYSTERY_GIFT && tScrollCount == 1)
            {
                gTasks[tScrollArrowTaskId].tArrowTaskScrollCount = 2;
            }

            sCurrItemAndOptionMenuCheck = ++tCurrItem;
            return TRUE;
        }
    }
    return FALSE;
}

static void Task_HandleMainMenuInput(u8 taskId)
{
    if (HandleMainMenuInput(taskId))
        gTasks[taskId].func = Task_HighlightSelectedMainMenuItem;
}

static void Task_HandleMainMenuAPressed(u8 taskId)
{
    bool8 wirelessAdapterConnected;
    u8 action = ACTION_NEW_GAME;

    wirelessAdapterConnected = IsWirelessAdapterConnected();
    switch (gTasks[taskId].tMenuType)
    {
        case HAS_NO_SAVED_GAME:
        default:
            switch (gTasks[taskId].tCurrItem)
            {
                case 0:
                default:
                    action = ACTION_NEW_GAME;
                    break;
                case 1:
                    action = ACTION_OPTION;
                    break;
            }
            break;
        case HAS_SAVED_GAME:
            switch (gTasks[taskId].tCurrItem)
            {
                case 0:
                default:
                    action = ACTION_CONTINUE;
                    break;
                case 1:
                    action = ACTION_NEW_GAME;
                    break;
                case 2:
                    action = ACTION_OPTION;
                    break;
            }
            break;
        case HAS_MYSTERY_GIFT:
            switch (gTasks[taskId].tCurrItem)
            {
                case 0:
                default:
                    action = ACTION_CONTINUE;
                    break;
                case 1:
                    action = ACTION_NEW_GAME;
                    break;
                case 2:
                    action = ACTION_MYSTERY_GIFT;
                    if (!wirelessAdapterConnected)
                    {
                        action = ACTION_INVALID;
                        gTasks[taskId].tMenuType = HAS_NO_SAVED_GAME;
                    }
                    break;
                case 3:
                    action = ACTION_OPTION;
                    break;
            }
            break;
        case HAS_MYSTERY_EVENTS:
            switch (gTasks[taskId].tCurrItem)
            {
                case 0:
                default:
                    action = ACTION_CONTINUE;
                    break;
                case 1:
                    action = ACTION_NEW_GAME;
                    break;
                case 2:
                    if (gTasks[taskId].tWirelessAdapterConnected)
                    {
                        action = ACTION_MYSTERY_GIFT;
                        if (!wirelessAdapterConnected)
                        {
                            action = ACTION_INVALID;
                            gTasks[taskId].tMenuType = HAS_NO_SAVED_GAME;
                        }
                    }
                    else if (wirelessAdapterConnected)
                    {
                        action = ACTION_INVALID;
                        gTasks[taskId].tMenuType = HAS_SAVED_GAME;
                    }
                    else
                    {
                        action = ACTION_EREADER;
                    }
                    break;
                case 3:
                    if (wirelessAdapterConnected)
                    {
                        action = ACTION_INVALID;
                        gTasks[taskId].tMenuType = HAS_MYSTERY_GIFT;
                    }
                    else
                    {
                        action = ACTION_MYSTERY_EVENTS;
                    }
                    break;
                case 4:
                    action = ACTION_OPTION;
                    break;
            }
            break;
    }
    if (action != ACTION_OPTION && action != ACTION_INVALID)
    {
        if (action == ACTION_CONTINUE)
            FadeOutBGM(2);
        else
            FadeOutBGM(4);
    }

    gTasks[taskId].tCurrAction = action;
    gTasks[taskId].func = Task_HandleMainMenuAPressed_;
}

static void Task_HandleMainMenuAPressed_(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        if (gTasks[taskId].tScrollArrowTaskId != 0xFF)
            RemoveScrollIndicatorArrowPair(gTasks[taskId].tScrollArrowTaskId);
        ClearStdWindowAndFrame(0, TRUE);
        ClearStdWindowAndFrame(1, TRUE);
        ClearStdWindowAndFrame(2, TRUE);
        ClearStdWindowAndFrame(3, TRUE);
        ClearStdWindowAndFrame(4, TRUE);
        ClearStdWindowAndFrame(5, TRUE);
        ClearStdWindowAndFrame(6, TRUE);
        ClearStdWindowAndFrame(7, TRUE);
        
        ChangeBgY(0, 0, 0);
        ChangeBgY(1, 0, 0);
        switch (gTasks[taskId].tCurrAction)
        {
            case ACTION_NEW_GAME:
            default:
                gPlttBufferUnfaded[0] = RGB_BLACK;
                gPlttBufferFaded[0] = RGB_BLACK;
                gIsStaircaseWarpAnimDisabled = FALSE;
                gTasks[taskId].func = Task_NewGameClockSetIntro1;
                break;
            case ACTION_CONTINUE:
                gPlttBufferUnfaded[0] = RGB_BLACK;
                gPlttBufferFaded[0] = RGB_BLACK;
                gIsStaircaseWarpAnimDisabled = FALSE;
                SetMainCallback2(CB2_ContinueSavedGame);
                DestroyTask(taskId);
                break;
            case ACTION_OPTION:
                gMain.savedCallback = CB2_ReinitMainMenu;
                SetMainCallback2(CB2_InitOptionMenu);
                DestroyTask(taskId);
                break;
            case ACTION_MYSTERY_GIFT:
                SetMainCallback2(c2_mystery_gift);
                DestroyTask(taskId);
                break;
            case ACTION_MYSTERY_EVENTS:
                SetMainCallback2(CB2_InitMysteryEventMenu);
                DestroyTask(taskId);
                break;
            case ACTION_EREADER:
                SetMainCallback2(c2_ereader);
                DestroyTask(taskId);
                break;
            case ACTION_INVALID:
                gTasks[taskId].tCurrItem = 0;
                gTasks[taskId].func = Task_DisplayMainMenuInvalidActionError;
                gPlttBufferUnfaded[0xF1] = RGB_WHITE;
                gPlttBufferFaded[0xF1] = RGB_WHITE;
                SetGpuReg(REG_OFFSET_BG2HOFS, 0);
                SetGpuReg(REG_OFFSET_BG2VOFS, 0);
                SetGpuReg(REG_OFFSET_BG1HOFS, 0);
                SetGpuReg(REG_OFFSET_BG1VOFS, 0);
                SetGpuReg(REG_OFFSET_BG0HOFS, 0);
                SetGpuReg(REG_OFFSET_BG0VOFS, 0);
                BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, RGB_BLACK);
                return;
        }
        FreeAllWindowBuffers();
        if (gTasks[taskId].tCurrAction != ACTION_OPTION)
            sCurrItemAndOptionMenuCheck = 0;
        else
            sCurrItemAndOptionMenuCheck |= OPTION_MENU_FLAG;  // entering the options menu
    }
}

static void Task_HandleMainMenuBPressed(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        if (gTasks[taskId].tScrollArrowTaskId != 0xFF)
            RemoveScrollIndicatorArrowPair(gTasks[taskId].tScrollArrowTaskId);
        sCurrItemAndOptionMenuCheck = 0;
        FreeAllWindowBuffers();
        SetMainCallback2(CB2_InitTitleScreen);
        DestroyTask(taskId);
    }
}

static void Task_DisplayMainMenuInvalidActionError(u8 taskId)
{
    switch (gTasks[taskId].tCurrItem)
    {
        case 0:
            FillBgTilemapBufferRect_Palette0(0, 0, 0, 0, 30, 20);
            switch (gTasks[taskId].tMenuType)
            {
                case 0:
                    CreateMainMenuErrorWindow(gText_WirelessNotConnected);
                    break;
                case 1:
                    CreateMainMenuErrorWindow(gText_MysteryGiftCantUse);
                    break;
                case 2:
                    CreateMainMenuErrorWindow(gText_MysteryEventsCantUse);
                    break;
            }
            gTasks[taskId].tCurrItem++;
            break;
        case 1:
            if (!gPaletteFade.active)
                gTasks[taskId].tCurrItem++;
            break;
        case 2:
            RunTextPrinters();
            if (!IsTextPrinterActive(7))
                gTasks[taskId].tCurrItem++;
            break;
        case 3:
            if (gMain.newKeys & (A_BUTTON | B_BUTTON))
            {
                PlaySE(SE_SELECT);
                BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
                gTasks[taskId].func = Task_HandleMainMenuBPressed;
            }
    }
}

#undef tMenuType
#undef tCurrItem
#undef tItemCount
#undef tScrollArrowTaskId
#undef tScrollCount
#undef tWirelessAdapterConnected

#undef tArrowTaskScrollCount

static void HighlightSelectedMainMenuItem(u8 menuType, u8 selectedMenuItem, s16 scrollCount)
{
    SetGpuReg(REG_OFFSET_WIN0H, MENU_WIN_HCOORDS);

    switch (menuType)
    {
        case HAS_NO_SAVED_GAME:
        default:
            switch (selectedMenuItem)
            {
                case 0:
                default:
                    SetGpuReg(REG_OFFSET_WIN0V, MENU_WIN_VCOORDS(0));
                    break;
                case 1:
                    SetGpuReg(REG_OFFSET_WIN0V, MENU_WIN_VCOORDS(1));
                    break;
            }
            break;
        case HAS_SAVED_GAME:
            switch (selectedMenuItem)
            {
                case 0:
                default:
                    SetGpuReg(REG_OFFSET_WIN0V, MENU_WIN_VCOORDS(2));
                    break;
                case 1:
                    SetGpuReg(REG_OFFSET_WIN0V, MENU_WIN_VCOORDS(3));
                    break;
                case 2:
                    SetGpuReg(REG_OFFSET_WIN0V, MENU_WIN_VCOORDS(4));
                    break;
            }
            break;
        case HAS_MYSTERY_GIFT:
            switch (selectedMenuItem)
            {
                case 0:
                default:
                    SetGpuReg(REG_OFFSET_WIN0V, MENU_WIN_VCOORDS(2));
                    break;
                case 1:
                    if (scrollCount == 1)
                        SetGpuReg(REG_OFFSET_WIN0V, MENU_WIN_VCOORDS(3) - MENU_SCROLL_SHIFT);
                    else
                        SetGpuReg(REG_OFFSET_WIN0V, MENU_WIN_VCOORDS(3));
                    break;
                case 2:
                    if (scrollCount == 1)
                        SetGpuReg(REG_OFFSET_WIN0V, MENU_WIN_VCOORDS(4) - MENU_SCROLL_SHIFT);
                    else
                        SetGpuReg(REG_OFFSET_WIN0V, MENU_WIN_VCOORDS(4));
                    break;
                case 3:
                    if (scrollCount == 1)
                        SetGpuReg(REG_OFFSET_WIN0V, MENU_WIN_VCOORDS(5) - MENU_SCROLL_SHIFT);
                    else
                        SetGpuReg(REG_OFFSET_WIN0V, MENU_WIN_VCOORDS(5));
                    break;
            }
            break;
        case HAS_MYSTERY_EVENTS:
            switch (selectedMenuItem)
            {
                case 0:
                default:
                    SetGpuReg(REG_OFFSET_WIN0V, MENU_WIN_VCOORDS(2));
                    break;
                case 1:
                    if (scrollCount == 2)
                        SetGpuReg(REG_OFFSET_WIN0V, MENU_WIN_VCOORDS(3) - (MENU_SCROLL_SHIFT * 2));
                    else if (scrollCount == 1)
                        SetGpuReg(REG_OFFSET_WIN0V, MENU_WIN_VCOORDS(3) - MENU_SCROLL_SHIFT);
                    else
                        SetGpuReg(REG_OFFSET_WIN0V, MENU_WIN_VCOORDS(3));
                    break;
                case 2:
                    if (scrollCount == 2)
                        SetGpuReg(REG_OFFSET_WIN0V, MENU_WIN_VCOORDS(4) - (MENU_SCROLL_SHIFT * 2));
                    else if (scrollCount == 1)
                        SetGpuReg(REG_OFFSET_WIN0V, MENU_WIN_VCOORDS(4) - MENU_SCROLL_SHIFT);
                    else
                        SetGpuReg(REG_OFFSET_WIN0V, MENU_WIN_VCOORDS(4));
                    break;
                case 3:
                    if (scrollCount == 2)
                        SetGpuReg(REG_OFFSET_WIN0V, MENU_WIN_VCOORDS(5) - (MENU_SCROLL_SHIFT * 2));
                    else if (scrollCount == 1)
                        SetGpuReg(REG_OFFSET_WIN0V, MENU_WIN_VCOORDS(5) - MENU_SCROLL_SHIFT);
                    else
                        SetGpuReg(REG_OFFSET_WIN0V, MENU_WIN_VCOORDS(5));
                    break;
                case 4:
                    SetGpuReg(REG_OFFSET_WIN0V, MENU_WIN_VCOORDS(6) - (MENU_SCROLL_SHIFT * 2));
                    break;
            }
            break;
    }
}

void Task_NewGameClockSetIntro1(u8 taskId)
{
    if (IsBGMStopped())
    {
        gTasks[taskId].data[0] = 15;
        gTasks[taskId].func = Task_NewGameClockSetIntro2;
    }
}

void Task_NewGameClockSetIntro2(u8 taskId)
{
    if (--gTasks[taskId].data[0] == 0)
    {
        SetGpuReg(REG_OFFSET_DISPCNT, 0);
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
        InitBgFromTemplate(&sOakBgTemplates[0]);
        SetGpuReg(REG_OFFSET_WIN0H, 0);
        SetGpuReg(REG_OFFSET_WIN0V, 0);
        SetGpuReg(REG_OFFSET_WININ, 0);
        SetGpuReg(REG_OFFSET_WINOUT, 0);
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        SetGpuReg(REG_OFFSET_BLDY, 0);

        ScanlineEffect_Stop();
        ResetSpriteData();
        FreeAllSpritePalettes();
        ResetPaletteFade();
        ResetAllPicSprites();

        gTasks[taskId].func = Task_NewGameClockSetIntro3;
        
        ShowBg(0);
    }
}

void Task_NewGameClockSetIntro3(u8 taskId)
{
    InitWindows(sClockSetWindowTemplates);
    LoadMessageBoxGfx(0, 0xFC,  0xF0);
    PutWindowTilemap(0);
    CopyWindowToVram(0, 2);
    StringExpandPlaceholders(gStringVar4, gText_SetClock_WokeMeUp);
    AddTextPrinterForMessage_IgnoreTextColor(1);
    BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, 0);
    NewGameOakSpeech_ShowDialogueWindow(0, 1);
    gTasks[taskId].func = Task_NewGameClockSetIntro4;
}

void Task_NewGameClockSetIntro4(u8 taskId)
{
    if (!RunTextPrintersAndIsPrinter0Active() && gMain.newKeys & (A_BUTTON | B_BUTTON))
    {
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 0x10, 0);
        gTasks[taskId].func = Task_NewGameClockSetIntro5;
    }
}

static void ReturnFromSetClock(void)
{
    u8 taskId;

    //InitTimeBasedEvents();
    ResetBgsAndClearDma3BusyFlags(0);
    SetGpuReg(REG_OFFSET_DISPCNT, 0);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
    sOakIntro_BgBuffer = AllocZeroed(0x400);
    //InitBgsFromTemplates(0, sMainMenuBgTemplates, 2);
    InitBgsFromTemplates(1, sOakBgTemplates, ARRAY_COUNT(sOakBgTemplates));
    SetBgTilemapBuffer(2, sOakIntro_BgBuffer);
    ResetAllBgsCoordinates();
    SetVBlankCallback(NULL);
    SetGpuReg(REG_OFFSET_BG2CNT, 0);
    SetGpuReg(REG_OFFSET_BG1CNT, 0);
    SetGpuReg(REG_OFFSET_BG0CNT, 0);
    SetGpuReg(REG_OFFSET_BG2HOFS, 0);
    SetGpuReg(REG_OFFSET_BG2VOFS, 0);
    SetGpuReg(REG_OFFSET_BG1HOFS, 0);
    SetGpuReg(REG_OFFSET_BG1VOFS, 0);
    SetGpuReg(REG_OFFSET_BG0HOFS, 0);
    SetGpuReg(REG_OFFSET_BG0VOFS, 0);
    DmaFill16(3, 0, VRAM, VRAM_SIZE);
    DmaFill32(3, 0, OAM, OAM_SIZE);
    DmaFill16(3, 0, PLTT, PLTT_SIZE);
    ResetPaletteFade();
    ResetTasks();
    taskId = CreateTask(Task_NewGameClockSetIntro6, 0);
    gTasks[taskId].data[0] = 0;
    ScanlineEffect_Stop();
    ResetSpriteData();
    FreeAllSpritePalettes();
    ResetAllPicSprites();
    SetGpuReg(REG_OFFSET_WIN0H, 0);
    SetGpuReg(REG_OFFSET_WIN0V, 0);
    SetGpuReg(REG_OFFSET_WININ, 0);
    SetGpuReg(REG_OFFSET_WINOUT, 0);
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    SetGpuReg(REG_OFFSET_BLDALPHA, 0);
    SetGpuReg(REG_OFFSET_BLDY, 0);
    gPlttBufferUnfaded[0] = RGB_BLACK;
    gPlttBufferFaded[0] = RGB_BLACK;
    SetVBlankCallback(VBlankCB_MainMenu);
    SetMainCallback2(CB2_MainMenu);
}

void Task_NewGameClockSetIntro5(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        SetMainCallback2(CB2_StartWallClock);
        gMain.savedCallback = ReturnFromSetClock;
    }
}

void Task_NewGameClockSetIntro6(u8 taskId)
{
    if (gTasks[taskId].data[0]++ > 30)
    {
        gTasks[taskId].func = Task_NewGameOakSpeech_Init;
    }
}

#define tPlayerSpriteId data[2]
#define tPokeBallSpriteId data[3]
#define tSlideOffset data[4]
#define tIsDoneFadingSprites data[5]
#define tPlayerGender data[6]
#define tTimer data[7]
#define tWooperSpriteId data[8]
#define tLotadSpriteId data[9]
#define tBrendanSpriteId data[10]
#define tMaySpriteId data[11]
#define tTimer2 data[12]

enum {
    INTRO_GOLD,
    INTRO_KRIS,
    INTRO_OAK,
};

static void Task_NewGameOakSpeech_Init(u8 taskId)
{
    LZ77UnCompVram(sOakSpeechBgGfx, (void*)VRAM);
    LZ77UnCompVram(sOakSpeechBgMap, (void*)(VRAM + 0xF000));
    LoadPalette(sOakSpeechBgPal, 0, 64);
    gPlttBufferUnfaded[0] = RGB_BLACK;
    gPlttBufferFaded[0] = RGB_BLACK;
    AddOakSpeechObjects(taskId);
    LoadOakIntroBigSprite(INTRO_OAK, 0);
    BeginNormalPaletteFade(0xFFFFFFFF, 4, 16, 0, 0);
    gTasks[taskId].tSlideOffset = 0;
    gTasks[taskId].func = Task_NewGameOakSpeech_WaitForTextToStart;
    gTasks[taskId].tPlayerSpriteId = 0xFF;
    gTasks[taskId].tPokeBallSpriteId = 0xFF;
    gTasks[taskId].tTimer = 80;
    PlayBGM(MUS_ROUTE30);
    ShowBg(0);
    ShowBg(1);
    ShowBg(2);
}

static void LoadOakIntroBigSprite(u16 which, u16 offset)
{
    u8 *buffer;
    u8 i;

    switch (which)
    {
        case INTRO_GOLD:
            LoadPalette(sOakIntro_GoldPal, 0x40, sizeof(sOakIntro_GoldPal));
            LZ77UnCompVram(sOakIntro_GoldTiles, (void *)(VRAM + 0x600 + offset));
            break;
        case INTRO_KRIS:
            LoadPalette(sOakIntro_KrisPal, 0x40, sizeof(sOakIntro_KrisPal));
            LZ77UnCompVram(sOakIntro_KrisTiles, (void *)(VRAM + 0x600 + offset));
            break;
        case INTRO_OAK:
            LoadPalette(sOakIntro_OakPal, 0x60, sizeof(sOakIntro_OakPal));
            LZ77UnCompVram(sOakIntro_OakTiles, (void *)(VRAM + 0x600 + offset));
            break;
    }

    buffer = AllocZeroed(0x60);

    for (i = 0; i < 0x60; i++)
    {
        buffer[i] = i;
    }

    FillBgTilemapBufferRect(2, 0, 0, 0, 32, 32, 16);
    CopyRectToBgTilemapBufferRect(2, buffer, 0, 0, 8, 12, 11, 2, 8, 12, 16, (offset * 64) + 24, 0);
    CopyBgTilemapBufferToVram(2);
    FREE_AND_SET_NULL(buffer);
}

static void Task_NewGameOakSpeech_WaitForTextToStart(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        if (gTasks[taskId].tTimer)
        {
            gTasks[taskId].tTimer--;
        }
        else
        {
            InitWindows(gNewGameBirchSpeechTextWindows);
            LoadMainMenuWindowFrameTiles(0, 0xF3);
            LoadMessageBoxGfx(0, 0xFC,  0xF0);
            NewGameOakSpeech_ShowDialogueWindow(0, 1);
            PutWindowTilemap(0);
            CopyWindowToVram(0, 2);
            FillWindowPixelBuffer(0, 0x11);
            StringExpandPlaceholders(gStringVar4, gText_Oak_Welcome);
            AddTextPrinterForMessage_IgnoreTextColor(1);
            gTasks[taskId].func = Task_NewGameOakSpeech_PrintThisEllipsis;
        }
    }
}

static void Task_NewGameOakSpeech_PrintThisEllipsis(u8 taskId)
{
    if (!RunTextPrintersAndIsPrinter0Active())
    {
        StringExpandPlaceholders(gStringVar4, gText_Oak_Pokemon);
        AddTextPrinterForMessage_IgnoreTextColor(1);
        gTasks[taskId].func = Task_NewGameOakSpeech_CreatePokeBallToReleaseWooper;
    }
}

static void Task_NewGameOakSpeech_CreatePokeBallToReleaseWooper(u8 taskId)
{
    if (!RunTextPrintersAndIsPrinter0Active())
    {
        u8 spriteId = gTasks[taskId].tWooperSpriteId;
        gSprites[spriteId].data[0] = 0;

        CreatePokeballSpriteToReleaseMon(spriteId, gSprites[spriteId].oam.paletteNum, 100, 66, 0, 0, 0x20, 0xFFFF1FFF, SPECIES_WOOPER);
        gTasks[taskId].func = Task_NewGameOakSpeech_PrintIsPokemonWaitForAnimation;
        gTasks[taskId].tTimer = 0;
    }
}

static void Task_NewGameOakSpeech_PrintIsPokemonWaitForAnimation(u8 taskId)
{
    if (gSprites[gTasks[taskId].tWooperSpriteId].animEnded)
    //if (IsCryFinished())
    {
        if (gTasks[taskId].tTimer >= 96)
        {
            // just gotta reset these back to normal after they were changed (that was a hard one to track down)
            gSprites[gTasks[taskId].tWooperSpriteId].affineAnimPaused = FALSE;
            gSprites[gTasks[taskId].tWooperSpriteId].affineAnims = gUnknown_082FF694;
            gTasks[taskId].func = Task_NewGameOakSpeech_MainSpeech1;
        }
    }
        
    if (gTasks[taskId].tTimer < 0x4000)
    {
        gTasks[taskId].tTimer++;
        
        if (gTasks[taskId].tTimer == 32)
        {
            StringExpandPlaceholders(gStringVar4, gText_Oak_Pokemon2);
            AddTextPrinterForMessage_IgnoreTextColor(1);
            FillWindowPixelBuffer(0, 0x11);
        }
    }
    RunTextPrinters();
}

static void Task_NewGameOakSpeech_MainSpeech1(u8 taskId)
{
    if (!RunTextPrintersAndIsPrinter0Active())
    {
        StringExpandPlaceholders(gStringVar4, gText_Oak_MainSpeech);
        AddTextPrinterForMessage_IgnoreTextColor(1);
        gTasks[taskId].func = Task_NewGameOakSpeech_PutAwayWooper;
    }
}

static void Task_NewGameOakSpeech_PutAwayWooper(u8 taskId)
{
    u8 spriteId;
    if (!RunTextPrintersAndIsPrinter0Active())
    {
        ClearDialogWindowAndFrame(0, TRUE);
        spriteId = gTasks[taskId].tWooperSpriteId;
        gTasks[taskId].tPokeBallSpriteId = sub_807671C(spriteId, gSprites[spriteId].oam.paletteNum, 100, 66, 0, 0, 0x20, 0xFFFF1F3F);
        gTasks[taskId].tTimer2 = 48;
        gTasks[taskId].tTimer = 64;
        gTasks[taskId].func = Task_NewGameOakSpeech_MainSpeech2;
    }
}

static void Task_NewGameOakSpeech_MainSpeech2(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (tTimer != 0)
    {
        if (tTimer < 24)
        {
            gSprites[tWooperSpriteId].pos1.y--;
        }
        tTimer--;
    }
    else
    {
        if (tTimer2 == 48)
        {
            FreeAndDestroyMonPicSprite(gTasks[taskId].tWooperSpriteId);
            DestroySprite(&gSprites[tPokeBallSpriteId]);
        }
        
        if (tTimer2 != 0)
        {
            tTimer2--;
        }
        else
        {
            NewGameOakSpeech_ShowDialogueWindow(0, FALSE);
            StringExpandPlaceholders(gStringVar4, gText_Oak_MainSpeech2);
            AddTextPrinterForMessage_IgnoreTextColor(1);
            CopyWindowToVram(0, 3);
            gTasks[taskId].func = Task_NewGameOakSpeech_StartOakPlatformFade;
        }
    }
}

static void Task_NewGameOakSpeech_StartOakPlatformFade(u8 taskId)
{
    if (!RunTextPrintersAndIsPrinter0Active())
    {
        ClearDialogWindowAndFrame(0, TRUE);
        NewGameOakSpeech_StartFadeOutTarget1InTarget2(taskId, 1);
        gTasks[taskId].tTimer = 48;
        gTasks[taskId].func = Task_NewGameOakSpeech_WaitOakPlatformFade;
    }
}

static void Task_NewGameOakSpeech_WaitOakPlatformFade(u8 taskId)
{
    if (gTasks[taskId].tIsDoneFadingSprites)
    {
        if (gTasks[taskId].tTimer)
        {
            gTasks[taskId].tTimer--;
        }
        else
        {
            gTasks[taskId].func = Task_NewGameOakSpeech_BoyOrGirl;
        }
    }
}

static void Task_NewGameOakSpeech_BoyOrGirl(u8 taskId)
{
    NewGameOakSpeech_ShowDialogueWindow(0, FALSE);
    FillWindowPixelBuffer(0, 0x11);
    StringExpandPlaceholders(gStringVar4, gText_Oak_BoyOrGirl);
    AddTextPrinterForMessage_IgnoreTextColor(1);
    CopyWindowToVram(0, 3);
    gTasks[taskId].func = Task_NewGameOakSpeech_WaitToShowGenderMenu;
}

static void Task_NewGameOakSpeech_WaitToShowGenderMenu(u8 taskId)
{
    if (!RunTextPrintersAndIsPrinter0Active())
    {
        NewGameOakSpeech_ShowGenderMenu();
        gTasks[taskId].func = Task_NewGameOakSpeech_ChooseGender;
    }
}

static void Task_NewGameOakSpeech_ChooseGender(u8 taskId)
{
    int gender = NewGameOakSpeech_ProcessGenderMenuInput();

    switch (gender)
    {
        case MALE:
            PlaySE(SE_SELECT);
            gSaveBlock2Ptr->playerGender = gender;
            gTasks[taskId].func = Task_NewGameOakSpeech_StartPlayerFadeIn;
            break;
        case FEMALE:
            PlaySE(SE_SELECT);
            gSaveBlock2Ptr->playerGender = gender;
            gTasks[taskId].func = Task_NewGameOakSpeech_StartPlayerFadeIn;
            break;
    }
}

static void Task_NewGameOakSpeech_StartPlayerFadeIn(u8 taskId)
{
    ClearDialogWindowAndFrame(0, TRUE);
    NewGameOakSpeech_ClearGenderWindow(1, 1);
    LoadOakIntroBigSprite(gSaveBlock2Ptr->playerGender, 0);
    NewGameOakSpeech_StartFadeInTarget1OutTarget2(taskId, 1);
    gTasks[taskId].tTimer = 30;
    gTasks[taskId].func = Task_NewGameOakSpeech_WaitForPlayerFadeIn;
}

static void Task_NewGameOakSpeech_WaitForPlayerFadeIn(u8 taskId)
{
    if (gTasks[taskId].tIsDoneFadingSprites)
    {
        if (gTasks[taskId].tTimer)
        {
            gTasks[taskId].tTimer--;
        }
        else
        {
            gTasks[taskId].func = Task_NewGameOakSpeech_WhatsYourName;
        }
    }
}

static void Task_NewGameOakSpeech_WhatsYourName(u8 taskId)
{
    NewGameOakSpeech_ShowDialogueWindow(0, FALSE);
    FillWindowPixelBuffer(0, 0x11);
    StringExpandPlaceholders(gStringVar4, gText_Oak_WhatsYourName);
    AddTextPrinterForMessage_IgnoreTextColor(1);
    CopyWindowToVram(0, 3);
    gTasks[taskId].func = Task_NewGameOakSpeech_WaitForWhatsYourNameToPrint;
}

static void Task_NewGameOakSpeech_WaitForWhatsYourNameToPrint(u8 taskId)
{
    if (!RunTextPrintersAndIsPrinter0Active())
    {
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
        gTasks[taskId].func = Task_NewGameOakSpeech_StartNamingScreen;
    }
}

static void Task_NewGameOakSpeech_StartNamingScreen(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        FreeAllWindowBuffers();
        NewGameOakSpeech_SetDefaultPlayerName(Random() % 20);
        DestroyTask(taskId);
        DoNamingScreen(0, gSaveBlock2Ptr->playerName, gSaveBlock2Ptr->playerGender, 0, 0, CB2_NewGameOakSpeech_ReturnFromNamingScreen);
    }
}

static void Task_NewGameOakSpeech_SoItsPlayerName(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        NewGameOakSpeech_ShowDialogueWindow(0, 1);
        FillWindowPixelBuffer(0, 0x11);
        StringExpandPlaceholders(gStringVar4, gText_Oak_SoItsPlayer);
        AddTextPrinterForMessage_IgnoreTextColor(1);
        gTasks[taskId].tTimer = 30;
        gTasks[taskId].func = Task_NewGameOakSpeech_CreateNameYesNo;
    }
}

static void Task_NewGameOakSpeech_CreateNameYesNo(u8 taskId)
{
    if (!RunTextPrintersAndIsPrinter0Active())
    {
        if (gTasks[taskId].tTimer)
        {
            gTasks[taskId].tTimer--;
        }
        else
        {
            CreateYesNoMenuParameterized(1, 1, 0xF3, 0xD0, 2, 15);
            gTasks[taskId].func = Task_NewGameOakSpeech_ProcessNameYesNoMenu;
        }
    }
}

static void Task_NewGameOakSpeech_ProcessNameYesNoMenu(u8 taskId)
{
    switch (Menu_ProcessInputNoWrapClearOnChoose())
    {
        case 0:
            PlaySE(SE_SELECT);
            ClearDialogWindowAndFrame(0, TRUE);
            gTasks[taskId].func = Task_NewGameOakSpeech_SlidePlatformAway2;
            break;
        case -1:
        case 1:
            PlaySE(SE_SELECT);
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
            gTasks[taskId].func = Task_NewGameOakSpeech_StartNamingScreen;
    }
}

static void Task_NewGameOakSpeech_SlidePlatformAway2(u8 taskId)
{
    u8 i, spriteId;

    if (gTasks[taskId].tSlideOffset)
    {
        gTasks[taskId].tSlideOffset -= 2;
        
        for (i = 0; i < 3; i++)
        {
            spriteId = gTasks[taskId].data[i + 9];
            gSprites[spriteId].pos1.x = gTasks[taskId].tSlideOffset + ((i - 1) * 32) + 120;
        }
        
        ChangeBgX(2, 0x200, 1);
    }
    else
    {
        gTasks[taskId].tTimer = 30;
        gTasks[taskId].func = Task_NewGameOakSpeech_AreYouReady;
    }
}

static void Task_NewGameOakSpeech_AreYouReady(u8 taskId)
{
    u8 spriteId;

    if (gTasks[taskId].tTimer)
    {
        gTasks[taskId].tTimer--;
    }
    else
    {
        NewGameOakSpeech_ShowDialogueWindow(0, FALSE);
        StringExpandPlaceholders(gStringVar4, gText_Oak_AreYouReady);
        AddTextPrinterForMessage_IgnoreTextColor(1);
        CopyWindowToVram(0, 3);
        gTasks[taskId].tTimer = 30;
        gTasks[taskId].func = Task_NewGameOakSpeech_PrepareToShrinkPlayer;
    }
}

static void Task_NewGameOakSpeech_PrepareToShrinkPlayer(u8 taskId)
{
    if (!RunTextPrintersAndIsPrinter0Active())
    {
        if (gTasks[taskId].tTimer)
        {
            gTasks[taskId].tTimer--;
        }
        else
        {
            FadeOutBGM(4);
            gTasks[taskId].func = Task_NewGameOakSpeech_ShrinkPlayer;
        }
    }
}

static void Task_NewGameOakSpeech_ShrinkPlayer(u8 taskId)
{
    gTasks[taskId].data[3] = 0;
    Task_NewGameOakSpeech_FadeEverythingButPlayerAndTextbox(taskId);
    Task_NewGameOakSpeech_StartFadePlayerToWhite(taskId);
    Task_NewGameOakSpeech_StartShrinkPlayer(taskId);
}

static void Task_NewGameOakSpeech_StartShrinkPlayer(u8 taskId)
{
    SetBgAttribute(2, 6, 1);
    gTasks[taskId].tTimer = 0;
    gTasks[taskId].data[1] = 0;
    gTasks[taskId].data[2] = 0x100;
    gTasks[taskId].data[15] = 0;
    gTasks[taskId].func = Task_NewGameOakSpeech_ShrinkBG2;
}

static void Task_NewGameOakSpeech_ShrinkBG2(u8 taskId)
{
    u16 isBetweenSteps;
    u16 oldScale;

    gTasks[taskId].data[3]++;
    
    isBetweenSteps = (u16)gTasks[taskId].data[3] % 20;

    if (!isBetweenSteps)
    {
        if (gTasks[taskId].data[3] == 40)
        {
            PlaySE(SE_TK_WARPIN);
        }

        oldScale = gTasks[taskId].data[2];
        gTasks[taskId].data[2] -= 0x20;

        SetBgAffine(2, 120 * 0x100, 84 * 0x100, 120, 84, sub_8151624(oldScale - 8), sub_8151624(gTasks[taskId].data[2] - 16), 0);

        if (gTasks[taskId].data[2] <= 0x60)
        {
            gTasks[taskId].data[15] = 1;
            gTasks[taskId].tTimer = 36;
            gTasks[taskId].func = Task_NewGameOakSpeech_FadePlayerToBlack;
        }
    }
}

static void Task_NewGameOakSpeech_FadeEverythingButPlayerAndTextbox(u8 taskId)
{
    u8 taskId2 = CreateTask(Task_NewGameOakSpeech_WaitToFadeTextbox, 1);

    gTasks[taskId2].data[0] = 0;
    gTasks[taskId2].data[1] = 0;
    gTasks[taskId2].data[2] = 0;
    gTasks[taskId2].data[15] = 0;

    BeginNormalPaletteFade(0xFFFF0FCF, 4, 0, 16, RGB_BLACK);
}

static void Task_NewGameOakSpeech_WaitToFadeTextbox(u8 taskId)
{
    u8 i;
    s16 *data = gTasks[taskId].data;


    if (!gPaletteFade.active)
    {
        if (data[1])
        {
            for (i = 0; i < 3; i++)
            {
                DestroySprite(&gSprites[data[i + 9]]);
            }

            FreeSpriteTilesByTag(0x1000);
            FreeSpritePaletteByTag(0x1000);

            DestroyTask(taskId);
        }
        else
        {
            data[1]++;
            BeginNormalPaletteFade(0x0000F000, 0, 0, 16, RGB_BLACK);
        }
    }
}

static void Task_NewGameOakSpeech_StartFadePlayerToWhite(u8 taskId)
{
    u8 taskId2 = CreateTask(Task_NewGameOakSpeech_FadePlayerToWhite, 2);

    gTasks[taskId2].data[0] = 8;
    gTasks[taskId2].data[1] = 0;
    gTasks[taskId2].data[2] = 8;
    gTasks[taskId2].data[14] = 0;
    gTasks[taskId2].data[15] = 0;
}

static void Task_NewGameOakSpeech_FadePlayerToWhite(u8 taskId)
{
    u8 i;
    s16 *data = gTasks[taskId].data;

    if (data[0])
    {
        data[0]--;
    }
    else
    {
        if (data[1] <= 0 && data[2] != 0)
        {
            data[2]--;
        }

        BlendPalette(0x40, 0x20, data[14], RGB_WHITE);

        data[14]++;
        data[1]--;
        data[0] = data[2];

        if (data[14] > 14)
        {
            for (i = 0; i < 32; i++)
            {
                gPlttBufferFaded[i + 0x40] = RGB_WHITE;
                gPlttBufferUnfaded[i + 0x40] = RGB_WHITE;
            }
            DestroyTask(taskId);
        }
    }
}

static void Task_NewGameOakSpeech_FadePlayerToBlack(u8 taskId)
{
    if (gTasks[taskId].tTimer)
    {
        gTasks[taskId].tTimer--;
    }
    else
    {
        BeginNormalPaletteFade(0x00000030, 2, 0, 16, RGB_BLACK);
        gTasks[taskId].func = Task_NewGameOakSpeech_Cleanup;
    }
}

static void Task_NewGameOakSpeech_Cleanup(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        FreeAllWindowBuffers();
        ResetAllPicSprites();
        FREE_AND_SET_NULL(sOakIntro_BgBuffer);
        SetMainCallback2(CB2_NewGame);
        DestroyTask(taskId);
    }
}

static void CB2_NewGameOakSpeech_ReturnFromNamingScreen(void)
{
    u8 i;
    u8 taskId;
    u8 spriteId;
    u16 savedIme;

    ResetBgsAndClearDma3BusyFlags(0);
    SetGpuReg(REG_OFFSET_DISPCNT, 0);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
    InitBgsFromTemplates(1, sOakBgTemplates, ARRAY_COUNT(sOakBgTemplates));
    SetBgTilemapBuffer(2, sOakIntro_BgBuffer);
    SetVBlankCallback(NULL);
    SetGpuReg(REG_OFFSET_BG2CNT, 0);
    SetGpuReg(REG_OFFSET_BG1CNT, 0);
    SetGpuReg(REG_OFFSET_BG0CNT, 0);
    SetGpuReg(REG_OFFSET_BG2HOFS, 0);
    SetGpuReg(REG_OFFSET_BG2VOFS, 0);
    SetGpuReg(REG_OFFSET_BG1HOFS, 0);
    SetGpuReg(REG_OFFSET_BG1VOFS, 0);
    SetGpuReg(REG_OFFSET_BG0HOFS, 0);
    SetGpuReg(REG_OFFSET_BG0VOFS, 0);
    DmaFill16(3, 0, VRAM, VRAM_SIZE);
    DmaFill32(3, 0, OAM, OAM_SIZE);
    DmaFill16(3, 0, PLTT, PLTT_SIZE);
    ResetPaletteFade();
    LZ77UnCompVram(sOakSpeechBgGfx, (u8*)VRAM);
    LZ77UnCompVram(sOakSpeechBgMap, (u8*)(BG_SCREEN_ADDR(30)));
    LoadPalette(sOakSpeechBgPal, 0, 64);
    ResetTasks();
    taskId = CreateTask(Task_NewGameOakSpeech_ReturnFromNamingScreenShowTextbox, 0);
    gTasks[taskId].tTimer = 5;
    gTasks[taskId].tSlideOffset = 60;
    ScanlineEffect_Stop();
    ResetSpriteData();
    FreeAllSpritePalettes();
    ResetAllPicSprites();
    AddOakSpeechObjects(taskId);
    LoadOakIntroBigSprite(gSaveBlock2Ptr->playerGender, 0);

    for (i = 0; i < 3; i++)
    {
        spriteId = gTasks[taskId].data[i + 9];
        gSprites[spriteId].pos1.x = 148 + (i * 32);
    }
    
    ChangeBgX(2, 60 * -0x100, 0);
    BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, RGB_BLACK);
    SetGpuReg(REG_OFFSET_WIN0H, 0);
    SetGpuReg(REG_OFFSET_WIN0V, 0);
    SetGpuReg(REG_OFFSET_WININ, 0);
    SetGpuReg(REG_OFFSET_WINOUT, 0);
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    SetGpuReg(REG_OFFSET_BLDALPHA, 0);
    SetGpuReg(REG_OFFSET_BLDY, 0);
    ShowBg(0);
    ShowBg(1);
    ShowBg(2);
    savedIme = REG_IME;
    REG_IME = 0;
    REG_IE |= 1;
    REG_IME = savedIme;
    SetVBlankCallback(VBlankCB_MainMenu);
    SetMainCallback2(CB2_MainMenu);
    InitWindows(gNewGameBirchSpeechTextWindows);
    LoadMainMenuWindowFrameTiles(0, 0xF3);
    LoadMessageBoxGfx(0, 0xFC, 0xF0);
    PutWindowTilemap(0);
    CopyWindowToVram(0, 3);
}

static void SpriteCB_Null(struct Sprite *sprite)
{
}

static void SpriteCB_MovePlayerDownWhileShrinking(struct Sprite *sprite)
{
    u32 y;

    y = (sprite->pos1.y << 16) + sprite->data[0] + 0xC000;
    sprite->pos1.y = y >> 16;
    sprite->data[0] = y;
}

static u8 NewGameOakSpeech_CreateLotadSprite(u8 a, u8 b)
{
    return CreatePicSprite2(SPECIES_WOOPER, 8, 0, 1, a, b, 14, -1);
}

void AddOakSpeechObjects(u8 taskId)
{
    u8 i;
    u8 wooperSprite;
    u8 spriteId;

    wooperSprite = NewGameOakSpeech_CreateLotadSprite(96, 96);
    gSprites[wooperSprite].callback = SpriteCB_Null;
    gSprites[wooperSprite].oam.priority = 0;
    gSprites[wooperSprite].invisible = TRUE;
    gTasks[taskId].tWooperSpriteId = wooperSprite;

    LoadCompressedSpriteSheet(&sCompressedSpriteSheet_OakPlatform);
    LoadSpritePalette(&sSpritePalette_OakPlatform);

    for (i = 0; i < 3; i++)
    {
        spriteId = CreateSprite(&sSpriteTemplate_OakPlatform, 88 + (i * 32), 112, 1);
        gTasks[taskId].data[i + 9] = spriteId;
        StartSpriteAnim(&gSprites[spriteId], i);
    }
}

#undef tPlayerSpriteId
#undef tSlideOffset
#undef tPlayerGender
#undef tWooperSpriteId
#undef tLotadSpriteId
#undef tBrendanSpriteId
#undef tMaySpriteId

#define tMainTask data[0]
#define tAlphaCoeff1 data[1]
#define tAlphaCoeff2 data[2]
#define tDelay data[3]
#define tDelayTimer data[4]

static void Task_NewGameOakSpeech_FadeOutTarget1InTarget2(u8 taskId)
{
    u8 i;
    int alphaCoeff2;

    if (gTasks[taskId].tAlphaCoeff1 == 0)
    {
        gTasks[gTasks[taskId].tMainTask].tIsDoneFadingSprites = TRUE;
        DestroyTask(taskId);
    }
    else if (gTasks[taskId].tDelayTimer)
    {
        gTasks[taskId].tDelayTimer--;
    }
    else
    {
        gTasks[taskId].tDelayTimer = gTasks[taskId].tDelay;
        gTasks[taskId].tAlphaCoeff1--;
        gTasks[taskId].tAlphaCoeff2++;
        
        if (gTasks[taskId].tAlphaCoeff1 == 8)
        {
            s16 *sprites = &gTasks[gTasks[taskId].tMainTask].data[9];
            for (i = 0; i < 3; i++)
            {
                gSprites[sprites[i]].invisible = TRUE;
            }
        }

        alphaCoeff2 = gTasks[taskId].tAlphaCoeff2 << 8;
        SetGpuReg(REG_OFFSET_BLDALPHA, gTasks[taskId].tAlphaCoeff1 + alphaCoeff2);
    }
}

static void NewGameOakSpeech_StartFadeOutTarget1InTarget2(u8 taskId, u8 delay)
{
    u8 taskId2;

    SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT2_BG1 | BLDCNT_TGT2_OBJ | BLDCNT_EFFECT_BLEND | BLDCNT_TGT1_BG2);
    SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(16, 0));
    SetGpuReg(REG_OFFSET_BLDY, 0);
    gTasks[taskId].tIsDoneFadingSprites = 0;
    taskId2 = CreateTask(Task_NewGameOakSpeech_FadeOutTarget1InTarget2, 0);
    gTasks[taskId2].tMainTask = taskId;
    gTasks[taskId2].tAlphaCoeff1 = 16;
    gTasks[taskId2].tAlphaCoeff2 = 0;
    gTasks[taskId2].tDelay = delay;
    gTasks[taskId2].tDelayTimer = delay;
}

static void Task_NewGameOakSpeech_FadeInTarget1OutTarget2(u8 taskId)
{
    u8 i;
    int alphaCoeff2;

    if (gTasks[taskId].tAlphaCoeff1 == 16)
    {
        gTasks[gTasks[taskId].tMainTask].tIsDoneFadingSprites = TRUE;
        DestroyTask(taskId);
    }
    else if (gTasks[taskId].tDelayTimer)
    {
        gTasks[taskId].tDelayTimer--;
    }
    else
    {
        gTasks[taskId].tDelayTimer = gTasks[taskId].tDelay;
        gTasks[taskId].tAlphaCoeff1++;
        gTasks[taskId].tAlphaCoeff2--;

        if (gTasks[taskId].tAlphaCoeff1 == 8)
        {
            s16 *sprites = &gTasks[gTasks[taskId].tMainTask].data[9];
            for (i = 0; i < 3; i++)
            {
                gSprites[sprites[i]].invisible = FALSE;
            }
        }

        alphaCoeff2 = gTasks[taskId].tAlphaCoeff2 << 8;
        SetGpuReg(REG_OFFSET_BLDALPHA, gTasks[taskId].tAlphaCoeff1 + alphaCoeff2);
    }
}

static void NewGameOakSpeech_StartFadeInTarget1OutTarget2(u8 taskId, u8 delay)
{
    u8 taskId2;

    SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT2_BG1 | BLDCNT_TGT2_OBJ | BLDCNT_EFFECT_BLEND | BLDCNT_TGT1_BG2);
    SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(0, 16));
    SetGpuReg(REG_OFFSET_BLDY, 0);
    gTasks[taskId].tIsDoneFadingSprites = 0;
    taskId2 = CreateTask(Task_NewGameOakSpeech_FadeInTarget1OutTarget2, 0);
    gTasks[taskId2].tMainTask = taskId;
    gTasks[taskId2].tAlphaCoeff1 = 0;
    gTasks[taskId2].tAlphaCoeff2 = 16;
    gTasks[taskId2].tDelay = delay;
    gTasks[taskId2].tDelayTimer = delay;
}

#undef tMainTask
#undef tAlphaCoeff1
#undef tAlphaCoeff2
#undef tDelay
#undef tDelayTimer

static void NewGameOakSpeech_ShowGenderMenu(void)
{
    DrawMainMenuWindowBorder(&gNewGameBirchSpeechTextWindows[1], 0xF3);
    FillWindowPixelBuffer(1, PIXEL_FILL(1));
    PrintMenuTable(1, 2, sMenuActions_Gender);
    InitMenuInUpperLeftCornerPlaySoundWhenAPressed(1, 2, 0);
    PutWindowTilemap(1);
    CopyWindowToVram(1, 3);
}

static s8 NewGameOakSpeech_ProcessGenderMenuInput(void)
{
    return Menu_ProcessInputNoWrap();
}

static void NewGameOakSpeech_SetDefaultPlayerName(u8 nameId)
{
    const u8* name;
    u8 i;

    if (gSaveBlock2Ptr->playerGender == MALE)
        name = gMalePresetNames[nameId];
    else
        name = gFemalePresetNames[nameId];
    for (i = 0; i < 7; i++)
        gSaveBlock2Ptr->playerName[i] = name[i];
    gSaveBlock2Ptr->playerName[7] = 0xFF;
}

static void CreateMainMenuErrorWindow(const u8* str)
{
    FillWindowPixelBuffer(7, PIXEL_FILL(1));
    AddTextPrinterParameterized(7, 1, str, 0, 1, 1, 0);
    PutWindowTilemap(7);
    CopyWindowToVram(7, 2);
    DrawMainMenuWindowBorder(&sWindowTemplates_MainMenu[7], MAIN_MENU_BORDER_TILE);
    SetGpuReg(REG_OFFSET_WIN0H, WIN_RANGE(10, 230));
    SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE(114, 158));
}

static void MainMenu_FormatSavegameText(void)
{
    MainMenu_FormatSavegamePlayer();
    MainMenu_FormatSavegamePokedex();
    MainMenu_FormatSavegameTime();
    MainMenu_FormatSavegameBadges();
}

static void MainMenu_FormatSavegamePlayer(void)
{
    StringExpandPlaceholders(gStringVar4, gText_ContinueMenuPlayer);
    AddTextPrinterParameterized3(2, 1, 2, 18, sTextColor_PlayerGenderColor, -1, gStringVar4);
    AddTextPrinterParameterized3(2, 1, 62, 18, sTextColor_PlayerGenderColor, -1, gSaveBlock2Ptr->playerName);
}

static void MainMenu_FormatSavegameTime(void)
{
    u8 str[0x20];
    u8* ptr;

    StringExpandPlaceholders(gStringVar4, gText_ContinueMenuTime);
    AddTextPrinterParameterized3(2, 1, 2, 34, sTextColor_PlayerGenderColor, -1, gStringVar4);
    ptr = ConvertIntToDecimalStringN(str, gSaveBlock2Ptr->playTimeHours, 0, 3);
    *ptr = CHAR_COLON;
    ConvertIntToDecimalStringN(ptr + 1, gSaveBlock2Ptr->playTimeMinutes, 2, 2);
    AddTextPrinterParameterized3(2, 1, 62, 34, sTextColor_PlayerGenderColor, -1, str);
}

static void MainMenu_FormatSavegamePokedex(void)
{
    u8 str[0x20];
    u16 dexCount;

    if (FlagGet(FLAG_SYS_POKEDEX_GET) == TRUE)
    {
        if (IsNationalPokedexEnabled())
            dexCount = GetNationalPokedexCount(1);
        else
            dexCount = GetHoennPokedexCount(1);
        StringExpandPlaceholders(gStringVar4, gText_ContinueMenuPokedex);
        AddTextPrinterParameterized3(2, 1, 2, 50, sTextColor_PlayerGenderColor, -1, gStringVar4);
        ConvertIntToDecimalStringN(str, dexCount, 0, 3);
        AddTextPrinterParameterized3(2, 1, 62, 50, sTextColor_PlayerGenderColor, -1, str);
    }
}

static void MainMenu_FormatSavegameBadges(void)
{
    u8 str[0x20];
    u8 badgeCount = 0;
    u32 i;

    for (i = FLAG_BADGE01_GET; i <= FLAG_BADGE08_GET; i++)
    {
        if (FlagGet(i))
            badgeCount++;
    }
    StringExpandPlaceholders(gStringVar4, gText_ContinueMenuBadges);
    AddTextPrinterParameterized3(2, 1, 2, 66, sTextColor_PlayerGenderColor, -1, gStringVar4);
    ConvertIntToDecimalStringN(str, badgeCount, 2, 1);
    AddTextPrinterParameterized3(2, 1, 62, 66, sTextColor_PlayerGenderColor, -1, str);
}

static void LoadMainMenuWindowFrameTiles(u8 bgId, u16 tileOffset)
{
    LoadBgTiles(bgId, GetWindowFrameTilesPal(gSaveBlock2Ptr->optionsWindowFrameType)->tiles, 0x120, tileOffset);
    LoadPalette(GetWindowFrameTilesPal(gSaveBlock2Ptr->optionsWindowFrameType)->pal, 32, 32);
}

static void DrawMainMenuWindowBorder(const struct WindowTemplate *template, u16 baseTileNum)
{
    u16 r9 = 1 + baseTileNum;
    u16 r10 = 2 + baseTileNum;
    u16 sp18 = 3 + baseTileNum;
    u16 spC = 5 + baseTileNum;
    u16 sp10 = 6 + baseTileNum;
    u16 sp14 = 7 + baseTileNum;
    u16 r6 = 8 + baseTileNum;

    FillBgTilemapBufferRect(template->bg, baseTileNum, template->tilemapLeft - 1, template->tilemapTop - 1, 1, 1, 2);
    FillBgTilemapBufferRect(template->bg, r9, template->tilemapLeft, template->tilemapTop - 1, template->width, 1, 2);
    FillBgTilemapBufferRect(template->bg, r10, template->tilemapLeft + template->width, template->tilemapTop - 1, 1, 1, 2);
    FillBgTilemapBufferRect(template->bg, sp18, template->tilemapLeft - 1, template->tilemapTop, 1, template->height, 2);
    FillBgTilemapBufferRect(template->bg, spC, template->tilemapLeft + template->width, template->tilemapTop, 1, template->height, 2);
    FillBgTilemapBufferRect(template->bg, sp10, template->tilemapLeft - 1, template->tilemapTop + template->height, 1, 1, 2);
    FillBgTilemapBufferRect(template->bg, sp14, template->tilemapLeft, template->tilemapTop + template->height, template->width, 1, 2);
    FillBgTilemapBufferRect(template->bg, r6, template->tilemapLeft + template->width, template->tilemapTop + template->height, 1, 1, 2);
    CopyBgTilemapBufferToVram(template->bg);
}

static void ClearMainMenuWindowTilemap(const struct WindowTemplate *template)
{
    FillBgTilemapBufferRect(template->bg, 0, template->tilemapLeft - 1, template->tilemapTop - 1, template->tilemapLeft + template->width + 1, template->tilemapTop + template->height + 1, 2);
    CopyBgTilemapBufferToVram(template->bg);
}

static void NewGameOakSpeech_ClearGenderWindowTilemap(u8 a, u8 b, u8 c, u8 d, u8 e, u8 unused)
{
    FillBgTilemapBufferRect(a, 0, b + 0xFF, c + 0xFF, d + 2, e + 2, 2);
}

static void NewGameOakSpeech_ClearGenderWindow(u8 windowId, u8 copyToVram)
{
    CallWindowFunction(windowId, NewGameOakSpeech_ClearGenderWindowTilemap);
    FillWindowPixelBuffer(windowId, PIXEL_FILL(1));
    ClearWindowTilemap(windowId);
    if (copyToVram == TRUE)
        CopyWindowToVram(windowId, 3);
}

void CreateYesNoMenuParameterized(u8 x, u8 y, u16 borderTileNum, u16 windowTileNum, u8 borderPalette, u8 windowPalette)
{
    struct WindowTemplate sp;

    sp = CreateWindowTemplate(0, x + 1, y + 1, 6, 4, windowPalette, windowTileNum);
    CreateYesNoMenu(&sp, borderTileNum, borderPalette, 0);
}

static void NewGameOakSpeech_ShowDialogueWindow(u8 windowId, u8 copyToVram)
{
    CallWindowFunction(windowId, NewGameOakSpeech_CreateDialogueWindowBorder);
    FillWindowPixelBuffer(windowId, PIXEL_FILL(1));
    PutWindowTilemap(windowId);
    if (copyToVram == TRUE)
        CopyWindowToVram(windowId, 3);
}

#define OAK_SPEECH_WINDOW_BASE_TILE_NUM 0xFC

static void NewGameOakSpeech_CreateDialogueWindowBorder(u8 bg, u8 tilemapLeft, u8 tilemapTop, u8 width, u8 height, u8 pal)
{
    FillBgTilemapBufferRect(bg,
                            OAK_SPEECH_WINDOW_BASE_TILE_NUM,
                            tilemapLeft - 2,
                            tilemapTop - 1,
                            1,
                            1,
                            pal);
    FillBgTilemapBufferRect(bg,
                            OAK_SPEECH_WINDOW_BASE_TILE_NUM + 1,
                            tilemapLeft - 1,
                            tilemapTop - 1,
                            1,
                            1,
                            pal);
    FillBgTilemapBufferRect(bg,
                            OAK_SPEECH_WINDOW_BASE_TILE_NUM + 2,
                            tilemapLeft,
                            tilemapTop - 1,
                            width,
                            1,
                            pal);
    FillBgTilemapBufferRect(bg,
                            OAK_SPEECH_WINDOW_BASE_TILE_NUM + 3,
                            tilemapLeft + width,
                            tilemapTop - 1,
                            1,
                            1,
                            pal);
    FillBgTilemapBufferRect(bg,
                            OAK_SPEECH_WINDOW_BASE_TILE_NUM + 4,
                            tilemapLeft + width + 1,
                            tilemapTop - 1,
                            1,
                            1,
                            pal);
    FillBgTilemapBufferRect(bg,
                            OAK_SPEECH_WINDOW_BASE_TILE_NUM + 5,
                            tilemapLeft - 2,
                            tilemapTop,
                            1,
                            1,
                            pal);
    FillBgTilemapBufferRect(bg,
                            OAK_SPEECH_WINDOW_BASE_TILE_NUM + 6,
                            tilemapLeft - 1,
                            tilemapTop,
                            1,
                            1,
                            pal);
    FillBgTilemapBufferRect(bg,
                            OAK_SPEECH_WINDOW_BASE_TILE_NUM + 8,
                            tilemapLeft + width,
                            tilemapTop,
                            1,
                            1,
                            pal);
    FillBgTilemapBufferRect(bg,
                            OAK_SPEECH_WINDOW_BASE_TILE_NUM + 9,
                            tilemapLeft + width + 1,
                            tilemapTop,
                            1,
                            1,
                            pal);
    FillBgTilemapBufferRect(bg,
                            OAK_SPEECH_WINDOW_BASE_TILE_NUM + 10,
                            tilemapLeft - 2,
                            tilemapTop + 1,
                            1,
                            1,
                            pal);
    FillBgTilemapBufferRect(bg,
                            OAK_SPEECH_WINDOW_BASE_TILE_NUM + 11,
                            tilemapLeft - 1,
                            tilemapTop + 1,
                            1,
                            1,
                            pal);
    FillBgTilemapBufferRect(bg,
                            OAK_SPEECH_WINDOW_BASE_TILE_NUM + 12,
                            tilemapLeft + width,
                            tilemapTop + 1,
                            1,
                            1,
                            pal);
    FillBgTilemapBufferRect(bg,
                            OAK_SPEECH_WINDOW_BASE_TILE_NUM + 13,
                            tilemapLeft + width + 1,
                            tilemapTop + 1,
                            1,
                            1,
                            pal);
    FillBgTilemapBufferRect(bg,
                            BG_TILE_V_FLIP(OAK_SPEECH_WINDOW_BASE_TILE_NUM + 10),
                            tilemapLeft - 2,
                            tilemapTop + 2,
                            1,
                            1,
                            pal);
    FillBgTilemapBufferRect(bg,
                            BG_TILE_V_FLIP(OAK_SPEECH_WINDOW_BASE_TILE_NUM + 11),
                            tilemapLeft - 1,
                            tilemapTop + 2,
                            1,
                            1,
                            pal);
    FillBgTilemapBufferRect(bg,
                            BG_TILE_V_FLIP(OAK_SPEECH_WINDOW_BASE_TILE_NUM + 12),
                            tilemapLeft + width,
                            tilemapTop + 2,
                            1,
                            1,
                            pal);
    FillBgTilemapBufferRect(bg,
                            BG_TILE_V_FLIP(OAK_SPEECH_WINDOW_BASE_TILE_NUM + 13),
                            tilemapLeft + width + 1,
                            tilemapTop + 2,
                            1,
                            1,
                            pal);
    FillBgTilemapBufferRect(bg,
                            BG_TILE_V_FLIP(OAK_SPEECH_WINDOW_BASE_TILE_NUM + 5),
                            tilemapLeft - 2,
                            tilemapTop + 3,
                            1,
                            1,
                            pal);
    FillBgTilemapBufferRect(bg,
                            BG_TILE_V_FLIP(OAK_SPEECH_WINDOW_BASE_TILE_NUM + 6),
                            tilemapLeft - 1,
                            tilemapTop + 3,
                            1,
                            1,
                            pal);
    FillBgTilemapBufferRect(bg,
                            BG_TILE_V_FLIP(OAK_SPEECH_WINDOW_BASE_TILE_NUM + 8),
                            tilemapLeft + width,
                            tilemapTop + 3,
                            1,
                            1,
                            pal);
    FillBgTilemapBufferRect(bg,
                            BG_TILE_V_FLIP(OAK_SPEECH_WINDOW_BASE_TILE_NUM + 9),
                            tilemapLeft + width + 1,
                            tilemapTop + 3,
                            1,
                            1,
                            pal);
    FillBgTilemapBufferRect(bg,
                            BG_TILE_V_FLIP(OAK_SPEECH_WINDOW_BASE_TILE_NUM),
                            tilemapLeft - 2,
                            tilemapTop + 4,
                            1,
                            1,
                            pal);
    FillBgTilemapBufferRect(bg,
                            BG_TILE_V_FLIP(OAK_SPEECH_WINDOW_BASE_TILE_NUM + 1),
                            tilemapLeft - 1,
                            tilemapTop + 4,
                            1,
                            1,
                            pal);
    FillBgTilemapBufferRect(bg,
                            BG_TILE_V_FLIP(OAK_SPEECH_WINDOW_BASE_TILE_NUM + 2),
                            tilemapLeft,
                            tilemapTop + 4,
                            width,
                            1,
                            pal);
    FillBgTilemapBufferRect(bg,
                            BG_TILE_V_FLIP(OAK_SPEECH_WINDOW_BASE_TILE_NUM + 3),
                            tilemapLeft + width,
                            tilemapTop + 4,
                            1,
                            1,
                            pal);
    FillBgTilemapBufferRect(bg,
                            BG_TILE_V_FLIP(OAK_SPEECH_WINDOW_BASE_TILE_NUM + 4),
                            tilemapLeft + width + 1,
                            tilemapTop + 4,
                            1,
                            1,
                            pal);
}

static void Task_NewGameOakSpeech_ReturnFromNamingScreenShowTextbox(u8 taskId)
{
    if (gTasks[taskId].tTimer-- <= 0)
    {
        gTasks[taskId].func = Task_NewGameOakSpeech_SoItsPlayerName;
    }
}

#undef tTimer
