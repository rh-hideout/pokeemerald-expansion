# 1 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 2 "data/maps/SeafloorCavern_Room9/scripts.pory"
.set LOCALID_KYOGRE, 1
# 3 "data/maps/SeafloorCavern_Room9/scripts.pory"
.set LOCALID_ARCHIE, 2
# 4 "data/maps/SeafloorCavern_Room9/scripts.pory"
.set LOCALID_MAXIE, 3
# 5 "data/maps/SeafloorCavern_Room9/scripts.pory"
.set LOCALID_GRUNT_1, 4
# 6 "data/maps/SeafloorCavern_Room9/scripts.pory"
.set LOCALID_GRUNT_2, 5
# 7 "data/maps/SeafloorCavern_Room9/scripts.pory"
.set LOCALID_KYOGRE_SLEEPING, 7
# 8 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 9 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_MapScripts::
# 10 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.byte 0
# 11 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 12 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_EventScript_ArchieAwakenKyogre::
# 13 "data/maps/SeafloorCavern_Room9/scripts.pory"
	lockall
# 14 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setvar VAR_0x8004, LOCALID_ARCHIE
# 15 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setvar VAR_0x8005, LOCALID_MAXIE
# 16 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setvar VAR_0x8006, LOCALID_GRUNT_1
# 17 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setvar VAR_0x8007, LOCALID_GRUNT_2
# 18 "data/maps/SeafloorCavern_Room9/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 19 "data/maps/SeafloorCavern_Room9/scripts.pory"
	waitmovement 0
# 20 "data/maps/SeafloorCavern_Room9/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SeafloorCavern_Room9_Movement_Delay32
# 21 "data/maps/SeafloorCavern_Room9/scripts.pory"
	waitmovement 0
# 22 "data/maps/SeafloorCavern_Room9/scripts.pory"
	playbgm MUS_ENCOUNTER_AQUA, FALSE
# 23 "data/maps/SeafloorCavern_Room9/scripts.pory"
	msgbox SeafloorCavern_Room9_Text_ArchieHoldItRightThere, MSGBOX_DEFAULT
# 24 "data/maps/SeafloorCavern_Room9/scripts.pory"
	closemessage
# 25 "data/maps/SeafloorCavern_Room9/scripts.pory"
	addobject VAR_0x8004
# 26 "data/maps/SeafloorCavern_Room9/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 27 "data/maps/SeafloorCavern_Room9/scripts.pory"
	waitmovement 0
# 28 "data/maps/SeafloorCavern_Room9/scripts.pory"
	applymovement VAR_0x8004, SeafloorCavern_Room9_Movement_ArchieApproachPlayer
# 29 "data/maps/SeafloorCavern_Room9/scripts.pory"
	waitmovement 0
# 30 "data/maps/SeafloorCavern_Room9/scripts.pory"
	msgbox SeafloorCavern_Room9_Text_ArchieSoItWasYou, MSGBOX_DEFAULT
# 31 "data/maps/SeafloorCavern_Room9/scripts.pory"
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFasterUp
# 32 "data/maps/SeafloorCavern_Room9/scripts.pory"
	waitmovement 0
# 33 "data/maps/SeafloorCavern_Room9/scripts.pory"
	msgbox SeafloorCavern_Room9_Text_ArchieBeholdKyogre, MSGBOX_DEFAULT
# 34 "data/maps/SeafloorCavern_Room9/scripts.pory"
	applymovement VAR_0x8004, Common_Movement_FacePlayer
# 35 "data/maps/SeafloorCavern_Room9/scripts.pory"
	waitmovement 0
# 36 "data/maps/SeafloorCavern_Room9/scripts.pory"
	msgbox SeafloorCavern_Room9_Text_ArchieYouMustDisappear, MSGBOX_DEFAULT
# 37 "data/maps/SeafloorCavern_Room9/scripts.pory"
	trainerbattle_no_intro TRAINER_ARCHIE, SeafloorCavern_Room9_Text_ArchieDefeat
# 38 "data/maps/SeafloorCavern_Room9/scripts.pory"
	msgbox SeafloorCavern_Room9_Text_ArchieWithThisRedOrb, MSGBOX_DEFAULT
# 39 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setweather WEATHER_NONE
# 40 "data/maps/SeafloorCavern_Room9/scripts.pory"
	doweather
# 41 "data/maps/SeafloorCavern_Room9/scripts.pory"
	special Script_FadeOutMapMusic
