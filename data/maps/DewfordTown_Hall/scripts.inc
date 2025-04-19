# 1 "data//maps/DewfordTown_Hall/scripts.pory"

# 2 "data//maps/DewfordTown_Hall/scripts.pory"
.set LOCALID_EXPERT_M, 4
# 3 "data//maps/DewfordTown_Hall/scripts.pory"
.set LOCALID_TWIN, 5
# 4 "data//maps/DewfordTown_Hall/scripts.pory"
.set LOCALID_SCHOOL_KID_M, 7
# 5 "data//maps/DewfordTown_Hall/scripts.pory"
.set LOCALID_PSYCHIC_M, 8
# 6 "data//maps/DewfordTown_Hall/scripts.pory"

# 7 "data//maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_MapScripts::
# 8 "data//maps/DewfordTown_Hall/scripts.pory"
	.byte 0
# 9 "data//maps/DewfordTown_Hall/scripts.pory"

# 10 "data//maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_Girl::
# 11 "data//maps/DewfordTown_Hall/scripts.pory"
	lock
# 12 "data//maps/DewfordTown_Hall/scripts.pory"
	faceplayer
# 13 "data//maps/DewfordTown_Hall/scripts.pory"
	call Common_EventScript_BufferTrendyPhrase
# 14 "data//maps/DewfordTown_Hall/scripts.pory"
	special IsTrendyPhraseBoring
# 15 "data//maps/DewfordTown_Hall/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, DewfordTown_Hall_EventScript_GirlBoredOfTrend
# 16 "data//maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_CantImagineLifeWithoutTrend, MSGBOX_DEFAULT
# 17 "data//maps/DewfordTown_Hall/scripts.pory"
	release
# 18 "data//maps/DewfordTown_Hall/scripts.pory"
	end
# 19 "data//maps/DewfordTown_Hall/scripts.pory"

# 20 "data//maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_GirlBoredOfTrend::
# 21 "data//maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_GettingBoredOfTrend, MSGBOX_DEFAULT
# 22 "data//maps/DewfordTown_Hall/scripts.pory"
	release
# 23 "data//maps/DewfordTown_Hall/scripts.pory"
	end
# 24 "data//maps/DewfordTown_Hall/scripts.pory"

# 25 "data//maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_Woman::
# 26 "data//maps/DewfordTown_Hall/scripts.pory"
	lock
# 27 "data//maps/DewfordTown_Hall/scripts.pory"
	faceplayer
# 28 "data//maps/DewfordTown_Hall/scripts.pory"
	call Common_EventScript_BufferTrendyPhrase
# 29 "data//maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_TeachingMonAboutTrend, MSGBOX_DEFAULT
# 30 "data//maps/DewfordTown_Hall/scripts.pory"
	release
# 31 "data//maps/DewfordTown_Hall/scripts.pory"
	end
# 32 "data//maps/DewfordTown_Hall/scripts.pory"

# 33 "data//maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_Man::
# 34 "data//maps/DewfordTown_Hall/scripts.pory"
	lock
# 35 "data//maps/DewfordTown_Hall/scripts.pory"
	faceplayer
# 36 "data//maps/DewfordTown_Hall/scripts.pory"
	call Common_EventScript_BufferTrendyPhrase
# 37 "data//maps/DewfordTown_Hall/scripts.pory"
	special BufferDeepLinkPhrase
# 38 "data//maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_DeepLinkBetweenXAndY, MSGBOX_YESNO
# 39 "data//maps/DewfordTown_Hall/scripts.pory"
	goto_if_eq VAR_RESULT, YES, DewfordTown_Hall_EventScript_ConfirmTrendLink
# 40 "data//maps/DewfordTown_Hall/scripts.pory"
	goto_if_eq VAR_RESULT, NO, DewfordTown_Hall_EventScript_RejectTrendLink
# 41 "data//maps/DewfordTown_Hall/scripts.pory"
	end
# 42 "data//maps/DewfordTown_Hall/scripts.pory"

# 43 "data//maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_ConfirmTrendLink::
# 44 "data//maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_MyHunchWasRight, MSGBOX_DEFAULT
# 45 "data//maps/DewfordTown_Hall/scripts.pory"
	release
# 46 "data//maps/DewfordTown_Hall/scripts.pory"
	end
# 47 "data//maps/DewfordTown_Hall/scripts.pory"

