# 1 "data/maps/ContestHall/scripts.pory"

# 2 "data/maps/ContestHall/scripts.pory"
ContestHall_MapScripts::
# 3 "data/maps/ContestHall/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, ContestHall_OnWarp
# 4 "data/maps/ContestHall/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, ContestHall_OnFrame
# 5 "data/maps/ContestHall/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, ContestHall_OnTransition
# 6 "data/maps/ContestHall/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, ContestHall_OnResume
# 7 "data/maps/ContestHall/scripts.pory"
	map_script MAP_SCRIPT_ON_RETURN_TO_FIELD, ContestHall_OnReturn
# 8 "data/maps/ContestHall/scripts.pory"
	.byte 0
# 9 "data/maps/ContestHall/scripts.pory"

# 10 "data/maps/ContestHall/scripts.pory"
ContestHall_OnReturn:
# 11 "data/maps/ContestHall/scripts.pory"
	special LoadLinkContestPlayerPalettes
# 12 "data/maps/ContestHall/scripts.pory"
	end
# 13 "data/maps/ContestHall/scripts.pory"

# 14 "data/maps/ContestHall/scripts.pory"
ContestHall_OnTransition:
# 15 "data/maps/ContestHall/scripts.pory"
	call ContestHall_EventScript_ReadyContestMusic
# 16 "data/maps/ContestHall/scripts.pory"
	setvar VAR_TEMP_0, 1
# 17 "data/maps/ContestHall/scripts.pory"
	call ContestHall_EventScript_AddRandomAudienceMembers
# 18 "data/maps/ContestHall/scripts.pory"
	end
# 19 "data/maps/ContestHall/scripts.pory"

# 20 "data/maps/ContestHall/scripts.pory"
ContestHall_EventScript_ReadyContestMusic::
# 21 "data/maps/ContestHall/scripts.pory"
	call ContestHall_EventScript_TryWaitForLink
# 22 "data/maps/ContestHall/scripts.pory"
	special GetContestMultiplayerId
# 23 "data/maps/ContestHall/scripts.pory"
	call_if_eq VAR_RESULT, 0, ContestHall_EventScript_SaveContestMusicPlayer1
# 24 "data/maps/ContestHall/scripts.pory"
	call_if_eq VAR_RESULT, 1, ContestHall_EventScript_SaveContestMusicPlayer2
# 25 "data/maps/ContestHall/scripts.pory"
	call_if_eq VAR_RESULT, 2, ContestHall_EventScript_SaveContestMusicPlayer3
# 26 "data/maps/ContestHall/scripts.pory"
	call_if_eq VAR_RESULT, 3, ContestHall_EventScript_SaveContestMusicPlayer4
# 27 "data/maps/ContestHall/scripts.pory"
	call_if_eq VAR_RESULT, 4, ContestHall_EventScript_SaveContestMusic
# 28 "data/maps/ContestHall/scripts.pory"
	return
# 29 "data/maps/ContestHall/scripts.pory"

# 30 "data/maps/ContestHall/scripts.pory"
ContestHall_EventScript_SaveContestMusicPlayer1::
# 31 "data/maps/ContestHall/scripts.pory"
	savebgm MUS_LINK_CONTEST_P1
# 32 "data/maps/ContestHall/scripts.pory"
	return
# 33 "data/maps/ContestHall/scripts.pory"

# 34 "data/maps/ContestHall/scripts.pory"
ContestHall_EventScript_SaveContestMusicPlayer2::
# 35 "data/maps/ContestHall/scripts.pory"
	savebgm MUS_LINK_CONTEST_P2
# 36 "data/maps/ContestHall/scripts.pory"
	return
# 37 "data/maps/ContestHall/scripts.pory"

# 38 "data/maps/ContestHall/scripts.pory"
ContestHall_EventScript_SaveContestMusicPlayer3::
# 39 "data/maps/ContestHall/scripts.pory"
	savebgm MUS_LINK_CONTEST_P3
# 40 "data/maps/ContestHall/scripts.pory"
	return
# 41 "data/maps/ContestHall/scripts.pory"

# 42 "data/maps/ContestHall/scripts.pory"
ContestHall_EventScript_SaveContestMusicPlayer4::
# 43 "data/maps/ContestHall/scripts.pory"
	savebgm MUS_LINK_CONTEST_P4
# 44 "data/maps/ContestHall/scripts.pory"
	return
# 45 "data/maps/ContestHall/scripts.pory"

# 46 "data/maps/ContestHall/scripts.pory"
ContestHall_EventScript_SaveContestMusic::
# 47 "data/maps/ContestHall/scripts.pory"
	savebgm MUS_CONTEST
# 48 "data/maps/ContestHall/scripts.pory"
	return
# 49 "data/maps/ContestHall/scripts.pory"

# 50 "data/maps/ContestHall/scripts.pory"
ContestHall_OnResume:
# 51 "data/maps/ContestHall/scripts.pory"
	call_if_eq VAR_TEMP_9, 1, ContestHall_EventScript_ReShowAudience
# 52 "data/maps/ContestHall/scripts.pory"
	end
# 53 "data/maps/ContestHall/scripts.pory"

# 54 "data/maps/ContestHall/scripts.pory"
ContestHall_EventScript_ReShowAudience::
# 55 "data/maps/ContestHall/scripts.pory"
	call ContestHall_EventScript_CreateAudience
# 56 "data/maps/ContestHall/scripts.pory"
	return
