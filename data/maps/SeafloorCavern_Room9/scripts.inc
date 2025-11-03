# 1 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 2 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_MapScripts::
# 3 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.byte 0
# 4 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 5 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_EventScript_ArchieAwakenKyogre::
# 6 "data/maps/SeafloorCavern_Room9/scripts.pory"
	lockall
# 7 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setvar VAR_0x8004, LOCALID_SEAFLOOR_CAVERN_ARCHIE
# 8 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setvar VAR_0x8005, LOCALID_SEAFLOOR_CAVERN_MAXIE
# 9 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setvar VAR_0x8006, LOCALID_SEAFLOOR_CAVERN_GRUNT_1
# 10 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setvar VAR_0x8007, LOCALID_SEAFLOOR_CAVERN_GRUNT_2
# 11 "data/maps/SeafloorCavern_Room9/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 12 "data/maps/SeafloorCavern_Room9/scripts.pory"
	waitmovement 0
# 13 "data/maps/SeafloorCavern_Room9/scripts.pory"
	applymovement LOCALID_PLAYER, SeafloorCavern_Room9_Movement_Delay32
# 14 "data/maps/SeafloorCavern_Room9/scripts.pory"
	waitmovement 0
# 15 "data/maps/SeafloorCavern_Room9/scripts.pory"
	playbgm MUS_ENCOUNTER_AQUA, FALSE
# 16 "data/maps/SeafloorCavern_Room9/scripts.pory"
	msgbox SeafloorCavern_Room9_Text_ArchieHoldItRightThere, MSGBOX_DEFAULT
# 17 "data/maps/SeafloorCavern_Room9/scripts.pory"
	closemessage
# 18 "data/maps/SeafloorCavern_Room9/scripts.pory"
	addobject VAR_0x8004
# 19 "data/maps/SeafloorCavern_Room9/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 20 "data/maps/SeafloorCavern_Room9/scripts.pory"
	waitmovement 0
# 21 "data/maps/SeafloorCavern_Room9/scripts.pory"
	applymovement VAR_0x8004, SeafloorCavern_Room9_Movement_ArchieApproachPlayer
# 22 "data/maps/SeafloorCavern_Room9/scripts.pory"
	waitmovement 0
# 23 "data/maps/SeafloorCavern_Room9/scripts.pory"
	msgbox SeafloorCavern_Room9_Text_ArchieSoItWasYou, MSGBOX_DEFAULT
# 24 "data/maps/SeafloorCavern_Room9/scripts.pory"
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFasterUp
# 25 "data/maps/SeafloorCavern_Room9/scripts.pory"
	waitmovement 0
# 26 "data/maps/SeafloorCavern_Room9/scripts.pory"
	msgbox SeafloorCavern_Room9_Text_ArchieBeholdKyogre, MSGBOX_DEFAULT
# 27 "data/maps/SeafloorCavern_Room9/scripts.pory"
	applymovement VAR_0x8004, Common_Movement_FacePlayer
# 28 "data/maps/SeafloorCavern_Room9/scripts.pory"
	waitmovement 0
# 29 "data/maps/SeafloorCavern_Room9/scripts.pory"
	msgbox SeafloorCavern_Room9_Text_ArchieYouMustDisappear, MSGBOX_DEFAULT
# 30 "data/maps/SeafloorCavern_Room9/scripts.pory"
	trainerbattle_no_intro TRAINER_ARCHIE, SeafloorCavern_Room9_Text_ArchieDefeat
# 31 "data/maps/SeafloorCavern_Room9/scripts.pory"
	msgbox SeafloorCavern_Room9_Text_ArchieWithThisRedOrb, MSGBOX_DEFAULT
# 32 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setweather WEATHER_NONE
# 33 "data/maps/SeafloorCavern_Room9/scripts.pory"
	doweather
# 34 "data/maps/SeafloorCavern_Room9/scripts.pory"
	special Script_FadeOutMapMusic
# 35 "data/maps/SeafloorCavern_Room9/scripts.pory"
	waitstate
# 36 "data/maps/SeafloorCavern_Room9/scripts.pory"
	msgbox SeafloorCavern_Room9_Text_RedOrbShinesByItself, MSGBOX_DEFAULT
# 37 "data/maps/SeafloorCavern_Room9/scripts.pory"
	special WaitWeather
# 38 "data/maps/SeafloorCavern_Room9/scripts.pory"
	waitstate
