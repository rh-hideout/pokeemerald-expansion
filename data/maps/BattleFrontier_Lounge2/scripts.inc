# 1 "data/maps/BattleFrontier_Lounge2/scripts.pory"

# 2 "data/maps/BattleFrontier_Lounge2/scripts.pory"
BattleFrontier_Lounge2_MapScripts::
# 3 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.byte 0
# 4 "data/maps/BattleFrontier_Lounge2/scripts.pory"

# 5 "data/maps/BattleFrontier_Lounge2/scripts.pory"
@ This NPC gives hints about a random facility or battle mode.
# 6 "data/maps/BattleFrontier_Lounge2/scripts.pory"
@ For battle modes he gives generic advice
# 7 "data/maps/BattleFrontier_Lounge2/scripts.pory"
@ For facilities, depending on how far the player has progressed he will say either
# 8 "data/maps/BattleFrontier_Lounge2/scripts.pory"
@    The name of the Frontier Brain there
# 9 "data/maps/BattleFrontier_Lounge2/scripts.pory"
@    The type and description of the 3 pokemon they use in their silver battle
# 10 "data/maps/BattleFrontier_Lounge2/scripts.pory"
@    The type and description of the 3 pokemon they use in their gold battle
# 11 "data/maps/BattleFrontier_Lounge2/scripts.pory"
BattleFrontier_Lounge2_EventScript_FrontierManiac::
# 12 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	lock
# 13 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	faceplayer
# 14 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	goto_if_set FLAG_MET_BATTLE_FRONTIER_MANIAC, BattleFrontier_Lounge2_EventScript_AlreadyMetManiac
# 15 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	setflag FLAG_MET_BATTLE_FRONTIER_MANIAC
# 16 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	msgbox BattleFrontier_Lounge2_Text_FrontierManiacIntro, MSGBOX_DEFAULT
# 17 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	goto BattleFrontier_Lounge2_EventScript_GiveAdvice
# 18 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	end
# 19 "data/maps/BattleFrontier_Lounge2/scripts.pory"

# 20 "data/maps/BattleFrontier_Lounge2/scripts.pory"
BattleFrontier_Lounge2_EventScript_AlreadyMetManiac::
# 21 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	msgbox BattleFrontier_Lounge2_Text_SwingByForTheLatestWord, MSGBOX_DEFAULT
# 22 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	goto BattleFrontier_Lounge2_EventScript_GiveAdvice
# 23 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	end
# 24 "data/maps/BattleFrontier_Lounge2/scripts.pory"

# 25 "data/maps/BattleFrontier_Lounge2/scripts.pory"
BattleFrontier_Lounge2_EventScript_GiveAdvice::
# 26 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_SINGLES, BattleFrontier_Lounge2_EventScript_BufferSingle
# 27 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_DOUBLES, BattleFrontier_Lounge2_EventScript_BufferDouble
# 28 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_MULTIS, BattleFrontier_Lounge2_EventScript_BufferMulti
# 29 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_LINK, BattleFrontier_Lounge2_EventScript_BufferMultiLink
# 30 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_DOME, BattleFrontier_Lounge2_EventScript_BufferBattleDome
# 31 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_FACTORY, BattleFrontier_Lounge2_EventScript_BufferBattleFactory
# 32 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_PALACE, BattleFrontier_Lounge2_EventScript_BufferBattlePalace
# 33 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_ARENA, BattleFrontier_Lounge2_EventScript_BufferBattleArena
# 34 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_PIKE, BattleFrontier_Lounge2_EventScript_BufferBattlePike
# 35 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_PYRAMID, BattleFrontier_Lounge2_EventScript_BufferBattlePyramid
# 36 "data/maps/BattleFrontier_Lounge2/scripts.pory"
@ <= FRONTIER_MANIAC_TOWER_LINK is any Battle Tower mode
# 37 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	call_if_le VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_LINK, BattleFrontier_Lounge2_EventScript_BattleTowerNews
# 38 "data/maps/BattleFrontier_Lounge2/scripts.pory"
@ >= FRONTIER_MANIAC_DOME is any facility other than Battle Tower
# 39 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	call_if_ge VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_DOME, BattleFrontier_Lounge2_EventScript_FacilityNews
# 40 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	special ShowFrontierManiacMessage
# 41 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	waitmessage
# 42 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	waitbuttonpress
# 43 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	release
# 44 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	end
# 45 "data/maps/BattleFrontier_Lounge2/scripts.pory"

