# 1 "data/maps/RustboroCity_Gym/scripts.pory"

# 2 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_MapScripts::
# 3 "data/maps/RustboroCity_Gym/scripts.pory"
	.byte 0
# 4 "data/maps/RustboroCity_Gym/scripts.pory"

# 5 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_EventScript_Roxanne::
# 6 "data/maps/RustboroCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_ROXANNE_1, RustboroCity_Gym_Text_RoxanneIntro, RustboroCity_Gym_Text_RoxanneDefeat, RustboroCity_Gym_EventScript_RoxanneDefeated, NO_MUSIC
# 7 "data/maps/RustboroCity_Gym/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 8 "data/maps/RustboroCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_Gym_EventScript_RoxanneRematch
# 9 "data/maps/RustboroCity_Gym/scripts.pory"
	goto_if_unset FLAG_RECEIVED_TM_ROCK_TOMB, RustboroCity_Gym_EventScript_GiveRockTomb
# 10 "data/maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_Text_RoxannePostBattle, MSGBOX_DEFAULT
# 11 "data/maps/RustboroCity_Gym/scripts.pory"
	release
# 12 "data/maps/RustboroCity_Gym/scripts.pory"
	end
# 13 "data/maps/RustboroCity_Gym/scripts.pory"

# 14 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_EventScript_RoxanneDefeated::
# 15 "data/maps/RustboroCity_Gym/scripts.pory"
	message RustboroCity_Gym_Text_ReceivedStoneBadge
# 16 "data/maps/RustboroCity_Gym/scripts.pory"
	waitmessage
# 17 "data/maps/RustboroCity_Gym/scripts.pory"
	call Common_EventScript_PlayGymBadgeFanfare
# 18 "data/maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_Text_StoneBadgeInfoTakeThis, MSGBOX_DEFAULT
# 19 "data/maps/RustboroCity_Gym/scripts.pory"
	setflag FLAG_DEFEATED_RUSTBORO_GYM
# 20 "data/maps/RustboroCity_Gym/scripts.pory"
	setflag FLAG_BADGE01_GET
# 21 "data/maps/RustboroCity_Gym/scripts.pory"
	setvar VAR_RUSTBORO_CITY_STATE, 1
# 22 "data/maps/RustboroCity_Gym/scripts.pory"
	addvar VAR_PETALBURG_GYM_STATE, 1
# 23 "data/maps/RustboroCity_Gym/scripts.pory"
	setvar VAR_0x8008, 1
# 24 "data/maps/RustboroCity_Gym/scripts.pory"
	call Common_EventScript_SetGymTrainers
# 25 "data/maps/RustboroCity_Gym/scripts.pory"
	call_if_eq VAR_PETALBURG_GYM_STATE, 6, Common_EventScript_ReadyPetalburgGymForBattle
# 26 "data/maps/RustboroCity_Gym/scripts.pory"
	goto RustboroCity_Gym_EventScript_GiveRockTomb
# 27 "data/maps/RustboroCity_Gym/scripts.pory"
	end
# 28 "data/maps/RustboroCity_Gym/scripts.pory"

# 29 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_EventScript_GiveRockTomb::
# 30 "data/maps/RustboroCity_Gym/scripts.pory"
	giveitem ITEM_TM_ROCK_TOMB
# 31 "data/maps/RustboroCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 32 "data/maps/RustboroCity_Gym/scripts.pory"
	setflag FLAG_RECEIVED_TM_ROCK_TOMB
# 33 "data/maps/RustboroCity_Gym/scripts.pory"
    msgbox RustboroCity_Gym_Text_ExplainRockTomb, MSGBOX_DEFAULT
# 34 "data/maps/RustboroCity_Gym/scripts.pory"
    giveitem ITEM_TM_TAKE_DOWN
# 35 "data/maps/RustboroCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 36 "data/maps/RustboroCity_Gym/scripts.pory"
    msgbox RustboroCity_Gym_Text_ExplainTakeDown, MSGBOX_DEFAULT
