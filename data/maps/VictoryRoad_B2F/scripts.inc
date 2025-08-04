# 1 "data/maps/VictoryRoad_B2F/scripts.pory"

# 2 "data/maps/VictoryRoad_B2F/scripts.pory"
VictoryRoad_B2F_MapScripts::
# 3 "data/maps/VictoryRoad_B2F/scripts.pory"
    map_script MAP_SCRIPT_ON_RESUME, VictoryRoad_B2F_OnResume
# 4 "data/maps/VictoryRoad_B2F/scripts.pory"
	.byte 0
# 5 "data/maps/VictoryRoad_B2F/scripts.pory"

# 6 "data/maps/VictoryRoad_B2F/scripts.pory"
VictoryRoad_B2F_EventScript_Vito::
# 7 "data/maps/VictoryRoad_B2F/scripts.pory"
	trainerbattle_single TRAINER_VITO, VictoryRoad_B2F_Text_VitoIntro, VictoryRoad_B2F_Text_VitoDefeat
# 8 "data/maps/VictoryRoad_B2F/scripts.pory"
	msgbox VictoryRoad_B2F_Text_VitoPostBattle, MSGBOX_AUTOCLOSE
# 9 "data/maps/VictoryRoad_B2F/scripts.pory"
	end
# 10 "data/maps/VictoryRoad_B2F/scripts.pory"

# 11 "data/maps/VictoryRoad_B2F/scripts.pory"
VictoryRoad_B2F_EventScript_Owen::
# 12 "data/maps/VictoryRoad_B2F/scripts.pory"
	trainerbattle_single TRAINER_OWEN, VictoryRoad_B2F_Text_OwenIntro, VictoryRoad_B2F_Text_OwenDefeat
# 13 "data/maps/VictoryRoad_B2F/scripts.pory"
	msgbox VictoryRoad_B2F_Text_OwenPostBattle, MSGBOX_AUTOCLOSE
# 14 "data/maps/VictoryRoad_B2F/scripts.pory"
	end
# 15 "data/maps/VictoryRoad_B2F/scripts.pory"

# 16 "data/maps/VictoryRoad_B2F/scripts.pory"
VictoryRoad_B2F_EventScript_Caroline::
# 17 "data/maps/VictoryRoad_B2F/scripts.pory"
	trainerbattle_single TRAINER_CAROLINE, VictoryRoad_B2F_Text_CarolineIntro, VictoryRoad_B2F_Text_CarolineDefeat
# 18 "data/maps/VictoryRoad_B2F/scripts.pory"
	msgbox VictoryRoad_B2F_Text_CarolinePostBattle, MSGBOX_AUTOCLOSE
# 19 "data/maps/VictoryRoad_B2F/scripts.pory"
	end
# 20 "data/maps/VictoryRoad_B2F/scripts.pory"

# 21 "data/maps/VictoryRoad_B2F/scripts.pory"
VictoryRoad_B2F_EventScript_Julie::
# 22 "data/maps/VictoryRoad_B2F/scripts.pory"
	trainerbattle_single TRAINER_JULIE, VictoryRoad_B2F_Text_JulieIntro, VictoryRoad_B2F_Text_JulieDefeat
# 23 "data/maps/VictoryRoad_B2F/scripts.pory"
	msgbox VictoryRoad_B2F_Text_JuliePostBattle, MSGBOX_AUTOCLOSE
# 24 "data/maps/VictoryRoad_B2F/scripts.pory"
	end
# 25 "data/maps/VictoryRoad_B2F/scripts.pory"

# 26 "data/maps/VictoryRoad_B2F/scripts.pory"
VictoryRoad_B2F_EventScript_Felix::
# 27 "data/maps/VictoryRoad_B2F/scripts.pory"
	trainerbattle_single TRAINER_FELIX, VictoryRoad_B2F_Text_FelixIntro, VictoryRoad_B2F_Text_FelixDefeat
# 28 "data/maps/VictoryRoad_B2F/scripts.pory"
	msgbox VictoryRoad_B2F_Text_FelixPostBattle, MSGBOX_AUTOCLOSE
# 29 "data/maps/VictoryRoad_B2F/scripts.pory"
	end
# 30 "data/maps/VictoryRoad_B2F/scripts.pory"

