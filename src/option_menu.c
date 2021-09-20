#include "global.h"
#include "option_menu.h"
#include "main.h"
#include "menu.h"
#include "scanline_effect.h"
#include "palette.h"
#include "sprite.h"
#include "task.h"
#include "bg.h"
#include "gpu_regs.h"
#include "window.h"
#include "text.h"
#include "text_window.h"
#include "international_string_util.h"
#include "strings.h"
#include "string_util.h"
#include "gba/m4a_internal.h"
#include "constants/rgb.h"

// Task data
enum
{
    TD_STATE,
    TD_MENUSELECTION,
    TD_TEXTSPEED,
    TD_BATTLESCENE,
    TD_BATTLESTYLE,
    TD_SOUND,
    TD_BUTTONMODE,
    TD_FRAMETYPE,
};

// Menu items
enum
{
    MENUITEM_TEXTSPEED,
    MENUITEM_BATTLESCENE,
    MENUITEM_BATTLESTYLE,
    MENUITEM_SOUND,
    MENUITEM_BUTTONMODE,
    MENUITEM_FRAMETYPE,
    MENUITEM_CANCEL,
    MENUITEM_COUNT,
};

// Window Ids
enum
{
    WIN_TEXT_OPTION,
    WIN_OPTIONS,
    WIN_CONTROLS,
};

enum
{
    OPTION_MENU_ACTION_DO_NOTHING,
    OPTION_MENU_ACTION_EXIT,
    OPTION_MENU_ACTION_CHANGE_FRAME,
    OPTION_MENU_ACTION_UPDATE_DISPLAY,
    OPTION_MENU_ACTION_CHANGE_TEXT
};

// this file's functions
static void Task_OptionMenuFadeIn(u8 taskId);
static u8   OptionMenu_ProcessInput(u8 taskId);
static void Task_OptionMenuSave(u8 taskId);
static void HighlightOptionMenuItem(u8 selection);
static void OptionMenu_PickSwitchCancel(void);
static u8   TextSpeed_ProcessInput(u8 selection);
static void TextSpeed_DrawChoices(u8 selection);
static u8   BattleScene_ProcessInput(u8 selection);
static void BattleScene_DrawChoices(u8 selection);
static u8   BattleStyle_ProcessInput(u8 selection);
static void BattleStyle_DrawChoices(u8 selection);
static u8   Sound_ProcessInput(u8 selection);
static void Sound_DrawChoices(u8 selection);
static u8   FrameType_ProcessInput(u8 selection);
static void FrameType_DrawChoices(u8 selection);
static u8   ButtonMode_ProcessInput(u8 selection);
static void ButtonMode_DrawChoices(u8 selection);
static void DrawTextOption(void);
static void DrawOptionMenuTexts(void);
static void DrawBgWindowFrames(void);
static void BufferOptionMenuString(u8 taskId, u8 selection);

static const struct WindowTemplate sOptionMenuWinTemplates[] =
{
    {
        .bg = 1,
        .tilemapLeft = 2,
        .tilemapTop = 3,
        .width = 26,
        .height = 2,
        .paletteNum = 1,
        .baseBlock = 2
    },
    {
        .bg = 0,
        .tilemapLeft = 2,
        .tilemapTop = 7,
        .width = 26,
        .height = 12,
        .paletteNum = 1,
        .baseBlock = 0x36
    },
    {
        .bg = 2,
        .tilemapLeft = 0,
        .tilemapTop = 0,
        .width = 30,
        .height = 2,
        .paletteNum = 0xF,
        .baseBlock = 0x16e
    },
    DUMMY_WIN_TEMPLATE
};

static const struct BgTemplate sOptionMenuBgTemplates[] =
{
   {
       .bg = 1,
       .charBaseIndex = 1,
       .mapBaseIndex = 30,
       .screenSize = 0,
       .paletteMode = 0,
       .priority = 0,
       .baseTile = 0
   },
   {
       .bg = 0,
       .charBaseIndex = 1,
       .mapBaseIndex = 31,
       .screenSize = 0,
       .paletteMode = 0,
       .priority = 1,
       .baseTile = 0
   },
   {
       .bg = 2,
       .charBaseIndex = 1,
       .mapBaseIndex = 29,
       .screenSize = 0,
       .paletteMode = 0,
       .priority = 2,
       .baseTile = 0
   },
};

static const u16 sOptionMenuText_Pal[] = INCBIN_U16("graphics/misc/option_menu_text.gbapal");