# 37 "data/maps/RustboroCity_Gym/scripts.pory"
	release
# 38 "data/maps/RustboroCity_Gym/scripts.pory"
	end
# 39 "data/maps/RustboroCity_Gym/scripts.pory"

# 40 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_EventScript_RoxanneRematch::
# 41 "data/maps/RustboroCity_Gym/scripts.pory"
	trainerbattle_rematch_double TRAINER_ROXANNE_1, RustboroCity_Gym_Text_RoxannePreRematch, RustboroCity_Gym_Text_RoxanneRematchDefeat, RustboroCity_Gym_Text_RoxanneRematchNeedTwoMons
# 42 "data/maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_Text_RoxannePostRematch, MSGBOX_AUTOCLOSE
# 43 "data/maps/RustboroCity_Gym/scripts.pory"
	end
# 44 "data/maps/RustboroCity_Gym/scripts.pory"

# 45 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_EventScript_Josh::
# 46 "data/maps/RustboroCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_JOSH, RustboroCity_Gym_Text_JoshIntro, RustboroCity_Gym_Text_JoshDefeat
# 47 "data/maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_Text_JoshPostBattle, MSGBOX_AUTOCLOSE
# 48 "data/maps/RustboroCity_Gym/scripts.pory"
	end
# 49 "data/maps/RustboroCity_Gym/scripts.pory"

# 50 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_EventScript_Tommy::
# 51 "data/maps/RustboroCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_TOMMY, RustboroCity_Gym_Text_TommyIntro, RustboroCity_Gym_Text_TommyDefeat
# 52 "data/maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_Text_TommyPostBattle, MSGBOX_AUTOCLOSE
# 53 "data/maps/RustboroCity_Gym/scripts.pory"
	end
# 54 "data/maps/RustboroCity_Gym/scripts.pory"

# 55 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_EventScript_Marc::
# 56 "data/maps/RustboroCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_MARC, RustboroCity_Gym_Text_MarcIntro, RustboroCity_Gym_Text_MarcDefeat
# 57 "data/maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_Text_MarcPostBattle, MSGBOX_AUTOCLOSE
# 58 "data/maps/RustboroCity_Gym/scripts.pory"
	end
# 59 "data/maps/RustboroCity_Gym/scripts.pory"

# 60 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_EventScript_GymGuide::
# 61 "data/maps/RustboroCity_Gym/scripts.pory"
	lock
# 62 "data/maps/RustboroCity_Gym/scripts.pory"
	faceplayer
# 63 "data/maps/RustboroCity_Gym/scripts.pory"
	goto_if_set FLAG_DEFEATED_RUSTBORO_GYM, RustboroCity_Gym_EventScript_GymGuidePostVictory
# 64 "data/maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
# 65 "data/maps/RustboroCity_Gym/scripts.pory"
	release
# 66 "data/maps/RustboroCity_Gym/scripts.pory"
	end
# 67 "data/maps/RustboroCity_Gym/scripts.pory"

# 68 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_EventScript_GymGuidePostVictory::
# 69 "data/maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
# 70 "data/maps/RustboroCity_Gym/scripts.pory"
	release
# 71 "data/maps/RustboroCity_Gym/scripts.pory"
	end
# 72 "data/maps/RustboroCity_Gym/scripts.pory"

# 73 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_EventScript_LeftGymStatue::
# 74 "data/maps/RustboroCity_Gym/scripts.pory"
	lockall
# 75 "data/maps/RustboroCity_Gym/scripts.pory"
	goto_if_set FLAG_BADGE01_GET, RustboroCity_Gym_EventScript_GymStatueCertified
# 76 "data/maps/RustboroCity_Gym/scripts.pory"
	goto RustboroCity_Gym_EventScript_GymStatue
