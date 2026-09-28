#include "global.h"
#include "battle.h"
#include "config_changes.h"
#include "dexnav.h"
#include "event_data.h"
#include "item.h"
#include "mass_outbreak.h"
#include "new_game.h"
#include "pokemon.h"
#include "random.h"
#include "safari_zone.h"
#include "wild_encounter.h"
#include "constants/item.h"
#include "test/overworld_script.h"
#include "test/test.h"

static void PrepareMassOutbreakShinyTest(void)
{
    ZeroPlayerPartyMons();
    ClearBag();
    AddBagItem(ITEM_POKE_BALL, 1);
    VarSet(VAR_REPEL_STEP_COUNT, 0);
    FlagClear(P_FLAG_FORCE_SHINY);
    FlagClear(P_FLAG_FORCE_NO_SHINY);
    FlagClear(WE_FLAG_NO_CATCHING);
    FlagClear(DN_FLAG_SEARCHING);
    ResetSafariZoneFlag();
    gDexNavSpecies = SPECIES_NONE;
    gIsFishingEncounter = FALSE;
    gBattleTypeFlags = 0;
    SetTrainerId(0, gSaveBlock2Ptr->playerTrainerId);
    SetConfig(CONFIG_SHINY_THRESHOLD, 16);
    StartStaticMassOutbreak(OUTBREAK_ID_ROUTE102);
}

TEST("Mass outbreak Shiny bonuses apply at 30 and 60 cleared Pokémon")
{
    u32 clearedCount = 0;
    bool32 needsSecondRoll = FALSE, expected = FALSE;
    PARAMETRIZE { clearedCount = 0; needsSecondRoll = FALSE; expected = FALSE; }
    PARAMETRIZE { clearedCount = 29; needsSecondRoll = FALSE; expected = FALSE; }
    PARAMETRIZE { clearedCount = 30; needsSecondRoll = FALSE; expected = TRUE; }
    PARAMETRIZE { clearedCount = 59; needsSecondRoll = FALSE; expected = TRUE; }
    PARAMETRIZE { clearedCount = 30; needsSecondRoll = TRUE; expected = FALSE; }
    PARAMETRIZE { clearedCount = 59; needsSecondRoll = TRUE; expected = FALSE; }
    PARAMETRIZE { clearedCount = 60; needsSecondRoll = TRUE; expected = TRUE; }
    PARAMETRIZE { clearedCount = 255; needsSecondRoll = TRUE; expected = TRUE; }

    PrepareMassOutbreakShinyTest();
    gSaveBlock1Ptr->outbreakClearedCount = clearedCount;
    // With OTID 0 these streams yield shiny values 24, 9 or 50973, 17, 0.
    rng_value_t seed = needsSecondRoll ? (rng_value_t){.a = 50957, .b = 16} : (rng_value_t){.a = 16, .b = 8};
    gRngValue = seed;
    EXPECT_EQ(SetUpMassOutbreakEncounter(0), TRUE);
    EXPECT_EQ(IsMonShiny(&gParties[B_TRAINER_OPPONENT_A][0]), expected && WE_MASS_OUTBREAK_SHINY_BONUS >= GEN_9);
    EXPECT_EQ(GetMonData(&gParties[B_TRAINER_OPPONENT_A][0], MON_DATA_PERSONALITY), needsSecondRoll ? 50973 : 24);
    EXPECT_EQ(gSaveBlock1Ptr->outbreakClearedCount, clearedCount);
    EXPECT_EQ(gBattleTypeFlags & BATTLE_TYPE_MASS_OUTBREAK, 0);

    // Generating an outbreak OWE must not give the next ordinary encounter or gift its bonus.
    gRngValue = seed;
    CreateWildMon(SPECIES_WOBBUFFET, 5);
    EXPECT_EQ(IsMonShiny(&gParties[B_TRAINER_OPPONENT_A][0]), FALSE);
    struct Pokemon gift;
    gRngValue = (rng_value_t){.a = 8};
    CreateMon(&gift, SPECIES_WOBBUFFET, 5, 16, OTID_STRUCT_PLAYER_ID);
    EXPECT_EQ(IsMonShiny(&gift), FALSE);
}

