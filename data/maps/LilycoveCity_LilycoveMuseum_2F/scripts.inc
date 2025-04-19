# 1 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"

# 2 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
.set LOCALID_CURATOR, 1
# 3 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"

# 4 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
LilycoveCity_LilycoveMuseum_2F_MapScripts::
# 5 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, LilycoveCity_LilycoveMuseum_2F_OnLoad
# 6 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LilycoveCity_LilycoveMuseum_2F_OnFrame
# 7 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.byte 0
# 8 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"

# 9 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
LilycoveCity_LilycoveMuseum_2F_OnLoad:
# 10 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	goto_if_set FLAG_COOL_PAINTING_MADE, LilycoveCity_LilycoveMuseum_2F_EventScript_SetCoolPainting
# 11 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	goto LilycoveCity_LilycoveMuseum_2F_EventScript_CheckBeautyPainting
# 12 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	end
# 13 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"

# 14 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
LilycoveCity_LilycoveMuseum_2F_EventScript_CheckBeautyPainting::
# 15 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	goto_if_set FLAG_BEAUTY_PAINTING_MADE, LilycoveCity_LilycoveMuseum_2F_EventScript_SetBeautyPainting
# 16 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	goto LilycoveCity_LilycoveMuseum_2F_EventScript_CheckCutePainting
# 17 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	end
# 18 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"

# 19 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
LilycoveCity_LilycoveMuseum_2F_EventScript_CheckCutePainting::
# 20 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	goto_if_set FLAG_CUTE_PAINTING_MADE, LilycoveCity_LilycoveMuseum_2F_EventScript_SetCutePainting
# 21 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	goto LilycoveCity_LilycoveMuseum_2F_EventScript_CheckSmartPainting
# 22 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	end
# 23 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"

# 24 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
LilycoveCity_LilycoveMuseum_2F_EventScript_CheckSmartPainting::
# 25 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	goto_if_set FLAG_SMART_PAINTING_MADE, LilycoveCity_LilycoveMuseum_2F_EventScript_SetSmartPainting
# 26 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	goto LilycoveCity_LilycoveMuseum_2F_EventScript_CheckToughPainting
# 27 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	end
# 28 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"

# 29 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
LilycoveCity_LilycoveMuseum_2F_EventScript_CheckToughPainting::
# 30 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	goto_if_set FLAG_TOUGH_PAINTING_MADE, LilycoveCity_LilycoveMuseum_2F_EventScript_SetToughPainting
# 31 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	end
# 32 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"

# 33 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
LilycoveCity_LilycoveMuseum_2F_EventScript_SetCoolPainting::
# 34 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	setmetatile 10, 6, METATILE_LilycoveMuseum_Painting2_Left, TRUE
# 35 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	setmetatile 11, 6, METATILE_LilycoveMuseum_Painting2_Right, TRUE
# 36 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	goto LilycoveCity_LilycoveMuseum_2F_EventScript_CheckBeautyPainting
# 37 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	end
# 38 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"

# 39 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
LilycoveCity_LilycoveMuseum_2F_EventScript_SetBeautyPainting::
# 40 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	setmetatile 18, 6, METATILE_LilycoveMuseum_Painting1_Left, TRUE
# 41 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	setmetatile 19, 6, METATILE_LilycoveMuseum_Painting1_Right, TRUE
# 42 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	goto LilycoveCity_LilycoveMuseum_2F_EventScript_CheckCutePainting
# 43 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	end
# 44 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"

# 45 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
LilycoveCity_LilycoveMuseum_2F_EventScript_SetCutePainting::
# 46 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	setmetatile 14, 10, METATILE_LilycoveMuseum_Painting3_Left, TRUE
# 47 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	setmetatile 15, 10, METATILE_LilycoveMuseum_Painting3_Right, TRUE
# 48 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	goto LilycoveCity_LilycoveMuseum_2F_EventScript_CheckSmartPainting
# 49 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	end
# 50 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"

# 51 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
LilycoveCity_LilycoveMuseum_2F_EventScript_SetSmartPainting::
# 52 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	setmetatile 6, 10, METATILE_LilycoveMuseum_Painting0_Left, TRUE
# 53 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	setmetatile 7, 10, METATILE_LilycoveMuseum_Painting0_Right, TRUE
# 54 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	goto LilycoveCity_LilycoveMuseum_2F_EventScript_CheckToughPainting
# 55 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	end
# 56 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"

