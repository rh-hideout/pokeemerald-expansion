	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_titlescreen_Ch1:
	gbs_switch 0
	tempo 134
	volume 7, 7
	duty_cycle 3
	pitch_offset 2
	vibrato 16, 1, 2
	stereo_panning TRUE, FALSE
	note_type 12, 10, 7
	volume_envelope 10, 0
	octave 3
	rest 4
	volume_envelope 10, 7
	octave 2
	note G_, 1
	rest 2
	note A_, 1
	note B_, 8
	note G_, 4
	octave 3
	note C_, 1
	rest 2
	note D_, 1
	note E_, 8
	note C_, 4
	octave 2
	note B_, 1
	rest 2
	octave 3
	note C_, 1
	octave 2
	note B_, 8
	note A_, 4
	note A_, 1
	rest 2
	note B_, 1
	octave 3
	note C_, 6
	note E_, 4
	note Fs, 2
	stereo_panning TRUE, TRUE
	octave 4
	note G_, 1
	stereo_panning TRUE, FALSE
	octave 3
	note D_, 5
	octave 2
	note B_, 2
	octave 3
	note D_, 4
	octave 2
	note B_, 4
	octave 3
	note C_, 6
	note F_, 6
	note C_, 4
	note D_, 6
	volume_envelope 11, 7
	note Ds, 1
	note E_, 1
	note F_, 6
	note E_, 1
	note Ds, 1
	note D_, 8
	note_type 8, 10, 7
	note C_, 4
	octave 2
	note B_, 4
	octave 3
	note C_, 4
	note D_, 9
	octave 2
	note B_, 3
	octave 3
	note D_, 6
	octave 2
	note B_, 6
	octave 3
	note C_, 3
	note D_, 6
	note E_, 3
	note E_, 4
	note E_, 4
	note C_, 4
	note_type 8, 10, 0
	octave 2
	note B_, 6
	note_type 8, 10, 7
	note B_, 6
	note_type 8, 10, 7
	octave 3
	note F_, 4
	note E_, 4
	note C_, 4
	note_type 8, 10, 0
	note D_, 6
	note_type 8, 10, 7
	note D_, 6
	note_type 8, 10, 7
	rest 3
	octave 2
	note B_, 3
	octave 3
	note C_, 3
	note D_, 3
	note D_, 9
	octave 2
	note B_, 3
	octave 3
	note D_, 6
	octave 2
	note B_, 6
	octave 3
	note C_, 9
	note F_, 9
	note C_, 6
	note D_, 9
	note_type 12, 11, 7
	note Ds, 1
	note E_, 1
	note F_, 6
	note E_, 1
	note Ds, 1
	note D_, 8
	note_type 8, 10, 7
	note C_, 4
	octave 2
	note B_, 4
	octave 3
	note C_, 4
	note D_, 9
	octave 2
	note B_, 3
	octave 3
	note D_, 9
	note_type 8, 11, 7
	note G_, 3
	note A_, 4
	note G_, 4
	note F_, 4
	note F_, 6
	note E_, 6
	note D_, 9
	note F_, 3
	note G_, 3
	note D_, 6
	note G_, 3
	note_type 8, 5, 4
	octave 2
	note G_, 3
	note B_, 3
	note_type 8, 9, 4
	octave 3
	note D_, 3
	note G_, 3
	tempo 136
	note_type 8, 11, 4
	note F_, 3
	note A_, 3
	note_type 8, 13, 4
	octave 4
	note C_, 3
	note F_, 3
	tempo 138
	note_type 8, 11, 4
	note D_, 9
	note C_, 9
	octave 3
	note As, 6
	note_type 12, 11, 7
	note F_, 1
	note E_, 1
	note D_, 1
	note E_, 1
	note F_, 4
	octave 4
	note D_, 4
	note F_, 4
	note E_, 6
	octave 3
	note G_, 2
	note_type 8, 11, 7
	note A_, 4
	note G_, 4
	note F_, 4
	note G_, 12
	octave 4
	note C_, 6
	tempo 136
	note Cs, 6
	tempo 134
	sound_call gbs_titlescreen_Ch1.sub1
	octave 4
	note C_, 4
	note C_, 4
	note Cs, 4
	sound_call gbs_titlescreen_Ch1.sub1
	octave 4
	note C_, 4
	note C_, 4
	note Cs, 4
	sound_call gbs_titlescreen_Ch1.sub1
	octave 3
	note E_, 4
	note E_, 4
	note C_, 4
	note_type 12, 10, 0
	note D_, 6
	note_type 12, 10, 7
	note D_, 10
	volume_envelope 10, 0
	note C_, 8
	volume_envelope 10, 7
	note C_, 8
	volume_envelope 10, 0
	octave 2
	note B_, 8
	volume_envelope 10, 7
	note B_, 8
	octave 3
	note C_, 8
	octave 2
	note B_, 8
	octave 3
	note D_, 8
	octave 2
	note B_, 8
	octave 3
	note C_, 8
	note F_, 8
	note A_, 8
	note G_, 6
	note G_, 1
	note Fs, 1
	note F_, 8
	note E_, 8
	volume_envelope 10, 0
	note D_, 16
	volume_envelope 10, 7
	note D_, 16
	volume_envelope 10, 3
	octave 2
	note G_, 1
	rest 3
	note G_, 1
	rest 5
	note G_, 1
	note G_, 1
	note G_, 1
	rest 3
	note G_, 1
	rest 3
	note G_, 1
	rest 3
	note_type 8, 11, 2
	note A_, 2
	note A_, 2
	note A_, 2
	note A_, 2
	note A_, 2
	note Fs, 2
	note_type 12, 11, 7
	note G_, 1
	rest 3
	octave 1
	note G_, 1
	rest 11
	sound_ret

