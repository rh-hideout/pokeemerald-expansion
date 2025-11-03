# 1 "data/maps/JaggedPass/scripts.pory"

# 2 "data/maps/JaggedPass/scripts.pory"
JaggedPass_MapScripts::
# 3 "data/maps/JaggedPass/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, JaggedPass_OnResume
# 4 "data/maps/JaggedPass/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, JaggedPass_OnTransition
# 5 "data/maps/JaggedPass/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, JaggedPass_OnLoad
# 6 "data/maps/JaggedPass/scripts.pory"
	.byte 0
# 7 "data/maps/JaggedPass/scripts.pory"

# 8 "data/maps/JaggedPass/scripts.pory"
JaggedPass_OnResume:
# 9 "data/maps/JaggedPass/scripts.pory"
	setstepcallback STEP_CB_ASH
# 10 "data/maps/JaggedPass/scripts.pory"
	call_if_eq VAR_JAGGED_PASS_STATE, 0, JaggedPass_EventScript_CheckHasMagmaEmblem
# 11 "data/maps/JaggedPass/scripts.pory"
	end
# 12 "data/maps/JaggedPass/scripts.pory"

# 13 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_CheckHasMagmaEmblem::
# 14 "data/maps/JaggedPass/scripts.pory"
	checkitem ITEM_MAGMA_EMBLEM
# 15 "data/maps/JaggedPass/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, JaggedPass_EventScript_SetReadyToOpenHideout
# 16 "data/maps/JaggedPass/scripts.pory"
	return
# 17 "data/maps/JaggedPass/scripts.pory"

# 18 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_SetReadyToOpenHideout::
# 19 "data/maps/JaggedPass/scripts.pory"
	setvar VAR_JAGGED_PASS_STATE, 1
# 20 "data/maps/JaggedPass/scripts.pory"
	return
# 21 "data/maps/JaggedPass/scripts.pory"

# 22 "data/maps/JaggedPass/scripts.pory"
JaggedPass_OnTransition:
# 23 "data/maps/JaggedPass/scripts.pory"
	call_if_eq VAR_JAGGED_PASS_ASH_WEATHER, 1, JaggedPass_EventScript_SetWeatherAsh
# 24 "data/maps/JaggedPass/scripts.pory"
	end
# 25 "data/maps/JaggedPass/scripts.pory"

# 26 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_SetWeatherAsh::
# 27 "data/maps/JaggedPass/scripts.pory"
	setweather WEATHER_VOLCANIC_ASH
# 28 "data/maps/JaggedPass/scripts.pory"
	doweather
# 29 "data/maps/JaggedPass/scripts.pory"
	return
# 30 "data/maps/JaggedPass/scripts.pory"

# 31 "data/maps/JaggedPass/scripts.pory"
JaggedPass_OnLoad:
# 32 "data/maps/JaggedPass/scripts.pory"
	goto_if_le VAR_JAGGED_PASS_STATE, 1, JaggedPass_EventScript_ConcealHideoutEntrance
# 33 "data/maps/JaggedPass/scripts.pory"
	end
# 34 "data/maps/JaggedPass/scripts.pory"

# 35 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_ConcealHideoutEntrance::
# 36 "data/maps/JaggedPass/scripts.pory"
	setmetatile 16, 17, METATILE_Lavaridge_RockWall, TRUE
# 37 "data/maps/JaggedPass/scripts.pory"
	setmetatile 16, 18, METATILE_Lavaridge_RockWall, TRUE
# 38 "data/maps/JaggedPass/scripts.pory"
	end
# 39 "data/maps/JaggedPass/scripts.pory"

# 40 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_OpenMagmaHideout::
# 41 "data/maps/JaggedPass/scripts.pory"
	lockall
# 42 "data/maps/JaggedPass/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 43 "data/maps/JaggedPass/scripts.pory"
	setvar VAR_0x8005, 1  @ horizontal pan
# 44 "data/maps/JaggedPass/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 45 "data/maps/JaggedPass/scripts.pory"
	setvar VAR_0x8007, 5  @ shake delay
