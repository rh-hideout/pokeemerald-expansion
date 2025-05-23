# 1 "data/maps/LittlerootTown/scripts.pory"

# 2 "data/maps/LittlerootTown/scripts.pory"
.set LOCALID_TWIN, 1
# 3 "data/maps/LittlerootTown/scripts.pory"
.set LOCALID_MOM, 4
# 4 "data/maps/LittlerootTown/scripts.pory"
.set LOCALID_RIVAL, 7
# 5 "data/maps/LittlerootTown/scripts.pory"
.set LOCALID_BIRCH, 8
# 6 "data/maps/LittlerootTown/scripts.pory"

# 7 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_MapScripts::
# 8 "data/maps/LittlerootTown/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_OnTransition
# 9 "data/maps/LittlerootTown/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_OnFrame
# 10 "data/maps/LittlerootTown/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, LittlerootTown_OnWarp
# 11 "data/maps/LittlerootTown/scripts.pory"
	.byte 0
# 12 "data/maps/LittlerootTown/scripts.pory"

# 13 "data/maps/LittlerootTown/scripts.pory"
	@ State descriptions for VAR_LITTLEROOT_TOWN_STATE
# 14 "data/maps/LittlerootTown/scripts.pory"
	@ 1: Met Rival
# 15 "data/maps/LittlerootTown/scripts.pory"
	@ 2: Saving Birch
# 16 "data/maps/LittlerootTown/scripts.pory"
	@ 3: Received Pokedex
# 17 "data/maps/LittlerootTown/scripts.pory"
	@ 4: Received Running Shoes
# 18 "data/maps/LittlerootTown/scripts.pory"

# 19 "data/maps/LittlerootTown/scripts.pory"
	@ State descriptions for VAR_LITTLEROOT_INTRO_STATE
# 20 "data/maps/LittlerootTown/scripts.pory"
	@ 1: In truck male
# 21 "data/maps/LittlerootTown/scripts.pory"
	@ 2: In truck female
# 22 "data/maps/LittlerootTown/scripts.pory"
	@ 3: Entered house
# 23 "data/maps/LittlerootTown/scripts.pory"
	@ 4: Told to go set clock
# 24 "data/maps/LittlerootTown/scripts.pory"
	@ 5: Entered 2F to set clock
# 25 "data/maps/LittlerootTown/scripts.pory"
	@ 6: Set clock
# 26 "data/maps/LittlerootTown/scripts.pory"
	@ 7: Told to go meet rival
# 27 "data/maps/LittlerootTown/scripts.pory"

# 28 "data/maps/LittlerootTown/scripts.pory"
	@ State descriptions for VAR_LITTLEROOT_HOUSES_STATE_MAY
# 29 "data/maps/LittlerootTown/scripts.pory"
	@                    and VAR_LITTLEROOT_HOUSES_STATE_BRENDAN
# 30 "data/maps/LittlerootTown/scripts.pory"
	@ 1: On Truck (and is corresponding gender)
# 31 "data/maps/LittlerootTown/scripts.pory"
	@ 2: Met Rival's Mom (and is corresponding gender)
# 32 "data/maps/LittlerootTown/scripts.pory"
	@ 3: Entered Hall of Fame
# 33 "data/maps/LittlerootTown/scripts.pory"
	@ 4: Completed Lati TV / SS Ticket event
# 34 "data/maps/LittlerootTown/scripts.pory"
	@ 5: Exited house after above event
# 35 "data/maps/LittlerootTown/scripts.pory"

# 36 "data/maps/LittlerootTown/scripts.pory"
	@ State descriptions for VAR_LITTLEROOT_RIVAL_STATE
# 37 "data/maps/LittlerootTown/scripts.pory"
	@ 1: Never occurs
# 38 "data/maps/LittlerootTown/scripts.pory"
	@ 2: Entered Rival's bedroom
# 39 "data/maps/LittlerootTown/scripts.pory"
	@ 3: Met Rival
# 40 "data/maps/LittlerootTown/scripts.pory"
	@ 4: Received Pokedex
# 41 "data/maps/LittlerootTown/scripts.pory"

# 42 "data/maps/LittlerootTown/scripts.pory"

# 43 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_OnTransition:
# 44 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_VISITED_LITTLEROOT_TOWN
# 45 "data/maps/LittlerootTown/scripts.pory"
	call Common_EventScript_SetupRivalGfxId
# 46 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 2, LittlerootTown_EventScript_MoveMomToMaysDoor
# 47 "data/maps/LittlerootTown/scripts.pory"
	call_if_unset FLAG_RESCUED_BIRCH, LittlerootTown_EventScript_SetTwinPos
# 48 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_LITTLEROOT_TOWN_STATE, 3, LittlerootTown_EventScript_SetMomStandingInFrontOfDoorPos
# 49 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_LITTLEROOT_HOUSES_STATE_MAY, 4, LittlerootTown_EventScript_SetExitedHouseAfterLatiSSTicketEvent
# 50 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_LITTLEROOT_HOUSES_STATE_BRENDAN, 4, LittlerootTown_EventScript_SetExitedHouseAfterLatiSSTicketEvent
# 51 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_OLDALE_RIVAL_STATE, 1, LittlerootTown_EventScript_MoveRivalFromOldale
# 52 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_LITTLEROOT_RIVAL_STATE, 3, LittlerootTown_EventScript_SetRivalLeftForRoute103
# 53 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 1, LittlerootTown_EventScript_HideMapNamePopup
# 54 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 2, LittlerootTown_EventScript_LeftLabAfterDexUpgrade
# 55 "data/maps/LittlerootTown/scripts.pory"
	end
# 56 "data/maps/LittlerootTown/scripts.pory"

# 57 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_LeftLabAfterDexUpgrade::
# 58 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 3
# 59 "data/maps/LittlerootTown/scripts.pory"
	return
# 60 "data/maps/LittlerootTown/scripts.pory"

# 61 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_HideMapNamePopup::
# 62 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_MAP_NAME_POPUP
# 63 "data/maps/LittlerootTown/scripts.pory"
	return
# 64 "data/maps/LittlerootTown/scripts.pory"

# 65 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetRivalLeftForRoute103::
# 66 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_RIVAL_LEFT_FOR_ROUTE103
# 67 "data/maps/LittlerootTown/scripts.pory"
	return
# 68 "data/maps/LittlerootTown/scripts.pory"

# 69 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MoveRivalFromOldale::
# 70 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_OLDALE_RIVAL_STATE, 2
# 71 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_OLDALE_TOWN_RIVAL
# 72 "data/maps/LittlerootTown/scripts.pory"
	return
# 73 "data/maps/LittlerootTown/scripts.pory"

# 74 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetExitedHouseAfterLatiSSTicketEvent::
# 75 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_MAY, 5
# 76 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_BRENDAN, 5
# 77 "data/maps/LittlerootTown/scripts.pory"
	return
# 78 "data/maps/LittlerootTown/scripts.pory"

# 79 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MoveMomToMaysDoor::
# 80 "data/maps/LittlerootTown/scripts.pory"
	setobjectxyperm LOCALID_MOM, 14, 8
# 81 "data/maps/LittlerootTown/scripts.pory"
	return
# 82 "data/maps/LittlerootTown/scripts.pory"

# 83 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetTwinPos::
# 84 "data/maps/LittlerootTown/scripts.pory"
	goto_if_eq VAR_LITTLEROOT_TOWN_STATE, 0, LittlerootTown_EventScript_SetTwinGuardingRoutePos
# 85 "data/maps/LittlerootTown/scripts.pory"
	setobjectxyperm LOCALID_TWIN, 10, 1
# 86 "data/maps/LittlerootTown/scripts.pory"
	setobjectmovementtype LOCALID_TWIN, MOVEMENT_TYPE_FACE_UP
# 87 "data/maps/LittlerootTown/scripts.pory"
	return
# 88 "data/maps/LittlerootTown/scripts.pory"

# 89 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetTwinGuardingRoutePos::
# 90 "data/maps/LittlerootTown/scripts.pory"
	setobjectxyperm LOCALID_TWIN, 7, 2
# 91 "data/maps/LittlerootTown/scripts.pory"
	setobjectmovementtype LOCALID_TWIN, MOVEMENT_TYPE_FACE_DOWN
# 92 "data/maps/LittlerootTown/scripts.pory"
	return
# 93 "data/maps/LittlerootTown/scripts.pory"

# 94 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetMomStandingInFrontOfDoorPos::
# 95 "data/maps/LittlerootTown/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MOM_OUTSIDE
# 96 "data/maps/LittlerootTown/scripts.pory"
	setobjectmovementtype LOCALID_MOM, MOVEMENT_TYPE_FACE_DOWN
# 97 "data/maps/LittlerootTown/scripts.pory"
	checkplayergender
# 98 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, MALE, LittlerootTown_EventScript_SetMomInFrontOfDoorMale
# 99 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_EventScript_SetMomInFrontOfDoorFemale
# 100 "data/maps/LittlerootTown/scripts.pory"
	return
# 101 "data/maps/LittlerootTown/scripts.pory"

# 102 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetMomInFrontOfDoorMale::
# 103 "data/maps/LittlerootTown/scripts.pory"
	setobjectxyperm LOCALID_MOM, 5, 9
# 104 "data/maps/LittlerootTown/scripts.pory"
	return
# 105 "data/maps/LittlerootTown/scripts.pory"

# 106 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetMomInFrontOfDoorFemale::
# 107 "data/maps/LittlerootTown/scripts.pory"
	setobjectxyperm LOCALID_MOM, 14, 9
# 108 "data/maps/LittlerootTown/scripts.pory"
	return
# 109 "data/maps/LittlerootTown/scripts.pory"

# 110 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_OnFrame:
# 111 "data/maps/LittlerootTown/scripts.pory"
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 1, LittlerootTown_EventScript_StepOffTruckMale
# 112 "data/maps/LittlerootTown/scripts.pory"
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 2, LittlerootTown_EventScript_StepOffTruckFemale
# 113 "data/maps/LittlerootTown/scripts.pory"
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 1, LittlerootTown_EventScript_BeginDexUpgradeScene
# 114 "data/maps/LittlerootTown/scripts.pory"
	.2byte 0
# 115 "data/maps/LittlerootTown/scripts.pory"

# 116 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_StepOffTruckMale::
# 117 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 118 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8004, 5
# 119 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8005, 8
# 120 "data/maps/LittlerootTown/scripts.pory"
	call LittlerootTown_EventScript_GoInsideWithMom
# 121 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_TRUCK
# 122 "data/maps/LittlerootTown/scripts.pory"
	warpsilent MAP_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F, 8, 8
# 123 "data/maps/LittlerootTown/scripts.pory"
	waitstate
# 124 "data/maps/LittlerootTown/scripts.pory"
	releaseall
# 125 "data/maps/LittlerootTown/scripts.pory"
	end
# 126 "data/maps/LittlerootTown/scripts.pory"

# 127 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_StepOffTruckFemale::
# 128 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 129 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8004, 14
# 130 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8005, 8
# 131 "data/maps/LittlerootTown/scripts.pory"
	call LittlerootTown_EventScript_GoInsideWithMom
# 132 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_TRUCK
# 133 "data/maps/LittlerootTown/scripts.pory"
	warpsilent MAP_LITTLEROOT_TOWN_MAYS_HOUSE_1F, 2, 8
# 134 "data/maps/LittlerootTown/scripts.pory"
	waitstate
# 135 "data/maps/LittlerootTown/scripts.pory"
	releaseall
# 136 "data/maps/LittlerootTown/scripts.pory"
	end
# 137 "data/maps/LittlerootTown/scripts.pory"

# 138 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_GoInsideWithMom::
# 139 "data/maps/LittlerootTown/scripts.pory"
	delay 15
# 140 "data/maps/LittlerootTown/scripts.pory"
	playse SE_LEDGE
# 141 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_Movement_PlayerStepOffTruck
# 142 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 143 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8004, VAR_0x8005
# 144 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 145 "data/maps/LittlerootTown/scripts.pory"
	addobject LOCALID_MOM
# 146 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomExitHouse
# 147 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 148 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8004, VAR_0x8005
# 149 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 150 "data/maps/LittlerootTown/scripts.pory"
	delay 10
# 151 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomApproachPlayerAtTruck
# 152 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 153 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_OurNewHomeLetsGoInside, MSGBOX_DEFAULT
# 154 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 155 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomApproachDoor
# 156 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_Movement_PlayerApproachDoor
# 157 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 158 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8004, VAR_0x8005
# 159 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 160 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomEnterHouse
# 161 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_Movement_PlayerEnterHouse
# 162 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 163 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MOM_OUTSIDE
# 164 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_INTRO_STATE, 3
# 165 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat OBJ_EVENT_ID_PLAYER, 0
# 166 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8004, VAR_0x8005
# 167 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 168 "data/maps/LittlerootTown/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_FAT_MAN
# 169 "data/maps/LittlerootTown/scripts.pory"
	clearflag FLAG_HIDE_MAP_NAME_POPUP
# 170 "data/maps/LittlerootTown/scripts.pory"
	return
# 171 "data/maps/LittlerootTown/scripts.pory"

# 172 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomExitHouse:
# 173 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 174 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 175 "data/maps/LittlerootTown/scripts.pory"

# 176 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerAtTruck:
# 177 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 178 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_left
# 179 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 180 "data/maps/LittlerootTown/scripts.pory"

# 181 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachDoor:
# 182 "data/maps/LittlerootTown/scripts.pory"
	delay_16
# 183 "data/maps/LittlerootTown/scripts.pory"
	delay_8
# 184 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 185 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 186 "data/maps/LittlerootTown/scripts.pory"

# 187 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomEnterHouse:
# 188 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 189 "data/maps/LittlerootTown/scripts.pory"
	set_invisible
# 190 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 191 "data/maps/LittlerootTown/scripts.pory"

# 192 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_PlayerApproachDoor:
# 193 "data/maps/LittlerootTown/scripts.pory"
	delay_16
# 194 "data/maps/LittlerootTown/scripts.pory"
	delay_8
# 195 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 196 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
# 197 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 198 "data/maps/LittlerootTown/scripts.pory"

# 199 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_PlayerEnterHouse:
# 200 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 201 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 202 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 203 "data/maps/LittlerootTown/scripts.pory"

# 204 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_PlayerStepOffTruck:
# 205 "data/maps/LittlerootTown/scripts.pory"
	jump_right
# 206 "data/maps/LittlerootTown/scripts.pory"
	delay_16
# 207 "data/maps/LittlerootTown/scripts.pory"
	delay_16
# 208 "data/maps/LittlerootTown/scripts.pory"
	delay_16
# 209 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 210 "data/maps/LittlerootTown/scripts.pory"

# 211 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_BeginDexUpgradeScene::
# 212 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 213 "data/maps/LittlerootTown/scripts.pory"
	playse SE_PIN
# 214 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_BIRCH, Common_Movement_ExclamationMark
# 215 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 216 "data/maps/LittlerootTown/scripts.pory"
	delay 80
# 217 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_BirchSomethingToShowYouAtLab, MSGBOX_DEFAULT
# 218 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 219 "data/maps/LittlerootTown/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_RIVAL
# 220 "data/maps/LittlerootTown/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCH
# 221 "data/maps/LittlerootTown/scripts.pory"
	delay 20
# 222 "data/maps/LittlerootTown/scripts.pory"
	clearflag FLAG_HIDE_MAP_NAME_POPUP
# 223 "data/maps/LittlerootTown/scripts.pory"
	warp MAP_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB, 6, 5
# 224 "data/maps/LittlerootTown/scripts.pory"
	waitstate
# 225 "data/maps/LittlerootTown/scripts.pory"
	releaseall
# 226 "data/maps/LittlerootTown/scripts.pory"
	end
# 227 "data/maps/LittlerootTown/scripts.pory"

# 228 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_OnWarp:
# 229 "data/maps/LittlerootTown/scripts.pory"
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 1, LittlerootTown_EventScript_SetRivalBirchPosForDexUpgrade
# 230 "data/maps/LittlerootTown/scripts.pory"
	.2byte 0
# 231 "data/maps/LittlerootTown/scripts.pory"

