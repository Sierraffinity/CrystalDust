#include "global.h"
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
EWRAM_DATA u8 gInBugCatchingContest = 0;
EWRAM_DATA u16 gCaughtBugCatchingContestSpecies = 0;
EWRAM_DATA struct Pokemon gCaughtBugCatchingContestMon = {0};

extern const u8 EventScript_RanOutOfParkBalls[];
extern const u8 EventScript_CaughtButRanOutOfParkBalls[];

bool8 InBugCatchingContest(void)
{
    return gInBugCatchingContest;
}

void EnterBugCatchingContest(void)
{
    gInBugCatchingContest = 1;
    gNumParkBalls = 2;
}

void EndBugCatchingContest(void)
{
    gInBugCatchingContest = 0;
    gNumParkBalls = 0;
}

void CB2_EndBugCatchingContestBattle(void)
{
    CpuFill16(0, (void*)(BG_PLTT), BG_PLTT_SIZE);
    ResetOamRange(0, 128);

    if (IsPlayerDefeated(gBattleOutcome))
    {
        EndBugCatchingContest();
        SetMainCallback2(CB2_WhiteOut);
    }
    else if (gNumParkBalls > 0)
    {
        SetMainCallback2(CB2_ReturnToField);
    }
    else if (gBattleOutcome == B_OUTCOME_NO_PARK_BALLS)
    {
        EndBugCatchingContest();
        ScriptContext2_RunNewScript(EventScript_RanOutOfParkBalls);
        WarpIntoMap();
        gFieldCallback = sub_80AF6F0;
        SetMainCallback2(CB2_LoadMap);
    }
    else if (gBattleOutcome == B_OUTCOME_CAUGHT)
    {
        // Player caught mon, but has no more Park Balls.
        EndBugCatchingContest();
        ScriptContext1_SetupScript(EventScript_CaughtButRanOutOfParkBalls);
        ScriptContext1_Stop();
        SetMainCallback2(CB2_ReturnToFieldContinueScriptPlayMapMusic);
    }
}