# 48 "data//maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_RejectTrendLink::
# 49 "data//maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_NotEasyToKeepUp, MSGBOX_DEFAULT
# 50 "data//maps/DewfordTown_Hall/scripts.pory"
	release
# 51 "data//maps/DewfordTown_Hall/scripts.pory"
	end
# 52 "data//maps/DewfordTown_Hall/scripts.pory"

# 53 "data//maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_ExpertM::
# 54 "data//maps/DewfordTown_Hall/scripts.pory"
	lock
# 55 "data//maps/DewfordTown_Hall/scripts.pory"
	faceplayer
# 56 "data//maps/DewfordTown_Hall/scripts.pory"
	call Common_EventScript_BufferTrendyPhrase
# 57 "data//maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_TVShowAboutTrend, MSGBOX_DEFAULT
# 58 "data//maps/DewfordTown_Hall/scripts.pory"
	closemessage
# 59 "data//maps/DewfordTown_Hall/scripts.pory"
	applymovement LOCALID_EXPERT_M, Common_Movement_WalkInPlaceFasterUp
# 60 "data//maps/DewfordTown_Hall/scripts.pory"
	waitmovement 0
# 61 "data//maps/DewfordTown_Hall/scripts.pory"
	release
# 62 "data//maps/DewfordTown_Hall/scripts.pory"
	end
# 63 "data//maps/DewfordTown_Hall/scripts.pory"

# 64 "data//maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_Twin::
# 65 "data//maps/DewfordTown_Hall/scripts.pory"
	lock
# 66 "data//maps/DewfordTown_Hall/scripts.pory"
	faceplayer
# 67 "data//maps/DewfordTown_Hall/scripts.pory"
	call Common_EventScript_BufferTrendyPhrase
# 68 "data//maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_IsTrendMorePopularAcrossSea, MSGBOX_DEFAULT
# 69 "data//maps/DewfordTown_Hall/scripts.pory"
	closemessage
# 70 "data//maps/DewfordTown_Hall/scripts.pory"
	applymovement LOCALID_TWIN, Common_Movement_WalkInPlaceFasterUp
# 71 "data//maps/DewfordTown_Hall/scripts.pory"
	waitmovement 0
# 72 "data//maps/DewfordTown_Hall/scripts.pory"
	release
# 73 "data//maps/DewfordTown_Hall/scripts.pory"
	end
# 74 "data//maps/DewfordTown_Hall/scripts.pory"

# 75 "data//maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_LittleBoy::
# 76 "data//maps/DewfordTown_Hall/scripts.pory"
	lock
# 77 "data//maps/DewfordTown_Hall/scripts.pory"
	faceplayer
# 78 "data//maps/DewfordTown_Hall/scripts.pory"
	call Common_EventScript_BufferTrendyPhrase
# 79 "data//maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_CollectTrendMerchandise, MSGBOX_DEFAULT
# 80 "data//maps/DewfordTown_Hall/scripts.pory"
	release
# 81 "data//maps/DewfordTown_Hall/scripts.pory"
	end
# 82 "data//maps/DewfordTown_Hall/scripts.pory"

# 83 "data//maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_Bookshelf::
# 84 "data//maps/DewfordTown_Hall/scripts.pory"
	lockall
# 85 "data//maps/DewfordTown_Hall/scripts.pory"
	call Common_EventScript_BufferTrendyPhrase
# 86 "data//maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_BooksAboutTrend, MSGBOX_DEFAULT
# 87 "data//maps/DewfordTown_Hall/scripts.pory"
	releaseall
# 88 "data//maps/DewfordTown_Hall/scripts.pory"
	end
# 89 "data//maps/DewfordTown_Hall/scripts.pory"

# 90 "data//maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_Painting::
# 91 "data//maps/DewfordTown_Hall/scripts.pory"
	lockall
# 92 "data//maps/DewfordTown_Hall/scripts.pory"
	call Common_EventScript_BufferTrendyPhrase
# 93 "data//maps/DewfordTown_Hall/scripts.pory"
	special GetDewfordHallPaintingNameIndex
# 94 "data//maps/DewfordTown_Hall/scripts.pory"
	switch VAR_RESULT
# 95 "data//maps/DewfordTown_Hall/scripts.pory"
	case 0, DewfordTown_Hall_EventScript_ScreamTitle
