.set LOCALID_SSAQUA_1F_DOORSAILOR, 4
.set LOCALID_SSAQUA_1F_GRANDPA, 2

SSAqua_1F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SSAqua_1F_OnFrame
	.byte 0

SSAqua_1F_OnFrame::
	map_script_2 VAR_SSAQUA_STATE, 5, SSAqua_1F_EventScript_Arrived
	.2byte 0

SSAqua_1F_EventScript_Arrived::
	lock
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 10  @ num shakes
	setvar VAR_0x8007, 6  @ shake delay
	special ShakeCamera
	waitstate
	playse SE_DING_DONG
	msgbox SSAqua_1F_Text_Sailor1_InVermilion, MSGBOX_DEFAULT
	closemessage
	setvar VAR_SSAQUA_STATE, 6
	release
	end

SSAqua_1F_EventScript_DoorSailor::
	lock
	faceplayer
	goto_if_ge VAR_SSAQUA_STATE, 5, SSAqua_1F_EventScript_DoorSailorArrived
	msgbox SSAqua_1F_Text_Sailor1_ToVermilion, MSGBOX_NPC
	end

SSAqua_1F_EventScript_DoorSailorArrived::
	msgbox SSAqua_1F_Text_SailorDoorArrived, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, SSAqua_1F_EventScript_LeaveBoat
	closemessage
	release
	end

