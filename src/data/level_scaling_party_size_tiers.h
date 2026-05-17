// ============================================================================
// PARTY SIZE SCALING — AVG-LEVEL THRESHOLD TABLE
// ============================================================================
//
// Used when a trainer resolves to PARTY_SIZE_SCALING_BY_PLAYER_LEVEL.
//
// Walked top→bottom: the first row whose maxAvgLevel >= the player's average
// party level wins, and the trainer's party is capped to that row's
// maxPartySize. Keep rows sorted ascending by maxAvgLevel; (maxAvgLevel = 255)
// is the catch-all if not defined earlier.
//
// A trainer never fields MORE than its defined party, so a cap of 6 here just
// means "no reduction".

const struct PartySizeTier gPartySizeScalingTiers[] =
{
    { .maxAvgLevel = 15,  .maxPartySize = 3 },
    { .maxAvgLevel = 25,  .maxPartySize = 4 },
    { .maxAvgLevel = 40,  .maxPartySize = 5 },
    { .maxAvgLevel = 50, .maxPartySize = 6 },
};
