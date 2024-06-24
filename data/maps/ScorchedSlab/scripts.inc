# 1 "data/maps/ScorchedSlab/scripts.pory"

# 2 "data/maps/ScorchedSlab/scripts.pory"
ScorchedSlab_MapScripts::
# 3 "data/maps/ScorchedSlab/scripts.pory"
    map_script MAP_SCRIPT_ON_RESUME, ScorchedSlab_OnResume
# 4 "data/maps/ScorchedSlab/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, ScorchedSlab_OnTransition
# 5 "data/maps/ScorchedSlab/scripts.pory"
	.byte 0
# 6 "data/maps/ScorchedSlab/scripts.pory"

# 7 "data/maps/ScorchedSlab/scripts.pory"
ScorchedSlab_OnResume:
# 8 "data/maps/ScorchedSlab/scripts.pory"
    call_if_set FLAG_SYS_CTRL_OBJ_DELETE, ScorchedSlab_EventScript_TryRemoveVictini
# 9 "data/maps/ScorchedSlab/scripts.pory"
    end
# 10 "data/maps/ScorchedSlab/scripts.pory"

# 11 "data/maps/ScorchedSlab/scripts.pory"
ScorchedSlab_EventScript_TryRemoveVictini::
# 12 "data/maps/ScorchedSlab/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 13 "data/maps/ScorchedSlab/scripts.pory"
    goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
# 14 "data/maps/ScorchedSlab/scripts.pory"
    removeobject VAR_LAST_TALKED
# 15 "data/maps/ScorchedSlab/scripts.pory"
    return
# 16 "data/maps/ScorchedSlab/scripts.pory"

# 17 "data/maps/ScorchedSlab/scripts.pory"
ScorchedSlab_OnTransition:
# 18 "data/maps/ScorchedSlab/scripts.pory"
	setflag FLAG_LANDMARK_SCORCHED_SLAB
# 19 "data/maps/ScorchedSlab/scripts.pory"
	end
# 20 "data/maps/ScorchedSlab/scripts.pory"

# 21 "data/maps/ScorchedSlab/scripts.pory"
ScorchedSlab_EventScript_Victini::
# 22 "data/maps/ScorchedSlab/scripts.pory"
    lock
# 23 "data/maps/ScorchedSlab/scripts.pory"
    faceplayer
# 24 "data/maps/ScorchedSlab/scripts.pory"
    waitse
# 25 "data/maps/ScorchedSlab/scripts.pory"
    playmoncry SPECIES_VICTINI, CRY_MODE_ENCOUNTER
# 26 "data/maps/ScorchedSlab/scripts.pory"
    delay 40
# 27 "data/maps/ScorchedSlab/scripts.pory"
    waitmoncry
# 28 "data/maps/ScorchedSlab/scripts.pory"
    setwildbattle SPECIES_VICTINI, 30
# 29 "data/maps/ScorchedSlab/scripts.pory"
    setflag FLAG_SYS_CTRL_OBJ_DELETE
# 30 "data/maps/ScorchedSlab/scripts.pory"
    special BattleSetup_StartLegendaryBattle
# 31 "data/maps/ScorchedSlab/scripts.pory"
    waitstate
# 32 "data/maps/ScorchedSlab/scripts.pory"
    clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 33 "data/maps/ScorchedSlab/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 34 "data/maps/ScorchedSlab/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_WON, ScorchedSlab_EventScript_DefeatedVictini
# 35 "data/maps/ScorchedSlab/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_RAN, ScorchedSlab_EventScript_RanFromVictini
# 36 "data/maps/ScorchedSlab/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, ScorchedSlab_EventScript_RanFromVictini
# 37 "data/maps/ScorchedSlab/scripts.pory"
    setflag FLAG_DEFEATED_VICTINI
# 38 "data/maps/ScorchedSlab/scripts.pory"
    release
# 39 "data/maps/ScorchedSlab/scripts.pory"
    end
# 40 "data/maps/ScorchedSlab/scripts.pory"

# 41 "data/maps/ScorchedSlab/scripts.pory"

# 42 "data/maps/ScorchedSlab/scripts.pory"
ScorchedSlab_EventScript_DefeatedVictini::
# 43 "data/maps/ScorchedSlab/scripts.pory"
    setflag FLAG_DEFEATED_VICTINI
# 44 "data/maps/ScorchedSlab/scripts.pory"
    goto Common_EventScript_RemoveStaticPokemon
# 45 "data/maps/ScorchedSlab/scripts.pory"
    end
# 46 "data/maps/ScorchedSlab/scripts.pory"

# 47 "data/maps/ScorchedSlab/scripts.pory"

# 48 "data/maps/ScorchedSlab/scripts.pory"
ScorchedSlab_EventScript_RanFromVictini::
# 49 "data/maps/ScorchedSlab/scripts.pory"
    setvar VAR_0x8004, SPECIES_VICTINI
# 50 "data/maps/ScorchedSlab/scripts.pory"
    goto Common_EventScript_LegendaryFlewAway
# 51 "data/maps/ScorchedSlab/scripts.pory"
    end
