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
	release
# 35 "data/maps/RustboroCity_Gym/scripts.pory"
	end
# 36 "data/maps/RustboroCity_Gym/scripts.pory"

# 37 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_EventScript_RoxanneRematch::
# 38 "data/maps/RustboroCity_Gym/scripts.pory"
	trainerbattle_rematch_double TRAINER_ROXANNE_1, RustboroCity_Gym_Text_RoxannePreRematch, RustboroCity_Gym_Text_RoxanneRematchDefeat, RustboroCity_Gym_Text_RoxanneRematchNeedTwoMons
# 39 "data/maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_Text_RoxannePostRematch, MSGBOX_AUTOCLOSE
# 40 "data/maps/RustboroCity_Gym/scripts.pory"
	end
# 41 "data/maps/RustboroCity_Gym/scripts.pory"

# 42 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_EventScript_Josh::
# 43 "data/maps/RustboroCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_JOSH, RustboroCity_Gym_Text_JoshIntro, RustboroCity_Gym_Text_JoshDefeat
# 44 "data/maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_Text_JoshPostBattle, MSGBOX_AUTOCLOSE
# 45 "data/maps/RustboroCity_Gym/scripts.pory"
	end
# 46 "data/maps/RustboroCity_Gym/scripts.pory"

# 47 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_EventScript_Tommy::
# 48 "data/maps/RustboroCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_TOMMY, RustboroCity_Gym_Text_TommyIntro, RustboroCity_Gym_Text_TommyDefeat
# 49 "data/maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_Text_TommyPostBattle, MSGBOX_AUTOCLOSE
# 50 "data/maps/RustboroCity_Gym/scripts.pory"
	end
# 51 "data/maps/RustboroCity_Gym/scripts.pory"

# 52 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_EventScript_Marc::
# 53 "data/maps/RustboroCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_MARC, RustboroCity_Gym_Text_MarcIntro, RustboroCity_Gym_Text_MarcDefeat
# 54 "data/maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_Text_MarcPostBattle, MSGBOX_AUTOCLOSE
# 55 "data/maps/RustboroCity_Gym/scripts.pory"
	end
# 56 "data/maps/RustboroCity_Gym/scripts.pory"

# 57 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_EventScript_GymGuide::
# 58 "data/maps/RustboroCity_Gym/scripts.pory"
	lock
# 59 "data/maps/RustboroCity_Gym/scripts.pory"
	faceplayer
# 60 "data/maps/RustboroCity_Gym/scripts.pory"
	goto_if_set FLAG_DEFEATED_RUSTBORO_GYM, RustboroCity_Gym_EventScript_GymGuidePostVictory
# 61 "data/maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
# 62 "data/maps/RustboroCity_Gym/scripts.pory"
	release
# 63 "data/maps/RustboroCity_Gym/scripts.pory"
	end
# 64 "data/maps/RustboroCity_Gym/scripts.pory"

# 65 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_EventScript_GymGuidePostVictory::
# 66 "data/maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
# 67 "data/maps/RustboroCity_Gym/scripts.pory"
	release
# 68 "data/maps/RustboroCity_Gym/scripts.pory"
	end
# 69 "data/maps/RustboroCity_Gym/scripts.pory"

# 70 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_EventScript_LeftGymStatue::
# 71 "data/maps/RustboroCity_Gym/scripts.pory"
	lockall
# 72 "data/maps/RustboroCity_Gym/scripts.pory"
	goto_if_set FLAG_BADGE01_GET, RustboroCity_Gym_EventScript_GymStatueCertified
# 73 "data/maps/RustboroCity_Gym/scripts.pory"
	goto RustboroCity_Gym_EventScript_GymStatue
# 74 "data/maps/RustboroCity_Gym/scripts.pory"
	end
# 75 "data/maps/RustboroCity_Gym/scripts.pory"

# 76 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_EventScript_RightGymStatue::
# 77 "data/maps/RustboroCity_Gym/scripts.pory"
	lockall
