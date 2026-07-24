.PHONY: all clean

CFLAGS := -O2 -g -Wall -Wextra -fsanitize=address -fsanitize=undefined
LDFLAGS := -fsanitize=address -fsanitize=undefined

SRCS = main.c elf.c dwarf.c

ifeq ($(OS),Windows_NT)
EXE := .exe
else
EXE :=
endif

all: postlink$(EXE)
	@:

postlink$(EXE): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -Wall -o $@ $(LDFLAGS)

clean:
	$(RM) postlink$(EXE)
