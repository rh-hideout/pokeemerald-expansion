CeruleanCity_House5_Frlg_MapScripts::
    map_script MAP_SCRIPT_ON_LOAD, CeruleanCity_House5_Frlg_OnLoad
    .byte 0


CeruleanCity_House5_Frlg_OnLoad:
    call CeruleanCity_House5_Frlg_SetCounterpartGraphics

    @ Library counterpart exists ONLY during the ingredient
    @ quest's Cerulean-library stage.
    compare VAR_BROCK_INGREDIENT_QUEST, 4
    goto_if_eq CeruleanCity_House5_Frlg_OnLoadDone

    removeobject LOCALID_COUNTERPART_CERULEAN_LIBRARY

CeruleanCity_House5_Frlg_OnLoadDone:
    end


CeruleanCity_House5_Frlg_SetCounterpartGraphics:
    goto_if_eq VAR_COUNTERPART_ID, COUNTERPART_BRENDAN, CeruleanCity_House5_Frlg_SetCounterpartBrendan
    goto_if_eq VAR_COUNTERPART_ID, COUNTERPART_MAY, CeruleanCity_House5_Frlg_SetCounterpartMay
    goto_if_eq VAR_COUNTERPART_ID, COUNTERPART_LEXY, CeruleanCity_House5_Frlg_SetCounterpartLexy
    goto_if_eq VAR_COUNTERPART_ID, COUNTERPART_JUSTIN, CeruleanCity_House5_Frlg_SetCounterpartJustin
    goto_if_eq VAR_COUNTERPART_ID, COUNTERPART_MAAM, CeruleanCity_House5_Frlg_SetCounterpartMaam
    goto_if_eq VAR_COUNTERPART_ID, COUNTERPART_SIR, CeruleanCity_House5_Frlg_SetCounterpartSir
    end


CeruleanCity_House5_Frlg_SetCounterpartBrendan:
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_BRENDAN_NORMAL
    end

CeruleanCity_House5_Frlg_SetCounterpartMay:
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_MAY_NORMAL
    end

CeruleanCity_House5_Frlg_SetCounterpartLexy:
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_LEXY_NORMAL
    end

CeruleanCity_House5_Frlg_SetCounterpartJustin:
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_JUSTIN_NORMAL
    end

CeruleanCity_House5_Frlg_SetCounterpartMaam:
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_MAAM_NORMAL
    end

CeruleanCity_House5_Frlg_SetCounterpartSir:
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SIR_NORMAL
    end


@ ============================================================
@ COUNTERPART - INGREDIENT QUEST
@ ============================================================

CeruleanCity_House5_Frlg_EventScript_IngredientCounterpart::
    lock
    faceplayer

    compare VAR_BROCK_INGREDIENT_QUEST, 4
    goto_if_eq CeruleanCity_House5_Frlg_EventScript_IngredientCounterpartWaiting

    compare VAR_BROCK_INGREDIENT_QUEST, 5
    goto_if_eq CeruleanCity_House5_Frlg_EventScript_IngredientCounterpartAfter

    release
    end


CeruleanCity_House5_Frlg_EventScript_IngredientCounterpartWaiting:
    msgbox CeruleanCity_House5_Frlg_Text_IngredientCounterpartWaiting, MSGBOX_DEFAULT
    release
    end


CeruleanCity_House5_Frlg_EventScript_IngredientCounterpartAfter:
    msgbox CeruleanCity_House5_Frlg_Text_IngredientCounterpartAfter, MSGBOX_DEFAULT
    release
    end


@ ============================================================
@ LIBRARY SCENE CHOREOGRAPHY
@ ============================================================

CeruleanCity_House5_Frlg_Movement_CounterpartFaceLibrarian:
    face_right
    step_end

CeruleanCity_House5_Frlg_Movement_CounterpartFacePlayer:
    face_down
    step_end

