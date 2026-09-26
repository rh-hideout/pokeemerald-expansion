#include "global.h"
#include "mf_moves.h"
#include "mf_rules.h"
#include "pokemon.h"
#include "test/test.h"

static void SetModernMoves(bool8 modernMoves)
{
    struct ModernRules *save = MfRules_GetSaveRules();

    MfRules_ApplyDevDefaults(save);
    MfRules_ApplyGamemodePreset(save, MF_GAMEMODE_CUSTOM);
    save->modernMoves = modernMoves;
    save->rulesLocked = TRUE;
}

static void RestorePhase1Defaults(void)
{
    struct ModernRules *save = MfRules_GetSaveRules();

    save->version = 0;
}

static bool32 LearnsetHasMoveAtLevel(const struct LevelUpMove *learnset, enum Move move, u16 level)
{
    u32 i;

    for (i = 0; learnset[i].move != LEVEL_UP_MOVE_END; i++)
    {
        if (learnset[i].move == move && learnset[i].level == level)
            return TRUE;
    }
    return FALSE;
}

static bool32 LearnsetHasMove(const struct LevelUpMove *learnset, enum Move move)
{
    u32 i;

    for (i = 0; learnset[i].move != LEVEL_UP_MOVE_END; i++)
    {
        if (learnset[i].move == move)
            return TRUE;
    }
    return FALSE;
}

static bool32 U16LearnsetHasMove(const u16 *learnset, enum Move move)
{
    u32 i;

    for (i = 0; learnset[i] != MOVE_UNAVAILABLE; i++)
    {
        if (learnset[i] == move)
            return TRUE;
    }
    return FALSE;
}

TEST("MF: modern movepool on uses GEN_LATEST level-up learnsets")
{
    const struct LevelUpMove *learnset;

    SetModernMoves(TRUE);
    learnset = GetSpeciesLevelUpLearnset(SPECIES_BULBASAUR);

    EXPECT(LearnsetHasMoveAtLevel(learnset, MOVE_VINE_WHIP, 3));
    EXPECT(LearnsetHasMove(learnset, MOVE_SEED_BOMB));
    EXPECT(!LearnsetHasMoveAtLevel(learnset, MOVE_VINE_WHIP, 10));

    RestorePhase1Defaults();
}

TEST("MF: modern movepool off uses FRLG classic level-up learnsets")
{
    const struct LevelUpMove *learnset;

    SetModernMoves(FALSE);
    learnset = GetSpeciesLevelUpLearnset(SPECIES_BULBASAUR);

    EXPECT(LearnsetHasMoveAtLevel(learnset, MOVE_VINE_WHIP, 10));
    EXPECT(!LearnsetHasMove(learnset, MOVE_SEED_BOMB));
    EXPECT(LearnsetHasMoveAtLevel(learnset, MOVE_GROWL, 4));

    RestorePhase1Defaults();
}

TEST("MF: modern movepool gates teachable TM/tutor compatibility")
{
    SetModernMoves(TRUE);
    EXPECT(CanLearnTeachableMove(SPECIES_BULBASAUR, MOVE_LIGHT_SCREEN));
    EXPECT(CanLearnTeachableMove(SPECIES_BULBASAUR, MOVE_SLEEP_TALK));

    SetModernMoves(FALSE);
    EXPECT(!CanLearnTeachableMove(SPECIES_BULBASAUR, MOVE_LIGHT_SCREEN));
    EXPECT(!CanLearnTeachableMove(SPECIES_BULBASAUR, MOVE_SLEEP_TALK));
    EXPECT(CanLearnTeachableMove(SPECIES_BULBASAUR, MOVE_TOXIC));
    EXPECT(CanLearnTeachableMove(SPECIES_BULBASAUR, MOVE_SWORDS_DANCE));

    RestorePhase1Defaults();
}

TEST("MF: modern movepool gates egg moves")
{
    const u16 *eggs;

    SetModernMoves(FALSE);
    eggs = GetSpeciesEggMoves(SPECIES_BULBASAUR);
    EXPECT(U16LearnsetHasMove(eggs, MOVE_LIGHT_SCREEN));
    EXPECT(U16LearnsetHasMove(eggs, MOVE_SAFEGUARD));
    EXPECT(!U16LearnsetHasMove(eggs, MOVE_LEAF_STORM));

    SetModernMoves(TRUE);
    eggs = GetSpeciesEggMoves(SPECIES_BULBASAUR);
    EXPECT(U16LearnsetHasMove(eggs, MOVE_LEAF_STORM));
    EXPECT(U16LearnsetHasMove(eggs, MOVE_GRASSY_TERRAIN));
    EXPECT(!U16LearnsetHasMove(eggs, MOVE_LIGHT_SCREEN));

    RestorePhase1Defaults();
}

TEST("MF: Charmander classic uses Metal Claw; modern uses Dragon Breath")
{
    const struct LevelUpMove *learnset;

    SetModernMoves(FALSE);
    learnset = GetSpeciesLevelUpLearnset(SPECIES_CHARMANDER);
    EXPECT(LearnsetHasMove(learnset, MOVE_METAL_CLAW));
    EXPECT(LearnsetHasMove(learnset, MOVE_DRAGON_RAGE));
    EXPECT(!LearnsetHasMove(learnset, MOVE_DRAGON_BREATH));

    SetModernMoves(TRUE);
    learnset = GetSpeciesLevelUpLearnset(SPECIES_CHARMANDER);
    EXPECT(LearnsetHasMove(learnset, MOVE_DRAGON_BREATH));
    EXPECT(LearnsetHasMove(learnset, MOVE_FIRE_FANG));
    EXPECT(!LearnsetHasMove(learnset, MOVE_METAL_CLAW));

    RestorePhase1Defaults();
}
