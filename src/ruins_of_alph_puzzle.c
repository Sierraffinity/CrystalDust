#include "global.h"
#include "malloc.h"
#include "bg.h"
#include "decompress.h"
#include "event_data.h"
#include "gpu_regs.h"
#include "international_string_util.h"
#include "main.h"
#include "menu.h"
#include "menu_helpers.h"
#include "overworld.h"
#include "palette.h"
#include "random.h"
#include "ruins_of_alph_puzzle.h"
#include "script.h"
#include "sound.h"
#include "sprite.h"
#include "task.h"
#include "text.h"
#include "text_window.h"
#include "window.h"
#include "constants/rgb.h"
#include "constants/songs.h"

// In order to invoke the Ruins of Alph puzzle, it should be launched via a normal script like the example below.
// The puzzle id is specified by VAR_0x8004. (0 = kabuto, 1 = aerodactyl, 2 = omanyte, 3 = ho-oh)
//
// ...
// setvar VAR_0x8004, 1
// special DoRuinsOfAlphPuzzle
// waitstate
// compare VAR_RESULT, 1
// goto_if_eq PuzzleCompleted
// ...

#define ALPH_PUZZLE_BG_BASE 2

#define ALPH_PUZZLE_WIN_HELP 0

#define TAG_PUZZLE_PIECE 500
#define TAG_PUZZLE_CURSOR 501

#define NUM_PUZZLE_PIECES 16

enum
{
    PUZZLE_KABUTO,
    PUZZLE_AERODACTYL,
    PUZZLE_OMANYTE,
    PUZZLE_HO_OH,
};

enum
{
    ALPH_PUZZLE_STATE_INIT,
    ALPH_PUZZLE_STATE_PROCESS_INPUT,
    ALPH_PUZZLE_STATE_COMPLETED_WAIT_FOR_SOUND,
    ALPH_PUZZLE_STATE_PROCESS_COMPLETED_INPUT,
    ALPH_PUZZLE_STATE_START_EXIT,
    ALPH_PUZZLE_STATE_EXIT,
};

struct RuinsOfAlphPuzzle
{
    u8 state;
    u8 puzzleId;
    u8 pieceSpriteIds[NUM_PUZZLE_PIECES];
    u8 cursorSpriteId;
};

static EWRAM_DATA struct RuinsOfAlphPuzzle *sRuinsOfAlphPuzzle = NULL;

static void FadeToPuzzleScreen(u8 taskId);
static void InitPuzzleScreen(void);
static void LoadPuzzleSpriteGfx(void);
static void InitPuzzleSprites(void);
static void PuzzleMainCallback(void);
static void PuzzleVBlankCallback(void);
static void PuzzleMain(u8 taskId);
static void HandleInput(void);
static void UpdateCursorSelection(void);
static void MoveCursor(int direction);
static u8 FindPuzzlePieceSpriteIdAtCoords(int x, int y, int selectedPieceSpriteId);
static void MovePuzzlePiece(struct Sprite *sprite);
static bool8 IsPuzzleCompleted(void);
static void HandleInput_PuzzleComplete(void);
static void StartExitPuzzle(void);
static void ExitPuzzle(void);
static void ShowHelpBar(const u8 *str);

static const struct BgTemplate sAlphPuzzleBgTemplates[] = {
    {
       .bg = ALPH_PUZZLE_BG_BASE,
       .charBaseIndex = 2,
       .mapBaseIndex = 31,
       .screenSize = 0,
       .paletteMode = 0,
       .priority = 2,
       .baseTile = 0
   },
};

static const struct WindowTemplate sAlphPuzzleWinTemplates[] = {
    {
        .bg = ALPH_PUZZLE_BG_BASE,
        .tilemapLeft = 0,
        .tilemapTop = 0,
        .width = 30,
        .height = 2,
        .paletteNum = 11,
        .baseBlock = 0x73,
    },
    DUMMY_WIN_TEMPLATE,
};

static const u32 sPuzzleBackgroundGfx[] = INCBIN_U32("graphics/ruins_of_alph_puzzle/puzzle_background.4bpp.lz");
static const u16 sPuzzleBackgroundPalette[] = INCBIN_U16("graphics/ruins_of_alph_puzzle/puzzle_background.gbapal");
static const u32 sPuzzleBackgroundTilemap[] = INCBIN_U32("graphics/ruins_of_alph_puzzle/puzzle_background.bin.lz");

