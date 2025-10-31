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
	speakername Unknown
# 94 "data/maps/SouthCampus/scripts.pory"
	msgbox SouthCampus_HearBattle_Text_0
# 95 "data/maps/SouthCampus/scripts.pory"
	playmoncry SPECIES_MEOWTH, 0
# 96 "data/maps/SouthCampus/scripts.pory"
	waitmoncry
# 97 "data/maps/SouthCampus/scripts.pory"
	delay 10
# 98 "data/maps/SouthCampus/scripts.pory"
	closemessage
# 99 "data/maps/SouthCampus/scripts.pory"
	applymovement OBJ_EVENT_ID_NPC_FOLLOWER, SouthCampus_HearBattle_Movement_0
# 100 "data/maps/SouthCampus/scripts.pory"
	playse SE_PIN
# 101 "data/maps/SouthCampus/scripts.pory"
	waitse
# 102 "data/maps/SouthCampus/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SouthCampus_HearBattle_Movement_1
# 103 "data/maps/SouthCampus/scripts.pory"
	waitmovement 0
# 104 "data/maps/SouthCampus/scripts.pory"
	applymovement OBJ_EVENT_ID_NPC_FOLLOWER, SouthCampus_HearBattle_Movement_2
# 105 "data/maps/SouthCampus/scripts.pory"
	playse SE_LEDGE
# 106 "data/maps/SouthCampus/scripts.pory"
	waitmovement 0
# 107 "data/maps/SouthCampus/scripts.pory"
	applymovement OBJ_EVENT_ID_NPC_FOLLOWER, SouthCampus_HearBattle_Movement_2
# 108 "data/maps/SouthCampus/scripts.pory"
	playse SE_LEDGE
# 109 "data/maps/SouthCampus/scripts.pory"
	waitmovement 0
# 110 "data/maps/SouthCampus/scripts.pory"
	speakername Tracie
# 111 "data/maps/SouthCampus/scripts.pory"
	msgbox SouthCampus_HearBattle_Text_1
# 112 "data/maps/SouthCampus/scripts.pory"
	closemessage
	return


SouthCampus_HearBattle2::
# 117 "data/maps/SouthCampus/scripts.pory"
	lock
# 118 "data/maps/SouthCampus/scripts.pory"
	applymovement LOCALID_FAT_MAN, SouthCampus_LockedCafeteria_Movement_0
# 119 "data/maps/SouthCampus/scripts.pory"
	speakername Unknown
# 120 "data/maps/SouthCampus/scripts.pory"
	msgbox SouthCampus_HearBattle_Text_0
# 121 "data/maps/SouthCampus/scripts.pory"
	playmoncry SPECIES_MEOWTH, 0
# 122 "data/maps/SouthCampus/scripts.pory"
	waitmoncry
# 123 "data/maps/SouthCampus/scripts.pory"
	delay 10
# 124 "data/maps/SouthCampus/scripts.pory"
	closemessage
# 125 "data/maps/SouthCampus/scripts.pory"
	applymovement OBJ_EVENT_ID_NPC_FOLLOWER, SouthCampus_HearBattle2_Movement_0
# 126 "data/maps/SouthCampus/scripts.pory"
	playse SE_PIN
# 127 "data/maps/SouthCampus/scripts.pory"
	waitse
# 128 "data/maps/SouthCampus/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SouthCampus_HearBattle2_Movement_1
# 129 "data/maps/SouthCampus/scripts.pory"
	waitmovement 0
# 130 "data/maps/SouthCampus/scripts.pory"
	applymovement OBJ_EVENT_ID_NPC_FOLLOWER, SouthCampus_HearBattle_Movement_2
# 131 "data/maps/SouthCampus/scripts.pory"
	playse SE_LEDGE
# 132 "data/maps/SouthCampus/scripts.pory"
	waitmovement 0
# 133 "data/maps/SouthCampus/scripts.pory"
	applymovement OBJ_EVENT_ID_NPC_FOLLOWER, SouthCampus_HearBattle_Movement_2
# 134 "data/maps/SouthCampus/scripts.pory"
	playse SE_LEDGE
# 135 "data/maps/SouthCampus/scripts.pory"
	waitmovement 0
# 136 "data/maps/SouthCampus/scripts.pory"
	speakername Tracie
