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

struct MoveInfo
{
    const u8 *name;
    const u8 *description;
    enum BattleMoveEffects effect;
    enum Type type:5; // Up to 32
    enum DamageCategory category:2;
    u16 power:9; // up to 511
    // end of word
    u16 accuracy:7;
    u16 target:9;
    u8 pp;
    union {
        u8 effect;
        u8 powerOverride;
    } zMove;
    // end of word
    s32 priority:4;
    u32 strikeCount:4; // Max 15 hits. Defaults to 1 if not set. May apply its effect on each hit.
    u32 criticalHitStage:2;
    bool32 alwaysCriticalHit:1;
    u32 numAdditionalEffects:3; // limited to 7
    // Flags
    bool32 makesContact:1;
    bool32 ignoresProtect:1;
    bool32 magicCoatAffected:1;
    bool32 snatchAffected:1;
    bool32 ignoresKingsRock:1;
    bool32 punchingMove:1;
    bool32 bitingMove:1;
    bool32 pulseMove:1;
    bool32 soundMove:1;
    bool32 ballisticMove:1;
    bool32 powderMove:1;
    bool32 danceMove:1;
    bool32 windMove:1;
    bool32 slicingMove:1;
    bool32 healingMove:1;
    bool32 minimizeDoubleDamage:1;
    bool32 ignoresTargetAbility:1;
    bool32 ignoresTargetDefenseEvasionStages:1;
    // end of word
    bool32 damagesUnderground:1;
    bool32 damagesUnderwater:1;
    bool32 damagesAirborne:1;
    bool32 damagesAirborneDoubleDamage:1;
    bool32 ignoreTypeIfFlyingAndUngrounded:1;
    bool32 thawsUser:1;
    bool32 ignoresSubstitute:1;
    bool32 forcePressure:1;
    bool32 cantUseTwice:1;
    bool32 alwaysHitsInRain:1;
    bool32 accuracy50InSun:1;
    bool32 alwaysHitsInHailSnow:1;
    // Ban flags
    bool32 gravityBanned:1;
    bool32 mirrorMoveBanned:1;
    bool32 meFirstBanned:1;
    bool32 mimicBanned:1;
    bool32 metronomeBanned:1;
    bool32 copycatBanned:1;
    bool32 assistBanned:1; // Matches same moves as copycatBanned + semi-invulnerable moves and Mirror Coat.
    bool32 sleepTalkBanned:1;
    bool32 instructBanned:1;
    bool32 encoreBanned:1;
    bool32 parentalBondBanned:1;
    bool32 skyBattleBanned:1;
    bool32 sketchBanned:1;
    bool32 dampBanned:1;
    //Other
    bool32 validApprenticeMove:1;
    u32 padding:5;
    // end of word

    union {
        struct {
            u16 stringId;
            u16 status;
        } twoTurnAttack;
        u32 protectMethod;
        u32 status;
        u32 moveProperty;
        u32 holdEffect;
        u32 type;
        u32 fixedDamage;
        u32 damagePercentage;
        u32 absorbPercentage;
        u32 recoilPercentage;
        u32 nonVolatileStatus;
        u32 overwriteAbility;
    } argument;

    // primary/secondary effects
    const struct AdditionalEffect *additionalEffects;

    // contest parameters
    u8 contestEffect;
    u8 contestCategory:3;
    u8 contestComboStarterId;
    u8 contestComboMoves[MAX_COMBO_MOVES];
    const u8 *battleAnimScript;
};

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
    return gMovesInfo[SanitizeMoveId(move)].name;
}

static inline enum BattleMoveEffects GetMoveEffect(u32 move)
{
    return gMovesInfo[SanitizeMoveId(move)].effect;
}

static inline const u8 *GetMoveDescription(u32 move)
{
    move = SanitizeMoveId(move);
    if (GetMoveEffect(move) == EFFECT_PLACEHOLDER)
        return gNotDoneYetDescription;
    return gMovesInfo[move].description;
}

static inline enum Type GetMoveType(u32 move)
{
    return gMovesInfo[SanitizeMoveId(move)].type;
}

static inline enum DamageCategory GetMoveCategory(u32 move)
{
    return gMovesInfo[SanitizeMoveId(move)].category;
}

