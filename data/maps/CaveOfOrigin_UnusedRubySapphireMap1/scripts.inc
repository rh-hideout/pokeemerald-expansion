# 1 "data/maps/CaveOfOrigin_UnusedRubySapphireMap1/scripts.pory"

# 2 "data/maps/CaveOfOrigin_UnusedRubySapphireMap1/scripts.pory"
CaveOfOrigin_UnusedRubySapphireMap1_MapScripts::
# 3 "data/maps/CaveOfOrigin_UnusedRubySapphireMap1/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, CaveOfOrigin_UnusedRubySapphireMap1_OnResume
# 4 "data/maps/CaveOfOrigin_UnusedRubySapphireMap1/scripts.pory"
	.byte 0
# 5 "data/maps/CaveOfOrigin_UnusedRubySapphireMap1/scripts.pory"

# 6 "data/maps/CaveOfOrigin_UnusedRubySapphireMap1/scripts.pory"
CaveOfOrigin_UnusedRubySapphireMap1_OnResume:
# 7 "data/maps/CaveOfOrigin_UnusedRubySapphireMap1/scripts.pory"
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, CaveOfOrigin_UnusedRubySapphireMap1_EventScript_TryRemoveArticuno
# 8 "data/maps/CaveOfOrigin_UnusedRubySapphireMap1/scripts.pory"
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, CaveOfOrigin_UnusedRubySapphireMap1_EventScript_TryRemoveArticuno_Galarian
# 9 "data/maps/CaveOfOrigin_UnusedRubySapphireMap1/scripts.pory"
	end
# 10 "data/maps/CaveOfOrigin_UnusedRubySapphireMap1/scripts.pory"

# 11 "data/maps/CaveOfOrigin_UnusedRubySapphireMap1/scripts.pory"
CaveOfOrigin_UnusedRubySapphireMap1_EventScript_TryRemoveArticuno::
# 12 "data/maps/CaveOfOrigin_UnusedRubySapphireMap1/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 13 "data/maps/CaveOfOrigin_UnusedRubySapphireMap1/scripts.pory"
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
# 14 "data/maps/CaveOfOrigin_UnusedRubySapphireMap1/scripts.pory"
	removeobject VAR_LAST_TALKED
# 15 "data/maps/CaveOfOrigin_UnusedRubySapphireMap1/scripts.pory"
	return
# 16 "data/maps/CaveOfOrigin_UnusedRubySapphireMap1/scripts.pory"

# 17 "data/maps/CaveOfOrigin_UnusedRubySapphireMap1/scripts.pory"
CaveOfOrigin_UnusedRubySapphireMap1_EventScript_TryRemoveArticuno_Galarian::
# 18 "data/maps/CaveOfOrigin_UnusedRubySapphireMap1/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 19 "data/maps/CaveOfOrigin_UnusedRubySapphireMap1/scripts.pory"
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
# 20 "data/maps/CaveOfOrigin_UnusedRubySapphireMap1/scripts.pory"
	removeobject VAR_LAST_TALKED
# 21 "data/maps/CaveOfOrigin_UnusedRubySapphireMap1/scripts.pory"
	return
# 22 "data/maps/CaveOfOrigin_UnusedRubySapphireMap1/scripts.pory"

# 23 "data/maps/CaveOfOrigin_UnusedRubySapphireMap1/scripts.pory"
CaveOfOrigin_UnusedRubySapphireMap1_EventScript_Articuno::
# 24 "data/maps/CaveOfOrigin_UnusedRubySapphireMap1/scripts.pory"
    lock
# 25 "data/maps/CaveOfOrigin_UnusedRubySapphireMap1/scripts.pory"
    faceplayer
# 26 "data/maps/CaveOfOrigin_UnusedRubySapphireMap1/scripts.pory"
    waitse
# 27 "data/maps/CaveOfOrigin_UnusedRubySapphireMap1/scripts.pory"
    playmoncry SPECIES_ARTICUNO, CRY_MODE_ENCOUNTER
# 28 "data/maps/CaveOfOrigin_UnusedRubySapphireMap1/scripts.pory"
    delay 40
