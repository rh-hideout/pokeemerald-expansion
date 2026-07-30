#define SQUARE(n) ((n) * (n))
#define CUBE(n) ((long long)(n) * (n) * (n))
#define CUSTOM_XP_SCALING_FACTOR 10
#define BASE_XP_OFFSET 50

// ORIGINAL XP FORMULAS

// #define EXP_SLOW(n) ((5 * CUBE(n)) / 4) // (5 * (n)^3) / 4
// #define EXP_FAST(n) ((4 * CUBE(n)) / 5) // (4 * (n)^3) / 5
// #define EXP_MEDIUM_FAST(n) (CUBE(n)) // (n)^3
// #define EXP_MEDIUM_SLOW(n) ((6 * CUBE(n)) / 5 - (15 * SQUARE(n)) + (100 * n) - 140)    // (6 * (n)^3) / 5 - (15 * (n)^2) + (100 * n) - 140
// #define EXP_ERRATIC(n)                                      \
//      (n <= 50) ? ((100 - n) * CUBE(n) /  50)                \
//     :(n <= 68) ? ((150 - n) * CUBE(n) / 100)                \
//     :(n <= 98) ? (((1911 - 10 * n) / 3) * CUBE(n) / 500)    \
//     :            ((160 - n) * CUBE(n) / 100)
// #define EXP_FLUCTUATING(n)                                  \
//      (n <= 15) ? (((n + 1) / 3 + 24) * CUBE(n) / 50)        \
//     :(n <= 36) ? ((n + 14)           * CUBE(n) / 50)        \
//     :            (((n / 2) + 32)     * CUBE(n) / 50)

// CUSTOM XP FORMULAS
#define EXP_SLOW(n) ((5 * CUBE(n)) / (4 * CUSTOM_XP_SCALING_FACTOR)) + BASE_XP_OFFSET // (5 * (n^3)) / (4 * CUSTOM_XP_SCALING_FACTOR)
#define EXP_FAST(n) ((4 * CUBE(n)) / (5 * CUSTOM_XP_SCALING_FACTOR)) + BASE_XP_OFFSET // (4 * (n^3)) / (5 * CUSTOM_XP_SCALING_FACTOR)
#define EXP_MEDIUM_FAST(n) (CUBE(n) / CUSTOM_XP_SCALING_FACTOR) + BASE_XP_OFFSET // (n^3) / CUSTOM_XP_SCALING_FACTOR
#define EXP_MEDIUM_SLOW(n) (((6 * CUBE(n)) / (5 * CUSTOM_XP_SCALING_FACTOR)) - (15 * SQUARE(n) / CUSTOM_XP_SCALING_FACTOR) + (100 * n / CUSTOM_XP_SCALING_FACTOR) - (140 / CUSTOM_XP_SCALING_FACTOR)) + BASE_XP_OFFSET
#define EXP_ERRATIC(n)                                                                \
   (n <= 50) ? (((250 - n) * CUBE(n) / (50 * CUSTOM_XP_SCALING_FACTOR))) + BASE_XP_OFFSET                 \
  :(n <= 68) ? (((300 - n) * CUBE(n) / (100 * CUSTOM_XP_SCALING_FACTOR))) + BASE_XP_OFFSET                \
  :(n <= 98) ? ((((1911 - 10 * n) / 3) * CUBE(n) / (500 * CUSTOM_XP_SCALING_FACTOR))) + BASE_XP_OFFSET    \
  :            (((400 - n) * CUBE(n) / (100 * CUSTOM_XP_SCALING_FACTOR))) + BASE_XP_OFFSET
  #define EXP_FLUCTUATING(n)                                                          \
  (n <= 15) ? ((((n + 1) / 3 + 24) * CUBE(n) / (50 * CUSTOM_XP_SCALING_FACTOR))) + BASE_XP_OFFSET         \
 :(n <= 36) ? (((n + 14) * CUBE(n) / (50 * CUSTOM_XP_SCALING_FACTOR))) + BASE_XP_OFFSET                   \
 :            ((((n / 2) + 32) * CUBE(n) / (50 * CUSTOM_XP_SCALING_FACTOR))) + BASE_XP_OFFSET
