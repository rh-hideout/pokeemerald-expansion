# 1 "data/maps/MtPyre_Summit/scripts.pory"

# 2 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_MapScripts::
# 3 "data/maps/MtPyre_Summit/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, MtPyre_Summit_OnTransition
# 4 "data/maps/MtPyre_Summit/scripts.pory"
	.byte 0
# 5 "data/maps/MtPyre_Summit/scripts.pory"

# 6 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_OnTransition:
# 7 "data/maps/MtPyre_Summit/scripts.pory"
	call_if_eq VAR_MT_PYRE_STATE, 2, MtPyre_Summit_EventScript_SetArchieMaxiePositions
# 8 "data/maps/MtPyre_Summit/scripts.pory"
	end
# 9 "data/maps/MtPyre_Summit/scripts.pory"

# 10 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_SetArchieMaxiePositions::
# 11 "data/maps/MtPyre_Summit/scripts.pory"
	setobjectxyperm LOCALID_MT_PYRE_SUMMIT_MAXIE, 23, 6
# 12 "data/maps/MtPyre_Summit/scripts.pory"
	setobjectxyperm LOCALID_MT_PYRE_SUMMIT_ARCHIE, 22, 6
# 13 "data/maps/MtPyre_Summit/scripts.pory"
	end
# 14 "data/maps/MtPyre_Summit/scripts.pory"

# 15 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_TeamAquaTrigger0::
# 16 "data/maps/MtPyre_Summit/scripts.pory"
	lockall
# 17 "data/maps/MtPyre_Summit/scripts.pory"
	setvar VAR_0x8008, 0
# 18 "data/maps/MtPyre_Summit/scripts.pory"
	goto MtPyre_Summit_EventScript_TeamAquaExits
# 19 "data/maps/MtPyre_Summit/scripts.pory"
	end
# 20 "data/maps/MtPyre_Summit/scripts.pory"

# 21 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_TeamAquaTrigger1::
# 22 "data/maps/MtPyre_Summit/scripts.pory"
	lockall
# 23 "data/maps/MtPyre_Summit/scripts.pory"
	setvar VAR_0x8008, 1
# 24 "data/maps/MtPyre_Summit/scripts.pory"
	goto MtPyre_Summit_EventScript_TeamAquaExits
# 25 "data/maps/MtPyre_Summit/scripts.pory"
	end
# 26 "data/maps/MtPyre_Summit/scripts.pory"

# 27 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_TeamAquaTrigger2::
# 28 "data/maps/MtPyre_Summit/scripts.pory"
	lockall
# 29 "data/maps/MtPyre_Summit/scripts.pory"
	setvar VAR_0x8008, 2
# 30 "data/maps/MtPyre_Summit/scripts.pory"
	goto MtPyre_Summit_EventScript_TeamAquaExits
# 31 "data/maps/MtPyre_Summit/scripts.pory"
	end
# 32 "data/maps/MtPyre_Summit/scripts.pory"

# 33 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_TeamAquaExits::
# 34 "data/maps/MtPyre_Summit/scripts.pory"
	playbgm MUS_ENCOUNTER_AQUA, FALSE
# 35 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
# 36 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 37 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, Common_Movement_WalkInPlaceFasterDown
# 38 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 39 "data/maps/MtPyre_Summit/scripts.pory"
	delay 50
# 40 "data/maps/MtPyre_Summit/scripts.pory"
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_ArchieFacePlayer0
# 41 "data/maps/MtPyre_Summit/scripts.pory"
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_ArchieFacePlayer1
# 42 "data/maps/MtPyre_Summit/scripts.pory"
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_ArchieFacePlayer2
# 43 "data/maps/MtPyre_Summit/scripts.pory"
	msgbox MtPyre_Summit_Text_ArchieWeGotTheOrbLetsGo, MSGBOX_DEFAULT
# 44 "data/maps/MtPyre_Summit/scripts.pory"
	closemessage
# 45 "data/maps/MtPyre_Summit/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 46 "data/maps/MtPyre_Summit/scripts.pory"
	removeobject LOCALID_MT_PYRE_SUMMIT_ARCHIE
# 47 "data/maps/MtPyre_Summit/scripts.pory"
	removeobject LOCALID_MT_PYRE_SUMMIT_GRUNT_1
# 48 "data/maps/MtPyre_Summit/scripts.pory"
	removeobject LOCALID_MT_PYRE_SUMMIT_GRUNT_2
# 49 "data/maps/MtPyre_Summit/scripts.pory"
	removeobject LOCALID_MT_PYRE_SUMMIT_GRUNT_3
# 50 "data/maps/MtPyre_Summit/scripts.pory"
	removeobject LOCALID_MT_PYRE_SUMMIT_GRUNT_4
# 51 "data/maps/MtPyre_Summit/scripts.pory"
	setflag FLAG_HIDE_MT_PYRE_SUMMIT_ARCHIE
# 52 "data/maps/MtPyre_Summit/scripts.pory"
	setflag FLAG_HIDE_MT_PYRE_SUMMIT_TEAM_AQUA
# 53 "data/maps/MtPyre_Summit/scripts.pory"
	fadedefaultbgm
# 54 "data/maps/MtPyre_Summit/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 55 "data/maps/MtPyre_Summit/scripts.pory"
	delay 20
# 56 "data/maps/MtPyre_Summit/scripts.pory"
	setvar VAR_MT_PYRE_STATE, 1
# 57 "data/maps/MtPyre_Summit/scripts.pory"
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_OldLadyApproachPlayer0
# 58 "data/maps/MtPyre_Summit/scripts.pory"
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_OldLadyApproachPlayer1
# 59 "data/maps/MtPyre_Summit/scripts.pory"
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_OldLadyApproachPlayer2
# 60 "data/maps/MtPyre_Summit/scripts.pory"
	msgbox MtPyre_Summit_Text_BothOrbsTakenMagmaLeftThis, MSGBOX_DEFAULT
# 61 "data/maps/MtPyre_Summit/scripts.pory"
	giveitem ITEM_MAGMA_EMBLEM
# 62 "data/maps/MtPyre_Summit/scripts.pory"
	setflag FLAG_RECEIVED_RED_OR_BLUE_ORB
# 63 "data/maps/MtPyre_Summit/scripts.pory"
	setflag FLAG_HIDE_JAGGED_PASS_MAGMA_GUARD
# 64 "data/maps/MtPyre_Summit/scripts.pory"
	releaseall
