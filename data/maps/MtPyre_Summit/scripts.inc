# 1 "data/maps/MtPyre_Summit/scripts.pory"

# 2 "data/maps/MtPyre_Summit/scripts.pory"
.set LOCALID_ARCHIE, 2
# 3 "data/maps/MtPyre_Summit/scripts.pory"
.set LOCALID_OLD_LADY, 3
# 4 "data/maps/MtPyre_Summit/scripts.pory"
.set LOCALID_GRUNT_1, 4
# 5 "data/maps/MtPyre_Summit/scripts.pory"
.set LOCALID_GRUNT_2, 5
# 6 "data/maps/MtPyre_Summit/scripts.pory"
.set LOCALID_GRUNT_3, 6
# 7 "data/maps/MtPyre_Summit/scripts.pory"
.set LOCALID_GRUNT_4, 7
# 8 "data/maps/MtPyre_Summit/scripts.pory"
.set LOCALID_MAXIE, 8
# 9 "data/maps/MtPyre_Summit/scripts.pory"

# 10 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_MapScripts::
# 11 "data/maps/MtPyre_Summit/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, MtPyre_Summit_OnTransition
# 12 "data/maps/MtPyre_Summit/scripts.pory"
	.byte 0
# 13 "data/maps/MtPyre_Summit/scripts.pory"

# 14 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_OnTransition:
# 15 "data/maps/MtPyre_Summit/scripts.pory"
	call_if_eq VAR_MT_PYRE_STATE, 2, MtPyre_Summit_EventScript_SetArchieMaxiePositions
# 16 "data/maps/MtPyre_Summit/scripts.pory"
	end
# 17 "data/maps/MtPyre_Summit/scripts.pory"

# 18 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_SetArchieMaxiePositions::
# 19 "data/maps/MtPyre_Summit/scripts.pory"
	setobjectxyperm LOCALID_MAXIE, 23, 6
# 20 "data/maps/MtPyre_Summit/scripts.pory"
	setobjectxyperm LOCALID_ARCHIE, 22, 6
# 21 "data/maps/MtPyre_Summit/scripts.pory"
	end
# 22 "data/maps/MtPyre_Summit/scripts.pory"

# 23 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_TeamAquaTrigger0::
# 24 "data/maps/MtPyre_Summit/scripts.pory"
	lockall
# 25 "data/maps/MtPyre_Summit/scripts.pory"
	setvar VAR_0x8008, 0
# 26 "data/maps/MtPyre_Summit/scripts.pory"
	goto MtPyre_Summit_EventScript_TeamAquaExits
# 27 "data/maps/MtPyre_Summit/scripts.pory"
	end
# 28 "data/maps/MtPyre_Summit/scripts.pory"

# 29 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_TeamAquaTrigger1::
# 30 "data/maps/MtPyre_Summit/scripts.pory"
	lockall
# 31 "data/maps/MtPyre_Summit/scripts.pory"
	setvar VAR_0x8008, 1
# 32 "data/maps/MtPyre_Summit/scripts.pory"
	goto MtPyre_Summit_EventScript_TeamAquaExits
# 33 "data/maps/MtPyre_Summit/scripts.pory"
	end
# 34 "data/maps/MtPyre_Summit/scripts.pory"

# 35 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_TeamAquaTrigger2::
# 36 "data/maps/MtPyre_Summit/scripts.pory"
	lockall
# 37 "data/maps/MtPyre_Summit/scripts.pory"
	setvar VAR_0x8008, 2
# 38 "data/maps/MtPyre_Summit/scripts.pory"
	goto MtPyre_Summit_EventScript_TeamAquaExits
# 39 "data/maps/MtPyre_Summit/scripts.pory"
	end
# 40 "data/maps/MtPyre_Summit/scripts.pory"

# 41 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_TeamAquaExits::
# 42 "data/maps/MtPyre_Summit/scripts.pory"
	playbgm MUS_ENCOUNTER_AQUA, FALSE
# 43 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
# 44 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 45 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_ARCHIE, Common_Movement_WalkInPlaceFasterDown
# 46 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 47 "data/maps/MtPyre_Summit/scripts.pory"
	delay 50
# 48 "data/maps/MtPyre_Summit/scripts.pory"
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_ArchieFacePlayer0
# 49 "data/maps/MtPyre_Summit/scripts.pory"
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_ArchieFacePlayer1
# 50 "data/maps/MtPyre_Summit/scripts.pory"
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_ArchieFacePlayer2
# 51 "data/maps/MtPyre_Summit/scripts.pory"
	msgbox MtPyre_Summit_Text_ArchieWeGotTheOrbLetsGo, MSGBOX_DEFAULT
# 52 "data/maps/MtPyre_Summit/scripts.pory"
	closemessage
# 53 "data/maps/MtPyre_Summit/scripts.pory"
	fadescreen FADE_TO_BLACK
# 54 "data/maps/MtPyre_Summit/scripts.pory"
	removeobject LOCALID_ARCHIE
# 55 "data/maps/MtPyre_Summit/scripts.pory"
	removeobject LOCALID_GRUNT_1
# 56 "data/maps/MtPyre_Summit/scripts.pory"
	removeobject LOCALID_GRUNT_2
# 57 "data/maps/MtPyre_Summit/scripts.pory"
	removeobject LOCALID_GRUNT_3
# 58 "data/maps/MtPyre_Summit/scripts.pory"
	removeobject LOCALID_GRUNT_4
# 59 "data/maps/MtPyre_Summit/scripts.pory"
	setflag FLAG_HIDE_MT_PYRE_SUMMIT_ARCHIE
# 60 "data/maps/MtPyre_Summit/scripts.pory"
	setflag FLAG_HIDE_MT_PYRE_SUMMIT_TEAM_AQUA
# 61 "data/maps/MtPyre_Summit/scripts.pory"
	fadedefaultbgm
# 62 "data/maps/MtPyre_Summit/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 63 "data/maps/MtPyre_Summit/scripts.pory"
	delay 20
# 64 "data/maps/MtPyre_Summit/scripts.pory"
	setvar VAR_MT_PYRE_STATE, 1
# 65 "data/maps/MtPyre_Summit/scripts.pory"
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_OldLadyApproachPlayer0
# 66 "data/maps/MtPyre_Summit/scripts.pory"
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_OldLadyApproachPlayer1
# 67 "data/maps/MtPyre_Summit/scripts.pory"
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_OldLadyApproachPlayer2
# 68 "data/maps/MtPyre_Summit/scripts.pory"
	msgbox MtPyre_Summit_Text_BothOrbsTakenMagmaLeftThis, MSGBOX_DEFAULT
