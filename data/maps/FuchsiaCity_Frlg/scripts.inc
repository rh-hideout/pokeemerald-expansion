FuchsiaCity_Frlg_MapScripts::
    map_script MAP_SCRIPT_ON_LOAD, FuchsiaCity_Frlg_OnLoad
    map_script MAP_SCRIPT_ON_FRAME_TABLE, FuchsiaCity_Frlg_OnFrame
    .byte 0


FuchsiaCity_Frlg_OnLoad:
    call FuchsiaCity_Frlg_SetCounterpartGraphics

    @ Gary only belongs on this map during the arrival state.
    compare VAR_BROCK_INGREDIENT_QUEST, 6
    goto_if_eq FuchsiaCity_Frlg_OnLoad_End

    setflag FLAG_HIDE_FUCHSIA_GARY
    removeobject LOCALID_FUCHSIA_GARY

FuchsiaCity_Frlg_OnLoad_End:
    end


FuchsiaCity_Frlg_OnFrame:
    map_script_2 VAR_BROCK_INGREDIENT_QUEST, 6, FuchsiaCity_Frlg_EventScript_Arrival
    .2byte 0


@ ============================================================
@ DYNAMIC COUNTERPART GRAPHICS
@ ============================================================

FuchsiaCity_Frlg_SetCounterpartGraphics:
    goto_if_eq VAR_COUNTERPART_ID, COUNTERPART_BRENDAN, FuchsiaCity_Frlg_SetBrendan
    goto_if_eq VAR_COUNTERPART_ID, COUNTERPART_MAY, FuchsiaCity_Frlg_SetMay
    goto_if_eq VAR_COUNTERPART_ID, COUNTERPART_LEXY, FuchsiaCity_Frlg_SetLexy
    goto_if_eq VAR_COUNTERPART_ID, COUNTERPART_JUSTIN, FuchsiaCity_Frlg_SetJustin
    goto_if_eq VAR_COUNTERPART_ID, COUNTERPART_MAAM, FuchsiaCity_Frlg_SetMaam
    goto_if_eq VAR_COUNTERPART_ID, COUNTERPART_SIR, FuchsiaCity_Frlg_SetSir

    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_BRENDAN_NORMAL
    return


FuchsiaCity_Frlg_SetBrendan:
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_BRENDAN_NORMAL
    return

FuchsiaCity_Frlg_SetMay:
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_MAY_NORMAL
    return

FuchsiaCity_Frlg_SetLexy:
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_LEXY_NORMAL
    return

FuchsiaCity_Frlg_SetJustin:
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_JUSTIN_NORMAL
    return

FuchsiaCity_Frlg_SetMaam:
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_MAAM_NORMAL
    return

FuchsiaCity_Frlg_SetSir:
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SIR_NORMAL
    return


@ ============================================================
@ ARRIVAL
@ ============================================================

