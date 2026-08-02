LittlerootTown_BrendansHouse_1F_MapScripts::
    map_script MAP_SCRIPT_ON_LOAD, LittlerootTown_BrendansHouse_1F_SetCounterpartGraphics
    .byte 0


@ =============================================================================
@ UNIVERSAL COUNTERPART HOUSE — 1F
@
@ VAR_COUNTERPART_HOME_EVENT
@   0 = Player has not been invited
@   1 = Counterpart invited player to meet them here
@   2 = Player accepted help finding Professor Oak
@   3 = Route 101 introduction is complete
@
@ Porymap counterpart object:
@   Local ID:  LOCALID_COUNTERPART_HOUSE_COUNTERPART
@   Graphics:  OBJ_EVENT_GFX_VAR_0
@   Script:    LittlerootTown_BrendansHouse_1F_EventScript_Counterpart
@ =============================================================================


@ =============================================================================
@ DYNAMIC COUNTERPART GRAPHICS
@ =============================================================================

LittlerootTown_BrendansHouse_1F_SetCounterpartGraphics:
    goto_if_eq VAR_COUNTERPART_ID, COUNTERPART_BRENDAN, LittlerootTown_BrendansHouse_1F_SetBrendan
    goto_if_eq VAR_COUNTERPART_ID, COUNTERPART_MAY, LittlerootTown_BrendansHouse_1F_SetMay
    goto_if_eq VAR_COUNTERPART_ID, COUNTERPART_LEXY, LittlerootTown_BrendansHouse_1F_SetCeleste
    goto_if_eq VAR_COUNTERPART_ID, COUNTERPART_JUSTIN, LittlerootTown_BrendansHouse_1F_SetHiiro
    goto_if_eq VAR_COUNTERPART_ID, COUNTERPART_MAAM, LittlerootTown_BrendansHouse_1F_SetAleciya
    goto_if_eq VAR_COUNTERPART_ID, COUNTERPART_SIR, LittlerootTown_BrendansHouse_1F_SetAster

    @ Safe fallback.
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_BRENDAN_NORMAL
    end


LittlerootTown_BrendansHouse_1F_SetBrendan:
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_BRENDAN_NORMAL
    end


LittlerootTown_BrendansHouse_1F_SetMay:
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_MAY_NORMAL
    end


LittlerootTown_BrendansHouse_1F_SetCeleste:
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_LEXY_NORMAL
    end


LittlerootTown_BrendansHouse_1F_SetHiiro:
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_JUSTIN_NORMAL
    end


LittlerootTown_BrendansHouse_1F_SetAleciya:
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_MAAM_NORMAL
    end


LittlerootTown_BrendansHouse_1F_SetAster:
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SIR_NORMAL
    end


@ =============================================================================
@ COUNTERPART INTERACTION
@ =============================================================================

LittlerootTown_BrendansHouse_1F_EventScript_Counterpart::
    lock
    faceplayer

    compare VAR_COUNTERPART_HOME_EVENT, 1
    goto_if_eq LittlerootTown_BrendansHouse_1F_EventScript_FormalIntroduction

    compare VAR_COUNTERPART_HOME_EVENT, 2
    goto_if_eq LittlerootTown_BrendansHouse_1F_EventScript_ReadyReminder

    compare VAR_COUNTERPART_HOME_EVENT, 3
    goto_if_eq LittlerootTown_BrendansHouse_1F_EventScript_AfterRoute101

    msgbox LittlerootTown_BrendansHouse_1F_Text_BeforeInvitation, MSGBOX_DEFAULT
    release
    end


@ =============================================================================
@ FORMAL INTRODUCTION AND BROCK QUESTION
@ =============================================================================

