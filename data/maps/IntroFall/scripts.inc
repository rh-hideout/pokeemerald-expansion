@ =============================================================================
@ INTRO FALL — MAP SCRIPTS
@ =============================================================================

IntroFall_MapScripts::
    map_script MAP_SCRIPT_ON_FRAME_TABLE, IntroFall_OnFrame
    .byte 0


IntroFall_OnFrame:
    map_script_2 VAR_TEMP_2, 0, IntroFall_EventScript_Begin
    .2byte 0


@ =============================================================================
@ INITIAL MAP SETUP
@ =============================================================================

IntroFall_EventScript_Begin:
    setvar VAR_TEMP_2, 1
    call IntroFall_Setup
    end


IntroFall_Setup:
    special Special_ApplyFallTint

    applymovement OBJ_EVENT_ID_PLAYER, IntroFall_Movement_PlayerFaceUp
    waitmovement 0

    return


@ =============================================================================
@ POOCHYENA DISCOVERY EVENTS
@ =============================================================================

IntroFall_EventScript_DiscoverPoochyenaFront::
    lockall

    applymovement OBJ_EVENT_ID_PLAYER, IntroFall_Movement_PlayerFaceUp
    waitmovement 0

    delay 30

    playmoncry SPECIES_POOCHYENA, 0
    waitmoncry

    delay 30

    releaseall
    end


IntroFall_EventScript_DiscoverPoochyena::
    lockall

    applymovement OBJ_EVENT_ID_PLAYER, IntroFall_Movement_PlayerFaceRight
    waitmovement 0

    delay 30

    playmoncry SPECIES_POOCHYENA, 0
    waitmoncry

    delay 30

    releaseall
    end


IntroFall_FirstCry::
    lockall

    playmoncry SPECIES_POOCHYENA, 0
    waitmoncry

    releaseall
    end


@ =============================================================================
@ OPTIONAL PARENT INTERACTION
@ =============================================================================

IntroFall_Parent::
    lock
    faceplayer

    msgbox IntroFall_Text_ParentSilent, MSGBOX_DEFAULT

    release
    end


@ =============================================================================
@ HURT POOCHYENA — MAIN DECISION
@
@ Choice 0: Help
@     VAR_RAISED_BY = 1
@     Compassion increases
@     Mom becomes the home parent
@
@ Choice 1: Get an adult
@     VAR_RAISED_BY = 2
@     Resolve increases
@     Dad becomes the home parent
@
@ VAR_PARENT_CHOICE remains separate:
@     1 = Tia accompanies the player during the fall
@     2 = Elias accompanies the player during the fall
@ =============================================================================

IntroFall_HurtPoochyena::
    lock
    faceplayer

    delay 20

    playmoncry SPECIES_POOCHYENA, 0
    waitmoncry

    delay 20

    msgbox IntroFall_Text_PoochyenaInjured, MSGBOX_DEFAULT
    closemessage

    delay 20

    multichoicedefault 15, 8, MULTI_HELP_OR_ADULT, 0, FALSE

    switch VAR_RESULT
    case 0, IntroFall_EventScript_ChooseHelp
    case 1, IntroFall_EventScript_ChooseAdult

    release
    end


@ =============================================================================
@ CHOICE ONE — HELP THE POOCHYENA
@
@ Tia or Elias still reacts based on VAR_PARENT_CHOICE.
@ Regardless of who accompanied the player, Mom becomes the home parent.
@ =============================================================================

IntroFall_EventScript_ChooseHelp:
    setvar VAR_RAISED_BY, 1
    addvar VAR_COMPASSION, 1

    msgbox IntroFall_Text_ChooseHelp, MSGBOX_DEFAULT
    closemessage

    special GetPlayerFacingDirection

    switch VAR_RESULT
    case DIR_NORTH, IntroFall_EventScript_HelpApproachNorth
    case DIR_SOUTH, IntroFall_EventScript_HelpApproachSouth
    case DIR_WEST, IntroFall_EventScript_HelpApproachWest
    case DIR_EAST, IntroFall_EventScript_HelpApproachEast

    @ Fallback in case no facing-direction branch is selected.
    goto IntroFall_EventScript_AfterHelpApproach


