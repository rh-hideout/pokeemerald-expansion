# 1 "data/maps/RustboroCity_PokemonSchool/scripts.pory"

# 2 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
RustboroCity_PokemonSchool_MapScripts::
# 3 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.byte 0
# 4 "data/maps/RustboroCity_PokemonSchool/scripts.pory"

# 5 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
RustboroCity_PokemonSchool_EventScript_Blackboard::
# 6 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	lockall
# 7 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	msgbox RustboroCity_PokemonSchool_Text_BlackboardListsStatusChanges, MSGBOX_DEFAULT
# 8 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
# 9 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	end
# 10 "data/maps/RustboroCity_PokemonSchool/scripts.pory"

# 11 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic::
# 12 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	message RustboroCity_PokemonSchool_Text_ReadWhichTopic
# 13 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	waitmessage
# 14 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	multichoicegrid 8, 1, MULTI_STATUS_INFO, 3, FALSE
# 15 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	switch VAR_RESULT
# 16 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	case 0, RustboroCity_PokemonSchool_EventScript_Poison
# 17 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	case 1, RustboroCity_PokemonSchool_EventScript_Paralysis
# 18 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	case 2, RustboroCity_PokemonSchool_EventScript_Sleep
# 19 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	case 3, RustboroCity_PokemonSchool_EventScript_Burn
# 20 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	case 4, RustboroCity_PokemonSchool_EventScript_Freeze
# 21 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	case 5, RustboroCity_PokemonSchool_EventScript_ExitTopicSelect
# 22 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	case MULTI_B_PRESSED, RustboroCity_PokemonSchool_EventScript_ExitTopicSelect
# 23 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	end
# 24 "data/maps/RustboroCity_PokemonSchool/scripts.pory"

# 25 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
RustboroCity_PokemonSchool_EventScript_Poison::
# 26 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	msgbox RustboroCity_PokemonSchool_Text_ExplainPoison, MSGBOX_DEFAULT
# 27 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
# 28 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	end
# 29 "data/maps/RustboroCity_PokemonSchool/scripts.pory"

# 30 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
RustboroCity_PokemonSchool_EventScript_Paralysis::
# 31 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	msgbox RustboroCity_PokemonSchool_Text_ExplainParalysis, MSGBOX_DEFAULT
# 32 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
# 33 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	end
# 34 "data/maps/RustboroCity_PokemonSchool/scripts.pory"

# 35 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
RustboroCity_PokemonSchool_EventScript_Sleep::
# 36 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	msgbox RustboroCity_PokemonSchool_Text_ExplainSleep, MSGBOX_DEFAULT
# 37 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
# 38 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	end
# 39 "data/maps/RustboroCity_PokemonSchool/scripts.pory"

# 40 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
RustboroCity_PokemonSchool_EventScript_Burn::
# 41 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	msgbox RustboroCity_PokemonSchool_Text_ExplainBurn, MSGBOX_DEFAULT
# 42 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
# 43 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	end
# 44 "data/maps/RustboroCity_PokemonSchool/scripts.pory"

# 45 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
RustboroCity_PokemonSchool_EventScript_Freeze::
# 46 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	msgbox RustboroCity_PokemonSchool_Text_ExplainFreeze, MSGBOX_DEFAULT
# 47 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
# 48 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	end
# 49 "data/maps/RustboroCity_PokemonSchool/scripts.pory"

# 50 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
RustboroCity_PokemonSchool_EventScript_ExitTopicSelect::
# 51 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	releaseall
# 52 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	end
# 53 "data/maps/RustboroCity_PokemonSchool/scripts.pory"

# 54 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
RustboroCity_PokemonSchool_EventScript_GameboyKid1::
# 55 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	msgbox RustboroCity_PokemonSchool_Text_TradingRightNow, MSGBOX_NPC
# 56 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	end
# 57 "data/maps/RustboroCity_PokemonSchool/scripts.pory"

# 58 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
RustboroCity_PokemonSchool_EventScript_GameboyKid2::
# 59 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	msgbox RustboroCity_PokemonSchool_Text_AlwaysWantedSeedot, MSGBOX_NPC
# 60 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	end
# 61 "data/maps/RustboroCity_PokemonSchool/scripts.pory"

