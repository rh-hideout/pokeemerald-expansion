@ -----------------------
@ ANPASSEN:
@ -----------------------
.set TRAINER_ROCKET_DUO, TRAINER_TEAM_ROCKET_1    @ <- dein Trainer aus opponents.h
.set REWARD_TM_ITEM,     ITEM_TM01                @ <- später easy ändern

@ TM-Objekt local_id
.set OBJ_MUSEUM_TM, 6

@ Spawn rechts
.set ROCKET_SPAWN_X,  19
.set JESSIE_SPAWN_Y,  3
.set JAMES_SPAWN_Y,   4
.set ROCKET_ELEV, 0

@ Nach 3 Schritten links stehen sie hier:
.set ROCKET_STAND_X,  16
.set JESSIE_STAND_Y,  3
.set JAMES_STAND_Y,   4

@ Studentin: kommt erst NACH dem Kampf
.set STUDENT_SPAWN_X, 19
.set STUDENT_SPAWN_Y, 3
.set STUDENT_END_X,   16
.set STUDENT_END_Y,   3

@ Drop der TM: 
.set REWARD_X, 16
.set REWARD_Y, 4


Museum_Flag1_MapScripts::
    map_script MAP_SCRIPT_ON_LOAD, Museum_Flag1_OnLoad
    map_script MAP_SCRIPT_ON_TRANSITION, Museum_Flag1_OnTransition
    map_script MAP_SCRIPT_ON_FRAME_TABLE, Museum_Flag1_OnFrame
    .byte 0

Museum_Flag1_OnLoad:
    goto_if_set FLAG_CTF_MUSEUM_DOOR_OPEN, 1f
    end
1:
    call Museum_Flag1_EventScript_ApplyDoorOpen
    end


Museum_Flag1_OnTransition:
    @ Tür anwenden, falls schon geöffnet
    goto_if_set FLAG_CTF_MUSEUM_DOOR_OPEN, 1f
    goto 2f
1:
    call Museum_Flag1_EventScript_ApplyDoorOpen
2:
    call Museum_Flag1_SyncState

    @ Cutscene NICHT hier starten -> nur vorbereiten
    goto_if_set FLAG_CTF_MUSEUM_SCENE_PENDING, Museum_Flag1_PrepCutscene

    setvar VAR_TEMP_0, 1
    end

Museum_Flag1_PrepCutscene:
    setvar VAR_TEMP_0, 0
    end

Museum_Flag1_OnFrame:
    map_script_2 VAR_TEMP_0, 0, Museum_Flag1_EventScript_RocketCutscene
    .2byte 0



Museum_Flag1_PostSceneState:
    clearflag FLAG_HIDE_MUSEUM_FLAG1_STUDENT
    setobjectxy LOCALID_MUSEUM_STUDENT, STUDENT_END_X, STUDENT_END_Y
    end


@ ---------------------------------------------------------
@ State Sync: sorgt beim (Re-)Betreten für korrekten Zustand
@ ---------------------------------------------------------
Museum_Flag1_SyncState:
    @ Wenn Trainer besiegt -> Rockets weg, TM ggf. sichtbar lassen, Student ggf. sichtbar
    checktrainerflag TRAINER_ROCKET_DUO
    goto_if_eq VAR_RESULT, 1, Museum_Flag1_Sync_Defeated



    @ NICHT besiegt: TM verstecken (bis Sieg), Student verstecken bis Szene done
    setflag FLAG_CTF_MUSEUM_TM_TAKEN

    goto_if_set FLAG_CTF_MUSEUM_ROCKET_SCENE_DONE, Museum_Flag1_Sync_StudentDone
    setflag FLAG_HIDE_MUSEUM_FLAG1_STUDENT
    return

Museum_Flag1_Sync_StudentDone:
    clearflag FLAG_HIDE_MUSEUM_FLAG1_STUDENT
    addobject LOCALID_MUSEUM_STUDENT
    setobjectxy LOCALID_MUSEUM_STUDENT, STUDENT_END_X, STUDENT_END_Y
    return

Museum_Flag1_Sync_Defeated:
    setflag FLAG_HIDE_MUSEUM_FLAG1_JESSIE
    setflag FLAG_HIDE_MUSEUM_FLAG1_JAMES
    removeobject LOCALID_MUSEUM_JESSIE
    removeobject LOCALID_MUSEUM_JAMES

    @ Student nur zeigen, wenn Szene done
    goto_if_set FLAG_CTF_MUSEUM_ROCKET_SCENE_DONE, 1f
    setflag FLAG_HIDE_MUSEUM_FLAG1_STUDENT
    goto 2f
