	.syntax unified

	.include "constants/gba_constants.inc"

	.arm
	.section .iwram.code, "ax", %progbits
	.align 2

.global FastUnsafeCopy32
.type FastUnsafeCopy32, %function

	@ Word aligned, 32-byte copy
	@ This function WILL overwrite your buffer, so make sure it is at least 32 bytes larger than the desired size.
FastUnsafeCopy32:
	push    {r4-r10}
.Lloop_32:
	ldmia r1!, {r3-r10}
	stmia r0!, {r3-r10}
	subs    r2, r2, #32
	bgt     .Lloop_32
	pop     {r4-r10}
	bx    lr

.global RlFastUncompUnsafe

	// header (see src):
	// struct RLFrameHeader {
	//   u16 frame_size_tiles: 8;
	//   u16 n_frames: 8;
	//   u16 offsets[n_frames]; // relative to &src->offsets, not src
	// }
	// followed by compressed data frames:
	// union RLFrame {
	//   struct {
	//     u16 zero: 1; // literally 0
	//     u16 zerofill_halfwords: 15;
	//   }
	//   struct {
	//     u16 one: 1; // literally 1
	//     u16 zerofill_halfwords: 8;
	//     u16 copy_halfwords_m1: 7; // copy_halfwords - 1
	//   }
	//   u16 data[copy_halfwords]; // if first struct, length is 0
	// }

	@ r0 = src (word aligned)
	@ r1 = frame_index
	@ r2 = dst (word aligned)

RlFastUncompUnsafe:
	ldrh r3, [r0], #2 // r3 = (frame_size_tiles - 1) | (n_frames << 8)
	cmp r1, r3, lsr #8 // check if frame_index is out of bounds
	bxge lr

	push {r4-r7}

	lsl r1, #1
	ldrh r1, [r0, r1]
	add r1, r0 // r1 = src->offset + src->offset[frame_index]

	and r3, #0x00FF // r3 = frame_size_tiles - 1
	add r3, #0x01 // r3 = frame_size_tiles
	add r3, r2, r3, lsl #5 // r3 = dst + (frame_size_tiles << 5) = dst + frame_size_bytes

	adr r0, .LRlFastUncompUnsafePool
	ldmia r0, {r4, r5}

	// r0: &0x0000
	// r1: frame
	// r2: dest
	// r3: end
	// r4: DMA_ENABLE << 16
	// r5: REG_DMA3SAD
.LRlFastUncompUnsafeLoop:
	//    r6 = (zerofill_halfwords << 1) | 0
	// or r6 = ((copy_halfwords - 1) << 9) | (zerofill_halfwords << 1) | 1
	ldrh r6, [r1], #2

	//    C = 0 and r6 = zerofill_halfwords and Z = zerofill_halfwords == 0
	// or C == 1 and r6 = ((copy_halfwords - 1) << 8) | zerofill_halfwords
	lsrs r6, #1

	// HINT: If C is 1, do a copy DMA.
	// HINT: C is 1 so adc adds one to (copy_halfwords - 1).
	adccs r7, r4, r6, lsr #8 // r7 = (DMA_ENABLE << 16) | copy_halfwords
	stmiacs r5, {r1, r2, r7}
	addcs r1, r1, r7, lsl #1
	addcs r2, r2, r7, lsl #1

	// HINT: If C is 1, mask out copy_halfwords and compute Z.
	// If C is 0, all the bits are zero_halfwords and Z is already
	// computed.
	andscs r6, #0xFF
	// HINT: Is Z is 0, do a zero-fill DMA.
	orrne r7, r6, (DMA_ENABLE | DMA_SRC_FIXED) << 16
	stmiane r5, {r0, r2, r7}
	addne r2, r2, r6, lsl #1

	cmp r2, r3
	bne .LRlFastUncompUnsafeLoop

	pop {r4-r7}
	bx lr

	// HINT: ldrh .LRlFastUncompUnsafePool == 0x0000