# 57 "data/maps/ContestHall/scripts.pory"

# 58 "data/maps/ContestHall/scripts.pory"
ContestHall_OnFrame:
# 59 "data/maps/ContestHall/scripts.pory"
	map_script_2 VAR_CONTEST_HALL_STATE, 1, ContestHall_EventScript_Contest
# 60 "data/maps/ContestHall/scripts.pory"
	.2byte 0
# 61 "data/maps/ContestHall/scripts.pory"

# 62 "data/maps/ContestHall/scripts.pory"
ContestHall_OnWarp:
# 63 "data/maps/ContestHall/scripts.pory"
	map_script_2 VAR_CONTEST_HALL_STATE, 1, ContestHall_EventScript_SetContestObjects
# 64 "data/maps/ContestHall/scripts.pory"
	.2byte 0
# 65 "data/maps/ContestHall/scripts.pory"

# 66 "data/maps/ContestHall/scripts.pory"
ContestHall_EventScript_Contest::
# 67 "data/maps/ContestHall/scripts.pory"
	call ContestHall_EventScript_DoContest
# 68 "data/maps/ContestHall/scripts.pory"
	call ContestHall_EventScript_SetExitWarp
# 69 "data/maps/ContestHall/scripts.pory"
	end
# 70 "data/maps/ContestHall/scripts.pory"

# 71 "data/maps/ContestHall/scripts.pory"
ContestHall_EventScript_SetContestObjects::
# 72 "data/maps/ContestHall/scripts.pory"
	special LoadLinkContestPlayerPalettes
# 73 "data/maps/ContestHall/scripts.pory"
	hideobjectat LOCALID_PLAYER, MAP_LITTLEROOT_TOWN
# 74 "data/maps/ContestHall/scripts.pory"
	call ContestHall_EventScript_CreateAudience
# 75 "data/maps/ContestHall/scripts.pory"
	end
# 76 "data/maps/ContestHall/scripts.pory"

# 77 "data/maps/ContestHall/scripts.pory"
@ There are 8 audience member object events, 7 of which are given random gfx below (the 8th is the Artist)
# 78 "data/maps/ContestHall/scripts.pory"
@ The rest of the audience is created statically by ContestHall_EventScript_CreateAudience
# 79 "data/maps/ContestHall/scripts.pory"
ContestHall_EventScript_AddRandomAudienceMembers::
# 80 "data/maps/ContestHall/scripts.pory"
	call ContestHall_EventScript_GetRandomAudienceGfxId
# 81 "data/maps/ContestHall/scripts.pory"
	call ContestHall_EventScript_SetRandomAudienceGfx
# 82 "data/maps/ContestHall/scripts.pory"
	goto_if_lt VAR_TEMP_0, 8, ContestHall_EventScript_AddRandomAudienceMembers
# 83 "data/maps/ContestHall/scripts.pory"
	return
# 84 "data/maps/ContestHall/scripts.pory"

# 85 "data/maps/ContestHall/scripts.pory"
ContestHall_EventScript_SetRandomAudienceGfx::
# 86 "data/maps/ContestHall/scripts.pory"
	switch VAR_TEMP_0
# 87 "data/maps/ContestHall/scripts.pory"
	case 1, ContestHall_EventScript_SetRandomAudience1
# 88 "data/maps/ContestHall/scripts.pory"
	case 2, ContestHall_EventScript_SetRandomAudience2
# 89 "data/maps/ContestHall/scripts.pory"
	case 3, ContestHall_EventScript_SetRandomAudience3
# 90 "data/maps/ContestHall/scripts.pory"
	case 4, ContestHall_EventScript_SetRandomAudience4
# 91 "data/maps/ContestHall/scripts.pory"
	case 5, ContestHall_EventScript_SetRandomAudience5
# 92 "data/maps/ContestHall/scripts.pory"
	case 6, ContestHall_EventScript_SetRandomAudience6
# 93 "data/maps/ContestHall/scripts.pory"
	case 7, ContestHall_EventScript_SetRandomAudience7
# 94 "data/maps/ContestHall/scripts.pory"
	end
# 95 "data/maps/ContestHall/scripts.pory"

# 96 "data/maps/ContestHall/scripts.pory"
ContestHall_EventScript_SetRandomAudience1::
# 97 "data/maps/ContestHall/scripts.pory"
	copyvar VAR_OBJ_GFX_ID_4, VAR_TEMP_1
# 98 "data/maps/ContestHall/scripts.pory"
	addvar VAR_TEMP_0, 1
# 99 "data/maps/ContestHall/scripts.pory"
	return
# 100 "data/maps/ContestHall/scripts.pory"

# 101 "data/maps/ContestHall/scripts.pory"
ContestHall_EventScript_SetRandomAudience2::
# 102 "data/maps/ContestHall/scripts.pory"
	copyvar VAR_OBJ_GFX_ID_5, VAR_TEMP_1
# 103 "data/maps/ContestHall/scripts.pory"
	addvar VAR_TEMP_0, 1
# 104 "data/maps/ContestHall/scripts.pory"
	return
# 105 "data/maps/ContestHall/scripts.pory"

# 106 "data/maps/ContestHall/scripts.pory"
ContestHall_EventScript_SetRandomAudience3::
# 107 "data/maps/ContestHall/scripts.pory"
	copyvar VAR_OBJ_GFX_ID_6, VAR_TEMP_1
