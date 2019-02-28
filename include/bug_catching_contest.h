#ifndef GUARD_BUG_CATCHING_CONTEST_H
#define GUARD_BUG_CATCHING_CONTEST_H

#define BUG_CATCHING_CONTEST_STATUS_OFF        0
#define BUG_CATCHING_CONTEST_STATUS_NOT_CAUGHT 1
#define BUG_CATCHING_CONTEST_STATUS_CAUGHT     2

bool8 InBugCatchingContest(void);
bool8 CaughtBugCatchingContestMon(void);
void EnterBugCatchingContest(void);
void EndBugCatchingContest(void);
void BugCatchingContestQuitPrompt(void);
void CB2_EndBugCatchingContestBattle(void);

extern u8 gNumParkBalls;
extern u8 gInBugCatchingContest;
extern u16 gCaughtBugCatchingContestSpecies;
extern struct Pokemon gCaughtBugCatchingContestMon;

#endif // GUARD_BUG_CATCHING_CONTEST_H
