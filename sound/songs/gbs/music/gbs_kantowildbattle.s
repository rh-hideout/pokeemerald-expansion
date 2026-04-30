	.include "asm/macros.inc"

	.section .rodata
	.align 1


gbs_kantowildbattle_Ch1:
	gbs_switch 0
	tempo 112
	volume 7, 7
	vibrato 18, 2, 3
	duty_cycle 2
	note_type 12, 11, 7
	rest 16
	octave 4
	note As, 6
	note A_, 1
	note Gs, 1
	note A_, 1
	note Gs, 1
	note G_, 1
	note Fs, 1
	note Gs, 1
	note G_, 1
	note Fs, 1
	note F_, 1
gbs_kantowildbattle_Ch1.mainloop:
	note_type 12, 11, 7
	sound_call gbs_kantowildbattle_Ch1.sub1
	octave 4
	note F_, 4
	note Cs, 4
	octave 3
	note B_, 8
	sound_call gbs_kantowildbattle_Ch1.sub1
	rest 8
	note G_, 1
	note B_, 1
	octave 4
	note Cs, 1
	octave 3
	note B_, 1
	note G_, 1
	note B_, 1
	octave 4
	note D_, 1
	note Ds, 1
	volume_envelope 11, 1
	note E_, 6
	note C_, 6
	octave 3
	note G_, 4
	octave 4
	note E_, 6
	note C_, 6
	note E_, 4
	volume_envelope 11, 7
	note F_, 1
	note Cs, 1
	octave 3
	note Gs, 1
	octave 4
	note C_, 1
	note Cs, 1
	octave 3
	note Gs, 1
	note F_, 1
	note G_, 1
	note Gs, 4
	note Fs, 1
	note G_, 1
	note Gs, 1
	octave 4
	note C_, 1
	note Cs, 4
	octave 3
	note F_, 1
	note Gs, 1
	octave 4
	note Cs, 1
	note E_, 1
	note F_, 3
	note G_, 1
	note Gs, 4
	volume_envelope 11, 1
	octave 3
	note G_, 6
	note F_, 6
	note E_, 4
	note Gs, 6
	note G_, 6
	note F_, 4
	octave 4
	note C_, 6
	octave 3
	note As, 6
	note G_, 4
	note_type 8, 11, 7
	octave 2
	note G_, 2
	octave 3
	note C_, 2
	note E_, 2
	note C_, 2
	note E_, 2
	note G_, 2
	note E_, 2
	note G_, 2
	octave 4
	note C_, 2
	octave 3
	note G_, 2
	octave 4
	note C_, 2
	note E_, 2
	note F_, 2
	note Cs, 2
	octave 3
	note Gs, 2
	octave 4
	note Cs, 2
	octave 3
	note Gs, 2
	note F_, 2
	note Gs, 2
	note F_, 2
	note Cs, 2
	note F_, 2
	note Cs, 2
	octave 2
	note Gs, 2
	note_type 12, 11, 7
	octave 3
	note Gs, 4
	octave 4
	note Cs, 4
	volume_envelope 7, 1
	note F_, 1
	note F_, 1
	volume_envelope 9, 1
	note F_, 1
	note F_, 1
	volume_envelope 11, 1
	note Gs, 1
	note Gs, 1
	volume_envelope 13, 1
	note Gs, 1
	note Gs, 1
	volume_envelope 12, 7
	note E_, 1
	note D_, 1
	note Cs, 1
	note D_, 1
	note E_, 12
	note E_, 8
	volume_envelope 11, 1
	note E_, 1
	note D_, 1
	note C_, 1
	octave 3
	note As, 1
	note A_, 1
	note G_, 1
	note F_, 1
	note E_, 1
	volume_envelope 11, 7
	note D_, 8
	note F_, 8
	note As, 8
	octave 4
	note D_, 8
	octave 3
	note G_, 8
	octave 4
	note C_, 8
	note E_, 8
	note G_, 8
	rest 8
	octave 3
	note Ds, 8
	note Gs, 8
	octave 4
	note C_, 8
	octave 3
	note As, 8
	rest 8
	octave 4
	note D_, 8
	octave 3
	note Gs, 2
	note F_, 2
	note D_, 2
	note F_, 2
	octave 4
	note C_, 4
	rest 6
	note C_, 1
	rest 5
	note Cs, 2
	note C_, 1
	rest 13
	note Cs, 4
	rest 6
	note Cs, 1
	rest 5
	note F_, 2
	note Ds, 1
	rest 5
	note Cs, 8