gbs_titlescreen_Ch1.sub1:
	note_type 12, 12, 3
	note D_, 1
gbs_titlescreen_Ch1.sub1loop1:
	rest 1
	octave 2
	note D_, 1
	octave 1
	note A_, 1
	octave 2
	note D_, 1
	sound_loop 5, gbs_titlescreen_Ch1.sub1loop1
	rest 1
	note D_, 1
	octave 1
	note A_, 1
	note_type 8, 11, 7
	sound_ret

gbs_titlescreen_Ch2:
	gbs_switch 1
	duty_cycle 3
	vibrato 20, 1, 2
	note_type 12, 12, 7
	volume_envelope 10, 4
	octave 1
	note G_, 1
	octave 2
	note D_, 1
	note G_, 1
	octave 3
	note C_, 1
	volume_envelope 12, 2
	octave 3
	note B_, 1
	rest 2
	note A_, 1
	volume_envelope 11, 0
	note G_, 6
	volume_envelope 11, 7
	note G_, 6
	rest 16
	rest 16
	volume_envelope 12, 7
	octave 4
	note C_, 1
	rest 2
	note D_, 1
	note E_, 8
	note Fs, 2
	note E_, 1
	note Fs, 1
	octave 3
	note G_, 6
	note B_, 2
	octave 4
	note D_, 8
	stereo_panning TRUE, FALSE
	volume_envelope 9, 7
	octave 2
	note A_, 4
	note F_, 4
	stereo_panning TRUE, TRUE
	volume_envelope 12, 7
	octave 4
	note F_, 6
	note E_, 1
	note Ds, 1
	note D_, 8
	stereo_panning TRUE, FALSE
	volume_envelope 9, 7
	octave 2
	note A_, 6
	octave 3
	note C_, 2
	stereo_panning FALSE, TRUE
	volume_envelope 10, 3
	octave 4
	note D_, 4
	note D_, 2
	note C_, 4
	note C_, 2
	octave 3
	note B_, 4
	stereo_panning TRUE, TRUE
	volume_envelope 12, 7
	octave 3
	note G_, 6
	note B_, 2
	octave 4
	note D_, 8
	stereo_panning TRUE, FALSE
	volume_envelope 9, 7
	octave 2
	note A_, 2
	note F_, 4
	note A_, 2
	stereo_panning TRUE, TRUE
	note_type 8, 12, 7
	octave 4
	note C_, 4
	octave 3
	note B_, 4
	octave 4
	note C_, 4
	note D_, 12
	stereo_panning TRUE, FALSE
	note_type 8, 11, 7
	octave 2
	note A_, 9
	stereo_panning FALSE, TRUE
	note_type 12, 12, 7
	note G_, 1
	note A_, 1
	note B_, 6
	note E_, 1
	note Fs, 1
	note G_, 4
	note_type 12, 4, -3
	note A_, 4
	stereo_panning TRUE, TRUE
	note_type 12, 12, 7
	octave 3
	note G_, 6
	note B_, 2
	octave 4
	note D_, 8
	stereo_panning TRUE, FALSE
	volume_envelope 9, 7
	octave 2
	note A_, 2
	note F_, 6
	stereo_panning TRUE, TRUE
	volume_envelope 12, 7
	octave 4
	note F_, 6
	note E_, 1
	note Ds, 1
	note D_, 8
	stereo_panning TRUE, FALSE
	volume_envelope 9, 7
	octave 3
	note C_, 2
	octave 2
	note A_, 6
	note B_, 6
	note G_, 2
	note_type 8, 12, 7
	note F_, 4
	note G_, 4
	note F_, 4
	stereo_panning TRUE, TRUE
	octave 3
	note G_, 9
	note B_, 3
	octave 4
	note D_, 12
	stereo_panning TRUE, FALSE
	note_type 8, 10, 7
	octave 3
	note D_, 4
	note C_, 4
	note D_, 4
	stereo_panning TRUE, TRUE
	note_type 8, 12, 7
	octave 4
	note F_, 4
	note E_, 4
	note F_, 4
	note G_, 9
	note As, 3
	note_type 12, 11, 0
	note G_, 8
	note_type 12, 11, 7
	note G_, 8
	volume_envelope 12, 6
	note A_, 4
	volume_envelope 5, -5
	note A_, 4
	volume_envelope 12, 7
	note As, 6
	volume_envelope 12, 3
	note F_, 2
	volume_envelope 12, 7
	note F_, 8
	volume_envelope 10, 7
	octave 3
	note As, 8
	volume_envelope 12, 7
	octave 4
	note As, 4
	note B_, 4
	octave 5
	note C_, 6
	volume_envelope 12, 3
	octave 4
	note G_, 2
	volume_envelope 12, 7
	note G_, 8
	volume_envelope 10, 7
	octave 3
	note E_, 8
	volume_envelope 12, 7
	octave 5
	note C_, 4
	note Cs, 4
	pitch_offset 1
	stereo_panning FALSE, TRUE
	sound_call gbs_titlescreen_Ch2.sub1
	note Cs, 4
	sound_call gbs_titlescreen_Ch2.sub1
	note Cs, 4
	sound_call gbs_titlescreen_Ch2.sub1
	octave 4
	note A_, 4
	stereo_panning TRUE, TRUE
	pitch_offset 0
	note_type 12, 11, 0
	octave 3
	note B_, 6
	note_type 12, 11, 7
	note B_, 10
	volume_envelope 12, 7
	note A_, 8
	note F_, 6
	note E_, 1
	note Ds, 1
	note D_, 8
	note G_, 8
	note F_, 8
	note A_, 8
	volume_envelope 11, 0
	note G_, 8
	volume_envelope 11, 7
	note G_, 8
	volume_envelope 12, 7
	note F_, 8
	octave 4
	note F_, 6
	note E_, 1
	note Ds, 1
	note D_, 8
	octave 2
	note B_, 8
	octave 3
	note C_, 8
	note A_, 6
	note F_, 1
	note A_, 1
	volume_envelope 11, 0
	note G_, 16
	volume_envelope 11, 7
	note G_, 16
	volume_envelope 12, 2
	octave 4
	note G_, 1
	rest 3
	note G_, 1
	rest 5
	note G_, 1
	note G_, 1
	note G_, 1
	rest 3
	note G_, 1
	rest 3
	volume_envelope 9, 0
	note G_, 4
	note_type 8, 12, 2
	octave 3
	note F_, 2
	note F_, 2
	note F_, 2
	note F_, 2
	note F_, 2
	note Fs, 2
	note_type 12, 12, 7
	note G_, 1
	rest 3
	octave 2
	note G_, 1
	rest 11
	sound_ret

