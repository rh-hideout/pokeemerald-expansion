# 1 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"

# 2 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
LilycoveCity_LilycoveMuseum_2F_MapScripts::
# 3 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, LilycoveCity_LilycoveMuseum_2F_OnLoad
# 4 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LilycoveCity_LilycoveMuseum_2F_OnFrame
# 5 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.byte 0
# 6 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"

# 7 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
LilycoveCity_LilycoveMuseum_2F_OnLoad:
# 8 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	goto_if_set FLAG_COOL_PAINTING_MADE, LilycoveCity_LilycoveMuseum_2F_EventScript_SetCoolPainting
# 9 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	goto LilycoveCity_LilycoveMuseum_2F_EventScript_CheckBeautyPainting
# 10 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	end
# 11 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"

# 12 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
LilycoveCity_LilycoveMuseum_2F_EventScript_CheckBeautyPainting::
# 13 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	goto_if_set FLAG_BEAUTY_PAINTING_MADE, LilycoveCity_LilycoveMuseum_2F_EventScript_SetBeautyPainting
# 14 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	goto LilycoveCity_LilycoveMuseum_2F_EventScript_CheckCutePainting
# 15 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	end
# 16 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"

# 17 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
LilycoveCity_LilycoveMuseum_2F_EventScript_CheckCutePainting::
# 18 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	goto_if_set FLAG_CUTE_PAINTING_MADE, LilycoveCity_LilycoveMuseum_2F_EventScript_SetCutePainting
# 19 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	goto LilycoveCity_LilycoveMuseum_2F_EventScript_CheckSmartPainting
# 20 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	end
# 21 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"

# 22 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
LilycoveCity_LilycoveMuseum_2F_EventScript_CheckSmartPainting::
# 23 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	goto_if_set FLAG_SMART_PAINTING_MADE, LilycoveCity_LilycoveMuseum_2F_EventScript_SetSmartPainting
# 24 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	goto LilycoveCity_LilycoveMuseum_2F_EventScript_CheckToughPainting
# 25 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	end
# 26 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"

# 27 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
LilycoveCity_LilycoveMuseum_2F_EventScript_CheckToughPainting::
# 28 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	goto_if_set FLAG_TOUGH_PAINTING_MADE, LilycoveCity_LilycoveMuseum_2F_EventScript_SetToughPainting
# 29 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	end
# 30 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"

# 31 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
LilycoveCity_LilycoveMuseum_2F_EventScript_SetCoolPainting::
# 32 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	setmetatile 10, 6, METATILE_LilycoveMuseum_Painting2_Left, TRUE
# 33 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	setmetatile 11, 6, METATILE_LilycoveMuseum_Painting2_Right, TRUE
# 34 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	goto LilycoveCity_LilycoveMuseum_2F_EventScript_CheckBeautyPainting
# 35 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	end
# 36 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"

# 37 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
LilycoveCity_LilycoveMuseum_2F_EventScript_SetBeautyPainting::
# 38 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	setmetatile 18, 6, METATILE_LilycoveMuseum_Painting1_Left, TRUE
# 39 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	setmetatile 19, 6, METATILE_LilycoveMuseum_Painting1_Right, TRUE
# 40 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	goto LilycoveCity_LilycoveMuseum_2F_EventScript_CheckCutePainting
# 41 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	end
# 42 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"

# 43 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
LilycoveCity_LilycoveMuseum_2F_EventScript_SetCutePainting::
# 44 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	setmetatile 14, 10, METATILE_LilycoveMuseum_Painting3_Left, TRUE
# 45 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	setmetatile 15, 10, METATILE_LilycoveMuseum_Painting3_Right, TRUE
# 46 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	goto LilycoveCity_LilycoveMuseum_2F_EventScript_CheckSmartPainting
# 47 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	end
# 48 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"

# 49 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
LilycoveCity_LilycoveMuseum_2F_EventScript_SetSmartPainting::
# 50 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	setmetatile 6, 10, METATILE_LilycoveMuseum_Painting0_Left, TRUE
# 51 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	setmetatile 7, 10, METATILE_LilycoveMuseum_Painting0_Right, TRUE
# 52 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	goto LilycoveCity_LilycoveMuseum_2F_EventScript_CheckToughPainting
# 53 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	end
# 54 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"

