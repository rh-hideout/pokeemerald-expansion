# 1 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 2 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
.set LOCALID_CURATOR, 2
# 3 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
.set LOCALID_ARTIST_2, 8
# 4 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 5 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_MapScripts::
# 6 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.byte 0
# 7 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 8 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_EventScript_Greeter::
# 9 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_WelcomeToLilycoveMuseum, MSGBOX_SIGN
# 10 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	end
# 11 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 12 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_EventScript_Curator::
# 13 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	lockall
# 14 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	applymovement LOCALID_CURATOR, Common_Movement_FacePlayer
# 15 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	message LilycoveCity_LilycoveMuseum_1F_Text_ImCuratorHaveYouViewedOurPaintings
# 16 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	waitmessage
# 17 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	multichoice 20, 8, MULTI_VIEWED_PAINTINGS, TRUE
# 18 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	goto_if_eq VAR_RESULT, 0, LilycoveCity_LilycoveMuseum_1F_EventScript_SawPaintings
# 19 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	goto_if_eq VAR_RESULT, 1, LilycoveCity_LilycoveMuseum_1F_EventScript_NotYet
# 20 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	end
# 21 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 22 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_EventScript_NotYet::
# 23 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_NotDisturbYouTakeYourTime, MSGBOX_NPC
# 24 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	end
# 25 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 26 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_EventScript_SawPaintings::
# 27 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_HaveYouAnInterestInPaintings, MSGBOX_YESNO
# 28 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	goto_if_eq VAR_RESULT, NO, LilycoveCity_LilycoveMuseum_1F_EventScript_NotInterested
# 29 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	goto_if_eq VAR_RESULT, YES, LilycoveCity_LilycoveMuseum_1F_EventScript_InterestedInPaintings
# 30 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	end
# 31 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 32 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_EventScript_NotInterested::
# 33 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_HonoredYoudVisitInSpiteOfThat, MSGBOX_SIGN
# 34 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	releaseall
# 35 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	end
# 36 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 37 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_EventScript_InterestedInPaintings::
# 38 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_ExcellentCanYouComeWithMe, MSGBOX_SIGN
# 39 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	applymovement LOCALID_CURATOR, LilycoveCity_LilycoveMuseum_1F_Movement_CuratorEnterStairs
# 40 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	waitmovement 0
# 41 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	removeobject LOCALID_CURATOR
# 42 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	switch VAR_FACING
# 43 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	case DIR_NORTH, LilycoveCity_LilycoveMuseum_1F_EventScript_FollowCuratorNorth
# 44 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	case DIR_WEST, LilycoveCity_LilycoveMuseum_1F_EventScript_FollowCuratorWest
# 45 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	case DIR_EAST, LilycoveCity_LilycoveMuseum_1F_EventScript_FollowCuratorEast
# 46 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	end
# 47 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 48 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_EventScript_FollowCuratorNorth::
# 49 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	lockall
# 50 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LilycoveCity_LilycoveMuseum_1F_Movement_FollowCuratorNorth
# 51 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	waitmovement 0
# 52 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	warp MAP_LILYCOVE_CITY_LILYCOVE_MUSEUM_2F, 11, 8
# 53 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	waitstate
# 54 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	end
# 55 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 56 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_EventScript_FollowCuratorWest::
# 57 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	lockall
# 58 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LilycoveCity_LilycoveMuseum_1F_Movement_FollowCuratorWest
# 59 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	waitmovement 0
# 60 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	warp MAP_LILYCOVE_CITY_LILYCOVE_MUSEUM_2F, 11, 8
# 61 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	waitstate
# 62 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	end
# 63 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 64 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_EventScript_FollowCuratorEast::
# 65 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	lockall
# 66 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LilycoveCity_LilycoveMuseum_1F_Movement_FollowCuratorEast
# 67 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	waitmovement 0
# 68 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	warp MAP_LILYCOVE_CITY_LILYCOVE_MUSEUM_2F, 11, 8
# 69 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	waitstate
# 70 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	end
# 71 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 72 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_Movement_CuratorEnterStairs:
# 73 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	walk_up
# 74 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	step_end
# 75 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 76 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_Movement_FollowCuratorWest:
# 77 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	walk_left
# 78 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	walk_up
# 79 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	step_end
# 80 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 81 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_Movement_FollowCuratorEast:
# 82 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	walk_right
# 83 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	walk_up
# 84 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	step_end
# 85 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 86 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_Movement_FollowCuratorNorth:
# 87 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	walk_up
# 88 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	walk_up
# 89 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	step_end
# 90 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 91 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_EventScript_OldPainting::
# 92 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_VeryOldPainting, MSGBOX_SIGN
# 93 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	end
# 94 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 95 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_EventScript_FantasyPainting::
# 96 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_OddLandscapeFantasticScenery, MSGBOX_SIGN
# 97 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	end
# 98 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 99 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_EventScript_WomanPainting::
# 100 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfBeautifulWoman, MSGBOX_SIGN
# 101 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	end
# 102 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 103 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_EventScript_LegendaryPokemonPainting::
# 104 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfLegendaryPokemon, MSGBOX_SIGN
# 105 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	end
# 106 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 107 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_EventScript_GrassPokemonPainting::
# 108 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfGrassPokemon, MSGBOX_SIGN
# 109 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	end
# 110 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 111 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_EventScript_BerryPainting::
# 112 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfBerries, MSGBOX_SIGN
# 113 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	end
# 114 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 115 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_EventScript_BirdSculpture::
# 116 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	msgbox LilycoveCity_LilycoveMuseum_Text_BirdPokemonSculptureReplica, MSGBOX_SIGN
# 117 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	end
# 118 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 119 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_EventScript_PokeBallSculpture::
# 120 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_BigPokeBallCarvedFromStone, MSGBOX_SIGN
# 121 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	end
# 122 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 123 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_EventScript_StoneTablet::
# 124 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_StoneTabletWithAncientText, MSGBOX_SIGN
# 125 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	end
# 126 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 127 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_EventScript_SchoolKidM::
# 128 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_MustntForgetLoveForFineArts, MSGBOX_NPC
# 129 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	end
# 130 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 131 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_EventScript_Artist1::
# 132 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_ThisMuseumIsInspiration, MSGBOX_NPC
# 133 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	end
# 134 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 135 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_EventScript_NinjaBoy::
# 136 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_ThisLadyIsPretty, MSGBOX_SIGN
# 137 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	end
# 138 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 139 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_EventScript_Woman1::
# 140 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_ThisPokemonIsAdorable, MSGBOX_SIGN
# 141 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	end
# 142 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 143 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_EventScript_Woman2::
# 144 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_HeardMuseumGotNewPaintings, MSGBOX_NPC
# 145 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	end
# 146 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 147 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_EventScript_PsychicM::
# 148 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_CuratorHasBeenCheerful, MSGBOX_NPC
# 149 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	end
# 150 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 151 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_EventScript_Artist2::
# 152 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	lock
# 153 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	faceplayer
# 154 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_AimToSeeGreatPaintings, MSGBOX_DEFAULT
# 155 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	closemessage
# 156 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	applymovement LOCALID_ARTIST_2, Common_Movement_FaceOriginalDirection
# 157 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	waitmovement 0
# 158 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	release
# 159 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	end
# 160 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 161 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_EventScript_FatMan::
# 162 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_MuseumTouristDestination, MSGBOX_NPC
# 163 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	end
# 164 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 165 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_Text_WelcomeToLilycoveMuseum:
# 166 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "Welcome to LILYCOVE MUSEUM.\p"
# 167 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "Please take the time to enjoy our\n"
# 168 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "collection of fantastic artwork\l"
# 169 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "featuring POKéMON.$"
# 170 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 171 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_Text_ImCuratorHaveYouViewedOurPaintings:
# 172 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "I'm the CURATOR of this MUSEUM of\n"
# 173 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "fine arts.\p"
# 174 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "It's heartening to see someone so\n"
# 175 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "young as you in our MUSEUM.\p"
# 176 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "Have you viewed our collection of\n"
# 177 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "paintings already?$"
# 178 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 179 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_Text_NotDisturbYouTakeYourTime:
# 180 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "Ah, then let me not disturb you.\n"
# 181 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "Please, do take your time.$"
# 182 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 183 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_Text_HaveYouAnInterestInPaintings:
# 184 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "Oh? I do believe that you seem to\n"
# 185 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "be a POKéMON TRAINER.\p"
# 186 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "Have you an interest in paintings,\n"
# 187 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "too?$"
# 188 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 189 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_Text_HonoredYoudVisitInSpiteOfThat:
# 190 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "I see…\p"
# 191 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "I'm honored that you would visit\n"
# 192 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "us in spite of that.$"
# 193 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 194 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_Text_ExcellentCanYouComeWithMe:
# 195 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "Ah, excellent!\n"
# 196 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "You do like paintings!\p"
# 197 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "Then, may I ask you to come with me?$"
# 198 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 199 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_Text_VeryOldPainting:
# 200 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "It's a very old painting.\n"
# 201 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "The paint is peeling here and there.$"
# 202 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 203 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_Text_OddLandscapeFantasticScenery:
# 204 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "It's an odd landscape with bizarre\n"
# 205 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "and fantastic scenery.$"
# 206 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 207 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfBeautifulWoman:
# 208 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "It's a painting of a beautiful, smiling\n"
# 209 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "woman with a POKéMON on her lap.$"
# 210 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 211 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfLegendaryPokemon:
# 212 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "It's a painting of a legendary POKéMON\n"
# 213 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "from long ago.\p"
# 214 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "The artist painted this from\n"
# 215 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "imagination.$"
# 216 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 217 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfGrassPokemon:
# 218 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "It's a painting of GRASS POKéMON\n"
# 219 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "swaying in a breeze.\p"
# 220 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "They appear to be enjoying the wind's\n"
# 221 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "gentle caress.$"
# 222 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 223 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfBerries:
# 224 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "It's a delicious-looking painting\n"
# 225 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "of BERRIES.\p"
# 226 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "This painting could make you hungry!$"
# 227 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 228 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_Text_BirdPokemonSculptureReplica:
# 229 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "It's a replica of a famous sculpture.\p"
# 230 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "It depicts an ancient BIRD POKéMON.$"
# 231 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 232 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_Text_BigPokeBallCarvedFromStone:
# 233 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "It's a big POKé BALL carved from\n"
# 234 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "a black stone.\p"
# 235 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "It was apparently used in festivals\n"
# 236 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "in the olden days.$"
# 237 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 238 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_Text_StoneTabletWithAncientText:
# 239 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "It's a huge stone tablet inscribed\n"
# 240 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "with POKéMON and dense text in the\l"
# 241 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "small characters of an ancient,\l"
# 242 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "unreadable language.$"
# 243 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 244 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_Text_WorksOfMagnificence:
# 245 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "Hmmm…\n"
# 246 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "What works of great magnificence…$"
# 247 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 248 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_Text_MustntForgetLoveForFineArts:
# 249 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "Battling with POKéMON is fun,\n"
# 250 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "I'll grant you that.\p"
# 251 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "But one mustn't forget our love for\n"
# 252 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "the fine arts.$"
# 253 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 254 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_Text_ThisMuseumIsInspiration:
# 255 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "This ART MUSEUM… Well, you could\n"
# 256 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "see many fantastic paintings.\p"
# 257 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "And the CURATOR is a wonderful person.\p"
# 258 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "Among artists like myself, this MUSEUM\n"
# 259 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "is an inspiration.$"
# 260 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 261 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_Text_ThisLadyIsPretty:
# 262 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "This lady is pretty!\n"
# 263 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "She's like Mommy!$"
# 264 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 265 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_Text_ThisPokemonIsAdorable:
# 266 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "This POKéMON is adorable!\n"
# 267 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "Just like our little boy!$"
# 268 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 269 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_Text_HeardMuseumGotNewPaintings:
# 270 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "I'd heard that this ART MUSEUM got\n"
# 271 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "in some new paintings.\p"
# 272 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "So, naturally I hurried over.\p"
# 273 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "Are the new paintings up on\n"
# 274 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "the second floor?$"
# 275 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 276 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_Text_CuratorHasBeenCheerful:
# 277 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "Lately, the CURATOR has been\n"
# 278 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "unusually cheerful.\p"
# 279 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "I bet something good happened for him.\n"
# 280 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "Definitely.$"
# 281 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 282 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_Text_AimToSeeGreatPaintings:
# 283 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "I aim to see many great paintings\n"
# 284 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "here and learn from them.\p"
# 285 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "I have this dream of one day having\n"
# 286 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "my artwork exhibited here.$"
# 287 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 288 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_Text_MuseumTouristDestination:
# 289 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "The ART MUSEUM has become a favorite\n"
# 290 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "tourist destination.\p"
# 291 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "It's great for LILYCOVE…\n"
# 292 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "No, great for the HOENN region!\p"
# 293 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "This is what I've heard--a lone TRAINER\n"
# 294 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "procured all the paintings upstairs.$"
