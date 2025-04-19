# 1 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"

# 2 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
.set LOCALID_SCOTT, 1
# 3 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"

# 4 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
BattleFrontier_ScottsHouse_MapScripts::
# 5 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	.byte 0
# 6 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"

# 7 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
BattleFrontier_ScottsHouse_EventScript_Scott::
# 8 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	lock
# 9 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	faceplayer
# 10 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	goto_if_set FLAG_TEMP_4, BattleFrontier_ScottsHouse_EventScript_GivenBerry
# 11 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	goto_if_set FLAG_TEMP_3, BattleFrontier_ScottsHouse_EventScript_GivenShield
# 12 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	goto_if_set FLAG_TEMP_2, BattleFrontier_ScottsHouse_EventScript_GivenBattlePoints
# 13 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	goto BattleFrontier_ScottsHouse_EventScript_CheckGiveItems
# 14 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	end
# 15 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"

# 16 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
BattleFrontier_ScottsHouse_EventScript_CheckGiveItems::
# 17 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	goto_if_unset FLAG_SCOTT_GIVES_BATTLE_POINTS, BattleFrontier_ScottsHouse_EventScript_WelcomeToFrontier
# 18 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	goto_if_unset FLAG_COLLECTED_ALL_SILVER_SYMBOLS, BattleFrontier_ScottsHouse_EventScript_CheckSilverSymbols
# 19 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	goto_if_unset FLAG_COLLECTED_ALL_GOLD_SYMBOLS, BattleFrontier_ScottsHouse_EventScript_CheckGoldSymbols
# 20 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	goto BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
# 21 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	end
# 22 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"

# 23 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
BattleFrontier_ScottsHouse_EventScript_CheckGiveShield::
# 24 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	goto_if_unset FLAG_RECEIVED_SILVER_SHIELD, BattleFrontier_ScottsHouse_EventScript_CheckGiveSilverShield
# 25 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	goto_if_unset FLAG_RECEIVED_GOLD_SHIELD, BattleFrontier_ScottsHouse_EventScript_CheckGiveGoldShield
# 26 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	goto BattleFrontier_ScottsHouse_EventScript_RandomComment
# 27 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	end
# 28 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"

# 29 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
BattleFrontier_ScottsHouse_EventScript_CheckSilverSymbols::
# 30 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	goto_if_unset FLAG_SYS_TOWER_SILVER, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
# 31 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	goto_if_unset FLAG_SYS_DOME_SILVER, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
# 32 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	goto_if_unset FLAG_SYS_PALACE_SILVER, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
# 33 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	goto_if_unset FLAG_SYS_ARENA_SILVER, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
# 34 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	goto_if_unset FLAG_SYS_FACTORY_SILVER, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
# 35 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	goto_if_unset FLAG_SYS_PIKE_SILVER, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
# 36 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	goto_if_unset FLAG_SYS_PYRAMID_SILVER, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
# 37 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	msgbox BattleFrontier_ScottsHouse_Text_YouveCollectedAllSilverSymbols, MSGBOX_DEFAULT
# 38 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	giveitem ITEM_LANSAT_BERRY
# 39 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_ScottsHouse_EventScript_BerryPocketFull
# 40 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	setflag FLAG_COLLECTED_ALL_SILVER_SYMBOLS
# 41 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	setflag FLAG_TEMP_4
# 42 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	release
# 43 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	end
# 44 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"

# 45 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
BattleFrontier_ScottsHouse_EventScript_CheckGoldSymbols::
# 46 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	goto_if_unset FLAG_SYS_TOWER_GOLD, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
# 47 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	goto_if_unset FLAG_SYS_DOME_GOLD, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
# 48 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	goto_if_unset FLAG_SYS_PALACE_GOLD, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
# 49 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	goto_if_unset FLAG_SYS_ARENA_GOLD, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
# 50 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	goto_if_unset FLAG_SYS_FACTORY_GOLD, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
# 51 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	goto_if_unset FLAG_SYS_PIKE_GOLD, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
# 52 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	goto_if_unset FLAG_SYS_PYRAMID_GOLD, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
# 53 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	msgbox BattleFrontier_ScottsHouse_Text_YouveCollectedAllGoldSymbols, MSGBOX_DEFAULT
# 54 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	giveitem ITEM_STARF_BERRY
# 55 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_ScottsHouse_EventScript_BerryPocketFull
# 56 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	setflag FLAG_COLLECTED_ALL_GOLD_SYMBOLS
# 57 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	setflag FLAG_TEMP_4
# 58 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	release
# 59 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	end
# 60 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"

