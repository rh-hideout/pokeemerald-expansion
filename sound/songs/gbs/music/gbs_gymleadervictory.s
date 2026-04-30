	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_gymleadervictory_Ch1:
	gbs_switch 0
	tempo 116
	volume 7, 7
	vibrato 18, 3, 4
	duty_cycle 3
	pitch_offset 1
	note_type 12, 11, 7
	octave 4
	note D_, 6
	octave 3
	note A_, 1
	octave 4
	note D_, 1
	note Fs, 6
	note D_, 1
	note Fs, 1
	note A_, 6
	note Fs, 1
	note A_, 1
	octave 5
	note D_, 8
	stereo_panning FALSE, TRUE
gbs_gymleadervictory_Ch1.mainloop:
gbs_gymleadervictory_Ch1.loop1:
	duty_cycle 1
	sound_call gbs_gymleadervictory_Ch1.sub1
	octave 4
	note Cs, 4
	note E_, 4
	sound_call gbs_gymleadervictory_Ch1.sub1
	note Fs, 8
	sound_loop 2, gbs_gymleadervictory_Ch1.loop1
	duty_cycle 2
	sound_call gbs_gymleadervictory_Ch1.sub2
	note A_, 4
	note G_, 4
	note Fs, 6
	note D_, 1
	note E_, 1
	note Fs, 6
	note E_, 2
	note D_, 8
	note Cs, 8
	duty_cycle 3
	sound_call gbs_gymleadervictory_Ch1.sub2
	note Cs, 4
	note E_, 4
	note G_, 6
	note A_, 1
	note G_, 1
	note A_, 6
	note G_, 2
	volume_envelope 8, 7
	note Fs, 16
	sound_loop 0, gbs_gymleadervictory_Ch1.mainloop

gbs_gymleadervictory_Ch1.sub1:
	volume_envelope 9, 1
	octave 3
	note Fs, 2
	note A_, 2
	octave 4
	note D_, 2
	octave 3
	note A_, 1
	note Fs, 1
	note E_, 2
	note A_, 2
	octave 4
	note Cs, 2
	octave 3
	note A_, 1
	note E_, 1
	note D_, 2
	note G_, 2
	note B_, 2
	note G_, 1
	note D_, 1
	sound_ret

gbs_gymleadervictory_Ch1.sub2:
	volume_envelope 8, 7
	octave 3
	note Fs, 14
	note D_, 1
	note Fs, 1
	note A_, 8
	note Fs, 4
	note A_, 1
	note Gs, 1
	note Fs, 1
	note A_, 1
	note Gs, 14
	note E_, 1
	note Gs, 1
	note B_, 8
	octave 4
	note D_, 4
	note E_, 1
	note D_, 1
	note E_, 1
	note D_, 1
	note Cs, 14
	octave 3
	note A_, 1
	octave 4
	note Cs, 1
	note E_, 8
	sound_ret

gbs_gymleadervictory_Ch2:
	gbs_switch 1
	vibrato 18, 3, 4
	duty_cycle 3
	note_type 12, 13, 7
	octave 4
	note A_, 6
	note Fs, 1
	note A_, 1
	octave 5
	note D_, 6
	octave 4
	note A_, 1
	octave 5
	note D_, 1
	note Fs, 16
gbs_gymleadervictory_Ch2.mainloop:
	duty_cycle 3
	volume_envelope 10, 1
	sound_call gbs_gymleadervictory_Ch2.sub1
	note A_, 4
	note A_, 4
	sound_call gbs_gymleadervictory_Ch2.sub1
	note D_, 6
	duty_cycle 2
	note B_, 1
	octave 5
	note Cs, 1
	sound_call gbs_gymleadervictory_Ch2.sub1
	note A_, 4
	note A_, 4
	sound_call gbs_gymleadervictory_Ch2.sub1
	note D_, 8
	duty_cycle 3
	sound_call gbs_gymleadervictory_Ch2.sub2
	note Fs, 4
	note E_, 4
	note D_, 14
	octave 4
	note B_, 2
	volume_envelope 10, 7
	note A_, 16
	duty_cycle 2
	sound_call gbs_gymleadervictory_Ch2.sub2
	octave 4
	note A_, 4
	octave 5
	note Cs, 4
	note D_, 14
	note E_, 2
	volume_envelope 10, 6
	note D_, 12
	rest 2
	duty_cycle 3
	octave 4
	note B_, 1
	octave 5
	note Cs, 1
	sound_loop 0, gbs_gymleadervictory_Ch2.mainloop

gbs_gymleadervictory_Ch2.sub1:
	octave 5
	note D_, 2
	note Cs, 2
	octave 4
	note B_, 4
	octave 5
	note Cs, 2
	octave 4
	note B_, 2
	note A_, 4
	note B_, 2
	note A_, 2
	note G_, 2
	note Fs, 2
	sound_ret

gbs_gymleadervictory_Ch2.sub2:
	volume_envelope 9, 8
	note A_, 6
	note Fs, 1
	note A_, 1
	octave 5
	note D_, 8
	note D_, 16
	octave 4
	note B_, 6
	note Gs, 1
	note B_, 1
	octave 5
	note E_, 8
	note E_, 16
	octave 4
	note G_, 6
	note E_, 1
	note G_, 1
	octave 5
	note Cs, 8
	note Cs, 8
	sound_ret

