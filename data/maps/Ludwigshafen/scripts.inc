Ludwigshafen_MapScripts::
    .byte 0


@ Trigger: beim Drauftreten wird das Intro einmalig abgespielt
Ludwigshafen_EventScript_IntroTrigger::
    lockall
    goto_if_set FLAG_LUDWIGSHAFEN_INTRO_DONE, Ludwigshafen_Intro_Done

    msgbox Ludwigshafen_Text_PleaseWait, MSGBOX_DEFAULT
    closemessage

    @ NPCs laufen 6 Tiles nach rechts auf den Spieler zu
    applymovement LOCALID_WANDA,  Ludwigshafen_Movement_ApproachRight6
    applymovement LOCALID_AMANDA, Ludwigshafen_Movement_ApproachRight6
    waitmovement 0

    msgbox Ludwigshafen_Text_WandaAmanda_Intro, MSGBOX_DEFAULT
    closemessage

    @ Beide laufen 23 nach links, Spieler läuft hinterher
    applymovement LOCALID_WANDA,  Ludwigshafen_Movement_WalkLeft23
    applymovement LOCALID_AMANDA, Ludwigshafen_Movement_WalkLeft23

    applymovement LOCALID_PLAYER, Ludwigshafen_Movement_WalkLeft23

    waitmovement 0

    applymovement LOCALID_AMANDA, Ludwigshafen_Movement_FaceRight
    applymovement LOCALID_WANDA,  Ludwigshafen_Movement_FaceRight

    waitmovement 0

    msgbox Ludwigshafen_Text_Both_Glitchy, MSGBOX_DEFAULT

    setflag FLAG_LUDWIGSHAFEN_INTRO_DONE

Ludwigshafen_Movement_FaceRight:
    face_right
    step_end

Ludwigshafen_Intro_Done:
    releaseall
    end


@ Nach dem Intro: beide sagen nur noch "Please hurry!"
Ludwigshafen_EventScript_Wanda_After::
    lock
    faceplayer
    msgbox Ludwigshafen_Text_Both_PleaseHurry, MSGBOX_DEFAULT
    release
    end

Ludwigshafen_EventScript_Amanda_After::
    lock
    faceplayer
    msgbox Ludwigshafen_Text_Both_PleaseHurry, MSGBOX_DEFAULT
    release
    end


@ ----------------
@ Movements
@ ----------------

Ludwigshafen_Movement_ApproachRight6:
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    step_end

Ludwigshafen_Movement_WalkLeft23:
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    step_end


@ ----------------
@ Text
@ ----------------

Ludwigshafen_Text_PleaseWait:
    .string "Hey you, please wait!$"

Ludwigshafen_Text_WandaAmanda_Intro:
    .string "WANDA: Quick, you have to help us!\p"
	.string "{PLAYER}: Sure, what's up?\n"
    .string "AMANDA: The doctor is in danger!$"

Ludwigshafen_Text_Both_Glitchy:
    .string "BOTH: Everything is so glitchy,\n"
	.string "hurry up and go inside!$"

Ludwigshafen_Text_Both_PleaseHurry:
    .string "BOTH: Please hurry!$"




    .include "constants/global.inc"

@ =========================================================
@ 1) Fake-Trade-Evo: Haunter -> Gengar (wählbares Party-Mon)
@ =========================================================
Ludwigshafen_EventScript_FakeTradeEvo_HaunterToGengar::
    lock
    faceplayer

    msgbox Ludwigshafen_Text_TradeEvoInvite, MSGBOX_YESNO
    compare VAR_RESULT, NO
    goto_if_eq Ludwigshafen_TradeEvo_End

