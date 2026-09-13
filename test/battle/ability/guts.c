#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Guts does not increase Attack without a status condition", s16 damage)
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_NO_GUARD; }
    PARAMETRIZE { ability = ABILITY_GUTS; }
    GIVEN {
        ASSUME(GetMoveCategory(MOVE_SCRATCH) == DAMAGE_CATEGORY_PHYSICAL);
        PLAYER(SPECIES_MACHOP) { Ability(ability); Attack(200); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(1000); MaxHP(1000); Defense(100); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Guts increases Attack by 50% when poisoned, badly poisoned, paralyzed, or burned", s16 damage)
{
    u32 status;
    PARAMETRIZE { status = STATUS1_NONE; }
    PARAMETRIZE { status = STATUS1_POISON; }
    PARAMETRIZE { status = STATUS1_TOXIC_POISON; }
    PARAMETRIZE { status = STATUS1_PARALYSIS; }
    PARAMETRIZE { status = STATUS1_BURN; }
    GIVEN {
        ASSUME(GetMoveCategory(MOVE_SCRATCH) == DAMAGE_CATEGORY_PHYSICAL);
        PLAYER(SPECIES_MACHOP) { Ability(ABILITY_GUTS); Status1(status); Attack(200); Speed(100); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(1000); MaxHP(1000); Defense(100); Speed(10); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH, WITH_RNG(RNG_PARALYSIS, FALSE)); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } THEN {
        EXPECT_EQ(player->status1 & (STATUS1_POISON | STATUS1_TOXIC_POISON | STATUS1_PARALYSIS | STATUS1_BURN), status);
        EXPECT_EQ(player->statStages[STAT_ATK], DEFAULT_STAT_STAGE);
        EXPECT_GT(opponent->hp, 0);
        if (i > 0)
            EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.5), results[i].damage);
    }
}

