#include "global.h"
#include "battle.h"
#include "dynamic_placeholder_text_util.h"
#include "event_object_movement.h"
#include "evolution_scene.h"
#include "field_weather.h"
#include "item.h"
#include "move.h"
#include "overworld.h"
#include "party_menu.h"
#include "pokemon.h"
#include "rtc.h"
#include "regions.h"
#include "region_map.h"
#include "string_util.h"


static bool32 IfGender_IsConditionMet(struct BoxPokemon *boxmon, struct EvolutionData *evo, const struct EvolutionParam *param)
{
    return (GetBoxMonGender(boxmon) == param->arg1);
}

static void IfGender_AppendParamString(u8 *dst, const struct EvolutionParam *param)
{
    if (param->arg1 == MON_MALE)
        StringAppend(dst, COMPOUND_STRING("Male"));
    else if (param->arg1 == MON_MALE)
        StringAppend(dst, COMPOUND_STRING("Female"));
    else
        errorf("Unknown gender value %d as IF_GENDER evo param", param->arg1);
}

static bool32 IfTime_IsConditionMet(struct BoxPokemon *boxmon, struct EvolutionData *evo, const struct EvolutionParam *param)
{
    return (GetTimeOfDay() == param->arg1);
}

static void IfTime_AppendParamString(u8 *dst, const struct EvolutionParam *param)
{
    if (param->arg1 == TIME_MORNING)
        StringAppend(dst, COMPOUND_STRING("Morning"));
    else if (param->arg1 == TIME_DAY)
        StringAppend(dst, COMPOUND_STRING("Day"));
    else if (param->arg1 == TIME_EVENING)
        StringAppend(dst, COMPOUND_STRING("Evening"));
    else if (param->arg1 == TIME_NIGHT)
        StringAppend(dst, COMPOUND_STRING("Night"));
    else
        errorf("Unknown gender value %d as IF_TIME evo param", param->arg1);
}

static bool32 IfNotTime_IsConditionMet(struct BoxPokemon *boxmon, struct EvolutionData *evo, const struct EvolutionParam *param)
{
    return (GetTimeOfDay() == param->arg1);
}

static void IfNotTime_AppendParamString(u8 *dst, const struct EvolutionParam *param)
{
    if (param->arg1 == TIME_MORNING)
        StringAppend(dst, COMPOUND_STRING("NOT Morning"));
    else if (param->arg1 == TIME_DAY)
        StringAppend(dst, COMPOUND_STRING("NOT Day"));
    else if (param->arg1 == TIME_EVENING)
        StringAppend(dst, COMPOUND_STRING("NOT Evening"));
    else if (param->arg1 == TIME_NIGHT)
        StringAppend(dst, COMPOUND_STRING("NOT Night"));
    else
        errorf("Unknown gender value %d as IF_NOT_TIME evo param", param->arg1);
}
/*
static bool32 IfMinFriendship_IsConditionMet(struct BoxPokemon *boxmon, struct EvolutionData *evo, const struct EvolutionParam *param)
{
    return (GetBoxMonData(boxmon, MON_DATA_FRIENDSHIP) >= param->arg1);
}

static void IfMinFriendship_AppendParamString(u8 *dst, const struct EvolutionParam *param)
{
    StringAppend(dst, COMPOUND_STRING("{UP_ARROW_2}friendship"));
}
*/
static bool32 IfAtkGtDef_IsConditionMet(struct BoxPokemon *boxmon, struct EvolutionData *evo, const struct EvolutionParam *param)
{
    return (CompareBoxmonAttackDefense(boxmon) == 1);
}

static void IfAtkGtDef_AppendParamString(u8 *dst, const struct EvolutionParam *param)
{
    StringAppend(dst, COMPOUND_STRING("Atk > Def"));
}

static bool32 IfAtkEqDef_IsConditionMet(struct BoxPokemon *boxmon, struct EvolutionData *evo, const struct EvolutionParam *param)
{
    return (CompareBoxmonAttackDefense(boxmon) == 0);
}

static void IfAtkEqDef_AppendParamString(u8 *dst, const struct EvolutionParam *param)
{
    StringAppend(dst, COMPOUND_STRING("Atk == Def"));
}

static bool32 IfAtkLtDef_IsConditionMet(struct BoxPokemon *boxmon, struct EvolutionData *evo, const struct EvolutionParam *param)
{
    return (CompareBoxmonAttackDefense(boxmon) == -1);
}

static void IfAtkLtDef_AppendParamString(u8 *dst, const struct EvolutionParam *param)
{
    StringAppend(dst, COMPOUND_STRING("Atk < Def"));
}

static bool32 IfHoldItem_IsConditionMet(struct BoxPokemon *boxmon, struct EvolutionData *evo, const struct EvolutionParam *param)
{
    evo->cannotStopEvo = TRUE;
    return (GetBoxMonData(boxmon, MON_DATA_HELD_ITEM) == param->arg1);
}

static void IfHoldItem_AfterEvolutionCallback(struct BoxPokemon *boxmon, bool32 wasInterrupted, const struct EvolutionParam *param)
{
    enum Item item = ITEM_NONE;
    SetBoxMonData(boxmon, MON_DATA_HELD_ITEM, &item);
}