# 46 "data/maps/JaggedPass/scripts.pory"
	special ShakeCamera
# 47 "data/maps/JaggedPass/scripts.pory"
	waitstate
# 48 "data/maps/JaggedPass/scripts.pory"
	msgbox JaggedPass_Text_BoulderShakingInResponseToEmblem, MSGBOX_DEFAULT
# 49 "data/maps/JaggedPass/scripts.pory"
	closemessage
# 50 "data/maps/JaggedPass/scripts.pory"
	setvar VAR_0x8004, 1   @ vertical pan
# 51 "data/maps/JaggedPass/scripts.pory"
	setvar VAR_0x8005, 1   @ horizontal pan
# 52 "data/maps/JaggedPass/scripts.pory"
	setvar VAR_0x8006, 16  @ num shakes
# 53 "data/maps/JaggedPass/scripts.pory"
	setvar VAR_0x8007, 3   @ shake delay
# 54 "data/maps/JaggedPass/scripts.pory"
	special ShakeCamera
# 55 "data/maps/JaggedPass/scripts.pory"
	waitstate
# 56 "data/maps/JaggedPass/scripts.pory"
	playse SE_EFFECTIVE
# 57 "data/maps/JaggedPass/scripts.pory"
	setmetatile 16, 17, METATILE_Lavaridge_CaveEntrance_Top, TRUE
# 58 "data/maps/JaggedPass/scripts.pory"
	setmetatile 16, 18, METATILE_Lavaridge_CaveEntrance_Bottom, FALSE
# 59 "data/maps/JaggedPass/scripts.pory"
	special DrawWholeMapView
# 60 "data/maps/JaggedPass/scripts.pory"
	delay 30
# 61 "data/maps/JaggedPass/scripts.pory"
	setvar VAR_JAGGED_PASS_STATE, 2
# 62 "data/maps/JaggedPass/scripts.pory"
	waitse
# 63 "data/maps/JaggedPass/scripts.pory"
	releaseall
# 64 "data/maps/JaggedPass/scripts.pory"
	end
# 65 "data/maps/JaggedPass/scripts.pory"

# 66 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_MagmaHideoutGuard::
# 67 "data/maps/JaggedPass/scripts.pory"
	lockall
# 68 "data/maps/JaggedPass/scripts.pory"
	goto_if_set FLAG_BEAT_MAGMA_GRUNT_JAGGED_PASS, JaggedPass_EventScript_GuardDefeated
# 69 "data/maps/JaggedPass/scripts.pory"
	waitse
# 70 "data/maps/JaggedPass/scripts.pory"
	playse SE_PIN
# 71 "data/maps/JaggedPass/scripts.pory"
	applymovement LOCALID_MAGMA_HIDEOUT_GUARD, Common_Movement_ExclamationMark
# 72 "data/maps/JaggedPass/scripts.pory"
	waitmovement 0
# 73 "data/maps/JaggedPass/scripts.pory"
	applymovement LOCALID_MAGMA_HIDEOUT_GUARD, Common_Movement_Delay48
# 74 "data/maps/JaggedPass/scripts.pory"
	waitmovement 0
# 75 "data/maps/JaggedPass/scripts.pory"
	applymovement LOCALID_MAGMA_HIDEOUT_GUARD, Common_Movement_FacePlayer
# 76 "data/maps/JaggedPass/scripts.pory"
	waitmovement 0
# 77 "data/maps/JaggedPass/scripts.pory"
	msgbox JaggedPass_Text_GruntIntro, MSGBOX_DEFAULT
# 78 "data/maps/JaggedPass/scripts.pory"
	closemessage
# 79 "data/maps/JaggedPass/scripts.pory"
	trainerbattle_no_intro TRAINER_GRUNT_JAGGED_PASS, JaggedPass_Text_GruntDefeat
# 80 "data/maps/JaggedPass/scripts.pory"
	setflag FLAG_BEAT_MAGMA_GRUNT_JAGGED_PASS
# 81 "data/maps/JaggedPass/scripts.pory"
	applymovement LOCALID_MAGMA_HIDEOUT_GUARD, Common_Movement_FaceOriginalDirection
