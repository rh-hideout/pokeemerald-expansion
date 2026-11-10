#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

// Max size of one frame in bytes: 256 tiles. The header stores the frame size
// as (frame_size / 32) - 1 -- the 0-based index of the last tile -- so the 8-bit
// field covers 1..256 tiles (RlFastUncomp adds 1 back, then multiplies by 32)
#define MAX_FRAME_SIZE (256 * 32)
#define MAX_FRAMES 255
#define MAX_HEADER_SIZE (MAX_FRAMES * 2 + 2)
#define MAX_COMP_FRAME_SIZE (MAX_FRAME_SIZE * 2) // Worst case compression ratio should be well below 2x

// Longest single run of zero-fill / copy bytes
#define MAX_ZERO_RUN_SHORT 255
#define MAX_ZERO_RUN_LONG 1024 // HINT: This could be as long as 32767
#define MAX_COPY_RUN 128

static uint16_t frame_buf[MAX_FRAME_SIZE / sizeof(uint16_t)];
static uint16_t comp_buf[MAX_COMP_FRAME_SIZE / sizeof(uint16_t)];
static uint8_t  final_buf[MAX_COMP_FRAME_SIZE * (MAX_FRAMES + 1) + MAX_HEADER_SIZE];
static uint8_t  header_buf[MAX_HEADER_SIZE];
static uint16_t comp_frame_sizes[MAX_FRAMES + 1];

// HINT: Change to 'true' to see a per-file summary of lengths. This is
// useful for tweaking the algorithm.
static bool log_stats = false;
static uint16_t stats_zero_lengths[MAX_ZERO_RUN_LONG + 1];
static uint16_t stats_copy_lengths[MAX_COPY_RUN + 1];

// Count a run of zero halfwords up to max_zero_run
static uint16_t find_zero_run(uint16_t const *data, uint16_t const *end, uint16_t max_zero_run) {
    uint16_t run = 0;
    while (run < max_zero_run && data < end && *data == 0x0000) {
        data++;
        run++;
    }
    return run;
}

// Count a run of halfwords to copy up to MAX_COPY_RUN
static uint8_t find_copy_run(uint16_t const *data, uint16_t const *end) {
    uint8_t run = 0;
    uint8_t zero_run = 0;
    for (;;) {
        if (data == end)
            return run;

        // If the max length is reached, only copy until the most recent
        // zero halfword (if any). This may make better use of the next
        // frame.
        if (run == MAX_COPY_RUN)
            return zero_run > 0 ? zero_run : run;
        if (data[0] == 0x0000)
            zero_run = run;

        // If the next two halfwords are zeros, end the run so that they
        // are part of the next frame's zero. Single instances of zero
        // halfwords are included in the copy because either way they
        // would cost two bytes, and this way reduces the number of
        // rlz_loop iterations in the decompressor.
        if (data[0] == 0x0000 && data + 1 < end && data[1] == 0x0000)
            return run;

        data++;
        run++;
    }
}

static void rl_compress(uint16_t const *uncomp, uint16_t *out, size_t len, size_t *comp_size) {
    uint16_t *write_ptr = out;
    uint16_t const *read_ptr = uncomp;
    uint16_t const *end = uncomp + len / sizeof(*uncomp);

    while (read_ptr < end) {
        uint8_t copy_run = find_copy_run(read_ptr, end);
        uint16_t zero_run;
        if (copy_run != 0) {
            zero_run = find_zero_run(read_ptr + copy_run, end, MAX_ZERO_RUN_SHORT);
            *write_ptr++ = ((copy_run - 1) << 9) | (zero_run << 1) | 1;
        }
        else {
            zero_run = find_zero_run(read_ptr + copy_run, end, MAX_ZERO_RUN_LONG);
            *write_ptr++ = zero_run << 1;
        }

        memcpy(write_ptr, read_ptr, copy_run * sizeof(*read_ptr));
        write_ptr += copy_run;
        read_ptr += copy_run + zero_run;

        stats_zero_lengths[zero_run]++;
        stats_copy_lengths[copy_run]++;
    }

    *comp_size = (size_t)((uint8_t *)write_ptr - (uint8_t *)out);
}

static void usage(const char *prog) {
    fprintf(stderr, "Usage: %s <input> <output> [-mwidth <width>] [-mheight <height>]\n", prog);
}