# 62 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
RustboroCity_PokemonSchool_EventScript_RichBoy::
# 63 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	msgbox RustboroCity_PokemonSchool_Text_PokemontCantUseManMadeItems, MSGBOX_NPC
# 64 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	end
# 65 "data/maps/RustboroCity_PokemonSchool/scripts.pory"

# 66 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
RustboroCity_PokemonSchool_EventScript_Lass::
# 67 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	msgbox RustboroCity_PokemonSchool_Text_ConfusedPokemonAttacksItself, MSGBOX_NPC
# 68 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	end
# 69 "data/maps/RustboroCity_PokemonSchool/scripts.pory"

# 70 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
RustboroCity_PokemonSchool_EventScript_SchoolKidM::
# 71 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	msgbox RustboroCity_PokemonSchool_Text_PokemonHealItselfWithBerry, MSGBOX_NPC
# 72 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	end
# 73 "data/maps/RustboroCity_PokemonSchool/scripts.pory"

# 74 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
RustboroCity_PokemonSchool_EventScript_StudentNotebook::
# 75 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	msgbox RustboroCity_PokemonSchool_Text_StudentsNotes, MSGBOX_SIGN
# 76 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	end
# 77 "data/maps/RustboroCity_PokemonSchool/scripts.pory"

# 78 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
RustboroCity_PokemonSchool_EventScript_Teacher::
# 79 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	lock
# 80 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	faceplayer
# 81 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	goto_if_set FLAG_RECEIVED_QUICK_CLAW, RustboroCity_PokemonSchool_EventScript_GaveQuickClaw
# 82 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsEast
# 83 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	call_if_eq VAR_FACING, DIR_WEST, RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsWest
# 84 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	msgbox RustboroCity_PokemonSchool_Text_StudentsWhoDontStudyGetQuickClaw, MSGBOX_DEFAULT
# 85 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	giveitem ITEM_QUICK_CLAW
# 86 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	goto_if_eq VAR_RESULT, 0, Common_EventScript_ShowBagIsFull
# 87 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	closemessage
# 88 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
# 89 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	waitmovement 0
# 90 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	setflag FLAG_RECEIVED_QUICK_CLAW
# 91 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	release
# 92 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	end
# 93 "data/maps/RustboroCity_PokemonSchool/scripts.pory"

# 94 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsEast::
# 95 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	applymovement VAR_LAST_TALKED, RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsEast
# 96 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	waitmovement 0
# 97 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	return
# 98 "data/maps/RustboroCity_PokemonSchool/scripts.pory"

# 99 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsWest::
# 100 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	applymovement VAR_LAST_TALKED, RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsWest
# 101 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	waitmovement 0
# 102 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	return
# 103 "data/maps/RustboroCity_PokemonSchool/scripts.pory"

# 104 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
RustboroCity_PokemonSchool_EventScript_GaveQuickClaw::
# 105 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	msgbox RustboroCity_PokemonSchool_Text_ExplainQuickClaw, MSGBOX_DEFAULT
# 106 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	closemessage
# 107 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
# 108 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	waitmovement 0
# 109 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	release
# 110 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	end
# 111 "data/maps/RustboroCity_PokemonSchool/scripts.pory"

# 112 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsWest:
# 113 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	walk_left
# 114 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	walk_down
# 115 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	walk_down
# 116 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	walk_right
# 117 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	walk_in_place_faster_down
# 118 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	delay_16
# 119 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	delay_16
# 120 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	delay_16
# 121 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	walk_down
# 122 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	walk_in_place_faster_left
# 123 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	delay_16
# 124 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	delay_16
# 125 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	walk_right
# 126 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	delay_16
# 127 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	delay_16
# 128 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	delay_8
# 129 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	walk_up
# 130 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	walk_left
# 131 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	walk_left
# 132 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	walk_up
# 133 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	walk_up
# 134 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	walk_right
# 135 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	step_end
# 136 "data/maps/RustboroCity_PokemonSchool/scripts.pory"