FuchsiaCity_Frlg_EventScript_Arrival::
    compare VAR_BROCK_INGREDIENT_QUEST, 6
    goto_if_ne FuchsiaCity_Frlg_EventScript_Arrival_End

    lockall

    @ We have just arrived with Gary.
    applymovement LOCALID_PLAYER, Common_Movement_FaceRight
    applymovement LOCALID_FUCHSIA_COUNTERPART, Common_Movement_FaceRight
    applymovement LOCALID_FUCHSIA_GARY, Common_Movement_FaceLeft
    waitmovement 0

    msgbox FuchsiaCity_Frlg_Text_GaryArrivalOutro1, MSGBOX_DEFAULT
    closemessage

    @ Counterpart answers Gary.
    applymovement LOCALID_FUCHSIA_GARY, Common_Movement_FaceDown
    applymovement LOCALID_FUCHSIA_COUNTERPART, Common_Movement_FaceUp
    waitmovement 0

    msgbox FuchsiaCity_Frlg_Text_GaryArrivalOutro2, MSGBOX_DEFAULT
    closemessage

    @ Player thanks Gary; Gary turns back toward the player.
    applymovement LOCALID_FUCHSIA_GARY, Common_Movement_FaceLeft
    applymovement LOCALID_PLAYER, Common_Movement_FaceRight
    waitmovement 0

    msgbox FuchsiaCity_Frlg_Text_GaryArrivalOutro3, MSGBOX_DEFAULT
    closemessage

    @ Gary exits toward the east edge of town.
    applymovement LOCALID_FUCHSIA_GARY, FuchsiaCity_Frlg_Movement_GaryLeaves
    waitmovement 0

    @ He is DONE done.
    setflag FLAG_HIDE_FUCHSIA_GARY
    removeobject LOCALID_FUCHSIA_GARY

    @ Fuchsia investigation is now active.
    setvar VAR_BROCK_INGREDIENT_QUEST, 7

    @ Counterpart turns toward the direction we need to travel.
    applymovement LOCALID_FUCHSIA_COUNTERPART, Common_Movement_FaceLeft
    applymovement LOCALID_PLAYER, Common_Movement_FaceLeft
    waitmovement 0

    releaseall
    end

FuchsiaCity_Frlg_EventScript_Arrival_End:
    end


FuchsiaCity_Frlg_EventScript_GaryArrival::
    lock
    faceplayer
    msgbox FuchsiaCity_Frlg_Text_GaryArrivalRepeat, MSGBOX_DEFAULT
    release
    end


FuchsiaCity_Frlg_Text_GaryArrivalOutro1:
    .string "GARY: FUCHSIA CITY.\p"
    .string "Try not to get lost.$"

FuchsiaCity_Frlg_Text_GaryArrivalOutro2:
    .string "{RIVAL}: We didn't ask for a tour.\p"
    .string "GARY: Good.\n"
    .string "I'm not giving one.$"

FuchsiaCity_Frlg_Text_GaryArrivalOutro3:
    .string "{PLAYER}: Thanks for the ride.\p"
    .string "GARY: Yeah, yeah.\p"
    .string "Try not to need another favor.$"


FuchsiaCity_Frlg_Text_GaryArrivalRepeat:
    .string "GARY: What?\p"
    .string "You're here.\n"
    .string "My job is done.$"


FuchsiaCity_Frlg_Movement_GaryLeaves:
    walk_right
    walk_right
    walk_right
    walk_right
    step_end


@ ============================================================
@ PLACEHOLDERS FOR PART 2
@ ============================================================

FuchsiaCity_Frlg_EventScript_Koga::
    lock
    faceplayer

    compare VAR_BROCK_INGREDIENT_QUEST, 7
    goto_if_eq FuchsiaCity_Frlg_EventScript_KogaRoadIntro

    compare VAR_BROCK_INGREDIENT_QUEST, 8
    goto_if_eq FuchsiaCity_Frlg_EventScript_KogaChallengeRepeat

    msgbox FuchsiaCity_Frlg_Text_KogaFallback, MSGBOX_DEFAULT
    release
    end