1:
    clearflag FLAG_HIDE_MUSEUM_FLAG1_STUDENT
    addobject LOCALID_MUSEUM_STUDENT
    setobjectxy LOCALID_MUSEUM_STUDENT, STUDENT_END_X, STUDENT_END_Y
2:
    return


@ --------------------------------------------------------------------------
@ CUTSCENE nach dem Teleport 
@ --------------------------------------------------------------------------
Museum_Flag1_EventScript_RocketCutscene::
    setvar VAR_TEMP_0, 1
    clearflag FLAG_CTF_MUSEUM_SCENE_PENDING

    lockall

    msgbox Museum_Flag1_Text_FarmerMess, MSGBOX_DEFAULT
    closemessage

    @ Rockets sichtbar machen + Position setzen
    clearflag FLAG_HIDE_MUSEUM_FLAG1_JESSIE
    clearflag FLAG_HIDE_MUSEUM_FLAG1_JAMES

	addobject LOCALID_MUSEUM_JESSIE
    addobject LOCALID_MUSEUM_JAMES

    setobjectxy LOCALID_MUSEUM_JESSIE, ROCKET_SPAWN_X, JESSIE_SPAWN_Y
    setobjectxy LOCALID_MUSEUM_JAMES,  ROCKET_SPAWN_X, JAMES_SPAWN_Y

	special DrawWholeMapView

    turnobject LOCALID_MUSEUM_JESSIE, DIR_WEST
    turnobject LOCALID_MUSEUM_JAMES,  DIR_WEST
    turnobject LOCALID_PLAYER, DIR_EAST

    @ 3 Felder nach links reinlaufen
    applymovement LOCALID_MUSEUM_JESSIE, Museum_Flag1_Movement_RocketEnter
    applymovement LOCALID_MUSEUM_JAMES,  Museum_Flag1_Movement_RocketEnter
    waitmovement 0

    msgbox Museum_Flag1_Text_RocketDialog, MSGBOX_DEFAULT
    closemessage

    @ NICHT verschwinden -> jetzt ansprechbar
    releaseall
    end


Museum_Flag1_Movement_RocketEnter:
    walk_left
    walk_left
    walk_left
    step_end

Museum_Flag1_Movement_RocketLeave:
    walk_right
    walk_right
    walk_right
    step_end

Museum_Flag1_Movement_StudentEnter:
    walk_left
    walk_left
    walk_left
    step_end


@ --------------------------------------------------------------------------
@ ROCKETS: Ansprechen -> Text -> DOUBLE Kampf 
@  -> kein Lock, wenn nur 1 Mon: wir checken vorher und releasen sauber
@ --------------------------------------------------------------------------
Museum_Flag1_EventScript_Rockets::
    lockall
    faceplayer

    @ schon besiegt?
    checktrainerflag TRAINER_ROCKET_DUO
    goto_if_eq VAR_RESULT, 1, Museum_Flag1_Rockets_AlreadyGone

    @ Double-Battle requires 2 Pokémon -> sonst kein trainerbattle call (sonst Softlock-Risiko)
	getpartysize
	goto_if_lt VAR_RESULT, 2, Museum_Flag1_Rockets_NotEnoughMons


    msgbox Museum_Flag1_Text_RocketPreBattle, MSGBOX_DEFAULT
    closemessage

    @ Startet Double Battle; Defeat-Text kommt nach Sieg im Battle,
    @ danach springt das Spiel in AfterBattle.
    trainerbattle_double TRAINER_ROCKET_DUO, Museum_Flag1_Text_RocketBattleStart, Museum_Flag1_Text_RocketDefeated, Museum_Flag1_Text_NotEnoughMons, Museum_Flag1_EventScript_Rockets_AfterBattle
    end

Museum_Flag1_Rockets_NotEnoughMons:
    msgbox Museum_Flag1_Text_NotEnoughMons, MSGBOX_DEFAULT
    releaseall
    end


Museum_Flag1_Rockets_AlreadyGone:
    msgbox Museum_Flag1_Text_RocketsGone, MSGBOX_DEFAULT
    releaseall
    end


