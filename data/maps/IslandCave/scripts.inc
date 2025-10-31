# 1 "data/maps/IslandCave/scripts.pory"

# 2 "data/maps/IslandCave/scripts.pory"
IslandCave_MapScripts::
# 3 "data/maps/IslandCave/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, IslandCave_OnResume
# 4 "data/maps/IslandCave/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, IslandCave_OnLoad
# 5 "data/maps/IslandCave/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, IslandCave_OnTransition
# 6 "data/maps/IslandCave/scripts.pory"
	.byte 0
# 7 "data/maps/IslandCave/scripts.pory"

# 8 "data/maps/IslandCave/scripts.pory"
IslandCave_OnResume:
# 9 "data/maps/IslandCave/scripts.pory"
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, IslandCave_EventScript_TryRemoveRegice
# 10 "data/maps/IslandCave/scripts.pory"
	end
# 11 "data/maps/IslandCave/scripts.pory"

# 12 "data/maps/IslandCave/scripts.pory"
IslandCave_EventScript_TryRemoveRegice::
# 13 "data/maps/IslandCave/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 14 "data/maps/IslandCave/scripts.pory"
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
# 15 "data/maps/IslandCave/scripts.pory"
	removeobject VAR_LAST_TALKED
# 16 "data/maps/IslandCave/scripts.pory"
	return
# 17 "data/maps/IslandCave/scripts.pory"

# 18 "data/maps/IslandCave/scripts.pory"
IslandCave_OnLoad:
# 19 "data/maps/IslandCave/scripts.pory"
	call_if_unset FLAG_SYS_BRAILLE_REGICE_COMPLETED, IslandCave_EventScript_HideRegiEntrance
# 20 "data/maps/IslandCave/scripts.pory"
	end
# 21 "data/maps/IslandCave/scripts.pory"

# 22 "data/maps/IslandCave/scripts.pory"
IslandCave_EventScript_HideRegiEntrance::
# 23 "data/maps/IslandCave/scripts.pory"
	setmetatile 7, 19, METATILE_Cave_EntranceCover, TRUE
# 24 "data/maps/IslandCave/scripts.pory"
	setmetatile 8, 19, METATILE_Cave_EntranceCover, TRUE
# 25 "data/maps/IslandCave/scripts.pory"
	setmetatile 9, 19, METATILE_Cave_EntranceCover, TRUE
# 26 "data/maps/IslandCave/scripts.pory"
	setmetatile 7, 20, METATILE_Cave_SealedChamberBraille_Mid, TRUE
# 27 "data/maps/IslandCave/scripts.pory"
	setmetatile 8, 20, METATILE_Cave_SealedChamberBraille_Mid, TRUE
# 28 "data/maps/IslandCave/scripts.pory"
	setmetatile 9, 20, METATILE_Cave_SealedChamberBraille_Mid, TRUE
# 29 "data/maps/IslandCave/scripts.pory"
	return
# 30 "data/maps/IslandCave/scripts.pory"

# 31 "data/maps/IslandCave/scripts.pory"
IslandCave_OnTransition:
# 32 "data/maps/IslandCave/scripts.pory"
	setflag FLAG_LANDMARK_ISLAND_CAVE
# 33 "data/maps/IslandCave/scripts.pory"
	call IslandCave_EventScript_ClearSteps
# 34 "data/maps/IslandCave/scripts.pory"
	call_if_unset FLAG_DEFEATED_REGICE, IslandCave_EventScript_ShowRegice
# 35 "data/maps/IslandCave/scripts.pory"
	end
# 36 "data/maps/IslandCave/scripts.pory"

# 37 "data/maps/IslandCave/scripts.pory"
IslandCave_EventScript_ShowRegice::
# 38 "data/maps/IslandCave/scripts.pory"
	clearflag FLAG_HIDE_REGICE
# 39 "data/maps/IslandCave/scripts.pory"
	return
# 40 "data/maps/IslandCave/scripts.pory"

