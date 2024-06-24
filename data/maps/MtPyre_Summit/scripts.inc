# 1 "data/maps/MtPyre_Summit/scripts.pory"

# 2 "data/maps/MtPyre_Summit/scripts.pory"

# 3 "data/maps/MtPyre_Summit/scripts.pory"
.set LOCALID_ARCHIE, 2
# 4 "data/maps/MtPyre_Summit/scripts.pory"
.set LOCALID_OLD_LADY, 3
# 5 "data/maps/MtPyre_Summit/scripts.pory"
.set LOCALID_GRUNT_1, 4
# 6 "data/maps/MtPyre_Summit/scripts.pory"
.set LOCALID_GRUNT_2, 5
# 7 "data/maps/MtPyre_Summit/scripts.pory"
.set LOCALID_GRUNT_3, 6
# 8 "data/maps/MtPyre_Summit/scripts.pory"
.set LOCALID_GRUNT_4, 7
# 9 "data/maps/MtPyre_Summit/scripts.pory"
.set LOCALID_MAXIE, 8
# 10 "data/maps/MtPyre_Summit/scripts.pory"

# 11 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_MapScripts::
# 12 "data/maps/MtPyre_Summit/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, MtPyre_Summit_OnResume
# 13 "data/maps/MtPyre_Summit/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, MtPyre_Summit_OnTransition
# 14 "data/maps/MtPyre_Summit/scripts.pory"
	.byte 0
# 15 "data/maps/MtPyre_Summit/scripts.pory"

# 16 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_OnResume:
# 17 "data/maps/MtPyre_Summit/scripts.pory"
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, MtPyre_Summit_EventScript_TryRemoveArceus
# 18 "data/maps/MtPyre_Summit/scripts.pory"
	end
# 19 "data/maps/MtPyre_Summit/scripts.pory"

# 20 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_TryRemoveArceus::
# 21 "data/maps/MtPyre_Summit/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 22 "data/maps/MtPyre_Summit/scripts.pory"
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
# 23 "data/maps/MtPyre_Summit/scripts.pory"
	removeobject VAR_LAST_TALKED
# 24 "data/maps/MtPyre_Summit/scripts.pory"
	return
# 25 "data/maps/MtPyre_Summit/scripts.pory"

# 26 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_OnTransition:
# 27 "data/maps/MtPyre_Summit/scripts.pory"
	call_if_eq VAR_MT_PYRE_STATE, 2, MtPyre_Summit_EventScript_SetArchieMaxiePositions
# 28 "data/maps/MtPyre_Summit/scripts.pory"
	end
# 29 "data/maps/MtPyre_Summit/scripts.pory"

# 30 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_SetArchieMaxiePositions::
# 31 "data/maps/MtPyre_Summit/scripts.pory"
	setobjectxyperm LOCALID_MAXIE, 23, 6
# 32 "data/maps/MtPyre_Summit/scripts.pory"
	setobjectxyperm LOCALID_ARCHIE, 22, 6
# 33 "data/maps/MtPyre_Summit/scripts.pory"
	end
# 34 "data/maps/MtPyre_Summit/scripts.pory"

# 35 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_TeamAquaTrigger0::
# 36 "data/maps/MtPyre_Summit/scripts.pory"
	lockall
# 37 "data/maps/MtPyre_Summit/scripts.pory"
	setvar VAR_0x8008, 0
# 38 "data/maps/MtPyre_Summit/scripts.pory"
	goto MtPyre_Summit_EventScript_TeamAquaExits
# 39 "data/maps/MtPyre_Summit/scripts.pory"
	end
# 40 "data/maps/MtPyre_Summit/scripts.pory"

# 41 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_TeamAquaTrigger1::
# 42 "data/maps/MtPyre_Summit/scripts.pory"
	lockall
# 43 "data/maps/MtPyre_Summit/scripts.pory"
	setvar VAR_0x8008, 1
# 44 "data/maps/MtPyre_Summit/scripts.pory"
	goto MtPyre_Summit_EventScript_TeamAquaExits
# 45 "data/maps/MtPyre_Summit/scripts.pory"
	end
# 46 "data/maps/MtPyre_Summit/scripts.pory"

# 47 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_TeamAquaTrigger2::
# 48 "data/maps/MtPyre_Summit/scripts.pory"
	lockall
# 49 "data/maps/MtPyre_Summit/scripts.pory"
	setvar VAR_0x8008, 2
# 50 "data/maps/MtPyre_Summit/scripts.pory"
	goto MtPyre_Summit_EventScript_TeamAquaExits
# 51 "data/maps/MtPyre_Summit/scripts.pory"
	end
# 52 "data/maps/MtPyre_Summit/scripts.pory"

# 53 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_TeamAquaExits::
# 54 "data/maps/MtPyre_Summit/scripts.pory"
	playbgm MUS_ENCOUNTER_AQUA, FALSE
# 55 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
# 56 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 57 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_ARCHIE, Common_Movement_WalkInPlaceFasterDown
# 58 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 59 "data/maps/MtPyre_Summit/scripts.pory"
	delay 50
# 60 "data/maps/MtPyre_Summit/scripts.pory"
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_ArchieFacePlayer0
# 61 "data/maps/MtPyre_Summit/scripts.pory"
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_ArchieFacePlayer1
# 62 "data/maps/MtPyre_Summit/scripts.pory"
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_ArchieFacePlayer2
# 63 "data/maps/MtPyre_Summit/scripts.pory"
	msgbox MtPyre_Summit_Text_ArchieWeGotTheOrbLetsGo, MSGBOX_DEFAULT
# 64 "data/maps/MtPyre_Summit/scripts.pory"
	closemessage
# 65 "data/maps/MtPyre_Summit/scripts.pory"
	fadescreen FADE_TO_BLACK
# 66 "data/maps/MtPyre_Summit/scripts.pory"
	removeobject LOCALID_ARCHIE
# 67 "data/maps/MtPyre_Summit/scripts.pory"
	removeobject LOCALID_GRUNT_1
# 68 "data/maps/MtPyre_Summit/scripts.pory"
	removeobject LOCALID_GRUNT_2
# 69 "data/maps/MtPyre_Summit/scripts.pory"
	removeobject LOCALID_GRUNT_3
# 70 "data/maps/MtPyre_Summit/scripts.pory"
	removeobject LOCALID_GRUNT_4
# 71 "data/maps/MtPyre_Summit/scripts.pory"
	setflag FLAG_HIDE_MT_PYRE_SUMMIT_ARCHIE
# 72 "data/maps/MtPyre_Summit/scripts.pory"
	setflag FLAG_HIDE_MT_PYRE_SUMMIT_TEAM_AQUA
# 73 "data/maps/MtPyre_Summit/scripts.pory"
	fadedefaultbgm
# 74 "data/maps/MtPyre_Summit/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 75 "data/maps/MtPyre_Summit/scripts.pory"
	delay 20
# 76 "data/maps/MtPyre_Summit/scripts.pory"
	setvar VAR_MT_PYRE_STATE, 1