gbs_titlescreen_Ch2.sub1:
	note_type 12, 11, 2
	note D_, 1
gbs_titlescreen_Ch2.sub1loop1:
	octave 3
	note A_, 1
	octave 4
	note D_, 1
	note A_, 1
	note D_, 1
	sound_loop 5, gbs_titlescreen_Ch2.sub1loop1
	octave 3
	note A_, 1
	octave 4
	note D_, 1
	note A_, 1
	note_type 8, 11, 7
	octave 5
	note C_, 4
	note C_, 4
	sound_ret

gbs_titlescreen_Ch3:
	gbs_switch 2
	stereo_panning FALSE, TRUE
	vibrato 16, 1, 4
	pitch_offset 1
	note_type 12, 1, 6
	octave 3
	octave 3
	rest 4
	octave 2
	note G_, 2
	note D_, 1
	note Cs, 1
	note D_, 1
	rest 1
	note G_, 2
	note D_, 1
	rest 1
	note D_, 2
	note G_, 2
	note D_, 2
	note F_, 2
	note C_, 1
	octave 1
	note B_, 1
	octave 2
	note C_, 1
	rest 1
	note F_, 2
	note C_, 1
	rest 1
	note C_, 2
	note F_, 2
	note C_, 2
	note G_, 2
	note D_, 1
	note Cs, 1
	note D_, 1
	rest 1
	note G_, 2
	note D_, 1
	rest 1
	note D_, 2
	note G_, 2
	note D_, 2
	note A_, 2
	note F_, 1
	note E_, 1
	note F_, 1
	rest 1
	note A_, 2
	note F_, 2
	note A_, 4
	octave 3
	note C_, 2
	octave 2
	note G_, 4
	note D_, 2
	note G_, 4
	note D_, 2
	note G_, 2
	note D_, 2
	note A_, 4
	note F_, 2
	note A_, 4
	note F_, 2
	note A_, 2
	octave 3
	note C_, 2
	octave 2
	note B_, 4
	note G_, 2
	note B_, 4
	note G_, 2
	note B_, 2
	note G_, 2
	note G_, 4
	note B_, 2
	note A_, 4
	note B_, 2
	octave 3
	note C_, 4
	octave 2
	note G_, 4
	note D_, 2
	note G_, 4
	note D_, 2
	note G_, 2
	note D_, 2
	note A_, 4
	note F_, 2
	note A_, 4
	note F_, 2
	note A_, 2
	octave 3
	note C_, 2
	octave 2
	note B_, 4
	note G_, 2
	note B_, 4
	note G_, 2
	note B_, 2
	octave 3
	note C_, 2
	octave 2
	note B_, 4
	note G_, 2
	note B_, 4
	note G_, 2
	octave 3
	note D_, 4
	octave 2
	note G_, 4
	note D_, 2
	note G_, 4
	note D_, 2
	note G_, 2
	note D_, 2
	note A_, 4
	note F_, 2
	note A_, 4
	note F_, 2
	note A_, 2
	octave 3
	note C_, 2
	octave 2
	note B_, 4
	note G_, 2
	note B_, 4
	note G_, 2
	note B_, 2
	note G_, 2
	octave 3
	note D_, 4
	octave 2
	note G_, 2
	octave 3
	note D_, 4
	octave 2
	note G_, 2
	octave 3
	note D_, 2
	octave 2
	note A_, 2
	note G_, 4
	note D_, 2
	note G_, 4
	note D_, 2
	note G_, 2
	note D_, 2
	note A_, 4
	note F_, 2
	note A_, 4
	note F_, 2
	note A_, 2
	octave 3
	note C_, 2
	octave 2
	note B_, 4
	note G_, 2
	note B_, 4
	note G_, 2
	octave 3
	note D_, 2
	octave 2
	note G_, 2
	note G_, 2
	note D_, 2
	note G_, 2
	note A_, 2
	note A_, 2
	note F_, 2
	note A_, 2
	octave 3
	note C_, 2
	note D_, 6
	octave 2
	note As, 6
	octave 3
	note F_, 4
	note As, 6
	note F_, 6
	note D_, 4
	note E_, 6
	note C_, 6
	note E_, 4
	octave 4
	note C_, 6
	octave 3
	note G_, 6
	note E_, 4
	note D_, 1
	rest 1
	stereo_panning TRUE, TRUE
	note_type 12, 1, 6
	pitch_offset 0
	octave 4
	note A_, 2
	octave 5
	note D_, 2
	note A_, 6
	note G_, 2
	note Fs, 2
	note D_, 1
	rest 2
	note E_, 1
	note Fs, 4
	note_type 8, 1, 6
	octave 3
	note C_, 4
	note C_, 4
	note Cs, 4
	note_type 12, 1, 6
	note D_, 1
	rest 1
	octave 4
	note A_, 2
	octave 5
	note D_, 2
	note A_, 6
	note G_, 2
	note Fs, 2
	note B_, 1
	rest 2
	note A_, 1
	note A_, 4
	note_type 8, 1, 6
	octave 3
	note C_, 4
	note C_, 4
	note Cs, 4
	note_type 12, 1, 6
	note D_, 1
	rest 1
	note_type 12, 1, 6
	octave 4
	note A_, 2
	octave 5
	note D_, 2
	note G_, 6
	note E_, 2
	note G_, 2
	note Fs, 1
	note E_, 1
	note D_, 6
	pitch_offset 1
	note_type 8, 1, 6
	octave 3
	note C_, 4
	note C_, 4
	note E_, 2
	note Fs, 2
	stereo_panning FALSE, TRUE
	note_type 12, 1, 6
	note G_, 16
	note F_, 16
	note G_, 8
	note D_, 6
	note D_, 1
	note E_, 1
	note F_, 2
	note F_, 12
	note E_, 1
	note Ds, 1
	note D_, 8
	note G_, 8
	note F_, 8
	note A_, 8
	note G_, 8
	note D_, 6
	note D_, 1
	note E_, 1
	note F_, 16
	note G_, 1
	rest 3
	note G_, 1
	rest 5
	note G_, 1
	note G_, 1
	note G_, 1
	rest 3
	note G_, 1
	rest 3
	note G_, 1
	rest 5
	note G_, 1
	note G_, 1
	note G_, 1
	rest 3
	octave 2
	note G_, 1
	rest 3
	note G_, 1
	rest 5
	note G_, 1
	note G_, 1
	note G_, 1
	rest 3
	note G_, 1
	rest 3
	note G_, 1
	rest 3
	note_type 8, 1, 6
	note F_, 2
	note F_, 2
	note F_, 2
	note F_, 2
	note F_, 2
	note A_, 2
	note_type 12, 1, 6
	note G_, 1
	rest 3
	octave 1
	note G_, 1
	rest 11
	sound_ret

