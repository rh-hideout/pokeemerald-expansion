@ =============================================================================
@ LITTLEROOT TOWN — MAP SCRIPTS
@
@ Opening quest flow:
@
@   1. Blaine reports that his important book is missing.
@   2. VAR_LIBRARY_BOOK_QUEST is set to 1 inside the library.
@   3. Fat Man points the player toward the far side of town.
@   4. Older Brother identifies his little sister as the child with the book.
@   5. Little Girl confesses and gives the player three response choices.
@   6. VAR_LIBRARY_BOOK_QUEST becomes 2.
@   7. FLAG_RESTAURANT_BOOK_SEARCH unlocks the restaurant sequence.
@   8. The book is eventually returned to Blaine.
@   9. FLAG_LIBRARY_BOOK_MISSION_COMPLETE marks the entire quest complete.
@ =============================================================================

LittlerootTown_MapScripts::
    map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_OnTransition
    map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_OnFrame
    map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, LittlerootTown_OnWarp
    .byte 0


@ =============================================================================
@ MAP TRANSITION
@
@ The original moving-truck and rival-opening logic has been removed.
@ Dex-upgrade support remains intact.
@ =============================================================================

LittlerootTown_OnTransition:
    setflag FLAG_VISITED_LITTLEROOT_TOWN
    setflag FLAG_HIDE_HARD_ROCK_BLAINE
    
    call_if_eq VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 1, LittlerootTown_EventScript_HideMapNamePopup
    call_if_eq VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 2, LittlerootTown_EventScript_LeftLabAfterDexUpgrade

    end


LittlerootTown_EventScript_HideMapNamePopup:
    setflag FLAG_HIDE_MAP_NAME_POPUP
    return


LittlerootTown_EventScript_LeftLabAfterDexUpgrade:
    setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 3
    return


@ =============================================================================
@ ON-FRAME TABLE
@ =============================================================================

LittlerootTown_OnFrame:
    map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 1, LittlerootTown_EventScript_BeginDexUpgradeScene
    .2byte 0


@ =============================================================================
@ DEX-UPGRADE SCENE
@
@ Preserved from the original script for later-game compatibility.
@ =============================================================================

LittlerootTown_EventScript_BeginDexUpgradeScene:
    lockall

    playse SE_PIN

    applymovement LOCALID_LITTLEROOT_BIRCH, Common_Movement_ExclamationMark
    waitmovement 0

    delay 80

    msgbox LittlerootTown_Text_BirchSomethingToShowYouAtLab, MSGBOX_DEFAULT
    closemessage

    clearflag FLAG_HIDE_LITTLEROOT_TOWN_RIVAL
    clearflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCH

    delay 20

    clearflag FLAG_HIDE_MAP_NAME_POPUP

    warp MAP_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB, 6, 5
    waitstate

    releaseall
    end


@ =============================================================================
@ WARP-IN TABLE — DEX UPGRADE
@ =============================================================================

LittlerootTown_OnWarp:
    map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 1, LittlerootTown_EventScript_SetRivalBirchPosForDexUpgrade
    .2byte 0


LittlerootTown_EventScript_SetRivalBirchPosForDexUpgrade:
    addobject LOCALID_LITTLEROOT_BIRCH
    addobject LOCALID_LITTLEROOT_RIVAL

    checkplayergender
    goto_if_eq VAR_RESULT, MALE, LittlerootTown_EventScript_SetRivalBirchPosForDexUpgradeMale
    goto LittlerootTown_EventScript_SetRivalBirchPosForDexUpgradeFemale


LittlerootTown_EventScript_SetRivalBirchPosForDexUpgradeMale:
    setobjectxy LOCALID_LITTLEROOT_RIVAL, 6, 10
    setobjectxy LOCALID_LITTLEROOT_BIRCH, 5, 10
    end


LittlerootTown_EventScript_SetRivalBirchPosForDexUpgradeFemale:
    setobjectxy LOCALID_LITTLEROOT_RIVAL, 13, 10
    setobjectxy LOCALID_LITTLEROOT_BIRCH, 14, 10
    end