gbs_kantowildbattle_Ch1.loop1:
	volume_envelope 11, 1
	octave 3
	note C_, 1
	note Ds, 1
	note D_, 1
	note Cs, 1
	sound_loop 8, gbs_kantowildbattle_Ch1.loop1
gbs_kantowildbattle_Ch1.loop2:
	note Cs, 1
	note F_, 1
	note E_, 1
	note Ds, 1
	sound_loop 8, gbs_kantowildbattle_Ch1.loop2
gbs_kantowildbattle_Ch1.loop3:
	note C_, 1
	note Ds, 1
	note D_, 1
	note Cs, 1
	sound_loop 16, gbs_kantowildbattle_Ch1.loop3
gbs_kantowildbattle_Ch1.loop4:
	note Cs, 1
	note E_, 1
	note Ds, 1
	note D_, 1
	sound_loop 8, gbs_kantowildbattle_Ch1.loop4
gbs_kantowildbattle_Ch1.loop5:
	note C_, 1
	note Ds, 1
	note D_, 1
	note Cs, 1
	sound_loop 8, gbs_kantowildbattle_Ch1.loop5
	sound_loop 0, gbs_kantowildbattle_Ch1.mainloop

gbs_kantowildbattle_Ch1.sub1:
	octave 4
	note C_, 1
	rest 5
	octave 3
	note B_, 1
	rest 5
	note As, 1
	rest 3
	rest 10
	octave 4
	note C_, 2
	rest 2
	note Ds, 2
	note Cs, 1
	rest 5
	note C_, 1
	rest 5
	octave 3
	note B_, 1
	rest 3
	sound_ret

gbs_kantowildbattle_Ch2:
	gbs_switch 1
	duty_cycle 1
	vibrato 18, 2, 3
	note_type 12, 11, 1
	octave 4
	note G_, 1
	note Fs, 1
	note F_, 1
	note E_, 1
	note G_, 1
	note Fs, 1
	note F_, 1
	note E_, 1
	note G_, 1
	note Fs, 1
	note F_, 1
	note E_, 1
	note G_, 1
	note Fs, 1
	note F_, 1
	note E_, 1
	note G_, 1
	note Fs, 1
	note F_, 1
	note E_, 1
	note Fs, 1
	note F_, 1
	note E_, 1
	note Ds, 1
	note F_, 1
	note E_, 1
	note Ds, 1
	note D_, 1
	note E_, 1
	note Ds, 1
	note D_, 1
	note Cs, 1
