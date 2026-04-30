	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_johtowildbattle_Ch1:
	gbs_switch 0
	tempo 104
	volume 7, 7
	duty_cycle 3
	pitch_offset 2
	vibrato 18, 1, 5
	.global gbs_johtowildbattle_Ch1.body
gbs_johtowildbattle_Ch1.body:
	note_type 12, 11, 2
	octave 4
	note C_, 1
	octave 3
	note B_, 1
	note As, 1
	note A_, 1
	note As, 1
	note A_, 1
	note Gs, 1
	note G_, 1
	note Gs, 1
	note G_, 1
	note Fs, 1
	note F_, 1
	note Fs, 1
	note F_, 1
	note E_, 1
	note Ds, 1
	note E_, 1
	note Ds, 1
	note D_, 1
	note Cs, 1
	note D_, 1
	note Cs, 1
	note C_, 1
	octave 2
	note B_, 1
	octave 3
	note C_, 1
	octave 2
	note B_, 1
	note As, 1
	note A_, 1
	note As, 1
	note B_, 1
	octave 3
	note C_, 1
	note Cs, 1
	volume_envelope 11, 2
	note G_, 6
	octave 2
	note As, 6
	octave 3
	note D_, 4
	note C_, 4
	note Cs, 4
	note D_, 8
	note Ds, 6
	octave 2
	note As, 6
	octave 3
	note Ds, 4
	note C_, 4
	note D_, 4
	volume_envelope 11, 5
	note Ds, 8
	volume_envelope 11, 2
	octave 4
	note D_, 6
	octave 3
	note As, 6
	octave 4
	note D_, 4
	note C_, 4
	note Cs, 4
	note D_, 8
	note Ds, 6
	octave 3
	note As, 6
	octave 4
	note Ds, 4
	note C_, 4
	note D_, 4
	volume_envelope 6, -7
	note Ds, 8
gbs_johtowildbattle_Ch1.mainloop:
	volume_envelope 11, 6
	octave 3
	note D_, 6
	octave 2
	note B_, 6
	note B_, 4
	octave 3
	note F_, 6
	note E_, 6
	note C_, 4
	note Gs, 8
	note As, 1
	note A_, 1
	note G_, 1
	note Fs, 1
	note G_, 1
	note Gs, 1
	note A_, 1
	note As, 1
	octave 4
	note C_, 8
	octave 3
	note B_, 1
	note As, 1
	note Gs, 1
	note G_, 1
	note Gs, 1
	note A_, 1
	note As, 1
	note B_, 1
	note D_, 6
	octave 2
	note B_, 6
	note B_, 4
	octave 3
	note F_, 6
	note E_, 6
	note D_, 4
	note E_, 8
	note D_, 8
	note C_, 8
	note F_, 8
	note Ds, 6
	note C_, 6
	note C_, 4
	note Fs, 6
	note F_, 6
	note Cs, 4
	note A_, 8
	note B_, 1
	note As, 1
	note Gs, 1
	note G_, 1
	note Gs, 1
	note A_, 1
	note As, 1
	note B_, 1
	octave 4
	note Cs, 8
	note C_, 1
	octave 3
	note B_, 1
	note A_, 1
	note Gs, 1
	note A_, 1
	note As, 1
	note B_, 1
	octave 4
	note C_, 1
	octave 3
	note Ds, 6
	note C_, 6
	note C_, 4
	note Fs, 6
	note F_, 6
	note Cs, 4
	note F_, 8
	note Ds, 8
	note Cs, 8
	note Fs, 8
	volume_envelope 11, 7
	note E_, 6
	note D_, 6
	note E_, 4
	note F_, 6
	note E_, 6
	note C_, 4
	note F_, 8
	note C_, 8
	note E_, 6
	note D_, 6
	note F_, 4
	note G_, 16
	octave 4
	note D_, 8
	note G_, 8
	note G_, 16
	note D_, 16
	octave 3
	note C_, 4
	note D_, 4
	note C_, 4
	octave 2
	note B_, 4
	octave 3
	note C_, 16
	note D_, 4
	note E_, 4
	note D_, 4
	note Fs, 4
	note G_, 16
	sound_loop 0, gbs_johtowildbattle_Ch1.mainloop

gbs_johtowildbattle_Ch2:
	gbs_switch 1
	duty_cycle 3
	vibrato 8, 3, 6
	pitch_offset 1
	sound_call gbs_johtowildbattle_Ch2.sub1
	note_type 12, 12, 2
	octave 4
	note G_, 6
	.global gbs_johtowildbattle_Ch2.body
