#include "global.h"
#include "malloc.h"
#include "battle.h"
#include "battle_message.h"
#include "bg.h"
#include "chooseboxmon.h"
#include "data.h"
#include "decompress.h"
#include "event_data.h"
#include "evolution_scene.h"
#include "evolution_graphics.h"
#include "gpu_regs.h"
#include "item.h"
#include "link.h"
#include "link_rfu.h"
#include "m4a.h"
#include "main.h"
#include "menu.h"
#include "overworld.h"
#include "palette.h"
#include "party_menu.h"
#include "pokedex.h"
#include "pokemon.h"
#include "pokemon_summary_screen.h"
#include "scanline_effect.h"
#include "sound.h"
#include "sprite.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "text.h"
#include "text_window.h"
#include "trig.h"
#include "trade.h"
#include "util.h"
#include "constants/battle_string_ids.h"
#include "constants/items.h"
#include "constants/party_menu.h"
#include "constants/rgb.h"
#include "constants/songs.h"

struct EvoScene
{
    struct EvolutionData data;
    u8 partyIndex;
    u8 preEvoSpriteId;
    u8 postEvoSpriteId;
    u8 evoTaskId;
    u8 delayTimer;
    bool8 isTradeEvo;
    u16 savedPalette[48];
};

static EWRAM_DATA struct EvoScene *sEvoStructPtr = NULL;
static EWRAM_DATA u16 *sBgAnimPal = NULL;

COMMON_DATA void (*gCB2_AfterEvolution)(void) = NULL;

#define sEvoCursorPos           gBattleCommunication[1] // when learning a new move
#define sEvoGraphicsTaskId      gBattleCommunication[2]

static void Task_BeginEvolutionScene(u8 taskId);
static void Task_EvolutionScene(u8 taskId);
static void CB2_EvolutionSceneUpdate(void);
static void EvoDummyFunc(void);
static void VBlankCB_EvolutionScene(void);
static void EvoScene_DoMonAnimAndCry(u8 monSpriteId, enum Species speciesId);
static bool32 EvoScene_IsMonAnimFinished(u8 monSpriteId);
static void StartBgAnimation(bool8 isLink);
static void StopBgAnimation(void);
static void Task_AnimateBg(u8 taskId);
static void RestoreBgAfterAnim(void);

static const u16 sUnusedPal1[] = INCGFX_U16("graphics/evolution_scene/unused_1.pal", ".gbapal");
static const u32 sBgAnim_Gfx[] = INCGFX_U32("graphics/evolution_scene/bg.png", ".4bpp.smol");
static const u32 sBgAnim_Inner_Tilemap[] = INCGFX_U32("graphics/evolution_scene/bg_inner.bin", ".smolTM");
static const u32 sBgAnim_Outer_Tilemap[] = INCGFX_U32("graphics/evolution_scene/bg_outer.bin", ".smolTM");
static const u16 sBgAnim_Intro_Pal[] = INCGFX_U16("graphics/evolution_scene/bg_anim_intro.pal", ".gbapal");
static const u16 sUnusedPal2[] = INCGFX_U16("graphics/evolution_scene/unused_2.pal", ".gbapal");
static const u16 sUnusedPal3[]  = INCGFX_U16("graphics/evolution_scene/unused_3.pal", ".gbapal");
static const u16 sUnusedPal4[] = INCGFX_U16("graphics/evolution_scene/unused_4.pal", ".gbapal");
static const u16 sBgAnim_Pal[] = INCGFX_U16("graphics/evolution_scene/bg_anim.pal", ".gbapal");

static const u8 sText_ShedinjaJapaneseName[] = _("ヌケニン");

// The below table is used by Task_UpdateBgPalette to control the speed at which the bg color updates.
// The first two values are indexes into sBgAnim_PalIndexes (indirectly, via sBgAnimPal), and are
// the start and end of the range of colors in sBgAnim_PalIndexes it will move through incrementally
// before starting over. It will repeat this cycle x number of times, where x = the 3rd value,
// delaying each increment by y, where y = the 4th value.
// Once it has cycled x number of times, it will move to the next array in this table.
static const u8 sBgAnim_PaletteControl[][4] =
{
    {  0, 12, 1, 6 },
    { 13, 36, 5, 2 },
    { 13, 24, 1, 2 },
    { 37, 49, 1, 6 },
};

// Indexes into sBgAnim_Pal, 0 is black, transitioning to a bright light blue (172, 213, 255) at 13
static const u8 sBgAnim_PalIndexes[][16] = {
    {  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0 },
    {  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  2,  0,  0 },
    {  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  2,  3,  0,  0 },
    {  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  2,  3,  4,  0,  0 },
    {  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  2,  3,  4,  5,  0,  0 },
    {  0,  0,  0,  0,  0,  0,  0,  0,  1,  2,  3,  4,  5,  6,  0,  0 },
    {  0,  0,  0,  0,  0,  0,  0,  1,  2,  3,  4,  5,  6,  7,  0,  0 },
    {  0,  0,  0,  0,  0,  0,  1,  2,  3,  4,  5,  6,  7,  8,  0,  0 },
    {  0,  0,  0,  0,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  0,  0 },
    {  0,  0,  0,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10,  0,  0 },
    {  0,  0,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  0, 11,  0,  0 },
    {  0,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12,  0,  0 },
    {  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13,  0,  0 },
    {  0,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 12,  0,  0 },
    {  0,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 12, 11,  0,  0 },
    {  0,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 12, 11, 10,  0,  0 },
    {  0,  5,  6,  7,  8,  9, 10, 11, 12, 13, 12, 11, 10,  9,  0,  0 },
    {  0,  6,  7,  8,  9, 10, 11, 12, 13, 12, 11, 10,  9,  8,  0,  0 },
    {  0,  7,  8,  9, 10, 11, 12, 13, 12, 11, 10,  9,  8,  7,  0,  0 },
    {  0,  8,  9, 10, 11, 12, 13, 12, 11, 10,  9,  8,  7,  6,  0,  0 },
    {  0,  9, 10, 11, 12, 13, 12, 11, 10,  9,  8,  7,  6,  5,  0,  0 },
    {  0, 10, 11, 12, 13, 12, 11, 10,  9,  8,  7,  6,  5,  4,  0,  0 },
    {  0, 11, 12, 13, 12, 11, 10,  9,  8,  7,  6,  5,  4,  3,  0,  0 },
    {  0, 12, 13, 12, 11, 10,  9,  8,  7,  6,  5,  4,  3,  2,  0,  0 },
    {  0, 13, 12, 11, 10,  9,  8,  7,  6,  5,  4,  3,  2,  1,  0,  0 },
    {  0, 12, 11, 10,  9,  8,  7,  6,  5,  4,  3,  2,  1,  2,  0,  0 },
    {  0, 11, 10,  9,  8,  7,  6,  5,  4,  3,  2,  1,  2,  3,  0,  0 },
    {  0, 10,  9,  8,  7,  6,  5,  4,  3,  2,  1,  2,  3,  4,  0,  0 },
    {  0,  9,  8,  7,  6,  5,  4,  3,  2,  1,  2,  3,  4,  5,  0,  0 },
    {  0,  8,  7,  6,  5,  4,  3,  2,  1,  2,  3,  4,  5,  6,  0,  0 },
    {  0,  7,  6,  5,  4,  3,  2,  1,  2,  3,  4,  5,  6,  7,  0,  0 },
    {  0,  6,  5,  4,  3,  2,  1,  2,  3,  4,  5,  6,  7,  8,  0,  0 },
    {  0,  5,  4,  3,  2,  1,  2,  3,  4,  5,  6,  7,  8,  9,  0,  0 },
    {  0,  4,  3,  2,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10,  0,  0 },
    {  0,  3,  2,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11,  0,  0 },
    {  0,  2,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12,  0,  0 },
    {  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13,  0,  0 },
    {  0, 12, 11, 10,  9,  8,  7,  6,  5,  4,  3,  2,  1,  0,  0,  0 },
    {  0, 11, 10,  9,  8,  7,  6,  5,  4,  3,  2,  1,  0,  0,  0,  0 },
    {  0, 10,  9,  8,  7,  6,  5,  4,  3,  2,  1,  0,  0,  0,  0,  0 },
    {  0,  9,  8,  7,  6,  5,  4,  3,  2,  1,  0,  0,  0,  0,  0,  0 },
    {  0,  8,  7,  6,  5,  4,  3,  2,  1,  0,  0,  0,  0,  0,  0,  0 },
    {  0,  7,  6,  5,  4,  3,  2,  1,  0,  0,  0,  0,  0,  0,  0,  0 },
    {  0,  6,  5,  4,  3,  2,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0 },
    {  0,  5,  4,  3,  2,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0 },
    {  0,  4,  3,  2,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0 },
    {  0,  3,  2,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0 },
    {  0,  2,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0 },
    {  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0 },
    {  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0 }
};