# 46 "data/maps/BattleFrontier_Lounge2/scripts.pory"
BattleFrontier_Lounge2_EventScript_BattleTowerNews::
# 47 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	msgbox BattleFrontier_Lounge2_Text_BattleTowerIsHottest, MSGBOX_DEFAULT
# 48 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	return
# 49 "data/maps/BattleFrontier_Lounge2/scripts.pory"

# 50 "data/maps/BattleFrontier_Lounge2/scripts.pory"
BattleFrontier_Lounge2_EventScript_FacilityNews::
# 51 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	msgbox BattleFrontier_Lounge2_Text_FacilityIsHottest, MSGBOX_DEFAULT
# 52 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	return
# 53 "data/maps/BattleFrontier_Lounge2/scripts.pory"

# 54 "data/maps/BattleFrontier_Lounge2/scripts.pory"
BattleFrontier_Lounge2_EventScript_BufferSingle::
# 55 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	bufferstdstring STR_VAR_1, STDSTRING_SINGLE
# 56 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	return
# 57 "data/maps/BattleFrontier_Lounge2/scripts.pory"

# 58 "data/maps/BattleFrontier_Lounge2/scripts.pory"
BattleFrontier_Lounge2_EventScript_BufferDouble::
# 59 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	bufferstdstring STR_VAR_1, STDSTRING_DOUBLE
# 60 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	return
# 61 "data/maps/BattleFrontier_Lounge2/scripts.pory"

# 62 "data/maps/BattleFrontier_Lounge2/scripts.pory"
BattleFrontier_Lounge2_EventScript_BufferMulti::
# 63 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	bufferstdstring STR_VAR_1, STDSTRING_MULTI
# 64 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	return
# 65 "data/maps/BattleFrontier_Lounge2/scripts.pory"

# 66 "data/maps/BattleFrontier_Lounge2/scripts.pory"
BattleFrontier_Lounge2_EventScript_BufferMultiLink::
# 67 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	bufferstdstring STR_VAR_1, STDSTRING_MULTI_LINK
# 68 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	return
# 69 "data/maps/BattleFrontier_Lounge2/scripts.pory"

# 70 "data/maps/BattleFrontier_Lounge2/scripts.pory"
BattleFrontier_Lounge2_EventScript_BufferBattleDome::
# 71 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_DOME
# 72 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	return
# 73 "data/maps/BattleFrontier_Lounge2/scripts.pory"

# 74 "data/maps/BattleFrontier_Lounge2/scripts.pory"
BattleFrontier_Lounge2_EventScript_BufferBattleFactory::
# 75 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_FACTORY
# 76 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	return
# 77 "data/maps/BattleFrontier_Lounge2/scripts.pory"

# 78 "data/maps/BattleFrontier_Lounge2/scripts.pory"
BattleFrontier_Lounge2_EventScript_BufferBattlePalace::
# 79 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_PALACE
# 80 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	return
# 81 "data/maps/BattleFrontier_Lounge2/scripts.pory"

# 82 "data/maps/BattleFrontier_Lounge2/scripts.pory"
BattleFrontier_Lounge2_EventScript_BufferBattleArena::
# 83 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_ARENA
# 84 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	return
# 85 "data/maps/BattleFrontier_Lounge2/scripts.pory"

# 86 "data/maps/BattleFrontier_Lounge2/scripts.pory"
BattleFrontier_Lounge2_EventScript_BufferBattlePike::
# 87 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_PIKE
# 88 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	return
# 89 "data/maps/BattleFrontier_Lounge2/scripts.pory"

# 90 "data/maps/BattleFrontier_Lounge2/scripts.pory"
BattleFrontier_Lounge2_EventScript_BufferBattlePyramid::
# 91 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_PYRAMID
# 92 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	return
# 93 "data/maps/BattleFrontier_Lounge2/scripts.pory"

