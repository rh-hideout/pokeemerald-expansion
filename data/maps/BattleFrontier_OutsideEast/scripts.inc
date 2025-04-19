# 1 "data//maps/BattleFrontier_OutsideEast/scripts.pory"

# 2 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
.set LOCALID_SUDOWOODO, 14
# 3 "data//maps/BattleFrontier_OutsideEast/scripts.pory"

# 4 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_MapScripts::
# 5 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_OutsideEast_OnResume
# 6 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_OutsideEast_OnTransition
# 7 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.byte 0
# 8 "data//maps/BattleFrontier_OutsideEast/scripts.pory"

# 9 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_OnResume:
# 10 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, BattleFrontier_OutsideEast_EventScript_TryRemoveSudowoodo
# 11 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	end
# 12 "data//maps/BattleFrontier_OutsideEast/scripts.pory"

# 13 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_EventScript_TryRemoveSudowoodo::
# 14 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 15 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
# 16 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	removeobject VAR_LAST_TALKED
# 17 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	return
# 18 "data//maps/BattleFrontier_OutsideEast/scripts.pory"

# 19 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_OnTransition:
# 20 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	setvar VAR_BRAVO_TRAINER_BATTLE_TOWER_ON, 0
# 21 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	setflag FLAG_HIDE_BATTLE_TOWER_REPORTER
# 22 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	call_if_unset FLAG_DEFEATED_SUDOWOODO, BattleFrontier_OutsideEast_EventScript_ShowSudowoodo
# 23 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	end
# 24 "data//maps/BattleFrontier_OutsideEast/scripts.pory"

# 25 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_EventScript_ShowSudowoodo::
# 26 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	clearflag FLAG_HIDE_BATTLE_FRONTIER_SUDOWOODO
# 27 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	return
# 28 "data//maps/BattleFrontier_OutsideEast/scripts.pory"

# 29 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_EventScript_BattleTowerSign::
# 30 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	msgbox BattleFrontier_OutsideEast_Text_BattleTowerSign, MSGBOX_SIGN
# 31 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	end
# 32 "data//maps/BattleFrontier_OutsideEast/scripts.pory"

# 33 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_EventScript_BattlePalaceSign::
# 34 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	msgbox BattleFrontier_OutsideEast_Text_BattlePalaceSign, MSGBOX_SIGN
# 35 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	end
# 36 "data//maps/BattleFrontier_OutsideEast/scripts.pory"

# 37 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_EventScript_BattleArenaSign::
# 38 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	msgbox BattleFrontier_OutsideEast_Text_BattleArenaSign, MSGBOX_SIGN
# 39 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	end
# 40 "data//maps/BattleFrontier_OutsideEast/scripts.pory"

# 41 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_EventScript_BattlePyramidSign::
# 42 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	msgbox BattleFrontier_OutsideEast_Text_BattlePyramidSign, MSGBOX_SIGN
# 43 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	end
# 44 "data//maps/BattleFrontier_OutsideEast/scripts.pory"

# 45 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_EventScript_NinjaBoy::
# 46 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	msgbox BattleFrontier_OutsideEast_Text_BattleTowerFeelsSpecial, MSGBOX_NPC
# 47 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	end
# 48 "data//maps/BattleFrontier_OutsideEast/scripts.pory"

# 49 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_EventScript_Man1::
# 50 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	msgbox BattleFrontier_OutsideEast_Text_ConquerLeagueAndFrontier, MSGBOX_NPC
# 51 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	end
# 52 "data//maps/BattleFrontier_OutsideEast/scripts.pory"

# 53 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_EventScript_Hiker::
# 54 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	msgbox BattleFrontier_OutsideEast_Text_PyramidTooHarsh, MSGBOX_NPC
# 55 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	end
# 56 "data//maps/BattleFrontier_OutsideEast/scripts.pory"

# 57 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_EventScript_HexManiac::
# 58 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	msgbox BattleFrontier_OutsideEast_Text_ThriveInDarkness, MSGBOX_NPC
# 59 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	end
# 60 "data//maps/BattleFrontier_OutsideEast/scripts.pory"

# 61 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_EventScript_BlackBelt1::
# 62 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	msgbox BattleFrontier_OutsideEast_Text_PutTogetherUltimateTeam, MSGBOX_NPC
# 63 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	end
# 64 "data//maps/BattleFrontier_OutsideEast/scripts.pory"

