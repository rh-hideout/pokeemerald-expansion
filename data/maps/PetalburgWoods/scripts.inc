# 1 "data/maps/PetalburgWoods/scripts.pory"

# 2 "data/maps/PetalburgWoods/scripts.pory"
.set LOCALID_GRUNT, 3
# 3 "data/maps/PetalburgWoods/scripts.pory"
.set LOCALID_DEVON_EMPLOYEE, 4
# 4 "data/maps/PetalburgWoods/scripts.pory"

# 5 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_MapScripts::
# 6 "data/maps/PetalburgWoods/scripts.pory"
	.byte 0
# 7 "data/maps/PetalburgWoods/scripts.pory"

# 8 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_DevonResearcherLeft::
# 9 "data/maps/PetalburgWoods/scripts.pory"
	lockall
# 10 "data/maps/PetalburgWoods/scripts.pory"
	call PetalburgWoods_EventScript_DevonResearcherIntro
# 11 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherApproachPlayerLeft
# 12 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 13 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_HaveYouSeenShroomish, MSGBOX_DEFAULT
# 14 "data/maps/PetalburgWoods/scripts.pory"
	closemessage
# 15 "data/maps/PetalburgWoods/scripts.pory"
	playbgm MUS_ENCOUNTER_AQUA, FALSE
# 16 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaEntrance
# 17 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 18 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_IWasGoingToAmbushYou, MSGBOX_DEFAULT
# 19 "data/maps/PetalburgWoods/scripts.pory"
	closemessage
# 20 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaApproachResearcherLeft
# 21 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 22 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterUp
# 23 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 24 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_HandOverThosePapers, MSGBOX_DEFAULT
# 25 "data/maps/PetalburgWoods/scripts.pory"
	closemessage
# 26 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherFleeToPlayerLeft
# 27 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 28 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_YouHaveToHelpMe, MSGBOX_DEFAULT
# 29 "data/maps/PetalburgWoods/scripts.pory"
	closemessage
# 30 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaApproachPlayer
# 31 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 32 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_NoOneCrossesTeamAqua, MSGBOX_DEFAULT
# 33 "data/maps/PetalburgWoods/scripts.pory"
	trainerbattle_no_intro TRAINER_GRUNT_PETALBURG_WOODS, PetalburgWoods_Text_YoureKiddingMe
# 34 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaBackOff
# 35 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 36 "data/maps/PetalburgWoods/scripts.pory"
	call PetalburgWoods_EventScript_DevonResearcherPostBattle
# 37 "data/maps/PetalburgWoods/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgWoods_Movement_WatchResearcherLeave
# 38 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherExitLeft
# 39 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 40 "data/maps/PetalburgWoods/scripts.pory"
	goto PetalburgWoods_EventScript_RemoveDevonResearcher
# 41 "data/maps/PetalburgWoods/scripts.pory"
	end
# 42 "data/maps/PetalburgWoods/scripts.pory"

# 43 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_DevonResearcherRight::
# 44 "data/maps/PetalburgWoods/scripts.pory"
	lockall
# 45 "data/maps/PetalburgWoods/scripts.pory"
	call PetalburgWoods_EventScript_DevonResearcherIntro
# 46 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherApproachPlayerRight
# 47 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 48 "data/maps/PetalburgWoods/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 49 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 50 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_HaveYouSeenShroomish, MSGBOX_DEFAULT
# 51 "data/maps/PetalburgWoods/scripts.pory"
	closemessage
# 52 "data/maps/PetalburgWoods/scripts.pory"
	playbgm MUS_ENCOUNTER_AQUA, FALSE
# 53 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaEntrance
# 54 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 55 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_IWasGoingToAmbushYou, MSGBOX_DEFAULT
# 56 "data/maps/PetalburgWoods/scripts.pory"
	closemessage
# 57 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaApproachResearcherRight
# 58 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 59 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterUp
# 60 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 61 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_HandOverThosePapers, MSGBOX_DEFAULT
# 62 "data/maps/PetalburgWoods/scripts.pory"
	closemessage
# 63 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherFleeToPlayerRight
# 64 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 65 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_YouHaveToHelpMe, MSGBOX_DEFAULT
# 66 "data/maps/PetalburgWoods/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 67 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 68 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_NoOneCrossesTeamAqua, MSGBOX_DEFAULT
# 69 "data/maps/PetalburgWoods/scripts.pory"
	trainerbattle_no_intro TRAINER_GRUNT_PETALBURG_WOODS, PetalburgWoods_Text_YoureKiddingMe