# 94 "data/maps/BattleFrontier_Lounge2/scripts.pory"
BattleFrontier_Lounge2_EventScript_Maniac1::
# 95 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	lock
# 96 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	msgbox BattleFrontier_Lounge2_Text_NewsGatheringPower, MSGBOX_DEFAULT
# 97 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	release
# 98 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	end
# 99 "data/maps/BattleFrontier_Lounge2/scripts.pory"

# 100 "data/maps/BattleFrontier_Lounge2/scripts.pory"
BattleFrontier_Lounge2_EventScript_Maniac2::
# 101 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	lock
# 102 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	msgbox BattleFrontier_Lounge2_Text_AmazingPowersOfObservation, MSGBOX_DEFAULT
# 103 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	release
# 104 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	end
# 105 "data/maps/BattleFrontier_Lounge2/scripts.pory"

# 106 "data/maps/BattleFrontier_Lounge2/scripts.pory"
BattleFrontier_Lounge2_EventScript_Maniac3::
# 107 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	lock
# 108 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	msgbox BattleFrontier_Lounge2_Text_AmazingPowerOfPersuasion, MSGBOX_DEFAULT
# 109 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	release
# 110 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	end
# 111 "data/maps/BattleFrontier_Lounge2/scripts.pory"

# 112 "data/maps/BattleFrontier_Lounge2/scripts.pory"
BattleFrontier_Lounge2_EventScript_TriathleteF::
# 113 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	msgbox BattleFrontier_Lounge2_Text_ThisPlaceIsScaringMe, MSGBOX_NPC
# 114 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	end
# 115 "data/maps/BattleFrontier_Lounge2/scripts.pory"

# 116 "data/maps/BattleFrontier_Lounge2/scripts.pory"
BattleFrontier_Lounge2_Text_FrontierManiacIntro::
# 117 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "Howdy! When it comes to news about\n"
# 118 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "the BATTLE FRONTIER, I'm no. 1.\p"
# 119 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "You can think of me as\n"
# 120 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "the FRONTIER MANIAC.\p"
# 121 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "Just checking, but you are a TRAINER,\n"
# 122 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "isn't that right?\p"
# 123 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "I'll happily share the hottest news\n"
# 124 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "I gathered about the BATTLE FRONTIER.$"
# 125 "data/maps/BattleFrontier_Lounge2/scripts.pory"

# 126 "data/maps/BattleFrontier_Lounge2/scripts.pory"
BattleFrontier_Lounge2_Text_SwingByForTheLatestWord::
# 127 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "Howdy! Did you swing by to grill me\n"
# 128 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "about the latest word? Oh, all right!$"
# 129 "data/maps/BattleFrontier_Lounge2/scripts.pory"

# 130 "data/maps/BattleFrontier_Lounge2/scripts.pory"
@ Unused
# 131 "data/maps/BattleFrontier_Lounge2/scripts.pory"
BattleFrontier_Lounge2_Text_MyInformationsBeenUsefulRight::
# 132 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "Well? Well? Well?\p"
# 133 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "I'm sure my information's been\n"
# 134 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "seriously useful to you, right?$"
# 135 "data/maps/BattleFrontier_Lounge2/scripts.pory"

# 136 "data/maps/BattleFrontier_Lounge2/scripts.pory"
BattleFrontier_Lounge2_Text_FacilityIsHottest::
# 137 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "Let's see now…\p"
# 138 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "It sounds like the {STR_VAR_1}\n"
# 139 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "is the hottest place going.$"
# 140 "data/maps/BattleFrontier_Lounge2/scripts.pory"

# 141 "data/maps/BattleFrontier_Lounge2/scripts.pory"
BattleFrontier_Lounge2_Text_BattleTowerIsHottest::
# 142 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "Let's see now…\p"
# 143 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "It sounds like BATTLE TOWER\n"
# 144 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "{STR_VAR_1} is the hottest.$"
# 145 "data/maps/BattleFrontier_Lounge2/scripts.pory"