# 77 "data/maps/MtPyre_Summit/scripts.pory"
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_OldLadyApproachPlayer0
# 78 "data/maps/MtPyre_Summit/scripts.pory"
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_OldLadyApproachPlayer1
# 79 "data/maps/MtPyre_Summit/scripts.pory"
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_OldLadyApproachPlayer2
# 80 "data/maps/MtPyre_Summit/scripts.pory"
	msgbox MtPyre_Summit_Text_BothOrbsTakenMagmaLeftThis, MSGBOX_DEFAULT
# 81 "data/maps/MtPyre_Summit/scripts.pory"
	giveitem ITEM_MAGMA_EMBLEM
# 82 "data/maps/MtPyre_Summit/scripts.pory"
	setflag FLAG_RECEIVED_RED_OR_BLUE_ORB
# 83 "data/maps/MtPyre_Summit/scripts.pory"
	setflag FLAG_HIDE_JAGGED_PASS_MAGMA_GUARD
# 84 "data/maps/MtPyre_Summit/scripts.pory"
	releaseall
# 85 "data/maps/MtPyre_Summit/scripts.pory"
	end
# 86 "data/maps/MtPyre_Summit/scripts.pory"

# 87 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_ArchieFacePlayer0::
# 88 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieFacePlayer0
# 89 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 90 "data/maps/MtPyre_Summit/scripts.pory"
	return
# 91 "data/maps/MtPyre_Summit/scripts.pory"

# 92 "data/maps/MtPyre_Summit/scripts.pory"
@ Archie is already facing player
# 93 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_ArchieFacePlayer1::
# 94 "data/maps/MtPyre_Summit/scripts.pory"
	return
# 95 "data/maps/MtPyre_Summit/scripts.pory"

# 96 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_ArchieFacePlayer2::
# 97 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieFacePlayer2
# 98 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 99 "data/maps/MtPyre_Summit/scripts.pory"
	return
# 100 "data/maps/MtPyre_Summit/scripts.pory"

# 101 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_OldLadyApproachPlayer0::
# 102 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_OLD_LADY, MtPyre_Summit_Movement_OldLadyApproachPlayer0
# 103 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 104 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 105 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 106 "data/maps/MtPyre_Summit/scripts.pory"
	return
# 107 "data/maps/MtPyre_Summit/scripts.pory"

# 108 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_OldLadyApproachPlayer1::
# 109 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_OLD_LADY, MtPyre_Summit_Movement_OldLadyApproachPlayer1
# 110 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 111 "data/maps/MtPyre_Summit/scripts.pory"
	return
# 112 "data/maps/MtPyre_Summit/scripts.pory"

# 113 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_OldLadyApproachPlayer2::
# 114 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_OLD_LADY, MtPyre_Summit_Movement_OldLadyApproachPlayer2
# 115 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 116 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 117 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 118 "data/maps/MtPyre_Summit/scripts.pory"
	return
# 119 "data/maps/MtPyre_Summit/scripts.pory"

# 120 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_OldLadyApproachPlayer0:
# 121 "data/maps/MtPyre_Summit/scripts.pory"
	walk_down
# 122 "data/maps/MtPyre_Summit/scripts.pory"
	walk_down
# 123 "data/maps/MtPyre_Summit/scripts.pory"
	walk_in_place_faster_left
# 124 "data/maps/MtPyre_Summit/scripts.pory"
	step_end
# 125 "data/maps/MtPyre_Summit/scripts.pory"

# 126 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_OldLadyApproachPlayer1:
# 127 "data/maps/MtPyre_Summit/scripts.pory"
	walk_down
# 128 "data/maps/MtPyre_Summit/scripts.pory"
	step_end
# 129 "data/maps/MtPyre_Summit/scripts.pory"

# 130 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_OldLadyApproachPlayer2:
# 131 "data/maps/MtPyre_Summit/scripts.pory"
	walk_down
# 132 "data/maps/MtPyre_Summit/scripts.pory"
	walk_down
# 133 "data/maps/MtPyre_Summit/scripts.pory"
	walk_in_place_faster_right
# 134 "data/maps/MtPyre_Summit/scripts.pory"
	step_end
# 135 "data/maps/MtPyre_Summit/scripts.pory"

# 136 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_ArchieFacePlayer0:
# 137 "data/maps/MtPyre_Summit/scripts.pory"
	walk_left
# 138 "data/maps/MtPyre_Summit/scripts.pory"
	walk_in_place_faster_down
# 139 "data/maps/MtPyre_Summit/scripts.pory"
	step_end
# 140 "data/maps/MtPyre_Summit/scripts.pory"

# 141 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_ArchieFacePlayer2:
# 142 "data/maps/MtPyre_Summit/scripts.pory"
	walk_right
# 143 "data/maps/MtPyre_Summit/scripts.pory"
	walk_in_place_faster_down
# 144 "data/maps/MtPyre_Summit/scripts.pory"
	step_end
# 145 "data/maps/MtPyre_Summit/scripts.pory"

# 146 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_OldMan::
# 147 "data/maps/MtPyre_Summit/scripts.pory"
	lock
# 148 "data/maps/MtPyre_Summit/scripts.pory"
	faceplayer
# 149 "data/maps/MtPyre_Summit/scripts.pory"
	goto_if_set FLAG_SOOTOPOLIS_ARCHIE_MAXIE_LEAVE, MtPyre_Summit_EventScript_OldManAfterRayquaza
# 150 "data/maps/MtPyre_Summit/scripts.pory"
	msgbox MtPyre_Summit_Text_WillYouHearOutMyTale, MSGBOX_YESNO
# 151 "data/maps/MtPyre_Summit/scripts.pory"
	call_if_eq VAR_RESULT, YES, MtPyre_Summit_EventScript_OldManTale
# 152 "data/maps/MtPyre_Summit/scripts.pory"
	call_if_eq VAR_RESULT, NO, MtPyre_Summit_EventScript_DeclineOldManTale
# 153 "data/maps/MtPyre_Summit/scripts.pory"
	release
# 154 "data/maps/MtPyre_Summit/scripts.pory"
	end
# 155 "data/maps/MtPyre_Summit/scripts.pory"

# 156 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_OldManAfterRayquaza::
# 157 "data/maps/MtPyre_Summit/scripts.pory"
	msgbox MtPyre_Summit_Text_HearTheNewLegendOfHoenn, MSGBOX_YESNO
# 158 "data/maps/MtPyre_Summit/scripts.pory"
	call_if_eq VAR_RESULT, YES, MtPyre_Summit_EventScript_OldManNewTale
# 159 "data/maps/MtPyre_Summit/scripts.pory"
	call_if_eq VAR_RESULT, NO, MtPyre_Summit_EventScript_DeclineOldManTale
# 160 "data/maps/MtPyre_Summit/scripts.pory"
	release
# 161 "data/maps/MtPyre_Summit/scripts.pory"
	end
# 162 "data/maps/MtPyre_Summit/scripts.pory"

# 163 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_OldManTale::
# 164 "data/maps/MtPyre_Summit/scripts.pory"
	msgbox MtPyre_Summit_Text_GroudonKyogreTale, MSGBOX_DEFAULT
