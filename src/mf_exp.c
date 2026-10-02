#include "global.h"
#include "difficulty.h"
#include "event_data.h"
#include "mf_exp.h"
#include "mf_level_cap.h"
#include "mf_rules.h"

u32 MfResolveExpPool(u32 calculatedExp, u8 expMultiplier, bool8 applyHardReduction)
{
    switch (expMultiplier)
    {
    case MF_EXP_MULT_15X:
        calculatedExp = (calculatedExp * 3) / 2;
        break;
    case MF_EXP_MULT_2X:
        calculatedExp *= 2;
        break;
    case MF_EXP_MULT_0X:
        return 0;
    case MF_EXP_MULT_1X:
    default:
        break;
    }

    if (applyHardReduction)
        calculatedExp = (calculatedExp * 3) / 5;

    return calculatedExp;
}

bool8 MfIsHardExpReductionActive(u8 levelCapMode, bool8 hardExpNormal, bool8 hardDifficulty, bool8 gameClear)
{
    if (hardExpNormal || gameClear)
        return FALSE;

    // Default (hardExp 0) is ME's 60% while "in Hard". We have no options-menu
    // Hard mode, so Level Cap Hard is that state. DIFFICULTY_HARD counts too
    // if a later change sets B_VAR_DIFFICULTY. The two do not stack.
    return levelCapMode == MF_LEVEL_CAP_HARD || hardDifficulty;
}

u32 MfScaleCalculatedExp(u32 calculatedExp)
{
    bool8 hardDifficulty = (GetCurrentDifficultyLevel() == DIFFICULTY_HARD);

    return MfResolveExpPool(
        calculatedExp,
        MfRules_GetExpMultiplier(),
        MfIsHardExpReductionActive(
            MfRules_GetLevelCap(),
            MfRules_GetBool(MF_RULE_BOOL_HARD_EXP),
            hardDifficulty,
            FlagGet(FLAG_SYS_GAME_CLEAR)));
}

bool8 MfIsExpMultiplierZero(void)
{
    return MfRules_GetExpMultiplier() == MF_EXP_MULT_0X;
}
