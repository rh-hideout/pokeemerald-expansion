#include "global.h"
#include "clock.h"
#include "new_game.h"
#include "random.h"
#include "pokemon.h"
#include "roamer.h"
#include "pokemon_size_record.h"
#include "script.h"
#include "lottery_corner.h"
#include "play_time.h"
#include "mauville_old_man.h"
#include "match_call.h"
#include "lilycove_lady.h"
#include "load_save.h"
#include "pokeblock.h"
#include "dewford_trend.h"
#include "berry.h"
#include "rtc.h"
#include "easy_chat.h"
#include "event_data.h"
#include "money.h"
#include "trainer_hill.h"
#include "trainer_tower.h"
#include "tv.h"
#include "coins.h"
#include "text.h"
#include "overworld.h"
#include "mail.h"
#include "battle_records.h"
#include "item.h"
#include "pokedex.h"
#include "apprentice.h"
#include "frontier_util.h"
#include "pokedex.h"
#include "save.h"
#include "link_rfu.h"
#include "main.h"
#include "contest.h"
#include "item_menu.h"
#include "pokemon_storage_system.h"
#include "pokemon_jump.h"
#include "decoration_inventory.h"
#include "secret_base.h"
#include "string_util.h"
#include "player_pc.h"
#include "field_specials.h"
#include "berry_powder.h"
#include "mystery_gift.h"
#include "union_room_chat.h"
#include "constants/map_groups.h"
#include "constants/items.h"
#include "difficulty.h"
#include "follower_npc.h"
#include "malloc.h"

extern const u8 EventScript_ResetAllMapFlags[];
extern const u8 EventScript_ResetAllMapFlagsFrlg[];

static void ClearFrontierRecord(void);
static void WarpToTruck(void);
static void ResetMiniGamesRecords(void);
static void ResetItemFlags(void);
static void ResetDexNav(void);

EWRAM_DATA bool8 gDifferentSaveFile = FALSE;
EWRAM_DATA bool8 gEnableContestDebugging = FALSE;
EWRAM_DATA bool8 gIsNewGamePlus = FALSE;

static const struct ContestWinner sContestWinnerPicDummy =
{
    .monName = _(""),
    .trainerName = _("")
};

void SetTrainerId(u32 trainerId, u8 *dst)
{
    dst[0] = trainerId;
    dst[1] = trainerId >> 8;
    dst[2] = trainerId >> 16;
    dst[3] = trainerId >> 24;
}

u32 GetTrainerId(u8 *trainerId)
{
    return (trainerId[3] << 24) | (trainerId[2] << 16) | (trainerId[1] << 8) | (trainerId[0]);
}

void CopyTrainerId(u8 *dst, u8 *src)
{
    s32 i;
    for (i = 0; i < TRAINER_ID_LENGTH; i++)
        dst[i] = src[i];
}

static void InitPlayerTrainerId(void)
{
    u32 trainerId = (Random() << 16) | GetGeneratedTrainerIdLower();
    SetTrainerId(trainerId, gSaveBlock2Ptr->playerTrainerId);
}

// L=A isnt set here for some reason.
static void SetDefaultOptions(void)
{
    gSaveBlock2Ptr->optionsTextSpeed = OPTIONS_TEXT_SPEED_FAST;
    gSaveBlock2Ptr->optionsWindowFrameType = 0;
    gSaveBlock2Ptr->optionsSound = OPTIONS_SOUND_STEREO;
    gSaveBlock2Ptr->optionsBattleStyle = OPTIONS_BATTLE_STYLE_SHIFT;
    gSaveBlock2Ptr->optionsBattleSceneOff = FALSE;
    gSaveBlock2Ptr->regionMapZoom = FALSE;
}

static void ClearPokedexFlags(void)
{
    gUnusedPokedexU8 = 0;
    memset(&gSaveBlock1Ptr->dexCaught, 0, sizeof(gSaveBlock1Ptr->dexCaught));
    memset(&gSaveBlock1Ptr->dexSeen, 0, sizeof(gSaveBlock1Ptr->dexSeen));
}

void ClearAllContestWinnerPics(void)
{
    s32 i;

    ClearContestWinnerPicsInContestHall();

    // Clear Museum paintings
    for (i = MUSEUM_CONTEST_WINNERS_START; i < NUM_CONTEST_WINNERS; i++)
        gSaveBlock1Ptr->contestWinners[i] = sContestWinnerPicDummy;
}

static void ClearFrontierRecord(void)
{
    CpuFill32(0, &gSaveBlock2Ptr->frontier, sizeof(gSaveBlock2Ptr->frontier));

    gSaveBlock2Ptr->frontier.opponentNames[0][0] = EOS;
    gSaveBlock2Ptr->frontier.opponentNames[1][0] = EOS;
}

