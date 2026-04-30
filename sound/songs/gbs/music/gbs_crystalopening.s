	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_crystalopening_Ch1:
	gbs_switch 0
	tempo 136
	volume 7, 7
	pitch_offset 2
	vibrato 16, 3, 4
	duty_cycle 3
	stereo_panning TRUE, FALSE
	note_type 12, 9, 2
	octave 2
	note Fs, 2
	note Fs, 4
	note Fs, 2
	note Fs, 2
	note Fs, 4
	note Fs, 2
	note Fs, 2
	note Fs, 4
	note Fs, 2
	note Fs, 2
	note Fs, 6
	note_type 12, 11, 4
	octave 2
	note B_, 2
	note Fs, 2
	note E_, 2
	note B_, 2
	octave 3
	note Cs, 2
	octave 2
	note Gs, 2
	note Fs, 2
	octave 3
	note Cs, 2
	octave 2
	note Fs, 2
	note Cs, 2
	octave 1
	note B_, 2
	octave 2
	note Fs, 2
	octave 3
	note Fs, 2
	octave 2
	note Fs, 2
	note B_, 2
	octave 3
	note E_, 2
	note Fs, 2
	note E_, 2
	octave 2
	note B_, 2
	note Fs, 2
	note B_, 2
	octave 3
	note E_, 2
	note Fs, 2
	note E_, 2
	octave 2
	note B_, 2
	note Fs, 2
	note B_, 2
	octave 3
	note E_, 2
	octave 2
	note D_, 8
	octave 3
	note D_, 2
	octave 2
	note A_, 2
	note G_, 2
	octave 3
	note D_, 2
	note E_, 2
	octave 2
	note B_, 2
	note A_, 2
	octave 3
	note E_, 2
	octave 2
	note A_, 2
	note E_, 2
	note D_, 2
	note A_, 2
	octave 3
	note A_, 2
	octave 2
	note A_, 2
	octave 3
	note D_, 2
	note E_, 2
	note A_, 2
	note E_, 2
	note D_, 2
	octave 2
	note A_, 2
	octave 3
	note D_, 2
	note E_, 2
	note A_, 2
	note E_, 2
	octave 4
	note C_, 2
	octave 3
	note G_, 2
	note Fs, 2
	octave 4
	note C_, 2
	note_type 12, 10, 0
	note D_, 8
	note D_, 8
	note_type 12, 10, 7
	note D_, 8
	note_type 12, 11, 2
	octave 2
	note D_, 16
	sound_ret

gbs_crystalopening_Ch2:
	gbs_switch 1
	note_type 12, 10, 2
	duty_cycle 3
	vibrato 8, 4, 4
	octave 2
	note B_, 2
	note B_, 4
	note B_, 2
	note B_, 2
	note B_, 4
	note B_, 2
	note B_, 2
	note B_, 4
	note B_, 2
	note B_, 2
	note B_, 2
	note_type 12, 10, 2
	octave 2
	note E_, 1
	note B_, 1
	octave 3
	note E_, 1
	note Fs, 1
	note_type 12, 12, 7
	note E_, 8
	note Fs, 8
	octave 2
	note B_, 8
	note_type 12, 11, 0
	octave 3
	note B_, 8
	note_type 12, 12, 7
	note B_, 16
	rest 16
	note G_, 8
	note A_, 8
	note D_, 8
	note_type 12, 12, 7
	octave 4
	note D_, 8
	note_type 12, 7, -4
	note D_, 8
	note_type 12, 12, 7
	note D_, 8
	note G_, 8
	note_type 12, 11, 0
	note Fs, 8
	note Fs, 8
	note_type 12, 12, 7
	note Fs, 8
	note_type 12, 12, 2
	octave 3
	note D_, 16
	sound_ret

