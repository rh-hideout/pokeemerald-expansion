@ Shared interaction script for every habitat spot object (spec §2 staged
@ hints + verbs). Habitat_OnInspectSpot expands the state-appropriate hint
@ into gStringVar4 (pre-expanded — displaying gStringVar4 re-expands it in
@ place, so it must arrive expansion-clean) and returns the state in
@ VAR_RESULT. ACTIVE spots then get the OFFER and PLACE verbs. All prose
@ here is engine placeholder; the verb UX (yes/no chains, berry-bag reuse)
@ is slice scaffolding for Jay to react to.
@ Entry for bg signs (dormant/stirring spots have no object): the map's
@ per-spot wrapper set VAR_0x8004 = spotId before jumping here.
HabitatSpot_EventScript_InspectById::
	lock
	special Habitat_OnInspectSpotById
	goto HabitatSpot_EventScript_Dispatch

@ Entry for the spot's object event (the manifested Pokémon).
HabitatSpot_EventScript_Interact::
	lock
	faceplayer
	special Habitat_OnInspectSpot
HabitatSpot_EventScript_Dispatch::
	switch VAR_RESULT
	case HABITAT_STATE_ACTIVE, HabitatSpot_EventScript_Active
	case HABITAT_STATE_BEFRIENDED, HabitatSpot_EventScript_Ambient
	case HABITAT_INSPECT_NOT_A_SPOT, HabitatSpot_EventScript_NotASpot
	msgbox gStringVar4, MSGBOX_DEFAULT
	specialvar VAR_RESULT, Habitat_PreviewPlaceItem
	goto_if_eq VAR_RESULT, TRUE, HabitatSpot_EventScript_PlacePrompt
	release
	end

HabitatSpot_EventScript_PlacePrompt::
	msgbox HabitatSpot_Text_PlacePrompt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, HabitatSpot_EventScript_Place
	release
	end

HabitatSpot_EventScript_Active::
	msgbox gStringVar4, MSGBOX_DEFAULT
	specialvar VAR_RESULT, Habitat_PreviewOfferItem
	goto_if_eq VAR_RESULT, TRUE, HabitatSpot_EventScript_OfferPrompt
	specialvar VAR_RESULT, Habitat_PreviewPlaceItem
	goto_if_eq VAR_RESULT, TRUE, HabitatSpot_EventScript_PlacePrompt
	release
	end

HabitatSpot_EventScript_OfferPrompt::
	msgbox HabitatSpot_Text_OfferPrompt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, HabitatSpot_EventScript_Offer
	specialvar VAR_RESULT, Habitat_PreviewPlaceItem
	goto_if_eq VAR_RESULT, TRUE, HabitatSpot_EventScript_PlacePrompt
	release
	end

HabitatSpot_EventScript_Offer::
	specialvar VAR_RESULT, Habitat_TryOffer
	goto_if_eq VAR_RESULT, TRUE, HabitatSpot_EventScript_Befriended
	msgbox HabitatSpot_Text_OfferRejected, MSGBOX_DEFAULT
	release
	end

HabitatSpot_EventScript_Befriended::
	msgbox HabitatSpot_Text_Befriended, MSGBOX_DEFAULT
	release
	end

HabitatSpot_EventScript_Place::
	specialvar VAR_RESULT, Habitat_TryPlaceItem
	goto_if_eq VAR_RESULT, TRUE, HabitatSpot_EventScript_Placed
	msgbox HabitatSpot_Text_NothingToPlace, MSGBOX_DEFAULT
	release
	end

HabitatSpot_EventScript_Placed::
	msgbox HabitatSpot_Text_Placed, MSGBOX_DEFAULT
	release
	end

HabitatSpot_EventScript_Leave::
	release
	end

HabitatSpot_EventScript_Ambient::
	msgbox HabitatSpot_Text_Ambient, MSGBOX_DEFAULT
	specialvar VAR_RESULT, Habitat_GetInteractionAvailableVerbs
	goto_if_eq VAR_RESULT, 9, HabitatSpot_EventScript_RecruitPrompt
	release
	end

HabitatSpot_EventScript_RecruitPrompt::
	msgbox HabitatSpot_Text_RecruitPrompt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, HabitatSpot_EventScript_Leave
	specialvar VAR_RESULT, Habitat_CanRecruitToGrove
	goto_if_eq VAR_RESULT, 1, HabitatSpot_EventScript_Recruited
	goto_if_eq VAR_RESULT, 2, HabitatSpot_EventScript_GroveFull
	msgbox HabitatSpot_Text_CannotCome, MSGBOX_DEFAULT
	release
	end

HabitatSpot_EventScript_Recruited::
	msgbox HabitatSpot_Text_Recruited, MSGBOX_DEFAULT
	closemessage
	release
	special Habitat_TryRecruitToGrove
	end

HabitatSpot_EventScript_GroveFull::
	msgbox HabitatSpot_Text_GroveFull, MSGBOX_DEFAULT
	release
	end

HabitatSpot_EventScript_NotASpot::
	msgbox HabitatSpot_Text_NotASpot, MSGBOX_DEFAULT
	release
	end

HabitatSpot_Text_OfferPrompt:
	.string "Offer {STR_VAR_2} {STR_VAR_1}?$"

HabitatSpot_Text_PlacePrompt:
	.string "Set down {STR_VAR_2} {STR_VAR_1}?$"

HabitatSpot_Text_OfferRejected:
	.string "It is not moved. (PLACEHOLDER;\n"
	.string "wrong offering; berry kept)$"

HabitatSpot_Text_Befriended:
	.string "BEFRIENDED! PLACEHOLDER: it will\n"
	.string "remember this. (resident soon)$"

HabitatSpot_Text_NothingToPlace:
	.string "Nothing you carry fits this\n"
	.string "place. (PLACEHOLDER)$"

HabitatSpot_Text_Placed:
	.string "SET DOWN! PLACEHOLDER: it is\n"
	.string "arranged just so.$"

HabitatSpot_Text_RecruitPrompt:
	.string "Ask it to come tend the Grove?\n"
	.string "(PLACEHOLDER)$"

HabitatSpot_Text_Recruited:
	.string "GROVE-BOUND! {STR_VAR_1} pads off\n"
	.string "toward the Grove. (PLACEHOLDER)$"

HabitatSpot_Text_GroveFull:
	.string "The Grove feels full today.\n"
	.string "(PLACEHOLDER: six-out cap)$"

HabitatSpot_Text_CannotCome:
	.string "It settles deeper where it is.\n"
	.string "(PLACEHOLDER: cannot come)$"

HabitatSpot_Text_Ambient:
	.string "PLACEHOLDER: it seems content near\n"
	.string "you. (befriended ambient)$"

HabitatSpot_Text_NotASpot:
	.string "PLACEHOLDER: nothing habitat-shaped\n"
	.string "about this. (unbound object)$"
