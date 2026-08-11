OOSS_MapScripts::
    map_script MAP_SCRIPT_ON_TRANSITION, OOSS_OnTransition
    .byte 0

OOSS_OnTransition:
    setvar VAR_OBJ_GFX_ID_2, OBJ_EVENT_GFX_SPECIES_SHINY(GLOOM)
    end

OOSS_EventScript_ShinyGloom::
    msgbox OOSS_Text_ShinyGloom, MSGBOX_DEFAULT
    goto InteractWithOverworldWildEncounter

OOSS_Text_ShinyGloom:
    .string "This GLOOM looks...\n"
    .string "different.$"