@ --------------------------------------------------------------------------
@ Nach Sieg: Rauch + verschwinden + TM drop + Student kommt
@ --------------------------------------------------------------------------
Museum_Flag1_EventScript_Rockets_AfterBattle::
    @ Sicherheitscheck: nur wenn wirklich besiegt
    checktrainerflag TRAINER_ROCKET_DUO
    goto_if_eq VAR_RESULT, 0, Museum_Flag1_Rockets_End

    @ Rauch/Poof-Illusion
    playse SE_FLEE
	dofieldeffectsparkle ROCKET_STAND_X, JESSIE_STAND_Y, ROCKET_ELEV
	dofieldeffectsparkle ROCKET_STAND_X, JAMES_STAND_Y,  ROCKET_ELEV
	waitfieldeffect FLDEFF_SPARKLE

    @ rauslaufen und dann despawn
    applymovement LOCALID_MUSEUM_JESSIE, Museum_Flag1_Movement_RocketLeave
    applymovement LOCALID_MUSEUM_JAMES,  Museum_Flag1_Movement_RocketLeave
    waitmovement 0

    setflag FLAG_HIDE_MUSEUM_FLAG1_JESSIE
    setflag FLAG_HIDE_MUSEUM_FLAG1_JAMES
    removeobject LOCALID_MUSEUM_JESSIE
    removeobject LOCALID_MUSEUM_JAMES

    @ TM drop (Itemball erscheint)
	clearflag FLAG_CTF_MUSEUM_TM_TAKEN
	addobject OBJ_MUSEUM_TM
    special DrawWholeMapView

    @ Jetzt Studentin rein + Dialog
    clearflag FLAG_HIDE_MUSEUM_FLAG1_STUDENT
	addobject LOCALID_MUSEUM_STUDENT
    setobjectxy LOCALID_MUSEUM_STUDENT, STUDENT_SPAWN_X, STUDENT_SPAWN_Y
	special DrawWholeMapView
    turnobject LOCALID_MUSEUM_STUDENT, DIR_WEST

    applymovement LOCALID_MUSEUM_STUDENT, Museum_Flag1_Movement_StudentEnter
    waitmovement 0

    msgbox Museum_Flag1_Text_StudentDialog, MSGBOX_DEFAULT
    closemessage

    setflag FLAG_CTF_MUSEUM_ROCKET_SCENE_DONE

Museum_Flag1_Rockets_End:
    releaseall
    end


@ --------------------------------------------------------------------------
@ REWARD: TM aufsammeln (kein callstd/finditem nesting -> safer)
@ --------------------------------------------------------------------------
Museum_Flag1_EventScript_RewardTM::
    lock
    goto_if_set FLAG_CTF_MUSEUM_TM_TAKEN, Museum_Flag1_RewardTM_Already

    giveitem REWARD_TM_ITEM, 1
    setflag FLAG_CTF_MUSEUM_TM_TAKEN

    removeobject OBJ_MUSEUM_TM
    special DrawWholeMapView

    release
    end

Museum_Flag1_RewardTM_Already:
    release
    end


@ --------------------------------------------------------------------------
@ TERMINAL: Gym 1 Flag prüfen
@ --------------------------------------------------------------------------
Museum_Flag1_EventScript_Terminal::
    lock
    faceplayer

    goto_if_set FLAG_CTF_MUSEUM_DOOR_OPEN, Museum_Flag1_Terminal_AlreadyOpen

    msgbox Museum_Flag1_Text_TerminalPrompt, MSGBOX_DEFAULT
    closemessage

    setvar VAR_0x8000, 1
    callnative Ctf_FlagTerminal
    waitstate

    goto_if_eq VAR_RESULT, 1, Museum_Flag1_Terminal_Correct
    goto Museum_Flag1_Terminal_Wrong


Museum_Flag1_Terminal_Wrong:
    msgbox Museum_Flag1_Text_TerminalWrong, MSGBOX_DEFAULT
    release
    end

Museum_Flag1_Terminal_AlreadyOpen:
    msgbox Museum_Flag1_Text_TerminalAlreadyOpen, MSGBOX_DEFAULT
    release
    end

Museum_Flag1_Terminal_Correct:
    msgbox Museum_Flag1_Text_TerminalCorrect, MSGBOX_DEFAULT
    closemessage

    setflag FLAG_CTF_MUSEUM_DOOR_OPEN
    call Museum_Flag1_EventScript_ApplyDoorOpen
    special DrawWholeMapView

    release
    end


@ --------------------------------------------------------------------------
@ TÜR 3x2 METATILES
@ Top-Left:
@ --------------------------------------------------------------------------
Museum_Flag1_EventScript_ApplyDoorOpen::
    setmetatile 9,  0, 0x0261, 0
    setmetatile 10,  0, 0x0207, 0
    setmetatile 11,  0, 0x0257, 0

    setmetatile 9, 1, 0x0262, 0
    setmetatile 10, 1, 0x020F, 0
    setmetatile 11, 1, 0x025F, 0
    return


