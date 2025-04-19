# 1 "data/maps/MeteorFalls_1F_1R/scripts.pory"

# 2 "data/maps/MeteorFalls_1F_1R/scripts.pory"
.set LOCALID_MAGMA_GRUNT_1, 5
# 3 "data/maps/MeteorFalls_1F_1R/scripts.pory"
.set LOCALID_MAGMA_GRUNT_2, 6
# 4 "data/maps/MeteorFalls_1F_1R/scripts.pory"
.set LOCALID_ARCHIE, 7
# 5 "data/maps/MeteorFalls_1F_1R/scripts.pory"
.set LOCALID_AQUA_GRUNT_1, 8
# 6 "data/maps/MeteorFalls_1F_1R/scripts.pory"
.set LOCALID_AQUA_GRUNT_2, 9
# 7 "data/maps/MeteorFalls_1F_1R/scripts.pory"

# 8 "data/maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_MapScripts::
# 9 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, MeteorFalls_1F_1R_OnLoad
# 10 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.byte 0
# 11 "data/maps/MeteorFalls_1F_1R/scripts.pory"

# 12 "data/maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_OnLoad:
# 13 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	call_if_set FLAG_SYS_GAME_CLEAR, MeteorFalls_1F_1R_EventScript_OpenStevensCave
# 14 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	end
# 15 "data/maps/MeteorFalls_1F_1R/scripts.pory"

# 16 "data/maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_EventScript_OpenStevensCave::
# 17 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	setmetatile 4, 1, METATILE_MeteorFalls_CaveEntrance_Top, TRUE
# 18 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	setmetatile 3, 2, METATILE_MeteorFalls_CaveEntrance_Left, TRUE
# 19 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	setmetatile 4, 2, METATILE_MeteorFalls_CaveEntrance_Bottom, FALSE
# 20 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	setmetatile 5, 2, METATILE_MeteorFalls_CaveEntrance_Right, TRUE
# 21 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	return
# 22 "data/maps/MeteorFalls_1F_1R/scripts.pory"

