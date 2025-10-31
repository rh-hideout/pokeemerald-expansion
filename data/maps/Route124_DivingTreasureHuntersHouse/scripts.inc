# 1 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"

# 2 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
Route124_DivingTreasureHuntersHouse_MapScripts::
# 3 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route124_DivingTreasureHuntersHouse_OnTransition
# 4 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	.byte 0
# 5 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"

# 6 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
Route124_DivingTreasureHuntersHouse_OnTransition:
# 7 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	setflag FLAG_LANDMARK_HUNTERS_HOUSE
# 8 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	end
# 9 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"

# 10 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
Route124_DivingTreasureHuntersHouse_EventScript_TreasureHunter::
# 11 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	lock
# 12 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	faceplayer
# 13 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	goto_if_set FLAG_MET_DIVING_TREASURE_HUNTER, Route124_DivingTreasureHuntersHouse_EventScript_SkipGreeting
# 14 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	msgbox Route124_DivingTreasureHuntersHouse_Text_Greeting, MSGBOX_DEFAULT
# 15 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	setflag FLAG_MET_DIVING_TREASURE_HUNTER
# 16 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	goto Route124_DivingTreasureHuntersHouse_EventScript_CheckPlayerHasShard
# 17 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	end
# 18 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"

# 19 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
Route124_DivingTreasureHuntersHouse_EventScript_SkipGreeting::
# 20 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	msgbox Route124_DivingTreasureHuntersHouse_Text_HaveYouSeenAnyShards, MSGBOX_DEFAULT
# 21 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	goto Route124_DivingTreasureHuntersHouse_EventScript_CheckPlayerHasShard
# 22 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	end
# 23 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"

# 24 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
Route124_DivingTreasureHuntersHouse_EventScript_CheckPlayerHasShard::
# 25 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	call Route124_DivingTreasureHuntersHouse_EventScript_GetPlayersShards
# 26 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	goto_if_eq VAR_TEMP_1, 0, Route124_DivingTreasureHuntersHouse_EventScript_NoShards
# 27 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	goto Route124_DivingTreasureHuntersHouse_EventScript_HasShard
# 28 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	end
# 29 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"

# 30 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
Route124_DivingTreasureHuntersHouse_EventScript_GetPlayersShards::
# 31 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	setvar VAR_TEMP_1, 0
# 32 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	checkitem ITEM_RED_SHARD
# 33 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	call_if_eq VAR_RESULT, TRUE, Route124_DivingTreasureHuntersHouse_EventScript_HasRedShard
# 34 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	checkitem ITEM_YELLOW_SHARD
# 35 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	call_if_eq VAR_RESULT, TRUE, Route124_DivingTreasureHuntersHouse_EventScript_HasYellowShard
# 36 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	checkitem ITEM_BLUE_SHARD
# 37 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	call_if_eq VAR_RESULT, TRUE, Route124_DivingTreasureHuntersHouse_EventScript_HasBlueShard
# 38 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	checkitem ITEM_GREEN_SHARD
# 39 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	call_if_eq VAR_RESULT, TRUE, Route124_DivingTreasureHuntersHouse_EventScript_HasGreenShard
# 40 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	return
# 41 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"

# 42 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
Route124_DivingTreasureHuntersHouse_EventScript_HasRedShard::
# 43 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	addvar VAR_TEMP_1, 1
# 44 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	return
# 45 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"

# 46 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
Route124_DivingTreasureHuntersHouse_EventScript_HasYellowShard::
# 47 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	addvar VAR_TEMP_1, 2
# 48 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	return
# 49 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"

# 50 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
Route124_DivingTreasureHuntersHouse_EventScript_HasBlueShard::
# 51 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	addvar VAR_TEMP_1, 4
# 52 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	return
# 53 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"

# 54 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
Route124_DivingTreasureHuntersHouse_EventScript_HasGreenShard::
# 55 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	addvar VAR_TEMP_1, 8
# 56 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	return
# 57 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"

