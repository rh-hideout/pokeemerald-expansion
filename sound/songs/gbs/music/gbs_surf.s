	.include "asm/macros.inc"

	.section .rodata
	.align 1


gbs_surf_Ch1:
	gbs_switch 0
	tempo 108
	volume 7, 7
	note_type 12, 10, 7
	stereo_panning FALSE, TRUE
gbs_surf_Ch1.mainloop:
	duty_cycle 2
	vibrato 16, 2, 4
	volume_envelope 7, 3
	octave 3
	note F_, 1
	rest 1
	note Ds, 1
	rest 1
	volume_envelope 7, 3
	note F_, 1
	rest 1
	note Ds, 1
	rest 1
	note Gs, 1
	rest 1
	note Ds, 1
	rest 1
	volume_envelope 7, 3
	note F_, 1
	rest 1
	note Ds, 1
	rest 1
	note F_, 1
	rest 1
	note Ds, 1
	volume_envelope 9, 3
	rest 1
	note Gs, 1
	rest 1
	note Ds, 1
	rest 1
	volume_envelope 10, 7
	note F_, 1
	rest 1
	note Ds, 1
	rest 1
	note F_, 1
	rest 1
	note Ds, 1
	volume_envelope 11, 7
	rest 1
	note As, 2
	note Gs, 2
	note F_, 2
	note D_, 2
	note_type 8, 12, 7
	octave 2
	note As, 2
	octave 3
	note D_, 2
	note F_, 2
	volume_envelope 15, 7
	note Gs, 2
	note As, 2
	octave 4
	note D_, 2
	duty_cycle 0
	sound_call gbs_surf_Ch1.sub1
	duty_cycle 1
	note_type 8, 10, 7
	sound_call gbs_surf_Ch1.sub1
	sound_call gbs_surf_Ch1.sub2
	octave 4
	note C_, 2
	octave 3
	note G_, 2
	note Ds, 2
	note C_, 2
	note Ds, 2
	note G_, 2
	octave 4
	note C_, 2
	note Ds, 2
	note G_, 2
	duty_cycle 1
	note_type 6, 9, 7
	sound_call gbs_surf_Ch1.sub2
	volume_envelope 10, 8
	note Gs, 6
	note A_, 6
	note As, 3
	octave 4
	note D_, 3
	volume_envelope 10, 8
	duty_cycle 1
	sound_call gbs_surf_Ch1.sub3
	octave 3
	note Ds, 8
	note Gs, 8
	note Ds, 8
	duty_cycle 3
	note_type 8, 9, 8
	sound_call gbs_surf_Ch1.sub3
	note_type 12, 10, 7
	octave 3
	note Ds, 12
	octave 2
	note F_, 4
	note Ds, 4
	note F_, 4
	note Gs, 4
	note Ds, 2
	note Gs, 2
	note B_, 2
	octave 3
	note Ds, 2
	sound_loop 0, gbs_surf_Ch1.mainloop

gbs_surf_Ch1.sub1:
	note_type 12, 10, 7
	octave 3
	note Ds, 4
	note As, 1
	rest 1
	octave 4
	note Ds, 1
	rest 1
	octave 3
	note As, 1
	rest 1
	octave 4
	note Ds, 1
	rest 1
	octave 3
	note Ds, 4
	note As, 1
	rest 1
	octave 4
	note Ds, 1
	rest 1
	octave 3
	note As, 1
	rest 1
	octave 4
	note Ds, 1
	rest 1
	octave 3
	note Cs, 4
	note As, 1
	rest 1
	octave 4
	note Cs, 1
	rest 1
	octave 3
	note As, 1
	rest 1
	octave 4
	note Cs, 1
	rest 1
	octave 3
	note Cs, 4
	note As, 1
	rest 1
	octave 4
	note Cs, 1
	rest 1
	octave 3
	note As, 1
	rest 1
	octave 4
	note Cs, 1
	rest 1
	octave 3
	note C_, 4
	note Gs, 1
	rest 1
	octave 4
	note C_, 1
	rest 1
	octave 3
	note Gs, 1
	rest 1
	octave 4
	note C_, 1
	rest 1
	octave 3
	note C_, 4
	note Gs, 1
	rest 1
	octave 4
	note C_, 1
	rest 1
	octave 3
	note Gs, 1
	rest 1
	octave 4
	note C_, 1
	rest 1
	note_type 6, 10, 7
	octave 3
	note As, 1
	note B_, 15
	octave 4
	note Ds, 4
	octave 3
	note B_, 4
	note Gs, 8
	note F_, 8
	note Cs, 4
	note D_, 4
	sound_ret

