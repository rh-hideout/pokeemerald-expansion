#include "global.h"
#include "test/test.h"
#include "constants/form_change_types.h"

TEST("Form species ID tables are shared between all forms")
{
    u32 i;
    u32 species = SPECIES_NONE;
    for (i = 0; i < NUM_SPECIES; i++)
    {
        if (gSpeciesInfo[i].formSpeciesIdTable) PARAMETRIZE { species = i; }
    }

    const u16 *formSpeciesIdTable = gSpeciesInfo[species].formSpeciesIdTable;
    for (i = 0; formSpeciesIdTable[i] != FORM_SPECIES_END; i++)
    {
        u32 formSpeciesId = formSpeciesIdTable[i];
        EXPECT_EQ(gSpeciesInfo[formSpeciesId].formSpeciesIdTable, formSpeciesIdTable);
    }
}

TEST("Form change tables contain only forms in the form species ID table")
{
    u32 i, j;
    u32 species = SPECIES_NONE;
    for (i = 0; i < NUM_SPECIES; i++)
    {
        if (gSpeciesInfo[i].formChangeTable) PARAMETRIZE { species = i; }
    }

    const struct FormChange *formChangeTable = gSpeciesInfo[species].formChangeTable;
    const u16 *formSpeciesIdTable = gSpeciesInfo[species].formSpeciesIdTable;
    EXPECT(formSpeciesIdTable);

    for (i = 0; formChangeTable[i].method != FORM_CHANGE_TERMINATOR; i++)
    {
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