# 78 "data/maps/RustboroCity_Gym/scripts.pory"
	goto_if_set FLAG_BADGE01_GET, RustboroCity_Gym_EventScript_GymStatueCertified
# 79 "data/maps/RustboroCity_Gym/scripts.pory"
	goto RustboroCity_Gym_EventScript_GymStatue
# 80 "data/maps/RustboroCity_Gym/scripts.pory"
	end
# 81 "data/maps/RustboroCity_Gym/scripts.pory"

# 82 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_EventScript_GymStatueCertified::
# 83 "data/maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
# 84 "data/maps/RustboroCity_Gym/scripts.pory"
	releaseall
# 85 "data/maps/RustboroCity_Gym/scripts.pory"
	end
# 86 "data/maps/RustboroCity_Gym/scripts.pory"

# 87 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_EventScript_GymStatue::
# 88 "data/maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
# 89 "data/maps/RustboroCity_Gym/scripts.pory"
	releaseall
# 90 "data/maps/RustboroCity_Gym/scripts.pory"
	end
# 91 "data/maps/RustboroCity_Gym/scripts.pory"

# 92 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_EventScript_RegisterRoxanne::
# 93 "data/maps/RustboroCity_Gym/scripts.pory"
	lockall
# 94 "data/maps/RustboroCity_Gym/scripts.pory"
	pokenavcall RustboroCity_Gym_Text_RoxanneRegisterCall
# 95 "data/maps/RustboroCity_Gym/scripts.pory"
	waitmessage
# 96 "data/maps/RustboroCity_Gym/scripts.pory"
	delay 30
# 97 "data/maps/RustboroCity_Gym/scripts.pory"
	playfanfare MUS_REGISTER_MATCH_CALL
# 98 "data/maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_Text_RegisteredRoxanne, MSGBOX_DEFAULT
# 99 "data/maps/RustboroCity_Gym/scripts.pory"
	waitfanfare
# 100 "data/maps/RustboroCity_Gym/scripts.pory"
	closemessage
# 101 "data/maps/RustboroCity_Gym/scripts.pory"
	delay 30
# 102 "data/maps/RustboroCity_Gym/scripts.pory"
	setflag FLAG_ENABLE_ROXANNE_MATCH_CALL
# 103 "data/maps/RustboroCity_Gym/scripts.pory"
	clearflag FLAG_ENABLE_ROXANNE_FIRST_CALL
# 104 "data/maps/RustboroCity_Gym/scripts.pory"
	releaseall
# 105 "data/maps/RustboroCity_Gym/scripts.pory"
	end
# 106 "data/maps/RustboroCity_Gym/scripts.pory"

# 107 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_GymGuideAdvice:
# 108 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Yo, how's it going?\p"
# 109 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Listen, my friend!\n"
# 110 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Would you like to become the CHAMPION?\p"
# 111 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "I'm no TRAINER, not me, but I can\n"
# 112 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "sure give you winning advice.\p"
# 113 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "That's settled, then! We'll aim for the\n"
# 114 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "POKéMON CHAMPIONSHIP together!\p"
# 115 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "It's your job as a TRAINER to collect\n"
# 116 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "GYM BADGES, am I right?\p"
# 117 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "But GYM LEADERS aren't pushovers!\p"
# 118 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "And that's where I come in!\n"
# 119 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "I'm here to provide expert advice!\p"
# 120 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "ROXANNE, the GYM LEADER, is a user\n"
# 121 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "of ROCK-type POKéMON.\p"
# 122 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "The ROCK type is very durable, but\n"
# 123 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "it can't stand WATER-type and\l"
# 124 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "GRASS-type moves.\p"
# 125 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Come see me afterwards, if you beat\n"
# 126 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "the GYM LEADER.\p"
# 127 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Well, go for it!$"
# 128 "data/maps/RustboroCity_Gym/scripts.pory"

