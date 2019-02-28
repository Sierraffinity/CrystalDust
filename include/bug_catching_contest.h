#ifndef GUARD_BUG_CATCHING_CONTEST_H
#define GUARD_BUG_CATCHING_CONTEST_H

bool8 InBugCatchingContest(void);
void EnterBugCatchingContest(void);
void EndBugCatchingContest(void);
void CB2_EndBugCatchingContestBattle(void);

extern u8 gNumParkBalls;
extern u8 gInBugCatchingContest;
extern u16 gCaughtBugCatchingContestSpecies;
extern struct Pokemon gCaughtBugCatchingContestMon;

#endif // GUARD_BUG_CATCHING_CONTEST_H
