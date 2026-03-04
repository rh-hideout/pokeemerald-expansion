Bridgeroom_MapScripts::
    map_script MAP_SCRIPT_ON_LOAD,       Bridgeroom_OnLoad
    map_script MAP_SCRIPT_ON_TRANSITION, Bridgeroom_OnTransition
    .byte 0

Bridgeroom_OnLoad:
    call Bridgeroom_ApplyBridgeIfFlagSet
    end

Bridgeroom_OnTransition:
    call Bridgeroom_ApplyBridgeIfFlagSet
    end

Bridgeroom_ApplyBridgeIfFlagSet:
    goto_if_unset FLAG_FLAG8_BRIDGE_SET, .LBridgeroom_NoBridge
    call Bridgeroom_SetBridgeMetatiles
    special DrawWholeMapView
.LBridgeroom_NoBridge:
    return


Bridgeroom_SetBridgeMetatiles:
    @ Row y = 4
    setmetatile  5, 4, 0x261, FALSE
    setmetatile  6, 4, 0x261, FALSE
    setmetatile  7, 4, 0x261, FALSE
    setmetatile  8, 4, 0x261, FALSE
    setmetatile  9, 4, 0x261, FALSE

    @ Row y = 5
    setmetatile  5, 5, 0x269, FALSE
    setmetatile  6, 5, 0x269, FALSE
    setmetatile  7, 5, 0x269, FALSE
    setmetatile  8, 5, 0x269, FALSE
    setmetatile  9, 5, 0x269, FALSE
    return

Bridgeroom_EventScript_HintNPC::
    lock
    faceplayer
    msgbox Bridgeroom_Text_HintNPC_1, MSGBOX_DEFAULT
    msgbox Bridgeroom_Text_HintNPC_2, MSGBOX_DEFAULT
    release
    end

Bridgeroom_EventScript_Terminal::
    lock
    faceplayer

    setflag FLAG_FLAG8_BRIDGE_SET
    goto_if_set FLAG_FLAG8_BRIDGE_SET, Bridgeroom_Terminal_FlagSet

    msgbox Bridgeroom_Text_Terminal_Intro, MSGBOX_DEFAULT
    release
    end


Bridgeroom_Terminal_FlagSet:
    call Bridgeroom_SetBridgeMetatiles
    special DrawWholeMapView
    msgbox Bridgeroom_Text_Terminal_FlagSet, MSGBOX_DEFAULT
    release
    end


Bridgeroom_Text_HintNPC_1:
    .string "This plateau used to have a bridge.\n"
    .string "It only appears if a single story flag\n"
    .string "inside the save data is set.$"

Bridgeroom_Text_HintNPC_2:
    .string "If you edited the save but nothing changes,\n"
    .string "you likely patched the wrong save copy,\n"
    .string "or broke a section checksum.\n"
    .string "The game will quietly load the other copy.$"

Bridgeroom_Text_Terminal_Intro:
    .string "BRIDGE CONTROL TERMINAL\n"
    .string "Access: OFFLINE\n"
    .string "\n"
    .string "Note: This bridge is not activated in-game.\n"
    .string "It requires a valid save-state patch.$"

Bridgeroom_Text_Terminal_SaveBlocks:
    .string "Gen-III saves keep TWO game-save blocks.\n"
    .string "Only the one with the higher SAVE INDEX\n"
    .string "is considered the newest.\n"
    .string "\n"
    .string "If your edit is ignored, you may have\n"
    .string "patched the older block.$"

Bridgeroom_Text_Terminal_Sections:
    .string "Each block is split into 4KB SECTIONS.\n"
    .string "At the end of every section you can find:\n"
    .string "- Section ID\n"
    .string "- Checksum\n"
    .string "- Signature (bytes: 25 20 01 08)\n"
    .string "- Save Index\n"
    .string "\n"
    .string "Find the right section, then patch safely.$"

Bridgeroom_Text_Terminal_Checksum:
    .string "Warning: Section checksums must match.\n"
    .string "Changing even one byte without updating\n"
    .string "the checksum will invalidate that section.\n"
    .string "\n"
    .string "Tip: Flags are bit-packed (8 flags per byte).\n"
    .string "Know your flag ID, then set the correct bit.$"

Bridgeroom_Text_Terminal_FlagSet:
    .string "Status: AUTHORIZED\n"
    .string "Bridge tiles deployed.\n"
    .string "\n"
    .string "If you can read this, your patched save\n"
    .string "was accepted by the game.$"