# 69 "data/maps/MtPyre_Summit/scripts.pory"
	giveitem ITEM_MAGMA_EMBLEM
# 70 "data/maps/MtPyre_Summit/scripts.pory"
	setflag FLAG_RECEIVED_RED_OR_BLUE_ORB
# 71 "data/maps/MtPyre_Summit/scripts.pory"
	setflag FLAG_HIDE_JAGGED_PASS_MAGMA_GUARD
# 72 "data/maps/MtPyre_Summit/scripts.pory"
	releaseall
# 73 "data/maps/MtPyre_Summit/scripts.pory"
	end
# 74 "data/maps/MtPyre_Summit/scripts.pory"

# 75 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_ArchieFacePlayer0::
# 76 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieFacePlayer0
# 77 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 78 "data/maps/MtPyre_Summit/scripts.pory"
	return
# 79 "data/maps/MtPyre_Summit/scripts.pory"

# 80 "data/maps/MtPyre_Summit/scripts.pory"
@ Archie is already facing player
# 81 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_ArchieFacePlayer1::
# 82 "data/maps/MtPyre_Summit/scripts.pory"
	return
# 83 "data/maps/MtPyre_Summit/scripts.pory"

# 84 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_ArchieFacePlayer2::
# 85 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieFacePlayer2
# 86 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 87 "data/maps/MtPyre_Summit/scripts.pory"
	return
# 88 "data/maps/MtPyre_Summit/scripts.pory"

# 89 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_OldLadyApproachPlayer0::
# 90 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_OLD_LADY, MtPyre_Summit_Movement_OldLadyApproachPlayer0
# 91 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 92 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 93 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 94 "data/maps/MtPyre_Summit/scripts.pory"
	return
# 95 "data/maps/MtPyre_Summit/scripts.pory"

# 96 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_OldLadyApproachPlayer1::
# 97 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_OLD_LADY, MtPyre_Summit_Movement_OldLadyApproachPlayer1
# 98 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 99 "data/maps/MtPyre_Summit/scripts.pory"
	return
# 100 "data/maps/MtPyre_Summit/scripts.pory"

# 101 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_OldLadyApproachPlayer2::
# 102 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_OLD_LADY, MtPyre_Summit_Movement_OldLadyApproachPlayer2
# 103 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 104 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 105 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 106 "data/maps/MtPyre_Summit/scripts.pory"
	return
# 107 "data/maps/MtPyre_Summit/scripts.pory"

# 108 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_OldLadyApproachPlayer0:
# 109 "data/maps/MtPyre_Summit/scripts.pory"
	walk_down
# 110 "data/maps/MtPyre_Summit/scripts.pory"
	walk_down
# 111 "data/maps/MtPyre_Summit/scripts.pory"
	walk_in_place_faster_left
# 112 "data/maps/MtPyre_Summit/scripts.pory"
	step_end
# 113 "data/maps/MtPyre_Summit/scripts.pory"

# 114 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_OldLadyApproachPlayer1:
# 115 "data/maps/MtPyre_Summit/scripts.pory"
	walk_down
# 116 "data/maps/MtPyre_Summit/scripts.pory"
	step_end
# 117 "data/maps/MtPyre_Summit/scripts.pory"

# 118 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_OldLadyApproachPlayer2:
# 119 "data/maps/MtPyre_Summit/scripts.pory"
	walk_down
# 120 "data/maps/MtPyre_Summit/scripts.pory"
	walk_down
# 121 "data/maps/MtPyre_Summit/scripts.pory"
	walk_in_place_faster_right
# 122 "data/maps/MtPyre_Summit/scripts.pory"
	step_end
# 123 "data/maps/MtPyre_Summit/scripts.pory"

# 124 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_ArchieFacePlayer0:
# 125 "data/maps/MtPyre_Summit/scripts.pory"
	walk_left
# 126 "data/maps/MtPyre_Summit/scripts.pory"
	walk_in_place_faster_down
# 127 "data/maps/MtPyre_Summit/scripts.pory"
	step_end
# 128 "data/maps/MtPyre_Summit/scripts.pory"

# 129 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_ArchieFacePlayer2:
# 130 "data/maps/MtPyre_Summit/scripts.pory"
	walk_right
# 131 "data/maps/MtPyre_Summit/scripts.pory"
	walk_in_place_faster_down
# 132 "data/maps/MtPyre_Summit/scripts.pory"
	step_end
# 133 "data/maps/MtPyre_Summit/scripts.pory"

# 134 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_OldMan::
# 135 "data/maps/MtPyre_Summit/scripts.pory"
	lock
# 136 "data/maps/MtPyre_Summit/scripts.pory"
	faceplayer
# 137 "data/maps/MtPyre_Summit/scripts.pory"
	goto_if_set FLAG_SOOTOPOLIS_ARCHIE_MAXIE_LEAVE, MtPyre_Summit_EventScript_OldManAfterRayquaza
# 138 "data/maps/MtPyre_Summit/scripts.pory"
	msgbox MtPyre_Summit_Text_WillYouHearOutMyTale, MSGBOX_YESNO
# 139 "data/maps/MtPyre_Summit/scripts.pory"
	call_if_eq VAR_RESULT, YES, MtPyre_Summit_EventScript_OldManTale
# 140 "data/maps/MtPyre_Summit/scripts.pory"
	call_if_eq VAR_RESULT, NO, MtPyre_Summit_EventScript_DeclineOldManTale
# 141 "data/maps/MtPyre_Summit/scripts.pory"
	release
# 142 "data/maps/MtPyre_Summit/scripts.pory"
	end
# 143 "data/maps/MtPyre_Summit/scripts.pory"

# 144 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_OldManAfterRayquaza::
# 145 "data/maps/MtPyre_Summit/scripts.pory"
	msgbox MtPyre_Summit_Text_HearTheNewLegendOfHoenn, MSGBOX_YESNO
# 146 "data/maps/MtPyre_Summit/scripts.pory"
	call_if_eq VAR_RESULT, YES, MtPyre_Summit_EventScript_OldManNewTale
# 147 "data/maps/MtPyre_Summit/scripts.pory"
	call_if_eq VAR_RESULT, NO, MtPyre_Summit_EventScript_DeclineOldManTale
# 148 "data/maps/MtPyre_Summit/scripts.pory"
	release
# 149 "data/maps/MtPyre_Summit/scripts.pory"
	end
# 150 "data/maps/MtPyre_Summit/scripts.pory"

# 151 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_OldManTale::
# 152 "data/maps/MtPyre_Summit/scripts.pory"
	msgbox MtPyre_Summit_Text_GroudonKyogreTale, MSGBOX_DEFAULT