# 108 "data/maps/ContestHall/scripts.pory"
	addvar VAR_TEMP_0, 1
# 109 "data/maps/ContestHall/scripts.pory"
	return
# 110 "data/maps/ContestHall/scripts.pory"

# 111 "data/maps/ContestHall/scripts.pory"
ContestHall_EventScript_SetRandomAudience4::
# 112 "data/maps/ContestHall/scripts.pory"
	copyvar VAR_OBJ_GFX_ID_7, VAR_TEMP_1
# 113 "data/maps/ContestHall/scripts.pory"
	addvar VAR_TEMP_0, 1
# 114 "data/maps/ContestHall/scripts.pory"
	return
# 115 "data/maps/ContestHall/scripts.pory"

# 116 "data/maps/ContestHall/scripts.pory"
ContestHall_EventScript_SetRandomAudience5::
# 117 "data/maps/ContestHall/scripts.pory"
	copyvar VAR_OBJ_GFX_ID_8, VAR_TEMP_1
# 118 "data/maps/ContestHall/scripts.pory"
	addvar VAR_TEMP_0, 1
# 119 "data/maps/ContestHall/scripts.pory"
	return
# 120 "data/maps/ContestHall/scripts.pory"

# 121 "data/maps/ContestHall/scripts.pory"
ContestHall_EventScript_SetRandomAudience6::
# 122 "data/maps/ContestHall/scripts.pory"
	copyvar VAR_OBJ_GFX_ID_9, VAR_TEMP_1
# 123 "data/maps/ContestHall/scripts.pory"
	addvar VAR_TEMP_0, 1
# 124 "data/maps/ContestHall/scripts.pory"
	return
# 125 "data/maps/ContestHall/scripts.pory"

# 126 "data/maps/ContestHall/scripts.pory"
ContestHall_EventScript_SetRandomAudience7::
# 127 "data/maps/ContestHall/scripts.pory"
	copyvar VAR_OBJ_GFX_ID_A, VAR_TEMP_1
# 128 "data/maps/ContestHall/scripts.pory"
	addvar VAR_TEMP_0, 1
# 129 "data/maps/ContestHall/scripts.pory"
	return
# 130 "data/maps/ContestHall/scripts.pory"

# 131 "data/maps/ContestHall/scripts.pory"
ContestHall_EventScript_GetRandomAudienceGfxId::
# 132 "data/maps/ContestHall/scripts.pory"
	setvar VAR_RESULT, 32
# 133 "data/maps/ContestHall/scripts.pory"
	special GenerateContestRand
# 134 "data/maps/ContestHall/scripts.pory"
	addvar VAR_RESULT, 1
# 135 "data/maps/ContestHall/scripts.pory"
	switch VAR_RESULT
# 136 "data/maps/ContestHall/scripts.pory"
	case 1, ContestHall_EventScript_RandomAudienceNinjaBoy
# 137 "data/maps/ContestHall/scripts.pory"
	case 2, ContestHall_EventScript_RandomAudienceTwin
# 138 "data/maps/ContestHall/scripts.pory"
	case 3, ContestHall_EventScript_RandomAudienceBoy1
# 139 "data/maps/ContestHall/scripts.pory"
	case 4, ContestHall_EventScript_RandomAudienceGirl1
# 140 "data/maps/ContestHall/scripts.pory"
	case 5, ContestHall_EventScript_RandomAudienceGirl2
# 141 "data/maps/ContestHall/scripts.pory"
	case 6, ContestHall_EventScript_RandomAudienceLittleBoy
# 142 "data/maps/ContestHall/scripts.pory"
	case 7, ContestHall_EventScript_RandomAudienceGirl
# 143 "data/maps/ContestHall/scripts.pory"
	case 8, ContestHall_EventScript_RandomAudienceBoy3
# 144 "data/maps/ContestHall/scripts.pory"
	case 9, ContestHall_EventScript_RandomAudienceGirl3
# 145 "data/maps/ContestHall/scripts.pory"
	case 10, ContestHall_EventScript_RandomAudienceRichBoy
# 146 "data/maps/ContestHall/scripts.pory"
	case 11, ContestHall_EventScript_RandomAudienceFatMan
# 147 "data/maps/ContestHall/scripts.pory"
	case 12, ContestHall_EventScript_RandomAudiencePokefanF
# 148 "data/maps/ContestHall/scripts.pory"
	case 13, ContestHall_EventScript_RandomAudienceMan1
# 149 "data/maps/ContestHall/scripts.pory"
	case 14, ContestHall_EventScript_RandomAudienceWoman2
# 150 "data/maps/ContestHall/scripts.pory"
	case 15, ContestHall_EventScript_RandomAudienceExpertM
# 151 "data/maps/ContestHall/scripts.pory"
	case 16, ContestHall_EventScript_RandomAudienceExpertF
# 152 "data/maps/ContestHall/scripts.pory"
	case 17, ContestHall_EventScript_RandomAudiencePokefanM
# 153 "data/maps/ContestHall/scripts.pory"
	case 18, ContestHall_EventScript_RandomAudienceWoman4
# 154 "data/maps/ContestHall/scripts.pory"
	case 19, ContestHall_EventScript_RandomAudienceCook
# 155 "data/maps/ContestHall/scripts.pory"
	case 20, ContestHall_EventScript_RandomAudienceLass
# 156 "data/maps/ContestHall/scripts.pory"
	case 21, ContestHall_EventScript_RandomAudienceOldWoman
