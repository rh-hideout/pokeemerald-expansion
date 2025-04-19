# 1 "data/maps/MossdeepCity_Gym/scripts.pory"

# 2 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_MapScripts::
# 3 "data/maps/MossdeepCity_Gym/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, MossdeepCity_Gym_OnTransition
# 4 "data/maps/MossdeepCity_Gym/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, MossdeepCity_Gym_OnLoad
# 5 "data/maps/MossdeepCity_Gym/scripts.pory"
	.byte 0
# 6 "data/maps/MossdeepCity_Gym/scripts.pory"

# 7 "data/maps/MossdeepCity_Gym/scripts.pory"
@ NOTE: Mossdeep Gym was redesigned between R/S and E. Leftover (and now functionally unused) scripts are commented below
# 8 "data/maps/MossdeepCity_Gym/scripts.pory"

# 9 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_OnTransition:
# 10 "data/maps/MossdeepCity_Gym/scripts.pory"
	setflag FLAG_TEMP_HIDE_FOLLOWER @ Hide follower since it can collide with moving statues
# 11 "data/maps/MossdeepCity_Gym/scripts.pory"
	end
# 12 "data/maps/MossdeepCity_Gym/scripts.pory"

# 13 "data/maps/MossdeepCity_Gym/scripts.pory"
@ All the below checks are leftover from RS. FLAG_MOSSDEEP_GYM_SWITCH_X is never set
# 14 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_OnLoad:
# 15 "data/maps/MossdeepCity_Gym/scripts.pory"
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_1, MossdeepCity_Gym_EventScript_SetSwitch1Metatiles
# 16 "data/maps/MossdeepCity_Gym/scripts.pory"
	goto MossdeepCity_Gym_EventScript_CheckSwitch2
# 17 "data/maps/MossdeepCity_Gym/scripts.pory"
	end
# 18 "data/maps/MossdeepCity_Gym/scripts.pory"

# 19 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_CheckSwitch2::
# 20 "data/maps/MossdeepCity_Gym/scripts.pory"
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_2, MossdeepCity_Gym_EventScript_SetSwitch2Metatiles
# 21 "data/maps/MossdeepCity_Gym/scripts.pory"
	goto MossdeepCity_Gym_EventScript_CheckSwitch3
# 22 "data/maps/MossdeepCity_Gym/scripts.pory"
	end
# 23 "data/maps/MossdeepCity_Gym/scripts.pory"

# 24 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_CheckSwitch3::
# 25 "data/maps/MossdeepCity_Gym/scripts.pory"
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_3, MossdeepCity_Gym_EventScript_SetSwitch3Metatiles
# 26 "data/maps/MossdeepCity_Gym/scripts.pory"
	goto MossdeepCity_Gym_EventScript_CheckSwitch4
# 27 "data/maps/MossdeepCity_Gym/scripts.pory"
	end
# 28 "data/maps/MossdeepCity_Gym/scripts.pory"

# 29 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_CheckSwitch4::
# 30 "data/maps/MossdeepCity_Gym/scripts.pory"
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_4, MossdeepCity_Gym_EventScript_SetSwitch4Metatiles
# 31 "data/maps/MossdeepCity_Gym/scripts.pory"
	end
# 32 "data/maps/MossdeepCity_Gym/scripts.pory"

# 33 "data/maps/MossdeepCity_Gym/scripts.pory"
@ All the below set metatile scripts are leftover from RS and are functionally unused
# 34 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_SetSwitch1Metatiles::
# 35 "data/maps/MossdeepCity_Gym/scripts.pory"
	setmetatile 5, 5, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
# 36 "data/maps/MossdeepCity_Gym/scripts.pory"
	setmetatile 2, 7, METATILE_RSMossdeepGym_Switch_Down, TRUE
# 37 "data/maps/MossdeepCity_Gym/scripts.pory"
	goto MossdeepCity_Gym_EventScript_CheckSwitch2
# 38 "data/maps/MossdeepCity_Gym/scripts.pory"
	end
# 39 "data/maps/MossdeepCity_Gym/scripts.pory"

# 40 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_SetSwitch2Metatiles::
# 41 "data/maps/MossdeepCity_Gym/scripts.pory"
	setmetatile 8, 14, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
# 42 "data/maps/MossdeepCity_Gym/scripts.pory"
	setmetatile 8, 10, METATILE_RSMossdeepGym_Switch_Down, TRUE
# 43 "data/maps/MossdeepCity_Gym/scripts.pory"
	goto MossdeepCity_Gym_EventScript_CheckSwitch3
# 44 "data/maps/MossdeepCity_Gym/scripts.pory"
	end
# 45 "data/maps/MossdeepCity_Gym/scripts.pory"

# 46 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_SetSwitch3Metatiles::
# 47 "data/maps/MossdeepCity_Gym/scripts.pory"
	setmetatile 15, 17, METATILE_RSMossdeepGym_RedArrow_Left, FALSE
# 48 "data/maps/MossdeepCity_Gym/scripts.pory"
	setmetatile 17, 15, METATILE_RSMossdeepGym_Switch_Down, TRUE
# 49 "data/maps/MossdeepCity_Gym/scripts.pory"
	goto MossdeepCity_Gym_EventScript_CheckSwitch4
# 50 "data/maps/MossdeepCity_Gym/scripts.pory"
	end
# 51 "data/maps/MossdeepCity_Gym/scripts.pory"

# 52 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_SetSwitch4Metatiles::
# 53 "data/maps/MossdeepCity_Gym/scripts.pory"
	setmetatile 1, 23, METATILE_RSMossdeepGym_RedArrow_Up, FALSE
# 54 "data/maps/MossdeepCity_Gym/scripts.pory"
	setmetatile 5, 24, METATILE_RSMossdeepGym_Switch_Down, TRUE
# 55 "data/maps/MossdeepCity_Gym/scripts.pory"
	end
# 56 "data/maps/MossdeepCity_Gym/scripts.pory"

# 57 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_TateAndLiza::
# 58 "data/maps/MossdeepCity_Gym/scripts.pory"
	trainerbattle_double TRAINER_TATE_AND_LIZA_1, MossdeepCity_Gym_Text_TateAndLizaIntro, MossdeepCity_Gym_Text_TateAndLizaDefeat, MossdeepCity_Gym_Text_TateAndLizaNeedTwoMons, MossdeepCity_Gym_EventScript_TateAndLizaDefeated, NO_MUSIC
# 59 "data/maps/MossdeepCity_Gym/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 60 "data/maps/MossdeepCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, MossdeepCity_Gym_EventScript_TateAndLizaRematch
# 61 "data/maps/MossdeepCity_Gym/scripts.pory"
	goto_if_unset FLAG_RECEIVED_TM_CALM_MIND, MossdeepCity_Gym_EventScript_GiveCalmMind2
