	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_rivalbattle_Ch1:
	gbs_switch 0
	tempo 102
	volume 7, 7
	duty_cycle 3
	pitch_offset 2
	vibrato 8, 1, 5
	note_type 12, 11, 2
	octave 3
	note Fs, 2
	note As, 4
	volume_envelope 11, 7
	note As, 10
	volume_envelope 11, 2
	note Fs, 2
	octave 4
	note Cs, 4
	volume_envelope 11, 7
	note Cs, 6
	note E_, 4
gbs_rivalbattle_Ch1.loop1:
	volume_envelope 11, 2
	octave 2
	note As, 6
	volume_envelope 11, 7
	octave 3
	note Cs, 6
	volume_envelope 11, 2
	note Ds, 4
	sound_loop 3, gbs_rivalbattle_Ch1.loop1
	volume_envelope 11, 2
	octave 2
	note As, 2
	octave 3
	note Cs, 4
	volume_envelope 11, 7
	note Cs, 10
gbs_rivalbattle_Ch1.loop2:
	volume_envelope 11, 2
	octave 3
	note Gs, 6
	volume_envelope 11, 7
	note B_, 6
	volume_envelope 11, 2
	octave 4
	note Cs, 4
	sound_loop 3, gbs_rivalbattle_Ch1.loop2
	volume_envelope 11, 2
	octave 3
	note Gs, 2
	note B_, 4
	volume_envelope 4, -5
	note B_, 10
gbs_rivalbattle_Ch1.mainloop:
	volume_envelope 11, 7
	note As, 6
	note Fs, 6
	note Ds, 4
	note F_, 4
	note Fs, 4
	note Gs, 2
	note As, 6
	volume_envelope 11, 2
	note F_, 1
	note Ds, 1
	note Cs, 1
	note Ds, 1
	volume_envelope 11, 7
	note F_, 4
	volume_envelope 11, 2
	note Gs, 1
	note Fs, 1
	note F_, 1
	note Fs, 1
	volume_envelope 11, 7
	note Gs, 4
	volume_envelope 11, 6
	note Gs, 2
	note As, 2
	note B_, 2
	note As, 2
	note B_, 2
	octave 4
	note Cs, 2
	octave 3
	note B_, 2
	octave 4
	note E_, 2
	volume_envelope 11, 7
	octave 3
	note As, 6
	note Fs, 6
	note As, 4
	octave 4
	note Cs, 4
	octave 3
	note B_, 4
	note As, 2
	note Gs, 6
	note F_, 6
	octave 4
	note Cs, 6
	octave 3
	note Gs, 4
	volume_envelope 11, 5
	note Cs, 2
	note F_, 2
	note Gs, 2
	octave 4
	note C_, 2
	note Cs, 2
	octave 3
	note Gs, 2
	note F_, 2
	note Gs, 2
	volume_envelope 11, 7
	note Fs, 10
	volume_envelope 11, 4
	octave 2
	note B_, 2
	octave 3
	note Ds, 2
	note Fs, 2
	volume_envelope 11, 7
	note F_, 4
	note Ds, 4
	note Cs, 2
	note Ds, 6
	volume_envelope 10, 0
	note F_, 8
	volume_envelope 10, 7
	note F_, 8
	volume_envelope 10, 0
	octave 2
	note As, 8
	volume_envelope 10, 7
	note As, 8
	volume_envelope 11, 7
	octave 3
	note Fs, 10
	volume_envelope 11, 5
	octave 2
	note B_, 2
	octave 3
	note Ds, 2
	note Fs, 2
	note F_, 2
	note Ds, 2
	note Cs, 2
	note Ds, 2
	note Gs, 2
	note Fs, 2
	note F_, 2
	note Gs, 2
	volume_envelope 10, 0
	note As, 16
	volume_envelope 10, 7
	note As, 16
	volume_envelope 10, 0
	note B_, 8
	volume_envelope 10, 7
	note B_, 4
	volume_envelope 11, 7
	note Gs, 4
	volume_envelope 11, 5
	octave 4
	note E_, 2
	note Ds, 2
	note Cs, 2
	octave 3
	note B_, 2
	octave 4
	note Fs, 2
	note E_, 2
	note Ds, 2
	note Cs, 2
