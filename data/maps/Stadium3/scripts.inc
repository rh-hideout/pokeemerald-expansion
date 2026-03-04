Stadium3_MapScripts::
    .byte 0


@ ---------------------------------------------------------
@ PROF. BAMBERGER
@ ---------------------------------------------------------
Stadium3_EventScript_Bamberger::
    lock
    faceplayer

    @ Wenn schon besiegt: kurzer Text und raus
    goto_if_set FLAG_DEFEATED_SOOTOPOLIS_GYM, Stadium3_Bamberger_After

    msgbox Stadium3_Text_BambergerIntro, MSGBOX_DEFAULT
    closemessage

    @ Trainerkampf gegen TAKAO
    trainerbattle_single TRAINER_TAKAO, Stadium3_Text_TakaoIntro, Stadium3_Text_TakaoDefeated, Stadium3_EventScript_Takao_AfterBattle
    release
    end


Stadium3_EventScript_Takao_AfterBattle::
    @ Nur weitermachen, wenn wirklich besiegt
    goto_if_set FLAG_DEFEATED_SOOTOPOLIS_GYM, Stadium3_Takao_AfterBattle_End

    @ Flag für 8. Orden/Gym clear
    setflag FLAG_DEFEATED_SOOTOPOLIS_GYM

    msgbox Stadium3_Text_Reward, MSGBOX_DEFAULT
    closemessage

    @ TM Reward (leicht änderbar)
    giveitem ITEM_TM01, 1
    goto_if_eq VAR_RESULT, 0, Stadium3_Takao_BagFull

    msgbox Stadium3_Text_TMReceived, MSGBOX_DEFAULT
    release
    end

Stadium3_Takao_BagFull:
    msgbox Stadium3_Text_BagFull, MSGBOX_DEFAULT
    release
    end

Stadium3_Takao_AfterBattle_End:
    release
    end


Stadium3_Bamberger_After:
    msgbox Stadium3_Text_AlreadyWon, MSGBOX_DEFAULT
    release
    end


@ ---------------------------------------------------------
@ Texte
@ ---------------------------------------------------------
Stadium3_Text_BambergerIntro::
    .string "PROF. BAMBERGER: Have you seen the\n"
    .string "abomination they've bred? Who knows\p"
    .string "what they're up to. Thank you for\n"
    .string "scaring them away. I've just finished\p"
    .string "treating all my POKéMON.\n"
    .string "Are you ready for your next test?$"

Stadium3_Text_TakaoIntro::
    .string "Let's see what you've learned!$"

Stadium3_Text_TakaoDefeated::
    .string "Impressive. You passed.$"

Stadium3_Text_Reward::
    .string "You earned the 8th Badge!$"

Stadium3_Text_TMReceived::
    .string "And take this TM.$"

Stadium3_Text_BagFull::
    .string "Your Bag is full.$"

Stadium3_Text_AlreadyWon::
    .string "You've already passed this test.$"
