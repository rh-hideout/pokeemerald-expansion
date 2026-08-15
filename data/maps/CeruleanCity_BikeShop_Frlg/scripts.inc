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
@ CERULEAN -> EVIL LAB ENTRANCE
@
@ Assign this script to the TWO Cerulean exterior coord triggers
@ at the lab entrance. This bypasses destination warp IDs entirely
@ and always places the player at x=5, y=8 inside the lab.
@
@ IMPORTANT:
@ - Lab mission trigger stays at (5,7)
@ - Entrance/spawn is (5,8)
@ - Exit trigger stays at (5,9)
@ ============================================================

CeruleanCity_Frlg_EventScript_EnterEvilLab::
    warp MAP_CERULEAN_CITY_BIKE_SHOP, 5, 8
    waitstate
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

    goto_if_set FLAG_CERULEAN_LAB_COMPLETE, CeruleanCity_BikeShop_Frlg_EventScript_LabAlreadyComplete
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

    goto CeruleanCity_BikeShop_Frlg_EventScript_StartBattle

@ ============================================================
@ BATTLE SEQUENCE
@ Player + Counterpart vs Rocket Grunt + James
@ ============================================================

CeruleanCity_BikeShop_Frlg_EventScript_StartBattle:
    msgbox CeruleanCity_BikeShop_Frlg_Text_BeforeBattle, MSGBOX_DEFAULT
    closemessage

    goto_if_eq VAR_COUNTERPART_ID, COUNTERPART_BRENDAN, CeruleanCity_BikeShop_Frlg_EventScript_BattleBrendan
    goto_if_eq VAR_COUNTERPART_ID, COUNTERPART_MAY, CeruleanCity_BikeShop_Frlg_EventScript_BattleMay
    goto_if_eq VAR_COUNTERPART_ID, COUNTERPART_LEXY, CeruleanCity_BikeShop_Frlg_EventScript_BattleCeleste
    goto_if_eq VAR_COUNTERPART_ID, COUNTERPART_JUSTIN, CeruleanCity_BikeShop_Frlg_EventScript_BattleHiiro
    goto_if_eq VAR_COUNTERPART_ID, COUNTERPART_MAAM, CeruleanCity_BikeShop_Frlg_EventScript_BattleAleciya
    goto_if_eq VAR_COUNTERPART_ID, COUNTERPART_SIR, CeruleanCity_BikeShop_Frlg_EventScript_BattleAster

    @ Fallback
    goto CeruleanCity_BikeShop_Frlg_EventScript_BattleCeleste


CeruleanCity_BikeShop_Frlg_EventScript_BattleBrendan:
    multi_2_vs_2 TRAINER_CERULEAN_ROCKET_GRUNT, CeruleanCity_BikeShop_Frlg_Text_RocketDefeated, TRAINER_CERULEAN_JAMES, CeruleanCity_BikeShop_Frlg_Text_JamesDefeated, PARTNER_BRENDAN
    switch VAR_RESULT
    case 1, CeruleanCity_BikeShop_Frlg_EventScript_AfterBattleWin
    fadescreen FADE_TO_BLACK
    special SetCB2WhiteOut
    end


CeruleanCity_BikeShop_Frlg_EventScript_BattleMay:
    multi_2_vs_2 TRAINER_CERULEAN_ROCKET_GRUNT, CeruleanCity_BikeShop_Frlg_Text_RocketDefeated, TRAINER_CERULEAN_JAMES, CeruleanCity_BikeShop_Frlg_Text_JamesDefeated, PARTNER_MAY
    switch VAR_RESULT
    case 1, CeruleanCity_BikeShop_Frlg_EventScript_AfterBattleWin
    fadescreen FADE_TO_BLACK
    special SetCB2WhiteOut
    end


CeruleanCity_BikeShop_Frlg_EventScript_BattleCeleste:
    multi_2_vs_2 TRAINER_CERULEAN_ROCKET_GRUNT, CeruleanCity_BikeShop_Frlg_Text_RocketDefeated, TRAINER_CERULEAN_JAMES, CeruleanCity_BikeShop_Frlg_Text_JamesDefeated, PARTNER_CELESTE
    switch VAR_RESULT
    case 1, CeruleanCity_BikeShop_Frlg_EventScript_AfterBattleWin
    fadescreen FADE_TO_BLACK
    special SetCB2WhiteOut
    end