CeruleanCity_House5_Frlg_Movement_LibrarianFaceCounterpart:
    face_left
    step_end

CeruleanCity_House5_Frlg_Movement_LibrarianFacePlayer:
    face_down
    step_end


@ ============================================================
@ LIBRARIAN
@ ============================================================

CeruleanCity_House5_Frlg_EventScript_Librarian::
    lock
    faceplayer

    @ Brock ingredient quest: Cerulean library lead.
    compare VAR_BROCK_INGREDIENT_QUEST, 4
    goto_if_eq CeruleanCity_House5_Frlg_EventScript_IngredientQuest

    @ If the special book callback already happened,
    @ use the permanent repeat line.
    goto_if_set FLAG_CERULEAN_LIBRARIAN_BOOK_SEEN, CeruleanCity_House5_Frlg_EventScript_LibrarianRepeat

    @ If the player has the Mysterious Book,
    @ trigger the special Cerulean callback.
    checkitem ITEM_MYSTERIOUS_BOOK, 1
    goto_if_eq VAR_RESULT, TRUE, CeruleanCity_House5_Frlg_EventScript_LibrarianBookCallback

    @ Otherwise use the normal original interaction.
    msgbox CeruleanCity_House5_Frlg_Text_LibrarianWelcome, MSGBOX_DEFAULT
    closemessage

    multichoice 0, 0, MULTICHOICE_CERULEAN_LIBRARY_OLD_MAN, FALSE

    switch VAR_RESULT
    case 0, CeruleanCity_House5_Frlg_EventScript_AskBlue
    case 1, CeruleanCity_House5_Frlg_EventScript_AskSuspicious
    case 2, CeruleanCity_House5_Frlg_EventScript_AskBooks

    release
    end


CeruleanCity_House5_Frlg_EventScript_AskBlue:
    addvar VAR_CURIOSITY, 1
    msgbox CeruleanCity_House5_Frlg_Text_AskBlue, MSGBOX_DEFAULT
    release
    end


CeruleanCity_House5_Frlg_EventScript_AskSuspicious:
    addvar VAR_PERSPECTIVE, 1
    msgbox CeruleanCity_House5_Frlg_Text_AskSuspicious, MSGBOX_DEFAULT
    release
    end


CeruleanCity_House5_Frlg_EventScript_AskBooks:
    addvar VAR_COMPASSION, 1
    msgbox CeruleanCity_House5_Frlg_Text_AskBooks, MSGBOX_DEFAULT
    release
    end


@ ============================================================
@ LIBRARIAN - MYSTERIOUS BOOK CALLBACK
@ ============================================================

CeruleanCity_House5_Frlg_EventScript_LibrarianBookCallback:
    msgbox CeruleanCity_House5_Frlg_Text_LibrarianBookNotice, MSGBOX_DEFAULT
    closemessage

    msgbox CeruleanCity_House5_Frlg_Text_PlayerBookOrigin, MSGBOX_DEFAULT
    closemessage

    msgbox CeruleanCity_House5_Frlg_Text_LibrarianLittleroot, MSGBOX_DEFAULT
    closemessage

    msgbox CeruleanCity_House5_Frlg_Text_LibrarianBlaine, MSGBOX_DEFAULT
    closemessage

    msgbox CeruleanCity_House5_Frlg_Text_PlayerDoesntKnow, MSGBOX_DEFAULT
    closemessage

    setflag FLAG_CERULEAN_LIBRARIAN_BOOK_SEEN

    release
    end


CeruleanCity_House5_Frlg_EventScript_LibrarianRepeat:
    msgbox CeruleanCity_House5_Frlg_Text_LibrarianRepeat, MSGBOX_DEFAULT
    release
    end

@ ============================================================
@ BROCK INGREDIENT QUEST - LORELEI / TWELVE MONTHS
@ ============================================================