# 42 "data/maps/SeafloorCavern_Room9/scripts.pory"
	waitstate
# 43 "data/maps/SeafloorCavern_Room9/scripts.pory"
	msgbox SeafloorCavern_Room9_Text_RedOrbShinesByItself, MSGBOX_DEFAULT
# 44 "data/maps/SeafloorCavern_Room9/scripts.pory"
	special WaitWeather
# 45 "data/maps/SeafloorCavern_Room9/scripts.pory"
	waitstate
# 46 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setvar VAR_RESULT, 1
# 47 "data/maps/SeafloorCavern_Room9/scripts.pory"
	playse SE_M_DETECT
# 48 "data/maps/SeafloorCavern_Room9/scripts.pory"
	dofieldeffectsparkle 16, 42, 0
# 49 "data/maps/SeafloorCavern_Room9/scripts.pory"
	waitfieldeffect FLDEFF_SPARKLE
# 50 "data/maps/SeafloorCavern_Room9/scripts.pory"
	closemessage
# 51 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setvar VAR_RESULT, 0
# 52 "data/maps/SeafloorCavern_Room9/scripts.pory"
	playfanfare MUS_AWAKEN_LEGEND
# 53 "data/maps/SeafloorCavern_Room9/scripts.pory"
	playse SE_ORB
# 54 "data/maps/SeafloorCavern_Room9/scripts.pory"
	special DoOrbEffect
# 55 "data/maps/SeafloorCavern_Room9/scripts.pory"
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFasterUp
# 56 "data/maps/SeafloorCavern_Room9/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 57 "data/maps/SeafloorCavern_Room9/scripts.pory"
	waitmovement 0
# 58 "data/maps/SeafloorCavern_Room9/scripts.pory"
	delay 150
# 59 "data/maps/SeafloorCavern_Room9/scripts.pory"
	removeobject LOCALID_KYOGRE_SLEEPING
# 60 "data/maps/SeafloorCavern_Room9/scripts.pory"
	addobject LOCALID_KYOGRE
# 61 "data/maps/SeafloorCavern_Room9/scripts.pory"
	waitstate
# 62 "data/maps/SeafloorCavern_Room9/scripts.pory"
	delay 60
# 63 "data/maps/SeafloorCavern_Room9/scripts.pory"
	applymovement LOCALID_KYOGRE, SeafloorCavern_Room9_Movement_KyogreApproach
# 64 "data/maps/SeafloorCavern_Room9/scripts.pory"
	waitmovement 0
# 65 "data/maps/SeafloorCavern_Room9/scripts.pory"
	special FadeOutOrbEffect
# 66 "data/maps/SeafloorCavern_Room9/scripts.pory"
	waitstate
# 67 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 68 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setvar VAR_0x8005, 1  @ horizontal pan
# 69 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 70 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setvar VAR_0x8007, 5  @ shake delay
# 71 "data/maps/SeafloorCavern_Room9/scripts.pory"
	special ShakeCamera
# 72 "data/maps/SeafloorCavern_Room9/scripts.pory"
	waitstate
# 73 "data/maps/SeafloorCavern_Room9/scripts.pory"
	applymovement LOCALID_KYOGRE, SeafloorCavern_Room9_Movement_KyogreExit
# 74 "data/maps/SeafloorCavern_Room9/scripts.pory"
	waitmovement 0
# 75 "data/maps/SeafloorCavern_Room9/scripts.pory"
	removeobject LOCALID_KYOGRE
# 76 "data/maps/SeafloorCavern_Room9/scripts.pory"
	delay 4
# 77 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setvar VAR_0x8004, 2  @ vertical pan
# 78 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setvar VAR_0x8005, 2  @ horizontal pan
# 79 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 80 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setvar VAR_0x8007, 5  @ shake delay
# 81 "data/maps/SeafloorCavern_Room9/scripts.pory"
	special ShakeCamera
# 82 "data/maps/SeafloorCavern_Room9/scripts.pory"
	waitstate
# 83 "data/maps/SeafloorCavern_Room9/scripts.pory"
	delay 30
# 84 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setvar VAR_0x8004, LOCALID_ARCHIE
# 85 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setvar VAR_0x8005, LOCALID_MAXIE
# 86 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setvar VAR_0x8006, LOCALID_GRUNT_1
# 87 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setvar VAR_0x8007, LOCALID_GRUNT_2
# 88 "data/maps/SeafloorCavern_Room9/scripts.pory"
	msgbox SeafloorCavern_Room9_Text_ArchieWhereDidKyogreGo, MSGBOX_DEFAULT