gbs_kantowildbattle_Ch2.mainloop:
	note_type 12, 11, 7
	sound_call gbs_kantowildbattle_Ch2.sub1
	octave 2
	note F_, 2
	octave 1
	note B_, 1
	rest 1
	octave 2
	note G_, 2
	sound_call gbs_kantowildbattle_Ch2.sub1
	octave 2
	note G_, 1
	rest 1
	octave 1
	note B_, 1
	rest 1
	octave 2
	note F_, 1
	note Fs, 1
	note_type 6, 11, 7
	sound_call gbs_kantowildbattle_Ch2.sub2
	sound_call gbs_kantowildbattle_Ch2.sub2
	transpose 0, 1
	sound_call gbs_kantowildbattle_Ch2.sub2
	sound_call gbs_kantowildbattle_Ch2.sub2
	transpose 0, 0
	sound_call gbs_kantowildbattle_Ch2.sub2
	sound_call gbs_kantowildbattle_Ch2.sub2
	sound_call gbs_kantowildbattle_Ch2.sub2
	sound_call gbs_kantowildbattle_Ch2.sub2
	transpose 0, 1
	sound_call gbs_kantowildbattle_Ch2.sub2
	sound_call gbs_kantowildbattle_Ch2.sub2
	transpose 0, 0
	sound_call gbs_kantowildbattle_Ch2.sub2
	sound_call gbs_kantowildbattle_Ch2.sub2
	rest 16
	octave 3
	note As, 16
	octave 4
	note D_, 16
	note F_, 16
	note_type 12, 11, 7
	note E_, 16
	note G_, 8
	octave 5
	note C_, 8
	rest 8
	octave 3
	note Gs, 8
	octave 4
	note C_, 8
	note Ds, 8
	note F_, 8
	note F_, 1
	octave 3
	note As, 1
	note Gs, 1
	note As, 1
	octave 4
	note F_, 1
	octave 3
	note As, 1
	note Gs, 1
	note As, 1
	octave 4
	note Gs, 8
	note Gs, 1
	note F_, 1
	note D_, 1
	octave 3
	note B_, 1
	octave 4
	note F_, 1
	note D_, 1
	octave 3
	note B_, 1
	note Gs, 1
	note_type 6, 11, 7
	sound_call gbs_kantowildbattle_Ch2.sub3
	transpose 0, 1
	sound_call gbs_kantowildbattle_Ch2.sub3
	transpose 0, 0
	sound_call gbs_kantowildbattle_Ch2.sub4
	octave 2
	note C_, 2
	rest 2
	octave 3
	note G_, 4
	octave 2
	note C_, 2
	rest 2
	note C_, 2
	rest 2
	octave 4
	note C_, 4
	octave 2
	note C_, 2
	rest 2
	octave 4
	note Ds, 4
	octave 2
	note C_, 2
	rest 2
	octave 4
	note Cs, 4
	octave 2
	note Cs, 2
	rest 2
	note Cs, 2
	rest 2
	octave 4
	note Cs, 4
	octave 2
	note Cs, 2
	rest 2
	note Cs, 2
	rest 2
	octave 4
	note Cs, 4
	octave 2
	note Cs, 2
	rest 2
	note Cs, 2
	rest 2
	octave 4
	note Cs, 4
	octave 2
	note Cs, 2
	rest 2
	note Cs, 2
	rest 2
	octave 4
	note Cs, 4
	octave 2
	note Cs, 2
	rest 2
	octave 4
	note F_, 4
	octave 2
	note Cs, 2
	rest 2
	sound_call gbs_kantowildbattle_Ch2.sub4
	sound_call gbs_kantowildbattle_Ch2.sub5
	sound_call gbs_kantowildbattle_Ch2.sub4
	sound_call gbs_kantowildbattle_Ch2.sub5
	transpose 0, 1
	sound_call gbs_kantowildbattle_Ch2.sub4
	transpose 0, 0
	note Cs, 2
	rest 2
	octave 3
	note Gs, 4
	octave 2
	note Cs, 2
	rest 2
	note Cs, 2
	rest 2
	octave 4
	note Cs, 4
	octave 2
	note Cs, 2
	rest 2
	octave 3
	note As, 4
	octave 2
	note Cs, 2
	rest 2
	sound_call gbs_kantowildbattle_Ch2.sub4
	note C_, 2
	rest 2
	octave 3
	note G_, 4
	octave 2
	note C_, 2
	rest 2
	note C_, 2
	rest 2
	octave 4
	note C_, 4
	octave 2
	note C_, 2
	rest 2
	octave 3
	note As, 4
	octave 2
	note C_, 2
	rest 2
	sound_loop 0, gbs_kantowildbattle_Ch2.mainloop

gbs_kantowildbattle_Ch2.sub1:
	octave 2
	note C_, 1
	rest 2
	note C_, 1
	octave 1
	note G_, 1
	rest 1
	octave 2
	note C_, 1
	rest 1
	octave 3
	note C_, 2
	octave 2
	note C_, 1
	rest 1
	octave 1
	note G_, 1
	rest 2
	note G_, 1
	octave 2
	note C_, 3
	note C_, 1
	octave 1
	note G_, 2
	octave 2
	note C_, 2
	octave 1
	note G_, 2
	octave 2
	note Fs, 2
	octave 1
	note G_, 2
	octave 2
	note G_, 2
	note Cs, 1
	rest 2
	note Cs, 1
	octave 1
	note Gs, 1
	rest 1
	octave 2
	note Cs, 1
	rest 1
	octave 3
	note Cs, 1
	rest 1
	octave 2
	note Cs, 2
	octave 1
	note Gs, 1
	rest 2
	note Gs, 1
	octave 2
	note Cs, 1
	rest 2
	note Cs, 1
	octave 1
	note Gs, 1
	rest 1
	octave 2
	note Cs, 1
	rest 1
	octave 1
	note G_, 2
	sound_ret

