Testmap_MapScripts::
	.byte 0

Testmap_EventScript_TutorialNpc::
	lock
	faceplayer
	goto_if_set FLAG_CTF_TUTORIAL_DONE, Testmap_TutorialNpc_After
	msgbox Testmap_Text_Hint, MSGBOX_DEFAULT
	release
	end

Testmap_TutorialNpc_After:
	msgbox Testmap_Text_After, MSGBOX_DEFAULT
	release
	end

Testmap_EventScript_TutorialTerminal::
	lock
	faceplayer
	goto_if_set FLAG_CTF_TUTORIAL_DONE, Testmap_Terminal_Already

	msgbox Testmap_Text_EnterFlag, MSGBOX_DEFAULT

	setvar VAR_0x8000, 9
	callnative Ctf_FlagTerminal
	waitstate

	compare VAR_RESULT, 1
	goto_if_eq Testmap_Terminal_Ok

	msgbox Testmap_Text_Wrong, MSGBOX_DEFAULT
	release
	end

Testmap_Terminal_Ok:
    msgbox Testmap_Text_Ok, MSGBOX_DEFAULT

    applymovement LOCALID_TESTMAP_BLOCKER, Testmap_Movement_SleepStep
    waitmovement 0

    msgbox Testmap_Text_WokeUp, MSGBOX_DEFAULT

    applymovement LOCALID_TESTMAP_BLOCKER, Testmap_Movement_SleepLeave
    waitmovement 0

    removeobject LOCALID_TESTMAP_BLOCKER
    removeobject LOCALID_TESTMAP_TERMINAL

	setflag FLAG_CTF_TUTORIAL_DONE

    release
    end


Testmap_Terminal_Already:
	msgbox Testmap_Text_Already, MSGBOX_DEFAULT
	release
	end

Testmap_EventScript_BlockNpc::
    lock
    msgbox Testmap_Text_Block, MSGBOX_DEFAULT
    applymovement LOCALID_TESTMAP_BLOCKER, Testmap_Movement_FaceDown
    waitmovement 0
    release
    end

Testmap_Movement_FaceDown:
    face_down
    step_end

Testmap_Movement_SleepStep:
	walk_fast_down
	face_left
	delay_16
	face_right
	delay_16
	step_end


Testmap_Movement_SleepLeave:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

Testmap_EventScript_BlockRoute102::
    goto_if_set FLAG_CTF_GYM1_DEFEATED, Testmap_BlockRoute102_End

    lockall
    msgbox Testmap_Text_GoUniversityFirst, MSGBOX_DEFAULT
    closemessage

    applymovement LOCALID_PLAYER, Testmap_Movement_TurnAndStepRight
    waitmovement 0

    releaseall
Testmap_BlockRoute102_End:
    end

Testmap_Movement_TurnAndStepRight:
    face_right
    walk_right
    step_end

Testmap_EventScript_ItemBall_Potion::
    lock
    checkitemspace ITEM_POTION, 1
    goto_if_eq VAR_RESULT, 0, Testmap_NoRoom
    giveitem ITEM_POTION, 1
    setflag FLAG_TESTMAP_POTION
    removeobject LOCALID_TESTMAP_ITEMBALL
    release
    end

Testmap_NoRoom:
    msgbox Testmap_Text_NoRoom, MSGBOX_DEFAULT
    release
    end

Testmap_Text_NoRoom:
    .string "Your bag is full.$"

Testmap_Text_GoUniversityFirst:
    .string "I should go to the university first.$"


Testmap_Text_Block:
	.string "This guy is sleeping on the stairs.\n"
	.string "I can't get past him.$"

Testmap_Text_Hint:
	.string "The man sleeps all day. Maybe you can\n" 
	.string "wake him up with a loud BANG?$"

Testmap_Text_After:
	.string "You did it!$"

Testmap_Text_EnterFlag:
	.string "TERMINAL: Enter flag.$"

Testmap_Text_Wrong:
	.string "TERMINAL: Incorrect.$"

Testmap_Text_Ok:
	.string "TERMINAL: Correct. <There is a very \n"
	.string "loud BANG coming from the terminal>$"

Testmap_Text_Already:
	.string "TERMINAL: Already cleared.$"

Testmap_Text_WokeUp:
	.string "SLEEPYHEAD: Holy shit!\n"
	.string "What was that?!$"
