# 1 "data/maps/MeteorFalls_1F_1R/scripts.pory"

# 2 "data/maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_MapScripts::
# 3 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, MeteorFalls_1F_1R_OnLoad
# 4 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.byte 0
# 5 "data/maps/MeteorFalls_1F_1R/scripts.pory"

# 6 "data/maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_OnLoad:
# 7 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	call_if_set FLAG_SYS_GAME_CLEAR, MeteorFalls_1F_1R_EventScript_OpenStevensCave
# 8 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	end
# 9 "data/maps/MeteorFalls_1F_1R/scripts.pory"

# 10 "data/maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_EventScript_OpenStevensCave::
# 11 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	setmetatile 4, 1, METATILE_MeteorFalls_CaveEntrance_Top, TRUE
# 12 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	setmetatile 3, 2, METATILE_MeteorFalls_CaveEntrance_Left, TRUE
# 13 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	setmetatile 4, 2, METATILE_MeteorFalls_CaveEntrance_Bottom, FALSE
# 14 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	setmetatile 5, 2, METATILE_MeteorFalls_CaveEntrance_Right, TRUE
# 15 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	return
# 16 "data/maps/MeteorFalls_1F_1R/scripts.pory"

# 17 "data/maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_EventScript_MagmaStealsMeteoriteScene::
# 18 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	lockall
# 19 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	playbgm MUS_ENCOUNTER_MAGMA, FALSE
# 20 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_FaceDown
# 21 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	waitmovement 0
# 22 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	delay 30
# 23 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	applymovement LOCALID_METEOR_FALLS_MAGMA_GRUNT_1, Common_Movement_WalkInPlaceDown
# 24 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	waitmovement 0
# 25 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	msgbox MeteorFalls_1F_1R_Text_WithThisMeteorite, MSGBOX_DEFAULT
# 26 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	closemessage
# 27 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	applymovement LOCALID_METEOR_FALLS_MAGMA_GRUNT_1, Common_Movement_WalkInPlaceFasterUp
# 28 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	applymovement LOCALID_METEOR_FALLS_MAGMA_GRUNT_2, Common_Movement_WalkInPlaceFasterUp
# 29 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	waitmovement 0
# 30 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	playse SE_PIN
# 31 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	applymovement LOCALID_METEOR_FALLS_MAGMA_GRUNT_1, Common_Movement_ExclamationMark
# 32 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	waitmovement 0
# 33 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	applymovement LOCALID_METEOR_FALLS_MAGMA_GRUNT_1, Common_Movement_Delay48
# 34 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	waitmovement 0
# 35 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	msgbox MeteorFalls_1F_1R_Text_DontExpectMercyFromMagma, MSGBOX_DEFAULT
# 36 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	closemessage
# 37 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	applymovement LOCALID_METEOR_FALLS_MAGMA_GRUNT_1, MeteorFalls_1F_1R_Movement_MagmaGruntApproachPlayer
# 38 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	waitmovement 0
# 39 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	msgbox MeteorFalls_1F_1R_Text_HoldItRightThereMagma, MSGBOX_DEFAULT
# 40 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	closemessage
# 41 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 42 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	applymovement LOCALID_METEOR_FALLS_MAGMA_GRUNT_1, Common_Movement_WalkInPlaceFasterLeft
# 43 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	applymovement LOCALID_METEOR_FALLS_MAGMA_GRUNT_2, Common_Movement_WalkInPlaceFasterLeft
# 44 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	waitmovement 0
# 45 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	addobject LOCALID_METEOR_FALLS_ARCHIE
# 46 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	addobject LOCALID_METEOR_FALLS_AQUA_GRUNT_1
# 47 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	addobject LOCALID_METEOR_FALLS_AQUA_GRUNT_2
# 48 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	playbgm MUS_ENCOUNTER_AQUA, FALSE
# 49 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	applymovement LOCALID_METEOR_FALLS_ARCHIE, MeteorFalls_1F_1R_Movement_ArchieArrive
# 50 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	applymovement LOCALID_METEOR_FALLS_AQUA_GRUNT_1, MeteorFalls_1F_1R_Movement_AquaGrunt1Arrive
# 51 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	applymovement LOCALID_METEOR_FALLS_AQUA_GRUNT_2, MeteorFalls_1F_1R_Movement_AquaGrunt2Arrive
# 52 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	waitmovement 0
# 53 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	applymovement LOCALID_METEOR_FALLS_MAGMA_GRUNT_1, Common_Movement_WalkInPlaceFasterLeft
# 54 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	applymovement LOCALID_METEOR_FALLS_MAGMA_GRUNT_2, Common_Movement_WalkInPlaceFasterLeft
# 55 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	waitmovement 0
# 56 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	msgbox MeteorFalls_1F_1R_Text_BeSeeingYouTeamAqua, MSGBOX_DEFAULT
# 57 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	closemessage
# 58 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	applymovement LOCALID_PLAYER, MeteorFalls_1F_1R_Movement_PushPlayerOutOfWay
# 59 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	applymovement LOCALID_METEOR_FALLS_MAGMA_GRUNT_1, MeteorFalls_1F_1R_Movement_MagmaGrunt1Exit
# 60 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	applymovement LOCALID_METEOR_FALLS_MAGMA_GRUNT_2, MeteorFalls_1F_1R_Movement_MagmaGrunt2Exit
# 61 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	waitmovement 0
# 62 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	removeobject LOCALID_METEOR_FALLS_MAGMA_GRUNT_1
# 63 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	removeobject LOCALID_METEOR_FALLS_MAGMA_GRUNT_2
# 64 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	applymovement LOCALID_METEOR_FALLS_ARCHIE, MeteorFalls_1F_1R_Movement_ArchieApproachPlayer
# 65 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	waitmovement 0
# 66 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	msgbox MeteorFalls_1F_1R_Text_ArchieSeenYouBefore, MSGBOX_DEFAULT
# 67 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	closemessage
# 68 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	applymovement LOCALID_METEOR_FALLS_AQUA_GRUNT_1, MeteorFalls_1F_1R_Movement_AquaGrunt1ApproachArchie
# 69 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	applymovement LOCALID_METEOR_FALLS_AQUA_GRUNT_2, MeteorFalls_1F_1R_Movement_AquaGrunt2ApproachArchie
# 70 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	waitmovement 0
# 71 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	msgbox MeteorFalls_1F_1R_Text_BossWeShouldChaseMagma, MSGBOX_DEFAULT
# 72 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	applymovement LOCALID_METEOR_FALLS_ARCHIE, Common_Movement_WalkInPlaceFasterDown
# 73 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	waitmovement 0
# 74 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	msgbox MeteorFalls_1F_1R_Text_ArchieYesNoTellingWhatMagmaWillDo, MSGBOX_DEFAULT
# 75 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	applymovement LOCALID_METEOR_FALLS_ARCHIE, Common_Movement_WalkInPlaceFasterLeft
# 76 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	waitmovement 0
# 77 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	msgbox MeteorFalls_1F_1R_Text_ArchieFarewell, MSGBOX_DEFAULT
# 78 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	closemessage
# 79 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	applymovement LOCALID_METEOR_FALLS_ARCHIE, MeteorFalls_1F_1R_Movement_ArchieExit
# 80 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	applymovement LOCALID_METEOR_FALLS_AQUA_GRUNT_1, MeteorFalls_1F_1R_Movement_AquaGrunt1Exit
# 81 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	applymovement LOCALID_METEOR_FALLS_AQUA_GRUNT_2, MeteorFalls_1F_1R_Movement_AquaGrunt2Exit
# 82 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	waitmovement 0
# 83 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	fadedefaultbgm
# 84 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	removeobject LOCALID_METEOR_FALLS_ARCHIE
# 85 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	removeobject LOCALID_METEOR_FALLS_AQUA_GRUNT_1
# 86 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	removeobject LOCALID_METEOR_FALLS_AQUA_GRUNT_2
# 87 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	setflag FLAG_HIDE_ROUTE_112_TEAM_MAGMA
# 88 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	setflag FLAG_MET_ARCHIE_METEOR_FALLS
# 89 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	setflag FLAG_HIDE_FALLARBOR_TOWN_BATTLE_TENT_SCOTT
# 90 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	setvar VAR_METEOR_FALLS_STATE, 1
# 91 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	releaseall
# 92 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	end
# 93 "data/maps/MeteorFalls_1F_1R/scripts.pory"