# 58 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
Route124_DivingTreasureHuntersHouse_EventScript_HasShard::
# 59 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	msgbox Route124_DivingTreasureHuntersHouse_Text_ThatsAShardIllTradeYou, MSGBOX_DEFAULT
# 60 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	goto Route124_DivingTreasureHuntersHouse_EventScript_ShowTradeOptions
# 61 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	end
# 62 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"

# 63 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
Route124_DivingTreasureHuntersHouse_EventScript_ShowTradeOptions::
# 64 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	message Route124_DivingTreasureHuntersHouse_Text_WhatDoYouWantToTrade
# 65 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	waitmessage
# 66 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	switch VAR_TEMP_1
# 67 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	case 1,  Route124_DivingTreasureHuntersHouse_EventScript_ShardOptionsR
# 68 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	case 2,  Route124_DivingTreasureHuntersHouse_EventScript_ShardOptionsY
# 69 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	case 3,  Route124_DivingTreasureHuntersHouse_EventScript_ShardOptionsRY
# 70 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	case 4,  Route124_DivingTreasureHuntersHouse_EventScript_ShardOptionsB
# 71 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	case 5,  Route124_DivingTreasureHuntersHouse_EventScript_ShardOptionsRB
# 72 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	case 6,  Route124_DivingTreasureHuntersHouse_EventScript_ShardOptionsYB
# 73 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	case 7,  Route124_DivingTreasureHuntersHouse_EventScript_ShardOptionsRYB
# 74 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	case 8,  Route124_DivingTreasureHuntersHouse_EventScript_ShardOptionsG
# 75 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	case 9,  Route124_DivingTreasureHuntersHouse_EventScript_ShardOptionsRG
# 76 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	case 10, Route124_DivingTreasureHuntersHouse_EventScript_ShardOptionsYG
# 77 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	case 11, Route124_DivingTreasureHuntersHouse_EventScript_ShardOptionsRYG
# 78 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	case 12, Route124_DivingTreasureHuntersHouse_EventScript_ShardOptionsBG
# 79 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	case 13, Route124_DivingTreasureHuntersHouse_EventScript_ShardOptionsRBG
# 80 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	case 14, Route124_DivingTreasureHuntersHouse_EventScript_ShardOptionsYBG
# 81 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	case 15, Route124_DivingTreasureHuntersHouse_EventScript_ShardOptionsRYBG
# 82 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	end
# 83 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"

# 84 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
Route124_DivingTreasureHuntersHouse_EventScript_ShardOptionsR::
# 85 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	multichoice 0, 0, MULTI_SHARDS_R, FALSE
# 86 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	switch VAR_RESULT
# 87 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	case 0, Route124_DivingTreasureHuntersHouse_EventScript_TradeRedShard
# 88 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	case 1, Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade
# 89 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	goto Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade
# 90 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	end
# 91 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"

# 92 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
Route124_DivingTreasureHuntersHouse_EventScript_ShardOptionsY::
# 93 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	multichoice 0, 0, MULTI_SHARDS_Y, FALSE
# 94 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	switch VAR_RESULT
# 95 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	case 0, Route124_DivingTreasureHuntersHouse_EventScript_TradeYellowShard
# 96 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	case 1, Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade
# 97 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	goto Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade
# 98 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	end
# 99 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"

# 100 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
Route124_DivingTreasureHuntersHouse_EventScript_ShardOptionsRY::
# 101 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	multichoice 0, 0, MULTI_SHARDS_RY, FALSE
# 102 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	switch VAR_RESULT
# 103 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	case 0, Route124_DivingTreasureHuntersHouse_EventScript_TradeRedShard
# 104 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	case 1, Route124_DivingTreasureHuntersHouse_EventScript_TradeYellowShard
# 105 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	case 2, Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade
# 106 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	goto Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade
# 107 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	end
# 108 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"

