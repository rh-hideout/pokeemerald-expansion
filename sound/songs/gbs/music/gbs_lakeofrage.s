	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_lakeofrage_Ch1:
	gbs_switch 0
	tempo 144
	volume 7, 7
	duty_cycle 3
	pitch_offset 2
	vibrato 8, 2, 2
	stereo_panning TRUE, FALSE
	note_type 12, 11, 4
	octave 3
	note D_, 6
	note D_, 10
	note D_, 6
	note D_, 6
	note E_, 4
gbs_lakeofrage_Ch1.mainloop:
	volume_envelope 11, 5
	note Fs, 6
	note E_, 6
	note D_, 4
	octave 4
	note D_, 6
	note C_, 4
	note E_, 2
	note D_, 4
	octave 3
	note B_, 6
	note G_, 2
	note_type 8, 11, 5
	note D_, 4
	note G_, 4
	note B_, 4
	note_type 12, 11, 4
	note D_, 3
	note Fs, 1
	volume_envelope 11, 7
	note A_, 8
	note Fs, 4
	note A_, 3
	octave 4
	note Cs, 1
	note D_, 12
	note_type 8, 11, 4
	octave 3
	note C_, 4
	octave 2
	note B_, 4
	note A_, 4
	note_type 8, 11, 7
	note A_, 12
	note_type 12, 11, 7
	octave 3
	note C_, 12
	volume_envelope 11, 4
	note E_, 4
	note D_, 2
	volume_envelope 11, 7
	octave 2
	note A_, 10
	volume_envelope 11, 4
	octave 3
	note E_, 4
	note D_, 3
	note E_, 1
	volume_envelope 11, 7
	note Fs, 8
	note D_, 6
	note C_, 1
	note E_, 1
	note C_, 8
	note E_, 6
	note E_, 1
	note G_, 1
	note E_, 8
	note G_, 6
	note Fs, 1
	note G_, 1
	volume_envelope 10, 0
	note A_, 7
	volume_envelope 10, 7
	note A_, 7
	note A_, 1
	octave 4
	note C_, 1
	volume_envelope 10, 0
	note D_, 6
	volume_envelope 10, 7
	note D_, 6
	sound_loop 0, gbs_lakeofrage_Ch1.mainloop

gbs_lakeofrage_Ch2:
	gbs_switch 1
	duty_cycle 3
	vibrato 32, 4, 4
	stereo_panning TRUE, TRUE
	note_type 12, 9, 0
	octave 3
	note G_, 8
	volume_envelope 9, 7
	note G_, 8
	volume_envelope 10, 0
	note A_, 8
	volume_envelope 10, 7
	note A_, 8
gbs_lakeofrage_Ch2.mainloop:
	note_type 8, 12, 7
	octave 4
	note D_, 16
	octave 3
	note A_, 4
	octave 4
	note D_, 4
	note A_, 16
	octave 5
	note C_, 4
	octave 4
	note B_, 4
	note_type 12, 12, 7
	note G_, 12
	note B_, 4
	note A_, 3
	note G_, 1
	volume_envelope 11, 0
	note Fs, 12
	volume_envelope 11, 7
	note Fs, 16
	note_type 8, 12, 3
	octave 3
	note G_, 4
	note Fs, 4
	note E_, 4
	note C_, 15
	note_type 12, 12, 3
	octave 4
	note C_, 1
	note E_, 1
	note G_, 1
	rest 1
	note E_, 1
	note G_, 1
	volume_envelope 12, 5
	octave 5
	note C_, 10
	volume_envelope 12, 3
	octave 4
	note A_, 4
	note G_, 4
	note Fs, 4
	note E_, 2
	note_type 8, 12, 3
	note D_, 4
	note E_, 4
	note Fs, 4
	note_type 8, 12, 7
	note A_, 12
	note_type 8, 12, 3
	octave 3
	note G_, 4
	note Fs, 4
	note E_, 4
	octave 4
	note C_, 4
	octave 3
	note B_, 4
	note A_, 4
	octave 4
	note E_, 4
	note D_, 4
	note C_, 4
	note G_, 4
	note Fs, 4
	note E_, 4
	note_type 8, 12, 7
	note Fs, 16
	note D_, 4
	note Fs, 4
	note_type 12, 12, 7
	note A_, 16
	sound_loop 0, gbs_lakeofrage_Ch2.mainloop

