
// Includes
#include "global.h"
#include "battle_setup.h"
#include "event_data.h"
#include "pokegear_phone.h"
#include "string_util.h"
#include "battle.h"
#include "gym_leader_rematch.h"

extern void sub_8197080(u8 *dest);
extern const u8 gTrainerClassNames[][13];

// Static type declarations

typedef struct MatchCallTextDataStruct {
    const u8 *text;
    u16 flag;
    u16 flag2;
} match_call_text_data_t;

struct MatchCallStructCommon {
    u8 type;
    u8 v1;
    u16 flag;
};

struct MatchCallStruct0 {
    u8 type;
    u8 v1;
    u16 flag;
    const u8 *desc;
    const u8 *name;
    const match_call_text_data_t *textData;
};

struct MatchCallStruct1 {
    u8 type;
    u8 v1;
    u16 flag;
    u16 rematchTableIdx;
    const u8 *desc;
    const u8 *name;
    const match_call_text_data_t *textData;
};

struct MatchCallSubstruct2 {
    u16 flag;
    u8 v2;
};

struct MatchCallStruct2 {
    u8 type;
    u8 v1;
    u16 flag;
    u16 rematchTableIdx;
    const u8 *desc;
    const match_call_text_data_t *textData;
    const struct MatchCallSubstruct2 *v10;
};

struct MatchCallStruct3 {
    u8 type;
    u8 v1;
    u16 flag;
    const u8 *desc;
    const u8 *name;
};

struct MatchCallStruct4 {
    u8 type;
    u8 gender;
    u16 flag;
    const u8 *desc;
    const u8 *name;
    const match_call_text_data_t *textData;
};

struct MatchCallStruct5 {
    u8 type;
    u8 v1;
    u16 flag;
    u16 v4;
    const u8 *desc;
    const u8 *name;
    const match_call_text_data_t *textData;
};

#define MATCHCALLDEF(name, type_, ...) \
static const struct MatchCallStruct##type_ name = { \
    .type = type_, \
    __VA_ARGS__ \
};

typedef union {
    const struct MatchCallStructCommon *common;
    const struct MatchCallStruct0 *type0;
    const struct MatchCallStruct1 *type1;
    const struct MatchCallStruct2 *type2;
    const struct MatchCallStruct3 *type3;
    const struct MatchCallStruct4 *type4;
    const struct MatchCallStruct5 *type5;
} match_call_t;

struct UnkStruct_08625388 {
    u16 idx;
    u16 v2;
    u16 v4;
    const u8 *v8[4];
};

static void sub_81D1920(const match_call_text_data_t *, u8 *);
static void sub_81D199C(const match_call_text_data_t *, u16, u8 *);
static void MatchCall_GetNameAndDescByRematchIdx(u32, const u8 **, const u8 **);

static u32 MatchCallGetFunctionIndex(match_call_t matchCall)
{
    switch (matchCall.common->type)
    {
        case 0:
        default:
            return 0;
        case 1:
        case 5:
            return 1;
        case 2:
            return 2;
        case 4:
            return 3;
        case 3:
            return 4;
    }
}

u32 GetTrainerIdxByRematchIdx(u32 rematchIdx)
{
    return gRematchTable[rematchIdx].trainerIds[0];
}

s32 GetRematchIdxByTrainerIdx(s32 trainerIdx)
{
    s32 rematchIdx;

    for (rematchIdx = 0; rematchIdx < REMATCH_TABLE_ENTRIES; rematchIdx++)
    {
        if (gRematchTable[rematchIdx].trainerIds[0] == trainerIdx)
            return rematchIdx;
    }
    return -1;
}

bool32 MatchCallFlagGetByIndex(u32 idx)
{
    return FALSE;
}

u8 sub_81D16DC(u32 idx)
{
    return FALSE;
}

bool32 MatchCall_IsRematchable(u32 idx)
{
    return FALSE;
}

bool32 sub_81D17E8(u32 idx)
{
    return FALSE;
}

