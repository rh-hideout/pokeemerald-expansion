#include "global.h"
#include "event_data.h"
#include "mf_encounters.h"
#include "mf_rules.h"
#include "test/test.h"
#include "constants/flags.h"

static void SetEncountersMode(u8 mode)
{
    struct ModernRules *save = MfRules_GetSaveRules();

    MfRules_ApplyDevDefaults(save);
    MfRules_ApplyGamemodePreset(save, MF_GAMEMODE_CUSTOM);
    save->alternateSpawns = mode & 3;
    save->rulesLocked = TRUE;
}

static void RestorePhase1Defaults(void)
{
    struct ModernRules *save = MfRules_GetSaveRules();

    save->version = 0;
}

TEST("MF: encounters vanilla never uses modern tables")
{
    SetEncountersMode(MF_ENCOUNTERS_VANILLA);
    FlagClear(FLAG_SYS_GAME_CLEAR);
    EXPECT(!MfShouldUseModernWildEncounters());

    FlagSet(FLAG_SYS_GAME_CLEAR);
    EXPECT(!MfShouldUseModernWildEncounters());

    FlagClear(FLAG_SYS_GAME_CLEAR);
    RestorePhase1Defaults();
}

TEST("MF: encounters modern always uses modern tables")
{
    SetEncountersMode(MF_ENCOUNTERS_MODERN);
    FlagClear(FLAG_SYS_GAME_CLEAR);
    EXPECT(MfShouldUseModernWildEncounters());

    FlagSet(FLAG_SYS_GAME_CLEAR);
    EXPECT(MfShouldUseModernWildEncounters());

    FlagClear(FLAG_SYS_GAME_CLEAR);
    RestorePhase1Defaults();
}

TEST("MF: encounters postgame flips only after game clear")
{
    SetEncountersMode(MF_ENCOUNTERS_POSTGAME);
    FlagClear(FLAG_SYS_GAME_CLEAR);
    EXPECT(!MfShouldUseModernWildEncounters());

    FlagSet(FLAG_SYS_GAME_CLEAR);
    EXPECT(MfShouldUseModernWildEncounters());

    FlagClear(FLAG_SYS_GAME_CLEAR);
    RestorePhase1Defaults();
}

TEST("MF: encounters active wild headers is non-NULL")
{
    SetEncountersMode(MF_ENCOUNTERS_VANILLA);
    EXPECT(MfGetActiveWildMonHeaders() != NULL);

    SetEncountersMode(MF_ENCOUNTERS_MODERN);
    EXPECT(MfGetActiveWildMonHeaders() != NULL);

    RestorePhase1Defaults();
}
