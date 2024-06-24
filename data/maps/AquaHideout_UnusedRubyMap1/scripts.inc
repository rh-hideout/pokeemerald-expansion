# 1 "data/maps/AquaHideout_UnusedRubyMap1/scripts.pory"

# 2 "data/maps/AquaHideout_UnusedRubyMap1/scripts.pory"
AquaHideout_UnusedRubyMap1_MapScripts::
# 3 "data/maps/AquaHideout_UnusedRubyMap1/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, AquaHideout_UnusedRubyMap1_OnResume
# 4 "data/maps/AquaHideout_UnusedRubyMap1/scripts.pory"
	.byte 0
# 5 "data/maps/AquaHideout_UnusedRubyMap1/scripts.pory"

# 6 "data/maps/AquaHideout_UnusedRubyMap1/scripts.pory"
AquaHideout_UnusedRubyMap1_OnResume:
# 7 "data/maps/AquaHideout_UnusedRubyMap1/scripts.pory"
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, AquaHideout_UnusedRubyMap1_EventScript_TryRemoveZapdos
# 8 "data/maps/AquaHideout_UnusedRubyMap1/scripts.pory"
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, AquaHideout_UnusedRubyMap1_EventScript_TryRemoveZapdos_Galarian
# 9 "data/maps/AquaHideout_UnusedRubyMap1/scripts.pory"
	end
# 10 "data/maps/AquaHideout_UnusedRubyMap1/scripts.pory"

# 11 "data/maps/AquaHideout_UnusedRubyMap1/scripts.pory"
AquaHideout_UnusedRubyMap1_EventScript_TryRemoveZapdos::
# 12 "data/maps/AquaHideout_UnusedRubyMap1/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 13 "data/maps/AquaHideout_UnusedRubyMap1/scripts.pory"
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
# 14 "data/maps/AquaHideout_UnusedRubyMap1/scripts.pory"
	removeobject VAR_LAST_TALKED
# 15 "data/maps/AquaHideout_UnusedRubyMap1/scripts.pory"
	return
# 16 "data/maps/AquaHideout_UnusedRubyMap1/scripts.pory"

# 17 "data/maps/AquaHideout_UnusedRubyMap1/scripts.pory"
AquaHideout_UnusedRubyMap1_EventScript_TryRemoveZapdos_Galarian::
# 18 "data/maps/AquaHideout_UnusedRubyMap1/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 19 "data/maps/AquaHideout_UnusedRubyMap1/scripts.pory"
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
# 20 "data/maps/AquaHideout_UnusedRubyMap1/scripts.pory"
	removeobject VAR_LAST_TALKED
# 21 "data/maps/AquaHideout_UnusedRubyMap1/scripts.pory"
	return
# 22 "data/maps/AquaHideout_UnusedRubyMap1/scripts.pory"

# 23 "data/maps/AquaHideout_UnusedRubyMap1/scripts.pory"
AquaHideout_UnusedRubyMap1_EventScript_Zapdos::
# 24 "data/maps/AquaHideout_UnusedRubyMap1/scripts.pory"
    lock
# 25 "data/maps/AquaHideout_UnusedRubyMap1/scripts.pory"
    faceplayer
# 26 "data/maps/AquaHideout_UnusedRubyMap1/scripts.pory"
    waitse
# 27 "data/maps/AquaHideout_UnusedRubyMap1/scripts.pory"
    playmoncry SPECIES_ZAPDOS, CRY_MODE_ENCOUNTER
# 28 "data/maps/AquaHideout_UnusedRubyMap1/scripts.pory"
    delay 40
# 29 "data/maps/AquaHideout_UnusedRubyMap1/scripts.pory"
    waitmoncry
# 30 "data/maps/AquaHideout_UnusedRubyMap1/scripts.pory"
    setwildbattle SPECIES_ZAPDOS, 40
# 31 "data/maps/AquaHideout_UnusedRubyMap1/scripts.pory"
    setflag FLAG_SYS_CTRL_OBJ_DELETE
# 32 "data/maps/AquaHideout_UnusedRubyMap1/scripts.pory"
    special BattleSetup_StartLegendaryBattle
# 33 "data/maps/AquaHideout_UnusedRubyMap1/scripts.pory"
    waitstate
# 34 "data/maps/AquaHideout_UnusedRubyMap1/scripts.pory"
    clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 35 "data/maps/AquaHideout_UnusedRubyMap1/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 36 "data/maps/AquaHideout_UnusedRubyMap1/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_WON, AquaHideout_UnusedRubyMap1_EventScript_DefeatedZapdos
# 37 "data/maps/AquaHideout_UnusedRubyMap1/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_RAN, AquaHideout_UnusedRubyMap1_EventScript_RanFromZapdos
# 38 "data/maps/AquaHideout_UnusedRubyMap1/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, AquaHideout_UnusedRubyMap1_EventScript_RanFromZapdos
# 39 "data/maps/AquaHideout_UnusedRubyMap1/scripts.pory"
    setflag FLAG_DEFEATED_ZAPDOS
# 40 "data/maps/AquaHideout_UnusedRubyMap1/scripts.pory"
    release
# 41 "data/maps/AquaHideout_UnusedRubyMap1/scripts.pory"
    end
# 42 "data/maps/AquaHideout_UnusedRubyMap1/scripts.pory"

# 43 "data/maps/AquaHideout_UnusedRubyMap1/scripts.pory"