Ludwigshafen_TradeEvo_SelectLoop:
    msgbox Ludwigshafen_Text_TradeEvoChoose, MSGBOX_DEFAULT
    closemessage

    special ChoosePartyMon
    waitstate

    @ Cancel/invalid selection -> VAR_0x8004 >= PARTY_SIZE
    goto_if_ge VAR_0x8004, PARTY_SIZE, Ludwigshafen_TradeEvo_End

    @ Optional: nicer Text (C-special prüft sowieso nochmal)
    specialvar VAR_RESULT, ScriptGetPartyMonSpecies
    goto_if_ne VAR_RESULT, SPECIES_HAUNTER, Ludwigshafen_TradeEvo_WrongMon

    @ ---- Konfiguration für dieses Event (pro Event frei definierbar) ----
    setvar VAR_0x8005, SPECIES_HAUNTER     @ required/base
    setvar VAR_0x8006, SPECIES_GENGAR      @ target
    setvar VAR_0x8007, ITEM_NONE           @ required held item (0/ITEM_NONE = keines)
    setvar VAR_0x8008, 0                   @ 0 = Everstone blockt, 1 = Everstone ignorieren
    setvar VAR_0x8009, 0                   @ 0 = Item nicht verbrauchen, 1 = verbrauchen (nur relevant wenn VAR_0x8007 != ITEM_NONE)

    @ Trade-Feeling: Sound + warten (Overworld, aber gelockt)
    playse SE_WARP_IN
    playse SE_WARP_OUT
    waitse

    @ Evolution starten (kein echter Trade; Pokémon bleibt deins)
    special Special_FakeTradeEvolveSelectedToTarget
    waitstate

    @ Resultcodes (VAR_RESULT):
    @ 1 = Evolution gestartet
    @ 2 = falsche Species
    @ 3 = Ei
    @ 4 = Everstone blockt
    @ 5 = benötigtes Held-Item fehlt
    compare VAR_RESULT, 1
    goto_if_eq Ludwigshafen_TradeEvo_Success

    compare VAR_RESULT, 3
    goto_if_eq Ludwigshafen_TradeEvo_IsEgg

    compare VAR_RESULT, 4
    goto_if_eq Ludwigshafen_TradeEvo_Everstone

    compare VAR_RESULT, 5
    goto_if_eq Ludwigshafen_TradeEvo_NoItem

    @ Fallback (inkl. “falsche Species”)
    goto Ludwigshafen_TradeEvo_WrongMon

Ludwigshafen_TradeEvo_Success:
    msgbox Ludwigshafen_Text_TradeEvoAfter, MSGBOX_DEFAULT
    goto Ludwigshafen_TradeEvo_End

Ludwigshafen_TradeEvo_WrongMon:
    msgbox Ludwigshafen_Text_TradeEvoWrongMon, MSGBOX_DEFAULT
    goto Ludwigshafen_TradeEvo_SelectLoop

Ludwigshafen_TradeEvo_IsEgg:
    msgbox Ludwigshafen_Text_TradeEvoIsEgg, MSGBOX_DEFAULT
    goto Ludwigshafen_TradeEvo_SelectLoop

Ludwigshafen_TradeEvo_Everstone:
    msgbox Ludwigshafen_Text_TradeEvoEverstone, MSGBOX_DEFAULT
    goto Ludwigshafen_TradeEvo_SelectLoop

Ludwigshafen_TradeEvo_NoItem:
    msgbox Ludwigshafen_Text_TradeEvoNoItem, MSGBOX_DEFAULT
    goto Ludwigshafen_TradeEvo_SelectLoop

Ludwigshafen_TradeEvo_End:
    release
    end


@ =========================================================
@ 2) Geschenk-NPC: Gibt 1x Haunter (einmalig per Flag)
@ =========================================================
Ludwigshafen_EventScript_GiftHaunter::
    lock
    faceplayer

    goto_if_set FLAG_LUDWIGSHAFEN_GOT_HAUNTER_GIFT, Ludwigshafen_GiftHaunter_AlreadyDone

    msgbox Ludwigshafen_Text_GiftHaunterOffer, MSGBOX_YESNO
    compare VAR_RESULT, NO
    goto_if_eq Ludwigshafen_GiftHaunter_End

    msgbox Ludwigshafen_Text_GiftHaunterGive, MSGBOX_DEFAULT
    closemessage

    givemon SPECIES_HAUNTER, 20, ITEM_NONE

    setflag FLAG_LUDWIGSHAFEN_GOT_HAUNTER_GIFT
    msgbox Ludwigshafen_Text_GiftHaunterAfter, MSGBOX_DEFAULT
    goto Ludwigshafen_GiftHaunter_End

