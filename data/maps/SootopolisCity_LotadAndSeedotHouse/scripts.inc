# 1 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"

# 2 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
SootopolisCity_LotadAndSeedotHouse_MapScripts::
# 3 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.byte 0
# 4 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"

# 5 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
SootopolisCity_LotadAndSeedotHouse_EventScript_SeedotBrother::
# 6 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	special GetSeedotSizeRecordInfo
# 7 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	lock
# 8 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	faceplayer
# 9 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_PleaseShowMeBigSeedot, MSGBOX_DEFAULT
# 10 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	special ChoosePartyMon
# 11 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	waitstate
# 12 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	copyvar VAR_RESULT, VAR_0x8004
# 13 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	goto_if_eq VAR_RESULT, PARTY_NOTHING_CHOSEN, SootopolisCity_LotadAndSeedotHouse_EventScript_CancelShowSeedot
# 14 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	special CompareSeedotSize
# 15 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	goto_if_eq VAR_RESULT, 1, SootopolisCity_LotadAndSeedotHouse_EventScript_NotSeedot
# 16 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	goto_if_eq VAR_RESULT, 2, SootopolisCity_LotadAndSeedotHouse_EventScript_SmallSeedot
# 17 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	goto_if_eq VAR_RESULT, 3, SootopolisCity_LotadAndSeedotHouse_EventScript_BigSeedot
# 18 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	release
# 19 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	end
# 20 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"

# 21 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
SootopolisCity_LotadAndSeedotHouse_EventScript_CancelShowSeedot::
# 22 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_DontHaveBigSeedot, MSGBOX_DEFAULT
# 23 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	release
# 24 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	end
# 25 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"

# 26 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
SootopolisCity_LotadAndSeedotHouse_EventScript_NotSeedot::
# 27 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_ThatsNotSeedot, MSGBOX_DEFAULT
# 28 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	release
# 29 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	end
# 30 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"

# 31 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
SootopolisCity_LotadAndSeedotHouse_EventScript_SmallSeedot::
# 32 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_SeenBiggerSeedot, MSGBOX_DEFAULT
# 33 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	release
# 34 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	end
# 35 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"

# 36 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
SootopolisCity_LotadAndSeedotHouse_EventScript_BigSeedot::
# 37 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_GoshMightBeBiggerThanLotad, MSGBOX_DEFAULT
# 38 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	giveitem ITEM_ELIXIR
# 39 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, SootopolisCity_LotadAndSeedotHouse_EventScript_NoRoomForElixir1
# 40 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	closemessage
# 41 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	release
# 42 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	end
# 43 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"

# 44 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
SootopolisCity_LotadAndSeedotHouse_EventScript_NoRoomForElixir1::
# 45 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_BagCrammedFull1, MSGBOX_DEFAULT
# 46 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	release
# 47 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	end
# 48 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"

# 49 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
SootopolisCity_LotadAndSeedotHouse_EventScript_LotadBrother::
# 50 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	special GetLotadSizeRecordInfo
# 51 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	lock
# 52 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	faceplayer
# 53 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_PleaseShowMeBigLotad, MSGBOX_DEFAULT
# 54 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	special ChoosePartyMon
# 55 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	waitstate
# 56 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	copyvar VAR_RESULT, VAR_0x8004
# 57 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	goto_if_eq VAR_RESULT, PARTY_NOTHING_CHOSEN, SootopolisCity_LotadAndSeedotHouse_EventScript_CancelShowLotad
# 58 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	special CompareLotadSize
# 59 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	goto_if_eq VAR_RESULT, 1, SootopolisCity_LotadAndSeedotHouse_EventScript_NotLotad
# 60 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	goto_if_eq VAR_RESULT, 2, SootopolisCity_LotadAndSeedotHouse_EventScript_SmallLotad
# 61 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	goto_if_eq VAR_RESULT, 3, SootopolisCity_LotadAndSeedotHouse_EventScript_BigLotad
# 62 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	release
# 63 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	end
# 64 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"

# 65 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
SootopolisCity_LotadAndSeedotHouse_EventScript_CancelShowLotad::
# 66 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_DontHaveBigLotad, MSGBOX_DEFAULT
# 67 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	release
# 68 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	end
# 69 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"

# 70 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
SootopolisCity_LotadAndSeedotHouse_EventScript_NotLotad::
# 71 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_ThatsNotLotad, MSGBOX_DEFAULT
# 72 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	release
# 73 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	end
# 74 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"

# 75 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
SootopolisCity_LotadAndSeedotHouse_EventScript_SmallLotad::
# 76 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_SeenBiggerLotad, MSGBOX_DEFAULT
# 77 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	release
# 78 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	end
# 79 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"

# 80 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
SootopolisCity_LotadAndSeedotHouse_EventScript_BigLotad::
# 81 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_WowMightBeBiggerThanSeedot, MSGBOX_DEFAULT
# 82 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	giveitem ITEM_ELIXIR
# 83 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, SootopolisCity_LotadAndSeedotHouse_EventScript_NoRoomForElixir2
# 84 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	closemessage
# 85 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	release
# 86 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	end
# 87 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"

# 88 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
SootopolisCity_LotadAndSeedotHouse_EventScript_NoRoomForElixir2::
# 89 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_BagCrammedFull2, MSGBOX_DEFAULT
# 90 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	release
# 91 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	end
# 92 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"

# 93 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
SootopolisCity_LotadAndSeedotHouse_EventScript_SeedotSizeRecord::
# 94 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	special GetSeedotSizeRecordInfo
# 95 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	lockall
# 96 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_BiggestSeedotInHistory, MSGBOX_DEFAULT
# 97 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	releaseall
# 98 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	end
# 99 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"