gbs_titlescreen_Ch4:
	gbs_switch 3
	toggle_noise 5
	stereo_panning TRUE, FALSE
	drum_speed 12
	rest 4
	drum_note 1, 2
	drum_note 1, 1
	drum_note 1, 1
	drum_note 1, 2
	drum_note 1, 1
	drum_note 1, 1
	drum_note 1, 1
	drum_note 1, 1
	drum_note 1, 6
	drum_note 1, 2
	drum_note 1, 1
	drum_note 1, 1
	drum_note 1, 2
	drum_note 1, 1
	drum_note 1, 1
	drum_note 1, 1
	drum_note 1, 1
	drum_note 1, 3
	drum_note 1, 1
	drum_note 1, 1
	drum_note 1, 1
	drum_note 1, 2
	drum_note 1, 1
	drum_note 1, 1
	drum_note 1, 2
	drum_note 1, 1
	drum_note 1, 1
	drum_note 1, 1
	drum_note 1, 1
	drum_note 1, 4
	drum_note 4, 2
	drum_note 1, 2
	drum_note 1, 1
	drum_note 1, 1
	drum_note 1, 2
	drum_note 1, 1
	drum_note 1, 1
	drum_note 1, 1
	drum_note 1, 1
	drum_note 1, 2
	drum_speed 6
	drum_note 3, 1
	drum_note 3, 1
	drum_note 2, 1
	drum_note 2, 1
	drum_note 2, 1
	drum_note 2, 1
	drum_note 1, 1
	drum_note 1, 1
	drum_speed 12
	sound_call gbs_titlescreen_Ch4.sub1
	sound_call gbs_titlescreen_Ch4.sub2
	sound_call gbs_titlescreen_Ch4.sub2
	drum_note 1, 2
	drum_note 4, 2
	drum_note 1, 2
	drum_note 4, 2
	drum_note 4, 2
	drum_note 1, 1
	drum_note 1, 1
	drum_note 1, 2
	drum_speed 6
	drum_note 2, 1
	drum_note 2, 1
	drum_note 1, 1
	drum_note 1, 1
	drum_speed 12
	sound_call gbs_titlescreen_Ch4.sub1
	drum_note 1, 2
	drum_note 4, 2
	drum_note 1, 2
	drum_note 6, 2
	drum_note 4, 2
	drum_note 1, 1
	drum_note 1, 1
	drum_note 1, 2
	drum_note 1, 2
	sound_call gbs_titlescreen_Ch4.sub2
	drum_note 1, 2
	drum_note 4, 2
	drum_note 1, 2
	drum_note 4, 2
	drum_note 4, 2
	drum_note 1, 1
	drum_note 1, 1
	drum_note 1, 2
	drum_note 1, 1
	drum_note 1, 1
	sound_call gbs_titlescreen_Ch4.sub1
	sound_call gbs_titlescreen_Ch4.sub2
	sound_call gbs_titlescreen_Ch4.sub2
	drum_note 1, 2
	drum_note 4, 2
	drum_note 1, 2
	drum_note 4, 2
	drum_note 4, 2
	drum_note 1, 1
	drum_note 1, 1
	drum_note 1, 2
	drum_speed 6
	drum_note 2, 1
	drum_note 3, 1
	drum_note 3, 1
	drum_note 2, 1
	drum_speed 12
	sound_call gbs_titlescreen_Ch4.sub1
	sound_call gbs_titlescreen_Ch4.sub2
	drum_note 1, 2
	drum_note 4, 2
	drum_note 1, 2
	drum_note 6, 2
	drum_note 4, 2
	drum_note 1, 1
	drum_note 1, 1
	drum_note 1, 2
	drum_note 1, 1
	drum_note 1, 1
	drum_note 1, 2
	drum_note 4, 2
	drum_note 1, 2
	drum_note 4, 2
	drum_note 4, 2
	drum_note 1, 1
	drum_note 1, 1
	drum_note 1, 2
	drum_speed 6
	drum_note 3, 1
	drum_note 3, 1
	drum_note 2, 1
	drum_note 2, 1
	drum_speed 12
	drum_note 10, 2
	drum_note 4, 4
	drum_note 10, 4
	drum_note 4, 2
	drum_note 10, 4
	drum_note 10, 2
	drum_note 4, 4
	drum_note 10, 4
	drum_note 4, 2
	drum_note 10, 2
	drum_note 10, 2
	drum_note 10, 2
	drum_note 4, 4
	drum_note 10, 4
	drum_note 4, 2
	drum_note 10, 4
	drum_note 10, 4
	drum_note 10, 4
	drum_note 10, 2
	drum_note 3, 1
	drum_note 3, 1
	drum_note 2, 1
	drum_note 2, 1
	drum_note 1, 1
	drum_note 1, 1
	sound_call gbs_titlescreen_Ch4.sub3
	sound_call gbs_titlescreen_Ch4.sub4
	drum_note 2, 1
	drum_note 3, 1
	drum_note 3, 1
	drum_note 2, 1
	drum_speed 12
	sound_call gbs_titlescreen_Ch4.sub3
	sound_call gbs_titlescreen_Ch4.sub4
	drum_note 3, 1
	drum_note 3, 1
	drum_note 2, 1
	drum_note 2, 1
	drum_speed 12
	sound_call gbs_titlescreen_Ch4.sub3
	sound_call gbs_titlescreen_Ch4.sub4
	drum_note 2, 1
	drum_note 2, 1
	drum_note 2, 1
	drum_note 2, 1
	drum_speed 12
	drum_note 9, 16
