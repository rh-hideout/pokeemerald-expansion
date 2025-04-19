# 1 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 2 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
.set LOCALID_LASS, 1
# 3 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
.set LOCALID_MAN, 2
# 4 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
.set LOCALID_POKEFAN_M, 3
# 5 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
.set LOCALID_LITTLE_GIRL, 4
# 6 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
.set LOCALID_NINJA_BOY, 5
# 7 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
.set LOCALID_BOY, 6
# 8 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
.set LOCALID_WOMAN, 7
# 9 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
.set LOCALID_EXPERT_F, 8
# 10 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 11 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_MapScripts::
# 12 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LilycoveCity_PokemonTrainerFanClub_OnFrame
# 13 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_PokemonTrainerFanClub_OnTransition
# 14 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.byte 0
# 15 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 16 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	@ See field_specials.c for a breakdown of the Fan Club and its variables
# 17 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 18 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_OnFrame:
# 19 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	map_script_2 VAR_LILYCOVE_FAN_CLUB_STATE, 1, LilycoveCity_PokemonTrainerFanClub_EventScript_MeetFirstFans
# 20 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.2byte 0
# 21 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 22 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_EventScript_MeetFirstFans::
# 23 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	lockall
# 24 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	applymovement LOCALID_LASS, Common_Movement_WalkInPlaceFasterDown
# 25 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	waitmovement 0
# 26 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_OhWowItsPlayer, MSGBOX_DEFAULT
# 27 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	applymovement LOCALID_LITTLE_GIRL, LilycoveCity_PokemonTrainerFanClub_Movement_LittleGirlWatchPlayer
# 28 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	applymovement LOCALID_MAN, LilycoveCity_PokemonTrainerFanClub_Movement_FanApproachPlayer
# 29 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	waitmovement 0
# 30 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 31 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	waitmovement 0
# 32 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_HeardAboutYouImYourFan, MSGBOX_DEFAULT
# 33 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	applymovement LOCALID_LITTLE_GIRL, LilycoveCity_PokemonTrainerFanClub_Movement_LittleGirlMoveCloserToPlayer
# 34 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	waitmovement 0
# 35 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 36 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	waitmovement 0
# 37 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	applymovement LOCALID_LITTLE_GIRL, LilycoveCity_PokemonTrainerFanClub_Movement_LittleGirlHideFromPlayer
# 38 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	waitmovement 0
# 39 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	setvar VAR_LILYCOVE_FAN_CLUB_STATE, 2
# 40 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	releaseall
# 41 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	end
# 42 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 43 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_Movement_FanApproachPlayer:
# 44 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	delay_8
# 45 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	walk_in_place_faster_down
# 46 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	walk_down
# 47 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	walk_down
# 48 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	walk_down
# 49 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	walk_left
# 50 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	walk_left
# 51 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	step_end
# 52 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 53 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_Movement_LittleGirlWatchPlayer:
# 54 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	walk_fast_left
# 55 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	walk_fast_left
# 56 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	walk_fast_down
# 57 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	walk_fast_down
# 58 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	walk_fast_left
# 59 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	walk_fast_down
# 60 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	step_end
# 61 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 62 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_Movement_LittleGirlMoveCloserToPlayer:
# 63 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	walk_down
# 64 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	walk_in_place_faster_right
# 65 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	step_end
# 66 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 67 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_Movement_LittleGirlHideFromPlayer:
# 68 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	jump_in_place_right
# 69 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	walk_fast_up
# 70 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	walk_fast_up
# 71 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	walk_fast_right
# 72 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	walk_in_place_faster_down
# 73 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	step_end
# 74 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 75 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_OnTransition:
# 76 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	call LilycoveCity_PokemonTrainerFanClub_EventScript_HideOrShowInterviewer
# 77 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	goto_if_eq VAR_LILYCOVE_FAN_CLUB_STATE, 1, LilycoveCity_PokemonTrainerFanClub_EventScript_SetFanMemberPositionsForFirstFanMeeting
# 78 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	goto_if_eq VAR_LILYCOVE_FAN_CLUB_STATE, 2, LilycoveCity_PokemonTrainerFanClub_EventScript_UpdateFanMemberPositions
# 79 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	end
# 80 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 81 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_EventScript_UpdateFanMemberPositions::
# 82 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	special TryLoseFansFromPlayTime
# 83 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	call LilycoveCity_PokemonTrainerFanClub_EventScript_CheckSetUpTVShow
# 84 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	setvar VAR_0x8004, FANCLUB_MEMBER1
# 85 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
# 86 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember1ToFarTable
# 87 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	setvar VAR_0x8004, FANCLUB_MEMBER2
# 88 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
# 89 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember2ToFarTable
# 90 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	setvar VAR_0x8004, FANCLUB_MEMBER3
# 91 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
# 92 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember3ToFarTable
# 93 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	setvar VAR_0x8004, FANCLUB_MEMBER4
# 94 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
# 95 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember4ToFarTable
# 96 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	setvar VAR_0x8004, FANCLUB_MEMBER5
# 97 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
# 98 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember5ToFarTable
# 99 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	setvar VAR_0x8004, FANCLUB_MEMBER6
# 100 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
# 101 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember6ToFarTable
# 102 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	setvar VAR_0x8004, FANCLUB_MEMBER7
# 103 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
# 104 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember7ToFarTable
# 105 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	setvar VAR_0x8004, FANCLUB_MEMBER8
# 106 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
# 107 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember8ToFarTable
# 108 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	end
# 109 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 110 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_EventScript_HideOrShowInterviewer::
# 111 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	specialvar VAR_RESULT, ShouldHideFanClubInterviewer
# 112 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_PokemonTrainerFanClub_EventScript_HideInterviewer
# 113 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	clearflag FLAG_HIDE_LILYCOVE_FAN_CLUB_INTERVIEWER
# 114 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	clearflag FLAG_FAN_CLUB_STRENGTH_SHARED
# 115 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	return
# 116 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 117 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_EventScript_HideInterviewer::
# 118 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	setflag FLAG_HIDE_LILYCOVE_FAN_CLUB_INTERVIEWER
# 119 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	return
# 120 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 121 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
@ Set up the fan club TV show, if the player has at least 5 fans in the club
# 122 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
@ Rather than counting up, 1 is subtracted from the total for each member not a fan of the players
# 123 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_EventScript_CheckSetUpTVShow::
# 124 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	setvar VAR_0x8005, NUM_TRAINER_FAN_CLUB_MEMBERS
# 125 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	setvar VAR_0x8004, FANCLUB_MEMBER1
# 126 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
# 127 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonTrainerFanClub_EventScript_CountNotPlayersFan
# 128 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	setvar VAR_0x8004, FANCLUB_MEMBER2
# 129 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
# 130 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonTrainerFanClub_EventScript_CountNotPlayersFan
# 131 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	setvar VAR_0x8004, FANCLUB_MEMBER3
# 132 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
# 133 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonTrainerFanClub_EventScript_CountNotPlayersFan
# 134 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	setvar VAR_0x8004, FANCLUB_MEMBER4
# 135 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
# 136 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonTrainerFanClub_EventScript_CountNotPlayersFan
# 137 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	setvar VAR_0x8004, FANCLUB_MEMBER5
# 138 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
# 139 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonTrainerFanClub_EventScript_CountNotPlayersFan
# 140 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	setvar VAR_0x8004, FANCLUB_MEMBER6
# 141 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
# 142 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonTrainerFanClub_EventScript_CountNotPlayersFan
# 143 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	setvar VAR_0x8004, FANCLUB_MEMBER7
# 144 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
# 145 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonTrainerFanClub_EventScript_CountNotPlayersFan
# 146 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	setvar VAR_0x8004, FANCLUB_MEMBER8
# 147 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
# 148 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonTrainerFanClub_EventScript_CountNotPlayersFan
# 149 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	goto_if_ge VAR_0x8005, 5, LilycoveCity_PokemonTrainerFanClub_EventScript_TrySetUpTVShow
# 150 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	return
# 151 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 152 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_EventScript_CountNotPlayersFan::
# 153 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	subvar VAR_0x8005, 1
# 154 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	return
# 155 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 156 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_EventScript_TrySetUpTVShow::
# 157 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	special TryPutTrainerFanClubOnAir
# 158 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	return
# 159 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 160 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember1ToFarTable::
# 161 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	setobjectxyperm LOCALID_LASS, 7, 5
# 162 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	return
# 163 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 164 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember2ToFarTable::
# 165 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	setobjectxyperm LOCALID_POKEFAN_M, 3, 4
# 166 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	return
# 167 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 168 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember3ToFarTable::
# 169 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	setobjectxyperm LOCALID_LITTLE_GIRL, 7, 2
# 170 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	return
# 171 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 172 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember4ToFarTable::
# 173 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	setobjectxyperm LOCALID_NINJA_BOY, 5, 5
# 174 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	return
# 175 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 176 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember5ToFarTable::
# 177 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	setobjectxyperm LOCALID_BOY, 5, 2
# 178 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	return
# 179 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 180 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember6ToFarTable::
# 181 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	setobjectxyperm LOCALID_MAN, 8, 4
# 182 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	return
# 183 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 184 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember7ToFarTable::
# 185 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	setobjectxyperm LOCALID_WOMAN, 3, 3
# 186 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	return
# 187 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 188 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember8ToFarTable::
# 189 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	setobjectxyperm LOCALID_EXPERT_F, 8, 3
# 190 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	return
# 191 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 192 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_EventScript_SetFanMemberPositionsForFirstFanMeeting::
# 193 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	call LilycoveCity_PokemonTrainerFanClub_EventScript_CheckSetUpTVShow
# 194 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	call LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember2ToFarTable
# 195 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	call LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember4ToFarTable
# 196 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	call LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember5ToFarTable
# 197 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	call LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember7ToFarTable
# 198 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	call LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember8ToFarTable
# 199 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	end
# 200 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 201 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_EventScript_Man::
# 202 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	lock
# 203 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	faceplayer
# 204 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	setvar VAR_0x8004, FANCLUB_MEMBER6
# 205 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	special BufferFanClubTrainerName
# 206 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	goto_if_eq VAR_LILYCOVE_FAN_CLUB_STATE, 0, LilycoveCity_PokemonTrainerFanClub_EventScript_ManPlayerNotChampion
# 207 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
# 208 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_PokemonTrainerFanClub_EventScript_ManPlayersFan
# 209 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
# 210 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	goto_if_eq VAR_RESULT, (NUM_TRAINER_FAN_CLUB_MEMBERS - 1), LilycoveCity_PokemonTrainerFanClub_EventScript_ManOnlyNonFan
# 211 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_TrainersPowerIsOutOfTheOrdinary, MSGBOX_DEFAULT
# 212 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	release
# 213 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	end
# 214 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 215 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_EventScript_ManPlayersFan::
# 216 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
# 217 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	goto_if_eq VAR_RESULT, 1, LilycoveCity_PokemonTrainerFanClub_EventScript_ManOnlyFan
# 218 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_YoureOneWeWantToWin, MSGBOX_DEFAULT
# 219 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	release
# 220 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	end
# 221 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 222 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_EventScript_ManOnlyFan::
# 223 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_OthersDontKnowYoureTheBest, MSGBOX_DEFAULT
# 224 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	release
# 225 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	end
# 226 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 227 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_EventScript_ManOnlyNonFan::
# 228 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_TrainerIsBestNoOneWantsToListen, MSGBOX_DEFAULT
# 229 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	release
# 230 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	end
# 231 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 232 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_EventScript_ManPlayerNotChampion::
# 233 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_HearingAboutToughNewTrainer, MSGBOX_DEFAULT
# 234 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	release
# 235 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	end
# 236 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 237 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_EventScript_Lass::
# 238 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	lock
# 239 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	faceplayer
# 240 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	setvar VAR_0x8004, FANCLUB_MEMBER1
# 241 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	special BufferFanClubTrainerName
# 242 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	goto_if_eq VAR_LILYCOVE_FAN_CLUB_STATE, 0, LilycoveCity_PokemonTrainerFanClub_EventScript_LassPlayerNotChampion
# 243 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
# 244 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_PokemonTrainerFanClub_EventScript_LassPlayersFan
# 245 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
# 246 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	goto_if_eq VAR_RESULT, (NUM_TRAINER_FAN_CLUB_MEMBERS - 1), LilycoveCity_PokemonTrainerFanClub_EventScript_LassOnlyNonFan
# 247 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_ICantHelpLikingBrawly, MSGBOX_DEFAULT
# 248 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	release
# 249 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	end
# 250 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 251 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_EventScript_LassPlayersFan::
# 252 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
# 253 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	goto_if_eq VAR_RESULT, 1, LilycoveCity_PokemonTrainerFanClub_EventScript_LassOnlyFan
# 254 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_ImPullingForYou, MSGBOX_DEFAULT
# 255 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	release
# 256 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	end
# 257 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 258 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_EventScript_LassOnlyFan::
# 259 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_BrawlyNoImYourFan, MSGBOX_DEFAULT
# 260 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	release
# 261 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	end
# 262 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 263 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_EventScript_LassOnlyNonFan::
# 264 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_NobodyUnderstandsBrawly, MSGBOX_DEFAULT
# 265 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	release
# 266 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	end
# 267 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 268 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_EventScript_LassPlayerNotChampion::
# 269 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_MyFavoriteTrainerIsBrawly, MSGBOX_DEFAULT
# 270 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	release
# 271 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	end
# 272 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 273 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_EventScript_PokefanM::
# 274 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	lock
# 275 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	faceplayer
# 276 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	setvar VAR_0x8004, FANCLUB_MEMBER2
# 277 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	special BufferFanClubTrainerName
# 278 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	goto_if_eq VAR_LILYCOVE_FAN_CLUB_STATE, 0, LilycoveCity_PokemonTrainerFanClub_EventScript_PokefanMPlayerNotChampion
# 279 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
# 280 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_PokemonTrainerFanClub_EventScript_PokefanMPlayersFan
# 281 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
# 282 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	goto_if_eq VAR_RESULT, (NUM_TRAINER_FAN_CLUB_MEMBERS - 1), LilycoveCity_PokemonTrainerFanClub_EventScript_PokefanMOnlyNonFan
# 283 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_LongWayToGoComparedToNorman, MSGBOX_DEFAULT
# 284 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	release
# 285 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	end
# 286 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 287 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_EventScript_PokefanMPlayersFan::
# 288 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
# 289 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	goto_if_eq VAR_RESULT, 1, LilycoveCity_PokemonTrainerFanClub_EventScript_PokefanMOnlyFan
# 290 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_YouveSurpassedYourFather, MSGBOX_DEFAULT
# 291 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	release
# 292 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	end
# 293 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 294 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_EventScript_PokefanMOnlyFan::
# 295 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_YourFatherNeverGaveUpSoKeepOnBattling, MSGBOX_DEFAULT
# 296 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	release
# 297 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	end
# 298 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 299 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_EventScript_PokefanMOnlyNonFan::
# 300 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_YouAndNormanAreDifferent, MSGBOX_DEFAULT
# 301 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	release
# 302 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	end
# 303 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 304 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_EventScript_PokefanMPlayerNotChampion::
# 305 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_WeDiscussStrongestTrainers, MSGBOX_DEFAULT
# 306 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	release
# 307 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	end
# 308 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 309 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_EventScript_LittleGirl::
# 310 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	lock
# 311 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	faceplayer
# 312 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	setvar VAR_0x8004, FANCLUB_MEMBER3
# 313 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	special BufferFanClubTrainerName
# 314 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	goto_if_eq VAR_LILYCOVE_FAN_CLUB_STATE, 0, LilycoveCity_PokemonTrainerFanClub_EventScript_LittleGirlPlayerNotChampion
# 315 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
# 316 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_PokemonTrainerFanClub_EventScript_LittleGirlPlayersFan
# 317 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
# 318 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	goto_if_eq VAR_RESULT, (NUM_TRAINER_FAN_CLUB_MEMBERS - 1), LilycoveCity_PokemonTrainerFanClub_EventScript_LittleGirlOnlyNonFan
# 319 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_EveryoneThinksTrainerIsCool, MSGBOX_DEFAULT
# 320 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	release
# 321 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	end
# 322 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 323 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_EventScript_LittleGirlPlayersFan::
# 324 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
# 325 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	goto_if_eq VAR_RESULT, 1, LilycoveCity_PokemonTrainerFanClub_EventScript_LittleGirlOnlyFan
# 326 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_OhWoweeItsPlayer, MSGBOX_DEFAULT
# 327 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	release
# 328 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	end
# 329 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 330 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_EventScript_LittleGirlOnlyFan::
# 331 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_AlwaysCheerForYou, MSGBOX_DEFAULT
# 332 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	release
# 333 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	end
# 334 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 335 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_EventScript_LittleGirlOnlyNonFan::
# 336 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_TrainerIsReallyCoolItsJustMe, MSGBOX_DEFAULT
# 337 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	release
# 338 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	end
# 339 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 340 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_EventScript_LittleGirlPlayerNotChampion::
# 341 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_WishThereWasTrainerLikeThat, MSGBOX_DEFAULT
# 342 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	release
# 343 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	end
# 344 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 345 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_EventScript_NinjaBoy::
# 346 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	lock
# 347 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	faceplayer
# 348 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	setvar VAR_0x8004, FANCLUB_MEMBER4
# 349 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	special BufferFanClubTrainerName
# 350 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
# 351 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_PokemonTrainerFanClub_EventScript_NinjaBoyPlayersFan
# 352 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
# 353 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	goto_if_eq VAR_RESULT, (NUM_TRAINER_FAN_CLUB_MEMBERS - 1), LilycoveCity_PokemonTrainerFanClub_EventScript_NinjaBoyOnlyNonFan
# 354 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_TrainerIsWickedlyCool, MSGBOX_DEFAULT
# 355 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	release
# 356 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	end
# 357 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 358 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_EventScript_NinjaBoyPlayersFan::
# 359 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
# 360 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	goto_if_eq VAR_RESULT, 1, LilycoveCity_PokemonTrainerFanClub_EventScript_NinjaBoyOnlyFan
# 361 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_WantToBeStrongLikeYou, MSGBOX_DEFAULT
# 362 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	release
# 363 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	end
# 364 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 365 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_EventScript_NinjaBoyOnlyFan::
# 366 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_OnlyOneWhoCheersForYou, MSGBOX_DEFAULT
# 367 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	release
# 368 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	end
# 369 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 370 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_EventScript_NinjaBoyOnlyNonFan::
# 371 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_NeverGoingToStopBeingTrainersFan, MSGBOX_DEFAULT
# 372 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	release
# 373 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	end
# 374 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 375 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_EventScript_Boy::
# 376 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	lock
# 377 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	faceplayer
# 378 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	setvar VAR_0x8004, FANCLUB_MEMBER5
# 379 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	special BufferFanClubTrainerName
# 380 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
# 381 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_PokemonTrainerFanClub_EventScript_BoyPlayersFan
# 382 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
# 383 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	goto_if_eq VAR_RESULT, (NUM_TRAINER_FAN_CLUB_MEMBERS - 1), LilycoveCity_PokemonTrainerFanClub_EventScript_BoyOnlyNonFan
# 384 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_ThinkTrainerIsNumberOne, MSGBOX_DEFAULT
# 385 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	release
# 386 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	end
# 387 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 388 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_EventScript_BoyPlayersFan::
# 389 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
# 390 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	goto_if_eq VAR_RESULT, 1, LilycoveCity_PokemonTrainerFanClub_EventScript_BoyOnlyFan
# 391 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_YoureAmazingAfterAll, MSGBOX_DEFAULT
# 392 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	release
# 393 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	end
# 394 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 395 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_EventScript_BoyOnlyFan::
# 396 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_ImInYourCorner, MSGBOX_DEFAULT
# 397 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	release
# 398 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	end
# 399 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 400 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_EventScript_BoyOnlyNonFan::
# 401 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_YoureMaybeStrongerThanTrainer, MSGBOX_DEFAULT
# 402 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	release
# 403 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	end
# 404 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 405 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_EventScript_Woman::
# 406 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	lock
# 407 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	faceplayer
# 408 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	setvar VAR_0x8004, FANCLUB_MEMBER7
# 409 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	special BufferFanClubTrainerName
# 410 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
# 411 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_PokemonTrainerFanClub_EventScript_WomanPlayersFan
# 412 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
# 413 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	goto_if_eq VAR_RESULT, (NUM_TRAINER_FAN_CLUB_MEMBERS - 1), LilycoveCity_PokemonTrainerFanClub_EventScript_WomanOnlyNonFan
# 414 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_TrainerIsStandout, MSGBOX_DEFAULT
# 415 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	release
# 416 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	end
# 417 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 418 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_EventScript_WomanPlayersFan::
# 419 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
# 420 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	goto_if_eq VAR_RESULT, 1, LilycoveCity_PokemonTrainerFanClub_EventScript_WomanOnlyFan
# 421 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_YouChangedMyMind, MSGBOX_DEFAULT
# 422 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	release
# 423 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	end
# 424 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 425 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_EventScript_WomanOnlyFan::
# 426 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_YouBattleAttractivelyInToughSituation, MSGBOX_DEFAULT
# 427 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	release
# 428 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	end
# 429 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 430 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_EventScript_WomanOnlyNonFan::
# 431 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_NoOneCanKnockYouButTrainerStronger, MSGBOX_DEFAULT
# 432 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	release
# 433 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	end
# 434 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 435 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_EventScript_ExpertF::
# 436 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	lock
# 437 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	faceplayer
# 438 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	setvar VAR_0x8004, FANCLUB_MEMBER8
# 439 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	special BufferFanClubTrainerName
# 440 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
# 441 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_PokemonTrainerFanClub_EventScript_ExpertFPlayersFan
# 442 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
# 443 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	goto_if_eq VAR_RESULT, (NUM_TRAINER_FAN_CLUB_MEMBERS - 1), LilycoveCity_PokemonTrainerFanClub_EventScript_ExpertFOnlyNonFan
# 444 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_HaventRealizedPotential, MSGBOX_DEFAULT
# 445 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	release
# 446 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	end
# 447 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 448 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_EventScript_ExpertFPlayersFan::
# 449 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
# 450 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	goto_if_eq VAR_RESULT, 1, LilycoveCity_PokemonTrainerFanClub_EventScript_ExpertFOnlyFan
# 451 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_YouImpressive, MSGBOX_DEFAULT
# 452 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	release
# 453 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	end
# 454 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 455 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_EventScript_ExpertFOnlyFan::
# 456 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_OnlyIRecognizeYourTrueWorth, MSGBOX_DEFAULT
# 457 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	release
# 458 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	end
# 459 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 460 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_EventScript_ExpertFOnlyNonFan::
# 461 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_YourePowerfulButNotTrueStrength, MSGBOX_DEFAULT
# 462 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	release
# 463 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	end
# 464 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 465 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_EventScript_Interviewer::
# 466 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	lock
# 467 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	faceplayer
# 468 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	goto_if_set FLAG_FAN_CLUB_STRENGTH_SHARED, LilycoveCity_PokemonTrainerFanClub_EventScript_AlreadyInterviewed
# 469 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	goto_if_unset FLAG_FAN_CLUB_STRENGTH_SHARED, LilycoveCity_PokemonTrainerFanClub_EventScript_Interview
# 470 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	end
# 471 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 472 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
@ The interviewer doesnt count as an individual fan club member
# 473 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
@ Instead they always ask about whoever the Lass would be interested in, if not the player
# 474 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_EventScript_Interview::
# 475 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	setvar VAR_0x8005, TVSHOW_FAN_CLUB_SPECIAL
# 476 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	special InterviewBefore
# 477 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_PokemonTrainerFanClub_EventScript_AlreadyInterviewed2
# 478 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	copyvar VAR_0x800A, VAR_0x8006
# 479 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	setvar VAR_0x8004, FANCLUB_MEMBER1
# 480 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	special BufferFanClubTrainerName
# 481 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_WhatsYourOpinionOfTrainer, MSGBOX_DEFAULT
# 482 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	setvar VAR_0x8004, EASY_CHAT_TYPE_FAN_QUESTION
# 483 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	copyvar VAR_0x8005, VAR_0x800A
# 484 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	call Common_ShowEasyChatScreen
# 485 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	lock
# 486 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	faceplayer
# 487 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	goto_if_eq VAR_RESULT, 1, LilycoveCity_PokemonTrainerFanClub_EventScript_SubmitOpinion
# 488 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	goto_if_eq VAR_RESULT, 0, LilycoveCity_PokemonTrainerFanClub_EventScript_CancelGiveOpinion
# 489 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	end
# 490 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 491 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_EventScript_SubmitOpinion::
# 492 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_ThatsWhatYouThink, MSGBOX_DEFAULT
# 493 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	goto LilycoveCity_PokemonTrainerFanClub_EventScript_RateTrainer
# 494 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	end
# 495 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 496 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_EventScript_CancelGiveOpinion::
# 497 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	setvar VAR_0x8004, FANCLUB_MEMBER1
# 498 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	special BufferFanClubTrainerName
# 499 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_HaveYouForgottenTrainer, MSGBOX_YESNO
# 500 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	goto_if_eq VAR_RESULT, YES, LilycoveCity_PokemonTrainerFanClub_EventScript_ForgetTrainer
# 501 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	goto_if_eq VAR_RESULT, NO, LilycoveCity_PokemonTrainerFanClub_EventScript_AskForOpinion
# 502 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	end
# 503 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 504 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_EventScript_AskForOpinion::
# 505 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	setvar VAR_0x8004, FANCLUB_MEMBER1
# 506 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	special BufferFanClubTrainerName
# 507 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_WhatsYourOpinionOfTrainer2, MSGBOX_DEFAULT
# 508 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	setvar VAR_0x8004, EASY_CHAT_TYPE_FAN_QUESTION
# 509 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	copyvar VAR_0x8005, VAR_0x800A
# 510 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	call Common_ShowEasyChatScreen
# 511 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	lock
# 512 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	faceplayer
# 513 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	goto_if_eq VAR_RESULT, 1, LilycoveCity_PokemonTrainerFanClub_EventScript_SubmitOpinion
# 514 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	goto_if_eq VAR_RESULT, 0, LilycoveCity_PokemonTrainerFanClub_EventScript_CancelGiveOpinion
# 515 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	end
# 516 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 517 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_EventScript_RateTrainer::
# 518 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	setvar VAR_0x8004, FANCLUB_MEMBER1
# 519 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	special BufferFanClubTrainerName
# 520 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	message LilycoveCity_PokemonTrainerFanClub_Text_HowStrongRateTrainer
# 521 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	waitmessage
# 522 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	setvar VAR_0x8004, SCROLL_MULTI_POKEMON_FAN_CLUB_RATER
# 523 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	special ShowScrollableMultichoice
# 524 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	waitstate
# 525 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	setvar VAR_0x8004, FANCLUB_MEMBER1
# 526 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	switch VAR_RESULT
# 527 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	case 11, LilycoveCity_PokemonTrainerFanClub_EventScript_CancelRateTrainer
# 528 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	case MULTI_B_PRESSED, LilycoveCity_PokemonTrainerFanClub_EventScript_CancelRateTrainer
# 529 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	setvar VAR_0x8004, FANCLUB_MEMBER1
# 530 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	special BufferFanClubTrainerName
# 531 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	copyvar VAR_0x8006, VAR_0x800A
# 532 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	copyvar VAR_0x8005, VAR_RESULT
# 533 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	special PutFanClubSpecialOnTheAir
# 534 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	goto LilycoveCity_PokemonTrainerFanClub_EventScript_CompleteInterview
# 535 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	end
# 536 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 537 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_EventScript_CancelRateTrainer::
# 538 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	setvar VAR_0x8004, FANCLUB_MEMBER1
# 539 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	special BufferFanClubTrainerName
# 540 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_HaveYouForgottenTrainer2, MSGBOX_YESNO
# 541 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	goto_if_eq VAR_RESULT, YES, LilycoveCity_PokemonTrainerFanClub_EventScript_ForgetTrainer
# 542 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	goto_if_eq VAR_RESULT, NO, LilycoveCity_PokemonTrainerFanClub_EventScript_RateTrainer
# 543 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	end
# 544 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 545 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_EventScript_ForgetTrainer::
# 546 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	setvar VAR_0x8004, FANCLUB_MEMBER1
# 547 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	special BufferFanClubTrainerName
# 548 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_YouShouldMeetTrainer, MSGBOX_DEFAULT
# 549 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	release
# 550 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	end
# 551 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 552 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_EventScript_CompleteInterview::
# 553 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	setvar VAR_0x8004, FANCLUB_MEMBER1
# 554 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	special BufferFanClubTrainerName
# 555 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_ThankYouIllShareThisInfo, MSGBOX_DEFAULT
# 556 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	setflag FLAG_FAN_CLUB_STRENGTH_SHARED
# 557 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	release
# 558 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	end
# 559 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 560 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_EventScript_AlreadyInterviewed::
# 561 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	setvar VAR_0x8004, FANCLUB_MEMBER1
# 562 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	special BufferFanClubTrainerName
# 563 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	msgbox LilycoveCity_PokemonTrainerFanClub_HopeYouCatchTVSpecial, MSGBOX_DEFAULT
# 564 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	release
# 565 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	end
# 566 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 567 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
@ Shouldnt be reached
# 568 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_EventScript_AlreadyInterviewed2::
# 569 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	end
# 570 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 571 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_Text_OhWowItsPlayer:
# 572 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "Oh, wow!\n"
# 573 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "It's {PLAYER}!$"
# 574 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 575 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_Text_HeardAboutYouImYourFan:
# 576 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "I've heard the news!\n"
# 577 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "You're really strong, aren't you?\p"
# 578 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "We always argue about who is the\n"
# 579 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "strongest of all TRAINERS here.\p"
# 580 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "So when I heard about you, I decided\n"
# 581 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "to be your fan!\p"
# 582 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "I hope you'll keep on battling other\n"
# 583 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "tough TRAINERS.\p"
# 584 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "That way, we'll be able to see more\n"
# 585 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "of your hot, hot battles.\p"
# 586 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "That will make the others here see\n"
# 587 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "exactly how great you are.\p"
# 588 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "Remember, I'm cheering for you,\n"
# 589 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "{PLAYER}!$"
# 590 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 591 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_Text_YoureOneWeWantToWin:
# 592 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "Yo, {PLAYER}!\n"
# 593 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "You're the one we want to win!$"
# 594 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 595 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_Text_OthersDontKnowYoureTheBest:
# 596 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "The others, they don't know that\n"
# 597 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "you're the best of the best!\p"
# 598 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "Isn't that right, {PLAYER}?\n"
# 599 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "Show them you've got guts!$"
# 600 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 601 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_Text_TrainersPowerIsOutOfTheOrdinary:
# 602 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "I hate to say this, but the TRAINER\n"
# 603 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "everybody's talking about is\l"
# 604 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "{STR_VAR_1}, no question about it!\p"
# 605 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "That TRAINER's power…\n"
# 606 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "It's out of the ordinary.$"
# 607 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 608 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_Text_TrainerIsBestNoOneWantsToListen:
# 609 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "Darn it… I've been telling people\n"
# 610 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "that {STR_VAR_1} is the best now…\p"
# 611 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "But no one wants to listen…$"
# 612 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 613 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_Text_HearingAboutToughNewTrainer:
# 614 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "I've been hearing things about\n"
# 615 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "a tough new TRAINER.\p"
# 616 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "This TRAINER's supposed to be beating\n"
# 617 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "GYM LEADERS, even.\p"
# 618 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "Do you know anything about this\n"
# 619 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "new TRAINER?$"
# 620 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 621 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_Text_ImPullingForYou:
# 622 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "Oh!\n"
# 623 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "{PLAYER}!\p"
# 624 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "Go for it!\n"
# 625 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "I'm pulling for you!$"
# 626 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 627 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_Text_BrawlyNoImYourFan:
# 628 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "Sigh…\n"
# 629 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "BRAWLY…\p"
# 630 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "Oh, no! Wait!\n"
# 631 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "That's not right! No, no, no!\p"
# 632 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "I'm your fan through and through!\p"
# 633 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "So make me proud!\n"
# 634 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "Go for it!$"
# 635 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 636 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_Text_ICantHelpLikingBrawly:
# 637 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "I can't help it, I can only get to\n"
# 638 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "like BRAWLY…$"
# 639 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 640 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_Text_NobodyUnderstandsBrawly:
# 641 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "Nobody understands the charm of\n"
# 642 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "BRAWLY…\p"
# 643 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "I don't care!\p"
# 644 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "Even if I'm the only one, I'm going\n"
# 645 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "to keep cheering for BRAWLY!$"
# 646 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 647 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_Text_MyFavoriteTrainerIsBrawly:
# 648 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "Whatever anyone says, my favorite\n"
# 649 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "TRAINER is DEWFORD's GYM LEADER\l"
# 650 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "BRAWLY!$"
# 651 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 652 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_Text_YouveSurpassedYourFather:
# 653 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "You've surpassed your own father in\n"
# 654 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "every regard!\p"
# 655 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "I'm telling you, so there's no question\n"
# 656 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "about it at all!$"
# 657 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 658 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_Text_YourFatherNeverGaveUpSoKeepOnBattling:
# 659 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "Even when things turned bleak,\n"
# 660 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "your father never gave up.\p"
# 661 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "This I know to be true.\p"
# 662 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "You never give up even if you lose!\n"
# 663 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "So keep on battling!$"
# 664 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 665 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_Text_LongWayToGoComparedToNorman:
# 666 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "NORMAN battled with more power,\n"
# 667 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "charisma, and showmanship than you.\p"
# 668 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "Even though people may say that\n"
# 669 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "you're strong…\p"
# 670 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "You've still got a long way to go\n"
# 671 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "compared to your father.$"
# 672 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 673 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_Text_YouAndNormanAreDifferent:
# 674 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "You're beginning to get the same\n"
# 675 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "air of awe NORMAN exudes.\p"
# 676 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "But there's something conclusively\n"
# 677 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "different between you and NORMAN.\p"
# 678 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "I can't tell you what that is.\n"
# 679 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "You'll have to find it yourself.$"
# 680 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 681 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_Text_WeDiscussStrongestTrainers:
# 682 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "Everyone here, we're all huge fans\n"
# 683 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "of POKéMON battles.\p"
# 684 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "We discuss who we consider to be\n"
# 685 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "the strongest of all TRAINERS.\p"
# 686 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "If you were to become famous,\n"
# 687 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "we might even become your fans!$"
# 688 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 689 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_Text_OhWoweeItsPlayer:
# 690 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "Oh, woweee! It's {PLAYER}!\n"
# 691 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "For real, too!\p"
# 692 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "Please, shake my hand, shake my hand!$"
# 693 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 694 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_Text_AlwaysCheerForYou:
# 695 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "I'll always cheer for you, {PLAYER}!\n"
# 696 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "Always, always!\p"
# 697 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "I don't want to see you lose ever,\n"
# 698 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "{PLAYER}.\p"
# 699 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "Because I know you're really,\n"
# 700 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "really strong, {PLAYER}!$"
# 701 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 702 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_Text_EveryoneThinksTrainerIsCool:
# 703 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "{STR_VAR_1} is really cool…\p"
# 704 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "Everyone thinks so, right, right?$"
# 705 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 706 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_Text_TrainerIsReallyCoolItsJustMe:
# 707 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "{STR_VAR_1} really is cool, don't\n"
# 708 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "you think so?\p"
# 709 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "Even if it's just me, I'm going to keep\n"
# 710 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "cheering my favorite TRAINER.$"
# 711 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 712 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_Text_WishThereWasTrainerLikeThat:
# 713 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "My favorite TRAINER is…\p"
# 714 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "Cool…\p"
# 715 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "Strong…\p"
# 716 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "And really nice…\p"
# 717 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "I wish there was a TRAINER like that…$"
# 718 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 719 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_Text_WantToBeStrongLikeYou:
# 720 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "Whoa! It's {PLAYER}!\n"
# 721 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "Wicked!\p"
# 722 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "When I grow up, I want to be strong\n"
# 723 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "like you, {PLAYER}!$"
# 724 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 725 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_Text_OnlyOneWhoCheersForYou:
# 726 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "Even if I'm the only one…\p"
# 727 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "You'll always be the only one\n"
# 728 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "I cheer for, {PLAYER}!\p"
# 729 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "Because I believe in you, {PLAYER}!$"
# 730 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 731 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_Text_TrainerIsWickedlyCool:
# 732 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "{STR_VAR_1} is so wickedly cool…\n"
# 733 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "I want to shake hands with my hero.$"
# 734 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 735 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_Text_NeverGoingToStopBeingTrainersFan:
# 736 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "Even if I'm the only one…\p"
# 737 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "I'm never going to stop being\n"
# 738 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "{STR_VAR_1}'s fan!\p"
# 739 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "Because I've heard, {STR_VAR_1}\n"
# 740 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "never loses!$"
# 741 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 742 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_Text_YoureAmazingAfterAll:
# 743 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "{PLAYER}!\n"
# 744 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "You are amazing after all!\p"
# 745 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "Ever since I set eyes on you,\n"
# 746 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "I knew that you were great.\p"
# 747 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "It looks like my eyes didn't deceive me.$"
# 748 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 749 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_Text_ImInYourCorner:
# 750 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "Who cares about the others.\n"
# 751 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "I'm in your corner!\p"
# 752 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "You don't need to worry. Just get\n"
# 753 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "out there and battle like always.$"
# 754 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 755 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_Text_ThinkTrainerIsNumberOne:
# 756 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "You're a pretty decent TRAINER,\n"
# 757 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "I think.\p"
# 758 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "But I also think that {STR_VAR_1}\n"
# 759 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "is number one right now.\p"
# 760 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "That's just my opinion.\n"
# 761 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "Don't worry about it too much.$"
# 762 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 763 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_Text_YoureMaybeStrongerThanTrainer:
# 764 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "Wow, you really are strong.\n"
# 765 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "Maybe even stronger than {STR_VAR_1}.\p"
# 766 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "But {STR_VAR_1} needs me.\p"
# 767 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "If I don't cheer for {STR_VAR_1},\n"
# 768 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "who will?$"
# 769 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 770 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_Text_YouChangedMyMind:
# 771 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "You've changed my mind!\n"
# 772 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "You are strong, aren't you?\p"
# 773 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "I'd like you to tell me how you managed\n"
# 774 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "to get so strong!$"
# 775 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 776 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_Text_YouBattleAttractivelyInToughSituation:
# 777 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "The tougher the situation, the more\n"
# 778 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "attractively you battle.\p"
# 779 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "I can't wait for your next battle!$"
# 780 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 781 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_Text_TrainerIsStandout:
# 782 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "Among the recently hot TRAINERS,\n"
# 783 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "{STR_VAR_1} is the standout.\p"
# 784 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "That toughness, it's simply not normal.\p"
# 785 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "You're doing okay, but you're not in\n"
# 786 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "the same class as {STR_VAR_1}.$"
# 787 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 788 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_Text_NoOneCanKnockYouButTrainerStronger:
# 789 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "You are really popular…\p"
# 790 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "You're strong, and you're caring to\n"
# 791 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "POKéMON. No one can knock you.\p"
# 792 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "But, you know, I believe in {STR_VAR_1}.\p"
# 793 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "{STR_VAR_1} is definitely stronger!\n"
# 794 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "I'm positive!$"
# 795 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 796 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_Text_YouImpressive:
# 797 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "You…\p"
# 798 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "Impressive!$"
# 799 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 800 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_Text_OnlyIRecognizeYourTrueWorth:
# 801 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "Your true worth, it is fine if only\n"
# 802 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "I recognized it.\p"
# 803 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "The others I doubt will understand\n"
# 804 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "the hidden power that beats within.$"
# 805 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 806 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_Text_HaventRealizedPotential:
# 807 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "Yes, I see strength in your eyes.\p"
# 808 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "But!\p"
# 809 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "You still haven't realized your\n"
# 810 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "potential.$"
# 811 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 812 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_Text_YourePowerfulButNotTrueStrength:
# 813 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "It is true that you are tremendously\n"
# 814 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "powerful.\p"
# 815 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "But!\n"
# 816 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "I can tell…\p"
# 817 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "That strength cannot be considered\n"
# 818 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "true strength yet!\p"
# 819 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "True strength is…!\n"
# 820 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "… …\p"
# 821 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "Actually, I have no idea, either.$"
