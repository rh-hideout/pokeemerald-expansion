# 1 "data/maps/LilycoveCity_ContestHall/scripts.pory"

# 2 "data/maps/LilycoveCity_ContestHall/scripts.pory"
@ All the LOCALID constants used in this file are essentially redundant.
# 3 "data/maps/LilycoveCity_ContestHall/scripts.pory"
@ They're all used to have the NPC the player talked to turn back so they're facing
# 4 "data/maps/LilycoveCity_ContestHall/scripts.pory"
@ their original direction (because they're watching/participating in the contests).
# 5 "data/maps/LilycoveCity_ContestHall/scripts.pory"
@ They could all be substituted for VAR_LAST_TALKED.
# 6 "data/maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_MapScripts::
# 7 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	.byte 0
# 8 "data/maps/LilycoveCity_ContestHall/scripts.pory"

# 9 "data/maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_EventScript_Boy1::
# 10 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	msgbox LilycoveCity_ContestHall_Text_TodayWonSmartnessContest, MSGBOX_NPC
# 11 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	end
# 12 "data/maps/LilycoveCity_ContestHall/scripts.pory"

# 13 "data/maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_EventScript_Boy2::
# 14 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	msgbox LilycoveCity_ContestHall_Text_EnteredBunchOfContests, MSGBOX_NPC
# 15 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	end
# 16 "data/maps/LilycoveCity_ContestHall/scripts.pory"

# 17 "data/maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_EventScript_Girl::
# 18 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	msgbox LilycoveCity_ContestHall_Text_ManWhoWonEarlierHadPokeblocks, MSGBOX_NPC
# 19 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	end
# 20 "data/maps/LilycoveCity_ContestHall/scripts.pory"

# 21 "data/maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_EventScript_Sailor::
# 22 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	msgbox LilycoveCity_ContestHall_Text_IsntThisPlaceHumongous, MSGBOX_NPC
# 23 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	end
# 24 "data/maps/LilycoveCity_ContestHall/scripts.pory"

# 25 "data/maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_EventScript_SmartContestMC::
# 26 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	lock
# 27 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	faceplayer
# 28 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	msgbox LilycoveCity_ContestHall_Text_GiveItBestSmartAppeal, MSGBOX_DEFAULT
# 29 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	closemessage
# 30 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	applymovement LOCALID_SMART_MC, Common_Movement_FaceOriginalDirection
# 31 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	waitmovement 0
# 32 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	release
# 33 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	end
# 34 "data/maps/LilycoveCity_ContestHall/scripts.pory"

# 35 "data/maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_EventScript_SmartContestJudge::
# 36 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	lock
# 37 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	faceplayer
# 38 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	msgbox LilycoveCity_ContestHall_Text_AreYouEnjoyingThisContest, MSGBOX_DEFAULT
# 39 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	closemessage
# 40 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	applymovement LOCALID_SMART_JUDGE, Common_Movement_FaceOriginalDirection
# 41 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	waitmovement 0
# 42 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	release
# 43 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	end
# 44 "data/maps/LilycoveCity_ContestHall/scripts.pory"

# 45 "data/maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_EventScript_SmartContestant1::
# 46 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	lock
# 47 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	faceplayer
# 48 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	msgbox LilycoveCity_ContestHall_Text_EnteredWrongContest, MSGBOX_DEFAULT
# 49 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	closemessage
# 50 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	applymovement LOCALID_SMART_CONTESTANT_1, Common_Movement_FaceOriginalDirection
# 51 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	waitmovement 0
# 52 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	release
# 53 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	end
# 54 "data/maps/LilycoveCity_ContestHall/scripts.pory"

# 55 "data/maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_EventScript_SmartContestant2::
# 56 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	lock
# 57 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	faceplayer
# 58 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	msgbox LilycoveCity_ContestHall_Text_RaisedMonToBeSmart, MSGBOX_DEFAULT
# 59 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	closemessage
# 60 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	applymovement LOCALID_SMART_CONTESTANT_2, Common_Movement_FaceOriginalDirection
# 61 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	waitmovement 0
# 62 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	release
# 63 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	end
# 64 "data/maps/LilycoveCity_ContestHall/scripts.pory"

# 65 "data/maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_EventScript_SmartContestant3::
# 66 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	lock
# 67 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	faceplayer
# 68 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	msgbox LilycoveCity_ContestHall_Text_IfMonPullsSmartMoveNext, MSGBOX_DEFAULT
# 69 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	closemessage
# 70 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	applymovement LOCALID_SMART_CONTESTANT_3, Common_Movement_FaceOriginalDirection
# 71 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	waitmovement 0
# 72 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	release
# 73 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	end
# 74 "data/maps/LilycoveCity_ContestHall/scripts.pory"

# 75 "data/maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_EventScript_SmartContestant4::
# 76 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	lock
# 77 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	faceplayer
# 78 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	msgbox LilycoveCity_ContestHall_Text_DontAppreciateCuteLeechLife, MSGBOX_DEFAULT
# 79 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	closemessage
# 80 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	applymovement LOCALID_SMART_CONTESTANT_4, Common_Movement_FaceOriginalDirection
# 81 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	waitmovement 0
# 82 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	release
# 83 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	end
# 84 "data/maps/LilycoveCity_ContestHall/scripts.pory"

# 85 "data/maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_EventScript_SmartContestAudience1::
# 86 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	msgbox LilycoveCity_ContestHall_Text_YoureBeautifulGrandpa, MSGBOX_SIGN
# 87 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	end
# 88 "data/maps/LilycoveCity_ContestHall/scripts.pory"

# 89 "data/maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_EventScript_SmartContestAudience2::
# 90 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	lock
# 91 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	faceplayer
# 92 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	msgbox LilycoveCity_ContestHall_Text_AllSeemToUseDifferentMoves, MSGBOX_DEFAULT
# 93 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	closemessage
# 94 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	applymovement LOCALID_SMART_AUDIENCE_2, Common_Movement_FaceOriginalDirection
# 95 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	waitmovement 0
# 96 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	release
# 97 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	end
# 98 "data/maps/LilycoveCity_ContestHall/scripts.pory"

# 99 "data/maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_EventScript_SmartContestAudience3::
# 100 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	lock
# 101 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	faceplayer
# 102 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	msgbox LilycoveCity_ContestHall_Text_PokemonSmarterThanTrainers, MSGBOX_DEFAULT
# 103 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	closemessage
# 104 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	applymovement LOCALID_SMART_AUDIENCE_3, Common_Movement_FaceOriginalDirection
# 105 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	waitmovement 0
# 106 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	release
# 107 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	end
# 108 "data/maps/LilycoveCity_ContestHall/scripts.pory"

# 109 "data/maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_EventScript_SmartContestAudience4::
# 110 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	lock
# 111 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	faceplayer
# 112 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	msgbox LilycoveCity_ContestHall_Text_StillLoveSmartnessContests, MSGBOX_DEFAULT
# 113 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	closemessage
# 114 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	applymovement LOCALID_SMART_AUDIENCE_4, Common_Movement_FaceOriginalDirection
# 115 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	waitmovement 0
# 116 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	release
# 117 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	end
# 118 "data/maps/LilycoveCity_ContestHall/scripts.pory"

# 119 "data/maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_EventScript_BeautyContestMC::
# 120 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	lock
# 121 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	faceplayer
# 122 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	msgbox LilycoveCity_ContestHall_Text_AreYouEnteringBeautyContest, MSGBOX_DEFAULT
# 123 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	closemessage
# 124 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	applymovement LOCALID_BEAUTY_MC, Common_Movement_FaceOriginalDirection
# 125 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	waitmovement 0
# 126 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	release
# 127 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	end
# 128 "data/maps/LilycoveCity_ContestHall/scripts.pory"

# 129 "data/maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_EventScript_BeautyContestJudge::
# 130 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	lock
# 131 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	faceplayer
# 132 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	msgbox LilycoveCity_ContestHall_Text_EveryPokemonPristineBeauty, MSGBOX_DEFAULT
# 133 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	closemessage
# 134 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	applymovement LOCALID_BEAUTY_JUDGE, Common_Movement_FaceOriginalDirection
# 135 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	waitmovement 0
# 136 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	release
# 137 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	end
# 138 "data/maps/LilycoveCity_ContestHall/scripts.pory"

# 139 "data/maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_EventScript_BeautyContestant1::
# 140 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	lock
# 141 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	faceplayer
# 142 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	msgbox LilycoveCity_ContestHall_Text_EyesWillBeGluedToMyBeauty, MSGBOX_DEFAULT
# 143 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	closemessage
# 144 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	applymovement LOCALID_BEAUTY_CONTESTANT_1, Common_Movement_FaceOriginalDirection
# 145 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	waitmovement 0
# 146 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	release
# 147 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	end
# 148 "data/maps/LilycoveCity_ContestHall/scripts.pory"

# 149 "data/maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_EventScript_BeautyContestant2::
# 150 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	lock
# 151 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	faceplayer
# 152 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	msgbox LilycoveCity_ContestHall_Text_OverdidGrooming, MSGBOX_DEFAULT
# 153 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	closemessage
# 154 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	applymovement LOCALID_BEAUTY_CONTESTANT_2, Common_Movement_FaceOriginalDirection
# 155 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	waitmovement 0
# 156 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	release
# 157 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	end
# 158 "data/maps/LilycoveCity_ContestHall/scripts.pory"

# 159 "data/maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_EventScript_BeautyContestant3::
# 160 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	lock
# 161 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	faceplayer
# 162 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	msgbox LilycoveCity_ContestHall_Text_JudgeWontSeeAuroraBeam, MSGBOX_DEFAULT
# 163 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	closemessage
# 164 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	applymovement LOCALID_BEAUTY_CONTESTANT_3, Common_Movement_FaceOriginalDirection
# 165 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	waitmovement 0
# 166 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	release
# 167 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	end
# 168 "data/maps/LilycoveCity_ContestHall/scripts.pory"

# 169 "data/maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_EventScript_BeautyContestant4::
# 170 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	lock
# 171 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	faceplayer
# 172 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	msgbox LilycoveCity_ContestHall_Text_PokemonLooksLikeYoungerMe, MSGBOX_DEFAULT
# 173 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	closemessage
# 174 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	applymovement LOCALID_BEAUTY_CONTESTANT_4, Common_Movement_FaceOriginalDirection
# 175 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	waitmovement 0
# 176 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	release
# 177 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	end
# 178 "data/maps/LilycoveCity_ContestHall/scripts.pory"

# 179 "data/maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_EventScript_BeautyContestAudience1::
# 180 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	lock
# 181 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	faceplayer
# 182 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	msgbox LilycoveCity_ContestHall_Text_WinBeautyContestMakesMeHappy, MSGBOX_DEFAULT
# 183 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	closemessage
# 184 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	applymovement LOCALID_BEAUTY_AUDIENCE_1, Common_Movement_FaceOriginalDirection
# 185 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	waitmovement 0
# 186 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	release
# 187 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	end
# 188 "data/maps/LilycoveCity_ContestHall/scripts.pory"

# 189 "data/maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_EventScript_BeautyContestAudience2::
# 190 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	lock
# 191 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	faceplayer
# 192 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	msgbox LilycoveCity_ContestHall_Text_GanderAtAllThosePrettyPokemon, MSGBOX_DEFAULT
# 193 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	closemessage
# 194 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	applymovement LOCALID_BEAUTY_AUDIENCE_2, Common_Movement_FaceOriginalDirection
# 195 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	waitmovement 0
# 196 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	release
# 197 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	end
# 198 "data/maps/LilycoveCity_ContestHall/scripts.pory"

# 199 "data/maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_EventScript_BeautyContestAudience3::
# 200 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	lock
# 201 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	faceplayer
# 202 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	msgbox LilycoveCity_ContestHall_Text_CantWinOnBeautyAlone, MSGBOX_DEFAULT
# 203 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	closemessage
# 204 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	applymovement LOCALID_BEAUTY_AUDIENCE_3, Common_Movement_FaceOriginalDirection
# 205 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	waitmovement 0
# 206 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	release
# 207 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	end
# 208 "data/maps/LilycoveCity_ContestHall/scripts.pory"

# 209 "data/maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_EventScript_CuteContestMC::
# 210 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	lock
# 211 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	faceplayer
# 212 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	msgbox LilycoveCity_ContestHall_Text_InTheMiddleOfContest, MSGBOX_DEFAULT
# 213 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	closemessage
# 214 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	applymovement LOCALID_CUTE_MC, Common_Movement_FaceOriginalDirection
# 215 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	waitmovement 0
# 216 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	release
# 217 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	end
# 218 "data/maps/LilycoveCity_ContestHall/scripts.pory"

# 219 "data/maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_EventScript_CuteContestJudge::
# 220 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	lock
# 221 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	faceplayer
# 222 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	msgbox LilycoveCity_ContestHall_Text_SuchCharmingCuteAppeals, MSGBOX_DEFAULT
# 223 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	closemessage
# 224 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	applymovement LOCALID_CUTE_JUDGE, Common_Movement_FaceOriginalDirection
# 225 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	waitmovement 0
# 226 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	release
# 227 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	end
# 228 "data/maps/LilycoveCity_ContestHall/scripts.pory"

# 229 "data/maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_EventScript_CuteContestant1::
# 230 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	lock
# 231 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	faceplayer
# 232 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	msgbox LilycoveCity_ContestHall_Text_MyAzurillWasDistracted, MSGBOX_DEFAULT
# 233 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	closemessage
# 234 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	applymovement LOCALID_CUTE_CONTESTANT_1, Common_Movement_FaceOriginalDirection
# 235 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	waitmovement 0
# 236 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	release
# 237 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	end
# 238 "data/maps/LilycoveCity_ContestHall/scripts.pory"

# 239 "data/maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_EventScript_CuteContestant2::
# 240 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	lock
# 241 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	faceplayer
# 242 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	msgbox LilycoveCity_ContestHall_Text_NeverWonBattleButContest, MSGBOX_DEFAULT
# 243 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	closemessage
# 244 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	applymovement LOCALID_CUTE_CONTESTANT_2, Common_Movement_FaceOriginalDirection
# 245 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	waitmovement 0
# 246 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	release
# 247 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	end
# 248 "data/maps/LilycoveCity_ContestHall/scripts.pory"

# 249 "data/maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_EventScript_CuteContestant3::
# 250 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	lock
# 251 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	faceplayer
# 252 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	msgbox LilycoveCity_ContestHall_Text_PetalDanceIsMarvel, MSGBOX_DEFAULT
# 253 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	closemessage
# 254 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	applymovement LOCALID_CUTE_CONTESTANT_3, Common_Movement_FaceOriginalDirection
# 255 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	waitmovement 0
# 256 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	release
# 257 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	end
# 258 "data/maps/LilycoveCity_ContestHall/scripts.pory"

# 259 "data/maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_EventScript_CuteContestant4::
# 260 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	lock
# 261 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	faceplayer
# 262 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	msgbox LilycoveCity_ContestHall_Text_MyMonAppealSoMuchCuter, MSGBOX_DEFAULT
# 263 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	closemessage
# 264 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	applymovement LOCALID_CUTE_CONTESTANT_4, Common_Movement_FaceOriginalDirection
# 265 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	waitmovement 0
# 266 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	release
# 267 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	end
# 268 "data/maps/LilycoveCity_ContestHall/scripts.pory"

# 269 "data/maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_EventScript_CuteContestAudience1::
# 270 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	lockall
# 271 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	applymovement LOCALID_CUTE_AUDIENCE_1, Common_Movement_FacePlayer
# 272 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	waitmovement 0
# 273 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	msgbox LilycoveCity_ContestHall_Text_MyChildIsInContest, MSGBOX_DEFAULT
# 274 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	closemessage
# 275 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	applymovement LOCALID_CUTE_AUDIENCE_1, Common_Movement_FaceOriginalDirection
# 276 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	waitmovement 0
# 277 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	delay 25
# 278 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	msgbox LilycoveCity_ContestHall_Text_ComeOnDear, MSGBOX_DEFAULT
# 279 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	releaseall
# 280 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	end
# 281 "data/maps/LilycoveCity_ContestHall/scripts.pory"

# 282 "data/maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_EventScript_CuteContestAudience2::
# 283 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	lock
# 284 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	faceplayer
# 285 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	msgbox LilycoveCity_ContestHall_Text_WantCuteMonOfMyOwn, MSGBOX_DEFAULT
# 286 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	closemessage
# 287 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	applymovement LOCALID_CUTE_AUDIENCE_2, Common_Movement_FaceOriginalDirection
# 288 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	waitmovement 0
# 289 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	release
# 290 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	end
# 291 "data/maps/LilycoveCity_ContestHall/scripts.pory"

# 292 "data/maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_EventScript_CuteContestAudience3::
# 293 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	lock
# 294 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	faceplayer
# 295 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	msgbox LilycoveCity_ContestHall_Text_ThatGirlThereIsCutest, MSGBOX_DEFAULT
# 296 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	closemessage
# 297 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	applymovement LOCALID_CUTE_AUDIENCE_3, Common_Movement_FaceOriginalDirection
# 298 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	waitmovement 0
# 299 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	release
# 300 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	end
# 301 "data/maps/LilycoveCity_ContestHall/scripts.pory"

# 302 "data/maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_EventScript_BeautyStageSign::
# 303 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	msgbox LilycoveCity_ContestHall_Text_BeautyContestStage, MSGBOX_SIGN
# 304 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	end
# 305 "data/maps/LilycoveCity_ContestHall/scripts.pory"

# 306 "data/maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_EventScript_CuteStageSign::
# 307 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	msgbox LilycoveCity_ContestHall_Text_CuteContestStage, MSGBOX_SIGN
# 308 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	end
# 309 "data/maps/LilycoveCity_ContestHall/scripts.pory"

# 310 "data/maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_EventScript_SmartStageSign::
# 311 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	msgbox LilycoveCity_ContestHall_Text_SmartContestStage, MSGBOX_SIGN
# 312 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	end
# 313 "data/maps/LilycoveCity_ContestHall/scripts.pory"

# 314 "data/maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_Text_TodayWonSmartnessContest:
# 315 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	.string "This POKéMON won the BEAUTY CONTEST\n"
# 316 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	.string "here before.\p"
# 317 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	.string "Well, guess what? Today, I made it\n"
# 318 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	.string "win a SMARTNESS CONTEST!\p"
# 319 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	.string "My abilities scare even me…$"
# 320 "data/maps/LilycoveCity_ContestHall/scripts.pory"

# 321 "data/maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_Text_EnteredBunchOfContests:
# 322 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	.string "I've entered a bunch of CONTESTS,\n"
# 323 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	.string "so I'm seeing how things work.\p"
# 324 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	.string "If you're in a COOLNESS CONTEST,\n"
# 325 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	.string "cool moves go over as appeals.\p"
# 326 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	.string "But smart moves and cute moves\n"
# 327 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	.string "don't go over well, for instance.$"
# 328 "data/maps/LilycoveCity_ContestHall/scripts.pory"

# 329 "data/maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_Text_ManWhoWonEarlierHadPokeblocks:
# 330 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	.string "That young man who won earlier had\n"
# 331 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	.string "a whole bunch of different {POKEBLOCK}S.\p"
# 332 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	.string "Can you win if you had that many\n"
# 333 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	.string "of those things?$"
# 334 "data/maps/LilycoveCity_ContestHall/scripts.pory"

# 335 "data/maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_Text_IsntThisPlaceHumongous:
# 336 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	.string "Whoa, isn't this place humongous!\p"
# 337 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	.string "The tension in the air… It's not\n"
# 338 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	.string "like a CONTEST hall in the sticks.$"
# 339 "data/maps/LilycoveCity_ContestHall/scripts.pory"

# 340 "data/maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_Text_GiveItBestSmartAppeal:
# 341 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	.string "MC: Okay, SMART POKéMON and their\n"
# 342 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	.string "TRAINERS, are you ready?!\p"
# 343 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	.string "Give it your best showing!\n"
# 344 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	.string "Let's appeal!$"
# 345 "data/maps/LilycoveCity_ContestHall/scripts.pory"

# 346 "data/maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_Text_AreYouEnjoyingThisContest:
# 347 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	.string "JUDGE: Are you enjoying this CONTEST?\p"
# 348 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	.string "Come back with three friends, and\n"
# 349 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	.string "all of you may enter a CONTEST!$"
# 350 "data/maps/LilycoveCity_ContestHall/scripts.pory"

# 351 "data/maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_Text_EnteredWrongContest:
# 352 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	.string "Ayayayay…\n"
# 353 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	.string "I entered the wrong CONTEST.\p"
# 354 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	.string "I entered this tough POKéMON in\n"
# 355 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	.string "the SMARTNESS CONTEST…\p"
# 356 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	.string "Come on, wow them with a smart-looking\n"
# 357 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	.string "ROCK SMASH.$"
# 358 "data/maps/LilycoveCity_ContestHall/scripts.pory"

# 359 "data/maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_Text_RaisedMonToBeSmart:
# 360 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	.string "I've spent many a year, and all my\n"
# 361 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	.string "wisdom besides, raising this POKéMON\l"
# 362 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	.string "to be smart.\p"
# 363 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	.string "It won't be easily bested by some\n"
# 364 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	.string "young pup's POKéMON.\p"
# 365 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	.string "My dear wife, are you seeing this?$"
# 366 "data/maps/LilycoveCity_ContestHall/scripts.pory"

# 367 "data/maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_Text_IfMonPullsSmartMoveNext:
# 368 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	.string "There it is!\p"
# 369 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	.string "If my POKéMON pulls a smart move next,\n"
# 370 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	.string "the audience's excitement will peak!$"
# 371 "data/maps/LilycoveCity_ContestHall/scripts.pory"

# 372 "data/maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_Text_DontAppreciateCuteLeechLife:
# 373 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	.string "Oh, dear, no!\p"
# 374 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	.string "My darling ZUBAT's LEECH LIFE is so\n"
# 375 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	.string "cute I kept using it over and over!\p"
# 376 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	.string "But these mean people don't appreciate\n"
# 377 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	.string "it at all!$"
# 378 "data/maps/LilycoveCity_ContestHall/scripts.pory"

# 379 "data/maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_Text_YoureBeautifulGrandpa:
# 380 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	.string "Kiyaaah! You're beautiful, Grandpa!$"
# 381 "data/maps/LilycoveCity_ContestHall/scripts.pory"

# 382 "data/maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_Text_AllSeemToUseDifferentMoves:
# 383 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	.string "Even when TRAINERS enter the same\n"
# 384 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	.string "kind of POKéMON, they all seem to use\l"
# 385 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	.string "different moves for appeals.\p"
# 386 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	.string "It's just like the way people have\n"
# 387 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	.string "different styles for battling.$"
# 388 "data/maps/LilycoveCity_ContestHall/scripts.pory"

# 389 "data/maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_Text_PokemonSmarterThanTrainers:
# 390 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	.string "I think the POKéMON look smarter\n"
# 391 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	.string "than their TRAINERS. By a lot.$"
# 392 "data/maps/LilycoveCity_ContestHall/scripts.pory"

# 393 "data/maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_Text_StillLoveSmartnessContests:
# 394 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	.string "When all's said and done, I still love\n"
# 395 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	.string "SMARTNESS CONTESTS.\p"
# 396 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	.string "That intellectual green color…\n"
# 397 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	.string "It's so… So… Cool.$"
# 398 "data/maps/LilycoveCity_ContestHall/scripts.pory"

# 399 "data/maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_Text_AreYouEnteringBeautyContest:
# 400 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	.string "MC: Are you entering the BEAUTY\n"
# 401 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	.string "CONTEST, too? Good luck!$"
# 402 "data/maps/LilycoveCity_ContestHall/scripts.pory"

# 403 "data/maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_Text_EveryPokemonPristineBeauty:
# 404 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	.string "JUDGE: Ah, every POKéMON here is\n"
# 405 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	.string "a model of pristine beauty!\p"
# 406 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	.string "Why, I almost forgot to score them!$"
# 407 "data/maps/LilycoveCity_ContestHall/scripts.pory"

# 408 "data/maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_Text_EyesWillBeGluedToMyBeauty:
# 409 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	.string "A POKéMON this beautiful…\n"
# 410 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	.string "There isn't another one like it.\p"
# 411 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	.string "Everyone's eyes will be glued to\n"
# 412 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	.string "my beauty.$"
# 413 "data/maps/LilycoveCity_ContestHall/scripts.pory"

# 414 "data/maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_Text_OverdidGrooming:
# 415 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	.string "Waaaah!\p"
# 416 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	.string "I brushed and groomed my POKéMON\n"
# 417 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	.string "carefully for this CONTEST…\p"
# 418 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	.string "But I overdid it…\n"
# 419 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	.string "My POKéMON's coat turned all scraggly…\p"
# 420 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	.string "What should I do?$"
# 421 "data/maps/LilycoveCity_ContestHall/scripts.pory"

# 422 "data/maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_Text_JudgeWontSeeAuroraBeam:
# 423 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	.string "This AURORA BEAM is so dazzling,\n"
# 424 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	.string "the JUDGE won't be able to see it.\p"
# 425 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	.string "Uh, wait a second…\n"
# 426 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	.string "That'll be meaningless, then!$"
# 427 "data/maps/LilycoveCity_ContestHall/scripts.pory"

# 428 "data/maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_Text_PokemonLooksLikeYoungerMe:
# 429 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	.string "This pretty POKéMON looks just like\n"
# 430 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	.string "me when I was younger.\p"
# 431 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	.string "Right when I said that, my husband\n"
# 432 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	.string "spewed the coffee he was drinking.\p"
# 433 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	.string "Did I say something funny?$"
# 434 "data/maps/LilycoveCity_ContestHall/scripts.pory"

# 435 "data/maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_Text_WinBeautyContestMakesMeHappy:
# 436 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	.string "You know, if I win at a BEAUTY\n"
# 437 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	.string "CONTEST, sure it makes me\l"
# 438 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	.string "happy. More than usual, anyway.$"
# 439 "data/maps/LilycoveCity_ContestHall/scripts.pory"

# 440 "data/maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_Text_GanderAtAllThosePrettyPokemon:
# 441 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	.string "Wahahahah!\p"
# 442 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	.string "Will you take a gander at all those\n"
# 443 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	.string "pretty POKéMON!\l"
# 444 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	.string "I just love this sort of glitz!$"
# 445 "data/maps/LilycoveCity_ContestHall/scripts.pory"

# 446 "data/maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_Text_CantWinOnBeautyAlone:
# 447 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	.string "You can't always win on just beauty\n"
# 448 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	.string "alone.\p"
# 449 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	.string "You have to groom your POKéMON so\n"
# 450 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	.string "it's nice and glossy like mine.$"
# 451 "data/maps/LilycoveCity_ContestHall/scripts.pory"

# 452 "data/maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_Text_InTheMiddleOfContest:
# 453 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	.string "MC: Uh-oh! Hello!\n"
# 454 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	.string "We're in the middle of a CONTEST!\p"
# 455 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	.string "Please enter at our registration\n"
# 456 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	.string "counter and come out, okay?$"
# 457 "data/maps/LilycoveCity_ContestHall/scripts.pory"

# 458 "data/maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_Text_SuchCharmingCuteAppeals:
# 459 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	.string "JUDGE: Oh, such charming and cute\n"
# 460 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	.string "appeals!\p"
# 461 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	.string "Oh, my goodness! What a perfectly\n"
# 462 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	.string "adorable WATER SPORT appeal!$"
# 463 "data/maps/LilycoveCity_ContestHall/scripts.pory"

# 464 "data/maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_Text_MyAzurillWasDistracted:
# 465 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	.string "Oh, no… My sweet AZURILL was\n"
# 466 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	.string "distracted by another POKéMON.$"
# 467 "data/maps/LilycoveCity_ContestHall/scripts.pory"

# 468 "data/maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_Text_NeverWonBattleButContest:
# 469 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	.string "My POKéMON has never won in a battle,\n"
# 470 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	.string "but put it in a CONTEST and look out!$"
# 471 "data/maps/LilycoveCity_ContestHall/scripts.pory"

# 472 "data/maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_Text_PetalDanceIsMarvel:
# 473 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	.string "My POKéMON's PETAL DANCE is a marvel\n"
# 474 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	.string "of elegance.\p"
# 475 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	.string "I won't let anyone disturb its\n"
# 476 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	.string "performance.$"
# 477 "data/maps/LilycoveCity_ContestHall/scripts.pory"

# 478 "data/maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_Text_MyMonAppealSoMuchCuter:
# 479 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	.string "Everyone's POKéMON are very cute.\p"
# 480 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	.string "However, if my POKéMON were to make\n"
# 481 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	.string "a cute appeal…\p"
# 482 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	.string "I'm sure that it would be so much \n"
# 483 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	.string "cuter than the others.$"
# 484 "data/maps/LilycoveCity_ContestHall/scripts.pory"

# 485 "data/maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_Text_MyChildIsInContest:
# 486 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	.string "My child is in this CONTEST.$"
# 487 "data/maps/LilycoveCity_ContestHall/scripts.pory"

# 488 "data/maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_Text_ComeOnDear:
# 489 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	.string "Come on, dear. Go for it!\n"
# 490 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	.string "Your POKéMON is the best!$"
# 491 "data/maps/LilycoveCity_ContestHall/scripts.pory"

# 492 "data/maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_Text_ThatGirlThereIsCutest:
# 493 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	.string "I think that girl over there is\n"
# 494 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	.string "the cutest of the lot.\p"
# 495 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	.string "What's that? They're judging\n"
# 496 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	.string "POKéMON by their looks?$"
# 497 "data/maps/LilycoveCity_ContestHall/scripts.pory"

# 498 "data/maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_Text_WantCuteMonOfMyOwn:
# 499 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	.string "Ohh, seeing all these cute POKéMON,\n"
# 500 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	.string "they make we want to get my own!\p"
# 501 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	.string "I'm going to go catch some!$"
# 502 "data/maps/LilycoveCity_ContestHall/scripts.pory"

# 503 "data/maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_Text_BeautyContestStage:
# 504 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	.string "BEAUTY CONTEST STAGE\n"
# 505 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	.string "BE ALLURED BY BEAUTIFUL POKéMON!$"
# 506 "data/maps/LilycoveCity_ContestHall/scripts.pory"

# 507 "data/maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_Text_CuteContestStage:
# 508 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	.string "CUTENESS CONTEST STAGE\n"
# 509 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	.string "BE CHARMED BY CUTE POKéMON!$"
# 510 "data/maps/LilycoveCity_ContestHall/scripts.pory"

# 511 "data/maps/LilycoveCity_ContestHall/scripts.pory"
LilycoveCity_ContestHall_Text_SmartContestStage:
# 512 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	.string "SMARTNESS CONTEST STAGE\n"
# 513 "data/maps/LilycoveCity_ContestHall/scripts.pory"
	.string "BE IMPRESSED BY SMART POKéMON!$"