TEST("Mass outbreak Shiny rolls stack with the Shiny Charm and lure")
{
    PrepareMassOutbreakShinyTest();
    // No roll can succeed, so the RNG counter measures every additional attempt.
    SetConfig(CONFIG_SHINY_THRESHOLD, 0);
    SeedRng(0);
    SetUpMassOutbreakEncounter(0);
    u32 baseCounter = gRngValue.ctr;

    gSaveBlock1Ptr->outbreakClearedCount = 60;
    AddBagItem(ITEM_SHINY_CHARM, 1);
    VarSet(VAR_REPEL_STEP_COUNT, REPEL_LURE_MASK | 1);
    SeedRng(0);
    SetUpMassOutbreakEncounter(0);
    EXPECT_EQ(gRngValue.ctr - baseCounter, I_SHINY_CHARM_ADDITIONAL_ROLLS + 1 + (WE_MASS_OUTBREAK_SHINY_BONUS >= GEN_9 ? 2 : 0));
    EXPECT_EQ(IsMonShiny(&gParties[B_TRAINER_OPPONENT_A][0]), FALSE);
    VarSet(VAR_REPEL_STEP_COUNT, 0);
    ClearBag();
}

TEST("Mass outbreak progress counts only defeated or caught outbreak encounters")
{
    u32 outcome = 0, flags = 0, expected = 0;
    PARAMETRIZE { outcome = B_OUTCOME_WON; flags = BATTLE_TYPE_MASS_OUTBREAK; expected = 30; }
    PARAMETRIZE { outcome = B_OUTCOME_CAUGHT; flags = BATTLE_TYPE_MASS_OUTBREAK; expected = 30; }
    PARAMETRIZE { outcome = B_OUTCOME_RAN; flags = BATTLE_TYPE_MASS_OUTBREAK; expected = 29; }
    PARAMETRIZE { outcome = B_OUTCOME_LOST; flags = BATTLE_TYPE_MASS_OUTBREAK; expected = 29; }
    PARAMETRIZE { outcome = B_OUTCOME_DREW; flags = BATTLE_TYPE_MASS_OUTBREAK; expected = 29; }
    PARAMETRIZE { outcome = B_OUTCOME_PLAYER_TELEPORTED; flags = BATTLE_TYPE_MASS_OUTBREAK; expected = 29; }
    PARAMETRIZE { outcome = B_OUTCOME_MON_FLED; flags = BATTLE_TYPE_MASS_OUTBREAK; expected = 29; }
    PARAMETRIZE { outcome = B_OUTCOME_MON_TELEPORTED; flags = BATTLE_TYPE_MASS_OUTBREAK; expected = 29; }
    PARAMETRIZE { outcome = B_OUTCOME_WON; flags = 0; expected = 29; }
    PARAMETRIZE { outcome = B_OUTCOME_WON; flags = BATTLE_TYPE_MASS_OUTBREAK | BATTLE_TYPE_TRAINER; expected = 29; }
    PARAMETRIZE { outcome = B_OUTCOME_WON; flags = BATTLE_TYPE_MASS_OUTBREAK | BATTLE_TYPE_RECORDED; expected = 29; }
    PARAMETRIZE { outcome = B_OUTCOME_WON; flags = BATTLE_TYPE_MASS_OUTBREAK | BATTLE_TYPE_LINK; expected = 29; }

    StartStaticMassOutbreak(OUTBREAK_ID_ROUTE102);
    gSaveBlock1Ptr->outbreakClearedCount = 29;
    gBattleTypeFlags = flags;
    gBattleOutcome = outcome;
    UpdateMassOutbreakProgress();
    EXPECT_EQ(GetMassOutbreakClearedCount(), expected);
    EXPECT_EQ(gBattleTypeFlags & BATTLE_TYPE_MASS_OUTBREAK, 0);
    UpdateMassOutbreakProgress();
    EXPECT_EQ(GetMassOutbreakClearedCount(), expected);
    gBattleTypeFlags = 0;
    gBattleOutcome = 0;
}

