# 1 "data/maps/PetalburgWoods/scripts.pory"

# 2 "data/maps/PetalburgWoods/scripts.pory"
.set LOCALID_GRUNT, 3
# 3 "data/maps/PetalburgWoods/scripts.pory"
.set LOCALID_DEVON_EMPLOYEE, 4
# 4 "data/maps/PetalburgWoods/scripts.pory"

# 5 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_MapScripts::
# 6 "data/maps/PetalburgWoods/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, PetalburgWoods_OnResume
# 7 "data/maps/PetalburgWoods/scripts.pory"
	.byte 0
# 8 "data/maps/PetalburgWoods/scripts.pory"

# 9 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_OnResume:
# 10 "data/maps/PetalburgWoods/scripts.pory"
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, PetalburgWoods_EventScript_TryRemoveCelebi
# 11 "data/maps/PetalburgWoods/scripts.pory"
	end
# 12 "data/maps/PetalburgWoods/scripts.pory"

# 13 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_TryRemoveCelebi::
# 14 "data/maps/PetalburgWoods/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 15 "data/maps/PetalburgWoods/scripts.pory"
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
# 16 "data/maps/PetalburgWoods/scripts.pory"
	removeobject VAR_LAST_TALKED
# 17 "data/maps/PetalburgWoods/scripts.pory"
	return
# 18 "data/maps/PetalburgWoods/scripts.pory"

# 19 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_DevonResearcherLeft::
# 20 "data/maps/PetalburgWoods/scripts.pory"
	lockall
# 21 "data/maps/PetalburgWoods/scripts.pory"
	call PetalburgWoods_EventScript_DevonResearcherIntro
# 22 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherApproachPlayerLeft
# 23 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 24 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_HaveYouSeenShroomish, MSGBOX_DEFAULT
# 25 "data/maps/PetalburgWoods/scripts.pory"
	closemessage
# 26 "data/maps/PetalburgWoods/scripts.pory"
	playbgm MUS_ENCOUNTER_AQUA, FALSE
# 27 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaEntrance
# 28 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 29 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_IWasGoingToAmbushYou, MSGBOX_DEFAULT
# 30 "data/maps/PetalburgWoods/scripts.pory"
	closemessage
# 31 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaApproachResearcherLeft
# 32 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 33 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterUp
# 34 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 35 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_HandOverThosePapers, MSGBOX_DEFAULT
# 36 "data/maps/PetalburgWoods/scripts.pory"
	closemessage
# 37 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherFleeToPlayerLeft
# 38 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 39 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_YouHaveToHelpMe, MSGBOX_DEFAULT
# 40 "data/maps/PetalburgWoods/scripts.pory"
	closemessage
# 41 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaApproachPlayer
# 42 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 43 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_NoOneCrossesTeamAqua, MSGBOX_DEFAULT
# 44 "data/maps/PetalburgWoods/scripts.pory"
	trainerbattle_no_intro TRAINER_GRUNT_PETALBURG_WOODS, PetalburgWoods_Text_YoureKiddingMe
# 45 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaBackOff
# 46 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 47 "data/maps/PetalburgWoods/scripts.pory"
	call PetalburgWoods_EventScript_DevonResearcherPostBattle
# 48 "data/maps/PetalburgWoods/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgWoods_Movement_WatchResearcherLeave
# 49 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherExitLeft
# 50 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 51 "data/maps/PetalburgWoods/scripts.pory"
	goto PetalburgWoods_EventScript_RemoveDevonResearcher
# 52 "data/maps/PetalburgWoods/scripts.pory"
	end
# 53 "data/maps/PetalburgWoods/scripts.pory"

# 54 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_DevonResearcherRight::
# 55 "data/maps/PetalburgWoods/scripts.pory"
	lockall
# 56 "data/maps/PetalburgWoods/scripts.pory"
	call PetalburgWoods_EventScript_DevonResearcherIntro
# 57 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherApproachPlayerRight
# 58 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 59 "data/maps/PetalburgWoods/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 60 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 61 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_HaveYouSeenShroomish, MSGBOX_DEFAULT
# 62 "data/maps/PetalburgWoods/scripts.pory"
	closemessage
# 63 "data/maps/PetalburgWoods/scripts.pory"
	playbgm MUS_ENCOUNTER_AQUA, FALSE
# 64 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaEntrance
# 65 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 66 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_IWasGoingToAmbushYou, MSGBOX_DEFAULT
# 67 "data/maps/PetalburgWoods/scripts.pory"
	closemessage
# 68 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaApproachResearcherRight
# 69 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 70 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterUp
# 71 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 72 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_HandOverThosePapers, MSGBOX_DEFAULT
# 73 "data/maps/PetalburgWoods/scripts.pory"
	closemessage