# 82 "data/maps/JaggedPass/scripts.pory"
	waitmovement 0
# 83 "data/maps/JaggedPass/scripts.pory"
	releaseall
# 84 "data/maps/JaggedPass/scripts.pory"
	end
# 85 "data/maps/JaggedPass/scripts.pory"

# 86 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_GuardDefeated::
# 87 "data/maps/JaggedPass/scripts.pory"
	applymovement LOCALID_MAGMA_HIDEOUT_GUARD, Common_Movement_FacePlayer
# 88 "data/maps/JaggedPass/scripts.pory"
	waitmovement 0
# 89 "data/maps/JaggedPass/scripts.pory"
	msgbox JaggedPass_Text_GoWhereverYouWant, MSGBOX_DEFAULT
# 90 "data/maps/JaggedPass/scripts.pory"
	closemessage
# 91 "data/maps/JaggedPass/scripts.pory"
	applymovement LOCALID_MAGMA_HIDEOUT_GUARD, Common_Movement_FaceOriginalDirection
# 92 "data/maps/JaggedPass/scripts.pory"
	waitmovement 0
# 93 "data/maps/JaggedPass/scripts.pory"
	releaseall
# 94 "data/maps/JaggedPass/scripts.pory"
	end
# 95 "data/maps/JaggedPass/scripts.pory"

# 96 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_Eric::
# 97 "data/maps/JaggedPass/scripts.pory"
	trainerbattle_single TRAINER_ERIC, JaggedPass_Text_EricIntro, JaggedPass_Text_EricDefeat
# 98 "data/maps/JaggedPass/scripts.pory"
	msgbox JaggedPass_Text_EricPostBattle, MSGBOX_AUTOCLOSE
# 99 "data/maps/JaggedPass/scripts.pory"
	end
# 100 "data/maps/JaggedPass/scripts.pory"

# 101 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_Diana::
# 102 "data/maps/JaggedPass/scripts.pory"
	trainerbattle_single TRAINER_DIANA_1, JaggedPass_Text_DianaIntro, JaggedPass_Text_DianaDefeat, JaggedPass_EventScript_RegisterDiana
# 103 "data/maps/JaggedPass/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 104 "data/maps/JaggedPass/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, JaggedPass_EventScript_DianaRematch
# 105 "data/maps/JaggedPass/scripts.pory"
	msgbox JaggedPass_Text_DianaPostBattle, MSGBOX_DEFAULT
# 106 "data/maps/JaggedPass/scripts.pory"
	release
# 107 "data/maps/JaggedPass/scripts.pory"
	end
# 108 "data/maps/JaggedPass/scripts.pory"

# 109 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_RegisterDiana::
# 110 "data/maps/JaggedPass/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 111 "data/maps/JaggedPass/scripts.pory"
	msgbox JaggedPass_Text_DianaRegister, MSGBOX_DEFAULT
# 112 "data/maps/JaggedPass/scripts.pory"
	register_matchcall TRAINER_DIANA_1
# 113 "data/maps/JaggedPass/scripts.pory"
	release
# 114 "data/maps/JaggedPass/scripts.pory"
	end
# 115 "data/maps/JaggedPass/scripts.pory"

# 116 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_DianaRematch::
# 117 "data/maps/JaggedPass/scripts.pory"
	trainerbattle_rematch TRAINER_DIANA_1, JaggedPass_Text_DianaRematchIntro, JaggedPass_Text_DianaRematchDefeat
# 118 "data/maps/JaggedPass/scripts.pory"
	msgbox JaggedPass_Text_DianaPostRematch, MSGBOX_AUTOCLOSE
# 119 "data/maps/JaggedPass/scripts.pory"
	end
# 120 "data/maps/JaggedPass/scripts.pory"

# 121 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_Ethan::
# 122 "data/maps/JaggedPass/scripts.pory"
	trainerbattle_single TRAINER_ETHAN_1, JaggedPass_Text_EthanIntro, JaggedPass_Text_EthanDefeat, JaggedPass_EventScript_RegisterEthan
