	.include "asm/macros.inc"

	.section .rodata
	.align 1

@ Sfx_4NoteDitty — 3 channels (Pulse1, Pulse2, Wave)
@ Ch6 and Ch7 are silent padding channels (rest only)

gbs_sfx_4noteditty_Ch5:
	gbs_switch 4
	toggle_sfx
	duty_cycle 2
	note_type 2, 14, 8
	transpose 0, 2
	octave 4
	note C_, 2
	volume_envelope 4, 8
	note C_, 2
	volume_envelope 14, 8
	note G_, 2
	volume_envelope 4, 8
	note G_, 2
	octave 5
	volume_envelope 14, 8
	note E_, 2
	volume_envelope 4, 8
	note E_, 2
	octave 6
	volume_envelope 14, 8
	note C_, 2
	volume_envelope 4, 3
	note C_, 16
	sound_ret

gbs_sfx_4noteditty_Ch6:
	gbs_switch 5
	toggle_sfx
	note_type 2, 11, 8
	rest 9
	rest 16
	sound_ret

gbs_sfx_4noteditty_Ch7:
	gbs_switch 6
	toggle_sfx
	note_type 2, 11, 8
	rest 9
	rest 16
	sound_ret

	.align 4
	.global gbs_sfx_4noteditty_Header
gbs_sfx_4noteditty_Header:
	.byte 3	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_4noteditty_Ch5
	.int gbs_sfx_4noteditty_Ch6
	.int gbs_sfx_4noteditty_Ch7
