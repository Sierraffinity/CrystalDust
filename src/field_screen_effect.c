#include "global.h"
#include "cable_club.h"
#include "event_data.h"
#include "fieldmap.h"
#include "field_camera.h"
#include "field_door.h"
#include "field_effect.h"
#include "event_object_lock.h"
#include "event_object_movement.h"
#include "field_player_avatar.h"
#include "field_screen_effect.h"
#include "field_special_scene.h"
#include "field_weather.h"
#include "gpu_regs.h"
#include "io_reg.h"
#include "link.h"
#include "link_rfu.h"
#include "load_save.h"
#include "main.h"
#include "menu.h"
#include "mirage_tower.h"
#include "metatile_behavior.h"
#include "palette.h"
#include "overworld.h"
#include "scanline_effect.h"
#include "script.h"
#include "sound.h"
#include "start_menu.h"
#include "task.h"
#include "text.h"
#include "constants/event_object_movement.h"
#include "constants/event_objects.h"
#include "constants/songs.h"
#include "constants/rgb.h"
#include "trainer_hill.h"
#include "fldeff.h"

// This file's functions.
static void Task_ExitNonAnimDoor(u8);
static void Task_ExitNonDoor(u8);
static void Task_StaircaseWarpIn(u8);
static void Task_DoContestHallWarp(u8);
static void FillPalBufferWhite(void);
static void Task_ExitDoor(u8);
static bool32 WaitForWeatherFadeIn(void);
static void Task_TeleportTileWarpExit(u8 taskId);
static void Task_StaircaseWarpOut(u8 taskId);
static void Task_SpinEnterWarp(u8 taskId);
static void Task_WarpAndLoadMap(u8 taskId);
static void Task_DoDoorWarp(u8 taskId);
static void Task_EnableScriptAfterMusicFade(u8 taskId);
static void AnimatePlayerWalkOutOnStaircase(s16 a0, s16 a1, s16 *a2, s16 *a3, s16 *a4);
static void BeginAnimatingPlayerWalkOutOnStaircase(s16 behavior, s16 *a1, s16 *a2);
static void SetStaircaseTargetPosValues(u8 behavior, s16 *a1, s16 *a2);
static bool8 AnimatePlayerWalkInOnStaircase(s16 *a0, s16 *a1, s16 *a2, s16 *a3, s16 *a4);
static void BeginAnimatingPlayerWalkInOnStaircase(s16 *a0, s16 *a1, s16 *a2, s16 *a3, s16 *a4);
static void Task_BarnDoorWipe(u8 taskId);
static void DoInwardBarnDoorWipe(void);
static void DoOutwardBarnDoorWipe(void);
static void Task_BarnDoorWipeChild(u8 taskId);
static void StartWarpFadeIn(bool8 a0);

// data[0] is used universally by tasks in this file as a state for switches
#define tState       data[0]

// const
static const u16 sFlashLevelPixelRadii[] = { 200, 72, 56, 40, 24 };
const s32 gMaxFlashLevel = ARRAY_COUNT(sFlashLevelPixelRadii) - 1;

const struct ScanlineEffectParams sFlashEffectParams =
{
    (void *)REG_ADDR_WIN0H,
    ((DMA_ENABLE | DMA_START_HBLANK | DMA_REPEAT | DMA_DEST_RELOAD) << 16) | 1,
    1
};

// code
static void FillPalBufferWhite(void)
{
    CpuFastFill16(RGB_WHITE, gPlttBufferFaded, PLTT_SIZE);
}

static void FillPalBufferBlack(void)
{
    CpuFastFill16(RGB_BLACK, gPlttBufferFaded, PLTT_SIZE);
}

void WarpFadeInScreen(void)
{
    u8 previousMapType = GetLastUsedWarpMapType();
    switch (GetMapPairFadeFromType(previousMapType, GetCurrentMapType()))
    {
    case 0:
        FillPalBufferBlack();
        FadeScreen(FADE_FROM_BLACK, 0);
        FillPalBufferBlack();
        break;
    case 1:
        FillPalBufferWhite();
        FadeScreen(FADE_FROM_WHITE, 0);
        FillPalBufferWhite();
    }
}

void FadeInFromWhite(void)
{
    u8 previousMapType = GetLastUsedWarpMapType();
    switch (GetMapPairFadeFromType(previousMapType, GetCurrentMapType()))
    {
    case 0:
        FillPalBufferBlack();
        FadeScreen(FADE_FROM_BLACK, 3);
        FillPalBufferBlack();
        break;
    case 1:
        FillPalBufferWhite();
        FadeScreen(FADE_FROM_WHITE, 3);
        FillPalBufferWhite();
    }
}

void FadeInFromBlack(void)
{
    FillPalBufferBlack();
    FadeScreen(FADE_FROM_BLACK, 0);
    FillPalBufferBlack();
}

void WarpFadeOutScreen(void)
{
    u8 currentMapType = GetCurrentMapType();
    switch (GetMapPairFadeToType(currentMapType, GetDestinationWarpMapHeader()->mapType))
    {
    case 0:
        FadeScreen(FADE_TO_BLACK, 0);
        break;
    case 1:
        FadeScreen(FADE_TO_WHITE, 0);
    }
}

static void SetPlayerVisibility(bool8 visible)
{
    SetPlayerInvisibility(!visible);
}

static void Task_WaitForUnionRoomFade(u8 taskId)
{
    if (WaitForWeatherFadeIn() == TRUE)
        DestroyTask(taskId);
}

void FieldCB_ContinueScriptUnionRoom(void)
{
    ScriptContext2_Enable();
    Overworld_PlaySpecialMapMusic();
    FadeInFromBlack();
    CreateTask(Task_WaitForUnionRoomFade, 10);
}

static void Task_WaitForFadeAndEnableScriptCtx(u8 taskID)
{
    if (WaitForWeatherFadeIn() == TRUE)
    {
        DestroyTask(taskID);
        EnableBothScriptContexts();
    }
}

void FieldCB_ContinueScriptHandleMusic(void)
{
    ScriptContext2_Enable();
    Overworld_PlaySpecialMapMusic();
    FadeInFromBlack();
    CreateTask(Task_WaitForFadeAndEnableScriptCtx, 10);
}

void FieldCB_ContinueScript(void)
{
    ScriptContext2_Enable();
    FadeInFromBlack();
    CreateTask(Task_WaitForFadeAndEnableScriptCtx, 10);
}

