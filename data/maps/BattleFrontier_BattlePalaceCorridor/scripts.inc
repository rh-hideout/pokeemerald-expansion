# 1 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"

# 2 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
BattleFrontier_BattlePalaceCorridor_MapScripts::
# 3 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePalaceCorridor_OnFrame
# 4 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	.byte 0
# 5 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"

# 6 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
BattleFrontier_BattlePalaceCorridor_OnFrame:
# 7 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	map_script_2 VAR_TEMP_0, 0, BattleFrontier_BattlePalaceCorridor_EventScript_WalkThroughCorridor
# 8 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	.2byte 0
# 9 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"

# 10 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
BattleFrontier_BattlePalaceCorridor_EventScript_WalkThroughCorridor::
# 11 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	delay 16
# 12 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	applymovement LOCALID_PALACE_CORRIDOR_ATTENDANT, BattleFrontier_BattlePalaceCorridor_Movement_EnterCorridor
# 13 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePalaceCorridor_Movement_EnterCorridor
# 14 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	waitmovement 0
# 15 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	lockall
# 16 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	palace_getcomment
# 17 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	call_if_eq VAR_RESULT, 0, BattleFrontier_BattlePalaceCorridor_EventScript_RandomComment1
# 18 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	call_if_eq VAR_RESULT, 1, BattleFrontier_BattlePalaceCorridor_EventScript_RandomComment2
# 19 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	call_if_eq VAR_RESULT, 2, BattleFrontier_BattlePalaceCorridor_EventScript_RandomComment3
# 20 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	call_if_eq VAR_RESULT, 3, BattleFrontier_BattlePalaceCorridor_EventScript_StreakComment
# 21 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	call_if_eq VAR_RESULT, 4, BattleFrontier_BattlePalaceCorridor_EventScript_LongStreakComment
# 22 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	closemessage
# 23 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	frontier_get FRONTIER_DATA_LVL_MODE
# 24 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	goto_if_eq VAR_RESULT, FRONTIER_LVL_OPEN, BattleFrontier_BattlePalaceCorridor_EventScript_WalkToOpenBattleRoom
# 25 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	applymovement LOCALID_PALACE_CORRIDOR_ATTENDANT, BattleFrontier_BattlePalaceCorridor_Movement_AttendantWalkTo50BattleRoom
# 26 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePalaceCorridor_Movement_PlayerWalkTo50BattleRoom
# 27 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	waitmovement 0
# 28 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	opendoor 6, 3
# 29 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	waitdooranim
# 30 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	applymovement LOCALID_PALACE_CORRIDOR_ATTENDANT, BattleFrontier_BattlePalaceCorridor_Movement_AttendantEnterBattleRoom
# 31 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePalaceCorridor_Movement_PlayerEnterBattleRoom
# 32 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	waitmovement 0
# 33 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	closedoor 6, 3
# 34 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	waitdooranim
# 35 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	goto BattleFrontier_BattlePalaceCorridor_EventScript_WarpToBattleRoom
# 36 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"

# 37 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
BattleFrontier_BattlePalaceCorridor_EventScript_WalkToOpenBattleRoom::
# 38 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	applymovement LOCALID_PALACE_CORRIDOR_ATTENDANT, BattleFrontier_BattlePalaceCorridor_Movement_AttendantWalkToOpenBattleRoom
# 39 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePalaceCorridor_Movement_PlayerWalkToOpenBattleRoom
# 40 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	waitmovement 0
# 41 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	opendoor 10, 3
# 42 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	waitdooranim
# 43 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	applymovement LOCALID_PALACE_CORRIDOR_ATTENDANT, BattleFrontier_BattlePalaceCorridor_Movement_AttendantEnterBattleRoom
# 44 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePalaceCorridor_Movement_PlayerEnterBattleRoom
# 45 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	waitmovement 0
# 46 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	closedoor 10, 3
# 47 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	waitdooranim
# 48 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
BattleFrontier_BattlePalaceCorridor_EventScript_WarpToBattleRoom::
# 49 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_PALACE_BATTLE_ROOM, 7, 4
# 50 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	waitstate
# 51 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	end
# 52 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"

# 53 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
BattleFrontier_BattlePalaceCorridor_EventScript_RandomComment1::
# 54 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	msgbox BattleFrontier_BattlePalaceCorridor_Text_PeopleAndMonAreSame, MSGBOX_DEFAULT
# 55 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	return
# 56 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"

# 57 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
BattleFrontier_BattlePalaceCorridor_EventScript_RandomComment2::
# 58 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	msgbox BattleFrontier_BattlePalaceCorridor_Text_LetMonDoWhatItLikes, MSGBOX_DEFAULT
# 59 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	return
# 60 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"

