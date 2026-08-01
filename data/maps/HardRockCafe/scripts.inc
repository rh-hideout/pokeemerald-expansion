HardRockCafe_MapScripts::
    map_script MAP_SCRIPT_ON_LOAD, HardRockCafe_SetCounterpartGraphics
    .byte 0

@ Temporary map-specific object ID.
@ Hard Rock Cafe counterpart is object event 5.
#define LOCALID_HARD_ROCK_COUNTERPART 5

@ ============================================================================
@ Dynamic counterpart graphics + Blaine setup
@ ============================================================================

HardRockCafe_SetCounterpartGraphics:
    goto_if_eq VAR_COUNTERPART_ID, COUNTERPART_BRENDAN, HardRockCafe_SetBrendan
    goto_if_eq VAR_COUNTERPART_ID, COUNTERPART_MAY, HardRockCafe_SetMay
    goto_if_eq VAR_COUNTERPART_ID, COUNTERPART_LEXY, HardRockCafe_SetLexy
    goto_if_eq VAR_COUNTERPART_ID, COUNTERPART_JUSTIN, HardRockCafe_SetJustin
    goto_if_eq VAR_COUNTERPART_ID, COUNTERPART_MAAM, HardRockCafe_SetMaam
    goto_if_eq VAR_COUNTERPART_ID, COUNTERPART_SIR, HardRockCafe_SetSir
    goto HardRockCafe_FinishMapLoad

HardRockCafe_SetBrendan:
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_BRENDAN_NORMAL
    goto HardRockCafe_FinishMapLoad

HardRockCafe_SetMay:
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_MAY_NORMAL
    goto HardRockCafe_FinishMapLoad

HardRockCafe_SetLexy:
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_LEXY_NORMAL
    goto HardRockCafe_FinishMapLoad

HardRockCafe_SetJustin:
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_JUSTIN_NORMAL
    goto HardRockCafe_FinishMapLoad

HardRockCafe_SetMaam:
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_MAAM_NORMAL
    goto HardRockCafe_FinishMapLoad

HardRockCafe_SetSir:
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SIR_NORMAL
    goto HardRockCafe_FinishMapLoad

HardRockCafe_FinishMapLoad:
    @ Keep Blaine invisible whenever the restaurant loads.
    @ Replace MAP_HARD_ROCK_CAFE if your generated map constant differs.
    end

@ ============================================================================
@ First counterpart encounter
@ ============================================================================

HardRockCafe_Counterpart::
    lock
    faceplayer

    getplayerxy VAR_TEMP_0, VAR_TEMP_1

    goto_if_eq VAR_TEMP_0, 8, HardRockCafe_CheckCorrectY
    goto HardRockCafe_CounterpartWrongSide

HardRockCafe_CheckCorrectY:
    goto_if_eq VAR_TEMP_1, 15, HardRockCafe_CounterpartSceneStart
    goto HardRockCafe_CounterpartWrongSide

HardRockCafe_CounterpartWrongSide:
    msgbox HardRockCafe_Text_WrongSide, MSGBOX_DEFAULT
    release
    end

HardRockCafe_CounterpartSceneStart:
    applymovement LOCALID_PLAYER, HardRockCafe_Movement_PlayerFaceCounterpart
    applymovement LOCALID_HARD_ROCK_COUNTERPART, HardRockCafe_Movement_CounterpartFacePlayer
    waitmovement 0

    checkflag FLAG_COUNTERPART_BOOK_SCENE_DONE
    goto_if TRUE, HardRockCafe_CounterpartAfterQuest

    special UpdateRelationship

    goto_if_eq VAR_COUNTERPART_RELATIONSHIP, RELATIONSHIP_COMPANION, HardRockCafe_OpeningCompanion
    goto_if_eq VAR_COUNTERPART_RELATIONSHIP, RELATIONSHIP_MENTOR, HardRockCafe_OpeningMentor
    goto_if_eq VAR_COUNTERPART_RELATIONSHIP, RELATIONSHIP_RIVAL, HardRockCafe_OpeningRival
    goto_if_eq VAR_COUNTERPART_RELATIONSHIP, RELATIONSHIP_FOIL, HardRockCafe_OpeningFoil

    goto HardRockCafe_OpeningUnknown


HardRockCafe_Text_WrongSide:
    .string "Wait! Come around to this side.\n"
    .string "I want to show you something.$"

