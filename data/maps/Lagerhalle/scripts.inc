Lagerhalle_MapScripts::
    map_script MAP_SCRIPT_ON_LOAD, Lagerhalle_OnLoad
    .byte 0


Lagerhalle_OnLoad:
    goto_if_unset FLAG_CTF_FLAG3_CORRECT, Lagerhalle_OnLoad_End

    setmetatile 25, 1, 0x2CB, FALSE
    setmetatile 26, 1, 0x2CC, FALSE
    setmetatile 27, 1, 0x2CD, FALSE
    special DrawWholeMapView

Lagerhalle_OnLoad_End:
    end



Lagerhalle_EventScript_Terminal::
    lock
    faceplayer

    goto_if_set FLAG_CTF_FLAG3_CORRECT, Lagerhalle_Terminal_AlreadyOpen

    msgbox Lagerhalle_Text_TerminalPrompt, MSGBOX_DEFAULT
    closemessage

    setvar VAR_0x8000, 6
    callnative Ctf_FlagTerminal
    waitstate

    goto_if_eq VAR_RESULT, 1, Lagerhalle_Terminal_Correct
    goto Lagerhalle_Terminal_Wrong

Lagerhalle_Terminal_Wrong:
    msgbox Lagerhalle_Text_TerminalWrong, MSGBOX_DEFAULT
    release
    end

Lagerhalle_Terminal_AlreadyOpen:
    msgbox Lagerhalle_Text_TerminalAlreadyOpen, MSGBOX_DEFAULT
    release
    end

Lagerhalle_Terminal_Correct:
    msgbox Lagerhalle_Text_TerminalCorrect, MSGBOX_DEFAULT
    closemessage

    setflag FLAG_CTF_FLAG3_CORRECT

    @ Tiles ändern
    setmetatile 25, 1, 0x2CB, FALSE
    setmetatile 26, 1, 0x2CC, FALSE
    setmetatile 27, 1, 0x2CD, FALSE
    special DrawWholeMapView

    release
    end



Lagerhalle_Text_TerminalPrompt::
    .string "Enter the Flag.$"

Lagerhalle_Text_TerminalWrong::
    .string "ACCESS DENIED.$"

Lagerhalle_Text_TerminalAlreadyOpen::
    .string "The terminal is already\n"
    .string "unlocked.$"

Lagerhalle_Text_TerminalCorrect::
    .string "Access granted. \n"
    .string "Rock removed.$"



@ --------------------
@ Trash
@ --------------------

Lagerhalle_EventScript_Trash::
    msgbox Lagerhalle_Text_Trash, MSGBOX_DEFAULT
    end



@ --------------------
@ Kämpfe
@ --------------------

@ Trainer 1
Lagerhalle_EventScript_Trainer1::
    trainerbattle_single TRAINER_AARON, Lagerhalle_Text_T1_Intro, Lagerhalle_Text_T1_Defeated
	msgbox Lagerhalle_Text_T1_PostBattle, MSGBOX_AUTOCLOSE
    end


@ Trainer 2
Lagerhalle_EventScript_Trainer2::
    trainerbattle_single TRAINER_PERRY, Lagerhalle_Text_T2_Intro, Lagerhalle_Text_T2_Defeated
    msgbox Lagerhalle_Text_T2_PostBattle, MSGBOX_AUTOCLOSE
	end


@ Trainer 3
Lagerhalle_EventScript_Trainer3::
    trainerbattle_single TRAINER_HUGH, Lagerhalle_Text_T3_Intro, Lagerhalle_Text_T3_Defeated
	msgbox Lagerhalle_Text_T3_PostBattle, MSGBOX_AUTOCLOSE
    end



Lagerhalle_EventScript_BlackhansaTrigger_20_3::
    checktrainerflag TRAINER_PHIL
    goto_if_eq VAR_RESULT, 1, Lagerhalle_Blackhansa_End
    lockall
    msgbox Lagerhalle_Text_Blackhansa_Welcome, MSGBOX_DEFAULT
    applymovement LOCALID_BLACKHANSA_BOSS, Lagerhalle_Movement_Blackhansa_From20_3
    waitmovement 0
    goto Lagerhalle_EventScript_Blackhansa_Battle

Lagerhalle_EventScript_BlackhansaTrigger_20_4::
    checktrainerflag TRAINER_PHIL
    goto_if_eq VAR_RESULT, 1, Lagerhalle_Blackhansa_End
    lockall
    msgbox Lagerhalle_Text_Blackhansa_Welcome, MSGBOX_DEFAULT
    applymovement LOCALID_BLACKHANSA_BOSS, Lagerhalle_Movement_Blackhansa_From20_4
    waitmovement 0
    goto Lagerhalle_EventScript_Blackhansa_Battle

Lagerhalle_Blackhansa_End:
    releaseall
    end



Lagerhalle_EventScript_Blackhansa_Battle::
    trainerbattle_single TRAINER_PHIL, Lagerhalle_Text_Blackhansa_Intro, Lagerhalle_Text_Blackhansa_Defeated, Lagerhalle_EventScript_Blackhansa_AfterBattle
    end


Lagerhalle_EventScript_Blackhansa_AfterBattle::
    @ Nur weitermachen, wenn wirklich besiegt
    checktrainerflag TRAINER_PHIL
    goto_if_eq VAR_RESULT, 1, Lagerhalle_Blackhansa_AfterBattle_Abort

    msgbox Lagerhalle_Text_Blackhansa_PostBattle, MSGBOX_DEFAULT

    setflag FLAG_LAGERHALLE_BLACKHANSA_DEFEATED      @ optional (kannst du behalten)
    setflag FLAG_HIDE_LAGERHALLE_BLACKHANSA_BOSS

    playse SE_WARP_IN
    removeobject LOCALID_BLACKHANSA_BOSS
    special DrawWholeMapView

    releaseall
    end

Lagerhalle_Blackhansa_AfterBattle_Abort:
    releaseall
    end



Lagerhalle_Movement_Blackhansa_From20_3:
    walk_up
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    step_end

Lagerhalle_Movement_Blackhansa_From20_4:
    walk_up
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_down
    walk_left
    walk_left
    step_end






@ --------------------
@ Texte
@ --------------------

Lagerhalle_Text_Trash::
    .string "In the trash can, you find an old\n"
    .string "ticket to the Kennedy Space Center\p"
    .string "in Florida. You'd better leave it\n"
    .string "here.$"


Lagerhalle_Text_Blackhansa_Welcome:
    .string "So you made it to me? You won't be\n"
    .string "able to free the professor. Soon\p"
    .string "we'll have control over the entire\n"
    .string "region!$"


