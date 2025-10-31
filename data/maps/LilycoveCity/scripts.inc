# 1 "data/maps/LilycoveCity/scripts.pory"

# 2 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_MapScripts::
# 3 "data/maps/LilycoveCity/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_OnTransition
# 4 "data/maps/LilycoveCity/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, LilycoveCity_OnLoad
# 5 "data/maps/LilycoveCity/scripts.pory"
	.byte 0
# 6 "data/maps/LilycoveCity/scripts.pory"

# 7 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_OnTransition:
# 8 "data/maps/LilycoveCity/scripts.pory"
	setflag FLAG_VISITED_LILYCOVE_CITY
# 9 "data/maps/LilycoveCity/scripts.pory"
	setvar VAR_CONTEST_HALL_STATE, 0
# 10 "data/maps/LilycoveCity/scripts.pory"
	setflag FLAG_HIDE_LILYCOVE_CONTEST_HALL_REPORTER
# 11 "data/maps/LilycoveCity/scripts.pory"
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
# 12 "data/maps/LilycoveCity/scripts.pory"
	call Common_EventScript_SetupRivalGfxId
# 13 "data/maps/LilycoveCity/scripts.pory"
	end
# 14 "data/maps/LilycoveCity/scripts.pory"

# 15 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_OnLoad:
# 16 "data/maps/LilycoveCity/scripts.pory"
	call_if_unset FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, LilycoveCity_EventScript_SetWailmerMetatiles
# 17 "data/maps/LilycoveCity/scripts.pory"
	end
# 18 "data/maps/LilycoveCity/scripts.pory"

# 19 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_SetWailmerMetatiles::
# 20 "data/maps/LilycoveCity/scripts.pory"
	setmetatile 76, 12, METATILE_Lilycove_Wailmer0, TRUE
# 21 "data/maps/LilycoveCity/scripts.pory"
	setmetatile 77, 12, METATILE_Lilycove_Wailmer1, TRUE
# 22 "data/maps/LilycoveCity/scripts.pory"
	setmetatile 76, 13, METATILE_Lilycove_Wailmer2, TRUE
# 23 "data/maps/LilycoveCity/scripts.pory"
	setmetatile 77, 13, METATILE_Lilycove_Wailmer3, TRUE
# 24 "data/maps/LilycoveCity/scripts.pory"
	setmetatile 76, 14, METATILE_Lilycove_Wailmer0_Alt, TRUE
# 25 "data/maps/LilycoveCity/scripts.pory"
	setmetatile 77, 14, METATILE_Lilycove_Wailmer1_Alt, TRUE
# 26 "data/maps/LilycoveCity/scripts.pory"
	setmetatile 76, 15, METATILE_Lilycove_Wailmer2, TRUE
# 27 "data/maps/LilycoveCity/scripts.pory"
	setmetatile 77, 15, METATILE_Lilycove_Wailmer3, TRUE
# 28 "data/maps/LilycoveCity/scripts.pory"
	setmetatile 77, 16, METATILE_Lilycove_Wailmer0_Alt, TRUE
# 29 "data/maps/LilycoveCity/scripts.pory"
	setmetatile 78, 16, METATILE_Lilycove_Wailmer1_Alt, TRUE
# 30 "data/maps/LilycoveCity/scripts.pory"
	setmetatile 77, 17, METATILE_Lilycove_Wailmer2, TRUE
# 31 "data/maps/LilycoveCity/scripts.pory"
	setmetatile 78, 17, METATILE_Lilycove_Wailmer3, TRUE
# 32 "data/maps/LilycoveCity/scripts.pory"
	return
# 33 "data/maps/LilycoveCity/scripts.pory"

# 34 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BerryGentleman::
# 35 "data/maps/LilycoveCity/scripts.pory"
	lock
# 36 "data/maps/LilycoveCity/scripts.pory"
	faceplayer
# 37 "data/maps/LilycoveCity/scripts.pory"
	dotimebasedevents
# 38 "data/maps/LilycoveCity/scripts.pory"
	goto_if_set FLAG_DAILY_LILYCOVE_RECEIVED_BERRY, LilycoveCity_EventScript_ReceivedBerry
# 39 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_BerrySuitsYou, MSGBOX_DEFAULT
# 40 "data/maps/LilycoveCity/scripts.pory"
	random 10
# 41 "data/maps/LilycoveCity/scripts.pory"
	addvar VAR_RESULT, FIRST_BERRY_INDEX
# 42 "data/maps/LilycoveCity/scripts.pory"
	giveitem VAR_RESULT
# 43 "data/maps/LilycoveCity/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 44 "data/maps/LilycoveCity/scripts.pory"
	setflag FLAG_DAILY_LILYCOVE_RECEIVED_BERRY
# 45 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_BecauseYoureTrainer, MSGBOX_DEFAULT
# 46 "data/maps/LilycoveCity/scripts.pory"
	release
# 47 "data/maps/LilycoveCity/scripts.pory"
	end
# 48 "data/maps/LilycoveCity/scripts.pory"

# 49 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_ReceivedBerry::
# 50 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_PokeblocksSuitPokemon, MSGBOX_DEFAULT
# 51 "data/maps/LilycoveCity/scripts.pory"
	release
# 52 "data/maps/LilycoveCity/scripts.pory"
	end
# 53 "data/maps/LilycoveCity/scripts.pory"

# 54 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Man3::
# 55 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_ContestHallInTown, MSGBOX_NPC
# 56 "data/maps/LilycoveCity/scripts.pory"
	end
# 57 "data/maps/LilycoveCity/scripts.pory"

# 58 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Girl::
# 59 "data/maps/LilycoveCity/scripts.pory"
	lock
# 60 "data/maps/LilycoveCity/scripts.pory"
	faceplayer
# 61 "data/maps/LilycoveCity/scripts.pory"
	goto_if_set FLAG_BADGE07_GET, LilycoveCity_EventScript_GirlAquaGone
# 62 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_StrangeCaveInCove, MSGBOX_DEFAULT
# 63 "data/maps/LilycoveCity/scripts.pory"
	release
# 64 "data/maps/LilycoveCity/scripts.pory"
	end
# 65 "data/maps/LilycoveCity/scripts.pory"

# 66 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_GirlAquaGone::
# 67 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_GoingToMoveDeleterForHMs, MSGBOX_DEFAULT
# 68 "data/maps/LilycoveCity/scripts.pory"
	release
# 69 "data/maps/LilycoveCity/scripts.pory"
	end
# 70 "data/maps/LilycoveCity/scripts.pory"

# 71 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_RichBoy::
# 72 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_ImFromKanto, MSGBOX_NPC
# 73 "data/maps/LilycoveCity/scripts.pory"
	end
# 74 "data/maps/LilycoveCity/scripts.pory"

# 75 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Sailor2::
# 76 "data/maps/LilycoveCity/scripts.pory"
	lock
# 77 "data/maps/LilycoveCity/scripts.pory"
	faceplayer
# 78 "data/maps/LilycoveCity/scripts.pory"
	goto_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, LilycoveCity_EventScript_Sailor2AquaGone
# 79 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_TeamAquaBeenTrainingWailmer, MSGBOX_DEFAULT
# 80 "data/maps/LilycoveCity/scripts.pory"
	release
# 81 "data/maps/LilycoveCity/scripts.pory"
	end
# 82 "data/maps/LilycoveCity/scripts.pory"

# 83 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Sailor2AquaGone::
# 84 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_SomeonePuntedTeamAquaOut, MSGBOX_DEFAULT
# 85 "data/maps/LilycoveCity/scripts.pory"
	release
# 86 "data/maps/LilycoveCity/scripts.pory"
	end
# 87 "data/maps/LilycoveCity/scripts.pory"

# 88 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Woman2::
# 89 "data/maps/LilycoveCity/scripts.pory"
	lock
# 90 "data/maps/LilycoveCity/scripts.pory"
	faceplayer
# 91 "data/maps/LilycoveCity/scripts.pory"
	goto_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, LilycoveCity_EventScript_Woman2AquaGone
# 92 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_SomeoneStoleMyPokemon, MSGBOX_DEFAULT
# 93 "data/maps/LilycoveCity/scripts.pory"
	release
# 94 "data/maps/LilycoveCity/scripts.pory"
	end
# 95 "data/maps/LilycoveCity/scripts.pory"

