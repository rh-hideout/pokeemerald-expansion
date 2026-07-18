// hh-runner — headless boot/interaction verifier for Hoenn Habitat.
//
// Drives the built ROM in libmgba (no window, unthrottled), using the same
// core-init sequence as mGBA's own perf runner. The game is observed through
// bus reads of symbols supplied on the command line (extracted from
// pokeemerald.map by verify.sh), never by pixel-guessing:
//
//   boot    - tap SELECT until title quickstart fires (expansion feature:
//             SELECT on the title starts a new game immediately)
//   settle  - wait for gMain.callback2 == CB2_Overworld for 120 straight frames
//   walk    - step the player toward --target using live position reads from
//             *gSaveBlock1Ptr (pos.x at +0, pos.y at +2)
//   face/press/textbox - face the tile above, press A, let the msgbox draw
//
// Screenshots (title/overworld/interact) and result.txt land in --out.
// Exit 0 iff the requested phase chain completed.
//
// Build (see verify.sh): cc against ~/tools/mgba-src headers + libmgba.dylib.

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <mgba/core/config.h>
#include <mgba/core/core.h>
#include <mgba/core/log.h>
#include <mgba-util/vfs.h>

// GBA KEYINPUT bit order.
enum {
    KEY_A = 0, KEY_B, KEY_SELECT, KEY_START,
    KEY_RIGHT, KEY_LEFT, KEY_UP, KEY_DOWN,
};

#define THUMB_BIT 1u
#define SETTLE_FRAMES 480
#define TAP_FRAMES 2      // held long enough to register, short enough to turn-not-walk
#define STEP_GAP 22       // frames to let a one-tile step finish

static void nullLog(struct mLogger* log, int category, enum mLogLevel level,
                    const char* format, va_list args) {
    UNUSED(log); UNUSED(category); UNUSED(level); UNUSED(format); UNUSED(args);
}
static struct mLogger sLogger = { .log = nullLog };

static struct mCore* sCore;
static const char* sOutDir;
static const uint32_t* sVideoBuffer;

