# 1 "data/maps/CaveOfOrigin_UnusedRubySapphireMap2/scripts.pory"

# 2 "data/maps/CaveOfOrigin_UnusedRubySapphireMap2/scripts.pory"
CaveOfOrigin_UnusedRubySapphireMap2_MapScripts::
# 3 "data/maps/CaveOfOrigin_UnusedRubySapphireMap2/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, CaveOfOrigin_UnusedRubySapphireMap2_OnResume
# 4 "data/maps/CaveOfOrigin_UnusedRubySapphireMap2/scripts.pory"
	.byte 0
# 5 "data/maps/CaveOfOrigin_UnusedRubySapphireMap2/scripts.pory"

# 6 "data/maps/CaveOfOrigin_UnusedRubySapphireMap2/scripts.pory"
CaveOfOrigin_UnusedRubySapphireMap2_OnResume:
# 7 "data/maps/CaveOfOrigin_UnusedRubySapphireMap2/scripts.pory"
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, CaveOfOrigin_UnusedRubySapphireMap2_EventScript_TryRemoveYveltal
# 8 "data/maps/CaveOfOrigin_UnusedRubySapphireMap2/scripts.pory"
	end
# 9 "data/maps/CaveOfOrigin_UnusedRubySapphireMap2/scripts.pory"

# 10 "data/maps/CaveOfOrigin_UnusedRubySapphireMap2/scripts.pory"
CaveOfOrigin_UnusedRubySapphireMap2_EventScript_TryRemoveYveltal::
# 11 "data/maps/CaveOfOrigin_UnusedRubySapphireMap2/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 12 "data/maps/CaveOfOrigin_UnusedRubySapphireMap2/scripts.pory"
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
# 13 "data/maps/CaveOfOrigin_UnusedRubySapphireMap2/scripts.pory"
	removeobject VAR_LAST_TALKED
# 14 "data/maps/CaveOfOrigin_UnusedRubySapphireMap2/scripts.pory"
	return
# 15 "data/maps/CaveOfOrigin_UnusedRubySapphireMap2/scripts.pory"

# 16 "data/maps/CaveOfOrigin_UnusedRubySapphireMap2/scripts.pory"
CaveOfOrigin_UnusedRubySapphireMap2_EventScript_Yveltal::
# 17 "data/maps/CaveOfOrigin_UnusedRubySapphireMap2/scripts.pory"
    lock
# 18 "data/maps/CaveOfOrigin_UnusedRubySapphireMap2/scripts.pory"
    faceplayer
# 19 "data/maps/CaveOfOrigin_UnusedRubySapphireMap2/scripts.pory"
    waitse
# 20 "data/maps/CaveOfOrigin_UnusedRubySapphireMap2/scripts.pory"
    playmoncry SPECIES_YVELTAL, CRY_MODE_ENCOUNTER
# 21 "data/maps/CaveOfOrigin_UnusedRubySapphireMap2/scripts.pory"
    delay 40
# 22 "data/maps/CaveOfOrigin_UnusedRubySapphireMap2/scripts.pory"
    waitmoncry
# 23 "data/maps/CaveOfOrigin_UnusedRubySapphireMap2/scripts.pory"
    setwildbattle SPECIES_YVELTAL, 50
# 24 "data/maps/CaveOfOrigin_UnusedRubySapphireMap2/scripts.pory"
    setflag FLAG_SYS_CTRL_OBJ_DELETE
# 25 "data/maps/CaveOfOrigin_UnusedRubySapphireMap2/scripts.pory"
    special BattleSetup_StartLegendaryBattle
# 26 "data/maps/CaveOfOrigin_UnusedRubySapphireMap2/scripts.pory"
    waitstate
# 27 "data/maps/CaveOfOrigin_UnusedRubySapphireMap2/scripts.pory"
    clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 28 "data/maps/CaveOfOrigin_UnusedRubySapphireMap2/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 29 "data/maps/CaveOfOrigin_UnusedRubySapphireMap2/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_WON, CaveOfOrigin_UnusedRubySapphireMap2_EventScript_DefeatedYveltal
# 30 "data/maps/CaveOfOrigin_UnusedRubySapphireMap2/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_RAN, CaveOfOrigin_UnusedRubySapphireMap2_EventScript_RanFromYveltal
# 31 "data/maps/CaveOfOrigin_UnusedRubySapphireMap2/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, CaveOfOrigin_UnusedRubySapphireMap2_EventScript_RanFromYveltal
# 32 "data/maps/CaveOfOrigin_UnusedRubySapphireMap2/scripts.pory"
    setflag FLAG_DEFEATED_YVELTAL
# 33 "data/maps/CaveOfOrigin_UnusedRubySapphireMap2/scripts.pory"
    release
# 34 "data/maps/CaveOfOrigin_UnusedRubySapphireMap2/scripts.pory"
    end
# 35 "data/maps/CaveOfOrigin_UnusedRubySapphireMap2/scripts.pory"

# 36 "data/maps/CaveOfOrigin_UnusedRubySapphireMap2/scripts.pory"

# 37 "data/maps/CaveOfOrigin_UnusedRubySapphireMap2/scripts.pory"
CaveOfOrigin_UnusedRubySapphireMap2_EventScript_DefeatedYveltal::
# 38 "data/maps/CaveOfOrigin_UnusedRubySapphireMap2/scripts.pory"
    setflag FLAG_DEFEATED_YVELTAL
# 39 "data/maps/CaveOfOrigin_UnusedRubySapphireMap2/scripts.pory"
    goto Common_EventScript_RemoveStaticPokemon
# 40 "data/maps/CaveOfOrigin_UnusedRubySapphireMap2/scripts.pory"
    end
# 41 "data/maps/CaveOfOrigin_UnusedRubySapphireMap2/scripts.pory"

# 42 "data/maps/CaveOfOrigin_UnusedRubySapphireMap2/scripts.pory"

# 43 "data/maps/CaveOfOrigin_UnusedRubySapphireMap2/scripts.pory"
CaveOfOrigin_UnusedRubySapphireMap2_EventScript_RanFromYveltal::
# 44 "data/maps/CaveOfOrigin_UnusedRubySapphireMap2/scripts.pory"
    setvar VAR_0x8004, SPECIES_YVELTAL
# 45 "data/maps/CaveOfOrigin_UnusedRubySapphireMap2/scripts.pory"
    goto Common_EventScript_LegendaryFlewAway
# 46 "data/maps/CaveOfOrigin_UnusedRubySapphireMap2/scripts.pory"
    end
