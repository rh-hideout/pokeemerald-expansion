#include "global.h"
#include "malloc.h"
#include "postlink.h"
#if TESTING
#include "test/test.h"
#endif

static void *sHeapStart;
static u32 sHeapSize;

ALIGNED(4) EWRAM_DATA u8 gHeap[HEAP_SIZE] = {0};

void PutMemBlockHeader(void *block, struct MemBlock *prev, struct MemBlock *next, u32 size)
{
    struct MemBlock *header = (struct MemBlock *)block;

    header->allocated = FALSE;
    header->callerHi = 0;
    header->magic = MALLOC_SYSTEM_ID;
    header->size = size;
    header->callerLo = 0;
    header->prev = prev;
    header->next = next;
}

void PutFirstMemBlockHeader(void *block, u32 size)
{
    PutMemBlockHeader(block, (struct MemBlock *)block, (struct MemBlock *)block, size - sizeof(struct MemBlock));
}

static void *AllocInternal(void *heapStart, u32 size, const char *caller)
{
    struct MemBlock *pos = (struct MemBlock *)heapStart;
    struct MemBlock *head = pos;
    struct MemBlock *splitBlock;
    u32 foundBlockSize;

    // Alignment
    if (size & 3)
        size = 4 * ((size / 4) + 1);

    for (;;)
    {
        // Loop through the blocks looking for unused block that's big enough.

        if (!pos->allocated)
        {
            foundBlockSize = pos->size;

            if (foundBlockSize >= size)
            {
                if (foundBlockSize - size < 2 * sizeof(struct MemBlock))
                {
                    // The block isn't much bigger than the requested size,
                    // so just use it.
                    pos->allocated = TRUE;
                }
                else
                {
                    // The block is significantly bigger than the requested
                    // size, so split the rest into a separate block.
                    foundBlockSize -= sizeof(struct MemBlock);
                    foundBlockSize -= size;

                    splitBlock = (struct MemBlock *)(pos->data + size);

                    pos->allocated = TRUE;
                    pos->size = size;

                    PutMemBlockHeader(splitBlock, pos, pos->next, foundBlockSize);

                    pos->next = splitBlock;

                    if (splitBlock->next != head)
                        splitBlock->next->prev = splitBlock;
                }

                pos->callerHi = ((uintptr_t)caller) >> 14;
                pos->callerLo = (uintptr_t)caller;

                return pos->data;
            }
        }

        if (pos->next == head)
            return NULL;

        pos = pos->next;
    }
}

static void FreeInternal(void *heapStart, void *pointer)
{
    if (pointer)
    {
        struct MemBlock *head = (struct MemBlock *)heapStart;
        struct MemBlock *block = (struct MemBlock *)((u8 *)pointer - sizeof(struct MemBlock));
        AGB_ASSERT(block->magic == MALLOC_SYSTEM_ID);
        AGB_ASSERT(block->allocated == TRUE);
        block->allocated = FALSE;

        // If the freed block isn't the last one, merge with the next block
        // if it's not in use.
        if (block->next != head)
        {
            if (!block->next->allocated)
            {
                block->size += sizeof(struct MemBlock) + block->next->size;
                block->next->magic = 0;
                block->next = block->next->next;
                if (block->next != head)
                    block->next->prev = block;
            }
        }

        // If the freed block isn't the first one, merge with the previous block
        // if it's not in use.
        if (block != head)
        {
            if (!block->prev->allocated)
            {
                AGB_ASSERT(block->prev->magic == MALLOC_SYSTEM_ID);

                block->prev->next = block->next;

                if (block->next != head)
                    block->next->prev = block->prev;

                block->magic = 0;
                block->prev->size += sizeof(struct MemBlock) + block->size;
            }
        }
    }
}

static void *AllocZeroedInternal(void *heapStart, u32 size, const char *caller)
{
    void *mem = AllocInternal(heapStart, size, caller);

    if (mem != NULL)
    {
        if (size & 3)
            size = 4 * ((size / 4) + 1);

        CpuFill32(0, mem, size);
    }

    return mem;
}

static bool32 CheckMemBlockInternal(void *heapStart, void *pointer)
{
    struct MemBlock *head = (struct MemBlock *)heapStart;
    struct MemBlock *block = (struct MemBlock *)((u8 *)pointer - sizeof(struct MemBlock));

    if (block->magic != MALLOC_SYSTEM_ID)
        return FALSE;

    if (block->next->magic != MALLOC_SYSTEM_ID)
        return FALSE;

    if (block->next != head && block->next->prev != block)
        return FALSE;

    if (block->prev->magic != MALLOC_SYSTEM_ID)
        return FALSE;

    if (block->prev != head && block->prev->next != block)
        return FALSE;

    if (block->next != head && block->next != (struct MemBlock *)(block->data + block->size))
        return FALSE;

    return TRUE;
}

void InitHeap(void *heapStart, u32 heapSize)
{
    sHeapStart = heapStart;
    sHeapSize = heapSize;
    PutFirstMemBlockHeader(heapStart, heapSize);
}

void PrintHeap(void)
{
    const struct MemBlock *head = HeapHead();
    const struct MemBlock *block = head;
    do
    {
        if (block->allocated)
            DebugPrintf("%p: %d bytes allocated", MemBlockCaller(block), block->size);
        block = block->next;
    }
    while (block != head);
}

void *Alloc(u32 size)
{
    const void *caller = PostlinkReturnAddress(2);
    void *p = AllocInternal(sHeapStart, size, caller);
    if (!p)
    {
        if (TESTING)
            PrintHeap();
        fatalf("%p: out of memory trying to allocate %d bytes", caller, size);
    }
    return p;
}

void *AllocUnchecked(u32 size)
{
    const void *caller = __builtin_return_address(0);
    return AllocInternal(sHeapStart, size, caller);
}

void *AllocZeroed(u32 size)
{
    const void *caller = __builtin_return_address(0);
    void *p = AllocZeroedInternal(sHeapStart, size, caller);
    if (!p)
    {
        if (TESTING)
            PrintHeap();
        fatalf("%p: out of memory trying to allocate %d bytes", caller, size);
    }
    return p;
}

void *AllocZeroedUnchecked(u32 size)
{
    const void *caller = __builtin_return_address(0);
    return AllocZeroedInternal(sHeapStart, size, caller);
}

void Free(void *pointer)
{
    FreeInternal(sHeapStart, pointer);
}

bool32 CheckMemBlock(void *pointer)
{
    return CheckMemBlockInternal(sHeapStart, pointer);
}

bool32 CheckHeap()
{
    struct MemBlock *pos = (struct MemBlock *)sHeapStart;

    do {
        if (!CheckMemBlockInternal(sHeapStart, pos->data))
            return FALSE;
        pos = pos->next;
    } while (pos != (struct MemBlock *)sHeapStart);

    return TRUE;
}

const struct MemBlock *HeapHead(void)
{
    return (const struct MemBlock *)sHeapStart;
}

const void *MemBlockCaller(const struct MemBlock *block)
{
    if (!block->allocated)
        return NULL;

    return (const void *)(ROM_START | (block->callerHi << 14) | block->callerLo);
}