static void Task_ReturnToFieldCableLink(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    switch (task->tState)
    {
    case 0:
        task->data[1] = CreateTask_ReestablishCableClubLink();
        task->tState++;
        break;
    case 1:
        if (gTasks[task->data[1]].isActive != TRUE)
        {
            WarpFadeInScreen();
            task->tState++;
        }
        break;
    case 2:
        if (WaitForWeatherFadeIn() == TRUE)
        {
            ScriptContext2_Disable();
            DestroyTask(taskId);
        }
        break;
    }
}

void FieldCB_ReturnToFieldCableLink(void)
{
    ScriptContext2_Enable();
    Overworld_PlaySpecialMapMusic();
    FillPalBufferBlack();
    CreateTask(Task_ReturnToFieldCableLink, 10);
}

static void Task_ReturnToFieldWirelessLink(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    switch (task->tState)
    {
    case 0:
        SetLinkStandbyCallback();
        task->tState++;
        break;
    case 1:
        if (!IsLinkTaskFinished())
        {
            if (++task->data[1] > 1800)
                GetLinkmanErrorParams(0x6000);
        }
        else
        {
            WarpFadeInScreen();
            task->tState++;
        }
        break;
    case 2:
        if (WaitForWeatherFadeIn() == TRUE)
        {
            StartSendingKeysToLink();
            ScriptContext2_Disable();
            DestroyTask(taskId);
        }
        break;
    }
}

void Task_ReturnToFieldRecordMixing(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    switch (task->tState)
    {
    case 0:
        SetLinkStandbyCallback();
        task->tState++;
        break;
    case 1:
        if (IsLinkTaskFinished())
        {
            task->tState++;
        }
        break;
    case 2:
        StartSendingKeysToLink();
        ResetAllMultiplayerState();
        ScriptContext2_Disable();
        DestroyTask(taskId);
        break;
    }
}

void FieldCB_ReturnToFieldWirelessLink(void)
{
    ScriptContext2_Enable();
    Overworld_PlaySpecialMapMusic();
    FillPalBufferBlack();
    CreateTask(Task_ReturnToFieldWirelessLink, 10);
}

static void SetUpWarpExitTask(bool8 forceBlack)
{
    s16 x, y;
    u8 behavior;
    TaskFunc func;

    PlayerGetDestCoords(&x, &y);
    behavior = MapGridGetMetatileBehaviorAt(x, y);

    if (MetatileBehavior_IsDoor(behavior) == TRUE)
    {
        func = Task_ExitDoor;
    }
    else
    {
        StartWarpFadeIn(forceBlack);
        if (MetatileBehavior_IsNonAnimDoor(behavior) == TRUE)
            func = Task_ExitNonAnimDoor;
        else if (!gIsStaircaseWarpAnimDisabled &&
                 MetatileBehavior_IsStaircase(behavior) == TRUE)
            func = Task_StaircaseWarpIn;
        else
            func = Task_ExitNonDoor;
    }
    gIsStaircaseWarpAnimDisabled = FALSE;
    CreateTask(func, 10);
}

static void StartWarpFadeIn(bool8 forceBlack)
{
    if (forceBlack)
        FadeInFromBlack();
    else
        WarpFadeInScreen();
}

void FieldCB_DefaultWarpExit(void)
{
    Overworld_PlaySpecialMapMusic();
    WarpFadeInScreen();
    SetUpWarpExitTask(FALSE);
    ScriptContext2_Enable();
}

void FieldCB_WarpExitFadeFromWhite(void)
{
    Overworld_PlaySpecialMapMusic();
    FadeInFromWhite();
    SetUpWarpExitTask(FALSE);
    ScriptContext2_Enable();
}

void FieldCB_WarpExitFadeFromBlack(void)
{
    if (!OnTrainerHillEReaderChallengeFloor()) // always false
        Overworld_PlaySpecialMapMusic();
    FadeInFromBlack();
    SetUpWarpExitTask(FALSE);
    ScriptContext2_Enable();
}

static void FieldCB_SpinEnterWarp(void)
{
    Overworld_PlaySpecialMapMusic();
    WarpFadeInScreen();
    PlaySE(SE_WARP_OUT);
    CreateTask(Task_SpinEnterWarp, 10);
    ScriptContext2_Enable();
}

static void FieldCB_MossdeepGymWarpExit(void)
{
    Overworld_PlaySpecialMapMusic();
    WarpFadeInScreen();
    PlaySE(SE_WARP_OUT);
    CreateTask(Task_ExitNonDoor, 10);
    ScriptContext2_Enable();
    SetObjectEventLoadFlag((~SKIP_OBJECT_EVENT_LOAD) & 0xF);
}

static void Task_ExitDoor(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    s16 *x = &task->data[2];
    s16 *y = &task->data[3];

    switch (task->tState)
    {
    case 0:
        SetPlayerVisibility(FALSE);
        FreezeObjectEvents();
        DoOutwardBarnDoorWipe();
        FadeInFromWhite();
        task->tState = 1;
        break;
    case 1:
        if (++task->data[15] == 25)
        {
            PlayerGetDestCoords(x, y);
            PlaySE(GetDoorSoundEffect(*x, *y));
            FieldAnimateDoorOpen(*x, *y);
            task->tState = 2;
        }
        break;
    case 2:
        if (!FieldIsDoorAnimationRunning())
        {
            u8 objEventId;
            PlayerGetDestCoords(x, y);
            SetPlayerVisibility(TRUE);
            objEventId = GetObjectEventIdByLocalIdAndMap(0xFF, 0, 0);
            ObjectEventSetHeldMovement(&gObjectEvents[objEventId], MOVEMENT_ACTION_WALK_NORMAL_DOWN);
            task->tState = 3;
        }
        break;
    case 3:
        if (++task->data[14] == 14)
        {
            FieldAnimateDoorClose(*x, *y);
            task->tState = 4;
        }
        break;
    case 4:
        if (WaitForWeatherFadeIn() && IsPlayerStandingStill() && !FieldIsDoorAnimationRunning() && !FuncIsActiveTask(Task_BarnDoorWipe))
        {
            u8 eventObjId = GetObjectEventIdByLocalIdAndMap(0xFF, 0, 0);
            ObjectEventClearHeldMovementIfFinished(&gObjectEvents[eventObjId]);
            task->data[0] = 5;
        }
        break;
    case 5:
        UnfreezeObjectEvents();
        ScriptContext2_Disable();
        DestroyTask(taskId);
        break;
    }
}