@ =============================================================================
@ FAT MAN — FIRST OUTSIDE CLUE
@
@ Normal:
@   Generic town dialogue.
@
@ Quest state 1:
@   Points the player toward the trees.
@   Sets FLAG_LIBRARY_OUTSIDE_CLUE.
@
@ Later:
@   Reminds the player where he saw the child go.
@ =============================================================================

LittlerootTown_EventScript_FatMan::
    lock
    faceplayer

    goto_if_set FLAG_LIBRARY_BOOK_MISSION_COMPLETE, LittlerootTown_EventScript_FatManAfterQuest

    compare VAR_LIBRARY_BOOK_QUEST, 1
    goto_if_eq LittlerootTown_EventScript_FatManBookClue

    compare VAR_LIBRARY_BOOK_QUEST, 2
    goto_if_eq LittlerootTown_EventScript_FatManDuringRestaurantSearch

    msgbox LittlerootTown_Text_FatManNormal, MSGBOX_NPC

    release
    end


LittlerootTown_EventScript_FatManBookClue:
    goto_if_set FLAG_LIBRARY_OUTSIDE_CLUE, LittlerootTown_EventScript_FatManRepeatClue

    msgbox LittlerootTown_Text_FatManBookClue, MSGBOX_DEFAULT
    closemessage

    setflag FLAG_LIBRARY_OUTSIDE_CLUE

    release
    end


LittlerootTown_EventScript_FatManRepeatClue:
    msgbox LittlerootTown_Text_FatManRepeatClue, MSGBOX_NPC

    release
    end


LittlerootTown_EventScript_FatManDuringRestaurantSearch:
    msgbox LittlerootTown_Text_FatManRestaurantReminder, MSGBOX_NPC

    release
    end


LittlerootTown_EventScript_FatManAfterQuest:
    msgbox LittlerootTown_Text_FatManAfterQuest, MSGBOX_NPC

    release
    end


@ =============================================================================
@ OLDER BROTHER — SECOND OUTSIDE CLUE
@
@ The Fat Man clue must be heard first.
@ The brother then identifies his little sister as the child with the book.
@ =============================================================================

LittlerootTown_EventScript_Boy::
    lock
    faceplayer

    goto_if_set FLAG_LIBRARY_BOOK_MISSION_COMPLETE, LittlerootTown_EventScript_BrotherAfterQuest

    compare VAR_LIBRARY_BOOK_QUEST, 1
    goto_if_ne LittlerootTown_EventScript_BrotherNormal

    goto_if_unset FLAG_LIBRARY_OUTSIDE_CLUE, LittlerootTown_EventScript_BrotherBeforeFatManClue
    goto_if_set FLAG_FOUND_BOOK_GIRL, LittlerootTown_EventScript_BrotherRepeatClue

    msgbox LittlerootTown_Text_BrotherBookClue, MSGBOX_DEFAULT
    closemessage

    setflag FLAG_FOUND_BOOK_GIRL

    release
    end


LittlerootTown_EventScript_BrotherBeforeFatManClue:
    msgbox LittlerootTown_Text_BrotherBeforeClue, MSGBOX_NPC

    release
    end


LittlerootTown_EventScript_BrotherRepeatClue:
    msgbox LittlerootTown_Text_BrotherRepeatClue, MSGBOX_NPC

    release
    end


LittlerootTown_EventScript_BrotherNormal:
    msgbox LittlerootTown_Text_BrotherNormal, MSGBOX_NPC

    release
    end


LittlerootTown_EventScript_BrotherAfterQuest:
    msgbox LittlerootTown_Text_BrotherAfterQuest, MSGBOX_NPC

    release
    end


@ =============================================================================
@ LITTLE GIRL — MISSING-BOOK CONFESSION
@
@ This uses the object that was previously assigned to:
@
@     LittlerootTown_EventScript_Twin
@
@ The script label is preserved so the Porymap object does not need to be
@ reassigned immediately.
@
@ The girl only gives the complete confession after the brother identifies
@ her. Until then, she remains upset and avoids explaining herself.
@ =============================================================================

