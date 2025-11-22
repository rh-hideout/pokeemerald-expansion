#ifndef GUARD_MOVES_H
#define GUARD_MOVES_H

#include "contest_effect.h"
#include "constants/battle.h"
#include "constants/battle_move_effects.h"
#include "constants/battle_string_ids.h"
#include "constants/moves.h"

// For defining EFFECT_HIT etc. with battle TV scores and flags etc.
struct __attribute__((packed, aligned(2))) BattleMoveEffect
{
    const u8 *battleScript;
    u16 battleTvScore:3;
    u16 encourageEncore:1;
    u16 twoTurnEffect:1;
    u16 semiInvulnerableEffect:1;
    u16 usesProtectCounter:1;
    u16 padding:9;
};

#define EFFECTS_ARR(...) (const struct AdditionalEffect[]) {__VA_ARGS__}
#define ADDITIONAL_EFFECTS(...) EFFECTS_ARR( __VA_ARGS__ ), .numAdditionalEffects = ARRAY_COUNT(EFFECTS_ARR( __VA_ARGS__ ))

struct AdditionalEffect
{
    enum MoveEffect moveEffect;
    u8 self:1;
    u8 onlyIfTargetRaisedStats:1;
    u8 onChargeTurnOnly:1;
    u8 sheerForceOverride:1; // Handles edge cases for Sheer Force - if TRUE, boosts when it shouldn't, or doesn't boost when it should
    u8 padding:4;
    union PACKED {
        enum WrappedStringID wrapped;
    } multistring;
    u8 chance; // 0% = effect certain, primary effect
};

enum ProtectType
{
    PROTECT_TYPE_NONE,
    PROTECT_TYPE_SIDE,
    PROTECT_TYPE_SINGLE,
};

enum ProtectMethod
{
    PROTECT_NONE,
    PROTECT_NORMAL,
    PROTECT_SPIKY_SHIELD,
    PROTECT_KINGS_SHIELD,
    PROTECT_BANEFUL_BUNKER,
    PROTECT_BURNING_BULWARK,
    PROTECT_OBSTRUCT,
    PROTECT_SILK_TRAP,
    PROTECT_MAX_GUARD,
    PROTECT_WIDE_GUARD,
    PROTECT_QUICK_GUARD,
    PROTECT_CRAFTY_SHIELD,
    PROTECT_MAT_BLOCK,
};

#define USE_FUNC(name) __attribute__((deprecated("use " name " instead")))

