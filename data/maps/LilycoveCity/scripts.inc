# 1 "data/maps/LilycoveCity/scripts.pory"

# 2 "data/maps/LilycoveCity/scripts.pory"
.set LOCALID_WOMAN_1, 19
# 3 "data/maps/LilycoveCity/scripts.pory"
.set LOCALID_MAN_1, 20
# 4 "data/maps/LilycoveCity/scripts.pory"

# 5 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_MapScripts::
# 6 "data/maps/LilycoveCity/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_OnTransition
# 7 "data/maps/LilycoveCity/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, LilycoveCity_OnLoad
# 8 "data/maps/LilycoveCity/scripts.pory"
	.byte 0
# 9 "data/maps/LilycoveCity/scripts.pory"

# 10 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_OnTransition:
# 11 "data/maps/LilycoveCity/scripts.pory"
	setflag FLAG_VISITED_LILYCOVE_CITY
# 12 "data/maps/LilycoveCity/scripts.pory"
	setvar VAR_CONTEST_HALL_STATE, 0
# 13 "data/maps/LilycoveCity/scripts.pory"
	setflag FLAG_HIDE_LILYCOVE_CONTEST_HALL_REPORTER
# 14 "data/maps/LilycoveCity/scripts.pory"
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
# 15 "data/maps/LilycoveCity/scripts.pory"
	call Common_EventScript_SetupRivalGfxId
# 16 "data/maps/LilycoveCity/scripts.pory"
	end
# 17 "data/maps/LilycoveCity/scripts.pory"

# 18 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_OnLoad:
# 19 "data/maps/LilycoveCity/scripts.pory"
	call_if_unset FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, LilycoveCity_EventScript_SetWailmerMetatiles
# 20 "data/maps/LilycoveCity/scripts.pory"
	end
# 21 "data/maps/LilycoveCity/scripts.pory"

# 22 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_SetWailmerMetatiles::
# 23 "data/maps/LilycoveCity/scripts.pory"
	setmetatile 76, 12, METATILE_Lilycove_Wailmer0, TRUE
# 24 "data/maps/LilycoveCity/scripts.pory"
	setmetatile 77, 12, METATILE_Lilycove_Wailmer1, TRUE
# 25 "data/maps/LilycoveCity/scripts.pory"
	setmetatile 76, 13, METATILE_Lilycove_Wailmer2, TRUE
# 26 "data/maps/LilycoveCity/scripts.pory"
	setmetatile 77, 13, METATILE_Lilycove_Wailmer3, TRUE
# 27 "data/maps/LilycoveCity/scripts.pory"
	setmetatile 76, 14, METATILE_Lilycove_Wailmer0_Alt, TRUE
# 28 "data/maps/LilycoveCity/scripts.pory"
	setmetatile 77, 14, METATILE_Lilycove_Wailmer1_Alt, TRUE
# 29 "data/maps/LilycoveCity/scripts.pory"
	setmetatile 76, 15, METATILE_Lilycove_Wailmer2, TRUE
# 30 "data/maps/LilycoveCity/scripts.pory"
	setmetatile 77, 15, METATILE_Lilycove_Wailmer3, TRUE
# 31 "data/maps/LilycoveCity/scripts.pory"
	setmetatile 77, 16, METATILE_Lilycove_Wailmer0_Alt, TRUE
# 32 "data/maps/LilycoveCity/scripts.pory"
	setmetatile 78, 16, METATILE_Lilycove_Wailmer1_Alt, TRUE
# 33 "data/maps/LilycoveCity/scripts.pory"
	setmetatile 77, 17, METATILE_Lilycove_Wailmer2, TRUE
# 34 "data/maps/LilycoveCity/scripts.pory"
	setmetatile 78, 17, METATILE_Lilycove_Wailmer3, TRUE
# 35 "data/maps/LilycoveCity/scripts.pory"
	return
# 36 "data/maps/LilycoveCity/scripts.pory"

# 37 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BerryGentleman::
# 38 "data/maps/LilycoveCity/scripts.pory"
	lock
# 39 "data/maps/LilycoveCity/scripts.pory"
	faceplayer
# 40 "data/maps/LilycoveCity/scripts.pory"
	dotimebasedevents
# 41 "data/maps/LilycoveCity/scripts.pory"
	goto_if_set FLAG_DAILY_LILYCOVE_RECEIVED_BERRY, LilycoveCity_EventScript_ReceivedBerry
# 42 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_BerrySuitsYou, MSGBOX_DEFAULT
# 43 "data/maps/LilycoveCity/scripts.pory"
	random 10
# 44 "data/maps/LilycoveCity/scripts.pory"
	addvar VAR_RESULT, FIRST_BERRY_INDEX
# 45 "data/maps/LilycoveCity/scripts.pory"
	giveitem VAR_RESULT
# 46 "data/maps/LilycoveCity/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 47 "data/maps/LilycoveCity/scripts.pory"
	setflag FLAG_DAILY_LILYCOVE_RECEIVED_BERRY
# 48 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_BecauseYoureTrainer, MSGBOX_DEFAULT
# 49 "data/maps/LilycoveCity/scripts.pory"
	release
# 50 "data/maps/LilycoveCity/scripts.pory"
	end
# 51 "data/maps/LilycoveCity/scripts.pory"

# 52 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_ReceivedBerry::
# 53 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_PokeblocksSuitPokemon, MSGBOX_DEFAULT
# 54 "data/maps/LilycoveCity/scripts.pory"
	release
# 55 "data/maps/LilycoveCity/scripts.pory"
	end
# 56 "data/maps/LilycoveCity/scripts.pory"

# 57 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Man3::
# 58 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_ContestHallInTown, MSGBOX_NPC
# 59 "data/maps/LilycoveCity/scripts.pory"
	end
# 60 "data/maps/LilycoveCity/scripts.pory"

# 61 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Girl::
# 62 "data/maps/LilycoveCity/scripts.pory"
	lock
# 63 "data/maps/LilycoveCity/scripts.pory"
	faceplayer
# 64 "data/maps/LilycoveCity/scripts.pory"
	goto_if_set FLAG_BADGE07_GET, LilycoveCity_EventScript_GirlAquaGone
# 65 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_StrangeCaveInCove, MSGBOX_DEFAULT
# 66 "data/maps/LilycoveCity/scripts.pory"
	release
# 67 "data/maps/LilycoveCity/scripts.pory"
	end
# 68 "data/maps/LilycoveCity/scripts.pory"

# 69 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_GirlAquaGone::
# 70 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_GoingToMoveDeleterForHMs, MSGBOX_DEFAULT
# 71 "data/maps/LilycoveCity/scripts.pory"
	release
# 72 "data/maps/LilycoveCity/scripts.pory"
	end
# 73 "data/maps/LilycoveCity/scripts.pory"

# 74 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_RichBoy::
# 75 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_ImFromKanto, MSGBOX_NPC
# 76 "data/maps/LilycoveCity/scripts.pory"
	end
# 77 "data/maps/LilycoveCity/scripts.pory"

# 78 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Sailor2::
# 79 "data/maps/LilycoveCity/scripts.pory"
	lock
# 80 "data/maps/LilycoveCity/scripts.pory"
	faceplayer
# 81 "data/maps/LilycoveCity/scripts.pory"
	goto_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, LilycoveCity_EventScript_Sailor2AquaGone
# 82 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_TeamAquaBeenTrainingWailmer, MSGBOX_DEFAULT
# 83 "data/maps/LilycoveCity/scripts.pory"
	release
# 84 "data/maps/LilycoveCity/scripts.pory"
	end
# 85 "data/maps/LilycoveCity/scripts.pory"

# 86 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Sailor2AquaGone::
# 87 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_SomeonePuntedTeamAquaOut, MSGBOX_DEFAULT
# 88 "data/maps/LilycoveCity/scripts.pory"
	release
# 89 "data/maps/LilycoveCity/scripts.pory"
	end
# 90 "data/maps/LilycoveCity/scripts.pory"

# 91 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Woman2::
# 92 "data/maps/LilycoveCity/scripts.pory"
	lock
# 93 "data/maps/LilycoveCity/scripts.pory"
	faceplayer
# 94 "data/maps/LilycoveCity/scripts.pory"
	goto_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, LilycoveCity_EventScript_Woman2AquaGone
