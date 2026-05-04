.set LOCALID_CIANWOOD_CHUCK, 1
.set LOCALID_CIANWOOD_CHUCK_ROCK_LEFT, 10
.set LOCALID_CIANWOOD_CHUCK_ROCK_RIGHT, 9

CianwoodGym_MapScripts::
	.byte 0


CianwoodGym_EventScript_Statue::
	lock
	goto_if_set FLAG_DEFEATED_CIANWOOD_GYM, CianwoodGym_EventScript_Statue2
	msgbox CianwoodGym_Text_GymStatue, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodGym_EventScript_Statue2::
	msgbox CianwoodGym_Text_GymStatueCertified, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodGym_Text_GymStatue:
	.string "CIANWOOD CITY POKéMON GYM$"

CianwoodGym_Text_GymStatueCertified:
	.string "CIANWOOD CITY POKéMON GYM\p"
	.string "CHUCK'S CERTIFIED TRAINERS:\n"
	.string "{PLAYER}$"

CianwoodGym_EventScript_Chuck::
	lock
	faceplayer
	goto_if_unset FLAG_HIDE_DOJO_CHUCK, CianwoodGym_EventScript_ChuckAtDojo
	goto_if_set FLAG_VISITED_VERMILION_CITY, CianwoodGym_EventScript_ChuckGotoDojo
	goto_if_set FLAG_DEFEATED_CIANWOOD_GYM, CianwoodGym_EventScript_Chuck_Defeated
	msgbox CianwoodGym_Text_ChuckIntro1, MSGBOX_DEFAULT
	applymovement LOCALID_CIANWOOD_CHUCK, CianwoodGym_Movement_ChuckLeft
	waitmovement 0
	message CianwoodGym_Text_ChuckIntro2
	applymovement LOCALID_CIANWOOD_CHUCK_ROCK_LEFT, Movement_SmashRock
	playse SE_M_ROCK_THROW
	waitmovement 0

	delay 20

	applymovement LOCALID_CIANWOOD_CHUCK, CianwoodGym_Movement_ChuckRight
	waitmovement 0
	applymovement LOCALID_CIANWOOD_CHUCK_ROCK_RIGHT, Movement_SmashRock
	playse SE_M_ROCK_THROW
	waitmovement 0
	waitmessage
	turnobject LOCALID_CIANWOOD_CHUCK, DIR_SOUTH
	msgbox CianwoodGym_Text_ChuckIntro3, MSGBOX_DEFAULT
	goto_if_set FLAG_DEFEATED_OLIVINE_CITY_GYM, CianwoodGym_EventScript_OlivineCheckMahog
	goto_if_set FLAG_DEFEATED_MAHOGANY_TOWN_GYM, CianwoodGym_EventScript_MahogCheckOlivine
	goto CianwoodGym_EventScript_Chuck_Battle1

CianwoodGym_EventScript_ChuckVictory::
	message CianwoodGym_Text_GetStormBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox CianwoodGym_Text_ChuckBadgeSpeech, MSGBOX_DEFAULT
	setflag FLAG_BADGE05_GET
	setflag FLAG_DEFEATED_CIANWOOD_GYM
	addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 5
	call Common_EventScript_SetGymTrainers
	giveitem ITEM_TM_FOCUS_PUNCH
	msgbox CianwoodGym_Text_ChuckTMSpeech, MSGBOX_DEFAULT
	setvar VAR_GETFLY, 1
	setrespawn HEAL_LOCATION_CIANWOOD_CITY
	closemessage
	release
	end

CianwoodGym_EventScript_ChuckGotoDojo::
	msgbox CianwoodGym_Text_ChuckGotoDojo, MSGBOX_DEFAULT
	closemessage
	clearflag FLAG_HIDE_DOJO_CHUCK
	release
	end

CianwoodGym_Text_ChuckGotoDojo:
	.string "WAHAHAHA {PLAYER}!\n"
	.string "I'm in the middle of my training!\p"
	.string "If you want another match, come to\n"
	.string "the FIGHTING DOJO in SAFFRON!$"	

CianwoodGym_EventScript_ChuckAtDojo::
	msgbox CianwoodGym_Text_ChuckAtDojo, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodGym_Text_ChuckAtDojo:
	.string "I will see you at the DOJO!\n"
	.string "WAHAHAHAHAHA$"

CianwoodGym_EventScript_OlivineCheckMahog::
	goto_if_set FLAG_DEFEATED_MAHOGANY_TOWN_GYM, CianwoodGym_EventScript_Chuck_Battle3
	goto CianwoodGym_EventScript_Chuck_Battle2

CianwoodGym_EventScript_MahogCheckOlivine::
	goto_if_set FLAG_DEFEATED_OLIVINE_CITY_GYM, CianwoodGym_EventScript_Chuck_Battle3
	goto CianwoodGym_EventScript_Chuck_Battle2
	
CianwoodGym_EventScript_Chuck_Battle1::
	trainerbattle_no_intro TRAINER_CHUCK_1, CianwoodGym_Text_ChuckIntro2
	goto CianwoodGym_EventScript_ChuckVictory

CianwoodGym_EventScript_Chuck_Battle2::
	trainerbattle_no_intro TRAINER_CHUCK_1_2, CianwoodGym_Text_ChuckIntro2
	goto CianwoodGym_EventScript_ChuckVictory