# 65 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_EventScript_Cook::
# 66 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	lock
# 67 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	msgbox BattleFrontier_OutsideEast_Text_BelieveInYouBuddy, MSGBOX_DEFAULT
# 68 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	release
# 69 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	end
# 70 "data//maps/BattleFrontier_OutsideEast/scripts.pory"

# 71 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_EventScript_Zigzagoon::
# 72 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	lock
# 73 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	faceplayer
# 74 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	waitse
# 75 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
# 76 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	msgbox BattleFrontier_OutsideEast_Text_ZigzagoonLooksVacant, MSGBOX_DEFAULT
# 77 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	waitmoncry
# 78 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	release
# 79 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	end
# 80 "data//maps/BattleFrontier_OutsideEast/scripts.pory"

# 81 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_EventScript_RichBoy::
# 82 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	msgbox BattleFrontier_OutsideEast_Text_PeopleCallMeBusybody, MSGBOX_NPC
# 83 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	end
# 84 "data//maps/BattleFrontier_OutsideEast/scripts.pory"

# 85 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_EventScript_ExpertF::
# 86 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	msgbox BattleFrontier_OutsideEast_Text_OnceBeatGymLeader, MSGBOX_NPC
# 87 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	end
# 88 "data//maps/BattleFrontier_OutsideEast/scripts.pory"

# 89 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_EventScript_TriathleteF::
# 90 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	msgbox BattleFrontier_OutsideEast_Text_FastOnBikeAndBattles, MSGBOX_NPC
# 91 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	end
# 92 "data//maps/BattleFrontier_OutsideEast/scripts.pory"

# 93 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_EventScript_Twin::
# 94 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	msgbox BattleFrontier_OutsideEast_Text_BetterThanDaddyAtPokemon, MSGBOX_NPC
# 95 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	end
# 96 "data//maps/BattleFrontier_OutsideEast/scripts.pory"

# 97 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_EventScript_Man2::
# 98 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	lock
# 99 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	msgbox BattleFrontier_OutsideEast_Text_GoRackUpSomeWinsForDaddy, MSGBOX_DEFAULT
# 100 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	release
# 101 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	end
# 102 "data//maps/BattleFrontier_OutsideEast/scripts.pory"

# 103 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_EventScript_TriathleteM::
# 104 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	msgbox BattleFrontier_OutsideEast_Text_DidScottBringYouHere, MSGBOX_NPC
# 105 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	end
# 106 "data//maps/BattleFrontier_OutsideEast/scripts.pory"

# 107 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_EventScript_Sudowoodo::
# 108 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	lock
# 109 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	faceplayer
# 110 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	waitse
# 111 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	playse SE_SUDOWOODO_SHAKE
# 112 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	applymovement LOCALID_SUDOWOODO, BattleFrontier_OutsideEast_Movement_SudowoodoShake
# 113 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	waitmovement 0
# 114 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	release
# 115 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	end
# 116 "data//maps/BattleFrontier_OutsideEast/scripts.pory"

# 117 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_EventScript_WaterSudowoodo::
# 118 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	lock
# 119 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	faceplayer
# 120 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	special DoWateringBerryTreeAnim
# 121 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	waitstate
# 122 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	waitse
# 123 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	playse SE_SUDOWOODO_SHAKE
# 124 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	applymovement LOCALID_SUDOWOODO, BattleFrontier_OutsideEast_Movement_SudowoodoShake
# 125 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	waitmovement 0
# 126 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	msgbox gText_Sudowoodo_Attacked, MSGBOX_DEFAULT
# 127 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	closemessage
# 128 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	waitse
# 129 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	playmoncry SPECIES_SUDOWOODO, CRY_MODE_ENCOUNTER
# 130 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	delay 40
# 131 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	waitmoncry
# 132 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	setvar VAR_LAST_TALKED, LOCALID_SUDOWOODO
# 133 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	setwildbattle SPECIES_SUDOWOODO, 40
# 134 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 135 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	dowildbattle
# 136 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 137 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 138 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo
# 139 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo
# 140 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo
# 141 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	setflag FLAG_DEFEATED_SUDOWOODO
# 142 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	release
# 143 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	end
# 144 "data//maps/BattleFrontier_OutsideEast/scripts.pory"