# 23 "data/maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_EventScript_MagmaStealsMeteoriteScene::
# 24 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	lockall
# 25 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	playbgm MUS_ENCOUNTER_MAGMA, FALSE
# 26 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
# 27 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	waitmovement 0
# 28 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	delay 30
# 29 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	applymovement LOCALID_MAGMA_GRUNT_1, Common_Movement_WalkInPlaceDown
# 30 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	waitmovement 0
# 31 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	msgbox MeteorFalls_1F_1R_Text_WithThisMeteorite, MSGBOX_DEFAULT
# 32 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	closemessage
# 33 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	applymovement LOCALID_MAGMA_GRUNT_1, Common_Movement_WalkInPlaceFasterUp
# 34 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	applymovement LOCALID_MAGMA_GRUNT_2, Common_Movement_WalkInPlaceFasterUp
# 35 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	waitmovement 0
# 36 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	playse SE_PIN
# 37 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	applymovement LOCALID_MAGMA_GRUNT_1, Common_Movement_ExclamationMark
# 38 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	waitmovement 0
# 39 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	applymovement LOCALID_MAGMA_GRUNT_1, Common_Movement_Delay48
# 40 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	waitmovement 0
# 41 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	msgbox MeteorFalls_1F_1R_Text_DontExpectMercyFromMagma, MSGBOX_DEFAULT
# 42 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	closemessage
# 43 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	applymovement LOCALID_MAGMA_GRUNT_1, MeteorFalls_1F_1R_Movement_MagmaGruntApproachPlayer
# 44 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	waitmovement 0
# 45 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	msgbox MeteorFalls_1F_1R_Text_HoldItRightThereMagma, MSGBOX_DEFAULT
# 46 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	closemessage
# 47 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 48 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	applymovement LOCALID_MAGMA_GRUNT_1, Common_Movement_WalkInPlaceFasterLeft
# 49 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	applymovement LOCALID_MAGMA_GRUNT_2, Common_Movement_WalkInPlaceFasterLeft
# 50 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	waitmovement 0
# 51 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	addobject LOCALID_ARCHIE
# 52 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	addobject LOCALID_AQUA_GRUNT_1
# 53 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	addobject LOCALID_AQUA_GRUNT_2
# 54 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	playbgm MUS_ENCOUNTER_AQUA, FALSE
# 55 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	applymovement LOCALID_ARCHIE, MeteorFalls_1F_1R_Movement_ArchieArrive
# 56 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	applymovement LOCALID_AQUA_GRUNT_1, MeteorFalls_1F_1R_Movement_AquaGrunt1Arrive
# 57 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	applymovement LOCALID_AQUA_GRUNT_2, MeteorFalls_1F_1R_Movement_AquaGrunt2Arrive
# 58 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	waitmovement 0
# 59 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	applymovement LOCALID_MAGMA_GRUNT_1, Common_Movement_WalkInPlaceFasterLeft
# 60 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	applymovement LOCALID_MAGMA_GRUNT_2, Common_Movement_WalkInPlaceFasterLeft
# 61 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	waitmovement 0
# 62 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	msgbox MeteorFalls_1F_1R_Text_BeSeeingYouTeamAqua, MSGBOX_DEFAULT
# 63 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	closemessage
# 64 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MeteorFalls_1F_1R_Movement_PushPlayerOutOfWay
# 65 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	applymovement LOCALID_MAGMA_GRUNT_1, MeteorFalls_1F_1R_Movement_MagmaGrunt1Exit
# 66 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	applymovement LOCALID_MAGMA_GRUNT_2, MeteorFalls_1F_1R_Movement_MagmaGrunt2Exit
# 67 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	waitmovement 0
# 68 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	removeobject LOCALID_MAGMA_GRUNT_1
# 69 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	removeobject LOCALID_MAGMA_GRUNT_2
# 70 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	applymovement LOCALID_ARCHIE, MeteorFalls_1F_1R_Movement_ArchieApproachPlayer
# 71 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	waitmovement 0
# 72 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	msgbox MeteorFalls_1F_1R_Text_ArchieSeenYouBefore, MSGBOX_DEFAULT
# 73 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	closemessage
# 74 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	applymovement LOCALID_AQUA_GRUNT_1, MeteorFalls_1F_1R_Movement_AquaGrunt1ApproachArchie
# 75 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	applymovement LOCALID_AQUA_GRUNT_2, MeteorFalls_1F_1R_Movement_AquaGrunt2ApproachArchie
# 76 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	waitmovement 0
# 77 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	msgbox MeteorFalls_1F_1R_Text_BossWeShouldChaseMagma, MSGBOX_DEFAULT
# 78 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	applymovement LOCALID_ARCHIE, Common_Movement_WalkInPlaceFasterDown
# 79 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	waitmovement 0
# 80 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	msgbox MeteorFalls_1F_1R_Text_ArchieYesNoTellingWhatMagmaWillDo, MSGBOX_DEFAULT
# 81 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	applymovement LOCALID_ARCHIE, Common_Movement_WalkInPlaceFasterLeft
# 82 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	waitmovement 0
# 83 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	msgbox MeteorFalls_1F_1R_Text_ArchieFarewell, MSGBOX_DEFAULT
# 84 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	closemessage
# 85 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	applymovement LOCALID_ARCHIE, MeteorFalls_1F_1R_Movement_ArchieExit
# 86 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	applymovement LOCALID_AQUA_GRUNT_1, MeteorFalls_1F_1R_Movement_AquaGrunt1Exit
# 87 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	applymovement LOCALID_AQUA_GRUNT_2, MeteorFalls_1F_1R_Movement_AquaGrunt2Exit
# 88 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	waitmovement 0
# 89 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	fadedefaultbgm
# 90 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	removeobject LOCALID_ARCHIE
# 91 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	removeobject LOCALID_AQUA_GRUNT_1
# 92 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	removeobject LOCALID_AQUA_GRUNT_2
# 93 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	setflag FLAG_HIDE_ROUTE_112_TEAM_MAGMA
# 94 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	setflag FLAG_MET_ARCHIE_METEOR_FALLS
# 95 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	setflag FLAG_HIDE_FALLARBOR_TOWN_BATTLE_TENT_SCOTT
# 96 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	setvar VAR_METEOR_FALLS_STATE, 1
# 97 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	releaseall
# 98 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	end
# 99 "data/maps/MeteorFalls_1F_1R/scripts.pory"

# 100 "data/maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_Movement_MagmaGruntApproachPlayer:
# 101 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 102 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 103 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_in_place_faster_up
# 104 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	step_end
# 105 "data/maps/MeteorFalls_1F_1R/scripts.pory"

