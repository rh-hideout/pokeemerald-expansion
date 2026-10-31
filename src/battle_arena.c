#include "global.h"
#include "battle.h"
#include "battle_arena.h"
#include "battle_message.h"
#include "battle_setup.h"
#include "battle_tower.h"
#include "bg.h"
#include "decompress.h"
#include "event_data.h"
#include "frontier_util.h"
#include "graphics.h"
#include "gpu_regs.h"
#include "item.h"
#include "m4a.h"
#include "overworld.h"
#include "palette.h"
#include "random.h"
#include "sound.h"
#include "string_util.h"
#include "text.h"
#include "util.h"
#include "constants/songs.h"
#include "constants/battle_arena.h"
#include "constants/battle_move_effects.h"
#include "constants/battle_string_ids.h"
#include "constants/battle_frontier.h"
#include "constants/frontier_util.h"
#include "constants/items.h"
#include "constants/moves.h"
#include "constants/rgb.h"

static void Unsed_InitArenaChallenge(void);
static void Unused_GetArenaData(void);
static void Unused_SetArenaData(void);
static void SaveArenaChallenge(void);
static void Unused_SetArenaPrize(void);
static void Unused_GiveArenaPrize(void);
static void BufferArenaOpponentName(void);
static void SpriteCB_JudgmentIcon(struct Sprite *sprite);
static void ShowJudgmentSprite(u8 x, u8 y, u8 category, enum BattlerId battler);

#define JUDGMENT_STATE_FINISHED 8

#define TAG_JUDGMENT_ICON 1000

enum {
    ANIM_ICON_X,        // Player lost
    ANIM_ICON_TRIANGLE, // Tie
    ANIM_ICON_CIRCLE,   // Player won
    ANIM_ICON_LINE,     // Line segment for separating the score total at the bottom
};

static const struct OamData sOam_JudgmentIcon =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(16x16),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(16x16),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 15,
    .affineParam = 0
};