# 146 "data/maps/BattleFrontier_Lounge2/scripts.pory"
BattleFrontier_Lounge2_Text_SalonMaidenIsThere::
# 147 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "Bet you didn't know this!\p"
# 148 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "One of those top TRAINERS that SCOTT\n"
# 149 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "calls the FRONTIER BRAINS is there.\p"
# 150 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "It's this mysterious TRAINER called\n"
# 151 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "the SALON MAIDEN that runs the place.$"
# 152 "data/maps/BattleFrontier_Lounge2/scripts.pory"

# 153 "data/maps/BattleFrontier_Lounge2/scripts.pory"
BattleFrontier_Lounge2_Text_SalonMaidenSilverMons::
# 154 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "Have you battled the SALON MAIDEN?\p"
# 155 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "When she's measuring up her opponent,\n"
# 156 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "she apparently uses these POKéMON:\p"
# 157 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "A PSYCHIC-type PSI POKéMON,\n"
# 158 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "a FIRE-type VOLCANO POKéMON,\l"
# 159 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "and a NORMAL-type SLEEPING POKéMON.$"
# 160 "data/maps/BattleFrontier_Lounge2/scripts.pory"

# 161 "data/maps/BattleFrontier_Lounge2/scripts.pory"
BattleFrontier_Lounge2_Text_SalonMaidenGoldMons::
# 162 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "Have you battled the SALON MAIDEN\n"
# 163 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "when she's serious?\p"
# 164 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "When she's battling flat out,\n"
# 165 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "she apparently uses these POKéMON:\p"
# 166 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "A DRAGON & PSYCHIC EON POKéMON,\n"
# 167 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "an ELECTRIC-type THUNDER POKéMON,\l"
# 168 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "and a NORMAL-type SLEEPING POKéMON.$"
# 169 "data/maps/BattleFrontier_Lounge2/scripts.pory"

# 170 "data/maps/BattleFrontier_Lounge2/scripts.pory"
BattleFrontier_Lounge2_Text_DomeAceIsThere::
# 171 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "Bet you didn't know this!\p"
# 172 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "One of those top TRAINERS that SCOTT\n"
# 173 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "calls the FRONTIER BRAINS is there.\p"
# 174 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "It's this flamboyant TRAINER called\n"
# 175 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "the DOME ACE that runs the place.$"
# 176 "data/maps/BattleFrontier_Lounge2/scripts.pory"

# 177 "data/maps/BattleFrontier_Lounge2/scripts.pory"
BattleFrontier_Lounge2_Text_DomeAceSilverMons::
# 178 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "Have you battled the DOME ACE?\p"
# 179 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "When he's treating the opponent\n"
# 180 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "lightly, he uses these three POKéMON:\p"
# 181 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "A DRAGON & FLYING DRAGON POKéMON,\n"
# 182 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "a WATER & GROUND MUD FISH POKéMON,\l"
# 183 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "and a FIRE & FLYING FLAME POKéMON.$"
# 184 "data/maps/BattleFrontier_Lounge2/scripts.pory"

# 185 "data/maps/BattleFrontier_Lounge2/scripts.pory"
BattleFrontier_Lounge2_Text_DomeAceGoldMons::
# 186 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "Have you battled the DOME ACE\n"
# 187 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "when he's serious?\p"
# 188 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "When he's demonstrating his strategy,\n"
# 189 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "he uses these three POKéMON:\p"
# 190 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "A DRAGON & FLYING EON POKéMON,\n"
# 191 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "a WATER & GROUND MUD FISH POKéMON,\l"
# 192 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "and a STEEL- & PSYCHIC-type IRON LEG\l"
# 193 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "POKéMON.$"
# 194 "data/maps/BattleFrontier_Lounge2/scripts.pory"

# 195 "data/maps/BattleFrontier_Lounge2/scripts.pory"
BattleFrontier_Lounge2_Text_FactoryHeadIsThere::
# 196 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "Bet you didn't know this!\p"
# 197 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "One of those top TRAINERS that SCOTT\n"
# 198 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "calls the FRONTIER BRAINS is there.\p"
# 199 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "It's this freaky TRAINER called\n"
# 200 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "the FACTORY HEAD that runs the place.$"
# 201 "data/maps/BattleFrontier_Lounge2/scripts.pory"