# 39 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setvar VAR_RESULT, 1
# 40 "data/maps/SeafloorCavern_Room9/scripts.pory"
	playse SE_M_DETECT
# 41 "data/maps/SeafloorCavern_Room9/scripts.pory"
	dofieldeffectsparkle 16, 42, 0
# 42 "data/maps/SeafloorCavern_Room9/scripts.pory"
	waitfieldeffect FLDEFF_SPARKLE
# 43 "data/maps/SeafloorCavern_Room9/scripts.pory"
	closemessage
# 44 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setvar VAR_RESULT, 0
# 45 "data/maps/SeafloorCavern_Room9/scripts.pory"
	playfanfare MUS_AWAKEN_LEGEND
# 46 "data/maps/SeafloorCavern_Room9/scripts.pory"
	playse SE_ORB
# 47 "data/maps/SeafloorCavern_Room9/scripts.pory"
	special DoOrbEffect
# 48 "data/maps/SeafloorCavern_Room9/scripts.pory"
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFasterUp
# 49 "data/maps/SeafloorCavern_Room9/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 50 "data/maps/SeafloorCavern_Room9/scripts.pory"
	waitmovement 0
# 51 "data/maps/SeafloorCavern_Room9/scripts.pory"
	delay 150
# 52 "data/maps/SeafloorCavern_Room9/scripts.pory"
	removeobject LOCALID_SEAFLOOR_CAVERN_KYOGRE_SLEEPING
# 53 "data/maps/SeafloorCavern_Room9/scripts.pory"
	addobject LOCALID_SEAFLOOR_CAVERN_KYOGRE
# 54 "data/maps/SeafloorCavern_Room9/scripts.pory"
	waitstate
# 55 "data/maps/SeafloorCavern_Room9/scripts.pory"
	delay 60
# 56 "data/maps/SeafloorCavern_Room9/scripts.pory"
	applymovement LOCALID_SEAFLOOR_CAVERN_KYOGRE, SeafloorCavern_Room9_Movement_KyogreApproach
# 57 "data/maps/SeafloorCavern_Room9/scripts.pory"
	waitmovement 0
# 58 "data/maps/SeafloorCavern_Room9/scripts.pory"
	special FadeOutOrbEffect
# 59 "data/maps/SeafloorCavern_Room9/scripts.pory"
	waitstate
# 60 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 61 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setvar VAR_0x8005, 1  @ horizontal pan
# 62 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 63 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setvar VAR_0x8007, 5  @ shake delay
# 64 "data/maps/SeafloorCavern_Room9/scripts.pory"
	special ShakeCamera
# 65 "data/maps/SeafloorCavern_Room9/scripts.pory"
	waitstate
# 66 "data/maps/SeafloorCavern_Room9/scripts.pory"
	applymovement LOCALID_SEAFLOOR_CAVERN_KYOGRE, SeafloorCavern_Room9_Movement_KyogreExit
# 67 "data/maps/SeafloorCavern_Room9/scripts.pory"
	waitmovement 0
# 68 "data/maps/SeafloorCavern_Room9/scripts.pory"
	removeobject LOCALID_SEAFLOOR_CAVERN_KYOGRE
# 69 "data/maps/SeafloorCavern_Room9/scripts.pory"
	delay 4
# 70 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setvar VAR_0x8004, 2  @ vertical pan
# 71 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setvar VAR_0x8005, 2  @ horizontal pan
# 72 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 73 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setvar VAR_0x8007, 5  @ shake delay
# 74 "data/maps/SeafloorCavern_Room9/scripts.pory"
	special ShakeCamera
# 75 "data/maps/SeafloorCavern_Room9/scripts.pory"
	waitstate
# 76 "data/maps/SeafloorCavern_Room9/scripts.pory"
	delay 30
# 77 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setvar VAR_0x8004, LOCALID_SEAFLOOR_CAVERN_ARCHIE
# 78 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setvar VAR_0x8005, LOCALID_SEAFLOOR_CAVERN_MAXIE
# 79 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setvar VAR_0x8006, LOCALID_SEAFLOOR_CAVERN_GRUNT_1
# 80 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setvar VAR_0x8007, LOCALID_SEAFLOOR_CAVERN_GRUNT_2
# 81 "data/maps/SeafloorCavern_Room9/scripts.pory"
	msgbox SeafloorCavern_Room9_Text_ArchieWhereDidKyogreGo, MSGBOX_DEFAULT
