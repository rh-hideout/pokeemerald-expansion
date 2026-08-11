CeruleanCity_BikeShop_Frlg_MapScripts::
    map_script MAP_SCRIPT_ON_TRANSITION, CeruleanCity_BikeShop_Frlg_OnTransition
    .byte 0

@ ============================================================
@ ON TRANSITION
@ Sets:
@   VAR_OBJ_GFX_ID_0 = dynamic counterpart
@   VAR_OBJ_GFX_ID_2 = shiny Magikarp
@
@ IMPORTANT:
@ No player movement here. Transition only prepares graphics.
@ ============================================================

CeruleanCity_BikeShop_Frlg_OnTransition:
    goto_if_eq VAR_COUNTERPART_ID, COUNTERPART_BRENDAN, CeruleanCity_BikeShop_Frlg_SetBrendan
    goto_if_eq VAR_COUNTERPART_ID, COUNTERPART_MAY, CeruleanCity_BikeShop_Frlg_SetMay
    goto_if_eq VAR_COUNTERPART_ID, COUNTERPART_LEXY, CeruleanCity_BikeShop_Frlg_SetLexy
    goto_if_eq VAR_COUNTERPART_ID, COUNTERPART_JUSTIN, CeruleanCity_BikeShop_Frlg_SetJustin
    goto_if_eq VAR_COUNTERPART_ID, COUNTERPART_MAAM, CeruleanCity_BikeShop_Frlg_SetMaam
    goto_if_eq VAR_COUNTERPART_ID, COUNTERPART_SIR, CeruleanCity_BikeShop_Frlg_SetSir

    @ Fallback
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_BRENDAN_NORMAL
    goto CeruleanCity_BikeShop_Frlg_SetMagikarp

CeruleanCity_BikeShop_Frlg_SetBrendan:
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_BRENDAN_NORMAL
    goto CeruleanCity_BikeShop_Frlg_SetMagikarp

CeruleanCity_BikeShop_Frlg_SetMay:
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_MAY_NORMAL
    goto CeruleanCity_BikeShop_Frlg_SetMagikarp

CeruleanCity_BikeShop_Frlg_SetLexy:
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_LEXY_NORMAL
    goto CeruleanCity_BikeShop_Frlg_SetMagikarp

CeruleanCity_BikeShop_Frlg_SetJustin:
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_JUSTIN_NORMAL
    goto CeruleanCity_BikeShop_Frlg_SetMagikarp

CeruleanCity_BikeShop_Frlg_SetMaam:
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_MAAM_NORMAL
    goto CeruleanCity_BikeShop_Frlg_SetMagikarp

CeruleanCity_BikeShop_Frlg_SetSir:
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SIR_NORMAL
    goto CeruleanCity_BikeShop_Frlg_SetMagikarp

CeruleanCity_BikeShop_Frlg_SetMagikarp:
    setvar VAR_OBJ_GFX_ID_2, OBJ_EVENT_GFX_SHINY_MAGIKARP
    end


@ ============================================================
@ ENTRY CUTSCENE
@
@ THIS is the script for the trigger near the entrance.
@
@ Player enters at roughly 5,8.
@ This walks them up/right into the confrontation area,
@ then directly begins LabIntro.
@
@ Assign your entrance trigger to:
@ CeruleanCity_BikeShop_Frlg_EventScript_EnterLab
@ ============================================================

CeruleanCity_BikeShop_Frlg_EventScript_EnterLab::
    lockall

    applymovement LOCALID_PLAYER, CeruleanCity_BikeShop_Frlg_Movement_WalkToLab
    waitmovement 0

    goto CeruleanCity_BikeShop_Frlg_EventScript_LabIntro


@ ============================================================
@ SECRET LAB INTRO
@
@ We arrive already locked from EnterLab.
@ Counterpart is already standing with Rocket + James.
@ ============================================================