# 157 "data/maps/ContestHall/scripts.pory"
	case 22, ContestHall_EventScript_RandomAudienceCamper
# 158 "data/maps/ContestHall/scripts.pory"
	case 23, ContestHall_EventScript_RandomAudiencePicnicker
# 159 "data/maps/ContestHall/scripts.pory"
	case 24, ContestHall_EventScript_RandomAudienceMan3
# 160 "data/maps/ContestHall/scripts.pory"
	case 25, ContestHall_EventScript_RandomAudienceWoman5
# 161 "data/maps/ContestHall/scripts.pory"
	case 26, ContestHall_EventScript_RandomAudienceYoungster
# 162 "data/maps/ContestHall/scripts.pory"
	case 27, ContestHall_EventScript_RandomAudienceBugCatcher
# 163 "data/maps/ContestHall/scripts.pory"
	case 28, ContestHall_EventScript_RandomAudiencePsychicM
# 164 "data/maps/ContestHall/scripts.pory"
	case 29, ContestHall_EventScript_RandomAudienceSchoolKidM
# 165 "data/maps/ContestHall/scripts.pory"
	case 30, ContestHall_EventScript_RandomAudienceBlackBelt
# 166 "data/maps/ContestHall/scripts.pory"
	case 31, ContestHall_EventScript_RandomAudienceBeauty
# 167 "data/maps/ContestHall/scripts.pory"
	case 32, ContestHall_EventScript_RandomAudienceScientist1
# 168 "data/maps/ContestHall/scripts.pory"
	end
# 169 "data/maps/ContestHall/scripts.pory"

# 170 "data/maps/ContestHall/scripts.pory"
ContestHall_EventScript_RandomAudienceNinjaBoy::
# 171 "data/maps/ContestHall/scripts.pory"
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_NINJA_BOY
# 172 "data/maps/ContestHall/scripts.pory"
	return
# 173 "data/maps/ContestHall/scripts.pory"

# 174 "data/maps/ContestHall/scripts.pory"
ContestHall_EventScript_RandomAudienceTwin::
# 175 "data/maps/ContestHall/scripts.pory"
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_TWIN
# 176 "data/maps/ContestHall/scripts.pory"
	return
# 177 "data/maps/ContestHall/scripts.pory"

# 178 "data/maps/ContestHall/scripts.pory"
ContestHall_EventScript_RandomAudienceBoy1::
# 179 "data/maps/ContestHall/scripts.pory"
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_BOY_1
# 180 "data/maps/ContestHall/scripts.pory"
	return
# 181 "data/maps/ContestHall/scripts.pory"

# 182 "data/maps/ContestHall/scripts.pory"
ContestHall_EventScript_RandomAudienceGirl1::
# 183 "data/maps/ContestHall/scripts.pory"
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_GIRL_1
# 184 "data/maps/ContestHall/scripts.pory"
	return
# 185 "data/maps/ContestHall/scripts.pory"

# 186 "data/maps/ContestHall/scripts.pory"
ContestHall_EventScript_RandomAudienceGirl2::
# 187 "data/maps/ContestHall/scripts.pory"
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_GIRL_2
# 188 "data/maps/ContestHall/scripts.pory"
	return
# 189 "data/maps/ContestHall/scripts.pory"

# 190 "data/maps/ContestHall/scripts.pory"
ContestHall_EventScript_RandomAudienceLittleBoy::
# 191 "data/maps/ContestHall/scripts.pory"
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_LITTLE_BOY
# 192 "data/maps/ContestHall/scripts.pory"
	return
# 193 "data/maps/ContestHall/scripts.pory"

# 194 "data/maps/ContestHall/scripts.pory"
ContestHall_EventScript_RandomAudienceGirl::
# 195 "data/maps/ContestHall/scripts.pory"
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_LITTLE_GIRL
# 196 "data/maps/ContestHall/scripts.pory"
	return
# 197 "data/maps/ContestHall/scripts.pory"

# 198 "data/maps/ContestHall/scripts.pory"
ContestHall_EventScript_RandomAudienceBoy3::
# 199 "data/maps/ContestHall/scripts.pory"
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_BOY_3
# 200 "data/maps/ContestHall/scripts.pory"
	return
# 201 "data/maps/ContestHall/scripts.pory"

# 202 "data/maps/ContestHall/scripts.pory"
ContestHall_EventScript_RandomAudienceGirl3::
# 203 "data/maps/ContestHall/scripts.pory"
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_GIRL_3
# 204 "data/maps/ContestHall/scripts.pory"
	return
# 205 "data/maps/ContestHall/scripts.pory"

# 206 "data/maps/ContestHall/scripts.pory"
ContestHall_EventScript_RandomAudienceRichBoy::
# 207 "data/maps/ContestHall/scripts.pory"
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_RICH_BOY
# 208 "data/maps/ContestHall/scripts.pory"
	return
# 209 "data/maps/ContestHall/scripts.pory"

# 210 "data/maps/ContestHall/scripts.pory"
ContestHall_EventScript_RandomAudienceFatMan::
# 211 "data/maps/ContestHall/scripts.pory"
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_FAT_MAN
# 212 "data/maps/ContestHall/scripts.pory"
	return
# 213 "data/maps/ContestHall/scripts.pory"

# 214 "data/maps/ContestHall/scripts.pory"
ContestHall_EventScript_RandomAudiencePokefanF::
# 215 "data/maps/ContestHall/scripts.pory"
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_POKEFAN_F
# 216 "data/maps/ContestHall/scripts.pory"
	return
