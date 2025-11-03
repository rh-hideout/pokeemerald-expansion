# 1 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"

# 2 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
LilycoveCity_DepartmentStoreElevator_MapScripts::
# 3 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	.byte 0
# 4 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"

# 5 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
LilycoveCity_DepartmentStoreElevator_EventScript_Attendant::
# 6 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	lock
# 7 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	faceplayer
# 8 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	setvar VAR_0x8004, 0
# 9 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	call_if_unset FLAG_TEMP_2, LilycoveCity_DepartmentStoreElevator_EventScript_SetFloor
# 10 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	copyvar VAR_0x8005, VAR_DEPT_STORE_FLOOR
# 11 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	special ShowDeptStoreElevatorFloorSelect
# 12 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	message gText_WhichFloorWouldYouLike
# 13 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	waitmessage
# 14 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	setvar VAR_0x8004, 0
# 15 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	specialvar VAR_RESULT, GetDeptStoreDefaultFloorChoice
# 16 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	switch VAR_RESULT
# 17 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	case 0, LilycoveCity_DepartmentStoreElevator_EventScript_ChooseFloorFrom5th
# 18 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	case 1, LilycoveCity_DepartmentStoreElevator_EventScript_ChooseFloorFrom4th
# 19 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	case 2, LilycoveCity_DepartmentStoreElevator_EventScript_ChooseFloorFrom3rd
# 20 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	case 3, LilycoveCity_DepartmentStoreElevator_EventScript_ChooseFloorFrom2nd
# 21 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	case 4, LilycoveCity_DepartmentStoreElevator_EventScript_ChooseFloorFrom1st
# 22 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	end
# 23 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"

# 24 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
@ Below scripts ensure the cursor for floor select always starts on the current floor
# 25 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
LilycoveCity_DepartmentStoreElevator_EventScript_ChooseFloorFrom5th::
# 26 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	multichoicedefault 0, 0, MULTI_FLOORS, 0, FALSE
# 27 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	goto LilycoveCity_DepartmentStoreElevator_EventScript_ChooseFloor
# 28 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	end
# 29 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"

# 30 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
LilycoveCity_DepartmentStoreElevator_EventScript_ChooseFloorFrom4th::
# 31 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	multichoicedefault 0, 0, MULTI_FLOORS, 1, FALSE
# 32 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	goto LilycoveCity_DepartmentStoreElevator_EventScript_ChooseFloor
# 33 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	end
# 34 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"

# 35 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
LilycoveCity_DepartmentStoreElevator_EventScript_ChooseFloorFrom3rd::
# 36 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	multichoicedefault 0, 0, MULTI_FLOORS, 2, FALSE
# 37 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	goto LilycoveCity_DepartmentStoreElevator_EventScript_ChooseFloor
# 38 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	end
# 39 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"

# 40 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
LilycoveCity_DepartmentStoreElevator_EventScript_ChooseFloorFrom2nd::
# 41 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	multichoicedefault 0, 0, MULTI_FLOORS, 3, FALSE
# 42 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	goto LilycoveCity_DepartmentStoreElevator_EventScript_ChooseFloor
# 43 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	end
# 44 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"

# 45 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
LilycoveCity_DepartmentStoreElevator_EventScript_ChooseFloorFrom1st::
# 46 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	multichoicedefault 0, 0, MULTI_FLOORS, 4, FALSE
# 47 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	goto LilycoveCity_DepartmentStoreElevator_EventScript_ChooseFloor
# 48 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	end
# 49 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"

# 50 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
LilycoveCity_DepartmentStoreElevator_EventScript_ChooseFloor::
# 51 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	switch VAR_RESULT
# 52 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	case 0, LilycoveCity_DepartmentStoreElevator_EventScript_5thFloor
# 53 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	case 1, LilycoveCity_DepartmentStoreElevator_EventScript_4thFloor
# 54 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	case 2, LilycoveCity_DepartmentStoreElevator_EventScript_3rdFloor
# 55 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	case 3, LilycoveCity_DepartmentStoreElevator_EventScript_2ndFloor
# 56 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	case 4, LilycoveCity_DepartmentStoreElevator_EventScript_1stFloor
# 57 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	case 5, LilycoveCity_DepartmentStoreElevator_EventScript_ExitFloorSelect
# 58 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	case MULTI_B_PRESSED, LilycoveCity_DepartmentStoreElevator_EventScript_ExitFloorSelect
# 59 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	end
# 60 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"