# 106 "data/maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_Movement_MagmaGrunt1Exit:
# 107 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_fast_up
# 108 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_fast_up
# 109 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_fast_right
# 110 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_fast_right
# 111 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_fast_right
# 112 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_fast_right
# 113 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_fast_right
# 114 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_fast_right
# 115 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_fast_right
# 116 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	step_end
# 117 "data/maps/MeteorFalls_1F_1R/scripts.pory"

# 118 "data/maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_Movement_MagmaGrunt2Exit:
# 119 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_fast_up
# 120 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_fast_up
# 121 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_fast_up
# 122 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_fast_right
# 123 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_fast_right
# 124 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_fast_right
# 125 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_fast_right
# 126 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_fast_right
# 127 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_fast_right
# 128 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_fast_right
# 129 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	step_end
# 130 "data/maps/MeteorFalls_1F_1R/scripts.pory"

# 131 "data/maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_Movement_ArchieArrive:
# 132 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 133 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 134 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 135 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 136 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 137 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 138 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	step_end
# 139 "data/maps/MeteorFalls_1F_1R/scripts.pory"

# 140 "data/maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_Movement_AquaGrunt1Arrive:
# 141 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	delay_16
# 142 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	delay_16
# 143 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 144 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 145 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 146 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 147 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 148 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	step_end
# 149 "data/maps/MeteorFalls_1F_1R/scripts.pory"

# 150 "data/maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_Movement_AquaGrunt2Arrive:
# 151 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	delay_16
# 152 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	delay_16
# 153 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 154 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 155 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 156 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 157 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 158 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	step_end
# 159 "data/maps/MeteorFalls_1F_1R/scripts.pory"

# 160 "data/maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_Movement_ArchieExit:
# 161 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 162 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 163 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 164 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 165 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 166 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 167 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 168 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	step_end
# 169 "data/maps/MeteorFalls_1F_1R/scripts.pory"

# 170 "data/maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_Movement_ArchieApproachPlayer:
# 171 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 172 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 173 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_up
# 174 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_up
# 175 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_in_place_faster_left
# 176 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	step_end
# 177 "data/maps/MeteorFalls_1F_1R/scripts.pory"

# 178 "data/maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_Movement_AquaGrunt1Exit:
# 179 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_up
# 180 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_up
# 181 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 182 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 183 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 184 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 185 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 186 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 187 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 188 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	step_end
# 189 "data/maps/MeteorFalls_1F_1R/scripts.pory"

# 190 "data/maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_Movement_AquaGrunt1ApproachArchie:
# 191 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 192 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 193 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 194 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_in_place_faster_up
# 195 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	step_end
# 196 "data/maps/MeteorFalls_1F_1R/scripts.pory"

# 197 "data/maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_Movement_AquaGrunt2Exit:
# 198 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_up
# 199 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_up
# 200 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_up
# 201 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 202 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 203 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 204 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 205 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 206 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 207 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 208 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	step_end
# 209 "data/maps/MeteorFalls_1F_1R/scripts.pory"

# 210 "data/maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_Movement_AquaGrunt2ApproachArchie:
# 211 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 212 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 213 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 214 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_in_place_faster_up
# 215 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	step_end
# 216 "data/maps/MeteorFalls_1F_1R/scripts.pory"

# 217 "data/maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_Movement_PushPlayerOutOfWay:
# 218 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_in_place_faster_down
# 219 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	delay_4
# 220 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_in_place_faster_right
# 221 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	lock_facing_direction
# 222 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_left
# 223 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	unlock_facing_direction
# 224 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	face_right
# 225 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	step_end
# 226 "data/maps/MeteorFalls_1F_1R/scripts.pory"

# 227 "data/maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_EventScript_ProfCozmo::
# 228 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	lock
# 229 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	faceplayer
# 230 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	goto_if_set FLAG_MET_PROF_COZMO, MeteorFalls_1F_1R_EventScript_MetCozmo
# 231 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	setflag FLAG_MET_PROF_COZMO
# 232 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	msgbox MeteorFalls_1F_1R_Text_MeetProfCozmo, MSGBOX_DEFAULT
# 233 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	release
# 234 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	end
# 235 "data/maps/MeteorFalls_1F_1R/scripts.pory"

# 236 "data/maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_EventScript_MetCozmo::
# 237 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	msgbox MeteorFalls_1F_1R_Text_WhatsTeamMagmaDoingAtMtChimney, MSGBOX_DEFAULT
# 238 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	release
# 239 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	end
# 240 "data/maps/MeteorFalls_1F_1R/scripts.pory"