# 31 "data/maps/VictoryRoad_B2F/scripts.pory"
VictoryRoad_B2F_EventScript_Dianne::
# 32 "data/maps/VictoryRoad_B2F/scripts.pory"
	trainerbattle_single TRAINER_DIANNE, VictoryRoad_B2F_Text_DianneIntro, VictoryRoad_B2F_Text_DianneDefeat
# 33 "data/maps/VictoryRoad_B2F/scripts.pory"
	msgbox VictoryRoad_B2F_Text_DiannePostBattle, MSGBOX_AUTOCLOSE
# 34 "data/maps/VictoryRoad_B2F/scripts.pory"
	end
# 35 "data/maps/VictoryRoad_B2F/scripts.pory"

# 36 "data/maps/VictoryRoad_B2F/scripts.pory"
VictoryRoad_B2F_Text_VitoIntro:
# 37 "data/maps/VictoryRoad_B2F/scripts.pory"
	.string "I trained together with my whole family,\n"
# 38 "data/maps/VictoryRoad_B2F/scripts.pory"
	.string "every one of us!\l"
# 39 "data/maps/VictoryRoad_B2F/scripts.pory"
	.string "I'm not losing to anyone!$"
# 40 "data/maps/VictoryRoad_B2F/scripts.pory"

# 41 "data/maps/VictoryRoad_B2F/scripts.pory"
VictoryRoad_B2F_Text_VitoDefeat:
# 42 "data/maps/VictoryRoad_B2F/scripts.pory"
	.string "Better than my family?!\n"
# 43 "data/maps/VictoryRoad_B2F/scripts.pory"
	.string "Is that possible?!$"
# 44 "data/maps/VictoryRoad_B2F/scripts.pory"

# 45 "data/maps/VictoryRoad_B2F/scripts.pory"
VictoryRoad_B2F_Text_VitoPostBattle:
# 46 "data/maps/VictoryRoad_B2F/scripts.pory"
	.string "I was better than everyone in my\n"
# 47 "data/maps/VictoryRoad_B2F/scripts.pory"
	.string "family. I've never lost before…\p"
# 48 "data/maps/VictoryRoad_B2F/scripts.pory"
	.string "I've lost my confidence…\n"
# 49 "data/maps/VictoryRoad_B2F/scripts.pory"
	.string "Maybe I'll go home…$"
# 50 "data/maps/VictoryRoad_B2F/scripts.pory"

# 51 "data/maps/VictoryRoad_B2F/scripts.pory"
VictoryRoad_B2F_Text_OwenIntro:
# 52 "data/maps/VictoryRoad_B2F/scripts.pory"
	.string "I'd heard that there was a tough\n"
# 53 "data/maps/VictoryRoad_B2F/scripts.pory"
	.string "little kid around. Do they mean you?$"
# 54 "data/maps/VictoryRoad_B2F/scripts.pory"

# 55 "data/maps/VictoryRoad_B2F/scripts.pory"
VictoryRoad_B2F_Text_OwenDefeat:
# 56 "data/maps/VictoryRoad_B2F/scripts.pory"
	.string "The little shrimp is tough!$"
# 57 "data/maps/VictoryRoad_B2F/scripts.pory"

# 58 "data/maps/VictoryRoad_B2F/scripts.pory"
VictoryRoad_B2F_Text_OwenPostBattle:
# 59 "data/maps/VictoryRoad_B2F/scripts.pory"
	.string "The rumors I heard, that tough little\n"
# 60 "data/maps/VictoryRoad_B2F/scripts.pory"
	.string "kid is from PETALBURG CITY.$"
# 61 "data/maps/VictoryRoad_B2F/scripts.pory"

# 62 "data/maps/VictoryRoad_B2F/scripts.pory"
VictoryRoad_B2F_Text_CarolineIntro:
# 63 "data/maps/VictoryRoad_B2F/scripts.pory"
	.string "You must be getting a little tired.$"
# 64 "data/maps/VictoryRoad_B2F/scripts.pory"

# 65 "data/maps/VictoryRoad_B2F/scripts.pory"
VictoryRoad_B2F_Text_CarolineDefeat:
# 66 "data/maps/VictoryRoad_B2F/scripts.pory"
	.string "No signs of tiring at all!$"
# 67 "data/maps/VictoryRoad_B2F/scripts.pory"

# 68 "data/maps/VictoryRoad_B2F/scripts.pory"
VictoryRoad_B2F_Text_CarolinePostBattle:
# 69 "data/maps/VictoryRoad_B2F/scripts.pory"
	.string "VICTORY ROAD and the POKéMON LEAGUE\n"