# 165 "data/maps/MtPyre_Summit/scripts.pory"
	return
# 166 "data/maps/MtPyre_Summit/scripts.pory"

# 167 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_DeclineOldManTale::
# 168 "data/maps/MtPyre_Summit/scripts.pory"
	msgbox MtPyre_Summit_Text_WellThatTooIsFine, MSGBOX_DEFAULT
# 169 "data/maps/MtPyre_Summit/scripts.pory"
	return
# 170 "data/maps/MtPyre_Summit/scripts.pory"

# 171 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_OldManNewTale::
# 172 "data/maps/MtPyre_Summit/scripts.pory"
	msgbox MtPyre_Summit_Text_HoennTrioTale, MSGBOX_DEFAULT
# 173 "data/maps/MtPyre_Summit/scripts.pory"
	return
# 174 "data/maps/MtPyre_Summit/scripts.pory"

# 175 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_OldLady::
# 176 "data/maps/MtPyre_Summit/scripts.pory"
	lock
# 177 "data/maps/MtPyre_Summit/scripts.pory"
	faceplayer
# 178 "data/maps/MtPyre_Summit/scripts.pory"
	goto_if_set FLAG_RETURNED_RED_OR_BLUE_ORB, MtPyre_Summit_EventScript_OldLadyAfterOrbsReturned
# 179 "data/maps/MtPyre_Summit/scripts.pory"
	call_if_ge VAR_MT_PYRE_STATE, 3, MtPyre_Summit_EventScript_OldLadyOrbsReturned
# 180 "data/maps/MtPyre_Summit/scripts.pory"
	goto_if_set FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN, MtPyre_Summit_EventScript_OldLadyLegendariesAwake
# 181 "data/maps/MtPyre_Summit/scripts.pory"
	msgbox MtPyre_Summit_Text_OrbsHaveBeenTaken, MSGBOX_DEFAULT
# 182 "data/maps/MtPyre_Summit/scripts.pory"
	release
# 183 "data/maps/MtPyre_Summit/scripts.pory"
	end
# 184 "data/maps/MtPyre_Summit/scripts.pory"

# 185 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_OldLadyOrbsReturned::
# 186 "data/maps/MtPyre_Summit/scripts.pory"
	msgbox MtPyre_Summit_Text_ThoseTwoMenReturnedOrbs, MSGBOX_DEFAULT
# 187 "data/maps/MtPyre_Summit/scripts.pory"
	setflag FLAG_RETURNED_RED_OR_BLUE_ORB
# 188 "data/maps/MtPyre_Summit/scripts.pory"
	release
# 189 "data/maps/MtPyre_Summit/scripts.pory"
	end
# 190 "data/maps/MtPyre_Summit/scripts.pory"

# 191 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_OldLadyLegendariesAwake::
# 192 "data/maps/MtPyre_Summit/scripts.pory"
	msgbox MtPyre_Summit_Text_GroudonKyogreAwakened, MSGBOX_DEFAULT
# 193 "data/maps/MtPyre_Summit/scripts.pory"
	release
# 194 "data/maps/MtPyre_Summit/scripts.pory"
	end
# 195 "data/maps/MtPyre_Summit/scripts.pory"

# 196 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_OldLadyAfterOrbsReturned::
# 197 "data/maps/MtPyre_Summit/scripts.pory"
	msgbox MtPyre_Summit_Text_SuperAncientPokemonTaughtUs, MSGBOX_DEFAULT
# 198 "data/maps/MtPyre_Summit/scripts.pory"
	release
# 199 "data/maps/MtPyre_Summit/scripts.pory"
	end
# 200 "data/maps/MtPyre_Summit/scripts.pory"

# 201 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_ArchieMaxieTrigger0::
# 202 "data/maps/MtPyre_Summit/scripts.pory"
	lockall
# 203 "data/maps/MtPyre_Summit/scripts.pory"
	setvar VAR_0x8008, 0
# 204 "data/maps/MtPyre_Summit/scripts.pory"
	goto MtPyre_Summit_EventScript_ArchieMaxieReturnOrbs
# 205 "data/maps/MtPyre_Summit/scripts.pory"
	end
# 206 "data/maps/MtPyre_Summit/scripts.pory"

# 207 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_ArchieMaxieTrigger1::
# 208 "data/maps/MtPyre_Summit/scripts.pory"
	lockall
# 209 "data/maps/MtPyre_Summit/scripts.pory"
	setvar VAR_0x8008, 1
# 210 "data/maps/MtPyre_Summit/scripts.pory"
	goto MtPyre_Summit_EventScript_ArchieMaxieReturnOrbs
# 211 "data/maps/MtPyre_Summit/scripts.pory"
	end
# 212 "data/maps/MtPyre_Summit/scripts.pory"

# 213 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_ArchieMaxieTrigger2::
# 214 "data/maps/MtPyre_Summit/scripts.pory"
	lockall
# 215 "data/maps/MtPyre_Summit/scripts.pory"
	setvar VAR_0x8008, 2
# 216 "data/maps/MtPyre_Summit/scripts.pory"
	goto MtPyre_Summit_EventScript_ArchieMaxieReturnOrbs
# 217 "data/maps/MtPyre_Summit/scripts.pory"
	end
# 218 "data/maps/MtPyre_Summit/scripts.pory"

# 219 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_ArchieMaxieReturnOrbs::
# 220 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 221 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 222 "data/maps/MtPyre_Summit/scripts.pory"
	delay 60
# 223 "data/maps/MtPyre_Summit/scripts.pory"
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_ArchieMaxieBeginExit0
# 224 "data/maps/MtPyre_Summit/scripts.pory"
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_ArchieMaxieBeginExit1
# 225 "data/maps/MtPyre_Summit/scripts.pory"
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_ArchieMaxieBeginExit2
# 226 "data/maps/MtPyre_Summit/scripts.pory"
	playse SE_PIN
# 227 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_MAXIE, Common_Movement_ExclamationMark
# 228 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 229 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_MAXIE, Common_Movement_Delay48
# 230 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 231 "data/maps/MtPyre_Summit/scripts.pory"
	delay 30
# 232 "data/maps/MtPyre_Summit/scripts.pory"
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_MaxieApproachPlayer0
# 233 "data/maps/MtPyre_Summit/scripts.pory"
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_MaxieApproachPlayer1
# 234 "data/maps/MtPyre_Summit/scripts.pory"
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_MaxieApproachPlayer2
# 235 "data/maps/MtPyre_Summit/scripts.pory"
	msgbox MtPyre_Summit_Text_MaxieSilence, MSGBOX_DEFAULT
# 236 "data/maps/MtPyre_Summit/scripts.pory"
	closemessage
# 237 "data/maps/MtPyre_Summit/scripts.pory"
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_MaxieApproachArchie0
# 238 "data/maps/MtPyre_Summit/scripts.pory"
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_MaxieApproachArchie1
# 239 "data/maps/MtPyre_Summit/scripts.pory"
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_MaxieApproachArchie2
# 240 "data/maps/MtPyre_Summit/scripts.pory"
	delay 30