LittlerootTown_EventScript_Twin::
    lock
    faceplayer

    goto_if_set FLAG_LIBRARY_BOOK_MISSION_COMPLETE, LittlerootTown_EventScript_LittleGirlAfterQuest

    compare VAR_LIBRARY_BOOK_QUEST, 0
    goto_if_eq LittlerootTown_EventScript_LittleGirlBeforeQuest

    compare VAR_LIBRARY_BOOK_QUEST, 1
    goto_if_eq LittlerootTown_EventScript_LittleGirlQuestActive

    compare VAR_LIBRARY_BOOK_QUEST, 2
    goto_if_eq LittlerootTown_EventScript_LittleGirlRestaurantSearch

    compare VAR_LIBRARY_BOOK_QUEST, 3
    goto_if_eq LittlerootTown_EventScript_LittleGirlBookRecovered

    goto LittlerootTown_EventScript_LittleGirlNormal


LittlerootTown_EventScript_LittleGirlBeforeQuest:
    msgbox LittlerootTown_Text_LittleGirlBeforeQuest, MSGBOX_NPC

    release
    end


LittlerootTown_EventScript_LittleGirlQuestActive:
    goto_if_unset FLAG_FOUND_BOOK_GIRL, LittlerootTown_EventScript_LittleGirlCrying
    goto LittlerootTown_EventScript_LittleGirlConfession


LittlerootTown_EventScript_LittleGirlCrying:
    msgbox LittlerootTown_Text_LittleGirlCrying, MSGBOX_DEFAULT

    release
    end


@ =============================================================================
@ LITTLE GIRL — CONFESSION
@ =============================================================================

LittlerootTown_EventScript_LittleGirlConfession:
    msgbox LittlerootTown_Text_PlayerAsksAboutBook, MSGBOX_DEFAULT
    closemessage

    delay 15

    msgbox LittlerootTown_Text_LittleGirlConfession, MSGBOX_DEFAULT
    closemessage

    delay 15

    multichoicedefault 8, 6, MULTI_LITTLE_GIRL_BOOK_RESPONSE, 0, FALSE

    switch VAR_RESULT
    case 0, LittlerootTown_EventScript_LittleGirlComfort
    case 1, LittlerootTown_EventScript_LittleGirlAccountability
    case 2, LittlerootTown_EventScript_LittleGirlInvestigate

    @ Safe fallback.
    goto LittlerootTown_EventScript_LittleGirlInvestigate


@ =============================================================================
@ RESPONSE ONE — COMPASSION
@
@ Menu choice:
@   "It's okay. We'll fix it."
@ =============================================================================

LittlerootTown_EventScript_LittleGirlComfort:
    addvar VAR_COMPASSION, 1

    msgbox LittlerootTown_Text_PlayerComfortsGirl, MSGBOX_DEFAULT
    closemessage

    delay 10

    msgbox LittlerootTown_Text_LittleGirlComforted, MSGBOX_DEFAULT
    closemessage

    goto LittlerootTown_EventScript_LittleGirlRevealRestaurant


@ =============================================================================
@ RESPONSE TWO — RESOLVE / ACCOUNTABILITY
@
@ Menu choice:
@   "You need to tell Blaine."
@ =============================================================================

LittlerootTown_EventScript_LittleGirlAccountability:
    addvar VAR_RESOLVE, 1

    msgbox LittlerootTown_Text_PlayerHoldsGirlAccountable, MSGBOX_DEFAULT
    closemessage

    delay 10

    msgbox LittlerootTown_Text_LittleGirlAcceptsResponsibility, MSGBOX_DEFAULT
    closemessage

    goto LittlerootTown_EventScript_LittleGirlRevealRestaurant


@ =============================================================================
@ RESPONSE THREE — CURIOSITY / INVESTIGATION
@
@ Menu choice:
@   "Where did you last have it?"
@ =============================================================================

LittlerootTown_EventScript_LittleGirlInvestigate:
    addvar VAR_CURIOSITY, 1

    msgbox LittlerootTown_Text_PlayerAsksForLocation, MSGBOX_DEFAULT
    closemessage

    delay 10

    msgbox LittlerootTown_Text_LittleGirlExplainsLocation, MSGBOX_DEFAULT
    closemessage

    goto LittlerootTown_EventScript_LittleGirlUnlockRestaurant


