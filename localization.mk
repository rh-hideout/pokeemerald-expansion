# Build-time localization. See localization/README.md.
#
#   make LANG=es        build pokeemerald-es.gba (strings + graphics from localization/)
#   make rom-fr         same as 'make LANG=fr'
#   make roms-all       build every language
#   make loc-extract    sync localization/text/**.csv with the sources
#   make loc-seed LANG=pt [SEED=copy|pseudo]
#   make loc-validate   validate every language without building
#   make loc-stats      translation coverage
#   make loc-test       run the localization tool tests
#
#   LOC_STRICT=1        missing or stale translations are errors
#   LOC_VERBOSE=1       print every warning

# Languages the build knows about; keep in sync with localization/rules.json.
LOC_LANGUAGES       := en es pt fr
LOC_SOURCE_LANG     := en
LOC_GAME_LANGUAGE_en := LANGUAGE_ENGLISH
LOC_GAME_LANGUAGE_es := LANGUAGE_SPANISH
LOC_GAME_LANGUAGE_pt := LANGUAGE_PORTUGUESE
LOC_GAME_LANGUAGE_fr := LANGUAGE_FRENCH

# Game language. The shell's own LANG (a system locale such as en_US.UTF-8)
# comes from the environment and is ignored; set the game language on the
# command line (make LANG=es) or with 'LANG := es' in config.mk.
LANG ?= en
ifeq ($(origin LANG),environment)
  LOC_LANG := $(LOC_SOURCE_LANG)
else
  LOC_LANG := $(LANG)
  # Don't hand "es" to recipes as a system locale.
  unexport LANG
endif

ifeq ($(filter $(LOC_LANG),$(LOC_LANGUAGES)),)
  $(error Unknown LANG '$(LOC_LANG)'. Supported languages: $(LOC_LANGUAGES))
endif

LOC_TOOL          := python3 tools/localization/loc.py
LOC_BUILD_DIR     := $(BUILD_DIR)/loc/$(LOC_LANG)
LOC_STAMP         := $(LOC_BUILD_DIR)/overlay.stamp
LOC_GEN_FLAGS     := $(if $(filter 1,$(LOC_STRICT)),--strict) $(if $(filter 1,$(LOC_VERBOSE)),-v)

ifeq ($(LOC_LANG),$(LOC_SOURCE_LANG))
  # The source language is the code itself: nothing to substitute, and the
  # ROM, object directory and file names are unchanged.
  LOC_SUFFIX        :=
  LOC_PREPROC_FLAGS :=
  LOC_SCANINC_FLAGS :=
  LOC_DEPS          :=
  LOC_CPPFLAGS      :=
else
  LOC_SUFFIX        := -$(LOC_LANG)
  LOC_PREPROC_FLAGS := -t $(LOC_BUILD_DIR)/strings -L $(LOC_BUILD_DIR)/gfx
  LOC_SCANINC_FLAGS := -t $(LOC_BUILD_DIR)/strings -L $(LOC_BUILD_DIR)/gfx
  LOC_DEPS          := $(LOC_STAMP)
  LOC_CPPFLAGS      := -DGAME_LANGUAGE=$(LOC_GAME_LANGUAGE_$(LOC_LANG))
endif

LOC_TARGET_LANGUAGES := $(filter-out $(LOC_SOURCE_LANG),$(LOC_LANGUAGES))
LOC_ROM_TARGETS      := $(addprefix rom-,$(LOC_LANGUAGES))

RULES_NO_SCAN += $(LOC_ROM_TARGETS) roms-all loc-extract loc-seed loc-validate loc-stats loc-test loc-audit clean-loc
.PHONY: $(LOC_ROM_TARGETS) roms-all loc-extract loc-seed loc-validate loc-stats loc-test loc-audit clean-loc

# Language ROM targets keep the game and build type: make rom-es BUILD=firered
LOC_SUBMAKE_VARS = BUILD=$(BUILD_NAME) RELEASE=$(RELEASE) DEBUG=$(DEBUG)

$(LOC_ROM_TARGETS): rom-%:
	@$(MAKE) LANG=$* $(LOC_SUBMAKE_VARS)

roms-all:
	@set -e; for lang in $(LOC_LANGUAGES); do $(MAKE) LANG=$$lang $(LOC_SUBMAKE_VARS); done

# Generated headers (map names, trainer names) hold game text too.
loc-extract:
	@$(MAKE) -s -f make_tools.mk
	@$(MAKE) -s MAP_VERSION=$(MAP_VERSION) generated
	$(LOC_TOOL) extract $(if $(filter 1,$(PRUNE)),--prune)

loc-seed:
	$(LOC_TOOL) seed $(LOC_LANG) $(if $(filter copy,$(SEED)),--copy-src) $(if $(filter pseudo,$(SEED)),--pseudo)

loc-validate:
	$(LOC_TOOL) validate --lang $(if $(filter command line,$(origin LANG)),$(LOC_LANG),all) $(LOC_GEN_FLAGS)

loc-stats:
	@$(LOC_TOOL) stats

loc-audit:
	@$(LOC_TOOL) audit-concat

loc-test:
	python3 -m unittest discover -s tools/localization/tests -t tools/localization

clean-loc:
	rm -rf $(BUILD_DIR)/loc