# 89 "data/maps/SeafloorCavern_Room9/scripts.pory"
	playse SE_PC_LOGIN
# 90 "data/maps/SeafloorCavern_Room9/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 91 "data/maps/SeafloorCavern_Room9/scripts.pory"
	waitmovement 0
# 92 "data/maps/SeafloorCavern_Room9/scripts.pory"
	msgbox SeafloorCavern_Room9_Text_ArchieAMessageFromOutside, MSGBOX_DEFAULT
# 93 "data/maps/SeafloorCavern_Room9/scripts.pory"
	closemessage
# 94 "data/maps/SeafloorCavern_Room9/scripts.pory"
	applymovement VAR_0x8004, SeafloorCavern_Room9_Movement_ArchieListenMessage
# 95 "data/maps/SeafloorCavern_Room9/scripts.pory"
	waitmovement 0
# 96 "data/maps/SeafloorCavern_Room9/scripts.pory"
	msgbox SeafloorCavern_Room9_Text_ArchieWhatRainingTooHard, MSGBOX_DEFAULT
# 97 "data/maps/SeafloorCavern_Room9/scripts.pory"
	closemessage
# 98 "data/maps/SeafloorCavern_Room9/scripts.pory"
	playse SE_PC_OFF
# 99 "data/maps/SeafloorCavern_Room9/scripts.pory"
	delay 20
# 100 "data/maps/SeafloorCavern_Room9/scripts.pory"
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFasterDown
# 101 "data/maps/SeafloorCavern_Room9/scripts.pory"
	waitmovement 0
# 102 "data/maps/SeafloorCavern_Room9/scripts.pory"
	msgbox SeafloorCavern_Room9_Text_ArchieWhyDidKyogreDisappear, MSGBOX_DEFAULT
# 103 "data/maps/SeafloorCavern_Room9/scripts.pory"
	closemessage
# 104 "data/maps/SeafloorCavern_Room9/scripts.pory"
	addobject VAR_0x8005
# 105 "data/maps/SeafloorCavern_Room9/scripts.pory"
	addobject VAR_0x8006
# 106 "data/maps/SeafloorCavern_Room9/scripts.pory"
	addobject VAR_0x8007
# 107 "data/maps/SeafloorCavern_Room9/scripts.pory"
	applymovement VAR_0x8007, SeafloorCavern_Room9_Movement_MagmaGruntArrive
# 108 "data/maps/SeafloorCavern_Room9/scripts.pory"
	applymovement VAR_0x8006, SeafloorCavern_Room9_Movement_MagmaGruntArrive
# 109 "data/maps/SeafloorCavern_Room9/scripts.pory"
	applymovement VAR_0x8005, SeafloorCavern_Room9_Movement_MaxieArrive
# 110 "data/maps/SeafloorCavern_Room9/scripts.pory"
	waitmovement 0
# 111 "data/maps/SeafloorCavern_Room9/scripts.pory"
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFasterLeft
# 112 "data/maps/SeafloorCavern_Room9/scripts.pory"
	waitmovement 0
# 113 "data/maps/SeafloorCavern_Room9/scripts.pory"
	msgbox SeafloorCavern_Room9_Text_MaxieWhatHaveYouWrought, MSGBOX_DEFAULT
# 114 "data/maps/SeafloorCavern_Room9/scripts.pory"
	playse SE_PIN
# 115 "data/maps/SeafloorCavern_Room9/scripts.pory"
	applymovement VAR_0x8004, Common_Movement_ExclamationMark
# 116 "data/maps/SeafloorCavern_Room9/scripts.pory"
	waitmovement 0
# 117 "data/maps/SeafloorCavern_Room9/scripts.pory"
	applymovement VAR_0x8004, Common_Movement_Delay48
# 118 "data/maps/SeafloorCavern_Room9/scripts.pory"
	waitmovement 0
# 119 "data/maps/SeafloorCavern_Room9/scripts.pory"
	msgbox SeafloorCavern_Room9_Text_ArchieDontGetAllHighAndMighty, MSGBOX_DEFAULT
# 120 "data/maps/SeafloorCavern_Room9/scripts.pory"
	msgbox SeafloorCavern_Room9_Text_MaxieWeDontHaveTimeToArgue, MSGBOX_DEFAULT
