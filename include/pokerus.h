#ifndef GUARD_POKERUS_H
#define GUARD_POKERUS_H

u32 GetDaysLeftBasedOnStrain(u32 strain);
void RandomlyGivePartyPokerus(void);
bool32 CheckPartyPokerus(void);
bool32 CheckMonPokerus(struct Pokemon *mon);
bool32 CheckMonHasHadPokerus(struct Pokemon *mon);
void UpdatePartyPokerusTime(u16 days);
void PartySpreadPokerus(void);

#endif // GUARD_POKERUS_H
