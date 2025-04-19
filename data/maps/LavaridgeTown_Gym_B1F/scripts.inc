# 1 "data/maps/LavaridgeTown_Gym_B1F/scripts.pory"

# 2 "data/maps/LavaridgeTown_Gym_B1F/scripts.pory"
.equ LOCALID_JACE, 1
# 3 "data/maps/LavaridgeTown_Gym_B1F/scripts.pory"
.equ LOCALID_KEEGAN, 2
# 4 "data/maps/LavaridgeTown_Gym_B1F/scripts.pory"
.equ LOCALID_JEFF, 3
# 5 "data/maps/LavaridgeTown_Gym_B1F/scripts.pory"
.equ LOCALID_ELI, 4
# 6 "data/maps/LavaridgeTown_Gym_B1F/scripts.pory"

# 7 "data/maps/LavaridgeTown_Gym_B1F/scripts.pory"
LavaridgeTown_Gym_B1F_MapScripts::
# 8 "data/maps/LavaridgeTown_Gym_B1F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, LavaridgeTown_Gym_B1F_OnTransition
# 9 "data/maps/LavaridgeTown_Gym_B1F/scripts.pory"
	.byte 0
# 10 "data/maps/LavaridgeTown_Gym_B1F/scripts.pory"

# 11 "data/maps/LavaridgeTown_Gym_B1F/scripts.pory"
LavaridgeTown_Gym_B1F_OnTransition:
# 12 "data/maps/LavaridgeTown_Gym_B1F/scripts.pory"
	call LavaridgeTown_Gym_B1F_EventScript_SetTrainerTempVars
# 13 "data/maps/LavaridgeTown_Gym_B1F/scripts.pory"
	call LavaridgeTown_Gym_B1F_EventScript_CheckBuryTrainers
# 14 "data/maps/LavaridgeTown_Gym_B1F/scripts.pory"
	end
# 15 "data/maps/LavaridgeTown_Gym_B1F/scripts.pory"

# 16 "data/maps/LavaridgeTown_Gym_B1F/scripts.pory"
@ Unclear where/if these temp vars are getting checked
# 17 "data/maps/LavaridgeTown_Gym_B1F/scripts.pory"
LavaridgeTown_Gym_B1F_EventScript_SetTrainerTempVars::
# 18 "data/maps/LavaridgeTown_Gym_B1F/scripts.pory"
	setvar VAR_TEMP_7, 0
# 19 "data/maps/LavaridgeTown_Gym_B1F/scripts.pory"
	setvar VAR_TEMP_8, 0
# 20 "data/maps/LavaridgeTown_Gym_B1F/scripts.pory"
	setvar VAR_TEMP_9, 0
# 21 "data/maps/LavaridgeTown_Gym_B1F/scripts.pory"
	setvar VAR_TEMP_A, 0
# 22 "data/maps/LavaridgeTown_Gym_B1F/scripts.pory"
	goto_if_defeated TRAINER_KEEGAN, LavaridgeTown_Gym_B1F_EventScript_SetJaceTempVar
# 23 "data/maps/LavaridgeTown_Gym_B1F/scripts.pory"
	setvar VAR_TEMP_7, 1
# 24 "data/maps/LavaridgeTown_Gym_B1F/scripts.pory"
LavaridgeTown_Gym_B1F_EventScript_SetJaceTempVar::
# 25 "data/maps/LavaridgeTown_Gym_B1F/scripts.pory"
	goto_if_defeated TRAINER_JACE, LavaridgeTown_Gym_B1F_EventScript_SetJeffTempVar
# 26 "data/maps/LavaridgeTown_Gym_B1F/scripts.pory"
	setvar VAR_TEMP_8, 1
# 27 "data/maps/LavaridgeTown_Gym_B1F/scripts.pory"
LavaridgeTown_Gym_B1F_EventScript_SetJeffTempVar::
# 28 "data/maps/LavaridgeTown_Gym_B1F/scripts.pory"
	goto_if_defeated TRAINER_JEFF, LavaridgeTown_Gym_B1F_EventScript_SetEliTempVar
# 29 "data/maps/LavaridgeTown_Gym_B1F/scripts.pory"
	setvar VAR_TEMP_9, 1
# 30 "data/maps/LavaridgeTown_Gym_B1F/scripts.pory"
LavaridgeTown_Gym_B1F_EventScript_SetEliTempVar::
# 31 "data/maps/LavaridgeTown_Gym_B1F/scripts.pory"
	goto_if_defeated TRAINER_ELI, LavaridgeTown_Gym_B1F_EventScript_EndSetTrainerTempVars
# 32 "data/maps/LavaridgeTown_Gym_B1F/scripts.pory"
	setvar VAR_TEMP_A, 1
# 33 "data/maps/LavaridgeTown_Gym_B1F/scripts.pory"
LavaridgeTown_Gym_B1F_EventScript_EndSetTrainerTempVars::
# 34 "data/maps/LavaridgeTown_Gym_B1F/scripts.pory"
	return
# 35 "data/maps/LavaridgeTown_Gym_B1F/scripts.pory"

# 36 "data/maps/LavaridgeTown_Gym_B1F/scripts.pory"
LavaridgeTown_Gym_B1F_EventScript_CheckBuryTrainers::
# 37 "data/maps/LavaridgeTown_Gym_B1F/scripts.pory"
	goto_if_defeated TRAINER_KEEGAN, LavaridgeTown_Gym_B1F_EventScript_CheckBuryJace
# 38 "data/maps/LavaridgeTown_Gym_B1F/scripts.pory"
	setobjectmovementtype LOCALID_KEEGAN, MOVEMENT_TYPE_BURIED
# 39 "data/maps/LavaridgeTown_Gym_B1F/scripts.pory"
LavaridgeTown_Gym_B1F_EventScript_CheckBuryJace::
# 40 "data/maps/LavaridgeTown_Gym_B1F/scripts.pory"
	goto_if_defeated TRAINER_JACE, LavaridgeTown_Gym_B1F_EventScript_CheckBuryJeff
# 41 "data/maps/LavaridgeTown_Gym_B1F/scripts.pory"
	setobjectmovementtype LOCALID_JACE, MOVEMENT_TYPE_BURIED
# 42 "data/maps/LavaridgeTown_Gym_B1F/scripts.pory"
LavaridgeTown_Gym_B1F_EventScript_CheckBuryJeff::
# 43 "data/maps/LavaridgeTown_Gym_B1F/scripts.pory"
	goto_if_defeated TRAINER_JEFF, LavaridgeTown_Gym_B1F_EventScript_CheckBuryEli
# 44 "data/maps/LavaridgeTown_Gym_B1F/scripts.pory"
	setobjectmovementtype LOCALID_JEFF, MOVEMENT_TYPE_BURIED
# 45 "data/maps/LavaridgeTown_Gym_B1F/scripts.pory"
LavaridgeTown_Gym_B1F_EventScript_CheckBuryEli::
# 46 "data/maps/LavaridgeTown_Gym_B1F/scripts.pory"
	goto_if_defeated TRAINER_ELI, LavaridgeTown_Gym_B1F_EventScript_EndCheckBuryTrainers
# 47 "data/maps/LavaridgeTown_Gym_B1F/scripts.pory"
	setobjectmovementtype LOCALID_ELI, MOVEMENT_TYPE_BURIED
# 48 "data/maps/LavaridgeTown_Gym_B1F/scripts.pory"
LavaridgeTown_Gym_B1F_EventScript_EndCheckBuryTrainers::
# 49 "data/maps/LavaridgeTown_Gym_B1F/scripts.pory"
	return