@ =============================================================================
@ SHARED RESTAURANT REVEAL
@
@ The emotional branches rejoin here. The girl explains that the book was
@ lost near the restaurant.
@ =============================================================================

LittlerootTown_EventScript_LittleGirlRevealRestaurant:
    msgbox LittlerootTown_Text_LittleGirlExplainsLocation, MSGBOX_DEFAULT
    closemessage

    goto LittlerootTown_EventScript_LittleGirlUnlockRestaurant


LittlerootTown_EventScript_LittleGirlUnlockRestaurant:
    setvar VAR_LIBRARY_BOOK_QUEST, 2
    setflag FLAG_RESTAURANT_BOOK_SEARCH

    msgbox LittlerootTown_Text_LittleGirlGoToRestaurant, MSGBOX_DEFAULT
    closemessage

    release
    end


@ =============================================================================
@ LITTLE GIRL — LATER QUEST STATES
@ =============================================================================

LittlerootTown_EventScript_LittleGirlRestaurantSearch:
    msgbox LittlerootTown_Text_LittleGirlRestaurantSearch, MSGBOX_NPC

    release
    end


LittlerootTown_EventScript_LittleGirlBookRecovered:
    msgbox LittlerootTown_Text_LittleGirlBookRecovered, MSGBOX_NPC

    release
    end


LittlerootTown_EventScript_LittleGirlAfterQuest:
    msgbox LittlerootTown_Text_LittleGirlAfterQuest, MSGBOX_NPC

    release
    end


LittlerootTown_EventScript_LittleGirlNormal:
    msgbox LittlerootTown_Text_LittleGirlNormal, MSGBOX_NPC

    release
    end


@ =============================================================================
@ COMPATIBILITY LABEL
@
@ The uploaded script also had a separate BookWitness object label. This now
@ redirects to the older-brother clue script so an existing Porymap object
@ using that label will still compile and function.
@ =============================================================================

LittlerootTown_EventScript_BookWitness::
    goto LittlerootTown_EventScript_Boy


LittlerootTown_EventScript_BookWitnessNormal:
    goto LittlerootTown_EventScript_BrotherNormal


@ =============================================================================
@ ROUTE-EXIT BLOCKERS
@
@ These labels are retained in case the existing map coordination events still
@ reference them. Before the full book mission is complete, the player is
@ encouraged to finish exploring Littleroot.
@
@ Once FLAG_LIBRARY_BOOK_MISSION_COMPLETE is set, these scripts immediately
@ release without pushing the player.
@ =============================================================================

LittlerootTown_EventScript_NeedPokemonTriggerLeft::
    lockall

    goto_if_set FLAG_LIBRARY_BOOK_MISSION_COMPLETE, LittlerootTown_EventScript_RouteExitAllowed

    msgbox LittlerootTown_Text_ExploreTownFirst, MSGBOX_DEFAULT
    closemessage

    applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_Movement_PushPlayerBackFromRoute
    waitmovement 0

    releaseall
    end


LittlerootTown_EventScript_NeedPokemonTriggerRight::
    lockall

    goto_if_set FLAG_LIBRARY_BOOK_MISSION_COMPLETE, LittlerootTown_EventScript_RouteExitAllowed

    msgbox LittlerootTown_Text_ExploreTownFirst, MSGBOX_DEFAULT
    closemessage

    applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_Movement_PushPlayerBackFromRoute
    waitmovement 0

    releaseall
    end


LittlerootTown_EventScript_GoSaveBirchTrigger::
    goto LittlerootTown_EventScript_NeedPokemonTriggerLeft


LittlerootTown_EventScript_RouteExitAllowed:
    releaseall
    end


LittlerootTown_Movement_PushPlayerBackFromRoute:
    lock_facing_direction
    walk_down
    unlock_facing_direction
    step_end


@ =============================================================================
@ TOWN SIGNS
@ =============================================================================

LittlerootTown_EventScript_TownSign::
    msgbox LittlerootTown_Text_TownSign, MSGBOX_SIGN
    end


LittlerootTown_EventScript_BirchsLabSign::
    msgbox LittlerootTown_Text_ProfBirchsLab, MSGBOX_SIGN
    end