static const u32 sKabutoPiecesGfx[] = INCBIN_U32("graphics/ruins_of_alph_puzzle/kabuto_pieces.4bpp.lz");
static const u16 sPuzzlePiecesPalette[] = INCBIN_U16("graphics/ruins_of_alph_puzzle/kabuto_pieces.gbapal");
static const u32 sAerodactylPiecesGfx[] = INCBIN_U32("graphics/ruins_of_alph_puzzle/aerodactyl_pieces.4bpp.lz");
static const u32 sOmanytePiecesGfx[] = INCBIN_U32("graphics/ruins_of_alph_puzzle/omanyte_pieces.4bpp.lz");
static const u32 sHoOhPiecesGfx[] = INCBIN_U32("graphics/ruins_of_alph_puzzle/hooh_pieces.4bpp.lz");

static const u32 sPuzzleCursorGfx[] = INCBIN_U32("graphics/ruins_of_alph_puzzle/puzzle_cursor.4bpp.lz");
static const u16 sPuzzleCursorPalette[] = INCBIN_U16("graphics/ruins_of_alph_puzzle/puzzle_cursor.gbapal");

static const u8 sHelpBarGrabText[] = _("{DPAD_ALL}MOVE  {A_BUTTON}GRAB  {B_BUTTON}EXIT");
static const u8 sHelpBarDropText[] = _("{DPAD_ALL}MOVE  {A_BUTTON}DROP  {B_BUTTON}EXIT");
static const u8 sHelpBarExitText[] = _("{A_BUTTON}{B_BUTTON}EXIT");

static const struct CompressedSpriteSheet sKabutoPiecesSpriteSheet = {
    .data = sKabutoPiecesGfx,
    .size = 0x2000,
    .tag = TAG_PUZZLE_PIECE,
};

static const struct CompressedSpriteSheet sAerodactylPiecesSpriteSheet = {
    .data = sAerodactylPiecesGfx,
    .size = 0x2000,
    .tag = TAG_PUZZLE_PIECE,
};

static const struct CompressedSpriteSheet sOmanytePiecesSpriteSheet = {
    .data = sOmanytePiecesGfx,
    .size = 0x2000,
    .tag = TAG_PUZZLE_PIECE,
};

static const struct CompressedSpriteSheet sHoOhPiecesSpriteSheet = {
    .data = sHoOhPiecesGfx,
    .size = 0x2000,
    .tag = TAG_PUZZLE_PIECE,
};

static const struct CompressedSpriteSheet sPuzzleCursorSpriteSheet = {
    .data = sPuzzleCursorGfx,
    .size = 0x400,
    .tag = TAG_PUZZLE_CURSOR,
};

static const struct SpritePalette sPuzzleSpritePalettes[] = {
    {sPuzzlePiecesPalette, TAG_PUZZLE_PIECE},
    {sPuzzleCursorPalette, TAG_PUZZLE_CURSOR},
    {0},
};

static const struct OamData sPuzzlePieceOamData = {
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = 0,
    .bpp = ST_OAM_4BPP,
    .shape = ST_OAM_SQUARE,
    .x = 0,
    .matrixNum = 0,
    .size = 2,
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0,
};

#define PUZZLE_PIECE_ANIMCMD(n) \
static const union AnimCmd sPuzzlePieceAnimCmd_##n[] =\
{\
    ANIMCMD_FRAME((n) * 16, 0),\
    ANIMCMD_END,\
};

PUZZLE_PIECE_ANIMCMD(0)
PUZZLE_PIECE_ANIMCMD(1)
PUZZLE_PIECE_ANIMCMD(2)
PUZZLE_PIECE_ANIMCMD(3)
PUZZLE_PIECE_ANIMCMD(4)
PUZZLE_PIECE_ANIMCMD(5)
PUZZLE_PIECE_ANIMCMD(6)
PUZZLE_PIECE_ANIMCMD(7)
PUZZLE_PIECE_ANIMCMD(8)
PUZZLE_PIECE_ANIMCMD(9)
PUZZLE_PIECE_ANIMCMD(10)
PUZZLE_PIECE_ANIMCMD(11)
PUZZLE_PIECE_ANIMCMD(12)
PUZZLE_PIECE_ANIMCMD(13)
PUZZLE_PIECE_ANIMCMD(14)
PUZZLE_PIECE_ANIMCMD(15)

