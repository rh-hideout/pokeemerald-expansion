#ifndef GUARD_SCRIPT_POKEMON_UTIL_H
#define GUARD_SCRIPT_POKEMON_UTIL_H

u32 ScriptGiveMon(u16 species, u8 level, u16 item);
u8 ScriptGiveEgg(u16 species);
void CreateScriptedWildMon(u16 species, u8 level, u16 item);
void CreateScriptedDoubleWildMon(u16 species, u8 level, u16 item, u16 species2, u8 level2, u16 item2);
void ScriptSetMonMoveSlot(u8 monIndex, u16 move, u8 slot);
void ReducePlayerPartyToSelectedMons(void);
void HealPlayerParty(void);
void Script_GetChosenMonOffensiveEVs(void);
void Script_GetChosenMonDefensiveEVs(void);
void Script_GetChosenMonOffensiveIVs(void);
void Script_GetChosenMonDefensiveIVs(void);
u32 BirchCase_GiveMonParameterized(u16 species, u8 level, u16 item, u8 ball, u8 nature, u8 abilityNum, u8 gender, u8 *evs, u8 *ivs, u16 *moves, bool8 ggMaxFactor, u8 teraType, bool8 isShinyExpansion);

#endif // GUARD_SCRIPT_POKEMON_UTIL_H