static void WarpToTruck(void)
{
    if (IS_FRLG)
        SetWarpDestination(MAP_GROUP(MAP_PALLET_TOWN_PLAYERS_HOUSE_2F), MAP_NUM(MAP_PALLET_TOWN_PLAYERS_HOUSE_2F), WARP_ID_NONE, 6, 6);
    else
        SetWarpDestination(MAP_GROUP(MAP_INSIDE_OF_TRUCK), MAP_NUM(MAP_INSIDE_OF_TRUCK), WARP_ID_NONE, -1, -1);
    WarpIntoMap();
}

void Sav2_ClearSetDefault(void)
{
    ClearSav2();
    SetDefaultOptions();
}

void ResetMenuAndMonGlobals(void)
{
    gDifferentSaveFile = FALSE;
    ResetPokedexScrollPositions();
    ZeroPlayerPartyMons();
    ZeroEnemyPartyMons();
    ResetBagScrollPositions();
    ResetPokeblockScrollPositions();
}

void NewGameInitData(void)
{
    bool8 isNewGamePlus = gIsNewGamePlus;
    struct Pokemon *playerPartyBackup = NULL;
    u8 playerPartyCountBackup = 0;
    void *pcStorageBackup = NULL;
    void *pcItemsBackup = NULL;
    void *bagItemsBackup = NULL;
    // void *bagKeyItemsBackup = NULL;
    void *bagPokeBallsBackup = NULL;
    // void *bagTMHMsBackup = NULL;
    void *bagBerriesBackup = NULL;
    void *dexCaughtBackup = NULL;
    void *dexSeenBackup = NULL;
    void *flagsBackup = NULL;
    void *optionsBackup = NULL;
    void *playerSettingsBackup = NULL;
    u8 savedTrainerId[TRAINER_ID_LENGTH];
    u32 moneyBackup = 0;
    u16 coinsBackup = 0;
    void *roamersBackup = NULL;
    void *locationHistoryBackup = NULL;
    void *roamerLocationBackup = NULL;

#if IS_FRLG
    u8 rivalName[PLAYER_NAME_LENGTH + 1];
#endif
    if (gSaveFileStatus == SAVE_STATUS_EMPTY || gSaveFileStatus == SAVE_STATUS_CORRUPT)
        RtcReset();

    if (isNewGamePlus)
    {
        /* Backup things we want to preserve */
        CopyTrainerId(savedTrainerId, gSaveBlock2Ptr->playerTrainerId);

        playerPartyBackup = Alloc(sizeof(gSaveBlock1Ptr->playerParty));
        memcpy(playerPartyBackup, gSaveBlock1Ptr->playerParty, sizeof(gSaveBlock1Ptr->playerParty));
        playerPartyCountBackup = gSaveBlock1Ptr->playerPartyCount;

        pcStorageBackup = Alloc(sizeof(*gPokemonStoragePtr));
        memcpy(pcStorageBackup, gPokemonStoragePtr, sizeof(*gPokemonStoragePtr));

        pcItemsBackup = Alloc(sizeof(gSaveBlock1Ptr->pcItems));
        memcpy(pcItemsBackup, gSaveBlock1Ptr->pcItems, sizeof(gSaveBlock1Ptr->pcItems));

        bagItemsBackup = Alloc(sizeof(gSaveBlock1Ptr->bag.items));
        memcpy(bagItemsBackup, gSaveBlock1Ptr->bag.items, sizeof(gSaveBlock1Ptr->bag.items));

        // bagKeyItemsBackup = Alloc(sizeof(gSaveBlock1Ptr->bag.keyItems));
        // memcpy(bagKeyItemsBackup, gSaveBlock1Ptr->bag.keyItems, sizeof(gSaveBlock1Ptr->bag.keyItems));

        bagPokeBallsBackup = Alloc(sizeof(gSaveBlock1Ptr->bag.pokeBalls));
        memcpy(bagPokeBallsBackup, gSaveBlock1Ptr->bag.pokeBalls, sizeof(gSaveBlock1Ptr->bag.pokeBalls));

        // bagTMHMsBackup = Alloc(sizeof(gSaveBlock1Ptr->bag.TMsHMs));
        // memcpy(bagTMHMsBackup, gSaveBlock1Ptr->bag.TMsHMs, sizeof(gSaveBlock1Ptr->bag.TMsHMs));

        bagBerriesBackup = Alloc(sizeof(gSaveBlock1Ptr->bag.berries));
        memcpy(bagBerriesBackup, gSaveBlock1Ptr->bag.berries, sizeof(gSaveBlock1Ptr->bag.berries));

        dexCaughtBackup = Alloc(sizeof(gSaveBlock1Ptr->dexCaught));
        memcpy(dexCaughtBackup, gSaveBlock1Ptr->dexCaught, sizeof(gSaveBlock1Ptr->dexCaught));

        dexSeenBackup = Alloc(sizeof(gSaveBlock1Ptr->dexSeen));
        memcpy(dexSeenBackup, gSaveBlock1Ptr->dexSeen, sizeof(gSaveBlock1Ptr->dexSeen));
        /* Backup money and coins so they persist through ClearSav1 */
        moneyBackup = GetMoney(&gSaveBlock1Ptr->money);
        coinsBackup = GetCoins();

        roamersBackup = Alloc(sizeof(gSaveBlock1Ptr->roamer));
        memcpy(roamersBackup, gSaveBlock1Ptr->roamer, sizeof(gSaveBlock1Ptr->roamer));

        locationHistoryBackup = Alloc(sizeof(sLocationHistory));
        memcpy(locationHistoryBackup, sLocationHistory, sizeof(sLocationHistory));

        roamerLocationBackup = Alloc(sizeof(sRoamerLocation));
        memcpy(roamerLocationBackup, sRoamerLocation, sizeof(sRoamerLocation));

        /* Backup only option-related flag bytes (minimize restoring unrelated flags) */
        flagsBackup = Alloc(3);
        ((u8 *)flagsBackup)[0] = gSaveBlock1Ptr->flags[FLAG_AI_BATTLES / 8];
        ((u8 *)flagsBackup)[1] = gSaveBlock1Ptr->flags[FLAG_AUTO_SCROLL_TEXT / 8];
        ((u8 *)flagsBackup)[2] = gSaveBlock1Ptr->flags[FLAG_RANDOMIZE_TYPE / 8];

        /* Backup SaveBlock2 options (packed bitfields occupy 2 bytes at offset 0x14) */
        optionsBackup = Alloc(sizeof(u16));
        memcpy(optionsBackup, (u8 *)gSaveBlock2Ptr + 0x14, sizeof(u16));
        /* Backup a few SaveBlock1 player settings stored in SaveBlock1 */
        playerSettingsBackup = Alloc(3);
        ((u8 *)playerSettingsBackup)[0] = gSaveBlock1Ptr->nuzlockeModeEnabled;
        ((u8 *)playerSettingsBackup)[1] = gSaveBlock1Ptr->autosaveModeEnabled;
        ((u8 *)playerSettingsBackup)[2] = gSaveBlock1Ptr->difficulty;

        gIsNewGamePlus = FALSE; // consume flag
    }

#if IS_FRLG
    StringCopy(rivalName, gSaveBlock1Ptr->rivalName);
#endif
    gDifferentSaveFile = TRUE;
    /* Keep existing encryptionKey when doing New Game+ to avoid re-encryption issues */
    if (!isNewGamePlus)
    {
        gSaveBlock2Ptr->encryptionKey = 0;
        ZeroPlayerPartyMons();
        ResetPokedex();
        InitPlayerTrainerId();
        PlayTimeCounter_Reset();
        ClearPokedexFlags();
        ResetPokemonStorageSystem();
        gPartiesCount[B_TRAINER_PLAYER] = 0;
        NewGameInitPCItems();
        // SetCurrentDifficultyLevel(DIFFICULTY_NORMAL); // OLD DIFFICULTY IMPLEMENTATION
        gSaveBlock2Ptr->newGamePlus = 0;
        ResetItemFlags();
        ResetDexNav();
    }
    ZeroEnemyPartyMons();
    ClearFrontierRecord();
    ClearSav1();
    if (!isNewGamePlus)
    {
        gSaveBlock1Ptr->difficulty = 1;
        SetMoney(&gSaveBlock1Ptr->money, 5000);
        DeactivateAllRoamers();
        SetCoins(0);
    }
    ClearSav3();
    ClearAllMail();
    gSaveBlock2Ptr->specialSaveWarpFlags = 0;
    gSaveBlock2Ptr->gcnLinkFlags = 0;
    InitEventData();
    ClearTVShowData();
    ResetGabbyAndTy();
    ClearSecretBases();
    ClearBerryTrees();
    ResetLinkContestBoolean();
    ResetGameStats();
    ClearAllContestWinnerPics();
    ClearPlayerLinkBattleRecords();
    InitSeedotSizeRecord();
    InitLotadSizeRecord();
    gSaveBlock1Ptr->registeredItem = ITEM_NONE;
    gSaveBlock1Ptr->registeredLongItem = ITEM_NONE;
    ClearBag();
    ClearPokeblocks();
    ClearDecorationInventories();
    InitEasyChatPhrases();
    SetMauvilleOldMan();
    InitDewfordTrend();
    ResetFanClub();
    ResetLotteryCorner();
    UpdateDailySeed();
    WarpToTruck();
    if (IS_FRLG)
        RunScriptImmediately(EventScript_ResetAllMapFlagsFrlg);
    else
        RunScriptImmediately(EventScript_ResetAllMapFlags);
#if IS_FRLG
        StringCopy(gSaveBlock1Ptr->rivalName, rivalName);
#endif
    ResetMiniGamesRecords();
    InitUnionRoomChatRegisteredTexts();
    InitLilycoveLady();
    ResetAllApprenticeData();
    ClearRankingHallRecords();
    InitMatchCallCounters();
    ClearMysteryGift();
    WipeTrainerNameRecords();
    ResetTrainerHillResults();
    ResetTrainerTowerResults();
    ResetContestLinkResults();
    ClearFollowerNPCData();

    /* Restore preserved data for New Game+ */
    if (isNewGamePlus)
    {
        if (playerPartyBackup != NULL)
        {
            memcpy(gSaveBlock1Ptr->playerParty, playerPartyBackup, sizeof(gSaveBlock1Ptr->playerParty));
            gSaveBlock1Ptr->playerPartyCount = playerPartyCountBackup;
            memcpy(gPokemonStoragePtr, pcStorageBackup, sizeof(*gPokemonStoragePtr));
            memcpy(gSaveBlock1Ptr->pcItems, pcItemsBackup, sizeof(gSaveBlock1Ptr->pcItems));
            memcpy(gSaveBlock1Ptr->bag.items, bagItemsBackup, sizeof(gSaveBlock1Ptr->bag.items));
            // memcpy(gSaveBlock1Ptr->bag.keyItems, bagKeyItemsBackup, sizeof(gSaveBlock1Ptr->bag.keyItems));
            memcpy(gSaveBlock1Ptr->bag.pokeBalls, bagPokeBallsBackup, sizeof(gSaveBlock1Ptr->bag.pokeBalls));
            // memcpy(gSaveBlock1Ptr->bag.TMsHMs, bagTMHMsBackup, sizeof(gSaveBlock1Ptr->bag.TMsHMs));
            memcpy(gSaveBlock1Ptr->bag.berries, bagBerriesBackup, sizeof(gSaveBlock1Ptr->bag.berries));
            CopyTrainerId(gSaveBlock2Ptr->playerTrainerId, savedTrainerId);

            /* Restore Pokédex flags preserved across ClearSav1 */
            if (dexCaughtBackup != NULL)
                memcpy(gSaveBlock1Ptr->dexCaught, dexCaughtBackup, sizeof(gSaveBlock1Ptr->dexCaught));
            if (dexSeenBackup != NULL)
                memcpy(gSaveBlock1Ptr->dexSeen, dexSeenBackup, sizeof(gSaveBlock1Ptr->dexSeen));

            /* Restore option-related flags from backup (only these specific settings) */
            if (flagsBackup != NULL)
            {
                u8 *fb = (u8 *)flagsBackup;
                (fb[0] & (1 << (FLAG_AI_BATTLES % 8))) ? FlagSet(FLAG_AI_BATTLES) : FlagClear(FLAG_AI_BATTLES);
                (fb[1] & (1 << (FLAG_AUTO_SCROLL_TEXT % 8))) ? FlagSet(FLAG_AUTO_SCROLL_TEXT) : FlagClear(FLAG_AUTO_SCROLL_TEXT);
                (fb[1] & (1 << (FLAG_RANDOMIZE_MON % 8))) ? FlagSet(FLAG_RANDOMIZE_MON) : FlagClear(FLAG_RANDOMIZE_MON);
                (fb[2] & (1 << (FLAG_RANDOMIZE_TYPE % 8))) ? FlagSet(FLAG_RANDOMIZE_TYPE) : FlagClear(FLAG_RANDOMIZE_TYPE);
                (fb[2] & (1 << (FLAG_RANDOMIZE_MOVES % 8))) ? FlagSet(FLAG_RANDOMIZE_MOVES) : FlagClear(FLAG_RANDOMIZE_MOVES);
                (fb[2] & (1 << (FLAG_LEVEL_CAP_OFF % 8))) ? FlagSet(FLAG_LEVEL_CAP_OFF) : FlagClear(FLAG_LEVEL_CAP_OFF);
                (fb[2] & (1 << (FLAG_AI_WILD_BATTLES % 8))) ? FlagSet(FLAG_AI_WILD_BATTLES) : FlagClear(FLAG_AI_WILD_BATTLES);
                (fb[2] & (1 << (FLAG_ALLOW_STAT_EDITOR % 8))) ? FlagSet(FLAG_ALLOW_STAT_EDITOR) : FlagClear(FLAG_ALLOW_STAT_EDITOR);
            }

            if (optionsBackup != NULL)
                memcpy((u8 *)gSaveBlock2Ptr + 0x14, optionsBackup, sizeof(u16));

            if (playerSettingsBackup != NULL)
            {
                gSaveBlock1Ptr->nuzlockeModeEnabled = ((u8 *)playerSettingsBackup)[0];
                gSaveBlock1Ptr->autosaveModeEnabled = ((u8 *)playerSettingsBackup)[1];
                gSaveBlock1Ptr->difficulty = ((u8 *)playerSettingsBackup)[2];
            }

            if (roamersBackup != NULL)
                memcpy(gSaveBlock1Ptr->roamer, roamersBackup, sizeof(gSaveBlock1Ptr->roamer));
            if (locationHistoryBackup != NULL)
                memcpy(sLocationHistory, locationHistoryBackup, sizeof(sLocationHistory));
            if (roamerLocationBackup != NULL)
                memcpy(sRoamerLocation, roamerLocationBackup, sizeof(sRoamerLocation));

            /* Restore money and coins preserved across ClearSav1 */
            SetMoney(&gSaveBlock1Ptr->money, moneyBackup);
            SetCoins(coinsBackup);

            /* Load restored party into runtime structures so follower code has mons available. */
            LoadPlayerParty();

            /* Increase New Game+ counter in save (0-255) */
            gSaveBlock2Ptr->newGamePlus++;
        }

        if (playerPartyBackup != NULL)
            Free(playerPartyBackup);
        if (pcStorageBackup != NULL)
            Free(pcStorageBackup);
        if (pcItemsBackup != NULL)
            Free(pcItemsBackup);
        if (bagItemsBackup != NULL)
            Free(bagItemsBackup);
        if (dexCaughtBackup != NULL)
            Free(dexCaughtBackup);
        if (dexSeenBackup != NULL)
            Free(dexSeenBackup);
        if (flagsBackup != NULL)
            Free(flagsBackup);
        if (optionsBackup != NULL)
            Free(optionsBackup);
        if (playerSettingsBackup != NULL)
            Free(playerSettingsBackup);
        if (roamersBackup != NULL)
            Free(roamersBackup);
        if (locationHistoryBackup != NULL)
            Free(locationHistoryBackup);
        if (roamerLocationBackup != NULL)
            Free(roamerLocationBackup);
        // if (bagKeyItemsBackup != NULL)
        //     Free(bagKeyItemsBackup);
        if (bagPokeBallsBackup != NULL)
            Free(bagPokeBallsBackup);
        // if (bagTMHMsBackup != NULL)
        //     Free(bagTMHMsBackup);
        if (bagBerriesBackup != NULL)
            Free(bagBerriesBackup);
    }
}

