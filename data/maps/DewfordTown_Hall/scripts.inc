# 1 "data/maps/DewfordTown_Hall/scripts.pory"

# 2 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_MapScripts::
# 3 "data/maps/DewfordTown_Hall/scripts.pory"
	.byte 0
# 4 "data/maps/DewfordTown_Hall/scripts.pory"

# 5 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_Girl::
# 6 "data/maps/DewfordTown_Hall/scripts.pory"
	lock
# 7 "data/maps/DewfordTown_Hall/scripts.pory"
	faceplayer
# 8 "data/maps/DewfordTown_Hall/scripts.pory"
	call Common_EventScript_BufferTrendyPhrase
# 9 "data/maps/DewfordTown_Hall/scripts.pory"
	special IsTrendyPhraseBoring
# 10 "data/maps/DewfordTown_Hall/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, DewfordTown_Hall_EventScript_GirlBoredOfTrend
# 11 "data/maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_CantImagineLifeWithoutTrend, MSGBOX_DEFAULT
# 12 "data/maps/DewfordTown_Hall/scripts.pory"
	release
# 13 "data/maps/DewfordTown_Hall/scripts.pory"
	end
# 14 "data/maps/DewfordTown_Hall/scripts.pory"

# 15 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_GirlBoredOfTrend::
# 16 "data/maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_GettingBoredOfTrend, MSGBOX_DEFAULT
# 17 "data/maps/DewfordTown_Hall/scripts.pory"
	release
# 18 "data/maps/DewfordTown_Hall/scripts.pory"
	end
# 19 "data/maps/DewfordTown_Hall/scripts.pory"

# 20 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_Woman::
# 21 "data/maps/DewfordTown_Hall/scripts.pory"
	lock
# 22 "data/maps/DewfordTown_Hall/scripts.pory"
	faceplayer
# 23 "data/maps/DewfordTown_Hall/scripts.pory"
	call Common_EventScript_BufferTrendyPhrase
# 24 "data/maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_TeachingMonAboutTrend, MSGBOX_DEFAULT
# 25 "data/maps/DewfordTown_Hall/scripts.pory"
	release
# 26 "data/maps/DewfordTown_Hall/scripts.pory"
	end
# 27 "data/maps/DewfordTown_Hall/scripts.pory"

# 28 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_Man::
# 29 "data/maps/DewfordTown_Hall/scripts.pory"
	lock
# 30 "data/maps/DewfordTown_Hall/scripts.pory"
	faceplayer
# 31 "data/maps/DewfordTown_Hall/scripts.pory"
	call Common_EventScript_BufferTrendyPhrase
# 32 "data/maps/DewfordTown_Hall/scripts.pory"
	special BufferDeepLinkPhrase
# 33 "data/maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_DeepLinkBetweenXAndY, MSGBOX_YESNO
# 34 "data/maps/DewfordTown_Hall/scripts.pory"
	goto_if_eq VAR_RESULT, YES, DewfordTown_Hall_EventScript_ConfirmTrendLink
# 35 "data/maps/DewfordTown_Hall/scripts.pory"
	goto_if_eq VAR_RESULT, NO, DewfordTown_Hall_EventScript_RejectTrendLink
# 36 "data/maps/DewfordTown_Hall/scripts.pory"
	end
# 37 "data/maps/DewfordTown_Hall/scripts.pory"

# 38 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_ConfirmTrendLink::
# 39 "data/maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_MyHunchWasRight, MSGBOX_DEFAULT
# 40 "data/maps/DewfordTown_Hall/scripts.pory"
	release
# 41 "data/maps/DewfordTown_Hall/scripts.pory"
	end
# 42 "data/maps/DewfordTown_Hall/scripts.pory"

# 43 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_RejectTrendLink::
# 44 "data/maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_NotEasyToKeepUp, MSGBOX_DEFAULT
# 45 "data/maps/DewfordTown_Hall/scripts.pory"
	release
# 46 "data/maps/DewfordTown_Hall/scripts.pory"
	end
# 47 "data/maps/DewfordTown_Hall/scripts.pory"

# 48 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_ExpertM::
# 49 "data/maps/DewfordTown_Hall/scripts.pory"
	lock
