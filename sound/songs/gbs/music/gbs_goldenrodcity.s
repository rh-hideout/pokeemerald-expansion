	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_goldenrodcity_Ch1:
	gbs_switch 0
	stereo_panning FALSE, TRUE
	tempo 176
	volume 7, 7
	note_type 12, 9, 7
	rest 16
	rest 16
	rest 16
	rest 16
gbs_goldenrodcity_Ch1.mainloop:
	duty_cycle 0
	sound_call gbs_goldenrodcity_Ch1.sub1
	octave 3
	note Gs, 1
	octave 4
	note C_, 1
	note Ds, 1
	note Fs, 1
	note Ds, 1
	note Fs, 1
	note Gs, 1
	octave 5
	note C_, 1
	volume_envelope 7, 1
	duty_cycle 0
	sound_call gbs_goldenrodcity_Ch1.sub2
	volume_envelope 7, 7
	note Ds, 2
	note F_, 2
	note Fs, 2
	note Gs, 4
	volume_envelope 7, 1
	sound_call gbs_goldenrodcity_Ch1.sub2
	note Ds, 1
	note Fs, 1
	volume_envelope 7, 7
	octave 5
	note C_, 2
	octave 4
	note Gs, 2
	note Fs, 2
	note Ds, 2
	duty_cycle 2
	volume_envelope 9, 7
	sound_call gbs_goldenrodcity_Ch1.sub1
	note C_, 4
	octave 3
	note Gs, 2
	octave 4
	note C_, 2
	sound_loop 0, gbs_goldenrodcity_Ch1.mainloop

gbs_goldenrodcity_Ch1.sub1:
	octave 4
	note Cs, 2
	octave 3
	note Gs, 1
	rest 3
	note Gs, 1
	rest 1
	octave 4
	note C_, 2
	octave 3
	note Gs, 1
	rest 3
	note Gs, 1
	rest 1
	note As, 2
	note F_, 1
	rest 1
	note Cs, 2
	note F_, 1
	rest 1
	note Ds, 2
	note C_, 2
	note Cs, 2
	note Ds, 2
	note Fs, 2
	note Cs, 1
	rest 3
	note Cs, 1
	rest 1
	note Fs, 2
	note Cs, 1
	rest 1
	note Fs, 2
	note As, 2
	note Cs, 2
	note Ds, 2
	note Gs, 2
	octave 4
	note Cs, 2
	sound_ret

gbs_goldenrodcity_Ch1.sub2:
	octave 4
	note F_, 1
	note Cs, 1
	octave 3
	note Gs, 1
	octave 4
	note Cs, 1
	note F_, 1
	note Gs, 1
	note F_, 1
	note Gs, 1
	note Cs, 1
	octave 3
	note Gs, 1
	note F_, 1
	note Gs, 1
	octave 4
	note Cs, 1
	note F_, 1
	note Cs, 1
	note F_, 1
	note Ds, 1
	note C_, 1
	octave 3
	note Gs, 1
	octave 4
	note C_, 1
	note Ds, 1
	note Fs, 1
	note Ds, 1
	note Fs, 1
	note C_, 1
	octave 3
	note Gs, 1
	note Fs, 1
	note Gs, 1
	octave 4
	note C_, 1
	note Ds, 1
	note C_, 1
	note Ds, 1
	note Cs, 1
	octave 3
	note As, 1
	note Fs, 1
	note As, 1
	octave 4
	note Cs, 1
	note F_, 1
	note Cs, 1
	note F_, 1
	octave 3
	note As, 1
	note Fs, 1
	note Cs, 1
	note Fs, 1
	note As, 1
	octave 4
	note Cs, 1
	octave 3
	note As, 1
	octave 4
	note Cs, 1
	note Ds, 1
	note C_, 1
	octave 3
	note Gs, 1
	octave 4
	note C_, 1
	note Ds, 1
	note Fs, 1
	sound_ret

gbs_goldenrodcity_Ch2:
	gbs_switch 1
	stereo_panning TRUE, FALSE
	vibrato 18, 2, 3
	duty_cycle 2
	note_type 12, 9, 7
