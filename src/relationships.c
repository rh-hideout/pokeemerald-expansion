#include "global.h"
#include "event_data.h"
#include "relationships.h"

#include "constants/relationships.h"
#include "constants/vars.h"

void UpdateRelationship(void)
{
    u16 compassion = VarGet(VAR_COMPASSION);
    u16 curiosity = VarGet(VAR_CURIOSITY);
    u16 resolve = VarGet(VAR_RESOLVE);
    u16 independence = VarGet(VAR_INDEPENDENCE);

    // A virtue must be the sole highest value to define the relationship.
    // Any tie or unclear result becomes the Foil route.

    if (compassion > curiosity
        && compassion > resolve
        && compassion > independence)
    {
        VarSet(VAR_COUNTERPART_RELATIONSHIP, RELATIONSHIP_COMPANION);
    }
    else if (curiosity > compassion
             && curiosity > resolve
             && curiosity > independence)
    {
        VarSet(VAR_COUNTERPART_RELATIONSHIP, RELATIONSHIP_MENTOR);
    }
    else if (resolve > compassion
             && resolve > curiosity
             && resolve > independence)
    {
        VarSet(VAR_COUNTERPART_RELATIONSHIP, RELATIONSHIP_RIVAL);
    }
    else
    {
        VarSet(VAR_COUNTERPART_RELATIONSHIP, RELATIONSHIP_FOIL);
    }
}