# 57 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
LilycoveCity_LilycoveMuseum_2F_EventScript_SetToughPainting::
# 58 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	setmetatile 2, 6, METATILE_LilycoveMuseum_Painting4_Left, TRUE
# 59 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	setmetatile 3, 6, METATILE_LilycoveMuseum_Painting4_Right, TRUE
# 60 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	end
# 61 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"

# 62 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
LilycoveCity_LilycoveMuseum_2F_OnFrame:
# 63 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	map_script_2 VAR_LILYCOVE_MUSEUM_2F_STATE, 0, LilycoveCity_LilycoveMuseum_2F_EventScript_ShowExhibitHall
# 64 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.2byte 0
# 65 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"

# 66 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
LilycoveCity_LilycoveMuseum_2F_EventScript_ShowExhibitHall::
# 67 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	lockall
# 68 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	applymovement LOCALID_CURATOR, Common_Movement_FacePlayer
# 69 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LilycoveCity_LilycoveMuseum_2F_Movement_PlayerWalkInPlaceLeft
# 70 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	waitmovement 0
# 71 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ThisIsExhibitHall, MSGBOX_SIGN
# 72 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	applymovement LOCALID_CURATOR, LilycoveCity_LilycoveMuseum_2F_Movement_FaceExhibitHall
# 73 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	waitmovement 0
# 74 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LilycoveCity_LilycoveMuseum_2F_Movement_FaceExhibitHall
# 75 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	waitmovement 0
# 76 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ExplainExhibitHall, MSGBOX_SIGN
# 77 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	applymovement LOCALID_CURATOR, Common_Movement_FacePlayer
# 78 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	waitmovement 0
# 79 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LilycoveCity_LilycoveMuseum_2F_Movement_PlayerWalkInPlaceLeft
# 80 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	waitmovement 0
# 81 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_PleaseObtainPaintingsForExhibit, MSGBOX_SIGN
# 82 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	copyvar VAR_LILYCOVE_MUSEUM_2F_STATE, 1
# 83 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	releaseall
# 84 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	end
# 85 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"

# 86 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
LilycoveCity_LilycoveMuseum_2F_Movement_PlayerWalkInPlaceLeft:
# 87 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	walk_in_place_faster_left
# 88 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	step_end
# 89 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"

# 90 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
LilycoveCity_LilycoveMuseum_2F_Movement_FaceExhibitHall:
# 91 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	face_up
# 92 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	delay_16
# 93 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	step_end
# 94 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"

# 95 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
LilycoveCity_LilycoveMuseum_2F_EventScript_Curator::
# 96 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	lockall
# 97 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	goto_if_set FLAG_RECEIVED_GLASS_ORNAMENT, LilycoveCity_LilycoveMuseum_2F_EventScript_ReceivedGlassOrnament
# 98 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	specialvar VAR_0x8004, CountPlayerMuseumPaintings
# 99 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	switch VAR_0x8004
# 100 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	case 1, LilycoveCity_LilycoveMuseum_2F_EventScript_AddedPainting
# 101 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	case 2, LilycoveCity_LilycoveMuseum_2F_EventScript_AddedPainting
# 102 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	case 3, LilycoveCity_LilycoveMuseum_2F_EventScript_AddedPainting
# 103 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	case 4, LilycoveCity_LilycoveMuseum_2F_EventScript_AddedPainting
# 104 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	case 5, LilycoveCity_LilycoveMuseum_2F_EventScript_ThankPlayer
# 105 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_WishToFillExhibit, MSGBOX_NPC
# 106 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	end
# 107 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"

# 108 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
LilycoveCity_LilycoveMuseum_2F_EventScript_AddedPainting::
# 109 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ThanksAddedNewPainting, MSGBOX_NPC
# 110 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	end
# 111 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"