# 137 "data/maps/SouthCampus/scripts.pory"
	msgbox SouthCampus_HearBattle_Text_1
# 138 "data/maps/SouthCampus/scripts.pory"
	closemessage
	return


SouthCampus_ApproachBattle::
# 145 "data/maps/SouthCampus/scripts.pory"
	speakername Tracie
# 146 "data/maps/SouthCampus/scripts.pory"
	msgbox SouthCampus_ApproachBattle_Text_0
# 147 "data/maps/SouthCampus/scripts.pory"
	closemessage
# 148 "data/maps/SouthCampus/scripts.pory"
	special SpawnCameraObject
# 149 "data/maps/SouthCampus/scripts.pory"
	setobjectxy LOCALID_CAMERA, 23, 29
# 150 "data/maps/SouthCampus/scripts.pory"
	playbgm CUS_VS_TRAINER, FALSE
# 151 "data/maps/SouthCampus/scripts.pory"
	applymovement LOCALID_CAMERA, SouthCampus_ApproachBattle_Movement_0
# 152 "data/maps/SouthCampus/scripts.pory"
	waitmovement 0
# 153 "data/maps/SouthCampus/scripts.pory"
	speakername SouthCampus_ApproachBattle_Text_1
# 154 "data/maps/SouthCampus/scripts.pory"
	msgbox SouthCampus_ApproachBattle_Text_2
# 155 "data/maps/SouthCampus/scripts.pory"
	closemessage
# 156 "data/maps/SouthCampus/scripts.pory"
	speakername SouthCampus_ApproachBattle_Text_3
# 157 "data/maps/SouthCampus/scripts.pory"
	msgbox SouthCampus_ApproachBattle_Text_4
# 158 "data/maps/SouthCampus/scripts.pory"
	closemessage
# 159 "data/maps/SouthCampus/scripts.pory"
	applymovement LOCALID_CAMERA, SouthCampus_ApproachBattle_Movement_1
# 160 "data/maps/SouthCampus/scripts.pory"
	waitmovement 0
# 161 "data/maps/SouthCampus/scripts.pory"
	speakername Tracie
# 162 "data/maps/SouthCampus/scripts.pory"
	msgbox SouthCampus_ApproachBattle_Text_5
# 163 "data/maps/SouthCampus/scripts.pory"
	closemessage
# 164 "data/maps/SouthCampus/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SouthCampus_HearBattle2_Movement_1
# 165 "data/maps/SouthCampus/scripts.pory"
	applymovement OBJ_EVENT_ID_NPC_FOLLOWER, SouthCampus_HearBattle2_Movement_1
# 166 "data/maps/SouthCampus/scripts.pory"
	applymovement LOCALID_FAT_MAN, SouthCampus_HearBattle_Movement_1
# 167 "data/maps/SouthCampus/scripts.pory"
	waitmovement 0
# 168 "data/maps/SouthCampus/scripts.pory"
	speakername SouthCampus_ApproachBattle_Text_6
# 169 "data/maps/SouthCampus/scripts.pory"
	msgbox SouthCampus_ApproachBattle_Text_7
# 170 "data/maps/SouthCampus/scripts.pory"
	closemessage
# 171 "data/maps/SouthCampus/scripts.pory"
	speakername Tracie
# 172 "data/maps/SouthCampus/scripts.pory"
	msgbox SouthCampus_ApproachBattle_Text_8
# 173 "data/maps/SouthCampus/scripts.pory"
	closemessage
# 174 "data/maps/SouthCampus/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SouthCampus_LockedCafeteria_Movement_0
# 175 "data/maps/SouthCampus/scripts.pory"
	applymovement OBJ_EVENT_ID_NPC_FOLLOWER, SouthCampus_LockedCafeteria_Movement_0
# 176 "data/maps/SouthCampus/scripts.pory"
	applymovement LOCALID_FAT_MAN, SouthCampus_LockedCafeteria_Movement_0
# 177 "data/maps/SouthCampus/scripts.pory"
	applymovement LOCALID_CAMERA, SouthCampus_ApproachBattle_Movement_0
# 178 "data/maps/SouthCampus/scripts.pory"
	waitmovement 0