# 95 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_SomeoneStoleMyPokemon, MSGBOX_DEFAULT
# 96 "data/maps/LilycoveCity/scripts.pory"
	release
# 97 "data/maps/LilycoveCity/scripts.pory"
	end
# 98 "data/maps/LilycoveCity/scripts.pory"

# 99 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Woman2AquaGone::
# 100 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MissingPokemonCameBack, MSGBOX_DEFAULT
# 101 "data/maps/LilycoveCity/scripts.pory"
	release
# 102 "data/maps/LilycoveCity/scripts.pory"
	end
# 103 "data/maps/LilycoveCity/scripts.pory"

# 104 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Man2::
# 105 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_ImArtDealer, MSGBOX_NPC
# 106 "data/maps/LilycoveCity/scripts.pory"
	end
# 107 "data/maps/LilycoveCity/scripts.pory"

# 108 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_ExpertM1::
# 109 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_SeaRemainsForeverYoung, MSGBOX_SIGN
# 110 "data/maps/LilycoveCity/scripts.pory"
	end
# 111 "data/maps/LilycoveCity/scripts.pory"

# 112 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_ExpertF::
# 113 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_SixtyYearsAgoHusbandProposed, MSGBOX_SIGN
# 114 "data/maps/LilycoveCity/scripts.pory"
	end
# 115 "data/maps/LilycoveCity/scripts.pory"

# 116 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_ExpertM2::
# 117 "data/maps/LilycoveCity/scripts.pory"
	lock
# 118 "data/maps/LilycoveCity/scripts.pory"
	faceplayer
# 119 "data/maps/LilycoveCity/scripts.pory"
	goto_if_set FLAG_BADGE07_GET, LilycoveCity_EventScript_ExpertM2AquaGone
# 120 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_TeamAquaRenovatedCavern, MSGBOX_DEFAULT
# 121 "data/maps/LilycoveCity/scripts.pory"
	release
# 122 "data/maps/LilycoveCity/scripts.pory"
	end
# 123 "data/maps/LilycoveCity/scripts.pory"

# 124 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_ExpertM2AquaGone::
# 125 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_TeamAquaLotGoneForGood, MSGBOX_DEFAULT
# 126 "data/maps/LilycoveCity/scripts.pory"
	release
# 127 "data/maps/LilycoveCity/scripts.pory"
	end
# 128 "data/maps/LilycoveCity/scripts.pory"

# 129 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Sailor1::
# 130 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_HeardTowerCalledSkyPillar, MSGBOX_NPC
# 131 "data/maps/LilycoveCity/scripts.pory"
	end
# 132 "data/maps/LilycoveCity/scripts.pory"

# 133 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_FatMan::
# 134 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_SawTallTowerOnRoute131, MSGBOX_NPC
# 135 "data/maps/LilycoveCity/scripts.pory"
	end
# 136 "data/maps/LilycoveCity/scripts.pory"

# 137 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Man1::
# 138 "data/maps/LilycoveCity/scripts.pory"
	lockall
# 139 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_JustArrivedAndSawRarePokemon, MSGBOX_NPC
# 140 "data/maps/LilycoveCity/scripts.pory"
	applymovement LOCALID_MAN_1, Common_Movement_FaceOriginalDirection
# 141 "data/maps/LilycoveCity/scripts.pory"
	end
# 142 "data/maps/LilycoveCity/scripts.pory"

# 143 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Woman1::
# 144 "data/maps/LilycoveCity/scripts.pory"
	lockall
# 145 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_HoneymoonVowToSeeRarePokemon, MSGBOX_NPC
# 146 "data/maps/LilycoveCity/scripts.pory"
	applymovement LOCALID_WOMAN_1, Common_Movement_FaceOriginalDirection
# 147 "data/maps/LilycoveCity/scripts.pory"
	end
# 148 "data/maps/LilycoveCity/scripts.pory"

# 149 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_CitySign::
# 150 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_CitySign, MSGBOX_SIGN
# 151 "data/maps/LilycoveCity/scripts.pory"
	end
# 152 "data/maps/LilycoveCity/scripts.pory"

# 153 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_ContestHallSign::
# 154 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_ContestHallSign, MSGBOX_SIGN
# 155 "data/maps/LilycoveCity/scripts.pory"
	end
# 156 "data/maps/LilycoveCity/scripts.pory"

# 157 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_MotelSign::
# 158 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MotelSign, MSGBOX_SIGN
# 159 "data/maps/LilycoveCity/scripts.pory"
	end
# 160 "data/maps/LilycoveCity/scripts.pory"

# 161 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_MuseumSign::
# 162 "data/maps/LilycoveCity/scripts.pory"
	lockall
# 163 "data/maps/LilycoveCity/scripts.pory"
	specialvar VAR_0x8004, CountPlayerMuseumPaintings
# 164 "data/maps/LilycoveCity/scripts.pory"
	switch VAR_0x8004
# 165 "data/maps/LilycoveCity/scripts.pory"
	case 0, LilycoveCity_EventScript_MuseumSignNoPaintings
# 166 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MuseumSignPlayersExhibit, MSGBOX_DEFAULT
# 167 "data/maps/LilycoveCity/scripts.pory"
	releaseall
# 168 "data/maps/LilycoveCity/scripts.pory"
	end
# 169 "data/maps/LilycoveCity/scripts.pory"

# 170 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_MuseumSignNoPaintings::
# 171 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MuseumSign, MSGBOX_DEFAULT
# 172 "data/maps/LilycoveCity/scripts.pory"
	releaseall
# 173 "data/maps/LilycoveCity/scripts.pory"
	end
# 174 "data/maps/LilycoveCity/scripts.pory"

# 175 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_HarborSign::
# 176 "data/maps/LilycoveCity/scripts.pory"
	lockall
# 177 "data/maps/LilycoveCity/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_EventScript_HarborSignFerryReady
# 178 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_HarborSignUnderConstruction, MSGBOX_DEFAULT
# 179 "data/maps/LilycoveCity/scripts.pory"
	releaseall
# 180 "data/maps/LilycoveCity/scripts.pory"
	end
# 181 "data/maps/LilycoveCity/scripts.pory"

# 182 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_HarborSignFerryReady::
# 183 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_HarborSign, MSGBOX_DEFAULT
# 184 "data/maps/LilycoveCity/scripts.pory"
	releaseall
# 185 "data/maps/LilycoveCity/scripts.pory"
	end
# 186 "data/maps/LilycoveCity/scripts.pory"

# 187 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_TrainerFanClubSign::
# 188 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_TrainerFanClubSign, MSGBOX_SIGN
# 189 "data/maps/LilycoveCity/scripts.pory"
	end
# 190 "data/maps/LilycoveCity/scripts.pory"

# 191 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_DepartmentStoreSign::
# 192 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_DepartmentStoreSign, MSGBOX_SIGN
# 193 "data/maps/LilycoveCity/scripts.pory"
	end
# 194 "data/maps/LilycoveCity/scripts.pory"

# 195 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_MoveDeletersHouseSign::
# 196 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MoveDeletersHouseSign, MSGBOX_SIGN
# 197 "data/maps/LilycoveCity/scripts.pory"
	end
# 198 "data/maps/LilycoveCity/scripts.pory"

# 199 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_WailmerTrainerGrunt::
# 200 "data/maps/LilycoveCity/scripts.pory"
	lockall
# 201 "data/maps/LilycoveCity/scripts.pory"
	goto_if_set FLAG_MET_WAILMER_TRAINER, LilycoveCity_EventScript_MetWailmerTrainer
# 202 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_WailmerLeapOutOfWater, MSGBOX_DEFAULT
# 203 "data/maps/LilycoveCity/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
# 204 "data/maps/LilycoveCity/scripts.pory"
	waitmovement 0
# 205 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_GetLostMessingUpTraining, MSGBOX_DEFAULT
# 206 "data/maps/LilycoveCity/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 207 "data/maps/LilycoveCity/scripts.pory"
	waitmovement 0
# 208 "data/maps/LilycoveCity/scripts.pory"
	setflag FLAG_MET_WAILMER_TRAINER
# 209 "data/maps/LilycoveCity/scripts.pory"
	releaseall
# 210 "data/maps/LilycoveCity/scripts.pory"
	end
# 211 "data/maps/LilycoveCity/scripts.pory"

