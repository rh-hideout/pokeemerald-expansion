# 1 "data/maps/PetalburgWoods/scripts.pory"

# 2 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_MapScripts::
# 3 "data/maps/PetalburgWoods/scripts.pory"
	.byte 0
# 4 "data/maps/PetalburgWoods/scripts.pory"

# 5 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_DevonResearcherLeft::
# 6 "data/maps/PetalburgWoods/scripts.pory"
	lockall
# 7 "data/maps/PetalburgWoods/scripts.pory"
	call PetalburgWoods_EventScript_DevonResearcherIntro
# 8 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherApproachPlayerLeft
# 9 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 10 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_HaveYouSeenShroomish, MSGBOX_DEFAULT
# 11 "data/maps/PetalburgWoods/scripts.pory"
	closemessage
# 12 "data/maps/PetalburgWoods/scripts.pory"
	playbgm MUS_ENCOUNTER_AQUA, FALSE
# 13 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaEntrance
# 14 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 15 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_IWasGoingToAmbushYou, MSGBOX_DEFAULT
# 16 "data/maps/PetalburgWoods/scripts.pory"
	closemessage
# 17 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaApproachResearcherLeft
# 18 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 19 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterUp
# 20 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 21 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_HandOverThosePapers, MSGBOX_DEFAULT
# 22 "data/maps/PetalburgWoods/scripts.pory"
	closemessage
# 23 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherFleeToPlayerLeft
# 24 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 25 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_YouHaveToHelpMe, MSGBOX_DEFAULT
# 26 "data/maps/PetalburgWoods/scripts.pory"
	closemessage
# 27 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaApproachPlayer
# 28 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 29 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_NoOneCrossesTeamAqua, MSGBOX_DEFAULT
# 30 "data/maps/PetalburgWoods/scripts.pory"
	trainerbattle_no_intro TRAINER_GRUNT_PETALBURG_WOODS, PetalburgWoods_Text_YoureKiddingMe
# 31 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaBackOff
# 32 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 33 "data/maps/PetalburgWoods/scripts.pory"
	call PetalburgWoods_EventScript_DevonResearcherPostBattle
# 34 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_PLAYER, PetalburgWoods_Movement_WatchResearcherLeave
# 35 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherExitLeft
# 36 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 37 "data/maps/PetalburgWoods/scripts.pory"
	goto PetalburgWoods_EventScript_RemoveDevonResearcher
# 38 "data/maps/PetalburgWoods/scripts.pory"
	end
# 39 "data/maps/PetalburgWoods/scripts.pory"

# 40 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_DevonResearcherRight::
# 41 "data/maps/PetalburgWoods/scripts.pory"
	lockall
# 42 "data/maps/PetalburgWoods/scripts.pory"
	call PetalburgWoods_EventScript_DevonResearcherIntro
# 43 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherApproachPlayerRight
# 44 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 45 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 46 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 47 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_HaveYouSeenShroomish, MSGBOX_DEFAULT
# 48 "data/maps/PetalburgWoods/scripts.pory"
	closemessage
# 49 "data/maps/PetalburgWoods/scripts.pory"
	playbgm MUS_ENCOUNTER_AQUA, FALSE
# 50 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaEntrance
# 51 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 52 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_IWasGoingToAmbushYou, MSGBOX_DEFAULT
# 53 "data/maps/PetalburgWoods/scripts.pory"
	closemessage
# 54 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaApproachResearcherRight
# 55 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 56 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterUp
# 57 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 58 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_HandOverThosePapers, MSGBOX_DEFAULT
# 59 "data/maps/PetalburgWoods/scripts.pory"
	closemessage
# 60 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherFleeToPlayerRight
# 61 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 62 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_YouHaveToHelpMe, MSGBOX_DEFAULT
# 63 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 64 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 65 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_NoOneCrossesTeamAqua, MSGBOX_DEFAULT
# 66 "data/maps/PetalburgWoods/scripts.pory"
	trainerbattle_no_intro TRAINER_GRUNT_PETALBURG_WOODS, PetalburgWoods_Text_YoureKiddingMe
# 67 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaBackOff
# 68 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 69 "data/maps/PetalburgWoods/scripts.pory"
	call PetalburgWoods_EventScript_DevonResearcherPostBattle
