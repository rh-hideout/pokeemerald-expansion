#!/bin/sh
set -eu

trainerproc=${1:-./trainerproc}
tmpdir=$(mktemp -d)
trap 'rm -rf "$tmpdir"' EXIT

input="$tmpdir/frontier_mons.party"
constants="$tmpdir/battle_frontier_mons.h"
mons="$tmpdir/battle_frontier_mons_data.h"

cat > "$input" <<'EOF'
#pragma trainerproc frontierMons
#pragma trainerproc frontierHighTier FRONTIER_MON_TEST_1

=== FRONTIER_MON_TEST_1 ===

Sparky (Pikachu) (M) @ Light Ball
EVs: 252 HP / 4 Atk / 12 Def / 36 SpA / 44 SpD / 60 Spe
IVs: 31 HP / 30 Atk / 29 Def / 28 SpA / 27 SpD / 26 Spe
Ability: Static
Level: 50
Ball: Luxury
Happiness: 200
Nature: Timid
Shiny: Yes
Dynamax Level: 7
Gigantamax: Yes
Tera Type: Fire
Tags: Red / Blue
- Thunderbolt
- Surf
- Protect
- Volt Switch

=== FRONTIER_MON_TEST_2 ===

Abra @ Twisted Spoon
EVs: 0 HP / 0 Atk / 0 Def / 252 SpA / 4 SpD / 252 Spe
Nature: Modest
Ball: Poke
- Psychic
EOF

"$trainerproc" -m frontier-mon-constants -o "$constants" -i "$input" "$input"
"$trainerproc" -m frontier-mons -o "$mons" -i "$input" "$input"

grep -Fq "enum FrontierMonId" "$constants"
grep -Fq "FRONTIER_MON_TEST_1," "$constants"
grep -Fq "FRONTIER_MON_TEST_2," "$constants"
grep -Fq "FRONTIER_MONS_HIGH_TIER = FRONTIER_MON_TEST_1" "$constants"
grep -Fq "NUM_FRONTIER_MONS = FRONTIER_MON_TEST_2 + 1" "$constants"

grep -Fq "[FRONTIER_MON_TEST_1] = {" "$mons"
grep -Fq ".nickname = COMPOUND_STRING(\"Sparky\")" "$mons"
grep -Fq ".species = SPECIES_PIKACHU" "$mons"
grep -Fq ".gender = TRAINER_MON_MALE" "$mons"
grep -Fq ".heldItem = ITEM_LIGHT_BALL" "$mons"
grep -Fq ".ev = TRAINER_PARTY_EVS(252, 4, 12, 60, 36, 44)" "$mons"
grep -Fq ".iv = TRAINER_PARTY_IVS(31, 30, 29, 26, 28, 27)" "$mons"
grep -Fq ".ability = ABILITY_STATIC" "$mons"
grep -Fq ".lvl = 50" "$mons"
grep -Fq ".ball = BALL_LUXURY" "$mons"
grep -Fq ".friendship = 200" "$mons"
grep -Fq ".nature = NATURE_TIMID" "$mons"
grep -Fq ".isShiny = TRUE" "$mons"
grep -Fq ".dynamaxLevel = 7" "$mons"
grep -Fq ".gigantamaxFactor = TRUE" "$mons"
grep -Fq ".shouldUseDynamax = TRUE" "$mons"
grep -Fq ".teraType = TYPE_FIRE" "$mons"
grep -Fq ".tags = MON_POOL_TAG_RED | MON_POOL_TAG_BLUE" "$mons"
grep -Fq "MOVE_THUNDERBOLT" "$mons"
grep -Fq "MOVE_VOLT_SWITCH" "$mons"

grep -Fq "[FRONTIER_MON_TEST_2] = {" "$mons"
grep -Fq ".species = SPECIES_ABRA" "$mons"
grep -Fq ".heldItem = ITEM_TWISTED_SPOON" "$mons"
grep -Fq ".nature = NATURE_MODEST" "$mons"
grep -Fq ".ball = BALL_POKE" "$mons"
grep -Fq "MOVE_PSYCHIC" "$mons"

if grep -Fq "TRAINER_MON_RANDOM_GENDER" "$mons"; then
    echo "frontier output should not emit implicit random gender defaults" >&2
    exit 1
fi

if grep -Fq "MAX_DYNAMAX_LEVEL" "$mons"; then
    echo "frontier output should not emit implicit Dynamax defaults" >&2
    exit 1
fi
