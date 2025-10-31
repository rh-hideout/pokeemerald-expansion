# 1 "data/maps/MauvilleCity_PokemonCenter_1F/scripts.pory"

# 2 "data/maps/MauvilleCity_PokemonCenter_1F/scripts.pory"
MauvilleCity_PokemonCenter_1F_MapScripts::
# 3 "data/maps/MauvilleCity_PokemonCenter_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, MauvilleCity_PokemonCenter_1F_OnTransition
# 4 "data/maps/MauvilleCity_PokemonCenter_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
# 5 "data/maps/MauvilleCity_PokemonCenter_1F/scripts.pory"
	.byte 0
# 6 "data/maps/MauvilleCity_PokemonCenter_1F/scripts.pory"

# 7 "data/maps/MauvilleCity_PokemonCenter_1F/scripts.pory"
MauvilleCity_PokemonCenter_1F_OnTransition:
# 8 "data/maps/MauvilleCity_PokemonCenter_1F/scripts.pory"
	setrespawn HEAL_LOCATION_MAUVILLE_CITY
# 9 "data/maps/MauvilleCity_PokemonCenter_1F/scripts.pory"
	call Common_EventScript_UpdateBrineyLocation
# 10 "data/maps/MauvilleCity_PokemonCenter_1F/scripts.pory"
	goto MauvilleCity_PokemonCenter_1F_EventScript_SetMauvilleOldManGfx
# 11 "data/maps/MauvilleCity_PokemonCenter_1F/scripts.pory"
	end
# 12 "data/maps/MauvilleCity_PokemonCenter_1F/scripts.pory"

# 13 "data/maps/MauvilleCity_PokemonCenter_1F/scripts.pory"
MauvilleCity_PokemonCenter_1F_EventScript_SetMauvilleOldManGfx::
# 14 "data/maps/MauvilleCity_PokemonCenter_1F/scripts.pory"
	special SetMauvilleOldManObjEventGfx
# 15 "data/maps/MauvilleCity_PokemonCenter_1F/scripts.pory"
	end
# 16 "data/maps/MauvilleCity_PokemonCenter_1F/scripts.pory"

# 17 "data/maps/MauvilleCity_PokemonCenter_1F/scripts.pory"
MauvilleCity_PokemonCenter_1F_EventScript_Nurse::
# 18 "data/maps/MauvilleCity_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x800B, LOCALID_MAUVILLE_NURSE
# 19 "data/maps/MauvilleCity_PokemonCenter_1F/scripts.pory"
	call Common_EventScript_PkmnCenterNurse
# 20 "data/maps/MauvilleCity_PokemonCenter_1F/scripts.pory"
	waitmessage
# 21 "data/maps/MauvilleCity_PokemonCenter_1F/scripts.pory"
	waitbuttonpress
# 22 "data/maps/MauvilleCity_PokemonCenter_1F/scripts.pory"
	release
# 23 "data/maps/MauvilleCity_PokemonCenter_1F/scripts.pory"
	end
# 24 "data/maps/MauvilleCity_PokemonCenter_1F/scripts.pory"

# 25 "data/maps/MauvilleCity_PokemonCenter_1F/scripts.pory"
MauvilleCity_PokemonCenter_1F_EventScript_Woman1::
# 26 "data/maps/MauvilleCity_PokemonCenter_1F/scripts.pory"
	msgbox MauvilleCity_PokemonCenter_1F_Text_ManOverThereSaysWeirdThings, MSGBOX_NPC
# 27 "data/maps/MauvilleCity_PokemonCenter_1F/scripts.pory"
	end
# 28 "data/maps/MauvilleCity_PokemonCenter_1F/scripts.pory"

# 29 "data/maps/MauvilleCity_PokemonCenter_1F/scripts.pory"
MauvilleCity_PokemonCenter_1F_EventScript_Woman2::
# 30 "data/maps/MauvilleCity_PokemonCenter_1F/scripts.pory"
	msgbox MauvilleCity_PokemonCenter_1F_Text_MyDataUpdatedFromRecordCorner, MSGBOX_NPC
# 31 "data/maps/MauvilleCity_PokemonCenter_1F/scripts.pory"
	end
# 32 "data/maps/MauvilleCity_PokemonCenter_1F/scripts.pory"

# 33 "data/maps/MauvilleCity_PokemonCenter_1F/scripts.pory"
MauvilleCity_PokemonCenter_1F_EventScript_Youngster::
# 34 "data/maps/MauvilleCity_PokemonCenter_1F/scripts.pory"
	msgbox MauvilleCity_PokemonCenter_1F_Text_RecordCornerSoundsFun, MSGBOX_NPC
# 35 "data/maps/MauvilleCity_PokemonCenter_1F/scripts.pory"
	end
# 36 "data/maps/MauvilleCity_PokemonCenter_1F/scripts.pory"

# 37 "data/maps/MauvilleCity_PokemonCenter_1F/scripts.pory"
MauvilleCity_PokemonCenter_1F_Text_ManOverThereSaysWeirdThings:
# 38 "data/maps/MauvilleCity_PokemonCenter_1F/scripts.pory"
	.string "That man over there, he says weird\n"
# 39 "data/maps/MauvilleCity_PokemonCenter_1F/scripts.pory"
	.string "things!\p"
# 40 "data/maps/MauvilleCity_PokemonCenter_1F/scripts.pory"
	.string "He's funny in a weird way.\n"
# 41 "data/maps/MauvilleCity_PokemonCenter_1F/scripts.pory"
	.string "I doubt I'll forget about him!$"
# 42 "data/maps/MauvilleCity_PokemonCenter_1F/scripts.pory"

# 43 "data/maps/MauvilleCity_PokemonCenter_1F/scripts.pory"
MauvilleCity_PokemonCenter_1F_Text_MyDataUpdatedFromRecordCorner:
# 44 "data/maps/MauvilleCity_PokemonCenter_1F/scripts.pory"
	.string "When I accessed the RECORD CORNER,\n"
# 45 "data/maps/MauvilleCity_PokemonCenter_1F/scripts.pory"
	.string "the data for what's hot in DEWFORD\l"
# 46 "data/maps/MauvilleCity_PokemonCenter_1F/scripts.pory"
	.string "got updated.\p"
# 47 "data/maps/MauvilleCity_PokemonCenter_1F/scripts.pory"
	.string "Now that bit of data is the same\n"
# 48 "data/maps/MauvilleCity_PokemonCenter_1F/scripts.pory"
	.string "as my friend's!$"
# 49 "data/maps/MauvilleCity_PokemonCenter_1F/scripts.pory"

# 50 "data/maps/MauvilleCity_PokemonCenter_1F/scripts.pory"
MauvilleCity_PokemonCenter_1F_Text_RecordCornerSoundsFun:
# 51 "data/maps/MauvilleCity_PokemonCenter_1F/scripts.pory"
	.string "A RECORD CORNER opened upstairs in\n"
# 52 "data/maps/MauvilleCity_PokemonCenter_1F/scripts.pory"
	.string "the POKéMON CENTER.\p"
# 53 "data/maps/MauvilleCity_PokemonCenter_1F/scripts.pory"
	.string "I don't know what it's about, but it\n"
# 54 "data/maps/MauvilleCity_PokemonCenter_1F/scripts.pory"
	.string "sounds fun. I'll go check it out!$"
