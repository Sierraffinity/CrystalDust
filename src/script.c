#include "global.h"
#include "script.h"
#include "event_data.h"
#include "field_camera.h"
#include "field_effect_helpers.h"
#include "fieldmap.h"
#include "field_player_avatar.h"
#include "item.h"
#include "mevent.h"
#include "party_menu.h"
#include "pokemon_storage_system.h"
#include "script_pokemon_util.h"
#include "string_util.h"
#include "tv.h"
#include "util.h"
#include "constants/event_objects.h"
#include "constants/items.h"
#include "constants/layouts.h"
#include "constants/map_scripts.h"
#include "constants/moves.h"
#include "constants/room_decor.h"

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
static u8 sMsgBoxWalkawayDisabled;

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
    EnableMsgBoxWalkaway();
    
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
    gSprites[gObjectEvents[GetObjectEventIdByLocalIdAndMap(9, mapNum, mapGroup)].spriteId].oam.paletteNum = 10; //Jolteon palette
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
    for(i = 0; i < 8; i++)
    {
        if(FlagGet(FLAG_BADGE09_GET + i))
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
    gSpecialVar_0x800B = FALSE;
    if(hasSuicune)
    {
        gSpecialVar_0x800B = TRUE;
    }
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

void SetLandmarkFlagIfEnteredFromNorth(void)
{
    if(gSaveBlock1Ptr->pos.y <= 2)
    {
        FlagSet(FLAG_LANDMARK_ROUTE_10_POKEMON_CENTER);
    }
}

void CheckHasFossils(void)
{
    u8 multichoiceCase = 0;

    bool8 haveHelixFossil = gSpecialVar_0x8008;
    bool8 haveDomeFossil = gSpecialVar_0x8009;
    bool8 haveOldAmber = gSpecialVar_0x800A;
    bool8 haveRootFossil = gSpecialVar_0x800B;
    bool8 haveClawFossil = gSpecialVar_Result;

    if(haveClawFossil)
        multichoiceCase |= 1 << 4;
    if(haveRootFossil)
        multichoiceCase |= 1 << 3;
    if(haveOldAmber)
        multichoiceCase |= 1 << 2;
    if(haveDomeFossil)
        multichoiceCase |= 1 << 1;
    if(haveHelixFossil)
        multichoiceCase |= 1 << 0;

    gSpecialVar_Result = multichoiceCase;
}

void CheckShouldForceBike(void)
{
    if(gMapHeader.mapLayoutId == LAYOUT_ROUTE18)
    {
        if(gSaveBlock1Ptr->pos.x <= 41 && gSaveBlock1Ptr->pos.y <= 11)
        {
            FlagSet(FLAG_SYS_CYCLING_ROAD);
            if (gPlayerAvatar.flags & PLAYER_AVATAR_FLAG_ON_FOOT)
            {
                if (gPlayerAvatar.flags & PLAYER_AVATAR_FLAG_ON_FOOT)
                    SetPlayerAvatarTransitionFlags(PLAYER_AVATAR_FLAG_BIKE);
                return;
            }
        }
    }
    if(gMapHeader.mapLayoutId == LAYOUT_ROUTE16)
    {
        if(gSaveBlock1Ptr->pos.x <= 20 && gSaveBlock1Ptr->pos.y >= 10)
        {
            FlagSet(FLAG_SYS_CYCLING_ROAD);
            if (gPlayerAvatar.flags & PLAYER_AVATAR_FLAG_ON_FOOT)
            {
                if (gPlayerAvatar.flags & PLAYER_AVATAR_FLAG_ON_FOOT)
                    SetPlayerAvatarTransitionFlags(PLAYER_AVATAR_FLAG_BIKE);
                return;
            }
        }
    }
}

void SetMtMoonRocksClearedGoneThroughLowerFloors(void)
{
    if(gSaveBlock1Ptr->pos.x == 26 && gSaveBlock1Ptr->pos.y == 20)
    {
        FlagSet(FLAG_MT_MOON_ROCKS_CLEARED);
    }
}

void HideWarpArrowSprite(void)
{
    struct ObjectEvent *playerObjEvent = &gObjectEvents[gPlayerAvatar.objectEventId];
    SetSpriteInvisible(playerObjEvent->warpArrowSpriteId);
}

static void SetUpRoomDecorBed(void)
{
    if(VarGet(VAR_ROOM_BED) <= BED_PIKACHU && VarGet(VAR_ROOM_BED) != BED_NONE)
    {
        // Feathery Bed values
        u32 topLeft = 0x068;
        u32 topMid = 0x069;
        u32 topRight = 0x06A;
        u32 botLeft = 0x070;
        u32 botMid = 0x071;
        u32 botRight = 0x072;
        // top of bed frame; the same for all beds
        MapGridSetMetatileIdAt(TILE_BED_START_X    , TILE_BED_START_Y    , 0x012);
        MapGridSetMetatileIdAt(TILE_BED_START_X + 1, TILE_BED_START_Y    , 0x013);
        MapGridSetMetatileIdAt(TILE_BED_START_X + 2, TILE_BED_START_Y    , 0x014);
        switch(VarGet(VAR_ROOM_BED))
        {
            case BED_PINK:
                topLeft += 3;
                topMid += 3;
                topRight += 3;
                botLeft += 3;
                botMid += 3;
                botRight += 3;
                break;
            case BED_POLKADOT:
                topLeft += 16;
                topMid += 16;
                topRight += 16;
                botLeft += 16;
                botMid += 16;
                botRight += 16;
                break;
            case BED_PIKACHU:
                topLeft += 19;
                topMid += 19;
                topRight += 19;
                botLeft += 19;
                botMid += 19;
                botRight += 19;
                break;
        }
        MapGridSetMetatileIdAt(TILE_BED_START_X    , TILE_BED_START_Y + 1, topLeft);
        MapGridSetMetatileIdAt(TILE_BED_START_X + 1, TILE_BED_START_Y + 1, topMid);
        MapGridSetMetatileIdAt(TILE_BED_START_X + 2, TILE_BED_START_Y + 1, topRight);
        MapGridSetMetatileIdAt(TILE_BED_START_X    , TILE_BED_START_Y + 2, botLeft);
        MapGridSetMetatileIdAt(TILE_BED_START_X + 1, TILE_BED_START_Y + 2, botMid | METATILE_COLLISION_MASK);
        MapGridSetMetatileIdAt(TILE_BED_START_X + 2, TILE_BED_START_Y + 2, botRight);
    }
}

static void SetUpRoomDecorPlant(void)
{
    if(VarGet(VAR_ROOM_PLANT) <= PLANT_GORGEOUS && VarGet(VAR_ROOM_PLANT) != PLANT_NONE)
    {   // left only for 2x2 plants, set to Colorful
        // Magna Plant Values
        u32 topLeft = 0x08A;
        u32 botLeft = 0x092;
        u32 topRight = 0x05E;
        u32 botRight = 0x066;
        switch(VarGet(VAR_ROOM_PLANT))
        {
            case PLANT_MAGNA:
                topLeft = 0x001;
                botLeft = 0x001;
                break;
            case PLANT_TROPIC:
                topLeft = 0x001;
                botLeft = 0x001;
                topRight += 16;
                botRight += 16;
                break;
            case PLANT_JUMBO:
                topLeft = 0x001;
                botLeft = 0x001;
                topRight += 32;
                botRight += 32;
                break;
            case PLANT_RED:
                topLeft = 0x001;
                botLeft = 0x001;
                topRight += 17;
                botRight += 17;
                break;
            case PLANT_TROPICAL:
                topLeft = 0x001;
                botLeft = 0x001;
                topRight += 1;
                botRight += 1;
                break;
            case PLANT_PRETTY:
                topLeft = 0x001;
                botLeft = 0x001;
                topRight += 33;
                botRight += 33;
                break;
            case PLANT_COLORFUL:
                topRight += 45;
                botRight += 45;
                break;
            case PLANT_BIG:
                topLeft += 2;
                botLeft += 2;
                topRight += 47;
                botRight += 47;
                break;
            case PLANT_GORGEOUS:
                topLeft += 4;
                botLeft += 4;
                topRight += 49;
                botRight += 49;
                break;
        }
        MapGridSetMetatileIdAt(TILE_PLANT_START_X - 1, TILE_PLANT_START_Y    , topLeft);
        MapGridSetMetatileIdAt(TILE_PLANT_START_X    , TILE_PLANT_START_Y    , topRight);
        if(VarGet(VAR_ROOM_PLANT) < PLANT_COLORFUL)
            MapGridSetMetatileIdAt(TILE_PLANT_START_X - 1, TILE_PLANT_START_Y + 1, botLeft);
        else
            MapGridSetMetatileIdAt(TILE_PLANT_START_X - 1, TILE_PLANT_START_Y + 1, botLeft | METATILE_COLLISION_MASK);
        MapGridSetMetatileIdAt(TILE_PLANT_START_X    , TILE_PLANT_START_Y + 1, botRight | METATILE_COLLISION_MASK);
    }
}

static void SetUpRoomDecorPoster(void)
{
    if(VarGet(VAR_ROOM_POSTER) <= POSTER_KISS && VarGet(VAR_ROOM_POSTER) != POSTER_NONE)
    {
        MapGridSetMetatileIdAt(TILE_POSTER_START_X    , TILE_POSTER_START_Y    , 0x02A + ((VarGet(VAR_ROOM_POSTER) - 1) * 2) | METATILE_COLLISION_MASK);
        MapGridSetMetatileIdAt(TILE_POSTER_START_X + 1, TILE_POSTER_START_Y    , 0x02B + ((VarGet(VAR_ROOM_POSTER) - 1) * 2) | METATILE_COLLISION_MASK);
        if(VarGet(VAR_ROOM_POSTER) < POSTER_SKY)
        {
            MapGridSetMetatileIdAt(TILE_POSTER_START_X    , TILE_POSTER_START_Y + 1, 0x046 + ((VarGet(VAR_ROOM_POSTER) - 1) * 2) | METATILE_COLLISION_MASK);
            MapGridSetMetatileIdAt(TILE_POSTER_START_X + 1, TILE_POSTER_START_Y + 1, 0x047 + ((VarGet(VAR_ROOM_POSTER) - 1) * 2) | METATILE_COLLISION_MASK);
        }
        else
        {
            MapGridSetMetatileIdAt(TILE_POSTER_START_X    , TILE_POSTER_START_Y + 1, 0x060 + ((VarGet(VAR_ROOM_POSTER) - 13) * 2) | METATILE_COLLISION_MASK);
            MapGridSetMetatileIdAt(TILE_POSTER_START_X + 1, TILE_POSTER_START_Y + 1, 0x061 + ((VarGet(VAR_ROOM_POSTER) - 13) * 2) | METATILE_COLLISION_MASK);
        }
    }
}

static void SetUpRoomDecorConsole(void)
{
    if(VarGet(VAR_ROOM_CONSOLE) <= CONSOLE_GAMECUBE && VarGet(VAR_ROOM_CONSOLE) != CONSOLE_NONE)
    {
        MapGridSetMetatileIdAt(TILE_CONSOLE_START_X, TILE_CONSOLE_START_Y    , 0x019 + (VarGet(VAR_ROOM_CONSOLE) - 1) | METATILE_COLLISION_MASK);
        MapGridSetMetatileIdAt(TILE_CONSOLE_START_X, TILE_CONSOLE_START_Y + 1, 0x021 + (VarGet(VAR_ROOM_CONSOLE) - 1));
    }
}

static void SetUpRoomDecorCarpet(void)
{
    if(VarGet(VAR_ROOM_CARPET) <= CARPET_SPIKES && VarGet(VAR_ROOM_CARPET) != CARPET_NONE)
    {
        u32 shift = 0;
        switch(VarGet(VAR_ROOM_CARPET))
        {
            case CARPET_YELLOW:
            case CARPET_GREEN:
                shift = 1;
                break;
            case CARPET_SURF:
            case CARPET_THUNDER:
                shift = 2;
                break;
            case CARPET_FIRE_BLAST:
            case CARPET_POWDER_SNOW:
                shift = 3;
                break;
            case CARPET_ATTRACT:
            case CARPET_FISSURE:
                shift = 4;
                break;
            case CARPET_SPIKES:
                shift = 5;
                break;
        }
        MapGridSetMetatileIdAt(TILE_CARPET_START_X    , TILE_CARPET_START_Y    , 0x218 + ((VarGet(VAR_ROOM_CARPET) - 1) * 4) + (shift * 24));
        MapGridSetMetatileIdAt(TILE_CARPET_START_X + 1, TILE_CARPET_START_Y    , 0x219 + ((VarGet(VAR_ROOM_CARPET) - 1) * 4) + (shift * 24));
        MapGridSetMetatileIdAt(TILE_CARPET_START_X + 2, TILE_CARPET_START_Y    , 0x21A + ((VarGet(VAR_ROOM_CARPET) - 1) * 4) + (shift * 24));
        MapGridSetMetatileIdAt(TILE_CARPET_START_X + 3, TILE_CARPET_START_Y    , 0x21B + ((VarGet(VAR_ROOM_CARPET) - 1) * 4) + (shift * 24));

        MapGridSetMetatileIdAt(TILE_CARPET_START_X    , TILE_CARPET_START_Y + 1, 0x220 + ((VarGet(VAR_ROOM_CARPET) - 1) * 4) + (shift * 24));
        MapGridSetMetatileIdAt(TILE_CARPET_START_X + 1, TILE_CARPET_START_Y + 1, 0x221 + ((VarGet(VAR_ROOM_CARPET) - 1) * 4) + (shift * 24));
        MapGridSetMetatileIdAt(TILE_CARPET_START_X + 2, TILE_CARPET_START_Y + 1, 0x222 + ((VarGet(VAR_ROOM_CARPET) - 1) * 4) + (shift * 24));
        MapGridSetMetatileIdAt(TILE_CARPET_START_X + 3, TILE_CARPET_START_Y + 1, 0x223 + ((VarGet(VAR_ROOM_CARPET) - 1) * 4) + (shift * 24));

        MapGridSetMetatileIdAt(TILE_CARPET_START_X    , TILE_CARPET_START_Y + 2, 0x228 + ((VarGet(VAR_ROOM_CARPET) - 1) * 4) + (shift * 24));
        MapGridSetMetatileIdAt(TILE_CARPET_START_X + 1, TILE_CARPET_START_Y + 2, 0x229 + ((VarGet(VAR_ROOM_CARPET) - 1) * 4) + (shift * 24));
        MapGridSetMetatileIdAt(TILE_CARPET_START_X + 2, TILE_CARPET_START_Y + 2, 0x22A + ((VarGet(VAR_ROOM_CARPET) - 1) * 4) + (shift * 24));
        MapGridSetMetatileIdAt(TILE_CARPET_START_X + 3, TILE_CARPET_START_Y + 2, 0x22B + ((VarGet(VAR_ROOM_CARPET) - 1) * 4) + (shift * 24));

        MapGridSetMetatileIdAt(TILE_CARPET_START_X    , TILE_CARPET_START_Y + 3, 0x230 + ((VarGet(VAR_ROOM_CARPET) - 1) * 4) + (shift * 24));
        MapGridSetMetatileIdAt(TILE_CARPET_START_X + 1, TILE_CARPET_START_Y + 3, 0x231 + ((VarGet(VAR_ROOM_CARPET) - 1) * 4) + (shift * 24));
        MapGridSetMetatileIdAt(TILE_CARPET_START_X + 2, TILE_CARPET_START_Y + 3, 0x232 + ((VarGet(VAR_ROOM_CARPET) - 1) * 4) + (shift * 24));
        MapGridSetMetatileIdAt(TILE_CARPET_START_X + 3, TILE_CARPET_START_Y + 3, 0x233 + ((VarGet(VAR_ROOM_CARPET) - 1) * 4) + (shift * 24));
    }
}

static void SetUpRoomDecorDesk(void)
{
    if(VarGet(VAR_ROOM_TABLE) <= DESK_HARD && VarGet(VAR_ROOM_TABLE) != DESK_NONE)
    {
        u32 shift = 0;
        if(VarGet(VAR_ROOM_TABLE) > DESK_COMFORT)
        {
            shift = 1;
        }
        MapGridSetMetatileIdAt(TILE_DESK_START_X    , TILE_DESK_START_Y    , 0x098 + ((VarGet(VAR_ROOM_TABLE) - 1) * 2) + ((VarGet(VAR_ROOM_CARPET)) * 32) + (shift * 8) | METATILE_COLLISION_MASK);
        MapGridSetMetatileIdAt(TILE_DESK_START_X + 1, TILE_DESK_START_Y    , 0x099 + ((VarGet(VAR_ROOM_TABLE) - 1) * 2) + ((VarGet(VAR_ROOM_CARPET)) * 32) + (shift * 8) | METATILE_COLLISION_MASK);
        MapGridSetMetatileIdAt(TILE_DESK_START_X    , TILE_DESK_START_Y + 1, 0x0A0 + ((VarGet(VAR_ROOM_TABLE) - 1) * 2) + ((VarGet(VAR_ROOM_CARPET)) * 32) + (shift * 8) | METATILE_COLLISION_MASK);
        MapGridSetMetatileIdAt(TILE_DESK_START_X + 1, TILE_DESK_START_Y + 1, 0x0A1 + ((VarGet(VAR_ROOM_TABLE) - 1) * 2) + ((VarGet(VAR_ROOM_CARPET)) * 32) + (shift * 8) | METATILE_COLLISION_MASK);
    }
}

static void SetUpRoomDecorCushion(void)
{
    FlagSet(FLAG_TEMP_4);
    if(VarGet(VAR_ROOM_BED) <= BED_PIKACHU && VarGet(VAR_ROOM_BED) != BED_NONE) // no cushion if no bed
    {
        if(VarGet(VAR_ROOM_CUSHION) <= CUSHION_WATER && VarGet(VAR_ROOM_CUSHION) != CUSHION_NONE)
        {
            FlagClear(FLAG_TEMP_4);
            switch(VarGet(VAR_ROOM_CUSHION))
            {
                case CUSHION_PIKA:
                    VarSet(VAR_OBJ_GFX_ID_2, OBJ_EVENT_GFX_ZPIKA_CUSHION);
                    break;
                case CUSHION_ROUND:
                    VarSet(VAR_OBJ_GFX_ID_2, OBJ_EVENT_GFX_ZROUND_CUSHION);
                    break;
                case CUSHION_KISS:
                    VarSet(VAR_OBJ_GFX_ID_2, OBJ_EVENT_GFX_ZKISS_CUSHION);
                    break;
                case CUSHION_ZIGZAG:
                    VarSet(VAR_OBJ_GFX_ID_2, OBJ_EVENT_GFX_ZIGZAG_CUSHION);
                    break;
                case CUSHION_SPIN:
                    VarSet(VAR_OBJ_GFX_ID_2, OBJ_EVENT_GFX_ZSPIN_CUSHION);
                    break;
                case CUSHION_DIAMOND:
                    VarSet(VAR_OBJ_GFX_ID_2, OBJ_EVENT_GFX_ZDIAMOND_CUSHION);
                    break;
                case CUSHION_BALL:
                    VarSet(VAR_OBJ_GFX_ID_2, OBJ_EVENT_GFX_ZBALL_CUSHION);
                    break;
                case CUSHION_GRASS:
                    VarSet(VAR_OBJ_GFX_ID_2, OBJ_EVENT_GFX_ZGRASS_CUSHION);
                    break;
                case CUSHION_FIRE:
                    VarSet(VAR_OBJ_GFX_ID_2, OBJ_EVENT_GFX_ZFIRE_CUSHION);
                    break;
                case CUSHION_WATER:
                    VarSet(VAR_OBJ_GFX_ID_2, OBJ_EVENT_GFX_ZWATER_CUSHION);
                    break;
            }
        }
    }
}

static void SetUpRoomDecorBigDoll(void)
{
    FlagSet(FLAG_TEMP_3);
    if(VarGet(VAR_ROOM_BIG_DOLL) <= BIG_DOLL_REGISTEEL && VarGet(VAR_ROOM_BIG_DOLL) != BIG_DOLL_NONE)
    {
        FlagClear(FLAG_TEMP_3);
        switch(VarGet(VAR_ROOM_BIG_DOLL))
        {
            case BIG_DOLL_SNORLAX:
                VarSet(VAR_OBJ_GFX_ID_3, OBJ_EVENT_GFX_BIG_SNORLAX_DOLL);
                break;
            case BIG_DOLL_ONIX:
                VarSet(VAR_OBJ_GFX_ID_3, OBJ_EVENT_GFX_ZBIG_ONIX_DOLL);
                break;
            case BIG_DOLL_LAPRAS:
                VarSet(VAR_OBJ_GFX_ID_3, OBJ_EVENT_GFX_BIG_LAPRAS_DOLL);
                break;
            case BIG_DOLL_RHYDON:
                VarSet(VAR_OBJ_GFX_ID_3, OBJ_EVENT_GFX_ZBIG_RHYDON_DOLL);
                break;
            case BIG_DOLL_VENUSAUR:
                VarSet(VAR_OBJ_GFX_ID_3, OBJ_EVENT_GFX_ZBIG_VENUSAUR_DOLL);
                break;
            case BIG_DOLL_CHARIZARD:
                VarSet(VAR_OBJ_GFX_ID_3, OBJ_EVENT_GFX_ZBIG_CHARIZARD_DOLL);
                break;
            case BIG_DOLL_BLASTOISE:
                VarSet(VAR_OBJ_GFX_ID_3, OBJ_EVENT_GFX_ZBIG_BLASTOISE_DOLL);
                break;
            case BIG_DOLL_WAILMER:
                VarSet(VAR_OBJ_GFX_ID_3, OBJ_EVENT_GFX_ZBIG_WAILMER_DOLL);
                break;
            case BIG_DOLL_REGIROCK:
                VarSet(VAR_OBJ_GFX_ID_3, OBJ_EVENT_GFX_ZBIG_REGIROCK_DOLL);
                break;
            case BIG_DOLL_REGICE:
                VarSet(VAR_OBJ_GFX_ID_3, OBJ_EVENT_GFX_ZBIG_REGICE_DOLL);
                break;
            case BIG_DOLL_REGISTEEL:
                VarSet(VAR_OBJ_GFX_ID_3, OBJ_EVENT_GFX_ZBIG_REGISTEEL_DOLL);
                break;
        }
    }
}

static u16 MapOrnamentConstantsToObjectEventGfx(u16 ornament)
{
    switch(ornament)
    {
        case DOLL_PIKACHU:
            return OBJ_EVENT_GFX_PIKACHU_DOLL;
        case DOLL_SURF_PIKACHU:
            return OBJ_EVENT_GFX_ZSURFING_PIKACHU_DOLL;
        case DOLL_CLEFAIRY:
            return OBJ_EVENT_GFX_CLEFAIRY_DOLL;
        case DOLL_JIGGLYPUFF:
            return OBJ_EVENT_GFX_JIGGLYPUFF_DOLL;
        case DOLL_BULBASAUR:
            return OBJ_EVENT_GFX_ZBULBASAUR_DOLL;
        case DOLL_ODDISH:
            return OBJ_EVENT_GFX_ZODDISH_DOLL;
        case DOLL_GENGAR:
            return OBJ_EVENT_GFX_ZGENGAR_DOLL;
        case DOLL_SHELLDER:
            return OBJ_EVENT_GFX_ZSHELLDER_DOLL;
        case DOLL_GRIMER:
            return OBJ_EVENT_GFX_ZGRIMER_DOLL;
        case DOLL_VOLTORB:
            return OBJ_EVENT_GFX_ZVOLTORB_DOLL;
        case DOLL_WEEDLE:
            return OBJ_EVENT_GFX_ZWEEDLE_DOLL;
        case DOLL_MAGIKARP:
            return OBJ_EVENT_GFX_ZMAGIKARP_DOLL;
        case DOLL_CHARMANDER:
            return OBJ_EVENT_GFX_ZCHARMANDER_DOLL;
        case DOLL_SQUIRTLE:
            return OBJ_EVENT_GFX_ZSQUIRTLE_DOLL;
        case DOLL_POLIWAG:
            return OBJ_EVENT_GFX_ZPOLIWAG_DOLL;
        case DOLL_DIGLETT:
            return OBJ_EVENT_GFX_ZDIGLETT_DOLL;
        case DOLL_STARYU:
            return OBJ_EVENT_GFX_ZSTARYU_DOLL;
        case DOLL_TENTACOOL:
            return OBJ_EVENT_GFX_ZTENTACOOL_DOLL;
        case DOLL_UNOWN:
            return OBJ_EVENT_GFX_ZUNOWN_DOLL;
        case DOLL_GEODUDE:
            return OBJ_EVENT_GFX_ZGEODUDE_DOLL;
        case DOLL_MACHOP:
            return OBJ_EVENT_GFX_ZMACHOP_DOLL;
        case DOLL_SILVER_TROPHY:
            return OBJ_EVENT_GFX_ZSILVER_TROPHY;
        case DOLL_GOLD_TROPHY:
            return OBJ_EVENT_GFX_ZGOLD_TROPHY;
        case DOLL_MAGNEMITE:
            return OBJ_EVENT_GFX_ZMAGNEMITE_DOLL;
        case DOLL_NATU:
            return OBJ_EVENT_GFX_ZNATU_DOLL;
        case DOLL_PORYGON2:
            return OBJ_EVENT_GFX_ZPORYGON2_DOLL;
        case DOLL_WOOPER:
            return OBJ_EVENT_GFX_ZWOOPER_DOLL;
        case DOLL_PICHU:
            return OBJ_EVENT_GFX_ZPICHU_DOLL;
        case DOLL_MARILL:
            return OBJ_EVENT_GFX_ZMARILL_DOLL;
        case DOLL_TOGEPI:
            return OBJ_EVENT_GFX_ZTOGEPI_DOLL;
        case DOLL_CYNDAQUIL:
            return OBJ_EVENT_GFX_ZCYNDAQUIL_DOLL;
        case DOLL_CHIKORITA:
            return OBJ_EVENT_GFX_ZCHIKORITA_DOLL;
        case DOLL_TOTODILE:
            return OBJ_EVENT_GFX_ZTOTODILE_DOLL;
        case DOLL_MEOWTH:
            return OBJ_EVENT_GFX_ZMEOWTH_DOLL;
        case DOLL_DITTO:
            return OBJ_EVENT_GFX_ZDITTO_DOLL;
        case DOLL_SMOOCHUM:
            return OBJ_EVENT_GFX_ZSMOOCHUM_DOLL;
        case DOLL_TREECKO:
            return OBJ_EVENT_GFX_ZTREECKO_DOLL;
        case DOLL_TORCHIC:
            return OBJ_EVENT_GFX_ZTORCHIC_DOLL;
        case DOLL_MUDKIP:
            return OBJ_EVENT_GFX_ZMUDKIP_DOLL;
        case DOLL_DUSKULL:
            return OBJ_EVENT_GFX_ZDUSKULL_DOLL;
        case DOLL_WYNAUT:
            return OBJ_EVENT_GFX_ZWYNAUT_DOLL;
        case DOLL_BALTOY:
            return OBJ_EVENT_GFX_ZBALTOY_DOLL;
        case DOLL_KECLEON:
            return OBJ_EVENT_GFX_ZKECLEON_DOLL;
        case DOLL_AZURILL:
            return OBJ_EVENT_GFX_ZAZURILL_DOLL;
        case DOLL_SKITTY:
            return OBJ_EVENT_GFX_ZSKITTY_DOLL;
        case DOLL_SWABLU:
            return OBJ_EVENT_GFX_ZSWABLU_DOLL;
        case DOLL_GULPIN:
            return OBJ_EVENT_GFX_ZGULPIN_DOLL;
        case DOLL_LOTAD:
            return OBJ_EVENT_GFX_ZLOTAD_DOLL;
        case DOLL_SEEDOT:
            return OBJ_EVENT_GFX_ZSEEDOT_DOLL;
        case DOLL_SILVER_SHIELD:
            return OBJ_EVENT_GFX_ZSILVER_SHIELD;
        case DOLL_GOLD_SHIELD:
            return OBJ_EVENT_GFX_ZGOLD_SHIELD;
        default:
            return OBJ_EVENT_GFX_ZUNOWN_DOLL;
    }
}

extern const u16 gObjectEventPal_ShieldDecorations;

// The Silver and Gold Shields were tiles in RSE Secret Bases, but object events here.
// No existing event object palette matches and the "free" slot 10 is taken up by decor that uses Red's palette.
// So, if the shields are present, their palette has to be force-loaded into their paletteNum slot (11).
void PatchShieldPaletteToSlot11(void)
{
    LoadPaletteDayNight(&gObjectEventPal_ShieldDecorations, 16 * 11 + 0x100, 0x20);
}

static void SetUpRoomDecorOrnaments(void)
{
    FlagSet(FLAG_TEMP_1);
    FlagSet(FLAG_TEMP_2);
    if(VarGet(VAR_ROOM_TABLE) <= DESK_HARD && VarGet(VAR_ROOM_TABLE) != DESK_NONE) // no ornament if no table
    {
        if(VarGet(VAR_ROOM_LEFT_ORNAMENT) <= DOLL_GOLD_SHIELD && VarGet(VAR_ROOM_LEFT_ORNAMENT) != DOLL_NONE)
        {
            FlagClear(FLAG_TEMP_1);
            VarSet(VAR_OBJ_GFX_ID_0, MapOrnamentConstantsToObjectEventGfx(VarGet(VAR_ROOM_LEFT_ORNAMENT)));
        }
        if(VarGet(VAR_ROOM_RIGHT_ORNAMENT) <= DOLL_GOLD_SHIELD && VarGet(VAR_ROOM_RIGHT_ORNAMENT) != DOLL_NONE)
        {
            FlagClear(FLAG_TEMP_2);
            VarSet(VAR_OBJ_GFX_ID_1, MapOrnamentConstantsToObjectEventGfx(VarGet(VAR_ROOM_RIGHT_ORNAMENT)));
        }
        PatchShieldPaletteToSlot11();
    }
}

void SetUpRoomDecor(void)
{
    SetUpRoomDecorBed();
    SetUpRoomDecorPlant();
    SetUpRoomDecorPoster();
    SetUpRoomDecorConsole();
    SetUpRoomDecorCarpet();
    SetUpRoomDecorDesk();
    SetUpRoomDecorCushion();
    SetUpRoomDecorBigDoll();
    SetUpRoomDecorOrnaments();
    DrawWholeMapView();
}

void DisableMsgBoxWalkaway(void)
{
    sMsgBoxWalkawayDisabled = TRUE;
}

void EnableMsgBoxWalkaway(void)
{
    sMsgBoxWalkawayDisabled = FALSE;
}

bool8 IsMsgBoxWalkawayDisabled(void)
{
    return sMsgBoxWalkawayDisabled;
}

void TeachTrappedTentacoolSurf(void)
{
    u32 i;
    u32 move = MOVE_SURF;
    u32 pp = 15;
    if(gSpecialVar_0x8007 == 0) //party
    {
        i = CalculatePlayerPartyCount() - 1;
        SetMonData(&gPlayerParty[i], MON_DATA_MOVE4, &move);
        SetMonData(&gPlayerParty[i], MON_DATA_PP1 + 3, &pp);
        return;
    }
    else //box
    {
        SetBoxMonDataAt(gSpecialVar_MonBoxId, gSpecialVar_MonBoxPos, MON_DATA_MOVE4, &move);
        SetBoxMonDataAt(gSpecialVar_MonBoxId, gSpecialVar_MonBoxPos, MON_DATA_PP1 + 3, &pp);
        return;
    }
}

// ChatGPT optimized
void CheckPlayerTrappedOnCianwoodOrCinnabar(void)
{
    bool32 hasHM03 = CheckBagHasItem(ITEM_HM03, 1);
    u32 i, j;

    for (i = 0; i < PARTY_SIZE; i++) {
        if (GetMonData(&gPlayerParty[i], MON_DATA_SPECIES, NULL) == SPECIES_NONE) {
            break;
        } else {
            struct Pokemon* partyMon = &gPlayerParty[i];
            if (!GetMonData(partyMon, MON_DATA_IS_EGG) && MonKnowsMove(partyMon, MOVE_SURF)) {
                gSpecialVar_Result = 0;
                return;
            }
            if (hasHM03 && CanMonLearnTMHM(partyMon, ITEM_HM03 - ITEM_TM01_FOCUS_PUNCH)) {
                gSpecialVar_Result = 0;
                return;
            }
        }
    }

    for (i = 0; i < TOTAL_BOXES_COUNT; i++) {
        for (j = 0; j < IN_BOX_COUNT; j++) {
            if (GetBoxMonDataAt(i, j, MON_DATA_SPECIES) == SPECIES_NONE) {
                continue;
            } else {
                struct Pokemon tempMon;
                BoxMonToMon(GetBoxedMonPtr(i, j), &tempMon);
                if (!GetMonData(&tempMon, MON_DATA_IS_EGG) && MonKnowsMove(&tempMon, MOVE_SURF)) {
                    gSpecialVar_Result = 0;
                    return;
                }
                if (hasHM03 && CanMonLearnTMHM(&tempMon, ITEM_HM03 - ITEM_TM01_FOCUS_PUNCH)) {
                    gSpecialVar_Result = 0;
                    return;
                }
            }
        }
    }

    if(hasHM03)
        gSpecialVar_Result = 1;
    else
        gSpecialVar_Result = 2; // need to teach Tentacool Surf
}

// ChatGPT optimized
void CheckPlayerTrappedAtIndigoPlateau(void)
{
    bool32 hasHM03 = CheckBagHasItem(ITEM_HM03, 1);
    bool32 hasHM02 = CheckBagHasItem(ITEM_HM02, 1);
    bool32 hasKantoFlyPoint = FlagGet(FLAG_VISITED_VERMILION_CITY);
    u32 i, j;

    for (i = 0; i < PARTY_SIZE; i++) {
        if (GetMonData(&gPlayerParty[i], MON_DATA_SPECIES, NULL) == SPECIES_NONE) {
            break;
        } else {
            struct Pokemon* partyMon = &gPlayerParty[i];
            if (!GetMonData(partyMon, MON_DATA_IS_EGG) && 
                (MonKnowsMove(partyMon, MOVE_SURF) || 
                 (MonKnowsMove(partyMon, MOVE_FLY) && hasKantoFlyPoint))) {
                gSpecialVar_Result = 0;
                return;
            }
            if ((hasHM03 && CanMonLearnTMHM(partyMon, ITEM_HM03 - ITEM_TM01_FOCUS_PUNCH)) ||
                (hasHM02 && CanMonLearnTMHM(partyMon, ITEM_HM02 - ITEM_TM01_FOCUS_PUNCH) && hasKantoFlyPoint)) {
                gSpecialVar_Result = 0;
                return;
            }
        }
    }

    for (i = 0; i < TOTAL_BOXES_COUNT; i++) {
        for (j = 0; j < IN_BOX_COUNT; j++) {
            if (GetBoxMonDataAt(i, j, MON_DATA_SPECIES) == SPECIES_NONE) {
                continue;
            } else {
                struct Pokemon tempMon;
                BoxMonToMon(GetBoxedMonPtr(i, j), &tempMon);
                if (!GetMonData(&tempMon, MON_DATA_IS_EGG) &&
                    (MonKnowsMove(&tempMon, MOVE_SURF) || 
                     (MonKnowsMove(&tempMon, MOVE_FLY) && hasKantoFlyPoint))) {
                    gSpecialVar_Result = 0;
                    return;
                }
                if ((hasHM03 && CanMonLearnTMHM(&tempMon, ITEM_HM03 - ITEM_TM01_FOCUS_PUNCH)) ||
                    (hasHM02 && CanMonLearnTMHM(&tempMon, ITEM_HM02 - ITEM_TM01_FOCUS_PUNCH) && hasKantoFlyPoint)) {
                    gSpecialVar_Result = 0;
                    return;
                }
            }
        }
    }

    gSpecialVar_Result = 1; // trapped
}
