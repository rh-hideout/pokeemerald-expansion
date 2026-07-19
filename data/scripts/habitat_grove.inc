@ Grove-side interaction: plot markers and worker display objects
@ (Littleroot placeholder map). Placeholder prose in the §7 register.
HabitatGrove_EventScript_Plot::
	lock
	specialvar VAR_RESULT, Habitat_OnInspectPlot
	switch VAR_RESULT
	case 1, HabitatGrove_EventScript_PlotGrowing
	case 2, HabitatGrove_EventScript_PlotMature
	msgbox HabitatGrove_Text_PlotUntended, MSGBOX_DEFAULT
	release
	end

HabitatGrove_EventScript_PlotGrowing::
	msgbox HabitatGrove_Text_PlotGrowing, MSGBOX_DEFAULT
	release
	end

HabitatGrove_EventScript_PlotMature::
	msgbox HabitatGrove_Text_PlotMature, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, HabitatGrove_EventScript_LeavePlot
	specialvar VAR_RESULT, Habitat_TryHarvestPlot
	goto_if_eq VAR_RESULT, 0, HabitatGrove_EventScript_HarvestFailed
	msgbox HabitatGrove_Text_Harvested, MSGBOX_DEFAULT
	release
	end

HabitatGrove_EventScript_HarvestFailed::
	msgbox HabitatGrove_Text_HarvestFailed, MSGBOX_DEFAULT
	release
	end

HabitatGrove_EventScript_LeavePlot::
	release
	end

HabitatGrove_EventScript_Worker::
	lock
	faceplayer
	specialvar VAR_RESULT, Habitat_OnTalkWorker
	goto_if_eq VAR_RESULT, FALSE, HabitatGrove_EventScript_WorkerConfused
	msgbox HabitatGrove_Text_WorkerStatus, MSGBOX_DEFAULT
	msgbox HabitatGrove_Text_RestPrompt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, HabitatGrove_EventScript_WorkerStays
	special Habitat_SendTalkedWorkerHome
	msgbox HabitatGrove_Text_WentHome, MSGBOX_DEFAULT
	release
	end

HabitatGrove_EventScript_WorkerStays::
	release
	end

HabitatGrove_EventScript_WorkerConfused::
	msgbox HabitatGrove_Text_WorkerConfused, MSGBOX_DEFAULT
	release
	end

HabitatGrove_Text_PlotUntended:
	.string "Untended soil. It waits without\n"
	.string "impatience. (PLACEHOLDER)$"

HabitatGrove_Text_PlotGrowing:
	.string "Growing: {STR_VAR_1}, stage {STR_VAR_2}.\n"
	.string "(PLACEHOLDER: quiet green work)$"

HabitatGrove_Text_PlotMature:
	.string "Ready: {STR_VAR_1}. Gather them?\n"
	.string "(PLACEHOLDER)$"

HabitatGrove_Text_Harvested:
	.string "HARVEST! {STR_VAR_2} {STR_VAR_1}(s).\n"
	.string "(PLACEHOLDER)$"

HabitatGrove_Text_HarvestFailed:
	.string "Your bag disagrees. (PLACEHOLDER:\n"
	.string "bag full; harvest stays)$"

HabitatGrove_Text_WorkerStatus:
	.string "{STR_VAR_1} hums over the {STR_VAR_2}\n"
	.string "plot. (PLACEHOLDER: species voice)$"

HabitatGrove_Text_RestPrompt:
	.string "Does it want to head home?\n"
	.string "(PLACEHOLDER)$"

HabitatGrove_Text_WentHome:
	.string "HOMEWARD. It pads back to its\n"
	.string "place. (PLACEHOLDER)$"

HabitatGrove_Text_WorkerConfused:
	.string "It blinks at you. (PLACEHOLDER:\n"
	.string "unresolved worker)$"