static void Task_ExitNonAnimDoor(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    s16 *x = &task->data[2];
    s16 *y = &task->data[3];

    switch (task->tState)
    {
    case 0:
        SetPlayerVisibility(FALSE);
        FreezeObjectEvents();
        PlayerGetDestCoords(x, y);
        task->tState = 1;
        break;
    case 1:
        if (WaitForWeatherFadeIn())
        {
            u8 objEventId;
            SetPlayerVisibility(TRUE);
            objEventId = GetObjectEventIdByLocalIdAndMap(OBJ_EVENT_ID_PLAYER, 0, 0);
            ObjectEventSetHeldMovement(&gObjectEvents[objEventId], GetWalkNormalMovementAction(GetPlayerFacingDirection()));
            task->tState = 2;
        }
        break;
    case 2:
        if (IsPlayerStandingStill())
        {
            UnfreezeObjectEvents();
            task->tState = 3;
        }
        break;
    case 3:
        ScriptContext2_Disable();
        DestroyTask(taskId);
        break;
    }
}

static void Task_ExitNonDoor(u8 taskId)
{
    switch (gTasks[taskId].tState)
    {
    case 0:
        FreezeObjectEvents();
        ScriptContext2_Enable();
        gTasks[taskId].tState++;
        break;
    case 1:
        if (WaitForWeatherFadeIn())
        {
            UnfreezeObjectEvents();
            ScriptContext2_Disable();
            DestroyTask(taskId);
        }
        break;
    }
}

static void Task_WaitForFadeShowStartMenu(u8 taskId)
{
    if (WaitForWeatherFadeIn() == TRUE)
    {
        DestroyTask(taskId);
        CreateTask(Task_ShowStartMenu, 80);
    }
}

void ReturnToFieldOpenStartMenu(void)
{
    FadeInFromBlack();
    CreateTask(Task_WaitForFadeShowStartMenu, 0x50);
    ScriptContext2_Enable();
}

bool8 FieldCB_ReturnToFieldOpenStartMenu(void)
{
    ShowReturnToFieldStartMenu();
    return FALSE;
}

static void Task_ReturnToFieldNoScript(u8 taskId)
{
    if (WaitForWeatherFadeIn() == 1)
    {
        ScriptContext2_Disable();
        DestroyTask(taskId);
        ScriptUnfreezeObjectEvents();
    }
}

void FieldCB_ReturnToFieldNoScript(void)
{
    ScriptContext2_Enable();
    FadeInFromBlack();
    CreateTask(Task_ReturnToFieldNoScript, 10);
}

void FieldCB_ReturnToFieldNoScriptCheckMusic(void)
{
    ScriptContext2_Enable();
    Overworld_PlaySpecialMapMusic();
    FadeInFromBlack();
    CreateTask(Task_ReturnToFieldNoScript, 10);
}

static bool32 PaletteFadeActive(void)
{
    return gPaletteFade.active;
}

static bool32 WaitForWeatherFadeIn(void)
{
    if (IsWeatherNotFadingIn() == TRUE)
        return TRUE;
    else
        return FALSE;
}

void DoWarp(void)
{
    ScriptContext2_Enable();
    TryFadeOutOldMapMusic();
    WarpFadeOutScreen();
    PlayRainStoppingSoundEffect();
    PlaySE(SE_EXIT);
    gFieldCallback = FieldCB_DefaultWarpExit;
    CreateTask(Task_WarpAndLoadMap, 10);
}

void DoDiveWarp(void)
{
    ScriptContext2_Enable();
    TryFadeOutOldMapMusic();
    WarpFadeOutScreen();
    PlayRainStoppingSoundEffect();
    gFieldCallback = FieldCB_DefaultWarpExit;
    CreateTask(Task_WarpAndLoadMap, 10);
}

void DoStaircaseWarp(u16 behavior, u16 unk)
{
    u8 taskId = CreateTask(Task_StaircaseWarpOut, 10);
    gTasks[taskId].data[1] = behavior;
    gTasks[taskId].data[15] = unk;
    Task_StaircaseWarpOut(taskId);
}

void DoSootopolisLegendWarp(void)
{
    ScriptContext2_Enable();
    TryFadeOutOldMapMusic();
    FadeScreen(FADE_TO_WHITE, 8);
    PlayRainStoppingSoundEffect();
    gFieldCallback = FieldCB_WarpExitFadeFromWhite;
    CreateTask(Task_WarpAndLoadMap, 10);
}

void DoDoorWarp(void)
{
    ScriptContext2_Enable();
    gFieldCallback = FieldCB_DefaultWarpExit;
    CreateTask(Task_DoDoorWarp, 10);
}

void DoFallWarp(void)
{
    DoDiveWarp();
    gFieldCallback = FieldCB_FallWarpExit;
}

void DoEscalatorWarp(u8 metatileBehavior)
{
    ScriptContext2_Enable();
    StartEscalatorWarp(metatileBehavior, 10);
}

void DoLavaridgeGymB1FWarp(void)
{
    ScriptContext2_Enable();
    StartLavaridgeGymB1FWarp(10);
}

void DoLavaridgeGym1FWarp(void)
{
    ScriptContext2_Enable();
    StartLavaridgeGym1FWarp(10);
}

// DoSpinEnterWarp but with a fade out
// Screen fades out to exit current map, player spins down from top to enter new map
// Used by teleporting tiles, e.g. in Aqua Hideout (For the move Teleport see FldEff_TeleportWarpOut)
void DoTeleportTileWarp(void)
{
    ScriptContext2_Enable();
    TryFadeOutOldMapMusic();
    WarpFadeOutScreen();
    PlaySE(SE_WARP_IN);
    CreateTask(Task_WarpAndLoadMap, 10);
    gFieldCallback = FieldCB_SpinEnterWarp;
}

void DoMossdeepGymWarp(void)
{
    SetObjectEventLoadFlag(SKIP_OBJECT_EVENT_LOAD);
    ScriptContext2_Enable();
    SaveObjectEvents();
    TryFadeOutOldMapMusic();
    WarpFadeOutScreen();
    PlaySE(SE_WARP_IN);
    CreateTask(Task_WarpAndLoadMap, 10);
    gFieldCallback = FieldCB_MossdeepGymWarpExit;
}