# 29 "data/maps/CaveOfOrigin_UnusedRubySapphireMap1/scripts.pory"
    waitmoncry
# 30 "data/maps/CaveOfOrigin_UnusedRubySapphireMap1/scripts.pory"
    setwildbattle SPECIES_ARTICUNO, 40
# 31 "data/maps/CaveOfOrigin_UnusedRubySapphireMap1/scripts.pory"
    setflag FLAG_SYS_CTRL_OBJ_DELETE
# 32 "data/maps/CaveOfOrigin_UnusedRubySapphireMap1/scripts.pory"
    special BattleSetup_StartLegendaryBattle
# 33 "data/maps/CaveOfOrigin_UnusedRubySapphireMap1/scripts.pory"
    waitstate
# 34 "data/maps/CaveOfOrigin_UnusedRubySapphireMap1/scripts.pory"
    clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 35 "data/maps/CaveOfOrigin_UnusedRubySapphireMap1/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 36 "data/maps/CaveOfOrigin_UnusedRubySapphireMap1/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_WON, CaveOfOrigin_UnusedRubySapphireMap1_EventScript_DefeatedArticuno
# 37 "data/maps/CaveOfOrigin_UnusedRubySapphireMap1/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_RAN, CaveOfOrigin_UnusedRubySapphireMap1_EventScript_RanFromArticuno
# 38 "data/maps/CaveOfOrigin_UnusedRubySapphireMap1/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, CaveOfOrigin_UnusedRubySapphireMap1_EventScript_RanFromArticuno
# 39 "data/maps/CaveOfOrigin_UnusedRubySapphireMap1/scripts.pory"
    setflag FLAG_DEFEATED_ARTICUNO
# 40 "data/maps/CaveOfOrigin_UnusedRubySapphireMap1/scripts.pory"
    release
# 41 "data/maps/CaveOfOrigin_UnusedRubySapphireMap1/scripts.pory"
    end
# 42 "data/maps/CaveOfOrigin_UnusedRubySapphireMap1/scripts.pory"

# 43 "data/maps/CaveOfOrigin_UnusedRubySapphireMap1/scripts.pory"

# 44 "data/maps/CaveOfOrigin_UnusedRubySapphireMap1/scripts.pory"
CaveOfOrigin_UnusedRubySapphireMap1_EventScript_DefeatedArticuno::
# 45 "data/maps/CaveOfOrigin_UnusedRubySapphireMap1/scripts.pory"
    setflag FLAG_DEFEATED_ARTICUNO
# 46 "data/maps/CaveOfOrigin_UnusedRubySapphireMap1/scripts.pory"
    goto Common_EventScript_RemoveStaticPokemon
# 47 "data/maps/CaveOfOrigin_UnusedRubySapphireMap1/scripts.pory"
    end
# 48 "data/maps/CaveOfOrigin_UnusedRubySapphireMap1/scripts.pory"

# 49 "data/maps/CaveOfOrigin_UnusedRubySapphireMap1/scripts.pory"

# 50 "data/maps/CaveOfOrigin_UnusedRubySapphireMap1/scripts.pory"
CaveOfOrigin_UnusedRubySapphireMap1_EventScript_RanFromArticuno::
# 51 "data/maps/CaveOfOrigin_UnusedRubySapphireMap1/scripts.pory"
    setvar VAR_0x8004, SPECIES_ARTICUNO
# 52 "data/maps/CaveOfOrigin_UnusedRubySapphireMap1/scripts.pory"
    goto Common_EventScript_LegendaryFlewAway
# 53 "data/maps/CaveOfOrigin_UnusedRubySapphireMap1/scripts.pory"
    end
# 54 "data/maps/CaveOfOrigin_UnusedRubySapphireMap1/scripts.pory"

# 55 "data/maps/CaveOfOrigin_UnusedRubySapphireMap1/scripts.pory"
CaveOfOrigin_UnusedRubySapphireMap1_EventScript_Articuno_Galarian::
# 56 "data/maps/CaveOfOrigin_UnusedRubySapphireMap1/scripts.pory"
    lock
# 57 "data/maps/CaveOfOrigin_UnusedRubySapphireMap1/scripts.pory"
    faceplayer
