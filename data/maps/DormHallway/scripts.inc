DormHallway_MapScripts::
# 2 "data/maps/DormHallway/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, DormHallway_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

DormHallway_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 3 "data/maps/DormHallway/scripts.pory"
	map_script_2 VAR_PLAYERDORM_STATE, 2, DormHallway_LeaveDorm
	.2byte 0


DormHallway_LeaveDorm::
# 8 "data/maps/DormHallway/scripts.pory"
	lockall
# 9 "data/maps/DormHallway/scripts.pory"
	speakername Tracie
# 10 "data/maps/DormHallway/scripts.pory"
	msgbox DormHallway_LeaveDorm_Text_0
# 11 "data/maps/DormHallway/scripts.pory"
	closemessage
# 12 "data/maps/DormHallway/scripts.pory"
	call DormHallway_EnterRotcart
# 13 "data/maps/DormHallway/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, DormHallway_LeaveDorm_Movement_0
# 14 "data/maps/DormHallway/scripts.pory"
	waitmovement 0
# 15 "data/maps/DormHallway/scripts.pory"
	speakername Tracie
# 16 "data/maps/DormHallway/scripts.pory"
	msgbox DormHallway_LeaveDorm_Text_1
# 17 "data/maps/DormHallway/scripts.pory"
	closemessage
# 18 "data/maps/DormHallway/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, DormHallway_LeaveDorm_Movement_1
# 19 "data/maps/DormHallway/scripts.pory"
	applymovement LOCALID_TRACIE, DormHallway_LeaveDorm_Movement_2
# 20 "data/maps/DormHallway/scripts.pory"
	waitmovement 0
# 21 "data/maps/DormHallway/scripts.pory"
	removeobject LOCALID_TRACIE
# 22 "data/maps/DormHallway/scripts.pory"
	playse SE_DOOR
# 23 "data/maps/DormHallway/scripts.pory"
	waitse
# 24 "data/maps/DormHallway/scripts.pory"
	setflag FLAG_HIDE_TRACIEROTCART
# 25 "data/maps/DormHallway/scripts.pory"
	setvar VAR_PLAYERDORM_STATE, 3
	end


DormHallway_EnterRotcart::
# 30 "data/maps/DormHallway/scripts.pory"
	playse SE_DOOR
# 31 "data/maps/DormHallway/scripts.pory"
	waitse
# 32 "data/maps/DormHallway/scripts.pory"
	playbgm MUS_RG_ENCOUNTER_RIVAL, TRUE
# 33 "data/maps/DormHallway/scripts.pory"
	applymovement LOCALID_ROTCART, DormHallway_EnterRotcart_Movement_0
# 34 "data/maps/DormHallway/scripts.pory"
	waitmovement 0
# 35 "data/maps/DormHallway/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, DormHallway_EnterRotcart_Movement_1
# 36 "data/maps/DormHallway/scripts.pory"
	applymovement LOCALID_TRACIE, DormHallway_EnterRotcart_Movement_1
# 37 "data/maps/DormHallway/scripts.pory"
	waitmovement 0
# 38 "data/maps/DormHallway/scripts.pory"
	speakername Unknown
# 39 "data/maps/DormHallway/scripts.pory"
	msgbox DormHallway_EnterRotcart_Text_0
# 40 "data/maps/DormHallway/scripts.pory"
	closemessage
# 41 "data/maps/DormHallway/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, DormHallway_EnterRotcart_Movement_2
# 42 "data/maps/DormHallway/scripts.pory"
	applymovement LOCALID_TRACIE, DormHallway_EnterRotcart_Movement_2
# 43 "data/maps/DormHallway/scripts.pory"
	waitmovement 0
# 44 "data/maps/DormHallway/scripts.pory"
	applymovement LOCALID_ROTCART, DormHallway_EnterRotcart_Movement_3
# 45 "data/maps/DormHallway/scripts.pory"
	waitmovement 0
# 46 "data/maps/DormHallway/scripts.pory"
	removeobject LOCALID_ROTCART
# 47 "data/maps/DormHallway/scripts.pory"
	fadedefaultbgm
	return


DormHallway_DontLeave::
# 52 "data/maps/DormHallway/scripts.pory"
	lock
# 53 "data/maps/DormHallway/scripts.pory"
	msgbox DormHallway_DontLeave_Text_0
# 54 "data/maps/DormHallway/scripts.pory"
	closemessage
# 55 "data/maps/DormHallway/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, DormHallway_DontLeave_Movement_0
# 56 "data/maps/DormHallway/scripts.pory"
	waitmovement 0
# 57 "data/maps/DormHallway/scripts.pory"
	release
	end


Player_Dorm_EventScript_PlayerSign::
# 63 "data/maps/DormHallway/scripts.pory"
	lock
# 64 "data/maps/DormHallway/scripts.pory"
	msgbox Player_Dorm_EventScript_PlayerSign_Text_0
# 65 "data/maps/DormHallway/scripts.pory"
	release
	end


Player_Dorm_EventScript_TracieSign::
# 70 "data/maps/DormHallway/scripts.pory"
	lock
# 71 "data/maps/DormHallway/scripts.pory"
	msgbox Player_Dorm_EventScript_TracieSign_Text_0
# 72 "data/maps/DormHallway/scripts.pory"
	release
	end


