SouthCampus_MapScripts::
	.byte 0


SouthCampus_LockedCafeteria::
# 5 "data/maps/SouthCampus/scripts.pory"
	lock
# 6 "data/maps/SouthCampus/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SouthCampus_LockedCafeteria_Movement_0
# 7 "data/maps/SouthCampus/scripts.pory"
	msgbox SouthCampus_LockedCafeteria_Text_0
# 8 "data/maps/SouthCampus/scripts.pory"
	closemessage
# 9 "data/maps/SouthCampus/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SouthCampus_LockedCafeteria_Movement_1
# 10 "data/maps/SouthCampus/scripts.pory"
	waitmovement 0
# 11 "data/maps/SouthCampus/scripts.pory"
	release
	return


SouthCampus_MoveToBattle1::
# 15 "data/maps/SouthCampus/scripts.pory"
	call SouthCampus_HearBattle
# 16 "data/maps/SouthCampus/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SouthCampus_MoveToBattle1_Movement_0
# 17 "data/maps/SouthCampus/scripts.pory"
	applymovement OBJ_EVENT_ID_NPC_FOLLOWER, SouthCampus_MoveToBattle1_Movement_1
# 18 "data/maps/SouthCampus/scripts.pory"
	waitmovement 0
# 19 "data/maps/SouthCampus/scripts.pory"
	call SouthCampus_ApproachBattle
	return


SouthCampus_MoveToBattle2::
# 23 "data/maps/SouthCampus/scripts.pory"
	call SouthCampus_HearBattle
# 24 "data/maps/SouthCampus/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SouthCampus_MoveToBattle2_Movement_0
# 25 "data/maps/SouthCampus/scripts.pory"
	applymovement OBJ_EVENT_ID_NPC_FOLLOWER, SouthCampus_MoveToBattle2_Movement_1
# 26 "data/maps/SouthCampus/scripts.pory"
	waitmovement 0
# 27 "data/maps/SouthCampus/scripts.pory"
	call SouthCampus_ApproachBattle
	return


SouthCampus_MoveToBattle3::
# 31 "data/maps/SouthCampus/scripts.pory"
	call SouthCampus_HearBattle
# 32 "data/maps/SouthCampus/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SouthCampus_MoveToBattle3_Movement_0
# 33 "data/maps/SouthCampus/scripts.pory"
	applymovement OBJ_EVENT_ID_NPC_FOLLOWER, SouthCampus_MoveToBattle3_Movement_1
# 34 "data/maps/SouthCampus/scripts.pory"
	waitmovement 0
# 35 "data/maps/SouthCampus/scripts.pory"
	call SouthCampus_ApproachBattle
	return


SouthCampus_MoveToBattle4::
# 39 "data/maps/SouthCampus/scripts.pory"
	call SouthCampus_HearBattle
# 40 "data/maps/SouthCampus/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SouthCampus_MoveToBattle4_Movement_0
# 41 "data/maps/SouthCampus/scripts.pory"
	applymovement OBJ_EVENT_ID_NPC_FOLLOWER, SouthCampus_MoveToBattle4_Movement_1
# 42 "data/maps/SouthCampus/scripts.pory"
	waitmovement 0
# 43 "data/maps/SouthCampus/scripts.pory"
	call SouthCampus_ApproachBattle
	return


SouthCampus_MoveToBattle5::
# 47 "data/maps/SouthCampus/scripts.pory"
	call SouthCampus_HearBattle2
# 48 "data/maps/SouthCampus/scripts.pory"
	applymovement OBJ_EVENT_ID_NPC_FOLLOWER, SouthCampus_MoveToBattle5_Movement_0
# 49 "data/maps/SouthCampus/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SouthCampus_MoveToBattle5_Movement_1
# 50 "data/maps/SouthCampus/scripts.pory"
	waitmovement 0
# 51 "data/maps/SouthCampus/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SouthCampus_MoveToBattle5_Movement_2
# 52 "data/maps/SouthCampus/scripts.pory"
	applymovement OBJ_EVENT_ID_NPC_FOLLOWER, SouthCampus_MoveToBattle5_Movement_3
# 53 "data/maps/SouthCampus/scripts.pory"
	waitmovement 0
# 54 "data/maps/SouthCampus/scripts.pory"
	call SouthCampus_ApproachBattle
	return


SouthCampus_MoveToBattle6::
# 58 "data/maps/SouthCampus/scripts.pory"
	call SouthCampus_HearBattle2
# 59 "data/maps/SouthCampus/scripts.pory"
	applymovement OBJ_EVENT_ID_NPC_FOLLOWER, SouthCampus_LockedCafeteria_Movement_0
# 60 "data/maps/SouthCampus/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SouthCampus_MoveToBattle6_Movement_0
# 61 "data/maps/SouthCampus/scripts.pory"
	waitmovement 0
# 62 "data/maps/SouthCampus/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SouthCampus_MoveToBattle6_Movement_1
# 63 "data/maps/SouthCampus/scripts.pory"
	applymovement OBJ_EVENT_ID_NPC_FOLLOWER, SouthCampus_MoveToBattle6_Movement_2
# 64 "data/maps/SouthCampus/scripts.pory"
	waitmovement 0
# 65 "data/maps/SouthCampus/scripts.pory"
	call SouthCampus_ApproachBattle
	return


SouthCampus_MoveToBattle7::
# 69 "data/maps/SouthCampus/scripts.pory"
	call SouthCampus_HearBattle2
# 70 "data/maps/SouthCampus/scripts.pory"
	applymovement OBJ_EVENT_ID_NPC_FOLLOWER, SouthCampus_LockedCafeteria_Movement_0
# 71 "data/maps/SouthCampus/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SouthCampus_MoveToBattle6_Movement_0
# 72 "data/maps/SouthCampus/scripts.pory"
	waitmovement 0
