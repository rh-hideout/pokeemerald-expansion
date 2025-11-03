# 1 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"

# 2 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"
RustboroCity_DevonCorp_1F_MapScripts::
# 3 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_DevonCorp_1F_OnTransition
# 4 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"
	.byte 0
# 5 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"

# 6 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"
RustboroCity_DevonCorp_1F_OnTransition:
# 7 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"
	call_if_unset FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_BlockStairs
# 8 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"
	end
# 9 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"

# 10 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"
RustboroCity_DevonCorp_1F_EventScript_BlockStairs::
# 11 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"
	setobjectxyperm LOCALID_DEVON_CORP_STAIR_GUARD, 14, 2
# 12 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"
	setobjectmovementtype LOCALID_DEVON_CORP_STAIR_GUARD, MOVEMENT_TYPE_FACE_DOWN
# 13 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"
	return
# 14 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"

# 15 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"
RustboroCity_DevonCorp_1F_EventScript_Employee::
# 16 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"
	lock
# 17 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"
	faceplayer
# 18 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"
	goto_if_set FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_GoodsRecovered
# 19 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"
	goto_if_set FLAG_DEVON_GOODS_STOLEN, RustboroCity_DevonCorp_1F_EventScript_RobberWasntBright
# 20 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"
	msgbox RustboroCity_DevonCorp_1F_Text_ThoseShoesAreOurProduct, MSGBOX_DEFAULT
# 21 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"
	release
# 22 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"
	end
# 23 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"

# 24 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"
RustboroCity_DevonCorp_1F_EventScript_RobberWasntBright::
# 25 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"
	msgbox RustboroCity_DevonCorp_1F_Text_RobberWasntVeryBright, MSGBOX_DEFAULT
# 26 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"
	release
# 27 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"
	end
# 28 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"

# 29 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"
RustboroCity_DevonCorp_1F_EventScript_GoodsRecovered::
# 30 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"
	msgbox RustboroCity_DevonCorp_1F_Text_SoundsLikeStolenGoodsRecovered, MSGBOX_DEFAULT
# 31 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"
	release
# 32 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"
	end
# 33 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"

# 34 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"
RustboroCity_DevonCorp_1F_EventScript_StairGuard::
# 35 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"
	lock
# 36 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"
	faceplayer
# 37 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"
	goto_if_set FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_AlwaysWelcome
# 38 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"
	goto_if_set FLAG_RECOVERED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_GotRobbed
# 39 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"
	goto_if_set FLAG_DEVON_GOODS_STOLEN, RustboroCity_DevonCorp_1F_EventScript_GotRobbed
# 40 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"
	msgbox RustboroCity_DevonCorp_1F_Text_OnlyAuthorizedPeopleEnter, MSGBOX_DEFAULT
# 41 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"
	release
# 42 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"
	end
# 43 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"

# 44 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"
RustboroCity_DevonCorp_1F_EventScript_AlwaysWelcome::
# 45 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"
	msgbox RustboroCity_DevonCorp_1F_Text_YoureAlwaysWelcomeHere, MSGBOX_DEFAULT
# 46 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"
	release
# 47 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"
	end
# 48 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"

# 49 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"
RustboroCity_DevonCorp_1F_EventScript_GotRobbed::
# 50 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"
	msgbox RustboroCity_DevonCorp_1F_Text_HowCouldWeGetRobbed, MSGBOX_DEFAULT
# 51 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"
	release
# 52 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"
	end
# 53 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"

# 54 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"
RustboroCity_DevonCorp_1F_EventScript_Greeter::
# 55 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"
	lock
# 56 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"
	faceplayer
# 57 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"
	goto_if_set FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_WelcomeToDevonCorp
# 58 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"
	goto_if_set FLAG_RECOVERED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_StaffGotRobbed
# 59 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"
	goto_if_set FLAG_DEVON_GOODS_STOLEN, RustboroCity_DevonCorp_1F_EventScript_StaffGotRobbed
# 60 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"
	msgbox RustboroCity_DevonCorp_1F_Text_WelcomeToDevonCorp, MSGBOX_DEFAULT
# 61 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"
	release
# 62 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"
	end
# 63 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"

# 64 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"
RustboroCity_DevonCorp_1F_EventScript_WelcomeToDevonCorp::
# 65 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"
	msgbox RustboroCity_DevonCorp_1F_Text_WelcomeToDevonCorp, MSGBOX_DEFAULT
# 66 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"
	release
# 67 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"
	end
# 68 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"

# 69 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"
RustboroCity_DevonCorp_1F_EventScript_StaffGotRobbed::
# 70 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"
	msgbox RustboroCity_DevonCorp_1F_Text_StaffGotRobbed, MSGBOX_DEFAULT
