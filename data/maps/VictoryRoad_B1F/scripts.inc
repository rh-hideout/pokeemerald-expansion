# 1 "data/maps/VictoryRoad_B1F/scripts.pory"

# 2 "data/maps/VictoryRoad_B1F/scripts.pory"
VictoryRoad_B1F_MapScripts::
# 3 "data/maps/VictoryRoad_B1F/scripts.pory"
     map_script MAP_SCRIPT_ON_RESUME, VictoryRoad_B1F_OnResume
# 4 "data/maps/VictoryRoad_B1F/scripts.pory"
	.byte 0
# 5 "data/maps/VictoryRoad_B1F/scripts.pory"

# 6 "data/maps/VictoryRoad_B1F/scripts.pory"
VictoryRoad_B1F_EventScript_Samuel::
# 7 "data/maps/VictoryRoad_B1F/scripts.pory"
	trainerbattle_single TRAINER_SAMUEL, VictoryRoad_B1F_Text_SamuelIntro, VictoryRoad_B1F_Text_SamuelDefeat
# 8 "data/maps/VictoryRoad_B1F/scripts.pory"
	msgbox VictoryRoad_B1F_Text_SamuelPostBattle, MSGBOX_AUTOCLOSE
# 9 "data/maps/VictoryRoad_B1F/scripts.pory"
	end
# 10 "data/maps/VictoryRoad_B1F/scripts.pory"

# 11 "data/maps/VictoryRoad_B1F/scripts.pory"
VictoryRoad_B1F_EventScript_Shannon::
# 12 "data/maps/VictoryRoad_B1F/scripts.pory"
	trainerbattle_single TRAINER_SHANNON, VictoryRoad_B1F_Text_ShannonIntro, VictoryRoad_B1F_Text_ShannonDefeat
# 13 "data/maps/VictoryRoad_B1F/scripts.pory"
	msgbox VictoryRoad_B1F_Text_ShannonPostBattle, MSGBOX_AUTOCLOSE
# 14 "data/maps/VictoryRoad_B1F/scripts.pory"
	end
# 15 "data/maps/VictoryRoad_B1F/scripts.pory"

# 16 "data/maps/VictoryRoad_B1F/scripts.pory"
VictoryRoad_B1F_EventScript_Michelle::
# 17 "data/maps/VictoryRoad_B1F/scripts.pory"
	trainerbattle_single TRAINER_MICHELLE, VictoryRoad_B1F_Text_MichelleIntro, VictoryRoad_B1F_Text_MichelleDefeat
# 18 "data/maps/VictoryRoad_B1F/scripts.pory"
	msgbox VictoryRoad_B1F_Text_MichellePostBattle, MSGBOX_AUTOCLOSE
# 19 "data/maps/VictoryRoad_B1F/scripts.pory"
	end
# 20 "data/maps/VictoryRoad_B1F/scripts.pory"

# 21 "data/maps/VictoryRoad_B1F/scripts.pory"
VictoryRoad_B1F_EventScript_Mitchell::
# 22 "data/maps/VictoryRoad_B1F/scripts.pory"
	trainerbattle_single TRAINER_MITCHELL, VictoryRoad_B1F_Text_MitchellIntro, VictoryRoad_B1F_Text_MitchellDefeat
# 23 "data/maps/VictoryRoad_B1F/scripts.pory"
	msgbox VictoryRoad_B1F_Text_MitchellPostBattle, MSGBOX_AUTOCLOSE
# 24 "data/maps/VictoryRoad_B1F/scripts.pory"
	end
# 25 "data/maps/VictoryRoad_B1F/scripts.pory"

# 26 "data/maps/VictoryRoad_B1F/scripts.pory"
VictoryRoad_B1F_EventScript_Halle::
# 27 "data/maps/VictoryRoad_B1F/scripts.pory"
	trainerbattle_single TRAINER_HALLE, VictoryRoad_B1F_Text_HalleIntro, VictoryRoad_B1F_Text_HalleDefeat