FuchsiaCity_Frlg_EventScript_KogaRoadIntro::
    lockall

    @ Counterpart realizes the player got ahead.
    msgbox FuchsiaCity_Frlg_Text_CounterpartCatchUp, MSGBOX_DEFAULT
    closemessage

    @ She runs in from the right and catches up below the player.
    setobjectxyperm LOCALID_FUCHSIA_COUNTERPART, 40, 22
    setobjectxy LOCALID_FUCHSIA_COUNTERPART, 40, 22

    applymovement LOCALID_FUCHSIA_COUNTERPART, FuchsiaCity_Frlg_Movement_CounterpartRoadJoin
    waitmovement 0

    @ Both initially look down the road toward Koga.
    applymovement LOCALID_PLAYER, Common_Movement_FaceLeft
    applymovement LOCALID_FUCHSIA_COUNTERPART, Common_Movement_FaceLeft
    applymovement LOCALID_FUCHSIA_KOGA, Common_Movement_FaceRight
    waitmovement 0

    @ Rival spots him from a distance.
    msgbox FuchsiaCity_Frlg_Text_KogaSpotting, MSGBOX_DEFAULT
    closemessage

    @ Player and counterpart turn toward each other.
    applymovement LOCALID_PLAYER, Common_Movement_FaceDown
    applymovement LOCALID_FUCHSIA_COUNTERPART, Common_Movement_FaceUp
    waitmovement 0

    msgbox FuchsiaCity_Frlg_Text_KogaWhoIsHe, MSGBOX_DEFAULT
    closemessage

    @ Look back at Koga for the "important" observation.
    applymovement LOCALID_PLAYER, Common_Movement_FaceLeft
    applymovement LOCALID_FUCHSIA_COUNTERPART, Common_Movement_FaceLeft
    waitmovement 0

    msgbox FuchsiaCity_Frlg_Text_KogaLooksImportant, MSGBOX_DEFAULT
    closemessage

    @ Back to each other for the argument.
    applymovement LOCALID_PLAYER, Common_Movement_FaceDown
    applymovement LOCALID_FUCHSIA_COUNTERPART, Common_Movement_FaceUp
    waitmovement 0

    msgbox FuchsiaCity_Frlg_Text_KogaIntro2, MSGBOX_DEFAULT
    closemessage

    @ Both look back toward him.
    applymovement LOCALID_PLAYER, Common_Movement_FaceLeft
    applymovement LOCALID_FUCHSIA_COUNTERPART, Common_Movement_FaceLeft
    waitmovement 0

    @ Koga is STILL down the road when he says this.
    msgbox FuchsiaCity_Frlg_Text_KogaCanHearYou, MSGBOX_DEFAULT
    closemessage

    @ ...well. He heard us.
    @ NOW everybody closes the distance.
    applymovement LOCALID_PLAYER, FuchsiaCity_Frlg_Movement_ApproachKoga
    applymovement LOCALID_FUCHSIA_COUNTERPART, FuchsiaCity_Frlg_Movement_ApproachKoga
    applymovement LOCALID_FUCHSIA_KOGA, FuchsiaCity_Frlg_Movement_KogaApproaches
    waitmovement 0

    @ Preserve the story actors' new positions.
    setobjectxyperm LOCALID_FUCHSIA_COUNTERPART, 35, 22
    setobjectxyperm LOCALID_FUCHSIA_KOGA, 33, 21

    @ Rival talks to player.
    applymovement LOCALID_FUCHSIA_COUNTERPART, Common_Movement_FaceUp
    applymovement LOCALID_PLAYER, Common_Movement_FaceDown
    waitmovement 0

    msgbox FuchsiaCity_Frlg_Text_KogaIntro3, MSGBOX_DEFAULT
    closemessage

    @ Koga addresses the pair.
    applymovement LOCALID_FUCHSIA_KOGA, Common_Movement_FaceRight
    applymovement LOCALID_PLAYER, Common_Movement_FaceLeft
    applymovement LOCALID_FUCHSIA_COUNTERPART, Common_Movement_FaceLeft
    waitmovement 0

    msgbox FuchsiaCity_Frlg_Text_KogaLoreleiReveal_Koga1, MSGBOX_DEFAULT
    closemessage

    @ Rival answers Koga.
    applymovement LOCALID_FUCHSIA_COUNTERPART, Common_Movement_FaceLeft
    applymovement LOCALID_FUCHSIA_KOGA, Common_Movement_FaceRight
    waitmovement 0

    msgbox FuchsiaCity_Frlg_Text_KogaLoreleiReveal_Rival1, MSGBOX_DEFAULT
    closemessage

    @ Koga immediately names Lorelei.
    msgbox FuchsiaCity_Frlg_Text_KogaLoreleiReveal_Koga2, MSGBOX_DEFAULT
    closemessage

    @ Player and rival react to one another.
    applymovement LOCALID_PLAYER, Common_Movement_FaceDown
    applymovement LOCALID_FUCHSIA_COUNTERPART, Common_Movement_FaceUp
    waitmovement 0

    msgbox FuchsiaCity_Frlg_Text_KogaLoreleiReveal_Reaction, MSGBOX_DEFAULT
    closemessage

    @ Back to Koga.
    applymovement LOCALID_PLAYER, Common_Movement_FaceLeft
    applymovement LOCALID_FUCHSIA_COUNTERPART, Common_Movement_FaceLeft
    applymovement LOCALID_FUCHSIA_KOGA, Common_Movement_FaceRight
    waitmovement 0

    msgbox FuchsiaCity_Frlg_Text_KogaWorthiness_Koga1, MSGBOX_DEFAULT
    closemessage

    @ Rival makes the case.
    msgbox FuchsiaCity_Frlg_Text_KogaWorthiness_Rival, MSGBOX_DEFAULT
    closemessage

    @ Koga is unmoved.
    msgbox FuchsiaCity_Frlg_Text_KogaWorthiness_Koga2, MSGBOX_DEFAULT
    closemessage

    @ Koga lays down the challenge.
    msgbox FuchsiaCity_Frlg_Text_KogaChallenge_Koga1, MSGBOX_DEFAULT
    closemessage

    @ Rival checks that he means both of them.
    applymovement LOCALID_FUCHSIA_COUNTERPART, Common_Movement_FaceLeft
    applymovement LOCALID_FUCHSIA_KOGA, Common_Movement_FaceRight
    waitmovement 0

    msgbox FuchsiaCity_Frlg_Text_KogaChallenge_Rival1, MSGBOX_DEFAULT
    closemessage

    msgbox FuchsiaCity_Frlg_Text_KogaChallenge_Koga2, MSGBOX_DEFAULT
    closemessage

    @ Rival immediately rejects the solo option.
    msgbox FuchsiaCity_Frlg_Text_KogaChallenge_Rival2, MSGBOX_DEFAULT
    closemessage

    @ Player turns to stare at rival.
    applymovement LOCALID_PLAYER, Common_Movement_FaceDown
    applymovement LOCALID_FUCHSIA_COUNTERPART, Common_Movement_FaceUp
    waitmovement 0

    msgbox FuchsiaCity_Frlg_Text_KogaChallenge_Player, MSGBOX_DEFAULT
    closemessage

    msgbox FuchsiaCity_Frlg_Text_KogaChallenge_Rival3, MSGBOX_DEFAULT
    closemessage

    @ Face Koga again for the actual battle prompt.
    applymovement LOCALID_PLAYER, Common_Movement_FaceLeft
    applymovement LOCALID_FUCHSIA_COUNTERPART, Common_Movement_FaceLeft
    applymovement LOCALID_FUCHSIA_KOGA, Common_Movement_FaceRight
    waitmovement 0

    setvar VAR_BROCK_INGREDIENT_QUEST, 8

    goto FuchsiaCity_Frlg_EventScript_KogaReadyPrompt