gbs_crystalopening_Ch3:
	gbs_switch 2
	note_type 12, 1, 6
	octave 1
	note B_, 4
	note_type 6, 1, 6
	note B_, 1
	note As, 1
	note A_, 1
	note Gs, 1
	note G_, 1
	note Fs, 1
	note F_, 1
	note E_, 1
	note_type 12, 1, 6
	note B_, 4
	note B_, 4
	note B_, 4
	note_type 6, 1, 6
	note B_, 1
	note As, 1
	note A_, 1
	note Gs, 1
	note G_, 1
	note Fs, 1
	note F_, 1
	note E_, 1
	note_type 12, 1, 6
	note B_, 4
	note B_, 4
	octave 2
	note B_, 8
	note Fs, 8
	note Ds, 8
	note B_, 4
	note Fs, 4
	note B_, 4
	octave 3
	note E_, 4
	note Fs, 4
	note E_, 4
	note D_, 4
	note Cs, 4
	octave 2
	note A_, 8
	octave 3
	note D_, 8
	octave 2
	note A_, 8
	note Fs, 8
	octave 3
	note D_, 4
	note E_, 4
	note Fs, 4
	note E_, 4
	note D_, 4
	note Cs, 4
	note C_, 8
	note D_, 8
	note D_, 16
	octave 2
	note D_, 1
	rest 15
	sound_ret

gbs_crystalopening_Ch4:
	gbs_switch 3
	stereo_panning FALSE, TRUE
	toggle_noise 3
	drum_speed 12
	rest 16
	rest 12
	octave 2
	drum_note 2, 1
	drum_note 2, 1
	drum_note 2, 1
	drum_note 2, 1
	drum_note 3, 4
	drum_speed 8
	drum_note 2, 1
	drum_note 2, 1
	drum_note 2, 1
	drum_note 2, 1
	drum_note 2, 1
	drum_note 2, 1
	drum_note 3, 6
	drum_note 2, 1
	drum_note 2, 1
	drum_note 2, 1
	drum_note 2, 1
	drum_note 2, 1
	drum_note 2, 1
	drum_note 3, 3
	drum_speed 12
	drum_note 2, 1
	drum_note 2, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 2, 1
	drum_note 2, 1
	drum_note 2, 2
	drum_note 2, 1
	drum_note 2, 1
	drum_note 8, 2
	drum_note 3, 1
	drum_note 2, 1
	drum_note 10, 1
	drum_note 8, 1
	drum_note 3, 1
	drum_note 3, 1
	drum_note 8, 1
	rest 1
	drum_note 2, 1
	drum_note 2, 1
	drum_note 10, 1
	drum_note 8, 1
	drum_note 2, 1
	drum_note 3, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 3, 1
	drum_note 3, 1
	drum_note 10, 2
	drum_note 2, 2
	drum_note 2, 2
	drum_note 2, 2
	drum_note 10, 2
	drum_note 3, 2
	drum_note 2, 1
	drum_note 2, 1
	drum_note 2, 1
	drum_note 2, 1
	drum_note 3, 4
	drum_note 2, 1
	drum_note 2, 1
	drum_note 2, 1
	drum_note 2, 1
	drum_note 3, 4
	drum_note 2, 1
	drum_note 2, 1
	drum_note 2, 1
	drum_note 2, 1
	drum_note 10, 1
	drum_note 8, 1
	drum_note 3, 1
	drum_note 2, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 2, 1
	drum_note 2, 1
	drum_note 10, 1
	drum_note 8, 1
	drum_note 3, 1
	drum_note 2, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 3, 1
	drum_note 2, 1
	drum_note 10, 1
	drum_note 8, 1
	drum_note 2, 1
	drum_note 2, 1
	drum_note 3, 1
	drum_note 2, 1
	drum_note 2, 1
	drum_note 3, 1
	drum_note 10, 1
	drum_note 8, 1
	drum_note 3, 1
	drum_note 2, 1
	drum_note 2, 1
	drum_note 8, 1
	drum_note 3, 1
	drum_note 2, 1
	drum_note 2, 2
	drum_note 3, 2
	rest 2
	drum_note 3, 2
	drum_note 3, 2
	rest 6
	rest 16
	rest 16
	sound_ret

	.align 4
	.global gbs_crystalopening_Header
gbs_crystalopening_Header:
	.byte 4	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_crystalopening_Ch1
	.int gbs_crystalopening_Ch2
	.int gbs_crystalopening_Ch3
	.int gbs_crystalopening_Ch4
