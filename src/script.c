#include "global.h"
#include "script.h"
#include "event_data.h"
#include "mevent.h"
#include "pokemon_storage_system.h"
#include "string_util.h"
#include "tv.h"
#include "util.h"
#include "constants/map_scripts.h"
#include "constants/moves.h"

#define RAM_SCRIPT_MAGIC 51

enum {
    SCRIPT_MODE_STOPPED,
    SCRIPT_MODE_BYTECODE,
    SCRIPT_MODE_NATIVE,
};

extern const u8* gRamScriptRetAddr;

EWRAM_DATA u8 gExitFromScriptEarlyWaitTimer = 0;

// ewram bss
static u8 sScriptContext1Status;
static struct ScriptContext sScriptContext1;
static struct ScriptContext sScriptContext2;
static bool8 sScriptContext2Enabled;
static u8 sCanExitScriptEarly;
static u8 sDoesTextboxUseSignBorder;

extern ScrCmdFunc gScriptCmdTable[];
extern ScrCmdFunc gScriptCmdTableEnd[];
extern void *gNullScriptPtr;

void InitScriptContext(struct ScriptContext *ctx, void *cmdTable, void *cmdTableEnd)
{
    s32 i;

    ctx->mode = SCRIPT_MODE_STOPPED;
    ctx->scriptPtr = NULL;
    ctx->stackDepth = 0;
    ctx->nativePtr = NULL;
    ctx->cmdTable = cmdTable;
    ctx->cmdTableEnd = cmdTableEnd;

    for (i = 0; i < (int)ARRAY_COUNT(ctx->data); i++)
        ctx->data[i] = 0;

    for (i = 0; i < (int)ARRAY_COUNT(ctx->stack); i++)
        ctx->stack[i] = NULL;
}

u8 SetupBytecodeScript(struct ScriptContext *ctx, const u8 *ptr)
{
    ctx->scriptPtr = ptr;
    ctx->mode = SCRIPT_MODE_BYTECODE;
    return 1;
}

void SetupNativeScript(struct ScriptContext *ctx, bool8 (*ptr)(void))
{
    ctx->mode = SCRIPT_MODE_NATIVE;
    ctx->nativePtr = ptr;
}

void StopScript(struct ScriptContext *ctx)
{
    ctx->mode = SCRIPT_MODE_STOPPED;
    ctx->scriptPtr = NULL;
}

bool8 RunScriptCommand(struct ScriptContext *ctx)
{
    if (ctx->mode == SCRIPT_MODE_STOPPED)
        return FALSE;

    switch (ctx->mode)
    {
    case SCRIPT_MODE_STOPPED:
        return FALSE;
    case SCRIPT_MODE_NATIVE:
        // Try to call a function in C
        // Continue to bytecode if no function or it returns TRUE
        if (ctx->nativePtr)
        {
            if (ctx->nativePtr() == TRUE)
                ctx->mode = SCRIPT_MODE_BYTECODE;
            return TRUE;
        }
        ctx->mode = SCRIPT_MODE_BYTECODE;
        // fallthrough
    case SCRIPT_MODE_BYTECODE:
        while (1)
        {
            u8 cmdCode;
            ScrCmdFunc *func;

            if (!ctx->scriptPtr)
            {
                ctx->mode = SCRIPT_MODE_STOPPED;
                return FALSE;
            }

            if (ctx->scriptPtr == gNullScriptPtr)
            {
                while (1)
                    asm("svc 2"); // HALT
            }

            cmdCode = *(ctx->scriptPtr);
            ctx->scriptPtr++;
            func = &ctx->cmdTable[cmdCode];

            if (func >= ctx->cmdTableEnd)
            {
                ctx->mode = SCRIPT_MODE_STOPPED;
                return FALSE;
            }

            if ((*func)(ctx) == TRUE)
                return TRUE;
        }
    }

    return TRUE;
}

static bool8 ScriptPush(struct ScriptContext *ctx, const u8 *ptr)
{
    if (ctx->stackDepth + 1 >= (int)ARRAY_COUNT(ctx->stack))
    {
        return TRUE;
    }
    else
    {
        ctx->stack[ctx->stackDepth] = ptr;
        ctx->stackDepth++;
        return FALSE;
    }
}