HardRockCafe_OpeningCompanion:
    msgbox HardRockCafe_Text_OpeningCompanion, MSGBOX_DEFAULT
    goto HardRockCafe_BookChoice

HardRockCafe_OpeningMentor:
    msgbox HardRockCafe_Text_OpeningMentor, MSGBOX_DEFAULT
    goto HardRockCafe_BookChoice

HardRockCafe_OpeningRival:
    msgbox HardRockCafe_Text_OpeningRival, MSGBOX_DEFAULT
    goto HardRockCafe_BookChoice

HardRockCafe_OpeningFoil:
    msgbox HardRockCafe_Text_OpeningFoil, MSGBOX_DEFAULT
    goto HardRockCafe_BookChoice

HardRockCafe_OpeningUnknown:
    msgbox HardRockCafe_Text_OpeningUnknown, MSGBOX_DEFAULT
    goto HardRockCafe_BookChoice


    

@ ============================================================================
@ Player response
@ ============================================================================

HardRockCafe_BookChoice:
    msgbox HardRockCafe_Text_ChooseResponse, MSGBOX_DEFAULT
    multichoice 0, 0, MULTICHOICE_COUNTERPART_BOOK_RESPONSE, TRUE

    goto_if_eq VAR_RESULT, 0, HardRockCafe_ChooseCompassion
    goto_if_eq VAR_RESULT, 1, HardRockCafe_ChooseCuriosity
    goto_if_eq VAR_RESULT, 2, HardRockCafe_ChooseResolve
    goto_if_eq VAR_RESULT, 3, HardRockCafe_ChooseIndependence

    goto HardRockCafe_ChooseCompassion

HardRockCafe_ChooseCompassion:
    addvar VAR_COMPASSION, 1
    addvar VAR_PERSPECTIVE, 1
    msgbox HardRockCafe_Text_ChoiceCompassionReply, MSGBOX_DEFAULT
    goto HardRockCafe_FinalizeRelationship

HardRockCafe_ChooseCuriosity:
    addvar VAR_CURIOSITY, 1
    addvar VAR_WISDOM, 1
    msgbox HardRockCafe_Text_ChoiceCuriosityReply, MSGBOX_DEFAULT
    goto HardRockCafe_FinalizeRelationship

HardRockCafe_ChooseResolve:
    addvar VAR_RESOLVE, 1
    msgbox HardRockCafe_Text_ChoiceResolveReply, MSGBOX_DEFAULT
    goto HardRockCafe_FinalizeRelationship

HardRockCafe_ChooseIndependence:
    addvar VAR_INDEPENDENCE, 1
    msgbox HardRockCafe_Text_ChoiceIndependenceReply, MSGBOX_DEFAULT
    goto HardRockCafe_FinalizeRelationship

@ ============================================================================
@ Final relationship
@ ============================================================================

HardRockCafe_FinalizeRelationship:
    special FinalizeCounterpartRelationship

    goto_if_eq VAR_COUNTERPART_RELATIONSHIP, RELATIONSHIP_COMPANION, HardRockCafe_FinalCompanion
    goto_if_eq VAR_COUNTERPART_RELATIONSHIP, RELATIONSHIP_MENTOR, HardRockCafe_FinalMentor
    goto_if_eq VAR_COUNTERPART_RELATIONSHIP, RELATIONSHIP_RIVAL, HardRockCafe_FinalRival
    goto_if_eq VAR_COUNTERPART_RELATIONSHIP, RELATIONSHIP_FOIL, HardRockCafe_FinalFoil

    goto HardRockCafe_FinalCompanion

HardRockCafe_FinalCompanion:
    goto HardRockCafe_BrockReveal

HardRockCafe_FinalMentor:
    goto HardRockCafe_BrockReveal

HardRockCafe_FinalRival:
    goto HardRockCafe_BrockReveal

HardRockCafe_FinalFoil:
    goto HardRockCafe_BrockReveal


    @ Continue your existing relationship branches here.


@ ============================================================================
@ Brock reveals that the missing book is a cookbook
@ ============================================================================

