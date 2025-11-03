# 1 "data/maps/DesertRuins/scripts.pory"

# 2 "data/maps/DesertRuins/scripts.pory"
DesertRuins_MapScripts::
# 3 "data/maps/DesertRuins/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, DesertRuins_OnResume
# 4 "data/maps/DesertRuins/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, DesertRuins_OnLoad
# 5 "data/maps/DesertRuins/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, DesertRuins_OnTransition
# 6 "data/maps/DesertRuins/scripts.pory"
	.byte 0
# 7 "data/maps/DesertRuins/scripts.pory"

# 8 "data/maps/DesertRuins/scripts.pory"
DesertRuins_OnResume:
# 9 "data/maps/DesertRuins/scripts.pory"
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, DesertRuins_EventScript_TryRemoveRegirock
# 10 "data/maps/DesertRuins/scripts.pory"
	end
# 11 "data/maps/DesertRuins/scripts.pory"

# 12 "data/maps/DesertRuins/scripts.pory"
DesertRuins_EventScript_TryRemoveRegirock::
# 13 "data/maps/DesertRuins/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 14 "data/maps/DesertRuins/scripts.pory"
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
# 15 "data/maps/DesertRuins/scripts.pory"
	removeobject VAR_LAST_TALKED
# 16 "data/maps/DesertRuins/scripts.pory"
	return
# 17 "data/maps/DesertRuins/scripts.pory"

# 18 "data/maps/DesertRuins/scripts.pory"
DesertRuins_OnLoad:
# 19 "data/maps/DesertRuins/scripts.pory"
	call_if_unset FLAG_SYS_REGIROCK_PUZZLE_COMPLETED, DesertRuins_EventScript_HideRegiEntrance
# 20 "data/maps/DesertRuins/scripts.pory"
	end
# 21 "data/maps/DesertRuins/scripts.pory"

# 22 "data/maps/DesertRuins/scripts.pory"
DesertRuins_EventScript_HideRegiEntrance::
# 23 "data/maps/DesertRuins/scripts.pory"
	setmetatile 7, 19, METATILE_Cave_EntranceCover, TRUE
# 24 "data/maps/DesertRuins/scripts.pory"
	setmetatile 8, 19, METATILE_Cave_EntranceCover, TRUE
# 25 "data/maps/DesertRuins/scripts.pory"
	setmetatile 9, 19, METATILE_Cave_EntranceCover, TRUE
# 26 "data/maps/DesertRuins/scripts.pory"
	setmetatile 7, 20, METATILE_Cave_SealedChamberBraille_Mid, TRUE
# 27 "data/maps/DesertRuins/scripts.pory"
	setmetatile 8, 20, METATILE_Cave_SealedChamberBraille_Mid, TRUE
# 28 "data/maps/DesertRuins/scripts.pory"
	setmetatile 9, 20, METATILE_Cave_SealedChamberBraille_Mid, TRUE
# 29 "data/maps/DesertRuins/scripts.pory"
	return
# 30 "data/maps/DesertRuins/scripts.pory"

# 31 "data/maps/DesertRuins/scripts.pory"
DesertRuins_OnTransition:
# 32 "data/maps/DesertRuins/scripts.pory"
	setflag FLAG_LANDMARK_DESERT_RUINS
# 33 "data/maps/DesertRuins/scripts.pory"
	call_if_unset FLAG_DEFEATED_REGIROCK, DesertRuins_EventScript_ShowRegirock
# 34 "data/maps/DesertRuins/scripts.pory"
	end
# 35 "data/maps/DesertRuins/scripts.pory"

# 36 "data/maps/DesertRuins/scripts.pory"
DesertRuins_EventScript_ShowRegirock::
# 37 "data/maps/DesertRuins/scripts.pory"
	clearflag FLAG_HIDE_REGIROCK
# 38 "data/maps/DesertRuins/scripts.pory"
	return
# 39 "data/maps/DesertRuins/scripts.pory"

# 40 "data/maps/DesertRuins/scripts.pory"
DesertRuins_EventScript_CaveEntranceMiddle::
# 41 "data/maps/DesertRuins/scripts.pory"
	lockall