LittlerootTown_EventScript_BrendansHouseSign::
    msgbox LittlerootTown_Text_PlayersHouse, MSGBOX_SIGN
    end


LittlerootTown_EventScript_MaysHouseSign::
    msgbox LittlerootTown_Text_NeighborHouse, MSGBOX_SIGN
    end


@ =============================================================================
@ COMPATIBILITY HOUSE-SIGN LABELS
@ =============================================================================

LittlerootTown_EventScript_PlayersHouseSignMale:
    msgbox LittlerootTown_Text_PlayersHouse, MSGBOX_DEFAULT
    return


LittlerootTown_EventScript_PlayersHouseSignFemale:
    msgbox LittlerootTown_Text_PlayersHouse, MSGBOX_DEFAULT
    return


LittlerootTown_EventScript_BirchsHouseSignMale:
    msgbox LittlerootTown_Text_NeighborHouse, MSGBOX_DEFAULT
    return


LittlerootTown_EventScript_BirchsHouseSignFemale:
    msgbox LittlerootTown_Text_NeighborHouse, MSGBOX_DEFAULT
    return


@ =============================================================================
@ FAT MAN TEXT
@ =============================================================================

LittlerootTown_Text_FatManNormal:
    .string "It's a peaceful little town.\p"
    .string "Still, it pays to look around.\n"
    .string "You never know what you'll find.$"


LittlerootTown_Text_FatManBookClue:
    .string "An important book?\p"
    .string "I did see a child hurrying past\n"
    .string "with one earlier...\p"
    .string "She headed toward the trees on\n"
    .string "the far side of town.$"


LittlerootTown_Text_FatManRepeatClue:
    .string "The child I saw went toward the\n"
    .string "trees on the far side of town.$"


LittlerootTown_Text_FatManRestaurantReminder:
    .string "So the book was lost near the\n"
    .string "restaurant?\p"
    .string "I'd ask around over there.$"


LittlerootTown_Text_FatManAfterQuest:
    .string "Sounds like everything worked\n"
    .string "out in the end.\p"
    .string "I'm glad to hear it.$"


@ =============================================================================
@ OLDER BROTHER TEXT
@ =============================================================================

LittlerootTown_Text_BrotherNormal:
    .string "My little sister is always\n"
    .string "running off somewhere.\p"
    .string "I can barely keep up with her.$"


LittlerootTown_Text_BrotherBeforeClue:
    .string "You look like you're searching\n"
    .string "for something.\p"
    .string "Maybe someone else in town saw\n"
    .string "where it went.$"


LittlerootTown_Text_BrotherBookClue:
    .string "I haven't seen a book myself...\p"
    .string "But my little sister was running\n"
    .string "around with one earlier.\p"
    .string "She seemed upset when she came\n"
    .string "back this way.$"


LittlerootTown_Text_BrotherRepeatClue:
    .string "My sister sometimes hides behind\n"
    .string "the trees when she's upset.$"


LittlerootTown_Text_BrotherAfterQuest:
    .string "Thanks for helping my sister.\p"
    .string "She makes mistakes, but she has\n"
    .string "a good heart.$"


@ =============================================================================
@ LITTLE GIRL TEXT — BEFORE CONFESSION
@ =============================================================================

LittlerootTown_Text_LittleGirlBeforeQuest:
    .string "The trees are quieter back here.\p"
    .string "Sometimes I come here when I\n"
    .string "want to be alone.$"


LittlerootTown_Text_LittleGirlCrying:
    .string "Sniff...\p"
    .string "Please...\n"
    .string "I don't want to talk right now.$"


LittlerootTown_Text_PlayerAsksAboutBook:
    .string "Did you take BLAINE'S book?$"


@ =============================================================================
@ LITTLE GIRL CONFESSION
@ =============================================================================

LittlerootTown_Text_LittleGirlConfession:
    .string "I...I only wanted to look at it.\p"
    .string "BLAINE said it was important,\n"
    .string "so I knew I shouldn't touch it.\p"
    .string "But I took it anyway...\p"
    .string "Someone bumped into me while I\n"
    .string "was carrying it.\p"
    .string "I dropped it, and when I went\n"
    .string "back...it was gone.$"