# 65 "data/maps/MtPyre_Summit/scripts.pory"
	end
# 66 "data/maps/MtPyre_Summit/scripts.pory"

# 67 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_ArchieFacePlayer0::
# 68 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieFacePlayer0
# 69 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 70 "data/maps/MtPyre_Summit/scripts.pory"
	return
# 71 "data/maps/MtPyre_Summit/scripts.pory"

# 72 "data/maps/MtPyre_Summit/scripts.pory"
@ Archie is already facing player
# 73 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_ArchieFacePlayer1::
# 74 "data/maps/MtPyre_Summit/scripts.pory"
	return
# 75 "data/maps/MtPyre_Summit/scripts.pory"

# 76 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_ArchieFacePlayer2::
# 77 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieFacePlayer2
# 78 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 79 "data/maps/MtPyre_Summit/scripts.pory"
	return
# 80 "data/maps/MtPyre_Summit/scripts.pory"

# 81 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_OldLadyApproachPlayer0::
# 82 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_MT_PYRE_SUMMIT_OLD_LADY, MtPyre_Summit_Movement_OldLadyApproachPlayer0
# 83 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 84 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 85 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 86 "data/maps/MtPyre_Summit/scripts.pory"
	return
# 87 "data/maps/MtPyre_Summit/scripts.pory"

# 88 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_OldLadyApproachPlayer1::
# 89 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_MT_PYRE_SUMMIT_OLD_LADY, MtPyre_Summit_Movement_OldLadyApproachPlayer1
# 90 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 91 "data/maps/MtPyre_Summit/scripts.pory"
	return
# 92 "data/maps/MtPyre_Summit/scripts.pory"

# 93 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_OldLadyApproachPlayer2::
# 94 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_MT_PYRE_SUMMIT_OLD_LADY, MtPyre_Summit_Movement_OldLadyApproachPlayer2
# 95 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 96 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 97 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 98 "data/maps/MtPyre_Summit/scripts.pory"
	return
# 99 "data/maps/MtPyre_Summit/scripts.pory"

# 100 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_OldLadyApproachPlayer0:
# 101 "data/maps/MtPyre_Summit/scripts.pory"
	walk_down
# 102 "data/maps/MtPyre_Summit/scripts.pory"
	walk_down
# 103 "data/maps/MtPyre_Summit/scripts.pory"
	walk_in_place_faster_left
# 104 "data/maps/MtPyre_Summit/scripts.pory"
	step_end
# 105 "data/maps/MtPyre_Summit/scripts.pory"

# 106 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_OldLadyApproachPlayer1:
# 107 "data/maps/MtPyre_Summit/scripts.pory"
	walk_down
# 108 "data/maps/MtPyre_Summit/scripts.pory"
	step_end
# 109 "data/maps/MtPyre_Summit/scripts.pory"

# 110 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_OldLadyApproachPlayer2:
# 111 "data/maps/MtPyre_Summit/scripts.pory"
	walk_down
# 112 "data/maps/MtPyre_Summit/scripts.pory"
	walk_down
# 113 "data/maps/MtPyre_Summit/scripts.pory"
	walk_in_place_faster_right
# 114 "data/maps/MtPyre_Summit/scripts.pory"
	step_end
# 115 "data/maps/MtPyre_Summit/scripts.pory"

# 116 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_ArchieFacePlayer0:
# 117 "data/maps/MtPyre_Summit/scripts.pory"
	walk_left
# 118 "data/maps/MtPyre_Summit/scripts.pory"
	walk_in_place_faster_down
# 119 "data/maps/MtPyre_Summit/scripts.pory"
	step_end
# 120 "data/maps/MtPyre_Summit/scripts.pory"

# 121 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_ArchieFacePlayer2:
# 122 "data/maps/MtPyre_Summit/scripts.pory"
	walk_right
# 123 "data/maps/MtPyre_Summit/scripts.pory"
	walk_in_place_faster_down
# 124 "data/maps/MtPyre_Summit/scripts.pory"
	step_end
# 125 "data/maps/MtPyre_Summit/scripts.pory"

# 126 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_OldMan::
# 127 "data/maps/MtPyre_Summit/scripts.pory"
	lock
# 128 "data/maps/MtPyre_Summit/scripts.pory"
	faceplayer
# 129 "data/maps/MtPyre_Summit/scripts.pory"
	goto_if_set FLAG_SOOTOPOLIS_ARCHIE_MAXIE_LEAVE, MtPyre_Summit_EventScript_OldManAfterRayquaza
# 130 "data/maps/MtPyre_Summit/scripts.pory"
	msgbox MtPyre_Summit_Text_WillYouHearOutMyTale, MSGBOX_YESNO
# 131 "data/maps/MtPyre_Summit/scripts.pory"
	call_if_eq VAR_RESULT, YES, MtPyre_Summit_EventScript_OldManTale
# 132 "data/maps/MtPyre_Summit/scripts.pory"
	call_if_eq VAR_RESULT, NO, MtPyre_Summit_EventScript_DeclineOldManTale
# 133 "data/maps/MtPyre_Summit/scripts.pory"
	release
# 134 "data/maps/MtPyre_Summit/scripts.pory"
	end
# 135 "data/maps/MtPyre_Summit/scripts.pory"

# 136 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_OldManAfterRayquaza::
# 137 "data/maps/MtPyre_Summit/scripts.pory"
	msgbox MtPyre_Summit_Text_HearTheNewLegendOfHoenn, MSGBOX_YESNO
# 138 "data/maps/MtPyre_Summit/scripts.pory"
	call_if_eq VAR_RESULT, YES, MtPyre_Summit_EventScript_OldManNewTale
# 139 "data/maps/MtPyre_Summit/scripts.pory"
	call_if_eq VAR_RESULT, NO, MtPyre_Summit_EventScript_DeclineOldManTale
# 140 "data/maps/MtPyre_Summit/scripts.pory"
	release
# 141 "data/maps/MtPyre_Summit/scripts.pory"
	end
# 142 "data/maps/MtPyre_Summit/scripts.pory"

# 143 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_OldManTale::
# 144 "data/maps/MtPyre_Summit/scripts.pory"
	msgbox MtPyre_Summit_Text_GroudonKyogreTale, MSGBOX_DEFAULT
# 145 "data/maps/MtPyre_Summit/scripts.pory"
	return
# 146 "data/maps/MtPyre_Summit/scripts.pory"

