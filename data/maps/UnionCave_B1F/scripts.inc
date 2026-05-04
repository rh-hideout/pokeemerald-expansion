UnionCave_B1F_MapScripts::
	.byte 0

UnionCave_B1F_EventScript_HikerPhillip::
	trainerbattle_single TRAINER_PHILLIP, UnionCave_B1F_Text_HikerPhillipSeen, UnionCave_B1F_Text_HikerPhillipBeaten
	msgbox UnionCave_B1F_Text_HikerPhillipAfter, MSGBOX_AUTOCLOSE
	end

UnionCave_B1F_EventScript_HikerLeonard::
	trainerbattle_single TRAINER_LEONARD, UnionCave_B1F_Text_HikerLeonardSeen, UnionCave_B1F_Text_HikerLeonardBeaten
	msgbox UnionCave_B1F_Text_HikerLeonardAfter, MSGBOX_AUTOCLOSE
	end

UnionCave_B1F_EventScript_PokemaniacAndrew::
	trainerbattle_single TRAINER_ANDREW, UnionCave_B1F_Text_PokemaniacAndrewSeen, UnionCave_B1F_Text_PokemaniacAndrewBeaten
	msgbox UnionCave_B1F_Text_PokemaniacAndrewAfter, MSGBOX_AUTOCLOSE
	end

UnionCave_B1F_EventScript_PokemaniacCalvin::
	trainerbattle_single TRAINER_CALVIN, UnionCave_B1F_Text_PokemaniacCalvinSeen, UnionCave_B1F_Text_PokemaniacCalvinBeaten
	msgbox UnionCave_B1F_Text_PokemaniacCalvinAfter, MSGBOX_AUTOCLOSE
	end

UnionCave_B1F_EventScript_Item_SecretPower::
	finditem ITEM_TM_SECRET_POWER
	end

UnionCave_B1F_EventScript_Item_Xdefend::
	finditem ITEM_X_DEFEND
	end

UnionCave_B1F_Text_HikerPhillipSeen:
	.string "It's been a while since I last saw\n"
	.string "another person.\p"
	.string "Don't be shy. Let's battle!$"

UnionCave_B1F_Text_HikerPhillipBeaten:
	.string "Uurggh…$"

UnionCave_B1F_Text_HikerPhillipAfter:
	.string "I've been lost for a long time…\p"
	.string "I don't mind it here, but I am\n"
	.string "soooo hungry!$"

UnionCave_B1F_Text_HikerLeonardSeen:
	.string "What do you know! A visitor!$"

UnionCave_B1F_Text_HikerLeonardBeaten:
	.string "Wahahah! You're a feisty one!$"

UnionCave_B1F_Text_HikerLeonardAfter:
	.string "I live down here.\p"
	.string "You can, too, if you'd like.\p"
	.string "There's plenty of room, you see.$"

UnionCave_B1F_Text_PokemaniacAndrewSeen:
	.string "Who's there?\p"
	.string "Leave me and my POKéMON alone!$"

UnionCave_B1F_Text_PokemaniacAndrewBeaten:
	.string "Go… Go away!$"

UnionCave_B1F_Text_PokemaniacAndrewAfter:
	.string "Just me and my POKéMON. I'm de-\n"
	.string "lirious with joy.$"

UnionCave_B1F_Text_PokemaniacCalvinSeen:
	.string "I came all the way here to conduct\n"
	.string "my POKéMON research.\p"
	.string "Let me demonstrate my findings in a\n"
	.string "real battle!$"

UnionCave_B1F_Text_PokemaniacCalvinBeaten:
	.string "You demonstrated on me!$"

UnionCave_B1F_Text_PokemaniacCalvinAfter:
	.string "I should compile and announce my\n"
	.string "study findings.\p"
	.string "I might even become famous like\n"
	.string "PROF.ELM.$"
