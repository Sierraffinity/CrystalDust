#include "global.h"
#include "main.h"
#include "palette.h"
#include "scanline_effect.h"
#include "task.h"
#include "title_screen.h"
#include "libgcnmultiboot.h"
#include "malloc.h"
#include "gpu_regs.h"
#include "link.h"
#include "multiboot_pokemon_colosseum.h"
#include "load_save.h"
#include "save.h"
#include "new_game.h"
#include "m4a.h"
#include "random.h"
#include "decompress.h"
#include "constants/songs.h"
#include "intro_credits_graphics.h"
#include "trig.h"
#include "intro.h"
#include "graphics.h"
#include "sound.h"
#include "constants/species.h"
#include "util.h"
#include "title_screen.h"
#include "constants/rgb.h"
#include "trainer_pokemon_sprites.h"
#include "constants/battle_anim.h"

extern const struct CompressedSpriteSheet gBattleAnimPicTable[];
extern const struct CompressedSpritePalette gBattleAnimPaletteTable[];
extern const struct SpriteTemplate gUnknown_08596C10[];

//ewram
EWRAM_DATA u16 gUnknown_0203BCC8 = 0;
EWRAM_DATA u16 gUnknown_0203BCCA = 0;
EWRAM_DATA u16 gUnknown_0203BCCC = 0;

//iwram
u32 gIntroFrameCounter;
struct GcmbStruct gMultibootProgramStruct;

//.rodata
static const u16 gIntro1BGPals[] = INCBIN_U16("graphics/intro/intro1_background.gbapal");
static const u32 gIntro1BG2_Tilemap[] = INCBIN_U32("graphics/intro/intro1_bg2.bin.lz");
static const u32 gIntro1BG2_LogoTilemap[] = INCBIN_U32("graphics/intro/intro1_bg2_logo.bin.lz");
static const u32 gIntro1BG3_Tilemap[] = INCBIN_U32("graphics/intro/intro1_bg3.bin.lz");
static const u32 gIntro1BG0_Tiles[] = INCBIN_U32("graphics/intro/intro1_background.4bpp.lz");
static const u32 gIntro1BG0_LogoTiles[] = INCBIN_U32("graphics/intro/intro1_logotiles.4bpp.lz");
static const u32 gIntroDittoTiles[] = INCBIN_U32("graphics/intro/intro1_ditto.4bpp.lz");
static const u32 gIntroPresentsTiles[] = INCBIN_U32("graphics/intro/intro1_presents.4bpp.lz");
static const u16 gIntro1DittoPalette[] = INCBIN_U16("graphics/intro/intro1_ditto.gbapal");
static const u16 gIntro2BGPals[][16] = {
    INCBIN_U16("graphics/intro/intro2_bg3.gbapal"),
    INCBIN_U16("graphics/intro/intro2_bg1.gbapal")
};
static const u32 gIntro2Tiles[] = INCBIN_U32("graphics/intro/intro2.4bpp.lz");
static const u32 gIntro2BG1_Tilemap[] = INCBIN_U32("graphics/intro/intro2_bg1.bin.lz");
static const u32 gIntro2BG2_Tilemap[] = INCBIN_U32("graphics/intro/intro2_bg2.bin.lz");
static const u32 gIntro2BG3_Tilemap[] = INCBIN_U32("graphics/intro/intro2_bg3.bin.lz");
static const u16 gIntro2UnownPalette[] = INCBIN_U16("graphics/intro/intro2_unownA.gbapal");
static const u16 gIntro2UnownPulsePalette[] = INCBIN_U16("graphics/intro/intro2_unown_pulse.gbapal");
static const u16 gIntro2SuicuneSilhouettePalette[] = INCBIN_U16("graphics/intro/intro2_suicune_silhouette.gbapal");
static const u16 gIntro2WooperPalette[] = INCBIN_U16("graphics/intro/intro2_wooper.gbapal");
static const u16 gIntro2PichuPalette[] = INCBIN_U16("graphics/intro/intro2_pichu.gbapal");
static const u32 gIntro2UnownATiles[] = INCBIN_U32("graphics/intro/intro2_unownA.4bpp.lz");
static const u32 gIntro2UnownPulseTiles[] = INCBIN_U32("graphics/intro/intro2_unown_pulse.4bpp.lz");
static const u32 gIntro2UnownOthersTiles[] = INCBIN_U32("graphics/intro/intro2_tiny_unowns.4bpp.lz");
static const u32 gIntro2SuicuneSilhouetteTiles[] = INCBIN_U32("graphics/intro/intro2_suicune_silhouette.4bpp.lz");
static const u32 gIntro2WooperTiles[] = INCBIN_U32("graphics/intro/intro2_wooper.4bpp.lz");
static const u32 gIntro2PichuTiles[] = INCBIN_U32("graphics/intro/intro2_pichu.4bpp.lz");
static const u16 gIntro3BG3_Pals[][16] = {
    INCBIN_U16("graphics/intro/intro3_suicune_mug.gbapal"),
    INCBIN_U16("graphics/intro/intro3_fallingbg.gbapal"),
};
static const u16 gIntro3SuicunePalette[] = INCBIN_U16("graphics/intro/intro3_suicune.gbapal");
static const u16 gIntro3NamePalette[] = INCBIN_U16("graphics/intro/intro3_name.gbapal");
static const u32 gIntro3BG3_Tiles[] = INCBIN_U32("graphics/intro/intro3_suicune_mug.4bpp.lz");
static const u32 gIntro3BG3_Tilemap[] = INCBIN_U32("graphics/intro/intro3_suicune_mug.bin.lz");
static const u32 gIntro3Name_Tiles[] = INCBIN_U32("graphics/intro/intro3_name.4bpp.lz");
static const u32 gIntro3Name_Tilemap[] = INCBIN_U32("graphics/intro/intro3_name.bin.lz");
static const u32 gIntro3SuicuneTiles[] = INCBIN_U32("graphics/intro/intro3_suicune.4bpp.lz");
static const u32 gIntro3UnownFTiles[] = INCBIN_U32("graphics/intro/intro3_unownF.4bpp.lz");

static const struct SpritePalette gSpritePalette_Ditto[] =
{
    {gIntro1DittoPalette, 2000},
    {NULL},
};
static const struct CompressedSpriteSheet gSpriteSheet_Ditto[] =
{
    {gIntroDittoTiles, 0x1800, 2000},
    {NULL},
};
static const struct OamData gOamData_Ditto =
{
    .y = 160,
    .affineMode = 1,
    .objMode = 0,
    .mosaic = TRUE,
    .bpp = 0,
    .shape = 0,
    .x = 0,
    .matrixNum = 0,
    .size = 3,
    .tileNum = 0,
    .priority = 3,
    .paletteNum = 0,
    .affineParam = 0,
};
static const union AnimCmd gSpriteAnim1_Ditto[] =
{
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_END,
};
static const union AnimCmd gSpriteAnim2_Ditto[] =
{
    ANIMCMD_FRAME(0, 48),
    ANIMCMD_FRAME(64, 8),
    ANIMCMD_END,
};
static const union AnimCmd gSpriteAnim3_Ditto[] =
{
    ANIMCMD_FRAME(128, 8),
    ANIMCMD_END,
};
static const union AnimCmd *const gSpriteAnimTable_Ditto[] =
{
    gSpriteAnim1_Ditto,
    gSpriteAnim2_Ditto,
    gSpriteAnim3_Ditto,
};
static const union AffineAnimCmd gSpriteAffineAnim1_Ditto[] = 
{
    AFFINEANIMCMD_SIZE(1, 1, 0),
    AFFINEANIMCMD_END,
};
static const union AffineAnimCmd gSpriteAffineAnim2_Ditto[] = 
{
    AFFINEANIMCMD_SIZE(0.75, 1.5, 0),
    AFFINEANIMCMD_FRAME(0, 0, 0, 8),
    AFFINEANIMCMD_FRAME(64, -64, 0, 3),
    AFFINEANIMCMD_FRAME(-24, 24, 0, 8),
    AFFINEANIMCMD_FRAME(3, -6, 0, 24),
    AFFINEANIMCMD_FRAME(24, -24, 0, 3),
    AFFINEANIMCMD_FRAME(-24, 24, 0, 3),
    AFFINEANIMCMD_SIZE(1, 1, 0),
    AFFINEANIMCMD_END,
};
static const union AffineAnimCmd *const gSpriteAffineAnimTable_Ditto[] =
{
    gSpriteAffineAnim1_Ditto,
    gSpriteAffineAnim2_Ditto,
};
static void SpriteCallback_Ditto(struct Sprite *sprite);
static const struct SpriteTemplate gSpriteTemplate_Ditto =
{
    .tileTag = 2000,
    .paletteTag = 2000,
    .oam = &gOamData_Ditto,
    .anims = gSpriteAnimTable_Ditto,
    .images = NULL,
    .affineAnims = gSpriteAffineAnimTable_Ditto,
    .callback = SpriteCallback_Ditto,
};
static const struct CompressedSpriteSheet gSpriteSheet_Presents[] =
{
    {gIntroPresentsTiles, 0x100, 2001},
    {NULL},
};
static const struct OamData gOamData_Presents =
{
    .y = 0,
    .affineMode = 0,
    .objMode = 1,
    .mosaic = 0,
    .bpp = 0,
    .shape = 1,
    .x = 0,
    .matrixNum = 0,
    .size = 1,
    .tileNum = 0,
    .priority = 3,
    .paletteNum = 0,
    .affineParam = 0,
};
static const struct SpriteTemplate gSpriteTemplate_Presents =
{
    .tileTag = 2001,
    .paletteTag = 2000,
    .oam = &gOamData_Presents,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};