SSAqua_1F_EventScript_LeaveBoat::
	fadescreenswapbuffers FADE_TO_BLACK

	@Kanto FLAGHEAP
	setflag FLAG_HIDE_COPYCAT_CLEFAIRY_DOLL
	setflag FLAG_HIDE_CERULEAN_GYM_TRAINERS
	setflag FLAG_HIDE_CERULEAN_CAPE_ROCKET
	setflag FLAG_HIDE_CERULEAN_GYM_ROCKET
	setflag FLAG_HIDDEN_ITEM_MACHINE_PART
	setflag FLAG_HIDE_ROUTE25_MISTY
	setflag FLAG_HIDE_ROUTE25_EUSINE
	setflag FLAG_HIDE_ROUTE25_SUICUNE
	setflag FLAG_HIDE_CELADON_EUSINE
	setflag FLAG_HIDE_SEAFOAM_GYMGUY
	setflag FLAG_HIDE_VIRIDIAN_BLUE
	setflag FLAG_HIDE_ROUTE14_EUSINE
	setflag FLAG_HIDE_ROUTE14_SUICUNE
	
	clearflag FLAG_BADGE09_GET
	clearflag FLAG_BADGE10_GET
	clearflag FLAG_BADGE11_GET
	clearflag FLAG_BADGE12_GET
	clearflag FLAG_BADGE13_GET
	clearflag FLAG_BADGE14_GET
	clearflag FLAG_BADGE15_GET
	clearflag FLAG_BADGE16_GET
	clearflag FLAG_GOT_VERMILION_HP_UP
	clearflag FLAG_KANTO_RADIO_GOT
	clearflag FLAG_HIDE_VERMILION_SNORLAX
	clearflag FLAG_HIDE_FAN_CLUB_CLEFAIRY_DOLL
	clearflag FLAG_FOUND_BOTH_VERMILION_GYM_SWITCHES
	clearflag FLAG_RETURNED_MACHINE_PART
	clearflag FLAG_GOT_TM_PSYCHIC
	clearflag FLAG_GOT_HOENN_STARTER
	clearflag FLAG_GOT_UP_GRADE
	clearflag FLAG_GOT_CLEANSE_TAG
	clearflag FLAG_ROUTE25_GOT_NUGGET
	clearflag FLAG_HIDE_POWER_PLANT_ENGINEER
	clearflag FLAG_HIDE_ZAPDOS
	clearflag FLAG_HIDE_ARTICUNO
	clearflag FLAG_HIDE_MOLTRES
	clearflag FLAG_GOT_TM_REST
	clearflag FLAG_GOT_SUPER_ROD
	clearflag FLAG_HIDE_CINNABAR_BLUE
	clearflag FLAG_GOT_ROUTE2_NUGGET
	clearflag FLAG_GOT_VIRIDIAN_TM_SLUDGE_BOMB
	clearflag FLAG_GOT_ROUTE_14_AERIAL_ACE
	clearflag FLAG_HIDE_PEWTER_ROOT_FOSSIL
	clearflag FLAG_HIDE_PEWTER_CLAW_FOSSIL
	clearflag FLAG_HIDE_MTMOON_SILVER
	clearflag FLAG_GOT_TM_STEEL_WING
	clearflag FLAG_HIDE_CERULEANCAVE_GUARD
	clearflag FLAG_HIDE_MTSILVER_RED
	clearflag FLAG_HIDE_MEWTWO
	clearflag FLAG_HIDE_LATIAS
	clearflag FLAG_HIDE_LATIOS
	clearflag FLAG_HIDE_GROUDON
	clearflag FLAG_HIDE_KYOGRE
	clearflag FLAG_HIDE_RAYQUAZA
	clearflag FLAG_HIDE_SEAFOAM_BLAINE

	clearflag FLAG_HIDE_CELADON_FALKNER
	clearflag FLAG_HIDE_VIRIDIAN_BUGSY
	clearflag FLAG_HIDE_DEPTSTORE_WHITNEY
	clearflag FLAG_HIDE_BELLCHIME_MORTY
	clearflag FLAG_HIDE_CAFE_JASMINE
	clearflag FLAG_HIDE_LAKE_PRYCE
	clearflag FLAG_HIDE_DEN_CLAIR


	setvar VAR_KANTO_ROCKET_STORY_STATE, 0
	setvar VAR_BILLS_GRANDPA, 0


	setvar VAR_FAN_CLUB_CLEFAIRY, 0
	setvar VAR_FAN_CLUB_GUY, 0
	setvar VAR_CLEFAIRY_DOLL_STATE, 0
	setvar VAR_NUM_BADGES, 8
	setvar VAR_VERMILION_CITY_STATE, 1

	setvar VAR_KANTO_SAFARI_ZONE_PROGRESS, 0 
	clearflag FLAG_IN_KANTO_SAFARI_ZONE 
	clearflag FLAG_IS_KANTO_CHAMPION 
	setvar VAR_BAOBA_QUEST_STATE, 0 
	setvar VAR_CINNABAR_ISLAND_STATE, 0 
	setvar VAR_MT_SILVER_STATE, 0, 
	setvar VAR_PALLETTOWN_LABSTATE, 0 
	clearflag FLAG_HIDE_LEAGUE_BLACKBELT 
	
	setflag FLAG_HIDE_DOJO_FALKNER
	setflag FLAG_HIDE_DOJO_BUGSY
	setflag FLAG_HIDE_DOJO_WHITNEY
	setflag FLAG_HIDE_DOJO_MORTY
	setflag FLAG_HIDE_DOJO_CHUCK
	setflag FLAG_HIDE_DOJO_JASMINE
	setflag FLAG_HIDE_DOJO_PRYCE
	setflag FLAG_HIDE_DOJO_CLAIR
	setflag FLAG_HIDE_DOJO_BROCK
	setflag FLAG_HIDE_DOJO_MISTY
	setflag FLAG_HIDE_DOJO_SURGE
	setflag FLAG_HIDE_DOJO_ERIKA
	setflag FLAG_HIDE_DOJO_JANINE
	setflag FLAG_HIDE_DOJO_SABRINA
	setflag FLAG_HIDE_DOJO_BLAINE
	setflag FLAG_HIDE_DOJO_BLUE
	@end flagheap
	setvar VAR_SSAQUA_STATE, 7
	warp MAP_VERMILION_CITY_PORT_INSIDE, 8, 9
	release
	end

SSAqua_1F_EventScript_RoomSailor::
	msgbox SSAqua_1F_Text_Sailor2_FirstTime, MSGBOX_NPC
	end