HardRockCafe_BrockReveal:
    @ Brock calls out first.
    msgbox HardRockCafe_Text_BrockCallsOut, MSGBOX_DEFAULT

    @ Player and counterpart turn toward him.
    applymovement LOCALID_PLAYER, HardRockCafe_Movement_PlayerLooksAtBrock
    applymovement LOCALID_HARD_ROCK_COUNTERPART, HardRockCafe_Movement_CounterpartLooksAtBrock
    waitmovement 0

    delay 20

    @ They walk toward Brock together.
    applymovement LOCALID_PLAYER, HardRockCafe_Movement_PlayerApproachesBrock
    applymovement LOCALID_HARD_ROCK_COUNTERPART, HardRockCafe_Movement_CounterpartApproachesBrock
    waitmovement 0

    @ Brock turns toward them.
    applymovement LOCALID_BROCK, HardRockCafe_Movement_BrockFacesPair
    waitmovement LOCALID_BROCK

    delay 15

    @ Cookbook reveal and shared shock.
    msgbox HardRockCafe_Text_BrockRecognizesBook, MSGBOX_DEFAULT
    msgbox HardRockCafe_Text_PlayerCookbookShock, MSGBOX_DEFAULT
    delay 20
    msgbox HardRockCafe_Text_CounterpartCookbookShock, MSGBOX_DEFAULT
    msgbox HardRockCafe_Text_BrockExplains, MSGBOX_DEFAULT

    @ Now branch into the counterpart's role-specific response.
    goto_if_eq VAR_COUNTERPART_RELATIONSHIP, RELATIONSHIP_COMPANION, HardRockCafe_BrockResponseCompanion
    goto_if_eq VAR_COUNTERPART_RELATIONSHIP, RELATIONSHIP_MENTOR, HardRockCafe_BrockResponseMentor
    goto_if_eq VAR_COUNTERPART_RELATIONSHIP, RELATIONSHIP_RIVAL, HardRockCafe_BrockResponseRival
    goto_if_eq VAR_COUNTERPART_RELATIONSHIP, RELATIONSHIP_FOIL, HardRockCafe_BrockResponseFoil

    goto HardRockCafe_BrockResponseUnknown


HardRockCafe_BrockResponseCompanion:
    msgbox HardRockCafe_Text_BrockResponseCompanion, MSGBOX_DEFAULT
    goto HardRockCafe_BrockInvitation

HardRockCafe_BrockResponseMentor:
    msgbox HardRockCafe_Text_BrockResponseMentor, MSGBOX_DEFAULT
    goto HardRockCafe_BrockInvitation

HardRockCafe_BrockResponseRival:
    msgbox HardRockCafe_Text_BrockResponseRival, MSGBOX_DEFAULT
    goto HardRockCafe_BrockInvitation

HardRockCafe_BrockResponseFoil:
    msgbox HardRockCafe_Text_BrockResponseFoil, MSGBOX_DEFAULT
    goto HardRockCafe_BrockInvitation

HardRockCafe_BrockResponseUnknown:
    msgbox HardRockCafe_Text_BrockResponseUnknown, MSGBOX_DEFAULT
    goto HardRockCafe_BrockInvitation

HardRockCafe_BrockInvitation:
    msgbox HardRockCafe_Text_BrockInvitation, MSGBOX_DEFAULT
    goto HardRockCafe_BlaineArrival

HardRockCafe_FinishBookScene:
    setflag FLAG_LIBRARY_BOOK_MISSION_COMPLETE
    setflag FLAG_COUNTERPART_BOOK_SCENE_DONE
    setflag FLAG_COUNTERPART_HOME_INVITE

    @ Add the library quest stage here when ready.
    setvar VAR_LIBRARY_BOOK_QUEST, 2

    release
    end


HardRockCafe_Movement_PlayerLooksAtBrock:
    face_up
    step_end

HardRockCafe_Movement_CounterpartLooksAtBrock:
    face_up
    step_end

HardRockCafe_Movement_PlayerApproachesBrock:
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    walk_right
    walk_right
    face_up
    step_end

HardRockCafe_Movement_CounterpartApproachesBrock:
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    walk_right
    walk_right
    face_up
    step_end

HardRockCafe_Movement_BrockFacesPair:
    face_down
    step_end

@ ============================================================================
@ Repeat dialogue
@ ============================================================================

HardRockCafe_CounterpartAfterQuest:
    msgbox HardRockCafe_Text_AfterQuest, MSGBOX_DEFAULT
    release
    end


@ ============================================================================
@ Restaurant NPC dialogue
@ ============================================================================