# 137 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsEast:
# 138 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	walk_right
# 139 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	walk_right
# 140 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	walk_down
# 141 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	walk_down
# 142 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	walk_left
# 143 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	walk_left
# 144 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	walk_in_place_faster_down
# 145 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	delay_16
# 146 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	delay_16
# 147 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	delay_16
# 148 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	walk_down
# 149 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	walk_in_place_faster_left
# 150 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	delay_16
# 151 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	delay_16
# 152 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	walk_right
# 153 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	delay_16
# 154 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	delay_16
# 155 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	delay_8
# 156 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	walk_up
# 157 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	walk_right
# 158 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	walk_up
# 159 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	walk_up
# 160 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	walk_left
# 161 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	walk_left
# 162 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	step_end
# 163 "data/maps/RustboroCity_PokemonSchool/scripts.pory"

# 164 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
RustboroCity_PokemonSchool_EventScript_Scott::
# 165 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	lock
# 166 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	faceplayer
# 167 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	goto_if_set FLAG_MET_SCOTT_AFTER_OBTAINING_STONE_BADGE, RustboroCity_PokemonSchool_EventScript_ScottWatchStudents
# 168 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	goto_if_set FLAG_MET_SCOTT_RUSTBORO, RustboroCity_PokemonSchool_EventScript_ScottSpokeAlready
# 169 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	goto_if_set FLAG_BADGE01_GET, RustboroCity_PokemonSchool_EventScript_ScottGreetHasBadge
# 170 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	msgbox RustboroCity_PokemonSchool_Text_ScottMetAlreadyCut, MSGBOX_DEFAULT
# 171 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	addvar VAR_SCOTT_STATE, 1
# 172 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	setflag FLAG_MET_SCOTT_RUSTBORO
# 173 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	release
# 174 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	end
# 175 "data/maps/RustboroCity_PokemonSchool/scripts.pory"

# 176 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
RustboroCity_PokemonSchool_EventScript_ScottSpokeAlready::
# 177 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	goto_if_set FLAG_BADGE01_GET, RustboroCity_PokemonSchool_EventScript_ScottNoticeBadge
# 178 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	msgbox RustboroCity_PokemonSchool_Text_StudentTalentLevelUnknown, MSGBOX_DEFAULT
# 179 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	release
# 180 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	end
# 181 "data/maps/RustboroCity_PokemonSchool/scripts.pory"

# 182 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
RustboroCity_PokemonSchool_EventScript_ScottGreetHasBadge::
# 183 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	msgbox RustboroCity_PokemonSchool_Text_ScottMetAlreadyStoneBadge, MSGBOX_DEFAULT
# 184 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	goto RustboroCity_PokemonSchool_EventScript_MetScottAfterBadge
# 185 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	end
# 186 "data/maps/RustboroCity_PokemonSchool/scripts.pory"

# 187 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
RustboroCity_PokemonSchool_EventScript_ScottNoticeBadge::
# 188 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	msgbox RustboroCity_PokemonSchool_Text_ScottStoneBadge, MSGBOX_DEFAULT
# 189 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	goto RustboroCity_PokemonSchool_EventScript_MetScottAfterBadge
# 190 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	end
# 191 "data/maps/RustboroCity_PokemonSchool/scripts.pory"

# 192 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
RustboroCity_PokemonSchool_EventScript_MetScottAfterBadge::
# 193 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	addvar VAR_SCOTT_STATE, 1
# 194 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	setflag FLAG_MET_SCOTT_AFTER_OBTAINING_STONE_BADGE
# 195 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	release
# 196 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	end
# 197 "data/maps/RustboroCity_PokemonSchool/scripts.pory"

# 198 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
RustboroCity_PokemonSchool_EventScript_ScottWatchStudents::
# 199 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	msgbox RustboroCity_PokemonSchool_Text_StudentTalentLevelUnknown, MSGBOX_DEFAULT
# 200 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	release
# 201 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	end
# 202 "data/maps/RustboroCity_PokemonSchool/scripts.pory"

# 203 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
RustboroCity_PokemonSchool_Text_BlackboardListsStatusChanges:
# 204 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "The blackboard lists status changes\n"
# 205 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "that may affect POKéMON in battle.$"
# 206 "data/maps/RustboroCity_PokemonSchool/scripts.pory"

# 207 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
RustboroCity_PokemonSchool_Text_ReadWhichTopic:
# 208 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "Which topic do you want to read?$"
# 209 "data/maps/RustboroCity_PokemonSchool/scripts.pory"

