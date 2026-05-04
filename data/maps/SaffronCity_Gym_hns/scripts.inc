SaffronCity_Gym_hns_MapScripts::
	.byte 0

SaffronCity_Gym_EventScript_GymGuy::
	goto_if_set FLAG_DEFEATED_SAFFRON_GYM, SaffronCity_Gym_EventScript_GymGuy2
	msgbox SaffronCity_Gym_Text_GymGuideIntro, MSGBOX_NPC
	end

SaffronCity_Gym_EventScript_GymGuy2::
	msgbox SaffronCity_Gym_Text_GymGuideWin, MSGBOX_NPC
	end

SaffronCity_Gym_EventScript_Rebecca::
	trainerbattle_single TRAINER_REBECCA SaffronCity_Gym_Text_MediumRebeccaSeen, SaffronCity_Gym_Text_MediumRebeccaBeaten
	msgbox SaffronCity_Gym_Text_MediumRebeccaAfter, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_Franklin::
	trainerbattle_single TRAINER_FRANKLIN SaffronCity_Gym_Text_PsychicFranklinSeen, SaffronCity_Gym_Text_PsychicFranklinBeaten
	msgbox SaffronCity_Gym_Text_PsychicFranklinAfter, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_Doris::
	trainerbattle_single TRAINER_DORIS SaffronCity_Gym_Text_MediumDorisSeen, SaffronCity_Gym_Text_MediumDorisBeaten
	msgbox SaffronCity_Gym_Text_MediumDorisAfter, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_Jared::
	trainerbattle_single TRAINER_JARED SaffronCity_Gym_Text_PsychicJaredSeen, SaffronCity_Gym_Text_PsychicJaredBeaten
	msgbox SaffronCity_Gym_Text_PsychicJaredAfter, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_Sabrina::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_SAFFRON_GYM, SaffronCity_Gym_EventScript_Sabrina_Defeated
	msgbox SaffronCity_Gym_Text_SabrinaIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_SABRINA, SaffronCity_Gym_Text_SabrinaWinLoss
	message SaffronCity_Gym_Text_ReceivedMarshBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox SaffronCity_Gym_Text_MarshBadgeInfo, MSGBOX_DEFAULT
	setflag FLAG_BADGE13_GET
	setflag FLAG_DEFEATED_SAFFRON_GYM
	addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 13
	call Common_EventScript_SetGymTrainers
	closemessage
	clearflag FLAG_HIDE_OLIVINE_SABRINA
	release
	end

SaffronCity_Gym_EventScript_Sabrina_Defeated::
	msgbox SaffronCity_Gym_Text_SabrinaPostBattle, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_Gym_Text_SabrinaIntro:
	.string "SABRINA: I knew you were coming…\p"
	.string "Three years ago I had a vision\n"
	.string "of your arrival.\p"
	.string "You're after my BADGE.\p"
	.string "I don't enjoy battling, but it's\n"
	.string "my duty as a LEADER to confer\l"
	.string "BADGES on anyone who has proven\l"
	.string "him- or herself worthy.\p"
	.string "Since you wish it, I will show\n"
	.string "you my psychic powers!$"

SaffronCity_Gym_Text_SabrinaWinLoss:
	.string "SABRINA: Your power…\p"
	.string "It far exceeds what I foresaw…\p"
	.string "Maybe it isn't possible to fully\n"
	.string "predict what the future holds…\p"
	.string "OK, you win. You earned yourself\n"
	.string "MARSHBADGE.$"

SaffronCity_Gym_Text_ReceivedMarshBadge:
	.string "{PLAYER} received MARSHBADGE.$"

SaffronCity_Gym_Text_MarshBadgeInfo:
	.string "SABRINA: MARSHBADGE draws out\n"
	.string "your subliminal powers…\p"
	.string "Although I failed to accurately\n"
	.string "predict your power, this much I\l"
	.string "know to be true.\p"
	.string "You will become a celebrated and\n"
	.string "beloved CHAMPION!$"