# 217 "data/maps/ContestHall/scripts.pory"

# 218 "data/maps/ContestHall/scripts.pory"
ContestHall_EventScript_RandomAudienceMan1::
# 219 "data/maps/ContestHall/scripts.pory"
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_MAN_1
# 220 "data/maps/ContestHall/scripts.pory"
	return
# 221 "data/maps/ContestHall/scripts.pory"

# 222 "data/maps/ContestHall/scripts.pory"
ContestHall_EventScript_RandomAudienceWoman2::
# 223 "data/maps/ContestHall/scripts.pory"
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_WOMAN_2
# 224 "data/maps/ContestHall/scripts.pory"
	return
# 225 "data/maps/ContestHall/scripts.pory"

# 226 "data/maps/ContestHall/scripts.pory"
ContestHall_EventScript_RandomAudienceExpertM::
# 227 "data/maps/ContestHall/scripts.pory"
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_EXPERT_M
# 228 "data/maps/ContestHall/scripts.pory"
	return
# 229 "data/maps/ContestHall/scripts.pory"

# 230 "data/maps/ContestHall/scripts.pory"
ContestHall_EventScript_RandomAudienceExpertF::
# 231 "data/maps/ContestHall/scripts.pory"
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_EXPERT_F
# 232 "data/maps/ContestHall/scripts.pory"
	return
# 233 "data/maps/ContestHall/scripts.pory"

# 234 "data/maps/ContestHall/scripts.pory"
ContestHall_EventScript_RandomAudiencePokefanM::
# 235 "data/maps/ContestHall/scripts.pory"
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_POKEFAN_M
# 236 "data/maps/ContestHall/scripts.pory"
	return
# 237 "data/maps/ContestHall/scripts.pory"

# 238 "data/maps/ContestHall/scripts.pory"
ContestHall_EventScript_RandomAudienceWoman4::
# 239 "data/maps/ContestHall/scripts.pory"
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_WOMAN_4
# 240 "data/maps/ContestHall/scripts.pory"
	return
# 241 "data/maps/ContestHall/scripts.pory"

# 242 "data/maps/ContestHall/scripts.pory"
ContestHall_EventScript_RandomAudienceCook::
# 243 "data/maps/ContestHall/scripts.pory"
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_COOK
# 244 "data/maps/ContestHall/scripts.pory"
	return
# 245 "data/maps/ContestHall/scripts.pory"

# 246 "data/maps/ContestHall/scripts.pory"
ContestHall_EventScript_RandomAudienceLass::
# 247 "data/maps/ContestHall/scripts.pory"
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_LASS
# 248 "data/maps/ContestHall/scripts.pory"
	return
# 249 "data/maps/ContestHall/scripts.pory"

# 250 "data/maps/ContestHall/scripts.pory"
ContestHall_EventScript_RandomAudienceOldWoman::
# 251 "data/maps/ContestHall/scripts.pory"
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_OLD_WOMAN
# 252 "data/maps/ContestHall/scripts.pory"
	return
# 253 "data/maps/ContestHall/scripts.pory"

# 254 "data/maps/ContestHall/scripts.pory"
ContestHall_EventScript_RandomAudienceCamper::
# 255 "data/maps/ContestHall/scripts.pory"
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_CAMPER
# 256 "data/maps/ContestHall/scripts.pory"
	return
# 257 "data/maps/ContestHall/scripts.pory"

# 258 "data/maps/ContestHall/scripts.pory"
ContestHall_EventScript_RandomAudiencePicnicker::
# 259 "data/maps/ContestHall/scripts.pory"
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_PICNICKER
# 260 "data/maps/ContestHall/scripts.pory"
	return
# 261 "data/maps/ContestHall/scripts.pory"

# 262 "data/maps/ContestHall/scripts.pory"
ContestHall_EventScript_RandomAudienceMan3::
# 263 "data/maps/ContestHall/scripts.pory"
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_MAN_3
# 264 "data/maps/ContestHall/scripts.pory"
	return
# 265 "data/maps/ContestHall/scripts.pory"

# 266 "data/maps/ContestHall/scripts.pory"
ContestHall_EventScript_RandomAudienceWoman5::
# 267 "data/maps/ContestHall/scripts.pory"
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_WOMAN_5
# 268 "data/maps/ContestHall/scripts.pory"
	return
# 269 "data/maps/ContestHall/scripts.pory"

# 270 "data/maps/ContestHall/scripts.pory"
ContestHall_EventScript_RandomAudienceYoungster::
# 271 "data/maps/ContestHall/scripts.pory"
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_YOUNGSTER
# 272 "data/maps/ContestHall/scripts.pory"
	return
# 273 "data/maps/ContestHall/scripts.pory"

# 274 "data/maps/ContestHall/scripts.pory"
ContestHall_EventScript_RandomAudienceBugCatcher::
# 275 "data/maps/ContestHall/scripts.pory"
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_BUG_CATCHER
# 276 "data/maps/ContestHall/scripts.pory"
	return
# 277 "data/maps/ContestHall/scripts.pory"

# 278 "data/maps/ContestHall/scripts.pory"
ContestHall_EventScript_RandomAudiencePsychicM::
# 279 "data/maps/ContestHall/scripts.pory"
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_PSYCHIC_M
# 280 "data/maps/ContestHall/scripts.pory"
	return