static const struct CompressedSpriteSheet gIntro2UnownASpriteSheet[] =
{
    {gIntro2UnownATiles, 0x400, 2002},
    {NULL},
};
static const struct SpritePalette gIntro2SpritePalettes[] =
{
    {gIntro2UnownPalette, 2002},
    {gIntro2UnownPulsePalette, 2003},
    {gIntro2WooperPalette, 2004},
    {gIntro2PichuPalette, 2005},
    {NULL},
};
static const struct SpritePalette gSuicuneSilhouetteSpritePalettes[] =
{
    {gIntro2SuicuneSilhouettePalette, 1000},
    {NULL},
};
static const struct OamData gOamData_UnownA =
{
    .y = 0,
    .affineMode = 3,
    .objMode = 0,
    .mosaic = 0,
    .bpp = 0,
    .shape = 2,
    .x = 0,
    .matrixNum = 0,
    .size = 3,
    .tileNum = 0,
    .priority = 3,
    .paletteNum = 0,
    .affineParam = 0,
};
static const union AffineAnimCmd gSpriteAffineAnim_UnownA1[] = 
{
    AFFINEANIMCMD_SIZE(1, 1, 0),
    AFFINEANIMCMD_END,
};
static const union AffineAnimCmd gSpriteAffineAnim_UnownA2[] = 
{
    AFFINEANIMCMD_SIZE(1, 1, 0),
    AFFINEANIMCMD_FRAME(8, 8, 0, 8),
    AFFINEANIMCMD_FRAME(-8, -8, 0, 8),
    AFFINEANIMCMD_END,
};
static const union AffineAnimCmd *const gSpriteAffineAnimTable_UnownA[] =
{
    gSpriteAffineAnim_UnownA1,
    gSpriteAffineAnim_UnownA2,
};
static const struct SpriteTemplate gSpriteTemplate_UnownA =
{
    .tileTag = 2002,
    .paletteTag = 2002,
    .oam = &gOamData_UnownA,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gSpriteAffineAnimTable_UnownA,
    .callback = SpriteCallbackDummy,
};
static const struct CompressedSpriteSheet gIntro2UnownPulseSpriteSheet[] =
{
    {gIntro2UnownPulseTiles, 0x800, 2003},
    {NULL},
};
static const struct OamData gOamData_UnownPulse =
{
    .y = 0,
    .affineMode = 0,
    .objMode = 0,
    .mosaic = 0,
    .bpp = 0,
    .shape = 0,
    .x = 0,
    .matrixNum = 0,
    .size = 2,
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0,
};
static const union AnimCmd gSpriteAnim_UnownPulse1[] =
{
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(16, 2),
    ANIMCMD_FRAME(32, 4),
    ANIMCMD_FRAME(48, 8),
    ANIMCMD_END,
};
static const union AnimCmd *const gSpriteAnimTable_UnownPulse[] =
{
    gSpriteAnim_UnownPulse1,
};
static void SpriteCallback_UnownPulse(struct Sprite *sprite);
static const struct SpriteTemplate gSpriteTemplate_UnownPulse =
{
    .tileTag = 2003,
    .paletteTag = 2003,
    .oam = &gOamData_UnownPulse,
    .anims = gSpriteAnimTable_UnownPulse,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallback_UnownPulse,
};
static const struct CompressedSpriteSheet gIntro2UnownOthersSpriteSheet[] =
{
    {gIntro2UnownOthersTiles, 0x1400, 2004},
    {NULL},
};
static const struct OamData gOamData_UnownOthers =
{
    .y = 0,
    .affineMode = 3,
    .objMode = 0,
    .mosaic = 0,
    .bpp = 0,
    .shape = 0,
    .x = 0,
    .matrixNum = 0,
    .size = 2,
    .tileNum = 0,
    .priority = 3,
    .paletteNum = 0,
    .affineParam = 0,
};
static const union AnimCmd gSpriteAnim_UnownOthersI[] =
{
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_END,
};
static const union AnimCmd gSpriteAnim_UnownOthersH[] =
{
    ANIMCMD_FRAME(16, 8),
    ANIMCMD_END,
};
static const union AnimCmd gSpriteAnim_UnownOthersU[] =
{
    ANIMCMD_FRAME(32, 8),
    ANIMCMD_END,
};
static const union AnimCmd gSpriteAnim_UnownOthersW[] =
{
    ANIMCMD_FRAME(48, 8),
    ANIMCMD_END,
};
static const union AnimCmd gSpriteAnim_UnownOthersG[] =
{
    ANIMCMD_FRAME(64, 8),
    ANIMCMD_END,
};
static const union AnimCmd gSpriteAnim_UnownOthersT[] =
{
    ANIMCMD_FRAME(80, 8),
    ANIMCMD_END,
};
static const union AnimCmd gSpriteAnim_UnownOthersB[] =
{
    ANIMCMD_FRAME(96, 8),
    ANIMCMD_END,
};
static const union AnimCmd gSpriteAnim_UnownOthersE[] =
{
    ANIMCMD_FRAME(112, 8),
    ANIMCMD_END,
};
static const union AnimCmd gSpriteAnim_UnownOthersS[] =
{
    ANIMCMD_FRAME(128, 8),
    ANIMCMD_END,
};
static const union AnimCmd gSpriteAnim_UnownOthersL[] =
{
    ANIMCMD_FRAME(144, 8),
    ANIMCMD_END,
};
static const union AnimCmd *const gSpriteAnimTable_UnownOthers[] =
{
    gSpriteAnim_UnownOthersI,
    gSpriteAnim_UnownOthersH,
    gSpriteAnim_UnownOthersU,
    gSpriteAnim_UnownOthersW,
    gSpriteAnim_UnownOthersG,
    gSpriteAnim_UnownOthersT,
    gSpriteAnim_UnownOthersB,
    gSpriteAnim_UnownOthersE,
    gSpriteAnim_UnownOthersS,
    gSpriteAnim_UnownOthersL,
};
static const union AffineAnimCmd gSpriteAffineAnim_UnownOthers1[] = 
{
    AFFINEANIMCMD_SIZE(1, 1, 0),
    AFFINEANIMCMD_END,
};
static const union AffineAnimCmd gSpriteAffineAnim_UnownOthers2[] = 
{
    AFFINEANIMCMD_SIZE(1, 1, 0),
    AFFINEANIMCMD_FRAME(8, 8, 0, 8),
    AFFINEANIMCMD_FRAME(-8, -8, 0, 8),
    AFFINEANIMCMD_END,
};
static const union AffineAnimCmd gSpriteAffineAnim_UnownOthers3[] = 
{
    AFFINEANIMCMD_SIZE(0.1, 0.1, 0),
    AFFINEANIMCMD_FRAME(64, 64, 0, 4),
    AFFINEANIMCMD_SIZE(1, 1, 0),
    AFFINEANIMCMD_END,
};
static const union AffineAnimCmd *const gSpriteAffineAnimTable_UnownOthers[] =
{
    gSpriteAffineAnim_UnownOthers1,
    gSpriteAffineAnim_UnownOthers2,
    gSpriteAffineAnim_UnownOthers3,
};
static const struct SpriteTemplate gSpriteTemplate_UnownOthers =
{
    .tileTag = 2004,
    .paletteTag = 2002,
    .oam = &gOamData_UnownOthers,
    .anims = gSpriteAnimTable_UnownOthers,
    .images = NULL,
    .affineAnims = gSpriteAffineAnimTable_UnownOthers,
    .callback = SpriteCallbackDummy,
};
static const struct CompressedSpriteSheet gIntro2SuicuneSilhouetteSpriteSheet[] =
{
    {gIntro2SuicuneSilhouetteTiles, 0x2000, 2005},
    {NULL},
};
static const struct OamData gOamData_SuicuneSilhouette =
{
    .y = 0,
    .affineMode = 0,
    .objMode = 0,
    .mosaic = 0,
    .bpp = 0,
    .shape = 0,
    .x = 0,
    .matrixNum = 0,
    .size = 3,
    .tileNum = 0,
    .priority = 3,
    .paletteNum = 0,
    .affineParam = 0,
};
static const union AnimCmd gSpriteAnim_SuicuneSilhouette1[] =
{
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(64, 4),
    ANIMCMD_FRAME(128, 4),
    ANIMCMD_FRAME(192, 4),
    ANIMCMD_JUMP(0),
};
static const union AnimCmd gSpriteAnim_SuicuneSilhouette2[] =
{
    ANIMCMD_FRAME(192, 4),
    ANIMCMD_JUMP(0),
};
static const union AnimCmd *const gSpriteAnimTable_SuicuneSilhouette[] =
{
    gSpriteAnim_SuicuneSilhouette1,
    gSpriteAnim_SuicuneSilhouette2,
};
static void SpriteCallback_SuicuneSilhouette(struct Sprite *sprite);
static const struct SpriteTemplate gSpriteTemplate_SuicuneSilhouette =
{
    .tileTag = 2005,
    .paletteTag = 1000,
    .oam = &gOamData_SuicuneSilhouette,
    .anims = gSpriteAnimTable_SuicuneSilhouette,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallback_SuicuneSilhouette,
};
static const struct CompressedSpriteSheet gIntro2WooperSpriteSheet[] =
{
    {gIntro2WooperTiles, 0x800, 2006},
    {NULL},
};
static const struct CompressedSpriteSheet gIntro2PichuSpriteSheet[] =
{
    {gIntro2PichuTiles, 0x1800, 2007},
    {NULL},
};
static const struct OamData gOamData_PopUpPkmn =
{
    .y = 0,
    .affineMode = 0,
    .objMode = 0,
    .mosaic = 0,
    .bpp = 0,
    .shape = 0,
    .x = 0,
    .matrixNum = 0,
    .size = 3,
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
    .affineParam = 0,
};
static const union AnimCmd gSpriteAnim_Wooper1[] =
{
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_END,
};
static const union AnimCmd *const gSpriteAnimTable_Wooper[] =
{
    gSpriteAnim_Wooper1,
};
static void SpriteCallback_PopUpPkmn(struct Sprite *sprite);
static const struct SpriteTemplate gSpriteTemplate_Wooper =
{
    .tileTag = 2006,
    .paletteTag = 2004,
    .oam = &gOamData_PopUpPkmn,
    .anims = gSpriteAnimTable_Wooper,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallback_PopUpPkmn,
};
static const union AnimCmd gSpriteAnim_Pichu1[] =
{
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_END,
};
static const union AnimCmd gSpriteAnim_Pichu2[] =
{
    ANIMCMD_FRAME(0, 24),
    ANIMCMD_FRAME(64, 8),
    ANIMCMD_FRAME(128, 8),
    ANIMCMD_END,
};
static const union AnimCmd *const gSpriteAnimTable_Pichu[] =
{
    gSpriteAnim_Pichu1,
    gSpriteAnim_Pichu2,
};
static const struct SpriteTemplate gSpriteTemplate_Pichu =
{
    .tileTag = 2007,
    .paletteTag = 2005,
    .oam = &gOamData_PopUpPkmn,
    .anims = gSpriteAnimTable_Pichu,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallback_PopUpPkmn,
};
static const struct CompressedSpriteSheet gIntro3SuicuneSpriteSheet[] =
{
    {gIntro3SuicuneTiles, 0x1800, 2008},
    {NULL},
};
static const struct SpritePalette gIntro3SpritePalettes[] =
{
    {gIntro3SuicunePalette, 2006},
    {gIntro2UnownPalette, 2002},
    {NULL},
};
static const struct OamData gOamData_Suicune =
{
    .y = 0,
    .affineMode = 3,
    .objMode = 0,
    .mosaic = 0,
    .bpp = 0,
    .shape = 0,
    .x = 0,
    .matrixNum = 0,
    .size = 3,
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0,
};
static const union AnimCmd gSpriteAnim_Suicune1[] =
{
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(64, 4),
    ANIMCMD_JUMP(0),
};
static const union AnimCmd gSpriteAnim_Suicune2[] =
{
    ANIMCMD_FRAME(128, 8),
    ANIMCMD_JUMP(0),
};
static const union AnimCmd *const gSpriteAnimTable_Suicune[] =
{
    gSpriteAnim_Suicune1,
    gSpriteAnim_Suicune2,
};
static const union AffineAnimCmd gSpriteAffineAnim_Suicune1[] = 
{
    AFFINEANIMCMD_SIZE(1, 1, 0),
    AFFINEANIMCMD_END,
};
static const union AffineAnimCmd gSpriteAffineAnim_Suicune2[] = 
{
    AFFINEANIMCMD_SIZE(1, 1, 0),
    AFFINEANIMCMD_FRAME(-1, -1, 0, 88),
    AFFINEANIMCMD_END,
};
static const union AffineAnimCmd *const gSpriteAffineAnimTable_Suicune[] =
{
    gSpriteAffineAnim_Suicune1,
    gSpriteAffineAnim_Suicune2,
};
static void SpriteCallback_Suicune(struct Sprite *sprite);
static const struct SpriteTemplate gSpriteTemplate_Suicune =
{
    .tileTag = 2008,
    .paletteTag = 2006,
    .oam = &gOamData_Suicune,
    .anims = gSpriteAnimTable_Suicune,
    .images = NULL,
    .affineAnims = gSpriteAffineAnimTable_Suicune,
    .callback = SpriteCallback_Suicune,
};
static const struct CompressedSpriteSheet gIntro3UnownFSpriteSheet[] =
{
    {gIntro3UnownFTiles, 0x1000, 2009},
    {NULL},
};
static const struct OamData gOamData_UnownF =
{
    .y = 0,
    .affineMode = 1,
    .objMode = 0,
    .mosaic = 0,
    .bpp = 0,
    .shape = 0,
    .x = 0,
    .matrixNum = 0,
    .size = 3,
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0,
};
static const union AnimCmd gSpriteAnim_UnownF1[] =
{
    ANIMCMD_FRAME(0, 14),
    ANIMCMD_FRAME(64, 8),
    ANIMCMD_END,
};
static const union AnimCmd *const gSpriteAnimTable_UnownF[] =
{
    gSpriteAnim_UnownF1,
};
static const union AffineAnimCmd gSpriteAffineAnim_UnownF1[] = 
{
    AFFINEANIMCMD_SIZE(.5, .5, 0),
    AFFINEANIMCMD_FRAME(32, 4, 0, 4),
    AFFINEANIMCMD_FRAME(-40, 72, 0, 4),
    AFFINEANIMCMD_FRAME(28, -28, 0, 6),
    AFFINEANIMCMD_SIZE(1, 1, 0),
    AFFINEANIMCMD_END,
};
static const union AffineAnimCmd *const gSpriteAffineAnimTable_UnownF[] =
{
    gSpriteAffineAnim_UnownF1,
};
static void SpriteCallback_UnownF(struct Sprite *sprite);
static const struct SpriteTemplate gSpriteTemplate_UnownF =
{
    .tileTag = 2009,
    .paletteTag = 2002,
    .oam = &gOamData_UnownF,
    .anims = gSpriteAnimTable_UnownF,
    .images = NULL,
    .affineAnims = gSpriteAffineAnimTable_UnownF,
    .callback = SpriteCallback_UnownF,
};