# 74 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherFleeToPlayerRight
# 75 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 76 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_YouHaveToHelpMe, MSGBOX_DEFAULT
# 77 "data/maps/PetalburgWoods/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 78 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 79 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_NoOneCrossesTeamAqua, MSGBOX_DEFAULT
# 80 "data/maps/PetalburgWoods/scripts.pory"
	trainerbattle_no_intro TRAINER_GRUNT_PETALBURG_WOODS, PetalburgWoods_Text_YoureKiddingMe
# 81 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaBackOff
# 82 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 83 "data/maps/PetalburgWoods/scripts.pory"
	call PetalburgWoods_EventScript_DevonResearcherPostBattle
# 84 "data/maps/PetalburgWoods/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgWoods_Movement_WatchResearcherLeave
# 85 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherExitRight
# 86 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 87 "data/maps/PetalburgWoods/scripts.pory"
	goto PetalburgWoods_EventScript_RemoveDevonResearcher
# 88 "data/maps/PetalburgWoods/scripts.pory"
	end
# 89 "data/maps/PetalburgWoods/scripts.pory"

# 90 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_DevonResearcherIntro::
# 91 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherLookAround
# 92 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 93 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_NotAOneToBeFound, MSGBOX_DEFAULT
# 94 "data/maps/PetalburgWoods/scripts.pory"
	closemessage
# 95 "data/maps/PetalburgWoods/scripts.pory"
	return
# 96 "data/maps/PetalburgWoods/scripts.pory"

# 97 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_DevonResearcherPostBattle::
# 98 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_YouveGotSomeNerve, MSGBOX_DEFAULT
# 99 "data/maps/PetalburgWoods/scripts.pory"
	closemessage
# 100 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaRunAway
# 101 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 102 "data/maps/PetalburgWoods/scripts.pory"
	removeobject LOCALID_GRUNT
# 103 "data/maps/PetalburgWoods/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 104 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 105 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_ThatWasAwfullyClose, MSGBOX_DEFAULT
# 106 "data/maps/PetalburgWoods/scripts.pory"
	giveitem ITEM_GREAT_BALL
# 107 "data/maps/PetalburgWoods/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, PetalburgWoods_EventScript_BagFull
# 108 "data/maps/PetalburgWoods/scripts.pory"
	goto PetalburgWoods_EventScript_DevonResearcherFinish
# 109 "data/maps/PetalburgWoods/scripts.pory"
	end
# 110 "data/maps/PetalburgWoods/scripts.pory"

# 111 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_BagFull::
# 112 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_YoureLoadedWithItems, MSGBOX_DEFAULT
# 113 "data/maps/PetalburgWoods/scripts.pory"
	goto PetalburgWoods_EventScript_DevonResearcherFinish
# 114 "data/maps/PetalburgWoods/scripts.pory"
	end
# 115 "data/maps/PetalburgWoods/scripts.pory"

# 116 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_DevonResearcherFinish::
# 117 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_TeamAquaAfterSomethingInRustboro, MSGBOX_DEFAULT
# 118 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherStartExit
# 119 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 120 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_ICantBeWastingTime, MSGBOX_DEFAULT
# 121 "data/maps/PetalburgWoods/scripts.pory"
	closemessage
# 122 "data/maps/PetalburgWoods/scripts.pory"
	return
# 123 "data/maps/PetalburgWoods/scripts.pory"

# 124 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_RemoveDevonResearcher::
# 125 "data/maps/PetalburgWoods/scripts.pory"
	removeobject LOCALID_DEVON_EMPLOYEE
# 126 "data/maps/PetalburgWoods/scripts.pory"
	setvar VAR_PETALBURG_WOODS_STATE, 1
# 127 "data/maps/PetalburgWoods/scripts.pory"
	releaseall
# 128 "data/maps/PetalburgWoods/scripts.pory"
	end
# 129 "data/maps/PetalburgWoods/scripts.pory"

# 130 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_DevonResearcherLookAround:
# 131 "data/maps/PetalburgWoods/scripts.pory"
	face_up
# 132 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 133 "data/maps/PetalburgWoods/scripts.pory"
	delay_4
# 134 "data/maps/PetalburgWoods/scripts.pory"
	face_right
# 135 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 136 "data/maps/PetalburgWoods/scripts.pory"
	delay_8
# 137 "data/maps/PetalburgWoods/scripts.pory"
	face_left
# 138 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 139 "data/maps/PetalburgWoods/scripts.pory"
	delay_8
# 140 "data/maps/PetalburgWoods/scripts.pory"
	face_down
# 141 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 142 "data/maps/PetalburgWoods/scripts.pory"
	face_right
# 143 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 144 "data/maps/PetalburgWoods/scripts.pory"
	delay_8
# 145 "data/maps/PetalburgWoods/scripts.pory"
	face_up
# 146 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 147 "data/maps/PetalburgWoods/scripts.pory"
	step_end
