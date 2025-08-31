
\n = New Box
\p = New Line in same box
\l = New Line in same box but scrolling down?

Route1_MapScripts::

Route1_EventScript_Greg::
	lockall
	trainerbattle_single TRAINER_GREG_1, Route1_Text_GregIntro Route1_EventScript_GregDefeated Route1_EventScript_GregRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route1_EventScript_GregRematch
	setvar VAR_0x8004, TRAINER_GREG_1
	specialvar VAR_RESULT, IsTrainerRegistered
	goto_if_eq VAR_RESULT, FALSE, Route1_EventScript_GregTryRegister
	msgbox Route1_Text_GregPostBattle, MSGBOX_DEFAULT
	release
	end


Route1_EventScript_GregRegisterMatchCall::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	goto_if_set FLAG_HAS_MATCH_CALL, Route1_EventScript_GregRegisterMatchCall
	release
	end


Route_EventScript_GregRegisterMatchCall::
	msgbox Route1_EventScript_GregRegisterShort, MSGBOX_DEFAULT
	register_matchcall TRAINER_GREG_1
	release
	end


Route1_EventScript_GregTryRegister::
	goto_if_set FLAG_HAS_MATCH_CALL, Route1_EventScript_GregRegister
	msgbox Route1_Text_GregPostBattle, MSGBOX_DEFAULT
	release
	end


Route1_EventScript_GregRegister::
	msgbox Route1_Text_GregRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_GREG_1
	release
	end


Route1_EventScript_GregRematch::
	trainerbattle_rematch TRAINER_GREG_1, Route1_Text_GregRematchIntro, Route1_Text_GregRematchDefeated
	msgbox Route1_Text_GregRematchPostBattle, MSGBOX_AUTOCLOSE
	end

