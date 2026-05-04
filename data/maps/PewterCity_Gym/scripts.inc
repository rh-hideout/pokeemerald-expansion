PewterCity_Gym_MapScripts::
	.byte 0



PewterCity_Gym_EventScript_Jerry::
	trainerbattle_single TRAINER_JERRY, PewterCity_Gym_Text_CamperJerry_Seen, PewterCity_Gym_Text_CamperJerry_Beaten
	msgbox PewterCity_Gym_Text_CamperJerry_AfterBattle, MSGBOX_AUTOCLOSE
	end

PewterCity_Gym_EventScript_Brock::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_PEWTER_GYM, PewterCity_Gym_EventScript_Brock_Defeated
	msgbox PewterCity_Gym_Text_Brock_Intro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_BROCK, PewterCity_Gym_Text_Brock_WinLoss
	message PewterCity_Gym_Text_ReceivedBoulderBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox PewterCity_Gym_Text_Brock_FightDone, MSGBOX_DEFAULT
	giveitem ITEM_TM_EARTHQUAKE
	setflag FLAG_BADGE09_GET
	setflag FLAG_DEFEATED_PEWTER_GYM
	addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 9
	call Common_EventScript_SetGymTrainers
	clearflag FLAG_HIDE_DIGLETT_BROCK
	closemessage
	release
	end

PewterCity_Gym_EventScript_Brock_Defeated::
	msgbox PewterCity_Gym_Text_Brock_FightDone, MSGBOX_DEFAULT
	closemessage
	release
	end


PewterCity_Gym_Text_Brock_Intro:
	.string "BROCK: Wow, it's not often that we get a\n"
	.string "challenger from JOHTO.\p"
	.string "I'm BROCK, the PEWTER GYM LEADER.\p"
	.string "I'm an expert on ROCK-type POKéMON.\p"
	.string "My POKéMON are impervious to most\n"
	.string "physical attacks. You'll have a hard\l"
	.string "time inflicting any damage.\p"
	.string "Come on!$"

PewterCity_Gym_Text_Brock_WinLoss:
	.string "BROCK: Your POKéMON's powerful attacks\n"
	.string "overcame my rock-hard defense…\p"
	.string "You're stronger than I expected…\p"
	.string "Go ahead--take this BADGE.$"

PewterCity_Gym_Text_ReceivedBoulderBadge:
	.string "{PLAYER} received BOULDERBADGE.$"

PewterCity_Gym_Text_Brock_BoulderBadge:
	.string "BROCK: {PLAYER}, thanks. I enjoyed\n"
	.string "battling you, even though I am a bit\l"
	.string "upset.\p"
	.string "That BOULDERBADGE will make your\n"
	.string "POKéMON even more powerful.$"

PewterCity_Gym_Text_Brock_FightDone:
	.string "BROCK: The world is huge. There are\n"
	.string "still many strong trainers like you.\p"
	.string "Just wait and see. I'm going to become\n"
	.string "a lot stronger too.$"

PewterCity_Gym_Text_CamperJerry_Seen:
	.string "The trainers of this GYM use ROCK-type\n"
	.string "POKéMON.\p"
	.string "The ROCK-type has high DEFENSE.\p"
	.string "Battles could end up going a long time.\n"
	.string "Are you ready for this?$"

PewterCity_Gym_Text_CamperJerry_Beaten:
	.string "I have to win these battles…$"

PewterCity_Gym_Text_CamperJerry_AfterBattle:
	.string "Hey, you! Trainer from JOHTO! BROCK is\n"
	.string "tough. He'll punish you if you don't\l"
	.string "take him seriously.$"

PewterCity_Gym_Text_Guide:
	.string "Yo! CHAMP in making! You're really\n"
	.string "rocking.\p"
	.string "Are you battling the GYM LEADERS of\n"
	.string "KANTO?\p"
	.string "They're strong and dedicated people,\n"
	.string "just like JOHTO's GYM LEADERS.$"

PewterCity_Gym_Text_Guide_Win:
	.string "Yo! CHAMP in making! That GYM didn't\n"
	.string "give you much trouble.\p"
	.string "The way you took charge was really\n"
	.string "inspiring. I mean that seriously.$"

PewterCity_Gym_EventScript_GymGuy::
	goto_if_set FLAG_DEFEATED_PEWTER_GYM, PewterCity_Gym_EventScript_GymGuyAfter
	msgbox PewterCity_Gym_Text_Guide, MSGBOX_NPC
	end

PewterCity_Gym_EventScript_GymGuyAfter::
	msgbox PewterCity_Gym_Text_Guide_Win, MSGBOX_NPC
	end


PewterCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE09_GET, PewterCity_Gym_EventScript_GymStatuePostVictory
	msgbox PewterCity_Gym_Text_GymStatue
	releaseall
	end

PewterCity_Gym_EventScript_GymStatuePostVictory::
	msgbox PewterCity_Gym_Text_GymStatuePlayerWon
	releaseall
	end

PewterCity_Gym_Text_GymStatue::
    .string "PEWTER POKéMON GYM\n"
    .string "LEADER: BROCK\p"
	.string "WINNING TRAINERS:\n"
	.string "BLUE, RED$"

PewterCity_Gym_Text_GymStatuePlayerWon::
    .string "PEWTER POKéMON GYM\n"
    .string "LEADER: BROCK\p"
    .string "WINNING TRAINERS:\n"
	.string "BLUE, RED, {PLAYER}$"