gbs_titlescreen_Ch4.loop1:
	rest 16
	sound_loop 6, gbs_titlescreen_Ch4.loop1
	rest 12
	drum_speed 6
	drum_note 3, 1
	drum_note 2, 1
	drum_note 3, 1
	drum_note 2, 1
	drum_note 3, 1
	drum_note 2, 1
	drum_note 1, 1
	drum_note 1, 1
	drum_speed 12
	drum_note 1, 4
	drum_note 1, 6
	drum_note 1, 1
	drum_note 1, 1
	drum_note 1, 4
	drum_note 1, 4
	drum_note 1, 6
	drum_note 1, 1
	drum_note 1, 1
	drum_note 1, 4
	drum_note 1, 4
	drum_note 1, 6
	drum_note 1, 1
	drum_note 1, 1
	drum_note 1, 4
	drum_note 1, 4
	drum_note 1, 4
	drum_speed 8
	drum_note 1, 2
	drum_note 1, 2
	drum_note 1, 2
	drum_speed 6
	drum_note 2, 1
	drum_note 2, 1
	drum_note 3, 1
	drum_note 3, 1
	drum_note 2, 1
	drum_note 2, 1
	drum_note 1, 1
	drum_note 1, 1
	drum_speed 12
	drum_note 1, 4
	drum_note 12, 4
	sound_ret

