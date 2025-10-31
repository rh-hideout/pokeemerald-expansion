# 1 "data/maps/LittlerootTown/scripts.pory"

# 2 "data/maps/LittlerootTown/scripts.pory"

# 3 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_MapScripts::
# 4 "data/maps/LittlerootTown/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_OnTransition
# 5 "data/maps/LittlerootTown/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_OnFrame
# 6 "data/maps/LittlerootTown/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, LittlerootTown_OnWarp
# 7 "data/maps/LittlerootTown/scripts.pory"
	.byte 0
# 8 "data/maps/LittlerootTown/scripts.pory"

# 9 "data/maps/LittlerootTown/scripts.pory"
	@ State descriptions for VAR_LITTLEROOT_TOWN_STATE
# 10 "data/maps/LittlerootTown/scripts.pory"
	@ 1: Met Rival
# 11 "data/maps/LittlerootTown/scripts.pory"
	@ 2: Saving Birch
# 12 "data/maps/LittlerootTown/scripts.pory"
	@ 3: Received Pokedex
# 13 "data/maps/LittlerootTown/scripts.pory"
	@ 4: Received Running Shoes
# 14 "data/maps/LittlerootTown/scripts.pory"

# 15 "data/maps/LittlerootTown/scripts.pory"
	@ State descriptions for VAR_LITTLEROOT_INTRO_STATE
# 16 "data/maps/LittlerootTown/scripts.pory"
	@ 1: In truck male
# 17 "data/maps/LittlerootTown/scripts.pory"
	@ 2: In truck female
# 18 "data/maps/LittlerootTown/scripts.pory"
	@ 3: Entered house
# 19 "data/maps/LittlerootTown/scripts.pory"
	@ 4: Told to go set clock
# 20 "data/maps/LittlerootTown/scripts.pory"
	@ 5: Entered 2F to set clock
# 21 "data/maps/LittlerootTown/scripts.pory"
	@ 6: Set clock
# 22 "data/maps/LittlerootTown/scripts.pory"
	@ 7: Told to go meet rival
# 23 "data/maps/LittlerootTown/scripts.pory"

# 24 "data/maps/LittlerootTown/scripts.pory"
	@ State descriptions for VAR_LITTLEROOT_HOUSES_STATE_MAY
# 25 "data/maps/LittlerootTown/scripts.pory"
	@                    and VAR_LITTLEROOT_HOUSES_STATE_BRENDAN
# 26 "data/maps/LittlerootTown/scripts.pory"
	@ 1: On Truck (and is corresponding gender)
# 27 "data/maps/LittlerootTown/scripts.pory"
	@ 2: Met Rival's Mom (and is corresponding gender)
# 28 "data/maps/LittlerootTown/scripts.pory"
	@ 3: Entered Hall of Fame
# 29 "data/maps/LittlerootTown/scripts.pory"
	@ 4: Completed Lati TV / SS Ticket event
# 30 "data/maps/LittlerootTown/scripts.pory"
	@ 5: Exited house after above event
# 31 "data/maps/LittlerootTown/scripts.pory"

# 32 "data/maps/LittlerootTown/scripts.pory"
	@ State descriptions for VAR_LITTLEROOT_RIVAL_STATE
# 33 "data/maps/LittlerootTown/scripts.pory"
	@ 1: Never occurs
# 34 "data/maps/LittlerootTown/scripts.pory"
	@ 2: Entered Rival's bedroom
# 35 "data/maps/LittlerootTown/scripts.pory"
	@ 3: Met Rival
# 36 "data/maps/LittlerootTown/scripts.pory"
	@ 4: Received Pokedex
# 37 "data/maps/LittlerootTown/scripts.pory"

# 38 "data/maps/LittlerootTown/scripts.pory"

# 39 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_OnTransition:
# 40 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_VISITED_LITTLEROOT_TOWN
# 41 "data/maps/LittlerootTown/scripts.pory"
	call Common_EventScript_SetupRivalGfxId
# 42 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 2, LittlerootTown_EventScript_MoveMomToMaysDoor
# 43 "data/maps/LittlerootTown/scripts.pory"
	call_if_unset FLAG_RESCUED_BIRCH, LittlerootTown_EventScript_SetTwinPos
# 44 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_LITTLEROOT_TOWN_STATE, 3, LittlerootTown_EventScript_SetMomStandingInFrontOfDoorPos
# 45 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_LITTLEROOT_HOUSES_STATE_MAY, 4, LittlerootTown_EventScript_SetExitedHouseAfterLatiSSTicketEvent
# 46 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_LITTLEROOT_HOUSES_STATE_BRENDAN, 4, LittlerootTown_EventScript_SetExitedHouseAfterLatiSSTicketEvent
# 47 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_OLDALE_RIVAL_STATE, 1, LittlerootTown_EventScript_MoveRivalFromOldale
# 48 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_LITTLEROOT_RIVAL_STATE, 3, LittlerootTown_EventScript_SetRivalLeftForRoute103
# 49 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 1, LittlerootTown_EventScript_HideMapNamePopup
# 50 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 2, LittlerootTown_EventScript_LeftLabAfterDexUpgrade
# 51 "data/maps/LittlerootTown/scripts.pory"
	end
# 52 "data/maps/LittlerootTown/scripts.pory"

# 53 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_LeftLabAfterDexUpgrade::
# 54 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 3
# 55 "data/maps/LittlerootTown/scripts.pory"
	return
# 56 "data/maps/LittlerootTown/scripts.pory"

# 57 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_HideMapNamePopup::
# 58 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_MAP_NAME_POPUP
# 59 "data/maps/LittlerootTown/scripts.pory"
	return
# 60 "data/maps/LittlerootTown/scripts.pory"

# 61 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetRivalLeftForRoute103::
# 62 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_RIVAL_LEFT_FOR_ROUTE103
# 63 "data/maps/LittlerootTown/scripts.pory"
	return
# 64 "data/maps/LittlerootTown/scripts.pory"

# 65 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MoveRivalFromOldale::
# 66 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_OLDALE_RIVAL_STATE, 2
# 67 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_OLDALE_TOWN_RIVAL
# 68 "data/maps/LittlerootTown/scripts.pory"
	return
# 69 "data/maps/LittlerootTown/scripts.pory"

# 70 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetExitedHouseAfterLatiSSTicketEvent::
# 71 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_MAY, 5
# 72 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_BRENDAN, 5
# 73 "data/maps/LittlerootTown/scripts.pory"
	return
# 74 "data/maps/LittlerootTown/scripts.pory"

# 75 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MoveMomToMaysDoor::
# 76 "data/maps/LittlerootTown/scripts.pory"
	setobjectxyperm LOCALID_LITTLEROOT_MOM, 14, 8
# 77 "data/maps/LittlerootTown/scripts.pory"
	return
# 78 "data/maps/LittlerootTown/scripts.pory"

# 79 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetTwinPos::
# 80 "data/maps/LittlerootTown/scripts.pory"
	goto_if_eq VAR_LITTLEROOT_TOWN_STATE, 0, LittlerootTown_EventScript_SetTwinGuardingRoutePos
# 81 "data/maps/LittlerootTown/scripts.pory"
	setobjectxyperm LOCALID_LITTLEROOT_TWIN, 10, 1
