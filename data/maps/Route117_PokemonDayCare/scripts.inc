# 1 "data/maps/Route117_PokemonDayCare/scripts.pory"

# 2 "data/maps/Route117_PokemonDayCare/scripts.pory"
Route117_PokemonDayCare_MapScripts::
# 3 "data/maps/Route117_PokemonDayCare/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route117_PokemonDayCare_OnTransition
# 4 "data/maps/Route117_PokemonDayCare/scripts.pory"
	.byte 0
# 5 "data/maps/Route117_PokemonDayCare/scripts.pory"

# 6 "data/maps/Route117_PokemonDayCare/scripts.pory"
Route117_PokemonDayCare_OnTransition:
# 7 "data/maps/Route117_PokemonDayCare/scripts.pory"
	setflag FLAG_LANDMARK_POKEMON_DAYCARE
# 8 "data/maps/Route117_PokemonDayCare/scripts.pory"
	end