static const union AnimCmd sAnim_JudgmentIcon_X[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_JudgmentIcon_Triangle[] =
{
    ANIMCMD_FRAME(4, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_JudgmentIcon_Circle[] =
{
    ANIMCMD_FRAME(8, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_JudgmentIcon_Line[] =
{
    ANIMCMD_FRAME(12, 1),
    ANIMCMD_END
};

static const union AnimCmd *const sAnims_JudgmentIcon[] =
{
    [ANIM_ICON_X]        = sAnim_JudgmentIcon_X,
    [ANIM_ICON_TRIANGLE] = sAnim_JudgmentIcon_Triangle,
    [ANIM_ICON_CIRCLE]   = sAnim_JudgmentIcon_Circle,
    [ANIM_ICON_LINE]     = sAnim_JudgmentIcon_Line,
};

static const struct SpriteTemplate sSpriteTemplate_JudgmentIcon =
{
    .tileTag = TAG_JUDGMENT_ICON,
    .paletteTag = TAG_NONE,
    .oam = &sOam_JudgmentIcon,
    .anims = sAnims_JudgmentIcon,
    .callback = SpriteCB_JudgmentIcon,
};

static const struct CompressedSpriteSheet sBattleArenaJudgmentSymbolsSpriteSheet[] =
{
    {gBattleArenaJudgmentSymbolsGfx, 0x200, TAG_JUDGMENT_ICON},
    {0}
};

static void (*const sArenaFunctions[])(void) =
{
    [BATTLE_ARENA_FUNC_INIT]             = Unsed_InitArenaChallenge,
    [BATTLE_ARENA_FUNC_GET_DATA]         = Unused_GetArenaData,
    [BATTLE_ARENA_FUNC_SET_DATA]         = Unused_SetArenaData,
    [BATTLE_ARENA_FUNC_SAVE]             = SaveArenaChallenge,
    [BATTLE_ARENA_FUNC_SET_PRIZE]        = Unused_SetArenaPrize,
    [BATTLE_ARENA_FUNC_GIVE_PRIZE]       = Unused_GiveArenaPrize,
    [BATTLE_ARENA_FUNC_GET_TRAINER_NAME] = BufferArenaOpponentName,
};

void CallBattleArenaFunction(void)
{
    sArenaFunctions[gSpecialVar_0x8004]();
}

u8 BattleArena_ShowJudgmentWindow(u8 *state)
{
    int i;
    u8 result = ARENA_RESULT_RUNNING;
    switch (*state)
    {
    case 0:
        BeginNormalPaletteFade(0x7FFFFF1C, 4, 0, 8, RGB_BLACK);
        SetGpuReg(REG_OFFSET_WININ, (WININ_WIN0_ALL & ~WININ_WIN0_BG0) | WININ_WIN1_ALL);
        LoadCompressedSpriteSheet(sBattleArenaJudgmentSymbolsSpriteSheet);
        LoadPalette(gBattleArenaJudgmentSymbolsPalette, OBJ_PLTT_ID(15), PLTT_SIZE_4BPP);
        gBattle_WIN0H = 0xFF;
        gBattle_WIN0V = 0x70;
        (*state)++;
        break;
    case 1:
        if (!gPaletteFade.active)
        {
            HandleBattleWindow(5, 0, 24, 13, 0);
            (*state)++;
        }
        break;
    case 2:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            gBattleTextBuff1[0] = CHAR_0;
            gBattleTextBuff1[1] = EOS;
            gBattleTextBuff2[0] = CHAR_0;
            gBattleTextBuff2[1] = EOS;
            BattleStringExpandPlaceholdersToDisplayedString(gText_PlayerMon1Name);
            BattlePutTextOnWindow(gDisplayedStringBattle, ARENA_WIN_PLAYER_NAME);
            BattlePutTextOnWindow(gText_Vs, ARENA_WIN_VS);
            BattleStringExpandPlaceholdersToDisplayedString(gText_OpponentMon1Name);
            BattlePutTextOnWindow(gDisplayedStringBattle, ARENA_WIN_OPPONENT_NAME);
            BattlePutTextOnWindow(gText_Mind, ARENA_WIN_MIND);
            BattlePutTextOnWindow(gText_Skill, ARENA_WIN_SKILL);
            BattlePutTextOnWindow(gText_Body, ARENA_WIN_BODY);
            BattleStringExpandPlaceholdersToDisplayedString(gText_Judgment);
            BattlePutTextOnWindow(gDisplayedStringBattle, ARENA_WIN_JUDGMENT_TITLE);
            (*state)++;
        }
        break;
    case 3:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_ALL | WININ_WIN1_ALL);

            // Create dividing line for the the score totals at the bottom
            for (i = 0; i < 8; i++)
            {
                u8 spriteId = CreateSprite(&sSpriteTemplate_JudgmentIcon, 64 + i * 16, 84, 0);
                StartSpriteAnim(&gSprites[spriteId], ANIM_ICON_LINE);
            }
            result = ARENA_RESULT_STEP_DONE;
            (*state)++;
        }
        break;
    case 4:
        PlaySE(SE_ARENA_TIMEUP1);
        ShowJudgmentSprite(80, 40, ARENA_CATEGORY_MIND, GetBattlerAtPosition(B_POSITION_PLAYER_LEFT));
        ShowJudgmentSprite(160, 40, ARENA_CATEGORY_MIND, GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT));
        BattleStringExpandPlaceholdersToDisplayedString(gText_Judgment);
        BattlePutTextOnWindow(gDisplayedStringBattle, ARENA_WIN_JUDGMENT_TITLE);
        (*state)++;
        result = ARENA_RESULT_STEP_DONE;
        break;
    case 5:
        PlaySE(SE_ARENA_TIMEUP1);
        ShowJudgmentSprite(80, 56, ARENA_CATEGORY_SKILL, GetBattlerAtPosition(B_POSITION_PLAYER_LEFT));
        ShowJudgmentSprite(160, 56, ARENA_CATEGORY_SKILL, GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT));
        BattleStringExpandPlaceholdersToDisplayedString(gText_Judgment);
        BattlePutTextOnWindow(gDisplayedStringBattle, ARENA_WIN_JUDGMENT_TITLE);
        (*state)++;
        result = ARENA_RESULT_STEP_DONE;
        break;
    case 6:
        PlaySE(SE_ARENA_TIMEUP1);
        ShowJudgmentSprite(80, 72, ARENA_CATEGORY_BODY, GetBattlerAtPosition(B_POSITION_PLAYER_LEFT));
        ShowJudgmentSprite(160, 72, ARENA_CATEGORY_BODY, GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT));
        BattleStringExpandPlaceholdersToDisplayedString(gText_Judgment);
        BattlePutTextOnWindow(gDisplayedStringBattle, ARENA_WIN_JUDGMENT_TITLE);
        (*state)++;
        result = ARENA_RESULT_STEP_DONE;
        break;
    case 7:
        PlaySE(SE_ARENA_TIMEUP2);
        if (gBattleTextBuff1[0] > gBattleTextBuff2[0])
        {
            result = ARENA_RESULT_PLAYER_WON;
            gBattleScripting.battler = 0;
        }
        else if (gBattleTextBuff1[0] < gBattleTextBuff2[0])
        {
            result = ARENA_RESULT_PLAYER_LOST;
            gBattleScripting.battler = 1;
        }
        else
        {
            result = ARENA_RESULT_TIE;
        }
        (*state)++;
        break;
    case JUDGMENT_STATE_FINISHED:
        // Finishing this state is the indicator to SpriteCB_JudgmentIcon that its safe to destroy the judgment icon sprites
        (*state)++;
        break;
    case JUDGMENT_STATE_FINISHED + 1:
        SetGpuReg(REG_OFFSET_WININ, (WININ_WIN0_ALL & ~WININ_WIN0_BG0) | WININ_WIN1_ALL);
        HandleBattleWindow(5, 0, 24, 13, WINDOW_CLEAR);
        CopyBgTilemapBufferToVram(0);
        m4aMPlayVolumeControl(&gMPlayInfo_BGM, TRACKS_ALL, 256);
        BeginNormalPaletteFade(0x7FFFFF1C, 4, 8, 0, RGB_BLACK);
        (*state)++;
        break;
    case JUDGMENT_STATE_FINISHED + 2:
        if (!gPaletteFade.active)
        {
            SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_ALL | WININ_WIN1_ALL);
            FreeSpriteTilesByTag(TAG_JUDGMENT_ICON);
            result = ARENA_RESULT_STEP_DONE;
            (*state)++;
        }
        break;
    }

    return result;
}