# 62 "data/maps/MossdeepCity_Gym/scripts.pory"
	msgbox MossdeepCity_Gym_Text_TateAndLizaPostBattle, MSGBOX_DEFAULT
# 63 "data/maps/MossdeepCity_Gym/scripts.pory"
	release
# 64 "data/maps/MossdeepCity_Gym/scripts.pory"
	end
# 65 "data/maps/MossdeepCity_Gym/scripts.pory"

# 66 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_TateAndLizaDefeated::
# 67 "data/maps/MossdeepCity_Gym/scripts.pory"
	message MossdeepCity_Gym_Text_ReceivedMindBadge
# 68 "data/maps/MossdeepCity_Gym/scripts.pory"
	waitmessage
# 69 "data/maps/MossdeepCity_Gym/scripts.pory"
	call Common_EventScript_PlayGymBadgeFanfare
# 70 "data/maps/MossdeepCity_Gym/scripts.pory"
	msgbox MossdeepCity_Gym_Text_ExplainMindBadgeTakeThis, MSGBOX_DEFAULT
# 71 "data/maps/MossdeepCity_Gym/scripts.pory"
	setflag FLAG_DEFEATED_MOSSDEEP_GYM
# 72 "data/maps/MossdeepCity_Gym/scripts.pory"
	setflag FLAG_BADGE07_GET
# 73 "data/maps/MossdeepCity_Gym/scripts.pory"
	setflag FLAG_HIDE_AQUA_HIDEOUT_GRUNTS
# 74 "data/maps/MossdeepCity_Gym/scripts.pory"
	clearflag FLAG_HIDE_SLATEPORT_CITY_STERNS_SHIPYARD_MR_BRINEY
# 75 "data/maps/MossdeepCity_Gym/scripts.pory"
	clearflag FLAG_UNKNOWN_0x393
# 76 "data/maps/MossdeepCity_Gym/scripts.pory"
	setvar VAR_0x8008, 7
# 77 "data/maps/MossdeepCity_Gym/scripts.pory"
	call Common_EventScript_SetGymTrainers
# 78 "data/maps/MossdeepCity_Gym/scripts.pory"
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_PATRONS
# 79 "data/maps/MossdeepCity_Gym/scripts.pory"
	clearflag FLAG_HIDE_MOSSDEEP_CITY_TEAM_MAGMA
# 80 "data/maps/MossdeepCity_Gym/scripts.pory"
	clearflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_1F_TEAM_MAGMA
# 81 "data/maps/MossdeepCity_Gym/scripts.pory"
	clearflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_2F_TEAM_MAGMA
# 82 "data/maps/MossdeepCity_Gym/scripts.pory"
	clearflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_2F_STEVEN
# 83 "data/maps/MossdeepCity_Gym/scripts.pory"
	setvar VAR_MOSSDEEP_CITY_STATE, 1
# 84 "data/maps/MossdeepCity_Gym/scripts.pory"
	setflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_1F_STEVEN
# 85 "data/maps/MossdeepCity_Gym/scripts.pory"
	setvar VAR_MOSSDEEP_SPACE_CENTER_STATE, 1
# 86 "data/maps/MossdeepCity_Gym/scripts.pory"
	call MossdeepCity_Gym_EventScript_GiveCalmMind
# 87 "data/maps/MossdeepCity_Gym/scripts.pory"
	closemessage
# 88 "data/maps/MossdeepCity_Gym/scripts.pory"
	delay 30
# 89 "data/maps/MossdeepCity_Gym/scripts.pory"
	playfanfare MUS_REGISTER_MATCH_CALL
# 90 "data/maps/MossdeepCity_Gym/scripts.pory"
	msgbox MossdeepCity_Gym_Text_RegisteredTateAndLiza, MSGBOX_DEFAULT
# 91 "data/maps/MossdeepCity_Gym/scripts.pory"
	waitfanfare
# 92 "data/maps/MossdeepCity_Gym/scripts.pory"
	closemessage
# 93 "data/maps/MossdeepCity_Gym/scripts.pory"
	delay 30
# 94 "data/maps/MossdeepCity_Gym/scripts.pory"
	setflag FLAG_ENABLE_TATE_AND_LIZA_MATCH_CALL
# 95 "data/maps/MossdeepCity_Gym/scripts.pory"
	release
# 96 "data/maps/MossdeepCity_Gym/scripts.pory"
	end
# 97 "data/maps/MossdeepCity_Gym/scripts.pory"

# 98 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_GiveCalmMind2::
# 99 "data/maps/MossdeepCity_Gym/scripts.pory"
	giveitem ITEM_TM_CALM_MIND
# 100 "data/maps/MossdeepCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 101 "data/maps/MossdeepCity_Gym/scripts.pory"
	msgbox MossdeepCity_Gym_Text_ExplainCalmMind, MSGBOX_DEFAULT
# 102 "data/maps/MossdeepCity_Gym/scripts.pory"
	setflag FLAG_RECEIVED_TM_CALM_MIND
# 103 "data/maps/MossdeepCity_Gym/scripts.pory"
	release
# 104 "data/maps/MossdeepCity_Gym/scripts.pory"
	end
# 105 "data/maps/MossdeepCity_Gym/scripts.pory"

# 106 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_GiveCalmMind::
# 107 "data/maps/MossdeepCity_Gym/scripts.pory"
	giveitem ITEM_TM_CALM_MIND
# 108 "data/maps/MossdeepCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
# 109 "data/maps/MossdeepCity_Gym/scripts.pory"
	msgbox MossdeepCity_Gym_Text_ExplainCalmMind, MSGBOX_DEFAULT
# 110 "data/maps/MossdeepCity_Gym/scripts.pory"
	setflag FLAG_RECEIVED_TM_CALM_MIND
# 111 "data/maps/MossdeepCity_Gym/scripts.pory"
	return
# 112 "data/maps/MossdeepCity_Gym/scripts.pory"

# 113 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_TateAndLizaRematch::
# 114 "data/maps/MossdeepCity_Gym/scripts.pory"
	trainerbattle_rematch_double TRAINER_TATE_AND_LIZA_1, MossdeepCity_Gym_Text_TateAndLizaPreRematch, MossdeepCity_Gym_Text_TateAndLizaRematchDefeat, MossdeepCity_Gym_Text_TateAndLizaRematchNeedTwoMons
# 115 "data/maps/MossdeepCity_Gym/scripts.pory"
	msgbox MossdeepCity_Gym_Text_TateAndLizaPostRematch, MSGBOX_AUTOCLOSE
# 116 "data/maps/MossdeepCity_Gym/scripts.pory"
	end
