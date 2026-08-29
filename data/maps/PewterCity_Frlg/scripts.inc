PewterCity_Frlg_MapScripts::
    map_script MAP_SCRIPT_ON_LOAD, PewterCity_Frlg_SetCounterpartGraphics
    .byte 0

PewterCity_Frlg_SetCounterpartGraphics:
    goto_if_eq VAR_COUNTERPART_ID, COUNTERPART_BRENDAN, PewterCity_Frlg_SetBrendan
    goto_if_eq VAR_COUNTERPART_ID, COUNTERPART_MAY, PewterCity_Frlg_SetMay
    goto_if_eq VAR_COUNTERPART_ID, COUNTERPART_LEXY, PewterCity_Frlg_SetLexy
    goto_if_eq VAR_COUNTERPART_ID, COUNTERPART_JUSTIN, PewterCity_Frlg_SetJustin
    goto_if_eq VAR_COUNTERPART_ID, COUNTERPART_MAAM, PewterCity_Frlg_SetMaam
    goto_if_eq VAR_COUNTERPART_ID, COUNTERPART_SIR, PewterCity_Frlg_SetSir
    goto PewterCity_Frlg_FinishMapLoad

PewterCity_Frlg_SetBrendan:
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_BRENDAN_NORMAL
    goto PewterCity_Frlg_FinishMapLoad

PewterCity_Frlg_SetMay:
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_MAY_NORMAL
    goto PewterCity_Frlg_FinishMapLoad

PewterCity_Frlg_SetLexy:
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_LEXY_NORMAL
    goto PewterCity_Frlg_FinishMapLoad

PewterCity_Frlg_SetJustin:
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_JUSTIN_NORMAL
    goto PewterCity_Frlg_FinishMapLoad

PewterCity_Frlg_SetMaam:
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_MAAM_NORMAL
    goto PewterCity_Frlg_FinishMapLoad

PewterCity_Frlg_SetSir:
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SIR_NORMAL
    goto PewterCity_Frlg_FinishMapLoad

PewterCity_Frlg_FinishMapLoad:
    end


@ ============================================================================
@ PHYSICAL COUNTERPART - PEWTER ARRIVAL
@ ============================================================================

PewterCity_Frlg_EventScript_CounterpartArrival::
    goto_if_set FLAG_HIDE_PEWTER_COUNTERPART, PewterCity_Frlg_EventScript_CounterpartArrival_End

    lockall

    applymovement LOCALID_PLAYER, PewterCity_Frlg_Movement_PlayerFaceCounterpart
    applymovement LOCALID_PEWTER_COUNTERPART, PewterCity_Frlg_Movement_CounterpartFacePlayer
    waitmovement 0

    msgbox PewterCity_Frlg_Text_CounterpartArrival1, MSGBOX_DEFAULT
    msgbox PewterCity_Frlg_Text_CounterpartArrival2, MSGBOX_DEFAULT

    applymovement LOCALID_PEWTER_COUNTERPART, PewterCity_Frlg_Movement_CounterpartLeaves
    waitmovement LOCALID_PEWTER_COUNTERPART

    setflag FLAG_HIDE_PEWTER_COUNTERPART
    removeobject LOCALID_PEWTER_COUNTERPART

    @ Rival has gone ahead to investigate near Lance.
    clearflag FLAG_HIDE_PEWTER_LANCE_COUNTERPART

    releaseall

PewterCity_Frlg_EventScript_CounterpartArrival_End:
    end


PewterCity_Frlg_EventScript_Counterpart::
    lock
    faceplayer
    msgbox PewterCity_Frlg_Text_CounterpartBeforeArrival, MSGBOX_DEFAULT
    release
    end


PewterCity_Frlg_Movement_PlayerFaceCounterpart:
    face_right
    step_end


PewterCity_Frlg_Movement_CounterpartFacePlayer:
    face_left
    step_end


PewterCity_Frlg_Movement_CounterpartLeaves:
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    step_end