void DoPortholeWarp(void)
{
    ScriptContext2_Enable();
    WarpFadeOutScreen();
    CreateTask(Task_WarpAndLoadMap, 10);
    gFieldCallback = FieldCB_ShowPortholeView;
}

static void Task_DoCableClubWarp(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    switch (task->tState)
    {
    case 0:
        ScriptContext2_Enable();
        task->tState++;
        break;
    case 1:
        if (!PaletteFadeActive() && BGMusicStopped())
            task->tState++;
        break;
    case 2:
        WarpIntoMap();
        SetMainCallback2(CB2_ReturnToFieldCableClub);
        DestroyTask(taskId);
        break;
    }
}

void DoCableClubWarp(void)
{
    ScriptContext2_Enable();
    TryFadeOutOldMapMusic();
    WarpFadeOutScreen();
    PlaySE(SE_EXIT);
    CreateTask(Task_DoCableClubWarp, 10);
}

static void Task_ReturnToWorldFromLinkRoom(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    switch (tState)
    {
    case 0:
        ClearLinkCallback_2();
        FadeScreen(FADE_TO_BLACK, 0);
        TryFadeOutOldMapMusic();
        PlaySE(SE_EXIT);
        tState++;
        break;
    case 1:
        if (!PaletteFadeActive() && BGMusicStopped())
        {
            SetCloseLinkCallback();
            tState++;
        }
        break;
    case 2:
        if (!gReceivedRemoteLinkPlayers)
        {
            WarpIntoMap();
            SetMainCallback2(CB2_LoadMap);
            DestroyTask(taskId);
        }
        break;
    }
}

void ReturnFromLinkRoom(void)
{
    CreateTask(Task_ReturnToWorldFromLinkRoom, 10);
}

static void Task_WarpAndLoadMap(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    switch (task->tState)
    {
    case 0:
        FreezeObjectEvents();
        ScriptContext2_Enable();
        task->tState++;
        break;
    case 1:
        if (!PaletteFadeActive())
        {
            if (task->data[1] == 0)
            {
                ClearMirageTowerPulseBlendEffect();
                task->data[1] = 1;
            }
            if (BGMusicStopped())
                task->tState++;
        }
        break;
    case 2:
        WarpIntoMap();
        SetMainCallback2(CB2_LoadMap);
        DestroyTask(taskId);
        break;
    }
}

static void Task_DoDoorWarp(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    s16 *x = &task->data[2];
    s16 *y = &task->data[3];

    switch (task->tState)
    {
    case 0:
        FreezeObjectEvents();
        PlayerGetDestCoords(x, y);
        PlaySE(GetDoorSoundEffect(*x, *y - 1));
        task->data[1] = FieldAnimateDoorOpen(*x, *y - 1);
        task->tState = 1;
        break;
    case 1:
        if (task->data[1] < 0 || gTasks[task->data[1]].isActive != TRUE)
        {
            u8 objEventId;
            objEventId = GetObjectEventIdByLocalIdAndMap(OBJ_EVENT_ID_PLAYER, 0, 0);
            ObjectEventClearHeldMovementIfActive(&gObjectEvents[objEventId]);
            objEventId = GetObjectEventIdByLocalIdAndMap(OBJ_EVENT_ID_PLAYER, 0, 0);
            ObjectEventSetHeldMovement(&gObjectEvents[objEventId], MOVEMENT_ACTION_WALK_NORMAL_UP);
            task->tState = 2;
        }
        break;
    case 2:
        if (IsPlayerStandingStill())
        {
            u8 objEventId;
            task->data[1] = FieldAnimateDoorClose(*x, *y - 1);
            objEventId = GetObjectEventIdByLocalIdAndMap(OBJ_EVENT_ID_PLAYER, 0, 0);
            ObjectEventClearHeldMovementIfFinished(&gObjectEvents[objEventId]);
            SetPlayerVisibility(FALSE);
            task->tState = 3;
        }
        break;
    case 3:
        if (task->data[1] < 0 || gTasks[task->data[1]].isActive != TRUE)
        {
            task->tState = 4;
        }
        break;
    case 4:
        TryFadeOutOldMapMusic();
        WarpFadeOutScreen();
        PlayRainStoppingSoundEffect();
        task->tState = 0;
        task->func = Task_WarpAndLoadMap;
        break;
    }
}

static void Task_DoContestHallWarp(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    switch (task->tState)
    {
    case 0:
        FreezeObjectEvents();
        ScriptContext2_Enable();
        task->tState++;
        break;
    case 1:
        if (!PaletteFadeActive() && BGMusicStopped())
        {
            task->tState++;
        }
        break;
    case 2:
        WarpIntoMap();
        SetMainCallback2(CB2_ReturnToFieldContestHall);
        DestroyTask(taskId);
        break;
    }
}

void DoContestHallWarp(void)
{
    ScriptContext2_Enable();
    TryFadeOutOldMapMusic();
    WarpFadeOutScreen();
    PlayRainStoppingSoundEffect();
    PlaySE(SE_EXIT);
    gFieldCallback = FieldCB_WarpExitFadeFromBlack;
    CreateTask(Task_DoContestHallWarp, 10);
}

static void SetFlashScanlineEffectWindowBoundary(u16 *dest, u32 y, s32 left, s32 right)
{
    if (y <= 160)
    {
        if (left < 0)
            left = 0;
        if (left > 255)
            left = 255;
        if (right < 0)
            right = 0;
        if (right > 255)
            right = 255;
        dest[y] = (left << 8) | right;
    }
}

static void SetFlashScanlineEffectWindowBoundaries(u16 *dest, s32 centerX, s32 centerY, s32 radius)
{
    s32 r = radius;
    s32 v2 = radius;
    s32 v3 = 0;
    while (r >= v3)
    {
        SetFlashScanlineEffectWindowBoundary(dest, centerY - v3, centerX - r, centerX + r);
        SetFlashScanlineEffectWindowBoundary(dest, centerY + v3, centerX - r, centerX + r);
        SetFlashScanlineEffectWindowBoundary(dest, centerY - r, centerX - v3, centerX + v3);
        SetFlashScanlineEffectWindowBoundary(dest, centerY + r, centerX - v3, centerX + v3);
        v2 -= (v3 * 2) - 1;
        v3++;
        if (v2 < 0)
        {
            v2 += 2 * (r - 1);
            r--;
        }
    }
}

