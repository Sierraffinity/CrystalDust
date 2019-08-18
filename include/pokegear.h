#ifndef GUARD_POKEGEAR_H
#define GUARD_POKEGEAR_H

extern const struct SpriteTemplate sSpriteTemplate_Digits;
extern const struct SpritePalette gSpritePalette_PokegearMenuSprites;
extern const struct SpriteSheet sSpriteSheet_DigitTiles;

void CB2_InitPokegear(void);
void InitPokegearPhoneCall(u8 taskId);
void HangupPokegearPhoneCall(void);

#endif //GUARD_POKEGEAR_H