// this file's functions
static void MainCB2_EndIntro(void);
static void Task_IntroLoadPart1Graphics(u8);
static void Task_IntroGameFreakStart(u8);
static void intro_reset_and_hide_bgs(void);
static void Task_ShowGameFreakScreen(u8);
static void Task_MosaicToGameFreakLogo(u8);
static void Task_FadeInOutGameFreakText(u8);
static void Task_WaitToStartUnownSequence(u8);
static void Task_IntroLoadPart2Graphics(u8);
static void Task_IntroStartUnownSequence(u8);
static void Task_IntroDoUnownASequence(u8);
static void Task_ScrollTreeGrassBackgrounds(u8);
static void Task_IntroDoSuicuneRunAcrossScreen(u8);
static void Task_FlashMultipleUnowns(u8);
static void Task_IntroLoadPart3Graphics(u8);
static void Task_IntroStartPart3(u8);
static void Task_IntroDoSuicuneRunningInPlace(u8);
static void Task_IntroWaitToSetupFallingSuicune(u8);
static void Task_IntroLoadPart3Graphics1(u8);
static void Task_IntroLoadPart3Graphics2(u8);
static void Task_IntroSuicuneFlyUp(u8);
static void Task_WaitToDoCrystalDustLogo(u8);
static void Task_DoCrystalDustLogo(u8);
static void Task_IntroFadeToTitle(u8);

static void VBlankCB_Intro(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
    ScanlineEffect_InitHBlankDmaTransfer();
}

static void MainCB2_Intro(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
    if (gMain.newKeys && !gPaletteFade.active)
        SetMainCallback2(MainCB2_EndIntro);
    else if (gIntroFrameCounter != -1)
        gIntroFrameCounter++;
}

static void MainCB2_EndIntro(void)
{
    if (!UpdatePaletteFade())
        SetMainCallback2(CB2_InitTitleScreen);
}

static void LoadCopyrightGraphics(u16 tilesetAddress, u16 tilemapAddress, u16 paletteAddress)
{
    LZ77UnCompVram(gIntroCopyright_Gfx, (void *)(VRAM + tilesetAddress));
    LZ77UnCompVram(gIntroCopyright_Tilemap, (void *)(VRAM + tilemapAddress));
    LoadPalette(gIntroCopyright_Pal, paletteAddress, 0x20);
}

static void SerialCB_CopyrightScreen(void)
{
    GameCubeMultiBoot_HandleSerialInterrupt(&gMultibootProgramStruct);
}