PewterCity_Frlg_Text_CounterpartArrival1:
    .string "{PLAYER}: HOW are you already here?\p"
    .string "{RIVAL}: What?\p"
    .string "{PLAYER}: You did this in CERULEAN too.\p"
    .string "{RIVAL}: Did what?\p"
    .string "{PLAYER}: GET THERE BEFORE ME.\p"
    .string "{RIVAL}: Maybe you're slow.\p"
    .string "{PLAYER}: I WARPED HERE.\p"
    .string "LIKE I HAVE SUPERPOWERS.\p"
    .string "I WALKED THROUGH A DOOR AND--\p"
    .string "HOW DID YOU GET HERE FIRST?!\p"
    .string "{RIVAL}: I left before you.\p"
    .string "{PLAYER}: YOU WERE EATING PANCAKES.\p"
    .string "{RIVAL}: I eat fast.\p"
    .string "{PLAYER}: THAT DOESN'T EXPLAIN\n"
    .string "ANYTHING.\p"
    .string "{RIVAL}: Anyway.\p"
    .string "We'll cover more ground if we\n"
    .string "split up.$"


PewterCity_Frlg_Text_CounterpartArrival2:
    .string "{RIVAL}: Ask around.\p"
    .string "I'll do the same.\p"
    .string "We'll meet where it matters.$"


PewterCity_Frlg_Text_CounterpartBeforeArrival:
    .string "{RIVAL}: We should probably\n"
    .string "start asking around.$"


@ ============================================================================
@ LANCE-STAGE RIVAL
@ ============================================================================

PewterCity_Frlg_EventScript_LanceCounterpart::
    lock
    faceplayer

    compare VAR_BROCK_INGREDIENT_QUEST, 1
    goto_if_eq PewterCity_Frlg_EventScript_LanceCounterpartBeforeLance

    compare VAR_BROCK_INGREDIENT_QUEST, 2
    goto_if_eq PewterCity_Frlg_EventScript_LanceCounterpartAfterLance

    msgbox PewterCity_Frlg_Text_LanceCounterpartFallback, MSGBOX_DEFAULT
    release
    end


PewterCity_Frlg_EventScript_LanceCounterpartBeforeLance:
    msgbox PewterCity_Frlg_Text_LanceCounterpartBeforeLance, MSGBOX_DEFAULT
    release
    end


PewterCity_Frlg_EventScript_LanceCounterpartAfterLance:
    msgbox PewterCity_Frlg_Text_LanceCounterpartCapeTheory, MSGBOX_DEFAULT

    applymovement LOCALID_PEWTER_LANCE_COUNTERPART, PewterCity_Frlg_Movement_LanceCounterpartLeaves
    waitmovement LOCALID_PEWTER_LANCE_COUNTERPART

    setflag FLAG_HIDE_PEWTER_LANCE_COUNTERPART
    removeobject LOCALID_PEWTER_LANCE_COUNTERPART

    @ Rival's next physical copy is waiting at Savvy's.
    clearflag FLAG_HIDE_PEWTER_SAVVY_COUNTERPART

    release
    end


PewterCity_Frlg_Text_LanceCounterpartBeforeLance:
    .string "{RIVAL}: You talk to him.\p"
    .string "I'll stay here and listen.$"


PewterCity_Frlg_Text_LanceCounterpartFallback:
    .string "{RIVAL}: We should keep moving.$"


@ BROCK'S MYSTERY INGREDIENT SEARCH - PEWTER
@
@ STATE 0 = quest not started
@ STATE 1 = Brock sent player to Pewter
@ STATE 2 = Lance directed player to Savvy
@ STATE 3 = Savvy gave the Cerulean lead
@ ============================================================================


@ ============================================================================
@ LASS
@ ============================================================================

PewterCity_Frlg_EventScript_IngredientLass::
    lock
    faceplayer

    compare VAR_BROCK_INGREDIENT_QUEST, 1
    goto_if_eq PewterCity_Frlg_EventScript_LassSearching

    compare VAR_BROCK_INGREDIENT_QUEST, 2
    goto_if_eq PewterCity_Frlg_EventScript_LassSavvy

    compare VAR_BROCK_INGREDIENT_QUEST, 3
    goto_if_eq PewterCity_Frlg_EventScript_LassAfterSavvy

    msgbox PewterCity_Frlg_Text_LassNormal, MSGBOX_DEFAULT
    release
    end

PewterCity_Frlg_EventScript_LassSearching:
    msgbox PewterCity_Frlg_Text_LassSearching, MSGBOX_DEFAULT
    release
    end