# 55 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
LilycoveCity_LilycoveMuseum_2F_EventScript_SetToughPainting::
# 56 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	setmetatile 2, 6, METATILE_LilycoveMuseum_Painting4_Left, TRUE
# 57 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	setmetatile 3, 6, METATILE_LilycoveMuseum_Painting4_Right, TRUE
# 58 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	end
# 59 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"

# 60 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
LilycoveCity_LilycoveMuseum_2F_OnFrame:
# 61 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	map_script_2 VAR_LILYCOVE_MUSEUM_2F_STATE, 0, LilycoveCity_LilycoveMuseum_2F_EventScript_ShowExhibitHall
# 62 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.2byte 0
# 63 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"

# 64 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
LilycoveCity_LilycoveMuseum_2F_EventScript_ShowExhibitHall::
# 65 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	lockall
# 66 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	applymovement LOCALID_MUSEUM_2F_CURATOR, Common_Movement_FacePlayer
# 67 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	applymovement LOCALID_PLAYER, LilycoveCity_LilycoveMuseum_2F_Movement_PlayerWalkInPlaceLeft
# 68 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	waitmovement 0
# 69 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ThisIsExhibitHall, MSGBOX_SIGN
# 70 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	applymovement LOCALID_MUSEUM_2F_CURATOR, LilycoveCity_LilycoveMuseum_2F_Movement_FaceExhibitHall
# 71 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	waitmovement 0
# 72 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	applymovement LOCALID_PLAYER, LilycoveCity_LilycoveMuseum_2F_Movement_FaceExhibitHall
# 73 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	waitmovement 0
# 74 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ExplainExhibitHall, MSGBOX_SIGN
# 75 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	applymovement LOCALID_MUSEUM_2F_CURATOR, Common_Movement_FacePlayer
# 76 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	waitmovement 0
# 77 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	applymovement LOCALID_PLAYER, LilycoveCity_LilycoveMuseum_2F_Movement_PlayerWalkInPlaceLeft
# 78 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	waitmovement 0
# 79 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_PleaseObtainPaintingsForExhibit, MSGBOX_SIGN
# 80 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	copyvar VAR_LILYCOVE_MUSEUM_2F_STATE, 1
# 81 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	releaseall
# 82 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	end
# 83 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"

# 84 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
LilycoveCity_LilycoveMuseum_2F_Movement_PlayerWalkInPlaceLeft:
# 85 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	walk_in_place_faster_left
# 86 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	step_end
# 87 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"

# 88 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
LilycoveCity_LilycoveMuseum_2F_Movement_FaceExhibitHall:
# 89 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	face_up
# 90 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	delay_16
# 91 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	step_end
# 92 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"

# 93 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
LilycoveCity_LilycoveMuseum_2F_EventScript_Curator::
# 94 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	lockall
# 95 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	goto_if_set FLAG_RECEIVED_GLASS_ORNAMENT, LilycoveCity_LilycoveMuseum_2F_EventScript_ReceivedGlassOrnament
# 96 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	specialvar VAR_0x8004, CountPlayerMuseumPaintings
# 97 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	switch VAR_0x8004
# 98 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	case 1, LilycoveCity_LilycoveMuseum_2F_EventScript_AddedPainting
# 99 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	case 2, LilycoveCity_LilycoveMuseum_2F_EventScript_AddedPainting
# 100 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	case 3, LilycoveCity_LilycoveMuseum_2F_EventScript_AddedPainting
# 101 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	case 4, LilycoveCity_LilycoveMuseum_2F_EventScript_AddedPainting
# 102 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	case 5, LilycoveCity_LilycoveMuseum_2F_EventScript_ThankPlayer
# 103 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_WishToFillExhibit, MSGBOX_NPC
# 104 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	end
# 105 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"

# 106 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
LilycoveCity_LilycoveMuseum_2F_EventScript_AddedPainting::
# 107 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ThanksAddedNewPainting, MSGBOX_NPC
# 108 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	end
# 109 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"