# 212 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_MetWailmerTrainer::
# 213 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_WailmerLeapOutOfWater, MSGBOX_DEFAULT
# 214 "data/maps/LilycoveCity/scripts.pory"
	releaseall
# 215 "data/maps/LilycoveCity/scripts.pory"
	end
# 216 "data/maps/LilycoveCity/scripts.pory"

# 217 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_AquaGrunt1::
# 218 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MovedLootIntoHideoutToday, MSGBOX_NPC
# 219 "data/maps/LilycoveCity/scripts.pory"
	end
# 220 "data/maps/LilycoveCity/scripts.pory"

# 221 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_AquaGrunt2::
# 222 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_ChanceToDoBigThings, MSGBOX_NPC
# 223 "data/maps/LilycoveCity/scripts.pory"
	end
# 224 "data/maps/LilycoveCity/scripts.pory"

# 225 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_AquaGrunt3::
# 226 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_DontGoNearCaveInCove, MSGBOX_NPC
# 227 "data/maps/LilycoveCity/scripts.pory"
	end
# 228 "data/maps/LilycoveCity/scripts.pory"

# 229 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_AquaGrunt4::
# 230 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_IfWorldBecomesOurs, MSGBOX_NPC
# 231 "data/maps/LilycoveCity/scripts.pory"
	end
# 232 "data/maps/LilycoveCity/scripts.pory"

# 233 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Rival::
# 234 "data/maps/LilycoveCity/scripts.pory"
	lock
# 235 "data/maps/LilycoveCity/scripts.pory"
	faceplayer
# 236 "data/maps/LilycoveCity/scripts.pory"
	checkplayergender
# 237 "data/maps/LilycoveCity/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, LilycoveCity_EventScript_May
# 238 "data/maps/LilycoveCity/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, LilycoveCity_EventScript_Brendan
# 239 "data/maps/LilycoveCity/scripts.pory"
	end
# 240 "data/maps/LilycoveCity/scripts.pory"

# 241 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_May::
# 242 "data/maps/LilycoveCity/scripts.pory"
	playbgm MUS_ENCOUNTER_MAY, TRUE
# 243 "data/maps/LilycoveCity/scripts.pory"
	call_if_set FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_MayAskToBattleAgain
# 244 "data/maps/LilycoveCity/scripts.pory"
	call_if_unset FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_MayAskToBattle
# 245 "data/maps/LilycoveCity/scripts.pory"
	goto_if_eq VAR_RESULT, NO, LilycoveCity_EventScript_DeclineMayBattle
# 246 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MayWontBeBeaten, MSGBOX_DEFAULT
# 247 "data/maps/LilycoveCity/scripts.pory"
	switch VAR_STARTER_MON
# 248 "data/maps/LilycoveCity/scripts.pory"
	case 0, LilycoveCity_EventScript_BattleMayTreecko
# 249 "data/maps/LilycoveCity/scripts.pory"
	case 1, LilycoveCity_EventScript_BattleMayTorchic
# 250 "data/maps/LilycoveCity/scripts.pory"
	case 2, LilycoveCity_EventScript_BattleMayMudkip
# 251 "data/maps/LilycoveCity/scripts.pory"
	end
# 252 "data/maps/LilycoveCity/scripts.pory"

# 253 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_MayAskToBattleAgain::
# 254 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MayBattleMe, MSGBOX_YESNO
# 255 "data/maps/LilycoveCity/scripts.pory"
	return
# 256 "data/maps/LilycoveCity/scripts.pory"

# 257 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_MayAskToBattle::
# 258 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MayShoppingLetsBattle, MSGBOX_YESNO
# 259 "data/maps/LilycoveCity/scripts.pory"
	return
# 260 "data/maps/LilycoveCity/scripts.pory"

# 261 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_DeclineMayBattle::
# 262 "data/maps/LilycoveCity/scripts.pory"
	setflag FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE
# 263 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MayNotRaisingPokemon, MSGBOX_DEFAULT
# 264 "data/maps/LilycoveCity/scripts.pory"
	savebgm MUS_DUMMY
# 265 "data/maps/LilycoveCity/scripts.pory"
	fadedefaultbgm
# 266 "data/maps/LilycoveCity/scripts.pory"
	release
# 267 "data/maps/LilycoveCity/scripts.pory"
	end
# 268 "data/maps/LilycoveCity/scripts.pory"

# 269 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Brendan::
# 270 "data/maps/LilycoveCity/scripts.pory"
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
# 271 "data/maps/LilycoveCity/scripts.pory"
	call_if_set FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_BrendanAskToBattleAgain
# 272 "data/maps/LilycoveCity/scripts.pory"
	call_if_unset FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_BrendanAskToBattle
# 273 "data/maps/LilycoveCity/scripts.pory"
	goto_if_eq VAR_RESULT, NO, LilycoveCity_EventScript_DeclineBrendanBattle
# 274 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_BrendanWontBeBeaten, MSGBOX_DEFAULT
# 275 "data/maps/LilycoveCity/scripts.pory"
	switch VAR_STARTER_MON
# 276 "data/maps/LilycoveCity/scripts.pory"
	case 0, LilycoveCity_EventScript_BattleBrendanTreecko
# 277 "data/maps/LilycoveCity/scripts.pory"
	case 1, LilycoveCity_EventScript_BattleBrendanTorchic
# 278 "data/maps/LilycoveCity/scripts.pory"
	case 2, LilycoveCity_EventScript_BattleBrendanMudkip
# 279 "data/maps/LilycoveCity/scripts.pory"
	end
# 280 "data/maps/LilycoveCity/scripts.pory"

# 281 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BrendanAskToBattleAgain::
# 282 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_BrendanBattleMe, MSGBOX_YESNO
# 283 "data/maps/LilycoveCity/scripts.pory"
	return
# 284 "data/maps/LilycoveCity/scripts.pory"

# 285 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BrendanAskToBattle::
# 286 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_BrendanShoppingLetsBattle, MSGBOX_YESNO
# 287 "data/maps/LilycoveCity/scripts.pory"
	return
# 288 "data/maps/LilycoveCity/scripts.pory"

# 289 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_DeclineBrendanBattle::
# 290 "data/maps/LilycoveCity/scripts.pory"
	setflag FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE
# 291 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_BrendanNoConfidence, MSGBOX_DEFAULT
# 292 "data/maps/LilycoveCity/scripts.pory"
	savebgm MUS_DUMMY
# 293 "data/maps/LilycoveCity/scripts.pory"
	fadedefaultbgm
# 294 "data/maps/LilycoveCity/scripts.pory"
	release
# 295 "data/maps/LilycoveCity/scripts.pory"
	end
# 296 "data/maps/LilycoveCity/scripts.pory"

# 297 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BattleMayTreecko::
# 298 "data/maps/LilycoveCity/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_LILYCOVE_TREECKO, LilycoveCity_Text_MayDefeat
# 299 "data/maps/LilycoveCity/scripts.pory"
	goto LilycoveCity_EventScript_DefeatedMay
# 300 "data/maps/LilycoveCity/scripts.pory"
	end
# 301 "data/maps/LilycoveCity/scripts.pory"

# 302 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BattleMayTorchic::
# 303 "data/maps/LilycoveCity/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_LILYCOVE_TORCHIC, LilycoveCity_Text_MayDefeat
# 304 "data/maps/LilycoveCity/scripts.pory"
	goto LilycoveCity_EventScript_DefeatedMay
# 305 "data/maps/LilycoveCity/scripts.pory"
	end
# 306 "data/maps/LilycoveCity/scripts.pory"

# 307 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BattleMayMudkip::
# 308 "data/maps/LilycoveCity/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_LILYCOVE_MUDKIP, LilycoveCity_Text_MayDefeat
# 309 "data/maps/LilycoveCity/scripts.pory"
	goto LilycoveCity_EventScript_DefeatedMay
# 310 "data/maps/LilycoveCity/scripts.pory"
	end
# 311 "data/maps/LilycoveCity/scripts.pory"

# 312 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BattleBrendanTreecko::
# 313 "data/maps/LilycoveCity/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_LILYCOVE_TREECKO, LilycoveCity_Text_BrendanDefeat
# 314 "data/maps/LilycoveCity/scripts.pory"
	goto LilycoveCity_EventScript_DefeatedBrendan
# 315 "data/maps/LilycoveCity/scripts.pory"
	end
