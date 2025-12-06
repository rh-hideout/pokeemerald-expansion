#ifndef ASSERTF_H
#define ASSERTF_H

/* assertf(cond) [{ recovery... }]
 * assertf(cond, fmt, ...) [{ recovery... }]
 *
 * If 'cond' is 'FALSE':
 * - In a release build: executes the recovery code.
 * - In a debug build: shows a resumable crash screen and executes the recovery code.
 * - In a test build: causes the test to be INVALID. */
#define assertf(cond, ...) CAT(_ASSERTF, FIRST(__VA_OPT__(_FMT,) _COND))(cond __VA_OPT__(,) __VA_ARGS__)

#define _ASSERTF_COND(cond) for (bool32 _recover = !(cond); _recover && (_ASSERTF_HANDLE("%s:%d: %s", __FILE__, __LINE__, STR(cond)), TRUE); _recover = FALSE)

#define _ASSERTF_FMT(cond, fmt, ...) for (bool32 _recover = !(cond); _recover && (_ASSERTF_HANDLE("%s:%d: " fmt, __FILE__, __LINE__ __VA_OPT__(,) __VA_ARGS__), TRUE); _recover = FALSE)

#if RELEASE
#define _ASSERTF_HANDLE(...) 0
#elif TESTING
#include "test_result.h"
#define _ASSERTF_HANDLE(fmt, ...) Test_ExitWithResult(TEST_RESULT_INVALID, 0, fmt, __VA_ARGS__)
#else
#define _ASSERTF_HANDLE(fmt, ...) AssertfCrashScreen(__builtin_return_address(0), fmt, __VA_ARGS__)
#endif

void AssertfCrashScreen(const void *return0, const char *fmt, ...);

#endif