static void ResetMiniGamesRecords(void)
{
    CpuFill16(0, &gSaveBlock2Ptr->berryCrush, sizeof(struct BerryCrush));
    SetBerryPowder(&gSaveBlock2Ptr->berryCrush.berryPowderAmount, 0);
    ResetPokemonJumpRecords();
    CpuFill16(0, &gSaveBlock2Ptr->berryPick, sizeof(struct BerryPickingResults));
}

static void ResetItemFlags(void)
{
#if OW_SHOW_ITEM_DESCRIPTIONS == OW_ITEM_DESCRIPTIONS_FIRST_TIME
    memset(&gSaveBlock3Ptr->itemFlags, 0, sizeof(gSaveBlock3Ptr->itemFlags));
#endif
}

static void ResetDexNav(void)
{
#if USE_DEXNAV_SEARCH_LEVELS == TRUE
    memset(gSaveBlock3Ptr->dexNavSearchLevels, 0, sizeof(gSaveBlock3Ptr->dexNavSearchLevels));
#endif
    gSaveBlock3Ptr->dexNavChain = 0;
}

// Script-native: sets VAR_RESULT to 1 if save's newGamePlus counter is > 0, otherwise 0
void CheckNewGamePlus(struct ScriptContext *ctx)
{
    u16 val = (gSaveBlock2Ptr->newGamePlus > 0) ? 1 : 0;
    VarSet(VAR_RESULT, val);
}
