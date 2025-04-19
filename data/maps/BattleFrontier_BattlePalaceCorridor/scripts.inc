# 1 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"

# 2 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
.set LOCALID_ATTENDANT, 1
# 3 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"

# 4 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
BattleFrontier_BattlePalaceCorridor_MapScripts::
# 5 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePalaceCorridor_OnFrame
# 6 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	.byte 0
# 7 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"

# 8 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
BattleFrontier_BattlePalaceCorridor_OnFrame:
# 9 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	map_script_2 VAR_TEMP_0, 0, BattleFrontier_BattlePalaceCorridor_EventScript_WalkThroughCorridor
# 10 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	.2byte 0
# 11 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"

# 12 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
BattleFrontier_BattlePalaceCorridor_EventScript_WalkThroughCorridor::
# 13 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	delay 16
# 14 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattlePalaceCorridor_Movement_EnterCorridor
# 15 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattlePalaceCorridor_Movement_EnterCorridor
# 16 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	waitmovement 0
# 17 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	lockall
# 18 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	palace_getcomment
# 19 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	call_if_eq VAR_RESULT, 0, BattleFrontier_BattlePalaceCorridor_EventScript_RandomComment1
# 20 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	call_if_eq VAR_RESULT, 1, BattleFrontier_BattlePalaceCorridor_EventScript_RandomComment2
# 21 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	call_if_eq VAR_RESULT, 2, BattleFrontier_BattlePalaceCorridor_EventScript_RandomComment3
# 22 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	call_if_eq VAR_RESULT, 3, BattleFrontier_BattlePalaceCorridor_EventScript_StreakComment
# 23 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	call_if_eq VAR_RESULT, 4, BattleFrontier_BattlePalaceCorridor_EventScript_LongStreakComment
# 24 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	closemessage
# 25 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	frontier_get FRONTIER_DATA_LVL_MODE
# 26 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	goto_if_eq VAR_RESULT, FRONTIER_LVL_OPEN, BattleFrontier_BattlePalaceCorridor_EventScript_WalkToOpenBattleRoom
# 27 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattlePalaceCorridor_Movement_AttendantWalkTo50BattleRoom
# 28 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattlePalaceCorridor_Movement_PlayerWalkTo50BattleRoom
# 29 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	waitmovement 0
# 30 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	opendoor 6, 3
# 31 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	waitdooranim
# 32 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattlePalaceCorridor_Movement_AttendantEnterBattleRoom
# 33 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattlePalaceCorridor_Movement_PlayerEnterBattleRoom
# 34 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	waitmovement 0
# 35 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	closedoor 6, 3
# 36 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	waitdooranim
# 37 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	goto BattleFrontier_BattlePalaceCorridor_EventScript_WarpToBattleRoom
# 38 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"

# 39 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
BattleFrontier_BattlePalaceCorridor_EventScript_WalkToOpenBattleRoom::
# 40 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattlePalaceCorridor_Movement_AttendantWalkToOpenBattleRoom
# 41 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattlePalaceCorridor_Movement_PlayerWalkToOpenBattleRoom
# 42 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	waitmovement 0
# 43 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	opendoor 10, 3
# 44 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	waitdooranim
# 45 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattlePalaceCorridor_Movement_AttendantEnterBattleRoom
# 46 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattlePalaceCorridor_Movement_PlayerEnterBattleRoom
# 47 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	waitmovement 0
# 48 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	closedoor 10, 3
# 49 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	waitdooranim
# 50 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
BattleFrontier_BattlePalaceCorridor_EventScript_WarpToBattleRoom::
# 51 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_PALACE_BATTLE_ROOM, 7, 4
# 52 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	waitstate
# 53 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	end
# 54 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"

# 55 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
BattleFrontier_BattlePalaceCorridor_EventScript_RandomComment1::
# 56 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	msgbox BattleFrontier_BattlePalaceCorridor_Text_PeopleAndMonAreSame, MSGBOX_DEFAULT
# 57 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	return
# 58 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"

# 59 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
BattleFrontier_BattlePalaceCorridor_EventScript_RandomComment2::
# 60 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	msgbox BattleFrontier_BattlePalaceCorridor_Text_LetMonDoWhatItLikes, MSGBOX_DEFAULT
# 61 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	return
# 62 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"