static void ShowJudgmentSprite(u8 x, u8 y, u8 category, enum BattlerId battler)
{
    int animNum = 0;
    int pointsPlayer = 0;
    int pointsOpponent = 0;
    s8 *mindPoints = gBattleStruct->arenaMindPoints;
    s8 *skillPoints = gBattleStruct->arenaSkillPoints;
    u16 *hpAtStart = gBattleStruct->arenaStartHp;

    switch (category)
    {
    case ARENA_CATEGORY_MIND:
        pointsPlayer = mindPoints[battler];
        pointsOpponent = mindPoints[GetOppositeBattler(battler)];
        break;
    case ARENA_CATEGORY_SKILL:
        pointsPlayer = skillPoints[battler];
        pointsOpponent = skillPoints[GetOppositeBattler(battler)];
        break;
    case ARENA_CATEGORY_BODY:
        pointsPlayer = (gBattleMons[battler].hp * 100) / hpAtStart[battler];
        pointsOpponent = (gBattleMons[GetOppositeBattler(battler)].hp * 100) / hpAtStart[GetOppositeBattler(battler)];
        break;
    }

    if (pointsPlayer > pointsOpponent)
    {
        animNum = ANIM_ICON_CIRCLE;
        // +2 to score total for winning
        if (battler != B_BATTLER_0)
            gBattleTextBuff2[0] += 2;
        else
            gBattleTextBuff1[0] += 2;
    }
    else if (pointsPlayer == pointsOpponent)
    {
        animNum = ANIM_ICON_TRIANGLE;
        // +1 to score total for a tie
        if (battler != B_BATTLER_0)
            gBattleTextBuff2[0] += 1;
        else
            gBattleTextBuff1[0] += 1;
    }
    else
    {
        animNum = ANIM_ICON_X;
    }

    pointsPlayer = CreateSprite(&sSpriteTemplate_JudgmentIcon, x, y, 0);
    StartSpriteAnim(&gSprites[pointsPlayer], animNum);
}

static void SpriteCB_JudgmentIcon(struct Sprite *sprite)
{
    if (gBattleCommunication[0] > JUDGMENT_STATE_FINISHED)
        DestroySprite(sprite);
}

