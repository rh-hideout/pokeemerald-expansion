#ifndef GUARD_CONSTANTS_SAFARIS_H
#define GUARD_CONSTANTS_SAFARIS_H

enum SafariEvents {
    SAFARI_EVENT_NONE,
    SAFARI_EVENT_HOENN,
    SAFARI_EVENT_KANTO,
    SAFARI_EVENT_COUNT
};

// VAR_SAFARI_WARP_STATE
#define SAFARI_WARP_ENTERING                    1
#define SAFARI_WARP_MANUAL_EXIT                 1 // reused SAFARI_WARP_ENTERING on purpose, if you manually leave, it may happen because of a warp without a script to set the value so the warp state would be the same as when you entered
#define SAFARI_WARP_NO_STEPS                    2
#define SAFARI_WARP_NO_BALLS                    3
#define SAFARI_WARP_NO_BALLS_MID_BATTLE         4
#define SAFARI_WARP_RETIRING                    5
#define SAFARI_WARP_WHITEOUT                    6

#endif // GUARD_CONSTANTS_SAFARIS_H
