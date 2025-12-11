#include "global.h"
#include "pokemon.h"
#include "pokemon_summary_screen.h"
#include "strings.h"
#include "daycare.h"
#include "random.h"
#include "battle_z_move.h"
#include "overworld.h"
#include "text.h"
#include "event_data.h"
#include "region_map.h"
#include "malloc.h"
#include "constants/species.h"
#include "constants/items.h"
#include "constants/abilities.h"
#include "constants/region_map_sections.h"
#include "item.h"
#include "constants/item.h"
#include "constants/hold_effects.h"
#include "mail.h"
#include "constants/pokemon.h"
#include "party_menu.h"
#include "field_weather.h"
#include "constants/weather.h"
#include "battle.h"
#include "string_util.h"
#include "daycare.h"
#include "wonder_trade.h"
#include "data/wonder_trade_custom_items.h"
#include "data/wonder_trade_custom_mons.h"
#include "data/wonder_trade_ots.h"

static u32 GenerateSurpriseTradeSpecies(void);
static u32 CalculateSurpriseTradeExperience(u32 level, u32 species);
static void AddSurpriseTradeMoves(struct Pokemon *mon);
static void AddLevelUpMoves(struct Pokemon *mon, u32 species, u32 *finalMoves, u32 *finalMoveCount);
static void AddTmMoves(struct Pokemon *mon, u32 species, u32 *finalMoves, u32 *finalMoveCount);
static void AddEggMoves(struct Pokemon *mon, u32 species, u32 *finalMoves, u32 *finalMoveCount);
static void AddTutorMoves(struct Pokemon *mon, u32 species, u32 *finalMoves, u32 *finalMoveCount);
static void ApplyFinalMoves(struct Pokemon *mon, u32 *finalMoves);
static void CompactMoveSlots(struct Pokemon *mon);
static void AddSurpriseTradeEffortValues(struct Pokemon* mon);
static u32 GenerateSurpriseTradeAbility(u32 species);
static bool32 IsItemBlocked(u32 item);
static u32 GenerateSurpriseTradeItem(u32 species);
static u32 GenerateSurpriseTradeBall(void);
static bool32 ShouldMonBeShiny(u32 personality, u32 trainerId);
static u32 GetTotalBST(u32 species);
static void TryAutoEvolve(u32 *species);

STATIC_ASSERT(WT_RANDOM_MOVESET_EGG + WT_RANDOM_MOVESET_LEVELUP + WT_RANDOM_MOVESET_TM + WT_RANDOM_MOVESET_TUTOR == 4, wonderTradeMoveSumNotFour);
STATIC_ASSERT(WT_NUM_PERFECT_IVS <=6 && WT_NUM_PERFECT_IVS >= 0, wonderTradePerfectIvsOutOfBounds);

void CreateWonderTradePokemon(void)
{
    u32 playerMonLevel = GetMonData(&gPlayerParty[gSpecialVar_0x8005], MON_DATA_LEVEL);
    u32 wonderTradeSpecies = GenerateSurpriseTradeSpecies();
    u32 experience = CalculateSurpriseTradeExperience(playerMonLevel, wonderTradeSpecies);
    u32 newHeldItem = GenerateSurpriseTradeItem(wonderTradeSpecies);
    u32 abilityNum = GenerateSurpriseTradeAbility(wonderTradeSpecies);
    enum PokeBall ball = GenerateSurpriseTradeBall();

    u32 trainer = Random() % ARRAY_COUNT(wonderTradeTrainer);
    u8* name = Alloc(TRAINER_NAME_LENGTH+1);
    StringCopy(name, wonderTradeTrainer[trainer].otName);

    u32 otId = wonderTradeTrainer[trainer].otId;
    u32 otGender = wonderTradeTrainer[trainer].otGender;

    u32 metLocation = METLOC_IN_GAME_TRADE;

    CreateMon(&gEnemyParty[0], wonderTradeSpecies, 1, WT_RANDOM_IVS, FALSE, 0, OT_ID_PRESET, otId);

    bool32 isShiny = ShouldMonBeShiny(GetMonData(&gEnemyParty[0],MON_DATA_PERSONALITY),otId);

    SetMonData(&gEnemyParty[0], MON_DATA_EXP, &experience);
    SetMonData(&gEnemyParty[0], MON_DATA_HELD_ITEM, &newHeldItem);
    SetMonData(&gEnemyParty[0], MON_DATA_ABILITY_NUM, &abilityNum);
    SetMonData(&gEnemyParty[0], MON_DATA_IS_SHINY, &isShiny);

    SetMonData(&gEnemyParty[0], MON_DATA_OT_NAME, name);
    SetMonData(&gEnemyParty[0], MON_DATA_OT_ID, &otId);
    SetMonData(&gEnemyParty[0], MON_DATA_OT_GENDER, &otGender);
    SetMonData(&gEnemyParty[0], MON_DATA_MET_LOCATION, &metLocation);
    SetMonData(&gEnemyParty[0], MON_DATA_POKEBALL, &ball);

    if (WT_RANDOM_EVS)
        AddSurpriseTradeEffortValues(&gEnemyParty[0]);
    AddSurpriseTradeMoves(&gEnemyParty[0]);


    CalculateMonStats(&gEnemyParty[0]);

    Free(name);
}