# 241 "data/maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_Text_WithThisMeteorite:
# 242 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "Hehehe!\p"
# 243 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "With this METEORITE, that thing in\n"
# 244 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "MT. CHIMNEY will…$"
# 245 "data/maps/MeteorFalls_1F_1R/scripts.pory"

# 246 "data/maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_Text_DontExpectMercyFromMagma:
# 247 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "Heh?\p"
# 248 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "I don't know who you are, but if you get\n"
# 249 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "in the way of TEAM MAGMA, don't\l"
# 250 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "expect any mercy!$"
# 251 "data/maps/MeteorFalls_1F_1R/scripts.pory"

# 252 "data/maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_Text_HoldItRightThereMagma:
# 253 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "Hold it right there, TEAM MAGMA!\p"
# 254 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "You're badly mistaken if you think you\n"
# 255 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "can have your way with the world!$"
# 256 "data/maps/MeteorFalls_1F_1R/scripts.pory"

# 257 "data/maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_Text_BeSeeingYouTeamAqua:
# 258 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "Hehehe!\n"
# 259 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "Even TEAM AQUA joins us!\p"
# 260 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "But it's too much trouble to deal with\n"
# 261 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "you all…\p"
# 262 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "Heh, it doesn't matter!\p"
# 263 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "We've got the METEORITE, so off to\n"
# 264 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "MT. CHIMNEY we go!\p"
# 265 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "Hehehe! Be seeing you, you TEAM\n"
# 266 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "AQUA dingbats!$"
# 267 "data/maps/MeteorFalls_1F_1R/scripts.pory"

# 268 "data/maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_Text_ArchieSeenYouBefore:
# 269 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "ARCHIE: Didn't I see you before?\n"
# 270 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "At SLATEPORT's MUSEUM?\p"
# 271 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "Ah, so your name is {PLAYER}.\p"
# 272 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "At the time, I thought you were one\n"
# 273 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "of TEAM MAGMA's goons.\p"
# 274 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "Humph…\n"
# 275 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "You're one odd kid.\p"
# 276 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "TEAM MAGMA is a dangerous group of\n"
# 277 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "total fanatics.\p"
# 278 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "They engage in destruction, claiming\n"
# 279 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "to expand the land mass.\p"
# 280 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "They are the rivals to us,\n"
# 281 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "the sea-loving TEAM AQUA!$"
# 282 "data/maps/MeteorFalls_1F_1R/scripts.pory"

# 283 "data/maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_Text_BossWeShouldChaseMagma:
# 284 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "BOSS, we should give chase to\n"
# 285 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "TEAM MAGMA…$"
# 286 "data/maps/MeteorFalls_1F_1R/scripts.pory"

# 287 "data/maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_Text_ArchieYesNoTellingWhatMagmaWillDo:
# 288 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "ARCHIE: Yes, yes, we must!\n"
# 289 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "We've got to hurry.\p"
# 290 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "There's no telling what TEAM MAGMA\n"
# 291 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "will do at MT. CHIMNEY!$"
# 292 "data/maps/MeteorFalls_1F_1R/scripts.pory"

# 293 "data/maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_Text_ArchieFarewell:
# 294 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "ARCHIE: {PLAYER}, you should keep\n"
# 295 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "an eye out for TEAM MAGMA, too.\p"
# 296 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "Farewell!$"
# 297 "data/maps/MeteorFalls_1F_1R/scripts.pory"

# 298 "data/maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_Text_MeetProfCozmo:
# 299 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "I… I'm COZMO…\n"
# 300 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "I'm a PROFESSOR…\p"
# 301 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "TEAM MAGMA asked me to guide them\n"
# 302 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "to METEOR FALLS…\p"
# 303 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "But they tricked me.\n"
# 304 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "They even took my METEORITE away…\p"
# 305 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "And then another similar bunch,\n"
# 306 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "TEAM AQUA showed up.\p"
# 307 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "After that…\n"
# 308 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "I don't understand any of it.\p"
# 309 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "But that TEAM MAGMA…\p"
# 310 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "What are they going to do with that\n"
# 311 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "METEORITE at MT. CHIMNEY?$"
# 312 "data/maps/MeteorFalls_1F_1R/scripts.pory"

# 313 "data/maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_Text_WhatsTeamMagmaDoingAtMtChimney:
# 314 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "PROF. COZMO: But that TEAM MAGMA…\p"
# 315 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "What are they going to do with that\n"
# 316 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "METEORITE at MT. CHIMNEY?$"
