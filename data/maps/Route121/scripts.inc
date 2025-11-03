# 1 "data/maps/Route121/scripts.pory"

# 2 "data/maps/Route121/scripts.pory"
Route121_MapScripts::
# 3 "data/maps/Route121/scripts.pory"
	.byte 0
# 4 "data/maps/Route121/scripts.pory"

# 5 "data/maps/Route121/scripts.pory"
Route121_EventScript_Woman::
# 6 "data/maps/Route121/scripts.pory"
	msgbox Route121_Text_AheadLoomsMtPyre, MSGBOX_NPC
# 7 "data/maps/Route121/scripts.pory"
	end
# 8 "data/maps/Route121/scripts.pory"

# 9 "data/maps/Route121/scripts.pory"
Route121_EventScript_MtPyrePierSign::
# 10 "data/maps/Route121/scripts.pory"
	msgbox Route121_Text_MtPyrePierSign, MSGBOX_SIGN
# 11 "data/maps/Route121/scripts.pory"
	end
# 12 "data/maps/Route121/scripts.pory"

# 13 "data/maps/Route121/scripts.pory"
Route121_EventScript_SafariZoneSign::
# 14 "data/maps/Route121/scripts.pory"
	msgbox Route121_Text_SafariZoneSign, MSGBOX_SIGN
# 15 "data/maps/Route121/scripts.pory"
	end
# 16 "data/maps/Route121/scripts.pory"

# 17 "data/maps/Route121/scripts.pory"
Route121_EventScript_AquaGruntsMoveOut::
# 18 "data/maps/Route121/scripts.pory"
	lockall
# 19 "data/maps/Route121/scripts.pory"
	playbgm MUS_ENCOUNTER_AQUA, FALSE
# 20 "data/maps/Route121/scripts.pory"
	applymovement LOCALID_ROUTE121_GRUNT_2, Common_Movement_WalkInPlaceRight
# 21 "data/maps/Route121/scripts.pory"
	waitmovement 0
# 22 "data/maps/Route121/scripts.pory"
	msgbox Route121_Text_OkayMoveOutToMtPyre, MSGBOX_DEFAULT
# 23 "data/maps/Route121/scripts.pory"
	closemessage
# 24 "data/maps/Route121/scripts.pory"
	applymovement LOCALID_ROUTE121_GRUNT_1, Route121_Movement_Grunt1Exit
# 25 "data/maps/Route121/scripts.pory"
	applymovement LOCALID_ROUTE121_GRUNT_2, Route121_Movement_Grunt2Exit
# 26 "data/maps/Route121/scripts.pory"
	applymovement LOCALID_ROUTE121_GRUNT_3, Route121_Movement_Grunt3Exit
# 27 "data/maps/Route121/scripts.pory"
	waitmovement 0
# 28 "data/maps/Route121/scripts.pory"
	fadedefaultbgm
# 29 "data/maps/Route121/scripts.pory"
	removeobject LOCALID_ROUTE121_GRUNT_1
# 30 "data/maps/Route121/scripts.pory"
	removeobject LOCALID_ROUTE121_GRUNT_2
# 31 "data/maps/Route121/scripts.pory"
	removeobject LOCALID_ROUTE121_GRUNT_3
# 32 "data/maps/Route121/scripts.pory"
	setvar VAR_ROUTE121_STATE, 1
# 33 "data/maps/Route121/scripts.pory"
	releaseall
# 34 "data/maps/Route121/scripts.pory"
	end
# 35 "data/maps/Route121/scripts.pory"

# 36 "data/maps/Route121/scripts.pory"
Route121_Movement_Grunt1Exit:
# 37 "data/maps/Route121/scripts.pory"
	walk_down
# 38 "data/maps/Route121/scripts.pory"
	walk_down
# 39 "data/maps/Route121/scripts.pory"
	walk_down
# 40 "data/maps/Route121/scripts.pory"
	walk_down
# 41 "data/maps/Route121/scripts.pory"
	walk_down
# 42 "data/maps/Route121/scripts.pory"
	walk_down
# 43 "data/maps/Route121/scripts.pory"
	walk_down
# 44 "data/maps/Route121/scripts.pory"
	walk_down
# 45 "data/maps/Route121/scripts.pory"
	step_end
# 46 "data/maps/Route121/scripts.pory"

# 47 "data/maps/Route121/scripts.pory"
Route121_Movement_Grunt2Exit:
# 48 "data/maps/Route121/scripts.pory"
	walk_down