static inline u32 GetMovePower(u32 move)
{
    return gMovesInfo[SanitizeMoveId(move)].power;
}

static inline u32 GetMoveAccuracy(u32 move)
{
    return gMovesInfo[SanitizeMoveId(move)].accuracy;
}

static inline u32 GetMoveTarget(u32 move)
{
    return gMovesInfo[SanitizeMoveId(move)].target;
}

static inline u32 GetMovePP(u32 move)
{
    return gMovesInfo[SanitizeMoveId(move)].pp;
}

static inline u32 GetMoveZEffect(u32 move)
{
    return gMovesInfo[SanitizeMoveId(move)].zMove.effect;
}

static inline u32 GetMoveZPowerOverride(u32 move)
{
    return gMovesInfo[SanitizeMoveId(move)].zMove.powerOverride;
}

static inline s32 GetMovePriority(u32 move)
{
    return gMovesInfo[SanitizeMoveId(move)].priority;
}

static inline u32 GetMoveStrikeCount(u32 move)
{
    return gMovesInfo[SanitizeMoveId(move)].strikeCount;
}

static inline u32 GetMoveCriticalHitStage(u32 move)
{
    return gMovesInfo[SanitizeMoveId(move)].criticalHitStage;
}

static inline bool32 MoveAlwaysCrits(u32 move)
{
    return gMovesInfo[SanitizeMoveId(move)].alwaysCriticalHit;
}

static inline u32 GetMoveAdditionalEffectCount(u32 move)
{
    return gMovesInfo[SanitizeMoveId(move)].numAdditionalEffects;
}

static inline bool32 MoveMakesContact(u32 move)
{
    return gMovesInfo[SanitizeMoveId(move)].makesContact;
}

static inline bool32 MoveIgnoresProtect(u32 move)
{
    return gMovesInfo[SanitizeMoveId(move)].ignoresProtect;
}

static inline bool32 MoveCanBeBouncedBack(u32 move)
{
    return gMovesInfo[SanitizeMoveId(move)].magicCoatAffected;
}

static inline bool32 MoveCanBeSnatched(u32 move)
{
    return gMovesInfo[SanitizeMoveId(move)].snatchAffected;
}

static inline bool32 MoveIgnoresKingsRock(u32 move)
{
    return gMovesInfo[SanitizeMoveId(move)].ignoresKingsRock;
}

static inline bool32 IsPunchingMove(u32 move)
{
    return gMovesInfo[SanitizeMoveId(move)].punchingMove;
}

static inline bool32 IsBitingMove(u32 move)
{
    return gMovesInfo[SanitizeMoveId(move)].bitingMove;
}

static inline bool32 IsPulseMove(u32 move)
{
    return gMovesInfo[SanitizeMoveId(move)].pulseMove;
}

static inline bool32 IsSoundMove(u32 move)
{
    return gMovesInfo[SanitizeMoveId(move)].soundMove;
}

static inline bool32 IsBallisticMove(u32 move)
{
    return gMovesInfo[SanitizeMoveId(move)].ballisticMove;
}

static inline bool32 IsPowderMove(u32 move)
{
    return gMovesInfo[SanitizeMoveId(move)].powderMove;
}

static inline bool32 IsDanceMove(u32 move)
{
    return gMovesInfo[SanitizeMoveId(move)].danceMove;
}

static inline bool32 IsWindMove(u32 move)
{
    return gMovesInfo[SanitizeMoveId(move)].windMove;
}

static inline bool32 IsSlicingMove(u32 move)
{
    return gMovesInfo[SanitizeMoveId(move)].slicingMove;
}

static inline bool32 IsHealingMove(u32 move)
{
    return gMovesInfo[SanitizeMoveId(move)].healingMove;
}

static inline bool32 MoveIncreasesPowerToMinimizedTargets(u32 move)
{
    return gMovesInfo[SanitizeMoveId(move)].minimizeDoubleDamage;
}

static inline bool32 MoveIgnoresTargetAbility(u32 move)
{
    return gMovesInfo[SanitizeMoveId(move)].ignoresTargetAbility;
}

static inline bool32 MoveIgnoresDefenseEvasionStages(u32 move)
{
    return gMovesInfo[SanitizeMoveId(move)].ignoresTargetDefenseEvasionStages;
}