# 28 "data/maps/VictoryRoad_B1F/scripts.pory"
	msgbox VictoryRoad_B1F_Text_HallePostBattle, MSGBOX_AUTOCLOSE
# 29 "data/maps/VictoryRoad_B1F/scripts.pory"
	end
# 30 "data/maps/VictoryRoad_B1F/scripts.pory"

# 31 "data/maps/VictoryRoad_B1F/scripts.pory"
VictoryRoad_B1F_Text_SamuelIntro:
# 32 "data/maps/VictoryRoad_B1F/scripts.pory"
	.string "The thought that I'm getting closer to\n"
# 33 "data/maps/VictoryRoad_B1F/scripts.pory"
	.string "the POKéMON LEAGUE…\p"
# 34 "data/maps/VictoryRoad_B1F/scripts.pory"
	.string "I'm getting stage fright…$"
# 35 "data/maps/VictoryRoad_B1F/scripts.pory"

# 36 "data/maps/VictoryRoad_B1F/scripts.pory"
VictoryRoad_B1F_Text_SamuelDefeat:
# 37 "data/maps/VictoryRoad_B1F/scripts.pory"
	.string "I couldn't do a thing…$"
# 38 "data/maps/VictoryRoad_B1F/scripts.pory"

# 39 "data/maps/VictoryRoad_B1F/scripts.pory"
VictoryRoad_B1F_Text_SamuelPostBattle:
# 40 "data/maps/VictoryRoad_B1F/scripts.pory"
	.string "The POKéMON LEAGUE became distant\n"
# 41 "data/maps/VictoryRoad_B1F/scripts.pory"
	.string "again… What a letdown…$"
# 42 "data/maps/VictoryRoad_B1F/scripts.pory"

# 43 "data/maps/VictoryRoad_B1F/scripts.pory"
VictoryRoad_B1F_Text_ShannonIntro:
# 44 "data/maps/VictoryRoad_B1F/scripts.pory"
	.string "To win your way through the POKéMON\n"
# 45 "data/maps/VictoryRoad_B1F/scripts.pory"
	.string "LEAGUE, you need the trust of your\l"
# 46 "data/maps/VictoryRoad_B1F/scripts.pory"
	.string "POKéMON.$"
# 47 "data/maps/VictoryRoad_B1F/scripts.pory"

# 48 "data/maps/VictoryRoad_B1F/scripts.pory"
VictoryRoad_B1F_Text_ShannonDefeat:
# 49 "data/maps/VictoryRoad_B1F/scripts.pory"
	.string "Your relationship is based on\n"
# 50 "data/maps/VictoryRoad_B1F/scripts.pory"
	.string "solid trust.$"
# 51 "data/maps/VictoryRoad_B1F/scripts.pory"

# 52 "data/maps/VictoryRoad_B1F/scripts.pory"
VictoryRoad_B1F_Text_ShannonPostBattle:
# 53 "data/maps/VictoryRoad_B1F/scripts.pory"
	.string "By being together all the time, trust\n"
# 54 "data/maps/VictoryRoad_B1F/scripts.pory"
	.string "grows between POKéMON and TRAINERS.$"
# 55 "data/maps/VictoryRoad_B1F/scripts.pory"

# 56 "data/maps/VictoryRoad_B1F/scripts.pory"
VictoryRoad_B1F_Text_MichelleIntro:
# 57 "data/maps/VictoryRoad_B1F/scripts.pory"
	.string "This isn't the goal. It's only a place\n"
# 58 "data/maps/VictoryRoad_B1F/scripts.pory"
	.string "on the way to the POKéMON LEAGUE.$"
# 59 "data/maps/VictoryRoad_B1F/scripts.pory"

# 60 "data/maps/VictoryRoad_B1F/scripts.pory"
VictoryRoad_B1F_Text_MichelleDefeat:
# 61 "data/maps/VictoryRoad_B1F/scripts.pory"
	.string "That's the way!$"