# 82 "data/maps/LittlerootTown/scripts.pory"
	setobjectmovementtype LOCALID_LITTLEROOT_TWIN, MOVEMENT_TYPE_FACE_UP
# 83 "data/maps/LittlerootTown/scripts.pory"
	return
# 84 "data/maps/LittlerootTown/scripts.pory"

# 85 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetTwinGuardingRoutePos::
# 86 "data/maps/LittlerootTown/scripts.pory"
	setobjectxyperm LOCALID_LITTLEROOT_TWIN, 7, 2
# 87 "data/maps/LittlerootTown/scripts.pory"
	setobjectmovementtype LOCALID_LITTLEROOT_TWIN, MOVEMENT_TYPE_FACE_DOWN
# 88 "data/maps/LittlerootTown/scripts.pory"
	return
# 89 "data/maps/LittlerootTown/scripts.pory"

# 90 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetMomStandingInFrontOfDoorPos::
# 91 "data/maps/LittlerootTown/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MOM_OUTSIDE
# 92 "data/maps/LittlerootTown/scripts.pory"
	setobjectmovementtype LOCALID_LITTLEROOT_MOM, MOVEMENT_TYPE_FACE_DOWN
# 93 "data/maps/LittlerootTown/scripts.pory"
	checkplayergender
# 94 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, MALE, LittlerootTown_EventScript_SetMomInFrontOfDoorMale
# 95 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_EventScript_SetMomInFrontOfDoorFemale
# 96 "data/maps/LittlerootTown/scripts.pory"
	return
# 97 "data/maps/LittlerootTown/scripts.pory"

# 98 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetMomInFrontOfDoorMale::
# 99 "data/maps/LittlerootTown/scripts.pory"
	setobjectxyperm LOCALID_LITTLEROOT_MOM, 5, 9
# 100 "data/maps/LittlerootTown/scripts.pory"
	return
# 101 "data/maps/LittlerootTown/scripts.pory"

# 102 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetMomInFrontOfDoorFemale::
# 103 "data/maps/LittlerootTown/scripts.pory"
	setobjectxyperm LOCALID_LITTLEROOT_MOM, 14, 9
# 104 "data/maps/LittlerootTown/scripts.pory"
	return
# 105 "data/maps/LittlerootTown/scripts.pory"

# 106 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_OnFrame:
# 107 "data/maps/LittlerootTown/scripts.pory"
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 1, LittlerootTown_EventScript_StepOffTruckMale
# 108 "data/maps/LittlerootTown/scripts.pory"
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 2, LittlerootTown_EventScript_StepOffTruckFemale
# 109 "data/maps/LittlerootTown/scripts.pory"
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 1, LittlerootTown_EventScript_BeginDexUpgradeScene
# 110 "data/maps/LittlerootTown/scripts.pory"
	.2byte 0
# 111 "data/maps/LittlerootTown/scripts.pory"

# 112 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_StepOffTruckMale::
# 113 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 114 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8004, 5
# 115 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8005, 8
# 116 "data/maps/LittlerootTown/scripts.pory"
	call LittlerootTown_EventScript_GoInsideWithMom
# 117 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_TRUCK
# 118 "data/maps/LittlerootTown/scripts.pory"
	warpsilent MAP_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F, 8, 8
# 119 "data/maps/LittlerootTown/scripts.pory"
	waitstate
# 120 "data/maps/LittlerootTown/scripts.pory"
	releaseall
# 121 "data/maps/LittlerootTown/scripts.pory"
	end
# 122 "data/maps/LittlerootTown/scripts.pory"

# 123 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_StepOffTruckFemale::
# 124 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 125 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8004, 14
# 126 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8005, 8
# 127 "data/maps/LittlerootTown/scripts.pory"
	call LittlerootTown_EventScript_GoInsideWithMom
# 128 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_TRUCK
# 129 "data/maps/LittlerootTown/scripts.pory"
	warpsilent MAP_LITTLEROOT_TOWN_MAYS_HOUSE_1F, 2, 8
# 130 "data/maps/LittlerootTown/scripts.pory"
	waitstate
# 131 "data/maps/LittlerootTown/scripts.pory"
	releaseall
# 132 "data/maps/LittlerootTown/scripts.pory"
	end
# 133 "data/maps/LittlerootTown/scripts.pory"

# 134 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_GoInsideWithMom::
# 135 "data/maps/LittlerootTown/scripts.pory"
	delay 15
# 136 "data/maps/LittlerootTown/scripts.pory"
	playse SE_LEDGE
# 137 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_PLAYER, LittlerootTown_Movement_PlayerStepOffTruck
# 138 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 139 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8004, VAR_0x8005
# 140 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 141 "data/maps/LittlerootTown/scripts.pory"
	addobject LOCALID_LITTLEROOT_MOM
# 142 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomExitHouse
# 143 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 144 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8004, VAR_0x8005
# 145 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 146 "data/maps/LittlerootTown/scripts.pory"
	delay 10
# 147 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomApproachPlayerAtTruck
# 148 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 149 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_OurNewHomeLetsGoInside, MSGBOX_DEFAULT
# 150 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 151 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomApproachDoor
# 152 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_PLAYER, LittlerootTown_Movement_PlayerApproachDoor
# 153 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 154 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8004, VAR_0x8005
# 155 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 156 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomEnterHouse
# 157 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_PLAYER, LittlerootTown_Movement_PlayerEnterHouse
# 158 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 159 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MOM_OUTSIDE
# 160 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_INTRO_STATE, 3
# 161 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat LOCALID_PLAYER, 0
# 162 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8004, VAR_0x8005
# 163 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 164 "data/maps/LittlerootTown/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_FAT_MAN
# 165 "data/maps/LittlerootTown/scripts.pory"
	clearflag FLAG_HIDE_MAP_NAME_POPUP
# 166 "data/maps/LittlerootTown/scripts.pory"
	return
# 167 "data/maps/LittlerootTown/scripts.pory"

# 168 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomExitHouse:
# 169 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 170 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 171 "data/maps/LittlerootTown/scripts.pory"

# 172 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerAtTruck:
# 173 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 174 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_left
# 175 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 176 "data/maps/LittlerootTown/scripts.pory"

# 177 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachDoor:
# 178 "data/maps/LittlerootTown/scripts.pory"
	delay_16
# 179 "data/maps/LittlerootTown/scripts.pory"
	delay_8
# 180 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 181 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 182 "data/maps/LittlerootTown/scripts.pory"

# 183 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomEnterHouse:
# 184 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 185 "data/maps/LittlerootTown/scripts.pory"
	set_invisible
# 186 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 187 "data/maps/LittlerootTown/scripts.pory"

# 188 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_PlayerApproachDoor:
# 189 "data/maps/LittlerootTown/scripts.pory"
	delay_16
# 190 "data/maps/LittlerootTown/scripts.pory"
	delay_8
# 191 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 192 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
# 193 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 194 "data/maps/LittlerootTown/scripts.pory"

# 195 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_PlayerEnterHouse:
# 196 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 197 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 198 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 199 "data/maps/LittlerootTown/scripts.pory"

# 200 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_PlayerStepOffTruck:
# 201 "data/maps/LittlerootTown/scripts.pory"
	jump_right
# 202 "data/maps/LittlerootTown/scripts.pory"
	delay_16