TEST("Mass outbreak progress saturates at 60 and ignores expired outbreaks")
{
    StartStaticMassOutbreak(OUTBREAK_ID_ROUTE102);
    gSaveBlock1Ptr->outbreakClearedCount = 59;
    gBattleOutcome = B_OUTCOME_WON;
    for (u32 i = 0; i < 200; i++)
    {
        gBattleTypeFlags = BATTLE_TYPE_MASS_OUTBREAK;
        UpdateMassOutbreakProgress();
    }
    EXPECT_EQ(gSaveBlock1Ptr->outbreakClearedCount, 60);
    RUN_OVERWORLD_SCRIPT(getmassoutbreakdata VAR_RESULT, OUTBREAK_DATA_CLEARED_COUNT;);
    EXPECT_EQ(gSpecialVar_Result, 60);
    UpdateMassOutbreakDaysLeft(gSaveBlock1Ptr->outbreakDaysLeft);
    gBattleTypeFlags = BATTLE_TYPE_MASS_OUTBREAK;
    UpdateMassOutbreakProgress();
    EXPECT_EQ(GetMassOutbreakClearedCount(), 0);
    gBattleOutcome = 0;
}

TEST("Mass outbreak progress treats legacy save padding as zero")
{
    u32 version = 0;
    PARAMETRIZE { version = 0; }
    PARAMETRIZE { version = 1; }
    PARAMETRIZE { version = 65535; }

    PrepareMassOutbreakShinyTest();
    gSaveBlock1Ptr->outbreakClearedCount = 255;
    gSaveBlock1Ptr->outbreakProgressVersion = version;
    EXPECT_EQ(GetMassOutbreakClearedCount(), 0);
    gRngValue = (rng_value_t){.a = 16, .b = 8};
    SetUpMassOutbreakEncounter(0);
    EXPECT_EQ(IsMonShiny(&gParties[B_TRAINER_OPPONENT_A][0]), FALSE);
    gBattleTypeFlags = BATTLE_TYPE_MASS_OUTBREAK;
    gBattleOutcome = B_OUTCOME_CAUGHT;
    UpdateMassOutbreakProgress();
    EXPECT_EQ(GetMassOutbreakClearedCount(), 1);
    gBattleOutcome = 0;
}

TEST("Mass outbreak progress resets when the outbreak is replaced or ended")
{
    u32 action = 0;
    for (u32 i = 0; i < 7; i++) PARAMETRIZE { action = i; }
    StartStaticMassOutbreak(OUTBREAK_ID_ROUTE102);
    gSaveBlock1Ptr->outbreakClearedCount = 60;
    switch (action)
    {
    case 0:
        StartStaticMassOutbreak(OUTBREAK_ID_ROUTE102);
        break;
    case 1:
        RUN_OVERWORLD_SCRIPT(setdynamicoutbreak SPECIES_BULBASAUR, 5, MOVE_TACKLE, MOVE_NONE, MOVE_NONE, MOVE_NONE, 100, 1, MAP_OLDALE_TOWN, noReplacement=FALSE;);
        break;
    case 2:
        RUN_OVERWORLD_SCRIPT(clearactiveoutbreak;);
        break;
    case 3:
        UpdateMassOutbreakDaysLeft(gSaveBlock1Ptr->outbreakDaysLeft);
        break;
    case 4:
        RUN_OVERWORLD_SCRIPT(editoutbreak species=SPECIES_BULBASAUR;);
        break;
    case 5:
        RUN_OVERWORLD_SCRIPT(editoutbreak map=MAP_OLDALE_TOWN;);
        break;
    case 6:
        RUN_OVERWORLD_SCRIPT(editoutbreak daysLeft=0;);
        break;
    }
    EXPECT_EQ(GetMassOutbreakClearedCount(), 0);
}