SaffronCity_Gym_Text_SabrinaPostBattle:
	.string "SABRINA: Your love for your\n"
	.string "POKéMON overwhelmed my psychic\l"
	.string "power…\p"
	.string "The power of love, I think, is\n"
	.string "also a kind of psychic power…$"

SaffronCity_Gym_Text_SabrinaRematch:
	.string "SABRINA: Ah, the KANTO CHAMPION.\p"
	.string "I sensed your return.\p"
	.string "Your power has grown immensely.\p"
	.string "Even now, I feel your aura.\p"
	.string "Want to have a rematch with me?$"

SaffronCity_Gym_Text_SabrinaRematchDefeat:
	.string "SABRINA: Your love for your\n"
	.string "POKéMON again overwhelmed my\l"
	.string "psychic power…$"

SaffronCity_Gym_Text_MediumRebeccaSeen:
	.string "The power of all those you\n"
	.string "defeated comes to me!$"

SaffronCity_Gym_Text_MediumRebeccaBeaten:
	.string "Strong… Far too strong…$"

SaffronCity_Gym_Text_MediumRebeccaAfter:
	.string "What is the source of your power?$"

SaffronCity_Gym_Text_PsychicFranklinSeen:
	.string "Psychic power is the power of\n"
	.string "your soul.$"

SaffronCity_Gym_Text_PsychicFranklinBeaten:
	.string "Your soul has more power than\n"
	.string "mine!$"

SaffronCity_Gym_Text_PsychicFranklinAfter:
	.string "You made your soul stronger, not\n"
	.string "just your abilities.$"

SaffronCity_Gym_Text_MediumDorisSeen:
	.string "Fufufufu… I see it clearly.\p"
	.string "I can see into your soul!$"

SaffronCity_Gym_Text_MediumDorisBeaten:
	.string "Though I read you, I still lost…$"

SaffronCity_Gym_Text_MediumDorisAfter:
	.string "Darn! I forgot that I predicted I\n"
	.string "would lose to you.$"

SaffronCity_Gym_Text_PsychicJaredSeen:
	.string "The FIGHTING DOJO next door was\n"
	.string "once this city's GYM.$"

SaffronCity_Gym_Text_PsychicJaredBeaten:
	.string "I was no match…$"

SaffronCity_Gym_Text_PsychicJaredAfter:
	.string "KARATE KING, the master of the\n"
	.string "FIGHTING DOJO, was just destroyed\l"
	.string "by SABRINA.$"

SaffronCity_Gym_Text_GymGuideIntro:
	.string "Yo, CHAMP in making!\p"
	.string "A trainer as skilled as you\n"
	.string "doesn't need to be told how to\l"
	.string "deal with PSYCHIC-type POKéMON,\l"
	.string "right?\p"
	.string "I expect great things from you!\p"
	.string "Good luck!$"

SaffronCity_Gym_Text_GymGuideWin:
	.string "That was another fantastic battle!$"

SaffronCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE13_GET, SaffronCity_Gym_EventScript_GymStatuePostVictory
	msgbox SaffronCity_Gym_Text_GymStatue
	releaseall
	end

SaffronCity_Gym_EventScript_GymStatuePostVictory::
	msgbox SaffronCity_Gym_Text_GymStatuePlayerWon
	releaseall
	end


SaffronCity_Gym_Text_GymStatue::
    .string "SAFFRON POKéMON GYM\n"
    .string "LEADER: SABRINA\p"
	.string "WINNING TRAINERS:\n"
	.string "BLUE, RED$"

SaffronCity_Gym_Text_GymStatuePlayerWon::
    .string "SAFFRON POKéMON GYM\n"
    .string "LEADER: SABRINA\p"
    .string "WINNING TRAINERS:\n"
	.string "BLUE, RED, {PLAYER}$"