# 70 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaBackOff
# 71 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 72 "data/maps/PetalburgWoods/scripts.pory"
	call PetalburgWoods_EventScript_DevonResearcherPostBattle
# 73 "data/maps/PetalburgWoods/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgWoods_Movement_WatchResearcherLeave
# 74 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherExitRight
# 75 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 76 "data/maps/PetalburgWoods/scripts.pory"
	goto PetalburgWoods_EventScript_RemoveDevonResearcher
# 77 "data/maps/PetalburgWoods/scripts.pory"
	end
# 78 "data/maps/PetalburgWoods/scripts.pory"

# 79 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_DevonResearcherIntro::
# 80 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherLookAround
# 81 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 82 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_NotAOneToBeFound, MSGBOX_DEFAULT
# 83 "data/maps/PetalburgWoods/scripts.pory"
	closemessage
# 84 "data/maps/PetalburgWoods/scripts.pory"
	return
# 85 "data/maps/PetalburgWoods/scripts.pory"

# 86 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_DevonResearcherPostBattle::
# 87 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_YouveGotSomeNerve, MSGBOX_DEFAULT
# 88 "data/maps/PetalburgWoods/scripts.pory"
	closemessage
# 89 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaRunAway
# 90 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 91 "data/maps/PetalburgWoods/scripts.pory"
	removeobject LOCALID_GRUNT
# 92 "data/maps/PetalburgWoods/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 93 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 94 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_ThatWasAwfullyClose, MSGBOX_DEFAULT
# 95 "data/maps/PetalburgWoods/scripts.pory"
	giveitem ITEM_GREAT_BALL
# 96 "data/maps/PetalburgWoods/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, PetalburgWoods_EventScript_BagFull
# 97 "data/maps/PetalburgWoods/scripts.pory"
	goto PetalburgWoods_EventScript_DevonResearcherFinish
# 98 "data/maps/PetalburgWoods/scripts.pory"
	end
# 99 "data/maps/PetalburgWoods/scripts.pory"

# 100 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_BagFull::
# 101 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_YoureLoadedWithItems, MSGBOX_DEFAULT
# 102 "data/maps/PetalburgWoods/scripts.pory"
	goto PetalburgWoods_EventScript_DevonResearcherFinish
# 103 "data/maps/PetalburgWoods/scripts.pory"
	end
# 104 "data/maps/PetalburgWoods/scripts.pory"

# 105 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_DevonResearcherFinish::
# 106 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_TeamAquaAfterSomethingInRustboro, MSGBOX_DEFAULT
# 107 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherStartExit
# 108 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 109 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_ICantBeWastingTime, MSGBOX_DEFAULT
# 110 "data/maps/PetalburgWoods/scripts.pory"
	closemessage
# 111 "data/maps/PetalburgWoods/scripts.pory"
	return
# 112 "data/maps/PetalburgWoods/scripts.pory"

# 113 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_RemoveDevonResearcher::
# 114 "data/maps/PetalburgWoods/scripts.pory"
	removeobject LOCALID_DEVON_EMPLOYEE
# 115 "data/maps/PetalburgWoods/scripts.pory"
	setvar VAR_PETALBURG_WOODS_STATE, 1
# 116 "data/maps/PetalburgWoods/scripts.pory"
	releaseall
# 117 "data/maps/PetalburgWoods/scripts.pory"
	end
# 118 "data/maps/PetalburgWoods/scripts.pory"

# 119 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_DevonResearcherLookAround:
# 120 "data/maps/PetalburgWoods/scripts.pory"
	face_up
# 121 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 122 "data/maps/PetalburgWoods/scripts.pory"
	delay_4
# 123 "data/maps/PetalburgWoods/scripts.pory"
	face_right
# 124 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 125 "data/maps/PetalburgWoods/scripts.pory"
	delay_8
# 126 "data/maps/PetalburgWoods/scripts.pory"
	face_left
# 127 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 128 "data/maps/PetalburgWoods/scripts.pory"
	delay_8
# 129 "data/maps/PetalburgWoods/scripts.pory"
	face_down
# 130 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 131 "data/maps/PetalburgWoods/scripts.pory"
	face_right
# 132 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 133 "data/maps/PetalburgWoods/scripts.pory"
	delay_8
# 134 "data/maps/PetalburgWoods/scripts.pory"
	face_up
# 135 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 136 "data/maps/PetalburgWoods/scripts.pory"
	step_end
# 137 "data/maps/PetalburgWoods/scripts.pory"

# 138 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_DevonResearcherExitLeft:
# 139 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_right
# 140 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 141 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 142 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 143 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 144 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 145 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 146 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 147 "data/maps/PetalburgWoods/scripts.pory"
	step_end
# 148 "data/maps/PetalburgWoods/scripts.pory"

# 149 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_DevonResearcherApproachPlayerLeft:
# 150 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 151 "data/maps/PetalburgWoods/scripts.pory"
	face_player
# 152 "data/maps/PetalburgWoods/scripts.pory"
	walk_down
# 153 "data/maps/PetalburgWoods/scripts.pory"
	walk_down
# 154 "data/maps/PetalburgWoods/scripts.pory"
	step_end
# 155 "data/maps/PetalburgWoods/scripts.pory"

# 156 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_DevonResearcherApproachPlayerRight:
# 157 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 158 "data/maps/PetalburgWoods/scripts.pory"
	face_player
# 159 "data/maps/PetalburgWoods/scripts.pory"
	walk_down
# 160 "data/maps/PetalburgWoods/scripts.pory"
	walk_down
# 161 "data/maps/PetalburgWoods/scripts.pory"
	walk_down
# 162 "data/maps/PetalburgWoods/scripts.pory"
	walk_in_place_faster_right
# 163 "data/maps/PetalburgWoods/scripts.pory"
	step_end
# 164 "data/maps/PetalburgWoods/scripts.pory"

# 165 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_DevonResearcherExitRight:
# 166 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_left
# 167 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 168 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 169 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 170 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 171 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 172 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 173 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 174 "data/maps/PetalburgWoods/scripts.pory"
	step_end
# 175 "data/maps/PetalburgWoods/scripts.pory"

# 176 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_WatchResearcherLeave:
# 177 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 178 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 179 "data/maps/PetalburgWoods/scripts.pory"
	walk_in_place_faster_up
# 180 "data/maps/PetalburgWoods/scripts.pory"
	step_end
# 181 "data/maps/PetalburgWoods/scripts.pory"

# 182 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_DevonResearcherFleeToPlayerLeft:
# 183 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_right
# 184 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_down
# 185 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_down
# 186 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_left
# 187 "data/maps/PetalburgWoods/scripts.pory"
	walk_in_place_faster_up
# 188 "data/maps/PetalburgWoods/scripts.pory"
	step_end
# 189 "data/maps/PetalburgWoods/scripts.pory"

# 190 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_DevonResearcherFleeToPlayerRight:
# 191 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_down
# 192 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_right
# 193 "data/maps/PetalburgWoods/scripts.pory"
	walk_in_place_faster_up
# 194 "data/maps/PetalburgWoods/scripts.pory"
	step_end
# 195 "data/maps/PetalburgWoods/scripts.pory"

# 196 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_DevonResearcherStartExit:
# 197 "data/maps/PetalburgWoods/scripts.pory"
	walk_in_place_faster_down
# 198 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 199 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 200 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 201 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 202 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 203 "data/maps/PetalburgWoods/scripts.pory"
	face_up
# 204 "data/maps/PetalburgWoods/scripts.pory"
	step_end
# 205 "data/maps/PetalburgWoods/scripts.pory"

# 206 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_AquaApproachResearcherLeft:
# 207 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_down
# 208 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_down
# 209 "data/maps/PetalburgWoods/scripts.pory"
	step_end
# 210 "data/maps/PetalburgWoods/scripts.pory"

# 211 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_AquaBackOff:
# 212 "data/maps/PetalburgWoods/scripts.pory"
	lock_facing_direction
# 213 "data/maps/PetalburgWoods/scripts.pory"
	walk_up
# 214 "data/maps/PetalburgWoods/scripts.pory"
	unlock_facing_direction
# 215 "data/maps/PetalburgWoods/scripts.pory"
	step_end
# 216 "data/maps/PetalburgWoods/scripts.pory"

# 217 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_AquaRunAway:
# 218 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 219 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 220 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 221 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 222 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 223 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 224 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 225 "data/maps/PetalburgWoods/scripts.pory"
	step_end
# 226 "data/maps/PetalburgWoods/scripts.pory"

# 227 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_AquaApproachResearcherRight:
# 228 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_down
# 229 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_down
# 230 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_down
# 231 "data/maps/PetalburgWoods/scripts.pory"
	step_end
# 232 "data/maps/PetalburgWoods/scripts.pory"

# 233 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_AquaEntrance:
# 234 "data/maps/PetalburgWoods/scripts.pory"
	walk_down
# 235 "data/maps/PetalburgWoods/scripts.pory"
	walk_down
# 236 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 237 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 238 "data/maps/PetalburgWoods/scripts.pory"
	step_end
# 239 "data/maps/PetalburgWoods/scripts.pory"

# 240 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_AquaApproachPlayer:
# 241 "data/maps/PetalburgWoods/scripts.pory"
	walk_down
# 242 "data/maps/PetalburgWoods/scripts.pory"
	step_end
# 243 "data/maps/PetalburgWoods/scripts.pory"

# 244 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_Boy1::
# 245 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_StayOutOfTallGrass, MSGBOX_NPC
# 246 "data/maps/PetalburgWoods/scripts.pory"
	end
# 247 "data/maps/PetalburgWoods/scripts.pory"

# 248 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_Boy2::
# 249 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_HiddenItemsExplanation, MSGBOX_NPC
# 250 "data/maps/PetalburgWoods/scripts.pory"
	end
# 251 "data/maps/PetalburgWoods/scripts.pory"

# 252 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_Girl::
# 253 "data/maps/PetalburgWoods/scripts.pory"
	lock
# 254 "data/maps/PetalburgWoods/scripts.pory"
	faceplayer
# 255 "data/maps/PetalburgWoods/scripts.pory"
	goto_if_set FLAG_RECEIVED_MIRACLE_SEED, PetalburgWoods_EventScript_ExplainMiracleSeed
# 256 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_TryUsingThisItem, MSGBOX_DEFAULT
# 257 "data/maps/PetalburgWoods/scripts.pory"
	giveitem ITEM_MIRACLE_SEED
# 258 "data/maps/PetalburgWoods/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 259 "data/maps/PetalburgWoods/scripts.pory"
	setflag FLAG_RECEIVED_MIRACLE_SEED
# 260 "data/maps/PetalburgWoods/scripts.pory"
	release
# 261 "data/maps/PetalburgWoods/scripts.pory"
	end
# 262 "data/maps/PetalburgWoods/scripts.pory"

# 263 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_ExplainMiracleSeed::
# 264 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_MiracleSeedExplanation, MSGBOX_DEFAULT
# 265 "data/maps/PetalburgWoods/scripts.pory"
	release
# 266 "data/maps/PetalburgWoods/scripts.pory"
	end
# 267 "data/maps/PetalburgWoods/scripts.pory"

# 268 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_Sign1::
# 269 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_TrainerTipsExperience, MSGBOX_SIGN
# 270 "data/maps/PetalburgWoods/scripts.pory"
	end
# 271 "data/maps/PetalburgWoods/scripts.pory"

# 272 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_Sign2::
# 273 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_TrainerTipsPP, MSGBOX_SIGN
# 274 "data/maps/PetalburgWoods/scripts.pory"
	end
# 275 "data/maps/PetalburgWoods/scripts.pory"

# 276 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_Lyle::
# 277 "data/maps/PetalburgWoods/scripts.pory"
	trainerbattle_single TRAINER_LYLE, PetalburgWoods_Text_GoBugPokemonTeam, PetalburgWoods_Text_ICouldntWin
# 278 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_ImOutOfPokeBalls, MSGBOX_AUTOCLOSE
# 279 "data/maps/PetalburgWoods/scripts.pory"
	end
# 280 "data/maps/PetalburgWoods/scripts.pory"

# 281 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_James::
# 282 "data/maps/PetalburgWoods/scripts.pory"
	trainerbattle_single TRAINER_JAMES_1, PetalburgWoods_Text_InstantlyPopularWithBugPokemon, PetalburgWoods_Text_CantBePopularIfILose, PetalburgWoods_EventScript_TryRegisterJames
# 283 "data/maps/PetalburgWoods/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 284 "data/maps/PetalburgWoods/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, PetalburgWoods_EventScript_JamesRematch
# 285 "data/maps/PetalburgWoods/scripts.pory"
	setvar VAR_0x8004, TRAINER_JAMES_1
# 286 "data/maps/PetalburgWoods/scripts.pory"
	specialvar VAR_RESULT, IsTrainerRegistered
# 287 "data/maps/PetalburgWoods/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, PetalburgWoods_EventScript_TryRegisterJames2
# 288 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_PeopleRespectYou, MSGBOX_DEFAULT
# 289 "data/maps/PetalburgWoods/scripts.pory"
	release
# 290 "data/maps/PetalburgWoods/scripts.pory"
	end
# 291 "data/maps/PetalburgWoods/scripts.pory"

# 292 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_TryRegisterJames::
# 293 "data/maps/PetalburgWoods/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 294 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 295 "data/maps/PetalburgWoods/scripts.pory"
	goto_if_set FLAG_HAS_MATCH_CALL, PetalburgWoods_EventScript_RegisterJames
# 296 "data/maps/PetalburgWoods/scripts.pory"
	release
# 297 "data/maps/PetalburgWoods/scripts.pory"
	end
# 298 "data/maps/PetalburgWoods/scripts.pory"

# 299 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_RegisterJames::
# 300 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_IWantRematch1, MSGBOX_DEFAULT
# 301 "data/maps/PetalburgWoods/scripts.pory"
	register_matchcall TRAINER_JAMES_1
# 302 "data/maps/PetalburgWoods/scripts.pory"
	release
# 303 "data/maps/PetalburgWoods/scripts.pory"
	end
# 304 "data/maps/PetalburgWoods/scripts.pory"

# 305 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_TryRegisterJames2::
# 306 "data/maps/PetalburgWoods/scripts.pory"
	goto_if_set FLAG_HAS_MATCH_CALL, PetalburgWoods_EventScript_RegisterJames2
# 307 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_PeopleRespectYou, MSGBOX_DEFAULT
# 308 "data/maps/PetalburgWoods/scripts.pory"
	release
# 309 "data/maps/PetalburgWoods/scripts.pory"
	end
# 310 "data/maps/PetalburgWoods/scripts.pory"

# 311 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_RegisterJames2::
# 312 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_IWantRematch2, MSGBOX_DEFAULT
# 313 "data/maps/PetalburgWoods/scripts.pory"
	register_matchcall TRAINER_JAMES_1
# 314 "data/maps/PetalburgWoods/scripts.pory"
	release
# 315 "data/maps/PetalburgWoods/scripts.pory"
	end
# 316 "data/maps/PetalburgWoods/scripts.pory"

# 317 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_JamesRematch::
# 318 "data/maps/PetalburgWoods/scripts.pory"
	trainerbattle_rematch TRAINER_JAMES_1, PetalburgWoods_Text_MyPokemonHaveGrown, PetalburgWoods_Text_CantBePopularIfLose
# 319 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_IveBeenTrainingHard, MSGBOX_AUTOCLOSE
# 320 "data/maps/PetalburgWoods/scripts.pory"
	end
# 321 "data/maps/PetalburgWoods/scripts.pory"

# 322 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_NotAOneToBeFound:
# 323 "data/maps/PetalburgWoods/scripts.pory"
	.string "Hmmm…\n"
# 324 "data/maps/PetalburgWoods/scripts.pory"
	.string "Not a one to be found…$"
# 325 "data/maps/PetalburgWoods/scripts.pory"

# 326 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_HaveYouSeenShroomish:
# 327 "data/maps/PetalburgWoods/scripts.pory"
	.string "Hello, have you seen any POKéMON\n"
# 328 "data/maps/PetalburgWoods/scripts.pory"
	.string "called SHROOMISH around here?\p"
# 329 "data/maps/PetalburgWoods/scripts.pory"
	.string "I really love that POKéMON.$"
# 330 "data/maps/PetalburgWoods/scripts.pory"

# 331 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_IWasGoingToAmbushYou:
# 332 "data/maps/PetalburgWoods/scripts.pory"
	.string "I was going to ambush you, but you\n"
# 333 "data/maps/PetalburgWoods/scripts.pory"
	.string "had to dawdle in PETALBURG WOODS\l"
# 334 "data/maps/PetalburgWoods/scripts.pory"
	.string "forever, didn't you?\p"
# 335 "data/maps/PetalburgWoods/scripts.pory"
	.string "I got sick of waiting, so here I am!$"
# 336 "data/maps/PetalburgWoods/scripts.pory"

# 337 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_HandOverThosePapers:
# 338 "data/maps/PetalburgWoods/scripts.pory"
	.string "You! DEVON RESEARCHER!\p"
# 339 "data/maps/PetalburgWoods/scripts.pory"
	.string "Hand over those papers!$"
# 340 "data/maps/PetalburgWoods/scripts.pory"

# 341 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_YouHaveToHelpMe:
# 342 "data/maps/PetalburgWoods/scripts.pory"
	.string "Aiyeeeh!\p"
# 343 "data/maps/PetalburgWoods/scripts.pory"
	.string "You're a POKéMON TRAINER, aren't you?\n"
# 344 "data/maps/PetalburgWoods/scripts.pory"
	.string "You've got to help me, please!$"
# 345 "data/maps/PetalburgWoods/scripts.pory"

# 346 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_NoOneCrossesTeamAqua:
# 347 "data/maps/PetalburgWoods/scripts.pory"
	.string "Hunh? What do you think you're doing?\n"
# 348 "data/maps/PetalburgWoods/scripts.pory"
	.string "What, you're going to protect him?\p"
# 349 "data/maps/PetalburgWoods/scripts.pory"
	.string "No one who crosses TEAM AQUA\n"
# 350 "data/maps/PetalburgWoods/scripts.pory"
	.string "gets any mercy, not even a kid!\p"
# 351 "data/maps/PetalburgWoods/scripts.pory"
	.string "Come on and battle me!$"
# 352 "data/maps/PetalburgWoods/scripts.pory"

# 353 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_YoureKiddingMe:
# 354 "data/maps/PetalburgWoods/scripts.pory"
	.string "You're kidding me! You're tough!$"
# 355 "data/maps/PetalburgWoods/scripts.pory"

# 356 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_YouveGotSomeNerve:
# 357 "data/maps/PetalburgWoods/scripts.pory"
	.string "Grrr… You've got some nerve\n"
# 358 "data/maps/PetalburgWoods/scripts.pory"
	.string "meddling with TEAM AQUA!\l"
# 359 "data/maps/PetalburgWoods/scripts.pory"
	.string "Come on and battle me again!\p"
# 360 "data/maps/PetalburgWoods/scripts.pory"
	.string "I wish I could say that, but I'm out of\n"
# 361 "data/maps/PetalburgWoods/scripts.pory"
	.string "POKéMON…\p"
# 362 "data/maps/PetalburgWoods/scripts.pory"
	.string "And, hey, we of TEAM AQUA are also\n"
# 363 "data/maps/PetalburgWoods/scripts.pory"
	.string "after something in RUSTBORO.\p"
# 364 "data/maps/PetalburgWoods/scripts.pory"
	.string "I'll let you go today!$"
# 365 "data/maps/PetalburgWoods/scripts.pory"

# 366 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_ThatWasAwfullyClose:
# 367 "data/maps/PetalburgWoods/scripts.pory"
	.string "Whew…\n"
# 368 "data/maps/PetalburgWoods/scripts.pory"
	.string "That was awfully close!\p"
# 369 "data/maps/PetalburgWoods/scripts.pory"
	.string "Thanks to you, he didn't rob me of\n"
# 370 "data/maps/PetalburgWoods/scripts.pory"
	.string "these important papers.\p"
# 371 "data/maps/PetalburgWoods/scripts.pory"
	.string "I know, I'll give you a GREAT BALL as\n"
# 372 "data/maps/PetalburgWoods/scripts.pory"
	.string "my thanks!$"
# 373 "data/maps/PetalburgWoods/scripts.pory"

# 374 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_TeamAquaAfterSomethingInRustboro:
# 375 "data/maps/PetalburgWoods/scripts.pory"
	.string "Didn't that TEAM AQUA thug say\n"
# 376 "data/maps/PetalburgWoods/scripts.pory"
	.string "they were after something in\l"
# 377 "data/maps/PetalburgWoods/scripts.pory"
	.string "RUSTBORO, too?$"
# 378 "data/maps/PetalburgWoods/scripts.pory"

# 379 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_ICantBeWastingTime:
# 380 "data/maps/PetalburgWoods/scripts.pory"
	.string "Uh-oh! It's a crisis!\n"
# 381 "data/maps/PetalburgWoods/scripts.pory"
	.string "I can't be wasting time!$"
# 382 "data/maps/PetalburgWoods/scripts.pory"