# 281 "data/maps/ContestHall/scripts.pory"

# 282 "data/maps/ContestHall/scripts.pory"
ContestHall_EventScript_RandomAudienceSchoolKidM::
# 283 "data/maps/ContestHall/scripts.pory"
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_SCHOOL_KID_M
# 284 "data/maps/ContestHall/scripts.pory"
	return
# 285 "data/maps/ContestHall/scripts.pory"

# 286 "data/maps/ContestHall/scripts.pory"
ContestHall_EventScript_RandomAudienceBlackBelt::
# 287 "data/maps/ContestHall/scripts.pory"
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_BLACK_BELT
# 288 "data/maps/ContestHall/scripts.pory"
	return
# 289 "data/maps/ContestHall/scripts.pory"

# 290 "data/maps/ContestHall/scripts.pory"
ContestHall_EventScript_RandomAudienceBeauty::
# 291 "data/maps/ContestHall/scripts.pory"
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_BEAUTY
# 292 "data/maps/ContestHall/scripts.pory"
	return
# 293 "data/maps/ContestHall/scripts.pory"

# 294 "data/maps/ContestHall/scripts.pory"
ContestHall_EventScript_RandomAudienceScientist1::
# 295 "data/maps/ContestHall/scripts.pory"
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_SCIENTIST_1
# 296 "data/maps/ContestHall/scripts.pory"
	return
# 297 "data/maps/ContestHall/scripts.pory"

# 298 "data/maps/ContestHall/scripts.pory"
ContestHall_EventScript_CreateAudience::
# 299 "data/maps/ContestHall/scripts.pory"
	specialvar VAR_RESULT, IsWirelessContest
# 300 "data/maps/ContestHall/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, ContestHall_EventScript_CreateWirelessContestAudience
# 301 "data/maps/ContestHall/scripts.pory"
	switch VAR_CONTEST_TYPE
# 302 "data/maps/ContestHall/scripts.pory"
	case CONTEST_TYPE_NPC_NORMAL, ContestHall_EventScript_CreateNormalContestAudience
# 303 "data/maps/ContestHall/scripts.pory"
	case CONTEST_TYPE_NPC_SUPER, ContestHall_EventScript_CreateSuperContestAudience
# 304 "data/maps/ContestHall/scripts.pory"
	case CONTEST_TYPE_NPC_HYPER, ContestHall_EventScript_CreateHyperContestAudience
# 305 "data/maps/ContestHall/scripts.pory"
	case CONTEST_TYPE_NPC_MASTER, ContestHall_EventScript_CreateMasterContestAudience
# 306 "data/maps/ContestHall/scripts.pory"
	case CONTEST_TYPE_LINK, ContestHall_EventScript_CreateMasterContestAudience
# 307 "data/maps/ContestHall/scripts.pory"
	return
# 308 "data/maps/ContestHall/scripts.pory"

# 309 "data/maps/ContestHall/scripts.pory"
ContestHall_EventScript_CreateNormalContestAudience::
# 310 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_NINJA_BOY, 20, 3, 2, 3, DIR_SOUTH
# 311 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_SCIENTIST_1, 24, 11, 2, 3, DIR_SOUTH
# 312 "data/maps/ContestHall/scripts.pory"
	return
# 313 "data/maps/ContestHall/scripts.pory"

# 314 "data/maps/ContestHall/scripts.pory"
ContestHall_EventScript_CreateSuperContestAudience::
# 315 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_BEAUTY, 0, 2, 3, 3, DIR_EAST
# 316 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_MAN_5, 1, 2, 4, 3, DIR_EAST
# 317 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_HIKER, 2, 2, 7, 3, DIR_EAST
# 318 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_SCIENTIST_1, 3, 2, 8, 3, DIR_EAST
# 319 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_NINJA_BOY, 10, 12, 3, 3, DIR_WEST
# 320 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_WOMAN_2, 11, 12, 4, 3, DIR_WEST
# 321 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_WOMAN_3, 12, 12, 7, 3, DIR_WEST
# 322 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_LITTLE_GIRL, 13, 12, 8, 3, DIR_WEST
# 323 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_LASS, 20, 3, 2, 3, DIR_SOUTH
# 324 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_SCIENTIST_1, 24, 11, 2, 3, DIR_SOUTH
# 325 "data/maps/ContestHall/scripts.pory"
	return
# 326 "data/maps/ContestHall/scripts.pory"

# 327 "data/maps/ContestHall/scripts.pory"
ContestHall_EventScript_CreateHyperContestAudience::
# 328 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_BEAUTY, 0, 2, 3, 3, DIR_EAST
# 329 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_MAN_5, 1, 2, 4, 3, DIR_EAST
# 330 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_HIKER, 2, 2, 7, 3, DIR_EAST
# 331 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_GENTLEMAN, 3, 2, 8, 3, DIR_EAST
# 332 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_NINJA_BOY, 10, 12, 3, 3, DIR_WEST
# 333 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_WOMAN_2, 11, 12, 4, 3, DIR_WEST
# 334 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_WOMAN_3, 12, 12, 7, 3, DIR_WEST
# 335 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_BEAUTY, 13, 12, 8, 3, DIR_WEST
# 336 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_EXPERT_F, 20, 3, 2, 3, DIR_SOUTH
# 337 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_MAN_2, 20, 6, 2, 3, DIR_SOUTH
# 338 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_WOMAN_5, 20, 7, 2, 3, DIR_SOUTH
# 339 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_SCIENTIST_1, 24, 8, 2, 3, DIR_SOUTH
# 340 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_GENTLEMAN, 24, 11, 2, 3, DIR_SOUTH
# 341 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_LITTLE_BOY, 25, 3, 9, 3, DIR_NORTH
# 342 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_YOUNGSTER, 26, 4, 9, 3, DIR_NORTH
# 343 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_FAT_MAN, 27, 5, 9, 3, DIR_NORTH
# 344 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_HEX_MANIAC, 28, 9, 9, 3, DIR_NORTH
# 345 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_SCHOOL_KID_M, 29, 10, 9, 3, DIR_NORTH
# 346 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_MART_EMPLOYEE, 30, 11, 9, 3, DIR_NORTH
# 347 "data/maps/ContestHall/scripts.pory"
	return