static void set_dimension(const char *name, const char *value, uint16_t *dim) {
    char *endptr;
    unsigned long parsed = strtoul(value, &endptr, 10);
    if (endptr == value || parsed > UINT16_MAX) {
        fprintf(stderr, "Error: invalid value '%s' for %s\n", value, name);
        exit(1);
    }
    *dim = (uint16_t)parsed;
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Error: not enough parameters\n");
        usage(argv[0]);
        return 1;
    }

    // Frame dimensions, may come from "mwidth_"/"mheight_" tags in the
    // filename or from -mwidth/-mheight arguments
    uint16_t mwidth = 4, mheight = 4;

    const char *mwidth_str = strstr(argv[1], "mwidth_");
    if (mwidth_str)
        set_dimension("mwidth_", mwidth_str + strlen("mwidth_"), &mwidth);

    const char *mheight_str = strstr(argv[1], "mheight_");
    if (mheight_str)
        set_dimension("mheight_", mheight_str + strlen("mheight_"), &mheight);

    // Options start after input (argv[1]) and output (argv[2])
    for (int i = 3; i < argc; i++) {
        if (strcmp(argv[i], "-mwidth") == 0) {
            if (i + 1 >= argc) {
                fprintf(stderr, "Error: -mwidth requires a value\n");
                return 1;
            }
            set_dimension("-mwidth", argv[++i], &mwidth);
        }
        else if (strcmp(argv[i], "-mheight") == 0) {
            if (i + 1 >= argc) {
                fprintf(stderr, "Error: -mheight requires a value\n");
                return 1;
            }
            set_dimension("-mheight", argv[++i], &mheight);
        }
        else {
            fprintf(stderr, "Error: unknown argument '%s'\n", argv[i]);
            usage(argv[0]);
            return 1;
        }
    }

    uint32_t frame_size = mwidth * mheight * 32;
    if (frame_size == 0 || frame_size > MAX_FRAME_SIZE) {
        fprintf(stderr, "Error: frame size %u bytes is not between 1 and %d bytes\n", frame_size, MAX_FRAME_SIZE);
        return 1;
    }
 
    FILE *input_file = fopen(argv[1], "rb");
    if (!input_file) {
        fprintf(stderr, "Error: could not open input file '%s'\n", argv[1]);
        return 1;
    }

    size_t frame_num = 0;
    uint8_t *frames_write_ptr = final_buf;
    while (frame_num <= MAX_FRAMES) {
        size_t read_size = fread(frame_buf, 1, frame_size, input_file);
        if (read_size == 0)
            break; // EOF: no more frames
        if (read_size != frame_size || ferror(input_file)) {
            fprintf(stderr, "Error: could not read frame %zu (expected %u bytes, got %zu)\n", frame_num, frame_size, read_size);
            fclose(input_file);
            return 1;
        }

        size_t comp_size;
        rl_compress(frame_buf, comp_buf, frame_size, &comp_size);
        memcpy(frames_write_ptr, comp_buf, comp_size);
        frames_write_ptr += comp_size;
        comp_frame_sizes[frame_num] = (uint16_t)comp_size;
        frame_num++;
    }
    fclose(input_file);

    if (frame_num > MAX_FRAMES) {
        fprintf(stderr, "Error: input has %zu frames; at most %d are supported (header frame count is 8-bit)\n", frame_num, MAX_FRAMES);
        return 1;
    }
    if (frame_num == 0) {
        fprintf(stderr, "Error: no frames found in '%s'\n", argv[1]);
        return 1;
    }

    header_buf[0] = (uint8_t)(frame_size / 32 - 1); // 0-based last tile index
    header_buf[1] = (uint8_t)frame_num;
    uint32_t off = frame_num * 2; // HINT: offset relative to header_buf[2].
    uint8_t *header_write_ptr = header_buf + 2;
    for (size_t i = 0; i < frame_num; i++) {
        if (off > UINT16_MAX) {
            fprintf(stderr, "Error: offset for frame %zu (%u) would exceed the 16-bit frame offsets the header supports\n", i, off);
            return 1;
        }
        *header_write_ptr++ = (uint8_t)(off & 0xFF);
        *header_write_ptr++ = (uint8_t)((off >> 8) & 0xFF);
        off += comp_frame_sizes[i];
    }

    FILE *output_file = fopen(argv[2], "wb");
    if (!output_file) {
        fprintf(stderr, "Error: could not open output file '%s'\n", argv[2]);
        return 1;
    }

    size_t header_size = header_write_ptr - header_buf;
    size_t frames_size = frames_write_ptr - final_buf;
    size_t total_len = frames_size + header_size;
    if (fwrite(header_buf, 1, header_size, output_file) != header_size || fwrite(final_buf, 1, frames_size, output_file) != frames_size) {
        fprintf(stderr, "Error: could not write output file '%s'\n", argv[2]);
        fclose(output_file);
        return 1;
    }
    // Pad to a 32-bit boundary
    uint8_t pad[3] = { 0, 0, 0 };
    size_t pad_len = (4 - (total_len % 4)) % 4;
    if (fwrite(pad, 1, pad_len, output_file) != pad_len) {
        fprintf(stderr, "Error: could not write output file '%s'\n", argv[2]);
        fclose(output_file);
        return 1;
    }

    if (fclose(output_file) != 0) {
        fprintf(stderr, "Error: could not close output file '%s'\n", argv[2]);
        return 1;
    }

    if (log_stats) {
        for (int i = 0; i < MAX_ZERO_RUN_LONG + 1; i++)
        {
            if (stats_zero_lengths[i] > 0)
                fprintf(stderr, "zero-fill %d halfwords: %d\n", i, stats_zero_lengths[i]);
        }
        for (int i = 0; i < MAX_COPY_RUN + 1; i++)
        {
            if (stats_copy_lengths[i] > 0)
                fprintf(stderr, "copy %d halfwords: %d\n", i, stats_copy_lengths[i]);
        }
    }

    return 0;
}