# 203 "data/maps/LittlerootTown/scripts.pory"
	delay_16
# 204 "data/maps/LittlerootTown/scripts.pory"
	delay_16
# 205 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 206 "data/maps/LittlerootTown/scripts.pory"

# 207 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_BeginDexUpgradeScene::
# 208 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 209 "data/maps/LittlerootTown/scripts.pory"
	playse SE_PIN
# 210 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_BIRCH, Common_Movement_ExclamationMark
# 211 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 212 "data/maps/LittlerootTown/scripts.pory"
	delay 80
# 213 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_BirchSomethingToShowYouAtLab, MSGBOX_DEFAULT
# 214 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 215 "data/maps/LittlerootTown/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_RIVAL
# 216 "data/maps/LittlerootTown/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCH
# 217 "data/maps/LittlerootTown/scripts.pory"
	delay 20
# 218 "data/maps/LittlerootTown/scripts.pory"
	clearflag FLAG_HIDE_MAP_NAME_POPUP
# 219 "data/maps/LittlerootTown/scripts.pory"
	warp MAP_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB, 6, 5
# 220 "data/maps/LittlerootTown/scripts.pory"
	waitstate
# 221 "data/maps/LittlerootTown/scripts.pory"
	releaseall
# 222 "data/maps/LittlerootTown/scripts.pory"
	end
# 223 "data/maps/LittlerootTown/scripts.pory"

# 224 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_OnWarp:
# 225 "data/maps/LittlerootTown/scripts.pory"
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 1, LittlerootTown_EventScript_SetRivalBirchPosForDexUpgrade
# 226 "data/maps/LittlerootTown/scripts.pory"
	.2byte 0
# 227 "data/maps/LittlerootTown/scripts.pory"

# 228 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetRivalBirchPosForDexUpgrade::
# 229 "data/maps/LittlerootTown/scripts.pory"
	addobject LOCALID_LITTLEROOT_BIRCH
# 230 "data/maps/LittlerootTown/scripts.pory"
	addobject LOCALID_LITTLEROOT_RIVAL
# 231 "data/maps/LittlerootTown/scripts.pory"
	checkplayergender
# 232 "data/maps/LittlerootTown/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, LittlerootTown_EventScript_SetRivalBirchPosForDexUpgradeMale
# 233 "data/maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_SetRivalBirchPosForDexUpgradeFemale
# 234 "data/maps/LittlerootTown/scripts.pory"
	end
# 235 "data/maps/LittlerootTown/scripts.pory"

# 236 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetRivalBirchPosForDexUpgradeMale::
# 237 "data/maps/LittlerootTown/scripts.pory"
	setobjectxy LOCALID_LITTLEROOT_RIVAL, 6, 10
# 238 "data/maps/LittlerootTown/scripts.pory"
	setobjectxy LOCALID_LITTLEROOT_BIRCH, 5, 10
# 239 "data/maps/LittlerootTown/scripts.pory"
	end
# 240 "data/maps/LittlerootTown/scripts.pory"

# 241 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetRivalBirchPosForDexUpgradeFemale::
# 242 "data/maps/LittlerootTown/scripts.pory"
	setobjectxy LOCALID_LITTLEROOT_RIVAL, 13, 10
# 243 "data/maps/LittlerootTown/scripts.pory"
	setobjectxy LOCALID_LITTLEROOT_BIRCH, 14, 10
# 244 "data/maps/LittlerootTown/scripts.pory"
	end
# 245 "data/maps/LittlerootTown/scripts.pory"

# 246 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_FatMan::
# 247 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_CanUsePCToStoreItems, MSGBOX_NPC
# 248 "data/maps/LittlerootTown/scripts.pory"
	end
# 249 "data/maps/LittlerootTown/scripts.pory"

# 250 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_Boy::
# 251 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_BirchSpendsDaysInLab, MSGBOX_NPC
# 252 "data/maps/LittlerootTown/scripts.pory"
	end
# 253 "data/maps/LittlerootTown/scripts.pory"

# 254 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_Twin::
# 255 "data/maps/LittlerootTown/scripts.pory"
	lock
# 256 "data/maps/LittlerootTown/scripts.pory"
	faceplayer
# 257 "data/maps/LittlerootTown/scripts.pory"
	goto_if_set FLAG_ADVENTURE_STARTED, LittlerootTown_EventScript_GoodLuck
# 258 "data/maps/LittlerootTown/scripts.pory"
	goto_if_set FLAG_RESCUED_BIRCH, LittlerootTown_EventScript_YouSavedBirch
# 259 "data/maps/LittlerootTown/scripts.pory"
	goto_if_ne VAR_LITTLEROOT_TOWN_STATE, 0, LittlerootTown_EventScript_GoSaveBirch
# 260 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_IfYouGoInGrassPokemonWillJumpOut, MSGBOX_DEFAULT
# 261 "data/maps/LittlerootTown/scripts.pory"
	release
# 262 "data/maps/LittlerootTown/scripts.pory"
	end
# 263 "data/maps/LittlerootTown/scripts.pory"

# 264 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_GoSaveBirch::
# 265 "data/maps/LittlerootTown/scripts.pory"
	special GetPlayerBigGuyGirlString
# 266 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_CanYouGoSeeWhatsHappening, MSGBOX_DEFAULT
# 267 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 268 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_TWIN, Common_Movement_FaceOriginalDirection
# 269 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 270 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_TOWN_STATE, 2
# 271 "data/maps/LittlerootTown/scripts.pory"
	release
# 272 "data/maps/LittlerootTown/scripts.pory"
	end
# 273 "data/maps/LittlerootTown/scripts.pory"

# 274 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_YouSavedBirch::
# 275 "data/maps/LittlerootTown/scripts.pory"
	special GetPlayerBigGuyGirlString
# 276 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_YouSavedBirch, MSGBOX_DEFAULT
# 277 "data/maps/LittlerootTown/scripts.pory"
	release
# 278 "data/maps/LittlerootTown/scripts.pory"
	end
# 279 "data/maps/LittlerootTown/scripts.pory"

# 280 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_GoodLuck::
# 281 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_GoodLuckCatchingPokemon, MSGBOX_DEFAULT
# 282 "data/maps/LittlerootTown/scripts.pory"
	release
# 283 "data/maps/LittlerootTown/scripts.pory"
	end
# 284 "data/maps/LittlerootTown/scripts.pory"

# 285 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_NeedPokemonTriggerLeft::
# 286 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 287 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_TWIN, LittlerootTown_Movement_TwinApproachPlayerLeft
# 288 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 289 "data/maps/LittlerootTown/scripts.pory"
	call LittlerootTown_EventScript_DangerousWithoutPokemon
# 290 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_TWIN, LittlerootTown_Movement_TwinReturnLeft
# 291 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 292 "data/maps/LittlerootTown/scripts.pory"
	releaseall
# 293 "data/maps/LittlerootTown/scripts.pory"
	end
# 294 "data/maps/LittlerootTown/scripts.pory"

# 295 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_DangerousWithoutPokemon::
# 296 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_IfYouGoInGrassPokemonWillJumpOut, MSGBOX_DEFAULT
# 297 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 298 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_TWIN, LittlerootTown_Movement_TwinPushPlayerFromRoute
# 299 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_PLAYER, LittlerootTown_Movement_PushPlayerBackFromRoute
# 300 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 301 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_DangerousIfYouDontHavePokemon, MSGBOX_DEFAULT
# 302 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 303 "data/maps/LittlerootTown/scripts.pory"
	return