# 109 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
Route124_DivingTreasureHuntersHouse_EventScript_ShardOptionsB::
# 110 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	multichoice 0, 0, MULTI_SHARDS_B, FALSE
# 111 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	switch VAR_RESULT
# 112 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	case 0, Route124_DivingTreasureHuntersHouse_EventScript_TradeBlueShard
# 113 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	case 1, Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade
# 114 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	goto Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade
# 115 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	end
# 116 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"

# 117 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
Route124_DivingTreasureHuntersHouse_EventScript_ShardOptionsRB::
# 118 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	multichoice 0, 0, MULTI_SHARDS_RB, FALSE
# 119 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	switch VAR_RESULT
# 120 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	case 0, Route124_DivingTreasureHuntersHouse_EventScript_TradeRedShard
# 121 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	case 1, Route124_DivingTreasureHuntersHouse_EventScript_TradeBlueShard
# 122 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	case 2, Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade
# 123 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	goto Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade
# 124 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	end
# 125 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"

# 126 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
Route124_DivingTreasureHuntersHouse_EventScript_ShardOptionsYB::
# 127 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	multichoice 0, 0, MULTI_SHARDS_YB, FALSE
# 128 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	switch VAR_RESULT
# 129 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	case 0, Route124_DivingTreasureHuntersHouse_EventScript_TradeYellowShard
# 130 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	case 1, Route124_DivingTreasureHuntersHouse_EventScript_TradeBlueShard
# 131 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	case 2, Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade
# 132 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	goto Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade
# 133 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	end
# 134 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"

# 135 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
Route124_DivingTreasureHuntersHouse_EventScript_ShardOptionsRYB::
# 136 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	multichoice 0, 0, MULTI_SHARDS_RYB, FALSE
# 137 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	switch VAR_RESULT
# 138 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	case 0, Route124_DivingTreasureHuntersHouse_EventScript_TradeRedShard
# 139 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	case 1, Route124_DivingTreasureHuntersHouse_EventScript_TradeYellowShard
# 140 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	case 2, Route124_DivingTreasureHuntersHouse_EventScript_TradeBlueShard
# 141 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	case 3, Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade
# 142 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	goto Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade
# 143 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	end
# 144 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"

# 145 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
Route124_DivingTreasureHuntersHouse_EventScript_ShardOptionsG::
# 146 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	multichoice 0, 0, MULTI_SHARDS_G, FALSE
# 147 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	switch VAR_RESULT
# 148 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	case 0, Route124_DivingTreasureHuntersHouse_EventScript_TradeGreenShard
# 149 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	case 1, Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade
# 150 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	goto Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade
# 151 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	end
# 152 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"

# 153 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
Route124_DivingTreasureHuntersHouse_EventScript_ShardOptionsRG::
# 154 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	multichoice 0, 0, MULTI_SHARDS_RG, FALSE
# 155 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	switch VAR_RESULT
# 156 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	case 0, Route124_DivingTreasureHuntersHouse_EventScript_TradeRedShard
# 157 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	case 1, Route124_DivingTreasureHuntersHouse_EventScript_TradeGreenShard
# 158 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	case 2, Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade
# 159 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	goto Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade
# 160 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	end
# 161 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"

# 162 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
Route124_DivingTreasureHuntersHouse_EventScript_ShardOptionsYG::
# 163 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	multichoice 0, 0, MULTI_SHARDS_YG, FALSE
# 164 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	switch VAR_RESULT
# 165 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	case 0, Route124_DivingTreasureHuntersHouse_EventScript_TradeYellowShard
# 166 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	case 1, Route124_DivingTreasureHuntersHouse_EventScript_TradeGreenShard
# 167 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	case 2, Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade
# 168 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	goto Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade
# 169 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	end
# 170 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"