# 117 "data/maps/MossdeepCity_Gym/scripts.pory"

# 118 "data/maps/MossdeepCity_Gym/scripts.pory"
@ All the below switch scripts are leftover from RS and are functionally unused
# 119 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_Switch1::
# 120 "data/maps/MossdeepCity_Gym/scripts.pory"
	lockall
# 121 "data/maps/MossdeepCity_Gym/scripts.pory"
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_1, MossdeepCity_Gym_EventScript_ClearSwitch1
# 122 "data/maps/MossdeepCity_Gym/scripts.pory"
	setflag FLAG_MOSSDEEP_GYM_SWITCH_1
# 123 "data/maps/MossdeepCity_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
# 124 "data/maps/MossdeepCity_Gym/scripts.pory"
	waitmovement 0
# 125 "data/maps/MossdeepCity_Gym/scripts.pory"
	setmetatile 5, 5, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
# 126 "data/maps/MossdeepCity_Gym/scripts.pory"
	setmetatile 2, 7, METATILE_RSMossdeepGym_Switch_Down, TRUE
# 127 "data/maps/MossdeepCity_Gym/scripts.pory"
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
# 128 "data/maps/MossdeepCity_Gym/scripts.pory"
	end
# 129 "data/maps/MossdeepCity_Gym/scripts.pory"

# 130 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed::
# 131 "data/maps/MossdeepCity_Gym/scripts.pory"
	special DrawWholeMapView
# 132 "data/maps/MossdeepCity_Gym/scripts.pory"
	playse SE_CLICK
# 133 "data/maps/MossdeepCity_Gym/scripts.pory"
	releaseall
# 134 "data/maps/MossdeepCity_Gym/scripts.pory"
	end
# 135 "data/maps/MossdeepCity_Gym/scripts.pory"

# 136 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_ClearSwitch1::
# 137 "data/maps/MossdeepCity_Gym/scripts.pory"
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_1
# 138 "data/maps/MossdeepCity_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
# 139 "data/maps/MossdeepCity_Gym/scripts.pory"
	waitmovement 0
# 140 "data/maps/MossdeepCity_Gym/scripts.pory"
	setmetatile 5, 5, METATILE_RSMossdeepGym_RedArrow_Left, FALSE
# 141 "data/maps/MossdeepCity_Gym/scripts.pory"
	setmetatile 2, 7, METATILE_RSMossdeepGym_Switch_Up, TRUE
# 142 "data/maps/MossdeepCity_Gym/scripts.pory"
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
# 143 "data/maps/MossdeepCity_Gym/scripts.pory"
	end
# 144 "data/maps/MossdeepCity_Gym/scripts.pory"

# 145 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_Switch2::
# 146 "data/maps/MossdeepCity_Gym/scripts.pory"
	lockall
# 147 "data/maps/MossdeepCity_Gym/scripts.pory"
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_2, MossdeepCity_Gym_EventScript_ClearSwitch2
# 148 "data/maps/MossdeepCity_Gym/scripts.pory"
	setflag FLAG_MOSSDEEP_GYM_SWITCH_2
# 149 "data/maps/MossdeepCity_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
# 150 "data/maps/MossdeepCity_Gym/scripts.pory"
	waitmovement 0
# 151 "data/maps/MossdeepCity_Gym/scripts.pory"
	setmetatile 8, 14, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
# 152 "data/maps/MossdeepCity_Gym/scripts.pory"
	setmetatile 8, 10, METATILE_RSMossdeepGym_Switch_Down, TRUE
# 153 "data/maps/MossdeepCity_Gym/scripts.pory"
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
# 154 "data/maps/MossdeepCity_Gym/scripts.pory"
	end
# 155 "data/maps/MossdeepCity_Gym/scripts.pory"

# 156 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_ClearSwitch2::
# 157 "data/maps/MossdeepCity_Gym/scripts.pory"
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_2
# 158 "data/maps/MossdeepCity_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
# 159 "data/maps/MossdeepCity_Gym/scripts.pory"
	waitmovement 0
# 160 "data/maps/MossdeepCity_Gym/scripts.pory"
	setmetatile 8, 14, METATILE_RSMossdeepGym_RedArrow_Down, FALSE
# 161 "data/maps/MossdeepCity_Gym/scripts.pory"
	setmetatile 8, 10, METATILE_RSMossdeepGym_Switch_Up, TRUE
# 162 "data/maps/MossdeepCity_Gym/scripts.pory"
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
# 163 "data/maps/MossdeepCity_Gym/scripts.pory"
	end
# 164 "data/maps/MossdeepCity_Gym/scripts.pory"

# 165 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_Switch3::
# 166 "data/maps/MossdeepCity_Gym/scripts.pory"
	lockall
# 167 "data/maps/MossdeepCity_Gym/scripts.pory"
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_3, MossdeepCity_Gym_EventScript_ClearSwitch3
# 168 "data/maps/MossdeepCity_Gym/scripts.pory"
	setflag FLAG_MOSSDEEP_GYM_SWITCH_3
# 169 "data/maps/MossdeepCity_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
# 170 "data/maps/MossdeepCity_Gym/scripts.pory"
	waitmovement 0
# 171 "data/maps/MossdeepCity_Gym/scripts.pory"
	setmetatile 15, 17, METATILE_RSMossdeepGym_RedArrow_Left, FALSE
# 172 "data/maps/MossdeepCity_Gym/scripts.pory"
	setmetatile 17, 15, METATILE_RSMossdeepGym_Switch_Down, TRUE
# 173 "data/maps/MossdeepCity_Gym/scripts.pory"
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
# 174 "data/maps/MossdeepCity_Gym/scripts.pory"
	end
# 175 "data/maps/MossdeepCity_Gym/scripts.pory"

# 176 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_ClearSwitch3::
# 177 "data/maps/MossdeepCity_Gym/scripts.pory"
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_3
# 178 "data/maps/MossdeepCity_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
# 179 "data/maps/MossdeepCity_Gym/scripts.pory"
	waitmovement 0
# 180 "data/maps/MossdeepCity_Gym/scripts.pory"
	setmetatile 15, 17, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
# 181 "data/maps/MossdeepCity_Gym/scripts.pory"
	setmetatile 17, 15, METATILE_RSMossdeepGym_Switch_Up, TRUE
# 182 "data/maps/MossdeepCity_Gym/scripts.pory"
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
# 183 "data/maps/MossdeepCity_Gym/scripts.pory"
	end
# 184 "data/maps/MossdeepCity_Gym/scripts.pory"

# 185 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_Switch4::
# 186 "data/maps/MossdeepCity_Gym/scripts.pory"
	lockall
