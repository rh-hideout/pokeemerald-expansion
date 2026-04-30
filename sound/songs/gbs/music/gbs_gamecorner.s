	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_gamecorner_Ch1:
	gbs_switch 0
	tempo 147
	volume 7, 7
	stereo_panning FALSE, TRUE
	note_type 12, 9, 1
	rest 8
gbs_gamecorner_Ch1.mainloop:
	volume_envelope 9, 1
	rest 16
	rest 16
	rest 16
	rest 16
	sound_call gbs_gamecorner_Ch1.sub1
	sound_call gbs_gamecorner_Ch1.sub1
	sound_call gbs_gamecorner_Ch1.sub1
	sound_call gbs_gamecorner_Ch1.sub2
	rest 16
	rest 16
	rest 16
	rest 16
	rest 16
	sound_call gbs_gamecorner_Ch1.sub1
	sound_call gbs_gamecorner_Ch1.sub1
	sound_call gbs_gamecorner_Ch1.sub1
	sound_call gbs_gamecorner_Ch1.sub2
	octave 3
	rest 2
	note Gs, 3
	note Gs, 3
	note As, 2
	note As, 2
	note Gs, 2
	note G_, 2
	volume_envelope 7, 1
gbs_gamecorner_Ch1.loop1:
	octave 4
	note Gs, 1
	octave 5
	note C_, 1
	note F_, 1
	note C_, 1
	sound_loop 4, gbs_gamecorner_Ch1.loop1
gbs_gamecorner_Ch1.loop2:
	octave 4
	note As, 1
	octave 5
	note D_, 1
	note G_, 1
	note D_, 1
	sound_loop 4, gbs_gamecorner_Ch1.loop2
gbs_gamecorner_Ch1.loop3:
	octave 4
	note Ds, 1
	note G_, 1
	octave 5
	note C_, 1
	octave 4
	note G_, 1
	sound_loop 4, gbs_gamecorner_Ch1.loop3
gbs_gamecorner_Ch1.loop4:
	octave 4
	note F_, 1
	note A_, 1
	octave 5
	note C_, 1
	octave 4
	note A_, 1
	sound_loop 4, gbs_gamecorner_Ch1.loop4
gbs_gamecorner_Ch1.loop5:
	octave 4
	note Gs, 1
	octave 5
	note C_, 1
	note F_, 1
	note C_, 1
	sound_loop 4, gbs_gamecorner_Ch1.loop5
gbs_gamecorner_Ch1.loop6:
	octave 4
	note As, 1
	octave 5
	note D_, 1
	note G_, 1
	note D_, 1
	sound_loop 4, gbs_gamecorner_Ch1.loop6
gbs_gamecorner_Ch1.loop7:
	octave 4
	note B_, 1
	octave 5
	note D_, 1
	note G_, 1
	note D_, 1
	sound_loop 4, gbs_gamecorner_Ch1.loop7
	octave 3
	note D_, 1
	note D_, 1
	note D_, 3
	note F_, 2
	note F_, 9
	sound_loop 0, gbs_gamecorner_Ch1.mainloop

gbs_gamecorner_Ch1.sub1:
	rest 2
	octave 4
	note As, 3
	note G_, 3
	note Ds, 3
	octave 3
	note F_, 3
	note F_, 2
	rest 2
	note Gs, 3
	note Gs, 3
	note As, 2
	note As, 2
	note Gs, 1
	note As, 3
	sound_ret

gbs_gamecorner_Ch1.sub2:
	rest 2
	octave 4
	note As, 3
	note G_, 3
	note Ds, 3
	octave 3
	note F_, 3
	note F_, 2
	sound_ret

gbs_gamecorner_Ch2:
	gbs_switch 1
	stereo_panning TRUE, TRUE
	vibrato 8, 2, 4
	note_type 12, 10, 1
	rest 8