# 304 "data/maps/LittlerootTown/scripts.pory"

# 305 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_TwinApproachPlayerLeft:
# 306 "data/maps/LittlerootTown/scripts.pory"
	face_right
# 307 "data/maps/LittlerootTown/scripts.pory"
	delay_8
# 308 "data/maps/LittlerootTown/scripts.pory"
	disable_jump_landing_ground_effect
# 309 "data/maps/LittlerootTown/scripts.pory"
	jump_in_place_right
# 310 "data/maps/LittlerootTown/scripts.pory"
	delay_8
# 311 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 312 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 313 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 314 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 315 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_up
# 316 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_up
# 317 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_left
# 318 "data/maps/LittlerootTown/scripts.pory"
	face_down
# 319 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 320 "data/maps/LittlerootTown/scripts.pory"

# 321 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_TwinPushPlayerFromRoute:
# 322 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 323 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 324 "data/maps/LittlerootTown/scripts.pory"

# 325 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_TwinReturnLeft:
# 326 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 327 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 328 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 329 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 330 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 331 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 332 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 333 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 334 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_down
# 335 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 336 "data/maps/LittlerootTown/scripts.pory"

# 337 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_PushPlayerBackFromRoute:
# 338 "data/maps/LittlerootTown/scripts.pory"
	lock_facing_direction
# 339 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 340 "data/maps/LittlerootTown/scripts.pory"
	unlock_facing_direction
# 341 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 342 "data/maps/LittlerootTown/scripts.pory"

# 343 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_NeedPokemonTriggerRight::
# 344 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 345 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_TWIN, LittlerootTown_Movement_TwinApproachPlayerRight
# 346 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 347 "data/maps/LittlerootTown/scripts.pory"
	call LittlerootTown_EventScript_DangerousWithoutPokemon
# 348 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_TWIN, LittlerootTown_Movement_TwinReturnRight
# 349 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 350 "data/maps/LittlerootTown/scripts.pory"
	releaseall
# 351 "data/maps/LittlerootTown/scripts.pory"
	end
# 352 "data/maps/LittlerootTown/scripts.pory"

# 353 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_TwinApproachPlayerRight:
# 354 "data/maps/LittlerootTown/scripts.pory"
	face_right
# 355 "data/maps/LittlerootTown/scripts.pory"
	delay_8
# 356 "data/maps/LittlerootTown/scripts.pory"
	disable_jump_landing_ground_effect
# 357 "data/maps/LittlerootTown/scripts.pory"
	jump_in_place_right
# 358 "data/maps/LittlerootTown/scripts.pory"
	delay_8
# 359 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 360 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 361 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 362 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_up
# 363 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_up
# 364 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 365 "data/maps/LittlerootTown/scripts.pory"
	face_down
# 366 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 367 "data/maps/LittlerootTown/scripts.pory"

# 368 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_TwinReturnRight:
# 369 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 370 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 371 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 372 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 373 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 374 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_down
# 375 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 376 "data/maps/LittlerootTown/scripts.pory"

# 377 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_GoSaveBirchTrigger::
# 378 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 379 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_TWIN, Common_Movement_WalkInPlaceFasterRight
# 380 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 381 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 382 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 383 "data/maps/LittlerootTown/scripts.pory"
	special GetPlayerBigGuyGirlString
# 384 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_CanYouGoSeeWhatsHappening, MSGBOX_DEFAULT
# 385 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 386 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_TWIN, Common_Movement_FaceOriginalDirection
# 387 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 388 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_TOWN_STATE, 2
# 389 "data/maps/LittlerootTown/scripts.pory"
	releaseall
# 390 "data/maps/LittlerootTown/scripts.pory"
	end
# 391 "data/maps/LittlerootTown/scripts.pory"

# 392 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_TownSign::
# 393 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_TownSign, MSGBOX_SIGN
# 394 "data/maps/LittlerootTown/scripts.pory"
	end
# 395 "data/maps/LittlerootTown/scripts.pory"

# 396 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_BirchsLabSign::
# 397 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_ProfBirchsLab, MSGBOX_SIGN
# 398 "data/maps/LittlerootTown/scripts.pory"
	end
# 399 "data/maps/LittlerootTown/scripts.pory"

# 400 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_BrendansHouseSign::
# 401 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 402 "data/maps/LittlerootTown/scripts.pory"
	checkplayergender
# 403 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, MALE, LittlerootTown_EventScript_PlayersHouseSignMale
# 404 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_EventScript_BirchsHouseSignFemale
# 405 "data/maps/LittlerootTown/scripts.pory"
	releaseall
# 406 "data/maps/LittlerootTown/scripts.pory"
	end
# 407 "data/maps/LittlerootTown/scripts.pory"

# 408 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_PlayersHouseSignMale::
# 409 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_PlayersHouse, MSGBOX_DEFAULT
# 410 "data/maps/LittlerootTown/scripts.pory"
	return
# 411 "data/maps/LittlerootTown/scripts.pory"

# 412 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_BirchsHouseSignFemale::
# 413 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_ProfBirchsHouse, MSGBOX_DEFAULT
# 414 "data/maps/LittlerootTown/scripts.pory"
	return
# 415 "data/maps/LittlerootTown/scripts.pory"

# 416 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MaysHouseSign::
# 417 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 418 "data/maps/LittlerootTown/scripts.pory"
	checkplayergender
# 419 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, MALE, LittlerootTown_EventScript_BirchsHouseSignMale
# 420 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_EventScript_PlayersHouseSignFemale
# 421 "data/maps/LittlerootTown/scripts.pory"
	releaseall
# 422 "data/maps/LittlerootTown/scripts.pory"
	end
# 423 "data/maps/LittlerootTown/scripts.pory"

# 424 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_BirchsHouseSignMale::
# 425 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_ProfBirchsHouse, MSGBOX_DEFAULT
# 426 "data/maps/LittlerootTown/scripts.pory"
	return
# 427 "data/maps/LittlerootTown/scripts.pory"

# 428 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_PlayersHouseSignFemale::
# 429 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_PlayersHouse, MSGBOX_DEFAULT
# 430 "data/maps/LittlerootTown/scripts.pory"
	return
# 431 "data/maps/LittlerootTown/scripts.pory"

# 432 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_GiveRunningShoesTrigger0::
# 433 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 434 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8008, 0
# 435 "data/maps/LittlerootTown/scripts.pory"
	setobjectxy LOCALID_LITTLEROOT_MOM, 10, 9
# 436 "data/maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
# 437 "data/maps/LittlerootTown/scripts.pory"
	end
# 438 "data/maps/LittlerootTown/scripts.pory"

# 439 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_GiveRunningShoesTrigger1::
# 440 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 441 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8008, 1
# 442 "data/maps/LittlerootTown/scripts.pory"
	setobjectxy LOCALID_LITTLEROOT_MOM, 11, 9
# 443 "data/maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
# 444 "data/maps/LittlerootTown/scripts.pory"
	end
# 445 "data/maps/LittlerootTown/scripts.pory"