# 179 "data/maps/SouthCampus/scripts.pory"
	call SouthCampus_MeowthBattle
	return


SouthCampus_MeowthBattle::
# 183 "data/maps/SouthCampus/scripts.pory"
	speakername SouthCampus_ApproachBattle_Text_1
# 184 "data/maps/SouthCampus/scripts.pory"
	msgbox SouthCampus_MeowthBattle_Text_0
# 185 "data/maps/SouthCampus/scripts.pory"
	closemessage
# 186 "data/maps/SouthCampus/scripts.pory"
	playmoncry SPECIES_MEOWTH, 0
# 187 "data/maps/SouthCampus/scripts.pory"
	waitmoncry
# 188 "data/maps/SouthCampus/scripts.pory"
	applymovement LOCALID_MEOWTH, SouthCampus_MeowthBattle_Movement_0
# 189 "data/maps/SouthCampus/scripts.pory"
	waitmovement 0
# 190 "data/maps/SouthCampus/scripts.pory"
	playse SE_M_SCRATCH
# 191 "data/maps/SouthCampus/scripts.pory"
	waitse
# 192 "data/maps/SouthCampus/scripts.pory"
	applymovement LOCALID_MEOWTH, SouthCampus_MeowthBattle_Movement_1
# 193 "data/maps/SouthCampus/scripts.pory"
	waitmovement 0
# 194 "data/maps/SouthCampus/scripts.pory"
	speakername SouthCampus_ApproachBattle_Text_3
# 195 "data/maps/SouthCampus/scripts.pory"
	msgbox SouthCampus_MeowthBattle_Text_1
# 196 "data/maps/SouthCampus/scripts.pory"
	closemessage
# 197 "data/maps/SouthCampus/scripts.pory"
	playmoncry SPECIES_MEOWTH_ALOLA, 0
# 198 "data/maps/SouthCampus/scripts.pory"
	waitmoncry
# 199 "data/maps/SouthCampus/scripts.pory"
	applymovement LOCALID_MEOWTH_ALOLA, SouthCampus_MeowthBattle_Movement_2
# 200 "data/maps/SouthCampus/scripts.pory"
	waitmovement 0
# 201 "data/maps/SouthCampus/scripts.pory"
	playse SE_M_PAY_DAY
# 202 "data/maps/SouthCampus/scripts.pory"
	waitse
# 203 "data/maps/SouthCampus/scripts.pory"
	applymovement LOCALID_MEOWTH_ALOLA, SouthCampus_MeowthBattle_Movement_3
# 204 "data/maps/SouthCampus/scripts.pory"
	waitmovement 0
# 205 "data/maps/SouthCampus/scripts.pory"
	delay 40
# 206 "data/maps/SouthCampus/scripts.pory"
	playmoncry SPECIES_MEOWTH, CRY_MODE_FAINT
# 207 "data/maps/SouthCampus/scripts.pory"
	waitmoncry
# 208 "data/maps/SouthCampus/scripts.pory"
	playse SE_FAINT
# 209 "data/maps/SouthCampus/scripts.pory"
	applymovement LOCALID_MEOWTH, SouthCampus_MeowthBattle_Movement_4
# 210 "data/maps/SouthCampus/scripts.pory"
	waitmovement 0
# 211 "data/maps/SouthCampus/scripts.pory"
	hideobjectat LOCALID_MEOWTH, MAP_SOUTH_CAMPUS
# 212 "data/maps/SouthCampus/scripts.pory"
	removeobject LOCALID_MEOWTH
# 213 "data/maps/SouthCampus/scripts.pory"
	delay 40
# 214 "data/maps/SouthCampus/scripts.pory"
	fadedefaultbgm
# 215 "data/maps/SouthCampus/scripts.pory"
	applymovement LOCALID_MEOWTH_ALOLA, SouthCampus_MeowthBattle_Movement_4
# 216 "data/maps/SouthCampus/scripts.pory"
	waitmovement 0
# 217 "data/maps/SouthCampus/scripts.pory"
	hideobjectat LOCALID_MEOWTH_ALOLA, MAP_SOUTH_CAMPUS
# 218 "data/maps/SouthCampus/scripts.pory"
	removeobject LOCALID_MEOWTH_ALOLA
