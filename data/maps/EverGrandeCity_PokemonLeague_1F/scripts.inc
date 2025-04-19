# 1 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"

# 2 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
.set LOCALID_NURSE, 1
# 3 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
.set LOCALID_GUARD_1, 3
# 4 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
.set LOCALID_GUARD_2, 4
# 5 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"

# 6 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
EverGrandeCity_PokemonLeague_1F_MapScripts::
# 7 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, EverGrandeCity_PokemonLeague_1F_OnTransition
# 8 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
# 9 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.byte 0
# 10 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"

# 11 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
EverGrandeCity_PokemonLeague_1F_OnTransition:
# 12 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	setrespawn HEAL_LOCATION_EVER_GRANDE_CITY_POKEMON_LEAGUE
# 13 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	setflag FLAG_LANDMARK_POKEMON_LEAGUE
# 14 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	call_if_unset FLAG_ENTERED_ELITE_FOUR, EverGrandeCity_PokemonLeague_1F_EventScript_GuardsBlockDoor
# 15 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	end
# 16 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"

# 17 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
EverGrandeCity_PokemonLeague_1F_EventScript_GuardsBlockDoor::
# 18 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	setobjectxyperm LOCALID_GUARD_1, 9, 2
# 19 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	setobjectxyperm LOCALID_GUARD_2, 10, 2
# 20 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	return
# 21 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"

# 22 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
EverGrandeCity_PokemonLeague_1F_EventScript_Nurse::
# 23 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	setvar VAR_0x800B, LOCALID_NURSE
# 24 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	call Common_EventScript_PkmnCenterNurse
# 25 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	waitmessage
# 26 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	waitbuttonpress
# 27 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	release
# 28 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	end
# 29 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"

# 30 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
EverGrandeCity_PokemonLeague_1F_EventScript_Clerk::
# 31 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	lock
# 32 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	faceplayer
# 33 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	message gText_HowMayIServeYou
# 34 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	waitmessage
# 35 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	pokemart EverGrandeCity_PokemonLeague_1F_Pokemart
# 36 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 37 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	release
# 38 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	end
# 39 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"

# 40 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.align 2
# 41 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
EverGrandeCity_PokemonLeague_1F_Pokemart:
# 42 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.2byte ITEM_ULTRA_BALL
# 43 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.2byte ITEM_HYPER_POTION
# 44 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.2byte ITEM_MAX_POTION
# 45 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.2byte ITEM_FULL_RESTORE
# 46 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.2byte ITEM_FULL_HEAL
# 47 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.2byte ITEM_REVIVE
# 48 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.2byte ITEM_MAX_REPEL
# 49 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	pokemartlistend
# 50 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"

# 51 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
@ The door guards only check for FLAG_BADGE06_GET because Winonas badge is the only one that can be skipped
# 52 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
@ Its assumed the player has the remaining badges
# 53 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
EverGrandeCity_PokemonLeague_1F_EventScript_DoorGuard::
# 54 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	lockall
# 55 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	goto_if_set FLAG_ENTERED_ELITE_FOUR, EverGrandeCity_PokemonLeague_1F_EventScript_GoForth
# 56 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
# 57 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	call_if_ge VAR_TEMP_0, 11, EverGrandeCity_PokemonLeague_1F_EventScript_PlayerMoveToFrontFromRight
# 58 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	call_if_le VAR_TEMP_0, 8, EverGrandeCity_PokemonLeague_1F_EventScript_PlayerMoveToFrontFromLeft
# 59 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	message EverGrandeCity_PokemonLeague_1F_Text_MustHaveAllGymBadges
# 60 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	waitmessage
# 61 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	delay 120
# 62 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	goto_if_unset FLAG_BADGE06_GET, EverGrandeCity_PokemonLeague_1F_EventScript_NotAllBadges
# 63 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	closemessage
# 64 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	applymovement LOCALID_GUARD_1, EverGrandeCity_PokemonLeague_1F_Movement_LeftGuardOutOfWay
# 65 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	applymovement LOCALID_GUARD_2, EverGrandeCity_PokemonLeague_1F_Movement_RightGuardOutOfWay
# 66 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	waitmovement 0
# 67 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	delay 10
# 68 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	playfanfare MUS_OBTAIN_BADGE
# 69 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	message EverGrandeCity_PokemonLeague_1F_Text_GoForth
# 70 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	waitmessage
# 71 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	waitfanfare
# 72 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	closemessage
# 73 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	copyobjectxytoperm LOCALID_GUARD_1
# 74 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	copyobjectxytoperm LOCALID_GUARD_2
# 75 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	setflag FLAG_ENTERED_ELITE_FOUR
# 76 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	releaseall
# 77 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	end
# 78 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"