gbs_lakeofrage_Ch3:
	gbs_switch 2
	stereo_panning FALSE, TRUE
	note_type 12, 1, 6
	octave 3
	note G_, 4
	rest 2
	note G_, 4
	rest 6
	note Fs, 4
	rest 2
	note Fs, 4
	rest 2
	note E_, 4
gbs_lakeofrage_Ch3.mainloop:
	octave 3
	note D_, 4
	octave 2
	note A_, 2
	octave 3
	note D_, 4
	octave 2
	note A_, 2
	octave 3
	note D_, 2
	note E_, 2
	note F_, 4
	note C_, 2
	note F_, 4
	note C_, 2
	note F_, 2
	note Fs, 2
	note G_, 4
	note D_, 2
	note G_, 4
	note D_, 2
	note G_, 2
	note B_, 2
	note A_, 2
	note D_, 2
	note Fs, 2
	note A_, 4
	note D_, 2
	note E_, 2
	note Fs, 2
	note A_, 2
	note Fs, 2
	note A_, 2
	octave 4
	note D_, 4
	octave 3
	note A_, 2
	octave 4
	note D_, 2
	note Fs, 2
	octave 3
	note E_, 4
	note C_, 2
	note E_, 4
	note C_, 2
	note E_, 2
	note C_, 2
	note G_, 4
	note C_, 2
	note G_, 4
	note C_, 2
	note G_, 2
	note C_, 2
	note Fs, 4
	note D_, 2
	note Fs, 4
	note D_, 2
	note Fs, 2
	note D_, 2
	note A_, 2
	note D_, 2
	note Fs, 2
	octave 4
	note D_, 4
	octave 3
	note D_, 2
	note E_, 2
	note Fs, 2
	note G_, 4
	note C_, 2
	note G_, 4
	note C_, 2
	note G_, 2
	note C_, 2
	note G_, 4
	note C_, 2
	note G_, 4
	note C_, 2
	note G_, 2
	note C_, 2
	note Fs, 4
	note D_, 2
	note Fs, 4
	note D_, 2
	note Fs, 2
	note D_, 2
	note D_, 4
	octave 2
	note A_, 2
	octave 3
	note D_, 4
	octave 2
	note A_, 2
	octave 3
	note D_, 2
	octave 2
	note A_, 2
	sound_loop 0, gbs_lakeofrage_Ch3.mainloop

gbs_lakeofrage_Ch4:
	gbs_switch 3
	stereo_panning TRUE, FALSE
	toggle_noise 3
	drum_speed 12
gbs_lakeofrage_Ch4.mainloop:
	drum_note 3, 2
	drum_note 3, 1
	drum_note 3, 1
	drum_note 8, 2
	drum_note 3, 2
	drum_note 3, 1
	drum_note 3, 1
	drum_note 7, 6
	drum_note 3, 2
	drum_note 3, 1
	drum_note 3, 1
	drum_note 8, 2
	drum_note 3, 2
	drum_note 3, 1
	drum_note 3, 1
	drum_note 7, 3
	drum_note 3, 1
	drum_note 3, 1
	drum_note 3, 1
	sound_loop 0, gbs_lakeofrage_Ch4.mainloop

	.align 4
	.global gbs_lakeofrage_Header
gbs_lakeofrage_Header:
	.byte 4	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_lakeofrage_Ch1
	.int gbs_lakeofrage_Ch2
	.int gbs_lakeofrage_Ch3
	.int gbs_lakeofrage_Ch4
