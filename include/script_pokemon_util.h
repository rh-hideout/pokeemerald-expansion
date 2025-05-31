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

void CreateScriptedWildShadowMon(u16 species, u8 level, u16 item, u16 heartValue);
void CreateScriptedDoubleWildShadowMon(u16 species1, u8 level1, u16 item1, u16 heartValue1, u16 species2, u8 level2, u16 item2, u16 heartValue2);

#endif // GUARD_SCRIPT_POKEMON_UTIL_H