static u32 GenerateSurpriseTradeSpecies(void)
{

    u32 species = SPECIES_NONE; // In theory, this should NEVER remain SPECIES_NONE. Use cases for pokemon being traded away with BST > 600 are handled.
    
    // Use custom mon list if WT_TYPE_CUSTOM
    
    if (WT_TYPE == WT_TYPE_CUSTOM) {

        species = customWonderTradeSpecies[RandomUniform(RNG_NONE, 1, WT_NUM_CUSTOM_SPECIES) - 1];

        if (WT_AUTO_EVOLVE)
            TryAutoEvolve(&species);

        return species;
    }

    u32 dexCount = (WT_DEX_NATIONAL) ? NATIONAL_DEX_COUNT : HOENN_DEX_COUNT;
    u32 *dexList = Alloc(dexCount * 4);

    for (u32 speciesIndex = 0; speciesIndex < dexCount; speciesIndex++)
        dexList[speciesIndex] = speciesIndex;

    Shuffle(dexList, dexCount, sizeof(dexList[0]));

    // For non-custom mons, we don't wanna just randomly pick mons potentially twice, we'd rather iterate through a random list of mons

    for (u32 speciesIndex = 0; speciesIndex < NUM_SPECIES; speciesIndex++)
    {

        u32 newSpecies = dexList[speciesIndex];
        if (!WT_DEX_NATIONAL)
            newSpecies = HoennToNationalOrder(newSpecies);
        newSpecies = NationalPokedexNumToSpecies(newSpecies);

        if ((gSpeciesInfo[newSpecies].isRestrictedLegendary && !WT_USE_RESTRICTEDS)
        ||  (gSpeciesInfo[newSpecies].isSubLegendary && !WT_USE_SUBLEGENDARIES)
        ||  (gSpeciesInfo[newSpecies].isMythical && !WT_USE_MYTHICALS)
        ||  (gSpeciesInfo[newSpecies].isUltraBeast && !WT_USE_ULTRA_BEASTS)
        ||  (gSpeciesInfo[newSpecies].isParadox && !WT_USE_PARADOXES))
            continue;

        if (WT_TYPE == WT_TYPE_WEIGHTED) {
            s32 playerMonBST = GetTotalBST(GetMonData(&gPlayerParty[gSpecialVar_0x8005], MON_DATA_SPECIES));
            s32 newSpeciesBST = GetTotalBST(newSpecies);
            s32 difference = playerMonBST - newSpeciesBST;
            if (difference < 0)
                difference *= -1;
            if (difference > WT_WEIGHT 
                || (playerMonBST > 700 && difference > 120) //Arceus Edge Case
                || (playerMonBST > 600 && difference > WT_WEIGHT_LENIENT)) //Edge case for trading away a legendary pokemon when you have a bunch of levers turned off
                continue;
        }

        if (WT_FORMS 
            && newSpecies != SPECIES_ARCEUS
            && newSpecies != SPECIES_GENESECT  // Edge cases for pokemon that change form with held items but have shared species info
            && newSpecies != SPECIES_SILVALLY
            && newSpecies != SPECIES_OGERPON) 
        { 
            const u16 *formTable = GetSpeciesFormTable(newSpecies);
            if (formTable != NULL) {
                u16 chooseableForms[64]; //Alcremie has a lot of forms bro
                u16 numForms = 0;
                for (u8 formId = 0; formTable[formId] != FORM_SPECIES_END; formId++) {
                    if (   gSpeciesInfo[formTable[formId]].isMegaEvolution
                        || gSpeciesInfo[formTable[formId]].isGigantamax
                        || gSpeciesInfo[formTable[formId]].isTotem
                        || gSpeciesInfo[formTable[formId]].isUltraBurst
                        || gSpeciesInfo[formTable[formId]].cannotBeTraded
                        || gSpeciesInfo[formTable[formId]].isTeraForm
                        || gSpeciesInfo[formTable[formId]].isPrimalReversion
                        || gSpeciesInfo[formTable[formId]].isWonderTradeBanned) {
                        //We don't want these
                        continue;
                    }
                    else {
                        chooseableForms[numForms] = formTable[formId];
                        numForms++;
                    }
                }
                if (numForms != 0) // Again, shouldn't happen, but doesn't hurt
                    newSpecies = chooseableForms[RandomUniform(RNG_NONE, 1, numForms) - 1];
            }
        }

        if (WT_AUTO_EVOLVE)
            TryAutoEvolve(&newSpecies);

        species = newSpecies;
        break;
    }

    Free(dexList);
    
    return species;
}