gbs_rivalbattle_Ch1.loop3:
	octave 3
	note As, 2
	note E_, 2
	note As, 2
	octave 4
	note Ds, 2
	note E_, 2
	note Ds, 2
	octave 3
	note As, 2
	octave 4
	note Ds, 2
	octave 3
	note As, 2
	octave 4
	note Ds, 2
	note E_, 2
	note Ds, 2
	octave 3
	note As, 2
	note Ds, 2
	note As, 2
	octave 4
	note Ds, 2
	sound_loop 2, gbs_rivalbattle_Ch1.loop3
	volume_envelope 9, 4
	octave 3
	note Ds, 8
	octave 2
	note As, 8
	octave 3
	note G_, 8
	note F_, 8
	volume_envelope 9, 6
	octave 2
	note Gs, 8
	note As, 8
	note B_, 8
	octave 3
	note Cs, 8
	volume_envelope 11, 7
	octave 4
	note Ds, 8
	octave 3
	note As, 8
	octave 4
	note G_, 8
	note F_, 8
	octave 3
	note Gs, 8
	note As, 8
	note B_, 8
	octave 4
	note Cs, 8
	volume_envelope 10, 0
	note Ds, 8
	volume_envelope 10, 7
	note Ds, 8
	volume_envelope 10, 0
	octave 3
	note G_, 8
	volume_envelope 10, 7
	note G_, 8
	volume_envelope 11, 7
	note Ds, 8
	note Cs, 8
	note Ds, 4
	note Cs, 4
	octave 2
	note B_, 4
	octave 3
	note Cs, 4
	volume_envelope 12, 7
	octave 2
	note As, 6
	octave 3
	note Cs, 6
	note Ds, 4
	note E_, 6
	note Ds, 6
	note Cs, 4
	note Gs, 6
	note E_, 6
	note Ds, 4
	note Cs, 6
	note Ds, 6
	note D_, 4
	octave 2
	note Gs, 6
	note B_, 6
	octave 3
	note Cs, 4
	note D_, 6
	note Cs, 6
	octave 2
	note B_, 4
	octave 3
	note Fs, 6
	note D_, 6
	note Cs, 4
	octave 2
	note B_, 6
	octave 3
	note Cs, 10
	sound_loop 0, gbs_rivalbattle_Ch1.mainloop

gbs_rivalbattle_Ch2:
	gbs_switch 1
	duty_cycle 3
	vibrato 8, 3, 6
	pitch_offset 1
	note_type 12, 12, 2
	octave 4
	note E_, 1
	note Ds, 1
	note D_, 1
	note Cs, 1
	note D_, 1
	note Cs, 1
	note C_, 1
	octave 3
	note B_, 1
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
	volume_envelope 12, 2
	octave 4
	note Ds, 6
	volume_envelope 12, 7
	octave 3
	note Fs, 6
	volume_envelope 12, 2
	note Gs, 4
gbs_rivalbattle_Ch2.loop1:
	volume_envelope 12, 2
	note Ds, 6
	volume_envelope 12, 7
	note Fs, 6
	volume_envelope 12, 2
	note Gs, 4
	sound_loop 2, gbs_rivalbattle_Ch2.loop1
	volume_envelope 12, 2
	note Ds, 2
	note Fs, 4
	volume_envelope 12, 7
	note Fs, 8
	volume_envelope 10, 2
	note B_, 1
	octave 4
	note C_, 1
gbs_rivalbattle_Ch2.loop2:
	volume_envelope 12, 2
	note Cs, 6
	volume_envelope 12, 7
	note E_, 6
	volume_envelope 12, 2
	note Fs, 4
	sound_loop 3, gbs_rivalbattle_Ch2.loop2
	volume_envelope 12, 2
	note Cs, 2
	note E_, 4
	volume_envelope 11, 0
	note E_, 4
	volume_envelope 11, 7
	note E_, 6