static void SetOrbFlashScanlineEffectWindowBoundary(u16 *dest, u32 y, s32 left, s32 right)
{
    if (y <= 160)
    {
        if (left < 0)
            left = 0;
        if (left > 240)
            left = 240;
        if (right < 0)
            right = 0;
        if (right > 240)
            right = 240;
        dest[y] = (left << 8) | right;
    }
}

static void SetOrbFlashScanlineEffectWindowBoundaries(u16 *dest, s32 centerX, s32 centerY, s32 radius)
{
    s32 r = radius;
    s32 v2 = radius;
    s32 v3 = 0;
    while (r >= v3)
    {
        SetOrbFlashScanlineEffectWindowBoundary(dest, centerY - v3, centerX - r, centerX + r);
        SetOrbFlashScanlineEffectWindowBoundary(dest, centerY + v3, centerX - r, centerX + r);
        SetOrbFlashScanlineEffectWindowBoundary(dest, centerY - r, centerX - v3, centerX + v3);
        SetOrbFlashScanlineEffectWindowBoundary(dest, centerY + r, centerX - v3, centerX + v3);
        v2 -= (v3 * 2) - 1;
        v3++;
        if (v2 < 0)
        {
            v2 += 2 * (r - 1);
            r--;
        }
    }
}

#define tFlashCenterX        data[1]
#define tFlashCenterY        data[2]
#define tCurFlashRadius      data[3]
#define tDestFlashRadius     data[4]
#define tFlashRadiusDelta    data[5]
#define tClearScanlineEffect data[6]

static void UpdateFlashLevelEffect(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    switch (tState)
    {
    case 0:
        SetFlashScanlineEffectWindowBoundaries(gScanlineEffectRegBuffers[gScanlineEffect.srcBuffer], tFlashCenterX, tFlashCenterY, tCurFlashRadius);
        tState = 1;
        break;
    case 1:
        SetFlashScanlineEffectWindowBoundaries(gScanlineEffectRegBuffers[gScanlineEffect.srcBuffer], tFlashCenterX, tFlashCenterY, tCurFlashRadius);
        tState = 0;
        tCurFlashRadius += tFlashRadiusDelta;
        if (tCurFlashRadius > tDestFlashRadius)
        {
            if (tClearScanlineEffect == 1)
            {
                ScanlineEffect_Stop();
                tState = 2;
            }
            else
            {
                DestroyTask(taskId);
            }
        }
        break;
    case 2:
        ScanlineEffect_Clear();
        DestroyTask(taskId);
        break;
    }
}

static void UpdateOrbFlashEffect(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    switch (tState)
    {
    case 0:
        SetOrbFlashScanlineEffectWindowBoundaries(gScanlineEffectRegBuffers[gScanlineEffect.srcBuffer], tFlashCenterX, tFlashCenterY, tCurFlashRadius);
        tState = 1;
        break;
    case 1:
        SetOrbFlashScanlineEffectWindowBoundaries(gScanlineEffectRegBuffers[gScanlineEffect.srcBuffer], tFlashCenterX, tFlashCenterY, tCurFlashRadius);
        tState = 0;
        tCurFlashRadius += tFlashRadiusDelta;
        if (tCurFlashRadius > tDestFlashRadius)
        {
            if (tClearScanlineEffect == 1)
            {
                ScanlineEffect_Stop();
                tState = 2;
            }
            else
            {
                DestroyTask(taskId);
            }
        }
        break;
    case 2:
        ScanlineEffect_Clear();
        DestroyTask(taskId);
        break;
    }
}

static void Task_WaitForFlashUpdate(u8 taskId)
{
    if (!FuncIsActiveTask(UpdateFlashLevelEffect))
    {
        EnableBothScriptContexts();
        DestroyTask(taskId);
    }
}

static void StartWaitForFlashUpdate(void)
{
    if (!FuncIsActiveTask(Task_WaitForFlashUpdate))
        CreateTask(Task_WaitForFlashUpdate, 80);
}

static u8 StartUpdateFlashLevelEffect(s32 centerX, s32 centerY, s32 initialFlashRadius, s32 destFlashRadius, s32 clearScanlineEffect, u8 delta)
{
    u8 taskId = CreateTask(UpdateFlashLevelEffect, 80);
    s16 *data = gTasks[taskId].data;

    tCurFlashRadius = initialFlashRadius;
    tDestFlashRadius = destFlashRadius;
    tFlashCenterX = centerX;
    tFlashCenterY = centerY;
    tClearScanlineEffect = clearScanlineEffect;

    if (initialFlashRadius < destFlashRadius)
        tFlashRadiusDelta = delta;
    else
        tFlashRadiusDelta = -delta;

    return taskId;
}

static u8 StartUpdateOrbFlashEffect(s32 centerX, s32 centerY, s32 initialFlashRadius, s32 destFlashRadius, s32 clearScanlineEffect, u8 delta)
{
    u8 taskId = CreateTask(UpdateOrbFlashEffect, 80);
    s16 *data = gTasks[taskId].data;

    tCurFlashRadius = initialFlashRadius;
    tDestFlashRadius = destFlashRadius;
    tFlashCenterX = centerX;
    tFlashCenterY = centerY;
    tClearScanlineEffect = clearScanlineEffect;

    if (initialFlashRadius < destFlashRadius)
        tFlashRadiusDelta = delta;
    else
        tFlashRadiusDelta = -delta;

    return taskId;
}

#undef tCurFlashRadius
#undef tDestFlashRadius
#undef tFlashRadiusDelta
#undef tClearScanlineEffect

// A higher flashLevel value is a smaller flash radius (more darkness). 0 is full brightness
void AnimateFlash(u8 flashLevel)
{
    u8 curFlashLevel = Overworld_GetFlashLevel();
    bool8 fullBrightness = FALSE;
    if (!flashLevel)
        fullBrightness = TRUE;
    StartUpdateFlashLevelEffect(DISPLAY_WIDTH / 2, DISPLAY_HEIGHT / 2, sFlashLevelPixelRadii[curFlashLevel], sFlashLevelPixelRadii[flashLevel], fullBrightness, 2);
    StartWaitForFlashUpdate();
    ScriptContext2_Enable();
}

void WriteFlashScanlineEffectBuffer(u8 flashLevel)
{
    if (flashLevel)
    {
        SetFlashScanlineEffectWindowBoundaries(&gScanlineEffectRegBuffers[0][0], DISPLAY_WIDTH / 2, DISPLAY_HEIGHT / 2, sFlashLevelPixelRadii[flashLevel]);
        CpuFastSet(&gScanlineEffectRegBuffers[0], &gScanlineEffectRegBuffers[1], 480);
    }
}

