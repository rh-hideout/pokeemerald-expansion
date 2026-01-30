@ Einfach später änderbar:
#define HEVL_TM ITEM_TM01

Museum2_flag1_MapScripts::
	.byte 0

Museum2_flag1_EventScript_ProfHevl::
	lock
	faceplayer

	goto_if_set FLAG_BADGE01_GET, Museum2_flag1_EventScript_ProfHevl_After

	msgbox Museum2_flag1_Text_Intro, MSGBOX_DEFAULT

	@ Verlustschutz: kein Whiteout, Script läuft danach weiter
	setflag FLAG_NO_WHITEOUT
	trainerbattle_no_intro TRAINER_PROF_HEVL, Museum2_flag1_Text_Defeat
	clearflag FLAG_NO_WHITEOUT

	@ Check ob verloren
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_LOST
	goto_if_eq Museum2_flag1_EventScript_ProfHevl_Lost

	@ Gewonnen: Badge + TM
	setflag FLAG_BADGE01_GET
	msgbox Museum2_flag1_Text_Badge, MSGBOX_DEFAULT

	giveitem HEVL_TM, 1
	msgbox Museum2_flag1_Text_TM, MSGBOX_DEFAULT

	release
	end

Museum2_flag1_EventScript_ProfHevl_Lost::
	msgbox Museum2_flag1_Text_Lost, MSGBOX_DEFAULT
	special HealPlayerParty
	release
	end

Museum2_flag1_EventScript_ProfHevl_After::
	msgbox Museum2_flag1_Text_After, MSGBOX_DEFAULT
	release
	end
