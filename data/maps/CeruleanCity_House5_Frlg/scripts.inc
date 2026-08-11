CeruleanCity_House5_Frlg_MapScripts::
    .byte 0


@ ============================================================
@ LIBRARIAN
@ ============================================================

CeruleanCity_House5_Frlg_EventScript_Librarian::
    lock
    faceplayer

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