# 49 "data/maps/Route121/scripts.pory"
	walk_down
# 50 "data/maps/Route121/scripts.pory"
	walk_down
# 51 "data/maps/Route121/scripts.pory"
	walk_down
# 52 "data/maps/Route121/scripts.pory"
	walk_down
# 53 "data/maps/Route121/scripts.pory"
	walk_down
# 54 "data/maps/Route121/scripts.pory"
	walk_down
# 55 "data/maps/Route121/scripts.pory"
	walk_down
# 56 "data/maps/Route121/scripts.pory"
	step_end
# 57 "data/maps/Route121/scripts.pory"

# 58 "data/maps/Route121/scripts.pory"
Route121_Movement_Grunt3Exit:
# 59 "data/maps/Route121/scripts.pory"
	walk_down
# 60 "data/maps/Route121/scripts.pory"
	walk_down
# 61 "data/maps/Route121/scripts.pory"
	walk_down
# 62 "data/maps/Route121/scripts.pory"
	walk_down
# 63 "data/maps/Route121/scripts.pory"
	walk_down
# 64 "data/maps/Route121/scripts.pory"
	walk_down
# 65 "data/maps/Route121/scripts.pory"
	walk_down
# 66 "data/maps/Route121/scripts.pory"
	walk_down
# 67 "data/maps/Route121/scripts.pory"
	step_end
# 68 "data/maps/Route121/scripts.pory"

# 69 "data/maps/Route121/scripts.pory"
Route121_EventScript_Vanessa::
# 70 "data/maps/Route121/scripts.pory"
	trainerbattle_single TRAINER_VANESSA, Route121_Text_VanessaIntro, Route121_Text_VanessaDefeat
# 71 "data/maps/Route121/scripts.pory"
	msgbox Route121_Text_VanessaPostBattle, MSGBOX_AUTOCLOSE
# 72 "data/maps/Route121/scripts.pory"
	end
# 73 "data/maps/Route121/scripts.pory"

# 74 "data/maps/Route121/scripts.pory"
Route121_EventScript_Walter::
# 75 "data/maps/Route121/scripts.pory"
	trainerbattle_single TRAINER_WALTER_1, Route121_Text_WalterIntro, Route121_Text_WalterDefeat, Route121_EventScript_RegisterWalter
# 76 "data/maps/Route121/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 77 "data/maps/Route121/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route121_EventScript_RematchWalter
# 78 "data/maps/Route121/scripts.pory"
	msgbox Route121_Text_WalterPostBattle, MSGBOX_DEFAULT
# 79 "data/maps/Route121/scripts.pory"
	release
# 80 "data/maps/Route121/scripts.pory"
	end
# 81 "data/maps/Route121/scripts.pory"

# 82 "data/maps/Route121/scripts.pory"
Route121_EventScript_RegisterWalter::
# 83 "data/maps/Route121/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 84 "data/maps/Route121/scripts.pory"
	waitmovement 0
# 85 "data/maps/Route121/scripts.pory"
	msgbox Route121_Text_WalterRegister, MSGBOX_DEFAULT
# 86 "data/maps/Route121/scripts.pory"
	register_matchcall TRAINER_WALTER_1
# 87 "data/maps/Route121/scripts.pory"
	release
# 88 "data/maps/Route121/scripts.pory"
	end
# 89 "data/maps/Route121/scripts.pory"

# 90 "data/maps/Route121/scripts.pory"
Route121_EventScript_RematchWalter::
# 91 "data/maps/Route121/scripts.pory"
	trainerbattle_rematch TRAINER_WALTER_1, Route121_Text_WalterRematchIntro, Route121_Text_WalterRematchDefeat
# 92 "data/maps/Route121/scripts.pory"
	msgbox Route121_Text_WalterPostRematch, MSGBOX_AUTOCLOSE
# 93 "data/maps/Route121/scripts.pory"
	end
# 94 "data/maps/Route121/scripts.pory"

# 95 "data/maps/Route121/scripts.pory"
Route121_EventScript_Tammy::
# 96 "data/maps/Route121/scripts.pory"
	trainerbattle_single TRAINER_TAMMY, Route121_Text_TammyIntro, Route121_Text_TammyDefeat
# 97 "data/maps/Route121/scripts.pory"
	msgbox Route121_Text_TammyPostBattle, MSGBOX_AUTOCLOSE
# 98 "data/maps/Route121/scripts.pory"
	end
# 99 "data/maps/Route121/scripts.pory"