# 96 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Woman2AquaGone::
# 97 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MissingPokemonCameBack, MSGBOX_DEFAULT
# 98 "data/maps/LilycoveCity/scripts.pory"
	release
# 99 "data/maps/LilycoveCity/scripts.pory"
	end
# 100 "data/maps/LilycoveCity/scripts.pory"

# 101 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Man2::
# 102 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_ImArtDealer, MSGBOX_NPC
# 103 "data/maps/LilycoveCity/scripts.pory"
	end
# 104 "data/maps/LilycoveCity/scripts.pory"

# 105 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_ExpertM1::
# 106 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_SeaRemainsForeverYoung, MSGBOX_SIGN
# 107 "data/maps/LilycoveCity/scripts.pory"
	end
# 108 "data/maps/LilycoveCity/scripts.pory"

# 109 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_ExpertF::
# 110 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_SixtyYearsAgoHusbandProposed, MSGBOX_SIGN
# 111 "data/maps/LilycoveCity/scripts.pory"
	end
# 112 "data/maps/LilycoveCity/scripts.pory"

# 113 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_ExpertM2::
# 114 "data/maps/LilycoveCity/scripts.pory"
	lock
# 115 "data/maps/LilycoveCity/scripts.pory"
	faceplayer
# 116 "data/maps/LilycoveCity/scripts.pory"
	goto_if_set FLAG_BADGE07_GET, LilycoveCity_EventScript_ExpertM2AquaGone
# 117 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_TeamAquaRenovatedCavern, MSGBOX_DEFAULT
# 118 "data/maps/LilycoveCity/scripts.pory"
	release
# 119 "data/maps/LilycoveCity/scripts.pory"
	end
# 120 "data/maps/LilycoveCity/scripts.pory"

# 121 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_ExpertM2AquaGone::
# 122 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_TeamAquaLotGoneForGood, MSGBOX_DEFAULT
# 123 "data/maps/LilycoveCity/scripts.pory"
	release
# 124 "data/maps/LilycoveCity/scripts.pory"
	end
# 125 "data/maps/LilycoveCity/scripts.pory"

# 126 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Sailor1::
# 127 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_HeardTowerCalledSkyPillar, MSGBOX_NPC
# 128 "data/maps/LilycoveCity/scripts.pory"
	end
# 129 "data/maps/LilycoveCity/scripts.pory"

# 130 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_FatMan::
# 131 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_SawTallTowerOnRoute131, MSGBOX_NPC
# 132 "data/maps/LilycoveCity/scripts.pory"
	end
# 133 "data/maps/LilycoveCity/scripts.pory"

# 134 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Man1::
# 135 "data/maps/LilycoveCity/scripts.pory"
	lockall
# 136 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_JustArrivedAndSawRarePokemon, MSGBOX_NPC
# 137 "data/maps/LilycoveCity/scripts.pory"
	applymovement LOCALID_LILYCOVE_MAN_1, Common_Movement_FaceOriginalDirection
# 138 "data/maps/LilycoveCity/scripts.pory"
	end
# 139 "data/maps/LilycoveCity/scripts.pory"

# 140 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Woman1::
# 141 "data/maps/LilycoveCity/scripts.pory"
	lockall
# 142 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_HoneymoonVowToSeeRarePokemon, MSGBOX_NPC
# 143 "data/maps/LilycoveCity/scripts.pory"
	applymovement LOCALID_LILYCOVE_WOMAN_1, Common_Movement_FaceOriginalDirection
# 144 "data/maps/LilycoveCity/scripts.pory"
	end
# 145 "data/maps/LilycoveCity/scripts.pory"

# 146 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_CitySign::
# 147 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_CitySign, MSGBOX_SIGN
# 148 "data/maps/LilycoveCity/scripts.pory"
	end
# 149 "data/maps/LilycoveCity/scripts.pory"

# 150 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_ContestHallSign::
# 151 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_ContestHallSign, MSGBOX_SIGN
# 152 "data/maps/LilycoveCity/scripts.pory"
	end
# 153 "data/maps/LilycoveCity/scripts.pory"

# 154 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_MotelSign::
# 155 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MotelSign, MSGBOX_SIGN
# 156 "data/maps/LilycoveCity/scripts.pory"
	end
# 157 "data/maps/LilycoveCity/scripts.pory"

# 158 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_MuseumSign::
# 159 "data/maps/LilycoveCity/scripts.pory"
	lockall
# 160 "data/maps/LilycoveCity/scripts.pory"
	specialvar VAR_0x8004, CountPlayerMuseumPaintings
# 161 "data/maps/LilycoveCity/scripts.pory"
	switch VAR_0x8004
# 162 "data/maps/LilycoveCity/scripts.pory"
	case 0, LilycoveCity_EventScript_MuseumSignNoPaintings
# 163 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MuseumSignPlayersExhibit, MSGBOX_DEFAULT
# 164 "data/maps/LilycoveCity/scripts.pory"
	releaseall
# 165 "data/maps/LilycoveCity/scripts.pory"
	end
# 166 "data/maps/LilycoveCity/scripts.pory"

# 167 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_MuseumSignNoPaintings::
# 168 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MuseumSign, MSGBOX_DEFAULT
# 169 "data/maps/LilycoveCity/scripts.pory"
	releaseall
# 170 "data/maps/LilycoveCity/scripts.pory"
	end
# 171 "data/maps/LilycoveCity/scripts.pory"

# 172 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_HarborSign::
# 173 "data/maps/LilycoveCity/scripts.pory"
	lockall
# 174 "data/maps/LilycoveCity/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_EventScript_HarborSignFerryReady
# 175 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_HarborSignUnderConstruction, MSGBOX_DEFAULT
# 176 "data/maps/LilycoveCity/scripts.pory"
	releaseall
# 177 "data/maps/LilycoveCity/scripts.pory"
	end
# 178 "data/maps/LilycoveCity/scripts.pory"

# 179 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_HarborSignFerryReady::
# 180 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_HarborSign, MSGBOX_DEFAULT
# 181 "data/maps/LilycoveCity/scripts.pory"
	releaseall
# 182 "data/maps/LilycoveCity/scripts.pory"
	end
# 183 "data/maps/LilycoveCity/scripts.pory"

# 184 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_TrainerFanClubSign::
# 185 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_TrainerFanClubSign, MSGBOX_SIGN
# 186 "data/maps/LilycoveCity/scripts.pory"
	end
# 187 "data/maps/LilycoveCity/scripts.pory"

# 188 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_DepartmentStoreSign::
# 189 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_DepartmentStoreSign, MSGBOX_SIGN
# 190 "data/maps/LilycoveCity/scripts.pory"
	end
# 191 "data/maps/LilycoveCity/scripts.pory"

# 192 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_MoveDeletersHouseSign::
# 193 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MoveDeletersHouseSign, MSGBOX_SIGN
# 194 "data/maps/LilycoveCity/scripts.pory"
	end
# 195 "data/maps/LilycoveCity/scripts.pory"

# 196 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_WailmerTrainerGrunt::
# 197 "data/maps/LilycoveCity/scripts.pory"
	lockall
# 198 "data/maps/LilycoveCity/scripts.pory"
	goto_if_set FLAG_MET_WAILMER_TRAINER, LilycoveCity_EventScript_MetWailmerTrainer
# 199 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_WailmerLeapOutOfWater, MSGBOX_DEFAULT
# 200 "data/maps/LilycoveCity/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
# 201 "data/maps/LilycoveCity/scripts.pory"
	waitmovement 0
# 202 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_GetLostMessingUpTraining, MSGBOX_DEFAULT
# 203 "data/maps/LilycoveCity/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 204 "data/maps/LilycoveCity/scripts.pory"
	waitmovement 0
# 205 "data/maps/LilycoveCity/scripts.pory"
	setflag FLAG_MET_WAILMER_TRAINER
# 206 "data/maps/LilycoveCity/scripts.pory"
	releaseall
# 207 "data/maps/LilycoveCity/scripts.pory"
	end
# 208 "data/maps/LilycoveCity/scripts.pory"

# 209 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_MetWailmerTrainer::
# 210 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_WailmerLeapOutOfWater, MSGBOX_DEFAULT
# 211 "data/maps/LilycoveCity/scripts.pory"
	releaseall
