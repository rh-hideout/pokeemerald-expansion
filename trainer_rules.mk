# party files are run through trainerproc, which is a tool that converts party data to an output file
# matching the current trainer .h formatting

AUTO_GEN_TARGETS += src/data/trainers.h
src/data/trainers.h: src/data/trainers.party
	$(CPP) $(CPPFLAGS) -traditional-cpp - < $< | $(TRAINERPROC) -o $@ -i $< -

AUTO_GEN_TARGETS += src/data/battle_partners.h
src/data/battle_partners.h: src/data/battle_partners.party
	$(CPP) $(CPPFLAGS) -traditional-cpp - < $< | $(TRAINERPROC) -o $@ -i $< -

AUTO_GEN_TARGETS += test/battle/trainer_control.h
test/battle/trainer_control.h: test/battle/trainer_control.party
	$(CPP) $(CPPFLAGS) -traditional-cpp - < $< | $(TRAINERPROC) -o $@ -i $< -
