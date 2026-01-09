---
allowed-tools: Bash(git:*), Bash(gh:*)
description: Commit changes, push, and create a PR
argument-hint: [target-branch]
---

## Context

- Current branch: !`git branch --show-current`
- Git status: !`git status --short`
- Recent commits on this branch: !`git log --oneline -5`

## Task

Ship the current changes by:

1. Review the staged and unstaged changes with `git diff` and `git diff --cached`
2. Stage all relevant changes (but NOT unrelated files)
3. Create a commit with a descriptive message following conventional commit style
4. Push to origin (create upstream if needed)
5. Create a PR targeting `$ARGUMENTS` branch (default to `upcoming` if not specified, use `master` only for bug fixes)

Use `gh pr create` with:
- A clear, concise title
- A body containing:
  - ## Summary (bullet points of changes)
  - ## Test plan (how to verify the changes)

Return the PR URL when complete.