# 153 "data/maps/MtPyre_Summit/scripts.pory"
	return
# 154 "data/maps/MtPyre_Summit/scripts.pory"

# 155 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_DeclineOldManTale::
# 156 "data/maps/MtPyre_Summit/scripts.pory"
	msgbox MtPyre_Summit_Text_WellThatTooIsFine, MSGBOX_DEFAULT
# 157 "data/maps/MtPyre_Summit/scripts.pory"
	return
# 158 "data/maps/MtPyre_Summit/scripts.pory"

# 159 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_OldManNewTale::
# 160 "data/maps/MtPyre_Summit/scripts.pory"
	msgbox MtPyre_Summit_Text_HoennTrioTale, MSGBOX_DEFAULT
# 161 "data/maps/MtPyre_Summit/scripts.pory"
	return
# 162 "data/maps/MtPyre_Summit/scripts.pory"

# 163 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_OldLady::
# 164 "data/maps/MtPyre_Summit/scripts.pory"
	lock
# 165 "data/maps/MtPyre_Summit/scripts.pory"
	faceplayer
# 166 "data/maps/MtPyre_Summit/scripts.pory"
	goto_if_set FLAG_RETURNED_RED_OR_BLUE_ORB, MtPyre_Summit_EventScript_OldLadyAfterOrbsReturned
# 167 "data/maps/MtPyre_Summit/scripts.pory"
	call_if_ge VAR_MT_PYRE_STATE, 3, MtPyre_Summit_EventScript_OldLadyOrbsReturned
# 168 "data/maps/MtPyre_Summit/scripts.pory"
	goto_if_set FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN, MtPyre_Summit_EventScript_OldLadyLegendariesAwake
# 169 "data/maps/MtPyre_Summit/scripts.pory"
	msgbox MtPyre_Summit_Text_OrbsHaveBeenTaken, MSGBOX_DEFAULT
# 170 "data/maps/MtPyre_Summit/scripts.pory"
	release
# 171 "data/maps/MtPyre_Summit/scripts.pory"
	end
# 172 "data/maps/MtPyre_Summit/scripts.pory"

# 173 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_OldLadyOrbsReturned::
# 174 "data/maps/MtPyre_Summit/scripts.pory"
	msgbox MtPyre_Summit_Text_ThoseTwoMenReturnedOrbs, MSGBOX_DEFAULT
# 175 "data/maps/MtPyre_Summit/scripts.pory"
	setflag FLAG_RETURNED_RED_OR_BLUE_ORB
# 176 "data/maps/MtPyre_Summit/scripts.pory"
	release
# 177 "data/maps/MtPyre_Summit/scripts.pory"
	end
# 178 "data/maps/MtPyre_Summit/scripts.pory"

# 179 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_OldLadyLegendariesAwake::
# 180 "data/maps/MtPyre_Summit/scripts.pory"
	msgbox MtPyre_Summit_Text_GroudonKyogreAwakened, MSGBOX_DEFAULT
# 181 "data/maps/MtPyre_Summit/scripts.pory"
	release
# 182 "data/maps/MtPyre_Summit/scripts.pory"
	end
# 183 "data/maps/MtPyre_Summit/scripts.pory"

# 184 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_OldLadyAfterOrbsReturned::
# 185 "data/maps/MtPyre_Summit/scripts.pory"
	msgbox MtPyre_Summit_Text_SuperAncientPokemonTaughtUs, MSGBOX_DEFAULT
# 186 "data/maps/MtPyre_Summit/scripts.pory"
	release
# 187 "data/maps/MtPyre_Summit/scripts.pory"
	end
# 188 "data/maps/MtPyre_Summit/scripts.pory"

# 189 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_ArchieMaxieTrigger0::
# 190 "data/maps/MtPyre_Summit/scripts.pory"
	lockall
# 191 "data/maps/MtPyre_Summit/scripts.pory"
	setvar VAR_0x8008, 0
# 192 "data/maps/MtPyre_Summit/scripts.pory"
	goto MtPyre_Summit_EventScript_ArchieMaxieReturnOrbs
# 193 "data/maps/MtPyre_Summit/scripts.pory"
	end
# 194 "data/maps/MtPyre_Summit/scripts.pory"

# 195 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_ArchieMaxieTrigger1::
# 196 "data/maps/MtPyre_Summit/scripts.pory"
	lockall
# 197 "data/maps/MtPyre_Summit/scripts.pory"
	setvar VAR_0x8008, 1
# 198 "data/maps/MtPyre_Summit/scripts.pory"
	goto MtPyre_Summit_EventScript_ArchieMaxieReturnOrbs
# 199 "data/maps/MtPyre_Summit/scripts.pory"
	end
# 200 "data/maps/MtPyre_Summit/scripts.pory"

# 201 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_ArchieMaxieTrigger2::
# 202 "data/maps/MtPyre_Summit/scripts.pory"
	lockall
# 203 "data/maps/MtPyre_Summit/scripts.pory"
	setvar VAR_0x8008, 2
# 204 "data/maps/MtPyre_Summit/scripts.pory"
	goto MtPyre_Summit_EventScript_ArchieMaxieReturnOrbs
# 205 "data/maps/MtPyre_Summit/scripts.pory"
	end
# 206 "data/maps/MtPyre_Summit/scripts.pory"

# 207 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_ArchieMaxieReturnOrbs::
# 208 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 209 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 210 "data/maps/MtPyre_Summit/scripts.pory"
	delay 60
# 211 "data/maps/MtPyre_Summit/scripts.pory"
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_ArchieMaxieBeginExit0
# 212 "data/maps/MtPyre_Summit/scripts.pory"
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_ArchieMaxieBeginExit1
# 213 "data/maps/MtPyre_Summit/scripts.pory"
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_ArchieMaxieBeginExit2
# 214 "data/maps/MtPyre_Summit/scripts.pory"
	playse SE_PIN
# 215 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_MAXIE, Common_Movement_ExclamationMark
# 216 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 217 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_MAXIE, Common_Movement_Delay48
# 218 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 219 "data/maps/MtPyre_Summit/scripts.pory"
	delay 30
# 220 "data/maps/MtPyre_Summit/scripts.pory"
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_MaxieApproachPlayer0
# 221 "data/maps/MtPyre_Summit/scripts.pory"
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_MaxieApproachPlayer1
# 222 "data/maps/MtPyre_Summit/scripts.pory"
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_MaxieApproachPlayer2
# 223 "data/maps/MtPyre_Summit/scripts.pory"
	msgbox MtPyre_Summit_Text_MaxieSilence, MSGBOX_DEFAULT
# 224 "data/maps/MtPyre_Summit/scripts.pory"
	closemessage
# 225 "data/maps/MtPyre_Summit/scripts.pory"
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_MaxieApproachArchie0
# 226 "data/maps/MtPyre_Summit/scripts.pory"
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_MaxieApproachArchie1
# 227 "data/maps/MtPyre_Summit/scripts.pory"
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_MaxieApproachArchie2
# 228 "data/maps/MtPyre_Summit/scripts.pory"
	delay 30
# 229 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieExit
# 230 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieExit
# 231 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 232 "data/maps/MtPyre_Summit/scripts.pory"
	removeobject LOCALID_ARCHIE
# 233 "data/maps/MtPyre_Summit/scripts.pory"
	removeobject LOCALID_MAXIE
# 234 "data/maps/MtPyre_Summit/scripts.pory"
	setvar VAR_MT_PYRE_STATE, 3
# 235 "data/maps/MtPyre_Summit/scripts.pory"
	releaseall
# 236 "data/maps/MtPyre_Summit/scripts.pory"
	end
# 237 "data/maps/MtPyre_Summit/scripts.pory"

# 238 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_ArchieMaxieBeginExit0::
# 239 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit0
# 240 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieExit
# 241 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieExit
# 242 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 243 "data/maps/MtPyre_Summit/scripts.pory"
	return
# 244 "data/maps/MtPyre_Summit/scripts.pory"

# 245 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_ArchieMaxieBeginExit1::
# 246 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit1
# 247 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieExit
# 248 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieExit
# 249 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 250 "data/maps/MtPyre_Summit/scripts.pory"
	return
# 251 "data/maps/MtPyre_Summit/scripts.pory"

# 252 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_ArchieMaxieBeginExit2::
# 253 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit2
# 254 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieExit
# 255 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieExit
# 256 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 257 "data/maps/MtPyre_Summit/scripts.pory"
	return
# 258 "data/maps/MtPyre_Summit/scripts.pory"

# 259 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_MaxieApproachPlayer0::
# 260 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerFaceMaxie0
# 261 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieWatchMaxie
# 262 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieApproachPlayer0
# 263 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 264 "data/maps/MtPyre_Summit/scripts.pory"
	return
# 265 "data/maps/MtPyre_Summit/scripts.pory"

# 266 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_MaxieApproachPlayer1::
# 267 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerFaceMaxie
# 268 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieWatchMaxie
# 269 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieApproachPlayer1
# 270 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 271 "data/maps/MtPyre_Summit/scripts.pory"
	return
# 272 "data/maps/MtPyre_Summit/scripts.pory"

# 273 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_MaxieApproachPlayer2::
# 274 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerFaceMaxie
# 275 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieWatchMaxie
# 276 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieApproachPlayer2
# 277 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 278 "data/maps/MtPyre_Summit/scripts.pory"
	return
# 279 "data/maps/MtPyre_Summit/scripts.pory"

# 280 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_MaxieApproachArchie0::
# 281 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerWatchMaxie
# 282 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieApproachArchie0
# 283 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 284 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_ARCHIE, Common_Movement_WalkInPlaceFasterRight
# 285 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 286 "data/maps/MtPyre_Summit/scripts.pory"
	return
# 287 "data/maps/MtPyre_Summit/scripts.pory"

# 288 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_MaxieApproachArchie1::
# 289 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerWatchMaxie
# 290 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieApproachArchie1
# 291 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 292 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_ARCHIE, Common_Movement_WalkInPlaceFasterRight
# 293 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 294 "data/maps/MtPyre_Summit/scripts.pory"
	return
# 295 "data/maps/MtPyre_Summit/scripts.pory"

# 296 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_MaxieApproachArchie2::
# 297 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerWatchMaxie
# 298 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieApproachArchie2
# 299 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 300 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_ARCHIE, Common_Movement_WalkInPlaceFasterRight
# 301 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 302 "data/maps/MtPyre_Summit/scripts.pory"
	return
# 303 "data/maps/MtPyre_Summit/scripts.pory"

# 304 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_PlayerFaceMaxie0:
# 305 "data/maps/MtPyre_Summit/scripts.pory"
	delay_16
# 306 "data/maps/MtPyre_Summit/scripts.pory"
	delay_16
# 307 "data/maps/MtPyre_Summit/scripts.pory"
	walk_in_place_faster_right
# 308 "data/maps/MtPyre_Summit/scripts.pory"
	step_end
# 309 "data/maps/MtPyre_Summit/scripts.pory"

# 310 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_PlayerFaceMaxie:
# 311 "data/maps/MtPyre_Summit/scripts.pory"
	delay_16
# 312 "data/maps/MtPyre_Summit/scripts.pory"
	delay_16
# 313 "data/maps/MtPyre_Summit/scripts.pory"
	walk_in_place_faster_left
# 314 "data/maps/MtPyre_Summit/scripts.pory"
	step_end
# 315 "data/maps/MtPyre_Summit/scripts.pory"

# 316 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_ArchieExit:
# 317 "data/maps/MtPyre_Summit/scripts.pory"
	walk_down
# 318 "data/maps/MtPyre_Summit/scripts.pory"
	walk_down
# 319 "data/maps/MtPyre_Summit/scripts.pory"
	walk_down
# 320 "data/maps/MtPyre_Summit/scripts.pory"
	walk_down
# 321 "data/maps/MtPyre_Summit/scripts.pory"
	walk_down
# 322 "data/maps/MtPyre_Summit/scripts.pory"
	walk_down
# 323 "data/maps/MtPyre_Summit/scripts.pory"
	step_end
# 324 "data/maps/MtPyre_Summit/scripts.pory"

# 325 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_MaxieExit:
# 326 "data/maps/MtPyre_Summit/scripts.pory"
	walk_down
# 327 "data/maps/MtPyre_Summit/scripts.pory"
	walk_down
# 328 "data/maps/MtPyre_Summit/scripts.pory"
	walk_down
# 329 "data/maps/MtPyre_Summit/scripts.pory"
	walk_down
# 330 "data/maps/MtPyre_Summit/scripts.pory"
	walk_down
# 331 "data/maps/MtPyre_Summit/scripts.pory"
	walk_down
# 332 "data/maps/MtPyre_Summit/scripts.pory"
	step_end
# 333 "data/maps/MtPyre_Summit/scripts.pory"

# 334 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit0:
# 335 "data/maps/MtPyre_Summit/scripts.pory"
	delay_16
# 336 "data/maps/MtPyre_Summit/scripts.pory"
	delay_8
# 337 "data/maps/MtPyre_Summit/scripts.pory"
	walk_left
# 338 "data/maps/MtPyre_Summit/scripts.pory"
	walk_in_place_faster_right
# 339 "data/maps/MtPyre_Summit/scripts.pory"
	delay_16
# 340 "data/maps/MtPyre_Summit/scripts.pory"
	walk_in_place_faster_down
# 341 "data/maps/MtPyre_Summit/scripts.pory"
	step_end
# 342 "data/maps/MtPyre_Summit/scripts.pory"

# 343 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit1:
# 344 "data/maps/MtPyre_Summit/scripts.pory"
	delay_16
# 345 "data/maps/MtPyre_Summit/scripts.pory"
	delay_8
# 346 "data/maps/MtPyre_Summit/scripts.pory"
	walk_right
# 347 "data/maps/MtPyre_Summit/scripts.pory"
	walk_in_place_faster_left
# 348 "data/maps/MtPyre_Summit/scripts.pory"
	delay_16
# 349 "data/maps/MtPyre_Summit/scripts.pory"
	walk_in_place_faster_down
# 350 "data/maps/MtPyre_Summit/scripts.pory"
	step_end
# 351 "data/maps/MtPyre_Summit/scripts.pory"

# 352 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit2:
# 353 "data/maps/MtPyre_Summit/scripts.pory"
	delay_16
# 354 "data/maps/MtPyre_Summit/scripts.pory"
	delay_8
# 355 "data/maps/MtPyre_Summit/scripts.pory"
	walk_in_place_faster_left
# 356 "data/maps/MtPyre_Summit/scripts.pory"
	delay_16
# 357 "data/maps/MtPyre_Summit/scripts.pory"
	walk_in_place_faster_down
# 358 "data/maps/MtPyre_Summit/scripts.pory"
	step_end
# 359 "data/maps/MtPyre_Summit/scripts.pory"

# 360 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_MaxieApproachPlayer0:
# 361 "data/maps/MtPyre_Summit/scripts.pory"
	walk_up
# 362 "data/maps/MtPyre_Summit/scripts.pory"
	walk_up
# 363 "data/maps/MtPyre_Summit/scripts.pory"
	walk_up
# 364 "data/maps/MtPyre_Summit/scripts.pory"
	walk_left
# 365 "data/maps/MtPyre_Summit/scripts.pory"
	step_end
# 366 "data/maps/MtPyre_Summit/scripts.pory"

# 367 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_MaxieApproachPlayer1:
# 368 "data/maps/MtPyre_Summit/scripts.pory"
	walk_up
# 369 "data/maps/MtPyre_Summit/scripts.pory"
	walk_up
# 370 "data/maps/MtPyre_Summit/scripts.pory"
	walk_up
# 371 "data/maps/MtPyre_Summit/scripts.pory"
	walk_in_place_faster_right
# 372 "data/maps/MtPyre_Summit/scripts.pory"
	step_end
# 373 "data/maps/MtPyre_Summit/scripts.pory"

# 374 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_MaxieApproachPlayer2:
# 375 "data/maps/MtPyre_Summit/scripts.pory"
	walk_up
# 376 "data/maps/MtPyre_Summit/scripts.pory"
	walk_up
# 377 "data/maps/MtPyre_Summit/scripts.pory"
	walk_up
# 378 "data/maps/MtPyre_Summit/scripts.pory"
	walk_in_place_faster_right
# 379 "data/maps/MtPyre_Summit/scripts.pory"
	step_end
# 380 "data/maps/MtPyre_Summit/scripts.pory"

# 381 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_ArchieWatchMaxie:
# 382 "data/maps/MtPyre_Summit/scripts.pory"
	delay_16
# 383 "data/maps/MtPyre_Summit/scripts.pory"
	walk_in_place_faster_up
# 384 "data/maps/MtPyre_Summit/scripts.pory"
	step_end
# 385 "data/maps/MtPyre_Summit/scripts.pory"

# 386 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_PlayerWatchMaxie:
# 387 "data/maps/MtPyre_Summit/scripts.pory"
	delay_16
# 388 "data/maps/MtPyre_Summit/scripts.pory"
	walk_in_place_faster_down
# 389 "data/maps/MtPyre_Summit/scripts.pory"
	step_end
# 390 "data/maps/MtPyre_Summit/scripts.pory"

# 391 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_MaxieApproachArchie0:
# 392 "data/maps/MtPyre_Summit/scripts.pory"
	walk_down
# 393 "data/maps/MtPyre_Summit/scripts.pory"
	walk_right
# 394 "data/maps/MtPyre_Summit/scripts.pory"
	walk_down
# 395 "data/maps/MtPyre_Summit/scripts.pory"
	walk_down
# 396 "data/maps/MtPyre_Summit/scripts.pory"
	walk_in_place_faster_left
# 397 "data/maps/MtPyre_Summit/scripts.pory"
	step_end
# 398 "data/maps/MtPyre_Summit/scripts.pory"

# 399 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_MaxieApproachArchie1:
# 400 "data/maps/MtPyre_Summit/scripts.pory"
	walk_down
# 401 "data/maps/MtPyre_Summit/scripts.pory"
	walk_down
# 402 "data/maps/MtPyre_Summit/scripts.pory"
	walk_down
# 403 "data/maps/MtPyre_Summit/scripts.pory"
	walk_in_place_faster_left
# 404 "data/maps/MtPyre_Summit/scripts.pory"
	step_end
# 405 "data/maps/MtPyre_Summit/scripts.pory"

# 406 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_MaxieApproachArchie2:
# 407 "data/maps/MtPyre_Summit/scripts.pory"
	walk_down
# 408 "data/maps/MtPyre_Summit/scripts.pory"
	walk_down
# 409 "data/maps/MtPyre_Summit/scripts.pory"
	walk_down
# 410 "data/maps/MtPyre_Summit/scripts.pory"
	walk_in_place_faster_left
# 411 "data/maps/MtPyre_Summit/scripts.pory"
	step_end
# 412 "data/maps/MtPyre_Summit/scripts.pory"

# 413 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_Grunt1::
# 414 "data/maps/MtPyre_Summit/scripts.pory"
	trainerbattle_single TRAINER_GRUNT_MT_PYRE_1, MtPyre_Summit_Text_Grunt1Intro, MtPyre_Summit_Text_Grunt1Defeat
# 415 "data/maps/MtPyre_Summit/scripts.pory"
	msgbox MtPyre_Summit_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
# 416 "data/maps/MtPyre_Summit/scripts.pory"
	end
# 417 "data/maps/MtPyre_Summit/scripts.pory"

# 418 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_Grunt2::
# 419 "data/maps/MtPyre_Summit/scripts.pory"
	trainerbattle_single TRAINER_GRUNT_MT_PYRE_2, MtPyre_Summit_Text_Grunt2Intro, MtPyre_Summit_Text_Grunt2Defeat
# 420 "data/maps/MtPyre_Summit/scripts.pory"
	msgbox MtPyre_Summit_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
# 421 "data/maps/MtPyre_Summit/scripts.pory"
	end
# 422 "data/maps/MtPyre_Summit/scripts.pory"

# 423 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_Grunt3::
# 424 "data/maps/MtPyre_Summit/scripts.pory"
	trainerbattle_single TRAINER_GRUNT_MT_PYRE_3, MtPyre_Summit_Text_Grunt3Intro, MtPyre_Summit_Text_Grunt3Defeat
# 425 "data/maps/MtPyre_Summit/scripts.pory"
	msgbox MtPyre_Summit_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
# 426 "data/maps/MtPyre_Summit/scripts.pory"
	end
# 427 "data/maps/MtPyre_Summit/scripts.pory"

# 428 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_Grunt4::
# 429 "data/maps/MtPyre_Summit/scripts.pory"
	trainerbattle_single TRAINER_GRUNT_MT_PYRE_4, MtPyre_Summit_Text_Grunt4Intro, MtPyre_Summit_Text_Grunt4Defeat
# 430 "data/maps/MtPyre_Summit/scripts.pory"
	msgbox MtPyre_Summit_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
# 431 "data/maps/MtPyre_Summit/scripts.pory"
	end
# 432 "data/maps/MtPyre_Summit/scripts.pory"

# 433 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_Grunt1Intro:
# 434 "data/maps/MtPyre_Summit/scripts.pory"
	.string "No! Those TEAM MAGMA goons got\n"
# 435 "data/maps/MtPyre_Summit/scripts.pory"
	.string "here ahead of us!\p"
# 436 "data/maps/MtPyre_Summit/scripts.pory"
	.string "We can't fall behind!$"
# 437 "data/maps/MtPyre_Summit/scripts.pory"

# 438 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_Grunt1Defeat:
# 439 "data/maps/MtPyre_Summit/scripts.pory"
	.string "I thought you were one of the MAGMAS\n"
# 440 "data/maps/MtPyre_Summit/scripts.pory"
	.string "who happened to come back…$"
# 441 "data/maps/MtPyre_Summit/scripts.pory"

# 442 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_Grunt1PostBattle:
# 443 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Yeah, so you are strong…\n"
# 444 "data/maps/MtPyre_Summit/scripts.pory"
	.string "But there're a lot of us!$"
# 445 "data/maps/MtPyre_Summit/scripts.pory"

# 446 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_Grunt2Intro:
# 447 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Hah!\n"
# 448 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Too bad for you!\p"
# 449 "data/maps/MtPyre_Summit/scripts.pory"
	.string "If you came earlier, you only would've\n"
# 450 "data/maps/MtPyre_Summit/scripts.pory"
	.string "had to battle the wimpy TEAM MAGMA.\p"
# 451 "data/maps/MtPyre_Summit/scripts.pory"
	.string "But since you arrived now, you have\n"
# 452 "data/maps/MtPyre_Summit/scripts.pory"
	.string "to take on us toughies!$"
# 453 "data/maps/MtPyre_Summit/scripts.pory"

# 454 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_Grunt2Defeat:
# 455 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Urgh… I should've let you take on\n"
# 456 "data/maps/MtPyre_Summit/scripts.pory"
	.string "TEAM MAGMA first…$"
# 457 "data/maps/MtPyre_Summit/scripts.pory"

# 458 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_Grunt2PostBattle:
# 459 "data/maps/MtPyre_Summit/scripts.pory"
	.string "You don't know anything!\n"
# 460 "data/maps/MtPyre_Summit/scripts.pory"
	.string "So why are you messing with us?$"
# 461 "data/maps/MtPyre_Summit/scripts.pory"

# 462 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_Grunt3Intro:
# 463 "data/maps/MtPyre_Summit/scripts.pory"
	.string "You…\n"
# 464 "data/maps/MtPyre_Summit/scripts.pory"
	.string "We saw you at MT. CHIMNEY.\p"
# 465 "data/maps/MtPyre_Summit/scripts.pory"
	.string "You don't belong to either TEAM,\n"
# 466 "data/maps/MtPyre_Summit/scripts.pory"
	.string "so why would you be here?$"
# 467 "data/maps/MtPyre_Summit/scripts.pory"

# 468 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_Grunt3Defeat:
# 469 "data/maps/MtPyre_Summit/scripts.pory"
	.string "If you're going to mess with anyone,\n"
# 470 "data/maps/MtPyre_Summit/scripts.pory"
	.string "let it be TEAM MAGMA…$"
# 471 "data/maps/MtPyre_Summit/scripts.pory"

# 472 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_Grunt3PostBattle:
# 473 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Heh, it doesn't matter!\n"
# 474 "data/maps/MtPyre_Summit/scripts.pory"
	.string "We bought ourselves some time!\p"
# 475 "data/maps/MtPyre_Summit/scripts.pory"
	.string "The BOSS should have snatched what\n"
# 476 "data/maps/MtPyre_Summit/scripts.pory"
	.string "he was after!$"
# 477 "data/maps/MtPyre_Summit/scripts.pory"

# 478 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_Grunt4Intro:
# 479 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Oh, I know!\n"
# 480 "data/maps/MtPyre_Summit/scripts.pory"
	.string "You tried to join TEAM MAGMA,\l"
# 481 "data/maps/MtPyre_Summit/scripts.pory"
	.string "but they wouldn't have you!\p"
# 482 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Well, don't think that we'll let you\n"
# 483 "data/maps/MtPyre_Summit/scripts.pory"
	.string "join our TEAM AQUA!$"
# 484 "data/maps/MtPyre_Summit/scripts.pory"

# 485 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_Grunt4Defeat:
# 486 "data/maps/MtPyre_Summit/scripts.pory"
	.string "If you want to join TEAM AQUA that\n"
# 487 "data/maps/MtPyre_Summit/scripts.pory"
	.string "badly, we can consider it…$"
# 488 "data/maps/MtPyre_Summit/scripts.pory"

# 489 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_Grunt4PostBattle:
# 490 "data/maps/MtPyre_Summit/scripts.pory"
	.string "We have a great combination going\n"
# 491 "data/maps/MtPyre_Summit/scripts.pory"
	.string "with us members and our leader.$"
# 492 "data/maps/MtPyre_Summit/scripts.pory"

# 493 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_ArchieWeGotTheOrbLetsGo:
# 494 "data/maps/MtPyre_Summit/scripts.pory"
	.string "ARCHIE: TEAM MAGMA's MAXIE got ahead\n"
# 495 "data/maps/MtPyre_Summit/scripts.pory"
	.string "of us, but we also got what we wanted.\p"
# 496 "data/maps/MtPyre_Summit/scripts.pory"
	.string "The RED ORB preserved at MT. PYRE…\n"
# 497 "data/maps/MtPyre_Summit/scripts.pory"
	.string "I, ARCHIE, now have it in my possession!\p"
# 498 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Fufufu… Now we can bring our ultimate\n"
# 499 "data/maps/MtPyre_Summit/scripts.pory"
	.string "objective to fruition!\p"
# 500 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Okay, TEAM!\n"
# 501 "data/maps/MtPyre_Summit/scripts.pory"
	.string "We're pulling out!$"
# 502 "data/maps/MtPyre_Summit/scripts.pory"

# 503 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_BothOrbsTakenMagmaLeftThis:
# 504 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Oh, no…\n"
# 505 "data/maps/MtPyre_Summit/scripts.pory"
	.string "This cannot happen…\p"
# 506 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Not only the BLUE ORB, but even\n"
# 507 "data/maps/MtPyre_Summit/scripts.pory"
	.string "the RED ORB has been taken…\p"
# 508 "data/maps/MtPyre_Summit/scripts.pory"
	.string "The BLUE ORB and RED ORB must never\n"
# 509 "data/maps/MtPyre_Summit/scripts.pory"
	.string "be separated. They belong together.\p"
# 510 "data/maps/MtPyre_Summit/scripts.pory"
	.string "What are those men trying to do with\n"
# 511 "data/maps/MtPyre_Summit/scripts.pory"
	.string "the two ORBS?\p"
# 512 "data/maps/MtPyre_Summit/scripts.pory"
	.string "… … … … … …\n"
# 513 "data/maps/MtPyre_Summit/scripts.pory"
	.string "… … … … … …\p"
# 514 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Oh, yes. Was it TEAM MAGMA who came\n"
# 515 "data/maps/MtPyre_Summit/scripts.pory"
	.string "and took the BLUE ORB first?\p"
# 516 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Well, in their haste, they left this\n"
# 517 "data/maps/MtPyre_Summit/scripts.pory"
	.string "behind.\p"
# 518 "data/maps/MtPyre_Summit/scripts.pory"
	.string "I couldn't imagine what exactly it\n"
# 519 "data/maps/MtPyre_Summit/scripts.pory"
	.string "could be.\p"
# 520 "data/maps/MtPyre_Summit/scripts.pory"
	.string "I would like you to have it.\n"
# 521 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Perhaps it will be useful in some way.$"
# 522 "data/maps/MtPyre_Summit/scripts.pory"

# 523 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_OrbsHaveBeenTaken:
# 524 "data/maps/MtPyre_Summit/scripts.pory"
	.string "The BLUE ORB and RED ORB taken by\n"
# 525 "data/maps/MtPyre_Summit/scripts.pory"
	.string "those sinister men…\p"
# 526 "data/maps/MtPyre_Summit/scripts.pory"
	.string "They must never be apart…\n"
# 527 "data/maps/MtPyre_Summit/scripts.pory"
	.string "I fear something terrible will happen…$"
# 528 "data/maps/MtPyre_Summit/scripts.pory"

# 529 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_GroudonKyogreAwakened:
# 530 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Oh, my goodness…\p"
# 531 "data/maps/MtPyre_Summit/scripts.pory"
	.string "You say that both GROUDON and KYOGRE\n"
# 532 "data/maps/MtPyre_Summit/scripts.pory"
	.string "have been awakened?\p"
# 533 "data/maps/MtPyre_Summit/scripts.pory"
	.string "It is said that the BLUE ORB and\n"
# 534 "data/maps/MtPyre_Summit/scripts.pory"
	.string "the RED ORB quelled the rage of\l"
# 535 "data/maps/MtPyre_Summit/scripts.pory"
	.string "the two POKéMON…\p"
# 536 "data/maps/MtPyre_Summit/scripts.pory"
	.string "It is also said that the true owner\n"
# 537 "data/maps/MtPyre_Summit/scripts.pory"
	.string "of the ORBS still exists.\p"
# 538 "data/maps/MtPyre_Summit/scripts.pory"
	.string "However, no one knows who, or what\n"
# 539 "data/maps/MtPyre_Summit/scripts.pory"
	.string "exactly, the ORBS belong to.\p"
# 540 "data/maps/MtPyre_Summit/scripts.pory"
	.string "It could be a human, or perhaps\n"
# 541 "data/maps/MtPyre_Summit/scripts.pory"
	.string "a POKéMON, but no one knows.$"
# 542 "data/maps/MtPyre_Summit/scripts.pory"

# 543 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_ThoseTwoMenReturnedOrbs:
# 544 "data/maps/MtPyre_Summit/scripts.pory"
	.string "The two men who took the ORBS came\n"
# 545 "data/maps/MtPyre_Summit/scripts.pory"
	.string "back to return them on their own.\p"
# 546 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Those men…\n"
# 547 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Perhaps they are not so evil after all…$"
# 548 "data/maps/MtPyre_Summit/scripts.pory"

# 549 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_SuperAncientPokemonTaughtUs:
# 550 "data/maps/MtPyre_Summit/scripts.pory"
	.string "The embodiments of the land, sea,\n"
# 551 "data/maps/MtPyre_Summit/scripts.pory"
	.string "and the sky…\p"
# 552 "data/maps/MtPyre_Summit/scripts.pory"
	.string "That is said to be the identities of\n"
# 553 "data/maps/MtPyre_Summit/scripts.pory"
	.string "the super-ancient POKéMON…\p"
# 554 "data/maps/MtPyre_Summit/scripts.pory"
	.string "In the same way that we humans and\n"
# 555 "data/maps/MtPyre_Summit/scripts.pory"
	.string "POKéMON have life, our world, too,\l"
# 556 "data/maps/MtPyre_Summit/scripts.pory"
	.string "is alive…\p"
# 557 "data/maps/MtPyre_Summit/scripts.pory"
	.string "The super-ancient POKéMON have\n"
# 558 "data/maps/MtPyre_Summit/scripts.pory"
	.string "taught us that…$"