static u8 SetUpCopyrightScreen(void)
{
    u16 ime;

    switch (gMain.state)
    {
    case 0:
        SetVBlankCallback(NULL);
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        SetGpuReg(REG_OFFSET_BLDY, 0);
        *(u16 *)PLTT = RGB_WHITE;
        SetGpuReg(REG_OFFSET_DISPCNT, 0);
        SetGpuReg(REG_OFFSET_BG0HOFS, 0);
        SetGpuReg(REG_OFFSET_BG0VOFS, 0);
        CpuFill32(0, (void *)VRAM, VRAM_SIZE);
        CpuFill32(0, (void *)OAM, OAM_SIZE);
        CpuFill16(0, (void *)(PLTT + 2), PLTT_SIZE - 2);
        ResetPaletteFade();
        LoadCopyrightGraphics(0, 0x3800, 0);
        ScanlineEffect_Stop();
        ResetTasks();
        ResetSpriteData();
        FreeAllSpritePalettes();
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0x10, 0, RGB_WHITEALPHA);
        SetGpuReg(REG_OFFSET_BG0CNT, BGCNT_PRIORITY(0)
                                   | BGCNT_CHARBASE(0)
                                   | BGCNT_SCREENBASE(7)
                                   | BGCNT_16COLOR
                                   | BGCNT_TXT256x256);
        EnableInterrupts(INTR_FLAG_VBLANK);
        SetVBlankCallback(VBlankCB_Intro);
        REG_DISPCNT = DISPCNT_MODE_0 | DISPCNT_OBJ_1D_MAP | DISPCNT_BG0_ON;
        SetSerialCallback(SerialCB_CopyrightScreen);
        GameCubeMultiBoot_Init(&gMultibootProgramStruct);
    default:
        UpdatePaletteFade();
        gMain.state++;
        GameCubeMultiBoot_Main(&gMultibootProgramStruct);
        break;
    case 140:
        GameCubeMultiBoot_Main(&gMultibootProgramStruct);
        if (gMultibootProgramStruct.gcmb_field_2 != 1)
        {
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 0x10, RGB_BLACK);
            gMain.state++;
        }
        break;
    case 141:
        if (UpdatePaletteFade())
            break;
        CreateTask(Task_IntroLoadPart1Graphics, 0);
        SetMainCallback2(MainCB2_Intro);
        if (gMultibootProgramStruct.gcmb_field_2 != 0)
        {
            if (gMultibootProgramStruct.gcmb_field_2 == 2)
            {
                // check the multiboot ROM header game code to see if we already did this
                if (*(u32 *)(EWRAM_START + 0xAC) == 0x65366347) // "Gc6e" in ASCII
                {
                    CpuCopy16(&gMultiBootProgram_PokemonColosseum_Start, (void *)EWRAM_START, sizeof(gMultiBootProgram_PokemonColosseum_Start));
                    *(u32 *)(EWRAM_START + 0xAC) = 0x65366347;
                }
                GameCubeMultiBoot_ExecuteProgram(&gMultibootProgramStruct);
            }
        }
        else
        {
            GameCubeMultiBoot_Quit();
            SetSerialCallback(SerialCB);
        }
        return 0;
    }

    return 1;
}

void CB2_InitCopyrightScreenAfterBootup(void)
{
    if (!SetUpCopyrightScreen())
    {
        SetSaveBlocksPointers(sub_815355C());
        sub_808447C();
        Save_ResetSaveCounters();
        Save_LoadGameData(SAVE_NORMAL);
        if (gSaveFileStatus == 0 || gSaveFileStatus == 2)
            Sav2_ClearSetDefault();
        SetPokemonCryStereo(gSaveBlock2Ptr->optionsSound);
        InitHeap(gHeap, HEAP_SIZE);
    }
}

void CB2_InitCopyrightScreenAfterTitleScreen(void)
{
    SetUpCopyrightScreen();
}

static void Task_IntroLoadPart1Graphics(u8 taskId)
{
    u8 spriteId;
    SetVBlankCallback(NULL);
    intro_reset_and_hide_bgs();
    SetGpuReg(REG_OFFSET_BG3VOFS, 0);
    SetGpuReg(REG_OFFSET_BG2VOFS, 0);
    LZ77UnCompVram(gIntro1BG0_Tiles, (void *)(VRAM + 0xC000));
    LZ77UnCompVram(gIntro1BG0_LogoTiles, (void *)(VRAM + 0xC200));
    LZ77UnCompVram(gIntro1BG2_Tilemap, (void *)(VRAM + 0xF000));
    LZ77UnCompVram(gIntro1BG3_Tilemap, (void *)(VRAM + 0xF800));
    LoadPalette(gIntro1BGPals, 0, sizeof(gIntro1BGPals));
    SetGpuReg(REG_OFFSET_BG3CNT, BGCNT_PRIORITY(3)
                               | BGCNT_CHARBASE(3)
                               | BGCNT_SCREENBASE(31)
                               | BGCNT_16COLOR
                               | BGCNT_TXT256x256);
    SetGpuReg(REG_OFFSET_BG2CNT, BGCNT_PRIORITY(2)
                               | BGCNT_CHARBASE(3)
                               | BGCNT_SCREENBASE(30)
                               | BGCNT_16COLOR
                               | BGCNT_TXT256x256);
    LoadCompressedObjectPic(gSpriteSheet_Ditto);
    LoadCompressedObjectPic(gSpriteSheet_Presents);
    LoadSpritePalettes(gSpritePalette_Ditto);
    CpuCopy16(gPlttBufferUnfaded + 0x100, gPlttBufferUnfaded + 0x1F0, 0x20);
    CpuCopy16(gPlttBufferUnfaded + 0x100, gPlttBufferUnfaded + 0x1E1, 0x1E);
    CpuCopy16(gPlttBufferUnfaded + 0x100, gPlttBufferUnfaded + 0x1D2, 0x1C);
    CpuCopy16(gPlttBufferUnfaded + 0x100, gPlttBufferUnfaded + 0x1C3, 0x1A);
    CpuCopy16(gPlttBufferUnfaded + 0x100, gPlttBufferUnfaded + 0x1B4, 0x18);
    CpuCopy16(gPlttBufferUnfaded + 0x100, gPlttBufferUnfaded + 0x1A5, 0x16);
    CpuCopy16(gPlttBufferUnfaded + 0x100, gPlttBufferUnfaded + 0x196, 0x14);
    spriteId = CreateSprite(&gSpriteTemplate_Ditto, 120, -48, 0);
    gSprites[spriteId].data[0] = 0;
    StartSpriteAnim(&gSprites[spriteId], 1);
    StartSpriteAffineAnim(&gSprites[spriteId], 1);
    gTasks[taskId].data[1] = spriteId;
    gTasks[taskId].func = Task_IntroGameFreakStart;
}

static void Task_WindowOpen(u8 taskId)
{
    u16 currentPos = gTasks[taskId].data[0];
    u16 desiredPos = gTasks[taskId].data[1];

    if (currentPos != desiredPos)
    {
        gTasks[taskId].data[0] += gTasks[taskId].data[2];
        SetGpuReg(REG_OFFSET_WIN0V, (currentPos << 8) | (0xA0 - currentPos));
    }
    else
    {
        SetGpuReg(REG_OFFSET_WIN0V, (desiredPos << 8) | (0xA0 - desiredPos));
        DestroyTask(taskId);
    }
}

static void Task_IntroGameFreakStart(u8 taskId)
{
    u8 windowTaskId;
    
    SetVBlankCallback(VBlankCB_Intro);
    SetGpuReg(REG_OFFSET_WIN0H, 0xF0);
    SetGpuReg(REG_OFFSET_WIN0V, 0x5050);
    SetGpuReg(REG_OFFSET_WININ, 0x3F);
    SetGpuReg(REG_OFFSET_WINOUT, 0x10);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0
                                | DISPCNT_OBJ_1D_MAP
                                | DISPCNT_BG3_ON
                                | DISPCNT_OBJ_ON
                                | DISPCNT_WIN0_ON);
    windowTaskId = CreateTask(Task_WindowOpen, 0);
    gTasks[windowTaskId].data[0] = 0x50;
    gTasks[windowTaskId].data[1] = 0x20;
    gTasks[windowTaskId].data[2] = -8;
    gTasks[taskId].func = Task_ShowGameFreakScreen;
    gIntroFrameCounter = 0;
    m4aSongNumStart(MUS_DEMO1);
    ResetSerial();
}

static void Task_ShowGameFreakScreen(u8 taskId)
{
    u8 newTaskId;
    
    if (gIntroFrameCounter == 80)
        CreateTask(Task_MosaicToGameFreakLogo, 0);
    
    if (gIntroFrameCounter == 170)
    {
        SetGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_BG2_ON);
        SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG2
                                   | BLDCNT_EFFECT_BLEND
                                   | BLDCNT_TGT2_BG0
                                   | BLDCNT_TGT2_BG1
                                   | BLDCNT_TGT2_BG2
                                   | BLDCNT_TGT2_BG3
                                   | BLDCNT_TGT2_OBJ
                                   | BLDCNT_TGT2_BD);
        newTaskId = CreateTask(Task_FadeInOutGameFreakText, 0);
        gTasks[newTaskId].data[1] = 0;
    }
    
    if (gIntroFrameCounter == 200)
    {
        LZ77UnCompVram(gIntro1BG2_LogoTilemap, (void *)(VRAM + 0xF000));
        DestroySprite(&gSprites[gTasks[taskId].data[1]]);
        gTasks[taskId].data[0] = CreateSprite(&gSpriteTemplate_Presents, 104, 108, 5);
        gTasks[taskId].data[1] = CreateSprite(&gSpriteTemplate_Presents, 136, 108, 5);
        gSprites[gTasks[taskId].data[1]].oam.tileNum += 4;
    }
    
    if (gIntroFrameCounter == 320)
    {
        SetGpuRegBits(REG_OFFSET_BLDCNT, BLDCNT_TGT1_OBJ);
        newTaskId = CreateTask(Task_FadeInOutGameFreakText, 0);
        gTasks[newTaskId].data[1] = 1;
    }
    
    if (gIntroFrameCounter == 350)
    {
        DestroySprite(&gSprites[gTasks[taskId].data[1]]);
        DestroySprite(&gSprites[gTasks[taskId].data[2]]);
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
        gTasks[taskId].func = Task_WaitToStartUnownSequence;
    }
}