#include "field_weather.h"
#include "rtc.h"
#include "regions.h"
#include "event_object_movement.h"

bool32 DoesBoxMonMeetConditions(struct BoxPokemon *boxmon, struct EvolutionData *evo, const struct Evolution *conditions)
{
    u32 i, j;
    enum Item heldItem = GetBoxMonData(boxmon, MON_DATA_HELD_ITEM);
    u32 gender = GetBoxMonGender(boxmon);
    u32 friendship = GetBoxMonData(boxmon, MON_DATA_FRIENDSHIP);
    u32 personality = GetBoxMonData(boxmon, MON_DATA_PERSONALITY);
    u16 upperPersonality = personality >> 16;
    enum OverworldWeather weather;
    u32 nature = GetNatureFromPersonality(personality);
    u32 evolutionTracker = GetBoxMonData(boxmon, MON_DATA_EVOLUTION_TRACKER);
    enum Species partnerSpecies;
    enum Item partnerHeldItem;
    enum HoldEffect partnerHoldEffect;

    if (conditions->method == EVO_TRADE)
    {
        partnerSpecies = GetMonData(evo->tradePartner, MON_DATA_SPECIES);
        partnerHeldItem = GetMonData(evo->tradePartner, MON_DATA_HELD_ITEM);
        partnerHoldEffect = GetItemHoldEffect(partnerHeldItem);
    }
    else
    {
        partnerSpecies = SPECIES_NONE;
        partnerHeldItem = ITEM_NONE;
        partnerHoldEffect = HOLD_EFFECT_NONE;
    }

    switch(conditions->method)
    {
        case EVO_LEVEL:
        case EVO_LEVEL_BATTLE_ONLY:
            if (GetLevelFromBoxMonExp(boxmon) < conditions->param)
                return FALSE;
            break;
        case EVO_ITEM:
        case EVO_SCRIPT_TRIGGER:
        case EVO_SPIN:
            if (evo->param != conditions->param)
                return FALSE;
            break;
        default:
            break;
    }
    // Check for additional conditions (only if the primary method passes). Skips if there's no additional conditions.
    for (i = 0; conditions->params != NULL && conditions->params[i].condition != CONDITIONS_END; i++)
    {
        const struct EvolutionParam param = conditions->params[i];
        bool32 currentCondition = FALSE;

        switch (param.condition)
        {
        // Gen 2
        case IF_GENDER:
            if (gender == param.arg1)
                currentCondition = TRUE;
            break;
        case IF_MIN_FRIENDSHIP:
            if (friendship >= param.arg1)
                currentCondition = TRUE;
            break;
        case IF_ATK_GT_DEF:
            if (CompareBoxmonAttackDefense(boxmon) == 1)
                currentCondition = TRUE;
            break;
        case IF_ATK_EQ_DEF:
            if (CompareBoxmonAttackDefense(boxmon) == 0)
                currentCondition = TRUE;
            break;
        case IF_ATK_LT_DEF:
            if (CompareBoxmonAttackDefense(boxmon) == -1)
                currentCondition = TRUE;
            break;
        case IF_TIME:
            if (GetTimeOfDay() == param.arg1)
                currentCondition = TRUE;
            break;
        case IF_NOT_TIME:
            if (GetTimeOfDay() != param.arg1)
                currentCondition = TRUE;
            break;
        case IF_HOLD_ITEM:
            if (heldItem == param.arg1)
            {
                currentCondition = TRUE;
                evo->cannotStopEvo |= TRUE;
            }
            break;
        // Gen 3
        case IF_PID_UPPER_MODULO_10_GT:
            if ((upperPersonality % 10) > param.arg1)
                currentCondition = TRUE;
            break;
        case IF_PID_UPPER_MODULO_10_EQ:
            if ((upperPersonality % 10) == param.arg1)
                currentCondition = TRUE;
            break;
        case IF_PID_UPPER_MODULO_10_LT:
            if ((upperPersonality % 10) < param.arg1)
                currentCondition = TRUE;
            break;
        case IF_MIN_BEAUTY:
        {
            u32 beauty = GetBoxMonData(boxmon, MON_DATA_BEAUTY, 0);
            if (beauty >= param.arg1)
                currentCondition = TRUE;
            break;
        }
        case IF_MIN_COOLNESS:
        {
            u32 coolness = GetBoxMonData(boxmon, MON_DATA_COOL, 0);
            if (coolness >= param.arg1)
                currentCondition = TRUE;
            break;
        }
        case IF_MIN_SMARTNESS:
        // remember that even though it's called "Smart/Smartness" here,
        // from gen 6 and up it's known as "Clever/Cleverness."
        {
            u32 smartness = GetBoxMonData(boxmon, MON_DATA_SMART, 0);
            if (smartness >= param.arg1)
                currentCondition = TRUE;
            break;
        }
        case IF_MIN_TOUGHNESS:
        {
            u32 toughness = GetBoxMonData(boxmon, MON_DATA_TOUGH, 0);
            if (toughness >= param.arg1)
                currentCondition = TRUE;
            break;
        }
        case IF_MIN_CUTENESS:
        {
            u32 cuteness = GetBoxMonData(boxmon, MON_DATA_CUTE, 0);
            if (cuteness >= param.arg1)
                currentCondition = TRUE;
            break;
        }
        // Gen 4
        case IF_SPECIES_IN_PARTY:
            for (j = 0; j < PARTY_SIZE; j++)
            {
                if (GetMonData(&gParties[B_TRAINER_PLAYER][j], MON_DATA_SPECIES) == param.arg1)
                {
                    currentCondition = TRUE;
                    break;
                }
            }
            break;
        case IF_IN_MAP:
            if (param.arg1 == ((gSaveBlock1Ptr->location.mapGroup) << 8 | gSaveBlock1Ptr->location.mapNum))
                currentCondition = TRUE;
            break;
        case IF_IN_MAPSEC:
            if (gMapHeader.regionMapSectionId == param.arg1)
                currentCondition = TRUE;
            break;
        case IF_KNOWS_MOVE:
            if (BoxMonKnowsMove(boxmon, param.arg1))
                currentCondition = TRUE;
            break;
        // Gen 5
        case IF_TRADE_PARTNER_SPECIES:
            if (param.arg1 == partnerSpecies && partnerHoldEffect != HOLD_EFFECT_PREVENT_EVOLVE)
                currentCondition = TRUE;
            break;
        // Gen 6
        case IF_TYPE_IN_PARTY:
            for (j = 0; j < PARTY_SIZE; j++)
            {
                enum Species currSpecies = GetMonData(&gParties[B_TRAINER_PLAYER][j], MON_DATA_SPECIES);
                if (GetSpeciesType(currSpecies, 0) == param.arg1
                 || GetSpeciesType(currSpecies, 1) == param.arg1)
                {
                    currentCondition = TRUE;
                    break;
                }
            }
            break;
        case IF_WEATHER:
            weather = GetCurrentWeather();
            if (param.arg1 == WEATHER_RAIN)
            {
                if (weather == WEATHER_RAIN || weather == WEATHER_RAIN_THUNDERSTORM || weather == WEATHER_DOWNPOUR)
                    currentCondition = TRUE;
            }
            else if (param.arg1 == WEATHER_FOG)
            {
                if (weather == WEATHER_FOG_DIAGONAL || weather == WEATHER_FOG_HORIZONTAL)
                    currentCondition = TRUE;
            }
            else if (weather == param.arg1)
            {
                currentCondition = TRUE;
            }
            break;
        case IF_KNOWS_MOVE_TYPE:
            for (j = 0; j < MAX_MON_MOVES; j++)
            {
                if (GetMoveType(GetBoxMonData(boxmon, MON_DATA_MOVE1 + j)) == param.arg1)
                {
                    currentCondition = TRUE;
                    break;
                }
            }
            break;
        // Gen 8
        case IF_NATURE:
            if (nature == param.arg1)
                currentCondition = TRUE;
            break;
        case IF_AMPED_NATURE:
            switch (nature)
            {
            case NATURE_HARDY:
            case NATURE_BRAVE:
            case NATURE_ADAMANT:
            case NATURE_NAUGHTY:
            case NATURE_DOCILE:
            case NATURE_IMPISH:
            case NATURE_LAX:
            case NATURE_HASTY:
            case NATURE_JOLLY:
            case NATURE_NAIVE:
            case NATURE_RASH:
            case NATURE_SASSY:
            case NATURE_QUIRKY:
                currentCondition = TRUE;
                break;
            }
            break;
        case IF_LOW_KEY_NATURE:
            switch (nature)
            {
            case NATURE_LONELY:
            case NATURE_BOLD:
            case NATURE_RELAXED:
            case NATURE_TIMID:
            case NATURE_SERIOUS:
            case NATURE_MODEST:
            case NATURE_MILD:
            case NATURE_QUIET:
            case NATURE_BASHFUL:
            case NATURE_CALM:
            case NATURE_GENTLE:
            case NATURE_CAREFUL:
                currentCondition = TRUE;
                break;
            }
            break;
        case IF_RECOIL_DAMAGE_GE:
            if (evolutionTracker >= param.arg1)
                currentCondition = TRUE;
            break;
        case IF_CURRENT_DAMAGE_GE:
        {
            if (GetBoxMonCurrentDamage(boxmon) >= param.arg1)
                currentCondition = TRUE;
            break;
        }
        case IF_CRITICAL_HITS_GE:
            u32 partyId = GetPartyIndexFromBoxMonPointer(boxmon);
            if (partyId != PARTY_SIZE && gPartyCriticalHits[partyId] >= param.arg1)
                currentCondition = TRUE;
            break;
        case IF_USED_MOVE_X_TIMES:
            if (evolutionTracker >= param.arg2)
                currentCondition = TRUE;
            break;
        // Gen 9
        case IF_DEFEAT_X_WITH_ITEMS:
            if (evolutionTracker >= param.arg3)
                currentCondition = TRUE;
            break;
        case IF_PID_MODULO_100_GT:
            if ((personality % 100) > param.arg1)
                currentCondition = TRUE;
            break;
        case IF_PID_MODULO_100_EQ:
            if ((personality % 100) == param.arg1)
                currentCondition = TRUE;
            break;
        case IF_PID_MODULO_100_LT:
            if ((personality % 100) < param.arg1)
                currentCondition = TRUE;
            break;
        case IF_MIN_OVERWORLD_STEPS:
            struct Pokemon *follower = GetFirstLiveMon();
            if (OW_FOLLOWERS_ENABLED && boxmon == &follower->box && gFollowerSteps >= param.arg1)
                currentCondition = TRUE;
            break;
        case IF_BAG_ITEM_COUNT:
            if (CheckBagHasItem(param.arg1, param.arg2))
            {
                currentCondition = TRUE;
                evo->cannotStopEvo |= TRUE;
            }
            break;
        case IF_REGION:
            if (GetCurrentRegion() == param.arg1)
                currentCondition = TRUE;
            break;
        case IF_NOT_REGION:
            if (GetCurrentRegion() != param.arg1)
                currentCondition = TRUE;
            break;
        case CONDITIONS_END:
            break;
        }

        if (currentCondition == FALSE)
            return FALSE;
    }

    return TRUE;
}

