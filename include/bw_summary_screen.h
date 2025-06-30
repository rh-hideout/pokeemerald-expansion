#ifndef GUARD_BW_SUMMARY_SCREEN_H
#define GUARD_BW_SUMMARY_SCREEN_H

#include "main.h"
#include "config/bw_summary_screen.h"

// Looking for configs for renaming mons and relearning moves? Those use the standard expansion configs
// P_SUMMARY_SCREEN_RENAME and P_SUMMARY_SCREEN_MOVE_RELEARNER in include/config/pokemon.h
// Same with showing dynamic types:
// P_SHOW_DYNAMIC_TYPES

/* Info for users

General tilemap setup
BG3 - scrolling grid background (or not scrolling if you turned the config off)
BG2 - main UI overlayed on scrolling BG
BG1 - pop in move effect windows
BG0 - text windows

Mosaic effect used when transitioning between screens and actvating
effect windows is controlled by tMosaicStrength in the relevant
task functions.

BG scrolling speed can be modified by altering the value parameter
of the ChangeBgX and ChangeBgY functions in VBlank()

Main UI and shadow transparency levels can be adjusted by changing the
value written to the alpha blend register in this line in bw_summary_screen.c:

static void InitBGs(void)
...
SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(14, 6));
...
}

*/

/* ravetodo in future updates
- extended move desc window
- ribbons
*/

void ShowPokemonSummaryScreen_BW(u8 mode, void *mons, u8 monIndex, u8 maxMonIndex, void (*callback)(void));
void ShowSelectMovePokemonSummaryScreen_BW(struct Pokemon *mons, u8 monIndex, u8 maxMonIndex, void (*callback)(void), u16 newMove);
void ShowPokemonSummaryScreenHandleDeoxys_BW(u8 mode, struct BoxPokemon *mons, u8 monIndex, u8 maxMonIndex, void (*callback)(void));
u8 GetMoveSlotToReplace_BW(void);
void SummaryScreen_SetAnimDelayTaskId_BW(u8 taskId);
void SummaryScreen_SetShadowAnimDelayTaskId_BW(u8 taskId);

#endif // GUARD_BW_SUMMARY_SCREEN_H