# 71 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"
	release
# 72 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"
	end
# 73 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"

# 74 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"
RustboroCity_DevonCorp_1F_EventScript_RocksMetalDisplay::
# 75 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"
	msgbox RustboroCity_DevonCorp_1F_Text_RocksMetalDisplay, MSGBOX_SIGN
# 76 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"
	end
# 77 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"

# 78 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"
RustboroCity_DevonCorp_1F_EventScript_ProductsDisplay::
# 79 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"
	msgbox RustboroCity_DevonCorp_1F_Text_ProductDisplay, MSGBOX_SIGN
# 80 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"
	end
# 81 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"

# 82 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"
RustboroCity_DevonCorp_1F_Text_WelcomeToDevonCorp:
# 83 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"
	.string "Hello and welcome to the DEVON\n"
# 84 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"
	.string "CORPORATION.\p"
# 85 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"
	.string "We're proud producers of items and\n"
# 86 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"
	.string "medicine that enhance your life.$"
# 87 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"

# 88 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"
RustboroCity_DevonCorp_1F_Text_StaffGotRobbed:
# 89 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"
	.string "One of our research staff stupidly\n"
# 90 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"
	.string "got robbed of an important parcel.$"
# 91 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"

# 92 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"
RustboroCity_DevonCorp_1F_Text_ThoseShoesAreOurProduct:
# 93 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"
	.string "Hey, those RUNNING SHOES!\n"
# 94 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"
	.string "They're one of our products!\p"
# 95 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"
	.string "It makes me happy when I see someone\n"
# 96 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"
	.string "using something we made.$"
# 97 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"

# 98 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"
RustboroCity_DevonCorp_1F_Text_RobberWasntVeryBright:
# 99 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"
	.string "That stolen parcel…\p"
# 100 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"
	.string "Well, sure it's important, but it's not\n"
# 101 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"
	.string "anything that anyone can use.\p"
# 102 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"
	.string "In my estimation, that robber must not\n"
# 103 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"
	.string "have been very bright.$"
# 104 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"

# 105 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"
RustboroCity_DevonCorp_1F_Text_SoundsLikeStolenGoodsRecovered:
# 106 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"
	.string "It sounds like they've recovered\n"
# 107 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"
	.string "the ripped-off DEVON GOODS.$"
# 108 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"

# 109 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"
RustboroCity_DevonCorp_1F_Text_OnlyAuthorizedPeopleEnter:
# 110 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"
	.string "I'm sorry, only authorized people\n"
# 111 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"
	.string "are allowed to enter here.$"
# 112 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"

# 113 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"
RustboroCity_DevonCorp_1F_Text_HowCouldWeGetRobbed:
# 114 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"
	.string "It's beyond stupid.\n"
# 115 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"
	.string "How could we get robbed?$"
# 116 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"

# 117 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"
RustboroCity_DevonCorp_1F_Text_YoureAlwaysWelcomeHere:
# 118 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"
	.string "Hi, there!\n"
# 119 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"
	.string "You're always welcome here!$"
# 120 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"

# 121 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"
RustboroCity_DevonCorp_1F_Text_RocksMetalDisplay:
# 122 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"
	.string "Samples of rocks and metal are\n"
# 123 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"
	.string "displayed in the glass case.\p"
# 124 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"
	.string "There's a panel with some writing\n"
# 125 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"
	.string "on it…\p"
# 126 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"
	.string "“DEVON CORPORATION got its start as\n"
# 127 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"
	.string "a producer of stones from quarries.\p"
# 128 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"
	.string "“The company also produced iron from\n"
# 129 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"
	.string "filings in the sand.\p"
# 130 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"
	.string "“From that humble start as a producer\n"
# 131 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"
	.string "of raw materials, DEVON developed.\p"
# 132 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"
	.string "“DEVON is now a manufacturer of a wide\n"
# 133 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"
	.string "range of industrial products.”$"
# 134 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"

# 135 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"
RustboroCity_DevonCorp_1F_Text_ProductDisplay:
# 136 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"
	.string "Prototypes and test products fill\n"
# 137 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"
	.string "the glass display case.\p"
# 138 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"
	.string "There's a panel with a description…\p"
# 139 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"
	.string "“In addition to industrial products,\n"
# 140 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"
	.string "DEVON now markets sundries and\l"
# 141 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"
	.string "pharmaceuticals for better lifestyles.\p"
# 142 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"
	.string "“Recently, DEVON has begun marketing\n"
# 143 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"
	.string "tools for POKéMON TRAINERS, including\l"
# 144 "data/maps/RustboroCity_DevonCorp_1F/scripts.pory"
	.string "POKé BALLS and POKéNAV systems.”$"