CeruleanCity_House5_Frlg_EventScript_IngredientQuest:
    @ Counterpart addresses librarian.
    applymovement LOCALID_COUNTERPART_CERULEAN_LIBRARY, CeruleanCity_House5_Frlg_Movement_CounterpartFaceLibrarian
    applymovement LOCALID_CERULEAN_LIBRARY_LIBRARIAN, CeruleanCity_House5_Frlg_Movement_LibrarianFaceCounterpart
    waitmovement 0

    msgbox CeruleanCity_House5_Frlg_Text_LoreleiOpening, MSGBOX_DEFAULT
    closemessage

    msgbox CeruleanCity_House5_Frlg_Text_LoreleiLead, MSGBOX_DEFAULT
    closemessage

    @ Librarian turns back to player for the personal callback.
    applymovement LOCALID_CERULEAN_LIBRARY_LIBRARIAN, CeruleanCity_House5_Frlg_Movement_LibrarianFacePlayer
    waitmovement 0

    @ Only reference the earlier book conversation if it happened.
    checkflag FLAG_CERULEAN_LIBRARIAN_BOOK_SEEN
    goto_if FALSE, CeruleanCity_House5_Frlg_EventScript_IngredientNoBookCallback

    msgbox CeruleanCity_House5_Frlg_Text_BeforeYouGo, MSGBOX_DEFAULT
    closemessage

    applymovement LOCALID_COUNTERPART_CERULEAN_LIBRARY, CeruleanCity_House5_Frlg_Movement_CounterpartFacePlayer
    waitmovement 0

    msgbox CeruleanCity_House5_Frlg_Text_CounterpartBookShock, MSGBOX_DEFAULT
    closemessage

    msgbox CeruleanCity_House5_Frlg_Text_TwelveMonthsQuestion, MSGBOX_DEFAULT
    closemessage

    applymovement LOCALID_COUNTERPART_CERULEAN_LIBRARY, CeruleanCity_House5_Frlg_Movement_CounterpartFaceLibrarian
    applymovement LOCALID_CERULEAN_LIBRARY_LIBRARIAN, CeruleanCity_House5_Frlg_Movement_LibrarianFaceCounterpart
    waitmovement 0

    msgbox CeruleanCity_House5_Frlg_Text_CounterpartYearJoke, MSGBOX_DEFAULT
    closemessage

    @ Now counterpart notices PLAYER reacting.
    applymovement LOCALID_COUNTERPART_CERULEAN_LIBRARY, CeruleanCity_House5_Frlg_Movement_CounterpartFacePlayer
    applymovement LOCALID_CERULEAN_LIBRARY_LIBRARIAN, CeruleanCity_House5_Frlg_Movement_LibrarianFacePlayer
    waitmovement 0

    msgbox CeruleanCity_House5_Frlg_Text_SaffronRealization, MSGBOX_DEFAULT
    closemessage

    multichoice 0, 0, MULTICHOICE_CERULEAN_BOOK_DISCLOSURE, FALSE

    switch VAR_RESULT
    case 0, CeruleanCity_House5_Frlg_EventScript_DiscloseEverything
    case 1, CeruleanCity_House5_Frlg_EventScript_DiscloseBook
    case 2, CeruleanCity_House5_Frlg_EventScript_Deflect

    goto CeruleanCity_House5_Frlg_EventScript_Deflect


CeruleanCity_House5_Frlg_EventScript_DiscloseEverything:
    addvar VAR_COMPASSION, 1
    addvar VAR_CURIOSITY, 1

    msgbox CeruleanCity_House5_Frlg_Text_DiscloseEverything, MSGBOX_DEFAULT
    closemessage

    msgbox CeruleanCity_House5_Frlg_Text_DiscloseEverythingReply, MSGBOX_DEFAULT
    closemessage

    goto CeruleanCity_House5_Frlg_EventScript_FinishIngredient


