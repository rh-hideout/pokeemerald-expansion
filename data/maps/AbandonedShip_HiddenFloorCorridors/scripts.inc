# 1 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"

# 2 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
AbandonedShip_HiddenFloorCorridors_MapScripts::
# 3 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, AbandonedShip_HiddenFloorCorridors_OnResume
# 4 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, AbandonedShip_HiddenFloorCorridors_OnLoad
# 5 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	.byte 0
# 6 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"

# 7 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
AbandonedShip_HiddenFloorCorridors_OnResume:
# 8 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	setdivewarp MAP_ABANDONED_SHIP_UNDERWATER1, 5, 4
# 9 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	end
# 10 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"

# 11 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
AbandonedShip_HiddenFloorCorridors_OnLoad:
# 12 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	call_if_unset FLAG_USED_ROOM_1_KEY, AbandonedShip_HiddenFloorCorridors_EventScript_LockRoom1
# 13 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	call_if_unset FLAG_USED_ROOM_2_KEY, AbandonedShip_HiddenFloorCorridors_EventScript_LockRoom2
# 14 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	call_if_unset FLAG_USED_ROOM_4_KEY, AbandonedShip_HiddenFloorCorridors_EventScript_LockRoom4
# 15 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	call_if_unset FLAG_USED_ROOM_6_KEY, AbandonedShip_HiddenFloorCorridors_EventScript_LockRoom6
# 16 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	call_if_set FLAG_USED_ROOM_1_KEY, AbandonedShip_HiddenFloorCorridors_EventScript_UnlockRoom1
# 17 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	call_if_set FLAG_USED_ROOM_2_KEY, AbandonedShip_HiddenFloorCorridors_EventScript_UnlockRoom2
# 18 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	call_if_set FLAG_USED_ROOM_4_KEY, AbandonedShip_HiddenFloorCorridors_EventScript_UnlockRoom4
# 19 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	call_if_set FLAG_USED_ROOM_6_KEY, AbandonedShip_HiddenFloorCorridors_EventScript_UnlockRoom6
# 20 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	end
# 21 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"

# 22 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
AbandonedShip_HiddenFloorCorridors_EventScript_UnlockRoom1::
# 23 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	setmetatile 3, 8, METATILE_InsideShip_IntactDoor_Bottom_Unlocked, TRUE
# 24 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	return
# 25 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"

# 26 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
AbandonedShip_HiddenFloorCorridors_EventScript_UnlockRoom2::
# 27 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	setmetatile 6, 8, METATILE_InsideShip_IntactDoor_Bottom_Unlocked, TRUE
# 28 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	return
# 29 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"

# 30 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
AbandonedShip_HiddenFloorCorridors_EventScript_UnlockRoom4::
# 31 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	setmetatile 3, 3, METATILE_InsideShip_DoorIndent_Unlocked, FALSE
# 32 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	return
# 33 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"

# 34 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
AbandonedShip_HiddenFloorCorridors_EventScript_UnlockRoom6::
# 35 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	setmetatile 9, 3, METATILE_InsideShip_DoorIndent_Unlocked, FALSE
# 36 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	return
# 37 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"

# 38 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
AbandonedShip_HiddenFloorCorridors_EventScript_LockRoom1::
# 39 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	setmetatile 3, 8, METATILE_InsideShip_IntactDoor_Bottom_Locked, TRUE
# 40 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	return
# 41 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"

# 42 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
AbandonedShip_HiddenFloorCorridors_EventScript_LockRoom2::
# 43 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	setmetatile 6, 8, METATILE_InsideShip_IntactDoor_Bottom_Locked, TRUE
# 44 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	return
# 45 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"

# 46 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
AbandonedShip_HiddenFloorCorridors_EventScript_LockRoom4::
# 47 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	setmetatile 3, 3, METATILE_InsideShip_DoorIndent_Locked, FALSE
# 48 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	return
# 49 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"

# 50 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
AbandonedShip_HiddenFloorCorridors_EventScript_LockRoom6::
# 51 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	setmetatile 9, 3, METATILE_InsideShip_DoorIndent_Locked, FALSE
# 52 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	return
# 53 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"

# 54 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
AbandonedShip_HiddenFloorCorridors_EventScript_Room1Door::
# 55 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	lockall
# 56 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	goto_if_set FLAG_USED_ROOM_1_KEY, AbandonedShip_HiddenFloorCorridors_EventScript_TheDoorIsOpen
# 57 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	checkitem ITEM_KEY_TO_ROOM_1
# 58 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, AbandonedShip_HiddenFloorCorridors_EventScript_Rm1IsLocked
# 59 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	msgbox AbandonedShip_HiddenFloorCorridors_Text_InsertedKey, MSGBOX_DEFAULT
# 60 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	playse SE_PIN
# 61 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	removeitem ITEM_KEY_TO_ROOM_1
# 62 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	setflag FLAG_USED_ROOM_1_KEY
# 63 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	call AbandonedShip_HiddenFloorCorridors_EventScript_UnlockRoom1
# 64 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	special DrawWholeMapView
# 65 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	releaseall
# 66 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	end
# 67 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"