gbs_surf_Ch1.sub2:
	octave 4
	note Gs, 16
	note Ds, 4
	note C_, 4
	octave 3
	note Gs, 4
	octave 4
	note C_, 4
	note D_, 4
	note Ds, 4
	note G_, 4
	note Gs, 4
	note_type 8, 9, 2
	note As, 2
	note F_, 2
	note D_, 2
	note F_, 2
	note D_, 2
	octave 3
	note As, 2
	octave 4
	note D_, 2
	octave 3
	note As, 2
	note F_, 2
	note As, 2
	note F_, 2
	note D_, 2
	octave 2
	note As, 2
	octave 3
	note D_, 2
	note F_, 2
	note Gs, 2
	note As, 2
	octave 4
	note D_, 2
	note_type 6, 9, 7
	note Cs, 1
	note D_, 15
	note G_, 4
	note D_, 4
	octave 3
	note As, 4
	octave 4
	note D_, 4
	note F_, 4
	note G_, 4
	note A_, 4
	note As, 4
	note_type 8, 9, 2
	octave 5
	note C_, 2
	octave 4
	note G_, 2
	note Ds, 2
	note G_, 2
	note Ds, 2
	note C_, 2
	note Ds, 2
	note C_, 2
	octave 3
	note G_, 2
	sound_ret

gbs_surf_Ch1.sub3:
	octave 3
	note As, 3
	note G_, 3
	note As, 3
	octave 4
	note Ds, 9
	note_type 6, 5, 8
	note D_, 1
	note Cs, 1
	note C_, 1
	octave 3
	note B_, 1
	note As, 1
	note A_, 1
	note Gs, 1
	note G_, 1
	volume_envelope 10, 8
	note Ds, 4
	note D_, 4
	note Ds, 4
	note G_, 4
	note A_, 4
	note Gs, 4
	note G_, 4
	note Fs, 4
	note F_, 4
	note E_, 4
	note G_, 8
	note Cs, 8
	note As, 8
	note A_, 1
	note As, 3
	note Gs, 4
	octave 4
	note C_, 4
	note F_, 12
	volume_envelope 5, 8
	note Ds, 1
	note D_, 1
	note Cs, 1
	note C_, 1
	octave 3
	note B_, 1
	note As, 1
	note A_, 1
	note G_, 1
	volume_envelope 10, 8
	note Gs, 8
	octave 4
	note Ds, 4
	octave 3
	note B_, 4
	note Gs, 8
	note Ds, 8
	octave 2
	note B_, 8
	sound_ret

gbs_surf_Ch2:
	gbs_switch 1
gbs_surf_Ch2.mainloop:
	note_type 12, 12, 2
	stereo_panning TRUE, FALSE
	duty_cycle 2
	vibrato 20, 2, 3
gbs_surf_Ch2.loop1:
	octave 1
	note As, 4
	octave 2
	note As, 1
	rest 3
	note As, 1
	rest 3
	sound_loop 3, gbs_surf_Ch2.loop1
	octave 1
	note As, 4
	octave 2
	note F_, 1
	rest 3
	note As, 1
	rest 3
