CeladonCity_Gym_MapScripts::
	.byte 0


CeladonCity_Gym_EventScript_Erika::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_CELADON_GYM, CeladonCity_Gym_EventScript_Erika_Defeated
	msgbox CeladonCity_Gym_Text_ErikaBeforeBattle, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_ERIKA, CeladonCity_Gym_Text_ErikaBeaten
	message CeladonCity_Gym_Text_PlayerReceivedRainbowBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox CeladonCity_Gym_Text_ErikaExplainTM, MSGBOX_DEFAULT
	giveitem ITEM_TM_GIGA_DRAIN
	setflag FLAG_BADGE12_GET
	setflag FLAG_DEFEATED_CELADON_GYM
	addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 12
	call Common_EventScript_SetGymTrainers
	clearflag FLAG_HIDE_FOUNTAIN_ERIKA
	closemessage
	release
	end

CeladonCity_Gym_EventScript_Erika_Defeated::
	msgbox CeladonCity_Gym_Text_ErikaAfterBattle, MSGBOX_DEFAULT
	closemessage
	release
	end

CeladonCity_Gym_Text_ErikaBeforeBattle:
	.string "ERIKA: Hello… Lovely weather,\n"
	.string "isn't it? It's so pleasant…\p"
	.string "…I'm afraid I may doze off…\p"
	.string "My name is ERIKA. I am the LEADER\n"
	.string "of CELADON GYM.\p"
	.string "…Oh? All the way from JOHTO, you\n"
	.string "say? How nice…\p"
	.string "Oh. I'm sorry, I didn't realize\n"
	.string "that you wished to challenge me.\p"
	.string "Very well, but I shall not lose.$"

CeladonCity_Gym_Text_ErikaBeaten:
	.string "ERIKA: Oh! I concede defeat…\p"
	.string "You are remarkably strong…\p"
	.string "I shall give you RAINBOWBADGE…$"

CeladonCity_Gym_Text_PlayerReceivedRainbowBadge:
	.string "{PLAYER} received RAINBOWBADGE.$"

CeladonCity_Gym_Text_ErikaExplainTM:
	.string "ERIKA: That was a delightful\n"
	.string "match.\p"
	.string "I felt inspired. Please, I wish\n"
	.string "you to have this TM.\p"
	.string "It is GIGA DRAIN.\p"
	.string "It is a wonderful move that\n"
	.string "drains half the damage it inflicts\l"
	.string "to heal your POKéMON.\p"
	.string "Please use it if it pleases you…$"

CeladonCity_Gym_Text_ErikaAfterBattle:
	.string "ERIKA: Losing leaves a bitter\n"
	.string "aftertaste…\p"
	.string "But knowing that there are strong\n"
	.string "trainers spurs me to do better…$"

CeladonCity_Gym_Text_ErikaRematch:
	.string "ERIKA: Oh, hello.\p"
	.string "What a surprise, KANTO CHAMPION!\p"
	.string "It's so lovely to see you again.\p"
	.string "Your journey must have been so\n"
	.string "exciting.\p"
	.string "Even champions enjoy a challenge.\p"
	.string "Want to have a rematch with me?$"

CeladonCity_Gym_Text_ErikaRematchDefeat:
	.string "ERIKA: Losing still leaves a\n"
	.string "bitter aftertaste…\p"
	.string "But knowing that there are strong\n"
	.string "trainers spurs me to do better…$"

CeladonCity_Gym_EventScript_Michelle::
	trainerbattle_single TRAINER_MICHELLE CeladonCity_Gym_Text_LassMichelleSeen, CeladonCity_Gym_Text_LassMichelleBeaten
	msgbox CeladonCity_Gym_Text_LassMichelleAfter, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_Text_LassMichelleSeen:
	.string "Do you think a girls-only GYM is\n"
	.string "rare?$"

CeladonCity_Gym_Text_LassMichelleBeaten:
	.string "Oh, bleah!$"

