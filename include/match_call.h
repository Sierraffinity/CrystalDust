#ifndef GUARD_MATCH_CALL_H
#define GUARD_MATCH_CALL_H

enum {
    MATCH_CALL_TYPE_NON_TRAINER,
    MATCH_CALL_TYPE_TRAINER,
    MATCH_CALL_TYPE_WALLY,
    MATCH_CALL_TYPE_BIRCH,
    MATCH_CALL_TYPE_MAY_BRENDAN,
    MATCH_CALL_TYPE_GYMLEADER_ELITEFOUR
};

struct MomItemTable {
    u32 threshold;
    u16 price;
    bool8 itemType; // TRUE for Doll, False for item
    u8 item; // no item indices bought by mom are > 255, so u8 is enough.
};

s32 GetRematchIdxByTrainerIdx(s32 trainerIdx);
void InitMatchCallCounters(void);
bool32 SelectMatchCallMessage(int trainerId, u8 *str, bool8 isCallingPlayer);
bool32 TryStartMatchCall(void);
bool32 TryStartForcedMatchCall(void);
u8 EndOverworldPhoneCall(void);
bool32 ExecuteMatchCallTextPrinter(int windowId);
void Task_InitOverworldPhoneCall(u8 taskId);
void StartMatchCallFromScript(const u8 *script, u8 callerId);
void BufferPokedexRatingForMatchCall(u8 *destStr);
void LoadMatchCallWindowGfx2(u32 windowId, u32 destOffset, u32 paletteId);
void DrawMatchCallTextBoxBorder_Internal(u32 windowId, u32 tileOffset, u32 paletteId);
bool32 CleanupAfterMatchCallHangup(void);
void DrawMatchCallTextBoxBorder(u32 windowId, u32 tileOffset, u32 paletteId);
bool32 MapAllowsMatchCall(void);
void MomTriesToBuySomething(void);

#endif //GUARD_MATCH_CALL_H
