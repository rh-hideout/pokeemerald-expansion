Route19_Cave_hns_MapScripts::
	.byte 0

Route19Cave_EventScript_Kyogre::
	lock
	faceplayer
	playmoncry SPECIES_KYOGRE, CRY_MODE_ENCOUNTER
	waitmoncry
	seteventmon SPECIES_KYOGRE, 70
	special BattleSetup_StartLegendaryBattle
waitstate
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, Route19Cave_EventScript_KyogreRan
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_ROUTE19CAVEKYOGRE
	setflag FLAG_HIDE_KYOGRE
	fadescreenswapbuffers FADE_FROM_BLACK
	release
	end

Route19Cave_EventScript_KyogreRan::
	release
	end