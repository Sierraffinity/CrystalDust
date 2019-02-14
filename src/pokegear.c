#include "global.h"
#include "main.h"
#include "pokegear.h"
#include "alloc.h"
#include "battle.h"
#include "battle_setup.h"
#include "bg.h"
#include "data2.h"
#include "day_night.h"
#include "event_data.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "international_string_util.h"
#include "list_menu.h"
#include "match_call.h"
#include "menu.h"
#include "overworld.h"
#include "palette.h"
#include "pokegear_phone.h"
#include "radio.h"
#include "random.h"
#include "region_map.h"
#include "rtc.h"
#include "scanline_effect.h"
#include "sound.h"
#include "string_util.h"
#include "strings.h"
#include "text.h"
#include "text_window.h"
#include "window.h"
#include "constants/flags.h"
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

#define TAG_PHONE_CALL_ICON 12347

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
    bool8 twentyFourHourMode;
    u8 currentRadioStation;
} sPokegearStruct = {0};

extern const u8 gTrainerClassNames[][13];

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
static void PhoneCard_AddScrollIndicators(u8 taskId);
static void PhoneCard_ReturnToMain(u8 taskId);
static void PhoneCard_PlaceCall(u8 taskId);
static void LoadPhoneCallWindowGfx(u8 taskId);
static void DrawPhoneCallTextBoxBorder(u32 windowId, u32 tileOffset, u32 paletteId);
static void MovePhoneCallWindowToVram(u8 taskId);
static void UpdateRadioStation(u8 taskId, u8 frequency);
static void LoadCardSprites(u8 taskId);
static void SpriteCB_Icons(struct Sprite* sprite);
static void InitPhoneCardData(void);
static void PhoneCard_ExecuteCallStart(u8 taskId);
static void PhoneCard_ExecuteCall(u8 taskId);

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
static const u16 sPhoneCallWindowPalette[] = INCBIN_U16("graphics/unknown/unknown_60EA4C.gbapal");
static const u8 sPhoneCallWindowGfx[] = INCBIN_U8("graphics/interface/menu_border.4bpp");
static const u8 sPhoneCallWindowIconGfx[] = INCBIN_U8("graphics/pokegear/phone_call_icon.4bpp");
static const u16 sPhoneCallWindowIconPalette[] = INCBIN_U16("graphics/pokegear/phone_call_icon.gbapal");

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

static const struct WindowTemplate sConfirmWindowTemplate = {
    .bg = 0,
    .tilemapLeft = 23,
    .tilemapTop = 9,
    .width = 6,
    .height = 4,
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
    .itemVerticalPadding = 0,
    .scrollMultiple = LIST_NO_MULTIPLE_SCROLL,
    .fontId = 1,
    .cursorKind = 0
};

const struct SpriteSheet sSpriteSheet_DigitTiles =
{
    .data = sDigitTiles,
    .size = 2176,
    .tag = 12345,
};

const struct SpritePalette gSpritePalette_PokegearMenuSprites =
{
    .data = sMenuSpritesPalette,
    .tag = 54321
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
    .tileTag = 12345,
    .paletteTag = 54321,
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
    .tag = 12346,
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
};

const struct SpriteTemplate sSpriteTemplate_Icons = {
    .tileTag = 12346,
    .paletteTag = 54321,
    .oam = &sOamData_Icons,
    .anims = sSpriteAnimTable_Icons,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_Icons
};

static const struct SpriteSheet sPhoneCallIconSpriteSheet = {
    .data = sPhoneCallWindowIconGfx,
    .size = 0x200,
    .tag = TAG_PHONE_CALL_ICON,
};

const struct SpritePalette gPhoneCallIconSpritePalette = {
    .data = sPhoneCallWindowIconPalette,
    .tag = TAG_PHONE_CALL_ICON
};

static const struct OamData sPhoneCallIcon_OamData = {
    .size = 2,
};