Ludwigshafen_GiftHaunter_AlreadyDone:
    msgbox Ludwigshafen_Text_GiftHaunterAlreadyDone, MSGBOX_DEFAULT

Ludwigshafen_GiftHaunter_End:
    release
    end



@ =========================================================
@ Texte (änderbar nach Wunsch)
@ =========================================================
Ludwigshafen_Text_TradeEvoInvite:
    .string "ILJA: Hey, we're swapping our HAUNTERS\n"
    .string "so they can evolve into GENGAR.\p"
    .string "RENE: Then we'll swap them back so \n"
    .string "everyone can keep their own.\p"
    .string "ILJA: Want to join us?$"

Ludwigshafen_Text_TradeEvoChoose:
    .string "Pick the HAUNTER you want to evolve.$"

Ludwigshafen_Text_TradeEvoAfter:
    .string "Nice! That trade vibe did the trick!\n"
    .string "Your HAUNTER evolved into GENGAR!$"
    
Ludwigshafen_Text_TradeEvoWrongMon:
    .string "That isn't an HAUNTER.\n"
    .string "Pick a different Pokémon.$"

Ludwigshafen_Text_TradeEvoIsEgg:
    .string "That's an Egg. That won't work.$"

Ludwigshafen_Text_TradeEvoEverstone:
    .string "It's holding an Everstone.\n"
    .string "That blocks the evolution!$"

Ludwigshafen_Text_TradeEvoNoItem:
    .string "It needs to hold a specific item\n"
    .string "for this evolution.$"


Ludwigshafen_Text_GiftHaunterOffer:
    .string "Hey! I found a spooky Pokémon.\n"
    .string "Do you want this HAUNTER?$"

Ludwigshafen_Text_GiftHaunterGive:
    .string "Alright! Take good care of it.$"

Ludwigshafen_Text_GiftHaunterAfter:
    .string "If you ever trade it, something\n"
    .string "interesting might happen...$"

Ludwigshafen_Text_GiftHaunterPartyFull:
    .string "Your party is full.\n"
    .string "Make room first!$"

Ludwigshafen_Text_GiftHaunterAlreadyDone:
    .string "How's that HAUNTER doing?$"






@ =========================================================
@ Debug Haunter flag


Ludwigshafen_EventScript_DebugGiftFlagToggle::
    lock
    faceplayer

    checkflag FLAG_LUDWIGSHAFEN_GOT_HAUNTER_GIFT
    goto_if_eq VAR_RESULT, TRUE, Ludwigshafen_Debug_FlagIsSet

Ludwigshafen_Debug_FlagIsNotSet:
    msgbox Ludwigshafen_Text_Debug_NotSet, MSGBOX_DEFAULT
    setflag FLAG_LUDWIGSHAFEN_GOT_HAUNTER_GIFT
    release
    end

Ludwigshafen_Debug_FlagIsSet:
    msgbox Ludwigshafen_Text_Debug_IsSet, MSGBOX_DEFAULT
    clearflag FLAG_LUDWIGSHAFEN_GOT_HAUNTER_GIFT
    release
    end

Ludwigshafen_Text_Debug_NotSet:
    .string "DEBUG: Flag ist NICHT gesetzt.\nIch setze sie jetzt.$"
Ludwigshafen_Text_Debug_IsSet:
    .string "DEBUG: Flag ist gesetzt.\nIch loesche sie jetzt.$"