struct MoveInfo
{
    const u8 *name USE_FUNC("GetMoveName");
    const u8 *description USE_FUNC("GetMoveDescription");
    enum BattleMoveEffects effect USE_FUNC("GetMoveEffect");
    enum Type type:5 USE_FUNC("GetMoveType"); // Up to 32
    enum DamageCategory category:2 USE_FUNC("GetMoveCategory");
    u16 power:9 USE_FUNC("GetMovePower"); // up to 511
    // end of word
    u16 accuracy:7 USE_FUNC("GetMoveAccuracy");
    u16 target:9 USE_FUNC("GetMoveTarget");
    u8 pp USE_FUNC("GetMovePP");
    union {
        u8 effect USE_FUNC("GetMoveZEffect");
        u8 powerOverride USE_FUNC("GetMoveZPowerOverride");
    } zMove;
    // end of word
    s32 priority:4 USE_FUNC("GetMovePriority");
    u32 strikeCount:4 USE_FUNC("GetMoveStrikeCount"); // Max 15 hits. Defaults to 1 if not set. May apply its effect on each hit.
    u32 criticalHitStage:2 USE_FUNC("GetMoveCriticalHitStage");
    bool32 alwaysCriticalHit:1 USE_FUNC("MoveAlwaysCrits");
    u32 numAdditionalEffects:3 USE_FUNC("GetMoveAdditionalEffectCount"); // limited to 7
    // Flags
    bool32 makesContact:1 USE_FUNC("MoveMakesContact");
    bool32 ignoresProtect:1 USE_FUNC("MoveIgnoresProtect");
    bool32 magicCoatAffected:1 USE_FUNC("MoveCanBeBouncedBack");
    bool32 snatchAffected:1 USE_FUNC("MoveCanBeSnatched");
    bool32 ignoresKingsRock:1 USE_FUNC("MoveIgnoresKingsRock");
    bool32 punchingMove:1 USE_FUNC("IsPunchingMove");
    bool32 bitingMove:1 USE_FUNC("IsBitingMove");
    bool32 pulseMove:1 USE_FUNC("IsPulseMove");
    bool32 soundMove:1 USE_FUNC("IsSoundMove");
    bool32 ballisticMove:1 USE_FUNC("IsBallisticMove");
    bool32 powderMove:1 USE_FUNC("IsPowderMove");
    bool32 danceMove:1 USE_FUNC("IsDanceMove");
    bool32 windMove:1 USE_FUNC("IsWindMove");
    bool32 slicingMove:1 USE_FUNC("IsSlicingMove");
    bool32 healingMove:1 USE_FUNC("IsHealingMove");
    bool32 minimizeDoubleDamage:1 USE_FUNC("MoveIncreasesPowerToMinimizedTargets");
    bool32 ignoresTargetAbility:1 USE_FUNC("MoveIgnoresTargetAbility");
    bool32 ignoresTargetDefenseEvasionStages:1 USE_FUNC("MoveIgnoresDefenseEvasionStages");
    // end of word
    bool32 damagesUnderground:1 USE_FUNC("MoveDamagesUnderground");
    bool32 damagesUnderwater:1 USE_FUNC("MoveDamagesUnderWater");
    bool32 damagesAirborne:1 USE_FUNC("MoveDamagesAirborne");
    bool32 damagesAirborneDoubleDamage:1 USE_FUNC("MoveDamagesAirborneDoubleDamage");
    bool32 ignoreTypeIfFlyingAndUngrounded:1 USE_FUNC("MoveIgnoresTypeIfFlyingAndUngrounded");
    bool32 thawsUser:1 USE_FUNC("MoveThawsUser");
    bool32 ignoresSubstitute:1 USE_FUNC("MoveIgnoresSubstitute");
    bool32 forcePressure:1 USE_FUNC("MoveForcesPressure");
    bool32 cantUseTwice:1 USE_FUNC("MoveCantBeUsedTwice");
    bool32 alwaysHitsInRain:1 USE_FUNC("MoveAlwaysHitsInRain");
    bool32 accuracy50InSun:1 USE_FUNC("MoveHas50AccuracyInSun");
    bool32 alwaysHitsInHailSnow:1 USE_FUNC("MoveAlwaysHitsInHailSnow");
    // Ban flags
    bool32 gravityBanned:1 USE_FUNC("IsMoveGravityBanned");
    bool32 mirrorMoveBanned:1 USE_FUNC("IsMoveMirrorMoveBanned");
    bool32 meFirstBanned:1 USE_FUNC("IsMoveMeFirstBanned");
    bool32 mimicBanned:1 USE_FUNC("IsMoveMimicBanned");
    bool32 metronomeBanned:1 USE_FUNC("IsMoveMetronomeBanned");
    bool32 copycatBanned:1 USE_FUNC("IsMoveCopycatBanned");
    bool32 assistBanned:1 USE_FUNC("IsMoveAssistBanned"); // Matches same moves as copycatBanned + semi-invulnerable moves and Mirror Coat.
    bool32 sleepTalkBanned:1 USE_FUNC("IsMoveSleepTalkBanned");
    bool32 instructBanned:1 USE_FUNC("IsMoveInstructBanned");
    bool32 encoreBanned:1 USE_FUNC("IsMoveEncoreBanned");
    bool32 parentalBondBanned:1 USE_FUNC("IsMoveParentalBondBanned");
    bool32 skyBattleBanned:1 USE_FUNC("IsMoveSkyBattleBanned");
    bool32 sketchBanned:1 USE_FUNC("IsMoveSketchBanned");
    bool32 dampBanned:1 USE_FUNC("IsMoveDampBanned");
    //Other
    bool32 validApprenticeMove:1 USE_FUNC("IsValidApprenticeMove");
    u32 padding:5;
    // end of word