struct EvolutionData InitTradeEvolutionData(struct Pokemon *mon)
{
    struct EvolutionData data;
    data.method = EVO_TRADE;
    data.tradePartner = mon;
    return data;
}


static bool32 AreEvoMethodsMatching(enum EvolutionMethods method, struct EvolutionData *evo)
{
    if (method == evo->method)
        return TRUE;
    if (method == EVO_LEVEL && evo->leveledUpInBattle)
        return TRUE;
    if (method == EVO_BATTLE_END && evo->method == EVO_BATTLE)
        return TRUE;
    if (method == EVO_LEVEL_BATTLE_ONLY && evo->method == EVO_BATTLE && evo->leveledUpInBattle)
        return TRUE;
    return FALSE;
}

enum Species GetEvolutionTargetSpecies(struct BoxPokemon *boxmon, struct EvolutionData *evo)
{
    enum Species targetSpecies = SPECIES_NONE;
    enum Species species = GetBoxMonData(boxmon, MON_DATA_SPECIES, 0);
    const struct Evolution *evolutions = GetSpeciesEvolutions(species);

    if (evolutions == NULL)
        return SPECIES_NONE;

    enum HoldEffect holdEffect = GetItemHoldEffect(GetBoxMonData(boxmon, MON_DATA_HELD_ITEM));
    if (holdEffect == HOLD_EFFECT_PREVENT_EVOLVE)
        return SPECIES_NONE;

    for (u32 i = 0; evolutions[i].method != EVOLUTIONS_END; i++)
    {
        if (!AreEvoMethodsMatching(evolutions[i].method, evo))
            continue;

        if (!DoesBoxMonMeetConditions(boxmon, evo, &evolutions[i]))
            continue;

        evo->evoIndex = i;

        assertf(targetSpecies == SPECIES_NONE, "pokemon %d has two competing evolutions")
        {
            return SPECIES_NONE;
        }
        targetSpecies = evolutions[i].targetSpecies;
    }

    // Pikachu, Meowth, Eevee and Duraludon cannot evolve if they have the
    // Gigantamax Factor. We assume that is because their evolutions
    // do not have a Gigantamax Form.
    if (GetBoxMonData(boxmon, MON_DATA_GIGANTAMAX_FACTOR)
     && GetGMaxTargetSpecies(species) != species
     && GetGMaxTargetSpecies(targetSpecies) == targetSpecies)
    {
        return SPECIES_NONE;
    }
    return targetSpecies;
}

static void CB2_BeginEvolutionScene(void)
{
    UpdatePaletteFade();
    RunTasks();
}

#define tState              data[0]
#define tPreEvoSpecies      data[1]
#define tPostEvoSpecies     data[2]
#define tLearnsetIndex  data[3]
#define tEvoWasStopped      data[4]
#define tLearnMoveTaskId    data[5]

bool32 TryEvolution(u32 partyIndex, struct EvolutionData *evo, u32 noFadeoutOrSpriteId)
{
    enum Species species = GetEvolutionTargetSpecies(GetBoxMonFromPartyIndex(partyIndex), evo);
    if (species == SPECIES_NONE)
        return FALSE;

    if (evo->method == EVO_ITEM || evo->method == EVO_TRADE)
        evo->cannotStopEvo |= TRUE;

    sEvoStructPtr = AllocZeroed(sizeof(struct EvoScene));
    memcpy(&sEvoStructPtr->data, evo, sizeof(struct EvolutionData));

    sEvoStructPtr->partyIndex = partyIndex;
    if (evo->method == EVO_TRADE)
    {
        sEvoStructPtr->isTradeEvo = TRUE;
        sEvoStructPtr->preEvoSpriteId = noFadeoutOrSpriteId;
    }
    else
    {
        sEvoStructPtr->isTradeEvo = FALSE;
    }
    u8 taskId = CreateTask(Task_BeginEvolutionScene, 0);
    if (sEvoStructPtr->isTradeEvo || noFadeoutOrSpriteId)
        gTasks[taskId].tState = 1;
    else
        gTasks[taskId].tState = 0;

    SetMainCallback2(CB2_BeginEvolutionScene);
    return TRUE;
}

static void Task_BeginEvolutionScene(u8 taskId)
{
    switch (gTasks[taskId].tState)
    {
    case 0:
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 0x10, RGB_BLACK);
        gTasks[taskId].tState++;
        break;
    case 1:
        if (!gPaletteFade.active)
        {
            if (sEvoStructPtr->isTradeEvo)
            {
                TradeEvolutionScene();
            }
            else
            {
                EvolutionScene();
            }
        }
        break;
    }
}