@ =============================================================================
@ COMPASSION RESPONSE
@ =============================================================================

LittlerootTown_Text_PlayerComfortsGirl:
    .string "It's okay.\n"
    .string "We'll fix it together.$"


LittlerootTown_Text_LittleGirlComforted:
    .string "You...you'll help me?\p"
    .string "Thank you...\n"
    .string "I was so scared.$"


@ =============================================================================
@ ACCOUNTABILITY RESPONSE
@ =============================================================================

LittlerootTown_Text_PlayerHoldsGirlAccountable:
    .string "You need to tell BLAINE what\n"
    .string "happened.$"


LittlerootTown_Text_LittleGirlAcceptsResponsibility:
    .string "I know...\p"
    .string "I was afraid he'd be angry.\p"
    .string "But I'll tell him the truth once\n"
    .string "we find the book.$"


@ =============================================================================
@ INVESTIGATION RESPONSE
@ =============================================================================

LittlerootTown_Text_PlayerAsksForLocation:
    .string "Where did you last have the\n"
    .string "book?$"


@ =============================================================================
@ SHARED RESTAURANT CLUE
@ =============================================================================

LittlerootTown_Text_LittleGirlExplainsLocation:
    .string "It happened near the restaurant.\p"
    .string "Someone bumped into me beside\n"
    .string "the delivery crates.\p"
    .string "When I turned around, the book\n"
    .string "was gone.$"


LittlerootTown_Text_LittleGirlGoToRestaurant:
    .string "Maybe somebody there found it...\p"
    .string "Please, will you help me look?$"


@ =============================================================================
@ LITTLE GIRL LATER DIALOGUE
@ =============================================================================

LittlerootTown_Text_LittleGirlRestaurantSearch:
    .string "The restaurant is just ahead.\p"
    .string "I really hope the book is still\n"
    .string "somewhere nearby.$"


LittlerootTown_Text_LittleGirlBookRecovered:
    .string "You found it!\p"
    .string "Now I have to tell BLAINE the\n"
    .string "truth about what I did.$"


LittlerootTown_Text_LittleGirlAfterQuest:
    .string "Thank you for helping me.\p"
    .string "Next time, I'll ask before I\n"
    .string "borrow something important.$"


LittlerootTown_Text_LittleGirlNormal:
    .string "Sniff...\n"
    .string "I didn't mean for any of this.$"


@ =============================================================================
@ ROUTE BLOCKER TEXT
@ =============================================================================

LittlerootTown_Text_ExploreTownFirst:
    .string "You should explore LITTLEROOT\n"
    .string "before beginning your journey.\p"
    .string "The library would be a good\n"
    .string "place to start.$"


@ =============================================================================
@ SIGNS
@ =============================================================================

LittlerootTown_Text_TownSign:
    .string "LITTLEROOT TOWN\n"
    .string "Where every journey takes root.$"


LittlerootTown_Text_ProfBirchsLab:
    .string "PROF. BIRCH'S POKéMON LAB$"


LittlerootTown_Text_PlayersHouse:
    .string "{PLAYER}'s HOUSE$"


LittlerootTown_Text_NeighborHouse:
    .string "A cozy LITTLEROOT home.$"


@ =============================================================================
@ DEX-UPGRADE TEXT
@ =============================================================================

LittlerootTown_Text_BirchSomethingToShowYouAtLab:
    .string "PROF. BIRCH: Ah, {PLAYER}!\p"
    .string "I have something important to\n"
    .string "show you at the LAB.\p"
    .string "Come with me.$"


LittlerootTown_EventScript_GiveRunningShoesTrigger2::
    goto LittlerootTown_EventScript_NeedPokemonTriggerLeft

LittlerootTown_EventScript_GiveRunningShoesTrigger3::
    goto LittlerootTown_EventScript_NeedPokemonTriggerLeft

LittlerootTown_EventScript_GiveRunningShoesTrigger4::
    goto LittlerootTown_EventScript_NeedPokemonTriggerRight

LittlerootTown_EventScript_GiveRunningShoesTrigger5::
    goto LittlerootTown_EventScript_NeedPokemonTriggerRight