# 50 "data/maps/DewfordTown_Hall/scripts.pory"
	faceplayer
# 51 "data/maps/DewfordTown_Hall/scripts.pory"
	call Common_EventScript_BufferTrendyPhrase
# 52 "data/maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_TVShowAboutTrend, MSGBOX_DEFAULT
# 53 "data/maps/DewfordTown_Hall/scripts.pory"
	closemessage
# 54 "data/maps/DewfordTown_Hall/scripts.pory"
	applymovement LOCALID_DEWFORD_HALL_EXPERT_M, Common_Movement_WalkInPlaceFasterUp
# 55 "data/maps/DewfordTown_Hall/scripts.pory"
	waitmovement 0
# 56 "data/maps/DewfordTown_Hall/scripts.pory"
	release
# 57 "data/maps/DewfordTown_Hall/scripts.pory"
	end
# 58 "data/maps/DewfordTown_Hall/scripts.pory"

# 59 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_Twin::
# 60 "data/maps/DewfordTown_Hall/scripts.pory"
	lock
# 61 "data/maps/DewfordTown_Hall/scripts.pory"
	faceplayer
# 62 "data/maps/DewfordTown_Hall/scripts.pory"
	call Common_EventScript_BufferTrendyPhrase
# 63 "data/maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_IsTrendMorePopularAcrossSea, MSGBOX_DEFAULT
# 64 "data/maps/DewfordTown_Hall/scripts.pory"
	closemessage
# 65 "data/maps/DewfordTown_Hall/scripts.pory"
	applymovement LOCALID_DEWFORD_HALL_TWIN, Common_Movement_WalkInPlaceFasterUp
# 66 "data/maps/DewfordTown_Hall/scripts.pory"
	waitmovement 0
# 67 "data/maps/DewfordTown_Hall/scripts.pory"
	release
# 68 "data/maps/DewfordTown_Hall/scripts.pory"
	end
# 69 "data/maps/DewfordTown_Hall/scripts.pory"

# 70 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_LittleBoy::
# 71 "data/maps/DewfordTown_Hall/scripts.pory"
	lock
# 72 "data/maps/DewfordTown_Hall/scripts.pory"
	faceplayer
# 73 "data/maps/DewfordTown_Hall/scripts.pory"
	call Common_EventScript_BufferTrendyPhrase
# 74 "data/maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_CollectTrendMerchandise, MSGBOX_DEFAULT
# 75 "data/maps/DewfordTown_Hall/scripts.pory"
	release
# 76 "data/maps/DewfordTown_Hall/scripts.pory"
	end
# 77 "data/maps/DewfordTown_Hall/scripts.pory"

# 78 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_Bookshelf::
# 79 "data/maps/DewfordTown_Hall/scripts.pory"
	lockall
# 80 "data/maps/DewfordTown_Hall/scripts.pory"
	call Common_EventScript_BufferTrendyPhrase
# 81 "data/maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_BooksAboutTrend, MSGBOX_DEFAULT
# 82 "data/maps/DewfordTown_Hall/scripts.pory"
	releaseall
# 83 "data/maps/DewfordTown_Hall/scripts.pory"
	end
# 84 "data/maps/DewfordTown_Hall/scripts.pory"

# 85 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_Painting::
# 86 "data/maps/DewfordTown_Hall/scripts.pory"
	lockall
# 87 "data/maps/DewfordTown_Hall/scripts.pory"
	call Common_EventScript_BufferTrendyPhrase
# 88 "data/maps/DewfordTown_Hall/scripts.pory"
	special GetDewfordHallPaintingNameIndex
# 89 "data/maps/DewfordTown_Hall/scripts.pory"
	switch VAR_RESULT
# 90 "data/maps/DewfordTown_Hall/scripts.pory"
	case 0, DewfordTown_Hall_EventScript_ScreamTitle
# 91 "data/maps/DewfordTown_Hall/scripts.pory"
	case 4, DewfordTown_Hall_EventScript_ScreamTitle
# 92 "data/maps/DewfordTown_Hall/scripts.pory"
	case 1, DewfordTown_Hall_EventScript_SmileTitle
# 93 "data/maps/DewfordTown_Hall/scripts.pory"
	case 5, DewfordTown_Hall_EventScript_ScreamTitle
