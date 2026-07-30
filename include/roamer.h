#ifndef GUARD_ROAMER_H
#define GUARD_ROAMER_H

void DeactivateAllRoamers(void);
void UpdateLocationHistoryForRoamer(void);
void RoamerMoveToOtherLocationSet(u32 roamerIndex);
void RoamerMove(u32 roamerIndex);
bool8 IsRoamerAt(u32 roamerIndex, u8 mapGroup, u8 mapNum);
void CreateRoamerMonInstance(u32 roamerIndex);
bool8 TryStartRoamerEncounter(void);
void UpdateRoamerHPStatus(struct Pokemon *mon);
void NextRoamer(u32 roamerIndex);
void SetRoamerInactive(u32 roamerIndex);
void GetRoamerLocation(u32 roamerIndex, u8 *mapGroup, u8 *mapNum);
bool8 TryAddRoamer(enum Species species, u16 level);
void MoveAllRoamersToOtherLocationSets(void);
void MoveAllRoamers(void);

extern u8 gEncounteredRoamerIndex;
extern u8 sLocationHistory[ROAMER_COUNT][3][2];
extern u8 sRoamerLocation[ROAMER_COUNT][2];
extern u8 gRoamerNearbyIndexOverride;

#endif // GUARD_ROAMER_H