void WriteBattlePyramidViewScanlineEffectBuffer(void)
{
    SetFlashScanlineEffectWindowBoundaries(&gScanlineEffectRegBuffers[0][0], DISPLAY_WIDTH / 2, DISPLAY_HEIGHT / 2, gSaveBlock2Ptr->frontier.pyramidLightRadius);
    CpuFastSet(&gScanlineEffectRegBuffers[0], &gScanlineEffectRegBuffers[1], 480);
}

static void Task_SpinEnterWarp(u8 taskId)
{
    switch (gTasks[taskId].tState)
    {
    case 0:
        FreezeObjectEvents();
        ScriptContext2_Enable();
        DoPlayerSpinEntrance();
        gTasks[taskId].tState++;
        break;
    case 1:
        if (WaitForWeatherFadeIn() && IsPlayerSpinEntranceActive() != TRUE)
        {
            UnfreezeObjectEvents();
            ScriptContext2_Disable();
            DestroyTask(taskId);
        }
        break;
    }
}

static void Task_SpinExitWarp(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    switch (task->tState)
    {
    case 0:
        FreezeObjectEvents();
        ScriptContext2_Enable();
        PlaySE(SE_WARP_IN);
        DoPlayerSpinExit();
        task->tState++;
        break;
    case 1:
        if (!IsPlayerSpinExitActive())
        {
            WarpFadeOutScreen();
            task->tState++;
        }
        break;
    case 2:
        if (!PaletteFadeActive() && BGMusicStopped())
            task->tState++;
        break;
    case 3:
        WarpIntoMap();
        SetMainCallback2(CB2_LoadMap);
        DestroyTask(taskId);
        break;
    }
}

// Only called by an unused function
// DoTeleportTileWarp is used instead
void DoSpinEnterWarp(void)
{
    ScriptContext2_Enable();
    CreateTask(Task_WarpAndLoadMap, 10);
    gFieldCallback = FieldCB_SpinEnterWarp;
}

// Opposite of DoSpinEnterWarp / DoTeleportTileWarp
// Player exits current map by spinning up offscreen, enters new map with a fade in
void DoSpinExitWarp(void)
{
    ScriptContext2_Enable();
    gFieldCallback = FieldCB_DefaultWarpExit;
    CreateTask(Task_SpinExitWarp, 10);
}

static void LoadOrbEffectPalette(bool8 blueOrb)
{
    int i;
    u16 color[1];

    if (!blueOrb)
        color[0] = RGB_RED;
    else
        color[0] = RGB_BLUE;

    for (i = 0; i < 16; i++)
    {
        LoadPalette(color, 0xF0 + i, 2);
    }
}

static bool8 UpdateOrbEffectBlend(u16 shakeDir)
{
    u8 lo = REG_BLDALPHA & 0xFF;
    u8 hi = REG_BLDALPHA >> 8;

    if (shakeDir != 0)
    {
        if (lo)
            lo--;
    }
    else
    {
        if (hi < 16)
            hi++;
    }

    SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(lo, hi));

    if (lo == 0 && hi == 16)
        return TRUE;
    else
        return FALSE;
}

#define tBlueOrb     data[1]
#define tCenterX     data[2]
#define tCenterY     data[3]
#define tShakeDelay  data[4]
#define tShakeDir    data[5]
#define tDispCnt     data[6]
#define tBldCnt      data[7]
#define tBldAlpha    data[8]
#define tWinIn       data[9]
#define tWinOut      data[10]

static void Task_OrbEffect(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    switch (tState)
    {
    case 0:
        tDispCnt = REG_DISPCNT;
        tBldCnt = REG_BLDCNT;
        tBldAlpha = REG_BLDALPHA;
        tWinIn = REG_WININ;
        tWinOut = REG_WINOUT;
        ClearGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_WIN1_ON);
        SetGpuRegBits(REG_OFFSET_BLDCNT, gOrbEffectBackgroundLayerFlags[0]);
        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(12, 7));
        SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG_ALL | WININ_WIN0_OBJ | WININ_WIN0_CLR);
        SetGpuReg(REG_OFFSET_WINOUT, WINOUT_WIN01_BG1 | WINOUT_WIN01_BG2 | WINOUT_WIN01_BG3 | WINOUT_WIN01_OBJ);
        SetBgTilemapPalette(0, 0, 0, 0x1E, 0x14, 0xF);
        ScheduleBgCopyTilemapToVram(0);
        SetOrbFlashScanlineEffectWindowBoundaries(&gScanlineEffectRegBuffers[0][0], tCenterX, tCenterY, 1);
        CpuFastSet(&gScanlineEffectRegBuffers[0], &gScanlineEffectRegBuffers[1], 480);
        ScanlineEffect_SetParams(sFlashEffectParams);
        tState = 1;
        break;
    case 1:
        sub_8199DF0(0, PIXEL_FILL(1), 0, 1);
        LoadOrbEffectPalette(tBlueOrb);
        StartUpdateOrbFlashEffect(tCenterX, tCenterY, 1, 160, 1, 2);
        tState = 2;
        break;
    case 2:
        if (!FuncIsActiveTask(UpdateOrbFlashEffect))
        {
            EnableBothScriptContexts();
            tState = 3;
        }
        break;
    case 3:
        InstallCameraPanAheadCallback();
        SetCameraPanningCallback(NULL);
        tShakeDir = 0;
        tShakeDelay = 4;
        tState = 4;
        break;
    case 4:
        if (--tShakeDelay == 0)
        {
            s32 panning;
            tShakeDelay = 4;
            tShakeDir ^= 1;
            if (tShakeDir)
                panning = 4;
            else
                panning = -4;
            SetCameraPanning(0, panning);
        }
        break;
    case 6:
        InstallCameraPanAheadCallback();
        tShakeDelay = 8;
        tState = 7;
        break;
    case 7:
        if (--tShakeDelay == 0)
        {
            tShakeDelay = 8;
            tShakeDir ^= 1;
            if (UpdateOrbEffectBlend(tShakeDir) == TRUE)
            {
                tState = 5;
                sub_8199DF0(0, PIXEL_FILL(0), 0, 1);
            }
        }
        break;
    case 5:
        SetGpuReg(REG_OFFSET_WIN0H, 255);
        SetGpuReg(REG_OFFSET_DISPCNT, tDispCnt);
        SetGpuReg(REG_OFFSET_BLDCNT, tBldCnt);
        SetGpuReg(REG_OFFSET_BLDALPHA, tBldAlpha);
        SetGpuReg(REG_OFFSET_WININ, tWinIn);
        SetGpuReg(REG_OFFSET_WINOUT, tWinOut);
        EnableBothScriptContexts();
        DestroyTask(taskId);
        break;
    }
}