# 94 "data/maps/DewfordTown_Hall/scripts.pory"
	case 2, DewfordTown_Hall_EventScript_LastTitle
# 95 "data/maps/DewfordTown_Hall/scripts.pory"
	case 6, DewfordTown_Hall_EventScript_LastTitle
# 96 "data/maps/DewfordTown_Hall/scripts.pory"
	case 3, DewfordTown_Hall_EventScript_BirthTitle
# 97 "data/maps/DewfordTown_Hall/scripts.pory"
	case 7, DewfordTown_Hall_EventScript_LastTitle
# 98 "data/maps/DewfordTown_Hall/scripts.pory"
	end
# 99 "data/maps/DewfordTown_Hall/scripts.pory"

# 100 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_ScreamTitle::
# 101 "data/maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_TrendsScream, MSGBOX_DEFAULT
# 102 "data/maps/DewfordTown_Hall/scripts.pory"
	releaseall
# 103 "data/maps/DewfordTown_Hall/scripts.pory"
	end
# 104 "data/maps/DewfordTown_Hall/scripts.pory"

# 105 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_SmileTitle::
# 106 "data/maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_TrendsSmile, MSGBOX_DEFAULT
# 107 "data/maps/DewfordTown_Hall/scripts.pory"
	releaseall
# 108 "data/maps/DewfordTown_Hall/scripts.pory"
	end
# 109 "data/maps/DewfordTown_Hall/scripts.pory"

# 110 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_LastTitle::
# 111 "data/maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_LastTrend, MSGBOX_DEFAULT
# 112 "data/maps/DewfordTown_Hall/scripts.pory"
	releaseall
# 113 "data/maps/DewfordTown_Hall/scripts.pory"
	end
# 114 "data/maps/DewfordTown_Hall/scripts.pory"

# 115 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_BirthTitle::
# 116 "data/maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_BirthOfTrend, MSGBOX_DEFAULT
# 117 "data/maps/DewfordTown_Hall/scripts.pory"
	releaseall
# 118 "data/maps/DewfordTown_Hall/scripts.pory"
	end
# 119 "data/maps/DewfordTown_Hall/scripts.pory"

# 120 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_SchoolKidM::
# 121 "data/maps/DewfordTown_Hall/scripts.pory"
	lockall
# 122 "data/maps/DewfordTown_Hall/scripts.pory"
	setvar VAR_0x8008, 0
# 123 "data/maps/DewfordTown_Hall/scripts.pory"
	goto DewfordTown_Hall_EventScript_DoTrendDebate
# 124 "data/maps/DewfordTown_Hall/scripts.pory"
	end
# 125 "data/maps/DewfordTown_Hall/scripts.pory"

# 126 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_PsychicM::
# 127 "data/maps/DewfordTown_Hall/scripts.pory"
	lockall
# 128 "data/maps/DewfordTown_Hall/scripts.pory"
	setvar VAR_0x8008, 1
# 129 "data/maps/DewfordTown_Hall/scripts.pory"
	goto DewfordTown_Hall_EventScript_DoTrendDebate
# 130 "data/maps/DewfordTown_Hall/scripts.pory"
	end
# 131 "data/maps/DewfordTown_Hall/scripts.pory"

# 132 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_DoTrendDebate::
# 133 "data/maps/DewfordTown_Hall/scripts.pory"
	call Common_EventScript_BufferTrendyPhrase
# 134 "data/maps/DewfordTown_Hall/scripts.pory"
	special GetDewfordHallPaintingNameIndex
# 135 "data/maps/DewfordTown_Hall/scripts.pory"
	switch VAR_RESULT
# 136 "data/maps/DewfordTown_Hall/scripts.pory"
	case 0, DewfordTown_Hall_EventScript_TrendDebate1
# 137 "data/maps/DewfordTown_Hall/scripts.pory"
	case 1, DewfordTown_Hall_EventScript_TrendDebate1
# 138 "data/maps/DewfordTown_Hall/scripts.pory"
	case 2, DewfordTown_Hall_EventScript_TrendDebate2
# 139 "data/maps/DewfordTown_Hall/scripts.pory"
	case 3, DewfordTown_Hall_EventScript_TrendDebate2
