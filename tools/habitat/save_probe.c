// Compile-only probe: each symbol's SIZE (via nm --print-size) encodes a
// sizeof()/offsetof() from the real headers, so the numbers can never drift
// from the source. Never linked into the ROM. See save_sizes.sh.
#include <stddef.h>
#include "global.h"
#include "constants/global.h"
#include "pokemon_storage_system.h"

#define PROBE(name, expr) char probe_##name[expr];

// Whole-block occupancy vs. sector budget
PROBE(SaveBlock1_total,     sizeof(struct SaveBlock1))
PROBE(SaveBlock2_total,     sizeof(struct SaveBlock2))
PROBE(PokemonStorage_total, sizeof(struct PokemonStorage))

// Spec §5 reclamation target: Secret Bases (+ their decoration sibling arrays)
PROBE(SecretBase_one,       sizeof(struct SecretBase))
PROBE(SecretBases_slab,     sizeof(((struct SaveBlock1 *)0)->secretBases))
PROBE(SecretBases_offset,   offsetof(struct SaveBlock1, secretBases) + 1)
PROBE(Decorations_span,     offsetof(struct SaveBlock1, tvShows)
                              - offsetof(struct SaveBlock1, playerRoomDecorations))

// Spec §5 backup targets: Contests, Battle Frontier
PROBE(ContestWinners_slab,  sizeof(((struct SaveBlock1 *)0)->contestWinners))
PROBE(Frontier_slab,        sizeof(((struct SaveBlock2 *)0)->frontier))

// Bonus targets observed while reading global.h (cut-content adjacent)
PROBE(TvShows_slab,         sizeof(((struct SaveBlock1 *)0)->tvShows))
PROBE(PokeNews_slab,        sizeof(((struct SaveBlock1 *)0)->pokeNews))

// Sector budget context (include/save.h): SB2 = 1 sector, SB1 = 4 sectors,
// and every sector donates a 116 B chunk to the expansion's SaveBlock3.
#include "save.h"
PROBE(SectorDataSize,       SECTOR_DATA_SIZE)
PROBE(SaveBlock1_budget,    SECTOR_DATA_SIZE * (SECTOR_ID_SAVEBLOCK1_END - SECTOR_ID_SAVEBLOCK1_START + 1))
PROBE(SaveBlock2_budget,    SECTOR_DATA_SIZE)
PROBE(SaveBlock3_total,     sizeof(struct SaveBlock3))
PROBE(SaveBlock3_budget,    SAVE_BLOCK_3_CHUNK_SIZE * 14)