# 41 "data/maps/IslandCave/scripts.pory"
IslandCave_EventScript_OpenRegiEntrance::
# 42 "data/maps/IslandCave/scripts.pory"
	setmetatile 7, 19, METATILE_Cave_SealedChamberEntrance_TopLeft, TRUE
# 43 "data/maps/IslandCave/scripts.pory"
	setmetatile 8, 19, METATILE_Cave_SealedChamberEntrance_TopMid, TRUE
# 44 "data/maps/IslandCave/scripts.pory"
	setmetatile 9, 19, METATILE_Cave_SealedChamberEntrance_TopRight, TRUE
# 45 "data/maps/IslandCave/scripts.pory"
	setmetatile 7, 20, METATILE_Cave_SealedChamberEntrance_BottomLeft, TRUE
# 46 "data/maps/IslandCave/scripts.pory"
	setmetatile 8, 20, METATILE_Cave_SealedChamberEntrance_BottomMid, FALSE
# 47 "data/maps/IslandCave/scripts.pory"
	setmetatile 9, 20, METATILE_Cave_SealedChamberEntrance_BottomRight, TRUE
# 48 "data/maps/IslandCave/scripts.pory"
	special DrawWholeMapView
# 49 "data/maps/IslandCave/scripts.pory"
	playse SE_BANG
# 50 "data/maps/IslandCave/scripts.pory"
	setflag FLAG_SYS_BRAILLE_REGICE_COMPLETED
# 51 "data/maps/IslandCave/scripts.pory"
	end
# 52 "data/maps/IslandCave/scripts.pory"

# 53 "data/maps/IslandCave/scripts.pory"
IslandCave_EventScript_CaveEntranceMiddle::
# 54 "data/maps/IslandCave/scripts.pory"
	lockall
# 55 "data/maps/IslandCave/scripts.pory"
	call_if_set FLAG_TEMP_REGICE_PUZZLE_FAILED, IslandCave_EventScript_ClearSteps
# 56 "data/maps/IslandCave/scripts.pory"
	goto_if_set FLAG_SYS_BRAILLE_REGICE_COMPLETED, IslandCave_EventScript_BigHoleInWall
# 57 "data/maps/IslandCave/scripts.pory"
	braillemessage IslandCave_Braille_RunLapAroundWall
# 58 "data/maps/IslandCave/scripts.pory"
	setflag FLAG_TEMP_REGICE_PUZZLE_STARTED
# 59 "data/maps/IslandCave/scripts.pory"
	special ShouldDoBrailleRegicePuzzle
# 60 "data/maps/IslandCave/scripts.pory"
	goto IslandCave_EventScript_CloseBrailleMsg
# 61 "data/maps/IslandCave/scripts.pory"
	end
# 62 "data/maps/IslandCave/scripts.pory"

# 63 "data/maps/IslandCave/scripts.pory"
IslandCave_EventScript_BigHoleInWall::
# 64 "data/maps/IslandCave/scripts.pory"
	msgbox gText_BigHoleInTheWall, MSGBOX_DEFAULT
# 65 "data/maps/IslandCave/scripts.pory"
	releaseall
# 66 "data/maps/IslandCave/scripts.pory"
	end
# 67 "data/maps/IslandCave/scripts.pory"

# 68 "data/maps/IslandCave/scripts.pory"
IslandCave_EventScript_CaveEntranceSide::
# 69 "data/maps/IslandCave/scripts.pory"
	lockall
# 70 "data/maps/IslandCave/scripts.pory"
	call_if_set FLAG_TEMP_REGICE_PUZZLE_FAILED, IslandCave_EventScript_ClearSteps
# 71 "data/maps/IslandCave/scripts.pory"
	braillemessage IslandCave_Braille_RunLapAroundWall
# 72 "data/maps/IslandCave/scripts.pory"
	goto_if_set FLAG_SYS_BRAILLE_REGICE_COMPLETED, IslandCave_EventScript_CloseBrailleMsg
# 73 "data/maps/IslandCave/scripts.pory"
	setflag FLAG_TEMP_REGICE_PUZZLE_STARTED