FuchsiaCity_Frlg_EventScript_KogaChallengeRepeat:
    msgbox FuchsiaCity_Frlg_Text_KogaChallengeRepeat, MSGBOX_DEFAULT
    closemessage

FuchsiaCity_Frlg_EventScript_KogaReadyPrompt:
    msgbox FuchsiaCity_Frlg_Text_KogaReady, MSGBOX_YESNO
    compare VAR_RESULT, NO
    goto_if_eq FuchsiaCity_Frlg_EventScript_KogaNotReady

    @ Route to the correct dynamic counterpart battle partner.
    goto_if_eq VAR_COUNTERPART_ID, COUNTERPART_BRENDAN, FuchsiaCity_Frlg_EventScript_KogaBattleBrendan
    goto_if_eq VAR_COUNTERPART_ID, COUNTERPART_MAY, FuchsiaCity_Frlg_EventScript_KogaBattleMay
    goto_if_eq VAR_COUNTERPART_ID, COUNTERPART_LEXY, FuchsiaCity_Frlg_EventScript_KogaBattleLexy
    goto_if_eq VAR_COUNTERPART_ID, COUNTERPART_JUSTIN, FuchsiaCity_Frlg_EventScript_KogaBattleJustin
    goto_if_eq VAR_COUNTERPART_ID, COUNTERPART_MAAM, FuchsiaCity_Frlg_EventScript_KogaBattleMaam
    goto_if_eq VAR_COUNTERPART_ID, COUNTERPART_SIR, FuchsiaCity_Frlg_EventScript_KogaBattleSir

    @ Fail-safe fallback.
    goto FuchsiaCity_Frlg_EventScript_KogaBattleLexy