# 112 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
LilycoveCity_LilycoveMuseum_2F_EventScript_ThankPlayer::
# 113 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	applymovement LOCALID_CURATOR, Common_Movement_FacePlayer
# 114 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	waitmovement 0
# 115 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ItsYouPlayer, MSGBOX_DEFAULT
# 116 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	applymovement LOCALID_CURATOR, LilycoveCity_LilycoveMuseum_2F_Movement_FaceExhibitHall
# 117 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_PaintingsAttractedMoreGuests, MSGBOX_DEFAULT
# 118 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	goto LilycoveCity_LilycoveMuseum_2F_EventScript_GiveGlassOrnament
# 119 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	end
# 120 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"

# 121 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
LilycoveCity_LilycoveMuseum_2F_EventScript_GiveGlassOrnament::
# 122 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	applymovement LOCALID_CURATOR, Common_Movement_FacePlayer
# 123 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_TokenOfGratitude, MSGBOX_DEFAULT
# 124 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	givedecoration DECOR_GLASS_ORNAMENT
# 125 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_LilycoveMuseum_2F_EventScript_NoRoomForGlassOrnament
# 126 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	setflag FLAG_RECEIVED_GLASS_ORNAMENT
# 127 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	closemessage
# 128 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	releaseall
# 129 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	end
# 130 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"

# 131 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
LilycoveCity_LilycoveMuseum_2F_EventScript_NoRoomForGlassOrnament::
# 132 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	call Common_EventScript_NoRoomForDecor
# 133 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_KeepThisForYou, MSGBOX_DEFAULT
# 134 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	closemessage
# 135 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	releaseall
# 136 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	end
# 137 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"

# 138 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
LilycoveCity_LilycoveMuseum_2F_EventScript_ReceivedGlassOrnament::
# 139 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_HonorToHaveYouVisit, MSGBOX_NPC
# 140 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	releaseall
# 141 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	end
# 142 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"

# 143 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
LilycoveCity_LilycoveMuseum_2F_EventScript_CutePainting::
# 144 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	lockall
# 145 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	goto_if_set FLAG_CUTE_PAINTING_MADE, LilycoveCity_LilycoveMuseum_2F_EventScript_ShowCutePainting
# 146 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ItsPinkPictureFrame, MSGBOX_SIGN
# 147 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	end
# 148 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"

# 149 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
LilycoveCity_LilycoveMuseum_2F_EventScript_ToughPainting::
# 150 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	lockall
# 151 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	goto_if_set FLAG_TOUGH_PAINTING_MADE, LilycoveCity_LilycoveMuseum_2F_EventScript_ShowToughPainting
# 152 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ItsYellowPictureFrame, MSGBOX_SIGN
# 153 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	end
# 154 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"

# 155 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
LilycoveCity_LilycoveMuseum_2F_EventScript_CoolPainting::
# 156 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	lockall
# 157 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	goto_if_set FLAG_COOL_PAINTING_MADE, LilycoveCity_LilycoveMuseum_2F_EventScript_ShowCoolPainting
# 158 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ItsRedPictureFrame, MSGBOX_SIGN
# 159 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	end
# 160 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"

# 161 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
LilycoveCity_LilycoveMuseum_2F_EventScript_BeautyPainting::
# 162 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	lockall
# 163 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	goto_if_set FLAG_BEAUTY_PAINTING_MADE, LilycoveCity_LilycoveMuseum_2F_EventScript_ShowBeautyPainting
# 164 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ItsBluePictureFrame, MSGBOX_SIGN
# 165 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	end
# 166 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"

# 167 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
LilycoveCity_LilycoveMuseum_2F_EventScript_SmartPainting::
# 168 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	lockall
# 169 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	goto_if_set FLAG_SMART_PAINTING_MADE, LilycoveCity_LilycoveMuseum_2F_EventScript_ShowSmartPainting
# 170 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ItsGreenPictureFrame, MSGBOX_SIGN
# 171 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	end
# 172 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"

# 173 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
LilycoveCity_LilycoveMuseum_2F_EventScript_Girl::
# 174 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_NewPaintingsSurprisedMe, MSGBOX_NPC
# 175 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	end
# 176 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"

# 177 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
LilycoveCity_LilycoveMuseum_2F_EventScript_ExpertM::
# 178 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_NewPaintingsRatherAmusing, MSGBOX_NPC
# 179 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	end
# 180 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"

