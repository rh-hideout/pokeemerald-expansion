@##################################################################
@ Surf
@##################################################################

EventScript_UseSurf::
    checkfieldmove FIELD_MOVE_SURF
    copyvar VAR_0x8004, VAR_RESULT
    goto_if_eq VAR_0x8004, PARTY_SIZE, EventScript_EndUseSurf @ On failure, jump to message
    goto_if_eq VAR_0x8004, PARTY_SIZE + 1, EventScript_UseSurfWithItem

    @ --- Pokémon logic ---
    bufferpartymonnick STR_VAR_1, VAR_0x8004
    setfieldeffectargument 0, VAR_0x8004
    lockall
    msgbox gText_WantToSurfWithPokemon, MSGBOX_YESNO
    goto_if_eq VAR_RESULT, NO, EventScript_ReleaseUseSurf
    msgbox gText_MonHelpedSurf, MSGBOX_DEFAULT
    dofieldeffect FLDEFF_USE_SURF
    goto EventScript_ReleaseUseSurf

EventScript_UseSurfWithItem::
    @ --- Item logic ---
    bufferitemname STR_VAR_2, ITEM_SURF_TOOL
    setfieldeffectargument 0, PARTY_SIZE
    lockall
    msgbox gText_WantToSurfWithItem, MSGBOX_YESNO
    goto_if_eq VAR_RESULT, NO, EventScript_ReleaseUseSurf
    msgbox gText_PlayerUsedSurfItem, MSGBOX_DEFAULT
    setfieldeffectargument 1, TRUE
    dofieldeffect FLDEFF_USE_SURF
    goto EventScript_ReleaseUseSurf

EventScript_ReleaseUseSurf::
	releaseall
EventScript_EndUseSurf::
	end