# 82 "data/maps/SeafloorCavern_Room9/scripts.pory"
	playse SE_PC_LOGIN
# 83 "data/maps/SeafloorCavern_Room9/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 84 "data/maps/SeafloorCavern_Room9/scripts.pory"
	waitmovement 0
# 85 "data/maps/SeafloorCavern_Room9/scripts.pory"
	msgbox SeafloorCavern_Room9_Text_ArchieAMessageFromOutside, MSGBOX_DEFAULT
# 86 "data/maps/SeafloorCavern_Room9/scripts.pory"
	closemessage
# 87 "data/maps/SeafloorCavern_Room9/scripts.pory"
	applymovement VAR_0x8004, SeafloorCavern_Room9_Movement_ArchieListenMessage
# 88 "data/maps/SeafloorCavern_Room9/scripts.pory"
	waitmovement 0
# 89 "data/maps/SeafloorCavern_Room9/scripts.pory"
	msgbox SeafloorCavern_Room9_Text_ArchieWhatRainingTooHard, MSGBOX_DEFAULT
# 90 "data/maps/SeafloorCavern_Room9/scripts.pory"
	closemessage
# 91 "data/maps/SeafloorCavern_Room9/scripts.pory"
	playse SE_PC_OFF
# 92 "data/maps/SeafloorCavern_Room9/scripts.pory"
	delay 20
# 93 "data/maps/SeafloorCavern_Room9/scripts.pory"
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFasterDown
# 94 "data/maps/SeafloorCavern_Room9/scripts.pory"
	waitmovement 0
# 95 "data/maps/SeafloorCavern_Room9/scripts.pory"
	msgbox SeafloorCavern_Room9_Text_ArchieWhyDidKyogreDisappear, MSGBOX_DEFAULT
# 96 "data/maps/SeafloorCavern_Room9/scripts.pory"
	closemessage
# 97 "data/maps/SeafloorCavern_Room9/scripts.pory"
	addobject VAR_0x8005
# 98 "data/maps/SeafloorCavern_Room9/scripts.pory"
	addobject VAR_0x8006
# 99 "data/maps/SeafloorCavern_Room9/scripts.pory"
	addobject VAR_0x8007
# 100 "data/maps/SeafloorCavern_Room9/scripts.pory"
	applymovement VAR_0x8007, SeafloorCavern_Room9_Movement_MagmaGruntArrive
# 101 "data/maps/SeafloorCavern_Room9/scripts.pory"
	applymovement VAR_0x8006, SeafloorCavern_Room9_Movement_MagmaGruntArrive
# 102 "data/maps/SeafloorCavern_Room9/scripts.pory"
	applymovement VAR_0x8005, SeafloorCavern_Room9_Movement_MaxieArrive
# 103 "data/maps/SeafloorCavern_Room9/scripts.pory"
	waitmovement 0
# 104 "data/maps/SeafloorCavern_Room9/scripts.pory"
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFasterLeft
# 105 "data/maps/SeafloorCavern_Room9/scripts.pory"
	waitmovement 0
# 106 "data/maps/SeafloorCavern_Room9/scripts.pory"
	msgbox SeafloorCavern_Room9_Text_MaxieWhatHaveYouWrought, MSGBOX_DEFAULT
# 107 "data/maps/SeafloorCavern_Room9/scripts.pory"
	playse SE_PIN
# 108 "data/maps/SeafloorCavern_Room9/scripts.pory"
	applymovement VAR_0x8004, Common_Movement_ExclamationMark
# 109 "data/maps/SeafloorCavern_Room9/scripts.pory"
	waitmovement 0
# 110 "data/maps/SeafloorCavern_Room9/scripts.pory"
	applymovement VAR_0x8004, Common_Movement_Delay48
# 111 "data/maps/SeafloorCavern_Room9/scripts.pory"
	waitmovement 0
# 112 "data/maps/SeafloorCavern_Room9/scripts.pory"
	msgbox SeafloorCavern_Room9_Text_ArchieDontGetAllHighAndMighty, MSGBOX_DEFAULT
# 113 "data/maps/SeafloorCavern_Room9/scripts.pory"
	msgbox SeafloorCavern_Room9_Text_MaxieWeDontHaveTimeToArgue, MSGBOX_DEFAULT
# 114 "data/maps/SeafloorCavern_Room9/scripts.pory"
	closemessage