static const u8 *ScriptPop(struct ScriptContext *ctx)
{
    if (ctx->stackDepth == 0)
        return NULL;

    ctx->stackDepth--;
    return ctx->stack[ctx->stackDepth];
}

void ScriptJump(struct ScriptContext *ctx, const u8 *ptr)
{
    ctx->scriptPtr = ptr;
}

void ScriptCall(struct ScriptContext *ctx, const u8 *ptr)
{
    ScriptPush(ctx, ctx->scriptPtr);
    ctx->scriptPtr = ptr;
}

void ScriptReturn(struct ScriptContext *ctx)
{
    ctx->scriptPtr = ScriptPop(ctx);
}

u16 ScriptReadHalfword(struct ScriptContext *ctx)
{
    u16 value = *(ctx->scriptPtr++);
    value |= *(ctx->scriptPtr++) << 8;
    return value;
}

u32 ScriptReadWord(struct ScriptContext *ctx)
{
    u32 value0 = *(ctx->scriptPtr++);
    u32 value1 = *(ctx->scriptPtr++);
    u32 value2 = *(ctx->scriptPtr++);
    u32 value3 = *(ctx->scriptPtr++);
    return (((((value3 << 8) + value2) << 8) + value1) << 8) + value0;
}

void ScriptContext2_Enable(void)
{
    sScriptContext2Enabled = TRUE;
}

void ScriptContext2_Disable(void)
{
    sScriptContext2Enabled = FALSE;
}

bool8 ScriptContext2_IsEnabled(void)
{
    return sScriptContext2Enabled;
}

void EnableExitingFromScriptEarly(void)
{
    gExitFromScriptEarlyWaitTimer = 6;
    sCanExitScriptEarly = TRUE;
}

void DisableExitingFromScriptEarly(void)
{
    sCanExitScriptEarly = FALSE;
}

bool8 CanExitScriptEarly(void)
{
    if (sCanExitScriptEarly == TRUE)
        return TRUE;
    else
        return FALSE;
}

void TextboxUseSignBorder(void)
{
    sDoesTextboxUseSignBorder = TRUE;
}

void TextboxUseStandardBorder(void)
{
    sDoesTextboxUseSignBorder = FALSE;
}

bool8 DoesTextboxUseSignBorder(void)
{
    if (sDoesTextboxUseSignBorder == TRUE)
        return TRUE;
    else
        return FALSE;
}

bool8 ScriptContext1_IsScriptSetUp(void)
{
    if (sScriptContext1Status == 0)
        return TRUE;
    else
        return FALSE;
}

void ScriptContext1_Init(void)
{
    InitScriptContext(&sScriptContext1, gScriptCmdTable, gScriptCmdTableEnd);
    sScriptContext1Status = 2;
}

bool8 ScriptContext2_RunScript(void)
{
    if (sScriptContext1Status == 2)
        return FALSE;

    if (sScriptContext1Status == 1)
        return FALSE;

    ScriptContext2_Enable();

    if (!RunScriptCommand(&sScriptContext1))
    {
        sScriptContext1Status = 2;
        ScriptContext2_Disable();
        return FALSE;
    }

    return TRUE;
}

void ScriptContext1_SetupScript(const u8 *ptr)
{
    DisableExitingFromScriptEarly();
    InitScriptContext(&sScriptContext1, gScriptCmdTable, gScriptCmdTableEnd);
    SetupBytecodeScript(&sScriptContext1, ptr);
    ScriptContext2_Enable();
    sScriptContext1Status = 0;
}

void ScriptContext1_Stop(void)
{
    sScriptContext1Status = 1;
}

void EnableBothScriptContexts(void)
{
    sScriptContext1Status = 0;
    ScriptContext2_Enable();
}

void ScriptContext2_RunNewScript(const u8 *ptr)
{
    InitScriptContext(&sScriptContext2, gScriptCmdTable, gScriptCmdTableEnd);
    SetupBytecodeScript(&sScriptContext2, ptr);
    while (RunScriptCommand(&sScriptContext2) == TRUE);
}

u8 *MapHeaderGetScriptTable(u8 tag)
{
    const u8 *mapScripts = gMapHeader.mapScripts;

    if (!mapScripts)
        return NULL;

    while (1)
    {
        if (!*mapScripts)
            return NULL;
        if (*mapScripts == tag)
        {
            mapScripts++;
            return T2_READ_PTR(mapScripts);
        }
        mapScripts += 5;
    }
}