# 77 "data/maps/RustboroCity_Gym/scripts.pory"
	end
# 78 "data/maps/RustboroCity_Gym/scripts.pory"

# 79 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_EventScript_RightGymStatue::
# 80 "data/maps/RustboroCity_Gym/scripts.pory"
	lockall
# 81 "data/maps/RustboroCity_Gym/scripts.pory"
	goto_if_set FLAG_BADGE01_GET, RustboroCity_Gym_EventScript_GymStatueCertified
# 82 "data/maps/RustboroCity_Gym/scripts.pory"
	goto RustboroCity_Gym_EventScript_GymStatue
# 83 "data/maps/RustboroCity_Gym/scripts.pory"
	end
# 84 "data/maps/RustboroCity_Gym/scripts.pory"

# 85 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_EventScript_GymStatueCertified::
# 86 "data/maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
# 87 "data/maps/RustboroCity_Gym/scripts.pory"
	releaseall
# 88 "data/maps/RustboroCity_Gym/scripts.pory"
	end
# 89 "data/maps/RustboroCity_Gym/scripts.pory"

# 90 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_EventScript_GymStatue::
# 91 "data/maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
# 92 "data/maps/RustboroCity_Gym/scripts.pory"
	releaseall
# 93 "data/maps/RustboroCity_Gym/scripts.pory"
	end
# 94 "data/maps/RustboroCity_Gym/scripts.pory"

# 95 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_EventScript_RegisterRoxanne::
# 96 "data/maps/RustboroCity_Gym/scripts.pory"
	lockall
# 97 "data/maps/RustboroCity_Gym/scripts.pory"
	pokenavcall RustboroCity_Gym_Text_RoxanneRegisterCall
# 98 "data/maps/RustboroCity_Gym/scripts.pory"
	waitmessage
# 99 "data/maps/RustboroCity_Gym/scripts.pory"
	delay 30
# 100 "data/maps/RustboroCity_Gym/scripts.pory"
	playfanfare MUS_REGISTER_MATCH_CALL
# 101 "data/maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_Text_RegisteredRoxanne, MSGBOX_DEFAULT
# 102 "data/maps/RustboroCity_Gym/scripts.pory"
	waitfanfare
# 103 "data/maps/RustboroCity_Gym/scripts.pory"
	closemessage
# 104 "data/maps/RustboroCity_Gym/scripts.pory"
	delay 30
# 105 "data/maps/RustboroCity_Gym/scripts.pory"
	setflag FLAG_ENABLE_ROXANNE_MATCH_CALL
# 106 "data/maps/RustboroCity_Gym/scripts.pory"
	clearflag FLAG_ENABLE_ROXANNE_FIRST_CALL
# 107 "data/maps/RustboroCity_Gym/scripts.pory"
	releaseall
# 108 "data/maps/RustboroCity_Gym/scripts.pory"
	end
# 109 "data/maps/RustboroCity_Gym/scripts.pory"

# 110 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_GymGuideAdvice:
# 111 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Yo, how's it going?\p"
# 112 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Listen, my friend!\n"
# 113 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Would you like to become the CHAMPION?\p"
# 114 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "I'm no TRAINER, not me, but I can\n"
# 115 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "sure give you winning advice.\p"
# 116 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "That's settled, then! We'll aim for the\n"
# 117 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "POKéMON CHAMPIONSHIP together!\p"
# 118 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "It's your job as a TRAINER to collect\n"
# 119 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "GYM BADGES, am I right?\p"
# 120 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "But GYM LEADERS aren't pushovers!\p"
# 121 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "And that's where I come in!\n"
# 122 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "I'm here to provide expert advice!\p"
# 123 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "ROXANNE, the GYM LEADER, is a user\n"
# 124 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "of ROCK-type POKéMON.\p"
# 125 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "The ROCK type is very durable, but\n"
# 126 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "it can't stand WATER-type and\l"
# 127 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "GRASS-type moves.\p"
# 128 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Come see me afterwards, if you beat\n"
# 129 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "the GYM LEADER.\p"
# 130 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Well, go for it!$"
# 131 "data/maps/RustboroCity_Gym/scripts.pory"

