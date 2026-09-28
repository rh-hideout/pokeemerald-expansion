#include "global.h"
#include "event_data.h"
#include "mf_nuzlocke.h"
#include "mf_rules.h"
#include "overworld.h"
#include "region_map.h"
#include "constants/battle.h"
#include "constants/flags.h"
#include "constants/region_map_sections.h"
#include "gba/isagbprint.h"

bool8 MfNuzlockeFlagGetFrom(const u8 *flags, u16 mapsec)
{
    if (flags == NULL || mapsec >= MAPSEC_COUNT)
        return FALSE;
    return (flags[mapsec / 8] >> (mapsec & 7)) & 1;
}

void MfNuzlockeFlagSetIn(u8 *flags, u16 mapsec)
{
    if (flags == NULL || mapsec >= MAPSEC_COUNT)
        return;
    flags[mapsec / 8] |= (u8)(1 << (mapsec & 7));
}

void MfNuzlockeFlagClearIn(u8 *flags, u16 mapsec)
{
    if (flags == NULL || mapsec >= MAPSEC_COUNT)
        return;
    flags[mapsec / 8] &= (u8)~(1 << (mapsec & 7));
}

u16 MfNuzlockeCountUsedFrom(const u8 *flags)
{
    u16 mapsec;
    u16 count = 0;

    if (flags == NULL)
        return 0;

    for (mapsec = 0; mapsec < MAPSEC_COUNT; mapsec++)
    {
        if (MfNuzlockeFlagGetFrom(flags, mapsec))
            count++;
    }
    return count;
}

bool8 MfNuzlockeFlagGet(u16 mapsec)
{
    return MfNuzlockeFlagGetFrom(MfRules_GetActiveRules()->nuzlockeEncounterFlags, mapsec);
}

void MfNuzlockeFlagSet(u16 mapsec)
{
#if MF_RULES_ENGINE
    MfNuzlockeFlagSetIn(MfRules_GetSaveRules()->nuzlockeEncounterFlags, mapsec);
#else
    (void)mapsec;
#endif
}

void MfNuzlockeFlagClear(u16 mapsec)
{
#if MF_RULES_ENGINE
    MfNuzlockeFlagClearIn(MfRules_GetSaveRules()->nuzlockeEncounterFlags, mapsec);
#else
    (void)mapsec;
#endif
}

u16 MfNuzlockeCountUsedAreas(void)
{
    return MfNuzlockeCountUsedFrom(MfRules_GetActiveRules()->nuzlockeEncounterFlags);
}

u16 MfNuzlocke_GetCurrentMapsec(void)
{
    // FR Kanto Safari is one MAPSEC_KANTO_SAFARI_ZONE for all zones (unlike
    // ME's Hoenn per-area split). Use the live map header section as-is.
    return GetCurrentRegionMapSectionId();
}

bool32 MfNuzlocke_IsEncounterLockActive(void)
{
#if !MF_NUZLOCKE || !MF_RULES_ENGINE
    return FALSE;
#else
    // Easy mini-mode sets nuzlockeEasy only — no area lock (ADR 0022 / 0036).
    if (!MfRules_IsNuzlocke())
        return FALSE;
    if (!FlagGet(FLAG_SYS_POKEMON_GET))
        return FALSE;
    // ME gates on FLAG_ADVENTURE_STARTED (Pokédex). On FRLG that symbol is a
    // stub (= 0); FlagGet(0) is always FALSE — use FLAG_SYS_POKEDEX_GET.
#if IS_FRLG
    if (!FlagGet(FLAG_SYS_POKEDEX_GET))
        return FALSE;
#else
    if (!FlagGet(FLAG_ADVENTURE_STARTED))
        return FALSE;
#endif
    // ME stops after champion; FR uses game-clear (beat Elite Four).
    if (FlagGet(FLAG_SYS_GAME_CLEAR))
        return FALSE;
    return TRUE;
#endif
}

bool32 MfNuzlocke_WildBattleConsumesEncounter(u32 battleTypeFlags)
{
    // Mirror ME's end-of-battle mask: trainers, tutorial, legendaries, and
    // link/frontier do not consume. Script gifts / fossils / starter never
    // reach this path. Statics that use BATTLE_TYPE_LEGENDARY are excluded.
    if (battleTypeFlags & (BATTLE_TYPE_TRAINER
                         | BATTLE_TYPE_FIRST_BATTLE
                         | BATTLE_TYPE_LINK
                         | BATTLE_TYPE_RECORDED_LINK
                         | BATTLE_TYPE_FRONTIER
                         | BATTLE_TYPE_EREADER_TRAINER
                         | BATTLE_TYPE_CATCH_TUTORIAL
                         | BATTLE_TYPE_LEGENDARY
                         | BATTLE_TYPE_GHOST
                         | BATTLE_TYPE_INGAME_PARTNER
                         | BATTLE_TYPE_RECORDED
                         | BATTLE_TYPE_TRAINER_HILL))
        return FALSE;

    return TRUE;
}

bool32 MfNuzlocke_IsAreaCaptureBlocked(void)
{
    if (!MfNuzlocke_IsEncounterLockActive())
        return FALSE;
    return MfNuzlockeFlagGet(MfNuzlocke_GetCurrentMapsec());
}

bool32 MfNuzlocke_ShouldShowFirstEncounterIcon(void)
{
    // ME: show red "1" when Nuzlocke is on and this wild mon is still catchable
    // for the area (not yet used). Species-clause / monotype hide it in S37/S48.
    if (!MfNuzlocke_IsEncounterLockActive())
        return FALSE;
    if (MfNuzlocke_IsAreaCaptureBlocked())
        return FALSE;
    return TRUE;
}

void MfNuzlocke_OnWildBattleEnd(u32 battleTypeFlags)
{
    if (!MfNuzlocke_IsEncounterLockActive())
        return;
    if (!MfNuzlocke_WildBattleConsumesEncounter(battleTypeFlags))
        return;
    MfNuzlockeFlagSet(MfNuzlocke_GetCurrentMapsec());
}

void MfNuzlocke_DebugDumpUsedAreas(void)
{
#ifndef NDEBUG
    u16 mapsec;
    u16 count = 0;
    u8 name[32];

    DebugPrintfLevel(MGBA_LOG_WARN, "=== MF Nuzlocke used areas ===");
    DebugPrintfLevel(MGBA_LOG_WARN, "lockActive=%u nuzlocke=%u used=%u",
        MfNuzlocke_IsEncounterLockActive(),
        MfRules_IsNuzlocke(),
        MfNuzlockeCountUsedAreas());
    DebugPrintfLevel(MGBA_LOG_WARN, "gates: pokemon=%u pokedex=%u gameClear=%u mapsec=%u blocked=%u",
        FlagGet(FLAG_SYS_POKEMON_GET),
#if IS_FRLG
        FlagGet(FLAG_SYS_POKEDEX_GET),
#else
        FlagGet(FLAG_ADVENTURE_STARTED),
#endif
        FlagGet(FLAG_SYS_GAME_CLEAR),
        MfNuzlocke_GetCurrentMapsec(),
        MfNuzlocke_IsAreaCaptureBlocked());

    for (mapsec = 0; mapsec < MAPSEC_COUNT; mapsec++)
    {
        if (!MfNuzlockeFlagGet(mapsec))
            continue;
        GetMapName(name, mapsec, 0);
        DebugPrintfLevel(MGBA_LOG_WARN, "  [%u] %s", mapsec, name);
        count++;
    }
    if (count == 0)
        DebugPrintfLevel(MGBA_LOG_WARN, "  (none)");
#else
    (void)0;
#endif
}