# 94 "data/maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_Movement_MagmaGruntApproachPlayer:
# 95 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 96 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 97 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_in_place_faster_up
# 98 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	step_end
# 99 "data/maps/MeteorFalls_1F_1R/scripts.pory"

# 100 "data/maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_Movement_MagmaGrunt1Exit:
# 101 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_fast_up
# 102 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_fast_up
# 103 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_fast_right
# 104 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_fast_right
# 105 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_fast_right
# 106 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_fast_right
# 107 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_fast_right
# 108 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_fast_right
# 109 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_fast_right
# 110 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	step_end
# 111 "data/maps/MeteorFalls_1F_1R/scripts.pory"

# 112 "data/maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_Movement_MagmaGrunt2Exit:
# 113 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_fast_up
# 114 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_fast_up
# 115 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_fast_up
# 116 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_fast_right
# 117 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_fast_right
# 118 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_fast_right
# 119 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_fast_right
# 120 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_fast_right
# 121 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_fast_right
# 122 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_fast_right
# 123 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	step_end
# 124 "data/maps/MeteorFalls_1F_1R/scripts.pory"

# 125 "data/maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_Movement_ArchieArrive:
# 126 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 127 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 128 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 129 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 130 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 131 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 132 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	step_end
# 133 "data/maps/MeteorFalls_1F_1R/scripts.pory"

