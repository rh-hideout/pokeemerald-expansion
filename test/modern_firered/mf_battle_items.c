#include "global.h"
#include "test/test.h"
#include "test/battle.h"
#include "item.h"
#include "mf_items.h"
#include "mf_rules.h"

static struct ModernRules *PrepareRules(void)
{
    struct ModernRules *save = MfRules_GetSaveRules();

    MfRules_ApplyDevDefaults(save);
    save->rulesLocked = TRUE;
    save->noItemPlayer = FALSE;
    save->noItemTrainer = FALSE;
    return save;
}

TEST("MF: player battle item ban allows balls only")
{
    struct ModernRules *save = PrepareRules();

    EXPECT(MfIsBattlePokeBall(ITEM_POKE_BALL));
    EXPECT(MfIsBattlePokeBall(ITEM_ULTRA_BALL));
    EXPECT(!MfIsBattlePokeBall(ITEM_POTION));
    EXPECT(!MfIsBattlePokeBall(ITEM_X_ATTACK));
    EXPECT(!MfIsBattlePokeBall(ITEM_NONE));

    EXPECT(MfIsPlayerBattleItemAllowed(ITEM_POTION));
    EXPECT(MfIsPlayerBattleItemAllowed(ITEM_POKE_BALL));
    EXPECT(MfAreTrainerBattleItemsAllowed());
    EXPECT(MfIsBattlerBattleItemAllowed(TRUE, ITEM_POTION));
    EXPECT(MfIsBattlerBattleItemAllowed(FALSE, ITEM_POTION));

    save->noItemPlayer = TRUE;
    EXPECT(!MfIsPlayerBattleItemAllowed(ITEM_POTION));
    EXPECT(!MfIsPlayerBattleItemAllowed(ITEM_SUPER_POTION));
    EXPECT(!MfIsPlayerBattleItemAllowed(ITEM_X_ATTACK));
    EXPECT(!MfIsPlayerBattleItemAllowed(ITEM_REVIVE));
    EXPECT(MfIsPlayerBattleItemAllowed(ITEM_POKE_BALL));
    EXPECT(MfIsPlayerBattleItemAllowed(ITEM_GREAT_BALL));
    EXPECT(!MfIsBattlerBattleItemAllowed(TRUE, ITEM_POTION));
    EXPECT(MfIsBattlerBattleItemAllowed(TRUE, ITEM_POKE_BALL));
    EXPECT(MfIsBattlerBattleItemAllowed(FALSE, ITEM_POTION));

    save->noItemTrainer = TRUE;
    EXPECT(!MfAreTrainerBattleItemsAllowed());
    EXPECT(!MfIsBattlerBattleItemAllowed(FALSE, ITEM_POTION));
    EXPECT(MfIsPlayerBattleItemAllowed(ITEM_POKE_BALL));

    save->noItemPlayer = FALSE;
    save->noItemTrainer = FALSE;
}

SINGLE_BATTLE_TEST("MF: player item ban skips potions and still throws balls")
{
    u16 hp = 0;

    GIVEN {
        PrepareRules()->noItemPlayer = TRUE;
        ASSUME(gItemsInfo[ITEM_POTION].battleUsage == EFFECT_ITEM_RESTORE_HP);
        ASSUME(gItemsInfo[ITEM_POKE_BALL].battleUsage == EFFECT_ITEM_THROW_BALL);
        PLAYER(SPECIES_WOBBUFFET) { HP(1); MaxHP(400); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(1); MaxHP(400); }
    } WHEN {
        TURN { USE_ITEM(player, ITEM_POTION, partyIndex: 0); }
    } SCENE {
        NOT HP_BAR(player);
    } THEN {
        hp = GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_HP);
        EXPECT_EQ(hp, 1u);
        PrepareRules();
    }
}

WILD_BATTLE_TEST("MF: player item ban still allows Poké Balls")
{
    u32 recordedOdds = 0;

    GIVEN {
        PrepareRules()->noItemPlayer = TRUE;
        ASSUME(gItemsInfo[ITEM_POKE_BALL].battleUsage == EFFECT_ITEM_THROW_BALL);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_CATERPIE);
    } WHEN {
        TURN { USE_ITEM(player, ITEM_POKE_BALL); }
    } SCENE {
        CATCHING_CHANCE(&recordedOdds);
    } THEN {
        PrepareRules();
    }
}

SINGLE_BATTLE_TEST("MF: trainer item ban skips opponent potions")
{
    u16 hp = 0;

    GIVEN {
        PrepareRules()->noItemTrainer = TRUE;
        ASSUME(gItemsInfo[ITEM_POTION].battleUsage == EFFECT_ITEM_RESTORE_HP);
        PLAYER(SPECIES_WOBBUFFET) { HP(1); MaxHP(400); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(1); MaxHP(400); }
    } WHEN {
        TURN { USE_ITEM(opponent, ITEM_POTION, partyIndex: 0); }
    } SCENE {
        NOT HP_BAR(opponent);
    } THEN {
        hp = GetMonData(&gParties[B_TRAINER_OPPONENT_A][0], MON_DATA_HP);
        EXPECT_EQ(hp, 1u);
        PrepareRules();
    }
}
