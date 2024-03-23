#ifndef GUARD_TEXT_WINDOW_H
#define GUARD_TEXT_WINDOW_H

#define WINDOW_FRAMES_COUNT 20

struct TilesPal
{
    const u8 *tiles;
    const u16 *pal;
};

extern const u8 gTextWindowFrame1_Gfx[];
extern const u16 gTextWindowFrame1_Pal[];

const struct TilesPal *GetWindowFrameTilesPal(u8 id);
void LoadMessageBoxGfx(u32 windowId, u16 destOffset, u8 palOffset);
void LoadSignMessageBoxGfx(u32 windowId, u16 destOffset, u8 palOffset);
void LoadThinWindowBorderGfx(u32 windowId, u16 destOffset, u8 palOffset);
void LoadThinWindowBorderTiles(u32 windowId, u16 destOffset);
void LoadUserWindowBorderGfx(u32 windowId, u16 destOffset, u8 palOffset);
void LoadWindowGfx(u32 windowId, u8 frameId, u16 destOffset, u8 palOffset);
void LoadUserWindowBorderGfx_(u32 windowId, u16 destOffset, u8 palOffset);
void DrawTextBorderOuter(u32 windowId, u16 tileNum, u8 palNum);
void DrawTextBorderInner(u32 windowId, u16 tileNum, u8 palNum);
void rbox_fill_rectangle(u32 windowId);
const u16 *GetTextWindowPalette(u8 id);
void sub_8098C6C(u8 bg, u16 destOffset, u8 palOffset);

#endif // GUARD_TEXT_WINDOW_H