# 96 "data//maps/DewfordTown_Hall/scripts.pory"
	case 4, DewfordTown_Hall_EventScript_ScreamTitle
# 97 "data//maps/DewfordTown_Hall/scripts.pory"
	case 1, DewfordTown_Hall_EventScript_SmileTitle
# 98 "data//maps/DewfordTown_Hall/scripts.pory"
	case 5, DewfordTown_Hall_EventScript_ScreamTitle
# 99 "data//maps/DewfordTown_Hall/scripts.pory"
	case 2, DewfordTown_Hall_EventScript_LastTitle
# 100 "data//maps/DewfordTown_Hall/scripts.pory"
	case 6, DewfordTown_Hall_EventScript_LastTitle
# 101 "data//maps/DewfordTown_Hall/scripts.pory"
	case 3, DewfordTown_Hall_EventScript_BirthTitle
# 102 "data//maps/DewfordTown_Hall/scripts.pory"
	case 7, DewfordTown_Hall_EventScript_LastTitle
# 103 "data//maps/DewfordTown_Hall/scripts.pory"
	end
# 104 "data//maps/DewfordTown_Hall/scripts.pory"

# 105 "data//maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_ScreamTitle::
# 106 "data//maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_TrendsScream, MSGBOX_DEFAULT
# 107 "data//maps/DewfordTown_Hall/scripts.pory"
	releaseall
# 108 "data//maps/DewfordTown_Hall/scripts.pory"
	end
# 109 "data//maps/DewfordTown_Hall/scripts.pory"

# 110 "data//maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_SmileTitle::
# 111 "data//maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_TrendsSmile, MSGBOX_DEFAULT
# 112 "data//maps/DewfordTown_Hall/scripts.pory"
	releaseall
# 113 "data//maps/DewfordTown_Hall/scripts.pory"
	end
# 114 "data//maps/DewfordTown_Hall/scripts.pory"

# 115 "data//maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_LastTitle::
# 116 "data//maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_LastTrend, MSGBOX_DEFAULT
# 117 "data//maps/DewfordTown_Hall/scripts.pory"
	releaseall
# 118 "data//maps/DewfordTown_Hall/scripts.pory"
	end
# 119 "data//maps/DewfordTown_Hall/scripts.pory"

# 120 "data//maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_BirthTitle::
# 121 "data//maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_BirthOfTrend, MSGBOX_DEFAULT
# 122 "data//maps/DewfordTown_Hall/scripts.pory"
	releaseall
# 123 "data//maps/DewfordTown_Hall/scripts.pory"
	end
# 124 "data//maps/DewfordTown_Hall/scripts.pory"

# 125 "data//maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_SchoolKidM::
# 126 "data//maps/DewfordTown_Hall/scripts.pory"
	lockall
# 127 "data//maps/DewfordTown_Hall/scripts.pory"
	setvar VAR_0x8008, 0
# 128 "data//maps/DewfordTown_Hall/scripts.pory"
	goto DewfordTown_Hall_EventScript_DoTrendDebate
# 129 "data//maps/DewfordTown_Hall/scripts.pory"
	end
# 130 "data//maps/DewfordTown_Hall/scripts.pory"

# 131 "data//maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_PsychicM::
# 132 "data//maps/DewfordTown_Hall/scripts.pory"
	lockall
# 133 "data//maps/DewfordTown_Hall/scripts.pory"
	setvar VAR_0x8008, 1
# 134 "data//maps/DewfordTown_Hall/scripts.pory"
	goto DewfordTown_Hall_EventScript_DoTrendDebate
# 135 "data//maps/DewfordTown_Hall/scripts.pory"
	end
# 136 "data//maps/DewfordTown_Hall/scripts.pory"

# 137 "data//maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_DoTrendDebate::
# 138 "data//maps/DewfordTown_Hall/scripts.pory"
	call Common_EventScript_BufferTrendyPhrase
# 139 "data//maps/DewfordTown_Hall/scripts.pory"
	special GetDewfordHallPaintingNameIndex
# 140 "data//maps/DewfordTown_Hall/scripts.pory"
	switch VAR_RESULT
# 141 "data//maps/DewfordTown_Hall/scripts.pory"
	case 0, DewfordTown_Hall_EventScript_TrendDebate1
# 142 "data//maps/DewfordTown_Hall/scripts.pory"
	case 1, DewfordTown_Hall_EventScript_TrendDebate1