# 232 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetRivalBirchPosForDexUpgrade::
# 233 "data/maps/LittlerootTown/scripts.pory"
	addobject LOCALID_BIRCH
# 234 "data/maps/LittlerootTown/scripts.pory"
	addobject LOCALID_RIVAL
# 235 "data/maps/LittlerootTown/scripts.pory"
	checkplayergender
# 236 "data/maps/LittlerootTown/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, LittlerootTown_EventScript_SetRivalBirchPosForDexUpgradeMale
# 237 "data/maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_SetRivalBirchPosForDexUpgradeFemale
# 238 "data/maps/LittlerootTown/scripts.pory"
	end
# 239 "data/maps/LittlerootTown/scripts.pory"

# 240 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetRivalBirchPosForDexUpgradeMale::
# 241 "data/maps/LittlerootTown/scripts.pory"
	setobjectxy LOCALID_RIVAL, 6, 10
# 242 "data/maps/LittlerootTown/scripts.pory"
	setobjectxy LOCALID_BIRCH, 5, 10
# 243 "data/maps/LittlerootTown/scripts.pory"
	end
# 244 "data/maps/LittlerootTown/scripts.pory"

# 245 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetRivalBirchPosForDexUpgradeFemale::
# 246 "data/maps/LittlerootTown/scripts.pory"
	setobjectxy LOCALID_RIVAL, 13, 10
# 247 "data/maps/LittlerootTown/scripts.pory"
	setobjectxy LOCALID_BIRCH, 14, 10
# 248 "data/maps/LittlerootTown/scripts.pory"
	end
# 249 "data/maps/LittlerootTown/scripts.pory"

# 250 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_FatMan::
# 251 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_CanUsePCToStoreItems, MSGBOX_NPC
# 252 "data/maps/LittlerootTown/scripts.pory"
	end
# 253 "data/maps/LittlerootTown/scripts.pory"

# 254 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_Boy::
# 255 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_BirchSpendsDaysInLab, MSGBOX_NPC
# 256 "data/maps/LittlerootTown/scripts.pory"
	end
# 257 "data/maps/LittlerootTown/scripts.pory"

# 258 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_Twin::
# 259 "data/maps/LittlerootTown/scripts.pory"
	lock
# 260 "data/maps/LittlerootTown/scripts.pory"
	faceplayer
# 261 "data/maps/LittlerootTown/scripts.pory"
	goto_if_set FLAG_ADVENTURE_STARTED, LittlerootTown_EventScript_GoodLuck
# 262 "data/maps/LittlerootTown/scripts.pory"
	goto_if_set FLAG_RESCUED_BIRCH, LittlerootTown_EventScript_YouSavedBirch
# 263 "data/maps/LittlerootTown/scripts.pory"
	goto_if_ne VAR_LITTLEROOT_TOWN_STATE, 0, LittlerootTown_EventScript_GoSaveBirch
# 264 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_IfYouGoInGrassPokemonWillJumpOut, MSGBOX_DEFAULT
# 265 "data/maps/LittlerootTown/scripts.pory"
	release
# 266 "data/maps/LittlerootTown/scripts.pory"
	end
# 267 "data/maps/LittlerootTown/scripts.pory"

# 268 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_GoSaveBirch::
# 269 "data/maps/LittlerootTown/scripts.pory"
	special GetPlayerBigGuyGirlString
# 270 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_CanYouGoSeeWhatsHappening, MSGBOX_DEFAULT
# 271 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 272 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_TWIN, Common_Movement_FaceOriginalDirection
# 273 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 274 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_TOWN_STATE, 2
# 275 "data/maps/LittlerootTown/scripts.pory"
	release
# 276 "data/maps/LittlerootTown/scripts.pory"
	end
# 277 "data/maps/LittlerootTown/scripts.pory"

# 278 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_YouSavedBirch::
# 279 "data/maps/LittlerootTown/scripts.pory"
	special GetPlayerBigGuyGirlString
# 280 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_YouSavedBirch, MSGBOX_DEFAULT
# 281 "data/maps/LittlerootTown/scripts.pory"
	release
# 282 "data/maps/LittlerootTown/scripts.pory"
	end
# 283 "data/maps/LittlerootTown/scripts.pory"

# 284 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_GoodLuck::
# 285 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_GoodLuckCatchingPokemon, MSGBOX_DEFAULT
# 286 "data/maps/LittlerootTown/scripts.pory"
	release
# 287 "data/maps/LittlerootTown/scripts.pory"
	end
# 288 "data/maps/LittlerootTown/scripts.pory"

# 289 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_NeedPokemonTriggerLeft::
# 290 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 291 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_TWIN, LittlerootTown_Movement_TwinApproachPlayerLeft
# 292 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 293 "data/maps/LittlerootTown/scripts.pory"
	call LittlerootTown_EventScript_DangerousWithoutPokemon
# 294 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_TWIN, LittlerootTown_Movement_TwinReturnLeft
# 295 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 296 "data/maps/LittlerootTown/scripts.pory"
	releaseall
# 297 "data/maps/LittlerootTown/scripts.pory"
	end
# 298 "data/maps/LittlerootTown/scripts.pory"

# 299 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_DangerousWithoutPokemon::
# 300 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_IfYouGoInGrassPokemonWillJumpOut, MSGBOX_DEFAULT
# 301 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 302 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_TWIN, LittlerootTown_Movement_TwinPushPlayerFromRoute
# 303 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_Movement_PushPlayerBackFromRoute
# 304 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 305 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_DangerousIfYouDontHavePokemon, MSGBOX_DEFAULT
# 306 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 307 "data/maps/LittlerootTown/scripts.pory"
	return
# 308 "data/maps/LittlerootTown/scripts.pory"

# 309 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_TwinApproachPlayerLeft:
# 310 "data/maps/LittlerootTown/scripts.pory"
	face_right
# 311 "data/maps/LittlerootTown/scripts.pory"
	delay_8
# 312 "data/maps/LittlerootTown/scripts.pory"
	disable_jump_landing_ground_effect
# 313 "data/maps/LittlerootTown/scripts.pory"
	jump_in_place_right
# 314 "data/maps/LittlerootTown/scripts.pory"
	delay_8
# 315 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 316 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 317 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 318 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 319 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_up
# 320 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_up
# 321 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_left
# 322 "data/maps/LittlerootTown/scripts.pory"
	face_down
# 323 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 324 "data/maps/LittlerootTown/scripts.pory"

# 325 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_TwinPushPlayerFromRoute:
# 326 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 327 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 328 "data/maps/LittlerootTown/scripts.pory"

# 329 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_TwinReturnLeft:
# 330 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 331 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 332 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 333 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 334 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 335 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 336 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 337 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 338 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_down
# 339 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 340 "data/maps/LittlerootTown/scripts.pory"

# 341 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_PushPlayerBackFromRoute:
# 342 "data/maps/LittlerootTown/scripts.pory"
	lock_facing_direction
# 343 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 344 "data/maps/LittlerootTown/scripts.pory"
	unlock_facing_direction
# 345 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 346 "data/maps/LittlerootTown/scripts.pory"

# 347 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_NeedPokemonTriggerRight::
# 348 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 349 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_TWIN, LittlerootTown_Movement_TwinApproachPlayerRight
# 350 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 351 "data/maps/LittlerootTown/scripts.pory"
	call LittlerootTown_EventScript_DangerousWithoutPokemon
# 352 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_TWIN, LittlerootTown_Movement_TwinReturnRight
# 353 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 354 "data/maps/LittlerootTown/scripts.pory"
	releaseall
# 355 "data/maps/LittlerootTown/scripts.pory"
	end
# 356 "data/maps/LittlerootTown/scripts.pory"

# 357 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_TwinApproachPlayerRight:
# 358 "data/maps/LittlerootTown/scripts.pory"
	face_right
# 359 "data/maps/LittlerootTown/scripts.pory"
	delay_8
# 360 "data/maps/LittlerootTown/scripts.pory"
	disable_jump_landing_ground_effect
# 361 "data/maps/LittlerootTown/scripts.pory"
	jump_in_place_right
# 362 "data/maps/LittlerootTown/scripts.pory"
	delay_8
# 363 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 364 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 365 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 366 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_up
# 367 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_up
# 368 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 369 "data/maps/LittlerootTown/scripts.pory"
	face_down
# 370 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 371 "data/maps/LittlerootTown/scripts.pory"

# 372 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_TwinReturnRight:
# 373 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 374 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 375 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 376 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 377 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 378 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_down
# 379 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 380 "data/maps/LittlerootTown/scripts.pory"

# 381 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_GoSaveBirchTrigger::
# 382 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 383 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_TWIN, Common_Movement_WalkInPlaceFasterRight
# 384 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 385 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 386 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 387 "data/maps/LittlerootTown/scripts.pory"
	special GetPlayerBigGuyGirlString
# 388 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_CanYouGoSeeWhatsHappening, MSGBOX_DEFAULT
# 389 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 390 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_TWIN, Common_Movement_FaceOriginalDirection
# 391 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 392 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_TOWN_STATE, 2
# 393 "data/maps/LittlerootTown/scripts.pory"
	releaseall
# 394 "data/maps/LittlerootTown/scripts.pory"
	end
# 395 "data/maps/LittlerootTown/scripts.pory"

# 396 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_TownSign::
# 397 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_TownSign, MSGBOX_SIGN
# 398 "data/maps/LittlerootTown/scripts.pory"
	end
# 399 "data/maps/LittlerootTown/scripts.pory"

# 400 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_BirchsLabSign::
# 401 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_ProfBirchsLab, MSGBOX_SIGN
# 402 "data/maps/LittlerootTown/scripts.pory"
	end
# 403 "data/maps/LittlerootTown/scripts.pory"

# 404 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_BrendansHouseSign::
# 405 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 406 "data/maps/LittlerootTown/scripts.pory"
	checkplayergender
# 407 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, MALE, LittlerootTown_EventScript_PlayersHouseSignMale
# 408 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_EventScript_BirchsHouseSignFemale
# 409 "data/maps/LittlerootTown/scripts.pory"
	releaseall
# 410 "data/maps/LittlerootTown/scripts.pory"
	end
# 411 "data/maps/LittlerootTown/scripts.pory"

# 412 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_PlayersHouseSignMale::
# 413 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_PlayersHouse, MSGBOX_DEFAULT
# 414 "data/maps/LittlerootTown/scripts.pory"
	return
# 415 "data/maps/LittlerootTown/scripts.pory"

# 416 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_BirchsHouseSignFemale::
# 417 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_ProfBirchsHouse, MSGBOX_DEFAULT
# 418 "data/maps/LittlerootTown/scripts.pory"
	return
# 419 "data/maps/LittlerootTown/scripts.pory"

# 420 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MaysHouseSign::
# 421 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 422 "data/maps/LittlerootTown/scripts.pory"
	checkplayergender
# 423 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, MALE, LittlerootTown_EventScript_BirchsHouseSignMale
# 424 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_EventScript_PlayersHouseSignFemale
# 425 "data/maps/LittlerootTown/scripts.pory"
	releaseall
# 426 "data/maps/LittlerootTown/scripts.pory"
	end
# 427 "data/maps/LittlerootTown/scripts.pory"

# 428 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_BirchsHouseSignMale::
# 429 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_ProfBirchsHouse, MSGBOX_DEFAULT
# 430 "data/maps/LittlerootTown/scripts.pory"
	return
# 431 "data/maps/LittlerootTown/scripts.pory"

# 432 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_PlayersHouseSignFemale::
# 433 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_PlayersHouse, MSGBOX_DEFAULT
# 434 "data/maps/LittlerootTown/scripts.pory"
	return
# 435 "data/maps/LittlerootTown/scripts.pory"

# 436 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_GiveRunningShoesTrigger0::
# 437 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 438 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8008, 0
# 439 "data/maps/LittlerootTown/scripts.pory"
	setobjectxy LOCALID_MOM, 10, 9
# 440 "data/maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
# 441 "data/maps/LittlerootTown/scripts.pory"
	end
# 442 "data/maps/LittlerootTown/scripts.pory"

# 443 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_GiveRunningShoesTrigger1::
# 444 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 445 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8008, 1
# 446 "data/maps/LittlerootTown/scripts.pory"
	setobjectxy LOCALID_MOM, 11, 9
# 447 "data/maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
# 448 "data/maps/LittlerootTown/scripts.pory"
	end
# 449 "data/maps/LittlerootTown/scripts.pory"

# 450 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_GiveRunningShoesTrigger2::
# 451 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 452 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8008, 2
# 453 "data/maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
# 454 "data/maps/LittlerootTown/scripts.pory"
	end
# 455 "data/maps/LittlerootTown/scripts.pory"

# 456 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_GiveRunningShoesTrigger3::
# 457 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 458 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8008, 3
# 459 "data/maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
# 460 "data/maps/LittlerootTown/scripts.pory"
	end
# 461 "data/maps/LittlerootTown/scripts.pory"

# 462 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_GiveRunningShoesTrigger4::
# 463 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 464 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8008, 4
# 465 "data/maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
# 466 "data/maps/LittlerootTown/scripts.pory"
	end
# 467 "data/maps/LittlerootTown/scripts.pory"

# 468 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_GiveRunningShoesTrigger5::
# 469 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 470 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8008, 5
# 471 "data/maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
# 472 "data/maps/LittlerootTown/scripts.pory"
	end
# 473 "data/maps/LittlerootTown/scripts.pory"

# 474 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_GiveRunningShoesTrigger::
# 475 "data/maps/LittlerootTown/scripts.pory"
	checkplayergender
# 476 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, MALE, LittlerootTown_EventScript_MomNoticePlayerMale
# 477 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_EventScript_MomNoticePlayerFemale
# 478 "data/maps/LittlerootTown/scripts.pory"
	checkplayergender
# 479 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, MALE, LittlerootTown_EventScript_SetHomeDoorCoordsMale
# 480 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_EventScript_SetHomeDoorCoordsFemale
# 481 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_WaitPlayer, MSGBOX_DEFAULT
# 482 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 483 "data/maps/LittlerootTown/scripts.pory"
	checkplayergender
# 484 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, MALE, LittlerootTown_EventScript_MomApproachPlayerMale
# 485 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_EventScript_MomApproachPlayerFemale
# 486 "data/maps/LittlerootTown/scripts.pory"
	call LittlerootTown_EventScript_GiveRunningShoes
# 487 "data/maps/LittlerootTown/scripts.pory"
	checkplayergender
# 488 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, MALE, LittlerootTown_EventScript_MomReturnHomeMale
# 489 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_EventScript_MomReturnHomeFemale
# 490 "data/maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_SetReceivedRunningShoes
# 491 "data/maps/LittlerootTown/scripts.pory"
	end
# 492 "data/maps/LittlerootTown/scripts.pory"

# 493 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetHomeDoorCoordsMale::
# 494 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8009, 5
# 495 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x800A, 8
# 496 "data/maps/LittlerootTown/scripts.pory"
	return
# 497 "data/maps/LittlerootTown/scripts.pory"

# 498 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetHomeDoorCoordsFemale::
# 499 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8009, 14
# 500 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x800A, 8
# 501 "data/maps/LittlerootTown/scripts.pory"
	return
# 502 "data/maps/LittlerootTown/scripts.pory"

# 503 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomNoticePlayerMale::
# 504 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, Common_Movement_WalkInPlaceFasterRight
# 505 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 506 "data/maps/LittlerootTown/scripts.pory"
	return
# 507 "data/maps/LittlerootTown/scripts.pory"

# 508 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomNoticePlayerFemale::
# 509 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, Common_Movement_WalkInPlaceFasterLeft
# 510 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 511 "data/maps/LittlerootTown/scripts.pory"
	return
# 512 "data/maps/LittlerootTown/scripts.pory"

# 513 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayerMale::
# 514 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 0, LittlerootTown_EventScript_MomApproachPlayer0
# 515 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 1, LittlerootTown_EventScript_MomApproachPlayer1
# 516 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 2, LittlerootTown_EventScript_MomApproachPlayerMale2
# 517 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 3, LittlerootTown_EventScript_MomApproachPlayerMale3
# 518 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 4, LittlerootTown_EventScript_MomApproachPlayerMale4
# 519 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 5, LittlerootTown_EventScript_MomApproachPlayerMale5
# 520 "data/maps/LittlerootTown/scripts.pory"
	return
