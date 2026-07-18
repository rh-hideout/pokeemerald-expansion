# Changelog

All notable changes to Hoenn Habitat. Base: pokeemerald-expansion `expansion/1.16.2`.

## [Unreleased] — Milestone 0: Toolchain & Foundations

- Pin project base to pokeemerald-expansion tag `expansion/1.16.2`; add project README banner and legal stance.
- Add design spec v0.1 and Milestone 0 implementation plan under `docs/superpowers/`.
- Add headless mGBA verification harness (`make verify`): builds the ROM, boots it
  with SDL dummy drivers, quickstarts past the intro, confirms the overworld via
  `gMain.callback2`, and captures screenshots. (`tools/habitat/`)
- Add throwaway scripted test spot in the moving truck (sign at (1,0)) proving the
  map.json → event script → msgbox pipeline. Remove when the real spot framework lands.
- Add save-region measurement probes (`tools/habitat/save_probe.c`) — measurement
  only; no save layout changes in M0.
