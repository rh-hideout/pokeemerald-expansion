# 1 "data/maps/MeteorFalls_B1F_2R/scripts.pory"

# 2 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
MeteorFalls_B1F_2R_MapScripts::
# 3 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
    map_script MAP_SCRIPT_ON_RESUME, MeteorFalls_B1F_2R_OnResume
# 4 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
	.byte 0
# 5 "data/maps/MeteorFalls_B1F_2R/scripts.pory"

# 6 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
MeteorFalls_B1F_2R_OnResume:
# 7 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
    call_if_set FLAG_SYS_CTRL_OBJ_DELETE, MeteorFalls_B1F_2R_EventScript_TryRemoveHoopa
# 8 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
    end
# 9 "data/maps/MeteorFalls_B1F_2R/scripts.pory"

# 10 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
MeteorFalls_B1F_2R_EventScript_TryRemoveHoopa::
# 11 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 12 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
    goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
# 13 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
    removeobject VAR_LAST_TALKED
# 14 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
    return
# 15 "data/maps/MeteorFalls_B1F_2R/scripts.pory"

# 16 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
MeteorFalls_B1F_2R_EventScript_Hoopa::
# 17 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
    lock
# 18 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
    faceplayer
# 19 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
    waitse
# 20 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
    playmoncry SPECIES_HOOPA, CRY_MODE_ENCOUNTER
# 21 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
    delay 40
# 22 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
    waitmoncry
# 23 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
    setwildbattle SPECIES_HOOPA, 60
# 24 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
    setflag FLAG_SYS_CTRL_OBJ_DELETE
# 25 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
    special BattleSetup_StartLegendaryBattle
# 26 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
    waitstate
# 27 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
    clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 28 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 29 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_WON, MeteorFalls_B1F_2R_EventScript_DefeatedHoopa
# 30 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_RAN, MeteorFalls_B1F_2R_EventScript_RanFromHoopa
# 31 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, MeteorFalls_B1F_2R_EventScript_RanFromHoopa
# 32 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
    setflag FLAG_DEFEATED_HOOPA
# 33 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
    release
# 34 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
    end
# 35 "data/maps/MeteorFalls_B1F_2R/scripts.pory"

# 36 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
MeteorFalls_B1F_2R_EventScript_DefeatedHoopa::
# 37 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
    setflag FLAG_DEFEATED_HOOPA
# 38 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
    goto Common_EventScript_RemoveStaticPokemon
# 39 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
    end
# 40 "data/maps/MeteorFalls_B1F_2R/scripts.pory"

# 41 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
MeteorFalls_B1F_2R_EventScript_RanFromHoopa::
# 42 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
    setvar VAR_0x8004, SPECIES_HOOPA
# 43 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
    goto Common_EventScript_LegendaryFlewAway
# 44 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
    end
