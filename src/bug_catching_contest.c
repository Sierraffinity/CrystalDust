#include "global.h"
#include "battle.h"
#include "battle_setup.h"
#include "bug_catching_contest.h"
#include "field_screen_effect.h"
#include "main.h"
#include "overworld.h"
#include "sprite.h"

bool8 InBugCatchingContest(void)
{
    return FALSE;
}

void CB2_EndBugCatchingContestBattle(void)
{
    CpuFill16(0, (void*)(BG_PLTT), BG_PLTT_SIZE);
    ResetOamRange(0, 128);

    if (IsPlayerDefeated(gBattleOutcome))
    {
        SetMainCallback2(CB2_WhiteOut);
    }
    else
    {
        SetMainCallback2(CB2_ReturnToField);
        gFieldCallback = sub_80AF6F0;
    }
}