gbs_gymleadervictory_Ch3:
	gbs_switch 2
	note_type 12, 2, 5
	octave 3
	note Fs, 16
	note D_, 10
	octave 2
	note A_, 2
	note B_, 2
	octave 3
	note Cs, 2
	stereo_panning TRUE, FALSE
gbs_gymleadervictory_Ch3.mainloop:
gbs_gymleadervictory_Ch3.loop1:
	note D_, 2
	rest 4
	octave 2
	note A_, 2
	octave 3
	note Cs, 2
	rest 4
	octave 2
	note A_, 2
	note B_, 2
	rest 4
	note G_, 2
	note A_, 2
	rest 2
	octave 3
	note Cs, 4
	note D_, 2
	rest 4
	octave 2
	note A_, 2
	octave 3
	note Cs, 2
	rest 4
	octave 2
	note A_, 2
	note B_, 2
	rest 4
	note G_, 2
	octave 3
	note D_, 2
	rest 6
	sound_loop 2, gbs_gymleadervictory_Ch3.loop1
	sound_call gbs_gymleadervictory_Ch3.sub1
	octave 3
	note D_, 2
	rest 2
	note D_, 2
	octave 4
	note D_, 2
	rest 2
	octave 3
	note D_, 2
	note Fs, 2
	note D_, 2
	note A_, 2
	rest 2
	octave 2
	note A_, 2
	octave 3
	note E_, 2
	rest 2
	octave 2
	note A_, 2
	octave 3
	note Cs, 2
	octave 2
	note A_, 2
	sound_call gbs_gymleadervictory_Ch3.sub1
	octave 3
	note D_, 2
	rest 2
	note G_, 2
	octave 4
	note D_, 2
	rest 2
	octave 3
	note D_, 2
	note G_, 2
	note E_, 2
	note D_, 2
	rest 2
	note D_, 2
	note A_, 2
	rest 2
	octave 2
	note A_, 2
	note B_, 2
	octave 3
	note Cs, 2
	sound_loop 0, gbs_gymleadervictory_Ch3.mainloop

gbs_gymleadervictory_Ch3.sub1:
	octave 3
	note D_, 2
	rest 2
	note D_, 2
	octave 4
	note D_, 2
	rest 2
	octave 3
	note D_, 2
	note Fs, 2
	note D_, 2
	note A_, 2
	rest 2
	note D_, 2
	note Fs, 2
	rest 2
	octave 2
	note A_, 2
	octave 3
	note D_, 2
	octave 2
	note A_, 2
	octave 3
	note E_, 2
	rest 2
	note E_, 2
	octave 4
	note E_, 2
	rest 2
	octave 3
	note E_, 2
	note Gs, 2
	note E_, 2
	note B_, 2
	rest 2
	note E_, 2
	note Gs, 2
	rest 2
	octave 2
	note B_, 2
	octave 3
	note E_, 2
	octave 2
	note B_, 2
	note A_, 2
	rest 2
	note A_, 2
	octave 3
	note A_, 2
	rest 2
	octave 2
	note A_, 2
	octave 3
	note Cs, 2
	octave 2
	note A_, 2
	octave 3
	note A_, 2
	rest 2
	octave 2
	note A_, 2
	octave 3
	note E_, 2
	rest 2
	octave 2
	note A_, 2
	octave 3
	note Cs, 2
	octave 2
	note A_, 2
	sound_ret

gbs_gymleadervictory_Ch4:
	gbs_switch 3
	toggle_noise 4
	drum_speed 12
	drum_note 12, 16
	drum_note 12, 16
gbs_gymleadervictory_Ch4.mainloop:
	sound_call gbs_gymleadervictory_Ch4.sub1
	drum_note 4, 6
	drum_note 4, 2
	drum_note 4, 8
	sound_call gbs_gymleadervictory_Ch4.sub1
	drum_note 4, 6
	drum_note 4, 2
	drum_note 4, 4
	drum_note 2, 1
	drum_note 2, 1
	drum_note 2, 1
	drum_note 2, 1
gbs_gymleadervictory_Ch4.loop1:
	drum_note 4, 2
	drum_note 8, 2
	drum_note 3, 2
	drum_note 4, 2
	drum_note 8, 2
	drum_note 4, 2
	drum_note 3, 2
	drum_note 8, 2
	sound_loop 16, gbs_gymleadervictory_Ch4.loop1
	sound_loop 0, gbs_gymleadervictory_Ch4.mainloop

gbs_gymleadervictory_Ch4.sub1:
gbs_gymleadervictory_Ch4.sub1loop1:
	drum_note 4, 6
	drum_note 4, 2
	drum_note 4, 4
	drum_note 3, 2
	drum_note 4, 2
	sound_loop 3, gbs_gymleadervictory_Ch4.sub1loop1
	sound_ret

	.align 4
	.global gbs_gymleadervictory_Header
gbs_gymleadervictory_Header:
	.byte 4	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_gymleadervictory_Ch1
	.int gbs_gymleadervictory_Ch2
	.int gbs_gymleadervictory_Ch3
	.int gbs_gymleadervictory_Ch4
