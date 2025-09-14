#ifndef GUARD_POKERUS_H
#define GUARD_POKERUS_H

void RandomlyGivePartyPokerus(struct Pokemon *party);
u8 CheckPartyPokerus(struct Pokemon *party);
u8 CheckMonPokerus(struct Pokemon *mon);
u8 CheckMonHasHadPokerus(struct Pokemon *mon);
void UpdatePartyPokerusTime(u16 days);
void PartySpreadPokerus(struct Pokemon *party);

#endif // GUARD_POKERUS_H
