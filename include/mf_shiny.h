#ifndef GUARD_MF_SHINY_H
#define GUARD_MF_SHINY_H

// Features SHINY CHANCE tiers (ME tx_Features_ShinyChance / menu 1/8192…1/512).
// Threshold is compared against GET_SHINY_VALUE (0..65535); Gen III vanilla is 8.
#define MF_SHINY_CHANCE_8192  0
#define MF_SHINY_CHANCE_4096  1
#define MF_SHINY_CHANCE_2048  2
#define MF_SHINY_CHANCE_1024  3
#define MF_SHINY_CHANCE_512   4
#define MF_SHINY_CHANCE_COUNT 5

// Active shiny threshold for new rolls (SHINY_ODDS << tier). Charm / lure /
// chain / DexNav rerolls in ComputePlayerShinyOdds still apply on top.
// When debug force-shiny is on, returns 65536 (always shiny).
u32 MfGetShinyOddsThreshold(void);

// Threshold for a stored tier id (clamped); used by tests and S37 clause helpers.
u32 MfShinyOddsThresholdForChance(u8 shinyChance);

// TRUE when shinyValue would count as shiny under the active rules.
bool32 MfIsShinyValue(u32 shinyValue);

// TRUE when otId + personality would count as shiny under the active rules.
// S37 shiny clause can reuse this for pre-catch checks; after CreateMon,
// GetMonData(..., MON_DATA_IS_SHINY) is authoritative.
bool32 MfIsShinyOtIdPersonality(u32 otId, u32 personality);

// Debug-only session toggle: next wild/gift rolls are always shiny.
bool32 MfDebug_GetForceShiny(void);
void MfDebug_SetForceShiny(bool32 enabled);

#endif // GUARD_MF_SHINY_H