# 129 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_GymGuidePostVictory:
# 130 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Whoa! What a breathtaking victory!\n"
# 131 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "My cheering must've worked!\p"
# 132 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Great!\n"
# 133 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Check your TRAINER CARD.\p"
# 134 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "The STONE BADGE you got should be\n"
# 135 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "properly recorded on it.\p"
# 136 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "In other words…\p"
# 137 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "You've climbed the first step on\n"
# 138 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "the stairs to the CHAMPIONSHIP!\p"
# 139 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "That's got to feel awesome!$"
# 140 "data/maps/RustboroCity_Gym/scripts.pory"

# 141 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_JoshIntro:
# 142 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Don't take us GYM TRAINERS lightly!\n"
# 143 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "I'll show you why we're better!$"
# 144 "data/maps/RustboroCity_Gym/scripts.pory"

# 145 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_JoshDefeat:
# 146 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "You were too good for me…$"
# 147 "data/maps/RustboroCity_Gym/scripts.pory"

# 148 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_JoshPostBattle:
# 149 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "You haven't seen anything of the ROCK\n"
# 150 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "type's terrifying power!$"
# 151 "data/maps/RustboroCity_Gym/scripts.pory"

# 152 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_TommyIntro:
# 153 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "If you can't beat me, you won't stand\n"
# 154 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "a chance against ROXANNE!$"
# 155 "data/maps/RustboroCity_Gym/scripts.pory"

# 156 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_TommyDefeat:
# 157 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Wow! You've got some potential!$"
# 158 "data/maps/RustboroCity_Gym/scripts.pory"

# 159 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_TommyPostBattle:
# 160 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "ROXANNE is stronger than me by\n"
# 161 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "several times.\p"
# 162 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "You'd better be on your guard!$"
# 163 "data/maps/RustboroCity_Gym/scripts.pory"

# 164 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_MarcIntro:
# 165 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "We might be in the middle of town,\n"
# 166 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "but so what?\p"
# 167 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "My ROCK POKéMON need room to\n"
# 168 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "rampage!$"
# 169 "data/maps/RustboroCity_Gym/scripts.pory"

# 170 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_MarcDefeat:
# 171 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Oh, man oh man!\n"
# 172 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Our challenger is one feisty customer!$"
# 173 "data/maps/RustboroCity_Gym/scripts.pory"

# 174 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_MarcPostBattle:
# 175 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "I have to hand it to our LEADER.\p"
# 176 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "It took smarts and sense for her to\n"
# 177 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "pick the ROCK type at her young age.$"
# 178 "data/maps/RustboroCity_Gym/scripts.pory"

# 179 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_RoxanneIntro:
# 180 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Hello, I am ROXANNE, the RUSTBORO\n"
# 181 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "POKéMON GYM LEADER.\p"
# 182 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "I became a GYM LEADER so that I might\n"
# 183 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "apply what I learned at the POKéMON\l"
# 184 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "TRAINER'S SCHOOL in battle.\p"
# 185 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Would you kindly demonstrate how you\n"
# 186 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "battle, and with which POKéMON?$"
# 187 "data/maps/RustboroCity_Gym/scripts.pory"

# 188 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_RoxanneDefeat:
# 189 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "So…\n"
# 190 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "I lost…\p"
# 191 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "It seems that I still have much more\n"
# 192 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "to learn…\p"
# 193 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "I understand.\p"
# 194 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "The POKéMON LEAGUE's rules state\n"
# 195 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "that TRAINERS are to be given this\l"
# 196 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "if they defeat a GYM LEADER.\p"
# 197 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Please accept the official POKéMON\n"
# 198 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "LEAGUE STONE BADGE.$"
# 199 "data/maps/RustboroCity_Gym/scripts.pory"

# 200 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_ReceivedStoneBadge:
# 201 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "{PLAYER} received the STONE BADGE\n"
# 202 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "from ROXANNE.$"
# 203 "data/maps/RustboroCity_Gym/scripts.pory"

# 204 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_StoneBadgeInfoTakeThis:
# 205 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "The STONE BADGE heightens the ATTACK\n"
# 206 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "power of your POKéMON.\p"
# 207 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "It also enables them to use the HM move\n"
# 208 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "CUT outside of battle.\p"
# 209 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Please take this with you, too.$"
# 210 "data/maps/RustboroCity_Gym/scripts.pory"

