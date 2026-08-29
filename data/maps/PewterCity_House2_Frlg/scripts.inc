PewterCity_House2_Frlg_MapScripts::
    map_script MAP_SCRIPT_ON_LOAD, PewterCity_House2_Frlg_SetCounterpartGraphics
    .byte 0

PewterCity_House2_Frlg_SetCounterpartGraphics:
    goto_if_eq VAR_COUNTERPART_ID, COUNTERPART_BRENDAN, PewterCity_House2_Frlg_SetBrendan
    goto_if_eq VAR_COUNTERPART_ID, COUNTERPART_MAY, PewterCity_House2_Frlg_SetMay
    goto_if_eq VAR_COUNTERPART_ID, COUNTERPART_LEXY, PewterCity_House2_Frlg_SetLexy
    goto_if_eq VAR_COUNTERPART_ID, COUNTERPART_JUSTIN, PewterCity_House2_Frlg_SetJustin
    goto_if_eq VAR_COUNTERPART_ID, COUNTERPART_MAAM, PewterCity_House2_Frlg_SetMaam
    goto_if_eq VAR_COUNTERPART_ID, COUNTERPART_SIR, PewterCity_House2_Frlg_SetSir
    goto PewterCity_House2_Frlg_FinishLoad

PewterCity_House2_Frlg_SetBrendan:
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_BRENDAN_NORMAL
    goto PewterCity_House2_Frlg_FinishLoad

PewterCity_House2_Frlg_SetMay:
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_MAY_NORMAL
    goto PewterCity_House2_Frlg_FinishLoad

PewterCity_House2_Frlg_SetLexy:
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_LEXY_NORMAL
    goto PewterCity_House2_Frlg_FinishLoad

PewterCity_House2_Frlg_SetJustin:
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_JUSTIN_NORMAL
    goto PewterCity_House2_Frlg_FinishLoad

PewterCity_House2_Frlg_SetMaam:
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_MAAM_NORMAL
    goto PewterCity_House2_Frlg_FinishLoad

PewterCity_House2_Frlg_SetSir:
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SIR_NORMAL
    goto PewterCity_House2_Frlg_FinishLoad

PewterCity_House2_Frlg_FinishLoad:
    end


@ ============================================================================
@ SAVVY
@ Pewter's resident source of everybody else's business.
@ ============================================================================

@ ============================================================================
@ SAVVY-STAGE RIVAL
@ ============================================================================

PewterCity_House2_Frlg_EventScript_Counterpart::
    lock
    faceplayer

    compare VAR_BROCK_INGREDIENT_QUEST, 2
    goto_if_eq PewterCity_House2_Frlg_EventScript_CounterpartQuest

    msgbox PewterCity_House2_Frlg_Text_CounterpartFallback, MSGBOX_DEFAULT
    release
    end

PewterCity_House2_Frlg_EventScript_CounterpartQuest:
    msgbox PewterCity_House2_Frlg_Text_CounterpartQuest, MSGBOX_DEFAULT
    release
    end

PewterCity_House2_Frlg_Text_CounterpartQuest:
    .string "{PLAYER}: ...\p"
    .string "{RIVAL}: Don't.\p"
    .string "{PLAYER}: I didn't say anything.\p"
    .string "{RIVAL}: Your face did.$"

PewterCity_House2_Frlg_Text_CounterpartFallback:
    .string "{RIVAL}: SAVVY's the one we need.$"


PewterCity_House2_Frlg_EventScript_Savvy::
    lock
    faceplayer

    compare VAR_BROCK_INGREDIENT_QUEST, 0
    goto_if_eq PewterCity_House2_Frlg_EventScript_SavvyNormal

    compare VAR_BROCK_INGREDIENT_QUEST, 1
    goto_if_eq PewterCity_House2_Frlg_EventScript_SavvyTooEarly

    compare VAR_BROCK_INGREDIENT_QUEST, 2
    goto_if_eq PewterCity_House2_Frlg_EventScript_SavvyQuest

    compare VAR_BROCK_INGREDIENT_QUEST, 3
    goto_if_eq PewterCity_House2_Frlg_EventScript_SavvyAfterClue

    goto PewterCity_House2_Frlg_EventScript_SavvyNormal


PewterCity_House2_Frlg_EventScript_SavvyTooEarly:
    msgbox PewterCity_House2_Frlg_Text_SavvyTooEarly, MSGBOX_DEFAULT
    release
    end


PewterCity_House2_Frlg_EventScript_SavvyQuest:
    @ Bring Rival into the conversation instead of leaving them
    @ awkwardly behind the player.
    getplayerxy VAR_TEMP_0, VAR_TEMP_1

    goto_if_eq VAR_TEMP_0, 2, PewterCity_House2_Frlg_EventScript_SavvyStageFromLeft
    goto_if_eq VAR_TEMP_0, 4, PewterCity_House2_Frlg_EventScript_SavvyStageFromRight

    @ Normal/front approach: Player is below Savvy at (3,4).
    goto PewterCity_House2_Frlg_EventScript_SavvyStageFromFront


PewterCity_House2_Frlg_EventScript_SavvyStageFromFront:
    @ Rival starts at (3,5). Move beside Player to (2,4).
    applymovement LOCALID_PEWTER_SAVVY_COUNTERPART, PewterCity_House2_Frlg_Movement_CounterpartStageFront
    waitmovement LOCALID_PEWTER_SAVVY_COUNTERPART
    goto PewterCity_House2_Frlg_EventScript_SavvyConversation