# 121 "data/maps/SeafloorCavern_Room9/scripts.pory"
	closemessage
# 122 "data/maps/SeafloorCavern_Room9/scripts.pory"
	applymovement VAR_0x8005, SeafloorCavern_Room9_Movement_MaxieExit
# 123 "data/maps/SeafloorCavern_Room9/scripts.pory"
	applymovement VAR_0x8004, SeafloorCavern_Room9_Movement_ArchieExit
# 124 "data/maps/SeafloorCavern_Room9/scripts.pory"
	waitmovement 0
# 125 "data/maps/SeafloorCavern_Room9/scripts.pory"
	msgbox SeafloorCavern_Room9_Text_MaxieComeOnPlayer, MSGBOX_DEFAULT
# 126 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setvar VAR_ROUTE128_STATE, 1
# 127 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setvar VAR_SOOTOPOLIS_CITY_STATE, 1
# 128 "data/maps/SeafloorCavern_Room9/scripts.pory"
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_STEVEN
# 129 "data/maps/SeafloorCavern_Room9/scripts.pory"
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_ARCHIE
# 130 "data/maps/SeafloorCavern_Room9/scripts.pory"
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_MAXIE
# 131 "data/maps/SeafloorCavern_Room9/scripts.pory"
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_RESIDENTS
# 132 "data/maps/SeafloorCavern_Room9/scripts.pory"
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_GROUDON
# 133 "data/maps/SeafloorCavern_Room9/scripts.pory"
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_KYOGRE
# 134 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_MAN_1
# 135 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setflag FLAG_LEGENDARIES_IN_SOOTOPOLIS
# 136 "data/maps/SeafloorCavern_Room9/scripts.pory"
	clearflag FLAG_HIDE_ROUTE_128_ARCHIE
# 137 "data/maps/SeafloorCavern_Room9/scripts.pory"
	clearflag FLAG_HIDE_ROUTE_128_MAXIE
# 138 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setflag FLAG_SYS_WEATHER_CTRL
# 139 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setflag FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN
# 140 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setflag FLAG_HIDE_MOSSDEEP_CITY_STEVENS_HOUSE_STEVEN
# 141 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setvar VAR_STEVENS_HOUSE_STATE, 2
# 142 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setvar VAR_SEAFLOOR_CAVERN_STATE, 1
# 143 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_ROOM_9_ARCHIE
# 144 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_ROOM_9_MAXIE
# 145 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_ROOM_9_MAGMA_GRUNTS
# 146 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_ROOM_9_KYOGRE
# 147 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_AQUA_GRUNTS
# 148 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setflag FLAG_HIDE_MAP_NAME_POPUP
# 149 "data/maps/SeafloorCavern_Room9/scripts.pory"
	warp MAP_ROUTE128, 38, 22
# 150 "data/maps/SeafloorCavern_Room9/scripts.pory"
	waitstate
# 151 "data/maps/SeafloorCavern_Room9/scripts.pory"
	releaseall
# 152 "data/maps/SeafloorCavern_Room9/scripts.pory"
	end
# 153 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 154 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_Movement_ArchieApproachPlayer:
# 155 "data/maps/SeafloorCavern_Room9/scripts.pory"
	walk_right
# 156 "data/maps/SeafloorCavern_Room9/scripts.pory"
	walk_right
# 157 "data/maps/SeafloorCavern_Room9/scripts.pory"
	walk_right
# 158 "data/maps/SeafloorCavern_Room9/scripts.pory"
	walk_right
# 159 "data/maps/SeafloorCavern_Room9/scripts.pory"
	walk_right
# 160 "data/maps/SeafloorCavern_Room9/scripts.pory"
	walk_right
# 161 "data/maps/SeafloorCavern_Room9/scripts.pory"
	walk_right
# 162 "data/maps/SeafloorCavern_Room9/scripts.pory"
	step_end
# 163 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 164 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_Movement_Unused1:
# 165 "data/maps/SeafloorCavern_Room9/scripts.pory"
	walk_left
# 166 "data/maps/SeafloorCavern_Room9/scripts.pory"
	walk_left
# 167 "data/maps/SeafloorCavern_Room9/scripts.pory"
	step_end
# 168 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 169 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_Movement_ArchieListenMessage:
# 170 "data/maps/SeafloorCavern_Room9/scripts.pory"
	walk_left
# 171 "data/maps/SeafloorCavern_Room9/scripts.pory"
	delay_16
