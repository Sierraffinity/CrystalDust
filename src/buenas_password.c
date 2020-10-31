#include "global.h"
#include "main.h"
#include "battle.h"
#include "buenas_password.h"
#include "data.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "international_string_util.h"
#include "item.h"
#include "item_menu.h"
#include "list_menu.h"
#include "malloc.h"
#include "menu.h"
#include "menu_helpers.h"
#include "radio.h"
#include "random.h"
#include "region_map.h"
#include "script.h"
#include "script_menu.h"
#include "sound.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "text_window.h"
#include "constants/items.h"
#include "constants/moves.h"
#include "constants/region_map_sections.h"
#include "constants/songs.h"
#include "constants/species.h"
#include "constants/vars.h"

static EWRAM_DATA struct ListMenuItem *sPasswordListMenuItems;
static EWRAM_DATA u8 sPointsWindowId = 0;

enum {
    PASS_SPECIES,
    PASS_ITEM,
    PASS_MAPSEC,
    PASS_TYPE,
    PASS_MOVE,
    PASS_STATION
};

static const struct {
    u8 type;
    u16 values[3];
} sBuenasPasswords[] = {
    { PASS_SPECIES, { SPECIES_CYNDAQUIL,    SPECIES_TOTODILE,           SPECIES_CHIKORITA } },
    { PASS_ITEM,    { ITEM_FRESH_WATER,     ITEM_SODA_POP,              ITEM_LEMONADE } },
    { PASS_ITEM,    { ITEM_POTION,          ITEM_ANTIDOTE,              ITEM_PARALYZE_HEAL } },
    { PASS_ITEM,    { ITEM_POKE_BALL,       ITEM_GREAT_BALL,            ITEM_ULTRA_BALL } },
    { PASS_SPECIES, { SPECIES_PIKACHU,      SPECIES_RATTATA,            SPECIES_GEODUDE } },
    { PASS_SPECIES, { SPECIES_HOOTHOOT,     SPECIES_SPINARAK,           SPECIES_DROWZEE } },
    { PASS_MAPSEC,  { MAPSEC_NEW_BARK_TOWN, MAPSEC_CHERRYGROVE_CITY,    MAPSEC_AZALEA_TOWN } },
    { PASS_TYPE,    { TYPE_FLYING,          TYPE_BUG,                   TYPE_GRASS } },
    { PASS_MOVE,    { MOVE_TACKLE,          MOVE_GROWL,                 MOVE_MUD_SLAP } },
    { PASS_ITEM,    { ITEM_X_ATTACK,        ITEM_X_DEFEND,              ITEM_X_SPEED } },
    { PASS_STATION, { OAKS_POKEMON_TALK,    POKEMON_MUSIC,              LUCKY_CHANNEL } }
};

// static functions
static void PasswordMenu_ProcessInput(u8 taskId);
static void PasswordMenu_Exit(u8 taskId, s32 chosenIndex);

// const data
static const struct ListMenuTemplate sPasswordListMenuItemsTemplate =
{
    .items = NULL,
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
    .itemPrintFunc = NULL,
    .totalItems = 0,
    .maxShowed = 0,
    .windowId = 0,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 2,
    .cursorPal = 2,
    .fillValue = 1,
    .cursorShadowPal = 3,
    .lettersSpacing = 0,
    .itemVerticalPadding = 2,
    .scrollMultiple = FALSE,
    .fontId = 2
};

#define tIndex data[0]
#define tListMenuWindowId data[1]
#define tListMenuTaskId data[2]

void BuenasPasswordMultichoice(void)
{
    struct WindowTemplate passwordMenuWindow =
    {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 1,
        .width = 0,
        .height = ARRAY_COUNT(sBuenasPasswords[0].values) * 2,
        .paletteNum = 15,
        .baseBlock = 0x0001
    };

    u16 password = VarGet(VAR_BUENAS_PASSWORD);
    u8 category = password >> 8;
    u8 taskId;
    s32 pixelWidth, i;

    sPasswordListMenuItems = AllocZeroed(sizeof(struct ListMenuItem) * ARRAY_COUNT(sBuenasPasswords[0].values));
    
    for (i = 0; i < ARRAY_COUNT(sBuenasPasswords[0].values); i++)
    {
        sPasswordListMenuItems[i].name = GetBuenasPassword(category, i);
        sPasswordListMenuItems[i].id = i;

        pixelWidth = DisplayTextAndGetWidth(sPasswordListMenuItems[i].name, pixelWidth);
    }

    passwordMenuWindow.width = ConvertPixelWidthToTileWidth(pixelWidth);

    taskId = CreateTask(PasswordMenu_ProcessInput, 0);
    gTasks[taskId].tIndex = password & 0xFF;
    gTasks[taskId].tListMenuWindowId = AddWindow(&passwordMenuWindow);
    DrawStdFrameWithCustomTileAndPalette(gTasks[taskId].tListMenuWindowId, FALSE, STD_WINDOW_BASE_TILE_NUM, STD_WINDOW_PALETTE_NUM);
    ScheduleBgCopyTilemapToVram(0);

    gMultiuseListMenuTemplate = sPasswordListMenuItemsTemplate;
    gMultiuseListMenuTemplate.windowId = gTasks[taskId].tListMenuWindowId;
    gMultiuseListMenuTemplate.totalItems = ARRAY_COUNT(sBuenasPasswords[0].values);
    gMultiuseListMenuTemplate.items = sPasswordListMenuItems;
    gMultiuseListMenuTemplate.maxShowed = ARRAY_COUNT(sBuenasPasswords[0].values);

    gTasks[taskId].tListMenuTaskId = ListMenuInit(&gMultiuseListMenuTemplate, 0, 0);
}