# 110 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
LilycoveCity_LilycoveMuseum_2F_EventScript_ThankPlayer::
# 111 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	applymovement LOCALID_MUSEUM_2F_CURATOR, Common_Movement_FacePlayer
# 112 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	waitmovement 0
# 113 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ItsYouPlayer, MSGBOX_DEFAULT
# 114 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	applymovement LOCALID_MUSEUM_2F_CURATOR, LilycoveCity_LilycoveMuseum_2F_Movement_FaceExhibitHall
# 115 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_PaintingsAttractedMoreGuests, MSGBOX_DEFAULT
# 116 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	goto LilycoveCity_LilycoveMuseum_2F_EventScript_GiveGlassOrnament
# 117 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	end
# 118 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"

# 119 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
LilycoveCity_LilycoveMuseum_2F_EventScript_GiveGlassOrnament::
# 120 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	applymovement LOCALID_MUSEUM_2F_CURATOR, Common_Movement_FacePlayer
# 121 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_TokenOfGratitude, MSGBOX_DEFAULT
# 122 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	givedecoration DECOR_GLASS_ORNAMENT
# 123 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_LilycoveMuseum_2F_EventScript_NoRoomForGlassOrnament
# 124 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	setflag FLAG_RECEIVED_GLASS_ORNAMENT
# 125 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	closemessage
# 126 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	releaseall
# 127 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	end
# 128 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"

# 129 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
LilycoveCity_LilycoveMuseum_2F_EventScript_NoRoomForGlassOrnament::
# 130 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	call Common_EventScript_NoRoomForDecor
# 131 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_KeepThisForYou, MSGBOX_DEFAULT
# 132 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	closemessage
# 133 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	releaseall
# 134 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	end
# 135 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"

# 136 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
LilycoveCity_LilycoveMuseum_2F_EventScript_ReceivedGlassOrnament::
# 137 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_HonorToHaveYouVisit, MSGBOX_NPC
# 138 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	releaseall
# 139 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	end
# 140 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"

# 141 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
LilycoveCity_LilycoveMuseum_2F_EventScript_CutePainting::
# 142 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	lockall
# 143 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	goto_if_set FLAG_CUTE_PAINTING_MADE, LilycoveCity_LilycoveMuseum_2F_EventScript_ShowCutePainting
# 144 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ItsPinkPictureFrame, MSGBOX_SIGN
# 145 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	end
# 146 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"

# 147 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
LilycoveCity_LilycoveMuseum_2F_EventScript_ToughPainting::
# 148 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	lockall
# 149 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	goto_if_set FLAG_TOUGH_PAINTING_MADE, LilycoveCity_LilycoveMuseum_2F_EventScript_ShowToughPainting
# 150 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ItsYellowPictureFrame, MSGBOX_SIGN
# 151 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	end
# 152 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"

# 153 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
LilycoveCity_LilycoveMuseum_2F_EventScript_CoolPainting::
# 154 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	lockall
# 155 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	goto_if_set FLAG_COOL_PAINTING_MADE, LilycoveCity_LilycoveMuseum_2F_EventScript_ShowCoolPainting
# 156 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ItsRedPictureFrame, MSGBOX_SIGN
# 157 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	end
# 158 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"

# 159 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
LilycoveCity_LilycoveMuseum_2F_EventScript_BeautyPainting::
# 160 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	lockall
# 161 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	goto_if_set FLAG_BEAUTY_PAINTING_MADE, LilycoveCity_LilycoveMuseum_2F_EventScript_ShowBeautyPainting
# 162 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ItsBluePictureFrame, MSGBOX_SIGN
# 163 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	end
# 164 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"

# 165 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
LilycoveCity_LilycoveMuseum_2F_EventScript_SmartPainting::
# 166 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	lockall
# 167 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	goto_if_set FLAG_SMART_PAINTING_MADE, LilycoveCity_LilycoveMuseum_2F_EventScript_ShowSmartPainting
# 168 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ItsGreenPictureFrame, MSGBOX_SIGN
# 169 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	end
# 170 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"

# 171 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
LilycoveCity_LilycoveMuseum_2F_EventScript_Girl::
# 172 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_NewPaintingsSurprisedMe, MSGBOX_NPC
# 173 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	end
# 174 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"

# 175 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
LilycoveCity_LilycoveMuseum_2F_EventScript_ExpertM::
# 176 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_NewPaintingsRatherAmusing, MSGBOX_NPC
# 177 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	end
# 178 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"