# 446 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_GiveRunningShoesTrigger2::
# 447 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 448 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8008, 2
# 449 "data/maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
# 450 "data/maps/LittlerootTown/scripts.pory"
	end
# 451 "data/maps/LittlerootTown/scripts.pory"

# 452 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_GiveRunningShoesTrigger3::
# 453 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 454 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8008, 3
# 455 "data/maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
# 456 "data/maps/LittlerootTown/scripts.pory"
	end
# 457 "data/maps/LittlerootTown/scripts.pory"

# 458 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_GiveRunningShoesTrigger4::
# 459 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 460 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8008, 4
# 461 "data/maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
# 462 "data/maps/LittlerootTown/scripts.pory"
	end
# 463 "data/maps/LittlerootTown/scripts.pory"

# 464 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_GiveRunningShoesTrigger5::
# 465 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 466 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8008, 5
# 467 "data/maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
# 468 "data/maps/LittlerootTown/scripts.pory"
	end
# 469 "data/maps/LittlerootTown/scripts.pory"

# 470 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_GiveRunningShoesTrigger::
# 471 "data/maps/LittlerootTown/scripts.pory"
	checkplayergender
# 472 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, MALE, LittlerootTown_EventScript_MomNoticePlayerMale
# 473 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_EventScript_MomNoticePlayerFemale
# 474 "data/maps/LittlerootTown/scripts.pory"
	checkplayergender
# 475 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, MALE, LittlerootTown_EventScript_SetHomeDoorCoordsMale
# 476 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_EventScript_SetHomeDoorCoordsFemale
# 477 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_WaitPlayer, MSGBOX_DEFAULT
# 478 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 479 "data/maps/LittlerootTown/scripts.pory"
	checkplayergender
# 480 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, MALE, LittlerootTown_EventScript_MomApproachPlayerMale
# 481 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_EventScript_MomApproachPlayerFemale
# 482 "data/maps/LittlerootTown/scripts.pory"
	call LittlerootTown_EventScript_GiveRunningShoes
# 483 "data/maps/LittlerootTown/scripts.pory"
	checkplayergender
# 484 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, MALE, LittlerootTown_EventScript_MomReturnHomeMale
# 485 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_EventScript_MomReturnHomeFemale
# 486 "data/maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_SetReceivedRunningShoes
# 487 "data/maps/LittlerootTown/scripts.pory"
	end
# 488 "data/maps/LittlerootTown/scripts.pory"

# 489 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetHomeDoorCoordsMale::
# 490 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8009, 5
# 491 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x800A, 8
# 492 "data/maps/LittlerootTown/scripts.pory"
	return
# 493 "data/maps/LittlerootTown/scripts.pory"

# 494 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetHomeDoorCoordsFemale::
# 495 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8009, 14
# 496 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x800A, 8
# 497 "data/maps/LittlerootTown/scripts.pory"
	return
# 498 "data/maps/LittlerootTown/scripts.pory"

# 499 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomNoticePlayerMale::
# 500 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_MOM, Common_Movement_WalkInPlaceFasterRight
# 501 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 502 "data/maps/LittlerootTown/scripts.pory"
	return
# 503 "data/maps/LittlerootTown/scripts.pory"

# 504 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomNoticePlayerFemale::
# 505 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_MOM, Common_Movement_WalkInPlaceFasterLeft
# 506 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 507 "data/maps/LittlerootTown/scripts.pory"
	return
# 508 "data/maps/LittlerootTown/scripts.pory"

# 509 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayerMale::
# 510 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 0, LittlerootTown_EventScript_MomApproachPlayer0
# 511 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 1, LittlerootTown_EventScript_MomApproachPlayer1
# 512 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 2, LittlerootTown_EventScript_MomApproachPlayerMale2
# 513 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 3, LittlerootTown_EventScript_MomApproachPlayerMale3
# 514 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 4, LittlerootTown_EventScript_MomApproachPlayerMale4
# 515 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 5, LittlerootTown_EventScript_MomApproachPlayerMale5
# 516 "data/maps/LittlerootTown/scripts.pory"
	return
# 517 "data/maps/LittlerootTown/scripts.pory"

# 518 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayerFemale::
# 519 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 0, LittlerootTown_EventScript_MomApproachPlayer0
# 520 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 1, LittlerootTown_EventScript_MomApproachPlayer1
# 521 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 2, LittlerootTown_EventScript_MomApproachPlayerFemale2
# 522 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 3, LittlerootTown_EventScript_MomApproachPlayerFemale3
# 523 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 4, LittlerootTown_EventScript_MomApproachPlayerFemale4
# 524 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 5, LittlerootTown_EventScript_MomApproachPlayerFemale5
# 525 "data/maps/LittlerootTown/scripts.pory"
	return
# 526 "data/maps/LittlerootTown/scripts.pory"

# 527 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayer0::
# 528 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 529 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 530 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomApproachPlayer0
# 531 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 532 "data/maps/LittlerootTown/scripts.pory"
	return
# 533 "data/maps/LittlerootTown/scripts.pory"

# 534 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayer1::
# 535 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 536 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 537 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomApproachPlayer1
# 538 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 539 "data/maps/LittlerootTown/scripts.pory"
	return
# 540 "data/maps/LittlerootTown/scripts.pory"

# 541 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayerMale2::
# 542 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 543 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 544 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomApproachPlayerMale2
# 545 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 546 "data/maps/LittlerootTown/scripts.pory"
	return
# 547 "data/maps/LittlerootTown/scripts.pory"

# 548 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayerMale3::
# 549 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 550 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 551 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomApproachPlayerMale3
# 552 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 553 "data/maps/LittlerootTown/scripts.pory"
	return
# 554 "data/maps/LittlerootTown/scripts.pory"

# 555 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayerMale4::
# 556 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 557 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 558 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomApproachPlayerMale4
# 559 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 560 "data/maps/LittlerootTown/scripts.pory"
	return
# 561 "data/maps/LittlerootTown/scripts.pory"

# 562 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayerMale5::
# 563 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 564 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 565 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomApproachPlayerMale5
# 566 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 567 "data/maps/LittlerootTown/scripts.pory"
	return
# 568 "data/maps/LittlerootTown/scripts.pory"

# 569 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayerFemale2::
# 570 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 571 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 572 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomApproachPlayerFemale2
# 573 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 574 "data/maps/LittlerootTown/scripts.pory"
	return
# 575 "data/maps/LittlerootTown/scripts.pory"

# 576 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayerFemale3::
# 577 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 578 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 579 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomApproachPlayerFemale3
# 580 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 581 "data/maps/LittlerootTown/scripts.pory"
	return
# 582 "data/maps/LittlerootTown/scripts.pory"

# 583 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayerFemale4::
# 584 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 585 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 586 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomApproachPlayerFemale4
# 587 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 588 "data/maps/LittlerootTown/scripts.pory"
	return
# 589 "data/maps/LittlerootTown/scripts.pory"

# 590 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayerFemale5::
# 591 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 592 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 593 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomApproachPlayerFemale5
# 594 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 595 "data/maps/LittlerootTown/scripts.pory"
	return
# 596 "data/maps/LittlerootTown/scripts.pory"