# 100 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
SootopolisCity_LotadAndSeedotHouse_EventScript_LotadSizeRecord::
# 101 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	special GetLotadSizeRecordInfo
# 102 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	lockall
# 103 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_BiggestLotadInHistory, MSGBOX_DEFAULT
# 104 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	releaseall
# 105 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	end
# 106 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"

# 107 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
SootopolisCity_LotadAndSeedotHouse_Text_PleaseShowMeBigSeedot:
# 108 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "Do you know the POKéMON SEEDOT?\n"
# 109 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "It's hardly ever seen in SOOTOPOLIS.\p"
# 110 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "Anyway, I love big SEEDOT.\n"
# 111 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "The bigger the better.\p"
# 112 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "But my younger brother, he says that\n"
# 113 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "LOTAD is bigger.\p"
# 114 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "That's silly.\n"
# 115 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "SEEDOT has to be bigger than that!\p"
# 116 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "Huh? Do you have a SEEDOT with you?\n"
# 117 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "P-p-please, show me!$"
# 118 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"

# 119 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
SootopolisCity_LotadAndSeedotHouse_Text_GoshMightBeBiggerThanLotad:
# 120 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "{STR_VAR_2}!\n"
# 121 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "Oh, my gosh, this is a big one!\p"
# 122 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "It might even beat the big LOTAD\n"
# 123 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "my younger brother saw!\p"
# 124 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "Thanks for showing me.\n"
# 125 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "This is my thanks!$"
# 126 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"

# 127 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
@ Unused
# 128 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
SootopolisCity_LotadAndSeedotHouse_Text_ReceivedPotion1:
# 129 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "{PLAYER} received a POTION.$"
# 130 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"

# 131 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
SootopolisCity_LotadAndSeedotHouse_Text_BagCrammedFull1:
# 132 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "Hunh?\n"
# 133 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "Your BAG is crammed full.$"
# 134 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"

# 135 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
SootopolisCity_LotadAndSeedotHouse_Text_SeenBiggerSeedot:
# 136 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "{STR_VAR_2}, is it?\p"
# 137 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "Hmm… I've seen a bigger SEEDOT\n"
# 138 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "than this one.$"
# 139 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"

# 140 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
SootopolisCity_LotadAndSeedotHouse_Text_ThatsNotSeedot:
# 141 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "Oh, now this is quite something…\n"
# 142 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "But it's not a SEEDOT!$"
# 143 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"

# 144 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
SootopolisCity_LotadAndSeedotHouse_Text_DontHaveBigSeedot:
# 145 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "You don't have a big SEEDOT?\n"
# 146 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "That's too bad…\p"
# 147 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "If you get a big SEEDOT, please\n"
# 148 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "come show me.$"
# 149 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"

# 150 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
SootopolisCity_LotadAndSeedotHouse_Text_BiggestSeedotInHistory:
# 151 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "The biggest SEEDOT in history!\n"
# 152 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "{STR_VAR_2}'s {STR_VAR_3} giant!\p"
# 153 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "A SEEDOT bigger than a LOTAD\n"
# 154 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "always wanted!$"
# 155 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"

# 156 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
SootopolisCity_LotadAndSeedotHouse_Text_PleaseShowMeBigLotad:
# 157 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "Do you know the POKéMON LOTAD?\n"
# 158 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "It's rarely seen in SOOTOPOLIS.\p"
# 159 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "I love, I mean love, big LOTAD!\p"
# 160 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "My big brother says that SEEDOT is\n"
# 161 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "bigger.\p"
# 162 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "But that's wrong! Everyone knows that\n"
# 163 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "LOTAD is a lot bigger.\p"
# 164 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "Hunh? Do you have a LOTAD?\n"
# 165 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "P-p-please show me!$"
# 166 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"

# 167 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
SootopolisCity_LotadAndSeedotHouse_Text_WowMightBeBiggerThanSeedot:
# 168 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "{STR_VAR_2}!\n"
# 169 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "Wow, that is big!\p"
# 170 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "It might be even bigger than the huge\n"
# 171 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "SEEDOT my big brother saw.\p"
# 172 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "Thanks for showing me!\n"
# 173 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "This is my thanks!$"
# 174 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"

# 175 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
@ Unused
# 176 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
SootopolisCity_LotadAndSeedotHouse_Text_ReceivedPotion2:
# 177 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "{PLAYER} received a POTION.$"
# 178 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"

# 179 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
SootopolisCity_LotadAndSeedotHouse_Text_BagCrammedFull2:
# 180 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "Hunh?\n"
# 181 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "Your BAG is crammed full.$"
# 182 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"

# 183 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
SootopolisCity_LotadAndSeedotHouse_Text_SeenBiggerLotad:
# 184 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "{STR_VAR_2}?\p"
# 185 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "Hmm… I've seen a bigger LOTAD\n"
# 186 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "than this one here.$"
# 187 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"

# 188 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
SootopolisCity_LotadAndSeedotHouse_Text_ThatsNotLotad:
# 189 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "Well, isn't this something!\n"
# 190 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "But it's no LOTAD!$"
# 191 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"

# 192 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
SootopolisCity_LotadAndSeedotHouse_Text_DontHaveBigLotad:
# 193 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "Don't you have a big LOTAD?\n"
# 194 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "How disappointing…\p"
# 195 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "If you get a big LOTAD, please\n"
# 196 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "come show me!$"
# 197 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"

# 198 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
SootopolisCity_LotadAndSeedotHouse_Text_BiggestLotadInHistory:
# 199 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "The biggest LOTAD in history!\n"
# 200 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "{STR_VAR_2}'s {STR_VAR_3} colossus!\p"
# 201 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "A LOTAD bigger than a SEEDOT\n"
# 202 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "always wanted!$"