# 145 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo::
# 146 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	setflag FLAG_DEFEATED_SUDOWOODO
# 147 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	goto Common_EventScript_RemoveStaticPokemon
# 148 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	end
# 149 "data//maps/BattleFrontier_OutsideEast/scripts.pory"

# 150 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_Movement_SudowoodoShake:
# 151 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	face_right
# 152 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	delay_8
# 153 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	face_down
# 154 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	delay_8
# 155 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	face_left
# 156 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	delay_8
# 157 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	face_down
# 158 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	delay_8
# 159 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	face_right
# 160 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	delay_8
# 161 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	face_down
# 162 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	delay_8
# 163 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	face_left
# 164 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	delay_8
# 165 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	face_down
# 166 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	step_end
# 167 "data//maps/BattleFrontier_OutsideEast/scripts.pory"

# 168 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_EventScript_Maniac1::
# 169 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	msgbox BattleFrontier_OutsideEast_Text_HeardPrettyGirlAtBattleArena, MSGBOX_NPC
# 170 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	end
# 171 "data//maps/BattleFrontier_OutsideEast/scripts.pory"

# 172 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_EventScript_Girl::
# 173 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	msgbox BattleFrontier_OutsideEast_Text_SometimesImportantOldManInThere, MSGBOX_NPC
# 174 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	end
# 175 "data//maps/BattleFrontier_OutsideEast/scripts.pory"

# 176 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_EventScript_PsychicM::
# 177 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	msgbox BattleFrontier_OutsideEast_Text_LegendOfBattlePyramid, MSGBOX_NPC
# 178 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	end
# 179 "data//maps/BattleFrontier_OutsideEast/scripts.pory"

# 180 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_EventScript_Man3::
# 181 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	msgbox BattleFrontier_OutsideEast_Text_GotWipedOut, MSGBOX_NPC
# 182 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	end
# 183 "data//maps/BattleFrontier_OutsideEast/scripts.pory"

# 184 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_EventScript_Woman1::
# 185 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	msgbox BattleFrontier_OutsideEast_Text_ToughTrainerInBattleTower, MSGBOX_NPC
# 186 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	end
# 187 "data//maps/BattleFrontier_OutsideEast/scripts.pory"

# 188 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_EventScript_Woman2::
# 189 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	msgbox BattleFrontier_OutsideEast_Text_EnoughBattlePointsForDoll, MSGBOX_NPC
# 190 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	end
# 191 "data//maps/BattleFrontier_OutsideEast/scripts.pory"

# 192 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_EventScript_BlackBelt2::
# 193 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	msgbox BattleFrontier_OutsideEast_Text_LikeToHaveNameRecordedHere, MSGBOX_NPC
# 194 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	end
# 195 "data//maps/BattleFrontier_OutsideEast/scripts.pory"

# 196 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_EventScript_Maniac2::
# 197 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	lock
# 198 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	msgbox BattleFrontier_OutsideEast_Text_CanDoAnythingWithYou, MSGBOX_DEFAULT
# 199 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	release
# 200 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	end
# 201 "data//maps/BattleFrontier_OutsideEast/scripts.pory"

# 202 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_EventScript_Woman3::
# 203 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	lock
# 204 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	msgbox BattleFrontier_OutsideEast_Text_PowerOfOurLoveWillOvercome, MSGBOX_DEFAULT
# 205 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	release
# 206 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	end
# 207 "data//maps/BattleFrontier_OutsideEast/scripts.pory"

# 208 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_EventScript_RankingHallSign::
# 209 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	msgbox BattleFrontier_OutsideEast_Text_RankingHallSign, MSGBOX_SIGN
# 210 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	end
# 211 "data//maps/BattleFrontier_OutsideEast/scripts.pory"

# 212 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_EventScript_ExchangeCornerSign::
# 213 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	msgbox BattleFrontier_OutsideEast_Text_ExchangeCornerSign, MSGBOX_SIGN
# 214 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	end
# 215 "data//maps/BattleFrontier_OutsideEast/scripts.pory"

# 216 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_EventScript_Gentleman::
# 217 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	msgbox BattleFrontier_OutsideEast_Text_FrontierNotExclusivelyForToughTrainers, MSGBOX_NPC
# 218 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	end
# 219 "data//maps/BattleFrontier_OutsideEast/scripts.pory"

