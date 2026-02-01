EventScript_UseSurf::
	goto_if_unset FLAG_BADGE05_GET, EventScript_EndUseSurf
	buffermovename STR_VAR_2, MOVE_SURF
	checkfieldmove FIELD_MOVE_SURF
	call_if_eq VAR_RESULT, PARTY_SIZE, EventScript_CheckSecretPowerSurf
	bufferpartymonnick STR_VAR_1, VAR_RESULT
	setfieldeffectargument 0, VAR_RESULT
	lockall
	msgbox Text_MonUsedFieldMove, MSGBOX_DEFAULT
	dofieldeffect FLDEFF_USE_SURF
EventScript_ReleaseUseSurf::
	releaseall
EventScript_EndUseSurf::
	end

EventScript_CheckSecretPowerSurf::
	buffermovename STR_VAR_2, MOVE_SECRET_POWER
	checkfieldmove FIELD_MOVE_SECRET_POWER, TRUE
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_EndUseSurf
	return
