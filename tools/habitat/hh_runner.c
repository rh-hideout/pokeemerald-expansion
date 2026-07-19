// hh-runner — headless scenario driver for Hoenn Habitat.
//
// Drives the built ROM in libmgba (no window, unthrottled), mirroring mGBA's
// own perf-runner init. Game state is observed through bus reads of symbols
// supplied on the command line (extracted from pokeemerald.map by verify.sh),
// never by pixel-guessing.
//
// Boot: taps SELECT until the expansion's quickstart starts a new game, then
// waits for gMain.callback2 == CB2_Overworld to hold. After that a scenario
// script runs — a semicolon-separated op list:
//   goto:X,Y      closed-loop walk using live *gSaveBlock1Ptr position reads
//   face:U|D|L|R  tap to turn without stepping
//   tap:K         4-frame key tap (A,B,START,SELECT,U,D,L,R)
//   wait:N        idle N frames
//   until-sv4:HH  wait (max 900 frames) until gStringVar4[0] == 0xHH — the
//                 field-message pipeline expands every shown message into
//                 gStringVar4, so first bytes identify which text is up
//   shot:NAME     screenshot to <out>/NAME.png
//   pass:MSG      finish PASS
// Any op timeout fails the run with position/sv4 diagnostics.

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <mgba/core/config.h>
#include <mgba/core/core.h>
#include <mgba/core/log.h>
#include <mgba-util/vfs.h>

enum {
    KEY_A = 0, KEY_B, KEY_SELECT, KEY_START,
    KEY_RIGHT, KEY_LEFT, KEY_UP, KEY_DOWN,
};

#define THUMB_BIT 1u
#define SETTLE_FRAMES 480   // truck-era fade margin; harmless at Route 103
#define TAP_FRAMES 4
#define STEP_HOLD 12
#define STEP_GAP 22
#define UNTIL_MAX 900

static void stderrLog(struct mLogger* log, int category, enum mLogLevel level,
                      const char* format, va_list args) {
    UNUSED(log);
    if (level & (mLOG_FATAL | mLOG_ERROR | mLOG_WARN)) {
        fprintf(stderr, "HH_MGBA[%s] ", mLogCategoryName(category));
        vfprintf(stderr, format, args);
        fputc('\n', stderr);
    }
}
static struct mLogger sLogger = { .log = stderrLog };

static struct mCore* sCore;
static const char* sOutDir;
static uint32_t sSb1Ptr, sStrVar4;

static void shot(const char* name) {
    char path[1024];
    snprintf(path, sizeof(path), "%s/%s.png", sOutDir, name);
    struct VFile* vf = VFileOpen(path, O_CREAT | O_TRUNC | O_WRONLY);
    if (vf) {
        mCoreTakeScreenshotVF(sCore, vf);
        vf->close(vf);
    }
}

static void playerPos(int16_t* x, int16_t* y) {
    uint32_t sb1 = sCore->busRead32(sCore, sSb1Ptr);
    *x = (int16_t) sCore->busRead16(sCore, sb1);
    *y = (int16_t) sCore->busRead16(sCore, sb1 + 2);
}

static int finish(const char* status, const char* msg, unsigned frame) {
    char path[1024];
    int16_t x = -1, y = -1;
    if (sSb1Ptr)
        playerPos(&x, &y);
    snprintf(path, sizeof(path), "%s/result.txt", sOutDir);
    FILE* f = fopen(path, "w");
    if (f) {
        fprintf(f, "%s %s (frame %u, pos %d,%d)\n", status, msg, frame, x, y);
        fclose(f);
    }
    printf("HH_RESULT %s %s (frame %u, pos %d,%d)\n", status, msg, frame, x, y);
    return strcmp(status, "PASS") == 0 ? 0 : 1;
}

// ---- scenario script ----

enum OpKind { OP_GOTO, OP_FACE, OP_TAP, OP_WAIT, OP_UNTIL_SV4, OP_DISMISS_UNTIL, OP_CLEAR_SV4, OP_SHOT, OP_PASS };
struct Op {
    enum OpKind kind;
    int a, b;
    char text[48];
};

static int keyByName(const char* s) {
    if (!strcmp(s, "A")) return KEY_A;
    if (!strcmp(s, "B")) return KEY_B;
    if (!strcmp(s, "START")) return KEY_START;
    if (!strcmp(s, "SELECT")) return KEY_SELECT;
    if (!strcmp(s, "U")) return KEY_UP;
    if (!strcmp(s, "D")) return KEY_DOWN;
    if (!strcmp(s, "L")) return KEY_LEFT;
    if (!strcmp(s, "R")) return KEY_RIGHT;
    return -1;
}