# 148 "data/maps/PetalburgWoods/scripts.pory"

# 149 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_DevonResearcherExitLeft:
# 150 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_right
# 151 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 152 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 153 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 154 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 155 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 156 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 157 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 158 "data/maps/PetalburgWoods/scripts.pory"
	step_end
# 159 "data/maps/PetalburgWoods/scripts.pory"

# 160 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_DevonResearcherApproachPlayerLeft:
# 161 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 162 "data/maps/PetalburgWoods/scripts.pory"
	face_player
# 163 "data/maps/PetalburgWoods/scripts.pory"
	walk_down
# 164 "data/maps/PetalburgWoods/scripts.pory"
	walk_down
# 165 "data/maps/PetalburgWoods/scripts.pory"
	step_end
# 166 "data/maps/PetalburgWoods/scripts.pory"

# 167 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_DevonResearcherApproachPlayerRight:
# 168 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 169 "data/maps/PetalburgWoods/scripts.pory"
	face_player
# 170 "data/maps/PetalburgWoods/scripts.pory"
	walk_down
# 171 "data/maps/PetalburgWoods/scripts.pory"
	walk_down
# 172 "data/maps/PetalburgWoods/scripts.pory"
	walk_down
# 173 "data/maps/PetalburgWoods/scripts.pory"
	walk_in_place_faster_right
# 174 "data/maps/PetalburgWoods/scripts.pory"
	step_end
# 175 "data/maps/PetalburgWoods/scripts.pory"

# 176 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_DevonResearcherExitRight:
# 177 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_left
# 178 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 179 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 180 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 181 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 182 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 183 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 184 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 185 "data/maps/PetalburgWoods/scripts.pory"
	step_end
# 186 "data/maps/PetalburgWoods/scripts.pory"

# 187 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_WatchResearcherLeave:
# 188 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 189 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 190 "data/maps/PetalburgWoods/scripts.pory"
	walk_in_place_faster_up
# 191 "data/maps/PetalburgWoods/scripts.pory"
	step_end
# 192 "data/maps/PetalburgWoods/scripts.pory"

# 193 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_DevonResearcherFleeToPlayerLeft:
# 194 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_right
# 195 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_down
# 196 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_down
# 197 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_left
# 198 "data/maps/PetalburgWoods/scripts.pory"
	walk_in_place_faster_up
# 199 "data/maps/PetalburgWoods/scripts.pory"
	step_end
# 200 "data/maps/PetalburgWoods/scripts.pory"

# 201 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_DevonResearcherFleeToPlayerRight:
# 202 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_down
# 203 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_right
# 204 "data/maps/PetalburgWoods/scripts.pory"
	walk_in_place_faster_up
# 205 "data/maps/PetalburgWoods/scripts.pory"
	step_end
# 206 "data/maps/PetalburgWoods/scripts.pory"

# 207 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_DevonResearcherStartExit:
# 208 "data/maps/PetalburgWoods/scripts.pory"
	walk_in_place_faster_down
# 209 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 210 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 211 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 212 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 213 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 214 "data/maps/PetalburgWoods/scripts.pory"
	face_up
# 215 "data/maps/PetalburgWoods/scripts.pory"
	step_end
# 216 "data/maps/PetalburgWoods/scripts.pory"

# 217 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_AquaApproachResearcherLeft:
# 218 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_down
# 219 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_down
# 220 "data/maps/PetalburgWoods/scripts.pory"
	step_end
# 221 "data/maps/PetalburgWoods/scripts.pory"

# 222 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_AquaBackOff:
# 223 "data/maps/PetalburgWoods/scripts.pory"
	lock_facing_direction
# 224 "data/maps/PetalburgWoods/scripts.pory"
	walk_up
# 225 "data/maps/PetalburgWoods/scripts.pory"
	unlock_facing_direction
# 226 "data/maps/PetalburgWoods/scripts.pory"
	step_end
# 227 "data/maps/PetalburgWoods/scripts.pory"

# 228 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_AquaRunAway:
# 229 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 230 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 231 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 232 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 233 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 234 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 235 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 236 "data/maps/PetalburgWoods/scripts.pory"
	step_end
# 237 "data/maps/PetalburgWoods/scripts.pory"

# 238 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_AquaApproachResearcherRight:
# 239 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_down
# 240 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_down
# 241 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_down
# 242 "data/maps/PetalburgWoods/scripts.pory"
	step_end
# 243 "data/maps/PetalburgWoods/scripts.pory"

# 244 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_AquaEntrance:
# 245 "data/maps/PetalburgWoods/scripts.pory"
	walk_down
# 246 "data/maps/PetalburgWoods/scripts.pory"
	walk_down
# 247 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 248 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 249 "data/maps/PetalburgWoods/scripts.pory"
	step_end
# 250 "data/maps/PetalburgWoods/scripts.pory"

