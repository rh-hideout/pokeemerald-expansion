# 1 "data/maps/CaveOfOrigin_UnusedRubySapphireMap3/scripts.pory"

# 2 "data/maps/CaveOfOrigin_UnusedRubySapphireMap3/scripts.pory"
CaveOfOrigin_UnusedRubySapphireMap3_MapScripts::
# 3 "data/maps/CaveOfOrigin_UnusedRubySapphireMap3/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, CaveOfOrigin_UnusedRubySapphireMap3_OnResume
# 4 "data/maps/CaveOfOrigin_UnusedRubySapphireMap3/scripts.pory"
	.byte 0
# 5 "data/maps/CaveOfOrigin_UnusedRubySapphireMap3/scripts.pory"

# 6 "data/maps/CaveOfOrigin_UnusedRubySapphireMap3/scripts.pory"
CaveOfOrigin_UnusedRubySapphireMap3_OnResume:
# 7 "data/maps/CaveOfOrigin_UnusedRubySapphireMap3/scripts.pory"
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, CaveOfOrigin_UnusedRubySapphireMap3_EventScript_TryRemoveXerneas
# 8 "data/maps/CaveOfOrigin_UnusedRubySapphireMap3/scripts.pory"
	end
# 9 "data/maps/CaveOfOrigin_UnusedRubySapphireMap3/scripts.pory"

# 10 "data/maps/CaveOfOrigin_UnusedRubySapphireMap3/scripts.pory"
CaveOfOrigin_UnusedRubySapphireMap3_EventScript_TryRemoveXerneas::
# 11 "data/maps/CaveOfOrigin_UnusedRubySapphireMap3/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 12 "data/maps/CaveOfOrigin_UnusedRubySapphireMap3/scripts.pory"
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
# 13 "data/maps/CaveOfOrigin_UnusedRubySapphireMap3/scripts.pory"
	removeobject VAR_LAST_TALKED
# 14 "data/maps/CaveOfOrigin_UnusedRubySapphireMap3/scripts.pory"
	return
# 15 "data/maps/CaveOfOrigin_UnusedRubySapphireMap3/scripts.pory"

# 16 "data/maps/CaveOfOrigin_UnusedRubySapphireMap3/scripts.pory"
CaveOfOrigin_UnusedRubySapphireMap3_EventScript_Xerneas::
# 17 "data/maps/CaveOfOrigin_UnusedRubySapphireMap3/scripts.pory"
    lock
# 18 "data/maps/CaveOfOrigin_UnusedRubySapphireMap3/scripts.pory"
    faceplayer
# 19 "data/maps/CaveOfOrigin_UnusedRubySapphireMap3/scripts.pory"
    waitse
# 20 "data/maps/CaveOfOrigin_UnusedRubySapphireMap3/scripts.pory"
    playmoncry SPECIES_XERNEAS, CRY_MODE_ENCOUNTER
# 21 "data/maps/CaveOfOrigin_UnusedRubySapphireMap3/scripts.pory"
    delay 40
# 22 "data/maps/CaveOfOrigin_UnusedRubySapphireMap3/scripts.pory"
    waitmoncry
# 23 "data/maps/CaveOfOrigin_UnusedRubySapphireMap3/scripts.pory"
    setwildbattle SPECIES_XERNEAS, 50
# 24 "data/maps/CaveOfOrigin_UnusedRubySapphireMap3/scripts.pory"
    setflag FLAG_SYS_CTRL_OBJ_DELETE
# 25 "data/maps/CaveOfOrigin_UnusedRubySapphireMap3/scripts.pory"
    special BattleSetup_StartLegendaryBattle
# 26 "data/maps/CaveOfOrigin_UnusedRubySapphireMap3/scripts.pory"
    waitstate
# 27 "data/maps/CaveOfOrigin_UnusedRubySapphireMap3/scripts.pory"
    clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 28 "data/maps/CaveOfOrigin_UnusedRubySapphireMap3/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 29 "data/maps/CaveOfOrigin_UnusedRubySapphireMap3/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_WON, CaveOfOrigin_UnusedRubySapphireMap3_EventScript_DefeatedXerneas
# 30 "data/maps/CaveOfOrigin_UnusedRubySapphireMap3/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_RAN, CaveOfOrigin_UnusedRubySapphireMap3_EventScript_RanFromXerneas
# 31 "data/maps/CaveOfOrigin_UnusedRubySapphireMap3/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, CaveOfOrigin_UnusedRubySapphireMap3_EventScript_RanFromXerneas
# 32 "data/maps/CaveOfOrigin_UnusedRubySapphireMap3/scripts.pory"
    setflag FLAG_DEFEATED_YVELTAL
# 33 "data/maps/CaveOfOrigin_UnusedRubySapphireMap3/scripts.pory"
    release
# 34 "data/maps/CaveOfOrigin_UnusedRubySapphireMap3/scripts.pory"
    end
# 35 "data/maps/CaveOfOrigin_UnusedRubySapphireMap3/scripts.pory"

# 36 "data/maps/CaveOfOrigin_UnusedRubySapphireMap3/scripts.pory"

# 37 "data/maps/CaveOfOrigin_UnusedRubySapphireMap3/scripts.pory"
CaveOfOrigin_UnusedRubySapphireMap3_EventScript_DefeatedXerneas::
# 38 "data/maps/CaveOfOrigin_UnusedRubySapphireMap3/scripts.pory"
    setflag FLAG_DEFEATED_XERNEAS
# 39 "data/maps/CaveOfOrigin_UnusedRubySapphireMap3/scripts.pory"
    goto Common_EventScript_RemoveStaticPokemon
# 40 "data/maps/CaveOfOrigin_UnusedRubySapphireMap3/scripts.pory"
    end
# 41 "data/maps/CaveOfOrigin_UnusedRubySapphireMap3/scripts.pory"

# 42 "data/maps/CaveOfOrigin_UnusedRubySapphireMap3/scripts.pory"

# 43 "data/maps/CaveOfOrigin_UnusedRubySapphireMap3/scripts.pory"
CaveOfOrigin_UnusedRubySapphireMap3_EventScript_RanFromXerneas::
# 44 "data/maps/CaveOfOrigin_UnusedRubySapphireMap3/scripts.pory"
    setvar VAR_0x8004, SPECIES_XERNEAS
# 45 "data/maps/CaveOfOrigin_UnusedRubySapphireMap3/scripts.pory"
    goto Common_EventScript_LegendaryFlewAway
# 46 "data/maps/CaveOfOrigin_UnusedRubySapphireMap3/scripts.pory"
    end
