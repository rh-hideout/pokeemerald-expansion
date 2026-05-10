#ifndef GUARD_NUZLOCKE_H
#define GUARD_NUZLOCKE_H

#include "pokemon.h"

// Nuzlocke encounter status values
#define NUZLOCKE_ENCOUNTER_NORMAL       0 // Not in Nuzlocke or can't catch (location used)
#define NUZLOCKE_ENCOUNTER_CATCHABLE    1 // First encounter, new species
#define NUZLOCKE_ENCOUNTER_DUPLICATE    2 // Duplicate species, can skip
#define NUZLOCKE_ENCOUNTER_SHINY        3 // Shiny clause applies

// Check if Nuzlocke mode is active
bool8 IsNuzlockeActive(void);

// Official location-based encounter tracking (from pokeemerald guide)
bool8 HasWildPokemonBeenSeenInLocation(u8 location, bool8 setEncounteredIfFirst);
bool8 HasWildPokemonBeenCaughtInLocation(u8 location, bool8 setCaughtIfCaught);

// Legacy compatibility
bool8 IsFirstEncounterInArea(u16 mapGroup, u16 mapNum);

// Dead Pokemon functions
bool8 IsMonDead(struct Pokemon *mon);
bool8 IsBoxMonDead(struct BoxPokemon *boxMon);
void SetMonDead(struct Pokemon *mon, bool8 isDead);
void SetBoxMonDead(struct BoxPokemon *boxMon, bool8 isDead);

// Species checking for duplicate clause
bool8 PlayerOwnsSpecies(u16 species);

// Faint handling functions
void NuzlockeHandleFaint(struct Pokemon *mon);

// Whiteout handling
void NuzlockeHandleWhiteout(void);

// Catching restrictions
bool8 NuzlockeCanCatchPokemon(u16 species, u32 personality, u32 otId);

// Battle end handling
void NuzlockeOnBattleEnd(void);

// Nuzlocke encounter status (for messages)
u8 GetNuzlockeEncounterStatus(u16 species, u32 personality, u32 otId);

// Silent save function
void NuzlockeSilentSave(void);

// Nurse Joy PC Transfer special functions
u16 CountDeadPartyMonsSpecial(void);
bool8 CanDepositDeadMonSpecial(void);
void PrepareNextDeadMonInfo(void);
void DepositDeadPartyMonToPC(void);

#endif // GUARD_NUZLOCKE_H