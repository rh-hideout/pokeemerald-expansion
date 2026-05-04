EcruteakCity_Gym_MapScripts::
	.byte 0

EcruteakCity_Gym_EventScript_GymGuy::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_ECRUTEAK_CITY_GYM, EcruteakCity_Gym_EventScript_GymGuy2
	msgbox EcruteakCity_GymGuideText, MSGBOX_DEFAULT
	closemessage
	release
	end
	
EcruteakCity_Gym_EventScript_GymGuy2::
	msgbox EcruteakCity_GymGuideWinText, MSGBOX_DEFAULT
	release
	end	

EcruteakCity_Gym_EventScript_Jeffrey::
	trainerbattle_single TRAINER_JEFFREY SageJeffreySeenText, SageJeffreyBeatenText
	msgbox SageJeffreyAfterBattleText, MSGBOX_AUTOCLOSE
	end
EcruteakCity_Gym_EventScript_Ping::
	trainerbattle_single TRAINER_PING SagePingSeenText, SagePingBeatenText
	msgbox SagePingAfterBattleText, MSGBOX_AUTOCLOSE
	end

EcruteakCity_Gym_EventScript_Martha::
	trainerbattle_single TRAINER_MARTHA MediumMarthaSeenText, MediumMarthaBeatenText
	msgbox MediumMarthaAfterBattleText, MSGBOX_AUTOCLOSE
	end

EcruteakCity_Gym_EventScript_Grace::
	trainerbattle_single TRAINER_GRACE MediumGraceSeenText, MediumGraceBeatenText
	msgbox MediumGraceAfterBattleText, MSGBOX_AUTOCLOSE
	end

EcruteakCity_Gym_EventScript_Morty::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_ECRUTEAK_CITY_GYM, EcruteakCity_Gym_EventScript_Morty_Defeated
	msgbox MortyIntroText, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_MORTY_1, MortyWinLossText
	message Text_ReceivedFogBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox MortyText_FogBadgeSpeech, MSGBOX_DEFAULT
	setflag FLAG_BADGE04_GET
	setflag FLAG_DEFEATED_ECRUTEAK_CITY_GYM
	addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 4
	call Common_EventScript_SetGymTrainers
	giveitem ITEM_TM_SHADOW_BALL
	msgbox MortyText_ShadowBallSpeech, MSGBOX_DEFAULT
	setvar VAR_ECRUTEAK_CITY_STATE, 4
	closemessage
	release
	end

EcruteakCity_Gym_EventScript_Morty_Defeated::
	msgbox MortyFightDoneText, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_Gym_EventScript_Statue::
	lock
	goto_if_set FLAG_DEFEATED_ECRUTEAK_CITY_GYM, EcruteakCity_Gym_EventScript_Statue2
	msgbox EcruteakCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_Gym_EventScript_Statue2::
	msgbox EcruteakCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_Gym_Text_GymStatue:
	.string "ECRUTEAK CITY POKéMON GYM$"

EcruteakCity_Gym_Text_GymStatueCertified:
	.string "ECRUTEAK CITY POKéMON GYM\p"
	.string "MORTY'S CERTIFIED TRAINERS:\n"
	.string "{PLAYER}$"

MortyIntroText:
	.string "Good of you to have come.\p"
	.string "Here in ECRUTEAK, POKéMON have\n"
	.string "always been revered.\p"
	.string "It's said that a rainbow-colored\n"
	.string "POKéMON will come down to\l"
	.string "appear before a true Trainer.\p"
	.string "I believed that tale, so I've\n"
	.string "trained here in secret.\p"
	.string "As a result, I can now see what\n"
	.string "others cannot.\p"
	.string "Just a bit more...\p"
	.string "With a little more, I could see\n"
	.string "a future where I meet the\l"
	.string "rainbow-colored POKéMON.\p"
	.string "You're going to help me reach\n"
	.string "that level!$"

