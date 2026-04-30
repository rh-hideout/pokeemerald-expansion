	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_looklass_Ch1:
	gbs_switch 0
	tempo 132
	volume 7, 7
	pitch_offset 1
	duty_cycle 2
	note_type 12, 12, 7
	octave 3
	note B_, 1
	rest 1
	octave 4
	note B_, 14
	stereo_panning FALSE, TRUE
	duty_cycle 0
gbs_looklass_Ch1.mainloop:
	volume_envelope 10, 2
	octave 3
	note E_, 4
	volume_envelope 10, 1
	note E_, 4
	note E_, 4
	note E_, 2
	volume_envelope 10, 3
	note B_, 2
	sound_loop 0, gbs_looklass_Ch1.mainloop

gbs_looklass_Ch2:
	gbs_switch 1
	stereo_panning TRUE, FALSE
	duty_cycle 0
	note_type 12, 8, 3
	rest 16
gbs_looklass_Ch2.mainloop:
	volume_envelope 9, 2
	octave 2
	note B_, 4
	volume_envelope 9, 1
	note B_, 4
	note B_, 4
	note B_, 2
	volume_envelope 9, 3
	octave 3
	note Gs, 2
	sound_loop 0, gbs_looklass_Ch2.mainloop

gbs_looklass_Ch3:
	gbs_switch 2
	note_type 12, 1, 0
	rest 8
	octave 6
	note E_, 2
	note Ds, 2
	note Cs, 2
	note C_, 2
gbs_looklass_Ch3.mainloop:
	octave 5
	note B_, 2
	rest 2
	octave 6
	note Ds, 2
	rest 2
	note E_, 2
	rest 2
	note Ds, 2
	rest 2
	note Cs, 2
	note C_, 2
	octave 5
	note B_, 2
	note A_, 2
	note Gs, 2
	note A_, 2
	note As, 2
	octave 6
	note Cs, 2
	octave 5
	note B_, 2
	rest 2
	octave 6
	note Cs, 2
	rest 2
	octave 5
	note B_, 2
	rest 2
	note A_, 2
	rest 2
	note Gs, 2
	note Fs, 2
	note E_, 2
	note Ds, 2
	note E_, 2
	note Fs, 2
	note Gs, 2
	note A_, 2
	sound_loop 0, gbs_looklass_Ch3.mainloop

gbs_looklass_Ch4:
	gbs_switch 3
	toggle_noise 4
	drum_speed 12
	drum_note 1, 16
gbs_looklass_Ch4.mainloop:
	drum_speed 6
	drum_note 3, 8
	drum_note 2, 8
	drum_note 2, 8
	drum_note 2, 4
	drum_note 3, 1
	drum_note 2, 1
	drum_note 2, 1
	drum_note 2, 1
	sound_loop 0, gbs_looklass_Ch4.mainloop

	.align 4
	.global gbs_looklass_Header
gbs_looklass_Header:
	.byte 4	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_looklass_Ch1
	.int gbs_looklass_Ch2
	.int gbs_looklass_Ch3
	.int gbs_looklass_Ch4