# 73 "data/maps/SouthCampus/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SouthCampus_MoveToBattle5_Movement_2
# 74 "data/maps/SouthCampus/scripts.pory"
	applymovement OBJ_EVENT_ID_NPC_FOLLOWER, SouthCampus_MoveToBattle7_Movement_0
# 75 "data/maps/SouthCampus/scripts.pory"
	waitmovement 0
# 76 "data/maps/SouthCampus/scripts.pory"
	call SouthCampus_ApproachBattle
	return


SouthCampus_MoveToBattle8::
# 80 "data/maps/SouthCampus/scripts.pory"
	call SouthCampus_HearBattle2
# 81 "data/maps/SouthCampus/scripts.pory"
	applymovement OBJ_EVENT_ID_NPC_FOLLOWER, SouthCampus_LockedCafeteria_Movement_0
# 82 "data/maps/SouthCampus/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SouthCampus_MoveToBattle6_Movement_0
# 83 "data/maps/SouthCampus/scripts.pory"
	waitmovement 0
# 84 "data/maps/SouthCampus/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SouthCampus_MoveToBattle8_Movement_0
# 85 "data/maps/SouthCampus/scripts.pory"
	applymovement OBJ_EVENT_ID_NPC_FOLLOWER, SouthCampus_MoveToBattle8_Movement_1
# 86 "data/maps/SouthCampus/scripts.pory"
	waitmovement 0
# 87 "data/maps/SouthCampus/scripts.pory"
	call SouthCampus_ApproachBattle
	return


SouthCampus_HearBattle::
# 91 "data/maps/SouthCampus/scripts.pory"
	lock
# 92 "data/maps/SouthCampus/scripts.pory"
	applymovement LOCALID_FAT_MAN, SouthCampus_LockedCafeteria_Movement_0
# 93 "data/maps/SouthCampus/scripts.pory"
	msgbox SouthCampus_HearBattle_Text_0
# 94 "data/maps/SouthCampus/scripts.pory"
	playmoncry SPECIES_MEOWTH, 0
# 95 "data/maps/SouthCampus/scripts.pory"
	waitmoncry
# 96 "data/maps/SouthCampus/scripts.pory"
	delay 10
# 97 "data/maps/SouthCampus/scripts.pory"
	closemessage
# 98 "data/maps/SouthCampus/scripts.pory"
	applymovement OBJ_EVENT_ID_NPC_FOLLOWER, SouthCampus_HearBattle_Movement_0
# 99 "data/maps/SouthCampus/scripts.pory"
	playse SE_PIN
# 100 "data/maps/SouthCampus/scripts.pory"
	waitse
# 101 "data/maps/SouthCampus/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SouthCampus_HearBattle_Movement_1
# 102 "data/maps/SouthCampus/scripts.pory"
	waitmovement 0
# 103 "data/maps/SouthCampus/scripts.pory"
	applymovement OBJ_EVENT_ID_NPC_FOLLOWER, SouthCampus_HearBattle_Movement_2
# 104 "data/maps/SouthCampus/scripts.pory"
	playse SE_LEDGE
# 105 "data/maps/SouthCampus/scripts.pory"
	waitmovement 0
# 106 "data/maps/SouthCampus/scripts.pory"
	applymovement OBJ_EVENT_ID_NPC_FOLLOWER, SouthCampus_HearBattle_Movement_2
# 107 "data/maps/SouthCampus/scripts.pory"
	playse SE_LEDGE
# 108 "data/maps/SouthCampus/scripts.pory"
	waitmovement 0
# 109 "data/maps/SouthCampus/scripts.pory"
	msgbox SouthCampus_HearBattle_Text_1
# 110 "data/maps/SouthCampus/scripts.pory"
	closemessage
	return


SouthCampus_HearBattle2::
# 115 "data/maps/SouthCampus/scripts.pory"
	lock
# 116 "data/maps/SouthCampus/scripts.pory"
	applymovement LOCALID_FAT_MAN, SouthCampus_LockedCafeteria_Movement_0
# 117 "data/maps/SouthCampus/scripts.pory"
	msgbox SouthCampus_HearBattle_Text_0
# 118 "data/maps/SouthCampus/scripts.pory"
	playmoncry SPECIES_MEOWTH, 0
# 119 "data/maps/SouthCampus/scripts.pory"
	waitmoncry
# 120 "data/maps/SouthCampus/scripts.pory"
	delay 10
# 121 "data/maps/SouthCampus/scripts.pory"
	closemessage
# 122 "data/maps/SouthCampus/scripts.pory"
	applymovement OBJ_EVENT_ID_NPC_FOLLOWER, SouthCampus_HearBattle2_Movement_0
# 123 "data/maps/SouthCampus/scripts.pory"
	playse SE_PIN
# 124 "data/maps/SouthCampus/scripts.pory"
	waitse
# 125 "data/maps/SouthCampus/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SouthCampus_HearBattle2_Movement_1
# 126 "data/maps/SouthCampus/scripts.pory"
	waitmovement 0
# 127 "data/maps/SouthCampus/scripts.pory"
	applymovement OBJ_EVENT_ID_NPC_FOLLOWER, SouthCampus_HearBattle_Movement_2
# 128 "data/maps/SouthCampus/scripts.pory"
	playse SE_LEDGE
# 129 "data/maps/SouthCampus/scripts.pory"
	waitmovement 0
# 130 "data/maps/SouthCampus/scripts.pory"
	applymovement OBJ_EVENT_ID_NPC_FOLLOWER, SouthCampus_HearBattle_Movement_2
# 131 "data/maps/SouthCampus/scripts.pory"
	playse SE_LEDGE
# 132 "data/maps/SouthCampus/scripts.pory"
	waitmovement 0
# 133 "data/maps/SouthCampus/scripts.pory"
	msgbox SouthCampus_HearBattle_Text_1
# 134 "data/maps/SouthCampus/scripts.pory"
	closemessage
	return