# 219 "data/maps/SouthCampus/scripts.pory"
	setflag FLAG_HIDE_MEOWTHS
# 220 "data/maps/SouthCampus/scripts.pory"
	speakername SouthCampus_ApproachBattle_Text_1
# 221 "data/maps/SouthCampus/scripts.pory"
	msgbox SouthCampus_MeowthBattle_Text_2
# 222 "data/maps/SouthCampus/scripts.pory"
	closemessage
# 223 "data/maps/SouthCampus/scripts.pory"
	speakername SouthCampus_ApproachBattle_Text_3
# 224 "data/maps/SouthCampus/scripts.pory"
	msgbox SouthCampus_MeowthBattle_Text_3
# 225 "data/maps/SouthCampus/scripts.pory"
	closemessage
# 226 "data/maps/SouthCampus/scripts.pory"
	applymovement LOCALID_LASS, SouthCampus_MeowthBattle_Movement_5
# 227 "data/maps/SouthCampus/scripts.pory"
	applymovement LOCALID_YOUNGSTER, SouthCampus_MeowthBattle_Movement_6
# 228 "data/maps/SouthCampus/scripts.pory"
	applymovement LOCALID_CAMERA, SouthCampus_ApproachBattle_Movement_1
# 229 "data/maps/SouthCampus/scripts.pory"
	delay 20
# 230 "data/maps/SouthCampus/scripts.pory"
	speakername Tracie
# 231 "data/maps/SouthCampus/scripts.pory"
	msgbox SouthCampus_MeowthBattle_Text_4
# 232 "data/maps/SouthCampus/scripts.pory"
	closemessage
# 233 "data/maps/SouthCampus/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SouthCampus_HearBattle_Movement_1
# 234 "data/maps/SouthCampus/scripts.pory"
	applymovement OBJ_EVENT_ID_NPC_FOLLOWER, SouthCampus_HearBattle2_Movement_1
# 235 "data/maps/SouthCampus/scripts.pory"
	playbgm MUS_ENCOUNTER_MAY, FALSE
# 236 "data/maps/SouthCampus/scripts.pory"
	speakername Tracie
# 237 "data/maps/SouthCampus/scripts.pory"
	msgbox SouthCampus_MeowthBattle_Text_5
# 238 "data/maps/SouthCampus/scripts.pory"
	closemessage
# 239 "data/maps/SouthCampus/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SouthCampus_MeowthBattle_Movement_7
# 240 "data/maps/SouthCampus/scripts.pory"
	applymovement OBJ_EVENT_ID_NPC_FOLLOWER, SouthCampus_MeowthBattle_Movement_8
# 241 "data/maps/SouthCampus/scripts.pory"
	applymovement LOCALID_CAMERA, SouthCampus_MeowthBattle_Movement_9
# 242 "data/maps/SouthCampus/scripts.pory"
	delay 90
# 243 "data/maps/SouthCampus/scripts.pory"
	speakername Tracie
# 244 "data/maps/SouthCampus/scripts.pory"
	msgbox SouthCampus_MeowthBattle_Text_6
# 245 "data/maps/SouthCampus/scripts.pory"
	closemessage
# 246 "data/maps/SouthCampus/scripts.pory"
	special RemoveCameraObject
# 247 "data/maps/SouthCampus/scripts.pory"
	removeobject LOCALID_CAMERA
# 248 "data/maps/SouthCampus/scripts.pory"
	setflag FLAG_HIDE_SOUTH_CAMPUS_TRAINERS
# 249 "data/maps/SouthCampus/scripts.pory"
	setflag FLAG_WHITEOUT_CONTINUE
# 250 "data/maps/SouthCampus/scripts.pory"
	trainerbattle_no_intro TRAINER_TRACIE_SOUTH_CAMPUS, SouthCampus_MeowthBattle_Text_7
# 251 "data/maps/SouthCampus/scripts.pory"
	clearflag FLAG_WHITEOUT_CONTINUE
# 252 "data/maps/SouthCampus/scripts.pory"
	call SouthCampus_TraciePostBattle
	return


SouthCampus_TraciePostBattle::
# 257 "data/maps/SouthCampus/scripts.pory"
	special SpawnCameraObject