HardRockCafe_Brock::
    lock
    faceplayer
    checkflag FLAG_COUNTERPART_BOOK_SCENE_DONE
    goto_if TRUE, HardRockCafe_BrockAfterReveal
    msgbox HardRockCafe_Text_BrockBeforeReveal, MSGBOX_DEFAULT
    release
    end

HardRockCafe_BrockAfterReveal:
    msgbox HardRockCafe_Text_BrockAfterReveal, MSGBOX_DEFAULT
    release
    end

HardRockCafe_Maxie::
    lock
    faceplayer
    msgbox HardRockCafe_Text_Maxie, MSGBOX_DEFAULT
    release
    end

HardRockCafe_MaxieNiece::
    lock
    msgbox HardRockCafe_Text_MaxieNiece, MSGBOX_DEFAULT
    release
    end

HardRockCafe_PancakeDiner::
    lock
    faceplayer
    msgbox HardRockCafe_Text_PancakeDiner, MSGBOX_DEFAULT
    release
    end

HardRockCafe_PancakeChef::
    lock
    faceplayer
    msgbox HardRockCafe_Text_PancakeChef, MSGBOX_DEFAULT
    release
    end

HardRockCafe_MaxieChef::
    lock
    faceplayer
    msgbox HardRockCafe_Text_MaxieChef, MSGBOX_DEFAULT
    release
    end

HardRockCafe_Chansey::
    lock
    faceplayer
    msgbox HardRockCafe_Text_Chansey, MSGBOX_DEFAULT
    release
    end
@ ============================================================================
@ Dialogue text
@ ============================================================================

HardRockCafe_Text_OpeningCompanion:
    .string "Hey! You're helping that girl from\n"
    .string "the library too, right?\p"
    .string "I found this outside.\n"
    .string "I was about to return it.$"

HardRockCafe_Text_OpeningMentor:
    .string "You're searching for the missing\n"
    .string "library book, aren't you?\p"
    .string "I found it near the path outside.\n"
    .string "The damaged cover gave it away.$"

HardRockCafe_Text_OpeningRival:
    .string "Looking for this?\p"
    .string "I figured someone else would find\n"
    .string "it eventually.\p"
    .string "I didn't expect it to take this long.$"

HardRockCafe_Text_OpeningFoil:
    .string "This book belongs to the library.\p"
    .string "Apparently everyone has decided\n"
    .string "that losing it is a catastrophe.$"

HardRockCafe_Text_OpeningUnknown:
    .string "Are you looking for this book?\p"
    .string "I found it outside and thought it\n"
    .string "might belong to the library.$"

HardRockCafe_Text_ChooseResponse:
    .string "How do you respond?$"

HardRockCafe_Text_FinalCompanion:
    .string "No problem!\p"
    .string "We should take it back together.\n"
    .string "She looked really worried.$"

HardRockCafe_Text_FinalMentor:
    .string "I can show you exactly where I\n"
    .string "found it on the way back.\p"
    .string "It may help explain how it got there.$"

HardRockCafe_Text_FinalRival:
    .string "Sure you would have.\p"
    .string "Come on, then. Let's see which one\n"
    .string "of us gets it back first.$"

HardRockCafe_Text_FinalFoil:
    .string "I don't. Not especially.\p"
    .string "But keeping something that isn't\n"
    .string "mine would be pointless.\p"
    .string "You can lead the way.$"

HardRockCafe_Text_AfterQuest:
    .string "We should return that book before\n"
    .string "she worries herself sick.$"

HardRockCafe_Text_BrockCallsOut:
    .string "Hey!\p"
    .string "You two are getting pretty loud\n"
    .string "in my restaurant!$"

HardRockCafe_Text_BrockRecognizesBook:
    .string "Wait...\p"
    .string "Is that the cookbook I...\n"
    .string "That Blaine!\p"
    .string "how on brand.\p"
    .string "Tell him I said thanks, kiddos!$"

HardRockCafe_Text_BrockExplains:
    .string "Um...yes?\p"
    .string "Without that book, I cannot make\n"
    .string "my famous Pewter Rock Roast!\p"
    .string "I only make it once every year,\n"
    .string "and I am preparing the ingredients.$"

HardRockCafe_Text_BrockResponseCompanion:
    .string "Well, at least we found it in time!\p"
    .string "I would have felt awful if everyone\n"
    .string "missed out because it was lost.$"

HardRockCafe_Text_BrockResponseMentor:
    .string "So the urgency was justified...\n"
    .string "just not for the reason we expected.\p"
    .string "I would like to see what makes the\n"
    .string "recipe so important.$"

