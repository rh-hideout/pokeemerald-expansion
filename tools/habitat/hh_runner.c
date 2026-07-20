// hh-runner — headless scenario driver for Hoenn Habitat.
//
// Drives the built ROM in libmgba (no window, unthrottled), mirroring mGBA's
// own perf-runner init. Habitat assertions read only the documented,
// versioned HabitatTestProbe ABI supplied by verify.sh from the fresh link
// map; they never depend on gMain, script internals, or message-buffer bytes.
//
// Boot: taps SELECT until the development probe becomes available. After that
// a scenario script runs — a semicolon-separated op list:
//   goto:X,Y      closed-loop walk using live *gSaveBlock1Ptr position reads
//   face:U|D|L|R  tap to turn without stepping
//   tap:K         4-frame key tap (A,B,START,SELECT,U,D,L,R)
//   wait:N        idle N frames
//   until-probe:FIELD,VALUE  wait for a documented probe field to equal VALUE
//   expect-probe:FIELD,VALUE fail unless a documented probe field equals VALUE
//   shot:NAME     screenshot to <out>/NAME.png
//   pass:MSG      finish PASS
// Any op timeout fails the run with documented probe diagnostics.

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <mgba/core/config.h>
#include <mgba/core/core.h>
#include <mgba/core/log.h>
#include <mgba-util/vfs.h>

#include "habitat/test_probe_schema.h"

enum {
    KEY_A = 0, KEY_B, KEY_SELECT, KEY_START,
    KEY_RIGHT, KEY_LEFT, KEY_UP, KEY_DOWN,
};

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
static uint32_t sSb1Ptr, sProbe;

static int probeField(const char *name, int *offset, int *width)
{
    struct Field { const char *name; int offset; int width; };
    static const struct Field fields[] = {
        { "version", HABITAT_TEST_PROBE_OFFSET_VERSION, 2 },
        { "spot_id", HABITAT_TEST_PROBE_OFFSET_SPOT_ID, 2 },
        { "spot_state", HABITAT_TEST_PROBE_OFFSET_SPOT_STATE, 1 },
        { "available_verbs", HABITAT_TEST_PROBE_OFFSET_AVAILABLE_VERBS, 1 },
        { "resolved_species", HABITAT_TEST_PROBE_OFFSET_RESOLVED_SPECIES, 2 },
        { "resident_spot_id", HABITAT_TEST_PROBE_OFFSET_RESIDENT_SPOT_ID, 2 },
        { "resident_assignment", HABITAT_TEST_PROBE_OFFSET_RESIDENT_ASSIGNMENT, 1 },
        { "bout_outcome", HABITAT_TEST_PROBE_OFFSET_BOUT_OUTCOME, 1 },
        { "map_group", HABITAT_TEST_PROBE_OFFSET_MAP_GROUP, 1 },
        { "map_num", HABITAT_TEST_PROBE_OFFSET_MAP_NUM, 1 },
    };
    for (size_t i = 0; i < sizeof(fields) / sizeof(fields[0]); i++)
        if (!strcmp(name, fields[i].name)) {
            *offset = fields[i].offset;
            *width = fields[i].width;
            return 0;
        }
    return -1;
}

static unsigned probeRead(int offset, int width)
{
    return width == 2 ? sCore->busRead16(sCore, sProbe + offset)
                      : sCore->busRead8(sCore, sProbe + offset);
}

static int probeWidthForOffset(int offset)
{
    return offset == HABITAT_TEST_PROBE_OFFSET_VERSION
        || offset == HABITAT_TEST_PROBE_OFFSET_SPOT_ID
        || offset == HABITAT_TEST_PROBE_OFFSET_RESOLVED_SPECIES
        || offset == HABITAT_TEST_PROBE_OFFSET_RESIDENT_SPOT_ID ? 2 : 1;
}

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

enum OpKind { OP_GOTO, OP_FACE, OP_TAP, OP_WAIT, OP_UNTIL_PROBE, OP_EXPECT_PROBE, OP_WALK, OP_UNTIL_MAP, OP_SHOT, OP_PASS };
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

static int parseProbeOp(const char *text, struct Op *op)
{
    char field[32];
    unsigned value;
    int width;
    if (sscanf(text, "%31[^,],%u", field, &value) != 2
     || probeField(field, &op->a, &width) != 0)
        return -1;
    op->b = (int)value;
    snprintf(op->text, sizeof(op->text), "%s", field);
    return 0;
}

