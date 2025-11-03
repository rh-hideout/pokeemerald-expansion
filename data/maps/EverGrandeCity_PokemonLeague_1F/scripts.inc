# 1 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"

# 2 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
EverGrandeCity_PokemonLeague_1F_MapScripts::
# 3 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, EverGrandeCity_PokemonLeague_1F_OnTransition
# 4 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
# 5 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.byte 0
# 6 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"

# 7 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
EverGrandeCity_PokemonLeague_1F_OnTransition:
# 8 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	setrespawn HEAL_LOCATION_EVER_GRANDE_CITY_POKEMON_LEAGUE
# 9 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	setflag FLAG_LANDMARK_POKEMON_LEAGUE
# 10 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	call_if_unset FLAG_ENTERED_ELITE_FOUR, EverGrandeCity_PokemonLeague_1F_EventScript_GuardsBlockDoor
# 11 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	end
# 12 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"

# 13 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
EverGrandeCity_PokemonLeague_1F_EventScript_GuardsBlockDoor::
# 14 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	setobjectxyperm LOCALID_LEAGUE_GUARD_1, 9, 2
# 15 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	setobjectxyperm LOCALID_LEAGUE_GUARD_2, 10, 2
# 16 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	return
# 17 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"

# 18 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
EverGrandeCity_PokemonLeague_1F_EventScript_Nurse::
# 19 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	setvar VAR_0x800B, LOCALID_LEAGUE_NURSE
# 20 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	call Common_EventScript_PkmnCenterNurse
# 21 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	waitmessage
# 22 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	waitbuttonpress
# 23 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	release
# 24 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	end
# 25 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"

# 26 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
EverGrandeCity_PokemonLeague_1F_EventScript_Clerk::
# 27 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	lock
# 28 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	faceplayer
# 29 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	message gText_HowMayIServeYou
# 30 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	waitmessage
# 31 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	pokemart EverGrandeCity_PokemonLeague_1F_Pokemart
# 32 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 33 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	release
# 34 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	end
# 35 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"

# 36 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.align 2
# 37 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
EverGrandeCity_PokemonLeague_1F_Pokemart:
# 38 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.2byte ITEM_ULTRA_BALL
# 39 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.2byte ITEM_HYPER_POTION
# 40 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.2byte ITEM_MAX_POTION
# 41 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.2byte ITEM_FULL_RESTORE
# 42 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.2byte ITEM_FULL_HEAL
# 43 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.2byte ITEM_REVIVE
# 44 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.2byte ITEM_MAX_REPEL
# 45 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	pokemartlistend
# 46 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"

# 47 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
@ The door guards only check for FLAG_BADGE06_GET because Winonas badge is the only one that can be skipped
# 48 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
@ Its assumed the player has the remaining badges
# 49 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
EverGrandeCity_PokemonLeague_1F_EventScript_DoorGuard::
# 50 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	lockall
# 51 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	goto_if_set FLAG_ENTERED_ELITE_FOUR, EverGrandeCity_PokemonLeague_1F_EventScript_GoForth
# 52 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
# 53 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	call_if_ge VAR_TEMP_0, 11, EverGrandeCity_PokemonLeague_1F_EventScript_PlayerMoveToFrontFromRight
# 54 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	call_if_le VAR_TEMP_0, 8, EverGrandeCity_PokemonLeague_1F_EventScript_PlayerMoveToFrontFromLeft
# 55 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	message EverGrandeCity_PokemonLeague_1F_Text_MustHaveAllGymBadges
# 56 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	waitmessage
# 57 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	delay 120
# 58 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	goto_if_unset FLAG_BADGE06_GET, EverGrandeCity_PokemonLeague_1F_EventScript_NotAllBadges
# 59 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	closemessage
# 60 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	applymovement LOCALID_LEAGUE_GUARD_1, EverGrandeCity_PokemonLeague_1F_Movement_LeftGuardOutOfWay
# 61 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	applymovement LOCALID_LEAGUE_GUARD_2, EverGrandeCity_PokemonLeague_1F_Movement_RightGuardOutOfWay
# 62 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	waitmovement 0
# 63 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	delay 10
# 64 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	playfanfare MUS_OBTAIN_BADGE
# 65 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	message EverGrandeCity_PokemonLeague_1F_Text_GoForth
# 66 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	waitmessage
# 67 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	waitfanfare
# 68 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	closemessage
# 69 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	copyobjectxytoperm LOCALID_LEAGUE_GUARD_1
# 70 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	copyobjectxytoperm LOCALID_LEAGUE_GUARD_2
# 71 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	setflag FLAG_ENTERED_ELITE_FOUR
# 72 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	releaseall
# 73 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	end
# 74 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"