gbs_kantowildbattle_Ch2.sub2:
	octave 2
	note C_, 2
	rest 4
	note C_, 1
	rest 1
	note C_, 2
	octave 3
	note C_, 2
	octave 2
	note C_, 4
	rest 2
	note C_, 2
	rest 2
	note C_, 2
	octave 3
	note C_, 2
	rest 2
	octave 2
	note C_, 4
	sound_ret

gbs_kantowildbattle_Ch2.sub3:
	octave 2
	note C_, 2
	rest 4
	note C_, 2
	rest 4
	octave 1
	note G_, 1
	rest 1
	note G_, 1
	rest 1
	octave 2
	note E_, 2
	rest 2
	note E_, 2
	rest 2
	note E_, 2
	note C_, 6
	note C_, 2
	rest 4
	note C_, 2
	octave 1
	note G_, 2
	octave 2
	note E_, 2
	note C_, 2
	octave 1
	note G_, 2
	octave 2
	note C_, 2
	rest 4
	note C_, 2
	note E_, 2
	note G_, 2
	note B_, 2
	octave 3
	note C_, 2
	sound_ret

gbs_kantowildbattle_Ch2.sub4:
	octave 3
	note G_, 4
	octave 2
	note C_, 2
	rest 2
	note C_, 2
	rest 2
	octave 3
	note G_, 4
	octave 2
	note C_, 2
	rest 2
	note C_, 2
	rest 2
	octave 3
	note G_, 4
	octave 2
	note C_, 2
	rest 2
	sound_ret

gbs_kantowildbattle_Ch2.sub5:
	note C_, 2
	rest 2
	octave 3
	note G_, 4
	octave 2
	note C_, 2
	rest 2
	note C_, 2
	rest 2
	octave 3
	note G_, 4
	octave 2
	note C_, 2
	rest 2
	octave 3
	note G_, 4
	octave 2
	note C_, 2
	rest 2
	sound_ret

gbs_kantowildbattle_Ch3:
	gbs_switch 2
	vibrato 20, 2, 3
	note_type 12, 1, 4
	octave 3
	note C_, 1
	rest 1
	note C_, 1
	octave 4
	note C_, 1
	octave 3
	note Cs, 1
	rest 1
	note Cs, 1
	octave 4
	note Cs, 1
	octave 3
	note D_, 1
	rest 1
	note D_, 1
	octave 4
	note D_, 1
	octave 3
	note Ds, 1
	rest 1
	note Ds, 1
	octave 4
	note Ds, 1
	octave 3
	note E_, 1
	rest 1
	note E_, 1
	octave 4
	note E_, 1
	octave 3
	note F_, 1
	rest 1
	note F_, 1
	octave 4
	note F_, 1
	octave 3
	note Fs, 1
	rest 1
	note Fs, 1
	octave 4
	note Fs, 1
	octave 3
	note G_, 1
	rest 1
	note G_, 1
	octave 4
	note G_, 1
