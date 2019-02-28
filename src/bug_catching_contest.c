#include "global.h"
#include "alloc.h"
#include "battle.h"
#include "battle_setup.h"
#include "bug_catching_contest.h"
#include "field_screen_effect.h"
#include "main.h"
#include "overworld.h"
#include "script.h"
#include "sprite.h"
#include "constants/flags.h"

EWRAM_DATA u8 gNumParkBalls = 0;
EWRAM_DATA u8 gBugCatchingContestStatus = 0;
EWRAM_DATA struct Pokemon gCaughtBugCatchingContestMon = {0};

extern const u8 EventScript_RanOutOfParkBalls[];
extern const u8 EventScript_CaughtButRanOutOfParkBalls[];
extern const u8 BugCatchingContest_StartMenuPrompt[];

bool8 InBugCatchingContest(void)
{
    return gBugCatchingContestStatus != BUG_CATCHING_CONTEST_STATUS_OFF;
}

bool8 CaughtBugCatchingContestMon(void)
{
    return gBugCatchingContestStatus == BUG_CATCHING_CONTEST_STATUS_CAUGHT;
}

void EnterBugCatchingContest(void)
{
    gBugCatchingContestStatus = BUG_CATCHING_CONTEST_STATUS_NOT_CAUGHT;
    gNumParkBalls = 2;
    CreateMon(&gCaughtBugCatchingContestMon, 214, 15, 1, 0, 0, OT_ID_PLAYER_ID, 0);
}

void EndBugCatchingContest(void)
{
    gBugCatchingContestStatus = BUG_CATCHING_CONTEST_STATUS_OFF;
    gNumParkBalls = 0;
    memset(&gCaughtBugCatchingContestMon, 0, sizeof(gCaughtBugCatchingContestMon));
}

void BugCatchingContestQuitPrompt(void)
{
    ScriptContext1_SetupScript(BugCatchingContest_StartMenuPrompt);
}

void CB2_EndBugCatchingContestBattle(void)
{
    CpuFill16(0, (void*)(BG_PLTT), BG_PLTT_SIZE);
    ResetOamRange(0, 128);

    if (IsPlayerDefeated(gBattleOutcome))
    {
        SetMainCallback2(CB2_WhiteOut);
    }
    else if (gNumParkBalls > 0)
    {
        SetMainCallback2(CB2_ReturnToField);
    }
    else if (gBattleOutcome == B_OUTCOME_NO_PARK_BALLS)
    {
        ScriptContext2_RunNewScript(EventScript_RanOutOfParkBalls);
        WarpIntoMap();
        gFieldCallback = sub_80AF6F0;
        SetMainCallback2(CB2_LoadMap);
    }
    else if (gBattleOutcome == B_OUTCOME_CAUGHT)
    {
        // Player caught mon, but has no more Park Balls.
        ScriptContext1_SetupScript(EventScript_CaughtButRanOutOfParkBalls);
        ScriptContext1_Stop();
        SetMainCallback2(CB2_ReturnToFieldContinueScriptPlayMapMusic);
    }
}
