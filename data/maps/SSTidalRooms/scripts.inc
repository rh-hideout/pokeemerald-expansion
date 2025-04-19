# 1 "data/maps/SSTidalRooms/scripts.pory"

# 2 "data/maps/SSTidalRooms/scripts.pory"
SSTidalRooms_MapScripts::
# 3 "data/maps/SSTidalRooms/scripts.pory"
	.byte 0
# 4 "data/maps/SSTidalRooms/scripts.pory"

# 5 "data/maps/SSTidalRooms/scripts.pory"
SSTidalRooms_EventScript_SnatchGiver::
# 6 "data/maps/SSTidalRooms/scripts.pory"
	lock
# 7 "data/maps/SSTidalRooms/scripts.pory"
	faceplayer
# 8 "data/maps/SSTidalRooms/scripts.pory"
	goto_if_set FLAG_RECEIVED_TM_SNATCH, SSTidalRooms_EventScript_ExplainSnatch
# 9 "data/maps/SSTidalRooms/scripts.pory"
	msgbox SSTidalRooms_Text_NotSuspiciousTakeThis, MSGBOX_DEFAULT
# 10 "data/maps/SSTidalRooms/scripts.pory"
	giveitem ITEM_TM_SNATCH
# 11 "data/maps/SSTidalRooms/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 12 "data/maps/SSTidalRooms/scripts.pory"
	setflag FLAG_RECEIVED_TM_SNATCH
# 13 "data/maps/SSTidalRooms/scripts.pory"
	msgbox SSTidalRooms_Text_ExplainSnatch, MSGBOX_DEFAULT
# 14 "data/maps/SSTidalRooms/scripts.pory"
	release
# 15 "data/maps/SSTidalRooms/scripts.pory"
	end
# 16 "data/maps/SSTidalRooms/scripts.pory"

# 17 "data/maps/SSTidalRooms/scripts.pory"
SSTidalRooms_EventScript_ExplainSnatch::
# 18 "data/maps/SSTidalRooms/scripts.pory"
	msgbox SSTidalRooms_Text_ExplainSnatch, MSGBOX_DEFAULT
# 19 "data/maps/SSTidalRooms/scripts.pory"
	release
# 20 "data/maps/SSTidalRooms/scripts.pory"
	end
# 21 "data/maps/SSTidalRooms/scripts.pory"

# 22 "data/maps/SSTidalRooms/scripts.pory"
SSTidalRooms_EventScript_Bed::
# 23 "data/maps/SSTidalRooms/scripts.pory"
	lockall
# 24 "data/maps/SSTidalRooms/scripts.pory"
	msgbox SSTidalRooms_Text_TakeRestOnBed, MSGBOX_DEFAULT
# 25 "data/maps/SSTidalRooms/scripts.pory"
	closemessage
# 26 "data/maps/SSTidalRooms/scripts.pory"
	call Common_EventScript_OutOfCenterPartyHeal
# 27 "data/maps/SSTidalRooms/scripts.pory"
	call SSTidalRooms_EventScript_ProgessCruiseAfterBed
# 28 "data/maps/SSTidalRooms/scripts.pory"
	releaseall
# 29 "data/maps/SSTidalRooms/scripts.pory"
	end
# 30 "data/maps/SSTidalRooms/scripts.pory"

# 31 "data/maps/SSTidalRooms/scripts.pory"
SSTidalRooms_EventScript_Colton::
# 32 "data/maps/SSTidalRooms/scripts.pory"
	trainerbattle_single TRAINER_COLTON, SSTidalRooms_Text_ColtonIntro, SSTidalRooms_Text_ColtonDefeat
# 33 "data/maps/SSTidalRooms/scripts.pory"
	msgbox SSTidalRooms_Text_ColtonPostBattle, MSGBOX_AUTOCLOSE
# 34 "data/maps/SSTidalRooms/scripts.pory"
	end
# 35 "data/maps/SSTidalRooms/scripts.pory"