# 140 "data/maps/DewfordTown_Hall/scripts.pory"
	case 4, DewfordTown_Hall_EventScript_TrendDebate3
# 141 "data/maps/DewfordTown_Hall/scripts.pory"
	case 5, DewfordTown_Hall_EventScript_TrendDebate3
# 142 "data/maps/DewfordTown_Hall/scripts.pory"
	case 6, DewfordTown_Hall_EventScript_TrendDebate4
# 143 "data/maps/DewfordTown_Hall/scripts.pory"
	case 7, DewfordTown_Hall_EventScript_TrendDebate5
# 144 "data/maps/DewfordTown_Hall/scripts.pory"
	end
# 145 "data/maps/DewfordTown_Hall/scripts.pory"

# 146 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_TrendDebate1::
# 147 "data/maps/DewfordTown_Hall/scripts.pory"
	call DewfordTown_Hall_EventScript_DebateReact1
# 148 "data/maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_SawTrendCoolestThing, MSGBOX_DEFAULT
# 149 "data/maps/DewfordTown_Hall/scripts.pory"
	call DewfordTown_Hall_EventScript_DebateReact2
# 150 "data/maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_AllegedTrendNotAuthentic, MSGBOX_DEFAULT
# 151 "data/maps/DewfordTown_Hall/scripts.pory"
	releaseall
# 152 "data/maps/DewfordTown_Hall/scripts.pory"
	end
# 153 "data/maps/DewfordTown_Hall/scripts.pory"

# 154 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_TrendDebate2::
# 155 "data/maps/DewfordTown_Hall/scripts.pory"
	call DewfordTown_Hall_EventScript_DebateReact1
# 156 "data/maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_ComposedTrendThemeSong, MSGBOX_DEFAULT
# 157 "data/maps/DewfordTown_Hall/scripts.pory"
	call DewfordTown_Hall_EventScript_DebateReact2
# 158 "data/maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_WorkOnYourSinging, MSGBOX_DEFAULT
# 159 "data/maps/DewfordTown_Hall/scripts.pory"
	releaseall
# 160 "data/maps/DewfordTown_Hall/scripts.pory"
	end
# 161 "data/maps/DewfordTown_Hall/scripts.pory"

# 162 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_TrendDebate3::
# 163 "data/maps/DewfordTown_Hall/scripts.pory"
	call DewfordTown_Hall_EventScript_DebateReact1
# 164 "data/maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_OrganizeTrendParty, MSGBOX_DEFAULT
# 165 "data/maps/DewfordTown_Hall/scripts.pory"
	call DewfordTown_Hall_EventScript_DebateReact2
# 166 "data/maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_BrilliantIndeed, MSGBOX_DEFAULT
# 167 "data/maps/DewfordTown_Hall/scripts.pory"
	releaseall
# 168 "data/maps/DewfordTown_Hall/scripts.pory"
	end
# 169 "data/maps/DewfordTown_Hall/scripts.pory"

# 170 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_TrendDebate4::
# 171 "data/maps/DewfordTown_Hall/scripts.pory"
	call DewfordTown_Hall_EventScript_DebateReact1
# 172 "data/maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_TrendHasBecomePartOfLife, MSGBOX_DEFAULT
# 173 "data/maps/DewfordTown_Hall/scripts.pory"
	call DewfordTown_Hall_EventScript_DebateReact2
# 174 "data/maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_TrendWeighsHeavilyOnMind, MSGBOX_DEFAULT
# 175 "data/maps/DewfordTown_Hall/scripts.pory"
	releaseall
# 176 "data/maps/DewfordTown_Hall/scripts.pory"
	end
# 177 "data/maps/DewfordTown_Hall/scripts.pory"

# 178 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_TrendDebate5::
# 179 "data/maps/DewfordTown_Hall/scripts.pory"
	call DewfordTown_Hall_EventScript_DebateReact1
# 180 "data/maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_IfWeTeamUpWellBeInvincible, MSGBOX_DEFAULT
# 181 "data/maps/DewfordTown_Hall/scripts.pory"
	call DewfordTown_Hall_EventScript_DebateReact2
