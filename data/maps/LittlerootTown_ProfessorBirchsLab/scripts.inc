LittlerootTown_ProfessorBirchsLab_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_ProfessorBirchsLab_OnTransition
	.byte 0

@ The slice deliberately exposes only the three Habitat frames.  Vanilla lab
@ callbacks, humans, reward events, and unapproved background interactions
@ are absent from the map registrations until they have an approved role.
LittlerootTown_ProfessorBirchsLab_OnTransition:
	special Habitat_PrepareLabFrames
	end

@ This symbol is referenced by the generic step-call dispatcher.  It is not
@ reachable in the Habitat slice, but remains a neutral no-op so the shared
@ dispatcher links without restoring its unapproved player-facing prose.
LittlerootTown_ProfessorBirchsLab_EventScript_ScottAboardSSTidalCall::
	end

@ This shared Professor Birch script is called from data/scripts/prof_birch.inc.
@ Keep its link-time entry point without resurrecting vanilla registration
@ dialogue in the Habitat slice.
EventScript_RegisterProfBirch::
	end

@ Per-frame background wrappers preserve dormant-frame inspection. Once a
@ resident manifests, its object event takes interaction priority.
BirchsLab_EventScript_HabitatFrameTorchic::
	setvar VAR_0x8004, 7
	goto HabitatSpot_EventScript_InspectById

BirchsLab_EventScript_HabitatFrameTreecko::
	setvar VAR_0x8004, 8
	goto HabitatSpot_EventScript_InspectById

BirchsLab_EventScript_HabitatFrameMudkip::
	setvar VAR_0x8004, 9
	goto HabitatSpot_EventScript_InspectById
