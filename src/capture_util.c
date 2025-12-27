#include "global.h"
#include "battle.h"
#include "capture_util.h"
#include "event_data.h"
#include "generational_changes.h"
#include "item.h"
#include "overworld.h"
#include "pokedex.h"
#include "random.h"
#include "rtc.h"
#include "wild_encounter.h"

static void ComputeBallData(struct BallData *ball)
{
    u32 i;
    u32 ballId = ItemIdToBallId(gLastUsedItem);
    struct BattlePokemon *mon = &gBattleMons[gBattlerTarget];

    ball->multiplier = 100;
    ball->divider = 100;
    ball->flatBonus = 0;
    ball->guaranteedCapture = FALSE;

    if (gSpeciesInfo[mon->species].isUltraBeast)
    {
        if (ballId == BALL_BEAST)
            ball->multiplier = 500;
        else
        {
            ball->multiplier = 410;
            ball->divider = 4096;
        }
        return;
    }
    switch (ballId)
    {
    case BALL_GREAT:
        ball->multiplier = 150;
        break;
    case BALL_ULTRA:
        ball->multiplier = 200;
        break;
    case BALL_MASTER:
        ball->guaranteedCapture = TRUE;
        break;
    case BALL_NET:
        if (mon->types[0] == TYPE_WATER || mon->types[1] == TYPE_WATER || mon->types[2] == TYPE_WATER
            || mon->types[0] == TYPE_BUG || mon->types[1] == TYPE_BUG || mon->types[2] == TYPE_BUG)
        {
            ball->multiplier = B_NET_BALL_MODIFIER >= GEN_7 ? 350 : 300;
        }
        break;
    case BALL_NEST:
        ball->multiplier = 100;
        if ((B_NEST_BALL_MODIFIER == GEN_5 && mon->level < 31)
            || (B_NEST_BALL_MODIFIER >= GEN_6 && mon->level < 30))
        {
            ball->multiplier = (41 - mon->level) * 4096 / 10;
            ball->divider = 4096;
        }
        else if (mon->level < 30)
        {
            ball->multiplier = 400 - (mon->level * 10);
        }
        break;
    case BALL_DIVE:
        if (GetCurrentMapType() == MAP_TYPE_UNDERWATER
            || (B_DIVE_BALL_MODIFIER >= GEN_4 && (gIsFishingEncounter || gIsSurfingEncounter)))
        {
            ball->multiplier = 350;
        }
        break;
    case BALL_DUSK:
        i = GetTimeOfDay();
        if (i == TIME_EVENING || i == TIME_NIGHT || gMapHeader.cave || gMapHeader.mapType == MAP_TYPE_UNDERGROUND)
            ball->multiplier = (B_DUSK_BALL_MODIFIER >= GEN_7 ? 300 : 350);
        break;
    case BALL_TIMER:
        if (B_TIMER_BALL_MODIFIER >= GEN_5)
        {
            ball->multiplier = 4096 + gBattleResults.battleTurnCounter * 1229;
            ball->divider = 4096;
        }
        else
        {
            ball->multiplier = 100 + gBattleResults.battleTurnCounter * 10;
        }
        if (ball->multiplier > (4 * ball->divider))
            ball->multiplier = 4 * ball->divider;
        break;
    case BALL_QUICK:
        if (gBattleResults.battleTurnCounter == 0)
            ball->multiplier = (B_QUICK_BALL_MODIFIER >= GEN_5 ? 500 : 400);
        break;
    case BALL_REPEAT:
        if (GetSetPokedexFlag(SpeciesToNationalPokedexNum(mon->species), FLAG_GET_CAUGHT))
            ball->multiplier = (B_REPEAT_BALL_MODIFIER >= GEN_7 ? 350 : 300);
        break;
    case BALL_LEVEL:
        if (gBattleMons[gBattlerAttacker].level >= 4 * mon->level)
            ball->multiplier = 800;
        else if (gBattleMons[gBattlerAttacker].level > 2 * mon->level)
            ball->multiplier = 400;
        else if (gBattleMons[gBattlerAttacker].level > mon->level)
            ball->multiplier = 200;
        break;
    case BALL_LURE:
        if (gIsFishingEncounter)
        {
            if (B_LURE_BALL_MODIFIER >= GEN_8)
                ball->multiplier = 400;
            else if (B_LURE_BALL_MODIFIER >= GEN_7)
                ball->multiplier = 500;
            else
                ball->multiplier = 300;
        }
        break;
    case BALL_MOON:
        const struct Evolution *evolutions = GetSpeciesEvolutions(mon->species);
        if (evolutions == NULL)
            break;
        for (i = 0; evolutions[i].method != EVOLUTIONS_END; i++)
        {
            if (evolutions[i].method == EVO_ITEM
                && evolutions[i].param == ITEM_MOON_STONE)
                ball->multiplier = 400;
        }
        break;
    case BALL_LOVE:
        if (mon->species == gBattleMons[gBattlerAttacker].species)
        {
            u8 gender1 = GetMonGender(GetBattlerMon(gBattlerTarget));
            u8 gender2 = GetMonGender(GetBattlerMon(gBattlerAttacker));

            if (gender1 != gender2 && gender1 != MON_GENDERLESS && gender2 != MON_GENDERLESS)
                ball->multiplier = 800;
        }
        break;
    case BALL_FAST:
        if (GetSpeciesBaseSpeed(mon->species) >= 100)
            ball->multiplier = 400;
        break;
    case BALL_HEAVY:
        i = GetSpeciesWeight(mon->species);
        if (B_HEAVY_BALL_MODIFIER >= GEN_7)
        {
            if (i < 1000)
                ball->flatBonus = -20;
            else if (i < 2000)
                ball->flatBonus = 0;
            else if (i < 3000)
                ball->flatBonus = 20;
            else
                ball->flatBonus = 30;
        }
        else if (B_HEAVY_BALL_MODIFIER >= GEN_4)
        {
            if (i < 2048)
                ball->flatBonus = -20;
            else if (i < 3072)
                ball->flatBonus = 20;
            else if (i < 4096)
                ball->flatBonus = 30;
            else
                ball->flatBonus = 40;
        }
        else
        {
            if (i < 1024)
                ball->flatBonus = -20;
            else if (i < 2048)
                ball->flatBonus = 0;
            else if (i < 3072)
                ball->flatBonus = 20;
            else if (i < 4096)
                ball->flatBonus = 30;
            else
                ball->flatBonus = 40;
        }
        break;
    case BALL_DREAM:
        if (B_DREAM_BALL_MODIFIER >= GEN_8 && (mon->status1 & STATUS1_SLEEP || (mon->ability == ABILITY_COMATOSE && !mon->volatiles.gastroAcid)))
            ball->multiplier = 400;
        break;
    case BALL_SAFARI:
        if (B_SAFARI_BALL_MODIFIER <= GEN_7)
            ball->multiplier = 150;
        break;
    case BALL_SPORT:
        if (B_SPORT_BALL_MODIFIER <= GEN_7)
            ball->multiplier = 150;
        break;
    case BALL_BEAST:
        ball->multiplier = 410;
        ball->divider = 4096;
        break;
    }

}