CeruleanCity_BikeShop_Frlg_EventScript_LabIntro::
    lockall

    @ ========================================================
    @ START
    @ Counterpart is ALREADY facing RIGHT toward the grunts.
    @ Player arrives facing LEFT toward counterpart.
    @ So ONLY turn the player toward the grunts.
    @ ========================================================

    applymovement LOCALID_PLAYER, CeruleanCity_BikeShop_Frlg_Movement_FaceRight
    waitmovement 0

    msgbox CeruleanCity_BikeShop_Frlg_Text_CounterpartWhatAreYouDoing, MSGBOX_DEFAULT
    closemessage

    @ The idiots finally acknowledge that they've been caught.
    applymovement LOCALID_CERULEAN_LAB_ROCKET, CeruleanCity_BikeShop_Frlg_Movement_FaceLeft
    applymovement LOCALID_JAMES, CeruleanCity_BikeShop_Frlg_Movement_FaceLeft
    waitmovement 0

    msgbox CeruleanCity_BikeShop_Frlg_Text_RocketAlreadyDone, MSGBOX_DEFAULT
    closemessage

    msgbox CeruleanCity_BikeShop_Frlg_Text_PlayerItsShiny, MSGBOX_DEFAULT
    closemessage

    msgbox CeruleanCity_BikeShop_Frlg_Text_RocketExactly, MSGBOX_DEFAULT
    closemessage

    msgbox CeruleanCity_BikeShop_Frlg_Text_PlayerExistingThing, MSGBOX_DEFAULT
    closemessage

    msgbox CeruleanCity_BikeShop_Frlg_Text_RocketCriminalMasterminds, MSGBOX_DEFAULT
    closemessage

    msgbox CeruleanCity_BikeShop_Frlg_Text_PlayerAreYou, MSGBOX_DEFAULT
    closemessage

    msgbox CeruleanCity_BikeShop_Frlg_Text_JamesBooks, MSGBOX_DEFAULT
    closemessage


    @ ========================================================
    @ PLAYER / COUNTERPART ASIDE
    @ Up to this point BOTH are already facing RIGHT
    @ toward Rocket + James.
    @
    @ Player is positioned so they are ALREADY facing
    @ counterpart correctly.
    @ Only counterpart needs to turn toward the player.
    @ ========================================================

    @ Counterpart turns toward player
    applymovement LOCALID_COUNTERPART_CERULEAN_LAB, Common_Movement_FacePlayer
    waitmovement 0

    @ Player turns toward counterpart
    applymovement LOCALID_PLAYER, CeruleanCity_BikeShop_Frlg_Movement_FaceUp
    waitmovement 0

    msgbox CeruleanCity_BikeShop_Frlg_Text_CounterpartBattleQuestion, MSGBOX_DEFAULT
    closemessage

    msgbox CeruleanCity_BikeShop_Frlg_Text_PlayerDoWeNeedTo, MSGBOX_DEFAULT
    closemessage

    @ Player turns back toward Rocket + James
    applymovement LOCALID_PLAYER, CeruleanCity_BikeShop_Frlg_Movement_FaceRight
    waitmovement 0

    @ Counterpart turns back toward Rocket + James
    applymovement LOCALID_COUNTERPART_CERULEAN_LAB, CeruleanCity_BikeShop_Frlg_Movement_FaceRight
    waitmovement 0


    @ ========================================================
    @ BACK TO ROCKET + JAMES
    @ Only counterpart needs to turn back RIGHT.
    @ Player was already facing RIGHT the whole time.
    @ ========================================================

    applymovement LOCALID_COUNTERPART_CERULEAN_LAB, CeruleanCity_BikeShop_Frlg_Movement_FaceRight
    waitmovement 0

    msgbox CeruleanCity_BikeShop_Frlg_Text_CounterpartMistyMad, MSGBOX_DEFAULT
    closemessage

    msgbox CeruleanCity_BikeShop_Frlg_Text_PlayerOhRight, MSGBOX_DEFAULT
    closemessage

    msgbox CeruleanCity_BikeShop_Frlg_Text_RocketSee, MSGBOX_DEFAULT
    closemessage

    msgbox CeruleanCity_BikeShop_Frlg_Text_JamesWhyHappy, MSGBOX_DEFAULT
    closemessage

    releaseall
    end


@ ============================================================
@ SHINY MAGIKARP
@ Assign this to the Magikarp object event.
@ ============================================================

CeruleanCity_BikeShop_Frlg_EventScript_ShinyMagikarp::
    lock
    faceplayer

    msgbox CeruleanCity_BikeShop_Frlg_Text_ShinyMagikarp, MSGBOX_DEFAULT

    release
    end


@ ============================================================
@ OPTIONAL NPC SCRIPTS
@
@ These are safe placeholders for Rocket and James if you
@ interact with them before/after the main cutscene.
@ ============================================================

CeruleanCity_BikeShop_Frlg_EventScript_Rocket::
    lock
    faceplayer

    msgbox CeruleanCity_BikeShop_Frlg_Text_RocketIdle, MSGBOX_DEFAULT

    release
    end

CeruleanCity_BikeShop_Frlg_EventScript_James::
    lock
    faceplayer

    msgbox CeruleanCity_BikeShop_Frlg_Text_JamesIdle, MSGBOX_DEFAULT

    release
    end


