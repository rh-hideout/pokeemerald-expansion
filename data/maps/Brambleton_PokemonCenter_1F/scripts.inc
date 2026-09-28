Brambleton_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Brambleton_PokemonCenter_1F_OnTransition
	.byte 0

Brambleton_PokemonCenter_1F_OnTransition::
	setflag FLAG_P_FLY_BRAMBLETON
	setrespawn HEAL_LOCATION_BRAMBLETON
	end

Brambleton_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_BRAMBLETON_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

Brambleton_PokemonCenter_1F_EventScript_Gentleman::
	msgbox Brambleton_PokemonCenter_1F_Text_1, MSGBOX_NPC
	end

Brambleton_PokemonCenter_1F_EventScript_Youngster::
	msgbox Brambleton_PokemonCenter_1F_Text_2, MSGBOX_NPC
	end

Brambleton_PokemonCenter_1F_Text_1::
	.string "In Pentara, no one can use healing\n"
	.string "items during a battle. Not\l"
	.string "trainers, not you.\p"
	.string "Every battle is decided by\n"
	.string "strategy alone. I find that rather\l"
	.string "elegant.$"

Brambleton_PokemonCenter_1F_Text_2::
	.string "I lost to the Gym Leader, but I\n"
	.string "didn't lose any money!\p"
	.string "Lose to an important trainer and\n"
	.string "you just get to try again. No\l"
	.string "penalty!$"