PewterCity_House2_Frlg_EventScript_SavvyStageFromLeft:
    @ Player is at (2,3). Rival moves to (3,4).
    applymovement LOCALID_PEWTER_SAVVY_COUNTERPART, PewterCity_House2_Frlg_Movement_CounterpartStageSide
    waitmovement LOCALID_PEWTER_SAVVY_COUNTERPART
    goto PewterCity_House2_Frlg_EventScript_SavvyConversation


PewterCity_House2_Frlg_EventScript_SavvyStageFromRight:
    @ Player is at (4,3). Same (3,4) staging spot works.
    applymovement LOCALID_PEWTER_SAVVY_COUNTERPART, PewterCity_House2_Frlg_Movement_CounterpartStageSide
    waitmovement LOCALID_PEWTER_SAVVY_COUNTERPART
    goto PewterCity_House2_Frlg_EventScript_SavvyConversation


PewterCity_House2_Frlg_EventScript_SavvyConversation:
    msgbox PewterCity_House2_Frlg_Text_SavvyGreeting, MSGBOX_DEFAULT
    msgbox PewterCity_House2_Frlg_Text_SavvyKnowsWhy, MSGBOX_DEFAULT
    msgbox PewterCity_House2_Frlg_Text_SavvyWoman, MSGBOX_DEFAULT
    msgbox PewterCity_House2_Frlg_Text_SavvyCerulean, MSGBOX_DEFAULT

    setvar VAR_BROCK_INGREDIENT_QUEST, 3

    msgbox PewterCity_House2_Frlg_Text_CounterpartSavvyExit, MSGBOX_DEFAULT

    @ Rival actually walks out through the door instead of evaporating.
    applymovement LOCALID_PEWTER_SAVVY_COUNTERPART, PewterCity_House2_Frlg_Movement_CounterpartLeaves
    waitmovement LOCALID_PEWTER_SAVVY_COUNTERPART

    setflag FLAG_HIDE_PEWTER_SAVVY_COUNTERPART
    removeobject LOCALID_PEWTER_SAVVY_COUNTERPART

    release
    end


PewterCity_House2_Frlg_EventScript_SavvyAfterClue:
    msgbox PewterCity_House2_Frlg_Text_SavvyAfterClue, MSGBOX_DEFAULT
    release
    end


PewterCity_House2_Frlg_EventScript_SavvyNormal:
    msgbox PewterCity_House2_Frlg_Text_SavvyNormal, MSGBOX_DEFAULT
    release
    end


@ ============================================================================
@ RIVAL CONVERSATION STAGING
@ ============================================================================

@ From (3,5) -> (2,4), beside Player when Player approached from below.
PewterCity_House2_Frlg_Movement_CounterpartStageFront:
    walk_left
    walk_up
    face_right
    step_end

@ From (3,5) -> (3,4), near both Player and Savvy for side approaches.
PewterCity_House2_Frlg_Movement_CounterpartStageSide:
    walk_up
    face_up
    step_end


@ ============================================================================
@ RIVAL EXIT
@ ============================================================================

PewterCity_House2_Frlg_Movement_CounterpartLeaves:
    face_down
    walk_down
    walk_down
    walk_down
    step_end



PewterCity_House2_Frlg_EventScript_Kid::
    lock
    faceplayer
    msgbox PewterCity_House2_Frlg_Text_Kid, MSGBOX_DEFAULT
    release
    end


PewterCity_House2_Frlg_Text_Kid:
    .string "People come here asking Mom\n"
    .string "questions all the time.\p"
    .string "Sometimes she answers before\n"
    .string "they ask.\p"
    .string "It's weird.$"


@ ============================================================================
@ TEXT
@ ============================================================================

PewterCity_House2_Frlg_Text_CounterpartSavvyExit:
    .string "{RIVAL}: Well. Back to CERULEAN.\p"
    .string "{PLAYER}: Together this time?\p"
    .string "{RIVAL}: Sure.\p"
    .string "{PLAYER}: ...Why don't I believe you?\p"
    .string "{RIVAL}: See you there.$"


PewterCity_House2_Frlg_Text_SavvyNormal:
    .string "SAVVY: People think PEWTER is quiet.\p"
    .string "People think a lot of things.$"


PewterCity_House2_Frlg_Text_SavvyTooEarly:
    .string "SAVVY: You aren't from around here.\p"
    .string "Don't worry.\n"
    .string "I won't hold it against you.$"


PewterCity_House2_Frlg_Text_SavvyGreeting:
    .string "SAVVY: Took you long enough.\p"
    .string "{PLAYER}: ...Excuse me?$"


PewterCity_House2_Frlg_Text_SavvyKnowsWhy:
    .string "SAVVY: Honey, you've been walking\n"
    .string "around PEWTER asking questions.\p"
    .string "Of course I know why you're here.\p"
    .string "{RIVAL}: I like her already.$"


PewterCity_House2_Frlg_Text_SavvyWoman:
    .string "{PLAYER}: Then you know about the\n"
    .string "ingredient?\p"
    .string "SAVVY: I know about the woman.\p"
    .string "Quiet. Serious.\n"
    .string "Didn't say much.\p"
    .string "{RIVAL}: That's not a lot to\n"
    .string "work with.\p"
    .string "SAVVY: I wasn't finished.$"


PewterCity_House2_Frlg_Text_SavvyCerulean:
    .string "SAVVY: She came through here looking\n"
    .string "for something herself.\p"
    .string "Then she left for CERULEAN.\p"
    .string "{PLAYER}: Cerulean?\p"
    .string "{RIVAL}: We JUST came from\n"
    .string "Cerulean.\p"
    .string "SAVVY: Then you know the way.$"


PewterCity_House2_Frlg_Text_SavvyAfterClue:
    .string "SAVVY: CERULEAN.\p"
    .string "And if you find her...\n"
    .string "tell her SAVVY says hello.$"