FuchsiaCity_Frlg_EventScript_KogaNotReady:
    msgbox FuchsiaCity_Frlg_Text_KogaNotReady, MSGBOX_DEFAULT
    closemessage
    releaseall
    end


@ ============================================================
@ KOGA 2-ON-1 PARTNER BATTLE
@ ============================================================

FuchsiaCity_Frlg_EventScript_KogaBattleBrendan:
    multi_2_vs_1 TRAINER_FUCHSIA_KOGA, FuchsiaCity_Frlg_Text_KogaDefeated, PARTNER_BRENDAN
    goto FuchsiaCity_Frlg_EventScript_KogaBattleResult

FuchsiaCity_Frlg_EventScript_KogaBattleMay:
    multi_2_vs_1 TRAINER_FUCHSIA_KOGA, FuchsiaCity_Frlg_Text_KogaDefeated, PARTNER_MAY
    goto FuchsiaCity_Frlg_EventScript_KogaBattleResult

FuchsiaCity_Frlg_EventScript_KogaBattleLexy:
    multi_2_vs_1 TRAINER_FUCHSIA_KOGA, FuchsiaCity_Frlg_Text_KogaDefeated, PARTNER_CELESTE
    goto FuchsiaCity_Frlg_EventScript_KogaBattleResult

FuchsiaCity_Frlg_EventScript_KogaBattleJustin:
    multi_2_vs_1 TRAINER_FUCHSIA_KOGA, FuchsiaCity_Frlg_Text_KogaDefeated, PARTNER_HIIRO
    goto FuchsiaCity_Frlg_EventScript_KogaBattleResult

FuchsiaCity_Frlg_EventScript_KogaBattleMaam:
    multi_2_vs_1 TRAINER_FUCHSIA_KOGA, FuchsiaCity_Frlg_Text_KogaDefeated, PARTNER_ALECIYA
    goto FuchsiaCity_Frlg_EventScript_KogaBattleResult

FuchsiaCity_Frlg_EventScript_KogaBattleSir:
    multi_2_vs_1 TRAINER_FUCHSIA_KOGA, FuchsiaCity_Frlg_Text_KogaDefeated, PARTNER_ASTER
    goto FuchsiaCity_Frlg_EventScript_KogaBattleResult


@ ============================================================
@ BATTLE RESULT
@
@ VAR_RESULT == 1: victory
@ Anything else: loss, but NO WHITEOUT.
@ ============================================================

FuchsiaCity_Frlg_EventScript_KogaBattleResult:
    switch VAR_RESULT
    case 1, FuchsiaCity_Frlg_EventScript_KogaBattleWon
    goto FuchsiaCity_Frlg_EventScript_KogaBattleLost


FuchsiaCity_Frlg_EventScript_KogaBattleWon:
    msgbox FuchsiaCity_Frlg_Text_KogaWinAftermath, MSGBOX_DEFAULT
    closemessage
    goto FuchsiaCity_Frlg_EventScript_KogaBattleResolved