gbs_rivalbattle_Ch2.mainloop:
	sound_call gbs_rivalbattle_Ch2.sub1
	volume_envelope 11, 0
	note Gs, 8
	volume_envelope 11, 7
	note Gs, 8
	sound_call gbs_rivalbattle_Ch2.sub1
	volume_envelope 4, -6
	note Gs, 8
	volume_envelope 11, 7
	note Gs, 8
	volume_envelope 11, 0
	octave 3
	note B_, 10
	volume_envelope 11, 7
	note B_, 6
	volume_envelope 11, 0
	octave 4
	note Cs, 8
	octave 3
	note B_, 8
	volume_envelope 11, 0
	note As, 10
	volume_envelope 11, 7
	note As, 6
	volume_envelope 2, -7
	note Ds, 10
	volume_envelope 11, 7
	note Ds, 6
	volume_envelope 11, 0
	note B_, 10
	volume_envelope 11, 7
	note B_, 6
	volume_envelope 12, 7
	octave 4
	note Cs, 8
	octave 3
	note B_, 8
	volume_envelope 11, 0
	octave 4
	note Ds, 16
	volume_envelope 11, 7
	note Ds, 16
	volume_envelope 11, 0
	note E_, 4
	volume_envelope 11, 7
	note E_, 6
	volume_envelope 12, 7
	note E_, 2
	note Gs, 2
	note B_, 2
	octave 5
	note Cs, 8
	octave 4
	note B_, 8
	volume_envelope 11, 0
	note As, 10
	volume_envelope 11, 7
	note As, 6
	volume_envelope 11, 0
	note A_, 10
	volume_envelope 11, 7
	note A_, 6
	volume_envelope 11, 0
	note Gs, 10
	volume_envelope 11, 7
	note Gs, 6
	volume_envelope 11, 0
	note G_, 10
	volume_envelope 11, 7
	note G_, 6
	volume_envelope 10, 4
	octave 3
	note G_, 8
	note Ds, 8
	note As, 8
	note Gs, 8
	volume_envelope 10, 6
	octave 2
	note B_, 8
	octave 3
	note Cs, 8
	note Ds, 8
	note F_, 8
	volume_envelope 12, 7
	octave 4
	note G_, 8
	note Ds, 8
	note As, 8
	note Gs, 8
	octave 3
	note B_, 8
	octave 4
	note Cs, 8
	note Ds, 8
	note F_, 8
	volume_envelope 11, 0
	note G_, 16
	note Ds, 16
	octave 3
	note B_, 8
	note As, 8
	note Gs, 8
	volume_envelope 12, 7
	note F_, 8
gbs_rivalbattle_Ch2.loop3:
	volume_envelope 12, 2
	octave 3
	note As, 6
	volume_envelope 12, 7
	octave 4
	note Cs, 6
	volume_envelope 12, 2
	note Ds, 4
	sound_loop 3, gbs_rivalbattle_Ch2.loop3
	volume_envelope 12, 2
	octave 3
	note As, 2
	octave 4
	note Cs, 4
	volume_envelope 11, 7
	note Cs, 6
	volume_envelope 9, -2
	note Cs, 4
gbs_rivalbattle_Ch2.loop4:
	volume_envelope 12, 2
	octave 3
	note Gs, 6
	volume_envelope 12, 7
	note B_, 6
	volume_envelope 12, 2
	octave 4
	note Cs, 4
	sound_loop 3, gbs_rivalbattle_Ch2.loop4
	volume_envelope 12, 2
	octave 3
	note Gs, 2
	note B_, 4
	volume_envelope 12, 7
	note B_, 6
	volume_envelope 6, -2
	octave 4
	note D_, 4
	sound_loop 0, gbs_rivalbattle_Ch2.mainloop

gbs_rivalbattle_Ch2.sub1:
	volume_envelope 12, 7
	note Ds, 10
	volume_envelope 12, 4
	octave 3
	note As, 2
	octave 4
	note Ds, 2
	note Fs, 2
	volume_envelope 12, 5
	note F_, 4
	note Ds, 4
	volume_envelope 12, 2
	note Cs, 2
	volume_envelope 12, 7
	note Ds, 6
	volume_envelope 11, 0
	note F_, 8
	volume_envelope 11, 7
	note F_, 8
	sound_ret

