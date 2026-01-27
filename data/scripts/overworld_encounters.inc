InteractWithDynamicWildOverworldEncounterInstant::
    lockall
    goto InteractWithDynamicWildOverworldEncounter

InteractWithDynamicWildOverworldEncounterApproach::
    lock
    callnative OWE_ApproachForBattle
    waitstate
InteractWithDynamicWildOverworldEncounter:
    applymovement VAR_LAST_TALKED, Common_Movement_ExclamationMark
    callnative ScriptFaceLastTalked
    playmoncry VAR_0x8004, CRY_MODE_DOUBLES
    waitmoncry
    special CreateOverworldWildEncounter
    waitstate
    end

