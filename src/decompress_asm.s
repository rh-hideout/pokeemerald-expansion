	.syntax unified

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

.global SmolFrameUncomp

	// header (see src):
	// struct RLFrameHeader {
	//   u16 n_frames: 8;
	//   u16 frame_size_tiles: 8;
	//   struct Offset {
	//     u16 offset: 15;
	//     u16 start_fill_mode: 1; TODO: is this actually a thing?
	//   }[n_frames];
	// }
	// followed by n_frames compressed data frames
	// they are built as follows:
	// [n] <data>
	// where n signifies the amount of 0 bytes to fill in fill mode
	// or the amount of bytes to copy from the compressed stream in copy mode
	// after a fill mode [n] follows a copy mode [n]
	// after a copy mode [n] follow <n> bytes of data, as well as a fill mode [n]
	// if the stream is fully decompressed an additional [n] is omitted,
	// the decompressor has to terminate then.

	@ r0 = src (word aligned)
	@ r1 = dst (word aligned)
	@ r2 = frame_index

SmolFrameUncomp:
	push {r4-r7}
	ldrh r3, [r0] // frame size in tiles and number of frames
	and r5, r3, #0xFF00
	lsr r5, r5, #3 // frame_size_bytes
	lsl r2, r2, #1 // index of offset compound - 2
	
// opt: we can omit this by reframing the offset to index from 2 and using incrementing ldrh above
	add r2, #2

	ldrh r2, [r0, r2] // offset compound

	add r0, r2, r0
	add r5, r5, r1 // r5 = dst + frame_size_bytes

	mov r6, #0 // for filling
	mov r7, #0x4000000
	orr r7, #0xD4 // dma3_sad
	mov r3, #(0x8000 << 16)

rlz_loop:
	ldrh r4, [r0], #2 // first 8 byte: number of fill hwords, second 8 byte: number of copy hwords

// fill stage
// (can probably be faster by improving the store loop,
// but alignment is tricky and there's a bunch of small fill compounds)
	and r2, r4, #0xFF

branch_fill_loop:
    subs r2, r2, #1
	strhge r6, [r1], #2
	bgt branch_fill_loop

// copy stage (can probably be faster by using DMA)
	lsrs r2, r4, #8
	beq skip_dma
	orr r4, r2, r3
	stmia r7, {r0, r1, r4} // dma
	//sub r7, #12
	lsl r2, #1
	add r0, r2
	add r1, r2
//branch_copy_loop:
//	subs r2, r2, #1
//	ldrhge r4, [r0], #2
//	strhge r4, [r1], #2
//	bgt branch_copy_loop
skip_dma:
	cmp r1, r5
	bne rlz_loop

decompress_done:
	pop {r4-r7}
	bx lr

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