# 143 "data//maps/DewfordTown_Hall/scripts.pory"
	case 2, DewfordTown_Hall_EventScript_TrendDebate2
# 144 "data//maps/DewfordTown_Hall/scripts.pory"
	case 3, DewfordTown_Hall_EventScript_TrendDebate2
# 145 "data//maps/DewfordTown_Hall/scripts.pory"
	case 4, DewfordTown_Hall_EventScript_TrendDebate3
# 146 "data//maps/DewfordTown_Hall/scripts.pory"
	case 5, DewfordTown_Hall_EventScript_TrendDebate3
# 147 "data//maps/DewfordTown_Hall/scripts.pory"
	case 6, DewfordTown_Hall_EventScript_TrendDebate4
# 148 "data//maps/DewfordTown_Hall/scripts.pory"
	case 7, DewfordTown_Hall_EventScript_TrendDebate5
# 149 "data//maps/DewfordTown_Hall/scripts.pory"
	end
# 150 "data//maps/DewfordTown_Hall/scripts.pory"

# 151 "data//maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_TrendDebate1::
# 152 "data//maps/DewfordTown_Hall/scripts.pory"
	call DewfordTown_Hall_EventScript_DebateReact1
# 153 "data//maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_SawTrendCoolestThing, MSGBOX_DEFAULT
# 154 "data//maps/DewfordTown_Hall/scripts.pory"
	call DewfordTown_Hall_EventScript_DebateReact2
# 155 "data//maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_AllegedTrendNotAuthentic, MSGBOX_DEFAULT
# 156 "data//maps/DewfordTown_Hall/scripts.pory"
	releaseall
# 157 "data//maps/DewfordTown_Hall/scripts.pory"
	end
# 158 "data//maps/DewfordTown_Hall/scripts.pory"

# 159 "data//maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_TrendDebate2::
# 160 "data//maps/DewfordTown_Hall/scripts.pory"
	call DewfordTown_Hall_EventScript_DebateReact1
# 161 "data//maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_ComposedTrendThemeSong, MSGBOX_DEFAULT
# 162 "data//maps/DewfordTown_Hall/scripts.pory"
	call DewfordTown_Hall_EventScript_DebateReact2
# 163 "data//maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_WorkOnYourSinging, MSGBOX_DEFAULT
# 164 "data//maps/DewfordTown_Hall/scripts.pory"
	releaseall
# 165 "data//maps/DewfordTown_Hall/scripts.pory"
	end
# 166 "data//maps/DewfordTown_Hall/scripts.pory"

# 167 "data//maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_TrendDebate3::
# 168 "data//maps/DewfordTown_Hall/scripts.pory"
	call DewfordTown_Hall_EventScript_DebateReact1
# 169 "data//maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_OrganizeTrendParty, MSGBOX_DEFAULT
# 170 "data//maps/DewfordTown_Hall/scripts.pory"
	call DewfordTown_Hall_EventScript_DebateReact2
# 171 "data//maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_BrilliantIndeed, MSGBOX_DEFAULT
# 172 "data//maps/DewfordTown_Hall/scripts.pory"
	releaseall
# 173 "data//maps/DewfordTown_Hall/scripts.pory"
	end
# 174 "data//maps/DewfordTown_Hall/scripts.pory"

# 175 "data//maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_TrendDebate4::
# 176 "data//maps/DewfordTown_Hall/scripts.pory"
	call DewfordTown_Hall_EventScript_DebateReact1
# 177 "data//maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_TrendHasBecomePartOfLife, MSGBOX_DEFAULT
# 178 "data//maps/DewfordTown_Hall/scripts.pory"
	call DewfordTown_Hall_EventScript_DebateReact2
# 179 "data//maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_TrendWeighsHeavilyOnMind, MSGBOX_DEFAULT
# 180 "data//maps/DewfordTown_Hall/scripts.pory"
	releaseall
# 181 "data//maps/DewfordTown_Hall/scripts.pory"
	end
# 182 "data//maps/DewfordTown_Hall/scripts.pory"

# 183 "data//maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_TrendDebate5::
# 184 "data//maps/DewfordTown_Hall/scripts.pory"
	call DewfordTown_Hall_EventScript_DebateReact1
# 185 "data//maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_IfWeTeamUpWellBeInvincible, MSGBOX_DEFAULT
# 186 "data//maps/DewfordTown_Hall/scripts.pory"
	call DewfordTown_Hall_EventScript_DebateReact2
