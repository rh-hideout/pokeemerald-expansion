#ifndef GUARD_SCRIPT_POKEMON_UTIL_H
#define GUARD_SCRIPT_POKEMON_UTIL_H

#include "constants/pokeball.h"
#include "constants/pokemon.h"

u32 ScriptGiveMon(enum Species species, u16 level, enum Item item);
u8 ScriptGiveEgg(enum Species species);
void CreateScriptedWildMon(enum Species species, u16 level, enum Item item);
void CreateScriptedDoubleWildMon(enum Species species, u16 level, enum Item item, enum Species species2, u16 level2, enum Item item2);
void ScriptSetMonMoveSlot(u8 monIndex, enum Move move, u8 slot);
void ReducePlayerPartyToSelectedMons(void);
void HealPlayerParty(void);
void Script_GetChosenMonOffensiveEVs(void);
void Script_GetChosenMonDefensiveEVs(void);
void Script_GetChosenMonOffensiveIVs(void);
void Script_GetChosenMonDefensiveIVs(void);
u32 ScriptGiveMonParameterized(u8 side, u8 slot, enum Species species, u16 level, enum Item item, enum PokeBall ball, u8 nature, u8 abilityNum, u8 gender, u16 *evs, u16 *ivs, enum Move *moves, enum ShinyMode shinyMode, bool8 gmaxFactor, enum Type teraType, u8 dmaxLevel);

#endif // GUARD_SCRIPT_POKEMON_UTIL_H
