SongFlagRoom_MapScripts::
	.byte 0

SongFlagRoom_OnTransition:
	setflag FLAG_SONGFLAGROOM_BETRETEN
	end


@ ========== NPC  ==========
SongFlagRoom_EventScript_Hiker::
	msgbox SongFlagRoom_Text_Hiker, MSGBOX_NPC
	end

@ ========== Terminal ==========
SongFlagRoom_EventScript_Terminal::
    lock
    faceplayer

    goto_if_set FLAG_CTF_SONGROOM_ROCK_REMOVED, SongFlagRoom_Terminal_AlreadyOpen

    msgbox SongFlagRoom_Text_TerminalPrompt, MSGBOX_DEFAULT
    closemessage

    setvar VAR_0x8000, 6
    callnative Ctf_FlagTerminal
    waitstate

    goto_if_eq VAR_RESULT, 1, SongFlagRoom_Terminal_Correct
    goto SongFlagRoom_Terminal_Wrong


SongFlagRoom_Terminal_Wrong:
    msgbox SongFlagRoom_Text_TerminalWrong, MSGBOX_DEFAULT
    release
    end

SongFlagRoom_Terminal_AlreadyOpen:
    msgbox SongFlagRoom_Text_TerminalAlreadyOpen, MSGBOX_DEFAULT
    release
    end

SongFlagRoom_Terminal_Correct:
    msgbox SongFlagRoom_Text_TerminalCorrect, MSGBOX_DEFAULT
    closemessage

    setflag FLAG_CTF_SONGROOM_ROCK_REMOVED

    @ Stein entfernen
    removeobject 3
    special DrawWholeMapView

    release
    end

SongFlagRoom_Text_Hiker:
	.string "Can you hear how the wind\n"
	.string "whistles through this cave?\p"
	.string "Almost like a melody.$"

SongFlagRoom_Text_TerminalPrompt::
    .string "Enter the Flag.$"

SongFlagRoom_Text_TerminalWrong::
    .string "ACCESS DENIED.$"

SongFlagRoom_Text_TerminalAlreadyOpen::
	.string "The terminal is already\n"
	.string "unlocked.$"

SongFlagRoom_Text_TerminalCorrect::
	.string "Access granted. \n"
	.string "Rock removed.$"