# 316 "data/maps/LilycoveCity/scripts.pory"

# 317 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BattleBrendanTorchic::
# 318 "data/maps/LilycoveCity/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_LILYCOVE_TORCHIC, LilycoveCity_Text_BrendanDefeat
# 319 "data/maps/LilycoveCity/scripts.pory"
	goto LilycoveCity_EventScript_DefeatedBrendan
# 320 "data/maps/LilycoveCity/scripts.pory"
	end
# 321 "data/maps/LilycoveCity/scripts.pory"

# 322 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BattleBrendanMudkip::
# 323 "data/maps/LilycoveCity/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_LILYCOVE_MUDKIP, LilycoveCity_Text_BrendanDefeat
# 324 "data/maps/LilycoveCity/scripts.pory"
	goto LilycoveCity_EventScript_DefeatedBrendan
# 325 "data/maps/LilycoveCity/scripts.pory"
	end
# 326 "data/maps/LilycoveCity/scripts.pory"

# 327 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_DefeatedMay::
# 328 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MayGoingBackToLittleroot, MSGBOX_DEFAULT
# 329 "data/maps/LilycoveCity/scripts.pory"
	setvar VAR_RESULT, FALSE
# 330 "data/maps/LilycoveCity/scripts.pory"
	call_if_set FLAG_BADGE06_GET, LilycoveCity_EventScript_CheckFinalBadge
# 331 "data/maps/LilycoveCity/scripts.pory"
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_EventScript_MayCollectBadges
# 332 "data/maps/LilycoveCity/scripts.pory"
	call_if_eq VAR_RESULT, TRUE, LilycoveCity_EventScript_MayPokemonLeague
# 333 "data/maps/LilycoveCity/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_BEDROOM
# 334 "data/maps/LilycoveCity/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_2F_PICHU_DOLL
# 335 "data/maps/LilycoveCity/scripts.pory"
	goto LilycoveCity_EventScript_RivalFlyAway
# 336 "data/maps/LilycoveCity/scripts.pory"
	end
# 337 "data/maps/LilycoveCity/scripts.pory"

# 338 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_CheckFinalBadge::
# 339 "data/maps/LilycoveCity/scripts.pory"
	goto_if_set FLAG_BADGE08_GET, LilycoveCity_EventScript_HasFinalBadge
# 340 "data/maps/LilycoveCity/scripts.pory"
	return
# 341 "data/maps/LilycoveCity/scripts.pory"

# 342 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_HasFinalBadge::
# 343 "data/maps/LilycoveCity/scripts.pory"
	setvar VAR_RESULT, TRUE
# 344 "data/maps/LilycoveCity/scripts.pory"
	return
# 345 "data/maps/LilycoveCity/scripts.pory"

# 346 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_MayCollectBadges::
# 347 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MayYouGoingToCollectBadges, MSGBOX_DEFAULT
# 348 "data/maps/LilycoveCity/scripts.pory"
	return
# 349 "data/maps/LilycoveCity/scripts.pory"

# 350 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_MayPokemonLeague::
# 351 "data/maps/LilycoveCity/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_EventScript_MayBattleFrontier
# 352 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MayYouGoingToPokemonLeague, MSGBOX_DEFAULT
# 353 "data/maps/LilycoveCity/scripts.pory"
	return
# 354 "data/maps/LilycoveCity/scripts.pory"

# 355 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_MayBattleFrontier::
# 356 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MayYouGoingToBattleFrontier, MSGBOX_DEFAULT
# 357 "data/maps/LilycoveCity/scripts.pory"
	return
# 358 "data/maps/LilycoveCity/scripts.pory"

# 359 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_DefeatedBrendan::
# 360 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_BrendanGoingBackToLittleroot, MSGBOX_DEFAULT
# 361 "data/maps/LilycoveCity/scripts.pory"
	setvar VAR_RESULT, FALSE
# 362 "data/maps/LilycoveCity/scripts.pory"
	call_if_set FLAG_BADGE06_GET, LilycoveCity_EventScript_CheckFinalBadge
# 363 "data/maps/LilycoveCity/scripts.pory"
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_EventScript_BrendanCollectBadges
# 364 "data/maps/LilycoveCity/scripts.pory"
	call_if_eq VAR_RESULT, TRUE, LilycoveCity_EventScript_BrendanPokemonLeague
# 365 "data/maps/LilycoveCity/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_BEDROOM
# 366 "data/maps/LilycoveCity/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_SWABLU_DOLL
# 367 "data/maps/LilycoveCity/scripts.pory"
	goto LilycoveCity_EventScript_RivalFlyAway
# 368 "data/maps/LilycoveCity/scripts.pory"
	end
# 369 "data/maps/LilycoveCity/scripts.pory"

# 370 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BrendanCollectBadges::
# 371 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_BrendanYouGoingToCollectBadges, MSGBOX_DEFAULT
# 372 "data/maps/LilycoveCity/scripts.pory"
	return
# 373 "data/maps/LilycoveCity/scripts.pory"

# 374 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BrendanPokemonLeague::
# 375 "data/maps/LilycoveCity/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_EventScript_BrendanBattleFrontier
# 376 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_BrendanYouGoingToPokemonLeague, MSGBOX_DEFAULT
# 377 "data/maps/LilycoveCity/scripts.pory"
	return
# 378 "data/maps/LilycoveCity/scripts.pory"

# 379 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BrendanBattleFrontier::
# 380 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_BrendanYouGoingToBattleFrontier, MSGBOX_DEFAULT
# 381 "data/maps/LilycoveCity/scripts.pory"
	return
# 382 "data/maps/LilycoveCity/scripts.pory"

# 383 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_RivalFlyAway::
# 384 "data/maps/LilycoveCity/scripts.pory"
	closemessage
# 385 "data/maps/LilycoveCity/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
# 386 "data/maps/LilycoveCity/scripts.pory"
	waitmovement 0
# 387 "data/maps/LilycoveCity/scripts.pory"
	delay 50
# 388 "data/maps/LilycoveCity/scripts.pory"
	setfieldeffectargument 0, 1
# 389 "data/maps/LilycoveCity/scripts.pory"
	dofieldeffect FLDEFF_NPCFLY_OUT
# 390 "data/maps/LilycoveCity/scripts.pory"
	delay 15
# 391 "data/maps/LilycoveCity/scripts.pory"
	removeobject VAR_LAST_TALKED
# 392 "data/maps/LilycoveCity/scripts.pory"
	waitfieldeffect FLDEFF_NPCFLY_OUT
# 393 "data/maps/LilycoveCity/scripts.pory"
	savebgm MUS_DUMMY
# 394 "data/maps/LilycoveCity/scripts.pory"
	fadedefaultbgm
# 395 "data/maps/LilycoveCity/scripts.pory"
	setflag FLAG_MET_RIVAL_LILYCOVE
# 396 "data/maps/LilycoveCity/scripts.pory"
	release
# 397 "data/maps/LilycoveCity/scripts.pory"
	end
# 398 "data/maps/LilycoveCity/scripts.pory"

# 399 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_SchoolKidM::
# 400 "data/maps/LilycoveCity/scripts.pory"
	lock
# 401 "data/maps/LilycoveCity/scripts.pory"
	faceplayer
# 402 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_DoYouKnowAboutBerryBlender, MSGBOX_YESNO
# 403 "data/maps/LilycoveCity/scripts.pory"
	call_if_eq VAR_RESULT, YES, LilycoveCity_EventScript_KnowAboutBerryBlender
# 404 "data/maps/LilycoveCity/scripts.pory"
	call_if_eq VAR_RESULT, NO, LilycoveCity_EventScript_DontKnowAboutBerryBlender
# 405 "data/maps/LilycoveCity/scripts.pory"
	release
# 406 "data/maps/LilycoveCity/scripts.pory"
	end
# 407 "data/maps/LilycoveCity/scripts.pory"

# 408 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_KnowAboutBerryBlender::
# 409 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_FasterSpinBetterPokeblocks, MSGBOX_DEFAULT
# 410 "data/maps/LilycoveCity/scripts.pory"
	return
# 411 "data/maps/LilycoveCity/scripts.pory"

# 412 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_DontKnowAboutBerryBlender::
# 413 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_ExplainBerryBlender, MSGBOX_DEFAULT
# 414 "data/maps/LilycoveCity/scripts.pory"
	return