TEST("Mass outbreak progress survives unrelated battles and edits to the same outbreak")
{
    StartStaticMassOutbreak(OUTBREAK_ID_ROUTE102);
    gSaveBlock1Ptr->outbreakClearedCount = 60;
    gSaveBlock1Ptr->location.mapGroup = MAP_GROUP(MAP_OLDALE_TOWN);
    gSaveBlock1Ptr->location.mapNum = MAP_NUM(MAP_OLDALE_TOWN);
    gChainFishingDexNavStreak = 0;
    gSaveBlock3Ptr->dexNavChain = 0;
    gBattleTypeFlags = 0;
    gBattleOutcome = B_OUTCOME_WON;
    UpdateMassOutbreakProgress();
    EXPECT_EQ(GetMassOutbreakClearedCount(), 60);
    RUN_OVERWORLD_SCRIPT(editoutbreak level=10, probability=100, daysLeft=2;);
    UpdateMassOutbreakDaysLeft(1);
    EXPECT_EQ(GetMassOutbreakClearedCount(), 60);
    gBattleOutcome = 0;
}

TEST("Mass outbreak moves preserve the shininess and personality of an existing overworld Pokémon")
{
    bool32 shiny = FALSE;
    PARAMETRIZE { shiny = FALSE; }
    PARAMETRIZE { shiny = TRUE; }
    struct Pokemon mon;
    StartStaticMassOutbreak(OUTBREAK_ID_ROUTE102);
    CreateMon(&mon, GetStaticOutbreakSpecies(OUTBREAK_ID_ROUTE102), 3, 1234, OTID_STRUCT_PRESET(0));
    SetMonData(&mon, MON_DATA_IS_SHINY, &shiny);
    SetMassOutbreakMonMoves(&mon);
    EXPECT_EQ(IsMonShiny(&mon), shiny);
    EXPECT_EQ(GetMonData(&mon, MON_DATA_PERSONALITY), 1234);
    for (u32 i = 0; i < MAX_MON_MOVES; i++)
        EXPECT_EQ(GetMonData(&mon, MON_DATA_MOVE1 + i), gSaveBlock1Ptr->outbreakPokemonMoves[i]);
}

TEST("startoutbreak sets a static outbreak when called with only one argument")
{
    ASSUME(OUTBREAK_COUNT >= 1);
    ZeroMassOutbreak();

    gSpecialVar_0x8000 = 0;
    RUN_OVERWORLD_SCRIPT(
        setstaticoutbreak VAR_0x8000;
    );

    struct MassOutbreak outbreak = GetStaticOutbreak(0);
    EXPECT_EQ(gSaveBlock1Ptr->outbreakPokemonSpecies, outbreak.species);
    EXPECT_EQ(gSaveBlock1Ptr->outbreakLocationMapNum, MAP_NUM(outbreak.location));
    EXPECT_EQ(gSaveBlock1Ptr->outbreakLocationMapGroup, MAP_GROUP(outbreak.location));
    EXPECT_EQ(gSaveBlock1Ptr->outbreakPokemonLevel, outbreak.level);
    for (u32 i = 0; i < MAX_MON_MOVES; i++)
    {
        EXPECT_EQ(gSaveBlock1Ptr->outbreakPokemonMoves[i], outbreak.moves[i]);
    }
    EXPECT_EQ(gSaveBlock1Ptr->outbreakPokemonProbability, outbreak.probability);
    EXPECT_EQ(gSaveBlock1Ptr->outbreakDaysLeft, outbreak.duration);
}

TEST("startoutbreak can set a dynamic outbreak")
{
    ZeroMassOutbreak();

    RUN_OVERWORLD_SCRIPT(
        startoutbreak species=SPECIES_BULBASAUR, level=2, move1=MOVE_SCRATCH, move2=MOVE_CELEBRATE, move3=MOVE_FLAMETHROWER, move4=MOVE_PSYCHIC, probability=3, daysLeft=4, map=MAP_OLDALE_TOWN;
    );

    EXPECT_EQ(gSaveBlock1Ptr->outbreakPokemonSpecies, SPECIES_BULBASAUR);
    EXPECT_EQ(gSaveBlock1Ptr->outbreakLocationMapNum, MAP_NUM(MAP_OLDALE_TOWN));
    EXPECT_EQ(gSaveBlock1Ptr->outbreakLocationMapGroup, MAP_GROUP(MAP_OLDALE_TOWN));
    EXPECT_EQ(gSaveBlock1Ptr->outbreakPokemonLevel, 2);
    EXPECT_EQ(gSaveBlock1Ptr->outbreakPokemonMoves[0], MOVE_SCRATCH);
    EXPECT_EQ(gSaveBlock1Ptr->outbreakPokemonMoves[1], MOVE_CELEBRATE);
    EXPECT_EQ(gSaveBlock1Ptr->outbreakPokemonMoves[2], MOVE_FLAMETHROWER);
    EXPECT_EQ(gSaveBlock1Ptr->outbreakPokemonMoves[3], MOVE_PSYCHIC);
    EXPECT_EQ(gSaveBlock1Ptr->outbreakPokemonProbability, 3);
    EXPECT_EQ(gSaveBlock1Ptr->outbreakDaysLeft, 4);
}

