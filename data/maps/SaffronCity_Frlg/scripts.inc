SaffronCity_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SaffronCity_OnTransition
	.byte 0

SaffronCity_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_SAFFRON_CITY
	call_if_unset FLAG_RESCUED_MR_FUJI, SaffronCity_EventScript_MoveDoorGuardGrunt
	end

SaffronCity_EventScript_MoveDoorGuardGrunt::
	setobjectxyperm LOCALID_SAFFRON_DOOR_GUARD_GRUNT, 33, 31
	return

SaffronCity_EventScript_RocketGrunt1::
	msgbox SaffronCity_Text_WhatDoYouWantGetLost, MSGBOX_NPC
	end

SaffronCity_EventScript_RocketGrunt2::
	msgbox SaffronCity_Text_BossTakeTownForTeamRocket, MSGBOX_NPC
	end

SaffronCity_EventScript_RocketGrunt3::
	msgbox SaffronCity_Text_DontGetDefiantOrIllHurtYou, MSGBOX_NPC
	end

SaffronCity_EventScript_RocketGrunt4::
	msgbox SaffronCity_Text_SaffronBelongsToTeamRocket, MSGBOX_NPC
	end

SaffronCity_EventScript_RocketGrunt5::
	msgbox SaffronCity_Text_CriminalLifeMakesMeFeelAlive, MSGBOX_NPC
	end

SaffronCity_EventScript_RocketGrunt6::
	msgbox SaffronCity_Text_WatchWhereYoureWalking, MSGBOX_NPC
	end

SaffronCity_EventScript_RocketGrunt7::
	msgbox SaffronCity_Text_WeCanExploitMonsAroundWorld, MSGBOX_NPC
	end

SaffronCity_EventScript_DoorGuardGrunt::
	lock
	goto_if_set FLAG_RESCUED_MR_FUJI, SaffronCity_EventScript_DoorGuardAsleep
	applymovement LOCALID_SAFFRON_DOOR_GUARD_GRUNT, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SaffronCity_Text_ImASecurityGuard
	release
	end

SaffronCity_EventScript_DoorGuardAsleep::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	msgbox SaffronCity_Text_HesTakingASnooze
	release
	end

SaffronCity_EventScript_WorkerM::
	msgbox SaffronCity_Text_YouBeatTeamRocket, MSGBOX_NPC
	end

SaffronCity_EventScript_Youngster::
	msgbox SaffronCity_Text_SafeToGoOutAgain, MSGBOX_NPC
	end

SaffronCity_EventScript_Lass::
	msgbox SaffronCity_Text_PeopleComingBackToSaffron, MSGBOX_NPC
	end

SaffronCity_EventScript_Boy::
	msgbox SaffronCity_Text_FlewHereOnPidgeot, MSGBOX_NPC
	end

SaffronCity_EventScript_Pidgeot::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PIDGEOT, CRY_MODE_NORMAL
	msgbox SaffronCity_Text_Pidgeot
	waitmoncry
	release
	end

SaffronCity_EventScript_Man::
	msgbox SaffronCity_Text_SawRocketBossEscaping, MSGBOX_NPC
	end

SaffronCity_EventScript_CitySign::
	msgbox SaffronCity_Text_CitySign, MSGBOX_SIGN
	end

SaffronCity_EventScript_DojoSign::
	msgbox SaffronCity_Text_FightingDojo, MSGBOX_SIGN
	end

SaffronCity_EventScript_GymSign::
	lockall
	famechecker FAMECHECKER_SABRINA, 0
	msgbox SaffronCity_Text_GymSign
	releaseall
	end

SaffronCity_EventScript_TrainerTips1::
	msgbox SaffronCity_Text_FullHealCuresStatus, MSGBOX_SIGN
	end

SaffronCity_EventScript_TrainerTips2::
	msgbox SaffronCity_Text_GreatBallImprovedCatchRate, MSGBOX_SIGN
	end

SaffronCity_EventScript_SilphCoSign::
	msgbox SaffronCity_Text_SilphCoSign, MSGBOX_SIGN
	end

SaffronCity_EventScript_MrPsychicsHouseSign::
	msgbox SaffronCity_Text_MrPsychicsHouse, MSGBOX_SIGN
	end

SaffronCity_EventScript_SilphProductSign::
	msgbox SaffronCity_Text_SilphsLatestProduct, MSGBOX_SIGN
	end

SaffronCity_EventScript_TrainerFanClubSign::
	msgbox SaffronCity_Text_TrainerFanClubSign, MSGBOX_SIGN
	end

