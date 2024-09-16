AquaHideout_UnusedRubyMap2_MapScripts::
	.byte 0


AHURM2_EventScript_Sign::
# 5 "data/maps/AquaHideout_UnusedRubyMap2/scripts.pory"
	lockall
# 6 "data/maps/AquaHideout_UnusedRubyMap2/scripts.pory"
	msgbox AHURM2_EventScript_Sign_Text_0
# 8 "data/maps/AquaHideout_UnusedRubyMap2/scripts.pory"
	releaseall
	return


# 12 "data/maps/AquaHideout_UnusedRubyMap2/scripts.pory"

# 13 "data/maps/AquaHideout_UnusedRubyMap2/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, AquaHideout_UnusedRubyMap2_OnResume
# 14 "data/maps/AquaHideout_UnusedRubyMap2/scripts.pory"
	.byte 0
# 15 "data/maps/AquaHideout_UnusedRubyMap2/scripts.pory"

# 16 "data/maps/AquaHideout_UnusedRubyMap2/scripts.pory"
AquaHideout_UnusedRubyMap2_OnResume:
# 17 "data/maps/AquaHideout_UnusedRubyMap2/scripts.pory"
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, AquaHideout_UnusedRubyMap2_EventScript_TryRemoveMagearna
# 18 "data/maps/AquaHideout_UnusedRubyMap2/scripts.pory"
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, AquaHideout_UnusedRubyMap2_EventScript_TryRemoveMagearna_Original_Color
# 19 "data/maps/AquaHideout_UnusedRubyMap2/scripts.pory"
	end
# 20 "data/maps/AquaHideout_UnusedRubyMap2/scripts.pory"

# 21 "data/maps/AquaHideout_UnusedRubyMap2/scripts.pory"
AquaHideout_UnusedRubyMap2_EventScript_TryRemoveMagearna::
# 22 "data/maps/AquaHideout_UnusedRubyMap2/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 23 "data/maps/AquaHideout_UnusedRubyMap2/scripts.pory"
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
# 24 "data/maps/AquaHideout_UnusedRubyMap2/scripts.pory"
	removeobject VAR_LAST_TALKED
# 25 "data/maps/AquaHideout_UnusedRubyMap2/scripts.pory"
	return
# 26 "data/maps/AquaHideout_UnusedRubyMap2/scripts.pory"

# 27 "data/maps/AquaHideout_UnusedRubyMap2/scripts.pory"
AquaHideout_UnusedRubyMap2_EventScript_TryRemoveMagearna_Original_Color::
# 28 "data/maps/AquaHideout_UnusedRubyMap2/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 29 "data/maps/AquaHideout_UnusedRubyMap2/scripts.pory"
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
# 30 "data/maps/AquaHideout_UnusedRubyMap2/scripts.pory"
	removeobject VAR_LAST_TALKED
# 31 "data/maps/AquaHideout_UnusedRubyMap2/scripts.pory"
	return
# 32 "data/maps/AquaHideout_UnusedRubyMap2/scripts.pory"

# 33 "data/maps/AquaHideout_UnusedRubyMap2/scripts.pory"
AquaHideout_UnusedRubyMap2_EventScript_Magearna::
# 34 "data/maps/AquaHideout_UnusedRubyMap2/scripts.pory"
    lock
# 35 "data/maps/AquaHideout_UnusedRubyMap2/scripts.pory"
    faceplayer
# 36 "data/maps/AquaHideout_UnusedRubyMap2/scripts.pory"
    waitse
# 37 "data/maps/AquaHideout_UnusedRubyMap2/scripts.pory"
    playmoncry SPECIES_MAGEARNA, CRY_MODE_ENCOUNTER
# 38 "data/maps/AquaHideout_UnusedRubyMap2/scripts.pory"
    delay 40
# 39 "data/maps/AquaHideout_UnusedRubyMap2/scripts.pory"
    waitmoncry
# 40 "data/maps/AquaHideout_UnusedRubyMap2/scripts.pory"
    setwildbattle SPECIES_MAGEARNA, 20
# 41 "data/maps/AquaHideout_UnusedRubyMap2/scripts.pory"
    setflag FLAG_SYS_CTRL_OBJ_DELETE
# 42 "data/maps/AquaHideout_UnusedRubyMap2/scripts.pory"
    special BattleSetup_StartLegendaryBattle
# 43 "data/maps/AquaHideout_UnusedRubyMap2/scripts.pory"
    waitstate
# 44 "data/maps/AquaHideout_UnusedRubyMap2/scripts.pory"
    clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 45 "data/maps/AquaHideout_UnusedRubyMap2/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 46 "data/maps/AquaHideout_UnusedRubyMap2/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_WON, AquaHideout_UnusedRubyMap2_EventScript_DefeatedMagearna
# 47 "data/maps/AquaHideout_UnusedRubyMap2/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_RAN, AquaHideout_UnusedRubyMap2_EventScript_RanFromMagearna
# 48 "data/maps/AquaHideout_UnusedRubyMap2/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, AquaHideout_UnusedRubyMap2_EventScript_RanFromMagearna
# 49 "data/maps/AquaHideout_UnusedRubyMap2/scripts.pory"
    setflag FLAG_DEFEATED_MAGEARNA
# 50 "data/maps/AquaHideout_UnusedRubyMap2/scripts.pory"
    release
# 51 "data/maps/AquaHideout_UnusedRubyMap2/scripts.pory"
    end
# 52 "data/maps/AquaHideout_UnusedRubyMap2/scripts.pory"

# 53 "data/maps/AquaHideout_UnusedRubyMap2/scripts.pory"

