# 1 "data/maps/LavaridgeTown_Gym_B1F/scripts.pory"

# 2 "data/maps/LavaridgeTown_Gym_B1F/scripts.pory"
LavaridgeTown_Gym_B1F_MapScripts::
# 3 "data/maps/LavaridgeTown_Gym_B1F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, LavaridgeTown_Gym_B1F_OnTransition
# 4 "data/maps/LavaridgeTown_Gym_B1F/scripts.pory"
	.byte 0
# 5 "data/maps/LavaridgeTown_Gym_B1F/scripts.pory"

# 6 "data/maps/LavaridgeTown_Gym_B1F/scripts.pory"
LavaridgeTown_Gym_B1F_OnTransition:
# 7 "data/maps/LavaridgeTown_Gym_B1F/scripts.pory"
	call LavaridgeTown_Gym_B1F_EventScript_SetTrainerTempVars
# 8 "data/maps/LavaridgeTown_Gym_B1F/scripts.pory"
	call LavaridgeTown_Gym_B1F_EventScript_CheckBuryTrainers
# 9 "data/maps/LavaridgeTown_Gym_B1F/scripts.pory"
	end
# 10 "data/maps/LavaridgeTown_Gym_B1F/scripts.pory"

# 11 "data/maps/LavaridgeTown_Gym_B1F/scripts.pory"
@ Unclear where/if these temp vars are getting checked
# 12 "data/maps/LavaridgeTown_Gym_B1F/scripts.pory"
LavaridgeTown_Gym_B1F_EventScript_SetTrainerTempVars::
# 13 "data/maps/LavaridgeTown_Gym_B1F/scripts.pory"
	setvar VAR_TEMP_7, 0
# 14 "data/maps/LavaridgeTown_Gym_B1F/scripts.pory"
	setvar VAR_TEMP_8, 0
# 15 "data/maps/LavaridgeTown_Gym_B1F/scripts.pory"
	setvar VAR_TEMP_9, 0
# 16 "data/maps/LavaridgeTown_Gym_B1F/scripts.pory"
	setvar VAR_TEMP_A, 0
# 17 "data/maps/LavaridgeTown_Gym_B1F/scripts.pory"
	goto_if_defeated TRAINER_KEEGAN, LavaridgeTown_Gym_B1F_EventScript_SetJaceTempVar
# 18 "data/maps/LavaridgeTown_Gym_B1F/scripts.pory"
	setvar VAR_TEMP_7, 1
# 19 "data/maps/LavaridgeTown_Gym_B1F/scripts.pory"
LavaridgeTown_Gym_B1F_EventScript_SetJaceTempVar::
# 20 "data/maps/LavaridgeTown_Gym_B1F/scripts.pory"
	goto_if_defeated TRAINER_JACE, LavaridgeTown_Gym_B1F_EventScript_SetJeffTempVar
# 21 "data/maps/LavaridgeTown_Gym_B1F/scripts.pory"
	setvar VAR_TEMP_8, 1
# 22 "data/maps/LavaridgeTown_Gym_B1F/scripts.pory"
LavaridgeTown_Gym_B1F_EventScript_SetJeffTempVar::
# 23 "data/maps/LavaridgeTown_Gym_B1F/scripts.pory"
	goto_if_defeated TRAINER_JEFF, LavaridgeTown_Gym_B1F_EventScript_SetEliTempVar
# 24 "data/maps/LavaridgeTown_Gym_B1F/scripts.pory"
	setvar VAR_TEMP_9, 1
# 25 "data/maps/LavaridgeTown_Gym_B1F/scripts.pory"
LavaridgeTown_Gym_B1F_EventScript_SetEliTempVar::
# 26 "data/maps/LavaridgeTown_Gym_B1F/scripts.pory"
	goto_if_defeated TRAINER_ELI, LavaridgeTown_Gym_B1F_EventScript_EndSetTrainerTempVars
# 27 "data/maps/LavaridgeTown_Gym_B1F/scripts.pory"
	setvar VAR_TEMP_A, 1
# 28 "data/maps/LavaridgeTown_Gym_B1F/scripts.pory"
LavaridgeTown_Gym_B1F_EventScript_EndSetTrainerTempVars::
# 29 "data/maps/LavaridgeTown_Gym_B1F/scripts.pory"
	return
# 30 "data/maps/LavaridgeTown_Gym_B1F/scripts.pory"

# 31 "data/maps/LavaridgeTown_Gym_B1F/scripts.pory"
LavaridgeTown_Gym_B1F_EventScript_CheckBuryTrainers::
# 32 "data/maps/LavaridgeTown_Gym_B1F/scripts.pory"
	goto_if_defeated TRAINER_KEEGAN, LavaridgeTown_Gym_B1F_EventScript_CheckBuryJace
# 33 "data/maps/LavaridgeTown_Gym_B1F/scripts.pory"
	setobjectmovementtype LOCALID_KEEGAN, MOVEMENT_TYPE_BURIED
# 34 "data/maps/LavaridgeTown_Gym_B1F/scripts.pory"
LavaridgeTown_Gym_B1F_EventScript_CheckBuryJace::
# 35 "data/maps/LavaridgeTown_Gym_B1F/scripts.pory"
	goto_if_defeated TRAINER_JACE, LavaridgeTown_Gym_B1F_EventScript_CheckBuryJeff
# 36 "data/maps/LavaridgeTown_Gym_B1F/scripts.pory"
	setobjectmovementtype LOCALID_JACE, MOVEMENT_TYPE_BURIED
# 37 "data/maps/LavaridgeTown_Gym_B1F/scripts.pory"
LavaridgeTown_Gym_B1F_EventScript_CheckBuryJeff::
# 38 "data/maps/LavaridgeTown_Gym_B1F/scripts.pory"
	goto_if_defeated TRAINER_JEFF, LavaridgeTown_Gym_B1F_EventScript_CheckBuryEli
# 39 "data/maps/LavaridgeTown_Gym_B1F/scripts.pory"
	setobjectmovementtype LOCALID_JEFF, MOVEMENT_TYPE_BURIED
# 40 "data/maps/LavaridgeTown_Gym_B1F/scripts.pory"
LavaridgeTown_Gym_B1F_EventScript_CheckBuryEli::
# 41 "data/maps/LavaridgeTown_Gym_B1F/scripts.pory"
	goto_if_defeated TRAINER_ELI, LavaridgeTown_Gym_B1F_EventScript_EndCheckBuryTrainers
# 42 "data/maps/LavaridgeTown_Gym_B1F/scripts.pory"
	setobjectmovementtype LOCALID_ELI, MOVEMENT_TYPE_BURIED
# 43 "data/maps/LavaridgeTown_Gym_B1F/scripts.pory"
LavaridgeTown_Gym_B1F_EventScript_EndCheckBuryTrainers::
# 44 "data/maps/LavaridgeTown_Gym_B1F/scripts.pory"
	return