HardRockCafe_Text_BrockResponseRival:
    .string "All of that for one recipe?\p"
    .string "This had better be the greatest\n"
    .string "meal anyone has ever tasted.$"

HardRockCafe_Text_BrockResponseFoil:
    .string "A town wide panic over dinner.\p"
    .string "Somehow, that makes less sense\n"
    .string "than what I was imagining.$"

HardRockCafe_Text_BrockResponseUnknown:
    .string "I definitely was not expecting\n"
    .string "this to be about food.$"

HardRockCafe_Text_BrockInvitation:
    .string "Come back after earning your\n"
    .string "third Badge!\p"
    .string "The roast should be ready by then.\n"
    .string "You both helped, so you both eat!$"

HardRockCafe_Text_BrockBeforeReveal:
    .string "Welcome!\p"
    .string "Try not to distract the chefs.\n"
    .string "Today is already busy enough.$"

HardRockCafe_Text_BrockAfterReveal:
    .string "Third Badge, remember!\p"
    .string "Do not make me eat the entire\n"
    .string "Pewter Rock Roast by myself.$"

HardRockCafe_Text_Maxie:
    .string "WHAT?!\p"
    .string "Because I lead Team Magma, I cannot\n"
    .string "enjoy a meal with my niece?\p"
    .string "Typical!\n"
    .string "Gang leaders have to eat too!$"

HardRockCafe_Text_MaxieNiece:
    .string "Uncle...\p"
    .string "Nobody said anything.\n"
    .string "It is not that serious.$"

HardRockCafe_Text_PancakeDiner:
    .string "Ahhh...pancakes.\p"
    .string "One of life's greatest joys.$"

HardRockCafe_Text_PancakeChef:
    .string "Every time I make pancakes,\n"
    .string "I start wanting pancakes.\p"
    .string "I wish I were off right now.$"

HardRockCafe_Text_MaxieChef:
    .string "Shrimp tempura...\n"
    .string "Spicy tuna roll...\p"
    .string "Do not mess this up.\n"
    .string "Do not mess this up.\p"
    .string "It is MAXIE.$"

HardRockCafe_Text_Chansey:
    .string "Chansey!$"

HardRockCafe_Text_ChoiceCompassionReply:
    .string "No problem.\p"
    .string "She looked really worried, so I\n"
    .string "figured I should bring it back.$"

HardRockCafe_Text_ChoiceCuriosityReply:
    .string "Near the path outside.\p"
    .string "The cover was damaged, so I knew\n"
    .string "it probably belonged to someone.$"

HardRockCafe_Text_ChoiceResolveReply:
    .string "Sure you would have.\p"
    .string "Next time, try finding it before\n"
    .string "someone else does.$"

HardRockCafe_Text_ChoiceIndependenceReply:
    .string "I don't. Not especially.\p"
    .string "But keeping something that isn't\n"
    .string "mine would be pointless.$"

HardRockCafe_Text_PlayerCookbookShock:
    .string "A...cookbook?!$"

HardRockCafe_Text_CounterpartCookbookShock:
    .string "Wait.\p"
    .string "Everyone was panicking...\n"
    .string "over a cookbook?!$"

HardRockCafe_BlaineArrival:
    clearflag FLAG_HIDE_HARD_ROCK_BLAINE
    addobject LOCALID_BLAINE
    delay 10

    applymovement LOCALID_BLAINE, HardRockCafe_Movement_BlaineApproaches
    waitmovement LOCALID_BLAINE

    @ Blaine begins speaking, so both characters turn toward him.
    applymovement LOCALID_PLAYER, HardRockCafe_Movement_PlayerFaceBlaine
    applymovement LOCALID_HARD_ROCK_COUNTERPART, HardRockCafe_Movement_CounterpartFaceBlaine
    waitmovement 0

    msgbox HardRockCafe_Text_BlainePraise, MSGBOX_DEFAULT

    @ The player turns back to the counterpart for the levitation aside.
    applymovement LOCALID_PLAYER, HardRockCafe_Movement_PlayerFaceCounterpart
    applymovement LOCALID_HARD_ROCK_COUNTERPART, HardRockCafe_Movement_CounterpartFacePlayer
    waitmovement 0

    msgbox HardRockCafe_Text_PlayerNoticesLevitation, MSGBOX_DEFAULT

    goto_if_eq VAR_COUNTERPART_RELATIONSHIP, RELATIONSHIP_COMPANION, HardRockCafe_LevitationCompanion
    goto_if_eq VAR_COUNTERPART_RELATIONSHIP, RELATIONSHIP_MENTOR, HardRockCafe_LevitationMentor
    goto_if_eq VAR_COUNTERPART_RELATIONSHIP, RELATIONSHIP_RIVAL, HardRockCafe_LevitationRival
    goto_if_eq VAR_COUNTERPART_RELATIONSHIP, RELATIONSHIP_FOIL, HardRockCafe_LevitationFoil
    goto HardRockCafe_LevitationUnknown