# 147 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_DeclineOldManTale::
# 148 "data/maps/MtPyre_Summit/scripts.pory"
	msgbox MtPyre_Summit_Text_WellThatTooIsFine, MSGBOX_DEFAULT
# 149 "data/maps/MtPyre_Summit/scripts.pory"
	return
# 150 "data/maps/MtPyre_Summit/scripts.pory"

# 151 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_OldManNewTale::
# 152 "data/maps/MtPyre_Summit/scripts.pory"
	msgbox MtPyre_Summit_Text_HoennTrioTale, MSGBOX_DEFAULT
# 153 "data/maps/MtPyre_Summit/scripts.pory"
	return
# 154 "data/maps/MtPyre_Summit/scripts.pory"

# 155 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_OldLady::
# 156 "data/maps/MtPyre_Summit/scripts.pory"
	lock
# 157 "data/maps/MtPyre_Summit/scripts.pory"
	faceplayer
# 158 "data/maps/MtPyre_Summit/scripts.pory"
	goto_if_set FLAG_RETURNED_RED_OR_BLUE_ORB, MtPyre_Summit_EventScript_OldLadyAfterOrbsReturned
# 159 "data/maps/MtPyre_Summit/scripts.pory"
	call_if_ge VAR_MT_PYRE_STATE, 3, MtPyre_Summit_EventScript_OldLadyOrbsReturned
# 160 "data/maps/MtPyre_Summit/scripts.pory"
	goto_if_set FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN, MtPyre_Summit_EventScript_OldLadyLegendariesAwake
# 161 "data/maps/MtPyre_Summit/scripts.pory"
	msgbox MtPyre_Summit_Text_OrbsHaveBeenTaken, MSGBOX_DEFAULT
# 162 "data/maps/MtPyre_Summit/scripts.pory"
	release
# 163 "data/maps/MtPyre_Summit/scripts.pory"
	end
# 164 "data/maps/MtPyre_Summit/scripts.pory"

# 165 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_OldLadyOrbsReturned::
# 166 "data/maps/MtPyre_Summit/scripts.pory"
	msgbox MtPyre_Summit_Text_ThoseTwoMenReturnedOrbs, MSGBOX_DEFAULT
# 167 "data/maps/MtPyre_Summit/scripts.pory"
	setflag FLAG_RETURNED_RED_OR_BLUE_ORB
# 168 "data/maps/MtPyre_Summit/scripts.pory"
	release
# 169 "data/maps/MtPyre_Summit/scripts.pory"
	end
# 170 "data/maps/MtPyre_Summit/scripts.pory"

# 171 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_OldLadyLegendariesAwake::
# 172 "data/maps/MtPyre_Summit/scripts.pory"
	msgbox MtPyre_Summit_Text_GroudonKyogreAwakened, MSGBOX_DEFAULT
# 173 "data/maps/MtPyre_Summit/scripts.pory"
	release
# 174 "data/maps/MtPyre_Summit/scripts.pory"
	end
# 175 "data/maps/MtPyre_Summit/scripts.pory"

# 176 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_OldLadyAfterOrbsReturned::
# 177 "data/maps/MtPyre_Summit/scripts.pory"
	msgbox MtPyre_Summit_Text_SuperAncientPokemonTaughtUs, MSGBOX_DEFAULT
# 178 "data/maps/MtPyre_Summit/scripts.pory"
	release
# 179 "data/maps/MtPyre_Summit/scripts.pory"
	end
# 180 "data/maps/MtPyre_Summit/scripts.pory"

# 181 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_ArchieMaxieTrigger0::
# 182 "data/maps/MtPyre_Summit/scripts.pory"
	lockall
# 183 "data/maps/MtPyre_Summit/scripts.pory"
	setvar VAR_0x8008, 0
# 184 "data/maps/MtPyre_Summit/scripts.pory"
	goto MtPyre_Summit_EventScript_ArchieMaxieReturnOrbs
# 185 "data/maps/MtPyre_Summit/scripts.pory"
	end
# 186 "data/maps/MtPyre_Summit/scripts.pory"

# 187 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_ArchieMaxieTrigger1::
# 188 "data/maps/MtPyre_Summit/scripts.pory"
	lockall
# 189 "data/maps/MtPyre_Summit/scripts.pory"
	setvar VAR_0x8008, 1
# 190 "data/maps/MtPyre_Summit/scripts.pory"
	goto MtPyre_Summit_EventScript_ArchieMaxieReturnOrbs
# 191 "data/maps/MtPyre_Summit/scripts.pory"
	end
# 192 "data/maps/MtPyre_Summit/scripts.pory"

# 193 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_ArchieMaxieTrigger2::
# 194 "data/maps/MtPyre_Summit/scripts.pory"
	lockall
# 195 "data/maps/MtPyre_Summit/scripts.pory"
	setvar VAR_0x8008, 2
# 196 "data/maps/MtPyre_Summit/scripts.pory"
	goto MtPyre_Summit_EventScript_ArchieMaxieReturnOrbs
# 197 "data/maps/MtPyre_Summit/scripts.pory"
	end
# 198 "data/maps/MtPyre_Summit/scripts.pory"

# 199 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_ArchieMaxieReturnOrbs::
# 200 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 201 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 202 "data/maps/MtPyre_Summit/scripts.pory"
	delay 60
# 203 "data/maps/MtPyre_Summit/scripts.pory"
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_ArchieMaxieBeginExit0
# 204 "data/maps/MtPyre_Summit/scripts.pory"
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_ArchieMaxieBeginExit1
# 205 "data/maps/MtPyre_Summit/scripts.pory"
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_ArchieMaxieBeginExit2
# 206 "data/maps/MtPyre_Summit/scripts.pory"
	playse SE_PIN
# 207 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, Common_Movement_ExclamationMark
# 208 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 209 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, Common_Movement_Delay48
# 210 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 211 "data/maps/MtPyre_Summit/scripts.pory"
	delay 30
# 212 "data/maps/MtPyre_Summit/scripts.pory"
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_MaxieApproachPlayer0
# 213 "data/maps/MtPyre_Summit/scripts.pory"
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_MaxieApproachPlayer1
# 214 "data/maps/MtPyre_Summit/scripts.pory"
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_MaxieApproachPlayer2
# 215 "data/maps/MtPyre_Summit/scripts.pory"
	msgbox MtPyre_Summit_Text_MaxieSilence, MSGBOX_DEFAULT
