	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_pokemoncenter_Ch1:
	gbs_switch 0
	tempo 152
	volume 7, 7
	duty_cycle 2
	vibrato 10, 1, 4
	pitch_offset 1
gbs_pokemoncenter_Ch1.mainloop:
	stereo_panning FALSE, TRUE
	note_type 12, 8, 3
	octave 3
	note Fs, 2
	note F_, 2
	note Fs, 2
	octave 4
	note D_, 4
	note Cs, 2
	octave 3
	note B_, 2
	note A_, 2
	note B_, 2
	note A_, 2
	note G_, 2
	note Fs, 2
	note E_, 2
	note Fs, 2
	note G_, 2
	note A_, 2
	note A_, 2
	note E_, 2
	note A_, 2
	octave 4
	note Cs, 4
	octave 3
	note B_, 2
	note A_, 2
	note G_, 2
	note Fs, 2
	note A_, 2
	note B_, 2
	octave 4
	note Cs, 2
	note D_, 2
	note Cs, 2
	octave 3
	note B_, 2
	note A_, 2
	note Fs, 2
	note F_, 2
	note Fs, 2
	octave 4
	note D_, 4
	note Cs, 2
	octave 3
	note B_, 2
	note A_, 2
	note B_, 2
	note A_, 2
	note G_, 2
	note Fs, 2
	note E_, 2
	note Fs, 2
	note G_, 2
	note A_, 2
	note A_, 2
	note E_, 2
	note A_, 2
	octave 4
	note Cs, 4
	octave 3
	note B_, 2
	note A_, 2
	note G_, 2
	note_type 12, 11, 4
	note Fs, 2
	note E_, 2
	note D_, 2
	note E_, 2
	note Fs, 2
	note G_, 2
	note A_, 2
	note B_, 2
	stereo_panning TRUE, FALSE
	note Fs, 2
	note E_, 2
	note D_, 4
	note E_, 2
	note Fs, 2
	note G_, 2
	note A_, 2
	note B_, 2
	note A_, 2
	note G_, 4
	note E_, 2
	note Fs, 2
	note G_, 2
	note A_, 2
	note G_, 2
	note Fs, 2
	note E_, 4
	note Cs, 2
	note D_, 2
	note E_, 2
	note G_, 2
	note Fs, 2
	note G_, 2
	note A_, 2
	note B_, 2
	note A_, 8
	octave 4
	note D_, 2
	note Cs, 2
	octave 3
	note B_, 4
	note A_, 2
	note B_, 2
	octave 4
	note Cs, 2
	note D_, 2
	note E_, 2
	note D_, 2
	note Cs, 4
	octave 3
	note B_, 2
	octave 4
	note Cs, 2
	note D_, 2
	note E_, 2
	note Cs, 2
	octave 3
	note B_, 2
	note A_, 4
	note G_, 2
	note A_, 2
	note B_, 2
	note G_, 2
	note A_, 2
	note G_, 2
	note Fs, 2
	note E_, 2
	note D_, 2
	note E_, 2
	note Fs, 2
	note G_, 2
	sound_loop 0, gbs_pokemoncenter_Ch1.mainloop

gbs_pokemoncenter_Ch2:
	gbs_switch 1
	vibrato 16, 2, 5
gbs_pokemoncenter_Ch2.mainloop:
	stereo_panning TRUE, TRUE
	sound_call gbs_pokemoncenter_Ch2.sub1
	stereo_panning FALSE, TRUE
	note_type 12, 10, 5
	octave 3
	note A_, 4
	note E_, 4
	stereo_panning TRUE, TRUE
	sound_call gbs_pokemoncenter_Ch2.sub2
	note D_, 2
	note Fs, 6
	stereo_panning FALSE, TRUE
	note_type 12, 10, 5
	octave 3
	note A_, 4
	note E_, 4
	stereo_panning TRUE, TRUE
	sound_call gbs_pokemoncenter_Ch2.sub1
	stereo_panning FALSE, TRUE
	note_type 12, 10, 5
	octave 3
	note A_, 4
	note E_, 4
	stereo_panning TRUE, TRUE
	sound_call gbs_pokemoncenter_Ch2.sub2
	note D_, 8
	stereo_panning FALSE, TRUE
	note_type 12, 10, 5
	octave 3
	note D_, 4
	note E_, 4
	note_type 12, 12, 6
	octave 4
	note Fs, 8
	note A_, 8
	note G_, 2
	note A_, 2
	note G_, 2
	note Fs, 2
	note E_, 8
	note Cs, 8
	note E_, 8
	note Fs, 2
	note G_, 2
	note Fs, 2
	note E_, 2
	note D_, 8
	note Fs, 8
	note A_, 8
	note G_, 2
	note Fs, 2
	note G_, 2
	note A_, 2
	note B_, 8
	note A_, 4
	note G_, 2
	note Fs, 2
	note G_, 8
	note Fs, 2
	note G_, 2
	note Fs, 2
	note E_, 2
	note D_, 8
	sound_loop 0, gbs_pokemoncenter_Ch2.mainloop

