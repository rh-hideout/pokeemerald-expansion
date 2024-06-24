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
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, IslandCave_EventScript_TryRemoveRegigigas
# 11 "data/maps/IslandCave/scripts.pory"
	end
# 12 "data/maps/IslandCave/scripts.pory"

# 13 "data/maps/IslandCave/scripts.pory"
IslandCave_EventScript_TryRemoveRegice::
# 14 "data/maps/IslandCave/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 15 "data/maps/IslandCave/scripts.pory"
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
# 16 "data/maps/IslandCave/scripts.pory"
	removeobject VAR_LAST_TALKED
# 17 "data/maps/IslandCave/scripts.pory"
	return
# 18 "data/maps/IslandCave/scripts.pory"

# 19 "data/maps/IslandCave/scripts.pory"
IslandCave_EventScript_TryRemoveRegigigas::
# 20 "data/maps/IslandCave/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 21 "data/maps/IslandCave/scripts.pory"
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
# 22 "data/maps/IslandCave/scripts.pory"
	removeobject VAR_LAST_TALKED
# 23 "data/maps/IslandCave/scripts.pory"
	return
# 24 "data/maps/IslandCave/scripts.pory"

# 25 "data/maps/IslandCave/scripts.pory"
IslandCave_OnLoad:
# 26 "data/maps/IslandCave/scripts.pory"
	call_if_unset FLAG_SYS_BRAILLE_REGICE_COMPLETED, IslandCave_EventScript_HideRegiEntrance
# 27 "data/maps/IslandCave/scripts.pory"
	end
# 28 "data/maps/IslandCave/scripts.pory"

# 29 "data/maps/IslandCave/scripts.pory"
IslandCave_EventScript_HideRegiEntrance::
# 30 "data/maps/IslandCave/scripts.pory"
	setmetatile 7, 19, METATILE_Cave_EntranceCover, TRUE
# 31 "data/maps/IslandCave/scripts.pory"
	setmetatile 8, 19, METATILE_Cave_EntranceCover, TRUE
# 32 "data/maps/IslandCave/scripts.pory"
	setmetatile 9, 19, METATILE_Cave_EntranceCover, TRUE
# 33 "data/maps/IslandCave/scripts.pory"
	setmetatile 7, 20, METATILE_Cave_SealedChamberBraille_Mid, TRUE
# 34 "data/maps/IslandCave/scripts.pory"
	setmetatile 8, 20, METATILE_Cave_SealedChamberBraille_Mid, TRUE
# 35 "data/maps/IslandCave/scripts.pory"
	setmetatile 9, 20, METATILE_Cave_SealedChamberBraille_Mid, TRUE
# 36 "data/maps/IslandCave/scripts.pory"
	return
# 37 "data/maps/IslandCave/scripts.pory"

# 38 "data/maps/IslandCave/scripts.pory"
IslandCave_OnTransition:
# 39 "data/maps/IslandCave/scripts.pory"
	setflag FLAG_LANDMARK_ISLAND_CAVE
# 40 "data/maps/IslandCave/scripts.pory"
	call IslandCave_EventScript_ClearSteps
# 41 "data/maps/IslandCave/scripts.pory"
	call_if_unset FLAG_DEFEATED_REGICE, IslandCave_EventScript_ShowRegice
# 42 "data/maps/IslandCave/scripts.pory"
	end
# 43 "data/maps/IslandCave/scripts.pory"

# 44 "data/maps/IslandCave/scripts.pory"
IslandCave_EventScript_ShowRegice::
# 45 "data/maps/IslandCave/scripts.pory"
	clearflag FLAG_HIDE_REGICE
# 46 "data/maps/IslandCave/scripts.pory"
	return
# 47 "data/maps/IslandCave/scripts.pory"

# 48 "data/maps/IslandCave/scripts.pory"
IslandCave_EventScript_OpenRegiEntrance::
# 49 "data/maps/IslandCave/scripts.pory"
	setmetatile 7, 19, METATILE_Cave_SealedChamberEntrance_TopLeft, TRUE
# 50 "data/maps/IslandCave/scripts.pory"
	setmetatile 8, 19, METATILE_Cave_SealedChamberEntrance_TopMid, TRUE
# 51 "data/maps/IslandCave/scripts.pory"
	setmetatile 9, 19, METATILE_Cave_SealedChamberEntrance_TopRight, TRUE
# 52 "data/maps/IslandCave/scripts.pory"
	setmetatile 7, 20, METATILE_Cave_SealedChamberEntrance_BottomLeft, TRUE
# 53 "data/maps/IslandCave/scripts.pory"
	setmetatile 8, 20, METATILE_Cave_SealedChamberEntrance_BottomMid, FALSE
# 54 "data/maps/IslandCave/scripts.pory"
	setmetatile 9, 20, METATILE_Cave_SealedChamberEntrance_BottomRight, TRUE
# 55 "data/maps/IslandCave/scripts.pory"
	special DrawWholeMapView