# 181 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
LilycoveCity_LilycoveMuseum_2F_EventScript_RichBoy::
# 182 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ThesePaintingsOfYourPokemon, MSGBOX_NPC
# 183 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	end
# 184 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"

# 185 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
LilycoveCity_LilycoveMuseum_2F_EventScript_ShowCoolPainting::
# 186 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ItsPaintingOfPokemon, MSGBOX_SIGN
# 187 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	fadescreen FADE_TO_BLACK
# 188 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	showcontestpainting CONTEST_WINNER_MUSEUM_COOL
# 189 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	releaseall
# 190 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	end
# 191 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"

# 192 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
LilycoveCity_LilycoveMuseum_2F_EventScript_ShowBeautyPainting::
# 193 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ItsPaintingOfPokemon, MSGBOX_SIGN
# 194 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	fadescreen FADE_TO_BLACK
# 195 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	showcontestpainting CONTEST_WINNER_MUSEUM_BEAUTY
# 196 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	releaseall
# 197 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	end
# 198 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"

# 199 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
LilycoveCity_LilycoveMuseum_2F_EventScript_ShowCutePainting::
# 200 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ItsPaintingOfPokemon, MSGBOX_SIGN
# 201 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	fadescreen FADE_TO_BLACK
# 202 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	showcontestpainting CONTEST_WINNER_MUSEUM_CUTE
# 203 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	releaseall
# 204 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	end
# 205 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"

# 206 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
LilycoveCity_LilycoveMuseum_2F_EventScript_ShowSmartPainting::
# 207 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ItsPaintingOfPokemon, MSGBOX_SIGN
# 208 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	fadescreen FADE_TO_BLACK
# 209 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	showcontestpainting CONTEST_WINNER_MUSEUM_SMART
# 210 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	releaseall
# 211 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	end
# 212 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"

# 213 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
LilycoveCity_LilycoveMuseum_2F_EventScript_ShowToughPainting::
# 214 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ItsPaintingOfPokemon, MSGBOX_SIGN
# 215 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	fadescreen FADE_TO_BLACK
# 216 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	showcontestpainting CONTEST_WINNER_MUSEUM_TOUGH
# 217 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	releaseall
# 218 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	end
# 219 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"

# 220 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
LilycoveCity_LilycoveMuseum_2F_Text_ThisIsExhibitHall:
# 221 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "This is our special exhibit hall.$"
# 222 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"

# 223 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
LilycoveCity_LilycoveMuseum_2F_Text_ExplainExhibitHall:
# 224 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "As you can plainly see, there is not\n"
# 225 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "a single painting on exhibit.\p"
# 226 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "Here, I don't wish to exhibit works of\n"
# 227 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "so-called classical art.\p"
# 228 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "Such classical works you can see on\n"
# 229 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "our ground floor.\p"
# 230 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "I wish to exhibit work that is far\n"
# 231 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "different from the classics.\p"
# 232 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "Art, after all, is not restricted to old,\n"
# 233 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "famous works!\p"
# 234 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "This exhibit hall, I wish to fill it with…\p"
# 235 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "Modern and vibrant artworks of\n"
# 236 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "POKéMON seemingly ready to spring\l"
# 237 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "forth into glorious life!$"
# 238 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"

# 239 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
LilycoveCity_LilycoveMuseum_2F_Text_PleaseObtainPaintingsForExhibit:
# 240 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "I beg your pardon. I didn't intend\n"
# 241 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "to monopolize the conversation.\p"
# 242 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "Now, as you are young, and yet\n"
# 243 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "obviously well traveled…\p"
# 244 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "You must encounter lively POKéMON\n"
# 245 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "and works of art depicting them.\p"
# 246 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "If you were to come across such\n"
# 247 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "a painting, may we ask you to obtain\l"
# 248 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "the artist's permission to exhibit\l"
# 249 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "it here?$"
# 250 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"

# 251 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
LilycoveCity_LilycoveMuseum_2F_Text_WishToFillExhibit:
# 252 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "I wish to fill this exhibit hall with\n"
# 253 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "modern and vibrant paintings of\l"
# 254 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "POKéMON.$"
# 255 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"