# 42 "data/maps/DesertRuins/scripts.pory"
	goto_if_set FLAG_SYS_REGIROCK_PUZZLE_COMPLETED, DesertRuins_EventScript_BigHoleInWall
# 43 "data/maps/DesertRuins/scripts.pory"
	braillemsgbox DesertRuins_Braille_UseRockSmash
# 44 "data/maps/DesertRuins/scripts.pory"
	releaseall
# 45 "data/maps/DesertRuins/scripts.pory"
	end
# 46 "data/maps/DesertRuins/scripts.pory"

# 47 "data/maps/DesertRuins/scripts.pory"
DesertRuins_EventScript_BigHoleInWall::
# 48 "data/maps/DesertRuins/scripts.pory"
	msgbox gText_BigHoleInTheWall, MSGBOX_DEFAULT
# 49 "data/maps/DesertRuins/scripts.pory"
	releaseall
# 50 "data/maps/DesertRuins/scripts.pory"
	end
# 51 "data/maps/DesertRuins/scripts.pory"

# 52 "data/maps/DesertRuins/scripts.pory"
DesertRuins_EventScript_CaveEntranceSide::
# 53 "data/maps/DesertRuins/scripts.pory"
	lockall
# 54 "data/maps/DesertRuins/scripts.pory"
	braillemsgbox DesertRuins_Braille_UseRockSmash
# 55 "data/maps/DesertRuins/scripts.pory"
	releaseall
# 56 "data/maps/DesertRuins/scripts.pory"
	end
# 57 "data/maps/DesertRuins/scripts.pory"

# 58 "data/maps/DesertRuins/scripts.pory"
DesertRuins_EventScript_Regirock::
# 59 "data/maps/DesertRuins/scripts.pory"
	lock
# 60 "data/maps/DesertRuins/scripts.pory"
	faceplayer
# 61 "data/maps/DesertRuins/scripts.pory"
	waitse
# 62 "data/maps/DesertRuins/scripts.pory"
	playmoncry SPECIES_REGIROCK, CRY_MODE_ENCOUNTER
# 63 "data/maps/DesertRuins/scripts.pory"
	delay 40
# 64 "data/maps/DesertRuins/scripts.pory"
	waitmoncry
# 65 "data/maps/DesertRuins/scripts.pory"
	setwildbattle SPECIES_REGIROCK, 40
# 66 "data/maps/DesertRuins/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 67 "data/maps/DesertRuins/scripts.pory"
	special StartRegiBattle
# 68 "data/maps/DesertRuins/scripts.pory"
	waitstate
# 69 "data/maps/DesertRuins/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 70 "data/maps/DesertRuins/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 71 "data/maps/DesertRuins/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, DesertRuins_EventScript_DefeatedRegirock
# 72 "data/maps/DesertRuins/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, DesertRuins_EventScript_RanFromRegirock
# 73 "data/maps/DesertRuins/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, DesertRuins_EventScript_RanFromRegirock
# 74 "data/maps/DesertRuins/scripts.pory"
	setflag FLAG_DEFEATED_REGIROCK
# 75 "data/maps/DesertRuins/scripts.pory"
	release
# 76 "data/maps/DesertRuins/scripts.pory"
	end
# 77 "data/maps/DesertRuins/scripts.pory"

# 78 "data/maps/DesertRuins/scripts.pory"
DesertRuins_EventScript_DefeatedRegirock::
# 79 "data/maps/DesertRuins/scripts.pory"
	setflag FLAG_DEFEATED_REGIROCK
# 80 "data/maps/DesertRuins/scripts.pory"
	goto Common_EventScript_RemoveStaticPokemon
# 81 "data/maps/DesertRuins/scripts.pory"
	end
# 82 "data/maps/DesertRuins/scripts.pory"

# 83 "data/maps/DesertRuins/scripts.pory"
DesertRuins_EventScript_RanFromRegirock::
# 84 "data/maps/DesertRuins/scripts.pory"
	setvar VAR_0x8004, SPECIES_REGIROCK
# 85 "data/maps/DesertRuins/scripts.pory"
	goto Common_EventScript_LegendaryFlewAway
# 86 "data/maps/DesertRuins/scripts.pory"
	end