/*
void BeginEvolutionScene(struct Pokemon *mon, enum Species postEvoSpecies, bool32 canStopEvo, u8 partyId)
{
    u8 taskId = CreateTask(Task_BeginEvolutionScene, 0);
    gTasks[taskId].tState = 0;
    gTasks[taskId].tPostEvoSpecies = postEvoSpecies;
    gTasks[taskId].tCanStop = canStopEvo;
    gTasks[taskId].tPartyId = partyId;
    SetMainCallback2(CB2_BeginEvolutionScene);
}
*/

static void SetBattleBgs(void)
{
    gBattle_BG0_X = 0;
    gBattle_BG0_Y = 0;
    gBattle_BG1_X = 0;
    gBattle_BG1_Y = 0;
    gBattle_BG2_X = 0;
    gBattle_BG2_Y = 0;
    gBattle_BG3_X = 256;
    gBattle_BG3_Y = 0;
}

static void EvoScene_InitGraphics_Standard(void)
{
    CpuFill32(0, (void *)(VRAM), VRAM_SIZE);

    ResetPaletteFade();
    ResetSpriteData();
    FreeAllSpritePalettes();
    gReservedSpritePaletteCount = 4;

    gBattleEnvironment = BATTLE_ENVIRONMENT_PLAIN;
    InitBattleBgsVideo();
    SetBattleBgs();
    LoadBattleTextboxAndBackground();

    SetGpuReg(REG_OFFSET_MOSAIC, 0);
    SetGpuReg(REG_OFFSET_WIN0H, 0);
    SetGpuReg(REG_OFFSET_WIN0V, 0);
    SetGpuReg(REG_OFFSET_WIN1H, 0);
    SetGpuReg(REG_OFFSET_WIN1V, 0);
    SetGpuReg(REG_OFFSET_WININ, 0);
    SetGpuReg(REG_OFFSET_WINOUT, 0);
}

static u8 LoadEvoPokemonSprite(enum Species species, bool32 isShiny, u32 personality, u32 slot)
{
    u8 id;
    u32 pal = slot + 1;
    enum BattlerPosition position = (slot << 1) | 1;
    LoadSpecialPokePic(gMonSpritesGfxPtr->spritesGfx[position],
                        species,
                        personality,
                        TRUE);
    LoadPalette(GetMonSpritePalFromSpeciesAndPersonality(species, isShiny, personality), OBJ_PLTT_ID(pal), PLTT_SIZE_4BPP);

    SetMultiuseSpriteTemplateToPokemon(species, position);
    gMultiuseSpriteTemplate.affineAnims = gDummySpriteAffineAnimTable;
    id = CreateSprite(&gMultiuseSpriteTemplate, 120, 64, 30);

    gSprites[id].callback = SpriteCallbackDummy_2;
    gSprites[id].oam.paletteNum = pal;
    return id;
}

static void EvolutionScene_FadeIn(void)
{
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_BG_ALL_ON | DISPCNT_OBJ_1D_MAP);
    ShowBg(0);
    ShowBg(1);
    ShowBg(2);
    ShowBg(3);

    BeginNormalPaletteFade(PALETTES_ALL, 0, 0x10, 0, RGB_BLACK);
    SetHBlankCallback(EvoDummyFunc);
    SetVBlankCallback(VBlankCB_EvolutionScene);
    SetMainCallback2(CB2_EvolutionSceneUpdate);
}

void EvolutionScene(void)
{
    u8 name[POKEMON_NAME_BUFFER_SIZE];
    u8 id;

    ScanlineEffect_Stop();
    m4aMPlayAllStop();
    ResetTasks();
    EvoScene_InitGraphics_Standard();

    AllocateMonSpritesGfx();
    LoadEvoSparkleSpriteAndPal();

    struct BoxPokemon *boxmon = GetBoxMonFromPartyIndex(sEvoStructPtr->partyIndex);
    enum Species currSpecies = GetBoxMonData(boxmon, MON_DATA_SPECIES);
    enum Species postEvoSpecies = GetSpeciesEvolutions(currSpecies)[sEvoStructPtr->data.evoIndex].targetSpecies;

    GetBoxMonData(boxmon, MON_DATA_NICKNAME, name);
    StringCopy_Nickname(gStringVar1, name);
    StringCopy(gStringVar2, GetSpeciesName(postEvoSpecies));

    u32 personality = GetBoxMonData(boxmon, MON_DATA_PERSONALITY);
    bool32 isShiny = GetBoxMonData(boxmon, MON_DATA_IS_SHINY);
    sEvoStructPtr->preEvoSpriteId = LoadEvoPokemonSprite(currSpecies, isShiny, personality, 0);

    sEvoStructPtr->postEvoSpriteId = LoadEvoPokemonSprite(postEvoSpecies, isShiny, personality, 1);
    gSprites[sEvoStructPtr->postEvoSpriteId].invisible = TRUE;

    sEvoStructPtr->evoTaskId = id = CreateTask(Task_EvolutionScene, 0);
    gTasks[id].tState = 0;
    gTasks[id].tPreEvoSpecies = currSpecies;
    gTasks[id].tPostEvoSpecies = postEvoSpecies;
    gTasks[id].tLearnsetIndex = 0;
    gTasks[id].tEvoWasStopped = FALSE;

    memcpy(&sEvoStructPtr->savedPalette, &gPlttBufferUnfaded[BG_PLTT_ID(2)], sizeof(sEvoStructPtr->savedPalette));

    EvolutionScene_FadeIn();
}

static void CB2_EvolutionSceneLoadGraphics(void)
{
    struct BoxPokemon *boxmon = GetBoxMonFromPartyIndex(sEvoStructPtr->partyIndex);

    EvoScene_InitGraphics_Standard();

    enum Species postEvoSpecies = gTasks[sEvoStructPtr->evoTaskId].tPostEvoSpecies;
    bool32 isShiny = GetBoxMonData(boxmon, MON_DATA_IS_SHINY);
    u32 personality = GetBoxMonData(boxmon, MON_DATA_PERSONALITY);
    sEvoStructPtr->postEvoSpriteId = LoadEvoPokemonSprite(postEvoSpecies, isShiny, personality, 1);

    EvolutionScene_FadeIn();
}

static void CB2_TradeEvolutionSceneLoadGraphics(void)
{
    struct BoxPokemon *boxmon = GetBoxMonFromPartyIndex(sEvoStructPtr->partyIndex);
    enum Species postEvoSpecies = gTasks[sEvoStructPtr->evoTaskId].tPostEvoSpecies;

    switch (gMain.state)
    {
    case 0:
        SetGpuReg(REG_OFFSET_DISPCNT, 0);
        SetHBlankCallback(NULL);
        SetVBlankCallback(NULL);
        ResetSpriteData();
        FreeAllSpritePalettes();
        gReservedSpritePaletteCount = 4;
        SetBattleBgs();
        gMain.state++;
        break;
    case 1:
        ResetPaletteFade();
        SetHBlankCallback(EvoDummyFunc);
        SetVBlankCallback(VBlankCB_EvolutionScene);
        gMain.state++;
        break;
    case 2:
        LoadTradeAnimGfx();
        gMain.state++;
        break;
    case 3:
        FillBgTilemapBufferRect(1, 0, 0, 0, 0x20, 0x20, 0x11);
        CopyBgTilemapBufferToVram(1);
        gMain.state++;
        break;
    case 4:
        {
            bool8 isShiny = GetBoxMonData(boxmon, MON_DATA_IS_SHINY);
            u32 personality = GetBoxMonData(boxmon, MON_DATA_PERSONALITY);
            sEvoStructPtr->postEvoSpriteId = LoadEvoPokemonSprite(postEvoSpecies, isShiny, personality, 1);
            gMain.state++;
        }
        break;
    case 5:
        {
            LinkTradeDrawWindow();
            gMain.state++;
        }
        break;
    case 6:
        if (gWirelessCommType)
        {
            LoadWirelessStatusIndicatorSpriteGfx();
            CreateWirelessStatusIndicatorSprite(0, 0);
        }
        BlendPalettes(PALETTES_ALL, 0x10, RGB_BLACK);
        gMain.state++;
        break;
    case 7:
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0x10, 0, RGB_BLACK);
        InitTradeSequenceBgGpuRegs();
        ShowBg(0);
        ShowBg(1);
        SetMainCallback2(CB2_EvolutionSceneUpdate);
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_BG0_ON | DISPCNT_BG1_ON | DISPCNT_OBJ_1D_MAP);
        break;
    }
}