# 61 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
BattleFrontier_ScottsHouse_EventScript_BerryPocketFull::
# 62 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	msgbox BattleFrontier_ScottsHouse_Text_BerryPocketStuffed, MSGBOX_DEFAULT
# 63 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	release
# 64 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	end
# 65 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"

# 66 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
BattleFrontier_ScottsHouse_EventScript_GivenBerry::
# 67 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	msgbox BattleFrontier_ScottsHouse_Text_SoGladIBroughtYouHere, MSGBOX_DEFAULT
# 68 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	release
# 69 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	end
# 70 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"

# 71 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
BattleFrontier_ScottsHouse_EventScript_RandomComment::
# 72 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	random 3
# 73 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	goto_if_eq VAR_RESULT, 1, BattleFrontier_ScottsHouse_EventScript_FrontierBrainComment
# 74 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	goto_if_eq VAR_RESULT, 2, BattleFrontier_ScottsHouse_EventScript_ArtisanCaveComment
# 75 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	msgbox BattleFrontier_ScottsHouse_Text_WhyIGoSeekingTrainers, MSGBOX_DEFAULT
# 76 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	release
# 77 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	end
# 78 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"

# 79 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
BattleFrontier_ScottsHouse_EventScript_FrontierBrainComment::
# 80 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	msgbox BattleFrontier_ScottsHouse_Text_HaveYouMetFrontierBrain, MSGBOX_DEFAULT
# 81 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	release
# 82 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	end
# 83 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"

# 84 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
BattleFrontier_ScottsHouse_EventScript_ArtisanCaveComment::
# 85 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	msgbox BattleFrontier_ScottsHouse_Text_MayFindWildMonsInFrontier, MSGBOX_DEFAULT
# 86 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	release
# 87 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	end
# 88 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"

# 89 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
BattleFrontier_ScottsHouse_EventScript_CheckGiveSilverShield::
# 90 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
# 91 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_50
# 92 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	tower_get TOWER_DATA_WIN_STREAK
# 93 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	goto_if_ge VAR_RESULT, 50, BattleFrontier_ScottsHouse_EventScript_GiveSilverShield
# 94 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_OPEN
# 95 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	tower_get TOWER_DATA_WIN_STREAK
# 96 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	goto_if_ge VAR_RESULT, 50, BattleFrontier_ScottsHouse_EventScript_GiveSilverShield
# 97 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	goto BattleFrontier_ScottsHouse_EventScript_RandomComment
# 98 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	end
# 99 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"

# 100 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
BattleFrontier_ScottsHouse_EventScript_GiveSilverShield::
# 101 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	msgbox BattleFrontier_ScottsHouse_Text_Beat50TrainersInARow, MSGBOX_DEFAULT
# 102 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	givedecoration DECOR_SILVER_SHIELD
# 103 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_ScottsHouse_EventScript_NoRoomForShield
# 104 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	setflag FLAG_RECEIVED_SILVER_SHIELD
# 105 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	setflag FLAG_TEMP_3
# 106 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	goto BattleFrontier_ScottsHouse_EventScript_GivenShield
# 107 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	end
# 108 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"

# 109 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
BattleFrontier_ScottsHouse_EventScript_NoRoomForShield::
# 110 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	msgbox BattleFrontier_ScottsHouse_Text_ComeBackForThisLater, MSGBOX_DEFAULT
# 111 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	release
# 112 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	end
# 113 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"

# 114 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
BattleFrontier_ScottsHouse_EventScript_GivenShield::
# 115 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	msgbox BattleFrontier_ScottsHouse_Text_ExpectingToHearEvenGreaterThings, MSGBOX_DEFAULT
# 116 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	release
# 117 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	end
# 118 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"

# 119 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
BattleFrontier_ScottsHouse_EventScript_CheckGiveGoldShield::
# 120 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
# 121 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_50
# 122 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	tower_get TOWER_DATA_WIN_STREAK
# 123 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	goto_if_ge VAR_RESULT, 100, BattleFrontier_ScottsHouse_EventScript_GiveGoldShield
# 124 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_OPEN
# 125 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	tower_get TOWER_DATA_WIN_STREAK
# 126 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	goto_if_ge VAR_RESULT, 100, BattleFrontier_ScottsHouse_EventScript_GiveGoldShield
# 127 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	goto BattleFrontier_ScottsHouse_EventScript_RandomComment
# 128 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	end
# 129 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"