gbs_gamecorner_Ch2.mainloop:
	volume_envelope 9, 2
	duty_cycle 1
	sound_call gbs_gamecorner_Ch2.sub1
	octave 1
	note F_, 2
	octave 3
	note Gs, 2
	octave 1
	note F_, 1
	octave 3
	note Gs, 2
	volume_envelope 10, 4
	note Gs, 3
	volume_envelope 9, 2
	note G_, 2
	note As, 1
	octave 4
	note C_, 3
	sound_call gbs_gamecorner_Ch2.sub1
	octave 4
	note F_, 2
	note Ds, 2
	note F_, 1
	note Ds, 2
	volume_envelope 10, 4
	note G_, 3
	note F_, 4
	duty_cycle 2
	volume_envelope 12, 7
	octave 3
	note Ds, 1
	note F_, 1
	note G_, 6
	note F_, 6
	note C_, 4
	note D_, 6
	note Ds, 6
	note F_, 4
	note D_, 6
	note C_, 6
	octave 2
	note As, 4
	note A_, 4
	rest 10
	octave 3
	note Ds, 1
	note F_, 1
	note G_, 6
	note F_, 6
	note C_, 4
	note D_, 6
	note Ds, 6
	note F_, 2
	note Ds, 1
	note F_, 1
	note G_, 16
	volume_envelope 9, 2
	note G_, 1
	note G_, 1
	note G_, 3
	note As, 2
	note As, 9
	volume_envelope 10, 4
	sound_loop 0, gbs_gamecorner_Ch2.mainloop

gbs_gamecorner_Ch2.sub1:
	octave 1
	note C_, 2
	octave 3
	note Ds, 3
	note Ds, 3
	note Ds, 3
	note F_, 3
	note F_, 2
	octave 1
	note C_, 2
	octave 3
	note Ds, 3
	note Ds, 3
	note F_, 2
	note F_, 2
	note Ds, 1
	note F_, 3
	octave 1
	note C_, 2
	octave 3
	note Ds, 3
	note Ds, 3
	note Ds, 3
	note F_, 3
	note F_, 2
	octave 1
	note C_, 2
	octave 3
	note Ds, 3
	note Ds, 3
	note F_, 2
	note C_, 2
	note Ds, 1
	note F_, 3
	octave 1
	note C_, 2
	octave 5
	note D_, 3
	octave 4
	note As, 3
	note G_, 2
	note C_, 2
	note D_, 2
	note Ds, 2
	note F_, 2
	note Ds, 2
	note F_, 1
	note Ds, 2
	volume_envelope 10, 4
	note F_, 3
	note G_, 4
	volume_envelope 9, 2
	note Fs, 1
	note F_, 1
	octave 1
	note C_, 2
	octave 5
	note D_, 3
	octave 4
	note As, 3
	note G_, 2
	note C_, 2
	note D_, 2
	note Ds, 2
	octave 1
	note F_, 1
	octave 4
	note F_, 1
	note Ds, 2
	note G_, 1
	note Ds, 2
	volume_envelope 10, 4
	note As, 3
	note A_, 2
	volume_envelope 9, 2
	note As, 1
	octave 5
	note C_, 3
	octave 1
	note C_, 2
	octave 5
	note D_, 3
	octave 4
	note As, 3
	note G_, 2
	note C_, 2
	note D_, 2
	note Ds, 2
	note F_, 2
	note Ds, 2
	note F_, 1
	note Ds, 2
	volume_envelope 10, 4
	note F_, 3
	note G_, 4
	volume_envelope 9, 2
	note Fs, 1
	note F_, 1
	octave 1
	note C_, 2
	octave 5
	note D_, 3
	octave 4
	note As, 3
	note G_, 2
	note C_, 2
	note D_, 2
	note Ds, 2
	sound_ret

gbs_gamecorner_Ch3:
	gbs_switch 2
	vibrato 8, 2, 2
	note_type 12, 1, 4
	rest 8
