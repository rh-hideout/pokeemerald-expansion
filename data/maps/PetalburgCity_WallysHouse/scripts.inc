# 1 "data/maps/PetalburgCity_WallysHouse/scripts.pory"

# 2 "data/maps/PetalburgCity_WallysHouse/scripts.pory"
PetalburgCity_WallysHouse_MapScripts::
# 3 "data/maps/PetalburgCity_WallysHouse/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PetalburgCity_WallysHouse_OnFrame
# 4 "data/maps/PetalburgCity_WallysHouse/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, PetalburgCity_WallysHouse_OnWarp
# 5 "data/maps/PetalburgCity_WallysHouse/scripts.pory"
	.byte 0
# 6 "data/maps/PetalburgCity_WallysHouse/scripts.pory"

# 7 "data/maps/PetalburgCity_WallysHouse/scripts.pory"
PetalburgCity_WallysHouse_OnWarp:
# 8 "data/maps/PetalburgCity_WallysHouse/scripts.pory"
	map_script_2 VAR_PETALBURG_CITY_STATE, 4, PetalburgCity_WallysHouse_EventScript_PlayerWallysDadFaceEachOther
# 9 "data/maps/PetalburgCity_WallysHouse/scripts.pory"
	.2byte 0
# 10 "data/maps/PetalburgCity_WallysHouse/scripts.pory"

# 11 "data/maps/PetalburgCity_WallysHouse/scripts.pory"
PetalburgCity_WallysHouse_EventScript_PlayerWallysDadFaceEachOther::
# 12 "data/maps/PetalburgCity_WallysHouse/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_EAST
# 13 "data/maps/PetalburgCity_WallysHouse/scripts.pory"
	turnobject LOCALID_WALLYS_HOUSE_WALLYS_DAD, DIR_WEST
# 14 "data/maps/PetalburgCity_WallysHouse/scripts.pory"
	end
# 15 "data/maps/PetalburgCity_WallysHouse/scripts.pory"

# 16 "data/maps/PetalburgCity_WallysHouse/scripts.pory"
PetalburgCity_WallysHouse_OnFrame:
# 17 "data/maps/PetalburgCity_WallysHouse/scripts.pory"
	map_script_2 VAR_PETALBURG_CITY_STATE, 4, PetalburgCity_WallysHouse_EventScript_GiveHMSurf
# 18 "data/maps/PetalburgCity_WallysHouse/scripts.pory"
	.2byte 0
# 19 "data/maps/PetalburgCity_WallysHouse/scripts.pory"

# 20 "data/maps/PetalburgCity_WallysHouse/scripts.pory"
PetalburgCity_WallysHouse_EventScript_GiveHMSurf::
# 21 "data/maps/PetalburgCity_WallysHouse/scripts.pory"
	lockall
# 22 "data/maps/PetalburgCity_WallysHouse/scripts.pory"
	msgbox PetalburgCity_WallysHouse_Text_PleaseExcuseUs, MSGBOX_DEFAULT
# 23 "data/maps/PetalburgCity_WallysHouse/scripts.pory"
	giveitem ITEM_HM_SURF
# 24 "data/maps/PetalburgCity_WallysHouse/scripts.pory"
	setflag FLAG_RECEIVED_HM_SURF
# 25 "data/maps/PetalburgCity_WallysHouse/scripts.pory"
	msgbox PetalburgCity_WallysHouse_Text_SurfGoAllSortsOfPlaces, MSGBOX_DEFAULT
# 26 "data/maps/PetalburgCity_WallysHouse/scripts.pory"
	setvar VAR_PETALBURG_CITY_STATE, 5
# 27 "data/maps/PetalburgCity_WallysHouse/scripts.pory"
	releaseall
# 28 "data/maps/PetalburgCity_WallysHouse/scripts.pory"
	end
# 29 "data/maps/PetalburgCity_WallysHouse/scripts.pory"

# 30 "data/maps/PetalburgCity_WallysHouse/scripts.pory"
PetalburgCity_WallysHouse_EventScript_WallysDad::
# 31 "data/maps/PetalburgCity_WallysHouse/scripts.pory"
	lock
# 32 "data/maps/PetalburgCity_WallysHouse/scripts.pory"
	faceplayer
# 33 "data/maps/PetalburgCity_WallysHouse/scripts.pory"
	goto_if_set FLAG_DEFEATED_WALLY_VICTORY_ROAD, PetalburgCity_WallysHouse_EventScript_DefeatedWallyInVictoryRoad