CianwoodGym_EventScript_Chuck_Battle3::
	trainerbattle_no_intro TRAINER_CHUCK_1_3, CianwoodGym_Text_ChuckIntro2
	goto CianwoodGym_EventScript_ChuckVictory

CianwoodGym_EventScript_Chuck_Defeated::
	msgbox CianwoodGym_Text_ChuckAfter, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodGym_Movement_ChuckLeft:
	jump_in_place_left
	step_end

CianwoodGym_Movement_ChuckRight:
	jump_in_place_right
	step_end

CianwoodGym_Text_ChuckIntro1:
	.string "WAHAHAH!\p"
	.string "So you've come this far!\p"
	.string "Let me tell you, I'm tough!\p"
	.string "My POKéMON will crush stones and\n"
	.string "shatter bones!\p"
	.string "Watch this!$"

CianwoodGym_Text_ChuckIntro2:
	.string "CHUCK: Urggh!\n"
	.string "…\p"
	.string "Oooarrgh!$"

CianwoodGym_Text_ChuckIntro3:
	.string "There! Scared now, are you?\p"
	.string "What? It has nothing to do with\n"
	.string "POKéMON?\p"
	.string "That's true!\p"
	.string "Come on. We shall do battle!$"

CianwoodGym_Text_ChuckLoss:
	.string "Wha? Huh? I lost?\p"
	.string "How about that!\n"
	.string "You're worthy of STORMBADGE!$"

CianwoodGym_Text_GetStormBadge:
	.string "{PLAYER} received STORMBADGE.$"

CianwoodGym_Text_ChuckBadgeSpeech:
	.string "STORMBADGE makes all POKéMON up to\n"
	.string "L70 obey, even traded ones.\p"
	.string "It also lets your POKéMON use FLY\n"
	.string "when you're not in a battle.\p"
	.string "Here, take this too!$"

CianwoodGym_Text_ChuckTMSpeech:
	.string "That is FOCUS PUNCH.\p"
	.string "It moves slow but deals huge\n"
	.string "damage. Just don't get hit first!$"

CianwoodGym_Text_ChuckAfter:
	.string "WAHAHAH! I enjoyed battling you!\p"
	.string "But a loss is a loss!\p"
	.string "From now on, I'm going to train\n"
	.string "24 hours a day!$"

CianwoodGym_Text_ChuckRematch:
	.string "WAHAHAH! JOHTO CHAMPION!\p"
	.string "You've come back for more!\p"
	.string "I see your skills have improved!\p"
	.string "Ready to see who's stronger?$"

CianwoodGym_Text_ChuckRematchDefeat:
	.string "Wha? Huh? I lost?\n"
	.string "Again?$"

CianwoodGym_EventScript_Yoshi::
	trainerbattle_single TRAINER_YOSHI CianwoodGym_Text_BlackbeltYoshiSeen, CianwoodGym_Text_BlackbeltYoshiBeaten
	msgbox CianwoodGym_Text_BlackbeltYoshiAfter, MSGBOX_AUTOCLOSE
	end

CianwoodGym_Text_BlackbeltYoshiSeen:
	.string "My POKéMON and I are bound togeth-\n"
	.string "er by friendship.\p"
	.string "Our bond will never be broken!$"

CianwoodGym_Text_BlackbeltYoshiBeaten:
	.string "This isn't real!$"

CianwoodGym_Text_BlackbeltYoshiAfter:
	.string "You seem to have a strong bond\n"
	.string "with your POKéMON too!$"

CianwoodGym_EventScript_Lao::
	trainerbattle_single TRAINER_LAO CianwoodGym_Text_BlackbeltLaoSeen, CianwoodGym_Text_BlackbeltLaoBeaten
	msgbox CianwoodGym_Text_BlackbeltLaoAfter, MSGBOX_AUTOCLOSE
	end

CianwoodGym_Text_BlackbeltLaoSeen:
	.string "We martial artists fear nothing!$"

CianwoodGym_Text_BlackbeltLaoBeaten:
	.string "That's shocking!$"

CianwoodGym_Text_BlackbeltLaoAfter:
	.string "Fighting POKéMON are afraid of\n"
	.string "psychics…$"


CianwoodGym_EventScript_Nob::
	trainerbattle_single TRAINER_NOB CianwoodGym_Text_BlackbeltNobSeen, CianwoodGym_Text_BlackbeltNobBeaten
	msgbox CianwoodGym_Text_BlackbeltNobAfter, MSGBOX_AUTOCLOSE
	end

CianwoodGym_Text_BlackbeltNobSeen:
	.string "Words are useless.\n"
	.string "Let your fists do the talking!$"

CianwoodGym_Text_BlackbeltNobBeaten:
	.string "…$"

CianwoodGym_Text_BlackbeltNobAfter:
	.string "I lost! I'm speechless!$"

CianwoodGym_EventScript_Lung::
	trainerbattle_single TRAINER_LUNG CianwoodGym_Text_BlackbeltLungSeen, CianwoodGym_Text_BlackbeltLungBeaten
	msgbox CianwoodGym_Text_BlackbeltLungAfter, MSGBOX_AUTOCLOSE
	end

CianwoodGym_Text_BlackbeltLungSeen:
	.string "My raging fists will shatter your\n"
	.string "POKéMON!$"

CianwoodGym_Text_BlackbeltLungBeaten:
	.string "I got shattered!$"

CianwoodGym_Text_BlackbeltLungAfter:
	.string "My POKéMON lost…\n"
	.string "My… my pride is shattered…$"

