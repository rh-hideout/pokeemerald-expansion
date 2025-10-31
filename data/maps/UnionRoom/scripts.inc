# 1 "data/maps/UnionRoom/scripts.pory"

# 2 "data/maps/UnionRoom/scripts.pory"
UnionRoom_MapScripts::
# 3 "data/maps/UnionRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, UnionRoom_OnResume
# 4 "data/maps/UnionRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, UnionRoom_OnTransition
# 5 "data/maps/UnionRoom/scripts.pory"
	.byte 0
# 6 "data/maps/UnionRoom/scripts.pory"

# 7 "data/maps/UnionRoom/scripts.pory"
UnionRoom_OnResume:
# 8 "data/maps/UnionRoom/scripts.pory"
	setflag FLAG_HIDE_UNION_ROOM_PLAYER_1
# 9 "data/maps/UnionRoom/scripts.pory"
	setflag FLAG_HIDE_UNION_ROOM_PLAYER_2
# 10 "data/maps/UnionRoom/scripts.pory"
	setflag FLAG_HIDE_UNION_ROOM_PLAYER_3
# 11 "data/maps/UnionRoom/scripts.pory"
	setflag FLAG_HIDE_UNION_ROOM_PLAYER_4
# 12 "data/maps/UnionRoom/scripts.pory"
	setflag FLAG_HIDE_UNION_ROOM_PLAYER_5
# 13 "data/maps/UnionRoom/scripts.pory"
	setflag FLAG_HIDE_UNION_ROOM_PLAYER_6
# 14 "data/maps/UnionRoom/scripts.pory"
	setflag FLAG_HIDE_UNION_ROOM_PLAYER_7
# 15 "data/maps/UnionRoom/scripts.pory"
	setflag FLAG_HIDE_UNION_ROOM_PLAYER_8
# 16 "data/maps/UnionRoom/scripts.pory"
	removeobject LOCALID_UNION_ROOM_PLAYER_1
# 17 "data/maps/UnionRoom/scripts.pory"
	removeobject LOCALID_UNION_ROOM_PLAYER_2
# 18 "data/maps/UnionRoom/scripts.pory"
	removeobject LOCALID_UNION_ROOM_PLAYER_3
# 19 "data/maps/UnionRoom/scripts.pory"
	removeobject LOCALID_UNION_ROOM_PLAYER_4
# 20 "data/maps/UnionRoom/scripts.pory"
	removeobject LOCALID_UNION_ROOM_PLAYER_5
# 21 "data/maps/UnionRoom/scripts.pory"
	removeobject LOCALID_UNION_ROOM_PLAYER_6
# 22 "data/maps/UnionRoom/scripts.pory"
	removeobject LOCALID_UNION_ROOM_PLAYER_7
# 23 "data/maps/UnionRoom/scripts.pory"
	removeobject LOCALID_UNION_ROOM_PLAYER_8
# 24 "data/maps/UnionRoom/scripts.pory"
	special RunUnionRoom
# 25 "data/maps/UnionRoom/scripts.pory"
	end
# 26 "data/maps/UnionRoom/scripts.pory"

# 27 "data/maps/UnionRoom/scripts.pory"
UnionRoom_OnTransition:
# 28 "data/maps/UnionRoom/scripts.pory"
	setflag FLAG_TEMP_HIDE_FOLLOWER
# 29 "data/maps/UnionRoom/scripts.pory"
	end
# 30 "data/maps/UnionRoom/scripts.pory"

# 31 "data/maps/UnionRoom/scripts.pory"
UnionRoom_EventScript_Player1::
# 32 "data/maps/UnionRoom/scripts.pory"
	lock
# 33 "data/maps/UnionRoom/scripts.pory"
	faceplayer
# 34 "data/maps/UnionRoom/scripts.pory"
	setvar VAR_RESULT, UR_INTERACT_PLAYER_1
# 35 "data/maps/UnionRoom/scripts.pory"
	waitstate
# 36 "data/maps/UnionRoom/scripts.pory"
	release
# 37 "data/maps/UnionRoom/scripts.pory"
	end
# 38 "data/maps/UnionRoom/scripts.pory"

# 39 "data/maps/UnionRoom/scripts.pory"
UnionRoom_EventScript_Player2::
# 40 "data/maps/UnionRoom/scripts.pory"
	lock
# 41 "data/maps/UnionRoom/scripts.pory"
	faceplayer
# 42 "data/maps/UnionRoom/scripts.pory"
	setvar VAR_RESULT, UR_INTERACT_PLAYER_2
# 43 "data/maps/UnionRoom/scripts.pory"
	waitstate
# 44 "data/maps/UnionRoom/scripts.pory"
	release
# 45 "data/maps/UnionRoom/scripts.pory"
	end
# 46 "data/maps/UnionRoom/scripts.pory"

# 47 "data/maps/UnionRoom/scripts.pory"
UnionRoom_EventScript_Player3::
# 48 "data/maps/UnionRoom/scripts.pory"
	lock
# 49 "data/maps/UnionRoom/scripts.pory"
	faceplayer