HardRockCafe_BlaineResponseCompanion:
    msgbox HardRockCafe_Text_BlaineResponseCompanion, MSGBOX_DEFAULT
    goto HardRockCafe_BlaineRewardInstruction

HardRockCafe_BlaineResponseMentor:
    msgbox HardRockCafe_Text_BlaineResponseMentor, MSGBOX_DEFAULT
    goto HardRockCafe_BlaineRewardInstruction

HardRockCafe_BlaineResponseRival:
    msgbox HardRockCafe_Text_BlaineResponseRival, MSGBOX_DEFAULT
    goto HardRockCafe_BlaineRewardInstruction

HardRockCafe_BlaineResponseFoil:
    msgbox HardRockCafe_Text_BlaineResponseFoil, MSGBOX_DEFAULT
    goto HardRockCafe_BlaineRewardInstruction

HardRockCafe_BlaineResponseUnknown:
    msgbox HardRockCafe_Text_BlaineResponseUnknown, MSGBOX_DEFAULT
    goto HardRockCafe_BlaineRewardInstruction

HardRockCafe_LevitationCompanion:
    msgbox HardRockCafe_Text_LevitationCompanion, MSGBOX_DEFAULT
    goto HardRockCafe_BlaineContinues

HardRockCafe_LevitationMentor:
    msgbox HardRockCafe_Text_LevitationMentor, MSGBOX_DEFAULT
    goto HardRockCafe_BlaineContinues

HardRockCafe_LevitationRival:
    msgbox HardRockCafe_Text_LevitationRival, MSGBOX_DEFAULT
    goto HardRockCafe_BlaineContinues

HardRockCafe_LevitationFoil:
    msgbox HardRockCafe_Text_LevitationFoil, MSGBOX_DEFAULT
    goto HardRockCafe_BlaineContinues

HardRockCafe_LevitationUnknown:
    msgbox HardRockCafe_Text_LevitationUnknown, MSGBOX_DEFAULT
    goto HardRockCafe_BlaineContinues


HardRockCafe_BlaineContinues:
    @ The aside is over; both turn back to Blaine so he can continue.
    applymovement LOCALID_PLAYER, HardRockCafe_Movement_PlayerFaceBlaine
    applymovement LOCALID_HARD_ROCK_COUNTERPART, HardRockCafe_Movement_CounterpartFaceBlaine
    waitmovement 0

    msgbox HardRockCafe_Text_BlaineRecognizesCounterpart, MSGBOX_DEFAULT

    goto_if_eq VAR_COUNTERPART_RELATIONSHIP, RELATIONSHIP_COMPANION, HardRockCafe_BlaineResponseCompanion
    goto_if_eq VAR_COUNTERPART_RELATIONSHIP, RELATIONSHIP_MENTOR, HardRockCafe_BlaineResponseMentor
    goto_if_eq VAR_COUNTERPART_RELATIONSHIP, RELATIONSHIP_RIVAL, HardRockCafe_BlaineResponseRival
    goto_if_eq VAR_COUNTERPART_RELATIONSHIP, RELATIONSHIP_FOIL, HardRockCafe_BlaineResponseFoil
    goto HardRockCafe_BlaineResponseUnknown