FuchsiaCity_Frlg_EventScript_KogaBattleLost:
    msgbox FuchsiaCity_Frlg_Text_KogaLossAftermath, MSGBOX_DEFAULT
    closemessage
    goto FuchsiaCity_Frlg_EventScript_KogaBattleResolved


FuchsiaCity_Frlg_EventScript_KogaBattleResolved:
    setvar VAR_BROCK_INGREDIENT_QUEST, 9

    msgbox FuchsiaCity_Frlg_Text_KogaLoreleiInfo, MSGBOX_DEFAULT
    release
    end


FuchsiaCity_Frlg_EventScript_Counterpart::
    lock
    faceplayer

    compare VAR_BROCK_INGREDIENT_QUEST, 8
    goto_if_eq FuchsiaCity_Frlg_EventScript_Counterpart_WaitingForKoga

    @ TEMP DEV RESET:
    @ At state 9, clicking the counterpart replays the entire Fuchsia arrival.
    compare VAR_BROCK_INGREDIENT_QUEST, 9
    goto_if_eq FuchsiaCity_Frlg_EventScript_DevReset

    compare VAR_BROCK_INGREDIENT_QUEST, 7
    goto_if_eq FuchsiaCity_Frlg_EventScript_Counterpart_Searching

    msgbox FuchsiaCity_Frlg_Text_CounterpartFallback, MSGBOX_DEFAULT
    release
    end


FuchsiaCity_Frlg_EventScript_DevReset::
    clearflag FLAG_HIDE_FUCHSIA_GARY
    setvar VAR_BROCK_INGREDIENT_QUEST, 6
    warp MAP_FUCHSIA_CITY, 43, 21
    waitstate
    end

FuchsiaCity_Frlg_EventScript_Counterpart_Searching:
    msgbox FuchsiaCity_Frlg_Text_CounterpartSearching, MSGBOX_DEFAULT
    release
    end

FuchsiaCity_Frlg_EventScript_Counterpart_WaitingForKoga:
    msgbox FuchsiaCity_Frlg_Text_CounterpartWaitingForKoga, MSGBOX_DEFAULT
    release
    end


FuchsiaCity_Frlg_Movement_CounterpartRoadJoin:
    walk_fast_left
    walk_fast_left
    walk_fast_left
    face_left
    step_end


FuchsiaCity_Frlg_Movement_ApproachKoga:
    walk_left
    walk_left
    face_left
    step_end


FuchsiaCity_Frlg_Movement_KogaApproaches:
    walk_right
    walk_right
    face_right
    step_end


FuchsiaCity_Frlg_Text_CounterpartCatchUp:
    .string "{RIVAL}: Wait!\n"
    .string "Let me catch up!$"


FuchsiaCity_Frlg_Text_KogaSpotting:
    .string "{RIVAL}: OoOh...$"


FuchsiaCity_Frlg_Text_KogaWhoIsHe:
    .string "{PLAYER}: What?\p"
    .string "{RIVAL}: Who is HEeeee?\p"
    .string "{PLAYER}: I don't know.$"


FuchsiaCity_Frlg_Text_KogaLooksImportant:
    .string "{RIVAL}: He looks importantttt.\p"
    .string "We should ask him!$"


FuchsiaCity_Frlg_Text_KogaIntro2:
    .string "{PLAYER}: That's your criteria?\p"
    .string "{RIVAL}: Do YOU have a better lead?\p"
    .string "{PLAYER}: ...No.$"


FuchsiaCity_Frlg_Text_KogaCanHearYou:
    .string "KOGA: ...I can hear you.$"


FuchsiaCity_Frlg_Text_KogaIntro3:
    .string "{RIVAL}: See?\p"
    .string "{PLAYER}: How does that prove\n"
    .string "anything?\p"
    .string "{RIVAL}: It doesn't matter.\p"
    .string "We're already talking to him.$"


