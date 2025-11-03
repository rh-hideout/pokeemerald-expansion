# 1 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 2 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_MapScripts::
# 3 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route110_TrickHousePuzzle5_OnTransition
# 4 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.byte 0
# 5 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 6 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_OnTransition:
# 7 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_1, 0
# 8 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_2, 0
# 9 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_3, 0
# 10 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_4, 0
# 11 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_5, 0
# 12 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_8, 0
# 13 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 14 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 15 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Scroll::
# 16 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	lockall
# 17 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_5_STATE, 0, Route110_TrickHousePuzzle5_EventScript_FoundScroll
# 18 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle_EventScript_ReadScrollAgain
# 19 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 20 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 21 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_FoundScroll::
# 22 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TRICK_HOUSE_PUZZLE_5_STATE, 1
# 23 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle_EventScript_FoundScroll
# 24 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 25 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 26 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll1::
# 27 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	lockall
# 28 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_1, Common_Movement_FacePlayer
# 29 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 30 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto_if_eq VAR_TEMP_1, 1, Route110_TrickHousePuzzle5_EventScript_CorrectGoThrough
# 31 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_9, 0
# 32 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll1Activate
# 33 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 34 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 35 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll2::
# 36 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	lockall
# 37 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_2, Common_Movement_FacePlayer
# 38 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 39 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto_if_eq VAR_TEMP_2, 1, Route110_TrickHousePuzzle5_EventScript_CorrectGoThrough
# 40 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_9, 0
# 41 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll2Activate
# 42 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 43 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 44 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll3::
# 45 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	lockall
# 46 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_3, Common_Movement_FacePlayer
# 47 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 48 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto_if_eq VAR_TEMP_3, 1, Route110_TrickHousePuzzle5_EventScript_CorrectGoThrough
# 49 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_9, 0
# 50 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll3Activate
# 51 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 52 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 53 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll4::
# 54 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	lockall
# 55 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_4, Common_Movement_FacePlayer
# 56 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 57 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto_if_eq VAR_TEMP_4, 1, Route110_TrickHousePuzzle5_EventScript_CorrectGoThrough
# 58 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_9, 0
# 59 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll4Activate
# 60 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 61 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 62 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll5::
# 63 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	lockall
# 64 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_5, Common_Movement_FacePlayer
# 65 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 66 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto_if_eq VAR_TEMP_5, 1, Route110_TrickHousePuzzle5_EventScript_CorrectGoThrough
# 67 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_9, 0
# 68 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll5Activate
# 69 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 70 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 71 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll1Trigger0::
# 72 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	lockall
# 73 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_9, 0
# 74 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll1Activate
# 75 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 76 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 77 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll1Trigger1::
# 78 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	lockall
# 79 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_9, 1
# 80 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll1Activate
# 81 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 82 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 83 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll1Trigger2::
# 84 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	lockall
# 85 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_9, 2
# 86 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll1Activate
# 87 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 88 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 89 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll1Trigger3::
# 90 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	lockall
# 91 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_9, 3
# 92 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll1Activate
# 93 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 94 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 95 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll1Trigger4::
# 96 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	lockall
# 97 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_9, 4
# 98 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll1Activate
# 99 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 100 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 101 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll2Trigger0::
# 102 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	lockall
# 103 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_9, 0
# 104 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll2Activate
# 105 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 106 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 107 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll2Trigger1::
# 108 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	lockall
# 109 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_9, 1
# 110 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll2Activate
# 111 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 112 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 113 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll2Trigger2::
# 114 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	lockall
# 115 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_9, 2
# 116 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll2Activate
# 117 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 118 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 119 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll2Trigger3::
# 120 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	lockall
# 121 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_9, 3
# 122 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll2Activate
# 123 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 124 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 125 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll2Trigger4::
# 126 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	lockall
# 127 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_9, 4
# 128 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll2Activate
# 129 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 130 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 131 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll2Trigger5::
# 132 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	lockall
# 133 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_9, 5
# 134 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll2Activate
# 135 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 136 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 137 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll3Trigger0::
# 138 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	lockall
# 139 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_9, 0
# 140 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll3Activate
# 141 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 142 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 143 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll3Trigger1::
# 144 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	lockall
# 145 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_9, 1
# 146 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll3Activate
# 147 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 148 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 149 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll3Trigger2::
# 150 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	lockall
# 151 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_9, 2
# 152 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll3Activate
# 153 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 154 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 155 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll3Trigger3::
# 156 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	lockall
# 157 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_9, 3
# 158 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll3Activate
# 159 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 160 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 161 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll3Trigger4::
# 162 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	lockall
# 163 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_9, 4
# 164 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll3Activate
# 165 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 166 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 167 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll4Trigger0::
# 168 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	lockall
# 169 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_9, 0
# 170 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll4Activate
# 171 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 172 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 173 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll4Trigger1::
# 174 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	lockall
# 175 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_9, 1
# 176 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll4Activate
# 177 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 178 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 179 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll4Trigger2::
# 180 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	lockall
# 181 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_9, 2
# 182 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll4Activate
# 183 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 184 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 185 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll4Trigger3::
# 186 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	lockall
# 187 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_9, 3
# 188 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll4Activate
# 189 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 190 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 191 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll4Trigger4::
# 192 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	lockall
# 193 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_9, 4
# 194 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll4Activate
# 195 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 196 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 197 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
@ Unused
# 198 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll4Trigger5::
# 199 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	lockall
# 200 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_9, 5
# 201 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll4Activate
# 202 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 203 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 204 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll5Trigger0::
# 205 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	lockall
# 206 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_9, 0
# 207 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll5Activate
# 208 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 209 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 210 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll1Activate::
# 211 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_1, 1
# 212 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_8, LOCALID_MECHADOLL_1
# 213 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	playse SE_PIN
# 214 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_1, Common_Movement_ExclamationMark
# 215 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 216 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_1, Common_Movement_Delay48
# 217 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 218 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_9, 1, Route110_TrickHousePuzzle5_EventScript_MechadollWalkLeft1
# 219 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_9, 2, Route110_TrickHousePuzzle5_EventScript_MechadollWalkLeft2
# 220 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_9, 3, Route110_TrickHousePuzzle5_EventScript_MechadollWalkLeft3
# 221 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_9, 4, Route110_TrickHousePuzzle5_EventScript_MechadollWalkLeft4
# 222 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	msgbox Route110_TrickHousePuzzle5_Text_Mechadoll1Intro, MSGBOX_DEFAULT
# 223 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	random 3
# 224 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	switch VAR_RESULT
# 225 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	case 0, Route110_TrickHousePuzzle5_EventScript_Mechadoll1Quiz1
# 226 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	case 1, Route110_TrickHousePuzzle5_EventScript_Mechadoll1Quiz2
# 227 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	case 2, Route110_TrickHousePuzzle5_EventScript_Mechadoll1Quiz3
# 228 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 229 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 230 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll2Activate::
# 231 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_2, 1
# 232 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_8, LOCALID_MECHADOLL_2
# 233 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	playse SE_PIN
# 234 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_2, Common_Movement_ExclamationMark
# 235 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 236 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_2, Common_Movement_Delay48
# 237 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 238 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_9, 1, Route110_TrickHousePuzzle5_EventScript_MechadollWalkRight1
# 239 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_9, 2, Route110_TrickHousePuzzle5_EventScript_MechadollWalkRight2
# 240 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_9, 3, Route110_TrickHousePuzzle5_EventScript_MechadollWalkRight3
# 241 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_9, 4, Route110_TrickHousePuzzle5_EventScript_MechadollWalkRight4
# 242 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_9, 5, Route110_TrickHousePuzzle5_EventScript_MechadollWalkRight5
# 243 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	msgbox Route110_TrickHousePuzzle5_Text_Mechadoll2Intro, MSGBOX_DEFAULT
# 244 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	random 3
# 245 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	switch VAR_RESULT
# 246 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	case 0, Route110_TrickHousePuzzle5_EventScript_Mechadoll2Quiz1
# 247 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	case 1, Route110_TrickHousePuzzle5_EventScript_Mechadoll2Quiz2
# 248 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	case 2, Route110_TrickHousePuzzle5_EventScript_Mechadoll2Quiz3
# 249 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 250 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 251 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll3Activate::
# 252 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_3, 1
# 253 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_8, LOCALID_MECHADOLL_3
# 254 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	playse SE_PIN
# 255 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_3, Common_Movement_ExclamationMark
# 256 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 257 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_3, Common_Movement_Delay48
# 258 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 259 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_9, 1, Route110_TrickHousePuzzle5_EventScript_MechadollWalkLeft1
# 260 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_9, 2, Route110_TrickHousePuzzle5_EventScript_MechadollWalkLeft2
# 261 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_9, 3, Route110_TrickHousePuzzle5_EventScript_MechadollWalkLeft3
# 262 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_9, 4, Route110_TrickHousePuzzle5_EventScript_MechadollWalkLeft4
# 263 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	msgbox Route110_TrickHousePuzzle5_Text_Mechadoll3Intro, MSGBOX_DEFAULT
# 264 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	random 3
# 265 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	switch VAR_RESULT
# 266 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	case 0, Route110_TrickHousePuzzle5_EventScript_Mechadoll3Quiz1
# 267 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	case 1, Route110_TrickHousePuzzle5_EventScript_Mechadoll3Quiz2
# 268 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	case 2, Route110_TrickHousePuzzle5_EventScript_Mechadoll3Quiz3
# 269 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 270 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 271 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll4Activate::
# 272 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_4, 1
# 273 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_8, LOCALID_MECHADOLL_4
# 274 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	playse SE_PIN
# 275 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_4, Common_Movement_ExclamationMark
# 276 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 277 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_4, Common_Movement_Delay48
# 278 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 279 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_9, 1, Route110_TrickHousePuzzle5_EventScript_MechadollWalkLeft1
# 280 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_9, 2, Route110_TrickHousePuzzle5_EventScript_MechadollWalkLeft2
# 281 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_9, 3, Route110_TrickHousePuzzle5_EventScript_MechadollWalkLeft3
# 282 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_9, 4, Route110_TrickHousePuzzle5_EventScript_MechadollWalkLeft4
# 283 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	msgbox Route110_TrickHousePuzzle5_Text_Mechadoll4Intro, MSGBOX_DEFAULT
# 284 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	random 3
# 285 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	switch VAR_RESULT
# 286 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	case 0, Route110_TrickHousePuzzle5_EventScript_Mechadoll4Quiz1
# 287 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	case 1, Route110_TrickHousePuzzle5_EventScript_Mechadoll4Quiz2
# 288 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	case 2, Route110_TrickHousePuzzle5_EventScript_Mechadoll4Quiz3
# 289 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 290 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 291 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll5Activate::
# 292 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_5, 1
# 293 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_8, LOCALID_MECHADOLL_5
# 294 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	playse SE_PIN
# 295 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_5, Common_Movement_ExclamationMark
# 296 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 297 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_5, Common_Movement_Delay48
# 298 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 299 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	msgbox Route110_TrickHousePuzzle5_Text_Mechadoll5Intro, MSGBOX_DEFAULT
# 300 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	random 3
# 301 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	switch VAR_RESULT
# 302 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	case 0, Route110_TrickHousePuzzle5_EventScript_Mechadoll5Quiz1
# 303 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	case 1, Route110_TrickHousePuzzle5_EventScript_Mechadoll5Quiz2
# 304 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	case 2, Route110_TrickHousePuzzle5_EventScript_Mechadoll5Quiz3
# 305 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 306 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 307 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll1Quiz1::
# 308 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	msgbox Route110_TrickHousePuzzle5_Text_Mechadoll1Quiz1, MSGBOX_DEFAULT
# 309 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	multichoice 0, 0, MULTI_MECHADOLL1_Q1, TRUE
# 310 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	switch VAR_RESULT
# 311 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	case 2, Route110_TrickHousePuzzle5_EventScript_CorrectAnswer
# 312 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_IncorrectAnswer
# 313 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 314 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 315 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll1Quiz2::
# 316 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	msgbox Route110_TrickHousePuzzle5_Text_Mechadoll1Quiz2, MSGBOX_DEFAULT
# 317 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	multichoice 0, 0, MULTI_MECHADOLL1_Q2, TRUE
# 318 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	switch VAR_RESULT
# 319 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	case 0, Route110_TrickHousePuzzle5_EventScript_CorrectAnswer
# 320 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_IncorrectAnswer
# 321 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 322 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 323 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll1Quiz3::
# 324 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	msgbox Route110_TrickHousePuzzle5_Text_Mechadoll1Quiz3, MSGBOX_DEFAULT
# 325 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	multichoice 0, 0, MULTI_MECHADOLL1_Q3, TRUE
# 326 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	switch VAR_RESULT
# 327 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	case 0, Route110_TrickHousePuzzle5_EventScript_CorrectAnswer
# 328 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_IncorrectAnswer
# 329 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 330 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 331 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll2Quiz1::
# 332 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	msgbox Route110_TrickHousePuzzle5_Text_Mechadoll2Quiz1, MSGBOX_DEFAULT
# 333 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	multichoice 0, 0, MULTI_MECHADOLL2_Q1, TRUE
# 334 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	switch VAR_RESULT
# 335 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	case 1, Route110_TrickHousePuzzle5_EventScript_CorrectAnswer
# 336 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_IncorrectAnswer
# 337 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 338 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 339 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll2Quiz2::
# 340 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	msgbox Route110_TrickHousePuzzle5_Text_Mechadoll2Quiz2, MSGBOX_DEFAULT
# 341 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	multichoice 0, 0, MULTI_MECHADOLL2_Q2, TRUE
# 342 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	switch VAR_RESULT
# 343 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	case 2, Route110_TrickHousePuzzle5_EventScript_CorrectAnswer
# 344 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_IncorrectAnswer
# 345 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 346 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 347 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll2Quiz3::
# 348 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	msgbox Route110_TrickHousePuzzle5_Text_Mechadoll2Quiz3, MSGBOX_DEFAULT
# 349 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	multichoice 0, 0, MULTI_MECHADOLL2_Q3, TRUE
# 350 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	switch VAR_RESULT
# 351 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	case 0, Route110_TrickHousePuzzle5_EventScript_CorrectAnswer
# 352 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_IncorrectAnswer
# 353 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 354 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 355 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll3Quiz1::
# 356 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	msgbox Route110_TrickHousePuzzle5_Text_Mechadoll3Quiz1, MSGBOX_DEFAULT
# 357 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	multichoice 0, 0, MULTI_MECHADOLL3_Q1, TRUE
# 358 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	switch VAR_RESULT
# 359 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	case 0, Route110_TrickHousePuzzle5_EventScript_CorrectAnswer
# 360 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_IncorrectAnswer
# 361 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 362 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 363 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll3Quiz2::
# 364 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	msgbox Route110_TrickHousePuzzle5_Text_Mechadoll3Quiz2, MSGBOX_DEFAULT
# 365 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	multichoice 0, 0, MULTI_MECHADOLL3_Q2, TRUE
# 366 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	switch VAR_RESULT
# 367 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	case 2, Route110_TrickHousePuzzle5_EventScript_CorrectAnswer
# 368 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_IncorrectAnswer
# 369 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 370 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 371 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll3Quiz3::
# 372 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	msgbox Route110_TrickHousePuzzle5_Text_Mechadoll3Quiz3, MSGBOX_DEFAULT
# 373 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	multichoice 0, 0, MULTI_MECHADOLL3_Q3, TRUE
# 374 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	switch VAR_RESULT
# 375 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	case 1, Route110_TrickHousePuzzle5_EventScript_CorrectAnswer
# 376 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_IncorrectAnswer
# 377 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 378 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 379 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll4Quiz1::
# 380 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	msgbox Route110_TrickHousePuzzle5_Text_Mechadoll4Quiz1, MSGBOX_DEFAULT
# 381 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	multichoice 0, 0, MULTI_MECHADOLL4_Q1, TRUE
# 382 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	switch VAR_RESULT
# 383 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	case 0, Route110_TrickHousePuzzle5_EventScript_CorrectAnswer
# 384 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_IncorrectAnswer
# 385 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 386 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 387 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll4Quiz2::
# 388 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	msgbox Route110_TrickHousePuzzle5_Text_Mechadoll4Quiz2, MSGBOX_DEFAULT
# 389 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	multichoice 0, 0, MULTI_MECHADOLL4_Q2, TRUE
# 390 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	switch VAR_RESULT
# 391 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	case 0, Route110_TrickHousePuzzle5_EventScript_CorrectAnswer
# 392 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_IncorrectAnswer
# 393 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 394 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 395 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll4Quiz3::
# 396 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	msgbox Route110_TrickHousePuzzle5_Text_Mechadoll4Quiz3, MSGBOX_DEFAULT
# 397 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	multichoice 0, 0, MULTI_MECHADOLL4_Q3, TRUE
# 398 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	switch VAR_RESULT
# 399 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	case 1, Route110_TrickHousePuzzle5_EventScript_CorrectAnswer
# 400 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_IncorrectAnswer
# 401 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 402 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 403 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll5Quiz1::
# 404 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	msgbox Route110_TrickHousePuzzle5_Text_Mechadoll5Quiz1, MSGBOX_DEFAULT
# 405 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	multichoice 0, 0, MULTI_MECHADOLL5_Q1, TRUE
# 406 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	switch VAR_RESULT
# 407 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	case 1, Route110_TrickHousePuzzle5_EventScript_CorrectAnswer
# 408 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_IncorrectAnswer
# 409 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 410 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 411 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll5Quiz2::
# 412 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	msgbox Route110_TrickHousePuzzle5_Text_Mechadoll5Quiz2, MSGBOX_DEFAULT
# 413 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	multichoice 0, 0, MULTI_MECHADOLL5_Q2, TRUE
# 414 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	switch VAR_RESULT
# 415 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	case 0, Route110_TrickHousePuzzle5_EventScript_CorrectAnswer
# 416 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_IncorrectAnswer
# 417 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 418 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 419 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll5Quiz3::
# 420 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	msgbox Route110_TrickHousePuzzle5_Text_Mechadoll5Quiz3, MSGBOX_DEFAULT
# 421 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	multichoice 0, 0, MULTI_MECHADOLL5_Q3, TRUE
# 422 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	switch VAR_RESULT
# 423 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	case 2, Route110_TrickHousePuzzle5_EventScript_CorrectAnswer
# 424 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_IncorrectAnswer
# 425 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 426 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 427 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_IncorrectAnswer::
# 428 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitse
# 429 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	playse SE_FAILURE
# 430 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	msgbox Route110_TrickHousePuzzle5_Text_DisappointmentError, MSGBOX_DEFAULT
# 431 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_1, Route110_TrickHousePuzzle5_Movement_MechadollShake
# 432 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_2, Route110_TrickHousePuzzle5_Movement_MechadollShake
# 433 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_3, Route110_TrickHousePuzzle5_Movement_MechadollShake
# 434 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_4, Route110_TrickHousePuzzle5_Movement_MechadollShake
# 435 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_5, Route110_TrickHousePuzzle5_Movement_MechadollShake
# 436 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	msgbox Route110_TrickHousePuzzle5_Text_Wahahahaha, MSGBOX_DEFAULT
# 437 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 438 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	msgbox Route110_TrickHousePuzzle5_Text_WaitForNextChallenge, MSGBOX_DEFAULT
# 439 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	closemessage
# 440 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	warp MAP_ROUTE110_TRICK_HOUSE_PUZZLE5, 0, 21
# 441 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitstate
# 442 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	releaseall
# 443 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 444 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 445 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_CorrectAnswer::
# 446 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitse
# 447 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	playse SE_SUCCESS
# 448 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_CorrectGoThrough
# 449 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 450 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 451 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_CorrectGoThrough::
# 452 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	msgbox Route110_TrickHousePuzzle5_Text_CorrectGoThrough, MSGBOX_DEFAULT
# 453 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	releaseall
# 454 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 455 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 456 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
@ Absurd redundancy in movement scripts that could be resolved by using VAR_TEMP_8 for applymovement instead
# 457 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
@ Many of the below movement scripts arent even used, see below
# 458 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
@   Mechadoll 2 is the only mechadoll to walk right, all the other WalkRight scripts are unused
# 459 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
@   Mechadoll 5 never walks, all the Mechadoll5Walk scripts are unused
# 460 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
@   No mechadoll walks left 5 paces, all the WalkLeft5 scripts are unused
# 461 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_MechadollWalkLeft1::
# 462 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_1, Route110_TrickHousePuzzle5_EventScript_Mechadoll1WalkLeft1
# 463 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_2, Route110_TrickHousePuzzle5_EventScript_Mechadoll2WalkLeft1
# 464 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_3, Route110_TrickHousePuzzle5_EventScript_Mechadoll3WalkLeft1
# 465 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_4, Route110_TrickHousePuzzle5_EventScript_Mechadoll4WalkLeft1
# 466 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_5, Route110_TrickHousePuzzle5_EventScript_Mechadoll5WalkLeft1
# 467 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 468 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 469 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_MechadollWalkLeft2::
# 470 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_1, Route110_TrickHousePuzzle5_EventScript_Mechadoll1WalkLeft2
# 471 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_2, Route110_TrickHousePuzzle5_EventScript_Mechadoll2WalkLeft2
# 472 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_3, Route110_TrickHousePuzzle5_EventScript_Mechadoll3WalkLeft2
# 473 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_4, Route110_TrickHousePuzzle5_EventScript_Mechadoll4WalkLeft2
# 474 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_5, Route110_TrickHousePuzzle5_EventScript_Mechadoll5WalkLeft2
# 475 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 476 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 477 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_MechadollWalkLeft3::
# 478 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_1, Route110_TrickHousePuzzle5_EventScript_Mechadoll1WalkLeft3
# 479 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_2, Route110_TrickHousePuzzle5_EventScript_Mechadoll2WalkLeft3
# 480 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_3, Route110_TrickHousePuzzle5_EventScript_Mechadoll3WalkLeft3
# 481 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_4, Route110_TrickHousePuzzle5_EventScript_Mechadoll4WalkLeft3
# 482 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_5, Route110_TrickHousePuzzle5_EventScript_Mechadoll5WalkLeft3
# 483 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 484 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 485 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_MechadollWalkLeft4::
# 486 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_1, Route110_TrickHousePuzzle5_EventScript_Mechadoll1WalkLeft4
# 487 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_2, Route110_TrickHousePuzzle5_EventScript_Mechadoll2WalkLeft4
# 488 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_3, Route110_TrickHousePuzzle5_EventScript_Mechadoll3WalkLeft4
# 489 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_4, Route110_TrickHousePuzzle5_EventScript_Mechadoll4WalkLeft4
# 490 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_5, Route110_TrickHousePuzzle5_EventScript_Mechadoll5WalkLeft4
# 491 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 492 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 493 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_MechadollWalkLeft5::
# 494 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_1, Route110_TrickHousePuzzle5_EventScript_Mechadoll1WalkLeft5
# 495 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_2, Route110_TrickHousePuzzle5_EventScript_Mechadoll2WalkLeft5
# 496 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_3, Route110_TrickHousePuzzle5_EventScript_Mechadoll3WalkLeft5
# 497 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_4, Route110_TrickHousePuzzle5_EventScript_Mechadoll4WalkLeft5
# 498 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_5, Route110_TrickHousePuzzle5_EventScript_Mechadoll5WalkLeft5
# 499 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 500 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 501 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_MechadollWalkRight1::
# 502 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_1, Route110_TrickHousePuzzle5_EventScript_Mechadoll1WalkRight1
# 503 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_2, Route110_TrickHousePuzzle5_EventScript_Mechadoll2WalkRight1
# 504 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_3, Route110_TrickHousePuzzle5_EventScript_Mechadoll3WalkRight1
# 505 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_4, Route110_TrickHousePuzzle5_EventScript_Mechadoll4WalkRight1
# 506 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_5, Route110_TrickHousePuzzle5_EventScript_Mechadoll5WalkRight1
# 507 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 508 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 509 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_MechadollWalkRight2::
# 510 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_1, Route110_TrickHousePuzzle5_EventScript_Mechadoll1WalkRight2
# 511 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_2, Route110_TrickHousePuzzle5_EventScript_Mechadoll2WalkRight2
# 512 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_3, Route110_TrickHousePuzzle5_EventScript_Mechadoll3WalkRight2
# 513 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_4, Route110_TrickHousePuzzle5_EventScript_Mechadoll4WalkRight2
# 514 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_5, Route110_TrickHousePuzzle5_EventScript_Mechadoll5WalkRight2
# 515 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 516 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 517 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_MechadollWalkRight3::
# 518 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_1, Route110_TrickHousePuzzle5_EventScript_Mechadoll1WalkRight3
# 519 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_2, Route110_TrickHousePuzzle5_EventScript_Mechadoll2WalkRight3
# 520 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_3, Route110_TrickHousePuzzle5_EventScript_Mechadoll3WalkRight3
# 521 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_4, Route110_TrickHousePuzzle5_EventScript_Mechadoll4WalkRight3
# 522 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_5, Route110_TrickHousePuzzle5_EventScript_Mechadoll5WalkRight3
# 523 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 524 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 525 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_MechadollWalkRight4::
# 526 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_1, Route110_TrickHousePuzzle5_EventScript_Mechadoll1WalkRight4
# 527 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_2, Route110_TrickHousePuzzle5_EventScript_Mechadoll2WalkRight4
# 528 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_3, Route110_TrickHousePuzzle5_EventScript_Mechadoll3WalkRight4
# 529 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_4, Route110_TrickHousePuzzle5_EventScript_Mechadoll4WalkRight4
# 530 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_5, Route110_TrickHousePuzzle5_EventScript_Mechadoll5WalkRight4
# 531 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 532 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 533 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_MechadollWalkRight5::
# 534 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_1, Route110_TrickHousePuzzle5_EventScript_Mechadoll1WalkRight5
# 535 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_2, Route110_TrickHousePuzzle5_EventScript_Mechadoll2WalkRight5
# 536 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_3, Route110_TrickHousePuzzle5_EventScript_Mechadoll3WalkRight5
# 537 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_4, Route110_TrickHousePuzzle5_EventScript_Mechadoll4WalkRight5
# 538 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_5, Route110_TrickHousePuzzle5_EventScript_Mechadoll5WalkRight5
# 539 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 540 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 541 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll1WalkLeft1::
# 542 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_1, Route110_TrickHousePuzzle5_Movement_WalkLeft1
# 543 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 544 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 545 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 546 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll2WalkLeft1::
# 547 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_2, Route110_TrickHousePuzzle5_Movement_WalkLeft1
# 548 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 549 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 550 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 551 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll3WalkLeft1::
# 552 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_3, Route110_TrickHousePuzzle5_Movement_WalkLeft1
# 553 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 554 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 555 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 556 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll4WalkLeft1::
# 557 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_4, Route110_TrickHousePuzzle5_Movement_WalkLeft1
# 558 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 559 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 560 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 561 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll5WalkLeft1::
# 562 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_5, Route110_TrickHousePuzzle5_Movement_WalkLeft1
# 563 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 564 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 565 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 566 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll1WalkLeft2::
# 567 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_1, Route110_TrickHousePuzzle5_Movement_WalkLeft2
# 568 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 569 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 570 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 571 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll2WalkLeft2::
# 572 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_2, Route110_TrickHousePuzzle5_Movement_WalkLeft2
# 573 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 574 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 575 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 576 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll3WalkLeft2::
# 577 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_3, Route110_TrickHousePuzzle5_Movement_WalkLeft2
# 578 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 579 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 580 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 581 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll4WalkLeft2::
# 582 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_4, Route110_TrickHousePuzzle5_Movement_WalkLeft2
# 583 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 584 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 585 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 586 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll5WalkLeft2::
# 587 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_5, Route110_TrickHousePuzzle5_Movement_WalkLeft2
# 588 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 589 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 590 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 591 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll1WalkLeft3::
# 592 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_1, Route110_TrickHousePuzzle5_Movement_WalkLeft3
# 593 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 594 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 595 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 596 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll2WalkLeft3::
# 597 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_2, Route110_TrickHousePuzzle5_Movement_WalkLeft3
# 598 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 599 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 600 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 601 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll3WalkLeft3::
# 602 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_3, Route110_TrickHousePuzzle5_Movement_WalkLeft3
# 603 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 604 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 605 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 606 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll4WalkLeft3::
# 607 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_4, Route110_TrickHousePuzzle5_Movement_WalkLeft3
# 608 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 609 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 610 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 611 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll5WalkLeft3::
# 612 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_5, Route110_TrickHousePuzzle5_Movement_WalkLeft3
# 613 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 614 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 615 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 616 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll1WalkLeft4::
# 617 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_1, Route110_TrickHousePuzzle5_Movement_WalkLeft4
# 618 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 619 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 620 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 621 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll2WalkLeft4::
# 622 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_2, Route110_TrickHousePuzzle5_Movement_WalkLeft4
# 623 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 624 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 625 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 626 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll3WalkLeft4::
# 627 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_3, Route110_TrickHousePuzzle5_Movement_WalkLeft4
# 628 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 629 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 630 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 631 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll4WalkLeft4::
# 632 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_4, Route110_TrickHousePuzzle5_Movement_WalkLeft4
# 633 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 634 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 635 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 636 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll5WalkLeft4::
# 637 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_5, Route110_TrickHousePuzzle5_Movement_WalkLeft4
# 638 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 639 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 640 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 641 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll1WalkLeft5::
# 642 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_1, Route110_TrickHousePuzzle5_Movement_WalkLeft5
# 643 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 644 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 645 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 646 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll2WalkLeft5::
# 647 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_2, Route110_TrickHousePuzzle5_Movement_WalkLeft5
# 648 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 649 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 650 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 651 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll3WalkLeft5::
# 652 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_3, Route110_TrickHousePuzzle5_Movement_WalkLeft5
# 653 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 654 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 655 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 656 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll4WalkLeft5::
# 657 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_4, Route110_TrickHousePuzzle5_Movement_WalkLeft5
# 658 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 659 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 660 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 661 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll5WalkLeft5::
# 662 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_5, Route110_TrickHousePuzzle5_Movement_WalkLeft5
# 663 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 664 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 665 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 666 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll1WalkRight1::
# 667 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_1, Route110_TrickHousePuzzle5_Movement_WalkRight1
# 668 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 669 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 670 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 671 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll2WalkRight1::
# 672 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_2, Route110_TrickHousePuzzle5_Movement_WalkRight1
# 673 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 674 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 675 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 676 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll3WalkRight1::
# 677 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_3, Route110_TrickHousePuzzle5_Movement_WalkRight1
# 678 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 679 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 680 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 681 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll4WalkRight1::
# 682 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_4, Route110_TrickHousePuzzle5_Movement_WalkRight1
# 683 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 684 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 685 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 686 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll5WalkRight1::
# 687 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_5, Route110_TrickHousePuzzle5_Movement_WalkRight1
# 688 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 689 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 690 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 691 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll1WalkRight2::
# 692 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_1, Route110_TrickHousePuzzle5_Movement_WalkRight2
# 693 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 694 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 695 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 696 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll2WalkRight2::
# 697 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_2, Route110_TrickHousePuzzle5_Movement_WalkRight2
# 698 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 699 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 700 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 701 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll3WalkRight2::
# 702 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_3, Route110_TrickHousePuzzle5_Movement_WalkRight2
# 703 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 704 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 705 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 706 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll4WalkRight2::
# 707 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_4, Route110_TrickHousePuzzle5_Movement_WalkRight2
# 708 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 709 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 710 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 711 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll5WalkRight2::
# 712 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_5, Route110_TrickHousePuzzle5_Movement_WalkRight2
# 713 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 714 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 715 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 716 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll1WalkRight3::
# 717 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_1, Route110_TrickHousePuzzle5_Movement_WalkRight3
# 718 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 719 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 720 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 721 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll2WalkRight3::
# 722 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_2, Route110_TrickHousePuzzle5_Movement_WalkRight3
# 723 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 724 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 725 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 726 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll3WalkRight3::
# 727 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_3, Route110_TrickHousePuzzle5_Movement_WalkRight3
# 728 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 729 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 730 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 731 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll4WalkRight3::
# 732 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_4, Route110_TrickHousePuzzle5_Movement_WalkRight3
# 733 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 734 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 735 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 736 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll5WalkRight3::
# 737 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_5, Route110_TrickHousePuzzle5_Movement_WalkRight3
# 738 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 739 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 740 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 741 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll1WalkRight4::
# 742 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_1, Route110_TrickHousePuzzle5_Movement_WalkRight4
# 743 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 744 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 745 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 746 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll2WalkRight4::
# 747 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_2, Route110_TrickHousePuzzle5_Movement_WalkRight4
# 748 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 749 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 750 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 751 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll3WalkRight4::
# 752 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_3, Route110_TrickHousePuzzle5_Movement_WalkRight4
# 753 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 754 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 755 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 756 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll4WalkRight4::
# 757 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_4, Route110_TrickHousePuzzle5_Movement_WalkRight4
# 758 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 759 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 760 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 761 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll5WalkRight4::
# 762 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_5, Route110_TrickHousePuzzle5_Movement_WalkRight4
# 763 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 764 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 765 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 766 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll1WalkRight5::
# 767 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_1, Route110_TrickHousePuzzle5_Movement_WalkRight5
# 768 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 769 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 770 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 771 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll2WalkRight5::
# 772 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_2, Route110_TrickHousePuzzle5_Movement_WalkRight5
# 773 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 774 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 775 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 776 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll3WalkRight5::
# 777 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_3, Route110_TrickHousePuzzle5_Movement_WalkRight5
# 778 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 779 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 780 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 781 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll4WalkRight5::
# 782 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_4, Route110_TrickHousePuzzle5_Movement_WalkRight5
# 783 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 784 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 785 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 786 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll5WalkRight5::
# 787 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_5, Route110_TrickHousePuzzle5_Movement_WalkRight5
# 788 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 789 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 790 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 791 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_Movement_WalkLeft1:
# 792 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	walk_left
# 793 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	step_end
# 794 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 795 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_Movement_WalkLeft2:
# 796 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	walk_left
# 797 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	walk_left
# 798 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	step_end
# 799 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 800 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_Movement_WalkLeft3:
# 801 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	walk_left
# 802 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	walk_left
# 803 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	walk_left
# 804 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	step_end
# 805 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 806 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_Movement_WalkLeft4:
# 807 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	walk_left
# 808 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	walk_left
# 809 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	walk_left
# 810 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	walk_left
# 811 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	step_end
# 812 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 813 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_Movement_WalkLeft5:
# 814 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	walk_left
# 815 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	walk_left
# 816 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	walk_left
# 817 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	walk_left
# 818 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	walk_left
# 819 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	step_end
# 820 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 821 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_Movement_WalkRight1:
# 822 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	walk_right
# 823 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	step_end
# 824 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 825 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_Movement_WalkRight2:
# 826 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	walk_right
# 827 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	walk_right
# 828 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	step_end
# 829 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 830 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_Movement_WalkRight3:
# 831 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	walk_right
# 832 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	walk_right
# 833 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	walk_right
# 834 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	step_end
# 835 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 836 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_Movement_WalkRight4:
# 837 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	walk_right
# 838 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	walk_right
# 839 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	walk_right
# 840 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	walk_right
# 841 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	step_end
# 842 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 843 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_Movement_WalkRight5:
# 844 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	walk_right
# 845 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	walk_right
# 846 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	walk_right
# 847 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	walk_right
# 848 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	walk_right
# 849 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	step_end
# 850 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 851 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_Movement_MechadollShake:
# 852 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	face_left
# 853 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	delay_2
# 854 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	face_right
# 855 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	delay_2
# 856 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	face_left
# 857 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	delay_2
# 858 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	face_right
# 859 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	delay_2
# 860 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	face_left
# 861 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	delay_2
# 862 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	face_right
# 863 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	delay_2
# 864 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	face_left
# 865 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	delay_2
# 866 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	face_right
# 867 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	delay_2
# 868 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	face_left
# 869 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	delay_2
# 870 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	face_right
# 871 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	delay_2
# 872 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	face_left
# 873 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	delay_2
# 874 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	face_right
# 875 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	delay_2
# 876 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	face_left
# 877 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	delay_2
# 878 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	face_right
# 879 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	delay_2
# 880 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	face_left
# 881 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	delay_2
# 882 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	face_right
# 883 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	delay_2
# 884 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	face_left
# 885 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	delay_2
# 886 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	face_right
# 887 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	delay_2
# 888 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	face_left
# 889 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	delay_2
# 890 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	face_right
# 891 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	delay_2
# 892 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	face_left
# 893 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	delay_2
# 894 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	face_right
# 895 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	delay_2
# 896 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	face_down
# 897 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	step_end
# 898 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 899 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_Text_WroteSecretCodeLockOpened:
# 900 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "{PLAYER} wrote down the secret code\n"
# 901 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "on the door.\p"
# 902 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "“TRICK MASTER is a genius.”\n"
# 903 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "… … … … … … … …\p"
# 904 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "The lock clicked open!$"
# 905 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 906 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_Text_Mechadoll1Intro:
# 907 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "CLICKETY-CLACK…\n"
# 908 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "MECHADOLL 1 AM I!\p"
# 909 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "IF YOU ANSWER QUIZZES CORRECTLY,\n"
# 910 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "THEN YOU WILL GO TO MECHADOLL 5.\l"
# 911 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "THEN YOU CAN OBTAIN THE SECRET CODE.$"
# 912 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 913 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_Text_Mechadoll1Quiz1:
# 914 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "MECHADOLL 1 QUIZ.\p"
# 915 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "One of these POKéMON is not found\n"
# 916 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "on ROUTE 110. Which one is it?$"
# 917 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 918 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_Text_Mechadoll1Quiz2:
# 919 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "MECHADOLL 1 QUIZ.\p"
# 920 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "One of these POKéMON is not of the\n"
# 921 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "WATER type. Which one is it?$"
# 922 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 923 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_Text_Mechadoll1Quiz3:
# 924 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "MECHADOLL 1 QUIZ.\p"
# 925 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "One of these POKéMON does not use\n"
# 926 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "LEECH LIFE. Which one is it?$"
# 927 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 928 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_Text_CorrectGoThrough:
# 929 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "CONGRATULATIONS. CORRECT YOU ARE.\n"
# 930 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "GO THROUGH. PLEASE.$"
# 931 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 932 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_Text_DisappointmentError:
# 933 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "BZZZT. DISAPPOINTMENT.\n"
# 934 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "ERROR.$"
# 935 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 936 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_Text_Wahahahaha:
# 937 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "WAHAHAHAHA! WAHAHAHAHA!\n"
# 938 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "CLICKETY-CLACK!$"
# 939 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 940 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_Text_WaitForNextChallenge:
# 941 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "YOUR NEXT CHALLENGE WE WAIT FOR.$"
# 942 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 943 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_Text_Mechadoll2Intro:
# 944 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "CLICKETY-CLACK…\n"
# 945 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "MECHADOLL 2 AM I!\p"
# 946 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "MECHADOLL 1'S QUIZ DIFFICULTY LEVEL\n"
# 947 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "IS SET TOO LOW.$"
# 948 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 949 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_Text_Mechadoll2Quiz1:
# 950 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "MECHADOLL 2 QUIZ.\p"
# 951 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "Which of these POKéMON did WALLY\n"
# 952 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "borrow from your father?$"
# 953 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 954 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_Text_Mechadoll2Quiz2:
# 955 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "MECHADOLL 2 QUIZ.\p"
# 956 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "Which of these POKéMON was chasing\n"
# 957 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "PROF. BIRCH?$"
# 958 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 959 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_Text_Mechadoll2Quiz3:
# 960 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "MECHADOLL 2 QUIZ.\p"
# 961 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "Which of these POKéMON did TEAM AQUA\n"
# 962 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "use in PETALBURG FOREST?$"
# 963 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 964 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_Text_Mechadoll3Intro:
# 965 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "CLICKETY-CLACK…\n"
# 966 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "MECHADOLL 3 AM I!\p"
# 967 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "MATTERS OF MONEY ARE MY SOLE FOCUS.$"
# 968 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 969 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_Text_Mechadoll3Quiz1:
# 970 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "MECHADOLL 3 QUIZ.\p"
# 971 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "Which costs more?\n"
# 972 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "Three HARBOR MAILS or one BURN HEAL?$"
# 973 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 974 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_Text_Mechadoll3Quiz2:
# 975 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "MECHADOLL 3 QUIZ.\p"
# 976 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "Sell one GREAT BALL and buy\n"
# 977 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "one POTION. How much money remains?$"
# 978 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 979 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_Text_Mechadoll3Quiz3:
# 980 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "MECHADOLL 3 QUIZ.\p"
# 981 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "Do one REPEL and SODA POP cost\n"
# 982 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "more than one SUPER POTION?$"
# 983 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 984 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_Text_Mechadoll4Intro:
# 985 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "CLICKETY-CLACK…\n"
# 986 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "MECHADOLL 4 THAT IS ME!\p"
# 987 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "MY QUIZ IS AN OBJECT OF BEAUTY.$"
# 988 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 989 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_Text_Mechadoll4Quiz1:
# 990 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "MECHADOLL 4 QUIZ.\p"
# 991 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "In SEASHORE HOUSE, were there more men\n"
# 992 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "or women?$"
# 993 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 994 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_Text_Mechadoll4Quiz2:
# 995 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "MECHADOLL 4 QUIZ.\p"
# 996 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "In LAVARIDGE TOWN, were there more\n"
# 997 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "elderly men or elderly women?$"
# 998 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 999 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_Text_Mechadoll4Quiz3:
# 1000 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "MECHADOLL 4 QUIZ.\p"
# 1001 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "In the TRAINER'S SCHOOL, how many\n"
# 1002 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "girl students were there?$"
# 1003 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 1004 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_Text_Mechadoll5Intro:
# 1005 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "CLICKETY-CLACK…\n"
# 1006 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "MECHADOLL 5 AM I!\p"
# 1007 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "THE MASTER'S BEST AND PROUDEST\n"
# 1008 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "ACHIEVEMENT AM I.$"
# 1009 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 1010 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_Text_Mechadoll5Quiz1:
# 1011 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "MECHADOLL 5 QUIZ.\p"
# 1012 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "In SLATEPORT's POKéMON FAN CLUB,\n"
# 1013 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "how many POKéMON were there?$"
# 1014 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 1015 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_Text_Mechadoll5Quiz2:
# 1016 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "MECHADOLL 5 QUIZ.\p"
# 1017 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "In FORTREE CITY, how many\n"
# 1018 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "tree houses were there?$"
# 1019 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 1020 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_Text_Mechadoll5Quiz3:
# 1021 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "MECHADOLL 5 QUIZ.\p"
# 1022 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "On the CYCLING ROAD, how many\n"
# 1023 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "TRIATHLETES were there?$"