# 258 "data/maps/SouthCampus/scripts.pory"
	hideobjectat LOCALID_LASS, MAP_SOUTH_CAMPUS
# 259 "data/maps/SouthCampus/scripts.pory"
	removeobject LOCALID_LASS
# 260 "data/maps/SouthCampus/scripts.pory"
	hideobjectat LOCALID_YOUNGSTER, MAP_SOUTH_CAMPUS
# 261 "data/maps/SouthCampus/scripts.pory"
	removeobject LOCALID_YOUNGSTER
# 262 "data/maps/SouthCampus/scripts.pory"
	setobjectxyperm LOCALID_CAMERA, 23, 26
# 263 "data/maps/SouthCampus/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SouthCampus_TraciePostBattle_Movement_0
# 264 "data/maps/SouthCampus/scripts.pory"
	applymovement OBJ_EVENT_ID_NPC_FOLLOWER, SouthCampus_TraciePostBattle_Movement_1
# 265 "data/maps/SouthCampus/scripts.pory"
	waitmovement 0
# 266 "data/maps/SouthCampus/scripts.pory"
	speakername Tracie
# 267 "data/maps/SouthCampus/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_LOST
	goto_if_eq SouthCampus_TraciePostBattle_2
# 274 "data/maps/SouthCampus/scripts.pory"
	msgbox SouthCampus_TraciePostBattle_Text_1
# 275 "data/maps/SouthCampus/scripts.pory"
	closemessage
# 276 "data/maps/SouthCampus/scripts.pory"
	call SouthCampus_HealParty
SouthCampus_TraciePostBattle_1:
# 278 "data/maps/SouthCampus/scripts.pory"
	speakername Tracie
# 279 "data/maps/SouthCampus/scripts.pory"
	msgbox SouthCampus_TraciePostBattle_Text_2
# 280 "data/maps/SouthCampus/scripts.pory"
	closemessage
# 281 "data/maps/SouthCampus/scripts.pory"
	applymovement OBJ_EVENT_ID_NPC_FOLLOWER, SouthCampus_TraciePostBattle_Movement_2
# 282 "data/maps/SouthCampus/scripts.pory"
	waitmovement 0
# 283 "data/maps/SouthCampus/scripts.pory"
	special RemoveCameraObject
# 284 "data/maps/SouthCampus/scripts.pory"
	removeobject LOCALID_CAMERA
# 285 "data/maps/SouthCampus/scripts.pory"
	destroyfollowernpc
# 286 "data/maps/SouthCampus/scripts.pory"
	setvar VAR_SOUTH_CAMPUS_STATE, 1
# 287 "data/maps/SouthCampus/scripts.pory"
	setrespawn HEAL_LOCATION_SOUTH_CAMPUS
# 288 "data/maps/SouthCampus/scripts.pory"
	fadedefaultbgm
# 289 "data/maps/SouthCampus/scripts.pory"
	release
	end

SouthCampus_TraciePostBattle_2:
# 268 "data/maps/SouthCampus/scripts.pory"
	msgbox SouthCampus_TraciePostBattle_Text_0
# 269 "data/maps/SouthCampus/scripts.pory"
	closemessage
# 270 "data/maps/SouthCampus/scripts.pory"
	call SouthCampus_HealParty
	goto SouthCampus_TraciePostBattle_1


SouthCampus_HealParty::
# 294 "data/maps/SouthCampus/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 295 "data/maps/SouthCampus/scripts.pory"
	playse SE_USE_ITEM
# 296 "data/maps/SouthCampus/scripts.pory"
	waitse
# 297 "data/maps/SouthCampus/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 298 "data/maps/SouthCampus/scripts.pory"
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

# 99 "data/maps/SouthCampus/scripts.pory"
SouthCampus_HearBattle_Movement_0:
# 99 "data/maps/SouthCampus/scripts.pory"
	emote_exclamation_mark
	step_end

# 102 "data/maps/SouthCampus/scripts.pory"
SouthCampus_HearBattle_Movement_1:
# 102 "data/maps/SouthCampus/scripts.pory"
	face_right
	step_end

# 104 "data/maps/SouthCampus/scripts.pory"
SouthCampus_HearBattle_Movement_2:
# 104 "data/maps/SouthCampus/scripts.pory"
	jump_in_place_left
	step_end