# 123 "data/maps/JaggedPass/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 124 "data/maps/JaggedPass/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, JaggedPass_EventScript_EthanRematch
# 125 "data/maps/JaggedPass/scripts.pory"
	msgbox JaggedPass_Text_EthanPostBattle, MSGBOX_DEFAULT
# 126 "data/maps/JaggedPass/scripts.pory"
	release
# 127 "data/maps/JaggedPass/scripts.pory"
	end
# 128 "data/maps/JaggedPass/scripts.pory"

# 129 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_RegisterEthan::
# 130 "data/maps/JaggedPass/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 131 "data/maps/JaggedPass/scripts.pory"
	msgbox JaggedPass_Text_EthanRegister, MSGBOX_DEFAULT
# 132 "data/maps/JaggedPass/scripts.pory"
	register_matchcall TRAINER_ETHAN_1
# 133 "data/maps/JaggedPass/scripts.pory"
	release
# 134 "data/maps/JaggedPass/scripts.pory"
	end
# 135 "data/maps/JaggedPass/scripts.pory"

# 136 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_EthanRematch::
# 137 "data/maps/JaggedPass/scripts.pory"
	trainerbattle_rematch TRAINER_ETHAN_1, JaggedPass_Text_EthanRematchIntro, JaggedPass_Text_EthanRematchDefeat
# 138 "data/maps/JaggedPass/scripts.pory"
	msgbox JaggedPass_Text_EthanPostRematch, MSGBOX_AUTOCLOSE
# 139 "data/maps/JaggedPass/scripts.pory"
	end
# 140 "data/maps/JaggedPass/scripts.pory"

# 141 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_Julio::
# 142 "data/maps/JaggedPass/scripts.pory"
	trainerbattle_single TRAINER_JULIO, JaggedPass_Text_JulioIntro, JaggedPass_Text_JulioDefeat
# 143 "data/maps/JaggedPass/scripts.pory"
	msgbox JaggedPass_Text_JulioPostBattle, MSGBOX_AUTOCLOSE
# 144 "data/maps/JaggedPass/scripts.pory"
	end
# 145 "data/maps/JaggedPass/scripts.pory"

# 146 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_Autumn::
# 147 "data/maps/JaggedPass/scripts.pory"
	trainerbattle_single TRAINER_AUTUMN, JaggedPass_Text_AutumnIntro, JaggedPass_Text_AutumnDefeat
# 148 "data/maps/JaggedPass/scripts.pory"
	msgbox JaggedPass_Text_AutumnPostBattle, MSGBOX_AUTOCLOSE
# 149 "data/maps/JaggedPass/scripts.pory"
	end
# 150 "data/maps/JaggedPass/scripts.pory"

# 151 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_EricIntro:
# 152 "data/maps/JaggedPass/scripts.pory"
	.string "MT. CHIMNEY's JAGGED PASS…\p"
# 153 "data/maps/JaggedPass/scripts.pory"
	.string "Now this is what I've always wanted\n"
# 154 "data/maps/JaggedPass/scripts.pory"
	.string "in a mountain.\p"
# 155 "data/maps/JaggedPass/scripts.pory"
	.string "This jagged bumpiness…\n"
# 156 "data/maps/JaggedPass/scripts.pory"
	.string "It rocks my soul!$"
# 157 "data/maps/JaggedPass/scripts.pory"

# 158 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_EricDefeat:
# 159 "data/maps/JaggedPass/scripts.pory"
	.string "Losing left me bitter!$"
# 160 "data/maps/JaggedPass/scripts.pory"

# 161 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_EricPostBattle:
# 162 "data/maps/JaggedPass/scripts.pory"
	.string "Yes, I did lose at POKéMON…\p"
# 163 "data/maps/JaggedPass/scripts.pory"
	.string "But, when it comes to the love of\n"
# 164 "data/maps/JaggedPass/scripts.pory"
	.string "the mountains, I have you beat!$"
# 165 "data/maps/JaggedPass/scripts.pory"

# 166 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_DianaIntro:
# 167 "data/maps/JaggedPass/scripts.pory"
	.string "This place isn't your casual hike.\n"
