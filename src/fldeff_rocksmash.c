#include "global.h"
#include "braille_puzzles.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "event_scripts.h"
#include "field_effect.h"
#include "field_player_avatar.h"
#include "fldeff.h"
#include "item_use.h"
#include "overworld.h"
#include "ow_abilities.h"
#include "party_menu.h"
#include "fldeff.h"
#include "script.h"
#include "sound.h"
#include "sprite.h"
#include "task.h"
#include "random.h"
#include "wild_encounter.h"
#include "constants/event_object_movement.h"
#include "constants/event_objects.h"
#include "constants/field_effects.h"
#include "constants/field_specials.h"
#include "constants/rock_smash_item_tables.h"
#include "constants/songs.h"

struct RockSmashItemTable {
    const enum Item *table;
    const u16 *weights; //if NULL, there will be equal chance to roll any item on the table
    u16 size;
    u16 weightsSum;
};

#include "data/rock_smash_items.h"

static void Task_DoFieldMove_Init(u8 taskId);
static void Task_DoFieldMove_ShowMonAfterPose(u8 taskId);
static void Task_DoFieldMove_WaitForMon(u8 taskId);
static void Task_DoFieldMove_RunFunc(u8 taskId);

static void FieldCallback_RockSmash(void);
static void FieldMove_RockSmash(void);

bool8 CheckObjectGraphicsInFrontOfPlayer(u16 graphicsId)
{
    u8 objEventId;

    GetXYCoordsOneStepInFrontOfPlayer(&gPlayerFacingPosition.x, &gPlayerFacingPosition.y);
    gPlayerFacingPosition.elevation = PlayerGetElevation();
    objEventId = GetObjectEventIdByPosition(gPlayerFacingPosition.x, gPlayerFacingPosition.y, gPlayerFacingPosition.elevation);
    if (gObjectEvents[objEventId].graphicsId != graphicsId)
    {
        return FALSE;
    }
    else
    {
        gSpecialVar_LastTalked = gObjectEvents[objEventId].localId;
        return TRUE;
    }
}

u8 CreateFieldMoveTask(void)
{
    GetXYCoordsOneStepInFrontOfPlayer(&gPlayerFacingPosition.x, &gPlayerFacingPosition.y);
    return CreateTask(Task_DoFieldMove_Init, 8);
}

static void Task_DoFieldMove_Init(u8 taskId)
{
    u8 objEventId;

    LockPlayerFieldControls();
    gPlayerAvatar.preventStep = TRUE;
    objEventId = gPlayerAvatar.objectEventId;
    if (!ObjectEventIsMovementOverridden(&gObjectEvents[objEventId])
     || ObjectEventClearHeldMovementIfFinished(&gObjectEvents[objEventId]))
    {
        if (gMapHeader.mapType == MAP_TYPE_UNDERWATER || gFieldEffectArguments[3])
        {
            // Skip field move pose underwater, or if arg3 is nonzero
            if (gFieldEffectArguments[3])
                gFieldEffectArguments[3] = 0;
            FieldEffectStart(FLDEFF_FIELD_MOVE_SHOW_MON_INIT);
            gTasks[taskId].func = Task_DoFieldMove_WaitForMon;
        }
        else
        {
            // Do field move pose
            SetPlayerAvatarFieldMove();
            ObjectEventSetHeldMovement(&gObjectEvents[objEventId], MOVEMENT_ACTION_START_ANIM_IN_DIRECTION);
            gTasks[taskId].func = Task_DoFieldMove_ShowMonAfterPose;
        }
    }
}

static void Task_DoFieldMove_ShowMonAfterPose(u8 taskId)
{
    if (ObjectEventCheckHeldMovementStatus(&gObjectEvents[gPlayerAvatar.objectEventId]) == TRUE)
    {
        FieldEffectStart(FLDEFF_FIELD_MOVE_SHOW_MON_INIT);
        gTasks[taskId].func = Task_DoFieldMove_WaitForMon;
    }
}

static void Task_DoFieldMove_WaitForMon(u8 taskId)
{
    if (!FieldEffectActiveListContains(FLDEFF_FIELD_MOVE_SHOW_MON))
    {
        gFieldEffectArguments[1] = GetPlayerFacingDirection();
        if (gFieldEffectArguments[1] == DIR_SOUTH)
            gFieldEffectArguments[2] = 0;
        if (gFieldEffectArguments[1] == DIR_NORTH)
            gFieldEffectArguments[2] = 1;
        if (gFieldEffectArguments[1] == DIR_WEST)
            gFieldEffectArguments[2] = 2;
        if (gFieldEffectArguments[1] == DIR_EAST)
            gFieldEffectArguments[2] = 3;
        ObjectEventSetGraphicsId(&gObjectEvents[gPlayerAvatar.objectEventId], GetPlayerAvatarGraphicsIdByCurrentState());
        StartSpriteAnim(&gSprites[gPlayerAvatar.spriteId], gFieldEffectArguments[2]);
        FieldEffectActiveListRemove(FLDEFF_FIELD_MOVE_SHOW_MON);
        gTasks[taskId].func = Task_DoFieldMove_RunFunc;
    }
}

