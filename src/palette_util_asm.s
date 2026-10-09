@@ Thumb implementation for:
@@
@@ void ReplacePalIndexInTile(Tile4BPP *tile, u32 old, u32 new)
@@ {
@@     for (u32 i = 0; i < 8; i++)
@@     {
@@         u32 mask = tile->data[i] ^ (0x11111111u * old);
@@         mask |= mask >> 1;
@@         mask |= mask >> 2;
@@         mask = (~mask & 0x11111111u) * 0xFu;
@@         tile->data[i] = (tile->data[i] & ~mask) | ((0x11111111u * new) & mask);
@@     }
@@ }

.syntax unified
.thumb
.section .text
.balign 2

.global ReplacePalIndexInTile
.type ReplacePalIndexInTile, %function

@@================================================== 
@@ Replaces given palette index in 8 pixel tile row
@@ --parameters:
@@ offset: byte offset for the row to replace
@@ -- Inputs:
@@ r1: oldIndex as word
@@ r2: newIndex as word
@@ r5: address of tile
@@ r4: holds 0x11111111u
@@ -- Clobbers: r0, r3, r6, r7
@@================================================== 
.macro replace_pal_in_row offset:req
	@ Load row into r0
	ldr  r0, [r5, \offset]
	movs r7, r0 @ Backup into r7 for later

	@ Clear nibbles matching oldIndex
	eors r0, r1

	@ Propagate set bits to the right in each nibble
	lsrs r3, r0, 1
	orrs r0, r3
	lsrs r3, r0, 2
	orrs r0, r3

	@ Clear the 3 high bits in each nibble
	mvns r0, r0
	ands r0, r4

	@ Multiply by 0xF
	movs r3, 0xF
	muls r0, r3

	@ Apply mask to newIndex
	movs r6, r2
	ands r6, r0

	@ Invert mask and apply to row
	mvns r0, r0
	ands r7, r0

	@ Combine to create the replaced row
	orrs r7, r6

	@ Writes new row back to memory
	str  r7, [r5, \offset] 
.endm


@@================================================== 
@@ Inputs:
@@ r0 = tileAddress
@@ r1 = oldIndex
@@ r2 = newIndex
@@ Used Regs:
@@ r4 = 0x11111111u
@@ r5 = Saved tileAddress
@@================================================== 
ReplacePalIndexInTile:
push {r4-r7} @ push onto stack

@ Load 0x11111111 into r4
movs r3, 0x11
lsls r4, r3, 8
orrs r4, r3
lsls r3, r4, 16
orrs r4, r3

@ Multiply old & new by 0x11111111u
muls r1, r4
muls r2, r4

@ Save tile address into r5
movs r5, r0

@ Replace pal in all 8 tile rows
replace_pal_in_row 0
replace_pal_in_row 4
replace_pal_in_row 8
replace_pal_in_row 12
replace_pal_in_row 16
replace_pal_in_row 20
replace_pal_in_row 24
replace_pal_in_row 28

@ restore registers and return
pop {r4-r7} 
bx lr