# 241 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieExit
# 242 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieExit
# 243 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 244 "data/maps/MtPyre_Summit/scripts.pory"
	removeobject LOCALID_ARCHIE
# 245 "data/maps/MtPyre_Summit/scripts.pory"
	removeobject LOCALID_MAXIE
# 246 "data/maps/MtPyre_Summit/scripts.pory"
	setvar VAR_MT_PYRE_STATE, 3
# 247 "data/maps/MtPyre_Summit/scripts.pory"
	releaseall
# 248 "data/maps/MtPyre_Summit/scripts.pory"
	end
# 249 "data/maps/MtPyre_Summit/scripts.pory"

# 250 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_ArchieMaxieBeginExit0::
# 251 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit0
# 252 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieExit
# 253 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieExit
# 254 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 255 "data/maps/MtPyre_Summit/scripts.pory"
	return
# 256 "data/maps/MtPyre_Summit/scripts.pory"

# 257 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_ArchieMaxieBeginExit1::
# 258 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit1
# 259 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieExit
# 260 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieExit
# 261 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 262 "data/maps/MtPyre_Summit/scripts.pory"
	return
# 263 "data/maps/MtPyre_Summit/scripts.pory"

# 264 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_ArchieMaxieBeginExit2::
# 265 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit2
# 266 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieExit
# 267 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieExit
# 268 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 269 "data/maps/MtPyre_Summit/scripts.pory"
	return
# 270 "data/maps/MtPyre_Summit/scripts.pory"

# 271 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_MaxieApproachPlayer0::
# 272 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerFaceMaxie0
# 273 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieWatchMaxie
# 274 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieApproachPlayer0
# 275 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 276 "data/maps/MtPyre_Summit/scripts.pory"
	return
# 277 "data/maps/MtPyre_Summit/scripts.pory"

# 278 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_MaxieApproachPlayer1::
# 279 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerFaceMaxie
# 280 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieWatchMaxie
# 281 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieApproachPlayer1
# 282 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 283 "data/maps/MtPyre_Summit/scripts.pory"
	return
# 284 "data/maps/MtPyre_Summit/scripts.pory"

# 285 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_MaxieApproachPlayer2::
# 286 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerFaceMaxie
# 287 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieWatchMaxie
# 288 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieApproachPlayer2
# 289 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 290 "data/maps/MtPyre_Summit/scripts.pory"
	return
# 291 "data/maps/MtPyre_Summit/scripts.pory"

# 292 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_MaxieApproachArchie0::
# 293 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerWatchMaxie
# 294 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieApproachArchie0
# 295 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 296 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_ARCHIE, Common_Movement_WalkInPlaceFasterRight
# 297 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 298 "data/maps/MtPyre_Summit/scripts.pory"
	return
# 299 "data/maps/MtPyre_Summit/scripts.pory"

# 300 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_MaxieApproachArchie1::
# 301 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerWatchMaxie
# 302 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieApproachArchie1
# 303 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 304 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_ARCHIE, Common_Movement_WalkInPlaceFasterRight
# 305 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 306 "data/maps/MtPyre_Summit/scripts.pory"
	return
# 307 "data/maps/MtPyre_Summit/scripts.pory"

# 308 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_MaxieApproachArchie2::
# 309 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerWatchMaxie
# 310 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieApproachArchie2
# 311 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 312 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_ARCHIE, Common_Movement_WalkInPlaceFasterRight
# 313 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 314 "data/maps/MtPyre_Summit/scripts.pory"
	return
# 315 "data/maps/MtPyre_Summit/scripts.pory"

# 316 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_PlayerFaceMaxie0:
# 317 "data/maps/MtPyre_Summit/scripts.pory"
	delay_16
# 318 "data/maps/MtPyre_Summit/scripts.pory"
	delay_16
# 319 "data/maps/MtPyre_Summit/scripts.pory"
	walk_in_place_faster_right
# 320 "data/maps/MtPyre_Summit/scripts.pory"
	step_end
# 321 "data/maps/MtPyre_Summit/scripts.pory"

# 322 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_PlayerFaceMaxie:
# 323 "data/maps/MtPyre_Summit/scripts.pory"
	delay_16
# 324 "data/maps/MtPyre_Summit/scripts.pory"
	delay_16
# 325 "data/maps/MtPyre_Summit/scripts.pory"
	walk_in_place_faster_left
# 326 "data/maps/MtPyre_Summit/scripts.pory"
	step_end
# 327 "data/maps/MtPyre_Summit/scripts.pory"

# 328 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_ArchieExit:
# 329 "data/maps/MtPyre_Summit/scripts.pory"
	walk_down
# 330 "data/maps/MtPyre_Summit/scripts.pory"
	walk_down
# 331 "data/maps/MtPyre_Summit/scripts.pory"
	walk_down
# 332 "data/maps/MtPyre_Summit/scripts.pory"
	walk_down
# 333 "data/maps/MtPyre_Summit/scripts.pory"
	walk_down
# 334 "data/maps/MtPyre_Summit/scripts.pory"
	walk_down
# 335 "data/maps/MtPyre_Summit/scripts.pory"
	step_end
# 336 "data/maps/MtPyre_Summit/scripts.pory"

# 337 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_MaxieExit:
# 338 "data/maps/MtPyre_Summit/scripts.pory"
	walk_down
# 339 "data/maps/MtPyre_Summit/scripts.pory"
	walk_down
# 340 "data/maps/MtPyre_Summit/scripts.pory"
	walk_down
# 341 "data/maps/MtPyre_Summit/scripts.pory"
	walk_down
# 342 "data/maps/MtPyre_Summit/scripts.pory"
	walk_down
# 343 "data/maps/MtPyre_Summit/scripts.pory"
	walk_down
# 344 "data/maps/MtPyre_Summit/scripts.pory"
	step_end
# 345 "data/maps/MtPyre_Summit/scripts.pory"

# 346 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit0:
# 347 "data/maps/MtPyre_Summit/scripts.pory"
	delay_16
# 348 "data/maps/MtPyre_Summit/scripts.pory"
	delay_8
# 349 "data/maps/MtPyre_Summit/scripts.pory"
	walk_left
# 350 "data/maps/MtPyre_Summit/scripts.pory"
	walk_in_place_faster_right
# 351 "data/maps/MtPyre_Summit/scripts.pory"
	delay_16
# 352 "data/maps/MtPyre_Summit/scripts.pory"
	walk_in_place_faster_down
# 353 "data/maps/MtPyre_Summit/scripts.pory"
	step_end
# 354 "data/maps/MtPyre_Summit/scripts.pory"

# 355 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit1:
# 356 "data/maps/MtPyre_Summit/scripts.pory"
	delay_16
# 357 "data/maps/MtPyre_Summit/scripts.pory"
	delay_8
# 358 "data/maps/MtPyre_Summit/scripts.pory"
	walk_right
# 359 "data/maps/MtPyre_Summit/scripts.pory"
	walk_in_place_faster_left