# 415 "data/maps/LilycoveCity/scripts.pory"

# 416 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MayShoppingLetsBattle:
# 417 "data/maps/LilycoveCity/scripts.pory"
	.string "MAY: Oh, hey?\n"
# 418 "data/maps/LilycoveCity/scripts.pory"
	.string "{PLAYER}{KUN}, are you shopping, too?\p"
# 419 "data/maps/LilycoveCity/scripts.pory"
	.string "I bought a whole bunch of DOLLS and\n"
# 420 "data/maps/LilycoveCity/scripts.pory"
	.string "POSTERS.\p"
# 421 "data/maps/LilycoveCity/scripts.pory"
	.string "Of course, I've also caught a lot of\n"
# 422 "data/maps/LilycoveCity/scripts.pory"
	.string "POKéMON, and I'm raising them\l"
# 423 "data/maps/LilycoveCity/scripts.pory"
	.string "properly, too.\p"
# 424 "data/maps/LilycoveCity/scripts.pory"
	.string "Actually, I'm more worried if you're\n"
# 425 "data/maps/LilycoveCity/scripts.pory"
	.string "raising POKéMON properly, {PLAYER}{KUN}.\p"
# 426 "data/maps/LilycoveCity/scripts.pory"
	.string "I'll battle with you, so you can show\n"
# 427 "data/maps/LilycoveCity/scripts.pory"
	.string "me your POKéMON, {PLAYER}{KUN}.$"
# 428 "data/maps/LilycoveCity/scripts.pory"

# 429 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MayNotRaisingPokemon:
# 430 "data/maps/LilycoveCity/scripts.pory"
	.string "MAY: Oh, why? {PLAYER}{KUN}, haven't you\n"
# 431 "data/maps/LilycoveCity/scripts.pory"
	.string "been raising your POKéMON?\p"
# 432 "data/maps/LilycoveCity/scripts.pory"
	.string "That's not a very good showing as a\n"
# 433 "data/maps/LilycoveCity/scripts.pory"
	.string "TRAINER…$"
# 434 "data/maps/LilycoveCity/scripts.pory"

# 435 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MayBattleMe:
# 436 "data/maps/LilycoveCity/scripts.pory"
	.string "MAY: Come on, battle with me, so I can\n"
# 437 "data/maps/LilycoveCity/scripts.pory"
	.string "check out your POKéMON!$"
# 438 "data/maps/LilycoveCity/scripts.pory"

# 439 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MayWontBeBeaten:
# 440 "data/maps/LilycoveCity/scripts.pory"
	.string "MAY: The POKéMON I raised won't be\n"
# 441 "data/maps/LilycoveCity/scripts.pory"
	.string "beaten by your POKéMON, {PLAYER}{KUN}!$"
# 442 "data/maps/LilycoveCity/scripts.pory"

# 443 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MayDefeat:
# 444 "data/maps/LilycoveCity/scripts.pory"
	.string "… … … … … … … …\p"
# 445 "data/maps/LilycoveCity/scripts.pory"
	.string "I remember the battle I had with you,\n"
# 446 "data/maps/LilycoveCity/scripts.pory"
	.string "{PLAYER}{KUN}, on ROUTE 103.\p"
# 447 "data/maps/LilycoveCity/scripts.pory"
	.string "That battle helped you become this\n"
# 448 "data/maps/LilycoveCity/scripts.pory"
	.string "strong, {PLAYER}{KUN}, didn't it?$"
# 449 "data/maps/LilycoveCity/scripts.pory"

# 450 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MayGoingBackToLittleroot:
# 451 "data/maps/LilycoveCity/scripts.pory"
	.string "MAY: I'm thinking of going back to\n"
# 452 "data/maps/LilycoveCity/scripts.pory"
	.string "LITTLEROOT soon.\p"
# 453 "data/maps/LilycoveCity/scripts.pory"
	.string "I've caught a decent group of POKéMON,\n"
# 454 "data/maps/LilycoveCity/scripts.pory"
	.string "and my POKéDEX is coming along, so\l"
# 455 "data/maps/LilycoveCity/scripts.pory"
	.string "I'm going home to show my dad.$"
# 456 "data/maps/LilycoveCity/scripts.pory"

# 457 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MayYouGoingToCollectBadges:
# 458 "data/maps/LilycoveCity/scripts.pory"
	.string "{PLAYER}{KUN}, what are you going to do?\p"
# 459 "data/maps/LilycoveCity/scripts.pory"
	.string "Collect all the GYM BADGES and take\n"
# 460 "data/maps/LilycoveCity/scripts.pory"
	.string "the POKéMON LEAGUE challenge?\p"
# 461 "data/maps/LilycoveCity/scripts.pory"
	.string "Well, while you're collecting BADGES,\n"
# 462 "data/maps/LilycoveCity/scripts.pory"
	.string "{PLAYER}{KUN}, I'm going to work on my\l"
# 463 "data/maps/LilycoveCity/scripts.pory"
	.string "POKéDEX. I'll complete it before you!\p"
# 464 "data/maps/LilycoveCity/scripts.pory"
	.string "See you!$"
# 465 "data/maps/LilycoveCity/scripts.pory"

# 466 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MayYouGoingToPokemonLeague:
# 467 "data/maps/LilycoveCity/scripts.pory"
	.string "{PLAYER}{KUN}, what are you going to do?\p"
# 468 "data/maps/LilycoveCity/scripts.pory"
	.string "Are you taking the POKéMON LEAGUE\n"
# 469 "data/maps/LilycoveCity/scripts.pory"
	.string "challenge?\p"
# 470 "data/maps/LilycoveCity/scripts.pory"
	.string "Or, are you going to complete your\n"
# 471 "data/maps/LilycoveCity/scripts.pory"
	.string "POKéDEX?\p"
# 472 "data/maps/LilycoveCity/scripts.pory"
	.string "I might've lost to you in battling,\n"
# 473 "data/maps/LilycoveCity/scripts.pory"
	.string "but I'll finish my POKéDEX before you!\p"
# 474 "data/maps/LilycoveCity/scripts.pory"
	.string "See you!$"
# 475 "data/maps/LilycoveCity/scripts.pory"

# 476 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MayYouGoingToBattleFrontier:
# 477 "data/maps/LilycoveCity/scripts.pory"
	.string "{PLAYER}{KUN}, what are you going to do?\p"
# 478 "data/maps/LilycoveCity/scripts.pory"
	.string "Are you taking the BATTLE FRONTIER\n"
# 479 "data/maps/LilycoveCity/scripts.pory"
	.string "challenge?\p"
# 480 "data/maps/LilycoveCity/scripts.pory"
	.string "Or, are you going to complete your\n"
# 481 "data/maps/LilycoveCity/scripts.pory"
	.string "POKéDEX?\p"
# 482 "data/maps/LilycoveCity/scripts.pory"
	.string "I might've lost to you in battling,\n"
# 483 "data/maps/LilycoveCity/scripts.pory"
	.string "but I'll finish my POKéDEX before you!\p"
# 484 "data/maps/LilycoveCity/scripts.pory"
	.string "See you!$"
# 485 "data/maps/LilycoveCity/scripts.pory"

# 486 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_BrendanShoppingLetsBattle:
# 487 "data/maps/LilycoveCity/scripts.pory"
	.string "BRENDAN: Oh, hey, it's {PLAYER}.\p"
# 488 "data/maps/LilycoveCity/scripts.pory"
	.string "I'm running an errand for my dad.\n"
# 489 "data/maps/LilycoveCity/scripts.pory"
	.string "No, I'm not buying any DOLLS.\p"
# 490 "data/maps/LilycoveCity/scripts.pory"
	.string "Anyways, it's been a while.\p"
# 491 "data/maps/LilycoveCity/scripts.pory"
	.string "Want to have a battle to see who's been\n"
# 492 "data/maps/LilycoveCity/scripts.pory"
	.string "raising POKéMON better?$"
# 493 "data/maps/LilycoveCity/scripts.pory"

# 494 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_BrendanNoConfidence:
# 495 "data/maps/LilycoveCity/scripts.pory"
	.string "BRENDAN: Oh, what's the matter?\n"
# 496 "data/maps/LilycoveCity/scripts.pory"
	.string "Don't have the confidence?$"
# 497 "data/maps/LilycoveCity/scripts.pory"