# 187 "data/maps/MossdeepCity_Gym/scripts.pory"
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_4, MossdeepCity_Gym_EventScript_ClearSwitch4
# 188 "data/maps/MossdeepCity_Gym/scripts.pory"
	setflag FLAG_MOSSDEEP_GYM_SWITCH_4
# 189 "data/maps/MossdeepCity_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
# 190 "data/maps/MossdeepCity_Gym/scripts.pory"
	waitmovement 0
# 191 "data/maps/MossdeepCity_Gym/scripts.pory"
	setmetatile 1, 23, METATILE_RSMossdeepGym_RedArrow_Up, FALSE
# 192 "data/maps/MossdeepCity_Gym/scripts.pory"
	setmetatile 5, 24, METATILE_RSMossdeepGym_Switch_Down, TRUE
# 193 "data/maps/MossdeepCity_Gym/scripts.pory"
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
# 194 "data/maps/MossdeepCity_Gym/scripts.pory"
	end
# 195 "data/maps/MossdeepCity_Gym/scripts.pory"

# 196 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_ClearSwitch4::
# 197 "data/maps/MossdeepCity_Gym/scripts.pory"
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_4
# 198 "data/maps/MossdeepCity_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
# 199 "data/maps/MossdeepCity_Gym/scripts.pory"
	waitmovement 0
# 200 "data/maps/MossdeepCity_Gym/scripts.pory"
	setmetatile 1, 23, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
# 201 "data/maps/MossdeepCity_Gym/scripts.pory"
	setmetatile 5, 24, METATILE_RSMossdeepGym_Switch_Up, TRUE
# 202 "data/maps/MossdeepCity_Gym/scripts.pory"
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
# 203 "data/maps/MossdeepCity_Gym/scripts.pory"
	end
# 204 "data/maps/MossdeepCity_Gym/scripts.pory"

# 205 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_WarpToEntrance::
# 206 "data/maps/MossdeepCity_Gym/scripts.pory"
	lockall
# 207 "data/maps/MossdeepCity_Gym/scripts.pory"
	warpmossdeepgym MAP_MOSSDEEP_CITY_GYM, 7, 30
# 208 "data/maps/MossdeepCity_Gym/scripts.pory"
	waitstate
# 209 "data/maps/MossdeepCity_Gym/scripts.pory"
	releaseall
# 210 "data/maps/MossdeepCity_Gym/scripts.pory"
	end
# 211 "data/maps/MossdeepCity_Gym/scripts.pory"

# 212 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_Preston::
# 213 "data/maps/MossdeepCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_PRESTON, MossdeepCity_Gym_Text_PrestonIntro, MossdeepCity_Gym_Text_PrestonDefeat
# 214 "data/maps/MossdeepCity_Gym/scripts.pory"
	msgbox MossdeepCity_Gym_Text_PrestonPostBattle, MSGBOX_AUTOCLOSE
# 215 "data/maps/MossdeepCity_Gym/scripts.pory"
	end
# 216 "data/maps/MossdeepCity_Gym/scripts.pory"

# 217 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_Virgil::
# 218 "data/maps/MossdeepCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_VIRGIL, MossdeepCity_Gym_Text_VirgilIntro, MossdeepCity_Gym_Text_VirgilDefeat
# 219 "data/maps/MossdeepCity_Gym/scripts.pory"
	msgbox MossdeepCity_Gym_Text_VirgilPostBattle, MSGBOX_AUTOCLOSE
# 220 "data/maps/MossdeepCity_Gym/scripts.pory"
	end
# 221 "data/maps/MossdeepCity_Gym/scripts.pory"

# 222 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_Blake::
# 223 "data/maps/MossdeepCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_BLAKE, MossdeepCity_Gym_Text_BlakeIntro, MossdeepCity_Gym_Text_BlakeDefeat
# 224 "data/maps/MossdeepCity_Gym/scripts.pory"
	msgbox MossdeepCity_Gym_Text_BlakePostBattle, MSGBOX_AUTOCLOSE
# 225 "data/maps/MossdeepCity_Gym/scripts.pory"
	end
# 226 "data/maps/MossdeepCity_Gym/scripts.pory"

# 227 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_Hannah::
# 228 "data/maps/MossdeepCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_HANNAH, MossdeepCity_Gym_Text_HannahIntro, MossdeepCity_Gym_Text_HannahDefeat
# 229 "data/maps/MossdeepCity_Gym/scripts.pory"
	msgbox MossdeepCity_Gym_Text_HannahPostBattle, MSGBOX_AUTOCLOSE
# 230 "data/maps/MossdeepCity_Gym/scripts.pory"
	end
# 231 "data/maps/MossdeepCity_Gym/scripts.pory"

# 232 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_Samantha::
# 233 "data/maps/MossdeepCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_SAMANTHA, MossdeepCity_Gym_Text_SamanthaIntro, MossdeepCity_Gym_Text_SamanthaDefeat
# 234 "data/maps/MossdeepCity_Gym/scripts.pory"
	msgbox MossdeepCity_Gym_Text_SamanthaPostBattle, MSGBOX_AUTOCLOSE
# 235 "data/maps/MossdeepCity_Gym/scripts.pory"
	end
# 236 "data/maps/MossdeepCity_Gym/scripts.pory"

# 237 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_Maura::
# 238 "data/maps/MossdeepCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_MAURA, MossdeepCity_Gym_Text_MauraIntro, MossdeepCity_Gym_Text_MauraDefeat
# 239 "data/maps/MossdeepCity_Gym/scripts.pory"
	msgbox MossdeepCity_Gym_Text_MauraPostBattle, MSGBOX_AUTOCLOSE
# 240 "data/maps/MossdeepCity_Gym/scripts.pory"
	end
# 241 "data/maps/MossdeepCity_Gym/scripts.pory"

# 242 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_Sylvia::
# 243 "data/maps/MossdeepCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_SYLVIA, MossdeepCity_Gym_Text_SylviaIntro, MossdeepCity_Gym_Text_SylviaDefeat
# 244 "data/maps/MossdeepCity_Gym/scripts.pory"
	msgbox MossdeepCity_Gym_Text_SylviaPostBattle, MSGBOX_AUTOCLOSE
# 245 "data/maps/MossdeepCity_Gym/scripts.pory"
	end
# 246 "data/maps/MossdeepCity_Gym/scripts.pory"

# 247 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_Nate::
# 248 "data/maps/MossdeepCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_NATE, MossdeepCity_Gym_Text_NateIntro, MossdeepCity_Gym_Text_NateDefeat
# 249 "data/maps/MossdeepCity_Gym/scripts.pory"
	msgbox MossdeepCity_Gym_Text_NatePostBattle, MSGBOX_AUTOCLOSE
# 250 "data/maps/MossdeepCity_Gym/scripts.pory"
	end