CeruleanCity_House5_Frlg_EventScript_DiscloseBook:
    addvar VAR_PERSPECTIVE, 1

    msgbox CeruleanCity_House5_Frlg_Text_DiscloseBook, MSGBOX_DEFAULT
    closemessage

    msgbox CeruleanCity_House5_Frlg_Text_DiscloseBookReply, MSGBOX_DEFAULT
    closemessage

    goto CeruleanCity_House5_Frlg_EventScript_FinishIngredient


CeruleanCity_House5_Frlg_EventScript_Deflect:
    addvar VAR_INDEPENDENCE, 1

    msgbox CeruleanCity_House5_Frlg_Text_Deflect, MSGBOX_DEFAULT
    closemessage

    msgbox CeruleanCity_House5_Frlg_Text_DeflectReply, MSGBOX_DEFAULT
    closemessage

    goto CeruleanCity_House5_Frlg_EventScript_FinishIngredient


CeruleanCity_House5_Frlg_EventScript_IngredientNoBookCallback:
    msgbox CeruleanCity_House5_Frlg_Text_NoBookCallback, MSGBOX_DEFAULT
    closemessage

    goto CeruleanCity_House5_Frlg_EventScript_FinishIngredient


CeruleanCity_House5_Frlg_EventScript_FinishIngredient:
    @ Move PLAYER underneath counterpart so the conversation
    @ visually reads as PLAYER <-> counterpart, not PLAYER
    @ continuing to stare at the librarian.
    applymovement LOCALID_PLAYER, CeruleanCity_House5_Frlg_Movement_PlayerStepsToCounterpart
    waitmovement 0

    applymovement LOCALID_COUNTERPART_CERULEAN_LIBRARY, CeruleanCity_House5_Frlg_Movement_CounterpartFacePlayer
    waitmovement 0

    @ Fuchsia is our next lead... unfortunately, counterpart
    @ knows exactly who can get us there.
    msgbox CeruleanCity_House5_Frlg_Text_FuchsiaRideRealization, MSGBOX_DEFAULT
    closemessage

    msgbox CeruleanCity_House5_Frlg_Text_FuchsiaRideArgument, MSGBOX_DEFAULT
    closemessage

    @ State 5 = library finished / go find Gary.
    setvar VAR_BROCK_INGREDIENT_QUEST, 5

    @ Leave the library naturally.
    applymovement LOCALID_COUNTERPART_CERULEAN_LIBRARY, CeruleanCity_House5_Frlg_Movement_CounterpartLeavesLibrary
    waitmovement 0

    @ Hide first so there is no visible pop, then remove the
    @ live object so it cannot leave collision on the doorway.
    hideobjectat LOCALID_COUNTERPART_CERULEAN_LIBRARY, MAP_CERULEAN_CITY_HOUSE5

    release
    end


@ ============================================================
@ INGREDIENT QUEST - COUNTERPART LEAVES FOR GARY
@ ============================================================

CeruleanCity_House5_Frlg_Movement_PlayerStepsToCounterpart:
    walk_left
    face_up
    step_end


CeruleanCity_House5_Frlg_Movement_CounterpartLeavesLibrary:
    walk_left
    walk_left
    walk_down
    walk_down
    walk_down
    walk_down
    step_end


@ ============================================================
@ JAMES / TEAM AQUA BOOK GREMLIN
@ ============================================================

CeruleanCity_House5_Frlg_EventScript_James::
    lockall

    applymovement LOCALID_JAMES, Common_Movement_FacePlayer
    waitmovement 0

    msgbox CeruleanCity_House5_Frlg_Text_JamesCaught, MSGBOX_DEFAULT
    closemessage

    msgbox CeruleanCity_House5_Frlg_Text_JamesExplanation, MSGBOX_DEFAULT
    closemessage

    msgbox CeruleanCity_House5_Frlg_Text_JamesRocketGuy, MSGBOX_DEFAULT
    closemessage

    msgbox CeruleanCity_House5_Frlg_Text_JamesEscape, MSGBOX_DEFAULT
    closemessage

    applymovement LOCALID_JAMES, CeruleanCity_House5_Frlg_Movement_JamesLeaves
    waitmovement 0

    setflag FLAG_HIDE_CERULEAN_AQUA_GRUNT
    removeobject LOCALID_JAMES

    releaseall
    end



