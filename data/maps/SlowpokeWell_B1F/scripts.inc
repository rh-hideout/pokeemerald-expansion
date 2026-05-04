.set LOCALID_WELL_KURT, 19

SlowpokeWell_B1F_MapScripts::
	.byte 0

SlowpokeWell_B1F_EventScript_Item_Super_Potion_1::
	finditem ITEM_SUPER_POTION
	end

SlowpokeWell_B1F_EventScript_Item_Super_Potion_2::
	finditem ITEM_SUPER_POTION
	end

SlowpokeWell_B1F_EventScript_Item_Great_Ball::
	finditem ITEM_GREAT_BALL
	end

SlowpokeWell_B1F_EventScript_Item_Full_Heal::
	finditem ITEM_FULL_HEAL
	end

SlowpokeWell_B1F_EventScript_Kurt::
	lock
	msgbox SlowpokeWell_B1F_Text_KurtIntro, MSGBOX_DEFAULT
	closemessage
	end

SlowpokeWell_B1F_EventScript_Grunt21::
	trainerbattle_single TRAINER_GRUNT_21, SlowpokeWell_B1F_Text_GruntM29Seen, SlowpokeWell_B1F_Text_GruntM29Beaten
	msgbox SlowpokeWell_B1F_Text_GruntM29After, MSGBOX_AUTOCLOSE
	end

SlowpokeWell_B1F_EventScript_Grunt22F::
	trainerbattle_single TRAINER_GRUNT_22, SlowpokeWell_B1F_Text_GruntF1Seen, SlowpokeWell_B1F_Text_GruntF1Beaten
	msgbox SlowpokeWell_B1F_Text_GruntF1After, MSGBOX_AUTOCLOSE
	end

SlowpokeWell_B1F_EventScript_Eto::
	trainerbattle_single TRAINER_ETO, SlowpokeWell_B1F_Text_GruntM2Seen, SlowpokeWell_B1F_Text_GruntM2Beaten
	msgbox SlowpokeWell_B1F_Text_GruntM2After, MSGBOX_AUTOCLOSE
	end

SlowpokeWell_B1F_EventScript_Proton::
	lock
	faceplayer
	msgbox SlowpokeWell_B1F_Text_ProtonSeen, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_PROTON_1, SlowpokeWell_B1F_Text_ProtonBeaten
	msgbox SlowpokeWell_B1F_Text_ProtonAfter, MSGBOX_AUTOCLOSE
	closemessage
	fadescreen FADE_TO_BLACK
	setflag FLAG_HIDE_AZALEA_TOWN_ROCKETS
	clearflag FLAG_HIDE_KURT_1
	addobject LOCALID_WELL_KURT
	removeobject 11
	removeobject 12
	removeobject 13
	delay 120
	fadescreen FADE_FROM_BLACK
	special DrawWholeMapView
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	applymovement LOCALID_WELL_KURT, SlowpokeWell_B1F_Movement_Kurt
	waitmovement 0
	msgbox SlowpokeWell_B1F_Text_KurtAfter, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	setflag FLAG_HIDE_SLOWPOKE_WELL_KURT
	setflag FLAG_HIDE_KURT_1
	clearflag FLAG_HIDE_KURT_2
	clearflag FLAG_HIDE_AZALEA_TOWN_SLOWPOKE
	setvar VAR_AZALEA_TOWN_STATE, 3
	warp MAP_AZALEA_TOWN_KURTS_HOUSE, 15, 4
	release
	end

SlowpokeWell_B1F_Movement_Kurt:
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	step_end

SlowpokeWell_B1F_Text_KurtIntro:
	.string "KURT: Hey there, {PLAYER}!\p"
	.string "The guard up top took off when\n"
	.string "I shouted at him.\p"
	.string "But then I took a tumble down\n"
	.string "the WELL.\p"
	.string "I slammed down hard on my back,\n"
	.string "so I can't move.\p"
	.string "Rats! If I were fit, my POKéMON\n"
	.string "would've punished them…\p"
	.string "Ah, it can't be helped.\p"
	.string "{PLAYER}, show them how gutsy\n"
	.string "you are in my place!$"

SlowpokeWell_B1F_Text_KurtAfter:
	.string "KURT: Way to go, {PLAYER}!\p"
	.string "TEAM ROCKET has taken off.\p"
	.string "My back's better too.\n"
	.string "Let's get out of here.$"

SlowpokeWell_B1F_Text_GruntM29Seen:
	.string "Darn! I was standing guard up\n"
	.string "top when some old coot yelled\l"
	.string "at me.\p"
	.string "He startled me so much that\n"
	.string "I fell down here.\p"
	.string "I think I'll vent my anger by\n"
	.string "taking it out on you!$"

SlowpokeWell_B1F_Text_GruntM29Beaten:
	.string "Arrgh! This is NOT my day!$"

SlowpokeWell_B1F_Text_GruntM29After:
	.string "Sure, we've been hacking the\n"
	.string "tails off SLOWPOKE and selling\l"
	.string "them.\p"
	.string "Everything we do is for profit.\p"
	.string "That's right! We're TEAM ROCKET,\n"
	.string "and we'll do anything for money!$"

SlowpokeWell_B1F_Text_ProtonSeen:
	.string "What do you want?\p"
	.string "If you interrupt our work,\n"
	.string "don't expect any mercy!$"

SlowpokeWell_B1F_Text_ProtonBeaten:
	.string "You did OK today,\n"
	.string "but wait till next time!$"

SlowpokeWell_B1F_Text_ProtonAfter:
	.string "Yeah, TEAM ROCKET was broken up\n"
	.string "three years ago.\p"
	.string "The boss went into hiding.\p"
	.string "But we continued our activities\n"
	.string "underground!\p"
	.string "A small obstacle like you won't be\n"
	.string "much of a problem for our mission.\p"
	.string "I advise you to be very afraid of\n"
	.string "what is to come!$"

SlowpokeWell_B1F_Text_GruntM2Seen:
	.string "Hyuck-hyuck-hyuck!\n"
	.string "Quit taking SLOWPOKETAILS?\p"
	.string "You're nuts!\n"
	.string "If we obeyed you, TEAM ROCKET's\l"
	.string "rep would be ruined!$"

SlowpokeWell_B1F_Text_GruntM2Beaten:
	.string "Hyuck…\n"
	.string "Too strong…$"

SlowpokeWell_B1F_Text_GruntM2After:
	.string "We need the money,\n"
	.string "but selling SLOWPOKETAILS?\p"
	.string "It's tough being a ROCKET GRUNT!$"

SlowpokeWell_B1F_Text_GruntF1Seen:
	.string "Stop taking TAILS?\p"
	.string "Yeah, just try to defeat all\n"
	.string "of us!$"

SlowpokeWell_B1F_Text_GruntF1Beaten:
	.string "You rotten brat!$"

SlowpokeWell_B1F_Text_GruntF1After:
	.string "SLOWPOKETAILS grow back fast!\p"
	.string "What's wrong with selling them?$"

SlowpokeWell_B1F_Text_SlowpokeWithMail:
	.string "A SLOWPOKE with its TAIL cut off…\p"
	.string "Huh? It has MAIL.\n"
	.string "Read it?$"

SlowpokeWell_B1F_Text_SlowpokeMail:
	.string "{PLAYER} read the MAIL.\p"
	.string "Be good and look after the\n"
	.string "house with Grandpa and SLOWPOKE.\p"
	.string "Love, Dad$"

SlowpokeWell_B1F_Text_TaillessSlowpoke:
	.string "A SLOWPOKE with its TAIL cut off…$"