static void TryAutoEvolve(u32 *species) {

    const struct Evolution *evolutions = GetSpeciesEvolutions(*species);

    if (evolutions == NULL)
        return;

    u16 chooseableEvos[64]; // Alcremie strikes again
    u16 numEvos = 0;
    u32 monLevel = GetMonData(&gPlayerParty[gSpecialVar_0x8005], MON_DATA_LEVEL);

    for (int i = 0; evolutions[i].method != EVOLUTIONS_END; i++)
    {
        u32 testSpecies = SPECIES_NONE;

        switch(evolutions[i].method)
        {
            case EVO_LEVEL:
                if (monLevel >= evolutions[i].param) 
                    testSpecies = evolutions[i].targetSpecies;
                break;
            case EVO_TRADE:
                if (monLevel >= WT_AUTO_EVOLVE_TRADE_LEVEL) 
                    testSpecies = evolutions[i].targetSpecies;
                break;
            case EVO_ITEM:
                if (monLevel >= WT_AUTO_EVOLVE_ITEM_LEVEL) 
                    testSpecies = evolutions[i].targetSpecies;
                break;
            case EVO_SPLIT_FROM_EVO: /*Shedinja special case*/
                if (monLevel >= 20) 
                    testSpecies = evolutions[i].targetSpecies;
                break;
            case EVO_SCRIPT_TRIGGER:
                if (monLevel >= WT_AUTO_EVOLVE_OTHER_LEVEL) 
                    testSpecies = evolutions[i].targetSpecies;
                break;
            case EVO_LEVEL_BATTLE_ONLY:
                if (monLevel >= evolutions[i].param) 
                    testSpecies = evolutions[i].targetSpecies;
                break;
            case EVO_BATTLE_END:
                if (monLevel >= WT_AUTO_EVOLVE_OTHER_LEVEL) 
                    testSpecies = evolutions[i].targetSpecies;
                break;
            case EVO_SPIN:
                if (monLevel >= WT_AUTO_EVOLVE_ITEM_LEVEL) 
                    testSpecies = evolutions[i].targetSpecies;
                break;
            default:
                break;
        }

        if (testSpecies != SPECIES_NONE && !gSpeciesInfo[testSpecies].isWonderTradeBanned) {

            bool32 isAlreadyIn = FALSE; 

            for (int j = 0; j <= numEvos; j++) {
                if (chooseableEvos[j] == testSpecies) {
                    isAlreadyIn = TRUE;
                }
            }

            if (!isAlreadyIn) {
                chooseableEvos[numEvos] = testSpecies;
                numEvos++;
            }
        }
    }

    if (numEvos == 0) // Shouldn't happen, but failsafe just in case of custom wonder trade bans or custom dexes
        return;

    *species = chooseableEvos[RandomUniform(RNG_NONE, 1, numEvos) - 1];

    //Evolve again?
    if (GetSpeciesEvolutions(*species) != NULL)
        TryAutoEvolve(species);

    return;
}

static u32 CalculateSurpriseTradeExperience(u32 level, u32 species)
{
    u32 growthRate = gSpeciesInfo[species].growthRate;
    u32 expLimit = gExperienceTables[growthRate][level + 1];
    u32 topLimit = gExperienceTables[growthRate][MAX_LEVEL];

    u32 exp = Random() % expLimit;

    if (exp == 0)
        exp = 1;
    else if (exp > topLimit)
        exp = topLimit;

    return exp;
}