# 212 "data/maps/LilycoveCity/scripts.pory"
	end
# 213 "data/maps/LilycoveCity/scripts.pory"

# 214 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_AquaGrunt1::
# 215 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MovedLootIntoHideoutToday, MSGBOX_NPC
# 216 "data/maps/LilycoveCity/scripts.pory"
	end
# 217 "data/maps/LilycoveCity/scripts.pory"

# 218 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_AquaGrunt2::
# 219 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_ChanceToDoBigThings, MSGBOX_NPC
# 220 "data/maps/LilycoveCity/scripts.pory"
	end
# 221 "data/maps/LilycoveCity/scripts.pory"

# 222 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_AquaGrunt3::
# 223 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_DontGoNearCaveInCove, MSGBOX_NPC
# 224 "data/maps/LilycoveCity/scripts.pory"
	end
# 225 "data/maps/LilycoveCity/scripts.pory"

# 226 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_AquaGrunt4::
# 227 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_IfWorldBecomesOurs, MSGBOX_NPC
# 228 "data/maps/LilycoveCity/scripts.pory"
	end
# 229 "data/maps/LilycoveCity/scripts.pory"

# 230 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Rival::
# 231 "data/maps/LilycoveCity/scripts.pory"
	lock
# 232 "data/maps/LilycoveCity/scripts.pory"
	faceplayer
# 233 "data/maps/LilycoveCity/scripts.pory"
	checkplayergender
# 234 "data/maps/LilycoveCity/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, LilycoveCity_EventScript_May
# 235 "data/maps/LilycoveCity/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, LilycoveCity_EventScript_Brendan
# 236 "data/maps/LilycoveCity/scripts.pory"
	end
# 237 "data/maps/LilycoveCity/scripts.pory"

# 238 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_May::
# 239 "data/maps/LilycoveCity/scripts.pory"
	playbgm MUS_ENCOUNTER_MAY, TRUE
# 240 "data/maps/LilycoveCity/scripts.pory"
	call_if_set FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_MayAskToBattleAgain
# 241 "data/maps/LilycoveCity/scripts.pory"
	call_if_unset FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_MayAskToBattle
# 242 "data/maps/LilycoveCity/scripts.pory"
	goto_if_eq VAR_RESULT, NO, LilycoveCity_EventScript_DeclineMayBattle
# 243 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MayWontBeBeaten, MSGBOX_DEFAULT
# 244 "data/maps/LilycoveCity/scripts.pory"
	switch VAR_STARTER_MON
# 245 "data/maps/LilycoveCity/scripts.pory"
	case 0, LilycoveCity_EventScript_BattleMayTreecko
# 246 "data/maps/LilycoveCity/scripts.pory"
	case 1, LilycoveCity_EventScript_BattleMayTorchic
# 247 "data/maps/LilycoveCity/scripts.pory"
	case 2, LilycoveCity_EventScript_BattleMayMudkip
# 248 "data/maps/LilycoveCity/scripts.pory"
	end
# 249 "data/maps/LilycoveCity/scripts.pory"

# 250 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_MayAskToBattleAgain::
# 251 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MayBattleMe, MSGBOX_YESNO
# 252 "data/maps/LilycoveCity/scripts.pory"
	return
# 253 "data/maps/LilycoveCity/scripts.pory"

# 254 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_MayAskToBattle::
# 255 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MayShoppingLetsBattle, MSGBOX_YESNO
# 256 "data/maps/LilycoveCity/scripts.pory"
	return
# 257 "data/maps/LilycoveCity/scripts.pory"

# 258 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_DeclineMayBattle::
# 259 "data/maps/LilycoveCity/scripts.pory"
	setflag FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE
# 260 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MayNotRaisingPokemon, MSGBOX_DEFAULT
# 261 "data/maps/LilycoveCity/scripts.pory"
	savebgm MUS_DUMMY
# 262 "data/maps/LilycoveCity/scripts.pory"
	fadedefaultbgm
# 263 "data/maps/LilycoveCity/scripts.pory"
	release
# 264 "data/maps/LilycoveCity/scripts.pory"
	end
# 265 "data/maps/LilycoveCity/scripts.pory"

# 266 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Brendan::
# 267 "data/maps/LilycoveCity/scripts.pory"
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
# 268 "data/maps/LilycoveCity/scripts.pory"
	call_if_set FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_BrendanAskToBattleAgain
# 269 "data/maps/LilycoveCity/scripts.pory"
	call_if_unset FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_BrendanAskToBattle
# 270 "data/maps/LilycoveCity/scripts.pory"
	goto_if_eq VAR_RESULT, NO, LilycoveCity_EventScript_DeclineBrendanBattle
# 271 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_BrendanWontBeBeaten, MSGBOX_DEFAULT
# 272 "data/maps/LilycoveCity/scripts.pory"
	switch VAR_STARTER_MON
# 273 "data/maps/LilycoveCity/scripts.pory"
	case 0, LilycoveCity_EventScript_BattleBrendanTreecko
# 274 "data/maps/LilycoveCity/scripts.pory"
	case 1, LilycoveCity_EventScript_BattleBrendanTorchic
# 275 "data/maps/LilycoveCity/scripts.pory"
	case 2, LilycoveCity_EventScript_BattleBrendanMudkip
# 276 "data/maps/LilycoveCity/scripts.pory"
	end
# 277 "data/maps/LilycoveCity/scripts.pory"

# 278 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BrendanAskToBattleAgain::
# 279 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_BrendanBattleMe, MSGBOX_YESNO
# 280 "data/maps/LilycoveCity/scripts.pory"
	return
# 281 "data/maps/LilycoveCity/scripts.pory"

# 282 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BrendanAskToBattle::
# 283 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_BrendanShoppingLetsBattle, MSGBOX_YESNO
# 284 "data/maps/LilycoveCity/scripts.pory"
	return
# 285 "data/maps/LilycoveCity/scripts.pory"

# 286 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_DeclineBrendanBattle::
# 287 "data/maps/LilycoveCity/scripts.pory"
	setflag FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE
# 288 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_BrendanNoConfidence, MSGBOX_DEFAULT
# 289 "data/maps/LilycoveCity/scripts.pory"
	savebgm MUS_DUMMY
# 290 "data/maps/LilycoveCity/scripts.pory"
	fadedefaultbgm
# 291 "data/maps/LilycoveCity/scripts.pory"
	release
# 292 "data/maps/LilycoveCity/scripts.pory"
	end
# 293 "data/maps/LilycoveCity/scripts.pory"

# 294 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BattleMayTreecko::
# 295 "data/maps/LilycoveCity/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_LILYCOVE_TREECKO, LilycoveCity_Text_MayDefeat
# 296 "data/maps/LilycoveCity/scripts.pory"
	goto LilycoveCity_EventScript_DefeatedMay
# 297 "data/maps/LilycoveCity/scripts.pory"
	end
# 298 "data/maps/LilycoveCity/scripts.pory"

# 299 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BattleMayTorchic::
# 300 "data/maps/LilycoveCity/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_LILYCOVE_TORCHIC, LilycoveCity_Text_MayDefeat
# 301 "data/maps/LilycoveCity/scripts.pory"
	goto LilycoveCity_EventScript_DefeatedMay
# 302 "data/maps/LilycoveCity/scripts.pory"
	end
# 303 "data/maps/LilycoveCity/scripts.pory"

# 304 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BattleMayMudkip::
# 305 "data/maps/LilycoveCity/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_LILYCOVE_MUDKIP, LilycoveCity_Text_MayDefeat
# 306 "data/maps/LilycoveCity/scripts.pory"
	goto LilycoveCity_EventScript_DefeatedMay
# 307 "data/maps/LilycoveCity/scripts.pory"
	end
# 308 "data/maps/LilycoveCity/scripts.pory"

# 309 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BattleBrendanTreecko::
# 310 "data/maps/LilycoveCity/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_LILYCOVE_TREECKO, LilycoveCity_Text_BrendanDefeat
# 311 "data/maps/LilycoveCity/scripts.pory"
	goto LilycoveCity_EventScript_DefeatedBrendan
# 312 "data/maps/LilycoveCity/scripts.pory"
	end
# 313 "data/maps/LilycoveCity/scripts.pory"