# 187 "data//maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_WellBeTrendDuo, MSGBOX_DEFAULT
# 188 "data//maps/DewfordTown_Hall/scripts.pory"
	releaseall
# 189 "data//maps/DewfordTown_Hall/scripts.pory"
	end
# 190 "data//maps/DewfordTown_Hall/scripts.pory"

# 191 "data//maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_DontMovePlayer1::
# 192 "data//maps/DewfordTown_Hall/scripts.pory"
	return
# 193 "data//maps/DewfordTown_Hall/scripts.pory"

# 194 "data//maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_DebateReact1::
# 195 "data//maps/DewfordTown_Hall/scripts.pory"
	applymovement LOCALID_PSYCHIC_M, DewfordTown_Hall_Movement_PsychicWalkInPlaceLeft
# 196 "data//maps/DewfordTown_Hall/scripts.pory"
	waitmovement 0
# 197 "data//maps/DewfordTown_Hall/scripts.pory"
	goto_if_eq VAR_0x8008, 0, DewfordTown_Hall_EventScript_PlayerReactWest
# 198 "data//maps/DewfordTown_Hall/scripts.pory"
	goto_if_eq VAR_0x8008, 1, DewfordTown_Hall_EventScript_DontMovePlayer2
# 199 "data//maps/DewfordTown_Hall/scripts.pory"
	end
# 200 "data//maps/DewfordTown_Hall/scripts.pory"

# 201 "data//maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_PlayerReactWest::
# 202 "data//maps/DewfordTown_Hall/scripts.pory"
	goto_if_eq VAR_FACING, DIR_EAST, DewfordTown_Hall_EventScript_DontMovePlayer1
# 203 "data//maps/DewfordTown_Hall/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 204 "data//maps/DewfordTown_Hall/scripts.pory"
	waitmovement 0
# 205 "data//maps/DewfordTown_Hall/scripts.pory"
	return
# 206 "data//maps/DewfordTown_Hall/scripts.pory"

# 207 "data//maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_DontMovePlayer2::
# 208 "data//maps/DewfordTown_Hall/scripts.pory"
	return
# 209 "data//maps/DewfordTown_Hall/scripts.pory"

# 210 "data//maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_DebateReact2::
# 211 "data//maps/DewfordTown_Hall/scripts.pory"
	applymovement LOCALID_SCHOOL_KID_M, DewfordTown_Hall_Movement_SchoolKidWalkInPlaceRight
# 212 "data//maps/DewfordTown_Hall/scripts.pory"
	waitmovement 0
# 213 "data//maps/DewfordTown_Hall/scripts.pory"
	goto_if_eq VAR_0x8008, 0, DewfordTown_Hall_EventScript_PlayerReactNorthSouth
# 214 "data//maps/DewfordTown_Hall/scripts.pory"
	goto_if_eq VAR_0x8008, 1, DewfordTown_Hall_EventScript_PlayerReactEast
# 215 "data//maps/DewfordTown_Hall/scripts.pory"
	end
# 216 "data//maps/DewfordTown_Hall/scripts.pory"

# 217 "data//maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_PlayerReactNorthSouth::
# 218 "data//maps/DewfordTown_Hall/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, DewfordTown_Hall_EventScript_PlayerWalkInPlaceUp
# 219 "data//maps/DewfordTown_Hall/scripts.pory"
	call_if_eq VAR_FACING, DIR_SOUTH, DewfordTown_Hall_EventScript_PlayerWalkInPlaceDown
# 220 "data//maps/DewfordTown_Hall/scripts.pory"
	return
# 221 "data//maps/DewfordTown_Hall/scripts.pory"

# 222 "data//maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_PlayerWalkInPlaceUp::
# 223 "data//maps/DewfordTown_Hall/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 224 "data//maps/DewfordTown_Hall/scripts.pory"
	waitmovement 0
# 225 "data//maps/DewfordTown_Hall/scripts.pory"
	return
# 226 "data//maps/DewfordTown_Hall/scripts.pory"

# 227 "data//maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_PlayerWalkInPlaceDown::
# 228 "data//maps/DewfordTown_Hall/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 229 "data//maps/DewfordTown_Hall/scripts.pory"
	waitmovement 0
# 230 "data//maps/DewfordTown_Hall/scripts.pory"
	return