LittlerootTown_BrendansHouse_1F_EventScript_FormalIntroduction:
    msgbox LittlerootTown_BrendansHouse_1F_Text_PlayerAsksAboutBrock, MSGBOX_DEFAULT
    msgbox LittlerootTown_BrendansHouse_1F_Text_CounterpartReactsToBrock, MSGBOX_DEFAULT

    goto_if_eq VAR_COUNTERPART_ID, COUNTERPART_BRENDAN, LittlerootTown_BrendansHouse_1F_EventScript_IntroduceBrendan
    goto_if_eq VAR_COUNTERPART_ID, COUNTERPART_MAY, LittlerootTown_BrendansHouse_1F_EventScript_IntroduceMay
    goto_if_eq VAR_COUNTERPART_ID, COUNTERPART_LEXY, LittlerootTown_BrendansHouse_1F_EventScript_IntroduceCeleste
    goto_if_eq VAR_COUNTERPART_ID, COUNTERPART_JUSTIN, LittlerootTown_BrendansHouse_1F_EventScript_IntroduceHiiro
    goto_if_eq VAR_COUNTERPART_ID, COUNTERPART_MAAM, LittlerootTown_BrendansHouse_1F_EventScript_IntroduceAleciya
    goto_if_eq VAR_COUNTERPART_ID, COUNTERPART_SIR, LittlerootTown_BrendansHouse_1F_EventScript_IntroduceAster

    goto LittlerootTown_BrendansHouse_1F_EventScript_IntroduceUnknown


LittlerootTown_BrendansHouse_1F_EventScript_IntroduceBrendan:
    msgbox LittlerootTown_BrendansHouse_1F_Text_IntroduceBrendan, MSGBOX_DEFAULT
    goto LittlerootTown_BrendansHouse_1F_EventScript_OfferHelp


LittlerootTown_BrendansHouse_1F_EventScript_IntroduceMay:
    msgbox LittlerootTown_BrendansHouse_1F_Text_IntroduceMay, MSGBOX_DEFAULT
    goto LittlerootTown_BrendansHouse_1F_EventScript_OfferHelp


LittlerootTown_BrendansHouse_1F_EventScript_IntroduceCeleste:
    msgbox LittlerootTown_BrendansHouse_1F_Text_IntroduceCeleste, MSGBOX_DEFAULT
    goto LittlerootTown_BrendansHouse_1F_EventScript_OfferHelp


LittlerootTown_BrendansHouse_1F_EventScript_IntroduceHiiro:
    msgbox LittlerootTown_BrendansHouse_1F_Text_IntroduceHiiro, MSGBOX_DEFAULT
    goto LittlerootTown_BrendansHouse_1F_EventScript_OfferHelp


LittlerootTown_BrendansHouse_1F_EventScript_IntroduceAleciya:
    msgbox LittlerootTown_BrendansHouse_1F_Text_IntroduceAleciya, MSGBOX_DEFAULT
    goto LittlerootTown_BrendansHouse_1F_EventScript_OfferHelp


LittlerootTown_BrendansHouse_1F_EventScript_IntroduceAster:
    msgbox LittlerootTown_BrendansHouse_1F_Text_IntroduceAster, MSGBOX_DEFAULT
    goto LittlerootTown_BrendansHouse_1F_EventScript_OfferHelp


LittlerootTown_BrendansHouse_1F_EventScript_IntroduceUnknown:
    msgbox LittlerootTown_BrendansHouse_1F_Text_IntroduceUnknown, MSGBOX_DEFAULT
    goto LittlerootTown_BrendansHouse_1F_EventScript_OfferHelp


@ =============================================================================
@ ACCEPT OR DECLINE HELP
@ =============================================================================

LittlerootTown_BrendansHouse_1F_EventScript_OfferHelp:
    msgbox LittlerootTown_BrendansHouse_1F_Text_OfferHelp, MSGBOX_DEFAULT

    yesnobox 20, 8
    compare VAR_RESULT, YES
    goto_if_eq LittlerootTown_BrendansHouse_1F_EventScript_AcceptHelp

    msgbox LittlerootTown_BrendansHouse_1F_Text_NotReady, MSGBOX_DEFAULT
    release
    end


LittlerootTown_BrendansHouse_1F_EventScript_AcceptHelp:
    @ The initial acceptance and the later reminder both use
    @ the same departure setup.
    goto LittlerootTown_BrendansHouse_1F_EventScript_LeaveForRoute101