gbs_rivalbattle_Ch3:
	gbs_switch 2
	note_type 12, 1, 9
	octave 3
	note Fs, 2
	note As, 2
	rest 2
	note As, 10
	octave 3
	note Fs, 2
	octave 4
	note Cs, 2
	rest 2
	note Cs, 6
	octave 3
	note Cs, 2
	note D_, 2
gbs_rivalbattle_Ch3.loop1:
	note Ds, 2
	note Cs, 2
	note Ds, 2
	note Fs, 4
	note E_, 2
	note Ds, 2
	note Cs, 2
	sound_loop 4, gbs_rivalbattle_Ch3.loop1
gbs_rivalbattle_Ch3.loop2:
	octave 3
	note Cs, 2
	octave 2
	note B_, 2
	octave 3
	note Cs, 2
	note E_, 4
	note D_, 2
	note Cs, 2
	octave 2
	note B_, 2
	sound_loop 3, gbs_rivalbattle_Ch3.loop2
	octave 3
	note Cs, 2
	note E_, 2
	note Cs, 2
	octave 2
	note B_, 4
	octave 3
	note C_, 2
	note Cs, 2
	note D_, 2
gbs_rivalbattle_Ch3.mainloop:
	sound_call gbs_rivalbattle_Ch3.sub1
	octave 2
	note As, 2
	octave 4
	note Cs, 2
	octave 2
	note As, 2
	octave 3
	note B_, 2
	octave 2
	note As, 2
	octave 3
	note As, 2
	octave 2
	note As, 2
	octave 3
	note Gs, 2
	sound_call gbs_rivalbattle_Ch3.sub2
	note Cs, 2
	note Gs, 2
	octave 4
	note Cs, 2
	octave 3
	note Gs, 4
	note Cs, 2
	note C_, 2
	octave 2
	note B_, 2
	sound_call gbs_rivalbattle_Ch3.sub1
	octave 2
	note As, 2
	octave 3
	note As, 2
	octave 2
	note As, 2
	octave 3
	note Gs, 2
	octave 2
	note As, 2
	octave 3
	note Fs, 2
	octave 2
	note As, 2
	octave 3
	note F_, 2
	sound_call gbs_rivalbattle_Ch3.sub2
gbs_rivalbattle_Ch3.loop3:
	note Cs, 2
	note Gs, 2
	sound_loop 4, gbs_rivalbattle_Ch3.loop3
	sound_call gbs_rivalbattle_Ch3.sub3
	note Gs, 2
	note Fs, 2
gbs_rivalbattle_Ch3.loop4:
	octave 2
	note As, 2
	octave 3
	note F_, 2
	sound_loop 4, gbs_rivalbattle_Ch3.loop4
	octave 2
	note As, 2
	octave 3
	note Fs, 2
	octave 2
	note As, 2
	octave 3
	note Fs, 2
	octave 2
	note As, 2
	octave 3
	note Fs, 2
	note F_, 2
	note Ds, 2
	sound_call gbs_rivalbattle_Ch3.sub3
	octave 2
	note B_, 2
	octave 3
	note D_, 2
	sound_call gbs_rivalbattle_Ch3.sub4
	octave 3
	note Ds, 2
	octave 4
	note Ds, 2
	sound_call gbs_rivalbattle_Ch3.sub4
	octave 3
	note Ds, 2
	note As, 2
	note E_, 2
	note B_, 2
	octave 4
	note E_, 2
	octave 3
	note E_, 2
	note B_, 2
	octave 4
	note E_, 2
	octave 3
	note E_, 2
	octave 4
	note E_, 2
	octave 3
	note E_, 2
	note B_, 2
	octave 4
	note E_, 2
	octave 3
	note E_, 2
	note E_, 2
	note Fs, 2
	note G_, 2
	note Gs, 2
gbs_rivalbattle_Ch3.loop5:
	note Ds, 2
	note As, 2
	sound_loop 4, gbs_rivalbattle_Ch3.loop5
gbs_rivalbattle_Ch3.loop6:
	note Ds, 2
	note A_, 2
	sound_loop 4, gbs_rivalbattle_Ch3.loop6
gbs_rivalbattle_Ch3.loop7:
	note Ds, 2
	note Gs, 2
	sound_loop 4, gbs_rivalbattle_Ch3.loop7
