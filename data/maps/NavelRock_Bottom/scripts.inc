# 1 "data/maps/NavelRock_Bottom/scripts.pory"

# 2 "data/maps/NavelRock_Bottom/scripts.pory"
.set LOCALID_LUGIA, 1
# 3 "data/maps/NavelRock_Bottom/scripts.pory"

# 4 "data/maps/NavelRock_Bottom/scripts.pory"
NavelRock_Bottom_MapScripts::
# 5 "data/maps/NavelRock_Bottom/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, NavelRock_Bottom_OnTransition
# 6 "data/maps/NavelRock_Bottom/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, NavelRock_Bottom_OnResume
# 7 "data/maps/NavelRock_Bottom/scripts.pory"
	.byte 0
# 8 "data/maps/NavelRock_Bottom/scripts.pory"

# 9 "data/maps/NavelRock_Bottom/scripts.pory"
NavelRock_Bottom_OnTransition:
# 10 "data/maps/NavelRock_Bottom/scripts.pory"
	call_if_set FLAG_CAUGHT_LUGIA, NavelRock_Bottom_EventScript_HideLugia
# 11 "data/maps/NavelRock_Bottom/scripts.pory"
	call_if_unset FLAG_CAUGHT_LUGIA, NavelRock_Bottom_EventScript_TryShowLugia
# 12 "data/maps/NavelRock_Bottom/scripts.pory"
	end
# 13 "data/maps/NavelRock_Bottom/scripts.pory"

# 14 "data/maps/NavelRock_Bottom/scripts.pory"
NavelRock_Bottom_EventScript_HideLugia::
# 15 "data/maps/NavelRock_Bottom/scripts.pory"
	setflag FLAG_HIDE_LUGIA
# 16 "data/maps/NavelRock_Bottom/scripts.pory"
	return
# 17 "data/maps/NavelRock_Bottom/scripts.pory"

# 18 "data/maps/NavelRock_Bottom/scripts.pory"
NavelRock_Bottom_EventScript_TryShowLugia::
# 19 "data/maps/NavelRock_Bottom/scripts.pory"
	goto_if_set FLAG_DEFEATED_LUGIA, Common_EventScript_NopReturn
# 20 "data/maps/NavelRock_Bottom/scripts.pory"
	clearflag FLAG_HIDE_LUGIA
# 21 "data/maps/NavelRock_Bottom/scripts.pory"
	return
# 22 "data/maps/NavelRock_Bottom/scripts.pory"

# 23 "data/maps/NavelRock_Bottom/scripts.pory"
NavelRock_Bottom_OnResume:
# 24 "data/maps/NavelRock_Bottom/scripts.pory"
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, NavelRock_Bottom_EventScript_TryRemoveLugia
# 25 "data/maps/NavelRock_Bottom/scripts.pory"
	end
# 26 "data/maps/NavelRock_Bottom/scripts.pory"

# 27 "data/maps/NavelRock_Bottom/scripts.pory"
NavelRock_Bottom_EventScript_TryRemoveLugia::
# 28 "data/maps/NavelRock_Bottom/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 29 "data/maps/NavelRock_Bottom/scripts.pory"
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
# 30 "data/maps/NavelRock_Bottom/scripts.pory"
	removeobject LOCALID_LUGIA
# 31 "data/maps/NavelRock_Bottom/scripts.pory"
	return
# 32 "data/maps/NavelRock_Bottom/scripts.pory"

# 33 "data/maps/NavelRock_Bottom/scripts.pory"
NavelRock_Bottom_EventScript_Lugia::
# 34 "data/maps/NavelRock_Bottom/scripts.pory"
	lock
# 35 "data/maps/NavelRock_Bottom/scripts.pory"
	faceplayer
# 36 "data/maps/NavelRock_Bottom/scripts.pory"
	waitse
# 37 "data/maps/NavelRock_Bottom/scripts.pory"
	delay 20
# 38 "data/maps/NavelRock_Bottom/scripts.pory"
	playse SE_THUNDERSTORM_STOP
# 39 "data/maps/NavelRock_Bottom/scripts.pory"
	setvar VAR_0x8004, 0  @ vertical pan
# 40 "data/maps/NavelRock_Bottom/scripts.pory"
	setvar VAR_0x8005, 3  @ horizontal pan