# 70 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_PLAYER, PetalburgWoods_Movement_WatchResearcherLeave
# 71 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherExitRight
# 72 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 73 "data/maps/PetalburgWoods/scripts.pory"
	goto PetalburgWoods_EventScript_RemoveDevonResearcher
# 74 "data/maps/PetalburgWoods/scripts.pory"
	end
# 75 "data/maps/PetalburgWoods/scripts.pory"

# 76 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_DevonResearcherIntro::
# 77 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherLookAround
# 78 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 79 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_NotAOneToBeFound, MSGBOX_DEFAULT
# 80 "data/maps/PetalburgWoods/scripts.pory"
	closemessage
# 81 "data/maps/PetalburgWoods/scripts.pory"
	return
# 82 "data/maps/PetalburgWoods/scripts.pory"

# 83 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_DevonResearcherPostBattle::
# 84 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_YouveGotSomeNerve, MSGBOX_DEFAULT
# 85 "data/maps/PetalburgWoods/scripts.pory"
	closemessage
# 86 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaRunAway
# 87 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 88 "data/maps/PetalburgWoods/scripts.pory"
	removeobject LOCALID_PETALBURG_WOODS_GRUNT
# 89 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 90 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 91 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_ThatWasAwfullyClose, MSGBOX_DEFAULT
# 92 "data/maps/PetalburgWoods/scripts.pory"
	giveitem ITEM_GREAT_BALL
# 93 "data/maps/PetalburgWoods/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, PetalburgWoods_EventScript_BagFull
# 94 "data/maps/PetalburgWoods/scripts.pory"
	goto PetalburgWoods_EventScript_DevonResearcherFinish
# 95 "data/maps/PetalburgWoods/scripts.pory"
	end
# 96 "data/maps/PetalburgWoods/scripts.pory"

# 97 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_BagFull::
# 98 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_YoureLoadedWithItems, MSGBOX_DEFAULT
# 99 "data/maps/PetalburgWoods/scripts.pory"
	goto PetalburgWoods_EventScript_DevonResearcherFinish
# 100 "data/maps/PetalburgWoods/scripts.pory"
	end
# 101 "data/maps/PetalburgWoods/scripts.pory"

# 102 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_DevonResearcherFinish::
# 103 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_TeamAquaAfterSomethingInRustboro, MSGBOX_DEFAULT
# 104 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherStartExit
# 105 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 106 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_ICantBeWastingTime, MSGBOX_DEFAULT
# 107 "data/maps/PetalburgWoods/scripts.pory"
	closemessage
# 108 "data/maps/PetalburgWoods/scripts.pory"
	return
# 109 "data/maps/PetalburgWoods/scripts.pory"

# 110 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_RemoveDevonResearcher::
# 111 "data/maps/PetalburgWoods/scripts.pory"
	removeobject LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE
# 112 "data/maps/PetalburgWoods/scripts.pory"
	setvar VAR_PETALBURG_WOODS_STATE, 1
# 113 "data/maps/PetalburgWoods/scripts.pory"
	releaseall
# 114 "data/maps/PetalburgWoods/scripts.pory"
	end
# 115 "data/maps/PetalburgWoods/scripts.pory"

# 116 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_DevonResearcherLookAround:
# 117 "data/maps/PetalburgWoods/scripts.pory"
	face_up
# 118 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 119 "data/maps/PetalburgWoods/scripts.pory"
	delay_4
# 120 "data/maps/PetalburgWoods/scripts.pory"
	face_right
# 121 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 122 "data/maps/PetalburgWoods/scripts.pory"
	delay_8
# 123 "data/maps/PetalburgWoods/scripts.pory"
	face_left
# 124 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 125 "data/maps/PetalburgWoods/scripts.pory"
	delay_8
# 126 "data/maps/PetalburgWoods/scripts.pory"
	face_down
# 127 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 128 "data/maps/PetalburgWoods/scripts.pory"
	face_right
# 129 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 130 "data/maps/PetalburgWoods/scripts.pory"
	delay_8
# 131 "data/maps/PetalburgWoods/scripts.pory"
	face_up
# 132 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 133 "data/maps/PetalburgWoods/scripts.pory"
	step_end
# 134 "data/maps/PetalburgWoods/scripts.pory"

# 135 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_DevonResearcherExitLeft:
# 136 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_right
# 137 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 138 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 139 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 140 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 141 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 142 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 143 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 144 "data/maps/PetalburgWoods/scripts.pory"
	step_end
