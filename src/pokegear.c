#include "global.h"
#include "main.h"
#include "pokegear.h"
#include "bg.h"
#include "data2.h"
#include "day_night.h"
#include "event_data.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "international_string_util.h"
#include "list_menu.h"
#include "malloc.h"
#include "menu.h"
#include "overworld.h"
#include "palette.h"
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
#define WIN_CONFIRM 5

#define MENU_FRAME_BASE_TILE_NUM 532
#define MENU_FRAME_PALETTE_NUM 13

#define REGION_MAP_XOFF 2

#define FREQ(a) (u8)(a * 2 - 1)

#define CARD_SLIDE_SPEED 32
#define ICON_SLIDE_SPEED 2
#define CARD_SLIDE_RIGHT_X 208

struct RadioStation{
    u8 frequency;
    u8 region;
    const u8 *(*loadFunc)(u8 taskId, u8 windowId);
};

// TEMP
#define FLAG_MAP_CARD FLAG_SYS_POKEMON_GET
#define FLAG_RADIO_CARD FLAG_SYS_TV_HOME

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
    u8 currentCard;
    bool8 canSwitchCards;
    bool8 twentyFourHourMode;
    u8 currentRadioStation;
} sPokegearStruct = {0};

// Static ROM declarations

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
static void LoadRadioCard(void);
static void LoadCard(enum CardType type);
static void LoadCardBgs(enum CardType type);
static void SpriteCB_ClockDigits(struct Sprite* sprite);
static void SpriteCB_RadioDigits(struct Sprite* sprite);
static void UnloadClockCard(void);
static void UnloadMapCard(void);
static void UnloadPhoneCard(void);
static void UnloadRadioCard(void);
static void PhoneCard_ConfirmCallProcessInput(u8 taskId);
static void PhoneCard_AddScrollIndicators(u8 taskId);
static void PhoneCard_ReturnToMain(u8 taskId);
static void PhoneCard_PlaceCall(u8 taskId);
static void UpdateRadioStation(u8 taskId, u8 frequency);
static void LoadCardSprites(u8 taskId);
static void SpriteCB_Icons(struct Sprite* sprite);

// .rodata
static const u16 gBGPals[] = INCBIN_U16("graphics/pokegear/bg.gbapal");
static const u16 sMenuSpritesPalette[] = INCBIN_U16("graphics/pokegear/menu_sprites.gbapal");
static const u8 gMainTiles[] = INCBIN_U8("graphics/pokegear/main.4bpp.lz");
static const u8 sDigitTiles[] = INCBIN_U8("graphics/pokegear/digits.4bpp");
static const u8 sIconTiles[] = INCBIN_U8("graphics/pokegear/icons.4bpp");
static const u8 gClockCardTilemap[] = INCBIN_U8("graphics/pokegear/clock.bin.lz");
static const u8 gMapCardTilemap[] = INCBIN_U8("graphics/pokegear/map.bin.lz");
static const u8 gPhoneCardTilemap[] = INCBIN_U8("graphics/pokegear/phone.bin.lz");
static const u8 gRadioCardTilemap[] = INCBIN_U8("graphics/pokegear/radio.bin.lz");

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
    { 0, 23, 9, 6, 4, 15, 0x0163 },
    DUMMY_WIN_TEMPLATE
};

static const struct ListMenuItem sTempListMenuItems[] =
{
    {gText_Mom, 0},
    {gText_Dad, 1},
    {gText_Cool, 2},
    {gText_Tough, 3},
    {gText_Spicy, 4},
    {gText_Cute, 5},
    {gText_Cute, 6},
    {gText_Cute, 7}
};

