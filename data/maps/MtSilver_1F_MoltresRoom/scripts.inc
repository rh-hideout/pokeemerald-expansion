.set LOCALID_MTSILVER_MOLTRES, 1

MtSilver_1F_MoltresRoom_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtSilver_1F_MoltresRoom_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

MtSilver_1F_MoltresRoom_OnTransition: 
	callnative SetTimeBasedEncounters
	end


MtSilver_1F_MoltresRoom_EventScript_Moltres::
	lock
	faceplayer
	playmoncry SPECIES_MOLTRES, CRY_MODE_ENCOUNTER
	msgbox SeafoamIslands_B1F_Text_ArticunoBattle
	delay 40
	waitmoncry
	seteventmon SPECIES_MOLTRES, 50
	special BattleSetup_StartLegendaryBattle
	waitstate
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, MtSilver_1F_MoltresRoom_EventScript_MoltresRan
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_MTSILVER_MOLTRES
	setflag FLAG_HIDE_MOLTRES
	fadescreenswapbuffers FADE_FROM_BLACK
	release
	end

MtSilver_1F_MoltresRoom_EventScript_MoltresRan::
	release
	end
