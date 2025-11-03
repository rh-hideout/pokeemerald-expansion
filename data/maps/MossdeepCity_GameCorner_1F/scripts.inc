# 1 "data/maps/MossdeepCity_GameCorner_1F/scripts.pory"

# 2 "data/maps/MossdeepCity_GameCorner_1F/scripts.pory"
MossdeepCity_GameCorner_1F_MapScripts::
# 3 "data/maps/MossdeepCity_GameCorner_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MossdeepCity_GameCorner_1F_OnFrame
# 4 "data/maps/MossdeepCity_GameCorner_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, MossdeepCity_GameCorner_1F_OnWarp
# 5 "data/maps/MossdeepCity_GameCorner_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, CableClub_OnLoad
# 6 "data/maps/MossdeepCity_GameCorner_1F/scripts.pory"
	.byte 0
# 7 "data/maps/MossdeepCity_GameCorner_1F/scripts.pory"

# 8 "data/maps/MossdeepCity_GameCorner_1F/scripts.pory"
MossdeepCity_GameCorner_1F_OnWarp:
# 9 "data/maps/MossdeepCity_GameCorner_1F/scripts.pory"
	map_script_2 VAR_CABLE_CLUB_STATE, USING_MINIGAME, CableClub_EventScript_CheckTurnAttendant
# 10 "data/maps/MossdeepCity_GameCorner_1F/scripts.pory"
	.2byte 0
# 11 "data/maps/MossdeepCity_GameCorner_1F/scripts.pory"

# 12 "data/maps/MossdeepCity_GameCorner_1F/scripts.pory"
MossdeepCity_GameCorner_1F_OnFrame:
# 13 "data/maps/MossdeepCity_GameCorner_1F/scripts.pory"
	map_script_2 VAR_CABLE_CLUB_STATE, USING_MINIGAME, CableClub_EventScript_ExitMinigameRoom
# 14 "data/maps/MossdeepCity_GameCorner_1F/scripts.pory"
	.2byte 0
# 15 "data/maps/MossdeepCity_GameCorner_1F/scripts.pory"

# 16 "data/maps/MossdeepCity_GameCorner_1F/scripts.pory"
@ Script is redundant, the label in the goto also does lock and faceplayer
# 17 "data/maps/MossdeepCity_GameCorner_1F/scripts.pory"
MossdeepCity_GameCorner_1F_EventScript_InfoMan::
# 18 "data/maps/MossdeepCity_GameCorner_1F/scripts.pory"
	lock
# 19 "data/maps/MossdeepCity_GameCorner_1F/scripts.pory"
	faceplayer
# 20 "data/maps/MossdeepCity_GameCorner_1F/scripts.pory"
	goto MossdeepCity_GameCorner_1F_EventScript_InfoMan2
# 21 "data/maps/MossdeepCity_GameCorner_1F/scripts.pory"
	release
# 22 "data/maps/MossdeepCity_GameCorner_1F/scripts.pory"
	end
# 23 "data/maps/MossdeepCity_GameCorner_1F/scripts.pory"

# 24 "data/maps/MossdeepCity_GameCorner_1F/scripts.pory"
@ Script is redundant, the label in the goto also does lock and faceplayer
# 25 "data/maps/MossdeepCity_GameCorner_1F/scripts.pory"
MossdeepCity_GameCorner_1F_EventScript_OldMan::
# 26 "data/maps/MossdeepCity_GameCorner_1F/scripts.pory"
	lock
# 27 "data/maps/MossdeepCity_GameCorner_1F/scripts.pory"
	faceplayer
# 28 "data/maps/MossdeepCity_GameCorner_1F/scripts.pory"
	goto MossdeepCity_GameCorner_1F_EventScript_OldMan2
# 29 "data/maps/MossdeepCity_GameCorner_1F/scripts.pory"
	release
# 30 "data/maps/MossdeepCity_GameCorner_1F/scripts.pory"
	end
# 31 "data/maps/MossdeepCity_GameCorner_1F/scripts.pory"

# 32 "data/maps/MossdeepCity_GameCorner_1F/scripts.pory"

# 33 "data/maps/MossdeepCity_GameCorner_1F/scripts.pory"
@ Everything below is leftover from RS
# 34 "data/maps/MossdeepCity_GameCorner_1F/scripts.pory"
@ The house that was here in RS was moved to Sootopolis and replaced by the Game Corner
# 35 "data/maps/MossdeepCity_GameCorner_1F/scripts.pory"
@ The text below is unused and duplicated in its replacement in Sootopolis City
# 36 "data/maps/MossdeepCity_GameCorner_1F/scripts.pory"
@ And the BG Door event was moved inaccessibly into a wall
# 37 "data/maps/MossdeepCity_GameCorner_1F/scripts.pory"

# 38 "data/maps/MossdeepCity_GameCorner_1F/scripts.pory"
RS_MysteryEventsHouse_EventScript_Door::
# 39 "data/maps/MossdeepCity_GameCorner_1F/scripts.pory"
	msgbox RS_MysteryEventsHouse_Text_DoorIsLocked, MSGBOX_SIGN
# 40 "data/maps/MossdeepCity_GameCorner_1F/scripts.pory"
	end
# 41 "data/maps/MossdeepCity_GameCorner_1F/scripts.pory"

# 42 "data/maps/MossdeepCity_GameCorner_1F/scripts.pory"
RS_MysteryEventsHouse_Text_OldManGreeting:
# 43 "data/maps/MossdeepCity_GameCorner_1F/scripts.pory"
	.string "When I was young, I traveled the world\n"
# 44 "data/maps/MossdeepCity_GameCorner_1F/scripts.pory"
	.string "as a POKéMON TRAINER.\p"
