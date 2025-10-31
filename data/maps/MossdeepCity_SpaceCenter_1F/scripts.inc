# 1 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 2 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_MapScripts::
# 3 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, MossdeepCity_SpaceCenter_1F_OnLoad
# 4 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, MossdeepCity_SpaceCenter_1F_OnTransition
# 5 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.byte 0
# 6 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 7 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_OnTransition:
# 8 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	goto_if_eq VAR_MOSSDEEP_CITY_STATE, 2, MossdeepCity_SpaceCenter_1F_EventScript_MoveObjectsForTeamMagma
# 9 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	end
# 10 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 11 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_EventScript_MoveObjectsForTeamMagma::
# 12 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	setobjectxyperm LOCALID_SPACE_CENTER_1F_SAILOR, 1, 9
# 13 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	setobjectmovementtype LOCALID_SPACE_CENTER_1F_SAILOR, MOVEMENT_TYPE_FACE_RIGHT
# 14 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	setobjectxyperm LOCALID_SPACE_CENTER_1F_WOMAN, 0, 8
# 15 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	setobjectmovementtype LOCALID_SPACE_CENTER_1F_WOMAN, MOVEMENT_TYPE_FACE_RIGHT
# 16 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	setobjectxyperm LOCALID_SPACE_CENTER_1F_OLD_MAN, 1, 6
# 17 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	setobjectmovementtype LOCALID_SPACE_CENTER_1F_OLD_MAN, MOVEMENT_TYPE_FACE_RIGHT
# 18 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	setobjectxyperm LOCALID_SPACE_CENTER_1F_SCIENTIST_1, 3, 4
# 19 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	setobjectmovementtype LOCALID_SPACE_CENTER_1F_SCIENTIST_1, MOVEMENT_TYPE_FACE_RIGHT
# 20 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	setobjectmovementtype LOCALID_SPACE_CENTER_1F_SCIENTIST_2, MOVEMENT_TYPE_FACE_RIGHT
# 21 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	goto_if_eq VAR_MOSSDEEP_SPACE_CENTER_STAIR_GUARD_STATE, 1, MossdeepCity_SpaceCenter_1F_EventScript_MoveStairGuardLeft
# 22 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	goto_if_eq VAR_MOSSDEEP_SPACE_CENTER_STAIR_GUARD_STATE, 2, MossdeepCity_SpaceCenter_1F_EventScript_MoveStairGuardDown
# 23 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	goto_if_eq VAR_MOSSDEEP_SPACE_CENTER_STAIR_GUARD_STATE, 3, MossdeepCity_SpaceCenter_1F_EventScript_MoveStairGuardRight
# 24 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	end
# 25 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 26 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_EventScript_MoveStairGuardLeft::
# 27 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	setobjectxyperm LOCALID_SPACE_CENTER_1F_STAIR_GRUNT, 12, 2
# 28 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	end
# 29 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 30 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_EventScript_MoveStairGuardDown::
# 31 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	setobjectxyperm LOCALID_SPACE_CENTER_1F_STAIR_GRUNT, 13, 3
# 32 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	end
# 33 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 34 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
@ Functionally unused. See comment on MossdeepCity_SpaceCenter_1F_EventScript_MoveGruntFromStairsEast
# 35 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_EventScript_MoveStairGuardRight::
# 36 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	setobjectxyperm LOCALID_SPACE_CENTER_1F_STAIR_GRUNT, 14, 2
# 37 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	end
# 38 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 39 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_OnLoad:
# 40 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	goto_if_le VAR_MOSSDEEP_CITY_STATE, 2, MossdeepCity_SpaceCenter_1F_EventScript_SetMagmaNote
# 41 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	end
# 42 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 43 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_EventScript_SetMagmaNote::
# 44 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	setmetatile 2, 5, METATILE_Facility_DataPad, TRUE
# 45 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	return
# 46 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 47 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_EventScript_RocketLaunchCounter::
# 48 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	lock
# 49 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	faceplayer
# 50 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	goto_if_eq VAR_MOSSDEEP_CITY_STATE, 2, MossdeepCity_SpaceCenter_1F_EventScript_RocketLaunchCounterMagma
# 51 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	dotimebasedevents
# 52 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	specialvar VAR_RESULT, GetWeekCount
# 53 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	buffernumberstring STR_VAR_1, VAR_RESULT
# 54 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	call_if_eq VAR_RESULT, 0, MossdeepCity_SpaceCenter_1F_EventScript_NoLaunchesYet
# 55 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	call_if_ge VAR_RESULT, 1, MossdeepCity_SpaceCenter_1F_EventScript_ShowLaunchNumber
# 56 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	closemessage
# 57 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 58 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	waitmovement 0
# 59 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	release
# 60 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	end
# 61 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 62 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_EventScript_NoLaunchesYet::
# 63 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	msgbox MossdeepCity_SpaceCenter_1F_Text_RocketLaunchImminent, MSGBOX_DEFAULT
# 64 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	return
# 65 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 66 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_EventScript_ShowLaunchNumber::
# 67 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	msgbox MossdeepCity_SpaceCenter_1F_Text_SuccessfulLaunchNumber, MSGBOX_DEFAULT
# 68 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	return
# 69 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 70 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_EventScript_RocketLaunchCounterMagma::
# 71 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	dotimebasedevents
# 72 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	specialvar VAR_RESULT, GetWeekCount
# 73 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	buffernumberstring STR_VAR_1, VAR_RESULT
# 74 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	call_if_eq VAR_RESULT, 0, MossdeepCity_SpaceCenter_1F_EventScript_NoLaunchesYetMagma
# 75 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	call_if_ge VAR_RESULT, 1, MossdeepCity_SpaceCenter_1F_EventScript_ShowLaunchNumberMagma
# 76 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	closemessage
# 77 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterRight
# 78 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	waitmovement 0
# 79 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	release
# 80 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	end
# 81 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 82 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_EventScript_NoLaunchesYetMagma::
# 83 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	msgbox MossdeepCity_SpaceCenter_1F_Text_HaywireButRocketLaunchImminent, MSGBOX_DEFAULT
# 84 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	return
# 85 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 86 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_EventScript_ShowLaunchNumberMagma::
# 87 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	msgbox MossdeepCity_SpaceCenter_1F_Text_HaywireButSuccessfulLaunchNumber, MSGBOX_DEFAULT
# 88 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	return
# 89 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 90 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_EventScript_Scientist::
# 91 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	lock
# 92 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	faceplayer
# 93 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	goto_if_eq VAR_MOSSDEEP_CITY_STATE, 2, MossdeepCity_SpaceCenter_1F_EventScript_ScientistMagma
# 94 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	msgbox MossdeepCity_SpaceCenter_1F_Text_RocketLaunchDemandsPerfection, MSGBOX_DEFAULT
# 95 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	release
# 96 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	end
# 97 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 98 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_EventScript_ScientistMagma::
# 99 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	msgbox MossdeepCity_SpaceCenter_1F_Text_MagmaHaveSightsOnSpaceCenter, MSGBOX_DEFAULT
# 100 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterRight
# 101 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	waitmovement 0
# 102 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	release
# 103 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	end
# 104 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 105 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_EventScript_SunStoneMan::
# 106 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	lock
# 107 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	faceplayer
# 108 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	goto_if_eq VAR_MOSSDEEP_CITY_STATE, 2, MossdeepCity_SpaceCenter_1F_EventScript_SunStoneManMagma
# 109 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	goto_if_set FLAG_RECEIVED_SUN_STONE_MOSSDEEP, MossdeepCity_SpaceCenter_1F_EventScript_GaveSunStone
# 110 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	msgbox MossdeepCity_SpaceCenter_1F_Text_FoundThisYouCanHaveIt, MSGBOX_DEFAULT
# 111 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	giveitem ITEM_SUN_STONE
# 112 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 113 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	setflag FLAG_RECEIVED_SUN_STONE_MOSSDEEP
# 114 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	msgbox MossdeepCity_SpaceCenter_1F_Text_HoennFamousForMeteorShowers, MSGBOX_DEFAULT
# 115 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	release
# 116 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	end
# 117 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 118 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_EventScript_GaveSunStone::
# 119 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	msgbox MossdeepCity_SpaceCenter_1F_Text_HoennFamousForMeteorShowers, MSGBOX_DEFAULT
# 120 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	release
# 121 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	end
# 122 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 123 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_EventScript_SunStoneManMagma::
# 124 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	goto_if_set FLAG_RECEIVED_SUN_STONE_MOSSDEEP, MossdeepCity_SpaceCenter_1F_EventScript_GaveSunStoneMagma
# 125 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	msgbox MossdeepCity_SpaceCenter_1F_Text_MagmaCantStealFuelTakeThis, MSGBOX_DEFAULT
# 126 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	giveitem ITEM_SUN_STONE
# 127 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 128 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	setflag FLAG_RECEIVED_SUN_STONE_MOSSDEEP
# 129 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	msgbox MossdeepCity_SpaceCenter_1F_Text_CantStrollOnBeachWithMagma, MSGBOX_DEFAULT
# 130 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterRight
# 131 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	waitmovement 0
# 132 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	release
# 133 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	end
# 134 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 135 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_EventScript_GaveSunStoneMagma::
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
MossdeepCity_SpaceCenter_1F_EventScript_Woman::
# 143 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	lock
# 144 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	faceplayer
# 145 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, MossdeepCity_SpaceCenter_1F_EventScript_WomanNormal
# 146 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	goto_if_eq VAR_MOSSDEEP_CITY_STATE, 2, MossdeepCity_SpaceCenter_1F_EventScript_WomanMagma
# 147 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	goto_if_lt VAR_MOSSDEEP_CITY_STATE, 2, MossdeepCity_SpaceCenter_1F_EventScript_WomanNormal
# 148 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	goto MossdeepCity_SpaceCenter_1F_EventScript_WomanMagma
# 149 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	end
# 150 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 151 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_EventScript_WomanNormal::
# 152 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	msgbox MossdeepCity_SpaceCenter_1F_Text_DidPokemonComeFromSpace, MSGBOX_DEFAULT
# 153 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	release
# 154 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	end
# 155 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 156 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_EventScript_WomanMagma::
# 157 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	msgbox MossdeepCity_SpaceCenter_1F_Text_AquaShouldBeatMagma, MSGBOX_DEFAULT
# 158 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	release
# 159 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	end
# 160 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 161 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_EventScript_OldMan::
# 162 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	lock
# 163 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	faceplayer
# 164 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, MossdeepCity_SpaceCenter_1F_EventScript_OldManNormal
# 165 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	goto_if_eq VAR_MOSSDEEP_CITY_STATE, 2, MossdeepCity_SpaceCenter_1F_EventScript_OldManMagma
# 166 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	goto_if_lt VAR_MOSSDEEP_CITY_STATE, 2, MossdeepCity_SpaceCenter_1F_EventScript_OldManNormal
# 167 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	goto MossdeepCity_SpaceCenter_1F_EventScript_OldManMagma
# 168 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	end
# 169 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 170 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_EventScript_OldManNormal::
# 171 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	msgbox MossdeepCity_SpaceCenter_1F_Text_RocketsBoggleMyMind, MSGBOX_DEFAULT
# 172 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	closemessage
# 173 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 174 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	waitmovement 0
# 175 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	release
# 176 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	end
# 177 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 178 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_EventScript_OldManMagma::
# 179 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	msgbox MossdeepCity_SpaceCenter_1F_Text_MagmaWantsToSpoilMyDream, MSGBOX_DEFAULT
# 180 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	closemessage
# 181 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 182 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	waitmovement 0
# 183 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	release
# 184 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	end
# 185 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 186 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_EventScript_Steven::
# 187 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	lock
# 188 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	faceplayer
# 189 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	msgbox MossdeepCity_SpaceCenter_1F_Text_StevenMagmaCantBeAllowedToTakeFuel, MSGBOX_DEFAULT
# 190 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 191 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	waitmovement 0
# 192 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	release
# 193 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	end
# 194 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 195 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_EventScript_MagmaNote::
# 196 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	lockall
# 197 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	msgbox MossdeepCity_SpaceCenter_1F_Text_MagmaIntentToStealNotice, MSGBOX_DEFAULT
# 198 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	releaseall
# 199 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	end
# 200 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 201 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_EventScript_Grunt3::
# 202 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	trainerbattle_single TRAINER_GRUNT_SPACE_CENTER_3, MossdeepCity_SpaceCenter_1F_Text_Grunt3Intro, MossdeepCity_SpaceCenter_1F_Text_Grunt3Defeat
# 203 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	msgbox MossdeepCity_SpaceCenter_1F_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
# 204 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	end
# 205 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 206 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_EventScript_Grunt1::
# 207 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	trainerbattle_single TRAINER_GRUNT_SPACE_CENTER_1, MossdeepCity_SpaceCenter_1F_Text_Grunt1Intro, MossdeepCity_SpaceCenter_1F_Text_Grunt1Defeat
# 208 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	msgbox MossdeepCity_SpaceCenter_1F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
# 209 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	end
# 210 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 211 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_EventScript_Grunt4::
# 212 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	trainerbattle_single TRAINER_GRUNT_SPACE_CENTER_4, MossdeepCity_SpaceCenter_1F_Text_Grunt4Intro, MossdeepCity_SpaceCenter_1F_Text_Grunt4Defeat
# 213 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	msgbox MossdeepCity_SpaceCenter_1F_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
# 214 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	end
# 215 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 216 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_EventScript_Grunt2::
# 217 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	lock
# 218 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	faceplayer
# 219 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	goto_if_set FLAG_DEFEATED_GRUNT_SPACE_CENTER_1F, MossdeepCity_SpaceCenter_1F_EventScript_Grunt2Defeated
# 220 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	msgbox MossdeepCity_SpaceCenter_1F_Text_Grunt2Intro, MSGBOX_DEFAULT
# 221 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	trainerbattle_no_intro TRAINER_GRUNT_SPACE_CENTER_2, MossdeepCity_SpaceCenter_1F_Text_Grunt2Defeat
# 222 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	setflag FLAG_DEFEATED_GRUNT_SPACE_CENTER_1F
# 223 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	copyobjectxytoperm LOCALID_SPACE_CENTER_1F_STAIR_GRUNT
# 224 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	switch VAR_FACING
# 225 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	case DIR_WEST, MossdeepCity_SpaceCenter_1F_EventScript_MoveGruntFromStairsWest
# 226 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
#ifdef BUGFIX
# 227 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	case DIR_EAST, MossdeepCity_SpaceCenter_1F_EventScript_MoveGruntFromStairsEast
# 228 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
#else
# 229 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	case DIR_WEST, MossdeepCity_SpaceCenter_1F_EventScript_MoveGruntFromStairsEast
# 230 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
#endif
# 231 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	applymovement LOCALID_SPACE_CENTER_1F_STAIR_GRUNT, MossdeepCity_SpaceCenter_1F_Movement_MoveGruntFromStairs
# 232 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	waitmovement 0
# 233 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	setvar VAR_MOSSDEEP_SPACE_CENTER_STAIR_GUARD_STATE, 2
# 234 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	release
# 235 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	end
# 236 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 237 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_EventScript_Grunt2Defeated::
# 238 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	msgbox MossdeepCity_SpaceCenter_1F_Text_Grunt2PostBattle, MSGBOX_DEFAULT
# 239 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	release
# 240 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	end
# 241 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 242 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_EventScript_MoveGruntFromStairsWest::
# 243 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	applymovement LOCALID_SPACE_CENTER_1F_STAIR_GRUNT, MossdeepCity_SpaceCenter_1F_Movement_MoveGruntFromStairsWest
# 244 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	waitmovement 0
# 245 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	setvar VAR_MOSSDEEP_SPACE_CENTER_STAIR_GUARD_STATE, 1
# 246 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	release
# 247 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	end
# 248 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 249 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
@ Functionally unused by mistake. The movement is handled anyway after the switch (see above)
# 250 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
@ This also means VAR_MOSSDEEP_SPACE_CENTER_STAIR_GUARD_STATE can never be 3
# 251 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_EventScript_MoveGruntFromStairsEast::
# 252 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	applymovement LOCALID_SPACE_CENTER_1F_STAIR_GRUNT, MossdeepCity_SpaceCenter_1F_Movement_MoveGruntFromStairsEast
# 253 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	waitmovement 0
# 254 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	setvar VAR_MOSSDEEP_SPACE_CENTER_STAIR_GUARD_STATE, 3
# 255 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	release
# 256 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	end
# 257 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 258 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_Movement_MoveGruntFromStairsWest:
# 259 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	lock_facing_direction
# 260 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	walk_left
# 261 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	unlock_facing_direction
# 262 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	step_end
# 263 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 264 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
@ Functionally unused. See above
# 265 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_Movement_MoveGruntFromStairsEast:
# 266 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	lock_facing_direction
# 267 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	walk_right
# 268 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	unlock_facing_direction
# 269 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	step_end
# 270 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 271 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
@ This was meant to only handle the player facing North, but by mistake(?) it also handles the player facing East
# 272 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_Movement_MoveGruntFromStairs:
# 273 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	face_left
# 274 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	lock_facing_direction
# 275 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	walk_right
# 276 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	unlock_facing_direction
# 277 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	step_end
# 278 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 279 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_Text_RocketLaunchImminent:
# 280 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "The rocket's launch is imminent!$"
# 281 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 282 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_Text_SuccessfulLaunchNumber:
# 283 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "The rocket launched safely!\n"
# 284 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "That's successful launch no. {STR_VAR_1}!$"
# 285 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 286 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_Text_HaywireButRocketLaunchImminent:
# 287 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "I know that things are a little\n"
# 288 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "haywire right now, but…\p"
# 289 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "The rocket's launch is imminent!$"
# 290 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 291 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_Text_HaywireButSuccessfulLaunchNumber:
# 292 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "I know that things are a little\n"
# 293 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "haywire right now, but…\p"
# 294 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "The rocket launched safely!\n"
# 295 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "That's successful launch no. {STR_VAR_1}!$"
# 296 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 297 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_Text_RocketLaunchDemandsPerfection:
# 298 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "A rocket launch demands perfection.\n"
# 299 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "Not even a 1% margin of error is allowed.\p"
# 300 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "Even if it's 99% okay, the whole thing\n"
# 301 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "is useless if 1% happens to be no good.\p"
# 302 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "Despite that, we never stop trying.\n"
# 303 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "Why? It's a dream that never ends.$"
# 304 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 305 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_Text_MagmaHaveSightsOnSpaceCenter:
# 306 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "Those MAGMA thugs have their sights\n"
# 307 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "set on our SPACE CENTER.\p"
# 308 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "But we can't allow anything that minor\n"
# 309 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "to interfere with our rocket launch!$"
# 310 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 311 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_Text_FoundThisYouCanHaveIt:
# 312 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "I was taking a stroll down the beach\n"
# 313 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "when I found this.\p"
# 314 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "It's not anything I need, so you can\n"
# 315 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "have it.$"
# 316 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 317 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_Text_HoennFamousForMeteorShowers:
# 318 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "The HOENN region has been famous for \n"
# 319 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "its meteor showers for a long time.$"
# 320 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 321 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_Text_MagmaCantStealFuelTakeThis:
# 322 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "TEAM MAGMA can't be allowed to steal\n"
# 323 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "the rocket fuel.\p"
# 324 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "Oh, by the way, you can have this stone\n"
# 325 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "I found on the beach.$"
# 326 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 327 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_Text_CantStrollOnBeachWithMagma:
# 328 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "With TEAM MAGMA around, I guess\n"
# 329 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "strolls on the beach aren't safe.$"
# 330 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 331 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_Text_DidPokemonComeFromSpace:
# 332 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "Some people claim that POKéMON came\n"
# 333 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "from space. Could it be true?$"
# 334 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 335 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_Text_AquaShouldBeatMagma:
# 336 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "TEAM AQUA should take care of\n"
# 337 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "TEAM MAGMA!\p"
# 338 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "But if they did that, TEAM AQUA will\n"
# 339 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "become bold and brazen, won't they?$"
# 340 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 341 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_Text_RocketsBoggleMyMind:
# 342 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "A giant chunk of metal bursts through\n"
# 343 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "the skies and flies into space…\p"
# 344 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "It boggles my mind!$"
# 345 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 346 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_Text_MagmaWantsToSpoilMyDream:
# 347 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "A giant chunk of metal bursts through\n"
# 348 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "the skies and flies into space…\p"
# 349 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "But TEAM MAGMA wants to spoil\n"
# 350 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "that dream of mine!\p"
# 351 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "I'm not having any of that!$"
# 352 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 353 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_Text_StevenMagmaCantBeAllowedToTakeFuel:
# 354 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "STEVEN: {PLAYER}{KUN}, have you read that\n"
# 355 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "proclamation already?\p"
# 356 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "TEAM MAGMA is coming after the rocket\n"
# 357 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "fuel on this island.\p"
# 358 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "I don't know what they'd need it for,\n"
# 359 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "but they can't be allowed to take it.\p"
# 360 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "I'll keep an eye on things for\n"
# 361 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "a while longer.\p"
# 362 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "In the meantime, why don't you go\n"
# 363 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "check out the town?$"
# 364 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 365 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_Text_Grunt3Intro:
# 366 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "As promised, we've come for\n"
# 367 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "the rocket fuel!$"
# 368 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 369 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_Text_Grunt3Defeat:
# 370 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "Ran out of fuel…$"
# 371 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 372 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_Text_Grunt3PostBattle:
# 373 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "Don't think you're on a roll just\n"
# 374 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "because you've beaten me!$"
# 375 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 376 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_Text_Grunt1Intro:
# 377 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "We gave you fair warning!\n"
# 378 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "There's nothing sneaky about us!$"
# 379 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 380 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_Text_Grunt1Defeat:
# 381 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "Grrr…\n"
# 382 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "We should've used sneaky treachery…$"
# 383 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 384 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_Text_Grunt1PostBattle:
# 385 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "Okay, I get it already! The next time,\n"
# 386 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "we'll come unannounced.$"
# 387 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 388 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_Text_Grunt4Intro:
# 389 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "The rocket fuel the SPACE CENTER has\n"
# 390 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "in storage--that's what we're after.\p"
# 391 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "We mean to take every last bit of it!$"
# 392 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 393 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_Text_Grunt4Defeat:
# 394 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "Please, can you spare some fuel?\n"
# 395 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "Even a chintzy cup will do!$"
# 396 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 397 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_Text_Grunt4PostBattle:
# 398 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "What are we going to do with\n"
# 399 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "the rocket fuel?\p"
# 400 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "How would I know?\n"
# 401 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "Ask our leader upstairs!$"
# 402 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 403 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_Text_Grunt2Intro:
# 404 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "Our leader said no one, but no one,\n"
# 405 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "gets past me!$"
# 406 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 407 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_Text_Grunt2Defeat:
# 408 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "Ack! Ack! Aaack!$"
# 409 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 410 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_Text_Grunt2PostBattle:
# 411 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "Please, tell our leader that\n"
# 412 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "I never abandoned my post.\l"
# 413 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "That I stayed to the bitter end…$"
# 414 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 415 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_Text_MagmaIntentToStealNotice:
# 416 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "This is…\n"
# 417 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "An intent-to-steal notice?\p"
# 418 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "“To the staff of the SPACE CENTER:\n"
# 419 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "How are you? We are doing fine.\p"
# 420 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "“We will soon visit you to take your\n"
# 421 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "rocket fuel.\p"
# 422 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "“Please don't try to stop us.\n"
# 423 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "We will take the fuel no matter what.\p"
# 424 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "“Let there be more land!\n"
# 425 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "                                          TEAM MAGMA”$"
