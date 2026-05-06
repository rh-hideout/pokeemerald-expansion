SouthernIsland_Interior_hns_MapScripts::
	.byte 0

SouthernIsland_Interior_hns_EventScript_Latios::
	lock
	faceplayer
	playmoncry SPECIES_LATIOS, CRY_MODE_ENCOUNTER
	waitmoncry
	seteventmon SPECIES_LATIOS, 50
	special BattleSetup_StartLegendaryBattle
	waitstate
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, SouthernIsland_Interior_hns_EventScript_LatiosRan
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_SOUTHERN_ISLAND_INTERIOR_HNS_LATIOS
	setflag FLAG_HIDE_LATIOS
	fadescreenswapbuffers FADE_FROM_BLACK
	release
	end

SouthernIsland_Interior_hns_EventScript_LatiosRan::
	release
	end


SouthernIsland_Interior_hns_EventScript_Latias::
	lock
	faceplayer
	playmoncry SPECIES_LATIAS, CRY_MODE_ENCOUNTER
	waitmoncry
	seteventmon SPECIES_LATIAS, 50
	special BattleSetup_StartLegendaryBattle
	waitstate
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, SouthernIsland_Interior_hns_EventScript_LatiasRan
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_SOUTHERN_ISLAND_INTERIOR_HNS_LATIAS
	setflag FLAG_HIDE_LATIAS
	fadescreenswapbuffers FADE_FROM_BLACK
	release
	end

SouthernIsland_Interior_hns_EventScript_LatiasRan::
	release
	end