# 171 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
Route124_DivingTreasureHuntersHouse_EventScript_ShardOptionsRYG::
# 172 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	multichoice 0, 0, MULTI_SHARDS_RYG, FALSE
# 173 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	switch VAR_RESULT
# 174 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	case 0, Route124_DivingTreasureHuntersHouse_EventScript_TradeRedShard
# 175 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	case 1, Route124_DivingTreasureHuntersHouse_EventScript_TradeYellowShard
# 176 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	case 2, Route124_DivingTreasureHuntersHouse_EventScript_TradeGreenShard
# 177 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	case 3, Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade
# 178 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	goto Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade
# 179 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	end
# 180 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"

# 181 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
Route124_DivingTreasureHuntersHouse_EventScript_ShardOptionsBG::
# 182 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	multichoice 0, 0, MULTI_SHARDS_BG, FALSE
# 183 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	switch VAR_RESULT
# 184 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	case 0, Route124_DivingTreasureHuntersHouse_EventScript_TradeBlueShard
# 185 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	case 1, Route124_DivingTreasureHuntersHouse_EventScript_TradeGreenShard
# 186 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	case 2, Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade
# 187 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	goto Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade
# 188 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	end
# 189 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"

# 190 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
Route124_DivingTreasureHuntersHouse_EventScript_ShardOptionsRBG::
# 191 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	multichoice 0, 0, MULTI_SHARDS_RBG, FALSE
# 192 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	switch VAR_RESULT
# 193 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	case 0, Route124_DivingTreasureHuntersHouse_EventScript_TradeRedShard
# 194 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	case 1, Route124_DivingTreasureHuntersHouse_EventScript_TradeBlueShard
# 195 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	case 2, Route124_DivingTreasureHuntersHouse_EventScript_TradeGreenShard
# 196 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	case 3, Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade
# 197 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	goto Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade
# 198 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	end
# 199 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"

# 200 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
Route124_DivingTreasureHuntersHouse_EventScript_ShardOptionsYBG::
# 201 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	multichoice 0, 0, MULTI_SHARDS_YBG, FALSE
# 202 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	switch VAR_RESULT
# 203 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	case 0, Route124_DivingTreasureHuntersHouse_EventScript_TradeYellowShard
# 204 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	case 1, Route124_DivingTreasureHuntersHouse_EventScript_TradeBlueShard
# 205 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	case 2, Route124_DivingTreasureHuntersHouse_EventScript_TradeGreenShard
# 206 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	case 3, Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade
# 207 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	goto Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade
# 208 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	end
# 209 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"

# 210 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
Route124_DivingTreasureHuntersHouse_EventScript_ShardOptionsRYBG::
# 211 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	multichoice 0, 0, MULTI_SHARDS_RYBG, FALSE
# 212 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	switch VAR_RESULT
# 213 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	case 0, Route124_DivingTreasureHuntersHouse_EventScript_TradeRedShard
# 214 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	case 1, Route124_DivingTreasureHuntersHouse_EventScript_TradeYellowShard
# 215 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	case 2, Route124_DivingTreasureHuntersHouse_EventScript_TradeBlueShard
# 216 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	case 3, Route124_DivingTreasureHuntersHouse_EventScript_TradeGreenShard
# 217 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	case 4, Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade
# 218 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	goto Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade
# 219 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	end
# 220 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"

# 221 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
Route124_DivingTreasureHuntersHouse_EventScript_TradeRedShard::
# 222 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	setvar VAR_0x8008, ITEM_RED_SHARD
# 223 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	setvar VAR_0x8009, ITEM_FIRE_STONE
# 224 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	goto Route124_DivingTreasureHuntersHouse_EventScript_TryTradeShard
# 225 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"

# 226 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
Route124_DivingTreasureHuntersHouse_EventScript_TradeYellowShard::
# 227 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	setvar VAR_0x8008, ITEM_YELLOW_SHARD
# 228 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	setvar VAR_0x8009, ITEM_THUNDER_STONE
# 229 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	goto Route124_DivingTreasureHuntersHouse_EventScript_TryTradeShard
# 230 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"

# 231 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
Route124_DivingTreasureHuntersHouse_EventScript_TradeBlueShard::
# 232 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	setvar VAR_0x8008, ITEM_BLUE_SHARD
# 233 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	setvar VAR_0x8009, ITEM_WATER_STONE
# 234 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	goto Route124_DivingTreasureHuntersHouse_EventScript_TryTradeShard
# 235 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"