void DoOrbEffect(void)
{
    u8 taskId = CreateTask(Task_OrbEffect, 80);
    s16 *data = gTasks[taskId].data;

    if (gSpecialVar_Result == 0)
    {
        tBlueOrb = FALSE;
        tCenterX = 104;
    }
    else if (gSpecialVar_Result == 1)
    {
        tBlueOrb = TRUE;
        tCenterX = 136;
    }
    else if (gSpecialVar_Result == 2)
    {
        tBlueOrb = FALSE;
        tCenterX = 120;
    }
    else
    {
        tBlueOrb = TRUE;
        tCenterX = 120;
    }

    tCenterY = 80;
}

void FadeOutOrbEffect(void)
{
    u8 taskId = FindTaskIdByFunc(Task_OrbEffect);
    gTasks[taskId].tState = 6;
}

#undef tBlueOrb
#undef tCenterX
#undef tCenterY
#undef tShakeDelay
#undef tShakeDir
#undef tDispCnt
#undef tBldCnt
#undef tBldAlpha
#undef tWinIn
#undef tWinOut

void Script_FadeOutMapMusic(void)
{
    Overworld_FadeOutMapMusic();
    CreateTask(Task_EnableScriptAfterMusicFade, 80);
}

static void Task_EnableScriptAfterMusicFade(u8 taskId)
{
    if (BGMusicStopped() == TRUE)
    {
        DestroyTask(taskId);
        EnableBothScriptContexts();
    }
}

#undef tState
#define tState data[9]
#define tDirection data[10]
#define DIR_WIPE_IN 0 // From edges to center.
#define DIR_WIPE_OUT 1 // From center to edges.
#define tChildOffset data[0]

static void DoInwardBarnDoorWipe(void)
{
    u8 taskId = CreateTask(Task_BarnDoorWipe, 80);
    gTasks[taskId].tDirection = DIR_WIPE_IN;
}

static void DoOutwardBarnDoorWipe(void)
{
    u8 taskId = CreateTask(Task_BarnDoorWipe, 80);
    gTasks[taskId].tDirection = DIR_WIPE_OUT;
}

static void BarnDoorWipeSaveGpuRegs(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    data[0] = GetGpuReg(REG_OFFSET_DISPCNT);
    data[1] = GetGpuReg(REG_OFFSET_WININ);
    data[2] = GetGpuReg(REG_OFFSET_WINOUT);
    data[3] = GetGpuReg(REG_OFFSET_BLDCNT);
    data[4] = GetGpuReg(REG_OFFSET_BLDALPHA);
    data[5] = GetGpuReg(REG_OFFSET_WIN0H);
    data[6] = GetGpuReg(REG_OFFSET_WIN0V);
    data[7] = GetGpuReg(REG_OFFSET_WIN1H);
    data[8] = GetGpuReg(REG_OFFSET_WIN1V);
}

static void BarnDoorWipeRestoreGpuRegs(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    SetGpuReg(REG_OFFSET_DISPCNT, data[0]);
    SetGpuReg(REG_OFFSET_WININ, data[1]);
    SetGpuReg(REG_OFFSET_WINOUT, data[2]);
    SetGpuReg(REG_OFFSET_BLDCNT, data[3]);
    SetGpuReg(REG_OFFSET_BLDALPHA, data[4]);
    SetGpuReg(REG_OFFSET_WIN0H, data[5]);
    SetGpuReg(REG_OFFSET_WIN0V, data[6]);
    SetGpuReg(REG_OFFSET_WIN1H, data[7]);
    SetGpuReg(REG_OFFSET_WIN1V, data[8]);
}

static void Task_BarnDoorWipe(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    switch (tState)
    {
        case 0:
            BarnDoorWipeSaveGpuRegs(taskId);
            SetGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON | DISPCNT_WIN1_ON);
            if (tState == 0)
            {
                SetGpuReg(REG_OFFSET_WIN0H, WIN_RANGE(0, 0));
                SetGpuReg(REG_OFFSET_WIN1H, WIN_RANGE(240, 255));
                SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE(0, 255));
                SetGpuReg(REG_OFFSET_WIN1V, WIN_RANGE(0, 255));
            }
            else
            {
                SetGpuReg(REG_OFFSET_WIN0H, WIN_RANGE(0, 120));
                SetGpuReg(REG_OFFSET_WIN1H, WIN_RANGE(120, 255));
                SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE(0, 255));
                SetGpuReg(REG_OFFSET_WIN1V, WIN_RANGE(0, 255));
            }
            SetGpuReg(REG_OFFSET_WININ, 0);
            SetGpuReg(REG_OFFSET_WINOUT, WINOUT_WIN01_BG_ALL |
                                         WINOUT_WIN01_OBJ |
                                         WINOUT_WIN01_CLR);
            tState++;
            break;
        case 1:
            CreateTask(Task_BarnDoorWipeChild, 80);
            tState++;
            break;
        case 2:
            if (!FuncIsActiveTask(Task_BarnDoorWipeChild))
            {
                tState++;
            }
            break;
        case 3:
            BarnDoorWipeRestoreGpuRegs(taskId);
            DestroyTask(taskId);
            break;
    }
}

static void Task_BarnDoorWipeChild(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
	u8 parentTaskId = FindTaskIdByFunc(Task_BarnDoorWipe);
    s16 lhs, rhs;

    if (gTasks[parentTaskId].tDirection == DIR_WIPE_IN)
    {
        lhs = tChildOffset;
        rhs = 240 - tChildOffset;

        if (lhs > 120)
        {
            DestroyTask(taskId);
            return;
        }
    }
    else
    {
        lhs = 120 - tChildOffset;
        rhs = 120 + tChildOffset;

        if (lhs < 0)
        {
            DestroyTask(taskId);
            return;
        }
    }

    SetGpuReg(REG_OFFSET_WIN0H, WIN_RANGE(0, lhs));
    SetGpuReg(REG_OFFSET_WIN1H, WIN_RANGE(rhs, 240));

    if (lhs < 90)
    {
        tChildOffset += 4;
    }
    else
    {
        tChildOffset += 2;
    }
}

