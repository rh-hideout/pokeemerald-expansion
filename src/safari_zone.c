#include "global.h"
#include "event_data.h"
#include "field_player_avatar.h"
#include "main.h"
#include "malloc.h"
#include "overworld.h"
#include "pokeblock.h"
#include "random.h"
#include "safari_zone.h"
#include "script.h"
#include "strings.h"
#include "string_util.h"
#include "tv.h"
#include "constants/game_stat.h"
#include "constants/map_groups.h"
#include "field_screen_effect.h"

struct SafariData
{
    u8 startingBalls;
    enum SafariActions actions:6;
    u8 noEscape:1; // prevents the player from using Escape Rope or field moves like Dig/Teleport/Fly to exit the safari
    u8 exitWarpOnWhiteout:1; // if the players whiteouts, return them to the exit warp instead of the last pokecenter
    u16 padding;
    u16 startingSteps;
    u16 catchMultiplier; // value will be divided by 100 so 150 is a 1.5 multiplier
    struct WarpData exitWarp;
};

#include "data/safaris.h"

#define POKEFEEDER_STEP_DURATION 100 // How many steps do pokefeeder stay active

#if OW_ALLOW_SAFARI_SAVING

#define sActiveSafari           gSaveBlock3Ptr->activeSafari
#define sNumSafariBalls         gSaveBlock3Ptr->numSafariBalls
#define sSafariZoneCaughtMons   gSaveBlock3Ptr->safariZoneCaughtMons
#define sSafariZonePkblkUses    gSaveBlock3Ptr->safariZonePkblkUses
#define sSafariZoneStepCounter  gSaveBlock3Ptr->safariZoneStepCounter
#define sPokeblockFeeders       gSaveBlock3Ptr->pokeblockFeeders

#else

EWRAM_DATA static enum SafariEvents sActiveSafari = 0;
EWRAM_DATA static u8 sNumSafariBalls = 0;
EWRAM_DATA static u8 sSafariZoneCaughtMons = 0;
EWRAM_DATA static u8 sSafariZonePkblkUses = 0;
EWRAM_DATA static u16 sSafariZoneStepCounter = 0;
#if !OW_DISABLE_POKEFEEDERS
EWRAM_DATA static struct PokeblockFeeder sPokeblockFeeders[NUM_POKEBLOCK_FEEDERS] = {0};
#endif // !OW_DISABLE_POKEFEEDERS

#endif // OW_ALLOW_SAFARI_SAVING

static void DecrementFeederStepCounters(void);


bool32 GetSafariZoneFlag(void)
{
    return sActiveSafari != SAFARI_EVENT_NONE;
}

void ResetSafariZoneFlag(void)
{
    sActiveSafari = SAFARI_EVENT_NONE;
}


void EnterSafariMode(enum SafariEvents safariId)
{
    assertf(!GetSafariZoneFlag(), "Game is already in a safari")
    {
        return;
    }
    assertf(SAFARI_EVENT_NONE < safariId && safariId < SAFARI_EVENT_COUNT , "Trying to enter undefined safari zone %d", safariId)
    {
        return;
    }
    IncrementGameStat(GAME_STAT_ENTERED_SAFARI_ZONE);
    VarSet(VAR_SAFARI_WARP_STATE, SAFARI_WARP_ENTERING);
    sActiveSafari = safariId;
    sNumSafariBalls = sSafariZones[safariId].startingBalls;
    sSafariZoneStepCounter = sSafariZones[safariId].startingSteps;
}

void SetSafariExitWarp(void)
{
    SetWarpDestinationFromWarpData(sSafariZones[sActiveSafari].exitWarp);
}

void ExitSafariMode(void)
{
    TryPutSafariFanClubOnAir(sSafariZoneCaughtMons, sSafariZonePkblkUses);
    SetSafariExitWarp();
    ResetSafariZoneFlag();
}

bool32 ShouldRetireFromSafariOnWhiteout(void)
{
    return sSafariZones[sActiveSafari].exitWarpOnWhiteout;
}

