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
#include "party_menu.h"
#include "script.h"
#include "sound.h"
#include "sprite.h"
#include "task.h"
#include "random.h"
#include "constants/event_object_movement.h"
#include "constants/event_objects.h"
#include "constants/field_effects.h"
#include "constants/songs.h"

static void Task_DoFieldMove_Init(u8 taskId);
static void Task_DoFieldMove_ShowMonAfterPose(u8 taskId);
static void Task_DoFieldMove_WaitForMon(u8 taskId);
static void Task_DoFieldMove_RunFunc(u8 taskId);
static void rockSmashGenerateItemGen4(void);
static void rockSmashGenerateItemGen6(void);

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

static const enum Item Gen6DefaultSmashTable[] = {
    ITEM_STAR_PIECE,
    ITEM_HARD_STONE,
    ITEM_SOFT_SAND,
    ITEM_REVIVE,
    ITEM_MAX_REVIVE,
    ITEM_ETHER,
    ITEM_MAX_ETHER,
    ITEM_PEARL,
    ITEM_BIG_PEARL,
    ITEM_HEART_SCALE,
    ITEM_NORMAL_GEM,
};

static const enum Item Gen6FossilSmashTable[] = {
    ITEM_DOME_FOSSIL,
    ITEM_ARMOR_FOSSIL,
    ITEM_PLUME_FOSSIL,
    ITEM_OLD_AMBER,
    ITEM_HELIX_FOSSIL,
    ITEM_SKULL_FOSSIL,
    ITEM_COVER_FOSSIL,
};

static const enum Item Gen4DefaultSmashTable[] = {
    ITEM_MAX_ETHER,     //25
    ITEM_REVIVE,        //20
    ITEM_HEART_SCALE,   //10
    ITEM_RED_SHARD,
    ITEM_GREEN_SHARD,
    ITEM_BLUE_SHARD,
    ITEM_YELLOW_SHARD,
    ITEM_STAR_PIECE,    //5
};

static const enum Item Gen4RuinsOfAlphSmashTable[] = {
    ITEM_RED_SHARD,     //25
    ITEM_YELLOW_SHARD,  //20
    ITEM_HELIX_FOSSIL,  //10
    ITEM_MAX_ETHER,
    ITEM_BLUE_SHARD,
    ITEM_GREEN_SHARD,
    ITEM_OLD_AMBER,
    ITEM_MAX_REVIVE,    //5
};

static const enum Item Gen4CliffCaveSmashTable[] = {
    ITEM_MAX_ETHER, //25
    ITEM_PEARL,     //20
    ITEM_BIG_PEARL, //10
    ITEM_RED_SHARD,
    ITEM_YELLOW_SHARD,
    ITEM_CLAW_FOSSIL,
    ITEM_CLAW_FOSSIL,
    ITEM_RARE_BONE, //5
};

void rockSmashGenerateItem(struct ScriptContext *ctx)
{
    if (OW_ROCK_SMASH_ITEMS == GEN_6)
        rockSmashGenerateItemGen6();
    else if (OW_ROCK_SMASH_ITEMS == GEN_4)
        rockSmashGenerateItemGen4();
    else
        VarSet(VAR_0x8005, ITEM_NONE);
    return;
}




static void rockSmashGenerateItemGen4(void)
{
    enum Item item = ITEM_NONE;

    if (gMapHeader.mapType == MAP_TYPE_INDOOR)
    {
        VarSet(VAR_0x8005, ITEM_NONE);// Not given in burned tower
        return;
    }
    u32 randomItem = RandomWeighted(RNG_NONE, 5, 4, 2, 2, 2, 2, 2, 1);

    //Tip: if you want the item table to vary between different breakable rocks, take a look at GetItemBallAmountFromTemplate(gSpecialVar_LastTalked - 1). This pulls data from the x view radius of var_last_talked.

    if (randomItem < 7)
    {
        u32 partySlot = VarGet(VAR_0x8006);
        enum Ability ability = GetMonAbility(&gParties[B_TRAINER_PLAYER][partySlot]);
        if (ability == ABILITY_SERENE_GRACE
           || ability == ABILITY_SUPER_LUCK)
            randomItem++;
    }   

    if ((gMapHeader.mapType == MAP_TYPE_OCEAN_ROUTE)
            || (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(MAP_CAVE_OF_ORIGIN_B1F) &&
            gSaveBlock1Ptr->location.mapNum == MAP_NUM(MAP_CAVE_OF_ORIGIN_B1F))) 
            // These are examples for unique locations for fossils.
        item = Gen4RuinsOfAlphSmashTable[randomItem];

    else if (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(MAP_ARTISAN_CAVE_B1F) &&
            gSaveBlock1Ptr->location.mapNum == MAP_NUM(MAP_ARTISAN_CAVE_B1F))
        item = Gen4CliffCaveSmashTable[randomItem];

    else
        item = Gen4DefaultSmashTable[randomItem];

    VarSet(VAR_0x8005, item);
}


static void rockSmashGenerateItemGen6(void)
{
    enum Item item = ITEM_NONE;

    if (gMapHeader.mapType == MAP_TYPE_INDOOR)
    {
        VarSet(VAR_0x8005, ITEM_NONE);// Not given in trick house
        return;
    }
    else if ((gMapHeader.mapType == MAP_TYPE_OCEAN_ROUTE)
            || (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(MAP_CAVE_OF_ORIGIN_B1F) &&
            gSaveBlock1Ptr->location.mapNum == MAP_NUM(MAP_CAVE_OF_ORIGIN_B1F))) 
            // These are example code for unique locations for fossils. They do not happen in game. In ORAS this table is used in mirage islands or Glittering Cave in XY.
            // If you want the item table to vary between different breakable rocks, take a look at GetItemBallAmountFromTemplate(gSpecialVar_LastTalked - 1). This pulls data from the x view radius of var_last_talked.
    {
        u32 randomNumber = Random() % ARRAY_COUNT(Gen6FossilSmashTable);
        VarSet(VAR_0x8005, Gen6FossilSmashTable[randomNumber]);
        return;
    }
    u32 randomNumber = Random() % ARRAY_COUNT(Gen6DefaultSmashTable);
    item = Gen6DefaultSmashTable[randomNumber];

    VarSet(VAR_0x8005, item);
}