# 44 "data/maps/AquaHideout_UnusedRubyMap1/scripts.pory"
AquaHideout_UnusedRubyMap1_EventScript_DefeatedZapdos::
# 45 "data/maps/AquaHideout_UnusedRubyMap1/scripts.pory"
    setflag FLAG_DEFEATED_ZAPDOS
# 46 "data/maps/AquaHideout_UnusedRubyMap1/scripts.pory"
    goto Common_EventScript_RemoveStaticPokemon
# 47 "data/maps/AquaHideout_UnusedRubyMap1/scripts.pory"
    end
# 48 "data/maps/AquaHideout_UnusedRubyMap1/scripts.pory"

# 49 "data/maps/AquaHideout_UnusedRubyMap1/scripts.pory"

# 50 "data/maps/AquaHideout_UnusedRubyMap1/scripts.pory"
AquaHideout_UnusedRubyMap1_EventScript_RanFromZapdos::
# 51 "data/maps/AquaHideout_UnusedRubyMap1/scripts.pory"
    setvar VAR_0x8004, SPECIES_ZAPDOS
# 52 "data/maps/AquaHideout_UnusedRubyMap1/scripts.pory"
    goto Common_EventScript_LegendaryFlewAway
# 53 "data/maps/AquaHideout_UnusedRubyMap1/scripts.pory"
    end
# 54 "data/maps/AquaHideout_UnusedRubyMap1/scripts.pory"

# 55 "data/maps/AquaHideout_UnusedRubyMap1/scripts.pory"
AquaHideout_UnusedRubyMap1_EventScript_Zapdos_Galarian::
# 56 "data/maps/AquaHideout_UnusedRubyMap1/scripts.pory"
    lock
# 57 "data/maps/AquaHideout_UnusedRubyMap1/scripts.pory"
    faceplayer
# 58 "data/maps/AquaHideout_UnusedRubyMap1/scripts.pory"
    waitse
# 59 "data/maps/AquaHideout_UnusedRubyMap1/scripts.pory"
    playmoncry SPECIES_ZAPDOS_GALARIAN, CRY_MODE_ENCOUNTER
# 60 "data/maps/AquaHideout_UnusedRubyMap1/scripts.pory"
    delay 40
# 61 "data/maps/AquaHideout_UnusedRubyMap1/scripts.pory"
    waitmoncry
# 62 "data/maps/AquaHideout_UnusedRubyMap1/scripts.pory"
    setwildbattle SPECIES_ZAPDOS_GALARIAN, 40
# 63 "data/maps/AquaHideout_UnusedRubyMap1/scripts.pory"
    setflag FLAG_SYS_CTRL_OBJ_DELETE
# 64 "data/maps/AquaHideout_UnusedRubyMap1/scripts.pory"
    special BattleSetup_StartLegendaryBattle
# 65 "data/maps/AquaHideout_UnusedRubyMap1/scripts.pory"
    waitstate
# 66 "data/maps/AquaHideout_UnusedRubyMap1/scripts.pory"
    clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 67 "data/maps/AquaHideout_UnusedRubyMap1/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 68 "data/maps/AquaHideout_UnusedRubyMap1/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_WON, AquaHideout_UnusedRubyMap1_EventScript_DefeatedZapdosG
# 69 "data/maps/AquaHideout_UnusedRubyMap1/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_RAN, AquaHideout_UnusedRubyMap1_EventScript_RanFromZapdosG
# 70 "data/maps/AquaHideout_UnusedRubyMap1/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, AquaHideout_UnusedRubyMap1_EventScript_RanFromZapdosG
# 71 "data/maps/AquaHideout_UnusedRubyMap1/scripts.pory"
    setflag FLAG_DEFEATED_ZAPDOS_GALARIAN
# 72 "data/maps/AquaHideout_UnusedRubyMap1/scripts.pory"
    release
# 73 "data/maps/AquaHideout_UnusedRubyMap1/scripts.pory"
    end
# 74 "data/maps/AquaHideout_UnusedRubyMap1/scripts.pory"

# 75 "data/maps/AquaHideout_UnusedRubyMap1/scripts.pory"

# 76 "data/maps/AquaHideout_UnusedRubyMap1/scripts.pory"
AquaHideout_UnusedRubyMap1_EventScript_DefeatedZapdosG::
# 77 "data/maps/AquaHideout_UnusedRubyMap1/scripts.pory"
    setflag FLAG_DEFEATED_ZAPDOS_GALARIAN
# 78 "data/maps/AquaHideout_UnusedRubyMap1/scripts.pory"
    goto Common_EventScript_RemoveStaticPokemon
# 79 "data/maps/AquaHideout_UnusedRubyMap1/scripts.pory"
    end
# 80 "data/maps/AquaHideout_UnusedRubyMap1/scripts.pory"

# 81 "data/maps/AquaHideout_UnusedRubyMap1/scripts.pory"

# 82 "data/maps/AquaHideout_UnusedRubyMap1/scripts.pory"
AquaHideout_UnusedRubyMap1_EventScript_RanFromZapdosG::
# 83 "data/maps/AquaHideout_UnusedRubyMap1/scripts.pory"
    setvar VAR_0x8004, SPECIES_ZAPDOS_GALARIAN
# 84 "data/maps/AquaHideout_UnusedRubyMap1/scripts.pory"
    goto Common_EventScript_LegendaryFlewAway
# 85 "data/maps/AquaHideout_UnusedRubyMap1/scripts.pory"
    end
