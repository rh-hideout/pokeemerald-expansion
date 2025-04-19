# 1 "data/maps/MarineCave_End/scripts.pory"

# 2 "data/maps/MarineCave_End/scripts.pory"
.set LOCALID_KYOGRE, 1
# 3 "data/maps/MarineCave_End/scripts.pory"

# 4 "data/maps/MarineCave_End/scripts.pory"
MarineCave_End_MapScripts::
# 5 "data/maps/MarineCave_End/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, MarineCave_End_OnResume
# 6 "data/maps/MarineCave_End/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, MarineCave_End_OnTransition
# 7 "data/maps/MarineCave_End/scripts.pory"
	.byte 0
# 8 "data/maps/MarineCave_End/scripts.pory"

# 9 "data/maps/MarineCave_End/scripts.pory"
MarineCave_End_OnResume:
# 10 "data/maps/MarineCave_End/scripts.pory"
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, MarineCave_End_EventScript_TryRemoveKyogre
# 11 "data/maps/MarineCave_End/scripts.pory"
	end
# 12 "data/maps/MarineCave_End/scripts.pory"

# 13 "data/maps/MarineCave_End/scripts.pory"
MarineCave_End_EventScript_TryRemoveKyogre::
# 14 "data/maps/MarineCave_End/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 15 "data/maps/MarineCave_End/scripts.pory"
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
# 16 "data/maps/MarineCave_End/scripts.pory"
	removeobject LOCALID_KYOGRE
# 17 "data/maps/MarineCave_End/scripts.pory"
	return
# 18 "data/maps/MarineCave_End/scripts.pory"

# 19 "data/maps/MarineCave_End/scripts.pory"
MarineCave_End_OnTransition:
# 20 "data/maps/MarineCave_End/scripts.pory"
	call_if_unset FLAG_DEFEATED_KYOGRE, MarineCave_End_EventScript_ShowKyogre
# 21 "data/maps/MarineCave_End/scripts.pory"
	end
# 22 "data/maps/MarineCave_End/scripts.pory"

# 23 "data/maps/MarineCave_End/scripts.pory"
MarineCave_End_EventScript_ShowKyogre::
# 24 "data/maps/MarineCave_End/scripts.pory"
	clearflag FLAG_HIDE_MARINE_CAVE_KYOGRE
# 25 "data/maps/MarineCave_End/scripts.pory"
	setvar VAR_TEMP_1, 1
# 26 "data/maps/MarineCave_End/scripts.pory"
	return
# 27 "data/maps/MarineCave_End/scripts.pory"

# 28 "data/maps/MarineCave_End/scripts.pory"
MarineCave_End_EventScript_Kyogre::
# 29 "data/maps/MarineCave_End/scripts.pory"
	lockall
# 30 "data/maps/MarineCave_End/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
# 31 "data/maps/MarineCave_End/scripts.pory"
	waitmovement 0
# 32 "data/maps/MarineCave_End/scripts.pory"
	applymovement LOCALID_KYOGRE, MarineCave_End_Movement_KyogreApproach
# 33 "data/maps/MarineCave_End/scripts.pory"
	waitmovement 0
# 34 "data/maps/MarineCave_End/scripts.pory"
	waitse
# 35 "data/maps/MarineCave_End/scripts.pory"
	playmoncry SPECIES_KYOGRE, CRY_MODE_ENCOUNTER
# 36 "data/maps/MarineCave_End/scripts.pory"
	delay 40
# 37 "data/maps/MarineCave_End/scripts.pory"
	waitmoncry
# 38 "data/maps/MarineCave_End/scripts.pory"
	setvar VAR_LAST_TALKED, LOCALID_KYOGRE
# 39 "data/maps/MarineCave_End/scripts.pory"
	setwildbattle SPECIES_KYOGRE, 70
# 40 "data/maps/MarineCave_End/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 41 "data/maps/MarineCave_End/scripts.pory"
	special BattleSetup_StartLegendaryBattle
# 42 "data/maps/MarineCave_End/scripts.pory"
	waitstate
# 43 "data/maps/MarineCave_End/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 44 "data/maps/MarineCave_End/scripts.pory"
	setvar VAR_TEMP_1, 0
# 45 "data/maps/MarineCave_End/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 46 "data/maps/MarineCave_End/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, MarineCave_End_EventScript_DefeatedKyogre
# 47 "data/maps/MarineCave_End/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, MarineCave_End_EventScript_RanFromKyogre
# 48 "data/maps/MarineCave_End/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, MarineCave_End_EventScript_RanFromKyogre
# 49 "data/maps/MarineCave_End/scripts.pory"
	setvar VAR_SHOULD_END_ABNORMAL_WEATHER, 1
# 50 "data/maps/MarineCave_End/scripts.pory"
	setflag FLAG_DEFEATED_KYOGRE
# 51 "data/maps/MarineCave_End/scripts.pory"
	releaseall
# 52 "data/maps/MarineCave_End/scripts.pory"
	end
# 53 "data/maps/MarineCave_End/scripts.pory"

# 54 "data/maps/MarineCave_End/scripts.pory"
MarineCave_End_EventScript_DefeatedKyogre::
# 55 "data/maps/MarineCave_End/scripts.pory"
	setvar VAR_SHOULD_END_ABNORMAL_WEATHER, 1
# 56 "data/maps/MarineCave_End/scripts.pory"
	setflag FLAG_DEFEATED_KYOGRE
# 57 "data/maps/MarineCave_End/scripts.pory"
	goto Common_EventScript_RemoveStaticPokemon
# 58 "data/maps/MarineCave_End/scripts.pory"
	end
# 59 "data/maps/MarineCave_End/scripts.pory"

# 60 "data/maps/MarineCave_End/scripts.pory"
MarineCave_End_EventScript_RanFromKyogre::
# 61 "data/maps/MarineCave_End/scripts.pory"
	setvar VAR_0x8004, SPECIES_KYOGRE
# 62 "data/maps/MarineCave_End/scripts.pory"
	goto Common_EventScript_LegendaryFlewAway
# 63 "data/maps/MarineCave_End/scripts.pory"
	end
# 64 "data/maps/MarineCave_End/scripts.pory"

# 65 "data/maps/MarineCave_End/scripts.pory"
MarineCave_End_Movement_KyogreApproach:
# 66 "data/maps/MarineCave_End/scripts.pory"
	init_affine_anim
# 67 "data/maps/MarineCave_End/scripts.pory"
	walk_down_start_affine
# 68 "data/maps/MarineCave_End/scripts.pory"
	delay_16
# 69 "data/maps/MarineCave_End/scripts.pory"
	delay_16
# 70 "data/maps/MarineCave_End/scripts.pory"
	walk_down_affine
# 71 "data/maps/MarineCave_End/scripts.pory"
	delay_16
# 72 "data/maps/MarineCave_End/scripts.pory"
	delay_16
# 73 "data/maps/MarineCave_End/scripts.pory"
	walk_down_affine
# 74 "data/maps/MarineCave_End/scripts.pory"
	step_end