# 597 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHomeMale::
# 598 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 0, LittlerootTown_EventScript_MomReturnHome0
# 599 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 1, LittlerootTown_EventScript_MomReturnHome1
# 600 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 2, LittlerootTown_EventScript_MomReturnHomeMale2
# 601 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 3, LittlerootTown_EventScript_MomReturnHomeMale3
# 602 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 4, LittlerootTown_EventScript_MomReturnHomeMale4
# 603 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 5, LittlerootTown_EventScript_MomReturnHomeMale5
# 604 "data/maps/LittlerootTown/scripts.pory"
	return
# 605 "data/maps/LittlerootTown/scripts.pory"

# 606 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHomeFemale::
# 607 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 0, LittlerootTown_EventScript_MomReturnHome0
# 608 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 1, LittlerootTown_EventScript_MomReturnHome1
# 609 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 2, LittlerootTown_EventScript_MomReturnHomeFemale2
# 610 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 3, LittlerootTown_EventScript_MomReturnHomeFemale3
# 611 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 4, LittlerootTown_EventScript_MomReturnHomeFemale4
# 612 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 5, LittlerootTown_EventScript_MomReturnHomeFemale5
# 613 "data/maps/LittlerootTown/scripts.pory"
	return
# 614 "data/maps/LittlerootTown/scripts.pory"

# 615 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHome0::
# 616 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomReturnHome0
# 617 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 618 "data/maps/LittlerootTown/scripts.pory"
	return
# 619 "data/maps/LittlerootTown/scripts.pory"

# 620 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHome1::
# 621 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomReturnHome1
# 622 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 623 "data/maps/LittlerootTown/scripts.pory"
	return
# 624 "data/maps/LittlerootTown/scripts.pory"

# 625 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHomeMale2::
# 626 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomReturnHomeMale2
# 627 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 628 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 629 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 630 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomExitThroughDoor
# 631 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 632 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat LOCALID_LITTLEROOT_MOM, MAP_LITTLEROOT_TOWN
# 633 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 634 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 635 "data/maps/LittlerootTown/scripts.pory"
	return
# 636 "data/maps/LittlerootTown/scripts.pory"

# 637 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHomeMale3::
# 638 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomReturnHomeMale3
# 639 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 640 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 641 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 642 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomExitThroughDoor
# 643 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 644 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat LOCALID_LITTLEROOT_MOM, MAP_LITTLEROOT_TOWN
# 645 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 646 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 647 "data/maps/LittlerootTown/scripts.pory"
	return
# 648 "data/maps/LittlerootTown/scripts.pory"

# 649 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHomeMale4::
# 650 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomReturnHomeMale4
# 651 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 652 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 653 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 654 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomExitThroughDoor
# 655 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 656 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat LOCALID_LITTLEROOT_MOM, MAP_LITTLEROOT_TOWN
# 657 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 658 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 659 "data/maps/LittlerootTown/scripts.pory"
	return
# 660 "data/maps/LittlerootTown/scripts.pory"

# 661 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHomeMale5::
# 662 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomReturnHomeMale5
# 663 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 664 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 665 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 666 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomExitThroughDoor
# 667 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 668 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat LOCALID_LITTLEROOT_MOM, MAP_LITTLEROOT_TOWN
# 669 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 670 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 671 "data/maps/LittlerootTown/scripts.pory"
	return
# 672 "data/maps/LittlerootTown/scripts.pory"

# 673 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHomeFemale2::
# 674 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomReturnHomeFemale2
# 675 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 676 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 677 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 678 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomExitThroughDoor
# 679 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 680 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat LOCALID_LITTLEROOT_MOM, MAP_LITTLEROOT_TOWN
# 681 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 682 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 683 "data/maps/LittlerootTown/scripts.pory"
	return
# 684 "data/maps/LittlerootTown/scripts.pory"

# 685 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHomeFemale3::
# 686 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomReturnHomeFemale3
# 687 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 688 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 689 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 690 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomExitThroughDoor
# 691 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 692 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat LOCALID_LITTLEROOT_MOM, MAP_LITTLEROOT_TOWN
# 693 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 694 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 695 "data/maps/LittlerootTown/scripts.pory"
	return
# 696 "data/maps/LittlerootTown/scripts.pory"

# 697 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHomeFemale4::
# 698 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomReturnHomeFemale4
# 699 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 700 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 701 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 702 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomExitThroughDoor
# 703 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 704 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat LOCALID_LITTLEROOT_MOM, MAP_LITTLEROOT_TOWN
# 705 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 706 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 707 "data/maps/LittlerootTown/scripts.pory"
	return
# 708 "data/maps/LittlerootTown/scripts.pory"

# 709 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHomeFemale5::
# 710 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomReturnHomeFemale5
# 711 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 712 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 713 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 714 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomExitThroughDoor
# 715 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 716 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat LOCALID_LITTLEROOT_MOM, MAP_LITTLEROOT_TOWN
# 717 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 718 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 719 "data/maps/LittlerootTown/scripts.pory"
	return
# 720 "data/maps/LittlerootTown/scripts.pory"

# 721 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayer0:
# 722 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 723 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 724 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 725 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 726 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 727 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 728 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 729 "data/maps/LittlerootTown/scripts.pory"

# 730 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayer1:
# 731 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 732 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 733 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 734 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 735 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 736 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 737 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 738 "data/maps/LittlerootTown/scripts.pory"

# 739 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerMale2:
# 740 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 741 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 742 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 743 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 744 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 745 "data/maps/LittlerootTown/scripts.pory"

# 746 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerMale3:
# 747 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 748 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 749 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 750 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 751 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 752 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 753 "data/maps/LittlerootTown/scripts.pory"

# 754 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerMale4:
# 755 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 756 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 757 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 758 "data/maps/LittlerootTown/scripts.pory"

# 759 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerMale5:
# 760 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 761 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 762 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 763 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 764 "data/maps/LittlerootTown/scripts.pory"

# 765 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerFemale2:
# 766 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 767 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 768 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 769 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 770 "data/maps/LittlerootTown/scripts.pory"

# 771 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerFemale3:
# 772 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 773 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 774 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 775 "data/maps/LittlerootTown/scripts.pory"

# 776 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerFemale4:
# 777 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 778 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 779 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 780 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 781 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 782 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 783 "data/maps/LittlerootTown/scripts.pory"

# 784 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerFemale5:
# 785 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 786 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 787 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 788 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 789 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 790 "data/maps/LittlerootTown/scripts.pory"

# 791 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHome0:
# 792 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 793 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 794 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 795 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 796 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 797 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 798 "data/maps/LittlerootTown/scripts.pory"

# 799 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHome1:
# 800 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 801 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 802 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 803 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 804 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 805 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 806 "data/maps/LittlerootTown/scripts.pory"

# 807 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeMale2:
# 808 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 809 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 810 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 811 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 812 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
# 813 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 814 "data/maps/LittlerootTown/scripts.pory"

# 815 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeMale3:
# 816 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 817 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 818 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 819 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 820 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 821 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
# 822 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 823 "data/maps/LittlerootTown/scripts.pory"

# 824 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeMale4:
# 825 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 826 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 827 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
# 828 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 829 "data/maps/LittlerootTown/scripts.pory"

# 830 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeMale5:
# 831 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 832 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 833 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 834 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
# 835 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 836 "data/maps/LittlerootTown/scripts.pory"