PewterCity_Frlg_EventScript_LassSavvy:
    msgbox PewterCity_Frlg_Text_LassSavvy, MSGBOX_DEFAULT
    release
    end

PewterCity_Frlg_EventScript_LassAfterSavvy:
    msgbox PewterCity_Frlg_Text_LassAfterSavvy, MSGBOX_DEFAULT
    release
    end


@ ============================================================================
@ FAT MAN
@ ============================================================================

PewterCity_Frlg_EventScript_IngredientFatMan::
    lock
    faceplayer

    compare VAR_BROCK_INGREDIENT_QUEST, 1
    goto_if_eq PewterCity_Frlg_EventScript_FatManSearching

    compare VAR_BROCK_INGREDIENT_QUEST, 2
    goto_if_eq PewterCity_Frlg_EventScript_FatManSavvy

    compare VAR_BROCK_INGREDIENT_QUEST, 3
    goto_if_eq PewterCity_Frlg_EventScript_FatManAfterSavvy

    msgbox PewterCity_Frlg_Text_FatManNormal, MSGBOX_DEFAULT
    release
    end

PewterCity_Frlg_EventScript_FatManSearching:
    msgbox PewterCity_Frlg_Text_FatManSearching, MSGBOX_DEFAULT
    release
    end

PewterCity_Frlg_EventScript_FatManSavvy:
    msgbox PewterCity_Frlg_Text_FatManSavvy, MSGBOX_DEFAULT
    release
    end

PewterCity_Frlg_EventScript_FatManAfterSavvy:
    msgbox PewterCity_Frlg_Text_FatManAfterSavvy, MSGBOX_DEFAULT
    release
    end


@ ============================================================================
@ BUG CATCHER
@ ============================================================================

PewterCity_Frlg_EventScript_IngredientBugCatcher::
    lock
    faceplayer

    compare VAR_BROCK_INGREDIENT_QUEST, 1
    goto_if_eq PewterCity_Frlg_EventScript_BugCatcherSearching

    compare VAR_BROCK_INGREDIENT_QUEST, 2
    goto_if_eq PewterCity_Frlg_EventScript_BugCatcherSavvy

    compare VAR_BROCK_INGREDIENT_QUEST, 3
    goto_if_eq PewterCity_Frlg_EventScript_BugCatcherAfterSavvy

    msgbox PewterCity_Frlg_Text_BugCatcherNormal, MSGBOX_DEFAULT
    release
    end

PewterCity_Frlg_EventScript_BugCatcherSearching:
    msgbox PewterCity_Frlg_Text_BugCatcherSearching, MSGBOX_DEFAULT
    release
    end

PewterCity_Frlg_EventScript_BugCatcherSavvy:
    msgbox PewterCity_Frlg_Text_BugCatcherSavvy, MSGBOX_DEFAULT
    release
    end

PewterCity_Frlg_EventScript_BugCatcherAfterSavvy:
    msgbox PewterCity_Frlg_Text_BugCatcherAfterSavvy, MSGBOX_DEFAULT
    release
    end


@ ============================================================================
@ LANCE
@ ============================================================================

PewterCity_Frlg_EventScript_Lance::
    lock
    faceplayer
    call PewterCity_Frlg_EventScript_DragoniteFacePlayer

    compare VAR_BROCK_INGREDIENT_QUEST, 1
    goto_if_eq PewterCity_Frlg_EventScript_LanceQuest

    compare VAR_BROCK_INGREDIENT_QUEST, 2
    goto_if_eq PewterCity_Frlg_EventScript_LanceWaitingOnSavvy

    compare VAR_BROCK_INGREDIENT_QUEST, 3
    goto_if_eq PewterCity_Frlg_EventScript_LanceAfterSavvy

    msgbox PewterCity_Frlg_Text_LanceNormal, MSGBOX_DEFAULT
    release
    end


PewterCity_Frlg_EventScript_LanceQuest:
    msgbox PewterCity_Frlg_Text_LanceQuestStart, MSGBOX_DEFAULT
    msgbox PewterCity_Frlg_Text_LanceSavvyLead, MSGBOX_DEFAULT

    @ Lance gave us the next lead.
    @ Rival stays nearby until the player talks to them.
    setvar VAR_BROCK_INGREDIENT_QUEST, 2

    release
    end


