TrainerHill_4F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, TrainerHill_OnResume
	map_script MAP_SCRIPT_ON_FRAME_TABLE, TrainerHill_OnFrame
	map_script MAP_SCRIPT_ON_LOAD, TrainerHill_4F_hns_OnLoad
	.byte 0

TrainerHill_4F_hns_OnLoad::
	setflag FLAG_TEMP_HIDE_FOLLOWER
	end