static void Task_MosaicToGameFreakLogo(u8 taskId)
{
    u16 temp;
    
    if (gIntroFrameCounter < 98)
    {
        temp = gTasks[taskId].data[0]++ >> 1;
        if (temp > 20)
            temp = 20;
        SetGpuReg(REG_OFFSET_MOSAIC, MOSAIC_SIZE(0, 0, temp, temp));
        return;
    }
    
    if (gIntroFrameCounter == 98)
    {
        // shift it up a tad pls
        gSprites[gTasks[taskId].data[1]].pos1.y = 70;
        StartSpriteAnim(&gSprites[gTasks[taskId].data[1]], 2);
    }
    
    if (gIntroFrameCounter < 116)
    {
        temp = gTasks[taskId].data[0]-- >> 1;
        if (temp > 20)
            temp = 20;
        SetGpuReg(REG_OFFSET_MOSAIC, MOSAIC_SIZE(0, 0, temp, temp));
        return;
    }
    
    if (gTasks[taskId].data[0] == 0)
    {
        SetGpuReg(REG_OFFSET_MOSAIC, 0);
        DestroyTask(taskId);
    }
}

static void Task_FadeInOutGameFreakText(u8 taskId)
{
    u16 temp = gTasks[taskId].data[0]++;
    
    if (gTasks[taskId].data[1] == 0)
        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(temp, 16 - temp));
    else
        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(16 - temp, temp));
    
    if (temp == 16)
        DestroyTask(taskId);
}

static void Task_WaitToStartUnownSequence(u8 taskId)
{
    if (gIntroFrameCounter == 460)
    {
        gIntroFrameCounter = 0;
        gTasks[taskId].func = Task_IntroLoadPart2Graphics;
    }
}

static void SpriteCallback_Ditto(struct Sprite *sprite)
{
    switch (sprite->data[0])
    {
    case 0:
        if (sprite->pos1.y < 80)
        {
            sprite->pos1.y += 10;
        }
        else
        {
            sprite->pos1.y = 79;
            sprite->data[1] = Q_8_8(-10);
            sprite->data[0]++;
        }
        break;
    case 1:
        if (sprite->pos1.y < 80)
        {
            sprite->pos1.y += Q_8_8_TO_INT(sprite->data[1]);
            sprite->data[1] += Q_8_8(0.65);
        }
        else
        {
            sprite->pos1.y = 80;
            sprite->callback = SpriteCallbackDummy;
        }
        break;
    }
}

static void Task_IntroLoadPart2Graphics(u8 taskId)
{
    intro_reset_and_hide_bgs();
    SetVBlankCallback(NULL);
    ResetSpriteData();
    FreeAllSpritePalettes();
    LZ77UnCompVram(gIntro2Tiles, (void *)(VRAM));
    LZ77UnCompVram(gIntro2BG1_Tilemap, (void *)(VRAM + 0xE000));
    LZ77UnCompVram(gIntro2BG2_Tilemap, (void *)(VRAM + 0xE800));
    LZ77UnCompVram(gIntro2BG3_Tilemap, (void *)(VRAM + 0xF800));
    LoadPalette(gIntro2BGPals, 0, sizeof(gIntro2BGPals));
    gTasks[taskId].func = Task_IntroStartUnownSequence;
}

static void Task_UnownFade(u8 taskId)
{
    bool8 isFadingOut = gTasks[taskId].data[0] & 1;
    u32 coeff = isFadingOut ? (u8)gTasks[taskId].data[2] : (u8)(gTasks[taskId].data[1] - gTasks[taskId].data[2]);
    u8 destroyOn = (gTasks[taskId].data[0] & 2) ? 15 : 16;
    coeff *= 16;
    coeff /= gTasks[taskId].data[1];
    gTasks[taskId].data[2]++;
    BlendPalette(0x100, 16, coeff, RGB_BLACK);
    if ((isFadingOut && coeff >= destroyOn) || (!isFadingOut && coeff == 0))
    {
        gUnknown_0203BCC8 = FALSE;
        DestroyTask(taskId);
    }
}

static u8 BeginUnownFade(u8 speed, bool8 isFadingOut, bool8 shouldNotFadeCompletely)
{
    u8 taskId = CreateTask(Task_UnownFade, 0);
    gUnknown_0203BCC8 = TRUE;
    gTasks[taskId].data[0] = isFadingOut | (shouldNotFadeCompletely << 1);
    gTasks[taskId].data[1] = speed;
    gTasks[taskId].data[2] = (!isFadingOut && shouldNotFadeCompletely) ? 1 : 0;
    return taskId;
}

static void Task_IntroStartUnownSequence(u8 taskId)
{
    LoadCompressedObjectPic(gIntro2UnownASpriteSheet);
    LoadCompressedObjectPic(gIntro2UnownPulseSpriteSheet);
    LoadCompressedObjectPic(gIntro2UnownOthersSpriteSheet);
    LoadCompressedObjectPic(gIntro2SuicuneSilhouetteSpriteSheet);
    LoadCompressedObjectPic(gIntro2WooperSpriteSheet);
    LoadCompressedObjectPic(gIntro2PichuSpriteSheet);
    LoadSpritePalettes(gIntro2SpritePalettes);
    LoadSpritePalettes(gSuicuneSilhouetteSpritePalettes);
    gTasks[taskId].data[1] = CreateSprite(&gSpriteTemplate_UnownA, 120, 80, 0);
    BeginUnownFade(32, FALSE, FALSE);
    SetVBlankCallback(VBlankCB_Intro);
    SetGpuReg(REG_OFFSET_BG3CNT, BGCNT_PRIORITY(3)
                               | BGCNT_CHARBASE(0)
                               | BGCNT_SCREENBASE(31)
                               | BGCNT_16COLOR
                               | BGCNT_TXT256x256);
    SetGpuReg(REG_OFFSET_BG2CNT, BGCNT_PRIORITY(2)
                               | BGCNT_CHARBASE(0)
                               | BGCNT_SCREENBASE(29)
                               | BGCNT_16COLOR
                               | BGCNT_TXT256x512);
    SetGpuReg(REG_OFFSET_BG1CNT, BGCNT_PRIORITY(1)
                               | BGCNT_CHARBASE(0)
                               | BGCNT_SCREENBASE(28)
                               | BGCNT_16COLOR
                               | BGCNT_TXT256x256);
    SetGpuReg(REG_OFFSET_WININ, 0x3F);
    SetGpuReg(REG_OFFSET_WINOUT, 0);
    SetGpuReg(REG_OFFSET_WIN0H, 0xF0);
    SetGpuReg(REG_OFFSET_WIN0V, 0x1090);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0
                                | DISPCNT_OBJ_1D_MAP
                                | DISPCNT_OBJ_ON);
    gTasks[taskId].data[0] = 0;
    gTasks[taskId].func = Task_IntroDoUnownASequence;
}

static void CreateUnownPulse(s16 x, s16 y)
{
    u8 spriteId;
    
    CreateSprite(&gSpriteTemplate_UnownPulse, x - 16, y - 16, 0);
    spriteId = CreateSprite(&gSpriteTemplate_UnownPulse, x + 16, y - 16, 0);
    gSprites[spriteId].hFlip = TRUE;
    gSprites[spriteId].oam.matrixNum |= 0x8;
    spriteId = CreateSprite(&gSpriteTemplate_UnownPulse, x - 16, y + 16, 0);
    gSprites[spriteId].vFlip = TRUE;
    gSprites[spriteId].oam.matrixNum |= 0x10;
    spriteId = CreateSprite(&gSpriteTemplate_UnownPulse, x + 16, y + 16, 0);
    gSprites[spriteId].hFlip = TRUE;
    gSprites[spriteId].vFlip = TRUE;
    gSprites[spriteId].oam.matrixNum |= 0x18;
}

static void Task_FadeScreenAndPulse(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    switch (data[0])
    {
    case 0:
        if (!gUnknown_0203BCC8)
        {
            data[2] = BeginUnownFade(32, FALSE, FALSE);
            data[0]++;
        }
        break;
    case 1:
        if (gTasks[data[2]].data[2] == 28)
        {
            StartSpriteAffineAnim(&gSprites[data[1]], 1);
            data[0]++;
        }
        break;
    case 2:
        if (!gUnknown_0203BCC8)
        {
            CreateUnownPulse(gSprites[data[1]].pos1.x, gSprites[data[1]].pos1.y);
            data[2] = BeginUnownFade(32, TRUE, FALSE);
            DestroyTask(taskId);
        }
        break;
    }
}