# 251 "data/maps/MossdeepCity_Gym/scripts.pory"

# 252 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_Macey::
# 253 "data/maps/MossdeepCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_MACEY, MossdeepCity_Gym_Text_MaceyIntro, MossdeepCity_Gym_Text_MaceyDefeat
# 254 "data/maps/MossdeepCity_Gym/scripts.pory"
	msgbox MossdeepCity_Gym_Text_MaceyPostBattle, MSGBOX_AUTOCLOSE
# 255 "data/maps/MossdeepCity_Gym/scripts.pory"
	end
# 256 "data/maps/MossdeepCity_Gym/scripts.pory"

# 257 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_Clifford::
# 258 "data/maps/MossdeepCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_CLIFFORD, MossdeepCity_Gym_Text_CliffordIntro, MossdeepCity_Gym_Text_CliffordDefeat
# 259 "data/maps/MossdeepCity_Gym/scripts.pory"
	msgbox MossdeepCity_Gym_Text_CliffordPostBattle, MSGBOX_AUTOCLOSE
# 260 "data/maps/MossdeepCity_Gym/scripts.pory"
	end
# 261 "data/maps/MossdeepCity_Gym/scripts.pory"

# 262 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_Nicholas::
# 263 "data/maps/MossdeepCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_NICHOLAS, MossdeepCity_Gym_Text_NicholasIntro, MossdeepCity_Gym_Text_NicholasDefeat
# 264 "data/maps/MossdeepCity_Gym/scripts.pory"
	msgbox MossdeepCity_Gym_Text_NicholasPostBattle, MSGBOX_AUTOCLOSE
# 265 "data/maps/MossdeepCity_Gym/scripts.pory"
	end
# 266 "data/maps/MossdeepCity_Gym/scripts.pory"

# 267 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_Kathleen::
# 268 "data/maps/MossdeepCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_KATHLEEN, MossdeepCity_Gym_Text_KathleenIntro, MossdeepCity_Gym_Text_KathleenDefeat
# 269 "data/maps/MossdeepCity_Gym/scripts.pory"
	msgbox MossdeepCity_Gym_Text_KathleenPostBattle, MSGBOX_AUTOCLOSE
# 270 "data/maps/MossdeepCity_Gym/scripts.pory"
	end
# 271 "data/maps/MossdeepCity_Gym/scripts.pory"

# 272 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_GymGuide::
# 273 "data/maps/MossdeepCity_Gym/scripts.pory"
	lock
# 274 "data/maps/MossdeepCity_Gym/scripts.pory"
	faceplayer
# 275 "data/maps/MossdeepCity_Gym/scripts.pory"
	goto_if_set FLAG_DEFEATED_MOSSDEEP_GYM, MossdeepCity_Gym_EventScript_GymGuidePostVictory
# 276 "data/maps/MossdeepCity_Gym/scripts.pory"
	msgbox MossdeepCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
# 277 "data/maps/MossdeepCity_Gym/scripts.pory"
	release
# 278 "data/maps/MossdeepCity_Gym/scripts.pory"
	end
# 279 "data/maps/MossdeepCity_Gym/scripts.pory"

# 280 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_GymGuidePostVictory::
# 281 "data/maps/MossdeepCity_Gym/scripts.pory"
	msgbox MossdeepCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
# 282 "data/maps/MossdeepCity_Gym/scripts.pory"
	release
# 283 "data/maps/MossdeepCity_Gym/scripts.pory"
	end
# 284 "data/maps/MossdeepCity_Gym/scripts.pory"

# 285 "data/maps/MossdeepCity_Gym/scripts.pory"
@ Leftover from RS, functionally unused
# 286 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Movement_WaitAfterSwitchUse:
# 287 "data/maps/MossdeepCity_Gym/scripts.pory"
	delay_16
# 288 "data/maps/MossdeepCity_Gym/scripts.pory"
	delay_16
# 289 "data/maps/MossdeepCity_Gym/scripts.pory"
	step_end
# 290 "data/maps/MossdeepCity_Gym/scripts.pory"

# 291 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_LeftGymStatue::
# 292 "data/maps/MossdeepCity_Gym/scripts.pory"
	lockall
# 293 "data/maps/MossdeepCity_Gym/scripts.pory"
	goto_if_set FLAG_BADGE07_GET, MossdeepCity_Gym_EventScript_GymStatueCertified
# 294 "data/maps/MossdeepCity_Gym/scripts.pory"
	goto MossdeepCity_Gym_EventScript_GymStatue
# 295 "data/maps/MossdeepCity_Gym/scripts.pory"
	end
# 296 "data/maps/MossdeepCity_Gym/scripts.pory"

# 297 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_RightGymStatue::
# 298 "data/maps/MossdeepCity_Gym/scripts.pory"
	lockall
# 299 "data/maps/MossdeepCity_Gym/scripts.pory"
	goto_if_set FLAG_BADGE07_GET, MossdeepCity_Gym_EventScript_GymStatueCertified
# 300 "data/maps/MossdeepCity_Gym/scripts.pory"
	goto MossdeepCity_Gym_EventScript_GymStatue
# 301 "data/maps/MossdeepCity_Gym/scripts.pory"
	end
# 302 "data/maps/MossdeepCity_Gym/scripts.pory"

# 303 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_GymStatueCertified::
# 304 "data/maps/MossdeepCity_Gym/scripts.pory"
	msgbox MossdeepCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
# 305 "data/maps/MossdeepCity_Gym/scripts.pory"
	releaseall
# 306 "data/maps/MossdeepCity_Gym/scripts.pory"
	end
# 307 "data/maps/MossdeepCity_Gym/scripts.pory"

# 308 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_GymStatue::
# 309 "data/maps/MossdeepCity_Gym/scripts.pory"
	msgbox MossdeepCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
# 310 "data/maps/MossdeepCity_Gym/scripts.pory"
	releaseall
# 311 "data/maps/MossdeepCity_Gym/scripts.pory"
	end
# 312 "data/maps/MossdeepCity_Gym/scripts.pory"

# 313 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_YellowFloorSwitch::
# 314 "data/maps/MossdeepCity_Gym/scripts.pory"
	playse SE_SWITCH
# 315 "data/maps/MossdeepCity_Gym/scripts.pory"
	waitse
# 316 "data/maps/MossdeepCity_Gym/scripts.pory"
	playse SE_REPEL
# 317 "data/maps/MossdeepCity_Gym/scripts.pory"
	initrotatingtilepuzzle FALSE
# 318 "data/maps/MossdeepCity_Gym/scripts.pory"
	moverotatingtileobjects 0
# 319 "data/maps/MossdeepCity_Gym/scripts.pory"
	waitmovement 0
# 320 "data/maps/MossdeepCity_Gym/scripts.pory"
	turnrotatingtileobjects