# 314 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BattleBrendanTorchic::
# 315 "data/maps/LilycoveCity/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_LILYCOVE_TORCHIC, LilycoveCity_Text_BrendanDefeat
# 316 "data/maps/LilycoveCity/scripts.pory"
	goto LilycoveCity_EventScript_DefeatedBrendan
# 317 "data/maps/LilycoveCity/scripts.pory"
	end
# 318 "data/maps/LilycoveCity/scripts.pory"

# 319 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BattleBrendanMudkip::
# 320 "data/maps/LilycoveCity/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_LILYCOVE_MUDKIP, LilycoveCity_Text_BrendanDefeat
# 321 "data/maps/LilycoveCity/scripts.pory"
	goto LilycoveCity_EventScript_DefeatedBrendan
# 322 "data/maps/LilycoveCity/scripts.pory"
	end
# 323 "data/maps/LilycoveCity/scripts.pory"

# 324 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_DefeatedMay::
# 325 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MayGoingBackToLittleroot, MSGBOX_DEFAULT
# 326 "data/maps/LilycoveCity/scripts.pory"
	setvar VAR_RESULT, FALSE
# 327 "data/maps/LilycoveCity/scripts.pory"
	call_if_set FLAG_BADGE06_GET, LilycoveCity_EventScript_CheckFinalBadge
# 328 "data/maps/LilycoveCity/scripts.pory"
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_EventScript_MayCollectBadges
# 329 "data/maps/LilycoveCity/scripts.pory"
	call_if_eq VAR_RESULT, TRUE, LilycoveCity_EventScript_MayPokemonLeague
# 330 "data/maps/LilycoveCity/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_BEDROOM
# 331 "data/maps/LilycoveCity/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_2F_PICHU_DOLL
# 332 "data/maps/LilycoveCity/scripts.pory"
	goto LilycoveCity_EventScript_RivalFlyAway
# 333 "data/maps/LilycoveCity/scripts.pory"
	end
# 334 "data/maps/LilycoveCity/scripts.pory"

# 335 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_CheckFinalBadge::
# 336 "data/maps/LilycoveCity/scripts.pory"
	goto_if_set FLAG_BADGE08_GET, LilycoveCity_EventScript_HasFinalBadge
# 337 "data/maps/LilycoveCity/scripts.pory"
	return
# 338 "data/maps/LilycoveCity/scripts.pory"

# 339 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_HasFinalBadge::
# 340 "data/maps/LilycoveCity/scripts.pory"
	setvar VAR_RESULT, TRUE
# 341 "data/maps/LilycoveCity/scripts.pory"
	return
# 342 "data/maps/LilycoveCity/scripts.pory"

# 343 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_MayCollectBadges::
# 344 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MayYouGoingToCollectBadges, MSGBOX_DEFAULT
# 345 "data/maps/LilycoveCity/scripts.pory"
	return
# 346 "data/maps/LilycoveCity/scripts.pory"

# 347 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_MayPokemonLeague::
# 348 "data/maps/LilycoveCity/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_EventScript_MayBattleFrontier
# 349 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MayYouGoingToPokemonLeague, MSGBOX_DEFAULT
# 350 "data/maps/LilycoveCity/scripts.pory"
	return
# 351 "data/maps/LilycoveCity/scripts.pory"

# 352 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_MayBattleFrontier::
# 353 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MayYouGoingToBattleFrontier, MSGBOX_DEFAULT
# 354 "data/maps/LilycoveCity/scripts.pory"
	return
# 355 "data/maps/LilycoveCity/scripts.pory"

# 356 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_DefeatedBrendan::
# 357 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_BrendanGoingBackToLittleroot, MSGBOX_DEFAULT
# 358 "data/maps/LilycoveCity/scripts.pory"
	setvar VAR_RESULT, FALSE
# 359 "data/maps/LilycoveCity/scripts.pory"
	call_if_set FLAG_BADGE06_GET, LilycoveCity_EventScript_CheckFinalBadge
# 360 "data/maps/LilycoveCity/scripts.pory"
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_EventScript_BrendanCollectBadges
# 361 "data/maps/LilycoveCity/scripts.pory"
	call_if_eq VAR_RESULT, TRUE, LilycoveCity_EventScript_BrendanPokemonLeague
# 362 "data/maps/LilycoveCity/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_BEDROOM
# 363 "data/maps/LilycoveCity/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_SWABLU_DOLL
# 364 "data/maps/LilycoveCity/scripts.pory"
	goto LilycoveCity_EventScript_RivalFlyAway
# 365 "data/maps/LilycoveCity/scripts.pory"
	end
# 366 "data/maps/LilycoveCity/scripts.pory"

# 367 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BrendanCollectBadges::
# 368 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_BrendanYouGoingToCollectBadges, MSGBOX_DEFAULT
# 369 "data/maps/LilycoveCity/scripts.pory"
	return
# 370 "data/maps/LilycoveCity/scripts.pory"

# 371 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BrendanPokemonLeague::
# 372 "data/maps/LilycoveCity/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_EventScript_BrendanBattleFrontier
# 373 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_BrendanYouGoingToPokemonLeague, MSGBOX_DEFAULT
# 374 "data/maps/LilycoveCity/scripts.pory"
	return
# 375 "data/maps/LilycoveCity/scripts.pory"

# 376 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BrendanBattleFrontier::
# 377 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_BrendanYouGoingToBattleFrontier, MSGBOX_DEFAULT
# 378 "data/maps/LilycoveCity/scripts.pory"
	return
# 379 "data/maps/LilycoveCity/scripts.pory"

# 380 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_RivalFlyAway::
# 381 "data/maps/LilycoveCity/scripts.pory"
	closemessage
# 382 "data/maps/LilycoveCity/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
# 383 "data/maps/LilycoveCity/scripts.pory"
	waitmovement 0
# 384 "data/maps/LilycoveCity/scripts.pory"
	delay 50
# 385 "data/maps/LilycoveCity/scripts.pory"
	setfieldeffectargument 0, 1
# 386 "data/maps/LilycoveCity/scripts.pory"
	dofieldeffect FLDEFF_NPCFLY_OUT
# 387 "data/maps/LilycoveCity/scripts.pory"
	delay 15
# 388 "data/maps/LilycoveCity/scripts.pory"
	removeobject VAR_LAST_TALKED
# 389 "data/maps/LilycoveCity/scripts.pory"
	waitfieldeffect FLDEFF_NPCFLY_OUT
# 390 "data/maps/LilycoveCity/scripts.pory"
	savebgm MUS_DUMMY
# 391 "data/maps/LilycoveCity/scripts.pory"
	fadedefaultbgm
# 392 "data/maps/LilycoveCity/scripts.pory"
	setflag FLAG_MET_RIVAL_LILYCOVE
# 393 "data/maps/LilycoveCity/scripts.pory"
	release
# 394 "data/maps/LilycoveCity/scripts.pory"
	end
# 395 "data/maps/LilycoveCity/scripts.pory"

# 396 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_SchoolKidM::
# 397 "data/maps/LilycoveCity/scripts.pory"
	lock
# 398 "data/maps/LilycoveCity/scripts.pory"
	faceplayer
# 399 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_DoYouKnowAboutBerryBlender, MSGBOX_YESNO
# 400 "data/maps/LilycoveCity/scripts.pory"
	call_if_eq VAR_RESULT, YES, LilycoveCity_EventScript_KnowAboutBerryBlender
# 401 "data/maps/LilycoveCity/scripts.pory"
	call_if_eq VAR_RESULT, NO, LilycoveCity_EventScript_DontKnowAboutBerryBlender
# 402 "data/maps/LilycoveCity/scripts.pory"
	release
# 403 "data/maps/LilycoveCity/scripts.pory"
	end
# 404 "data/maps/LilycoveCity/scripts.pory"

# 405 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_KnowAboutBerryBlender::
# 406 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_FasterSpinBetterPokeblocks, MSGBOX_DEFAULT
# 407 "data/maps/LilycoveCity/scripts.pory"
	return
# 408 "data/maps/LilycoveCity/scripts.pory"

# 409 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_DontKnowAboutBerryBlender::
# 410 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_ExplainBerryBlender, MSGBOX_DEFAULT
# 411 "data/maps/LilycoveCity/scripts.pory"
	return
# 412 "data/maps/LilycoveCity/scripts.pory"