LittlerootTown_BrendansHouse_1F_EventScript_ReadyReminder:
    msgbox LittlerootTown_BrendansHouse_1F_Text_ReadyReminder, MSGBOX_DEFAULT

    yesnobox 20, 8
    compare VAR_RESULT, YES
    goto_if_eq LittlerootTown_BrendansHouse_1F_EventScript_LeaveForRoute101

    msgbox LittlerootTown_BrendansHouse_1F_Text_NotReady, MSGBOX_DEFAULT
    release
    end


LittlerootTown_BrendansHouse_1F_EventScript_LeaveForRoute101:
    @ Marks the invitation as accepted.
    setvar VAR_COUNTERPART_HOME_EVENT, 2

    @ State 3 tells Littleroot's ON_FRAME table to begin
    @ the outside escort when the player exits this house.
    setvar VAR_LITTLEROOT_STORY, 3

    @ Reveal the separate counterpart object placed outside
    @ in Littleroot.
    clearflag FLAG_HIDE_COUNTERPART_LITTLEROOT_WALK

    msgbox LittlerootTown_BrendansHouse_1F_Text_LetsGo, MSGBOX_DEFAULT

    @ For now, the player exits through the normal doorway.
    @ Littleroot's ON_FRAME script takes over after the map loads.
    release
    end


LittlerootTown_BrendansHouse_1F_EventScript_AfterRoute101:
    msgbox LittlerootTown_BrendansHouse_1F_Text_AfterRoute101, MSGBOX_DEFAULT
    release
    end


@ =============================================================================
@ HOUSE OBJECTS
@ =============================================================================

LittlerootTown_BrendansHouse_1F_EventScript_Bookshelf::
    msgbox LittlerootTown_BrendansHouse_1F_Text_Bookshelf, MSGBOX_SIGN
    end


LittlerootTown_BrendansHouse_1F_EventScript_TV::
    msgbox LittlerootTown_BrendansHouse_1F_Text_TV, MSGBOX_SIGN
    end


LittlerootTown_BrendansHouse_1F_EventScript_Table::
    msgbox LittlerootTown_BrendansHouse_1F_Text_Table, MSGBOX_SIGN
    end


@ =============================================================================
@ DIALOGUE
@ =============================================================================

LittlerootTown_BrendansHouse_1F_Text_BeforeInvitation:
    .string "It doesn't look like anyone is\n"
    .string "expecting you yet.$"


LittlerootTown_BrendansHouse_1F_Text_PlayerAsksAboutBrock:
    .string "{PLAYER}: Wait...\p"
    .string "The restaurant guy never told me\n"
    .string "his name.\p"
    .string "Who was he?$"


LittlerootTown_BrendansHouse_1F_Text_CounterpartReactsToBrock:
    .string "You don't know who that was?\p"
    .string "That's Br..\p"
    .string "...\p"
    .string "Wow. You really don't know\n"
    .string "anything, huh?\p"
    .string "You'll find out soon enough.$"


LittlerootTown_BrendansHouse_1F_Text_IntroduceBrendan:
    .string "Anyway, I'm Brendan.\p"
    .string "Professor Oak is my grandfather.$"


LittlerootTown_BrendansHouse_1F_Text_IntroduceMay:
    .string "Anyway, I'm May.\p"
    .string "Professor Oak is my grandfather.$"


LittlerootTown_BrendansHouse_1F_Text_IntroduceCeleste:
    .string "Anyway, I'm Celeste.\p"
    .string "Professor Oak is my grandfather.$"


LittlerootTown_BrendansHouse_1F_Text_IntroduceHiiro:
    .string "Anyway, I'm Hiiro.\p"
    .string "Professor Oak is my grandfather.$"


LittlerootTown_BrendansHouse_1F_Text_IntroduceAleciya:
    .string "Anyway, I'm Aleciya.\p"
    .string "Professor Oak is my grandfather.$"


LittlerootTown_BrendansHouse_1F_Text_IntroduceAster:
    .string "Anyway, I'm Aster.\p"
    .string "Professor Oak is my grandfather.$"


LittlerootTown_BrendansHouse_1F_Text_IntroduceUnknown:
    .string "Anyway...\p"
    .string "Professor Oak is my grandfather.$"


LittlerootTown_BrendansHouse_1F_Text_OfferHelp:
    .string "Gramps should be around Route 101\n"
    .string "doing research.\p"
    .string "I can take you to him now.\p"
    .string "Are you ready?$"