    union {
        struct {
            u16 stringId USE_FUNC("GetMoveTwoTurnAttackStringId");
            u16 status USE_FUNC("GetMoveTwoTurnAttackStatus or GetMoveTwoTurnAttackWeather");
        } twoTurnAttack;
        u32 protectMethod USE_FUNC("GetMoveProtectMethod");
        u32 status USE_FUNC("GetMoveEffectArg_Status");
        u32 moveProperty USE_FUNC("GetMoveEffectArg_MoveProperty");
        u32 holdEffect USE_FUNC("GetMoveEffectArg_HoldEffect");
        u32 type USE_FUNC("GetMoveArgType");
        u32 fixedDamage USE_FUNC("GetMoveFixedHPDamage");
        u32 damagePercentage USE_FUNC("GetMoveDamagePercentage");
        u32 absorbPercentage USE_FUNC("GetMoveAbsorbPercentage");
        u32 recoilPercentage USE_FUNC("GetMoveRecoil");
        u32 nonVolatileStatus USE_FUNC("GetMoveNonVolatileStatus");
        u32 overwriteAbility USE_FUNC("GetMoveOverwriteAbility");
    } argument;

    // primary/secondary effects
    const struct AdditionalEffect *additionalEffects USE_FUNC("GetMoveAdditionalEffectById");

    // contest parameters
    u8 contestEffect USE_FUNC("GetMoveContestEffect");
    u8 contestCategory:3 USE_FUNC("GetMoveContestCategory");
    u8 contestComboStarterId USE_FUNC("GetMoveContestComboStarter");
    u8 contestComboMoves[MAX_COMBO_MOVES] USE_FUNC("GetMoveContestComboMoves");
    const u8 *battleAnimScript USE_FUNC("GetMoveAnimationScript");
};

#undef USE_FUNC

extern const struct MoveInfo gMovesInfo[MOVES_COUNT_ALL];
extern const u8 gNotDoneYetDescription[];
extern const struct BattleMoveEffect gBattleMoveEffects[];

static inline u32 SanitizeMoveId(u32 move)
{
    if (move >= MOVES_COUNT_ALL)
        return MOVE_NONE;
    else
        return move;
}

static inline const u8 *GetMoveName(u32 move)
{
    return GET_DEPRECATED(const u8 *, gMovesInfo[SanitizeMoveId(move)].name);
}

static inline enum BattleMoveEffects GetMoveEffect(u32 move)
{
    return GET_DEPRECATED(u32, gMovesInfo[SanitizeMoveId(move)].effect);
}

static inline const u8 *GetMoveDescription(u32 move)
{
    move = SanitizeMoveId(move);
    if (GetMoveEffect(move) == EFFECT_PLACEHOLDER)
        return gNotDoneYetDescription;
    return GET_DEPRECATED(const u8 *, gMovesInfo[move].description);
}

static inline enum Type GetMoveType(u32 move)
{
    return GET_DEPRECATED(u32, gMovesInfo[SanitizeMoveId(move)].type);
}

static inline enum DamageCategory GetMoveCategory(u32 move)
{
    return GET_DEPRECATED(u32, gMovesInfo[SanitizeMoveId(move)].category);
}

static inline u32 GetMovePower(u32 move)
{
    return GET_DEPRECATED(u32, gMovesInfo[SanitizeMoveId(move)].power);
}

static inline u32 GetMoveAccuracy(u32 move)
{
    return GET_DEPRECATED(u32, gMovesInfo[SanitizeMoveId(move)].accuracy);
}

