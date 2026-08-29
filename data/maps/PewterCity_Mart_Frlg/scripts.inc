PewterCity_Mart_Frlg_MapScripts::
    .byte 0


PewterCity_Mart_Frlg_EventScript_Clerk::
    lock
    faceplayer
    message gText_HowMayIServeYou
    waitmessage
    pokemart PewterCity_Mart_Frlg_Pokemart
    msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
    release
    end


    .align 2
PewterCity_Mart_Frlg_Pokemart:
    .2byte ITEM_POKE_BALL
    .2byte ITEM_POTION
    .2byte ITEM_ANTIDOTE
    .2byte ITEM_PARALYZE_HEAL
    .2byte ITEM_BURN_HEAL
    .2byte ITEM_ICE_HEAL
    .2byte ITEM_AWAKENING
    .2byte ITEM_ESCAPE_ROPE
    pokemartlistend


PewterCity_Mart_Frlg_EventScript_Youngster::
    lock
    faceplayer
    msgbox PewterCity_Mart_Frlg_Text_Youngster, MSGBOX_DEFAULT
    release
    end


PewterCity_Mart_Frlg_EventScript_Boy::
    lock
    faceplayer
    msgbox PewterCity_Mart_Frlg_Text_Boy, MSGBOX_DEFAULT
    release
    end


PewterCity_Mart_Frlg_Text_Youngster:
    .string "Tourists buy POTIONS.\p"
    .string "Locals buy REPELS.\p"
    .string "The museum crowd wanders into\n"
    .string "everything.$"


PewterCity_Mart_Frlg_Text_Boy:
    .string "I came in for one thing.\p"
    .string "I forgot what it was.\p"
    .string "...So now I'm buying POKE BALLS.$"