# 348 "data/maps/ContestHall/scripts.pory"

# 349 "data/maps/ContestHall/scripts.pory"
ContestHall_EventScript_CreateMasterContestAudience::
# 350 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_BEAUTY, 0, 2, 3, 3, DIR_EAST
# 351 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_MAN_5, 1, 2, 4, 3, DIR_EAST
# 352 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_HIKER, 2, 2, 7, 3, DIR_EAST
# 353 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_LITTLE_GIRL, 3, 2, 8, 3, DIR_EAST
# 354 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_MANIAC, 4, 1, 3, 3, DIR_EAST
# 355 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_WOMAN_5, 6, 1, 5, 3, DIR_EAST
# 356 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_WOMAN_4, 7, 1, 6, 3, DIR_EAST
# 357 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_GENTLEMAN, 9, 1, 8, 3, DIR_EAST
# 358 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_NINJA_BOY, 10, 12, 3, 3, DIR_WEST
# 359 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_WOMAN_2, 11, 12, 4, 3, DIR_WEST
# 360 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_WOMAN_3, 12, 12, 7, 3, DIR_WEST
# 361 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_BEAUTY, 13, 12, 8, 3, DIR_WEST
# 362 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_FISHERMAN, 14, 13, 3, 3, DIR_WEST
# 363 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_RUNNING_TRIATHLETE_F, 15, 13, 4, 3, DIR_WEST
# 364 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_MAN_4, 17, 13, 6, 3, DIR_WEST
# 365 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_MART_EMPLOYEE, 18, 13, 7, 3, DIR_WEST
# 366 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_DEVON_EMPLOYEE, 19, 13, 8, 3, DIR_WEST
# 367 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_POKEFAN_M, 20, 3, 2, 3, DIR_SOUTH
# 368 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_CAMPER, 21, 6, 2, 3, DIR_SOUTH
# 369 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_MAN_3, 22, 7, 2, 3, DIR_SOUTH
# 370 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_SCIENTIST_1, 24, 11, 2, 3, DIR_SOUTH
# 371 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_SAILOR, 25, 3, 9, 3, DIR_NORTH
# 372 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_YOUNGSTER, 26, 4, 9, 3, DIR_NORTH
# 373 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_GENTLEMAN, 27, 5, 9, 3, DIR_NORTH
# 374 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_HEX_MANIAC, 28, 9, 9, 3, DIR_NORTH
# 375 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_SCHOOL_KID_M, 29, 10, 9, 3, DIR_NORTH
# 376 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_MART_EMPLOYEE, 30, 11, 9, 3, DIR_NORTH
# 377 "data/maps/ContestHall/scripts.pory"
	return
# 378 "data/maps/ContestHall/scripts.pory"

# 379 "data/maps/ContestHall/scripts.pory"
ContestHall_EventScript_CreateWirelessContestAudience::
# 380 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_BEAUTY, 0, 2, 3, 3, DIR_EAST
# 381 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_MAN_5, 1, 2, 4, 3, DIR_EAST
# 382 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_HIKER, 2, 2, 7, 3, DIR_EAST
# 383 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_LITTLE_GIRL, 3, 2, 8, 3, DIR_EAST
# 384 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_MANIAC, 4, 1, 3, 3, DIR_EAST
# 385 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_WOMAN_5, 6, 1, 5, 3, DIR_EAST
# 386 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_WOMAN_4, 7, 1, 6, 3, DIR_EAST
# 387 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_GENTLEMAN, 9, 1, 8, 3, DIR_EAST
# 388 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_NINJA_BOY, 10, 12, 3, 3, DIR_WEST
# 389 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_WOMAN_2, 11, 12, 4, 3, DIR_WEST
# 390 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_WOMAN_3, 12, 12, 7, 3, DIR_WEST
# 391 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_BEAUTY, 13, 12, 8, 3, DIR_WEST
# 392 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_FISHERMAN, 14, 13, 3, 3, DIR_WEST
# 393 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_RUNNING_TRIATHLETE_F, 15, 13, 4, 3, DIR_WEST
# 394 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_MAN_4, 17, 13, 6, 3, DIR_WEST
# 395 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_MART_EMPLOYEE, 18, 13, 7, 3, DIR_WEST
# 396 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_DEVON_EMPLOYEE, 19, 13, 8, 3, DIR_WEST
# 397 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_POKEFAN_M, 20, 3, 2, 3, DIR_SOUTH
# 398 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_CAMPER, 21, 6, 2, 3, DIR_SOUTH
# 399 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_MAN_3, 22, 7, 2, 3, DIR_SOUTH
# 400 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_SCIENTIST_1, 24, 11, 2, 3, DIR_SOUTH
# 401 "data/maps/ContestHall/scripts.pory"
	return