SouthCampus_ApproachBattle::
# 141 "data/maps/SouthCampus/scripts.pory"
	msgbox SouthCampus_ApproachBattle_Text_0
# 142 "data/maps/SouthCampus/scripts.pory"
	closemessage
# 143 "data/maps/SouthCampus/scripts.pory"
	special SpawnCameraObject
# 144 "data/maps/SouthCampus/scripts.pory"
	setobjectxy LOCALID_CAMERA, 23, 29
# 145 "data/maps/SouthCampus/scripts.pory"
	playbgm CUS_VS_TRAINER, FALSE
# 146 "data/maps/SouthCampus/scripts.pory"
	applymovement LOCALID_CAMERA, SouthCampus_ApproachBattle_Movement_0
# 147 "data/maps/SouthCampus/scripts.pory"
	waitmovement 0
# 148 "data/maps/SouthCampus/scripts.pory"
	msgbox SouthCampus_ApproachBattle_Text_1
# 149 "data/maps/SouthCampus/scripts.pory"
	closemessage
# 150 "data/maps/SouthCampus/scripts.pory"
	msgbox SouthCampus_ApproachBattle_Text_2
# 151 "data/maps/SouthCampus/scripts.pory"
	closemessage
# 152 "data/maps/SouthCampus/scripts.pory"
	applymovement LOCALID_CAMERA, SouthCampus_ApproachBattle_Movement_1
# 153 "data/maps/SouthCampus/scripts.pory"
	waitmovement 0
# 154 "data/maps/SouthCampus/scripts.pory"
	msgbox SouthCampus_ApproachBattle_Text_3
# 155 "data/maps/SouthCampus/scripts.pory"
	closemessage
# 156 "data/maps/SouthCampus/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SouthCampus_HearBattle2_Movement_1
# 157 "data/maps/SouthCampus/scripts.pory"
	applymovement OBJ_EVENT_ID_NPC_FOLLOWER, SouthCampus_HearBattle2_Movement_1
# 158 "data/maps/SouthCampus/scripts.pory"
	applymovement LOCALID_FAT_MAN, SouthCampus_HearBattle_Movement_1
# 159 "data/maps/SouthCampus/scripts.pory"
	waitmovement 0
# 160 "data/maps/SouthCampus/scripts.pory"
	msgbox SouthCampus_ApproachBattle_Text_4
# 161 "data/maps/SouthCampus/scripts.pory"
	closemessage
# 162 "data/maps/SouthCampus/scripts.pory"
	msgbox SouthCampus_ApproachBattle_Text_5
# 163 "data/maps/SouthCampus/scripts.pory"
	closemessage
# 164 "data/maps/SouthCampus/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SouthCampus_LockedCafeteria_Movement_0
# 165 "data/maps/SouthCampus/scripts.pory"
	applymovement OBJ_EVENT_ID_NPC_FOLLOWER, SouthCampus_LockedCafeteria_Movement_0
# 166 "data/maps/SouthCampus/scripts.pory"
	applymovement LOCALID_FAT_MAN, SouthCampus_LockedCafeteria_Movement_0
# 167 "data/maps/SouthCampus/scripts.pory"
	applymovement LOCALID_CAMERA, SouthCampus_ApproachBattle_Movement_0
# 168 "data/maps/SouthCampus/scripts.pory"
	waitmovement 0
# 169 "data/maps/SouthCampus/scripts.pory"
	call SouthCampus_MeowthBattle
	return


SouthCampus_MeowthBattle::
# 173 "data/maps/SouthCampus/scripts.pory"
	msgbox SouthCampus_MeowthBattle_Text_0
# 174 "data/maps/SouthCampus/scripts.pory"
	closemessage
# 175 "data/maps/SouthCampus/scripts.pory"
	playmoncry SPECIES_MEOWTH, 0
# 176 "data/maps/SouthCampus/scripts.pory"
	waitmoncry
# 177 "data/maps/SouthCampus/scripts.pory"
	applymovement LOCALID_MEOWTH, SouthCampus_MeowthBattle_Movement_0
# 178 "data/maps/SouthCampus/scripts.pory"
	waitmovement 0
# 179 "data/maps/SouthCampus/scripts.pory"
	playse SE_M_SCRATCH
# 180 "data/maps/SouthCampus/scripts.pory"
	waitse
# 181 "data/maps/SouthCampus/scripts.pory"
	applymovement LOCALID_MEOWTH, SouthCampus_MeowthBattle_Movement_1
# 182 "data/maps/SouthCampus/scripts.pory"
	waitmovement 0
# 183 "data/maps/SouthCampus/scripts.pory"
	msgbox SouthCampus_MeowthBattle_Text_1
# 184 "data/maps/SouthCampus/scripts.pory"
	closemessage
# 185 "data/maps/SouthCampus/scripts.pory"
	playmoncry SPECIES_MEOWTH_ALOLA, 0
# 186 "data/maps/SouthCampus/scripts.pory"
	waitmoncry
# 187 "data/maps/SouthCampus/scripts.pory"
	applymovement LOCALID_MEOWTH_ALOLA, SouthCampus_MeowthBattle_Movement_2
# 188 "data/maps/SouthCampus/scripts.pory"
	waitmovement 0
# 189 "data/maps/SouthCampus/scripts.pory"
	playse SE_M_PAY_DAY
# 190 "data/maps/SouthCampus/scripts.pory"
	waitse
# 191 "data/maps/SouthCampus/scripts.pory"
	applymovement LOCALID_MEOWTH_ALOLA, SouthCampus_MeowthBattle_Movement_3
# 192 "data/maps/SouthCampus/scripts.pory"
	waitmovement 0
# 193 "data/maps/SouthCampus/scripts.pory"
	delay 40
# 194 "data/maps/SouthCampus/scripts.pory"
	playmoncry SPECIES_MEOWTH, CRY_MODE_FAINT
# 195 "data/maps/SouthCampus/scripts.pory"
	waitmoncry