void MapHeaderRunScriptType(u8 tag)
{
    u8 *ptr = MapHeaderGetScriptTable(tag);
    if (ptr)
        ScriptContext2_RunNewScript(ptr);
}

u8 *MapHeaderCheckScriptTable(u8 tag)
{
    u8 *ptr = MapHeaderGetScriptTable(tag);

    if (!ptr)
        return NULL;

    while (1)
    {
        u16 varIndex1;
        u16 varIndex2;

        // Read first var (or .2byte terminal value)
        varIndex1 = T1_READ_16(ptr);
        if (!varIndex1)
            return NULL; // Reached end of table
        ptr += 2;

        // Read second var
        varIndex2 = T1_READ_16(ptr);
        ptr += 2;

        // Run map script if vars are equal
        if (VarGet(varIndex1) == VarGet(varIndex2))
            return T2_READ_PTR(ptr);
        ptr += 4;
    }
}

void RunOnLoadMapScript(void)
{
    MapHeaderRunScriptType(MAP_SCRIPT_ON_LOAD);
}

void RunOnTransitionMapScript(void)
{
    MapHeaderRunScriptType(MAP_SCRIPT_ON_TRANSITION);
}

void RunOnResumeMapScript(void)
{
    MapHeaderRunScriptType(MAP_SCRIPT_ON_RESUME);
}

void RunOnReturnToFieldMapScript(void)
{
    MapHeaderRunScriptType(MAP_SCRIPT_ON_RETURN_TO_FIELD);
}

void RunOnDiveWarpMapScript(void)
{
    MapHeaderRunScriptType(MAP_SCRIPT_ON_DIVE_WARP);
}

bool8 TryRunOnFrameMapScript(void)
{
    u8 *ptr = MapHeaderCheckScriptTable(MAP_SCRIPT_ON_FRAME_TABLE);

    if (!ptr)
        return FALSE;

    ScriptContext1_SetupScript(ptr);
    return TRUE;
}

void TryRunOnWarpIntoMapScript(void)
{
    u8 *ptr = MapHeaderCheckScriptTable(MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE);
    if (ptr)
        ScriptContext2_RunNewScript(ptr);
}

u32 CalculateRamScriptChecksum(void)
{
    return CalcCRC16WithTable((u8*)(&gSaveBlock1Ptr->ramScript.data), sizeof(gSaveBlock1Ptr->ramScript.data));
}

void ClearRamScript(void)
{
    CpuFill32(0, &gSaveBlock1Ptr->ramScript, sizeof(struct RamScript));
}

bool8 InitRamScript(const u8 *script, u16 scriptSize, u8 mapGroup, u8 mapNum, u8 objectId)
{
    struct RamScriptData *scriptData = &gSaveBlock1Ptr->ramScript.data;

    ClearRamScript();

    if (scriptSize > sizeof(scriptData->script))
        return FALSE;

    scriptData->magic = RAM_SCRIPT_MAGIC;
    scriptData->mapGroup = mapGroup;
    scriptData->mapNum = mapNum;
    scriptData->objectId = objectId;
    memcpy(scriptData->script, script, scriptSize);
    gSaveBlock1Ptr->ramScript.checksum = CalculateRamScriptChecksum();
    return TRUE;
}

const u8 *GetRamScript(u8 objectId, const u8 *script)
{
    struct RamScriptData *scriptData = &gSaveBlock1Ptr->ramScript.data;
    gRamScriptRetAddr = NULL;
    if (scriptData->magic != RAM_SCRIPT_MAGIC)
        return script;
    if (scriptData->mapGroup != gSaveBlock1Ptr->location.mapGroup)
        return script;
    if (scriptData->mapNum != gSaveBlock1Ptr->location.mapNum)
        return script;
    if (scriptData->objectId != objectId)
        return script;
    if (CalculateRamScriptChecksum() != gSaveBlock1Ptr->ramScript.checksum)
    {
        ClearRamScript();
        return script;
    }
    else
    {
        gRamScriptRetAddr = script;
        return scriptData->script;
    }
}

