# 1 "data/maps/AncientTomb/scripts.pory"

# 2 "data/maps/AncientTomb/scripts.pory"
AncientTomb_MapScripts::
# 3 "data/maps/AncientTomb/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, AncientTomb_OnResume
# 4 "data/maps/AncientTomb/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, AncientTomb_OnLoad
# 5 "data/maps/AncientTomb/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, AncientTomb_OnTransition
# 6 "data/maps/AncientTomb/scripts.pory"
	.byte 0
# 7 "data/maps/AncientTomb/scripts.pory"

# 8 "data/maps/AncientTomb/scripts.pory"
AncientTomb_OnResume:
# 9 "data/maps/AncientTomb/scripts.pory"
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, AncientTomb_EventScript_TryRemoveRegisteel
# 10 "data/maps/AncientTomb/scripts.pory"
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, AncientTomb_EventScript_TryRemoveRegieleki
# 11 "data/maps/AncientTomb/scripts.pory"
	end
# 12 "data/maps/AncientTomb/scripts.pory"

# 13 "data/maps/AncientTomb/scripts.pory"
AncientTomb_EventScript_TryRemoveRegisteel::
# 14 "data/maps/AncientTomb/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 15 "data/maps/AncientTomb/scripts.pory"
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
# 16 "data/maps/AncientTomb/scripts.pory"
	removeobject VAR_LAST_TALKED
# 17 "data/maps/AncientTomb/scripts.pory"
	return
# 18 "data/maps/AncientTomb/scripts.pory"

# 19 "data/maps/AncientTomb/scripts.pory"
AncientTomb_EventScript_TryRemoveRegieleki::
# 20 "data/maps/AncientTomb/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 21 "data/maps/AncientTomb/scripts.pory"
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
# 22 "data/maps/AncientTomb/scripts.pory"
	removeobject VAR_LAST_TALKED
# 23 "data/maps/AncientTomb/scripts.pory"
	return
# 24 "data/maps/AncientTomb/scripts.pory"

# 25 "data/maps/AncientTomb/scripts.pory"
AncientTomb_OnTransition:
# 26 "data/maps/AncientTomb/scripts.pory"
	setflag FLAG_LANDMARK_ANCIENT_TOMB
# 27 "data/maps/AncientTomb/scripts.pory"
	call_if_unset FLAG_DEFEATED_REGISTEEL, AncientTomb_EventScript_ShowRegisteel
# 28 "data/maps/AncientTomb/scripts.pory"
	end
# 29 "data/maps/AncientTomb/scripts.pory"

# 30 "data/maps/AncientTomb/scripts.pory"
AncientTomb_EventScript_ShowRegisteel::
# 31 "data/maps/AncientTomb/scripts.pory"
	clearflag FLAG_HIDE_REGISTEEL
# 32 "data/maps/AncientTomb/scripts.pory"
	return
# 33 "data/maps/AncientTomb/scripts.pory"

# 34 "data/maps/AncientTomb/scripts.pory"
AncientTomb_OnLoad:
# 35 "data/maps/AncientTomb/scripts.pory"
	call_if_unset FLAG_SYS_REGISTEEL_PUZZLE_COMPLETED, AncientTomb_EventScript_HideRegiEntrance
# 36 "data/maps/AncientTomb/scripts.pory"
	end
# 37 "data/maps/AncientTomb/scripts.pory"

# 38 "data/maps/AncientTomb/scripts.pory"
AncientTomb_EventScript_HideRegiEntrance::
# 39 "data/maps/AncientTomb/scripts.pory"
	setmetatile 7, 19, METATILE_Cave_EntranceCover, TRUE
# 40 "data/maps/AncientTomb/scripts.pory"
	setmetatile 8, 19, METATILE_Cave_EntranceCover, TRUE
# 41 "data/maps/AncientTomb/scripts.pory"
	setmetatile 9, 19, METATILE_Cave_EntranceCover, TRUE
