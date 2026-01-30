SongFlagRoom_MapScripts::
	.byte 0

@ ========== NPC (Object ID 1) ==========
SongFlagRoom_EventScript_Hiker::
	msgbox SongFlagRoom_Text_Hiker, MSGBOX_NPC
	end

@ ========== Terminal (Object ID 2) ==========
SongFlagRoom_EventScript_Terminal::
	lock
	faceplayer

	@ Wenn der Stein schon weg ist: nix mehr eingeben lassen
	goto_if_set FLAG_SONGFLAGROOM_ROCK_REMOVED, SongFlagRoom_Terminal_AlreadyDone

	@ --- HIER: Flag #6 abfragen (dein CTF-Terminal-System) ---
	@ Übergib die "6" an dein Terminal (so wie bei deinen anderen Terminal-Maps)
	setvar VAR_0x8000, 6
	special Special_CtfTerminal_EnterFlag
	waitstate

	@ Erwartung: Special setzt VAR_RESULT auf 1 bei Erfolg, sonst 0
	compare VAR_RESULT, 1
	goto_if_eq SongFlagRoom_Terminal_Success

SongFlagRoom_Terminal_Fail::
	msgbox SongFlagRoom_Text_TerminalFail, MSGBOX_DEFAULT
	release
	end

SongFlagRoom_Terminal_Success::
	msgbox SongFlagRoom_Text_TerminalSuccess, MSGBOX_DEFAULT

	@ Stein dauerhaft entfernen:
	setflag FLAG_SONGFLAGROOM_ROCK_REMOVED
	removeobject 3

	release
	end

SongFlagRoom_Terminal_AlreadyDone::
	msgbox SongFlagRoom_Text_TerminalAlready, MSGBOX_DEFAULT
	release
	end

SongFlagRoom_Text_Hiker:
	.string "Can you hear how the wind whistles through this cave? Almost like a melody.$"

SongFlagRoom_Text_TerminalSuccess:
	.string "Access granted. A hidden path opens...$"

SongFlagRoom_Text_TerminalFail:
	.string "Access denied.$"

SongFlagRoom_Text_TerminalAlready:
	.string "The terminal is already unlocked.$"