# 79 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
EverGrandeCity_PokemonLeague_1F_EventScript_PlayerMoveToFrontFromRight::
# 80 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, EverGrandeCity_PokemonLeague_1F_Movement_MoveToFrontFromRight
# 81 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	waitmovement 0
# 82 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	return
# 83 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"

# 84 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
EverGrandeCity_PokemonLeague_1F_EventScript_PlayerMoveToFrontFromLeft::
# 85 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, EverGrandeCity_PokemonLeague_1F_Movement_MoveToFrontFromLeft
# 86 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	waitmovement 0
# 87 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	return
# 88 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"

# 89 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
EverGrandeCity_PokemonLeague_1F_EventScript_NotAllBadges::
# 90 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	playse SE_FAILURE
# 91 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	msgbox EverGrandeCity_PokemonLeague_1F_Text_HaventObtainedAllBadges, MSGBOX_DEFAULT
# 92 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	releaseall
# 93 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	end
# 94 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"

# 95 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
EverGrandeCity_PokemonLeague_1F_EventScript_GoForth::
# 96 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
# 97 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	waitmovement 0
# 98 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	msgbox EverGrandeCity_PokemonLeague_1F_Text_GoForth, MSGBOX_DEFAULT
# 99 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	closemessage
# 100 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 101 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	waitmovement 0
# 102 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	releaseall
# 103 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	end
# 104 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"

# 105 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
EverGrandeCity_PokemonLeague_1F_Movement_MoveToFrontFromRight:
# 106 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	walk_down
# 107 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	walk_left
# 108 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	walk_in_place_faster_up
# 109 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	step_end
# 110 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"

# 111 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
EverGrandeCity_PokemonLeague_1F_Movement_MoveToFrontFromLeft:
# 112 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	walk_down
# 113 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	walk_right
# 114 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	walk_in_place_faster_up
# 115 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	step_end
# 116 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"

# 117 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
EverGrandeCity_PokemonLeague_1F_Movement_LeftGuardOutOfWay:
# 118 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	walk_left
# 119 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	walk_in_place_faster_down
# 120 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	step_end
# 121 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"

# 122 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
EverGrandeCity_PokemonLeague_1F_Movement_RightGuardOutOfWay:
# 123 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	walk_right
# 124 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	walk_in_place_faster_down
# 125 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	step_end
# 126 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"

# 127 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
EverGrandeCity_PokemonLeague_1F_Text_MustHaveAllGymBadges:
# 128 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.string "Beyond this point, only those TRAINERS\n"
# 129 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.string "who have collected all the GYM BADGES\l"
# 130 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.string "are permitted to enter.\p"
# 131 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.string "TRAINER, let us confirm that you have\n"
# 132 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.string "all the GYM BADGES.$"
# 133 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"

# 134 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
EverGrandeCity_PokemonLeague_1F_Text_HaventObtainedAllBadges:
# 135 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.string "You haven't obtained all the BADGES.\p"
# 136 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.string "If you're bound for the POKéMON\n"
# 137 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.string "LEAGUE, you must return with them.$"
# 138 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"

# 139 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
EverGrandeCity_PokemonLeague_1F_Text_GoForth:
# 140 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.string "TRAINER! Believe in yourself and your\n"
# 141 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.string "POKéMON, and go forth!$"