# 45 "data/maps/MossdeepCity_GameCorner_1F/scripts.pory"
	.string "Now that I've become an old buzzard,\n"
# 46 "data/maps/MossdeepCity_GameCorner_1F/scripts.pory"
	.string "my only amusement is watching young\l"
# 47 "data/maps/MossdeepCity_GameCorner_1F/scripts.pory"
	.string "TRAINERS battle.$"
# 48 "data/maps/MossdeepCity_GameCorner_1F/scripts.pory"

# 49 "data/maps/MossdeepCity_GameCorner_1F/scripts.pory"
RS_MysteryEventsHouse_Text_DoorIsLocked:
# 50 "data/maps/MossdeepCity_GameCorner_1F/scripts.pory"
	.string "The door appears to be locked.$"
# 51 "data/maps/MossdeepCity_GameCorner_1F/scripts.pory"

# 52 "data/maps/MossdeepCity_GameCorner_1F/scripts.pory"
RS_MysteryEventsHouse_Text_ChallengeVisitingTrainer:
# 53 "data/maps/MossdeepCity_GameCorner_1F/scripts.pory"
	.string "A TRAINER named {STR_VAR_1} is\n"
# 54 "data/maps/MossdeepCity_GameCorner_1F/scripts.pory"
	.string "visiting my home.\p"
# 55 "data/maps/MossdeepCity_GameCorner_1F/scripts.pory"
	.string "Would you like to challenge\n"
# 56 "data/maps/MossdeepCity_GameCorner_1F/scripts.pory"
	.string "{STR_VAR_1}?$"
# 57 "data/maps/MossdeepCity_GameCorner_1F/scripts.pory"

# 58 "data/maps/MossdeepCity_GameCorner_1F/scripts.pory"
RS_MysteryEventsHouse_Text_YouWontBattle:
# 59 "data/maps/MossdeepCity_GameCorner_1F/scripts.pory"
	.string "You won't battle? I'm disappointed\n"
# 60 "data/maps/MossdeepCity_GameCorner_1F/scripts.pory"
	.string "that I can't see you battle…$"
# 61 "data/maps/MossdeepCity_GameCorner_1F/scripts.pory"

# 62 "data/maps/MossdeepCity_GameCorner_1F/scripts.pory"
RS_MysteryEventsHouse_Text_KeepItToA3On3:
# 63 "data/maps/MossdeepCity_GameCorner_1F/scripts.pory"
	.string "Oh, good, good!\p"
# 64 "data/maps/MossdeepCity_GameCorner_1F/scripts.pory"
	.string "But my house isn't all that sturdy.\p"
# 65 "data/maps/MossdeepCity_GameCorner_1F/scripts.pory"
	.string "Could I ask you to keep it down to\n"
# 66 "data/maps/MossdeepCity_GameCorner_1F/scripts.pory"
	.string "a 3-on-3 match?$"
# 67 "data/maps/MossdeepCity_GameCorner_1F/scripts.pory"

# 68 "data/maps/MossdeepCity_GameCorner_1F/scripts.pory"
RS_MysteryEventsHouse_Text_SaveYourProgress:
# 69 "data/maps/MossdeepCity_GameCorner_1F/scripts.pory"
	.string "Before you two battle, you should\n"
# 70 "data/maps/MossdeepCity_GameCorner_1F/scripts.pory"
	.string "save your progress.$"
# 71 "data/maps/MossdeepCity_GameCorner_1F/scripts.pory"

# 72 "data/maps/MossdeepCity_GameCorner_1F/scripts.pory"
RS_MysteryEventsHouse_Text_HopeToSeeAGoodMatch:
# 73 "data/maps/MossdeepCity_GameCorner_1F/scripts.pory"
	.string "I hope to see a good match!$"
# 74 "data/maps/MossdeepCity_GameCorner_1F/scripts.pory"

# 75 "data/maps/MossdeepCity_GameCorner_1F/scripts.pory"
RS_MysteryEventsHouse_Text_BattleTie:
# 76 "data/maps/MossdeepCity_GameCorner_1F/scripts.pory"
	.string "So, it became a standoff.\p"
# 77 "data/maps/MossdeepCity_GameCorner_1F/scripts.pory"
	.string "It was a brilliant match in which\n"
# 78 "data/maps/MossdeepCity_GameCorner_1F/scripts.pory"
	.string "neither side conceded a step!$"
# 79 "data/maps/MossdeepCity_GameCorner_1F/scripts.pory"

# 80 "data/maps/MossdeepCity_GameCorner_1F/scripts.pory"
RS_MysteryEventsHouse_Text_BattleWon:
# 81 "data/maps/MossdeepCity_GameCorner_1F/scripts.pory"
	.string "That was superlative!\p"
# 82 "data/maps/MossdeepCity_GameCorner_1F/scripts.pory"
	.string "Why, it was like seeing myself in\n"
# 83 "data/maps/MossdeepCity_GameCorner_1F/scripts.pory"
	.string "my youth again!$"
# 84 "data/maps/MossdeepCity_GameCorner_1F/scripts.pory"

# 85 "data/maps/MossdeepCity_GameCorner_1F/scripts.pory"
RS_MysteryEventsHouse_Text_BattleLost:
# 86 "data/maps/MossdeepCity_GameCorner_1F/scripts.pory"
	.string "Ah, too bad for you!\p"
# 87 "data/maps/MossdeepCity_GameCorner_1F/scripts.pory"
	.string "But it was a good match.\n"
# 88 "data/maps/MossdeepCity_GameCorner_1F/scripts.pory"
	.string "I hope you can win next time.$"