CeruleanCity_BikeShop_Frlg_EventScript_BattleHiiro:
    multi_2_vs_2 TRAINER_CERULEAN_ROCKET_GRUNT, CeruleanCity_BikeShop_Frlg_Text_RocketDefeated, TRAINER_CERULEAN_JAMES, CeruleanCity_BikeShop_Frlg_Text_JamesDefeated, PARTNER_HIIRO
    switch VAR_RESULT
    case 1, CeruleanCity_BikeShop_Frlg_EventScript_AfterBattleWin
    fadescreen FADE_TO_BLACK
    special SetCB2WhiteOut
    end


CeruleanCity_BikeShop_Frlg_EventScript_BattleAleciya:
    multi_2_vs_2 TRAINER_CERULEAN_ROCKET_GRUNT, CeruleanCity_BikeShop_Frlg_Text_RocketDefeated, TRAINER_CERULEAN_JAMES, CeruleanCity_BikeShop_Frlg_Text_JamesDefeated, PARTNER_ALECIYA
    switch VAR_RESULT
    case 1, CeruleanCity_BikeShop_Frlg_EventScript_AfterBattleWin
    fadescreen FADE_TO_BLACK
    special SetCB2WhiteOut
    end


CeruleanCity_BikeShop_Frlg_EventScript_BattleAster:
    multi_2_vs_2 TRAINER_CERULEAN_ROCKET_GRUNT, CeruleanCity_BikeShop_Frlg_Text_RocketDefeated, TRAINER_CERULEAN_JAMES, CeruleanCity_BikeShop_Frlg_Text_JamesDefeated, PARTNER_ASTER
    switch VAR_RESULT
    case 1, CeruleanCity_BikeShop_Frlg_EventScript_AfterBattleWin
    fadescreen FADE_TO_BLACK
    special SetCB2WhiteOut
    end

@ ============================================================
@ POST-BATTLE
@ ============================================================

CeruleanCity_BikeShop_Frlg_EventScript_AfterBattleWin:
    msgbox CeruleanCity_BikeShop_Frlg_Text_RocketPleaseKeepCarpy, MSGBOX_DEFAULT
    closemessage

    multichoice 0, 0, MULTICHOICE_CARPY_DECISION, FALSE

    switch VAR_RESULT
    case 0, CeruleanCity_BikeShop_Frlg_EventScript_KeepCarpy
    case 1, CeruleanCity_BikeShop_Frlg_EventScript_TakeCarpy

    goto CeruleanCity_BikeShop_Frlg_EventScript_TakeCarpy


@ ============================================================
@ CHOICE 1 - COMPASSION
@ Let them keep Carpy
@ ============================================================

CeruleanCity_BikeShop_Frlg_EventScript_KeepCarpy:
    addvar VAR_COMPASSION, 1

    msgbox CeruleanCity_BikeShop_Frlg_Text_PlayerKeepCarpy, MSGBOX_DEFAULT
    closemessage

    msgbox CeruleanCity_BikeShop_Frlg_Text_JamesThankYou, MSGBOX_DEFAULT
    closemessage

    goto CeruleanCity_BikeShop_Frlg_EventScript_CarpyExitAllowed


@ ============================================================
@ CHOICE 2 - RESOLVE
@ Tell them they cannot keep Carpy
@ They ignore you anyway lmao
@ ============================================================

CeruleanCity_BikeShop_Frlg_EventScript_TakeCarpy:
    addvar VAR_RESOLVE, 1

    msgbox CeruleanCity_BikeShop_Frlg_Text_PlayerTakeCarpy, MSGBOX_DEFAULT
    closemessage

    msgbox CeruleanCity_BikeShop_Frlg_Text_RocketCounterpoint, MSGBOX_DEFAULT
    closemessage

    msgbox CeruleanCity_BikeShop_Frlg_Text_JamesGrabCarpy, MSGBOX_DEFAULT
    closemessage

    goto CeruleanCity_BikeShop_Frlg_EventScript_CarpyExitStolen


