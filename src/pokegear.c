#include "global.h"
#include "main.h"
#include "pokegear.h"
#include "malloc.h"
#include "battle_setup.h"
#include "bg.h"
#include "data.h"
#include "day_night.h"
#include "event_data.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "international_string_util.h"
#include "list_menu.h"
#include "m4a.h"
#include "match_call.h"
#include "menu.h"
#include "menu_helpers.h"
#include "overworld.h"
#include "palette.h"
#include "phone_contact.h"
#include "phone_script.h"
#include "radio.h"
#include "random.h"
#include "region_map.h"
#include "rtc.h"
#include "scanline_effect.h"
#include "script.h"
#include "sound.h"
#include "string_util.h"
#include "strings.h"
#include "text.h"
#include "text_window.h"
#include "window.h"
#include "constants/flags.h"
#include "constants/map_types.h"
#include "constants/region_map_sections.h"
#include "constants/songs.h"

#define WIN_DIALOG 0
#define WIN_HELP 1
#define WIN_TOP 2
#define WIN_BOTTOM 3
#define WIN_LIST 4

#define MENU_FRAME_BASE_TILE_NUM 532
#define MENU_FRAME_PALETTE_NUM 13

#define REGION_MAP_XOFF 2

#define CARD_SLIDE_SPEED 32
#define ICON_SLIDE_SPEED 2
#define CARD_SLIDE_RIGHT_X 208

#define PHONE_CARD_MAX_SHOWN_CONTACTS 5
#define PHONE_CARD_MAX_NAME_LENGTH 31

#define TAG_DIGITS       12345
#define TAG_ICONS        12346
#define TAG_PHONE_SIGNAL 12347

// Static RAM declarations

enum CardType {
    ClockCard,
    MapCard,
    PhoneCard,
    RadioCard,
    CardCount
};

static EWRAM_DATA struct {
    MainCallback callback;
    struct RegionMap *map;
    struct ListMenuItem *phoneContactItems;
    u8 *phoneContactNames;
    u8 *phoneContactIds;
    u8 phoneContactCount;
    u8 phoneCallActionWindowId;
    u16 phoneScrollOffset;
    u16 phoneSelectedItem;
    u8 currentCard;
    bool8 canSwitchCards;
    u8 fakeSeconds;
    u8 currentRadioStation;
    bool8 exiting;
    struct Time cachedTime;
} sPokegearStruct = {0};

void CB2_InitPokegear(void);
static void VBlankCB(void);
static void CB2_Pokegear(void);
static void Task_Pokegear1(u8 taskId);
static void Task_Pokegear1_1(u8 taskId);
static void Task_Pokegear2(u8 taskId);
static void Task_Pokegear3(u8 taskId);
static void Task_SwapCards(u8 taskId);
static void Task_ExitPokegear1(u8 taskId);
static void Task_ExitPokegear2(u8 taskId);
static void Task_ClockCard(u8 taskId);
static void Task_MapCard(u8 taskId);
static void Task_PhoneCard(u8 taskId);
static void Task_RadioCard(u8 taskId);
static void PhoneCard_ConfirmCall(u8 taskId);
static void LoadClockCard(void);
static void LoadMapCard(void);
static void LoadPhoneCard(void);
static void DisplayPhoneCardDefaultText(void);
static void LoadRadioCard(void);
static void LoadCard(enum CardType type);
static void LoadCardBgs(enum CardType type);
static void SpriteCB_ClockDigits(struct Sprite* sprite);
static void SpriteCB_RadioDigits(struct Sprite* sprite);
static void FreePokegearData(void);
static void UnloadClockCard(void);
static void UnloadMapCard(void);
static void UnloadPhoneCard(void);
static void UnloadRadioCard(void);
static void PhoneCard_ConfirmCallProcessInput(u8 taskId);
static void PhoneCard_ConfirmDeleteProcessInput(u8 taskId);
static void PhoneCard_AddScrollIndicators(u8 taskId);
static void PhoneCard_ReturnToMain(u8 taskId);
static void PhoneCard_PlaceCall(u8 taskId);
static void PhoneCard_DeleteEntry(u8 taskId);
static void UpdateRadioStation(u8 taskId, u8 frequency);
static void LoadCardSprites(u8 taskId);
static void SpriteCB_Icons(struct Sprite* sprite);
static void InitPhoneCardData(void);
static void FreePhoneCardData(void);
static void PhoneCard_ExecuteCall(u8 taskId);
static void ClearOrDrawTopBar(bool8 clear);
static void ShowHelpBar(const u8 *string);

// .rodata
static const u16 gBGPals[] = INCBIN_U16("graphics/pokegear/bg.gbapal");
static const u16 sMenuSpritesPalette[] = INCBIN_U16("graphics/pokegear/menu_sprites.gbapal");
static const u32 gMainTiles[] = INCBIN_U32("graphics/pokegear/main.4bpp.lz");
static const u8 sDigitTiles[] = INCBIN_U8("graphics/pokegear/digits.4bpp");
static const u8 sIconTiles[] = INCBIN_U8("graphics/pokegear/icons.4bpp");
static const u32 gClockCardTilemap[] = INCBIN_U32("graphics/pokegear/clock.bin.lz");
static const u32 gMapCardTilemap[] = INCBIN_U32("graphics/pokegear/map.bin.lz");
static const u32 gPhoneCardTilemap[] = INCBIN_U32("graphics/pokegear/phone.bin.lz");
static const u32 gRadioCardTilemap[] = INCBIN_U32("graphics/pokegear/radio.bin.lz");
static const u8 sPhoneSignalIconGfx[] = INCBIN_U8("graphics/pokegear/phone_signal.4bpp");
static const u16 sPhoneSignalIconPalette[] = INCBIN_U16("graphics/pokegear/phone_signal.gbapal");

static const struct BgTemplate sBgTemplates[] =
{
    {
        .bg = 0,
        .charBaseIndex = 2,
        .mapBaseIndex = 30,
        .screenSize = 1,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    },
    {
        .bg = 1,
        .charBaseIndex = 0,
        .mapBaseIndex = 28,
        .screenSize = 1,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0
    },
    {
        .bg = 2,
        .charBaseIndex = 1,
        .mapBaseIndex = 26,
        .screenSize = 1,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0
    },
    {
        .bg = 3,
        .charBaseIndex = 0,
        .mapBaseIndex = 25,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 3,
        .baseTile = 0
    },
};

static const struct WindowTemplate sWindowTemplates[] =
{
    { 0, 6, 15, 23, 4, 15, 0x0001 },
    { 0, 0, 0, 30, 2, 11, 0x005D },
    { 0, 10, 5, 14, 3, 15, 0x0099 },
    { 0, 10, 10, 14, 3, 15, 0x0099 },
    { 0, 8, 4, 17, 10, 15, 0x0099 },
    DUMMY_WIN_TEMPLATE
};

static const struct WindowTemplate sCallCancelWindowTemplate = {
    .bg = 0,
    .tilemapLeft = 23,
    .tilemapTop = 9,
    .width = 6,
    .height = 4,
    .paletteNum = 15,
    .baseBlock = 0x0163,
};

static const struct WindowTemplate sCallDeleteCancelWindowTemplate = {
    .bg = 0,
    .tilemapLeft = 23,
    .tilemapTop = 7,
    .width = 6,
    .height = 6,
    .paletteNum = 15,
    .baseBlock = 0x0163,
};

static const struct WindowTemplate sPhoneCallWindowTemplate =
{
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 15,
    .width = 28,
    .height = 4,
    .paletteNum = 15,
    .baseBlock = 0x14B
};

static const struct WindowTemplate sYesNoWindowTemplate = {
    .bg = 0,
    .tilemapLeft = 23,
    .tilemapTop = 9,
    .width = 6,
    .height = 4,
    .paletteNum = 15,
    .baseBlock = 0x0163,
};