# 220 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_EventScript_OldWoman::
# 221 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	lock
# 222 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	faceplayer
# 223 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	goto_if_set FLAG_DEFEATED_SUDOWOODO, BattleFrontier_OutsideEast_EventScript_OldWomanSudowoodoGone
# 224 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	msgbox BattleFrontier_OutsideEast_Text_OddTreeHereSeemsToWiggle, MSGBOX_DEFAULT
# 225 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	release
# 226 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	end
# 227 "data//maps/BattleFrontier_OutsideEast/scripts.pory"

# 228 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_EventScript_OldWomanSudowoodoGone::
# 229 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	msgbox BattleFrontier_OutsideEast_Text_OnceAnOddTreePastHere, MSGBOX_DEFAULT
# 230 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	release
# 231 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	end
# 232 "data//maps/BattleFrontier_OutsideEast/scripts.pory"

# 233 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_EventScript_Camper::
# 234 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	msgbox BattleFrontier_OutsideEast_Text_StickyMonWithLongTail, MSGBOX_NPC
# 235 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	end
# 236 "data//maps/BattleFrontier_OutsideEast/scripts.pory"

# 237 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_Text_BattleTowerSign:
# 238 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "This is the BATTLE TOWER!\n"
# 239 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "Keep the win streak as the toughest\l"
# 240 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "TRAINER!$"
# 241 "data//maps/BattleFrontier_OutsideEast/scripts.pory"

# 242 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_Text_BattlePalaceSign:
# 243 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "This is the BATTLE PALACE!\n"
# 244 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "Keep your eyes on POKéMON battles!$"
# 245 "data//maps/BattleFrontier_OutsideEast/scripts.pory"

# 246 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_Text_BattleArenaSign:
# 247 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "This is the BATTLE ARENA!\n"
# 248 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "Let the toughest teams gather!$"
# 249 "data//maps/BattleFrontier_OutsideEast/scripts.pory"

# 250 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_Text_BattlePyramidSign:
# 251 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "This is the BATTLE PYRAMID!\n"
# 252 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "Advance through the Battle Quest!$"
# 253 "data//maps/BattleFrontier_OutsideEast/scripts.pory"

# 254 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_Text_RankingHallSign:
# 255 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "BATTLE FRONTIER RANKING HALL\n"
# 256 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "Set your sights on new records!$"
# 257 "data//maps/BattleFrontier_OutsideEast/scripts.pory"

# 258 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_Text_ExchangeCornerSign:
# 259 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "BATTLE POINT EXCHANGE SERVICE CORNER\n"
# 260 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "Exchange your Battle Points!$"
# 261 "data//maps/BattleFrontier_OutsideEast/scripts.pory"

# 262 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_Text_BattleTowerFeelsSpecial:
# 263 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "Wow!\n"
# 264 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "It's huge!\p"
# 265 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "The BATTLE TOWER feels special.\n"
# 266 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "It's different from the others.$"
# 267 "data//maps/BattleFrontier_OutsideEast/scripts.pory"

# 268 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_Text_ConquerLeagueAndFrontier:
# 269 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "My grand ambition is to conquer both\n"
# 270 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "the BATTLE FRONTIER and the POKéMON\l"
# 271 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "LEAGUE.\p"
# 272 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "And if my dream comes true…\p"
# 273 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "I… I'm going to ask MIMI next door\n"
# 274 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "if she will be friends with me!$"
# 275 "data//maps/BattleFrontier_OutsideEast/scripts.pory"

# 276 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_Text_PyramidTooHarsh:
# 277 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "The BATTLE PYRAMID's too harsh!\n"
# 278 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "I just can't make it to the top!\p"
# 279 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "Since I'm out of options, maybe I can\n"
# 280 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "climb the outside…$"
# 281 "data//maps/BattleFrontier_OutsideEast/scripts.pory"

# 282 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_Text_ThriveInDarkness:
# 283 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "I thrive in darkness…\n"
# 284 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "Yes… What is worthy of me?\l"
# 285 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "None other than the BATTLE PYRAMID…\p"
# 286 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "What say you to wandering in darkness\n"
# 287 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "and in utter and total desperation?$"
# 288 "data//maps/BattleFrontier_OutsideEast/scripts.pory"