# 130 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
BattleFrontier_ScottsHouse_EventScript_GiveGoldShield::
# 131 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	msgbox BattleFrontier_ScottsHouse_Text_Beat100TrainersInARow, MSGBOX_DEFAULT
# 132 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	givedecoration DECOR_GOLD_SHIELD
# 133 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_ScottsHouse_EventScript_NoRoomForShield
# 134 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	setflag FLAG_RECEIVED_GOLD_SHIELD
# 135 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	setflag FLAG_TEMP_3
# 136 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	goto BattleFrontier_ScottsHouse_EventScript_GivenShield
# 137 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	end
# 138 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"

# 139 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
BattleFrontier_ScottsHouse_EventScript_GivenBattlePoints::
# 140 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	msgbox BattleFrontier_ScottsHouse_Text_ExpectingGreatThings, MSGBOX_DEFAULT
# 141 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	release
# 142 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	end
# 143 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"

# 144 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
BattleFrontier_ScottsHouse_EventScript_WelcomeToFrontier::
# 145 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	msgbox BattleFrontier_ScottsHouse_Text_WelcomeToBattleFrontier, MSGBOX_DEFAULT
# 146 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	closemessage
# 147 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	delay 30
# 148 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, BattleFrontier_ScottsHouse_EventScript_ScottFaceAwayNorth
# 149 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	call_if_eq VAR_FACING, DIR_SOUTH, BattleFrontier_ScottsHouse_EventScript_ScottFaceAwaySouth
# 150 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, BattleFrontier_ScottsHouse_EventScript_ScottFaceAwayEast
# 151 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	call_if_eq VAR_FACING, DIR_WEST, BattleFrontier_ScottsHouse_EventScript_ScottFaceAwayWest
# 152 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	msgbox BattleFrontier_ScottsHouse_Text_HowMuchEffortItTookToMakeReal, MSGBOX_DEFAULT
# 153 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	applymovement LOCALID_SCOTT, Common_Movement_FacePlayer
# 154 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	waitmovement 0
# 155 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	msgbox BattleFrontier_ScottsHouse_Text_HaveThisAsMementoOfOurPathsCrossing, MSGBOX_DEFAULT
# 156 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	goto_if_eq VAR_SCOTT_STATE, 13, BattleFrontier_ScottsHouse_EventScript_Give4BattlePoints
# 157 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	goto_if_ge VAR_SCOTT_STATE, 9, BattleFrontier_ScottsHouse_EventScript_Give3BattlePoints
# 158 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	goto_if_ge VAR_SCOTT_STATE, 6, BattleFrontier_ScottsHouse_EventScript_Give2BattlePoints
# 159 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	goto BattleFrontier_ScottsHouse_EventScript_Give1BattlePoint
# 160 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	end
# 161 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"

# 162 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
BattleFrontier_ScottsHouse_EventScript_Give4BattlePoints::
# 163 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	buffernumberstring STR_VAR_1, 4
# 164 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	setvar VAR_0x8004, 4
# 165 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	goto BattleFrontier_ScottsHouse_EventScript_GiveBattlePoints
# 166 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	end
# 167 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"

# 168 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
BattleFrontier_ScottsHouse_EventScript_Give3BattlePoints::
# 169 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	buffernumberstring STR_VAR_1, 3
# 170 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	setvar VAR_0x8004, 3
# 171 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	goto BattleFrontier_ScottsHouse_EventScript_GiveBattlePoints
# 172 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	end
# 173 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"

# 174 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
BattleFrontier_ScottsHouse_EventScript_Give2BattlePoints::
# 175 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	buffernumberstring STR_VAR_1, 2
# 176 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	setvar VAR_0x8004, 2
# 177 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	goto BattleFrontier_ScottsHouse_EventScript_GiveBattlePoints
# 178 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	end
# 179 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"

# 180 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
BattleFrontier_ScottsHouse_EventScript_Give1BattlePoint::
# 181 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	buffernumberstring STR_VAR_1, 1
# 182 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	setvar VAR_0x8004, 1
# 183 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	goto BattleFrontier_ScottsHouse_EventScript_GiveBattlePoints
# 184 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	end
# 185 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"