# 182 "data/maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_WellBeTrendDuo, MSGBOX_DEFAULT
# 183 "data/maps/DewfordTown_Hall/scripts.pory"
	releaseall
# 184 "data/maps/DewfordTown_Hall/scripts.pory"
	end
# 185 "data/maps/DewfordTown_Hall/scripts.pory"

# 186 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_DontMovePlayer1::
# 187 "data/maps/DewfordTown_Hall/scripts.pory"
	return
# 188 "data/maps/DewfordTown_Hall/scripts.pory"

# 189 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_DebateReact1::
# 190 "data/maps/DewfordTown_Hall/scripts.pory"
	applymovement LOCALID_DEWFORD_HALL_PSYCHIC_M, DewfordTown_Hall_Movement_PsychicWalkInPlaceLeft
# 191 "data/maps/DewfordTown_Hall/scripts.pory"
	waitmovement 0
# 192 "data/maps/DewfordTown_Hall/scripts.pory"
	goto_if_eq VAR_0x8008, 0, DewfordTown_Hall_EventScript_PlayerReactWest
# 193 "data/maps/DewfordTown_Hall/scripts.pory"
	goto_if_eq VAR_0x8008, 1, DewfordTown_Hall_EventScript_DontMovePlayer2
# 194 "data/maps/DewfordTown_Hall/scripts.pory"
	end
# 195 "data/maps/DewfordTown_Hall/scripts.pory"

# 196 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_PlayerReactWest::
# 197 "data/maps/DewfordTown_Hall/scripts.pory"
	goto_if_eq VAR_FACING, DIR_EAST, DewfordTown_Hall_EventScript_DontMovePlayer1
# 198 "data/maps/DewfordTown_Hall/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 199 "data/maps/DewfordTown_Hall/scripts.pory"
	waitmovement 0
# 200 "data/maps/DewfordTown_Hall/scripts.pory"
	return
# 201 "data/maps/DewfordTown_Hall/scripts.pory"

# 202 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_DontMovePlayer2::
# 203 "data/maps/DewfordTown_Hall/scripts.pory"
	return
# 204 "data/maps/DewfordTown_Hall/scripts.pory"

# 205 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_DebateReact2::
# 206 "data/maps/DewfordTown_Hall/scripts.pory"
	applymovement LOCALID_DEWFORD_HALL_SCHOOL_KID_M, DewfordTown_Hall_Movement_SchoolKidWalkInPlaceRight
# 207 "data/maps/DewfordTown_Hall/scripts.pory"
	waitmovement 0
# 208 "data/maps/DewfordTown_Hall/scripts.pory"
	goto_if_eq VAR_0x8008, 0, DewfordTown_Hall_EventScript_PlayerReactNorthSouth
# 209 "data/maps/DewfordTown_Hall/scripts.pory"
	goto_if_eq VAR_0x8008, 1, DewfordTown_Hall_EventScript_PlayerReactEast
# 210 "data/maps/DewfordTown_Hall/scripts.pory"
	end
# 211 "data/maps/DewfordTown_Hall/scripts.pory"

# 212 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_PlayerReactNorthSouth::
# 213 "data/maps/DewfordTown_Hall/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, DewfordTown_Hall_EventScript_PlayerWalkInPlaceUp
# 214 "data/maps/DewfordTown_Hall/scripts.pory"
	call_if_eq VAR_FACING, DIR_SOUTH, DewfordTown_Hall_EventScript_PlayerWalkInPlaceDown
# 215 "data/maps/DewfordTown_Hall/scripts.pory"
	return
# 216 "data/maps/DewfordTown_Hall/scripts.pory"

# 217 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_PlayerWalkInPlaceUp::
# 218 "data/maps/DewfordTown_Hall/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 219 "data/maps/DewfordTown_Hall/scripts.pory"
	waitmovement 0
# 220 "data/maps/DewfordTown_Hall/scripts.pory"
	return
# 221 "data/maps/DewfordTown_Hall/scripts.pory"

# 222 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_PlayerWalkInPlaceDown::
# 223 "data/maps/DewfordTown_Hall/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 224 "data/maps/DewfordTown_Hall/scripts.pory"
	waitmovement 0
# 225 "data/maps/DewfordTown_Hall/scripts.pory"
	return
