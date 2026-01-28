Testmap_MapScripts::
	.byte 0

Testmap_EventScript_TutorialNpc::
	lock
	faceplayer
	checkflag FLAG_CTF_TUTORIAL_DONE
	goto_if_set Testmap_TutorialNpc_After
	msgbox Testmap_Text_Hint, MSGBOX_NPC
	release
	end

Testmap_TutorialNpc_After:
	msgbox Testmap_Text_After, MSGBOX_NPC
	release
	end

Testmap_EventScript_TutorialTerminal::
	lock
	faceplayer

	checkflag FLAG_CTF_TUTORIAL_DONE
	goto_if_set Testmap_Terminal_Already

	msgbox Testmap_Text_EnterFlag, MSGBOX_DEFAULT

	@ Wichtig: 9 = Tutorial-ID (siehe C-Code-Anpassung)
	setvar VAR_0x8000, 9
	callnative Ctf_FlagTerminal
	waitstate

	compare VAR_RESULT, 1
	goto_if_eq Testmap_Terminal_Ok

	msgbox Testmap_Text_Wrong, MSGBOX_DEFAULT
	release
	end

Testmap_Terminal_Ok:
	setflag FLAG_CTF_TUTORIAL_DONE
	msgbox Testmap_Text_Ok, MSGBOX_DEFAULT

	@ Sofort entfernen (LocalIds aus Porymap!)
	removeobject 3  @ Blocker
	removeobject 2  @ Terminal

	release
	end

Testmap_Terminal_Already:
	msgbox Testmap_Text_Already, MSGBOX_DEFAULT
	release
	end

Testmap_EventScript_BlockNpc::
	msgbox Testmap_Text_Block, MSGBOX_NPC
	release
	end

Testmap_Text_Block:
	.string "This guy is sleeping on the stairs.\n"
	.string "I can't get past him.$"

Testmap_Text_Hint:
	.string "The man sleeps all day. Maybe you can\n" 
	.string "wake him up with a loud BANG?.$"

Testmap_Text_After:
	.string "You did it!.$"

Testmap_Text_EnterFlag:
	.string "TERMINAL: Enter flag.$"

Testmap_Text_Wrong:
	.string "TERMINAL: Incorrect.$"

Testmap_Text_Ok:
	.string "TERMINAL: Correct. <There is a very \n"
	.string "loud BANG coming from the terminal>.$"

Testmap_Text_Already:
	.string "TERMINAL: Already cleared.$"