static const union AnimCmd *const sPuzzlePieceAnimCmds[] = {
    sPuzzlePieceAnimCmd_0,
    sPuzzlePieceAnimCmd_1,
    sPuzzlePieceAnimCmd_2,
    sPuzzlePieceAnimCmd_3,
    sPuzzlePieceAnimCmd_4,
    sPuzzlePieceAnimCmd_5,
    sPuzzlePieceAnimCmd_6,
    sPuzzlePieceAnimCmd_7,
    sPuzzlePieceAnimCmd_8,
    sPuzzlePieceAnimCmd_9,
    sPuzzlePieceAnimCmd_10,
    sPuzzlePieceAnimCmd_11,
    sPuzzlePieceAnimCmd_12,
    sPuzzlePieceAnimCmd_13,
    sPuzzlePieceAnimCmd_14,
    sPuzzlePieceAnimCmd_15,
};

static const struct SpriteTemplate sPuzzlePieceSpriteTemplate = {
    .tileTag = TAG_PUZZLE_PIECE,
    .paletteTag = TAG_PUZZLE_PIECE,
    .oam = &sPuzzlePieceOamData,
    .anims = sPuzzlePieceAnimCmds,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const union AnimCmd *const sPuzzleCursorAnimCmds[] = {
    sPuzzlePieceAnimCmd_0,
    sPuzzlePieceAnimCmd_1,
};

static const struct SpriteTemplate sPuzzleCursorSpriteTemplate = {
    .tileTag = TAG_PUZZLE_CURSOR,
    .paletteTag = TAG_PUZZLE_CURSOR,
    .oam = &sPuzzlePieceOamData,
    .anims = sPuzzleCursorAnimCmds,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const u8 sPuzzlePieceCoords[][5][2] = {
    {
        {51,   36},
        {51,   68},
        {51,   92},
        {51,  116},
        {51,  140},
    },
    {
        {84,   36},
        {84,   68},
        {84,   92},
        {84,  116},
        {84,  140},
    },
    {
        {108,  36},
        {108,  68},
        {108,  92},
        {108, 116},
        {108, 140},
    },
    {
        {132,  36},
        {132,  68},
        {132,  92},
        {132, 116},
        {132, 140},
    },
    {
        {156,  36},
        {156,  68},
        {156,  92},
        {156, 116},
        {156, 140},
    },
    {
        {189,  36},
        {189,  68},
        {189,  92},
        {189, 116},
        {189, 140},
    },
};

void DoRuinsOfAlphPuzzle(void)
{
    u8 taskId;
    int i;

    ScriptContext1_Stop();
    sRuinsOfAlphPuzzle = AllocZeroed(sizeof(*sRuinsOfAlphPuzzle));
    sRuinsOfAlphPuzzle->puzzleId = gSpecialVar_0x8004;
    for (i = 0; i < NUM_PUZZLE_PIECES; i++)
        sRuinsOfAlphPuzzle->pieceSpriteIds[i] = MAX_SPRITES;

    taskId = CreateTask(FadeToPuzzleScreen, 0);
}

static void FadeToPuzzleScreen(u8 taskId)
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
            SetMainCallback2(InitPuzzleScreen);
            DestroyTask(taskId);
        }
        break;
    }
}