# 360 "data/maps/MtPyre_Summit/scripts.pory"
	delay_16
# 361 "data/maps/MtPyre_Summit/scripts.pory"
	walk_in_place_faster_down
# 362 "data/maps/MtPyre_Summit/scripts.pory"
	step_end
# 363 "data/maps/MtPyre_Summit/scripts.pory"

# 364 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit2:
# 365 "data/maps/MtPyre_Summit/scripts.pory"
	delay_16
# 366 "data/maps/MtPyre_Summit/scripts.pory"
	delay_8
# 367 "data/maps/MtPyre_Summit/scripts.pory"
	walk_in_place_faster_left
# 368 "data/maps/MtPyre_Summit/scripts.pory"
	delay_16
# 369 "data/maps/MtPyre_Summit/scripts.pory"
	walk_in_place_faster_down
# 370 "data/maps/MtPyre_Summit/scripts.pory"
	step_end
# 371 "data/maps/MtPyre_Summit/scripts.pory"

# 372 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_MaxieApproachPlayer0:
# 373 "data/maps/MtPyre_Summit/scripts.pory"
	walk_up
# 374 "data/maps/MtPyre_Summit/scripts.pory"
	walk_up
# 375 "data/maps/MtPyre_Summit/scripts.pory"
	walk_up
# 376 "data/maps/MtPyre_Summit/scripts.pory"
	walk_left
# 377 "data/maps/MtPyre_Summit/scripts.pory"
	step_end
# 378 "data/maps/MtPyre_Summit/scripts.pory"

# 379 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_MaxieApproachPlayer1:
# 380 "data/maps/MtPyre_Summit/scripts.pory"
	walk_up
# 381 "data/maps/MtPyre_Summit/scripts.pory"
	walk_up
# 382 "data/maps/MtPyre_Summit/scripts.pory"
	walk_up
# 383 "data/maps/MtPyre_Summit/scripts.pory"
	walk_in_place_faster_right
# 384 "data/maps/MtPyre_Summit/scripts.pory"
	step_end
# 385 "data/maps/MtPyre_Summit/scripts.pory"

# 386 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_MaxieApproachPlayer2:
# 387 "data/maps/MtPyre_Summit/scripts.pory"
	walk_up
# 388 "data/maps/MtPyre_Summit/scripts.pory"
	walk_up
# 389 "data/maps/MtPyre_Summit/scripts.pory"
	walk_up
# 390 "data/maps/MtPyre_Summit/scripts.pory"
	walk_in_place_faster_right
# 391 "data/maps/MtPyre_Summit/scripts.pory"
	step_end
# 392 "data/maps/MtPyre_Summit/scripts.pory"

# 393 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_ArchieWatchMaxie:
# 394 "data/maps/MtPyre_Summit/scripts.pory"
	delay_16
# 395 "data/maps/MtPyre_Summit/scripts.pory"
	walk_in_place_faster_up
# 396 "data/maps/MtPyre_Summit/scripts.pory"
	step_end
# 397 "data/maps/MtPyre_Summit/scripts.pory"

# 398 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_PlayerWatchMaxie:
# 399 "data/maps/MtPyre_Summit/scripts.pory"
	delay_16
# 400 "data/maps/MtPyre_Summit/scripts.pory"
	walk_in_place_faster_down
# 401 "data/maps/MtPyre_Summit/scripts.pory"
	step_end
# 402 "data/maps/MtPyre_Summit/scripts.pory"

# 403 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_MaxieApproachArchie0:
# 404 "data/maps/MtPyre_Summit/scripts.pory"
	walk_down
# 405 "data/maps/MtPyre_Summit/scripts.pory"
	walk_right
# 406 "data/maps/MtPyre_Summit/scripts.pory"
	walk_down
# 407 "data/maps/MtPyre_Summit/scripts.pory"
	walk_down
# 408 "data/maps/MtPyre_Summit/scripts.pory"
	walk_in_place_faster_left
# 409 "data/maps/MtPyre_Summit/scripts.pory"
	step_end
# 410 "data/maps/MtPyre_Summit/scripts.pory"

# 411 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_MaxieApproachArchie1:
# 412 "data/maps/MtPyre_Summit/scripts.pory"
	walk_down
# 413 "data/maps/MtPyre_Summit/scripts.pory"
	walk_down
# 414 "data/maps/MtPyre_Summit/scripts.pory"
	walk_down
# 415 "data/maps/MtPyre_Summit/scripts.pory"
	walk_in_place_faster_left
# 416 "data/maps/MtPyre_Summit/scripts.pory"
	step_end
# 417 "data/maps/MtPyre_Summit/scripts.pory"

# 418 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_MaxieApproachArchie2:
# 419 "data/maps/MtPyre_Summit/scripts.pory"
	walk_down
# 420 "data/maps/MtPyre_Summit/scripts.pory"
	walk_down
# 421 "data/maps/MtPyre_Summit/scripts.pory"
	walk_down
# 422 "data/maps/MtPyre_Summit/scripts.pory"
	walk_in_place_faster_left
# 423 "data/maps/MtPyre_Summit/scripts.pory"
	step_end
# 424 "data/maps/MtPyre_Summit/scripts.pory"

# 425 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_Grunt1::
# 426 "data/maps/MtPyre_Summit/scripts.pory"
	trainerbattle_single TRAINER_GRUNT_MT_PYRE_1, MtPyre_Summit_Text_Grunt1Intro, MtPyre_Summit_Text_Grunt1Defeat
# 427 "data/maps/MtPyre_Summit/scripts.pory"
	msgbox MtPyre_Summit_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
# 428 "data/maps/MtPyre_Summit/scripts.pory"
	end
# 429 "data/maps/MtPyre_Summit/scripts.pory"

# 430 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_Grunt2::
# 431 "data/maps/MtPyre_Summit/scripts.pory"
	trainerbattle_single TRAINER_GRUNT_MT_PYRE_2, MtPyre_Summit_Text_Grunt2Intro, MtPyre_Summit_Text_Grunt2Defeat
# 432 "data/maps/MtPyre_Summit/scripts.pory"
	msgbox MtPyre_Summit_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
# 433 "data/maps/MtPyre_Summit/scripts.pory"
	end
# 434 "data/maps/MtPyre_Summit/scripts.pory"

# 435 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_Grunt3::
# 436 "data/maps/MtPyre_Summit/scripts.pory"
	trainerbattle_single TRAINER_GRUNT_MT_PYRE_3, MtPyre_Summit_Text_Grunt3Intro, MtPyre_Summit_Text_Grunt3Defeat
# 437 "data/maps/MtPyre_Summit/scripts.pory"
	msgbox MtPyre_Summit_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
# 438 "data/maps/MtPyre_Summit/scripts.pory"
	end
# 439 "data/maps/MtPyre_Summit/scripts.pory"

# 440 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_Grunt4::
# 441 "data/maps/MtPyre_Summit/scripts.pory"
	trainerbattle_single TRAINER_GRUNT_MT_PYRE_4, MtPyre_Summit_Text_Grunt4Intro, MtPyre_Summit_Text_Grunt4Defeat