# 226 "data/maps/DewfordTown_Hall/scripts.pory"

# 227 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_PlayerReactEast::
# 228 "data/maps/DewfordTown_Hall/scripts.pory"
	goto_if_eq VAR_FACING, DIR_WEST, DewfordTown_Hall_EventScript_DontMovePlayer1
# 229 "data/maps/DewfordTown_Hall/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 230 "data/maps/DewfordTown_Hall/scripts.pory"
	waitmovement 0
# 231 "data/maps/DewfordTown_Hall/scripts.pory"
	return
# 232 "data/maps/DewfordTown_Hall/scripts.pory"

# 233 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Movement_PsychicWalkInPlaceLeft:
# 234 "data/maps/DewfordTown_Hall/scripts.pory"
	walk_in_place_left
# 235 "data/maps/DewfordTown_Hall/scripts.pory"
	step_end
# 236 "data/maps/DewfordTown_Hall/scripts.pory"

# 237 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Movement_SchoolKidWalkInPlaceRight:
# 238 "data/maps/DewfordTown_Hall/scripts.pory"
	walk_in_place_right
# 239 "data/maps/DewfordTown_Hall/scripts.pory"
	step_end
# 240 "data/maps/DewfordTown_Hall/scripts.pory"

# 241 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_SludgeBombMan::
# 242 "data/maps/DewfordTown_Hall/scripts.pory"
	lock
# 243 "data/maps/DewfordTown_Hall/scripts.pory"
	faceplayer
# 244 "data/maps/DewfordTown_Hall/scripts.pory"
	call Common_EventScript_BufferTrendyPhrase
# 245 "data/maps/DewfordTown_Hall/scripts.pory"
	goto_if_set FLAG_RECEIVED_TM_SLUDGE_BOMB, DewfordTown_Hall_EventScript_ReceivedSludgeBomb
# 246 "data/maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_GiveYouSludgeBomb, MSGBOX_DEFAULT
# 247 "data/maps/DewfordTown_Hall/scripts.pory"
	giveitem ITEM_TM_SLUDGE_BOMB
# 248 "data/maps/DewfordTown_Hall/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 249 "data/maps/DewfordTown_Hall/scripts.pory"
	setflag FLAG_RECEIVED_TM_SLUDGE_BOMB
# 250 "data/maps/DewfordTown_Hall/scripts.pory"
	release
# 251 "data/maps/DewfordTown_Hall/scripts.pory"
	end
# 252 "data/maps/DewfordTown_Hall/scripts.pory"

# 253 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_ReceivedSludgeBomb::
# 254 "data/maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_LoveSludgeBombButTrendInToo, MSGBOX_DEFAULT
# 255 "data/maps/DewfordTown_Hall/scripts.pory"
	release
# 256 "data/maps/DewfordTown_Hall/scripts.pory"
	end
# 257 "data/maps/DewfordTown_Hall/scripts.pory"

# 258 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_CantImagineLifeWithoutTrend:
# 259 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "What's in vogue? Why, it has to be\n"
# 260 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "“{STR_VAR_1}”!\p"
# 261 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "I can't imagine what life would be like\n"
# 262 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "without “{STR_VAR_1}”!$"
# 263 "data/maps/DewfordTown_Hall/scripts.pory"

# 264 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_GettingBoredOfTrend:
# 265 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "What's in vogue? Why, it has to be\n"
# 266 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "“{STR_VAR_1}”!\p"
# 267 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "But I'm getting kind of bored with it.\p"
# 268 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "I should look for the next big thing.$"
# 269 "data/maps/DewfordTown_Hall/scripts.pory"

# 270 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_TeachingMonAboutTrend:
# 271 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "I'm teaching my POKéMON about\n"
# 272 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "“{STR_VAR_1},”\l"
# 273 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "but it's not going well.\p"
# 274 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "It's a bit too much, I think.$"
# 275 "data/maps/DewfordTown_Hall/scripts.pory"

# 276 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_DeepLinkBetweenXAndY:
# 277 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "I'm studying up on the hip and trendy\n"
# 278 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "“{STR_VAR_1}” now.\p"
# 279 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "Is it true that there's a deep link\n"
# 280 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "between “{STR_VAR_1}”\l"
# 281 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "and “{STR_VAR_2}”?$"
# 282 "data/maps/DewfordTown_Hall/scripts.pory"