SINGLE_BATTLE_TEST("Guts boosts physical moves called by Sleep Talk while asleep", s16 damage)
{
    u32 status;
    PARAMETRIZE { status = STATUS1_NONE; }
    PARAMETRIZE { status = STATUS1_SLEEP_TURN(3); }
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_SLEEP_TALK) == EFFECT_SLEEP_TALK);
        ASSUME(!IsMoveSleepTalkBanned(MOVE_SCRATCH));
        ASSUME(GetMoveCategory(MOVE_SCRATCH) == DAMAGE_CATEGORY_PHYSICAL);
        PLAYER(SPECIES_MACHOP) { Ability(ABILITY_GUTS); Status1(status); Attack(200); Moves(MOVE_SLEEP_TALK, MOVE_SCRATCH); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(1000); MaxHP(1000); Defense(100); }
    } WHEN {
        if (status == STATUS1_NONE)
            TURN { MOVE(player, MOVE_SCRATCH); }
        else
            TURN { MOVE(player, MOVE_SLEEP_TALK); }
    } SCENE {
        if (status != STATUS1_NONE)
            ANIMATION(ANIM_TYPE_MOVE, MOVE_SLEEP_TALK, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } THEN {
        if (status != STATUS1_NONE)
            EXPECT(player->status1 & STATUS1_SLEEP);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.5), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Guts does not boost special attacks", s16 damage)
{
    u32 status;
    PARAMETRIZE { status = STATUS1_NONE; }
    PARAMETRIZE { status = STATUS1_POISON; }
    PARAMETRIZE { status = STATUS1_TOXIC_POISON; }
    PARAMETRIZE { status = STATUS1_PARALYSIS; }
    PARAMETRIZE { status = STATUS1_BURN; }
    GIVEN {
        ASSUME(GetMoveCategory(MOVE_SWIFT) == DAMAGE_CATEGORY_SPECIAL);
        PLAYER(SPECIES_MACHOP) { Ability(ABILITY_GUTS); Status1(status); SpAttack(200); Speed(100); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(1000); MaxHP(1000); SpDefense(100); Speed(10); }
    } WHEN {
        TURN { MOVE(player, MOVE_SWIFT, WITH_RNG(RNG_PARALYSIS, FALSE)); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SWIFT, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } THEN {
        if (i > 0)
            EXPECT_EQ(results[0].damage, results[i].damage);
    }
}

SINGLE_BATTLE_TEST("Guts does not activate from confusion alone", s16 damage)
{
    bool32 confused;
    PARAMETRIZE { confused = FALSE; }
    PARAMETRIZE { confused = TRUE; }
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_CONFUSE_RAY) == EFFECT_CONFUSE);
        ASSUME(GetMoveCategory(MOVE_SCRATCH) == DAMAGE_CATEGORY_PHYSICAL);
        PLAYER(SPECIES_MACHOP) { Ability(ABILITY_GUTS); Attack(200); Speed(1); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(1000); MaxHP(1000); Defense(100); Speed(2); }
    } WHEN {
        if (confused)
            TURN { MOVE(opponent, MOVE_CONFUSE_RAY); MOVE(player, MOVE_SCRATCH, WITH_RNG(RNG_CONFUSION, FALSE)); }
        else
            TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        if (confused)
            ANIMATION(ANIM_TYPE_MOVE, MOVE_CONFUSE_RAY, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } THEN {
        EXPECT_EQ(player->status1, STATUS1_NONE);
        EXPECT((player->volatiles.confusionTimer > 0) == confused);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Guts does not prevent residual burn damage")
{
    u32 gen, damage;
    PARAMETRIZE { gen = GEN_6; damage = 20; }
    PARAMETRIZE { gen = GEN_7; damage = 10; }
    GIVEN {
        WITH_CONFIG(B_BURN_DAMAGE, gen);
        PLAYER(SPECIES_MACHOP) { Ability(ABILITY_GUTS); Status1(STATUS1_BURN); HP(160); MaxHP(160); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {}
    } SCENE {
        HP_BAR(player, damage: damage);
    } THEN {
        EXPECT_EQ(player->hp, 160 - damage);
        EXPECT(player->status1 & STATUS1_BURN);
    }
}

SINGLE_BATTLE_TEST("Guts does not prevent paralysis from reducing Speed")
{
    u32 status;
    PARAMETRIZE { status = STATUS1_NONE; }
    PARAMETRIZE { status = STATUS1_PARALYSIS; }
    GIVEN {
        WITH_CONFIG(B_PARALYSIS_SPEED, GEN_7);
        PLAYER(SPECIES_MACHOP) { Ability(ABILITY_GUTS); Status1(status); Speed(100); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(75); }
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE, WITH_RNG(RNG_PARALYSIS, FALSE)); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        if (status == STATUS1_NONE)
        {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        }
        else
        {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        }
    }
}

SINGLE_BATTLE_TEST("Guts does not prevent full paralysis")
{
    GIVEN {
        PLAYER(SPECIES_MACHOP) { Ability(ABILITY_GUTS); Status1(STATUS1_PARALYSIS); Speed(100); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(1000); MaxHP(1000); Speed(10); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH, WITH_RNG(RNG_PARALYSIS, TRUE)); }
    } SCENE {
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
            HP_BAR(opponent);
        }
    } THEN {
        EXPECT_EQ(opponent->hp, 1000);
        EXPECT(player->status1 & STATUS1_PARALYSIS);
    }
}