void TradeEvolutionScene(void)
{
    u8 name[POKEMON_NAME_BUFFER_SIZE];
    u8 id;

    gAffineAnimsDisabled = TRUE;
    SetBattleBgs();
    LoadEvoSparkleSpriteAndPal();

    struct BoxPokemon *boxmon = GetBoxMonFromPartyIndex(sEvoStructPtr->partyIndex);
    enum Species currSpecies = GetBoxMonData(boxmon, MON_DATA_SPECIES);
    enum Species postEvoSpecies = GetSpeciesEvolutions(currSpecies)[sEvoStructPtr->data.evoIndex].targetSpecies;

    GetBoxMonData(boxmon, MON_DATA_NICKNAME, name);
    StringCopy_Nickname(gStringVar1, name);
    StringCopy(gStringVar2, GetSpeciesName(postEvoSpecies));

    u32 personality = GetBoxMonData(boxmon, MON_DATA_PERSONALITY);
    bool32 isShiny = GetBoxMonData(boxmon, MON_DATA_IS_SHINY);
    sEvoStructPtr->postEvoSpriteId = LoadEvoPokemonSprite(postEvoSpecies, isShiny, personality, 1);
    gSprites[sEvoStructPtr->postEvoSpriteId].invisible = TRUE;

    sEvoStructPtr->evoTaskId = id = CreateTask(Task_EvolutionScene, 0);
    gTasks[id].tState = 0; // EVOSTATE_INTRO_MSG
    gTasks[id].tPreEvoSpecies = currSpecies;
    gTasks[id].tPostEvoSpecies = postEvoSpecies;
    gTasks[id].tLearnsetIndex = 0;
    gTasks[id].tEvoWasStopped = FALSE;

    gTextFlags.useAlternateDownArrow = TRUE;

    SetVBlankCallback(VBlankCB_EvolutionScene);
    SetMainCallback2(CB2_EvolutionSceneUpdate);
}

static void CB2_EvolutionSceneUpdate(void)
{
    AnimateSprites();
    BuildOamBuffer();
    RunTextPrinters();
    UpdatePaletteFade();
    RunTasks();
}

static void ConsumeEvolutionItems(u8 taskId)
{
    const struct Evolution *evo = GetSpeciesEvolutions(gTasks[taskId].tPreEvoSpecies);
    evo = &evo[sEvoStructPtr->data.evoIndex];

    if (evo->method == EVO_ITEM)
    {
        RemoveBagItem(evo->param, 1);
    }

    for (u32 i = 0; evo->params != NULL && evo->params[i].condition != CONDITIONS_END; i++)
    {
        const struct EvolutionParam *param = &evo->params[i];

        switch (param->condition)
        {
            case IF_HOLD_ITEM:
                enum Item item = ITEM_NONE;
                struct BoxPokemon *boxmon = GetBoxMonFromPartyIndex(sEvoStructPtr->partyIndex);
                SetBoxMonData(boxmon, MON_DATA_HELD_ITEM, &item);
                break;
            case IF_BAG_ITEM_COUNT:
                RemoveBagItem(param->arg1, param->arg2);
                break;
            default:
                break;
        }
    }
}

static void CreateShedinja(enum Species preEvoSpecies, enum Species postEvoSpecies, struct BoxPokemon *boxmon)
{
    u32 data = 0;
    enum Item ball = ITEM_POKE_BALL;
    const struct Evolution *evolutions = GetSpeciesEvolutions(preEvoSpecies);

    if (evolutions == NULL)
        return;

    for (u32 i = 0; evolutions[i].method != EVOLUTIONS_END; i++)
    {
        if (evolutions[i].method == EVO_SPLIT_FROM_EVO
         && evolutions[i].param == postEvoSpecies
         && gPartiesCount[B_TRAINER_PLAYER] < PARTY_SIZE
         && DoesBoxMonMeetConditions(boxmon, &sEvoStructPtr->data, &evolutions[i]))
        {
            s32 j;
            struct Pokemon *shedinja = &gParties[B_TRAINER_PLAYER][gPartiesCount[B_TRAINER_PLAYER]];

            BoxMonToMon(boxmon, &gParties[B_TRAINER_PLAYER][gPartiesCount[B_TRAINER_PLAYER]]);
            SetMonData(&gParties[B_TRAINER_PLAYER][gPartiesCount[B_TRAINER_PLAYER]], MON_DATA_SPECIES, &evolutions[i].targetSpecies);
            SetMonData(&gParties[B_TRAINER_PLAYER][gPartiesCount[B_TRAINER_PLAYER]], MON_DATA_NICKNAME, GetSpeciesName(evolutions[i].targetSpecies));
            SetMonData(&gParties[B_TRAINER_PLAYER][gPartiesCount[B_TRAINER_PLAYER]], MON_DATA_HELD_ITEM, &data);
            SetMonData(&gParties[B_TRAINER_PLAYER][gPartiesCount[B_TRAINER_PLAYER]], MON_DATA_MARKINGS, &data);
            if (P_SHEDINJA_BALL >= GEN_4)
            {
                enum PokeBall ballData = GetItemSecondaryId(ball);
                SetMonData(&gParties[B_TRAINER_PLAYER][gPartiesCount[B_TRAINER_PLAYER]], MON_DATA_POKEBALL, &ballData);
                RemoveBagItem(ball, 1);
            }

            for (j = MON_DATA_COOL_RIBBON; j < MON_DATA_COOL_RIBBON + CONTEST_CATEGORIES_COUNT; j++)
                SetMonData(&gParties[B_TRAINER_PLAYER][gPartiesCount[B_TRAINER_PLAYER]], j, &data);
            for (j = MON_DATA_CHAMPION_RIBBON; j <= MON_DATA_WORLD_RIBBON; j++)
                SetMonData(&gParties[B_TRAINER_PLAYER][gPartiesCount[B_TRAINER_PLAYER]], j, &data);

            SetMonData(&gParties[B_TRAINER_PLAYER][gPartiesCount[B_TRAINER_PLAYER]], MON_DATA_STATUS, &data);
            data = MAIL_NONE;
            SetMonData(&gParties[B_TRAINER_PLAYER][gPartiesCount[B_TRAINER_PLAYER]], MON_DATA_MAIL, &data);

            CalculateMonStats(&gParties[B_TRAINER_PLAYER][gPartiesCount[B_TRAINER_PLAYER]]);
            CalculatePlayerPartyCount();

            GetSetPokedexFlag(SpeciesToNationalPokedexNum(evolutions[i].targetSpecies), FLAG_SET_SEEN);
            GetSetPokedexFlag(SpeciesToNationalPokedexNum(evolutions[i].targetSpecies), FLAG_SET_CAUGHT);

            if (GetMonData(shedinja, MON_DATA_SPECIES) == SPECIES_SHEDINJA
                && GetMonData(shedinja, MON_DATA_LANGUAGE) == LANGUAGE_JAPANESE
                && GetBoxMonData(boxmon, MON_DATA_SPECIES) == SPECIES_NINJASK)
                    SetMonData(shedinja, MON_DATA_NICKNAME, sText_ShedinjaJapaneseName);

        }
    }
}

// States for the main switch in Task_EvolutionScene
enum {
    EVOSTATE_INTRO_MSG,
    EVOSTATE_INTRO_MON_ANIM,
    EVOSTATE_INTRO_SOUND,
    EVOSTATE_START_MUSIC,
    EVOSTATE_START_BG_AND_SPARKLE_SPIRAL,
    EVOSTATE_SPARKLE_ARC,
    EVOSTATE_CYCLE_MON_SPRITE,
    EVOSTATE_WAIT_CYCLE_MON_SPRITE,
    EVOSTATE_SPARKLE_CIRCLE,
    EVOSTATE_SPARKLE_SPRAY,
    EVOSTATE_RESTORE_SCREEN,
    EVOSTATE_EVO_MON_ANIM,
    EVOSTATE_SET_MON_EVOLVED,
    EVOSTATE_RESTORE_BGM,
    EVOSTATE_TRY_LEARN_MOVE,
    EVOSTATE_BEFORE_END,
    EVOSTATE_END,
    EVOSTATE_CANCEL,
    EVOSTATE_CANCEL_MON_ANIM,
    EVOSTATE_CANCEL_MSG,
    EVOSTATE_LEARNING_MOVE,
    EVOSTATE_LEARNED_MOVE,
    EVOSTATE_TRY_LEARN_ANOTHER_MOVE,
    EVOSTATE_REPLACE_MOVE,
};

