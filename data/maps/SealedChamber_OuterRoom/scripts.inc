# 1 "data/maps/SealedChamber_OuterRoom/scripts.pory"

# 2 "data/maps/SealedChamber_OuterRoom/scripts.pory"
SealedChamber_OuterRoom_MapScripts::
# 3 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, SealedChamber_OuterRoom_OnResume
# 4 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, SealedChamber_OuterRoom_OnTransition
# 5 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, SealedChamber_OuterRoom_OnLoad
# 6 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	.byte 0
# 7 "data/maps/SealedChamber_OuterRoom/scripts.pory"

# 8 "data/maps/SealedChamber_OuterRoom/scripts.pory"
SealedChamber_OuterRoom_OnResume:
# 9 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	setdivewarp MAP_UNDERWATER_SEALED_CHAMBER, 12, 44
# 10 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	setescapewarp MAP_UNDERWATER_SEALED_CHAMBER, 12, 44
# 11 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	end
# 12 "data/maps/SealedChamber_OuterRoom/scripts.pory"

# 13 "data/maps/SealedChamber_OuterRoom/scripts.pory"
SealedChamber_OuterRoom_OnTransition:
# 14 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	setflag FLAG_LANDMARK_SEALED_CHAMBER
# 15 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	end
# 16 "data/maps/SealedChamber_OuterRoom/scripts.pory"

# 17 "data/maps/SealedChamber_OuterRoom/scripts.pory"
SealedChamber_OuterRoom_OnLoad:
# 18 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	call_if_unset FLAG_SYS_BRAILLE_DIG, SealedChamber_OuterRoom_EventScript_CloseInnerRoomEntrance
# 19 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	end
# 20 "data/maps/SealedChamber_OuterRoom/scripts.pory"

# 21 "data/maps/SealedChamber_OuterRoom/scripts.pory"
SealedChamber_OuterRoom_EventScript_CloseInnerRoomEntrance::
# 22 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	setmetatile 9, 1, METATILE_Cave_EntranceCover, TRUE
# 23 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	setmetatile 10, 1, METATILE_Cave_EntranceCover, TRUE
# 24 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	setmetatile 11, 1, METATILE_Cave_EntranceCover, TRUE
# 25 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	setmetatile 9, 2, METATILE_Cave_SealedChamberBraille_Mid, TRUE
# 26 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	setmetatile 10, 2, METATILE_Cave_SealedChamberBraille_Mid, TRUE
# 27 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	setmetatile 11, 2, METATILE_Cave_SealedChamberBraille_Mid, TRUE
# 28 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	return
# 29 "data/maps/SealedChamber_OuterRoom/scripts.pory"

# 30 "data/maps/SealedChamber_OuterRoom/scripts.pory"
SealedChamber_OuterRoom_EventScript_BrailleABC::
# 31 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	lockall
# 32 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	braillemsgbox SealedChamber_OuterRoom_Braille_ABC
# 33 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	releaseall
# 34 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	end
# 35 "data/maps/SealedChamber_OuterRoom/scripts.pory"

# 36 "data/maps/SealedChamber_OuterRoom/scripts.pory"
SealedChamber_OuterRoom_EventScript_BrailleGHI::
# 37 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	lockall
# 38 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	braillemsgbox SealedChamber_OuterRoom_Braille_GHI
# 39 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	releaseall
# 40 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	end
# 41 "data/maps/SealedChamber_OuterRoom/scripts.pory"

# 42 "data/maps/SealedChamber_OuterRoom/scripts.pory"
SealedChamber_OuterRoom_EventScript_BrailleMNO::
# 43 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	lockall
# 44 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	braillemsgbox SealedChamber_OuterRoom_Braille_MNO
# 45 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	releaseall
# 46 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	end
# 47 "data/maps/SealedChamber_OuterRoom/scripts.pory"