void AddSurpriseTradeMoves(struct Pokemon *mon)
{
    u32 species = GetMonData(mon, MON_DATA_SPECIES, NULL);
    u32 finalMoves[MAX_MON_MOVES] = {MOVE_NONE};

    u32 finalMoveCount = 0;

    AddLevelUpMoves(mon, species, finalMoves, &finalMoveCount);
    
    if (WT_RANDOM_MOVESETS && WT_RANDOM_MOVESET_TM != 0) {
        AddTmMoves(mon, species, finalMoves, &finalMoveCount);
    }
    if (WT_RANDOM_MOVESETS && WT_RANDOM_MOVESET_EGG != 0) {
        AddEggMoves(mon, species, finalMoves, &finalMoveCount);
    }
    if (WT_RANDOM_MOVESETS && WT_RANDOM_MOVESET_TUTOR != 0) {
        AddTutorMoves(mon, species, finalMoves, &finalMoveCount);
    } 

    ApplyFinalMoves(mon, finalMoves);
    CompactMoveSlots(mon);
}

static void AddTmMoves(struct Pokemon *mon, u32 species, u32 *finalMoves, u32 *finalMoveCount) {

    u16 moves[MAX_RELEARNER_MOVES] = {0};
    u16 numMoves = GetRelearnerTMMoves(mon, moves);

    if (numMoves == 0) {
        return;
    }

    u16 pickedIndices[4] = {0};
    u16 chosenCount = 0;

    Shuffle(moves, numMoves, sizeof(moves[0]));

    for (u32 i = 0; i < numMoves && chosenCount < WT_RANDOM_MOVESET_TM; i++) {

        bool32 alreadyChosen = FALSE;

        for (u32 j = 0; j < chosenCount; j++) {
            if (moves[i] == pickedIndices[j]) {
                alreadyChosen = TRUE;
                break;
            }
        }
        for (u32 j = 0; j < *finalMoveCount; j++) {
            if (moves[i] == finalMoves[j]) {
                alreadyChosen = TRUE;
                break;
            }
        }
        if (!alreadyChosen) {
            pickedIndices[chosenCount] = i;
            chosenCount++;
            finalMoves[*finalMoveCount] = moves[i];
            (*finalMoveCount)++;
        }
    }

    return;
}

static void AddEggMoves(struct Pokemon *mon, u32 species, u32 *finalMoves, u32 *finalMoveCount) {
    
    u16 moves[MAX_RELEARNER_MOVES] = {0};
    u16 numMoves = GetRelearnerEggMoves(mon, moves);

    if (numMoves == 0) {
        return;
    }

    u16 pickedIndices[4] = {0};
    u16 chosenCount = 0;

    Shuffle(moves, numMoves, sizeof(moves[0]));

    for (u32 i = 0; i < numMoves && chosenCount < WT_RANDOM_MOVESET_EGG; i++) {

        bool32 alreadyChosen = FALSE;

        for (u32 j = 0; j < chosenCount; j++) {
            if (moves[i] == pickedIndices[j]) {
                alreadyChosen = TRUE;
                break;
            }
        }
        for (u32 j = 0; j < *finalMoveCount; j++) {
            if (moves[i] == finalMoves[j]) {
                alreadyChosen = TRUE;
                break;
            }
        }
        if (!alreadyChosen) {
            pickedIndices[chosenCount] = i;
            chosenCount++;
            finalMoves[*finalMoveCount] = moves[i];
            (*finalMoveCount)++;
        }
    }

    return;
}
static void AddTutorMoves(struct Pokemon *mon, u32 species, u32 *finalMoves, u32 *finalMoveCount) {

    u16 moves[MAX_RELEARNER_MOVES] = {0};
    u16 numMoves = GetRelearnerTutorMoves(mon, moves);

    if (numMoves == 0) {
        return;
    }

    u16 pickedIndices[4] = {0};
    u16 chosenCount = 0;

    Shuffle(moves, numMoves, sizeof(moves[0]));

    for (u32 i = 0; i < numMoves && chosenCount < WT_RANDOM_MOVESET_TUTOR; i++) {

        bool32 alreadyChosen = FALSE;

        for (u32 j = 0; j < chosenCount; j++) {
            if (moves[i] == pickedIndices[j]) {
                alreadyChosen = TRUE;
                break;
            }
        }
        for (u32 j = 0; j < *finalMoveCount; j++) {
            if (moves[i] == finalMoves[j]) {
                alreadyChosen = TRUE;
                break;
            }
        }
        if (!alreadyChosen) {
            pickedIndices[chosenCount] = i;
            chosenCount++;
            finalMoves[*finalMoveCount] = moves[i];
            (*finalMoveCount)++;
        }
    }

    return;
}