static int parseScript(char* spec, struct Op* ops, int maxOps) {
    int n = 0;
    char* save = NULL;
    for (char* tok = strtok_r(spec, ";", &save); tok;
         tok = strtok_r(NULL, ";", &save)) {
        if (n >= maxOps) {
            // A silently truncated script "passes" every op it kept and then
            // dies confusingly ("ended without pass op") — fail loudly instead.
            fprintf(stderr, "hh-runner: script exceeds %d ops\n", maxOps);
            return -1;
        }
        struct Op* op = &ops[n];
        memset(op, 0, sizeof(*op));
        if (sscanf(tok, "goto:%d,%d", &op->a, &op->b) == 2) op->kind = OP_GOTO;
        else if (!strncmp(tok, "face:", 5)) { op->kind = OP_FACE; op->a = keyByName(tok + 5); }
        else if (!strncmp(tok, "tap:", 4)) { op->kind = OP_TAP; op->a = keyByName(tok + 4); }
        else if (sscanf(tok, "wait:%d", &op->a) == 1) op->kind = OP_WAIT;
        else if (!strncmp(tok, "until-probe:", 12)
              && parseProbeOp(tok + 12, op) == 0) op->kind = OP_UNTIL_PROBE;
        else if (!strncmp(tok, "expect-probe:", 13)
              && parseProbeOp(tok + 13, op) == 0) op->kind = OP_EXPECT_PROBE;
        else if (tok == strstr(tok, "walk:") && sscanf(tok + 7, "%d", &op->b) == 1) {
            op->kind = OP_WALK; op->a = keyByName((char[]){tok[5], 0});
        }
        else if (sscanf(tok, "until-map:%d,%d", &op->a, &op->b) == 2) op->kind = OP_UNTIL_MAP;
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
    unsigned maxFrames = 60000;
    struct Op ops[256];
    int nOps = 0;
    sOutDir = "verify-out";

    for (int i = 1; i < argc - 1; i++) {
        if (!strcmp(argv[i], "--rom")) rom = argv[++i];
        else if (!strcmp(argv[i], "--out")) sOutDir = argv[++i];
        else if (!strcmp(argv[i], "--sb1ptr")) sSb1Ptr = strtoul(argv[++i], NULL, 16);
        else if (!strcmp(argv[i], "--probe")) sProbe = strtoul(argv[++i], NULL, 16);
        else if (!strcmp(argv[i], "--script")) scriptSpec = argv[++i];
        else if (!strcmp(argv[i], "--max-frames")) maxFrames = strtoul(argv[++i], NULL, 10);
    }
    if (!rom || !sSb1Ptr || !sProbe || !scriptSpec) {
        fprintf(stderr, "usage: hh-runner --rom ROM --sb1ptr HEX --probe HEX "
                        "--script 'op;op;...' [--out DIR]\n");
        return 2;
    }
    nOps = parseScript(scriptSpec, ops, 256);
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
        if (phase == BOOT) {
            if (probeRead(HABITAT_TEST_PROBE_OFFSET_VERSION, 2) == HABITAT_TEST_PROBE_VERSION) {
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
            settled = probeRead(HABITAT_TEST_PROBE_OFFSET_VERSION, 2) == HABITAT_TEST_PROBE_VERSION
                ? settled + 1 : 0;
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
            opDeadline = frame + ((op->kind == OP_GOTO) ? 6000 : UNTIL_MAX);
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
                // Y first, X last: arrivals are horizontal, so a follow-up
                // face:U is a turn — a same-direction tap would step instead.
                int key = (y > op->b) ? KEY_UP : (y < op->b) ? KEY_DOWN
                        : (x > op->a) ? KEY_LEFT : KEY_RIGHT;
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
                fprintf(stderr, "HH_TRACE tap key=%d at f=%u\n", op->a, frame);
            }
            break;
        case OP_WAIT:
            if (frame >= opDeadline)
                done = 1;
            break;
        case OP_UNTIL_PROBE:
            if (probeRead(op->a, probeWidthForOffset(op->a)) == (unsigned) op->b)
                done = 1;
            break;
        case OP_EXPECT_PROBE:
            if (probeRead(op->a, probeWidthForOffset(op->a)) == (unsigned) op->b) {
                done = 1;
            } else {
                char msg[128];
                snprintf(msg, sizeof(msg), "probe %s expected %d got %u", op->text, op->b,
                         probeRead(op->a, probeWidthForOffset(op->a)));
                rc = finish("FAIL", msg, frame);
            }
            break;
        case OP_WALK:
            // b step-holds of direction a — blind edge-crossing for map
            // connections where greedy goto has no target coordinates.
            if (frame >= nextAct && !keys) {
                if (op->b <= 0) {
                    done = 1;
                } else {
                    op->b--;
                    keys = 1u << op->a;
                    holdUntil = frame + STEP_HOLD;
                    nextAct = frame + STEP_HOLD + STEP_GAP;
                }
            }
            break;
        case OP_UNTIL_MAP: {
            if (probeRead(HABITAT_TEST_PROBE_OFFSET_MAP_GROUP, 1) == (unsigned) op->a
             && probeRead(HABITAT_TEST_PROBE_OFFSET_MAP_NUM, 1) == (unsigned) op->b)
                done = 1;
            break;
        }
        case OP_SHOT:
            shot(op->text);
            done = 1;
            break;
        case OP_PASS:
            rc = finish("PASS", op->text, frame);
            break;
        }
        if (rc < 0 && op->kind != OP_WAIT && frame >= opDeadline) {
            char msg[360];
            int16_t x, y;
            playerPos(&x, &y);
            snprintf(msg, sizeof(msg),
                     "op %d timed out (kind %d) pos=%d,%d probe spot=%u state=%u verbs=%u map=%u,%u",
                     opIndex, (int) op->kind, x, y,
                     probeRead(HABITAT_TEST_PROBE_OFFSET_SPOT_ID, 2),
                     probeRead(HABITAT_TEST_PROBE_OFFSET_SPOT_STATE, 1),
                     probeRead(HABITAT_TEST_PROBE_OFFSET_AVAILABLE_VERBS, 1),
                     probeRead(HABITAT_TEST_PROBE_OFFSET_MAP_GROUP, 1),
                     probeRead(HABITAT_TEST_PROBE_OFFSET_MAP_NUM, 1));
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