# 321 "data/maps/MossdeepCity_Gym/scripts.pory"
	waitmovement 0
# 322 "data/maps/MossdeepCity_Gym/scripts.pory"
	freerotatingtilepuzzle
# 323 "data/maps/MossdeepCity_Gym/scripts.pory"
	end
# 324 "data/maps/MossdeepCity_Gym/scripts.pory"

# 325 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_BlueFloorSwitch::
# 326 "data/maps/MossdeepCity_Gym/scripts.pory"
	playse SE_SWITCH
# 327 "data/maps/MossdeepCity_Gym/scripts.pory"
	waitse
# 328 "data/maps/MossdeepCity_Gym/scripts.pory"
	playse SE_REPEL
# 329 "data/maps/MossdeepCity_Gym/scripts.pory"
	initrotatingtilepuzzle FALSE
# 330 "data/maps/MossdeepCity_Gym/scripts.pory"
	moverotatingtileobjects 1
# 331 "data/maps/MossdeepCity_Gym/scripts.pory"
	waitmovement 0
# 332 "data/maps/MossdeepCity_Gym/scripts.pory"
	turnrotatingtileobjects
# 333 "data/maps/MossdeepCity_Gym/scripts.pory"
	waitmovement 0
# 334 "data/maps/MossdeepCity_Gym/scripts.pory"
	freerotatingtilepuzzle
# 335 "data/maps/MossdeepCity_Gym/scripts.pory"
	end
# 336 "data/maps/MossdeepCity_Gym/scripts.pory"

# 337 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_GreenFloorSwitch::
# 338 "data/maps/MossdeepCity_Gym/scripts.pory"
	playse SE_SWITCH
# 339 "data/maps/MossdeepCity_Gym/scripts.pory"
	waitse
# 340 "data/maps/MossdeepCity_Gym/scripts.pory"
	playse SE_REPEL
# 341 "data/maps/MossdeepCity_Gym/scripts.pory"
	initrotatingtilepuzzle FALSE
# 342 "data/maps/MossdeepCity_Gym/scripts.pory"
	moverotatingtileobjects 2
# 343 "data/maps/MossdeepCity_Gym/scripts.pory"
	waitmovement 0
# 344 "data/maps/MossdeepCity_Gym/scripts.pory"
	turnrotatingtileobjects
# 345 "data/maps/MossdeepCity_Gym/scripts.pory"
	waitmovement 0
# 346 "data/maps/MossdeepCity_Gym/scripts.pory"
	freerotatingtilepuzzle
# 347 "data/maps/MossdeepCity_Gym/scripts.pory"
	end
# 348 "data/maps/MossdeepCity_Gym/scripts.pory"

# 349 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_PurpleFloorSwitch::
# 350 "data/maps/MossdeepCity_Gym/scripts.pory"
	playse SE_SWITCH
# 351 "data/maps/MossdeepCity_Gym/scripts.pory"
	waitse
# 352 "data/maps/MossdeepCity_Gym/scripts.pory"
	playse SE_REPEL
# 353 "data/maps/MossdeepCity_Gym/scripts.pory"
	initrotatingtilepuzzle FALSE
# 354 "data/maps/MossdeepCity_Gym/scripts.pory"
	moverotatingtileobjects 3
# 355 "data/maps/MossdeepCity_Gym/scripts.pory"
	waitmovement 0
# 356 "data/maps/MossdeepCity_Gym/scripts.pory"
	turnrotatingtileobjects
# 357 "data/maps/MossdeepCity_Gym/scripts.pory"
	waitmovement 0
# 358 "data/maps/MossdeepCity_Gym/scripts.pory"
	freerotatingtilepuzzle
# 359 "data/maps/MossdeepCity_Gym/scripts.pory"
	end
# 360 "data/maps/MossdeepCity_Gym/scripts.pory"

# 361 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_RedFloorSwitch::
# 362 "data/maps/MossdeepCity_Gym/scripts.pory"
	playse SE_SWITCH
# 363 "data/maps/MossdeepCity_Gym/scripts.pory"
	waitse
# 364 "data/maps/MossdeepCity_Gym/scripts.pory"
	playse SE_REPEL
# 365 "data/maps/MossdeepCity_Gym/scripts.pory"
	initrotatingtilepuzzle FALSE
# 366 "data/maps/MossdeepCity_Gym/scripts.pory"
	moverotatingtileobjects 4
# 367 "data/maps/MossdeepCity_Gym/scripts.pory"
	waitmovement 0
# 368 "data/maps/MossdeepCity_Gym/scripts.pory"
	turnrotatingtileobjects
# 369 "data/maps/MossdeepCity_Gym/scripts.pory"
	waitmovement 0
# 370 "data/maps/MossdeepCity_Gym/scripts.pory"
	freerotatingtilepuzzle
# 371 "data/maps/MossdeepCity_Gym/scripts.pory"
	end
# 372 "data/maps/MossdeepCity_Gym/scripts.pory"

# 373 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_GymGuideAdvice:
# 374 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "Yo, how's it going, CHAMPION-bound\n"
# 375 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "{PLAYER}?\p"
# 376 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "The GYM LEADERS here use\n"
# 377 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "PSYCHIC-type POKéMON.\p"
# 378 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "If you go up against them with\n"
# 379 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "FIGHTING- or POISON-type POKéMON,\l"
# 380 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "they'll inflict horrible damage!\p"
# 381 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "Plus, they'll come at you with\n"
# 382 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "outstanding combination attacks.\p"
# 383 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "If you want to win, you'll need to show\n"
# 384 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "them how tight you are with your\l"
# 385 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "POKéMON. Go for it!$"
# 386 "data/maps/MossdeepCity_Gym/scripts.pory"

# 387 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_GymGuidePostVictory:
# 388 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "Wow, you're astounding!\n"
# 389 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "You're one great TRAINER!$"
# 390 "data/maps/MossdeepCity_Gym/scripts.pory"

# 391 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_PrestonIntro:
# 392 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "Battles hinge on the strength of your\n"
# 393 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "spirit! The weak-spirited will never win!$"
# 394 "data/maps/MossdeepCity_Gym/scripts.pory"

# 395 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_PrestonDefeat:
# 396 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "I lost!\n"
# 397 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "I must temper my spirit again!$"
# 398 "data/maps/MossdeepCity_Gym/scripts.pory"

# 399 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_PrestonPostBattle:
# 400 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "The indecisive lose.\n"
# 401 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "That's my warning to you.$"
# 402 "data/maps/MossdeepCity_Gym/scripts.pory"

# 403 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_VirgilIntro:
# 404 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "Let me see your talent!$"
# 405 "data/maps/MossdeepCity_Gym/scripts.pory"