# 231 "data//maps/DewfordTown_Hall/scripts.pory"

# 232 "data//maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_PlayerReactEast::
# 233 "data//maps/DewfordTown_Hall/scripts.pory"
	goto_if_eq VAR_FACING, DIR_WEST, DewfordTown_Hall_EventScript_DontMovePlayer1
# 234 "data//maps/DewfordTown_Hall/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 235 "data//maps/DewfordTown_Hall/scripts.pory"
	waitmovement 0
# 236 "data//maps/DewfordTown_Hall/scripts.pory"
	return
# 237 "data//maps/DewfordTown_Hall/scripts.pory"

# 238 "data//maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Movement_PsychicWalkInPlaceLeft:
# 239 "data//maps/DewfordTown_Hall/scripts.pory"
	walk_in_place_left
# 240 "data//maps/DewfordTown_Hall/scripts.pory"
	step_end
# 241 "data//maps/DewfordTown_Hall/scripts.pory"

# 242 "data//maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Movement_SchoolKidWalkInPlaceRight:
# 243 "data//maps/DewfordTown_Hall/scripts.pory"
	walk_in_place_right
# 244 "data//maps/DewfordTown_Hall/scripts.pory"
	step_end
# 245 "data//maps/DewfordTown_Hall/scripts.pory"

# 246 "data//maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_SludgeBombMan::
# 247 "data//maps/DewfordTown_Hall/scripts.pory"
	lock
# 248 "data//maps/DewfordTown_Hall/scripts.pory"
	faceplayer
# 249 "data//maps/DewfordTown_Hall/scripts.pory"
	call Common_EventScript_BufferTrendyPhrase
# 250 "data//maps/DewfordTown_Hall/scripts.pory"
	goto_if_set FLAG_RECEIVED_TM_SLUDGE_BOMB, DewfordTown_Hall_EventScript_ReceivedSludgeBomb
# 251 "data//maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_GiveYouSludgeBomb, MSGBOX_DEFAULT
# 252 "data//maps/DewfordTown_Hall/scripts.pory"
	giveitem ITEM_TM_SLUDGE_BOMB
# 253 "data//maps/DewfordTown_Hall/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 254 "data//maps/DewfordTown_Hall/scripts.pory"
	setflag FLAG_RECEIVED_TM_SLUDGE_BOMB
# 255 "data//maps/DewfordTown_Hall/scripts.pory"
	release
# 256 "data//maps/DewfordTown_Hall/scripts.pory"
	end
# 257 "data//maps/DewfordTown_Hall/scripts.pory"

# 258 "data//maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_ReceivedSludgeBomb::
# 259 "data//maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_LoveSludgeBombButTrendInToo, MSGBOX_DEFAULT
# 260 "data//maps/DewfordTown_Hall/scripts.pory"
	release
# 261 "data//maps/DewfordTown_Hall/scripts.pory"
	end
# 262 "data//maps/DewfordTown_Hall/scripts.pory"

# 263 "data//maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_CantImagineLifeWithoutTrend:
# 264 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "What's in vogue? Why, it has to be\n"
# 265 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "“{STR_VAR_1}”!\p"
# 266 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "I can't imagine what life would be like\n"
# 267 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "without “{STR_VAR_1}”!$"
# 268 "data//maps/DewfordTown_Hall/scripts.pory"

# 269 "data//maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_GettingBoredOfTrend:
# 270 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "What's in vogue? Why, it has to be\n"
# 271 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "“{STR_VAR_1}”!\p"
# 272 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "But I'm getting kind of bored with it.\p"
# 273 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "I should look for the next big thing.$"
# 274 "data//maps/DewfordTown_Hall/scripts.pory"

# 275 "data//maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_TeachingMonAboutTrend:
# 276 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "I'm teaching my POKéMON about\n"
# 277 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "“{STR_VAR_1},”\l"
# 278 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "but it's not going well.\p"
# 279 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "It's a bit too much, I think.$"
# 280 "data//maps/DewfordTown_Hall/scripts.pory"

# 281 "data//maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_DeepLinkBetweenXAndY:
# 282 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "I'm studying up on the hip and trendy\n"
# 283 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "“{STR_VAR_1}” now.\p"
# 284 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "Is it true that there's a deep link\n"
# 285 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "between “{STR_VAR_1}”\l"
# 286 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "and “{STR_VAR_2}”?$"
# 287 "data//maps/DewfordTown_Hall/scripts.pory"