# 196 "data/maps/SouthCampus/scripts.pory"
	playse SE_FAINT
# 197 "data/maps/SouthCampus/scripts.pory"
	applymovement LOCALID_MEOWTH, SouthCampus_MeowthBattle_Movement_4
# 198 "data/maps/SouthCampus/scripts.pory"
	waitmovement 0
# 199 "data/maps/SouthCampus/scripts.pory"
	hideobjectat LOCALID_MEOWTH, MAP_SOUTH_CAMPUS
# 200 "data/maps/SouthCampus/scripts.pory"
	removeobject LOCALID_MEOWTH
# 201 "data/maps/SouthCampus/scripts.pory"
	delay 40
# 202 "data/maps/SouthCampus/scripts.pory"
	fadedefaultbgm
# 203 "data/maps/SouthCampus/scripts.pory"
	applymovement LOCALID_MEOWTH_ALOLA, SouthCampus_MeowthBattle_Movement_4
# 204 "data/maps/SouthCampus/scripts.pory"
	waitmovement 0
# 205 "data/maps/SouthCampus/scripts.pory"
	hideobjectat LOCALID_MEOWTH_ALOLA, MAP_SOUTH_CAMPUS
# 206 "data/maps/SouthCampus/scripts.pory"
	removeobject LOCALID_MEOWTH_ALOLA
# 207 "data/maps/SouthCampus/scripts.pory"
	setflag FLAG_HIDE_MEOWTHS
# 208 "data/maps/SouthCampus/scripts.pory"
	msgbox SouthCampus_MeowthBattle_Text_2
# 209 "data/maps/SouthCampus/scripts.pory"
	closemessage
# 210 "data/maps/SouthCampus/scripts.pory"
	msgbox SouthCampus_MeowthBattle_Text_3
# 211 "data/maps/SouthCampus/scripts.pory"
	closemessage
# 212 "data/maps/SouthCampus/scripts.pory"
	applymovement LOCALID_LASS, SouthCampus_MeowthBattle_Movement_5
# 213 "data/maps/SouthCampus/scripts.pory"
	applymovement LOCALID_YOUNGSTER, SouthCampus_MeowthBattle_Movement_6
# 214 "data/maps/SouthCampus/scripts.pory"
	applymovement LOCALID_CAMERA, SouthCampus_ApproachBattle_Movement_1
# 215 "data/maps/SouthCampus/scripts.pory"
	delay 20
# 216 "data/maps/SouthCampus/scripts.pory"
	msgbox SouthCampus_MeowthBattle_Text_4
# 217 "data/maps/SouthCampus/scripts.pory"
	closemessage
# 218 "data/maps/SouthCampus/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SouthCampus_HearBattle_Movement_1
# 219 "data/maps/SouthCampus/scripts.pory"
	applymovement OBJ_EVENT_ID_NPC_FOLLOWER, SouthCampus_HearBattle2_Movement_1
# 220 "data/maps/SouthCampus/scripts.pory"
	playbgm MUS_ENCOUNTER_MAY, FALSE
# 221 "data/maps/SouthCampus/scripts.pory"
	msgbox SouthCampus_MeowthBattle_Text_5
# 222 "data/maps/SouthCampus/scripts.pory"
	closemessage
# 223 "data/maps/SouthCampus/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SouthCampus_MeowthBattle_Movement_7
# 224 "data/maps/SouthCampus/scripts.pory"
	applymovement OBJ_EVENT_ID_NPC_FOLLOWER, SouthCampus_MeowthBattle_Movement_8
# 225 "data/maps/SouthCampus/scripts.pory"
	applymovement LOCALID_CAMERA, SouthCampus_MeowthBattle_Movement_9
# 226 "data/maps/SouthCampus/scripts.pory"
	delay 90
# 227 "data/maps/SouthCampus/scripts.pory"
	msgbox SouthCampus_MeowthBattle_Text_6
# 228 "data/maps/SouthCampus/scripts.pory"
	closemessage
# 229 "data/maps/SouthCampus/scripts.pory"
	special RemoveCameraObject
# 230 "data/maps/SouthCampus/scripts.pory"
	removeobject LOCALID_CAMERA
# 231 "data/maps/SouthCampus/scripts.pory"
	setflag FLAG_HIDE_SOUTH_CAMPUS_TRAINERS
# 232 "data/maps/SouthCampus/scripts.pory"
	setflag FLAG_WHITEOUT_CONTINUE
# 233 "data/maps/SouthCampus/scripts.pory"
	trainerbattle_no_intro TRAINER_TRACIE_SOUTH_CAMPUS, SouthCampus_MeowthBattle_Text_7
# 234 "data/maps/SouthCampus/scripts.pory"
	clearflag FLAG_WHITEOUT_CONTINUE
# 235 "data/maps/SouthCampus/scripts.pory"
	call SouthCampus_TraciePostBattle
	return


SouthCampus_TraciePostBattle::
# 240 "data/maps/SouthCampus/scripts.pory"
	special SpawnCameraObject
# 241 "data/maps/SouthCampus/scripts.pory"
	hideobjectat LOCALID_LASS, MAP_SOUTH_CAMPUS
# 242 "data/maps/SouthCampus/scripts.pory"
	removeobject LOCALID_LASS
# 243 "data/maps/SouthCampus/scripts.pory"
	hideobjectat LOCALID_YOUNGSTER, MAP_SOUTH_CAMPUS
# 244 "data/maps/SouthCampus/scripts.pory"
	removeobject LOCALID_YOUNGSTER
# 245 "data/maps/SouthCampus/scripts.pory"
	setobjectxyperm LOCALID_CAMERA, 23, 26
# 246 "data/maps/SouthCampus/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SouthCampus_TraciePostBattle_Movement_0
# 247 "data/maps/SouthCampus/scripts.pory"
	applymovement OBJ_EVENT_ID_NPC_FOLLOWER, SouthCampus_TraciePostBattle_Movement_1