# 289 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_Text_PutTogetherUltimateTeam:
# 290 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "I didn't sleep for a week, but then\n"
# 291 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "I put together the ultimate team!\p"
# 292 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "I can't see myself losing, no joke.\n"
# 293 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "We're storming the BATTLE ARENA!$"
# 294 "data//maps/BattleFrontier_OutsideEast/scripts.pory"

# 295 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_Text_DidScottBringYouHere:
# 296 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "Did SCOTT bring you here, too?\n"
# 297 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "What is it with that guy?\p"
# 298 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "It sounds like he really does know\n"
# 299 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "how to spot talented TRAINERS, but…\p"
# 300 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "I've never seen him battling in person\n"
# 301 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "ever.$"
# 302 "data//maps/BattleFrontier_OutsideEast/scripts.pory"

# 303 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_Text_BelieveInYouBuddy:
# 304 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "ZIGG!\n"
# 305 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "I believe in you, little buddy!\p"
# 306 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "I'll make my little ZIGG any favorite\n"
# 307 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "tasty treats you like if you win!$"
# 308 "data//maps/BattleFrontier_OutsideEast/scripts.pory"

# 309 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_Text_ZigzagoonLooksVacant:
# 310 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "ZIGZAGOON looks vacant…$"
# 311 "data//maps/BattleFrontier_OutsideEast/scripts.pory"

# 312 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_Text_PeopleCallMeBusybody:
# 313 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "People call me a busybody,\n"
# 314 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "but I can't help it.\p"
# 315 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "Your hat's on crooked!\n"
# 316 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "Oh, no, trash on the ground!\l"
# 317 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "Oops, it's almost dinnertime!\p"
# 318 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "I don't know if I can stand to just\n"
# 319 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "watch at the BATTLE PALACE…$"
# 320 "data//maps/BattleFrontier_OutsideEast/scripts.pory"

# 321 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_Text_OnceBeatGymLeader:
# 322 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "I may not look that impressive now,\n"
# 323 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "but I once beat a GYM LEADER.\p"
# 324 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "Who knows, maybe I should give it\n"
# 325 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "another shot at glory.$"
# 326 "data//maps/BattleFrontier_OutsideEast/scripts.pory"

# 327 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_Text_FastOnBikeAndBattles:
# 328 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "I'm fast on my BIKE, and that goes for\n"
# 329 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "the way I battle, too.\p"
# 330 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "I win matches in the blink of\n"
# 331 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "an eye!$"
# 332 "data//maps/BattleFrontier_OutsideEast/scripts.pory"

# 333 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_Text_BetterThanDaddyAtPokemon:
# 334 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "I'm better than my daddy\n"
# 335 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "at POKéMON.$"
# 336 "data//maps/BattleFrontier_OutsideEast/scripts.pory"

# 337 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_Text_GoRackUpSomeWinsForDaddy:
# 338 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "Go on, my baby sweetie!\n"
# 339 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "Go rack up some wins for Daddy!\p"
# 340 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "You're just like your mother,\n"
# 341 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "so you'll be dominating!$"
# 342 "data//maps/BattleFrontier_OutsideEast/scripts.pory"

# 343 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_Text_HeardPrettyGirlAtBattleArena:
# 344 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "It wasn't easy getting here,\n"
# 345 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "but I'd heard about this knockout\l"
# 346 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "pretty girl at the BATTLE ARENA.\p"
# 347 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "Instead of her, do you know what\n"
# 348 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "I found?\p"
# 349 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "A whole teeming mob of sweaty,\n"
# 350 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "stinky, and primitive martial artists!$"
# 351 "data//maps/BattleFrontier_OutsideEast/scripts.pory"

# 352 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_Text_SometimesImportantOldManInThere:
# 353 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "I sometimes see this really important-\n"
# 354 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "looking old man going in there.\p"
# 355 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "He has these really awesome POKéMON.\n"
# 356 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "He seems really nice, though.$"
# 357 "data//maps/BattleFrontier_OutsideEast/scripts.pory"

# 358 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_Text_LegendOfBattlePyramid:
# 359 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "Do you know it?\n"
# 360 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "The legend of the BATTLE PYRAMID?\p"
# 361 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "When there comes a confident TRAINER\n"
# 362 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "reaching for the golden pinnacle,\l"
# 363 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "there shall appear a man among men.\p"
# 364 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "Don't know that legend?\n"
# 365 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "Well, of course not!\l"
# 366 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "I just made it up!\p"
# 367 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "What's it supposed to mean?\n"
# 368 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "That, my friend, I can't say!$"
# 369 "data//maps/BattleFrontier_OutsideEast/scripts.pory"