SINGLE_BATTLE_TEST("Guts starts boosting after Flame Orb or Toxic Orb inflicts status")
{
    enum Item item;
    u32 status;
    s16 damage[2];
    PARAMETRIZE { item = ITEM_FLAME_ORB; status = STATUS1_BURN; }
    PARAMETRIZE { item = ITEM_TOXIC_ORB; status = STATUS1_TOXIC_POISON; }
    GIVEN {
        ASSUME(GetMoveCategory(MOVE_SCRATCH) == DAMAGE_CATEGORY_PHYSICAL);
        ASSUME(GetItemHoldEffect(ITEM_FLAME_ORB) == HOLD_EFFECT_FLAME_ORB);
        ASSUME(GetItemHoldEffect(ITEM_TOXIC_ORB) == HOLD_EFFECT_TOXIC_ORB);
        PLAYER(SPECIES_MACHOP) { Ability(ABILITY_GUTS); Item(item); Attack(200); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(1000); MaxHP(1000); Defense(100); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        HP_BAR(opponent, captureDamage: &damage[0]);
        STATUS_ICON(player, status);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        HP_BAR(opponent, captureDamage: &damage[1]);
    } THEN {
        EXPECT(player->status1 & status);
        EXPECT_GT(opponent->hp, 0);
        EXPECT_MUL_EQ(damage[0], Q_4_12(1.5), damage[1]);
    }
}

SINGLE_BATTLE_TEST("Guts stops boosting after its status condition is cured")
{
    u32 status;
    s16 damage[2];
    PARAMETRIZE { status = STATUS1_POISON; }
    PARAMETRIZE { status = STATUS1_BURN; }
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_HEAL_BELL) == EFFECT_HEAL_BELL);
        ASSUME(GetMoveCategory(MOVE_SCRATCH) == DAMAGE_CATEGORY_PHYSICAL);
        PLAYER(SPECIES_MACHOP) { Ability(ABILITY_GUTS); Status1(status); Attack(200); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(1000); MaxHP(1000); Defense(100); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
        TURN { MOVE(player, MOVE_HEAL_BELL); }
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        HP_BAR(opponent, captureDamage: &damage[0]);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HEAL_BELL, player);
        STATUS_ICON(player, none: TRUE);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        HP_BAR(opponent, captureDamage: &damage[1]);
    } THEN {
        EXPECT_EQ(player->status1, STATUS1_NONE);
        EXPECT_GT(opponent->hp, 0);
        EXPECT_MUL_EQ(damage[1], Q_4_12(1.5), damage[0]);
    }
}

SINGLE_BATTLE_TEST("Guts loses its Attack boost and burn protection under Gastro Acid")
{
    u32 status;
    s16 damage[2];
    PARAMETRIZE { status = STATUS1_POISON; }
    PARAMETRIZE { status = STATUS1_BURN; }
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_GASTRO_ACID) == EFFECT_GASTRO_ACID);
        ASSUME(GetMoveCategory(MOVE_SCRATCH) == DAMAGE_CATEGORY_PHYSICAL);
        PLAYER(SPECIES_MACHOP) { Ability(ABILITY_GUTS); Status1(status); Attack(200); Speed(1); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(1000); MaxHP(1000); Defense(100); Speed(2); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
        TURN { MOVE(opponent, MOVE_GASTRO_ACID); MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        HP_BAR(opponent, captureDamage: &damage[0]);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GASTRO_ACID, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        HP_BAR(opponent, captureDamage: &damage[1]);
    } THEN {
        EXPECT(player->volatiles.gastroAcid);
        EXPECT(player->status1 & status);
        EXPECT_GT(opponent->hp, 0);
        if (status == STATUS1_BURN)
            EXPECT_MUL_EQ(damage[1], Q_4_12(3.0), damage[0]);
        else
            EXPECT_MUL_EQ(damage[1], Q_4_12(1.5), damage[0]);
    }
}