# 42 "data/maps/AncientTomb/scripts.pory"
	setmetatile 7, 20, METATILE_Cave_SealedChamberBraille_Mid, TRUE
# 43 "data/maps/AncientTomb/scripts.pory"
	setmetatile 8, 20, METATILE_Cave_SealedChamberBraille_Mid, TRUE
# 44 "data/maps/AncientTomb/scripts.pory"
	setmetatile 9, 20, METATILE_Cave_SealedChamberBraille_Mid, TRUE
# 45 "data/maps/AncientTomb/scripts.pory"
	return
# 46 "data/maps/AncientTomb/scripts.pory"

# 47 "data/maps/AncientTomb/scripts.pory"
AncientTomb_EventScript_CaveEntranceMiddle::
# 48 "data/maps/AncientTomb/scripts.pory"
	lockall
# 49 "data/maps/AncientTomb/scripts.pory"
	goto_if_set FLAG_SYS_REGISTEEL_PUZZLE_COMPLETED, AncientTomb_EventScript_BigHoleInWall
# 50 "data/maps/AncientTomb/scripts.pory"
	braillemsgbox AncientTomb_Braille_ShineInTheMiddle
# 51 "data/maps/AncientTomb/scripts.pory"
	releaseall
# 52 "data/maps/AncientTomb/scripts.pory"
	end
# 53 "data/maps/AncientTomb/scripts.pory"

# 54 "data/maps/AncientTomb/scripts.pory"
AncientTomb_EventScript_BigHoleInWall::
# 55 "data/maps/AncientTomb/scripts.pory"
	msgbox gText_BigHoleInTheWall, MSGBOX_DEFAULT
# 56 "data/maps/AncientTomb/scripts.pory"
	releaseall
# 57 "data/maps/AncientTomb/scripts.pory"
	end
# 58 "data/maps/AncientTomb/scripts.pory"

# 59 "data/maps/AncientTomb/scripts.pory"
AncientTomb_EventScript_CaveEntranceSide::
# 60 "data/maps/AncientTomb/scripts.pory"
	lockall
# 61 "data/maps/AncientTomb/scripts.pory"
	braillemsgbox AncientTomb_Braille_ShineInTheMiddle
# 62 "data/maps/AncientTomb/scripts.pory"
	releaseall
# 63 "data/maps/AncientTomb/scripts.pory"
	end
# 64 "data/maps/AncientTomb/scripts.pory"

# 65 "data/maps/AncientTomb/scripts.pory"
AncientTomb_EventScript_Registeel::
# 66 "data/maps/AncientTomb/scripts.pory"
	lock
# 67 "data/maps/AncientTomb/scripts.pory"
	faceplayer
# 68 "data/maps/AncientTomb/scripts.pory"
	waitse
# 69 "data/maps/AncientTomb/scripts.pory"
	playmoncry SPECIES_REGISTEEL, CRY_MODE_ENCOUNTER
# 70 "data/maps/AncientTomb/scripts.pory"
	delay 40
# 71 "data/maps/AncientTomb/scripts.pory"
	waitmoncry
# 72 "data/maps/AncientTomb/scripts.pory"
	setwildbattle SPECIES_REGISTEEL, 40
# 73 "data/maps/AncientTomb/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 74 "data/maps/AncientTomb/scripts.pory"
	special StartRegiBattle
# 75 "data/maps/AncientTomb/scripts.pory"
	waitstate
# 76 "data/maps/AncientTomb/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 77 "data/maps/AncientTomb/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 78 "data/maps/AncientTomb/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, AncientTomb_EventScript_DefeatedRegisteel
# 79 "data/maps/AncientTomb/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, AncientTomb_EventScript_RanFromRegisteel
# 80 "data/maps/AncientTomb/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, AncientTomb_EventScript_RanFromRegisteel
# 81 "data/maps/AncientTomb/scripts.pory"
	setflag FLAG_DEFEATED_REGISTEEL
# 82 "data/maps/AncientTomb/scripts.pory"
	release
# 83 "data/maps/AncientTomb/scripts.pory"
	end