# 34 "data/maps/PetalburgCity_WallysHouse/scripts.pory"
	goto_if_set FLAG_RECEIVED_HM_SURF, PetalburgCity_WallysHouse_EventScript_ReceievedHMSurf
# 35 "data/maps/PetalburgCity_WallysHouse/scripts.pory"
	goto_if_set FLAG_THANKED_FOR_PLAYING_WITH_WALLY, PetalburgCity_WallysHouse_EventScript_PlayedWithWally
# 36 "data/maps/PetalburgCity_WallysHouse/scripts.pory"
	msgbox PetalburgCity_WallysHouse_Text_ThanksForPlayingWithWally, MSGBOX_DEFAULT
# 37 "data/maps/PetalburgCity_WallysHouse/scripts.pory"
	setflag FLAG_THANKED_FOR_PLAYING_WITH_WALLY
# 38 "data/maps/PetalburgCity_WallysHouse/scripts.pory"
	release
# 39 "data/maps/PetalburgCity_WallysHouse/scripts.pory"
	end
# 40 "data/maps/PetalburgCity_WallysHouse/scripts.pory"

# 41 "data/maps/PetalburgCity_WallysHouse/scripts.pory"
PetalburgCity_WallysHouse_EventScript_ReceievedHMSurf::
# 42 "data/maps/PetalburgCity_WallysHouse/scripts.pory"
	msgbox PetalburgCity_WallysHouse_Text_WallyIsComingHomeSoon, MSGBOX_DEFAULT
# 43 "data/maps/PetalburgCity_WallysHouse/scripts.pory"
	release
# 44 "data/maps/PetalburgCity_WallysHouse/scripts.pory"
	end
# 45 "data/maps/PetalburgCity_WallysHouse/scripts.pory"

# 46 "data/maps/PetalburgCity_WallysHouse/scripts.pory"
PetalburgCity_WallysHouse_EventScript_DefeatedWallyInVictoryRoad::
# 47 "data/maps/PetalburgCity_WallysHouse/scripts.pory"
	msgbox PetalburgCity_WallysHouse_Text_YouMetWallyInEverGrandeCity, MSGBOX_DEFAULT
# 48 "data/maps/PetalburgCity_WallysHouse/scripts.pory"
	release
# 49 "data/maps/PetalburgCity_WallysHouse/scripts.pory"
	end
# 50 "data/maps/PetalburgCity_WallysHouse/scripts.pory"

# 51 "data/maps/PetalburgCity_WallysHouse/scripts.pory"
PetalburgCity_WallysHouse_EventScript_PlayedWithWally::
# 52 "data/maps/PetalburgCity_WallysHouse/scripts.pory"
	msgbox PetalburgCity_WallysHouse_Text_WonderHowWallyIsDoing, MSGBOX_DEFAULT
# 53 "data/maps/PetalburgCity_WallysHouse/scripts.pory"
	release
# 54 "data/maps/PetalburgCity_WallysHouse/scripts.pory"
	end
# 55 "data/maps/PetalburgCity_WallysHouse/scripts.pory"

# 56 "data/maps/PetalburgCity_WallysHouse/scripts.pory"
PetalburgCity_WallysHouse_EventScript_WallysMom::
# 57 "data/maps/PetalburgCity_WallysHouse/scripts.pory"
	lock
# 58 "data/maps/PetalburgCity_WallysHouse/scripts.pory"
	faceplayer
# 59 "data/maps/PetalburgCity_WallysHouse/scripts.pory"
	goto_if_set FLAG_RECEIVED_HM_SURF, PetalburgCity_WallysHouse_EventScript_ReceivedHMSurf
# 60 "data/maps/PetalburgCity_WallysHouse/scripts.pory"
	msgbox PetalburgCity_WallysHouse_Text_WallyWasReallyHappy, MSGBOX_DEFAULT
# 61 "data/maps/PetalburgCity_WallysHouse/scripts.pory"
	release
# 62 "data/maps/PetalburgCity_WallysHouse/scripts.pory"
	end
# 63 "data/maps/PetalburgCity_WallysHouse/scripts.pory"

# 64 "data/maps/PetalburgCity_WallysHouse/scripts.pory"
PetalburgCity_WallysHouse_EventScript_ReceivedHMSurf::
# 65 "data/maps/PetalburgCity_WallysHouse/scripts.pory"
	msgbox PetalburgCity_WallysHouse_Text_WallyLeftWithoutTelling, MSGBOX_DEFAULT