# 70 "data/maps/VictoryRoad_B2F/scripts.pory"
	.string "are long and grueling challenges.\l"
# 71 "data/maps/VictoryRoad_B2F/scripts.pory"
	.string "Beware of fatigue!$"
# 72 "data/maps/VictoryRoad_B2F/scripts.pory"

# 73 "data/maps/VictoryRoad_B2F/scripts.pory"
VictoryRoad_B2F_Text_JulieIntro:
# 74 "data/maps/VictoryRoad_B2F/scripts.pory"
	.string "You shouldn't get complacent just\n"
# 75 "data/maps/VictoryRoad_B2F/scripts.pory"
	.string "because you have a lot of GYM BADGES.\p"
# 76 "data/maps/VictoryRoad_B2F/scripts.pory"
	.string "There's always going to be someone\n"
# 77 "data/maps/VictoryRoad_B2F/scripts.pory"
	.string "who's better than you!$"
# 78 "data/maps/VictoryRoad_B2F/scripts.pory"

# 79 "data/maps/VictoryRoad_B2F/scripts.pory"
VictoryRoad_B2F_Text_JulieDefeat:
# 80 "data/maps/VictoryRoad_B2F/scripts.pory"
	.string "You're better than me!$"
# 81 "data/maps/VictoryRoad_B2F/scripts.pory"

# 82 "data/maps/VictoryRoad_B2F/scripts.pory"
VictoryRoad_B2F_Text_JuliePostBattle:
# 83 "data/maps/VictoryRoad_B2F/scripts.pory"
	.string "Gaze on your collected BADGES and\n"
# 84 "data/maps/VictoryRoad_B2F/scripts.pory"
	.string "remember the TRAINERS you've faced.$"
# 85 "data/maps/VictoryRoad_B2F/scripts.pory"

# 86 "data/maps/VictoryRoad_B2F/scripts.pory"
VictoryRoad_B2F_Text_FelixIntro:
# 87 "data/maps/VictoryRoad_B2F/scripts.pory"
	.string "I've come this far, but the tension's\n"
# 88 "data/maps/VictoryRoad_B2F/scripts.pory"
	.string "giving me awful stomach pain…$"
# 89 "data/maps/VictoryRoad_B2F/scripts.pory"

# 90 "data/maps/VictoryRoad_B2F/scripts.pory"
VictoryRoad_B2F_Text_FelixDefeat:
# 91 "data/maps/VictoryRoad_B2F/scripts.pory"
	.string "Ooh…\n"
# 92 "data/maps/VictoryRoad_B2F/scripts.pory"
	.string "It hurts…$"
# 93 "data/maps/VictoryRoad_B2F/scripts.pory"

# 94 "data/maps/VictoryRoad_B2F/scripts.pory"
VictoryRoad_B2F_Text_FelixPostBattle:
# 95 "data/maps/VictoryRoad_B2F/scripts.pory"
	.string "I can't help getting all tense knowing\n"
# 96 "data/maps/VictoryRoad_B2F/scripts.pory"
	.string "that I'm nearing the POKéMON LEAGUE.\p"
# 97 "data/maps/VictoryRoad_B2F/scripts.pory"
	.string "It's all I can do to feign calm.$"
# 98 "data/maps/VictoryRoad_B2F/scripts.pory"

# 99 "data/maps/VictoryRoad_B2F/scripts.pory"
VictoryRoad_B2F_Text_DianneIntro:
# 100 "data/maps/VictoryRoad_B2F/scripts.pory"
	.string "The elite among the elite gather in\n"
# 101 "data/maps/VictoryRoad_B2F/scripts.pory"
	.string "this cave.\p"
# 102 "data/maps/VictoryRoad_B2F/scripts.pory"
	.string "How are you finding it?$"
# 103 "data/maps/VictoryRoad_B2F/scripts.pory"

# 104 "data/maps/VictoryRoad_B2F/scripts.pory"
VictoryRoad_B2F_Text_DianneDefeat:
# 105 "data/maps/VictoryRoad_B2F/scripts.pory"
	.string "Not rattled in the least bit!$"
# 106 "data/maps/VictoryRoad_B2F/scripts.pory"