static const u8 *const sOptionMenuItemsNames[MENUITEM_COUNT] =
{
    [MENUITEM_TEXTSPEED]   = gText_TextSpeed,
    [MENUITEM_BATTLESCENE] = gText_BattleScene,
    [MENUITEM_BATTLESTYLE] = gText_BattleStyle,
    [MENUITEM_SOUND]       = gText_Sound,
    [MENUITEM_BUTTONMODE]  = gText_ButtonMode,
    [MENUITEM_FRAMETYPE]   = gText_Frame,
    [MENUITEM_CANCEL]      = gText_OptionMenuCancel,
};

static const u8 *const sTextSpeedOptions[] =
{
    gText_TextSpeedSlow, 
    gText_TextSpeedMid, 
    gText_TextSpeedFast
};

static const u8 *const sBattleSceneOptions[] =
{
    gText_BattleSceneOn, 
    gText_BattleSceneOff
};

static const u8 *const sBattleStyleOptions[] =
{
    gText_BattleStyleShift,
    gText_BattleStyleSet
};

static const u8 *const sSoundOptions[] =
{
    gText_SoundMono, 
    gText_SoundStereo
};

static const u8 *const sButtonTypeOptions[] =
{
    gText_ButtonTypeNormal,
	gText_ButtonTypeLR,
	gText_ButtonTypeLEqualsA
};

static const u16 sOptionMenuItemCounts[MENUITEM_COUNT] = {
    [MENUITEM_TEXTSPEED] =      ARRAY_COUNT(sTextSpeedOptions),
    [MENUITEM_BATTLESCENE] =    ARRAY_COUNT(sBattleSceneOptions),
    [MENUITEM_BATTLESTYLE] =    ARRAY_COUNT(sBattleStyleOptions),
    [MENUITEM_SOUND] =          ARRAY_COUNT(sSoundOptions),
    [MENUITEM_BUTTONMODE] =     ARRAY_COUNT(sButtonTypeOptions),
    [MENUITEM_FRAMETYPE] =      WINDOW_FRAMES_COUNT
};

static const u16 sOptionMenuPalette[] = INCBIN_U16("graphics/misc/option_menu.gbapal");
static const u8 sOptionMenuPickSwitchCancelTextColor[] = {TEXT_DYNAMIC_COLOR_6, TEXT_COLOR_WHITE, TEXT_COLOR_DARK_GRAY};

// code
static void MainCB2(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

static void VBlankCB(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

void CB2_InitOptionMenu(void)
{
    switch (gMain.state)
    {
    default:
    case 0:
        SetVBlankCallback(NULL);
        break;
    case 1:
        DmaClearLarge16(3, (void*)(VRAM), VRAM_SIZE, 0x1000);
        DmaClear32(3, OAM, OAM_SIZE);
        DmaClear16(3, PLTT, PLTT_SIZE);
        gPlttBufferUnfaded[0] = RGB_BLACK;
        SetGpuReg(REG_OFFSET_DISPCNT, 0);
        ResetBgsAndClearDma3BusyFlags(0);
        InitBgsFromTemplates(0, sOptionMenuBgTemplates, ARRAY_COUNT(sOptionMenuBgTemplates));
        ChangeBgX(0, 0, 0);
        ChangeBgY(0, 0, 0);
        ChangeBgX(1, 0, 0);
        ChangeBgY(1, 0, 0);
        ChangeBgX(2, 0, 0);
        ChangeBgY(2, 0, 0);
        ChangeBgX(3, 0, 0);
        ChangeBgY(3, 0, 0);
        InitWindows(sOptionMenuWinTemplates);
        DeactivateAllTextPrinters();
        SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG0 | BLDCNT_EFFECT_BLEND | BLDCNT_EFFECT_LIGHTEN);
        SetGpuReg(REG_OFFSET_BLDY, BLDCNT_TGT1_BG1);
        SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG0);
        SetGpuReg(REG_OFFSET_WINOUT, WINOUT_WIN01_BG0 | WINOUT_WIN01_BG1 | WINOUT_WIN01_BG2 | WINOUT_WIN01_CLR);
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_1D_MAP | DISPCNT_OBJ_ON | DISPCNT_WIN0_ON);
        ShowBg(0);
        ShowBg(1);
        ShowBg(2);
        break;
    case 2:
        ResetSpriteData();
        ResetPaletteFade();
        FreeAllSpritePalettes();
        ResetTasks();
        ScanlineEffect_Stop();
        break;
    case 3:
        LoadBgTiles(1, GetWindowFrameTilesPal(gSaveBlock2Ptr->optionsWindowFrameType)->tiles, 0x120, 0x1AA);
        break;
    case 4:
        LoadPalette(GetWindowFrameTilesPal(gSaveBlock2Ptr->optionsWindowFrameType)->pal, 0x20, 0x20);
        break;
    case 5:
        LoadPalette(sOptionMenuPalette, 0x10, 0x20);
        LoadPalette(GetTextWindowPalette(2), 0xF0, 0x20);
        break;
    case 6:
        LoadThinWindowBorderGfx(0, 0x1B3, 0x30);
        break;
    case 7:
        DrawTextOption();
        break;
    case 8:
        DrawBgWindowFrames();
    case 9:
        DrawOptionMenuTexts();
        break;
    case 10:
    {
        u8 i;
        u8 taskId = CreateTask(Task_OptionMenuFadeIn, 0);
        gTasks[taskId].data[TD_STATE] = 0;
        gTasks[taskId].data[TD_MENUSELECTION] = 0;
        gTasks[taskId].data[TD_TEXTSPEED] = gSaveBlock2Ptr->optionsTextSpeed;
        gTasks[taskId].data[TD_BATTLESCENE] = gSaveBlock2Ptr->optionsBattleSceneOff;
        gTasks[taskId].data[TD_BATTLESTYLE] = gSaveBlock2Ptr->optionsBattleStyle;
        gTasks[taskId].data[TD_SOUND] = gSaveBlock2Ptr->optionsSound;
        gTasks[taskId].data[TD_BUTTONMODE] = gSaveBlock2Ptr->optionsButtonMode;
        gTasks[taskId].data[TD_FRAMETYPE] = gSaveBlock2Ptr->optionsWindowFrameType;

        for (i = 0; i < MENUITEM_COUNT; i++)
            BufferOptionMenuString(taskId, i);
        break;
    }
    case 11:
        HighlightOptionMenuItem(0);
        break;
    case 12:
        OptionMenu_PickSwitchCancel();
        break;
    case 13:
        SetMainCallback2(MainCB2);
        return;
    }
    gMain.state++;
}