# 837 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeFemale2:
# 838 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 839 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 840 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 841 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
# 842 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 843 "data/maps/LittlerootTown/scripts.pory"

# 844 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeFemale3:
# 845 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 846 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 847 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
# 848 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 849 "data/maps/LittlerootTown/scripts.pory"

# 850 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeFemale4:
# 851 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 852 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 853 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 854 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 855 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 856 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
# 857 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 858 "data/maps/LittlerootTown/scripts.pory"

# 859 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeFemale5:
# 860 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 861 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 862 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 863 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 864 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
# 865 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 866 "data/maps/LittlerootTown/scripts.pory"

# 867 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomExitThroughDoor:
# 868 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 869 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 870 "data/maps/LittlerootTown/scripts.pory"

# 871 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_Mom::
# 872 "data/maps/LittlerootTown/scripts.pory"
	lock
# 873 "data/maps/LittlerootTown/scripts.pory"
	faceplayer
# 874 "data/maps/LittlerootTown/scripts.pory"
	checkplayergender
# 875 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, MALE, LittlerootTown_EventScript_SetHomeDoorCoordsMale
# 876 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_EventScript_SetHomeDoorCoordsFemale
# 877 "data/maps/LittlerootTown/scripts.pory"
	call LittlerootTown_EventScript_GiveRunningShoes
# 878 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_MOM, Common_Movement_WalkInPlaceFasterUp
# 879 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 880 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 881 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 882 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomExitThroughDoor
# 883 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 884 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat LOCALID_LITTLEROOT_MOM, MAP_LITTLEROOT_TOWN
# 885 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 886 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 887 "data/maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_SetReceivedRunningShoes
# 888 "data/maps/LittlerootTown/scripts.pory"
	end
# 889 "data/maps/LittlerootTown/scripts.pory"

# 890 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetReceivedRunningShoes::
# 891 "data/maps/LittlerootTown/scripts.pory"
	removeobject LOCALID_LITTLEROOT_MOM
# 892 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_SYS_B_DASH
# 893 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_TOWN_STATE, 4
# 894 "data/maps/LittlerootTown/scripts.pory"
	release
# 895 "data/maps/LittlerootTown/scripts.pory"
	end
# 896 "data/maps/LittlerootTown/scripts.pory"

# 897 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_GiveRunningShoes::
# 898 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_WearTheseRunningShoes, MSGBOX_DEFAULT
# 899 "data/maps/LittlerootTown/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 900 "data/maps/LittlerootTown/scripts.pory"
	message LittlerootTown_Text_SwitchShoesWithRunningShoes
# 901 "data/maps/LittlerootTown/scripts.pory"
	waitfanfare
# 902 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_RECEIVED_RUNNING_SHOES
# 903 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_ExplainRunningShoes, MSGBOX_DEFAULT
# 904 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_ComeHomeIfAnythingHappens, MSGBOX_DEFAULT
# 905 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 906 "data/maps/LittlerootTown/scripts.pory"
	delay 30
# 907 "data/maps/LittlerootTown/scripts.pory"
	return
# 908 "data/maps/LittlerootTown/scripts.pory"

# 909 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_OurNewHomeLetsGoInside:
# 910 "data/maps/LittlerootTown/scripts.pory"
	.string "MOM: {PLAYER}, we're here, honey!\p"
# 911 "data/maps/LittlerootTown/scripts.pory"
	.string "It must be tiring riding with our things\n"
# 912 "data/maps/LittlerootTown/scripts.pory"
	.string "in the moving truck.\p"
# 913 "data/maps/LittlerootTown/scripts.pory"
	.string "Well, this is LITTLEROOT TOWN.\p"
# 914 "data/maps/LittlerootTown/scripts.pory"
	.string "How do you like it?\n"
# 915 "data/maps/LittlerootTown/scripts.pory"
	.string "This is our new home!\p"
# 916 "data/maps/LittlerootTown/scripts.pory"
	.string "It has a quaint feel, but it seems to be\n"
# 917 "data/maps/LittlerootTown/scripts.pory"
	.string "an easy place to live, don't you think?\p"
# 918 "data/maps/LittlerootTown/scripts.pory"
	.string "And, you get your own room, {PLAYER}!\n"
# 919 "data/maps/LittlerootTown/scripts.pory"
	.string "Let's go inside.$"
# 920 "data/maps/LittlerootTown/scripts.pory"

# 921 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_WaitPlayer:
# 922 "data/maps/LittlerootTown/scripts.pory"
	.string "MOM: Wait, {PLAYER}!$"
# 923 "data/maps/LittlerootTown/scripts.pory"

# 924 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_WearTheseRunningShoes:
# 925 "data/maps/LittlerootTown/scripts.pory"
	.string "MOM: {PLAYER}! {PLAYER}! Did you\n"
# 926 "data/maps/LittlerootTown/scripts.pory"
	.string "introduce yourself to PROF. BIRCH?\p"
# 927 "data/maps/LittlerootTown/scripts.pory"
	.string "Oh! What an adorable POKéMON!\n"
# 928 "data/maps/LittlerootTown/scripts.pory"
	.string "You got it from PROF. BIRCH. How nice!\p"
# 929 "data/maps/LittlerootTown/scripts.pory"
	.string "You're your father's child, all right.\n"
# 930 "data/maps/LittlerootTown/scripts.pory"
	.string "You look good together with POKéMON!\p"
# 931 "data/maps/LittlerootTown/scripts.pory"
	.string "Here, honey! If you're going out on an\n"
# 932 "data/maps/LittlerootTown/scripts.pory"
	.string "adventure, wear these RUNNING SHOES.\p"
# 933 "data/maps/LittlerootTown/scripts.pory"
	.string "They'll put a zip in your step!$"
# 934 "data/maps/LittlerootTown/scripts.pory"

# 935 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_SwitchShoesWithRunningShoes:
# 936 "data/maps/LittlerootTown/scripts.pory"
	.string "{PLAYER} switched shoes with the\n"
# 937 "data/maps/LittlerootTown/scripts.pory"
	.string "RUNNING SHOES.$"
# 938 "data/maps/LittlerootTown/scripts.pory"

# 939 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_ExplainRunningShoes:
# 940 "data/maps/LittlerootTown/scripts.pory"
	.string "MOM: {PLAYER}, those shoes came with\n"
# 941 "data/maps/LittlerootTown/scripts.pory"
	.string "instructions.\p"
# 942 "data/maps/LittlerootTown/scripts.pory"
	.string "“Press the B Button while wearing these\n"
# 943 "data/maps/LittlerootTown/scripts.pory"
	.string "RUNNING SHOES to run extra-fast!\p"
# 944 "data/maps/LittlerootTown/scripts.pory"
	.string "“Slip on these RUNNING SHOES and race\n"
# 945 "data/maps/LittlerootTown/scripts.pory"
	.string "in the great outdoors!”$"
# 946 "data/maps/LittlerootTown/scripts.pory"

# 947 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_ComeHomeIfAnythingHappens:
# 948 "data/maps/LittlerootTown/scripts.pory"
	.string "… … … … … … … …\n"
# 949 "data/maps/LittlerootTown/scripts.pory"
	.string "… … … … … … … …\p"
# 950 "data/maps/LittlerootTown/scripts.pory"
	.string "To think that you have your very own\n"