# 413 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MayShoppingLetsBattle:
# 414 "data/maps/LilycoveCity/scripts.pory"
	.string "MAY: Oh, hey?\n"
# 415 "data/maps/LilycoveCity/scripts.pory"
	.string "{PLAYER}{KUN}, are you shopping, too?\p"
# 416 "data/maps/LilycoveCity/scripts.pory"
	.string "I bought a whole bunch of DOLLS and\n"
# 417 "data/maps/LilycoveCity/scripts.pory"
	.string "POSTERS.\p"
# 418 "data/maps/LilycoveCity/scripts.pory"
	.string "Of course, I've also caught a lot of\n"
# 419 "data/maps/LilycoveCity/scripts.pory"
	.string "POKéMON, and I'm raising them\l"
# 420 "data/maps/LilycoveCity/scripts.pory"
	.string "properly, too.\p"
# 421 "data/maps/LilycoveCity/scripts.pory"
	.string "Actually, I'm more worried if you're\n"
# 422 "data/maps/LilycoveCity/scripts.pory"
	.string "raising POKéMON properly, {PLAYER}{KUN}.\p"
# 423 "data/maps/LilycoveCity/scripts.pory"
	.string "I'll battle with you, so you can show\n"
# 424 "data/maps/LilycoveCity/scripts.pory"
	.string "me your POKéMON, {PLAYER}{KUN}.$"
# 425 "data/maps/LilycoveCity/scripts.pory"

# 426 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MayNotRaisingPokemon:
# 427 "data/maps/LilycoveCity/scripts.pory"
	.string "MAY: Oh, why? {PLAYER}{KUN}, haven't you\n"
# 428 "data/maps/LilycoveCity/scripts.pory"
	.string "been raising your POKéMON?\p"
# 429 "data/maps/LilycoveCity/scripts.pory"
	.string "That's not a very good showing as a\n"
# 430 "data/maps/LilycoveCity/scripts.pory"
	.string "TRAINER…$"
# 431 "data/maps/LilycoveCity/scripts.pory"

# 432 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MayBattleMe:
# 433 "data/maps/LilycoveCity/scripts.pory"
	.string "MAY: Come on, battle with me, so I can\n"
# 434 "data/maps/LilycoveCity/scripts.pory"
	.string "check out your POKéMON!$"
# 435 "data/maps/LilycoveCity/scripts.pory"

# 436 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MayWontBeBeaten:
# 437 "data/maps/LilycoveCity/scripts.pory"
	.string "MAY: The POKéMON I raised won't be\n"
# 438 "data/maps/LilycoveCity/scripts.pory"
	.string "beaten by your POKéMON, {PLAYER}{KUN}!$"
# 439 "data/maps/LilycoveCity/scripts.pory"

# 440 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MayDefeat:
# 441 "data/maps/LilycoveCity/scripts.pory"
	.string "… … … … … … … …\p"
# 442 "data/maps/LilycoveCity/scripts.pory"
	.string "I remember the battle I had with you,\n"
# 443 "data/maps/LilycoveCity/scripts.pory"
	.string "{PLAYER}{KUN}, on ROUTE 103.\p"
# 444 "data/maps/LilycoveCity/scripts.pory"
	.string "That battle helped you become this\n"
# 445 "data/maps/LilycoveCity/scripts.pory"
	.string "strong, {PLAYER}{KUN}, didn't it?$"
# 446 "data/maps/LilycoveCity/scripts.pory"

# 447 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MayGoingBackToLittleroot:
# 448 "data/maps/LilycoveCity/scripts.pory"
	.string "MAY: I'm thinking of going back to\n"
# 449 "data/maps/LilycoveCity/scripts.pory"
	.string "LITTLEROOT soon.\p"
# 450 "data/maps/LilycoveCity/scripts.pory"
	.string "I've caught a decent group of POKéMON,\n"
# 451 "data/maps/LilycoveCity/scripts.pory"
	.string "and my POKéDEX is coming along, so\l"
# 452 "data/maps/LilycoveCity/scripts.pory"
	.string "I'm going home to show my dad.$"
# 453 "data/maps/LilycoveCity/scripts.pory"

# 454 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MayYouGoingToCollectBadges:
# 455 "data/maps/LilycoveCity/scripts.pory"
	.string "{PLAYER}{KUN}, what are you going to do?\p"
# 456 "data/maps/LilycoveCity/scripts.pory"
	.string "Collect all the GYM BADGES and take\n"
# 457 "data/maps/LilycoveCity/scripts.pory"
	.string "the POKéMON LEAGUE challenge?\p"
# 458 "data/maps/LilycoveCity/scripts.pory"
	.string "Well, while you're collecting BADGES,\n"
# 459 "data/maps/LilycoveCity/scripts.pory"
	.string "{PLAYER}{KUN}, I'm going to work on my\l"
# 460 "data/maps/LilycoveCity/scripts.pory"
	.string "POKéDEX. I'll complete it before you!\p"
# 461 "data/maps/LilycoveCity/scripts.pory"
	.string "See you!$"
# 462 "data/maps/LilycoveCity/scripts.pory"

# 463 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MayYouGoingToPokemonLeague:
# 464 "data/maps/LilycoveCity/scripts.pory"
	.string "{PLAYER}{KUN}, what are you going to do?\p"
# 465 "data/maps/LilycoveCity/scripts.pory"
	.string "Are you taking the POKéMON LEAGUE\n"
# 466 "data/maps/LilycoveCity/scripts.pory"
	.string "challenge?\p"
# 467 "data/maps/LilycoveCity/scripts.pory"
	.string "Or, are you going to complete your\n"
# 468 "data/maps/LilycoveCity/scripts.pory"
	.string "POKéDEX?\p"
# 469 "data/maps/LilycoveCity/scripts.pory"
	.string "I might've lost to you in battling,\n"
# 470 "data/maps/LilycoveCity/scripts.pory"
	.string "but I'll finish my POKéDEX before you!\p"
# 471 "data/maps/LilycoveCity/scripts.pory"
	.string "See you!$"
# 472 "data/maps/LilycoveCity/scripts.pory"

# 473 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MayYouGoingToBattleFrontier:
# 474 "data/maps/LilycoveCity/scripts.pory"
	.string "{PLAYER}{KUN}, what are you going to do?\p"
# 475 "data/maps/LilycoveCity/scripts.pory"
	.string "Are you taking the BATTLE FRONTIER\n"
# 476 "data/maps/LilycoveCity/scripts.pory"
	.string "challenge?\p"
# 477 "data/maps/LilycoveCity/scripts.pory"
	.string "Or, are you going to complete your\n"
# 478 "data/maps/LilycoveCity/scripts.pory"
	.string "POKéDEX?\p"
# 479 "data/maps/LilycoveCity/scripts.pory"
	.string "I might've lost to you in battling,\n"
# 480 "data/maps/LilycoveCity/scripts.pory"
	.string "but I'll finish my POKéDEX before you!\p"
# 481 "data/maps/LilycoveCity/scripts.pory"
	.string "See you!$"
# 482 "data/maps/LilycoveCity/scripts.pory"

# 483 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_BrendanShoppingLetsBattle:
# 484 "data/maps/LilycoveCity/scripts.pory"
	.string "BRENDAN: Oh, hey, it's {PLAYER}.\p"
# 485 "data/maps/LilycoveCity/scripts.pory"
	.string "I'm running an errand for my dad.\n"
# 486 "data/maps/LilycoveCity/scripts.pory"
	.string "No, I'm not buying any DOLLS.\p"
# 487 "data/maps/LilycoveCity/scripts.pory"
	.string "Anyways, it's been a while.\p"
# 488 "data/maps/LilycoveCity/scripts.pory"
	.string "Want to have a battle to see who's been\n"
# 489 "data/maps/LilycoveCity/scripts.pory"
	.string "raising POKéMON better?$"
# 490 "data/maps/LilycoveCity/scripts.pory"

# 491 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_BrendanNoConfidence:
# 492 "data/maps/LilycoveCity/scripts.pory"
	.string "BRENDAN: Oh, what's the matter?\n"
# 493 "data/maps/LilycoveCity/scripts.pory"
	.string "Don't have the confidence?$"
# 494 "data/maps/LilycoveCity/scripts.pory"

# 495 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_BrendanBattleMe:
# 496 "data/maps/LilycoveCity/scripts.pory"
	.string "BRENDAN: Want to battle to see who's\n"