# 521 "data/maps/LittlerootTown/scripts.pory"

# 522 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayerFemale::
# 523 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 0, LittlerootTown_EventScript_MomApproachPlayer0
# 524 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 1, LittlerootTown_EventScript_MomApproachPlayer1
# 525 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 2, LittlerootTown_EventScript_MomApproachPlayerFemale2
# 526 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 3, LittlerootTown_EventScript_MomApproachPlayerFemale3
# 527 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 4, LittlerootTown_EventScript_MomApproachPlayerFemale4
# 528 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 5, LittlerootTown_EventScript_MomApproachPlayerFemale5
# 529 "data/maps/LittlerootTown/scripts.pory"
	return
# 530 "data/maps/LittlerootTown/scripts.pory"

# 531 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayer0::
# 532 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 533 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 534 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomApproachPlayer0
# 535 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 536 "data/maps/LittlerootTown/scripts.pory"
	return
# 537 "data/maps/LittlerootTown/scripts.pory"

# 538 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayer1::
# 539 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 540 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 541 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomApproachPlayer1
# 542 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 543 "data/maps/LittlerootTown/scripts.pory"
	return
# 544 "data/maps/LittlerootTown/scripts.pory"

# 545 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayerMale2::
# 546 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 547 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 548 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomApproachPlayerMale2
# 549 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 550 "data/maps/LittlerootTown/scripts.pory"
	return
# 551 "data/maps/LittlerootTown/scripts.pory"

# 552 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayerMale3::
# 553 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 554 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 555 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomApproachPlayerMale3
# 556 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 557 "data/maps/LittlerootTown/scripts.pory"
	return
# 558 "data/maps/LittlerootTown/scripts.pory"

# 559 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayerMale4::
# 560 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 561 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 562 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomApproachPlayerMale4
# 563 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 564 "data/maps/LittlerootTown/scripts.pory"
	return
# 565 "data/maps/LittlerootTown/scripts.pory"

# 566 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayerMale5::
# 567 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 568 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 569 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomApproachPlayerMale5
# 570 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 571 "data/maps/LittlerootTown/scripts.pory"
	return
# 572 "data/maps/LittlerootTown/scripts.pory"

# 573 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayerFemale2::
# 574 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 575 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 576 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomApproachPlayerFemale2
# 577 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 578 "data/maps/LittlerootTown/scripts.pory"
	return
# 579 "data/maps/LittlerootTown/scripts.pory"

# 580 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayerFemale3::
# 581 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 582 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 583 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomApproachPlayerFemale3
# 584 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 585 "data/maps/LittlerootTown/scripts.pory"
	return
# 586 "data/maps/LittlerootTown/scripts.pory"

# 587 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayerFemale4::
# 588 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 589 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 590 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomApproachPlayerFemale4
# 591 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 592 "data/maps/LittlerootTown/scripts.pory"
	return
# 593 "data/maps/LittlerootTown/scripts.pory"

# 594 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayerFemale5::
# 595 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 596 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 597 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomApproachPlayerFemale5
# 598 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 599 "data/maps/LittlerootTown/scripts.pory"
	return
# 600 "data/maps/LittlerootTown/scripts.pory"

# 601 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHomeMale::
# 602 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 0, LittlerootTown_EventScript_MomReturnHome0
# 603 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 1, LittlerootTown_EventScript_MomReturnHome1
# 604 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 2, LittlerootTown_EventScript_MomReturnHomeMale2
# 605 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 3, LittlerootTown_EventScript_MomReturnHomeMale3
# 606 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 4, LittlerootTown_EventScript_MomReturnHomeMale4
# 607 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 5, LittlerootTown_EventScript_MomReturnHomeMale5
# 608 "data/maps/LittlerootTown/scripts.pory"
	return
# 609 "data/maps/LittlerootTown/scripts.pory"

# 610 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHomeFemale::
# 611 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 0, LittlerootTown_EventScript_MomReturnHome0
# 612 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 1, LittlerootTown_EventScript_MomReturnHome1
# 613 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 2, LittlerootTown_EventScript_MomReturnHomeFemale2
# 614 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 3, LittlerootTown_EventScript_MomReturnHomeFemale3
# 615 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 4, LittlerootTown_EventScript_MomReturnHomeFemale4
# 616 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 5, LittlerootTown_EventScript_MomReturnHomeFemale5
# 617 "data/maps/LittlerootTown/scripts.pory"
	return
# 618 "data/maps/LittlerootTown/scripts.pory"

# 619 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHome0::
# 620 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomReturnHome0
# 621 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 622 "data/maps/LittlerootTown/scripts.pory"
	return
# 623 "data/maps/LittlerootTown/scripts.pory"

# 624 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHome1::
# 625 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomReturnHome1
# 626 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 627 "data/maps/LittlerootTown/scripts.pory"
	return
# 628 "data/maps/LittlerootTown/scripts.pory"

# 629 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHomeMale2::
# 630 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomReturnHomeMale2
# 631 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 632 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 633 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 634 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomExitThroughDoor
# 635 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 636 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat LOCALID_MOM, MAP_LITTLEROOT_TOWN
# 637 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 638 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 639 "data/maps/LittlerootTown/scripts.pory"
	return
# 640 "data/maps/LittlerootTown/scripts.pory"

# 641 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHomeMale3::
# 642 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomReturnHomeMale3
# 643 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 644 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 645 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 646 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomExitThroughDoor
# 647 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 648 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat LOCALID_MOM, MAP_LITTLEROOT_TOWN
# 649 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 650 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 651 "data/maps/LittlerootTown/scripts.pory"
	return
# 652 "data/maps/LittlerootTown/scripts.pory"

# 653 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHomeMale4::
# 654 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomReturnHomeMale4
# 655 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 656 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 657 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 658 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomExitThroughDoor
# 659 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 660 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat LOCALID_MOM, MAP_LITTLEROOT_TOWN
# 661 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 662 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 663 "data/maps/LittlerootTown/scripts.pory"
	return
# 664 "data/maps/LittlerootTown/scripts.pory"

# 665 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHomeMale5::
# 666 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomReturnHomeMale5
# 667 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 668 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 669 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 670 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomExitThroughDoor
# 671 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 672 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat LOCALID_MOM, MAP_LITTLEROOT_TOWN
# 673 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 674 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 675 "data/maps/LittlerootTown/scripts.pory"
	return
# 676 "data/maps/LittlerootTown/scripts.pory"

# 677 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHomeFemale2::
# 678 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomReturnHomeFemale2
# 679 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 680 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 681 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 682 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomExitThroughDoor
# 683 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 684 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat LOCALID_MOM, MAP_LITTLEROOT_TOWN
# 685 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 686 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 687 "data/maps/LittlerootTown/scripts.pory"
	return
# 688 "data/maps/LittlerootTown/scripts.pory"

# 689 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHomeFemale3::
# 690 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomReturnHomeFemale3
# 691 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 692 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 693 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 694 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomExitThroughDoor
# 695 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 696 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat LOCALID_MOM, MAP_LITTLEROOT_TOWN
# 697 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 698 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 699 "data/maps/LittlerootTown/scripts.pory"
	return
# 700 "data/maps/LittlerootTown/scripts.pory"

# 701 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHomeFemale4::
# 702 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomReturnHomeFemale4
# 703 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 704 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 705 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 706 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomExitThroughDoor
# 707 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 708 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat LOCALID_MOM, MAP_LITTLEROOT_TOWN
# 709 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 710 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 711 "data/maps/LittlerootTown/scripts.pory"
	return
# 712 "data/maps/LittlerootTown/scripts.pory"

# 713 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHomeFemale5::
# 714 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomReturnHomeFemale5
# 715 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 716 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 717 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 718 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomExitThroughDoor
# 719 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 720 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat LOCALID_MOM, MAP_LITTLEROOT_TOWN
# 721 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 722 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 723 "data/maps/LittlerootTown/scripts.pory"
	return
# 724 "data/maps/LittlerootTown/scripts.pory"

# 725 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayer0:
# 726 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 727 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 728 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 729 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 730 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 731 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 732 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 733 "data/maps/LittlerootTown/scripts.pory"

# 734 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayer1:
# 735 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 736 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 737 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 738 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 739 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 740 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 741 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 742 "data/maps/LittlerootTown/scripts.pory"

# 743 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerMale2:
# 744 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 745 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 746 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 747 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 748 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 749 "data/maps/LittlerootTown/scripts.pory"

# 750 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerMale3:
# 751 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 752 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 753 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 754 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 755 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 756 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 757 "data/maps/LittlerootTown/scripts.pory"

# 758 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerMale4:
# 759 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 760 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 761 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 762 "data/maps/LittlerootTown/scripts.pory"

# 763 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerMale5:
# 764 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 765 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 766 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 767 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 768 "data/maps/LittlerootTown/scripts.pory"

# 769 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerFemale2:
# 770 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 771 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 772 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 773 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 774 "data/maps/LittlerootTown/scripts.pory"

# 775 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerFemale3:
# 776 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 777 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 778 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 779 "data/maps/LittlerootTown/scripts.pory"

# 780 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerFemale4:
# 781 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 782 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 783 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 784 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 785 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 786 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 787 "data/maps/LittlerootTown/scripts.pory"

# 788 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerFemale5:
# 789 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 790 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 791 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 792 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 793 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 794 "data/maps/LittlerootTown/scripts.pory"

# 795 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHome0:
# 796 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 797 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 798 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 799 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 800 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 801 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 802 "data/maps/LittlerootTown/scripts.pory"

# 803 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHome1:
# 804 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 805 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 806 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 807 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 808 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 809 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 810 "data/maps/LittlerootTown/scripts.pory"

# 811 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeMale2:
# 812 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 813 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 814 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 815 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 816 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
# 817 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 818 "data/maps/LittlerootTown/scripts.pory"

# 819 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeMale3:
# 820 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 821 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 822 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 823 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 824 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 825 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
# 826 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 827 "data/maps/LittlerootTown/scripts.pory"

# 828 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeMale4:
# 829 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 830 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 831 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
# 832 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 833 "data/maps/LittlerootTown/scripts.pory"

# 834 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeMale5:
# 835 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 836 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 837 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 838 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
# 839 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 840 "data/maps/LittlerootTown/scripts.pory"

# 841 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeFemale2:
# 842 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 843 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 844 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 845 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
# 846 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 847 "data/maps/LittlerootTown/scripts.pory"

# 848 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeFemale3:
# 849 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 850 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 851 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
# 852 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 853 "data/maps/LittlerootTown/scripts.pory"

# 854 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeFemale4:
# 855 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 856 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 857 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 858 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 859 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 860 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
# 861 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 862 "data/maps/LittlerootTown/scripts.pory"

# 863 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeFemale5:
# 864 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 865 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 866 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 867 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 868 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
# 869 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 870 "data/maps/LittlerootTown/scripts.pory"

# 871 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomExitThroughDoor:
# 872 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 873 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 874 "data/maps/LittlerootTown/scripts.pory"

# 875 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_Mom::
# 876 "data/maps/LittlerootTown/scripts.pory"
	lock
# 877 "data/maps/LittlerootTown/scripts.pory"
	faceplayer
# 878 "data/maps/LittlerootTown/scripts.pory"
	checkplayergender
# 879 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, MALE, LittlerootTown_EventScript_SetHomeDoorCoordsMale
# 880 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_EventScript_SetHomeDoorCoordsFemale
# 881 "data/maps/LittlerootTown/scripts.pory"
	call LittlerootTown_EventScript_GiveRunningShoes
# 882 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, Common_Movement_WalkInPlaceFasterUp
# 883 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 884 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 885 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 886 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomExitThroughDoor
# 887 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 888 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat LOCALID_MOM, MAP_LITTLEROOT_TOWN
# 889 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 890 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 891 "data/maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_SetReceivedRunningShoes
# 892 "data/maps/LittlerootTown/scripts.pory"
	end
# 893 "data/maps/LittlerootTown/scripts.pory"

# 894 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetReceivedRunningShoes::
# 895 "data/maps/LittlerootTown/scripts.pory"
	removeobject LOCALID_MOM
# 896 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_SYS_B_DASH
# 897 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_TOWN_STATE, 4
# 898 "data/maps/LittlerootTown/scripts.pory"
	release
# 899 "data/maps/LittlerootTown/scripts.pory"
	end
# 900 "data/maps/LittlerootTown/scripts.pory"

# 901 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_GiveRunningShoes::
# 902 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_WearTheseRunningShoes, MSGBOX_DEFAULT
# 903 "data/maps/LittlerootTown/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 904 "data/maps/LittlerootTown/scripts.pory"
	message LittlerootTown_Text_SwitchShoesWithRunningShoes
# 905 "data/maps/LittlerootTown/scripts.pory"
	waitfanfare
# 906 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_RECEIVED_RUNNING_SHOES
# 907 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_ExplainRunningShoes, MSGBOX_DEFAULT
# 908 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_ComeHomeIfAnythingHappens, MSGBOX_DEFAULT
# 909 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 910 "data/maps/LittlerootTown/scripts.pory"
	delay 30
# 911 "data/maps/LittlerootTown/scripts.pory"
	return
# 912 "data/maps/LittlerootTown/scripts.pory"

# 913 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_OurNewHomeLetsGoInside:
# 914 "data/maps/LittlerootTown/scripts.pory"
	.string "MOM: {PLAYER}, we're here, honey!\p"
# 915 "data/maps/LittlerootTown/scripts.pory"
	.string "It must be tiring riding with our things\n"
# 916 "data/maps/LittlerootTown/scripts.pory"
	.string "in the moving truck.\p"
# 917 "data/maps/LittlerootTown/scripts.pory"
	.string "Well, this is LITTLEROOT TOWN.\p"
# 918 "data/maps/LittlerootTown/scripts.pory"
	.string "How do you like it?\n"
# 919 "data/maps/LittlerootTown/scripts.pory"
	.string "This is our new home!\p"
# 920 "data/maps/LittlerootTown/scripts.pory"
	.string "It has a quaint feel, but it seems to be\n"
# 921 "data/maps/LittlerootTown/scripts.pory"
	.string "an easy place to live, don't you think?\p"
# 922 "data/maps/LittlerootTown/scripts.pory"
	.string "And, you get your own room, {PLAYER}!\n"
# 923 "data/maps/LittlerootTown/scripts.pory"
	.string "Let's go inside.$"
# 924 "data/maps/LittlerootTown/scripts.pory"

# 925 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_WaitPlayer:
# 926 "data/maps/LittlerootTown/scripts.pory"
	.string "MOM: Wait, {PLAYER}!$"
# 927 "data/maps/LittlerootTown/scripts.pory"

# 928 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_WearTheseRunningShoes:
# 929 "data/maps/LittlerootTown/scripts.pory"
	.string "MOM: {PLAYER}! {PLAYER}! Did you\n"
# 930 "data/maps/LittlerootTown/scripts.pory"
	.string "introduce yourself to PROF. BIRCH?\p"
# 931 "data/maps/LittlerootTown/scripts.pory"
	.string "Oh! What an adorable POKéMON!\n"
# 932 "data/maps/LittlerootTown/scripts.pory"
	.string "You got it from PROF. BIRCH. How nice!\p"
# 933 "data/maps/LittlerootTown/scripts.pory"
	.string "You're your father's child, all right.\n"
# 934 "data/maps/LittlerootTown/scripts.pory"
	.string "You look good together with POKéMON!\p"
# 935 "data/maps/LittlerootTown/scripts.pory"
	.string "Here, honey! If you're going out on an\n"
# 936 "data/maps/LittlerootTown/scripts.pory"
	.string "adventure, wear these RUNNING SHOES.\p"
# 937 "data/maps/LittlerootTown/scripts.pory"
	.string "They'll put a zip in your step!$"
# 938 "data/maps/LittlerootTown/scripts.pory"