# 402 "data/maps/ContestHall/scripts.pory"

# 403 "data/maps/ContestHall/scripts.pory"
ContestHall_EventScript_SetExitWarp::
# 404 "data/maps/ContestHall/scripts.pory"
	special ClearLinkContestFlags
# 405 "data/maps/ContestHall/scripts.pory"
	switch VAR_CONTEST_TYPE
# 406 "data/maps/ContestHall/scripts.pory"
	case CONTEST_TYPE_NPC_NORMAL, ContestHall_EventScript_SetExitWarpNormalContest
# 407 "data/maps/ContestHall/scripts.pory"
	case CONTEST_TYPE_NPC_SUPER, ContestHall_EventScript_SetExitWarpSuperContest
# 408 "data/maps/ContestHall/scripts.pory"
	case CONTEST_TYPE_NPC_HYPER, ContestHall_EventScript_SetExitWarpHyperContest
# 409 "data/maps/ContestHall/scripts.pory"
	case CONTEST_TYPE_NPC_MASTER, ContestHall_EventScript_SetExitWarpMasterContest
# 410 "data/maps/ContestHall/scripts.pory"
	case CONTEST_TYPE_LINK, ContestHall_EventScript_SetExitWarpLinkContest
# 411 "data/maps/ContestHall/scripts.pory"
	return
# 412 "data/maps/ContestHall/scripts.pory"

# 413 "data/maps/ContestHall/scripts.pory"
ContestHall_EventScript_SetExitWarpNormalContest::
# 414 "data/maps/ContestHall/scripts.pory"
	warp MAP_LILYCOVE_CITY_CONTEST_LOBBY, 14, 4
# 415 "data/maps/ContestHall/scripts.pory"
	waitstate
# 416 "data/maps/ContestHall/scripts.pory"
	end
# 417 "data/maps/ContestHall/scripts.pory"

# 418 "data/maps/ContestHall/scripts.pory"
ContestHall_EventScript_SetExitWarpSuperContest::
# 419 "data/maps/ContestHall/scripts.pory"
	warp MAP_LILYCOVE_CITY_CONTEST_LOBBY, 14, 4
# 420 "data/maps/ContestHall/scripts.pory"
	waitstate
# 421 "data/maps/ContestHall/scripts.pory"
	end
# 422 "data/maps/ContestHall/scripts.pory"

# 423 "data/maps/ContestHall/scripts.pory"
ContestHall_EventScript_SetExitWarpHyperContest::
# 424 "data/maps/ContestHall/scripts.pory"
	warp MAP_LILYCOVE_CITY_CONTEST_LOBBY, 14, 4
# 425 "data/maps/ContestHall/scripts.pory"
	waitstate
# 426 "data/maps/ContestHall/scripts.pory"
	end
# 427 "data/maps/ContestHall/scripts.pory"

# 428 "data/maps/ContestHall/scripts.pory"
ContestHall_EventScript_SetExitWarpMasterContest::
# 429 "data/maps/ContestHall/scripts.pory"
	warp MAP_LILYCOVE_CITY_CONTEST_LOBBY, 14, 4
# 430 "data/maps/ContestHall/scripts.pory"
	waitstate
# 431 "data/maps/ContestHall/scripts.pory"
	end
# 432 "data/maps/ContestHall/scripts.pory"

# 433 "data/maps/ContestHall/scripts.pory"
ContestHall_EventScript_SetExitWarpLinkContest::
# 434 "data/maps/ContestHall/scripts.pory"
	warp MAP_LILYCOVE_CITY_CONTEST_LOBBY, 15, 4
# 435 "data/maps/ContestHall/scripts.pory"
	waitstate
# 436 "data/maps/ContestHall/scripts.pory"
	end
# 437 "data/maps/ContestHall/scripts.pory"

# 438 "data/maps/ContestHall/scripts.pory"
LilycoveCity_ContestLobby_EventScript_SetPlayerGfx::
# 439 "data/maps/ContestHall/scripts.pory"
	checkplayergender
# 440 "data/maps/ContestHall/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, LilycoveCity_ContestLobby_EventScript_SetPlayerGfxBrendan
# 441 "data/maps/ContestHall/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, LilycoveCity_ContestLobby_EventScript_SetPlayerGfxMay
# 442 "data/maps/ContestHall/scripts.pory"
	return
# 443 "data/maps/ContestHall/scripts.pory"

# 444 "data/maps/ContestHall/scripts.pory"
LilycoveCity_ContestLobby_EventScript_SetPlayerGfxBrendan::
# 445 "data/maps/ContestHall/scripts.pory"
	setvar VAR_OBJ_GFX_ID_3, OBJ_EVENT_GFX_RIVAL_BRENDAN_NORMAL
# 446 "data/maps/ContestHall/scripts.pory"
	return
# 447 "data/maps/ContestHall/scripts.pory"

# 448 "data/maps/ContestHall/scripts.pory"
LilycoveCity_ContestLobby_EventScript_SetPlayerGfxMay::
# 449 "data/maps/ContestHall/scripts.pory"
	setvar VAR_OBJ_GFX_ID_3, OBJ_EVENT_GFX_RIVAL_MAY_NORMAL
# 450 "data/maps/ContestHall/scripts.pory"
	return