# 41 "data/maps/NavelRock_Bottom/scripts.pory"
	setvar VAR_0x8006, 4  @ num shakes
# 42 "data/maps/NavelRock_Bottom/scripts.pory"
	setvar VAR_0x8007, 2  @ shake delay
# 43 "data/maps/NavelRock_Bottom/scripts.pory"
	special ShakeCamera
# 44 "data/maps/NavelRock_Bottom/scripts.pory"
	delay 30
# 45 "data/maps/NavelRock_Bottom/scripts.pory"
	playse SE_THUNDERSTORM_STOP
# 46 "data/maps/NavelRock_Bottom/scripts.pory"
	setvar VAR_0x8004, 0  @ vertical pan
# 47 "data/maps/NavelRock_Bottom/scripts.pory"
	setvar VAR_0x8005, 3  @ horizontal pan
# 48 "data/maps/NavelRock_Bottom/scripts.pory"
	setvar VAR_0x8006, 4  @ num shakes
# 49 "data/maps/NavelRock_Bottom/scripts.pory"
	setvar VAR_0x8007, 2  @ shake delay
# 50 "data/maps/NavelRock_Bottom/scripts.pory"
	special ShakeCamera
# 51 "data/maps/NavelRock_Bottom/scripts.pory"
	delay 30
# 52 "data/maps/NavelRock_Bottom/scripts.pory"
	delay 50
# 53 "data/maps/NavelRock_Bottom/scripts.pory"
	waitse
# 54 "data/maps/NavelRock_Bottom/scripts.pory"
	playmoncry SPECIES_LUGIA, CRY_MODE_ENCOUNTER
# 55 "data/maps/NavelRock_Bottom/scripts.pory"
	waitmoncry
# 56 "data/maps/NavelRock_Bottom/scripts.pory"
	delay 20
# 57 "data/maps/NavelRock_Bottom/scripts.pory"
	seteventmon SPECIES_LUGIA, 70
# 58 "data/maps/NavelRock_Bottom/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 59 "data/maps/NavelRock_Bottom/scripts.pory"
	special BattleSetup_StartLegendaryBattle
# 60 "data/maps/NavelRock_Bottom/scripts.pory"
	waitstate
# 61 "data/maps/NavelRock_Bottom/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 62 "data/maps/NavelRock_Bottom/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 63 "data/maps/NavelRock_Bottom/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, NavelRock_Bottom_EventScript_DefeatedLugia
# 64 "data/maps/NavelRock_Bottom/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, NavelRock_Bottom_EventScript_RanFromLugia
# 65 "data/maps/NavelRock_Bottom/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, NavelRock_Bottom_EventScript_RanFromLugia
# 66 "data/maps/NavelRock_Bottom/scripts.pory"
	setflag FLAG_CAUGHT_LUGIA
# 67 "data/maps/NavelRock_Bottom/scripts.pory"
	release
# 68 "data/maps/NavelRock_Bottom/scripts.pory"
	end
# 69 "data/maps/NavelRock_Bottom/scripts.pory"

# 70 "data/maps/NavelRock_Bottom/scripts.pory"
NavelRock_Bottom_EventScript_DefeatedLugia::
# 71 "data/maps/NavelRock_Bottom/scripts.pory"
	setflag FLAG_DEFEATED_LUGIA
# 72 "data/maps/NavelRock_Bottom/scripts.pory"
	setvar VAR_0x8004, SPECIES_LUGIA
# 73 "data/maps/NavelRock_Bottom/scripts.pory"
	goto Common_EventScript_LegendaryFlewAway
# 74 "data/maps/NavelRock_Bottom/scripts.pory"
	end
# 75 "data/maps/NavelRock_Bottom/scripts.pory"

# 76 "data/maps/NavelRock_Bottom/scripts.pory"
NavelRock_Bottom_EventScript_RanFromLugia::
# 77 "data/maps/NavelRock_Bottom/scripts.pory"
	setvar VAR_0x8004, SPECIES_LUGIA
# 78 "data/maps/NavelRock_Bottom/scripts.pory"
	goto Common_EventScript_LegendaryFlewAway
# 79 "data/maps/NavelRock_Bottom/scripts.pory"
	end
