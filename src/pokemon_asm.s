	.syntax unified
        .text

	.include "constants/gba_constants.inc"
	.include "asm/macros/function.inc"

#define OFFSETOF_PERSONALITY 0
#define OFFSETOF_SECURE 32

@ void FastShuffleSubstructs(struct BoxPokemon *, mode)
	thumb_func_start FastShuffleSubstructs
FastShuffleSubstructs:
	ldr r3, =0xAAAAAAAB
	ldr r2, [r0, OFFSETOF_PERSONALITY]
	adds r0, OFFSETOF_SECURE
	bx pc
	.arm
	@ Switch to FIQ so that we have:
	@ - spsr_fiq (initialized in crt0.s) to return to SYS in Thumb.
	@ - Banked registers that don't have to be saved/restored.
	@ and suppress IRQs because FIQ aliases the IRQ stack.
	msr cpsr_c, (PSR_FIQ_MODE | PSR_I_BIT)
	@ Save unbanked registers and lr so we can ldmdb into pc.
	stmdb sp, {r4-r7, lr}^

	@ Save mode in C.
	lsrs r1, 1

	@ r14 = personality % 24.
	umull r4, r14, r2, r3
	lsr r14, 4
	add r14, r14, r14, lsl 1
	sub r14, r2, r14, lsl 3

	@ Load the substructs into r1-r3, r4-r6, r7-r9, r10-r12.
	@ Positioned as early as possible to maximize prefetch buffer
	@ opportunity.
	ldmia r0, {r1-r12}

	@ The addresses of specialized implementations are given by:
	@ Encrypt[i] = Encrypt0 + (personality % 24) * 40.
	@ Decrypt[i] = Encrypt0 + (personality % 24) * 40 + 20.

	@ r14 = ((personality % 24) * 2 + mode) * 5.
	adc r14, r14, r14        @ r14 = (personality % 24) * 2 + mode
	add r14, r14, r14, lsl 2 @ r14 = r14 * 5
