.PHONY: all check clean

CFLAGS := -Wall -O2

SRCS := main.c

ifeq ($(OS),Windows_NT)
EXE := .exe
else
EXE :=
endif

all: trainerproc$(EXE)
	@:

trainerproc$(EXE): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $@ $(LDFLAGS)

check: trainerproc$(EXE)
	sh ./test_frontier_mons.sh ./trainerproc$(EXE)

clean:
	$(RM) trainerproc$(EXE)