# 251 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_AquaApproachPlayer:
# 252 "data/maps/PetalburgWoods/scripts.pory"
	walk_down
# 253 "data/maps/PetalburgWoods/scripts.pory"
	step_end
# 254 "data/maps/PetalburgWoods/scripts.pory"

# 255 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_Boy1::
# 256 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_StayOutOfTallGrass, MSGBOX_NPC
# 257 "data/maps/PetalburgWoods/scripts.pory"
	end
# 258 "data/maps/PetalburgWoods/scripts.pory"

# 259 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_Boy2::
# 260 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_HiddenItemsExplanation, MSGBOX_NPC
# 261 "data/maps/PetalburgWoods/scripts.pory"
	end
# 262 "data/maps/PetalburgWoods/scripts.pory"

# 263 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_Girl::
# 264 "data/maps/PetalburgWoods/scripts.pory"
	lock
# 265 "data/maps/PetalburgWoods/scripts.pory"
	faceplayer
# 266 "data/maps/PetalburgWoods/scripts.pory"
	goto_if_set FLAG_RECEIVED_MIRACLE_SEED, PetalburgWoods_EventScript_ExplainMiracleSeed
# 267 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_TryUsingThisItem, MSGBOX_DEFAULT
# 268 "data/maps/PetalburgWoods/scripts.pory"
	giveitem ITEM_MIRACLE_SEED
# 269 "data/maps/PetalburgWoods/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 270 "data/maps/PetalburgWoods/scripts.pory"
	setflag FLAG_RECEIVED_MIRACLE_SEED
# 271 "data/maps/PetalburgWoods/scripts.pory"
	release
# 272 "data/maps/PetalburgWoods/scripts.pory"
	end
# 273 "data/maps/PetalburgWoods/scripts.pory"

# 274 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_ExplainMiracleSeed::
# 275 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_MiracleSeedExplanation, MSGBOX_DEFAULT
# 276 "data/maps/PetalburgWoods/scripts.pory"
	release
# 277 "data/maps/PetalburgWoods/scripts.pory"
	end
# 278 "data/maps/PetalburgWoods/scripts.pory"

# 279 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_Sign1::
# 280 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_TrainerTipsExperience, MSGBOX_SIGN
# 281 "data/maps/PetalburgWoods/scripts.pory"
	end
# 282 "data/maps/PetalburgWoods/scripts.pory"

# 283 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_Sign2::
# 284 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_TrainerTipsPP, MSGBOX_SIGN
# 285 "data/maps/PetalburgWoods/scripts.pory"
	end
# 286 "data/maps/PetalburgWoods/scripts.pory"

# 287 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_Lyle::
# 288 "data/maps/PetalburgWoods/scripts.pory"
	trainerbattle_single TRAINER_LYLE, PetalburgWoods_Text_GoBugPokemonTeam, PetalburgWoods_Text_ICouldntWin
# 289 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_ImOutOfPokeBalls, MSGBOX_AUTOCLOSE
# 290 "data/maps/PetalburgWoods/scripts.pory"
	end
# 291 "data/maps/PetalburgWoods/scripts.pory"

# 292 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_James::
# 293 "data/maps/PetalburgWoods/scripts.pory"
	trainerbattle_single TRAINER_JAMES_1, PetalburgWoods_Text_InstantlyPopularWithBugPokemon, PetalburgWoods_Text_CantBePopularIfILose, PetalburgWoods_EventScript_TryRegisterJames
# 294 "data/maps/PetalburgWoods/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 295 "data/maps/PetalburgWoods/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, PetalburgWoods_EventScript_JamesRematch
# 296 "data/maps/PetalburgWoods/scripts.pory"
	setvar VAR_0x8004, TRAINER_JAMES_1
# 297 "data/maps/PetalburgWoods/scripts.pory"
	specialvar VAR_RESULT, IsTrainerRegistered
# 298 "data/maps/PetalburgWoods/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, PetalburgWoods_EventScript_TryRegisterJames2
# 299 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_PeopleRespectYou, MSGBOX_DEFAULT
# 300 "data/maps/PetalburgWoods/scripts.pory"
	release
# 301 "data/maps/PetalburgWoods/scripts.pory"
	end
# 302 "data/maps/PetalburgWoods/scripts.pory"

# 303 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_TryRegisterJames::
# 304 "data/maps/PetalburgWoods/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 305 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 306 "data/maps/PetalburgWoods/scripts.pory"
	goto_if_set FLAG_HAS_MATCH_CALL, PetalburgWoods_EventScript_RegisterJames
# 307 "data/maps/PetalburgWoods/scripts.pory"
	release
# 308 "data/maps/PetalburgWoods/scripts.pory"
	end
# 309 "data/maps/PetalburgWoods/scripts.pory"