gbs_gamecorner_Ch3.mainloop:
	stereo_panning TRUE, TRUE
	note_type 12, 1, 4
	sound_call gbs_gamecorner_Ch3.sub1
	sound_call gbs_gamecorner_Ch3.sub2
	octave 4
	note G_, 1
	note A_, 3
	sound_call gbs_gamecorner_Ch3.sub1
	sound_call gbs_gamecorner_Ch3.sub2
	octave 4
	note As, 1
	octave 5
	note C_, 3
	stereo_panning TRUE, FALSE
	sound_call gbs_gamecorner_Ch3.sub1
	sound_call gbs_gamecorner_Ch3.sub3
	sound_call gbs_gamecorner_Ch3.sub1
	sound_call gbs_gamecorner_Ch3.sub4
	sound_call gbs_gamecorner_Ch3.sub1
	sound_call gbs_gamecorner_Ch3.sub3
	sound_call gbs_gamecorner_Ch3.sub1
	stereo_panning TRUE, TRUE
	octave 2
	note F_, 1
	octave 3
	note F_, 1
	octave 5
	note C_, 1
	octave 4
	note F_, 1
	octave 2
	note F_, 1
	octave 5
	note C_, 1
	octave 3
	note F_, 1
	octave 5
	note Ds, 3
	note D_, 1
	rest 1
	note Ds, 1
	note F_, 1
	rest 2
	sound_call gbs_gamecorner_Ch3.sub1
	sound_call gbs_gamecorner_Ch3.sub2
	octave 4
	note G_, 1
	note A_, 3
	sound_call gbs_gamecorner_Ch3.sub1
	sound_call gbs_gamecorner_Ch3.sub2
	octave 4
	note As, 1
	octave 5
	note C_, 3
	stereo_panning TRUE, FALSE
	sound_call gbs_gamecorner_Ch3.sub1
	sound_call gbs_gamecorner_Ch3.sub3
	sound_call gbs_gamecorner_Ch3.sub1
	sound_call gbs_gamecorner_Ch3.sub4
	sound_call gbs_gamecorner_Ch3.sub1
	sound_call gbs_gamecorner_Ch3.sub3
	sound_call gbs_gamecorner_Ch3.sub1
	octave 2
	note F_, 1
	octave 3
	note F_, 1
	octave 5
	note C_, 1
	octave 4
	note F_, 1
	octave 3
	note F_, 1
	octave 5
	note C_, 1
	octave 4
	note F_, 1
	octave 3
	note F_, 1
	octave 5
	note Ds, 1
	rest 1
	note D_, 1
	rest 1
	note C_, 1
	rest 1
	octave 4
	note As, 1
	rest 1
	volume_envelope 1, 5
	sound_call gbs_gamecorner_Ch3.sub5
	octave 2
	note C_, 2
	rest 1
	note C_, 1
	octave 3
	note C_, 1
	octave 2
	note C_, 1
	rest 1
	note C_, 1
	note C_, 1
	octave 3
	note C_, 1
	octave 2
	note C_, 2
	octave 3
	note C_, 1
	octave 2
	note C_, 1
	rest 1
	octave 3
	note C_, 1
	octave 2
	note F_, 2
	rest 1
	note F_, 1
	octave 3
	note F_, 1
	octave 2
	note F_, 1
	rest 1
	note F_, 1
	note F_, 1
	octave 3
	note F_, 1
	octave 2
	note F_, 2
	octave 3
	note F_, 1
	octave 2
	note F_, 1
	rest 1
	octave 3
	note F_, 1
	sound_call gbs_gamecorner_Ch3.sub5
	octave 2
	note G_, 2
	rest 1
	note G_, 1
	octave 3
	note G_, 1
	octave 2
	note G_, 1
	rest 1
	note G_, 1
	note G_, 1
	octave 3
	note G_, 1
	octave 2
	note G_, 2
	octave 3
	note G_, 1
	octave 2
	note G_, 1
	rest 1
	octave 3
	note G_, 1
	octave 2
	note B_, 1
	note B_, 1
	note B_, 1
	rest 2
	note B_, 1
	rest 1
	note B_, 1
	rest 4
	note_type 6, 1, 5
	octave 3
	note D_, 1
	note C_, 1
	octave 2
	note B_, 1
	note A_, 1
	note G_, 1
	note F_, 1
	note E_, 1
	note D_, 1
	sound_loop 0, gbs_gamecorner_Ch3.mainloop

