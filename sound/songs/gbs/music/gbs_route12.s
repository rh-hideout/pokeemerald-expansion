	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_route12_Ch1:
	gbs_switch 0
	tempo 148
	volume 7, 7
	vibrato 18, 3, 4
	pitch_offset 1
	stereo_panning FALSE, TRUE
	duty_cycle 3
	note_type 12, 9, 8
	octave 3
	note Gs, 1
	rest 2
	note A_, 1
	note Gs, 8
	octave 2
	note B_, 1
	octave 3
	note E_, 1
	note Fs, 1
	note Gs, 1
	note Fs, 1
	rest 2
	note E_, 1
	volume_envelope 9, 7
	note Ds, 12
gbs_route12_Ch1.mainloop:
	duty_cycle 2
	volume_envelope 9, 6
	sound_call gbs_route12_Ch1.sub1
	sound_call gbs_route12_Ch1.sub2
	sound_call gbs_route12_Ch1.sub1
	note E_, 1
	rest 2
	note Fs, 1
	note E_, 4
	note B_, 4
	octave 4
	note Ds, 4
	sound_call gbs_route12_Ch1.sub1
	sound_call gbs_route12_Ch1.sub2
	sound_call gbs_route12_Ch1.sub1
	volume_envelope 9, 2
	octave 4
	note E_, 1
	octave 3
	note B_, 1
	note Gs, 1
	note E_, 1
	octave 4
	note Ds, 1
	octave 3
	note B_, 1
	note Gs, 1
	note Ds, 1
	octave 4
	note D_, 1
	octave 3
	note B_, 1
	note Gs, 1
	note D_, 1
	note Cs, 1
	note F_, 1
	note Gs, 1
	note B_, 1
	duty_cycle 3
	volume_envelope 7, -7
	octave 4
	note Cs, 3
	octave 3
	note B_, 3
	note A_, 1
	rest 1
	note A_, 4
	octave 4
	note Cs, 2
	octave 3
	note B_, 2
	octave 4
	note Cs, 1
	octave 3
	note B_, 1
	note A_, 4
	note Gs, 2
	note Fs, 2
	note Gs, 2
	note A_, 2
	octave 4
	note C_, 2
	octave 3
	note B_, 3
	note A_, 3
	note Gs, 1
	rest 1
	note Gs, 4
	note B_, 2
	note A_, 2
	note B_, 1
	note A_, 1
	note Gs, 4
	note Fs, 2
	note E_, 2
	note Fs, 2
	note G_, 2
	note E_, 2
	note Ds, 3
	note Fs, 3
	note Ds, 2
	note E_, 8
	note Fs, 8
	note Ds, 4
	note Fs, 4
gbs_route12_Ch1.loop1:
	volume_envelope 9, 7
	note Gs, 1
	note A_, 1
	note B_, 4
	octave 2
	note B_, 1
	octave 3
	note Ds, 1
	note E_, 1
	rest 1
	note E_, 1
	note Fs, 1
	note Gs, 4
	sound_loop 2, gbs_route12_Ch1.loop1
	sound_loop 0, gbs_route12_Ch1.mainloop

gbs_route12_Ch1.sub1:
	octave 3
	note Gs, 1
	rest 1
	note E_, 1
	rest 1
	octave 2
	note B_, 1
	rest 1
	note B_, 1
	octave 3
	note Ds, 1
	note E_, 4
	note Gs, 4
	sound_ret

gbs_route12_Ch1.sub2:
	note A_, 1
	rest 1
	note Fs, 1
	rest 1
	note D_, 1
	rest 1
	note Fs, 1
	note Gs, 1
	note A_, 4
	note Fs, 4
	sound_ret

gbs_route12_Ch2:
	gbs_switch 1
	duty_cycle 3
	vibrato 18, 3, 4
	note_type 12, 11, 8
	octave 4
	note E_, 1
	rest 2
	note Fs, 1
	note E_, 12
	octave 3
	note B_, 1
	rest 2
	octave 4
	note C_, 1
	volume_envelope 11, 7
	octave 3
	note B_, 8
	note Ds, 1
	note Fs, 1
	note B_, 1
	octave 4
	note Ds, 1
gbs_route12_Ch2.mainloop:
	duty_cycle 3
	volume_envelope 11, 7
	sound_call gbs_route12_Ch2.sub1
	note Fs, 1
	note A_, 1
	note Gs, 1
	note Fs, 1
	note Gs, 2
	rest 1
	note E_, 1
	octave 3
	note B_, 12
	duty_cycle 2
	octave 2
	note B_, 1
	rest 2
	octave 3
	note C_, 1
	octave 2
	note B_, 4
	octave 3
	note Ds, 4
	note Fs, 4
	duty_cycle 3
	sound_call gbs_route12_Ch2.sub1
	note A_, 1
	octave 5
	note Cs, 1
	octave 4
	note B_, 1
	note A_, 1
	note B_, 2
	rest 1
	note A_, 1
	volume_envelope 11, 8
	note Gs, 6
	volume_envelope 11, 7
	note Gs, 6
	volume_envelope 6, -7
	note Gs, 16
	duty_cycle 2
	volume_envelope 10, 8
	note A_, 3
	note Gs, 3
	note Fs, 1
	rest 1
	note Fs, 8
	volume_envelope 10, 7
	note Fs, 10
	rest 2
	note Fs, 4
	volume_envelope 10, 8
	note Gs, 3
	note Fs, 3
	note E_, 1
	rest 1
	note E_, 8
	volume_envelope 10, 7
	note E_, 10
	rest 2
	note E_, 4
	note Fs, 3
	note Ds, 3
	octave 3
	note B_, 2
	volume_envelope 10, 8
	octave 4
	note B_, 8
	note B_, 8
	note A_, 8
	note Gs, 1
	note Fs, 1
	note E_, 14
	note E_, 10
	volume_envelope 10, 4
	note E_, 6
	sound_loop 0, gbs_route12_Ch2.mainloop