# 186 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
BattleFrontier_ScottsHouse_EventScript_GiveBattlePoints::
# 187 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	special GiveFrontierBattlePoints
# 188 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	msgbox BattleFrontier_ScottsHouse_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
# 189 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	msgbox BattleFrontier_ScottsHouse_Text_ExplainBattlePoints, MSGBOX_DEFAULT
# 190 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	setflag FLAG_SCOTT_GIVES_BATTLE_POINTS
# 191 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	setflag FLAG_TEMP_2
# 192 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	release
# 193 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	end
# 194 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"

# 195 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
BattleFrontier_ScottsHouse_EventScript_ScottFaceAwayNorth::
# 196 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	applymovement LOCALID_SCOTT, Common_Movement_WalkInPlaceFasterUp
# 197 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	waitmovement 0
# 198 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	return
# 199 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"

# 200 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
BattleFrontier_ScottsHouse_EventScript_ScottFaceAwaySouth::
# 201 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	applymovement LOCALID_SCOTT, Common_Movement_WalkInPlaceFasterDown
# 202 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	waitmovement 0
# 203 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	return
# 204 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"

# 205 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
BattleFrontier_ScottsHouse_EventScript_ScottFaceAwayEast::
# 206 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	applymovement LOCALID_SCOTT, Common_Movement_WalkInPlaceFasterRight
# 207 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	waitmovement 0
# 208 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	return
# 209 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"

# 210 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
BattleFrontier_ScottsHouse_EventScript_ScottFaceAwayWest::
# 211 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	applymovement LOCALID_SCOTT, Common_Movement_WalkInPlaceFasterLeft
# 212 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	waitmovement 0
# 213 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	return
# 214 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"

# 215 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
BattleFrontier_ScottsHouse_Text_WelcomeToBattleFrontier:
# 216 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "SCOTT: Well, hello and welcome!\n"
# 217 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "Heheh… Sorry about the cramped space.\p"
# 218 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "Anyway, {PLAYER}{KUN}, let me formally\n"
# 219 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "welcome you to the BATTLE FRONTIER.\p"
# 220 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "This is my dream come true.\n"
# 221 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "It took me years and years, but I've\l"
# 222 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "finally given shape to my dream.$"
# 223 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"

# 224 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
BattleFrontier_ScottsHouse_Text_HowMuchEffortItTookToMakeReal:
# 225 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "On reflection, it was a terribly long\n"
# 226 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "journey…\p"
# 227 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "I left home alone on a quest to find\n"
# 228 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "strong TRAINERS.\p"
# 229 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "No one can imagine how much effort\n"
# 230 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "or time it took to make this real.$"
# 231 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"

# 232 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
BattleFrontier_ScottsHouse_Text_HaveThisAsMementoOfOurPathsCrossing:
# 233 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "But that's all in the past.\n"
# 234 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "No point dwelling on that!\p"
# 235 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "All I want for you is to enjoy battling\n"
# 236 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "to your heart's content here.\p"
# 237 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "{PLAYER}{KUN}, I want you to have this\n"
# 238 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "as a memento for all the time our\l"
# 239 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "paths crossed on our journeys.$"
# 240 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"

# 241 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
BattleFrontier_ScottsHouse_Text_ObtainedXBattlePoints:
# 242 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "{PLAYER} obtained\n"
# 243 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "{STR_VAR_1} Battle Point(s).$"
# 244 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"

# 245 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
BattleFrontier_ScottsHouse_Text_ExplainBattlePoints:
# 246 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "SCOTT: You can check your Battle\n"
# 247 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "Points on your FRONTIER PASS.\p"
# 248 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "The more success you have here at\n"
# 249 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "the BATTLE FRONTIER, the more Battle\l"
# 250 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "Points you will collect.\p"
# 251 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "Use your Battle Points the way you\n"
# 252 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "see fit, like trading them for items.$"
# 253 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"

# 254 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
BattleFrontier_ScottsHouse_Text_ExpectingGreatThings:
# 255 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "I'm expecting great things from you!$"
# 256 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"

# 257 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
BattleFrontier_ScottsHouse_Text_WhyIGoSeekingTrainers:
# 258 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "SCOTT: Every TRAINER is an individual.\n"
# 259 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "They all lead lives of their own.\p"
# 260 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "But when they're in a battle,\n"
# 261 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "it doesn't matter who they are.\p"
# 262 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "They're all the same!\p"
# 263 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "I love the purity of battle,\n"
# 264 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "where everyone is equal.\p"
# 265 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "That's why I go everywhere seeking\n"
# 266 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "TRAINERS who are serious about\l"
# 267 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "battling, and invite them here.$"
# 268 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"

