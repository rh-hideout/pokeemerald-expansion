#include "global.h"
#include "event_object_movement.h"
#include "random_mon_generation.h"
#include "string_util.h"
#include "test/test.h"
#include "constants/form_change_types.h"

TEST("Form species ID tables are shared between all forms")
{
    enum Species species = SPECIES_NONE;
    const u16 *formSpeciesIdTable;

    for (enum Species i = SPECIES_NONE; i < NUM_SPECIES; i++)
    {
        if (gSpeciesInfo[i].formSpeciesIdTable)
        {
            PARAMETRIZE_LABEL("ID:%d - %S", i, gSpeciesInfo[i].speciesName) { species = i; }
        }
    }

    formSpeciesIdTable = gSpeciesInfo[species].formSpeciesIdTable;
    for (u32 i = 0; formSpeciesIdTable[i] != FORM_SPECIES_END; i++)
    {
        enum Species formSpeciesId = formSpeciesIdTable[i];
        EXPECT_EQ(gSpeciesInfo[formSpeciesId].formSpeciesIdTable, formSpeciesIdTable);
    }
}

TEST("Form species ID tables fit within RANDOM_MON_MAX_FORMS")
{
    u32 formCount;
    enum Species species = SPECIES_NONE;
    const u16 *formSpeciesIdTable;

    for (enum Species i = SPECIES_NONE; i < NUM_SPECIES; i++)
    {
        if (gSpeciesInfo[i].formSpeciesIdTable)
            PARAMETRIZE_LABEL("ID:%d - %S", i, gSpeciesInfo[i].speciesName) { species = i; }
    }

    formSpeciesIdTable = gSpeciesInfo[species].formSpeciesIdTable;
    for (formCount = 0; formSpeciesIdTable[formCount] != FORM_SPECIES_END; formCount++)
        ;

    EXPECT(formCount <= RANDOM_MON_MAX_FORMS);
}

TEST("Form change tables contain only forms in the form species ID table")
{
    enum Species species = SPECIES_NONE;
    const struct FormChange *formChangeTable;
    const u16 *formSpeciesIdTable;

    for (enum Species i = SPECIES_NONE; i < NUM_SPECIES; i++)
    {
        if (gSpeciesInfo[i].formChangeTable)
        {
            PARAMETRIZE_LABEL("ID:%d - %S", i, gSpeciesInfo[i].speciesName) { species = i; }
        }
    }

    formChangeTable = gSpeciesInfo[species].formChangeTable;
    formSpeciesIdTable = gSpeciesInfo[species].formSpeciesIdTable;
    EXPECT(formSpeciesIdTable);

    for (u32 i = 0; formChangeTable[i].method != FORM_CHANGE_TERMINATOR; i++)
    {
        u32 j;

        if (formChangeTable[i].targetSpecies == SPECIES_NONE)
            continue;
        for (j = 0; formSpeciesIdTable[j] != FORM_SPECIES_END; j++)
        {
            if (formChangeTable[i].targetSpecies == formSpeciesIdTable[j])
            {
                break;
            }
        }
        EXPECT(formSpeciesIdTable[j] != FORM_SPECIES_END);
    }
}

TEST("Forms have the appropriate species form changes")
{
    enum Species species = SPECIES_NONE;

    for (enum Species i = SPECIES_NONE; i < NUM_SPECIES; i++)
    {
        if (gSpeciesInfo[i].isMegaEvolution
            || gSpeciesInfo[i].isGigantamax
            || gSpeciesInfo[i].isUltraBurst
            || gSpeciesInfo[i].isPrimalReversion)
        {
            PARAMETRIZE_LABEL("ID:%d - %S", i, gSpeciesInfo[i].speciesName) { species = i; }
        }
    }
    bool32 hasBattleEnd = FALSE, hasFaint = FALSE;

    const struct FormChange *formChanges = GetSpeciesFormChanges(species);
    EXPECT(formChanges != NULL);

    for (u32 j = 0; formChanges[j].method != FORM_CHANGE_TERMINATOR; j++)
    {
        if (species != formChanges[j].targetSpecies)
        {
            if (formChanges[j].method == FORM_CHANGE_END_BATTLE)
                hasBattleEnd = TRUE;
            else if (formChanges[j].method == FORM_CHANGE_FAINT)
                hasFaint = TRUE;
        }
    }

    EXPECT(hasBattleEnd);

    // Primal Reversion don't change forms upon fainting
    if (gSpeciesInfo[species].isMegaEvolution
        || gSpeciesInfo[species].isGigantamax
        || gSpeciesInfo[species].isUltraBurst)
    {
        EXPECT(hasFaint);
    }
}

TEST("Form change targets have the appropriate species flags")
{
    enum Species species = SPECIES_NONE;
    const struct FormChange *formChangeTable;

    for (enum Species i = SPECIES_NONE; i < NUM_SPECIES; i++)
    {
        if (gSpeciesInfo[i].formChangeTable)
        {
            PARAMETRIZE_LABEL("ID:%d - %S", i, gSpeciesInfo[i].speciesName) { species = i; }
        }
    }

    formChangeTable = gSpeciesInfo[species].formChangeTable;
    for (u32 i = 0; formChangeTable[i].method != FORM_CHANGE_TERMINATOR; i++)
    {
        const struct SpeciesInfo *targetSpeciesInfo = &gSpeciesInfo[formChangeTable[i].targetSpecies];
        switch (formChangeTable[i].method)
        {
        case FORM_CHANGE_BATTLE_MEGA_EVOLUTION_ITEM:
        case FORM_CHANGE_BATTLE_MEGA_EVOLUTION_MOVE:
            EXPECT(targetSpeciesInfo->isMegaEvolution);
            break;
        case FORM_CHANGE_BATTLE_PRIMAL_REVERSION:
            EXPECT(targetSpeciesInfo->isPrimalReversion);
            break;
        case FORM_CHANGE_BATTLE_ULTRA_BURST:
            EXPECT(targetSpeciesInfo->isUltraBurst);
            break;
        case FORM_CHANGE_BATTLE_GIGANTAMAX:
            EXPECT(targetSpeciesInfo->isGigantamax);
            break;
        default:
            break;
       }
    }
}

