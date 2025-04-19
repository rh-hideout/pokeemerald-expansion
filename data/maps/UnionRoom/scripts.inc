# 1 "data/maps/UnionRoom/scripts.pory"

# 2 "data/maps/UnionRoom/scripts.pory"
@ Note: LOCALID_UNION_ROOM_PLAYER_# are local ids for this map used elsewhere. They're defined in event_objects.h
# 3 "data/maps/UnionRoom/scripts.pory"

# 4 "data/maps/UnionRoom/scripts.pory"
UnionRoom_MapScripts::
# 5 "data/maps/UnionRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, UnionRoom_OnResume
# 6 "data/maps/UnionRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, UnionRoom_OnTransition
# 7 "data/maps/UnionRoom/scripts.pory"
	.byte 0
# 8 "data/maps/UnionRoom/scripts.pory"

# 9 "data/maps/UnionRoom/scripts.pory"
UnionRoom_OnResume:
# 10 "data/maps/UnionRoom/scripts.pory"
	setflag FLAG_HIDE_UNION_ROOM_PLAYER_1
# 11 "data/maps/UnionRoom/scripts.pory"
	setflag FLAG_HIDE_UNION_ROOM_PLAYER_2
# 12 "data/maps/UnionRoom/scripts.pory"
	setflag FLAG_HIDE_UNION_ROOM_PLAYER_3
# 13 "data/maps/UnionRoom/scripts.pory"
	setflag FLAG_HIDE_UNION_ROOM_PLAYER_4
# 14 "data/maps/UnionRoom/scripts.pory"
	setflag FLAG_HIDE_UNION_ROOM_PLAYER_5
# 15 "data/maps/UnionRoom/scripts.pory"
	setflag FLAG_HIDE_UNION_ROOM_PLAYER_6
# 16 "data/maps/UnionRoom/scripts.pory"
	setflag FLAG_HIDE_UNION_ROOM_PLAYER_7
# 17 "data/maps/UnionRoom/scripts.pory"
	setflag FLAG_HIDE_UNION_ROOM_PLAYER_8
# 18 "data/maps/UnionRoom/scripts.pory"
	removeobject LOCALID_UNION_ROOM_PLAYER_1
# 19 "data/maps/UnionRoom/scripts.pory"
	removeobject LOCALID_UNION_ROOM_PLAYER_2
# 20 "data/maps/UnionRoom/scripts.pory"
	removeobject LOCALID_UNION_ROOM_PLAYER_3
# 21 "data/maps/UnionRoom/scripts.pory"
	removeobject LOCALID_UNION_ROOM_PLAYER_4
# 22 "data/maps/UnionRoom/scripts.pory"
	removeobject LOCALID_UNION_ROOM_PLAYER_5
# 23 "data/maps/UnionRoom/scripts.pory"
	removeobject LOCALID_UNION_ROOM_PLAYER_6
# 24 "data/maps/UnionRoom/scripts.pory"
	removeobject LOCALID_UNION_ROOM_PLAYER_7
# 25 "data/maps/UnionRoom/scripts.pory"
	removeobject LOCALID_UNION_ROOM_PLAYER_8
# 26 "data/maps/UnionRoom/scripts.pory"
	special RunUnionRoom
# 27 "data/maps/UnionRoom/scripts.pory"
	end
# 28 "data/maps/UnionRoom/scripts.pory"

# 29 "data/maps/UnionRoom/scripts.pory"
UnionRoom_OnTransition:
# 30 "data/maps/UnionRoom/scripts.pory"
	setflag FLAG_TEMP_HIDE_FOLLOWER
# 31 "data/maps/UnionRoom/scripts.pory"
	end
# 32 "data/maps/UnionRoom/scripts.pory"

# 33 "data/maps/UnionRoom/scripts.pory"
UnionRoom_EventScript_Player1::
# 34 "data/maps/UnionRoom/scripts.pory"
	lock
# 35 "data/maps/UnionRoom/scripts.pory"
	faceplayer
# 36 "data/maps/UnionRoom/scripts.pory"
	setvar VAR_RESULT, UR_INTERACT_PLAYER_1
# 37 "data/maps/UnionRoom/scripts.pory"
	waitstate
# 38 "data/maps/UnionRoom/scripts.pory"
	release
# 39 "data/maps/UnionRoom/scripts.pory"
	end
# 40 "data/maps/UnionRoom/scripts.pory"

# 41 "data/maps/UnionRoom/scripts.pory"
UnionRoom_EventScript_Player2::
# 42 "data/maps/UnionRoom/scripts.pory"
	lock
# 43 "data/maps/UnionRoom/scripts.pory"
	faceplayer
# 44 "data/maps/UnionRoom/scripts.pory"
	setvar VAR_RESULT, UR_INTERACT_PLAYER_2
# 45 "data/maps/UnionRoom/scripts.pory"
	waitstate
# 46 "data/maps/UnionRoom/scripts.pory"
	release
# 47 "data/maps/UnionRoom/scripts.pory"
	end
# 48 "data/maps/UnionRoom/scripts.pory"

# 49 "data/maps/UnionRoom/scripts.pory"
UnionRoom_EventScript_Player3::
# 50 "data/maps/UnionRoom/scripts.pory"
	lock