# 56 "data/maps/IslandCave/scripts.pory"
	playse SE_BANG
# 57 "data/maps/IslandCave/scripts.pory"
	setflag FLAG_SYS_BRAILLE_REGICE_COMPLETED
# 58 "data/maps/IslandCave/scripts.pory"
	end
# 59 "data/maps/IslandCave/scripts.pory"

# 60 "data/maps/IslandCave/scripts.pory"
IslandCave_EventScript_CaveEntranceMiddle::
# 61 "data/maps/IslandCave/scripts.pory"
	lockall
# 62 "data/maps/IslandCave/scripts.pory"
	call_if_set FLAG_TEMP_REGICE_PUZZLE_FAILED, IslandCave_EventScript_ClearSteps
# 63 "data/maps/IslandCave/scripts.pory"
	goto_if_set FLAG_SYS_BRAILLE_REGICE_COMPLETED, IslandCave_EventScript_BigHoleInWall
# 64 "data/maps/IslandCave/scripts.pory"
	braillemessage IslandCave_Braille_RunLapAroundWall
# 65 "data/maps/IslandCave/scripts.pory"
	setflag FLAG_TEMP_REGICE_PUZZLE_STARTED
# 66 "data/maps/IslandCave/scripts.pory"
	special ShouldDoBrailleRegicePuzzle
# 67 "data/maps/IslandCave/scripts.pory"
	goto IslandCave_EventScript_CloseBrailleMsg
# 68 "data/maps/IslandCave/scripts.pory"
	end
# 69 "data/maps/IslandCave/scripts.pory"

# 70 "data/maps/IslandCave/scripts.pory"
IslandCave_EventScript_BigHoleInWall::
# 71 "data/maps/IslandCave/scripts.pory"
	msgbox gText_BigHoleInTheWall, MSGBOX_DEFAULT
# 72 "data/maps/IslandCave/scripts.pory"
	releaseall
# 73 "data/maps/IslandCave/scripts.pory"
	end
# 74 "data/maps/IslandCave/scripts.pory"

# 75 "data/maps/IslandCave/scripts.pory"
IslandCave_EventScript_CaveEntranceSide::
# 76 "data/maps/IslandCave/scripts.pory"
	lockall
# 77 "data/maps/IslandCave/scripts.pory"
	call_if_set FLAG_TEMP_REGICE_PUZZLE_FAILED, IslandCave_EventScript_ClearSteps
# 78 "data/maps/IslandCave/scripts.pory"
	braillemessage IslandCave_Braille_RunLapAroundWall
# 79 "data/maps/IslandCave/scripts.pory"
	goto_if_set FLAG_SYS_BRAILLE_REGICE_COMPLETED, IslandCave_EventScript_CloseBrailleMsg
# 80 "data/maps/IslandCave/scripts.pory"
	setflag FLAG_TEMP_REGICE_PUZZLE_STARTED
# 81 "data/maps/IslandCave/scripts.pory"
	special ShouldDoBrailleRegicePuzzle
# 82 "data/maps/IslandCave/scripts.pory"
	goto IslandCave_EventScript_CloseBrailleMsg
# 83 "data/maps/IslandCave/scripts.pory"
	end
# 84 "data/maps/IslandCave/scripts.pory"

# 85 "data/maps/IslandCave/scripts.pory"
IslandCave_EventScript_CloseBrailleMsg::
# 86 "data/maps/IslandCave/scripts.pory"
	waitbuttonpress
# 87 "data/maps/IslandCave/scripts.pory"
	closebraillemessage
# 88 "data/maps/IslandCave/scripts.pory"
	releaseall
# 89 "data/maps/IslandCave/scripts.pory"
	end
# 90 "data/maps/IslandCave/scripts.pory"

# 91 "data/maps/IslandCave/scripts.pory"
IslandCave_EventScript_ClearSteps::
# 92 "data/maps/IslandCave/scripts.pory"
	setvar VAR_REGICE_STEPS_1, 0
# 93 "data/maps/IslandCave/scripts.pory"
	setvar VAR_REGICE_STEPS_2, 0
# 94 "data/maps/IslandCave/scripts.pory"
	setvar VAR_REGICE_STEPS_3, 0
# 95 "data/maps/IslandCave/scripts.pory"
	clearflag FLAG_TEMP_REGICE_PUZZLE_FAILED
# 96 "data/maps/IslandCave/scripts.pory"
	return
# 97 "data/maps/IslandCave/scripts.pory"

# 98 "data/maps/IslandCave/scripts.pory"
IslandCave_EventScript_Regice::
# 99 "data/maps/IslandCave/scripts.pory"
	lock
# 100 "data/maps/IslandCave/scripts.pory"
	faceplayer
# 101 "data/maps/IslandCave/scripts.pory"
	waitse
# 102 "data/maps/IslandCave/scripts.pory"
	playmoncry SPECIES_REGICE, CRY_MODE_ENCOUNTER
