# 1 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 2 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
.set LOCALID_RICH_BOY, 1
# 3 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
.set LOCALID_GENTLEMAN, 2
# 4 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
.set LOCALID_SCIENTIST, 3
# 5 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
.set LOCALID_STEVEN, 4
# 6 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
@ Grunt names numbered like their Trainer values (which are for the full Space Center)
# 7 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
.set LOCALID_GRUNT_6, 5
# 8 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
.set LOCALID_GRUNT_5, 6
# 9 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
.set LOCALID_GRUNT_7, 7
# 10 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
.set LOCALID_TABITHA, 8
# 11 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
.set LOCALID_MAXIE, 9
# 12 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 13 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_MapScripts::
# 14 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, MossdeepCity_SpaceCenter_2F_OnTransition
# 15 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MossdeepCity_SpaceCenter_2F_OnFrame
# 16 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.byte 0
# 17 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 18 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_OnTransition:
# 19 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	call_if_eq VAR_MOSSDEEP_CITY_STATE, 2, MossdeepCity_SpaceCenter_2F_EventScript_MoveCivilians
# 20 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	call_if_eq VAR_MOSSDEEP_SPACE_CENTER_STATE, 2, MossdeepCity_SpaceCenter_2F_EventScript_MoveDefeatedGrunts
# 21 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	end
# 22 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 23 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_EventScript_MoveCivilians::
# 24 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	clearflag FLAG_INTERACTED_WITH_STEVEN_SPACE_CENTER
# 25 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	setobjectxyperm LOCALID_SCIENTIST, 5, 3
# 26 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	setobjectmovementtype LOCALID_SCIENTIST, MOVEMENT_TYPE_FACE_RIGHT
# 27 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	setobjectxyperm LOCALID_RICH_BOY, 3, 2
# 28 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	setobjectmovementtype LOCALID_RICH_BOY, MOVEMENT_TYPE_FACE_RIGHT
# 29 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	setobjectxyperm LOCALID_GENTLEMAN, 1, 3
# 30 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	setobjectmovementtype LOCALID_GENTLEMAN, MOVEMENT_TYPE_FACE_RIGHT
# 31 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	return
# 32 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 33 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_EventScript_MoveDefeatedGrunts::
# 34 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	setobjectxyperm LOCALID_GRUNT_6, 11, 2
# 35 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	setobjectxyperm LOCALID_GRUNT_7, 15, 2
# 36 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	setobjectxyperm LOCALID_GRUNT_5, 13, 4
# 37 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	return
# 38 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 39 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_OnFrame:
# 40 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	map_script_2 VAR_MOSSDEEP_SPACE_CENTER_STATE, 1, MossdeepCity_SpaceCenter_2F_EventScript_ThreeMagmaGrunts
# 41 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.2byte 0
# 42 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 43 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_EventScript_ThreeMagmaGrunts::
# 44 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	playse SE_PIN
# 45 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
# 46 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	waitmovement 0
# 47 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
# 48 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	waitmovement 0
# 49 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	msgbox MossdeepCity_SpaceCenter_2F_Text_YoureOutnumberedTakeUsOn, MSGBOX_YESNO
# 50 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	goto_if_eq VAR_RESULT, YES, MossdeepCity_SpaceCenter_2F_EventScript_BattleThreeMagmaGrunts
# 51 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	msgbox MossdeepCity_SpaceCenter_2F_Text_GoodAnswer, MSGBOX_DEFAULT
# 52 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	closemessage
# 53 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_SpaceCenter_2F_Movement_PlayerExit
# 54 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	waitmovement 0
# 55 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	warp MAP_MOSSDEEP_CITY_SPACE_CENTER_1F, 13, 1
# 56 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	waitstate
# 57 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	releaseall
# 58 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	end
# 59 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 60 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_Movement_PlayerExit:
# 61 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	walk_up
# 62 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	step_end
# 63 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 64 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_EventScript_BattleThreeMagmaGrunts::
# 65 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	msgbox MossdeepCity_SpaceCenter_2F_Text_Grunt5Intro, MSGBOX_DEFAULT
# 66 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	trainerbattle_no_intro TRAINER_GRUNT_SPACE_CENTER_5, MossdeepCity_SpaceCenter_2F_Text_Grunt5Defeat
# 67 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	applymovement LOCALID_GRUNT_5, MossdeepCity_SpaceCenter_2F_Movement_Grunt5Defeated
# 68 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	waitmovement 0
# 69 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 70 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	waitmovement 0
# 71 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	msgbox MossdeepCity_SpaceCenter_2F_Text_Grunt6Intro, MSGBOX_DEFAULT
# 72 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	trainerbattle_no_intro TRAINER_GRUNT_SPACE_CENTER_6, MossdeepCity_SpaceCenter_2F_Text_Grunt6Defeat
# 73 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	applymovement LOCALID_GRUNT_6, MossdeepCity_SpaceCenter_2F_Movement_Grunt6Defeated
# 74 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	waitmovement 0
# 75 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 76 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	waitmovement 0
# 77 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	msgbox MossdeepCity_SpaceCenter_2F_Text_Grunt7Intro, MSGBOX_DEFAULT
# 78 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	trainerbattle_no_intro TRAINER_GRUNT_SPACE_CENTER_7, MossdeepCity_SpaceCenter_2F_Text_Grunt7Defeat
# 79 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	applymovement LOCALID_GRUNT_7, MossdeepCity_SpaceCenter_2F_Movement_Grunt7Defeated
# 80 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	waitmovement 0
# 81 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	setvar VAR_MOSSDEEP_SPACE_CENTER_STATE, 2
# 82 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	copyobjectxytoperm LOCALID_GRUNT_6
# 83 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	copyobjectxytoperm LOCALID_GRUNT_7
# 84 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	copyobjectxytoperm LOCALID_GRUNT_5
# 85 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	releaseall
# 86 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	end
# 87 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 88 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_Movement_Grunt6Defeated:
# 89 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	lock_facing_direction
# 90 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	walk_left
# 91 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	unlock_facing_direction
# 92 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	step_end
# 93 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 94 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_Movement_Grunt5Defeated:
# 95 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	lock_facing_direction
# 96 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	walk_down
# 97 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	unlock_facing_direction
# 98 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	step_end
# 99 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 100 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_Movement_Grunt7Defeated:
# 101 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	lock_facing_direction
# 102 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	walk_right
# 103 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	unlock_facing_direction
# 104 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	step_end
# 105 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 106 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_EventScript_Scientist::
# 107 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	lock
# 108 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	faceplayer
# 109 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, MossdeepCity_SpaceCenter_2F_EventScript_ScientistNormal
# 110 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	goto_if_eq VAR_MOSSDEEP_CITY_STATE, 2, MossdeepCity_SpaceCenter_2F_EventScript_ScientistMagma
# 111 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	goto_if_lt VAR_MOSSDEEP_CITY_STATE, 2, MossdeepCity_SpaceCenter_2F_EventScript_ScientistNormal
# 112 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	goto MossdeepCity_SpaceCenter_2F_EventScript_ScientistMagma
# 113 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	end
# 114 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 115 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_EventScript_ScientistNormal::
# 116 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	msgbox MossdeepCity_SpaceCenter_2F_Text_MossdeepIdealForRockets, MSGBOX_DEFAULT
# 117 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	release
# 118 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	end
# 119 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 120 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_EventScript_ScientistMagma::
# 121 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	msgbox MossdeepCity_SpaceCenter_2F_Text_WhyWouldMagmaStealRocketFuel, MSGBOX_DEFAULT
# 122 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	release
# 123 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	end
# 124 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 125 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_EventScript_Gentleman::
# 126 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	lock
# 127 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	faceplayer
# 128 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, MossdeepCity_SpaceCenter_2F_EventScript_GentlemanNormal
# 129 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	goto_if_eq VAR_MOSSDEEP_CITY_STATE, 2, MossdeepCity_SpaceCenter_2F_EventScript_GentlemanMagma
# 130 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	goto_if_lt VAR_MOSSDEEP_CITY_STATE, 2, MossdeepCity_SpaceCenter_2F_EventScript_GentlemanNormal
# 131 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	goto MossdeepCity_SpaceCenter_2F_EventScript_GentlemanMagma
# 132 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	end
# 133 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 134 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_EventScript_GentlemanNormal::
# 135 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	msgbox MossdeepCity_SpaceCenter_2F_Text_WouldveLikedToBeAstronaut, MSGBOX_DEFAULT
# 136 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	release
# 137 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	end
# 138 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 139 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_EventScript_GentlemanMagma::
# 140 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	msgbox MossdeepCity_SpaceCenter_2F_Text_MagmaCantGetAwayWithThis, MSGBOX_DEFAULT
# 141 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	release
# 142 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	end
# 143 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 144 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_EventScript_RichBoy::
# 145 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	lock
# 146 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	faceplayer
# 147 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, MossdeepCity_SpaceCenter_2F_EventScript_RichBoyNormal
# 148 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	goto_if_eq VAR_MOSSDEEP_CITY_STATE, 2, MossdeepCity_SpaceCenter_2F_EventScript_RichBoyMagma
# 149 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	goto_if_lt VAR_MOSSDEEP_CITY_STATE, 2, MossdeepCity_SpaceCenter_2F_EventScript_RichBoyNormal
# 150 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	goto MossdeepCity_SpaceCenter_2F_EventScript_RichBoyMagma
# 151 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	end
# 152 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 153 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_EventScript_RichBoyNormal::
# 154 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	msgbox MossdeepCity_SpaceCenter_2F_Text_WishOrdinaryPeopleCouldGoIntoSpace, MSGBOX_DEFAULT
# 155 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	release
# 156 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	end
# 157 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 158 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_EventScript_RichBoyMagma::
# 159 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	msgbox MossdeepCity_SpaceCenter_2F_Text_DoesMagmaWantToGoToSpace, MSGBOX_DEFAULT
# 160 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	release
# 161 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	end
# 162 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 163 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
@ Battle for the below 3 grunts is handled in MossdeepCity_SpaceCenter_2F_EventScript_BattleThreeMagmaGrunts
# 164 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_EventScript_Grunt6::
# 165 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	msgbox MossdeepCity_SpaceCenter_2F_Text_Grunt6PostBattle, MSGBOX_NPC
# 166 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	end
# 167 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 168 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_EventScript_Grunt7::
# 169 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	msgbox MossdeepCity_SpaceCenter_2F_Text_Grunt7PostBattle, MSGBOX_NPC
# 170 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	end
# 171 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 172 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_EventScript_Grunt5::
# 173 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	msgbox MossdeepCity_SpaceCenter_2F_Text_Grunt5PostBattle, MSGBOX_NPC
# 174 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	end
# 175 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 176 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_EventScript_Tabitha::
# 177 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	lock
# 178 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	faceplayer
# 179 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	msgbox MossdeepCity_SpaceCenter_2F_Text_WellTakeCareOfYou, MSGBOX_DEFAULT
# 180 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 181 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	waitmovement 0
# 182 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	release
# 183 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	end
# 184 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 185 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_EventScript_Maxie::
# 186 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	lockall
# 187 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	msgbox MossdeepCity_SpaceCenter_2F_Text_MaxieDontInterfere, MSGBOX_DEFAULT
# 188 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	releaseall
# 189 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	end
# 190 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 191 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_EventScript_Steven::
# 192 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	lockall
# 193 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	goto_if_set FLAG_INTERACTED_WITH_STEVEN_SPACE_CENTER, MossdeepCity_SpaceCenter_2F_EventScript_ReadyForBattlePrompt
# 194 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	setflag FLAG_INTERACTED_WITH_STEVEN_SPACE_CENTER
# 195 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	msgbox MossdeepCity_SpaceCenter_2F_Text_StevenWhyStealRocketFuel, MSGBOX_DEFAULT
# 196 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	msgbox MossdeepCity_SpaceCenter_2F_Text_MaxieUseFuelToEruptVolcano, MSGBOX_DEFAULT
# 197 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	closemessage
# 198 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	delay 30
# 199 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	playse SE_NOT_EFFECTIVE
# 200 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	switch VAR_FACING
# 201 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	case DIR_SOUTH, MossdeepCity_SpaceCenter_2F_EventScript_StevenFightMovementSouth
# 202 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	applymovement LOCALID_STEVEN, MossdeepCity_SpaceCenter_2F_Movement_StevenFight
# 203 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	waitmovement 0
# 204 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	releaseall
# 205 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	end
# 206 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 207 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_EventScript_StevenFightMovementSouth::
# 208 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	applymovement LOCALID_STEVEN, MossdeepCity_SpaceCenter_2F_Movement_StevenFightSouth
# 209 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	waitmovement 0
# 210 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	releaseall
# 211 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	end
# 212 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 213 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_Movement_StevenFight:
# 214 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	lock_facing_direction
# 215 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	walk_fast_up
# 216 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	walk_fast_up
# 217 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	unlock_facing_direction
# 218 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	delay_16
# 219 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	delay_16
# 220 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	walk_slow_down
# 221 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	walk_slow_down
# 222 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	step_end
# 223 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 224 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_Movement_StevenFightSouth:
# 225 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	face_left
# 226 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	lock_facing_direction
# 227 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	walk_fast_right
# 228 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	walk_fast_right
# 229 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	unlock_facing_direction
# 230 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	delay_16
# 231 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	delay_16
# 232 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	walk_slow_left
# 233 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	walk_slow_left
# 234 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	face_down
# 235 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	step_end
# 236 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 237 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_EventScript_ReadyForBattlePrompt::
# 238 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
# 239 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	waitmovement 0
# 240 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	msgbox MossdeepCity_SpaceCenter_2F_Text_StevenAreYouReadyToBattle, MSGBOX_YESNO
# 241 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	goto_if_eq VAR_RESULT, YES, MossdeepCity_SpaceCenter_2F_EventScript_ChoosePartyForMultiBattle
# 242 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	msgbox MossdeepCity_SpaceCenter_2F_Text_StevenHurryGetReadyQuickly, MSGBOX_DEFAULT
# 243 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	closemessage
# 244 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
# 245 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	waitmovement 0
# 246 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	releaseall
# 247 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	end
# 248 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 249 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_EventScript_ChoosePartyForMultiBattle::
# 250 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
# 251 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	waitmovement 0
# 252 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	special SavePlayerParty
# 253 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	fadescreen FADE_TO_BLACK
# 254 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	special ChooseHalfPartyForBattle
# 255 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	waitstate
# 256 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	goto_if_ne VAR_RESULT, 0, MossdeepCity_SpaceCenter_2F_EventScript_DoStevenMultiBattle
# 257 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	special LoadPlayerParty
# 258 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	goto MossdeepCity_SpaceCenter_2F_EventScript_ReadyForBattlePrompt
# 259 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 260 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_EventScript_DoStevenMultiBattle::
# 261 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	multi_2_vs_2 TRAINER_MAXIE_MOSSDEEP, MossdeepCity_SpaceCenter_2F_Text_JustWantToExpandLand, TRAINER_TABITHA_MOSSDEEP, MossdeepCity_SpaceCenter_Text_TabithaDefeat, PARTNER_STEVEN
# 262 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	switch VAR_RESULT
# 263 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	case 1, MossdeepCity_SpaceCenter_2F_EventScript_DefeatedMaxieTabitha
# 264 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	fadescreen FADE_TO_BLACK
# 265 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	special SetCB2WhiteOut
# 266 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	waitstate
# 267 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 268 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_EventScript_DefeatedMaxieTabitha::
# 269 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	msgbox MossdeepCity_SpaceCenter_2F_Text_MaxieWeFailedIsAquaAlsoMisguided, MSGBOX_DEFAULT
# 270 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	closemessage
# 271 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	delay 20
# 272 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	applymovement LOCALID_MAXIE, Common_Movement_WalkInPlaceFasterLeft
# 273 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	applymovement LOCALID_TABITHA, Common_Movement_WalkInPlaceFasterDown
# 274 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	waitmovement 0
# 275 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	delay 60
# 276 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	applymovement LOCALID_MAXIE, Common_Movement_WalkInPlaceFasterUp
# 277 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	applymovement LOCALID_TABITHA, Common_Movement_WalkInPlaceFasterRight
# 278 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	waitmovement 0
# 279 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	delay 20
# 280 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	msgbox MossdeepCity_SpaceCenter_2F_Text_MaxieWeWillGiveUp, MSGBOX_DEFAULT
# 281 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	closemessage
# 282 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	setvar VAR_MOSSDEEP_CITY_STATE, 3
# 283 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	fadedefaultbgm
# 284 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	fadescreen FADE_TO_BLACK
# 285 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	setvar VAR_MOSSDEEP_SPACE_CENTER_STATE, 3
# 286 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	setflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_1F_TEAM_MAGMA
# 287 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	setflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_2F_TEAM_MAGMA
# 288 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	setflag FLAG_HIDE_MOSSDEEP_CITY_TEAM_MAGMA
# 289 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	removeobject LOCALID_GRUNT_6
# 290 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	removeobject LOCALID_GRUNT_7
# 291 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	removeobject LOCALID_GRUNT_5
# 292 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	removeobject LOCALID_TABITHA
# 293 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	removeobject LOCALID_MAXIE
# 294 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	setobjectxy LOCALID_SCIENTIST, 5, 6
# 295 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	turnobject LOCALID_SCIENTIST, DIR_SOUTH
# 296 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	setobjectxy LOCALID_GENTLEMAN, 11, 8
# 297 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	turnobject LOCALID_GENTLEMAN, DIR_NORTH
# 298 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	setobjectxy LOCALID_RICH_BOY, 6, 2
# 299 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	turnobject LOCALID_RICH_BOY, DIR_NORTH
# 300 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	call MossdeepCity_SpaceCenter_2F_EventScript_StevenFacePlayer
# 301 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 302 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	msgbox MossdeepCity_SpaceCenter_2F_Text_StevenThankYouComeSeeMeAtHome, MSGBOX_DEFAULT
# 303 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	closemessage
# 304 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	fadescreen FADE_TO_BLACK
# 305 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	setflag FLAG_DEFEATED_MAGMA_SPACE_CENTER
# 306 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	setflag FLAG_HIDE_MOSSDEEP_CITY_STEVENS_HOUSE_STEVEN
# 307 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	removeobject LOCALID_STEVEN
# 308 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	setflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_MAGMA_NOTE
# 309 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	clearflag FLAG_HIDE_MOSSDEEP_CITY_STEVENS_HOUSE_STEVEN
# 310 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	setvar VAR_STEVENS_HOUSE_STATE, 1
# 311 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	setflag FLAG_HIDE_MOSSDEEP_CITY_SCOTT
# 312 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	removeobject LOCALID_SCIENTIST
# 313 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	setobjectxyperm LOCALID_SCIENTIST, 5, 6
# 314 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	setobjectmovementtype LOCALID_SCIENTIST, MOVEMENT_TYPE_WANDER_AROUND
# 315 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	addobject LOCALID_SCIENTIST
# 316 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 317 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
#ifdef BUGFIX
# 318 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	releaseall
# 319 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
#endif
# 320 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	end
# 321 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 322 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_EventScript_StevenFacePlayer::
# 323 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	switch VAR_FACING
# 324 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	case DIR_SOUTH, MossdeepCity_SpaceCenter_2F_EventScript_StevenFacePlayerSouth
# 325 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	case DIR_WEST, MossdeepCity_SpaceCenter_2F_EventScript_StevenFacePlayerWest
# 326 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	return
# 327 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 328 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_EventScript_StevenFacePlayerSouth::
# 329 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	turnobject LOCALID_STEVEN, DIR_NORTH
# 330 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	return
# 331 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 332 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_EventScript_StevenFacePlayerWest::
# 333 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	turnobject LOCALID_STEVEN, DIR_EAST
# 334 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	return
# 335 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 336 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_EventScript_RivalRayquazaCall::
# 337 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	lockall
# 338 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	checkplayergender
# 339 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	call_if_eq VAR_RESULT, MALE, MossdeepCity_SpaceCenter_2F_EventScript_MayRayquazaCall
# 340 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, MossdeepCity_SpaceCenter_2F_EventScript_BrendanRayquazaCall
# 341 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	closemessage
# 342 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	clearflag FLAG_DEFEATED_MAGMA_SPACE_CENTER
# 343 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	releaseall
# 344 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	end
# 345 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 346 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_EventScript_MayRayquazaCall::
# 347 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	pokenavcall MatchCall_Text_MayRayquazaCall
# 348 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	waitmessage
# 349 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	return
# 350 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 351 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_EventScript_BrendanRayquazaCall::
# 352 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	pokenavcall MatchCall_Text_BrendanRayquazaCall
# 353 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	waitmessage
# 354 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	return
# 355 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 356 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_Text_MossdeepIdealForRockets:
# 357 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "MOSSDEEP has mainly sunny weather,\n"
# 358 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "and its winds are stable.\p"
# 359 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "It's an ideal location for launching\n"
# 360 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "rockets.$"
# 361 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 362 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_Text_WhyWouldMagmaStealRocketFuel:
# 363 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "Why would TEAM MAGMA want to steal\n"
# 364 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "our rocket fuel in the first place?$"
# 365 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 366 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_Text_WouldveLikedToBeAstronaut:
# 367 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "If only I was a little younger, I would\n"
# 368 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "have liked being an astronaut…\p"
# 369 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "No… It's not too late!\n"
# 370 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "I can and will try!$"
# 371 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 372 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_Text_MagmaCantGetAwayWithThis:
# 373 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "If TEAM MAGMA takes the rocket fuel,\n"
# 374 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "I won't be able to go to space!\p"
# 375 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "They can't be allowed to get away\n"
# 376 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "with such an outrage!$"
# 377 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 378 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_Text_WishOrdinaryPeopleCouldGoIntoSpace:
# 379 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "I wish ordinary people could go into\n"
# 380 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "space one day…$"
# 381 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 382 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_Text_DoesMagmaWantToGoToSpace:
# 383 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "TEAM MAGMA…\n"
# 384 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "Do they want to go to space, too?$"
# 385 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 386 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_Text_YoureOutnumberedTakeUsOn:
# 387 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "What's wrong with you?\p"
# 388 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "You're outnumbered three to one,\n"
# 389 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "but you still want to take us on?$"
# 390 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 391 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_Text_GoodAnswer:
# 392 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "Good answer!\n"
# 393 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "That's what a smart person'll do!$"
# 394 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 395 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_Text_Grunt5Intro:
# 396 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "A reckless go-getter, are you?\n"
# 397 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "Okay, I'll go first!$"
# 398 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 399 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_Text_Grunt5Defeat:
# 400 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "I lost!\n"
# 401 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "But!$"
# 402 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 403 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_Text_Grunt6Intro:
# 404 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "It's too soon to be relieved!\n"
# 405 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "I'm up next!$"
# 406 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 407 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_Text_Grunt6Defeat:
# 408 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "I lost, too!\n"
# 409 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "But!$"
# 410 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 411 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_Text_Grunt7Intro:
# 412 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "I bet you want to take a break.\n"
# 413 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "But I'm not about to let you do that!$"
# 414 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 415 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_Text_Grunt7Defeat:
# 416 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "We should've taken a break…\n"
# 417 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "That's what we should've done…$"
# 418 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 419 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_Text_Grunt6PostBattle:
# 420 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "Three of us here, and look at the sorry\n"
# 421 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "mess we got ourselves into.$"
# 422 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 423 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_Text_Grunt7PostBattle:
# 424 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "We three losing like this…\n"
# 425 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "We look worse than usual by triple!$"
# 426 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 427 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_Text_Grunt5PostBattle:
# 428 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "Are we being useful to our leader\n"
# 429 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "at all?$"
# 430 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 431 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_Text_WellTakeCareOfYou:
# 432 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "Hehehe!\p"
# 433 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "We come all the way here to get some\n"
# 434 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "fuel, and we're interfered with again!\p"
# 435 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "If you're going to mess with us too,\n"
# 436 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "we'll take care of you at the same time!$"
# 437 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 438 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_Text_MaxieDontInterfere:
# 439 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "MAXIE: Clear out of the way!\n"
# 440 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "Don't you dare interfere!$"
# 441 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 442 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_Text_StevenWhyStealRocketFuel:
# 443 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "STEVEN: TEAM MAGMA…\p"
# 444 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "What's the point of stealing rocket\n"
# 445 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "fuel?$"
# 446 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 447 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_Text_MaxieUseFuelToEruptVolcano:
# 448 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "MAXIE: Fufufu… Since you're so\n"
# 449 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "curious, you deserve an explanation.\p"
# 450 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "We're going to jettison the entire\n"
# 451 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "load into MT. CHIMNEY!\p"
# 452 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "With GROUDON gone, we have no need\n"
# 453 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "for that slag heap of a mountain!\p"
# 454 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "So we'll use the fuel's power to make\n"
# 455 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "the volcano erupt!\p"
# 456 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "It will be savage!$"
# 457 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 458 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_Text_StevenAreYouReadyToBattle:
# 459 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "STEVEN: {PLAYER}{KUN}!\n"
# 460 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "You're going to help me?\p"
# 461 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "Let's go into battle together!\n"
# 462 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "Are you ready?$"
# 463 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 464 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_Text_StevenHurryGetReadyQuickly:
# 465 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "STEVEN: Then, hurry!\n"
# 466 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "Get ready quickly!$"
# 467 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 468 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_Text_JustWantToExpandLand:
# 469 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "All I want…\n"
# 470 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "I just want to expand the land mass…$"
# 471 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 472 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_Text_TabithaDefeat:
# 473 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "I'm with our leader…$"
# 474 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 475 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_Text_MaxieWeFailedIsAquaAlsoMisguided:
# 476 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "MAXIE: We failed to make the volcano\n"
# 477 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "erupt…\p"
# 478 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "We failed to control GROUDON after\n"
# 479 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "we had awoken it…\p"
# 480 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "Is our goal to expand the land\n"
# 481 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "misguided?\p"
# 482 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "… … … … … …\n"
# 483 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "… … … … … …\p"
# 484 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "If…\n"
# 485 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "If we, TEAM MAGMA, are wrong…\l"
# 486 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "… … … … … …\p"
# 487 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "Then might TEAM AQUA's goal to expand\n"
# 488 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "the sea also be equally misguided?$"
# 489 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 490 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_Text_MaxieWeWillGiveUp:
# 491 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "MAXIE: All right…\n"
# 492 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "We will give up on the fuel…\p"
# 493 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "There appear to be more important\n"
# 494 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "matters that I must examine…$"
# 495 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 496 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_Text_StevenThankYouComeSeeMeAtHome:
# 497 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "STEVEN: Whew, that was too tense.\n"
# 498 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "{PLAYER}{KUN}, thank you.\p"
# 499 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "I have something to give you as\n"
# 500 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "thanks for your support.\p"
# 501 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "Please come see me at home\n"
# 502 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "after this.\p"
# 503 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "Oh, yes, I don't live in RUSTBORO CITY.\n"
# 504 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "I live right here on this island.$"