.LAddPC:
	@ pc = Encrypt0 + ((personality % 24) * 2 + mode) * 20.
	add pc, pc, r14, lsl 2
	.pool
	.org .LAddPC + 8 @ Ensure that pc is Encrypt0 at .LAddPC.

	Encrypt0: stmia r0!, {r1-r3, r4-r6, r7-r9, r10-r12}; ldmdb sp, {r4-r7, pc}^; nop; nop; nop
	Decrypt0: stmia r0!, {r1-r3, r4-r6, r7-r9, r10-r12}; ldmdb sp, {r4-r7, pc}^; nop; nop; nop
	Encrypt1: stmia r0!, {r1-r3, r4-r6, r10-r12}; stmia r0!, {r7-r9}; ldmdb sp, {r4-r7, pc}^; nop; nop
	Decrypt1: stmia r0!, {r1-r3, r4-r6, r10-r12}; stmia r0!, {r7-r9}; ldmdb sp, {r4-r7, pc}^; nop; nop
	Encrypt2: stmia r0!, {r1-r3, r7-r9}; stmia r0!, {r4-r6, r10-r12}; ldmdb sp, {r4-r7, pc}^; nop; nop
	Decrypt2: stmia r0!, {r1-r3, r7-r9}; stmia r0!, {r4-r6, r10-r12}; ldmdb sp, {r4-r7, pc}^; nop; nop
	Encrypt3: stmia r0!, {r1-r3, r7-r9, r10-r12}; stmia r0!, {r4-r6}; ldmdb sp, {r4-r7, pc}^; nop; nop
	Decrypt3: stmia r0!, {r1-r3, r10-r12}; stmia r0!, {r4-r6, r7-r9}; ldmdb sp, {r4-r7, pc}^; nop; nop
	Encrypt4: stmia r0!, {r1-r3, r10-r12}; stmia r0!, {r4-r6, r7-r9}; ldmdb sp, {r4-r7, pc}^; nop; nop
	Decrypt4: stmia r0!, {r1-r3, r7-r9, r10-r12}; stmia r0!, {r4-r6}; ldmdb sp, {r4-r7, pc}^; nop; nop
	Encrypt5: stmia r0!, {r1-r3, r10-r12}; stmia r0!, {r7-r9}; stmia r0!, {r4-r6}; ldmdb sp, {r4-r7, pc}^; nop
	Decrypt5: stmia r0!, {r1-r3, r10-r12}; stmia r0!, {r7-r9}; stmia r0!, {r4-r6}; ldmdb sp, {r4-r7, pc}^; nop
	Encrypt6: stmia r0!, {r4-r6}; stmia r0!, {r1-r3, r7-r9, r10-r12}; ldmdb sp, {r4-r7, pc}^; nop; nop
	Decrypt6: stmia r0!, {r4-r6}; stmia r0!, {r1-r3, r7-r9, r10-r12}; ldmdb sp, {r4-r7, pc}^; nop; nop
	Encrypt7: stmia r0!, {r4-r6}; stmia r0!, {r1-r3, r10-r12}; stmia r0!, {r7-r9}; ldmdb sp, {r4-r7, pc}^; nop
	Decrypt7: stmia r0!, {r4-r6}; stmia r0!, {r1-r3, r10-r12}; stmia r0!, {r7-r9}; ldmdb sp, {r4-r7, pc}^; nop
	Encrypt8: stmia r0!, {r4-r6, r7-r9}; stmia r0!, {r1-r3, r10-r12}; ldmdb sp, {r4-r7, pc}^; nop; nop
	Decrypt8: stmia r0!, {r7-r9}; stmia r0!, {r1-r3, r4-r6, r10-r12}; ldmdb sp, {r4-r7, pc}^; nop; nop
	Encrypt9: stmia r0!, {r4-r6, r7-r9, r10-r12}; stmia r0!, {r1-r3}; ldmdb sp, {r4-r7, pc}^; nop; nop
	Decrypt9: stmia r0!, {r10-r12}; stmia r0!, {r1-r3, r4-r6, r7-r9}; ldmdb sp, {r4-r7, pc}^; nop; nop
	Encrypt10: stmia r0!, {r4-r6, r10-r12}; stmia r0!, {r1-r3, r7-r9}; ldmdb sp, {r4-r7, pc}^; nop; nop
	Decrypt10: stmia r0!, {r7-r9}; stmia r0!, {r1-r3, r10-r12}; stmia r0!, {r4-r6}; ldmdb sp, {r4-r7, pc}^; nop
	Encrypt11: stmia r0!, {r4-r6, r10-r12}; stmia r0!, {r7-r9}; stmia r0!, {r1-r3}; ldmdb sp, {r4-r7, pc}^; nop
	Decrypt11: stmia r0!, {r10-r12}; stmia r0!, {r1-r3, r7-r9}; stmia r0!, {r4-r6}; ldmdb sp, {r4-r7, pc}^; nop
	Encrypt12: stmia r0!, {r7-r9}; stmia r0!, {r1-r3, r4-r6, r10-r12}; ldmdb sp, {r4-r7, pc}^; nop; nop
	Decrypt12: stmia r0!, {r4-r6, r7-r9}; stmia r0!, {r1-r3, r10-r12}; ldmdb sp, {r4-r7, pc}^; nop; nop
	Encrypt13: stmia r0!, {r7-r9}; stmia r0!, {r1-r3, r10-r12}; stmia r0!, {r4-r6}; ldmdb sp, {r4-r7, pc}^; nop
	Decrypt13: stmia r0!, {r4-r6, r10-r12}; stmia r0!, {r1-r3, r7-r9}; ldmdb sp, {r4-r7, pc}^; nop; nop
	Encrypt14: stmia r0!, {r7-r9}; stmia r0!, {r4-r6}; stmia r0!, {r1-r3, r10-r12}; ldmdb sp, {r4-r7, pc}^; nop
	Decrypt14: stmia r0!, {r7-r9}; stmia r0!, {r4-r6}; stmia r0!, {r1-r3, r10-r12}; ldmdb sp, {r4-r7, pc}^; nop
	Encrypt15: stmia r0!, {r7-r9}; stmia r0!, {r4-r6, r10-r12}; stmia r0!, {r1-r3}; ldmdb sp, {r4-r7, pc}^; nop
	Decrypt15: stmia r0!, {r10-r12}; stmia r0!, {r4-r6}; stmia r0!, {r1-r3, r7-r9}; ldmdb sp, {r4-r7, pc}^; nop
	Encrypt16: stmia r0!, {r7-r9, r10-r12}; stmia r0!, {r1-r3, r4-r6}; ldmdb sp, {r4-r7, pc}^; nop; nop
	Decrypt16: stmia r0!, {r7-r9, r10-r12}; stmia r0!, {r1-r3, r4-r6}; ldmdb sp, {r4-r7, pc}^; nop; nop
	Encrypt17: stmia r0!, {r7-r9, r10-r12}; stmia r0!, {r4-r6}; stmia r0!, {r1-r3}; ldmdb sp, {r4-r7, pc}^; nop
	Decrypt17: stmia r0!, {r10-r12}; stmia r0!, {r7-r9}; stmia r0!, {r1-r3, r4-r6}; ldmdb sp, {r4-r7, pc}^; nop
	Encrypt18: stmia r0!, {r10-r12}; stmia r0!, {r1-r3, r4-r6, r7-r9}; ldmdb sp, {r4-r7, pc}^; nop; nop
	Decrypt18: stmia r0!, {r4-r6, r7-r9, r10-r12}; stmia r0!, {r1-r3}; ldmdb sp, {r4-r7, pc}^; nop; nop
	Encrypt19: stmia r0!, {r10-r12}; stmia r0!, {r1-r3, r7-r9}; stmia r0!, {r4-r6}; ldmdb sp, {r4-r7, pc}^; nop
	Decrypt19: stmia r0!, {r4-r6, r10-r12}; stmia r0!, {r7-r9}; stmia r0!, {r1-r3}; ldmdb sp, {r4-r7, pc}^; nop
	Encrypt20: stmia r0!, {r10-r12}; stmia r0!, {r4-r6}; stmia r0!, {r1-r3, r7-r9}; ldmdb sp, {r4-r7, pc}^; nop
	Decrypt20: stmia r0!, {r7-r9}; stmia r0!, {r4-r6, r10-r12}; stmia r0!, {r1-r3}; ldmdb sp, {r4-r7, pc}^; nop
	Encrypt21: stmia r0!, {r10-r12}; stmia r0!, {r4-r6, r7-r9}; stmia r0!, {r1-r3}; ldmdb sp, {r4-r7, pc}^; nop
	Decrypt21: stmia r0!, {r10-r12}; stmia r0!, {r4-r6, r7-r9}; stmia r0!, {r1-r3}; ldmdb sp, {r4-r7, pc}^; nop
	Encrypt22: stmia r0!, {r10-r12}; stmia r0!, {r7-r9}; stmia r0!, {r1-r3, r4-r6}; ldmdb sp, {r4-r7, pc}^; nop
	Decrypt22: stmia r0!, {r7-r9, r10-r12}; stmia r0!, {r4-r6}; stmia r0!, {r1-r3}; ldmdb sp, {r4-r7, pc}^; nop
	Encrypt23: stmia r0!, {r10-r12}; stmia r0!, {r7-r9}; stmia r0!, {r4-r6}; stmia r0!, {r1-r3}; ldmdb sp, {r4-r7, pc}^
	Decrypt23: stmia r0!, {r10-r12}; stmia r0!, {r7-r9}; stmia r0!, {r4-r6}; stmia r0!, {r1-r3}; ldmdb sp, {r4-r7, pc}^

	thumb_func_end FastShuffleSubstructs