# 216 "data/maps/MtPyre_Summit/scripts.pory"
	closemessage
# 217 "data/maps/MtPyre_Summit/scripts.pory"
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_MaxieApproachArchie0
# 218 "data/maps/MtPyre_Summit/scripts.pory"
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_MaxieApproachArchie1
# 219 "data/maps/MtPyre_Summit/scripts.pory"
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_MaxieApproachArchie2
# 220 "data/maps/MtPyre_Summit/scripts.pory"
	delay 30
# 221 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieExit
# 222 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieExit
# 223 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 224 "data/maps/MtPyre_Summit/scripts.pory"
	removeobject LOCALID_MT_PYRE_SUMMIT_ARCHIE
# 225 "data/maps/MtPyre_Summit/scripts.pory"
	removeobject LOCALID_MT_PYRE_SUMMIT_MAXIE
# 226 "data/maps/MtPyre_Summit/scripts.pory"
	setvar VAR_MT_PYRE_STATE, 3
# 227 "data/maps/MtPyre_Summit/scripts.pory"
	releaseall
# 228 "data/maps/MtPyre_Summit/scripts.pory"
	end
# 229 "data/maps/MtPyre_Summit/scripts.pory"

# 230 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_ArchieMaxieBeginExit0::
# 231 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit0
# 232 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieExit
# 233 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieExit
# 234 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 235 "data/maps/MtPyre_Summit/scripts.pory"
	return
# 236 "data/maps/MtPyre_Summit/scripts.pory"

# 237 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_ArchieMaxieBeginExit1::
# 238 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit1
# 239 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieExit
# 240 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieExit
# 241 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 242 "data/maps/MtPyre_Summit/scripts.pory"
	return
# 243 "data/maps/MtPyre_Summit/scripts.pory"

# 244 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_ArchieMaxieBeginExit2::
# 245 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit2
# 246 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieExit
# 247 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieExit
# 248 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 249 "data/maps/MtPyre_Summit/scripts.pory"
	return
# 250 "data/maps/MtPyre_Summit/scripts.pory"

# 251 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_MaxieApproachPlayer0::
# 252 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerFaceMaxie0
# 253 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieWatchMaxie
# 254 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieApproachPlayer0
# 255 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 256 "data/maps/MtPyre_Summit/scripts.pory"
	return
# 257 "data/maps/MtPyre_Summit/scripts.pory"

# 258 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_MaxieApproachPlayer1::
# 259 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerFaceMaxie
# 260 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieWatchMaxie
# 261 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieApproachPlayer1
# 262 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 263 "data/maps/MtPyre_Summit/scripts.pory"
	return
# 264 "data/maps/MtPyre_Summit/scripts.pory"

# 265 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_MaxieApproachPlayer2::
# 266 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerFaceMaxie
# 267 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieWatchMaxie
# 268 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieApproachPlayer2
# 269 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 270 "data/maps/MtPyre_Summit/scripts.pory"
	return
# 271 "data/maps/MtPyre_Summit/scripts.pory"

# 272 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_MaxieApproachArchie0::
# 273 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerWatchMaxie
# 274 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieApproachArchie0
# 275 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 276 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, Common_Movement_WalkInPlaceFasterRight
# 277 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 278 "data/maps/MtPyre_Summit/scripts.pory"
	return
# 279 "data/maps/MtPyre_Summit/scripts.pory"

# 280 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_MaxieApproachArchie1::
# 281 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerWatchMaxie
# 282 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieApproachArchie1
# 283 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 284 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, Common_Movement_WalkInPlaceFasterRight
# 285 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 286 "data/maps/MtPyre_Summit/scripts.pory"
	return
# 287 "data/maps/MtPyre_Summit/scripts.pory"

# 288 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_MaxieApproachArchie2::
# 289 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerWatchMaxie
# 290 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieApproachArchie2
# 291 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 292 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, Common_Movement_WalkInPlaceFasterRight
# 293 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 294 "data/maps/MtPyre_Summit/scripts.pory"
	return
# 295 "data/maps/MtPyre_Summit/scripts.pory"

# 296 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_PlayerFaceMaxie0:
# 297 "data/maps/MtPyre_Summit/scripts.pory"
	delay_16
# 298 "data/maps/MtPyre_Summit/scripts.pory"
	delay_16
# 299 "data/maps/MtPyre_Summit/scripts.pory"
	walk_in_place_faster_right
# 300 "data/maps/MtPyre_Summit/scripts.pory"
	step_end
# 301 "data/maps/MtPyre_Summit/scripts.pory"

# 302 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_PlayerFaceMaxie:
# 303 "data/maps/MtPyre_Summit/scripts.pory"
	delay_16
# 304 "data/maps/MtPyre_Summit/scripts.pory"
	delay_16
# 305 "data/maps/MtPyre_Summit/scripts.pory"
	walk_in_place_faster_left
# 306 "data/maps/MtPyre_Summit/scripts.pory"
	step_end
# 307 "data/maps/MtPyre_Summit/scripts.pory"

# 308 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_ArchieExit:
# 309 "data/maps/MtPyre_Summit/scripts.pory"
	walk_down
# 310 "data/maps/MtPyre_Summit/scripts.pory"
	walk_down
# 311 "data/maps/MtPyre_Summit/scripts.pory"
	walk_down
# 312 "data/maps/MtPyre_Summit/scripts.pory"
	walk_down
# 313 "data/maps/MtPyre_Summit/scripts.pory"
	walk_down
# 314 "data/maps/MtPyre_Summit/scripts.pory"
	walk_down
# 315 "data/maps/MtPyre_Summit/scripts.pory"
	step_end
# 316 "data/maps/MtPyre_Summit/scripts.pory"

# 317 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_MaxieExit:
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
	walk_down
# 324 "data/maps/MtPyre_Summit/scripts.pory"
	step_end
# 325 "data/maps/MtPyre_Summit/scripts.pory"

# 326 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit0:
# 327 "data/maps/MtPyre_Summit/scripts.pory"
	delay_16
# 328 "data/maps/MtPyre_Summit/scripts.pory"
	delay_8
# 329 "data/maps/MtPyre_Summit/scripts.pory"
	walk_left
# 330 "data/maps/MtPyre_Summit/scripts.pory"
	walk_in_place_faster_right
# 331 "data/maps/MtPyre_Summit/scripts.pory"
	delay_16