static void AddLevelUpMoves(struct Pokemon *mon, u32 species, u32 *finalMoves, u32 *finalMoveCount)
{
    u32 learnedMoves[MAX_MON_MOVES] = {MOVE_NONE};
    u32 learnedCount = 0;
    u32 level = GetLevelFromMonExp(mon);

    const struct LevelUpMove *learnset = GetSpeciesLevelUpLearnset(species);
    for (u32 i = 0; learnset[i].move != LEVEL_UP_MOVE_END; i++)
    {
        if (learnset[i].level > level || learnset[i].level == 0)
            continue;

        bool32 alreadyIn = FALSE;
        for (u32 learnedMoveIndex = 0; learnedMoveIndex < learnedCount; learnedMoveIndex++)
        {
            if (learnedMoves[learnedMoveIndex] != learnset[i].move)
                continue;

            alreadyIn = TRUE;
            break;
        }

        if (!alreadyIn && learnedCount < ARRAY_COUNT(learnedMoves))
            learnedMoves[learnedCount++] = learnset[i].move;
    }

    u32 start = (learnedCount >= MAX_MON_MOVES) ? learnedCount - MAX_MON_MOVES : 0;
    u32 finalCount = 0;
    if (!WT_RANDOM_MOVESETS) {
        for (u32 moveIndex = start; moveIndex < learnedCount && finalCount < MAX_MON_MOVES; moveIndex++)
            finalMoves[finalCount++] = learnedMoves[moveIndex];
    } else {
        for (u32 moveIndex = start; moveIndex < learnedCount && *finalMoveCount < WT_RANDOM_MOVESET_LEVELUP; moveIndex++) {
            finalMoves[*finalMoveCount] = learnedMoves[moveIndex];
            (*finalMoveCount)++;
        }
    }
}

static void ApplyFinalMoves(struct Pokemon *mon, u32 *finalMoves)
{
    for (u32 i = 0; i < MAX_MON_MOVES; i++)
    {
        SetMonData(mon, MON_DATA_MOVE1 + i, &finalMoves[i]);
        u32 pp = GetMovePP(finalMoves[i]);
        SetMonData(mon, MON_DATA_PP1 + i, &pp);
    }
}

static void CompactMoveSlots(struct Pokemon *mon)
{
    for (u32 i = 0; i < MAX_MON_MOVES - 1; i++)
    {
        u32 move = GetMonData(mon, MON_DATA_MOVE1 + i);

        if (move != MOVE_NONE)
            continue;

        move = GetMonData(mon, MON_DATA_MOVE1 + i + 1);

        if (move == MOVE_NONE)
            continue;

        ShiftMoveSlot(mon, i, i + 1);
    }
}

static void AddSurpriseTradeEffortValues(struct Pokemon* mon)
{
    s32 level = GetLevelFromMonExp(mon);
    u32 levelRatio = (level * 100) / MAX_LEVEL;
    u32 remaining = (MAX_TOTAL_EVS * levelRatio) / 100;
    u32 statIndex = 0;
    u32 evs[NUM_STATS] = {0};

    if (remaining > MAX_TOTAL_EVS)
        remaining = MAX_TOTAL_EVS;

    while (remaining > 0)
    {
        statIndex = Random() % NUM_STATS;
        if (evs[statIndex] >= MAX_PER_STAT_EVS)
            continue;

        evs[statIndex]++;
        remaining--;
    }

    for (statIndex = 0; statIndex < NUM_STATS; statIndex++)
        SetMonData(mon, MON_DATA_HP_EV + statIndex, &evs[statIndex]);
}