# 269 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
BattleFrontier_ScottsHouse_Text_HaveYouMetFrontierBrain:
# 270 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "SCOTT: Have you met any of\n"
# 271 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "the FRONTIER BRAINS?\p"
# 272 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "Better yet, have you obtained any\n"
# 273 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "symbols from them?\p"
# 274 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "I handpicked the FRONTIER BRAINS\n"
# 275 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "as the toughest TRAINERS anywhere.\p"
# 276 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "But I'm sure that seeing how tough\n"
# 277 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "you are will startle even them!$"
# 278 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"

# 279 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
BattleFrontier_ScottsHouse_Text_MayFindWildMonsInFrontier:
# 280 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "SCOTT: You don't just train for battle,\n"
# 281 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "right?\p"
# 282 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "I think I remember you working on\n"
# 283 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "a POKéDEX as well.\p"
# 284 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "Well, guess what?\p"
# 285 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "You may run into wild POKéMON in\n"
# 286 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "the BATTLE FRONTIER somewhere…\l"
# 287 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "Fufufu!$"
# 288 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"

# 289 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
BattleFrontier_ScottsHouse_Text_YouveCollectedAllSilverSymbols:
# 290 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "SCOTT: Are you enjoying things in\n"
# 291 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "the BATTLE FRONTIER?\p"
# 292 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "…Wait a second…\n"
# 293 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "Oh!\p"
# 294 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "Your FRONTIER PASS!\n"
# 295 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "You've collected the full set\l"
# 296 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "of silver symbols!\p"
# 297 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "That's more than impressive!\n"
# 298 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "You are tough, just as I suspected!\p"
# 299 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "Normally, I wouldn't do something\n"
# 300 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "like this, but this is a special time!\p"
# 301 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "I want you to have this.\n"
# 302 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "I'm sure you can put it to proper use.$"
# 303 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"

# 304 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
BattleFrontier_ScottsHouse_Text_YouveCollectedAllGoldSymbols:
# 305 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "SCOTT: I hope you're enjoying\n"
# 306 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "everything in the BATTLE FRONTIER.\p"
# 307 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "…Wait a second…\n"
# 308 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "Oh, my disbelieving eyes!\p"
# 309 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "Your FRONTIER PASS!\n"
# 310 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "You've gathered up the full set\l"
# 311 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "of gold symbols!\p"
# 312 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "That's more than stupendous!\n"
# 313 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "You're incredible, just as I suspected!\p"
# 314 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "… … … … … …\p"
# 315 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "{PLAYER}, you've got to accept this!\p"
# 316 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "I think you will be able to\n"
# 317 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "appreciate the value of my gift!$"
# 318 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"

# 319 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
BattleFrontier_ScottsHouse_Text_SoGladIBroughtYouHere:
# 320 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "I must say I have the gift of knowing\n"
# 321 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "a good TRAINER when I see one.\p"
# 322 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "I'm so glad I had the foresight to\n"
# 323 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "bring you here!$"
# 324 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"

# 325 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
BattleFrontier_ScottsHouse_Text_BerryPocketStuffed:
# 326 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "Your BERRY POCKET seems to\n"
# 327 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "be stuffed.$"
# 328 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"

# 329 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
BattleFrontier_ScottsHouse_Text_Beat50TrainersInARow:
# 330 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "SCOTT: Oh, I heard about you!\n"
# 331 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "How you ruled the BATTLE TOWER!\l"
# 332 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "You beat over 50 TRAINERS in a row?\p"
# 333 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "That's fantastic!\n"
# 334 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "I want you to have this!$"
# 335 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"

# 336 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
BattleFrontier_ScottsHouse_Text_Beat100TrainersInARow:
# 337 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "SCOTT: Oh, my! I heard about you!\n"
# 338 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "How you overwhelmed the BATTLE TOWER!\l"
# 339 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "You beat over 100 TRAINERS in a row?\p"
# 340 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "That's ridiculously spectacular!\n"
# 341 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "You've got to have this!$"
# 342 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"

# 343 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
BattleFrontier_ScottsHouse_Text_ExpectingToHearEvenGreaterThings:
# 344 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "I'll be expecting to hear even greater\n"
# 345 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "things about you now!$"
# 346 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"

# 347 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
BattleFrontier_ScottsHouse_Text_ComeBackForThisLater:
# 348 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "Oops, well, if you have too much\n"
# 349 "data//maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "stuff, come back for this later.$"