# 62 "data/maps/VictoryRoad_B1F/scripts.pory"

# 63 "data/maps/VictoryRoad_B1F/scripts.pory"
VictoryRoad_B1F_Text_MichellePostBattle:
# 64 "data/maps/VictoryRoad_B1F/scripts.pory"
	.string "You'll do fine, for sure!\n"
# 65 "data/maps/VictoryRoad_B1F/scripts.pory"
	.string "Your POKéMON are all eager to go!$"
# 66 "data/maps/VictoryRoad_B1F/scripts.pory"

# 67 "data/maps/VictoryRoad_B1F/scripts.pory"
VictoryRoad_B1F_Text_MitchellIntro:
# 68 "data/maps/VictoryRoad_B1F/scripts.pory"
	.string "My POKéMON are cosmically\n"
# 69 "data/maps/VictoryRoad_B1F/scripts.pory"
	.string "awe inspiring!$"
# 70 "data/maps/VictoryRoad_B1F/scripts.pory"

# 71 "data/maps/VictoryRoad_B1F/scripts.pory"
VictoryRoad_B1F_Text_MitchellDefeat:
# 72 "data/maps/VictoryRoad_B1F/scripts.pory"
	.string "I've never met anyone like you before.$"
# 73 "data/maps/VictoryRoad_B1F/scripts.pory"

# 74 "data/maps/VictoryRoad_B1F/scripts.pory"
VictoryRoad_B1F_Text_MitchellPostBattle:
# 75 "data/maps/VictoryRoad_B1F/scripts.pory"
	.string "Even outside of battle, I sense\n"
# 76 "data/maps/VictoryRoad_B1F/scripts.pory"
	.string "incredible power emanating from you\l"
# 77 "data/maps/VictoryRoad_B1F/scripts.pory"
	.string "and your POKéMON.$"
# 78 "data/maps/VictoryRoad_B1F/scripts.pory"

# 79 "data/maps/VictoryRoad_B1F/scripts.pory"
VictoryRoad_B1F_Text_HalleIntro:
# 80 "data/maps/VictoryRoad_B1F/scripts.pory"
	.string "Okay, no need to get your back up!\n"
# 81 "data/maps/VictoryRoad_B1F/scripts.pory"
	.string "Relax, let's take it easy!$"
# 82 "data/maps/VictoryRoad_B1F/scripts.pory"

# 83 "data/maps/VictoryRoad_B1F/scripts.pory"
VictoryRoad_B1F_Text_HalleDefeat:
# 84 "data/maps/VictoryRoad_B1F/scripts.pory"
	.string "Whoa!\n"
# 85 "data/maps/VictoryRoad_B1F/scripts.pory"
	.string "Wonderful!$"
# 86 "data/maps/VictoryRoad_B1F/scripts.pory"

# 87 "data/maps/VictoryRoad_B1F/scripts.pory"
VictoryRoad_B1F_Text_HallePostBattle:
# 88 "data/maps/VictoryRoad_B1F/scripts.pory"
	.string "Sure, this is VICTORY ROAD.\p"
# 89 "data/maps/VictoryRoad_B1F/scripts.pory"
	.string "But it's not all that different from\n"
# 90 "data/maps/VictoryRoad_B1F/scripts.pory"
	.string "the path you've taken so far.\p"
# 91 "data/maps/VictoryRoad_B1F/scripts.pory"
	.string "Try to enjoy things the rest of\n"
# 92 "data/maps/VictoryRoad_B1F/scripts.pory"
	.string "the way!$"
# 93 "data/maps/VictoryRoad_B1F/scripts.pory"

# 94 "data/maps/VictoryRoad_B1F/scripts.pory"
VictoryRoad_B1F_OnResume:
# 95 "data/maps/VictoryRoad_B1F/scripts.pory"
    call_if_set FLAG_SYS_CTRL_OBJ_DELETE, VictoryRoad_B1F_EventScript_TryRemoveEternatus