# 134 "data/maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_Movement_AquaGrunt1Arrive:
# 135 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	delay_16
# 136 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	delay_16
# 137 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 138 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 139 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 140 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 141 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 142 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	step_end
# 143 "data/maps/MeteorFalls_1F_1R/scripts.pory"

# 144 "data/maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_Movement_AquaGrunt2Arrive:
# 145 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	delay_16
# 146 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	delay_16
# 147 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 148 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 149 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 150 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 151 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 152 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	step_end
# 153 "data/maps/MeteorFalls_1F_1R/scripts.pory"

# 154 "data/maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_Movement_ArchieExit:
# 155 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 156 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 157 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 158 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 159 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 160 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 161 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 162 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	step_end
# 163 "data/maps/MeteorFalls_1F_1R/scripts.pory"

# 164 "data/maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_Movement_ArchieApproachPlayer:
# 165 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 166 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 167 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_up
# 168 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_up
# 169 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_in_place_faster_left
# 170 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	step_end
# 171 "data/maps/MeteorFalls_1F_1R/scripts.pory"

# 172 "data/maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_Movement_AquaGrunt1Exit:
# 173 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_up
# 174 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_up
# 175 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 176 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 177 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 178 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 179 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 180 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 181 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 182 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	step_end
# 183 "data/maps/MeteorFalls_1F_1R/scripts.pory"

# 184 "data/maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_Movement_AquaGrunt1ApproachArchie:
# 185 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 186 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 187 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 188 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_in_place_faster_up
# 189 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	step_end
# 190 "data/maps/MeteorFalls_1F_1R/scripts.pory"

# 191 "data/maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_Movement_AquaGrunt2Exit:
# 192 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_up
# 193 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_up
# 194 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_up
# 195 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 196 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 197 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 198 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 199 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 200 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 201 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 202 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	step_end
# 203 "data/maps/MeteorFalls_1F_1R/scripts.pory"

# 204 "data/maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_Movement_AquaGrunt2ApproachArchie:
# 205 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 206 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 207 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 208 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_in_place_faster_up
# 209 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	step_end
# 210 "data/maps/MeteorFalls_1F_1R/scripts.pory"

# 211 "data/maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_Movement_PushPlayerOutOfWay:
# 212 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_in_place_faster_down
# 213 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	delay_4
# 214 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_in_place_faster_right
# 215 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	lock_facing_direction
# 216 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_left
# 217 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	unlock_facing_direction
# 218 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	face_right
# 219 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	step_end
# 220 "data/maps/MeteorFalls_1F_1R/scripts.pory"

# 221 "data/maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_EventScript_ProfCozmo::
# 222 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	lock
# 223 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	faceplayer
# 224 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	goto_if_set FLAG_MET_PROF_COZMO, MeteorFalls_1F_1R_EventScript_MetCozmo
# 225 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	setflag FLAG_MET_PROF_COZMO
# 226 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	msgbox MeteorFalls_1F_1R_Text_MeetProfCozmo, MSGBOX_DEFAULT
# 227 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	release
# 228 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	end
# 229 "data/maps/MeteorFalls_1F_1R/scripts.pory"

# 230 "data/maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_EventScript_MetCozmo::
# 231 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	msgbox MeteorFalls_1F_1R_Text_WhatsTeamMagmaDoingAtMtChimney, MSGBOX_DEFAULT
# 232 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	release
# 233 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	end
# 234 "data/maps/MeteorFalls_1F_1R/scripts.pory"