static const struct ListMenuTemplate sPhoneCardListMenuTemplate =
{
    .items = NULL,
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
    .itemPrintFunc = NULL,
    .totalItems = 0,
    .maxShowed = PHONE_CARD_MAX_SHOWN_CONTACTS,
    .windowId = WIN_LIST,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 2,
    .fillValue = 0,
    .cursorShadowPal = 3,
    .lettersSpacing = 1,
    .itemVerticalPadding = 2,
    .scrollMultiple = LIST_NO_MULTIPLE_SCROLL,
    .fontId = 2,
    .cursorKind = 0
};

const struct SpriteSheet sSpriteSheet_DigitTiles =
{
    .data = sDigitTiles,
    .size = 2176,
    .tag = TAG_DIGITS,
};

const struct SpritePalette gSpritePalette_PokegearMenuSprites =
{
    .data = sMenuSpritesPalette,
    .tag = TAG_ICONS
};

static const union AnimCmd sSpriteAnim_Digit0[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_Digit1[] =
{
    ANIMCMD_FRAME(4, 5),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_Digit2[] =
{
    ANIMCMD_FRAME(8, 5),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_Digit3[] =
{
    ANIMCMD_FRAME(12, 5),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_Digit4[] =
{
    ANIMCMD_FRAME(16, 5),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_Digit5[] =
{
    ANIMCMD_FRAME(20, 5),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_Digit6[] =
{
    ANIMCMD_FRAME(24, 5),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_Digit7[] =
{
    ANIMCMD_FRAME(28, 5),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_Digit8[] =
{
    ANIMCMD_FRAME(32, 5),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_Digit9[] =
{
    ANIMCMD_FRAME(36, 5),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_DigitOff[] =
{
    ANIMCMD_FRAME(40, 5),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_ColonOff[] =
{
    ANIMCMD_FRAME(44, 5),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_ColonOn[] =
{
    ANIMCMD_FRAME(48, 5),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_AM[] =
{
    ANIMCMD_FRAME(52, 5),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_PM[] =
{
    ANIMCMD_FRAME(56, 5),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_AMPMOff[] =
{
    ANIMCMD_FRAME(60, 5),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_Point[] =
{
    ANIMCMD_FRAME(64, 5),
    ANIMCMD_END
};

static const union AnimCmd *const sSpriteAnimTable_Digits[] =
{
    sSpriteAnim_Digit0,
    sSpriteAnim_Digit1,
    sSpriteAnim_Digit2,
    sSpriteAnim_Digit3,
    sSpriteAnim_Digit4,
    sSpriteAnim_Digit5,
    sSpriteAnim_Digit6,
    sSpriteAnim_Digit7,
    sSpriteAnim_Digit8,
    sSpriteAnim_Digit9,
    sSpriteAnim_DigitOff,
    sSpriteAnim_ColonOff,
    sSpriteAnim_ColonOn,
    sSpriteAnim_AM,
    sSpriteAnim_PM,
    sSpriteAnim_AMPMOff,
    sSpriteAnim_Point,
};

static const struct OamData sOamData_Digits =
{
    .y = 0,
    .affineMode = 0,
    .objMode = 0,
    .mosaic = 0,
    .bpp = 0,
    .shape = 0,
    .x = 0,
    .matrixNum = 0,
    .size = 1,
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0,
};

const struct SpriteTemplate sSpriteTemplate_Digits = {
    .tileTag = TAG_DIGITS,
    .paletteTag = TAG_ICONS,
    .oam = &sOamData_Digits,
    .anims = sSpriteAnimTable_Digits,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpriteSheet sSpriteSheet_IconTiles =
{
    .data = sIconTiles,
    .size = 0xE00,
    .tag = TAG_ICONS,
};

static const union AnimCmd sSpriteAnim_IconClock[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_IconMapJohto[] =
{
    ANIMCMD_FRAME(16, 5),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_IconMapKanto[] =
{
    ANIMCMD_FRAME(32, 5),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_IconMapSevii1[] =
{
    ANIMCMD_FRAME(48, 5),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_IconMapSevii2[] =
{
    ANIMCMD_FRAME(64, 5),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_IconMapSevii3[] =
{
    ANIMCMD_FRAME(80, 5),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_IconPhone[] =
{
    ANIMCMD_FRAME(96, 5),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_IconRadio[] =
{
    ANIMCMD_FRAME(112, 5),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_IconWrench[] =
{
    ANIMCMD_FRAME(128, 5),
    ANIMCMD_END
};

static const union AnimCmd *const sSpriteAnimTable_Icons[] =
{
    sSpriteAnim_IconClock,
    sSpriteAnim_IconMapJohto,
    sSpriteAnim_IconMapKanto,
    sSpriteAnim_IconMapSevii1,
    sSpriteAnim_IconMapSevii2,
    sSpriteAnim_IconMapSevii3,
    sSpriteAnim_IconPhone,
    sSpriteAnim_IconRadio,
    sSpriteAnim_IconWrench,
};

static const struct OamData sOamData_Icons =
{
    .size = 2,
    .priority = 1
};

const struct SpriteTemplate sSpriteTemplate_Icons = {
    .tileTag = TAG_ICONS,
    .paletteTag = TAG_ICONS,
    .oam = &sOamData_Icons,
    .anims = sSpriteAnimTable_Icons,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_Icons
};

static const struct SpriteSheet sSpriteSheet_PhoneSignal = {
    .data = sPhoneSignalIconGfx,
    .size = 0x200,
    .tag = TAG_PHONE_SIGNAL,
};

static const struct SpritePalette sSpritePalette_PhoneSignal =
{
    .data = sPhoneSignalIconPalette,
    .tag = TAG_PHONE_SIGNAL
};

static const union AnimCmd sSpriteAnim_Signal0[] = {
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_Signal1[] = {
    ANIMCMD_FRAME(4, 5),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_Signal2[] = {
    ANIMCMD_FRAME(8, 5),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_Signal3[] = {
    ANIMCMD_FRAME(12, 5),
    ANIMCMD_END
};

static const union AnimCmd *const sSpriteAnimTable_PhoneSignal[] =
{
    sSpriteAnim_Signal0,
    sSpriteAnim_Signal1,
    sSpriteAnim_Signal2,
    sSpriteAnim_Signal3
};

static const struct OamData sOamData_PhoneSignal = {
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = 0,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(16x16),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(16x16),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0,
};

static const struct SpriteTemplate sSpriteTemplate_PhoneSignal = {
    .tileTag = TAG_PHONE_SIGNAL,
    .paletteTag = TAG_PHONE_SIGNAL,
    .oam = &sOamData_PhoneSignal,
    .anims = sSpriteAnimTable_PhoneSignal,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

// .text

const u8 sTextColor[3] = {
    0x00, 0x02, 0x03
};

void CB2_InitPokegear(void)
{
    u8 newTask;

    ResetTasks();
    SetVBlankCallback(NULL);
    SetGpuReg(REG_OFFSET_DISPCNT, 0);
    SetGpuReg(REG_OFFSET_BG3CNT, 0);
    SetGpuReg(REG_OFFSET_BG2CNT, 0);
    SetGpuReg(REG_OFFSET_BG1CNT, 0);
    SetGpuReg(REG_OFFSET_BG0CNT, 0);
    SetGpuReg(REG_OFFSET_BG0HOFS, 0);
    SetGpuReg(REG_OFFSET_BG0VOFS, 0);
    SetGpuReg(REG_OFFSET_BG1HOFS, 0);
    SetGpuReg(REG_OFFSET_BG1VOFS, 0);
    SetGpuReg(REG_OFFSET_BG2HOFS, 0);
    SetGpuReg(REG_OFFSET_BG2VOFS, 0);
    SetGpuReg(REG_OFFSET_BG3HOFS, 0);
    SetGpuReg(REG_OFFSET_BG3VOFS, 0);
    DmaFillLarge16(3, 0, (void *)VRAM, VRAM_SIZE, 0x1000);
    DmaClear32(3, (void *)OAM, OAM_SIZE);
    DmaClear16(3, (void *)PLTT, PLTT_SIZE);
    LZ77UnCompVram(gMainTiles, (void *)(VRAM + 0x0000));
    LZ77UnCompVram(gPokegear_GridMap, (void *)(VRAM + 0xC800));
    LoadPalette(gBGPals, 0, sizeof(gBGPals));
    LoadPalette(GetTextWindowPalette(2), 0xB0, 0x20);
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, sBgTemplates, ARRAY_COUNT(sBgTemplates));
    InitWindows(sWindowTemplates);
    DeactivateAllTextPrinters();
    LoadUserWindowBorderGfx(0, MENU_FRAME_BASE_TILE_NUM, MENU_FRAME_PALETTE_NUM * 0x10);
    ClearScheduledBgCopiesToVram();
    ScanlineEffect_Stop();
    ResetSpriteData();
    ResetPaletteFade();
    FreeAllSpritePalettes();
    newTask = CreateTask(Task_Pokegear1, 0);
    BeginNormalPaletteFade(0xFFFFFFFF, 0, 0x10, 0, 0);
    EnableInterrupts(INTR_FLAG_VBLANK);
    SetVBlankCallback(VBlankCB);
    SetMainCallback2(CB2_Pokegear);

    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    SetGpuReg(REG_OFFSET_BLDALPHA, 0);
    SetGpuReg(REG_OFFSET_BLDY, 0);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_1D_MAP | DISPCNT_OBJ_ON);

    gTasks[newTask].data[0] = 0;
    LoadCardSprites(newTask);
    ClearOrDrawTopBar(FALSE);
    ShowHelpBar(gText_ClockCardHelp);
    ScheduleBgCopyTilemapToVram(0);
    LoadCardBgs(ClockCard);

    SetGpuReg(REG_OFFSET_BG1HOFS, 512 - CARD_SLIDE_RIGHT_X);

    ShowBg(0);
    ShowBg(1);
    ShowBg(3);

    PlaySE(SE_POKENAV_ON);
    sPokegearStruct.exiting = FALSE;
}

static void VBlankCB(void)
{
    ProcessSpriteCopyRequests();
    LoadOam();
    TransferPlttBuffer();
}

static void CB2_Pokegear(void)
{
    PhoneScriptContext_RunScript();
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    RunTextPrinters();
    DoScheduledBgTilemapCopiesToVram();
    UpdatePaletteFade();
}

static void LoadCard(enum CardType cardId)
{
    switch (cardId)
    {
        case ClockCard:
            LoadClockCard();
            break;
        case MapCard:
            LoadMapCard();
            break;
        case PhoneCard:
            LoadPhoneCard();
            break;
        case RadioCard:
            LoadRadioCard();
            break;
    }
}

static void UnloadCard(enum CardType cardId)
{
    switch (cardId)
    {
        case ClockCard:
            UnloadClockCard();
            break;
        case MapCard:
            UnloadMapCard();
            break;
        case PhoneCard:
            UnloadPhoneCard();
            break;
        case RadioCard:
            UnloadRadioCard();
            break;
    }
}

static void FreePokegearData(void)
{
    FREE_AND_SET_NULL(sPokegearStruct.map);
    FREE_AND_SET_NULL(sPokegearStruct.phoneContactNames);
    FREE_AND_SET_NULL(sPokegearStruct.phoneContactItems);
    FREE_AND_SET_NULL(sPokegearStruct.phoneContactIds);
}

#define tState data[0]
#define tCounter data[1]

#define tState data[0]
#define tNewCard data[1]
#define tCurrentPos data[2]
#define tIconSprites(n) data[3 + n]

static void Task_Pokegear1(u8 taskId)
{
    if (gTasks[taskId].data[0]++ > 10)
    {
        sPokegearStruct.canSwitchCards = FALSE;
        sPokegearStruct.fakeSeconds = Random() & 0xFF; // don't always start fully on
        sPokegearStruct.cachedTime = gLocalTime; // initialize cached time
        InitPhoneCardData();
        gTasks[taskId].tCurrentPos = CARD_SLIDE_RIGHT_X;
        gTasks[taskId].func = Task_Pokegear1_1;
    }
}

static void Task_Pokegear1_1(u8 taskId)
{
    u8 i;
    s16 *data = gTasks[taskId].data;
    tCurrentPos -= CARD_SLIDE_SPEED;

    if (tCurrentPos > 0)
    {
        SetGpuReg(REG_OFFSET_BG1HOFS, 512 - tCurrentPos);
    }
    else
    {
        SetGpuReg(REG_OFFSET_BG1HOFS, 0);
        LoadCard(ClockCard);
        gTasks[taskId].func = Task_Pokegear2;
    }
}

static void Task_Pokegear2(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        sPokegearStruct.callback = NULL;
        sPokegearStruct.currentCard = ClockCard;
        sPokegearStruct.canSwitchCards = TRUE;
        gTasks[taskId].func = Task_Pokegear3;
    }
}

static void LoadCardSprites(u8 taskId)
{
    u8 i, spriteId;

    LoadSpriteSheet(&sSpriteSheet_IconTiles);
    LoadSpritePalette(&gSpritePalette_PokegearMenuSprites);

    for (i = 0; i < CardCount; i++)
    {
        u8 anim;

        spriteId = CreateSprite(&sSpriteTemplate_Icons, -24, i * 32 + 32, 0);
        gTasks[taskId].tIconSprites(i) = spriteId;
        gSprites[spriteId].tState = 0;
        switch (i)
        {
            case ClockCard:
                anim = 0;
                gSprites[spriteId].x += 8;
                break;
            case MapCard:
                if (!FlagGet(FLAG_SYS_HAS_MAP_CARD))
                    gSprites[spriteId].invisible = TRUE;
                anim = GetCurrentRegion() + 1;
                break;
            case PhoneCard:
                anim = 4;
                break;
            case RadioCard:
                if (!FlagGet(FLAG_SYS_HAS_RADIO_CARD))
                    gSprites[spriteId].invisible = TRUE;
                anim = 5;
                break;
        }
        StartSpriteAnim(&gSprites[spriteId], anim);
    }
}

static void SpriteCB_Icons(struct Sprite *sprite)
{
    switch (sprite->tState)
    {
        case 0: // slide on Pokegear init
            if (sprite->tCounter < 32)
            {
                sprite->x += ICON_SLIDE_SPEED;
                sprite->tCounter += ICON_SLIDE_SPEED;
            }
            else
            {
                sprite->tCounter = 0;
                sprite->tState = 3;
            }
            break;
        case 1: // sliding out
            if (sprite->x < 16)
            {
                sprite->x += 2;
            }
            else
            {
                sprite->tState = 3;
            }
            break;
        case 2: // sliding in
            if (sprite->x > 8)
            {
                sprite->x -= 2;
            }
            else
            {
                sprite->tState = 3;
            }
            break;
        case 3: // done
            break;
    }
}

static u8 ChangeCardWithDelta(s8 delta, u8 oldCard)
{
    int newCard = oldCard + delta;

    while (TRUE)
    {
        if (newCard < 0 || newCard >= CardCount)
        {
            newCard = oldCard;
            break;
        }

        if ((newCard == MapCard && !FlagGet(FLAG_SYS_HAS_MAP_CARD)) ||
            (newCard == RadioCard && !FlagGet(FLAG_SYS_HAS_RADIO_CARD)))
        {
            newCard += delta;
        }
        else
        {
            break;
        }
    }

    return newCard;
}

static void Task_Pokegear3(u8 taskId)
{
    if (++sPokegearStruct.fakeSeconds >= 60)
    {
        sPokegearStruct.fakeSeconds = 0;
    }

    if (sPokegearStruct.canSwitchCards)
    {
        u8 newCard = sPokegearStruct.currentCard;

        if (JOY_NEW(B_BUTTON))
        {
            gTasks[taskId].func = Task_ExitPokegear1;
            PlaySE(SE_POKENAV_OFF);
            return;
        }
        else if (JOY_NEW(START_BUTTON))
        {
            newCard = ChangeCardWithDelta(-1, sPokegearStruct.currentCard);
        }
        else if (JOY_NEW(SELECT_BUTTON))
        {
            newCard = ChangeCardWithDelta(1, sPokegearStruct.currentCard);
        }

        if (sPokegearStruct.currentCard != newCard)
        {
            PlaySE(SE_SELECT);
            gTasks[taskId].tState = 0;
            gTasks[taskId].tNewCard = newCard;
            gTasks[taskId].func = Task_SwapCards;
            UnloadCard(sPokegearStruct.currentCard);
        }
    }
}

static void ShowHelpBar(const u8 *string)
{
    const u8 color[3] = { 15, 1, 2 };

    FillWindowPixelBuffer(WIN_HELP, 0xFF);
    AddTextPrinterParameterized3(WIN_HELP, 0, GetStringRightAlignXOffset(0, string, 240) - 4, 0, color, 0, string);
    CopyWindowToVram(WIN_HELP, 2);
}

static void ClearOrDrawTopBar(bool8 clear)
{
    if (!clear)
    {
        PutWindowTilemap(WIN_HELP);
    }
    else
    {
        ClearWindowTilemap(WIN_HELP);
    }
}

static void LoadCardBgs(enum CardType newCard)
{
    HideBg(2);

    switch (newCard)
    {
        case ClockCard:
            LZ77UnCompVram(gClockCardTilemap, (void *)(VRAM + 0xE000));
            break;
        case MapCard:
            ShowBg(2);
            LZ77UnCompVram(gMapCardTilemap, (void *)(VRAM + 0xE000));
            sPokegearStruct.map = AllocZeroed(sizeof(struct RegionMap));
            InitRegionMapData(sPokegearStruct.map, &sBgTemplates[2], MAPMODE_POKEGEAR, REGION_MAP_XOFF, 0);  // TODO: Make check for button
            while(LoadRegionMapGfx(FALSE));
            break;
        case PhoneCard:
            LZ77UnCompVram(gPhoneCardTilemap, (void *)(VRAM + 0xE000));
            break;
        case RadioCard:
            LZ77UnCompVram(gRadioCardTilemap, (void *)(VRAM + 0xE000));
            break;
    }

}

static void Task_SwapCards(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    u8 newCard = tNewCard;

    if (JOY_NEW(START_BUTTON))
    {
        newCard = ChangeCardWithDelta(-1, tNewCard);
    }
    else if (JOY_NEW(SELECT_BUTTON))
    {
        newCard = ChangeCardWithDelta(1, tNewCard);
    }

    if (tNewCard != newCard)
    {
        PlaySE(SE_SELECT);
        if (tState > 1)
        {
            tState = 0;
        }
        sPokegearStruct.currentCard = tNewCard;
        tNewCard = newCard;
    }

    switch (tState)
    {
        case 0:
            tCurrentPos = 0;
            gSprites[tIconSprites(sPokegearStruct.currentCard)].data[0] = 2;
            tState++;
        case 1:
            tCurrentPos += CARD_SLIDE_SPEED;
            if (tCurrentPos < CARD_SLIDE_RIGHT_X)
            {
                SetGpuReg(REG_OFFSET_BG1HOFS, 512 - tCurrentPos);
                SetGpuReg(REG_OFFSET_BG2HOFS, 512 - tCurrentPos);
            }
            else
            {
                tCurrentPos = CARD_SLIDE_RIGHT_X;
                SetGpuReg(REG_OFFSET_BG1HOFS, 512 - CARD_SLIDE_RIGHT_X);
                SetGpuReg(REG_OFFSET_BG2HOFS, 512 - CARD_SLIDE_RIGHT_X);
                gSprites[tIconSprites(tNewCard)].data[0] = 1;
                sPokegearStruct.currentCard = tNewCard;
                LoadCardBgs(tNewCard);
                tState++;
            }
            break;
        case 2:
            tCurrentPos -= CARD_SLIDE_SPEED;
            if (tCurrentPos > 0)
            {
                SetGpuReg(REG_OFFSET_BG1HOFS, 512 - tCurrentPos);
                SetGpuReg(REG_OFFSET_BG2HOFS, 512 - tCurrentPos);
            }
            else
            {
                SetGpuReg(REG_OFFSET_BG1HOFS, 0);
                SetGpuReg(REG_OFFSET_BG2HOFS, 0);
                LoadCard(tNewCard);
                gTasks[taskId].func = Task_Pokegear3;
            }
            break;
    }
}

static void Task_ExitPokegear1(u8 taskId)
{
    sPokegearStruct.exiting = TRUE;
    BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, 0);
    gTasks[taskId].func = Task_ExitPokegear2;
}

static void Task_ExitPokegear2(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        UnloadCard(sPokegearStruct.currentCard);
        FreePokegearData();
        ClearOrDrawTopBar(TRUE);
        FreeAllWindowBuffers(); // just make sure, y'know?
        SetMainCallback2(CB2_ReturnToFieldWithOpenMenu);
    }
}

#define tDayOfWeek data[0]
#define tDigitSpriteIds(n) data[n + 1]

#define tPosition data[0]
#define tStoredVal data[1]

static void LoadClockCard(void)
{
    static const u8 clockX[6] = {
        108, 122, 130, 139, 153, 165
    };

    int i;
    u8 newTask, spriteId;
    const u8 *dayOfWeek = GetDayOfWeekString(gLocalTime.dayOfWeek);
    ShowHelpBar(gText_ClockCardHelp);

    DrawStdFrameWithCustomTileAndPalette(WIN_DIALOG, FALSE, MENU_FRAME_BASE_TILE_NUM, MENU_FRAME_PALETTE_NUM);
    PutWindowTilemap(WIN_TOP);
    AddTextPrinterParameterized2(WIN_DIALOG, 2, gText_PokegearInstructions, 0, NULL, 2, 1, 3);
    AddTextPrinterParameterized3(WIN_TOP, 2, GetStringCenterAlignXOffset(2, dayOfWeek, 0x70), 1, sTextColor, 0, dayOfWeek);
    ScheduleBgCopyTilemapToVram(0);

    LoadSpriteSheet(&sSpriteSheet_DigitTiles);

    newTask = CreateTask(Task_ClockCard, 0);
    gTasks[newTask].tDayOfWeek = gLocalTime.dayOfWeek;

    for (i = 0; i < 6; i++)
    {
        spriteId = CreateSprite(&sSpriteTemplate_Digits, clockX[i], 84, 0);
        gSprites[spriteId].tPosition = i;
        gSprites[spriteId].tStoredVal = -1; // causes initialization
        gSprites[spriteId].callback = SpriteCB_ClockDigits;
        gTasks[newTask].tDigitSpriteIds(i) = spriteId;
    }
}

static void Task_ClockCard(u8 taskId)
{
    int i;
    bool8 shouldForceUpdate = FALSE;

    RtcCalcLocalTime();

    // if emulator paused on Pokégear main menu, force update
    // don't check seconds because that just leads back to mistimed blinks again
    // also we don't even display seconds anyway
    if (sPokegearStruct.cachedTime.minutes != gLocalTime.minutes ||
        sPokegearStruct.cachedTime.hours != gLocalTime.hours ||
        sPokegearStruct.cachedTime.days != gLocalTime.days)
    {
        sPokegearStruct.cachedTime = gLocalTime;
        shouldForceUpdate = TRUE;
    }

    if (JOY_NEW(A_BUTTON))
    {
        PlaySE(SE_SELECT);
        gSaveBlock2Ptr->twentyFourHourClock = !gSaveBlock2Ptr->twentyFourHourClock;
        shouldForceUpdate = TRUE;
    }

    // only change day of week when clock gets an update
    if ((shouldForceUpdate || sPokegearStruct.fakeSeconds == 0) && gTasks[taskId].tDayOfWeek != gLocalTime.dayOfWeek)
    {
        const u8 *dayOfWeek = GetDayOfWeekString(gLocalTime.dayOfWeek);
        gTasks[taskId].tDayOfWeek = gLocalTime.dayOfWeek;
        FillWindowPixelBuffer(WIN_TOP, 0);
        AddTextPrinterParameterized3(WIN_TOP, 2, GetStringCenterAlignXOffset(2, dayOfWeek, 0x70), 1, sTextColor, 0, dayOfWeek);
    }

    if (shouldForceUpdate)
    {
        for (i = 0; i < 6; i++)
        {
            gSprites[gTasks[taskId].tDigitSpriteIds(i)].tStoredVal = -1; // queue sprites for immediate changeover
        }
    }
}

static void SpriteCB_ClockDigits(struct Sprite* sprite)
{
    u8 value = sprite->tStoredVal;

    if (sprite->tStoredVal == -1 || sPokegearStruct.fakeSeconds == 0)
    {
        switch (sprite->tPosition)
        {
            case 0:
                value = gLocalTime.hours;
                if (!gSaveBlock2Ptr->twentyFourHourClock)
                {
                    if (value > 12)
                        value -= 12;
                    else if (value == 0)
                        value = 12;
                }
                value = value / 10;
                if (value != 0)
                    value += 1;
                break;
            case 1:
                value = gLocalTime.hours;
                if (!gSaveBlock2Ptr->twentyFourHourClock)
                {
                    if (value > 12)
                        value -= 12;
                    else if (value == 0)
                        value = 12;
                }
                value = value % 10 + 1;
                break;
            case 2:
                // handled outside of switch
                break;
            case 3:
                value = gLocalTime.minutes / 10 + 1;
                break;
            case 4:
                value = gLocalTime.minutes % 10 + 1;
                break;
            case 5:
                if (gSaveBlock2Ptr->twentyFourHourClock)
                    value = 13;
                else if (gLocalTime.hours < 12)
                    value = 14;
                else
                    value = 15;
                break;
            default:
                value = 0;
                break;
        }
    }

    if (sprite->tPosition == 2)
    {
        if (sPokegearStruct.fakeSeconds < 30)
            value = 12;
        else
            value = 11;
    }

    if (sprite->tStoredVal != value)
    {
        sprite->tStoredVal = value;
        StartSpriteAnim(sprite, value);
    }
}

static void UnloadClockCard(void)
{
    u8 taskId = FindTaskIdByFunc(Task_ClockCard);
    int i;

    ClearStdWindowAndFrameToTransparent(WIN_DIALOG, TRUE);

    FillWindowPixelBuffer(WIN_TOP, 0);
    ClearWindowTilemap(WIN_TOP);
    CopyWindowToVram(WIN_TOP, 2);

    FreeSpriteTilesByTag(TAG_DIGITS);

    for (i = 0; i < 6; i++)
    {
        DestroySprite(&gSprites[gTasks[taskId].data[i + 1]]);
    }

    DestroyTask(taskId);
}

#undef tDayOfWeek

#undef tPosition
#undef tStoredVal

#define tState data[0]

static void LoadMapCard(void)
{
    u8 newTask;

    newTask = CreateTask(Task_MapCard, 0);
    gTasks[newTask].tState = 0;
}

static void Task_MapCard(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    switch (tState)
    {
        case 0:
            if (!LoadRegionMapGfx_Pt2())
            {
                CreateRegionMapCursor(0, 0, FALSE);
                CreateRegionMapPlayerIcon(1, 1);
                CreateSecondaryLayerDots(2, 2);
                CreateRegionMapName(3, 4);
                ShowRegionMapCursorSprite();
                switch (GetSelectedMapsecLandmarkState())
                {
                    case LANDMARK_STATE_INFO:
                        ShowHelpBar(gText_MapCardHelp2);
                        break;
                    case LANDMARK_STATE_SWITCH:
                        ShowHelpBar(gText_MapCardHelp3);
                        break;
                    default:
                        ShowHelpBar(gText_MapCardHelp1);
                        break;
                }
                tState++;
            }
            break;
        case 1:
            switch (DoRegionMapInputCallback())
            {
                case MAP_INPUT_MOVE_END:
                    PlaySEForSelectedMapsec();
                    switch (GetSelectedMapsecLandmarkState())
                    {
                        case LANDMARK_STATE_INFO:
                            ShowHelpBar(gText_MapCardHelp2);
                            break;
                        case LANDMARK_STATE_SWITCH:
                            ShowHelpBar(gText_MapCardHelp3);
                            break;
                        default:
                            ShowHelpBar(gText_MapCardHelp1);
                            break;
                    }
                    break;
            }
            break;
    }
}

static void UnloadMapCard(void)
{
    u8 taskId = FindTaskIdByFunc(Task_MapCard);

    FreeRegionMapResources();

    DestroyTask(taskId);
}

#define tListMenuTaskId data[0]
#define tScrollTaskId   data[1]
#define tSignalSpriteId data[2]

static void LoadPhoneCardContactList(u8 taskId)
{
    struct ListMenuTemplate menuTemplate = sPhoneCardListMenuTemplate;
    menuTemplate.items = sPokegearStruct.phoneContactItems;
    menuTemplate.totalItems = sPokegearStruct.phoneContactCount;
    SetCursorWithinListBounds(&sPokegearStruct.phoneScrollOffset, &sPokegearStruct.phoneSelectedItem, menuTemplate.maxShowed, sPokegearStruct.phoneContactCount);
    gTasks[taskId].tListMenuTaskId = ListMenuInit(&menuTemplate, sPokegearStruct.phoneScrollOffset, sPokegearStruct.phoneSelectedItem);
}

static void LoadPhoneCard(void)
{
    u8 newTask = CreateTask(Task_PhoneCard, 0);
    s16 *data = gTasks[newTask].data;
    u8 animNum = 3;

    ShowHelpBar(gText_PhoneCardHelp1);
    LoadPhoneCardContactList(newTask);
    DisplayPhoneCardDefaultText();
    tScrollTaskId = 0xFF;

    LoadSpriteSheet(&sSpriteSheet_PhoneSignal);
    LoadSpritePalette(&sSpritePalette_PhoneSignal);
    tSignalSpriteId = CreateSprite(&sSpriteTemplate_PhoneSignal, 200, 25, 0);

    if (!MapAllowsMatchCall())
    {
        animNum = 0;
    }
    else
    {
        switch (gMapHeader.mapType)
        {
        case MAP_TYPE_UNDERGROUND:
        case MAP_TYPE_UNDERWATER:
            animNum = 1;
            break;
        case MAP_TYPE_INDOOR:
        case MAP_TYPE_SECRET_BASE:
            animNum = 2;
            break;
        default:
            animNum = 3;
            break;
        }
    }

    StartSpriteAnim(&gSprites[tSignalSpriteId], animNum);

    PhoneCard_AddScrollIndicators(newTask);
}

static void DisplayPhoneCardDefaultText(void)
{
    DrawStdFrameWithCustomTileAndPalette(WIN_DIALOG, FALSE, MENU_FRAME_BASE_TILE_NUM, MENU_FRAME_PALETTE_NUM);
    AddTextPrinterParameterized5(WIN_DIALOG, 2, gText_PokegearWhomDoYouWantToCall, 0, 1, 0, NULL, 1, 1);
    ScheduleBgCopyTilemapToVram(0);
}

static void PhoneCard_AddScrollIndicators(u8 taskId)
{
    if (sPokegearStruct.phoneContactCount > PHONE_CARD_MAX_SHOWN_CONTACTS && gTasks[taskId].tScrollTaskId == 0xFF)
        gTasks[taskId].tScrollTaskId = AddScrollIndicatorArrowPairParameterized(SCROLL_ARROW_UP,
                                                                                206,
                                                                                40,
                                                                                104,
                                                                                sPokegearStruct.phoneContactCount - PHONE_CARD_MAX_SHOWN_CONTACTS,
                                                                                0x13F8,
                                                                                0x13F8,
                                                                                &sPokegearStruct.phoneScrollOffset);
}

static void PhoneCard_RemoveScrollIndicators(u8 taskId)
{
    if (gTasks[taskId].tScrollTaskId != 0xFF)
    {
        RemoveScrollIndicatorArrowPair(gTasks[taskId].tScrollTaskId);
        gTasks[taskId].tScrollTaskId = 0xFF;
    }
}

static void Task_PhoneCard(u8 taskId)
{
    int input;
    if (sPokegearStruct.exiting)
        return;

    input = ListMenu_ProcessInput(gTasks[taskId].tListMenuTaskId);
    ListMenuGetScrollAndRow(gTasks[taskId].tListMenuTaskId, &sPokegearStruct.phoneScrollOffset, &sPokegearStruct.phoneSelectedItem);
    switch (input)
    {
    case LIST_NOTHING_CHOSEN:
    case LIST_CANCEL:
        break;
    default:
        PlaySE(SE_SELECT);
        PhoneCard_ConfirmCall(taskId);
        break;
    }
}

static const struct MenuAction sCallOptions[] = {
    {gText_Call, PhoneCard_PlaceCall},
    {gText_Cancel6, PhoneCard_ReturnToMain}
};

static const struct MenuAction sCallOptionsDeletable[] = {
    {gText_Call, PhoneCard_PlaceCall},
    {gText_Delete, PhoneCard_DeleteEntry},
    {gText_Cancel6, PhoneCard_ReturnToMain}
};

static void PhoneCard_ConfirmCall(u8 taskId)
{
    bool8 isPermanent = gPhoneContacts[sPokegearStruct.phoneContactIds[sPokegearStruct.phoneSelectedItem + sPokegearStruct.phoneScrollOffset]].isPermanent;

    sPokegearStruct.canSwitchCards = FALSE;
    ShowHelpBar(gText_UpDownPickAOk);
    PhoneCard_RemoveScrollIndicators(taskId);

    if (isPermanent)
    {
        sPokegearStruct.phoneCallActionWindowId = AddWindow(&sCallCancelWindowTemplate);
        DrawStdFrameWithCustomTileAndPalette(sPokegearStruct.phoneCallActionWindowId, FALSE, MENU_FRAME_BASE_TILE_NUM, MENU_FRAME_PALETTE_NUM);
        MultichoiceList_PrintItems(sPokegearStruct.phoneCallActionWindowId, 2, GetMenuCursorDimensionByFont(1, 0), 1, 16, ARRAY_COUNT(sCallOptions), sCallOptions, 0, 2);
        InitMenuInUpperLeftCornerPlaySoundWhenAPressed(sPokegearStruct.phoneCallActionWindowId, 2, 0, 1, 16, ARRAY_COUNT(sCallOptions), 0);
    }
    else
    {
        sPokegearStruct.phoneCallActionWindowId = AddWindow(&sCallDeleteCancelWindowTemplate);
        DrawStdFrameWithCustomTileAndPalette(sPokegearStruct.phoneCallActionWindowId, FALSE, MENU_FRAME_BASE_TILE_NUM, MENU_FRAME_PALETTE_NUM);
        MultichoiceList_PrintItems(sPokegearStruct.phoneCallActionWindowId, 2, GetMenuCursorDimensionByFont(1, 0), 1, 16, ARRAY_COUNT(sCallOptionsDeletable), sCallOptionsDeletable, 0, 2);
        InitMenuInUpperLeftCornerPlaySoundWhenAPressed(sPokegearStruct.phoneCallActionWindowId, 2, 0, 1, 16, ARRAY_COUNT(sCallOptionsDeletable), 0);
    }

    ScheduleBgCopyTilemapToVram(0);
    gTasks[taskId].func = PhoneCard_ConfirmCallProcessInput;
}

static void PhoneCard_ConfirmCallProcessInput(u8 taskId)
{
    s8 input = Menu_ProcessInputNoWrap();
    bool8 isPermanent = gPhoneContacts[sPokegearStruct.phoneContactIds[sPokegearStruct.phoneSelectedItem + sPokegearStruct.phoneScrollOffset]].isPermanent;

    switch (input)
    {
        case MENU_NOTHING_CHOSEN:
            break;
        case MENU_B_PRESSED:
            PlaySE(SE_SELECT);
            ClearStdWindowAndFrameToTransparent(sPokegearStruct.phoneCallActionWindowId, FALSE);
            RemoveWindow(sPokegearStruct.phoneCallActionWindowId);
            PutWindowTilemap(WIN_LIST);
            PhoneCard_ReturnToMain(taskId);
            break;
        default:
            PlaySE(SE_SELECT);
            ClearStdWindowAndFrameToTransparent(sPokegearStruct.phoneCallActionWindowId, FALSE);
            RemoveWindow(sPokegearStruct.phoneCallActionWindowId);
            PutWindowTilemap(WIN_LIST);
            if (isPermanent)
            {
                gTasks[taskId].func = sCallOptions[input].func.void_u8;
            }
            else
            {
                gTasks[taskId].func = sCallOptionsDeletable[input].func.void_u8;
            }
            break;
    }
}

void PhoneCard_RefreshContactList(void)
{
    PutWindowTilemap(WIN_LIST);
}

static void PhoneCard_ReturnToMain(u8 taskId)
{
    ShowHelpBar(gText_PhoneCardHelp1);
    PhoneCard_AddScrollIndicators(taskId);
    DisplayPhoneCardDefaultText();
    sPokegearStruct.canSwitchCards = TRUE;
    gTasks[taskId].func = Task_PhoneCard;
}

static void PhoneCard_PlaceCall(u8 taskId)
{
    const struct PhoneContact *phoneContact = &gPhoneContacts[sPokegearStruct.phoneContactIds[sPokegearStruct.phoneSelectedItem + sPokegearStruct.phoneScrollOffset]];
    ShowHelpBar(gText_ANext);
    FillWindowPixelBuffer(WIN_DIALOG, 0x11);
    PhoneScriptContext_SetupPhoneScript(phoneContact, PHONE_SCRIPT_POKEGEAR);
    gTasks[taskId].func = PhoneCard_ExecuteCall;
}

static void PhoneCard_DeleteEntry(u8 taskId)
{
    ShowHelpBar(gText_ANext);
    FillWindowPixelBuffer(WIN_DIALOG, 0x11);
    AddTextPrinterParameterized5(WIN_DIALOG, 2, gText_PokegearDeleteThisStoredPhoneNumber, 0, 1, 0, NULL, 1, 1);
    CreateYesNoMenu(&sYesNoWindowTemplate, 2, 0, 2, MENU_FRAME_BASE_TILE_NUM, MENU_FRAME_PALETTE_NUM, 0);
    ScheduleBgCopyTilemapToVram(0);
    gTasks[taskId].func = PhoneCard_ConfirmDeleteProcessInput;
}

static void PhoneCard_ConfirmDeleteProcessInput(u8 taskId)
{
    s8 input = Menu_ProcessInputNoWrap();

    switch (input)
    {
        case MENU_B_PRESSED:
        case 1:
            PlaySE(SE_SELECT);
            ClearStdWindowAndFrameToTransparent(sPokegearStruct.phoneCallActionWindowId, FALSE);
            RemoveWindow(sPokegearStruct.phoneCallActionWindowId);
            PutWindowTilemap(WIN_LIST);
            PhoneCard_ReturnToMain(taskId);
            break;
        case 0:
            PlaySE(SE_SELECT);
            ClearStdWindowAndFrameToTransparent(sPokegearStruct.phoneCallActionWindowId, FALSE);
            RemoveWindow(sPokegearStruct.phoneCallActionWindowId);
            FlagClear(gPhoneContacts[sPokegearStruct.phoneContactIds[sPokegearStruct.phoneSelectedItem + sPokegearStruct.phoneScrollOffset]].registeredFlag);
            InitPhoneCardData();
            DestroyListMenuTask(gTasks[taskId].tListMenuTaskId, &sPokegearStruct.phoneScrollOffset, &sPokegearStruct.phoneSelectedItem);
            LoadPhoneCardContactList(taskId);
            PutWindowTilemap(WIN_LIST);
            PhoneCard_ReturnToMain(taskId);
            break;
    }
}
static const u8 sPhoneCallText_NobodyAnswered[] = _("Nobody answered the call…");
static const u8 sPhoneCallText_OutOfService_Ellipsis[] = _("{PAUSE 10}{PLAY_SE SE_PHONE_BEEP}…… {PAUSE 40}{PLAY_SE SE_PHONE_BEEP}…… {PAUSE 40}{PLAY_SE SE_PHONE_BEEP}……{PAUSE 40}");
static const u8 sPhoneCallText_OutOfService[] = _("You're out of the service area.");
static const u8 sPhoneCallText_JustGoTalkToThem[] = _("Just go talk to that person!");

#define tPhoneCallInitState data[0]

void Task_InitPokegearPhoneCall(u8 taskId)
{
    switch (gTasks[taskId].tPhoneCallInitState)
    {
    case 0:
        gSpecialVar_Result = PHONE_CALL_SUCCESS;
        gPhoneCallWindowId = AddWindow(&sPhoneCallWindowTemplate);
        LoadBgTiles(0, gPhoneCall_WindowGfx, sizeof(gPhoneCall_WindowGfx), 0x143);
        FillWindowPixelBuffer(gPhoneCallWindowId, 0x11);
        LoadPalette(gPhoneCall_WindowPal, 0xE0, sizeof(gPhoneCall_WindowPal));
        gTasks[taskId].tPhoneCallInitState = 1;
        break;
    case 1:
        FreeTempTileDataBuffersIfPossible();
        PutWindowTilemap(gPhoneCallWindowId);
        DrawPhoneCallTextBoxBorder(gPhoneCallWindowId, 0x143, 14);
        CopyWindowToVram(gPhoneCallWindowId, 2);
        CopyBgTilemapBufferToVram(0);
        if (!MapAllowsMatchCall())
        {
            AddTextPrinterParameterized5(gPhoneCallWindowId, 2, sPhoneCallText_OutOfService_Ellipsis, 2, 1, 0, NULL, 1, 2);
            gTasks[taskId].tPhoneCallInitState = 3;
        }
        else
        {
            AddTextPrinterParameterized5(gPhoneCallWindowId, 2, gText_PokegearCallEllipsis, 2, 1, 0, NULL, 1, 2);
            gTasks[taskId].tPhoneCallInitState = 2;
        }
        break;
    case 2:
        if (IsTextPrinterActive(gPhoneCallWindowId))
        {
            gTextFlags.canABSpeedUpPrint = 0;
        }
        else
        {
            const struct PhoneContact *phoneContact;
            const u8 *str = NULL;
            RtcCalcLocalTime();
            FillWindowPixelBuffer(gPhoneCallWindowId, 0x11);
            phoneContact = &gPhoneContacts[sPokegearStruct.phoneContactIds[sPokegearStruct.phoneSelectedItem + sPokegearStruct.phoneScrollOffset]];

            if (phoneContact->mapNum == gSaveBlock1Ptr->location.mapNum && phoneContact->mapGroup == gSaveBlock1Ptr->location.mapGroup)
                str = sPhoneCallText_JustGoTalkToThem;
            else if (!DummiedOut_IsPhoneContactAvailable(phoneContact, gLocalTime.dayOfWeek, gLocalTime.hours))
                str = sPhoneCallText_NobodyAnswered;

            if (str != NULL)
            {
                StringExpandPlaceholders(gStringVar4, str);
                AddTextPrinterParameterized5(gPhoneCallWindowId, 2, gStringVar4, 2, 1, GetPlayerTextSpeedDelay(), NULL, 1, 2);
                gSpecialVar_Result = PHONE_CALL_FAIL;
                gTasks[taskId].tPhoneCallInitState = 4;
            }
            else
            {
                DestroyTask(taskId);
            }
        }
        break;
    case 3:
        // Out of the service area
        if (IsTextPrinterActive(gPhoneCallWindowId))
        {
            gTextFlags.canABSpeedUpPrint = 0;
        }
        else
        {
            AddTextPrinterParameterized5(gPhoneCallWindowId, 2, sPhoneCallText_OutOfService, 2, 1, 0, NULL, 1, 2);
            gSpecialVar_Result = PHONE_CALL_FAIL_SILENT;
            gTasks[taskId].tPhoneCallInitState = 4;
        }
    case 4:
        // Getting to this switch case means that the phone call was unsuccessful, due to being out of range, in the same map, or
        // the phone contact not being available to talk.

		if (IsTextPrinterActive(gPhoneCallWindowId))
		{
			if (JOY_HELD(A_BUTTON))
				gTextFlags.canABSpeedUpPrint = 1;
			else
				gTextFlags.canABSpeedUpPrint = 0;
		}
		else if (JOY_NEW(A_BUTTON | B_BUTTON))
		{
			DestroyTask(taskId);
		}

        break;
    }
}

void DrawPhoneCallTextBoxBorder(u32 windowId, u32 tileOffset, u32 paletteId)
{
    int bg, x, y, width, height;
    int tileNum;

    bg = GetWindowAttribute(windowId, WINDOW_BG);
    x = GetWindowAttribute(windowId, WINDOW_TILEMAP_LEFT);
    y = GetWindowAttribute(windowId, WINDOW_TILEMAP_TOP);
    width = GetWindowAttribute(windowId, WINDOW_WIDTH);
    height = GetWindowAttribute(windowId, WINDOW_HEIGHT);
    tileNum = tileOffset + GetBgAttribute(bg, BG_ATTR_BASETILE);

    FillBgTilemapBufferRect_Palette0(bg, ((paletteId << 12) & 0xF000) | (tileNum + 0), x - 1, y - 1, 1, 1);
    FillBgTilemapBufferRect_Palette0(bg, ((paletteId << 12) & 0xF000) | (tileNum + 1), x, y - 1, width, 1);
    FillBgTilemapBufferRect_Palette0(bg, ((paletteId << 12) & 0xF000) | (tileNum + 2), x + width, y - 1, 1, 1);
    FillBgTilemapBufferRect_Palette0(bg, ((paletteId << 12) & 0xF000) | (tileNum + 3), x - 1, y, 1, height);
    FillBgTilemapBufferRect_Palette0(bg, ((paletteId << 12) & 0xF000) | (tileNum + 4), x + width, y, 1, height);
    FillBgTilemapBufferRect_Palette0(bg, ((paletteId << 12) & 0xF000) | (tileNum + 5), x - 1, y + height, 1, 1);
    FillBgTilemapBufferRect_Palette0(bg, ((paletteId << 12) & 0xF000) | (tileNum + 6), x, y + height, width, 1);
    FillBgTilemapBufferRect_Palette0(bg, ((paletteId << 12) & 0xF000) | (tileNum + 7), x + width, y + height, 1, 1);
}

void EndPokegearPhoneCall(void)
{
    ClearStdWindowAndFrameToTransparent(gPhoneCallWindowId, TRUE);
    RemoveWindow(gPhoneCallWindowId);
    DisplayPhoneCardDefaultText();
}

static void PhoneCard_ExecuteCall(u8 taskId)
{
    if (!PhoneScriptContext_IsEnabled())
        gTasks[taskId].func = PhoneCard_ReturnToMain;
}

static void UnloadPhoneCard(void)
{
    u8 taskId = FindTaskIdByFunc(Task_PhoneCard);
    s16 *data = gTasks[taskId].data;

    FreeSpriteTilesByTag(TAG_PHONE_SIGNAL);
    FreeSpritePaletteByTag(TAG_PHONE_SIGNAL);
    if (tSignalSpriteId != MAX_SPRITES)
    {
        DestroySprite(&gSprites[tSignalSpriteId]);
        tSignalSpriteId = MAX_SPRITES;
    }

    PhoneCard_RemoveScrollIndicators(taskId);
    ClearStdWindowAndFrameToTransparent(WIN_DIALOG, TRUE);
    ClearStdWindowAndFrameToTransparent(WIN_LIST, TRUE);
    DestroyListMenuTask(tListMenuTaskId, NULL, NULL);

    DestroyTask(taskId);
}

#undef tListMenuTaskId
#undef tScrollTaskId
#undef tSignalSpriteId

#define tRadioShowTaskId data[0]

#define tShowNameId data[0]
#define tWindowId data[1]
#define tCurrentLine data[2]

#define tPosition data[0]
#define tStoredVal data[1]

static void LoadRadioCard(void)
{
    static const u8 radioX[6] = {
        114, 128, 142, 150, 159
    };

    int i;
    u8 newTask, spriteId;

    ShowHelpBar(gText_RadioCardHelp);
    DrawStdFrameWithCustomTileAndPalette(WIN_DIALOG, FALSE, MENU_FRAME_BASE_TILE_NUM, MENU_FRAME_PALETTE_NUM);
    FillWindowPixelBuffer(WIN_DIALOG, 0x11);
    CopyWindowToVram(WIN_DIALOG, 2);
    PutWindowTilemap(WIN_BOTTOM);
    FillWindowPixelBuffer(WIN_BOTTOM, 0x00);
    CopyWindowToVram(WIN_BOTTOM, 2);
    ScheduleBgCopyTilemapToVram(0);

    LoadSpriteSheet(&sSpriteSheet_DigitTiles);

    newTask = CreateTask(Task_RadioCard, 0);

    gTasks[newTask].tRadioShowTaskId = 0xFF;

    UpdateRadioStation(newTask, sPokegearStruct.currentRadioStation);
    PlayNewMapMusic(MUS_DUMMY);
    Overworld_SetSavedMusic(MUS_DUMMY);

    for (i = 0; i < 5; i++)
    {
        spriteId = CreateSprite(&sSpriteTemplate_Digits, radioX[i], 52, 0);
        gSprites[spriteId].tPosition = i;
        gSprites[spriteId].callback = SpriteCB_RadioDigits;
        gTasks[newTask].data[i + 1] = spriteId;
    }
}

static void SpriteCB_RadioDigits(struct Sprite* sprite)
{
    u8 value;
    u8 station = sPokegearStruct.currentRadioStation + 1;
    u8 stationMajor = station >> 1;

    switch (sprite->tPosition)
    {
        case 0:
            value = stationMajor / 100 + 1;
            break;
        case 1:
            value = (stationMajor / 10) % 10 + 1;
            break;
        case 2:
            value = stationMajor % 10 + 1;
            break;
        case 3:
            value = 16;
            break;
        case 4:
            value = station & 1 ? 6 : 1;
            break;
        default:
            value = 0;
            break;
    }

    if (sprite->tStoredVal != value)
    {
        sprite->tStoredVal = value;
        StartSpriteAnim(sprite, value);
    }
}

static void ClearRadioWindows(void)
{
    FillWindowPixelBuffer(WIN_BOTTOM, 0);
    CopyWindowToVram(WIN_BOTTOM, 2);
    FillWindowPixelBuffer(WIN_DIALOG, 0x11);
    CopyWindowToVram(WIN_DIALOG, 2);
}

static void UpdateRadioStation(u8 taskId, u8 frequency)
{
    const u8 *title = NULL;
    const struct RadioStation *station;
    u8 region = GetCurrentRegion();

    for (station = gRadioStationData; station->frequency != 0xFF; station++)
    {
        if (station->frequency == frequency && station->region == region)
            break;
    }

    if (gTasks[taskId].tRadioShowTaskId != 0xFF)
    {
        DestroyTask(gTasks[taskId].tRadioShowTaskId);
        gTasks[taskId].tRadioShowTaskId = 0xFF;
        ClearRadioWindows();
        PlayNewMapMusic(MUS_DUMMY);
        Overworld_SetSavedMusic(MUS_DUMMY);
    }

    if (station->frequency != 0xFF)
    {
        u8 showId = station->loadFunc();

        if (showId != NO_RADIO_SHOW)
        {
            u8 radioShowTaskId = CreateTask(Task_PlayRadioShow, 80);

            gTasks[radioShowTaskId].tWindowId = WIN_DIALOG;
            gTasks[radioShowTaskId].tCurrentLine = showId;
            gTasks[radioShowTaskId].tShowNameId = NO_RADIO_SHOW;
            gTasks[taskId].tRadioShowTaskId = radioShowTaskId;

            ClearRadioWindows();
        }
        else
        {
            gTasks[taskId].tRadioShowTaskId = 0xFF;
        }
    }
    else
    {
        gTasks[taskId].tRadioShowTaskId = 0xFF;
    }
}

static void Task_RadioCard(u8 taskId)
{
    u8 station;
    if (sPokegearStruct.exiting)
    {
        if (gTasks[taskId].tRadioShowTaskId != 0xFF)
        {
            DestroyTask(gTasks[taskId].tRadioShowTaskId);
            gTasks[taskId].tRadioShowTaskId = 0xFF;
        }
        return;
    }

    station = sPokegearStruct.currentRadioStation;
    if (JOY_REPEAT(DPAD_RIGHT))
    {
        station++;
    }
    else if (JOY_REPEAT(DPAD_LEFT))
    {
        station--;
    }

    if (station != sPokegearStruct.currentRadioStation && station <= RADIO_FREQ(20.5)) // limit station between 0.5 and 20.5
    {
        PlaySE(SE_BALL_TRAY_EXIT);
        UpdateRadioStation(taskId, station);
        sPokegearStruct.currentRadioStation = station;
    }

    if (gTasks[taskId].tRadioShowTaskId != 0xFF)
    {
        u8 showNameId = gTasks[gTasks[taskId].tRadioShowTaskId].tShowNameId;
        if (showNameId != 0xFF)
        {
            if (showNameId != NO_RADIO_SHOW)
            {
                AddTextPrinterParameterized3(WIN_BOTTOM,
                                             2,
                                             GetStringCenterAlignXOffset(2, gRadioShowNames[showNameId], 0x70),
                                             5,
                                             sTextColor,
                                             0,
                                             gRadioShowNames[showNameId]);
            }
            else
            {
                ClearRadioWindows();
            }
            gTasks[gTasks[taskId].tRadioShowTaskId].tShowNameId = 0xFF;
        }
    }
}

static void UnloadRadioCard(void)
{
    u8 taskId = FindTaskIdByFunc(Task_RadioCard);
    int i;

    ClearStdWindowAndFrameToTransparent(WIN_DIALOG, TRUE);

    FillWindowPixelBuffer(WIN_BOTTOM, 0);
    ClearWindowTilemap(WIN_BOTTOM);
    CopyWindowToVram(WIN_BOTTOM, 2);

    if (IsBGMStopped())
        Overworld_PlaySpecialMapMusic();

    FreeSpriteTilesByTag(TAG_DIGITS);

    for (i = 0; i < 5; i++)
    {
        DestroySprite(&gSprites[gTasks[taskId].data[i + 1]]);
    }

    if (gTasks[taskId].tRadioShowTaskId != 0xFF)
    {
        DestroyTask(gTasks[taskId].tRadioShowTaskId);
    }

    DestroyTask(taskId);
}

static void InitPhoneCardData(void)
{
    int i;
    u8 contacts[PHONE_CONTACT_COUNT];
    int contactCount = 0;

    for (i = 0; i < PHONE_CONTACT_COUNT; i++)
    {
        if (FlagGet(gPhoneContacts[i].registeredFlag))
        {
            contacts[contactCount] = i;
            contactCount++;
        }
    }

    // Generate the phone contact list.
    sPokegearStruct.phoneContactCount = contactCount;
    if (contactCount > 0)
    {
        // we can only ever delete contacts from this menu, so no need to reallocate if the lists already exist
        if (!sPokegearStruct.phoneContactNames)
        {
            sPokegearStruct.phoneContactNames = Alloc(contactCount * PHONE_CARD_MAX_NAME_LENGTH);
        }

        if (!sPokegearStruct.phoneContactItems)
        {
            sPokegearStruct.phoneContactItems = Alloc(contactCount * sizeof(struct ListMenuItem));
        }

        if (!sPokegearStruct.phoneContactIds)
        {
            sPokegearStruct.phoneContactIds = Alloc(contactCount);
        }

        for (i = 0; i < contactCount; i++)
        {
            const struct PhoneContact *phoneContact = &gPhoneContacts[contacts[i]];
            struct ListMenuItem *item = &sPokegearStruct.phoneContactItems[i];
            item->id = i;
            sPokegearStruct.phoneContactIds[i] = contacts[i];
            item->name = BuildPhoneContactDisplayName(phoneContact, sPokegearStruct.phoneContactNames + i * PHONE_CARD_MAX_NAME_LENGTH);
        }
    }
}

#undef WIN_DIALOG
#undef WIN_TOP
#undef WIN_BOTTOM