static void InitPuzzleScreen(void)
{
    SetVBlankCallback(NULL);
    ResetAllBgsCoordinates();
    ResetVramOamAndBgCntRegs();
    ResetBgsAndClearDma3BusyFlags(0);

    InitBgsFromTemplates(0, sAlphPuzzleBgTemplates, ARRAY_COUNT(sAlphPuzzleBgTemplates));
    SetBgTilemapBuffer(ALPH_PUZZLE_BG_BASE, AllocZeroed(BG_SCREEN_SIZE));
    DecompressAndLoadBgGfxUsingHeap(ALPH_PUZZLE_BG_BASE, sPuzzleBackgroundGfx, 0xE60, 0, 0);
    CopyToBgTilemapBuffer(ALPH_PUZZLE_BG_BASE, sPuzzleBackgroundTilemap, 0, 0);
    ResetPaletteFade();
    LoadPalette(sPuzzleBackgroundPalette, 0, sizeof(sPuzzleBackgroundPalette));
    InitWindows(sAlphPuzzleWinTemplates);
    DeactivateAllTextPrinters();

    ResetSpriteData();
    FreeAllSpritePalettes();
    LoadPuzzleSpriteGfx();
    InitPuzzleSprites();
    LoadPalette(GetTextWindowPalette(2), 11 * 16, 32); // palette for ALPH_PUZZLE_WIN_HELP
    ShowHelpBar(sHelpBarGrabText);

    CopyBgTilemapBufferToVram(ALPH_PUZZLE_BG_BASE);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 | DISPCNT_OBJ_1D_MAP | DISPCNT_OBJ_ON);
    ShowBg(ALPH_PUZZLE_BG_BASE);
    BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, RGB_BLACK);
    SetVBlankCallback(PuzzleVBlankCallback);
    SetMainCallback2(PuzzleMainCallback);
    CreateTask(PuzzleMain, 0);
}

static void LoadPuzzleSpriteGfx(void)
{
    switch (sRuinsOfAlphPuzzle->puzzleId)
    {
    case PUZZLE_KABUTO:
        LoadCompressedSpriteSheet(&sKabutoPiecesSpriteSheet);
        break;
    case PUZZLE_AERODACTYL:
        LoadCompressedSpriteSheet(&sAerodactylPiecesSpriteSheet);
        break;
    case PUZZLE_OMANYTE:
        LoadCompressedSpriteSheet(&sOmanytePiecesSpriteSheet);
        break;
    case PUZZLE_HO_OH:
        LoadCompressedSpriteSheet(&sHoOhPiecesSpriteSheet);
        break;
    }

    LoadCompressedSpriteSheet(&sPuzzleCursorSpriteSheet);
    LoadSpritePalettes(sPuzzleSpritePalettes);
}

static void InitPuzzleSprites(void)
{
    int i, j;
    int x, y;
    u16 rand;
    int pieceId;
    struct Sprite *sprite;
    s8 puzzleConfig[30];

    for (i = 0; i < 30; i++)
        puzzleConfig[i] = -1;

    for (i = 0; i < NUM_PUZZLE_PIECES; i++)
    {
        while (1)
        {
            rand = Random() % 30;
            if (puzzleConfig[rand] == -1)
            {
                puzzleConfig[rand] = i;
                break;
            }
        }
    }

    for (i = 0; i < 6; i++)
    {
        for (j = 0; j < 5; j++)
        {
            pieceId = puzzleConfig[j * 6 + i];
            if (pieceId != -1)
            {
                x = sPuzzlePieceCoords[i][j][0];
                y = sPuzzlePieceCoords[i][j][1];
                sRuinsOfAlphPuzzle->pieceSpriteIds[pieceId] = CreateSprite(&sPuzzlePieceSpriteTemplate, x, y, 3);
                sprite = &gSprites[sRuinsOfAlphPuzzle->pieceSpriteIds[pieceId]];
                sprite->data[0] = pieceId;
                sprite->data[1] = i;
                sprite->data[2] = j;
                StartSpriteAnim(sprite, pieceId);
            }
        }
    }

    x = sPuzzlePieceCoords[1][1][0];
    y = sPuzzlePieceCoords[1][1][1];
    sRuinsOfAlphPuzzle->cursorSpriteId = CreateSprite(&sPuzzleCursorSpriteTemplate, x, y, 2);
    sprite = &gSprites[sRuinsOfAlphPuzzle->cursorSpriteId];
    sprite->data[0] = 0;
    sprite->data[1] = 1;
    sprite->data[2] = 1;
    sprite->data[3] = 0xFF;
}

static void PuzzleMainCallback(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    RunTextPrinters();
    UpdatePaletteFade();
}