# 36 "data/maps/SSTidalRooms/scripts.pory"
SSTidalRooms_EventScript_Micah::
# 37 "data/maps/SSTidalRooms/scripts.pory"
	trainerbattle_single TRAINER_MICAH, SSTidalRooms_Text_MicahIntro, SSTidalRooms_Text_MicahDefeat
# 38 "data/maps/SSTidalRooms/scripts.pory"
	msgbox SSTidalRooms_Text_MicahPostBattle, MSGBOX_AUTOCLOSE
# 39 "data/maps/SSTidalRooms/scripts.pory"
	end
# 40 "data/maps/SSTidalRooms/scripts.pory"

# 41 "data/maps/SSTidalRooms/scripts.pory"
SSTidalRooms_EventScript_Thomas::
# 42 "data/maps/SSTidalRooms/scripts.pory"
	trainerbattle_single TRAINER_THOMAS, SSTidalRooms_Text_ThomasIntro, SSTidalRooms_Text_ThomasDefeat
# 43 "data/maps/SSTidalRooms/scripts.pory"
	msgbox SSTidalRooms_Text_ThomasPostBattle, MSGBOX_AUTOCLOSE
# 44 "data/maps/SSTidalRooms/scripts.pory"
	end
# 45 "data/maps/SSTidalRooms/scripts.pory"

# 46 "data/maps/SSTidalRooms/scripts.pory"
SSTidalRooms_EventScript_Jed::
# 47 "data/maps/SSTidalRooms/scripts.pory"
	trainerbattle_double TRAINER_LEA_AND_JED, SSTidalRooms_Text_JedIntro, SSTidalRooms_Text_JedDefeat, SSTidalRooms_Text_JedNotEnoughMons
# 48 "data/maps/SSTidalRooms/scripts.pory"
	msgbox SSTidalRooms_Text_JedPostBattle, MSGBOX_AUTOCLOSE
# 49 "data/maps/SSTidalRooms/scripts.pory"
	end
# 50 "data/maps/SSTidalRooms/scripts.pory"

# 51 "data/maps/SSTidalRooms/scripts.pory"
SSTidalRooms_EventScript_Lea::
# 52 "data/maps/SSTidalRooms/scripts.pory"
	trainerbattle_double TRAINER_LEA_AND_JED, SSTidalRooms_Text_LeaIntro, SSTidalRooms_Text_LeaDefeat, SSTidalRooms_Text_LeaNotEnoughMons
# 53 "data/maps/SSTidalRooms/scripts.pory"
	msgbox SSTidalRooms_Text_LeaPostBattle, MSGBOX_AUTOCLOSE
# 54 "data/maps/SSTidalRooms/scripts.pory"
	end
# 55 "data/maps/SSTidalRooms/scripts.pory"

# 56 "data/maps/SSTidalRooms/scripts.pory"
SSTidalRooms_EventScript_Garret::
# 57 "data/maps/SSTidalRooms/scripts.pory"
	trainerbattle_single TRAINER_GARRET, SSTidalRooms_Text_GarretIntro, SSTidalRooms_Text_GarretDefeat
# 58 "data/maps/SSTidalRooms/scripts.pory"
	msgbox SSTidalRooms_Text_GarretPostBattle, MSGBOX_AUTOCLOSE
# 59 "data/maps/SSTidalRooms/scripts.pory"
	end
# 60 "data/maps/SSTidalRooms/scripts.pory"

# 61 "data/maps/SSTidalRooms/scripts.pory"
SSTidalRooms_EventScript_Naomi::
# 62 "data/maps/SSTidalRooms/scripts.pory"
	trainerbattle_single TRAINER_NAOMI, SSTidalRooms_Text_NaomiIntro, SSTidalRooms_Text_NaomiDefeat
# 63 "data/maps/SSTidalRooms/scripts.pory"
	msgbox SSTidalRooms_Text_NaomiPostBattle, MSGBOX_AUTOCLOSE