gbs_surf_Ch2.loop2:
	note Ds, 4
	note G_, 2
	note Gs, 2
	note As, 4
	note Ds, 4
	note G_, 2
	note Gs, 2
	note As, 4
	note Cs, 4
	note G_, 2
	note Gs, 2
	note As, 4
	note Cs, 4
	note G_, 2
	note Gs, 2
	note As, 4
	note C_, 4
	note F_, 2
	note G_, 2
	note Gs, 4
	note C_, 4
	note F_, 2
	note G_, 2
	note Gs, 4
	octave 1
	note B_, 4
	octave 2
	note F_, 2
	note G_, 2
	note Gs, 2
	note As, 2
	note B_, 4
	note As, 4
	note Gs, 4
	sound_loop 2, gbs_surf_Ch2.loop2
	volume_envelope 12, 7
	sound_call gbs_surf_Ch2.sub1
	note Ds, 4
	note D_, 4
	note Cs, 4
	sound_call gbs_surf_Ch2.sub1
	note D_, 4
	note Ds, 4
	octave 1
	note As, 4
	note_type 6, 11, 8
	sound_call gbs_surf_Ch2.sub2
	duty_cycle 1
	volume_envelope 11, 8
	sound_call gbs_surf_Ch2.sub3
	duty_cycle 2
	sound_call gbs_surf_Ch2.sub4
	duty_cycle 1
	volume_envelope 11, 8
	sound_call gbs_surf_Ch2.sub5
	octave 3
	note B_, 16
	octave 4
	note Cs, 8
	transpose 0, 12
	duty_cycle 3
	sound_call gbs_surf_Ch2.sub2
	volume_envelope 11, 8
	duty_cycle 1
	sound_call gbs_surf_Ch2.sub3
	duty_cycle 3
	sound_call gbs_surf_Ch2.sub4
	volume_envelope 11, 8
	duty_cycle 1
	sound_call gbs_surf_Ch2.sub5
	transpose 0, 0
	note_type 12, 11, 8
	octave 4
	note B_, 12
	duty_cycle 2
	note As, 4
	note Gs, 4
	note Ds, 4
	note Gs, 4
	note As, 4
	note B_, 4
	sound_loop 0, gbs_surf_Ch2.mainloop

gbs_surf_Ch2.sub1:
	octave 1
	note Gs, 4
	octave 3
	note F_, 4
	note Ds, 4
	octave 1
	note Gs, 4
	octave 3
	note Ds, 4
	note D_, 4
	octave 1
	note As, 4
	octave 3
	note C_, 4
	octave 2
	note As, 4
	octave 1
	note As, 4
	octave 2
	note Gs, 4
	note As, 4
	octave 1
	note G_, 4
	octave 3
	note D_, 4
	note C_, 4
	octave 1
	note G_, 4
	octave 2
	note As, 4
	note G_, 4
	note C_, 4
	octave 3
	note F_, 4
	note G_, 4
	sound_ret

gbs_surf_Ch2.sub2:
	octave 4
	note F_, 4
	note Ds, 4
	note F_, 4
	note G_, 12
	volume_envelope 5, 8
	note Fs, 1
	note F_, 1
	note E_, 1
	note Ds, 1
	note D_, 1
	note Cs, 1
	note C_, 1
	octave 3
	note B_, 1
	note A_, 1
	sound_ret

gbs_surf_Ch2.sub3:
	note As, 7
	octave 4
	note C_, 8
	note Cs, 16
	note C_, 4
	octave 3
	note B_, 4
	octave 4
	note C_, 16
	note G_, 8
	sound_ret

gbs_surf_Ch2.sub4:
	note Fs, 1
	note G_, 3
	note F_, 4
	note G_, 4
	note Gs, 12
	volume_envelope 5, 8
	note G_, 1
	note Fs, 1
	note F_, 1
	note E_, 1
	note Ds, 1
	note D_, 1
	note Cs, 1
	octave 3
	note B_, 1
	sound_ret

gbs_surf_Ch2.sub5:
	octave 4
	note C_, 8
	note G_, 4
	note Gs, 4
	note As, 8
	note Gs, 8
	note Ds, 8
	sound_ret

gbs_surf_Ch3:
	gbs_switch 2