# 310 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_RegisterJames::
# 311 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_IWantRematch1, MSGBOX_DEFAULT
# 312 "data/maps/PetalburgWoods/scripts.pory"
	register_matchcall TRAINER_JAMES_1
# 313 "data/maps/PetalburgWoods/scripts.pory"
	release
# 314 "data/maps/PetalburgWoods/scripts.pory"
	end
# 315 "data/maps/PetalburgWoods/scripts.pory"

# 316 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_TryRegisterJames2::
# 317 "data/maps/PetalburgWoods/scripts.pory"
	goto_if_set FLAG_HAS_MATCH_CALL, PetalburgWoods_EventScript_RegisterJames2
# 318 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_PeopleRespectYou, MSGBOX_DEFAULT
# 319 "data/maps/PetalburgWoods/scripts.pory"
	release
# 320 "data/maps/PetalburgWoods/scripts.pory"
	end
# 321 "data/maps/PetalburgWoods/scripts.pory"

# 322 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_RegisterJames2::
# 323 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_IWantRematch2, MSGBOX_DEFAULT
# 324 "data/maps/PetalburgWoods/scripts.pory"
	register_matchcall TRAINER_JAMES_1
# 325 "data/maps/PetalburgWoods/scripts.pory"
	release
# 326 "data/maps/PetalburgWoods/scripts.pory"
	end
# 327 "data/maps/PetalburgWoods/scripts.pory"

# 328 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_JamesRematch::
# 329 "data/maps/PetalburgWoods/scripts.pory"
	trainerbattle_rematch TRAINER_JAMES_1, PetalburgWoods_Text_MyPokemonHaveGrown, PetalburgWoods_Text_CantBePopularIfLose
# 330 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_IveBeenTrainingHard, MSGBOX_AUTOCLOSE
# 331 "data/maps/PetalburgWoods/scripts.pory"
	end
# 332 "data/maps/PetalburgWoods/scripts.pory"

# 333 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_NotAOneToBeFound:
# 334 "data/maps/PetalburgWoods/scripts.pory"
	.string "Hmmm…\n"
# 335 "data/maps/PetalburgWoods/scripts.pory"
	.string "Not a one to be found…$"
# 336 "data/maps/PetalburgWoods/scripts.pory"

# 337 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_HaveYouSeenShroomish:
# 338 "data/maps/PetalburgWoods/scripts.pory"
	.string "Hello, have you seen any POKéMON\n"
# 339 "data/maps/PetalburgWoods/scripts.pory"
	.string "called SHROOMISH around here?\p"
# 340 "data/maps/PetalburgWoods/scripts.pory"
	.string "I really love that POKéMON.$"
# 341 "data/maps/PetalburgWoods/scripts.pory"

# 342 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_IWasGoingToAmbushYou:
# 343 "data/maps/PetalburgWoods/scripts.pory"
	.string "I was going to ambush you, but you\n"
# 344 "data/maps/PetalburgWoods/scripts.pory"
	.string "had to dawdle in PETALBURG WOODS\l"
# 345 "data/maps/PetalburgWoods/scripts.pory"
	.string "forever, didn't you?\p"
# 346 "data/maps/PetalburgWoods/scripts.pory"
	.string "I got sick of waiting, so here I am!$"
# 347 "data/maps/PetalburgWoods/scripts.pory"

# 348 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_HandOverThosePapers:
# 349 "data/maps/PetalburgWoods/scripts.pory"
	.string "You! DEVON RESEARCHER!\p"
# 350 "data/maps/PetalburgWoods/scripts.pory"
	.string "Hand over those papers!$"
# 351 "data/maps/PetalburgWoods/scripts.pory"

# 352 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_YouHaveToHelpMe:
# 353 "data/maps/PetalburgWoods/scripts.pory"
	.string "Aiyeeeh!\p"
# 354 "data/maps/PetalburgWoods/scripts.pory"
	.string "You're a POKéMON TRAINER, aren't you?\n"
# 355 "data/maps/PetalburgWoods/scripts.pory"
	.string "You've got to help me, please!$"
# 356 "data/maps/PetalburgWoods/scripts.pory"

# 357 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_NoOneCrossesTeamAqua:
# 358 "data/maps/PetalburgWoods/scripts.pory"
	.string "Hunh? What do you think you're doing?\n"
# 359 "data/maps/PetalburgWoods/scripts.pory"
	.string "What, you're going to protect him?\p"
# 360 "data/maps/PetalburgWoods/scripts.pory"
	.string "No one who crosses TEAM AQUA\n"
# 361 "data/maps/PetalburgWoods/scripts.pory"
	.string "gets any mercy, not even a kid!\p"
# 362 "data/maps/PetalburgWoods/scripts.pory"
	.string "Come on and battle me!$"
# 363 "data/maps/PetalburgWoods/scripts.pory"

