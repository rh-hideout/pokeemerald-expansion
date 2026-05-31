# party files are run through trainerproc, which is a tool that converts party data to an output file
# matching the current trainer .h formatting

AUTO_GEN_TARGETS += src/data/trainers.h
AUTO_GEN_TARGETS += src/data/trainers_frlg.h
AUTO_GEN_TARGETS += src/data/battle_partners.h
AUTO_GEN_TARGETS += test/battle/trainer_control.h
AUTO_GEN_TARGETS += test/battle/partner_control.h
AUTO_GEN_TARGETS += test/battle/frontier_mons_constants.h
AUTO_GEN_TARGETS += test/battle/frontier_mons.h
AUTO_GEN_TARGETS += test/battle/frontier_pool_sets_constants.h
AUTO_GEN_TARGETS += test/battle/frontier_pool_sets.h
AUTO_GEN_TARGETS += src/data/debug_trainers.h
AUTO_GEN_TARGETS += include/constants/battle_frontier_mons.h
AUTO_GEN_TARGETS += include/constants/battle_frontier_pool_sets.h
AUTO_GEN_TARGETS += src/data/battle_frontier/battle_frontier_mons.h
AUTO_GEN_TARGETS += src/data/battle_frontier/battle_frontier_pool_sets.h

%.h: %.party $(TRAINERPROC)
	$(CPP) $(CPPFLAGS) -traditional-cpp - < $< | $(TRAINERPROC) -o $@ -i $< -

src/data/battle_frontier/battle_frontier_mons.h: src/data/battle_frontier/battle_frontier_mons.pool_mons $(TRAINERPROC)
	$(CPP) $(CPPFLAGS) -traditional-cpp - < $< | $(TRAINERPROC) -m frontier-mons -o $@ -i $< -

include/constants/battle_frontier_mons.h: src/data/battle_frontier/battle_frontier_mons.pool_mons $(TRAINERPROC)
	$(CPP) $(CPPFLAGS) -traditional-cpp - < $< | $(TRAINERPROC) -m frontier-mon-constants -o $@ -i $< -

src/data/battle_frontier/battle_frontier_pool_sets.h: src/data/battle_frontier/battle_frontier_pool_sets.pool_sets $(TRAINERPROC)
	$(CPP) $(CPPFLAGS) -traditional-cpp - < $< | $(TRAINERPROC) -m pool-sets -o $@ -i $< -

include/constants/battle_frontier_pool_sets.h: src/data/battle_frontier/battle_frontier_pool_sets.pool_sets $(TRAINERPROC)
	$(CPP) $(CPPFLAGS) -traditional-cpp - < $< | $(TRAINERPROC) -m pool-set-constants -o $@ -i $< -

test/battle/frontier_mons.h: test/battle/frontier_mons.pool_mons $(TRAINERPROC)
	$(CPP) $(CPPFLAGS) -traditional-cpp - < $< | $(TRAINERPROC) -m frontier-mons -o $@ -i $< -

test/battle/frontier_mons_constants.h: test/battle/frontier_mons.pool_mons $(TRAINERPROC)
	$(CPP) $(CPPFLAGS) -traditional-cpp - < $< | $(TRAINERPROC) -m frontier-mon-constants -o $@ -i $< -

test/battle/frontier_pool_sets.h: test/battle/frontier_pool_sets.pool_sets $(TRAINERPROC)
	$(CPP) $(CPPFLAGS) -traditional-cpp - < $< | $(TRAINERPROC) -m pool-sets -o $@ -i $< -

test/battle/frontier_pool_sets_constants.h: test/battle/frontier_pool_sets.pool_sets $(TRAINERPROC)
	$(CPP) $(CPPFLAGS) -traditional-cpp - < $< | $(TRAINERPROC) -m pool-set-constants -o $@ -i $< -
