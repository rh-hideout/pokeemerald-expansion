#ifndef GUARD_ALLOC_H
#define GUARD_ALLOC_H


#define FREE_AND_SET_NULL(ptr)          \
do {                                    \
    Free(ptr);                          \
    ptr = NULL;                         \
} while (0)

#define TRY_FREE_AND_SET_NULL(ptr) if (ptr != NULL) FREE_AND_SET_NULL(ptr)

#define MALLOC_SYSTEM_ID 0xA3A3

struct MemBlock
{
    // Whether this block is currently allocated.
    u16 allocated:1;

    u16 unused_00:4;

    // High 11 bits of caller pointer.
    u16 callerHi:11;

    // Magic number used for error checking. Should equal MALLOC_SYSTEM_ID.
    u16 magic;

    // Size of the block (not including this header struct).
    u32 size:18;

    // Low 14 bits of caller pointer.
    u32 callerLo:14;

    // Previous block pointer. Equals sHeapStart if this is the first block.
    struct MemBlock *prev;

    // Next block pointer. Equals sHeapStart if this is the last block.
    struct MemBlock *next;

    // Data in the memory block. (Arrays of length 0 are a GNU extension.)
    u8 data[0];
};

#define HEAP_SIZE 0x1C500
extern u8 gHeap[HEAP_SIZE];

void *Alloc(u32 size);
void *AllocUnchecked(u32 size);
void *AllocZeroed(u32 size);
void *AllocZeroedUnchecked(u32 size);
void Free(void *pointer);
void InitHeap(void *heapStart, u32 heapSize);
void PrintHeap(void);

const struct MemBlock *HeapHead(void);
const void *MemBlockCaller(const struct MemBlock *block);

#endif // GUARD_ALLOC_H
