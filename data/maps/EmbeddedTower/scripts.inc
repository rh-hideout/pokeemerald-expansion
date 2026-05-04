.set LOCALID_EMBEDDEDRAYQUAZA, 1
.set LOCALID_EMBEDDEDGROUDON, 1
.set LOCALID_EMBEDDEDKYOGRE, 1

EmbeddedTower_MapScripts::
	.byte 0

EmbeddedTower_EventScript_Groudon::
	lock
	faceplayer
	playmoncry SPECIES_GROUDON, CRY_MODE_ENCOUNTER
	waitmoncry
	seteventmon SPECIES_GROUDON, 70
	special BattleSetup_StartLegendaryBattle
waitstate
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, EmbeddedTower_EventScript_GroudonRan
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_EMBEDDEDGROUDON
	setflag FLAG_HIDE_GROUDON
	fadescreenswapbuffers FADE_FROM_BLACK
	release
	end

EmbeddedTower_EventScript_GroudonRan::
	release
	end

EmbeddedTower_EventScript_Kyogre::
	lock
	faceplayer
	playmoncry SPECIES_KYOGRE, CRY_MODE_ENCOUNTER
	waitmoncry
	seteventmon SPECIES_KYOGRE, 70
	special BattleSetup_StartLegendaryBattle
waitstate
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, EmbeddedTower_EventScript_KyogreRan
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_EMBEDDEDKYOGRE
	setflag FLAG_HIDE_KYOGRE
	fadescreenswapbuffers FADE_FROM_BLACK
	release
	end

EmbeddedTower_EventScript_KyogreRan::
	release
	end


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