gbs_johtowildbattle_Ch2.body:
	octave 3
	note D_, 6
	note G_, 4
	note F_, 4
	note Fs, 4
	note G_, 8
	note Gs, 6
	note D_, 6
	note Gs, 4
	note F_, 4
	note G_, 4
	volume_envelope 12, 7
	note Gs, 8
	volume_envelope 12, 2
	octave 4
	note G_, 6
	note D_, 6
	note G_, 4
	note F_, 4
	note Fs, 4
	note G_, 8
	note Gs, 6
	note D_, 6
	note Gs, 4
	note F_, 4
	note G_, 4
	volume_envelope 6, -7
	note Gs, 8
gbs_johtowildbattle_Ch2.mainloop:
	volume_envelope 12, 4
	octave 3
	note G_, 6
	note D_, 6
	note D_, 2
	note G_, 2
	octave 4
	note C_, 2
	octave 3
	note B_, 2
	note A_, 2
	note G_, 2
	note F_, 2
	note G_, 2
	note A_, 2
	octave 4
	note Cs, 2
	volume_envelope 11, 0
	note Ds, 16
	volume_envelope 11, 7
	note Ds, 16
	volume_envelope 12, 4
	octave 3
	note G_, 6
	note D_, 6
	note D_, 2
	note G_, 2
	octave 4
	note C_, 4
	octave 3
	note B_, 4
	note A_, 4
	note B_, 4
	volume_envelope 11, 0
	note A_, 16
	volume_envelope 11, 6
	note A_, 16
	volume_envelope 12, 4
	note Gs, 6
	note Ds, 6
	note Ds, 2
	note Gs, 2
	octave 4
	note Cs, 2
	note C_, 2
	octave 3
	note As, 2
	note Gs, 2
	note Fs, 2
	note Gs, 2
	note As, 2
	octave 4
	note D_, 2
	volume_envelope 11, 0
	note E_, 16
	volume_envelope 11, 7
	note E_, 16
	volume_envelope 12, 4
	octave 3
	note Gs, 6
	note Ds, 6
	note Ds, 2
	note Gs, 2
	octave 4
	note Cs, 4
	note C_, 4
	octave 3
	note As, 4
	note Gs, 4
	volume_envelope 11, 0
	note As, 16
	volume_envelope 11, 5
	note As, 16
	volume_envelope 12, 6
	octave 4
	note B_, 12
	note G_, 2
	note B_, 2
	octave 5
	note D_, 2
	note C_, 2
	octave 4
	note B_, 2
	note A_, 2
	note G_, 2
	note A_, 2
	note B_, 2
	note G_, 2
	note A_, 12
	octave 3
	note F_, 2
	note A_, 2
	octave 4
	note C_, 2
	octave 3
	note B_, 2
	note A_, 2
	note G_, 2
	note F_, 2
	note G_, 2
	note A_, 2
	octave 4
	note C_, 2
	volume_envelope 12, 7
	note D_, 16
	note G_, 8
	octave 5
	note C_, 8
	octave 4
	note B_, 16
	note G_, 16
	octave 3
	note E_, 4
	note Fs, 4
	note E_, 4
	note D_, 4
	note E_, 16
	note G_, 4
	note A_, 4
	note G_, 4
	note As, 4
	note B_, 16
	sound_loop 0, gbs_johtowildbattle_Ch2.mainloop

	.global gbs_johtowildbattle_Ch2.sub1
gbs_johtowildbattle_Ch2.sub1:
	note_type 12, 12, 2
	octave 4
	note F_, 1
	note Fs, 1
	note G_, 1
	octave 5
	note G_, 1
	octave 4
	note F_, 1
	note Fs, 1
	note G_, 1
	octave 5
	note G_, 1
	octave 4
	note F_, 1
	note Fs, 1
	note G_, 1
	octave 5
	note G_, 1
	octave 4
	note F_, 1
	note Fs, 1
	note G_, 1
	octave 5
	note G_, 1
	octave 4
	note F_, 1
	note Fs, 1
	note G_, 1
	octave 5
	note G_, 1
	octave 4
	note F_, 1
	note Fs, 1
	note G_, 1
	octave 5
	note G_, 1
	octave 4
	note F_, 1
	note Fs, 1
	note G_, 1
	octave 5
	note G_, 1
	octave 4
	note F_, 1
	note Fs, 1
	note G_, 1
	octave 5
	note G_, 1
	sound_ret

gbs_johtowildbattle_Ch3:
	gbs_switch 2
	note_type 12, 1, 4
	.global gbs_johtowildbattle_Ch3.body
