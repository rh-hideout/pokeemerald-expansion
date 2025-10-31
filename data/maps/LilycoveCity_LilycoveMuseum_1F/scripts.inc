# 1 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 2 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_MapScripts::
# 3 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.byte 0
# 4 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 5 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_EventScript_Greeter::
# 6 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_WelcomeToLilycoveMuseum, MSGBOX_SIGN
# 7 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	end
# 8 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 9 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_EventScript_Curator::
# 10 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	lockall
# 11 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	applymovement LOCALID_MUSEUM_1F_CURATOR, Common_Movement_FacePlayer
# 12 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	message LilycoveCity_LilycoveMuseum_1F_Text_ImCuratorHaveYouViewedOurPaintings
# 13 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	waitmessage
# 14 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	multichoice 20, 8, MULTI_VIEWED_PAINTINGS, TRUE
# 15 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	goto_if_eq VAR_RESULT, 0, LilycoveCity_LilycoveMuseum_1F_EventScript_SawPaintings
# 16 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	goto_if_eq VAR_RESULT, 1, LilycoveCity_LilycoveMuseum_1F_EventScript_NotYet
# 17 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	end
# 18 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 19 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_EventScript_NotYet::
# 20 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_NotDisturbYouTakeYourTime, MSGBOX_NPC
# 21 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	end
# 22 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 23 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_EventScript_SawPaintings::
# 24 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_HaveYouAnInterestInPaintings, MSGBOX_YESNO
# 25 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	goto_if_eq VAR_RESULT, NO, LilycoveCity_LilycoveMuseum_1F_EventScript_NotInterested
# 26 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	goto_if_eq VAR_RESULT, YES, LilycoveCity_LilycoveMuseum_1F_EventScript_InterestedInPaintings
# 27 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	end
# 28 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 29 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_EventScript_NotInterested::
# 30 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_HonoredYoudVisitInSpiteOfThat, MSGBOX_SIGN
# 31 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	releaseall
# 32 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	end
# 33 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 34 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_EventScript_InterestedInPaintings::
# 35 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_ExcellentCanYouComeWithMe, MSGBOX_SIGN
# 36 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	applymovement LOCALID_MUSEUM_1F_CURATOR, LilycoveCity_LilycoveMuseum_1F_Movement_CuratorEnterStairs
# 37 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	waitmovement 0
# 38 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	removeobject LOCALID_MUSEUM_1F_CURATOR
# 39 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	switch VAR_FACING
# 40 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	case DIR_NORTH, LilycoveCity_LilycoveMuseum_1F_EventScript_FollowCuratorNorth
# 41 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	case DIR_WEST, LilycoveCity_LilycoveMuseum_1F_EventScript_FollowCuratorWest
# 42 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	case DIR_EAST, LilycoveCity_LilycoveMuseum_1F_EventScript_FollowCuratorEast
# 43 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	end
# 44 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 45 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_EventScript_FollowCuratorNorth::
# 46 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	lockall
# 47 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	applymovement LOCALID_PLAYER, LilycoveCity_LilycoveMuseum_1F_Movement_FollowCuratorNorth
# 48 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	waitmovement 0
# 49 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	warp MAP_LILYCOVE_CITY_LILYCOVE_MUSEUM_2F, 11, 8
# 50 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	waitstate
# 51 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	end
# 52 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 53 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_EventScript_FollowCuratorWest::
# 54 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	lockall
# 55 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	applymovement LOCALID_PLAYER, LilycoveCity_LilycoveMuseum_1F_Movement_FollowCuratorWest
# 56 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	waitmovement 0
# 57 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	warp MAP_LILYCOVE_CITY_LILYCOVE_MUSEUM_2F, 11, 8
# 58 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	waitstate
# 59 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	end
# 60 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 61 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_EventScript_FollowCuratorEast::
# 62 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	lockall
# 63 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	applymovement LOCALID_PLAYER, LilycoveCity_LilycoveMuseum_1F_Movement_FollowCuratorEast
# 64 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	waitmovement 0
# 65 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	warp MAP_LILYCOVE_CITY_LILYCOVE_MUSEUM_2F, 11, 8
# 66 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	waitstate
# 67 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	end
# 68 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 69 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_Movement_CuratorEnterStairs:
# 70 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	walk_up
# 71 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	step_end
# 72 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 73 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_Movement_FollowCuratorWest:
# 74 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	walk_left
# 75 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	walk_up
# 76 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	step_end
# 77 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 78 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_Movement_FollowCuratorEast:
# 79 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	walk_right
# 80 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	walk_up
# 81 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	step_end
# 82 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 83 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_Movement_FollowCuratorNorth:
# 84 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	walk_up
# 85 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	walk_up
# 86 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	step_end
# 87 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 88 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_EventScript_OldPainting::
# 89 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_VeryOldPainting, MSGBOX_SIGN
# 90 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	end
# 91 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 92 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_EventScript_FantasyPainting::
# 93 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_OddLandscapeFantasticScenery, MSGBOX_SIGN
# 94 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	end
# 95 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 96 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_EventScript_WomanPainting::
# 97 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfBeautifulWoman, MSGBOX_SIGN
# 98 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	end
# 99 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 100 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_EventScript_LegendaryPokemonPainting::
# 101 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfLegendaryPokemon, MSGBOX_SIGN
# 102 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	end
# 103 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 104 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_EventScript_GrassPokemonPainting::
# 105 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfGrassPokemon, MSGBOX_SIGN
# 106 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	end
# 107 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 108 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_EventScript_BerryPainting::
# 109 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfBerries, MSGBOX_SIGN
# 110 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	end
# 111 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 112 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_EventScript_BirdSculpture::
# 113 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	msgbox LilycoveCity_LilycoveMuseum_Text_BirdPokemonSculptureReplica, MSGBOX_SIGN
# 114 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	end
# 115 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 116 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_EventScript_PokeBallSculpture::
# 117 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_BigPokeBallCarvedFromStone, MSGBOX_SIGN
# 118 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	end
# 119 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 120 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_EventScript_StoneTablet::
# 121 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_StoneTabletWithAncientText, MSGBOX_SIGN
# 122 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	end
# 123 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 124 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_EventScript_SchoolKidM::
# 125 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_MustntForgetLoveForFineArts, MSGBOX_NPC
# 126 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	end
# 127 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 128 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_EventScript_Artist1::
# 129 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_ThisMuseumIsInspiration, MSGBOX_NPC
# 130 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	end
# 131 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 132 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_EventScript_NinjaBoy::
# 133 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_ThisLadyIsPretty, MSGBOX_SIGN
# 134 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	end
# 135 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 136 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_EventScript_Woman1::
# 137 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_ThisPokemonIsAdorable, MSGBOX_SIGN
# 138 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	end
# 139 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 140 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_EventScript_Woman2::
# 141 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_HeardMuseumGotNewPaintings, MSGBOX_NPC
# 142 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	end
# 143 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 144 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_EventScript_PsychicM::
# 145 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_CuratorHasBeenCheerful, MSGBOX_NPC
# 146 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	end
# 147 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 148 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_EventScript_Artist2::
# 149 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	lock
# 150 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	faceplayer
# 151 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_AimToSeeGreatPaintings, MSGBOX_DEFAULT
# 152 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	closemessage
# 153 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	applymovement LOCALID_MUSEUM_1F_ARTIST_2, Common_Movement_FaceOriginalDirection
# 154 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	waitmovement 0
# 155 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	release
# 156 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	end
# 157 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 158 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_EventScript_FatMan::
# 159 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_MuseumTouristDestination, MSGBOX_NPC
# 160 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	end
# 161 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 162 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_Text_WelcomeToLilycoveMuseum:
# 163 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "Welcome to LILYCOVE MUSEUM.\p"
# 164 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "Please take the time to enjoy our\n"
# 165 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "collection of fantastic artwork\l"
# 166 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "featuring POKéMON.$"
# 167 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 168 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_Text_ImCuratorHaveYouViewedOurPaintings:
# 169 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "I'm the CURATOR of this MUSEUM of\n"
# 170 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "fine arts.\p"
# 171 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "It's heartening to see someone so\n"
# 172 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "young as you in our MUSEUM.\p"
# 173 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "Have you viewed our collection of\n"
# 174 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "paintings already?$"
# 175 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 176 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_Text_NotDisturbYouTakeYourTime:
# 177 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "Ah, then let me not disturb you.\n"
# 178 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "Please, do take your time.$"
# 179 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 180 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_Text_HaveYouAnInterestInPaintings:
# 181 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "Oh? I do believe that you seem to\n"
# 182 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "be a POKéMON TRAINER.\p"
# 183 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "Have you an interest in paintings,\n"
# 184 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "too?$"
# 185 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 186 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_Text_HonoredYoudVisitInSpiteOfThat:
# 187 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "I see…\p"
# 188 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "I'm honored that you would visit\n"
# 189 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "us in spite of that.$"
# 190 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 191 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_Text_ExcellentCanYouComeWithMe:
# 192 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "Ah, excellent!\n"
# 193 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "You do like paintings!\p"
# 194 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "Then, may I ask you to come with me?$"
# 195 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 196 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_Text_VeryOldPainting:
# 197 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "It's a very old painting.\n"
# 198 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "The paint is peeling here and there.$"
# 199 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 200 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_Text_OddLandscapeFantasticScenery:
# 201 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "It's an odd landscape with bizarre\n"
# 202 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "and fantastic scenery.$"
# 203 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 204 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfBeautifulWoman:
# 205 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "It's a painting of a beautiful, smiling\n"
# 206 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "woman with a POKéMON on her lap.$"
# 207 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 208 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfLegendaryPokemon:
# 209 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "It's a painting of a legendary POKéMON\n"
# 210 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "from long ago.\p"
# 211 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "The artist painted this from\n"
# 212 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "imagination.$"
# 213 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 214 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfGrassPokemon:
# 215 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "It's a painting of GRASS POKéMON\n"
# 216 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "swaying in a breeze.\p"
# 217 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "They appear to be enjoying the wind's\n"
# 218 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "gentle caress.$"
# 219 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 220 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfBerries:
# 221 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "It's a delicious-looking painting\n"
# 222 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "of BERRIES.\p"
# 223 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "This painting could make you hungry!$"
# 224 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 225 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_Text_BirdPokemonSculptureReplica:
# 226 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "It's a replica of a famous sculpture.\p"
# 227 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "It depicts an ancient BIRD POKéMON.$"
# 228 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 229 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_Text_BigPokeBallCarvedFromStone:
# 230 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "It's a big POKé BALL carved from\n"
# 231 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "a black stone.\p"
# 232 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "It was apparently used in festivals\n"
# 233 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "in the olden days.$"
# 234 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 235 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_Text_StoneTabletWithAncientText:
# 236 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "It's a huge stone tablet inscribed\n"
# 237 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "with POKéMON and dense text in the\l"
# 238 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "small characters of an ancient,\l"
# 239 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "unreadable language.$"
# 240 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 241 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_Text_WorksOfMagnificence:
# 242 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "Hmmm…\n"
# 243 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "What works of great magnificence…$"
# 244 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 245 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_Text_MustntForgetLoveForFineArts:
# 246 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "Battling with POKéMON is fun,\n"
# 247 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "I'll grant you that.\p"
# 248 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "But one mustn't forget our love for\n"
# 249 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "the fine arts.$"
# 250 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 251 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_Text_ThisMuseumIsInspiration:
# 252 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "This ART MUSEUM… Well, you could\n"
# 253 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "see many fantastic paintings.\p"
# 254 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "And the CURATOR is a wonderful person.\p"
# 255 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "Among artists like myself, this MUSEUM\n"
# 256 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "is an inspiration.$"
# 257 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 258 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_Text_ThisLadyIsPretty:
# 259 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "This lady is pretty!\n"
# 260 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "She's like Mommy!$"
# 261 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 262 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_Text_ThisPokemonIsAdorable:
# 263 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "This POKéMON is adorable!\n"
# 264 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "Just like our little boy!$"
# 265 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 266 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_Text_HeardMuseumGotNewPaintings:
# 267 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "I'd heard that this ART MUSEUM got\n"
# 268 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "in some new paintings.\p"
# 269 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "So, naturally I hurried over.\p"
# 270 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "Are the new paintings up on\n"
# 271 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "the second floor?$"
# 272 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 273 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_Text_CuratorHasBeenCheerful:
# 274 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "Lately, the CURATOR has been\n"
# 275 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "unusually cheerful.\p"
# 276 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "I bet something good happened for him.\n"
# 277 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "Definitely.$"
# 278 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 279 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_Text_AimToSeeGreatPaintings:
# 280 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "I aim to see many great paintings\n"
# 281 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "here and learn from them.\p"
# 282 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "I have this dream of one day having\n"
# 283 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "my artwork exhibited here.$"
# 284 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 285 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_Text_MuseumTouristDestination:
# 286 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "The ART MUSEUM has become a favorite\n"
# 287 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "tourist destination.\p"
# 288 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "It's great for LILYCOVE…\n"
# 289 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "No, great for the HOENN region!\p"
# 290 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "This is what I've heard--a lone TRAINER\n"
# 291 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "procured all the paintings upstairs.$"