# 115 "data/maps/SeafloorCavern_Room9/scripts.pory"
	applymovement VAR_0x8005, SeafloorCavern_Room9_Movement_MaxieExit
# 116 "data/maps/SeafloorCavern_Room9/scripts.pory"
	applymovement VAR_0x8004, SeafloorCavern_Room9_Movement_ArchieExit
# 117 "data/maps/SeafloorCavern_Room9/scripts.pory"
	waitmovement 0
# 118 "data/maps/SeafloorCavern_Room9/scripts.pory"
	msgbox SeafloorCavern_Room9_Text_MaxieComeOnPlayer, MSGBOX_DEFAULT
# 119 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setvar VAR_ROUTE128_STATE, 1
# 120 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setvar VAR_SOOTOPOLIS_CITY_STATE, 1
# 121 "data/maps/SeafloorCavern_Room9/scripts.pory"
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_STEVEN
# 122 "data/maps/SeafloorCavern_Room9/scripts.pory"
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_ARCHIE
# 123 "data/maps/SeafloorCavern_Room9/scripts.pory"
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_MAXIE
# 124 "data/maps/SeafloorCavern_Room9/scripts.pory"
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_RESIDENTS
# 125 "data/maps/SeafloorCavern_Room9/scripts.pory"
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_GROUDON
# 126 "data/maps/SeafloorCavern_Room9/scripts.pory"
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_KYOGRE
# 127 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_MAN_1
# 128 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setflag FLAG_LEGENDARIES_IN_SOOTOPOLIS
# 129 "data/maps/SeafloorCavern_Room9/scripts.pory"
	clearflag FLAG_HIDE_ROUTE_128_ARCHIE
# 130 "data/maps/SeafloorCavern_Room9/scripts.pory"
	clearflag FLAG_HIDE_ROUTE_128_MAXIE
# 131 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setflag FLAG_SYS_WEATHER_CTRL
# 132 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setflag FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN
# 133 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setflag FLAG_HIDE_MOSSDEEP_CITY_STEVENS_HOUSE_STEVEN
# 134 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setvar VAR_STEVENS_HOUSE_STATE, 2
# 135 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setvar VAR_SEAFLOOR_CAVERN_STATE, 1
# 136 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_ROOM_9_ARCHIE
# 137 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_ROOM_9_MAXIE
# 138 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_ROOM_9_MAGMA_GRUNTS
# 139 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_ROOM_9_KYOGRE
# 140 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_AQUA_GRUNTS
# 141 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setflag FLAG_HIDE_MAP_NAME_POPUP
# 142 "data/maps/SeafloorCavern_Room9/scripts.pory"
	warp MAP_ROUTE128, 38, 22
# 143 "data/maps/SeafloorCavern_Room9/scripts.pory"
	waitstate
# 144 "data/maps/SeafloorCavern_Room9/scripts.pory"
	releaseall
# 145 "data/maps/SeafloorCavern_Room9/scripts.pory"
	end
# 146 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 147 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_Movement_ArchieApproachPlayer:
# 148 "data/maps/SeafloorCavern_Room9/scripts.pory"
	walk_right
# 149 "data/maps/SeafloorCavern_Room9/scripts.pory"
	walk_right
# 150 "data/maps/SeafloorCavern_Room9/scripts.pory"
	walk_right
# 151 "data/maps/SeafloorCavern_Room9/scripts.pory"
	walk_right
# 152 "data/maps/SeafloorCavern_Room9/scripts.pory"
	walk_right
# 153 "data/maps/SeafloorCavern_Room9/scripts.pory"
	walk_right
# 154 "data/maps/SeafloorCavern_Room9/scripts.pory"
	walk_right
# 155 "data/maps/SeafloorCavern_Room9/scripts.pory"
	step_end
# 156 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 157 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_Movement_Unused1:
# 158 "data/maps/SeafloorCavern_Room9/scripts.pory"
	walk_left
# 159 "data/maps/SeafloorCavern_Room9/scripts.pory"
	walk_left
# 160 "data/maps/SeafloorCavern_Room9/scripts.pory"
	step_end
# 161 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 162 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_Movement_ArchieListenMessage:
# 163 "data/maps/SeafloorCavern_Room9/scripts.pory"
	walk_left
# 164 "data/maps/SeafloorCavern_Room9/scripts.pory"
	delay_16
# 165 "data/maps/SeafloorCavern_Room9/scripts.pory"
	step_end