# 103 "data/maps/IslandCave/scripts.pory"
	delay 40
# 104 "data/maps/IslandCave/scripts.pory"
	waitmoncry
# 105 "data/maps/IslandCave/scripts.pory"
	setwildbattle SPECIES_REGICE, 40
# 106 "data/maps/IslandCave/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 107 "data/maps/IslandCave/scripts.pory"
	special StartRegiBattle
# 108 "data/maps/IslandCave/scripts.pory"
	waitstate
# 109 "data/maps/IslandCave/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 110 "data/maps/IslandCave/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 111 "data/maps/IslandCave/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, IslandCave_EventScript_DefeatedRegice
# 112 "data/maps/IslandCave/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, IslandCave_EventScript_RanFromRegice
# 113 "data/maps/IslandCave/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, IslandCave_EventScript_RanFromRegice
# 114 "data/maps/IslandCave/scripts.pory"
	setflag FLAG_DEFEATED_REGICE
# 115 "data/maps/IslandCave/scripts.pory"
	release
# 116 "data/maps/IslandCave/scripts.pory"
	end
# 117 "data/maps/IslandCave/scripts.pory"

# 118 "data/maps/IslandCave/scripts.pory"
IslandCave_EventScript_DefeatedRegice::
# 119 "data/maps/IslandCave/scripts.pory"
	setflag FLAG_DEFEATED_REGICE
# 120 "data/maps/IslandCave/scripts.pory"
	goto Common_EventScript_RemoveStaticPokemon
# 121 "data/maps/IslandCave/scripts.pory"
	end
# 122 "data/maps/IslandCave/scripts.pory"

# 123 "data/maps/IslandCave/scripts.pory"
IslandCave_EventScript_RanFromRegice::
# 124 "data/maps/IslandCave/scripts.pory"
	setvar VAR_0x8004, SPECIES_REGICE
# 125 "data/maps/IslandCave/scripts.pory"
	goto Common_EventScript_LegendaryFlewAway
# 126 "data/maps/IslandCave/scripts.pory"
	end
# 127 "data/maps/IslandCave/scripts.pory"

# 128 "data/maps/IslandCave/scripts.pory"
IslandCave_EventScript_Regigigas::
# 129 "data/maps/IslandCave/scripts.pory"
    lock
# 130 "data/maps/IslandCave/scripts.pory"
    faceplayer
# 131 "data/maps/IslandCave/scripts.pory"
    waitse
# 132 "data/maps/IslandCave/scripts.pory"
    playmoncry SPECIES_REGIGIGAS, CRY_MODE_ENCOUNTER
# 133 "data/maps/IslandCave/scripts.pory"
    delay 40
# 134 "data/maps/IslandCave/scripts.pory"
    waitmoncry
# 135 "data/maps/IslandCave/scripts.pory"
    setwildbattle SPECIES_REGIGIGAS, 70
# 136 "data/maps/IslandCave/scripts.pory"
    setflag FLAG_SYS_CTRL_OBJ_DELETE
# 137 "data/maps/IslandCave/scripts.pory"
    special StartRegiBattle
# 138 "data/maps/IslandCave/scripts.pory"
    waitstate
# 139 "data/maps/IslandCave/scripts.pory"
    clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 140 "data/maps/IslandCave/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 141 "data/maps/IslandCave/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_WON, IslandCave_EventScript_DefeatedRegigigas
# 142 "data/maps/IslandCave/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_RAN, IslandCave_EventScript_RanFromRegigigas
# 143 "data/maps/IslandCave/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, IslandCave_EventScript_RanFromRegigigas
# 144 "data/maps/IslandCave/scripts.pory"
    setflag FLAG_DEFEATED_REGIGIGAS
# 145 "data/maps/IslandCave/scripts.pory"
    release
# 146 "data/maps/IslandCave/scripts.pory"
    end
# 147 "data/maps/IslandCave/scripts.pory"

# 148 "data/maps/IslandCave/scripts.pory"

# 149 "data/maps/IslandCave/scripts.pory"
IslandCave_EventScript_DefeatedRegigigas::
# 150 "data/maps/IslandCave/scripts.pory"
    setflag FLAG_DEFEATED_REGIGIGAS
# 151 "data/maps/IslandCave/scripts.pory"
    goto Common_EventScript_RemoveStaticPokemon
# 152 "data/maps/IslandCave/scripts.pory"
    end
# 153 "data/maps/IslandCave/scripts.pory"

# 154 "data/maps/IslandCave/scripts.pory"

# 155 "data/maps/IslandCave/scripts.pory"
IslandCave_EventScript_RanFromRegigigas::
# 156 "data/maps/IslandCave/scripts.pory"
    setvar VAR_0x8004, SPECIES_REGIGIGAS
# 157 "data/maps/IslandCave/scripts.pory"
    goto Common_EventScript_LegendaryFlewAway
# 158 "data/maps/IslandCave/scripts.pory"
    end
