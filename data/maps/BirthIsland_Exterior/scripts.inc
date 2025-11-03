# 1 "data/maps/BirthIsland_Exterior/scripts.pory"

# 2 "data/maps/BirthIsland_Exterior/scripts.pory"
BirthIsland_Exterior_MapScripts::
# 3 "data/maps/BirthIsland_Exterior/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, BirthIsland_Exterior_OnTransition
# 4 "data/maps/BirthIsland_Exterior/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, BirthIsland_Exterior_OnResume
# 5 "data/maps/BirthIsland_Exterior/scripts.pory"
	map_script MAP_SCRIPT_ON_RETURN_TO_FIELD, BirthIsland_Exterior_OnReturnToField
# 6 "data/maps/BirthIsland_Exterior/scripts.pory"
	.byte 0
# 7 "data/maps/BirthIsland_Exterior/scripts.pory"

# 8 "data/maps/BirthIsland_Exterior/scripts.pory"
BirthIsland_Exterior_OnReturnToField:
# 9 "data/maps/BirthIsland_Exterior/scripts.pory"
	special SetDeoxysRockPalette
# 10 "data/maps/BirthIsland_Exterior/scripts.pory"
	end
# 11 "data/maps/BirthIsland_Exterior/scripts.pory"

# 12 "data/maps/BirthIsland_Exterior/scripts.pory"
BirthIsland_Exterior_OnTransition:
# 13 "data/maps/BirthIsland_Exterior/scripts.pory"
	setflag FLAG_MAP_SCRIPT_CHECKED_DEOXYS
# 14 "data/maps/BirthIsland_Exterior/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_BRENDAN_NORMAL
# 15 "data/maps/BirthIsland_Exterior/scripts.pory"
	setvar VAR_DEOXYS_ROCK_STEP_COUNT, 0
# 16 "data/maps/BirthIsland_Exterior/scripts.pory"
	setvar VAR_DEOXYS_ROCK_LEVEL, 0
# 17 "data/maps/BirthIsland_Exterior/scripts.pory"
	call_if_set FLAG_BATTLED_DEOXYS, BirthIsland_Exterior_EventScript_HideDeoxysAndPuzzle
# 18 "data/maps/BirthIsland_Exterior/scripts.pory"
	call_if_unset FLAG_BATTLED_DEOXYS, BirthIsland_Exterior_EventScript_TryShowDeoxysPuzzle
# 19 "data/maps/BirthIsland_Exterior/scripts.pory"
	end
# 20 "data/maps/BirthIsland_Exterior/scripts.pory"

# 21 "data/maps/BirthIsland_Exterior/scripts.pory"
BirthIsland_Exterior_EventScript_HideDeoxysAndPuzzle::
# 22 "data/maps/BirthIsland_Exterior/scripts.pory"
	setflag FLAG_HIDE_DEOXYS
# 23 "data/maps/BirthIsland_Exterior/scripts.pory"
	setflag FLAG_HIDE_BIRTH_ISLAND_DEOXYS_TRIANGLE
# 24 "data/maps/BirthIsland_Exterior/scripts.pory"
	return
# 25 "data/maps/BirthIsland_Exterior/scripts.pory"

# 26 "data/maps/BirthIsland_Exterior/scripts.pory"
BirthIsland_Exterior_EventScript_TryShowDeoxysPuzzle::
# 27 "data/maps/BirthIsland_Exterior/scripts.pory"
	goto_if_set FLAG_DEFEATED_DEOXYS, Common_EventScript_NopReturn
# 28 "data/maps/BirthIsland_Exterior/scripts.pory"
	clearflag FLAG_HIDE_BIRTH_ISLAND_DEOXYS_TRIANGLE
# 29 "data/maps/BirthIsland_Exterior/scripts.pory"
	clearflag FLAG_DEOXYS_ROCK_COMPLETE
# 30 "data/maps/BirthIsland_Exterior/scripts.pory"
	return
# 31 "data/maps/BirthIsland_Exterior/scripts.pory"

# 32 "data/maps/BirthIsland_Exterior/scripts.pory"
BirthIsland_Exterior_OnResume:
# 33 "data/maps/BirthIsland_Exterior/scripts.pory"
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, BirthIsland_Exterior_EventScript_TryRemoveDeoxys
# 34 "data/maps/BirthIsland_Exterior/scripts.pory"
	end
# 35 "data/maps/BirthIsland_Exterior/scripts.pory"

# 36 "data/maps/BirthIsland_Exterior/scripts.pory"
BirthIsland_Exterior_EventScript_TryRemoveDeoxys::
# 37 "data/maps/BirthIsland_Exterior/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 38 "data/maps/BirthIsland_Exterior/scripts.pory"
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
# 39 "data/maps/BirthIsland_Exterior/scripts.pory"
	removeobject LOCALID_BIRTH_ISLAND_DEOXYS