static const u8 sBadgeLevel[] = {
    25,
    30,
    35,
    40,
    45,
    50,
    55,
    60,
    100,
};

u32 ComputeCaptureOdds()
{
    struct BallData ball;
    ComputeBallData(&ball);

    if (ball.guaranteedCapture)
        return CAPTURE_GUARANTEED;
    struct BattlePokemon *mon = &gBattleMons[gBattlerTarget];
    u32 odds = (mon->maxHP * 3 -  mon->hp * 2);
    s32 catchRate;

    if (gBattleTypeFlags & BATTLE_TYPE_SAFARI)
        catchRate = gBattleStruct->safariCatchFactor * 1275 / 100;
    else
        catchRate = gSpeciesInfo[mon->species].catchRate;

    catchRate += ball.flatBonus;
    if (catchRate <= 0)
        catchRate = catchRate + ball.flatBonus;

    odds = odds * catchRate / (mon->maxHP * 3);
    odds = odds * ball.multiplier / ball.divider;

    u8 badgeCount = 0;
    for (u32 i = FLAG_BADGE01_GET; i < FLAG_BADGE01_GET + NUM_BADGES; i++)
    {
        if (FlagGet(i))
            badgeCount++;
    }
    if (GetConfig(CONFIG_MISSING_BADGE_CATCH_MALUS) == GEN_8 && badgeCount < NUM_BADGES && gBattleMons[gBattlerAttacker].level < mon->level)
        odds = odds * 410 / 4096;
    if (GetConfig(CONFIG_MISSING_BADGE_CATCH_MALUS) == GEN_9 && badgeCount < NUM_BADGES)
    {
        for (u32 i = badgeCount; i < NUM_BADGES && mon->level > sBadgeLevel[i]; i++)
            odds = odds * 4 / 5;
    }

    if (GetConfig(CONFIG_LOW_LEVEL_CATCH_BONUS) == GEN_8 && mon->level <= 20)
         odds = odds * (30 - mon->level) / 10;
    else if (GetConfig(CONFIG_LOW_LEVEL_CATCH_BONUS) >= GEN_9 && mon->level <= 13)
        odds = odds * (36 - (mon->level * 2)) / 10;

    if (mon->status1 & STATUS1_INCAPACITATED)
    {
        if (GetConfig(CONFIG_INCAPACITATED_CATCH_BONUS) >= GEN_5)
            odds = (odds * 25) / 10;
        else
            odds *= 2;
    }
    if (mon->status1 & STATUS1_CAN_MOVE)
        odds = odds * 15 / 10;

    return odds;
}

bool32 CriticalCapture(u32 odds)
{
    u32 numCaught;
    u32 totalDexCount;
    u32 charmBoost = 1;

    if (B_CRITICAL_CAPTURE == FALSE)
        return FALSE;

    if (B_CRITICAL_CAPTURE_LOCAL_DEX == TRUE)
        totalDexCount = HOENN_DEX_COUNT;
    else
        totalDexCount = NATIONAL_DEX_COUNT;

    if (CheckBagHasItem(ITEM_CATCHING_CHARM, 1))
        charmBoost = (100 + B_CATCHING_CHARM_BOOST) / 100;

    numCaught = GetNationalPokedexCount(FLAG_GET_CAUGHT);
    if (numCaught > (totalDexCount * 600) / 650)
        odds = (odds * (250 * charmBoost)) / 100;
    else if (numCaught > (totalDexCount * 450) / 650)
        odds = (odds * (200 * charmBoost)) / 100;
    else if (numCaught > (totalDexCount * 300) / 650)
        odds = (odds * (150 * charmBoost)) / 100;
    else if (numCaught > (totalDexCount * 150) / 650)
        odds = (odds * (100 * charmBoost)) / 100;
    else if (numCaught > (totalDexCount * 30) / 650)
        odds = (odds * (50 * charmBoost)) / 100;
    else
        return FALSE;

    if (odds > 255)
        odds = 255;

    odds /= 6;
    if (RandomUniform(RNG_BALLTHROW_CRITICAL, 0, MAX_u8) < odds)
        return TRUE;

    return FALSE;
}

u32 ComputeBallShakeOdds(u32 odds)
{
    odds = Sqrt(Sqrt(16711680 / odds));
    odds = 1048560 / odds;
    return odds;
}