# 210 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
RustboroCity_PokemonSchool_Text_ExplainPoison:
# 211 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "If a POKéMON is poisoned, it will\n"
# 212 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "steadily lose HP.\p"
# 213 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "The effects of poison remain after\n"
# 214 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "a battle.\p"
# 215 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "A poisoned POKéMON's HP will drop\n"
# 216 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "while it is traveling.\p"
# 217 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "Heal a poisoning using an ANTIDOTE.$"
# 218 "data/maps/RustboroCity_PokemonSchool/scripts.pory"

# 219 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
RustboroCity_PokemonSchool_Text_ExplainParalysis:
# 220 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "If a POKéMON becomes paralyzed,\n"
# 221 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "its SPEED drops.\p"
# 222 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "It may also not be able to move while\n"
# 223 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "it is in battle.\p"
# 224 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "Paralysis remains after battle.\n"
# 225 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "Cure it using a PARLYZ HEAL.$"
# 226 "data/maps/RustboroCity_PokemonSchool/scripts.pory"

# 227 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
RustboroCity_PokemonSchool_Text_ExplainSleep:
# 228 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "If a POKéMON falls asleep, it will be\n"
# 229 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "unable to attack.\p"
# 230 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "A POKéMON may wake up on its own,\n"
# 231 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "but if a battle ends while it is\l"
# 232 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "sleeping, it will stay asleep.\p"
# 233 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "Wake it up using an AWAKENING.$"
# 234 "data/maps/RustboroCity_PokemonSchool/scripts.pory"

# 235 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
RustboroCity_PokemonSchool_Text_ExplainBurn:
# 236 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "A burn reduces ATTACK power, and it\n"
# 237 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "steadily reduces the victim's HP.\p"
# 238 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "A burn lingers after battle.\n"
# 239 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "Cure a burn using a BURN HEAL.$"
# 240 "data/maps/RustboroCity_PokemonSchool/scripts.pory"

# 241 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
RustboroCity_PokemonSchool_Text_ExplainFreeze:
# 242 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "If a POKéMON is frozen, it becomes\n"
# 243 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "completely helpless.\p"
# 244 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "It will remain frozen after battle.\n"
# 245 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "Thaw it out using an ICE HEAL.$"
# 246 "data/maps/RustboroCity_PokemonSchool/scripts.pory"

# 247 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
RustboroCity_PokemonSchool_Text_StudentsWhoDontStudyGetQuickClaw:
# 248 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "Students who don't study get a little\n"
# 249 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "taste of my QUICK CLAW.\p"
# 250 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "Whether or not you are a good student \n"
# 251 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "will be evident from the way you use\l"
# 252 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "this item.$"
# 253 "data/maps/RustboroCity_PokemonSchool/scripts.pory"

# 254 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
RustboroCity_PokemonSchool_Text_ExplainQuickClaw:
# 255 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "A POKéMON holding the QUICK CLAW will\n"
# 256 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "occasionally speed up and get to move\l"
# 257 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "before its opponent.\p"
# 258 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "There are many other items that are\n"
# 259 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "meant to be held by POKéMON.\p"
# 260 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "Just those alone will give you many\n"
# 261 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "topics to study!$"
# 262 "data/maps/RustboroCity_PokemonSchool/scripts.pory"

# 263 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
RustboroCity_PokemonSchool_Text_TradingRightNow:
# 264 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "I'm trading POKéMON with my friend\n"
# 265 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "right now.$"
# 266 "data/maps/RustboroCity_PokemonSchool/scripts.pory"

# 267 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
RustboroCity_PokemonSchool_Text_AlwaysWantedSeedot:
# 268 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "I always wanted a SEEDOT, and\n"
# 269 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "I'm finally getting one!$"
# 270 "data/maps/RustboroCity_PokemonSchool/scripts.pory"

# 271 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
RustboroCity_PokemonSchool_Text_PokemontCantUseManMadeItems:
# 272 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "POKéMON can hold items, but they\n"
# 273 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "don't know what to do with man-made\l"
# 274 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "items like POTION and ANTIDOTE.$"
# 275 "data/maps/RustboroCity_PokemonSchool/scripts.pory"

