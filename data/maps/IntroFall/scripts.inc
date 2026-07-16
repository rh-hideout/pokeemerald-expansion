IntroFall_MapScripts::
    map_script MAP_SCRIPT_ON_FRAME_TABLE, IntroFall_OnFrame
    .byte 0


IntroFall_OnFrame:
    map_script_2 VAR_TEMP_2, 0, IntroFall_EventScript_Begin
    .2byte 0

IntroFall_EventScript_Begin:
    setvar VAR_TEMP_2, 1

    call IntroFall_Setup

    end

IntroFall_Setup:
    applymovement OBJ_EVENT_ID_PLAYER, IntroFall_PlayerFaceUp
    waitmovement 0
    return

IntroFall_EventScript_DiscoverPoochyenaFront::
    lockall

    applymovement OBJ_EVENT_ID_PLAYER, IntroFall_PlayerFaceUp
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

IntroFall_PlayerFaceUp:
    face_up
    step_end

IntroFall_Parent::
    lock
    faceplayer
    msgbox IntroFall_Text_ParentSilent, MSGBOX_DEFAULT
    release
    end

IntroFall_Movement_PlayerApproachPoochyena:
    walk_up
    step_end

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
    walk_up
    step_end

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
    walk_up
    step_end

IntroFall_Movement_PlayerCallParent:
    face_down
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


IntroFall_EventScript_DiscoverPoochyena::
    lockall

    applymovement OBJ_EVENT_ID_PLAYER, IntroFall_PlayerFaceRight
    waitmovement 0

    delay 30

    playmoncry SPECIES_POOCHYENA, 0
    waitmoncry

    delay 30

    releaseall
    end

IntroFall_PlayerFaceRight:
    face_right
    step_end

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

IntroFall_EventScript_ChooseHelp:
    setvar VAR_RAISED_BY, 1

    msgbox IntroFall_Text_ChooseHelp, MSGBOX_DEFAULT
    closemessage

    applymovement OBJ_EVENT_ID_PLAYER, IntroFall_Movement_PlayerApproachPoochyena
    waitmovement 0

    playmoncry SPECIES_POOCHYENA, 0
    waitmoncry

    goto_if_eq VAR_PARENT_CHOICE, 1, IntroFall_EventScript_Help_MomComes
    goto_if_eq VAR_PARENT_CHOICE, 2, IntroFall_EventScript_Help_DadComes

    releaseall
    end

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

    goto IntroFall_EventScript_SetHomeMom


IntroFall_EventScript_ChooseAdult:
    setvar VAR_RAISED_BY, 2

    msgbox IntroFall_Text_ChooseAdult, MSGBOX_DEFAULT
    closemessage

    applymovement OBJ_EVENT_ID_PLAYER, IntroFall_Movement_PlayerCallParent
    waitmovement 0

    delay 20

    goto_if_eq VAR_PARENT_CHOICE, 1, IntroFall_EventScript_Adult_MomComes
    goto_if_eq VAR_PARENT_CHOICE, 2, IntroFall_EventScript_Adult_DadComes

    releaseall
    end

IntroFall_EventScript_Adult_MomComes:
    applymovement LOCALID_MOM, IntroFall_Movement_MomComesToHelp
    waitmovement 0

    msgbox IntroFall_Text_MomAdultReaction, MSGBOX_DEFAULT
    closemessage

    goto IntroFall_EventScript_SetHomeDad

IntroFall_EventScript_Adult_DadComes:
    applymovement LOCALID_DAD, IntroFall_Movement_DadComesToHelp
    waitmovement 0

    msgbox IntroFall_Text_DadAdultReaction, MSGBOX_DEFAULT
    closemessage

    goto IntroFall_EventScript_SetHomeDad
    



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
    .string "...$"

IntroFall_Text_ParentReaction:
    .string "Wait! don't touch it!\n"
    .string "You could be hurt.$"

IntroFall_Text_MomAdultReaction:
    .string "You did the right thing.\n"
    .string "Stay close to me.$"

IntroFall_Text_DadAdultReaction:
    .string "You did the right thing.\n"
    .string "Stay close to me.$"

IntroFall_EventScript_EndFall:
    delay 30

    playmoncry SPECIES_POOCHYENA, 0
    waitmoncry

    delay 45

    waitstate

    delay 120

    end


IntroFall_EventScript_SetHomeMom:
    clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_MOM
    setflag FLAG_HIDE_PLAYERS_HOUSE_DAD
    goto IntroFall_EventScript_WakeUp

IntroFall_EventScript_SetHomeDad:
    setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_MOM
    clearflag FLAG_HIDE_PLAYERS_HOUSE_DAD
    goto IntroFall_EventScript_WakeUp

IntroFall_EventScript_WakeUp:
    warp MAP_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F, 4, 2
    waitstate
    end
    


