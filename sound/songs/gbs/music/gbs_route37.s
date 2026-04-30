	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_route37_Ch1:
	gbs_switch 0
	tempo 144
	volume 7, 7
	duty_cycle 3
	pitch_offset 2
	vibrato 16, 2, 2
	note_type 12, 11, 3
	rest 16
	rest 16
gbs_route37_Ch1.mainloop:
	volume_envelope 11, 3
	rest 2
	octave 2
	note Fs, 2
	note B_, 2
	octave 3
	note E_, 2
	volume_envelope 11, 7
	note Ds, 10
	volume_envelope 11, 3
	note E_, 4
	note Ds, 4
	note Cs, 4
	octave 2
	note B_, 2
	octave 3
	note Ds, 3
	octave 2
	note B_, 1
	volume_envelope 11, 7
	note Fs, 8
	note B_, 8
	octave 3
	note B_, 12
	volume_envelope 11, 3
	rest 2
	octave 2
	note Fs, 2
	note B_, 2
	octave 3
	note E_, 2
	volume_envelope 11, 7
	note Ds, 10
	octave 2
	note A_, 4
	octave 3
	note Cs, 4
	note E_, 4
	note A_, 2
	note Fs, 3
	note A_, 1
	note B_, 6
	octave 2
	note B_, 2
	octave 3
	note Ds, 2
	note Fs, 2
	note B_, 2
	note A_, 4
	note Fs, 4
	note E_, 2
	note Ds, 4
	stereo_panning FALSE, TRUE
gbs_route37_Ch1.loop1:
	sound_call gbs_route37_Ch1.sub1
	octave 3
	note Cs, 4
	sound_loop 2, gbs_route37_Ch1.loop1
	sound_call gbs_route37_Ch1.sub2
	octave 3
	note Fs, 4
	sound_call gbs_route37_Ch1.sub2
	octave 3
	note Fs, 4
	sound_call gbs_route37_Ch1.sub1
	octave 3
	note E_, 4
	sound_call gbs_route37_Ch1.sub1
	octave 3
	note Gs, 4
	sound_call gbs_route37_Ch1.sub2
	octave 4
	note Ds, 4
	sound_call gbs_route37_Ch1.sub2
	octave 3
	note F_, 4
	stereo_panning TRUE, TRUE
	sound_call gbs_route37_Ch1.sub2
	rest 4
	sound_call gbs_route37_Ch1.sub2
	rest 4
	sound_loop 0, gbs_route37_Ch1.mainloop

gbs_route37_Ch1.sub1:
	volume_envelope 12, 2
	octave 2
	note A_, 2
	note A_, 1
	note A_, 1
	note A_, 2
	note A_, 1
	note A_, 1
	note A_, 1
	note A_, 1
	note A_, 2
	volume_envelope 11, 7
	sound_ret

gbs_route37_Ch1.sub2:
	volume_envelope 12, 2
	octave 2
	note B_, 2
	note B_, 1
	note B_, 1
	note B_, 2
	note B_, 1
	note B_, 1
	note B_, 1
	note B_, 1
	note B_, 2
	volume_envelope 11, 7
	sound_ret

gbs_route37_Ch2:
	gbs_switch 1
	duty_cycle 3
	vibrato 28, 1, 2
	note_type 12, 12, 2
	octave 2
	note B_, 2
	note_type 12, 12, 1
	note B_, 1
	note B_, 1
	volume_envelope 12, 2
	note B_, 2
	volume_envelope 12, 1
	note B_, 1
	note B_, 1
	note B_, 1
	note B_, 1
	volume_envelope 12, 2
	note B_, 6
	note B_, 2
	volume_envelope 12, 1
	note B_, 1
	note B_, 1
	volume_envelope 12, 2
	note B_, 2
	volume_envelope 12, 1
	note B_, 1
	note B_, 1
	note B_, 1
	note B_, 1
	volume_envelope 12, 2
	note B_, 2
gbs_route37_Ch2.mainloop:
	sound_call gbs_route37_Ch2.sub1
	volume_envelope 12, 6
	octave 4
	note Cs, 4
	octave 3
	note B_, 4
	note A_, 4
	note E_, 4
	volume_envelope 11, 0
	note Fs, 8
	volume_envelope 11, 7
	note Fs, 8
	volume_envelope 12, 7
	note Ds, 12
	sound_call gbs_route37_Ch2.sub1
	volume_envelope 12, 7
	octave 4
	note Cs, 4
	octave 3
	note B_, 4
	octave 4
	note Cs, 4
	note E_, 4
	volume_envelope 11, 0
	note Ds, 16
	volume_envelope 11, 0
	note Ds, 8
	volume_envelope 11, 7
	note Ds, 8
	volume_envelope 12, 4
	rest 4
	octave 3
	note A_, 3
	octave 4
	note E_, 1
	note A_, 4
	note Gs, 4
	volume_envelope 10, 0
	note Cs, 6
	note Ds, 6
	note E_, 4
	volume_envelope 12, 3
	note Fs, 3
	note E_, 1
	volume_envelope 11, 0
	note Ds, 6
	volume_envelope 11, 7
	note Ds, 6
	volume_envelope 12, 3
	octave 3
	note B_, 3
	note Fs, 1
	volume_envelope 11, 0
	octave 4
	note Ds, 6
	volume_envelope 11, 7
	octave 4
	note Ds, 6
	volume_envelope 12, 4
	rest 4
	octave 3
	note A_, 3
	octave 4
	note E_, 1
	note A_, 4
	note Gs, 4
	volume_envelope 11, 0
	note Cs, 6
	note Ds, 6
	note E_, 4
	volume_envelope 12, 3
	note Fs, 3
	note Ds, 1
	volume_envelope 11, 0
	note B_, 6
	volume_envelope 11, 7
	note B_, 6
	volume_envelope 12, 3
	note B_, 3
	note Fs, 1
	volume_envelope 11, 0
	octave 5
	note Ds, 6
	volume_envelope 11, 7
	octave 5
	note Ds, 6
	volume_envelope 12, 2
	octave 3
	note Fs, 2
	note Fs, 1
	note Fs, 1
	note Fs, 2
	volume_envelope 12, 1
	note Fs, 1
	note Fs, 1
	note Fs, 1
	note Fs, 1
	volume_envelope 12, 2
	note Fs, 6
	note Fs, 2
	note Fs, 1
	note Fs, 1
	note Fs, 2
	volume_envelope 12, 1
	note Fs, 1
	note Fs, 1
	note Fs, 1
	note Fs, 1
	volume_envelope 12, 2
	note Fs, 2
	sound_loop 0, gbs_route37_Ch2.mainloop