# 84 "data/maps/AncientTomb/scripts.pory"

# 85 "data/maps/AncientTomb/scripts.pory"
AncientTomb_EventScript_DefeatedRegisteel::
# 86 "data/maps/AncientTomb/scripts.pory"
	setflag FLAG_DEFEATED_REGISTEEL
# 87 "data/maps/AncientTomb/scripts.pory"
	goto Common_EventScript_RemoveStaticPokemon
# 88 "data/maps/AncientTomb/scripts.pory"
	end
# 89 "data/maps/AncientTomb/scripts.pory"

# 90 "data/maps/AncientTomb/scripts.pory"
AncientTomb_EventScript_RanFromRegisteel::
# 91 "data/maps/AncientTomb/scripts.pory"
	setvar VAR_0x8004, SPECIES_REGISTEEL
# 92 "data/maps/AncientTomb/scripts.pory"
	goto Common_EventScript_LegendaryFlewAway
# 93 "data/maps/AncientTomb/scripts.pory"
	end
# 94 "data/maps/AncientTomb/scripts.pory"

# 95 "data/maps/AncientTomb/scripts.pory"
AncientTomb_EventScript_Regieleki::
# 96 "data/maps/AncientTomb/scripts.pory"
    lock
# 97 "data/maps/AncientTomb/scripts.pory"
    faceplayer
# 98 "data/maps/AncientTomb/scripts.pory"
    waitse
# 99 "data/maps/AncientTomb/scripts.pory"
    playmoncry SPECIES_REGIELEKI, CRY_MODE_ENCOUNTER
# 100 "data/maps/AncientTomb/scripts.pory"
    delay 40
# 101 "data/maps/AncientTomb/scripts.pory"
    waitmoncry
# 102 "data/maps/AncientTomb/scripts.pory"
    setwildbattle SPECIES_REGIELEKI, 40
# 103 "data/maps/AncientTomb/scripts.pory"
    setflag FLAG_SYS_CTRL_OBJ_DELETE
# 104 "data/maps/AncientTomb/scripts.pory"
    special StartRegiBattle
# 105 "data/maps/AncientTomb/scripts.pory"
    waitstate
# 106 "data/maps/AncientTomb/scripts.pory"
    clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 107 "data/maps/AncientTomb/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 108 "data/maps/AncientTomb/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_WON, AncientTomb_EventScript_DefeatedRegieleki
# 109 "data/maps/AncientTomb/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_RAN, AncientTomb_EventScript_RanFromRegieleki
# 110 "data/maps/AncientTomb/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, AncientTomb_EventScript_RanFromRegieleki
# 111 "data/maps/AncientTomb/scripts.pory"
    setflag FLAG_DEFEATED_REGIELEKI
# 112 "data/maps/AncientTomb/scripts.pory"
    release
# 113 "data/maps/AncientTomb/scripts.pory"
    end
# 114 "data/maps/AncientTomb/scripts.pory"

# 115 "data/maps/AncientTomb/scripts.pory"

# 116 "data/maps/AncientTomb/scripts.pory"
AncientTomb_EventScript_DefeatedRegieleki::
# 117 "data/maps/AncientTomb/scripts.pory"
    setflag FLAG_DEFEATED_REGIELEKI
# 118 "data/maps/AncientTomb/scripts.pory"
    goto Common_EventScript_RemoveStaticPokemon
# 119 "data/maps/AncientTomb/scripts.pory"
    end
# 120 "data/maps/AncientTomb/scripts.pory"

# 121 "data/maps/AncientTomb/scripts.pory"

# 122 "data/maps/AncientTomb/scripts.pory"
AncientTomb_EventScript_RanFromRegieleki::
# 123 "data/maps/AncientTomb/scripts.pory"
    setvar VAR_0x8004, SPECIES_REGIELEKI
# 124 "data/maps/AncientTomb/scripts.pory"
    goto Common_EventScript_LegendaryFlewAway
# 125 "data/maps/AncientTomb/scripts.pory"
    end
