FuchsiaCity_WardensHouse_Frlg_MapScripts::
    .byte 0


FuchsiaCity_WardensHouse_Frlg_EventScript_Warden::
    lock
    faceplayer
    msgbox FuchsiaCity_WardensHouse_Frlg_Text_Warden, MSGBOX_DEFAULT
    release
    end


FuchsiaCity_WardensHouse_Frlg_EventScript_FireStone::
    lock
    giveitem ITEM_FIRE_STONE
    goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
    setflag FLAG_ITEM_FUCHSIA_WARDEN_FIRE_STONE
    removeobject LOCALID_FUCHSIA_WARDEN_FIRE_STONE
    release
    end


FuchsiaCity_WardensHouse_Frlg_Text_Warden:
    .string "WARDEN: Ah! A visitor!\p"
    .string "Make yourself at home.\p"
    .string "And if you find anything lying\n"
    .string "around, it's probably been there\n"
    .string "longer than I remember.$"
