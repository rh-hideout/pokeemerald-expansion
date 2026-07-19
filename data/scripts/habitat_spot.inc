@ Shared interaction script for every habitat spot object (spec §2 staged
@ hints). Habitat_OnInspectSpot expands the state-appropriate hint into
@ gStringVar4 (placeholders already resolved — displaying gStringVar4
@ re-expands it, so it must arrive expansion-clean) and returns the state
@ in VAR_RESULT. Placeholder ambient text below is engine-side filler.
HabitatSpot_EventScript_Interact::
	lock
	faceplayer
	special Habitat_OnInspectSpot
	switch VAR_RESULT
	case HABITAT_STATE_ACTIVE, HabitatSpot_EventScript_Active
	case HABITAT_STATE_BEFRIENDED, HabitatSpot_EventScript_Ambient
	case HABITAT_INSPECT_NOT_A_SPOT, HabitatSpot_EventScript_NotASpot
	msgbox gStringVar4, MSGBOX_DEFAULT
	release
	end

HabitatSpot_EventScript_Active::
	msgbox gStringVar4, MSGBOX_DEFAULT
	release
	end

HabitatSpot_EventScript_Ambient::
	msgbox HabitatSpot_Text_Ambient, MSGBOX_DEFAULT
	release
	end

HabitatSpot_EventScript_NotASpot::
	msgbox HabitatSpot_Text_NotASpot, MSGBOX_DEFAULT
	release
	end

HabitatSpot_Text_Ambient:
	.string "PLACEHOLDER: it seems content near\n"
	.string "you. (befriended ambient)$"

HabitatSpot_Text_NotASpot:
	.string "PLACEHOLDER: nothing habitat-shaped\n"
	.string "about this. (unbound object)$"