static void Task_IntroDoUnownASequence(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    u8 newTaskId;

    if (gIntroFrameCounter == 32)
        BeginUnownFade(32, TRUE, FALSE);
    
    if (gIntroFrameCounter == 64)
    {
        CreateTask(Task_FadeScreenAndPulse, 0);
        gTasks[newTaskId].data[1] = data[1];
    }
    
    if (gIntroFrameCounter == 170)
        DestroySprite(&gSprites[data[1]]);
    
    if (gIntroFrameCounter == 173)
    {
        data[2] = CreateTask(Task_ScrollTreeGrassBackgrounds, 0);
        gTasks[data[2]].data[0] = 0;
        gTasks[data[2]].data[1] = 0;
        gTasks[data[2]].data[2] = 1;
    }
    
    if (gIntroFrameCounter == 303)
        gTasks[data[2]].data[0] = 2;
    
    if (gIntroFrameCounter == 370)
    {
        gTasks[taskId].data[1] = CreateSprite(&gSpriteTemplate_UnownOthers, 170, 50, 0);
        CreateTask(Task_FadeScreenAndPulse, 0);
        gTasks[newTaskId].data[1] = data[1];
    }
    
    if (gIntroFrameCounter == 434)
    {
        StartSpriteAnim(&gSprites[data[1]], 1);
        gSprites[data[1]].pos1.x = 60;
        gSprites[data[1]].pos1.y = 110;
        CreateTask(Task_FadeScreenAndPulse, 0);
        gTasks[newTaskId].data[1] = data[1];
    }
    
    if (gIntroFrameCounter == 600)
    {
        gSprites[data[1]].invisible = TRUE;
        gTasks[taskId].func = Task_IntroDoSuicuneRunAcrossScreen;
    }
}

static void Task_ScrollTreeGrassBackgrounds(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    
    switch (data[0])
    {
    case 0:
        SetGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_BG1_ON
                                        | DISPCNT_BG2_ON
                                        | DISPCNT_BG3_ON
                                        | DISPCNT_WIN0_ON);
        data[0]++;
        break;
    case 1:
        ((u16)data[1]) += data[2];
        SetGpuReg(REG_OFFSET_BG1HOFS, ((u16)data[1]) << 1);
        SetGpuReg(REG_OFFSET_BG2HOFS, ((u16)data[1]) >> 1);
        SetGpuReg(REG_OFFSET_BG3HOFS, ((u16)data[1]) >> 1);
        break;
    case 2:
        ClearGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_BG1_ON
                                          | DISPCNT_BG2_ON
                                          | DISPCNT_BG3_ON
                                          | DISPCNT_WIN0_ON);
        SetGpuReg(REG_OFFSET_BG1HOFS, 0);
        SetGpuReg(REG_OFFSET_BG2HOFS, 0);
        SetGpuReg(REG_OFFSET_BG3HOFS, 0);
        DestroyTask(taskId);
        break;
    case 3:
        ((u16)data[1]) += data[2];
        SetGpuReg(REG_OFFSET_BG1HOFS, (((u16)data[1]) << 1) + 1);
        DestroyTask(taskId);
    }
}

static void SpriteCallback_UnownPulse(struct Sprite *sprite)
{
    if (sprite->hFlip)
        sprite->pos1.x += 2;
    else
        sprite->pos1.x -= 2;
    
    if (sprite->vFlip)
        sprite->pos1.y += 2;
    else
        sprite->pos1.y -= 2;
    
    if (sprite->animEnded)
        DestroySprite(sprite);
}

static void Task_ShakeGrass(u8 taskId)
{
    gTasks[taskId].data[0]++;
    
    if (gTasks[taskId].data[1]++ > 5)
    {
        gTasks[taskId].data[1] = 0;
        gTasks[taskId].data[2] ^= TRUE;
    }
    
    if (gTasks[taskId].data[2] == FALSE)
        SetGpuReg(REG_OFFSET_BG2VOFS, 160);
    else
        SetGpuReg(REG_OFFSET_BG2VOFS, 0);
    
    if (gTasks[taskId].data[0] == 40)
        DestroyTask(taskId);
}

static void Task_IntroDoSuicuneRunAcrossScreen(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    
    if (gIntroFrameCounter == 601)
    {
        data[2] = CreateTask(Task_ScrollTreeGrassBackgrounds, 0);
        gTasks[data[2]].data[0] = 0;
        gTasks[data[2]].data[1] = 0;
        gTasks[data[2]].data[2] = 1;
    }
    
    if (gIntroFrameCounter == 665)
    {
        DestroyTask(data[2]);
        data[2] = CreateSprite(&gSpriteTemplate_SuicuneSilhouette, 272, 68, 0);
        gSprites[data[2]].data[0] = -10;
        gSprites[data[2]].data[1] = 0;
    }
    
    if (gIntroFrameCounter == 710)
        CreateTask(Task_ShakeGrass, 0);
    
    if (gIntroFrameCounter == 738)
        data[2] = CreateSprite(&gSpriteTemplate_Wooper, 60, 135, 0);
    
    if (gIntroFrameCounter == 770)
    {
        data[3] = CreateSprite(&gSpriteTemplate_Pichu, 170, 135, 0);
        gSprites[data[3]].data[2] = TRUE;
    }
    
    if (gIntroFrameCounter == 898)
    {
        DestroySprite(&gSprites[data[2]]);
        DestroySprite(&gSprites[data[3]]);
        ClearGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_BG1_ON
                                          | DISPCNT_BG2_ON
                                          | DISPCNT_BG3_ON
                                          | DISPCNT_OBJ_ON  // fix for DestroySprite not being as fast as GPU regs being set
                                          | DISPCNT_WIN0_ON);
    }
    
    if (gIntroFrameCounter == 946)
    {
        SetGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON);
        StartSpriteAnim(&gSprites[data[1]], 2);
        gSprites[data[1]].pos1.x = 100;
        gSprites[data[1]].pos1.y = 74;
        gSprites[data[1]].invisible = FALSE;
        BeginUnownFade(16, FALSE, FALSE);
        gTasks[taskId].func = Task_FlashMultipleUnowns;
    }
}

static void Task_FlashMultipleUnowns(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    switch (data[0])
    {
    case 0:
    case 2:
    case 4:
    case 6:
        if (!gUnknown_0203BCC8)
        {
            BeginUnownFade(16, TRUE, TRUE);
            data[0]++;
        }
        break;
    case 1:
        if (!gUnknown_0203BCC8)
        {
            StartSpriteAnim(&gSprites[data[1]], 3);
            gSprites[data[1]].pos1.x = 190;
            gSprites[data[1]].pos1.y = 40;
            BeginUnownFade(16, FALSE, TRUE);
            data[0]++;
        }
        break;
    case 3:
        if (!gUnknown_0203BCC8)
        {
            StartSpriteAnim(&gSprites[data[1]], 4);
            gSprites[data[1]].pos1.x = 50;
            gSprites[data[1]].pos1.y = 70;
            BeginUnownFade(16, FALSE, TRUE);
            data[0]++;
        }
        break;
    case 5:
        if (!gUnknown_0203BCC8)
        {
            StartSpriteAnim(&gSprites[data[1]], 5);
            gSprites[data[1]].pos1.x = 130;
            gSprites[data[1]].pos1.y = 130;
            BeginUnownFade(16, FALSE, TRUE);
            data[0]++;
        }
        break;
    case 7:
        if (!gUnknown_0203BCC8)
        {
            StartSpriteAnim(&gSprites[data[1]], 6);
            gSprites[data[1]].pos1.x = 110;
            gSprites[data[1]].pos1.y = 30;
            BeginUnownFade(8, FALSE, TRUE);
            data[0]++;
        }
        break;
    case 8:
    case 10:
    case 12:
        if (!gUnknown_0203BCC8)
        {
            BeginUnownFade(8, TRUE, TRUE);
            data[0]++;
        }
        break;
    case 9:
        if (!gUnknown_0203BCC8)
        {
            StartSpriteAnim(&gSprites[data[1]], 7);
            gSprites[data[1]].pos1.x = 200;
            gSprites[data[1]].pos1.y = 80;
            BeginUnownFade(8, FALSE, TRUE);
            data[0]++;
        }
        break;
    case 11:
        if (!gUnknown_0203BCC8)
        {
            StartSpriteAnim(&gSprites[data[1]], 8);
            gSprites[data[1]].pos1.x = 40;
            gSprites[data[1]].pos1.y = 120;
            BeginUnownFade(8, FALSE, TRUE);
            data[0]++;
        }
        break;
    case 13:
        if (!gUnknown_0203BCC8)
        {
            StartSpriteAnim(&gSprites[data[1]], 9);
            gSprites[data[1]].pos1.x = 140;
            gSprites[data[1]].pos1.y = 90;
            BeginUnownFade(8, FALSE, TRUE);
            data[0]++;
        }
        break;
    case 14:
        if (!gUnknown_0203BCC8)
        {
            BeginUnownFade(8, TRUE, FALSE);
            gTasks[taskId].func = Task_IntroLoadPart3Graphics;
        }
        break;
    }
}

static void SpriteCallback_SuicuneSilhouette(struct Sprite *sprite)
{
    sprite->pos1.x += sprite->data[0];
    sprite->pos1.y += sprite->data[1];
    
    if (sprite->pos1.x < -32)
        DestroySprite(sprite);
}

