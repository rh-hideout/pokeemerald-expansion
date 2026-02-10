FinaleFarmer_MapScripts::
	.byte 0

FinaleFarmer_EventScript_PhillipBoss::
    lockall
    faceplayer
    goto_if_set FLAG_BADGE08_GET, FinaleFarmer_AfterScript


    @ First textbox: "..."
    msgbox FinaleFarmer_Text_Dots, MSGBOX_DEFAULT
    closemessage

    @ Turn boss to face down (starts face up)
    turnobject LOCALID_FARMER_FINALE, DIR_SOUTH

    @ Optional: branch if special Pokemon in party (Gengar)
    call FinaleFarmer_CheckPartyForGastlyLine
    compare VAR_RESULT, 1
    goto_if_eq FinaleFarmer_Intro_Gengar

FinaleFarmer_Intro_Normal:
    msgbox FinaleFarmer_Text_Intro, MSGBOX_DEFAULT
    goto FinaleFarmer_StartBattle

FinaleFarmer_Intro_Gengar:
    msgbox FinaleFarmer_Text_Intro_Gengar, MSGBOX_DEFAULT
    goto FinaleFarmer_StartBattle

FinaleFarmer_StartBattle:
    closemessage
    setvar VAR_LAST_TALKED, LOCALID_FARMER_FINALE

    @ IMPORTANT: This trainerbattle macro in your repo requires all params.
    @ Also: keep it on ONE line and use numeric constants (0/1).
    trainerbattle TRAINER_BATTLE_SINGLE, LOCALID_FARMER_FINALE, TRAINER_PHILLIP, FinaleFarmer_Text_Intro, FinaleFarmer_Text_Lose, FinaleFarmer_AfterBattle, 0, 0, 0, 0, 0, FinaleFarmer_Text_AfterBattle, FinaleFarmer_Text_CannotBattle, 0, 1, 0, 0

    end

FinaleFarmer_AfterScript:
    msgbox FinaleFarmer_Text_After, MSGBOX_DEFAULT
    release
    end

@ =========================================================
@ After battle (player won)
@ =========================================================
FinaleFarmer_AfterBattle:
    lockall
    faceplayer
    setflag FLAG_BADGE08_GET
    msgbox FinaleFarmer_Text_VictorySpeech, MSGBOX_DEFAULT
    closemessage
    msgbox FinaleFarmer_Text_BadgeReceived, MSGBOX_DEFAULT
    releaseall
    end



@ =========================================================
@ Party Check Helper (STUB)
@ =========================================================

FinaleFarmer_CheckPartyForGastlyLine:
    setvar VAR_RESULT, 0

    setvar VAR_0x8004, SPECIES_GASTLY
    specialvar VAR_0x8005, PARTY_CONTAINS_SPECIES
    compare VAR_0x8005, 1
    goto_if_eq .found

    setvar VAR_0x8004, SPECIES_HAUNTER
    specialvar VAR_0x8005, Special_PartyContainsSpecies
    compare VAR_0x8005, 1
    goto_if_eq .found

    setvar VAR_0x8004, SPECIES_GENGAR
    specialvar VAR_0x8005, Special_PartyContainsSpecies
    compare VAR_0x8005, 1
    goto_if_eq .found

    return
.found:
    setvar VAR_RESULT, 1
    return


@ =========================================================
@ Text
@ =========================================================

FinaleFarmer_Text_Dots:
    .string "...$"

FinaleFarmer_Text_Intro:
    .string "You made it.\n"
    .string "Not by luck, by method.\p"
    .string "By curiosity sharpened into skill.\n"
    .string "This is the final lab.\p"
    .string "The final firewall.\n"
    .string "The last system to breach.\p"
    .string "In Computer Science, we don't\n"
    .string "fear complexity, we map it.\p"
    .string "In Cyber Security, we don't\n"
    .string "wait for threats, we anticipate.\p"
    .string "Show me your discipline.\n"
    .string "Show me your craft.\p"
    .string "Show me your proof.$"

FinaleFarmer_Text_Intro_Gengar:
    .string "...\p"
    .string "That presence in your team...\n"
    .string "A shadow with teeth.\p"
    .string "A reminder that unseen vectors\n"
    .string "still strike hardest.\p"
    .string "Good.\n"
    .string "Bring it.\p"
    .string "Let's see if your defenses hold.$"

FinaleFarmer_Text_Lose:
    .string "A system can be restarted.\n"
    .string "A mind can be rebuilt.\p"
    .string "Return when you're ready.$"

FinaleFarmer_Text_AfterBattle:
    .string "Impressive.\n"
    .string "You didn't just win,\p"
    .string "you validated your approach.$"

FinaleFarmer_Text_VictorySpeech:
    .string "That's it.\n"
    .string "No shortcuts.\p"
    .string "No exploits without ethics.\p"
    .string "You demonstrated analysis,\n"
    .string "resilience, and intent.\p"
    .string "From theory to practice.\n"
    .string "From noise to signal.\p"
    .string "From student to specialist.$"

FinaleFarmer_Text_BadgeReceived:
    .string "You received the\n"
    .string "DIGITAL TECHNOLOGY BADGE!\p"
    .string "This badge marks the completion\n"
    .string "of the program.\p"
    .string "Your final credential:\n"
    .string "earned, not given.$"

FinaleFarmer_Text_After:
    .string "You've earned it.\n"
    .string "Carry that badge like a key\n"
    .string "and like a responsibility.$"

FinaleFarmer_Text_CannotBattle:
    .string "You have no usable Pokemon.$"

