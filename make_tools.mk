# This controls building executables in the `tools` folder.
# Can be invoked through the `Makefile` or standalone.

MAKEFLAGS += --no-print-directory

# Inclusive list. If you don't want a tool to be built, don't add it here.
TOOLS_DIR := tools
TOOL_NAMES := bin2c gbafix gbagfx jsonproc mapjson mid2agb preproc ramscrgen rsfont scaninc trainerproc compresSmol wav2agb
CHECK_TOOL_NAMES = patchelf mgba-rom-test-hydra

TOOLDIRS := $(TOOL_NAMES:%=$(TOOLS_DIR)/%)
CHECKTOOLDIRS := $(CHECK_TOOL_NAMES:%=$(TOOLS_DIR)/%)

# Tool making doesnt require a pokeemerald dependency scan.
RULES_NO_SCAN += tools check-tools trainerproc-check clean-tools clean-check-tools history $(TOOLDIRS) $(CHECKTOOLDIRS)
.PHONY: $(RULES_NO_SCAN)

tools: history $(TOOLDIRS)

check-tools: $(CHECKTOOLDIRS) trainerproc-check

$(TOOLDIRS):
	@$(MAKE) -C $@

$(CHECKTOOLDIRS):
	@$(MAKE) -C $@

trainerproc-check: tools/trainerproc
	@$(MAKE) -C tools/trainerproc check

clean-tools:
	@$(foreach tooldir,$(TOOLDIRS),$(MAKE) clean -C $(tooldir);)

clean-check-tools:
	@$(foreach tooldir,$(CHECKTOOLDIRS),$(MAKE) clean -C $(tooldir);)

history:
	@$(SHELL) ./check_history.sh
