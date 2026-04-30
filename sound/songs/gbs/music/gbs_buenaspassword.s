	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_buenaspassword_Ch1:
	gbs_switch 0
	tempo 136
	volume 7, 7
	pitch_offset 1
	note_type 12, 11, 3
	rest 8
gbs_buenaspassword_Ch1.mainloop:
	stereo_panning TRUE, TRUE
	rest 16
	rest 16
	duty_cycle 3
	note_type 6, 9, 7
	stereo_panning FALSE, TRUE
	octave 4
	note Gs, 1
	rest 1
	note Gs, 1
	rest 1
	note Fs, 2
	note Gs, 2
	rest 10
	rest 10
	stereo_panning TRUE, FALSE
	note Cs, 2
	note F_, 2
	note Gs, 1
	rest 1
	note Gs, 1
	rest 1
	note Fs, 2
	note Gs, 2
	rest 12
	duty_cycle 2
	sound_call gbs_buenaspassword_Ch1.sub1
	stereo_panning TRUE, TRUE
	sound_call gbs_buenaspassword_Ch2.sub3
	sound_call gbs_buenaspassword_Ch1.sub2
	sound_call gbs_buenaspassword_Ch1.sub1
	stereo_panning TRUE, TRUE
	sound_call gbs_buenaspassword_Ch2.sub3
	sound_call gbs_buenaspassword_Ch1.sub2
	sound_call gbs_buenaspassword_Ch1.sub1
	duty_cycle 1
	note Cs, 2
	rest 2
	note Ds, 2
	rest 2
	note Fs, 2
	rest 1
	note Gs, 2
	rest 1
	note As, 2
	note B_, 1
	rest 1
	octave 4
	note Cs, 1
	rest 1
	note Ds, 1
	rest 1
	octave 3
	note B_, 2
	rest 2
	note B_, 2
	note Gs, 2
	note B_, 2
	note As, 2
	note Gs, 2
	note G_, 1
	note Ds, 3
	note Cs, 2
	octave 2
	note B_, 2
	note As, 1
	note Gs, 3
	note As, 2
	note G_, 2
	note As, 1
	octave 3
	note Cs, 3
	note Ds, 2
	note Cs, 2
	note Ds, 1
	note G_, 3
	note B_, 2
	rest 2
	note As, 2
	rest 2
	note Gs, 2
	rest 1
	note Fs, 2
	rest 1
	note Ds, 2
	note Cs, 1
	rest 1
	note Ds, 1
	rest 1
	note F_, 1
	rest 1
	note Cs, 2
	rest 2
	note Gs, 2
	octave 4
	note Cs, 2
	note F_, 2
	note Gs, 1
	rest 1
	note Ds, 1
	rest 1
	note Gs, 1
	note Fs, 3
	note F_, 1
	rest 1
	note Ds, 1
	rest 1
	octave 3
	note B_, 1
	note Gs, 3
	note Fs, 1
	rest 1
	note Ds, 1
	rest 1
	note Gs, 1
	note Ds, 2
	note Fs, 1
	note Gs, 1
	rest 1
	note Ds, 1
	rest 1
	note Fs, 1
	rest 1
	note G_, 1
	rest 1
	sound_loop 0, gbs_buenaspassword_Ch1.mainloop

gbs_buenaspassword_Ch1.sub1:
	stereo_panning FALSE, TRUE
	note_type 6, 8, 4
	octave 4
	note Ds, 2
	volume_envelope 7, 1
	note Cs, 1
	note C_, 1
	volume_envelope 5, 1
	octave 3
	note As, 1
	note Gs, 1
	volume_envelope 3, 1
	note G_, 1
	note F_, 1
	volume_envelope 1, 1
	note Ds, 1
	note Cs, 1
	note C_, 1
	rest 1
	note_type 12, 8, 4
	sound_ret

gbs_buenaspassword_Ch1.sub2:
	octave 3
	note Ds, 1
	rest 1
	octave 2
	note Gs, 1
	rest 1
	octave 3
	note Ds, 1
	octave 2
	note Gs, 1
	rest 1
	octave 3
	note Ds, 1
	rest 2
	sound_ret

gbs_buenaspassword_Ch2:
	gbs_switch 1
	vibrato 18, 3, 4
	duty_cycle 2
	note_type 12, 10, 5
	rest 7
	octave 3
	note Fs, 1