void BattleArena_InitPoints(void)
{
    s8 *mindPoints = gBattleStruct->arenaMindPoints;
    s8 *skillPoints = gBattleStruct->arenaSkillPoints;
    u16 *hpAtStart = gBattleStruct->arenaStartHp;

    mindPoints[0] = 0;
    mindPoints[1] = 0;
    skillPoints[0] = 0;
    skillPoints[1] = 0;
    hpAtStart[0] = gBattleMons[0].hp;
    hpAtStart[1] = gBattleMons[1].hp;
}

void BattleArena_AddMindPoints(enum BattlerId battler)
{
// All moves with power != 0 give 1 point, with the following exceptions:
//    - Counter, Mirror Coat, and Bide give 0 points
//    - Fake Out subtracts 1 point
// All status moves give 0 points, with the following exceptions:
//    - Protect, Detect, and Endure subtract 1 point
    enum BattleMoveEffects effect = GetMoveEffect(gCurrentMove);

    if (effect == EFFECT_FIRST_TURN_ONLY
     || effect == EFFECT_PROTECT
     || effect == EFFECT_ENDURE)
    {
        gBattleStruct->arenaMindPoints[battler]--;
    }
    else if (!IsBattleMoveStatus(gCurrentMove)
          && effect != EFFECT_REFLECT_DAMAGE
          && effect != EFFECT_BIDE)
    {
        gBattleStruct->arenaMindPoints[battler]++;
    }
}

void BattleArena_AddSkillPoints(enum BattlerId battlerAtk)
{
    s8 *skillPoints = gBattleStruct->arenaSkillPoints;

    if (gBattleStruct->unableToUseMove)
        return;

    if (gBattleStruct->battlerState[battlerAtk].alreadyStatusedMoveAttempt)
    {
        gBattleStruct->battlerState[battlerAtk].alreadyStatusedMoveAttempt = FALSE;
        skillPoints[battlerAtk] -= 2;
        return;
    }

    for (enum BattlerId battlerDef = 0; battlerDef < gBattlersCount; battlerDef++)
    {
        if (IsBattlerUnaffectedByMove(battlerDef))
        {
            if (IsBattlerMoveResultSet(battlerDef, MOVE_RESULT_MISSED))
                skillPoints[battlerAtk] -= 2;
        }
        else if (IsBattlerMoveResultSet(battlerDef, (MOVE_RESULT_HIGH_EFFECTIVENESS | MOVE_RESULT_LOW_EFFECTIVENESS)))
        {
            skillPoints[battlerAtk] += 1;
        }
        else if (IsBattlerMoveResultSet(battlerDef, MOVE_RESULT_HIGH_EFFECTIVENESS))
        {
            skillPoints[battlerAtk] += 2;
        }
        else if (IsBattlerMoveResultSet(battlerDef, MOVE_RESULT_LOW_EFFECTIVENESS))
        {
            skillPoints[battlerAtk] -= 1;
        }
        else if (!gProtectStructs[battlerDef].protected)
        {
            skillPoints[battlerAtk] += 1;
        }
    }
}

void BattleArena_DeductSkillPoints(enum BattlerId battler, enum StringID stringId)
{
    s8 *skillPoints = gBattleStruct->arenaSkillPoints;

    switch (stringId)
    {
    case STRINGID_PKMNSXMADEYUSELESS:
    case STRINGID_PKMNSXMADEITINEFFECTIVE:
    case STRINGID_PKMNSXPREVENTSFLINCHING:
    case STRINGID_PKMNSXBLOCKSY:
    case STRINGID_PKMNSXMADEYINEFFECTIVE:
    case STRINGID_PKMNPROTECTEDBY:
    case STRINGID_PKMNPREVENTSUSAGE:
    case STRINGID_PKMNRESTOREDHPUSING:
    case STRINGID_PKMNPREVENTSROMANCEWITH:
    case STRINGID_PKMNPREVENTSCONFUSIONWITH:
    case STRINGID_PKMNRAISEDFIREPOWERWITH:
    case STRINGID_PKMNANCHORSITSELFWITH:
    case STRINGID_PKMNSTAYEDAWAKEUSING:
        skillPoints[battler] -= 3;
        break;
    default:
        break;
    }
}