# 939 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_SwitchShoesWithRunningShoes:
# 940 "data/maps/LittlerootTown/scripts.pory"
	.string "{PLAYER} switched shoes with the\n"
# 941 "data/maps/LittlerootTown/scripts.pory"
	.string "RUNNING SHOES.$"
# 942 "data/maps/LittlerootTown/scripts.pory"

# 943 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_ExplainRunningShoes:
# 944 "data/maps/LittlerootTown/scripts.pory"
	.string "MOM: {PLAYER}, those shoes came with\n"
# 945 "data/maps/LittlerootTown/scripts.pory"
	.string "instructions.\p"
# 946 "data/maps/LittlerootTown/scripts.pory"
	.string "“Press the B Button while wearing these\n"
# 947 "data/maps/LittlerootTown/scripts.pory"
	.string "RUNNING SHOES to run extra-fast!\p"
# 948 "data/maps/LittlerootTown/scripts.pory"
	.string "“Slip on these RUNNING SHOES and race\n"
# 949 "data/maps/LittlerootTown/scripts.pory"
	.string "in the great outdoors!”$"
# 950 "data/maps/LittlerootTown/scripts.pory"

# 951 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_ComeHomeIfAnythingHappens:
# 952 "data/maps/LittlerootTown/scripts.pory"
	.string "… … … … … … … …\n"
# 953 "data/maps/LittlerootTown/scripts.pory"
	.string "… … … … … … … …\p"
# 954 "data/maps/LittlerootTown/scripts.pory"
	.string "To think that you have your very own\n"
# 955 "data/maps/LittlerootTown/scripts.pory"
	.string "POKéMON now…\l"
# 956 "data/maps/LittlerootTown/scripts.pory"
	.string "Your father will be overjoyed.\p"
# 957 "data/maps/LittlerootTown/scripts.pory"
	.string "…But please be careful.\n"
# 958 "data/maps/LittlerootTown/scripts.pory"
	.string "If anything happens, you can come home.\p"
# 959 "data/maps/LittlerootTown/scripts.pory"
	.string "Go on, go get them, honey!$"
# 960 "data/maps/LittlerootTown/scripts.pory"

# 961 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_CanUsePCToStoreItems:
# 962 "data/maps/LittlerootTown/scripts.pory"
	.string "If you use a PC, you can store items\n"
# 963 "data/maps/LittlerootTown/scripts.pory"
	.string "and POKéMON.\p"
# 964 "data/maps/LittlerootTown/scripts.pory"
	.string "The power of science is staggering!$"
# 965 "data/maps/LittlerootTown/scripts.pory"

# 966 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_BirchSpendsDaysInLab:
# 967 "data/maps/LittlerootTown/scripts.pory"
	.string "PROF. BIRCH spends days in his LAB\n"
# 968 "data/maps/LittlerootTown/scripts.pory"
	.string "studying, then he'll suddenly go out in\l"
# 969 "data/maps/LittlerootTown/scripts.pory"
	.string "the wild to do more research…\p"
# 970 "data/maps/LittlerootTown/scripts.pory"
	.string "When does PROF. BIRCH spend time\n"
# 971 "data/maps/LittlerootTown/scripts.pory"
	.string "at home?$"
# 972 "data/maps/LittlerootTown/scripts.pory"

# 973 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_IfYouGoInGrassPokemonWillJumpOut:
# 974 "data/maps/LittlerootTown/scripts.pory"
	.string "Um, um, um!\p"
# 975 "data/maps/LittlerootTown/scripts.pory"
	.string "If you go outside and go in the grass,\n"
# 976 "data/maps/LittlerootTown/scripts.pory"
	.string "wild POKéMON will jump out!$"
# 977 "data/maps/LittlerootTown/scripts.pory"

# 978 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_DangerousIfYouDontHavePokemon:
# 979 "data/maps/LittlerootTown/scripts.pory"
	.string "It's dangerous if you don't have\n"
# 980 "data/maps/LittlerootTown/scripts.pory"
	.string "your own POKéMON.$"
# 981 "data/maps/LittlerootTown/scripts.pory"

# 982 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_CanYouGoSeeWhatsHappening:
# 983 "data/maps/LittlerootTown/scripts.pory"
	.string "Um, hi!\p"
# 984 "data/maps/LittlerootTown/scripts.pory"
	.string "There are scary POKéMON outside!\n"
# 985 "data/maps/LittlerootTown/scripts.pory"
	.string "I can hear their cries!\p"
# 986 "data/maps/LittlerootTown/scripts.pory"
	.string "I want to go see what's going on,\n"
# 987 "data/maps/LittlerootTown/scripts.pory"
	.string "but I don't have any POKéMON…\p"
# 988 "data/maps/LittlerootTown/scripts.pory"
	.string "Can you go see what's happening\n"
# 989 "data/maps/LittlerootTown/scripts.pory"
	.string "for me?$"
# 990 "data/maps/LittlerootTown/scripts.pory"

# 991 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_YouSavedBirch:
# 992 "data/maps/LittlerootTown/scripts.pory"
	.string "You saved PROF. BIRCH!\n"
# 993 "data/maps/LittlerootTown/scripts.pory"
	.string "I'm so glad!$"
# 994 "data/maps/LittlerootTown/scripts.pory"

# 995 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_GoodLuckCatchingPokemon:
# 996 "data/maps/LittlerootTown/scripts.pory"
	.string "Are you going to catch POKéMON?\n"
# 997 "data/maps/LittlerootTown/scripts.pory"
	.string "Good luck!$"
# 998 "data/maps/LittlerootTown/scripts.pory"

# 999 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_TownSign:
# 1000 "data/maps/LittlerootTown/scripts.pory"
	.string "LITTLEROOT TOWN\n"
# 1001 "data/maps/LittlerootTown/scripts.pory"
	.string "“A town that can't be shaded any hue.”$"
# 1002 "data/maps/LittlerootTown/scripts.pory"

# 1003 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_ProfBirchsLab:
# 1004 "data/maps/LittlerootTown/scripts.pory"
	.string "PROF. BIRCH'S POKéMON LAB$"
# 1005 "data/maps/LittlerootTown/scripts.pory"

# 1006 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_PlayersHouse:
# 1007 "data/maps/LittlerootTown/scripts.pory"
	.string "{PLAYER}'s HOUSE$"
# 1008 "data/maps/LittlerootTown/scripts.pory"

# 1009 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_ProfBirchsHouse:
# 1010 "data/maps/LittlerootTown/scripts.pory"
	.string "PROF. BIRCH'S HOUSE$"
# 1011 "data/maps/LittlerootTown/scripts.pory"

# 1012 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_BirchSomethingToShowYouAtLab:
# 1013 "data/maps/LittlerootTown/scripts.pory"
	.string "PROF. BIRCH: Well, well, {PLAYER}{KUN}!\n"
# 1014 "data/maps/LittlerootTown/scripts.pory"
	.string "That was good work out there!\p"
# 1015 "data/maps/LittlerootTown/scripts.pory"
	.string "I knew there was something special\n"
# 1016 "data/maps/LittlerootTown/scripts.pory"
	.string "about you when I first saw you,\l"
# 1017 "data/maps/LittlerootTown/scripts.pory"
	.string "but I never expected this.\p"
# 1018 "data/maps/LittlerootTown/scripts.pory"
	.string "Oh, yes. Do you still have the POKéDEX\n"
# 1019 "data/maps/LittlerootTown/scripts.pory"
	.string "I gave you?\p"
# 1020 "data/maps/LittlerootTown/scripts.pory"
	.string "I have something to show you.\n"
# 1021 "data/maps/LittlerootTown/scripts.pory"
	.string "Let's go to my LAB.$"

LittlerootTown_EventScript_NewLittlerootTownSign::
# 1025 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 1026 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_EventScript_NewLittlerootTownSign_Text_0
# 1027 "data/maps/LittlerootTown/scripts.pory"
	special NameRival
# 1028 "data/maps/LittlerootTown/scripts.pory"
	waitstate
	return


LittlerootTown_EventScript_GymChampionCheck::
# 1032 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 1033 "data/maps/LittlerootTown/scripts.pory"
	faceplayer
# 1035 "data/maps/LittlerootTown/scripts.pory"
	goto_if_unset FLAG_UNUSED_0x020, LittlerootTown_EventScript_GymChampionCheck_1
# 1037 "data/maps/LittlerootTown/scripts.pory"
	goto_if_set FLAG_UNUSED_0x020, LittlerootTown_EventScript_GymChampionCheck_2
	return

LittlerootTown_EventScript_GymChampionCheck_1:
# 1036 "data/maps/LittlerootTown/scripts.pory"
	call GymVerifyIntro
	return

LittlerootTown_EventScript_GymChampionCheck_2:
# 1038 "data/maps/LittlerootTown/scripts.pory"
	goto Verification
	return


ChampionVerified::
# 1044 "data/maps/LittlerootTown/scripts.pory"
	msgbox ChampionVerified_Text_0
# 1045 "data/maps/LittlerootTown/scripts.pory"
	msgbox ChampionVerified_Text_1
# 1046 "data/maps/LittlerootTown/scripts.pory"
	msgbox ChampionVerified_Text_2
# 1047 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 1048 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 1049 "data/maps/LittlerootTown/scripts.pory"
	applymovement 9, MagmaGruntLeave
# 1050 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 1051 "data/maps/LittlerootTown/scripts.pory"
	removeobject 9
# 1052 "data/maps/LittlerootTown/scripts.pory"
	msgbox ChampionVerified_Text_3
# 1053 "data/maps/LittlerootTown/scripts.pory"
	releaseall
	end


# 1057 "data/maps/LittlerootTown/scripts.pory"
MagmaGruntLeave:
# 1058 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 1058 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 1058 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 1059 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 1059 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 1059 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 1059 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 1059 "data/maps/LittlerootTown/scripts.pory"
	walk_up
	step_end

ChampionNotVerified::
# 1063 "data/maps/LittlerootTown/scripts.pory"
	msgbox ChampionNotVerified_Text_0
# 1064 "data/maps/LittlerootTown/scripts.pory"
	msgbox ChampionNotVerified_Text_1
# 1065 "data/maps/LittlerootTown/scripts.pory"
	msgbox ChampionNotVerified_Text_2
# 1066 "data/maps/LittlerootTown/scripts.pory"
	closemessage
	end


GymVerifyIntro::
# 1071 "data/maps/LittlerootTown/scripts.pory"
	msgbox GymVerifyIntro_Text_0
# 1072 "data/maps/LittlerootTown/scripts.pory"
	msgbox GymVerifyIntro_Text_1
# 1073 "data/maps/LittlerootTown/scripts.pory"
	msgbox GymVerifyIntro_Text_2
# 1074 "data/maps/LittlerootTown/scripts.pory"
	msgbox GymVerifyIntro_Text_3
# 1075 "data/maps/LittlerootTown/scripts.pory"
	msgbox GymVerifyIntro_Text_4
# 1076 "data/maps/LittlerootTown/scripts.pory"
	msgbox GymVerifyIntro_Text_5
# 1077 "data/maps/LittlerootTown/scripts.pory"
	msgbox GymVerifyIntro_Text_6
# 1078 "data/maps/LittlerootTown/scripts.pory"
	msgbox GymVerifyIntro_Text_7
# 1079 "data/maps/LittlerootTown/scripts.pory"
	msgbox GymVerifyIntro_Text_8
# 1080 "data/maps/LittlerootTown/scripts.pory"
	msgbox GymVerifyIntro_Text_9
# 1081 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_UNUSED_0x020
# 1082 "data/maps/LittlerootTown/scripts.pory"
	goto Verification
# 1083 "data/maps/LittlerootTown/scripts.pory"
	closemessage
	end


Verification::
# 1089 "data/maps/LittlerootTown/scripts.pory"
	msgbox Verification_Text_0
# 1090 "data/maps/LittlerootTown/scripts.pory"
	goto_if_set FLAG_IS_CHAMPION, Verification_1
# 1092 "data/maps/LittlerootTown/scripts.pory"
	goto_if_unset FLAG_IS_CHAMPION, Verification_2
	return

Verification_1:
# 1091 "data/maps/LittlerootTown/scripts.pory"
	goto ChampionVerified
	return

Verification_2:
# 1093 "data/maps/LittlerootTown/scripts.pory"
	goto ChampionNotVerified
	return


StarterMenu::
# 1097 "data/maps/LittlerootTown/scripts.pory"
	lock
# 1098 "data/maps/LittlerootTown/scripts.pory"
	faceplayer
# 1099 "data/maps/LittlerootTown/scripts.pory"
	msgbox StarterMenu_Text_0
# 1100 "data/maps/LittlerootTown/scripts.pory"
	goto_if_unset FLAG_UNUSED_0x493, StarterMenu_1
	return

StarterMenu_1:
# 1101 "data/maps/LittlerootTown/scripts.pory"
	call Starters
# 1102 "data/maps/LittlerootTown/scripts.pory"
	waitmessage
# 1103 "data/maps/LittlerootTown/scripts.pory"
	release
	end


Starters::
# 1109 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Starters_Text_0, SPECIES_BULBASAUR
# 1110 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Starters_Text_1, SPECIES_CHARMANDER
# 1111 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Starters_Text_2, SPECIES_SQUIRTLE
# 1112 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Starters_Text_3, SPECIES_CHIKORITA
# 1113 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Starters_Text_4, SPECIES_CYNDAQUIL
# 1114 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Starters_Text_5, SPECIES_TOTODILE
# 1115 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Starters_Text_6, SPECIES_TREECKO
# 1116 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Starters_Text_7, SPECIES_TORCHIC
# 1117 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Starters_Text_8, SPECIES_MUDKIP
# 1118 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Starters_Text_9, SPECIES_TURTWIG
# 1119 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Starters_Text_10, SPECIES_CHIMCHAR
# 1120 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Starters_Text_11, SPECIES_PIPLUP
# 1121 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Starters_Text_12, SPECIES_SNIVY
# 1122 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Starters_Text_13, SPECIES_TEPIG
# 1123 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Starters_Text_14, SPECIES_OSHAWOTT
# 1124 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Starters_Text_15, SPECIES_CHESPIN
# 1125 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Starters_Text_16, SPECIES_FENNEKIN
# 1126 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Starters_Text_17, SPECIES_FROAKIE
# 1127 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Starters_Text_18, SPECIES_ROWLET
# 1128 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Starters_Text_19, SPECIES_LITTEN
# 1129 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Starters_Text_20, SPECIES_POPPLIO
# 1130 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Starters_Text_21, SPECIES_GROOKEY
# 1131 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Starters_Text_22, SPECIES_SCORBUNNY
# 1132 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Starters_Text_23, SPECIES_SOBBLE
# 1133 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Starters_Text_24, SPECIES_SPRIGATITO
# 1134 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Starters_Text_25, SPECIES_FUECOCO
# 1135 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Starters_Text_26, SPECIES_QUAXLY
# 1136 "data/maps/LittlerootTown/scripts.pory"
	dynmultistack 0, 0, TRUE, 6, FALSE, VAR_0x800A, DYN_MULTICHOICE_CB_NONE
# 1137 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, SPECIES_BULBASAUR
	goto_if_eq Starters_2
Starters_1:
# 1142 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq Starters_5
# 1145 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Starters_6
Starters_4:
# 1147 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq Starters_10
Starters_9:
# 1155 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, SPECIES_CHARMANDER
	goto_if_eq Starters_13
Starters_12:
# 1160 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq Starters_16
# 1163 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Starters_17
Starters_15:
# 1165 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq Starters_21
Starters_20:
# 1173 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, SPECIES_SQUIRTLE
	goto_if_eq Starters_24
Starters_23:
# 1178 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq Starters_27
# 1181 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Starters_28
Starters_26:
# 1183 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq Starters_32
Starters_31:
# 1191 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, SPECIES_CHIKORITA
	goto_if_eq Starters_35
Starters_34:
# 1195 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq Starters_38
# 1198 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Starters_39
Starters_37:
# 1200 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq Starters_43
Starters_42:
# 1208 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, SPECIES_CYNDAQUIL
	goto_if_eq Starters_46