CeruleanCity_House5_Frlg_Movement_JamesLeaves:
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    step_end


CeruleanCity_House5_Frlg_Text_FuchsiaRideRealization:
    .string "{RIVAL}: ...FUCHSIA.\p"
    .string "...\p"
    .string "Damn it.\p"
    .string "{PLAYER}: What?\p"
    .string "{RIVAL}: I know someone who can\n"
    .string "get us there.\p"
    .string "{PLAYER}: Great.\p"
    .string "{RIVAL}: No.\n"
    .string "Not great.$"


CeruleanCity_House5_Frlg_Text_FuchsiaRideArgument:
    .string "{RIVAL}: Ughhh...\n"
    .string "come with me, I guess.\p"
    .string "{PLAYER}: Who?\p"
    .string "{RIVAL}: I HATE asking people\n"
    .string "for favors.\p"
    .string "{PLAYER}: You still haven't\n"
    .string "answered me.\p"
    .string "{RIVAL}: COME ON.$"


@ ============================================================
@ BROCK INGREDIENT QUEST TEXT
@ ============================================================

CeruleanCity_House5_Frlg_Text_IngredientCounterpartWaiting:
    .string "{RIVAL}: See?\p"
    .string "I said I'd meet you here.\p"
    .string "Now ask the book guy about our\n"
    .string "mysterious lady.$"


CeruleanCity_House5_Frlg_Text_IngredientCounterpartAfter:
    .string "{RIVAL}: So...\p"
    .string "FUCHSIA.\p"
    .string "And apparently your life has even\n"
    .string "more footnotes than I thought.$"


CeruleanCity_House5_Frlg_Text_LoreleiOpening:
    .string "LIBRARIAN: Back again?\p"
    .string "You look like you're searching for\n"
    .string "someone this time.\p"
    .string "{RIVAL}: A woman.\p"
    .string "Red hair. Serious face.\p"
    .string "Looks like she could freeze you\n"
    .string "just by staring at you.\p"
    .string "...Figuratively. Probably.$"


CeruleanCity_House5_Frlg_Text_LoreleiLead:
    .string "LIBRARIAN: Ah! Yes, I remember her.\p"
    .string "She spent quite some time with our\n"
    .string "older records.\p"
    .string "She was especially interested in\n"
    .string "material from FUCHSIA CITY.\p"
    .string "Something about an old ingredient\n"
    .string "and where it could still be found.\p"
    .string "{RIVAL}: FUCHSIA it is, then.$"


CeruleanCity_House5_Frlg_Text_BeforeYouGo:
    .string "LIBRARIAN: Actually...\p"
    .string "Before you go.\p"
    .string "After the last time you were here,\n"
    .string "I couldn't stop thinking about\l"
    .string "your book.$"


CeruleanCity_House5_Frlg_Text_CounterpartBookShock:
    .string "{RIVAL}: ...Your WHAT?\p"
    .string "LIBRARIAN: That peculiar cover.\p"
    .string "I knew I'd seen something like it\n"
    .string "before.$"


CeruleanCity_House5_Frlg_Text_TwelveMonthsQuestion:
    .string "LIBRARIAN: Tell me, {PLAYER}...\p"
    .string "Do the TWELVE MONTHS mean anything\n"
    .string "to you?$"


CeruleanCity_House5_Frlg_Text_CounterpartYearJoke:
    .string "{RIVAL}: The twelve months?\p"
    .string "Sure.\p"
    .string "They make a year.\p"
    .string "Twelve of them, specifically.\p"
    .string "{PLAYER}: Please stop.\p"
    .string "LIBRARIAN: I am familiar with\n"
    .string "the calendar.\p"
    .string "{RIVAL}: Okay, good.\p"
    .string "Just establishing a baseline.$"