# 383 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_YoureLoadedWithItems:
# 384 "data/maps/PetalburgWoods/scripts.pory"
	.string "You're loaded with items.\n"
# 385 "data/maps/PetalburgWoods/scripts.pory"
	.string "I can't give you this GREAT BALL.$"
# 386 "data/maps/PetalburgWoods/scripts.pory"

# 387 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_GoBugPokemonTeam:
# 388 "data/maps/PetalburgWoods/scripts.pory"
	.string "I caught a whole bunch of POKéMON!\p"
# 389 "data/maps/PetalburgWoods/scripts.pory"
	.string "Go, go, go!\n"
# 390 "data/maps/PetalburgWoods/scripts.pory"
	.string "My BUG POKéMON team!$"
# 391 "data/maps/PetalburgWoods/scripts.pory"

# 392 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_ICouldntWin:
# 393 "data/maps/PetalburgWoods/scripts.pory"
	.string "I have all these POKéMON,\n"
# 394 "data/maps/PetalburgWoods/scripts.pory"
	.string "but I couldn't win…$"
# 395 "data/maps/PetalburgWoods/scripts.pory"

# 396 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_ImOutOfPokeBalls:
# 397 "data/maps/PetalburgWoods/scripts.pory"
	.string "I caught a bunch of POKéMON.\n"
# 398 "data/maps/PetalburgWoods/scripts.pory"
	.string "Now I'm out of POKé BALLS.$"
# 399 "data/maps/PetalburgWoods/scripts.pory"

# 400 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_InstantlyPopularWithBugPokemon:
# 401 "data/maps/PetalburgWoods/scripts.pory"
	.string "If you take BUG POKéMON to school,\n"
# 402 "data/maps/PetalburgWoods/scripts.pory"
	.string "you get to be instantly popular!$"
# 403 "data/maps/PetalburgWoods/scripts.pory"

# 404 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_CantBePopularIfILose:
# 405 "data/maps/PetalburgWoods/scripts.pory"
	.string "I can't be popular if I lose.$"
# 406 "data/maps/PetalburgWoods/scripts.pory"

# 407 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_PeopleRespectYou:
# 408 "data/maps/PetalburgWoods/scripts.pory"
	.string "If you have a big BUG POKéMON,\n"
# 409 "data/maps/PetalburgWoods/scripts.pory"
	.string "people respect you for it.$"
# 410 "data/maps/PetalburgWoods/scripts.pory"

# 411 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_IWantRematch1:
# 412 "data/maps/PetalburgWoods/scripts.pory"
	.string "I want a rematch when my BUG\n"
# 413 "data/maps/PetalburgWoods/scripts.pory"
	.string "POKéMON grow up!\p"
# 414 "data/maps/PetalburgWoods/scripts.pory"
	.string "I'm registering you in my POKéNAV!$"
# 415 "data/maps/PetalburgWoods/scripts.pory"

# 416 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_IWantRematch2:
# 417 "data/maps/PetalburgWoods/scripts.pory"
	.string "I want a rematch when my BUG \n"
# 418 "data/maps/PetalburgWoods/scripts.pory"
	.string "POKéMON grow up!\p"
# 419 "data/maps/PetalburgWoods/scripts.pory"
	.string "I'm registering you in my POKéNAV!$"
# 420 "data/maps/PetalburgWoods/scripts.pory"

# 421 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_MyPokemonHaveGrown:
# 422 "data/maps/PetalburgWoods/scripts.pory"
	.string "My BUG POKéMON have grown.\n"
# 423 "data/maps/PetalburgWoods/scripts.pory"
	.string "I'll be popular again.$"
# 424 "data/maps/PetalburgWoods/scripts.pory"

# 425 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_CantBePopularIfLose:
# 426 "data/maps/PetalburgWoods/scripts.pory"
	.string "I can't be popular if I lose.$"
# 427 "data/maps/PetalburgWoods/scripts.pory"

# 428 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_IveBeenTrainingHard:
# 429 "data/maps/PetalburgWoods/scripts.pory"
	.string "You get to be popular if you have\n"
# 430 "data/maps/PetalburgWoods/scripts.pory"
	.string "strong POKéMON, right?\l"
# 431 "data/maps/PetalburgWoods/scripts.pory"
	.string "So, I've been training hard.$"
# 432 "data/maps/PetalburgWoods/scripts.pory"

