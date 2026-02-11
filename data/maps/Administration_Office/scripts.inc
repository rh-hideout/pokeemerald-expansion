Administration_Office_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Administration_Office_OnLoad
	.byte 0

Administration_Office_OnLoad:
	setvar VAR_TEMP_0, 0
	end

Administration_Office_EventScript_EmptyRoom::
	setvar VAR_TEMP_0, 1
	goto_if_set FLAG_CTF_ADMIN_OFFICE_INTRO, Administration_Office_Empty_End
	lockall
	msgbox Administration_Office_Text_EmptyOffice, MSGBOX_DEFAULT
	setflag FLAG_CTF_ADMIN_OFFICE_INTRO
	releaseall

Administration_Office_Empty_End:
	end

Administration_Office_EventScript_Terminal::
	lock
	faceplayer
	goto_if_set FLAG_CTF_ENROLLMENT_TERMINAL_DONE, Administration_Office_Terminal_Already
	msgbox Administration_Office_Text_TerminalIntro, MSGBOX_DEFAULT
	setvar VAR_0x8000, 10
	callnative Ctf_FlagTerminal
	waitstate
	compare VAR_RESULT, 1
	goto_if_eq Administration_Office_Terminal_Correct
	msgbox Administration_Office_Text_TerminalWrong, MSGBOX_DEFAULT
	release
	end

Administration_Office_Terminal_Correct:
	msgbox Administration_Office_Text_TerminalCorrect, MSGBOX_DEFAULT
	setflag FLAG_CTF_ENROLLMENT_TERMINAL_DONE
	release
	end

Administration_Office_Terminal_Already:
	msgbox Administration_Office_Text_TerminalAlready, MSGBOX_DEFAULT
	release
	end

Administration_Office_Text_EmptyOffice:
	.string "Hmm… no one's here.\p"
	.string "But I was told I have to enroll by today.$"

Administration_Office_Text_TerminalIntro:
	.string "CTF ENROLLMENT TERMINAL - DHBW\n"
	.string "User: {PLAYER}\p"
	.string "Please enter your matching\n"
	.string "matriculation number.$"

Administration_Office_Text_TerminalWrong:
	.string "TERMINAL: Incorrect.$"

Administration_Office_Text_TerminalCorrect:
	.string "TERMINAL: Correct.$"

Administration_Office_Text_TerminalAlready:
	.string "TERMINAL: Access already granted.$"