# 442 "data/maps/MtPyre_Summit/scripts.pory"
	msgbox MtPyre_Summit_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
# 443 "data/maps/MtPyre_Summit/scripts.pory"
	end
# 444 "data/maps/MtPyre_Summit/scripts.pory"

# 445 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_Grunt1Intro:
# 446 "data/maps/MtPyre_Summit/scripts.pory"
	.string "No! Those TEAM MAGMA goons got\n"
# 447 "data/maps/MtPyre_Summit/scripts.pory"
	.string "here ahead of us!\p"
# 448 "data/maps/MtPyre_Summit/scripts.pory"
	.string "We can't fall behind!$"
# 449 "data/maps/MtPyre_Summit/scripts.pory"

# 450 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_Grunt1Defeat:
# 451 "data/maps/MtPyre_Summit/scripts.pory"
	.string "I thought you were one of the MAGMAS\n"
# 452 "data/maps/MtPyre_Summit/scripts.pory"
	.string "who happened to come back…$"
# 453 "data/maps/MtPyre_Summit/scripts.pory"

# 454 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_Grunt1PostBattle:
# 455 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Yeah, so you are strong…\n"
# 456 "data/maps/MtPyre_Summit/scripts.pory"
	.string "But there're a lot of us!$"
# 457 "data/maps/MtPyre_Summit/scripts.pory"

# 458 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_Grunt2Intro:
# 459 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Hah!\n"
# 460 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Too bad for you!\p"
# 461 "data/maps/MtPyre_Summit/scripts.pory"
	.string "If you came earlier, you only would've\n"
# 462 "data/maps/MtPyre_Summit/scripts.pory"
	.string "had to battle the wimpy TEAM MAGMA.\p"
# 463 "data/maps/MtPyre_Summit/scripts.pory"
	.string "But since you arrived now, you have\n"
# 464 "data/maps/MtPyre_Summit/scripts.pory"
	.string "to take on us toughies!$"
# 465 "data/maps/MtPyre_Summit/scripts.pory"

# 466 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_Grunt2Defeat:
# 467 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Urgh… I should've let you take on\n"
# 468 "data/maps/MtPyre_Summit/scripts.pory"
	.string "TEAM MAGMA first…$"
# 469 "data/maps/MtPyre_Summit/scripts.pory"

# 470 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_Grunt2PostBattle:
# 471 "data/maps/MtPyre_Summit/scripts.pory"
	.string "You don't know anything!\n"
# 472 "data/maps/MtPyre_Summit/scripts.pory"
	.string "So why are you messing with us?$"
# 473 "data/maps/MtPyre_Summit/scripts.pory"

# 474 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_Grunt3Intro:
# 475 "data/maps/MtPyre_Summit/scripts.pory"
	.string "You…\n"
# 476 "data/maps/MtPyre_Summit/scripts.pory"
	.string "We saw you at MT. CHIMNEY.\p"
# 477 "data/maps/MtPyre_Summit/scripts.pory"
	.string "You don't belong to either TEAM,\n"
# 478 "data/maps/MtPyre_Summit/scripts.pory"
	.string "so why would you be here?$"
# 479 "data/maps/MtPyre_Summit/scripts.pory"

# 480 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_Grunt3Defeat:
# 481 "data/maps/MtPyre_Summit/scripts.pory"
	.string "If you're going to mess with anyone,\n"
# 482 "data/maps/MtPyre_Summit/scripts.pory"
	.string "let it be TEAM MAGMA…$"
# 483 "data/maps/MtPyre_Summit/scripts.pory"

# 484 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_Grunt3PostBattle:
# 485 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Heh, it doesn't matter!\n"
# 486 "data/maps/MtPyre_Summit/scripts.pory"
	.string "We bought ourselves some time!\p"
# 487 "data/maps/MtPyre_Summit/scripts.pory"
	.string "The BOSS should have snatched what\n"
# 488 "data/maps/MtPyre_Summit/scripts.pory"
	.string "he was after!$"
# 489 "data/maps/MtPyre_Summit/scripts.pory"

# 490 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_Grunt4Intro:
# 491 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Oh, I know!\n"
# 492 "data/maps/MtPyre_Summit/scripts.pory"
	.string "You tried to join TEAM MAGMA,\l"
# 493 "data/maps/MtPyre_Summit/scripts.pory"
	.string "but they wouldn't have you!\p"
# 494 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Well, don't think that we'll let you\n"
# 495 "data/maps/MtPyre_Summit/scripts.pory"
	.string "join our TEAM AQUA!$"
# 496 "data/maps/MtPyre_Summit/scripts.pory"

# 497 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_Grunt4Defeat:
# 498 "data/maps/MtPyre_Summit/scripts.pory"
	.string "If you want to join TEAM AQUA that\n"
# 499 "data/maps/MtPyre_Summit/scripts.pory"
	.string "badly, we can consider it…$"
# 500 "data/maps/MtPyre_Summit/scripts.pory"

# 501 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_Grunt4PostBattle:
# 502 "data/maps/MtPyre_Summit/scripts.pory"
	.string "We have a great combination going\n"
# 503 "data/maps/MtPyre_Summit/scripts.pory"
	.string "with us members and our leader.$"
# 504 "data/maps/MtPyre_Summit/scripts.pory"

# 505 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_ArchieWeGotTheOrbLetsGo:
# 506 "data/maps/MtPyre_Summit/scripts.pory"
	.string "ARCHIE: TEAM MAGMA's MAXIE got ahead\n"
# 507 "data/maps/MtPyre_Summit/scripts.pory"
	.string "of us, but we also got what we wanted.\p"
# 508 "data/maps/MtPyre_Summit/scripts.pory"
	.string "The RED ORB preserved at MT. PYRE…\n"
# 509 "data/maps/MtPyre_Summit/scripts.pory"
	.string "I, ARCHIE, now have it in my possession!\p"
# 510 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Fufufu… Now we can bring our ultimate\n"
# 511 "data/maps/MtPyre_Summit/scripts.pory"
	.string "objective to fruition!\p"
# 512 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Okay, TEAM!\n"
# 513 "data/maps/MtPyre_Summit/scripts.pory"
	.string "We're pulling out!$"
# 514 "data/maps/MtPyre_Summit/scripts.pory"

# 515 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_BothOrbsTakenMagmaLeftThis:
# 516 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Oh, no…\n"
# 517 "data/maps/MtPyre_Summit/scripts.pory"
	.string "This cannot happen…\p"
# 518 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Not only the BLUE ORB, but even\n"
# 519 "data/maps/MtPyre_Summit/scripts.pory"
	.string "the RED ORB has been taken…\p"
# 520 "data/maps/MtPyre_Summit/scripts.pory"
	.string "The BLUE ORB and RED ORB must never\n"
# 521 "data/maps/MtPyre_Summit/scripts.pory"
	.string "be separated. They belong together.\p"
# 522 "data/maps/MtPyre_Summit/scripts.pory"
	.string "What are those men trying to do with\n"