// Task data from CycleEvolutionMonSprite
#define tEvoStopped data[8]

static void PrintEvolutionText(const u8 *str)
{
    if (sEvoStructPtr->isTradeEvo)
        DrawTextOnTradeWindow(0, gStringVar4, 1);
    else
        BattlePutTextOnWindow(gStringVar4, B_WIN_MSG);
}

static void UIAskConfirmation(void)
{
    if (sEvoStructPtr->isTradeEvo)
    {
        LoadUserWindowBorderGfx(0, 0xA8, BG_PLTT_ID(14));
        CreateYesNoMenu(&gTradeEvolutionSceneYesNoWindowTemplate, 0xA8, 0xE, 0);
        return;
    }
    HandleBattleWindow(YESNOBOX_X_Y, 0);
    BattlePutTextOnWindow(gText_BattleYesNoChoice, B_WIN_YESNO);
    sEvoCursorPos = 0;
    BattleCreateYesNoCursorAt(0);
}

static s32 UIWaitConfirmation(void)
{
    if (sEvoStructPtr->isTradeEvo)
        return Menu_ProcessInputNoWrapClearOnChoose();
    if (JOY_NEW(A_BUTTON))
    {
        PlaySE(SE_SELECT);
        HandleBattleWindow(YESNOBOX_X_Y, WINDOW_CLEAR);
        return sEvoCursorPos;
    }
    if (JOY_NEW(B_BUTTON))
    {
        HandleBattleWindow(YESNOBOX_X_Y, WINDOW_CLEAR);
        return MENU_B_PRESSED;
    }
    if (JOY_NEW(DPAD_UP) || JOY_NEW(DPAD_DOWN))
    {
        PlaySE(SE_SELECT);
        BattleDestroyYesNoCursorAt(sEvoCursorPos);
        sEvoCursorPos ^= 1;
        BattleCreateYesNoCursorAt(sEvoCursorPos);
    }
     return MENU_NOTHING_CHOSEN;

}

static void UIPrintMessage(const u8 *message)
{
    StringExpandPlaceholders(gStringVar4, message);
    PrintEvolutionText(gStringVar4);
}

static void UIPlayFanfare(u32 songId)
{
    PlayFanfare(songId);
}

static void UIShowMoveList(u8 taskId)
{
    void (*callback)(void);
    if (sEvoStructPtr->isTradeEvo)
        callback = CB2_TradeEvolutionSceneLoadGraphics;
    else
        callback = CB2_EvolutionSceneLoadGraphics;
    ShowSelectMovePokemonSummaryScreen(gParties[B_TRAINER_PLAYER], gTasks[taskId].data[1], callback, gTasks[taskId].data[2]);
    if (sEvoStructPtr->isTradeEvo)
    {
        Free(GetBgTilemapBuffer(3));
        Free(GetBgTilemapBuffer(1));
        Free(GetBgTilemapBuffer(0));
    }
    FreeAllWindowBuffers();
}

static void UIEndTask(u8 taskId)
{
    u32 evoSceneTaskId = gTasks[taskId].data[4];
    gTasks[evoSceneTaskId].tState = EVOSTATE_TRY_LEARN_MOVE;
}

static const struct MoveLearnUI sMoveLearnUI =
{
    .askConfirmation = UIAskConfirmation,
    .waitConfirmation = UIWaitConfirmation,
    .printMessage = UIPrintMessage,
    .playFanfare = UIPlayFanfare,
    .showMoveList = UIShowMoveList,
    .endTask = UIEndTask
};

static void EvolutionRenameBoxMon(struct BoxPokemon *boxmon, enum Species oldSpecies, enum Species newSpecies)
{
    u8 language;
    GetBoxMonData(boxmon, MON_DATA_NICKNAME, gStringVar1);
    language = GetBoxMonData(boxmon, MON_DATA_LANGUAGE, &language);
    if (language == GAME_LANGUAGE && !StringCompare(GetSpeciesName(oldSpecies), gStringVar1))
        SetBoxMonData(boxmon, MON_DATA_NICKNAME, GetSpeciesName(newSpecies));
}

static u16 BoxMonTryLearningNewMoveEvolution(struct BoxPokemon *boxmon, u8 taskId)
{
    enum Species species = gTasks[taskId].tPostEvoSpecies;
    u8 level = GetLevelFromBoxMonExp(boxmon);
    const struct LevelUpMove *learnset = GetSpeciesLevelUpLearnset(species);
    bool32 canLearn;

    while (learnset[gTasks[taskId].tLearnsetIndex].move != LEVEL_UP_MOVE_END)
    {
        canLearn = TRUE;
        if (learnset[gTasks[taskId].tLearnsetIndex].level == 0)
            ;
        else if (learnset[gTasks[taskId].tLearnsetIndex].level != level)
             canLearn = FALSE;
        else if (P_EVOLUTION_LEVEL_1_LEARN >= GEN_8 && level == 1)
            canLearn = FALSE;
        gTasks[taskId].tLearnsetIndex++;
        if (canLearn)
        {
            return learnset[gTasks[taskId].tLearnsetIndex - 1].move;
        }
    }
    return MOVE_NONE;
}

