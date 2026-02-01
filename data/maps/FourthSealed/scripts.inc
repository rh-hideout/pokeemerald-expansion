FourthSealed_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, FourthSealed_OnResume
	map_script MAP_SCRIPT_ON_LOAD, FourthSealed_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, FourthSealed_OnTransition
	.byte 0

FourthSealed_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, FourthSealed_EventScript_TryRemoveRegisteel
	end

FourthSealed_EventScript_TryRemoveRegisteel::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

FourthSealed_OnTransition:
	call_if_unset FLAG_DEFEATED_TAPULELE, FourthSealed_EventScript_ShowRegisteel
	end

FourthSealed_EventScript_ShowRegisteel::
	clearflag FLAG_HIDE_TAPULELE
	return

FourthSealed_OnLoad:
	call_if_unset FLAG_SYS_TAPULELE_PUZZLE_COMPLETED, FourthSealed_EventScript_HideRegiEntrance
	end

FourthSealed_EventScript_HideRegiEntrance::
	setmetatile 7, 19, METATILE_Cave_EntranceCover, TRUE
	setmetatile 8, 19, METATILE_Cave_EntranceCover, TRUE
	setmetatile 9, 19, METATILE_Cave_EntranceCover, TRUE
	setmetatile 7, 20, METATILE_Cave_SealedChamberBraille_Mid, TRUE
	setmetatile 8, 20, METATILE_Cave_SealedChamberBraille_Mid, TRUE
	setmetatile 9, 20, METATILE_Cave_SealedChamberBraille_Mid, TRUE
	return

FourthSealed_EventScript_CaveEntranceMiddle::
	lockall
	goto_if_set FLAG_SYS_TAPULELE_PUZZLE_COMPLETED, FourthSealed_EventScript_BigHoleInWall
	specialvar VAR_RESULT, CheckContestWinnerFirstSlot
	goto_if_eq VAR_RESULT, FALSE, FourthSealed_EventScript_CaveEntranceSide2
	special DoSealedChamberShakingEffect_Short
	waitstate
	playse SE_DOOR
	delay 40
	setmetatile 7, 19, METATILE_Cave_SealedChamberEntrance_TopLeft, TRUE
	setmetatile 8, 19, METATILE_Cave_SealedChamberEntrance_TopMid, TRUE
	setmetatile 9, 19, METATILE_Cave_SealedChamberEntrance_TopRight, TRUE
	setmetatile 7, 20, METATILE_Cave_SealedChamberEntrance_BottomLeft , TRUE
	setmetatile 8, 20, METATILE_Cave_SealedChamberEntrance_BottomMid, FALSE
	setmetatile 9, 20, METATILE_Cave_SealedChamberEntrance_BottomRight, TRUE
	special DrawWholeMapView
	setflag FLAG_SYS_TAPULELE_PUZZLE_COMPLETED
FourthSealed_EventScript_BigHoleInWall::
	msgbox gText_BigHoleInTheWall, MSGBOX_DEFAULT
	releaseall
	end

FourthSealed_EventScript_CaveEntranceSide::
	lockall
FourthSealed_EventScript_CaveEntranceSide2::
	braillemsgbox FourthSealed_Braille_ContestWinner
	releaseall
	end

FourthSealed_EventScript_Registeel::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_TAPU_LELE, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_TAPU_LELE, 40
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special StartRegiBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, FourthSealed_EventScript_DefeatedRegisteel
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, FourthSealed_EventScript_RanFromRegisteel
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, FourthSealed_EventScript_RanFromRegisteel
	setflag FLAG_DEFEATED_TAPULELE
	release
	end

FourthSealed_EventScript_DefeatedRegisteel::
	setflag FLAG_DEFEATED_TAPULELE
	goto Common_EventScript_RemoveStaticPokemon
	end

FourthSealed_EventScript_RanFromRegisteel::
	setvar VAR_0x8004, SPECIES_TAPU_LELE
	goto Common_EventScript_LegendaryFlewAway
	end