bool32 ValidateSavedRamScript(void)
{
    struct RamScriptData *scriptData = &gSaveBlock1Ptr->ramScript.data;
    if (scriptData->magic != RAM_SCRIPT_MAGIC)
        return FALSE;
    if (scriptData->mapGroup != 0xFF)
        return FALSE;
    if (scriptData->mapNum != 0xFF)
        return FALSE;
    if (scriptData->objectId != 0xFF)
        return FALSE;
    if (CalculateRamScriptChecksum() != gSaveBlock1Ptr->ramScript.checksum)
        return FALSE;
    return TRUE;
}

u8 *GetSavedRamScriptIfValid(void)
{
    struct RamScriptData *scriptData = &gSaveBlock1Ptr->ramScript.data;
    if (!ValidateReceivedWonderCard())
        return NULL;
    if (scriptData->magic != RAM_SCRIPT_MAGIC)
        return NULL;
    if (scriptData->mapGroup != 0xFF)
        return NULL;
    if (scriptData->mapNum != 0xFF)
        return NULL;
    if (scriptData->objectId != 0xFF)
        return NULL;
    if (CalculateRamScriptChecksum() != gSaveBlock1Ptr->ramScript.checksum)
    {
        ClearRamScript();
        return NULL;
    }
    else
    {
        return scriptData->script;
    }
}

void InitRamScript_NoObjectEvent(u8 *script, u16 scriptSize)
{
    if (scriptSize > sizeof(gSaveBlock1Ptr->ramScript.data.script))
        scriptSize = sizeof(gSaveBlock1Ptr->ramScript.data.script);
    InitRamScript(script, scriptSize, 0xFF, 0xFF, 0xFF);
}

void GetObjectEventTrainerRangeFromTemplate(void)
{
    gSpecialVar_Result = gMapHeader.events->objectEvents[gSpecialVar_LastTalked - 1].trainerRange_berryTreeId;
}

extern void LoadPaletteDayNight(const void *src, u16 offset, u16 size);
extern const u16 gObjectEventPal_Eusine;
extern u8 GetObjectEventIdByLocalIdAndMap(u8 localId, u8 mapNum, u8 mapGroupId);

void PatchEusinePaletteToSlot11(void)
{
    if(!FlagGet(FLAG_AWAKENED_LEGENDARY_BEASTS))
    {
        gSprites[gObjectEvents[GetObjectEventIdByLocalIdAndMap(1, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup)].spriteId].oam.paletteNum = 11;
        LoadPaletteDayNight(&gObjectEventPal_Eusine, 16 * 11 + 0x100, 0x20);
    }
}

void OverrideKimonoGirlsPaletteSlots(void)
{
    u8 mapNum = gSaveBlock1Ptr->location.mapNum;
    u8 mapGroup = gSaveBlock1Ptr->location.mapGroup;

    gSprites[gObjectEvents[GetObjectEventIdByLocalIdAndMap(6, mapNum, mapGroup)].spriteId].oam.paletteNum = 2; //Espeon palette
    gSprites[gObjectEvents[GetObjectEventIdByLocalIdAndMap(7, mapNum, mapGroup)].spriteId].oam.paletteNum = 4; //Umbreon palette
    gSprites[gObjectEvents[GetObjectEventIdByLocalIdAndMap(8, mapNum, mapGroup)].spriteId].oam.paletteNum = 11; //Vaporeon palette
    gSprites[gObjectEvents[GetObjectEventIdByLocalIdAndMap(9, mapNum, mapGroup)].spriteId].oam.paletteNum = 10; //Joleon palette
}

extern const u16 gObjectEventPal_EspeonKimonoGirl[];
extern const u16 gObjectEventPal_UmbreonKimonoGirl[];
extern const u16 gObjectEventPal_VaporeonKimonoGirl[];
extern const u16 gObjectEventPal_JolteonKimonoGirl[];

void PatchKimonoGirlPalettesToSlots(void)
{
    LoadPaletteDayNight(&gObjectEventPal_EspeonKimonoGirl, 16 * 2 + 0x100, 0x20);
    LoadPaletteDayNight(&gObjectEventPal_UmbreonKimonoGirl, 16 * 4 + 0x100, 0x20);
    LoadPaletteDayNight(&gObjectEventPal_VaporeonKimonoGirl, 16 * 11 + 0x100, 0x20);
    LoadPaletteDayNight(&gObjectEventPal_JolteonKimonoGirl, 16 * 10 + 0x100, 0x20);
}

extern const u16 gObjectEventPal_EnteiAsleep[];
extern const u16 gObjectEventPal_RaikouAsleep[];
extern const u16 gObjectEventPal_SuicuneAsleep[];

