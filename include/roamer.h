#ifndef GUARD_ROAMER_H
#define GUARD_ROAMER_H

void DeactivateAllRoamers(void);
void InitRoamer(void);
void UpdateLocationHistoryForRoamer(void);
void RoamerMoveToOtherLocationSet(u32 roamerIndex);
void RoamerMove(u32 roamerIndex);
bool8 IsRoamerAt(u32 roamerIndex, u8 mapGroup, u8 mapNum);
void GenerateRoamerMon(u32 roamerIndex, u32 minLevel);
bool32 CheckForRoamerEncounter(void);
void UpdateRoamerHPStatus(struct Pokemon *mon);
void SetRoamerInactive(u32 roamerIndex);
void GetRoamerLocation(u32 roamerIndex, u8 *mapGroup, u8 *mapNum);
bool8 TryAddRoamer(enum Species species, u8 level);
void MoveAllRoamersToOtherLocationSets(void);
void MoveAllRoamers(void);

extern u8 gEncounteredRoamerIndex;

#endif // GUARD_ROAMER_H