static u32 GenerateSurpriseTradeAbility(u32 species)
{
    u8 increment = 0;
    u32 possibleAbilities[3];

    for (u8 i = 0; i < 3; i++) {
        if (gSpeciesInfo[species].abilities[i] != ABILITY_NONE) {
            possibleAbilities[increment] = i;
            increment++;
        }
    }

    return possibleAbilities[RandomUniform(RNG_NONE, 1, increment) - 1];
}

const u32 blockedHoldEffects[] =
{
    HOLD_EFFECT_NONE,
    HOLD_EFFECT_REPEL,
    HOLD_EFFECT_SOUL_DEW,
    HOLD_EFFECT_DEEP_SEA_TOOTH,
    HOLD_EFFECT_DEEP_SEA_SCALE,
    HOLD_EFFECT_LIGHT_BALL,
    HOLD_EFFECT_THICK_CLUB,
    HOLD_EFFECT_LEEK,
    HOLD_EFFECT_ADAMANT_ORB,
    HOLD_EFFECT_LUSTROUS_ORB,
    HOLD_EFFECT_GRISEOUS_ORB,
    HOLD_EFFECT_ENIGMA_BERRY,
    HOLD_EFFECT_PLATE,
    HOLD_EFFECT_DRIVE,
    HOLD_EFFECT_GEMS,
    HOLD_EFFECT_MEGA_STONE,
    HOLD_EFFECT_PRIMAL_ORB,
    HOLD_EFFECT_MEMORY,
    HOLD_EFFECT_Z_CRYSTAL,
    HOLD_EFFECT_BOOSTER_ENERGY,
    HOLD_EFFECT_OGERPON_MASK,
};

static bool32 IsItemBlocked(u32 item)
{
    u32 itemHoldEffect = GetItemHoldEffect(item);

    if (GetItemImportance(item))
        return TRUE;

    for (u32 holdIndex = 0; holdIndex < ARRAY_COUNT(blockedHoldEffects); holdIndex++)
        if (itemHoldEffect == blockedHoldEffects[holdIndex])
            return TRUE;

    return FALSE;
}

