	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_lookrocket_Ch1:
	gbs_switch 0
	tempo 123
	volume 7, 7
	transpose 0, 2
	stereo_panning FALSE, TRUE
	duty_cycle 3
	vibrato 5, 6, 4
	note_type 12, 10, 8
	octave 4
	note C_, 1
	note D_, 1
	sound_call gbs_lookrocket_Ch1.sub1
	duty_cycle 1
gbs_lookrocket_Ch1.mainloop:
	volume_envelope 10, 8
	sound_call gbs_lookrocket_Ch1.sub2
	sound_call gbs_lookrocket_Ch2.sub5
	octave 4
	note Fs, 1
	rest 1
	volume_envelope 5, 3
	sound_call gbs_lookrocket_Ch1.sub3
	volume_envelope 12, 3
	sound_call gbs_lookrocket_Ch1.sub3
	volume_envelope 14, 3
	sound_call gbs_lookrocket_Ch1.sub3
	rest 16
	sound_loop 0, gbs_lookrocket_Ch1.mainloop

	.global gbs_lookrocket_Ch1.sub1
gbs_lookrocket_Ch1.sub1:
	note Ds, 1
	rest 1
	note D_, 1
	rest 1
	note Cs, 1
	rest 1
	note C_, 1
	rest 3
	octave 2
	note F_, 1
	note Gs, 1
	note B_, 1
	octave 3
	note D_, 1
	note F_, 1
	note Gs, 1
	sound_ret

	.global gbs_lookrocket_Ch1.sub2
gbs_lookrocket_Ch1.sub2:
	rest 2
	octave 3
	note Ds, 1
	rest 5
	note Ds, 4
	octave 2
	note A_, 2
	octave 3
	note Ds, 1
	note F_, 1
	note Fs, 6
	note Ds, 1
	rest 3
	note Fs, 1
	rest 1
	note Ds, 1
	rest 1
	octave 4
	note Fs, 1
	rest 1
	sound_ret

	.global gbs_lookrocket_Ch1.sub3
gbs_lookrocket_Ch1.sub3:
	rest 2
	octave 2
	note B_, 1
	rest 7
	octave 3
	note C_, 1
	rest 5
	sound_ret

gbs_lookrocket_Ch2:
	gbs_switch 1
	transpose 0, 2
	vibrato 4, 6, 4
	duty_cycle 3
	note_type 12, 11, 7
	stereo_panning TRUE, TRUE
	octave 5
	note C_, 1
	note D_, 1
	sound_call gbs_lookrocket_Ch2.sub1
gbs_lookrocket_Ch2.mainloop:
	volume_envelope 11, 7
	sound_call gbs_lookrocket_Ch2.sub5
	octave 5
	note C_, 1
	rest 1
	sound_call gbs_lookrocket_Ch2.sub2
	volume_envelope 5, 3
	sound_call gbs_lookrocket_Ch2.sub3
	volume_envelope 12, 3
	sound_call gbs_lookrocket_Ch2.sub3
	volume_envelope 14, 3
	sound_call gbs_lookrocket_Ch2.sub3
	sound_call gbs_lookrocket_Ch2.sub4
	sound_loop 0, gbs_lookrocket_Ch2.mainloop

	.global gbs_lookrocket_Ch2.sub1
gbs_lookrocket_Ch2.sub1:
	note Ds, 1
	rest 1
	note D_, 1
	rest 1
	note Cs, 1
	rest 1
	note C_, 1
	rest 3
	octave 3
	note B_, 6
	duty_cycle 0
	sound_ret

	.global gbs_lookrocket_Ch2.sub2
gbs_lookrocket_Ch2.sub2:
	rest 2
	octave 4
	note Ds, 1
	rest 5
	note F_, 4
	note C_, 1
	note D_, 1
	note Ds, 1
	note F_, 1
	note Fs, 6
	note Ds, 1
	rest 3
	note Fs, 1
	rest 1
	note Ds, 1
	rest 1
	octave 5
	note Ds, 1
	rest 1
	sound_ret

	.global gbs_lookrocket_Ch2.sub3
gbs_lookrocket_Ch2.sub3:
	rest 2
	octave 3
	note F_, 1
	rest 7
	note Fs, 1
	rest 5
	sound_ret

	.global gbs_lookrocket_Ch2.sub4
gbs_lookrocket_Ch2.sub4:
	volume_envelope 6, 3
	note Gs, 1
	note F_, 1
	note D_, 1
	octave 2
	note B_, 1
	volume_envelope 10, 3
	octave 3
	note A_, 1
	note Fs, 1
	note Ds, 1
	note C_, 1
	volume_envelope 12, 3
	note As, 1
	note G_, 1
	note E_, 1
	note Cs, 1
	volume_envelope 15, 3
	note B_, 1
	note Gs, 1
	note F_, 1
	note D_, 1
	sound_ret

	.global gbs_lookrocket_Ch2.sub5
gbs_lookrocket_Ch2.sub5:
	octave 3
	rest 2
	note G_, 1
	rest 5
	note A_, 8
	note As, 6
	note A_, 1
	rest 3
	note As, 1
	rest 1
	note A_, 1
	rest 1
	sound_ret

