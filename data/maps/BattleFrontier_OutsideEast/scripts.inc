# 1 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 2 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_MapScripts::
# 3 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_OutsideEast_OnResume
# 4 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_OutsideEast_OnTransition
# 5 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.byte 0
# 6 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 7 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_OnResume:
# 8 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, BattleFrontier_OutsideEast_EventScript_TryRemoveSudowoodo
# 9 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	end
# 10 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 11 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_EventScript_TryRemoveSudowoodo::
# 12 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 13 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
# 14 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	removeobject VAR_LAST_TALKED
# 15 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	return
# 16 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 17 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_OnTransition:
# 18 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	setvar VAR_BRAVO_TRAINER_BATTLE_TOWER_ON, 0
# 19 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	setflag FLAG_HIDE_BATTLE_TOWER_REPORTER
# 20 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	call_if_unset FLAG_DEFEATED_SUDOWOODO, BattleFrontier_OutsideEast_EventScript_ShowSudowoodo
# 21 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	end
# 22 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 23 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_EventScript_ShowSudowoodo::
# 24 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	clearflag FLAG_HIDE_BATTLE_FRONTIER_SUDOWOODO
# 25 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	return
# 26 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 27 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_EventScript_BattleTowerSign::
# 28 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	msgbox BattleFrontier_OutsideEast_Text_BattleTowerSign, MSGBOX_SIGN
# 29 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	end
# 30 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 31 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_EventScript_BattlePalaceSign::
# 32 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	msgbox BattleFrontier_OutsideEast_Text_BattlePalaceSign, MSGBOX_SIGN
# 33 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	end
# 34 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 35 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_EventScript_BattleArenaSign::
# 36 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	msgbox BattleFrontier_OutsideEast_Text_BattleArenaSign, MSGBOX_SIGN
# 37 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	end
# 38 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 39 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_EventScript_BattlePyramidSign::
# 40 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	msgbox BattleFrontier_OutsideEast_Text_BattlePyramidSign, MSGBOX_SIGN
# 41 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	end
# 42 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 43 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_EventScript_NinjaBoy::
# 44 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	msgbox BattleFrontier_OutsideEast_Text_BattleTowerFeelsSpecial, MSGBOX_NPC
# 45 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	end
# 46 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 47 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_EventScript_Man1::
# 48 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	msgbox BattleFrontier_OutsideEast_Text_ConquerLeagueAndFrontier, MSGBOX_NPC
# 49 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	end
# 50 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 51 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_EventScript_Hiker::
# 52 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	msgbox BattleFrontier_OutsideEast_Text_PyramidTooHarsh, MSGBOX_NPC
# 53 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	end
# 54 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 55 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_EventScript_HexManiac::
# 56 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	msgbox BattleFrontier_OutsideEast_Text_ThriveInDarkness, MSGBOX_NPC
# 57 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	end
# 58 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 59 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_EventScript_BlackBelt1::
# 60 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	msgbox BattleFrontier_OutsideEast_Text_PutTogetherUltimateTeam, MSGBOX_NPC
# 61 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	end
# 62 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 63 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_EventScript_Cook::
# 64 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	lock
# 65 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	msgbox BattleFrontier_OutsideEast_Text_BelieveInYouBuddy, MSGBOX_DEFAULT
# 66 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	release
# 67 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	end
# 68 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 69 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_EventScript_Zigzagoon::
# 70 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	lock
# 71 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	faceplayer
# 72 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	waitse
# 73 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
# 74 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	msgbox BattleFrontier_OutsideEast_Text_ZigzagoonLooksVacant, MSGBOX_DEFAULT
# 75 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	waitmoncry
# 76 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	release
# 77 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	end
# 78 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 79 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_EventScript_RichBoy::
# 80 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	msgbox BattleFrontier_OutsideEast_Text_PeopleCallMeBusybody, MSGBOX_NPC
# 81 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	end
# 82 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 83 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_EventScript_ExpertF::
# 84 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	msgbox BattleFrontier_OutsideEast_Text_OnceBeatGymLeader, MSGBOX_NPC
# 85 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	end
# 86 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 87 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_EventScript_TriathleteF::
# 88 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	msgbox BattleFrontier_OutsideEast_Text_FastOnBikeAndBattles, MSGBOX_NPC
# 89 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	end
# 90 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 91 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_EventScript_Twin::
# 92 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	msgbox BattleFrontier_OutsideEast_Text_BetterThanDaddyAtPokemon, MSGBOX_NPC
# 93 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	end
# 94 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 95 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_EventScript_Man2::
# 96 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	lock
# 97 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	msgbox BattleFrontier_OutsideEast_Text_GoRackUpSomeWinsForDaddy, MSGBOX_DEFAULT
# 98 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	release
# 99 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	end
# 100 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 101 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_EventScript_TriathleteM::
# 102 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	msgbox BattleFrontier_OutsideEast_Text_DidScottBringYouHere, MSGBOX_NPC
# 103 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	end
# 104 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 105 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_EventScript_Sudowoodo::
# 106 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	lock
# 107 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	faceplayer
# 108 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	waitse
# 109 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	playse SE_SUDOWOODO_SHAKE
# 110 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	applymovement LOCALID_FRONTIER_SUDOWOODO, BattleFrontier_OutsideEast_Movement_SudowoodoShake
# 111 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	waitmovement 0
# 112 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	release
# 113 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	end
# 114 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 115 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_EventScript_WaterSudowoodo::
# 116 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	lock
# 117 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	faceplayer
# 118 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	special DoWateringBerryTreeAnim
# 119 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	waitstate
# 120 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	waitse
# 121 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	playse SE_SUDOWOODO_SHAKE
# 122 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	applymovement LOCALID_FRONTIER_SUDOWOODO, BattleFrontier_OutsideEast_Movement_SudowoodoShake
# 123 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	waitmovement 0
# 124 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	msgbox gText_Sudowoodo_Attacked, MSGBOX_DEFAULT
# 125 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	closemessage
# 126 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	waitse
# 127 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	playmoncry SPECIES_SUDOWOODO, CRY_MODE_ENCOUNTER
# 128 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	delay 40
# 129 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	waitmoncry
# 130 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	setvar VAR_LAST_TALKED, LOCALID_FRONTIER_SUDOWOODO
# 131 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	setwildbattle SPECIES_SUDOWOODO, 40
# 132 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 133 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	dowildbattle
# 134 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 135 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 136 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo
# 137 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo
# 138 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo
# 139 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	setflag FLAG_DEFEATED_SUDOWOODO
# 140 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	release
# 141 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	end
# 142 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 143 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo::
# 144 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	setflag FLAG_DEFEATED_SUDOWOODO
# 145 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	goto Common_EventScript_RemoveStaticPokemon
# 146 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	end
# 147 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 148 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_Movement_SudowoodoShake:
# 149 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	face_right
# 150 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	delay_8
# 151 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	face_down
# 152 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	delay_8
# 153 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	face_left
# 154 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	delay_8
# 155 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	face_down
# 156 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	delay_8
# 157 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	face_right
# 158 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	delay_8
# 159 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	face_down
# 160 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	delay_8
# 161 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	face_left
# 162 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	delay_8
# 163 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	face_down
# 164 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	step_end
# 165 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 166 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_EventScript_Maniac1::
# 167 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	msgbox BattleFrontier_OutsideEast_Text_HeardPrettyGirlAtBattleArena, MSGBOX_NPC
# 168 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	end
# 169 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 170 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_EventScript_Girl::
# 171 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	msgbox BattleFrontier_OutsideEast_Text_SometimesImportantOldManInThere, MSGBOX_NPC
# 172 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	end
# 173 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 174 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_EventScript_PsychicM::
# 175 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	msgbox BattleFrontier_OutsideEast_Text_LegendOfBattlePyramid, MSGBOX_NPC
# 176 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	end
# 177 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 178 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_EventScript_Man3::
# 179 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	msgbox BattleFrontier_OutsideEast_Text_GotWipedOut, MSGBOX_NPC
# 180 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	end
# 181 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 182 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_EventScript_Woman1::
# 183 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	msgbox BattleFrontier_OutsideEast_Text_ToughTrainerInBattleTower, MSGBOX_NPC
# 184 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	end
# 185 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 186 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_EventScript_Woman2::
# 187 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	msgbox BattleFrontier_OutsideEast_Text_EnoughBattlePointsForDoll, MSGBOX_NPC
# 188 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	end
# 189 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 190 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_EventScript_BlackBelt2::
# 191 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	msgbox BattleFrontier_OutsideEast_Text_LikeToHaveNameRecordedHere, MSGBOX_NPC
# 192 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	end
# 193 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 194 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_EventScript_Maniac2::
# 195 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	lock
# 196 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	msgbox BattleFrontier_OutsideEast_Text_CanDoAnythingWithYou, MSGBOX_DEFAULT
# 197 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	release
# 198 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	end
# 199 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 200 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_EventScript_Woman3::
# 201 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	lock
# 202 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	msgbox BattleFrontier_OutsideEast_Text_PowerOfOurLoveWillOvercome, MSGBOX_DEFAULT
# 203 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	release
# 204 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	end
# 205 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 206 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_EventScript_RankingHallSign::
# 207 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	msgbox BattleFrontier_OutsideEast_Text_RankingHallSign, MSGBOX_SIGN
# 208 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	end
# 209 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 210 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_EventScript_ExchangeCornerSign::
# 211 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	msgbox BattleFrontier_OutsideEast_Text_ExchangeCornerSign, MSGBOX_SIGN
# 212 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	end
# 213 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 214 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_EventScript_Gentleman::
# 215 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	msgbox BattleFrontier_OutsideEast_Text_FrontierNotExclusivelyForToughTrainers, MSGBOX_NPC
# 216 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	end
# 217 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 218 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_EventScript_OldWoman::
# 219 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	lock
# 220 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	faceplayer
# 221 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	goto_if_set FLAG_DEFEATED_SUDOWOODO, BattleFrontier_OutsideEast_EventScript_OldWomanSudowoodoGone
# 222 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	msgbox BattleFrontier_OutsideEast_Text_OddTreeHereSeemsToWiggle, MSGBOX_DEFAULT
# 223 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	release
# 224 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	end
# 225 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 226 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_EventScript_OldWomanSudowoodoGone::
# 227 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	msgbox BattleFrontier_OutsideEast_Text_OnceAnOddTreePastHere, MSGBOX_DEFAULT
# 228 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	release
# 229 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	end
# 230 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 231 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_EventScript_Camper::
# 232 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	msgbox BattleFrontier_OutsideEast_Text_StickyMonWithLongTail, MSGBOX_NPC
# 233 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	end
# 234 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 235 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_Text_BattleTowerSign:
# 236 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "This is the BATTLE TOWER!\n"
# 237 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "Keep the win streak as the toughest\l"
# 238 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "TRAINER!$"
# 239 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 240 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_Text_BattlePalaceSign:
# 241 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "This is the BATTLE PALACE!\n"
# 242 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "Keep your eyes on POKéMON battles!$"
# 243 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 244 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_Text_BattleArenaSign:
# 245 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "This is the BATTLE ARENA!\n"
# 246 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "Let the toughest teams gather!$"
# 247 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 248 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_Text_BattlePyramidSign:
# 249 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "This is the BATTLE PYRAMID!\n"
# 250 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "Advance through the Battle Quest!$"
# 251 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 252 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_Text_RankingHallSign:
# 253 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "BATTLE FRONTIER RANKING HALL\n"
# 254 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "Set your sights on new records!$"
# 255 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 256 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_Text_ExchangeCornerSign:
# 257 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "BATTLE POINT EXCHANGE SERVICE CORNER\n"
# 258 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "Exchange your Battle Points!$"
# 259 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 260 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_Text_BattleTowerFeelsSpecial:
# 261 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "Wow!\n"
# 262 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "It's huge!\p"
# 263 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "The BATTLE TOWER feels special.\n"
# 264 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "It's different from the others.$"
# 265 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 266 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_Text_ConquerLeagueAndFrontier:
# 267 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "My grand ambition is to conquer both\n"
# 268 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "the BATTLE FRONTIER and the POKéMON\l"
# 269 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "LEAGUE.\p"
# 270 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "And if my dream comes true…\p"
# 271 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "I… I'm going to ask MIMI next door\n"
# 272 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "if she will be friends with me!$"
# 273 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 274 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_Text_PyramidTooHarsh:
# 275 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "The BATTLE PYRAMID's too harsh!\n"
# 276 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "I just can't make it to the top!\p"
# 277 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "Since I'm out of options, maybe I can\n"
# 278 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "climb the outside…$"
# 279 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 280 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_Text_ThriveInDarkness:
# 281 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "I thrive in darkness…\n"
# 282 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "Yes… What is worthy of me?\l"
# 283 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "None other than the BATTLE PYRAMID…\p"
# 284 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "What say you to wandering in darkness\n"
# 285 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "and in utter and total desperation?$"
# 286 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 287 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_Text_PutTogetherUltimateTeam:
# 288 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "I didn't sleep for a week, but then\n"
# 289 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "I put together the ultimate team!\p"
# 290 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "I can't see myself losing, no joke.\n"
# 291 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "We're storming the BATTLE ARENA!$"
# 292 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 293 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_Text_DidScottBringYouHere:
# 294 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "Did SCOTT bring you here, too?\n"
# 295 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "What is it with that guy?\p"
# 296 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "It sounds like he really does know\n"
# 297 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "how to spot talented TRAINERS, but…\p"
# 298 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "I've never seen him battling in person\n"
# 299 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "ever.$"
# 300 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 301 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_Text_BelieveInYouBuddy:
# 302 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "ZIGG!\n"
# 303 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "I believe in you, little buddy!\p"
# 304 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "I'll make my little ZIGG any favorite\n"
# 305 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "tasty treats you like if you win!$"
# 306 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 307 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_Text_ZigzagoonLooksVacant:
# 308 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "ZIGZAGOON looks vacant…$"
# 309 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 310 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_Text_PeopleCallMeBusybody:
# 311 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "People call me a busybody,\n"
# 312 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "but I can't help it.\p"
# 313 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "Your hat's on crooked!\n"
# 314 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "Oh, no, trash on the ground!\l"
# 315 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "Oops, it's almost dinnertime!\p"
# 316 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "I don't know if I can stand to just\n"
# 317 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "watch at the BATTLE PALACE…$"
# 318 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 319 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_Text_OnceBeatGymLeader:
# 320 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "I may not look that impressive now,\n"
# 321 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "but I once beat a GYM LEADER.\p"
# 322 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "Who knows, maybe I should give it\n"
# 323 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "another shot at glory.$"
# 324 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 325 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_Text_FastOnBikeAndBattles:
# 326 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "I'm fast on my BIKE, and that goes for\n"
# 327 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "the way I battle, too.\p"
# 328 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "I win matches in the blink of\n"
# 329 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "an eye!$"
# 330 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 331 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_Text_BetterThanDaddyAtPokemon:
# 332 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "I'm better than my daddy\n"
# 333 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "at POKéMON.$"
# 334 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 335 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_Text_GoRackUpSomeWinsForDaddy:
# 336 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "Go on, my baby sweetie!\n"
# 337 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "Go rack up some wins for Daddy!\p"
# 338 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "You're just like your mother,\n"
# 339 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "so you'll be dominating!$"
# 340 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 341 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_Text_HeardPrettyGirlAtBattleArena:
# 342 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "It wasn't easy getting here,\n"
# 343 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "but I'd heard about this knockout\l"
# 344 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "pretty girl at the BATTLE ARENA.\p"
# 345 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "Instead of her, do you know what\n"
# 346 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "I found?\p"
# 347 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "A whole teeming mob of sweaty,\n"
# 348 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "stinky, and primitive martial artists!$"
# 349 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 350 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_Text_SometimesImportantOldManInThere:
# 351 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "I sometimes see this really important-\n"
# 352 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "looking old man going in there.\p"
# 353 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "He has these really awesome POKéMON.\n"
# 354 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "He seems really nice, though.$"
# 355 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 356 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_Text_LegendOfBattlePyramid:
# 357 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "Do you know it?\n"
# 358 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "The legend of the BATTLE PYRAMID?\p"
# 359 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "When there comes a confident TRAINER\n"
# 360 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "reaching for the golden pinnacle,\l"
# 361 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "there shall appear a man among men.\p"
# 362 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "Don't know that legend?\n"
# 363 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "Well, of course not!\l"
# 364 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "I just made it up!\p"
# 365 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "What's it supposed to mean?\n"
# 366 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "That, my friend, I can't say!$"
# 367 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 368 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_Text_GotWipedOut:
# 369 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "Man! Oh man!\n"
# 370 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "I've never lost once before!\p"
# 371 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "But I got wiped out with no saving\n"
# 372 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "grace at all!\p"
# 373 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "And then I'm told I don't have any\n"
# 374 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "talent?! Man!$"
# 375 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 376 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_Text_ToughTrainerInBattleTower:
# 377 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "This guy ran into a horribly tough\n"
# 378 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "TRAINER while he was on the BATTLE\l"
# 379 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "TOWER challenge.\p"
# 380 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "Now look at him…\p"
# 381 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "You need to be cautious if you ever\n"
# 382 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "decide to go to the BATTLE TOWER.$"
# 383 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 384 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_Text_EnoughBattlePointsForDoll:
# 385 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "Yes!\n"
# 386 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "I've finally got enough Battle Points!\p"
# 387 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "I guess I'll trade for another giant\n"
# 388 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "plush DOLL!$"
# 389 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 390 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_Text_LikeToHaveNameRecordedHere:
# 391 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "Oh, yeah, okay!\n"
# 392 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "So this is the RANKING HALL!\p"
# 393 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "I'd like to go down in history as\n"
# 394 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "a super champ and have my name\l"
# 395 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "recorded here for posterity.$"
# 396 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 397 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_Text_CanDoAnythingWithYou:
# 398 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "With you by my side, I can do anything.$"
# 399 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 400 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_Text_PowerOfOurLoveWillOvercome:
# 401 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "Ooh, darling, you are so wonderful!\p"
# 402 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "Ooh, I just can't wait anymore!\p"
# 403 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "Let's go to a MULTI BATTLE ROOM\n"
# 404 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "right this instant!\p"
# 405 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "If we get together in the BATTLE SALON,\n"
# 406 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "the power of our love will overcome\l"
# 407 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "everyone we meet.\p"
# 408 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "Why, before us, darling, everything\n"
# 409 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "will topple like dominoes!$"
# 410 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 411 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_Text_FrontierNotExclusivelyForToughTrainers:
# 412 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "The BATTLE FRONTIER isn't exclusively\n"
# 413 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "for tough TRAINERS.\p"
# 414 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "Many people with special abilities\n"
# 415 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "have been invited, it seems.\p"
# 416 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "That man SCOTT…\p"
# 417 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "He may have built this place to serve\n"
# 418 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "a bigger objective…$"
# 419 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 420 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_Text_OddTreeHereSeemsToWiggle:
# 421 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "Excuse me, young one.\n"
# 422 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "Have you good eyesight?\p"
# 423 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "There is an odd tree past here, and to\n"
# 424 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "my tired eyes it seems to wiggle.$"
# 425 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 426 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_Text_OnceAnOddTreePastHere:
# 427 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "Excuse me, young one.\n"
# 428 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "Have you a good memory?\p"
# 429 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "I have this feeling there once was\n"
# 430 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "an odd tree past here.$"
# 431 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 432 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_Text_StickyMonWithLongTail:
# 433 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "I…\n"
# 434 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "I saw it!\p"
# 435 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "There was a sticky sort of a POKéMON\n"
# 436 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "with a long tail up ahead!\p"
# 437 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "It was hiding under a boulder, and\n"
# 438 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "it kept staring at me!$"
