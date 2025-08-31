# Makefile for use as a subproject of pokeemerald, et al
# The enforced contract is to provide a default target to compile the tool and a
# "clean" target to sweep everything up

.PHONY: all clean

TARGET := poryscript
ifeq ($(OS),Windows_NT)
    TARGET := $(TARGET).exe
endif

# Add any new packages to this variable to pick up underlying source files
PACKAGES := ast emitter lexer parser
GOFILES  := main.go $(foreach package,$(PACKAGES),$(wildcard $(package)/*.go))
SOURCES  := $(filter-out %_test.go,$(GOFILES))

$(TARGET): $(SOURCES)
	go build -o $@

all: $(TARGET)

clean:
	go clean
	rm -f $(TARGET)