# 68 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
AbandonedShip_HiddenFloorCorridors_EventScript_Room2Door::
# 69 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	lockall
# 70 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	goto_if_set FLAG_USED_ROOM_2_KEY, AbandonedShip_HiddenFloorCorridors_EventScript_TheDoorIsOpen
# 71 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	checkitem ITEM_KEY_TO_ROOM_2
# 72 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, AbandonedShip_HiddenFloorCorridors_EventScript_Rm2IsLocked
# 73 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	msgbox AbandonedShip_HiddenFloorCorridors_Text_InsertedKey, MSGBOX_DEFAULT
# 74 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	playse SE_PIN
# 75 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	removeitem ITEM_KEY_TO_ROOM_2
# 76 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	setflag FLAG_USED_ROOM_2_KEY
# 77 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	call AbandonedShip_HiddenFloorCorridors_EventScript_UnlockRoom2
# 78 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	special DrawWholeMapView
# 79 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	releaseall
# 80 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	end
# 81 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"

# 82 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
AbandonedShip_HiddenFloorCorridors_EventScript_Room4Door::
# 83 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	lockall
# 84 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	goto_if_set FLAG_USED_ROOM_4_KEY, AbandonedShip_HiddenFloorCorridors_EventScript_TheDoorIsOpen
# 85 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	checkitem ITEM_KEY_TO_ROOM_4
# 86 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, AbandonedShip_HiddenFloorCorridors_EventScript_Rm4IsLocked
# 87 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	msgbox AbandonedShip_HiddenFloorCorridors_Text_InsertedKey, MSGBOX_DEFAULT
# 88 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	playse SE_PIN
# 89 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	removeitem ITEM_KEY_TO_ROOM_4
# 90 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	setflag FLAG_USED_ROOM_4_KEY
# 91 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	call AbandonedShip_HiddenFloorCorridors_EventScript_UnlockRoom4
# 92 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	special DrawWholeMapView
# 93 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	releaseall
# 94 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	end
# 95 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"

# 96 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
AbandonedShip_HiddenFloorCorridors_EventScript_Room6Door::
# 97 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	lockall
# 98 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	goto_if_set FLAG_USED_ROOM_6_KEY, AbandonedShip_HiddenFloorCorridors_EventScript_TheDoorIsOpen
# 99 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	checkitem ITEM_KEY_TO_ROOM_6
# 100 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, AbandonedShip_HiddenFloorCorridors_EventScript_Rm6IsLocked
# 101 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	msgbox AbandonedShip_HiddenFloorCorridors_Text_InsertedKey, MSGBOX_DEFAULT
# 102 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	playse SE_PIN
# 103 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	removeitem ITEM_KEY_TO_ROOM_6
# 104 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	setflag FLAG_USED_ROOM_6_KEY
# 105 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	call AbandonedShip_HiddenFloorCorridors_EventScript_UnlockRoom6
# 106 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	special DrawWholeMapView
# 107 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	releaseall
# 108 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	end
# 109 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"

# 110 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
AbandonedShip_HiddenFloorCorridors_EventScript_Rm1IsLocked::
# 111 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	msgbox AbandonedShip_HiddenFloorCorridors_Text_Rm1DoorIsLocked, MSGBOX_DEFAULT
# 112 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	releaseall
# 113 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	end
# 114 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"

# 115 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
AbandonedShip_HiddenFloorCorridors_EventScript_Rm2IsLocked::
# 116 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	msgbox AbandonedShip_HiddenFloorCorridors_Text_Rm2DoorIsLocked, MSGBOX_DEFAULT
# 117 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	releaseall
# 118 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	end
# 119 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"

# 120 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
AbandonedShip_HiddenFloorCorridors_EventScript_Rm4IsLocked::
# 121 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	msgbox AbandonedShip_HiddenFloorCorridors_Text_Rm4DoorIsLocked, MSGBOX_DEFAULT
# 122 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	releaseall
# 123 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	end
# 124 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"

# 125 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
AbandonedShip_HiddenFloorCorridors_EventScript_Rm6IsLocked::
# 126 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	msgbox AbandonedShip_HiddenFloorCorridors_Text_Rm6DoorIsLocked, MSGBOX_DEFAULT
# 127 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	releaseall
# 128 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	end
# 129 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"

# 130 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
AbandonedShip_HiddenFloorCorridors_EventScript_TheDoorIsOpen::
# 131 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	msgbox AbandonedShip_Text_TheDoorIsOpen, MSGBOX_DEFAULT
# 132 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	releaseall
# 133 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	end
# 134 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"

# 135 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
AbandonedShip_HiddenFloorCorridors_Text_Rm1DoorIsLocked:
# 136 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	.string "The door is locked.\p"
# 137 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	.string "“RM. 1” is painted on the door.$"
# 138 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"

# 139 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
AbandonedShip_HiddenFloorCorridors_Text_Rm2DoorIsLocked:
# 140 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	.string "The door is locked.\p"
# 141 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	.string "“RM. 2” is painted on the door.$"
# 142 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"

# 143 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
AbandonedShip_HiddenFloorCorridors_Text_Rm4DoorIsLocked:
# 144 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	.string "The door is locked.\p"
# 145 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	.string "“RM. 4” is painted on the door.$"
# 146 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"

# 147 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
AbandonedShip_HiddenFloorCorridors_Text_Rm6DoorIsLocked:
# 148 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	.string "The door is locked.\p"
# 149 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	.string "“RM. 6” is painted on the door.$"
# 150 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"

# 151 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
AbandonedShip_HiddenFloorCorridors_Text_InsertedKey:
# 152 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	.string "{PLAYER} inserted and turned the\n"
# 153 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	.string "KEY.\p"
# 154 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	.string "The inserted KEY stuck fast,\n"
# 155 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	.string "but the door opened.$"