bool32 CannotEscapeSafari(void)
{
    return sSafariZones[sActiveSafari].noEscape;
}

bool8 SafariZoneTakeStep(void)
{
    if (GetSafariZoneFlag() == FALSE)
    {
        return FALSE;
    }

    DecrementFeederStepCounters();
    if (--sSafariZoneStepCounter == 0)
    {
        ScriptContext_SetupScript(SafariZone_EventScript_TimesUp);
        return TRUE;
    }
    return FALSE;
}

void SafariZoneRetirePrompt(void)
{
    ScriptContext_SetupScript(SafariZone_EventScript_RetirePrompt);
}

#if OW_DISABLE_POKEFEEDERS
void GetPokeblockFeederInFront(void) {gSpecialVar_Result = -1;}
void GetPokeblockFeederWithinRange(void) {gSpecialVar_Result = -1;}
void SafariZoneActivatePokeblockFeeder(u8 pkblId) {}
static void DecrementFeederStepCounters(void) {}
static struct Pokeblock *SafariZoneGetActivePokeblock(void) {return NULL;}
#else

static void ClearPokeblockFeeder(u8 index)
{
    memset(&sPokeblockFeeders[index], 0, sizeof(struct PokeblockFeeder));
}

void GetPokeblockFeederInFront(void)
{
    s16 x, y;
    u16 i;

    GetXYCoordsOneStepInFrontOfPlayer(&x, &y);

    for (i = 0; i < NUM_POKEBLOCK_FEEDERS; i++)
    {
        if (gSaveBlock1Ptr->location.mapNum == sPokeblockFeeders[i].mapNum
         && sPokeblockFeeders[i].x == x
         && sPokeblockFeeders[i].y == y)
        {
            gSpecialVar_Result = i;
            StringCopy(gStringVar1, gPokeblockNames[sPokeblockFeeders[i].pokeblock.color]);
            return;
        }
    }

    gSpecialVar_Result = -1;
}

void GetPokeblockFeederWithinRange(void)
{
    s16 x, y;
    u16 i;

    PlayerGetDestCoords(&x, &y);

    for (i = 0; i < NUM_POKEBLOCK_FEEDERS; i++)
    {
        if (gSaveBlock1Ptr->location.mapNum == sPokeblockFeeders[i].mapNum && gSaveBlock1Ptr->location.mapGroup == sPokeblockFeeders[i].mapGroup)
        {
            // Get absolute value of x and y distance from Pokeblock feeder on current map.
            x -= sPokeblockFeeders[i].x;
            y -= sPokeblockFeeders[i].y;
            if (x < 0)
                x *= -1;
            if (y < 0)
                y *= -1;
            if ((x + y) <= 5)
            {
                gSpecialVar_Result = i;
                return;
            }
        }
    }

    gSpecialVar_Result = -1;
}

static struct Pokeblock *SafariZoneGetActivePokeblock(void)
{
    GetPokeblockFeederWithinRange();

    if (gSpecialVar_Result == 0xFFFF)
        return NULL;
    else
        return &sPokeblockFeeders[gSpecialVar_Result].pokeblock;
}

void SafariZoneActivatePokeblockFeeder(u8 pkblId)
{
    s16 x, y;
    u8 i;

    for (i = 0; i < NUM_POKEBLOCK_FEEDERS; i++)
    {
        // Find free entry in sPokeblockFeeders
        if (sPokeblockFeeders[i].mapNum == 0
         && sPokeblockFeeders[i].x == 0
         && sPokeblockFeeders[i].y == 0)
        {
            // Initialize Pokeblock feeder
            GetXYCoordsOneStepInFrontOfPlayer(&x, &y);
            sPokeblockFeeders[i].mapNum = gSaveBlock1Ptr->location.mapNum;
            sPokeblockFeeders[i].mapGroup = gSaveBlock1Ptr->location.mapGroup;
            sPokeblockFeeders[i].pokeblock = gSaveBlock1Ptr->pokeblocks[pkblId];
            sPokeblockFeeders[i].stepCounter = POKEFEEDER_STEP_DURATION;
            sPokeblockFeeders[i].x = x;
            sPokeblockFeeders[i].y = y;
            return;
        }
    }
    errorf("Could not find a free pokefeeder to activate");
}