# 100 "data/maps/Route121/scripts.pory"
Route121_EventScript_Kate::
# 101 "data/maps/Route121/scripts.pory"
	trainerbattle_double TRAINER_KATE_AND_JOY, Route121_Text_KateIntro, Route121_Text_KateDefeat, Route121_Text_KateNotEnoughMons
# 102 "data/maps/Route121/scripts.pory"
	msgbox Route121_Text_KatePostBattle, MSGBOX_AUTOCLOSE
# 103 "data/maps/Route121/scripts.pory"
	end
# 104 "data/maps/Route121/scripts.pory"

# 105 "data/maps/Route121/scripts.pory"
Route121_EventScript_Joy::
# 106 "data/maps/Route121/scripts.pory"
	trainerbattle_double TRAINER_KATE_AND_JOY, Route121_Text_JoyIntro, Route121_Text_JoyDefeat, Route121_Text_JoyNotEnoughMons
# 107 "data/maps/Route121/scripts.pory"
	msgbox Route121_Text_JoyPostBattle, MSGBOX_AUTOCLOSE
# 108 "data/maps/Route121/scripts.pory"
	end
# 109 "data/maps/Route121/scripts.pory"

# 110 "data/maps/Route121/scripts.pory"
Route121_EventScript_Jessica::
# 111 "data/maps/Route121/scripts.pory"
	trainerbattle_single TRAINER_JESSICA_1, Route121_Text_JessicaIntro, Route121_Text_JessicaDefeat, Route121_EventScript_RegisterJessica
# 112 "data/maps/Route121/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 113 "data/maps/Route121/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route121_EventScript_RematchJessica
# 114 "data/maps/Route121/scripts.pory"
	msgbox Route121_Text_JessicaPostBattle, MSGBOX_DEFAULT
# 115 "data/maps/Route121/scripts.pory"
	release
# 116 "data/maps/Route121/scripts.pory"
	end
# 117 "data/maps/Route121/scripts.pory"

# 118 "data/maps/Route121/scripts.pory"
Route121_EventScript_RegisterJessica::
# 119 "data/maps/Route121/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 120 "data/maps/Route121/scripts.pory"
	waitmovement 0
# 121 "data/maps/Route121/scripts.pory"
	msgbox Route121_Text_JessicaRegister, MSGBOX_DEFAULT
# 122 "data/maps/Route121/scripts.pory"
	register_matchcall TRAINER_JESSICA_1
# 123 "data/maps/Route121/scripts.pory"
	release
# 124 "data/maps/Route121/scripts.pory"
	end
# 125 "data/maps/Route121/scripts.pory"

# 126 "data/maps/Route121/scripts.pory"
Route121_EventScript_RematchJessica::
# 127 "data/maps/Route121/scripts.pory"
	trainerbattle_rematch TRAINER_JESSICA_1, Route121_Text_JessicaRematchIntro, Route121_Text_JessicaRematchDefeat
# 128 "data/maps/Route121/scripts.pory"
	msgbox Route121_Text_JessicaPostRematch, MSGBOX_AUTOCLOSE
# 129 "data/maps/Route121/scripts.pory"
	end
# 130 "data/maps/Route121/scripts.pory"

# 131 "data/maps/Route121/scripts.pory"
Route121_EventScript_Cale::
# 132 "data/maps/Route121/scripts.pory"
	trainerbattle_single TRAINER_CALE, Route121_Text_CaleIntro, Route121_Text_CaleDefeat
# 133 "data/maps/Route121/scripts.pory"
	msgbox Route121_Text_CalePostBattle, MSGBOX_AUTOCLOSE
# 134 "data/maps/Route121/scripts.pory"
	end
# 135 "data/maps/Route121/scripts.pory"

# 136 "data/maps/Route121/scripts.pory"
Route121_EventScript_Myles::
# 137 "data/maps/Route121/scripts.pory"
	trainerbattle_single TRAINER_MYLES, Route121_Text_MylesIntro, Route121_Text_MylesDefeat
# 138 "data/maps/Route121/scripts.pory"
	msgbox Route121_Text_MylesPostBattle, MSGBOX_AUTOCLOSE
# 139 "data/maps/Route121/scripts.pory"
	end
# 140 "data/maps/Route121/scripts.pory"

# 141 "data/maps/Route121/scripts.pory"
Route121_EventScript_Pat::
# 142 "data/maps/Route121/scripts.pory"
	trainerbattle_single TRAINER_PAT, Route121_Text_PatIntro, Route121_Text_PatDefeat