CeladonCity_Gym_Text_LassMichelleAfter:
	.string "I just got careless, that's all!$"


CeladonCity_Gym_EventScript_Tanya::
	trainerbattle_single TRAINER_TANYA CeladonCity_Gym_Text_PicnickerTanyaSeen, CeladonCity_Gym_Text_PicnickerTanyaBeaten
	msgbox CeladonCity_Gym_Text_PicnickerTanyaAfter, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_Text_PicnickerTanyaSeen:
	.string "Oh, a battle? That's kind of scary,\n"
	.string "but OK!$"

CeladonCity_Gym_Text_PicnickerTanyaBeaten:
	.string "Oh, that's it?$"

CeladonCity_Gym_Text_PicnickerTanyaAfter:
	.string "Oh, look at all your BADGES. No\n"
	.string "wonder I couldn't win!$"

CeladonCity_Gym_EventScript_Julia::
	trainerbattle_single TRAINER_JULIA CeladonCity_Gym_Text_BeautyJuliaSeen, CeladonCity_Gym_Text_BeautyJuliaBeaten
	msgbox CeladonCity_Gym_Text_BeautyJuliaAfter, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_Text_BeautyJuliaSeen:
	.string "Were you looking at these flowers\n"
	.string "or at me?$"

CeladonCity_Gym_Text_BeautyJuliaBeaten:
	.string "How annoying!$"

CeladonCity_Gym_Text_BeautyJuliaAfter:
	.string "How do I go about becoming\n"
	.string "ladylike like ERIKA?$"

CeladonCity_Gym_EventScript_Jo::
	trainerbattle_double TRAINER_JO_AND_ZOE, CeladonCity_Gym_Text_TwinsJoAndZoe1Seen, CeladonCity_Gym_Text_TwinsJoAndZoe1Beaten, Route104_Text_GinaNotEnoughMons
	special GetPlayerBigGuyGirlString
	msgbox CeladonCity_Gym_Text_TwinsJoAndZoe1After, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_EventScript_Zoe::
	trainerbattle_double TRAINER_JO_AND_ZOE, CeladonCity_Gym_Text_TwinsJoAndZoe2Seen, CeladonCity_Gym_Text_TwinsJoAndZoe2Beaten, Route104_Text_GinaNotEnoughMons
	msgbox CeladonCity_Gym_Text_TwinsJoAndZoe2After, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_Text_TwinsJoAndZoe1Seen:
	.string "We'll show you POKéMON moves that\n"
	.string "ERIKA taught us!$"

CeladonCity_Gym_Text_TwinsJoAndZoe1Beaten:
	.string "Oh… We lost…$"

CeladonCity_Gym_Text_TwinsJoAndZoe1After:
	.string "ERIKA will get you back for us!$"

CeladonCity_Gym_Text_TwinsJoAndZoe2Seen:
	.string "We're going to protect ERIKA!$"

CeladonCity_Gym_Text_TwinsJoAndZoe2Beaten:
	.string "We couldn't win…$"

CeladonCity_Gym_Text_TwinsJoAndZoe2After:
	.string "ERIKA is much, much stronger!$"

CeladonCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE12_GET, CeladonCity_Gym_EventScript_GymStatuePostVictory
	msgbox CeladonCity_Gym_Text_GymStatue
	releaseall
	end

CeladonCity_Gym_EventScript_GymStatuePostVictory::
	msgbox CeladonCity_Gym_Text_GymStatuePlayerWon
	releaseall
	end

CeladonCity_Gym_Text_GymStatue::
    .string "CELADON POKéMON GYM\n"
    .string "LEADER: ERIKA\p"
	.string "WINNING TRAINERS:\n"
	.string "BLUE, RED$"

CeladonCity_Gym_Text_GymStatuePlayerWon::
    .string "CELADON POKéMON GYM\n"
    .string "LEADER: ERIKA\p"
    .string "WINNING TRAINERS:\n"
	.string "BLUE, RED, {PLAYER}$"