# 288 "data//maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_MyHunchWasRight:
# 289 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "Oh!\n"
# 290 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "So, my hunch was right!\p"
# 291 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "I'm one step closer to being hip and\n"
# 292 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "happening, yowza!$"
# 293 "data//maps/DewfordTown_Hall/scripts.pory"

# 294 "data//maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_NotEasyToKeepUp:
# 295 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "What?!\n"
# 296 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "Is that so?!\p"
# 297 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "It's not easy for an older fellow like\n"
# 298 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "me to keep up with trends!$"
# 299 "data//maps/DewfordTown_Hall/scripts.pory"

# 300 "data//maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_TVShowAboutTrend:
# 301 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "This whole business about\n"
# 302 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "“{STR_VAR_1}”…\l"
# 303 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "Isn't there a TV show on it?$"
# 304 "data//maps/DewfordTown_Hall/scripts.pory"

# 305 "data//maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_IsTrendMorePopularAcrossSea:
# 306 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "Across the sea…\p"
# 307 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "Is “{STR_VAR_1}”\n"
# 308 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "even more popular?$"
# 309 "data//maps/DewfordTown_Hall/scripts.pory"

# 310 "data//maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_CollectTrendMerchandise:
# 311 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "I collect official\n"
# 312 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "“{STR_VAR_1}”\l"
# 313 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "licensed merchandise.\p"
# 314 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "I have official\n"
# 315 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "“{STR_VAR_1}” DOLLS…\p"
# 316 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "Official “{STR_VAR_1}”\n"
# 317 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "brand clothing…\p"
# 318 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "And officially licensed\n"
# 319 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "“{STR_VAR_1}”\l"
# 320 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "picture books.\p"
# 321 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "Heheh, I own!\n"
# 322 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "I'm not sharing anything with you!$"
# 323 "data//maps/DewfordTown_Hall/scripts.pory"

# 324 "data//maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_BooksAboutTrend:
# 325 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "IDENTIFYING GOOD\n"
# 326 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "“{STR_VAR_1}” &\l"
# 327 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "BAD “{STR_VAR_1}”…\p"
# 328 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "THE LINK BETWEEN\n"
# 329 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "“{STR_VAR_1}” AND\l"
# 330 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "POKéMON…\p"
# 331 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "USEFUL\n"
# 332 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "“{STR_VAR_1}”…\p"
# 333 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "It's neatly jammed with books about\n"
# 334 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "“{STR_VAR_1}.”$"
# 335 "data//maps/DewfordTown_Hall/scripts.pory"

# 336 "data//maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_TrendsScream:
# 337 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "“{STR_VAR_1}'S\n"
# 338 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "SCREAM” is the title.$"
# 339 "data//maps/DewfordTown_Hall/scripts.pory"

# 340 "data//maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_TrendsSmile:
# 341 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "“{STR_VAR_1}'S\n"
# 342 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "SMILE” is the title.$"
# 343 "data//maps/DewfordTown_Hall/scripts.pory"

# 344 "data//maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_LastTrend:
# 345 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "It's titled “THE LAST\n"
# 346 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "{STR_VAR_1}”.$"
# 347 "data//maps/DewfordTown_Hall/scripts.pory"

# 348 "data//maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_BirthOfTrend:
# 349 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "It's titled “THE BIRTH OF\n"
# 350 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "{STR_VAR_1}”.$"
# 351 "data//maps/DewfordTown_Hall/scripts.pory"

# 352 "data//maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_SawTrendCoolestThing:
# 353 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "I saw “{STR_VAR_1}”!\n"
# 354 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "Cool, huh?\p"
# 355 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "It's, like, the coolest thing going!\p"
# 356 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "It was awesome!\n"
# 357 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "It was the real thing, oh yeah!$"
# 358 "data//maps/DewfordTown_Hall/scripts.pory"

# 359 "data//maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_AllegedTrendNotAuthentic:
# 360 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "Oh, no, no, no.\p"
# 361 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "That alleged\n"
# 362 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "“{STR_VAR_1}”\l"
# 363 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "you claim to have seen--it's not.\p"
# 364 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "The authentic article is much…\n"
# 365 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "How should I say it?\l"
# 366 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "Sharper, yet more mellow!\p"
# 367 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "Ah, no matter. It's astonishing!$"
# 368 "data//maps/DewfordTown_Hall/scripts.pory"