# 498 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_BrendanBattleMe:
# 499 "data/maps/LilycoveCity/scripts.pory"
	.string "BRENDAN: Want to battle to see who's\n"
# 500 "data/maps/LilycoveCity/scripts.pory"
	.string "been raising POKéMON better?$"
# 501 "data/maps/LilycoveCity/scripts.pory"

# 502 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_BrendanWontBeBeaten:
# 503 "data/maps/LilycoveCity/scripts.pory"
	.string "BRENDAN: Aww, but you know I'm not\n"
# 504 "data/maps/LilycoveCity/scripts.pory"
	.string "going to lose to no {PLAYER}.$"
# 505 "data/maps/LilycoveCity/scripts.pory"

# 506 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_BrendanDefeat:
# 507 "data/maps/LilycoveCity/scripts.pory"
	.string "Humph…\n"
# 508 "data/maps/LilycoveCity/scripts.pory"
	.string "You've done a lot of raising.\p"
# 509 "data/maps/LilycoveCity/scripts.pory"
	.string "That stings a bit--I had a head start\n"
# 510 "data/maps/LilycoveCity/scripts.pory"
	.string "on you as a TRAINER…$"
# 511 "data/maps/LilycoveCity/scripts.pory"

# 512 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_BrendanGoingBackToLittleroot:
# 513 "data/maps/LilycoveCity/scripts.pory"
	.string "BRENDAN: I…\n"
# 514 "data/maps/LilycoveCity/scripts.pory"
	.string "I plan on going home to LITTLEROOT.\p"
# 515 "data/maps/LilycoveCity/scripts.pory"
	.string "You know I'm helping out my dad on his\n"
# 516 "data/maps/LilycoveCity/scripts.pory"
	.string "POKéDEX. It's coming together pretty\l"
# 517 "data/maps/LilycoveCity/scripts.pory"
	.string "decently, so I should go show him.$"
# 518 "data/maps/LilycoveCity/scripts.pory"

# 519 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_BrendanYouGoingToCollectBadges:
# 520 "data/maps/LilycoveCity/scripts.pory"
	.string "{PLAYER}, what are you going to do?\p"
# 521 "data/maps/LilycoveCity/scripts.pory"
	.string "Collect all the GYM BADGES and take\n"
# 522 "data/maps/LilycoveCity/scripts.pory"
	.string "the POKéMON LEAGUE challenge?\p"
# 523 "data/maps/LilycoveCity/scripts.pory"
	.string "Maybe I'll do that, too…\p"
# 524 "data/maps/LilycoveCity/scripts.pory"
	.string "Well, anyway, hang in there!$"
# 525 "data/maps/LilycoveCity/scripts.pory"

# 526 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_BrendanYouGoingToPokemonLeague:
# 527 "data/maps/LilycoveCity/scripts.pory"
	.string "{PLAYER}, what are you going to do?\p"
# 528 "data/maps/LilycoveCity/scripts.pory"
	.string "Since you're that strong, are you\n"
# 529 "data/maps/LilycoveCity/scripts.pory"
	.string "taking the POKéMON LEAGUE challenge?\p"
# 530 "data/maps/LilycoveCity/scripts.pory"
	.string "Heh, even me--if I trained my POKéMON\n"
# 531 "data/maps/LilycoveCity/scripts.pory"
	.string "a bit more, I should be stronger than\l"
# 532 "data/maps/LilycoveCity/scripts.pory"
	.string "you, {PLAYER}.\p"
# 533 "data/maps/LilycoveCity/scripts.pory"
	.string "Well, anyway, hang in there!$"
# 534 "data/maps/LilycoveCity/scripts.pory"

# 535 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_BrendanYouGoingToBattleFrontier:
# 536 "data/maps/LilycoveCity/scripts.pory"
	.string "{PLAYER}, what are you going to do?\p"
# 537 "data/maps/LilycoveCity/scripts.pory"
	.string "Are you taking the BATTLE FRONTIER\n"
# 538 "data/maps/LilycoveCity/scripts.pory"
	.string "challenge?\p"
# 539 "data/maps/LilycoveCity/scripts.pory"
	.string "Or, are you going to complete your\n"
# 540 "data/maps/LilycoveCity/scripts.pory"
	.string "POKéDEX?\p"
# 541 "data/maps/LilycoveCity/scripts.pory"
	.string "Since you're that strong, you should\n"
# 542 "data/maps/LilycoveCity/scripts.pory"
	.string "consider the BATTLE FRONTIER.\p"
# 543 "data/maps/LilycoveCity/scripts.pory"
	.string "Heh, if I train my POKéMON a bit more,\n"
# 544 "data/maps/LilycoveCity/scripts.pory"
	.string "I'll get stronger than you, {PLAYER}.\p"
# 545 "data/maps/LilycoveCity/scripts.pory"
	.string "Maybe I should go to the BATTLE\n"
# 546 "data/maps/LilycoveCity/scripts.pory"
	.string "FRONTIER.\p"
# 547 "data/maps/LilycoveCity/scripts.pory"
	.string "Well, anyway, hang in there!$"
# 548 "data/maps/LilycoveCity/scripts.pory"

# 549 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MovedLootIntoHideoutToday:
# 550 "data/maps/LilycoveCity/scripts.pory"
	.string "Fufufu…\p"
# 551 "data/maps/LilycoveCity/scripts.pory"
	.string "We moved more loot into our secret\n"
# 552 "data/maps/LilycoveCity/scripts.pory"
	.string "HIDEOUT today…\p"
# 553 "data/maps/LilycoveCity/scripts.pory"
	.string "Wh-who are you?!\n"
# 554 "data/maps/LilycoveCity/scripts.pory"
	.string "I was just talking to myself!$"
# 555 "data/maps/LilycoveCity/scripts.pory"

# 556 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_ChanceToDoBigThings:
# 557 "data/maps/LilycoveCity/scripts.pory"
	.string "I'm just a GRUNT, so I don't know what\n"
# 558 "data/maps/LilycoveCity/scripts.pory"
	.string "the BOSS is thinking…\p"
# 559 "data/maps/LilycoveCity/scripts.pory"
	.string "But being on TEAM AQUA, I know I'll get\n"
# 560 "data/maps/LilycoveCity/scripts.pory"
	.string "the chance to do big things!\p"
# 561 "data/maps/LilycoveCity/scripts.pory"
	.string "Wh-who are you?!\n"
# 562 "data/maps/LilycoveCity/scripts.pory"
	.string "I was just talking to myself!$"
# 563 "data/maps/LilycoveCity/scripts.pory"

# 564 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_DontGoNearCaveInCove:
# 565 "data/maps/LilycoveCity/scripts.pory"
	.string "Hey, you!\p"
# 566 "data/maps/LilycoveCity/scripts.pory"
	.string "Don't go near the cave in the cove!\p"
# 567 "data/maps/LilycoveCity/scripts.pory"
	.string "Why? You don't need a reason why!\n"
# 568 "data/maps/LilycoveCity/scripts.pory"
	.string "I'm an adult, so you just listen to me!$"
# 569 "data/maps/LilycoveCity/scripts.pory"

# 570 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_IfWorldBecomesOurs:
# 571 "data/maps/LilycoveCity/scripts.pory"
	.string "If this whole wide world becomes ours,\n"
# 572 "data/maps/LilycoveCity/scripts.pory"
	.string "TEAM AQUA's, it will be a happier\l"
# 573 "data/maps/LilycoveCity/scripts.pory"
	.string "place for POKéMON, too.$"
# 574 "data/maps/LilycoveCity/scripts.pory"

# 575 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_WailmerLeapOutOfWater:
# 576 "data/maps/LilycoveCity/scripts.pory"
	.string "There! WAILMER!\n"
# 577 "data/maps/LilycoveCity/scripts.pory"
	.string "Leap out of the water now!$"
# 578 "data/maps/LilycoveCity/scripts.pory"

# 579 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_GetLostMessingUpTraining:
# 580 "data/maps/LilycoveCity/scripts.pory"
	.string "Hunh? What do you want?\p"
# 581 "data/maps/LilycoveCity/scripts.pory"
	.string "You're messing up our training,\n"
# 582 "data/maps/LilycoveCity/scripts.pory"
	.string "so can you, like, get lost?$"
# 583 "data/maps/LilycoveCity/scripts.pory"