# 125 "data/maps/SouthCampus/scripts.pory"
SouthCampus_HearBattle2_Movement_0:
# 125 "data/maps/SouthCampus/scripts.pory"
	face_left
# 125 "data/maps/SouthCampus/scripts.pory"
	emote_exclamation_mark
	step_end

# 128 "data/maps/SouthCampus/scripts.pory"
SouthCampus_HearBattle2_Movement_1:
# 128 "data/maps/SouthCampus/scripts.pory"
	face_left
	step_end

# 151 "data/maps/SouthCampus/scripts.pory"
SouthCampus_ApproachBattle_Movement_0:
# 151 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 151 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
# 151 "data/maps/SouthCampus/scripts.pory"
	walk_fast_up
	step_end

# 159 "data/maps/SouthCampus/scripts.pory"
SouthCampus_ApproachBattle_Movement_1:
# 159 "data/maps/SouthCampus/scripts.pory"
	walk_fast_down
# 159 "data/maps/SouthCampus/scripts.pory"
	walk_fast_down
# 159 "data/maps/SouthCampus/scripts.pory"
	walk_fast_down
	step_end

# 188 "data/maps/SouthCampus/scripts.pory"
SouthCampus_MeowthBattle_Movement_0:
# 188 "data/maps/SouthCampus/scripts.pory"
	slide_right
# 188 "data/maps/SouthCampus/scripts.pory"
	slide_right
	step_end

# 192 "data/maps/SouthCampus/scripts.pory"
SouthCampus_MeowthBattle_Movement_1:
# 192 "data/maps/SouthCampus/scripts.pory"
	slide_left
# 192 "data/maps/SouthCampus/scripts.pory"
	slide_left
# 192 "data/maps/SouthCampus/scripts.pory"
	face_right
	step_end

# 199 "data/maps/SouthCampus/scripts.pory"
SouthCampus_MeowthBattle_Movement_2:
# 199 "data/maps/SouthCampus/scripts.pory"
	slide_left
# 199 "data/maps/SouthCampus/scripts.pory"
	slide_left
	step_end

# 203 "data/maps/SouthCampus/scripts.pory"
SouthCampus_MeowthBattle_Movement_3:
# 203 "data/maps/SouthCampus/scripts.pory"
	slide_right
# 203 "data/maps/SouthCampus/scripts.pory"
	slide_right
# 203 "data/maps/SouthCampus/scripts.pory"
	face_left
	step_end

# 209 "data/maps/SouthCampus/scripts.pory"
SouthCampus_MeowthBattle_Movement_4:
# 209 "data/maps/SouthCampus/scripts.pory"
	enter_pokeball
	step_end

# 226 "data/maps/SouthCampus/scripts.pory"
SouthCampus_MeowthBattle_Movement_5:
# 226 "data/maps/SouthCampus/scripts.pory"
	walk_right
# 226 "data/maps/SouthCampus/scripts.pory"
	walk_right
# 226 "data/maps/SouthCampus/scripts.pory"
	walk_right
# 226 "data/maps/SouthCampus/scripts.pory"
	walk_right
# 226 "data/maps/SouthCampus/scripts.pory"
	walk_right
	step_end

# 227 "data/maps/SouthCampus/scripts.pory"
SouthCampus_MeowthBattle_Movement_6:
# 227 "data/maps/SouthCampus/scripts.pory"
	walk_right
# 227 "data/maps/SouthCampus/scripts.pory"
	walk_right
# 227 "data/maps/SouthCampus/scripts.pory"
	walk_right
# 227 "data/maps/SouthCampus/scripts.pory"
	walk_right
# 227 "data/maps/SouthCampus/scripts.pory"
	walk_right
# 227 "data/maps/SouthCampus/scripts.pory"
	walk_right
# 227 "data/maps/SouthCampus/scripts.pory"
	walk_right
# 227 "data/maps/SouthCampus/scripts.pory"
	walk_right
# 227 "data/maps/SouthCampus/scripts.pory"
	walk_right
# 227 "data/maps/SouthCampus/scripts.pory"
	walk_right
# 227 "data/maps/SouthCampus/scripts.pory"
	walk_right
# 227 "data/maps/SouthCampus/scripts.pory"
	walk_right
	step_end

