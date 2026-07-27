Town_Library_MapScripts::
    .byte 0


@ =============================================================================
@ LIBRARY INTRO
@
@ VAR_LIBRARY_BOOK_QUEST
@   0 = Quest has not started
@   1 = Searching for Blaine's missing book
@   2 = Book found / return to Blaine      (future)
@   3 = Book returned                      (future)
@   4 = Deliver cookbook to restaurant     (future)
@   5 = Quest complete                     (future)
@
@ Both entrance coordinate triggers should use:
@   Town_Library_EventScript_EntranceScene
@ =============================================================================

Town_Library_EventScript_EntranceLeft::
    goto_if_set FLAG_LIBRARY_INTRO_COMPLETE, Town_Library_EventScript_EntranceDone

    lockall

    @ Shift onto the shared center route.
    applymovement OBJ_EVENT_ID_PLAYER, Town_Library_Movement_LeftEntranceAlign
    waitmovement 0

    goto Town_Library_EventScript_EntranceScene_Main


Town_Library_EventScript_EntranceRight::
    goto_if_set FLAG_LIBRARY_INTRO_COMPLETE, Town_Library_EventScript_EntranceDone

    lockall

    @ Shift onto the shared center route.
    applymovement OBJ_EVENT_ID_PLAYER, Town_Library_Movement_RightEntranceAlign
    waitmovement 0

    goto Town_Library_EventScript_EntranceScene_Main

Town_Library_EventScript_EntranceScene_Main:
    compare VAR_LIBRARY_BOOK_QUEST, 0
    goto_if_ne Town_Library_EventScript_EntranceScene_AlreadyStarted

    goto_if_set FLAG_HIDE_HOME_MOM, Town_Library_EventScript_BlaineMentionsElias

Town_Library_EventScript_BlaineMentionsTia:
    msgbox Town_Library_Text_BlaineTooYoungTia, MSGBOX_DEFAULT
    goto Town_Library_EventScript_ParentAnswersBlaine

Town_Library_EventScript_BlaineMentionsElias:
    msgbox Town_Library_Text_BlaineTooYoungElias, MSGBOX_DEFAULT

Town_Library_EventScript_ParentAnswersBlaine:
    msgbox Town_Library_Text_ParentSituationDire, MSGBOX_DEFAULT

    goto_if_set FLAG_HIDE_HOME_MOM, Town_Library_EventScript_DadCallsPlayer


Town_Library_EventScript_MomCallsPlayer:
    msgbox Town_Library_Text_MomCallsPlayer, MSGBOX_DEFAULT
    goto Town_Library_EventScript_ApproachParent


Town_Library_EventScript_DadCallsPlayer:
    msgbox Town_Library_Text_DadCallsPlayer, MSGBOX_DEFAULT


Town_Library_EventScript_ApproachParent:
    applymovement OBJ_EVENT_ID_PLAYER, Town_Library_Movement_PlayerApproachParent
    waitmovement 0

    call Town_Library_EventScript_FacePlayer
    delay 12

    goto_if_set FLAG_HIDE_HOME_MOM, Town_Library_EventScript_DadIntroduction


Town_Library_EventScript_MomIntroduction:
    msgbox Town_Library_Text_MomIntroduction, MSGBOX_DEFAULT
    goto Town_Library_EventScript_ChooseResponse


Town_Library_EventScript_DadIntroduction:
    msgbox Town_Library_Text_DadIntroduction, MSGBOX_DEFAULT
    goto Town_Library_EventScript_ChooseResponse




@ =============================================================================
@ PLAYER'S FIRST VIRTUE CHOICE
@ =============================================================================

Town_Library_EventScript_ChooseResponse:
    multichoice 0, 0, MULTICHOICE_LIBRARY_HELP_BLAINE, FALSE

    switch VAR_RESULT
    case 0, Town_Library_EventScript_ResponseOfCourse
    case 1, Town_Library_EventScript_ResponseIGuess
    case 2, Town_Library_EventScript_ResponseNoThanks

    goto Town_Library_EventScript_ResponseNoThanks