LittlerootTown_BrendansHouse_1F_Text_NotReady:
    .string "All right.\p"
    .string "Come back when you're ready.$"


LittlerootTown_BrendansHouse_1F_Text_LetsGo:
    .string "Good.\p"
    .string "Stay close and try not to get\n"
    .string "lost on your first day.$"


LittlerootTown_BrendansHouse_1F_Text_ReadyReminder:
    .string "Ready to find Gramps?$"


LittlerootTown_BrendansHouse_1F_Text_AfterRoute101:
    .string "Your first day certainly wasn't\n"
    .string "boring.$"


LittlerootTown_BrendansHouse_1F_Text_Bookshelf:
    .string "The shelves are packed with books\n"
    .string "about Pokemon and local history.$"


LittlerootTown_BrendansHouse_1F_Text_TV:
    .string "A documentary about Pokemon\n"
    .string "migration is playing.$"


LittlerootTown_BrendansHouse_1F_Text_Table:
    .string "Several research notes are spread\n"
    .string "across the table.$"


@ =============================================================================
@ COMPATIBILITY STUBS
@
@ These prevent old map-event references from breaking the linker while
@ you clean the original Brendan house events out of Porymap.
@ Delete these later once grep confirms nothing references them.
@ =============================================================================

LittlerootTown_BrendansHouse_1F_EventScript_GoSeeRoom::
    end


LittlerootTown_BrendansHouse_1F_EventScript_MeetRival0::
    end


LittlerootTown_BrendansHouse_1F_EventScript_MeetRival1::
    end


LittlerootTown_BrendansHouse_1F_EventScript_MeetRival2::
    end


LittlerootTown_BrendansHouse_1F_EventScript_YoureNewNeighbor::
    end
PlayersHouse_1F_Text_IsntItNiceInHere:
	.string "MOM: See, {PLAYER}?\n"
	.string "Isn't it nice in here, too?$"

PlayersHouse_1F_Text_MoversPokemonGoSetClock:
	.string "The mover's POKéMON do all the work\n"
	.string "of moving us in and cleaning up after.\l"
	.string "This is so convenient!\p"
	.string "{PLAYER}, your room is upstairs.\n"
	.string "Go check it out, dear!\p"
	.string "DAD bought you a new clock to mark\n"
	.string "our move here.\l"
	.string "Don't forget to set it!$"

PlayersHouse_1F_Text_ArentYouInterestedInRoom:
	.string "MOM: Well, {PLAYER}?\p"
	.string "Aren't you interested in seeing your\n"
	.string "very own room?$"

PlayersHouse_1F_Text_GoSetTheClock:
	.string "MOM: {PLAYER}.\p"
	.string "Go set the clock in your room, honey.$"

PlayersHouse_1F_Text_OhComeQuickly:
	.string "MOM: Oh! {PLAYER}, {PLAYER}!\n"
	.string "Quick! Come quickly!$"

PlayersHouse_1F_Text_MaybeDadWillBeOn:
	.string "MOM: Look! It's PETALBURG GYM!\n"
	.string "Maybe DAD will be on!$"

PlayersHouse_1F_Text_ItsOverWeMissedHim:
	.string "MOM: Oh… It's over.\p"
	.string "I think DAD was on, but we missed him.\n"
	.string "Too bad.$"

PlayersHouse_1F_Text_GoIntroduceYourselfNextDoor:
	.string "Oh, yes.\n"
	.string "One of DAD's friends lives in town.\p"
	.string "PROF. OAK is his name.\p"
	.string "He lives right next door, so you should\n"
	.string "go over and introduce yourself.$"

PlayersHouse_1F_Text_SeeYouHoney:
	.string "MOM: See you, honey!$"

PlayersHouse_1F_Text_DidYouMeetProfBirch:
	.string "MOM: Did you introduce yourself to\n"
	.string "PROF. OAK?$"

PlayersHouse_1F_Text_YouShouldRestABit:
	.string "MOM: How are you doing, {PLAYER}?\n"
	.string "You look a little tired.\p"
	.string "I think you should rest a bit.$"

PlayersHouse_1F_Text_TakeCareHoney:
	.string "MOM: Take care, honey!$"