# 332 "data/maps/MtPyre_Summit/scripts.pory"
	walk_in_place_faster_down
# 333 "data/maps/MtPyre_Summit/scripts.pory"
	step_end
# 334 "data/maps/MtPyre_Summit/scripts.pory"

# 335 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit1:
# 336 "data/maps/MtPyre_Summit/scripts.pory"
	delay_16
# 337 "data/maps/MtPyre_Summit/scripts.pory"
	delay_8
# 338 "data/maps/MtPyre_Summit/scripts.pory"
	walk_right
# 339 "data/maps/MtPyre_Summit/scripts.pory"
	walk_in_place_faster_left
# 340 "data/maps/MtPyre_Summit/scripts.pory"
	delay_16
# 341 "data/maps/MtPyre_Summit/scripts.pory"
	walk_in_place_faster_down
# 342 "data/maps/MtPyre_Summit/scripts.pory"
	step_end
# 343 "data/maps/MtPyre_Summit/scripts.pory"

# 344 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit2:
# 345 "data/maps/MtPyre_Summit/scripts.pory"
	delay_16
# 346 "data/maps/MtPyre_Summit/scripts.pory"
	delay_8
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
MtPyre_Summit_Movement_MaxieApproachPlayer0:
# 353 "data/maps/MtPyre_Summit/scripts.pory"
	walk_up
# 354 "data/maps/MtPyre_Summit/scripts.pory"
	walk_up
# 355 "data/maps/MtPyre_Summit/scripts.pory"
	walk_up
# 356 "data/maps/MtPyre_Summit/scripts.pory"
	walk_left
# 357 "data/maps/MtPyre_Summit/scripts.pory"
	step_end
# 358 "data/maps/MtPyre_Summit/scripts.pory"

# 359 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_MaxieApproachPlayer1:
# 360 "data/maps/MtPyre_Summit/scripts.pory"
	walk_up
# 361 "data/maps/MtPyre_Summit/scripts.pory"
	walk_up
# 362 "data/maps/MtPyre_Summit/scripts.pory"
	walk_up
# 363 "data/maps/MtPyre_Summit/scripts.pory"
	walk_in_place_faster_right
# 364 "data/maps/MtPyre_Summit/scripts.pory"
	step_end
# 365 "data/maps/MtPyre_Summit/scripts.pory"

# 366 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_MaxieApproachPlayer2:
# 367 "data/maps/MtPyre_Summit/scripts.pory"
	walk_up
# 368 "data/maps/MtPyre_Summit/scripts.pory"
	walk_up
# 369 "data/maps/MtPyre_Summit/scripts.pory"
	walk_up
# 370 "data/maps/MtPyre_Summit/scripts.pory"
	walk_in_place_faster_right
# 371 "data/maps/MtPyre_Summit/scripts.pory"
	step_end
# 372 "data/maps/MtPyre_Summit/scripts.pory"

# 373 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_ArchieWatchMaxie:
# 374 "data/maps/MtPyre_Summit/scripts.pory"
	delay_16
# 375 "data/maps/MtPyre_Summit/scripts.pory"
	walk_in_place_faster_up
# 376 "data/maps/MtPyre_Summit/scripts.pory"
	step_end
# 377 "data/maps/MtPyre_Summit/scripts.pory"

# 378 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_PlayerWatchMaxie:
# 379 "data/maps/MtPyre_Summit/scripts.pory"
	delay_16
# 380 "data/maps/MtPyre_Summit/scripts.pory"
	walk_in_place_faster_down
# 381 "data/maps/MtPyre_Summit/scripts.pory"
	step_end
# 382 "data/maps/MtPyre_Summit/scripts.pory"

# 383 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_MaxieApproachArchie0:
# 384 "data/maps/MtPyre_Summit/scripts.pory"
	walk_down
# 385 "data/maps/MtPyre_Summit/scripts.pory"
	walk_right
# 386 "data/maps/MtPyre_Summit/scripts.pory"
	walk_down
# 387 "data/maps/MtPyre_Summit/scripts.pory"
	walk_down
# 388 "data/maps/MtPyre_Summit/scripts.pory"
	walk_in_place_faster_left
# 389 "data/maps/MtPyre_Summit/scripts.pory"
	step_end
# 390 "data/maps/MtPyre_Summit/scripts.pory"

# 391 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_MaxieApproachArchie1:
# 392 "data/maps/MtPyre_Summit/scripts.pory"
	walk_down
# 393 "data/maps/MtPyre_Summit/scripts.pory"
	walk_down
# 394 "data/maps/MtPyre_Summit/scripts.pory"
	walk_down
# 395 "data/maps/MtPyre_Summit/scripts.pory"
	walk_in_place_faster_left
# 396 "data/maps/MtPyre_Summit/scripts.pory"
	step_end
# 397 "data/maps/MtPyre_Summit/scripts.pory"

# 398 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_MaxieApproachArchie2:
# 399 "data/maps/MtPyre_Summit/scripts.pory"
	walk_down
# 400 "data/maps/MtPyre_Summit/scripts.pory"
	walk_down
# 401 "data/maps/MtPyre_Summit/scripts.pory"
	walk_down
# 402 "data/maps/MtPyre_Summit/scripts.pory"
	walk_in_place_faster_left
# 403 "data/maps/MtPyre_Summit/scripts.pory"
	step_end
# 404 "data/maps/MtPyre_Summit/scripts.pory"

# 405 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_Grunt1::
# 406 "data/maps/MtPyre_Summit/scripts.pory"
	trainerbattle_single TRAINER_GRUNT_MT_PYRE_1, MtPyre_Summit_Text_Grunt1Intro, MtPyre_Summit_Text_Grunt1Defeat
# 407 "data/maps/MtPyre_Summit/scripts.pory"
	msgbox MtPyre_Summit_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
# 408 "data/maps/MtPyre_Summit/scripts.pory"
	end
# 409 "data/maps/MtPyre_Summit/scripts.pory"

# 410 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_Grunt2::
# 411 "data/maps/MtPyre_Summit/scripts.pory"
	trainerbattle_single TRAINER_GRUNT_MT_PYRE_2, MtPyre_Summit_Text_Grunt2Intro, MtPyre_Summit_Text_Grunt2Defeat
# 412 "data/maps/MtPyre_Summit/scripts.pory"
	msgbox MtPyre_Summit_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