gbs_route37_Ch2.sub1:
	volume_envelope 12, 7
	octave 3
	note Fs, 4
	volume_envelope 11, 0
	note B_, 5
	volume_envelope 11, 7
	note B_, 5
	volume_envelope 12, 3
	note Fs, 2
	note Fs, 2
	note B_, 2
	sound_ret

gbs_route37_Ch3:
	gbs_switch 2
	stereo_panning TRUE, FALSE
	note_type 12, 1, 4
gbs_route37_Ch3.loop1:
	octave 2
	note Fs, 2
	rest 6
	sound_loop 4, gbs_route37_Ch3.loop1
gbs_route37_Ch3.mainloop:
	sound_call gbs_route37_Ch3.sub1
	note A_, 2
	octave 3
	note Cs, 2
	octave 2
	note Gs, 2
	note B_, 2
	note Fs, 2
	note A_, 2
	note Fs, 2
	note E_, 2
gbs_route37_Ch3.loop2:
	note Ds, 2
	note Fs, 2
	sound_loop 4, gbs_route37_Ch3.loop2
	sound_call gbs_route37_Ch3.sub1
	sound_call gbs_route37_Ch3.sub1
	note A_, 2
	octave 3
	note Cs, 2
	octave 2
	note Gs, 2
	note B_, 2
	note Fs, 2
	note A_, 2
	octave 3
	note Cs, 2
	octave 2
	note A_, 2
	sound_call gbs_route37_Ch3.sub1
gbs_route37_Ch3.loop3:
	octave 2
	note B_, 2
	octave 3
	note Ds, 2
	sound_loop 4, gbs_route37_Ch3.loop3
gbs_route37_Ch3.loop4:
	octave 2
	note A_, 2
	octave 3
	note Cs, 2
	sound_loop 7, gbs_route37_Ch3.loop4
	note E_, 2
	note Cs, 2
	sound_call gbs_route37_Ch3.sub2
gbs_route37_Ch3.loop5:
	octave 2
	note B_, 2
	octave 3
	note Fs, 2
	sound_loop 4, gbs_route37_Ch3.loop5
gbs_route37_Ch3.loop6:
	octave 2
	note A_, 2
	octave 3
	note Cs, 2
	sound_loop 7, gbs_route37_Ch3.loop6
	note E_, 2
	note Cs, 2
	sound_call gbs_route37_Ch3.sub2
	sound_call gbs_route37_Ch3.sub1
gbs_route37_Ch3.loop7:
	note Fs, 2
	rest 6
	sound_loop 4, gbs_route37_Ch3.loop7
	sound_loop 0, gbs_route37_Ch3.mainloop

gbs_route37_Ch3.sub1:
	octave 2
	note Fs, 2
	note B_, 2
	note Fs, 2
	note B_, 2
	note Fs, 2
	note B_, 2
	note Fs, 2
	note B_, 2
	sound_ret

gbs_route37_Ch3.sub2:
	octave 2
	note B_, 2
	octave 3
	note Ds, 2
	octave 2
	note B_, 2
	octave 3
	note Ds, 2
	octave 2
	note B_, 2
	octave 3
	note Ds, 2
	octave 2
	note B_, 2
	octave 3
	note Ds, 2
	sound_ret

gbs_route37_Ch4:
	gbs_switch 3
	stereo_panning FALSE, TRUE
	toggle_noise 0
gbs_route37_Ch4.mainloop:
	drum_speed 12
	sound_call gbs_route37_Ch4.sub1
	drum_note 3, 1
	drum_note 4, 1
	drum_note 4, 1
	drum_note 3, 1
	sound_call gbs_route37_Ch4.sub1
	drum_speed 6
	drum_note 4, 1
	drum_note 4, 1
	drum_note 4, 1
	drum_note 4, 1
	drum_note 4, 1
	drum_note 3, 1
	drum_note 3, 1
	drum_note 3, 1
	sound_loop 0, gbs_route37_Ch4.mainloop

gbs_route37_Ch4.sub1:
	drum_note 3, 2
	drum_note 4, 1
	drum_note 4, 1
	drum_note 3, 2
	drum_note 4, 1
	drum_note 4, 1
	drum_note 3, 2
	drum_note 4, 1
	drum_note 4, 1
	sound_ret

	.align 4
	.global gbs_route37_Header
gbs_route37_Header:
	.byte 4	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_route37_Ch1
	.int gbs_route37_Ch2
	.int gbs_route37_Ch3
	.int gbs_route37_Ch4