# 433 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_StayOutOfTallGrass:
# 434 "data/maps/PetalburgWoods/scripts.pory"
	.string "Yo, there!\n"
# 435 "data/maps/PetalburgWoods/scripts.pory"
	.string "Your POKéMON doing okay?\p"
# 436 "data/maps/PetalburgWoods/scripts.pory"
	.string "If your POKéMON are weak and you want\n"
# 437 "data/maps/PetalburgWoods/scripts.pory"
	.string "to avoid battles, you should stay out\l"
# 438 "data/maps/PetalburgWoods/scripts.pory"
	.string "of tall grass.$"
# 439 "data/maps/PetalburgWoods/scripts.pory"

# 440 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_HiddenItemsExplanation:
# 441 "data/maps/PetalburgWoods/scripts.pory"
	.string "Sometimes, there are things on the\n"
# 442 "data/maps/PetalburgWoods/scripts.pory"
	.string "ground even if you can't see them.\p"
# 443 "data/maps/PetalburgWoods/scripts.pory"
	.string "That's why I always check where I'm\n"
# 444 "data/maps/PetalburgWoods/scripts.pory"
	.string "walking.$"
# 445 "data/maps/PetalburgWoods/scripts.pory"

# 446 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_TryUsingThisItem:
# 447 "data/maps/PetalburgWoods/scripts.pory"
	.string "Oh, neat!\n"
# 448 "data/maps/PetalburgWoods/scripts.pory"
	.string "That's the BADGE from RUSTBORO GYM!\p"
# 449 "data/maps/PetalburgWoods/scripts.pory"
	.string "You must be a TRAINER.\n"
# 450 "data/maps/PetalburgWoods/scripts.pory"
	.string "You should try using this item.$"
# 451 "data/maps/PetalburgWoods/scripts.pory"

# 452 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_MiracleSeedExplanation:
# 453 "data/maps/PetalburgWoods/scripts.pory"
	.string "It's a MIRACLE SEED.\n"
# 454 "data/maps/PetalburgWoods/scripts.pory"
	.string "If a POKéMON holds that item, its\l"
# 455 "data/maps/PetalburgWoods/scripts.pory"
	.string "GRASS-type moves become stronger.\p"
# 456 "data/maps/PetalburgWoods/scripts.pory"
	.string "Besides MIRACLE SEED, I think there are\n"
# 457 "data/maps/PetalburgWoods/scripts.pory"
	.string "other convenient items for POKéMON\l"
# 458 "data/maps/PetalburgWoods/scripts.pory"
	.string "to hold.$"
# 459 "data/maps/PetalburgWoods/scripts.pory"

# 460 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_TrainerTipsExperience:
# 461 "data/maps/PetalburgWoods/scripts.pory"
	.string "TRAINER TIPS\p"
# 462 "data/maps/PetalburgWoods/scripts.pory"
	.string "Any POKéMON that appears even once\n"
# 463 "data/maps/PetalburgWoods/scripts.pory"
	.string "in a battle is awarded EXP Points.\p"
# 464 "data/maps/PetalburgWoods/scripts.pory"
	.string "To raise a weak POKéMON, put it at the\n"
# 465 "data/maps/PetalburgWoods/scripts.pory"
	.string "left of the team list.\p"
# 466 "data/maps/PetalburgWoods/scripts.pory"
	.string "As soon as a battle starts, switch it\n"
# 467 "data/maps/PetalburgWoods/scripts.pory"
	.string "out. It will earn EXP Points without\l"
# 468 "data/maps/PetalburgWoods/scripts.pory"
	.string "being exposed to any harm.$"
# 469 "data/maps/PetalburgWoods/scripts.pory"

# 470 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_TrainerTipsPP:
# 471 "data/maps/PetalburgWoods/scripts.pory"
	.string "TRAINER TIPS\p"
# 472 "data/maps/PetalburgWoods/scripts.pory"
	.string "In addition to Hit Points (HP), POKéMON\n"
# 473 "data/maps/PetalburgWoods/scripts.pory"
	.string "have Power Points (PP) that are used to\l"
# 474 "data/maps/PetalburgWoods/scripts.pory"
	.string "make moves during battle.\p"
# 475 "data/maps/PetalburgWoods/scripts.pory"
	.string "If a POKéMON runs out of PP, it must be\n"
# 476 "data/maps/PetalburgWoods/scripts.pory"
	.string "taken to a POKéMON CENTER.$"