CeruleanCity_House5_Frlg_Text_SaffronRealization:
    .string "{PLAYER}: ...\p"
    .string "{RIVAL}: ...\p"
    .string "Why are you making that face?\p"
    .string "{PLAYER}: What face?\p"
    .string "{RIVAL}: THAT face.\p"
    .string "The one where something incredibly\n"
    .string "concerning suddenly makes sense.\p"
    .string "{PLAYER}: I don't have a face\n"
    .string "for that.\p"
    .string "{RIVAL}: You absolutely do.\p"
    .string "You know what he's talking about,\n"
    .string "don't you?\p"
    .string "{PLAYER}: ...$"


CeruleanCity_House5_Frlg_Text_DiscloseEverything:
    .string "{PLAYER}: Okay.\p"
    .string "There's a book.\p"
    .string "I've had it since LITTLEROOT.\p"
    .string "It reacted to something in the\n"
    .string "SEASHORE HOUSE...\p"
    .string "and somehow I ended up in SAFFRON.\p"
    .string "But not the SAFFRON we know.\p"
    .string "It was... earlier.$"


CeruleanCity_House5_Frlg_Text_DiscloseEverythingReply:
    .string "{RIVAL}: ...Earlier?\p"
    .string "{PLAYER}: In time.\p"
    .string "{RIVAL}: YOU WENT BACK IN TIME?!\p"
    .string "{PLAYER}: Apparently.\p"
    .string "{RIVAL}: And this wasn't something\n"
    .string "you thought to mention?!\p"
    .string "{PLAYER}: We weren't exactly--\p"
    .string "{RIVAL}: Don't say “together.”\p"
    .string "{PLAYER}: ...\p"
    .string "{RIVAL}: I KNEW you were going\n"
    .string "to say it.$"


CeruleanCity_House5_Frlg_Text_DiscloseBook:
    .string "{PLAYER}: I have a strange book.\p"
    .string "I've had it for a while.\p"
    .string "He noticed the cover the last time\n"
    .string "we were here.\p"
    .string "That's all I really want to say\n"
    .string "about it right now.$"


CeruleanCity_House5_Frlg_Text_DiscloseBookReply:
    .string "{RIVAL}: ...A while?\p"
    .string "We've been through multiple cities.\p"
    .string "{PLAYER}: Not together.\p"
    .string "You keep showing up.\p"
    .string "{RIVAL}: That is NOT the point.\p"
    .string "...Fine.\p"
    .string "For now.$"


CeruleanCity_House5_Frlg_Text_Deflect:
    .string "{PLAYER}: I don't know what he\n"
    .string "means.\p"
    .string "{RIVAL}: ...Really.\p"
    .string "{PLAYER}: Really.$"


CeruleanCity_House5_Frlg_Text_DeflectReply:
    .string "{RIVAL}: Hm.\p"
    .string "Okay.\p"
    .string "I'm going to remember that answer.$"


CeruleanCity_House5_Frlg_Text_NoBookCallback:
    .string "LIBRARIAN: Well...\p"
    .string "If you're following that woman's\n"
    .string "trail, FUCHSIA is your best lead.\p"
    .string "{RIVAL}: Then that's where we're\n"
    .string "going.$"


@ ============================================================
@ TEXT
@ ============================================================

CeruleanCity_House5_Frlg_Text_LibrarianWelcome:
    .string "LIBRARIAN: Welcome!\p"
    .string "It's always wonderful to see young\n"
    .string "people interested in books!$"