# 61 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
BattleFrontier_BattlePalaceCorridor_EventScript_RandomComment3::
# 62 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	msgbox BattleFrontier_BattlePalaceCorridor_Text_MonDifferentWhenCornered, MSGBOX_DEFAULT
# 63 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	return
# 64 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"

# 65 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
BattleFrontier_BattlePalaceCorridor_EventScript_StreakComment::
# 66 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	msgbox BattleFrontier_BattlePalaceCorridor_Text_BeginningToUnderstandNature, MSGBOX_DEFAULT
# 67 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	return
# 68 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"

# 69 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
BattleFrontier_BattlePalaceCorridor_EventScript_LongStreakComment::
# 70 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	msgbox BattleFrontier_BattlePalaceCorridor_Text_HeartfeltBondBetweenYouAndMons, MSGBOX_DEFAULT
# 71 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	return
# 72 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"

# 73 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
BattleFrontier_BattlePalaceCorridor_Movement_EnterCorridor:
# 74 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	walk_up
# 75 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	walk_up
# 76 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	walk_up
# 77 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	walk_up
# 78 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	step_end
# 79 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"

# 80 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
BattleFrontier_BattlePalaceCorridor_Movement_AttendantWalkTo50BattleRoom:
# 81 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	walk_up
# 82 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	walk_up
# 83 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	walk_left
# 84 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	walk_left
# 85 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	walk_up
# 86 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	walk_up
# 87 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	step_end
# 88 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"

# 89 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
BattleFrontier_BattlePalaceCorridor_Movement_PlayerWalkTo50BattleRoom:
# 90 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	walk_up
# 91 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	walk_up
# 92 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	walk_up
# 93 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	walk_left
# 94 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	walk_left
# 95 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	walk_up
# 96 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	step_end
# 97 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"

# 98 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
BattleFrontier_BattlePalaceCorridor_Movement_AttendantWalkToOpenBattleRoom:
# 99 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	walk_up
# 100 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	walk_right
# 101 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	walk_right
# 102 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	walk_up
# 103 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	walk_up
# 104 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	walk_up
# 105 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	step_end
# 106 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"

# 107 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
BattleFrontier_BattlePalaceCorridor_Movement_PlayerWalkToOpenBattleRoom:
# 108 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	walk_up
# 109 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	walk_up
# 110 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	walk_right
# 111 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	walk_right
# 112 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	walk_up
# 113 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	walk_up
# 114 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	step_end
# 115 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"

# 116 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
BattleFrontier_BattlePalaceCorridor_Movement_PlayerEnterBattleRoom:
# 117 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	walk_up
# 118 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
BattleFrontier_BattlePalaceCorridor_Movement_AttendantEnterBattleRoom:
# 119 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	walk_up
# 120 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	set_invisible
# 121 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	step_end
# 122 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"

# 123 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
BattleFrontier_BattlePalaceCorridor_Text_PeopleAndMonAreSame:
# 124 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	.string "People and POKéMON, they are but\n"
# 125 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	.string "the same…\p"
# 126 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	.string "Their individual nature makes them\n"
# 127 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	.string "good at certain things, and not good\l"
# 128 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	.string "at others.$"
# 129 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"

# 130 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
BattleFrontier_BattlePalaceCorridor_Text_LetMonDoWhatItLikes:
# 131 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	.string "Rather than trying to make a POKéMON\n"
# 132 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	.string "do what it dislikes, try to let it do\l"
# 133 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	.string "what it likes and is good at doing.\p"
# 134 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	.string "Put yourself in the POKéMON's position\n"
# 135 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	.string "and consider what moves it would like.$"
# 136 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"

# 137 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
BattleFrontier_BattlePalaceCorridor_Text_MonDifferentWhenCornered:
# 138 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	.string "A POKéMON's nature is a remarkable\n"
# 139 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	.string "thing…\p"
# 140 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	.string "Some POKéMON behave in a completely\n"
# 141 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	.string "different way when they are cornered.$"
# 142 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"

# 143 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
BattleFrontier_BattlePalaceCorridor_Text_BeginningToUnderstandNature:
# 144 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	.string "Are you beginning to understand how\n"
# 145 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	.string "a POKéMON's nature makes it behave?$"
# 146 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"

# 147 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
BattleFrontier_BattlePalaceCorridor_Text_HeartfeltBondBetweenYouAndMons:
# 148 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	.string "Ah… I see a strong, heartfelt bond\n"
# 149 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	.string "between you and your POKéMON…$"