gbs_pokemoncenter_Ch2.sub1:
	duty_cycle 2
	note_type 12, 12, 2
	octave 4
	note D_, 2
	octave 3
	note A_, 2
	octave 4
	note D_, 2
	volume_envelope 12, 3
	note A_, 4
	note G_, 4
	note Fs, 2
	note E_, 2
	note Cs, 6
	sound_ret

gbs_pokemoncenter_Ch2.sub2:
	note_type 12, 12, 2
	octave 4
	note Cs, 2
	octave 3
	note A_, 2
	octave 4
	note Cs, 2
	volume_envelope 12, 3
	note Fs, 4
	note E_, 4
	note Cs, 2
	sound_ret

gbs_pokemoncenter_Ch3:
	gbs_switch 2
	note_type 12, 2, 8
gbs_pokemoncenter_Ch3.mainloop:
	stereo_panning TRUE, FALSE
	octave 3
	note D_, 1
	rest 5
	note Fs, 1
	rest 3
	note Fs, 1
	rest 1
	note G_, 1
	rest 1
	note Fs, 1
	rest 1
	sound_call gbs_pokemoncenter_Ch3.sub1
	sound_call gbs_pokemoncenter_Ch3.sub2
	note Fs, 1
	rest 5
	note A_, 1
	rest 3
	note A_, 1
	rest 1
	note G_, 1
	rest 1
	note A_, 1
	rest 1
	note D_, 1
	rest 5
	note Fs, 1
	rest 3
	note Fs, 1
	rest 1
	note G_, 1
	rest 1
	note Fs, 1
	rest 1
	sound_call gbs_pokemoncenter_Ch3.sub1
	sound_call gbs_pokemoncenter_Ch3.sub2
	note D_, 1
	rest 5
	note Fs, 1
	rest 3
	note Fs, 1
	rest 1
	note D_, 1
	rest 1
	note G_, 1
	rest 1
	stereo_panning TRUE, TRUE
	sound_call gbs_pokemoncenter_Ch3.sub3
	note G_, 1
	rest 5
	note B_, 1
	rest 3
	note B_, 1
	rest 1
	note G_, 1
	rest 1
	note B_, 1
	rest 1
	note E_, 1
	rest 5
	note G_, 1
	rest 3
	note G_, 1
	rest 3
	note G_, 1
	rest 1
	note Fs, 1
	rest 5
	note A_, 1
	rest 3
	note A_, 1
	rest 1
	note Gs, 1
	rest 1
	note A_, 1
	rest 1
	sound_call gbs_pokemoncenter_Ch3.sub3
	note G_, 1
	rest 5
	note B_, 1
	rest 3
	note B_, 1
	rest 3
	note B_, 1
	rest 1
	note E_, 1
	rest 5
	note G_, 1
	rest 3
	note G_, 1
	rest 3
	note G_, 1
	rest 1
	note Fs, 1
	rest 5
	note A_, 1
	rest 3
	note A_, 1
	rest 1
	note G_, 1
	rest 1
	note E_, 1
	rest 1
	sound_loop 0, gbs_pokemoncenter_Ch3.mainloop

gbs_pokemoncenter_Ch3.sub1:
	note E_, 1
	rest 5
	note A_, 1
	rest 3
	note A_, 1
	rest 3
	note A_, 1
	rest 1
	sound_ret

gbs_pokemoncenter_Ch3.sub2:
	note E_, 1
	rest 5
	note A_, 1
	rest 3
	note A_, 1
	rest 1
	note G_, 1
	rest 1
	note A_, 1
	rest 1
	sound_ret

gbs_pokemoncenter_Ch3.sub3:
	note Fs, 1
	rest 5
	note A_, 1
	rest 3
	note A_, 1
	rest 3
	note A_, 1
	rest 1
	sound_ret

gbs_pokemoncenter_Ch4:
	gbs_switch 3
	toggle_noise 3
	drum_speed 12
	stereo_panning TRUE, TRUE
gbs_pokemoncenter_Ch4.mainloop:
	drum_note 8, 6
	drum_note 8, 4
	drum_note 8, 2
	drum_note 8, 2
	drum_note 8, 2
	sound_loop 0, gbs_pokemoncenter_Ch4.mainloop

	.align 4
	.global gbs_pokemoncenter_Header
gbs_pokemoncenter_Header:
	.byte 4	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_pokemoncenter_Ch1
	.int gbs_pokemoncenter_Ch2
	.int gbs_pokemoncenter_Ch3
	.int gbs_pokemoncenter_Ch4
