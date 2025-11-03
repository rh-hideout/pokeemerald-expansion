# 1 "data/maps/MossdeepCity_PokemonCenter_2F/scripts.pory"

# 2 "data/maps/MossdeepCity_PokemonCenter_2F/scripts.pory"
MossdeepCity_PokemonCenter_2F_MapScripts::
# 3 "data/maps/MossdeepCity_PokemonCenter_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CableClub_OnFrame
# 4 "data/maps/MossdeepCity_PokemonCenter_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, CableClub_OnWarp
# 5 "data/maps/MossdeepCity_PokemonCenter_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, CableClub_OnLoad
# 6 "data/maps/MossdeepCity_PokemonCenter_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, CableClub_OnTransition
# 7 "data/maps/MossdeepCity_PokemonCenter_2F/scripts.pory"
	.byte 0
# 8 "data/maps/MossdeepCity_PokemonCenter_2F/scripts.pory"

# 9 "data/maps/MossdeepCity_PokemonCenter_2F/scripts.pory"
@ The below 3 are unused and leftover from RS
# 10 "data/maps/MossdeepCity_PokemonCenter_2F/scripts.pory"
MossdeepCity_PokemonCenter_2F_EventScript_Colosseum::
# 11 "data/maps/MossdeepCity_PokemonCenter_2F/scripts.pory"
	call CableClub_EventScript_Colosseum
# 12 "data/maps/MossdeepCity_PokemonCenter_2F/scripts.pory"
	end
# 13 "data/maps/MossdeepCity_PokemonCenter_2F/scripts.pory"

# 14 "data/maps/MossdeepCity_PokemonCenter_2F/scripts.pory"
MossdeepCity_PokemonCenter_2F_EventScript_TradeCenter::
# 15 "data/maps/MossdeepCity_PokemonCenter_2F/scripts.pory"
	call CableClub_EventScript_TradeCenter
# 16 "data/maps/MossdeepCity_PokemonCenter_2F/scripts.pory"
	end
# 17 "data/maps/MossdeepCity_PokemonCenter_2F/scripts.pory"

# 18 "data/maps/MossdeepCity_PokemonCenter_2F/scripts.pory"
MossdeepCity_PokemonCenter_2F_EventScript_RecordCorner::
# 19 "data/maps/MossdeepCity_PokemonCenter_2F/scripts.pory"
	call CableClub_EventScript_RecordCorner
# 20 "data/maps/MossdeepCity_PokemonCenter_2F/scripts.pory"
	end
# 21 "data/maps/MossdeepCity_PokemonCenter_2F/scripts.pory"

# 22 "data/maps/MossdeepCity_PokemonCenter_2F/scripts.pory"
MossdeepCity_PokemonCenter_2F_EventScript_Woman5::
# 23 "data/maps/MossdeepCity_PokemonCenter_2F/scripts.pory"
	msgbox MossdeepCity_PokemonCenter_2F_Text_Woman5, MSGBOX_NPC
# 24 "data/maps/MossdeepCity_PokemonCenter_2F/scripts.pory"
	end
# 25 "data/maps/MossdeepCity_PokemonCenter_2F/scripts.pory"

# 26 "data/maps/MossdeepCity_PokemonCenter_2F/scripts.pory"
MossdeepCity_PokemonCenter_2F_Text_Woman5:
# 27 "data/maps/MossdeepCity_PokemonCenter_2F/scripts.pory"
	.string "If I win a whole lot of link battles\n"
# 28 "data/maps/MossdeepCity_PokemonCenter_2F/scripts.pory"
	.string "and show everyone how good I am,\l"
# 29 "data/maps/MossdeepCity_PokemonCenter_2F/scripts.pory"
	.string "I might get a fan following!$"