# 951 "data/maps/LittlerootTown/scripts.pory"
	.string "POKéMON now…\l"
# 952 "data/maps/LittlerootTown/scripts.pory"
	.string "Your father will be overjoyed.\p"
# 953 "data/maps/LittlerootTown/scripts.pory"
	.string "…But please be careful.\n"
# 954 "data/maps/LittlerootTown/scripts.pory"
	.string "If anything happens, you can come home.\p"
# 955 "data/maps/LittlerootTown/scripts.pory"
	.string "Go on, go get them, honey!$"
# 956 "data/maps/LittlerootTown/scripts.pory"

# 957 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_CanUsePCToStoreItems:
# 958 "data/maps/LittlerootTown/scripts.pory"
	.string "If you use a PC, you can store items\n"
# 959 "data/maps/LittlerootTown/scripts.pory"
	.string "and POKéMON.\p"
# 960 "data/maps/LittlerootTown/scripts.pory"
	.string "The power of science is staggering!$"
# 961 "data/maps/LittlerootTown/scripts.pory"

# 962 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_BirchSpendsDaysInLab:
# 963 "data/maps/LittlerootTown/scripts.pory"
	.string "PROF. BIRCH spends days in his LAB\n"
# 964 "data/maps/LittlerootTown/scripts.pory"
	.string "studying, then he'll suddenly go out in\l"
# 965 "data/maps/LittlerootTown/scripts.pory"
	.string "the wild to do more research…\p"
# 966 "data/maps/LittlerootTown/scripts.pory"
	.string "When does PROF. BIRCH spend time\n"
# 967 "data/maps/LittlerootTown/scripts.pory"
	.string "at home?$"
# 968 "data/maps/LittlerootTown/scripts.pory"

# 969 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_IfYouGoInGrassPokemonWillJumpOut:
# 970 "data/maps/LittlerootTown/scripts.pory"
	.string "Um, um, um!\p"
# 971 "data/maps/LittlerootTown/scripts.pory"
	.string "If you go outside and go in the grass,\n"
# 972 "data/maps/LittlerootTown/scripts.pory"
	.string "wild POKéMON will jump out!$"
# 973 "data/maps/LittlerootTown/scripts.pory"

# 974 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_DangerousIfYouDontHavePokemon:
# 975 "data/maps/LittlerootTown/scripts.pory"
	.string "It's dangerous if you don't have\n"
# 976 "data/maps/LittlerootTown/scripts.pory"
	.string "your own POKéMON.$"
# 977 "data/maps/LittlerootTown/scripts.pory"

# 978 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_CanYouGoSeeWhatsHappening:
# 979 "data/maps/LittlerootTown/scripts.pory"
	.string "Um, hi!\p"
# 980 "data/maps/LittlerootTown/scripts.pory"
	.string "There are scary POKéMON outside!\n"
# 981 "data/maps/LittlerootTown/scripts.pory"
	.string "I can hear their cries!\p"
# 982 "data/maps/LittlerootTown/scripts.pory"
	.string "I want to go see what's going on,\n"
# 983 "data/maps/LittlerootTown/scripts.pory"
	.string "but I don't have any POKéMON…\p"
# 984 "data/maps/LittlerootTown/scripts.pory"
	.string "Can you go see what's happening\n"
# 985 "data/maps/LittlerootTown/scripts.pory"
	.string "for me?$"
# 986 "data/maps/LittlerootTown/scripts.pory"

# 987 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_YouSavedBirch:
# 988 "data/maps/LittlerootTown/scripts.pory"
	.string "You saved PROF. BIRCH!\n"
# 989 "data/maps/LittlerootTown/scripts.pory"
	.string "I'm so glad!$"
# 990 "data/maps/LittlerootTown/scripts.pory"

# 991 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_GoodLuckCatchingPokemon:
# 992 "data/maps/LittlerootTown/scripts.pory"
	.string "Are you going to catch POKéMON?\n"
# 993 "data/maps/LittlerootTown/scripts.pory"
	.string "Good luck!$"
# 994 "data/maps/LittlerootTown/scripts.pory"

# 995 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_TownSign:
# 996 "data/maps/LittlerootTown/scripts.pory"
	.string "LITTLEROOT TOWN\n"
# 997 "data/maps/LittlerootTown/scripts.pory"
	.string "“A town that can't be shaded any hue.”$"
# 998 "data/maps/LittlerootTown/scripts.pory"

# 999 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_ProfBirchsLab:
# 1000 "data/maps/LittlerootTown/scripts.pory"
	.string "PROF. BIRCH'S POKéMON LAB$"
# 1001 "data/maps/LittlerootTown/scripts.pory"

# 1002 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_PlayersHouse:
# 1003 "data/maps/LittlerootTown/scripts.pory"
	.string "{PLAYER}'s HOUSE$"
# 1004 "data/maps/LittlerootTown/scripts.pory"

# 1005 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_ProfBirchsHouse:
# 1006 "data/maps/LittlerootTown/scripts.pory"
	.string "PROF. BIRCH'S HOUSE$"
# 1007 "data/maps/LittlerootTown/scripts.pory"

# 1008 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_BirchSomethingToShowYouAtLab:
# 1009 "data/maps/LittlerootTown/scripts.pory"
	.string "PROF. BIRCH: Well, well, {PLAYER}{KUN}!\n"
# 1010 "data/maps/LittlerootTown/scripts.pory"
	.string "That was good work out there!\p"
# 1011 "data/maps/LittlerootTown/scripts.pory"
	.string "I knew there was something special\n"
# 1012 "data/maps/LittlerootTown/scripts.pory"
	.string "about you when I first saw you,\l"
# 1013 "data/maps/LittlerootTown/scripts.pory"
	.string "but I never expected this.\p"
# 1014 "data/maps/LittlerootTown/scripts.pory"
	.string "Oh, yes. Do you still have the POKéDEX\n"
# 1015 "data/maps/LittlerootTown/scripts.pory"
	.string "I gave you?\p"
# 1016 "data/maps/LittlerootTown/scripts.pory"
	.string "I have something to show you.\n"
# 1017 "data/maps/LittlerootTown/scripts.pory"
	.string "Let's go to my LAB.$"

LittlerootTown_EventScript_Maxie::
# 1034 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 1035 "data/maps/LittlerootTown/scripts.pory"
	speakername Maxie
# 1036 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_EventScript_Maxie_Text_0
# 1037 "data/maps/LittlerootTown/scripts.pory"
	releaseall
	return


LittlerootTown_EventScript_Test::
# 1043 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 1044 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_EventScript_Test_Text_0
# 1045 "data/maps/LittlerootTown/scripts.pory"
	releaseall
	return


LittlerootTown_EventScript_Maxie_Text_0:
# 1036 "data/maps/LittlerootTown/scripts.pory"
	.string "Testing the speaker box.$"

LittlerootTown_EventScript_Test_Text_0:
# 1044 "data/maps/LittlerootTown/scripts.pory"
	.string "Test$"

Maxie::
# 1021 "data/maps/LittlerootTown/scripts.pory"
	.string "Prof. Maple$"

Unknown::
# 1025 "data/maps/LittlerootTown/scripts.pory"
	.string "???$"

Birch::
# 1029 "data/maps/LittlerootTown/scripts.pory"
	.string "Birch$"