# 413 "data/maps/MtPyre_Summit/scripts.pory"
	end
# 414 "data/maps/MtPyre_Summit/scripts.pory"

# 415 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_Grunt3::
# 416 "data/maps/MtPyre_Summit/scripts.pory"
	trainerbattle_single TRAINER_GRUNT_MT_PYRE_3, MtPyre_Summit_Text_Grunt3Intro, MtPyre_Summit_Text_Grunt3Defeat
# 417 "data/maps/MtPyre_Summit/scripts.pory"
	msgbox MtPyre_Summit_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
# 418 "data/maps/MtPyre_Summit/scripts.pory"
	end
# 419 "data/maps/MtPyre_Summit/scripts.pory"

# 420 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_Grunt4::
# 421 "data/maps/MtPyre_Summit/scripts.pory"
	trainerbattle_single TRAINER_GRUNT_MT_PYRE_4, MtPyre_Summit_Text_Grunt4Intro, MtPyre_Summit_Text_Grunt4Defeat
# 422 "data/maps/MtPyre_Summit/scripts.pory"
	msgbox MtPyre_Summit_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
# 423 "data/maps/MtPyre_Summit/scripts.pory"
	end
# 424 "data/maps/MtPyre_Summit/scripts.pory"

# 425 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_Grunt1Intro:
# 426 "data/maps/MtPyre_Summit/scripts.pory"
	.string "No! Those TEAM MAGMA goons got\n"
# 427 "data/maps/MtPyre_Summit/scripts.pory"
	.string "here ahead of us!\p"
# 428 "data/maps/MtPyre_Summit/scripts.pory"
	.string "We can't fall behind!$"
# 429 "data/maps/MtPyre_Summit/scripts.pory"

# 430 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_Grunt1Defeat:
# 431 "data/maps/MtPyre_Summit/scripts.pory"
	.string "I thought you were one of the MAGMAS\n"
# 432 "data/maps/MtPyre_Summit/scripts.pory"
	.string "who happened to come back…$"
# 433 "data/maps/MtPyre_Summit/scripts.pory"

# 434 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_Grunt1PostBattle:
# 435 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Yeah, so you are strong…\n"
# 436 "data/maps/MtPyre_Summit/scripts.pory"
	.string "But there're a lot of us!$"
# 437 "data/maps/MtPyre_Summit/scripts.pory"

# 438 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_Grunt2Intro:
# 439 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Hah!\n"
# 440 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Too bad for you!\p"
# 441 "data/maps/MtPyre_Summit/scripts.pory"
	.string "If you came earlier, you only would've\n"
# 442 "data/maps/MtPyre_Summit/scripts.pory"
	.string "had to battle the wimpy TEAM MAGMA.\p"
# 443 "data/maps/MtPyre_Summit/scripts.pory"
	.string "But since you arrived now, you have\n"
# 444 "data/maps/MtPyre_Summit/scripts.pory"
	.string "to take on us toughies!$"
# 445 "data/maps/MtPyre_Summit/scripts.pory"

# 446 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_Grunt2Defeat:
# 447 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Urgh… I should've let you take on\n"
# 448 "data/maps/MtPyre_Summit/scripts.pory"
	.string "TEAM MAGMA first…$"
# 449 "data/maps/MtPyre_Summit/scripts.pory"

# 450 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_Grunt2PostBattle:
# 451 "data/maps/MtPyre_Summit/scripts.pory"
	.string "You don't know anything!\n"
# 452 "data/maps/MtPyre_Summit/scripts.pory"
	.string "So why are you messing with us?$"
# 453 "data/maps/MtPyre_Summit/scripts.pory"

# 454 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_Grunt3Intro:
# 455 "data/maps/MtPyre_Summit/scripts.pory"
	.string "You…\n"
# 456 "data/maps/MtPyre_Summit/scripts.pory"
	.string "We saw you at MT. CHIMNEY.\p"
# 457 "data/maps/MtPyre_Summit/scripts.pory"
	.string "You don't belong to either TEAM,\n"
# 458 "data/maps/MtPyre_Summit/scripts.pory"
	.string "so why would you be here?$"
# 459 "data/maps/MtPyre_Summit/scripts.pory"

# 460 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_Grunt3Defeat:
# 461 "data/maps/MtPyre_Summit/scripts.pory"
	.string "If you're going to mess with anyone,\n"
# 462 "data/maps/MtPyre_Summit/scripts.pory"
	.string "let it be TEAM MAGMA…$"
# 463 "data/maps/MtPyre_Summit/scripts.pory"

# 464 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_Grunt3PostBattle:
# 465 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Heh, it doesn't matter!\n"
# 466 "data/maps/MtPyre_Summit/scripts.pory"
	.string "We bought ourselves some time!\p"
# 467 "data/maps/MtPyre_Summit/scripts.pory"
	.string "The BOSS should have snatched what\n"
# 468 "data/maps/MtPyre_Summit/scripts.pory"
	.string "he was after!$"
# 469 "data/maps/MtPyre_Summit/scripts.pory"

# 470 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_Grunt4Intro:
# 471 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Oh, I know!\n"
# 472 "data/maps/MtPyre_Summit/scripts.pory"
	.string "You tried to join TEAM MAGMA,\l"
# 473 "data/maps/MtPyre_Summit/scripts.pory"
	.string "but they wouldn't have you!\p"
# 474 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Well, don't think that we'll let you\n"
# 475 "data/maps/MtPyre_Summit/scripts.pory"
	.string "join our TEAM AQUA!$"
# 476 "data/maps/MtPyre_Summit/scripts.pory"

# 477 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_Grunt4Defeat:
# 478 "data/maps/MtPyre_Summit/scripts.pory"
	.string "If you want to join TEAM AQUA that\n"
# 479 "data/maps/MtPyre_Summit/scripts.pory"
	.string "badly, we can consider it…$"
# 480 "data/maps/MtPyre_Summit/scripts.pory"

# 481 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_Grunt4PostBattle:
# 482 "data/maps/MtPyre_Summit/scripts.pory"
	.string "We have a great combination going\n"
# 483 "data/maps/MtPyre_Summit/scripts.pory"
	.string "with us members and our leader.$"
# 484 "data/maps/MtPyre_Summit/scripts.pory"

# 485 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_ArchieWeGotTheOrbLetsGo:
# 486 "data/maps/MtPyre_Summit/scripts.pory"
	.string "ARCHIE: TEAM MAGMA's MAXIE got ahead\n"