@ ============================================================
@ CARPY + GRUNTS EXIT
@ ============================================================

CeruleanCity_BikeShop_Frlg_EventScript_CarpyExitAllowed:
    setvar VAR_TEMP_1, 1
    goto CeruleanCity_BikeShop_Frlg_EventScript_CarpyExit


CeruleanCity_BikeShop_Frlg_EventScript_CarpyExitStolen:
    setvar VAR_TEMP_1, 0
    goto CeruleanCity_BikeShop_Frlg_EventScript_CarpyExit


CeruleanCity_BikeShop_Frlg_EventScript_CarpyExit:
    fadescreen FADE_TO_BLACK

    setflag FLAG_HIDE_CERULEAN_ROCKET_GRUNT
    setflag FLAG_HIDE_CERULEAN_AQUA_GRUNT
    setflag FLAG_CERULEAN_LAB_COMPLETE

    removeobject LOCALID_CERULEAN_LAB_ROCKET
    removeobject LOCALID_JAMES
    removeobject LOCALID_LAB_MAGICARP

    fadescreen FADE_FROM_BLACK

    goto_if_eq VAR_TEMP_1, 1, CeruleanCity_BikeShop_Frlg_EventScript_CarpyAllowedReaction

    msgbox CeruleanCity_BikeShop_Frlg_Text_CounterpartCarpyGone, MSGBOX_DEFAULT
    closemessage

    msgbox CeruleanCity_BikeShop_Frlg_Text_PlayerYep, MSGBOX_DEFAULT
    closemessage

    goto CeruleanCity_BikeShop_Frlg_EventScript_PrepareGoodbye


CeruleanCity_BikeShop_Frlg_EventScript_CarpyAllowedReaction:
    msgbox CeruleanCity_BikeShop_Frlg_Text_CounterpartCarpyAllowed, MSGBOX_DEFAULT
    closemessage

    msgbox CeruleanCity_BikeShop_Frlg_Text_PlayerYep, MSGBOX_DEFAULT
    closemessage

    goto CeruleanCity_BikeShop_Frlg_EventScript_PrepareGoodbye


CeruleanCity_BikeShop_Frlg_EventScript_PrepareGoodbye:
    @ After the grunts disappear, turn toward each other.
    applymovement LOCALID_COUNTERPART_CERULEAN_LAB, Common_Movement_FaceDown
    applymovement LOCALID_PLAYER, CeruleanCity_BikeShop_Frlg_Movement_FaceUp
    waitmovement 0

    goto CeruleanCity_BikeShop_Frlg_EventScript_CounterpartGoodbye


@ ============================================================
@ TEXT - BATTLE / CARPY
@ ============================================================

CeruleanCity_BikeShop_Frlg_Text_BeforeBattle:
    .string "ROCKET GRUNT: FINE!\p"
    .string "If you want a battle so bad-\p"
    .string "JAMES: They literally said they\n"
    .string "didn't.\p"
    .string "ROCKET GRUNT: JAMES.$"

CeruleanCity_BikeShop_Frlg_Text_RocketPleaseKeepCarpy:
    .string "ROCKET GRUNT: WAIT!\p"
    .string "Please don't take CARPY!\p"
    .string "We love him!\p"
    .string "He's ours!!$"

CeruleanCity_BikeShop_Frlg_Text_PlayerKeepCarpy:
    .string "{PLAYER}: ...Fine.\p"
    .string "You can keep him.$"

CeruleanCity_BikeShop_Frlg_Text_JamesThankYou:
    .string "JAMES: YES!\p"
    .string "CARPY, YOU'RE COMING WITH US!$"

CeruleanCity_BikeShop_Frlg_Text_PlayerTakeCarpy:
    .string "{PLAYER}: No.\p"
    .string "You're not taking him.$"

CeruleanCity_BikeShop_Frlg_Text_RocketCounterpoint:
    .string "ROCKET GRUNT: ...\p"
    .string "Okay, counterpoint...\p"
    .string "YES WE ARE.$"

CeruleanCity_BikeShop_Frlg_Text_JamesGrabCarpy:
    .string "JAMES: Grab CARPY and RUN!$"