SaffronCity_Text_WhatDoYouWantGetLost::
	.string "What do you want?\n"
	.string "Get lost!$"

SaffronCity_Text_BossTakeTownForTeamRocket::
	.string "[Boss] said he'll take this town\n"
	.string "in the name of [Team Rocket]!$"

SaffronCity_Text_DontGetDefiantOrIllHurtYou::
	.string "Don't get defiant!\n"
	.string "Or I'll have to hurt you!$"

SaffronCity_Text_SaffronBelongsToTeamRocket::
	.string "[Saffron] belongs to [Team Rocket]!$"

SaffronCity_Text_CriminalLifeMakesMeFeelAlive::
	.string "My life as a criminal makes me feel\n"
	.string "so alive!$"

SaffronCity_Text_WatchWhereYoureWalking::
	.string "Ow!\n"
	.string "Watch where you're walking!$"

SaffronCity_Text_WeCanExploitMonsAroundWorld::
	.string "With [Silph] under control, we can\n"
	.string "exploit [Pokémon] around the world!\p"
	.string "We'll get stinking rich, yeahah!$"

SaffronCity_Text_YouBeatTeamRocket::
	.string "You beat [Team Rocket] all alone?\n"
	.string "That's amazing!$"

SaffronCity_Text_SafeToGoOutAgain::
	.string "Yeah! [Team Rocket] is gone!\n"
	.string "It's safe to go out again!$"

SaffronCity_Text_PeopleComingBackToSaffron::
	.string "People fled from here in droves\n"
	.string "when those [Rockets] came.\p"
	.string "They should be flocking back to\n"
	.string "[Saffron] now.$"

SaffronCity_Text_FlewHereOnPidgeot::
	.string "I flew here on my [Pidgeot] when\n"
	.string "I read about [Silph].\p"
	.string "It's already over?\n"
	.string "I missed the media action…$"

SaffronCity_Text_Pidgeot::
	.string "[Pidgeot]: Bi bibii!$"

SaffronCity_Text_SawRocketBossEscaping::
	.string "I saw the [Rocket Boss] escaping\n"
	.string "[Silph]'s building.$"

SaffronCity_Text_ImASecurityGuard::
	.string "I'm a security guard.\p"
	.string "Suspicious kids I don't allow in!$"

SaffronCity_Text_HesTakingASnooze::
	.string "…\n"
	.string "Snore…\p"
	.string "Hah! He's taking a snooze!$"

SaffronCity_Text_CitySign::
	.string "[Saffron City]\n"
	.string "Shining, Golden Land of Commerce$"

SaffronCity_Text_FightingDojo::
	.string "[Fighting Dojo]$"

SaffronCity_Text_GymSign::
	.string "[Saffron City Pokémon Gym]\n"
	.string "[Leader]: [Sabrina]\l"
	.string "The Master of [Psychic Pokémon]!$"

SaffronCity_Text_FullHealCuresStatus::
	.string "[Trainer Tips]\p"
	.string "[Full Heal] cures all ailments like\n"
	.string "burns, paralysis, poisoning,\l"
	.string "freezing, and sleep.\p"
	.string "It costs a bit more, but it's more\n"
	.string "convenient than buying other items.$"

SaffronCity_Text_GreatBallImprovedCatchRate::
	.string "[Trainer Tips]\p"
	.string "The new [Great Ball] offers improved\n"
	.string "catching rates.\p"
	.string "Try it on those hard-to-catch\n"
	.string "[Pokémon].$"

SaffronCity_Text_SilphCoSign::
	.string "[Silph Co. Office Building]$"

SaffronCity_Text_MrPsychicsHouse::
	.string "[Mr. Psychic's House]$"

SaffronCity_Text_SilphsLatestProduct::
	.string "[Silph]'s latest product!\n"
	.string "Release to be determined…$"

SaffronCity_Text_TrainerFanClubSign::
	.string "[Pokémon Trainer Fan Club]\p"
	.string "Many [Trainers] have scribbled their\n"
	.string "names on this sign.$"

SaffronCity_Text_HowCanClubNotRecognizeLance::
	.string "This [Fan Club]…\n"
	.string "No one here has a clue!\p"
	.string "How could they not recognize\n"
	.string "the brilliance that is [Lance]?\p"
	.string "He stands for justice!\n"
	.string "He's cool, and yet passionate!\l"
	.string "He's the greatest, [Lance]!$"