static void Task_DoFieldMove_RunFunc(u8 taskId)
{
    // The function for the field move to do is stored in halves across data[8] and data[9]
    void (*fieldMoveFunc)(void) = (void (*)(void))(((u16)gTasks[taskId].data[8] << 16) | (u16)gTasks[taskId].data[9]);

    fieldMoveFunc();
    gPlayerAvatar.preventStep = FALSE;
    DestroyTask(taskId);
}

// Called when Rock Smash is used from the party menu
// For interacting with a smashable rock in the field, see EventScript_RockSmash
bool32 SetUpFieldMove_RockSmash(void)
{
    // In Ruby and Sapphire, Regirock's tomb is opened by using Strength. In Emerald,
    // it is opened by using Rock Smash.
    if (ShouldDoBrailleRegirockEffect())
    {
        gSpecialVar_Result = GetCursorSelectionMonId();
        gFieldCallback2 = FieldCallback_PrepareFadeInFromMenu;
        gPostMenuFieldCallback = SetUpPuzzleEffectRegirock;
        return TRUE;
    }
    else if (CheckObjectGraphicsInFrontOfPlayer(OBJ_EVENT_GFX_BREAKABLE_ROCK) == TRUE)
    {
        gFieldCallback2 = FieldCallback_PrepareFadeInFromMenu;
        gPostMenuFieldCallback = FieldCallback_RockSmash;
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

static void FieldCallback_RockSmash(void)
{
    gFieldEffectArguments[0] = GetCursorSelectionMonId();
    ScriptContext_SetupScript(EventScript_UseRockSmash);
}

bool8 FldEff_UseRockSmash(void)
{
    u8 taskId = CreateFieldMoveTask();

    gTasks[taskId].data[8] = (u32)FieldMove_RockSmash >> 16;
    gTasks[taskId].data[9] = (u32)FieldMove_RockSmash;
    IncrementGameStat(GAME_STAT_USED_ROCK_SMASH);
    return FALSE;
}

// The actual rock smashing is handled by EventScript_SmashRock, so this function does very little
static void FieldMove_RockSmash(void)
{
    PlaySE(SE_M_ROCK_THROW);
    FieldEffectActiveListRemove(FLDEFF_USE_ROCK_SMASH);
    ScriptContext_Enable();
}

static enum Item GetRockSmashRandomItem(void)
{
    u32 itemTable = gMapHeader.events->objectEvents[(gSpecialVar_LastTalked - 1)].trainerRange_berryTreeId;
    itemTable >>= 8;// remove data that is being used for probability

    assertf(itemTable < ROCK_SMASH_ITEM_TABLE_COUNT, "Unassigned or invalid rock smash item table %d", itemTable)
    {
        if ((gMapHeader.mapType == MAP_TYPE_OCEAN_ROUTE)
            || (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(MAP_SEAFLOOR_CAVERN_ROOM1)
            && (gSaveBlock1Ptr->location.mapNum == MAP_NUM(MAP_SEAFLOOR_CAVERN_ROOM1)
             || gSaveBlock1Ptr->location.mapNum == MAP_NUM(MAP_SEAFLOOR_CAVERN_ROOM2)
             || gSaveBlock1Ptr->location.mapNum == MAP_NUM(MAP_SEAFLOOR_CAVERN_ROOM5))))
            itemTable = ROCK_SMASH_ITEM_TABLE_CLIFF;
        else if (gMapHeader.mapType == MAP_TYPE_INDOOR)
            itemTable = ROCK_SMASH_ITEM_TABLE_NONE;
        else
            itemTable = ROCK_SMASH_ITEM_TABLE_DEFAULT;
    }
    if (itemTable == ROCK_SMASH_ITEM_TABLE_NONE)
    {
        return ITEM_NONE;
    }

    u32 randomIndex;
    if (sRockSmashTables[itemTable].weightsSum)// I.e. if using Gen 4 mechanics
    {
        randomIndex = RandomWeightedArray(RNG_ROCK_SMASH_ITEM_DROP, sRockSmashTables[itemTable].weightsSum, sRockSmashTables[itemTable].size, sRockSmashTables[itemTable].weights);
        if (randomIndex < sRockSmashTables[itemTable].size - 1)
        {
            u32 partySlot = VarGet(VAR_0x8006);
            if (DoesRockSmashUserHaveIncreasedItemRarity(partySlot))// Check for serene grace and super luck's impact on a weighted table.
                randomIndex++;
        }
    }
    else // Gen 6 mechanics
        randomIndex = RandomUniform(RNG_ROCK_SMASH_ITEM_DROP, 0, sRockSmashTables[itemTable].size - 1);

    return sRockSmashTables[itemTable].table[randomIndex];
}

void Scrcmd_rockSmashGenerateItem(struct ScriptContext *ctx)
{
    enum Item item = ITEM_NONE;
    if (OW_ROCK_SMASH_ITEMS >= GEN_4)
        item = GetRockSmashRandomItem();
    else
        errorf("Trying to get rock smash item but the OW_ROCK_SMASH_ITEMS config doesn't allow it");
    VarSet(VAR_0x8005, item);
}