# 364 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_YoureKiddingMe:
# 365 "data/maps/PetalburgWoods/scripts.pory"
	.string "You're kidding me! You're tough!$"
# 366 "data/maps/PetalburgWoods/scripts.pory"

# 367 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_YouveGotSomeNerve:
# 368 "data/maps/PetalburgWoods/scripts.pory"
	.string "Grrr… You've got some nerve\n"
# 369 "data/maps/PetalburgWoods/scripts.pory"
	.string "meddling with TEAM AQUA!\l"
# 370 "data/maps/PetalburgWoods/scripts.pory"
	.string "Come on and battle me again!\p"
# 371 "data/maps/PetalburgWoods/scripts.pory"
	.string "I wish I could say that, but I'm out of\n"
# 372 "data/maps/PetalburgWoods/scripts.pory"
	.string "POKéMON…\p"
# 373 "data/maps/PetalburgWoods/scripts.pory"
	.string "And, hey, we of TEAM AQUA are also\n"
# 374 "data/maps/PetalburgWoods/scripts.pory"
	.string "after something in RUSTBORO.\p"
# 375 "data/maps/PetalburgWoods/scripts.pory"
	.string "I'll let you go today!$"
# 376 "data/maps/PetalburgWoods/scripts.pory"

# 377 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_ThatWasAwfullyClose:
# 378 "data/maps/PetalburgWoods/scripts.pory"
	.string "Whew…\n"
# 379 "data/maps/PetalburgWoods/scripts.pory"
	.string "That was awfully close!\p"
# 380 "data/maps/PetalburgWoods/scripts.pory"
	.string "Thanks to you, he didn't rob me of\n"
# 381 "data/maps/PetalburgWoods/scripts.pory"
	.string "these important papers.\p"
# 382 "data/maps/PetalburgWoods/scripts.pory"
	.string "I know, I'll give you a GREAT BALL as\n"
# 383 "data/maps/PetalburgWoods/scripts.pory"
	.string "my thanks!$"
# 384 "data/maps/PetalburgWoods/scripts.pory"

# 385 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_TeamAquaAfterSomethingInRustboro:
# 386 "data/maps/PetalburgWoods/scripts.pory"
	.string "Didn't that TEAM AQUA thug say\n"
# 387 "data/maps/PetalburgWoods/scripts.pory"
	.string "they were after something in\l"
# 388 "data/maps/PetalburgWoods/scripts.pory"
	.string "RUSTBORO, too?$"
# 389 "data/maps/PetalburgWoods/scripts.pory"

# 390 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_ICantBeWastingTime:
# 391 "data/maps/PetalburgWoods/scripts.pory"
	.string "Uh-oh! It's a crisis!\n"
# 392 "data/maps/PetalburgWoods/scripts.pory"
	.string "I can't be wasting time!$"
# 393 "data/maps/PetalburgWoods/scripts.pory"

# 394 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_YoureLoadedWithItems:
# 395 "data/maps/PetalburgWoods/scripts.pory"
	.string "You're loaded with items.\n"
# 396 "data/maps/PetalburgWoods/scripts.pory"
	.string "I can't give you this GREAT BALL.$"
# 397 "data/maps/PetalburgWoods/scripts.pory"

# 398 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_GoBugPokemonTeam:
# 399 "data/maps/PetalburgWoods/scripts.pory"
	.string "I caught a whole bunch of POKéMON!\p"
# 400 "data/maps/PetalburgWoods/scripts.pory"
	.string "Go, go, go!\n"
# 401 "data/maps/PetalburgWoods/scripts.pory"
	.string "My BUG POKéMON team!$"
# 402 "data/maps/PetalburgWoods/scripts.pory"

# 403 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_ICouldntWin:
# 404 "data/maps/PetalburgWoods/scripts.pory"
	.string "I have all these POKéMON,\n"
# 405 "data/maps/PetalburgWoods/scripts.pory"
	.string "but I couldn't win…$"
# 406 "data/maps/PetalburgWoods/scripts.pory"

# 407 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_ImOutOfPokeBalls:
# 408 "data/maps/PetalburgWoods/scripts.pory"
	.string "I caught a bunch of POKéMON.\n"
# 409 "data/maps/PetalburgWoods/scripts.pory"
	.string "Now I'm out of POKé BALLS.$"
# 410 "data/maps/PetalburgWoods/scripts.pory"

# 411 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_InstantlyPopularWithBugPokemon:
# 412 "data/maps/PetalburgWoods/scripts.pory"
	.string "If you take BUG POKéMON to school,\n"
# 413 "data/maps/PetalburgWoods/scripts.pory"
	.string "you get to be instantly popular!$"
# 414 "data/maps/PetalburgWoods/scripts.pory"

# 415 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_CantBePopularIfILose:
# 416 "data/maps/PetalburgWoods/scripts.pory"
	.string "I can't be popular if I lose.$"
