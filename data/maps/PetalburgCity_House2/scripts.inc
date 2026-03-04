PetalburgCity_House2_MapScripts::
	.byte 0

PetalburgCity_House2_EventScript_Woman::
	msgbox PetalburgCity_House2_Text_NormanBecameGymLeader, MSGBOX_NPC
	end


PetalburgCity_House2_EventScript_LockpickGuy::
    lock
    faceplayer

    goto_if_set FLAG_RECEIVED_LOCKPICK_SET, PetalburgCity_House2_LockpickGuy_After

    msgbox PetalburgCity_House2_Text_Intro, MSGBOX_DEFAULT

    @ 1. Frage: Locksport interessiert?
    msgbox PetalburgCity_House2_Text_AskInterest, MSGBOX_YESNO
    compare VAR_RESULT, 1
    goto_if_eq PetalburgCity_House2_LockpickGuy_InterestYes

PetalburgCity_House2_LockpickGuy_InterestNo:
    msgbox PetalburgCity_House2_Text_InterestNo, MSGBOX_DEFAULT
    release
    end

PetalburgCity_House2_LockpickGuy_InterestYes:
    @ 2. Frage: Lockpickset zum Ausprobieren?
    msgbox PetalburgCity_House2_Text_AskSet, MSGBOX_YESNO
    compare VAR_RESULT, 1
    goto_if_eq PetalburgCity_House2_LockpickGuy_GiveSet

PetalburgCity_House2_LockpickGuy_SetNo:
    msgbox PetalburgCity_House2_Text_SetNo, MSGBOX_DEFAULT
    release
    end

PetalburgCity_House2_LockpickGuy_GiveSet:
    msgbox PetalburgCity_House2_Text_SetYes, MSGBOX_DEFAULT

    giveitem ITEM_LOCKPICK_SET, 1
    compare VAR_RESULT, 0
    goto_if_eq PetalburgCity_House2_LockpickGuy_BagFull

    setflag FLAG_RECEIVED_LOCKPICK_SET
    release
    end

PetalburgCity_House2_LockpickGuy_BagFull:
    msgbox PetalburgCity_House2_Text_BagFull, MSGBOX_DEFAULT
    release
    end

PetalburgCity_House2_LockpickGuy_After:
    msgbox PetalburgCity_House2_Text_After, MSGBOX_DEFAULT
    release
    end




PetalburgCity_House2_Text_Intro:
    .string "Hey! Nice to see a curious mind.$"

PetalburgCity_House2_Text_AskInterest:
    .string "Are you interested in LOCKSPORT?$"

PetalburgCity_House2_Text_InterestNo:
    .string "Oh well then not.$"

PetalburgCity_House2_Text_AskSet:
    .string "Want a LOCKPICK SET to try it out?$"

PetalburgCity_House2_Text_SetNo:
    .string "That's too bad, it's a fun sport.$"

PetalburgCity_House2_Text_SetYes:
    .string "Nice! Here you go. Have this LOCKPICK SET!$"

PetalburgCity_House2_Text_BagFull:
    .string "Your BAG is full. Come back after making space.$"

PetalburgCity_House2_Text_After:
    .string "How's locksport going? Stay safe and have fun.$"


PetalburgCity_House2_Text_NormanBecameGymLeader:
	.string "My husband is the IT manager at\n"
	.string "Blackhansa. He also solves all the\p"
	.string "computer problems for our family\n"
	.string "and friends. He's so helpful!$"


