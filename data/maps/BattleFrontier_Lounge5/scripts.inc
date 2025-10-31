# 1 "data/maps/BattleFrontier_Lounge5/scripts.pory"

# 2 "data/maps/BattleFrontier_Lounge5/scripts.pory"
BattleFrontier_Lounge5_MapScripts::
# 3 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.byte 0
# 4 "data/maps/BattleFrontier_Lounge5/scripts.pory"

# 5 "data/maps/BattleFrontier_Lounge5/scripts.pory"
BattleFrontier_Lounge5_EventScript_NatureGirl::
# 6 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	lock
# 7 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	faceplayer
# 8 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	msgbox BattleFrontier_Lounge5_Text_NatureGirlGreeting, MSGBOX_YESNO
# 9 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge5_EventScript_NatureGirlNoneShown
# 10 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	special ChoosePartyMon
# 11 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	waitstate
# 12 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	lock
# 13 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	faceplayer
# 14 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, BattleFrontier_Lounge5_EventScript_NatureGirlNoneShown
# 15 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
# 16 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	goto_if_eq VAR_RESULT, SPECIES_EGG, BattleFrontier_Lounge5_EventScript_NatureGirlEgg
# 17 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	special ShowNatureGirlMessage
# 18 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	waitmessage
# 19 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	waitbuttonpress
# 20 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	release
# 21 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	end
# 22 "data/maps/BattleFrontier_Lounge5/scripts.pory"

# 23 "data/maps/BattleFrontier_Lounge5/scripts.pory"
BattleFrontier_Lounge5_EventScript_NatureGirlEgg::
# 24 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	msgbox BattleFrontier_Lounge5_Text_NatureGirlEgg, MSGBOX_DEFAULT
# 25 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	release
# 26 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	end
# 27 "data/maps/BattleFrontier_Lounge5/scripts.pory"

# 28 "data/maps/BattleFrontier_Lounge5/scripts.pory"
BattleFrontier_Lounge5_EventScript_NatureGirlNoneShown::
# 29 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	msgbox BattleFrontier_Lounge5_Text_NatureGirlNoneShown, MSGBOX_DEFAULT
# 30 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	release
# 31 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	end
# 32 "data/maps/BattleFrontier_Lounge5/scripts.pory"

# 33 "data/maps/BattleFrontier_Lounge5/scripts.pory"
BattleFrontier_Lounge5_EventScript_Gentleman::
# 34 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	msgbox BattleFrontier_Lounge5_Text_LadyClaimsSheUnderstandsPokemon, MSGBOX_NPC
# 35 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	end
# 36 "data/maps/BattleFrontier_Lounge5/scripts.pory"

# 37 "data/maps/BattleFrontier_Lounge5/scripts.pory"
BattleFrontier_Lounge5_EventScript_BlackBelt::
# 38 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	msgbox BattleFrontier_Lounge5_Text_GirlSayingSomethingProfound, MSGBOX_NPC
# 39 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	end
# 40 "data/maps/BattleFrontier_Lounge5/scripts.pory"

# 41 "data/maps/BattleFrontier_Lounge5/scripts.pory"
BattleFrontier_Lounge5_EventScript_LittleBoy::
# 42 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	msgbox BattleFrontier_Lounge5_Text_GirlPlaysAtRedHouseALot, MSGBOX_NPC
# 43 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	end
# 44 "data/maps/BattleFrontier_Lounge5/scripts.pory"

# 45 "data/maps/BattleFrontier_Lounge5/scripts.pory"
BattleFrontier_Lounge5_Text_NatureGirlGreeting::
# 46 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "Ehehe!\n"
# 47 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "I can tell what POKéMON are thinking!\p"
# 48 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "Please!\n"
# 49 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "Can I see your POKéMON?$"
# 50 "data/maps/BattleFrontier_Lounge5/scripts.pory"

# 51 "data/maps/BattleFrontier_Lounge5/scripts.pory"
BattleFrontier_Lounge5_Text_NatureGirlNoneShown::
# 52 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "Boo!\n"
# 53 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "Cheapie!$"
# 54 "data/maps/BattleFrontier_Lounge5/scripts.pory"

# 55 "data/maps/BattleFrontier_Lounge5/scripts.pory"
BattleFrontier_Lounge5_Text_NatureGirlAttackHighAttackLow::
# 56 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "Hmhm…\p"
# 57 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "This one says it likes to battle!\n"
# 58 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "It will battle even if it has a lot\l"
# 59 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "of ouchies!$"
# 60 "data/maps/BattleFrontier_Lounge5/scripts.pory"