# 248 "data/maps/SouthCampus/scripts.pory"
	waitmovement 0
# 249 "data/maps/SouthCampus/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_LOST
	goto_if_eq SouthCampus_TraciePostBattle_2
# 256 "data/maps/SouthCampus/scripts.pory"
	msgbox SouthCampus_TraciePostBattle_Text_1
# 257 "data/maps/SouthCampus/scripts.pory"
	closemessage
# 258 "data/maps/SouthCampus/scripts.pory"
	call SouthCampus_HealParty
SouthCampus_TraciePostBattle_1:
# 260 "data/maps/SouthCampus/scripts.pory"
	msgbox SouthCampus_TraciePostBattle_Text_2
# 261 "data/maps/SouthCampus/scripts.pory"
	closemessage
# 262 "data/maps/SouthCampus/scripts.pory"
	applymovement OBJ_EVENT_ID_NPC_FOLLOWER, SouthCampus_TraciePostBattle_Movement_2
# 263 "data/maps/SouthCampus/scripts.pory"
	waitmovement 0
# 264 "data/maps/SouthCampus/scripts.pory"
	special RemoveCameraObject
# 265 "data/maps/SouthCampus/scripts.pory"
	removeobject LOCALID_CAMERA
# 266 "data/maps/SouthCampus/scripts.pory"
	destroyfollowernpc
# 267 "data/maps/SouthCampus/scripts.pory"
	setvar VAR_SOUTH_CAMPUS_STATE, 1
# 268 "data/maps/SouthCampus/scripts.pory"
	setrespawn HEAL_LOCATION_SOUTH_CAMPUS
# 269 "data/maps/SouthCampus/scripts.pory"
	fadedefaultbgm
# 270 "data/maps/SouthCampus/scripts.pory"
	release
	end

SouthCampus_TraciePostBattle_2:
# 250 "data/maps/SouthCampus/scripts.pory"
	msgbox SouthCampus_TraciePostBattle_Text_0
# 251 "data/maps/SouthCampus/scripts.pory"
	closemessage
# 252 "data/maps/SouthCampus/scripts.pory"
	call SouthCampus_HealParty
	goto SouthCampus_TraciePostBattle_1


SouthCampus_HealParty::
# 275 "data/maps/SouthCampus/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 276 "data/maps/SouthCampus/scripts.pory"
	playse SE_USE_ITEM
# 277 "data/maps/SouthCampus/scripts.pory"
	waitse
# 278 "data/maps/SouthCampus/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 279 "data/maps/SouthCampus/scripts.pory"
	special HealPlayerParty
	return


# 6 "data/maps/SouthCampus/scripts.pory"
SouthCampus_LockedCafeteria_Movement_0:
# 6 "data/maps/SouthCampus/scripts.pory"
	face_up
	step_end

# 9 "data/maps/SouthCampus/scripts.pory"
SouthCampus_LockedCafeteria_Movement_1:
# 9 "data/maps/SouthCampus/scripts.pory"
	walk_down
	step_end

# 16 "data/maps/SouthCampus/scripts.pory"
SouthCampus_MoveToBattle1_Movement_0:
# 16 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 16 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 16 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 16 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 16 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 16 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 16 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 16 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 16 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 16 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 16 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 16 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 16 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 16 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 16 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 16 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 16 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 16 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 16 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 16 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 16 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 16 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 16 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 16 "data/maps/SouthCampus/scripts.pory"
	face_up
	step_end

# 17 "data/maps/SouthCampus/scripts.pory"
SouthCampus_MoveToBattle1_Movement_1:
# 17 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 17 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 17 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 17 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 17 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 17 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 17 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 17 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 17 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 17 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 17 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 17 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 17 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 17 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 17 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 17 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 17 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 17 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 17 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 17 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 17 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 17 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 17 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 17 "data/maps/SouthCampus/scripts.pory"
	face_up
	step_end

# 24 "data/maps/SouthCampus/scripts.pory"
SouthCampus_MoveToBattle2_Movement_0:
# 24 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 24 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 24 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 24 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 24 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 24 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 24 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 24 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 24 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 24 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 24 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 24 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 24 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 24 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 24 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 24 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 24 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 24 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 24 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 24 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 24 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 24 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 24 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 24 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 24 "data/maps/SouthCampus/scripts.pory"
	face_up
	step_end

# 25 "data/maps/SouthCampus/scripts.pory"
SouthCampus_MoveToBattle2_Movement_1:
# 25 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 25 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 25 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 25 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 25 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 25 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 25 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 25 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 25 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 25 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 25 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 25 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 25 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 25 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 25 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 25 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 25 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 25 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 25 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 25 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 25 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 25 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 25 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 25 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 25 "data/maps/SouthCampus/scripts.pory"
	face_up
	step_end

# 32 "data/maps/SouthCampus/scripts.pory"
SouthCampus_MoveToBattle3_Movement_0:
# 32 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 32 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 32 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 32 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 32 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 32 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 32 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 32 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 32 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 32 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 32 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 32 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 32 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 32 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 32 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 32 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 32 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 32 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 32 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 32 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 32 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 32 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 32 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 32 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 32 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 32 "data/maps/SouthCampus/scripts.pory"
	face_up
	step_end

# 33 "data/maps/SouthCampus/scripts.pory"
SouthCampus_MoveToBattle3_Movement_1:
# 33 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 33 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 33 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 33 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 33 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 33 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 33 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 33 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 33 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 33 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 33 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 33 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 33 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 33 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 33 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 33 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 33 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 33 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 33 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 33 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 33 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 33 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 33 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 33 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 33 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 33 "data/maps/SouthCampus/scripts.pory"
	face_up
	step_end