static void UNUSED UpdateHPAtStart(enum BattlerId battler)
{
    u16 *hpAtStart = gBattleStruct->arenaStartHp;

    hpAtStart[battler] = gBattleMons[battler].hp;
    if (hpAtStart[GetOppositeBattler(battler)] > gBattleMons[GetOppositeBattler(battler)].hp)
        hpAtStart[GetOppositeBattler(battler)] = gBattleMons[GetOppositeBattler(battler)].hp;
}

static void Unsed_InitArenaChallenge(void)
{

}

static void Unused_GetArenaData(void)
{

}

static void Unused_SetArenaData(void)
{

}

static void SaveArenaChallenge(void)
{
    ClearEnemyPartyAfterChallenge();
    gSaveBlock2Ptr->frontier.challengeStatus = gSpecialVar_0x8005;
    VarSet(VAR_TEMP_CHALLENGE_STATUS, 0);
    gSaveBlock2Ptr->frontier.challengePaused = TRUE;
    SaveGameFrontier();
}

static void Unused_SetArenaPrize(void)
{

}

static void Unused_GiveArenaPrize(void)
{

}

static void BufferArenaOpponentName(void)
{
    GetFrontierTrainerName(gStringVar1, TRAINER_BATTLE_PARAM.opponentA);
}

void DrawArenaRefereeTextBox(void)
{
    u8 width = 27;
    u8 palNum = 7;

    FillBgTilemapBufferRect(0, 0,    254, 14, 1,  6, palNum);
    FillBgTilemapBufferRect(0, 0,    32,  14, 1,  6, palNum);
    FillBgTilemapBufferRect(0, 0x31, 0,   14, 1,  1, palNum);
    FillBgTilemapBufferRect(0, 0x33, 1,   14, 1,  1, palNum);
    FillBgTilemapBufferRect(0, 0x34, 2,   14, width, 1, palNum);
    width++;
    FillBgTilemapBufferRect(0, 0x35, 28,  14, 1,  1, palNum);
    FillBgTilemapBufferRect(0, 0x36, 29,  14, 1,  1, palNum);
    FillBgTilemapBufferRect(0, 0x37, 0,   15, 1,  5, palNum);
    FillBgTilemapBufferRect(0, 0x39, 1,   15, width, 5, palNum);
    FillBgTilemapBufferRect(0, 0x3A, 29,  15, 1,  5, palNum);
    FillBgTilemapBufferRect(0, 0x831, 0,  19, 1,  1, palNum);
    FillBgTilemapBufferRect(0, 0x833, 1,  19, 1,  1, palNum);
    FillBgTilemapBufferRect(0, 0x834, 2,  19, width - 2, 1, palNum);
    FillBgTilemapBufferRect(0, 0x835, 28, 19, 1,  1, palNum);
    FillBgTilemapBufferRect(0, 0x836, 29, 19, 1,  1, palNum);
}

void EraseArenaRefereeTextBox(void)
{
    u8 width;
    u8 height;
    u8 palNum = 0;

    FillBgTilemapBufferRect(0, 3, 0, 14, 1, 1, palNum);
    height = 4;
    FillBgTilemapBufferRect(0, 4, 1, 14, 1, 1, palNum);
    width = 27;
    FillBgTilemapBufferRect(0, 5, 2, 14, width, 1, palNum);
    FillBgTilemapBufferRect(0, 6, 28, 14, 1, 1, palNum);
    FillBgTilemapBufferRect(0, 7, 29, 14, 1, 1, palNum);
    FillBgTilemapBufferRect(0, 8, 0, 15, 1, height, palNum);
    FillBgTilemapBufferRect(0, 9, 1, 15, 1, height, palNum);
    FillBgTilemapBufferRect(0, 0xA, 2, 15, width, height, palNum);
    FillBgTilemapBufferRect(0, 0xB, 28, 15, 1, height, palNum);
    FillBgTilemapBufferRect(0, 0xC, 29, 15, 1, height, palNum);
    FillBgTilemapBufferRect(0, 0xD, 0, 19, 1, 1, palNum);
    FillBgTilemapBufferRect(0, 0xE, 1, 19, 1, 1, palNum);
    FillBgTilemapBufferRect(0, 0xF, 2, 19, width, 1, palNum);
    FillBgTilemapBufferRect(0, 0x10, 28, 19, 1, 1, palNum);
    FillBgTilemapBufferRect(0, 0x11, 29, 19, 1, 1, palNum);
}