# 50 "data/maps/UnionRoom/scripts.pory"
	setvar VAR_RESULT, UR_INTERACT_PLAYER_3
# 51 "data/maps/UnionRoom/scripts.pory"
	waitstate
# 52 "data/maps/UnionRoom/scripts.pory"
	release
# 53 "data/maps/UnionRoom/scripts.pory"
	end
# 54 "data/maps/UnionRoom/scripts.pory"

# 55 "data/maps/UnionRoom/scripts.pory"
UnionRoom_EventScript_Player4::
# 56 "data/maps/UnionRoom/scripts.pory"
	lock
# 57 "data/maps/UnionRoom/scripts.pory"
	faceplayer
# 58 "data/maps/UnionRoom/scripts.pory"
	setvar VAR_RESULT, UR_INTERACT_PLAYER_4
# 59 "data/maps/UnionRoom/scripts.pory"
	waitstate
# 60 "data/maps/UnionRoom/scripts.pory"
	release
# 61 "data/maps/UnionRoom/scripts.pory"
	end
# 62 "data/maps/UnionRoom/scripts.pory"

# 63 "data/maps/UnionRoom/scripts.pory"
UnionRoom_EventScript_Player5::
# 64 "data/maps/UnionRoom/scripts.pory"
	lock
# 65 "data/maps/UnionRoom/scripts.pory"
	faceplayer
# 66 "data/maps/UnionRoom/scripts.pory"
	setvar VAR_RESULT, UR_INTERACT_PLAYER_5
# 67 "data/maps/UnionRoom/scripts.pory"
	waitstate
# 68 "data/maps/UnionRoom/scripts.pory"
	release
# 69 "data/maps/UnionRoom/scripts.pory"
	end
# 70 "data/maps/UnionRoom/scripts.pory"

# 71 "data/maps/UnionRoom/scripts.pory"
UnionRoom_EventScript_Player6::
# 72 "data/maps/UnionRoom/scripts.pory"
	lock
# 73 "data/maps/UnionRoom/scripts.pory"
	faceplayer
# 74 "data/maps/UnionRoom/scripts.pory"
	setvar VAR_RESULT, UR_INTERACT_PLAYER_6
# 75 "data/maps/UnionRoom/scripts.pory"
	waitstate
# 76 "data/maps/UnionRoom/scripts.pory"
	release
# 77 "data/maps/UnionRoom/scripts.pory"
	end
# 78 "data/maps/UnionRoom/scripts.pory"

# 79 "data/maps/UnionRoom/scripts.pory"
UnionRoom_EventScript_Player7::
# 80 "data/maps/UnionRoom/scripts.pory"
	lock
# 81 "data/maps/UnionRoom/scripts.pory"
	faceplayer
# 82 "data/maps/UnionRoom/scripts.pory"
	setvar VAR_RESULT, UR_INTERACT_PLAYER_7
# 83 "data/maps/UnionRoom/scripts.pory"
	waitstate
# 84 "data/maps/UnionRoom/scripts.pory"
	release
# 85 "data/maps/UnionRoom/scripts.pory"
	end
# 86 "data/maps/UnionRoom/scripts.pory"

# 87 "data/maps/UnionRoom/scripts.pory"
UnionRoom_EventScript_Player8::
# 88 "data/maps/UnionRoom/scripts.pory"
	lock
# 89 "data/maps/UnionRoom/scripts.pory"
	faceplayer
# 90 "data/maps/UnionRoom/scripts.pory"
	setvar VAR_RESULT, UR_INTERACT_PLAYER_8
# 91 "data/maps/UnionRoom/scripts.pory"
	waitstate
# 92 "data/maps/UnionRoom/scripts.pory"
	release
# 93 "data/maps/UnionRoom/scripts.pory"
	end
# 94 "data/maps/UnionRoom/scripts.pory"

# 95 "data/maps/UnionRoom/scripts.pory"
UnionRoom_EventScript_Attendant::
# 96 "data/maps/UnionRoom/scripts.pory"
	lock
# 97 "data/maps/UnionRoom/scripts.pory"
	faceplayer
# 98 "data/maps/UnionRoom/scripts.pory"
	setvar VAR_RESULT, UR_INTERACT_ATTENDANT
# 99 "data/maps/UnionRoom/scripts.pory"
	waitstate
# 100 "data/maps/UnionRoom/scripts.pory"
	release
# 101 "data/maps/UnionRoom/scripts.pory"
	end
# 102 "data/maps/UnionRoom/scripts.pory"

# 103 "data/maps/UnionRoom/scripts.pory"
UnionRoom_EventScript_Unused::
# 104 "data/maps/UnionRoom/scripts.pory"
	lockall
# 105 "data/maps/UnionRoom/scripts.pory"
	setvar VAR_RESULT, UR_INTERACT_UNUSED
# 106 "data/maps/UnionRoom/scripts.pory"
	waitstate
# 107 "data/maps/UnionRoom/scripts.pory"
	releaseall
# 108 "data/maps/UnionRoom/scripts.pory"
	end