# 202 "data/maps/BattleFrontier_Lounge2/scripts.pory"
BattleFrontier_Lounge2_Text_FactoryHeadSilverMons::
# 203 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "Have you battled the FACTORY HEAD\n"
# 204 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "already?\p"
# 205 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "Let me think… When he goes to battle,\n"
# 206 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "he just gets three rental POKéMON.\p"
# 207 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "He battles under pretty much the same\n"
# 208 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "conditions as you.$"
# 209 "data/maps/BattleFrontier_Lounge2/scripts.pory"

# 210 "data/maps/BattleFrontier_Lounge2/scripts.pory"
BattleFrontier_Lounge2_Text_FactoryHeadGoldMons::
# 211 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "Have you battled the FACTORY HEAD\n"
# 212 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "when he's serious?\p"
# 213 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "When he goes seriously to battle,\n"
# 214 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "he still gets three rental POKéMON.\p"
# 215 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "He battles under virtually the same\n"
# 216 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "conditions as you.$"
# 217 "data/maps/BattleFrontier_Lounge2/scripts.pory"

# 218 "data/maps/BattleFrontier_Lounge2/scripts.pory"
BattleFrontier_Lounge2_Text_PikeQueenIsThere::
# 219 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "Bet you didn't know this!\p"
# 220 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "One of those top TRAINERS that SCOTT\n"
# 221 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "calls the FRONTIER BRAINS is there.\p"
# 222 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "It's this scary TRAINER called\n"
# 223 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "the PIKE QUEEN that runs the place.$"
# 224 "data/maps/BattleFrontier_Lounge2/scripts.pory"

# 225 "data/maps/BattleFrontier_Lounge2/scripts.pory"
BattleFrontier_Lounge2_Text_PikeQueenSilverMons::
# 226 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "Have you battled the PIKE QUEEN\n"
# 227 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "before?\p"
# 228 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "When she's in a good mood, they say\n"
# 229 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "she uses these three POKéMON:\p"
# 230 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "A POISON-type FANG SNAKE POKéMON,\n"
# 231 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "a BUG & ROCK MOLD POKéMON,\l"
# 232 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "and a WATER-type TENDER POKéMON.$"
# 233 "data/maps/BattleFrontier_Lounge2/scripts.pory"

# 234 "data/maps/BattleFrontier_Lounge2/scripts.pory"
BattleFrontier_Lounge2_Text_PikeQueenGoldMons::
# 235 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "Have you battled the PIKE QUEEN\n"
# 236 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "when she's serious?\p"
# 237 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "When she's seriously annoyed, they say\n"
# 238 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "she uses these three POKéMON:\p"
# 239 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "A POISON-type FANG SNAKE POKéMON,\n"
# 240 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "a STEEL & GROUND IRON SNAKE POKéMON,\l"
# 241 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "and a WATER- & FLYING-type ATROCIOUS\l"
# 242 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "POKéMON.$"
# 243 "data/maps/BattleFrontier_Lounge2/scripts.pory"

# 244 "data/maps/BattleFrontier_Lounge2/scripts.pory"
BattleFrontier_Lounge2_Text_ArenaTycoonIsThere::
# 245 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "Bet you didn't know this!\p"
# 246 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "One of those top TRAINERS that SCOTT\n"
# 247 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "calls the FRONTIER BRAINS is there.\p"
# 248 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "It's this cute TRAINER called\n"
# 249 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "the ARENA TYCOON that runs the place.$"
# 250 "data/maps/BattleFrontier_Lounge2/scripts.pory"

# 251 "data/maps/BattleFrontier_Lounge2/scripts.pory"
BattleFrontier_Lounge2_Text_ArenaTycoonSilverMons::
# 252 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "Have you battled the ARENA TYCOON\n"
# 253 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "before?\p"
# 254 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "When she's assessing the foe's ability,\n"
# 255 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "she supposedly uses these POKéMON:\p"
# 256 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "A BUG & FIGHTING SINGLE HORN POKéMON,\n"
# 257 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "a DARK-type MOONLIGHT POKéMON,\l"
# 258 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "and a BUG & GHOST SHED POKéMON.$"
# 259 "data/maps/BattleFrontier_Lounge2/scripts.pory"