static void SpriteCallback_PopUpPkmn(struct Sprite *sprite)
{
    switch (sprite->data[0])
    {
    case 0:
        sprite->data[1] = 10;
        sprite->data[0]++;
    case 1:
        if (sprite->data[1] > 4)
        {
            sprite->pos1.y -= (sprite->data[1]--);
            break;
        }
        else
        {
            sprite->data[1] = 4;
            sprite->data[0]++;
        }
    case 2:
        if (sprite->data[1] > 0)
        {
            sprite->pos1.y += (sprite->data[1]--) >> 1;
            break;
        }
        else
        {
            sprite->data[0]++;
        }
    case 3:
        if (sprite->data[2])
            StartSpriteAnim(sprite, 1);
        sprite->callback = SpriteCallbackDummy;
        break;
    }
}

static void Task_ScrollTreeGrassBackgrounds2(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    
    ((u16)data[1]) -= 20;
    ((u16)data[2]) -= 12;
    SetGpuReg(REG_OFFSET_BG1HOFS, ((u16)data[1]));
    SetGpuReg(REG_OFFSET_BG2HOFS, ((u16)data[2]));
    SetGpuReg(REG_OFFSET_BG3HOFS, ((u16)data[2]));
}

static void Task_IntroLoadPart3Graphics(u8 taskId)
{
    if (gIntroFrameCounter > 1220)
    {
        s16 *data = gTasks[taskId].data;

        intro_reset_and_hide_bgs();
        ResetSpriteData();
        FreeAllSpritePalettes();
        
        LoadCompressedObjectPic(gIntro2SuicuneSilhouetteSpriteSheet);
        LoadSpritePalettes(gSuicuneSilhouetteSpritePalettes);
        
        data[0] = 0;
        data[1] = CreateTask(Task_ScrollTreeGrassBackgrounds2, 0);
        data[2] = CreateSprite(&gSpriteTemplate_SuicuneSilhouette, 120, 68, 0);
        gTasks[taskId].func = Task_IntroStartPart3;
    }
}

static void Task_IntroStartPart3(u8 taskId)
{
    gTasks[taskId].func = Task_IntroDoSuicuneRunningInPlace;
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0
                                | DISPCNT_OBJ_1D_MAP
                                | DISPCNT_BG1_ON
                                | DISPCNT_BG2_ON
                                | DISPCNT_BG3_ON
                                | DISPCNT_OBJ_ON
                                | DISPCNT_WIN0_ON);
    gIntroFrameCounter = 0;
    //m4aSongNumStart(MUS_T_BATTLE);
}

static void Task_IntroDoSuicuneRunningInPlace(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    
    if (gIntroFrameCounter == 66)
    {
        gSprites[data[2]].data[0] = -3;
    }
    
    if (gIntroFrameCounter == 96)
    {
        StartSpriteAnim(&gSprites[data[2]], 1);
        gSprites[data[2]].data[0] = -8;
        gSprites[data[2]].data[1] = -3;
    }
    
    if (gIntroFrameCounter == 130)
    {
        DestroySprite(&gSprites[data[2]]);
        DestroySprite(&gSprites[data[3]]);
        DestroyTask(data[1]);
        ClearGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_BG1_ON
                                          | DISPCNT_BG2_ON
                                          | DISPCNT_BG3_ON
                                          | DISPCNT_WIN0_ON);
        gTasks[taskId].func = Task_IntroWaitToSetupFallingSuicune;
    }
}

static void Task_IntroWaitToSetupFallingSuicune(u8 taskId)
{
    if (gIntroFrameCounter > 190)
        gTasks[taskId].func = Task_IntroLoadPart3Graphics1;
}

static void Task_IntroLoadPart3Graphics1(u8 taskId)
{
    intro_reset_and_hide_bgs();
    ResetSpriteData();
    FreeAllSpritePalettes();
    LZ77UnCompVram(gBattleAnimBackgroundImage_17, (void *)VRAM);
    LZ77UnCompVram(gIntro3BG3_Tiles, (void *)VRAM + 0x400);
    LZ77UnCompVram(gBattleAnimBackgroundTilemap_17, (void *)(VRAM + 0xF800));
    LZ77UnCompVram(gIntro3BG3_Tilemap, (void *)(VRAM + 0xD800));
    LoadCompressedObjectPic(gIntro3SuicuneSpriteSheet);
    LoadCompressedObjectPic(gIntro3UnownFSpriteSheet);
    LoadCompressedObjectPic(gIntro2UnownOthersSpriteSheet);
    LoadPalette(gIntro3BG3_Pals, 0x10, sizeof(gIntro3BG3_Pals));
    LoadSpritePalettes(gIntro3SpritePalettes);
    gTasks[taskId].data[1] = IndexOfSpritePaletteTag(gIntro3SpritePalettes[1].tag) + 16;
    BlendPalette(gTasks[taskId].data[1] * 16, 16, 16, RGB(31, 31, 16));
    gTasks[taskId].func = Task_IntroLoadPart3Graphics2;
}

static void Task_ScrollFallingBG(u8 taskId)
{
    SetGpuReg(REG_OFFSET_BG3VOFS, gTasks[taskId].data[0] -= 12);
}

static void Task_IntroLoadPart3Graphics2(u8 taskId)
{
    u8 windowTaskId;
    
    SetGpuReg(REG_OFFSET_WIN0H, 0xF0);
    SetGpuReg(REG_OFFSET_WIN0V, 0x5050);
    SetGpuReg(REG_OFFSET_WININ, 0x3F);
    SetGpuReg(REG_OFFSET_WINOUT, 0);
    SetGpuReg(REG_OFFSET_BG2HOFS, -240);
    SetGpuReg(REG_OFFSET_BG3CNT, BGCNT_PRIORITY(3)
                               | BGCNT_CHARBASE(0)
                               | BGCNT_SCREENBASE(31)
                               | BGCNT_16COLOR
                               | BGCNT_TXT256x256);
    SetGpuReg(REG_OFFSET_BG2CNT, BGCNT_PRIORITY(2)
                               | BGCNT_CHARBASE(0)
                               | BGCNT_SCREENBASE(27)
                               | BGCNT_16COLOR
                               | BGCNT_TXT512x512);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0
                                | DISPCNT_OBJ_1D_MAP
                                | DISPCNT_BG3_ON
                                | DISPCNT_OBJ_ON
                                | DISPCNT_WIN0_ON);
    gTasks[taskId].data[0] = CreateTask(Task_ScrollFallingBG, 0);
    windowTaskId = CreateTask(Task_WindowOpen, 0);
    gTasks[windowTaskId].data[0] = 0x50;
    gTasks[windowTaskId].data[1] = 0x10;
    gTasks[windowTaskId].data[2] = -8;
    gTasks[taskId].func = Task_IntroSuicuneFlyUp;
}

static void Task_SlideSuicuneMugIn(u8 taskId)
{
    switch (gTasks[taskId].data[0])
    {
    case 0:
        SetGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_BG2_ON);
        gTasks[taskId].data[1] = -240;
        gTasks[taskId].data[0]++;
    case 1:
        if (gTasks[taskId].data[1] < -8)
        {
            gTasks[taskId].data[1] += 8;
        }
        else if (gTasks[taskId].data[3]++ > 7)
        {
            gTasks[taskId].data[3] = 0;
            gTasks[taskId].data[1]++;
        }
        
        if (gIntroFrameCounter == 500)
            gTasks[taskId].data[0]++;
        else
            SetGpuReg(REG_OFFSET_BG2HOFS, gTasks[taskId].data[1]);
        break;
    case 2:
        if (gTasks[taskId].data[2] > -160)
        {
            gTasks[taskId].data[2] -= 8;
            SetGpuReg(REG_OFFSET_BG2VOFS, gTasks[taskId].data[2]);
        }
        else
        {
            ClearGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_BG2_ON);
            DestroyTask(taskId);
            return;
        }
        break;
    }
    
}