# 64 "data/maps/SSTidalRooms/scripts.pory"
	end
# 65 "data/maps/SSTidalRooms/scripts.pory"

# 66 "data/maps/SSTidalRooms/scripts.pory"
SSTidalRooms_Text_TakeRestOnBed:
# 67 "data/maps/SSTidalRooms/scripts.pory"
	.string "There's a bed…\n"
# 68 "data/maps/SSTidalRooms/scripts.pory"
	.string "Let's take a rest.$"
# 69 "data/maps/SSTidalRooms/scripts.pory"

# 70 "data/maps/SSTidalRooms/scripts.pory"
SSTidalRooms_Text_ColtonIntro:
# 71 "data/maps/SSTidalRooms/scripts.pory"
	.string "I often sail to LILYCOVE CITY.\p"
# 72 "data/maps/SSTidalRooms/scripts.pory"
	.string "I enjoy attending CONTESTS,\n"
# 73 "data/maps/SSTidalRooms/scripts.pory"
	.string "you see.$"
# 74 "data/maps/SSTidalRooms/scripts.pory"

# 75 "data/maps/SSTidalRooms/scripts.pory"
SSTidalRooms_Text_ColtonDefeat:
# 76 "data/maps/SSTidalRooms/scripts.pory"
	.string "That was an enjoyable match!$"
# 77 "data/maps/SSTidalRooms/scripts.pory"

# 78 "data/maps/SSTidalRooms/scripts.pory"
SSTidalRooms_Text_ColtonPostBattle:
# 79 "data/maps/SSTidalRooms/scripts.pory"
	.string "I get so excited imagining what kinds\n"
# 80 "data/maps/SSTidalRooms/scripts.pory"
	.string "of POKéMON I'll get to see in the next\l"
# 81 "data/maps/SSTidalRooms/scripts.pory"
	.string "CONTEST. The anticipation of it thrills!$"
# 82 "data/maps/SSTidalRooms/scripts.pory"

# 83 "data/maps/SSTidalRooms/scripts.pory"
SSTidalRooms_Text_MicahIntro:
# 84 "data/maps/SSTidalRooms/scripts.pory"
	.string "Are your friends strong?$"
# 85 "data/maps/SSTidalRooms/scripts.pory"

# 86 "data/maps/SSTidalRooms/scripts.pory"
SSTidalRooms_Text_MicahDefeat:
# 87 "data/maps/SSTidalRooms/scripts.pory"
	.string "Your friends are, indeed, strong.$"
# 88 "data/maps/SSTidalRooms/scripts.pory"

# 89 "data/maps/SSTidalRooms/scripts.pory"
SSTidalRooms_Text_MicahPostBattle:
# 90 "data/maps/SSTidalRooms/scripts.pory"
	.string "Friends need not be human.\n"
# 91 "data/maps/SSTidalRooms/scripts.pory"
	.string "For me, POKéMON are treasured friends!$"
# 92 "data/maps/SSTidalRooms/scripts.pory"

# 93 "data/maps/SSTidalRooms/scripts.pory"
SSTidalRooms_Text_ThomasIntro:
# 94 "data/maps/SSTidalRooms/scripts.pory"
	.string "Child…\n"
# 95 "data/maps/SSTidalRooms/scripts.pory"
	.string "Did you knock on the door?$"
# 96 "data/maps/SSTidalRooms/scripts.pory"

# 97 "data/maps/SSTidalRooms/scripts.pory"
SSTidalRooms_Text_ThomasDefeat:
# 98 "data/maps/SSTidalRooms/scripts.pory"
	.string "A loss is to be accepted without haste\n"
# 99 "data/maps/SSTidalRooms/scripts.pory"
	.string "or panic.$"
# 100 "data/maps/SSTidalRooms/scripts.pory"

# 101 "data/maps/SSTidalRooms/scripts.pory"
SSTidalRooms_Text_ThomasPostBattle:
# 102 "data/maps/SSTidalRooms/scripts.pory"
	.string "To be never ruffled in any situation is\n"
