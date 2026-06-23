.PHONY: all clean

SRCS = rl_compress.c

ifeq ($(OS),Windows_NT)
EXE := .exe
else
EXE :=
endif

all: rl_compress$(EXE)
	@:

rl_compress$(EXE): $(SRCS)
	$(CC) -o3 $(SRCS) -o $@ $(LDFLAGS)

clean:
	$(RM) rl_compress$(EXE)