# 417 "data/maps/PetalburgWoods/scripts.pory"

# 418 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_PeopleRespectYou:
# 419 "data/maps/PetalburgWoods/scripts.pory"
	.string "If you have a big BUG POKéMON,\n"
# 420 "data/maps/PetalburgWoods/scripts.pory"
	.string "people respect you for it.$"
# 421 "data/maps/PetalburgWoods/scripts.pory"

# 422 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_IWantRematch1:
# 423 "data/maps/PetalburgWoods/scripts.pory"
	.string "I want a rematch when my BUG\n"
# 424 "data/maps/PetalburgWoods/scripts.pory"
	.string "POKéMON grow up!\p"
# 425 "data/maps/PetalburgWoods/scripts.pory"
	.string "I'm registering you in my POKéNAV!$"
# 426 "data/maps/PetalburgWoods/scripts.pory"

# 427 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_IWantRematch2:
# 428 "data/maps/PetalburgWoods/scripts.pory"
	.string "I want a rematch when my BUG \n"
# 429 "data/maps/PetalburgWoods/scripts.pory"
	.string "POKéMON grow up!\p"
# 430 "data/maps/PetalburgWoods/scripts.pory"
	.string "I'm registering you in my POKéNAV!$"
# 431 "data/maps/PetalburgWoods/scripts.pory"

# 432 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_MyPokemonHaveGrown:
# 433 "data/maps/PetalburgWoods/scripts.pory"
	.string "My BUG POKéMON have grown.\n"
# 434 "data/maps/PetalburgWoods/scripts.pory"
	.string "I'll be popular again.$"
# 435 "data/maps/PetalburgWoods/scripts.pory"

# 436 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_CantBePopularIfLose:
# 437 "data/maps/PetalburgWoods/scripts.pory"
	.string "I can't be popular if I lose.$"
# 438 "data/maps/PetalburgWoods/scripts.pory"

# 439 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_IveBeenTrainingHard:
# 440 "data/maps/PetalburgWoods/scripts.pory"
	.string "You get to be popular if you have\n"
# 441 "data/maps/PetalburgWoods/scripts.pory"
	.string "strong POKéMON, right?\l"
# 442 "data/maps/PetalburgWoods/scripts.pory"
	.string "So, I've been training hard.$"
# 443 "data/maps/PetalburgWoods/scripts.pory"

# 444 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_StayOutOfTallGrass:
# 445 "data/maps/PetalburgWoods/scripts.pory"
	.string "Yo, there!\n"
# 446 "data/maps/PetalburgWoods/scripts.pory"
	.string "Your POKéMON doing okay?\p"
# 447 "data/maps/PetalburgWoods/scripts.pory"
	.string "If your POKéMON are weak and you want\n"
# 448 "data/maps/PetalburgWoods/scripts.pory"
	.string "to avoid battles, you should stay out\l"
# 449 "data/maps/PetalburgWoods/scripts.pory"
	.string "of tall grass.$"
# 450 "data/maps/PetalburgWoods/scripts.pory"

# 451 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_HiddenItemsExplanation:
# 452 "data/maps/PetalburgWoods/scripts.pory"
	.string "Sometimes, there are things on the\n"
# 453 "data/maps/PetalburgWoods/scripts.pory"
	.string "ground even if you can't see them.\p"
# 454 "data/maps/PetalburgWoods/scripts.pory"
	.string "That's why I always check where I'm\n"
# 455 "data/maps/PetalburgWoods/scripts.pory"
	.string "walking.$"
# 456 "data/maps/PetalburgWoods/scripts.pory"

# 457 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_TryUsingThisItem:
# 458 "data/maps/PetalburgWoods/scripts.pory"
	.string "Oh, neat!\n"
# 459 "data/maps/PetalburgWoods/scripts.pory"
	.string "That's the BADGE from RUSTBORO GYM!\p"
# 460 "data/maps/PetalburgWoods/scripts.pory"
	.string "You must be a TRAINER.\n"
# 461 "data/maps/PetalburgWoods/scripts.pory"
	.string "You should try using this item.$"
# 462 "data/maps/PetalburgWoods/scripts.pory"

# 463 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_MiracleSeedExplanation:
# 464 "data/maps/PetalburgWoods/scripts.pory"
	.string "It's a MIRACLE SEED.\n"
# 465 "data/maps/PetalburgWoods/scripts.pory"
	.string "If a POKéMON holds that item, its\l"
# 466 "data/maps/PetalburgWoods/scripts.pory"
	.string "GRASS-type moves become stronger.\p"
# 467 "data/maps/PetalburgWoods/scripts.pory"
	.string "Besides MIRACLE SEED, I think there are\n"
# 468 "data/maps/PetalburgWoods/scripts.pory"
	.string "other convenient items for POKéMON\l"