gbs_surf_Ch3.mainloop:
	stereo_panning TRUE, TRUE
	note_type 12, 1, 5
	vibrato 22, 2, 3
	octave 4
	note As, 12
	octave 5
	note C_, 12
	note D_, 8
	note Ds, 4
	note F_, 4
	note G_, 4
	note Gs, 4
	volume_envelope 1, 2
	note As, 12
	rest 4
	note Gs, 4
	note G_, 4
	note_type 6, 1, 2
	note Fs, 1
	note G_, 15
	note Gs, 4
	note G_, 4
	note F_, 16
	octave 4
	note As, 8
	note_type 12, 1, 2
	octave 5
	note Gs, 16
	note G_, 4
	note F_, 4
	note_type 6, 1, 2
	note E_, 1
	note F_, 15
	note G_, 4
	note F_, 4
	note Ds, 16
	note F_, 8
	note_type 12, 1, 4
	note As, 12
	rest 4
	note Gs, 4
	note G_, 4
	note_type 6, 1, 4
	note Fs, 1
	note G_, 15
	note Gs, 4
	note G_, 4
	note F_, 16
	octave 4
	note As, 8
	note_type 12, 1, 4
	octave 5
	note Gs, 16
	note G_, 4
	note F_, 4
	note_type 6, 1, 4
	note E_, 1
	note F_, 15
	note G_, 4
	note F_, 4
	note Ds, 16
	octave 6
	note Ds, 8
	note_type 12, 1, 3
	note C_, 16
	note D_, 4
	note Ds, 4
	note_type 6, 1, 3
	note D_, 1
	note Ds, 15
	note D_, 4
	note C_, 4
	octave 5
	note D_, 16
	octave 6
	note D_, 8
	note_type 12, 1, 3
	octave 5
	note As, 12
	note_type 6, 1, 3
	note A_, 1
	note As, 7
	octave 6
	note C_, 8
	note D_, 8
	note F_, 16
	note Ds, 4
	note D_, 4
	note Ds, 16
	note D_, 8
	note_type 12, 1, 4
	note C_, 12
	note C_, 4
	note D_, 4
	note Ds, 4
	note_type 6, 1, 4
	note D_, 1
	note Ds, 15
	note D_, 4
	note C_, 4
	octave 5
	note D_, 16
	octave 6
	note D_, 8
	note_type 12, 1, 4
	octave 5
	note As, 12
	note_type 6, 1, 4
	note A_, 1
	note As, 7
	octave 6
	note C_, 8
	note D_, 8
	note_type 12, 1, 4
	note F_, 12
	note G_, 8
	octave 5
	note As, 4
	volume_envelope 1, 5
	sound_call gbs_surf_Ch3.sub1
	octave 2
	note B_, 4
	octave 3
	note Ds, 4
	note F_, 4
	note Gs, 4
	note As, 4
	note B_, 4
	sound_call gbs_surf_Ch3.sub1
	octave 2
	note B_, 4
	octave 3
	note Ds, 4
	note Gs, 4
	note B_, 12
	octave 2
	note B_, 12
	octave 3
	note Ds, 8
	octave 2
	note B_, 4
	sound_loop 0, gbs_surf_Ch3.mainloop

gbs_surf_Ch3.sub1:
	octave 3
	note Ds, 4
	note G_, 1
	rest 3
	note As, 1
	rest 3
	note Ds, 4
	note G_, 1
	rest 3
	note As, 1
	rest 3
	note Cs, 4
	note G_, 1
	rest 3
	note As, 1
	rest 3
	note Cs, 4
	note G_, 1
	rest 3
	note As, 1
	rest 3
	note C_, 4
	note F_, 1
	rest 3
	note Gs, 1
	rest 3
	note C_, 4
	note F_, 1
	rest 3
	note Gs, 1
	rest 3
	sound_ret

	.align 4
	.global gbs_surf_Header
gbs_surf_Header:
	.byte 3	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_surf_Ch1
	.int gbs_surf_Ch2
	.int gbs_surf_Ch3