# 96 "data/maps/VictoryRoad_B1F/scripts.pory"
    end
# 97 "data/maps/VictoryRoad_B1F/scripts.pory"

# 98 "data/maps/VictoryRoad_B1F/scripts.pory"
VictoryRoad_B1F_EventScript_TryRemoveEternatus::
# 99 "data/maps/VictoryRoad_B1F/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 100 "data/maps/VictoryRoad_B1F/scripts.pory"
    goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
# 101 "data/maps/VictoryRoad_B1F/scripts.pory"
    removeobject VAR_LAST_TALKED
# 102 "data/maps/VictoryRoad_B1F/scripts.pory"
    return
# 103 "data/maps/VictoryRoad_B1F/scripts.pory"

# 104 "data/maps/VictoryRoad_B1F/scripts.pory"
VictoryRoad_B1F_EventScript_Eternatus::
# 105 "data/maps/VictoryRoad_B1F/scripts.pory"
    lock
# 106 "data/maps/VictoryRoad_B1F/scripts.pory"
    faceplayer
# 107 "data/maps/VictoryRoad_B1F/scripts.pory"
    waitse
# 108 "data/maps/VictoryRoad_B1F/scripts.pory"
    playmoncry SPECIES_ETERNATUS, CRY_MODE_ENCOUNTER
# 109 "data/maps/VictoryRoad_B1F/scripts.pory"
    delay 40
# 110 "data/maps/VictoryRoad_B1F/scripts.pory"
    waitmoncry
# 111 "data/maps/VictoryRoad_B1F/scripts.pory"
    setwildbattle SPECIES_ETERNATUS, 70
# 112 "data/maps/VictoryRoad_B1F/scripts.pory"
    setflag FLAG_SYS_CTRL_OBJ_DELETE
# 113 "data/maps/VictoryRoad_B1F/scripts.pory"
    special BattleSetup_StartLegendaryBattle
# 114 "data/maps/VictoryRoad_B1F/scripts.pory"
    waitstate
# 115 "data/maps/VictoryRoad_B1F/scripts.pory"
    clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 116 "data/maps/VictoryRoad_B1F/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 117 "data/maps/VictoryRoad_B1F/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_WON, VictoryRoad_B1F_EventScript_DefeatedEternatus
# 118 "data/maps/VictoryRoad_B1F/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_RAN, VictoryRoad_B1F_EventScript_RanFromEternatus
# 119 "data/maps/VictoryRoad_B1F/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, VictoryRoad_B1F_EventScript_RanFromEternatus
# 120 "data/maps/VictoryRoad_B1F/scripts.pory"
    setflag FLAG_DEFEATED_ETERNATUS
# 121 "data/maps/VictoryRoad_B1F/scripts.pory"
    release
# 122 "data/maps/VictoryRoad_B1F/scripts.pory"
    end
# 123 "data/maps/VictoryRoad_B1F/scripts.pory"

# 124 "data/maps/VictoryRoad_B1F/scripts.pory"
VictoryRoad_B1F_EventScript_DefeatedEternatus::
# 125 "data/maps/VictoryRoad_B1F/scripts.pory"
    setflag FLAG_DEFEATED_ETERNATUS
# 126 "data/maps/VictoryRoad_B1F/scripts.pory"
    goto Common_EventScript_RemoveStaticPokemon
# 127 "data/maps/VictoryRoad_B1F/scripts.pory"
    end
# 128 "data/maps/VictoryRoad_B1F/scripts.pory"

# 129 "data/maps/VictoryRoad_B1F/scripts.pory"
VictoryRoad_B1F_EventScript_RanFromEternatus::
# 130 "data/maps/VictoryRoad_B1F/scripts.pory"
    setvar VAR_0x8004, SPECIES_ETERNATUS
# 131 "data/maps/VictoryRoad_B1F/scripts.pory"
    goto Common_EventScript_LegendaryFlewAway
# 132 "data/maps/VictoryRoad_B1F/scripts.pory"
    end