Starters_45:
# 1212 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq Starters_49
# 1215 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Starters_50
Starters_48:
# 1217 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq Starters_54
Starters_53:
# 1225 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, SPECIES_TOTODILE
	goto_if_eq Starters_57
Starters_56:
# 1230 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq Starters_60
# 1233 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Starters_61
Starters_59:
# 1235 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq Starters_65
Starters_64:
# 1243 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, SPECIES_TREECKO
	goto_if_eq Starters_68
Starters_67:
# 1247 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq Starters_71
# 1250 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Starters_72
Starters_70:
# 1252 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq Starters_76
Starters_75:
# 1260 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, SPECIES_TORCHIC
	goto_if_eq Starters_79
Starters_78:
# 1265 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq Starters_82
# 1268 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Starters_83
Starters_81:
# 1270 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq Starters_87
Starters_86:
# 1278 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, SPECIES_MUDKIP
	goto_if_eq Starters_90
Starters_89:
# 1283 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq Starters_93
# 1286 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Starters_94
Starters_92:
# 1288 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq Starters_98
Starters_97:
# 1296 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, SPECIES_TURTWIG
	goto_if_eq Starters_101
Starters_100:
# 1301 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq Starters_104
# 1304 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Starters_105
Starters_103:
# 1306 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq Starters_109
Starters_108:
# 1314 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, SPECIES_CHIMCHAR
	goto_if_eq Starters_112
Starters_111:
# 1320 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq Starters_115
# 1323 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Starters_116
Starters_114:
# 1325 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq Starters_120
Starters_119:
# 1333 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, SPECIES_PIPLUP
	goto_if_eq Starters_123
Starters_122:
# 1339 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq Starters_126
# 1342 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Starters_127
Starters_125:
# 1344 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq Starters_131
Starters_130:
# 1352 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, SPECIES_SNIVY
	goto_if_eq Starters_134
Starters_133:
# 1357 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq Starters_137
# 1360 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Starters_138
Starters_136:
# 1362 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq Starters_142
Starters_141:
# 1369 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, SPECIES_TEPIG
	goto_if_eq Starters_145
Starters_144:
# 1374 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq Starters_148
# 1377 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Starters_149
Starters_147:
# 1379 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq Starters_153
Starters_152:
# 1387 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, SPECIES_OSHAWOTT
	goto_if_eq Starters_156
Starters_155:
# 1393 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq Starters_159
# 1396 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Starters_160
Starters_158:
# 1398 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq Starters_164
Starters_163:
# 1406 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, SPECIES_CHESPIN
	goto_if_eq Starters_167
Starters_166:
# 1411 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq Starters_170
# 1414 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Starters_171
Starters_169:
# 1416 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq Starters_175
Starters_174:
# 1424 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, SPECIES_FENNEKIN
	goto_if_eq Starters_178
Starters_177:
# 1429 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq Starters_181
# 1432 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Starters_182
Starters_180:
# 1434 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq Starters_186
Starters_185:
# 1442 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, SPECIES_FROAKIE
	goto_if_eq Starters_189
Starters_188:
# 1447 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq Starters_192
# 1450 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Starters_193
Starters_191:
# 1452 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq Starters_197
Starters_196:
# 1460 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, SPECIES_ROWLET
	goto_if_eq Starters_200
Starters_199:
# 1465 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq Starters_203
# 1468 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Starters_204
Starters_202:
# 1470 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq Starters_208
Starters_207:
# 1478 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, SPECIES_LITTEN
	goto_if_eq Starters_211
Starters_210:
# 1483 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq Starters_214
# 1486 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Starters_215
Starters_213:
# 1488 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq Starters_219
Starters_218:
# 1496 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, SPECIES_POPPLIO
	goto_if_eq Starters_222
Starters_221:
# 1501 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq Starters_225
# 1504 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Starters_226
Starters_224:
# 1506 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq Starters_230
Starters_229:
# 1514 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, SPECIES_GROOKEY
	goto_if_eq Starters_233
Starters_232:
# 1519 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq Starters_236
# 1522 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Starters_237
Starters_235:
# 1524 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq Starters_241
Starters_240:
# 1532 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, SPECIES_SCORBUNNY
	goto_if_eq Starters_244
Starters_243:
# 1537 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq Starters_247
# 1540 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Starters_248
Starters_246:
# 1542 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq Starters_252
Starters_251:
# 1550 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, SPECIES_SOBBLE
	goto_if_eq Starters_255
Starters_254:
# 1555 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq Starters_258
# 1558 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Starters_259
Starters_257:
# 1560 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq Starters_263
Starters_262:
# 1568 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, SPECIES_SPRIGATITO
	goto_if_eq Starters_266
Starters_265:
# 1573 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq Starters_269
# 1576 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Starters_270
Starters_268:
# 1578 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq Starters_274
Starters_273:
# 1586 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, SPECIES_FUECOCO
	goto_if_eq Starters_277
Starters_276:
# 1591 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq Starters_280
# 1594 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Starters_281
Starters_279:
# 1596 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq Starters_285
Starters_284:
# 1604 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, SPECIES_QUAXLY
	goto_if_eq Starters_288
Starters_287:
# 1609 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq Starters_291
# 1612 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Starters_292
Starters_290:
# 1614 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq Starters_295
	return

Starters_2:
# 1138 "data/maps/LittlerootTown/scripts.pory"
	showmonpic SPECIES_BULBASAUR, 10, 3
# 1139 "data/maps/LittlerootTown/scripts.pory"
	playmoncry SPECIES_BULBASAUR, CRY_MODE_NORMAL
# 1140 "data/maps/LittlerootTown/scripts.pory"
	msgbox Starters_Text_27, MSGBOX_YESNO
# 1141 "data/maps/LittlerootTown/scripts.pory"
	waitmessage
	goto Starters_1

Starters_5:
# 1143 "data/maps/LittlerootTown/scripts.pory"
	hidemonpic
# 1144 "data/maps/LittlerootTown/scripts.pory"
	call StarterMenu
	goto Starters_4

Starters_6:
# 1146 "data/maps/LittlerootTown/scripts.pory"
	givemon SPECIES_BULBASAUR, 5, ITEM_NONE
	goto Starters_4

Starters_10:
# 1148 "data/maps/LittlerootTown/scripts.pory"
	playfanfare MUS_EVOLVED
# 1149 "data/maps/LittlerootTown/scripts.pory"
	msgbox Starters_Text_28
# 1150 "data/maps/LittlerootTown/scripts.pory"
	waitfanfare
# 1151 "data/maps/LittlerootTown/scripts.pory"
	waitmessage
# 1152 "data/maps/LittlerootTown/scripts.pory"
	removeobject 2
# 1153 "data/maps/LittlerootTown/scripts.pory"
	call NicknamePartyMon
	goto Starters_9

Starters_13:
# 1156 "data/maps/LittlerootTown/scripts.pory"
	playmoncry SPECIES_CHARMANDER, CRY_MODE_NORMAL
# 1157 "data/maps/LittlerootTown/scripts.pory"
	showmonpic SPECIES_CHARMANDER, 10, 3
# 1158 "data/maps/LittlerootTown/scripts.pory"
	msgbox Starters_Text_29, MSGBOX_YESNO
# 1159 "data/maps/LittlerootTown/scripts.pory"
	waitmessage
	goto Starters_12

Starters_16:
# 1161 "data/maps/LittlerootTown/scripts.pory"
	hidemonpic
# 1162 "data/maps/LittlerootTown/scripts.pory"
	call StarterMenu
	goto Starters_15

Starters_17:
# 1164 "data/maps/LittlerootTown/scripts.pory"
	givemon SPECIES_CHARMANDER, 5, ITEM_NONE
	goto Starters_15

Starters_21:
# 1166 "data/maps/LittlerootTown/scripts.pory"
	playfanfare MUS_EVOLVED
# 1167 "data/maps/LittlerootTown/scripts.pory"
	msgbox Starters_Text_30
# 1168 "data/maps/LittlerootTown/scripts.pory"
	waitfanfare
# 1169 "data/maps/LittlerootTown/scripts.pory"
	waitmessage
# 1170 "data/maps/LittlerootTown/scripts.pory"
	removeobject 2
# 1171 "data/maps/LittlerootTown/scripts.pory"
	call NicknamePartyMon
	goto Starters_20

Starters_24:
# 1174 "data/maps/LittlerootTown/scripts.pory"
	playmoncry SPECIES_SQUIRTLE, CRY_MODE_NORMAL
# 1175 "data/maps/LittlerootTown/scripts.pory"
	showmonpic SPECIES_SQUIRTLE, 10, 3
# 1176 "data/maps/LittlerootTown/scripts.pory"
	msgbox Starters_Text_31, MSGBOX_YESNO
# 1177 "data/maps/LittlerootTown/scripts.pory"
	waitmessage
	goto Starters_23

Starters_27:
# 1179 "data/maps/LittlerootTown/scripts.pory"
	hidemonpic
# 1180 "data/maps/LittlerootTown/scripts.pory"
	call StarterMenu
	goto Starters_26

Starters_28:
# 1182 "data/maps/LittlerootTown/scripts.pory"
	givemon SPECIES_SQUIRTLE, 5, ITEM_NONE
	goto Starters_26

Starters_32:
# 1184 "data/maps/LittlerootTown/scripts.pory"
	playfanfare MUS_EVOLVED
# 1185 "data/maps/LittlerootTown/scripts.pory"
	msgbox Starters_Text_32
# 1186 "data/maps/LittlerootTown/scripts.pory"
	waitfanfare
# 1187 "data/maps/LittlerootTown/scripts.pory"
	waitmessage
# 1188 "data/maps/LittlerootTown/scripts.pory"
	removeobject 2
# 1189 "data/maps/LittlerootTown/scripts.pory"
	call NicknamePartyMon
	goto Starters_31

Starters_35:
# 1192 "data/maps/LittlerootTown/scripts.pory"
	playmoncry SPECIES_CHIKORITA, CRY_MODE_NORMAL
# 1193 "data/maps/LittlerootTown/scripts.pory"
	showmonpic SPECIES_CHIKORITA, 10, 3
# 1194 "data/maps/LittlerootTown/scripts.pory"
	msgbox Starters_Text_33, MSGBOX_YESNO
	goto Starters_34

Starters_38:
# 1196 "data/maps/LittlerootTown/scripts.pory"
	hidemonpic
# 1197 "data/maps/LittlerootTown/scripts.pory"
	call StarterMenu
	goto Starters_37

Starters_39:
# 1199 "data/maps/LittlerootTown/scripts.pory"
	givemon SPECIES_CHIKORITA, 5, ITEM_NONE
	goto Starters_37

Starters_43:
# 1201 "data/maps/LittlerootTown/scripts.pory"
	playfanfare MUS_EVOLVED
# 1202 "data/maps/LittlerootTown/scripts.pory"
	msgbox Starters_Text_34
# 1203 "data/maps/LittlerootTown/scripts.pory"
	waitfanfare
# 1204 "data/maps/LittlerootTown/scripts.pory"
	waitmessage
# 1205 "data/maps/LittlerootTown/scripts.pory"
	removeobject 2
# 1206 "data/maps/LittlerootTown/scripts.pory"
	call NicknamePartyMon
	goto Starters_42

Starters_46:
# 1209 "data/maps/LittlerootTown/scripts.pory"
	playmoncry SPECIES_CYNDAQUIL, CRY_MODE_NORMAL
# 1210 "data/maps/LittlerootTown/scripts.pory"
	showmonpic SPECIES_CYNDAQUIL, 10, 3
# 1211 "data/maps/LittlerootTown/scripts.pory"
	msgbox Starters_Text_35, MSGBOX_YESNO
	goto Starters_45

Starters_49:
# 1213 "data/maps/LittlerootTown/scripts.pory"
	hidemonpic
# 1214 "data/maps/LittlerootTown/scripts.pory"
	call StarterMenu
	goto Starters_48

Starters_50:
# 1216 "data/maps/LittlerootTown/scripts.pory"
	givemon SPECIES_CYNDAQUIL, 5, ITEM_NONE
	goto Starters_48

Starters_54:
# 1218 "data/maps/LittlerootTown/scripts.pory"
	playfanfare MUS_EVOLVED
# 1219 "data/maps/LittlerootTown/scripts.pory"
	msgbox Starters_Text_36
# 1220 "data/maps/LittlerootTown/scripts.pory"
	waitfanfare
# 1221 "data/maps/LittlerootTown/scripts.pory"
	waitmessage
# 1222 "data/maps/LittlerootTown/scripts.pory"
	removeobject 2
# 1223 "data/maps/LittlerootTown/scripts.pory"
	call NicknamePartyMon
	goto Starters_53

Starters_57:
# 1226 "data/maps/LittlerootTown/scripts.pory"
	playmoncry SPECIES_TOTODILE, CRY_MODE_NORMAL
# 1227 "data/maps/LittlerootTown/scripts.pory"
	showmonpic SPECIES_TOTODILE, 10, 3
# 1228 "data/maps/LittlerootTown/scripts.pory"
	msgbox Starters_Text_37, MSGBOX_YESNO
# 1229 "data/maps/LittlerootTown/scripts.pory"
	waitmessage
	goto Starters_56

Starters_60:
# 1231 "data/maps/LittlerootTown/scripts.pory"
	hidemonpic
# 1232 "data/maps/LittlerootTown/scripts.pory"
	call StarterMenu
	goto Starters_59

Starters_61:
# 1234 "data/maps/LittlerootTown/scripts.pory"
	givemon SPECIES_TOTODILE, 5, ITEM_NONE
	goto Starters_59

Starters_65:
# 1236 "data/maps/LittlerootTown/scripts.pory"
	playfanfare MUS_EVOLVED
# 1237 "data/maps/LittlerootTown/scripts.pory"
	msgbox Starters_Text_38
# 1238 "data/maps/LittlerootTown/scripts.pory"
	waitfanfare
# 1239 "data/maps/LittlerootTown/scripts.pory"
	waitmessage
# 1240 "data/maps/LittlerootTown/scripts.pory"
	removeobject 2
# 1241 "data/maps/LittlerootTown/scripts.pory"
	call NicknamePartyMon
	goto Starters_64

Starters_68:
# 1244 "data/maps/LittlerootTown/scripts.pory"
	showmonpic SPECIES_TREECKO, 10, 3
# 1245 "data/maps/LittlerootTown/scripts.pory"
	playmoncry SPECIES_TREECKO, CRY_MODE_NORMAL
# 1246 "data/maps/LittlerootTown/scripts.pory"
	msgbox Starters_Text_39, MSGBOX_YESNO
	goto Starters_67

Starters_71:
# 1248 "data/maps/LittlerootTown/scripts.pory"
	hidemonpic
# 1249 "data/maps/LittlerootTown/scripts.pory"
	call StarterMenu
	goto Starters_70

Starters_72:
# 1251 "data/maps/LittlerootTown/scripts.pory"
	givemon SPECIES_TREECKO, 5, ITEM_NONE
	goto Starters_70

Starters_76:
# 1253 "data/maps/LittlerootTown/scripts.pory"
	playfanfare MUS_EVOLVED
# 1254 "data/maps/LittlerootTown/scripts.pory"
	msgbox Starters_Text_40
# 1255 "data/maps/LittlerootTown/scripts.pory"
	waitfanfare
# 1256 "data/maps/LittlerootTown/scripts.pory"
	waitmessage
# 1257 "data/maps/LittlerootTown/scripts.pory"
	removeobject 2
# 1258 "data/maps/LittlerootTown/scripts.pory"
	call NicknamePartyMon
	goto Starters_75

Starters_79:
# 1261 "data/maps/LittlerootTown/scripts.pory"
	playmoncry SPECIES_TORCHIC, CRY_MODE_NORMAL
# 1262 "data/maps/LittlerootTown/scripts.pory"
	showmonpic SPECIES_TORCHIC, 10, 3
# 1263 "data/maps/LittlerootTown/scripts.pory"
	msgbox Starters_Text_41, MSGBOX_YESNO
# 1264 "data/maps/LittlerootTown/scripts.pory"
	waitmessage
	goto Starters_78

Starters_82:
# 1266 "data/maps/LittlerootTown/scripts.pory"
	hidemonpic