gbs_titlescreen_Ch4.sub1:
	drum_note 1, 2
	drum_note 4, 2
	drum_note 1, 2
	drum_note 4, 2
	drum_note 6, 2
	drum_note 1, 1
	drum_note 1, 1
	drum_note 1, 2
	drum_note 4, 2
	sound_ret

gbs_titlescreen_Ch4.sub2:
	drum_note 1, 2
	drum_note 4, 2
	drum_note 1, 2
	drum_note 6, 2
	drum_note 4, 2
	drum_note 1, 1
	drum_note 1, 1
	drum_note 1, 2
	drum_note 4, 2
	sound_ret

gbs_titlescreen_Ch4.sub3:
gbs_titlescreen_Ch4.sub3loop1:
	drum_note 1, 2
	drum_note 1, 1
	drum_note 1, 1
	sound_loop 4, gbs_titlescreen_Ch4.sub3loop1
	sound_ret

gbs_titlescreen_Ch4.sub4:
	drum_note 1, 2
	drum_note 1, 1
	drum_note 1, 1
	drum_note 1, 2
	drum_note 1, 1
	drum_note 1, 1
	drum_speed 8
	drum_note 1, 4
	drum_note 1, 4
	sound_ret

	.align 4
	.global gbs_titlescreen_Header
gbs_titlescreen_Header:
	.byte 4	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_titlescreen_Ch1
	.int gbs_titlescreen_Ch2
	.int gbs_titlescreen_Ch3
	.int gbs_titlescreen_Ch4