gbs_buenaspassword_Ch2.mainloop:
	stereo_panning TRUE, TRUE
	sound_call gbs_buenaspassword_Ch2.sub3
	sound_call gbs_buenaspassword_Ch2.sub1
	stereo_panning TRUE, TRUE
	sound_call gbs_buenaspassword_Ch2.sub2
	octave 3
	note B_, 2
	note As, 2
	note B_, 2
	note Gs, 16
	sound_call gbs_buenaspassword_Ch2.sub1
	stereo_panning TRUE, TRUE
	sound_call gbs_buenaspassword_Ch2.sub2
	note B_, 2
	note As, 2
	note B_, 2
	note Gs, 16
	sound_call gbs_buenaspassword_Ch2.sub1
	note Fs, 2
	rest 2
	note Gs, 2
	rest 2
	note As, 2
	rest 1
	note B_, 2
	rest 1
	octave 4
	note Cs, 2
	note Ds, 1
	rest 1
	note F_, 1
	rest 1
	note Fs, 1
	rest 1
	note Ds, 2
	rest 2
	note Gs, 2
	note Fs, 2
	note Gs, 2
	note Ds, 14
	note Cs, 1
	note Ds, 1
	note Cs, 6
	octave 3
	note B_, 1
	octave 4
	note Cs, 1
	note Ds, 8
	note Fs, 2
	rest 2
	note F_, 2
	rest 2
	note Ds, 2
	rest 1
	note Cs, 2
	rest 1
	octave 3
	note B_, 2
	note Gs, 1
	rest 1
	note As, 1
	rest 1
	note B_, 1
	rest 1
	note Gs, 2
	rest 2
	octave 4
	note Cs, 2
	note F_, 2
	note Gs, 2
	note B_, 14
	note As, 1
	note B_, 1
	note Gs, 10
	volume_envelope 8, 4
	octave 2
	note Ds, 1
	rest 1
	note Fs, 1
	rest 1
	note G_, 1
	rest 1
	volume_envelope 10, 5
	sound_loop 0, gbs_buenaspassword_Ch2.mainloop

gbs_buenaspassword_Ch2.sub1:
	octave 3
	note Gs, 1
	rest 1
	note Ds, 1
	rest 1
	note Fs, 1
	note Ds, 1
	rest 1
	note Fs, 1
	rest 2
	stereo_panning TRUE, FALSE
	octave 4
	note Gs, 1
	note_type 6, 8, 1
	note G_, 1
	note F_, 1
	volume_envelope 7, 1
	note Ds, 1
	note Cs, 1
	volume_envelope 6, 1
	note C_, 1
	octave 3
	note As, 1
	volume_envelope 4, 1
	note Gs, 1
	volume_envelope 2, 1
	note G_, 1
	note F_, 1
	rest 1
	note_type 12, 10, 5
	sound_ret

gbs_buenaspassword_Ch2.sub2:
	octave 4
	note Gs, 2
	rest 2
	note Fs, 2
	rest 2
	note F_, 2
	rest 1
	note Ds, 2
	rest 1
	note Cs, 2
	note Ds, 1
	rest 1
	note Ds, 1
	rest 1
	note Cs, 1
	rest 1
	note Ds, 2
	rest 2
	sound_ret

gbs_buenaspassword_Ch2.sub3:
	octave 3
	note Gs, 1
	rest 1
	note Ds, 1
	rest 1
	note Fs, 1
	note Ds, 1
	rest 1
	note Fs, 1
	note F_, 1
	rest 1
	note Cs, 1
	rest 1
	octave 2
	note B_, 1
	note Gs, 3
	octave 3
	note Gs, 1
	rest 1
	note Ds, 1
	rest 1
	note Fs, 1
	note Ds, 1
	rest 1
	note Fs, 1
	note F_, 1
	rest 1
	note Cs, 1
	rest 1
	octave 2
	note B_, 1
	note Gs, 2
	octave 3
	note Fs, 1
	note Gs, 1
	rest 1
	note Ds, 1
	rest 1
	note Fs, 1
	note Ds, 1
	rest 1
	note Fs, 1
	note F_, 1
	rest 1
	note Cs, 1
	rest 1
	octave 2
	note B_, 1
	note Gs, 3
	sound_ret

gbs_buenaspassword_Ch3:
	gbs_switch 2
	note_type 12, 1, 4
	rest 8
gbs_buenaspassword_Ch3.mainloop:
gbs_buenaspassword_Ch3.loop1:
	sound_call gbs_buenaspassword_Ch3.sub1
	sound_call gbs_buenaspassword_Ch3.sub1
	sound_call gbs_buenaspassword_Ch3.sub1
	octave 2
	note Gs, 1
	rest 1
	octave 3
	note Fs, 1
	rest 1
	octave 2
	note Gs, 1
	octave 3
	note Ds, 2
	octave 2
	note Gs, 1
	rest 2
	note B_, 1
	rest 1
	note Gs, 4
	sound_loop 3, gbs_buenaspassword_Ch3.loop1
	note Fs, 1
	rest 1
	note As, 1
	rest 1
	octave 3
	note Cs, 1
	octave 2
	note Fs, 1
	rest 1
	octave 3
	note Cs, 1
	octave 2
	note Fs, 1
	rest 1
	note As, 2
	octave 3
	note Cs, 1
	rest 1
	octave 2
	note Fs, 2
	note Gs, 1
	rest 1
	note Gs, 1
	rest 1
	note B_, 1
	note Gs, 1
	rest 1
	octave 3
	note Ds, 1
	octave 2
	note Gs, 1
	rest 1
	octave 3
	note Gs, 2
	octave 2
	note Gs, 1
	rest 1
	octave 3
	note Ds, 2
	octave 2
	note Ds, 1
	rest 1
	note Ds, 1
	rest 1
	note Gs, 1
	note Ds, 1
	rest 1
	note As, 1
	note Ds, 1
	rest 1
	note Gs, 2
	note As, 1
	rest 1
	note Ds, 1
	rest 1
	note Ds, 1
	rest 1
	note Ds, 1
	rest 1
	note G_, 1
	note Ds, 1
	rest 1
	note As, 1
	note Ds, 1
	rest 1
	octave 3
	note Ds, 2
	octave 2
	note Ds, 1
	rest 1
	note G_, 2
	sound_call gbs_buenaspassword_Ch3.sub2
	octave 3
	note Cs, 1
	rest 1
	note Cs, 1
	rest 1
	note F_, 1
	note Cs, 1
	rest 1
	note Gs, 1
	octave 2
	note Gs, 1
	rest 1
	octave 3
	note F_, 2
	octave 2
	note Gs, 1
	rest 1
	octave 3
	note Cs, 2
	sound_call gbs_buenaspassword_Ch3.sub2
	note Gs, 1
	rest 1
	note Gs, 1
	rest 1
	note B_, 1
	note Gs, 2
	octave 3
	note Ds, 1
	octave 2
	note Gs, 1
	rest 1
	note Ds, 1
	rest 1
	note Fs, 1
	rest 1
	note G_, 1
	rest 1
	sound_loop 0, gbs_buenaspassword_Ch3.mainloop