static void PuzzleVBlankCallback(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void PuzzleMain(u8 taskId)
{
    switch (sRuinsOfAlphPuzzle->state)
    {
    case ALPH_PUZZLE_STATE_INIT:
        if (!gPaletteFade.active)
            sRuinsOfAlphPuzzle->state = ALPH_PUZZLE_STATE_PROCESS_INPUT;
        break;
    case ALPH_PUZZLE_STATE_PROCESS_INPUT:
        HandleInput();
        break;
    case ALPH_PUZZLE_STATE_COMPLETED_WAIT_FOR_SOUND:
        if (IsSEPlaying())
            break;

        ShowHelpBar(sHelpBarExitText);
        PlayFanfare(MUS_SLOTS_WIN);
        sRuinsOfAlphPuzzle->state = ALPH_PUZZLE_STATE_PROCESS_COMPLETED_INPUT;
        // fallthrough
    case ALPH_PUZZLE_STATE_PROCESS_COMPLETED_INPUT:
        HandleInput_PuzzleComplete();
        break;
    case ALPH_PUZZLE_STATE_START_EXIT:
        StartExitPuzzle();
        break;
    case ALPH_PUZZLE_STATE_EXIT:
        ExitPuzzle();
        break;
    }
}

static void HandleInput(void)
{
    if (JOY_NEW(A_BUTTON))
    {
        UpdateCursorSelection();
    }
    else if (JOY_NEW(B_BUTTON))
    {
        gSpecialVar_Result = 0;
        sRuinsOfAlphPuzzle->state = ALPH_PUZZLE_STATE_START_EXIT;
    }
    else if (JOY_NEW(DPAD_UP))
    {
        MoveCursor(0);
    }
    else if (JOY_NEW(DPAD_RIGHT))
    {
        MoveCursor(1);
    }
    else if (JOY_NEW(DPAD_DOWN))
    {
        MoveCursor(2);
    }
    else if (JOY_NEW(DPAD_LEFT))
    {
        MoveCursor(3);
    }
}

static void UpdateCursorSelection(void)
{
    u8 spriteId;
    struct Sprite *cursorSprite = &gSprites[sRuinsOfAlphPuzzle->cursorSpriteId];
    
    if (!cursorSprite->data[0])
    {
        spriteId = FindPuzzlePieceSpriteIdAtCoords(cursorSprite->data[1], cursorSprite->data[2], cursorSprite->data[3]);
        if (spriteId != 0xFF)
        {
            cursorSprite->data[0] = 1;
            cursorSprite->data[3] = spriteId;
            gSprites[cursorSprite->data[3]].subpriority = 2;
            StartSpriteAnim(cursorSprite, 1);
            PlaySE(SE_CLICK);
            ShowHelpBar(sHelpBarDropText);
        }
        else
        {
            PlaySE(SE_FAILURE);
        }
    }
    else
    {
        spriteId = FindPuzzlePieceSpriteIdAtCoords(cursorSprite->data[1], cursorSprite->data[2], cursorSprite->data[3]);
        if (spriteId == 0xFF)
        {
            gSprites[cursorSprite->data[3]].subpriority = 3;
            cursorSprite->data[0] = 0;
            cursorSprite->data[3] = 0xFF;
            StartSpriteAnim(cursorSprite, 0);
            PlaySE(SE_UNLOCK);
            if (IsPuzzleCompleted())
            {
                DestroySprite(cursorSprite);
                sRuinsOfAlphPuzzle->state = ALPH_PUZZLE_STATE_COMPLETED_WAIT_FOR_SOUND;
            }
            else
            {
                ShowHelpBar(sHelpBarGrabText);
            }
        }
        else
        {
            PlaySE(SE_FAILURE);
        }
    }
}

static void MoveCursor(int direction)
{
    struct Sprite *cursorSprite;
    int curX, curY;
    int destX, destY;

    cursorSprite = &gSprites[sRuinsOfAlphPuzzle->cursorSpriteId];
    if (cursorSprite->callback != SpriteCallbackDummy)
        return;

    curX = cursorSprite->data[1];
    curY = cursorSprite->data[2];
    destX = curX;
    destY = curY;
    switch (direction)
    {
        case 0: if (curY > 0) destY = curY - 1; break;
        case 1: if (curX < 5) destX = curX + 1; break;
        case 2: if (curY < 4) destY = curY + 1; break;
        case 3: if (curX > 0) destX = curX - 1; break;
    }

    if (curX == destX && curY == destY)
        return;

    cursorSprite->data[4] = destX;
    cursorSprite->data[5] = destY;
    cursorSprite->callback = MovePuzzlePiece;
    if (cursorSprite->data[3] != 0xFF)
    {
        gSprites[cursorSprite->data[3]].data[4] = destX;
        gSprites[cursorSprite->data[3]].data[5] = destY;
        gSprites[cursorSprite->data[3]].callback = MovePuzzlePiece;
    }

    if (cursorSprite->data[0])
        PlaySE(SE_SWITCH);
    else
        PlaySE(SE_BALL_TRAY_EXIT);
}

static u8 FindPuzzlePieceSpriteIdAtCoords(int x, int y, int selectedPieceSpriteId)
{
    int i;
    struct Sprite *sprite;
    u8 spriteId;

    for (i = 0; i < NUM_PUZZLE_PIECES; i++)
    {
        spriteId = sRuinsOfAlphPuzzle->pieceSpriteIds[i];
        sprite = &gSprites[spriteId];
        if (sprite->data[1] == x && sprite->data[2] == y && selectedPieceSpriteId != spriteId)
            return spriteId;
    }

    return 0xFF;
}

static void MovePuzzlePiece(struct Sprite *sprite)
{
    int complete = 0;
    int destXCoord = sPuzzlePieceCoords[sprite->data[4]][sprite->data[5]][0];
    int destYCoord = sPuzzlePieceCoords[sprite->data[4]][sprite->data[5]][1];
    if (sprite->y > destYCoord)
    {
        sprite->y -= 8;
        if (sprite->y <= destYCoord)
        {
            sprite->y = destYCoord;
            complete = 1;
        }
    }
    else if (sprite->x < destXCoord)
    {
        sprite->x += 8;
        if (sprite->x >= destXCoord)
        {
            sprite->x = destXCoord;
            complete = 1;
        }
    }
    else if (sprite->y < destYCoord)
    {
        sprite->y += 8;
        if (sprite->y >= destYCoord)
        {
            sprite->y = destYCoord;
            complete = 1;
        }
    }
    else if (sprite->x > destXCoord)
    {
        sprite->x -= 8;
        if (sprite->x <= destXCoord)
        {
            sprite->x = destXCoord;
            complete = 1;
        }
    }

    if (complete)
    {
        sprite->data[1] = sprite->data[4];
        sprite->data[2] = sprite->data[5];
        sprite->callback = SpriteCallbackDummy;
    }
}

static bool8 IsPuzzleCompleted(void)
{
    int i;
    int correctX, correctY;
    struct Sprite *sprite;

    for (i = 0; i < NUM_PUZZLE_PIECES; i++)
    {
        correctX = i % 4 + 1;
        correctY = i / 4 + 1;
        sprite = &gSprites[sRuinsOfAlphPuzzle->pieceSpriteIds[i]];
        if (sprite->data[1] != correctX || sprite->data[2] != correctY)
            return FALSE;
    }

    return TRUE;
}

static void HandleInput_PuzzleComplete(void)
{
    if (IsFanfareTaskInactive())
    {
        if (JOY_NEW(A_BUTTON | B_BUTTON))
        {
            gSpecialVar_Result = 1;
            sRuinsOfAlphPuzzle->state = ALPH_PUZZLE_STATE_START_EXIT;
        }
    }
}

static void StartExitPuzzle(void)
{
    BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
    sRuinsOfAlphPuzzle->state = ALPH_PUZZLE_STATE_EXIT;
}

static void ExitPuzzle(void)
{
    if (!gPaletteFade.active)
    {
        SetMainCallback2(CB2_ReturnToFieldContinueScriptPlayMapMusic);
        FREE_AND_SET_NULL(sRuinsOfAlphPuzzle);
    }
}

static void ShowHelpBar(const u8 *str)
{
    const u8 color[3] = { 15, 1, 2 };

    FillWindowPixelBuffer(ALPH_PUZZLE_WIN_HELP, 0xFF);
    AddTextPrinterParameterized3(ALPH_PUZZLE_WIN_HELP, 0, GetStringRightAlignXOffset(0, str, 240) - 4, 0, color, 0, str);
    PutWindowTilemap(ALPH_PUZZLE_WIN_HELP);
    CopyWindowToVram(ALPH_PUZZLE_WIN_HELP, 3);
}

#undef ALPH_PUZZLE_BG_BASE
#undef ALPH_PUZZLE_WIN_HELP
#undef TAG_PUZZLE_PIECE
#undef TAG_PUZZLE_CURSOR
#undef NUM_PUZZLE_PIECES