# 487 "data/maps/MtPyre_Summit/scripts.pory"
	.string "of us, but we also got what we wanted.\p"
# 488 "data/maps/MtPyre_Summit/scripts.pory"
	.string "The RED ORB preserved at MT. PYRE…\n"
# 489 "data/maps/MtPyre_Summit/scripts.pory"
	.string "I, ARCHIE, now have it in my possession!\p"
# 490 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Fufufu… Now we can bring our ultimate\n"
# 491 "data/maps/MtPyre_Summit/scripts.pory"
	.string "objective to fruition!\p"
# 492 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Okay, TEAM!\n"
# 493 "data/maps/MtPyre_Summit/scripts.pory"
	.string "We're pulling out!$"
# 494 "data/maps/MtPyre_Summit/scripts.pory"

# 495 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_BothOrbsTakenMagmaLeftThis:
# 496 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Oh, no…\n"
# 497 "data/maps/MtPyre_Summit/scripts.pory"
	.string "This cannot happen…\p"
# 498 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Not only the BLUE ORB, but even\n"
# 499 "data/maps/MtPyre_Summit/scripts.pory"
	.string "the RED ORB has been taken…\p"
# 500 "data/maps/MtPyre_Summit/scripts.pory"
	.string "The BLUE ORB and RED ORB must never\n"
# 501 "data/maps/MtPyre_Summit/scripts.pory"
	.string "be separated. They belong together.\p"
# 502 "data/maps/MtPyre_Summit/scripts.pory"
	.string "What are those men trying to do with\n"
# 503 "data/maps/MtPyre_Summit/scripts.pory"
	.string "the two ORBS?\p"
# 504 "data/maps/MtPyre_Summit/scripts.pory"
	.string "… … … … … …\n"
# 505 "data/maps/MtPyre_Summit/scripts.pory"
	.string "… … … … … …\p"
# 506 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Oh, yes. Was it TEAM MAGMA who came\n"
# 507 "data/maps/MtPyre_Summit/scripts.pory"
	.string "and took the BLUE ORB first?\p"
# 508 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Well, in their haste, they left this\n"
# 509 "data/maps/MtPyre_Summit/scripts.pory"
	.string "behind.\p"
# 510 "data/maps/MtPyre_Summit/scripts.pory"
	.string "I couldn't imagine what exactly it\n"
# 511 "data/maps/MtPyre_Summit/scripts.pory"
	.string "could be.\p"
# 512 "data/maps/MtPyre_Summit/scripts.pory"
	.string "I would like you to have it.\n"
# 513 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Perhaps it will be useful in some way.$"
# 514 "data/maps/MtPyre_Summit/scripts.pory"

# 515 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_OrbsHaveBeenTaken:
# 516 "data/maps/MtPyre_Summit/scripts.pory"
	.string "The BLUE ORB and RED ORB taken by\n"
# 517 "data/maps/MtPyre_Summit/scripts.pory"
	.string "those sinister men…\p"
# 518 "data/maps/MtPyre_Summit/scripts.pory"
	.string "They must never be apart…\n"
# 519 "data/maps/MtPyre_Summit/scripts.pory"
	.string "I fear something terrible will happen…$"
# 520 "data/maps/MtPyre_Summit/scripts.pory"

# 521 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_GroudonKyogreAwakened:
# 522 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Oh, my goodness…\p"
# 523 "data/maps/MtPyre_Summit/scripts.pory"
	.string "You say that both GROUDON and KYOGRE\n"
# 524 "data/maps/MtPyre_Summit/scripts.pory"
	.string "have been awakened?\p"
# 525 "data/maps/MtPyre_Summit/scripts.pory"
	.string "It is said that the BLUE ORB and\n"
# 526 "data/maps/MtPyre_Summit/scripts.pory"
	.string "the RED ORB quelled the rage of\l"
# 527 "data/maps/MtPyre_Summit/scripts.pory"
	.string "the two POKéMON…\p"
# 528 "data/maps/MtPyre_Summit/scripts.pory"
	.string "It is also said that the true owner\n"
# 529 "data/maps/MtPyre_Summit/scripts.pory"
	.string "of the ORBS still exists.\p"
# 530 "data/maps/MtPyre_Summit/scripts.pory"
	.string "However, no one knows who, or what\n"
# 531 "data/maps/MtPyre_Summit/scripts.pory"
	.string "exactly, the ORBS belong to.\p"
# 532 "data/maps/MtPyre_Summit/scripts.pory"
	.string "It could be a human, or perhaps\n"
# 533 "data/maps/MtPyre_Summit/scripts.pory"
	.string "a POKéMON, but no one knows.$"
# 534 "data/maps/MtPyre_Summit/scripts.pory"

# 535 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_ThoseTwoMenReturnedOrbs:
# 536 "data/maps/MtPyre_Summit/scripts.pory"
	.string "The two men who took the ORBS came\n"
# 537 "data/maps/MtPyre_Summit/scripts.pory"
	.string "back to return them on their own.\p"
# 538 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Those men…\n"
# 539 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Perhaps they are not so evil after all…$"
# 540 "data/maps/MtPyre_Summit/scripts.pory"

# 541 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_SuperAncientPokemonTaughtUs:
# 542 "data/maps/MtPyre_Summit/scripts.pory"
	.string "The embodiments of the land, sea,\n"
# 543 "data/maps/MtPyre_Summit/scripts.pory"
	.string "and the sky…\p"
# 544 "data/maps/MtPyre_Summit/scripts.pory"
	.string "That is said to be the identities of\n"
# 545 "data/maps/MtPyre_Summit/scripts.pory"
	.string "the super-ancient POKéMON…\p"
# 546 "data/maps/MtPyre_Summit/scripts.pory"
	.string "In the same way that we humans and\n"
# 547 "data/maps/MtPyre_Summit/scripts.pory"
	.string "POKéMON have life, our world, too,\l"
# 548 "data/maps/MtPyre_Summit/scripts.pory"
	.string "is alive…\p"
# 549 "data/maps/MtPyre_Summit/scripts.pory"
	.string "The super-ancient POKéMON have\n"
# 550 "data/maps/MtPyre_Summit/scripts.pory"
	.string "taught us that…$"
# 551 "data/maps/MtPyre_Summit/scripts.pory"

# 552 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_WillYouHearOutMyTale:
# 553 "data/maps/MtPyre_Summit/scripts.pory"
	.string "MT. PYRE is where we calm the spirits\n"