u32 MatchCall_GetRematchTableIdx(u32 idx)
{
    return REMATCH_TABLE_ENTRIES;
}

void MatchCall_GetMessage(u32 idx, u8 *dest)
{
    return;
}

void sub_81D1920(const match_call_text_data_t *sub0, u8 *dest)
{
    u32 i;
    for (i = 0; sub0[i].text != NULL; i++)
        ;
    if (i)
        i--;
    while (i)
    {
        if (sub0[i].flag != 0xffff && FlagGet(sub0[i].flag) == TRUE)
            break;
        i--;
    }
    if (sub0[i].flag2 != 0xffff)
        FlagSet(sub0[i].flag2);
    StringExpandPlaceholders(dest, sub0[i].text);
}

#ifdef NONMATCHING
// There's some weird upmerge going on that I cannot replicate at this time.
static void sub_81D199C(const match_call_text_data_t *sub0, u16 idx, u8 *dest)
{
    u32 i;
    for (i = 0; sub0[i].text != NULL; i++)
    {
        if (sub0[i].flag == 0xfffe)
            break;
        if (sub0[i].flag == 0xffff && !FlagGet(sub0[i].flag))
            break;
    }
    if (sub0[i].flag != 0xfffe)
    {
        if (i)
            i--;
        if (sub0[i].flag2 != 0xffff)
            FlagSet(sub0[i].flag2);
        StringExpandPlaceholders(dest, sub0[i].text);
    }
    else
    {
        if (!FlagGet(FLAG_SYS_GAME_CLEAR))
            ;
        else if (gSaveBlock1Ptr->trainerRematches[idx])
            i += 2;
        else if (CountBattledRematchTeams(idx) >= 2)
            i += 3;
        else
            i++;
        StringExpandPlaceholders(dest, sub0[i].text);
    }
}
#else
static NAKED void sub_81D199C(const match_call_text_data_t *sub0, u16 idx, u8 *dest)
{
    asm_unified("\tpush {r4-r7,lr}\n"
                    "\tmov r7, r10\n"
                    "\tmov r6, r9\n"
                    "\tmov r5, r8\n"
                    "\tpush {r5-r7}\n"
                    "\tadds r6, r0, 0\n"
                    "\tmov r10, r2\n"
                    "\tlsls r1, 16\n"
                    "\tlsrs r7, r1, 16\n"
                    "\tmovs r5, 0\n"
                    "\tldr r0, [r6]\n"
                    "\tcmp r0, 0\n"
                    "\tbeq _081D19E6\n"
                    "\tldrh r0, [r6, 0x4]\n"
                    "\tldr r1, =0x0000fffe\n"
                    "\tcmp r0, r1\n"
                    "\tbeq _081D1A24\n"
                    "\tldr r0, =0x0000ffff\n"
                    "\tmov r9, r0\n"
                    "\tmov r8, r1\n"
                    "\tadds r4, r6, 0\n"
                    "_081D19C6:\n"
                    "\tldrh r0, [r4, 0x4]\n"
                    "\tcmp r0, r9\n"
                    "\tbeq _081D19D6\n"
                    "\tbl FlagGet\n"
                    "\tlsls r0, 24\n"
                    "\tcmp r0, 0\n"
                    "\tbeq _081D19E6\n"
                    "_081D19D6:\n"
                    "\tadds r4, 0x8\n"
                    "\tadds r5, 0x1\n"
                    "\tldr r0, [r4]\n"
                    "\tcmp r0, 0\n"
                    "\tbeq _081D19E6\n"
                    "\tldrh r0, [r4, 0x4]\n"
                    "\tcmp r0, r8\n"
                    "\tbne _081D19C6\n"
                    "_081D19E6:\n"
                    "\tlsls r0, r5, 3\n"
                    "\tadds r0, r6\n"
                    "\tldrh r1, [r0, 0x4]\n"
                    "\tldr r0, =0x0000fffe\n"
                    "\tcmp r1, r0\n"
                    "\tbeq _081D1A24\n"
                    "\tcmp r5, 0\n"
                    "\tbeq _081D19F8\n"
                    "\tsubs r5, 0x1\n"
                    "_081D19F8:\n"
                    "\tlsls r0, r5, 3\n"
                    "\tadds r4, r0, r6\n"
                    "\tldrh r1, [r4, 0x6]\n"
                    "\tldr r0, =0x0000ffff\n"
                    "\tcmp r1, r0\n"
                    "\tbeq _081D1A0A\n"
                    "\tadds r0, r1, 0\n"
                    "\tbl FlagSet\n"
                    "_081D1A0A:\n"
                    "\tldr r1, [r4]\n"
                    "\tmov r0, r10\n"
                    "\tbl StringExpandPlaceholders\n"
                    "\tb _081D1A5C\n"
                    "\t.pool\n"
                    "_081D1A1C:\n"
                    "\tadds r5, 0x2\n"
                    "\tb _081D1A50\n"
                    "_081D1A20:\n"
                    "\tadds r5, 0x3\n"
                    "\tb _081D1A50\n"
                    "_081D1A24:\n"
                    "\tldr r0, =0x00000864\n"
                    "\tbl FlagGet\n"
                    "\tlsls r0, 24\n"
                    "\tcmp r0, 0\n"
                    "\tbeq _081D1A50\n"
                    "\tldr r0, =gSaveBlock1Ptr\n"
                    "\tldr r0, [r0]\n"
                    "\tldr r1, =0x000009ca\n"
                    "\tadds r0, r1\n"
                    "\tadds r0, r7\n"
                    "\tldrb r0, [r0]\n"
                    "\tcmp r0, 0\n"
                    "\tbne _081D1A1C\n"
                    "\tadds r0, r7, 0\n"
                    "\tbl CountBattledRematchTeams\n"
                    "\tlsls r0, 16\n"
                    "\tlsrs r0, 16\n"
                    "\tcmp r0, 0x1\n"
                    "\tbhi _081D1A20\n"
                    "\tadds r5, 0x1\n"
                    "_081D1A50:\n"
                    "\tlsls r0, r5, 3\n"
                    "\tadds r0, r6\n"
                    "\tldr r1, [r0]\n"
                    "\tmov r0, r10\n"
                    "\tbl StringExpandPlaceholders\n"
                    "_081D1A5C:\n"
                    "\tpop {r3-r5}\n"
                    "\tmov r8, r3\n"
                    "\tmov r9, r4\n"
                    "\tmov r10, r5\n"
                    "\tpop {r4-r7}\n"
                    "\tpop {r0}\n"
                    "\tbx r0\n"
                    "\t.pool");
}
#endif

void sub_81D1A78(u32 idx, const u8 **desc, const u8 **name)
{
    return;
}

static void MatchCall_GetNameAndDescByRematchIdx(u32 idx, const u8 **desc, const u8 **name)
{
    const struct Trainer *trainer = gTrainers + GetTrainerIdxByRematchIdx(idx);
    *desc = gTrainerClassNames[trainer->trainerClass];
    *name = trainer->trainerName;
}

const u8 *sub_81D1B40(u32 idx, u32 offset)
{
    return NULL;
}

s32 sub_81D1BD0(u32 idx)
{
    return -1;
}

bool32 sub_81D1BF8(u32 idx)
{
    s32 i;

    for (i = 0; i < 21; i++)
    {
        u32 r0 = MatchCall_GetRematchTableIdx(i);
        if (r0 != REMATCH_TABLE_ENTRIES && r0 == idx)
            return TRUE;
    }
    return FALSE;
}

void SetMatchCallRegisteredFlag(void)
{
    s32 r0 = GetRematchIdxByTrainerIdx(gSpecialVar_0x8004);
    if (r0 >= 0)
        FlagSet(gPhoneContacts[gRematchTable[r0].phoneContactId].registeredFlag);
}
