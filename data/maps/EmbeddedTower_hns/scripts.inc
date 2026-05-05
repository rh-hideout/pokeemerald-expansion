EmbeddedTower_hns_MapScripts::
	.byte 0



EmbeddedTower_EventScript_Rayquaza::
	lock
	faceplayer
	playmoncry SPECIES_RAYQUAZA, CRY_MODE_ENCOUNTER
	waitmoncry
	seteventmon SPECIES_RAYQUAZA, 70
	special BattleSetup_StartLegendaryBattle
waitstate
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, EmbeddedTower_EventScript_RayquazaRan
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_EMBEDDEDRAYQUAZA
	setflag FLAG_HIDE_RAYQUAZA
	fadescreenswapbuffers FADE_FROM_BLACK
	release
	end

EmbeddedTower_EventScript_RayquazaRan::
	release
	end