Town_Library_EventScript_ResponseOfCourse:
    addvar VAR_COMPASSION, 1

    goto_if_set FLAG_HIDE_HOME_MOM, Town_Library_EventScript_DadGreat

    msgbox Town_Library_Text_MomGreat, MSGBOX_DEFAULT
    goto Town_Library_EventScript_BlaineExplainsQuest

Town_Library_EventScript_DadGreat:
    msgbox Town_Library_Text_DadGreat, MSGBOX_DEFAULT
    goto Town_Library_EventScript_BlaineExplainsQuest


Town_Library_EventScript_ResponseIGuess:
    addvar VAR_PERSPECTIVE, 1

    goto_if_set FLAG_HIDE_HOME_MOM, Town_Library_EventScript_DadEncourages

    msgbox Town_Library_Text_MomEncourages, MSGBOX_DEFAULT
    goto Town_Library_EventScript_BlaineExplainsQuest

Town_Library_EventScript_DadEncourages:
    msgbox Town_Library_Text_DadEncourages, MSGBOX_DEFAULT
    goto Town_Library_EventScript_BlaineExplainsQuest


Town_Library_EventScript_ResponseNoThanks:
    goto_if_set FLAG_HIDE_HOME_MOM, Town_Library_EventScript_DadRefusesRefusal

    msgbox Town_Library_Text_MomRefusesRefusal, MSGBOX_DEFAULT
    goto Town_Library_EventScript_BlaineExplainsQuest

Town_Library_EventScript_DadRefusesRefusal:
    msgbox Town_Library_Text_DadRefusesRefusal, MSGBOX_DEFAULT
    goto Town_Library_EventScript_BlaineExplainsQuest


@ =============================================================================
@ QUEST BEGINS
@ =============================================================================

Town_Library_EventScript_BlaineExplainsQuest:
    applymovement OBJ_EVENT_ID_PLAYER, Town_Library_Movement_PlayerApproachBlaine
    waitmovement 0

    applymovement LOCALID_LIBRARY_BLAINE, Town_Library_Movement_BlaineFacePlayer
    waitmovement 0

    msgbox Town_Library_Text_BlaineBookMissing, MSGBOX_DEFAULT
    msgbox Town_Library_Text_BlaineSearchTown, MSGBOX_DEFAULT

    setvar VAR_LIBRARY_BOOK_QUEST, 1
    setflag FLAG_LIBRARY_INTRO_COMPLETE

    releaseall
    end



@ Safety branch in case the quest variable was changed before the intro flag.
Town_Library_EventScript_EntranceScene_AlreadyStarted:
    setflag FLAG_LIBRARY_INTRO_COMPLETE
    releaseall
    end

Town_Library_EventScript_EntranceDone:
    end


@ =============================================================================
@ CUTSCENE FACING HELPERS
@ =============================================================================

Town_Library_EventScript_FacePlayer:
    applymovement LOCALID_LIBRARY_BLAINE, Town_Library_Movement_BlaineFacePlayer

    goto_if_set FLAG_HIDE_HOME_MOM, Town_Library_EventScript_FaceDad
    goto Town_Library_EventScript_FaceMom

Town_Library_EventScript_FaceMom:
    applymovement LOCALID_LIBRARY_MOM, Town_Library_Movement_ParentFacePlayer
    waitmovement 0
    return

Town_Library_EventScript_FaceDad:
    applymovement LOCALID_LIBRARY_DAD, Town_Library_Movement_ParentFacePlayer
    waitmovement 0
    return

Town_Library_Movement_LeftEntranceAlign:
    walk_left
    walk_left
    step_end

Town_Library_Movement_RightEntranceAlign:
    step_end

Town_Library_Movement_PlayerApproachBlaine:
    walk_left
    walk_left
    face_up
    step_end



@ =============================================================================
@ PARENT INTERACTION
@
@ Assign this script to both Mom and Dad in Porymap:
@   Town_Library_EventScript_Parent
@ =============================================================================