FuchsiaCity_Frlg_Text_KogaLoreleiReveal_Koga1:
    .string "KOGA: You wished to speak with me?$"


FuchsiaCity_Frlg_Text_KogaLoreleiReveal_Rival1:
    .string "{RIVAL}: We're looking for someone.$"


FuchsiaCity_Frlg_Text_KogaLoreleiReveal_Koga2:
    .string "KOGA: LORELEI.$"


FuchsiaCity_Frlg_Text_KogaLoreleiReveal_Reaction:
    .string "{PLAYER}: ...\p"
    .string "{RIVAL}: Okay, SEE?\n"
    .string "Important.$"


FuchsiaCity_Frlg_Text_KogaWorthiness_Koga1:
    .string "KOGA: You are asking me for the\n"
    .string "whereabouts of someone who clearly\n"
    .string "did not wish to be followed.\p"
    .string "Why should I tell you anything?$"


FuchsiaCity_Frlg_Text_KogaWorthiness_Rival:
    .string "{RIVAL}: Because we've been chasing\n"
    .string "this lead across two cities.$"


FuchsiaCity_Frlg_Text_KogaWorthiness_Koga2:
    .string "KOGA: That establishes persistence.\p"
    .string "Not worthiness.$"


FuchsiaCity_Frlg_Text_KogaChallenge_Koga1:
    .string "KOGA: You came together.\p"
    .string "Then together, prove that you are\n"
    .string "worth the answer.$"


FuchsiaCity_Frlg_Text_KogaChallenge_Rival1:
    .string "{RIVAL}: ...Both of us?$"


FuchsiaCity_Frlg_Text_KogaChallenge_Koga2:
    .string "KOGA: Unless you would prefer to\n"
    .string "face me alone.$"


FuchsiaCity_Frlg_Text_KogaChallenge_Rival2:
    .string "{RIVAL}: Nope.$"


FuchsiaCity_Frlg_Text_KogaChallenge_Player:
    .string "{PLAYER}: Wow.$"


FuchsiaCity_Frlg_Text_KogaChallenge_Rival3:
    .string "{RIVAL}: I know my limits.$"


FuchsiaCity_Frlg_Text_KogaChallengeRepeat:
    .string "KOGA: When you are ready,\n"
    .string "we will begin.$"

FuchsiaCity_Frlg_Text_KogaReady:
    .string "Are you ready?$"

FuchsiaCity_Frlg_Text_KogaNotReady:
    .string "KOGA: Very well.\p"
    .string "When you are ready,\n"
    .string "we will begin.$"


FuchsiaCity_Frlg_Text_KogaFallback:
    .string "KOGA: We have nothing further\n"
    .string "to discuss.$"


FuchsiaCity_Frlg_Text_CounterpartSearching:
    .string "{RIVAL}: Well...\n"
    .string "we're here.\p"
    .string "Let's see who looks like\n"
    .string "they know something.$"

FuchsiaCity_Frlg_Text_CounterpartWaitingForKoga:
    .string "{RIVAL}: I get it.\p"
    .string "Explore the town if you want.\p"
    .string "I'm staying here.\p"
    .string "Maybe I can figure out how\n"
    .string "we're supposed to win this.$"

FuchsiaCity_Frlg_Text_CounterpartFallback:
    .string "{RIVAL}: Come on.\n"
    .string "We've got work to do.$"


@ ============================================================
@ KOGA BATTLE / AFTERMATH TEXT
@ ============================================================

FuchsiaCity_Frlg_Text_KogaDefeated:
    .string "KOGA: ...Impressive.$"

FuchsiaCity_Frlg_Text_KogaWinAftermath:
    .string "KOGA: ...I underestimated you.\p"
    .string "Both of you.\p"
    .string "{RIVAL}: I'm choosing to hear that\n"
    .string "as an apology.\p"
    .string "KOGA: It was not.\p"
    .string "{RIVAL}: Of course it wasn't.$"

