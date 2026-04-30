	.include "asm/macros.inc"

	.section .rodata
	.align 1

@ Sfx_QuitSlots — 4 channels (Pulse1, Pulse2, Wave, Noise)

gbs_sfx_quitslots_Ch5:
	gbs_switch 4
	toggle_sfx
	tempo 144
	volume 7, 7
	duty_cycle 2
	note_type 8, 8, 2
	octave 3
	note Gs, 2
	rest 4
	note Cs, 2
	note F_, 2
	note Gs, 2
	note F_, 2
	note Gs, 2
	octave 4
	note D_, 2
	note F_, 2
	note D_, 2
	octave 3
	note B_, 2
	note As, 2
	note Fs, 2
	note As, 2
	note Gs, 2
	note Fs, 2
	volume_envelope 9, 7
	note Gs, 14
	rest 6
	sound_ret

gbs_sfx_quitslots_Ch6:
	gbs_switch 5
	toggle_sfx
	duty_cycle 2
	note_type 8, 11, 3
	rest 3
	octave 4
	note B_, 1
	octave 5
	note C_, 2
	octave 4
	note Gs, 4
	note As, 2
	volume_envelope 12, 1
	note B_, 4
	note As, 2
	note Gs, 4
	note F_, 2
	note Fs, 4
	note F_, 2
	note Ds, 4
	volume_envelope 11, 7
	note F_, 14
	rest 6
	sound_ret

gbs_sfx_quitslots_Ch7:
	gbs_switch 6
	toggle_sfx
	note_type 8, 2, 5
	octave 3
	note Cs, 2
	rest 2
	note F_, 2
	note Ds, 2
	note Cs, 2
	note Gs, 2
	note D_, 2
	rest 2
	note D_, 2
	octave 2
	note Gs, 2
	note B_, 2
	octave 3
	note D_, 2
	note Ds, 2
	rest 2
	octave 2
	note As, 2
	octave 3
	note C_, 2
	rest 2
	note Cs, 14
	rest 6
	sound_ret

gbs_sfx_quitslots_Ch8:
	gbs_switch 7
	toggle_sfx
	sfx_toggle_noise 3
	drum_speed 8
	note Ds, 6
	note D_, 4
	note Ds, 2
	note Ds, 4
	note Ds, 2
	note D_, 4
	note Ds, 2
	note D_, 4
	note Ds, 2
	note D_, 4
	note B_, 14
	rest 6
	sound_ret

	.align 4
	.global gbs_sfx_quitslots_Header
gbs_sfx_quitslots_Header:
	.byte 4	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_quitslots_Ch5
	.int gbs_sfx_quitslots_Ch6
	.int gbs_sfx_quitslots_Ch7
	.int gbs_sfx_quitslots_Ch8