# 168 "data/maps/JaggedPass/scripts.pory"
	.string "It's not suited for a picnic.$"
# 169 "data/maps/JaggedPass/scripts.pory"

# 170 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_DianaDefeat:
# 171 "data/maps/JaggedPass/scripts.pory"
	.string "Ohhh, no!\n"
# 172 "data/maps/JaggedPass/scripts.pory"
	.string "The ground is too bumpy…$"
# 173 "data/maps/JaggedPass/scripts.pory"

# 174 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_DianaPostBattle:
# 175 "data/maps/JaggedPass/scripts.pory"
	.string "Did you know?\p"
# 176 "data/maps/JaggedPass/scripts.pory"
	.string "Some people cleverly ride their\n"
# 177 "data/maps/JaggedPass/scripts.pory"
	.string "bicycles up this horribly bumpy pass.$"
# 178 "data/maps/JaggedPass/scripts.pory"

# 179 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_DianaRegister:
# 180 "data/maps/JaggedPass/scripts.pory"
	.string "Will you ever be back in this area?\n"
# 181 "data/maps/JaggedPass/scripts.pory"
	.string "If you do return, I'd like a rematch.$"
# 182 "data/maps/JaggedPass/scripts.pory"

# 183 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_DianaRematchIntro:
# 184 "data/maps/JaggedPass/scripts.pory"
	.string "Picnics are fun wherever you go.\n"
# 185 "data/maps/JaggedPass/scripts.pory"
	.string "Just like POKéMON!$"
# 186 "data/maps/JaggedPass/scripts.pory"

# 187 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_DianaRematchDefeat:
# 188 "data/maps/JaggedPass/scripts.pory"
	.string "I only lost because the ground is\n"
# 189 "data/maps/JaggedPass/scripts.pory"
	.string "too bumpy!$"
# 190 "data/maps/JaggedPass/scripts.pory"

# 191 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_DianaPostRematch:
# 192 "data/maps/JaggedPass/scripts.pory"
	.string "I'll forget about losing and just\n"
# 193 "data/maps/JaggedPass/scripts.pory"
	.string "enjoy this bumpy hike.$"
# 194 "data/maps/JaggedPass/scripts.pory"

# 195 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_EthanIntro:
# 196 "data/maps/JaggedPass/scripts.pory"
	.string "JAGGED PASS is hard to walk on.\n"
# 197 "data/maps/JaggedPass/scripts.pory"
	.string "It's a good place for training.$"
# 198 "data/maps/JaggedPass/scripts.pory"

# 199 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_EthanDefeat:
# 200 "data/maps/JaggedPass/scripts.pory"
	.string "It was all over while we were still\n"
# 201 "data/maps/JaggedPass/scripts.pory"
	.string "trying to find a good footing…$"
# 202 "data/maps/JaggedPass/scripts.pory"

# 203 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_EthanPostBattle:
# 204 "data/maps/JaggedPass/scripts.pory"
	.string "If I had an ACRO BIKE, I'd be able to\n"
# 205 "data/maps/JaggedPass/scripts.pory"
	.string "jump ledges.$"
# 206 "data/maps/JaggedPass/scripts.pory"

# 207 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_EthanRegister:
# 208 "data/maps/JaggedPass/scripts.pory"
	.string "When I get more used to this bumpiness,\n"
# 209 "data/maps/JaggedPass/scripts.pory"
	.string "I'll be sure to win!\p"
# 210 "data/maps/JaggedPass/scripts.pory"
	.string "Can you register me in your POKéNAV?$"
# 211 "data/maps/JaggedPass/scripts.pory"

# 212 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_EthanRematchIntro:
# 213 "data/maps/JaggedPass/scripts.pory"
	.string "I got used to this bumpiness.\n"
# 214 "data/maps/JaggedPass/scripts.pory"
	.string "I sing while I climb now.$"
# 215 "data/maps/JaggedPass/scripts.pory"

# 216 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_EthanRematchDefeat:
# 217 "data/maps/JaggedPass/scripts.pory"
	.string "It's still not easy to battle on this\n"
