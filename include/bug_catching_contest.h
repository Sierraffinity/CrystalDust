#ifndef GUARD_BUG_CATCHING_CONTEST_H
#define GUARD_BUG_CATCHING_CONTEST_H

#include "main.h"
#include "constants/map_groups.h"

#define BUG_CATCHING_CONTEST_STATUS_OFF        0
#define BUG_CATCHING_CONTEST_STATUS_NOT_CAUGHT 1
#define BUG_CATCHING_CONTEST_STATUS_CAUGHT     2

#define MAP_BUG_CATCHING_CONTEST MAP_ROUTE29

bool8 InBugCatchingContest(void);
void TryEndBugCatchingContest(void);
bool8 CaughtBugCatchingContestMon(void);
void SetCaughtBugCatchingContestMon(struct Pokemon *caughtMon);
void EnterBugCatchingContest(void);
void EndBugCatchingContest(void);
void BugCatchingContestQuitPrompt(void);
void PlaceBugCatchingContestEventObjects(void);
void CB2_EndBugCatchingContestBattle(void);
void DoSwapBugContestMonScreen(struct Pokemon *newMon, MainCallback returnCallback);

extern u8 gNumParkBalls;
extern u8 gBugCatchingContestStatus;
extern struct Pokemon gCaughtBugCatchingContestMon;

#endif // GUARD_BUG_CATCHING_CONTEST_H