# 172 "data/maps/SeafloorCavern_Room9/scripts.pory"
	step_end
# 173 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 174 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_Movement_Unused2:
# 175 "data/maps/SeafloorCavern_Room9/scripts.pory"
	walk_right
# 176 "data/maps/SeafloorCavern_Room9/scripts.pory"
	step_end
# 177 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 178 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_Movement_ArchieExit:
# 179 "data/maps/SeafloorCavern_Room9/scripts.pory"
	face_up
# 180 "data/maps/SeafloorCavern_Room9/scripts.pory"
	lock_facing_direction
# 181 "data/maps/SeafloorCavern_Room9/scripts.pory"
	walk_down
# 182 "data/maps/SeafloorCavern_Room9/scripts.pory"
	unlock_facing_direction
# 183 "data/maps/SeafloorCavern_Room9/scripts.pory"
	walk_in_place_faster_right
# 184 "data/maps/SeafloorCavern_Room9/scripts.pory"
	step_end
# 185 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 186 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_Movement_KyogreApproach:
# 187 "data/maps/SeafloorCavern_Room9/scripts.pory"
	delay_16
# 188 "data/maps/SeafloorCavern_Room9/scripts.pory"
	delay_16
# 189 "data/maps/SeafloorCavern_Room9/scripts.pory"
	walk_slow_down
# 190 "data/maps/SeafloorCavern_Room9/scripts.pory"
	delay_16
# 191 "data/maps/SeafloorCavern_Room9/scripts.pory"
	delay_16
# 192 "data/maps/SeafloorCavern_Room9/scripts.pory"
	delay_16
# 193 "data/maps/SeafloorCavern_Room9/scripts.pory"
	walk_slow_down
# 194 "data/maps/SeafloorCavern_Room9/scripts.pory"
	delay_16
# 195 "data/maps/SeafloorCavern_Room9/scripts.pory"
	delay_16
# 196 "data/maps/SeafloorCavern_Room9/scripts.pory"
	delay_16
# 197 "data/maps/SeafloorCavern_Room9/scripts.pory"
	step_end
# 198 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 199 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_Movement_KyogreExit:
# 200 "data/maps/SeafloorCavern_Room9/scripts.pory"
	slide_up
# 201 "data/maps/SeafloorCavern_Room9/scripts.pory"
	slide_up
# 202 "data/maps/SeafloorCavern_Room9/scripts.pory"
	step_end
# 203 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 204 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_Movement_MaxieArrive:
# 205 "data/maps/SeafloorCavern_Room9/scripts.pory"
	walk_fast_right
# 206 "data/maps/SeafloorCavern_Room9/scripts.pory"
	walk_fast_right
# 207 "data/maps/SeafloorCavern_Room9/scripts.pory"
	walk_fast_right
# 208 "data/maps/SeafloorCavern_Room9/scripts.pory"
	walk_fast_right
# 209 "data/maps/SeafloorCavern_Room9/scripts.pory"
	walk_fast_right
# 210 "data/maps/SeafloorCavern_Room9/scripts.pory"
	step_end
# 211 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 212 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_Movement_MaxieExit:
# 213 "data/maps/SeafloorCavern_Room9/scripts.pory"
	walk_right
# 214 "data/maps/SeafloorCavern_Room9/scripts.pory"
	walk_right
# 215 "data/maps/SeafloorCavern_Room9/scripts.pory"
	step_end
# 216 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 217 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_Movement_MagmaGruntArrive:
# 218 "data/maps/SeafloorCavern_Room9/scripts.pory"
	walk_fast_right
# 219 "data/maps/SeafloorCavern_Room9/scripts.pory"
	walk_fast_right
# 220 "data/maps/SeafloorCavern_Room9/scripts.pory"
	walk_fast_right
# 221 "data/maps/SeafloorCavern_Room9/scripts.pory"
	walk_fast_right
# 222 "data/maps/SeafloorCavern_Room9/scripts.pory"
	step_end
# 223 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 224 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_Movement_Delay32:
# 225 "data/maps/SeafloorCavern_Room9/scripts.pory"
	delay_16
# 226 "data/maps/SeafloorCavern_Room9/scripts.pory"
	delay_16
# 227 "data/maps/SeafloorCavern_Room9/scripts.pory"
	step_end
