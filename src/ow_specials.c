#include "global.h"
#include "pokemon.h"
#include "event_data.h"
#include "constants/pokemon.h"

// Returns TRUE if the player's party contains at least one RED, one BLUE, and
// one YELLOW Pokémon (by body colour). Used by the painter NPC on r3.
u16 CheckPartyHasRGBPokemon(void)
{
    bool8 hasRed = FALSE, hasBlue = FALSE, hasYellow = FALSE;
    u8 i;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        u16 species = GetMonData(&gPlayerParty[i], MON_DATA_SPECIES);
        if (species == SPECIES_NONE)
            continue;

        switch (gSpeciesInfo[species].bodyColor)
        {
        case BODY_COLOR_RED:    hasRed    = TRUE; break;
        case BODY_COLOR_BLUE:   hasBlue   = TRUE; break;
        case BODY_COLOR_YELLOW: hasYellow = TRUE; break;
        default: break;
        }
    }

    return (hasRed && hasBlue && hasYellow) ? TRUE : FALSE;
}