static const struct SpriteTemplate sPhoneCallIconSpriteTemplate = {
    .tileTag = TAG_PHONE_CALL_ICON,
    .paletteTag = TAG_PHONE_CALL_ICON,
    .oam = &sPhoneCallIcon_OamData,
    .anims = gDummySpriteAnimTable,
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
    LoadPalette(stdpal_get(2), 0xB0, 0x20);
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, sBgTemplates, ARRAY_COUNT(sBgTemplates));
    InitWindows(sWindowTemplates);
    DeactivateAllTextPrinters();
    LoadUserWindowBorderGfx(0, MENU_FRAME_BASE_TILE_NUM, MENU_FRAME_PALETTE_NUM * 0x10);
    clear_scheduled_bg_copies_to_vram();
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
    LoadCardBgs(ClockCard);

    SetGpuReg(REG_OFFSET_BG1HOFS, 512 - CARD_SLIDE_RIGHT_X);

    ShowBg(0);
    ShowBg(1);
    ShowBg(3);
    
    PlaySE(SE_PN_ON);
}

static void VBlankCB(void)
{
    ProcessSpriteCopyRequests();
    LoadOam();
    TransferPlttBuffer();
}

static void CB2_Pokegear(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    RunTextPrinters();
    do_scheduled_bg_tilemap_copies_to_vram();
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
    Free(sPokegearStruct.map);
    Free(sPokegearStruct.phoneContactItems);
    Free(sPokegearStruct.phoneContactNames);
    Free(sPokegearStruct.phoneContactIds);
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
        sPokegearStruct.twentyFourHourMode = FlagGet(FLAG_SYS_POKEGEAR_24HR);
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
                gSprites[spriteId].pos1.x += 8;
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
                sprite->pos1.x += ICON_SLIDE_SPEED;
                sprite->tCounter += ICON_SLIDE_SPEED;
            }
            else
            {
                sprite->tCounter = 0;
                sprite->tState = 3;
            }
            break;
        case 1: // sliding out
            if (sprite->pos1.x < 16)
            {
                sprite->pos1.x += 2;
            }
            else
            {
                sprite->tState = 3;
            }
            break;
        case 2: // sliding in
            if (sprite->pos1.x > 8)
            {
                sprite->pos1.x -= 2;
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
    if (sPokegearStruct.canSwitchCards)
    {
        u8 newCard = sPokegearStruct.currentCard;

        if (gMain.newKeys & B_BUTTON)
        {
            gTasks[taskId].func = Task_ExitPokegear1;
            PlaySE(SE_PN_OFF);
            return;
        }
        else if (gMain.newKeys & DPAD_LEFT)
        {
            newCard = ChangeCardWithDelta(-1, sPokegearStruct.currentCard);
        }
        else if (gMain.newKeys & DPAD_RIGHT)
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
    PutWindowTilemap(WIN_HELP);
    schedule_bg_copy_tilemap_to_vram(0);
}

static void LoadCardBgs(enum CardType newCard)
{
    HideBg(2);
    
    switch (newCard)
    {
        case ClockCard:
            ShowHelpBar(gText_ClockCardHelp);
            LZ77UnCompVram(gClockCardTilemap, (void *)(VRAM + 0xE000));
            break;
        case MapCard:
            ShowHelpBar(gText_MapCardHelp1);
            ShowBg(2);
            LZ77UnCompVram(gMapCardTilemap, (void *)(VRAM + 0xE000));
            sPokegearStruct.map = AllocZeroed(sizeof(struct RegionMap));
            sub_8122CF8(sPokegearStruct.map, &sBgTemplates[2], MAPBUTTON_NONE, REGION_MAP_XOFF);  // TODO: Make check for button
            while(sub_8122DB0(FALSE));
            break;
        case PhoneCard:
            ShowHelpBar(gText_PhoneCardHelp1);
            LZ77UnCompVram(gPhoneCardTilemap, (void *)(VRAM + 0xE000));
            break;
        case RadioCard:
            ShowHelpBar(gText_RadioCardHelp);
            LZ77UnCompVram(gRadioCardTilemap, (void *)(VRAM + 0xE000));
            break;
    }

}

static void Task_SwapCards(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    u8 newCard = tNewCard;

    if (gMain.newKeys & DPAD_LEFT)
    {
        newCard = ChangeCardWithDelta(-1, tNewCard);
    }
    else if (gMain.newKeys & DPAD_RIGHT)
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
    BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, 0);
    gTasks[taskId].func = Task_ExitPokegear2;
}