# 260 "data/maps/BattleFrontier_Lounge2/scripts.pory"
BattleFrontier_Lounge2_Text_ArenaTycoonGoldMons::
# 261 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "Have you battled the ARENA TYCOON\n"
# 262 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "when she's serious?\p"
# 263 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "When she battles for keeps,\n"
# 264 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "she supposedly uses these POKéMON:\p"
# 265 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "A DARK-type MOONLIGHT POKéMON,\n"
# 266 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "a GHOST & POISON SHADOW POKéMON\l"
# 267 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "and a GRASS- & FIGHTING-type\l"
# 268 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "MUSHROOM POKéMON.$"
# 269 "data/maps/BattleFrontier_Lounge2/scripts.pory"

# 270 "data/maps/BattleFrontier_Lounge2/scripts.pory"
BattleFrontier_Lounge2_Text_PalaceMavenIsThere::
# 271 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "Bet you didn't know this!\p"
# 272 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "One of those top TRAINERS that SCOTT\n"
# 273 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "calls the FRONTIER BRAINS is there.\p"
# 274 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "It's this sinister TRAINER called\n"
# 275 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "the PALACE MAVEN that runs the place.$"
# 276 "data/maps/BattleFrontier_Lounge2/scripts.pory"

# 277 "data/maps/BattleFrontier_Lounge2/scripts.pory"
BattleFrontier_Lounge2_Text_PalaceMavenSilverMons::
# 278 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "Have you battled the PALACE MAVEN\n"
# 279 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "before?\p"
# 280 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "When he's testing the opponent's\n"
# 281 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "spirit, he's said to use these POKéMON:\p"
# 282 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "A POISON & FLYING-type BAT POKéMON,\n"
# 283 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "a NORMAL-type LAZY POKéMON, and a\l"
# 284 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "WATER- & ICE-type TRANSPORT POKéMON.$"
# 285 "data/maps/BattleFrontier_Lounge2/scripts.pory"

# 286 "data/maps/BattleFrontier_Lounge2/scripts.pory"
BattleFrontier_Lounge2_Text_PalaceMavenGoldMons::
# 287 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "Have you battled the PALACE MAVEN\n"
# 288 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "when he's serious?\p"
# 289 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "When he throws his entire might into\n"
# 290 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "battle, he's said to use these POKéMON:\p"
# 291 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "A FIRE-type LEGENDARY POKéMON,\n"
# 292 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "a NORMAL-type LAZY POKéMON,\l"
# 293 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "and a WATER-type AURORA POKéMON.$"
# 294 "data/maps/BattleFrontier_Lounge2/scripts.pory"

# 295 "data/maps/BattleFrontier_Lounge2/scripts.pory"
BattleFrontier_Lounge2_Text_PyramidKingIsThere::
# 296 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "Bet you didn't know this!\p"
# 297 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "One of those top TRAINERS that SCOTT\n"
# 298 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "calls the FRONTIER BRAINS is there.\p"
# 299 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "It's this fiery-hot TRAINER called\n"
# 300 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "the PYRAMID KING that runs the place.$"
# 301 "data/maps/BattleFrontier_Lounge2/scripts.pory"

# 302 "data/maps/BattleFrontier_Lounge2/scripts.pory"
BattleFrontier_Lounge2_Text_PyramidKingSilverMons::
# 303 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "Have you battled the PYRAMID KING\n"
# 304 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "before?\p"
# 305 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "When he's checking the foe's power,\n"
# 306 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "he apparently uses these POKéMON:\p"
# 307 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "A ROCK-type ROCK PEAK POKéMON,\n"
# 308 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "an ICE-type ICEBERG POKéMON,\l"
# 309 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "and a STEEL-type IRON POKéMON.$"
# 310 "data/maps/BattleFrontier_Lounge2/scripts.pory"

