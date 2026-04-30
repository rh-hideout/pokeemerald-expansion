	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_evolved_Ch5:
	gbs_switch 4
	toggle_sfx
	note_type 1, 12, 1
	octave 4
	note C_, 2
	note E_, 2
	note C_, 2
	note E_, 3
	note G_, 3
	note B_, 3
	octave 5
	note E_, 2
	note C_, 2
	note E_, 2
	note G_, 3
	note B_, 3
	octave 7
	note C_, 16
	sound_ret

	.align 4
	.global gbs_sfx_evolved_Header
gbs_sfx_evolved_Header:
	.byte 1	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_evolved_Ch5