# 66 "data/maps/PetalburgCity_WallysHouse/scripts.pory"
	release
# 67 "data/maps/PetalburgCity_WallysHouse/scripts.pory"
	end
# 68 "data/maps/PetalburgCity_WallysHouse/scripts.pory"

# 69 "data/maps/PetalburgCity_WallysHouse/scripts.pory"
PetalburgCity_WallysHouse_Text_ThanksForPlayingWithWally:
# 70 "data/maps/PetalburgCity_WallysHouse/scripts.pory"
	.string "You're…\n"
# 71 "data/maps/PetalburgCity_WallysHouse/scripts.pory"
	.string "Ah, you must be {PLAYER}{KUN}, right?\p"
# 72 "data/maps/PetalburgCity_WallysHouse/scripts.pory"
	.string "Thank you for playing with WALLY a\n"
# 73 "data/maps/PetalburgCity_WallysHouse/scripts.pory"
	.string "little while ago.\p"
# 74 "data/maps/PetalburgCity_WallysHouse/scripts.pory"
	.string "He's been frail and sickly ever\n"
# 75 "data/maps/PetalburgCity_WallysHouse/scripts.pory"
	.string "since he was a baby.\p"
# 76 "data/maps/PetalburgCity_WallysHouse/scripts.pory"
	.string "We've sent him to stay with my relatives\n"
# 77 "data/maps/PetalburgCity_WallysHouse/scripts.pory"
	.string "in VERDANTURF TOWN for a while.\p"
# 78 "data/maps/PetalburgCity_WallysHouse/scripts.pory"
	.string "The air is a lot cleaner there\n"
# 79 "data/maps/PetalburgCity_WallysHouse/scripts.pory"
	.string "than it is here.\p"
# 80 "data/maps/PetalburgCity_WallysHouse/scripts.pory"
	.string "What's that? Where's WALLY?\n"
# 81 "data/maps/PetalburgCity_WallysHouse/scripts.pory"
	.string "He's already left, our WALLY.\p"
# 82 "data/maps/PetalburgCity_WallysHouse/scripts.pory"
	.string "I wonder where he could have\n"
# 83 "data/maps/PetalburgCity_WallysHouse/scripts.pory"
	.string "gotten by now?$"
# 84 "data/maps/PetalburgCity_WallysHouse/scripts.pory"

# 85 "data/maps/PetalburgCity_WallysHouse/scripts.pory"
PetalburgCity_WallysHouse_Text_WonderHowWallyIsDoing:
# 86 "data/maps/PetalburgCity_WallysHouse/scripts.pory"
	.string "I wonder how our WALLY is doing?$"
# 87 "data/maps/PetalburgCity_WallysHouse/scripts.pory"

# 88 "data/maps/PetalburgCity_WallysHouse/scripts.pory"
PetalburgCity_WallysHouse_Text_PleaseExcuseUs:
# 89 "data/maps/PetalburgCity_WallysHouse/scripts.pory"
	.string "{PLAYER}{KUN}! Please excuse us for\n"
# 90 "data/maps/PetalburgCity_WallysHouse/scripts.pory"
	.string "dragging you here this way.\p"
# 91 "data/maps/PetalburgCity_WallysHouse/scripts.pory"
	.string "But our WALLY's become very healthy\n"
# 92 "data/maps/PetalburgCity_WallysHouse/scripts.pory"
	.string "since he went to VERDANTURF TOWN.\p"
# 93 "data/maps/PetalburgCity_WallysHouse/scripts.pory"
	.string "We owe it all to you!\p"
# 94 "data/maps/PetalburgCity_WallysHouse/scripts.pory"
	.string "When WALLY left town, you helped\n"
# 95 "data/maps/PetalburgCity_WallysHouse/scripts.pory"
	.string "him catch a POKéMON, right?\p"
# 96 "data/maps/PetalburgCity_WallysHouse/scripts.pory"
	.string "I think that made WALLY really\n"
# 97 "data/maps/PetalburgCity_WallysHouse/scripts.pory"
	.string "happy.\p"
# 98 "data/maps/PetalburgCity_WallysHouse/scripts.pory"
	.string "Actually, not just WALLY.\n"
# 99 "data/maps/PetalburgCity_WallysHouse/scripts.pory"
	.string "It made me, his father, happy too.\p"
# 100 "data/maps/PetalburgCity_WallysHouse/scripts.pory"
	.string "Happy that he's gained such a great\n"