# 145 "data/maps/PetalburgWoods/scripts.pory"

# 146 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_DevonResearcherApproachPlayerLeft:
# 147 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 148 "data/maps/PetalburgWoods/scripts.pory"
	face_player
# 149 "data/maps/PetalburgWoods/scripts.pory"
	walk_down
# 150 "data/maps/PetalburgWoods/scripts.pory"
	walk_down
# 151 "data/maps/PetalburgWoods/scripts.pory"
	step_end
# 152 "data/maps/PetalburgWoods/scripts.pory"

# 153 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_DevonResearcherApproachPlayerRight:
# 154 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 155 "data/maps/PetalburgWoods/scripts.pory"
	face_player
# 156 "data/maps/PetalburgWoods/scripts.pory"
	walk_down
# 157 "data/maps/PetalburgWoods/scripts.pory"
	walk_down
# 158 "data/maps/PetalburgWoods/scripts.pory"
	walk_down
# 159 "data/maps/PetalburgWoods/scripts.pory"
	walk_in_place_faster_right
# 160 "data/maps/PetalburgWoods/scripts.pory"
	step_end
# 161 "data/maps/PetalburgWoods/scripts.pory"

# 162 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_DevonResearcherExitRight:
# 163 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_left
# 164 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 165 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 166 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 167 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 168 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 169 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 170 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 171 "data/maps/PetalburgWoods/scripts.pory"
	step_end
# 172 "data/maps/PetalburgWoods/scripts.pory"

# 173 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_WatchResearcherLeave:
# 174 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 175 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 176 "data/maps/PetalburgWoods/scripts.pory"
	walk_in_place_faster_up
# 177 "data/maps/PetalburgWoods/scripts.pory"
	step_end
# 178 "data/maps/PetalburgWoods/scripts.pory"

# 179 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_DevonResearcherFleeToPlayerLeft:
# 180 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_right
# 181 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_down
# 182 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_down
# 183 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_left
# 184 "data/maps/PetalburgWoods/scripts.pory"
	walk_in_place_faster_up
# 185 "data/maps/PetalburgWoods/scripts.pory"
	step_end
# 186 "data/maps/PetalburgWoods/scripts.pory"

# 187 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_DevonResearcherFleeToPlayerRight:
# 188 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_down
# 189 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_right
# 190 "data/maps/PetalburgWoods/scripts.pory"
	walk_in_place_faster_up
# 191 "data/maps/PetalburgWoods/scripts.pory"
	step_end
# 192 "data/maps/PetalburgWoods/scripts.pory"

# 193 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_DevonResearcherStartExit:
# 194 "data/maps/PetalburgWoods/scripts.pory"
	walk_in_place_faster_down
# 195 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 196 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 197 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 198 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 199 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 200 "data/maps/PetalburgWoods/scripts.pory"
	face_up
# 201 "data/maps/PetalburgWoods/scripts.pory"
	step_end
# 202 "data/maps/PetalburgWoods/scripts.pory"

# 203 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_AquaApproachResearcherLeft:
# 204 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_down
# 205 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_down
# 206 "data/maps/PetalburgWoods/scripts.pory"
	step_end
# 207 "data/maps/PetalburgWoods/scripts.pory"

# 208 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_AquaBackOff:
# 209 "data/maps/PetalburgWoods/scripts.pory"
	lock_facing_direction
# 210 "data/maps/PetalburgWoods/scripts.pory"
	walk_up
# 211 "data/maps/PetalburgWoods/scripts.pory"
	unlock_facing_direction
# 212 "data/maps/PetalburgWoods/scripts.pory"
	step_end
# 213 "data/maps/PetalburgWoods/scripts.pory"

# 214 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_AquaRunAway:
# 215 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 216 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 217 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 218 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 219 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 220 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 221 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 222 "data/maps/PetalburgWoods/scripts.pory"
	step_end
# 223 "data/maps/PetalburgWoods/scripts.pory"

# 224 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_AquaApproachResearcherRight:
# 225 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_down
# 226 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_down
# 227 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_down
# 228 "data/maps/PetalburgWoods/scripts.pory"
	step_end
# 229 "data/maps/PetalburgWoods/scripts.pory"