# 469 "data/maps/PetalburgWoods/scripts.pory"
	.string "to hold.$"
# 470 "data/maps/PetalburgWoods/scripts.pory"

# 471 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_TrainerTipsExperience:
# 472 "data/maps/PetalburgWoods/scripts.pory"
	.string "TRAINER TIPS\p"
# 473 "data/maps/PetalburgWoods/scripts.pory"
	.string "Any POKéMON that appears even once\n"
# 474 "data/maps/PetalburgWoods/scripts.pory"
	.string "in a battle is awarded EXP Points.\p"
# 475 "data/maps/PetalburgWoods/scripts.pory"
	.string "To raise a weak POKéMON, put it at the\n"
# 476 "data/maps/PetalburgWoods/scripts.pory"
	.string "left of the team list.\p"
# 477 "data/maps/PetalburgWoods/scripts.pory"
	.string "As soon as a battle starts, switch it\n"
# 478 "data/maps/PetalburgWoods/scripts.pory"
	.string "out. It will earn EXP Points without\l"
# 479 "data/maps/PetalburgWoods/scripts.pory"
	.string "being exposed to any harm.$"
# 480 "data/maps/PetalburgWoods/scripts.pory"

# 481 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_TrainerTipsPP:
# 482 "data/maps/PetalburgWoods/scripts.pory"
	.string "TRAINER TIPS\p"
# 483 "data/maps/PetalburgWoods/scripts.pory"
	.string "In addition to Hit Points (HP), POKéMON\n"
# 484 "data/maps/PetalburgWoods/scripts.pory"
	.string "have Power Points (PP) that are used to\l"
# 485 "data/maps/PetalburgWoods/scripts.pory"
	.string "make moves during battle.\p"
# 486 "data/maps/PetalburgWoods/scripts.pory"
	.string "If a POKéMON runs out of PP, it must be\n"
# 487 "data/maps/PetalburgWoods/scripts.pory"
	.string "taken to a POKéMON CENTER.$"
# 488 "data/maps/PetalburgWoods/scripts.pory"

# 489 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_Celebi::
# 490 "data/maps/PetalburgWoods/scripts.pory"
    lock
# 491 "data/maps/PetalburgWoods/scripts.pory"
    faceplayer
# 492 "data/maps/PetalburgWoods/scripts.pory"
    waitse
# 493 "data/maps/PetalburgWoods/scripts.pory"
    playmoncry SPECIES_CELEBI, CRY_MODE_ENCOUNTER
# 494 "data/maps/PetalburgWoods/scripts.pory"
    delay 40
# 495 "data/maps/PetalburgWoods/scripts.pory"
    waitmoncry
# 496 "data/maps/PetalburgWoods/scripts.pory"
    setwildbattle SPECIES_CELEBI, 30
# 497 "data/maps/PetalburgWoods/scripts.pory"
    setflag FLAG_SYS_CTRL_OBJ_DELETE
# 498 "data/maps/PetalburgWoods/scripts.pory"
    special BattleSetup_StartLegendaryBattle
# 499 "data/maps/PetalburgWoods/scripts.pory"
    waitstate
# 500 "data/maps/PetalburgWoods/scripts.pory"
    clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 501 "data/maps/PetalburgWoods/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 502 "data/maps/PetalburgWoods/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_WON, PetalburgWoods_EventScript_DefeatedCelebi
# 503 "data/maps/PetalburgWoods/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_RAN, PetalburgWoods_EventScript_RanFromCelebi
# 504 "data/maps/PetalburgWoods/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, PetalburgWoods_EventScript_RanFromCelebi
# 505 "data/maps/PetalburgWoods/scripts.pory"
    setflag FLAG_DEFEATED_CELEBI
# 506 "data/maps/PetalburgWoods/scripts.pory"
    release
# 507 "data/maps/PetalburgWoods/scripts.pory"
    end
# 508 "data/maps/PetalburgWoods/scripts.pory"

# 509 "data/maps/PetalburgWoods/scripts.pory"

# 510 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_DefeatedCelebi::
# 511 "data/maps/PetalburgWoods/scripts.pory"
    setflag FLAG_DEFEATED_CELEBI
# 512 "data/maps/PetalburgWoods/scripts.pory"
    goto Common_EventScript_RemoveStaticPokemon
# 513 "data/maps/PetalburgWoods/scripts.pory"
    end
# 514 "data/maps/PetalburgWoods/scripts.pory"

# 515 "data/maps/PetalburgWoods/scripts.pory"

# 516 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_RanFromCelebi::
# 517 "data/maps/PetalburgWoods/scripts.pory"
    setvar VAR_0x8004, SPECIES_CELEBI
# 518 "data/maps/PetalburgWoods/scripts.pory"
    goto Common_EventScript_LegendaryFlewAway
# 519 "data/maps/PetalburgWoods/scripts.pory"
    end