# 523 "data/maps/MtPyre_Summit/scripts.pory"
	.string "the two ORBS?\p"
# 524 "data/maps/MtPyre_Summit/scripts.pory"
	.string "… … … … … …\n"
# 525 "data/maps/MtPyre_Summit/scripts.pory"
	.string "… … … … … …\p"
# 526 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Oh, yes. Was it TEAM MAGMA who came\n"
# 527 "data/maps/MtPyre_Summit/scripts.pory"
	.string "and took the BLUE ORB first?\p"
# 528 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Well, in their haste, they left this\n"
# 529 "data/maps/MtPyre_Summit/scripts.pory"
	.string "behind.\p"
# 530 "data/maps/MtPyre_Summit/scripts.pory"
	.string "I couldn't imagine what exactly it\n"
# 531 "data/maps/MtPyre_Summit/scripts.pory"
	.string "could be.\p"
# 532 "data/maps/MtPyre_Summit/scripts.pory"
	.string "I would like you to have it.\n"
# 533 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Perhaps it will be useful in some way.$"
# 534 "data/maps/MtPyre_Summit/scripts.pory"

# 535 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_OrbsHaveBeenTaken:
# 536 "data/maps/MtPyre_Summit/scripts.pory"
	.string "The BLUE ORB and RED ORB taken by\n"
# 537 "data/maps/MtPyre_Summit/scripts.pory"
	.string "those sinister men…\p"
# 538 "data/maps/MtPyre_Summit/scripts.pory"
	.string "They must never be apart…\n"
# 539 "data/maps/MtPyre_Summit/scripts.pory"
	.string "I fear something terrible will happen…$"
# 540 "data/maps/MtPyre_Summit/scripts.pory"

# 541 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_GroudonKyogreAwakened:
# 542 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Oh, my goodness…\p"
# 543 "data/maps/MtPyre_Summit/scripts.pory"
	.string "You say that both GROUDON and KYOGRE\n"
# 544 "data/maps/MtPyre_Summit/scripts.pory"
	.string "have been awakened?\p"
# 545 "data/maps/MtPyre_Summit/scripts.pory"
	.string "It is said that the BLUE ORB and\n"
# 546 "data/maps/MtPyre_Summit/scripts.pory"
	.string "the RED ORB quelled the rage of\l"
# 547 "data/maps/MtPyre_Summit/scripts.pory"
	.string "the two POKéMON…\p"
# 548 "data/maps/MtPyre_Summit/scripts.pory"
	.string "It is also said that the true owner\n"
# 549 "data/maps/MtPyre_Summit/scripts.pory"
	.string "of the ORBS still exists.\p"
# 550 "data/maps/MtPyre_Summit/scripts.pory"
	.string "However, no one knows who, or what\n"
# 551 "data/maps/MtPyre_Summit/scripts.pory"
	.string "exactly, the ORBS belong to.\p"
# 552 "data/maps/MtPyre_Summit/scripts.pory"
	.string "It could be a human, or perhaps\n"
# 553 "data/maps/MtPyre_Summit/scripts.pory"
	.string "a POKéMON, but no one knows.$"
# 554 "data/maps/MtPyre_Summit/scripts.pory"

# 555 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_ThoseTwoMenReturnedOrbs:
# 556 "data/maps/MtPyre_Summit/scripts.pory"
	.string "The two men who took the ORBS came\n"
# 557 "data/maps/MtPyre_Summit/scripts.pory"
	.string "back to return them on their own.\p"
# 558 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Those men…\n"
# 559 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Perhaps they are not so evil after all…$"
# 560 "data/maps/MtPyre_Summit/scripts.pory"

# 561 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_SuperAncientPokemonTaughtUs:
# 562 "data/maps/MtPyre_Summit/scripts.pory"
	.string "The embodiments of the land, sea,\n"
# 563 "data/maps/MtPyre_Summit/scripts.pory"
	.string "and the sky…\p"
# 564 "data/maps/MtPyre_Summit/scripts.pory"
	.string "That is said to be the identities of\n"
# 565 "data/maps/MtPyre_Summit/scripts.pory"
	.string "the super-ancient POKéMON…\p"
# 566 "data/maps/MtPyre_Summit/scripts.pory"
	.string "In the same way that we humans and\n"
# 567 "data/maps/MtPyre_Summit/scripts.pory"
	.string "POKéMON have life, our world, too,\l"
# 568 "data/maps/MtPyre_Summit/scripts.pory"
	.string "is alive…\p"
# 569 "data/maps/MtPyre_Summit/scripts.pory"
	.string "The super-ancient POKéMON have\n"
# 570 "data/maps/MtPyre_Summit/scripts.pory"
	.string "taught us that…$"
# 571 "data/maps/MtPyre_Summit/scripts.pory"

# 572 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_WillYouHearOutMyTale:
# 573 "data/maps/MtPyre_Summit/scripts.pory"
	.string "MT. PYRE is where we calm the spirits\n"
# 574 "data/maps/MtPyre_Summit/scripts.pory"
	.string "of POKéMON that have passed on…\p"
# 575 "data/maps/MtPyre_Summit/scripts.pory"
	.string "This is a high place where one can\n"
# 576 "data/maps/MtPyre_Summit/scripts.pory"
	.string "see all of HOENN…\p"
# 577 "data/maps/MtPyre_Summit/scripts.pory"
	.string "The disembodied spirits of POKéMON\n"
# 578 "data/maps/MtPyre_Summit/scripts.pory"
	.string "must find solace here…\p"
# 579 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Is it coincidence that you are here…\p"
# 580 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Will you hear out my tale? A tale long\n"
# 581 "data/maps/MtPyre_Summit/scripts.pory"
	.string "told in the HOENN region?$"
# 582 "data/maps/MtPyre_Summit/scripts.pory"

# 583 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_GroudonKyogreTale:
# 584 "data/maps/MtPyre_Summit/scripts.pory"
	.string "It happened long, long ago…\p"
# 585 "data/maps/MtPyre_Summit/scripts.pory"
	.string "The world was wracked by a ferocious\n"
# 586 "data/maps/MtPyre_Summit/scripts.pory"
	.string "clash between the POKéMON of the land\l"
# 587 "data/maps/MtPyre_Summit/scripts.pory"
	.string "and the POKéMON of the sea…\p"
# 588 "data/maps/MtPyre_Summit/scripts.pory"
	.string "The POKéMON of the land raised\n"
# 589 "data/maps/MtPyre_Summit/scripts.pory"
	.string "mountains and created continents…\p"
# 590 "data/maps/MtPyre_Summit/scripts.pory"
	.string "The POKéMON of the sea raised huge\n"
# 591 "data/maps/MtPyre_Summit/scripts.pory"
	.string "waves and carved out oceans…\p"
# 592 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Their fierce duel raged without end.\p"
# 593 "data/maps/MtPyre_Summit/scripts.pory"
	.string "The world was engulfed in massive\n"
# 594 "data/maps/MtPyre_Summit/scripts.pory"
	.string "infernos and vicious storms.\p"
# 595 "data/maps/MtPyre_Summit/scripts.pory"
	.string "The BLUE ORB and the RED ORB brought\n"