static void Task_EvolutionScene(u8 taskId)
{
    u32 var;
    struct BoxPokemon *boxmon = GetBoxMonFromPartyIndex(sEvoStructPtr->partyIndex);

    // check if B Button was held, so the evolution gets stopped
    if (gMain.heldKeys == B_BUTTON
        && gTasks[taskId].tState == EVOSTATE_WAIT_CYCLE_MON_SPRITE
        && gTasks[sEvoGraphicsTaskId].isActive
        && !sEvoStructPtr->data.cannotStopEvo)
    {
        gTasks[taskId].tState = EVOSTATE_CANCEL;
        gSpecialVar_Result = EVO_EVENT_INTERRUPTED;
        gTasks[sEvoGraphicsTaskId].tEvoStopped = TRUE;
        StopBgAnimation();
        return;
    }

    switch (gTasks[taskId].tState)
    {
    case EVOSTATE_INTRO_MSG:
        if (!gPaletteFade.active)
        {
            StringExpandPlaceholders(gStringVar4, gText_PkmnIsEvolving);
            PrintEvolutionText(gStringVar4);
            if (sEvoStructPtr->isTradeEvo)
                gTasks[taskId].tState = EVOSTATE_INTRO_SOUND;
            else
                gTasks[taskId].tState++;
        }
        break;
    case EVOSTATE_INTRO_MON_ANIM:
        if (!IsTextPrinterActiveOnWindow(0))
        {
            EvoScene_DoMonAnimAndCry(sEvoStructPtr->preEvoSpriteId, gTasks[taskId].tPreEvoSpecies);
            gTasks[taskId].tState++;
        }
        break;
    case EVOSTATE_INTRO_SOUND:
        if (sEvoStructPtr->isTradeEvo || EvoScene_IsMonAnimFinished(sEvoStructPtr->preEvoSpriteId))
        {
            m4aSongNumStop(MUS_EVOLUTION);
            PlaySE(MUS_EVOLUTION_INTRO);
            gTasks[taskId].tState++;
        }
        break;
    case EVOSTATE_START_MUSIC:
        if (!IsSEPlaying())
        {
            // Start music, fade background to black
            PlayNewMapMusic(MUS_EVOLUTION);
            gTasks[taskId].tState++;
            BeginNormalPaletteFade(0x1C, 4, 0, 0x10, RGB_BLACK);
        }
        break;
    case EVOSTATE_START_BG_AND_SPARKLE_SPIRAL:
        if (!gPaletteFade.active)
        {
            StartBgAnimation(sEvoStructPtr->isTradeEvo);
            sEvoGraphicsTaskId = EvolutionSparkles_SpiralUpward(gSprites[sEvoStructPtr->preEvoSpriteId].oam.paletteNum + 16);
            gTasks[taskId].tState++;
        }
        break;
    case EVOSTATE_SPARKLE_ARC:
        if (!gTasks[sEvoGraphicsTaskId].isActive)
        {
            gTasks[taskId].tState++;
            sEvoStructPtr->delayTimer = 1;
            sEvoGraphicsTaskId = EvolutionSparkles_ArcDown();
        }
        break;
    case EVOSTATE_CYCLE_MON_SPRITE: // launch task that flashes pre evo with post evo sprites
        if (!gTasks[sEvoGraphicsTaskId].isActive)
        {
            sEvoGraphicsTaskId = CycleEvolutionMonSprite(sEvoStructPtr->preEvoSpriteId, sEvoStructPtr->postEvoSpriteId);
            gTasks[taskId].tState++;
        }
        break;
    case EVOSTATE_WAIT_CYCLE_MON_SPRITE:
        if (--sEvoStructPtr->delayTimer == 0)
        {
            sEvoStructPtr->delayTimer = 3;
            if (!gTasks[sEvoGraphicsTaskId].isActive)
                gTasks[taskId].tState++;
        }
        break;
    case EVOSTATE_SPARKLE_CIRCLE:
        sEvoGraphicsTaskId = EvolutionSparkles_CircleInward();
        gTasks[taskId].tState++;
        break;
    case EVOSTATE_SPARKLE_SPRAY:
        if (!gTasks[sEvoGraphicsTaskId].isActive)
        {
            sEvoGraphicsTaskId = EvolutionSparkles_SprayAndFlash(sEvoStructPtr->isTradeEvo);
            gTasks[taskId].tState++;
        }
        break;
    case EVOSTATE_RESTORE_SCREEN: // stop music, return screen to pre-fade state
        if (!gTasks[sEvoGraphicsTaskId].isActive)
        {
            memcpy(&gPlttBufferUnfaded[BG_PLTT_ID(2)], sEvoStructPtr->savedPalette, sizeof(sEvoStructPtr->savedPalette));
            m4aMPlayStop(&gMPlayInfo_BGM);
            PlaySE(SE_EXP);
            if (sEvoStructPtr->isTradeEvo)
            {
                Free(sBgAnimPal);
            }
            else
            {
                RestoreBgAfterAnim();
                BeginNormalPaletteFade(0x1C, 0, 0x10, 0, RGB_BLACK);
            }
            gTasks[taskId].tState++;
        }
        break;
    case EVOSTATE_EVO_MON_ANIM:
        if (!gPaletteFade.active && !IsSEPlaying())
        {
            EvoScene_DoMonAnimAndCry(sEvoStructPtr->postEvoSpriteId, gTasks[taskId].tPostEvoSpecies);
            gTasks[taskId].tState++;
        }
        break;
    case EVOSTATE_SET_MON_EVOLVED:
        if (IsCryFinished())
        {
            u32 zero = 0;
            StringExpandPlaceholders(gStringVar4, gText_CongratsPkmnEvolved);
            PrintEvolutionText(gStringVar4);
            PlayFanfare(MUS_EVOLVED);
            gTasks[taskId].tState++;
            SetBoxMonData(boxmon, MON_DATA_SPECIES, (void *)(&gTasks[taskId].tPostEvoSpecies));
            SetBoxMonData(boxmon, MON_DATA_EVOLUTION_TRACKER, &zero);
            if (sEvoStructPtr->partyIndex < PARTY_SIZE)
                CalculateMonStats(&gParties[B_TRAINER_PLAYER][sEvoStructPtr->partyIndex]);
            EvolutionRenameBoxMon(boxmon, gTasks[taskId].tPreEvoSpecies, gTasks[taskId].tPostEvoSpecies);
            GetSetPokedexFlag(SpeciesToNationalPokedexNum(gTasks[taskId].tPostEvoSpecies), FLAG_SET_SEEN);
            GetSetPokedexFlag(SpeciesToNationalPokedexNum(gTasks[taskId].tPostEvoSpecies), FLAG_SET_CAUGHT);
            IncrementGameStat(GAME_STAT_EVOLVED_POKEMON);
        }
        break;
    case EVOSTATE_RESTORE_BGM:
        if (IsFanfareTaskInactive())
        {
            m4aMPlayContinue(&gMPlayInfo_BGM);
            gTasks[taskId].tState++;
        }
        break;
    case EVOSTATE_TRY_LEARN_MOVE:
        if (!IsTextPrinterActiveOnWindow(0))
        {
            var = BoxMonTryLearningNewMoveEvolution(boxmon, taskId);
            if (var == MOVE_NONE)
            {
                gTasks[taskId].tState++;
                break;
            }
            if (BoxMonKnowsMove(boxmon, var))
                break;

            u32 learnTaskId = CreateTask(TaskDummy, 0);
            gTasks[learnTaskId].data[0] = GetLearnMoveLevelUpStartState();
            gTasks[learnTaskId].data[1] = sEvoStructPtr->partyIndex;
            gTasks[learnTaskId].data[2] = var;
            gTasks[learnTaskId].data[3] = TRUE;
            gTasks[learnTaskId].data[4] = taskId;
            gTasks[taskId].tLearnMoveTaskId = learnTaskId;
            gTasks[taskId].tState = EVOSTATE_LEARNING_MOVE;
        }
        break;
    case EVOSTATE_BEFORE_END:
        if (!IsTextPrinterActiveOnWindow(0))
        {
            if (!sEvoStructPtr->isTradeEvo)
            {
                StopMapMusic();
                Overworld_PlaySpecialMapMusic();
                BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 0x10, RGB_BLACK);
            }
            gTasks[taskId].tState++;
        }
        break;
    case EVOSTATE_END:
        if (!gPaletteFade.active)
        {
            if (!gTasks[taskId].tEvoWasStopped)
                CreateShedinja(gTasks[taskId].tPreEvoSpecies, gTasks[taskId].tPostEvoSpecies, boxmon);

            ConsumeEvolutionItems(taskId);
            if (sEvoStructPtr->isTradeEvo)
            {
                gTextFlags.useAlternateDownArrow = FALSE;
            }
            else
            {
                FreeMonSpritesGfx();
                FreeAllWindowBuffers();
            }
            DestroyTask(taskId);
            FREE_AND_SET_NULL(sEvoStructPtr);
            SetMainCallback2(gCB2_AfterEvolution);
        }
        break;
    case EVOSTATE_CANCEL:
        if (!gTasks[sEvoGraphicsTaskId].isActive)
        {
            m4aMPlayAllStop();
            BeginNormalPaletteFade((1 << (gSprites[sEvoStructPtr->preEvoSpriteId].oam.paletteNum + 16)) | (0x4001C), 0, 0x10, 0, RGB_WHITE);
            gTasks[taskId].tState++;
        }
        break;
    case EVOSTATE_CANCEL_MON_ANIM:
        if (!gPaletteFade.active)
        {
            EvoScene_DoMonAnimAndCry(sEvoStructPtr->preEvoSpriteId, gTasks[taskId].tPreEvoSpecies);
            gTasks[taskId].tState++;
        }
        break;
    case EVOSTATE_CANCEL_MSG:
        if (EvoScene_IsMonAnimFinished(sEvoStructPtr->isTradeEvo))
        {
            if (gTasks[taskId].tEvoWasStopped) // FRLG auto cancellation
                StringExpandPlaceholders(gStringVar4, gText_EllipsisQuestionMark);
            else
                StringExpandPlaceholders(gStringVar4, gText_PkmnStoppedEvolving);

            PrintEvolutionText(gStringVar4);
            gTasks[taskId].tEvoWasStopped = TRUE;
            gTasks[taskId].tState = EVOSTATE_BEFORE_END;
        }
        break;
    case EVOSTATE_LEARNING_MOVE:
        if (!IsTextPrinterActiveOnWindow(0) && gMain.callback2 == CB2_EvolutionSceneUpdate)
        {
            var = gTasks[taskId].tLearnMoveTaskId;
            gTasks[var].data[0] = LearnMove(&sMoveLearnUI, var);
        }
        break;
    }

}

#undef tState
#undef tPreEvoSpecies
#undef tPostEvoSpecies
#undef tLearnsetIndex
#undef tEvoWasStopped
#undef tLearnMoveTaskId

static void EvoDummyFunc(void)
{
}