gbs_kantowildbattle_Ch3.mainloop:
	note_type 12, 1, 4
	octave 5
	note G_, 1
	rest 2
	octave 4
	note G_, 1
	rest 2
	octave 5
	note G_, 1
	rest 3
	octave 4
	note G_, 1
	rest 1
	octave 5
	note G_, 1
	rest 2
	octave 4
	note G_, 1
	octave 3
	note G_, 1
	note B_, 1
	octave 4
	note C_, 1
	note D_, 1
	note Ds, 6
	octave 5
	note Ds, 2
	rest 2
	note G_, 2
	note Gs, 1
	rest 2
	octave 4
	note Gs, 1
	rest 2
	octave 5
	note Gs, 1
	rest 3
	octave 4
	note Gs, 1
	rest 1
	octave 5
	note Gs, 1
	rest 2
	octave 4
	note Gs, 1
	octave 6
	note Cs, 6
	octave 5
	note Gs, 1
	note F_, 1
	note B_, 1
	note G_, 1
	note F_, 1
	note D_, 1
	note G_, 1
	note F_, 1
	note D_, 1
	octave 4
	note B_, 1
	octave 5
	note G_, 1
	rest 2
	octave 4
	note G_, 1
	rest 2
	octave 5
	note G_, 1
	rest 3
	octave 4
	note G_, 1
	rest 1
	octave 5
	note G_, 1
	rest 2
	octave 4
	note G_, 1
	note C_, 1
	note D_, 1
	note Ds, 1
	note F_, 1
	note G_, 6
	octave 5
	note Ds, 2
	rest 2
	note G_, 2
	note Gs, 1
	rest 2
	octave 4
	note G_, 1
	rest 2
	octave 5
	note Gs, 1
	rest 3
	octave 4
	note G_, 1
	rest 1
	octave 5
	note Gs, 1
	rest 2
	octave 4
	note G_, 1
	note Cs, 4
	note Gs, 4
	octave 5
	note F_, 7
	note Fs, 1
	note G_, 2
	volume_envelope 2, 4
	note C_, 1
	octave 4
	note G_, 1
	octave 5
	note C_, 1
	octave 4
	note G_, 1
	volume_envelope 1, 4
	octave 5
	note Fs, 2
	volume_envelope 2, 4
	note C_, 1
	octave 4
	note G_, 1
	octave 5
	note C_, 1
	octave 4
	note G_, 1
	volume_envelope 1, 4
	octave 5
	note E_, 2
	volume_envelope 2, 4
	note C_, 1
	octave 4
	note G_, 1
	volume_envelope 1, 4
	octave 5
	note G_, 2
	volume_envelope 2, 4
	note C_, 1
	octave 4
	note G_, 1
	octave 5
	note C_, 1
	octave 4
	note G_, 1
	volume_envelope 1, 4
	octave 5
	note A_, 2
	volume_envelope 2, 4
	note C_, 1
	octave 4
	note G_, 1
	octave 5
	note C_, 1
	octave 4
	note G_, 1
	volume_envelope 1, 4
	octave 5
	note G_, 2
	volume_envelope 2, 4
	note C_, 1
	octave 4
	note Gs, 1
	volume_envelope 1, 4
	octave 5
	note Gs, 12
	note G_, 2
	note F_, 2
	note Gs, 2
	note G_, 2
	note Cs, 1
	note F_, 1
	note Gs, 1
	octave 6
	note C_, 1
	note Cs, 8
	octave 5
	note C_, 2
	volume_envelope 2, 4
	octave 4
	note E_, 1
	note G_, 1
	note E_, 1
	note G_, 1
	volume_envelope 1, 4
	note As, 2
	volume_envelope 2, 4
	note E_, 1
	note G_, 1
	note E_, 1
	note G_, 1
	volume_envelope 1, 4
	note Gs, 2
	volume_envelope 2, 4
	note E_, 1
	note G_, 1
	volume_envelope 1, 4
	octave 5
	note Cs, 2
	volume_envelope 2, 4
	octave 4
	note E_, 1
	note G_, 1
	note E_, 1
	note G_, 1
	volume_envelope 1, 4
	octave 5
	note C_, 2
	volume_envelope 2, 4
	octave 4
	note E_, 1
	note G_, 1
	note E_, 1
	note G_, 1
	volume_envelope 1, 4
	note As, 2
	volume_envelope 2, 4
	note E_, 1
	note G_, 1
	volume_envelope 1, 4
	octave 5
	note F_, 2
	volume_envelope 2, 4
	octave 4
	note G_, 1
	octave 5
	note C_, 1
	octave 4
	note G_, 1
	octave 5
	note C_, 1
	volume_envelope 1, 4
	note E_, 2
	volume_envelope 2, 4
	octave 4
	note G_, 1
	octave 5
	note C_, 1
	octave 4
	note G_, 1
	octave 5
	note C_, 1
	volume_envelope 1, 4
	note D_, 2
	volume_envelope 2, 4
	octave 4
	note G_, 1
	octave 5
	note C_, 1
	volume_envelope 1, 4
	octave 4
	note As, 4
	octave 5
	note C_, 4
	note D_, 4
	note F_, 4
	note Gs, 16
	note_type 6, 1, 4
	note Gs, 1
	rest 1
	volume_envelope 2, 4
	note Gs, 1
	rest 1
	volume_envelope 3, 4
	note Gs, 1
	rest 1
	note Gs, 1
	rest 1
	note Gs, 1
	rest 1
	note Gs, 1
	rest 1
	volume_envelope 2, 4
	note Gs, 1
	rest 1
	note Gs, 1
	rest 1
	note Gs, 1
	rest 1
	note Gs, 1
	rest 1
	volume_envelope 1, 4
	note Gs, 1
	rest 1
	note Gs, 1
	rest 1
	octave 6
	note Cs, 1
	rest 1
	note Cs, 1
	rest 1
	note Cs, 1
	rest 1
	note Cs, 1
	rest 1
	octave 5
	note G_, 2
	note F_, 2
	note E_, 2
	note F_, 2
	note_type 12, 1, 5
	note G_, 12
	note G_, 8
	note_type 6, 1, 5
	note G_, 1
	rest 1
	note G_, 1
	rest 1
	note G_, 1
	rest 1
	note G_, 1
	rest 1
	volume_envelope 2, 4
	note G_, 1
	rest 1
	note G_, 1
	rest 1
	volume_envelope 1, 4
	note G_, 1
	rest 1
	note G_, 1
	rest 1
	note_type 12, 1, 4
	octave 2
	note As, 16
	note As, 1
	rest 2
	note As, 1
	rest 2
	note As, 1
	rest 1
	octave 3
	note As, 1
	rest 2
	note As, 1
	rest 2
	note As, 1
	rest 1
	note C_, 1
	rest 2
	note_type 6, 1, 5
	note C_, 1
	rest 1
	note C_, 2
	octave 4
	note C_, 2
	octave 3
	note C_, 4
	rest 2
	note C_, 2
	rest 2
	note C_, 2
	octave 4
	note C_, 2
	rest 2
	octave 3
	note C_, 4
	note C_, 2
	rest 4
	note C_, 1
	rest 1
	note C_, 2
	octave 4
	note C_, 2
	octave 3
	note C_, 4
	rest 2
	note C_, 2
	rest 2
	note C_, 2
	octave 2
	note As, 2
	rest 2
	note As, 2
	rest 2
	note_type 12, 1, 4
	note Gs, 16
	note Gs, 16
	note As, 2
	rest 2
	note As, 1
	rest 3
	note As, 1
	rest 1
	octave 3
	note As, 1
	rest 1
	octave 2
	note As, 1
	rest 1
	octave 3
	note As, 1
	rest 1
	note D_, 2
	rest 2
	note D_, 1
	rest 3
	note D_, 1
	rest 1
	octave 4
	note D_, 1
	rest 1
	octave 2
	note B_, 1
	rest 1
	octave 3
	note B_, 1
	rest 1
	octave 5
	note E_, 4
	octave 4
	note C_, 1
	note E_, 1
	note G_, 1
	note B_, 1
	octave 5
	note C_, 1
	rest 1
	note E_, 1
	rest 5
	note F_, 2
	note E_, 1
	rest 1
	octave 4
	note C_, 1
	octave 3
	note G_, 1
	octave 4
	note C_, 1
	note E_, 1
	note G_, 1
	note E_, 1
	note C_, 1
	note E_, 1
	note G_, 1
	octave 5
	note C_, 1
	note E_, 1
	note G_, 1
	note F_, 4
	octave 4
	note Cs, 1
	note F_, 1
	note Gs, 1
	octave 5
	note C_, 1
	note Cs, 1
	rest 1
	note F_, 1
	rest 5
	note Gs, 2
	note G_, 1
	rest 5
	note F_, 8
	volume_envelope 1, 3
	note G_, 6
	note Fs, 6
	note E_, 2
	rest 2
	note G_, 6
	note A_, 6
	note G_, 2
	rest 2
	note Gs, 12
	note G_, 2
	note F_, 2
	note Gs, 2
	note G_, 2
	rest 4
	octave 6
	note Cs, 8
	octave 5
	note C_, 6
	octave 4
	note As, 6
	note Gs, 2
	rest 2
	octave 5
	note Cs, 6
	note C_, 6
	octave 4
	note As, 2
	rest 2
	octave 5
	note F_, 6
	note E_, 6
	note D_, 2
	rest 2
	octave 4
	note As, 4
	octave 5
	note C_, 4
	note D_, 4
	note F_, 4
	note Gs, 16
	note Gs, 16
	note G_, 16
	note G_, 16
	sound_loop 0, gbs_kantowildbattle_Ch3.mainloop

	.align 4
	.global gbs_kantowildbattle_Header
gbs_kantowildbattle_Header:
	.byte 3	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_kantowildbattle_Ch1
	.int gbs_kantowildbattle_Ch2
	.int gbs_kantowildbattle_Ch3