FuchsiaCity_Frlg_Text_KogaLossAftermath:
    .string "{RIVAL}: ...You alive?\p"
    .string "{PLAYER}: I think so.\p"
    .string "KOGA: You lasted longer than\n"
    .string "I expected.\p"
    .string "{RIVAL}: THAT was longer than\n"
    .string "you expected?!\p"
    .string "KOGA: Victory was not the only\n"
    .string "measure of this challenge.\p"
    .string "You stood your ground.\p"
    .string "You have convinced me.$"

FuchsiaCity_Frlg_Text_KogaLoreleiInfo:
    .string "KOGA: Very well.\p"
    .string "I will tell you what I know\n"
    .string "of LORELEI.\p"
    .string "She was here.\n"
    .string "Briefly.\p"
    .string "She left FUCHSIA some time ago.\p"
    .string "She was returning to\n"
    .string "PEWTER CITY.\p"
    .string "{RIVAL}: ...PEWTER?\p"
    .string "{PLAYER}: We were just there.\p"
    .string "{RIVAL}: Of course we were.\p"
    .string "KOGA: If you intend to follow her,\n"
    .string "I suggest you do so quickly.\p"
    .string "{RIVAL}: Great.\n"
    .string "Back to PEWTER.\p"
    .string "{PLAYER}: We're getting really good\n"
    .string "at going in circles.\p"
    .string "{RIVAL}: Don't make that a skill.$"


@ ============================================================
@ FUCHSIA RESIDENTS
@ ============================================================

FuchsiaCity_Frlg_EventScript_FatMan::
    lock
    faceplayer
    msgbox FuchsiaCity_Frlg_Text_FatMan, MSGBOX_DEFAULT
    release
    end


FuchsiaCity_Frlg_EventScript_Youngster::
    lock
    faceplayer
    msgbox FuchsiaCity_Frlg_Text_Youngster, MSGBOX_DEFAULT
    release
    end


FuchsiaCity_Frlg_EventScript_LittleBoy::
    lock
    faceplayer
    msgbox FuchsiaCity_Frlg_Text_LittleBoy, MSGBOX_DEFAULT
    release
    end


FuchsiaCity_Frlg_EventScript_BugCatcher::
    lock
    faceplayer
    msgbox FuchsiaCity_Frlg_Text_BugCatcher, MSGBOX_DEFAULT
    release
    end


FuchsiaCity_Frlg_EventScript_Lass::
    lock
    faceplayer
    msgbox FuchsiaCity_Frlg_Text_Lass, MSGBOX_DEFAULT
    release
    end


FuchsiaCity_Frlg_Text_FatMan:
    .string "Some people come to FUCHSIA for\n"
    .string "the SAFARI ZONE.\p"
    .string "Me? I like sitting here and\n"
    .string "watching everybody run around.$"


FuchsiaCity_Frlg_Text_Youngster:
    .string "Did you see the VOLTORB?!\p"
    .string "Everyone keeps telling me not to\n"
    .string "poke it.\p"
    .string "I wasn't going to!\p"
    .string "...Probably.$"


FuchsiaCity_Frlg_Text_LittleBoy:
    .string "I wanted to ride the LAPRAS.\p"
    .string "Apparently, “because it looks fun”\n"
    .string "isn't a good enough reason.$"


FuchsiaCity_Frlg_Text_BugCatcher:
    .string "People think I came here to look\n"
    .string "for rare BUG POKéMON.\p"
    .string "I did.\p"
    .string "Then I saw the KANGASKHAN.$"


FuchsiaCity_Frlg_Text_Lass:
    .string "FUCHSIA is weird.\p"
    .string "There are POKéMON everywhere,\n"
    .string "half the town smells like grass,\p"
    .string "and somehow it all works.$"