HardRockCafe_BlaineRewardInstruction:
    msgbox HardRockCafe_Text_BlaineRewardInstruction, MSGBOX_DEFAULT

    @ The counterpart realizes this is the player's first day,
    @ so they turn toward one another again.
    applymovement LOCALID_PLAYER, HardRockCafe_Movement_PlayerFaceCounterpart
    applymovement LOCALID_HARD_ROCK_COUNTERPART, HardRockCafe_Movement_CounterpartFacePlayer
    waitmovement 0

    msgbox HardRockCafe_Text_CounterpartLearnsName, MSGBOX_DEFAULT
    msgbox HardRockCafe_Text_CounterpartInvitation, MSGBOX_DEFAULT

    @ Both turn back toward Blaine for his exit line.
    applymovement LOCALID_PLAYER, HardRockCafe_Movement_PlayerFaceBlaine
    applymovement LOCALID_HARD_ROCK_COUNTERPART, HardRockCafe_Movement_CounterpartFaceBlaine
    waitmovement 0

    msgbox HardRockCafe_Text_BlaineLeaves, MSGBOX_DEFAULT

    applymovement LOCALID_BLAINE, HardRockCafe_Movement_BlaineLeaves
    waitmovement LOCALID_BLAINE
    removeobject LOCALID_BLAINE
    setflag FLAG_HIDE_HARD_ROCK_BLAINE

    goto HardRockCafe_FinishBookScene

@ Adjust these steps to match Blaine's off-camera Porymap position.
HardRockCafe_Movement_BlaineApproaches:
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    face_down
    step_end

@ Exact reverse of the approach.
HardRockCafe_Movement_BlaineLeaves:
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    step_end

HardRockCafe_Movement_PlayerFaceBlaine:
    face_up
    step_end

HardRockCafe_Movement_CounterpartFaceBlaine:
    face_up
    step_end

HardRockCafe_Movement_PlayerFaceCounterpart:
    @ Player stands at (8, 15), to the right of the counterpart.
    face_left
    step_end

HardRockCafe_Movement_CounterpartFacePlayer:
    @ Counterpart stands at (7, 15), to the left of the player.
    face_right
    step_end

HardRockCafe_Text_BlainePraise:
    .string "There you are, {PLAYER}!\p"
    .string "Excellent work finding that very\n"
    .string "important book.$"

HardRockCafe_Text_BlaineRecognizesCounterpart:
    .string "Wait...\p"
    .string "What is Oak's grandchild doing\n"
    .string "here?\p"
    .string "I thought you preferred keeping\n"
    .string "to yourself.$"

HardRockCafe_Text_BlaineResponseCompanion:
    .string "I found the book and decided to\n"
    .string "help return it.\p"
    .string "That is not strange.$"

HardRockCafe_Text_BlaineResponseMentor:
    .string "I was curious how it ended up\n"
    .string "outside.\p"
    .string "Helping was simply efficient.$"

HardRockCafe_Text_BlaineResponseRival:
    .string "I found it before {PLAYER} did.\p"
    .string "Someone had to finish the search.$"

HardRockCafe_Text_BlaineResponseFoil:
    .string "I was eating.\p"
    .string "They happened to interrupt me.$"

HardRockCafe_Text_BlaineResponseUnknown:
    .string "It is a long story.$"

HardRockCafe_Text_BlaineRewardInstruction:
    .string "In any case, come back to the\n"
    .string "library when you're ready.\p"
    .string "You've earned a reward.$"

HardRockCafe_Text_BlaineLeaves:
    .string "Meet me back at the library.\n"
    .string "Your gift will be waiting.$"

HardRockCafe_Text_CounterpartLearnsName:
    .string "Wait. You're {PLAYER}?\p"
    .string "Oh...\n"
    .string "So this really is your first day.$"

HardRockCafe_Text_CounterpartInvitation:
    .string "That explains a lot.\p"
    .string "If you feel like it, meet me at\n"
    .string "home later.\p"
    .string "I'll lead you to Gramps so you can\n"
    .string "get your first Pokemon.$"

HardRockCafe_Text_PlayerNoticesLevitation:
    .string "Did he just...\n"
    .string "levitate over here?$"

HardRockCafe_Text_LevitationCompanion:
    .string "I think so.\p"
    .string "Well...he is a scientist.$"

HardRockCafe_Text_LevitationMentor:
    .string "Apparently.\p"
    .string "I would ask how, but I doubt we'd\n"
    .string "understand the explanation.$"

HardRockCafe_Text_LevitationRival:
    .string "Don't look so impressed.\p"
    .string "You can probably learn that after\n"
    .string "your second badge.$"

HardRockCafe_Text_LevitationFoil:
    .string "Yes.\p"
    .string "And somehow that isn't the strangest\n"
    .string "thing that's happened today.$"

HardRockCafe_Text_LevitationUnknown:
    .string "He is a scientist.\p"
    .string "Maybe they can just do that.$"