gbs_goldenrodcity_Ch2.mainloop:
	volume_envelope 9, 7
	sound_call gbs_goldenrodcity_Ch2.sub1
	octave 4
	note F_, 2
	note Fs, 2
	note Gs, 2
	note F_, 2
	note Ds, 8
	sound_call gbs_goldenrodcity_Ch2.sub1
	note Gs, 2
	note As, 2
	octave 5
	note C_, 2
	note Cs, 2
	note Ds, 8
	duty_cycle 2
	volume_envelope 7, 7
	sound_call gbs_goldenrodcity_Ch2.sub2
	octave 4
	note Gs, 2
	note As, 2
	note B_, 2
	octave 5
	note C_, 4
	duty_cycle 3
	volume_envelope 7, 7
	sound_call gbs_goldenrodcity_Ch2.sub2
	note F_, 2
	note Ds, 2
	note Cs, 2
	note C_, 2
	octave 4
	note Gs, 2
	sound_loop 0, gbs_goldenrodcity_Ch2.mainloop

gbs_goldenrodcity_Ch2.sub1:
	octave 4
	note F_, 4
	note Cs, 4
	note Ds, 4
	note C_, 4
	note Cs, 2
	note C_, 2
	octave 3
	note As, 2
	octave 4
	note C_, 2
	octave 3
	note Gs, 6
	octave 3
	note Gs, 1
	octave 3
	note A_, 1
	note As, 4
	octave 4
	note Cs, 4
	octave 3
	note As, 2
	octave 4
	note As, 2
	note Gs, 2
	note Fs, 2
	duty_cycle 1
	sound_ret

gbs_goldenrodcity_Ch2.sub2:
	note Cs, 6
	note F_, 6
	note Cs, 4
	note C_, 6
	note Ds, 6
	note C_, 2
	octave 4
	note Gs, 1
	note A_, 1
	note As, 6
	octave 5
	note Cs, 6
	octave 4
	note As, 4
	octave 5
	note C_, 4
	note Ds, 2
	sound_ret

gbs_goldenrodcity_Ch3:
	gbs_switch 2
	stereo_panning TRUE, TRUE
	vibrato 8, 2, 3
	note_type 12, 2, 5
gbs_goldenrodcity_Ch3.mainloop:
	sound_call gbs_goldenrodcity_Ch3.sub1
	sound_call gbs_goldenrodcity_Ch3.sub1
	sound_call gbs_goldenrodcity_Ch3.sub2
	rest 3
	octave 3
	note C_, 1
	note Ds, 1
	note G_, 1
	note Gs, 1
	note Ds, 2
	sound_call gbs_goldenrodcity_Ch3.sub2
	rest 1
	octave 3
	note Gs, 2
	note Fs, 2
	note Ds, 2
	octave 2
	note Gs, 2
	sound_loop 0, gbs_goldenrodcity_Ch3.mainloop

gbs_goldenrodcity_Ch3.sub1:
	octave 3
	note Cs, 4
	rest 2
	note Cs, 1
	rest 1
	note C_, 4
	rest 2
	note C_, 1
	rest 1
	octave 2
	note As, 4
	rest 2
	note As, 1
	rest 1
	note Gs, 4
	rest 2
	note Gs, 1
	rest 1
	note Fs, 4
	rest 2
	note Fs, 1
	rest 1
	octave 3
	note Ds, 4
	rest 2
	note Ds, 1
	rest 1
	note Gs, 4
	rest 2
	note Gs, 1
	rest 1
	octave 2
	note Gs, 1
	rest 1
	note Gs, 3
	rest 1
	octave 3
	note Gs, 1
	rest 1
	sound_ret