# 230 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_AquaEntrance:
# 231 "data/maps/PetalburgWoods/scripts.pory"
	walk_down
# 232 "data/maps/PetalburgWoods/scripts.pory"
	walk_down
# 233 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 234 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 235 "data/maps/PetalburgWoods/scripts.pory"
	step_end
# 236 "data/maps/PetalburgWoods/scripts.pory"

# 237 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_AquaApproachPlayer:
# 238 "data/maps/PetalburgWoods/scripts.pory"
	walk_down
# 239 "data/maps/PetalburgWoods/scripts.pory"
	step_end
# 240 "data/maps/PetalburgWoods/scripts.pory"

# 241 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_Boy1::
# 242 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_StayOutOfTallGrass, MSGBOX_NPC
# 243 "data/maps/PetalburgWoods/scripts.pory"
	end
# 244 "data/maps/PetalburgWoods/scripts.pory"

# 245 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_Boy2::
# 246 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_HiddenItemsExplanation, MSGBOX_NPC
# 247 "data/maps/PetalburgWoods/scripts.pory"
	end
# 248 "data/maps/PetalburgWoods/scripts.pory"

# 249 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_Girl::
# 250 "data/maps/PetalburgWoods/scripts.pory"
	lock
# 251 "data/maps/PetalburgWoods/scripts.pory"
	faceplayer
# 252 "data/maps/PetalburgWoods/scripts.pory"
	goto_if_set FLAG_RECEIVED_MIRACLE_SEED, PetalburgWoods_EventScript_ExplainMiracleSeed
# 253 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_TryUsingThisItem, MSGBOX_DEFAULT
# 254 "data/maps/PetalburgWoods/scripts.pory"
	giveitem ITEM_MIRACLE_SEED
# 255 "data/maps/PetalburgWoods/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 256 "data/maps/PetalburgWoods/scripts.pory"
	setflag FLAG_RECEIVED_MIRACLE_SEED
# 257 "data/maps/PetalburgWoods/scripts.pory"
	release
# 258 "data/maps/PetalburgWoods/scripts.pory"
	end
# 259 "data/maps/PetalburgWoods/scripts.pory"

# 260 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_ExplainMiracleSeed::
# 261 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_MiracleSeedExplanation, MSGBOX_DEFAULT
# 262 "data/maps/PetalburgWoods/scripts.pory"
	release
# 263 "data/maps/PetalburgWoods/scripts.pory"
	end
# 264 "data/maps/PetalburgWoods/scripts.pory"

# 265 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_Sign1::
# 266 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_TrainerTipsExperience, MSGBOX_SIGN
# 267 "data/maps/PetalburgWoods/scripts.pory"
	end
# 268 "data/maps/PetalburgWoods/scripts.pory"

# 269 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_Sign2::
# 270 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_TrainerTipsPP, MSGBOX_SIGN
# 271 "data/maps/PetalburgWoods/scripts.pory"
	end
# 272 "data/maps/PetalburgWoods/scripts.pory"

# 273 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_Lyle::
# 274 "data/maps/PetalburgWoods/scripts.pory"
	trainerbattle_single TRAINER_LYLE, PetalburgWoods_Text_GoBugPokemonTeam, PetalburgWoods_Text_ICouldntWin
# 275 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_ImOutOfPokeBalls, MSGBOX_AUTOCLOSE
# 276 "data/maps/PetalburgWoods/scripts.pory"
	end
# 277 "data/maps/PetalburgWoods/scripts.pory"

# 278 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_James::
# 279 "data/maps/PetalburgWoods/scripts.pory"
	trainerbattle_single TRAINER_JAMES_1, PetalburgWoods_Text_InstantlyPopularWithBugPokemon, PetalburgWoods_Text_CantBePopularIfILose, PetalburgWoods_EventScript_TryRegisterJames
# 280 "data/maps/PetalburgWoods/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 281 "data/maps/PetalburgWoods/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, PetalburgWoods_EventScript_JamesRematch
# 282 "data/maps/PetalburgWoods/scripts.pory"
	setvar VAR_0x8004, TRAINER_JAMES_1
# 283 "data/maps/PetalburgWoods/scripts.pory"
	specialvar VAR_RESULT, IsTrainerRegistered
# 284 "data/maps/PetalburgWoods/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, PetalburgWoods_EventScript_TryRegisterJames2
# 285 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_PeopleRespectYou, MSGBOX_DEFAULT
# 286 "data/maps/PetalburgWoods/scripts.pory"
	release