# 584 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_ContestHallInTown:
# 585 "data/maps/LilycoveCity/scripts.pory"
	.string "There's a POKéMON CONTEST HALL\n"
# 586 "data/maps/LilycoveCity/scripts.pory"
	.string "right in this here town. \p"
# 587 "data/maps/LilycoveCity/scripts.pory"
	.string "That means well-raised POKéMON will\n"
# 588 "data/maps/LilycoveCity/scripts.pory"
	.string "come from all over the country.\p"
# 589 "data/maps/LilycoveCity/scripts.pory"
	.string "My heart swells with excitement!$"
# 590 "data/maps/LilycoveCity/scripts.pory"

# 591 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_StrangeCaveInCove:
# 592 "data/maps/LilycoveCity/scripts.pory"
	.string "Have you seen that strange cave in\n"
# 593 "data/maps/LilycoveCity/scripts.pory"
	.string "the cove at the edge of town?$"
# 594 "data/maps/LilycoveCity/scripts.pory"

# 595 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_GoingToMoveDeleterForHMs:
# 596 "data/maps/LilycoveCity/scripts.pory"
	.string "I'm going to teach my POKéMON some new\n"
# 597 "data/maps/LilycoveCity/scripts.pory"
	.string "moves for entering a CONTEST.\p"
# 598 "data/maps/LilycoveCity/scripts.pory"
	.string "So, I'm going to see the MOVE DELETER\n"
# 599 "data/maps/LilycoveCity/scripts.pory"
	.string "and make it forget HM moves.$"
# 600 "data/maps/LilycoveCity/scripts.pory"

# 601 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_ImFromKanto:
# 602 "data/maps/LilycoveCity/scripts.pory"
	.string "I came from KANTO.\p"
# 603 "data/maps/LilycoveCity/scripts.pory"
	.string "The HOENN region is beautiful with\n"
# 604 "data/maps/LilycoveCity/scripts.pory"
	.string "all its water and verdant nature.\p"
# 605 "data/maps/LilycoveCity/scripts.pory"
	.string "Hunh? Wait a second…\p"
# 606 "data/maps/LilycoveCity/scripts.pory"
	.string "Could there be rare POKéMON that live\n"
# 607 "data/maps/LilycoveCity/scripts.pory"
	.string "only in this area?$"
# 608 "data/maps/LilycoveCity/scripts.pory"

# 609 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_TeamAquaBeenTrainingWailmer:
# 610 "data/maps/LilycoveCity/scripts.pory"
	.string "TEAM AQUA's been training their\n"
# 611 "data/maps/LilycoveCity/scripts.pory"
	.string "WAILMER in the cove.\p"
# 612 "data/maps/LilycoveCity/scripts.pory"
	.string "We SAILORS can't get our boats out\n"
# 613 "data/maps/LilycoveCity/scripts.pory"
	.string "to sea with them in the way!$"
# 614 "data/maps/LilycoveCity/scripts.pory"

# 615 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_SomeonePuntedTeamAquaOut:
# 616 "data/maps/LilycoveCity/scripts.pory"
	.string "Ahoy, did you know?\p"
# 617 "data/maps/LilycoveCity/scripts.pory"
	.string "Someone punted TEAM AQUA out of\n"
# 618 "data/maps/LilycoveCity/scripts.pory"
	.string "the way for us!\p"
# 619 "data/maps/LilycoveCity/scripts.pory"
	.string "That got the WAILMER out of the cove,\n"
# 620 "data/maps/LilycoveCity/scripts.pory"
	.string "so we can get our boats out again.$"
# 621 "data/maps/LilycoveCity/scripts.pory"

# 622 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_SomeoneStoleMyPokemon:
# 623 "data/maps/LilycoveCity/scripts.pory"
	.string "I was taking a relaxing snooze at the\n"
# 624 "data/maps/LilycoveCity/scripts.pory"
	.string "seaside inn to the sound of waves…\p"
# 625 "data/maps/LilycoveCity/scripts.pory"
	.string "When someone stole my POKéMON!\p"
# 626 "data/maps/LilycoveCity/scripts.pory"
	.string "Who's the abductor?\n"
# 627 "data/maps/LilycoveCity/scripts.pory"
	.string "TEAM AQUA? Is it TEAM AQUA?$"
# 628 "data/maps/LilycoveCity/scripts.pory"

# 629 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MissingPokemonCameBack:
# 630 "data/maps/LilycoveCity/scripts.pory"
	.string "My missing POKéMON…\n"
# 631 "data/maps/LilycoveCity/scripts.pory"
	.string "It came back without me noticing!$"
# 632 "data/maps/LilycoveCity/scripts.pory"

# 633 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_ImArtDealer:
# 634 "data/maps/LilycoveCity/scripts.pory"
	.string "I'm an ART DEALER.\p"
# 635 "data/maps/LilycoveCity/scripts.pory"
	.string "I am a buyer and seller of fine art,\n"
# 636 "data/maps/LilycoveCity/scripts.pory"
	.string "especially paintings.\p"
# 637 "data/maps/LilycoveCity/scripts.pory"
	.string "I've heard that the MUSEUM here has\n"
# 638 "data/maps/LilycoveCity/scripts.pory"
	.string "magnificent works on exhibit…$"
# 639 "data/maps/LilycoveCity/scripts.pory"

# 640 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_SeaRemainsForeverYoung:
# 641 "data/maps/LilycoveCity/scripts.pory"
	.string "Even as we grow old and wrinkled,\n"
# 642 "data/maps/LilycoveCity/scripts.pory"
	.string "the sea remains forever young with\l"
# 643 "data/maps/LilycoveCity/scripts.pory"
	.string "the vivid brilliance of life…\p"
# 644 "data/maps/LilycoveCity/scripts.pory"
	.string "Fwohoho fwohohohoho…$"
# 645 "data/maps/LilycoveCity/scripts.pory"

# 646 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_SixtyYearsAgoHusbandProposed:
# 647 "data/maps/LilycoveCity/scripts.pory"
	.string "It was sixty years ago that my husband\n"
# 648 "data/maps/LilycoveCity/scripts.pory"
	.string "proposed to me here.\l"
# 649 "data/maps/LilycoveCity/scripts.pory"
	.string "The sea remains as beautiful as ever.\p"
# 650 "data/maps/LilycoveCity/scripts.pory"
	.string "Mufufufu mufufufufufu…$"
# 651 "data/maps/LilycoveCity/scripts.pory"

# 652 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_TeamAquaRenovatedCavern:
# 653 "data/maps/LilycoveCity/scripts.pory"
	.string "Hm, you know of the peculiar cavern\n"
# 654 "data/maps/LilycoveCity/scripts.pory"
	.string "in this cove?\p"
# 655 "data/maps/LilycoveCity/scripts.pory"
	.string "That had been a natural formation,\n"
# 656 "data/maps/LilycoveCity/scripts.pory"
	.string "but then that TEAM AQUA lot came\l"
# 657 "data/maps/LilycoveCity/scripts.pory"
	.string "along and made their renovations.\p"
# 658 "data/maps/LilycoveCity/scripts.pory"
	.string "They call themselves\n"
# 659 "data/maps/LilycoveCity/scripts.pory"
	.string "the “nature-loving TEAM AQUA”!\p"
# 660 "data/maps/LilycoveCity/scripts.pory"
	.string "But what they do and what they say\n"
# 661 "data/maps/LilycoveCity/scripts.pory"
	.string "don't match at all!$"
# 662 "data/maps/LilycoveCity/scripts.pory"

# 663 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_TeamAquaLotGoneForGood:
# 664 "data/maps/LilycoveCity/scripts.pory"
	.string "That cave in the cove…\p"
# 665 "data/maps/LilycoveCity/scripts.pory"
	.string "I didn't notice it right away,\n"
# 666 "data/maps/LilycoveCity/scripts.pory"
	.string "but it's completely empty now.\p"
# 667 "data/maps/LilycoveCity/scripts.pory"
	.string "That TEAM AQUA lot, they must\n"
# 668 "data/maps/LilycoveCity/scripts.pory"
	.string "have gone away for good.$"
# 669 "data/maps/LilycoveCity/scripts.pory"

# 670 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_CitySign:
# 671 "data/maps/LilycoveCity/scripts.pory"
	.string "LILYCOVE CITY\p"
