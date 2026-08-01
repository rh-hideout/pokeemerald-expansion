#include "global.h"
#include "relationships.h"
#include "constants/relationships.h"
#include "constants/vars.h"
#include "event_data.h"
#include "constants/counterparts.h"
#include "constants/flags.h"




void UpdateRelationship(void)
{
    if (FlagGet(FLAG_COUNTERPART_RELATIONSHIP_LOCKED))
        return;

    u16 compassion   = VarGet(VAR_COMPASSION);
    u16 curiosity    = VarGet(VAR_CURIOSITY);
    u16 resolve      = VarGet(VAR_RESOLVE);
    u16 independence = VarGet(VAR_INDEPENDENCE);
    u16 wisdom       = VarGet(VAR_WISDOM);
    u16 perspective  = VarGet(VAR_PERSPECTIVE);

    // Rest of your existing function stays here.

    /*
     * Each relationship route receives an equally weighted
     * maximum contribution:
     *
     * Companion = Compassion + Perspective
     * Mentor    = Curiosity + Wisdom
     * Rival     = Resolve x2
     * Foil      = Independence x2
     */
    u32 companionScore = compassion + perspective;
    u32 mentorScore    = curiosity + wisdom;
    u32 rivalScore     = resolve * 2;
    u32 foilScore      = independence * 2;

    /*
     * Before the player has made any meaningful decisions,
     * leave the relationship unresolved.
     */
    if (companionScore == 0
     && mentorScore == 0
     && rivalScore == 0
     && foilScore == 0)
    {
        VarSet(VAR_COUNTERPART_RELATIONSHIP, RELATIONSHIP_UNKNOWN);
    }
    /*
     * A route must be the sole highest score.
     */
    else if (companionScore > mentorScore
          && companionScore > rivalScore
          && companionScore > foilScore)
    {
        VarSet(VAR_COUNTERPART_RELATIONSHIP, RELATIONSHIP_COMPANION);
    }
    else if (mentorScore > companionScore
          && mentorScore > rivalScore
          && mentorScore > foilScore)
    {
        VarSet(VAR_COUNTERPART_RELATIONSHIP, RELATIONSHIP_MENTOR);
    }
    else if (rivalScore > companionScore
          && rivalScore > mentorScore
          && rivalScore > foilScore)
    {
        VarSet(VAR_COUNTERPART_RELATIONSHIP, RELATIONSHIP_RIVAL);
    }
    else
    {
        /*
         * Independence being highest, or any tied/unclear result,
         * produces the Foil route.
         */
        VarSet(VAR_COUNTERPART_RELATIONSHIP, RELATIONSHIP_FOIL);
    }
}

void FinalizeCounterpartRelationship(void)
{
    UpdateRelationship();
    FlagSet(FLAG_COUNTERPART_RELATIONSHIP_LOCKED);
}