# 218 "data/maps/JaggedPass/scripts.pory"
	.string "bumpy ground…$"
# 219 "data/maps/JaggedPass/scripts.pory"

# 220 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_EthanPostRematch:
# 221 "data/maps/JaggedPass/scripts.pory"
	.string "I should get an ACRO BIKE from RYDEL\n"
# 222 "data/maps/JaggedPass/scripts.pory"
	.string "in MAUVILLE CITY…$"
# 223 "data/maps/JaggedPass/scripts.pory"

# 224 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_GruntIntro:
# 225 "data/maps/JaggedPass/scripts.pory"
	.string "Wah!\n"
# 226 "data/maps/JaggedPass/scripts.pory"
	.string "What are you doing here?\p"
# 227 "data/maps/JaggedPass/scripts.pory"
	.string "What am I doing in a place like this?\p"
# 228 "data/maps/JaggedPass/scripts.pory"
	.string "What business is it of yours?$"
# 229 "data/maps/JaggedPass/scripts.pory"

# 230 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_GruntDefeat:
# 231 "data/maps/JaggedPass/scripts.pory"
	.string "Urrrgh…\p"
# 232 "data/maps/JaggedPass/scripts.pory"
	.string "I should've ducked into our HIDEOUT\n"
# 233 "data/maps/JaggedPass/scripts.pory"
	.string "right away…$"
# 234 "data/maps/JaggedPass/scripts.pory"

# 235 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_GoWhereverYouWant:
# 236 "data/maps/JaggedPass/scripts.pory"
	.string "Okay, oh-kay!\n"
# 237 "data/maps/JaggedPass/scripts.pory"
	.string "I admit it--you're strong!\p"
# 238 "data/maps/JaggedPass/scripts.pory"
	.string "Don't worry about me.\n"
# 239 "data/maps/JaggedPass/scripts.pory"
	.string "Go wherever you want!$"
# 240 "data/maps/JaggedPass/scripts.pory"

# 241 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_BoulderShakingInResponseToEmblem:
# 242 "data/maps/JaggedPass/scripts.pory"
	.string "Oh! This boulder is shaking in response\n"
# 243 "data/maps/JaggedPass/scripts.pory"
	.string "to the MAGMA EMBLEM!$"
# 244 "data/maps/JaggedPass/scripts.pory"

# 245 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_JulioIntro:
# 246 "data/maps/JaggedPass/scripts.pory"
	.string "Aiyeeh! It's awfully scary to shoot\n"
# 247 "data/maps/JaggedPass/scripts.pory"
	.string "down the mountain in one go!$"
# 248 "data/maps/JaggedPass/scripts.pory"

# 249 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_JulioDefeat:
# 250 "data/maps/JaggedPass/scripts.pory"
	.string "I feel like I'm falling apart…$"
# 251 "data/maps/JaggedPass/scripts.pory"

# 252 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_JulioPostBattle:
# 253 "data/maps/JaggedPass/scripts.pory"
	.string "My bicycle bounced around so much,\n"
# 254 "data/maps/JaggedPass/scripts.pory"
	.string "my rear end's sore…$"
# 255 "data/maps/JaggedPass/scripts.pory"

# 256 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_AutumnIntro:
# 257 "data/maps/JaggedPass/scripts.pory"
	.string "I climb this hill every day.\n"
# 258 "data/maps/JaggedPass/scripts.pory"
	.string "I have confidence in my strength!$"
# 259 "data/maps/JaggedPass/scripts.pory"

# 260 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_AutumnDefeat:
# 261 "data/maps/JaggedPass/scripts.pory"
	.string "Hmm…\n"
# 262 "data/maps/JaggedPass/scripts.pory"
	.string "What went wrong?$"
# 263 "data/maps/JaggedPass/scripts.pory"

# 264 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_AutumnPostBattle:
# 265 "data/maps/JaggedPass/scripts.pory"
	.string "What is that odd rock protrusion\n"
# 266 "data/maps/JaggedPass/scripts.pory"
	.string "a little up the hill from here?$"
