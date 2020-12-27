#ifndef GUARD_POKEGEAR_H
#define GUARD_POKEGEAR_H

extern const struct SpriteTemplate sSpriteTemplate_Digits;
extern const struct SpritePalette gSpritePalette_PokegearMenuSprites;
extern const struct SpriteSheet sSpriteSheet_DigitTiles;

void CB2_InitPokegear(void);
void Task_InitPokegearPhoneCall(u8 taskId);
void EndPokegearPhoneCall(void);
void DrawPhoneCallTextBoxBorder(u32 windowId, u32 tileOffset, u32 paletteId);
void PhoneCard_RefreshContactList(void);

#endif //GUARD_POKEGEAR_H
