# 1 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 2 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
.set LOCALID_MECHADOLL_1, 1
# 3 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
.set LOCALID_MECHADOLL_2, 2
# 4 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
.set LOCALID_MECHADOLL_3, 3
# 5 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
.set LOCALID_MECHADOLL_4, 4
# 6 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
.set LOCALID_MECHADOLL_5, 5
# 7 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 8 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_MapScripts::
# 9 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route110_TrickHousePuzzle5_OnTransition
# 10 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.byte 0
# 11 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 12 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_OnTransition:
# 13 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_1, 0
# 14 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_2, 0
# 15 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_3, 0
# 16 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_4, 0
# 17 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_5, 0
# 18 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_8, 0
# 19 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 20 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 21 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Scroll::
# 22 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	lockall
# 23 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_5_STATE, 0, Route110_TrickHousePuzzle5_EventScript_FoundScroll
# 24 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle_EventScript_ReadScrollAgain
# 25 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 26 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 27 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_FoundScroll::
# 28 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TRICK_HOUSE_PUZZLE_5_STATE, 1
# 29 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle_EventScript_FoundScroll
# 30 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 31 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 32 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll1::
# 33 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	lockall
# 34 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_1, Common_Movement_FacePlayer
# 35 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 36 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto_if_eq VAR_TEMP_1, 1, Route110_TrickHousePuzzle5_EventScript_CorrectGoThrough
# 37 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_9, 0
# 38 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll1Activate
# 39 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 40 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 41 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll2::
# 42 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	lockall
# 43 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_2, Common_Movement_FacePlayer
# 44 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 45 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto_if_eq VAR_TEMP_2, 1, Route110_TrickHousePuzzle5_EventScript_CorrectGoThrough
# 46 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_9, 0
# 47 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll2Activate
# 48 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 49 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 50 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll3::
# 51 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	lockall
# 52 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_3, Common_Movement_FacePlayer
# 53 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 54 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto_if_eq VAR_TEMP_3, 1, Route110_TrickHousePuzzle5_EventScript_CorrectGoThrough
# 55 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_9, 0
# 56 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll3Activate
# 57 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 58 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 59 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll4::
# 60 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	lockall
# 61 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_4, Common_Movement_FacePlayer
# 62 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 63 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto_if_eq VAR_TEMP_4, 1, Route110_TrickHousePuzzle5_EventScript_CorrectGoThrough
# 64 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_9, 0
# 65 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll4Activate
# 66 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 67 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 68 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll5::
# 69 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	lockall
# 70 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_5, Common_Movement_FacePlayer
# 71 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 72 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto_if_eq VAR_TEMP_5, 1, Route110_TrickHousePuzzle5_EventScript_CorrectGoThrough
# 73 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_9, 0
# 74 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll5Activate
# 75 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 76 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 77 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll1Trigger0::
# 78 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	lockall
# 79 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_9, 0
# 80 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll1Activate
# 81 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 82 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 83 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll1Trigger1::
# 84 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	lockall
# 85 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_9, 1
# 86 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll1Activate
# 87 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 88 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 89 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll1Trigger2::
# 90 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	lockall
# 91 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_9, 2
# 92 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll1Activate
# 93 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 94 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 95 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll1Trigger3::
# 96 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	lockall
# 97 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_9, 3
# 98 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll1Activate
# 99 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 100 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 101 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll1Trigger4::
# 102 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	lockall
# 103 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_9, 4
# 104 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll1Activate
# 105 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 106 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 107 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll2Trigger0::
# 108 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	lockall
# 109 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_9, 0
# 110 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll2Activate
# 111 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 112 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 113 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll2Trigger1::
# 114 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	lockall
# 115 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_9, 1
# 116 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll2Activate
# 117 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 118 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 119 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll2Trigger2::
# 120 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	lockall
# 121 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_9, 2
# 122 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll2Activate
# 123 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 124 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 125 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll2Trigger3::
# 126 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	lockall
# 127 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_9, 3
# 128 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll2Activate
# 129 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 130 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 131 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll2Trigger4::
# 132 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	lockall
# 133 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_9, 4
# 134 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll2Activate
# 135 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 136 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 137 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll2Trigger5::
# 138 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	lockall
# 139 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_9, 5
# 140 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll2Activate
# 141 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 142 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 143 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll3Trigger0::
# 144 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	lockall
# 145 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_9, 0
# 146 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll3Activate
# 147 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 148 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 149 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll3Trigger1::
# 150 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	lockall
# 151 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_9, 1
# 152 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll3Activate
# 153 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 154 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 155 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll3Trigger2::
# 156 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	lockall
# 157 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_9, 2
# 158 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll3Activate
# 159 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 160 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 161 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll3Trigger3::
# 162 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	lockall
# 163 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_9, 3
# 164 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll3Activate
# 165 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 166 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 167 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll3Trigger4::
# 168 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	lockall
# 169 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_9, 4
# 170 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll3Activate
# 171 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 172 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 173 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll4Trigger0::
# 174 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	lockall
# 175 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_9, 0
# 176 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll4Activate
# 177 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 178 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 179 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll4Trigger1::
# 180 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	lockall
# 181 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_9, 1
# 182 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll4Activate
# 183 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 184 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 185 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll4Trigger2::
# 186 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	lockall
# 187 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_9, 2
# 188 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll4Activate
# 189 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 190 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 191 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll4Trigger3::
# 192 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	lockall
# 193 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_9, 3
# 194 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll4Activate
# 195 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 196 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 197 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll4Trigger4::
# 198 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	lockall
# 199 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_9, 4
# 200 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll4Activate
# 201 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 202 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 203 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
@ Unused
# 204 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll4Trigger5::
# 205 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	lockall
# 206 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_9, 5
# 207 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll4Activate
# 208 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 209 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 210 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll5Trigger0::
# 211 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	lockall
# 212 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_9, 0
# 213 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll5Activate
# 214 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 215 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 216 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll1Activate::
# 217 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_1, 1
# 218 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_8, LOCALID_MECHADOLL_1
# 219 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	playse SE_PIN
# 220 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_1, Common_Movement_ExclamationMark
# 221 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 222 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_1, Common_Movement_Delay48
# 223 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 224 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_9, 1, Route110_TrickHousePuzzle5_EventScript_MechadollWalkLeft1
# 225 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_9, 2, Route110_TrickHousePuzzle5_EventScript_MechadollWalkLeft2
# 226 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_9, 3, Route110_TrickHousePuzzle5_EventScript_MechadollWalkLeft3
# 227 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_9, 4, Route110_TrickHousePuzzle5_EventScript_MechadollWalkLeft4
# 228 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	msgbox Route110_TrickHousePuzzle5_Text_Mechadoll1Intro, MSGBOX_DEFAULT
# 229 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	random 3
# 230 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	switch VAR_RESULT
# 231 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	case 0, Route110_TrickHousePuzzle5_EventScript_Mechadoll1Quiz1
# 232 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	case 1, Route110_TrickHousePuzzle5_EventScript_Mechadoll1Quiz2
# 233 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	case 2, Route110_TrickHousePuzzle5_EventScript_Mechadoll1Quiz3
# 234 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 235 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 236 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll2Activate::
# 237 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_2, 1
# 238 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_8, LOCALID_MECHADOLL_2
# 239 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	playse SE_PIN
# 240 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_2, Common_Movement_ExclamationMark
# 241 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 242 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_2, Common_Movement_Delay48
# 243 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 244 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_9, 1, Route110_TrickHousePuzzle5_EventScript_MechadollWalkRight1
# 245 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_9, 2, Route110_TrickHousePuzzle5_EventScript_MechadollWalkRight2
# 246 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_9, 3, Route110_TrickHousePuzzle5_EventScript_MechadollWalkRight3
# 247 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_9, 4, Route110_TrickHousePuzzle5_EventScript_MechadollWalkRight4
# 248 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_9, 5, Route110_TrickHousePuzzle5_EventScript_MechadollWalkRight5
# 249 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	msgbox Route110_TrickHousePuzzle5_Text_Mechadoll2Intro, MSGBOX_DEFAULT
# 250 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	random 3
# 251 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	switch VAR_RESULT
# 252 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	case 0, Route110_TrickHousePuzzle5_EventScript_Mechadoll2Quiz1
# 253 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	case 1, Route110_TrickHousePuzzle5_EventScript_Mechadoll2Quiz2
# 254 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	case 2, Route110_TrickHousePuzzle5_EventScript_Mechadoll2Quiz3
# 255 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 256 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 257 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll3Activate::
# 258 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_3, 1
# 259 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_8, LOCALID_MECHADOLL_3
# 260 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	playse SE_PIN
# 261 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_3, Common_Movement_ExclamationMark
# 262 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 263 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_3, Common_Movement_Delay48
# 264 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 265 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_9, 1, Route110_TrickHousePuzzle5_EventScript_MechadollWalkLeft1
# 266 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_9, 2, Route110_TrickHousePuzzle5_EventScript_MechadollWalkLeft2
# 267 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_9, 3, Route110_TrickHousePuzzle5_EventScript_MechadollWalkLeft3
# 268 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_9, 4, Route110_TrickHousePuzzle5_EventScript_MechadollWalkLeft4
# 269 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	msgbox Route110_TrickHousePuzzle5_Text_Mechadoll3Intro, MSGBOX_DEFAULT
# 270 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	random 3
# 271 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	switch VAR_RESULT
# 272 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	case 0, Route110_TrickHousePuzzle5_EventScript_Mechadoll3Quiz1
# 273 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	case 1, Route110_TrickHousePuzzle5_EventScript_Mechadoll3Quiz2
# 274 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	case 2, Route110_TrickHousePuzzle5_EventScript_Mechadoll3Quiz3
# 275 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 276 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 277 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll4Activate::
# 278 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_4, 1
# 279 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_8, LOCALID_MECHADOLL_4
# 280 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	playse SE_PIN
# 281 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_4, Common_Movement_ExclamationMark
# 282 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 283 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_4, Common_Movement_Delay48
# 284 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 285 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_9, 1, Route110_TrickHousePuzzle5_EventScript_MechadollWalkLeft1
# 286 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_9, 2, Route110_TrickHousePuzzle5_EventScript_MechadollWalkLeft2
# 287 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_9, 3, Route110_TrickHousePuzzle5_EventScript_MechadollWalkLeft3
# 288 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_9, 4, Route110_TrickHousePuzzle5_EventScript_MechadollWalkLeft4
# 289 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	msgbox Route110_TrickHousePuzzle5_Text_Mechadoll4Intro, MSGBOX_DEFAULT
# 290 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	random 3
# 291 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	switch VAR_RESULT
# 292 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	case 0, Route110_TrickHousePuzzle5_EventScript_Mechadoll4Quiz1
# 293 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	case 1, Route110_TrickHousePuzzle5_EventScript_Mechadoll4Quiz2
# 294 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	case 2, Route110_TrickHousePuzzle5_EventScript_Mechadoll4Quiz3
# 295 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 296 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 297 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll5Activate::
# 298 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_5, 1
# 299 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_8, LOCALID_MECHADOLL_5
# 300 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	playse SE_PIN
# 301 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_5, Common_Movement_ExclamationMark
# 302 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 303 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_5, Common_Movement_Delay48
# 304 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 305 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	msgbox Route110_TrickHousePuzzle5_Text_Mechadoll5Intro, MSGBOX_DEFAULT
# 306 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	random 3
# 307 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	switch VAR_RESULT
# 308 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	case 0, Route110_TrickHousePuzzle5_EventScript_Mechadoll5Quiz1
# 309 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	case 1, Route110_TrickHousePuzzle5_EventScript_Mechadoll5Quiz2
# 310 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	case 2, Route110_TrickHousePuzzle5_EventScript_Mechadoll5Quiz3
# 311 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 312 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 313 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll1Quiz1::
# 314 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	msgbox Route110_TrickHousePuzzle5_Text_Mechadoll1Quiz1, MSGBOX_DEFAULT
# 315 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	multichoice 0, 0, MULTI_MECHADOLL1_Q1, TRUE
# 316 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	switch VAR_RESULT
# 317 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	case 2, Route110_TrickHousePuzzle5_EventScript_CorrectAnswer
# 318 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_IncorrectAnswer
# 319 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 320 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 321 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll1Quiz2::
# 322 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	msgbox Route110_TrickHousePuzzle5_Text_Mechadoll1Quiz2, MSGBOX_DEFAULT
# 323 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	multichoice 0, 0, MULTI_MECHADOLL1_Q2, TRUE
# 324 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	switch VAR_RESULT
# 325 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	case 0, Route110_TrickHousePuzzle5_EventScript_CorrectAnswer
# 326 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_IncorrectAnswer
# 327 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 328 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 329 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll1Quiz3::
# 330 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	msgbox Route110_TrickHousePuzzle5_Text_Mechadoll1Quiz3, MSGBOX_DEFAULT
# 331 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	multichoice 0, 0, MULTI_MECHADOLL1_Q3, TRUE
# 332 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	switch VAR_RESULT
# 333 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	case 0, Route110_TrickHousePuzzle5_EventScript_CorrectAnswer
# 334 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_IncorrectAnswer
# 335 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 336 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 337 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll2Quiz1::
# 338 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	msgbox Route110_TrickHousePuzzle5_Text_Mechadoll2Quiz1, MSGBOX_DEFAULT
# 339 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	multichoice 0, 0, MULTI_MECHADOLL2_Q1, TRUE
# 340 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	switch VAR_RESULT
# 341 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	case 1, Route110_TrickHousePuzzle5_EventScript_CorrectAnswer
# 342 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_IncorrectAnswer
# 343 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 344 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 345 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll2Quiz2::
# 346 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	msgbox Route110_TrickHousePuzzle5_Text_Mechadoll2Quiz2, MSGBOX_DEFAULT
# 347 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	multichoice 0, 0, MULTI_MECHADOLL2_Q2, TRUE
# 348 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	switch VAR_RESULT
# 349 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	case 2, Route110_TrickHousePuzzle5_EventScript_CorrectAnswer
# 350 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_IncorrectAnswer
# 351 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 352 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 353 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll2Quiz3::
# 354 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	msgbox Route110_TrickHousePuzzle5_Text_Mechadoll2Quiz3, MSGBOX_DEFAULT
# 355 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	multichoice 0, 0, MULTI_MECHADOLL2_Q3, TRUE
# 356 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	switch VAR_RESULT
# 357 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	case 0, Route110_TrickHousePuzzle5_EventScript_CorrectAnswer
# 358 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_IncorrectAnswer
# 359 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 360 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 361 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll3Quiz1::
# 362 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	msgbox Route110_TrickHousePuzzle5_Text_Mechadoll3Quiz1, MSGBOX_DEFAULT
# 363 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	multichoice 0, 0, MULTI_MECHADOLL3_Q1, TRUE
# 364 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	switch VAR_RESULT
# 365 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	case 0, Route110_TrickHousePuzzle5_EventScript_CorrectAnswer
# 366 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_IncorrectAnswer
# 367 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 368 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 369 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll3Quiz2::
# 370 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	msgbox Route110_TrickHousePuzzle5_Text_Mechadoll3Quiz2, MSGBOX_DEFAULT
# 371 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	multichoice 0, 0, MULTI_MECHADOLL3_Q2, TRUE
# 372 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	switch VAR_RESULT
# 373 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	case 2, Route110_TrickHousePuzzle5_EventScript_CorrectAnswer
# 374 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_IncorrectAnswer
# 375 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 376 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 377 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll3Quiz3::
# 378 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	msgbox Route110_TrickHousePuzzle5_Text_Mechadoll3Quiz3, MSGBOX_DEFAULT
# 379 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	multichoice 0, 0, MULTI_MECHADOLL3_Q3, TRUE
# 380 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	switch VAR_RESULT
# 381 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	case 1, Route110_TrickHousePuzzle5_EventScript_CorrectAnswer
# 382 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_IncorrectAnswer
# 383 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 384 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 385 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll4Quiz1::
# 386 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	msgbox Route110_TrickHousePuzzle5_Text_Mechadoll4Quiz1, MSGBOX_DEFAULT
# 387 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	multichoice 0, 0, MULTI_MECHADOLL4_Q1, TRUE
# 388 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	switch VAR_RESULT
# 389 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	case 0, Route110_TrickHousePuzzle5_EventScript_CorrectAnswer
# 390 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_IncorrectAnswer
# 391 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 392 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 393 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll4Quiz2::
# 394 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	msgbox Route110_TrickHousePuzzle5_Text_Mechadoll4Quiz2, MSGBOX_DEFAULT
# 395 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	multichoice 0, 0, MULTI_MECHADOLL4_Q2, TRUE
# 396 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	switch VAR_RESULT
# 397 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	case 0, Route110_TrickHousePuzzle5_EventScript_CorrectAnswer
# 398 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_IncorrectAnswer
# 399 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 400 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 401 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll4Quiz3::
# 402 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	msgbox Route110_TrickHousePuzzle5_Text_Mechadoll4Quiz3, MSGBOX_DEFAULT
# 403 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	multichoice 0, 0, MULTI_MECHADOLL4_Q3, TRUE
# 404 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	switch VAR_RESULT
# 405 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	case 1, Route110_TrickHousePuzzle5_EventScript_CorrectAnswer
# 406 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_IncorrectAnswer
# 407 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 408 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 409 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll5Quiz1::
# 410 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	msgbox Route110_TrickHousePuzzle5_Text_Mechadoll5Quiz1, MSGBOX_DEFAULT
# 411 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	multichoice 0, 0, MULTI_MECHADOLL5_Q1, TRUE
# 412 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	switch VAR_RESULT
# 413 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	case 1, Route110_TrickHousePuzzle5_EventScript_CorrectAnswer
# 414 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_IncorrectAnswer
# 415 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 416 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 417 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll5Quiz2::
# 418 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	msgbox Route110_TrickHousePuzzle5_Text_Mechadoll5Quiz2, MSGBOX_DEFAULT
# 419 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	multichoice 0, 0, MULTI_MECHADOLL5_Q2, TRUE
# 420 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	switch VAR_RESULT
# 421 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	case 0, Route110_TrickHousePuzzle5_EventScript_CorrectAnswer
# 422 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_IncorrectAnswer
# 423 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 424 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 425 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll5Quiz3::
# 426 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	msgbox Route110_TrickHousePuzzle5_Text_Mechadoll5Quiz3, MSGBOX_DEFAULT
# 427 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	multichoice 0, 0, MULTI_MECHADOLL5_Q3, TRUE
# 428 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	switch VAR_RESULT
# 429 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	case 2, Route110_TrickHousePuzzle5_EventScript_CorrectAnswer
# 430 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_IncorrectAnswer
# 431 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 432 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 433 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_IncorrectAnswer::
# 434 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitse
# 435 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	playse SE_FAILURE
# 436 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	msgbox Route110_TrickHousePuzzle5_Text_DisappointmentError, MSGBOX_DEFAULT
# 437 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_1, Route110_TrickHousePuzzle5_Movement_MechadollShake
# 438 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_2, Route110_TrickHousePuzzle5_Movement_MechadollShake
# 439 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_3, Route110_TrickHousePuzzle5_Movement_MechadollShake
# 440 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_4, Route110_TrickHousePuzzle5_Movement_MechadollShake
# 441 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_5, Route110_TrickHousePuzzle5_Movement_MechadollShake
# 442 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	msgbox Route110_TrickHousePuzzle5_Text_Wahahahaha, MSGBOX_DEFAULT
# 443 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 444 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	msgbox Route110_TrickHousePuzzle5_Text_WaitForNextChallenge, MSGBOX_DEFAULT
# 445 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	closemessage
# 446 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	warp MAP_ROUTE110_TRICK_HOUSE_PUZZLE5, 0, 21
# 447 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitstate
# 448 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	releaseall
# 449 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 450 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 451 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_CorrectAnswer::
# 452 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitse
# 453 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	playse SE_SUCCESS
# 454 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_CorrectGoThrough
# 455 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 456 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 457 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_CorrectGoThrough::
# 458 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	msgbox Route110_TrickHousePuzzle5_Text_CorrectGoThrough, MSGBOX_DEFAULT
# 459 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	releaseall
# 460 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 461 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 462 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
@ Absurd redundancy in movement scripts that could be resolved by using VAR_TEMP_8 for applymovement instead
# 463 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
@ Many of the below movement scripts arent even used, see below
# 464 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
@   Mechadoll 2 is the only mechadoll to walk right, all the other WalkRight scripts are unused
# 465 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
@   Mechadoll 5 never walks, all the Mechadoll5Walk scripts are unused
# 466 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
@   No mechadoll walks left 5 paces, all the WalkLeft5 scripts are unused
# 467 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_MechadollWalkLeft1::
# 468 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_1, Route110_TrickHousePuzzle5_EventScript_Mechadoll1WalkLeft1
# 469 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_2, Route110_TrickHousePuzzle5_EventScript_Mechadoll2WalkLeft1
# 470 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_3, Route110_TrickHousePuzzle5_EventScript_Mechadoll3WalkLeft1
# 471 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_4, Route110_TrickHousePuzzle5_EventScript_Mechadoll4WalkLeft1
# 472 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_5, Route110_TrickHousePuzzle5_EventScript_Mechadoll5WalkLeft1
# 473 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 474 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 475 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_MechadollWalkLeft2::
# 476 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_1, Route110_TrickHousePuzzle5_EventScript_Mechadoll1WalkLeft2
# 477 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_2, Route110_TrickHousePuzzle5_EventScript_Mechadoll2WalkLeft2
# 478 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_3, Route110_TrickHousePuzzle5_EventScript_Mechadoll3WalkLeft2
# 479 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_4, Route110_TrickHousePuzzle5_EventScript_Mechadoll4WalkLeft2
# 480 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_5, Route110_TrickHousePuzzle5_EventScript_Mechadoll5WalkLeft2
# 481 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 482 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 483 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_MechadollWalkLeft3::
# 484 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_1, Route110_TrickHousePuzzle5_EventScript_Mechadoll1WalkLeft3
# 485 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_2, Route110_TrickHousePuzzle5_EventScript_Mechadoll2WalkLeft3
# 486 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_3, Route110_TrickHousePuzzle5_EventScript_Mechadoll3WalkLeft3
# 487 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_4, Route110_TrickHousePuzzle5_EventScript_Mechadoll4WalkLeft3
# 488 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_5, Route110_TrickHousePuzzle5_EventScript_Mechadoll5WalkLeft3
# 489 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 490 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 491 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_MechadollWalkLeft4::
# 492 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_1, Route110_TrickHousePuzzle5_EventScript_Mechadoll1WalkLeft4
# 493 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_2, Route110_TrickHousePuzzle5_EventScript_Mechadoll2WalkLeft4
# 494 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_3, Route110_TrickHousePuzzle5_EventScript_Mechadoll3WalkLeft4
# 495 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_4, Route110_TrickHousePuzzle5_EventScript_Mechadoll4WalkLeft4
# 496 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_5, Route110_TrickHousePuzzle5_EventScript_Mechadoll5WalkLeft4
# 497 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 498 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 499 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_MechadollWalkLeft5::
# 500 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_1, Route110_TrickHousePuzzle5_EventScript_Mechadoll1WalkLeft5
# 501 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_2, Route110_TrickHousePuzzle5_EventScript_Mechadoll2WalkLeft5
# 502 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_3, Route110_TrickHousePuzzle5_EventScript_Mechadoll3WalkLeft5
# 503 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_4, Route110_TrickHousePuzzle5_EventScript_Mechadoll4WalkLeft5
# 504 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_5, Route110_TrickHousePuzzle5_EventScript_Mechadoll5WalkLeft5
# 505 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 506 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 507 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_MechadollWalkRight1::
# 508 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_1, Route110_TrickHousePuzzle5_EventScript_Mechadoll1WalkRight1
# 509 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_2, Route110_TrickHousePuzzle5_EventScript_Mechadoll2WalkRight1
# 510 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_3, Route110_TrickHousePuzzle5_EventScript_Mechadoll3WalkRight1
# 511 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_4, Route110_TrickHousePuzzle5_EventScript_Mechadoll4WalkRight1
# 512 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_5, Route110_TrickHousePuzzle5_EventScript_Mechadoll5WalkRight1
# 513 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 514 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 515 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_MechadollWalkRight2::
# 516 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_1, Route110_TrickHousePuzzle5_EventScript_Mechadoll1WalkRight2
# 517 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_2, Route110_TrickHousePuzzle5_EventScript_Mechadoll2WalkRight2
# 518 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_3, Route110_TrickHousePuzzle5_EventScript_Mechadoll3WalkRight2
# 519 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_4, Route110_TrickHousePuzzle5_EventScript_Mechadoll4WalkRight2
# 520 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_5, Route110_TrickHousePuzzle5_EventScript_Mechadoll5WalkRight2
# 521 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 522 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 523 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_MechadollWalkRight3::
# 524 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_1, Route110_TrickHousePuzzle5_EventScript_Mechadoll1WalkRight3
# 525 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_2, Route110_TrickHousePuzzle5_EventScript_Mechadoll2WalkRight3
# 526 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_3, Route110_TrickHousePuzzle5_EventScript_Mechadoll3WalkRight3
# 527 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_4, Route110_TrickHousePuzzle5_EventScript_Mechadoll4WalkRight3
# 528 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_5, Route110_TrickHousePuzzle5_EventScript_Mechadoll5WalkRight3
# 529 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 530 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 531 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_MechadollWalkRight4::
# 532 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_1, Route110_TrickHousePuzzle5_EventScript_Mechadoll1WalkRight4
# 533 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_2, Route110_TrickHousePuzzle5_EventScript_Mechadoll2WalkRight4
# 534 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_3, Route110_TrickHousePuzzle5_EventScript_Mechadoll3WalkRight4
# 535 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_4, Route110_TrickHousePuzzle5_EventScript_Mechadoll4WalkRight4
# 536 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_5, Route110_TrickHousePuzzle5_EventScript_Mechadoll5WalkRight4
# 537 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 538 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 539 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_MechadollWalkRight5::
# 540 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_1, Route110_TrickHousePuzzle5_EventScript_Mechadoll1WalkRight5
# 541 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_2, Route110_TrickHousePuzzle5_EventScript_Mechadoll2WalkRight5
# 542 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_3, Route110_TrickHousePuzzle5_EventScript_Mechadoll3WalkRight5
# 543 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_4, Route110_TrickHousePuzzle5_EventScript_Mechadoll4WalkRight5
# 544 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq VAR_TEMP_8, LOCALID_MECHADOLL_5, Route110_TrickHousePuzzle5_EventScript_Mechadoll5WalkRight5
# 545 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 546 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 547 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll1WalkLeft1::
# 548 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_1, Route110_TrickHousePuzzle5_Movement_WalkLeft1
# 549 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 550 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 551 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 552 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll2WalkLeft1::
# 553 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_2, Route110_TrickHousePuzzle5_Movement_WalkLeft1
# 554 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 555 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 556 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 557 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll3WalkLeft1::
# 558 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_3, Route110_TrickHousePuzzle5_Movement_WalkLeft1
# 559 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 560 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 561 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 562 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll4WalkLeft1::
# 563 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_4, Route110_TrickHousePuzzle5_Movement_WalkLeft1
# 564 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 565 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 566 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 567 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll5WalkLeft1::
# 568 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_5, Route110_TrickHousePuzzle5_Movement_WalkLeft1
# 569 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 570 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 571 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 572 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll1WalkLeft2::
# 573 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_1, Route110_TrickHousePuzzle5_Movement_WalkLeft2
# 574 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 575 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 576 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 577 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll2WalkLeft2::
# 578 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_2, Route110_TrickHousePuzzle5_Movement_WalkLeft2
# 579 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 580 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 581 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 582 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll3WalkLeft2::
# 583 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_3, Route110_TrickHousePuzzle5_Movement_WalkLeft2
# 584 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 585 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 586 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 587 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll4WalkLeft2::
# 588 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_4, Route110_TrickHousePuzzle5_Movement_WalkLeft2
# 589 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 590 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 591 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 592 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll5WalkLeft2::
# 593 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_5, Route110_TrickHousePuzzle5_Movement_WalkLeft2
# 594 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 595 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 596 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 597 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll1WalkLeft3::
# 598 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_1, Route110_TrickHousePuzzle5_Movement_WalkLeft3
# 599 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 600 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 601 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 602 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll2WalkLeft3::
# 603 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_2, Route110_TrickHousePuzzle5_Movement_WalkLeft3
# 604 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 605 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 606 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 607 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll3WalkLeft3::
# 608 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_3, Route110_TrickHousePuzzle5_Movement_WalkLeft3
# 609 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 610 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 611 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 612 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll4WalkLeft3::
# 613 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_4, Route110_TrickHousePuzzle5_Movement_WalkLeft3
# 614 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 615 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 616 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 617 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll5WalkLeft3::
# 618 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_5, Route110_TrickHousePuzzle5_Movement_WalkLeft3
# 619 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 620 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 621 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 622 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll1WalkLeft4::
# 623 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_1, Route110_TrickHousePuzzle5_Movement_WalkLeft4
# 624 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 625 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 626 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 627 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll2WalkLeft4::
# 628 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_2, Route110_TrickHousePuzzle5_Movement_WalkLeft4
# 629 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 630 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 631 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 632 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll3WalkLeft4::
# 633 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_3, Route110_TrickHousePuzzle5_Movement_WalkLeft4
# 634 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 635 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 636 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 637 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll4WalkLeft4::
# 638 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_4, Route110_TrickHousePuzzle5_Movement_WalkLeft4
# 639 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 640 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 641 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 642 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll5WalkLeft4::
# 643 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_5, Route110_TrickHousePuzzle5_Movement_WalkLeft4
# 644 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 645 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 646 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 647 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll1WalkLeft5::
# 648 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_1, Route110_TrickHousePuzzle5_Movement_WalkLeft5
# 649 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 650 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 651 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 652 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll2WalkLeft5::
# 653 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_2, Route110_TrickHousePuzzle5_Movement_WalkLeft5
# 654 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 655 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 656 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 657 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll3WalkLeft5::
# 658 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_3, Route110_TrickHousePuzzle5_Movement_WalkLeft5
# 659 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 660 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 661 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 662 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll4WalkLeft5::
# 663 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_4, Route110_TrickHousePuzzle5_Movement_WalkLeft5
# 664 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 665 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 666 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 667 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll5WalkLeft5::
# 668 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_5, Route110_TrickHousePuzzle5_Movement_WalkLeft5
# 669 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 670 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 671 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 672 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll1WalkRight1::
# 673 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_1, Route110_TrickHousePuzzle5_Movement_WalkRight1
# 674 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 675 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 676 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 677 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll2WalkRight1::
# 678 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_2, Route110_TrickHousePuzzle5_Movement_WalkRight1
# 679 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 680 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 681 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 682 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll3WalkRight1::
# 683 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_3, Route110_TrickHousePuzzle5_Movement_WalkRight1
# 684 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 685 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 686 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 687 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll4WalkRight1::
# 688 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_4, Route110_TrickHousePuzzle5_Movement_WalkRight1
# 689 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 690 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 691 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 692 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll5WalkRight1::
# 693 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_5, Route110_TrickHousePuzzle5_Movement_WalkRight1
# 694 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 695 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 696 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 697 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll1WalkRight2::
# 698 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_1, Route110_TrickHousePuzzle5_Movement_WalkRight2
# 699 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 700 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 701 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 702 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll2WalkRight2::
# 703 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_2, Route110_TrickHousePuzzle5_Movement_WalkRight2
# 704 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 705 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 706 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 707 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll3WalkRight2::
# 708 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_3, Route110_TrickHousePuzzle5_Movement_WalkRight2
# 709 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 710 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 711 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 712 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll4WalkRight2::
# 713 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_4, Route110_TrickHousePuzzle5_Movement_WalkRight2
# 714 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 715 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 716 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 717 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll5WalkRight2::
# 718 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_5, Route110_TrickHousePuzzle5_Movement_WalkRight2
# 719 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 720 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 721 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 722 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll1WalkRight3::
# 723 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_1, Route110_TrickHousePuzzle5_Movement_WalkRight3
# 724 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 725 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 726 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 727 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll2WalkRight3::
# 728 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_2, Route110_TrickHousePuzzle5_Movement_WalkRight3
# 729 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 730 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 731 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 732 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll3WalkRight3::
# 733 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_3, Route110_TrickHousePuzzle5_Movement_WalkRight3
# 734 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 735 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 736 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 737 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll4WalkRight3::
# 738 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_4, Route110_TrickHousePuzzle5_Movement_WalkRight3
# 739 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 740 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 741 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 742 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll5WalkRight3::
# 743 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_5, Route110_TrickHousePuzzle5_Movement_WalkRight3
# 744 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 745 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 746 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 747 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll1WalkRight4::
# 748 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_1, Route110_TrickHousePuzzle5_Movement_WalkRight4
# 749 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 750 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 751 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 752 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll2WalkRight4::
# 753 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_2, Route110_TrickHousePuzzle5_Movement_WalkRight4
# 754 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 755 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 756 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 757 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll3WalkRight4::
# 758 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_3, Route110_TrickHousePuzzle5_Movement_WalkRight4
# 759 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 760 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 761 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 762 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll4WalkRight4::
# 763 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_4, Route110_TrickHousePuzzle5_Movement_WalkRight4
# 764 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 765 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 766 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 767 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll5WalkRight4::
# 768 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_5, Route110_TrickHousePuzzle5_Movement_WalkRight4
# 769 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 770 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 771 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 772 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll1WalkRight5::
# 773 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_1, Route110_TrickHousePuzzle5_Movement_WalkRight5
# 774 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 775 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 776 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 777 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll2WalkRight5::
# 778 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_2, Route110_TrickHousePuzzle5_Movement_WalkRight5
# 779 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 780 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 781 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 782 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll3WalkRight5::
# 783 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_3, Route110_TrickHousePuzzle5_Movement_WalkRight5
# 784 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 785 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 786 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 787 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll4WalkRight5::
# 788 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_4, Route110_TrickHousePuzzle5_Movement_WalkRight5
# 789 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 790 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 791 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 792 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll5WalkRight5::
# 793 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_5, Route110_TrickHousePuzzle5_Movement_WalkRight5
# 794 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 795 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 796 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 797 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_Movement_WalkLeft1:
# 798 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	walk_left
# 799 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	step_end
# 800 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 801 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_Movement_WalkLeft2:
# 802 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	walk_left
# 803 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	walk_left
# 804 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	step_end
# 805 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 806 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_Movement_WalkLeft3:
# 807 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	walk_left
# 808 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	walk_left
# 809 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	walk_left
# 810 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	step_end
# 811 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 812 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_Movement_WalkLeft4:
# 813 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	walk_left
# 814 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	walk_left
# 815 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	walk_left
# 816 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	walk_left
# 817 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	step_end
# 818 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 819 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_Movement_WalkLeft5:
# 820 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	walk_left
# 821 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	walk_left
# 822 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	walk_left
# 823 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	walk_left
# 824 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	walk_left
# 825 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	step_end
# 826 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 827 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_Movement_WalkRight1:
# 828 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	walk_right
# 829 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	step_end
# 830 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 831 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_Movement_WalkRight2:
# 832 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	walk_right
# 833 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	walk_right
# 834 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	step_end
# 835 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 836 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_Movement_WalkRight3:
# 837 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	walk_right
# 838 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	walk_right
# 839 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	walk_right
# 840 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	step_end
# 841 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 842 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_Movement_WalkRight4:
# 843 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	walk_right
# 844 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	walk_right
# 845 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	walk_right
# 846 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	walk_right
# 847 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	step_end
# 848 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 849 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_Movement_WalkRight5:
# 850 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	walk_right
# 851 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	walk_right
# 852 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	walk_right
# 853 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	walk_right
# 854 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	walk_right
# 855 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	step_end
# 856 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 857 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_Movement_MechadollShake:
# 858 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	face_left
# 859 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	delay_2
# 860 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	face_right
# 861 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	delay_2
# 862 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	face_left
# 863 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	delay_2
# 864 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	face_right
# 865 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	delay_2
# 866 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	face_left
# 867 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	delay_2
# 868 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	face_right
# 869 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	delay_2
# 870 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	face_left
# 871 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	delay_2
# 872 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	face_right
# 873 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	delay_2
# 874 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	face_left
# 875 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	delay_2
# 876 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	face_right
# 877 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	delay_2
# 878 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	face_left
# 879 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	delay_2
# 880 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	face_right
# 881 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	delay_2
# 882 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	face_left
# 883 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	delay_2
# 884 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	face_right
# 885 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	delay_2
# 886 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	face_left
# 887 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	delay_2
# 888 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	face_right
# 889 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	delay_2
# 890 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	face_left
# 891 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	delay_2
# 892 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	face_right
# 893 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	delay_2
# 894 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	face_left
# 895 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	delay_2
# 896 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	face_right
# 897 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	delay_2
# 898 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	face_left
# 899 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	delay_2
# 900 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	face_right
# 901 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	delay_2
# 902 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	face_down
# 903 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	step_end
# 904 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 905 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_Text_WroteSecretCodeLockOpened:
# 906 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "{PLAYER} wrote down the secret code\n"
# 907 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "on the door.\p"
# 908 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "“TRICK MASTER is a genius.”\n"
# 909 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "… … … … … … … …\p"
# 910 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "The lock clicked open!$"
# 911 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 912 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_Text_Mechadoll1Intro:
# 913 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "CLICKETY-CLACK…\n"
# 914 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "MECHADOLL 1 AM I!\p"
# 915 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "IF YOU ANSWER QUIZZES CORRECTLY,\n"
# 916 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "THEN YOU WILL GO TO MECHADOLL 5.\l"
# 917 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "THEN YOU CAN OBTAIN THE SECRET CODE.$"
# 918 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 919 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_Text_Mechadoll1Quiz1:
# 920 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "MECHADOLL 1 QUIZ.\p"
# 921 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "One of these POKéMON is not found\n"
# 922 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "on ROUTE 110. Which one is it?$"
# 923 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 924 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_Text_Mechadoll1Quiz2:
# 925 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "MECHADOLL 1 QUIZ.\p"
# 926 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "One of these POKéMON is not of the\n"
# 927 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "WATER type. Which one is it?$"
# 928 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 929 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_Text_Mechadoll1Quiz3:
# 930 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "MECHADOLL 1 QUIZ.\p"
# 931 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "One of these POKéMON does not use\n"
# 932 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "LEECH LIFE. Which one is it?$"
# 933 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 934 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_Text_CorrectGoThrough:
# 935 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "CONGRATULATIONS. CORRECT YOU ARE.\n"
# 936 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "GO THROUGH. PLEASE.$"
# 937 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 938 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_Text_DisappointmentError:
# 939 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "BZZZT. DISAPPOINTMENT.\n"
# 940 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "ERROR.$"
# 941 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 942 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_Text_Wahahahaha:
# 943 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "WAHAHAHAHA! WAHAHAHAHA!\n"
# 944 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "CLICKETY-CLACK!$"
# 945 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 946 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_Text_WaitForNextChallenge:
# 947 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "YOUR NEXT CHALLENGE WE WAIT FOR.$"
# 948 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 949 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_Text_Mechadoll2Intro:
# 950 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "CLICKETY-CLACK…\n"
# 951 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "MECHADOLL 2 AM I!\p"
# 952 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "MECHADOLL 1'S QUIZ DIFFICULTY LEVEL\n"
# 953 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "IS SET TOO LOW.$"
# 954 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 955 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_Text_Mechadoll2Quiz1:
# 956 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "MECHADOLL 2 QUIZ.\p"
# 957 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "Which of these POKéMON did WALLY\n"
# 958 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "borrow from your father?$"
# 959 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 960 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_Text_Mechadoll2Quiz2:
# 961 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "MECHADOLL 2 QUIZ.\p"
# 962 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "Which of these POKéMON was chasing\n"
# 963 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "PROF. BIRCH?$"
# 964 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 965 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_Text_Mechadoll2Quiz3:
# 966 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "MECHADOLL 2 QUIZ.\p"
# 967 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "Which of these POKéMON did TEAM AQUA\n"
# 968 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "use in PETALBURG FOREST?$"
# 969 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 970 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_Text_Mechadoll3Intro:
# 971 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "CLICKETY-CLACK…\n"
# 972 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "MECHADOLL 3 AM I!\p"
# 973 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "MATTERS OF MONEY ARE MY SOLE FOCUS.$"
# 974 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 975 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_Text_Mechadoll3Quiz1:
# 976 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "MECHADOLL 3 QUIZ.\p"
# 977 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "Which costs more?\n"
# 978 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "Three HARBOR MAILS or one BURN HEAL?$"
# 979 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 980 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_Text_Mechadoll3Quiz2:
# 981 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "MECHADOLL 3 QUIZ.\p"
# 982 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "Sell one GREAT BALL and buy\n"
# 983 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "one POTION. How much money remains?$"
# 984 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 985 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_Text_Mechadoll3Quiz3:
# 986 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "MECHADOLL 3 QUIZ.\p"
# 987 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "Do one REPEL and SODA POP cost\n"
# 988 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "more than one SUPER POTION?$"
# 989 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 990 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_Text_Mechadoll4Intro:
# 991 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "CLICKETY-CLACK…\n"
# 992 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "MECHADOLL 4 THAT IS ME!\p"
# 993 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "MY QUIZ IS AN OBJECT OF BEAUTY.$"
# 994 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 995 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_Text_Mechadoll4Quiz1:
# 996 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "MECHADOLL 4 QUIZ.\p"
# 997 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "In SEASHORE HOUSE, were there more men\n"
# 998 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "or women?$"
# 999 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 1000 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_Text_Mechadoll4Quiz2:
# 1001 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "MECHADOLL 4 QUIZ.\p"
# 1002 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "In LAVARIDGE TOWN, were there more\n"
# 1003 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "elderly men or elderly women?$"
# 1004 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 1005 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_Text_Mechadoll4Quiz3:
# 1006 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "MECHADOLL 4 QUIZ.\p"
# 1007 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "In the TRAINER'S SCHOOL, how many\n"
# 1008 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "girl students were there?$"
# 1009 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 1010 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_Text_Mechadoll5Intro:
# 1011 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "CLICKETY-CLACK…\n"
# 1012 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "MECHADOLL 5 AM I!\p"
# 1013 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "THE MASTER'S BEST AND PROUDEST\n"
# 1014 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "ACHIEVEMENT AM I.$"
# 1015 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 1016 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_Text_Mechadoll5Quiz1:
# 1017 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "MECHADOLL 5 QUIZ.\p"
# 1018 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "In SLATEPORT's POKéMON FAN CLUB,\n"
# 1019 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "how many POKéMON were there?$"
# 1020 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 1021 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_Text_Mechadoll5Quiz2:
# 1022 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "MECHADOLL 5 QUIZ.\p"
# 1023 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "In FORTREE CITY, how many\n"
# 1024 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "tree houses were there?$"
# 1025 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 1026 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_Text_Mechadoll5Quiz3:
# 1027 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "MECHADOLL 5 QUIZ.\p"
# 1028 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "On the CYCLING ROAD, how many\n"
# 1029 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "TRIATHLETES were there?$"
