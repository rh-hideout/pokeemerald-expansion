#include "global.h"
#include "decompress_error_handler.h"

void DecompressionError(const u32 *src, enum CompressionError error)
{
    errorf("Decompression failed.\nAddress: 0x%p\nError: 0x%x\n", src, error);
}

void DoDecompressionError(void)
{
    DecompressionError((u32 *)0x12345678, HEADER_ERROR);
}