static u32 GenerateSurpriseTradeItem(u32 species)
{
    if (!WT_ITEMS)
        return ITEM_NONE;

    u32 item = ITEM_NONE;

    if (WT_SPECIES_SPECIFIC_ITEMS) {

        u32 possibleSpeciesItems[18];
        u32 itemCount = 0;
        u32 baseSpecies = GET_BASE_SPECIES_ID(species);

        switch (baseSpecies) {
            case SPECIES_PICHU:
            case SPECIES_PIKACHU:
            case SPECIES_RAICHU:
                possibleSpeciesItems[itemCount] = ITEM_LIGHT_BALL;
                itemCount++;
                break;
            case SPECIES_CUBONE:
            case SPECIES_MAROWAK:
                possibleSpeciesItems[itemCount] = ITEM_THICK_CLUB;
                itemCount++;
                break;
            case SPECIES_FARFETCHD:
            case SPECIES_SIRFETCHD:
                possibleSpeciesItems[itemCount] = ITEM_LEEK;
                itemCount++;
                break;
            case SPECIES_CLAMPERL:
                possibleSpeciesItems[itemCount] = ITEM_DEEP_SEA_SCALE;
                itemCount++;
                possibleSpeciesItems[itemCount] = ITEM_DEEP_SEA_TOOTH;
                itemCount++;
                break;
            case SPECIES_DIALGA:
                possibleSpeciesItems[itemCount] = ITEM_ADAMANT_ORB;
                itemCount++;
                possibleSpeciesItems[itemCount] = ITEM_ADAMANT_CRYSTAL;
                itemCount++;
                break;
            case SPECIES_PALKIA:
                possibleSpeciesItems[itemCount] = ITEM_LUSTROUS_ORB;
                itemCount++;
                possibleSpeciesItems[itemCount] = ITEM_LUSTROUS_GLOBE;
                itemCount++;
                break;
            case SPECIES_GIRATINA:
                possibleSpeciesItems[itemCount] = ITEM_GRISEOUS_ORB;
                itemCount++;
                possibleSpeciesItems[itemCount] = ITEM_GRISEOUS_CORE;
                itemCount++;
                break;
            case SPECIES_HAPPINY:
            case SPECIES_CHANSEY:
            case SPECIES_BLISSEY:
                possibleSpeciesItems[itemCount] = ITEM_LUCKY_PUNCH;
                itemCount++;
                break;
            case SPECIES_DITTO:
                possibleSpeciesItems[itemCount] = ITEM_METAL_POWDER;
                itemCount++;
                possibleSpeciesItems[itemCount] = ITEM_QUICK_POWDER;
                itemCount++;
                break;
            case SPECIES_LATIOS:
            case SPECIES_LATIAS:
                possibleSpeciesItems[itemCount] = ITEM_SOUL_DEW;
                itemCount++;
                break;
            case SPECIES_KYOGRE:
                possibleSpeciesItems[itemCount] = ITEM_BLUE_ORB;
                itemCount++;
                break;
            case SPECIES_GROUDON:
                possibleSpeciesItems[itemCount] = ITEM_RED_ORB;
                itemCount++;
                break;
            case SPECIES_ZACIAN:
                possibleSpeciesItems[itemCount] = ITEM_RUSTED_SWORD;
                itemCount++;
                break;
            case SPECIES_ZAMAZENTA:
                possibleSpeciesItems[itemCount] = ITEM_RUSTED_SHIELD;
                itemCount++;
                break;
            case SPECIES_GENESECT:
                for (u32 i = ITEM_DOUSE_DRIVE; i <= ITEM_CHILL_DRIVE; i++) {
                    possibleSpeciesItems[itemCount] = i;
                    itemCount++;
                }
                break;
            case SPECIES_TYPE_NULL:
            case SPECIES_SILVALLY:
                for (u32 i = ITEM_FIRE_MEMORY; i <= ITEM_FAIRY_MEMORY; i++) {
                    possibleSpeciesItems[itemCount] = i;
                    itemCount++;
                }
                break;
            case SPECIES_ARCEUS:
                for (u32 i = ITEM_FLAME_PLATE; i <= ITEM_PIXIE_PLATE; i++) {
                    possibleSpeciesItems[itemCount] = i;
                    itemCount++;
                }
                break;
            default:
                break;
        }

        if (WT_SPECIES_SPECIFIC_MEGA_STONES) {
            const struct FormChange *formChanges = GetSpeciesFormChanges(species);
            for (u32 i = 0; formChanges != NULL && formChanges[i].method != FORM_CHANGE_TERMINATOR; i++) {
                if (formChanges[i].method == FORM_CHANGE_BATTLE_MEGA_EVOLUTION_ITEM) {
                    possibleSpeciesItems[itemCount] = formChanges[i].param1;
                    itemCount++;
                }
            }
        }
        
        if (WT_SPECIES_SPECIFIC_Z_CRYSTALS) {
            u32 speciesCrystal = GetSpeciesZItem(species);
            if (!speciesCrystal == ITEM_NONE) {
                possibleSpeciesItems[itemCount] = speciesCrystal;
                itemCount++;
            }
        }

        item = possibleSpeciesItems[RandomUniform(RNG_NONE, 1, itemCount) - 1];
    }

    if (!WT_CUSTOM_ITEMS && item == ITEM_NONE) {
        while (IsItemBlocked(item))
            item = Random() % ITEMS_COUNT;
    } else if (item == ITEM_NONE) {
        item = customWonderTradeItems[RandomUniform(RNG_NONE, 1, WT_NUM_CUSTOM_ITEMS) - 1];
    }

    return item;
}

static u32 GenerateSurpriseTradeBall(void)
{
    enum PokeBall ball = BALL_POKE;

    if (!WT_BALLS)
        return ball;

    while (ball == BALL_POKE)
        ball = Random() % POKEBALL_COUNT;

    return ball;
}

static bool32 ShouldMonBeShiny(u32 personality, u32 trainerId)
{
    u32 rerolls = 0;

    if (CheckBagHasItem(ITEM_SHINY_CHARM, 1))
        rerolls += I_SHINY_CHARM_ADDITIONAL_ROLLS;

    while (GET_SHINY_VALUE(trainerId, personality) >= SHINY_ODDS && rerolls > 0)
    {
        personality = Random32();
        rerolls--;
    }

    return GET_SHINY_VALUE(trainerId, personality) < SHINY_ODDS;
}

static u32 GetTotalBST(u32 species)
{
    return GetSpeciesBaseHP(species)
         + GetSpeciesBaseAttack(species)
         + GetSpeciesBaseDefense(species)
         + GetSpeciesBaseSpeed(species)
         + GetSpeciesBaseSpAttack(species)
         + GetSpeciesBaseSpDefense(species);
}