# 75 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
EverGrandeCity_PokemonLeague_1F_EventScript_PlayerMoveToFrontFromRight::
# 76 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	applymovement LOCALID_PLAYER, EverGrandeCity_PokemonLeague_1F_Movement_MoveToFrontFromRight
# 77 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	waitmovement 0
# 78 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	return
# 79 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"

# 80 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
EverGrandeCity_PokemonLeague_1F_EventScript_PlayerMoveToFrontFromLeft::
# 81 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	applymovement LOCALID_PLAYER, EverGrandeCity_PokemonLeague_1F_Movement_MoveToFrontFromLeft
# 82 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	waitmovement 0
# 83 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	return
# 84 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"

# 85 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
EverGrandeCity_PokemonLeague_1F_EventScript_NotAllBadges::
# 86 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	playse SE_FAILURE
# 87 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	msgbox EverGrandeCity_PokemonLeague_1F_Text_HaventObtainedAllBadges, MSGBOX_DEFAULT
# 88 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	releaseall
# 89 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	end
# 90 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"

# 91 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
EverGrandeCity_PokemonLeague_1F_EventScript_GoForth::
# 92 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
# 93 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	waitmovement 0
# 94 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	msgbox EverGrandeCity_PokemonLeague_1F_Text_GoForth, MSGBOX_DEFAULT
# 95 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	closemessage
# 96 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 97 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	waitmovement 0
# 98 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	releaseall
# 99 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	end
# 100 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"

# 101 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
EverGrandeCity_PokemonLeague_1F_Movement_MoveToFrontFromRight:
# 102 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	walk_down
# 103 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	walk_left
# 104 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	walk_in_place_faster_up
# 105 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	step_end
# 106 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"

# 107 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
EverGrandeCity_PokemonLeague_1F_Movement_MoveToFrontFromLeft:
# 108 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	walk_down
# 109 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	walk_right
# 110 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	walk_in_place_faster_up
# 111 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	step_end
# 112 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"

# 113 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
EverGrandeCity_PokemonLeague_1F_Movement_LeftGuardOutOfWay:
# 114 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	walk_left
# 115 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	walk_in_place_faster_down
# 116 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	step_end
# 117 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"

# 118 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
EverGrandeCity_PokemonLeague_1F_Movement_RightGuardOutOfWay:
# 119 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	walk_right
# 120 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	walk_in_place_faster_down
# 121 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	step_end
# 122 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"

# 123 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
EverGrandeCity_PokemonLeague_1F_Text_MustHaveAllGymBadges:
# 124 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.string "Beyond this point, only those TRAINERS\n"
# 125 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.string "who have collected all the GYM BADGES\l"
# 126 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.string "are permitted to enter.\p"
# 127 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.string "TRAINER, let us confirm that you have\n"
# 128 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.string "all the GYM BADGES.$"
# 129 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"

# 130 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
EverGrandeCity_PokemonLeague_1F_Text_HaventObtainedAllBadges:
# 131 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.string "You haven't obtained all the BADGES.\p"
# 132 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.string "If you're bound for the POKéMON\n"
# 133 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.string "LEAGUE, you must return with them.$"
# 134 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"

# 135 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
EverGrandeCity_PokemonLeague_1F_Text_GoForth:
# 136 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.string "TRAINER! Believe in yourself and your\n"
# 137 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.string "POKéMON, and go forth!$"