void PatchAsleepBeastsPalettesToSlots(void)
{
    LoadPaletteDayNight(&gObjectEventPal_EnteiAsleep, 16 * 2 + 0x100, 0x20);
    LoadPaletteDayNight(&gObjectEventPal_RaikouAsleep, 16 * 4 + 0x100, 0x20);
    LoadPaletteDayNight(&gObjectEventPal_SuicuneAsleep, 16 * 3 + 0x100, 0x20);
}

extern const u16 gObjectEventPal_Npc1[];
extern const u16 gObjectEventPal_Npc2[];
extern const u16 gObjectEventPal_Npc3[];

void AwakenEntei(void)
{
    LoadPaletteDayNight(&gObjectEventPal_Npc1, 16 * 2 + 0x100, 0x20);
}

void AwakenRaikou(void)
{
    LoadPaletteDayNight(&gObjectEventPal_Npc3, 16 * 4 + 0x100, 0x20);
}

void AwakenSuicune(void)
{
    LoadPaletteDayNight(&gObjectEventPal_Npc2, 16 * 3 + 0x100, 0x20);
}

void IsHoOhInFirstInParty(void)
{
    if(GetMonData(&gPlayerParty[0], MON_DATA_SPECIES2) == SPECIES_HO_OH)
        gSpecialVar_Result = TRUE;
    else
        gSpecialVar_Result = FALSE;
}

void CountBadges(void)
{
    u32 i;
    u32 numBadges = 0;
    for(i = 0; i < 8; i++)
    {
        if(FlagGet(FLAG_BADGE01_GET + i))
            numBadges++;
    }
    gSpecialVar_Result = numBadges;
}

void GiveEnemyMonSelfdestruct(void)
{
    u16 move = MOVE_SELF_DESTRUCT;
    SetMonData(&gEnemyParty[0], MON_DATA_MOVE1, &move);
}

extern const u16 gObjectEventPal_Murkrow;

void PatchMurkrowPaletteToSlot10(void)
{
    LoadPaletteDayNight(&gObjectEventPal_Murkrow, 16 * 10 + 0x100, 0x20);
}

static bool32 MonHasPlayersOT(struct Pokemon mon)
{
    if (GetMonData(&mon, MON_DATA_LANGUAGE) != GAME_LANGUAGE)
        return FALSE;

    GetMonData(&mon, MON_DATA_OT_NAME, gStringVar1);

    if (StringCompare(gSaveBlock2Ptr->playerName, gStringVar1))
        return FALSE;

    if (GetPlayerIDAsU32() != GetMonData(&mon, MON_DATA_OT_ID, NULL))
        return FALSE;

    return TRUE;
}

void CheckOwnAllBeasts(void)
{
    u32 i, j, k;
    u16 species = SPECIES_BLISSEY; //incremented in k loop to Raikou to start
    bool32 hasRaikou = FALSE;
    bool32 hasEntei = FALSE;
    bool32 hasSuicune = FALSE;
    bool32 hasMon = FALSE;
    struct Pokemon tempMon;

    for(k = 0; k < 3; k++)
    {
        if(k == 1)
            hasRaikou = hasMon;
        if(k == 2)
            hasEntei = hasMon;
        species++;
        hasMon = FALSE;

        // check party for species
        for(i = 0; i < PARTY_SIZE && !hasMon; i++)
        {

            if(species == GetMonData(&gPlayerParty[i], MON_DATA_SPECIES, 0))
            {
                hasMon = MonHasPlayersOT(gPlayerParty[i]);
            }
        }
        // check boxes for species
        for(i = 0; i < TOTAL_BOXES_COUNT && !hasMon; i++)
        {
            for(j = 0; j < IN_BOX_COUNT && !hasMon; j++)
            {
                if(GetBoxMonDataAt(i, j, MON_DATA_SPECIES) == species)
                {
                    BoxMonToMon(GetBoxedMonPtr(i, j), &tempMon);
                    hasMon = MonHasPlayersOT(tempMon);
                }
            }
        }
    }
    hasSuicune = hasMon;
    if(hasRaikou && hasEntei && hasSuicune)
    {
        gSpecialVar_Result = TRUE;
        return;
    }
    else
    {
        gSpecialVar_Result = FALSE;
        return;
    }  
}