static int frameIsLit(void) {
    // Sample the buffer sparsely; "lit" = any sampled pixel meaningfully non-black.
    for (unsigned i = 0; i < 256 * 160; i += 61) {
        if ((sVideoBuffer[i] & 0x00F0F0F0) != 0)
            return 1;
    }
    return 0;
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

static int finish(const char* status, const char* msg, unsigned frame) {
    char path[1024];
    snprintf(path, sizeof(path), "%s/result.txt", sOutDir);
    FILE* f = fopen(path, "w");
    if (f) {
        fprintf(f, "%s %s (frame %u)\n", status, msg, frame);
        fclose(f);
    }
    printf("HH_RESULT %s %s (frame %u)\n", status, msg, frame);
    return strcmp(status, "PASS") == 0 ? 0 : 1;
}

int main(int argc, char** argv) {
    const char* rom = NULL;
    uint32_t gMain = 0, cb2Overworld = 0, sb1Ptr = 0;
    int targetX = 1, targetY = 1;
    int interact = 1;
    unsigned maxFrames = 30000;
    sOutDir = "verify-out";

    for (int i = 1; i < argc - 1; i++) {
        if (!strcmp(argv[i], "--rom")) rom = argv[++i];
        else if (!strcmp(argv[i], "--out")) sOutDir = argv[++i];
        else if (!strcmp(argv[i], "--gmain")) gMain = strtoul(argv[++i], NULL, 16);
        else if (!strcmp(argv[i], "--cb2-overworld")) cb2Overworld = strtoul(argv[++i], NULL, 16);
        else if (!strcmp(argv[i], "--sb1ptr")) sb1Ptr = strtoul(argv[++i], NULL, 16);
        else if (!strcmp(argv[i], "--target")) sscanf(argv[++i], "%d,%d", &targetX, &targetY);
        else if (!strcmp(argv[i], "--interact")) interact = atoi(argv[++i]);
        else if (!strcmp(argv[i], "--max-frames")) maxFrames = strtoul(argv[++i], NULL, 10);
    }
    if (!rom || !gMain || !cb2Overworld || !sb1Ptr) {
        fprintf(stderr, "usage: hh-runner --rom ROM --gmain HEX --cb2-overworld HEX "
                        "--sb1ptr HEX [--out DIR] [--target X,Y] [--interact 0|1] "
                        "[--max-frames N]\n");
        return 2;
    }

    mLogSetDefaultLogger(&sLogger);

    sCore = mCoreFind(rom);
    if (!sCore) {
        fprintf(stderr, "hh-runner: no core for %s\n", rom);
        return 2;
    }
    sCore->init(sCore);
    unsigned w, h;
    sCore->desiredVideoDimensions(sCore, &w, &h);
    void* videoBuffer = malloc(256 * 256 * 4);
    sVideoBuffer = videoBuffer;
    sCore->setVideoBuffer(sCore, videoBuffer, 256);
    if (!mCoreLoadFile(sCore, rom)) {
        fprintf(stderr, "hh-runner: failed to load %s\n", rom);
        return 2;
    }
    mCoreConfigInit(&sCore->config, "hh-runner");  // hermetic: no mCoreConfigLoad
    struct mCoreOptions opts = { .audioSync = false, .videoSync = false };
    mCoreConfigLoadDefaults(&sCore->config, &opts);
    mCoreConfigSetDefaultValue(&sCore->config, "idleOptimization", "detect");
    mCoreLoadConfig(sCore);
    sCore->reset(sCore);

    enum { BOOT, SETTLE, WALK, FACE, PRESS, TEXTBOX } phase = BOOT;
    unsigned keys = 0, holdUntil = 0, nextAct = 240, settled = 0;
    int rc = -1;

    unsigned frame;
    for (frame = 0; frame < maxFrames && rc < 0; frame++) {
        if (keys && frame >= holdUntil) {
            keys = 0;
        }
        sCore->setKeys(sCore, keys);
        sCore->runFrame(sCore);

        uint32_t cb2 = sCore->busRead32(sCore, gMain + 4);
        int inOverworld = cb2 == (cb2Overworld | THUMB_BIT);

        switch (phase) {
        case BOOT:
            if (inOverworld) {
                phase = SETTLE;
                settled = 0;
                break;
            }
            if (frame >= nextAct && !keys) {
                if (frameIsLit())
                    shot("title");  // last lit pre-overworld screen = title (or intro)
                keys = 1u << KEY_SELECT;
                holdUntil = frame + TAP_FRAMES;
                nextAct = frame + 20;
            }
            break;
        case SETTLE:
            settled = inOverworld ? settled + 1 : 0;
            if (settled >= SETTLE_FRAMES) {
                shot("overworld");
                if (interact) {
                    phase = WALK;
                    nextAct = frame + 30;
                } else {
                    rc = finish("PASS", "overworld reached", frame);
                }
            }
            break;
        case WALK: {
            uint32_t sb1 = sCore->busRead32(sCore, sb1Ptr);
            int16_t x = (int16_t) sCore->busRead16(sCore, sb1);
            int16_t y = (int16_t) sCore->busRead16(sCore, sb1 + 2);
            if (frame >= nextAct && !keys) {
                int key = -1;
                if (x > targetX) key = KEY_LEFT;
                else if (x < targetX) key = KEY_RIGHT;
                else if (y > targetY) key = KEY_UP;
                else if (y < targetY) key = KEY_DOWN;
                if (key < 0) {
                    phase = FACE;
                    nextAct = frame + 10;
                } else {
                    keys = 1u << key;
                    holdUntil = frame + 12;  // long enough to step, not just turn
                    nextAct = frame + 12 + STEP_GAP;
                }
            }
            break;
        }
        case FACE:
            if (frame >= nextAct && !keys) {
                keys = 1u << KEY_UP;  // sign sits one tile above target
                holdUntil = frame + TAP_FRAMES;
                phase = PRESS;
                nextAct = frame + 20;
            }
            break;
        case PRESS:
            if (frame >= nextAct && !keys) {
                keys = 1u << KEY_A;
                holdUntil = frame + TAP_FRAMES;
                phase = TEXTBOX;
                nextAct = frame + 150;  // let the msgbox finish drawing
            }
            break;
        case TEXTBOX:
            if (frame >= nextAct) {
                shot("interact");
                rc = finish("PASS", "interacted with test spot", frame);
            }
            break;
        }
    }

    if (rc < 0) {
        char msg[128];
        uint32_t sb1 = sCore->busRead32(sCore, sb1Ptr);
        snprintf(msg, sizeof(msg), "timeout in phase %d at pos %d,%d", (int) phase,
                 (int16_t) sCore->busRead16(sCore, sb1),
                 (int16_t) sCore->busRead16(sCore, sb1 + 2));
        shot("timeout");
        rc = finish("FAIL", msg, frame);
    }

    mCoreConfigDeinit(&sCore->config);
    sCore->deinit(sCore);
    free(videoBuffer);
    return rc;
}
