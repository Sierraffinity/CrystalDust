const struct MonCoords gTrainerBackPicCoords[] =
{
    {.size = 8, .y_offset = 4},
    {.size = 8, .y_offset = 4},
    {.size = 8, .y_offset = 5},
    {.size = 8, .y_offset = 5},
    {.size = 8, .y_offset = 4},
    {.size = 8, .y_offset = 4},
    {.size = 8, .y_offset = 4},
    {.size = 8, .y_offset = 4},
};

// this table goes functionally unused, since none of these pics are compressed
// and the place they would get extracted to gets overwritten later anyway
// the casts are so they'll play nice with the strict struct definition
const struct CompressedSpriteSheet gTrainerBackPicTable[] =
{
    (const u32 *)gTrainerBackPic_Gold, 0x2000, 0,
    (const u32 *)gTrainerBackPic_Kris, 0x2000, 1,
    (const u32 *)gTrainerBackPic_Brendan, 0x2000, 2,
    (const u32 *)gTrainerBackPic_May, 0x2000, 3,
    (const u32 *)gTrainerBackPic_Red, 0x2800, 4,
    (const u32 *)gTrainerBackPic_Leaf, 0x2800, 5,
    (const u32 *)gTrainerBackPic_RubySapphireBrendan, 0x2000, 6,
    (const u32 *)gTrainerBackPic_RubySapphireMay, 0x2000, 7,
    (const u32 *)gTrainerBackPic_Wally, 0x2000, 8,
    (const u32 *)gTrainerBackPic_Steven, 0x2000, 9,
};

const struct CompressedSpritePalette gTrainerBackPicPaletteTable[] = 
{
    gTrainerBackPicPalette_Gold, 0,
    gTrainerPalette_May, 1,
    gTrainerPalette_Brendan, 2,
    gTrainerPalette_May, 3,
    gTrainerBackPicPalette_Red, 4,
    gTrainerBackPicPalette_Leaf, 5,
    gTrainerPalette_RubySapphireBrendan, 6,
    gTrainerPalette_RubySapphireMay, 7,
    gTrainerPalette_Wally, 8,
    gTrainerPalette_Steven, 9,
};