static void Task_ExitPokegear2(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        UnloadCard(sPokegearStruct.currentCard);
        FreePokegearData();
        FreeAllWindowBuffers(); // just make sure, y'know?
        SetMainCallback2(CB2_ReturnToFieldWithOpenMenu);
    }
}

#define tDayOfWeek data[0]

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

    SetWindowBorderStyle(WIN_DIALOG, FALSE, MENU_FRAME_BASE_TILE_NUM, MENU_FRAME_PALETTE_NUM);
    PutWindowTilemap(WIN_TOP);
    //PutWindowTilemap(WIN_BOTTOM);
    AddTextPrinterParameterized(WIN_DIALOG, 1, gText_PokegearInstructions, 0, 1, 0, NULL);
    AddTextPrinterParameterized3(WIN_TOP, 1, GetStringCenterAlignXOffset(1, dayOfWeek, 0x70), 1, sTextColor, 0, dayOfWeek);
    //AddTextPrinterParameterized3(WIN_BOTTOM, 1, GetStringCenterAlignXOffset(1, gText_PokegearSelectToChangeMode, 0x70), 5, sTextColor, 0, gText_PokegearSelectToChangeMode);
    schedule_bg_copy_tilemap_to_vram(0);
    
    LoadSpriteSheet(&sSpriteSheet_DigitTiles);

    newTask = CreateTask(Task_ClockCard, 0);
    gTasks[newTask].tDayOfWeek = gLocalTime.dayOfWeek;

    for (i = 0; i < 6; i++)
    {
        spriteId = CreateSprite(&sSpriteTemplate_Digits, clockX[i], 84, 0);
        gSprites[spriteId].tPosition = i;
        gSprites[spriteId].callback = SpriteCB_ClockDigits;
        gTasks[newTask].data[i + 1] = spriteId;
    }
}

static void Task_ClockCard(u8 taskId)
{
    RtcCalcLocalTime();
    if (gMain.newKeys & SELECT_BUTTON)
    {
        PlaySE(SE_SELECT);
        sPokegearStruct.twentyFourHourMode = !sPokegearStruct.twentyFourHourMode;
        if (sPokegearStruct.twentyFourHourMode)
            FlagSet(FLAG_SYS_POKEGEAR_24HR);
        else
            FlagClear(FLAG_SYS_POKEGEAR_24HR);
    }

    if (gTasks[taskId].tDayOfWeek != gLocalTime.dayOfWeek)
    {
        const u8 *dayOfWeek = GetDayOfWeekString(gLocalTime.dayOfWeek);
        gTasks[taskId].tDayOfWeek = gLocalTime.dayOfWeek;
        FillWindowPixelBuffer(WIN_TOP, 0);
        AddTextPrinterParameterized3(WIN_TOP, 1, GetStringCenterAlignXOffset(1, dayOfWeek, 0x70), 1, sTextColor, 0, dayOfWeek);
    }
}