static void OptionMenu_PickSwitchCancel(void)
{
    s32 x = 228 - GetStringWidth(0, gText_PickSwitchCancel, 0);
    FillWindowPixelBuffer(WIN_CONTROLS, PIXEL_FILL(15)); 
    AddTextPrinterParameterized3(WIN_CONTROLS, 0, x, 0, sOptionMenuPickSwitchCancelTextColor, 0, gText_PickSwitchCancel);
    PutWindowTilemap(WIN_CONTROLS);
    CopyWindowToVram(WIN_CONTROLS, COPYWIN_BOTH);
}

static void Task_OptionMenuFadeIn(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    switch (data[TD_STATE])
    {
    case 0:
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0x10, 0, RGB_BLACK);
        SetVBlankCallback(VBlankCB);
        data[TD_STATE]++;
        break;
    case 1:
        if (gPaletteFade.active)
            return;
        data[TD_STATE]++;
        break;
    case 2:
        switch (OptionMenu_ProcessInput(taskId))
        {
        case OPTION_MENU_ACTION_DO_NOTHING:
            break;
        case OPTION_MENU_ACTION_EXIT:
            data[TD_STATE]++;
            break;
        case OPTION_MENU_ACTION_CHANGE_FRAME:
            LoadBgTiles(1, GetWindowFrameTilesPal(data[TD_FRAMETYPE])->tiles, 0x120, 0x1AA);
            LoadPalette(GetWindowFrameTilesPal(data[TD_FRAMETYPE])->pal, 0x20, 0x20);
            // fallthrough
        case OPTION_MENU_ACTION_CHANGE_TEXT:
            BufferOptionMenuString(taskId, data[TD_MENUSELECTION]);
            break;
        case OPTION_MENU_ACTION_UPDATE_DISPLAY:
            HighlightOptionMenuItem(data[TD_MENUSELECTION]);
            break;
        }
        break;
    case 3:
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 0x10, RGB_BLACK);
        data[TD_STATE]++;
        break;
    case 4:
        if (gPaletteFade.active)
            return;
        data[TD_STATE]++;
        break;
    case 5:
        Task_OptionMenuSave(taskId);
        break;
    }
}