Town_Library_EventScript_Parent::
    lock

    compare VAR_LIBRARY_BOOK_QUEST, 1
    goto_if_eq Town_Library_EventScript_ParentQuestReminder

    msgbox Town_Library_Text_ParentNormal, MSGBOX_NPC
    release
    end

Town_Library_EventScript_ParentQuestReminder:
    msgbox Town_Library_Text_ParentQuestReminder, MSGBOX_NPC
    release
    end


@ =============================================================================
@ BLAINE INTERACTION
@
@ Assign this script to Blaine in Porymap:
@   Town_Library_EventScript_Blaine
@ =============================================================================

Town_Library_EventScript_Blaine::
    lock

    compare VAR_LIBRARY_BOOK_QUEST, 0
    goto_if_eq Town_Library_EventScript_BlaineBeforeQuest

    compare VAR_LIBRARY_BOOK_QUEST, 1
    goto_if_eq Town_Library_EventScript_BlaineSearching

    @ Temporary fallback until book-return states are written.
    msgbox Town_Library_Text_BlaineSearching, MSGBOX_NPC
    release
    end

Town_Library_EventScript_BlaineBeforeQuest:
    msgbox Town_Library_Text_BlaineBeforeQuest, MSGBOX_NPC
    release
    end

Town_Library_EventScript_BlaineSearching:
    msgbox Town_Library_Text_BlaineSearching, MSGBOX_NPC
    release
    end


@ =============================================================================
@ GRUNT BOOK CLUB
@
@ Put this same script on all reasonable approach triggers:
@   Town_Library_EventScript_GruntConversation
@
@ These Local ID names should be generated by Porymap:
@   LOCALID_LIBRARY_AQUA_GRUNT
@   LOCALID_LIBRARY_MAGMA_GRUNT
@ =============================================================================

Town_Library_EventScript_GruntConversation::
    lockall

    compare VAR_LIBRARY_BOOK_QUEST, 1
    goto_if_ne Town_Library_EventScript_GruntConversation_End

    goto_if_set FLAG_LIBRARY_GRUNTS_HEARD, Town_Library_EventScript_GruntConversation_End

    @ The player initially overhears the grunts talking to one another.
    msgbox Town_Library_Text_GruntBookClubOpening, MSGBOX_DEFAULT
    setflag FLAG_LIBRARY_GRUNTS_HEARD

    yesnobox 20, 8
    compare VAR_RESULT, YES
    goto_if_eq Town_Library_EventScript_SitWithGrunts

    goto Town_Library_EventScript_QuestionGruntsDirectly


Town_Library_EventScript_QuestionGruntsDirectly:
    applymovement OBJ_EVENT_ID_PLAYER, Town_Library_Movement_PlayerFaceTable
    applymovement LOCALID_LIBRARY_AQUA_GRUNT, Town_Library_Movement_AquaFacePlayer
    applymovement LOCALID_LIBRARY_MAGMA_GRUNT, Town_Library_Movement_MagmaFacePlayer
    waitmovement 0

    msgbox Town_Library_Text_AskGruntsDirectly, MSGBOX_DEFAULT
    msgbox Town_Library_Text_GruntsDefendThemselves, MSGBOX_DEFAULT

    releaseall
    end


Town_Library_EventScript_SitWithGrunts:
    addvar VAR_PERSPECTIVE, 1
    setflag FLAG_LIBRARY_SAT_WITH_GRUNTS

    applymovement OBJ_EVENT_ID_PLAYER, Town_Library_Movement_PlayerFaceTable
    applymovement LOCALID_LIBRARY_AQUA_GRUNT, Town_Library_Movement_AquaFacePlayer
    applymovement LOCALID_LIBRARY_MAGMA_GRUNT, Town_Library_Movement_MagmaFacePlayer
    waitmovement 0

    msgbox Town_Library_Text_GruntBookClubDetails, MSGBOX_DEFAULT
    msgbox Town_Library_Text_AskGruntsPolitely, MSGBOX_DEFAULT
    msgbox Town_Library_Text_GruntsDefendThemselves, MSGBOX_DEFAULT

    releaseall
    end


