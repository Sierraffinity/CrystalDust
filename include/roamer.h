#ifndef GUARD_ROAMER_H
#define GUARD_ROAMER_H

void ClearRoamerData(void);
void ClearRoamerLocationData(void);
void InitRoamer(void);
void UpdateLocationHistoryForRoamer(void);
void RoamerMoveToOtherLocationSet(void);
void RoamerMove(void);
u16 IsRoamerAt(u8 mapGroup, u8 mapNum);
void CreateRoamerMonInstance(u16 species);
u8 TryStartRoamerEncounter(void);
void UpdateRoamerHPStatus(struct Pokemon *mon);
void SetRoamerInactive(struct Pokemon *mon);
void GetRoamerLocation(u16 species, u8 *mapGroup, u8 *mapNum);
void RegenerateRaikou(void);
void RegenerateEntei(void);
void IsRaikouActive(void);
void IsEnteiActive(void);

#endif // GUARD_ROAMER_H