# 107 "data/maps/VictoryRoad_B2F/scripts.pory"
VictoryRoad_B2F_Text_DiannePostBattle:
# 108 "data/maps/VictoryRoad_B2F/scripts.pory"
	.string "You do have guts! I like that!\n"
# 109 "data/maps/VictoryRoad_B2F/scripts.pory"
	.string "Keep it going!$"
# 110 "data/maps/VictoryRoad_B2F/scripts.pory"

# 111 "data/maps/VictoryRoad_B2F/scripts.pory"
VictoryRoad_B2F_OnResume:
# 112 "data/maps/VictoryRoad_B2F/scripts.pory"
    call_if_set FLAG_SYS_CTRL_OBJ_DELETE, VictoryRoad_B2F_EventScript_TryRemoveZacian
# 113 "data/maps/VictoryRoad_B2F/scripts.pory"
    call_if_set FLAG_SYS_CTRL_OBJ_DELETE, VictoryRoad_B2F_EventScript_TryRemoveZamazenta
# 114 "data/maps/VictoryRoad_B2F/scripts.pory"
    end
# 115 "data/maps/VictoryRoad_B2F/scripts.pory"

# 116 "data/maps/VictoryRoad_B2F/scripts.pory"
VictoryRoad_B2F_EventScript_TryRemoveZacian::
# 117 "data/maps/VictoryRoad_B2F/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 118 "data/maps/VictoryRoad_B2F/scripts.pory"
    goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
# 119 "data/maps/VictoryRoad_B2F/scripts.pory"
    removeobject VAR_LAST_TALKED
# 120 "data/maps/VictoryRoad_B2F/scripts.pory"
    return
# 121 "data/maps/VictoryRoad_B2F/scripts.pory"

# 122 "data/maps/VictoryRoad_B2F/scripts.pory"
VictoryRoad_B2F_EventScript_TryRemoveZamazenta::
# 123 "data/maps/VictoryRoad_B2F/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 124 "data/maps/VictoryRoad_B2F/scripts.pory"
    goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
# 125 "data/maps/VictoryRoad_B2F/scripts.pory"
    removeobject VAR_LAST_TALKED
# 126 "data/maps/VictoryRoad_B2F/scripts.pory"
    return
# 127 "data/maps/VictoryRoad_B2F/scripts.pory"

# 128 "data/maps/VictoryRoad_B2F/scripts.pory"
VictoryRoad_B2F_EventScript_Zacian::
# 129 "data/maps/VictoryRoad_B2F/scripts.pory"
    lock
# 130 "data/maps/VictoryRoad_B2F/scripts.pory"
    faceplayer
# 131 "data/maps/VictoryRoad_B2F/scripts.pory"
    waitse
# 132 "data/maps/VictoryRoad_B2F/scripts.pory"
    playmoncry SPECIES_ZACIAN, CRY_MODE_ENCOUNTER
# 133 "data/maps/VictoryRoad_B2F/scripts.pory"
    delay 40
# 134 "data/maps/VictoryRoad_B2F/scripts.pory"
    waitmoncry
# 135 "data/maps/VictoryRoad_B2F/scripts.pory"
    setwildbattle SPECIES_ZACIAN, 60
# 136 "data/maps/VictoryRoad_B2F/scripts.pory"
    setflag FLAG_SYS_CTRL_OBJ_DELETE
# 137 "data/maps/VictoryRoad_B2F/scripts.pory"
    special BattleSetup_StartLegendaryBattle
# 138 "data/maps/VictoryRoad_B2F/scripts.pory"
    waitstate
# 139 "data/maps/VictoryRoad_B2F/scripts.pory"
    clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 140 "data/maps/VictoryRoad_B2F/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 141 "data/maps/VictoryRoad_B2F/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_WON, VictoryRoad_B2F_EventScript_DefeatedZacian
# 142 "data/maps/VictoryRoad_B2F/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_RAN, VictoryRoad_B2F_EventScript_RanFromZacian
# 143 "data/maps/VictoryRoad_B2F/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, VictoryRoad_B2F_EventScript_RanFromZacian
# 144 "data/maps/VictoryRoad_B2F/scripts.pory"
    setflag FLAG_DEFEATED_ZACIAN
# 145 "data/maps/VictoryRoad_B2F/scripts.pory"
    release
# 146 "data/maps/VictoryRoad_B2F/scripts.pory"
    end
# 147 "data/maps/VictoryRoad_B2F/scripts.pory"

