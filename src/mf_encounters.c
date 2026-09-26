#include "global.h"
#include "event_data.h"
#include "mf_encounters.h"
#include "mf_rules.h"
#include "constants/flags.h"

#if defined(FIRERED)
#include "data/mf_modern_wild_encounters.h"
#endif

bool32 MfShouldUseModernWildEncounters(void)
{
    u8 mode = MfRules_GetAlternateSpawns();

    if (mode == MF_ENCOUNTERS_MODERN)
        return TRUE;
    if (mode == MF_ENCOUNTERS_POSTGAME)
        return FlagGet(FLAG_SYS_GAME_CLEAR);
    return FALSE;
}

const struct WildPokemonHeader *MfGetActiveWildMonHeaders(void)
{
#if defined(FIRERED)
    if (MfShouldUseModernWildEncounters())
        return gMfModernWildMonHeaders;
#endif
    return gWildMonHeaders;
}