static u8 OptionMenu_ProcessInput(u8 taskId)
{
    
    u16* current;
    s16 *data = gTasks[taskId].data;

    if (JOY_REPEAT(DPAD_RIGHT))
    {
        current = &data[data[TD_MENUSELECTION] + TD_TEXTSPEED];
        if (*current == (sOptionMenuItemCounts[data[TD_MENUSELECTION]] - 1))
            *current = 0;
        else
            ++*current;

        if (data[TD_MENUSELECTION] == MENUITEM_FRAMETYPE)
            return OPTION_MENU_ACTION_CHANGE_FRAME;
        else
            return OPTION_MENU_ACTION_CHANGE_TEXT;
    }
    else if (JOY_REPEAT(DPAD_LEFT))
    {
        current = &data[data[TD_MENUSELECTION] + TD_TEXTSPEED];
        if (*current == 0)
            *current = sOptionMenuItemCounts[data[TD_MENUSELECTION]] - 1;
        else
            --*current;
        
        if (data[TD_MENUSELECTION] == MENUITEM_FRAMETYPE)
            return OPTION_MENU_ACTION_CHANGE_FRAME;
        else
            return OPTION_MENU_ACTION_CHANGE_TEXT;
    }
    else if (JOY_REPEAT(DPAD_UP))
    {
        if (data[TD_MENUSELECTION] > 0)
            data[TD_MENUSELECTION]--;
        else
            data[TD_MENUSELECTION] = MENUITEM_CANCEL;
        return OPTION_MENU_ACTION_UPDATE_DISPLAY;        
    }
    else if (JOY_REPEAT(DPAD_DOWN))
    {
        if (data[TD_MENUSELECTION] < MENUITEM_CANCEL)
            data[TD_MENUSELECTION]++;
        else
            data[TD_MENUSELECTION] = 0;
        HighlightOptionMenuItem(data[TD_MENUSELECTION]);
        return OPTION_MENU_ACTION_UPDATE_DISPLAY;
    }
    else if (JOY_NEW(A_BUTTON))
    {
        if (data[TD_MENUSELECTION] == MENUITEM_CANCEL)
            return OPTION_MENU_ACTION_EXIT;
    }
    else if (JOY_NEW(B_BUTTON))
    {
        return OPTION_MENU_ACTION_EXIT;
    }

    return OPTION_MENU_ACTION_DO_NOTHING;
}

static void Task_OptionMenuSave(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    SetMainCallback2(gMain.savedCallback);
    FreeAllWindowBuffers();
    gSaveBlock2Ptr->optionsTextSpeed = data[TD_TEXTSPEED];
    gSaveBlock2Ptr->optionsBattleSceneOff = data[TD_BATTLESCENE];
    gSaveBlock2Ptr->optionsBattleStyle = data[TD_BATTLESTYLE];
    gSaveBlock2Ptr->optionsSound = data[TD_SOUND];
    gSaveBlock2Ptr->optionsButtonMode = data[TD_BUTTONMODE];
    gSaveBlock2Ptr->optionsWindowFrameType = data[TD_FRAMETYPE];
    SetPokemonCryStereo(data[TD_SOUND]);
    DestroyTask(taskId);
}

static void HighlightOptionMenuItem(u8 index)
{
    u16 maxLetterHeight, y;
    
    maxLetterHeight = GetFontAttribute(2, FONTATTR_MAX_LETTER_HEIGHT);
    y = index * (maxLetterHeight - 1) + 58;
    SetGpuReg(REG_OFFSET_WIN0H, WIN_RANGE(16, 224));
    SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE(y, y + maxLetterHeight));
}

static void DrawOptionMenuChoice(const u8 *text, u8 x, u8 y, u8 style)
{
    u8 dst[16];
    u16 i;

    for (i = 0; *text != EOS && i <= 14; i++)
        dst[i] = *(text++);

    if (style != 0)
    {
        dst[2] = 5;
        dst[5] = 4;
    }

    dst[i] = EOS;
    AddTextPrinterParameterized(WIN_OPTIONS, 2, dst, x, y + 1, TEXT_SPEED_FF, NULL);
}