# 74 "data/maps/IslandCave/scripts.pory"
	special ShouldDoBrailleRegicePuzzle
# 75 "data/maps/IslandCave/scripts.pory"
	goto IslandCave_EventScript_CloseBrailleMsg
# 76 "data/maps/IslandCave/scripts.pory"
	end
# 77 "data/maps/IslandCave/scripts.pory"

# 78 "data/maps/IslandCave/scripts.pory"
IslandCave_EventScript_CloseBrailleMsg::
# 79 "data/maps/IslandCave/scripts.pory"
	waitbuttonpress
# 80 "data/maps/IslandCave/scripts.pory"
	closebraillemessage
# 81 "data/maps/IslandCave/scripts.pory"
	releaseall
# 82 "data/maps/IslandCave/scripts.pory"
	end
# 83 "data/maps/IslandCave/scripts.pory"

# 84 "data/maps/IslandCave/scripts.pory"
IslandCave_EventScript_ClearSteps::
# 85 "data/maps/IslandCave/scripts.pory"
	setvar VAR_REGICE_STEPS_1, 0
# 86 "data/maps/IslandCave/scripts.pory"
	setvar VAR_REGICE_STEPS_2, 0
# 87 "data/maps/IslandCave/scripts.pory"
	setvar VAR_REGICE_STEPS_3, 0
# 88 "data/maps/IslandCave/scripts.pory"
	clearflag FLAG_TEMP_REGICE_PUZZLE_FAILED
# 89 "data/maps/IslandCave/scripts.pory"
	return
# 90 "data/maps/IslandCave/scripts.pory"

# 91 "data/maps/IslandCave/scripts.pory"
IslandCave_EventScript_Regice::
# 92 "data/maps/IslandCave/scripts.pory"
	lock
# 93 "data/maps/IslandCave/scripts.pory"
	faceplayer
# 94 "data/maps/IslandCave/scripts.pory"
	waitse
# 95 "data/maps/IslandCave/scripts.pory"
	playmoncry SPECIES_REGICE, CRY_MODE_ENCOUNTER
# 96 "data/maps/IslandCave/scripts.pory"
	delay 40
# 97 "data/maps/IslandCave/scripts.pory"
	waitmoncry
# 98 "data/maps/IslandCave/scripts.pory"
	setwildbattle SPECIES_REGICE, 40
# 99 "data/maps/IslandCave/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 100 "data/maps/IslandCave/scripts.pory"
	special StartRegiBattle
# 101 "data/maps/IslandCave/scripts.pory"
	waitstate
# 102 "data/maps/IslandCave/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 103 "data/maps/IslandCave/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 104 "data/maps/IslandCave/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, IslandCave_EventScript_DefeatedRegice
# 105 "data/maps/IslandCave/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, IslandCave_EventScript_RanFromRegice
# 106 "data/maps/IslandCave/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, IslandCave_EventScript_RanFromRegice
# 107 "data/maps/IslandCave/scripts.pory"
	setflag FLAG_DEFEATED_REGICE
# 108 "data/maps/IslandCave/scripts.pory"
	release
# 109 "data/maps/IslandCave/scripts.pory"
	end
# 110 "data/maps/IslandCave/scripts.pory"

# 111 "data/maps/IslandCave/scripts.pory"
IslandCave_EventScript_DefeatedRegice::
# 112 "data/maps/IslandCave/scripts.pory"
	setflag FLAG_DEFEATED_REGICE
# 113 "data/maps/IslandCave/scripts.pory"
	goto Common_EventScript_RemoveStaticPokemon
# 114 "data/maps/IslandCave/scripts.pory"
	end
# 115 "data/maps/IslandCave/scripts.pory"

# 116 "data/maps/IslandCave/scripts.pory"
IslandCave_EventScript_RanFromRegice::
# 117 "data/maps/IslandCave/scripts.pory"
	setvar VAR_0x8004, SPECIES_REGICE
# 118 "data/maps/IslandCave/scripts.pory"
	goto Common_EventScript_LegendaryFlewAway
# 119 "data/maps/IslandCave/scripts.pory"
	end