PewterCity_Frlg_EventScript_LanceWaitingOnSavvy:
    msgbox PewterCity_Frlg_Text_LanceWaitingOnSavvy, MSGBOX_DEFAULT
    release
    end


PewterCity_Frlg_EventScript_LanceAfterSavvy:
    msgbox PewterCity_Frlg_Text_LanceAfterSavvy, MSGBOX_DEFAULT
    closemessage

    delay 15

    waitse
    playmoncry SPECIES_DRAGONITE, CRY_MODE_NORMAL
    waitmoncry
    delay 20

    warp MAP_CERULEAN_CITY, 33, 16
    waitstate
    end


@ ============================================================================
@ LANCE RIVAL EXIT CHOREOGRAPHY
@ ============================================================================

PewterCity_Frlg_Movement_LanceCounterpartFacePlayer:
    face_left
    step_end

PewterCity_Frlg_Movement_LanceCounterpartLeaves:
    face_left
    walk_left
    walk_left
    walk_down
    walk_down
    walk_down
    walk_down
    step_end


@ ============================================================================
@ TEXT
@ ============================================================================

PewterCity_Frlg_Text_LanceCounterpartCapeTheory:
    .string "{RIVAL}: I KNEW he'd know something!\p"
    .string "{PLAYER}: How?\p"
    .string "{RIVAL}: It was the cape.\p"
    .string "{PLAYER}: The cape?\p"
    .string "{RIVAL}: Guys with capes always\n"
    .string "know stuff.\p"
    .string "{PLAYER}: That's not--\p"
    .string "{RIVAL}: Byeeeee.$"


PewterCity_Frlg_Text_LassNormal:
    .string "PEWTER is quieter than it looks.\p"
    .string "Usually.$"

PewterCity_Frlg_Text_LassSearching:
    .string "An ingredient?\p"
    .string "That's... not very specific.\p"
    .string "Maybe ask around?$"

PewterCity_Frlg_Text_LassSavvy:
    .string "Oh! LANCE sent you to SAVVY?\p"
    .string "Then you're done asking us.\p"
    .string "If anybody in PEWTER knows,\n"
    .string "it's her.$"

PewterCity_Frlg_Text_LassAfterSavvy:
    .string "SAVVY knew, didn't she?\p"
    .string "She always knows.$"


PewterCity_Frlg_Text_FatManNormal:
    .string "Nothing beats a good meal.$"

PewterCity_Frlg_Text_FatManSearching:
    .string "You're looking for an ingredient?\p"
    .string "You came to the right man.\p"
    .string "{PLAYER}: Do you know where it is?\p"
    .string "...No.$"

PewterCity_Frlg_Text_FatManSavvy:
    .string "SAVVY?\p"
    .string "Yeah. She'd know.\p"
    .string "She knows things she has no\n"
    .string "business knowing.$"

PewterCity_Frlg_Text_FatManAfterSavvy:
    .string "So SAVVY had your answer?\p"
    .string "Of course she did.$"


PewterCity_Frlg_Text_BugCatcherNormal:
    .string "There are interesting people\n"
    .string "everywhere if you pay attention.$"

PewterCity_Frlg_Text_BugCatcherSearching:
    .string "An ingredient?\p"
    .string "Sorry. Haven't heard anything.$"

PewterCity_Frlg_Text_BugCatcherSavvy:
    .string "You're looking for SAVVY?\p"
    .string "South side of town.\p"
    .string "You'll know when you've found her.$"

PewterCity_Frlg_Text_BugCatcherAfterSavvy:
    .string "You're leaving already?\p"
    .string "Guess you found what you needed.$"


PewterCity_Frlg_Text_LanceNormal:
    .string "LANCE: PEWTER has a way of making\n"
    .string "people slow down.\p"
    .string "Usually that's a good thing.$"

PewterCity_Frlg_Text_LanceQuestStart:
    .string "LANCE: You aren't sightseeing.\p"
    .string "{PLAYER}: Brock sent me.\p"
    .string "We're looking for an ingredient.\p"
    .string "LANCE: An ingredient?\p"
    .string "And he sent you to PEWTER?\p"
    .string "{PLAYER}: That's literally all\n"
    .string "he gave me.$"