TEST("startoutbreak can set a dynamic outbreak (vars)")
{
    ZeroMassOutbreak();

    VarSet(VAR_0x8000, SPECIES_BULBASAUR);
    VarSet(VAR_0x8001, 2);
    VarSet(VAR_0x8002, MOVE_SCRATCH);
    VarSet(VAR_0x8003, MOVE_CELEBRATE);
    VarSet(VAR_0x8004, MOVE_FLAMETHROWER);
    VarSet(VAR_0x8005, MOVE_PSYCHIC);
    VarSet(VAR_0x8006, 3);
    VarSet(VAR_0x8007, 4);
    VarSet(VAR_0x8008, MAP_OLDALE_TOWN);
    RUN_OVERWORLD_SCRIPT(
        startoutbreak species=VAR_0x8000, level=VAR_0x8001, move1=VAR_0x8002, move2=VAR_0x8003, move3=VAR_0x8004, move4=VAR_0x8005, probability=VAR_0x8006, daysLeft=VAR_0x8007, map=VAR_0x8008;
    );

    EXPECT_EQ(gSaveBlock1Ptr->outbreakPokemonSpecies, SPECIES_BULBASAUR);
    EXPECT_EQ(gSaveBlock1Ptr->outbreakLocationMapNum, MAP_NUM(MAP_OLDALE_TOWN));
    EXPECT_EQ(gSaveBlock1Ptr->outbreakLocationMapGroup, MAP_GROUP(MAP_OLDALE_TOWN));
    EXPECT_EQ(gSaveBlock1Ptr->outbreakPokemonLevel, 2);
    EXPECT_EQ(gSaveBlock1Ptr->outbreakPokemonMoves[0], MOVE_SCRATCH);
    EXPECT_EQ(gSaveBlock1Ptr->outbreakPokemonMoves[1], MOVE_CELEBRATE);
    EXPECT_EQ(gSaveBlock1Ptr->outbreakPokemonMoves[2], MOVE_FLAMETHROWER);
    EXPECT_EQ(gSaveBlock1Ptr->outbreakPokemonMoves[3], MOVE_PSYCHIC);
    EXPECT_EQ(gSaveBlock1Ptr->outbreakPokemonProbability, 3);
    EXPECT_EQ(gSaveBlock1Ptr->outbreakDaysLeft, 4);
}

TEST("editoutbreak doesn't touch unset arguments")
{
    ZeroMassOutbreak();

    RUN_OVERWORLD_SCRIPT(
        startoutbreak species=SPECIES_BULBASAUR, level=2, move1=MOVE_SCRATCH, move2=MOVE_CELEBRATE, move3=MOVE_FLAMETHROWER, move4=MOVE_PSYCHIC, probability=3, daysLeft=4, map=MAP_OLDALE_TOWN;
        editoutbreak;
    );

    EXPECT_EQ(gSaveBlock1Ptr->outbreakPokemonSpecies, SPECIES_BULBASAUR);
    EXPECT_EQ(gSaveBlock1Ptr->outbreakLocationMapNum, MAP_NUM(MAP_OLDALE_TOWN));
    EXPECT_EQ(gSaveBlock1Ptr->outbreakLocationMapGroup, MAP_GROUP(MAP_OLDALE_TOWN));
    EXPECT_EQ(gSaveBlock1Ptr->outbreakPokemonLevel, 2);
    EXPECT_EQ(gSaveBlock1Ptr->outbreakPokemonMoves[0], MOVE_SCRATCH);
    EXPECT_EQ(gSaveBlock1Ptr->outbreakPokemonMoves[1], MOVE_CELEBRATE);
    EXPECT_EQ(gSaveBlock1Ptr->outbreakPokemonMoves[2], MOVE_FLAMETHROWER);
    EXPECT_EQ(gSaveBlock1Ptr->outbreakPokemonMoves[3], MOVE_PSYCHIC);
    EXPECT_EQ(gSaveBlock1Ptr->outbreakPokemonProbability, 3);
    EXPECT_EQ(gSaveBlock1Ptr->outbreakDaysLeft, 4);
}