# 239 "data/maps/SouthCampus/scripts.pory"
SouthCampus_MeowthBattle_Movement_7:
# 239 "data/maps/SouthCampus/scripts.pory"
	walk_up
# 239 "data/maps/SouthCampus/scripts.pory"
	walk_up
# 239 "data/maps/SouthCampus/scripts.pory"
	walk_up
# 239 "data/maps/SouthCampus/scripts.pory"
	walk_left
# 239 "data/maps/SouthCampus/scripts.pory"
	walk_left
# 239 "data/maps/SouthCampus/scripts.pory"
	walk_left
# 239 "data/maps/SouthCampus/scripts.pory"
	face_right
	step_end

# 240 "data/maps/SouthCampus/scripts.pory"
SouthCampus_MeowthBattle_Movement_8:
# 240 "data/maps/SouthCampus/scripts.pory"
	walk_up
# 240 "data/maps/SouthCampus/scripts.pory"
	walk_up
# 240 "data/maps/SouthCampus/scripts.pory"
	walk_up
# 240 "data/maps/SouthCampus/scripts.pory"
	walk_right
# 240 "data/maps/SouthCampus/scripts.pory"
	walk_right
# 240 "data/maps/SouthCampus/scripts.pory"
	walk_right
# 240 "data/maps/SouthCampus/scripts.pory"
	face_left
	step_end

# 241 "data/maps/SouthCampus/scripts.pory"
SouthCampus_MeowthBattle_Movement_9:
# 241 "data/maps/SouthCampus/scripts.pory"
	walk_up
# 241 "data/maps/SouthCampus/scripts.pory"
	walk_up
# 241 "data/maps/SouthCampus/scripts.pory"
	walk_up
	step_end

# 263 "data/maps/SouthCampus/scripts.pory"
SouthCampus_TraciePostBattle_Movement_0:
# 263 "data/maps/SouthCampus/scripts.pory"
	walk_right
# 263 "data/maps/SouthCampus/scripts.pory"
	walk_right
# 263 "data/maps/SouthCampus/scripts.pory"
	walk_right
	step_end

# 264 "data/maps/SouthCampus/scripts.pory"
SouthCampus_TraciePostBattle_Movement_1:
# 264 "data/maps/SouthCampus/scripts.pory"
	walk_left
# 264 "data/maps/SouthCampus/scripts.pory"
	walk_left
# 264 "data/maps/SouthCampus/scripts.pory"
	walk_left
	step_end

# 281 "data/maps/SouthCampus/scripts.pory"
SouthCampus_TraciePostBattle_Movement_2:
# 281 "data/maps/SouthCampus/scripts.pory"
	walk_right
# 281 "data/maps/SouthCampus/scripts.pory"
	walk_right
# 281 "data/maps/SouthCampus/scripts.pory"
	walk_right
# 281 "data/maps/SouthCampus/scripts.pory"
	walk_right
# 281 "data/maps/SouthCampus/scripts.pory"
	walk_right
# 281 "data/maps/SouthCampus/scripts.pory"
	walk_right
# 281 "data/maps/SouthCampus/scripts.pory"
	walk_right
# 281 "data/maps/SouthCampus/scripts.pory"
	walk_right
	step_end

SouthCampus_LockedCafeteria_Text_0:
# 7 "data/maps/SouthCampus/scripts.pory"
	.string "The cafeteria isn't open.$"

SouthCampus_HearBattle_Text_0:
# 94 "data/maps/SouthCampus/scripts.pory"
	.string "Go, Meowth!$"

SouthCampus_HearBattle_Text_1:
# 111 "data/maps/SouthCampus/scripts.pory"
	.string "{PLAYER}, did you hear that?\p"
	.string "It sounds like a Pokémon battle\n"
	.string "just started!\p"
	.string "Let's check it out!$"

SouthCampus_ApproachBattle_Text_0:
# 146 "data/maps/SouthCampus/scripts.pory"
	.string "I knew it!\n"
	.string "They're having a battle!$"

SouthCampus_ApproachBattle_Text_1:
# 153 "data/maps/SouthCampus/scripts.pory"
	.string "Youngster$"

SouthCampus_ApproachBattle_Text_2:
# 154 "data/maps/SouthCampus/scripts.pory"
	.string "My Meowth is way stronger!\n"
	.string "He's going to win for sure!$"