static const struct ListMenuTemplate sPhoneCardListMenuTemplate =
{
    .items = sTempListMenuItems,
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
    .itemPrintFunc = NULL,
    .totalItems = ARRAY_COUNT(sTempListMenuItems),
    .maxShowed = 5,
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
                anim = GetCurrentRegion() + 1;
                break;
            case PhoneCard:
                anim = 4;
                break;
            case RadioCard:
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
        
        if ((newCard == MapCard && !FlagGet(FLAG_MAP_CARD)) ||
            (newCard == RadioCard && !FlagGet(FLAG_RADIO_CARD)))
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
    box_print(WIN_HELP, 0, GetStringRightAlignXOffset(0, string, 240) - 4, 0, color, 0, string);
    PutWindowTilemap(WIN_HELP);
    CopyWindowToVram(WIN_HELP, 3);
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
    const u8 *dayOfWeek = GetDayOfWeekString();

    SetWindowBorderStyle(WIN_DIALOG, FALSE, MENU_FRAME_BASE_TILE_NUM, MENU_FRAME_PALETTE_NUM);
    PutWindowTilemap(WIN_TOP);
    //PutWindowTilemap(WIN_BOTTOM);
    PrintTextOnWindow(WIN_DIALOG, 1, gText_PokegearInstructions, 0, 1, 0, NULL);
    box_print(WIN_TOP, 1, GetStringCenterAlignXOffset(1, dayOfWeek, 0x70), 1, sTextColor, 0, dayOfWeek);
    //box_print(WIN_BOTTOM, 1, GetStringCenterAlignXOffset(1, gText_PokegearSelectToChangeMode, 0x70), 5, sTextColor, 0, gText_PokegearSelectToChangeMode);
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
        //FlagSet(FLAG_POKEGEAR_24HR);
    }

    if (gTasks[taskId].tDayOfWeek != gLocalTime.dayOfWeek)
    {
        const u8 *dayOfWeek = GetDayOfWeekString();
        gTasks[taskId].tDayOfWeek = gLocalTime.dayOfWeek;
        FillWindowPixelBuffer(WIN_TOP, 0);
        box_print(WIN_TOP, 1, GetStringCenterAlignXOffset(1, dayOfWeek, 0x70), 1, sTextColor, 0, dayOfWeek);
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
#define tSelectedItem data[1]
#define tScrollTaskId data[2]
#define tScrollOffset data[3]

static void LoadPhoneCard(void)
{
    struct ListMenuTemplate menuTemplate = sPhoneCardListMenuTemplate;
    u8 newTask;

    SetWindowBorderStyle(WIN_DIALOG, FALSE, MENU_FRAME_BASE_TILE_NUM, MENU_FRAME_PALETTE_NUM);
    FillWindowPixelBuffer(WIN_DIALOG, 0x11);
    CopyWindowToVram(WIN_DIALOG, 2);

    newTask = CreateTask(Task_PhoneCard, 0);
    gTasks[newTask].tListMenuTaskId = ListMenuInit(&menuTemplate, 0, 0);
    PrintTextOnWindow(WIN_DIALOG, 1, gText_PokegearWhomDoYouWantToCall, 0, 1, 0, NULL);
    schedule_bg_copy_tilemap_to_vram(0);
    
    gTasks[newTask].tScrollTaskId = 0xFF;
    gTasks[newTask].tScrollOffset = 0;
    PhoneCard_AddScrollIndicators(newTask);
}

static void PhoneCard_AddScrollIndicators(u8 taskId)
{
    if (gTasks[taskId].tScrollTaskId == 0xFF)
        gTasks[taskId].tScrollTaskId = AddScrollIndicatorArrowPairParameterized(SCROLL_ARROW_UP,
                                                                                206,
                                                                                40,
                                                                                104,
                                                                                2,
                                                                                0x13F8,
                                                                                0x13F8,
                                                                                &(gTasks[taskId].tScrollOffset));
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
    s32 id = ListMenuHandleInputGetItemId(gTasks[taskId].tListMenuTaskId);
    ListMenuGetScrollAndRow(gTasks[taskId].tListMenuTaskId, &(gTasks[taskId].tScrollOffset), &(gTasks[taskId].tSelectedItem));
    switch(id)
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
    SetWindowBorderStyle(WIN_CONFIRM, FALSE, MENU_FRAME_BASE_TILE_NUM, MENU_FRAME_PALETTE_NUM);
    PrintMenuTable(WIN_CONFIRM, ARRAY_COUNT(sCallOptions), sCallOptions);
    InitMenuInUpperLeftCornerPlaySoundWhenAPressed(WIN_CONFIRM, ARRAY_COUNT(sCallOptions), 0);
    schedule_bg_copy_tilemap_to_vram(0);
    gTasks[taskId].func = PhoneCard_ConfirmCallProcessInput;
}

static void PhoneCard_ConfirmCallProcessInput(u8 taskId)
{
    s8 inputOptionId = ProcessMenuInput_other();

    switch(inputOptionId)
    {
        case MENU_NOTHING_CHOSEN:
            break;
        case MENU_B_PRESSED:
            PlaySE(SE_SELECT);
            sub_8197434(WIN_CONFIRM, TRUE);
            PhoneCard_ReturnToMain(taskId);
            break;

        default:
            PlaySE(SE_SELECT);
            sub_8197434(WIN_CONFIRM, TRUE);
            gTasks[taskId].func = sCallOptions[inputOptionId].func.void_u8;
            break;
    }
}

static void PhoneCard_ReturnToMain(u8 taskId)
{
    ShowHelpBar(gText_PhoneCardHelp1);
    PhoneCard_AddScrollIndicators(taskId);
    sPokegearStruct.canSwitchCards = TRUE;
    gTasks[taskId].func = Task_PhoneCard;
}

static void PhoneCard_PlaceCall(u8 taskId)
{
    ShowHelpBar(gText_ANext);
    // TODO
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

#define tCurrentLine data[0]
#define tNextLine data[1]
#define tNumLinesPrinted data[2]
#define tScrollDistance data[3]
#define tTextDelay data[4]
#define tMiscCounter data[5]

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
    //PutWindowTilemap(WIN_TOP);
    PutWindowTilemap(WIN_BOTTOM);
    //box_print(WIN_TOP, 1, GetStringCenterAlignXOffset(1, gText_PokegearRadioTuning, 0x70), 5, sTextColor, 0, gText_PokegearRadioTuning);
    FillWindowPixelBuffer(WIN_BOTTOM, 0x00);
    CopyWindowToVram(WIN_BOTTOM, 2);
    schedule_bg_copy_tilemap_to_vram(0);

    LoadSpriteSheet(&sSpriteSheet_DigitTiles);

    newTask = CreateTask(Task_RadioCard, 0);

    gTasks[newTask].tCurrentLine = NO_RADIO_SHOW;
    gTasks[newTask].tNextLine = NO_RADIO_SHOW;
    gTasks[newTask].tNumLinesPrinted = 0;
    gTasks[newTask].tScrollDistance = 0;
    gTasks[newTask].tTextDelay = 0;
    gTasks[newTask].tMiscCounter = 0;

    UpdateRadioStation(newTask, sPokegearStruct.currentRadioStation);

    for (i = 0; i < 5; i++)
    {
        spriteId = CreateSprite(&sSpriteTemplate_Digits, radioX[i], 52, 0);
        gSprites[spriteId].tPosition = i;
        gSprites[spriteId].callback = SpriteCB_RadioDigits;
        gTasks[newTask].data[i + 6] = spriteId;
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

static const struct RadioStation sRadioStationData[] = {
    { FREQ(4.5), REGION_JOHTO, LoadStation_PokemonChannel },
    { FREQ(7.5), REGION_JOHTO, LoadStation_PokemonMusic },
    { FREQ(8.5), REGION_JOHTO, LoadStation_LuckyChannel },
    { FREQ(10.5), REGION_JOHTO, LoadStation_BuenasPassword },
    { FREQ(13.5), REGION_JOHTO, LoadStation_UnownRadio },
    { FREQ(20.5), REGION_JOHTO, LoadStation_EvolutionRadio },
    { 0xFF, 0xFF, NULL }
};

void DrawStationTitle(const u8 *title)
{
    box_print(WIN_BOTTOM, 1, GetStringCenterAlignXOffset(1, title, 0x70), 5, sTextColor, 0, title);
}

void ClearStationTitle(void)
{
    FillWindowPixelBuffer(WIN_BOTTOM, 0);
    CopyWindowToVram(WIN_BOTTOM, 2);
}

static void UpdateRadioStation(u8 taskId, u8 frequency)
{
    u16 song = MUS_DUMMY;
    const u8 *title = NULL;
    const struct RadioStation *station;
    u8 region = GetCurrentRegion();

    for (station = &sRadioStationData[0]; station->frequency != 0xFF; station++)
    {
        if (station->frequency == frequency && station->region == region)
            break;
    }

    if (station->frequency != 0xFF)
    {
        gTasks[taskId].tNumLinesPrinted = 0;
        title = station->loadFunc(taskId, WIN_DIALOG);

        if (title != NULL)
        {
            DrawStationTitle(title);
        }
    }
    else
    {
        gTasks[taskId].tCurrentLine = NO_RADIO_SHOW;
        gTasks[taskId].tNextLine = NO_RADIO_SHOW;
        gTasks[taskId].tNumLinesPrinted = 0;
        ClearStationTitle();
        FillWindowPixelBuffer(WIN_DIALOG, 0x11);
        CopyWindowToVram(WIN_DIALOG, 2);
        PlayNewMapMusic(MUS_DUMMY);
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
    else if (gTasks[taskId].tCurrentLine != NO_RADIO_SHOW)
    {
        PlayRadioShow(taskId, WIN_DIALOG);
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
    {
        Overworld_PlaySpecialMapMusic();
    }

    FreeSpriteTilesByTag(12345);
    
    for (i = 0; i < 5; i++)
    {
        DestroySprite(&gSprites[gTasks[taskId].data[i + 6]]);
    }

    DestroyTask(taskId);
}

#undef WIN_DIALOG
#undef WIN_TOP
#undef WIN_BOTTOM