# 235 "data/maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_Text_WithThisMeteorite:
# 236 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "Hehehe!\p"
# 237 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "With this METEORITE, that thing in\n"
# 238 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "MT. CHIMNEY will…$"
# 239 "data/maps/MeteorFalls_1F_1R/scripts.pory"

# 240 "data/maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_Text_DontExpectMercyFromMagma:
# 241 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "Heh?\p"
# 242 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "I don't know who you are, but if you get\n"
# 243 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "in the way of TEAM MAGMA, don't\l"
# 244 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "expect any mercy!$"
# 245 "data/maps/MeteorFalls_1F_1R/scripts.pory"

# 246 "data/maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_Text_HoldItRightThereMagma:
# 247 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "Hold it right there, TEAM MAGMA!\p"
# 248 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "You're badly mistaken if you think you\n"
# 249 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "can have your way with the world!$"
# 250 "data/maps/MeteorFalls_1F_1R/scripts.pory"

# 251 "data/maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_Text_BeSeeingYouTeamAqua:
# 252 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "Hehehe!\n"
# 253 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "Even TEAM AQUA joins us!\p"
# 254 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "But it's too much trouble to deal with\n"
# 255 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "you all…\p"
# 256 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "Heh, it doesn't matter!\p"
# 257 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "We've got the METEORITE, so off to\n"
# 258 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "MT. CHIMNEY we go!\p"
# 259 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "Hehehe! Be seeing you, you TEAM\n"
# 260 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "AQUA dingbats!$"
# 261 "data/maps/MeteorFalls_1F_1R/scripts.pory"

# 262 "data/maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_Text_ArchieSeenYouBefore:
# 263 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "ARCHIE: Didn't I see you before?\n"
# 264 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "At SLATEPORT's MUSEUM?\p"
# 265 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "Ah, so your name is {PLAYER}.\p"
# 266 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "At the time, I thought you were one\n"
# 267 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "of TEAM MAGMA's goons.\p"
# 268 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "Humph…\n"
# 269 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "You're one odd kid.\p"
# 270 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "TEAM MAGMA is a dangerous group of\n"
# 271 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "total fanatics.\p"
# 272 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "They engage in destruction, claiming\n"
# 273 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "to expand the land mass.\p"
# 274 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "They are the rivals to us,\n"
# 275 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "the sea-loving TEAM AQUA!$"
# 276 "data/maps/MeteorFalls_1F_1R/scripts.pory"

# 277 "data/maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_Text_BossWeShouldChaseMagma:
# 278 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "BOSS, we should give chase to\n"
# 279 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "TEAM MAGMA…$"
# 280 "data/maps/MeteorFalls_1F_1R/scripts.pory"

# 281 "data/maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_Text_ArchieYesNoTellingWhatMagmaWillDo:
# 282 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "ARCHIE: Yes, yes, we must!\n"
# 283 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "We've got to hurry.\p"
# 284 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "There's no telling what TEAM MAGMA\n"
# 285 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "will do at MT. CHIMNEY!$"
# 286 "data/maps/MeteorFalls_1F_1R/scripts.pory"

# 287 "data/maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_Text_ArchieFarewell:
# 288 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "ARCHIE: {PLAYER}, you should keep\n"
# 289 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "an eye out for TEAM MAGMA, too.\p"
# 290 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "Farewell!$"
# 291 "data/maps/MeteorFalls_1F_1R/scripts.pory"

# 292 "data/maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_Text_MeetProfCozmo:
# 293 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "I… I'm COZMO…\n"
# 294 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "I'm a PROFESSOR…\p"
# 295 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "TEAM MAGMA asked me to guide them\n"
# 296 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "to METEOR FALLS…\p"
# 297 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "But they tricked me.\n"
# 298 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "They even took my METEORITE away…\p"
# 299 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "And then another similar bunch,\n"
# 300 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "TEAM AQUA showed up.\p"
# 301 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "After that…\n"
# 302 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "I don't understand any of it.\p"
# 303 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "But that TEAM MAGMA…\p"
# 304 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "What are they going to do with that\n"
# 305 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "METEORITE at MT. CHIMNEY?$"
# 306 "data/maps/MeteorFalls_1F_1R/scripts.pory"

# 307 "data/maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_Text_WhatsTeamMagmaDoingAtMtChimney:
# 308 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "PROF. COZMO: But that TEAM MAGMA…\p"
# 309 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "What are they going to do with that\n"
# 310 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "METEORITE at MT. CHIMNEY?$"