static int parseScript(char* spec, struct Op* ops, int maxOps) {
    int n = 0;
    char* save = NULL;
    for (char* tok = strtok_r(spec, ";", &save); tok && n < maxOps;
         tok = strtok_r(NULL, ";", &save)) {
        struct Op* op = &ops[n];
        memset(op, 0, sizeof(*op));
        if (sscanf(tok, "goto:%d,%d", &op->a, &op->b) == 2) op->kind = OP_GOTO;
        else if (!strncmp(tok, "face:", 5)) { op->kind = OP_FACE; op->a = keyByName(tok + 5); }
        else if (!strncmp(tok, "tap:", 4)) { op->kind = OP_TAP; op->a = keyByName(tok + 4); }
        else if (sscanf(tok, "wait:%d", &op->a) == 1) op->kind = OP_WAIT;
        else if (sscanf(tok, "until-sv4:%x", &op->a) == 1) op->kind = OP_UNTIL_SV4;
        else if (sscanf(tok, "dismiss-until:%x", &op->a) == 1) op->kind = OP_DISMISS_UNTIL;
        else if (!strcmp(tok, "clear-sv4")) op->kind = OP_CLEAR_SV4;
        else if (!strncmp(tok, "shot:", 5)) { op->kind = OP_SHOT; snprintf(op->text, sizeof(op->text), "%s", tok + 5); }
        else if (!strncmp(tok, "pass:", 5)) { op->kind = OP_PASS; snprintf(op->text, sizeof(op->text), "%s", tok + 5); }
        else { fprintf(stderr, "hh-runner: bad op '%s'\n", tok); return -1; }
        if ((op->kind == OP_FACE || op->kind == OP_TAP) && op->a < 0) {
            fprintf(stderr, "hh-runner: bad key in '%s'\n", tok);
            return -1;
        }
        n++;
    }
    return n;
}