@ ============================================================
@ MOVEMENTS
@ ============================================================

CeruleanCity_BikeShop_Frlg_Movement_WalkToLab:
    walk_up
    walk_up
    walk_up
    walk_up
    walk_right
    step_end

CeruleanCity_BikeShop_Frlg_Movement_FaceRight:
    face_right
    step_end

CeruleanCity_BikeShop_Frlg_Movement_FaceLeft:
    face_left
    step_end

CeruleanCity_BikeShop_Frlg_Movement_FaceUp:
    face_up
    step_end




@ ============================================================
@ TEXT - LAB INTRO
@ ============================================================

CeruleanCity_BikeShop_Frlg_Text_CounterpartWhatAreYouDoing:
    .string "OAK'S GRANDCHILD: Um...\p"
    .string "You two know you can't just...\n"
    .string "do this, right?$"

CeruleanCity_BikeShop_Frlg_Text_RocketAlreadyDone:
    .string "ROCKET GRUNT: TOO LATE!\p"
    .string "Look at that MAGIKARP!\p"
    .string "It's already DONE!\p"
    .string "We're gonna sell it for a FORTUNE!\p"
    .string "It's SPECIAL!$"

CeruleanCity_BikeShop_Frlg_Text_PlayerItsShiny:
    .string "{PLAYER}: ...Guys.\p"
    .string "It's shiny.$"

CeruleanCity_BikeShop_Frlg_Text_RocketExactly:
    .string "ROCKET GRUNT: EXACTLY!$"

CeruleanCity_BikeShop_Frlg_Text_PlayerExistingThing:
    .string "{PLAYER}: No, I mean...\p"
    .string "That's already a thing.\p"
    .string "It's rare, but you didn't invent\n"
    .string "it.\p"
    .string "You didn't really do anything\n"
    .string "special.\p"
    .string "You got lucky.$"

CeruleanCity_BikeShop_Frlg_Text_RocketCriminalMasterminds:
    .string "ROCKET GRUNT: We are CRIMINAL\n"
    .string "MASTERMINDS!$"

CeruleanCity_BikeShop_Frlg_Text_PlayerAreYou:
    .string "{PLAYER}: ...Are you?$"

CeruleanCity_BikeShop_Frlg_Text_JamesBooks:
    .string "JAMES: Listen, man.\p"
    .string "You know I need my money for books.$"

CeruleanCity_BikeShop_Frlg_Text_CounterpartBattleQuestion:
    .string "OAK'S GRANDCHILD: Don't we usually\n"
    .string "battle the bad guys?$"

CeruleanCity_BikeShop_Frlg_Text_PlayerDoWeNeedTo:
    .string "{PLAYER}: I mean...\p"
    .string "Do we really need to?\p"
    .string "They didn't actually do anything.$"

CeruleanCity_BikeShop_Frlg_Text_CounterpartMistyMad:
    .string "OAK'S GRANDCHILD: ...\p"
    .string "MISTY seemed pretty mad about them\n"
    .string "breaking into her building.$"

CeruleanCity_BikeShop_Frlg_Text_PlayerOhRight:
    .string "{PLAYER}: ...Oh.\p"
    .string "Right.$"

CeruleanCity_BikeShop_Frlg_Text_RocketSee:
    .string "ROCKET GRUNT: SEE?!$"

CeruleanCity_BikeShop_Frlg_Text_JamesWhyHappy:
    .string "JAMES: WHY ARE YOU HAPPY ABOUT\n"
    .string "THAT?!$"


@ ============================================================
@ TEXT - MAGIKARP / NPC INTERACTIONS
@ ============================================================

CeruleanCity_BikeShop_Frlg_Text_ShinyMagikarp:
    .string "MAGIKARP: Karp! Karp!\p"
    .string "{PLAYER}: ...Yep.\p"
    .string "It's definitely shiny.$"

CeruleanCity_BikeShop_Frlg_Text_RocketIdle:
    .string "ROCKET GRUNT: Don't touch our\n"
    .string "experiment!\p"
    .string "...It's very scientific.$"

CeruleanCity_BikeShop_Frlg_Text_JamesIdle:
    .string "JAMES: I did this for the books.\p"
    .string "Mostly the books.$"

@ ============================================================
@ EXTREMELY SUBTLE EVIL LAB SIGN
@ ============================================================

CeruleanCity_Frlg_EventScript_EvilLabSign::
    msgbox CeruleanCity_Frlg_Text_EvilLabSign, MSGBOX_SIGN
    end

CeruleanCity_Frlg_Text_EvilLabSign:
    .string "EVIL LAB!!!$"