# 40 "data/maps/SouthCampus/scripts.pory"
SouthCampus_MoveToBattle4_Movement_0:
# 40 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 40 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 40 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 40 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 40 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 40 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 40 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 40 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 40 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 40 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 40 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 40 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 40 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 40 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 40 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 40 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 40 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 40 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 40 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 40 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 40 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 40 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 40 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 40 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 40 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 40 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 40 "data/maps/SouthCampus/scripts.pory"
	face_up
	step_end

# 41 "data/maps/SouthCampus/scripts.pory"
SouthCampus_MoveToBattle4_Movement_1:
# 41 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 41 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 41 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 41 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 41 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 41 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 41 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 41 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 41 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 41 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 41 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 41 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 41 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 41 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 41 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 41 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 41 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 41 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 41 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 41 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 41 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 41 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 41 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 41 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 41 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 41 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 41 "data/maps/SouthCampus/scripts.pory"
	face_up
	step_end

# 48 "data/maps/SouthCampus/scripts.pory"
SouthCampus_MoveToBattle5_Movement_0:
# 48 "data/maps/SouthCampus/scripts.pory"
	face_down
	step_end

# 49 "data/maps/SouthCampus/scripts.pory"
SouthCampus_MoveToBattle5_Movement_1:
# 49 "data/maps/SouthCampus/scripts.pory"
	walk_fast_down
# 49 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
	step_end

# 51 "data/maps/SouthCampus/scripts.pory"
SouthCampus_MoveToBattle5_Movement_2:
# 51 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 51 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 51 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 51 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 51 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 51 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 51 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 51 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 51 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 51 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 51 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 51 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 51 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 51 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 51 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 51 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 51 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 51 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 51 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 51 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 51 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 51 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 51 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 51 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 51 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 51 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 51 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 51 "data/maps/SouthCampus/scripts.pory"
	face_up
	step_end

# 52 "data/maps/SouthCampus/scripts.pory"
SouthCampus_MoveToBattle5_Movement_3:
# 52 "data/maps/SouthCampus/scripts.pory"
	walk_fast_down
# 52 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 52 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 52 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 52 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 52 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 52 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 52 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 52 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 52 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 52 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 52 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 52 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 52 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 52 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 52 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 52 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 52 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 52 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 52 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 52 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 52 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 52 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 52 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 52 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 52 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 52 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 52 "data/maps/SouthCampus/scripts.pory"
	face_up
	step_end

# 60 "data/maps/SouthCampus/scripts.pory"
SouthCampus_MoveToBattle6_Movement_0:
# 60 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 60 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
	step_end

# 62 "data/maps/SouthCampus/scripts.pory"
SouthCampus_MoveToBattle6_Movement_1:
# 62 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 62 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 62 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 62 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 62 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 62 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 62 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 62 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 62 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 62 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 62 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 62 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 62 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 62 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 62 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 62 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 62 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 62 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 62 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 62 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 62 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 62 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 62 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 62 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 62 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 62 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 62 "data/maps/SouthCampus/scripts.pory"
	face_up
	step_end

# 63 "data/maps/SouthCampus/scripts.pory"
SouthCampus_MoveToBattle6_Movement_2:
# 63 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 63 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 63 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 63 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 63 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 63 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 63 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 63 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 63 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 63 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 63 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 63 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 63 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 63 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 63 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 63 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 63 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 63 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 63 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 63 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 63 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 63 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 63 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 63 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 63 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 63 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 63 "data/maps/SouthCampus/scripts.pory"
	face_up
	step_end

# 74 "data/maps/SouthCampus/scripts.pory"
SouthCampus_MoveToBattle7_Movement_0:
# 74 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 74 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 74 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 74 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 74 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 74 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 74 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 74 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 74 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 74 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 74 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 74 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 74 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 74 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 74 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 74 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 74 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 74 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 74 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 74 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 74 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 74 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 74 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 74 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 74 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 74 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 74 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 74 "data/maps/SouthCampus/scripts.pory"
	face_up
	step_end

# 84 "data/maps/SouthCampus/scripts.pory"
SouthCampus_MoveToBattle8_Movement_0:
# 84 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 84 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 84 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 84 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 84 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 84 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 84 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 84 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 84 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 84 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 84 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 84 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 84 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 84 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 84 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 84 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 84 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 84 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 84 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 84 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 84 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 84 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 84 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 84 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 84 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 84 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 84 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 84 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 84 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 84 "data/maps/SouthCampus/scripts.pory"
	face_up
	step_end

# 85 "data/maps/SouthCampus/scripts.pory"
SouthCampus_MoveToBattle8_Movement_1:
# 85 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 85 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 85 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 85 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 85 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 85 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 85 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 85 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 85 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 85 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 85 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 85 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 85 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 85 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 85 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 85 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 85 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 85 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 85 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 85 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 85 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 85 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 85 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 85 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 85 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 85 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 85 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 85 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 85 "data/maps/SouthCampus/scripts.pory"
	walk_fast_left
# 85 "data/maps/SouthCampus/scripts.pory"
	face_up
	step_end

# 98 "data/maps/SouthCampus/scripts.pory"
SouthCampus_HearBattle_Movement_0:
# 98 "data/maps/SouthCampus/scripts.pory"
	emote_exclamation_mark
	step_end

# 101 "data/maps/SouthCampus/scripts.pory"
SouthCampus_HearBattle_Movement_1:
# 101 "data/maps/SouthCampus/scripts.pory"
	face_right
	step_end

# 103 "data/maps/SouthCampus/scripts.pory"
SouthCampus_HearBattle_Movement_2:
# 103 "data/maps/SouthCampus/scripts.pory"
	jump_in_place_left
	step_end

# 122 "data/maps/SouthCampus/scripts.pory"
SouthCampus_HearBattle2_Movement_0:
# 122 "data/maps/SouthCampus/scripts.pory"
	face_left
# 122 "data/maps/SouthCampus/scripts.pory"
	emote_exclamation_mark
	step_end