# 54 "data/maps/AquaHideout_UnusedRubyMap2/scripts.pory"
AquaHideout_UnusedRubyMap2_EventScript_DefeatedMagearna::
# 55 "data/maps/AquaHideout_UnusedRubyMap2/scripts.pory"
    setflag FLAG_DEFEATED_MAGEARNA
# 56 "data/maps/AquaHideout_UnusedRubyMap2/scripts.pory"
    goto Common_EventScript_RemoveStaticPokemon
# 57 "data/maps/AquaHideout_UnusedRubyMap2/scripts.pory"
    end
# 58 "data/maps/AquaHideout_UnusedRubyMap2/scripts.pory"

# 59 "data/maps/AquaHideout_UnusedRubyMap2/scripts.pory"

# 60 "data/maps/AquaHideout_UnusedRubyMap2/scripts.pory"
AquaHideout_UnusedRubyMap2_EventScript_RanFromMagearna::
# 61 "data/maps/AquaHideout_UnusedRubyMap2/scripts.pory"
    setvar VAR_0x8004, SPECIES_MAGEARNA
# 62 "data/maps/AquaHideout_UnusedRubyMap2/scripts.pory"
    goto Common_EventScript_LegendaryFlewAway
# 63 "data/maps/AquaHideout_UnusedRubyMap2/scripts.pory"
    end
# 64 "data/maps/AquaHideout_UnusedRubyMap2/scripts.pory"

# 65 "data/maps/AquaHideout_UnusedRubyMap2/scripts.pory"
AquaHideout_UnusedRubyMap2_EventScript_Magearna_Original_Color::
# 66 "data/maps/AquaHideout_UnusedRubyMap2/scripts.pory"
    lock
# 67 "data/maps/AquaHideout_UnusedRubyMap2/scripts.pory"
    faceplayer
# 68 "data/maps/AquaHideout_UnusedRubyMap2/scripts.pory"
    waitse
# 69 "data/maps/AquaHideout_UnusedRubyMap2/scripts.pory"
    playmoncry SPECIES_MAGEARNA_ORIGINAL_COLOR, CRY_MODE_ENCOUNTER
# 70 "data/maps/AquaHideout_UnusedRubyMap2/scripts.pory"
    delay 40
# 71 "data/maps/AquaHideout_UnusedRubyMap2/scripts.pory"
    waitmoncry
# 72 "data/maps/AquaHideout_UnusedRubyMap2/scripts.pory"
    setwildbattle SPECIES_MAGEARNA_ORIGINAL_COLOR, 20
# 73 "data/maps/AquaHideout_UnusedRubyMap2/scripts.pory"
    setflag FLAG_SYS_CTRL_OBJ_DELETE
# 74 "data/maps/AquaHideout_UnusedRubyMap2/scripts.pory"
    special BattleSetup_StartLegendaryBattle
# 75 "data/maps/AquaHideout_UnusedRubyMap2/scripts.pory"
    waitstate
# 76 "data/maps/AquaHideout_UnusedRubyMap2/scripts.pory"
    clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 77 "data/maps/AquaHideout_UnusedRubyMap2/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 78 "data/maps/AquaHideout_UnusedRubyMap2/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_WON, AquaHideout_UnusedRubyMap2_EventScript_DefeatedMagearnao
# 79 "data/maps/AquaHideout_UnusedRubyMap2/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_RAN, AquaHideout_UnusedRubyMap2_EventScript_RanFromMagearnao
# 80 "data/maps/AquaHideout_UnusedRubyMap2/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, AquaHideout_UnusedRubyMap2_EventScript_RanFromMagearnao
# 81 "data/maps/AquaHideout_UnusedRubyMap2/scripts.pory"
    setflag FLAG_DEFEATED_MAGEARNA_ORIGINAL_COLOR
# 82 "data/maps/AquaHideout_UnusedRubyMap2/scripts.pory"
    release
# 83 "data/maps/AquaHideout_UnusedRubyMap2/scripts.pory"
    end
# 84 "data/maps/AquaHideout_UnusedRubyMap2/scripts.pory"

# 85 "data/maps/AquaHideout_UnusedRubyMap2/scripts.pory"

# 86 "data/maps/AquaHideout_UnusedRubyMap2/scripts.pory"
AquaHideout_UnusedRubyMap2_EventScript_DefeatedMagearnao::
# 87 "data/maps/AquaHideout_UnusedRubyMap2/scripts.pory"
    setflag FLAG_DEFEATED_MAGEARNA_ORIGINAL_COLOR
# 88 "data/maps/AquaHideout_UnusedRubyMap2/scripts.pory"
    goto Common_EventScript_RemoveStaticPokemon
# 89 "data/maps/AquaHideout_UnusedRubyMap2/scripts.pory"
    end
# 90 "data/maps/AquaHideout_UnusedRubyMap2/scripts.pory"

# 91 "data/maps/AquaHideout_UnusedRubyMap2/scripts.pory"

# 92 "data/maps/AquaHideout_UnusedRubyMap2/scripts.pory"
AquaHideout_UnusedRubyMap2_EventScript_RanFromMagearnao::
# 93 "data/maps/AquaHideout_UnusedRubyMap2/scripts.pory"
    setvar VAR_0x8004, SPECIES_MAGEARNA_ORIGINAL_COLOR
# 94 "data/maps/AquaHideout_UnusedRubyMap2/scripts.pory"
    goto Common_EventScript_LegendaryFlewAway
# 95 "data/maps/AquaHideout_UnusedRubyMap2/scripts.pory"
    end

AHURM2_EventScript_Sign_Text_0:
# 6 "data/maps/AquaHideout_UnusedRubyMap2/scripts.pory"
	.string "BLACK MARKET\p"
	.string "Do not use key items or pay the price!\p"
	.string "$"
