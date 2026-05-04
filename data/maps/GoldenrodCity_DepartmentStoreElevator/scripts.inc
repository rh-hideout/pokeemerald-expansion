GoldenrodCity_DepartmentStoreElevator_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, GoldenrodDeptElevator_OnFrame
	.byte 0

GoldenrodDeptElevator_OnFrame::
	map_script_2 VAR_ELEVATOR, 1, GoldenrodDeptElevator_EventScript_Exit
	.2byte 0

GoldenrodDeptElevator_EventScript_Exit::
	opendoor 9, 4
	opendoor 10, 6
	waitdooranim
	waitdooranim
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown1
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown1
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown1
	waitmovement 0	
	closedoor 9, 4
	closedoor 10, 6
	waitdooranim
	waitdooranim
	setvar VAR_ELEVATOR, 0
	release
	end

GoldenrodDeptElevator_EventScript_Elevator::
	lock
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	delay 8
	opendoor 9, 4
	opendoor 10, 6
	waitdooranim
	waitdooranim
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp1
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp1
	waitmovement 0
	closedoor 9, 4
	closedoor 10, 6
	waitdooranim
	waitdooranim
	multichoice 20, 0, MULTI_7FLOORS, FALSE
	switch VAR_RESULT
	case 0, GoldenrodDeptElevator_EventScript_F6
	case 1, GoldenrodDeptElevator_EventScript_F5
	case 2, GoldenrodDeptElevator_EventScript_F4
	case 3, GoldenrodDeptElevator_EventScript_F3
	case 4, GoldenrodDeptElevator_EventScript_F2
	case 5, GoldenrodDeptElevator_EventScript_F1
	case 6, GoldenrodDeptElevator_EventScript_F0
	case 7, GoldenrodDeptElevator_EventScript_Cancel
	case MULTI_B_PRESSED, GoldenrodDeptElevator_EventScript_Cancel
	closemessage
	end

GoldenrodDeptElevator_EventScript_F0::
	fadescreen FADE_TO_BLACK
	playse SE_SUCCESS
	setvar VAR_ELEVATOR, 1
	waitse
	warp MAP_GOLDENROD_CITY_DEPARTMENT_STORE_BASEMENT, 10, 5
	delay 60
	end
GoldenrodDeptElevator_EventScript_F1::
	fadescreen FADE_TO_BLACK
	playse SE_SUCCESS
	setvar VAR_ELEVATOR, 1
	waitse
	warp MAP_GOLDENROD_CITY_DEPARTMENT_STORE_1F, 9, 3
	delay 60
	end
GoldenrodDeptElevator_EventScript_F2::
	fadescreen FADE_TO_BLACK
	playse SE_SUCCESS
	setvar VAR_ELEVATOR, 1
	waitse
	warp MAP_GOLDENROD_CITY_DEPARTMENT_STORE_2F, 9, 3
	delay 60
	end
GoldenrodDeptElevator_EventScript_F3::
	fadescreen FADE_TO_BLACK
	playse SE_SUCCESS
	setvar VAR_ELEVATOR, 1
	waitse
	warp MAP_GOLDENROD_CITY_DEPARTMENT_STORE_3F, 9, 3
	delay 60
	end
GoldenrodDeptElevator_EventScript_F4::
	fadescreen FADE_TO_BLACK
	playse SE_SUCCESS
	setvar VAR_ELEVATOR, 1
	waitse
	warp MAP_GOLDENROD_CITY_DEPARTMENT_STORE_4F, 9, 3
	delay 60
	end
GoldenrodDeptElevator_EventScript_F5::
	fadescreen FADE_TO_BLACK
	playse SE_SUCCESS
	setvar VAR_ELEVATOR, 1
	waitse
	warp MAP_GOLDENROD_CITY_DEPARTMENT_STORE_5F, 9, 3
	delay 60
	end