static inline u32 GetMoveTarget(u32 move)
{
    return GET_DEPRECATED(u32, gMovesInfo[SanitizeMoveId(move)].target);
}

static inline u32 GetMovePP(u32 move)
{
    return GET_DEPRECATED(u32, gMovesInfo[SanitizeMoveId(move)].pp);
}

static inline u32 GetMoveZEffect(u32 move)
{
    return GET_DEPRECATED(u32, gMovesInfo[SanitizeMoveId(move)].zMove.effect);
}

static inline u32 GetMoveZPowerOverride(u32 move)
{
    return GET_DEPRECATED(u32, gMovesInfo[SanitizeMoveId(move)].zMove.powerOverride);
}

static inline s32 GetMovePriority(u32 move)
{
    return GET_DEPRECATED(s32, gMovesInfo[SanitizeMoveId(move)].priority);
}

static inline u32 GetMoveStrikeCount(u32 move)
{
    return GET_DEPRECATED(u32, gMovesInfo[SanitizeMoveId(move)].strikeCount);
}

static inline u32 GetMoveCriticalHitStage(u32 move)
{
    return GET_DEPRECATED(u32, gMovesInfo[SanitizeMoveId(move)].criticalHitStage);
}

static inline bool32 MoveAlwaysCrits(u32 move)
{
    return GET_DEPRECATED(bool32, gMovesInfo[SanitizeMoveId(move)].alwaysCriticalHit);
}

static inline u32 GetMoveAdditionalEffectCount(u32 move)
{
    return GET_DEPRECATED(u32, gMovesInfo[SanitizeMoveId(move)].numAdditionalEffects);
}

static inline bool32 MoveMakesContact(u32 move)
{
    return GET_DEPRECATED(u32, gMovesInfo[SanitizeMoveId(move)].makesContact);
}

static inline bool32 MoveIgnoresProtect(u32 move)
{
    return GET_DEPRECATED(bool32, gMovesInfo[SanitizeMoveId(move)].ignoresProtect);
}

static inline bool32 MoveCanBeBouncedBack(u32 move)
{
    return GET_DEPRECATED(bool32, gMovesInfo[SanitizeMoveId(move)].magicCoatAffected);
}

static inline bool32 MoveCanBeSnatched(u32 move)
{
    return GET_DEPRECATED(bool32, gMovesInfo[SanitizeMoveId(move)].snatchAffected);
}

static inline bool32 MoveIgnoresKingsRock(u32 move)
{
    return GET_DEPRECATED(bool32, gMovesInfo[SanitizeMoveId(move)].ignoresKingsRock);
}

static inline bool32 IsPunchingMove(u32 move)
{
    return GET_DEPRECATED(bool32, gMovesInfo[SanitizeMoveId(move)].punchingMove);
}

static inline bool32 IsBitingMove(u32 move)
{
    return GET_DEPRECATED(bool32, gMovesInfo[SanitizeMoveId(move)].bitingMove);
}

static inline bool32 IsPulseMove(u32 move)
{
    return GET_DEPRECATED(bool32, gMovesInfo[SanitizeMoveId(move)].pulseMove);
}

static inline bool32 IsSoundMove(u32 move)
{
    return GET_DEPRECATED(bool32, gMovesInfo[SanitizeMoveId(move)].soundMove);
}

static inline bool32 IsBallisticMove(u32 move)
{
    return GET_DEPRECATED(bool32, gMovesInfo[SanitizeMoveId(move)].ballisticMove);
}

static inline bool32 IsPowderMove(u32 move)
{
    return GET_DEPRECATED(bool32, gMovesInfo[SanitizeMoveId(move)].powderMove);
}

static inline bool32 IsDanceMove(u32 move)
{
    return GET_DEPRECATED(bool32, gMovesInfo[SanitizeMoveId(move)].danceMove);
}

static inline bool32 IsWindMove(u32 move)
{
    return GET_DEPRECATED(bool32, gMovesInfo[SanitizeMoveId(move)].windMove);
}

