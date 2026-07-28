HardRockCafe_MapScripts::
    map_script MAP_SCRIPT_ON_LOAD, HardRockCafe_SetCounterpartGraphics
    .byte 0

HardRockCafe_SetCounterpartGraphics:
    goto_if_eq VAR_COUNTERPART_ID, COUNTERPART_BRENDAN, HardRockCafe_SetBrendan
    goto_if_eq VAR_COUNTERPART_ID, COUNTERPART_MAY, HardRockCafe_SetMay
    goto_if_eq VAR_COUNTERPART_ID, COUNTERPART_LEXY, HardRockCafe_SetLexy
    goto_if_eq VAR_COUNTERPART_ID, COUNTERPART_JUSTIN, HardRockCafe_SetJustin
    goto_if_eq VAR_COUNTERPART_ID, COUNTERPART_MAAM, HardRockCafe_SetMaam
    goto_if_eq VAR_COUNTERPART_ID, COUNTERPART_SIR, HardRockCafe_SetSir
    end

HardRockCafe_SetBrendan:
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_BRENDAN_NORMAL
    end

HardRockCafe_SetMay:
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_MAY_NORMAL
    end

HardRockCafe_SetLexy:
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_LEXY_NORMAL
    end

HardRockCafe_SetJustin:
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_JUSTIN_NORMAL
    end

HardRockCafe_SetMaam:
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_MAAM_NORMAL
    end

HardRockCafe_SetSir:
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SIR_NORMAL
    end