static inline bool32 MoveDamagesUnderground(u32 move)
{
    return gMovesInfo[SanitizeMoveId(move)].damagesUnderground;
}

static inline bool32 MoveDamagesUnderWater(u32 move)
{
    return gMovesInfo[SanitizeMoveId(move)].damagesUnderwater;
}

static inline bool32 MoveDamagesAirborne(u32 move)
{
    return gMovesInfo[SanitizeMoveId(move)].damagesAirborne;
}

static inline bool32 MoveDamagesAirborneDoubleDamage(u32 move)
{
    return gMovesInfo[SanitizeMoveId(move)].damagesAirborneDoubleDamage;
}

static inline bool32 MoveIgnoresTypeIfFlyingAndUngrounded(u32 move)
{
    return gMovesInfo[SanitizeMoveId(move)].ignoreTypeIfFlyingAndUngrounded;
}

static inline bool32 MoveThawsUser(u32 move)
{
    return gMovesInfo[SanitizeMoveId(move)].thawsUser;
}

static inline bool32 MoveIgnoresSubstitute(u32 move)
{
    return gMovesInfo[SanitizeMoveId(move)].ignoresSubstitute;
}

static inline bool32 MoveForcesPressure(u32 move)
{
    return gMovesInfo[SanitizeMoveId(move)].forcePressure;
}

static inline bool32 MoveCantBeUsedTwice(u32 move)
{
    return gMovesInfo[SanitizeMoveId(move)].cantUseTwice;
}

static inline bool32 MoveAlwaysHitsInRain(u32 move)
{
    return gMovesInfo[SanitizeMoveId(move)].alwaysHitsInRain;
}

static inline bool32 MoveHas50AccuracyInSun(u32 move)
{
    return gMovesInfo[SanitizeMoveId(move)].accuracy50InSun;
}

static inline bool32 MoveAlwaysHitsInHailSnow(u32 move)
{
    return gMovesInfo[SanitizeMoveId(move)].alwaysHitsInHailSnow;
}

static inline bool32 IsMoveGravityBanned(u32 move)
{
    return gMovesInfo[SanitizeMoveId(move)].gravityBanned;
}

static inline bool32 IsMoveMirrorMoveBanned(u32 move)
{
    return gMovesInfo[SanitizeMoveId(move)].mirrorMoveBanned;
}

static inline bool32 IsMoveMeFirstBanned(u32 move)
{
    return gMovesInfo[SanitizeMoveId(move)].meFirstBanned;
}

static inline bool32 IsMoveMimicBanned(u32 move)
{
    return gMovesInfo[SanitizeMoveId(move)].mimicBanned;
}

static inline bool32 IsMoveMetronomeBanned(u32 move)
{
    return gMovesInfo[SanitizeMoveId(move)].metronomeBanned;
}

static inline bool32 IsMoveCopycatBanned(u32 move)
{
    return gMovesInfo[SanitizeMoveId(move)].copycatBanned;
}

static inline bool32 IsMoveAssistBanned(u32 move)
{
    return gMovesInfo[SanitizeMoveId(move)].assistBanned;
}

static inline bool32 IsMoveSleepTalkBanned(u32 move)
{
    return gMovesInfo[SanitizeMoveId(move)].sleepTalkBanned;
}

static inline bool32 IsMoveInstructBanned(u32 move)
{
    return gMovesInfo[SanitizeMoveId(move)].instructBanned;
}

static inline bool32 IsMoveEncoreBanned(u32 move)
{
    return gMovesInfo[SanitizeMoveId(move)].encoreBanned;
}

static inline bool32 IsMoveParentalBondBanned(u32 move)
{
    return gMovesInfo[SanitizeMoveId(move)].parentalBondBanned;
}

static inline bool32 IsMoveSkyBattleBanned(u32 move)
{
    return gMovesInfo[SanitizeMoveId(move)].skyBattleBanned;
}

static inline bool32 IsMoveSketchBanned(u32 move)
{
    return gMovesInfo[SanitizeMoveId(move)].sketchBanned;
}

static inline bool32 IsMoveDampBanned(u32 move)
{
    return gMovesInfo[SanitizeMoveId(move)].dampBanned;
}