static void PasswordMenu_ProcessInput(u8 taskId)
{
    s16 *data;
    s32 id;

    data = gTasks[taskId].data;
    id = ListMenu_ProcessInput(tListMenuTaskId);
    switch (id)
    {
    case LIST_NOTHING_CHOSEN:
    case LIST_CANCEL:
        break;
    default:
        PlaySE(SE_SELECT);
        PasswordMenu_Exit(taskId, id);
        break;
    }
}

static void PasswordMenu_Exit(u8 taskId, s32 chosenIndex)
{
    s16 *data = gTasks[taskId].data;

    gSpecialVar_Result = tIndex == chosenIndex;

    DestroyListMenuTask(tListMenuTaskId, NULL, NULL);
    ClearStdWindowAndFrameToTransparent(tListMenuWindowId, FALSE);
    ClearWindowTilemap(tListMenuWindowId);
    ScheduleBgCopyTilemapToVram(0);
    RemoveWindow(tListMenuWindowId);
    EnableBothScriptContexts();
    DestroyTask(taskId);
}

#undef tIndex
#undef tListMenuTaskId

void PrintPointsString(u32 pointAmount)
{
    u8 windowId;
    int width;

    ConvertIntToDecimalStringN(gStringVar1, pointAmount, STR_CONV_MODE_RIGHT_ALIGN, 4);
    StringExpandPlaceholders(gStringVar4, gText_Var1Points);
    width = GetStringWidth(0, gStringVar4, 0);
    windowId = sPointsWindowId;
    AddTextPrinterParameterized(windowId, 0, gStringVar4, 64 - width, 0xC, 0, NULL);
}

void ShowPointsWindow(u32 pointAmount, u8 x, u8 y)
{
    struct WindowTemplate template;

    SetWindowTemplateFields(&template, 0, x + 1, y + 1, 8, 3, 0xF, 0x20);
    sPointsWindowId = AddWindow(&template);
    FillWindowPixelBuffer(sPointsWindowId, 0);
    PutWindowTilemap(sPointsWindowId);
    LoadThinWindowBorderGfx(sPointsWindowId, 0x21D, 0xD0);
    DrawStdFrameWithCustomTileAndPalette(sPointsWindowId, FALSE, 0x21D, 0xD);
    AddTextPrinterParameterized(sPointsWindowId, 2, gText_Points, 0, 0, 0xFF, 0);
    PrintPointsString(pointAmount);
}

void ShowPointsWindowAtTopLeft(void)
{
    ShowPointsWindow(VarGet(VAR_BLUE_CARD_BALANCE), 0, 0);
}

void UpdatePointsWindow(void)
{
    PrintPointsString(VarGet(VAR_BLUE_CARD_BALANCE));
}

void HidePointsWindow(void)
{
    ClearWindowTilemap(sPointsWindowId);
    ClearStdWindowAndFrameToTransparent(sPointsWindowId, TRUE);
    RemoveWindow(sPointsWindowId);
}

const u8 *GetBuenasPassword(u8 category, u8 index)
{
    const u8 *string;
    u16 value;

    if (category > ARRAY_COUNT(sBuenasPasswords))
    {
        category = 0;
    }

    if (index > ARRAY_COUNT(sBuenasPasswords[0].values))
    {
        index = 0;
    }

    value = sBuenasPasswords[category].values[index];

    switch (sBuenasPasswords[category].type)
    {
        case PASS_SPECIES:
            string = gSpeciesNames[value];
            break;
        case PASS_ITEM:
            string = ItemId_GetName(value);
            break;
        case PASS_MAPSEC:
            string = gRegionMapEntries[value].name;
            break;
        case PASS_TYPE:
            string = gTypeNames[value];
            break;
        case PASS_MOVE:
            string = gMoveNames[value];
            break;
        case PASS_STATION:
            string = gRadioShowNames[value];
            break;
    }

    return string;
}

u16 GenerateRandomBuenasPassword(void)
{
    return (Random() % ARRAY_COUNT(sBuenasPasswords)) << 8 | (Random() % ARRAY_COUNT(sBuenasPasswords[0].values));
}