# 406 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_VirgilDefeat:
# 407 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "You possess spectacular talent!$"
# 408 "data/maps/MossdeepCity_Gym/scripts.pory"

# 409 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_VirgilPostBattle:
# 410 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "If there are prodigies in the world,\n"
# 411 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "then our GYM LEADERS are them!\p"
# 412 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "However, you may be even more talented\n"
# 413 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "than them…$"
# 414 "data/maps/MossdeepCity_Gym/scripts.pory"

# 415 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_BlakeIntro:
# 416 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "Fufufufu… Watch me levitate a POKé\n"
# 417 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "BALL telekinetically!\p"
# 418 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "Wrooooooooaaaar!\n"
# 419 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "… … … … … … …\p"
# 420 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "Sometimes, I'm out of sync…$"
# 421 "data/maps/MossdeepCity_Gym/scripts.pory"

# 422 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_BlakeDefeat:
# 423 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "My POKéMON battling skills are out\n"
# 424 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "of sync, too!$"
# 425 "data/maps/MossdeepCity_Gym/scripts.pory"

# 426 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_BlakePostBattle:
# 427 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "A POKé BALL was too heavy to lift\n"
# 428 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "psychically. But this dust bunny…\p"
# 429 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "Whoooooooooooooooh!\n"
# 430 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "… … … … … …\p"
# 431 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "No, I'm not cheating!\n"
# 432 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "I didn't blow on it! Honestly!$"
# 433 "data/maps/MossdeepCity_Gym/scripts.pory"

# 434 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_HannahIntro:
# 435 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "When you lose to me, don't be too hard\n"
# 436 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "on yourself.\p"
# 437 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "It's not that you're weak--I'm just\n"
# 438 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "too strong!$"
# 439 "data/maps/MossdeepCity_Gym/scripts.pory"

# 440 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_HannahDefeat:
# 441 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "You're just too strong!$"
# 442 "data/maps/MossdeepCity_Gym/scripts.pory"

# 443 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_HannahPostBattle:
# 444 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "I'm not going to get down on myself for\n"
# 445 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "losing. I just need to train harder.\p"
# 446 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "Positive thinking--that's my strong\n"
# 447 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "point!$"
# 448 "data/maps/MossdeepCity_Gym/scripts.pory"

# 449 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_SamanthaIntro:
# 450 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "I see it…\n"
# 451 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "I see your future…\p"
# 452 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "If you can beat me, I will tell you\n"
# 453 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "your future!$"
# 454 "data/maps/MossdeepCity_Gym/scripts.pory"

# 455 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_SamanthaDefeat:
# 456 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "I surrender!$"
# 457 "data/maps/MossdeepCity_Gym/scripts.pory"

# 458 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_SamanthaPostBattle:
# 459 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "You will wage a terrifically intense\n"
# 460 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "battle with our GYM LEADERS…\p"
# 461 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "The result…\n"
# 462 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "You won't hear it from me!$"
# 463 "data/maps/MossdeepCity_Gym/scripts.pory"

# 464 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_MauraIntro:
# 465 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "The roads you have traveled…\n"
# 466 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "What you have experienced…\p"
# 467 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "Come at me with everything you've\n"
# 468 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "learned!$"
# 469 "data/maps/MossdeepCity_Gym/scripts.pory"

# 470 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_MauraDefeat:
# 471 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "You've traveled a path of greatness!$"
# 472 "data/maps/MossdeepCity_Gym/scripts.pory"

# 473 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_MauraPostBattle:
# 474 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "A bright future awaits those who have\n"
# 475 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "worked diligently.\p"
# 476 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "For those who lazed idly, there is\n"
# 477 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "only despair at the end.\p"
# 478 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "What goes around comes around…$"
# 479 "data/maps/MossdeepCity_Gym/scripts.pory"

# 480 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_SylviaIntro:
# 481 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "Even at the risk of life, I will win\n"
# 482 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "this battle!$"
# 483 "data/maps/MossdeepCity_Gym/scripts.pory"

# 484 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_SylviaDefeat:
# 485 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "What you do…\n"
# 486 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "It horrifies me…$"
# 487 "data/maps/MossdeepCity_Gym/scripts.pory"

# 488 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_SylviaPostBattle:
# 489 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "How dare you beat me…\p"
# 490 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "It won't be my fault if something\n"
# 491 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "horrible befalls you…$"
# 492 "data/maps/MossdeepCity_Gym/scripts.pory"

# 493 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_NateIntro:
# 494 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "Hohoho.\p"
# 495 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "You need me to show you how tenacious\n"
# 496 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "the PSYCHIC type can be.$"
# 497 "data/maps/MossdeepCity_Gym/scripts.pory"

# 498 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_NateDefeat:
# 499 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "Oh! My, my!\n"
# 500 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "Your battle style is fantastic!$"
# 501 "data/maps/MossdeepCity_Gym/scripts.pory"

# 502 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_NatePostBattle:
# 503 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "I… I don't let defeat rattle m-me,\n"
# 504 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "however b-badly.$"
# 505 "data/maps/MossdeepCity_Gym/scripts.pory"

# 506 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_KathleenIntro:
# 507 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "Let me show you a perfectly awful,\n"
# 508 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "horrifying time!$"
# 509 "data/maps/MossdeepCity_Gym/scripts.pory"

# 510 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_KathleenDefeat:
# 511 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "N-nooooo!$"
# 512 "data/maps/MossdeepCity_Gym/scripts.pory"

# 513 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_KathleenPostBattle:
# 514 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "Your vitality is contagious!\n"
# 515 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "Get away from me quickly!$"
# 516 "data/maps/MossdeepCity_Gym/scripts.pory"

# 517 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_CliffordIntro:
# 518 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "I may be past my prime, but I suggest\n"
# 519 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "you not patronize me.$"
# 520 "data/maps/MossdeepCity_Gym/scripts.pory"

# 521 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_CliffordDefeat:
# 522 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "Ah, you overflow with the power\n"
# 523 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "of youth!$"
# 524 "data/maps/MossdeepCity_Gym/scripts.pory"

# 525 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_CliffordPostBattle:
# 526 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "It seems that I could not overcome\n"
# 527 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "your youthful energy.$"
# 528 "data/maps/MossdeepCity_Gym/scripts.pory"

# 529 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_MaceyIntro:
# 530 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "You're not getting through to the end!\n"
# 531 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "Not if I can help it!$"
# 532 "data/maps/MossdeepCity_Gym/scripts.pory"

# 533 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_MaceyDefeat:
# 534 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "How could you be so ludicrously\n"
# 535 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "strong?$"
# 536 "data/maps/MossdeepCity_Gym/scripts.pory"