# 103 "data/maps/SSTidalRooms/scripts.pory"
	.string "the GENTLEMAN's code of conduct.$"
# 104 "data/maps/SSTidalRooms/scripts.pory"

# 105 "data/maps/SSTidalRooms/scripts.pory"
SSTidalRooms_Text_JedIntro:
# 106 "data/maps/SSTidalRooms/scripts.pory"
	.string "JED: I feel a little shy about this, but…\n"
# 107 "data/maps/SSTidalRooms/scripts.pory"
	.string "We'll show you our lovey-dovey power!$"
# 108 "data/maps/SSTidalRooms/scripts.pory"

# 109 "data/maps/SSTidalRooms/scripts.pory"
SSTidalRooms_Text_JedDefeat:
# 110 "data/maps/SSTidalRooms/scripts.pory"
	.string "JED: Sigh…$"
# 111 "data/maps/SSTidalRooms/scripts.pory"

# 112 "data/maps/SSTidalRooms/scripts.pory"
SSTidalRooms_Text_JedPostBattle:
# 113 "data/maps/SSTidalRooms/scripts.pory"
	.string "JED: It's the first time that our lovey-\n"
# 114 "data/maps/SSTidalRooms/scripts.pory"
	.string "dovey power couldn't prevail!\l"
# 115 "data/maps/SSTidalRooms/scripts.pory"
	.string "You must be an awesome TRAINER!$"
# 116 "data/maps/SSTidalRooms/scripts.pory"

# 117 "data/maps/SSTidalRooms/scripts.pory"
SSTidalRooms_Text_JedNotEnoughMons:
# 118 "data/maps/SSTidalRooms/scripts.pory"
	.string "JED: You only have one POKéMON?\n"
# 119 "data/maps/SSTidalRooms/scripts.pory"
	.string "Isn't that just too lonesome?$"
# 120 "data/maps/SSTidalRooms/scripts.pory"

# 121 "data/maps/SSTidalRooms/scripts.pory"
SSTidalRooms_Text_LeaIntro:
# 122 "data/maps/SSTidalRooms/scripts.pory"
	.string "LEA: I feel a little silly, but…\n"
# 123 "data/maps/SSTidalRooms/scripts.pory"
	.string "We'll show you our lovey-dovey power!$"
# 124 "data/maps/SSTidalRooms/scripts.pory"

# 125 "data/maps/SSTidalRooms/scripts.pory"
SSTidalRooms_Text_LeaDefeat:
# 126 "data/maps/SSTidalRooms/scripts.pory"
	.string "LEA: Oh, boo!$"
# 127 "data/maps/SSTidalRooms/scripts.pory"

# 128 "data/maps/SSTidalRooms/scripts.pory"
SSTidalRooms_Text_LeaPostBattle:
# 129 "data/maps/SSTidalRooms/scripts.pory"
	.string "LEA: I can't believe it!\n"
# 130 "data/maps/SSTidalRooms/scripts.pory"
	.string "Our lovey-dovey power failed…\l"
# 131 "data/maps/SSTidalRooms/scripts.pory"
	.string "You must be an awesome TRAINER!$"
# 132 "data/maps/SSTidalRooms/scripts.pory"

# 133 "data/maps/SSTidalRooms/scripts.pory"
SSTidalRooms_Text_LeaNotEnoughMons:
# 134 "data/maps/SSTidalRooms/scripts.pory"
	.string "LEA: I wanted to battle…\n"
# 135 "data/maps/SSTidalRooms/scripts.pory"
	.string "But you don't even have two POKéMON…$"
# 136 "data/maps/SSTidalRooms/scripts.pory"

# 137 "data/maps/SSTidalRooms/scripts.pory"
SSTidalRooms_Text_GarretIntro:
# 138 "data/maps/SSTidalRooms/scripts.pory"
	.string "Ah, you've come just in time.\p"