# 559 "data/maps/MtPyre_Summit/scripts.pory"

# 560 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_WillYouHearOutMyTale:
# 561 "data/maps/MtPyre_Summit/scripts.pory"
	.string "MT. PYRE is where we calm the spirits\n"
# 562 "data/maps/MtPyre_Summit/scripts.pory"
	.string "of POKéMON that have passed on…\p"
# 563 "data/maps/MtPyre_Summit/scripts.pory"
	.string "This is a high place where one can\n"
# 564 "data/maps/MtPyre_Summit/scripts.pory"
	.string "see all of HOENN…\p"
# 565 "data/maps/MtPyre_Summit/scripts.pory"
	.string "The disembodied spirits of POKéMON\n"
# 566 "data/maps/MtPyre_Summit/scripts.pory"
	.string "must find solace here…\p"
# 567 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Is it coincidence that you are here…\p"
# 568 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Will you hear out my tale? A tale long\n"
# 569 "data/maps/MtPyre_Summit/scripts.pory"
	.string "told in the HOENN region?$"
# 570 "data/maps/MtPyre_Summit/scripts.pory"

# 571 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_GroudonKyogreTale:
# 572 "data/maps/MtPyre_Summit/scripts.pory"
	.string "It happened long, long ago…\p"
# 573 "data/maps/MtPyre_Summit/scripts.pory"
	.string "The world was wracked by a ferocious\n"
# 574 "data/maps/MtPyre_Summit/scripts.pory"
	.string "clash between the POKéMON of the land\l"
# 575 "data/maps/MtPyre_Summit/scripts.pory"
	.string "and the POKéMON of the sea…\p"
# 576 "data/maps/MtPyre_Summit/scripts.pory"
	.string "The POKéMON of the land raised\n"
# 577 "data/maps/MtPyre_Summit/scripts.pory"
	.string "mountains and created continents…\p"
# 578 "data/maps/MtPyre_Summit/scripts.pory"
	.string "The POKéMON of the sea raised huge\n"
# 579 "data/maps/MtPyre_Summit/scripts.pory"
	.string "waves and carved out oceans…\p"
# 580 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Their fierce duel raged without end.\p"
# 581 "data/maps/MtPyre_Summit/scripts.pory"
	.string "The world was engulfed in massive\n"
# 582 "data/maps/MtPyre_Summit/scripts.pory"
	.string "infernos and vicious storms.\p"
# 583 "data/maps/MtPyre_Summit/scripts.pory"
	.string "The BLUE ORB and the RED ORB brought\n"
# 584 "data/maps/MtPyre_Summit/scripts.pory"
	.string "an end to the calamity.\p"
# 585 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Light poured from the two ORBS and\n"
# 586 "data/maps/MtPyre_Summit/scripts.pory"
	.string "becalmed the enraged adversaries.\p"
# 587 "data/maps/MtPyre_Summit/scripts.pory"
	.string "The pair, made docile, dove deep into\n"
# 588 "data/maps/MtPyre_Summit/scripts.pory"
	.string "the sea where eventually they\l"
# 589 "data/maps/MtPyre_Summit/scripts.pory"
	.string "disappeared…$"
# 590 "data/maps/MtPyre_Summit/scripts.pory"

# 591 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_WellThatTooIsFine:
# 592 "data/maps/MtPyre_Summit/scripts.pory"
	.string "I see…\n"
# 593 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Well, that, too, is fine…$"
# 594 "data/maps/MtPyre_Summit/scripts.pory"

# 595 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_MaxieSilence:
# 596 "data/maps/MtPyre_Summit/scripts.pory"
	.string "MAXIE: {PLAYER}…\p"
# 597 "data/maps/MtPyre_Summit/scripts.pory"
	.string "… … … … … …\n"
# 598 "data/maps/MtPyre_Summit/scripts.pory"
	.string "… … … … … …$"
# 599 "data/maps/MtPyre_Summit/scripts.pory"

# 600 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_HearTheNewLegendOfHoenn:
# 601 "data/maps/MtPyre_Summit/scripts.pory"
	.string "It is my role to pass on the legends\n"
# 602 "data/maps/MtPyre_Summit/scripts.pory"
	.string "of HOENN to future generations.\p"
# 603 "data/maps/MtPyre_Summit/scripts.pory"
	.string "And the crisis that just ended in\n"
# 604 "data/maps/MtPyre_Summit/scripts.pory"
	.string "SOOTOPOLIS rewrote a legend…\p"
# 605 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Have you the time to hear the new\n"
# 606 "data/maps/MtPyre_Summit/scripts.pory"
	.string "legend of HOENN?$"
# 607 "data/maps/MtPyre_Summit/scripts.pory"

# 608 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_HoennTrioTale:
# 609 "data/maps/MtPyre_Summit/scripts.pory"
	.string "It happened long, long ago…\p"
# 610 "data/maps/MtPyre_Summit/scripts.pory"
	.string "The world was wracked by a ferocious\n"
# 611 "data/maps/MtPyre_Summit/scripts.pory"
	.string "clash between the POKéMON of the land\l"
# 612 "data/maps/MtPyre_Summit/scripts.pory"
	.string "and the POKéMON of the sea…\p"
# 613 "data/maps/MtPyre_Summit/scripts.pory"
	.string "The POKéMON of the land raised\n"
# 614 "data/maps/MtPyre_Summit/scripts.pory"
	.string "mountains and created continents…\p"
# 615 "data/maps/MtPyre_Summit/scripts.pory"
	.string "The POKéMON of the sea raised huge\n"
# 616 "data/maps/MtPyre_Summit/scripts.pory"
	.string "waves and carved out oceans…\p"
# 617 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Their fierce duel raged without end.\p"
# 618 "data/maps/MtPyre_Summit/scripts.pory"
	.string "The world was engulfed in massive\n"
# 619 "data/maps/MtPyre_Summit/scripts.pory"
	.string "fires and vicious storms.\p"
# 620 "data/maps/MtPyre_Summit/scripts.pory"
	.string "It was then that the POKéMON of\n"
# 621 "data/maps/MtPyre_Summit/scripts.pory"
	.string "the sky descended from a storm.\p"
# 622 "data/maps/MtPyre_Summit/scripts.pory"
	.string "The POKéMON, shining a vivid green,\n"
# 623 "data/maps/MtPyre_Summit/scripts.pory"
	.string "becalmed the two enraged POKéMON.\p"
# 624 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Then, its duty done, the green POKéMON\n"
# 625 "data/maps/MtPyre_Summit/scripts.pory"
	.string "flew off into the wild blue yonder…$"