# 311 "data/maps/BattleFrontier_Lounge2/scripts.pory"
BattleFrontier_Lounge2_Text_PyramidKingGoldMons::
# 312 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "Have you battled the PYRAMID KING\n"
# 313 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "when he's serious?\p"
# 314 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "When he's pumped with hot power,\n"
# 315 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "he apparently uses these POKéMON:\p"
# 316 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "An ICE & FLYING FREEZE POKéMON, an\n"
# 317 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "ELECTRIC & FLYING ELECTRIC POKéMON,\l"
# 318 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "and a FIRE- & FLYING-type FLAME\l"
# 319 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "POKéMON.$"
# 320 "data/maps/BattleFrontier_Lounge2/scripts.pory"

# 321 "data/maps/BattleFrontier_Lounge2/scripts.pory"
BattleFrontier_Lounge2_Text_DoubleBattleAdvice1::
# 322 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "Sure, there are several places where\n"
# 323 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "you can enter DOUBLE BATTLES.\p"
# 324 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "But the DOUBLE BATTLE ROOMS of\n"
# 325 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "the BATTLE TOWER are, like, basic!\p"
# 326 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "They're where you should learn about\n"
# 327 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "how DOUBLE BATTLES are played here\l"
# 328 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "in the BATTLE FRONTIER.$"
# 329 "data/maps/BattleFrontier_Lounge2/scripts.pory"

# 330 "data/maps/BattleFrontier_Lounge2/scripts.pory"
BattleFrontier_Lounge2_Text_DoubleBattleAdvice2::
# 331 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "Watch yourself in the battles here.\p"
# 332 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "I hear there are TRAINERS that have\n"
# 333 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "strategies they developed just for\l"
# 334 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "DOUBLE BATTLES.$"
# 335 "data/maps/BattleFrontier_Lounge2/scripts.pory"

# 336 "data/maps/BattleFrontier_Lounge2/scripts.pory"
BattleFrontier_Lounge2_Text_DoubleBattleAdvice3::
# 337 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "Once you're confident and comfortable\n"
# 338 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "with DOUBLE BATTLES here, you should\l"
# 339 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "think about challenging other places\l"
# 340 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "offering DOUBLE BATTLES.$"
# 341 "data/maps/BattleFrontier_Lounge2/scripts.pory"

# 342 "data/maps/BattleFrontier_Lounge2/scripts.pory"
BattleFrontier_Lounge2_Text_MultiBattleAdvice::
# 343 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "All sorts of TRAINERS gather in\n"
# 344 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "the BATTLE SALON.\p"
# 345 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "Just think--you may run into your\n"
# 346 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "friends or followers!\l"
# 347 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "You should look carefully!$"
# 348 "data/maps/BattleFrontier_Lounge2/scripts.pory"

# 349 "data/maps/BattleFrontier_Lounge2/scripts.pory"
BattleFrontier_Lounge2_Text_LinkMultiBattleAdvice::
# 350 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "If you're with a friend, head for the\n"
# 351 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "LINK MULTI BATTLE ROOM.\p"
# 352 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "If you play with a strong friend,\n"
# 353 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "you can expect to see tough foes!$"
# 354 "data/maps/BattleFrontier_Lounge2/scripts.pory"

# 355 "data/maps/BattleFrontier_Lounge2/scripts.pory"
BattleFrontier_Lounge2_Text_NewsGatheringPower::
# 356 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "What amazing news-gathering power!\n"
# 357 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "My mentor's like none other!$"
# 358 "data/maps/BattleFrontier_Lounge2/scripts.pory"

# 359 "data/maps/BattleFrontier_Lounge2/scripts.pory"
BattleFrontier_Lounge2_Text_AmazingPowersOfObservation::
# 360 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "What amazing powers of observation!\n"
# 361 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "My mentor's like none other!$"
# 362 "data/maps/BattleFrontier_Lounge2/scripts.pory"

# 363 "data/maps/BattleFrontier_Lounge2/scripts.pory"
BattleFrontier_Lounge2_Text_AmazingPowerOfPersuasion::
# 364 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "What amazing power of persuasion!\n"
# 365 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "My mentor's like none other!$"
# 366 "data/maps/BattleFrontier_Lounge2/scripts.pory"

# 367 "data/maps/BattleFrontier_Lounge2/scripts.pory"
BattleFrontier_Lounge2_Text_ThisPlaceIsScaringMe::
# 368 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "…What is this place?\n"
# 369 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "It's scaring me…$"