static void BufferOptionMenuString(u8 taskId, u8 selection)
{
    s16 *data = gTasks[taskId].data;
    u8 str[20];
    u8 x, y;
    u8 *strEnd;

    const u8 optionsColor[] = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_LIGHT_RED, TEXT_COLOR_RED};
    x = 130;
    y = ((GetFontAttribute(2, FONTATTR_MAX_LETTER_HEIGHT) - 1) * selection) + 2;
    FillWindowPixelRect(1, 1, x, y, 0x46, GetFontAttribute(2, FONTATTR_MAX_LETTER_HEIGHT));

    switch (selection)
    {
    case MENUITEM_TEXTSPEED:
        AddTextPrinterParameterized3(1, 2, x, y, optionsColor, -1, sTextSpeedOptions[data[TD_TEXTSPEED]]);
        break;
    case MENUITEM_BATTLESCENE:
        AddTextPrinterParameterized3(1, 2, x, y, optionsColor, -1, sBattleSceneOptions[data[TD_BATTLESCENE]]);
        break;
    case MENUITEM_BATTLESTYLE:
        AddTextPrinterParameterized3(1, 2, x, y, optionsColor, -1, sBattleStyleOptions[data[TD_BATTLESTYLE]]);
        break;
    case MENUITEM_SOUND:
        AddTextPrinterParameterized3(1, 2, x, y, optionsColor, -1, sSoundOptions[data[TD_SOUND]]);
        break;
    case MENUITEM_BUTTONMODE:
        AddTextPrinterParameterized3(1, 2, x, y, optionsColor, -1, sButtonTypeOptions[data[TD_BUTTONMODE]]);
        break;
    case MENUITEM_FRAMETYPE:
        strEnd = StringCopy(str, gText_FrameType);
        *(strEnd++) = CHAR_SPACE;
        ConvertIntToDecimalStringN(strEnd, data[TD_FRAMETYPE] + 1, STR_CONV_MODE_LEFT_ALIGN, 2);
        AddTextPrinterParameterized3(1, 2, x, y, optionsColor, TEXT_SPEED_FF, str);
        break;
    default:
        break;
    }
    PutWindowTilemap(WIN_OPTIONS);
    CopyWindowToVram(WIN_OPTIONS, COPYWIN_BOTH);
}

static void DrawTextOption(void)
{
    FillWindowPixelBuffer(WIN_TEXT_OPTION, PIXEL_FILL(1));
    AddTextPrinterParameterized(WIN_TEXT_OPTION, 2, gText_Option, 8, 1, TEXT_SPEED_FF, NULL);
    PutWindowTilemap(WIN_TEXT_OPTION);
    CopyWindowToVram(WIN_TEXT_OPTION, COPYWIN_BOTH);
}

static void DrawOptionMenuTexts(void)
{
    u8 i;

    FillWindowPixelBuffer(WIN_OPTIONS, PIXEL_FILL(1));
    for (i = 0; i < MENUITEM_COUNT; i++)
    {
        AddTextPrinterParameterized(WIN_OPTIONS, 2, sOptionMenuItemsNames[i], 8, ((i * (GetFontAttribute(2, FONTATTR_MAX_LETTER_HEIGHT))) + 2) - i, TEXT_SPEED_FF, NULL);
    }
}

#define TILE_TOP_CORNER_L 0x1A2
#define TILE_TOP_EDGE     0x1A3
#define TILE_TOP_CORNER_R 0x1A4
#define TILE_LEFT_EDGE    0x1A5
#define TILE_RIGHT_EDGE   0x1A7
#define TILE_BOT_CORNER_L 0x1A8
#define TILE_BOT_EDGE     0x1A9
#define TILE_BOT_CORNER_R 0x1AA

static void DrawBgWindowFrames(void)
{
    FillBgTilemapBufferRect(1, 0x1B3, 1, 2, 1, 1, 3);
    FillBgTilemapBufferRect(1, 0x1B4, 2, 2, 27, 1, 3);
    FillBgTilemapBufferRect(1, 0x1B5, 28, 2, 1, 1, 3);
    FillBgTilemapBufferRect(1, 0x1B6, 1, 3, 1, 2, 3);
    FillBgTilemapBufferRect(1, 0x1B8, 28, 3, 1, 2, 3);
    FillBgTilemapBufferRect(1, 0x1B9, 1, 5, 1, 1, 3);
    FillBgTilemapBufferRect(1, 0x1BA, 2, 5, 27, 1, 3);
    FillBgTilemapBufferRect(1, 0x1BB, 28, 5, 1, 1, 3);
    FillBgTilemapBufferRect(1, 0x1AA, 1, 6, 1, 1, 2);
    FillBgTilemapBufferRect(1, 0x1AB, 2, 6, 26, 1, 2);
    FillBgTilemapBufferRect(1, 0x1AC, 28, 6, 1, 1, 2);
    FillBgTilemapBufferRect(1, 0x1AD, 1, 7, 1, 16, 2);
    FillBgTilemapBufferRect(1, 0x1AF, 28, 7, 1, 16, 2);
    FillBgTilemapBufferRect(1, 0x1B0, 1, 19, 1, 1, 2);
    FillBgTilemapBufferRect(1, 0x1B1, 2, 19, 26, 1, 2);
    FillBgTilemapBufferRect(1, 0x1B2, 28, 19, 1, 1, 2);

    CopyBgTilemapBufferToVram(1);
}