# 283 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_MyHunchWasRight:
# 284 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "Oh!\n"
# 285 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "So, my hunch was right!\p"
# 286 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "I'm one step closer to being hip and\n"
# 287 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "happening, yowza!$"
# 288 "data/maps/DewfordTown_Hall/scripts.pory"

# 289 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_NotEasyToKeepUp:
# 290 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "What?!\n"
# 291 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "Is that so?!\p"
# 292 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "It's not easy for an older fellow like\n"
# 293 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "me to keep up with trends!$"
# 294 "data/maps/DewfordTown_Hall/scripts.pory"

# 295 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_TVShowAboutTrend:
# 296 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "This whole business about\n"
# 297 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "“{STR_VAR_1}”…\l"
# 298 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "Isn't there a TV show on it?$"
# 299 "data/maps/DewfordTown_Hall/scripts.pory"

# 300 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_IsTrendMorePopularAcrossSea:
# 301 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "Across the sea…\p"
# 302 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "Is “{STR_VAR_1}”\n"
# 303 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "even more popular?$"
# 304 "data/maps/DewfordTown_Hall/scripts.pory"

# 305 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_CollectTrendMerchandise:
# 306 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "I collect official\n"
# 307 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "“{STR_VAR_1}”\l"
# 308 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "licensed merchandise.\p"
# 309 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "I have official\n"
# 310 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "“{STR_VAR_1}” DOLLS…\p"
# 311 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "Official “{STR_VAR_1}”\n"
# 312 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "brand clothing…\p"
# 313 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "And officially licensed\n"
# 314 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "“{STR_VAR_1}”\l"
# 315 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "picture books.\p"
# 316 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "Heheh, I own!\n"
# 317 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "I'm not sharing anything with you!$"
# 318 "data/maps/DewfordTown_Hall/scripts.pory"

# 319 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_BooksAboutTrend:
# 320 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "IDENTIFYING GOOD\n"
# 321 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "“{STR_VAR_1}” &\l"
# 322 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "BAD “{STR_VAR_1}”…\p"
# 323 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "THE LINK BETWEEN\n"
# 324 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "“{STR_VAR_1}” AND\l"
# 325 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "POKéMON…\p"
# 326 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "USEFUL\n"
# 327 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "“{STR_VAR_1}”…\p"
# 328 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "It's neatly jammed with books about\n"
# 329 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "“{STR_VAR_1}.”$"
# 330 "data/maps/DewfordTown_Hall/scripts.pory"

# 331 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_TrendsScream:
# 332 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "“{STR_VAR_1}'S\n"
# 333 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "SCREAM” is the title.$"
# 334 "data/maps/DewfordTown_Hall/scripts.pory"

# 335 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_TrendsSmile:
# 336 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "“{STR_VAR_1}'S\n"
# 337 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "SMILE” is the title.$"
# 338 "data/maps/DewfordTown_Hall/scripts.pory"

# 339 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_LastTrend:
# 340 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "It's titled “THE LAST\n"
# 341 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "{STR_VAR_1}”.$"
# 342 "data/maps/DewfordTown_Hall/scripts.pory"

# 343 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_BirthOfTrend:
# 344 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "It's titled “THE BIRTH OF\n"
# 345 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "{STR_VAR_1}”.$"
# 346 "data/maps/DewfordTown_Hall/scripts.pory"

# 347 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_SawTrendCoolestThing:
# 348 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "I saw “{STR_VAR_1}”!\n"
# 349 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "Cool, huh?\p"
# 350 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "It's, like, the coolest thing going!\p"
# 351 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "It was awesome!\n"
# 352 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "It was the real thing, oh yeah!$"
# 353 "data/maps/DewfordTown_Hall/scripts.pory"

# 354 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_AllegedTrendNotAuthentic:
# 355 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "Oh, no, no, no.\p"
# 356 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "That alleged\n"
# 357 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "“{STR_VAR_1}”\l"
# 358 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "you claim to have seen--it's not.\p"
# 359 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "The authentic article is much…\n"
# 360 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "How should I say it?\l"
# 361 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "Sharper, yet more mellow!\p"
# 362 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "Ah, no matter. It's astonishing!$"
# 363 "data/maps/DewfordTown_Hall/scripts.pory"