# 179 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
LilycoveCity_LilycoveMuseum_2F_EventScript_RichBoy::
# 180 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ThesePaintingsOfYourPokemon, MSGBOX_NPC
# 181 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	end
# 182 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"

# 183 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
LilycoveCity_LilycoveMuseum_2F_EventScript_ShowCoolPainting::
# 184 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ItsPaintingOfPokemon, MSGBOX_SIGN
# 185 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	fadescreen FADE_TO_BLACK
# 186 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	showcontestpainting CONTEST_WINNER_MUSEUM_COOL
# 187 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	releaseall
# 188 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	end
# 189 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"

# 190 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
LilycoveCity_LilycoveMuseum_2F_EventScript_ShowBeautyPainting::
# 191 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ItsPaintingOfPokemon, MSGBOX_SIGN
# 192 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	fadescreen FADE_TO_BLACK
# 193 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	showcontestpainting CONTEST_WINNER_MUSEUM_BEAUTY
# 194 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	releaseall
# 195 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	end
# 196 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"

# 197 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
LilycoveCity_LilycoveMuseum_2F_EventScript_ShowCutePainting::
# 198 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ItsPaintingOfPokemon, MSGBOX_SIGN
# 199 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	fadescreen FADE_TO_BLACK
# 200 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	showcontestpainting CONTEST_WINNER_MUSEUM_CUTE
# 201 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	releaseall
# 202 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	end
# 203 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"

# 204 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
LilycoveCity_LilycoveMuseum_2F_EventScript_ShowSmartPainting::
# 205 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ItsPaintingOfPokemon, MSGBOX_SIGN
# 206 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	fadescreen FADE_TO_BLACK
# 207 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	showcontestpainting CONTEST_WINNER_MUSEUM_SMART
# 208 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	releaseall
# 209 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	end
# 210 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"

# 211 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
LilycoveCity_LilycoveMuseum_2F_EventScript_ShowToughPainting::
# 212 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ItsPaintingOfPokemon, MSGBOX_SIGN
# 213 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	fadescreen FADE_TO_BLACK
# 214 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	showcontestpainting CONTEST_WINNER_MUSEUM_TOUGH
# 215 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	releaseall
# 216 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	end
# 217 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"

# 218 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
LilycoveCity_LilycoveMuseum_2F_Text_ThisIsExhibitHall:
# 219 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "This is our special exhibit hall.$"
# 220 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"

# 221 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
LilycoveCity_LilycoveMuseum_2F_Text_ExplainExhibitHall:
# 222 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "As you can plainly see, there is not\n"
# 223 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "a single painting on exhibit.\p"
# 224 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "Here, I don't wish to exhibit works of\n"
# 225 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "so-called classical art.\p"
# 226 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "Such classical works you can see on\n"
# 227 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "our ground floor.\p"
# 228 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "I wish to exhibit work that is far\n"
# 229 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "different from the classics.\p"
# 230 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "Art, after all, is not restricted to old,\n"
# 231 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "famous works!\p"
# 232 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "This exhibit hall, I wish to fill it with…\p"
# 233 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "Modern and vibrant artworks of\n"
# 234 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "POKéMON seemingly ready to spring\l"
# 235 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "forth into glorious life!$"
# 236 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"

# 237 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
LilycoveCity_LilycoveMuseum_2F_Text_PleaseObtainPaintingsForExhibit:
# 238 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "I beg your pardon. I didn't intend\n"
# 239 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "to monopolize the conversation.\p"
# 240 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "Now, as you are young, and yet\n"
# 241 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "obviously well traveled…\p"
# 242 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "You must encounter lively POKéMON\n"
# 243 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "and works of art depicting them.\p"
# 244 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "If you were to come across such\n"
# 245 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "a painting, may we ask you to obtain\l"
# 246 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "the artist's permission to exhibit\l"
# 247 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "it here?$"
# 248 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"

# 249 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
LilycoveCity_LilycoveMuseum_2F_Text_WishToFillExhibit:
# 250 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "I wish to fill this exhibit hall with\n"
# 251 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "modern and vibrant paintings of\l"
# 252 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "POKéMON.$"
# 253 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"