# 132 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_GymGuidePostVictory:
# 133 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Whoa! What a breathtaking victory!\n"
# 134 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "My cheering must've worked!\p"
# 135 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Great!\n"
# 136 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Check your TRAINER CARD.\p"
# 137 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "The STONE BADGE you got should be\n"
# 138 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "properly recorded on it.\p"
# 139 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "In other words…\p"
# 140 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "You've climbed the first step on\n"
# 141 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "the stairs to the CHAMPIONSHIP!\p"
# 142 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "That's got to feel awesome!$"
# 143 "data/maps/RustboroCity_Gym/scripts.pory"

# 144 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_JoshIntro:
# 145 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Don't take us GYM TRAINERS lightly!\n"
# 146 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "I'll show you why we're better!$"
# 147 "data/maps/RustboroCity_Gym/scripts.pory"

# 148 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_JoshDefeat:
# 149 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "You were too good for me…$"
# 150 "data/maps/RustboroCity_Gym/scripts.pory"

# 151 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_JoshPostBattle:
# 152 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "You haven't seen anything of the ROCK\n"
# 153 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "type's terrifying power!$"
# 154 "data/maps/RustboroCity_Gym/scripts.pory"

# 155 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_TommyIntro:
# 156 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "If you can't beat me, you won't stand\n"
# 157 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "a chance against ROXANNE!$"
# 158 "data/maps/RustboroCity_Gym/scripts.pory"

# 159 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_TommyDefeat:
# 160 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Wow! You've got some potential!$"
# 161 "data/maps/RustboroCity_Gym/scripts.pory"

# 162 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_TommyPostBattle:
# 163 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "ROXANNE is stronger than me by\n"
# 164 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "several times.\p"
# 165 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "You'd better be on your guard!$"
# 166 "data/maps/RustboroCity_Gym/scripts.pory"

# 167 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_MarcIntro:
# 168 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "We might be in the middle of town,\n"
# 169 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "but so what?\p"
# 170 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "My ROCK POKéMON need room to\n"
# 171 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "rampage!$"
# 172 "data/maps/RustboroCity_Gym/scripts.pory"

# 173 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_MarcDefeat:
# 174 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Oh, man oh man!\n"
# 175 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Our challenger is one feisty customer!$"
# 176 "data/maps/RustboroCity_Gym/scripts.pory"

# 177 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_MarcPostBattle:
# 178 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "I have to hand it to our LEADER.\p"
# 179 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "It took smarts and sense for her to\n"
# 180 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "pick the ROCK type at her young age.$"
# 181 "data/maps/RustboroCity_Gym/scripts.pory"

# 182 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_RoxanneIntro:
# 183 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Hello, I am ROXANNE, the RUSTBORO\n"
# 184 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "POKéMON GYM LEADER.\p"
# 185 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "I became a GYM LEADER so that I might\n"
# 186 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "apply what I learned at the POKéMON\l"
# 187 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "TRAINER'S SCHOOL in battle.\p"
# 188 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Would you kindly demonstrate how you\n"
# 189 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "battle, and with which POKéMON?$"
# 190 "data/maps/RustboroCity_Gym/scripts.pory"

# 191 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_RoxanneDefeat:
# 192 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "So…\n"
# 193 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "I lost…\p"
# 194 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "It seems that I still have much more\n"
# 195 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "to learn…\p"
# 196 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "I understand.\p"
# 197 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "The POKéMON LEAGUE's rules state\n"
# 198 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "that TRAINERS are to be given this\l"
# 199 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "if they defeat a GYM LEADER.\p"
# 200 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Please accept the official POKéMON\n"
# 201 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "LEAGUE STONE BADGE.$"
# 202 "data/maps/RustboroCity_Gym/scripts.pory"