Town_Library_EventScript_GruntConversation_End:
    releaseall
    end


@ =============================================================================
@ MANIAC
@
@ Assign in Porymap:
@   Town_Library_EventScript_Maniac
@ =============================================================================

Town_Library_EventScript_Maniac::
    lock

    compare VAR_LIBRARY_BOOK_QUEST, 1
    goto_if_ne Town_Library_EventScript_ManiacNormal

    msgbox Town_Library_Text_AskManiac, MSGBOX_DEFAULT
    msgbox Town_Library_Text_ManiacQuestion, MSGBOX_NPC

    setflag FLAG_LIBRARY_QUESTIONED_MANIAC
    release
    end

Town_Library_EventScript_ManiacNormal:
    msgbox Town_Library_Text_ManiacNormal, MSGBOX_NPC
    release
    end


@ =============================================================================
@ GENTLEMAN
@
@ Assign in Porymap:
@   Town_Library_EventScript_Gentleman
@ =============================================================================

Town_Library_EventScript_Gentleman::
    lock

    compare VAR_LIBRARY_BOOK_QUEST, 1
    goto_if_ne Town_Library_EventScript_GentlemanNormal

    msgbox Town_Library_Text_AskGentleman, MSGBOX_DEFAULT
    msgbox Town_Library_Text_GentlemanClue, MSGBOX_NPC

    setflag FLAG_LIBRARY_GENTLEMAN_CLUE
    release
    end

Town_Library_EventScript_GentlemanNormal:
    msgbox Town_Library_Text_GentlemanNormal, MSGBOX_NPC
    release
    end


@ =============================================================================
@ MOVEMENTS
@ =============================================================================

Town_Library_Movement_PlayerApproachParent:
    walk_up
    walk_up
    walk_left
    walk_left
    face_left
    step_end

Town_Library_Movement_ParentFacePlayer:
    face_right
    step_end

Town_Library_Movement_BlaineFacePlayer:
    face_down
    step_end

Town_Library_Movement_PlayerFaceTable:
    face_up
    step_end

Town_Library_Movement_AquaFacePlayer:
    face_down
    step_end

Town_Library_Movement_MagmaFacePlayer:
    face_down
    step_end

Town_Library_Movement_PlayerFaceBlaine:
    face_up
    step_end


@ =============================================================================
@ INTRO TEXT
@ =============================================================================

Town_Library_Text_BlaineTooYoungTia:
    .string "...They may be too young to know\n"
    .string "about that, Tia.$"

Town_Library_Text_BlaineTooYoungElias:
    .string "...They may be too young to know\n"
    .string "about that, Elias.$"

Town_Library_Text_ParentSituationDire:
    .string "Yes, Blaine, I know, but...\p"
    .string "The situation is dire.$"

Town_Library_Text_MomCallsPlayer:
    .string "{PLAYER}!$"

Town_Library_Text_DadCallsPlayer:
    .string "{PLAYER}!$"

Town_Library_Text_MomIntroduction:
    .string "Your Uncle Blaine has something\n"
    .string "he needs you to do for him.\p"
    .string "You'll help him, won't you?$"

Town_Library_Text_DadIntroduction:
    .string "Your Uncle Blaine needs your\n"
    .string "help with something.\p"
    .string "You'll help him, right?$"

Town_Library_Text_MomGreat:
    .string "Great!\p"
    .string "Blaine, tell {PLAYER} the details.$"

Town_Library_Text_DadGreat:
    .string "That's what I like to hear!\p"
    .string "Blaine, tell {PLAYER} what you\n"
    .string "need.$"

Town_Library_Text_MomEncourages:
    .string "C'mon! It'll be fun!\p"
    .string "Blaine, tell {PLAYER} the details.$"

Town_Library_Text_DadEncourages:
    .string "That's good enough for me.\p"
    .string "Go ahead, Blaine.$"