gbs_gamecorner_Ch3.sub1:
	octave 2
	note C_, 1
	octave 3
	note C_, 1
	octave 4
	note G_, 1
	note C_, 1
	octave 3
	note C_, 1
	octave 4
	note G_, 1
	note C_, 1
	octave 3
	note C_, 1
	octave 4
	note G_, 1
	note C_, 1
	octave 3
	note C_, 1
	octave 4
	note A_, 1
	note C_, 1
	octave 3
	note C_, 1
	octave 4
	note A_, 2
	sound_ret

gbs_gamecorner_Ch3.sub2:
	octave 2
	note C_, 1
	octave 3
	note C_, 1
	octave 4
	note G_, 1
	note C_, 1
	octave 3
	note C_, 1
	octave 4
	note G_, 1
	note C_, 1
	octave 3
	note C_, 1
	octave 4
	note As, 1
	rest 1
	note A_, 1
	rest 1
	sound_ret

gbs_gamecorner_Ch3.sub3:
	octave 2
	note F_, 1
	octave 3
	note F_, 1
	octave 5
	note C_, 1
	octave 4
	note F_, 1
	octave 3
	note F_, 1
	octave 5
	note C_, 1
	octave 4
	note F_, 1
	octave 3
	note F_, 1
	octave 5
	note Ds, 1
	rest 1
	note D_, 1
	rest 1
	note C_, 1
	note D_, 3
	sound_ret

gbs_gamecorner_Ch3.sub4:
	octave 2
	note F_, 1
	octave 3
	note F_, 1
	octave 5
	note C_, 1
	octave 4
	note F_, 1
	octave 3
	note F_, 1
	octave 5
	note C_, 1
	octave 4
	note F_, 1
	octave 3
	note F_, 1
	octave 5
	note Ds, 1
	rest 1
	note D_, 1
	rest 1
	note C_, 1
	note D_, 1
	octave 3
	note F_, 1
	rest 1
	sound_ret

gbs_gamecorner_Ch3.sub5:
	octave 2
	note F_, 2
	rest 1
	note F_, 1
	octave 3
	note F_, 1
	octave 2
	note F_, 1
	rest 1
	note F_, 1
	note F_, 1
	octave 3
	note F_, 1
	octave 2
	note F_, 2
	octave 3
	note F_, 1
	octave 2
	note F_, 1
	rest 1
	octave 3
	note F_, 1
	octave 2
	note G_, 2
	rest 1
	note G_, 1
	octave 3
	note G_, 1
	octave 2
	note G_, 1
	rest 1
	note G_, 1
	note G_, 1
	octave 3
	note G_, 1
	octave 2
	note F_, 1
	octave 3
	note F_, 1
	octave 2
	note Ds, 1
	octave 3
	note Ds, 1
	octave 2
	note D_, 1
	octave 3
	note D_, 1
	sound_ret

gbs_gamecorner_Ch4:
	gbs_switch 3
	toggle_noise 3
	drum_speed 12
	drum_speed 8
	drum_note 3, 1
	drum_note 3, 1
	drum_note 3, 1
	drum_speed 12
	drum_note 3, 1
	drum_note 3, 1
	drum_note 3, 2
	drum_note 3, 1
	drum_note 3, 1
gbs_gamecorner_Ch4.mainloop:
	sound_call gbs_gamecorner_Ch4.sub1
gbs_gamecorner_Ch4.loop1:
	drum_note 11, 2
	drum_note 7, 2
	drum_note 3, 2
	drum_note 7, 2
	drum_note 11, 2
	drum_note 7, 2
	drum_note 3, 2
	drum_note 7, 2
	sound_loop 6, gbs_gamecorner_Ch4.loop1
	sound_call gbs_gamecorner_Ch4.sub2