gbs_rivalbattle_Ch3.loop8:
	note Ds, 2
	note G_, 2
	sound_loop 12, gbs_rivalbattle_Ch3.loop8
gbs_rivalbattle_Ch3.loop9:
	octave 2
	note B_, 2
	octave 3
	note Ds, 2
	sound_loop 4, gbs_rivalbattle_Ch3.loop9
gbs_rivalbattle_Ch3.loop10:
	octave 2
	note B_, 2
	octave 3
	note Fs, 2
	sound_loop 4, gbs_rivalbattle_Ch3.loop10
	note Ds, 2
	note G_, 2
	note As, 2
	note Ds, 2
	note G_, 2
	note As, 2
	note Ds, 2
	note As, 2
	note Ds, 2
	note G_, 2
	note As, 2
	note Ds, 2
	note G_, 2
	note As, 2
	note Ds, 2
	note As, 2
	octave 2
	note B_, 2
	octave 3
	note G_, 2
	note B_, 2
	octave 2
	note B_, 2
	octave 3
	note G_, 2
	note B_, 2
	octave 2
	note B_, 2
	octave 3
	note B_, 2
	octave 2
	note B_, 2
	octave 3
	note Gs, 2
	note B_, 2
	octave 2
	note B_, 2
	octave 4
	note Ds, 2
	note Cs, 2
	octave 3
	note B_, 2
	note Gs, 2
	note G_, 8
	note Ds, 8
	note As, 8
	note G_, 8
	octave 2
	note B_, 8
	octave 3
	note Cs, 8
	note Ds, 8
	note F_, 8
gbs_rivalbattle_Ch3.loop11:
	octave 2
	note As, 2
	octave 3
	note Ds, 2
	sound_loop 7, gbs_rivalbattle_Ch3.loop11
	note E_, 2
	note Ds, 2
gbs_rivalbattle_Ch3.loop12:
	octave 2
	note As, 2
	octave 3
	note Ds, 2
	sound_loop 6, gbs_rivalbattle_Ch3.loop12
	octave 2
	note As, 2
	octave 3
	note Fs, 2
	note F_, 2
	note E_, 2
gbs_rivalbattle_Ch3.loop13:
	octave 2
	note Gs, 2
	octave 3
	note Cs, 2
	sound_loop 7, gbs_rivalbattle_Ch3.loop13
	note D_, 2
	note Cs, 2
gbs_rivalbattle_Ch3.loop14:
	octave 2
	note Gs, 2
	octave 3
	note Cs, 2
	sound_loop 4, gbs_rivalbattle_Ch3.loop14
	octave 2
	note B_, 2
	note Gs, 2
	note B_, 2
	octave 3
	note F_, 4
	note E_, 2
	note Ds, 2
	note D_, 2
	sound_loop 0, gbs_rivalbattle_Ch3.mainloop

gbs_rivalbattle_Ch3.sub1:
gbs_rivalbattle_Ch3.sub1loop1:
	octave 2
	note As, 2
	octave 3
	note Ds, 2
	sound_loop 4, gbs_rivalbattle_Ch3.sub1loop1
	sound_ret

gbs_rivalbattle_Ch3.sub2:
	note Cs, 2
	note Gs, 2
	octave 4
	note Cs, 2
	octave 3
	note Gs, 4
	octave 4
	note Cs, 2
	octave 3
	note Cs, 2
	note Gs, 2
	sound_ret

gbs_rivalbattle_Ch3.sub3:
gbs_rivalbattle_Ch3.sub3loop1:
	octave 2
	note B_, 2
	octave 3
	note Fs, 2
	sound_loop 7, gbs_rivalbattle_Ch3.sub3loop1
	sound_ret

gbs_rivalbattle_Ch3.sub4:
gbs_rivalbattle_Ch3.sub4loop1:
	octave 3
	note Ds, 2
	note As, 2
	octave 4
	note Ds, 2
	sound_loop 2, gbs_rivalbattle_Ch3.sub4loop1
	sound_ret

	.align 4
	.global gbs_rivalbattle_Header
gbs_rivalbattle_Header:
	.byte 3	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_rivalbattle_Ch1
	.int gbs_rivalbattle_Ch2
	.int gbs_rivalbattle_Ch3