# 287 "data/maps/PetalburgWoods/scripts.pory"
	end
# 288 "data/maps/PetalburgWoods/scripts.pory"

# 289 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_TryRegisterJames::
# 290 "data/maps/PetalburgWoods/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 291 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 292 "data/maps/PetalburgWoods/scripts.pory"
	goto_if_set FLAG_HAS_MATCH_CALL, PetalburgWoods_EventScript_RegisterJames
# 293 "data/maps/PetalburgWoods/scripts.pory"
	release
# 294 "data/maps/PetalburgWoods/scripts.pory"
	end
# 295 "data/maps/PetalburgWoods/scripts.pory"

# 296 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_RegisterJames::
# 297 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_IWantRematch1, MSGBOX_DEFAULT
# 298 "data/maps/PetalburgWoods/scripts.pory"
	register_matchcall TRAINER_JAMES_1
# 299 "data/maps/PetalburgWoods/scripts.pory"
	release
# 300 "data/maps/PetalburgWoods/scripts.pory"
	end
# 301 "data/maps/PetalburgWoods/scripts.pory"

# 302 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_TryRegisterJames2::
# 303 "data/maps/PetalburgWoods/scripts.pory"
	goto_if_set FLAG_HAS_MATCH_CALL, PetalburgWoods_EventScript_RegisterJames2
# 304 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_PeopleRespectYou, MSGBOX_DEFAULT
# 305 "data/maps/PetalburgWoods/scripts.pory"
	release
# 306 "data/maps/PetalburgWoods/scripts.pory"
	end
# 307 "data/maps/PetalburgWoods/scripts.pory"

# 308 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_RegisterJames2::
# 309 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_IWantRematch2, MSGBOX_DEFAULT
# 310 "data/maps/PetalburgWoods/scripts.pory"
	register_matchcall TRAINER_JAMES_1
# 311 "data/maps/PetalburgWoods/scripts.pory"
	release
# 312 "data/maps/PetalburgWoods/scripts.pory"
	end
# 313 "data/maps/PetalburgWoods/scripts.pory"

# 314 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_JamesRematch::
# 315 "data/maps/PetalburgWoods/scripts.pory"
	trainerbattle_rematch TRAINER_JAMES_1, PetalburgWoods_Text_MyPokemonHaveGrown, PetalburgWoods_Text_CantBePopularIfLose
# 316 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_IveBeenTrainingHard, MSGBOX_AUTOCLOSE
# 317 "data/maps/PetalburgWoods/scripts.pory"
	end
# 318 "data/maps/PetalburgWoods/scripts.pory"

# 319 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_NotAOneToBeFound:
# 320 "data/maps/PetalburgWoods/scripts.pory"
	.string "Hmmm…\n"
# 321 "data/maps/PetalburgWoods/scripts.pory"
	.string "Not a one to be found…$"
# 322 "data/maps/PetalburgWoods/scripts.pory"

# 323 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_HaveYouSeenShroomish:
# 324 "data/maps/PetalburgWoods/scripts.pory"
	.string "Hello, have you seen any POKéMON\n"
# 325 "data/maps/PetalburgWoods/scripts.pory"
	.string "called SHROOMISH around here?\p"
# 326 "data/maps/PetalburgWoods/scripts.pory"
	.string "I really love that POKéMON.$"
# 327 "data/maps/PetalburgWoods/scripts.pory"

# 328 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_IWasGoingToAmbushYou:
# 329 "data/maps/PetalburgWoods/scripts.pory"
	.string "I was going to ambush you, but you\n"
# 330 "data/maps/PetalburgWoods/scripts.pory"
	.string "had to dawdle in PETALBURG WOODS\l"
# 331 "data/maps/PetalburgWoods/scripts.pory"
	.string "forever, didn't you?\p"
# 332 "data/maps/PetalburgWoods/scripts.pory"
	.string "I got sick of waiting, so here I am!$"
# 333 "data/maps/PetalburgWoods/scripts.pory"

# 334 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_HandOverThosePapers:
# 335 "data/maps/PetalburgWoods/scripts.pory"
	.string "You! DEVON RESEARCHER!\p"
# 336 "data/maps/PetalburgWoods/scripts.pory"
	.string "Hand over those papers!$"