# 672 "data/maps/LilycoveCity/scripts.pory"
	.string "“Where the land ends and the\n"
# 673 "data/maps/LilycoveCity/scripts.pory"
	.string "sea begins.”$"
# 674 "data/maps/LilycoveCity/scripts.pory"

# 675 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_ContestHallSign:
# 676 "data/maps/LilycoveCity/scripts.pory"
	.string "POKéMON CONTEST HALL\n"
# 677 "data/maps/LilycoveCity/scripts.pory"
	.string "“The gathering place for TRAINERS!”$"
# 678 "data/maps/LilycoveCity/scripts.pory"

# 679 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MotelSign:
# 680 "data/maps/LilycoveCity/scripts.pory"
	.string "COVE LILY MOTEL\p"
# 681 "data/maps/LilycoveCity/scripts.pory"
	.string "“Remember us as COVE LILY of\n"
# 682 "data/maps/LilycoveCity/scripts.pory"
	.string "LILYCOVE.”$"
# 683 "data/maps/LilycoveCity/scripts.pory"

# 684 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MuseumSign:
# 685 "data/maps/LilycoveCity/scripts.pory"
	.string "LILYCOVE MUSEUM\p"
# 686 "data/maps/LilycoveCity/scripts.pory"
	.string "“POKéMON Masterpiece Collection\n"
# 687 "data/maps/LilycoveCity/scripts.pory"
	.string "on exhibit!”$"
# 688 "data/maps/LilycoveCity/scripts.pory"

# 689 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MuseumSignPlayersExhibit:
# 690 "data/maps/LilycoveCity/scripts.pory"
	.string "LILYCOVE MUSEUM\p"
# 691 "data/maps/LilycoveCity/scripts.pory"
	.string "“{PLAYER}'s POKéMON Collection\n"
# 692 "data/maps/LilycoveCity/scripts.pory"
	.string "on exhibit!”$"
# 693 "data/maps/LilycoveCity/scripts.pory"

# 694 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_HarborSignUnderConstruction:
# 695 "data/maps/LilycoveCity/scripts.pory"
	.string "LILYCOVE CITY HARBOR\p"
# 696 "data/maps/LilycoveCity/scripts.pory"
	.string "“The ferry S.S. TIDAL is under\n"
# 697 "data/maps/LilycoveCity/scripts.pory"
	.string "construction in SLATEPORT CITY.\p"
# 698 "data/maps/LilycoveCity/scripts.pory"
	.string "“Service is scheduled to begin\n"
# 699 "data/maps/LilycoveCity/scripts.pory"
	.string "shortly.”$"
# 700 "data/maps/LilycoveCity/scripts.pory"

# 701 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_HarborSign:
# 702 "data/maps/LilycoveCity/scripts.pory"
	.string "LILYCOVE CITY HARBOR\p"
# 703 "data/maps/LilycoveCity/scripts.pory"
	.string "“Enjoy a delightful cruise on\n"
# 704 "data/maps/LilycoveCity/scripts.pory"
	.string "the ferry S.S. TIDAL.”$"
# 705 "data/maps/LilycoveCity/scripts.pory"

# 706 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_TrainerFanClubSign:
# 707 "data/maps/LilycoveCity/scripts.pory"
	.string "POKéMON TRAINER FAN CLUB\p"
# 708 "data/maps/LilycoveCity/scripts.pory"
	.string "The names of TRAINERS are scribbled\n"
# 709 "data/maps/LilycoveCity/scripts.pory"
	.string "all over the sign…$"
# 710 "data/maps/LilycoveCity/scripts.pory"

# 711 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_DepartmentStoreSign:
# 712 "data/maps/LilycoveCity/scripts.pory"
	.string "LILYCOVE DEPARTMENT STORE\p"
# 713 "data/maps/LilycoveCity/scripts.pory"
	.string "“Overflowing with great merchandise\n"
# 714 "data/maps/LilycoveCity/scripts.pory"
	.string "and excitement!\p"
# 715 "data/maps/LilycoveCity/scripts.pory"
	.string "“A great place to find that something\n"
# 716 "data/maps/LilycoveCity/scripts.pory"
	.string "you need!”$"
# 717 "data/maps/LilycoveCity/scripts.pory"

# 718 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MoveDeletersHouseSign:
# 719 "data/maps/LilycoveCity/scripts.pory"
	.string "MOVE DELETER'S HOUSE\p"
# 720 "data/maps/LilycoveCity/scripts.pory"
	.string "“Unwanted POKéMON moves deleted.”$"
# 721 "data/maps/LilycoveCity/scripts.pory"

# 722 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_DoYouKnowAboutBerryBlender:
# 723 "data/maps/LilycoveCity/scripts.pory"
	.string "Do you know about the machine\n"
# 724 "data/maps/LilycoveCity/scripts.pory"
	.string "BERRY BLENDER?$"
# 725 "data/maps/LilycoveCity/scripts.pory"

# 726 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_FasterSpinBetterPokeblocks:
# 727 "data/maps/LilycoveCity/scripts.pory"
	.string "People have to work together to get it\n"
# 728 "data/maps/LilycoveCity/scripts.pory"
	.string "to spin faster.\p"
# 729 "data/maps/LilycoveCity/scripts.pory"
	.string "The faster you can make it spin, the\n"
# 730 "data/maps/LilycoveCity/scripts.pory"
	.string "better {POKEBLOCK}S you can get, I've heard.$"
# 731 "data/maps/LilycoveCity/scripts.pory"

# 732 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_ExplainBerryBlender:
# 733 "data/maps/LilycoveCity/scripts.pory"
	.string "It's used for making a kind of candy\n"
# 734 "data/maps/LilycoveCity/scripts.pory"
	.string "called a {POKEBLOCK}.\p"
# 735 "data/maps/LilycoveCity/scripts.pory"
	.string "If you give a good {POKEBLOCK} to a POKéMON,\n"
# 736 "data/maps/LilycoveCity/scripts.pory"
	.string "its condition will improve by a lot.$"
# 737 "data/maps/LilycoveCity/scripts.pory"

# 738 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_HeardTowerCalledSkyPillar:
# 739 "data/maps/LilycoveCity/scripts.pory"
	.string "I heard there's a tower somewhere out\n"
# 740 "data/maps/LilycoveCity/scripts.pory"
	.string "on the sea routes.\p"
# 741 "data/maps/LilycoveCity/scripts.pory"
	.string "It's called the SKY PILLAR, I hear.$"
# 742 "data/maps/LilycoveCity/scripts.pory"

# 743 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_SawTallTowerOnRoute131:
# 744 "data/maps/LilycoveCity/scripts.pory"
	.string "I saw this tall tower somewhere\n"
# 745 "data/maps/LilycoveCity/scripts.pory"
	.string "around ROUTE 131.\p"
# 746 "data/maps/LilycoveCity/scripts.pory"
	.string "Could that possibly be…?$"
# 747 "data/maps/LilycoveCity/scripts.pory"

# 748 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_JustArrivedAndSawRarePokemon:
# 749 "data/maps/LilycoveCity/scripts.pory"
	.string "We just arrived here on our\n"
# 750 "data/maps/LilycoveCity/scripts.pory"
	.string "honeymoon vacation.\p"
# 751 "data/maps/LilycoveCity/scripts.pory"
	.string "We happened to see a DRAGON-type\n"
# 752 "data/maps/LilycoveCity/scripts.pory"
	.string "POKéMON flying way up in the sky.\p"
# 753 "data/maps/LilycoveCity/scripts.pory"
	.string "Do cool POKéMON like that live in\n"
# 754 "data/maps/LilycoveCity/scripts.pory"
	.string "the HOENN region?$"
# 755 "data/maps/LilycoveCity/scripts.pory"

# 756 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_HoneymoonVowToSeeRarePokemon:
# 757 "data/maps/LilycoveCity/scripts.pory"
	.string "On our honeymoon, we vowed to see as\n"
# 758 "data/maps/LilycoveCity/scripts.pory"
	.string "many rare POKéMON as we can.\p"
# 759 "data/maps/LilycoveCity/scripts.pory"
	.string "So we were delighted to see a rare\n"
# 760 "data/maps/LilycoveCity/scripts.pory"
	.string "POKéMON as soon as we arrived.\p"
# 761 "data/maps/LilycoveCity/scripts.pory"
	.string "I mean, we are totally happy!$"