static void SpriteCB_ClockDigits(struct Sprite* sprite)
{
    u8 value;

    switch (sprite->tPosition)
    {
        case 0:
            value = gLocalTime.hours;
            if (!sPokegearStruct.twentyFourHourMode)
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
            if (!sPokegearStruct.twentyFourHourMode)
            {
                if (value > 12)
                    value -= 12;
                else if (value == 0)
                    value = 12;
            }
            value = value % 10 + 1;
            break;
        case 2:
            if (gLocalTime.seconds & 1)
                value = 11;
            else
                value = 12;
            break;
        case 3:
            value = gLocalTime.minutes / 10 + 1;
            break;
        case 4:
            value = gLocalTime.minutes % 10 + 1;
            break;
        case 5:
            if (sPokegearStruct.twentyFourHourMode)
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

    sub_8198070(WIN_DIALOG, TRUE);
    
    FillWindowPixelBuffer(WIN_TOP, 0);
    ClearWindowTilemap(WIN_TOP);
    CopyWindowToVram(WIN_TOP, 2);

    FreeSpriteTilesByTag(12345);
    
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
#define tLastEvent data[1]

static void LoadMapCard(void)
{
    u8 newTask;

    newTask = CreateTask(Task_MapCard, 0);
    gTasks[newTask].tState = 0;
}

static void Task_MapCard(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    u8 event;
    const u8 *helpString = NULL;

    switch (tState)
    {
        case 0:
            if (!RegionMap_InitGfx2())
            {
                CreateRegionMapCursor(0, 0, FALSE);
                CreateRegionMapPlayerIcon(1, 1);
                CreateSecondaryLayerDots(2, 2);
                CreateRegionMapName(3, 4);
                tState++;
            }
            break;
        case 1:
            if (gMain.newKeys & A_BUTTON)
            {
                PlaySE(SE_HI_TURUN);
                ShowHelpBar(gText_MapCardHelp2);
                ShowRegionMapCursorSprite();
                sPokegearStruct.canSwitchCards = FALSE;
                tState++;
            }
            break;
        case 2:
            event = sub_81230AC();
            switch (event)
            {
                case INPUT_EVENT_B_BUTTON:
                    PlaySE(SE_W063B);
                    ShowHelpBar(gText_MapCardHelp1);
                    HideRegionMapCursorSprite();
                    tState--;
                    sPokegearStruct.canSwitchCards = TRUE;
                    break;
                case INPUT_EVENT_LANDMARK:
                    helpString = gText_MapCardHelp3;
                    break;
                case INPUT_EVENT_ON_BUTTON:
                    helpString = gText_MapCardHelp4;
                    break;
                case INPUT_EVENT_MOVE_END:
                    helpString = gText_MapCardHelp2;
                    break;
            }

            if (helpString != NULL && event != tLastEvent)
            {
                ShowHelpBar(helpString);
            }
            tLastEvent = event;
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
#define tScrollTaskId data[2]
#define tPhoneCallWindowId data[3]
#define tPhoneCallIconSpriteId data[4]

static void LoadPhoneCard(void)
{
    u8 newTask;
    int scrollOffset, selectedRow;
    struct ListMenuTemplate menuTemplate = sPhoneCardListMenuTemplate;
    menuTemplate.items = sPokegearStruct.phoneContactItems;
    menuTemplate.totalItems = sPokegearStruct.phoneContactCount;

    newTask = CreateTask(Task_PhoneCard, 0);
    if (sPokegearStruct.phoneScrollOffset + sPokegearStruct.phoneSelectedItem >= sPokegearStruct.phoneContactCount)
        gTasks[newTask].tListMenuTaskId = ListMenuInit(&menuTemplate, 0, 0);
    else
        gTasks[newTask].tListMenuTaskId = ListMenuInit(&menuTemplate, sPokegearStruct.phoneScrollOffset, sPokegearStruct.phoneSelectedItem);

    DisplayPhoneCardDefaultText();
    
    gTasks[newTask].tScrollTaskId = 0xFF;
    gTasks[newTask].tPhoneCallIconSpriteId = MAX_SPRITES;
    PhoneCard_AddScrollIndicators(newTask);
}

static void DisplayPhoneCardDefaultText(void)
{
    SetWindowBorderStyle(WIN_DIALOG, FALSE, MENU_FRAME_BASE_TILE_NUM, MENU_FRAME_PALETTE_NUM);
    AddTextPrinterParameterized(WIN_DIALOG, 1, gText_PokegearWhomDoYouWantToCall, 0, 1, 0, NULL);
    schedule_bg_copy_tilemap_to_vram(0);
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
    int input = ListMenu_ProcessInput(gTasks[taskId].tListMenuTaskId);
    ListMenuGetScrollAndRow(gTasks[taskId].tListMenuTaskId, &sPokegearStruct.phoneScrollOffset, &sPokegearStruct.phoneSelectedItem);
    switch (input)
    {
    case LIST_NOTHING_CHOSEN:
    case LIST_B_PRESSED:
        break;
    default:
        PlaySE(SE_SELECT);
        PhoneCard_ConfirmCall(taskId);
        break;
    }
}

static const struct MenuAction sCallOptions[] = {
    {gUnknown_085EC017, PhoneCard_PlaceCall},
    {gUnknown_085EC022, PhoneCard_ReturnToMain}
};

static void PhoneCard_ConfirmCall(u8 taskId)
{
    sPokegearStruct.canSwitchCards = FALSE;
    ShowHelpBar(gText_UpDownPickAOk);
    PhoneCard_RemoveScrollIndicators(taskId);
    sPokegearStruct.phoneCallActionWindowId = AddWindow(&sConfirmWindowTemplate);
    SetWindowBorderStyle(sPokegearStruct.phoneCallActionWindowId, FALSE, MENU_FRAME_BASE_TILE_NUM, MENU_FRAME_PALETTE_NUM);
    PrintMenuTable(sPokegearStruct.phoneCallActionWindowId, ARRAY_COUNT(sCallOptions), sCallOptions);
    InitMenuInUpperLeftCornerPlaySoundWhenAPressed(sPokegearStruct.phoneCallActionWindowId, ARRAY_COUNT(sCallOptions), 0);
    schedule_bg_copy_tilemap_to_vram(0);
    gTasks[taskId].func = PhoneCard_ConfirmCallProcessInput;
}

static void PhoneCard_ConfirmCallProcessInput(u8 taskId)
{
    s8 input = ProcessMenuInput_other();

    switch (input)
    {
        case MENU_NOTHING_CHOSEN:
            break;
        case MENU_B_PRESSED:
            PlaySE(SE_SELECT);
            sub_8198070(sPokegearStruct.phoneCallActionWindowId, FALSE);
            RemoveWindow(sPokegearStruct.phoneCallActionWindowId);
            PutWindowTilemap(WIN_LIST);
            PhoneCard_ReturnToMain(taskId);
            break;
        default:
            PlaySE(SE_SELECT);
            sub_8198070(sPokegearStruct.phoneCallActionWindowId, FALSE);
            RemoveWindow(sPokegearStruct.phoneCallActionWindowId);
            PutWindowTilemap(WIN_LIST);
            gTasks[taskId].func = sCallOptions[input].func.void_u8;
            break;
    }
}

static void PhoneCard_ReturnToMain(u8 taskId)
{
    ShowHelpBar(gText_PhoneCardHelp1);
    PhoneCard_AddScrollIndicators(taskId);
    DisplayPhoneCardDefaultText();
    if (gTasks[taskId].tPhoneCallIconSpriteId != MAX_SPRITES)
    {
        DestroySprite(&gSprites[gTasks[taskId].tPhoneCallIconSpriteId]);
        gTasks[taskId].tPhoneCallIconSpriteId = MAX_SPRITES;
    }
    sPokegearStruct.canSwitchCards = TRUE;
    gTasks[taskId].func = Task_PhoneCard;
}

static const u8 sPhoneCallText_Ellipsis[] = _("………………\p");
static const u8 sTestText[] = _("Hiya helloooo!\nBye.");
static const u8 sPhoneCallText_NobodyAnswered[] = _("Nobody answered the call…");

static void PhoneCard_PlaceCall(u8 taskId)
{
    ShowHelpBar(gText_ANext);
    FillWindowPixelBuffer(WIN_DIALOG, 0x11);
    gTasks[taskId].func = LoadPhoneCallWindowGfx;
}

static void LoadPhoneCallWindowGfx(u8 taskId)
{
    gTasks[taskId].tPhoneCallWindowId = AddWindow(&sPhoneCallWindowTemplate);
    LoadBgTiles(0, sPhoneCallWindowGfx, sizeof(sPhoneCallWindowGfx), 0x143);
    FillWindowPixelBuffer(gTasks[taskId].tPhoneCallWindowId, 0x11);
    LoadPalette(sPhoneCallWindowPalette, 0xE0, 0x20);
    LoadSpriteSheet(&sPhoneCallIconSpriteSheet);
    LoadSpritePalette(&gPhoneCallIconSpritePalette);
    gTasks[taskId].func = MovePhoneCallWindowToVram;
}

static void MovePhoneCallWindowToVram(u8 taskId)
{
    free_temp_tile_data_buffers_if_possible();
    PutWindowTilemap(gTasks[taskId].tPhoneCallWindowId);
    DrawPhoneCallTextBoxBorder(gTasks[taskId].tPhoneCallWindowId, 0x143, 14);
    CopyWindowToVram(gTasks[taskId].tPhoneCallWindowId, 2);
    CopyBgTilemapBufferToVram(0);
    gTasks[taskId].tPhoneCallIconSpriteId = CreateSprite(&sPhoneCallIconSpriteTemplate, 24, 136, 3);
    PlaySE(SE_TOREEYE);
    AddTextPrinterParameterized(gTasks[taskId].tPhoneCallWindowId, 1, sPhoneCallText_Ellipsis, 32, 1, 8, NULL);
    gTasks[taskId].func = PhoneCard_ExecuteCallStart;
}

static void DrawPhoneCallTextBoxBorder(u32 windowId, u32 tileOffset, u32 paletteId)
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

static void PhoneCard_ExecuteCallStart(u8 taskId)
{
    const struct PhoneContact *phoneContact;

    if (IsTextPrinterActive(gTasks[taskId].tPhoneCallWindowId))
    {
        gTextFlags.canABSpeedUpPrint = 0;
    }
    else
    {
        RtcCalcLocalTime();
        FillWindowPixelBuffer(gTasks[taskId].tPhoneCallWindowId, 0x11);
        phoneContact = &gPhoneContacts[sPokegearStruct.phoneContactIds[sPokegearStruct.phoneSelectedItem + sPokegearStruct.phoneScrollOffset]];
        if (phoneContact->isAvailable(gLocalTime.dayOfWeek, gLocalTime.hours))
            AddTextPrinterParameterized(gTasks[taskId].tPhoneCallWindowId, 1, sTestText, 32, 1, GetPlayerTextSpeedDelay(), NULL);
        else
            AddTextPrinterParameterized(gTasks[taskId].tPhoneCallWindowId, 1, sPhoneCallText_NobodyAnswered, 32, 1, GetPlayerTextSpeedDelay(), NULL);

        gTasks[taskId].func = PhoneCard_ExecuteCall;
    }
}

static void PhoneCard_ExecuteCall(u8 taskId)
{
    if (IsTextPrinterActive(gTasks[taskId].tPhoneCallWindowId))
    {
        if (gMain.heldKeys & A_BUTTON)
            gTextFlags.canABSpeedUpPrint = 1;
        else
            gTextFlags.canABSpeedUpPrint = 0;
    }
    else if (!IsSEPlaying() && gMain.newKeys & (A_BUTTON | B_BUTTON))
    {
        FillBgTilemapBufferRect_Palette0(0, 0, 0, 14, 30, 6);
        RemoveWindow(gTasks[taskId].tPhoneCallWindowId);
        PlaySE(SE_TOREOFF);
        gTasks[taskId].func = PhoneCard_ReturnToMain;
    }
}

static void UnloadPhoneCard(void)
{
    u8 taskId = FindTaskIdByFunc(Task_PhoneCard);

    PhoneCard_RemoveScrollIndicators(taskId);
    sub_8198070(WIN_DIALOG, TRUE);
    sub_8198070(WIN_LIST, TRUE);
    DestroyListMenuTask(gTasks[taskId].tListMenuTaskId, NULL, NULL);

    DestroyTask(taskId);
}

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
    
    SetWindowBorderStyle(WIN_DIALOG, FALSE, MENU_FRAME_BASE_TILE_NUM, MENU_FRAME_PALETTE_NUM);
    FillWindowPixelBuffer(WIN_DIALOG, 0x11);
    CopyWindowToVram(WIN_DIALOG, 2);
    PutWindowTilemap(WIN_BOTTOM);
    FillWindowPixelBuffer(WIN_BOTTOM, 0x00);
    CopyWindowToVram(WIN_BOTTOM, 2);
    schedule_bg_copy_tilemap_to_vram(0);

    LoadSpriteSheet(&sSpriteSheet_DigitTiles);

    newTask = CreateTask(Task_RadioCard, 0);

    gTasks[newTask].tRadioShowTaskId = 0xFF;

    UpdateRadioStation(newTask, sPokegearStruct.currentRadioStation);
    PlayNewMapMusic(MUS_DUMMY);

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
        ClearRadioWindows();
        PlayNewMapMusic(MUS_DUMMY);
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
    u8 station = sPokegearStruct.currentRadioStation;

    if (gMain.newAndRepeatedKeys & DPAD_UP)
    {
        station++;
    }
    else if (gMain.newAndRepeatedKeys & DPAD_DOWN)
    {
        station--;
    }

    if (station != sPokegearStruct.currentRadioStation && station <= 40) // limit station between 0.5 and 20.5
    {
        PlaySE(SE_TB_KARA);
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
                                             1,
                                             GetStringCenterAlignXOffset(1, gRadioShowNames[showNameId], 0x70),
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

    sub_8198070(WIN_DIALOG, TRUE);
    
    FillWindowPixelBuffer(WIN_BOTTOM, 0);
    ClearWindowTilemap(WIN_BOTTOM);
    CopyWindowToVram(WIN_BOTTOM, 2);

    if (IsBGMStopped())
        Overworld_PlaySpecialMapMusic();

    FreeSpriteTilesByTag(12345);
    
    for (i = 0; i < 5; i++)
    {
        DestroySprite(&gSprites[gTasks[taskId].data[i + 1]]);
    }

    DestroyTask(gTasks[taskId].tRadioShowTaskId);
    DestroyTask(taskId);
}

static const u8 sPhoneContactName_UnknownContact[] = _("UNKNOWN CONTACT");

static void InitPhoneCardData(void)
{
    int i, j, l;
    int classXOffset;
    const u8 *src;
    u8 *dest;
    u8 *contactName;
    u8 contacts[PHONE_CONTACT_COUNT];
    int contactCount = 0;

    for (i = 0; i < PHONE_CONTACT_COUNT; i++)
    {
        if (TRUE || FlagGet(gPhoneContacts[i].registeredFlag))
        {
            contacts[contactCount] = i;
            contactCount++;
        }
    }

    // Generate the phone contact list.
    sPokegearStruct.phoneContactCount = contactCount;
    if (contactCount > 0)
    {
        sPokegearStruct.phoneContactNames = Alloc(contactCount * PHONE_CARD_MAX_NAME_LENGTH);
        sPokegearStruct.phoneContactItems = Alloc(contactCount * sizeof(struct ListMenuItem));
        sPokegearStruct.phoneContactIds = Alloc(contactCount);
        for (i = 0; i < contactCount; i++)
        {
            const struct PhoneContact *phoneContact = &gPhoneContacts[contacts[i]];
            struct ListMenuItem *item = &sPokegearStruct.phoneContactItems[i];
            item->id = i;
            sPokegearStruct.phoneContactIds[i] = contacts[i];
            if (phoneContact->customDisplayName)
            {
                item->name = phoneContact->customDisplayName;
            }
            else if (phoneContact->rematchTrainerId != 0xFF)
            {
                int trainerId = gRematchTable[phoneContact->rematchTrainerId].trainerIds[0];
                src = gTrainers[trainerId].trainerName;
                dest = sPokegearStruct.phoneContactNames + i * PHONE_CARD_MAX_NAME_LENGTH;
                j = 0;
                for (l = 0; src[l] != EOS; l++)
                    dest[j++] = src[l];

                dest[j++] = CHAR_COLON;
                dest[j++] = EXT_CTRL_CODE_BEGIN;
                dest[j++] = EXT_CTRL_CODE_SIZE;
                dest[j++] = 0;

                classXOffset = GetStringRightAlignXOffset(0, gTrainerClassNames[gTrainers[trainerId].trainerClass], 128);
                dest[j++] = EXT_CTRL_CODE_BEGIN;
                dest[j++] = EXT_CTRL_CODE_CLEAR_TO;
                dest[j++] = classXOffset;

                src = gTrainerClassNames[gTrainers[trainerId].trainerClass];
                for (l = 0; src[l] != EOS; l++)
                    dest[j++] = src[l];

                dest[j++] = EOS;
                item->name = dest;
            }
            else
            {
                item->name = sPhoneContactName_UnknownContact;
            }
        }
    }
}

#undef WIN_DIALOG
#undef WIN_TOP
#undef WIN_BOTTOM