# 48 "data/maps/SealedChamber_OuterRoom/scripts.pory"
SealedChamber_OuterRoom_EventScript_BrailleTUV::
# 49 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	lockall
# 50 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	braillemsgbox SealedChamber_OuterRoom_Braille_TUV
# 51 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	releaseall
# 52 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	end
# 53 "data/maps/SealedChamber_OuterRoom/scripts.pory"

# 54 "data/maps/SealedChamber_OuterRoom/scripts.pory"
SealedChamber_OuterRoom_EventScript_BrailleDEF::
# 55 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	lockall
# 56 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	braillemsgbox SealedChamber_OuterRoom_Braille_DEF
# 57 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	releaseall
# 58 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	end
# 59 "data/maps/SealedChamber_OuterRoom/scripts.pory"

# 60 "data/maps/SealedChamber_OuterRoom/scripts.pory"
SealedChamber_OuterRoom_EventScript_BrailleJKL::
# 61 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	lockall
# 62 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	braillemsgbox SealedChamber_OuterRoom_Braille_JKL
# 63 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	releaseall
# 64 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	end
# 65 "data/maps/SealedChamber_OuterRoom/scripts.pory"

# 66 "data/maps/SealedChamber_OuterRoom/scripts.pory"
SealedChamber_OuterRoom_EventScript_BraillePQRS::
# 67 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	lockall
# 68 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	braillemsgbox SealedChamber_OuterRoom_Braille_PQRS
# 69 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	releaseall
# 70 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	end
# 71 "data/maps/SealedChamber_OuterRoom/scripts.pory"

# 72 "data/maps/SealedChamber_OuterRoom/scripts.pory"
SealedChamber_OuterRoom_EventScript_BraillePeriod::
# 73 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	lockall
# 74 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	braillemsgbox SealedChamber_OuterRoom_Braille_Period
# 75 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	releaseall
# 76 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	end
# 77 "data/maps/SealedChamber_OuterRoom/scripts.pory"

# 78 "data/maps/SealedChamber_OuterRoom/scripts.pory"
SealedChamber_OuterRoom_EventScript_BrailleWXYZ::
# 79 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	lockall
# 80 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	braillemsgbox SealedChamber_OuterRoom_Braille_WXYZ
# 81 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	releaseall
# 82 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	end
# 83 "data/maps/SealedChamber_OuterRoom/scripts.pory"

# 84 "data/maps/SealedChamber_OuterRoom/scripts.pory"
SealedChamber_OuterRoom_EventScript_BrailleComma::
# 85 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	lockall
# 86 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	braillemsgbox SealedChamber_OuterRoom_Braille_Comma
# 87 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	releaseall
# 88 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	end
# 89 "data/maps/SealedChamber_OuterRoom/scripts.pory"

# 90 "data/maps/SealedChamber_OuterRoom/scripts.pory"
SealedChamber_OuterRoom_EventScript_InnerRoomEntranceWall::
# 91 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	lockall
# 92 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	goto_if_set FLAG_SYS_BRAILLE_DIG, SealedChamber_OuterRoom_EventScript_HoleInWall
# 93 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	braillemsgbox SealedChamber_OuterRoom_Braille_DigHere
# 94 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	releaseall
# 95 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	end
# 96 "data/maps/SealedChamber_OuterRoom/scripts.pory"

# 97 "data/maps/SealedChamber_OuterRoom/scripts.pory"
SealedChamber_OuterRoom_EventScript_HoleInWall::
# 98 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	msgbox gText_BigHoleInTheWall, MSGBOX_DEFAULT
# 99 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	releaseall
# 100 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	end
# 101 "data/maps/SealedChamber_OuterRoom/scripts.pory"

# 102 "data/maps/SealedChamber_OuterRoom/scripts.pory"
SealedChamber_OuterRoom_EventScript_BrailleDigHere::
# 103 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	lockall
# 104 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	braillemsgbox SealedChamber_OuterRoom_Braille_DigHere
# 105 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	releaseall
# 106 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	end