static inline bool32 IsSlicingMove(u32 move)
{
    return GET_DEPRECATED(bool32, gMovesInfo[SanitizeMoveId(move)].slicingMove);
}

static inline bool32 IsHealingMove(u32 move)
{
    return GET_DEPRECATED(bool32, gMovesInfo[SanitizeMoveId(move)].healingMove);
}

static inline bool32 MoveIncreasesPowerToMinimizedTargets(u32 move)
{
    return GET_DEPRECATED(bool32, gMovesInfo[SanitizeMoveId(move)].minimizeDoubleDamage);
}

static inline bool32 MoveIgnoresTargetAbility(u32 move)
{
    return GET_DEPRECATED(bool32, gMovesInfo[SanitizeMoveId(move)].ignoresTargetAbility);
}

static inline bool32 MoveIgnoresDefenseEvasionStages(u32 move)
{
    return GET_DEPRECATED(bool32, gMovesInfo[SanitizeMoveId(move)].ignoresTargetDefenseEvasionStages);
}

static inline bool32 MoveDamagesUnderground(u32 move)
{
    return GET_DEPRECATED(bool32, gMovesInfo[SanitizeMoveId(move)].damagesUnderground);
}

static inline bool32 MoveDamagesUnderWater(u32 move)
{
    return GET_DEPRECATED(bool32, gMovesInfo[SanitizeMoveId(move)].damagesUnderwater);
}

static inline bool32 MoveDamagesAirborne(u32 move)
{
    return GET_DEPRECATED(bool32, gMovesInfo[SanitizeMoveId(move)].damagesAirborne);
}

static inline bool32 MoveDamagesAirborneDoubleDamage(u32 move)
{
    return GET_DEPRECATED(bool32, gMovesInfo[SanitizeMoveId(move)].damagesAirborneDoubleDamage);
}

static inline bool32 MoveIgnoresTypeIfFlyingAndUngrounded(u32 move)
{
    return GET_DEPRECATED(bool32, gMovesInfo[SanitizeMoveId(move)].ignoreTypeIfFlyingAndUngrounded);
}

static inline bool32 MoveThawsUser(u32 move)
{
    return GET_DEPRECATED(bool32, gMovesInfo[SanitizeMoveId(move)].thawsUser);
}

static inline bool32 MoveIgnoresSubstitute(u32 move)
{
    return GET_DEPRECATED(bool32, gMovesInfo[SanitizeMoveId(move)].ignoresSubstitute);
}

static inline bool32 MoveForcesPressure(u32 move)
{
    return GET_DEPRECATED(bool32, gMovesInfo[SanitizeMoveId(move)].forcePressure);
}

static inline bool32 MoveCantBeUsedTwice(u32 move)
{
    return GET_DEPRECATED(bool32, gMovesInfo[SanitizeMoveId(move)].cantUseTwice);
}

static inline bool32 MoveAlwaysHitsInRain(u32 move)
{
    return GET_DEPRECATED(bool32, gMovesInfo[SanitizeMoveId(move)].alwaysHitsInRain);
}

static inline bool32 MoveHas50AccuracyInSun(u32 move)
{
    return GET_DEPRECATED(bool32, gMovesInfo[SanitizeMoveId(move)].accuracy50InSun);
}

static inline bool32 MoveAlwaysHitsInHailSnow(u32 move)
{
    return GET_DEPRECATED(bool32, gMovesInfo[SanitizeMoveId(move)].alwaysHitsInHailSnow);
}

static inline bool32 IsMoveGravityBanned(u32 move)
{
    return GET_DEPRECATED(bool32, gMovesInfo[SanitizeMoveId(move)].gravityBanned);
}

static inline bool32 IsMoveMirrorMoveBanned(u32 move)
{
    return GET_DEPRECATED(bool32, gMovesInfo[SanitizeMoveId(move)].mirrorMoveBanned);
}