static void Task_IntroSuicuneFlyUp(u8 taskId)
{
    u8 newTaskId;
    u8 spriteId;
    u8 index;
    
    if (gIntroFrameCounter == 196)
        gTasks[taskId].data[2] = CreateSprite(&gSpriteTemplate_Suicune, 160, 192, 0);
    
    if (gIntroFrameCounter == 260)
        gTasks[taskId].data[3] = CreateSprite(&gSpriteTemplate_UnownF, 70, 60, 0);
    
    if (gIntroFrameCounter == 272)
    {
        BeginNormalPaletteFade(1 << gTasks[taskId].data[1], 0, 16, 0, RGB(31, 31, 16));
        gSprites[gTasks[taskId].data[3]].data[0] = 1;
    }
    
    if (gIntroFrameCounter == 343)
    {
        gSprites[gTasks[taskId].data[2]].data[0] = 2;
        gSprites[gTasks[taskId].data[3]].data[0] = 2;
    }
    
    if (gIntroFrameCounter == 390)
        CreateTask(Task_SlideSuicuneMugIn, 0);
    
    if (gIntroFrameCounter == 400)
    {
        newTaskId = CreateTask(Task_WindowOpen, 0);
        gTasks[newTaskId].data[0] = 0x10;
        gTasks[newTaskId].data[1] = 0x20;
        gTasks[newTaskId].data[2] = 1;
    }
    
    if (gIntroFrameCounter == 500)
    {
        newTaskId = CreateTask(Task_WindowOpen, 0);
        gTasks[newTaskId].data[0] = 0x20;
        gTasks[newTaskId].data[1] = 0x10;
        gTasks[newTaskId].data[2] = -1;
    }
    
    if (gIntroFrameCounter == 560)
    {
        gSprites[gTasks[taskId].data[2]].data[0] = 4;
        gSprites[gTasks[taskId].data[2]].pos1.x = 120;
        gSprites[gTasks[taskId].data[2]].pos1.y = 192;
        StartSpriteAnim(&gSprites[gTasks[taskId].data[2]], 1);
    }
    
    if (gIntroFrameCounter == 638)
    {
        // U
        spriteId = CreateSprite(&gSpriteTemplate_UnownOthers, 40, 80, 0);
        StartSpriteAnim(&gSprites[spriteId], 2);
        StartSpriteAffineAnim(&gSprites[spriteId], 2);
    }
    
    if (gIntroFrameCounter == 642)
    {
        // E
        spriteId = CreateSprite(&gSpriteTemplate_UnownOthers, 200, 86, 0);
        StartSpriteAnim(&gSprites[spriteId], 7);
        StartSpriteAffineAnim(&gSprites[spriteId], 2);
    }
    
    if (gIntroFrameCounter == 646)
    {
        // B
        spriteId = CreateSprite(&gSpriteTemplate_UnownOthers, 100, 30, 0);
        StartSpriteAnim(&gSprites[spriteId], 6);
        StartSpriteAffineAnim(&gSprites[spriteId], 2);
    }
    
    if (gIntroFrameCounter == 650)
    {
        // H
        spriteId = CreateSprite(&gSpriteTemplate_UnownOthers, 80, 124, 0);
        StartSpriteAnim(&gSprites[spriteId], 1);
        StartSpriteAffineAnim(&gSprites[spriteId], 2);
    }
    
    if (gIntroFrameCounter == 654)
    {
        // T
        spriteId = CreateSprite(&gSpriteTemplate_UnownOthers, 150, 30, 0);
        StartSpriteAnim(&gSprites[spriteId], 5);
        StartSpriteAffineAnim(&gSprites[spriteId], 2);
        // S
        spriteId = CreateSprite(&gSpriteTemplate_UnownOthers, 150, 120, 0);
        StartSpriteAnim(&gSprites[spriteId], 8);
        StartSpriteAffineAnim(&gSprites[spriteId], 2);
    }
    
    if (gIntroFrameCounter == 658)
    {
        // G
        spriteId = CreateSprite(&gSpriteTemplate_UnownOthers, 60, 44, 0);
        StartSpriteAnim(&gSprites[spriteId], 4);
        StartSpriteAffineAnim(&gSprites[spriteId], 2);
        // W
        spriteId = CreateSprite(&gSpriteTemplate_UnownOthers, 180, 60, 0);
        StartSpriteAnim(&gSprites[spriteId], 3);
        StartSpriteAffineAnim(&gSprites[spriteId], 2);
    }
    
    if (gIntroFrameCounter == 710)
    {
        index = IndexOfSpritePaletteTag(gIntro3SpritePalettes[0].tag) + 16;
        BeginNormalPaletteFade(1 << index, 1, 0, 16, RGB_BLACK);
        StartSpriteAffineAnim(&gSprites[gTasks[taskId].data[2]], 1);
    }
    
    if (gIntroFrameCounter == 740)
    {
        index = IndexOfSpritePaletteTag(gIntro3SpritePalettes[0].tag) + 16;
        FillPalette(RGB_BLACK, index * 16, 32);
        BeginNormalPaletteFade(0xFFFFFFFF, 2, 0, 16, RGB_WHITE);
        gTasks[taskId].func = Task_WaitToDoCrystalDustLogo;
    }
}

static void Task_WaitToDoCrystalDustLogo(u8 taskId)
{
    if (gIntroFrameCounter == 902)
    {
        intro_reset_and_hide_bgs();
        ResetSpriteData();
        FreeAllSpritePalettes();
        FillPalette(RGB_WHITE, 0, 32);
        LZ77UnCompVram(gIntro3Name_Tiles, (void *)VRAM);
        LZ77UnCompVram(gIntro3Name_Tilemap, (void *)(VRAM + 0xF800));
        CpuCopy16(gIntro3NamePalette, gPlttBufferUnfaded, 32);
        CpuCopy16(gIntro3NamePalette, gPlttBufferUnfaded + 16, 32);
        gPlttBufferUnfaded[0] = RGB_WHITE;
        SetGpuReg(REG_OFFSET_BG0CNT, BGCNT_PRIORITY(0)
                                   | BGCNT_CHARBASE(0)
                                   | BGCNT_SCREENBASE(31)
                                   | BGCNT_16COLOR
                                   | BGCNT_TXT256x256);
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 | DISPCNT_OBJ_1D_MAP | DISPCNT_BG0_ON);
        gTasks[taskId].func = Task_DoCrystalDustLogo;
        gTasks[taskId].data[0] = 2;
        gTasks[taskId].data[1] = 0;
    }
}

static void Task_DoCrystalDustLogo(u8 taskId)
{
    if (gTasks[taskId].data[1] == 16)
    {
        gTasks[taskId].data[0] += 2;
        gTasks[taskId].data[1] = 0;
    }
    else if (gTasks[taskId].data[0] < 26)
    {
        if (gTasks[taskId].data[0] == 16)
            gTasks[taskId].data[0] += 2;
        gTasks[taskId].data[1] += 2;
        BlendPalette(gTasks[taskId].data[0], 2, 16 - gTasks[taskId].data[1], RGB_WHITE);
    }
    else if (gIntroFrameCounter == 1096)
    {
        BeginNormalPaletteFade(0xFFFFFFFF, 2, 0, 16, RGB_WHITE);
        gTasks[taskId].func = Task_IntroFadeToTitle;
    }
}

static void Task_IntroFadeToTitle(u8 taskId)
{
    if (gIntroFrameCounter == 1150)
    {
        DestroyTask(taskId);
        SetMainCallback2(MainCB2_EndIntro);
    }
}

static void SpriteCallback_Suicune(struct Sprite *sprite)
{
    switch (sprite->data[0])
    {
    case 0:
        if (sprite->pos1.y > 88)
            sprite->pos1.y -= 8;
        else
            sprite->data[0]++;
        break;
    case 1:
        if (sprite->data[1]++ > 15)
        {
            sprite->data[1] = 0;
            sprite->pos1.y--;
        }
        break;
    case 2:
        if (sprite->pos1.x < 272)
            sprite->pos1.x += 8;
        else
            sprite->data[0]++;
        break;
    case 4:
        if (sprite->pos1.y > 80)
            sprite->pos1.y -= 2;
        break;
    }
}

static void SpriteCallback_UnownF(struct Sprite *sprite)
{
    switch (sprite->data[0])
    {
    case 1:
        sprite->data[1] = (sprite->data[1] + 1) & 0xFF;
        sprite->pos1.y = Sin(sprite->data[1]++, 4) + 60;
        break;
    case 2:
        if (sprite->pos1.x > -32)
            sprite->pos1.x -= 8;
        else
            DestroySprite(sprite);
        break;
    }
}

static void intro_reset_and_hide_bgs(void)
{
    SetGpuReg(REG_OFFSET_DISPCNT, 0);
    SetGpuReg(REG_OFFSET_BG3HOFS, 0);
    SetGpuReg(REG_OFFSET_BG3VOFS, 0);
    SetGpuReg(REG_OFFSET_BG2HOFS, 0);
    SetGpuReg(REG_OFFSET_BG2VOFS, 0);
    SetGpuReg(REG_OFFSET_BG1HOFS, 0);
    SetGpuReg(REG_OFFSET_BG1VOFS, 0);
    SetGpuReg(REG_OFFSET_BG0HOFS, 0);
    SetGpuReg(REG_OFFSET_BG0VOFS, 0);
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    SetGpuReg(REG_OFFSET_BLDALPHA, 0);
    SetGpuReg(REG_OFFSET_BLDY, 0);
}

void sub_816F2A8(u16 scrX, u16 scrY, u16 zoom, u16 alpha)
{
    struct BgAffineSrcData src;
    struct BgAffineDstData dest;

    src.texX = 0x8000;
    src.texY = 0x8000;
    src.scrX = scrX;
    src.scrY = scrY;
    src.sx = zoom;
    src.sy = zoom;
    src.alpha = alpha;
    BgAffineSet(&src, &dest, 1);
    SetGpuReg(REG_OFFSET_BG2PA, dest.pa);
    SetGpuReg(REG_OFFSET_BG2PB, dest.pb);
    SetGpuReg(REG_OFFSET_BG2PC, dest.pc);
    SetGpuReg(REG_OFFSET_BG2PD, dest.pd);
    SetGpuReg(REG_OFFSET_BG2X_L, dest.dx);
    SetGpuReg(REG_OFFSET_BG2X_H, dest.dx >> 16);
    SetGpuReg(REG_OFFSET_BG2Y_L, dest.dy);
    SetGpuReg(REG_OFFSET_BG2Y_H, dest.dy >> 16);
}
