# 1 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 2 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
.set LOCALID_SCIENTIST_1, 1
# 3 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
.set LOCALID_SCIENTIST_2, 2
# 4 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
.set LOCALID_SAILOR, 3
# 5 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
.set LOCALID_OLD_MAN, 4
# 6 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
.set LOCALID_WOMAN, 5
# 7 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
.set LOCALID_STAIR_GRUNT, 9
# 8 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 9 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_MapScripts::
# 10 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, MossdeepCity_SpaceCenter_1F_OnLoad
# 11 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, MossdeepCity_SpaceCenter_1F_OnTransition
# 12 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.byte 0
# 13 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 14 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_OnTransition:
# 15 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	goto_if_eq VAR_MOSSDEEP_CITY_STATE, 2, MossdeepCity_SpaceCenter_1F_EventScript_MoveObjectsForTeamMagma
# 16 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	end
# 17 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 18 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_EventScript_MoveObjectsForTeamMagma::
# 19 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	setobjectxyperm LOCALID_SAILOR, 1, 9
# 20 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	setobjectmovementtype LOCALID_SAILOR, MOVEMENT_TYPE_FACE_RIGHT
# 21 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	setobjectxyperm LOCALID_WOMAN, 0, 8
# 22 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	setobjectmovementtype LOCALID_WOMAN, MOVEMENT_TYPE_FACE_RIGHT
# 23 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	setobjectxyperm LOCALID_OLD_MAN, 1, 6
# 24 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	setobjectmovementtype LOCALID_OLD_MAN, MOVEMENT_TYPE_FACE_RIGHT
# 25 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	setobjectxyperm LOCALID_SCIENTIST_1, 3, 4
# 26 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	setobjectmovementtype LOCALID_SCIENTIST_1, MOVEMENT_TYPE_FACE_RIGHT
# 27 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	setobjectmovementtype LOCALID_SCIENTIST_2, MOVEMENT_TYPE_FACE_RIGHT
# 28 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	goto_if_eq VAR_MOSSDEEP_SPACE_CENTER_STAIR_GUARD_STATE, 1, MossdeepCity_SpaceCenter_1F_EventScript_MoveStairGuardLeft
# 29 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	goto_if_eq VAR_MOSSDEEP_SPACE_CENTER_STAIR_GUARD_STATE, 2, MossdeepCity_SpaceCenter_1F_EventScript_MoveStairGuardDown
# 30 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	goto_if_eq VAR_MOSSDEEP_SPACE_CENTER_STAIR_GUARD_STATE, 3, MossdeepCity_SpaceCenter_1F_EventScript_MoveStairGuardRight
# 31 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	end
# 32 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 33 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_EventScript_MoveStairGuardLeft::
# 34 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	setobjectxyperm LOCALID_STAIR_GRUNT, 12, 2
# 35 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	end
# 36 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 37 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_EventScript_MoveStairGuardDown::
# 38 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	setobjectxyperm LOCALID_STAIR_GRUNT, 13, 3
# 39 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	end
# 40 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 41 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
@ Functionally unused. See comment on MossdeepCity_SpaceCenter_1F_EventScript_MoveGruntFromStairsEast
# 42 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_EventScript_MoveStairGuardRight::
# 43 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	setobjectxyperm LOCALID_STAIR_GRUNT, 14, 2
# 44 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	end
# 45 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 46 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_OnLoad:
# 47 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	goto_if_le VAR_MOSSDEEP_CITY_STATE, 2, MossdeepCity_SpaceCenter_1F_EventScript_SetMagmaNote
# 48 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	end
# 49 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 50 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_EventScript_SetMagmaNote::
# 51 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	setmetatile 2, 5, METATILE_Facility_DataPad, TRUE
# 52 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	return
# 53 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 54 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_EventScript_RocketLaunchCounter::
# 55 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	lock
# 56 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	faceplayer
# 57 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	goto_if_eq VAR_MOSSDEEP_CITY_STATE, 2, MossdeepCity_SpaceCenter_1F_EventScript_RocketLaunchCounterMagma
# 58 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	dotimebasedevents
# 59 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	specialvar VAR_RESULT, GetWeekCount
# 60 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	buffernumberstring STR_VAR_1, VAR_RESULT
# 61 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	call_if_eq VAR_RESULT, 0, MossdeepCity_SpaceCenter_1F_EventScript_NoLaunchesYet
# 62 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	call_if_ge VAR_RESULT, 1, MossdeepCity_SpaceCenter_1F_EventScript_ShowLaunchNumber
# 63 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	closemessage
# 64 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 65 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	waitmovement 0
# 66 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	release
# 67 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	end
# 68 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 69 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_EventScript_NoLaunchesYet::
# 70 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	msgbox MossdeepCity_SpaceCenter_1F_Text_RocketLaunchImminent, MSGBOX_DEFAULT
# 71 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	return
# 72 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 73 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_EventScript_ShowLaunchNumber::
# 74 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	msgbox MossdeepCity_SpaceCenter_1F_Text_SuccessfulLaunchNumber, MSGBOX_DEFAULT
# 75 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	return
# 76 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 77 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_EventScript_RocketLaunchCounterMagma::
# 78 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	dotimebasedevents
# 79 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	specialvar VAR_RESULT, GetWeekCount
# 80 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	buffernumberstring STR_VAR_1, VAR_RESULT
# 81 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	call_if_eq VAR_RESULT, 0, MossdeepCity_SpaceCenter_1F_EventScript_NoLaunchesYetMagma
# 82 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	call_if_ge VAR_RESULT, 1, MossdeepCity_SpaceCenter_1F_EventScript_ShowLaunchNumberMagma
# 83 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	closemessage
# 84 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterRight
# 85 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	waitmovement 0
# 86 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	release
# 87 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	end
# 88 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 89 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_EventScript_NoLaunchesYetMagma::
# 90 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	msgbox MossdeepCity_SpaceCenter_1F_Text_HaywireButRocketLaunchImminent, MSGBOX_DEFAULT
# 91 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	return
# 92 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 93 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_EventScript_ShowLaunchNumberMagma::
# 94 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	msgbox MossdeepCity_SpaceCenter_1F_Text_HaywireButSuccessfulLaunchNumber, MSGBOX_DEFAULT
# 95 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	return
# 96 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 97 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_EventScript_Scientist::
# 98 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	lock
# 99 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	faceplayer
# 100 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	goto_if_eq VAR_MOSSDEEP_CITY_STATE, 2, MossdeepCity_SpaceCenter_1F_EventScript_ScientistMagma
# 101 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	msgbox MossdeepCity_SpaceCenter_1F_Text_RocketLaunchDemandsPerfection, MSGBOX_DEFAULT
# 102 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	release
# 103 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	end
# 104 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 105 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_EventScript_ScientistMagma::
# 106 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	msgbox MossdeepCity_SpaceCenter_1F_Text_MagmaHaveSightsOnSpaceCenter, MSGBOX_DEFAULT
# 107 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterRight
# 108 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	waitmovement 0
# 109 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	release
# 110 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	end
# 111 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 112 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_EventScript_SunStoneMan::
# 113 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	lock
# 114 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	faceplayer
# 115 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	goto_if_eq VAR_MOSSDEEP_CITY_STATE, 2, MossdeepCity_SpaceCenter_1F_EventScript_SunStoneManMagma
# 116 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	goto_if_set FLAG_RECEIVED_SUN_STONE_MOSSDEEP, MossdeepCity_SpaceCenter_1F_EventScript_GaveSunStone
# 117 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	msgbox MossdeepCity_SpaceCenter_1F_Text_FoundThisYouCanHaveIt, MSGBOX_DEFAULT
# 118 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	giveitem ITEM_SUN_STONE
# 119 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 120 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	setflag FLAG_RECEIVED_SUN_STONE_MOSSDEEP
# 121 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	msgbox MossdeepCity_SpaceCenter_1F_Text_HoennFamousForMeteorShowers, MSGBOX_DEFAULT
# 122 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	release
# 123 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	end
# 124 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 125 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_EventScript_GaveSunStone::
# 126 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	msgbox MossdeepCity_SpaceCenter_1F_Text_HoennFamousForMeteorShowers, MSGBOX_DEFAULT
# 127 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	release
# 128 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	end
# 129 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 130 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_EventScript_SunStoneManMagma::
# 131 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	goto_if_set FLAG_RECEIVED_SUN_STONE_MOSSDEEP, MossdeepCity_SpaceCenter_1F_EventScript_GaveSunStoneMagma
# 132 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	msgbox MossdeepCity_SpaceCenter_1F_Text_MagmaCantStealFuelTakeThis, MSGBOX_DEFAULT
# 133 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	giveitem ITEM_SUN_STONE
# 134 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 135 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	setflag FLAG_RECEIVED_SUN_STONE_MOSSDEEP
# 136 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	msgbox MossdeepCity_SpaceCenter_1F_Text_CantStrollOnBeachWithMagma, MSGBOX_DEFAULT
# 137 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterRight
# 138 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	waitmovement 0
# 139 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	release
# 140 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	end
# 141 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 142 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_EventScript_GaveSunStoneMagma::
# 143 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	msgbox MossdeepCity_SpaceCenter_1F_Text_CantStrollOnBeachWithMagma, MSGBOX_DEFAULT
# 144 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterRight
# 145 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	waitmovement 0
# 146 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	release
# 147 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	end
# 148 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 149 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_EventScript_Woman::
# 150 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	lock
# 151 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	faceplayer
# 152 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, MossdeepCity_SpaceCenter_1F_EventScript_WomanNormal
# 153 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	goto_if_eq VAR_MOSSDEEP_CITY_STATE, 2, MossdeepCity_SpaceCenter_1F_EventScript_WomanMagma
# 154 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	goto_if_lt VAR_MOSSDEEP_CITY_STATE, 2, MossdeepCity_SpaceCenter_1F_EventScript_WomanNormal
# 155 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	goto MossdeepCity_SpaceCenter_1F_EventScript_WomanMagma
# 156 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	end
# 157 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 158 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_EventScript_WomanNormal::
# 159 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	msgbox MossdeepCity_SpaceCenter_1F_Text_DidPokemonComeFromSpace, MSGBOX_DEFAULT
# 160 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	release
# 161 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	end
# 162 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 163 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_EventScript_WomanMagma::
# 164 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	msgbox MossdeepCity_SpaceCenter_1F_Text_AquaShouldBeatMagma, MSGBOX_DEFAULT
# 165 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	release
# 166 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	end
# 167 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 168 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_EventScript_OldMan::
# 169 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	lock
# 170 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	faceplayer
# 171 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, MossdeepCity_SpaceCenter_1F_EventScript_OldManNormal
# 172 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	goto_if_eq VAR_MOSSDEEP_CITY_STATE, 2, MossdeepCity_SpaceCenter_1F_EventScript_OldManMagma
# 173 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	goto_if_lt VAR_MOSSDEEP_CITY_STATE, 2, MossdeepCity_SpaceCenter_1F_EventScript_OldManNormal
# 174 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	goto MossdeepCity_SpaceCenter_1F_EventScript_OldManMagma
# 175 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	end
# 176 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 177 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_EventScript_OldManNormal::
# 178 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	msgbox MossdeepCity_SpaceCenter_1F_Text_RocketsBoggleMyMind, MSGBOX_DEFAULT
# 179 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	closemessage
# 180 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 181 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	waitmovement 0
# 182 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	release
# 183 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	end
# 184 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 185 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_EventScript_OldManMagma::
# 186 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	msgbox MossdeepCity_SpaceCenter_1F_Text_MagmaWantsToSpoilMyDream, MSGBOX_DEFAULT
# 187 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	closemessage
# 188 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 189 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	waitmovement 0
# 190 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	release
# 191 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	end
# 192 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 193 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_EventScript_Steven::
# 194 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	lock
# 195 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	faceplayer
# 196 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	msgbox MossdeepCity_SpaceCenter_1F_Text_StevenMagmaCantBeAllowedToTakeFuel, MSGBOX_DEFAULT
# 197 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 198 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	waitmovement 0
# 199 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	release
# 200 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	end
# 201 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 202 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_EventScript_MagmaNote::
# 203 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	lockall
# 204 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	msgbox MossdeepCity_SpaceCenter_1F_Text_MagmaIntentToStealNotice, MSGBOX_DEFAULT
# 205 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	releaseall
# 206 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	end
# 207 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 208 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_EventScript_Grunt3::
# 209 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	trainerbattle_single TRAINER_GRUNT_SPACE_CENTER_3, MossdeepCity_SpaceCenter_1F_Text_Grunt3Intro, MossdeepCity_SpaceCenter_1F_Text_Grunt3Defeat
# 210 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	msgbox MossdeepCity_SpaceCenter_1F_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
# 211 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	end
# 212 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 213 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_EventScript_Grunt1::
# 214 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	trainerbattle_single TRAINER_GRUNT_SPACE_CENTER_1, MossdeepCity_SpaceCenter_1F_Text_Grunt1Intro, MossdeepCity_SpaceCenter_1F_Text_Grunt1Defeat
# 215 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	msgbox MossdeepCity_SpaceCenter_1F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
# 216 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	end
# 217 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 218 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_EventScript_Grunt4::
# 219 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	trainerbattle_single TRAINER_GRUNT_SPACE_CENTER_4, MossdeepCity_SpaceCenter_1F_Text_Grunt4Intro, MossdeepCity_SpaceCenter_1F_Text_Grunt4Defeat
# 220 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	msgbox MossdeepCity_SpaceCenter_1F_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
# 221 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	end
# 222 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 223 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_EventScript_Grunt2::
# 224 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	lock
# 225 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	faceplayer
# 226 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	goto_if_set FLAG_DEFEATED_GRUNT_SPACE_CENTER_1F, MossdeepCity_SpaceCenter_1F_EventScript_Grunt2Defeated
# 227 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	msgbox MossdeepCity_SpaceCenter_1F_Text_Grunt2Intro, MSGBOX_DEFAULT
# 228 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	trainerbattle_no_intro TRAINER_GRUNT_SPACE_CENTER_2, MossdeepCity_SpaceCenter_1F_Text_Grunt2Defeat
# 229 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	setflag FLAG_DEFEATED_GRUNT_SPACE_CENTER_1F
# 230 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	copyobjectxytoperm LOCALID_STAIR_GRUNT
# 231 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	switch VAR_FACING
# 232 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	case DIR_WEST, MossdeepCity_SpaceCenter_1F_EventScript_MoveGruntFromStairsWest
# 233 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
#ifdef BUGFIX
# 234 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	case DIR_EAST, MossdeepCity_SpaceCenter_1F_EventScript_MoveGruntFromStairsEast
# 235 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
#else
# 236 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	case DIR_WEST, MossdeepCity_SpaceCenter_1F_EventScript_MoveGruntFromStairsEast
# 237 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
#endif
# 238 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	applymovement LOCALID_STAIR_GRUNT, MossdeepCity_SpaceCenter_1F_Movement_MoveGruntFromStairs
# 239 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	waitmovement 0
# 240 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	setvar VAR_MOSSDEEP_SPACE_CENTER_STAIR_GUARD_STATE, 2
# 241 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	release
# 242 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	end
# 243 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 244 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_EventScript_Grunt2Defeated::
# 245 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	msgbox MossdeepCity_SpaceCenter_1F_Text_Grunt2PostBattle, MSGBOX_DEFAULT
# 246 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	release
# 247 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	end
# 248 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 249 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_EventScript_MoveGruntFromStairsWest::
# 250 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	applymovement LOCALID_STAIR_GRUNT, MossdeepCity_SpaceCenter_1F_Movement_MoveGruntFromStairsWest
# 251 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	waitmovement 0
# 252 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	setvar VAR_MOSSDEEP_SPACE_CENTER_STAIR_GUARD_STATE, 1
# 253 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	release
# 254 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	end
# 255 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 256 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
@ Functionally unused by mistake. The movement is handled anyway after the switch (see above)
# 257 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
@ This also means VAR_MOSSDEEP_SPACE_CENTER_STAIR_GUARD_STATE can never be 3
# 258 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_EventScript_MoveGruntFromStairsEast::
# 259 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	applymovement LOCALID_STAIR_GRUNT, MossdeepCity_SpaceCenter_1F_Movement_MoveGruntFromStairsEast
# 260 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	waitmovement 0
# 261 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	setvar VAR_MOSSDEEP_SPACE_CENTER_STAIR_GUARD_STATE, 3
# 262 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	release
# 263 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	end
# 264 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 265 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_Movement_MoveGruntFromStairsWest:
# 266 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	lock_facing_direction
# 267 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	walk_left
# 268 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	unlock_facing_direction
# 269 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	step_end
# 270 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 271 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
@ Functionally unused. See above
# 272 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_Movement_MoveGruntFromStairsEast:
# 273 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	lock_facing_direction
# 274 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	walk_right
# 275 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	unlock_facing_direction
# 276 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	step_end
# 277 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 278 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
@ This was meant to only handle the player facing North, but by mistake(?) it also handles the player facing East
# 279 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_Movement_MoveGruntFromStairs:
# 280 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	face_left
# 281 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	lock_facing_direction
# 282 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	walk_right
# 283 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	unlock_facing_direction
# 284 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	step_end
# 285 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 286 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_Text_RocketLaunchImminent:
# 287 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "The rocket's launch is imminent!$"
# 288 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 289 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_Text_SuccessfulLaunchNumber:
# 290 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "The rocket launched safely!\n"
# 291 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "That's successful launch no. {STR_VAR_1}!$"
# 292 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 293 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_Text_HaywireButRocketLaunchImminent:
# 294 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "I know that things are a little\n"
# 295 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "haywire right now, but…\p"
# 296 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "The rocket's launch is imminent!$"
# 297 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 298 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_Text_HaywireButSuccessfulLaunchNumber:
# 299 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "I know that things are a little\n"
# 300 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "haywire right now, but…\p"
# 301 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "The rocket launched safely!\n"
# 302 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "That's successful launch no. {STR_VAR_1}!$"
# 303 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 304 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_Text_RocketLaunchDemandsPerfection:
# 305 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "A rocket launch demands perfection.\n"
# 306 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "Not even a 1% margin of error is allowed.\p"
# 307 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "Even if it's 99% okay, the whole thing\n"
# 308 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "is useless if 1% happens to be no good.\p"
# 309 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "Despite that, we never stop trying.\n"
# 310 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "Why? It's a dream that never ends.$"
# 311 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 312 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_Text_MagmaHaveSightsOnSpaceCenter:
# 313 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "Those MAGMA thugs have their sights\n"
# 314 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "set on our SPACE CENTER.\p"
# 315 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "But we can't allow anything that minor\n"
# 316 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "to interfere with our rocket launch!$"
# 317 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 318 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_Text_FoundThisYouCanHaveIt:
# 319 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "I was taking a stroll down the beach\n"
# 320 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "when I found this.\p"
# 321 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "It's not anything I need, so you can\n"
# 322 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "have it.$"
# 323 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 324 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_Text_HoennFamousForMeteorShowers:
# 325 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "The HOENN region has been famous for \n"
# 326 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "its meteor showers for a long time.$"
# 327 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 328 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_Text_MagmaCantStealFuelTakeThis:
# 329 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "TEAM MAGMA can't be allowed to steal\n"
# 330 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "the rocket fuel.\p"
# 331 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "Oh, by the way, you can have this stone\n"
# 332 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "I found on the beach.$"
# 333 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 334 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_Text_CantStrollOnBeachWithMagma:
# 335 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "With TEAM MAGMA around, I guess\n"
# 336 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "strolls on the beach aren't safe.$"
# 337 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 338 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_Text_DidPokemonComeFromSpace:
# 339 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "Some people claim that POKéMON came\n"
# 340 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "from space. Could it be true?$"
# 341 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 342 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_Text_AquaShouldBeatMagma:
# 343 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "TEAM AQUA should take care of\n"
# 344 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "TEAM MAGMA!\p"
# 345 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "But if they did that, TEAM AQUA will\n"
# 346 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "become bold and brazen, won't they?$"
# 347 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 348 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_Text_RocketsBoggleMyMind:
# 349 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "A giant chunk of metal bursts through\n"
# 350 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "the skies and flies into space…\p"
# 351 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "It boggles my mind!$"
# 352 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 353 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_Text_MagmaWantsToSpoilMyDream:
# 354 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "A giant chunk of metal bursts through\n"
# 355 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "the skies and flies into space…\p"
# 356 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "But TEAM MAGMA wants to spoil\n"
# 357 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "that dream of mine!\p"
# 358 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "I'm not having any of that!$"
# 359 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 360 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_Text_StevenMagmaCantBeAllowedToTakeFuel:
# 361 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "STEVEN: {PLAYER}{KUN}, have you read that\n"
# 362 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "proclamation already?\p"
# 363 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "TEAM MAGMA is coming after the rocket\n"
# 364 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "fuel on this island.\p"
# 365 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "I don't know what they'd need it for,\n"
# 366 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "but they can't be allowed to take it.\p"
# 367 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "I'll keep an eye on things for\n"
# 368 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "a while longer.\p"
# 369 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "In the meantime, why don't you go\n"
# 370 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "check out the town?$"
# 371 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 372 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_Text_Grunt3Intro:
# 373 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "As promised, we've come for\n"
# 374 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "the rocket fuel!$"
# 375 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 376 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_Text_Grunt3Defeat:
# 377 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "Ran out of fuel…$"
# 378 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 379 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_Text_Grunt3PostBattle:
# 380 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "Don't think you're on a roll just\n"
# 381 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "because you've beaten me!$"
# 382 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 383 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_Text_Grunt1Intro:
# 384 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "We gave you fair warning!\n"
# 385 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "There's nothing sneaky about us!$"
# 386 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 387 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_Text_Grunt1Defeat:
# 388 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "Grrr…\n"
# 389 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "We should've used sneaky treachery…$"
# 390 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 391 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_Text_Grunt1PostBattle:
# 392 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "Okay, I get it already! The next time,\n"
# 393 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "we'll come unannounced.$"
# 394 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 395 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_Text_Grunt4Intro:
# 396 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "The rocket fuel the SPACE CENTER has\n"
# 397 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "in storage--that's what we're after.\p"
# 398 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "We mean to take every last bit of it!$"
# 399 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 400 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_Text_Grunt4Defeat:
# 401 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "Please, can you spare some fuel?\n"
# 402 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "Even a chintzy cup will do!$"
# 403 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 404 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_Text_Grunt4PostBattle:
# 405 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "What are we going to do with\n"
# 406 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "the rocket fuel?\p"
# 407 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "How would I know?\n"
# 408 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "Ask our leader upstairs!$"
# 409 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 410 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_Text_Grunt2Intro:
# 411 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "Our leader said no one, but no one,\n"
# 412 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "gets past me!$"
# 413 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 414 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_Text_Grunt2Defeat:
# 415 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "Ack! Ack! Aaack!$"
# 416 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 417 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_Text_Grunt2PostBattle:
# 418 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "Please, tell our leader that\n"
# 419 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "I never abandoned my post.\l"
# 420 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "That I stayed to the bitter end…$"
# 421 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 422 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_Text_MagmaIntentToStealNotice:
# 423 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "This is…\n"
# 424 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "An intent-to-steal notice?\p"
# 425 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "“To the staff of the SPACE CENTER:\n"
# 426 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "How are you? We are doing fine.\p"
# 427 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "“We will soon visit you to take your\n"
# 428 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "rocket fuel.\p"
# 429 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "“Please don't try to stop us.\n"
# 430 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "We will take the fuel no matter what.\p"
# 431 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "“Let there be more land!\n"
# 432 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "                                          TEAM MAGMA”$"