# 203 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_ReceivedStoneBadge:
# 204 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "{PLAYER} received the STONE BADGE\n"
# 205 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "from ROXANNE.$"
# 206 "data/maps/RustboroCity_Gym/scripts.pory"

# 207 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_StoneBadgeInfoTakeThis:
# 208 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "The STONE BADGE raises the level cap\n"
# 209 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "of your POKéMON to 17.\p"
# 210 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "It also enables them to use the HM move\n"
# 211 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "CUT outside of battle.\p"
# 212 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Please take this with you, too.$"
# 213 "data/maps/RustboroCity_Gym/scripts.pory"

# 214 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_ExplainRockTomb:
# 215 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "That TECHNICAL MACHINE, TM39,\n"
# 216 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "contains ROCK TOMB.\p"
# 217 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "It not only inflicts damage by dropping\n"
# 218 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "rocks, it also lowers SPEED.$"
# 219 "data/maps/RustboroCity_Gym/scripts.pory"

# 220 "data/maps/RustboroCity_Gym/scripts.pory"

# 221 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_ExplainTakeDown:
# 222 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "That TECHNICAL MACHINE, TM52,\n"
# 223 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "contains TAKE DOWN.\p"
# 224 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "It's a strong move but can\n"
# 225 "data/maps/RustboroCity_Gym/scripts.pory"
    .string "cause significant recoil,\l"
# 226 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "so think before you use it.$"
# 227 "data/maps/RustboroCity_Gym/scripts.pory"

# 228 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_RoxannePostBattle:
# 229 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Since you are so strong, you should\n"
# 230 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "challenge other GYM LEADERS.\p"
# 231 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "By battling many TRAINERS, you should\n"
# 232 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "learn many things.$"
# 233 "data/maps/RustboroCity_Gym/scripts.pory"

# 234 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_GymStatue:
# 235 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "RUSTBORO CITY POKéMON GYM$"
# 236 "data/maps/RustboroCity_Gym/scripts.pory"

# 237 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_GymStatueCertified:
# 238 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "RUSTBORO CITY POKéMON GYM\p"
# 239 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "ROXANNE'S CERTIFIED TRAINERS:\n"
# 240 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "{PLAYER}$"
# 241 "data/maps/RustboroCity_Gym/scripts.pory"

# 242 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_RoxanneRegisterCall:
# 243 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "… … … … … …\n"
# 244 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "… … … … … Beep!\p"
# 245 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "ROXANNE: Oh, hello, {PLAYER}?\n"
# 246 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "This is ROXANNE of RUSTBORO CITY.\p"
# 247 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "I heard from BRAWLY that you're\n"
# 248 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "moving up through the ranks of\l"
# 249 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "TRAINERS at an incredible clip.\p"
# 250 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Well, I'd rather not think that\n"
# 251 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "I can't beat you.\p"
# 252 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "I promise, I will shape up my GYM\n"
# 253 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "so that you may challenge us again.\p"
# 254 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "I hope you'll be looking forward to\n"
# 255 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "that occasion as much as me!\p"
# 256 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "… … … … … …\n"
# 257 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "… … … … … Click!$"
# 258 "data/maps/RustboroCity_Gym/scripts.pory"

# 259 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_RegisteredRoxanne:
# 260 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Registered GYM LEADER ROXANNE\n"
# 261 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "in the POKéNAV.$"
# 262 "data/maps/RustboroCity_Gym/scripts.pory"

# 263 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_RoxannePreRematch:
# 264 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "ROXANNE: I'm so glad to see you again.\n"
# 265 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "I'm ROXANNE, the GYM LEADER here.\p"
# 266 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "I'm sure we've both experienced many\n"
# 267 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "battles since we last met.\p"
# 268 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "I would like to see how much better\n"
# 269 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "we've become. Let us battle!$"
# 270 "data/maps/RustboroCity_Gym/scripts.pory"