gbs_gamecorner_Ch4.loop2:
	drum_note 11, 2
	drum_note 7, 2
	drum_note 3, 2
	drum_note 7, 2
	drum_note 11, 2
	drum_note 7, 2
	drum_note 3, 2
	drum_note 7, 2
	sound_loop 3, gbs_gamecorner_Ch4.loop2
	rest 12
	drum_note 3, 1
	drum_note 3, 1
	drum_note 7, 2
	sound_call gbs_gamecorner_Ch4.sub1
gbs_gamecorner_Ch4.loop3:
	drum_note 11, 2
	drum_note 7, 2
	drum_note 3, 2
	drum_note 7, 2
	drum_note 11, 2
	drum_note 7, 2
	drum_note 3, 2
	drum_note 7, 2
	sound_loop 6, gbs_gamecorner_Ch4.loop3
	sound_call gbs_gamecorner_Ch4.sub2
gbs_gamecorner_Ch4.loop4:
	drum_note 11, 2
	drum_note 7, 2
	drum_note 3, 2
	drum_note 7, 2
	drum_note 11, 2
	drum_note 7, 2
	drum_note 3, 2
	drum_note 7, 2
	sound_loop 3, gbs_gamecorner_Ch4.loop4
	drum_note 11, 2
	drum_note 7, 2
	drum_note 3, 2
	drum_note 7, 2
	drum_note 4, 2
	drum_note 7, 2
	drum_note 3, 1
	drum_note 3, 1
	drum_note 3, 1
	drum_note 3, 1
gbs_gamecorner_Ch4.loop5:
	drum_note 11, 2
	drum_note 7, 1
	drum_note 4, 1
	drum_note 3, 1
	drum_note 4, 1
	drum_note 7, 1
	drum_note 4, 1
	drum_note 4, 1
	drum_note 3, 1
	drum_note 7, 1
	drum_note 4, 1
	drum_note 3, 2
	drum_note 7, 2
	sound_loop 3, gbs_gamecorner_Ch4.loop5
	drum_note 11, 2
	drum_note 7, 1
	drum_note 4, 1
	drum_note 3, 1
	drum_note 4, 1
	drum_note 7, 1
	drum_note 4, 1
	drum_note 4, 1
	drum_note 3, 1
	drum_note 7, 1
	drum_note 4, 1
	drum_note 3, 2
	drum_note 3, 1
	drum_note 3, 1
gbs_gamecorner_Ch4.loop6:
	drum_note 11, 2
	drum_note 7, 1
	drum_note 4, 1
	drum_note 3, 1
	drum_note 4, 1
	drum_note 7, 1
	drum_note 4, 1
	drum_note 4, 1
	drum_note 3, 1
	drum_note 7, 1
	drum_note 4, 1
	drum_note 3, 2
	drum_note 7, 2
	sound_loop 3, gbs_gamecorner_Ch4.loop6
	drum_note 3, 1
	drum_note 3, 1
	drum_note 3, 2
	drum_note 11, 1
	drum_note 7, 2
	drum_note 7, 5
	drum_note 3, 1
	drum_note 3, 1
	drum_note 4, 2
	sound_loop 0, gbs_gamecorner_Ch4.mainloop

gbs_gamecorner_Ch4.sub1:
	drum_note 1, 2
	drum_note 7, 2
	drum_note 3, 2
	drum_note 7, 2
	drum_note 11, 2
	drum_note 7, 2
	drum_note 3, 2
	drum_note 7, 2
	sound_ret

gbs_gamecorner_Ch4.sub2:
	drum_note 11, 2
	drum_note 7, 2
	drum_note 3, 2
	drum_note 7, 2
	drum_note 11, 2
	drum_note 7, 2
	drum_note 3, 1
	drum_note 3, 1
	drum_note 7, 2
	sound_ret

	.align 4
	.global gbs_gamecorner_Header
gbs_gamecorner_Header:
	.byte 4	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_gamecorner_Ch1
	.int gbs_gamecorner_Ch2
	.int gbs_gamecorner_Ch3
	.int gbs_gamecorner_Ch4