# 1267 "data/maps/LittlerootTown/scripts.pory"
	call StarterMenu
	goto Starters_81

Starters_83:
# 1269 "data/maps/LittlerootTown/scripts.pory"
	givemon SPECIES_TORCHIC, 5, ITEM_NONE
	goto Starters_81

Starters_87:
# 1271 "data/maps/LittlerootTown/scripts.pory"
	playfanfare MUS_EVOLVED
# 1272 "data/maps/LittlerootTown/scripts.pory"
	msgbox Starters_Text_42
# 1273 "data/maps/LittlerootTown/scripts.pory"
	waitfanfare
# 1274 "data/maps/LittlerootTown/scripts.pory"
	waitmessage
# 1275 "data/maps/LittlerootTown/scripts.pory"
	removeobject 2
# 1276 "data/maps/LittlerootTown/scripts.pory"
	call NicknamePartyMon
	goto Starters_86

Starters_90:
# 1279 "data/maps/LittlerootTown/scripts.pory"
	playmoncry SPECIES_MUDKIP, CRY_MODE_NORMAL
# 1280 "data/maps/LittlerootTown/scripts.pory"
	showmonpic SPECIES_MUDKIP, 10, 3
# 1281 "data/maps/LittlerootTown/scripts.pory"
	msgbox Starters_Text_43, MSGBOX_YESNO
# 1282 "data/maps/LittlerootTown/scripts.pory"
	waitmessage
	goto Starters_89

Starters_93:
# 1284 "data/maps/LittlerootTown/scripts.pory"
	hidemonpic
# 1285 "data/maps/LittlerootTown/scripts.pory"
	call StarterMenu
	goto Starters_92

Starters_94:
# 1287 "data/maps/LittlerootTown/scripts.pory"
	givemon SPECIES_MUDKIP, 5, ITEM_NONE
	goto Starters_92

Starters_98:
# 1289 "data/maps/LittlerootTown/scripts.pory"
	playfanfare MUS_EVOLVED
# 1290 "data/maps/LittlerootTown/scripts.pory"
	msgbox Starters_Text_44
# 1291 "data/maps/LittlerootTown/scripts.pory"
	waitfanfare
# 1292 "data/maps/LittlerootTown/scripts.pory"
	waitmessage
# 1293 "data/maps/LittlerootTown/scripts.pory"
	removeobject 2
# 1294 "data/maps/LittlerootTown/scripts.pory"
	call NicknamePartyMon
	goto Starters_97

Starters_101:
# 1297 "data/maps/LittlerootTown/scripts.pory"
	playmoncry SPECIES_TURTWIG, CRY_MODE_NORMAL
# 1298 "data/maps/LittlerootTown/scripts.pory"
	showmonpic SPECIES_TURTWIG, 10, 3
# 1299 "data/maps/LittlerootTown/scripts.pory"
	msgbox Starters_Text_45, MSGBOX_YESNO
# 1300 "data/maps/LittlerootTown/scripts.pory"
	waitmessage
	goto Starters_100

Starters_104:
# 1302 "data/maps/LittlerootTown/scripts.pory"
	hidemonpic
# 1303 "data/maps/LittlerootTown/scripts.pory"
	call StarterMenu
	goto Starters_103

Starters_105:
# 1305 "data/maps/LittlerootTown/scripts.pory"
	givemon SPECIES_TURTWIG, 5, ITEM_NONE
	goto Starters_103

Starters_109:
# 1307 "data/maps/LittlerootTown/scripts.pory"
	playfanfare MUS_EVOLVED
# 1308 "data/maps/LittlerootTown/scripts.pory"
	msgbox Starters_Text_46
# 1309 "data/maps/LittlerootTown/scripts.pory"
	waitfanfare
# 1310 "data/maps/LittlerootTown/scripts.pory"
	waitmessage
# 1311 "data/maps/LittlerootTown/scripts.pory"
	removeobject 2
# 1312 "data/maps/LittlerootTown/scripts.pory"
	call NicknamePartyMon
	goto Starters_108

Starters_112:
# 1315 "data/maps/LittlerootTown/scripts.pory"
	playmoncry SPECIES_CHIMCHAR, CRY_MODE_NORMAL
# 1316 "data/maps/LittlerootTown/scripts.pory"
	showmonpic SPECIES_CHIMCHAR, 10, 3
# 1317 "data/maps/LittlerootTown/scripts.pory"
	msgbox Starters_Text_47, MSGBOX_YESNO
# 1318 "data/maps/LittlerootTown/scripts.pory"
	waitfanfare
# 1319 "data/maps/LittlerootTown/scripts.pory"
	waitmessage
	goto Starters_111

Starters_115:
# 1321 "data/maps/LittlerootTown/scripts.pory"
	hidemonpic
# 1322 "data/maps/LittlerootTown/scripts.pory"
	call StarterMenu
	goto Starters_114

Starters_116:
# 1324 "data/maps/LittlerootTown/scripts.pory"
	givemon SPECIES_CHIMCHAR, 5, ITEM_NONE
	goto Starters_114

Starters_120:
# 1326 "data/maps/LittlerootTown/scripts.pory"
	playfanfare MUS_EVOLVED
# 1327 "data/maps/LittlerootTown/scripts.pory"
	msgbox Starters_Text_48
# 1328 "data/maps/LittlerootTown/scripts.pory"
	waitfanfare
# 1329 "data/maps/LittlerootTown/scripts.pory"
	waitmessage
# 1330 "data/maps/LittlerootTown/scripts.pory"
	removeobject 2
# 1331 "data/maps/LittlerootTown/scripts.pory"
	call NicknamePartyMon
	goto Starters_119

Starters_123:
# 1334 "data/maps/LittlerootTown/scripts.pory"
	playmoncry SPECIES_PIPLUP, CRY_MODE_NORMAL
# 1335 "data/maps/LittlerootTown/scripts.pory"
	showmonpic SPECIES_PIPLUP, 10, 3
# 1336 "data/maps/LittlerootTown/scripts.pory"
	msgbox Starters_Text_49, MSGBOX_YESNO
# 1337 "data/maps/LittlerootTown/scripts.pory"
	waitfanfare
# 1338 "data/maps/LittlerootTown/scripts.pory"
	waitmessage
	goto Starters_122

Starters_126:
# 1340 "data/maps/LittlerootTown/scripts.pory"
	hidemonpic
# 1341 "data/maps/LittlerootTown/scripts.pory"
	call StarterMenu
	goto Starters_125

Starters_127:
# 1343 "data/maps/LittlerootTown/scripts.pory"
	givemon SPECIES_PIPLUP, 5, ITEM_NONE
	goto Starters_125

Starters_131:
# 1345 "data/maps/LittlerootTown/scripts.pory"
	playfanfare MUS_EVOLVED
# 1346 "data/maps/LittlerootTown/scripts.pory"
	msgbox Starters_Text_50
# 1347 "data/maps/LittlerootTown/scripts.pory"
	waitfanfare
# 1348 "data/maps/LittlerootTown/scripts.pory"
	waitmessage
# 1349 "data/maps/LittlerootTown/scripts.pory"
	removeobject 2
# 1350 "data/maps/LittlerootTown/scripts.pory"
	call NicknamePartyMon
	goto Starters_130

Starters_134:
# 1353 "data/maps/LittlerootTown/scripts.pory"
	playmoncry SPECIES_SNIVY, CRY_MODE_NORMAL
# 1354 "data/maps/LittlerootTown/scripts.pory"
	showmonpic SPECIES_SNIVY, 10, 3
# 1355 "data/maps/LittlerootTown/scripts.pory"
	msgbox Starters_Text_51, MSGBOX_YESNO
# 1356 "data/maps/LittlerootTown/scripts.pory"
	waitmessage
	goto Starters_133

Starters_137:
# 1358 "data/maps/LittlerootTown/scripts.pory"
	hidemonpic
# 1359 "data/maps/LittlerootTown/scripts.pory"
	call StarterMenu
	goto Starters_136

Starters_138:
# 1361 "data/maps/LittlerootTown/scripts.pory"
	givemon SPECIES_SNIVY, 5, ITEM_NONE
	goto Starters_136

Starters_142:
# 1363 "data/maps/LittlerootTown/scripts.pory"
	playfanfare MUS_EVOLVED
# 1364 "data/maps/LittlerootTown/scripts.pory"
	msgbox Starters_Text_52
# 1365 "data/maps/LittlerootTown/scripts.pory"
	waitfanfare
# 1366 "data/maps/LittlerootTown/scripts.pory"
	waitmessage
# 1367 "data/maps/LittlerootTown/scripts.pory"
	call NicknamePartyMon
	goto Starters_141

Starters_145:
# 1370 "data/maps/LittlerootTown/scripts.pory"
	playmoncry SPECIES_TEPIG, CRY_MODE_NORMAL
# 1371 "data/maps/LittlerootTown/scripts.pory"
	showmonpic SPECIES_TEPIG, 10, 3
# 1372 "data/maps/LittlerootTown/scripts.pory"
	msgbox Starters_Text_53, MSGBOX_YESNO
# 1373 "data/maps/LittlerootTown/scripts.pory"
	waitmessage
	goto Starters_144

Starters_148:
# 1375 "data/maps/LittlerootTown/scripts.pory"
	hidemonpic
# 1376 "data/maps/LittlerootTown/scripts.pory"
	call StarterMenu
	goto Starters_147

Starters_149:
# 1378 "data/maps/LittlerootTown/scripts.pory"
	givemon SPECIES_TEPIG, 5, ITEM_NONE
	goto Starters_147

Starters_153:
# 1380 "data/maps/LittlerootTown/scripts.pory"
	playfanfare MUS_EVOLVED
# 1381 "data/maps/LittlerootTown/scripts.pory"
	msgbox Starters_Text_54
# 1382 "data/maps/LittlerootTown/scripts.pory"
	waitfanfare
# 1383 "data/maps/LittlerootTown/scripts.pory"
	waitmessage
# 1384 "data/maps/LittlerootTown/scripts.pory"
	removeobject 2
# 1385 "data/maps/LittlerootTown/scripts.pory"
	call NicknamePartyMon
	goto Starters_152

Starters_156:
# 1388 "data/maps/LittlerootTown/scripts.pory"
	playmoncry SPECIES_OSHAWOTT, CRY_MODE_NORMAL
# 1389 "data/maps/LittlerootTown/scripts.pory"
	showmonpic SPECIES_OSHAWOTT, 10, 3
# 1390 "data/maps/LittlerootTown/scripts.pory"
	msgbox Starters_Text_55, MSGBOX_YESNO
# 1391 "data/maps/LittlerootTown/scripts.pory"
	waitfanfare
# 1392 "data/maps/LittlerootTown/scripts.pory"
	waitmessage
	goto Starters_155

Starters_159:
# 1394 "data/maps/LittlerootTown/scripts.pory"
	hidemonpic
# 1395 "data/maps/LittlerootTown/scripts.pory"
	call StarterMenu
	goto Starters_158

Starters_160:
# 1397 "data/maps/LittlerootTown/scripts.pory"
	givemon SPECIES_OSHAWOTT, 5, ITEM_NONE
	goto Starters_158

Starters_164:
# 1399 "data/maps/LittlerootTown/scripts.pory"
	playfanfare MUS_EVOLVED
# 1400 "data/maps/LittlerootTown/scripts.pory"
	msgbox Starters_Text_56
# 1401 "data/maps/LittlerootTown/scripts.pory"
	waitfanfare
# 1402 "data/maps/LittlerootTown/scripts.pory"
	waitmessage
# 1403 "data/maps/LittlerootTown/scripts.pory"
	removeobject 2
# 1404 "data/maps/LittlerootTown/scripts.pory"
	call NicknamePartyMon
	goto Starters_163

Starters_167:
# 1407 "data/maps/LittlerootTown/scripts.pory"
	playmoncry SPECIES_CHESPIN, CRY_MODE_NORMAL
# 1408 "data/maps/LittlerootTown/scripts.pory"
	showmonpic SPECIES_CHESPIN, 10, 3
# 1409 "data/maps/LittlerootTown/scripts.pory"
	msgbox Starters_Text_57, MSGBOX_YESNO
# 1410 "data/maps/LittlerootTown/scripts.pory"
	waitmessage
	goto Starters_166

Starters_170:
# 1412 "data/maps/LittlerootTown/scripts.pory"
	hidemonpic
# 1413 "data/maps/LittlerootTown/scripts.pory"
	call StarterMenu
	goto Starters_169

Starters_171:
# 1415 "data/maps/LittlerootTown/scripts.pory"
	givemon SPECIES_CHESPIN, 5, ITEM_NONE
	goto Starters_169

Starters_175:
# 1417 "data/maps/LittlerootTown/scripts.pory"
	playfanfare MUS_EVOLVED
# 1418 "data/maps/LittlerootTown/scripts.pory"
	msgbox Starters_Text_58
# 1419 "data/maps/LittlerootTown/scripts.pory"
	waitfanfare
# 1420 "data/maps/LittlerootTown/scripts.pory"
	waitmessage
# 1421 "data/maps/LittlerootTown/scripts.pory"
	removeobject 2
# 1422 "data/maps/LittlerootTown/scripts.pory"
	call NicknamePartyMon
	goto Starters_174

Starters_178:
# 1425 "data/maps/LittlerootTown/scripts.pory"
	playmoncry SPECIES_FENNEKIN, CRY_MODE_NORMAL
# 1426 "data/maps/LittlerootTown/scripts.pory"
	showmonpic SPECIES_FENNEKIN, 10, 3
# 1427 "data/maps/LittlerootTown/scripts.pory"
	msgbox Starters_Text_59, MSGBOX_YESNO
# 1428 "data/maps/LittlerootTown/scripts.pory"
	waitmessage
	goto Starters_177

Starters_181:
# 1430 "data/maps/LittlerootTown/scripts.pory"
	hidemonpic
# 1431 "data/maps/LittlerootTown/scripts.pory"
	call StarterMenu
	goto Starters_180

Starters_182:
# 1433 "data/maps/LittlerootTown/scripts.pory"
	givemon SPECIES_FENNEKIN, 5, ITEM_NONE
	goto Starters_180

Starters_186:
# 1435 "data/maps/LittlerootTown/scripts.pory"
	playfanfare MUS_EVOLVED
# 1436 "data/maps/LittlerootTown/scripts.pory"
	msgbox Starters_Text_60
# 1437 "data/maps/LittlerootTown/scripts.pory"
	waitfanfare
# 1438 "data/maps/LittlerootTown/scripts.pory"
	waitmessage
# 1439 "data/maps/LittlerootTown/scripts.pory"
	removeobject 2
# 1440 "data/maps/LittlerootTown/scripts.pory"
	call NicknamePartyMon
	goto Starters_185

Starters_189:
# 1443 "data/maps/LittlerootTown/scripts.pory"
	playmoncry SPECIES_FROAKIE, CRY_MODE_NORMAL
# 1444 "data/maps/LittlerootTown/scripts.pory"
	showmonpic SPECIES_FROAKIE, 10, 3
# 1445 "data/maps/LittlerootTown/scripts.pory"
	msgbox Starters_Text_61, MSGBOX_YESNO
# 1446 "data/maps/LittlerootTown/scripts.pory"
	waitmessage
	goto Starters_188

Starters_192:
# 1448 "data/maps/LittlerootTown/scripts.pory"
	hidemonpic
# 1449 "data/maps/LittlerootTown/scripts.pory"
	call StarterMenu
	goto Starters_191

Starters_193:
# 1451 "data/maps/LittlerootTown/scripts.pory"
	givemon SPECIES_FROAKIE, 5, ITEM_NONE
	goto Starters_191

Starters_197:
# 1453 "data/maps/LittlerootTown/scripts.pory"
	playfanfare MUS_EVOLVED
# 1454 "data/maps/LittlerootTown/scripts.pory"
	msgbox Starters_Text_62
# 1455 "data/maps/LittlerootTown/scripts.pory"
	waitfanfare
# 1456 "data/maps/LittlerootTown/scripts.pory"
	removeobject 2
# 1457 "data/maps/LittlerootTown/scripts.pory"
	waitmessage