# 148 "data/maps/VictoryRoad_B2F/scripts.pory"
VictoryRoad_B2F_EventScript_DefeatedZacian::
# 149 "data/maps/VictoryRoad_B2F/scripts.pory"
    setflag FLAG_DEFEATED_ZACIAN
# 150 "data/maps/VictoryRoad_B2F/scripts.pory"
    goto Common_EventScript_RemoveStaticPokemon
# 151 "data/maps/VictoryRoad_B2F/scripts.pory"
    end
# 152 "data/maps/VictoryRoad_B2F/scripts.pory"

# 153 "data/maps/VictoryRoad_B2F/scripts.pory"
VictoryRoad_B2F_EventScript_RanFromZacian::
# 154 "data/maps/VictoryRoad_B2F/scripts.pory"
    setvar VAR_0x8004, SPECIES_ZACIAN
# 155 "data/maps/VictoryRoad_B2F/scripts.pory"
    goto Common_EventScript_LegendaryFlewAway
# 156 "data/maps/VictoryRoad_B2F/scripts.pory"
    end
# 157 "data/maps/VictoryRoad_B2F/scripts.pory"

# 158 "data/maps/VictoryRoad_B2F/scripts.pory"
VictoryRoad_B2F_EventScript_Zamazenta::
# 159 "data/maps/VictoryRoad_B2F/scripts.pory"
    lock
# 160 "data/maps/VictoryRoad_B2F/scripts.pory"
    faceplayer
# 161 "data/maps/VictoryRoad_B2F/scripts.pory"
    waitse
# 162 "data/maps/VictoryRoad_B2F/scripts.pory"
    playmoncry SPECIES_ZAMAZENTA, CRY_MODE_ENCOUNTER
# 163 "data/maps/VictoryRoad_B2F/scripts.pory"
    delay 40
# 164 "data/maps/VictoryRoad_B2F/scripts.pory"
    waitmoncry
# 165 "data/maps/VictoryRoad_B2F/scripts.pory"
    setwildbattle SPECIES_ZAMAZENTA, 60
# 166 "data/maps/VictoryRoad_B2F/scripts.pory"
    setflag FLAG_SYS_CTRL_OBJ_DELETE
# 167 "data/maps/VictoryRoad_B2F/scripts.pory"
    special BattleSetup_StartLegendaryBattle
# 168 "data/maps/VictoryRoad_B2F/scripts.pory"
    waitstate
# 169 "data/maps/VictoryRoad_B2F/scripts.pory"
    clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 170 "data/maps/VictoryRoad_B2F/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 171 "data/maps/VictoryRoad_B2F/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_WON, VictoryRoad_B2F_EventScript_DefeatedZamazenta
# 172 "data/maps/VictoryRoad_B2F/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_RAN, VictoryRoad_B2F_EventScript_RanFromZamazenta
# 173 "data/maps/VictoryRoad_B2F/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, VictoryRoad_B2F_EventScript_RanFromZamazenta
# 174 "data/maps/VictoryRoad_B2F/scripts.pory"
    setflag FLAG_DEFEATED_ZAMAZENTA
# 175 "data/maps/VictoryRoad_B2F/scripts.pory"
    release
# 176 "data/maps/VictoryRoad_B2F/scripts.pory"
    end
# 177 "data/maps/VictoryRoad_B2F/scripts.pory"

# 178 "data/maps/VictoryRoad_B2F/scripts.pory"
VictoryRoad_B2F_EventScript_DefeatedZamazenta::
# 179 "data/maps/VictoryRoad_B2F/scripts.pory"
    setflag FLAG_DEFEATED_ZAMAZENTA
# 180 "data/maps/VictoryRoad_B2F/scripts.pory"
    goto Common_EventScript_RemoveStaticPokemon
# 181 "data/maps/VictoryRoad_B2F/scripts.pory"
    end
# 182 "data/maps/VictoryRoad_B2F/scripts.pory"

# 183 "data/maps/VictoryRoad_B2F/scripts.pory"
VictoryRoad_B2F_EventScript_RanFromZamazenta::
# 184 "data/maps/VictoryRoad_B2F/scripts.pory"
    setvar VAR_0x8004, SPECIES_ZAMAZENTA
# 185 "data/maps/VictoryRoad_B2F/scripts.pory"
    goto Common_EventScript_LegendaryFlewAway
# 186 "data/maps/VictoryRoad_B2F/scripts.pory"
    end