# 125 "data/maps/SouthCampus/scripts.pory"
SouthCampus_HearBattle2_Movement_1:
# 125 "data/maps/SouthCampus/scripts.pory"
	face_left
	step_end

# 146 "data/maps/SouthCampus/scripts.pory"
SouthCampus_ApproachBattle_Movement_0:
# 146 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 146 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 146 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
	step_end

# 152 "data/maps/SouthCampus/scripts.pory"
SouthCampus_ApproachBattle_Movement_1:
# 152 "data/maps/SouthCampus/scripts.pory"
	walk_fast_down
# 152 "data/maps/SouthCampus/scripts.pory"
	walk_fast_down
# 152 "data/maps/SouthCampus/scripts.pory"
	walk_fast_down
	step_end

# 177 "data/maps/SouthCampus/scripts.pory"
SouthCampus_MeowthBattle_Movement_0:
# 177 "data/maps/SouthCampus/scripts.pory"
	slide_right
# 177 "data/maps/SouthCampus/scripts.pory"
	slide_right
	step_end

# 181 "data/maps/SouthCampus/scripts.pory"
SouthCampus_MeowthBattle_Movement_1:
# 181 "data/maps/SouthCampus/scripts.pory"
	slide_left
# 181 "data/maps/SouthCampus/scripts.pory"
	slide_left
# 181 "data/maps/SouthCampus/scripts.pory"
	face_right
	step_end

# 187 "data/maps/SouthCampus/scripts.pory"
SouthCampus_MeowthBattle_Movement_2:
# 187 "data/maps/SouthCampus/scripts.pory"
	slide_left
# 187 "data/maps/SouthCampus/scripts.pory"
	slide_left
	step_end

# 191 "data/maps/SouthCampus/scripts.pory"
SouthCampus_MeowthBattle_Movement_3:
# 191 "data/maps/SouthCampus/scripts.pory"
	slide_right
# 191 "data/maps/SouthCampus/scripts.pory"
	slide_right
# 191 "data/maps/SouthCampus/scripts.pory"
	face_left
	step_end

# 197 "data/maps/SouthCampus/scripts.pory"
SouthCampus_MeowthBattle_Movement_4:
# 197 "data/maps/SouthCampus/scripts.pory"
	enter_pokeball
	step_end

# 212 "data/maps/SouthCampus/scripts.pory"
SouthCampus_MeowthBattle_Movement_5:
# 212 "data/maps/SouthCampus/scripts.pory"
	walk_right
# 212 "data/maps/SouthCampus/scripts.pory"
	walk_right
# 212 "data/maps/SouthCampus/scripts.pory"
	walk_right
# 212 "data/maps/SouthCampus/scripts.pory"
	walk_right
# 212 "data/maps/SouthCampus/scripts.pory"
	walk_right
	step_end

# 213 "data/maps/SouthCampus/scripts.pory"
SouthCampus_MeowthBattle_Movement_6:
# 213 "data/maps/SouthCampus/scripts.pory"
	walk_right
# 213 "data/maps/SouthCampus/scripts.pory"
	walk_right
# 213 "data/maps/SouthCampus/scripts.pory"
	walk_right
# 213 "data/maps/SouthCampus/scripts.pory"
	walk_right
# 213 "data/maps/SouthCampus/scripts.pory"
	walk_right
# 213 "data/maps/SouthCampus/scripts.pory"
	walk_right
# 213 "data/maps/SouthCampus/scripts.pory"
	walk_right
# 213 "data/maps/SouthCampus/scripts.pory"
	walk_right
# 213 "data/maps/SouthCampus/scripts.pory"
	walk_right
# 213 "data/maps/SouthCampus/scripts.pory"
	walk_right
# 213 "data/maps/SouthCampus/scripts.pory"
	walk_right
# 213 "data/maps/SouthCampus/scripts.pory"
	walk_right
	step_end

# 223 "data/maps/SouthCampus/scripts.pory"
SouthCampus_MeowthBattle_Movement_7:
# 223 "data/maps/SouthCampus/scripts.pory"
	walk_up
# 223 "data/maps/SouthCampus/scripts.pory"
	walk_up
# 223 "data/maps/SouthCampus/scripts.pory"
	walk_up
# 223 "data/maps/SouthCampus/scripts.pory"
	walk_left
# 223 "data/maps/SouthCampus/scripts.pory"
	walk_left
# 223 "data/maps/SouthCampus/scripts.pory"
	walk_left
# 223 "data/maps/SouthCampus/scripts.pory"
	face_right
	step_end

# 224 "data/maps/SouthCampus/scripts.pory"
SouthCampus_MeowthBattle_Movement_8:
# 224 "data/maps/SouthCampus/scripts.pory"
	walk_up
# 224 "data/maps/SouthCampus/scripts.pory"
	walk_up
# 224 "data/maps/SouthCampus/scripts.pory"
	walk_up
# 224 "data/maps/SouthCampus/scripts.pory"
	walk_right
# 224 "data/maps/SouthCampus/scripts.pory"
	walk_right
# 224 "data/maps/SouthCampus/scripts.pory"
	walk_right
# 224 "data/maps/SouthCampus/scripts.pory"
	face_left
	step_end

# 225 "data/maps/SouthCampus/scripts.pory"
SouthCampus_MeowthBattle_Movement_9:
# 225 "data/maps/SouthCampus/scripts.pory"
	walk_up
# 225 "data/maps/SouthCampus/scripts.pory"
	walk_up
# 225 "data/maps/SouthCampus/scripts.pory"
	walk_up
	step_end

# 246 "data/maps/SouthCampus/scripts.pory"
SouthCampus_TraciePostBattle_Movement_0:
# 246 "data/maps/SouthCampus/scripts.pory"
	walk_right
# 246 "data/maps/SouthCampus/scripts.pory"
	walk_right
# 246 "data/maps/SouthCampus/scripts.pory"
	walk_right
	step_end