# 337 "data/maps/PetalburgWoods/scripts.pory"

# 338 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_YouHaveToHelpMe:
# 339 "data/maps/PetalburgWoods/scripts.pory"
	.string "Aiyeeeh!\p"
# 340 "data/maps/PetalburgWoods/scripts.pory"
	.string "You're a POKéMON TRAINER, aren't you?\n"
# 341 "data/maps/PetalburgWoods/scripts.pory"
	.string "You've got to help me, please!$"
# 342 "data/maps/PetalburgWoods/scripts.pory"

# 343 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_NoOneCrossesTeamAqua:
# 344 "data/maps/PetalburgWoods/scripts.pory"
	.string "Hunh? What do you think you're doing?\n"
# 345 "data/maps/PetalburgWoods/scripts.pory"
	.string "What, you're going to protect him?\p"
# 346 "data/maps/PetalburgWoods/scripts.pory"
	.string "No one who crosses TEAM AQUA\n"
# 347 "data/maps/PetalburgWoods/scripts.pory"
	.string "gets any mercy, not even a kid!\p"
# 348 "data/maps/PetalburgWoods/scripts.pory"
	.string "Come on and battle me!$"
# 349 "data/maps/PetalburgWoods/scripts.pory"

# 350 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_YoureKiddingMe:
# 351 "data/maps/PetalburgWoods/scripts.pory"
	.string "You're kidding me! You're tough!$"
# 352 "data/maps/PetalburgWoods/scripts.pory"

# 353 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_YouveGotSomeNerve:
# 354 "data/maps/PetalburgWoods/scripts.pory"
	.string "Grrr… You've got some nerve\n"
# 355 "data/maps/PetalburgWoods/scripts.pory"
	.string "meddling with TEAM AQUA!\l"
# 356 "data/maps/PetalburgWoods/scripts.pory"
	.string "Come on and battle me again!\p"
# 357 "data/maps/PetalburgWoods/scripts.pory"
	.string "I wish I could say that, but I'm out of\n"
# 358 "data/maps/PetalburgWoods/scripts.pory"
	.string "POKéMON…\p"
# 359 "data/maps/PetalburgWoods/scripts.pory"
	.string "And, hey, we of TEAM AQUA are also\n"
# 360 "data/maps/PetalburgWoods/scripts.pory"
	.string "after something in RUSTBORO.\p"
# 361 "data/maps/PetalburgWoods/scripts.pory"
	.string "I'll let you go today!$"
# 362 "data/maps/PetalburgWoods/scripts.pory"

# 363 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_ThatWasAwfullyClose:
# 364 "data/maps/PetalburgWoods/scripts.pory"
	.string "Whew…\n"
# 365 "data/maps/PetalburgWoods/scripts.pory"
	.string "That was awfully close!\p"
# 366 "data/maps/PetalburgWoods/scripts.pory"
	.string "Thanks to you, he didn't rob me of\n"
# 367 "data/maps/PetalburgWoods/scripts.pory"
	.string "these important papers.\p"
# 368 "data/maps/PetalburgWoods/scripts.pory"
	.string "I know, I'll give you a GREAT BALL as\n"
# 369 "data/maps/PetalburgWoods/scripts.pory"
	.string "my thanks!$"
# 370 "data/maps/PetalburgWoods/scripts.pory"

# 371 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_TeamAquaAfterSomethingInRustboro:
# 372 "data/maps/PetalburgWoods/scripts.pory"
	.string "Didn't that TEAM AQUA thug say\n"
# 373 "data/maps/PetalburgWoods/scripts.pory"
	.string "they were after something in\l"
# 374 "data/maps/PetalburgWoods/scripts.pory"
	.string "RUSTBORO, too?$"
# 375 "data/maps/PetalburgWoods/scripts.pory"

# 376 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_ICantBeWastingTime:
# 377 "data/maps/PetalburgWoods/scripts.pory"
	.string "Uh-oh! It's a crisis!\n"
# 378 "data/maps/PetalburgWoods/scripts.pory"
	.string "I can't be wasting time!$"
# 379 "data/maps/PetalburgWoods/scripts.pory"

# 380 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_YoureLoadedWithItems:
# 381 "data/maps/PetalburgWoods/scripts.pory"
	.string "You're loaded with items.\n"
# 382 "data/maps/PetalburgWoods/scripts.pory"
	.string "I can't give you this GREAT BALL.$"
# 383 "data/maps/PetalburgWoods/scripts.pory"

# 384 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_GoBugPokemonTeam:
# 385 "data/maps/PetalburgWoods/scripts.pory"
	.string "I caught a whole bunch of POKéMON!\p"
# 386 "data/maps/PetalburgWoods/scripts.pory"
	.string "Go, go, go!\n"
# 387 "data/maps/PetalburgWoods/scripts.pory"
	.string "My BUG POKéMON team!$"
# 388 "data/maps/PetalburgWoods/scripts.pory"

# 389 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_ICouldntWin:
# 390 "data/maps/PetalburgWoods/scripts.pory"
	.string "I have all these POKéMON,\n"
# 391 "data/maps/PetalburgWoods/scripts.pory"
	.string "but I couldn't win…$"
# 392 "data/maps/PetalburgWoods/scripts.pory"

# 393 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_ImOutOfPokeBalls:
# 394 "data/maps/PetalburgWoods/scripts.pory"
	.string "I caught a bunch of POKéMON.\n"
# 395 "data/maps/PetalburgWoods/scripts.pory"
	.string "Now I'm out of POKé BALLS.$"
# 396 "data/maps/PetalburgWoods/scripts.pory"

# 397 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_InstantlyPopularWithBugPokemon:
# 398 "data/maps/PetalburgWoods/scripts.pory"
	.string "If you take BUG POKéMON to school,\n"
# 399 "data/maps/PetalburgWoods/scripts.pory"
	.string "you get to be instantly popular!$"
# 400 "data/maps/PetalburgWoods/scripts.pory"

# 401 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_CantBePopularIfILose:
# 402 "data/maps/PetalburgWoods/scripts.pory"
	.string "I can't be popular if I lose.$"
# 403 "data/maps/PetalburgWoods/scripts.pory"

# 404 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_PeopleRespectYou:
# 405 "data/maps/PetalburgWoods/scripts.pory"
	.string "If you have a big BUG POKéMON,\n"
# 406 "data/maps/PetalburgWoods/scripts.pory"
	.string "people respect you for it.$"
# 407 "data/maps/PetalburgWoods/scripts.pory"

# 408 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_IWantRematch1:
# 409 "data/maps/PetalburgWoods/scripts.pory"
	.string "I want a rematch when my BUG\n"
# 410 "data/maps/PetalburgWoods/scripts.pory"
	.string "POKéMON grow up!\p"
# 411 "data/maps/PetalburgWoods/scripts.pory"
	.string "I'm registering you in my POKéNAV!$"
# 412 "data/maps/PetalburgWoods/scripts.pory"

# 413 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_IWantRematch2:
# 414 "data/maps/PetalburgWoods/scripts.pory"
	.string "I want a rematch when my BUG \n"
# 415 "data/maps/PetalburgWoods/scripts.pory"
	.string "POKéMON grow up!\p"
# 416 "data/maps/PetalburgWoods/scripts.pory"
	.string "I'm registering you in my POKéNAV!$"
# 417 "data/maps/PetalburgWoods/scripts.pory"

# 418 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_MyPokemonHaveGrown:
# 419 "data/maps/PetalburgWoods/scripts.pory"
	.string "My BUG POKéMON have grown.\n"
# 420 "data/maps/PetalburgWoods/scripts.pory"
	.string "I'll be popular again.$"
# 421 "data/maps/PetalburgWoods/scripts.pory"

# 422 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_CantBePopularIfLose:
# 423 "data/maps/PetalburgWoods/scripts.pory"
	.string "I can't be popular if I lose.$"
# 424 "data/maps/PetalburgWoods/scripts.pory"

# 425 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_IveBeenTrainingHard:
# 426 "data/maps/PetalburgWoods/scripts.pory"
	.string "You get to be popular if you have\n"
# 427 "data/maps/PetalburgWoods/scripts.pory"
	.string "strong POKéMON, right?\l"
# 428 "data/maps/PetalburgWoods/scripts.pory"
	.string "So, I've been training hard.$"
# 429 "data/maps/PetalburgWoods/scripts.pory"

# 430 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_StayOutOfTallGrass:
# 431 "data/maps/PetalburgWoods/scripts.pory"
	.string "Yo, there!\n"