# 276 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
RustboroCity_PokemonSchool_Text_ConfusedPokemonAttacksItself:
# 277 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "You know how some POKéMON moves can\n"
# 278 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "confuse a POKéMON?\p"
# 279 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "A confused POKéMON will sometimes\n"
# 280 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "attack itself without meaning to.\p"
# 281 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "But once it leaves battle, it will\n"
# 282 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "return to normal.$"
# 283 "data/maps/RustboroCity_PokemonSchool/scripts.pory"

# 284 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
RustboroCity_PokemonSchool_Text_PokemonHealItselfWithBerry:
# 285 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "A POKéMON holding a BERRY will heal\n"
# 286 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "itself…\p"
# 287 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "There are many kinds of items that\n"
# 288 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "POKéMON can hold…\p"
# 289 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "Boy, it sure is hard taking notes\n"
# 290 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "down…$"
# 291 "data/maps/RustboroCity_PokemonSchool/scripts.pory"

# 292 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
RustboroCity_PokemonSchool_Text_StudentsNotes:
# 293 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "It's this student's notebook…\p"
# 294 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "POKéMON are to be caught using\n"
# 295 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "POKé BALLS.\p"
# 296 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "Up to six POKéMON can accompany\n"
# 297 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "a TRAINER.\p"
# 298 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "A TRAINER is someone who catches\n"
# 299 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "POKéMON, raises them, and battles\l"
# 300 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "with them.\p"
# 301 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "A TRAINER's mission is to defeat\n"
# 302 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "the strong TRAINERS who await\l"
# 303 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "challengers in POKéMON GYMS.$"
# 304 "data/maps/RustboroCity_PokemonSchool/scripts.pory"

# 305 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
RustboroCity_PokemonSchool_Text_ScottMetAlreadyCut:
# 306 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "Hello? Didn't we meet before?\n"
# 307 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "I think back in PETALBURG CITY.\p"
# 308 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "Let me introduce myself.\n"
# 309 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "My name's SCOTT.\p"
# 310 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "I've been traveling everywhere in\n"
# 311 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "search of outstanding TRAINERS.\p"
# 312 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "More specifically, I'm looking for\n"
# 313 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "POKéMON battle experts.\p"
# 314 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "So, what brings you to this SCHOOL?\n"
# 315 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "Are you a TRAINER, too?\p"
# 316 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "The first thing you should do is to\n"
# 317 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "have a POKéMON learn the move CUT.\p"
# 318 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "If I remember correctly, someone in\n"
# 319 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "this town has CUT.$"
# 320 "data/maps/RustboroCity_PokemonSchool/scripts.pory"

# 321 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
RustboroCity_PokemonSchool_Text_StudentTalentLevelUnknown:
# 322 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "SCOTT: Hmm…\p"
# 323 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "The talent levels of the students here\n"
# 324 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "are unknown. The potential's there.$"
# 325 "data/maps/RustboroCity_PokemonSchool/scripts.pory"

# 326 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
RustboroCity_PokemonSchool_Text_ScottStoneBadge:
# 327 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "SCOTT: Oh, what's that?\p"
# 328 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "It's a STONE BADGE, isn't it?\n"
# 329 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "That's pretty impressive, I'd say.\p"
# 330 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "But, you know, I would've loved to see\n"
# 331 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "you in battle.\p"
# 332 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "It's hard to tell what you're like as\n"
# 333 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "a TRAINER from a LEAGUE BADGE.$"
# 334 "data/maps/RustboroCity_PokemonSchool/scripts.pory"

# 335 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
RustboroCity_PokemonSchool_Text_ScottMetAlreadyStoneBadge:
# 336 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "Hello? Didn't we meet before?\n"
# 337 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "I think back in PETALBURG CITY.\p"
# 338 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "Let me introduce myself.\n"
# 339 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "My name's SCOTT.\p"
# 340 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "I've been traveling everywhere in\n"
# 341 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "search of outstanding TRAINERS.\p"
# 342 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "More specifically, I'm looking for\n"
# 343 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "POKéMON battle experts.\p"
# 344 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "Oh, what's that?\n"
# 345 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "It's a STONE BADGE, isn't it?\p"
# 346 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "That's pretty impressive, I'd say, for\n"
# 347 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "a starting TRAINER like yourself.\p"
# 348 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "But, you know, I would've loved to see\n"
# 349 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "you in battle.\p"
# 350 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "It's hard to tell what you're like as\n"
# 351 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "a TRAINER from a LEAGUE BADGE.$"
