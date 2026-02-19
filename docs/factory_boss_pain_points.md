# Factory Boss Framework Pain Points

## Logged

- Pool routing ambiguity:
  - `preferRandbatsPool` should be replaced by a clear mode-driven rule (random mode uses randbats pool, regular mode uses regular pool).

- Slide trigger flexibility:
  - Boss profile currently only exposes last-mon switch-in and last-mon low-HP slide text.
  - Need a cleaner way to configure other slide triggers per boss (example: mega evolution slide for Wally's Gallade).

- Boss display name:
  - Wally appearing as `Pokemon Trainer Wally` should be configurable per boss encounter (or via a dedicated trainer class/message path).

- Pre-battle cutscene text:
  - Status: resolved.
  - Now profile-driven via `FactoryBossTextSet` (`preBattleCallText`, `battleIntroText`, `battleStartText`, `battlePostWinText`).

- Post-battle defeat text:
  - Status: resolved.
  - Frontier brain speech now supports per-boss `battleSpeechPlayerWon` / `battleSpeechPlayerLost`.