# 58 "data/maps/CaveOfOrigin_UnusedRubySapphireMap1/scripts.pory"
    waitse
# 59 "data/maps/CaveOfOrigin_UnusedRubySapphireMap1/scripts.pory"
    playmoncry SPECIES_ARTICUNO_GALARIAN, CRY_MODE_ENCOUNTER
# 60 "data/maps/CaveOfOrigin_UnusedRubySapphireMap1/scripts.pory"
    delay 40
# 61 "data/maps/CaveOfOrigin_UnusedRubySapphireMap1/scripts.pory"
    waitmoncry
# 62 "data/maps/CaveOfOrigin_UnusedRubySapphireMap1/scripts.pory"
    setwildbattle SPECIES_ARTICUNO_GALARIAN, 40
# 63 "data/maps/CaveOfOrigin_UnusedRubySapphireMap1/scripts.pory"
    setflag FLAG_SYS_CTRL_OBJ_DELETE
# 64 "data/maps/CaveOfOrigin_UnusedRubySapphireMap1/scripts.pory"
    special BattleSetup_StartLegendaryBattle
# 65 "data/maps/CaveOfOrigin_UnusedRubySapphireMap1/scripts.pory"
    waitstate
# 66 "data/maps/CaveOfOrigin_UnusedRubySapphireMap1/scripts.pory"
    clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 67 "data/maps/CaveOfOrigin_UnusedRubySapphireMap1/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 68 "data/maps/CaveOfOrigin_UnusedRubySapphireMap1/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_WON, CaveOfOrigin_UnusedRubySapphireMap1_EventScript_DefeatedArticunoG
# 69 "data/maps/CaveOfOrigin_UnusedRubySapphireMap1/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_RAN, CaveOfOrigin_UnusedRubySapphireMap1_EventScript_RanFromArticunoG
# 70 "data/maps/CaveOfOrigin_UnusedRubySapphireMap1/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, CaveOfOrigin_UnusedRubySapphireMap1_EventScript_RanFromArticunoG
# 71 "data/maps/CaveOfOrigin_UnusedRubySapphireMap1/scripts.pory"
    setflag FLAG_DEFEATED_ARTICUNO_GALARIAN
# 72 "data/maps/CaveOfOrigin_UnusedRubySapphireMap1/scripts.pory"
    release
# 73 "data/maps/CaveOfOrigin_UnusedRubySapphireMap1/scripts.pory"
    end
# 74 "data/maps/CaveOfOrigin_UnusedRubySapphireMap1/scripts.pory"

# 75 "data/maps/CaveOfOrigin_UnusedRubySapphireMap1/scripts.pory"

# 76 "data/maps/CaveOfOrigin_UnusedRubySapphireMap1/scripts.pory"
CaveOfOrigin_UnusedRubySapphireMap1_EventScript_DefeatedArticunoG::
# 77 "data/maps/CaveOfOrigin_UnusedRubySapphireMap1/scripts.pory"
    setflag FLAG_DEFEATED_ARTICUNO_GALARIAN
# 78 "data/maps/CaveOfOrigin_UnusedRubySapphireMap1/scripts.pory"
    goto Common_EventScript_RemoveStaticPokemon
# 79 "data/maps/CaveOfOrigin_UnusedRubySapphireMap1/scripts.pory"
    end
# 80 "data/maps/CaveOfOrigin_UnusedRubySapphireMap1/scripts.pory"

# 81 "data/maps/CaveOfOrigin_UnusedRubySapphireMap1/scripts.pory"

# 82 "data/maps/CaveOfOrigin_UnusedRubySapphireMap1/scripts.pory"
CaveOfOrigin_UnusedRubySapphireMap1_EventScript_RanFromArticunoG::
# 83 "data/maps/CaveOfOrigin_UnusedRubySapphireMap1/scripts.pory"
    setvar VAR_0x8004, SPECIES_ARTICUNO_GALARIAN
# 84 "data/maps/CaveOfOrigin_UnusedRubySapphireMap1/scripts.pory"
    goto Common_EventScript_LegendaryFlewAway
# 85 "data/maps/CaveOfOrigin_UnusedRubySapphireMap1/scripts.pory"
    end
