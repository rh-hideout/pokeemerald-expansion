@ Einfach später änderbar in eine andere TM oder anderes Item als Reward für Sieg. 
@ Auch Textblock ganz unten nicht vergessen!
#define HEVL_TM ITEM_TM01

Museum2_Flag1_MapScripts::
	.byte 0

Museum2_Flag1_EventScript_Hevl::
	lock
	faceplayer

	@ Schon gewonnen?
	goto_if_set FLAG_BADGE01_GET, Museum2_Flag1_After

	msgbox Museum2_Flag1_Text_Intro, MSG_FACE

	@ Verlustschutz: kein Whiteout
	setflag B_FLAG_NO_WHITEOUT
	trainerbattle_no_intro TRAINER_PROF_HEVL, Museum2_Flag1_Text_Defeat
	clearflag B_FLAG_NO_WHITEOUT

	@ Check ob verloren
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_LOST
	goto_if_eq Museum2_Flag1_Lost

	@ Sieg: Badge + Fanfare + TM
	setflag FLAG_BADGE01_GET

	msgbox Museum2_Flag1_Text_Win, MSG_FACE
	closemessage

	playfanfare MUS_OBTAIN_BADGE
	msgbox Museum2_Flag1_Text_ReceivedBadge, MSGBOX_DEFAULT
	waitfanfare
	closemessage

	giveitem HEVL_TM, 1
	msgbox Museum2_Flag1_Text_TM, MSGBOX_DEFAULT

	release
	end

Museum2_Flag1_Lost::
	msgbox Museum2_Flag1_Text_Lost, MSG_FACE
	special HealPlayerParty
	release
	end

Museum2_Flag1_After::
	msgbox Museum2_Flag1_Text_After, MSG_FACE
	release
	end


Museum2_Flag1_Text_Intro::
	.string "You saved XX and thus ensured\n"
	.string "our mathematical superiority.\p"
	.string "You can now take your exam with\n"
	.string "me to prove yourself worthy.$"

Museum2_Flag1_Text_Defeat::
	.string "PROF. HEVL: Correct... enough.$"

Museum2_Flag1_Text_Lost::
	.string "Not bad, but you need to try again.$"

Museum2_Flag1_Text_Win::
	.string "PROF. HEVL: Excellent!\n"
	.string "You proved yourself worthy.\p"
	.string "Take this, the FIRST BADGE.$"

Museum2_Flag1_Text_ReceivedBadge::
	.string "You received the FIRST BADGE!$"

Museum2_Flag1_Text_TM::
	.string "You received a TM!$"

Museum2_Flag1_Text_After::
	.string "Our proof is complete.\n"
	.string "Keep studying.$"

