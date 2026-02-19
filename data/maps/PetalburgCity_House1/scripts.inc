PetalburgCity_House1_MapScripts::
	.byte 0

PetalburgCity_House1_EventScript_Man::
	msgbox PetalburgCity_House1_Text_TravelingIsWonderful, MSGBOX_NPC
	end

    .include "constants/global.inc"




PetalburgCity_House1_EventScript_ZigzagoonForSecretPhoto::
    lock
    faceplayer

    goto_if_set FLAG_CTF_PETALBURG_HOUSE1_SECRET_PHOTO, PetalburgCity_House1_ZigzagoonForSecretPhoto_AlreadyDone

    msgbox PetalburgCity_House1_Text_Offer, MSGBOX_YESNO
    goto_if_eq VAR_RESULT, NO, PetalburgCity_House1_ZigzagoonForSecretPhoto_Cancel

    checkitemspace ITEM_SECRET_PHOTO, 1
    goto_if_eq VAR_RESULT, 0, PetalburgCity_House1_ZigzagoonForSecretPhoto_BagFull

    getpartysize
    goto_if_eq VAR_RESULT, 0, PetalburgCity_House1_ZigzagoonForSecretPhoto_NoPokemon

PetalburgCity_House1_ZigzagoonForSecretPhoto_ChooseMon:
    msgbox PetalburgCity_House1_Text_Choose, MSGBOX_DEFAULT

    special ChoosePartyMon
    waitstate
    goto_if_ge VAR_0x8004, PARTY_SIZE, PetalburgCity_House1_ZigzagoonForSecretPhoto_Cancel

    specialvar VAR_RESULT, ScriptGetPartyMonSpecies
    goto_if_ne VAR_RESULT, SPECIES_ZIGZAGOON, PetalburgCity_House1_ZigzagoonForSecretPhoto_WrongMon

    special Special_TakeChosenPartyMon

    msgbox PetalburgCity_House1_Text_Thanks, MSGBOX_DEFAULT
    giveitem ITEM_SECRET_PHOTO, 1

    setflag FLAG_CTF_PETALBURG_HOUSE1_SECRET_PHOTO
    msgbox PetalburgCity_House1_Text_Done, MSGBOX_DEFAULT
    release
    end


PetalburgCity_House1_ZigzagoonForSecretPhoto_WrongMon:
    msgbox PetalburgCity_House1_Text_WrongMon, MSGBOX_DEFAULT
    goto PetalburgCity_House1_ZigzagoonForSecretPhoto_ChooseMon

PetalburgCity_House1_ZigzagoonForSecretPhoto_BagFull:
    msgbox PetalburgCity_House1_Text_BagFull, MSGBOX_DEFAULT
    release
    end

PetalburgCity_House1_ZigzagoonForSecretPhoto_NoPokemon:
    msgbox PetalburgCity_House1_Text_NoPokemon, MSGBOX_DEFAULT
    release
    end

PetalburgCity_House1_ZigzagoonForSecretPhoto_AlreadyDone:
    msgbox PetalburgCity_House1_Text_AlreadyDone, MSGBOX_DEFAULT
    release
    end

PetalburgCity_House1_ZigzagoonForSecretPhoto_Cancel:
    msgbox PetalburgCity_House1_Text_Cancel, MSGBOX_DEFAULT
    release
    end


PetalburgCity_House1_EventScript_GiftZigzagoon::
    lock
    faceplayer

    goto_if_set FLAG_CTF_PETALBURG_HOUSE1_GOT_ZIGZAGOON, PetalburgCity_House1_Text_Gifter_After

    getpartysize
    goto_if_ge VAR_RESULT, PARTY_SIZE, PetalburgCity_House1_Text_Gifter_PartyFull

    msgbox PetalburgCity_House1_Text_Gifter_Intro, MSGBOX_DEFAULT
    closemessage

    givemon SPECIES_ZIGZAGOON, 5

    setflag FLAG_CTF_PETALBURG_HOUSE1_GOT_ZIGZAGOON
    msgbox PetalburgCity_House1_Text_Gifter_Given, MSGBOX_DEFAULT
    release
    end

PetalburgCity_House1_Text_Gifter_PartyFull:
    msgbox PetalburgCity_House1_Text_Gifter_PartyFullText, MSGBOX_DEFAULT
    release
    end


PetalburgCity_House1_Text_Gifter_Intro:
    .string "Hey!\n"
    .string "You look like you could use a\n"
    .string "reliable little runner.\p"
    .string "Take this ZIGZAGOON - consider it\n"
    .string "a starter tool for your journey.$"

PetalburgCity_House1_Text_Gifter_Given:
    .string "ZIGZAGOON joined your team!\n"
    .string "Treat it well - it will pay you\n"
    .string "back in surprises.$"

PetalburgCity_House1_Text_Gifter_PartyFullText:
    .string "Your party is full.\n"
    .string "Make room and talk to me again.$"

PetalburgCity_House1_Text_Gifter_After:
    .string "Use that ZIGZAGOON wisely.\n"
    .string "Sometimes the smallest tools open\n"
    .string "the biggest doors.$"


PetalburgCity_House1_Text_Offer:
	.string "Psst... I collect ZIGZAGOON! If\n"
	.string "you give me one, you'll get this\p"
	.string "photo I found at the last\n"
	.string "BLACKHANSA parade.$"

PetalburgCity_House1_Text_Choose:
	.string "Which ZIGZAGOON would you like to\n"
	.string "give me?$"

PetalburgCity_House1_Text_WrongMon:
	.string "Hmm... that's not a ZIGZAGOON. It\n"
	.string "has to be a ZIGZAGOON!$"

PetalburgCity_House1_Text_Thanks:
	.string "Ohh, perfect! That's exactly what\n"
	.string "I was looking for!$"

PetalburgCity_House1_Text_Done:
	.string "Here is the PHOTO.$"

PetalburgCity_House1_Text_BagFull:
    .string "Your bag is full.\n"
    .string "Make some space first.$"

PetalburgCity_House1_Text_NoPokemon:
    .string "You don't have any POKéMON$"

PetalburgCity_House1_Text_AlreadyDone:
    .string "Thanks, I have enough for now.$"

PetalburgCity_House1_Text_Cancel:
    .string "Okay, maybe later.$"





PetalburgCity_House1_Text_TravelingIsWonderful:
	.string "Did you know that the BLACKHANSA\n"
	.string "BOSS likes to travel? He has \p"
	.string "three favorite destinations that\n"
	.string "he visits again and again. But\p"
	.string "he keeps the exact locations to\n"
	.string "himself.$"