Town_Library_Text_MomRefusesRefusal:
    .string "Sorry, sweetie, but you can't get\n"
    .string "out of this one.$"

Town_Library_Text_DadRefusesRefusal:
    .string "Nice try, but this isn't optional.$"

Town_Library_Text_BlaineBookMissing:
    .string "A very important book has gone\n"
    .string "missing from my library.\p"
    .string "I know it hasn't left town, but I\n"
    .string "don't know who has it.$"

Town_Library_Text_BlaineSearchTown:
    .string "Speak with the people here and\n"
    .string "look around Littleroot.\p"
    .string "Bring the book back to me when\n"
    .string "you find it.$"


@ =============================================================================
@ REPEAT INTERACTION TEXT
@ =============================================================================

Town_Library_Text_ParentQuestReminder:
    .string "Make sure you come back once\n"
    .string "you find Uncle Blaine's book.$"

Town_Library_Text_ParentNormal:
    .string "Uncle Blaine has always loved\n"
    .string "this library.$"

Town_Library_Text_BlaineSearching:
    .string "Knowledge has a way of turning\n"
    .string "up in unexpected places.\p"
    .string "Talk to everyone in town, and\n"
    .string "come back when you've found it.$"

Town_Library_Text_BlaineBeforeQuest:
    .string "Give your parent and me just\n"
    .string "a moment, {PLAYER}.$"


@ =============================================================================
@ GRUNT TEXT
@ =============================================================================

Town_Library_Text_GruntBookClubOpening:
    .string "AQUA GRUNT: People really think\n"
    .string "gang members can't read.\p"
    .string "MAGMA GRUNT: Offensive,\n"
    .string "honestly.\p"
    .string "AQUA GRUNT: I finished three\n"
    .string "books this week.\p"
    .string "Sit with them?$"

Town_Library_Text_GruntBookClubDetails:
    .string "They excitedly explain that they\n"
    .string "meet here every week.\p"
    .string "Their book club is currently\n"
    .string "debating villains.\p"
    .string "Today, they're arguing over who\n"
    .string "had the better motive.$"

Town_Library_Text_AskGruntsPolitely:
    .string "You eventually ask whether they\n"
    .string "have seen Blaine's missing book.$"

Town_Library_Text_AskGruntsDirectly:
    .string "You ask whether they stole\n"
    .string "Blaine's missing book.$"

Town_Library_Text_GruntsDefendThemselves:
    .string "MAGMA GRUNT: Wow. Low-hanging\n"
    .string "fruit.\p"
    .string "AQUA GRUNT: But I guess we should\n"
    .string "have expected that.\p"
    .string "MAGMA GRUNT: We would never steal\n"
    .string "from Mr. Blaine!\p"
    .string "AQUA GRUNT: He's one of the only\n"
    .string "people who doesn't judge us.\p"
    .string "We'd never do anything to upset\n"
    .string "him.$"


@ =============================================================================
@ MANIAC TEXT
@ =============================================================================

Town_Library_Text_AskManiac:
    .string "{PLAYER}: Did you take one of\n"
    .string "Uncle Blaine's books?$"

Town_Library_Text_ManiacQuestion:
    .string "Did I steal a book?\p"
    .string "...\p"
    .string "...\p"
    .string "Maybe.\p"
    .string "Wait. Which book?\p"
    .string "No. Leave me alone.$"

Town_Library_Text_ManiacNormal:
    .string "I'm trying to concentrate.$"


@ =============================================================================
@ GENTLEMAN TEXT
@ =============================================================================

Town_Library_Text_AskGentleman:
    .string "{PLAYER}: Did you take one of\n"
    .string "Uncle Blaine's books?$"

Town_Library_Text_GentlemanClue:
    .string "No, child. Stealing is hardly\n"
    .string "gentlemanly.\p"
    .string "Though a true gentleman observes\n"
    .string "before he accuses.\p"
    .string "I happened to see a distressed\n"
    .string "young girl near the trees outside.$"

Town_Library_Text_GentlemanNormal:
    .string "A good library demands good\n"
    .string "manners.$"
    
