	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_masterball_Ch5:
	gbs_switch 4
	toggle_sfx
	duty_cycle 1
	note_type 2, 14, 1
	octave 6
	note B_, 2
	octave 7
	note D_, 2
	octave 6
	note B_, 2
	note G_, 2
	note B_, 2
	note As, 2
	note A_, 2
	note As, 2
	note A_, 2
	volume_envelope 12, 1
	note Gs, 2
	note G_, 2
	note Fs, 2
	volume_envelope 9, 1
	note F_, 2
	note E_, 2
	note Ds, 2
	volume_envelope 6, 1
	note D_, 2
	note Cs, 2
	note C_, 2
	sound_ret

	.align 4
	.global gbs_sfx_masterball_Header
gbs_sfx_masterball_Header:
	.byte 1	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_masterball_Ch5