static void IfHoldItem_AppendParamString(u8 *dst, const struct EvolutionParam *param)
{
    DynamicPlaceholderTextUtil_SetPlaceholderPtr(0, GetItemName(param->arg1));
    DynamicPlaceholderTextUtil_AppendExpandedPlaceholders(dst, COMPOUND_STRING("holds {DYNAMIC 0}"));
}

static bool32 IfPid10GreaterThan_IsConditionMet(struct BoxPokemon *boxmon, struct EvolutionData *evo, const struct EvolutionParam *param)
{
    u32 upperPersonality = GetBoxMonData(boxmon, MON_DATA_PERSONALITY) >> 16;
    return ((upperPersonality % 10) > param->arg1);
}

static void IfPid10GreaterThan_AppendParamString(u8 *dst, const struct EvolutionParam *param)
{
    u8 numericStr[5];
    u32 arg;
    if (param->arg1 < 10 && param->arg1 >= 0)
    {
        arg = 9 - param->arg1;
        ConvertIntToDecimalStringN(numericStr, arg * 10, STR_CONV_MODE_LEFT_ALIGN, 3);
        DynamicPlaceholderTextUtil_SetPlaceholderPtr(0, numericStr);
        DynamicPlaceholderTextUtil_AppendExpandedPlaceholders(dst, COMPOUND_STRING("{DYNAMIC 0}% chance"));
    }
    else
    {
        errorf("Inavlid value %d for IF_PID_UPPER_MODULO_10_GT evo param", param->arg1);
        StringAppend(dst, COMPOUND_STRING("?? chance"));
    }
}

static bool32 IfPid10LowerThan_IsConditionMet(struct BoxPokemon *boxmon, struct EvolutionData *evo, const struct EvolutionParam *param)
{
    u32 upperPersonality = GetBoxMonData(boxmon, MON_DATA_PERSONALITY) >> 16;
    return ((upperPersonality % 10) < param->arg1);
}

static void IfPid10LowerThan_AppendParamString(u8 *dst, const struct EvolutionParam *param)
{
    u8 numericStr[5];
    u32 arg;
    if (param->arg1 < 10 && param->arg1 >= 0)
    {
        arg = param->arg1;
        ConvertIntToDecimalStringN(numericStr, arg * 10, STR_CONV_MODE_LEFT_ALIGN, 3);
        DynamicPlaceholderTextUtil_SetPlaceholderPtr(0, numericStr);
        DynamicPlaceholderTextUtil_AppendExpandedPlaceholders(dst, COMPOUND_STRING("{DYNAMIC 0}% chance"));
    }
    else
    {
        errorf("Inavlid value %d for IF_PID_UPPER_MODULO_10_LT evo param", param->arg1);
        StringAppend(dst, COMPOUND_STRING("?? chance"));
    }
}

static bool32 IfPid10Equal_IsConditionMet(struct BoxPokemon *boxmon, struct EvolutionData *evo, const struct EvolutionParam *param)
{
    u32 upperPersonality = GetBoxMonData(boxmon, MON_DATA_PERSONALITY) >> 16;
    return ((upperPersonality % 10) == param->arg1);
}

static void IfPid10Equal_AppendParamString(u8 *dst, const struct EvolutionParam *param)
{
    StringAppend(dst, COMPOUND_STRING("10% chance"));
}