# 101 "data/maps/PetalburgCity_WallysHouse/scripts.pory"
	.string "friend as you.\p"
# 102 "data/maps/PetalburgCity_WallysHouse/scripts.pory"
	.string "This isn't a bribe or anything, but\n"
# 103 "data/maps/PetalburgCity_WallysHouse/scripts.pory"
	.string "I'd really like you to have this.$"
# 104 "data/maps/PetalburgCity_WallysHouse/scripts.pory"

# 105 "data/maps/PetalburgCity_WallysHouse/scripts.pory"
PetalburgCity_WallysHouse_Text_SurfGoAllSortsOfPlaces:
# 106 "data/maps/PetalburgCity_WallysHouse/scripts.pory"
	.string "If your POKéMON can SURF, you'll be\n"
# 107 "data/maps/PetalburgCity_WallysHouse/scripts.pory"
	.string "able to go to all sorts of places.$"
# 108 "data/maps/PetalburgCity_WallysHouse/scripts.pory"

# 109 "data/maps/PetalburgCity_WallysHouse/scripts.pory"
PetalburgCity_WallysHouse_Text_WallyIsComingHomeSoon:
# 110 "data/maps/PetalburgCity_WallysHouse/scripts.pory"
	.string "WALLY's coming home soon.\n"
# 111 "data/maps/PetalburgCity_WallysHouse/scripts.pory"
	.string "I'm looking forward to that.$"
# 112 "data/maps/PetalburgCity_WallysHouse/scripts.pory"

# 113 "data/maps/PetalburgCity_WallysHouse/scripts.pory"
PetalburgCity_WallysHouse_Text_YouMetWallyInEverGrandeCity:
# 114 "data/maps/PetalburgCity_WallysHouse/scripts.pory"
	.string "Oh? You met WALLY in\n"
# 115 "data/maps/PetalburgCity_WallysHouse/scripts.pory"
	.string "EVER GRANDE CITY?\p"
# 116 "data/maps/PetalburgCity_WallysHouse/scripts.pory"
	.string "Oh, {PLAYER}{KUN}, don't be silly.\p"
# 117 "data/maps/PetalburgCity_WallysHouse/scripts.pory"
	.string "He may have gotten healthy, but he\n"
# 118 "data/maps/PetalburgCity_WallysHouse/scripts.pory"
	.string "can't go somewhere far away like\l"
# 119 "data/maps/PetalburgCity_WallysHouse/scripts.pory"
	.string "that all by himself.$"
# 120 "data/maps/PetalburgCity_WallysHouse/scripts.pory"

# 121 "data/maps/PetalburgCity_WallysHouse/scripts.pory"
PetalburgCity_WallysHouse_Text_WallyWasReallyHappy:
# 122 "data/maps/PetalburgCity_WallysHouse/scripts.pory"
	.string "WALLY was really happy when he told\n"
# 123 "data/maps/PetalburgCity_WallysHouse/scripts.pory"
	.string "us that he caught a POKéMON.\p"
# 124 "data/maps/PetalburgCity_WallysHouse/scripts.pory"
	.string "It's been ages since I've seen him\n"
# 125 "data/maps/PetalburgCity_WallysHouse/scripts.pory"
	.string "smile like that.$"
# 126 "data/maps/PetalburgCity_WallysHouse/scripts.pory"

# 127 "data/maps/PetalburgCity_WallysHouse/scripts.pory"
PetalburgCity_WallysHouse_Text_WallyLeftWithoutTelling:
# 128 "data/maps/PetalburgCity_WallysHouse/scripts.pory"
	.string "I want you to keep this a secret\n"
# 129 "data/maps/PetalburgCity_WallysHouse/scripts.pory"
	.string "from my husband…\p"
# 130 "data/maps/PetalburgCity_WallysHouse/scripts.pory"
	.string "But our WALLY left VERDANTURF TOWN\n"
# 131 "data/maps/PetalburgCity_WallysHouse/scripts.pory"
	.string "without telling anyone.\p"
# 132 "data/maps/PetalburgCity_WallysHouse/scripts.pory"
	.string "You know, WALLY is frail, but\n"
# 133 "data/maps/PetalburgCity_WallysHouse/scripts.pory"
	.string "he's surprisingly strong-willed.\p"
# 134 "data/maps/PetalburgCity_WallysHouse/scripts.pory"
	.string "I'm sure that he'll come back safe\n"
# 135 "data/maps/PetalburgCity_WallysHouse/scripts.pory"
	.string "and sound one day!$"