# 63 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
BattleFrontier_BattlePalaceCorridor_EventScript_RandomComment3::
# 64 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	msgbox BattleFrontier_BattlePalaceCorridor_Text_MonDifferentWhenCornered, MSGBOX_DEFAULT
# 65 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	return
# 66 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"

# 67 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
BattleFrontier_BattlePalaceCorridor_EventScript_StreakComment::
# 68 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	msgbox BattleFrontier_BattlePalaceCorridor_Text_BeginningToUnderstandNature, MSGBOX_DEFAULT
# 69 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	return
# 70 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"

# 71 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
BattleFrontier_BattlePalaceCorridor_EventScript_LongStreakComment::
# 72 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	msgbox BattleFrontier_BattlePalaceCorridor_Text_HeartfeltBondBetweenYouAndMons, MSGBOX_DEFAULT
# 73 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	return
# 74 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"

# 75 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
BattleFrontier_BattlePalaceCorridor_Movement_EnterCorridor:
# 76 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	walk_up
# 77 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	walk_up
# 78 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	walk_up
# 79 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	walk_up
# 80 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	step_end
# 81 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"

# 82 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
BattleFrontier_BattlePalaceCorridor_Movement_AttendantWalkTo50BattleRoom:
# 83 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	walk_up
# 84 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	walk_up
# 85 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	walk_left
# 86 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	walk_left
# 87 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	walk_up
# 88 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	walk_up
# 89 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	step_end
# 90 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"

# 91 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
BattleFrontier_BattlePalaceCorridor_Movement_PlayerWalkTo50BattleRoom:
# 92 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	walk_up
# 93 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	walk_up
# 94 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	walk_up
# 95 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	walk_left
# 96 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	walk_left
# 97 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	walk_up
# 98 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	step_end
# 99 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"

# 100 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
BattleFrontier_BattlePalaceCorridor_Movement_AttendantWalkToOpenBattleRoom:
# 101 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	walk_up
# 102 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	walk_right
# 103 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	walk_right
# 104 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	walk_up
# 105 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	walk_up
# 106 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	walk_up
# 107 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	step_end
# 108 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"

# 109 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
BattleFrontier_BattlePalaceCorridor_Movement_PlayerWalkToOpenBattleRoom:
# 110 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	walk_up
# 111 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	walk_up
# 112 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	walk_right
# 113 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	walk_right
# 114 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	walk_up
# 115 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	walk_up
# 116 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	step_end
# 117 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"

# 118 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
BattleFrontier_BattlePalaceCorridor_Movement_PlayerEnterBattleRoom:
# 119 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	walk_up
# 120 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
BattleFrontier_BattlePalaceCorridor_Movement_AttendantEnterBattleRoom:
# 121 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	walk_up
# 122 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	set_invisible
# 123 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	step_end
# 124 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"

# 125 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
BattleFrontier_BattlePalaceCorridor_Text_PeopleAndMonAreSame:
# 126 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	.string "People and POKéMON, they are but\n"
# 127 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	.string "the same…\p"
# 128 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	.string "Their individual nature makes them\n"
# 129 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	.string "good at certain things, and not good\l"
# 130 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	.string "at others.$"
# 131 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"

# 132 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
BattleFrontier_BattlePalaceCorridor_Text_LetMonDoWhatItLikes:
# 133 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	.string "Rather than trying to make a POKéMON\n"
# 134 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	.string "do what it dislikes, try to let it do\l"
# 135 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	.string "what it likes and is good at doing.\p"
# 136 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	.string "Put yourself in the POKéMON's position\n"
# 137 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	.string "and consider what moves it would like.$"
# 138 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"

# 139 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
BattleFrontier_BattlePalaceCorridor_Text_MonDifferentWhenCornered:
# 140 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	.string "A POKéMON's nature is a remarkable\n"
# 141 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	.string "thing…\p"
# 142 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	.string "Some POKéMON behave in a completely\n"
# 143 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	.string "different way when they are cornered.$"
# 144 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"

# 145 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
BattleFrontier_BattlePalaceCorridor_Text_BeginningToUnderstandNature:
# 146 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	.string "Are you beginning to understand how\n"
# 147 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	.string "a POKéMON's nature makes it behave?$"
# 148 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"

# 149 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
BattleFrontier_BattlePalaceCorridor_Text_HeartfeltBondBetweenYouAndMons:
# 150 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	.string "Ah… I see a strong, heartfelt bond\n"
# 151 "data//maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	.string "between you and your POKéMON…$"