# 254 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
LilycoveCity_LilycoveMuseum_2F_Text_ThanksAddedNewPainting:
# 255 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "Thanks to you, we've added a new\n"
# 256 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "painting to our collection!\p"
# 257 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "I've heard it depicts your POKéMON.\n"
# 258 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "Truly magnificent!\p"
# 259 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "Thank you so very, very much!$"
# 260 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"

# 261 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
LilycoveCity_LilycoveMuseum_2F_Text_ItsYouPlayer:
# 262 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "Ah! It's you!\n"
# 263 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "{PLAYER}!$"
# 264 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"

# 265 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
LilycoveCity_LilycoveMuseum_2F_Text_PaintingsAttractedMoreGuests:
# 266 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "Isn't this marvelous?\n"
# 267 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "This collection of paintings!\p"
# 268 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "Each one of them flawless!\n"
# 269 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "None better than another!\p"
# 270 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "These paintings have attracted\n"
# 271 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "more guests to our ART MUSEUM.\p"
# 272 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "Sincerely, I thank you, {PLAYER}.\n"
# 273 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "This is my dream come true!$"
# 274 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"

# 275 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
LilycoveCity_LilycoveMuseum_2F_Text_TokenOfGratitude:
# 276 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "This is merely a token of my gratitude.$"
# 277 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"

# 278 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
LilycoveCity_LilycoveMuseum_2F_Text_KeepThisForYou:
# 279 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "I will keep this for you until we\n"
# 280 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "meet again.$"
# 281 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"

# 282 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
LilycoveCity_LilycoveMuseum_2F_Text_HonorToHaveYouVisit:
# 283 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "Ah, so good to see you, {PLAYER}!\p"
# 284 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "It's an honor to have you visit us\n"
# 285 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "on your busy journeys.\p"
# 286 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "Please, relax and do enjoy your\n"
# 287 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "visit with us.$"
# 288 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"

# 289 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
LilycoveCity_LilycoveMuseum_2F_Text_ItsPinkPictureFrame:
# 290 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "It's a picture frame with pink-colored\n"
# 291 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "adornments.$"
# 292 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"

# 293 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
LilycoveCity_LilycoveMuseum_2F_Text_ItsYellowPictureFrame:
# 294 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "It's a picture frame with\n"
# 295 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "yellow-colored adornments.$"
# 296 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"

# 297 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
LilycoveCity_LilycoveMuseum_2F_Text_ItsBluePictureFrame:
# 298 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "It's a picture frame with\n"
# 299 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "blue-colored adornments.$"
# 300 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"

# 301 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
LilycoveCity_LilycoveMuseum_2F_Text_ItsRedPictureFrame:
# 302 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "It's a picture frame with\n"
# 303 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "red-colored adornments.$"
# 304 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"

# 305 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
LilycoveCity_LilycoveMuseum_2F_Text_ItsGreenPictureFrame:
# 306 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "It's a picture frame with\n"
# 307 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "green-colored adornments.$"
# 308 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"

# 309 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
LilycoveCity_LilycoveMuseum_2F_Text_ItsPaintingOfPokemon:
# 310 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "It's a painting of POKéMON.$"
# 311 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"

# 312 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
LilycoveCity_LilycoveMuseum_2F_Text_NewPaintingsSurprisedMe:
# 313 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "I've been away awhile, so the new\n"
# 314 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "paintings up here surprised me.\p"
# 315 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "I wish someone would paint my POKéMON\n"
# 316 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "this pretty.$"
# 317 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"

# 318 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
LilycoveCity_LilycoveMuseum_2F_Text_NewPaintingsRatherAmusing:
# 319 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "Well… So this is where they show\n"
# 320 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "the topical POKéMON paintings.\p"
# 321 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "I see, these new paintings are indeed\n"
# 322 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "rather amusing.$"
# 323 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"

# 324 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
LilycoveCity_LilycoveMuseum_2F_Text_ThesePaintingsOfYourPokemon:
# 325 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "Wow, is that right?\n"
# 326 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "These paintings are of your POKéMON.\p"
# 327 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "Isn't that just the ultimate joy for\n"
# 328 "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.pory"
	.string "a TRAINER?$"