# 432 "data/maps/PetalburgWoods/scripts.pory"
	.string "Your POKéMON doing okay?\p"
# 433 "data/maps/PetalburgWoods/scripts.pory"
	.string "If your POKéMON are weak and you want\n"
# 434 "data/maps/PetalburgWoods/scripts.pory"
	.string "to avoid battles, you should stay out\l"
# 435 "data/maps/PetalburgWoods/scripts.pory"
	.string "of tall grass.$"
# 436 "data/maps/PetalburgWoods/scripts.pory"

# 437 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_HiddenItemsExplanation:
# 438 "data/maps/PetalburgWoods/scripts.pory"
	.string "Sometimes, there are things on the\n"
# 439 "data/maps/PetalburgWoods/scripts.pory"
	.string "ground even if you can't see them.\p"
# 440 "data/maps/PetalburgWoods/scripts.pory"
	.string "That's why I always check where I'm\n"
# 441 "data/maps/PetalburgWoods/scripts.pory"
	.string "walking.$"
# 442 "data/maps/PetalburgWoods/scripts.pory"

# 443 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_TryUsingThisItem:
# 444 "data/maps/PetalburgWoods/scripts.pory"
	.string "Oh, neat!\n"
# 445 "data/maps/PetalburgWoods/scripts.pory"
	.string "That's the BADGE from RUSTBORO GYM!\p"
# 446 "data/maps/PetalburgWoods/scripts.pory"
	.string "You must be a TRAINER.\n"
# 447 "data/maps/PetalburgWoods/scripts.pory"
	.string "You should try using this item.$"
# 448 "data/maps/PetalburgWoods/scripts.pory"

# 449 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_MiracleSeedExplanation:
# 450 "data/maps/PetalburgWoods/scripts.pory"
	.string "It's a MIRACLE SEED.\n"
# 451 "data/maps/PetalburgWoods/scripts.pory"
	.string "If a POKéMON holds that item, its\l"
# 452 "data/maps/PetalburgWoods/scripts.pory"
	.string "GRASS-type moves become stronger.\p"
# 453 "data/maps/PetalburgWoods/scripts.pory"
	.string "Besides MIRACLE SEED, I think there are\n"
# 454 "data/maps/PetalburgWoods/scripts.pory"
	.string "other convenient items for POKéMON\l"
# 455 "data/maps/PetalburgWoods/scripts.pory"
	.string "to hold.$"
# 456 "data/maps/PetalburgWoods/scripts.pory"

# 457 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_TrainerTipsExperience:
# 458 "data/maps/PetalburgWoods/scripts.pory"
	.string "TRAINER TIPS\p"
# 459 "data/maps/PetalburgWoods/scripts.pory"
	.string "Any POKéMON that appears even once\n"
# 460 "data/maps/PetalburgWoods/scripts.pory"
	.string "in a battle is awarded EXP Points.\p"
# 461 "data/maps/PetalburgWoods/scripts.pory"
	.string "To raise a weak POKéMON, put it at the\n"
# 462 "data/maps/PetalburgWoods/scripts.pory"
	.string "left of the team list.\p"
# 463 "data/maps/PetalburgWoods/scripts.pory"
	.string "As soon as a battle starts, switch it\n"
# 464 "data/maps/PetalburgWoods/scripts.pory"
	.string "out. It will earn EXP Points without\l"
# 465 "data/maps/PetalburgWoods/scripts.pory"
	.string "being exposed to any harm.$"
# 466 "data/maps/PetalburgWoods/scripts.pory"

# 467 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_TrainerTipsPP:
# 468 "data/maps/PetalburgWoods/scripts.pory"
	.string "TRAINER TIPS\p"
# 469 "data/maps/PetalburgWoods/scripts.pory"
	.string "In addition to Hit Points (HP), POKéMON\n"
# 470 "data/maps/PetalburgWoods/scripts.pory"
	.string "have Power Points (PP) that are used to\l"
# 471 "data/maps/PetalburgWoods/scripts.pory"
	.string "make moves during battle.\p"
# 472 "data/maps/PetalburgWoods/scripts.pory"
	.string "If a POKéMON runs out of PP, it must be\n"
# 473 "data/maps/PetalburgWoods/scripts.pory"
	.string "taken to a POKéMON CENTER.$"
