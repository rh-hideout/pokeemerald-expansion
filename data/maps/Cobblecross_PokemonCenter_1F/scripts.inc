Cobblecross_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Cobblecross_PokemonCenter_1F_OnTransition
	.byte 0

Cobblecross_PokemonCenter_1F_OnTransition::
	setflag FLAG_P_FLY_COBBLECROSS
	setrespawn HEAL_LOCATION_COBBLECROSS
	end

Cobblecross_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_COBBLECROSS_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

Cobblecross_PokemonCenter_1F_EventScript_Hiker::
	msgbox Cobblecross_PokemonCenter_1F_Text_1, MSGBOX_NPC
	end

Cobblecross_PokemonCenter_1F_Text_1::
	.string "Rock Pokémon hate Water, Grass,\n"
	.string "Fighting, Ground and Steel moves.\p"
	.string "Garnet's sandstorm chips away at\n"
	.string "anything that isn't Rock, Ground\l"
	.string "or Steel, though!$"