CeruleanCity_BikeShop_Frlg_Text_CounterpartCarpyGone:
    .string "OAK'S GRANDCHILD: ...\p"
    .string "Did they just steal the MAGIKARP\n"
    .string "you said they couldn't keep?$"

CeruleanCity_BikeShop_Frlg_Text_PlayerYep:
    .string "{PLAYER}: ...Yep.$"


CeruleanCity_BikeShop_Frlg_Text_CounterpartCarpyAllowed:
    .string "OAK'S GRANDCHILD: ...\p"
    .string "Did they seriously just run off\n"
    .string "with that MAGIKARP?\p"
    .string "...You DID say they could have it.$"


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

CeruleanCity_BikeShop_Frlg_Text_RocketDefeated:
    .string "ROCKET GRUNT: This was not part of\n"
    .string "the experiment!$"

CeruleanCity_BikeShop_Frlg_Text_JamesDefeated:
    .string "JAMES: ...There goes my book money.$"

@ ============================================================
@ LAB ALREADY COMPLETE
@ Prevents the entrance trigger from replaying the lab scene.
@ ============================================================

CeruleanCity_BikeShop_Frlg_EventScript_LabAlreadyComplete:
    end


@ ============================================================
@ LAB EXIT
@ Scripted exit bypasses broken native FRLG Bike Shop warp.
@ Referenced by map coord events, so this MUST be global (::).
@ ============================================================

CeruleanCity_BikeShop_Frlg_EventScript_ExitLab::
    warp MAP_CERULEAN_CITY, 13, 28
    waitstate
    end

@ ============================================================
@ CERULEAN LAB FINALE
@ ============================================================

CeruleanCity_BikeShop_Frlg_EventScript_CounterpartGoodbye::
    msgbox CeruleanCity_BikeShop_Frlg_Text_CounterpartBack, MSGBOX_DEFAULT
    closemessage

    msgbox CeruleanCity_BikeShop_Frlg_Text_CounterpartHandleSomething, MSGBOX_DEFAULT
    closemessage

    goto_if_set FLAG_HIDE_CERULEAN_RIVAL, CeruleanCity_BikeShop_Frlg_EventScript_LeaveAfterGary

    goto CeruleanCity_BikeShop_Frlg_EventScript_LeaveWithoutGary


CeruleanCity_BikeShop_Frlg_EventScript_LeaveAfterGary:
    applymovement LOCALID_COUNTERPART_CERULEAN_LAB, CeruleanCity_BikeShop_Frlg_Movement_CounterpartLeaves
    waitmovement 0

    setflag FLAG_HIDE_CERULEAN_LAB_COUNTERPART
    removeobject LOCALID_COUNTERPART_CERULEAN_LAB

    msgbox CeruleanCity_BikeShop_Frlg_Text_GaryThought, MSGBOX_DEFAULT
    closemessage

    releaseall
    end


CeruleanCity_BikeShop_Frlg_EventScript_LeaveWithoutGary:
    applymovement LOCALID_COUNTERPART_CERULEAN_LAB, CeruleanCity_BikeShop_Frlg_Movement_CounterpartLeaves
    waitmovement 0

    setflag FLAG_HIDE_CERULEAN_LAB_COUNTERPART
    removeobject LOCALID_COUNTERPART_CERULEAN_LAB

    releaseall
    end


CeruleanCity_BikeShop_Frlg_Movement_CounterpartLeaves:
    walk_right
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    step_end


CeruleanCity_BikeShop_Frlg_Text_CounterpartBack:
    .string "OAK'S GRANDCHILD: Well...\p"
    .string "I guess we should get back.$"


CeruleanCity_BikeShop_Frlg_Text_CounterpartHandleSomething:
    .string "OAK'S GRANDCHILD: Actually...\p"
    .string "There's something I need to handle\n"
    .string "first.\p"
    .string "I'll meet you back at MISTY'S\n"
    .string "house.$"


CeruleanCity_BikeShop_Frlg_Text_GaryThought:
    .string "{PLAYER}: ...They must be going\n"
    .string "back to talk to that guy from the\l"
    .string "bridge.\p"
    .string "Better stay out of it.\p"
    .string "They're... a LOT.$"
