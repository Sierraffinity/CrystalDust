#ifndef GUARD_MATCH_CALL_H
#define GUARD_MATCH_CALL_H

#include "phone_contact.h"
#include "constants/maps.h"
#include "constants/region_map_sections.h"

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
void SelectMatchCallMessage_Opening(int trainerId, u8 *str, bool8 isCallingPlayer, const struct PhoneContact *phoneContact);
bool32 SelectMatchCallMessage(int trainerId, u8 *str, bool8 isCallingPlayer, const struct PhoneContact *phoneContact);
void SelectMatchCallMessage_Hangup(int trainerId, u8 *str, bool8 isCallingPlayer, const struct PhoneContact *phoneContact);
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
void isPlayerBeingCalled(const struct PhoneContact *, bool8);
void UpdateForcedCallsPerDay();
u32 getRematchIdFromTrainerId(int trainerId);
bool8 CanMatchCallIdAcceptRematch(int matchCallId, s8 dayOfWeek, s8 hour);
int GetTrainerMatchCallId(int);

#define OUTBREAK_WALKING 1
#define OUTBREAK_SURFING 2
#define OUTBREAK_FISHING 3

struct massOutbreakPhoneCallData{
    u16 species;
    u8 location_map_num;
    u8 location_map_group;
    u8 probability;
    u8 level;
    u8 wildState;
    u8 specialLevel1;
    u8 specialLevel2;
};

#define NUM_STRVARS_IN_MSG 3

struct MatchCallText
{
    const u8 *text;
    s8 stringVarFuncIds[NUM_STRVARS_IN_MSG];
};

struct MatchCallTrainerTextInfo
{
    u16 trainerId;
    u16 unused;
    u8 battleFrontierRecordStreakTextIndex;
    u16 rematchOfferedFlag;
    u16 rematchCheckFlags[4];
    u16 giftFlag;
    u8 genericStartIndex;
    u8 genericTextsAmount;
    struct massOutbreakPhoneCallData outbreakData;
    struct MatchCallText callTexts[3];
    struct MatchCallText answerTexts[3];
    struct MatchCallText giftText;
    struct MatchCallText rematchText;
    struct MatchCallText outbreakText;
    struct MatchCallText remindGiftText;
    struct MatchCallText remindRematchText;
    struct MatchCallText remindoutbreakText;
    struct MatchCallText hangupText;
    s8 rematchAvailability[2];
};

#define MATCH_CALL_COUNT 26
extern const struct MatchCallTrainerTextInfo gMatchCallTrainers[MATCH_CALL_COUNT];

void MatchCall_StartMassOutbreak(struct massOutbreakPhoneCallData *massOutbreak);
void MatchCall_EndMassOutbreak(void);
void MatchCall_TryEndMassOutbreak(u16 days);

#endif //GUARD_MATCH_CALL_H