SouthCampus_ApproachBattle_Text_3:
# 156 "data/maps/SouthCampus/scripts.pory"
	.string "Lass$"

SouthCampus_ApproachBattle_Text_4:
# 157 "data/maps/SouthCampus/scripts.pory"
	.string "Don't get overconfident.\p"
	.string "I'll bet you've never seen a\n"
	.string "Meowth like mine before!$"

SouthCampus_ApproachBattle_Text_5:
# 162 "data/maps/SouthCampus/scripts.pory"
	.string "I've never seen a Meowth like her's\n"
	.string "before, either.\p"
	.string "I wonder why it looks so different…$"

SouthCampus_ApproachBattle_Text_6:
# 168 "data/maps/SouthCampus/scripts.pory"
	.string "Man$"

SouthCampus_ApproachBattle_Text_7:
# 169 "data/maps/SouthCampus/scripts.pory"
	.string "Some Pokémon come in different\n"
	.string "varieties depending on their habitat.\p"
	.string "Her Meowth is a Dark-type and his is a\n"
	.string "Normal-type.\p"
	.string "Neither Meowth has a type advantage\n"
	.string "against the other, so it's been a good\l"
	.string "battle so far!$"

SouthCampus_ApproachBattle_Text_8:
# 172 "data/maps/SouthCampus/scripts.pory"
	.string "Oh, that makes sense!\p"
	.string "It's so neat that Pokémon of the same\n"
	.string "species can be different types!$"

SouthCampus_MeowthBattle_Text_0:
# 184 "data/maps/SouthCampus/scripts.pory"
	.string "Meowth, use Scratch!$"

SouthCampus_MeowthBattle_Text_1:
# 195 "data/maps/SouthCampus/scripts.pory"
	.string "Meowth, use Pay Day!$"

SouthCampus_MeowthBattle_Text_2:
# 221 "data/maps/SouthCampus/scripts.pory"
	.string "Aww, darn!\n"
	.string "Oh well.\p"
	.string "Can't win them all.\n"
	.string "Thanks for the battle!$"

SouthCampus_MeowthBattle_Text_3:
# 224 "data/maps/SouthCampus/scripts.pory"
	.string "Same to you!\n"
	.string "It was fun!$"

SouthCampus_MeowthBattle_Text_4:
# 231 "data/maps/SouthCampus/scripts.pory"
	.string "That was such a great battle!\n"
	.string "I'm all fired up!$"

SouthCampus_MeowthBattle_Text_5:
# 237 "data/maps/SouthCampus/scripts.pory"
	.string "Hey!\n"
	.string "Let's have a battle!\p"
	.string "It'll be the first battle of our final\n"
	.string "year of school, and I can't think of\l"
	.string "anyone better to have it with!$"

SouthCampus_MeowthBattle_Text_6:
# 244 "data/maps/SouthCampus/scripts.pory"
	.string "Alright, here we go.\n"
	.string "No holding back!$"

SouthCampus_MeowthBattle_Text_7:
# 250 "data/maps/SouthCampus/scripts.pory"
	.string "Looks like I still have some\n"
	.string "catching up to do!$"

SouthCampus_TraciePostBattle_Text_0:
# 268 "data/maps/SouthCampus/scripts.pory"
	.string "Thanks for the battle!\p"
	.string "But, I could tell you were\n"
	.string "holding back!\p"
	.string "You better not do that again!\p"
	.string "I can't wait to battle again once our\n"
	.string "journeys start!\p"
	.string "Let me heal your Pokémon quick!$"

SouthCampus_TraciePostBattle_Text_1:
# 274 "data/maps/SouthCampus/scripts.pory"
	.string "That was so much fun!\p"
	.string "I can't wait to battle again once our\n"
	.string "journeys start!\p"
	.string "Let me heal your Pokémon quick!$"

SouthCampus_TraciePostBattle_Text_2:
# 279 "data/maps/SouthCampus/scripts.pory"
	.string "I'm going to go on ahead to North\n"
	.string "Campus for orientation.\p"
	.string "Try not to take too long getting there.\n"
	.string "You don't want to be late!\p"
	.string "See you soon!$"