# 236 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
Route124_DivingTreasureHuntersHouse_EventScript_TradeGreenShard::
# 237 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	setvar VAR_0x8008, ITEM_GREEN_SHARD
# 238 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	setvar VAR_0x8009, ITEM_LEAF_STONE
# 239 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	goto Route124_DivingTreasureHuntersHouse_EventScript_TryTradeShard
# 240 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"

# 241 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
Route124_DivingTreasureHuntersHouse_EventScript_TryTradeShard::
# 242 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	bufferitemname STR_VAR_1, VAR_0x8008
# 243 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	bufferitemname STR_VAR_2, VAR_0x8009
# 244 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	msgbox Route124_DivingTreasureHuntersHouse_Text_YoullTradeShardForStone, MSGBOX_YESNO
# 245 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	goto_if_eq VAR_RESULT, NO, Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade
# 246 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	checkitemspace VAR_0x8009
# 247 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route124_DivingTreasureHuntersHouse_EventScript_TradeShard
# 248 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	checkitem VAR_0x8008, 2
# 249 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Route124_DivingTreasureHuntersHouse_EventScript_TradeShard
# 250 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	goto Route124_DivingTreasureHuntersHouse_EventScript_BagFull
# 251 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	end
# 252 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"

# 253 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
Route124_DivingTreasureHuntersHouse_EventScript_TradeShard::
# 254 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	removeitem VAR_0x8008
# 255 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	giveitem VAR_0x8009
# 256 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	msgbox Route124_DivingTreasureHuntersHouse_Text_ItsADeal, MSGBOX_DEFAULT
# 257 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	call Route124_DivingTreasureHuntersHouse_EventScript_GetPlayersShards
# 258 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	goto_if_eq VAR_TEMP_1, 0, Route124_DivingTreasureHuntersHouse_EventScript_EndTrade
# 259 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	msgbox Route124_DivingTreasureHuntersHouse_Text_TradeSomethingElse, MSGBOX_YESNO
# 260 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	goto_if_eq VAR_RESULT, YES, Route124_DivingTreasureHuntersHouse_EventScript_ShowTradeOptions
# 261 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	goto Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade
# 262 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	end
# 263 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"

# 264 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
Route124_DivingTreasureHuntersHouse_EventScript_BagFull::
# 265 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	msgbox Route124_DivingTreasureHuntersHouse_Text_BagFull, MSGBOX_DEFAULT
# 266 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	release
# 267 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	end
# 268 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"

# 269 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade::
# 270 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	msgbox Route124_DivingTreasureHuntersHouse_Text_ComeBackIfYouChangeMind, MSGBOX_DEFAULT
# 271 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	release
# 272 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	end
# 273 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"

# 274 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
Route124_DivingTreasureHuntersHouse_EventScript_NoShards::
# 275 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	msgbox Route124_DivingTreasureHuntersHouse_Text_YouHaventGotAnyShards, MSGBOX_DEFAULT
# 276 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	release
# 277 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	end
# 278 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"

# 279 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
Route124_DivingTreasureHuntersHouse_EventScript_EndTrade::
# 280 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	release
# 281 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	end
# 282 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"

# 283 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
Route124_DivingTreasureHuntersHouse_EventScript_ShardTradeBoard::
# 284 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	msgbox Route124_DivingTreasureHuntersHouse_Text_ShardTradeBoard, MSGBOX_SIGN
# 285 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	end
# 286 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"

# 287 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
Route124_DivingTreasureHuntersHouse_Text_Greeting:
# 288 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	.string "I'm the DIVING TREASURE HUNTER!\p"
# 289 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	.string "I'm the awesome dude who makes\n"
# 290 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	.string "deep-sea dives to gather treasures\l"
# 291 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	.string "resting at the bottom.$"
# 292 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"