gbs_route12_Ch2.sub1:
	octave 4
	note E_, 6
	volume_envelope 11, 1
	octave 3
	note B_, 1
	note B_, 1
	volume_envelope 11, 7
	note B_, 4
	octave 4
	note B_, 4
	note A_, 4
	note Gs, 4
	note Fs, 4
	sound_ret

gbs_route12_Ch3:
	gbs_switch 2
	vibrato 18, 5, 4
	note_type 12, 1, 6
	octave 3
	note Gs, 2
	rest 4
	note Gs, 1
	note A_, 1
	note B_, 2
	rest 2
	note E_, 4
	note Ds, 2
	rest 4
	note Ds, 1
	note E_, 1
	note Fs, 2
	rest 2
	note Ds, 4
gbs_route12_Ch3.mainloop:
	sound_call gbs_route12_Ch3.sub1
	note Fs, 1
	rest 1
	note E_, 1
	rest 3
	note Ds, 1
	note E_, 1
	note Fs, 4
	octave 2
	note B_, 4
	sound_call gbs_route12_Ch3.sub1
	note E_, 1
	rest 1
	note B_, 1
	rest 3
	octave 2
	note B_, 1
	octave 3
	note Cs, 1
	note D_, 4
	note F_, 4
	note Fs, 13
	rest 1
	note Fs, 1
	note Gs, 1
	note A_, 5
	rest 1
	note A_, 1
	note B_, 1
	octave 4
	note C_, 4
	octave 3
	note Fs, 4
	note E_, 14
	note Gs, 1
	note A_, 1
	note B_, 6
	note E_, 1
	note Fs, 1
	note G_, 4
	note E_, 4
	octave 2
	note B_, 5
	rest 1
	note B_, 1
	octave 3
	note Ds, 1
	note Fs, 8
	note E_, 8
	note Fs, 4
	note Ds, 4
gbs_route12_Ch3.loop1:
	note E_, 1
	rest 1
	note E_, 1
	rest 3
	note E_, 1
	note Fs, 1
	note Gs, 4
	note E_, 3
	rest 1
	sound_loop 2, gbs_route12_Ch3.loop1
	sound_loop 0, gbs_route12_Ch3.mainloop

gbs_route12_Ch3.sub1:
	octave 3
	note E_, 1
	rest 1
	note E_, 1
	rest 3
	note E_, 1
	note Fs, 1
	note Gs, 4
	note E_, 4
	note D_, 1
	rest 1
	note D_, 1
	rest 3
	note D_, 1
	note E_, 1
	note Fs, 4
	note D_, 4
	note E_, 1
	rest 1
	note E_, 1
	rest 3
	note E_, 1
	note Fs, 1
	note Gs, 4
	note E_, 4
	sound_ret

gbs_route12_Ch4:
	gbs_switch 3
	toggle_noise 4
	stereo_panning TRUE, FALSE
	drum_speed 12
	drum_note 12, 10
	drum_note 2, 1
	drum_note 2, 1
	drum_note 3, 4
	drum_note 12, 6
	drum_note 2, 1
	drum_note 2, 1
	drum_note 3, 4
	drum_speed 6
	sound_call gbs_route12_Ch4.sub1
gbs_route12_Ch4.mainloop:
gbs_route12_Ch4.loop1:
	drum_note 3, 4
	drum_note 3, 8
	drum_note 2, 2
	drum_note 2, 2
	drum_note 3, 8
	sound_call gbs_route12_Ch4.sub1
	sound_loop 8, gbs_route12_Ch4.loop1
gbs_route12_Ch4.loop2:
	drum_speed 12
	drum_note 12, 10
	drum_note 3, 1
	drum_note 3, 1
	drum_note 3, 6
	drum_note 2, 1
	drum_note 2, 1
	drum_note 3, 6
	drum_note 2, 1
	drum_note 2, 1
	drum_note 3, 4
	sound_loop 2, gbs_route12_Ch4.loop2
	drum_note 12, 16
	drum_speed 6
	sound_call gbs_route12_Ch4.sub1
	sound_call gbs_route12_Ch4.sub1
	drum_note 12, 16
gbs_route12_Ch4.loop3:
	drum_note 3, 4
	drum_note 3, 8
	drum_note 2, 2
	drum_note 2, 2
	drum_note 3, 8
	sound_call gbs_route12_Ch4.sub1
	sound_loop 2, gbs_route12_Ch4.loop3
	sound_loop 0, gbs_route12_Ch4.mainloop

gbs_route12_Ch4.sub1:
	drum_note 2, 1
	drum_note 2, 1
	drum_note 2, 1
	drum_note 2, 1
	drum_note 2, 1
	drum_note 2, 1
	drum_note 2, 1
	drum_note 2, 1
	sound_ret

	.align 4
	.global gbs_route12_Header
gbs_route12_Header:
	.byte 4	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_route12_Ch1
	.int gbs_route12_Ch2
	.int gbs_route12_Ch3
	.int gbs_route12_Ch4