# 537 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_MaceyPostBattle:
# 538 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "Humph! You may be strong, but you're\n"
# 539 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "not suitable for the PSYCHIC type!\p"
# 540 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "The way you battle is somehow brutal!$"
# 541 "data/maps/MossdeepCity_Gym/scripts.pory"

# 542 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_NicholasIntro:
# 543 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "Wroooar! Have a taste of my super\n"
# 544 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "POKéMON hard-battling power!$"
# 545 "data/maps/MossdeepCity_Gym/scripts.pory"

# 546 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_NicholasDefeat:
# 547 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "Oh!\n"
# 548 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "Done in!$"
# 549 "data/maps/MossdeepCity_Gym/scripts.pory"

# 550 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_NicholasPostBattle:
# 551 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "All right! I think I'll develop a special\n"
# 552 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "invincible POKéMON power next.$"
# 553 "data/maps/MossdeepCity_Gym/scripts.pory"

# 554 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_TateAndLizaIntro:
# 555 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "TATE: Hehehe… Were you surprised?\p"
# 556 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "LIZA: Fufufu… Were you surprised?\p"
# 557 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "TATE: That there are two GYM LEADERS?\n"
# 558 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "LIZA: That there are two GYM LEADERS?\p"
# 559 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "TATE: We're twins!\n"
# 560 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "LIZA: We're twins!\p"
# 561 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "TATE: We don't need to talk because…\n"
# 562 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "LIZA: We can each determine what…\p"
# 563 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "TATE: The other is thinking…\n"
# 564 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "LIZA: All in our minds!\p"
# 565 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "TATE: This combination of ours…\n"
# 566 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "LIZA: Can you beat it?$"
# 567 "data/maps/MossdeepCity_Gym/scripts.pory"

# 568 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_TateAndLizaDefeat:
# 569 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "TATE: What?! Our combination…\n"
# 570 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "LIZA: Was shattered!\p"
# 571 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "TATE: It can't be helped. You've won…\n"
# 572 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "LIZA: So, in recognition, take this.$"
# 573 "data/maps/MossdeepCity_Gym/scripts.pory"

# 574 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_ReceivedMindBadge:
# 575 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "{PLAYER} received the MIND BADGE\n"
# 576 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "from TATE and LIZA.$"
# 577 "data/maps/MossdeepCity_Gym/scripts.pory"

# 578 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_ExplainMindBadgeTakeThis:
# 579 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "TATE: The MIND BADGE enhances the\n"
# 580 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "SP. ATK and SP. DEF of POKéMON.\p"
# 581 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "LIZA: It also lets you use the HM move\n"
# 582 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "DIVE outside of battle.\p"
# 583 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "TATE: You should also take this, too.$"
# 584 "data/maps/MossdeepCity_Gym/scripts.pory"

# 585 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_ExplainCalmMind:
# 586 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "TATE: That TM04 contains…\n"
# 587 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "LIZA: CALM MIND!\p"
# 588 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "TATE: It raises SP. ATK and…\n"
# 589 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "LIZA: It raises SP. DEF!\p"
# 590 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "TATE: It's a move that's perfect…\n"
# 591 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "LIZA: For PSYCHIC POKéMON!\p"
# 592 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "… … … … … …$"
# 593 "data/maps/MossdeepCity_Gym/scripts.pory"

# 594 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_RegisteredTateAndLiza:
# 595 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "Registered GYM LEADERS TATE & LIZA\n"
# 596 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "in the POKéNAV.$"
# 597 "data/maps/MossdeepCity_Gym/scripts.pory"

# 598 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_TateAndLizaPostBattle:
# 599 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "TATE: Looks like the bond between you\n"
# 600 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "and your POKéMON is far stronger than\l"
# 601 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "the bond that we share as twins.\p"
# 602 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "LIZA: You will become even stronger!\n"
# 603 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "We've battled you, so we know.$"
# 604 "data/maps/MossdeepCity_Gym/scripts.pory"

# 605 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_TateAndLizaNeedTwoMons:
# 606 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "TATE: Hehehe… Were you surprised?\p"
# 607 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "LIZA: That there are two GYM LEADERS?\p"
# 608 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "TATE: Oops, you have only one…\n"
# 609 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "LIZA: POKéMON that can battle.\p"
# 610 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "TATE: We can't battle that way!\p"
# 611 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "LIZA: If you want to challenge us,\n"
# 612 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "bring some more POKéMON.$"
# 613 "data/maps/MossdeepCity_Gym/scripts.pory"

# 614 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_GymStatue:
# 615 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "MOSSDEEP CITY POKéMON GYM$"
# 616 "data/maps/MossdeepCity_Gym/scripts.pory"

# 617 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_GymStatueCertified:
# 618 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "MOSSDEEP CITY POKéMON GYM\p"
# 619 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "LIZA AND TATE'S CERTIFIED TRAINERS:\n"
# 620 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "{PLAYER}$"
# 621 "data/maps/MossdeepCity_Gym/scripts.pory"

# 622 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_TateAndLizaPreRematch:
# 623 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "TATE: POKéMON…\n"
# 624 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "LIZA: POKéMON…\p"
# 625 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "TATE: By changing the party's mix…\n"
# 626 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "LIZA: The battle style changes.\p"
# 627 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "TATE: But me…\n"
# 628 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "LIZA: But me…\p"
# 629 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "TATE: I'll always be with LIZA!\n"
# 630 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "LIZA: I'll always be with TATE!\p"
# 631 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "TATE: Our combination…\n"
# 632 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "LIZA: We'll show you again and again!$"
# 633 "data/maps/MossdeepCity_Gym/scripts.pory"

# 634 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_TateAndLizaRematchDefeat:
# 635 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "TATE: You and your POKéMON…\n"
# 636 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "LIZA: It's as if you were siblings!$"
# 637 "data/maps/MossdeepCity_Gym/scripts.pory"

# 638 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_TateAndLizaPostRematch:
# 639 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "TATE: You can knock us down,\n"
# 640 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "but we'll never stay down!\p"
# 641 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "LIZA: Because the two of us,\n"
# 642 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "we always support each other!$"
# 643 "data/maps/MossdeepCity_Gym/scripts.pory"

# 644 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_TateAndLizaRematchNeedTwoMons:
# 645 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "TATE: You're back again…\n"
# 646 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "LIZA: You're back again…\p"
# 647 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "TATE: To give us a rematch.\n"
# 648 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "LIZA: To give us a rematch.\p"
# 649 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "TATE: But…\n"
# 650 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "LIZA: For our match…\p"
# 651 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "TATE: You brought just one POKéMON!\n"
# 652 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "LIZA: You brought just one POKéMON!\p"
# 653 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "TATE: We need you to bring at least…\n"
# 654 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "LIZA: Two POKéMON when you come back.$"