@--------------------------------------------------------------------------
@ Heal
@--------------------------------------------------------------------------

Museum_Flag1_EventScript_HealGuy::
    lock
    faceplayer
    msgbox Museum_Flag1_Text_Heal, MSGBOX_DEFAULT
    closemessage

    playfanfare MUS_HEAL
    special HealPlayerParty
    waitfanfare

    release
    end


@--------------------------------------------------------------------------
@ Schilder
@--------------------------------------------------------------------------


Museum_Flag1_EventScript_Sign_M1::
	msgbox Museum_Flag1_Text_Sign_M, MSGBOX_DEFAULT
	end

Museum_Flag1_EventScript_Sign_X::
	msgbox Museum_Flag1_Text_Sign_X, MSGBOX_DEFAULT
	end

Museum_Flag1_EventScript_Sign_S::
	msgbox Museum_Flag1_Text_Sign_S, MSGBOX_DEFAULT
	end

Museum_Flag1_EventScript_Sign_Q::
	msgbox Museum_Flag1_Text_Sign_Q, MSGBOX_DEFAULT
	end

Museum_Flag1_EventScript_Sign_N::
	msgbox Museum_Flag1_Text_Sign_N, MSGBOX_DEFAULT
	end

Museum_Flag1_EventScript_Sign_D::
	msgbox Museum_Flag1_Text_Sign_D, MSGBOX_DEFAULT
	end

Museum_Flag1_EventScript_Sign_M2::
	msgbox Museum_Flag1_Text_Sign_M, MSGBOX_DEFAULT
	end

Museum_Flag1_EventScript_Sign_Roman::
	msgbox Museum_Flag1_Text_Roman, MSGBOX_DEFAULT
	end




@ --------------------------------------------------------------------------
@ TEXTE
@ --------------------------------------------------------------------------
Museum_Flag1_Text_FarmerMess:
    .string "PROF. FARMER: What's all\n"
    .string "this mess?$"

Museum_Flag1_Text_RocketDialog:
    .string "JESSIE: Prepare for trouble!\n"
    .string "JAMES: And make it double!\p"
    .string "PROF. FARMER: Cut that crap\n"
    .string "who are you?\p"
    .string "JESSIE: How rude!\p"
    .string "JAMES: We are TEAM ROCKET and\n"
	.string "were hired by Business Informatics\p"
    .string "to steal your MATHALYZER!$"

Museum_Flag1_Text_RocketPreBattle:
    .string "JESSIE: You want it back?\n"
    .string "Too bad for you, losers!\p"
    .string "JAMES: Let's see what you've got!$"

@ Intro-Text NUR für den Battle-Start (weil trainerbattle_double einen braucht)
Museum_Flag1_Text_RocketBattleStart:
    .string "TEAM ROCKET: Let's battle!$"

@ Defeat-Text, der nach deinem Sieg im Battle angezeigt wird
Museum_Flag1_Text_RocketDefeated:
    .string "JESSIE: Looks like we're...\n"
    .string "JAMES: blasting off again!$"


Museum_Flag1_Text_RocketsGone:
    .string "They already fled.$"

Museum_Flag1_Text_StudentDialog:
    .string "They've barricaded the door.\n"
    .string "How are we going to get out\n"
    .string "of here?$"

Museum_Flag1_Text_NotEnoughMons:
    .string "You need at least two POKéMON to battle!$"

Museum_Flag1_Text_TerminalPrompt:
    .string "TERMINAL: Enter the code.$"

Museum_Flag1_Text_TerminalWrong:
    .string "TERMINAL: Access denied.$"

Museum_Flag1_Text_TerminalCorrect:
    .string "TERMINAL: Code accepted.\n"
    .string "Opening hidden door...$"

Museum_Flag1_Text_TerminalAlreadyOpen:
    .string "TERMINAL: Door already opened.$"

Museum_Flag1_Text_Heal:
    .string "Here, let me heal your POKéMON.$"


Museum_Flag1_Text_Sign_M:
	.string "M$"

Museum_Flag1_Text_Sign_X:
	.string "X$"

Museum_Flag1_Text_Sign_S:
	.string "S$"

Museum_Flag1_Text_Sign_Q:
	.string "Q$"

Museum_Flag1_Text_Sign_N:
	.string "N$"

Museum_Flag1_Text_Sign_D:
	.string "D$"

Museum_Flag1_Text_Roman:
    .string "The only picture that TEAM ROCKET\n"
	.string "did not destroy. It shows a Roman\p"
	.string "general.$"