PlayersHouse_1F_Text_GotDadsBadgeHeresSomethingFromMom:
	.string "MOM: Oh? Did DAD give you that BADGE?\p"
	.string "Then here's something from your MOM!$"

PlayersHouse_1F_Text_DontPushYourselfTooHard:
	.string "Don't push yourself too hard, dear.\n"
	.string "You can always come home.\p"
	.string "Go for it, honey!$"

PlayersHouse_1F_Text_IsThatAPokenav:
	.string "MOM: What is that, honey? A POKéNAV?\n"
	.string "Someone from DEVON gave it to you?\p"
	.string "Well, honey, how about registering\n"
	.string "your mom?\p"
	.string "… … …$"

PlayersHouse_1F_Text_RegisteredMom:
	.string "Registered MOM\n"
	.string "in the POKéNAV.$"

PlayersHouse_1F_Text_Vigoroth1:
	.string "Fugiiiiih!$"

PlayersHouse_1F_Text_Vigoroth2:
	.string "Huggoh, uggo uggo…$"

PlayersHouse_1F_Text_ReportFromPetalburgGym:
	.string "INTERVIEWER: …We brought you this\n"
	.string "report from in front of PETALBURG GYM.$"

PlayersHouse_1F_Text_TheresAMovieOnTV:
	.string "There is a movie on TV.\p"
	.string "Two men are dancing on a big piano\n"
	.string "keyboard.\p"
	.string "Better get going!$"

PlayersHouse_1F_Text_RunningShoesManual:
	.string "It's the instruction booklet for the\n"
	.string "RUNNING SHOES.\p"
	.string "“Press the B Button to run while\n"
	.string "wearing your RUNNING SHOES.\p"
	.string "“Lace up your RUNNING SHOES and hit\n"
	.string "the road running!”$"

PlayersHouse_1F_Text_TicketFromBrineyCameForYou:
	.string "DAD: Hm?\p"
	.string "Hey, it's {PLAYER}!\p"
	.string "It's been a while since I saw you,\n"
	.string "but you look…stronger, somehow.\p"
	.string "That's the impression I get.\n"
	.string "But your old man hasn't given up yet!\p"
	.string "Oh, yes, I have something for you.\n"
	.string "This came to you from someone named\l"
	.string "MR. BRINEY.$"

PlayersHouse_1F_Text_PortsInSlateportLilycove:
	.string "DAD: Hm, a TICKET for a ferry?\p"
	.string "If I recall, there are ferry ports in\n"
	.string "SLATEPORT and LILYCOVE.$"

PlayersHouse_1F_Text_BetterGetBackToGym:
	.string "I'd better get back to PETALBURG GYM.\p"
	.string "MOM, thanks for looking after the house\n"
	.string "while I'm away.$"

PlayersHouse_1F_Text_DadShouldStayLonger:
	.string "MOM: That DAD of yours…\p"
	.string "He comes home for the first time in a\n"
	.string "while, but all he talks about is POKéMON.\p"
	.string "He should relax and stay a little longer.$"

PlayersHouse_1F_Text_IsThatABreakingStory:
	.string "MOM: Is that a breaking news story?$"

PlayersHouse_1F_Text_LatiEmergencyNewsFlash:
	.string "We bring you this emergency\n"
	.string "news flash!\p"
	.string "In various HOENN locales, there have\n"
	.string "been reports of a BZZT…colored\l"
	.string "POKéMON in flight.\p"
	.string "The identity of this POKéMON is\n"
	.string "currently unknown.\p"
	.string "We now return you to the regular\n"
	.string "movie program.$"

PlayersHouse_1F_Text_WhatColorDidTheySay:
	.string "MOM: {PLAYER}, did you catch that?\p"
	.string "What color did the announcer say\n"
	.string "that POKéMON was?$"

PlayersHouse_1F_Text_StillUnknownPokemon:
	.string "MOM: Well, isn't that something!\n"
	.string "There are still unknown POKéMON.$"


@ Temporary compatibility alias for the current Porymap object.
CounterpartHouse_Counterpart::
    goto LittlerootTown_BrendansHouse_1F_EventScript_Counterpart