gbs_goldenrodcity_Ch3.sub2:
	note Cs, 1
	rest 1
	octave 4
	note Cs, 1
	octave 3
	note Cs, 1
	rest 2
	note Cs, 1
	rest 5
	octave 4
	note C_, 1
	note Cs, 1
	octave 3
	note Gs, 2
	note C_, 1
	rest 1
	octave 4
	note C_, 1
	octave 3
	note C_, 1
	rest 2
	note C_, 1
	rest 5
	note B_, 1
	octave 4
	note C_, 1
	octave 3
	note Gs, 2
	octave 2
	note As, 1
	rest 1
	octave 3
	note As, 1
	octave 2
	note As, 1
	rest 2
	note As, 1
	rest 5
	octave 3
	note A_, 1
	note As, 1
	note Fs, 2
	octave 2
	note Gs, 1
	rest 1
	octave 3
	note Gs, 1
	octave 2
	note Gs, 1
	rest 2
	note Gs, 1
	sound_ret

gbs_goldenrodcity_Ch4:
	gbs_switch 3
	toggle_noise 3
	drum_speed 12
	rest 16
	rest 16
	rest 16
	rest 8
	drum_note 3, 2
	drum_note 7, 2
	drum_note 3, 1
	drum_note 3, 1
	drum_note 7, 2
gbs_goldenrodcity_Ch4.mainloop:
gbs_goldenrodcity_Ch4.loop1:
	drum_note 4, 2
	drum_note 7, 2
	drum_note 3, 2
	drum_note 7, 2
	drum_note 4, 2
	drum_note 7, 2
	drum_note 3, 2
	drum_note 7, 2
	sound_loop 3, gbs_goldenrodcity_Ch4.loop1
	sound_call gbs_goldenrodcity_Ch4.sub1
	sound_call gbs_goldenrodcity_Ch4.sub2
	drum_note 8, 1
	drum_note 8, 1
	drum_note 7, 2
	sound_call gbs_goldenrodcity_Ch4.sub2
	drum_note 3, 2
	drum_note 7, 2
	sound_call gbs_goldenrodcity_Ch4.sub2
	drum_note 3, 1
	drum_note 3, 1
	drum_note 7, 2
	sound_call gbs_goldenrodcity_Ch4.sub2
	drum_note 3, 2
	drum_note 3, 1
	drum_note 3, 1
	sound_call gbs_goldenrodcity_Ch4.sub2
	drum_note 8, 1
	drum_note 8, 1
	drum_note 7, 2
	sound_call gbs_goldenrodcity_Ch4.sub2
	drum_note 3, 2
	drum_note 7, 2
	sound_call gbs_goldenrodcity_Ch4.sub2
	drum_note 3, 1
	drum_note 3, 1
	drum_note 7, 2
	sound_call gbs_goldenrodcity_Ch4.sub2
	drum_note 3, 2
	drum_note 3, 1
	drum_note 3, 1
gbs_goldenrodcity_Ch4.loop2:
	drum_note 4, 2
	drum_note 7, 2
	drum_note 3, 2
	drum_note 7, 2
	drum_note 4, 2
	drum_note 7, 2
	drum_note 3, 2
	drum_note 7, 2
	sound_loop 3, gbs_goldenrodcity_Ch4.loop2
	sound_call gbs_goldenrodcity_Ch4.sub1
	sound_loop 0, gbs_goldenrodcity_Ch4.mainloop

gbs_goldenrodcity_Ch4.sub1:
	drum_note 4, 2
	drum_note 7, 2
	drum_note 3, 2
	drum_note 7, 2
	drum_note 4, 2
	drum_note 7, 2
	drum_note 3, 1
	drum_note 3, 1
	drum_note 7, 2
	sound_ret

gbs_goldenrodcity_Ch4.sub2:
	drum_note 4, 2
	drum_note 3, 1
	drum_note 4, 3
	drum_note 4, 2
	drum_note 8, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 8, 1
	sound_ret

	.align 4
	.global gbs_goldenrodcity_Header
gbs_goldenrodcity_Header:
	.byte 4	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_goldenrodcity_Ch1
	.int gbs_goldenrodcity_Ch2
	.int gbs_goldenrodcity_Ch3
	.int gbs_goldenrodcity_Ch4