# 369 "data//maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_ComposedTrendThemeSong:
# 370 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "Hey, listen, I composed a theme song\n"
# 371 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "for “{STR_VAR_1}.”\p"
# 372 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "“{STR_VAR_1}”\n"
# 373 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "is really popular right now.\p"
# 374 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "Okay, listen!\n"
# 375 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "… …\p"
# 376 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "Oh!\n"
# 377 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "{STR_VAR_1}!\p"
# 378 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "Wonderful\n"
# 379 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "{STR_VAR_1}!$"
# 380 "data//maps/DewfordTown_Hall/scripts.pory"

# 381 "data//maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_WorkOnYourSinging:
# 382 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "… …\p"
# 383 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "I dare say, chap, it would pay for you\n"
# 384 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "to work on your singing before you\l"
# 385 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "trifle yourself with\l"
# 386 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "“{STR_VAR_1}.”$"
# 387 "data//maps/DewfordTown_Hall/scripts.pory"

# 388 "data//maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_OrganizeTrendParty:
# 389 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "Anyway, as I was saying earlier, we\n"
# 390 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "should get together and organize a\l"
# 391 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "“{STR_VAR_1}” party\l"
# 392 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "on the island.$"
# 393 "data//maps/DewfordTown_Hall/scripts.pory"

# 394 "data//maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_BrilliantIndeed:
# 395 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "Oh, a smashing good idea!\p"
# 396 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "It will settle once and for all\n"
# 397 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "who is the best at\l"
# 398 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "“{STR_VAR_1}.”\l"
# 399 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "Brilliant, indeed!\p"
# 400 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "Starting today, our lives will revolve\n"
# 401 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "around “{STR_VAR_1}”!$"
# 402 "data//maps/DewfordTown_Hall/scripts.pory"

# 403 "data//maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_TrendHasBecomePartOfLife:
# 404 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "I was thinking, though…\p"
# 405 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "Wouldn't you agree that\n"
# 406 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "“{STR_VAR_1}” has\l"
# 407 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "grown from being something trendy to\l"
# 408 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "being a part of our daily lives?$"
# 409 "data//maps/DewfordTown_Hall/scripts.pory"

# 410 "data//maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_TrendWeighsHeavilyOnMind:
# 411 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "Beg pardon?\n"
# 412 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "That much, what?\p"
# 413 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "However, it's true that\n"
# 414 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "“{STR_VAR_1}”\l"
# 415 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "weighs heavily on your mind, whether\l"
# 416 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "you're awake or asleep.\p"
# 417 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "Absolutely, you're the\n"
# 418 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "“{STR_VAR_1}”\l"
# 419 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "PROFESSOR, old sport!$"
# 420 "data//maps/DewfordTown_Hall/scripts.pory"

# 421 "data//maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_IfWeTeamUpWellBeInvincible:
# 422 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "If you and me team up as a combo,\n"
# 423 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "we'll be invincible when it comes to all\l"
# 424 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "things “{STR_VAR_1}”!$"
# 425 "data//maps/DewfordTown_Hall/scripts.pory"

# 426 "data//maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_WellBeTrendDuo:
# 427 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "Spot on, my friend!\p"
# 428 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "We shall be the\n"
# 429 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "“{STR_VAR_1}” DUO!\p"
# 430 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "Isn't that a ripe image?\n"
# 431 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "Hahahah!$"
# 432 "data//maps/DewfordTown_Hall/scripts.pory"

# 433 "data//maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_GiveYouSludgeBomb:
# 434 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "For me, SLUDGE BOMB is at the peak\n"
# 435 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "of popularity. It's the one.\p"
# 436 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "Hunh? You're telling me that you don't\n"
# 437 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "know about SLUDGE BOMB?\p"
# 438 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "That's outright pitiful.\n"
# 439 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "I'll give you one.$"
# 440 "data//maps/DewfordTown_Hall/scripts.pory"

# 441 "data//maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_LoveSludgeBombButTrendInToo:
# 442 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "I love SLUDGE BOMB.\p"
# 443 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "But POKéMON with the move\n"
# 444 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "“{STR_VAR_1}”\l"
# 445 "data//maps/DewfordTown_Hall/scripts.pory"
	.string "are in, too.$"