PewterCity_Frlg_Text_LanceSavvyLead:
    .string "LANCE: Then don't waste your time\n"
    .string "asking everyone in town.\p"
    .string "Find SAVVY.\p"
    .string "{PLAYER}: Savvy?\p"
    .string "LANCE: South side of PEWTER.\p"
    .string "If something happened here,\n"
    .string "she knows about it.$"


PewterCity_Frlg_Text_LanceWaitingOnSavvy:
    .string "LANCE: Find SAVVY.\p"
    .string "South side of town.\p"
    .string "Trust me.$"

PewterCity_Frlg_Text_LanceAfterSavvy:
    .string "LANCE: CERULEAN?\p"
    .string "Then whoever you're chasing\n"
    .string "didn't stay in PEWTER long.\p"
    .string "{PLAYER}: Guess I'm headed back.\p"
    .string "LANCE: DRAGONITE can take you.\p"
    .string "{PLAYER}: Wait, wha--$"


@ ============================================================================
@ EAST PEWTER NPCs
@ ============================================================================

PewterCity_Frlg_EventScript_EastBoy::
    lock
    faceplayer
    msgbox PewterCity_Frlg_Text_EastBoy, MSGBOX_DEFAULT
    release
    end

PewterCity_Frlg_EventScript_EastScientist::
    lock
    faceplayer
    msgbox PewterCity_Frlg_Text_EastScientist, MSGBOX_DEFAULT
    release
    end


PewterCity_Frlg_Text_EastBoy:
    .string "He keeps staring at rocks.\p"
    .string "Like... for HOURS.\p"
    .string "I asked what he was looking for.\p"
    .string "He said, 'context.'$"


PewterCity_Frlg_Text_EastScientist:
    .string "People think museums preserve\n"
    .string "answers.\p"
    .string "They don't.\p"
    .string "They preserve evidence.\p"
    .string "Answers change when we learn\n"
    .string "how to read it.$"


@ ============================================================================
@ Dragonite reacts when Player talks to Lance
@ ============================================================================

PewterCity_Frlg_EventScript_DragoniteFacePlayer:
    getplayerxy VAR_TEMP_0, VAR_TEMP_1

    @ Player is LEFT of Lance at (33,17).
    goto_if_eq VAR_TEMP_0, 33, PewterCity_Frlg_EventScript_DragoniteFaceWest

    @ Player is directly ABOVE Lance at (34,16).
    goto_if_eq VAR_TEMP_1, 16, PewterCity_Frlg_EventScript_DragoniteFaceNorth

    @ Normal interaction: Player is BELOW Lance at (34,18).
    goto PewterCity_Frlg_EventScript_DragoniteFaceSouth


PewterCity_Frlg_EventScript_DragoniteFaceSouth:
    applymovement LOCALID_PEWTER_DRAGONITE, PewterCity_Frlg_Movement_DragoniteFaceSouth
    waitmovement LOCALID_PEWTER_DRAGONITE
    return

PewterCity_Frlg_EventScript_DragoniteFaceNorth:
    applymovement LOCALID_PEWTER_DRAGONITE, PewterCity_Frlg_Movement_DragoniteFaceNorth
    waitmovement LOCALID_PEWTER_DRAGONITE
    return

PewterCity_Frlg_EventScript_DragoniteFaceWest:
    applymovement LOCALID_PEWTER_DRAGONITE, PewterCity_Frlg_Movement_DragoniteFaceWest
    waitmovement LOCALID_PEWTER_DRAGONITE
    return

PewterCity_Frlg_EventScript_DragoniteFaceEast:
    applymovement LOCALID_PEWTER_DRAGONITE, PewterCity_Frlg_Movement_DragoniteFaceEast
    waitmovement LOCALID_PEWTER_DRAGONITE
    return

PewterCity_Frlg_Movement_DragoniteFaceSouth:
    face_down
    step_end

PewterCity_Frlg_Movement_DragoniteFaceNorth:
    face_up
    step_end

PewterCity_Frlg_Movement_DragoniteFaceWest:
    face_left
    step_end

PewterCity_Frlg_Movement_DragoniteFaceEast:
    face_right
    step_end