static void VBlankCB_EvolutionScene(void)
{
    SetGpuReg(REG_OFFSET_BG0HOFS, gBattle_BG0_X);
    SetGpuReg(REG_OFFSET_BG0VOFS, gBattle_BG0_Y);
    SetGpuReg(REG_OFFSET_BG1HOFS, gBattle_BG1_X);
    SetGpuReg(REG_OFFSET_BG1VOFS, gBattle_BG1_Y);
    SetGpuReg(REG_OFFSET_BG2HOFS, gBattle_BG2_X);
    SetGpuReg(REG_OFFSET_BG2VOFS, gBattle_BG2_Y);
    SetGpuReg(REG_OFFSET_BG3HOFS, gBattle_BG3_X);
    SetGpuReg(REG_OFFSET_BG3VOFS, gBattle_BG3_Y);

    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
    ScanlineEffect_InitHBlankDmaTransfer();
}

#define tCycleTimer   data[0]
#define tPalStage     data[1]
#define tControlStage data[2]
#define tNumCycles    data[3]
#define tStartTimer   data[5]
#define tPaused       data[6]

// See comments above sBgAnim_PaletteControl
#define START_PAL sBgAnim_PaletteControl[tControlStage][0]
#define END_PAL   sBgAnim_PaletteControl[tControlStage][1]
#define CYCLES    sBgAnim_PaletteControl[tControlStage][2]
#define DELAY     sBgAnim_PaletteControl[tControlStage][3]

// Cycles the background through a set range of palettes in a series
// of stages, each stage having a different palette range and timing
static void Task_UpdateBgPalette(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (tPaused)
        return;
    if (tStartTimer++ < 20)
        return;

    if (tCycleTimer++ > DELAY)
    {
        if (END_PAL == tPalStage)
        {
            // Reached final palette in current stage, completed a 'cycle'
            // If this is the final cycle for this stage, move to the next stage
            tNumCycles++;
            if (tNumCycles == CYCLES)
            {
                tNumCycles = 0;
                tControlStage++;
            }
            tPalStage = START_PAL;
        }
        else
        {
            // Haven't reached final palette in current stage, load the current palette
            LoadPalette(&sBgAnimPal[tPalStage * 16], BG_PLTT_ID(10), PLTT_SIZE_4BPP);
            tCycleTimer = 0;
            tPalStage++;
        }
    }

    if (tControlStage == (int)ARRAY_COUNT(sBgAnim_PaletteControl[0]))
        DestroyTask(taskId);
}

#undef tCycleTimer
#undef tPalStage
#undef tControlStage
#undef tNumCycles
#undef tStartTimer
#undef START_PAL
#undef END_PAL
#undef CYCLES
#undef DELAY

#define tIsLink data[2]

static void CreateBgAnimTask(bool8 isLink)
{
    u8 taskId = CreateTask(Task_AnimateBg, 7);

    if (!isLink)
        gTasks[taskId].tIsLink = FALSE;
    else
        gTasks[taskId].tIsLink = TRUE;
}

static void Task_AnimateBg(u8 taskId)
{
    u16 *outer_X, *outer_Y;

    u16 *inner_X = &gBattle_BG1_X;
    u16 *inner_Y = &gBattle_BG1_Y;

    if (!gTasks[taskId].tIsLink)
    {
        outer_X = &gBattle_BG2_X;
        outer_Y = &gBattle_BG2_Y;
    }
    else
    {
        outer_X = &gBattle_BG3_X;
        outer_Y = &gBattle_BG3_Y;
    }

    gTasks[taskId].data[0] = (gTasks[taskId].data[0] + 5) & 0xFF;
    gTasks[taskId].data[1] = (gTasks[taskId].data[0] + 0x80) & 0xFF;

    *inner_X = Cos(gTasks[taskId].data[0], 4) + 8;
    *inner_Y = Sin(gTasks[taskId].data[0], 4) + 16;

    *outer_X = Cos(gTasks[taskId].data[1], 4) + 8;
    *outer_Y = Sin(gTasks[taskId].data[1], 4) + 16;

    if (!FuncIsActiveTask(Task_UpdateBgPalette))
    {
        DestroyTask(taskId);

        *inner_X = 0;
        *inner_Y = 0;

        *outer_X = 256;
        *outer_Y = 0;
    }
}

#undef tIsLink

static void InitMovingBgPalette(u16 *palette)
{
    s32 i, j;

    for (i = 0; i < (int)ARRAY_COUNT(sBgAnim_PalIndexes); i++)
    {
        for (j = 0; j < 16; j++)
        {
            palette[i * 16 + j] = sBgAnim_Pal[sBgAnim_PalIndexes[i][j]];
        }
    }
}

static void StartBgAnimation(bool8 isLink)
{
    u8 innerBgId, outerBgId;

    sBgAnimPal = AllocZeroed(0x640);
    InitMovingBgPalette(sBgAnimPal);

    if (!isLink)
        innerBgId = 1, outerBgId = 2;
    else
        innerBgId = 1, outerBgId = 3;

    LoadPalette(sBgAnim_Intro_Pal, BG_PLTT_ID(10), PLTT_SIZE_4BPP);

    DecompressAndLoadBgGfxUsingHeap(1, sBgAnim_Gfx, FALSE, 0, 0);
    CopyToBgTilemapBuffer(innerBgId, sBgAnim_Inner_Tilemap, 0, 0);
    CopyToBgTilemapBuffer(outerBgId, sBgAnim_Outer_Tilemap, 0, 0);
    CopyBgTilemapBufferToVram(innerBgId);
    CopyBgTilemapBufferToVram(outerBgId);

    if (!isLink)
    {
        SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG1 | BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_BG2);
        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(8, 8));
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_BG2_ON | DISPCNT_BG1_ON | DISPCNT_BG0_ON | DISPCNT_OBJ_1D_MAP);

        SetBgAttribute(innerBgId, BG_ATTR_PRIORITY, 2);
        SetBgAttribute(outerBgId, BG_ATTR_PRIORITY, 2);

        ShowBg(1);
        ShowBg(2);
    }
    else
    {
        SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG1 | BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_BG3);
        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(8, 8));
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_BG3_ON | DISPCNT_BG1_ON | DISPCNT_BG0_ON | DISPCNT_OBJ_1D_MAP);
        SetGpuReg(REG_OFFSET_BG3CNT, BGCNT_PRIORITY(3) | BGCNT_SCREENBASE(6));
    }

    CreateTask(Task_UpdateBgPalette, 5);
    CreateBgAnimTask(isLink);
}

static void UNUSED PauseBgPaletteAnim(void)
{
    u8 taskId = FindTaskIdByFunc(Task_UpdateBgPalette);

    if (taskId != TASK_NONE)
        gTasks[taskId].tPaused = TRUE;

    FillPalette(RGB_BLACK, BG_PLTT_ID(10), PLTT_SIZE_4BPP);
}

#undef tPaused

static void StopBgAnimation(void)
{
    u8 taskId;

    if ((taskId = FindTaskIdByFunc(Task_UpdateBgPalette)) != TASK_NONE)
        DestroyTask(taskId);
    if ((taskId = FindTaskIdByFunc(Task_AnimateBg)) != TASK_NONE)
        DestroyTask(taskId);

    FillPalette(RGB_BLACK, BG_PLTT_ID(10), PLTT_SIZE_4BPP);
    RestoreBgAfterAnim();
}

static void RestoreBgAfterAnim(void)
{
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    gBattle_BG1_X = 0;
    gBattle_BG1_Y = 0;
    gBattle_BG2_X = 0;
    SetBgAttribute(1, BG_ATTR_PRIORITY, GetBattleBgTemplateData(1, 5));
    SetBgAttribute(2, BG_ATTR_PRIORITY, GetBattleBgTemplateData(2, 5));
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_BG3_ON | DISPCNT_BG0_ON | DISPCNT_OBJ_1D_MAP);
    Free(sBgAnimPal);
}

static void EvoScene_DoMonAnimAndCry(u8 monSpriteId, enum Species speciesId)
{
    DoMonFrontSpriteAnimation(&gSprites[monSpriteId], speciesId, FALSE, 0);
}

static bool32 EvoScene_IsMonAnimFinished(u8 monSpriteId)
{
    if (gSprites[monSpriteId].callback == SpriteCallbackDummy)
        return TRUE;

    return FALSE;
}