# 1458 "data/maps/LittlerootTown/scripts.pory"
	call NicknamePartyMon
	goto Starters_196

Starters_200:
# 1461 "data/maps/LittlerootTown/scripts.pory"
	playmoncry SPECIES_ROWLET, CRY_MODE_NORMAL
# 1462 "data/maps/LittlerootTown/scripts.pory"
	showmonpic SPECIES_ROWLET, 10, 3
# 1463 "data/maps/LittlerootTown/scripts.pory"
	msgbox Starters_Text_63, MSGBOX_YESNO
# 1464 "data/maps/LittlerootTown/scripts.pory"
	waitmessage
	goto Starters_199

Starters_203:
# 1466 "data/maps/LittlerootTown/scripts.pory"
	hidemonpic
# 1467 "data/maps/LittlerootTown/scripts.pory"
	call StarterMenu
	goto Starters_202

Starters_204:
# 1469 "data/maps/LittlerootTown/scripts.pory"
	givemon SPECIES_ROWLET, 5, ITEM_NONE
	goto Starters_202

Starters_208:
# 1471 "data/maps/LittlerootTown/scripts.pory"
	playfanfare MUS_EVOLVED
# 1472 "data/maps/LittlerootTown/scripts.pory"
	msgbox Starters_Text_64
# 1473 "data/maps/LittlerootTown/scripts.pory"
	waitfanfare
# 1474 "data/maps/LittlerootTown/scripts.pory"
	waitmessage
# 1475 "data/maps/LittlerootTown/scripts.pory"
	removeobject 2
# 1476 "data/maps/LittlerootTown/scripts.pory"
	call NicknamePartyMon
	goto Starters_207

Starters_211:
# 1479 "data/maps/LittlerootTown/scripts.pory"
	playmoncry SPECIES_LITTEN, CRY_MODE_NORMAL
# 1480 "data/maps/LittlerootTown/scripts.pory"
	showmonpic SPECIES_LITTEN, 10, 3
# 1481 "data/maps/LittlerootTown/scripts.pory"
	msgbox Starters_Text_65, MSGBOX_YESNO
# 1482 "data/maps/LittlerootTown/scripts.pory"
	waitmessage
	goto Starters_210

Starters_214:
# 1484 "data/maps/LittlerootTown/scripts.pory"
	hidemonpic
# 1485 "data/maps/LittlerootTown/scripts.pory"
	call StarterMenu
	goto Starters_213

Starters_215:
# 1487 "data/maps/LittlerootTown/scripts.pory"
	givemon SPECIES_LITTEN, 5, ITEM_NONE
	goto Starters_213

Starters_219:
# 1489 "data/maps/LittlerootTown/scripts.pory"
	playfanfare MUS_EVOLVED
# 1490 "data/maps/LittlerootTown/scripts.pory"
	msgbox Starters_Text_66
# 1491 "data/maps/LittlerootTown/scripts.pory"
	waitfanfare
# 1492 "data/maps/LittlerootTown/scripts.pory"
	waitmessage
# 1493 "data/maps/LittlerootTown/scripts.pory"
	removeobject 2
# 1494 "data/maps/LittlerootTown/scripts.pory"
	call NicknamePartyMon
	goto Starters_218

Starters_222:
# 1497 "data/maps/LittlerootTown/scripts.pory"
	playmoncry SPECIES_POPPLIO, CRY_MODE_NORMAL
# 1498 "data/maps/LittlerootTown/scripts.pory"
	showmonpic SPECIES_POPPLIO, 10, 3
# 1499 "data/maps/LittlerootTown/scripts.pory"
	msgbox Starters_Text_67, MSGBOX_YESNO
# 1500 "data/maps/LittlerootTown/scripts.pory"
	waitmessage
	goto Starters_221

Starters_225:
# 1502 "data/maps/LittlerootTown/scripts.pory"
	hidemonpic
# 1503 "data/maps/LittlerootTown/scripts.pory"
	call StarterMenu
	goto Starters_224

Starters_226:
# 1505 "data/maps/LittlerootTown/scripts.pory"
	givemon SPECIES_POPPLIO, 5, ITEM_NONE
	goto Starters_224

Starters_230:
# 1507 "data/maps/LittlerootTown/scripts.pory"
	playfanfare MUS_EVOLVED
# 1508 "data/maps/LittlerootTown/scripts.pory"
	msgbox Starters_Text_68
# 1509 "data/maps/LittlerootTown/scripts.pory"
	waitfanfare
# 1510 "data/maps/LittlerootTown/scripts.pory"
	waitmessage
# 1511 "data/maps/LittlerootTown/scripts.pory"
	removeobject 2
# 1512 "data/maps/LittlerootTown/scripts.pory"
	call NicknamePartyMon
	goto Starters_229

Starters_233:
# 1515 "data/maps/LittlerootTown/scripts.pory"
	playmoncry SPECIES_GROOKEY, CRY_MODE_NORMAL
# 1516 "data/maps/LittlerootTown/scripts.pory"
	showmonpic SPECIES_GROOKEY, 10, 3
# 1517 "data/maps/LittlerootTown/scripts.pory"
	msgbox Starters_Text_69, MSGBOX_YESNO
# 1518 "data/maps/LittlerootTown/scripts.pory"
	waitmessage
	goto Starters_232

Starters_236:
# 1520 "data/maps/LittlerootTown/scripts.pory"
	hidemonpic
# 1521 "data/maps/LittlerootTown/scripts.pory"
	call StarterMenu
	goto Starters_235

Starters_237:
# 1523 "data/maps/LittlerootTown/scripts.pory"
	givemon SPECIES_FROAKIE, 5, ITEM_NONE
	goto Starters_235

Starters_241:
# 1525 "data/maps/LittlerootTown/scripts.pory"
	playfanfare MUS_EVOLVED
# 1526 "data/maps/LittlerootTown/scripts.pory"
	msgbox Starters_Text_70
# 1527 "data/maps/LittlerootTown/scripts.pory"
	waitfanfare
# 1528 "data/maps/LittlerootTown/scripts.pory"
	waitmessage
# 1529 "data/maps/LittlerootTown/scripts.pory"
	removeobject 2
# 1530 "data/maps/LittlerootTown/scripts.pory"
	call NicknamePartyMon
	goto Starters_240

Starters_244:
# 1533 "data/maps/LittlerootTown/scripts.pory"
	playmoncry SPECIES_SCORBUNNY, CRY_MODE_NORMAL
# 1534 "data/maps/LittlerootTown/scripts.pory"
	showmonpic SPECIES_SCORBUNNY, 10, 3
# 1535 "data/maps/LittlerootTown/scripts.pory"
	msgbox Starters_Text_71, MSGBOX_YESNO
# 1536 "data/maps/LittlerootTown/scripts.pory"
	waitmessage
	goto Starters_243

Starters_247:
# 1538 "data/maps/LittlerootTown/scripts.pory"
	hidemonpic
# 1539 "data/maps/LittlerootTown/scripts.pory"
	call StarterMenu
	goto Starters_246

Starters_248:
# 1541 "data/maps/LittlerootTown/scripts.pory"
	givemon SPECIES_SCORBUNNY, 5, ITEM_NONE
	goto Starters_246

Starters_252:
# 1543 "data/maps/LittlerootTown/scripts.pory"
	playfanfare MUS_EVOLVED
# 1544 "data/maps/LittlerootTown/scripts.pory"
	msgbox Starters_Text_72
# 1545 "data/maps/LittlerootTown/scripts.pory"
	waitfanfare
# 1546 "data/maps/LittlerootTown/scripts.pory"
	waitmessage
# 1547 "data/maps/LittlerootTown/scripts.pory"
	removeobject 2
# 1548 "data/maps/LittlerootTown/scripts.pory"
	call NicknamePartyMon
	goto Starters_251

Starters_255:
# 1551 "data/maps/LittlerootTown/scripts.pory"
	playmoncry SPECIES_SOBBLE, CRY_MODE_NORMAL
# 1552 "data/maps/LittlerootTown/scripts.pory"
	showmonpic SPECIES_SOBBLE, 10, 3
# 1553 "data/maps/LittlerootTown/scripts.pory"
	msgbox Starters_Text_73, MSGBOX_YESNO
# 1554 "data/maps/LittlerootTown/scripts.pory"
	waitmessage
	goto Starters_254

Starters_258:
# 1556 "data/maps/LittlerootTown/scripts.pory"
	hidemonpic
# 1557 "data/maps/LittlerootTown/scripts.pory"
	call StarterMenu
	goto Starters_257

Starters_259:
# 1559 "data/maps/LittlerootTown/scripts.pory"
	givemon SPECIES_SOBBLE, 5, ITEM_NONE
	goto Starters_257

Starters_263:
# 1561 "data/maps/LittlerootTown/scripts.pory"
	playfanfare MUS_EVOLVED
# 1562 "data/maps/LittlerootTown/scripts.pory"
	msgbox Starters_Text_74
# 1563 "data/maps/LittlerootTown/scripts.pory"
	waitfanfare
# 1564 "data/maps/LittlerootTown/scripts.pory"
	waitmessage
# 1565 "data/maps/LittlerootTown/scripts.pory"
	removeobject 2
# 1566 "data/maps/LittlerootTown/scripts.pory"
	call NicknamePartyMon
	goto Starters_262

Starters_266:
# 1569 "data/maps/LittlerootTown/scripts.pory"
	playmoncry SPECIES_SPRIGATITO, CRY_MODE_NORMAL
# 1570 "data/maps/LittlerootTown/scripts.pory"
	showmonpic SPECIES_SPRIGATITO, 10, 3
# 1571 "data/maps/LittlerootTown/scripts.pory"
	msgbox Starters_Text_75, MSGBOX_YESNO
# 1572 "data/maps/LittlerootTown/scripts.pory"
	waitmessage
	goto Starters_265

Starters_269:
# 1574 "data/maps/LittlerootTown/scripts.pory"
	hidemonpic
# 1575 "data/maps/LittlerootTown/scripts.pory"
	call StarterMenu
	goto Starters_268

Starters_270:
# 1577 "data/maps/LittlerootTown/scripts.pory"
	givemon SPECIES_SPRIGATITO, 5, ITEM_NONE
	goto Starters_268

Starters_274:
# 1579 "data/maps/LittlerootTown/scripts.pory"
	playfanfare MUS_EVOLVED
# 1580 "data/maps/LittlerootTown/scripts.pory"
	msgbox Starters_Text_76
# 1581 "data/maps/LittlerootTown/scripts.pory"
	waitfanfare
# 1582 "data/maps/LittlerootTown/scripts.pory"
	waitmessage
# 1583 "data/maps/LittlerootTown/scripts.pory"
	removeobject 2
# 1584 "data/maps/LittlerootTown/scripts.pory"
	call NicknamePartyMon
	goto Starters_273

Starters_277:
# 1587 "data/maps/LittlerootTown/scripts.pory"
	playmoncry SPECIES_FUECOCO, CRY_MODE_NORMAL
# 1588 "data/maps/LittlerootTown/scripts.pory"
	showmonpic SPECIES_FUECOCO, 10, 3
# 1589 "data/maps/LittlerootTown/scripts.pory"
	msgbox Starters_Text_77, MSGBOX_YESNO
# 1590 "data/maps/LittlerootTown/scripts.pory"
	waitmessage
	goto Starters_276

Starters_280:
# 1592 "data/maps/LittlerootTown/scripts.pory"
	hidemonpic
# 1593 "data/maps/LittlerootTown/scripts.pory"
	call StarterMenu
	goto Starters_279

Starters_281:
# 1595 "data/maps/LittlerootTown/scripts.pory"
	givemon SPECIES_FUECOCO, 5, ITEM_NONE
	goto Starters_279

Starters_285:
# 1597 "data/maps/LittlerootTown/scripts.pory"
	playfanfare MUS_EVOLVED
# 1598 "data/maps/LittlerootTown/scripts.pory"
	msgbox Starters_Text_78
# 1599 "data/maps/LittlerootTown/scripts.pory"
	waitfanfare
# 1600 "data/maps/LittlerootTown/scripts.pory"
	waitmessage
# 1601 "data/maps/LittlerootTown/scripts.pory"
	removeobject 2
# 1602 "data/maps/LittlerootTown/scripts.pory"
	call NicknamePartyMon
	goto Starters_284

Starters_288:
# 1605 "data/maps/LittlerootTown/scripts.pory"
	playmoncry SPECIES_QUAXLY, CRY_MODE_NORMAL
# 1606 "data/maps/LittlerootTown/scripts.pory"
	showmonpic SPECIES_QUAXLY, 10, 3
# 1607 "data/maps/LittlerootTown/scripts.pory"
	msgbox Starters_Text_79, MSGBOX_YESNO
# 1608 "data/maps/LittlerootTown/scripts.pory"
	waitmessage
	goto Starters_287

Starters_291:
# 1610 "data/maps/LittlerootTown/scripts.pory"
	hidemonpic
# 1611 "data/maps/LittlerootTown/scripts.pory"
	call StarterMenu
	goto Starters_290

Starters_292:
# 1613 "data/maps/LittlerootTown/scripts.pory"
	givemon SPECIES_QUAXLY, 5, ITEM_NONE
	goto Starters_290

Starters_295:
# 1615 "data/maps/LittlerootTown/scripts.pory"
	playfanfare MUS_EVOLVED
# 1616 "data/maps/LittlerootTown/scripts.pory"
	msgbox Starters_Text_80
# 1617 "data/maps/LittlerootTown/scripts.pory"
	waitfanfare
# 1618 "data/maps/LittlerootTown/scripts.pory"
	waitmessage
# 1619 "data/maps/LittlerootTown/scripts.pory"
	removeobject 2
# 1620 "data/maps/LittlerootTown/scripts.pory"
	call NicknamePartyMon
	return


NicknameBoxMon::
# 1626 "data/maps/LittlerootTown/scripts.pory"
	msgbox NicknameBoxMon_Text_0, MSGBOX_YESNO
# 1627 "data/maps/LittlerootTown/scripts.pory"
	waitmessage
# 1628 "data/maps/LittlerootTown/scripts.pory"
	hidemonpic
# 1629 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq NicknameBoxMon_2
NicknameBoxMon_1:
# 1634 "data/maps/LittlerootTown/scripts.pory"
	msgbox NicknameBoxMon_Text_1
	return

NicknameBoxMon_2:
# 1630 "data/maps/LittlerootTown/scripts.pory"
	call Common_EventScript_NameReceivedBoxMon
# 1631 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 1632 "data/maps/LittlerootTown/scripts.pory"
	release
	goto NicknameBoxMon_1


NicknamePartyMon::
# 1638 "data/maps/LittlerootTown/scripts.pory"
	msgbox NicknamePartyMon_Text_0, MSGBOX_YESNO
# 1639 "data/maps/LittlerootTown/scripts.pory"
	waitmessage
# 1640 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq NicknamePartyMon_1
# 1648 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq NicknamePartyMon_2
	return

NicknamePartyMon_1:
# 1641 "data/maps/LittlerootTown/scripts.pory"
	call Common_EventScript_GetGiftMonPartySlot
# 1642 "data/maps/LittlerootTown/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
# 1643 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
# 1644 "data/maps/LittlerootTown/scripts.pory"
	hidemonpic
# 1645 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 1646 "data/maps/LittlerootTown/scripts.pory"
	release
	end

NicknamePartyMon_2:
# 1649 "data/maps/LittlerootTown/scripts.pory"
	call Common_EventScript_GetGiftMonPartySlot
# 1650 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
# 1651 "data/maps/LittlerootTown/scripts.pory"
	hidemonpic
# 1652 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 1653 "data/maps/LittlerootTown/scripts.pory"
	release
	end


StarterKit::
# 1658 "data/maps/LittlerootTown/scripts.pory"
	msgbox StarterKit_Text_0
# 1659 "data/maps/LittlerootTown/scripts.pory"
	giveitem ITEM_POKE_BALL, 10
# 1660 "data/maps/LittlerootTown/scripts.pory"
	msgbox StarterKit_Text_1
# 1661 "data/maps/LittlerootTown/scripts.pory"
	giveitem ITEM_POTION, 5
