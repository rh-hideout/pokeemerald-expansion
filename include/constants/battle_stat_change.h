#ifndef GUARD_CONSTANTS_BATTLE_MOVE_STAT_CHANGE_H
#define GUARD_CONSTANTS_BATTLE_MOVE_STAT_CHANGE_H

enum StatChangeResult
{
    STAT_CHANGE_WORKED,
    STAT_CHANGE_DIDNT_WORK,
    STAT_CHANGE_POSSIBLE,
    STAT_CHANGE_NOT_POSSIBLE,
    STAT_CHANGE_BLOCKED_BY_TARGET,
};

// Cmd_statbuffchange
#define STAT_CHANGE_ALLOW_PTR               (1 << 0)   // If set, allow use of jumpptr. If not set and unable to raise/lower stats, jump to failInstr.
#define STAT_CHANGE_MIRROR_ARMOR            (1 << 1)   // Stat change redirection caused by Mirror Armor ability.
#define STAT_CHANGE_ONLY_CHECKING           (1 << 2)   // Checks if the stat change can occur. Does not change stats or play stat change animation.
#define STAT_CHANGE_NOT_PROTECT_AFFECTED    (1 << 3)
#define STAT_CHANGE_UPDATE_MOVE_EFFECT      (1 << 4)
#define STAT_CHANGE_CHECK_PREVENTION        (1 << 5)
#define STAT_CHANGE_CERTAIN                 (1 << 6)

// stat flags for TryPlayStatChangeAnimation
#define BIT_HP                      (1 << 0)
#define BIT_ATK                     (1 << 1)
#define BIT_DEF                     (1 << 2)
#define BIT_SPEED                   (1 << 3)
#define BIT_SPATK                   (1 << 4)
#define BIT_SPDEF                   (1 << 5)
#define BIT_ACC                     (1 << 6)
#define BIT_EVASION                 (1 << 7)

enum StatChangeProcess
{
    PROCESS_ADJUST_STATS, // Default state
    PROCESS_NEGATIVE_STATS,
    PROCESS_POSITIVE_STATS,
    PROCESS_STATS_DONE,
};

#endif // GUARD_BATTLE_MOVE_STAT_CHANGE_H