SSAqua_1F_EventScript_Sailor3::
	msgbox SSAqua_1F_Text_Sailor3, MSGBOX_NPC
	end

SSAqua_1F_Trigger_Grandpa::
	lock
	clearflag FLAG_HIDE_SSAQUA_1F_GRANDPA
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	call_if_eq VAR_TEMP_0, 28, SSAqua_1F_EventScript_GrandpaEnterLeft
	call_if_eq VAR_TEMP_0, 29, SSAqua_1F_EventScript_GrandpaEnterRight
	applymovement OBJ_EVENT_ID_PLAYER, SSAqua_1F_Movement_PlayerSlideRight
	waitmovement 0
	applymovement LOCALID_SSAQUA_1F_GRANDPA, Common_Movement_WalkRight1
	waitmovement 0
	msgbox SSAqua_1F_Text_Grandpa, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SSAQUA_1F_GRANDPA, SSAqua_1F_Movement_GrandpaLeave
	waitmovement 0
	playse SE_DOOR
	removeobject LOCALID_SSAQUA_1F_GRANDPA
	
	setflag FLAG_HIDE_SSAQUA_1F_GRANDPA		@flagheap
	setflag FLAG_HIDE_SSAQUA_ROOM_SSE_GRANDDAUGHTER

	clearflag FLAG_HIDE_SSAQUA_SAILOR
	clearflag FLAG_HIDE_SSAQUA_CAPTAINS_ROOM_GRANDDAUGHTER

	setvar VAR_SSAQUA_STATE, 2
	release
	end

SSAqua_1F_EventScript_GrandpaEnterLeft::
	applymovement LOCALID_SSAQUA_1F_GRANDPA, SSAqua_1F_Movement_GrandpaEnterLeft
	waitmovement 0
	return

SSAqua_1F_EventScript_GrandpaEnterRight::
	applymovement LOCALID_SSAQUA_1F_GRANDPA, SSAqua_1F_Movement_GrandpaEnterRight
	waitmovement 0
	return

SSAqua_1F_Movement_GrandpaEnterLeft:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

SSAqua_1F_Movement_GrandpaEnterRight:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

SSAqua_1F_Movement_PlayerSlideRight:
	face_left
	lock_facing_direction
	walk_fast_right
	unlock_facing_direction
	step_end

SSAqua_1F_Movement_GrandpaLeave:
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

SSAqua_1F_Text_Sailor1_ToVermilion:
    .string "FAST SHIP S.S.AQUA is en route to\n"
    .string "VERMILION CITY.\p"
    .string "We will make an announcement when\n"
    .string "we arrive.$"

SSAqua_1F_Text_Sailor1_ToOlivine:
    .string "FAST SHIP S.S.AQUA is en route to\n"
    .string "OLIVINE CITY.\p"
    .string "We will make an announcement when\n"
    .string "we arrive.$"

SSAqua_1F_Text_Sailor2_FirstTime:
    .string "Here's your cabin.\p"
    .string "If your POKéMON are hurt, take a\n"
    .string "nap in the bed.\p"
    .string "That will heal them.$"

SSAqua_1F_Text_Sailor3:
    .string "The passengers are all trainers.\p"
    .string "They're all itching to battle in\n"
    .string "their cabins.$"

SSAqua_1F_Text_Grandpa:
    .string "Whoa! Excuse me. I was in a hurry!\p"
    .string "My granddaughter is missing!\p"
    .string "She's just a wee girl. If you see\n"
    .string "her, please let me know!$"

SSAqua_1F_Text_Sailor1_InOlivine:
    .string "FAST SHIP S.S.AQUA has arrived in\n"
    .string "OLIVINE CITY.$"

SSAqua_1F_Text_Sailor1_InVermilion:
    .string "FAST SHIP S.S.AQUA has arrived in\n"
    .string "VERMILION CITY.$"


SSAqua_1F_Text_SailorDoorArrived:
    .string "We have arrived in VERMILION CITY.\n"
    .string "Would you like to disembark?$"