# 596 "data/maps/MtPyre_Summit/scripts.pory"
	.string "an end to the calamity.\p"
# 597 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Light poured from the two ORBS and\n"
# 598 "data/maps/MtPyre_Summit/scripts.pory"
	.string "becalmed the enraged adversaries.\p"
# 599 "data/maps/MtPyre_Summit/scripts.pory"
	.string "The pair, made docile, dove deep into\n"
# 600 "data/maps/MtPyre_Summit/scripts.pory"
	.string "the sea where eventually they\l"
# 601 "data/maps/MtPyre_Summit/scripts.pory"
	.string "disappeared…$"
# 602 "data/maps/MtPyre_Summit/scripts.pory"

# 603 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_WellThatTooIsFine:
# 604 "data/maps/MtPyre_Summit/scripts.pory"
	.string "I see…\n"
# 605 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Well, that, too, is fine…$"
# 606 "data/maps/MtPyre_Summit/scripts.pory"

# 607 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_MaxieSilence:
# 608 "data/maps/MtPyre_Summit/scripts.pory"
	.string "MAXIE: {PLAYER}…\p"
# 609 "data/maps/MtPyre_Summit/scripts.pory"
	.string "… … … … … …\n"
# 610 "data/maps/MtPyre_Summit/scripts.pory"
	.string "… … … … … …$"
# 611 "data/maps/MtPyre_Summit/scripts.pory"

# 612 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_HearTheNewLegendOfHoenn:
# 613 "data/maps/MtPyre_Summit/scripts.pory"
	.string "It is my role to pass on the legends\n"
# 614 "data/maps/MtPyre_Summit/scripts.pory"
	.string "of HOENN to future generations.\p"
# 615 "data/maps/MtPyre_Summit/scripts.pory"
	.string "And the crisis that just ended in\n"
# 616 "data/maps/MtPyre_Summit/scripts.pory"
	.string "SOOTOPOLIS rewrote a legend…\p"
# 617 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Have you the time to hear the new\n"
# 618 "data/maps/MtPyre_Summit/scripts.pory"
	.string "legend of HOENN?$"
# 619 "data/maps/MtPyre_Summit/scripts.pory"

# 620 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_HoennTrioTale:
# 621 "data/maps/MtPyre_Summit/scripts.pory"
	.string "It happened long, long ago…\p"
# 622 "data/maps/MtPyre_Summit/scripts.pory"
	.string "The world was wracked by a ferocious\n"
# 623 "data/maps/MtPyre_Summit/scripts.pory"
	.string "clash between the POKéMON of the land\l"
# 624 "data/maps/MtPyre_Summit/scripts.pory"
	.string "and the POKéMON of the sea…\p"
# 625 "data/maps/MtPyre_Summit/scripts.pory"
	.string "The POKéMON of the land raised\n"
# 626 "data/maps/MtPyre_Summit/scripts.pory"
	.string "mountains and created continents…\p"
# 627 "data/maps/MtPyre_Summit/scripts.pory"
	.string "The POKéMON of the sea raised huge\n"
# 628 "data/maps/MtPyre_Summit/scripts.pory"
	.string "waves and carved out oceans…\p"
# 629 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Their fierce duel raged without end.\p"
# 630 "data/maps/MtPyre_Summit/scripts.pory"
	.string "The world was engulfed in massive\n"
# 631 "data/maps/MtPyre_Summit/scripts.pory"
	.string "fires and vicious storms.\p"
# 632 "data/maps/MtPyre_Summit/scripts.pory"
	.string "It was then that the POKéMON of\n"
# 633 "data/maps/MtPyre_Summit/scripts.pory"
	.string "the sky descended from a storm.\p"
# 634 "data/maps/MtPyre_Summit/scripts.pory"
	.string "The POKéMON, shining a vivid green,\n"
# 635 "data/maps/MtPyre_Summit/scripts.pory"
	.string "becalmed the two enraged POKéMON.\p"
# 636 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Then, its duty done, the green POKéMON\n"
# 637 "data/maps/MtPyre_Summit/scripts.pory"
	.string "flew off into the wild blue yonder…$"
# 638 "data/maps/MtPyre_Summit/scripts.pory"

# 639 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_Arceus::
# 640 "data/maps/MtPyre_Summit/scripts.pory"
    lock
# 641 "data/maps/MtPyre_Summit/scripts.pory"
    faceplayer
# 642 "data/maps/MtPyre_Summit/scripts.pory"
    waitse
# 643 "data/maps/MtPyre_Summit/scripts.pory"
    playmoncry SPECIES_ARCEUS, CRY_MODE_ENCOUNTER
# 644 "data/maps/MtPyre_Summit/scripts.pory"
    delay 40
# 645 "data/maps/MtPyre_Summit/scripts.pory"
    waitmoncry
# 646 "data/maps/MtPyre_Summit/scripts.pory"
    setwildbattle SPECIES_ARCEUS, 70
# 647 "data/maps/MtPyre_Summit/scripts.pory"
    setflag FLAG_SYS_CTRL_OBJ_DELETE
# 648 "data/maps/MtPyre_Summit/scripts.pory"
    special BattleSetup_StartLegendaryBattle
# 649 "data/maps/MtPyre_Summit/scripts.pory"
    waitstate
# 650 "data/maps/MtPyre_Summit/scripts.pory"
    clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 651 "data/maps/MtPyre_Summit/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 652 "data/maps/MtPyre_Summit/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_WON, MtPyre_Summit_EventScript_DefeatedArceus
# 653 "data/maps/MtPyre_Summit/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_RAN, MtPyre_Summit_EventScript_RanFromArceus
# 654 "data/maps/MtPyre_Summit/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, MtPyre_Summit_EventScript_RanFromArceus
# 655 "data/maps/MtPyre_Summit/scripts.pory"
    setflag FLAG_DEFEATED_ARCEUS
# 656 "data/maps/MtPyre_Summit/scripts.pory"
    release
# 657 "data/maps/MtPyre_Summit/scripts.pory"
    end
# 658 "data/maps/MtPyre_Summit/scripts.pory"

# 659 "data/maps/MtPyre_Summit/scripts.pory"

# 660 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_DefeatedArceus::
# 661 "data/maps/MtPyre_Summit/scripts.pory"
    setflag FLAG_DEFEATED_ARCEUS
# 662 "data/maps/MtPyre_Summit/scripts.pory"
    goto Common_EventScript_RemoveStaticPokemon
# 663 "data/maps/MtPyre_Summit/scripts.pory"
    end
# 664 "data/maps/MtPyre_Summit/scripts.pory"

# 665 "data/maps/MtPyre_Summit/scripts.pory"

# 666 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_RanFromArceus::
# 667 "data/maps/MtPyre_Summit/scripts.pory"
    setvar VAR_0x8004, SPECIES_ARCEUS
# 668 "data/maps/MtPyre_Summit/scripts.pory"
    goto Common_EventScript_LegendaryFlewAway
# 669 "data/maps/MtPyre_Summit/scripts.pory"
    end