# 211 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_ExplainRockTomb:
# 212 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "That TECHNICAL MACHINE, TM39,\n"
# 213 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "contains ROCK TOMB.\p"
# 214 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "It not only inflicts damage by dropping\n"
# 215 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "rocks, it also lowers SPEED.\p"
# 216 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "If you use a TM, it instantly teaches\n"
# 217 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "the move to a POKéMON.\p"
# 218 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Remember, a TM can be used only once,\n"
# 219 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "so think before you use it.$"
# 220 "data/maps/RustboroCity_Gym/scripts.pory"

# 221 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_RoxannePostBattle:
# 222 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Since you are so strong, you should\n"
# 223 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "challenge other GYM LEADERS.\p"
# 224 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "By battling many TRAINERS, you should\n"
# 225 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "learn many things.$"
# 226 "data/maps/RustboroCity_Gym/scripts.pory"

# 227 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_GymStatue:
# 228 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "RUSTBORO CITY POKéMON GYM$"
# 229 "data/maps/RustboroCity_Gym/scripts.pory"

# 230 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_GymStatueCertified:
# 231 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "RUSTBORO CITY POKéMON GYM\p"
# 232 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "ROXANNE'S CERTIFIED TRAINERS:\n"
# 233 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "{PLAYER}$"
# 234 "data/maps/RustboroCity_Gym/scripts.pory"

# 235 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_RoxanneRegisterCall:
# 236 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "… … … … … …\n"
# 237 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "… … … … … Beep!\p"
# 238 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "ROXANNE: Oh, hello, {PLAYER}?\n"
# 239 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "This is ROXANNE of RUSTBORO CITY.\p"
# 240 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "I heard from BRAWLY that you're\n"
# 241 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "moving up through the ranks of\l"
# 242 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "TRAINERS at an incredible clip.\p"
# 243 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Well, I'd rather not think that\n"
# 244 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "I can't beat you.\p"
# 245 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "I promise, I will shape up my GYM\n"
# 246 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "so that you may challenge us again.\p"
# 247 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "I hope you'll be looking forward to\n"
# 248 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "that occasion as much as me!\p"
# 249 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "… … … … … …\n"
# 250 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "… … … … … Click!$"
# 251 "data/maps/RustboroCity_Gym/scripts.pory"

# 252 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_RegisteredRoxanne:
# 253 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Registered GYM LEADER ROXANNE\n"
# 254 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "in the POKéNAV.$"
# 255 "data/maps/RustboroCity_Gym/scripts.pory"

# 256 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_RoxannePreRematch:
# 257 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "ROXANNE: I'm so glad to see you again.\n"
# 258 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "I'm ROXANNE, the GYM LEADER here.\p"
# 259 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "I'm sure we've both experienced many\n"
# 260 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "battles since we last met.\p"
# 261 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "I would like to see how much better\n"
# 262 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "we've become. Let us battle!$"
# 263 "data/maps/RustboroCity_Gym/scripts.pory"

# 264 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_RoxanneRematchDefeat:
# 265 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Grr…\n"
# 266 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Again, I have lost…$"
# 267 "data/maps/RustboroCity_Gym/scripts.pory"

# 268 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_RoxannePostRematch:
# 269 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "ROXANNE: I still have much to learn\n"
# 270 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "when it comes to battling POKéMON.\p"
# 271 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "That awareness makes me love battling\n"
# 272 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "all that much more!$"
# 273 "data/maps/RustboroCity_Gym/scripts.pory"

# 274 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_RoxanneRematchNeedTwoMons:
# 275 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "ROXANNE: I'm so glad to see you again.\n"
# 276 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "I'm ROXANNE, the GYM LEADER here.\p"
# 277 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "I'm sure we've both experienced many\n"
# 278 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "battles since we last met.\p"
# 279 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "I would like to see how much better\n"
# 280 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "we've become…\p"
# 281 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Oh, no…\n"
# 282 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "You only have one POKéMON with you?\p"
# 283 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Please return with at least one more\n"
# 284 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "POKéMON.$"