GoldenrodDeptElevator_EventScript_F6::
	fadescreen FADE_TO_BLACK
	playse SE_SUCCESS
	setvar VAR_ELEVATOR, 1
	waitse
	warp MAP_GOLDENROD_CITY_DEPARTMENT_STORE_6F, 9, 3
	delay 60
	end

GoldenrodDeptElevator_EventScript_Cancel::
	closemessage
	opendoor 9, 4
	opendoor 10, 6
	waitdooranim
	waitdooranim
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown1
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown1
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown1
	waitmovement 0	
	closedoor 9, 4
	closedoor 10, 6
	waitdooranim
	waitdooranim
	release
	end

@========================================================================================================================================================================
@============CELADON ELEVATOR=========================================================================================================================
@========================================================================================================================================================================


CeladonDeptElevator_OnFrame::
	map_script_2 VAR_ELEVATOR, 1, CeladonDeptElevator_EventScript_Exit
	.2byte 0

CeladonDeptElevator_EventScript_Exit::
	opendoor 6, 1
	opendoor 10, 6
	waitdooranim
	waitdooranim
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown1
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown1
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown1
	waitmovement 0	
	closedoor 6, 1
	closedoor 10, 6
	waitdooranim
	waitdooranim
	setvar VAR_ELEVATOR, 0
	release
	end

CeladonDeptElevator_EventScript_Elevator::
	lock
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	delay 8
	opendoor 6, 1
	opendoor 10, 6
	waitdooranim
	waitdooranim
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp1
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp1
	waitmovement 0
	closedoor 6, 1
	closedoor 10, 6
	waitdooranim
	waitdooranim
	multichoice 20, 0, MULTI_5FLOORS, FALSE
	switch VAR_RESULT
	case 0, CeladonDeptElevator_EventScript_F5
	case 1, CeladonDeptElevator_EventScript_F4
	case 2, CeladonDeptElevator_EventScript_F3
	case 3, CeladonDeptElevator_EventScript_F2
	case 4, CeladonDeptElevator_EventScript_F1
	case 5, CeladonDeptElevator_EventScript_Cancel
	case MULTI_B_PRESSED, CeladonDeptElevator_EventScript_Cancel
	closemessage
	end

CeladonDeptElevator_EventScript_F1::
	fadescreen FADE_TO_BLACK
	playse SE_SUCCESS
	setvar VAR_ELEVATOR, 1
	waitse
	warp MAP_CELADON_CITY_DEPARTMENT_STORE_1F, 6, 0
	delay 60
	end
CeladonDeptElevator_EventScript_F2::
	fadescreen FADE_TO_BLACK
	playse SE_SUCCESS
	setvar VAR_ELEVATOR, 1
	waitse
	warp MAP_CELADON_CITY_DEPARTMENT_STORE_2F, 6, 0
	delay 60
	end
CeladonDeptElevator_EventScript_F3::
	fadescreen FADE_TO_BLACK
	playse SE_SUCCESS
	setvar VAR_ELEVATOR, 1
	waitse
	warp MAP_CELADON_CITY_DEPARTMENT_STORE_3F, 6, 0
	delay 60
	end
CeladonDeptElevator_EventScript_F4::
	fadescreen FADE_TO_BLACK
	playse SE_SUCCESS
	setvar VAR_ELEVATOR, 1
	waitse
	warp MAP_CELADON_CITY_DEPARTMENT_STORE_4F, 6, 0
	delay 60
	end
CeladonDeptElevator_EventScript_F5::
	fadescreen FADE_TO_BLACK
	playse SE_SUCCESS
	setvar VAR_ELEVATOR, 1
	waitse
	warp MAP_CELADON_CITY_DEPARTMENT_STORE_5F, 6, 0
	delay 60
	end


CeladonDeptElevator_EventScript_Cancel::
	closemessage
	opendoor 6, 1
	opendoor 10, 6
	waitdooranim
	waitdooranim
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown1
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown1
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown1
	waitmovement 0	
	closedoor 6, 1
	closedoor 10, 6
	waitdooranim
	waitdooranim
	release
	end