# 61 "data/maps/BattleFrontier_Lounge5/scripts.pory"
BattleFrontier_Lounge5_Text_NatureGirlAttackHighDefenseLow::
# 62 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "Hmhm…\p"
# 63 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "This one says it likes to battle!\n"
# 64 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "But if it gets enough ouchies,\l"
# 65 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "it will worry about itself!$"
# 66 "data/maps/BattleFrontier_Lounge5/scripts.pory"

# 67 "data/maps/BattleFrontier_Lounge5/scripts.pory"
BattleFrontier_Lounge5_Text_NatureGirlAttackHighSupportLow::
# 68 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "Hmhm…\p"
# 69 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "This one says it likes to battle!\n"
# 70 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "But if it gets enough ouchies,\l"
# 71 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "it will turn sneaky!$"
# 72 "data/maps/BattleFrontier_Lounge5/scripts.pory"

# 73 "data/maps/BattleFrontier_Lounge5/scripts.pory"
BattleFrontier_Lounge5_Text_NatureGirlDefenseHighAttackLow::
# 74 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "Hmhm…\p"
# 75 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "This one says it looks after itself!\n"
# 76 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "But if it gets enough ouchies,\l"
# 77 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "it will hit back!$"
# 78 "data/maps/BattleFrontier_Lounge5/scripts.pory"

# 79 "data/maps/BattleFrontier_Lounge5/scripts.pory"
BattleFrontier_Lounge5_Text_NatureGirlDefenseHighDefenseLow::
# 80 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "Hmhm…\p"
# 81 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "This one says it looks after itself!\n"
# 82 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "It says it worries about itself whether\l"
# 83 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "or not it has a lot of ouchies!$"
# 84 "data/maps/BattleFrontier_Lounge5/scripts.pory"

# 85 "data/maps/BattleFrontier_Lounge5/scripts.pory"
BattleFrontier_Lounge5_Text_NatureGirlDefenseHighSupportLow::
# 86 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "Hmhm…\p"
# 87 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "This one says it looks after itself!\n"
# 88 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "But if it gets enough ouchies,\l"
# 89 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "it will turn sneaky!$"
# 90 "data/maps/BattleFrontier_Lounge5/scripts.pory"

# 91 "data/maps/BattleFrontier_Lounge5/scripts.pory"
BattleFrontier_Lounge5_Text_NatureGirlSupportHighAttackLow::
# 92 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "Hmhm…\p"
# 93 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "This one says it likes to be sneaky!\n"
# 94 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "But if it gets enough ouchies,\l"
# 95 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "it will hit back!$"
# 96 "data/maps/BattleFrontier_Lounge5/scripts.pory"

# 97 "data/maps/BattleFrontier_Lounge5/scripts.pory"
BattleFrontier_Lounge5_Text_NatureGirlSupportHighDefenseLow::
# 98 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "Hmhm…\p"
# 99 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "This one says it likes to be sneaky!\n"
# 100 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "But if it gets enough ouchies,\l"
# 101 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "it will worry about itself!$"
# 102 "data/maps/BattleFrontier_Lounge5/scripts.pory"

# 103 "data/maps/BattleFrontier_Lounge5/scripts.pory"
BattleFrontier_Lounge5_Text_NatureGirlSupportHighSupportLow::
# 104 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "Hmhm…\p"
# 105 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "This one says it likes to be sneaky!\n"
# 106 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "It says it likes to be sneaky even\l"
# 107 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "if it has a lot of ouchies!$"
# 108 "data/maps/BattleFrontier_Lounge5/scripts.pory"

# 109 "data/maps/BattleFrontier_Lounge5/scripts.pory"
BattleFrontier_Lounge5_Text_NatureGirlEgg::
# 110 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "That's silly! An EGG is asleep!\n"
# 111 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "I can't talk to it!$"
# 112 "data/maps/BattleFrontier_Lounge5/scripts.pory"

# 113 "data/maps/BattleFrontier_Lounge5/scripts.pory"
BattleFrontier_Lounge5_Text_LadyClaimsSheUnderstandsPokemon::
# 114 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "How charming!\n"
# 115 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "That little lady claims she can\l"
# 116 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "understand POKéMON!$"
# 117 "data/maps/BattleFrontier_Lounge5/scripts.pory"

# 118 "data/maps/BattleFrontier_Lounge5/scripts.pory"
BattleFrontier_Lounge5_Text_GirlSayingSomethingProfound::
# 119 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "I have this feeling that the little girl\n"
# 120 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "is saying something profound.$"
# 121 "data/maps/BattleFrontier_Lounge5/scripts.pory"

# 122 "data/maps/BattleFrontier_Lounge5/scripts.pory"
BattleFrontier_Lounge5_Text_GirlPlaysAtRedHouseALot::
# 123 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "I know something!\p"
# 124 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "That little girl plays at the red house\n"
# 125 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "a lot!$"