# 139 "data/maps/SSTidalRooms/scripts.pory"
	.string "I'm bored, you see.\n"
# 140 "data/maps/SSTidalRooms/scripts.pory"
	.string "You may entertain me.$"
# 141 "data/maps/SSTidalRooms/scripts.pory"

# 142 "data/maps/SSTidalRooms/scripts.pory"
SSTidalRooms_Text_GarretDefeat:
# 143 "data/maps/SSTidalRooms/scripts.pory"
	.string "…That will do.$"
# 144 "data/maps/SSTidalRooms/scripts.pory"

# 145 "data/maps/SSTidalRooms/scripts.pory"
SSTidalRooms_Text_GarretPostBattle:
# 146 "data/maps/SSTidalRooms/scripts.pory"
	.string "Perhaps I shall get Father to acquire\n"
# 147 "data/maps/SSTidalRooms/scripts.pory"
	.string "a yacht for me.\l"
# 148 "data/maps/SSTidalRooms/scripts.pory"
	.string "A yacht for me and POKéMON!$"
# 149 "data/maps/SSTidalRooms/scripts.pory"

# 150 "data/maps/SSTidalRooms/scripts.pory"
SSTidalRooms_Text_NaomiIntro:
# 151 "data/maps/SSTidalRooms/scripts.pory"
	.string "Oh, you're such an adorable TRAINER.\n"
# 152 "data/maps/SSTidalRooms/scripts.pory"
	.string "Would you like to have tea?\l"
# 153 "data/maps/SSTidalRooms/scripts.pory"
	.string "Or would you rather battle?$"
# 154 "data/maps/SSTidalRooms/scripts.pory"

# 155 "data/maps/SSTidalRooms/scripts.pory"
SSTidalRooms_Text_NaomiDefeat:
# 156 "data/maps/SSTidalRooms/scripts.pory"
	.string "I see.\n"
# 157 "data/maps/SSTidalRooms/scripts.pory"
	.string "You're the active sort.$"
# 158 "data/maps/SSTidalRooms/scripts.pory"

# 159 "data/maps/SSTidalRooms/scripts.pory"
SSTidalRooms_Text_NaomiPostBattle:
# 160 "data/maps/SSTidalRooms/scripts.pory"
	.string "A world cruise on a luxury liner has its\n"
# 161 "data/maps/SSTidalRooms/scripts.pory"
	.string "charms, I must say…\p"
# 162 "data/maps/SSTidalRooms/scripts.pory"
	.string "But, I will admit there is an appealing\n"
# 163 "data/maps/SSTidalRooms/scripts.pory"
	.string "side to touring HOENN by ferry.$"
# 164 "data/maps/SSTidalRooms/scripts.pory"

# 165 "data/maps/SSTidalRooms/scripts.pory"
SSTidalRooms_Text_NotSuspiciousTakeThis:
# 166 "data/maps/SSTidalRooms/scripts.pory"
	.string "Uh… Hi! I… I'm not acting suspicious!\n"
# 167 "data/maps/SSTidalRooms/scripts.pory"
	.string "Uh… You can have this! For free!\p"
# 168 "data/maps/SSTidalRooms/scripts.pory"
	.string "It… Honestly, I didn't SNATCH it from\n"
# 169 "data/maps/SSTidalRooms/scripts.pory"
	.string "someone! I'd never do such a thing!\l"
# 170 "data/maps/SSTidalRooms/scripts.pory"
	.string "It's clean! You can use it!$"
# 171 "data/maps/SSTidalRooms/scripts.pory"

# 172 "data/maps/SSTidalRooms/scripts.pory"
SSTidalRooms_Text_ExplainSnatch:
# 173 "data/maps/SSTidalRooms/scripts.pory"
	.string "SNATCH steals the beneficial effects\n"
# 174 "data/maps/SSTidalRooms/scripts.pory"
	.string "of certain moves before they can be\l"
# 175 "data/maps/SSTidalRooms/scripts.pory"
	.string "used by a foe or ally.$"