# 228 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 229 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_Text_ArchieHoldItRightThere:
# 230 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "ARCHIE: Hold it right there.$"
# 231 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 232 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_Text_ArchieSoItWasYou:
# 233 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "ARCHIE: Fufufu…\n"
# 234 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "So it was you, after all.$"
# 235 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 236 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_Text_ArchieBeholdKyogre:
# 237 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "ARCHIE: Behold!\p"
# 238 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "See how beautiful it is, the sleeping\n"
# 239 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "form of the ancient POKéMON KYOGRE!\p"
# 240 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "I have waited so long for this day to\n"
# 241 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "come…$"
# 242 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 243 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_Text_ArchieYouMustDisappear:
# 244 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "ARCHIE: It surprises me, how you've\n"
# 245 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "managed to chase me here.\p"
# 246 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "But that's all over now.\p"
# 247 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "For the realization of my dream,\n"
# 248 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "you must disappear now!$"
# 249 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 250 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_Text_ArchieDefeat:
# 251 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "What?!\n"
# 252 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "I lost to a mere child like you?!$"
# 253 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 254 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_Text_ArchieWithThisRedOrb:
# 255 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "ARCHIE: Fufufu…\p"
# 256 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "I commend you. I must recognize that\n"
# 257 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "you are truly gifted.\p"
# 258 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "But!\n"
# 259 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "I have this in my possession!\p"
# 260 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "With this RED ORB, I can make KYOGRE…$"
# 261 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 262 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_Text_RedOrbShinesByItself:
# 263 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "The RED ORB suddenly began shining\n"
# 264 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "by itself!$"
# 265 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 266 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_Text_ArchieWhereDidKyogreGo:
# 267 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "ARCHIE: What?!\p"
# 268 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "I didn't do anything.\n"
# 269 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "Why did the RED ORB…\p"
# 270 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "Where did KYOGRE go?$"
# 271 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 272 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_Text_ArchieAMessageFromOutside:
# 273 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "ARCHIE: Hm? It's a message from our\n"
# 274 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "members outside…$"
# 275 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 276 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_Text_ArchieWhatRainingTooHard:
# 277 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "ARCHIE: Yes, what is it?\p"
# 278 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "Hm…\n"
# 279 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "It's raining heavily?\p"
# 280 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "Good… That should have happened.\n"
# 281 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "That is why we awakened KYOGRE,\l"
# 282 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "to realize TEAM AQUA's vision of\l"
# 283 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "expanding the sea.\p"
# 284 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "What?!\p"
# 285 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "It's raining far harder than we\n"
# 286 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "envisioned? You're in danger?\p"
# 287 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "That can't be…\n"
# 288 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "That's just not possible…\p"
# 289 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "Hold your position and monitor\n"
# 290 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "the situation!$"
# 291 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 292 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_Text_ArchieWhyDidKyogreDisappear:
# 293 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "ARCHIE: There's something wrong…\p"
# 294 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "The RED ORB is supposed to awaken\n"
# 295 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "and control KYOGRE…\p"
# 296 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "But… Why?\n"
# 297 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "Why did KYOGRE disappear?\p"
# 298 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "Why?!$"
# 299 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 300 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_Text_MaxieWhatHaveYouWrought:
# 301 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "MAXIE: What have you wrought?\p"
# 302 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "ARCHIE… You've finally awoken KYOGRE,\n"
# 303 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "haven't you?\p"
# 304 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "What will happen to the world if this\n"
# 305 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "downpour continues for all eternity?\p"
# 306 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "The world's landmass will drown in\n"
# 307 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "the deepening sea…$"
# 308 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 309 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_Text_ArchieDontGetAllHighAndMighty:
# 310 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "ARCHIE: W-what?!\n"
# 311 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "Don't get all high and mighty with me!\p"
# 312 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "Wasn't it you, TEAM MAGMA, that\n"
# 313 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "infuriated GROUDON?\p"
# 314 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "So long as I have this RED ORB,\n"
# 315 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "I should be able to control KYOGRE…\p"
# 316 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "I should be able to control it…$"
# 317 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 318 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_Text_MaxieWeDontHaveTimeToArgue:
# 319 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "MAXIE: We don't have the time to\n"
# 320 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "argue about it here!\p"
# 321 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "Get outside and see for yourself!\p"
# 322 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "See if what you've wrought is the\n"
# 323 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "world that we desired!$"
# 324 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 325 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_Text_MaxieComeOnPlayer:
# 326 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "MAXIE: {PLAYER}, come on, you have\n"
# 327 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "to get out of here, too!$"
