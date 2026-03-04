#include <stdio.h>
#include <stddef.h>
#include "global.h"

int main(void)
{
    printf("sizeof(struct SaveBlock1) = 0x%zx\n", sizeof(struct SaveBlock1));
    printf("offsetof(struct SaveBlock1, flags) = 0x%zx\n", offsetof(struct SaveBlock1, flags));
    return 0;
}
