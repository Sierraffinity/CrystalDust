#ifndef GUARD_POKEBALL_H
#define GUARD_POKEBALL_H

enum {
    BALL_AFFINE_ANIM_0,
    BALL_ROTATE_RIGHT,
    BALL_ROTATE_LEFT, 
    BALL_AFFINE_ANIM_3,
    BALL_AFFINE_ANIM_4
};

enum
{
    BALLGFX_POKE,
    BALLGFX_GREAT,
    BALLGFX_SAFARI,
    BALLGFX_ULTRA,
    BALLGFX_MASTER,
    BALLGFX_NET,
    BALLGFX_DIVE,
    BALLGFX_NEST,
    BALLGFX_REPEAT,
    BALLGFX_TIMER,
    BALLGFX_LUXURY,
    BALLGFX_PREMIER,
    BALLGFX_LEVEL,
    BALLGFX_LURE,
    BALLGFX_MOON,
    BALLGFX_FRIEND,
    BALLGFX_FAST,
    BALLGFX_HEAVY,
    BALLGFX_LOVE,
    BALLGFX_PARK,
    BALLGFX_COUNT
};

enum
{
    BALL_NONE,
    BALL_MASTER,
    BALL_ULTRA,
    BALL_GREAT,
    BALL_POKE,
    BALL_SAFARI,
    BALL_NET,
    BALL_DIVE,
    BALL_NEST,
    BALL_REPEAT,
    BALL_TIMER,
    BALL_LUXURY,
    BALL_PREMIER,
    BALL_LEVEL,
    BALL_LURE,
    BALL_MOON,
    BALL_FRIEND,
    BALL_FAST,
    BALL_HEAVY,
    BALL_LOVE,
    BALL_PARK
};

#define POKEBALL_COUNT BALLGFX_COUNT
#define IS_ITEM_BALL(x) ((x) <= ITEM_PREMIER_BALL || ((x) >= ITEM_LEVEL_BALL && (x) <= ITEM_PARK_BALL))
#define ITEM_ID_TO_BALL_ID(x) (((x) >= ITEM_LEVEL_BALL && (x) <= ITEM_PARK_BALL) ? (((x) - ITEM_LEVEL_BALL) + BALL_LEVEL) : (x))

extern const struct SpriteTemplate gBallSpriteTemplates[];

#define POKEBALL_PLAYER_SENDOUT     0xFF
#define POKEBALL_OPPONENT_SENDOUT   0xFE

u8 DoPokeballSendOutAnimation(s16 pan, u8 kindOfThrow);
void CreatePokeballSpriteToReleaseMon(u8 monSpriteId, u8 battler, u8 x, u8 y, u8 oamPriority, u8 subpriortiy, u8 g, u32 h, u16 species);
u8 CreateTradePokeballSprite(u8 a, u8 b, u8 x, u8 y, u8 oamPriority, u8 subPriority, u8 g, u32 h);
void StartHealthboxSlideIn(u8 battler);
void DoHitAnimHealthboxEffect(u8 battler);
void LoadBallGfx(u8 ballId);
void FreeBallGfx(u8 ballId);

#endif // GUARD_POKEBALL_H
