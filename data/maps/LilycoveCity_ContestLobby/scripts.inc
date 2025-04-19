# 1 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 2 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
@ Note: data/scripts/berry_blender.inc is for the same map, so shares local IDs
# 3 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
.set LOCALID_RECEPTIONIST, 1
# 4 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
.set LOCALID_LINK_RECEPTIONIST, 2
# 5 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
.set LOCALID_ARTIST, 4
# 6 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
.set LOCALID_ARTIST_LINK, 11
# 7 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 8 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_MapScripts::
# 9 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_ContestLobby_OnTransition
# 10 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LilycoveCity_ContestLobby_OnFrame
# 11 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.byte 0
# 12 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 13 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
@ Some scripts for this room are split into data/scripts/contest_hall and data/scripts/berry_blender
# 14 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 15 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_OnTransition:
# 16 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	call LilycoveCity_ContestLobby_EventScript_TryShowContestReporter
# 17 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	call LilycoveCity_ContestLobby_EventScript_TryShowBlendMaster
# 18 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 19 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 20 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_TryShowBlendMaster::
# 21 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	getpokenewsactive POKENEWS_BLENDMASTER
# 22 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_ContestLobby_EventScript_ShowBlendMaster
# 23 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	clearflag FLAG_HIDE_LILYCOVE_CONTEST_HALL_BLEND_MASTER_REPLACEMENT
# 24 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	setflag FLAG_HIDE_LILYCOVE_CONTEST_HALL_BLEND_MASTER
# 25 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	return
# 26 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 27 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_ShowBlendMaster::
# 28 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	setflag FLAG_HIDE_LILYCOVE_CONTEST_HALL_BLEND_MASTER_REPLACEMENT
# 29 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	clearflag FLAG_HIDE_LILYCOVE_CONTEST_HALL_BLEND_MASTER
# 30 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	return
# 31 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 32 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_OnFrame:
# 33 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	map_script_2 VAR_LILYCOVE_CONTEST_LOBBY_STATE, 1, LilycoveCity_ContestLobby_EventScript_TryDoContestArtist
# 34 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	map_script_2 VAR_LILYCOVE_CONTEST_LOBBY_STATE, 2, LilycoveCity_ContestLobby_EventScript_TryDoLinkContestArtist
# 35 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.2byte 0
# 36 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 37 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_TryDoContestArtist::
# 38 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	goto_if_set FLAG_HIDE_LILYCOVE_MUSEUM_CURATOR, LilycoveCity_ContestLobby_EventScript_ContestArtist
# 39 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	setvar VAR_LILYCOVE_CONTEST_LOBBY_STATE, 0
# 40 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 41 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 42 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_ContestArtist::
# 43 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	lockall
# 44 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	addobject LOCALID_ARTIST
# 45 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	applymovement LOCALID_ARTIST, LilycoveCity_ContestLobby_Movement_ArtistApproachPlayer
# 46 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	waitmovement LOCALID_ARTIST
# 47 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LilycoveCity_ContestLobby_Movement_PlayerFaceArtist
# 48 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	waitmovement 0
# 49 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	msgbox LilycoveCity_ContestLobby_Text_YourPokemonSpurredMeToPaint, MSGBOX_DEFAULT
# 50 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	lockall
# 51 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	fadescreen FADE_TO_BLACK
# 52 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	showcontestpainting CONTEST_WINNER_ARTIST
# 53 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	lockall
# 54 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	msgbox LilycoveCity_ContestLobby_Text_ShouldITakePaintingToMuseum, MSGBOX_YESNO
# 55 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	goto_if_eq VAR_RESULT, YES, LilycoveCity_ContestLobby_EventScript_TakePaintingToMuseum
# 56 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	goto_if_eq VAR_RESULT, NO, LilycoveCity_ContestLobby_EventScript_ConfirmDontTakePainting
# 57 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	releaseall
# 58 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 59 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 60 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_TakePaintingToMuseum::
# 61 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	msgbox LilycoveCity_ContestLobby_Text_IllTakePaintingToMuseum, MSGBOX_DEFAULT
# 62 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	closemessage
# 63 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	special SaveMuseumContestPainting
# 64 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	setvar VAR_LILYCOVE_CONTEST_LOBBY_STATE, 0
# 65 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	specialvar VAR_RESULT, GiveMonArtistRibbon
# 66 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	call_if_eq VAR_RESULT, TRUE, LilycoveCity_ContestLobby_EventScript_ReceivedArtistRibbon
# 67 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	applymovement LOCALID_ARTIST, LilycoveCity_ContestLobby_Movement_ArtistExit
# 68 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	waitmovement 0
# 69 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	removeobject LOCALID_ARTIST
# 70 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	call LilycoveCity_ContestLobby_EventScript_UpdateMuseumPatrons
# 71 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	call LilycoveCity_ContestLobby_EventScript_SetPaintingFlag
# 72 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	releaseall
# 73 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 74 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 75 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_ConfirmDontTakePainting::
# 76 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	msgbox LilycoveCity_ContestLobby_Text_TakeHomeButIdLikeToTakeToMuseum, MSGBOX_YESNO
# 77 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	goto_if_eq VAR_RESULT, YES, LilycoveCity_ContestLobby_EventScript_TakePaintingToMuseum
# 78 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	msgbox LilycoveCity_ContestLobby_Text_FineThatsTheWayItIs, MSGBOX_DEFAULT
# 79 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	closemessage
# 80 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	applymovement LOCALID_ARTIST, LilycoveCity_ContestLobby_Movement_ArtistExit
# 81 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	waitmovement 0
# 82 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	setvar VAR_LILYCOVE_CONTEST_LOBBY_STATE, 0
# 83 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	removeobject LOCALID_ARTIST
# 84 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	releaseall
# 85 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 86 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 87 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_ReceivedArtistRibbon::
# 88 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	incrementgamestat GAME_STAT_RECEIVED_RIBBONS
# 89 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	special BufferContestWinnerMonName
# 90 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	applymovement LOCALID_ARTIST, LilycoveCity_ContestLobby_Movement_ArtistBeginToExit
# 91 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	waitmovement 0
# 92 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	playse SE_PIN
# 93 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	applymovement LOCALID_ARTIST, Common_Movement_ExclamationMark
# 94 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	waitmovement 0
# 95 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	applymovement LOCALID_ARTIST, LilycoveCity_ContestLobby_Movement_ArtistReturnToPlayer
# 96 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	waitmovement 0
# 97 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	msgbox LilycoveCity_ContestLobby_Text_TakeMementoOfPainting, MSGBOX_DEFAULT
# 98 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 99 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	msgbox LilycoveCity_ContestLobby_Text_ReceivedARibbon, MSGBOX_DEFAULT
# 100 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	waitfanfare
# 101 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	msgbox LilycoveCity_ContestLobby_Text_PutTheRibbonOnMon, MSGBOX_DEFAULT
# 102 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	msgbox LilycoveCity_ContestLobby_Text_OkaySeeYou, MSGBOX_DEFAULT
# 103 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	closemessage
# 104 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	return
# 105 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 106 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_UpdateMuseumPatrons::
# 107 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	specialvar VAR_0x8004, CountPlayerMuseumPaintings
# 108 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	switch VAR_0x8004
# 109 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	case 1, LilycoveCity_ContestLobby_EventScript_ShowPatron1
# 110 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	case 2, LilycoveCity_ContestLobby_EventScript_ShowPatron2
# 111 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	case 3, LilycoveCity_ContestLobby_EventScript_ShowPatron3
# 112 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	case 4, LilycoveCity_ContestLobby_EventScript_ShowPatron4
# 113 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	case 5, LilycoveCity_ContestLobby_EventScript_ShowTourists
# 114 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	return
# 115 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 116 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_ShowPatron1::
# 117 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	clearflag FLAG_HIDE_LILYCOVE_MUSEUM_PATRON_1
# 118 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	return
# 119 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 120 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_ShowPatron2::
# 121 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	clearflag FLAG_HIDE_LILYCOVE_MUSEUM_PATRON_2
# 122 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	return
# 123 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 124 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_ShowPatron3::
# 125 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	clearflag FLAG_HIDE_LILYCOVE_MUSEUM_PATRON_3
# 126 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	return
# 127 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 128 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_ShowPatron4::
# 129 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	clearflag FLAG_HIDE_LILYCOVE_MUSEUM_PATRON_4
# 130 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	return
# 131 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 132 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_ShowTourists::
# 133 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	clearflag FLAG_HIDE_LILYCOVE_MUSEUM_TOURISTS
# 134 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	return
# 135 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 136 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_SetPaintingFlag::
# 137 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	switch VAR_CONTEST_CATEGORY
# 138 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	case CONTEST_CATEGORY_COOL, LilycoveCity_ContestLobby_EventScript_MadeCoolPainting
# 139 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	case CONTEST_CATEGORY_BEAUTY, LilycoveCity_ContestLobby_EventScript_MadeBeautyPainting
# 140 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	case CONTEST_CATEGORY_CUTE, LilycoveCity_ContestLobby_EventScript_MadeCutePainting
# 141 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	case CONTEST_CATEGORY_SMART, LilycoveCity_ContestLobby_EventScript_MadeSmartPainting
# 142 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	case CONTEST_CATEGORY_TOUGH, LilycoveCity_ContestLobby_EventScript_MadeToughPainting
# 143 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	return
# 144 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 145 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_MadeCoolPainting::
# 146 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	setflag FLAG_COOL_PAINTING_MADE
# 147 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	return
# 148 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 149 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_MadeBeautyPainting::
# 150 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	setflag FLAG_BEAUTY_PAINTING_MADE
# 151 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	return
# 152 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 153 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_MadeCutePainting::
# 154 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	setflag FLAG_CUTE_PAINTING_MADE
# 155 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	return
# 156 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 157 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_MadeSmartPainting::
# 158 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	setflag FLAG_SMART_PAINTING_MADE
# 159 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	return
# 160 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 161 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_MadeToughPainting::
# 162 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	setflag FLAG_TOUGH_PAINTING_MADE
# 163 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	return
# 164 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 165 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_Movement_ArtistApproachPlayer:
# 166 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_down
# 167 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_down
# 168 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_down
# 169 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_right
# 170 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_right
# 171 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_right
# 172 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_right
# 173 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	step_end
# 174 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 175 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_Movement_ArtistExit:
# 176 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_down
# 177 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_down
# 178 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_down
# 179 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_down
# 180 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_down
# 181 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_down
# 182 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_down
# 183 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_down
# 184 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	step_end
# 185 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 186 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_Movement_PlayerFaceArtist:
# 187 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_in_place_faster_left
# 188 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	step_end
# 189 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 190 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_Movement_ArtistBeginToExit:
# 191 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_down
# 192 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_down
# 193 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_down
# 194 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	step_end
# 195 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 196 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_Movement_ArtistReturnToPlayer:
# 197 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	delay_16
# 198 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	delay_16
# 199 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	delay_16
# 200 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	delay_16
# 201 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_fast_up
# 202 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_fast_up
# 203 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_fast_up
# 204 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_in_place_faster_right
# 205 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	step_end
# 206 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 207 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_TryDoLinkContestArtist::
# 208 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	goto_if_set FLAG_HIDE_LILYCOVE_MUSEUM_CURATOR, LilycoveCity_ContestLobby_EventScript_LinkContestArtist
# 209 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	setvar VAR_LILYCOVE_CONTEST_LOBBY_STATE, 0
# 210 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 211 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 212 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_LinkContestArtist::
# 213 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	lockall
# 214 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	addobject LOCALID_ARTIST_LINK
# 215 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	applymovement LOCALID_ARTIST_LINK, LilycoveCity_ContestLobby_Movement_LinkArtistApproachPlayer
# 216 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	waitmovement LOCALID_ARTIST_LINK
# 217 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LilycoveCity_ContestLobby_Movement_PlayerFaceLinkArtist
# 218 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	waitmovement 0
# 219 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	msgbox LilycoveCity_ContestLobby_Text_YourPokemonSpurredMeToPaint, MSGBOX_DEFAULT
# 220 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	lockall
# 221 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	fadescreen FADE_TO_BLACK
# 222 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	showcontestpainting CONTEST_WINNER_ARTIST
# 223 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	msgbox LilycoveCity_ContestLobby_Text_ShouldITakePaintingToMuseum, MSGBOX_YESNO
# 224 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	goto_if_eq VAR_RESULT, YES, LilycoveCity_ContestLobby_EventScript_TakePaintingToMuseumLink
# 225 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	goto_if_eq VAR_RESULT, NO, LilycoveCity_ContestLobby_EventScript_ConfirmDontTakePaintingLink
# 226 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 227 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 228 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_TakePaintingToMuseumLink::
# 229 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	msgbox LilycoveCity_ContestLobby_Text_IllTakePaintingToMuseum, MSGBOX_DEFAULT
# 230 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	closemessage
# 231 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	special SaveMuseumContestPainting
# 232 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	setvar VAR_LILYCOVE_CONTEST_LOBBY_STATE, 0
# 233 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	specialvar VAR_RESULT, GiveMonArtistRibbon
# 234 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	call_if_eq VAR_RESULT, TRUE, LilycoveCity_ContestLobby_EventScript_ReceivedLinkArtistRibbon
# 235 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	applymovement LOCALID_ARTIST_LINK, LilycoveCity_ContestLobby_Movement_LinkArtistExit
# 236 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	waitmovement 0
# 237 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	removeobject LOCALID_ARTIST_LINK
# 238 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	call LilycoveCity_ContestLobby_EventScript_UpdateMuseumPatrons
# 239 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	call LilycoveCity_ContestLobby_EventScript_SetPaintingFlag
# 240 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	releaseall
# 241 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 242 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 243 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_ConfirmDontTakePaintingLink::
# 244 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	msgbox LilycoveCity_ContestLobby_Text_TakeHomeButIdLikeToTakeToMuseum, MSGBOX_YESNO
# 245 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	goto_if_eq VAR_RESULT, YES, LilycoveCity_ContestLobby_EventScript_TakePaintingToMuseumLink
# 246 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	msgbox LilycoveCity_ContestLobby_Text_FineThatsTheWayItIs, MSGBOX_DEFAULT
# 247 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	closemessage
# 248 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	applymovement LOCALID_ARTIST_LINK, LilycoveCity_ContestLobby_Movement_LinkArtistExit
# 249 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	waitmovement 0
# 250 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	setvar VAR_LILYCOVE_CONTEST_LOBBY_STATE, 0
# 251 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	removeobject LOCALID_ARTIST_LINK
# 252 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	releaseall
# 253 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 254 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 255 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_ReceivedLinkArtistRibbon::
# 256 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	incrementgamestat GAME_STAT_RECEIVED_RIBBONS
# 257 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	setflag FLAG_SYS_RIBBON_GET
# 258 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	special BufferContestWinnerMonName
# 259 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	applymovement LOCALID_ARTIST_LINK, LilycoveCity_ContestLobby_Movement_LinkArtistBeginExit
# 260 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	waitmovement 0
# 261 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	playse SE_PIN
# 262 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	applymovement LOCALID_ARTIST_LINK, Common_Movement_ExclamationMark
# 263 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	waitmovement 0
# 264 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	applymovement LOCALID_ARTIST_LINK, LilycoveCity_ContestLobby_Movement_LinkArtistReturnToPlayer
# 265 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	waitmovement 0
# 266 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	msgbox LilycoveCity_ContestLobby_Text_TakeMementoOfPainting, MSGBOX_DEFAULT
# 267 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 268 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	msgbox LilycoveCity_ContestLobby_Text_ReceivedARibbon, MSGBOX_DEFAULT
# 269 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	waitfanfare
# 270 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	msgbox LilycoveCity_ContestLobby_Text_PutTheRibbonOnMon, MSGBOX_DEFAULT
# 271 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	msgbox LilycoveCity_ContestLobby_Text_OkaySeeYou, MSGBOX_DEFAULT
# 272 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	closemessage
# 273 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	return
# 274 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 275 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_Movement_LinkArtistApproachPlayer:
# 276 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_down
# 277 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_down
# 278 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_down
# 279 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_left
# 280 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_left
# 281 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_left
# 282 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_left
# 283 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_left
# 284 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	step_end
# 285 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 286 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_Movement_LinkArtistExit:
# 287 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_down
# 288 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_down
# 289 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_down
# 290 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_down
# 291 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_down
# 292 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_down
# 293 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_down
# 294 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_down
# 295 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	step_end
# 296 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 297 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_Movement_PlayerFaceLinkArtist:
# 298 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_in_place_faster_right
# 299 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	step_end
# 300 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 301 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_Movement_LinkArtistBeginExit:
# 302 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_down
# 303 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_down
# 304 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_down
# 305 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	step_end
# 306 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 307 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_Movement_LinkArtistReturnToPlayer:
# 308 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	delay_16
# 309 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	delay_16
# 310 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	delay_16
# 311 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	delay_16
# 312 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_fast_up
# 313 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_fast_up
# 314 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_fast_up
# 315 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_in_place_faster_left
# 316 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	step_end
# 317 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 318 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
@ EventScript_SpeakToContestReceptionist either ends or returns after a contest entry is submitted
# 319 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_ContestReceptionist::
# 320 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	special ClearLinkContestFlags
# 321 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	specialvar VAR_RESULT, IsContestDebugActive  @ Always FALSE
# 322 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_ContestLobby_EventScript_SetDebug
# 323 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	call LilycoveCity_ContestLobby_EventScript_SpeakToContestReceptionist
# 324 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	call LilycoveCity_ContestLobby_EventScript_LeadToContestHall
# 325 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	special SetContestTrainerGfxIds
# 326 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	call LilycoveCity_ContestLobby_EventScript_SetPlayerGfx
# 327 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	call LilycoveCity_ContestLobby_EventScript_SetContestType
# 328 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	call LilycoveCity_ContestLobby_EventScript_WarpToContestHall
# 329 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	waitstate
# 330 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 331 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 332 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_SetContestType::
# 333 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	switch VAR_CONTEST_RANK
# 334 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	case CONTEST_RANK_NORMAL, LilycoveCity_ContestLobby_EventScript_SetNormalContestType
# 335 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	case CONTEST_RANK_SUPER, LilycoveCity_ContestLobby_EventScript_SetSuperContestType
# 336 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	case CONTEST_RANK_HYPER, LilycoveCity_ContestLobby_EventScript_SetHyperContestType
# 337 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	case CONTEST_RANK_MASTER, LilycoveCity_ContestLobby_EventScript_SetMasterContestType
# 338 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	return
# 339 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 340 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_SetNormalContestType::
# 341 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	setvar VAR_CONTEST_TYPE, CONTEST_TYPE_NPC_NORMAL
# 342 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	return
# 343 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 344 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_SetSuperContestType::
# 345 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	setvar VAR_CONTEST_TYPE, CONTEST_TYPE_NPC_SUPER
# 346 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	return
# 347 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 348 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_SetHyperContestType::
# 349 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	setvar VAR_CONTEST_TYPE, CONTEST_TYPE_NPC_HYPER
# 350 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	return
# 351 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 352 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_SetMasterContestType::
# 353 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	setvar VAR_CONTEST_TYPE, CONTEST_TYPE_NPC_MASTER
# 354 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	return
# 355 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 356 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
@ Functionally unused
# 357 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_SetDebug::
# 358 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	setflag FLAG_HIDE_LILYCOVE_MUSEUM_CURATOR
# 359 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	copyvar VAR_LILYCOVE_MUSEUM_2F_STATE, 1
# 360 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	additem ITEM_CONTEST_PASS
# 361 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	setvar VAR_0x800B, 8
# 362 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	setvar VAR_CONTEST_RANK, CONTEST_RANK_MASTER
# 363 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	setvar VAR_LILYCOVE_CONTEST_LOBBY_STATE, 1
# 364 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	setflag FLAG_SYS_RIBBON_GET
# 365 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 366 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 367 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_WarpToContestHall::
# 368 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	setflag FLAG_ENTERED_CONTEST
# 369 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	switch VAR_CONTEST_CATEGORY
# 370 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	case CONTEST_CATEGORY_COOL, LilycoveCity_ContestLobby_EventScript_WarpToCoolContestHall
# 371 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	case CONTEST_CATEGORY_BEAUTY, LilycoveCity_ContestLobby_EventScript_WarpToBeautyContestHall
# 372 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	case CONTEST_CATEGORY_CUTE, LilycoveCity_ContestLobby_EventScript_WarpToCuteContestHall
# 373 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	case CONTEST_CATEGORY_SMART, LilycoveCity_ContestLobby_EventScript_WarpToSmartContestHall
# 374 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	case CONTEST_CATEGORY_TOUGH, LilycoveCity_ContestLobby_EventScript_WarpToToughContestHall
# 375 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	return
# 376 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 377 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_WarpToCoolContestHall::
# 378 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	setwarp MAP_CONTEST_HALL_COOL, 7, 5
# 379 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	special DoContestHallWarp
# 380 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	waitstate
# 381 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	return
# 382 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 383 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_WarpToBeautyContestHall::
# 384 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	setwarp MAP_CONTEST_HALL_BEAUTY, 7, 5
# 385 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	special DoContestHallWarp
# 386 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	waitstate
# 387 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	return
# 388 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 389 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_WarpToCuteContestHall::
# 390 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	setwarp MAP_CONTEST_HALL_CUTE, 7, 5
# 391 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	special DoContestHallWarp
# 392 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	waitstate
# 393 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	return
# 394 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 395 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_WarpToSmartContestHall::
# 396 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	setwarp MAP_CONTEST_HALL_SMART, 7, 5
# 397 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	special DoContestHallWarp
# 398 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	waitstate
# 399 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	return
# 400 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 401 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_WarpToToughContestHall::
# 402 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	setwarp MAP_CONTEST_HALL_TOUGH, 7, 5
# 403 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	special DoContestHallWarp
# 404 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	waitstate
# 405 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	return
# 406 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 407 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_LeadToContestHall::
# 408 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	lockall
# 409 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	applymovement LOCALID_RECEPTIONIST, LilycoveCity_ContestLobby_Movement_ReceptionistApproachCounter
# 410 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	waitmovement 0
# 411 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	playse SE_BRIDGE_WALK
# 412 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	setmetatile 12, 2, METATILE_Contest_WallShadow, TRUE
# 413 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	setmetatile 12, 3, METATILE_Contest_FloorShadow, TRUE
# 414 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	special DrawWholeMapView
# 415 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	applymovement LOCALID_RECEPTIONIST, LilycoveCity_ContestLobby_Movement_ReceptionistExitCounter
# 416 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	waitmovement 0
# 417 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	playse SE_BRIDGE_WALK
# 418 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	setmetatile 12, 2, METATILE_Contest_CounterFlap_Top, TRUE
# 419 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	setmetatile 12, 3, METATILE_Contest_CounterFlap_Bottom, TRUE
# 420 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	special DrawWholeMapView
# 421 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	delay 20
# 422 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	applymovement LOCALID_RECEPTIONIST, LilycoveCity_ContestLobby_Movement_ReceptionistFacePlayer
# 423 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	waitmovement 0
# 424 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LilycoveCity_ContestLobby_Movement_PlayerApproachReceptionist
# 425 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	waitmovement 0
# 426 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	msgbox LilycoveCity_ContestLobby_Text_ComeThroughHere, MSGBOX_DEFAULT
# 427 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	closemessage
# 428 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	applymovement LOCALID_RECEPTIONIST, LilycoveCity_ContestLobby_Movement_ReceptionistWalkToContestHall
# 429 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LilycoveCity_ContestLobby_Movement_PlayerWalkToContestHall
# 430 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	waitmovement 0
# 431 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	releaseall
# 432 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	return
# 433 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 434 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_Movement_PlayerWalkToContestHall:
# 435 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_left
# 436 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_left
# 437 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_left
# 438 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_left
# 439 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_up
# 440 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_up
# 441 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_up
# 442 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	delay_8
# 443 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	set_invisible
# 444 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	step_end
# 445 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 446 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_Movement_PlayerApproachReceptionist:
# 447 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_in_place_faster_left
# 448 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_left
# 449 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	step_end
# 450 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 451 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_Movement_ReceptionistApproachCounter:
# 452 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_left
# 453 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_left
# 454 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_in_place_faster_down
# 455 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	step_end
# 456 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 457 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_Movement_ReceptionistExitCounter:
# 458 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_down
# 459 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_down
# 460 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_in_place_faster_up
# 461 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	step_end
# 462 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 463 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_Movement_ReceptionistWalkToContestHall:
# 464 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_left
# 465 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_left
# 466 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_left
# 467 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_up
# 468 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_up
# 469 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_up
# 470 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	delay_8
# 471 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	set_invisible
# 472 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	step_end
# 473 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 474 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_Movement_ReceptionistFacePlayer:
# 475 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_in_place_faster_right
# 476 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	step_end
# 477 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 478 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_BlackBelt::
# 479 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	msgbox LilycoveCity_ContestLobby_Text_MasterRankHereICome, MSGBOX_NPC
# 480 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 481 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 482 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_Girl::
# 483 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	msgbox LilycoveCity_ContestLobby_Text_WholeVarietyOfPokemonHere, MSGBOX_NPC
# 484 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 485 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 486 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_Artist::
# 487 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	msgbox LilycoveCity_ContestLobby_Text_ContestFeastForEyes, MSGBOX_NPC
# 488 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 489 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 490 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_FatMan::
# 491 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	msgbox LilycoveCity_ContestLobby_Text_ToughContestIsExtreme, MSGBOX_NPC
# 492 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 493 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 494 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_Fisherman::
# 495 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	msgbox LilycoveCity_ContestLobby_Text_LavishedCareOnMon, MSGBOX_NPC
# 496 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 497 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 498 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_NinjaBoy::
# 499 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	msgbox LilycoveCity_ContestLobby_Text_MadePokeblocksWithFamily, MSGBOX_NPC
# 500 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 501 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 502 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_ContestWinner1::
# 503 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	lockall
# 504 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	fadescreen FADE_TO_BLACK
# 505 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	showcontestpainting CONTEST_WINNER_HALL_1
# 506 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	releaseall
# 507 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 508 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 509 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_ContestWinner2::
# 510 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	lockall
# 511 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	fadescreen FADE_TO_BLACK
# 512 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	showcontestpainting CONTEST_WINNER_HALL_2
# 513 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	releaseall
# 514 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 515 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 516 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_ContestWinner3::
# 517 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	lockall
# 518 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	fadescreen FADE_TO_BLACK
# 519 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	showcontestpainting CONTEST_WINNER_HALL_3
# 520 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	releaseall
# 521 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 522 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 523 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_ContestWinner4::
# 524 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	lockall
# 525 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	fadescreen FADE_TO_BLACK
# 526 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	showcontestpainting CONTEST_WINNER_HALL_4
# 527 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	releaseall
# 528 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 529 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 530 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_ContestWinner5::
# 531 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	lockall
# 532 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	fadescreen FADE_TO_BLACK
# 533 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	showcontestpainting CONTEST_WINNER_HALL_5
# 534 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	releaseall
# 535 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 536 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 537 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_ContestWinner6::
# 538 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	lockall
# 539 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	fadescreen FADE_TO_BLACK
# 540 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	showcontestpainting CONTEST_WINNER_HALL_6
# 541 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	releaseall
# 542 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 543 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 544 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_Blender3Boy::
# 545 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	msgbox BerryBlender_Text_LetsGetBlendingAlready, MSGBOX_NPC
# 546 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 547 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 548 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_Blender3Girl::
# 549 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	msgbox BerryBlender_Text_WhatKindOfPokeblockWillIGet, MSGBOX_NPC
# 550 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 551 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 552 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_BerryBlenderSpeedRecords::
# 553 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	lockall
# 554 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	special ShowBerryBlenderRecordWindow
# 555 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	waitbuttonpress
# 556 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	special RemoveRecordsWindow
# 557 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	releaseall
# 558 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 559 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 560 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_LinkContestResults::
# 561 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	lockall
# 562 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	frontier_results FACILITY_LINK_CONTEST
# 563 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	waitbuttonpress
# 564 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	special RemoveRecordsWindow
# 565 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	releaseall
# 566 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 567 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 568 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_BlendMaster::
# 569 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	lock
# 570 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	faceplayer
# 571 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	msgbox BerryBlender_Text_BlendWithTheBlendMaster, MSGBOX_DEFAULT
# 572 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	goto LilycoveCity_ContestLobby_EventScript_FaceOriginalDirection
# 573 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 574 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 575 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_BlendMasterOnlooker1::
# 576 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	lock
# 577 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	msgbox BerryBlender_Text_WhoaAwesome, MSGBOX_DEFAULT
# 578 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	release
# 579 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 580 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 581 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_BlendMasterOnlooker2::
# 582 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	lock
# 583 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	msgbox BerryBlender_Text_WickedlyFast, MSGBOX_DEFAULT
# 584 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	release
# 585 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 586 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 587 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_BlendMasterOnlooker3::
# 588 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	lock
# 589 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	msgbox BerryBlender_Text_WhatAnExpert, MSGBOX_DEFAULT
# 590 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	release
# 591 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 592 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 593 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_BlendMasterOnlooker4::
# 594 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	lock
# 595 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	faceplayer
# 596 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	msgbox BerryBlender_Text_MadeAmazingPokeblocksWithMaster, MSGBOX_DEFAULT
# 597 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	goto LilycoveCity_ContestLobby_EventScript_FaceOriginalDirection
# 598 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 599 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 600 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_BlendMasterOnlooker5::
# 601 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	lock
# 602 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	faceplayer
# 603 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	msgbox BerryBlender_Text_QualitiesOfBlendMaster, MSGBOX_DEFAULT
# 604 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	goto LilycoveCity_ContestLobby_EventScript_FaceOriginalDirection
# 605 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 606 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 607 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_BlendMasterOnlooker6::
# 608 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	lock
# 609 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	faceplayer
# 610 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	msgbox BerryBlender_Text_MasterWorksOnSkillsInMountains, MSGBOX_DEFAULT
# 611 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	goto LilycoveCity_ContestLobby_EventScript_FaceOriginalDirection
# 612 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 613 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 614 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_FaceOriginalDirection::
# 615 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	closemessage
# 616 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 617 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	waitmovement 0
# 618 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	release
# 619 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 620 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 621 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_LinkContestReceptionist::
# 622 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	special ClearLinkContestFlags
# 623 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	lock
# 624 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	faceplayer
# 625 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	msgbox LilycoveCity_ContestLobby_Text_LinkContestReception, MSGBOX_DEFAULT
# 626 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	goto LilycoveCity_ContestLobby_EventScript_AskEnterLinkContest
# 627 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 628 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 629 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_AskEnterLinkContest::
# 630 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	message LilycoveCity_ContestLobby_Text_EnterContest3
# 631 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	waitmessage
# 632 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	multichoice 0, 0, MULTI_ENTERINFO, FALSE
# 633 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	switch VAR_RESULT
# 634 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	case 0, LilycoveCity_ContestLobby_EventScript_TryEnterLinkContest
# 635 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	case 1, LilycoveCity_ContestLobby_EventScript_LinkContestInfo
# 636 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	case 2, LilycoveCity_ContestLobby_EventScript_CancelLinkContest
# 637 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	case MULTI_B_PRESSED, LilycoveCity_ContestLobby_EventScript_CancelLinkContest
# 638 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 639 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 640 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_TryEnterLinkContest::
# 641 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	msgbox LilycoveCity_ContestLobby_Text_ProgressWillBeSaved, MSGBOX_YESNO
# 642 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	goto_if_eq VAR_RESULT, NO, LilycoveCity_ContestLobby_EventScript_CancelLinkContest
# 643 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	call Common_EventScript_SaveGame
# 644 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_ContestLobby_EventScript_CancelLinkContest
# 645 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	message LilycoveCity_ContestLobby_Text_WhichContestMode
# 646 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	waitmessage
# 647 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	specialvar VAR_TEMP_D, IsWirelessAdapterConnected
# 648 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	multichoice 0, 0, MULTI_LINK_CONTEST_MODE, FALSE
# 649 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	switch VAR_RESULT
# 650 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	case 0, LilycoveCity_ContestLobby_EventScript_EmeraldMode  @ Shortened to E-Mode
# 651 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	case 1, LilycoveCity_ContestLobby_EventScript_GlobalMode   @ Shortened to G-Mode
# 652 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	case 2, LilycoveCity_ContestLobby_EventScript_CancelLinkContest
# 653 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	case MULTI_B_PRESSED, LilycoveCity_ContestLobby_EventScript_CancelLinkContest
# 654 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 655 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 656 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_EmeraldMode::
# 657 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	setvar VAR_TEMP_C, 0
# 658 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	goto LilycoveCity_ContestLobby_EventScript_ChooseLinkContestType
# 659 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 660 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 661 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_GlobalMode::
# 662 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	setvar VAR_TEMP_C, 1
# 663 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	goto_if_eq VAR_TEMP_D, 1, LilycoveCity_ContestLobby_EventScript_CancelLinkNoWirelessGMode
# 664 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	goto LilycoveCity_ContestLobby_EventScript_ChooseLinkContestType
# 665 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 666 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 667 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_ChooseLinkContestType::
# 668 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	message LilycoveCity_ContestLobby_Text_EnterWhichContest3
# 669 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	waitmessage
# 670 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	multichoice 0, 0, MULTI_CONTEST_TYPE, FALSE
# 671 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	switch VAR_RESULT
# 672 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	case CONTEST_CATEGORIES_COUNT, LilycoveCity_ContestLobby_EventScript_CancelLinkContest
# 673 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	case MULTI_B_PRESSED, LilycoveCity_ContestLobby_EventScript_CancelLinkContest
# 674 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	copyvar VAR_CONTEST_CATEGORY, VAR_RESULT
# 675 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	goto LilycoveCity_ContestLobby_EventScript_ChooseLinkContestMon
# 676 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 677 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 678 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_LinkContestInfo::
# 679 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	message LilycoveCity_ContestLobby_Text_WhichTopic2
# 680 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	waitmessage
# 681 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	multichoice 0, 0, MULTI_LINK_CONTEST_INFO, FALSE
# 682 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	switch VAR_RESULT
# 683 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	case 0, LilycoveCity_ContestLobby_EventScript_ExplainLinkContest
# 684 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	case 1, LilycoveCity_ContestLobby_EventScript_ExplainEMode
# 685 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	case 2, LilycoveCity_ContestLobby_EventScript_ExplainGMode
# 686 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	case 3, LilycoveCity_ContestLobby_EventScript_AskEnterLinkContest
# 687 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	case MULTI_B_PRESSED, LilycoveCity_ContestLobby_EventScript_AskEnterLinkContest
# 688 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 689 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 690 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_ExplainLinkContest::
# 691 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	msgbox LilycoveCity_ContestLobby_Text_ExplainLinkContest, MSGBOX_DEFAULT
# 692 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	goto LilycoveCity_ContestLobby_EventScript_LinkContestInfo
# 693 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 694 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 695 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_ExplainEMode::
# 696 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	msgbox LilycoveCity_ContestLobby_Text_ExplainEMode, MSGBOX_DEFAULT
# 697 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	goto LilycoveCity_ContestLobby_EventScript_LinkContestInfo
# 698 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 699 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 700 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_ExplainGMode::
# 701 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	msgbox LilycoveCity_ContestLobby_Text_ExplainGMode, MSGBOX_DEFAULT
# 702 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	goto LilycoveCity_ContestLobby_EventScript_LinkContestInfo
# 703 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 704 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 705 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_CancelLinkContest::
# 706 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	special CloseLink
# 707 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	msgbox LilycoveCity_ContestLobby_Text_ParticipateAnotherTime, MSGBOX_DEFAULT
# 708 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	release
# 709 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 710 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 711 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_ChooseLinkContestMon::
# 712 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	msgbox LilycoveCity_ContestLobby_Text_EnterWhichPokemon3, MSGBOX_DEFAULT
# 713 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	setvar VAR_CONTEST_RANK, 0
# 714 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	choosecontestmon
# 715 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, LilycoveCity_ContestLobby_EventScript_CancelLinkContest
# 716 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	special TryEnterContestMon
# 717 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	goto_if_eq VAR_RESULT, CANT_ENTER_CONTEST, LilycoveCity_ContestLobby_EventScript_LinkCantEnterLowRank
# 718 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	goto_if_eq VAR_RESULT, CAN_ENTER_CONTEST_EQUAL_RANK, LilycoveCity_ContestLobby_EventScript_EnterMonForLinkContest
# 719 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	goto_if_eq VAR_RESULT, CAN_ENTER_CONTEST_HIGH_RANK, LilycoveCity_ContestLobby_EventScript_EnterMonForLinkContest
# 720 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	goto_if_eq VAR_RESULT, CANT_ENTER_CONTEST_EGG, LilycoveCity_ContestLobby_EventScript_LinkCantEnterEgg
# 721 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	goto_if_eq VAR_RESULT, CANT_ENTER_CONTEST_FAINTED, LilycoveCity_ContestLobby_EventScript_LinkCantEnterFainted
# 722 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 723 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 724 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_LinkCantEnterLowRank::
# 725 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	msgbox LilycoveCity_ContestLobby_Text_MonNotQualifiedForRank, MSGBOX_DEFAULT
# 726 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	goto LilycoveCity_ContestLobby_EventScript_ChooseLinkContestMon
# 727 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 728 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 729 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_LinkCantEnterEgg::
# 730 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	msgbox LilycoveCity_ContestLobby_Text_EggCannotTakePart2, MSGBOX_DEFAULT
# 731 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	goto LilycoveCity_ContestLobby_EventScript_ChooseLinkContestMon
# 732 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 733 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 734 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_LinkCantEnterFainted::
# 735 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	msgbox LilycoveCity_ContestLobby_Text_MonInNoCondition2, MSGBOX_DEFAULT
# 736 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	goto LilycoveCity_ContestLobby_EventScript_ChooseLinkContestMon
# 737 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 738 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 739 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_EnterMonForLinkContest::
# 740 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	copyvar VAR_0x8008, VAR_0x8004
# 741 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	goto LilycoveCity_ContestLobby_EventScript_TrySetUpLinkContest
# 742 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 743 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 744 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_TrySetUpLinkContest::
# 745 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	goto_if_eq VAR_TEMP_D, 1, LilycoveCity_ContestLobby_EventScript_SetLinkGroupType
# 746 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	goto_if_ge VAR_TEMP_D, 2, LilycoveCity_ContestLobby_EventScript_CancelLinkContest
# 747 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	message LilycoveCity_ContestLobby_Text_PleaseWaitBButtonCancel
# 748 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	waitmessage
# 749 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 750 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	call_if_eq VAR_TEMP_C, 0, LilycoveCity_ContestLobby_EventScript_TryLinkEMode
# 751 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	call_if_eq VAR_TEMP_C, 1, LilycoveCity_ContestLobby_EventScript_TryLinkGMode
# 752 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	goto_if_ge VAR_TEMP_C, 2, LilycoveCity_ContestLobby_EventScript_CancelLinkContest
# 753 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	goto_if_eq VAR_RESULT, LINKUP_WRONG_NUM_PLAYERS, LilycoveCity_ContestLobby_EventScript_CancelLinkDifferentChoices
# 754 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	goto_if_eq VAR_RESULT, LINKUP_DIFF_SELECTIONS, LilycoveCity_ContestLobby_EventScript_CancelLinkDifferentChoices
# 755 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	goto_if_eq VAR_RESULT, LINKUP_FAILED, LilycoveCity_ContestLobby_EventScript_CancelLinkContest
# 756 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	goto_if_eq VAR_RESULT, LINKUP_CONNECTION_ERROR, LilycoveCity_ContestLobby_EventScript_CancelLinkError
# 757 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	goto_if_eq VAR_RESULT, LINKUP_FAILED_CONTEST_GMODE, LilycoveCity_ContestLobby_EventScript_CancelLinkModeDifference
# 758 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	messageinstant LilycoveCity_ContestLobby_Text_Transmitting
# 759 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	contestlinktransfer
# 760 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	switch VAR_0x8004
# 761 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	case 0, LilycoveCity_ContestLobby_EventScript_StartLinkContest
# 762 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	case 1, LilycoveCity_ContestLobby_EventScript_CancelLinkDifferentContest
# 763 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	case 2, LilycoveCity_ContestLobby_EventScript_CancelLinkTransmissionError
# 764 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 765 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 766 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_TryLinkEMode::
# 767 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	special TryContestEModeLinkup
# 768 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	waitstate
# 769 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	return
# 770 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 771 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_TryLinkGMode::
# 772 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	special TryContestGModeLinkup
# 773 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	waitstate
# 774 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	return
# 775 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 776 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_CancelLinkDifferentContest::
# 777 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	msgbox LilycoveCity_ContestLobby_Text_PlayersChoseDifferentContest, MSGBOX_DEFAULT
# 778 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	goto LilycoveCity_ContestLobby_EventScript_CancelLinkContest
# 779 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 780 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 781 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_CancelLinkDifferentChoices::
# 782 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	msgbox LilycoveCity_ContestLobby_Text_PlayersMadeDifferentChoice, MSGBOX_DEFAULT
# 783 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	goto LilycoveCity_ContestLobby_EventScript_CancelLinkContest
# 784 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 785 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 786 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_CancelLinkModeDifference::
# 787 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	msgbox LilycoveCity_ContestLobby_Text_PlayerAt4PCounterUseGMode, MSGBOX_DEFAULT
# 788 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	goto LilycoveCity_ContestLobby_EventScript_CancelLinkContest
# 789 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 790 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 791 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_CancelLinkError::
# 792 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	special CloseLink
# 793 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	msgbox Text_LinkErrorPleaseReset, MSGBOX_DEFAULT
# 794 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	release
# 795 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 796 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 797 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_CancelLinkNoWirelessGMode::
# 798 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	special CloseLink
# 799 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	msgbox LilycoveCity_ContestLobby_Text_NoWirelessAdapterInGMode, MSGBOX_DEFAULT
# 800 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	release
# 801 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 802 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 803 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_CancelLinkTransmissionError::
# 804 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	msgbox LilycoveCity_ContestLobby_Text_TransmissionError, MSGBOX_DEFAULT
# 805 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	goto LilycoveCity_ContestLobby_EventScript_CancelLinkContest
# 806 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 807 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 808 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_StartLinkContest::
# 809 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	special GetContestPlayerId
# 810 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	addvar VAR_0x8004, 1
# 811 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	buffernumberstring STR_VAR_2, VAR_0x8004
# 812 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	messageautoscroll LilycoveCity_ContestLobby_Text_YourMonIsEntryNumX
# 813 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	waitmessage
# 814 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	subvar VAR_0x8004, 1
# 815 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	call LilycoveCity_ContestLobby_EventScript_LeadToLinkContestHall
# 816 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	setvar VAR_CONTEST_HALL_STATE, 1
# 817 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	special SetLinkContestPlayerGfx
# 818 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	setvar VAR_CONTEST_TYPE, CONTEST_TYPE_LINK
# 819 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	setvar VAR_CONTEST_RANK, CONTEST_RANK_MASTER
# 820 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	call LilycoveCity_ContestLobby_EventScript_WarpToContestHall
# 821 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 822 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 823 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_SetLinkGroupType::
# 824 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	call_if_eq VAR_CONTEST_CATEGORY, CONTEST_CATEGORY_COOL, LilycoveCity_ContestLobby_EventScript_SetLinkGroupCoolContest
# 825 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	call_if_eq VAR_CONTEST_CATEGORY, CONTEST_CATEGORY_BEAUTY, LilycoveCity_ContestLobby_EventScript_SetLinkGroupBeautyContest
# 826 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	call_if_eq VAR_CONTEST_CATEGORY, CONTEST_CATEGORY_CUTE, LilycoveCity_ContestLobby_EventScript_SetLinkGroupCuteContest
# 827 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	call_if_eq VAR_CONTEST_CATEGORY, CONTEST_CATEGORY_SMART, LilycoveCity_ContestLobby_EventScript_SetLinkGroupSmartContest
# 828 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	call_if_eq VAR_CONTEST_CATEGORY, CONTEST_CATEGORY_TOUGH, LilycoveCity_ContestLobby_EventScript_SetLinkGroupToughContest
# 829 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	goto LilycoveCity_ContestLobby_EventScript_DecideLinkLeader
# 830 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 831 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 832 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_SetLinkGroupCoolContest::
# 833 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	setvar VAR_0x8004, LINK_GROUP_COOL_CONTEST
# 834 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	return
# 835 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 836 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_SetLinkGroupBeautyContest::
# 837 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	setvar VAR_0x8004, LINK_GROUP_BEAUTY_CONTEST
# 838 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	return
# 839 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 840 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_SetLinkGroupCuteContest::
# 841 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	setvar VAR_0x8004, LINK_GROUP_CUTE_CONTEST
# 842 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	return
# 843 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 844 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_SetLinkGroupSmartContest::
# 845 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	setvar VAR_0x8004, LINK_GROUP_SMART_CONTEST
# 846 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	return
# 847 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 848 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_SetLinkGroupToughContest::
# 849 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	setvar VAR_0x8004, LINK_GROUP_TOUGH_CONTEST
# 850 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	return
# 851 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 852 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_DecideLinkLeader::
# 853 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	message LilycoveCity_ContestLobby_Text_PleaseDecideLinkLeader
# 854 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	waitmessage
# 855 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	multichoice 16, 6, MULTI_LINK_LEADER, FALSE
# 856 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	switch VAR_RESULT
# 857 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	case 0, LilycoveCity_ContestLobby_EventScript_TryJoinGroup
# 858 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	case 1, LilycoveCity_ContestLobby_EventScript_TryLeadGroup
# 859 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	case 2, LilycoveCity_ContestLobby_EventScript_CancelLinkContest
# 860 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	case MULTI_B_PRESSED, LilycoveCity_ContestLobby_EventScript_CancelLinkContest
# 861 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 862 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 863 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_TryLeadGroup::
# 864 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	call LilycoveCity_ContestLobby_EventScript_TryBecomeLinkLeader
# 865 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	goto_if_eq VAR_RESULT, LINKUP_SUCCESS, LilycoveCity_ContestLobby_EventScript_LinkLeaderDecided
# 866 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	goto_if_eq VAR_RESULT, LINKUP_FAILED, LilycoveCity_ContestLobby_EventScript_DecideLinkLeader
# 867 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	goto_if_eq VAR_RESULT, LINKUP_RETRY_ROLE_ASSIGN, LilycoveCity_ContestLobby_EventScript_TryLeadGroup
# 868 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	release
# 869 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 870 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 871 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_TryJoinGroup::
# 872 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	call LilycoveCity_ContestLobby_EventScript_TryJoinLinkGroup
# 873 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	goto_if_eq VAR_RESULT, LINKUP_SUCCESS, LilycoveCity_ContestLobby_EventScript_LinkLeaderDecided
# 874 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	goto_if_eq VAR_RESULT, LINKUP_FAILED, LilycoveCity_ContestLobby_EventScript_DecideLinkLeader
# 875 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	goto_if_eq VAR_RESULT, LINKUP_RETRY_ROLE_ASSIGN, LilycoveCity_ContestLobby_EventScript_TryJoinGroup
# 876 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	release
# 877 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 878 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 879 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_TryBecomeLinkLeader::
# 880 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	special TryBecomeLinkLeader
# 881 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	waitstate
# 882 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	return
# 883 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 884 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_TryJoinLinkGroup::
# 885 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	special TryJoinLinkGroup
# 886 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	waitstate
# 887 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	return
# 888 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 889 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_LinkLeaderDecided::
# 890 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	messageinstant LilycoveCity_ContestLobby_Text_Transmitting
# 891 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	contestlinktransfer
# 892 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	goto LilycoveCity_ContestLobby_EventScript_StartLinkContest
# 893 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 894 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 895 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_LeadToLinkContestHall::
# 896 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	messageautoscroll LilycoveCity_ContestLobby_Text_ContestBeginShortly
# 897 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	waitmessage
# 898 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	delay 20
# 899 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	closemessage
# 900 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	applymovement LOCALID_LINK_RECEPTIONIST, LilycoveCity_ContestLobby_Movement_LinkReceptionistApproachCounter
# 901 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	waitmovement 0
# 902 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	playse SE_BRIDGE_WALK
# 903 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	setmetatile 17, 2, METATILE_Contest_WallShadow, TRUE
# 904 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	setmetatile 17, 3, METATILE_Contest_FloorShadow, TRUE
# 905 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	special DrawWholeMapView
# 906 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	applymovement LOCALID_LINK_RECEPTIONIST, LilycoveCity_ContestLobby_Movement_LinkReceptionistExitCounter
# 907 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	waitmovement 0
# 908 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	playse SE_BRIDGE_WALK
# 909 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	setmetatile 17, 2, METATILE_Contest_CounterFlap_Top, TRUE
# 910 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	setmetatile 17, 3, METATILE_Contest_CounterFlap_Bottom, TRUE
# 911 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	special DrawWholeMapView
# 912 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	delay 20
# 913 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	applymovement LOCALID_LINK_RECEPTIONIST, LilycoveCity_ContestLobby_Movement_LinkReceptionistFacePlayer
# 914 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	waitmovement 0
# 915 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LilycoveCity_ContestLobby_Movement_PlayerApproachLinkReceptionist
# 916 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	waitmovement 0
# 917 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	messageautoscroll LilycoveCity_ContestLobby_Text_ComeThroughHere
# 918 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	waitmessage
# 919 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	delay 20
# 920 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	closemessage
# 921 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	call LilycoveCity_ContestLobby_EventScript_DelayIfContestWithRSPlayer
# 922 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	applymovement LOCALID_LINK_RECEPTIONIST, LilycoveCity_ContestLobby_Movement_LinkReceptionistWalkToContestHall
# 923 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LilycoveCity_ContestLobby_Movement_PlayerWalkToLinkContestHall
# 924 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	waitmovement 0
# 925 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	release
# 926 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	return
# 927 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 928 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_Movement_PlayerWalkToLinkContestHall:
# 929 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_right
# 930 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_right
# 931 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_right
# 932 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_right
# 933 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_right
# 934 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_up
# 935 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_up
# 936 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_up
# 937 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	delay_8
# 938 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	set_invisible
# 939 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	step_end
# 940 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 941 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_Movement_PlayerApproachLinkReceptionist:
# 942 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_right
# 943 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	step_end
# 944 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 945 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_Movement_LinkReceptionistApproachCounter:
# 946 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_right
# 947 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_right
# 948 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_in_place_faster_down
# 949 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	step_end
# 950 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 951 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_Movement_LinkReceptionistExitCounter:
# 952 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_down
# 953 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_down
# 954 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_in_place_faster_up
# 955 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	step_end
# 956 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 957 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_Movement_LinkReceptionistWalkToContestHall:
# 958 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_right
# 959 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_right
# 960 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_right
# 961 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_right
# 962 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_up
# 963 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_up
# 964 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_up
# 965 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	delay_8
# 966 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	set_invisible
# 967 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	step_end
# 968 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 969 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_Movement_LinkReceptionistFacePlayer:
# 970 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_in_place_faster_left
# 971 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	step_end
# 972 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 973 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_LittleGirl::
# 974 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	lock
# 975 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	faceplayer
# 976 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	goto_if_set FLAG_RECEIVED_POKEBLOCK_CASE, LilycoveCity_ContestLobby_EventScript_LittleGirlHaveCase
# 977 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	msgbox LilycoveCity_ContestLobby_Text_LadyGaveMePokeblockCase, MSGBOX_DEFAULT
# 978 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	release
# 979 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 980 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 981 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_LittleGirlHaveCase::
# 982 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	msgbox LilycoveCity_ContestLobby_Text_MakePokeblocksDifferentBerries, MSGBOX_DEFAULT
# 983 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	release
# 984 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 985 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 986 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_Text_LadyGaveMePokeblockCase:
# 987 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "Yippee!\p"
# 988 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "The lady at the reception counter\n"
# 989 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "gave me a case for {POKEBLOCK}S!$"
# 990 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 991 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_Text_MakePokeblocksDifferentBerries:
# 992 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "Make {POKEBLOCK}S and put them in there.\p"
# 993 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "When you make a {POKEBLOCK}, everyone\n"
# 994 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "has to put in a different BERRY.$"
# 995 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 996 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_Text_YourPokemonSpurredMeToPaint:
# 997 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "Congratulations!\p"
# 998 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "I did a painting of your POKéMON to\n"
# 999 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "commemorate its victory…\p"
# 1000 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "Well, your POKéMON's appeals were\n"
# 1001 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "so fantastic, it spurred me into\l"
# 1002 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "painting better than I usually do.\l"
# 1003 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "Look, see?$"
# 1004 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 1005 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_Text_ShouldITakePaintingToMuseum:
# 1006 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "What do you think? I'm confident in\n"
# 1007 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "what I've done, but do you like it?\p"
# 1008 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "A work of this caliber, it wouldn't look\n"
# 1009 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "out of place in an art museum.\p"
# 1010 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "Huh? An art museum really is looking\n"
# 1011 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "for paintings?\p"
# 1012 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "Do you think I should take this there?$"
# 1013 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 1014 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_Text_IllTakePaintingToMuseum:
# 1015 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "What, really? Then, sure, I will take\n"
# 1016 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "this painting there right now.\p"
# 1017 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "I'll give it a proper title, too.\p"
# 1018 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "I hope they'll like it and consider\n"
# 1019 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "exhibiting this.\p"
# 1020 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "Please check if they did accept this.\n"
# 1021 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "Thank you!$"
# 1022 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 1023 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_Text_TakeMementoOfPainting:
# 1024 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "Oh, that's right!\p"
# 1025 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "As a memento of me painting your\n"
# 1026 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "POKéMON, please take this.$"
# 1027 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 1028 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_Text_ReceivedARibbon:
# 1029 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "{PLAYER} received a RIBBON.$"
# 1030 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 1031 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_Text_PutTheRibbonOnMon:
# 1032 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "{PLAYER} put the RIBBON on\n"
# 1033 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "{STR_VAR_1}.$"
# 1034 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 1035 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_Text_OkaySeeYou:
# 1036 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "Okay, see you!$"
# 1037 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 1038 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_Text_TakeHomeButIdLikeToTakeToMuseum:
# 1039 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "Oh… Then, I guess I'll just take\n"
# 1040 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "this home with me…\p"
# 1041 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "But, you know, I would like to take\n"
# 1042 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "this to the art museum… Okay?$"
# 1043 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 1044 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_Text_FineThatsTheWayItIs:
# 1045 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "Oh, fine, that's the way it is.\n"
# 1046 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "I will hang this in my own house.\p"
# 1047 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "I'll just have to try harder next time.\n"
# 1048 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "Well, be seeing you.$"
# 1049 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 1050 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_Text_MasterRankHereICome:
# 1051 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "Hoo, boy… Master Rank CONTESTS,\n"
# 1052 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "here I come.\p"
# 1053 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "The world will know that my dearest\n"
# 1054 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "POKéMON is the cutest being in all\l"
# 1055 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "existence. The time has come!\l"
# 1056 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "Uheheheh.$"
# 1057 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 1058 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_Text_WholeVarietyOfPokemonHere:
# 1059 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "You can see a whole variety of\n"
# 1060 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "POKéMON here.\p"
# 1061 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "That's why I make this place a regular\n"
# 1062 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "part of my daily stroll.$"
# 1063 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 1064 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_Text_ContestFeastForEyes:
# 1065 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "Wow, coming out to a CONTEST is\n"
# 1066 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "a feast for these eyes!\p"
# 1067 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "Would you look at all the POKéMON\n"
# 1068 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "that just scream to be painted?$"
# 1069 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 1070 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_Text_ToughContestIsExtreme:
# 1071 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "The TOUGHNESS CONTEST is like\n"
# 1072 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "extreme, man!\p"
# 1073 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "Those muscular appeals…\n"
# 1074 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "Cascading sweat… I swoon!$"
# 1075 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 1076 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_Text_LavishedCareOnMon:
# 1077 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "Day in and day out, I lavished my care\n"
# 1078 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "on this POKéMON.\p"
# 1079 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "Its condition is peaking.\n"
# 1080 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "Today, victory is mine!$"
# 1081 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 1082 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_Text_MadePokeblocksWithFamily:
# 1083 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "I made {POKEBLOCK}S with Mom, Dad, and\n"
# 1084 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "Big Sister. They turned out great!\p"
# 1085 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "I bet you can make smoother, better\n"
# 1086 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "{POKEBLOCK}S if you have more people.$"