static inline bool32 IsValidApprenticeMove(u32 move)
{
    return gMovesInfo[SanitizeMoveId(move)].validApprenticeMove;
}

static inline u32 GetMoveTwoTurnAttackStringId(u32 move)
{
    return gMovesInfo[SanitizeMoveId(move)].argument.twoTurnAttack.stringId;
}

static inline u32 GetMoveTwoTurnAttackStatus(u32 move)
{
    return gMovesInfo[SanitizeMoveId(move)].argument.twoTurnAttack.status;
}

static inline u32 GetMoveTwoTurnAttackWeather(u32 move)
{
    return gMovesInfo[SanitizeMoveId(move)].argument.twoTurnAttack.status;
}

static inline enum ProtectMethod GetMoveProtectMethod(u32 move)
{
    return gMovesInfo[SanitizeMoveId(move)].argument.protectMethod;
}

static inline u32 GetMoveEffectArg_Status(u32 move)
{
    return gMovesInfo[SanitizeMoveId(move)].argument.status;
}

static inline u32 GetMoveEffectArg_MoveProperty(u32 move)
{
    return gMovesInfo[SanitizeMoveId(move)].argument.moveProperty;
}

static inline u32 GetMoveEffectArg_HoldEffect(u32 move)
{
    return gMovesInfo[SanitizeMoveId(move)].argument.holdEffect;
}

static inline u32 GetMoveArgType(u32 move)
{
    return gMovesInfo[SanitizeMoveId(move)].argument.type;
}

static inline u32 GetMoveFixedHPDamage(u32 move)
{
    return gMovesInfo[SanitizeMoveId(move)].argument.fixedDamage;
}

static inline u32 GetMoveAbsorbPercentage(u32 move)
{
    move = SanitizeMoveId(move);
    if (gMovesInfo[move].argument.absorbPercentage == 0)
        return 50;
    return gMovesInfo[move].argument.absorbPercentage;
}

static inline u32 GetMoveRecoil(u32 move)
{
    return gMovesInfo[SanitizeMoveId(move)].argument.recoilPercentage;
}

static inline u32 GetMoveNonVolatileStatus(u32 move)
{
    move = SanitizeMoveId(move);
    switch(GetMoveEffect(move))
    {
    case EFFECT_NON_VOLATILE_STATUS:
    case EFFECT_YAWN:
    case EFFECT_DARK_VOID:
        return gMovesInfo[move].argument.nonVolatileStatus;
    default:
        return MOVE_EFFECT_NONE;
    }
}

static inline u32 GetMoveDamagePercentage(u32 move)
{
    return gMovesInfo[SanitizeMoveId(move)].argument.damagePercentage;
}

static inline u32 GetMoveOverwriteAbility(u32 move)
{
    return gMovesInfo[SanitizeMoveId(move)].argument.overwriteAbility;
}

static inline const struct AdditionalEffect *GetMoveAdditionalEffectById(u32 move, u32 effect)
{
    return &gMovesInfo[SanitizeMoveId(move)].additionalEffects[effect];
}

static inline u32 GetMoveContestEffect(u32 move)
{
    return gMovesInfo[SanitizeMoveId(move)].contestEffect;
}

static inline u32 GetMoveContestCategory(u32 move)
{
    return gMovesInfo[SanitizeMoveId(move)].contestCategory;
}

static inline u32 GetMoveContestComboStarter(u32 move)
{
    return gMovesInfo[SanitizeMoveId(move)].contestCategory;
}

static inline u32 GetMoveContestComboMoves(u32 move, u32 comboMove)
{
    return gMovesInfo[SanitizeMoveId(move)].contestComboMoves[comboMove];
}

static inline const u8 *GetMoveAnimationScript(u32 move)
{
    move = SanitizeMoveId(move);
    if (gMovesInfo[move].battleAnimScript == NULL)
    {
        DebugPrintfLevel(MGBA_LOG_WARN, "No animation for moveId=%u", move);
        return gMovesInfo[MOVE_NONE].battleAnimScript;
    }
    return gMovesInfo[move].battleAnimScript;
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

#ifndef ROM_HEADER_INCLUDE
#define gMovesInfo \
_Pragma("GCC error \"Use getters instead of accessing gMovesInfo directly.\"") \
gMovesInfo
#endif

#endif // GUARD_MOVES_H