# 293 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
Route124_DivingTreasureHuntersHouse_Text_HaveYouSeenAnyShards:
# 294 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	.string "Tell me, have you seen any SHARDS of\n"
# 295 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	.string "tools made in ancient times?$"
# 296 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"

# 297 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
Route124_DivingTreasureHuntersHouse_Text_YouHaventGotAnyShards:
# 298 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	.string "You haven't got any treasures\n"
# 299 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	.string "for me…\p"
# 300 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	.string "If you see any SHARDS, like the RED\n"
# 301 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	.string "SHARD, you've got to trade it with me!$"
# 302 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"

# 303 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
Route124_DivingTreasureHuntersHouse_Text_ThatsAShardIllTradeYou:
# 304 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	.string "Oh, hey! That…\n"
# 305 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	.string "That's a SHARD! I'm looking for those!\p"
# 306 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	.string "Oh, man, you've got to trade that\n"
# 307 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	.string "with me! I'll give you something good!$"
# 308 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"

# 309 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
Route124_DivingTreasureHuntersHouse_Text_WhatDoYouWantToTrade:
# 310 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	.string "What do you want to trade?$"
# 311 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"

# 312 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
Route124_DivingTreasureHuntersHouse_Text_YoullTradeShardForStone:
# 313 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	.string "You'll trade your {STR_VAR_1} for\n"
# 314 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	.string "my {STR_VAR_2}, then?$"
# 315 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"

# 316 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
Route124_DivingTreasureHuntersHouse_Text_ItsADeal:
# 317 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	.string "It's a done deal!\n"
# 318 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	.string "Use that wisely!$"
# 319 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"

# 320 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
Route124_DivingTreasureHuntersHouse_Text_TradeSomethingElse:
# 321 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	.string "Do you want to trade something else?$"
# 322 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"

# 323 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
Route124_DivingTreasureHuntersHouse_Text_BagFull:
# 324 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	.string "Whoops, your BAG's full.\n"
# 325 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	.string "Get rid of some items, friend!$"
# 326 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"

# 327 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
Route124_DivingTreasureHuntersHouse_Text_ComeBackIfYouChangeMind:
# 328 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	.string "No? That's a downer.\n"
# 329 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	.string "Well, if you change your mind, come back.$"
# 330 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"

# 331 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
Route124_DivingTreasureHuntersHouse_Text_ShardTradeBoard:
# 332 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	.string "{CLEAR_TO 0x0a}Wanted item{CLEAR_TO 0x7c}Trade item\n"
# 333 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	.string "{CLEAR_TO 0x0f}RED SHARD{CLEAR_TO 0x59}{LEFT_ARROW}{RIGHT_ARROW}{CLEAR_TO 0x7b}FIRE STONE{CLEAR_TO 0xc8}\p"
# 334 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	.string "{CLEAR_TO 0x0a}Wanted item{CLEAR_TO 0x7c}Trade item\n"
# 335 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	.string "{CLEAR_TO 0x06}YELLOW SHARD{CLEAR_TO 0x59}{LEFT_ARROW}{RIGHT_ARROW}{CLEAR_TO 0x73}THUNDERSTONE{CLEAR_TO 0xc8}\p"
# 336 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	.string "{CLEAR_TO 0x0a}Wanted item{CLEAR_TO 0x7c}Trade item\n"
# 337 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	.string "{CLEAR_TO 0x0c}BLUE SHARD{CLEAR_TO 0x59}{LEFT_ARROW}{RIGHT_ARROW}{CLEAR_TO 0x79}WATER STONE{CLEAR_TO 0xc8}\p"
# 338 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	.string "{CLEAR_TO 0x0a}Wanted item{CLEAR_TO 0x7c}Trade item\n"
# 339 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	.string "{CLEAR_TO 0x08}GREEN SHARD{CLEAR_TO 0x59}{LEFT_ARROW}{RIGHT_ARROW}{CLEAR_TO 0x7b}LEAF STONE$"
