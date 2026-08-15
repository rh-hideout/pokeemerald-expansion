CeruleanCity_Mart_Frlg_MapScripts::
    .byte 0


CeruleanCity_Mart_Frlg_EventScript_Clerk::
    lock
    faceplayer
    message gText_HowMayIServeYou
    waitmessage
    pokemart CeruleanCity_Mart_Frlg_Pokemart
    msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
    release
    end


    .align 2
CeruleanCity_Mart_Frlg_Pokemart:
    .2byte ITEM_POKE_BALL
    .2byte ITEM_POTION
    .2byte ITEM_ANTIDOTE
    .2byte ITEM_PARALYZE_HEAL
    .2byte ITEM_BURN_HEAL
    .2byte ITEM_ICE_HEAL
    .2byte ITEM_AWAKENING
    .2byte ITEM_ESCAPE_ROPE
    pokemartlistend


CeruleanCity_Mart_Frlg_EventScript_NpcPlaceholder::
    end


@ CERULEAN CUSTOM NPC CLEANUP

CeruleanCity_Mart_Frlg_EventScript_Woman::
    lock
    faceplayer
    msgbox CeruleanCity_Mart_Frlg_Text_Woman, MSGBOX_DEFAULT
    release
    end

CeruleanCity_Mart_Frlg_Text_Woman:
    .string "I always buy more than I came in\n"
    .string "here for.\p"
    .string "Every single time.$"

CeruleanCity_Mart_Frlg_EventScript_Youngster::
    lock
    faceplayer
    msgbox CeruleanCity_Mart_Frlg_Text_Youngster, MSGBOX_DEFAULT
    release
    end

CeruleanCity_Mart_Frlg_Text_Youngster:
    .string "I spent all my money on supplies.\p"
    .string "...Probably should've saved some.$"