# 554 "data/maps/MtPyre_Summit/scripts.pory"
	.string "of POKéMON that have passed on…\p"
# 555 "data/maps/MtPyre_Summit/scripts.pory"
	.string "This is a high place where one can\n"
# 556 "data/maps/MtPyre_Summit/scripts.pory"
	.string "see all of HOENN…\p"
# 557 "data/maps/MtPyre_Summit/scripts.pory"
	.string "The disembodied spirits of POKéMON\n"
# 558 "data/maps/MtPyre_Summit/scripts.pory"
	.string "must find solace here…\p"
# 559 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Is it coincidence that you are here…\p"
# 560 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Will you hear out my tale? A tale long\n"
# 561 "data/maps/MtPyre_Summit/scripts.pory"
	.string "told in the HOENN region?$"
# 562 "data/maps/MtPyre_Summit/scripts.pory"

# 563 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_GroudonKyogreTale:
# 564 "data/maps/MtPyre_Summit/scripts.pory"
	.string "It happened long, long ago…\p"
# 565 "data/maps/MtPyre_Summit/scripts.pory"
	.string "The world was wracked by a ferocious\n"
# 566 "data/maps/MtPyre_Summit/scripts.pory"
	.string "clash between the POKéMON of the land\l"
# 567 "data/maps/MtPyre_Summit/scripts.pory"
	.string "and the POKéMON of the sea…\p"
# 568 "data/maps/MtPyre_Summit/scripts.pory"
	.string "The POKéMON of the land raised\n"
# 569 "data/maps/MtPyre_Summit/scripts.pory"
	.string "mountains and created continents…\p"
# 570 "data/maps/MtPyre_Summit/scripts.pory"
	.string "The POKéMON of the sea raised huge\n"
# 571 "data/maps/MtPyre_Summit/scripts.pory"
	.string "waves and carved out oceans…\p"
# 572 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Their fierce duel raged without end.\p"
# 573 "data/maps/MtPyre_Summit/scripts.pory"
	.string "The world was engulfed in massive\n"
# 574 "data/maps/MtPyre_Summit/scripts.pory"
	.string "infernos and vicious storms.\p"
# 575 "data/maps/MtPyre_Summit/scripts.pory"
	.string "The BLUE ORB and the RED ORB brought\n"
# 576 "data/maps/MtPyre_Summit/scripts.pory"
	.string "an end to the calamity.\p"
# 577 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Light poured from the two ORBS and\n"
# 578 "data/maps/MtPyre_Summit/scripts.pory"
	.string "becalmed the enraged adversaries.\p"
# 579 "data/maps/MtPyre_Summit/scripts.pory"
	.string "The pair, made docile, dove deep into\n"
# 580 "data/maps/MtPyre_Summit/scripts.pory"
	.string "the sea where eventually they\l"
# 581 "data/maps/MtPyre_Summit/scripts.pory"
	.string "disappeared…$"
# 582 "data/maps/MtPyre_Summit/scripts.pory"

# 583 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_WellThatTooIsFine:
# 584 "data/maps/MtPyre_Summit/scripts.pory"
	.string "I see…\n"
# 585 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Well, that, too, is fine…$"
# 586 "data/maps/MtPyre_Summit/scripts.pory"

# 587 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_MaxieSilence:
# 588 "data/maps/MtPyre_Summit/scripts.pory"
	.string "MAXIE: {PLAYER}…\p"
# 589 "data/maps/MtPyre_Summit/scripts.pory"
	.string "… … … … … …\n"
# 590 "data/maps/MtPyre_Summit/scripts.pory"
	.string "… … … … … …$"
# 591 "data/maps/MtPyre_Summit/scripts.pory"

# 592 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_HearTheNewLegendOfHoenn:
# 593 "data/maps/MtPyre_Summit/scripts.pory"
	.string "It is my role to pass on the legends\n"
# 594 "data/maps/MtPyre_Summit/scripts.pory"
	.string "of HOENN to future generations.\p"
# 595 "data/maps/MtPyre_Summit/scripts.pory"
	.string "And the crisis that just ended in\n"
# 596 "data/maps/MtPyre_Summit/scripts.pory"
	.string "SOOTOPOLIS rewrote a legend…\p"
# 597 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Have you the time to hear the new\n"
# 598 "data/maps/MtPyre_Summit/scripts.pory"
	.string "legend of HOENN?$"
# 599 "data/maps/MtPyre_Summit/scripts.pory"

# 600 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_HoennTrioTale:
# 601 "data/maps/MtPyre_Summit/scripts.pory"
	.string "It happened long, long ago…\p"
# 602 "data/maps/MtPyre_Summit/scripts.pory"
	.string "The world was wracked by a ferocious\n"
# 603 "data/maps/MtPyre_Summit/scripts.pory"
	.string "clash between the POKéMON of the land\l"
# 604 "data/maps/MtPyre_Summit/scripts.pory"
	.string "and the POKéMON of the sea…\p"
# 605 "data/maps/MtPyre_Summit/scripts.pory"
	.string "The POKéMON of the land raised\n"
# 606 "data/maps/MtPyre_Summit/scripts.pory"
	.string "mountains and created continents…\p"
# 607 "data/maps/MtPyre_Summit/scripts.pory"
	.string "The POKéMON of the sea raised huge\n"
# 608 "data/maps/MtPyre_Summit/scripts.pory"
	.string "waves and carved out oceans…\p"
# 609 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Their fierce duel raged without end.\p"
# 610 "data/maps/MtPyre_Summit/scripts.pory"
	.string "The world was engulfed in massive\n"
# 611 "data/maps/MtPyre_Summit/scripts.pory"
	.string "fires and vicious storms.\p"
# 612 "data/maps/MtPyre_Summit/scripts.pory"
	.string "It was then that the POKéMON of\n"
# 613 "data/maps/MtPyre_Summit/scripts.pory"
	.string "the sky descended from a storm.\p"
# 614 "data/maps/MtPyre_Summit/scripts.pory"
	.string "The POKéMON, shining a vivid green,\n"
# 615 "data/maps/MtPyre_Summit/scripts.pory"
	.string "becalmed the two enraged POKéMON.\p"
# 616 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Then, its duty done, the green POKéMON\n"
# 617 "data/maps/MtPyre_Summit/scripts.pory"
	.string "flew off into the wild blue yonder…$"