# 247 "data/maps/SouthCampus/scripts.pory"
SouthCampus_TraciePostBattle_Movement_1:
# 247 "data/maps/SouthCampus/scripts.pory"
	walk_left
# 247 "data/maps/SouthCampus/scripts.pory"
	walk_left
# 247 "data/maps/SouthCampus/scripts.pory"
	walk_left
	step_end

# 262 "data/maps/SouthCampus/scripts.pory"
SouthCampus_TraciePostBattle_Movement_2:
# 262 "data/maps/SouthCampus/scripts.pory"
	walk_right
# 262 "data/maps/SouthCampus/scripts.pory"
	walk_right
# 262 "data/maps/SouthCampus/scripts.pory"
	walk_right
# 262 "data/maps/SouthCampus/scripts.pory"
	walk_right
# 262 "data/maps/SouthCampus/scripts.pory"
	walk_right
# 262 "data/maps/SouthCampus/scripts.pory"
	walk_right
# 262 "data/maps/SouthCampus/scripts.pory"
	walk_right
# 262 "data/maps/SouthCampus/scripts.pory"
	walk_right
	step_end

SouthCampus_LockedCafeteria_Text_0:
# 7 "data/maps/SouthCampus/scripts.pory"
	.string "The cafeteria isn't open.$"

SouthCampus_HearBattle_Text_0:
# 93 "data/maps/SouthCampus/scripts.pory"
	.string "Go, Meowth!$"

SouthCampus_HearBattle_Text_1:
# 109 "data/maps/SouthCampus/scripts.pory"
	.string "{PLAYER}, did you hear that?\p"
	.string "It sounds like a Pokémon battle\n"
	.string "just started!\p"
	.string "Let's check it out!$"

SouthCampus_ApproachBattle_Text_0:
# 141 "data/maps/SouthCampus/scripts.pory"
	.string "I knew it!\n"
	.string "They're having a battle!$"

SouthCampus_ApproachBattle_Text_1:
# 148 "data/maps/SouthCampus/scripts.pory"
	.string "My Meowth is way stronger!\n"
	.string "He's going to win for sure!$"

SouthCampus_ApproachBattle_Text_2:
# 150 "data/maps/SouthCampus/scripts.pory"
	.string "Don't get overconfident.\p"
	.string "I'll bet you've never seen a\n"
	.string "Meowth like mine before!$"

SouthCampus_ApproachBattle_Text_3:
# 154 "data/maps/SouthCampus/scripts.pory"
	.string "I've never seen a Meowth like her's\n"
	.string "before, either.\p"
	.string "I wonder why it looks so different…$"

SouthCampus_ApproachBattle_Text_4:
# 160 "data/maps/SouthCampus/scripts.pory"
	.string "Some Pokémon come in different\n"
	.string "varieties depending on their habitat.\p"
	.string "Her Meowth is a Dark-type and his is a\n"
	.string "Normal-type.\p"
	.string "Neither Meowth has a type advantage\n"
	.string "against the other, so it's been a good\l"
	.string "battle so far!$"

SouthCampus_ApproachBattle_Text_5:
# 162 "data/maps/SouthCampus/scripts.pory"
	.string "Oh, that makes sense!\p"
	.string "It's so neat that Pokémon of the same\n"
	.string "species can be different types!$"

SouthCampus_MeowthBattle_Text_0:
# 173 "data/maps/SouthCampus/scripts.pory"
	.string "Meowth, use Scratch!$"

SouthCampus_MeowthBattle_Text_1:
# 183 "data/maps/SouthCampus/scripts.pory"
	.string "Meowth, use Pay Day!$"

SouthCampus_MeowthBattle_Text_2:
# 208 "data/maps/SouthCampus/scripts.pory"
	.string "Aww, darn!\n"
	.string "Oh well.\p"
	.string "Can't win them all.\n"
	.string "Thanks for the battle!$"

SouthCampus_MeowthBattle_Text_3:
# 210 "data/maps/SouthCampus/scripts.pory"
	.string "Same to you!\n"
	.string "It was fun!$"

SouthCampus_MeowthBattle_Text_4:
# 216 "data/maps/SouthCampus/scripts.pory"
	.string "That was such a great battle!\n"
	.string "I'm all fired up!$"

SouthCampus_MeowthBattle_Text_5:
# 221 "data/maps/SouthCampus/scripts.pory"
	.string "Hey!\n"
	.string "Let's have a battle!\p"
	.string "It'll be the first battle of our final\n"
	.string "year of school, and I can't think of\l"
	.string "anyone better to have it with!$"

SouthCampus_MeowthBattle_Text_6:
# 227 "data/maps/SouthCampus/scripts.pory"
	.string "Alright, here we go.\n"
	.string "No holding back!$"

SouthCampus_MeowthBattle_Text_7:
# 233 "data/maps/SouthCampus/scripts.pory"
	.string "Looks like I still have some\n"
	.string "catching up to do!$"

SouthCampus_TraciePostBattle_Text_0:
# 250 "data/maps/SouthCampus/scripts.pory"
	.string "Thanks for the battle!\p"
	.string "But, I could tell you were\n"
	.string "holding back!\p"
	.string "You better not do that again!\p"
	.string "I can't wait to battle again once our\n"
	.string "journeys start!\p"
	.string "Let me heal your Pokémon quick!$"

SouthCampus_TraciePostBattle_Text_1:
# 256 "data/maps/SouthCampus/scripts.pory"
	.string "That was so much fun!\p"
	.string "I can't wait to battle again once our\n"
	.string "journeys start!\p"
	.string "Let me heal your Pokémon quick!$"

SouthCampus_TraciePostBattle_Text_2:
# 260 "data/maps/SouthCampus/scripts.pory"
	.string "I'm going to go on ahead to North\n"
	.string "Campus for orientation.\p"
	.string "Try not to take too long getting there.\n"
	.string "You don't want to be late!\p"
	.string "See you soon!$"
