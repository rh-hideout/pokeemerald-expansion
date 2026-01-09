---
allowed-tools: Bash(make:*)
description: Run tests with optional filter pattern
argument-hint: [pattern]
---

## Context

- CPU cores: !`nproc`

## Test patterns

- Prefix match: `TESTS="Spikes"` runs all tests starting with "Spikes"
- Infix match: `TESTS="*effect*"` runs tests containing "effect"
- File match: `TESTS="filename.c"` runs tests from specific file

## Task

Run the test suite with optional filtering:

If pattern provided ($ARGUMENTS):
```
make check -j$(nproc) TESTS="$ARGUMENTS"
```

If no pattern:
```
make check -j$(nproc)
```

Report test results including:
- Number of tests passed/failed
- Any failing test names and their errors
- Suggestions for fixing failures if applicable
