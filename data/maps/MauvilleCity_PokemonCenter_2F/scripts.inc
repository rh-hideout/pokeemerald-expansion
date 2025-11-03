# 1 "data/maps/MauvilleCity_PokemonCenter_2F/scripts.pory"

# 2 "data/maps/MauvilleCity_PokemonCenter_2F/scripts.pory"
MauvilleCity_PokemonCenter_2F_MapScripts::
# 3 "data/maps/MauvilleCity_PokemonCenter_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CableClub_OnFrame
# 4 "data/maps/MauvilleCity_PokemonCenter_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, CableClub_OnWarp
# 5 "data/maps/MauvilleCity_PokemonCenter_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, CableClub_OnLoad
# 6 "data/maps/MauvilleCity_PokemonCenter_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, CableClub_OnTransition
# 7 "data/maps/MauvilleCity_PokemonCenter_2F/scripts.pory"
	.byte 0
# 8 "data/maps/MauvilleCity_PokemonCenter_2F/scripts.pory"

# 9 "data/maps/MauvilleCity_PokemonCenter_2F/scripts.pory"
@ The below 3 are unused and leftover from RS
# 10 "data/maps/MauvilleCity_PokemonCenter_2F/scripts.pory"
MauvilleCity_PokemonCenter_2F_EventScript_Colosseum::
# 11 "data/maps/MauvilleCity_PokemonCenter_2F/scripts.pory"
	call CableClub_EventScript_Colosseum
# 12 "data/maps/MauvilleCity_PokemonCenter_2F/scripts.pory"
	end
# 13 "data/maps/MauvilleCity_PokemonCenter_2F/scripts.pory"

# 14 "data/maps/MauvilleCity_PokemonCenter_2F/scripts.pory"
MauvilleCity_PokemonCenter_2F_EventScript_TradeCenter::
# 15 "data/maps/MauvilleCity_PokemonCenter_2F/scripts.pory"
	call CableClub_EventScript_TradeCenter
# 16 "data/maps/MauvilleCity_PokemonCenter_2F/scripts.pory"
	end
# 17 "data/maps/MauvilleCity_PokemonCenter_2F/scripts.pory"

# 18 "data/maps/MauvilleCity_PokemonCenter_2F/scripts.pory"
MauvilleCity_PokemonCenter_2F_EventScript_RecordCorner::
# 19 "data/maps/MauvilleCity_PokemonCenter_2F/scripts.pory"
	call CableClub_EventScript_RecordCorner
# 20 "data/maps/MauvilleCity_PokemonCenter_2F/scripts.pory"
	end
# 21 "data/maps/MauvilleCity_PokemonCenter_2F/scripts.pory"

# 22 "data/maps/MauvilleCity_PokemonCenter_2F/scripts.pory"
MauvilleCity_PokemonCenter_2F_EventScript_Youngster::
# 23 "data/maps/MauvilleCity_PokemonCenter_2F/scripts.pory"
	msgbox MauvilleCity_PokemonCenter_2F_Text_Youngster, MSGBOX_NPC
# 24 "data/maps/MauvilleCity_PokemonCenter_2F/scripts.pory"
	end
# 25 "data/maps/MauvilleCity_PokemonCenter_2F/scripts.pory"

# 26 "data/maps/MauvilleCity_PokemonCenter_2F/scripts.pory"
MauvilleCity_PokemonCenter_2F_Text_Youngster:
# 27 "data/maps/MauvilleCity_PokemonCenter_2F/scripts.pory"
	.string "Did you know that you can link battle\n"
# 28 "data/maps/MauvilleCity_PokemonCenter_2F/scripts.pory"
	.string "at the COLOSSEUM here?\p"
# 29 "data/maps/MauvilleCity_PokemonCenter_2F/scripts.pory"
	.string "They put up your record on the wall\n"
# 30 "data/maps/MauvilleCity_PokemonCenter_2F/scripts.pory"
	.string "for everyone to see.\p"
# 31 "data/maps/MauvilleCity_PokemonCenter_2F/scripts.pory"
	.string "It's embarrassing if you lose more\n"
# 32 "data/maps/MauvilleCity_PokemonCenter_2F/scripts.pory"
	.string "often than you win…$"