# 61 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
LilycoveCity_DepartmentStoreElevator_EventScript_1stFloor::
# 62 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	setvar VAR_0x8006, DEPT_STORE_FLOORNUM_1F
# 63 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	setdynamicwarp MAP_LILYCOVE_CITY_DEPARTMENT_STORE_1F, 2, 1
# 64 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	goto_if_eq VAR_DEPT_STORE_FLOOR, DEPT_STORE_FLOORNUM_1F, LilycoveCity_DepartmentStoreElevator_EventScript_ExitFloorSelect
# 65 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	call LilycoveCity_DepartmentStoreElevator_EventScript_MoveElevator
# 66 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	setvar VAR_DEPT_STORE_FLOOR, DEPT_STORE_FLOORNUM_1F
# 67 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	goto LilycoveCity_DepartmentStoreElevator_EventScript_ExitFloorSelect
# 68 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	end
# 69 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"

# 70 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
LilycoveCity_DepartmentStoreElevator_EventScript_2ndFloor::
# 71 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	setvar VAR_0x8006, DEPT_STORE_FLOORNUM_2F
# 72 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	setdynamicwarp MAP_LILYCOVE_CITY_DEPARTMENT_STORE_2F, 2, 1
# 73 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	goto_if_eq VAR_DEPT_STORE_FLOOR, DEPT_STORE_FLOORNUM_2F, LilycoveCity_DepartmentStoreElevator_EventScript_ExitFloorSelect
# 74 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	call LilycoveCity_DepartmentStoreElevator_EventScript_MoveElevator
# 75 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	setvar VAR_DEPT_STORE_FLOOR, DEPT_STORE_FLOORNUM_2F
# 76 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	goto LilycoveCity_DepartmentStoreElevator_EventScript_ExitFloorSelect
# 77 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	end
# 78 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"

# 79 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
LilycoveCity_DepartmentStoreElevator_EventScript_3rdFloor::
# 80 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	setvar VAR_0x8006, DEPT_STORE_FLOORNUM_3F
# 81 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	setdynamicwarp MAP_LILYCOVE_CITY_DEPARTMENT_STORE_3F, 2, 1
# 82 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	goto_if_eq VAR_DEPT_STORE_FLOOR, DEPT_STORE_FLOORNUM_3F, LilycoveCity_DepartmentStoreElevator_EventScript_ExitFloorSelect
# 83 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	call LilycoveCity_DepartmentStoreElevator_EventScript_MoveElevator
# 84 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	setvar VAR_DEPT_STORE_FLOOR, DEPT_STORE_FLOORNUM_3F
# 85 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	goto LilycoveCity_DepartmentStoreElevator_EventScript_ExitFloorSelect
# 86 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	end
# 87 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"

# 88 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
LilycoveCity_DepartmentStoreElevator_EventScript_4thFloor::
# 89 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	setvar VAR_0x8006, DEPT_STORE_FLOORNUM_4F
# 90 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	setdynamicwarp MAP_LILYCOVE_CITY_DEPARTMENT_STORE_4F, 2, 1
# 91 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	goto_if_eq VAR_DEPT_STORE_FLOOR, DEPT_STORE_FLOORNUM_4F, LilycoveCity_DepartmentStoreElevator_EventScript_ExitFloorSelect
# 92 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	call LilycoveCity_DepartmentStoreElevator_EventScript_MoveElevator
# 93 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	setvar VAR_DEPT_STORE_FLOOR, DEPT_STORE_FLOORNUM_4F
# 94 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	goto LilycoveCity_DepartmentStoreElevator_EventScript_ExitFloorSelect
# 95 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	end
# 96 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"

# 97 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
LilycoveCity_DepartmentStoreElevator_EventScript_5thFloor::
# 98 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	setvar VAR_0x8006, DEPT_STORE_FLOORNUM_5F
# 99 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	setdynamicwarp MAP_LILYCOVE_CITY_DEPARTMENT_STORE_5F, 2, 1
# 100 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	goto_if_eq VAR_DEPT_STORE_FLOOR, DEPT_STORE_FLOORNUM_5F, LilycoveCity_DepartmentStoreElevator_EventScript_ExitFloorSelect
# 101 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	call LilycoveCity_DepartmentStoreElevator_EventScript_MoveElevator
# 102 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	setvar VAR_DEPT_STORE_FLOOR, DEPT_STORE_FLOORNUM_5F
# 103 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	goto LilycoveCity_DepartmentStoreElevator_EventScript_ExitFloorSelect
# 104 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	end
# 105 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"

# 106 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
LilycoveCity_DepartmentStoreElevator_EventScript_ExitFloorSelect::
# 107 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	special CloseDeptStoreElevatorWindow
# 108 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	release
# 109 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	end
# 110 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"

# 111 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
LilycoveCity_DepartmentStoreElevator_EventScript_MoveElevator::
# 112 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	special CloseDeptStoreElevatorWindow
# 113 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	closemessage
# 114 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
# 115 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	waitmovement 0
# 116 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	waitse
# 117 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	special MoveElevator
# 118 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	waitstate
# 119 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	setflag FLAG_TEMP_2
# 120 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	return
# 121 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"

# 122 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
LilycoveCity_DepartmentStoreElevator_EventScript_SetFloor::
# 123 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	special SetDeptStoreFloor
# 124 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	return