#if OW_POKEMON_OBJECT_EVENTS

TEST("Species' overworld sprites have correct number of frames for animTable")
{
    ASSUME(OW_GFX_COMPRESS == OGC_FAST || OW_GFX_COMPRESS == OGC_SMALL);

    enum Species species = 0;

    for (enum Species j = SPECIES_NONE; j < NUM_SPECIES; j++)
    {
        if (IsSpeciesEnabled(j))
            PARAMETRIZE_LABEL("ID:%d - %S", j, GetSpeciesName(j)) { species = j; }
    }

    {
        struct ObjectEventGraphicsInfo const * const overworldData = &gSpeciesInfo[species].overworldData;
        union AnimCmd const * const * const speciesAnimTable = overworldData->anims;

        if (speciesAnimTable == NULL)
            EXPECT(NULL == overworldData->images);
        else
        {
            u32 frameCount = -1;
            if (OW_GFX_COMPRESS == OGC_FAST)
            {
                frameCount = ((u8*) overworldData->images->data)[1];
            }
            else if (OW_GFX_COMPRESS == OGC_SMALL)
            {
                u32 headerWord = ((u32*) overworldData->images->data)[0];
                u32 imageSize = ((headerWord >> 4) & 0x3FFF) * 4;
                frameCount = imageSize / overworldData->images->size;
            }

            if (speciesAnimTable == sAnimTable_Following)
                EXPECT_EQ(6, frameCount);
            else if (speciesAnimTable == sAnimTable_Following_Asym)
                EXPECT_EQ(8, frameCount);
            else
                Test_ExitWithResult(TEST_RESULT_ASSUMPTION_FAIL, __LINE__, "%s:%d: Unknown anim table: %p", gTestRunnerState.test->filename, __LINE__, speciesAnimTable);
        }
    }

    #if P_GENDER_DIFFERENCES
    {
        struct ObjectEventGraphicsInfo const * const overworldData = &gSpeciesInfo[species].overworldDataFemale;
        union AnimCmd const * const * const speciesAnimTable = overworldData->anims;

        if (speciesAnimTable == NULL)
            EXPECT(NULL == overworldData->images);
        else
        {
            u32 frameCount = -1;
            if (OW_GFX_COMPRESS == OGC_FAST)
            {
                frameCount = ((u8*) overworldData->images->data)[1];
            }
            else if (OW_GFX_COMPRESS == OGC_SMALL)
            {
                u32 headerWord = ((u32*) overworldData->images->data)[0];
                u32 imageSize = ((headerWord >> 4) & 0x3FFF) * 4;
                frameCount = imageSize / overworldData->images->size;
            }

            if (speciesAnimTable == sAnimTable_Following)
                EXPECT_EQ(6, frameCount);
            else if (speciesAnimTable == sAnimTable_Following_Asym)
                EXPECT_EQ(8, frameCount);
            else
                Test_ExitWithResult(TEST_RESULT_ASSUMPTION_FAIL, __LINE__, "%s:%d: Unknown anim table: %p", gTestRunnerState.test->filename, __LINE__, speciesAnimTable);
        }
    }
    #endif
}

#endif

TEST("No species has two evolutions that use the evolution tracker")
{
    enum Species species = SPECIES_NONE;
    u32 evolutionTrackerEvolutions;
    bool32 hasRecoilEvo;
    const struct Evolution *evolutions;

    for (enum Species i = SPECIES_NONE; i < NUM_SPECIES; i++)
    {
        if (IsSpeciesEnabled(i) && GetSpeciesEvolutions(i) != NULL)
            PARAMETRIZE_LABEL("ID:%d - %S", i, GetSpeciesName(i)) { species = i; }
    }

    evolutionTrackerEvolutions = 0;
    hasRecoilEvo = FALSE;
    evolutions = GetSpeciesEvolutions(species);

    for (u32 i = 0; evolutions[i].method != EVOLUTIONS_END; i++)
    {
        if (evolutions[i].params == NULL)
            continue;
        for (u32 j = 0; evolutions[i].params[j].condition != CONDITIONS_END; j++)
        {
            if (evolutions[i].params[j].condition == IF_USED_MOVE_X_TIMES
             || evolutions[i].params[j].condition == IF_DEFEAT_X_WITH_ITEMS
            )
                evolutionTrackerEvolutions++;

            if (evolutions[i].params[j].condition == IF_RECOIL_DAMAGE_GE)
            {
                // Special handling for these since they can be combined as the evolution tracker field is used for the same purpose
                if (!hasRecoilEvo)
                {
                    hasRecoilEvo = TRUE;
                    evolutionTrackerEvolutions++;
                }
            }
        }
    }

    EXPECT(evolutionTrackerEvolutions < 2);
}

extern const u8 gFallbackPokedexText[];

TEST("Every species has a description")
{
    enum Species species = SPECIES_NONE;
    for (enum Species i = SPECIES_NONE + 1; i < NUM_SPECIES; i++)
    {
        if (IsSpeciesEnabled(i))
            PARAMETRIZE_LABEL("ID:%d - %S", i, GetSpeciesName(i)) { species = i; }
    }

    EXPECT_NE(StringCompare(GetSpeciesPokedexDescription(species), gFallbackPokedexText), 0);
}
