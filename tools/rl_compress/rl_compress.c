#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

// Currently 8bpp 64 x 64
#define MAX_FRAME_SIZE (64 * 64)
#define MAX_FRAMES 256
#define MAX_HEADER_SIZE (MAX_FRAMES * 2 + 2)

uint8_t frame_buf[MAX_FRAME_SIZE];
uint8_t comp_buf[MAX_FRAME_SIZE * 2];
uint8_t final_buf[MAX_FRAME_SIZE * MAX_FRAMES + MAX_HEADER_SIZE];
uint8_t header_buf[MAX_HEADER_SIZE];
uint16_t comp_frame_sizes[MAX_FRAMES];

uint16_t find_zero_run(uint8_t *data, size_t len) {
    uint16_t longest = 0;
    uint8_t *read_ptr = data;
    while (longest < 510 && read_ptr < data + len && *read_ptr == 0) {
        longest += 1;
        read_ptr++;
    }
    if (longest % 2 != 0)
        longest -= 1;
    return longest;
}

uint16_t find_non_zero_run(uint8_t *data, size_t len) {
    uint16_t longest = 0;
    uint8_t *read_ptr = data;
    while (longest < 510 && read_ptr < data + len && (*read_ptr != 0 || (read_ptr < data + len + 1 && *(read_ptr + 1) != 0))) {
        longest += 1;
        read_ptr++;
    }
    if (longest % 2 != 0)
        longest += 1;
    return longest;
}

size_t rl_compress(uint8_t *uncomp, size_t len) {
    uint8_t *compressed = comp_buf;
    uint8_t *read_ptr = uncomp;
    while (read_ptr < uncomp + len) {
        uint16_t current_run_z = find_zero_run(read_ptr, len - (read_ptr - uncomp));
        *compressed++ = current_run_z / 2;
        read_ptr += current_run_z;
        uint16_t current_run_nz = find_non_zero_run(read_ptr, len - (read_ptr - uncomp));
        *compressed++ = current_run_nz / 2;
        memcpy(compressed, read_ptr, current_run_nz);
        compressed += current_run_nz;
        read_ptr += current_run_nz;
    }
    return compressed - comp_buf;
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Not enough parameters\n");
        return 1;
    }

    unsigned int mwidth = 4, mheight = 4;

    const char *mwidth_str = strstr(argv[1], "mwidth_");
    if (mwidth_str) {
        mwidth_str += strlen("mwidth_");
        mwidth = strtoul(mwidth_str, NULL, 10);
    }

    const char *mheight_str = strstr(argv[1], "mheight_");
    if (mheight_str) {
        mheight_str += strlen("mheight_");
        mheight = strtoul(mheight_str, NULL, 10);
    }

    for (size_t i = 2; i < argc; i++) {
        if (!strcmp(argv[i], "-mwidth")) {
            if (i + 1 >= argc)
                return 1;

            i++;

            mwidth = strtoul(argv[i], NULL, 10);
        }
        else if (!strcmp(argv[i], "-mheight")) {
            if (i + 1 >= argc)
                return 1;

            i++;

            mheight = strtoul(argv[i], NULL, 10);
        }
    }

    int ret = 0;

    FILE *input_file = fopen(argv[1], "r");
    size_t frame_size = ((mwidth * 8) * (mheight * 8)) / 2;

    size_t frame_num;
    uint8_t *frames_write_ptr = final_buf;
    for (frame_num = 0; frame_num < MAX_FRAMES; frame_num++) {
        size_t read_frames = fread(frame_buf, 1, frame_size, input_file);
        if (read_frames != frame_size) {
            if (!feof(input_file)) {
                fprintf(stderr, "Error: Could not read frame %u from file\n", frame_num);
                ret = 1;
                goto comp_end;
            }
            else
                break;
        }

        size_t comp_size = rl_compress(frame_buf, frame_size);
        memcpy(frames_write_ptr, comp_buf, comp_size);
        frames_write_ptr += comp_size;

        comp_frame_sizes[frame_num] = comp_size;
    }

    if (frame_num >= MAX_FRAMES) {
        fprintf(stderr, "Error: More then %d frames are now allowed\n", MAX_FRAMES);
        ret = 1;
        goto comp_end;
    }

    header_buf[0] = frame_num;
    header_buf[1] = frame_size / 32;

    size_t offset = 2 + frame_num * 2;
    uint8_t *header_write_ptr = header_buf + 2;
    for (size_t i = 0; i < frame_num; i++) {
        *header_write_ptr++ = offset & 0xFF;
        *header_write_ptr++ = (offset >> 8) & 0xFF;
        offset += comp_frame_sizes[i];
    }

    FILE *output_file = fopen(argv[2], "w");
    fwrite(header_buf, 1, header_write_ptr - header_buf, output_file);
    fwrite(final_buf, 1, frames_write_ptr - final_buf, output_file);
    uint32_t tmp_zero = 0;
    size_t pad_len = 4 - (((header_write_ptr - header_buf) + (frames_write_ptr - final_buf)) % 4);
    fwrite((void *)&tmp_zero, 1, pad_len, output_file);
    fclose(output_file);

comp_end:

    fclose(input_file);
    return ret;
}