# 370 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_Text_GotWipedOut:
# 371 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "Man! Oh man!\n"
# 372 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "I've never lost once before!\p"
# 373 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "But I got wiped out with no saving\n"
# 374 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "grace at all!\p"
# 375 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "And then I'm told I don't have any\n"
# 376 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "talent?! Man!$"
# 377 "data//maps/BattleFrontier_OutsideEast/scripts.pory"

# 378 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_Text_ToughTrainerInBattleTower:
# 379 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "This guy ran into a horribly tough\n"
# 380 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "TRAINER while he was on the BATTLE\l"
# 381 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "TOWER challenge.\p"
# 382 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "Now look at him…\p"
# 383 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "You need to be cautious if you ever\n"
# 384 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "decide to go to the BATTLE TOWER.$"
# 385 "data//maps/BattleFrontier_OutsideEast/scripts.pory"

# 386 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_Text_EnoughBattlePointsForDoll:
# 387 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "Yes!\n"
# 388 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "I've finally got enough Battle Points!\p"
# 389 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "I guess I'll trade for another giant\n"
# 390 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "plush DOLL!$"
# 391 "data//maps/BattleFrontier_OutsideEast/scripts.pory"

# 392 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_Text_LikeToHaveNameRecordedHere:
# 393 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "Oh, yeah, okay!\n"
# 394 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "So this is the RANKING HALL!\p"
# 395 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "I'd like to go down in history as\n"
# 396 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "a super champ and have my name\l"
# 397 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "recorded here for posterity.$"
# 398 "data//maps/BattleFrontier_OutsideEast/scripts.pory"

# 399 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_Text_CanDoAnythingWithYou:
# 400 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "With you by my side, I can do anything.$"
# 401 "data//maps/BattleFrontier_OutsideEast/scripts.pory"

# 402 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_Text_PowerOfOurLoveWillOvercome:
# 403 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "Ooh, darling, you are so wonderful!\p"
# 404 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "Ooh, I just can't wait anymore!\p"
# 405 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "Let's go to a MULTI BATTLE ROOM\n"
# 406 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "right this instant!\p"
# 407 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "If we get together in the BATTLE SALON,\n"
# 408 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "the power of our love will overcome\l"
# 409 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "everyone we meet.\p"
# 410 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "Why, before us, darling, everything\n"
# 411 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "will topple like dominoes!$"
# 412 "data//maps/BattleFrontier_OutsideEast/scripts.pory"

# 413 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_Text_FrontierNotExclusivelyForToughTrainers:
# 414 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "The BATTLE FRONTIER isn't exclusively\n"
# 415 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "for tough TRAINERS.\p"
# 416 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "Many people with special abilities\n"
# 417 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "have been invited, it seems.\p"
# 418 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "That man SCOTT…\p"
# 419 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "He may have built this place to serve\n"
# 420 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "a bigger objective…$"
# 421 "data//maps/BattleFrontier_OutsideEast/scripts.pory"

# 422 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_Text_OddTreeHereSeemsToWiggle:
# 423 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "Excuse me, young one.\n"
# 424 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "Have you good eyesight?\p"
# 425 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "There is an odd tree past here, and to\n"
# 426 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "my tired eyes it seems to wiggle.$"
# 427 "data//maps/BattleFrontier_OutsideEast/scripts.pory"

# 428 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_Text_OnceAnOddTreePastHere:
# 429 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "Excuse me, young one.\n"
# 430 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "Have you a good memory?\p"
# 431 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "I have this feeling there once was\n"
# 432 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "an odd tree past here.$"
# 433 "data//maps/BattleFrontier_OutsideEast/scripts.pory"

# 434 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_Text_StickyMonWithLongTail:
# 435 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "I…\n"
# 436 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "I saw it!\p"
# 437 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "There was a sticky sort of a POKéMON\n"
# 438 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "with a long tail up ahead!\p"
# 439 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "It was hiding under a boulder, and\n"
# 440 "data//maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "it kept staring at me!$"
