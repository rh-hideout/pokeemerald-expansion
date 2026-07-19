// Script-facing interaction layer: specials called from
// data/scripts/habitat_spot.inc. Text placeholders are engine-side; hint
// prose is authored content (spec working agreement).
#include "global.h"
#include "habitat/save.h"
#include "habitat/spots.h"
#include "event_data.h"
#include "pokemon.h"
#include "string_util.h"
#include "constants/habitat.h"

static const u8 sText_NotASpot[] = _("PLACEHOLDER: nothing here.$");

// special Habitat_OnInspectSpot — resolves the talked object to a spot,
// counts the talk, buffers {STR_VAR_1}=species name and gStringVar4=staged
// hint, and returns the spot state (or HABITAT_INSPECT_NOT_A_SPOT).
void Habitat_OnInspectSpot(void)
{
    const struct HabitatSpot *spot = Habitat_GetSpotByObject(
        gSaveBlock1Ptr->location.mapGroup,
        gSaveBlock1Ptr->location.mapNum,
        gSpecialVar_LastTalked);
    u8 state;
    const u8 *hint;

    if (spot == NULL)
    {
        StringCopy(gStringVar4, sText_NotASpot);
        gSpecialVar_Result = HABITAT_INSPECT_NOT_A_SPOT;
        return;
    }

    Habitat_IncrementTalkCount(spot->spotId);
    state = Habitat_GetSpotState(spot->spotId);
    switch (state)
    {
    case HABITAT_STATE_DORMANT:  hint = spot->hintDormant;  break;
    case HABITAT_STATE_STIRRING: hint = spot->hintStirring; break;
    default:                     hint = spot->hintActive;   break;
    }
    // Expand ROM hint -> gStringVar4 NOW (species name via {STR_VAR_1}).
    // The field-message pipeline re-expands gStringVar4 into itself at
    // display time; a with-placeholders self-expansion shifts lengths over
    // an overlapping buffer and corrupts EWRAM (found the hard way in the
    // M1 phase 2 headless runs). Text handed to msgbox from gStringVar4
    // must always arrive here fully expanded.
    StringCopy(gStringVar1, GetSpeciesName(spot->species));
    StringExpandPlaceholders(gStringVar4, hint);
    gSpecialVar_Result = state;
}