# 143 "data/maps/Route121/scripts.pory"
	msgbox Route121_Text_PatPostBattle, MSGBOX_AUTOCLOSE
# 144 "data/maps/Route121/scripts.pory"
	end
# 145 "data/maps/Route121/scripts.pory"

# 146 "data/maps/Route121/scripts.pory"
Route121_EventScript_Marcel::
# 147 "data/maps/Route121/scripts.pory"
	trainerbattle_single TRAINER_MARCEL, Route121_Text_MarcelIntro, Route121_Text_MarcelDefeat
# 148 "data/maps/Route121/scripts.pory"
	msgbox Route121_Text_MarcelPostBattle, MSGBOX_AUTOCLOSE
# 149 "data/maps/Route121/scripts.pory"
	end
# 150 "data/maps/Route121/scripts.pory"

# 151 "data/maps/Route121/scripts.pory"
Route121_EventScript_Cristin::
# 152 "data/maps/Route121/scripts.pory"
	trainerbattle_single TRAINER_CRISTIN_1, Route121_Text_CristinIntro, Route121_Text_CristinDefeat, Route121_EventScript_RegisterCristin
# 153 "data/maps/Route121/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 154 "data/maps/Route121/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route121_EventScript_RematchCristin
# 155 "data/maps/Route121/scripts.pory"
	msgbox Route121_Text_CristinPostBattle, MSGBOX_DEFAULT
# 156 "data/maps/Route121/scripts.pory"
	release
# 157 "data/maps/Route121/scripts.pory"
	end
# 158 "data/maps/Route121/scripts.pory"

# 159 "data/maps/Route121/scripts.pory"
Route121_EventScript_RegisterCristin::
# 160 "data/maps/Route121/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 161 "data/maps/Route121/scripts.pory"
	waitmovement 0
# 162 "data/maps/Route121/scripts.pory"
	msgbox Route121_Text_CristinRegister, MSGBOX_DEFAULT
# 163 "data/maps/Route121/scripts.pory"
	register_matchcall TRAINER_CRISTIN_1
# 164 "data/maps/Route121/scripts.pory"
	release
# 165 "data/maps/Route121/scripts.pory"
	end
# 166 "data/maps/Route121/scripts.pory"

# 167 "data/maps/Route121/scripts.pory"
Route121_EventScript_RematchCristin::
# 168 "data/maps/Route121/scripts.pory"
	trainerbattle_rematch TRAINER_CRISTIN_1, Route121_Text_CristinRematchIntro, Route121_Text_CristinRematchDefeat
# 169 "data/maps/Route121/scripts.pory"
	msgbox Route121_Text_CristinPostRematch, MSGBOX_AUTOCLOSE
# 170 "data/maps/Route121/scripts.pory"
	end
# 171 "data/maps/Route121/scripts.pory"

# 172 "data/maps/Route121/scripts.pory"
Route121_Text_OkayMoveOutToMtPyre:
# 173 "data/maps/Route121/scripts.pory"
	.string "Okay!\n"
# 174 "data/maps/Route121/scripts.pory"
	.string "We're to move out to MT. PYRE!$"
# 175 "data/maps/Route121/scripts.pory"

# 176 "data/maps/Route121/scripts.pory"
Route121_Text_AheadLoomsMtPyre:
# 177 "data/maps/Route121/scripts.pory"
	.string "Ahead looms MT. PYRE…\p"
# 178 "data/maps/Route121/scripts.pory"
	.string "It is a natural monument to the spirits \n"
# 179 "data/maps/Route121/scripts.pory"
	.string "of departed POKéMON…$"
# 180 "data/maps/Route121/scripts.pory"

# 181 "data/maps/Route121/scripts.pory"
Route121_Text_MtPyrePierSign:
# 182 "data/maps/Route121/scripts.pory"
	.string "MT. PYRE PIER\p"
# 183 "data/maps/Route121/scripts.pory"
	.string "…The sign is old and worn out.\n"
# 184 "data/maps/Route121/scripts.pory"
	.string "The words are barely legible…$"
# 185 "data/maps/Route121/scripts.pory"

# 186 "data/maps/Route121/scripts.pory"
Route121_Text_SafariZoneSign:
# 187 "data/maps/Route121/scripts.pory"
	.string "“Filled with rare POKéMON!”\n"
# 188 "data/maps/Route121/scripts.pory"
	.string "SAFARI ZONE$"