IntroFall_EventScript_HelpApproachNorth:
    applymovement OBJ_EVENT_ID_PLAYER, IntroFall_Movement_PlayerApproachNorth
    waitmovement 0

    goto IntroFall_EventScript_AfterHelpApproach


IntroFall_EventScript_HelpApproachSouth:
    applymovement OBJ_EVENT_ID_PLAYER, IntroFall_Movement_PlayerApproachSouth
    waitmovement 0

    goto IntroFall_EventScript_AfterHelpApproach


IntroFall_EventScript_HelpApproachWest:
    applymovement OBJ_EVENT_ID_PLAYER, IntroFall_Movement_PlayerApproachWest
    waitmovement 0

    goto IntroFall_EventScript_AfterHelpApproach


IntroFall_EventScript_HelpApproachEast:
    applymovement OBJ_EVENT_ID_PLAYER, IntroFall_Movement_PlayerApproachEast
    waitmovement 0

    goto IntroFall_EventScript_AfterHelpApproach


IntroFall_EventScript_AfterHelpApproach:
    playmoncry SPECIES_POOCHYENA, 0
    waitmoncry

    @ The darkness choice determines who rushes over in the fall.
    goto_if_eq VAR_PARENT_CHOICE, 1, IntroFall_EventScript_Help_MomComes
    goto_if_eq VAR_PARENT_CHOICE, 2, IntroFall_EventScript_Help_DadComes

    @ Safe fallback if VAR_PARENT_CHOICE somehow has no expected value.
    goto IntroFall_EventScript_Help_MomComes


IntroFall_EventScript_Help_MomComes:
    applymovement LOCALID_MOM, IntroFall_Movement_MomRushesOver
    waitmovement 0

    goto IntroFall_EventScript_ParentReaction


IntroFall_EventScript_Help_DadComes:
    applymovement LOCALID_DAD, IntroFall_Movement_DadRushesOver
    waitmovement 0

    goto IntroFall_EventScript_ParentReaction


IntroFall_EventScript_ParentReaction:
    msgbox IntroFall_Text_ParentReaction, MSGBOX_DEFAULT
    closemessage

    @ HELP always results in Mom being the home parent.
    goto IntroFall_EventScript_SetHomeMom


@ =============================================================================
@ CHOICE TWO — GET AN ADULT
@
@ Tia or Elias still responds based on VAR_PARENT_CHOICE.
@ Regardless of who accompanied the player, Dad becomes the home parent.
@ =============================================================================

IntroFall_EventScript_ChooseAdult:
    setvar VAR_RAISED_BY, 2
    addvar VAR_RESOLVE, 1

    msgbox IntroFall_Text_ChooseAdult, MSGBOX_DEFAULT
    closemessage

    applymovement OBJ_EVENT_ID_PLAYER, IntroFall_Movement_PlayerCallParent
    waitmovement 0

    delay 20

    @ The darkness choice determines who comes over in the fall.
    goto_if_eq VAR_PARENT_CHOICE, 1, IntroFall_EventScript_Adult_MomComes
    goto_if_eq VAR_PARENT_CHOICE, 2, IntroFall_EventScript_Adult_DadComes

    @ Safe fallback if VAR_PARENT_CHOICE somehow has no expected value.
    goto IntroFall_EventScript_Adult_MomComes


IntroFall_EventScript_Adult_MomComes:
    applymovement LOCALID_MOM, IntroFall_Movement_MomComesToHelp
    waitmovement 0

    msgbox IntroFall_Text_MomAdultReaction, MSGBOX_DEFAULT
    closemessage

    @ GET AN ADULT always results in Dad being the home parent.
    goto IntroFall_EventScript_SetHomeDad


IntroFall_EventScript_Adult_DadComes:
    applymovement LOCALID_DAD, IntroFall_Movement_DadComesToHelp
    waitmovement 0

    msgbox IntroFall_Text_DadAdultReaction, MSGBOX_DEFAULT
    closemessage

    @ GET AN ADULT always results in Dad being the home parent.
    goto IntroFall_EventScript_SetHomeDad