#define MIN_MON_DATA_EVO_PARAM(mon_data, label1, label2)                                                                                    \
static bool32 IfMin## label1 ##_IsConditionMet(struct BoxPokemon *boxmon, struct EvolutionData *evo, const struct EvolutionParam *param)    \
{                                                                                                                                           \
    return (GetBoxMonData(boxmon, mon_data) >= param->arg1);                                                                                 \
}                                                                                                                                           \
static void IfMin## label1 ##_AppendParamString(u8 *dst, const struct EvolutionParam *param)    \
{                                                                                                                                           \
    StringAppend(dst, COMPOUND_STRING("{UP_ARROW_2}" #label2));                                                                                 \
}

MIN_MON_DATA_EVO_PARAM(MON_DATA_FRIENDSHIP, Friendship, friendship)
MIN_MON_DATA_EVO_PARAM(MON_DATA_BEAUTY,     Beauty,     beauty)
MIN_MON_DATA_EVO_PARAM(MON_DATA_COOL,       Coolness,   coolness)
MIN_MON_DATA_EVO_PARAM(MON_DATA_SMART,      Smartness,  smartness)
MIN_MON_DATA_EVO_PARAM(MON_DATA_TOUGH,      Toughness,  toughness)
MIN_MON_DATA_EVO_PARAM(MON_DATA_CUTE,       Cuteness,   cuteness)

static bool32 IfSpeciesInParty_IsConditionMet(struct BoxPokemon *boxmon, struct EvolutionData *evo, const struct EvolutionParam *param)
{
    for (u32 i = 0; i < PARTY_SIZE; i++)
    {
        if (GetMonData(&gParties[B_TRAINER_PLAYER][i], MON_DATA_SPECIES) == param->arg1)
            return TRUE;
    }
    return FALSE;
}

static void IfSpeciesInParty_AppendParamString(u8 *dst, const struct EvolutionParam *param)
{
    DynamicPlaceholderTextUtil_SetPlaceholderPtr(0, GetSpeciesName(param->arg1));
    DynamicPlaceholderTextUtil_AppendExpandedPlaceholders(dst, COMPOUND_STRING("{DYNAMIC 0} in party"));
}

static bool32 IfInMap_IsConditionMet(struct BoxPokemon *boxmon, struct EvolutionData *evo, const struct EvolutionParam *param)
{
    return (param->arg1 == ((gSaveBlock1Ptr->location.mapGroup) << 8 | gSaveBlock1Ptr->location.mapNum));
}

static void IfInMap_AppendParamString(u8 *dst, const struct EvolutionParam *param)
{
    u32 regionMapId = Overworld_GetMapHeaderByGroupAndId(param->arg1 >> 8, param->arg1 & 0xFF)->regionMapSectionId;
    DynamicPlaceholderTextUtil_SetPlaceholderPtr(0, gRegionMapEntries[regionMapId].name);
    DynamicPlaceholderTextUtil_AppendExpandedPlaceholders(dst, COMPOUND_STRING("in {DYNAMIC 0}"));
}

static bool32 IfInMapSec_IsConditionMet(struct BoxPokemon *boxmon, struct EvolutionData *evo, const struct EvolutionParam *param)
{
    return (param->arg1 == gMapHeader.regionMapSectionId);
}

static void IfInMapSec_AppendParamString(u8 *dst, const struct EvolutionParam *param)
{
    DynamicPlaceholderTextUtil_SetPlaceholderPtr(0, gRegionMapEntries[param->arg1].name);
    DynamicPlaceholderTextUtil_AppendExpandedPlaceholders(dst, COMPOUND_STRING("in {DYNAMIC 0}"));
}

static bool32 IfKnowsMove_IsConditionMet(struct BoxPokemon *boxmon, struct EvolutionData *evo, const struct EvolutionParam *param)
{
    return (BoxMonKnowsMove(boxmon, param->arg1));
}

static void IfKnowsMove_AppendParamString(u8 *dst, const struct EvolutionParam *param)
{
    DynamicPlaceholderTextUtil_SetPlaceholderPtr(0, GetMoveName(param->arg1));
    DynamicPlaceholderTextUtil_AppendExpandedPlaceholders(dst, COMPOUND_STRING("knows {DYNAMIC 0}"));
}

static bool32 IfTradePartnerSpecies_IsConditionMet(struct BoxPokemon *boxmon, struct EvolutionData *evo, const struct EvolutionParam *param)
{
    if (GetItemHoldEffect(GetMonData(evo->tradePartner, MON_DATA_HELD_ITEM)) == HOLD_EFFECT_PREVENT_EVOLVE)
        return FALSE;
    return (param->arg1 == GetMonData(evo->tradePartner, MON_DATA_SPECIES));
}

static void IfTradePartnerSpecies_AppendParamString(u8 *dst, const struct EvolutionParam *param)
{
    DynamicPlaceholderTextUtil_SetPlaceholderPtr(0, GetSpeciesName(param->arg1));
    DynamicPlaceholderTextUtil_AppendExpandedPlaceholders(dst, COMPOUND_STRING("traded with {DYNAMIC 0}"));
}

static bool32 IfTypeInParty_IsConditionMet(struct BoxPokemon *boxmon, struct EvolutionData *evo, const struct EvolutionParam *param)
{
    for (u32 i = 0; i < PARTY_SIZE; i++)
    {
        enum Species currSpecies = GetMonData(&gParties[B_TRAINER_PLAYER][i], MON_DATA_SPECIES);
        if (SpeciesHasType(currSpecies, param->arg1))
            return TRUE;
    }
    return FALSE;
}

static void IfTypeInParty_AppendParamString(u8 *dst, const struct EvolutionParam *param)
{
    DynamicPlaceholderTextUtil_SetPlaceholderPtr(0, gTypesInfo[param->arg1].name);
    DynamicPlaceholderTextUtil_AppendExpandedPlaceholders(dst, COMPOUND_STRING("{DYNAMIC 0}-type in party"));
}

static bool32 IfWeather_IsConditionMet(struct BoxPokemon *boxmon, struct EvolutionData *evo, const struct EvolutionParam *param)
{
    u32 weather = GetCurrentWeather();
    if (param->arg1 == WEATHER_RAIN)
    {
        if (weather == WEATHER_RAIN || weather == WEATHER_RAIN_THUNDERSTORM || weather == WEATHER_DOWNPOUR)
            return TRUE;
    }
    else if (param->arg1 == WEATHER_FOG)
    {
        if (weather == WEATHER_FOG_DIAGONAL || weather == WEATHER_FOG_HORIZONTAL)
            return TRUE;
    }
    else if (param->arg1 == weather)
    {
        return TRUE;
    }
    return FALSE;
}

static void IfWeather_AppendParamString(u8 *dst, const struct EvolutionParam *param)
{
    DynamicPlaceholderTextUtil_SetPlaceholderPtr(0, GetWeatherName(param->arg1));
    DynamicPlaceholderTextUtil_AppendExpandedPlaceholders(dst, COMPOUND_STRING("weather {DYNAMIC 0}"));
}

static bool32 IfKnowsMoveType_IsConditionMet(struct BoxPokemon *boxmon, struct EvolutionData *evo, const struct EvolutionParam *param)
{
    for (u32 i = 0; i < MAX_MON_MOVES; i++)
    {
        if (param->arg1 == GetMoveType(GetBoxMonData(boxmon, MON_DATA_MOVE1 + i)))
            return TRUE;
    }
    return FALSE;
}

static void IfKnowsMoveType_AppendParamString(u8 *dst, const struct EvolutionParam *param)
{
    DynamicPlaceholderTextUtil_SetPlaceholderPtr(0, gTypesInfo[param->arg1].name);
    DynamicPlaceholderTextUtil_AppendExpandedPlaceholders(dst, COMPOUND_STRING("has {DYNAMIC 0}-type move"));
}

static bool32 IfNature_IsConditionMet(struct BoxPokemon *boxmon, struct EvolutionData *evo, const struct EvolutionParam *param)
{
    return (param->arg1 == GetNatureFromPersonality(GetBoxMonData(boxmon, MON_DATA_PERSONALITY)));
}

static void IfNature_AppendParamString(u8 *dst, const struct EvolutionParam *param)
{
    DynamicPlaceholderTextUtil_SetPlaceholderPtr(0, gNaturesInfo[param->arg1].name);
    DynamicPlaceholderTextUtil_AppendExpandedPlaceholders(dst, COMPOUND_STRING("{DYNAMIC 0} nature"));
}

static const u8 sAmpedNaturesList[] = {
    NATURE_HARDY,
    NATURE_BRAVE,
    NATURE_ADAMANT,
    NATURE_NAUGHTY,
    NATURE_DOCILE,
    NATURE_IMPISH,
    NATURE_LAX,
    NATURE_HASTY,
    NATURE_JOLLY,
    NATURE_NAIVE,
    NATURE_RASH,
    NATURE_SASSY,
    NATURE_QUIRKY,
};

static const u8 sLowKeyNaturesList[] = {
    NATURE_LONELY,
    NATURE_BOLD,
    NATURE_RELAXED,
    NATURE_TIMID,
    NATURE_SERIOUS,
    NATURE_MODEST,
    NATURE_MILD,
    NATURE_QUIET,
    NATURE_BASHFUL,
    NATURE_CALM,
    NATURE_GENTLE,
    NATURE_CAREFUL,
};

static bool32 IfAmpedNature_IsConditionMet(struct BoxPokemon *boxmon, struct EvolutionData *evo, const struct EvolutionParam *param)
{
    u32 nature = GetNatureFromPersonality(GetBoxMonData(boxmon, MON_DATA_PERSONALITY));
    for (u32 i = 0; i < ARRAY_COUNT(sAmpedNaturesList); i++)
    {
        if (nature == sAmpedNaturesList[i])
            return TRUE;
    }
    return FALSE;
}

static void IfAmpedNature_AppendParamString(u8 *dst, const struct EvolutionParam *param)
{
    StringAppend(dst, COMPOUND_STRING("amped natures"));
}

static bool32 IfLowKeyNature_IsConditionMet(struct BoxPokemon *boxmon, struct EvolutionData *evo, const struct EvolutionParam *param)
{
    u32 nature = GetNatureFromPersonality(GetBoxMonData(boxmon, MON_DATA_PERSONALITY));
    for (u32 i = 0; i < ARRAY_COUNT(sLowKeyNaturesList) ; i++)
    {
        if (nature == sLowKeyNaturesList[i])
            return TRUE;
    }
    return FALSE;
}

static void IfLowKeyNature_AppendParamString(u8 *dst, const struct EvolutionParam *param)
{
    StringAppend(dst, COMPOUND_STRING("low-key natures"));
}

static bool32 IfRecoilDamageGe_IsConditionMet(struct BoxPokemon *boxmon, struct EvolutionData *evo, const struct EvolutionParam *param)
{
    return (GetBoxMonData(boxmon, MON_DATA_EVOLUTION_TRACKER) >= param->arg1);
}

static void IfRecoilDamageGe_AppendParamString(u8 *dst, const struct EvolutionParam *param)
{
    u8 numericStr[5];
    ConvertIntToDecimalStringN(numericStr, param->arg1, STR_CONV_MODE_LEFT_ALIGN, 3);
    DynamicPlaceholderTextUtil_SetPlaceholderPtr(0, numericStr);
    StringAppend(dst, COMPOUND_STRING("takes >= {DYNAMIC 0} recoil damage"));
}

static bool32 IfCurrentDamageGe_IsConditionMet(struct BoxPokemon *boxmon, struct EvolutionData *evo, const struct EvolutionParam *param)
{
    return (GetBoxMonCurrentDamage(boxmon) >= param->arg1);
}

static void IfCurrentDamageGe_AppendParamString(u8 *dst, const struct EvolutionParam *param)
{
    u8 numericStr[5];
    ConvertIntToDecimalStringN(numericStr, param->arg1, STR_CONV_MODE_LEFT_ALIGN, 3);
    DynamicPlaceholderTextUtil_SetPlaceholderPtr(0, numericStr);
    StringAppend(dst, COMPOUND_STRING("{DYNAMIC 0} current damage"));
}

static bool32 IfCriticalHitsGe_IsConditionMet(struct BoxPokemon *boxmon, struct EvolutionData *evo, const struct EvolutionParam *param)
{
    u32 partyId = GetPartyIndexFromBoxMonPointer(boxmon);
    if (partyId < PARTY_SIZE && gPartyCriticalHits[partyId] >= param->arg1)
        return TRUE;
    return FALSE;
}

static void IfCriticalHitsGe_AppendParamString(u8 *dst, const struct EvolutionParam *param)
{
    u8 numericStr[5];
    ConvertIntToDecimalStringN(numericStr, param->arg1, STR_CONV_MODE_LEFT_ALIGN, 3);
    DynamicPlaceholderTextUtil_SetPlaceholderPtr(0, numericStr);
    StringAppend(dst, COMPOUND_STRING("{DYNAMIC 0} critical hits"));
}

static bool32 IfUsedMoveXTimes_IsConditionMet(struct BoxPokemon *boxmon, struct EvolutionData *evo, const struct EvolutionParam *param)
{
    return (GetBoxMonData(boxmon, MON_DATA_EVOLUTION_TRACKER) >= param->arg2);
}

static void IfUsedMoveXTimes_AppendParamString(u8 *dst, const struct EvolutionParam *param)
{
    u8 numericStr[5];
    DynamicPlaceholderTextUtil_SetPlaceholderPtr(0, GetMoveName(param->arg1));
    ConvertIntToDecimalStringN(numericStr, param->arg2, STR_CONV_MODE_LEFT_ALIGN, 3);
    DynamicPlaceholderTextUtil_SetPlaceholderPtr(1, numericStr);
    StringAppend(dst, COMPOUND_STRING("use {DYNAMIC 0} {DYNAMIC 1} times"));
}

static bool32 IfDefeatXWithItems_IsConditionMet(struct BoxPokemon *boxmon, struct EvolutionData *evo, const struct EvolutionParam *param)
{
    return (GetBoxMonData(boxmon, MON_DATA_EVOLUTION_TRACKER) >= param->arg3);
}

static void IfDefeatXWithItems_AppendParamString(u8 *dst, const struct EvolutionParam *param)
{
    u8 numericStr[5];
    ConvertIntToDecimalStringN(numericStr, param->arg3, STR_CONV_MODE_LEFT_ALIGN, 3);
    DynamicPlaceholderTextUtil_SetPlaceholderPtr(0, numericStr);
    DynamicPlaceholderTextUtil_SetPlaceholderPtr(1, GetSpeciesName(param->arg1));
    DynamicPlaceholderTextUtil_SetPlaceholderPtr(2, GetItemName(param->arg2));
    StringAppend(dst, COMPOUND_STRING("defeat {DYNAMIC 0} {DYNAMIC 1} that hold {DYNAMIC 2}"));
}

static bool32 IfPid100GreaterThan_IsConditionMet(struct BoxPokemon *boxmon, struct EvolutionData *evo, const struct EvolutionParam *param)
{
    return ((GetBoxMonData(boxmon, MON_DATA_PERSONALITY) % 100) > param->arg1);
}

static void IfPid100GreaterThan_AppendParamString(u8 *dst, const struct EvolutionParam *param)
{
    u8 numericStr[5];
    u32 arg;
    if (param->arg1 < 100 && param->arg1 >= 0)
    {
        arg = 99 - param->arg1;
        ConvertIntToDecimalStringN(numericStr, arg, STR_CONV_MODE_LEFT_ALIGN, 3);
        DynamicPlaceholderTextUtil_SetPlaceholderPtr(0, numericStr);
        DynamicPlaceholderTextUtil_AppendExpandedPlaceholders(dst, COMPOUND_STRING("{DYNAMIC 0}% chance"));
    }
    else
    {
        errorf("Inavlid value %d for IF_PID_MODULO_100_GT evo param", param->arg1);
        StringAppend(dst, COMPOUND_STRING("??% chance"));
    }
}

static bool32 IfPid100LowerThan_IsConditionMet(struct BoxPokemon *boxmon, struct EvolutionData *evo, const struct EvolutionParam *param)
{
    return ((GetBoxMonData(boxmon, MON_DATA_PERSONALITY) % 100) < param->arg1);
}

static void IfPid100LowerThan_AppendParamString(u8 *dst, const struct EvolutionParam *param)
{
    u8 numericStr[5];
    u32 arg;
    if (param->arg1 < 100 && param->arg1 >= 0)
    {
        arg = param->arg1;
        ConvertIntToDecimalStringN(numericStr, arg, STR_CONV_MODE_LEFT_ALIGN, 3);
        DynamicPlaceholderTextUtil_SetPlaceholderPtr(0, numericStr);
        DynamicPlaceholderTextUtil_AppendExpandedPlaceholders(dst, COMPOUND_STRING("{DYNAMIC 0}% chance"));
    }
    else
    {
        errorf("Inavlid value %d for IF_PID_MODULO_100_LT evo param", param->arg1);
        StringAppend(dst, COMPOUND_STRING("??% chance"));
    }
}

static bool32 IfPid100Equal_IsConditionMet(struct BoxPokemon *boxmon, struct EvolutionData *evo, const struct EvolutionParam *param)
{
    return ((GetBoxMonData(boxmon, MON_DATA_PERSONALITY) % 100) == param->arg1);
}

static void IfPid100Equal_AppendParamString(u8 *dst, const struct EvolutionParam *param)
{
    StringAppend(dst, COMPOUND_STRING("1% chance"));
}

static bool32 IfMinOverworldSteps_IsConditionMet(struct BoxPokemon *boxmon, struct EvolutionData *evo, const struct EvolutionParam *param)
{
    struct Pokemon *follower = GetFirstLiveMon();
    return (OW_FOLLOWERS_ENABLED && boxmon == &follower->box && gFollowerSteps >= param->arg1);
}

static void IfMinOverworldSteps_AppendParamString(u8 *dst, const struct EvolutionParam *param)
{
    u8 numericStr[5];
    ConvertIntToDecimalStringN(numericStr, param->arg1, STR_CONV_MODE_LEFT_ALIGN, 4);
    DynamicPlaceholderTextUtil_SetPlaceholderPtr(0, numericStr);
    StringAppend(dst, COMPOUND_STRING("after following you for {DYNAMIC 0} steps"));
}

static bool32 IfBagItemCount_IsConditionMet(struct BoxPokemon *boxmon, struct EvolutionData *evo, const struct EvolutionParam *param)
{
    evo->cannotStopEvo = TRUE;
    return (CheckBagHasItem(param->arg1, param->arg2));
}

static void IfBagItemCount_AfterEvolutionCallback(struct BoxPokemon *boxmon, bool32 wasInterrupted, const struct EvolutionParam *param)
{
    RemoveBagItem(param->arg1, param->arg2);
}

static void IfBagItemCount_AppendParamString(u8 *dst, const struct EvolutionParam *param)
{
    u8 numericStr[5];
    ConvertIntToDecimalStringN(numericStr, param->arg2, STR_CONV_MODE_LEFT_ALIGN, 3);
    DynamicPlaceholderTextUtil_SetPlaceholderPtr(0, numericStr);
    DynamicPlaceholderTextUtil_SetPlaceholderPtr(1, GetSpeciesName(param->arg1));
    StringAppend(dst, COMPOUND_STRING("{DYNAMIC 0} {DYNAMIC 1} in bag"));
}

static bool32 IfRegion_IsConditionMet(struct BoxPokemon *boxmon, struct EvolutionData *evo, const struct EvolutionParam *param)
{
    return (param->arg1 == GetCurrentRegion());
}

static void IfRegion_AppendParamString(u8 *dst, const struct EvolutionParam *param)
{
    StringAppend(dst, COMPOUND_STRING("in "));
    switch ((enum Region)param->arg1)
    {
        case REGION_NONE:
        case REGIONS_COUNT:
            StringAppend(dst, COMPOUND_STRING("???"));
            break;
        case REGION_KANTO: StringAppend(dst, COMPOUND_STRING("Kanto")); break;
        case REGION_JOHTO: StringAppend(dst, COMPOUND_STRING("Johto")); break;
        case REGION_HOENN: StringAppend(dst, COMPOUND_STRING("Hoenn")); break;
        case REGION_SINNOH: StringAppend(dst, COMPOUND_STRING("Sinnoh")); break;
        case REGION_UNOVA: StringAppend(dst, COMPOUND_STRING("Unova")); break;
        case REGION_KALOS: StringAppend(dst, COMPOUND_STRING("Kalos")); break;
        case REGION_ALOLA: StringAppend(dst, COMPOUND_STRING("Alola")); break;
        case REGION_GALAR: StringAppend(dst, COMPOUND_STRING("Galar")); break;
        case REGION_HISUI: StringAppend(dst, COMPOUND_STRING("Hisui")); break;
        case REGION_PALDEA: StringAppend(dst, COMPOUND_STRING("Paldea")); break;
    }
}

static bool32 IfNotRegion_IsConditionMet(struct BoxPokemon *boxmon, struct EvolutionData *evo, const struct EvolutionParam *param)
{
    return (param->arg1 != GetCurrentRegion());
}

static void IfNotRegion_AppendParamString(u8 *dst, const struct EvolutionParam *param)
{
    StringAppend(dst, COMPOUND_STRING("out of "));
    switch ((enum Region)param->arg1)
    {
        case REGION_NONE:
        case REGIONS_COUNT:
            StringAppend(dst, COMPOUND_STRING("???"));
            break;
        case REGION_KANTO: StringAppend(dst, COMPOUND_STRING("Kanto")); break;
        case REGION_JOHTO: StringAppend(dst, COMPOUND_STRING("Johto")); break;
        case REGION_HOENN: StringAppend(dst, COMPOUND_STRING("Hoenn")); break;
        case REGION_SINNOH: StringAppend(dst, COMPOUND_STRING("Sinnoh")); break;
        case REGION_UNOVA: StringAppend(dst, COMPOUND_STRING("Unova")); break;
        case REGION_KALOS: StringAppend(dst, COMPOUND_STRING("Kalos")); break;
        case REGION_ALOLA: StringAppend(dst, COMPOUND_STRING("Alola")); break;
        case REGION_GALAR: StringAppend(dst, COMPOUND_STRING("Galar")); break;
        case REGION_HISUI: StringAppend(dst, COMPOUND_STRING("Hisui")); break;
        case REGION_PALDEA: StringAppend(dst, COMPOUND_STRING("Paldea")); break;
    }
}

struct EvoParamFunctions {
    bool32 (*IsConditionMet)(struct BoxPokemon *, struct EvolutionData *, const struct EvolutionParam *);
    void (*AfterEvolutionCallback)(struct BoxPokemon *, bool32, const struct EvolutionParam *);
    void (*AppendParamString)(u8 *, const struct EvolutionParam *);
};


static const struct EvoParamFunctions sEvolutionParams[CONDITIONS_END] = 
{
    [IF_GENDER] = {
        .IsConditionMet = IfGender_IsConditionMet,
        .AfterEvolutionCallback = NULL,
        .AppendParamString = IfGender_AppendParamString,
    },
    [IF_TIME] = {
        .IsConditionMet = IfTime_IsConditionMet,
        .AfterEvolutionCallback = NULL,
        .AppendParamString = IfTime_AppendParamString,
    },
    [IF_NOT_TIME] = {
        .IsConditionMet = IfNotTime_IsConditionMet,
        .AfterEvolutionCallback = NULL,
        .AppendParamString = IfNotTime_AppendParamString,
    },
    [IF_MIN_FRIENDSHIP] = {
        .IsConditionMet = IfMinFriendship_IsConditionMet,
        .AfterEvolutionCallback = NULL,
        .AppendParamString = IfMinFriendship_AppendParamString,
    },
    [IF_ATK_GT_DEF] = {
        .IsConditionMet = IfAtkGtDef_IsConditionMet,
        .AfterEvolutionCallback = NULL,
        .AppendParamString = IfAtkGtDef_AppendParamString,
    },
    [IF_ATK_EQ_DEF] = {
        .IsConditionMet = IfAtkEqDef_IsConditionMet,
        .AfterEvolutionCallback = NULL,
        .AppendParamString = IfAtkEqDef_AppendParamString,
    },
    [IF_ATK_LT_DEF] = {
        .IsConditionMet = IfAtkLtDef_IsConditionMet,
        .AfterEvolutionCallback = NULL,
        .AppendParamString = IfAtkLtDef_AppendParamString,
    },
    [IF_HOLD_ITEM] = {
        .IsConditionMet = IfHoldItem_IsConditionMet,
        .AfterEvolutionCallback = IfHoldItem_AfterEvolutionCallback,
        .AppendParamString = IfHoldItem_AppendParamString,
    },
    // Gen 3
    [IF_PID_UPPER_MODULO_10_GT] = {
        .IsConditionMet = IfPid10GreaterThan_IsConditionMet,
        .AfterEvolutionCallback = NULL,
        .AppendParamString = IfPid10GreaterThan_AppendParamString,
    },
    [IF_PID_UPPER_MODULO_10_EQ] = {
        .IsConditionMet = IfPid10Equal_IsConditionMet,
        .AfterEvolutionCallback = NULL,
        .AppendParamString = IfPid10Equal_AppendParamString,
    },
    [IF_PID_UPPER_MODULO_10_LT] = {
        .IsConditionMet = IfPid10LowerThan_IsConditionMet,
        .AfterEvolutionCallback = NULL,
        .AppendParamString = IfPid10LowerThan_AppendParamString,
    },
    [IF_MIN_BEAUTY] = {
        .IsConditionMet = IfMinBeauty_IsConditionMet,
        .AfterEvolutionCallback = NULL,
        .AppendParamString = IfMinBeauty_AppendParamString,
    },
    [IF_MIN_COOLNESS] = {
        .IsConditionMet = IfMinCoolness_IsConditionMet,
        .AfterEvolutionCallback = NULL,
        .AppendParamString = IfMinCoolness_AppendParamString,
    },
    [IF_MIN_SMARTNESS] = {
        .IsConditionMet = IfMinSmartness_IsConditionMet,
        .AfterEvolutionCallback = NULL,
        .AppendParamString = IfMinSmartness_AppendParamString,
    },
    [IF_MIN_TOUGHNESS] = {
        .IsConditionMet = IfMinToughness_IsConditionMet,
        .AfterEvolutionCallback = NULL,
        .AppendParamString = IfMinToughness_AppendParamString,
    },
    [IF_MIN_CUTENESS] = {
        .IsConditionMet = IfMinCuteness_IsConditionMet,
        .AfterEvolutionCallback = NULL,
        .AppendParamString = IfMinCuteness_AppendParamString,
    },
    // Gen 4
    [IF_SPECIES_IN_PARTY] = {
        .IsConditionMet = IfSpeciesInParty_IsConditionMet,
        .AfterEvolutionCallback = NULL,
        .AppendParamString = IfSpeciesInParty_AppendParamString,
    },
    [IF_IN_MAP] = {
        .IsConditionMet = IfInMap_IsConditionMet,
        .AfterEvolutionCallback = NULL,
        .AppendParamString = IfInMap_AppendParamString,
    },
    [IF_IN_MAPSEC] = {
        .IsConditionMet = IfInMapSec_IsConditionMet,
        .AfterEvolutionCallback = NULL,
        .AppendParamString = IfInMapSec_AppendParamString,
    },
    [IF_KNOWS_MOVE] = {
        .IsConditionMet = IfKnowsMove_IsConditionMet,
        .AfterEvolutionCallback = NULL,
        .AppendParamString = IfKnowsMove_AppendParamString,
    },
    // Gen 5
    [IF_TRADE_PARTNER_SPECIES] = {
        .IsConditionMet = IfTradePartnerSpecies_IsConditionMet,
        .AfterEvolutionCallback = NULL,
        .AppendParamString = IfTradePartnerSpecies_AppendParamString,
    },
    // Gen 6
    [IF_TYPE_IN_PARTY] = {
        .IsConditionMet = IfTypeInParty_IsConditionMet,
        .AfterEvolutionCallback = NULL,
        .AppendParamString = IfTypeInParty_AppendParamString,
    },
    [IF_WEATHER] = {
        .IsConditionMet = IfWeather_IsConditionMet,
        .AfterEvolutionCallback = NULL,
        .AppendParamString = IfWeather_AppendParamString,
    },
    [IF_KNOWS_MOVE_TYPE] = {
        .IsConditionMet = IfKnowsMoveType_IsConditionMet,
        .AfterEvolutionCallback = NULL,
        .AppendParamString = IfKnowsMoveType_AppendParamString,
    },
    // Gen 8
    [IF_NATURE] = {
        .IsConditionMet = IfNature_IsConditionMet,
        .AfterEvolutionCallback = NULL,
        .AppendParamString = IfNature_AppendParamString,
    },
    [IF_AMPED_NATURE] = {
        .IsConditionMet = IfAmpedNature_IsConditionMet,
        .AfterEvolutionCallback = NULL,
        .AppendParamString = IfAmpedNature_AppendParamString,
    },
    [IF_LOW_KEY_NATURE] = {
        .IsConditionMet = IfLowKeyNature_IsConditionMet,
        .AfterEvolutionCallback = NULL,
        .AppendParamString = IfLowKeyNature_AppendParamString,
    },
    [IF_RECOIL_DAMAGE_GE] = {
        .IsConditionMet = IfRecoilDamageGe_IsConditionMet,
        .AfterEvolutionCallback = NULL,
        .AppendParamString = IfRecoilDamageGe_AppendParamString,
    },
    [IF_CURRENT_DAMAGE_GE] = {
        .IsConditionMet = IfCurrentDamageGe_IsConditionMet,
        .AfterEvolutionCallback = NULL,
        .AppendParamString = IfCurrentDamageGe_AppendParamString,
    },
    [IF_CRITICAL_HITS_GE] = {
        .IsConditionMet = IfCriticalHitsGe_IsConditionMet,
        .AfterEvolutionCallback = NULL,
        .AppendParamString = IfCriticalHitsGe_AppendParamString,
    },
    [IF_USED_MOVE_X_TIMES] = {
        .IsConditionMet = IfUsedMoveXTimes_IsConditionMet,
        .AfterEvolutionCallback = NULL,
        .AppendParamString = IfUsedMoveXTimes_AppendParamString,
    },
    // Gen 9
    [IF_DEFEAT_X_WITH_ITEMS] = {
        .IsConditionMet = IfDefeatXWithItems_IsConditionMet,
        .AfterEvolutionCallback = NULL,
        .AppendParamString = IfDefeatXWithItems_AppendParamString,
    },
    [IF_PID_MODULO_100_GT] = {
        .IsConditionMet = IfPid100GreaterThan_IsConditionMet,
        .AfterEvolutionCallback = NULL,
        .AppendParamString = IfPid100GreaterThan_AppendParamString,
    },
    [IF_PID_MODULO_100_EQ] = {
        .IsConditionMet = IfPid100Equal_IsConditionMet,
        .AfterEvolutionCallback = NULL,
        .AppendParamString = IfPid100Equal_AppendParamString,
    },
    [IF_PID_MODULO_100_LT] = {
        .IsConditionMet = IfPid100LowerThan_IsConditionMet,
        .AfterEvolutionCallback = NULL,
        .AppendParamString = IfPid100LowerThan_AppendParamString,
    },
    [IF_MIN_OVERWORLD_STEPS] = {
        .IsConditionMet = IfMinOverworldSteps_IsConditionMet,
        .AfterEvolutionCallback = NULL,
        .AppendParamString = IfMinOverworldSteps_AppendParamString,
    },
    [IF_BAG_ITEM_COUNT] = {
        .IsConditionMet = IfBagItemCount_IsConditionMet,
        .AfterEvolutionCallback = IfBagItemCount_AfterEvolutionCallback,
        .AppendParamString = IfBagItemCount_AppendParamString,
    },
    [IF_REGION] = {
        .IsConditionMet = IfRegion_IsConditionMet,
        .AfterEvolutionCallback = NULL,
        .AppendParamString = IfRegion_AppendParamString,
    },
    [IF_NOT_REGION] = {
        .IsConditionMet = IfNotRegion_IsConditionMet,
        .AfterEvolutionCallback = NULL,
        .AppendParamString = IfNotRegion_AppendParamString,
    }
};

bool32 CheckEvolutionCondition(struct BoxPokemon *boxmon, struct EvolutionData *evo, const struct EvolutionParam *param)
{
    if (!sEvolutionParams[param->condition].IsConditionMet)
        return TRUE;
    return sEvolutionParams[param->condition].IsConditionMet(boxmon, evo, param);
}

void AppendEvoParamString(u8 *dst, const struct EvolutionParam *param)
{
    if (!sEvolutionParams[param->condition].AppendParamString)
        return;
    sEvolutionParams[param->condition].AppendParamString(dst, param);
}

void AfterEvolutionParamCallback(struct BoxPokemon *boxmon, bool32 wasInterrupted, const struct EvolutionParam *param)
{
    if (!sEvolutionParams[param->condition].AfterEvolutionCallback)
        return;
    sEvolutionParams[param->condition].AfterEvolutionCallback(boxmon, wasInterrupted, param);
}