static inline bool32 IsMoveMeFirstBanned(u32 move)
{
    return GET_DEPRECATED(bool32, gMovesInfo[SanitizeMoveId(move)].meFirstBanned);
}

static inline bool32 IsMoveMimicBanned(u32 move)
{
    return GET_DEPRECATED(bool32, gMovesInfo[SanitizeMoveId(move)].mimicBanned);
}

static inline bool32 IsMoveMetronomeBanned(u32 move)
{
    return GET_DEPRECATED(bool32, gMovesInfo[SanitizeMoveId(move)].metronomeBanned);
}

static inline bool32 IsMoveCopycatBanned(u32 move)
{
    return GET_DEPRECATED(bool32, gMovesInfo[SanitizeMoveId(move)].copycatBanned);
}

static inline bool32 IsMoveAssistBanned(u32 move)
{
    return GET_DEPRECATED(bool32, gMovesInfo[SanitizeMoveId(move)].assistBanned);
}

static inline bool32 IsMoveSleepTalkBanned(u32 move)
{
    return GET_DEPRECATED(bool32, gMovesInfo[SanitizeMoveId(move)].sleepTalkBanned);
}

static inline bool32 IsMoveInstructBanned(u32 move)
{
    return GET_DEPRECATED(bool32, gMovesInfo[SanitizeMoveId(move)].instructBanned);
}

static inline bool32 IsMoveEncoreBanned(u32 move)
{
    return GET_DEPRECATED(bool32, gMovesInfo[SanitizeMoveId(move)].encoreBanned);
}

static inline bool32 IsMoveParentalBondBanned(u32 move)
{
    return GET_DEPRECATED(bool32, gMovesInfo[SanitizeMoveId(move)].parentalBondBanned);
}

static inline bool32 IsMoveSkyBattleBanned(u32 move)
{
    return GET_DEPRECATED(bool32, gMovesInfo[SanitizeMoveId(move)].skyBattleBanned);
}

static inline bool32 IsMoveSketchBanned(u32 move)
{
    return GET_DEPRECATED(bool32, gMovesInfo[SanitizeMoveId(move)].sketchBanned);
}

static inline bool32 IsMoveDampBanned(u32 move)
{
    return GET_DEPRECATED(bool32, gMovesInfo[SanitizeMoveId(move)].dampBanned);
}

static inline bool32 IsValidApprenticeMove(u32 move)
{
    return GET_DEPRECATED(bool32, gMovesInfo[SanitizeMoveId(move)].validApprenticeMove);
}

static inline u32 GetMoveTwoTurnAttackStringId(u32 move)
{
    return GET_DEPRECATED(u32, gMovesInfo[SanitizeMoveId(move)].argument.twoTurnAttack.stringId);
}

static inline u32 GetMoveTwoTurnAttackStatus(u32 move)
{
    return GET_DEPRECATED(u32, gMovesInfo[SanitizeMoveId(move)].argument.twoTurnAttack.status);
}

static inline u32 GetMoveTwoTurnAttackWeather(u32 move)
{
    return GET_DEPRECATED(u32, gMovesInfo[SanitizeMoveId(move)].argument.twoTurnAttack.status);
}

static inline enum ProtectMethod GetMoveProtectMethod(u32 move)
{
    return GET_DEPRECATED(u32, gMovesInfo[SanitizeMoveId(move)].argument.protectMethod);
}

static inline u32 GetMoveEffectArg_Status(u32 move)
{
    return GET_DEPRECATED(u32, gMovesInfo[SanitizeMoveId(move)].argument.status);
}

static inline u32 GetMoveEffectArg_MoveProperty(u32 move)
{
    return GET_DEPRECATED(u32, gMovesInfo[SanitizeMoveId(move)].argument.moveProperty);
}

static inline u32 GetMoveEffectArg_HoldEffect(u32 move)
{
    return GET_DEPRECATED(u32, gMovesInfo[SanitizeMoveId(move)].argument.holdEffect);
}