# 40 "data/maps/BirthIsland_Exterior/scripts.pory"
	return
# 41 "data/maps/BirthIsland_Exterior/scripts.pory"

# 42 "data/maps/BirthIsland_Exterior/scripts.pory"
BirthIsland_Exterior_EventScript_Triangle::
# 43 "data/maps/BirthIsland_Exterior/scripts.pory"
	lock
# 44 "data/maps/BirthIsland_Exterior/scripts.pory"
	faceplayer
# 45 "data/maps/BirthIsland_Exterior/scripts.pory"
	special DoDeoxysRockInteraction
# 46 "data/maps/BirthIsland_Exterior/scripts.pory"
	waitstate
# 47 "data/maps/BirthIsland_Exterior/scripts.pory"
	switch VAR_RESULT
# 48 "data/maps/BirthIsland_Exterior/scripts.pory"
	case DEOXYS_ROCK_FAILED,     BirthIsland_Exterior_EventScript_Failed
# 49 "data/maps/BirthIsland_Exterior/scripts.pory"
	case DEOXYS_ROCK_PROGRESSED, BirthIsland_Exterior_EventScript_Progressed
# 50 "data/maps/BirthIsland_Exterior/scripts.pory"
	case DEOXYS_ROCK_SOLVED,     BirthIsland_Exterior_EventScript_Deoxys
# 51 "data/maps/BirthIsland_Exterior/scripts.pory"
	case DEOXYS_ROCK_COMPLETE,   BirthIsland_Exterior_EventScript_Complete
# 52 "data/maps/BirthIsland_Exterior/scripts.pory"
	end
# 53 "data/maps/BirthIsland_Exterior/scripts.pory"

# 54 "data/maps/BirthIsland_Exterior/scripts.pory"
@ The actual rock triangle movement is handled by DoDeoxysRockInteraction.
# 55 "data/maps/BirthIsland_Exterior/scripts.pory"
@ Unless the player has solved the puzzle and needs to encounter Deoxys,
# 56 "data/maps/BirthIsland_Exterior/scripts.pory"
@ there's nothing else the script needs to do.
# 57 "data/maps/BirthIsland_Exterior/scripts.pory"
BirthIsland_Exterior_EventScript_Failed::
# 58 "data/maps/BirthIsland_Exterior/scripts.pory"
	release
# 59 "data/maps/BirthIsland_Exterior/scripts.pory"
	end
# 60 "data/maps/BirthIsland_Exterior/scripts.pory"

# 61 "data/maps/BirthIsland_Exterior/scripts.pory"
BirthIsland_Exterior_EventScript_Progressed::
# 62 "data/maps/BirthIsland_Exterior/scripts.pory"
	release
# 63 "data/maps/BirthIsland_Exterior/scripts.pory"
	end
# 64 "data/maps/BirthIsland_Exterior/scripts.pory"

# 65 "data/maps/BirthIsland_Exterior/scripts.pory"
BirthIsland_Exterior_EventScript_Complete::
# 66 "data/maps/BirthIsland_Exterior/scripts.pory"
	release
# 67 "data/maps/BirthIsland_Exterior/scripts.pory"
	end
# 68 "data/maps/BirthIsland_Exterior/scripts.pory"

# 69 "data/maps/BirthIsland_Exterior/scripts.pory"
BirthIsland_Exterior_EventScript_Deoxys::
# 70 "data/maps/BirthIsland_Exterior/scripts.pory"
	waitse
# 71 "data/maps/BirthIsland_Exterior/scripts.pory"
	setfieldeffectargument 0, LOCALID_BIRTH_ISLAND_EXTERIOR_ROCK
# 72 "data/maps/BirthIsland_Exterior/scripts.pory"
	setfieldeffectargument 1, MAP_NUM(MAP_BIRTH_ISLAND_EXTERIOR)
# 73 "data/maps/BirthIsland_Exterior/scripts.pory"
	setfieldeffectargument 2, MAP_GROUP(MAP_BIRTH_ISLAND_EXTERIOR)
# 74 "data/maps/BirthIsland_Exterior/scripts.pory"
	dofieldeffect FLDEFF_DESTROY_DEOXYS_ROCK
# 75 "data/maps/BirthIsland_Exterior/scripts.pory"
	playbgm MUS_RG_ENCOUNTER_DEOXYS, FALSE
# 76 "data/maps/BirthIsland_Exterior/scripts.pory"
	waitfieldeffect FLDEFF_DESTROY_DEOXYS_ROCK