# 166 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 167 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_Movement_Unused2:
# 168 "data/maps/SeafloorCavern_Room9/scripts.pory"
	walk_right
# 169 "data/maps/SeafloorCavern_Room9/scripts.pory"
	step_end
# 170 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 171 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_Movement_ArchieExit:
# 172 "data/maps/SeafloorCavern_Room9/scripts.pory"
	face_up
# 173 "data/maps/SeafloorCavern_Room9/scripts.pory"
	lock_facing_direction
# 174 "data/maps/SeafloorCavern_Room9/scripts.pory"
	walk_down
# 175 "data/maps/SeafloorCavern_Room9/scripts.pory"
	unlock_facing_direction
# 176 "data/maps/SeafloorCavern_Room9/scripts.pory"
	walk_in_place_faster_right
# 177 "data/maps/SeafloorCavern_Room9/scripts.pory"
	step_end
# 178 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 179 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_Movement_KyogreApproach:
# 180 "data/maps/SeafloorCavern_Room9/scripts.pory"
	delay_16
# 181 "data/maps/SeafloorCavern_Room9/scripts.pory"
	delay_16
# 182 "data/maps/SeafloorCavern_Room9/scripts.pory"
	walk_slow_down
# 183 "data/maps/SeafloorCavern_Room9/scripts.pory"
	delay_16
# 184 "data/maps/SeafloorCavern_Room9/scripts.pory"
	delay_16
# 185 "data/maps/SeafloorCavern_Room9/scripts.pory"
	delay_16
# 186 "data/maps/SeafloorCavern_Room9/scripts.pory"
	walk_slow_down
# 187 "data/maps/SeafloorCavern_Room9/scripts.pory"
	delay_16
# 188 "data/maps/SeafloorCavern_Room9/scripts.pory"
	delay_16
# 189 "data/maps/SeafloorCavern_Room9/scripts.pory"
	delay_16
# 190 "data/maps/SeafloorCavern_Room9/scripts.pory"
	step_end
# 191 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 192 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_Movement_KyogreExit:
# 193 "data/maps/SeafloorCavern_Room9/scripts.pory"
	slide_up
# 194 "data/maps/SeafloorCavern_Room9/scripts.pory"
	slide_up
# 195 "data/maps/SeafloorCavern_Room9/scripts.pory"
	step_end
# 196 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 197 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_Movement_MaxieArrive:
# 198 "data/maps/SeafloorCavern_Room9/scripts.pory"
	walk_fast_right
# 199 "data/maps/SeafloorCavern_Room9/scripts.pory"
	walk_fast_right
# 200 "data/maps/SeafloorCavern_Room9/scripts.pory"
	walk_fast_right
# 201 "data/maps/SeafloorCavern_Room9/scripts.pory"
	walk_fast_right
# 202 "data/maps/SeafloorCavern_Room9/scripts.pory"
	walk_fast_right
# 203 "data/maps/SeafloorCavern_Room9/scripts.pory"
	step_end
# 204 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 205 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_Movement_MaxieExit:
# 206 "data/maps/SeafloorCavern_Room9/scripts.pory"
	walk_right
# 207 "data/maps/SeafloorCavern_Room9/scripts.pory"
	walk_right
# 208 "data/maps/SeafloorCavern_Room9/scripts.pory"
	step_end
# 209 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 210 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_Movement_MagmaGruntArrive:
# 211 "data/maps/SeafloorCavern_Room9/scripts.pory"
	walk_fast_right
# 212 "data/maps/SeafloorCavern_Room9/scripts.pory"
	walk_fast_right
# 213 "data/maps/SeafloorCavern_Room9/scripts.pory"
	walk_fast_right
# 214 "data/maps/SeafloorCavern_Room9/scripts.pory"
	walk_fast_right
# 215 "data/maps/SeafloorCavern_Room9/scripts.pory"
	step_end
# 216 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 217 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_Movement_Delay32:
# 218 "data/maps/SeafloorCavern_Room9/scripts.pory"
	delay_16
# 219 "data/maps/SeafloorCavern_Room9/scripts.pory"
	delay_16
# 220 "data/maps/SeafloorCavern_Room9/scripts.pory"
	step_end