static inline u32 GetMoveArgType(u32 move)
{
    return GET_DEPRECATED(u32, gMovesInfo[SanitizeMoveId(move)].argument.type);
}

static inline u32 GetMoveFixedHPDamage(u32 move)
{
    return GET_DEPRECATED(u32, gMovesInfo[SanitizeMoveId(move)].argument.fixedDamage);
}

static inline u32 GetMoveAbsorbPercentage(u32 move)
{
    move = SanitizeMoveId(move);
    if (GET_DEPRECATED(u32, gMovesInfo[move].argument.absorbPercentage) == 0)
        return 50;
    return GET_DEPRECATED(u32, gMovesInfo[move].argument.absorbPercentage);
}

static inline u32 GetMoveRecoil(u32 move)
{
    return GET_DEPRECATED(u32, gMovesInfo[SanitizeMoveId(move)].argument.recoilPercentage);
}

static inline u32 GetMoveNonVolatileStatus(u32 move)
{
    move = SanitizeMoveId(move);
    switch(GetMoveEffect(move))
    {
    case EFFECT_NON_VOLATILE_STATUS:
    case EFFECT_YAWN:
    case EFFECT_DARK_VOID:
        return GET_DEPRECATED(u32, gMovesInfo[move].argument.nonVolatileStatus);
    default:
        return MOVE_EFFECT_NONE;
    }
}

static inline u32 GetMoveDamagePercentage(u32 move)
{
    return GET_DEPRECATED(u32, gMovesInfo[SanitizeMoveId(move)].argument.damagePercentage);
}

static inline u32 GetMoveOverwriteAbility(u32 move)
{
    return GET_DEPRECATED(u32, gMovesInfo[SanitizeMoveId(move)].argument.overwriteAbility);
}

static inline const struct AdditionalEffect *GetMoveAdditionalEffectById(u32 move, u32 effect)
{
    return GET_DEPRECATED(const struct AdditionalEffect *, &gMovesInfo[SanitizeMoveId(move)].additionalEffects[effect]);
}

static inline u32 GetMoveContestEffect(u32 move)
{
    return GET_DEPRECATED(u32, gMovesInfo[SanitizeMoveId(move)].contestEffect);
}

static inline u32 GetMoveContestCategory(u32 move)
{
    return GET_DEPRECATED(u32, gMovesInfo[SanitizeMoveId(move)].contestCategory);
}

static inline u32 GetMoveContestComboStarter(u32 move)
{
    return GET_DEPRECATED(u32, gMovesInfo[SanitizeMoveId(move)].contestCategory);
}

static inline u32 GetMoveContestComboMoves(u32 move, u32 comboMove)
{
    return GET_DEPRECATED(u32, gMovesInfo[SanitizeMoveId(move)].contestComboMoves[comboMove]);
}

static inline const u8 *GetMoveAnimationScript(u32 move)
{
    move = SanitizeMoveId(move);
    if (GET_DEPRECATED(const u8 *, gMovesInfo[move].battleAnimScript) == NULL)
    {
        DebugPrintfLevel(MGBA_LOG_WARN, "No animation for moveId=%u", move);
        return GET_DEPRECATED(const u8 *, gMovesInfo[MOVE_NONE].battleAnimScript);
    }
    return GET_DEPRECATED(const u8 *, gMovesInfo[move].battleAnimScript);
}

static inline const u8 *GetMoveBattleScript(u32 move)
{
    move = SanitizeMoveId(move);
    if (gBattleMoveEffects[GetMoveEffect(move)].battleScript == NULL)
    {
        DebugPrintfLevel(MGBA_LOG_WARN, "No effect for moveId=%u", move);
        return gBattleMoveEffects[EFFECT_PLACEHOLDER].battleScript;
    }
    return gBattleMoveEffects[GetMoveEffect(move)].battleScript;
}

#endif // GUARD_MOVES_H