# 51 "data/maps/UnionRoom/scripts.pory"
	faceplayer
# 52 "data/maps/UnionRoom/scripts.pory"
	setvar VAR_RESULT, UR_INTERACT_PLAYER_3
# 53 "data/maps/UnionRoom/scripts.pory"
	waitstate
# 54 "data/maps/UnionRoom/scripts.pory"
	release
# 55 "data/maps/UnionRoom/scripts.pory"
	end
# 56 "data/maps/UnionRoom/scripts.pory"

# 57 "data/maps/UnionRoom/scripts.pory"
UnionRoom_EventScript_Player4::
# 58 "data/maps/UnionRoom/scripts.pory"
	lock
# 59 "data/maps/UnionRoom/scripts.pory"
	faceplayer
# 60 "data/maps/UnionRoom/scripts.pory"
	setvar VAR_RESULT, UR_INTERACT_PLAYER_4
# 61 "data/maps/UnionRoom/scripts.pory"
	waitstate
# 62 "data/maps/UnionRoom/scripts.pory"
	release
# 63 "data/maps/UnionRoom/scripts.pory"
	end
# 64 "data/maps/UnionRoom/scripts.pory"

# 65 "data/maps/UnionRoom/scripts.pory"
UnionRoom_EventScript_Player5::
# 66 "data/maps/UnionRoom/scripts.pory"
	lock
# 67 "data/maps/UnionRoom/scripts.pory"
	faceplayer
# 68 "data/maps/UnionRoom/scripts.pory"
	setvar VAR_RESULT, UR_INTERACT_PLAYER_5
# 69 "data/maps/UnionRoom/scripts.pory"
	waitstate
# 70 "data/maps/UnionRoom/scripts.pory"
	release
# 71 "data/maps/UnionRoom/scripts.pory"
	end
# 72 "data/maps/UnionRoom/scripts.pory"

# 73 "data/maps/UnionRoom/scripts.pory"
UnionRoom_EventScript_Player6::
# 74 "data/maps/UnionRoom/scripts.pory"
	lock
# 75 "data/maps/UnionRoom/scripts.pory"
	faceplayer
# 76 "data/maps/UnionRoom/scripts.pory"
	setvar VAR_RESULT, UR_INTERACT_PLAYER_6
# 77 "data/maps/UnionRoom/scripts.pory"
	waitstate
# 78 "data/maps/UnionRoom/scripts.pory"
	release
# 79 "data/maps/UnionRoom/scripts.pory"
	end
# 80 "data/maps/UnionRoom/scripts.pory"

# 81 "data/maps/UnionRoom/scripts.pory"
UnionRoom_EventScript_Player7::
# 82 "data/maps/UnionRoom/scripts.pory"
	lock
# 83 "data/maps/UnionRoom/scripts.pory"
	faceplayer
# 84 "data/maps/UnionRoom/scripts.pory"
	setvar VAR_RESULT, UR_INTERACT_PLAYER_7
# 85 "data/maps/UnionRoom/scripts.pory"
	waitstate
# 86 "data/maps/UnionRoom/scripts.pory"
	release
# 87 "data/maps/UnionRoom/scripts.pory"
	end
# 88 "data/maps/UnionRoom/scripts.pory"

# 89 "data/maps/UnionRoom/scripts.pory"
UnionRoom_EventScript_Player8::
# 90 "data/maps/UnionRoom/scripts.pory"
	lock
# 91 "data/maps/UnionRoom/scripts.pory"
	faceplayer
# 92 "data/maps/UnionRoom/scripts.pory"
	setvar VAR_RESULT, UR_INTERACT_PLAYER_8
# 93 "data/maps/UnionRoom/scripts.pory"
	waitstate
# 94 "data/maps/UnionRoom/scripts.pory"
	release
# 95 "data/maps/UnionRoom/scripts.pory"
	end
# 96 "data/maps/UnionRoom/scripts.pory"

# 97 "data/maps/UnionRoom/scripts.pory"
UnionRoom_EventScript_Attendant::
# 98 "data/maps/UnionRoom/scripts.pory"
	lock
# 99 "data/maps/UnionRoom/scripts.pory"
	faceplayer
# 100 "data/maps/UnionRoom/scripts.pory"
	setvar VAR_RESULT, UR_INTERACT_ATTENDANT
# 101 "data/maps/UnionRoom/scripts.pory"
	waitstate
# 102 "data/maps/UnionRoom/scripts.pory"
	release
# 103 "data/maps/UnionRoom/scripts.pory"
	end
# 104 "data/maps/UnionRoom/scripts.pory"

# 105 "data/maps/UnionRoom/scripts.pory"
UnionRoom_EventScript_Unused::
# 106 "data/maps/UnionRoom/scripts.pory"
	lockall
# 107 "data/maps/UnionRoom/scripts.pory"
	setvar VAR_RESULT, UR_INTERACT_UNUSED
# 108 "data/maps/UnionRoom/scripts.pory"
	waitstate
# 109 "data/maps/UnionRoom/scripts.pory"
	releaseall
# 110 "data/maps/UnionRoom/scripts.pory"
	end