CeruleanCity_House5_Frlg_Text_AskBlue:
    .string "{PLAYER}: The guy in blue over\n"
    .string "there. What do you know about him?\p"
    .string "LIBRARIAN: Him?\p"
    .string "Oh, he's been perfectly pleasant!\p"
    .string "He really understands the\n"
    .string "importance of books.\p"
    .string "Youngsters like that don't come\n"
    .string "around too often anymore.\p"
    .string "...I hope he's not the person\n"
    .string "you're looking for.$"


CeruleanCity_House5_Frlg_Text_AskSuspicious:
    .string "{PLAYER}: Has that guy been acting\n"
    .string "suspicious?\p"
    .string "LIBRARIAN: Suspicious?\p"
    .string "Not at all!\p"
    .string "He's been quietly reading since he\n"
    .string "arrived.\p"
    .string "Though...\n"
    .string "his clothes are certainly unusual.$"


CeruleanCity_House5_Frlg_Text_AskBooks:
    .string "{PLAYER}: What has he been looking\n"
    .string "for?\p"
    .string "LIBRARIAN: Books, mostly!\p"
    .string "He asked about some of our older\n"
    .string "research material.\p"
    .string "Very enthusiastic young man.\p"
    .string "Perhaps a little TOO enthusiastic.$"


CeruleanCity_House5_Frlg_Text_JamesCaught:
    .string "JAMES: OH, COME ONNNNN!\p"
    .string "I went BACK IN TIME after failing\n"
    .string "the last mission just so I could\l"
    .string "read books I'd otherwise never\l"
    .string "get to read!\p"
    .string "And YOU?!\n"
    .string "AGAIN?!$"


CeruleanCity_House5_Frlg_Text_JamesExplanation:
    .string "JAMES: Whatever.\p"
    .string "You're too late anyway.\p"
    .string "We already did the whole\n"
    .string "bad guy thing.\p"
    .string "It wasn't even that bad!\p"
    .string "One of these books talked about an\n"
    .string "experiment involving changing a\l"
    .string "POKéMON's color.\p"
    .string "So we tried it.$"


CeruleanCity_House5_Frlg_Text_JamesRocketGuy:
    .string "JAMES: That Rocket guy got all\n"
    .string "obsessive and weird about it.\p"
    .string "I just wanted the research.\p"
    .string "And, obviously...\n"
    .string "the books.$"


CeruleanCity_House5_Frlg_Text_JamesEscape:
    .string "JAMES: Anyway...\p"
    .string "SO LONG, SUCKERRRRR!$"

CeruleanCity_House5_Frlg_Text_LibrarianBookNotice:
    .string "LIBRARIAN: That book...\p"
    .string "It has a rather peculiar cover.\p"
    .string "Do you mind if I ask where you\n"
    .string "got it?$"


CeruleanCity_House5_Frlg_Text_PlayerBookOrigin:
    .string "{PLAYER}: Oh, this?\p"
    .string "Someone gave it to me at BLAINE'S\n"
    .string "LIBRARY back home in LITTLEROOT.$"


CeruleanCity_House5_Frlg_Text_LibrarianLittleroot:
    .string "LIBRARIAN: ...\p"
    .string "LITTLEROOT?\p"
    .string "Where's that?$"


CeruleanCity_House5_Frlg_Text_LibrarianBlaine:
    .string "LIBRARIAN: Wait...\p"
    .string "Did you say BLAINE?\p"
    .string "As in BLAINE, the CINNABAR ISLAND\n"
    .string "GYM LEADER?!\p"
    .string "Since when does BLAINE have a\n"
    .string "LIBRARY?!$"


CeruleanCity_House5_Frlg_Text_PlayerDoesntKnow:
    .string "...You don't know how to answer\n"
    .string "any of those questions.\p"
    .string "You decide it's probably best\n"
    .string "to leave.$"


CeruleanCity_House5_Frlg_Text_LibrarianRepeat:
    .string "LIBRARIAN: BLAINE'S LIBRARY...\p"
    .string "I'll have to look into that.$"