gbs_johtowildbattle_Ch3.body:
	octave 4
	note G_, 2
	octave 5
	note D_, 2
	octave 4
	note G_, 2
	octave 5
	note Cs, 2
	octave 4
	note Fs, 2
	octave 5
	note C_, 2
	octave 4
	note Fs, 2
	note B_, 2
	note F_, 2
	note As, 2
	note F_, 2
	note A_, 2
	note F_, 2
	note D_, 2
	note G_, 2
	note F_, 2
	note D_, 2
	note G_, 2
	note D_, 2
	note G_, 2
	note D_, 2
	note G_, 2
	note D_, 2
	note G_, 2
	note D_, 2
	note G_, 2
	note D_, 2
	note G_, 2
	note D_, 2
	note E_, 2
	note F_, 2
	note G_, 2
	sound_call gbs_johtowildbattle_Ch3.sub1
	note Ds, 2
	note Gs, 2
	note Ds, 2
	note Gs, 2
	note Ds, 2
	note Ds, 2
	note G_, 2
	note F_, 2
gbs_johtowildbattle_Ch3.loop1:
	note D_, 2
	note G_, 2
	sound_loop 6, gbs_johtowildbattle_Ch3.loop1
	note D_, 2
	note E_, 2
	note F_, 2
	note G_, 2
	sound_call gbs_johtowildbattle_Ch3.sub1
	note F_, 2
	note F_, 2
	note G_, 2
	note G_, 2
	note Gs, 2
	note G_, 2
	note F_, 2
	note Ds, 2
gbs_johtowildbattle_Ch3.mainloop:
gbs_johtowildbattle_Ch3.loop2:
	note D_, 2
	note G_, 2
	sound_loop 7, gbs_johtowildbattle_Ch3.loop2
	note Fs, 4
	sound_call gbs_johtowildbattle_Ch3.sub1
	sound_call gbs_johtowildbattle_Ch3.sub1
gbs_johtowildbattle_Ch3.loop3:
	note D_, 2
	note G_, 2
	sound_loop 7, gbs_johtowildbattle_Ch3.loop3
	note D_, 2
	note A_, 2
gbs_johtowildbattle_Ch3.loop4:
	note C_, 2
	note F_, 2
	sound_loop 5, gbs_johtowildbattle_Ch3.loop4
	note E_, 2
	note D_, 2
	note C_, 2
	note D_, 2
	note E_, 2
	note F_, 2
	sound_call gbs_johtowildbattle_Ch3.sub1
	note Ds, 2
	note Gs, 2
	note Ds, 2
	note Gs, 2
	note Ds, 2
	note Gs, 2
	note G_, 4
gbs_johtowildbattle_Ch3.loop5:
	note E_, 2
	note A_, 2
	sound_loop 8, gbs_johtowildbattle_Ch3.loop5
	sound_call gbs_johtowildbattle_Ch3.sub1
	note Ds, 2
	note Gs, 2
	note Ds, 2
	note Gs, 2
	note Ds, 2
	note Gs, 2
	note Ds, 2
	note As, 2
	note Cs, 2
	note Fs, 2
	note Cs, 2
	note Fs, 2
	note Cs, 2
	note Fs, 2
	note Cs, 2
	note Fs, 2
	note Cs, 2
	note Fs, 2
	note F_, 2
	note Fs, 2
	note Gs, 2
	note Fs, 2
	note F_, 2
	note Ds, 2
gbs_johtowildbattle_Ch3.loop6:
	note D_, 2
	note G_, 2
	sound_loop 8, gbs_johtowildbattle_Ch3.loop6
gbs_johtowildbattle_Ch3.loop7:
	note C_, 2
	note F_, 2
	sound_loop 7, gbs_johtowildbattle_Ch3.loop7
	note E_, 2
	note C_, 2
	note D_, 4
	note G_, 4
	note D_, 4
	note G_, 4
gbs_johtowildbattle_Ch3.loop8:
	note D_, 2
	note G_, 2
	sound_loop 12, gbs_johtowildbattle_Ch3.loop8
gbs_johtowildbattle_Ch3.loop9:
	note C_, 2
	note E_, 2
	sound_loop 7, gbs_johtowildbattle_Ch3.loop9
	note F_, 2
	note Fs, 2
gbs_johtowildbattle_Ch3.loop10:
	note D_, 2
	note G_, 2
	sound_loop 6, gbs_johtowildbattle_Ch3.loop10
	note A_, 2
	note G_, 2
	note Fs, 2
	note E_, 2
	sound_loop 0, gbs_johtowildbattle_Ch3.mainloop

gbs_johtowildbattle_Ch3.sub1:
gbs_johtowildbattle_Ch3.sub1loop1:
	note Ds, 2
	note Gs, 2
	sound_loop 4, gbs_johtowildbattle_Ch3.sub1loop1
	sound_ret

	.align 4
	.global gbs_johtowildbattle_Header
gbs_johtowildbattle_Header:
	.byte 3	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_johtowildbattle_Ch1
	.int gbs_johtowildbattle_Ch2
	.int gbs_johtowildbattle_Ch3
