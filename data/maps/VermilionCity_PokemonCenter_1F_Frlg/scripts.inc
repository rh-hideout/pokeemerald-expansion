VermilionCity_PokemonCenter_1F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VermilionCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

VermilionCity_PokemonCenter_1F_OnTransition::
	setrespawn HEAL_LOCATION_VERMILION_CITY
	end

VermilionCity_PokemonCenter_1F_EventScript_Nurse::
	lock
	faceplayer
	call EventScript_PkmnCenterNurse_Frlg
	release
	end

VermilionCity_PokemonCenter_1F_EventScript_Man::
	msgbox VermilionCity_PokemonCenter_1F_Text_PoisonedMonFaintedWhileWalking, MSGBOX_NPC
	end

VermilionCity_PokemonCenter_1F_EventScript_Hiker::
	msgbox VermilionCity_PokemonCenter_1F_Text_TrainerMonsStrongerThanWild, MSGBOX_NPC
	end

VermilionCity_PokemonCenter_1F_EventScript_Youngster::
	msgbox VermilionCity_PokemonCenter_1F_Text_AllMonWeakToSpecificTypes, MSGBOX_NPC
	end

VermilionCity_PokemonCenter_1F_EventScript_VSSeekerWoman::
	lock
	faceplayer
	goto_if_set FLAG_GOT_VS_SEEKER, VermilionCity_PokemonCenter_1F_EventScript_ExplainVSSeeker
	msgbox VermilionCity_PokemonCenter_1F_Text_UrgeToBattleSomeoneAgain
	setflag FLAG_GOT_VS_SEEKER
	giveitem ITEM_VS_SEEKER
	goto_if_eq VAR_RESULT, FALSE, EventScript_BagIsFull
	msgbox VermilionCity_PokemonCenter_1F_Text_UseDeviceForRematches
	release
	end

VermilionCity_PokemonCenter_1F_EventScript_ExplainVSSeeker::
	msgbox VermilionCity_PokemonCenter_1F_Text_ExplainVSSeeker
	release
	end

VermilionCity_PokemonCenter_1F_Text_TrainerMonsStrongerThanWild::
	.string "Even if they are the same level,\n"
	.string "[Pokémon] can have very different\l"
	.string "stats and abilities.\p"
	.string "A [Pokémon] raised by a [Trainer] is\n"
	.string "stronger than one in the wild.$"

VermilionCity_PokemonCenter_1F_Text_PoisonedMonFaintedWhileWalking::
	.string "My [Pokémon] was poisoned!\n"
	.string "It fainted while we were walking!$"

VermilionCity_PokemonCenter_1F_Text_AllMonWeakToSpecificTypes::
	.string "It is true that a higher-level\n"
	.string "[Pokémon] will be more powerful…\p"
	.string "But, all [Pokémon] will have weak\n"
	.string "points against specific types.\p"
	.string "So, there appears to be no\n"
	.string "universally strong [Pokémon].$"

VermilionCity_PokemonCenter_1F_Text_UrgeToBattleSomeoneAgain::
	.string "The urge to battle with someone\n"
	.string "you've tangled with before…\p"
	.string "Have you ever had that urge?\n"
	.string "I'm sure you have.\p"
	.string "I wanted to battle certain people\n"
	.string "again over and over, too.\p"
	.string "So, I've been giving these away.\n"
	.string "Please, take one!$"

VermilionCity_PokemonCenter_1F_Text_UseDeviceForRematches::
	.string "Use that device and you'll find\n"
	.string "[Trainers] looking for a rematch.\p"
	.string "You have to charge its battery to\n"
	.string "use it, though.$"

VermilionCity_PokemonCenter_1F_Text_ExplainVSSeeker::
	.string "How do you use the [VS Seeker]?\n"
	.string "There's nothing to it.\p"
	.string "Use it like beep-beep-beep, and\n"
	.string "[Trainers] around you will notice.\p"
	.string "If any [Trainer] wants a rematch,\n"
	.string "it will let you know immediately.\p"
	.string "Charge its battery and use it\n"
	.string "while you're on a road.$"