MortyWinLossText:
	.string "I'm not good enough yet...\p"
	.string "All right. This BADGE is yours.$"

Text_ReceivedFogBadge:
	.string "{PLAYER} received the FOGBADGE.$"

MortyText_FogBadgeSpeech:
	.string "With the FOGBADGE, POKéMON up\n"
	.string "to Level 50 will obey you.\p"
	.string "Also, any POKéMON that knows\n"
	.string "SURF will be able to use it\l"
	.string "anytime.\p"
	.string "I want you to have this too.$"

MortyText_ShadowBallSpeech:
	.string "That's SHADOW BALL.\n"
	.string "It causes damage and may\l"
	.string "lower SP. DEF.\p"
	.string "Use it if it suits you.$"

MortyFightDoneText:
	.string "I see...\p"
	.string "Your journey has taken you to\n"
	.string "far-off places.\p"
	.string "You've witnessed more than I\n"
	.string "ever have.\p"
	.string "I envy you for that...$"

MortyRematchText:
	.string "Ah, the JOHTO CHAMPION!\n"
	.string "Good of you to come.\p"
	.string "You've shown strength and skill,\n"
	.string "but have you grown since we\l"
	.string "last battled?\p"
	.string "I've trained with my GHOST-type\n"
	.string "POKéMON ever since.\p"
	.string "Let's see if you can overcome\n"
	.string "the shadows again.\p"
	.string "Want to have a rematch?$"

Morty_RematchDefeatText:
	.string "I'm not good enough yet...\p"
	.string "You've witnessed more than I\n"
	.string "ever have.\p"
	.string "I envy you for that...$"

SageJeffreySeenText:
	.string "I spent the spring with my\n"
	.string "POKéMON.\p"
	.string "Then summer, fall, and winter...\p"
	.string "Then spring came again.\n"
	.string "We've been together a long time.$"

SageJeffreyBeatenText:
	.string "Wins and losses--I've known\n"
	.string "them both.$"

SageJeffreyAfterBattleText:
	.string "Where did POKéMON come from?$"

SagePingSeenText:
	.string "Can you inflict any damage\n"
	.string "on our POKéMON?$"

SagePingBeatenText:
	.string "Ah! Well done!$"

SagePingAfterBattleText:
	.string "We use GHOST-type POKéMON.\p"
	.string "No NORMAL-type attacks can\n"
	.string "harm them!$"

MediumMarthaSeenText:
	.string "I shall win!$"

MediumMarthaBeatenText:
	.string "I... I... I lost!$"

MediumMarthaAfterBattleText:
	.string "The one who wants to win the\n"
	.string "most is the one who will!$"

MediumGraceSeenText:
	.string "Stumped by our dark corridors?\n"
	.string "Defeat me if you want a hint!$"

MediumGraceBeatenText:
	.string "Wha-what?$"

MediumGraceAfterBattleText:
	.string "Fine. I'll tell you the secret\n"
	.string "of the shadows.\p"
	.string "The path is right in front of\n"
	.string "your eyes!$"

EcruteakCity_GymGuideText:
	.string "Hey CHAMP! You're almost\n"
	.string "halfway there!\p"
	.string "Trainers here use GHOST and\n"
	.string "DARK-type POKéMON.\p"
	.string "While MORTY is a GHOST-type\n"
	.string "expert, be wary of his mystic\l"
	.string "deer.\p"
	.string "It's said to cause strange\n"
	.string "nightmares...$"

EcruteakCity_GymGuideWinText:
	.string "Whew, {PLAYER}. You did great!\p"
	.string "I was cowering in the corner\n"
	.string "out of pure terror!$"

EcruteakCity_GymClosedText:
	.string "MORTY, the GYM LEADER, is\n"
	.string "absent.\p"
	.string "Sorry, but you'll have to\n"
	.string "leave.\p"
	.string "Hohohoho.$"