# 497 "data/maps/LilycoveCity/scripts.pory"
	.string "been raising POKéMON better?$"
# 498 "data/maps/LilycoveCity/scripts.pory"

# 499 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_BrendanWontBeBeaten:
# 500 "data/maps/LilycoveCity/scripts.pory"
	.string "BRENDAN: Aww, but you know I'm not\n"
# 501 "data/maps/LilycoveCity/scripts.pory"
	.string "going to lose to no {PLAYER}.$"
# 502 "data/maps/LilycoveCity/scripts.pory"

# 503 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_BrendanDefeat:
# 504 "data/maps/LilycoveCity/scripts.pory"
	.string "Humph…\n"
# 505 "data/maps/LilycoveCity/scripts.pory"
	.string "You've done a lot of raising.\p"
# 506 "data/maps/LilycoveCity/scripts.pory"
	.string "That stings a bit--I had a head start\n"
# 507 "data/maps/LilycoveCity/scripts.pory"
	.string "on you as a TRAINER…$"
# 508 "data/maps/LilycoveCity/scripts.pory"

# 509 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_BrendanGoingBackToLittleroot:
# 510 "data/maps/LilycoveCity/scripts.pory"
	.string "BRENDAN: I…\n"
# 511 "data/maps/LilycoveCity/scripts.pory"
	.string "I plan on going home to LITTLEROOT.\p"
# 512 "data/maps/LilycoveCity/scripts.pory"
	.string "You know I'm helping out my dad on his\n"
# 513 "data/maps/LilycoveCity/scripts.pory"
	.string "POKéDEX. It's coming together pretty\l"
# 514 "data/maps/LilycoveCity/scripts.pory"
	.string "decently, so I should go show him.$"
# 515 "data/maps/LilycoveCity/scripts.pory"

# 516 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_BrendanYouGoingToCollectBadges:
# 517 "data/maps/LilycoveCity/scripts.pory"
	.string "{PLAYER}, what are you going to do?\p"
# 518 "data/maps/LilycoveCity/scripts.pory"
	.string "Collect all the GYM BADGES and take\n"
# 519 "data/maps/LilycoveCity/scripts.pory"
	.string "the POKéMON LEAGUE challenge?\p"
# 520 "data/maps/LilycoveCity/scripts.pory"
	.string "Maybe I'll do that, too…\p"
# 521 "data/maps/LilycoveCity/scripts.pory"
	.string "Well, anyway, hang in there!$"
# 522 "data/maps/LilycoveCity/scripts.pory"

# 523 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_BrendanYouGoingToPokemonLeague:
# 524 "data/maps/LilycoveCity/scripts.pory"
	.string "{PLAYER}, what are you going to do?\p"
# 525 "data/maps/LilycoveCity/scripts.pory"
	.string "Since you're that strong, are you\n"
# 526 "data/maps/LilycoveCity/scripts.pory"
	.string "taking the POKéMON LEAGUE challenge?\p"
# 527 "data/maps/LilycoveCity/scripts.pory"
	.string "Heh, even me--if I trained my POKéMON\n"
# 528 "data/maps/LilycoveCity/scripts.pory"
	.string "a bit more, I should be stronger than\l"
# 529 "data/maps/LilycoveCity/scripts.pory"
	.string "you, {PLAYER}.\p"
# 530 "data/maps/LilycoveCity/scripts.pory"
	.string "Well, anyway, hang in there!$"
# 531 "data/maps/LilycoveCity/scripts.pory"

# 532 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_BrendanYouGoingToBattleFrontier:
# 533 "data/maps/LilycoveCity/scripts.pory"
	.string "{PLAYER}, what are you going to do?\p"
# 534 "data/maps/LilycoveCity/scripts.pory"
	.string "Are you taking the BATTLE FRONTIER\n"
# 535 "data/maps/LilycoveCity/scripts.pory"
	.string "challenge?\p"
# 536 "data/maps/LilycoveCity/scripts.pory"
	.string "Or, are you going to complete your\n"
# 537 "data/maps/LilycoveCity/scripts.pory"
	.string "POKéDEX?\p"
# 538 "data/maps/LilycoveCity/scripts.pory"
	.string "Since you're that strong, you should\n"
# 539 "data/maps/LilycoveCity/scripts.pory"
	.string "consider the BATTLE FRONTIER.\p"
# 540 "data/maps/LilycoveCity/scripts.pory"
	.string "Heh, if I train my POKéMON a bit more,\n"
# 541 "data/maps/LilycoveCity/scripts.pory"
	.string "I'll get stronger than you, {PLAYER}.\p"
# 542 "data/maps/LilycoveCity/scripts.pory"
	.string "Maybe I should go to the BATTLE\n"
# 543 "data/maps/LilycoveCity/scripts.pory"
	.string "FRONTIER.\p"
# 544 "data/maps/LilycoveCity/scripts.pory"
	.string "Well, anyway, hang in there!$"
# 545 "data/maps/LilycoveCity/scripts.pory"

# 546 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MovedLootIntoHideoutToday:
# 547 "data/maps/LilycoveCity/scripts.pory"
	.string "Fufufu…\p"
# 548 "data/maps/LilycoveCity/scripts.pory"
	.string "We moved more loot into our secret\n"
# 549 "data/maps/LilycoveCity/scripts.pory"
	.string "HIDEOUT today…\p"
# 550 "data/maps/LilycoveCity/scripts.pory"
	.string "Wh-who are you?!\n"
# 551 "data/maps/LilycoveCity/scripts.pory"
	.string "I was just talking to myself!$"
# 552 "data/maps/LilycoveCity/scripts.pory"

# 553 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_ChanceToDoBigThings:
# 554 "data/maps/LilycoveCity/scripts.pory"
	.string "I'm just a GRUNT, so I don't know what\n"
# 555 "data/maps/LilycoveCity/scripts.pory"
	.string "the BOSS is thinking…\p"
# 556 "data/maps/LilycoveCity/scripts.pory"
	.string "But being on TEAM AQUA, I know I'll get\n"
# 557 "data/maps/LilycoveCity/scripts.pory"
	.string "the chance to do big things!\p"
# 558 "data/maps/LilycoveCity/scripts.pory"
	.string "Wh-who are you?!\n"
# 559 "data/maps/LilycoveCity/scripts.pory"
	.string "I was just talking to myself!$"
# 560 "data/maps/LilycoveCity/scripts.pory"

# 561 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_DontGoNearCaveInCove:
# 562 "data/maps/LilycoveCity/scripts.pory"
	.string "Hey, you!\p"
# 563 "data/maps/LilycoveCity/scripts.pory"
	.string "Don't go near the cave in the cove!\p"
# 564 "data/maps/LilycoveCity/scripts.pory"
	.string "Why? You don't need a reason why!\n"
# 565 "data/maps/LilycoveCity/scripts.pory"
	.string "I'm an adult, so you just listen to me!$"
# 566 "data/maps/LilycoveCity/scripts.pory"

# 567 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_IfWorldBecomesOurs:
# 568 "data/maps/LilycoveCity/scripts.pory"
	.string "If this whole wide world becomes ours,\n"
# 569 "data/maps/LilycoveCity/scripts.pory"
	.string "TEAM AQUA's, it will be a happier\l"
# 570 "data/maps/LilycoveCity/scripts.pory"
	.string "place for POKéMON, too.$"
# 571 "data/maps/LilycoveCity/scripts.pory"

# 572 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_WailmerLeapOutOfWater:
# 573 "data/maps/LilycoveCity/scripts.pory"
	.string "There! WAILMER!\n"
# 574 "data/maps/LilycoveCity/scripts.pory"
	.string "Leap out of the water now!$"
# 575 "data/maps/LilycoveCity/scripts.pory"

# 576 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_GetLostMessingUpTraining:
# 577 "data/maps/LilycoveCity/scripts.pory"
	.string "Hunh? What do you want?\p"
# 578 "data/maps/LilycoveCity/scripts.pory"
	.string "You're messing up our training,\n"
# 579 "data/maps/LilycoveCity/scripts.pory"
	.string "so can you, like, get lost?$"
# 580 "data/maps/LilycoveCity/scripts.pory"