.LRlFastUncompUnsafePool:
	.word DMA_ENABLE << 16
	.word REG_DMA3SAD

	.section .text @Copied to stack on run-time
	.align 2

.global LZ77UnCompWRAMOptimized
.type LZ77UnCompWRAMOptimized, %function
LZ77UnCompWRAMOptimized: @ 0x000010FC
	push {r4, r5, r6, lr}
	// read in data header in r5
	// Data header (32bit)
	// Bit 0-3   Reserved
	// Bit 4-7   Compressed type (must be 1 for LZ77)
	// Bit 8-31  Size of decompressed data
	ldr r5, [r0], #4
	// store decompressed size in r2
	lsr r2, r5, #8
	// main loop
	cmp r2, #0
	ble LZ77_Done
LZ77_MainLoop:
	// read in Flag Byte
	// Flag data (8bit)
	// Bit 0-7   Type Flags for next 8 Blocks, MSB first
	ldrb lr, [r0], #1
	// shift to the highest byte
	lsl lr, lr, #24
	// 8 blocks so set counter (r4) to 8
	mov r4, #8
	b LZ77_EightBlockLoop
LZ77_HandleCompressedData:
	// reading in block type 1 Part 1 into r5
	// Block Type 1 Part 1 - Compressed - Copy N+3 Bytes from Dest-Disp-1 to Dest
	// Bit 0-3   Disp MSBs
	// Bit 4-7   Number of bytes to copy (minus 3)
	// byte copy range: [3, 18]
	ldrb r5, [r0], #1
	

	// 18 -> 0
	// 17 -> 1
	// 16 -> 2
	// ...
	// 3 -> 15
	// formula: do 18 - x
	// want to calculate r3 = 18 - (3 + (numBytesToCopy))
	// r3 = 18 - 3 - (numBytesToCopy)
	// r3 = 15 - numBytesToCopy
	// but then also need to do r2 = r2 - (3 + (numBytesToCopy))
	// r2 = r2 - 3 - numBytesToCopy
	// r2 = r2 - 18 + 18 - 3 - numBytesToCopy
	// r2 = r2 - 18 + 15 - numBytesToCopy
	
	mov r6, #3
	// r3 = 3 + (numBytesToCopy)
	add r3, r6, r5, asr #4
	// get displacement high bits
	and r5, r5, #0xf
	// Now reading Block Type 1 Part 2 into r6
	// Block type 1 Part 2
	// Bit 0-7  Disp LSBs
	ldrb r6, [r0], #1
	// combine low and high bits into r6
	orr r6, r6, r5, lsl #8
	// +1 because of reasons
	add r6, r6, #1
	// subtract how many bytes are going to be copied from the size
	subs r2, r2, r3

	// do duff's device
	// https://en.wikipedia.org/wiki/Duff%27s_device
	// calculate pc offset
	rsb r3, r3, #18
	// jump
	add pc, pc, r3, lsl #3
	nop
	.rept 18
	ldrb r5, [r1, -r6]
	strb r5, [r1], #1
	.endr

	// cpsr flags still preserved from earlier
	// check if no more bytes have to be copied
	ble LZ77_Done
	// check if end of the block
	subs r4, r4, #1
	ble LZ77_MainLoop
LZ77_EightBlockLoop:
	// check if compressed data (bit set)
	lsls lr, lr, #1
	bcs LZ77_HandleCompressedData
	// uncompressed data can only be 1 byte long
	// copy one byte of uncompressed data
	ldrb r6, [r0], #1
	strb r6, [r1], #1
	subs r2, r2, #1
	ble LZ77_Done
LZ77_EightBlockLoop_HandleLoop:
	// check if we're done with the 8 blocks
	subs r4, r4, #1
	bgt LZ77_EightBlockLoop // go back to main loop if so
	// no need to check if r2 is 0 since already checked elsewhere
	b LZ77_MainLoop
LZ77_Done:
	pop {r4, r5, r6, lr}
	bx lr

.global LZ77UnCompWRAMOptimized_end
LZ77UnCompWRAMOptimized_end:
