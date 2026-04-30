	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_route2_Ch1:
	gbs_switch 0
	tempo 151
	volume 7, 7
	stereo_panning FALSE, TRUE
	vibrato 6, 2, 3
	note_type 12, 11, 1
	rest 16
	rest 16
	sound_call gbs_route2_Ch1.sub1
gbs_route2_Ch1.mainloop:
	volume_envelope 11, 1
	octave 3
	note B_, 4
	note B_, 4
	note B_, 4
	note B_, 4
	octave 4
	note E_, 4
	note E_, 4
	note E_, 4
	note E_, 4
	sound_call gbs_route2_Ch1.sub1
	sound_call gbs_route2_Ch1.sub2
	sound_call gbs_route2_Ch1.sub2
	sound_call gbs_route2_Ch1.sub3
	octave 3
	note G_, 2
	octave 4
	note C_, 2
	octave 3
	note G_, 2
	octave 4
	note C_, 2
	note F_, 2
	note D_, 2
	octave 3
	note B_, 2
	note G_, 2
	sound_call gbs_route2_Ch1.sub3
	note G_, 2
	octave 4
	note C_, 2
	note D_, 2
	note G_, 2
	note F_, 2
	note D_, 2
	octave 3
	note B_, 2
	note G_, 2
	sound_loop 0, gbs_route2_Ch1.mainloop

gbs_route2_Ch1.sub1:
	octave 4
	note C_, 4
	note C_, 4
	note C_, 4
	note C_, 4
	note C_, 4
	note C_, 4
	volume_envelope 11, 7
	note C_, 4
	octave 3
	note B_, 4
	volume_envelope 11, 1
	sound_ret

gbs_route2_Ch1.sub2:
	octave 2
	note B_, 2
	octave 3
	note E_, 2
	octave 2
	note B_, 2
	octave 3
	note E_, 2
	octave 2
	note B_, 2
	octave 3
	note E_, 2
	octave 2
	note B_, 2
	octave 3
	note E_, 2
	note E_, 2
	note As, 2
	note E_, 2
	note As, 2
	note E_, 2
	note As, 2
	note E_, 2
	note As, 2
	note C_, 2
	note A_, 2
	note C_, 2
	note A_, 2
	note C_, 2
	note A_, 2
	note C_, 2
	note A_, 2
	note C_, 2
	note Gs, 2
	note C_, 2
	note Gs, 2
	volume_envelope 11, 7
	octave 2
	note B_, 2
	octave 3
	note Gs, 2
	octave 2
	note B_, 2
	octave 3
	note G_, 2
	volume_envelope 11, 1
	sound_ret

gbs_route2_Ch1.sub3:
	note B_, 2
	note G_, 2
	note B_, 2
	note G_, 2
	note B_, 2
	note Gs, 2
	note B_, 2
	note Gs, 2
	octave 4
	note E_, 2
	note C_, 2
	note E_, 2
	note C_, 2
	note D_, 2
	octave 3
	note B_, 2
	octave 4
	note D_, 2
	octave 3
	note B_, 2
	octave 4
	note C_, 2
	octave 3
	note A_, 2
	octave 4
	note C_, 2
	octave 3
	note A_, 2
	octave 4
	note C_, 2
	octave 3
	note A_, 2
	octave 4
	note C_, 2
	octave 3
	note A_, 2
	sound_ret

gbs_route2_Ch2:
	gbs_switch 1
	stereo_panning TRUE, TRUE
	vibrato 8, 2, 4
	note_type 12, 11, 2
	sound_call gbs_route2_Ch2.sub1
gbs_route2_Ch2.mainloop:
	volume_envelope 11, 2
	sound_call gbs_route2_Ch2.sub1
	duty_cycle 2
	volume_envelope 11, 5
	sound_call gbs_route2_Ch2.sub2
	sound_call gbs_route2_Ch2.sub2
	sound_call gbs_route2_Ch2.sub3
	sound_call gbs_route2_Ch2.sub3
	sound_loop 0, gbs_route2_Ch2.mainloop

gbs_route2_Ch2.sub1:
	octave 4
	note E_, 4
	note E_, 4
	note E_, 2
	octave 2
	note C_, 2
	octave 4
	note E_, 2
	octave 2
	note C_, 2
	octave 4
	note As, 4
	note As, 4
	note As, 2
	octave 2
	note G_, 2
	octave 4
	note As, 2
	octave 2
	note G_, 2
	octave 4
	note A_, 4
	note A_, 4
	note A_, 4
	note A_, 4
	note Gs, 4
	note Gs, 4
	volume_envelope 11, 7
	note Gs, 4
	note G_, 4
	volume_envelope 11, 2
	sound_ret

gbs_route2_Ch2.sub2:
	octave 2
	note C_, 4
	rest 2
	note C_, 1
	rest 1
	note C_, 1
	rest 1
	note C_, 2
	rest 2
	note C_, 1
	rest 1
	note G_, 4
	rest 2
	note G_, 1
	rest 1
	note G_, 1
	rest 1
	note G_, 2
	rest 2
	note G_, 1
	rest 1
	note F_, 4
	rest 2
	note F_, 1
	rest 1
	note F_, 1
	rest 1
	note F_, 2
	rest 2
	note F_, 1
	rest 1
	note F_, 4
	rest 2
	note F_, 1
	rest 1
	note F_, 4
	note D_, 4
	sound_ret

gbs_route2_Ch2.sub3:
	octave 2
	note E_, 4
	rest 2
	note E_, 1
	rest 1
	note E_, 1
	rest 1
	note E_, 2
	rest 2
	note E_, 1
	rest 1
	note A_, 4
	rest 2
	note A_, 1
	rest 1
	note Gs, 1
	rest 1
	note Gs, 2
	rest 2
	note Gs, 1
	rest 1
	note F_, 4
	rest 2
	note F_, 1
	rest 1
	note Fs, 1
	rest 1
	note Fs, 2
	rest 2
	note Fs, 1
	rest 1
	note G_, 4
	rest 2
	note G_, 1
	rest 1
	note G_, 1
	rest 1
	note G_, 2
	rest 2
	note G_, 1
	rest 1
	sound_ret

gbs_route2_Ch3:
	gbs_switch 2
	stereo_panning TRUE, FALSE
	vibrato 22, 1, 5
	note_type 12, 1, 4
	octave 4
	note B_, 1
	rest 3
	note B_, 1
	rest 3
	note B_, 1
	rest 3
	note B_, 1
	rest 3
	octave 5
	note E_, 1
	rest 3
	note E_, 1
	rest 3
	note E_, 1
	rest 3
	note E_, 1
	rest 3
	sound_call gbs_route2_Ch3.sub1
	octave 3
	note D_, 4
gbs_route2_Ch3.mainloop:
	note_type 12, 1, 5
	octave 3
	note C_, 4
	rest 2
	note C_, 1
	rest 1
	note C_, 1
	rest 1
	note C_, 2
	rest 2
	note C_, 1
	rest 1
	note G_, 4
	rest 2
	note G_, 1
	rest 1
	note G_, 1
	rest 1
	note G_, 2
	rest 2
	note G_, 1
	rest 1
	sound_call gbs_route2_Ch3.sub1
	octave 3
	note D_, 2
	volume_envelope 1, 0
	octave 6
	note C_, 1
	note D_, 1
	sound_call gbs_route2_Ch3.sub2
	rest 4
	note G_, 8
	note F_, 2
	note G_, 2
	note_type 12, 1, 0
	sound_call gbs_route2_Ch3.sub2
	rest 16
	volume_envelope 2, 5
	sound_call gbs_route2_Ch3.sub3
	rest 4
	note Ds, 1
	note E_, 7
	note D_, 4
	octave 5
	note B_, 1
	octave 6
	note C_, 3
	octave 5
	note B_, 4
	note A_, 4
	note B_, 8
	note G_, 4
	octave 6
	note A_, 4
	note G_, 4
	sound_call gbs_route2_Ch3.sub3
	rest 4
	note Gs, 1
	note A_, 7
	note B_, 4
	note Fs, 1
	note G_, 16
	note G_, 15
	sound_loop 0, gbs_route2_Ch3.mainloop

gbs_route2_Ch3.sub1:
	octave 3
	note F_, 4
	rest 2
	note F_, 1
	rest 1
	note F_, 1
	rest 1
	note F_, 2
	rest 2
	note F_, 1
	rest 1
	note F_, 4
	rest 2
	note F_, 1
	rest 1
	note F_, 4
	sound_ret

gbs_route2_Ch3.sub2:
	octave 6
	note E_, 10
	note D_, 2
	rest 2
	note C_, 2
	note_type 6, 1, 0
	octave 5
	note Fs, 1
	note G_, 15
	note A_, 4
	note As, 4
	rest 4
	octave 6
	note C_, 2
	note D_, 2
	note Ds, 1
	note E_, 16
	note E_, 7
	note F_, 4
	note E_, 4
	note Ds, 1
	note E_, 3
	note D_, 4
	note C_, 4
	note D_, 4
	sound_ret

gbs_route2_Ch3.sub3:
	octave 5
	note B_, 16
	rest 4
	octave 6
	note Cs, 1
	note D_, 7
	note E_, 4
	octave 5
	note B_, 1
	octave 6
	note C_, 16
	note C_, 3
	note D_, 4
	rest 4
	note E_, 4
	note F_, 16
	sound_ret

gbs_route2_Ch4:
	gbs_switch 3
	toggle_noise 5
	drum_speed 12
gbs_route2_Ch4.loop1:
	drum_note 10, 4
	drum_note 10, 4
	drum_note 10, 2
	drum_note 12, 2
	drum_note 10, 2
	drum_note 12, 2
	sound_loop 3, gbs_route2_Ch4.loop1
	drum_note 10, 4
	drum_note 10, 4
	drum_note 10, 2
	drum_note 10, 2
	drum_note 4, 4
gbs_route2_Ch4.mainloop:
gbs_route2_Ch4.loop2:
	drum_note 10, 4
	drum_note 10, 4
	drum_note 10, 2
	drum_note 10, 2
	drum_note 12, 2
	drum_note 10, 2
	sound_loop 4, gbs_route2_Ch4.loop2
gbs_route2_Ch4.loop3:
	drum_note 12, 4
	drum_note 10, 2
	drum_note 12, 2
	drum_note 10, 2
	drum_note 12, 2
	drum_note 10, 2
	drum_note 12, 2
	sound_loop 7, gbs_route2_Ch4.loop3
	drum_note 12, 4
	drum_note 10, 4
	drum_note 10, 2
	drum_note 10, 2
	drum_note 4, 4
gbs_route2_Ch4.loop4:
	drum_note 12, 4
	drum_note 1, 4
	drum_note 12, 2
	drum_note 12, 2
	drum_note 1, 4
	sound_loop 3, gbs_route2_Ch4.loop4
	drum_note 12, 4
	drum_note 1, 4
	drum_note 2, 2
	drum_note 1, 2
	drum_note 2, 4
gbs_route2_Ch4.loop5:
	drum_note 12, 4
	drum_note 1, 4
	drum_note 12, 2
	drum_note 12, 2
	drum_note 1, 4
	sound_loop 3, gbs_route2_Ch4.loop5
	drum_note 12, 4
	drum_note 1, 4
	drum_note 3, 2
	drum_note 3, 2
	drum_note 4, 4
	sound_loop 0, gbs_route2_Ch4.mainloop

	.align 4
	.global gbs_route2_Header
gbs_route2_Header:
	.byte 4	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_route2_Ch1
	.int gbs_route2_Ch2
	.int gbs_route2_Ch3
	.int gbs_route2_Ch4