gbs_lookrocket_Ch3:
	gbs_switch 2
	transpose 0, 2
	vibrato 4, 2, 2
	note_type 12, 1, 4
	stereo_panning TRUE, FALSE
	rest 2
	sound_call gbs_lookrocket_Ch3.sub1
gbs_lookrocket_Ch3.mainloop:
	sound_call gbs_lookrocket_Ch3.sub4
	sound_call gbs_lookrocket_Ch3.sub4
	volume_envelope 2, 4
	sound_call gbs_lookrocket_Ch3.sub5
	volume_envelope 1, 4
	sound_call gbs_lookrocket_Ch3.sub2
	sound_call gbs_lookrocket_Ch3.sub5
	sound_call gbs_lookrocket_Ch3.sub3
	sound_loop 0, gbs_lookrocket_Ch3.mainloop

	.global gbs_lookrocket_Ch3.sub1
gbs_lookrocket_Ch3.sub1:
	octave 3
	note F_, 1
	rest 1
	note Gs, 1
	rest 1
	octave 4
	note C_, 1
	rest 1
	note D_, 1
	rest 3
	octave 3
	note D_, 6
	sound_ret

	.global gbs_lookrocket_Ch3.sub2
gbs_lookrocket_Ch3.sub2:
	octave 2
	note Gs, 1
	rest 1
	octave 3
	note Gs, 1
	rest 1
	octave 2
	note Gs, 1
	rest 1
	note Gs, 1
	rest 1
	note A_, 1
	rest 1
	octave 3
	note A_, 1
	rest 1
	note C_, 1
	rest 1
	note Fs, 1
	rest 1
	sound_ret

	.global gbs_lookrocket_Ch3.sub3
gbs_lookrocket_Ch3.sub3:
	volume_envelope 2, 4
	octave 2
	note Gs, 1
	rest 1
	octave 3
	note F_, 1
	rest 1
	octave 2
	note A_, 1
	rest 1
	octave 3
	note Fs, 1
	rest 1
	volume_envelope 1, 4
	octave 2
	note As, 1
	rest 1
	octave 3
	note G_, 1
	rest 1
	octave 2
	note B_, 1
	rest 1
	octave 3
	note Gs, 1
	rest 1
	sound_ret

	.global gbs_lookrocket_Ch3.sub4
gbs_lookrocket_Ch3.sub4:
	note C_, 1
	rest 1
	octave 4
	note C_, 1
	rest 1
	octave 3
	note C_, 1
	rest 1
	note C_, 1
	rest 1
	octave 4
	note C_, 1
	rest 1
	octave 3
	note C_, 1
	rest 1
	note Ds, 1
	rest 1
	note G_, 1
	rest 1
	note C_, 1
	rest 1
	note C_, 1
	rest 1
	note C_, 1
	rest 1
	note C_, 1
	rest 1
	note C_, 1
	rest 1
	note C_, 1
	rest 1
	note Fs, 1
	rest 1
	note A_, 1
	rest 1
	sound_ret

	.global gbs_lookrocket_Ch3.sub5
gbs_lookrocket_Ch3.sub5:
	octave 2
	note Gs, 1
	rest 1
	octave 3
	note Gs, 1
	rest 1
	octave 2
	note Gs, 1
	rest 1
	note Gs, 1
	rest 1
	note A_, 1
	rest 1
	octave 3
	note A_, 1
	rest 1
	note Gs, 1
	note Fs, 1
	note Ds, 1
	note C_, 1
	sound_ret

gbs_lookrocket_Ch4:
	gbs_switch 3
	toggle_noise 3
	drum_speed 12
	rest 2
	sound_call gbs_lookrocket_Ch4.sub1
gbs_lookrocket_Ch4.mainloop:
	sound_call gbs_lookrocket_Ch4.sub2
	sound_call gbs_lookrocket_Ch4.sub2
	sound_call gbs_lookrocket_Ch4.sub2
	sound_call gbs_lookrocket_Ch4.sub2
	sound_call gbs_lookrocket_Ch4.sub2
	sound_call gbs_lookrocket_Ch4.sub2
	sound_call gbs_lookrocket_Ch4.sub2
	sound_call gbs_lookrocket_Ch4.sub1
	sound_loop 0, gbs_lookrocket_Ch4.mainloop

	.global gbs_lookrocket_Ch4.sub1
gbs_lookrocket_Ch4.sub1:
	drum_note 1, 8
	drum_note 3, 2
	drum_note 4, 2
	drum_note 2, 1
	drum_note 2, 1
	drum_note 3, 1
	drum_note 3, 1
	sound_ret

	.global gbs_lookrocket_Ch4.sub2
gbs_lookrocket_Ch4.sub2:
	drum_note 4, 2
	drum_note 7, 2
	drum_note 3, 2
	drum_note 7, 2
	drum_note 4, 2
	drum_note 7, 2
	drum_note 3, 2
	drum_note 7, 2
	sound_ret

	.align 4
	.global gbs_lookrocket_Header
gbs_lookrocket_Header:
	.byte 4	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_lookrocket_Ch1
	.int gbs_lookrocket_Ch2
	.int gbs_lookrocket_Ch3
	.int gbs_lookrocket_Ch4