#undef tState
#undef tDirection
#undef DIR_WIPE_IN
#undef DIR_WIPE_OUT
#undef tChildOffset

static void Task_StaircaseWarpOut(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    struct ObjectEvent *eventObj = &gObjectEvents[gPlayerAvatar.objectEventId];
    struct Sprite *sprite = &gSprites[gPlayerAvatar.spriteId];

    switch (data[0])
    {
    case 0:
        ScriptContext2_Enable();
        FreezeObjectEvents();
        CameraObjectReset2();
        data[0]++;
        break;
    case 1:
        if (!ObjectEventIsMovementOverridden(eventObj) || ObjectEventClearHeldMovementIfFinished(eventObj))
        {
            if (data[15] != 0)
            {
                data[15]--;
            }
            else
            {
                TryFadeOutOldMapMusic();
                PlayRainStoppingSoundEffect();
                sprite->oam.priority = 1;
                BeginAnimatingPlayerWalkOutOnStaircase(data[1], &data[2], &data[3]);
                PlaySE(SE_EXIT);
                data[0]++;
            }
        }
        break;
    case 2:
        AnimatePlayerWalkOutOnStaircase(data[2], data[3], &data[4], &data[5], &data[6]);
        if (++data[15] > 11)
        {
            WarpFadeOutScreen();
            data[0]++;
        }
        break;
    case 3:
        AnimatePlayerWalkOutOnStaircase(data[2], data[3], &data[4], &data[5], &data[6]);
        if (!PaletteFadeActive() && BGMusicStopped())
            data[0]++;
        break;
    default:
        gFieldCallback = FieldCB_DefaultWarpExit;
        WarpIntoMap();
        SetMainCallback2(CB2_LoadMap);
        DestroyTask(taskId);
        break;
    }
}

static void AnimatePlayerWalkOutOnStaircase(s16 xDelta, s16 yDelta, s16 *x, s16 *y, s16 *frame)
{
    struct ObjectEvent *eventObj = &gObjectEvents[gPlayerAvatar.objectEventId];
    struct Sprite *sprite = &gSprites[gPlayerAvatar.spriteId];

    if (yDelta > 0 || *frame > 6)
        *y += yDelta;

    *x += xDelta;
    (*frame)++;

    gSprites[gPlayerAvatar.spriteId].x2 = *x / 32;
    gSprites[gPlayerAvatar.spriteId].y2 = *y / 32;

    if (eventObj->heldMovementFinished)
        ObjectEventForceSetHeldMovement(eventObj, GetWalkInPlaceNormalMovementAction(GetPlayerFacingDirection()));
}

static void BeginAnimatingPlayerWalkOutOnStaircase(s16 behavior, s16 *x, s16 *y)
{
    struct ObjectEvent *eventObj = &gObjectEvents[gPlayerAvatar.objectEventId];

    ObjectEventForceSetHeldMovement(eventObj, GetWalkInPlaceNormalMovementAction(GetPlayerFacingDirection()));
    SetStaircaseTargetPosValues(behavior, x, y);
}

static void SetStaircaseTargetPosValues(u8 behavior, s16 *x, s16 *y)
{
    if (MetatileBehavior_IsStaircaseUpEast(behavior))
    {
        *x = 16;
        *y = -10;
    }
    else if (MetatileBehavior_IsStaircaseUpWest(behavior))
    {
        *x = -17;
        *y = -10;
    }
    else if (MetatileBehavior_IsStaircaseDownEast(behavior))
    {
        *x = 17;
        *y = 3;
    }
    else if (MetatileBehavior_IsStaircaseDownWest(behavior))
    {
        *x = -17;
        *y = 3;
    }
    else
    {
        *x = 0;
        *y = 0;
    }
}

static void Task_StaircaseWarpIn(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    switch (data[0])
    {
        default:
            if (WaitForWeatherFadeIn() == TRUE)
            {
                CameraObjectReset1();
                ScriptContext2_Disable();
                DestroyTask(taskId);
            }
            break;
        case 0:
            Overworld_PlaySpecialMapMusic();
            WarpFadeInScreen();
            ScriptContext2_Enable();
            BeginAnimatingPlayerWalkInOnStaircase(&data[1], &data[2], &data[3], &data[4], &data[5]);
            data[0]++;
            break;
        case 1:
            if (!AnimatePlayerWalkInOnStaircase(&data[1], &data[2], &data[3], &data[4], &data[5]))
                data[0]++;
            break;
    }
}

static void BeginAnimatingPlayerWalkInOnStaircase(s16 *xPixels, s16 *yPixels, s16 *xSubpixels, s16 *ySubpixels, s16 *frame)
{
    s16 x, y;
    u8 behavior;
    u8 direction;

    PlayerGetDestCoords(&x, &y);
    behavior = MapGridGetMetatileBehaviorAt(x, y);

    if (MetatileBehavior_IsStaircaseDownEast(behavior) || MetatileBehavior_IsStaircaseUpEast(behavior))
        direction = DIR_WEST;
    else
        direction = DIR_EAST;

    ObjectEventForceSetHeldMovement(&gObjectEvents[gPlayerAvatar.objectEventId], GetWalkInPlaceFastMovementAction(direction));
    SetStaircaseTargetPosValues(behavior, xPixels, yPixels);

    *xSubpixels = *xPixels * 16;
    *ySubpixels = *yPixels * 16;
    *frame = 16;
    gSprites[gPlayerAvatar.spriteId].x2 = *xSubpixels / 32;
    gSprites[gPlayerAvatar.spriteId].y2 = *ySubpixels / 32;
    *xPixels = -*xPixels;
    *yPixels = -*yPixels;
}

static bool8 AnimatePlayerWalkInOnStaircase(s16 *xDelta, s16 *yDelta, s16 *x, s16 *y, s16 *frame)
{
    struct Sprite *playerSprite = &gSprites[gPlayerAvatar.spriteId];

    if (*frame == 0)
    {
        playerSprite->x2 = 0;
        playerSprite->y2 = 0;
        return FALSE;
    }
    else
    {
        *x += *xDelta;
        *y += *yDelta;
        playerSprite->x2 = *x / 32;
        playerSprite->y2 = *y / 32;
        (*frame)--;
        return TRUE;
    }
}