# 364 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_ComposedTrendThemeSong:
# 365 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "Hey, listen, I composed a theme song\n"
# 366 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "for “{STR_VAR_1}.”\p"
# 367 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "“{STR_VAR_1}”\n"
# 368 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "is really popular right now.\p"
# 369 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "Okay, listen!\n"
# 370 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "… …\p"
# 371 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "Oh!\n"
# 372 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "{STR_VAR_1}!\p"
# 373 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "Wonderful\n"
# 374 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "{STR_VAR_1}!$"
# 375 "data/maps/DewfordTown_Hall/scripts.pory"

# 376 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_WorkOnYourSinging:
# 377 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "… …\p"
# 378 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "I dare say, chap, it would pay for you\n"
# 379 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "to work on your singing before you\l"
# 380 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "trifle yourself with\l"
# 381 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "“{STR_VAR_1}.”$"
# 382 "data/maps/DewfordTown_Hall/scripts.pory"

# 383 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_OrganizeTrendParty:
# 384 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "Anyway, as I was saying earlier, we\n"
# 385 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "should get together and organize a\l"
# 386 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "“{STR_VAR_1}” party\l"
# 387 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "on the island.$"
# 388 "data/maps/DewfordTown_Hall/scripts.pory"

# 389 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_BrilliantIndeed:
# 390 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "Oh, a smashing good idea!\p"
# 391 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "It will settle once and for all\n"
# 392 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "who is the best at\l"
# 393 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "“{STR_VAR_1}.”\l"
# 394 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "Brilliant, indeed!\p"
# 395 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "Starting today, our lives will revolve\n"
# 396 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "around “{STR_VAR_1}”!$"
# 397 "data/maps/DewfordTown_Hall/scripts.pory"

# 398 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_TrendHasBecomePartOfLife:
# 399 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "I was thinking, though…\p"
# 400 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "Wouldn't you agree that\n"
# 401 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "“{STR_VAR_1}” has\l"
# 402 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "grown from being something trendy to\l"
# 403 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "being a part of our daily lives?$"
# 404 "data/maps/DewfordTown_Hall/scripts.pory"

# 405 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_TrendWeighsHeavilyOnMind:
# 406 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "Beg pardon?\n"
# 407 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "That much, what?\p"
# 408 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "However, it's true that\n"
# 409 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "“{STR_VAR_1}”\l"
# 410 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "weighs heavily on your mind, whether\l"
# 411 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "you're awake or asleep.\p"
# 412 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "Absolutely, you're the\n"
# 413 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "“{STR_VAR_1}”\l"
# 414 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "PROFESSOR, old sport!$"
# 415 "data/maps/DewfordTown_Hall/scripts.pory"

# 416 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_IfWeTeamUpWellBeInvincible:
# 417 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "If you and me team up as a combo,\n"
# 418 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "we'll be invincible when it comes to all\l"
# 419 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "things “{STR_VAR_1}”!$"
# 420 "data/maps/DewfordTown_Hall/scripts.pory"

# 421 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_WellBeTrendDuo:
# 422 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "Spot on, my friend!\p"
# 423 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "We shall be the\n"
# 424 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "“{STR_VAR_1}” DUO!\p"
# 425 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "Isn't that a ripe image?\n"
# 426 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "Hahahah!$"
# 427 "data/maps/DewfordTown_Hall/scripts.pory"

# 428 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_GiveYouSludgeBomb:
# 429 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "For me, SLUDGE BOMB is at the peak\n"
# 430 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "of popularity. It's the one.\p"
# 431 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "Hunh? You're telling me that you don't\n"
# 432 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "know about SLUDGE BOMB?\p"
# 433 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "That's outright pitiful.\n"
# 434 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "I'll give you one.$"
# 435 "data/maps/DewfordTown_Hall/scripts.pory"

# 436 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_LoveSludgeBombButTrendInToo:
# 437 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "I love SLUDGE BOMB.\p"
# 438 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "But POKéMON with the move\n"
# 439 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "“{STR_VAR_1}”\l"
# 440 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "are in, too.$"