gbs_buenaspassword_Ch3.sub1:
	octave 2
	note Gs, 1
	rest 1
	octave 3
	note Fs, 1
	rest 1
	octave 2
	note Gs, 1
	octave 3
	note Ds, 2
	octave 2
	note Gs, 1
	octave 3
	note Cs, 1
	rest 1
	note B_, 1
	rest 1
	note Cs, 1
	note F_, 2
	note Cs, 1
	sound_ret

gbs_buenaspassword_Ch3.sub2:
	octave 2
	note Gs, 1
	rest 1
	note Gs, 1
	rest 1
	note B_, 1
	note Gs, 1
	rest 1
	octave 3
	note Ds, 1
	octave 2
	note Gs, 1
	rest 1
	note B_, 2
	octave 3
	note Ds, 1
	rest 1
	octave 2
	note Gs, 2
	sound_ret

gbs_buenaspassword_Ch4:
	gbs_switch 3
	toggle_noise 3
	drum_speed 12
	drum_note 4, 2
	drum_note 3, 2
	drum_note 3, 2
	drum_note 3, 1
	drum_note 3, 1
gbs_buenaspassword_Ch4.mainloop:
gbs_buenaspassword_Ch4.loop1:
	sound_call gbs_buenaspassword_Ch4.sub1
	sound_call gbs_buenaspassword_Ch4.sub1
	sound_call gbs_buenaspassword_Ch4.sub1
	sound_call gbs_buenaspassword_Ch4.sub2
	sound_loop 4, gbs_buenaspassword_Ch4.loop1
	sound_call gbs_buenaspassword_Ch4.sub1
	sound_call gbs_buenaspassword_Ch4.sub1
	sound_call gbs_buenaspassword_Ch4.sub1
	stereo_panning TRUE, TRUE
	drum_note 4, 2
	stereo_panning TRUE, FALSE
	drum_note 8, 2
	stereo_panning TRUE, TRUE
	drum_note 3, 2
	stereo_panning FALSE, TRUE
	drum_note 8, 1
	drum_note 8, 1
	stereo_panning TRUE, FALSE
	drum_note 8, 2
	stereo_panning TRUE, TRUE
	drum_note 3, 2
	drum_note 3, 2
	drum_note 3, 1
	drum_note 3, 1
	sound_loop 0, gbs_buenaspassword_Ch4.mainloop

gbs_buenaspassword_Ch4.sub1:
	stereo_panning TRUE, TRUE
	drum_note 4, 2
	stereo_panning TRUE, FALSE
	drum_note 8, 2
	stereo_panning TRUE, TRUE
	drum_note 3, 2
	stereo_panning FALSE, TRUE
	drum_note 8, 1
	drum_note 8, 1
	stereo_panning TRUE, FALSE
	drum_note 8, 2
	stereo_panning TRUE, TRUE
	drum_note 4, 2
	drum_note 3, 2
	stereo_panning FALSE, TRUE
	drum_note 8, 2
	sound_ret

gbs_buenaspassword_Ch4.sub2:
	stereo_panning TRUE, TRUE
	drum_note 4, 2
	stereo_panning TRUE, FALSE
	drum_note 8, 2
	stereo_panning TRUE, TRUE
	drum_note 3, 2
	stereo_panning FALSE, TRUE
	drum_note 8, 1
	drum_note 8, 1
	stereo_panning TRUE, FALSE
	drum_note 8, 2
	stereo_panning TRUE, TRUE
	drum_note 4, 2
	drum_note 3, 2
	drum_note 3, 1
	drum_note 3, 1
	sound_ret

	.align 4
	.global gbs_buenaspassword_Header
gbs_buenaspassword_Header:
	.byte 4	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_buenaspassword_Ch1
	.int gbs_buenaspassword_Ch2
	.int gbs_buenaspassword_Ch3
	.int gbs_buenaspassword_Ch4
