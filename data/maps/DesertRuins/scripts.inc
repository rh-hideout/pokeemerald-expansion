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
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, DesertRuins_EventScript_TryRemoveRegidrago
# 11 "data/maps/DesertRuins/scripts.pory"
	end
# 12 "data/maps/DesertRuins/scripts.pory"

# 13 "data/maps/DesertRuins/scripts.pory"
DesertRuins_EventScript_TryRemoveRegirock::
# 14 "data/maps/DesertRuins/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 15 "data/maps/DesertRuins/scripts.pory"
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
# 16 "data/maps/DesertRuins/scripts.pory"
	removeobject VAR_LAST_TALKED
# 17 "data/maps/DesertRuins/scripts.pory"
	return
# 18 "data/maps/DesertRuins/scripts.pory"

# 19 "data/maps/DesertRuins/scripts.pory"
DesertRuins_EventScript_TryRemoveRegidrago::
# 20 "data/maps/DesertRuins/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 21 "data/maps/DesertRuins/scripts.pory"
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
# 22 "data/maps/DesertRuins/scripts.pory"
	removeobject VAR_LAST_TALKED
# 23 "data/maps/DesertRuins/scripts.pory"
	return
# 24 "data/maps/DesertRuins/scripts.pory"

# 25 "data/maps/DesertRuins/scripts.pory"
DesertRuins_OnLoad:
# 26 "data/maps/DesertRuins/scripts.pory"
	call_if_unset FLAG_SYS_REGIROCK_PUZZLE_COMPLETED, DesertRuins_EventScript_HideRegiEntrance
# 27 "data/maps/DesertRuins/scripts.pory"
	end
# 28 "data/maps/DesertRuins/scripts.pory"

# 29 "data/maps/DesertRuins/scripts.pory"
DesertRuins_EventScript_HideRegiEntrance::
# 30 "data/maps/DesertRuins/scripts.pory"
	setmetatile 7, 19, METATILE_Cave_EntranceCover, TRUE
# 31 "data/maps/DesertRuins/scripts.pory"
	setmetatile 8, 19, METATILE_Cave_EntranceCover, TRUE
# 32 "data/maps/DesertRuins/scripts.pory"
	setmetatile 9, 19, METATILE_Cave_EntranceCover, TRUE
# 33 "data/maps/DesertRuins/scripts.pory"
	setmetatile 7, 20, METATILE_Cave_SealedChamberBraille_Mid, TRUE
# 34 "data/maps/DesertRuins/scripts.pory"
	setmetatile 8, 20, METATILE_Cave_SealedChamberBraille_Mid, TRUE
# 35 "data/maps/DesertRuins/scripts.pory"
	setmetatile 9, 20, METATILE_Cave_SealedChamberBraille_Mid, TRUE
# 36 "data/maps/DesertRuins/scripts.pory"
	return
# 37 "data/maps/DesertRuins/scripts.pory"

# 38 "data/maps/DesertRuins/scripts.pory"
DesertRuins_OnTransition:
# 39 "data/maps/DesertRuins/scripts.pory"
	setflag FLAG_LANDMARK_DESERT_RUINS
# 40 "data/maps/DesertRuins/scripts.pory"
	call_if_unset FLAG_DEFEATED_REGIROCK, DesertRuins_EventScript_ShowRegirock
# 41 "data/maps/DesertRuins/scripts.pory"
	end
# 42 "data/maps/DesertRuins/scripts.pory"

# 43 "data/maps/DesertRuins/scripts.pory"
DesertRuins_EventScript_ShowRegirock::
# 44 "data/maps/DesertRuins/scripts.pory"
	clearflag FLAG_HIDE_REGIROCK
# 45 "data/maps/DesertRuins/scripts.pory"
	return
# 46 "data/maps/DesertRuins/scripts.pory"

# 47 "data/maps/DesertRuins/scripts.pory"
DesertRuins_EventScript_CaveEntranceMiddle::
# 48 "data/maps/DesertRuins/scripts.pory"
	lockall
# 49 "data/maps/DesertRuins/scripts.pory"
	goto_if_set FLAG_SYS_REGIROCK_PUZZLE_COMPLETED, DesertRuins_EventScript_BigHoleInWall
# 50 "data/maps/DesertRuins/scripts.pory"
	braillemsgbox DesertRuins_Braille_UseRockSmash
# 51 "data/maps/DesertRuins/scripts.pory"
	releaseall
# 52 "data/maps/DesertRuins/scripts.pory"
	end
# 53 "data/maps/DesertRuins/scripts.pory"

# 54 "data/maps/DesertRuins/scripts.pory"
DesertRuins_EventScript_BigHoleInWall::
# 55 "data/maps/DesertRuins/scripts.pory"
	msgbox gText_BigHoleInTheWall, MSGBOX_DEFAULT
# 56 "data/maps/DesertRuins/scripts.pory"
	releaseall
# 57 "data/maps/DesertRuins/scripts.pory"
	end
# 58 "data/maps/DesertRuins/scripts.pory"

# 59 "data/maps/DesertRuins/scripts.pory"
DesertRuins_EventScript_CaveEntranceSide::
# 60 "data/maps/DesertRuins/scripts.pory"
	lockall
# 61 "data/maps/DesertRuins/scripts.pory"
	braillemsgbox DesertRuins_Braille_UseRockSmash
# 62 "data/maps/DesertRuins/scripts.pory"
	releaseall
# 63 "data/maps/DesertRuins/scripts.pory"
	end
# 64 "data/maps/DesertRuins/scripts.pory"