# 1662 "data/maps/LittlerootTown/scripts.pory"
	msgbox StarterKit_Text_2
# 1663 "data/maps/LittlerootTown/scripts.pory"
	release
	end


LittlerootTown_EventScript_NewLittlerootTownSign_Text_0:
# 1026 "data/maps/LittlerootTown/scripts.pory"
	.string "Testing!$"

ChampionVerified_Text_0:
# 1044 "data/maps/LittlerootTown/scripts.pory"
	.string "DING DING DING! Hall of Fame\n"
	.string "Status...Confirmed!$"

ChampionVerified_Text_1:
# 1045 "data/maps/LittlerootTown/scripts.pory"
	.string "CharonChaos: You're the Hoenn\n"
	.string "Champion. Congratulations!$"

ChampionVerified_Text_2:
# 1046 "data/maps/LittlerootTown/scripts.pory"
	.string "CharonChaos: Maxie has requested me to\n"
	.string "send you his blessings. Enjoy the new\l"
	.string "Littleroot Town for saving our lives!$"

ChampionVerified_Text_3:
# 1052 "data/maps/LittlerootTown/scripts.pory"
	.string "Congratulations {PLAYER}! You now\n"
	.string "have access to New Littleroot Town!$"

ChampionNotVerified_Text_0:
# 1063 "data/maps/LittlerootTown/scripts.pory"
	.string "Error: Current name {PLAYER} is not a\n"
	.string "Hoenn Champion!$"

ChampionNotVerified_Text_1:
# 1064 "data/maps/LittlerootTown/scripts.pory"
	.string "CharonChaos: Bummer... Looks like you\n"
	.string "got ways to go.$"

ChampionNotVerified_Text_2:
# 1065 "data/maps/LittlerootTown/scripts.pory"
	.string "CharonChaos: Come back when you\n"
	.string "become the Hoenn Champion.$"

GymVerifyIntro_Text_0:
# 1071 "data/maps/LittlerootTown/scripts.pory"
	.string "CharonChaos: OKAY! OKAY! I'll have it\n"
	.string "done before the new champion enters\l"
	.string "the hall of fame.$"

GymVerifyIntro_Text_1:
# 1072 "data/maps/LittlerootTown/scripts.pory"
	.string "CharonChaos: Oh my bad! I was talking\n"
	.string "to my boss. Hello, I am CharonChaos!$"

GymVerifyIntro_Text_2:
# 1073 "data/maps/LittlerootTown/scripts.pory"
	.string "CharonChaos: What's your name?$"

GymVerifyIntro_Text_3:
# 1074 "data/maps/LittlerootTown/scripts.pory"
	.string "CharonChaos: ... {PLAYER}? Cool!$"

GymVerifyIntro_Text_4:
# 1075 "data/maps/LittlerootTown/scripts.pory"
	.string "CharonChaos: You might be wondering\n"
	.string "why I am guarding this place. Well, it is\l"
	.string "part of Littleroot Town. In fact, It is\l"
	.string "New Littleroot Town.$"

GymVerifyIntro_Text_5:
# 1076 "data/maps/LittlerootTown/scripts.pory"
	.string "CharonChaos: I was contracted by Team\n"
	.string "Magma...$"

GymVerifyIntro_Text_6:
# 1077 "data/maps/LittlerootTown/scripts.pory"
	.string "CharonChaos: No I am not a bad guy. I'll\n"
	.string "explain.$"

GymVerifyIntro_Text_7:
# 1078 "data/maps/LittlerootTown/scripts.pory"
	.string "CharonChaos: I was a former Hoenn\n"
	.string "Champion a while back and I recently\l"
	.string "retired.$"

GymVerifyIntro_Text_8:
# 1079 "data/maps/LittlerootTown/scripts.pory"
	.string "CharonChaos: Anyways...$"

GymVerifyIntro_Text_9:
# 1080 "data/maps/LittlerootTown/scripts.pory"
	.string "CharonChaos: In order for you to pass\n"
	.string "{PLAYER}, you need to become the\l"
	.string "Hoenn region's champion. Otherwise, I\l"
	.string "cannot let you in New Littleroot Town.$"

Verification_Text_0:
# 1089 "data/maps/LittlerootTown/scripts.pory"
	.string "CharonChaos: Let me attempt to verify\n"
	.string "your name {PLAYER} to the Hoenn\l"
	.string "region Hall of Fame database...$"

StarterMenu_Text_0:
# 1099 "data/maps/LittlerootTown/scripts.pory"
	.string "Choose your starter.$"

Starters_Text_0:
# 1109 "data/maps/LittlerootTown/scripts.pory"
	.string "Bulbasaur$"

Starters_Text_1:
# 1110 "data/maps/LittlerootTown/scripts.pory"
	.string "Charmander$"

Starters_Text_2:
# 1111 "data/maps/LittlerootTown/scripts.pory"
	.string "Squirtle$"

Starters_Text_3:
# 1112 "data/maps/LittlerootTown/scripts.pory"
	.string "Chikorita$"

Starters_Text_4:
# 1113 "data/maps/LittlerootTown/scripts.pory"
	.string "Cyndaquil$"

Starters_Text_5:
# 1114 "data/maps/LittlerootTown/scripts.pory"
	.string "Totodile$"

Starters_Text_6:
# 1115 "data/maps/LittlerootTown/scripts.pory"
	.string "Treecko$"

Starters_Text_7:
# 1116 "data/maps/LittlerootTown/scripts.pory"
	.string "Torchic$"

Starters_Text_8:
# 1117 "data/maps/LittlerootTown/scripts.pory"
	.string "Mudkip$"

Starters_Text_9:
# 1118 "data/maps/LittlerootTown/scripts.pory"
	.string "Turtwig$"

Starters_Text_10:
# 1119 "data/maps/LittlerootTown/scripts.pory"
	.string "Chimchar$"

Starters_Text_11:
# 1120 "data/maps/LittlerootTown/scripts.pory"
	.string "Piplup$"

Starters_Text_12:
# 1121 "data/maps/LittlerootTown/scripts.pory"
	.string "Snivy$"

Starters_Text_13:
# 1122 "data/maps/LittlerootTown/scripts.pory"
	.string "Tepig$"

Starters_Text_14:
# 1123 "data/maps/LittlerootTown/scripts.pory"
	.string "Oshawott$"

Starters_Text_15:
# 1124 "data/maps/LittlerootTown/scripts.pory"
	.string "Chespin$"

Starters_Text_16:
# 1125 "data/maps/LittlerootTown/scripts.pory"
	.string "Fennekin$"

Starters_Text_17:
# 1126 "data/maps/LittlerootTown/scripts.pory"
	.string "Froakie$"

Starters_Text_18:
# 1127 "data/maps/LittlerootTown/scripts.pory"
	.string "Rowlet$"

Starters_Text_19:
# 1128 "data/maps/LittlerootTown/scripts.pory"
	.string "Litten$"

Starters_Text_20:
# 1129 "data/maps/LittlerootTown/scripts.pory"
	.string "Popplio$"

Starters_Text_21:
# 1130 "data/maps/LittlerootTown/scripts.pory"
	.string "Grookey$"

Starters_Text_22:
# 1131 "data/maps/LittlerootTown/scripts.pory"
	.string "Scorbunny$"

Starters_Text_23:
# 1132 "data/maps/LittlerootTown/scripts.pory"
	.string "Sobble$"

Starters_Text_24:
# 1133 "data/maps/LittlerootTown/scripts.pory"
	.string "Sprigatito$"

Starters_Text_25:
# 1134 "data/maps/LittlerootTown/scripts.pory"
	.string "Fuecoco$"

Starters_Text_26:
# 1135 "data/maps/LittlerootTown/scripts.pory"
	.string "Quaxly$"

Starters_Text_27:
# 1140 "data/maps/LittlerootTown/scripts.pory"
	.string "Are you sure you want Bulbasaur?$"

Starters_Text_28:
# 1149 "data/maps/LittlerootTown/scripts.pory"
	.string "{PLAYER} received Bulbasaur!$"

Starters_Text_29:
# 1158 "data/maps/LittlerootTown/scripts.pory"
	.string "Are you sure you want Charmander?$"

Starters_Text_30:
# 1167 "data/maps/LittlerootTown/scripts.pory"
	.string "{PLAYER} received Charmander!$"

Starters_Text_31:
# 1176 "data/maps/LittlerootTown/scripts.pory"
	.string "Are you sure you want Squirtle?$"

Starters_Text_32:
# 1185 "data/maps/LittlerootTown/scripts.pory"
	.string "{PLAYER} received Squirtle!$"

Starters_Text_33:
# 1194 "data/maps/LittlerootTown/scripts.pory"
	.string "Are you sure you want Chikorita?$"

Starters_Text_34:
# 1202 "data/maps/LittlerootTown/scripts.pory"
	.string "{PLAYER} received Chikorita!$"

Starters_Text_35:
# 1211 "data/maps/LittlerootTown/scripts.pory"
	.string "Are you sure you want Cyndaquil?$"

Starters_Text_36:
# 1219 "data/maps/LittlerootTown/scripts.pory"
	.string "{PLAYER} received Cyndaquil!$"

Starters_Text_37:
# 1228 "data/maps/LittlerootTown/scripts.pory"
	.string "Are you sure you want Totodile?$"

Starters_Text_38:
# 1237 "data/maps/LittlerootTown/scripts.pory"
	.string "{PLAYER} received Totodile!$"

Starters_Text_39:
# 1246 "data/maps/LittlerootTown/scripts.pory"
	.string "Are you sure you want Treecko?$"

Starters_Text_40:
# 1254 "data/maps/LittlerootTown/scripts.pory"
	.string "{PLAYER} received Treecko!$"

Starters_Text_41:
# 1263 "data/maps/LittlerootTown/scripts.pory"
	.string "Are you sure you want Torchic?$"

Starters_Text_42:
# 1272 "data/maps/LittlerootTown/scripts.pory"
	.string "{PLAYER} received Torchic!$"

Starters_Text_43:
# 1281 "data/maps/LittlerootTown/scripts.pory"
	.string "Are you sure you want Mudkip?$"

Starters_Text_44:
# 1290 "data/maps/LittlerootTown/scripts.pory"
	.string "{PLAYER} received Mudkip!$"

Starters_Text_45:
# 1299 "data/maps/LittlerootTown/scripts.pory"
	.string "Are you sure you want Turtwig?$"

Starters_Text_46:
# 1308 "data/maps/LittlerootTown/scripts.pory"
	.string "{PLAYER} received Turtwig!$"

Starters_Text_47:
# 1317 "data/maps/LittlerootTown/scripts.pory"
	.string "Are you sure you want Chimchar?$"

Starters_Text_48:
# 1327 "data/maps/LittlerootTown/scripts.pory"
	.string "{PLAYER} received Chimchar!$"

Starters_Text_49:
# 1336 "data/maps/LittlerootTown/scripts.pory"
	.string "Are you sure you want Piplup?$"

Starters_Text_50:
# 1346 "data/maps/LittlerootTown/scripts.pory"
	.string "{PLAYER} received Piplup!$"

Starters_Text_51:
# 1355 "data/maps/LittlerootTown/scripts.pory"
	.string "Are you sure you want Snivy?$"

Starters_Text_52:
# 1364 "data/maps/LittlerootTown/scripts.pory"
	.string "{PLAYER} received Snivy!$"

Starters_Text_53:
# 1372 "data/maps/LittlerootTown/scripts.pory"
	.string "Are you sure you want Tepig?$"

Starters_Text_54:
# 1381 "data/maps/LittlerootTown/scripts.pory"
	.string "{PLAYER} received Tepig!$"

Starters_Text_55:
# 1390 "data/maps/LittlerootTown/scripts.pory"
	.string "Are you sure you want Oshawott?$"

Starters_Text_56:
# 1400 "data/maps/LittlerootTown/scripts.pory"
	.string "{PLAYER} received Oshawott!$"

Starters_Text_57:
# 1409 "data/maps/LittlerootTown/scripts.pory"
	.string "Are you sure you want Chespin?$"

Starters_Text_58:
# 1418 "data/maps/LittlerootTown/scripts.pory"
	.string "{PLAYER} received Chespin!$"

Starters_Text_59:
# 1427 "data/maps/LittlerootTown/scripts.pory"
	.string "Are you sure you want Fennekin?$"

Starters_Text_60:
# 1436 "data/maps/LittlerootTown/scripts.pory"
	.string "{PLAYER} received Fennekin!$"

Starters_Text_61:
# 1445 "data/maps/LittlerootTown/scripts.pory"
	.string "Are you sure you want Froakie?$"

Starters_Text_62:
# 1454 "data/maps/LittlerootTown/scripts.pory"
	.string "{PLAYER} received Froakie!$"

Starters_Text_63:
# 1463 "data/maps/LittlerootTown/scripts.pory"
	.string "Are you sure you want Rowlet?$"

Starters_Text_64:
# 1472 "data/maps/LittlerootTown/scripts.pory"
	.string "{PLAYER} received Rowlet!$"

Starters_Text_65:
# 1481 "data/maps/LittlerootTown/scripts.pory"
	.string "Are you sure you want Litten?$"

Starters_Text_66:
# 1490 "data/maps/LittlerootTown/scripts.pory"
	.string "{PLAYER} received Litten!$"

Starters_Text_67:
# 1499 "data/maps/LittlerootTown/scripts.pory"
	.string "Are you sure you want Popplio?$"

Starters_Text_68:
# 1508 "data/maps/LittlerootTown/scripts.pory"
	.string "{PLAYER} received Popplio!$"

Starters_Text_69:
# 1517 "data/maps/LittlerootTown/scripts.pory"
	.string "Are you sure you want Grookey?$"

Starters_Text_70:
# 1526 "data/maps/LittlerootTown/scripts.pory"
	.string "{PLAYER} received Grookey!$"

Starters_Text_71:
# 1535 "data/maps/LittlerootTown/scripts.pory"
	.string "Are you sure you want Scorbunny?$"

Starters_Text_72:
# 1544 "data/maps/LittlerootTown/scripts.pory"
	.string "{PLAYER} received Scorbunny!$"

Starters_Text_73:
# 1553 "data/maps/LittlerootTown/scripts.pory"
	.string "Are you sure you want Sobble?$"

Starters_Text_74:
# 1562 "data/maps/LittlerootTown/scripts.pory"
	.string "{PLAYER} received Sobble!$"

Starters_Text_75:
# 1571 "data/maps/LittlerootTown/scripts.pory"
	.string "Are you sure you want Sprigatito?$"

Starters_Text_76:
# 1580 "data/maps/LittlerootTown/scripts.pory"
	.string "{PLAYER} received Sprigatito!$"

Starters_Text_77:
# 1589 "data/maps/LittlerootTown/scripts.pory"
	.string "Are you sure you want Fuecoco?$"

Starters_Text_78:
# 1598 "data/maps/LittlerootTown/scripts.pory"
	.string "{PLAYER} received Fuecoco!$"

Starters_Text_79:
# 1607 "data/maps/LittlerootTown/scripts.pory"
	.string "Are you sure you want Quaxly?$"

Starters_Text_80:
# 1616 "data/maps/LittlerootTown/scripts.pory"
	.string "{PLAYER} received Quaxly!$"

NicknameBoxMon_Text_0:
# 1626 "data/maps/LittlerootTown/scripts.pory"
	.string "Would you like to give your starter a nickname?$"

NicknameBoxMon_Text_1:
# 1634 "data/maps/LittlerootTown/scripts.pory"
	.string "Transferred to PC$"

NicknamePartyMon_Text_0:
# 1638 "data/maps/LittlerootTown/scripts.pory"
	.string "Would you like to give your starter\na nickname?$"

StarterKit_Text_0:
# 1658 "data/maps/LittlerootTown/scripts.pory"
	.string "{PLAYER} looks further into the bag.$"

StarterKit_Text_1:
# 1660 "data/maps/LittlerootTown/scripts.pory"
	.string "{PLAYER} obtained 10 Poké Balls.$"

StarterKit_Text_2:
# 1662 "data/maps/LittlerootTown/scripts.pory"
	.string "{PLAYER} obtained 5 Potions.$"
