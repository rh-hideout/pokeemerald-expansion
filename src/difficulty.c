#include "global.h"
#include "data.h"
#include "event_data.h"
#include "script.h"
#include "constants/battle.h"

enum DifficultyLevel GetCurrentDifficultyLevel(void)
{
    if (!B_VAR_DIFFICULTY)
        return DIFFICULTY_NORMAL;

    return VarGet(B_VAR_DIFFICULTY);
}

void SetCurrentDifficultyLevel(enum DifficultyLevel desiredDifficulty)
{
    if (!B_VAR_DIFFICULTY)
        return;

    if (desiredDifficulty > DIFFICULTY_MAX)
        desiredDifficulty = DIFFICULTY_MAX;

    VarSet(B_VAR_DIFFICULTY, desiredDifficulty);
}

enum DifficultyLevel GetBattlePartnerDifficultyLevel(u16 partnerId)
{
    enum DifficultyLevel difficulty = GetCurrentDifficultyLevel();

    if (partnerId > TRAINER_PARTNER(PARTNER_NONE))
        partnerId -= TRAINER_PARTNER(PARTNER_NONE);

    if (difficulty == DIFFICULTY_NORMAL)
        return DIFFICULTY_NORMAL;

    if (gBattlePartners[difficulty][partnerId].party == NULL)
        return DIFFICULTY_NORMAL;

    return difficulty;
}

enum DifficultyLevel GetTrainerDifficultyLevel(u16 trainerId)
{
    enum DifficultyLevel difficulty = GetCurrentDifficultyLevel();

    if (difficulty == DIFFICULTY_NORMAL)
        return DIFFICULTY_NORMAL;

    if (gTrainers[difficulty][trainerId].party == NULL)
        return DIFFICULTY_NORMAL;

    return difficulty;
}

void Script_IncreaseDifficulty(struct ScriptContext *ctx)
{
    enum DifficultyLevel currentDifficulty;

    if (!B_VAR_DIFFICULTY)
        return;

    currentDifficulty = GetCurrentDifficultyLevel();

    if (currentDifficulty++ > DIFFICULTY_MAX)
        return;

    SetCurrentDifficultyLevel(currentDifficulty);
}

void Script_DecreaseDifficulty(struct ScriptContext *ctx)
{
    enum DifficultyLevel currentDifficulty;

    if (!B_VAR_DIFFICULTY)
        return;

    currentDifficulty = GetCurrentDifficultyLevel();

    if (!currentDifficulty)
        return;

    SetCurrentDifficultyLevel(--currentDifficulty);
}

void Script_GetDifficulty(struct ScriptContext *ctx)
{
    gSpecialVar_Result = GetCurrentDifficultyLevel();
}

void Script_SetDifficulty(struct ScriptContext *ctx)
{
    enum DifficultyLevel desiredDifficulty = ScriptReadByte(ctx);

    SetCurrentDifficultyLevel(desiredDifficulty);
}
