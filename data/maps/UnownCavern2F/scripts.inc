UnownCavern2F_MapScripts::
	.byte 0


# 4 "data/maps/UnownCavern2F/scripts.pory"

# 5 "data/maps/UnownCavern2F/scripts.pory"

# 6 "data/maps/UnownCavern2F/scripts.pory"
UnownCavern_2F_MapScripts::
# 7 "data/maps/UnownCavern2F/scripts.pory"
    map_script MAP_SCRIPT_ON_RESUME, UnownCavern_2F_OnResume
# 8 "data/maps/UnownCavern2F/scripts.pory"
    .byte 0
# 9 "data/maps/UnownCavern2F/scripts.pory"

# 10 "data/maps/UnownCavern2F/scripts.pory"

# 11 "data/maps/UnownCavern2F/scripts.pory"
UnownCavern_2F_OnResume:
# 12 "data/maps/UnownCavern2F/scripts.pory"
    call_if_set FLAG_SYS_CTRL_OBJ_DELETE, UnownCavern_2F_EventScript_TryRemoveMewtwo
# 13 "data/maps/UnownCavern2F/scripts.pory"
    end
# 14 "data/maps/UnownCavern2F/scripts.pory"

# 15 "data/maps/UnownCavern2F/scripts.pory"

# 16 "data/maps/UnownCavern2F/scripts.pory"
UnownCavern_2F_EventScript_TryRemoveMewtwo::
# 17 "data/maps/UnownCavern2F/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 18 "data/maps/UnownCavern2F/scripts.pory"
    goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
# 19 "data/maps/UnownCavern2F/scripts.pory"
    removeobject VAR_LAST_TALKED
# 20 "data/maps/UnownCavern2F/scripts.pory"
    return
# 21 "data/maps/UnownCavern2F/scripts.pory"

# 22 "data/maps/UnownCavern2F/scripts.pory"
UnownCavern_2F_EventScript_Mewtwo::
# 23 "data/maps/UnownCavern2F/scripts.pory"
    lock
# 24 "data/maps/UnownCavern2F/scripts.pory"
    faceplayer
# 25 "data/maps/UnownCavern2F/scripts.pory"
    waitse
# 26 "data/maps/UnownCavern2F/scripts.pory"
    playmoncry SPECIES_MEWTWO, CRY_MODE_ENCOUNTER
# 27 "data/maps/UnownCavern2F/scripts.pory"
    delay 40
# 28 "data/maps/UnownCavern2F/scripts.pory"
    waitmoncry
# 29 "data/maps/UnownCavern2F/scripts.pory"
    setwildbattle SPECIES_MEWTWO, 70
# 30 "data/maps/UnownCavern2F/scripts.pory"
    setflag FLAG_SYS_CTRL_OBJ_DELETE
# 31 "data/maps/UnownCavern2F/scripts.pory"
    special BattleSetup_StartLegendaryBattle
# 32 "data/maps/UnownCavern2F/scripts.pory"
    waitstate
# 33 "data/maps/UnownCavern2F/scripts.pory"
    clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 34 "data/maps/UnownCavern2F/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 35 "data/maps/UnownCavern2F/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_WON, UnownCavern_2F_EventScript_DefeatedMewtwo
# 36 "data/maps/UnownCavern2F/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_RAN, UnownCavern_2F_EventScript_RanFromMewtwo
# 37 "data/maps/UnownCavern2F/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, UnownCavern_2F_EventScript_RanFromMewtwo
# 38 "data/maps/UnownCavern2F/scripts.pory"
    setflag FLAG_DEFEATED_MEWTWO
# 39 "data/maps/UnownCavern2F/scripts.pory"
    release
# 40 "data/maps/UnownCavern2F/scripts.pory"
    end
# 41 "data/maps/UnownCavern2F/scripts.pory"

# 42 "data/maps/UnownCavern2F/scripts.pory"

# 43 "data/maps/UnownCavern2F/scripts.pory"
UnownCavern_2F_EventScript_DefeatedMewtwo::
# 44 "data/maps/UnownCavern2F/scripts.pory"
    setflag FLAG_DEFEATED_MEWTWO
# 45 "data/maps/UnownCavern2F/scripts.pory"
    goto Common_EventScript_RemoveStaticPokemon
# 46 "data/maps/UnownCavern2F/scripts.pory"
    end
# 47 "data/maps/UnownCavern2F/scripts.pory"

# 48 "data/maps/UnownCavern2F/scripts.pory"

# 49 "data/maps/UnownCavern2F/scripts.pory"
UnownCavern_2F_EventScript_RanFromMewtwo::
# 50 "data/maps/UnownCavern2F/scripts.pory"
    setvar VAR_0x8004, SPECIES_MEWTWO
# 51 "data/maps/UnownCavern2F/scripts.pory"
    goto Common_EventScript_LegendaryFlewAway
# 52 "data/maps/UnownCavern2F/scripts.pory"
    end