# 581 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_ContestHallInTown:
# 582 "data/maps/LilycoveCity/scripts.pory"
	.string "There's a POKéMON CONTEST HALL\n"
# 583 "data/maps/LilycoveCity/scripts.pory"
	.string "right in this here town. \p"
# 584 "data/maps/LilycoveCity/scripts.pory"
	.string "That means well-raised POKéMON will\n"
# 585 "data/maps/LilycoveCity/scripts.pory"
	.string "come from all over the country.\p"
# 586 "data/maps/LilycoveCity/scripts.pory"
	.string "My heart swells with excitement!$"
# 587 "data/maps/LilycoveCity/scripts.pory"

# 588 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_StrangeCaveInCove:
# 589 "data/maps/LilycoveCity/scripts.pory"
	.string "Have you seen that strange cave in\n"
# 590 "data/maps/LilycoveCity/scripts.pory"
	.string "the cove at the edge of town?$"
# 591 "data/maps/LilycoveCity/scripts.pory"

# 592 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_GoingToMoveDeleterForHMs:
# 593 "data/maps/LilycoveCity/scripts.pory"
	.string "I'm going to teach my POKéMON some new\n"
# 594 "data/maps/LilycoveCity/scripts.pory"
	.string "moves for entering a CONTEST.\p"
# 595 "data/maps/LilycoveCity/scripts.pory"
	.string "So, I'm going to see the MOVE DELETER\n"
# 596 "data/maps/LilycoveCity/scripts.pory"
	.string "and make it forget HM moves.$"
# 597 "data/maps/LilycoveCity/scripts.pory"

# 598 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_ImFromKanto:
# 599 "data/maps/LilycoveCity/scripts.pory"
	.string "I came from KANTO.\p"
# 600 "data/maps/LilycoveCity/scripts.pory"
	.string "The HOENN region is beautiful with\n"
# 601 "data/maps/LilycoveCity/scripts.pory"
	.string "all its water and verdant nature.\p"
# 602 "data/maps/LilycoveCity/scripts.pory"
	.string "Hunh? Wait a second…\p"
# 603 "data/maps/LilycoveCity/scripts.pory"
	.string "Could there be rare POKéMON that live\n"
# 604 "data/maps/LilycoveCity/scripts.pory"
	.string "only in this area?$"
# 605 "data/maps/LilycoveCity/scripts.pory"

# 606 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_TeamAquaBeenTrainingWailmer:
# 607 "data/maps/LilycoveCity/scripts.pory"
	.string "TEAM AQUA's been training their\n"
# 608 "data/maps/LilycoveCity/scripts.pory"
	.string "WAILMER in the cove.\p"
# 609 "data/maps/LilycoveCity/scripts.pory"
	.string "We SAILORS can't get our boats out\n"
# 610 "data/maps/LilycoveCity/scripts.pory"
	.string "to sea with them in the way!$"
# 611 "data/maps/LilycoveCity/scripts.pory"

# 612 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_SomeonePuntedTeamAquaOut:
# 613 "data/maps/LilycoveCity/scripts.pory"
	.string "Ahoy, did you know?\p"
# 614 "data/maps/LilycoveCity/scripts.pory"
	.string "Someone punted TEAM AQUA out of\n"
# 615 "data/maps/LilycoveCity/scripts.pory"
	.string "the way for us!\p"
# 616 "data/maps/LilycoveCity/scripts.pory"
	.string "That got the WAILMER out of the cove,\n"
# 617 "data/maps/LilycoveCity/scripts.pory"
	.string "so we can get our boats out again.$"
# 618 "data/maps/LilycoveCity/scripts.pory"

# 619 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_SomeoneStoleMyPokemon:
# 620 "data/maps/LilycoveCity/scripts.pory"
	.string "I was taking a relaxing snooze at the\n"
# 621 "data/maps/LilycoveCity/scripts.pory"
	.string "seaside inn to the sound of waves…\p"
# 622 "data/maps/LilycoveCity/scripts.pory"
	.string "When someone stole my POKéMON!\p"
# 623 "data/maps/LilycoveCity/scripts.pory"
	.string "Who's the abductor?\n"
# 624 "data/maps/LilycoveCity/scripts.pory"
	.string "TEAM AQUA? Is it TEAM AQUA?$"
# 625 "data/maps/LilycoveCity/scripts.pory"

# 626 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MissingPokemonCameBack:
# 627 "data/maps/LilycoveCity/scripts.pory"
	.string "My missing POKéMON…\n"
# 628 "data/maps/LilycoveCity/scripts.pory"
	.string "It came back without me noticing!$"
# 629 "data/maps/LilycoveCity/scripts.pory"

# 630 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_ImArtDealer:
# 631 "data/maps/LilycoveCity/scripts.pory"
	.string "I'm an ART DEALER.\p"
# 632 "data/maps/LilycoveCity/scripts.pory"
	.string "I am a buyer and seller of fine art,\n"
# 633 "data/maps/LilycoveCity/scripts.pory"
	.string "especially paintings.\p"
# 634 "data/maps/LilycoveCity/scripts.pory"
	.string "I've heard that the MUSEUM here has\n"
# 635 "data/maps/LilycoveCity/scripts.pory"
	.string "magnificent works on exhibit…$"
# 636 "data/maps/LilycoveCity/scripts.pory"

# 637 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_SeaRemainsForeverYoung:
# 638 "data/maps/LilycoveCity/scripts.pory"
	.string "Even as we grow old and wrinkled,\n"
# 639 "data/maps/LilycoveCity/scripts.pory"
	.string "the sea remains forever young with\l"
# 640 "data/maps/LilycoveCity/scripts.pory"
	.string "the vivid brilliance of life…\p"
# 641 "data/maps/LilycoveCity/scripts.pory"
	.string "Fwohoho fwohohohoho…$"
# 642 "data/maps/LilycoveCity/scripts.pory"

# 643 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_SixtyYearsAgoHusbandProposed:
# 644 "data/maps/LilycoveCity/scripts.pory"
	.string "It was sixty years ago that my husband\n"
# 645 "data/maps/LilycoveCity/scripts.pory"
	.string "proposed to me here.\l"
# 646 "data/maps/LilycoveCity/scripts.pory"
	.string "The sea remains as beautiful as ever.\p"
# 647 "data/maps/LilycoveCity/scripts.pory"
	.string "Mufufufu mufufufufufu…$"
# 648 "data/maps/LilycoveCity/scripts.pory"

# 649 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_TeamAquaRenovatedCavern:
# 650 "data/maps/LilycoveCity/scripts.pory"
	.string "Hm, you know of the peculiar cavern\n"
# 651 "data/maps/LilycoveCity/scripts.pory"
	.string "in this cove?\p"
# 652 "data/maps/LilycoveCity/scripts.pory"
	.string "That had been a natural formation,\n"
# 653 "data/maps/LilycoveCity/scripts.pory"
	.string "but then that TEAM AQUA lot came\l"
# 654 "data/maps/LilycoveCity/scripts.pory"
	.string "along and made their renovations.\p"
# 655 "data/maps/LilycoveCity/scripts.pory"
	.string "They call themselves\n"
# 656 "data/maps/LilycoveCity/scripts.pory"
	.string "the “nature-loving TEAM AQUA”!\p"
# 657 "data/maps/LilycoveCity/scripts.pory"
	.string "But what they do and what they say\n"
# 658 "data/maps/LilycoveCity/scripts.pory"
	.string "don't match at all!$"
# 659 "data/maps/LilycoveCity/scripts.pory"

# 660 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_TeamAquaLotGoneForGood:
# 661 "data/maps/LilycoveCity/scripts.pory"
	.string "That cave in the cove…\p"
# 662 "data/maps/LilycoveCity/scripts.pory"
	.string "I didn't notice it right away,\n"
# 663 "data/maps/LilycoveCity/scripts.pory"
	.string "but it's completely empty now.\p"
# 664 "data/maps/LilycoveCity/scripts.pory"
	.string "That TEAM AQUA lot, they must\n"
# 665 "data/maps/LilycoveCity/scripts.pory"
	.string "have gone away for good.$"
# 666 "data/maps/LilycoveCity/scripts.pory"

# 667 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_CitySign:
# 668 "data/maps/LilycoveCity/scripts.pory"
	.string "LILYCOVE CITY\p"
# 669 "data/maps/LilycoveCity/scripts.pory"
	.string "“Where the land ends and the\n"
