# 2 "data/maps/AquaHideout_UnusedRubyMap3/scripts.pory"

# 3 "data/maps/AquaHideout_UnusedRubyMap3/scripts.pory"
AquaHideout_UnusedRubyMap3_MapScripts::
# 4 "data/maps/AquaHideout_UnusedRubyMap3/scripts.pory"
    map_script MAP_SCRIPT_ON_RESUME, AquaHideout_UnusedRubyMap3_OnResume
# 5 "data/maps/AquaHideout_UnusedRubyMap3/scripts.pory"
	.byte 0
# 6 "data/maps/AquaHideout_UnusedRubyMap3/scripts.pory"

# 7 "data/maps/AquaHideout_UnusedRubyMap3/scripts.pory"
AquaHideout_UnusedRubyMap3_OnResume:
# 8 "data/maps/AquaHideout_UnusedRubyMap3/scripts.pory"
    call_if_set FLAG_SYS_CTRL_OBJ_DELETE, AquaHideout_UnusedRubyMap3_EventScript_TryRemoveGenesect
# 9 "data/maps/AquaHideout_UnusedRubyMap3/scripts.pory"
    end
# 10 "data/maps/AquaHideout_UnusedRubyMap3/scripts.pory"

# 11 "data/maps/AquaHideout_UnusedRubyMap3/scripts.pory"
AquaHideout_UnusedRubyMap3_EventScript_TryRemoveGenesect::
# 12 "data/maps/AquaHideout_UnusedRubyMap3/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 13 "data/maps/AquaHideout_UnusedRubyMap3/scripts.pory"
    goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
# 14 "data/maps/AquaHideout_UnusedRubyMap3/scripts.pory"
    removeobject VAR_LAST_TALKED
# 15 "data/maps/AquaHideout_UnusedRubyMap3/scripts.pory"
    return
# 16 "data/maps/AquaHideout_UnusedRubyMap3/scripts.pory"

# 17 "data/maps/AquaHideout_UnusedRubyMap3/scripts.pory"
AquaHideout_UnusedRubyMap3_EventScript_Genesect::
# 18 "data/maps/AquaHideout_UnusedRubyMap3/scripts.pory"
    lock
# 19 "data/maps/AquaHideout_UnusedRubyMap3/scripts.pory"
    faceplayer
# 20 "data/maps/AquaHideout_UnusedRubyMap3/scripts.pory"
    waitse
# 21 "data/maps/AquaHideout_UnusedRubyMap3/scripts.pory"
    playmoncry SPECIES_GENESECT, CRY_MODE_ENCOUNTER
# 22 "data/maps/AquaHideout_UnusedRubyMap3/scripts.pory"
    delay 40
# 23 "data/maps/AquaHideout_UnusedRubyMap3/scripts.pory"
    waitmoncry
# 24 "data/maps/AquaHideout_UnusedRubyMap3/scripts.pory"
    setwildbattle SPECIES_GENESECT, 30
# 25 "data/maps/AquaHideout_UnusedRubyMap3/scripts.pory"
    setflag FLAG_SYS_CTRL_OBJ_DELETE
# 26 "data/maps/AquaHideout_UnusedRubyMap3/scripts.pory"
    special BattleSetup_StartLegendaryBattle
# 27 "data/maps/AquaHideout_UnusedRubyMap3/scripts.pory"
    waitstate
# 28 "data/maps/AquaHideout_UnusedRubyMap3/scripts.pory"
    clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 29 "data/maps/AquaHideout_UnusedRubyMap3/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 30 "data/maps/AquaHideout_UnusedRubyMap3/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_WON, AquaHideout_UnusedRubyMap3_EventScript_DefeatedGenesect
# 31 "data/maps/AquaHideout_UnusedRubyMap3/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_RAN, AquaHideout_UnusedRubyMap3_EventScript_RanFromGenesect
# 32 "data/maps/AquaHideout_UnusedRubyMap3/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, AquaHideout_UnusedRubyMap3_EventScript_RanFromGenesect
# 33 "data/maps/AquaHideout_UnusedRubyMap3/scripts.pory"
    setflag FLAG_DEFEATED_GENESECT
# 34 "data/maps/AquaHideout_UnusedRubyMap3/scripts.pory"
    release
# 35 "data/maps/AquaHideout_UnusedRubyMap3/scripts.pory"
    end
# 36 "data/maps/AquaHideout_UnusedRubyMap3/scripts.pory"

# 37 "data/maps/AquaHideout_UnusedRubyMap3/scripts.pory"

# 38 "data/maps/AquaHideout_UnusedRubyMap3/scripts.pory"
AquaHideout_UnusedRubyMap3_EventScript_DefeatedGenesect::
# 39 "data/maps/AquaHideout_UnusedRubyMap3/scripts.pory"
    setflag FLAG_DEFEATED_GENESECT
# 40 "data/maps/AquaHideout_UnusedRubyMap3/scripts.pory"
    goto Common_EventScript_RemoveStaticPokemon
# 41 "data/maps/AquaHideout_UnusedRubyMap3/scripts.pory"
    end
# 42 "data/maps/AquaHideout_UnusedRubyMap3/scripts.pory"

# 43 "data/maps/AquaHideout_UnusedRubyMap3/scripts.pory"

# 44 "data/maps/AquaHideout_UnusedRubyMap3/scripts.pory"
AquaHideout_UnusedRubyMap3_EventScript_RanFromGenesect::
# 45 "data/maps/AquaHideout_UnusedRubyMap3/scripts.pory"
    setvar VAR_0x8004, SPECIES_GENESECT
# 46 "data/maps/AquaHideout_UnusedRubyMap3/scripts.pory"
    goto Common_EventScript_LegendaryFlewAway
# 47 "data/maps/AquaHideout_UnusedRubyMap3/scripts.pory"
    end