# 77 "data/maps/BirthIsland_Exterior/scripts.pory"
	addobject LOCALID_BIRTH_ISLAND_DEOXYS
# 78 "data/maps/BirthIsland_Exterior/scripts.pory"
	applymovement LOCALID_BIRTH_ISLAND_DEOXYS, BirthIsland_Exterior_Movement_DeoxysApproach
# 79 "data/maps/BirthIsland_Exterior/scripts.pory"
	waitmovement 0
# 80 "data/maps/BirthIsland_Exterior/scripts.pory"
	waitse
# 81 "data/maps/BirthIsland_Exterior/scripts.pory"
	playmoncry SPECIES_DEOXYS_NORMAL, CRY_MODE_ENCOUNTER
# 82 "data/maps/BirthIsland_Exterior/scripts.pory"
	delay 40
# 83 "data/maps/BirthIsland_Exterior/scripts.pory"
	waitmoncry
# 84 "data/maps/BirthIsland_Exterior/scripts.pory"
	setvar VAR_LAST_TALKED, LOCALID_BIRTH_ISLAND_DEOXYS
# 85 "data/maps/BirthIsland_Exterior/scripts.pory"
	seteventmon SPECIES_DEOXYS_NORMAL, 30
# 86 "data/maps/BirthIsland_Exterior/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 87 "data/maps/BirthIsland_Exterior/scripts.pory"
	special BattleSetup_StartLegendaryBattle
# 88 "data/maps/BirthIsland_Exterior/scripts.pory"
	waitstate
# 89 "data/maps/BirthIsland_Exterior/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 90 "data/maps/BirthIsland_Exterior/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 91 "data/maps/BirthIsland_Exterior/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, BirthIsland_Exterior_EventScript_DefeatedDeoxys
# 92 "data/maps/BirthIsland_Exterior/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, BirthIsland_Exterior_EventScript_RanFromDeoxys
# 93 "data/maps/BirthIsland_Exterior/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, BirthIsland_Exterior_EventScript_RanFromDeoxys
# 94 "data/maps/BirthIsland_Exterior/scripts.pory"
	setflag FLAG_BATTLED_DEOXYS
# 95 "data/maps/BirthIsland_Exterior/scripts.pory"
	release
# 96 "data/maps/BirthIsland_Exterior/scripts.pory"
	end
# 97 "data/maps/BirthIsland_Exterior/scripts.pory"

# 98 "data/maps/BirthIsland_Exterior/scripts.pory"
BirthIsland_Exterior_EventScript_DefeatedDeoxys::
# 99 "data/maps/BirthIsland_Exterior/scripts.pory"
	setflag FLAG_DEFEATED_DEOXYS
# 100 "data/maps/BirthIsland_Exterior/scripts.pory"
	setvar VAR_0x8004, SPECIES_DEOXYS_NORMAL
# 101 "data/maps/BirthIsland_Exterior/scripts.pory"
	goto Common_EventScript_LegendaryFlewAway
# 102 "data/maps/BirthIsland_Exterior/scripts.pory"
	end
# 103 "data/maps/BirthIsland_Exterior/scripts.pory"

# 104 "data/maps/BirthIsland_Exterior/scripts.pory"
BirthIsland_Exterior_EventScript_RanFromDeoxys::
# 105 "data/maps/BirthIsland_Exterior/scripts.pory"
	setvar VAR_0x8004, SPECIES_DEOXYS_NORMAL
# 106 "data/maps/BirthIsland_Exterior/scripts.pory"
	goto Common_EventScript_LegendaryFlewAway
# 107 "data/maps/BirthIsland_Exterior/scripts.pory"
	end
# 108 "data/maps/BirthIsland_Exterior/scripts.pory"

# 109 "data/maps/BirthIsland_Exterior/scripts.pory"
BirthIsland_Exterior_Movement_DeoxysApproach:
# 110 "data/maps/BirthIsland_Exterior/scripts.pory"
	walk_slow_down
# 111 "data/maps/BirthIsland_Exterior/scripts.pory"
	walk_slow_down
# 112 "data/maps/BirthIsland_Exterior/scripts.pory"
	walk_slow_down
# 113 "data/maps/BirthIsland_Exterior/scripts.pory"
	walk_slow_down
# 114 "data/maps/BirthIsland_Exterior/scripts.pory"
	walk_slow_down
# 115 "data/maps/BirthIsland_Exterior/scripts.pory"
	walk_slow_down
# 116 "data/maps/BirthIsland_Exterior/scripts.pory"
	walk_slow_down
# 117 "data/maps/BirthIsland_Exterior/scripts.pory"
	step_end