Player_Dorm_EventScript_RotcartSign::
# 77 "data/maps/DormHallway/scripts.pory"
	lock
# 78 "data/maps/DormHallway/scripts.pory"
	msgbox Player_Dorm_EventScript_RotcartSign_Text_0
# 79 "data/maps/DormHallway/scripts.pory"
	release
	end


# 13 "data/maps/DormHallway/scripts.pory"
DormHallway_LeaveDorm_Movement_0:
# 13 "data/maps/DormHallway/scripts.pory"
	face_down
	step_end

# 18 "data/maps/DormHallway/scripts.pory"
DormHallway_LeaveDorm_Movement_1:
# 18 "data/maps/DormHallway/scripts.pory"
	face_right
	step_end

# 19 "data/maps/DormHallway/scripts.pory"
DormHallway_LeaveDorm_Movement_2:
# 19 "data/maps/DormHallway/scripts.pory"
	walk_right
# 19 "data/maps/DormHallway/scripts.pory"
	walk_right
# 19 "data/maps/DormHallway/scripts.pory"
	walk_right
# 19 "data/maps/DormHallway/scripts.pory"
	walk_right
# 19 "data/maps/DormHallway/scripts.pory"
	walk_right
# 19 "data/maps/DormHallway/scripts.pory"
	walk_right
# 19 "data/maps/DormHallway/scripts.pory"
	walk_right
# 19 "data/maps/DormHallway/scripts.pory"
	walk_right
# 19 "data/maps/DormHallway/scripts.pory"
	walk_right
# 19 "data/maps/DormHallway/scripts.pory"
	walk_up
	step_end

# 33 "data/maps/DormHallway/scripts.pory"
DormHallway_EnterRotcart_Movement_0:
# 33 "data/maps/DormHallway/scripts.pory"
	walk_right
# 33 "data/maps/DormHallway/scripts.pory"
	walk_right
# 33 "data/maps/DormHallway/scripts.pory"
	walk_right
# 33 "data/maps/DormHallway/scripts.pory"
	walk_right
# 33 "data/maps/DormHallway/scripts.pory"
	walk_right
# 33 "data/maps/DormHallway/scripts.pory"
	walk_right
# 33 "data/maps/DormHallway/scripts.pory"
	walk_right
# 33 "data/maps/DormHallway/scripts.pory"
	walk_right
	step_end

# 35 "data/maps/DormHallway/scripts.pory"
DormHallway_EnterRotcart_Movement_1:
# 35 "data/maps/DormHallway/scripts.pory"
	face_left
	step_end

# 41 "data/maps/DormHallway/scripts.pory"
DormHallway_EnterRotcart_Movement_2:
# 41 "data/maps/DormHallway/scripts.pory"
	walk_down
# 41 "data/maps/DormHallway/scripts.pory"
	face_up
	step_end

# 44 "data/maps/DormHallway/scripts.pory"
DormHallway_EnterRotcart_Movement_3:
# 44 "data/maps/DormHallway/scripts.pory"
	walk_right
# 44 "data/maps/DormHallway/scripts.pory"
	walk_right
# 44 "data/maps/DormHallway/scripts.pory"
	walk_right
# 44 "data/maps/DormHallway/scripts.pory"
	walk_right
# 44 "data/maps/DormHallway/scripts.pory"
	walk_right
# 44 "data/maps/DormHallway/scripts.pory"
	walk_right
# 44 "data/maps/DormHallway/scripts.pory"
	walk_right
# 44 "data/maps/DormHallway/scripts.pory"
	walk_right
# 44 "data/maps/DormHallway/scripts.pory"
	walk_right
	step_end

# 55 "data/maps/DormHallway/scripts.pory"
DormHallway_DontLeave_Movement_0:
# 55 "data/maps/DormHallway/scripts.pory"
	walk_down
	step_end

DormHallway_LeaveDorm_Text_0:
# 10 "data/maps/DormHallway/scripts.pory"
	.string "Oh! Before I forget!\p"
	.string "I need to stop at my room to grab some\n"
	.string "things.$"

DormHallway_LeaveDorm_Text_1:
# 16 "data/maps/DormHallway/scripts.pory"
	.string "Ugh! Rotcart…\n"
	.string "What an asshole!\p"
	.string "I know he's one of the strongest\n"
	.string "Trainers in this school, but does he\l"
	.string "really have to be such a dick?\p"
	.string "At least you're able to give him a run\n"
	.string "for his money…\p"
	.string "He does have a point though, we need to\n"
	.string "get going!\p"
	.string "Follow me to my room!$"

DormHallway_EnterRotcart_Text_0:
# 39 "data/maps/DormHallway/scripts.pory"
	.string "… … …\p… … …\n… … …\pMove.$"

DormHallway_DontLeave_Text_0:
# 53 "data/maps/DormHallway/scripts.pory"
	.string "Tracie's dorm isn't this way.$"

Player_Dorm_EventScript_PlayerSign_Text_0:
# 64 "data/maps/DormHallway/scripts.pory"
	.string "{PLAYER}'s room$"

Player_Dorm_EventScript_TracieSign_Text_0:
# 71 "data/maps/DormHallway/scripts.pory"
	.string "Tracie's room$"

Player_Dorm_EventScript_RotcartSign_Text_0:
# 78 "data/maps/DormHallway/scripts.pory"
	.string "Rotcart's room$"
