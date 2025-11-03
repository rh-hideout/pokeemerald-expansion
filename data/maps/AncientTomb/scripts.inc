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
	end
# 11 "data/maps/AncientTomb/scripts.pory"

# 12 "data/maps/AncientTomb/scripts.pory"
AncientTomb_EventScript_TryRemoveRegisteel::
# 13 "data/maps/AncientTomb/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 14 "data/maps/AncientTomb/scripts.pory"
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
# 15 "data/maps/AncientTomb/scripts.pory"
	removeobject VAR_LAST_TALKED
# 16 "data/maps/AncientTomb/scripts.pory"
	return
# 17 "data/maps/AncientTomb/scripts.pory"

# 18 "data/maps/AncientTomb/scripts.pory"
AncientTomb_OnTransition:
# 19 "data/maps/AncientTomb/scripts.pory"
	setflag FLAG_LANDMARK_ANCIENT_TOMB
# 20 "data/maps/AncientTomb/scripts.pory"
	call_if_unset FLAG_DEFEATED_REGISTEEL, AncientTomb_EventScript_ShowRegisteel
# 21 "data/maps/AncientTomb/scripts.pory"
	end
# 22 "data/maps/AncientTomb/scripts.pory"

# 23 "data/maps/AncientTomb/scripts.pory"
AncientTomb_EventScript_ShowRegisteel::
# 24 "data/maps/AncientTomb/scripts.pory"
	clearflag FLAG_HIDE_REGISTEEL
# 25 "data/maps/AncientTomb/scripts.pory"
	return
# 26 "data/maps/AncientTomb/scripts.pory"

# 27 "data/maps/AncientTomb/scripts.pory"
AncientTomb_OnLoad:
# 28 "data/maps/AncientTomb/scripts.pory"
	call_if_unset FLAG_SYS_REGISTEEL_PUZZLE_COMPLETED, AncientTomb_EventScript_HideRegiEntrance
# 29 "data/maps/AncientTomb/scripts.pory"
	end
# 30 "data/maps/AncientTomb/scripts.pory"

# 31 "data/maps/AncientTomb/scripts.pory"
AncientTomb_EventScript_HideRegiEntrance::
# 32 "data/maps/AncientTomb/scripts.pory"
	setmetatile 7, 19, METATILE_Cave_EntranceCover, TRUE
# 33 "data/maps/AncientTomb/scripts.pory"
	setmetatile 8, 19, METATILE_Cave_EntranceCover, TRUE
# 34 "data/maps/AncientTomb/scripts.pory"
	setmetatile 9, 19, METATILE_Cave_EntranceCover, TRUE
# 35 "data/maps/AncientTomb/scripts.pory"
	setmetatile 7, 20, METATILE_Cave_SealedChamberBraille_Mid, TRUE
# 36 "data/maps/AncientTomb/scripts.pory"
	setmetatile 8, 20, METATILE_Cave_SealedChamberBraille_Mid, TRUE
# 37 "data/maps/AncientTomb/scripts.pory"
	setmetatile 9, 20, METATILE_Cave_SealedChamberBraille_Mid, TRUE
# 38 "data/maps/AncientTomb/scripts.pory"
	return
# 39 "data/maps/AncientTomb/scripts.pory"

# 40 "data/maps/AncientTomb/scripts.pory"
AncientTomb_EventScript_CaveEntranceMiddle::
# 41 "data/maps/AncientTomb/scripts.pory"
	lockall
# 42 "data/maps/AncientTomb/scripts.pory"
	goto_if_set FLAG_SYS_REGISTEEL_PUZZLE_COMPLETED, AncientTomb_EventScript_BigHoleInWall
# 43 "data/maps/AncientTomb/scripts.pory"
	braillemsgbox AncientTomb_Braille_ShineInTheMiddle
# 44 "data/maps/AncientTomb/scripts.pory"
	releaseall
# 45 "data/maps/AncientTomb/scripts.pory"
	end
# 46 "data/maps/AncientTomb/scripts.pory"

# 47 "data/maps/AncientTomb/scripts.pory"
AncientTomb_EventScript_BigHoleInWall::
# 48 "data/maps/AncientTomb/scripts.pory"
	msgbox gText_BigHoleInTheWall, MSGBOX_DEFAULT
# 49 "data/maps/AncientTomb/scripts.pory"
	releaseall
# 50 "data/maps/AncientTomb/scripts.pory"
	end
# 51 "data/maps/AncientTomb/scripts.pory"

# 52 "data/maps/AncientTomb/scripts.pory"
AncientTomb_EventScript_CaveEntranceSide::
# 53 "data/maps/AncientTomb/scripts.pory"
	lockall
# 54 "data/maps/AncientTomb/scripts.pory"
	braillemsgbox AncientTomb_Braille_ShineInTheMiddle
# 55 "data/maps/AncientTomb/scripts.pory"
	releaseall
# 56 "data/maps/AncientTomb/scripts.pory"
	end
# 57 "data/maps/AncientTomb/scripts.pory"

# 58 "data/maps/AncientTomb/scripts.pory"
AncientTomb_EventScript_Registeel::
# 59 "data/maps/AncientTomb/scripts.pory"
	lock
# 60 "data/maps/AncientTomb/scripts.pory"
	faceplayer
# 61 "data/maps/AncientTomb/scripts.pory"
	waitse
# 62 "data/maps/AncientTomb/scripts.pory"
	playmoncry SPECIES_REGISTEEL, CRY_MODE_ENCOUNTER
# 63 "data/maps/AncientTomb/scripts.pory"
	delay 40
# 64 "data/maps/AncientTomb/scripts.pory"
	waitmoncry
# 65 "data/maps/AncientTomb/scripts.pory"
	setwildbattle SPECIES_REGISTEEL, 40
# 66 "data/maps/AncientTomb/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 67 "data/maps/AncientTomb/scripts.pory"
	special StartRegiBattle
# 68 "data/maps/AncientTomb/scripts.pory"
	waitstate
# 69 "data/maps/AncientTomb/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 70 "data/maps/AncientTomb/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 71 "data/maps/AncientTomb/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, AncientTomb_EventScript_DefeatedRegisteel
# 72 "data/maps/AncientTomb/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, AncientTomb_EventScript_RanFromRegisteel
# 73 "data/maps/AncientTomb/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, AncientTomb_EventScript_RanFromRegisteel
# 74 "data/maps/AncientTomb/scripts.pory"
	setflag FLAG_DEFEATED_REGISTEEL
# 75 "data/maps/AncientTomb/scripts.pory"
	release
# 76 "data/maps/AncientTomb/scripts.pory"
	end
# 77 "data/maps/AncientTomb/scripts.pory"

# 78 "data/maps/AncientTomb/scripts.pory"
AncientTomb_EventScript_DefeatedRegisteel::
# 79 "data/maps/AncientTomb/scripts.pory"
	setflag FLAG_DEFEATED_REGISTEEL
# 80 "data/maps/AncientTomb/scripts.pory"
	goto Common_EventScript_RemoveStaticPokemon
# 81 "data/maps/AncientTomb/scripts.pory"
	end
# 82 "data/maps/AncientTomb/scripts.pory"

# 83 "data/maps/AncientTomb/scripts.pory"
AncientTomb_EventScript_RanFromRegisteel::
# 84 "data/maps/AncientTomb/scripts.pory"
	setvar VAR_0x8004, SPECIES_REGISTEEL
# 85 "data/maps/AncientTomb/scripts.pory"
	goto Common_EventScript_LegendaryFlewAway
# 86 "data/maps/AncientTomb/scripts.pory"
	end