@ =============================================================================
@ HOME-PARENT SETUP
@
@ These original HOME flags control the downstairs parent objects:
@
@ Mom home:
@     Show Mom
@     Hide Dad
@
@ Dad home:
@     Hide Mom
@     Show Dad
@
@ The UPSTAIRS flags separately prepare the bedroom parent for the
@ wake-up scene. The bedroom script will later hide that upstairs copy.
@ =============================================================================

IntroFall_EventScript_SetHomeMom:
    @ Downstairs/home objects:
    clearflag FLAG_HIDE_HOME_MOM
    setflag FLAG_HIDE_HOME_DAD


    goto IntroFall_EventScript_WakeUp


IntroFall_EventScript_SetHomeDad:
    @ Downstairs/home objects:
    setflag FLAG_HIDE_HOME_MOM
    clearflag FLAG_HIDE_HOME_DAD


    goto IntroFall_EventScript_WakeUp


@ =============================================================================
@ END FLASHBACK AND WARP TO BEDROOM
@ =============================================================================

IntroFall_EventScript_WakeUp:
    setflag FLAG_INTRO_FLASHBACK_COMPLETE

    special Special_ClearIntroTint

    warp MAP_LITTLEROOT_TOWN_PLAYERS_HOUSE_1F, 1, 4
    waitstate
    end


@ =============================================================================
@ UNUSED / OPTIONAL END-FALL SEQUENCE
@ =============================================================================

IntroFall_EventScript_EndFall:
    delay 30

    playmoncry SPECIES_POOCHYENA, 0
    waitmoncry

    delay 45

    waitstate

    delay 120

    end


@ =============================================================================
@ PLAYER MOVEMENTS
@ =============================================================================

IntroFall_Movement_PlayerFaceUp:
    face_up
    step_end


IntroFall_Movement_PlayerFaceRight:
    face_right
    step_end


IntroFall_Movement_PlayerCallParent:
    face_down
    step_end


IntroFall_Movement_PlayerApproachPoochyena:
    walk_up
    step_end


IntroFall_Movement_PlayerApproachNorth:
    walk_up
    step_end


IntroFall_Movement_PlayerApproachSouth:
    walk_down
    step_end


IntroFall_Movement_PlayerApproachWest:
    walk_left
    step_end


IntroFall_Movement_PlayerApproachEast:
    walk_right
    step_end


@ =============================================================================
@ MOM MOVEMENTS
@ =============================================================================

IntroFall_Movement_MomRushesOver:
    walk_up
    walk_up
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    face_up
    step_end


IntroFall_Movement_MomComesToHelp:
    walk_up
    walk_up
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    face_up
    step_end


@ =============================================================================
@ DAD MOVEMENTS
@ =============================================================================

IntroFall_Movement_DadRushesOver:
    walk_up
    walk_right
    walk_down
    walk_right
    walk_right
    walk_right
    walk_right
    walk_up
    walk_up
    walk_right
    face_up
    step_end


IntroFall_Movement_DadComesToHelp:
    walk_up
    walk_right
    walk_down
    walk_right
    walk_right
    walk_right
    walk_right
    walk_up
    walk_up
    walk_right
    walk_up
    step_end


@ =============================================================================
@ TEXT
@ =============================================================================

IntroFall_Text_PoochyenaInjured:
    .string "...This POOCHYENA is trembling...\n"
    .string "It looks badly hurt.$"


IntroFall_Text_ChooseHelp:
    .string "You slowly reach toward the\n"
    .string "injured POOCHYENA...$"


IntroFall_Text_ChooseAdult:
    .string "You should find an adult...\n"
    .string "Someone will know what to do.$"


IntroFall_Text_ParentSilent:
    .string "Not...\n"
    .string "again...$"


IntroFall_Text_ParentReaction:
    .string "Wait! Don't touch it!\n"
    .string "You could be hurt.$"


IntroFall_Text_MomAdultReaction:
    .string "You did the right thing.\n"
    .string "Stay close to me.$"


IntroFall_Text_DadAdultReaction:
    .string "You did the right thing.\n"
    .string "Stay close to me.$"
    


