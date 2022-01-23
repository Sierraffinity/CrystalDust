#ifndef GUARD_ITEM_PC_H
#define GUARD_ITEM_PC_H

#include "main.h"

void ItemPc_Init(u8 kind, MainCallback callback);
void ItemPc_SetInitializedFlag(bool8 flag);
void ItemPc_CB2_ReturnFromPartyMenu(void);
u16 ItemPc_GetItemIdBySlotId(u16 itemIndex);
u8 ItemPc_GetCursorPosition(void);

#endif //GUARD_ITEM_PC_H