TEST("checkhasactiveoutbreak sets the outbreak status to VAR_RESULT")
{
    ZeroMassOutbreak();

    RUN_OVERWORLD_SCRIPT(
        checkhasactiveoutbreak;
    );

    EXPECT_EQ(gSpecialVar_Result, FALSE);

    RUN_OVERWORLD_SCRIPT(
        startoutbreak species=SPECIES_BULBASAUR, level=2, move1=MOVE_SCRATCH, move2=MOVE_CELEBRATE, move3=MOVE_FLAMETHROWER, move4=MOVE_PSYCHIC, probability=3, daysLeft=4, map=MAP_OLDALE_TOWN;
        checkhasactiveoutbreak;
    );
    EXPECT_EQ(gSpecialVar_Result, TRUE);
}

TEST("clearactiveoutbreak disables active outbreak")
{
    ZeroMassOutbreak();

    RUN_OVERWORLD_SCRIPT(
        startoutbreak species=SPECIES_BULBASAUR, level=2, move1=MOVE_SCRATCH, move2=MOVE_CELEBRATE, move3=MOVE_FLAMETHROWER, move4=MOVE_PSYCHIC, probability=3, daysLeft=4, map=MAP_OLDALE_TOWN;
    );

    EXPECT_EQ(IsMassOutbreakActive(), TRUE);

    RUN_OVERWORLD_SCRIPT(
        clearactiveoutbreak;
    );

    EXPECT_EQ(IsMassOutbreakActive(), FALSE);
}

TEST("getmassoutbreakdata")
{
    ZeroMassOutbreak();

    RUN_OVERWORLD_SCRIPT(
        startoutbreak species=SPECIES_BULBASAUR, level=2, move1=MOVE_SCRATCH, move2=MOVE_CELEBRATE, move3=MOVE_FLAMETHROWER, move4=MOVE_PSYCHIC, probability=3, daysLeft=4, map=MAP_OLDALE_TOWN;
        getmassoutbreakdata VAR_0x8000, OUTBREAK_DATA_SPECIES;
        getmassoutbreakdata VAR_0x8001, OUTBREAK_DATA_MOVE1;
        getmassoutbreakdata VAR_0x8002, OUTBREAK_DATA_MOVE2;
        getmassoutbreakdata VAR_0x8003, OUTBREAK_DATA_MOVE3;
        getmassoutbreakdata VAR_0x8004, OUTBREAK_DATA_MOVE4;
        getmassoutbreakdata VAR_0x8005, OUTBREAK_DATA_LEVEL;
        getmassoutbreakdata VAR_0x8006, OUTBREAK_DATA_PROBABILITY;
        getmassoutbreakdata VAR_0x8007, OUTBREAK_DATA_DAYS_LEFT;
        getmassoutbreakdata VAR_0x8008, OUTBREAK_DATA_MAP;
    );

    EXPECT_EQ(gSpecialVar_0x8000, SPECIES_BULBASAUR);
    EXPECT_EQ(gSpecialVar_0x8001, MOVE_SCRATCH);
    EXPECT_EQ(gSpecialVar_0x8002, MOVE_CELEBRATE);
    EXPECT_EQ(gSpecialVar_0x8003, MOVE_FLAMETHROWER);
    EXPECT_EQ(gSpecialVar_0x8004, MOVE_PSYCHIC);
    EXPECT_EQ(gSpecialVar_0x8005, 2);
    EXPECT_EQ(gSpecialVar_0x8006, 3);
    EXPECT_EQ(gSpecialVar_0x8007, 4);
    EXPECT_EQ(gSpecialVar_0x8008, MAP_OLDALE_TOWN);
}