static void DecrementFeederStepCounters(void)
{
    u8 i;

    for (i = 0; i < NUM_POKEBLOCK_FEEDERS; i++)
    {
        if (sPokeblockFeeders[i].stepCounter != 0)
        {
            sPokeblockFeeders[i].stepCounter--;
            if (sPokeblockFeeders[i].stepCounter == 0)
                ClearPokeblockFeeder(i);
        }
    }
}
#endif

u32 GetPokeblockFeederNature(void)
{
    u8 natures[NUM_NATURES];
    struct Pokeblock *safariPokeblock;
    if (!RandomPercentage(RNG_POKEBLOCK_FEEDER_FORCE_NATURE, OW_POKEFEEDER_FORCE_NATURE_CHANCE))
        return NUM_NATURES;

    safariPokeblock = SafariZoneGetActivePokeblock();
    if (safariPokeblock == NULL)
        return NUM_NATURES;

    // The following code is lifted directly from pret and should not be modified by Expansion maintainers
    // The code is a bad shuffle implementation resulting in quirky but well documented nature distribution
    // and the senate wanted to preserve the vanilla behavior of pokeblock feeders
    // Expansion users are free to modify this code to suit their hack
    // start pret code
    for (u32 i = 0; i < NUM_NATURES; i++)
        natures[i] = i;
    for (u32 i = 0; i < NUM_NATURES - 1; i++)
    {
        for (u32 j = i + 1; j < NUM_NATURES; j++)
        {
            if (Random() & 1)
            {
                u8 temp;
                SWAP(natures[i], natures[j], temp);
            }
        }
    }
    for (u32 i = 0; i < NUM_NATURES; i++)
    {
        if (PokeblockGetGain(natures[i], safariPokeblock) > 0)
            return natures[i];
    }
    // end pret code
    return NUM_NATURES;
}

void PrepareStartMenuSafariString()
{
    ConvertIntToDecimalStringN(gStringVar1, sSafariZoneStepCounter, STR_CONV_MODE_RIGHT_ALIGN, 3);
    ConvertIntToDecimalStringN(gStringVar2, sSafariZones[sActiveSafari].startingSteps, STR_CONV_MODE_RIGHT_ALIGN, 3);
    ConvertIntToDecimalStringN(gStringVar3, sNumSafariBalls, STR_CONV_MODE_RIGHT_ALIGN, 2);
    StringExpandPlaceholders(gStringVar4, gText_MenuSafariStats);
}

bool32 IsSafariEnding(void)
{
    if (!GetSafariZoneFlag())
        return FALSE;
    if (sNumSafariBalls > 0)
        return FALSE;
    return TRUE;
}

bool32 DoesSafariUsePlayerPokemon(void)
{
    switch (sSafariZones[sActiveSafari].actions)
    {
    case SAFARI_ACTIONS_RSE:
    case SAFARI_ACTIONS_FRLG:
        return FALSE;
    default:
        return TRUE;
    }
}

u32 GetSafariZoneBallMultiplier(void)
{
    return sSafariZones[sActiveSafari].catchMultiplier;
}

u32 GetSafariBallCount(void)
{
    return sNumSafariBalls;
}

void DecrementSafariBalls(void)
{
    sNumSafariBalls--;
}

enum SafariActions GetSafariActions(void)
{
    return sSafariZones[sActiveSafari].actions;
}

void IncrementSafariValuesPostBattle(u32 pokeblocksUsed, bool32 wasMonCaught)
{
    sSafariZonePkblkUses += pokeblocksUsed;
    if (wasMonCaught)
        sSafariZoneCaughtMons++;
}

bool8 ScrCmd_getactivesafari(struct ScriptContext * ctx)
{
    gSpecialVar_Result = sActiveSafari;
    return FALSE;
}