# 670 "data/maps/LilycoveCity/scripts.pory"
	.string "sea begins.”$"
# 671 "data/maps/LilycoveCity/scripts.pory"

# 672 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_ContestHallSign:
# 673 "data/maps/LilycoveCity/scripts.pory"
	.string "POKéMON CONTEST HALL\n"
# 674 "data/maps/LilycoveCity/scripts.pory"
	.string "“The gathering place for TRAINERS!”$"
# 675 "data/maps/LilycoveCity/scripts.pory"

# 676 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MotelSign:
# 677 "data/maps/LilycoveCity/scripts.pory"
	.string "COVE LILY MOTEL\p"
# 678 "data/maps/LilycoveCity/scripts.pory"
	.string "“Remember us as COVE LILY of\n"
# 679 "data/maps/LilycoveCity/scripts.pory"
	.string "LILYCOVE.”$"
# 680 "data/maps/LilycoveCity/scripts.pory"

# 681 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MuseumSign:
# 682 "data/maps/LilycoveCity/scripts.pory"
	.string "LILYCOVE MUSEUM\p"
# 683 "data/maps/LilycoveCity/scripts.pory"
	.string "“POKéMON Masterpiece Collection\n"
# 684 "data/maps/LilycoveCity/scripts.pory"
	.string "on exhibit!”$"
# 685 "data/maps/LilycoveCity/scripts.pory"

# 686 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MuseumSignPlayersExhibit:
# 687 "data/maps/LilycoveCity/scripts.pory"
	.string "LILYCOVE MUSEUM\p"
# 688 "data/maps/LilycoveCity/scripts.pory"
	.string "“{PLAYER}'s POKéMON Collection\n"
# 689 "data/maps/LilycoveCity/scripts.pory"
	.string "on exhibit!”$"
# 690 "data/maps/LilycoveCity/scripts.pory"

# 691 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_HarborSignUnderConstruction:
# 692 "data/maps/LilycoveCity/scripts.pory"
	.string "LILYCOVE CITY HARBOR\p"
# 693 "data/maps/LilycoveCity/scripts.pory"
	.string "“The ferry S.S. TIDAL is under\n"
# 694 "data/maps/LilycoveCity/scripts.pory"
	.string "construction in SLATEPORT CITY.\p"
# 695 "data/maps/LilycoveCity/scripts.pory"
	.string "“Service is scheduled to begin\n"
# 696 "data/maps/LilycoveCity/scripts.pory"
	.string "shortly.”$"
# 697 "data/maps/LilycoveCity/scripts.pory"

# 698 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_HarborSign:
# 699 "data/maps/LilycoveCity/scripts.pory"
	.string "LILYCOVE CITY HARBOR\p"
# 700 "data/maps/LilycoveCity/scripts.pory"
	.string "“Enjoy a delightful cruise on\n"
# 701 "data/maps/LilycoveCity/scripts.pory"
	.string "the ferry S.S. TIDAL.”$"
# 702 "data/maps/LilycoveCity/scripts.pory"

# 703 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_TrainerFanClubSign:
# 704 "data/maps/LilycoveCity/scripts.pory"
	.string "POKéMON TRAINER FAN CLUB\p"
# 705 "data/maps/LilycoveCity/scripts.pory"
	.string "The names of TRAINERS are scribbled\n"
# 706 "data/maps/LilycoveCity/scripts.pory"
	.string "all over the sign…$"
# 707 "data/maps/LilycoveCity/scripts.pory"

# 708 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_DepartmentStoreSign:
# 709 "data/maps/LilycoveCity/scripts.pory"
	.string "LILYCOVE DEPARTMENT STORE\p"
# 710 "data/maps/LilycoveCity/scripts.pory"
	.string "“Overflowing with great merchandise\n"
# 711 "data/maps/LilycoveCity/scripts.pory"
	.string "and excitement!\p"
# 712 "data/maps/LilycoveCity/scripts.pory"
	.string "“A great place to find that something\n"
# 713 "data/maps/LilycoveCity/scripts.pory"
	.string "you need!”$"
# 714 "data/maps/LilycoveCity/scripts.pory"

# 715 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MoveDeletersHouseSign:
# 716 "data/maps/LilycoveCity/scripts.pory"
	.string "MOVE DELETER'S HOUSE\p"
# 717 "data/maps/LilycoveCity/scripts.pory"
	.string "“Unwanted POKéMON moves deleted.”$"
# 718 "data/maps/LilycoveCity/scripts.pory"

# 719 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_DoYouKnowAboutBerryBlender:
# 720 "data/maps/LilycoveCity/scripts.pory"
	.string "Do you know about the machine\n"
# 721 "data/maps/LilycoveCity/scripts.pory"
	.string "BERRY BLENDER?$"
# 722 "data/maps/LilycoveCity/scripts.pory"

# 723 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_FasterSpinBetterPokeblocks:
# 724 "data/maps/LilycoveCity/scripts.pory"
	.string "People have to work together to get it\n"
# 725 "data/maps/LilycoveCity/scripts.pory"
	.string "to spin faster.\p"
# 726 "data/maps/LilycoveCity/scripts.pory"
	.string "The faster you can make it spin, the\n"
# 727 "data/maps/LilycoveCity/scripts.pory"
	.string "better {POKEBLOCK}S you can get, I've heard.$"
# 728 "data/maps/LilycoveCity/scripts.pory"

# 729 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_ExplainBerryBlender:
# 730 "data/maps/LilycoveCity/scripts.pory"
	.string "It's used for making a kind of candy\n"
# 731 "data/maps/LilycoveCity/scripts.pory"
	.string "called a {POKEBLOCK}.\p"
# 732 "data/maps/LilycoveCity/scripts.pory"
	.string "If you give a good {POKEBLOCK} to a POKéMON,\n"
# 733 "data/maps/LilycoveCity/scripts.pory"
	.string "its condition will improve by a lot.$"
# 734 "data/maps/LilycoveCity/scripts.pory"

# 735 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_HeardTowerCalledSkyPillar:
# 736 "data/maps/LilycoveCity/scripts.pory"
	.string "I heard there's a tower somewhere out\n"
# 737 "data/maps/LilycoveCity/scripts.pory"
	.string "on the sea routes.\p"
# 738 "data/maps/LilycoveCity/scripts.pory"
	.string "It's called the SKY PILLAR, I hear.$"
# 739 "data/maps/LilycoveCity/scripts.pory"

# 740 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_SawTallTowerOnRoute131:
# 741 "data/maps/LilycoveCity/scripts.pory"
	.string "I saw this tall tower somewhere\n"
# 742 "data/maps/LilycoveCity/scripts.pory"
	.string "around ROUTE 131.\p"
# 743 "data/maps/LilycoveCity/scripts.pory"
	.string "Could that possibly be…?$"
# 744 "data/maps/LilycoveCity/scripts.pory"

# 745 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_JustArrivedAndSawRarePokemon:
# 746 "data/maps/LilycoveCity/scripts.pory"
	.string "We just arrived here on our\n"
# 747 "data/maps/LilycoveCity/scripts.pory"
	.string "honeymoon vacation.\p"
# 748 "data/maps/LilycoveCity/scripts.pory"
	.string "We happened to see a DRAGON-type\n"
# 749 "data/maps/LilycoveCity/scripts.pory"
	.string "POKéMON flying way up in the sky.\p"
# 750 "data/maps/LilycoveCity/scripts.pory"
	.string "Do cool POKéMON like that live in\n"
# 751 "data/maps/LilycoveCity/scripts.pory"
	.string "the HOENN region?$"
# 752 "data/maps/LilycoveCity/scripts.pory"

# 753 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_HoneymoonVowToSeeRarePokemon:
# 754 "data/maps/LilycoveCity/scripts.pory"
	.string "On our honeymoon, we vowed to see as\n"
# 755 "data/maps/LilycoveCity/scripts.pory"
	.string "many rare POKéMON as we can.\p"
# 756 "data/maps/LilycoveCity/scripts.pory"
	.string "So we were delighted to see a rare\n"
# 757 "data/maps/LilycoveCity/scripts.pory"
	.string "POKéMON as soon as we arrived.\p"
# 758 "data/maps/LilycoveCity/scripts.pory"
	.string "I mean, we are totally happy!$"