# 65 "data/maps/DesertRuins/scripts.pory"
DesertRuins_EventScript_Regirock::
# 66 "data/maps/DesertRuins/scripts.pory"
	lock
# 67 "data/maps/DesertRuins/scripts.pory"
	faceplayer
# 68 "data/maps/DesertRuins/scripts.pory"
	waitse
# 69 "data/maps/DesertRuins/scripts.pory"
	playmoncry SPECIES_REGIROCK, CRY_MODE_ENCOUNTER
# 70 "data/maps/DesertRuins/scripts.pory"
	delay 40
# 71 "data/maps/DesertRuins/scripts.pory"
	waitmoncry
# 72 "data/maps/DesertRuins/scripts.pory"
	setwildbattle SPECIES_REGIROCK, 40
# 73 "data/maps/DesertRuins/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 74 "data/maps/DesertRuins/scripts.pory"
	special StartRegiBattle
# 75 "data/maps/DesertRuins/scripts.pory"
	waitstate
# 76 "data/maps/DesertRuins/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 77 "data/maps/DesertRuins/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 78 "data/maps/DesertRuins/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, DesertRuins_EventScript_DefeatedRegirock
# 79 "data/maps/DesertRuins/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, DesertRuins_EventScript_RanFromRegirock
# 80 "data/maps/DesertRuins/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, DesertRuins_EventScript_RanFromRegirock
# 81 "data/maps/DesertRuins/scripts.pory"
	setflag FLAG_DEFEATED_REGIROCK
# 82 "data/maps/DesertRuins/scripts.pory"
	release
# 83 "data/maps/DesertRuins/scripts.pory"
	end
# 84 "data/maps/DesertRuins/scripts.pory"

# 85 "data/maps/DesertRuins/scripts.pory"
DesertRuins_EventScript_DefeatedRegirock::
# 86 "data/maps/DesertRuins/scripts.pory"
	setflag FLAG_DEFEATED_REGIROCK
# 87 "data/maps/DesertRuins/scripts.pory"
	goto Common_EventScript_RemoveStaticPokemon
# 88 "data/maps/DesertRuins/scripts.pory"
	end
# 89 "data/maps/DesertRuins/scripts.pory"

# 90 "data/maps/DesertRuins/scripts.pory"
DesertRuins_EventScript_RanFromRegirock::
# 91 "data/maps/DesertRuins/scripts.pory"
	setvar VAR_0x8004, SPECIES_REGIROCK
# 92 "data/maps/DesertRuins/scripts.pory"
	goto Common_EventScript_LegendaryFlewAway
# 93 "data/maps/DesertRuins/scripts.pory"
	end
# 94 "data/maps/DesertRuins/scripts.pory"

# 95 "data/maps/DesertRuins/scripts.pory"
DesertRuins_EventScript_Regidrago::
# 96 "data/maps/DesertRuins/scripts.pory"
    lock
# 97 "data/maps/DesertRuins/scripts.pory"
    faceplayer
# 98 "data/maps/DesertRuins/scripts.pory"
    waitse
# 99 "data/maps/DesertRuins/scripts.pory"
    playmoncry SPECIES_REGIDRAGO, CRY_MODE_ENCOUNTER
# 100 "data/maps/DesertRuins/scripts.pory"
    delay 40
# 101 "data/maps/DesertRuins/scripts.pory"
    waitmoncry
# 102 "data/maps/DesertRuins/scripts.pory"
    setwildbattle SPECIES_REGIDRAGO, 40
# 103 "data/maps/DesertRuins/scripts.pory"
    setflag FLAG_SYS_CTRL_OBJ_DELETE
# 104 "data/maps/DesertRuins/scripts.pory"
    special StartRegiBattle
# 105 "data/maps/DesertRuins/scripts.pory"
    waitstate
# 106 "data/maps/DesertRuins/scripts.pory"
    clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 107 "data/maps/DesertRuins/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 108 "data/maps/DesertRuins/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_WON, DesertRuins_EventScript_DefeatedRegidrago
# 109 "data/maps/DesertRuins/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_RAN, DesertRuins_EventScript_RanFromRegidrago
# 110 "data/maps/DesertRuins/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, DesertRuins_EventScript_RanFromRegidrago
# 111 "data/maps/DesertRuins/scripts.pory"
    setflag FLAG_DEFEATED_REGIROCK
# 112 "data/maps/DesertRuins/scripts.pory"
    release
# 113 "data/maps/DesertRuins/scripts.pory"
    end
# 114 "data/maps/DesertRuins/scripts.pory"

# 115 "data/maps/DesertRuins/scripts.pory"

# 116 "data/maps/DesertRuins/scripts.pory"
DesertRuins_EventScript_DefeatedRegidrago::
# 117 "data/maps/DesertRuins/scripts.pory"
    setflag FLAG_DEFEATED_REGIDRAGO
# 118 "data/maps/DesertRuins/scripts.pory"
    goto Common_EventScript_RemoveStaticPokemon
# 119 "data/maps/DesertRuins/scripts.pory"
    end
# 120 "data/maps/DesertRuins/scripts.pory"

# 121 "data/maps/DesertRuins/scripts.pory"

# 122 "data/maps/DesertRuins/scripts.pory"
DesertRuins_EventScript_RanFromRegidrago::
# 123 "data/maps/DesertRuins/scripts.pory"
    setvar VAR_0x8004, SPECIES_REGIDRAGO
# 124 "data/maps/DesertRuins/scripts.pory"
    goto Common_EventScript_LegendaryFlewAway
# 125 "data/maps/DesertRuins/scripts.pory"
    end