int main(int argc, char** argv) {
    const char* rom = NULL;
    char* scriptSpec = NULL;
    uint32_t gMain = 0, cb2Overworld = 0;
    unsigned maxFrames = 60000;
    struct Op ops[64];
    int nOps = 0;
    sOutDir = "verify-out";

    for (int i = 1; i < argc - 1; i++) {
        if (!strcmp(argv[i], "--rom")) rom = argv[++i];
        else if (!strcmp(argv[i], "--out")) sOutDir = argv[++i];
        else if (!strcmp(argv[i], "--gmain")) gMain = strtoul(argv[++i], NULL, 16);
        else if (!strcmp(argv[i], "--cb2-overworld")) cb2Overworld = strtoul(argv[++i], NULL, 16);
        else if (!strcmp(argv[i], "--sb1ptr")) sSb1Ptr = strtoul(argv[++i], NULL, 16);
        else if (!strcmp(argv[i], "--strvar4")) sStrVar4 = strtoul(argv[++i], NULL, 16);
        else if (!strcmp(argv[i], "--script")) scriptSpec = argv[++i];
        else if (!strcmp(argv[i], "--max-frames")) maxFrames = strtoul(argv[++i], NULL, 10);
    }
    if (!rom || !gMain || !cb2Overworld || !sSb1Ptr || !scriptSpec) {
        fprintf(stderr, "usage: hh-runner --rom ROM --gmain HEX --cb2-overworld HEX "
                        "--sb1ptr HEX --strvar4 HEX --script 'op;op;...' [--out DIR]\n");
        return 2;
    }
    nOps = parseScript(scriptSpec, ops, 64);
    if (nOps < 0)
        return 2;

    mLogSetDefaultLogger(&sLogger);
    sCore = mCoreFind(rom);
    if (!sCore) {
        fprintf(stderr, "hh-runner: no core for %s\n", rom);
        return 2;
    }
    sCore->init(sCore);
    void* videoBuffer = malloc(256 * 256 * 4);
    sCore->setVideoBuffer(sCore, videoBuffer, 256);
    if (!mCoreLoadFile(sCore, rom)) {
        fprintf(stderr, "hh-runner: failed to load %s\n", rom);
        return 2;
    }
    mCoreConfigInit(&sCore->config, "hh-runner");  // hermetic: no user config load
    struct mCoreOptions opts = { .audioSync = false, .videoSync = false };
    mCoreConfigLoadDefaults(&sCore->config, &opts);
    mCoreConfigSetDefaultValue(&sCore->config, "idleOptimization", "detect");
    mCoreLoadConfig(sCore);
    sCore->reset(sCore);

    enum { BOOT, SETTLE, SCRIPT } phase = BOOT;
    unsigned keys = 0, holdUntil = 0, nextAct = 240, settled = 0, opDeadline = 0;
    int opIndex = 0, opArmed = 0;
    int rc = -1;

    for (unsigned frame = 0; frame < maxFrames && rc < 0; frame++) {
        if (keys && frame >= holdUntil)
            keys = 0;
        sCore->setKeys(sCore, keys);
        sCore->runFrame(sCore);

        uint32_t cb2 = sCore->busRead32(sCore, gMain + 4);
        int inOverworld = cb2 == (cb2Overworld | THUMB_BIT);

        if (phase == BOOT) {
            if (inOverworld) {
                phase = SETTLE;
                settled = 0;
            } else if (frame >= nextAct && !keys) {
                keys = 1u << KEY_SELECT;
                holdUntil = frame + 2;
                nextAct = frame + 20;
                if (frame > 18000)
                    rc = finish("FAIL", "never reached overworld", frame);
            }
            continue;
        }
        if (phase == SETTLE) {
            settled = inOverworld ? settled + 1 : 0;
            if (settled >= SETTLE_FRAMES) {
                shot("overworld");
                phase = SCRIPT;
                nextAct = frame + 1;
            }
            continue;
        }

        // SCRIPT phase: execute ops in order.
        if (opIndex >= nOps) {
            rc = finish("FAIL", "script ended without pass op", frame);
            break;
        }
        struct Op* op = &ops[opIndex];
        if (!opArmed) {
            opArmed = 1;
            opDeadline = frame + ((op->kind == OP_GOTO) ? 6000 : (op->kind == OP_DISMISS_UNTIL) ? 1500 : UNTIL_MAX);
            if (op->kind == OP_WAIT)
                opDeadline = frame + op->a;
        }
        int done = 0;
        switch (op->kind) {
        case OP_GOTO: {
            int16_t x, y;
            playerPos(&x, &y);
            if (x == op->a && y == op->b)
                done = 1;
            else if (frame >= nextAct && !keys) {
                int key = (x > op->a) ? KEY_LEFT : (x < op->a) ? KEY_RIGHT
                        : (y > op->b) ? KEY_UP : KEY_DOWN;
                keys = 1u << key;
                holdUntil = frame + STEP_HOLD;
                nextAct = frame + STEP_HOLD + STEP_GAP;
            }
            break;
        }
        case OP_FACE:
            if (frame >= nextAct && !keys) {
                keys = 1u << op->a;
                holdUntil = frame + 2;  // short tap: turn, don't step
                nextAct = frame + 16;
                done = 1;
            }
            break;
        case OP_TAP:
            if (frame >= nextAct && !keys) {
                keys = 1u << op->a;
                holdUntil = frame + TAP_FRAMES;
                nextAct = frame + TAP_FRAMES + 4;
                done = 1;
            }
            break;
        case OP_WAIT:
            if (frame >= opDeadline)
                done = 1;
            break;
        case OP_UNTIL_SV4:
            if (sCore->busRead8(sCore, sStrVar4) == (uint32_t) op->a)
                done = 1;
            break;
        case OP_DISMISS_UNTIL:
            // Advance any message/prompt flow by tapping A on a cadence until
            // the identified text is up. All slice answers are YES/first-item,
            // which A selects.
            if (sCore->busRead8(sCore, sStrVar4) == (uint32_t) op->a) {
                done = 1;
            } else if (frame >= nextAct && !keys) {
                keys = 1u << KEY_A;
                holdUntil = frame + TAP_FRAMES;
                nextAct = frame + 24;
            }
            break;
        case OP_CLEAR_SV4:
            sCore->busWrite8(sCore, sStrVar4, 0);
            done = 1;
            break;
        case OP_SHOT:
            shot(op->text);
            done = 1;
            break;
        case OP_PASS:
            rc = finish("PASS", op->text, frame);
            break;
        }
        if (rc < 0 && op->kind != OP_WAIT && frame >= opDeadline) {
            char msg[160];
            int16_t x, y;
            playerPos(&x, &y);
            snprintf(msg, sizeof(msg), "op %d timed out (kind %d) pos=%d,%d sv4=%02x",
                     opIndex, (int) op->kind, x, y, sCore->busRead8(sCore, sStrVar4));
            shot("timeout");
            rc = finish("FAIL", msg, frame);
        }
        if (done) {
            opIndex++;
            opArmed = 0;
        }
    }
    if (rc < 0)
        rc = finish("FAIL", "frame budget exhausted", maxFrames);

    mCoreConfigDeinit(&sCore->config);
    sCore->deinit(sCore);
    free(videoBuffer);
    return rc;
}