# 221 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 222 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_Text_ArchieHoldItRightThere:
# 223 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "ARCHIE: Hold it right there.$"
# 224 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 225 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_Text_ArchieSoItWasYou:
# 226 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "ARCHIE: Fufufu…\n"
# 227 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "So it was you, after all.$"
# 228 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 229 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_Text_ArchieBeholdKyogre:
# 230 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "ARCHIE: Behold!\p"
# 231 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "See how beautiful it is, the sleeping\n"
# 232 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "form of the ancient POKéMON KYOGRE!\p"
# 233 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "I have waited so long for this day to\n"
# 234 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "come…$"
# 235 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 236 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_Text_ArchieYouMustDisappear:
# 237 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "ARCHIE: It surprises me, how you've\n"
# 238 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "managed to chase me here.\p"
# 239 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "But that's all over now.\p"
# 240 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "For the realization of my dream,\n"
# 241 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "you must disappear now!$"
# 242 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 243 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_Text_ArchieDefeat:
# 244 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "What?!\n"
# 245 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "I lost to a mere child like you?!$"
# 246 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 247 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_Text_ArchieWithThisRedOrb:
# 248 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "ARCHIE: Fufufu…\p"
# 249 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "I commend you. I must recognize that\n"
# 250 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "you are truly gifted.\p"
# 251 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "But!\n"
# 252 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "I have this in my possession!\p"
# 253 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "With this RED ORB, I can make KYOGRE…$"
# 254 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 255 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_Text_RedOrbShinesByItself:
# 256 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "The RED ORB suddenly began shining\n"
# 257 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "by itself!$"
# 258 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 259 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_Text_ArchieWhereDidKyogreGo:
# 260 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "ARCHIE: What?!\p"
# 261 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "I didn't do anything.\n"
# 262 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "Why did the RED ORB…\p"
# 263 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "Where did KYOGRE go?$"
# 264 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 265 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_Text_ArchieAMessageFromOutside:
# 266 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "ARCHIE: Hm? It's a message from our\n"
# 267 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "members outside…$"
# 268 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 269 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_Text_ArchieWhatRainingTooHard:
# 270 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "ARCHIE: Yes, what is it?\p"
# 271 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "Hm…\n"
# 272 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "It's raining heavily?\p"
# 273 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "Good… That should have happened.\n"
# 274 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "That is why we awakened KYOGRE,\l"
# 275 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "to realize TEAM AQUA's vision of\l"
# 276 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "expanding the sea.\p"
# 277 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "What?!\p"
# 278 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "It's raining far harder than we\n"
# 279 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "envisioned? You're in danger?\p"
# 280 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "That can't be…\n"
# 281 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "That's just not possible…\p"
# 282 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "Hold your position and monitor\n"
# 283 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "the situation!$"
# 284 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 285 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_Text_ArchieWhyDidKyogreDisappear:
# 286 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "ARCHIE: There's something wrong…\p"
# 287 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "The RED ORB is supposed to awaken\n"
# 288 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "and control KYOGRE…\p"
# 289 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "But… Why?\n"
# 290 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "Why did KYOGRE disappear?\p"
# 291 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "Why?!$"
# 292 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 293 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_Text_MaxieWhatHaveYouWrought:
# 294 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "MAXIE: What have you wrought?\p"
# 295 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "ARCHIE… You've finally awoken KYOGRE,\n"
# 296 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "haven't you?\p"
# 297 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "What will happen to the world if this\n"
# 298 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "downpour continues for all eternity?\p"
# 299 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "The world's landmass will drown in\n"
# 300 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "the deepening sea…$"
# 301 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 302 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_Text_ArchieDontGetAllHighAndMighty:
# 303 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "ARCHIE: W-what?!\n"
# 304 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "Don't get all high and mighty with me!\p"
# 305 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "Wasn't it you, TEAM MAGMA, that\n"
# 306 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "infuriated GROUDON?\p"
# 307 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "So long as I have this RED ORB,\n"
# 308 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "I should be able to control KYOGRE…\p"
# 309 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "I should be able to control it…$"
# 310 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 311 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_Text_MaxieWeDontHaveTimeToArgue:
# 312 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "MAXIE: We don't have the time to\n"
# 313 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "argue about it here!\p"
# 314 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "Get outside and see for yourself!\p"
# 315 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "See if what you've wrought is the\n"
# 316 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "world that we desired!$"
# 317 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 318 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_Text_MaxieComeOnPlayer:
# 319 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "MAXIE: {PLAYER}, come on, you have\n"
# 320 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "to get out of here, too!$"