# 256 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
LilycoveCity_LilycoveMuseum_2F_Text_ThanksAddedNewPainting:
# 257 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "Thanks to you, we've added a new\n"
# 258 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "painting to our collection!\p"
# 259 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "I've heard it depicts your POKéMON.\n"
# 260 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "Truly magnificent!\p"
# 261 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "Thank you so very, very much!$"
# 262 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"

# 263 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
LilycoveCity_LilycoveMuseum_2F_Text_ItsYouPlayer:
# 264 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "Ah! It's you!\n"
# 265 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "{PLAYER}!$"
# 266 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"

# 267 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
LilycoveCity_LilycoveMuseum_2F_Text_PaintingsAttractedMoreGuests:
# 268 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "Isn't this marvelous?\n"
# 269 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "This collection of paintings!\p"
# 270 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "Each one of them flawless!\n"
# 271 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "None better than another!\p"
# 272 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "These paintings have attracted\n"
# 273 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "more guests to our ART MUSEUM.\p"
# 274 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "Sincerely, I thank you, {PLAYER}.\n"
# 275 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "This is my dream come true!$"
# 276 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"

# 277 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
LilycoveCity_LilycoveMuseum_2F_Text_TokenOfGratitude:
# 278 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "This is merely a token of my gratitude.$"
# 279 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"

# 280 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
LilycoveCity_LilycoveMuseum_2F_Text_KeepThisForYou:
# 281 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "I will keep this for you until we\n"
# 282 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "meet again.$"
# 283 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"

# 284 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
LilycoveCity_LilycoveMuseum_2F_Text_HonorToHaveYouVisit:
# 285 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "Ah, so good to see you, {PLAYER}!\p"
# 286 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "It's an honor to have you visit us\n"
# 287 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "on your busy journeys.\p"
# 288 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "Please, relax and do enjoy your\n"
# 289 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "visit with us.$"
# 290 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"

# 291 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
LilycoveCity_LilycoveMuseum_2F_Text_ItsPinkPictureFrame:
# 292 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "It's a picture frame with pink-colored\n"
# 293 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "adornments.$"
# 294 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"

# 295 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
LilycoveCity_LilycoveMuseum_2F_Text_ItsYellowPictureFrame:
# 296 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "It's a picture frame with\n"
# 297 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "yellow-colored adornments.$"
# 298 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"

# 299 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
LilycoveCity_LilycoveMuseum_2F_Text_ItsBluePictureFrame:
# 300 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "It's a picture frame with\n"
# 301 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "blue-colored adornments.$"
# 302 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"

# 303 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
LilycoveCity_LilycoveMuseum_2F_Text_ItsRedPictureFrame:
# 304 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "It's a picture frame with\n"
# 305 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "red-colored adornments.$"
# 306 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"

# 307 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
LilycoveCity_LilycoveMuseum_2F_Text_ItsGreenPictureFrame:
# 308 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "It's a picture frame with\n"
# 309 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "green-colored adornments.$"
# 310 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"

# 311 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
LilycoveCity_LilycoveMuseum_2F_Text_ItsPaintingOfPokemon:
# 312 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "It's a painting of POKéMON.$"
# 313 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"

# 314 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
LilycoveCity_LilycoveMuseum_2F_Text_NewPaintingsSurprisedMe:
# 315 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "I've been away awhile, so the new\n"
# 316 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "paintings up here surprised me.\p"
# 317 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "I wish someone would paint my POKéMON\n"
# 318 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "this pretty.$"
# 319 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"

# 320 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
LilycoveCity_LilycoveMuseum_2F_Text_NewPaintingsRatherAmusing:
# 321 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "Well… So this is where they show\n"
# 322 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "the topical POKéMON paintings.\p"
# 323 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "I see, these new paintings are indeed\n"
# 324 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "rather amusing.$"
# 325 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"

# 326 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
LilycoveCity_LilycoveMuseum_2F_Text_ThesePaintingsOfYourPokemon:
# 327 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "Wow, is that right?\n"
# 328 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "These paintings are of your POKéMON.\p"
# 329 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "Isn't that just the ultimate joy for\n"
# 330 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "a TRAINER?$"