# 271 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_RoxanneRematchDefeat:
# 272 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Grr…\n"
# 273 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Again, I have lost…$"
# 274 "data/maps/RustboroCity_Gym/scripts.pory"

# 275 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_RoxannePostRematch:
# 276 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "ROXANNE: I still have much to learn\n"
# 277 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "when it comes to battling POKéMON.\p"
# 278 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "That awareness makes me love battling\n"
# 279 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "all that much more!$"
# 280 "data/maps/RustboroCity_Gym/scripts.pory"

# 281 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_RoxanneRematchNeedTwoMons:
# 282 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "ROXANNE: I'm so glad to see you again.\n"
# 283 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "I'm ROXANNE, the GYM LEADER here.\p"
# 284 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "I'm sure we've both experienced many\n"
# 285 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "battles since we last met.\p"
# 286 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "I would like to see how much better\n"
# 287 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "we've become…\p"
# 288 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Oh, no…\n"
# 289 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "You only have one POKéMON with you?\p"
# 290 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Please return with at least one more\n"
# 291 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "POKéMON.$"

RustboroCity_Gym_EventScript_Raticate::
# 296 "data/maps/RustboroCity_Gym/scripts.pory"
	applymovement 6, RustboroCity_Gym_EventScript_Raticate_Movement_0
# 297 "data/maps/RustboroCity_Gym/scripts.pory"
	lock
# 298 "data/maps/RustboroCity_Gym/scripts.pory"
	playmoncry SPECIES_RATICATE, CRY_MODE_ENCOUNTER
# 299 "data/maps/RustboroCity_Gym/scripts.pory"
	waitmoncry
# 300 "data/maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_EventScript_Raticate_Text_0, MSGBOX_DEFAULT
# 301 "data/maps/RustboroCity_Gym/scripts.pory"
	turnobject 6, DIR_SOUTH
# 302 "data/maps/RustboroCity_Gym/scripts.pory"
	applymovement 6, RustboroCity_Gym_EventScript_Raticate_Movement_1
# 303 "data/maps/RustboroCity_Gym/scripts.pory"
	release
	end


RustboroCity_Gym_EventScript_Anorith::
# 309 "data/maps/RustboroCity_Gym/scripts.pory"
	applymovement 7, RustboroCity_Gym_EventScript_Raticate_Movement_0
# 310 "data/maps/RustboroCity_Gym/scripts.pory"
	lock
# 311 "data/maps/RustboroCity_Gym/scripts.pory"
	playmoncry SPECIES_ANORITH, CRY_MODE_ENCOUNTER
# 312 "data/maps/RustboroCity_Gym/scripts.pory"
	waitmoncry
# 313 "data/maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_EventScript_Anorith_Text_0, MSGBOX_DEFAULT
# 314 "data/maps/RustboroCity_Gym/scripts.pory"
	turnobject 7, DIR_SOUTH
# 315 "data/maps/RustboroCity_Gym/scripts.pory"
	applymovement 7, RustboroCity_Gym_EventScript_Raticate_Movement_1
# 316 "data/maps/RustboroCity_Gym/scripts.pory"
	release
	end


# 296 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_EventScript_Raticate_Movement_0:
# 296 "data/maps/RustboroCity_Gym/scripts.pory"
	face_player
	step_end

# 302 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_EventScript_Raticate_Movement_1:
# 302 "data/maps/RustboroCity_Gym/scripts.pory"
	walk_in_place_down
	step_end

RustboroCity_Gym_EventScript_Raticate_Text_0:
# 300 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Raticate is bearing its fangs at you.\n"
	.string "Its fur does have a nice sheen, though.$"

RustboroCity_Gym_EventScript_Anorith_Text_0:
# 313 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Anorith chitters and looks around for\n"
	.string "berries. Nasty.$"