SINGLE_BATTLE_TEST("Guts stacks with Choice Band", s16 damage)
{
    enum Item item;
    u32 status, attack;
    PARAMETRIZE { item = ITEM_NONE; status = STATUS1_NONE; attack = 450; }
    PARAMETRIZE { item = ITEM_CHOICE_BAND; status = STATUS1_POISON; attack = 200; }
    GIVEN {
        ASSUME(GetItemHoldEffect(ITEM_CHOICE_BAND) == HOLD_EFFECT_CHOICE_BAND);
        ASSUME(GetMoveCategory(MOVE_SCRATCH) == DAMAGE_CATEGORY_PHYSICAL);
        PLAYER(SPECIES_MACHOP) { Ability(ABILITY_GUTS); Item(item); Status1(status); Attack(attack); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(1000); MaxHP(1000); Defense(100); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Guts stacks with Attack stat stages", s16 damage)
{
    bool32 boostAttack;
    u32 attack;
    PARAMETRIZE { boostAttack = FALSE; attack = 400; }
    PARAMETRIZE { boostAttack = TRUE; attack = 200; }
    GIVEN {
        ASSUME_STAT_CHANGE(MOVE_SWORDS_DANCE, attack: +2);
        ASSUME(GetMoveCategory(MOVE_SCRATCH) == DAMAGE_CATEGORY_PHYSICAL);
        PLAYER(SPECIES_MACHOP) { Ability(ABILITY_GUTS); Status1(STATUS1_POISON); Attack(attack); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(1000); MaxHP(1000); Defense(100); }
    } WHEN {
        if (boostAttack)
            TURN { MOVE(player, MOVE_SWORDS_DANCE); }
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        if (boostAttack)
            ANIMATION(ANIM_TYPE_MOVE, MOVE_SWORDS_DANCE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } THEN {
        EXPECT_EQ(player->statStages[STAT_ATK], DEFAULT_STAT_STAGE + (boostAttack ? 2 : 0));
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Guts stacks with Facade and ignores burn before and after Gen 6", s16 damage)
{
    u32 status, gen;
    PARAMETRIZE { gen = GEN_5; status = STATUS1_NONE; }
    PARAMETRIZE { gen = GEN_5; status = STATUS1_BURN; }
    PARAMETRIZE { gen = GEN_6; status = STATUS1_NONE; }
    PARAMETRIZE { gen = GEN_6; status = STATUS1_BURN; }
    GIVEN {
        WITH_CONFIG(B_BURN_FACADE_DMG, gen);
        ASSUME(GetMoveEffect(MOVE_FACADE) == EFFECT_FACADE);
        ASSUME(GetMoveCategory(MOVE_FACADE) == DAMAGE_CATEGORY_PHYSICAL);
        PLAYER(SPECIES_MACHOP) { Ability(ABILITY_GUTS); Status1(status); Attack(200); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(1000); MaxHP(1000); Defense(100); }
    } WHEN {
        TURN { MOVE(player, MOVE_FACADE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FACADE, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(3.0), results[1].damage);
        EXPECT_EQ(results[0].damage, results[2].damage);
        EXPECT_EQ(results[1].damage, results[3].damage);
    }
}

SINGLE_BATTLE_TEST("Guts boosts Foul Play using the user's status condition", s16 damage)
{
    u32 status;
    PARAMETRIZE { status = STATUS1_NONE; }
    PARAMETRIZE { status = STATUS1_POISON; }
    PARAMETRIZE { status = STATUS1_BURN; }
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_FOUL_PLAY) == EFFECT_FOUL_PLAY);
        ASSUME(GetMoveCategory(MOVE_FOUL_PLAY) == DAMAGE_CATEGORY_PHYSICAL);
        PLAYER(SPECIES_MACHOP) { Ability(ABILITY_GUTS); Status1(status); Attack(50); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(1000); MaxHP(1000); Attack(200); Defense(100); }
    } WHEN {
        TURN { MOVE(player, MOVE_FOUL_PLAY); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FOUL_PLAY, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } THEN {
        EXPECT_GT(opponent->hp, 0);
        if (i > 0)
            EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.5), results[i].damage);
    }
}

SINGLE_BATTLE_TEST("Guts does not boost an opponent's Foul Play using the target's status", s16 damage)
{
    u32 status;
    PARAMETRIZE { status = STATUS1_NONE; }
    PARAMETRIZE { status = STATUS1_POISON; }
    PARAMETRIZE { status = STATUS1_BURN; }
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_FOUL_PLAY) == EFFECT_FOUL_PLAY);
        ASSUME(GetMoveCategory(MOVE_FOUL_PLAY) == DAMAGE_CATEGORY_PHYSICAL);
        PLAYER(SPECIES_MACHOP) { Ability(ABILITY_GUTS); Status1(status); HP(1000); MaxHP(1000); Attack(200); Defense(100); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_FOUL_PLAY); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FOUL_PLAY, opponent);
        HP_BAR(player, captureDamage: &results[i].damage);
    } THEN {
        if (i > 0)
            EXPECT_EQ(results[0].damage, results[i].damage);
    }
}

SINGLE_BATTLE_TEST("Guts does not change Seismic Toss's fixed damage")
{
    u32 status;
    PARAMETRIZE { status = STATUS1_NONE; }
    PARAMETRIZE { status = STATUS1_POISON; }
    PARAMETRIZE { status = STATUS1_BURN; }
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_SEISMIC_TOSS) == EFFECT_LEVEL_DAMAGE);
        PLAYER(SPECIES_MACHOP) { Ability(ABILITY_GUTS); Status1(status); Level(50); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(1000); MaxHP(1000); }
    } WHEN {
        TURN { MOVE(player, MOVE_SEISMIC_TOSS); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SEISMIC_TOSS, player);
        HP_BAR(opponent, damage: 50);
    } THEN {
        EXPECT_EQ(opponent->hp, 950);
    }
}
