# 1 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 2 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
.set LOCALID_COLE, 2
# 3 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
.set LOCALID_GERALD, 3
# 4 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
.set LOCALID_AXLE, 4
# 5 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
.set LOCALID_DANIELLE, 5
# 6 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 7 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_1F_MapScripts::
# 8 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, LavaridgeTown_Gym_1F_OnTransition
# 9 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.byte 0
# 10 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 11 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_1F_OnTransition:
# 12 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	call LavaridgeTown_Gym_1F_EventScript_SetTrainerTempVars
# 13 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	call LavaridgeTown_Gym_1F_EventScript_CheckBuryTrainers
# 14 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	end
# 15 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 16 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
@ Unclear where/if these temp vars are getting checked
# 17 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_1F_EventScript_SetTrainerTempVars::
# 18 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	setvar VAR_TEMP_B, 0
# 19 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	setvar VAR_TEMP_C, 0
# 20 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	setvar VAR_TEMP_D, 0
# 21 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	setvar VAR_TEMP_E, 0
# 22 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	setvar VAR_TEMP_F, 0
# 23 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	goto_if_defeated TRAINER_COLE, LavaridgeTown_Gym_1F_EventScript_SetGeraldTempVar
# 24 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	setvar VAR_TEMP_B, 1
# 25 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_1F_EventScript_SetGeraldTempVar::
# 26 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	goto_if_defeated TRAINER_GERALD, LavaridgeTown_Gym_1F_EventScript_SetAxleTempVar
# 27 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	setvar VAR_TEMP_C, 1
# 28 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_1F_EventScript_SetAxleTempVar::
# 29 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	goto_if_defeated TRAINER_AXLE, LavaridgeTown_Gym_1F_EventScript_SetDanielleTempVar
# 30 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	setvar VAR_TEMP_D, 1
# 31 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_1F_EventScript_SetDanielleTempVar::
# 32 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	goto_if_defeated TRAINER_DANIELLE, LavaridgeTown_Gym_1F_EventScript_EndSetTrainerTempVars
# 33 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	setvar VAR_TEMP_E, 1
# 34 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_1F_EventScript_EndSetTrainerTempVars::
# 35 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	return
# 36 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 37 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_1F_EventScript_CheckBuryTrainers::
# 38 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	goto_if_defeated TRAINER_COLE, LavaridgeTown_Gym_1F_EventScript_CheckBuryGerald
# 39 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	setobjectmovementtype LOCALID_COLE, MOVEMENT_TYPE_BURIED
# 40 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_1F_EventScript_CheckBuryGerald::
# 41 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	goto_if_defeated TRAINER_GERALD, LavaridgeTown_Gym_1F_EventScript_CheckBuryAxle
# 42 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	setobjectmovementtype LOCALID_GERALD, MOVEMENT_TYPE_BURIED
# 43 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_1F_EventScript_CheckBuryAxle::
# 44 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	goto_if_defeated TRAINER_AXLE, LavaridgeTown_Gym_1F_EventScript_CheckBuryDanielle
# 45 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	setobjectmovementtype LOCALID_AXLE, MOVEMENT_TYPE_BURIED
# 46 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_1F_EventScript_CheckBuryDanielle::
# 47 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	goto_if_defeated TRAINER_DANIELLE, LavaridgeTown_Gym_1F_EventScript_EndCheckBuryTrainers
# 48 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	setobjectmovementtype LOCALID_DANIELLE, MOVEMENT_TYPE_BURIED
# 49 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_1F_EventScript_EndCheckBuryTrainers::
# 50 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	return
# 51 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 52 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_1F_EventScript_Flannery::
# 53 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	trainerbattle_single TRAINER_FLANNERY_1, LavaridgeTown_Gym_1F_Text_FlanneryIntro, LavaridgeTown_Gym_1F_Text_FlanneryDefeat, LavaridgeTown_Gym_1F_EventScript_FlanneryDefeated, NO_MUSIC
# 54 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 55 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, LavaridgeTown_Gym_1F_EventScript_FlanneryRematch
# 56 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	goto_if_unset FLAG_RECEIVED_TM_OVERHEAT, LavaridgeTown_Gym_1F_EventScript_GiveOverheat2
# 57 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	msgbox LavaridgeTown_Gym_1F_Text_FlanneryPostBattle, MSGBOX_DEFAULT
# 58 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	release
# 59 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	end
# 60 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 61 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_1F_EventScript_FlanneryDefeated::
# 62 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	message LavaridgeTown_Gym_1F_Text_ReceivedHeatBadge
# 63 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	waitmessage
# 64 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	call Common_EventScript_PlayGymBadgeFanfare
# 65 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	msgbox LavaridgeTown_Gym_1F_Text_ExplainHeatBadgeTakeThis, MSGBOX_DEFAULT
# 66 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	setflag FLAG_WHITEOUT_TO_LAVARIDGE
# 67 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	setflag FLAG_DEFEATED_LAVARIDGE_GYM
# 68 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	setflag FLAG_BADGE04_GET
# 69 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	addvar VAR_PETALBURG_GYM_STATE, 1
# 70 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	call_if_eq VAR_PETALBURG_GYM_STATE, 6, Common_EventScript_ReadyPetalburgGymForBattle
# 71 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	setvar VAR_0x8008, 4
# 72 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	call Common_EventScript_SetGymTrainers
# 73 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	setflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WALLY
# 74 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	setvar VAR_LAVARIDGE_TOWN_STATE, 1
# 75 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	call LavaridgeTown_Gym_1F_EventScript_GiveOverheat
# 76 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	closemessage
# 77 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	delay 30
# 78 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	playfanfare MUS_REGISTER_MATCH_CALL
# 79 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	msgbox LavaridgeTown_Gym_1F_Text_RegisteredFlannery, MSGBOX_DEFAULT
# 80 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	waitfanfare
# 81 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	closemessage
# 82 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	delay 30
# 83 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	setflag FLAG_ENABLE_FLANNERY_MATCH_CALL
# 84 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	release
# 85 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	end
# 86 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 87 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_1F_EventScript_GiveOverheat2::
# 88 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	giveitem ITEM_TM_OVERHEAT
# 89 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 90 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	msgbox LavaridgeTown_Gym_1F_Text_ExplainOverheat, MSGBOX_DEFAULT
# 91 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	setflag FLAG_RECEIVED_TM_OVERHEAT
# 92 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	release
# 93 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	end
# 94 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 95 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_1F_EventScript_GiveOverheat::
# 96 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	giveitem ITEM_TM_OVERHEAT
# 97 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
# 98 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	msgbox LavaridgeTown_Gym_1F_Text_ExplainOverheat, MSGBOX_DEFAULT
# 99 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	setflag FLAG_RECEIVED_TM_OVERHEAT
# 100 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	return
# 101 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 102 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_1F_EventScript_FlanneryRematch::
# 103 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	trainerbattle_rematch_double TRAINER_FLANNERY_1, LavaridgeTown_Gym_1F_Text_FlanneryPreRematch, LavaridgeTown_Gym_1F_Text_FlanneryRematchDefeat, LavaridgeTown_Gym_1F_Text_FlanneryRematchNeedTwoMons
# 104 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	msgbox LavaridgeTown_Gym_1F_Text_FlanneryPostRematch, MSGBOX_AUTOCLOSE
# 105 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	end
# 106 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 107 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_1F_EventScript_Cole::
# 108 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, LOCALID_COLE, TRAINER_COLE, LavaridgeTown_Gym_1F_Text_ColeIntro, LavaridgeTown_Gym_1F_Text_ColeDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript, OBJ_ID_NONE, TRAINER_NONE, NULL, NULL, NULL, NULL, NULL, FALSE, TRUE, FALSE, FALSE
# 109 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	msgbox LavaridgeTown_Gym_1F_Text_ColePostBattle, MSGBOX_AUTOCLOSE
# 110 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	end
# 111 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 112 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_EventScript_CheckTrainerScript::
# 113 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	call LavaridgeTown_Gym_1F_EventScript_SetTrainerTempVars
# 114 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	release
# 115 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	special ShouldTryGetTrainerScript
# 116 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	goto_if_eq VAR_RESULT, 1, EventScript_GotoTrainerScript
# 117 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	end
# 118 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 119 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_1F_EventScript_Axle::
# 120 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, LOCALID_AXLE, TRAINER_AXLE, LavaridgeTown_Gym_1F_Text_AxleIntro, LavaridgeTown_Gym_1F_Text_AxleDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript, OBJ_ID_NONE, TRAINER_NONE, NULL, NULL, NULL, NULL, NULL, FALSE, TRUE, FALSE, FALSE
# 121 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	msgbox LavaridgeTown_Gym_1F_Text_AxlePostBattle, MSGBOX_AUTOCLOSE
# 122 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	end
# 123 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 124 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_B1F_EventScript_Keegan::
# 125 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, LOCALID_KEEGAN, TRAINER_KEEGAN, LavaridgeTown_Gym_B1F_Text_KeeganIntro, LavaridgeTown_Gym_B1F_Text_KeeganDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript, OBJ_ID_NONE, TRAINER_NONE, NULL, NULL, NULL, NULL, NULL, FALSE, TRUE, FALSE, FALSE
# 126 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	msgbox LavaridgeTown_Gym_B1F_Text_KeeganPostBattle, MSGBOX_AUTOCLOSE
# 127 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	end
# 128 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 129 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_1F_EventScript_Danielle::
# 130 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, LOCALID_DANIELLE, TRAINER_DANIELLE, LavaridgeTown_Gym_1F_Text_DanielleIntro, LavaridgeTown_Gym_1F_Text_DanielleDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript, OBJ_ID_NONE, TRAINER_NONE, NULL, NULL, NULL, NULL, NULL, FALSE, TRUE, FALSE, FALSE
# 131 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	msgbox LavaridgeTown_Gym_1F_Text_DaniellePostBattle, MSGBOX_AUTOCLOSE
# 132 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	end
# 133 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 134 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_1F_EventScript_Gerald::
# 135 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, LOCALID_GERALD, TRAINER_GERALD, LavaridgeTown_Gym_1F_Text_GeraldIntro, LavaridgeTown_Gym_1F_Text_GeraldDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript, OBJ_ID_NONE, TRAINER_NONE, NULL, NULL, NULL, NULL, NULL, FALSE, TRUE, FALSE, FALSE
# 136 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	msgbox LavaridgeTown_Gym_1F_Text_GeraldPostBattle, MSGBOX_AUTOCLOSE
# 137 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	end
# 138 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 139 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_B1F_EventScript_Jace::
# 140 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, LOCALID_JACE, TRAINER_JACE, LavaridgeTown_Gym_B1F_Text_JaceIntro, LavaridgeTown_Gym_B1F_Text_JaceDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript, OBJ_ID_NONE, TRAINER_NONE, NULL, NULL, NULL, NULL, NULL, FALSE, TRUE, FALSE, FALSE
# 141 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	msgbox LavaridgeTown_Gym_B1F_Text_JacePostBattle, MSGBOX_AUTOCLOSE
# 142 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	end
# 143 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 144 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_B1F_EventScript_Jeff::
# 145 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, LOCALID_JEFF, TRAINER_JEFF, LavaridgeTown_Gym_B1F_Text_JeffIntro, LavaridgeTown_Gym_B1F_Text_JeffDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript, OBJ_ID_NONE, TRAINER_NONE, NULL, NULL, NULL, NULL, NULL, FALSE, TRUE, FALSE, FALSE
# 146 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	msgbox LavaridgeTown_Gym_B1F_Text_JeffPostBattle, MSGBOX_AUTOCLOSE
# 147 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	end
# 148 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 149 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_B1F_EventScript_Eli::
# 150 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, LOCALID_ELI, TRAINER_ELI, LavaridgeTown_Gym_B1F_Text_EliIntro, LavaridgeTown_Gym_B1F_Text_EliDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript, OBJ_ID_NONE, TRAINER_NONE, NULL, NULL, NULL, NULL, NULL, FALSE, TRUE, FALSE, FALSE
# 151 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	msgbox LavaridgeTown_Gym_B1F_Text_EliPostBattle, MSGBOX_AUTOCLOSE
# 152 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	end
# 153 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 154 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_1F_EventScript_GymGuide::
# 155 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	lock
# 156 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	faceplayer
# 157 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	goto_if_set FLAG_DEFEATED_LAVARIDGE_GYM, LavaridgeTown_Gym_1F_EventScript_GymGuidePostVictory
# 158 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	msgbox LavaridgeTown_Gym_1F_Text_GymGuideAdvice, MSGBOX_DEFAULT
# 159 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	release
# 160 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	end
# 161 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 162 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_1F_EventScript_GymGuidePostVictory::
# 163 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	msgbox LavaridgeTown_Gym_1F_Text_GymGuidePostVictory, MSGBOX_DEFAULT
# 164 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	release
# 165 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	end
# 166 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 167 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_1F_EventScript_LeftGymStatue::
# 168 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	lockall
# 169 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	goto_if_set FLAG_BADGE04_GET, LavaridgeTown_Gym_1F_EventScript_GymStatueCertified
# 170 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	goto LavaridgeTown_Gym_1F_EventScript_GymStatue
# 171 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	end
# 172 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 173 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_1F_EventScript_RightGymStatue::
# 174 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	lockall
# 175 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	goto_if_set FLAG_BADGE04_GET, LavaridgeTown_Gym_1F_EventScript_GymStatueCertified
# 176 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	goto LavaridgeTown_Gym_1F_EventScript_GymStatue
# 177 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	end
# 178 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 179 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_1F_EventScript_GymStatueCertified::
# 180 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	msgbox LavaridgeTown_Gym_1F_Text_GymStatueCertified, MSGBOX_DEFAULT
# 181 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	releaseall
# 182 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	end
# 183 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 184 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_1F_EventScript_GymStatue::
# 185 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	msgbox LavaridgeTown_Gym_1F_Text_GymStatue, MSGBOX_DEFAULT
# 186 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	releaseall
# 187 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	end
# 188 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 189 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_1F_Text_GymGuideAdvice:
# 190 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "Hey, how's it going, CHAMPION-\n"
# 191 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "bound {PLAYER}?\p"
# 192 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "LAVARIDGE's GYM LEADER FLANNERY\n"
# 193 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "uses FIRE-type POKéMON.\p"
# 194 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "Her passion for POKéMON burns stronger\n"
# 195 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "and hotter than a volcano.\p"
# 196 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "Don't get too close to her--you'll burn!\n"
# 197 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "Hose her down with water and then\l"
# 198 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "go for it!$"
# 199 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 200 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_1F_Text_GymGuidePostVictory:
# 201 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "Yow! That was a scorching-hot battle!$"
# 202 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 203 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_1F_Text_ColeIntro:
# 204 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "Owowowowow!\n"
# 205 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "Yikes, it's hot!$"
# 206 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 207 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_1F_Text_ColeDefeat:
# 208 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "I'm blinded by sweat in my eyes…$"
# 209 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 210 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_1F_Text_ColePostBattle:
# 211 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "Being buried in hot sand promotes\n"
# 212 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "circulation.\p"
# 213 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "It's effective for healing pain in\n"
# 214 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "your joints.$"
# 215 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 216 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_1F_Text_AxleIntro:
# 217 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "I'm trying to relieve my stress.\n"
# 218 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "Don't come along and stress me out!$"
# 219 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 220 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_1F_Text_AxleDefeat:
# 221 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "I hope FLANNERY flames you good!$"
# 222 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 223 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_1F_Text_AxlePostBattle:
# 224 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "Haaah… Whew…\p"
# 225 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "If you spend too much time buried in\n"
# 226 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "hot sand, it tuckers you out…$"
# 227 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 228 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_B1F_Text_KeeganIntro:
# 229 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "You must be getting tired by now.\n"
# 230 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "You'd like to rest in the hot sand,\l"
# 231 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "wouldn't you?\p"
# 232 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "But you should know that maintaining\n"
# 233 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "your willpower is an important ability\l"
# 234 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "for all TRAINERS.$"
# 235 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 236 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_B1F_Text_KeeganDefeat:
# 237 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "Play with fire, and be burned…$"
# 238 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 239 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_B1F_Text_KeeganPostBattle:
# 240 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "Your skill is real…\n"
# 241 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "But our LEADER FLANNERY is strong.\p"
# 242 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "If you don't watch yourself, you'll be\n"
# 243 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "burned seriously.$"
# 244 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 245 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_1F_Text_GeraldIntro:
# 246 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "Can your POKéMON withstand\n"
# 247 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "392-degree heat?$"
# 248 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 249 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_1F_Text_GeraldDefeat:
# 250 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "It didn't burn hotly enough…$"
# 251 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 252 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_1F_Text_GeraldPostBattle:
# 253 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "The temperature of magma is\n"
# 254 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "392 degrees.\p"
# 255 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "Your POKéMON beat me, so they should\n"
# 256 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "easily survive in magma.$"
# 257 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 258 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_1F_Text_DanielleIntro:
# 259 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "Um…\n"
# 260 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "Okay, I'll battle with you.$"
# 261 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 262 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_1F_Text_DanielleDefeat:
# 263 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "Oh, but you're too strong.$"
# 264 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 265 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_1F_Text_DaniellePostBattle:
# 266 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "I'm going to be a pretty and strong\n"
# 267 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "TRAINER just like FLANNERY.$"
# 268 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 269 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_B1F_Text_JaceIntro:
# 270 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "Come on, get with it!\n"
# 271 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "Let's go before my feelings cool!$"
# 272 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 273 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_B1F_Text_JaceDefeat:
# 274 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "It's so hot, and yet my heart is\n"
# 275 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "clutched by ice…$"
# 276 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 277 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_B1F_Text_JacePostBattle:
# 278 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "The way the battling spirit burns\n"
# 279 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "within you, you may stand a chance\l"
# 280 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "against our LEADER.$"
# 281 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 282 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_B1F_Text_JeffIntro:
# 283 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "See how the flames blaze wildly?\n"
# 284 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "They flare in anticipation of my win!$"
# 285 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 286 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_B1F_Text_JeffDefeat:
# 287 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "Something didn't go right.$"
# 288 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 289 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_B1F_Text_JeffPostBattle:
# 290 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "Well, so what? I say so what?\n"
# 291 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "I can walk on hot coals barefoot!\p"
# 292 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "…Don't even think about trying it!$"
# 293 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 294 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_B1F_Text_EliIntro:
# 295 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "As much as I love mountains,\n"
# 296 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "I especially love volcanoes.$"
# 297 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 298 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_B1F_Text_EliDefeat:
# 299 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "Well, it seems to me I lost without\n"
# 300 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "ever being in control.$"
# 301 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 302 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_B1F_Text_EliPostBattle:
# 303 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "I stay here because I became a fan\n"
# 304 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "of FLANNERY's power.\p"
# 305 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "Hehehehe.$"
# 306 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 307 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_1F_Text_FlanneryIntro:
# 308 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "Welcome… No, wait.\p"
# 309 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "Puny TRAINER, how good to see you've\n"
# 310 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "made it here!\p"
# 311 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "I have been entrusted with the…\n"
# 312 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "No, wait.\p"
# 313 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "I am FLANNERY, and I'm the GYM\n"
# 314 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "LEADER here!\p"
# 315 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "Uh…\n"
# 316 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "Dare not underestimate me, though\l"
# 317 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "I have been LEADER only a short time!\p"
# 318 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "With skills inherited from my grand-\n"
# 319 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "father, I shall, uh…demonstrate the\l"
# 320 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "hot moves we have honed on this land!$"
# 321 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 322 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_1F_Text_FlanneryDefeat:
# 323 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "Oh…\n"
# 324 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "I guess I was trying too hard…\p"
# 325 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "I… I've only recently become\n"
# 326 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "a GYM LEADER.\p"
# 327 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "I tried too hard to be someone\n"
# 328 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "I'm not.\p"
# 329 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "I have to do things my natural way. If\n"
# 330 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "I don't, my POKéMON will be confused.\p"
# 331 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "Thanks for teaching me that.\n"
# 332 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "For that, you deserve this.$"
# 333 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 334 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_1F_Text_ReceivedHeatBadge:
# 335 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "{PLAYER} received the HEAT BADGE\n"
# 336 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "from FLANNERY.$"
# 337 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 338 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_1F_Text_ExplainHeatBadgeTakeThis:
# 339 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "If you have a HEAT BADGE, all POKéMON\n"
# 340 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "up to Level 50, even those you get in\l"
# 341 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "trades from other people, will obey\l"
# 342 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "you completely.\p"
# 343 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "And, it lets POKéMON use the HM move\n"
# 344 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "STRENGTH outside of battle.\p"
# 345 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "This is a token of my appreciation.\n"
# 346 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "Don't be shy about taking it!$"
# 347 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 348 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_1F_Text_ExplainOverheat:
# 349 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "That TM50 contains OVERHEAT.\p"
# 350 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "That move inflicts serious damage on\n"
# 351 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "the opponent.\p"
# 352 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "But it also sharply cuts the SP. ATK\n"
# 353 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "of the POKéMON using it. It might not\l"
# 354 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "be suitable for longer battles.$"
# 355 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 356 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_1F_Text_RegisteredFlannery:
# 357 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "Registered GYM LEADER FLANNERY\n"
# 358 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "in the POKéNAV.$"
# 359 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 360 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_1F_Text_FlanneryPostBattle:
# 361 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "Your power reminds me of someone…\p"
# 362 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "Oh! I know! You battle like NORMAN,\n"
# 363 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "the GYM LEADER of PETALBURG.$"
# 364 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 365 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_1F_Text_GymStatue:
# 366 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "LAVARIDGE TOWN POKéMON GYM$"
# 367 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 368 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_1F_Text_GymStatueCertified:
# 369 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "LAVARIDGE TOWN POKéMON GYM\p"
# 370 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "FLANNERY'S CERTIFIED TRAINERS:\n"
# 371 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "{PLAYER}$"
# 372 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 373 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_1F_Text_FlanneryPreRematch:
# 374 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "FLANNERY: Losing a battle isn't going\n"
# 375 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "to deflate me.\p"
# 376 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "I love POKéMON.\n"
# 377 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "I love to battle.\l"
# 378 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "And… I love this GYM!\p"
# 379 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "Let's exchange superhot moves\n"
# 380 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "in another battle!$"
# 381 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 382 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_1F_Text_FlanneryRematchDefeat:
# 383 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "Whew!\n"
# 384 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "On the verge of eruption!$"
# 385 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 386 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_1F_Text_FlanneryPostRematch:
# 387 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "FLANNERY: I lost the match,\n"
# 388 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "but I'm completely satisfied.\p"
# 389 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "It's not often I get to enjoy a battle\n"
# 390 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "this heated.\p"
# 391 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "Let's have another one like this\n"
# 392 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "again sometime!$"
# 393 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 394 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_1F_Text_FlanneryRematchNeedTwoMons:
# 395 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "FLANNERY: Losing a battle isn't going\n"
# 396 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "to deflate me.\p"
# 397 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "I love POKéMON.\n"
# 398 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "I love to battle.\l"
# 399 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "And… I love this GYM!\p"
# 400 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "Let's exchange superhot moves\n"
# 401 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "in another battle!\p"
# 402 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "Oh, wait. Do you only have one POKéMON\n"
# 403 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "that can battle?\p"
# 404 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "I hate to say this, but when you come\n"
# 405 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "see me, bring at least two POKéMON.$"
