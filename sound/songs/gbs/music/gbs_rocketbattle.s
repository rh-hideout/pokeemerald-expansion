	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_rocketbattle_Ch1:
	gbs_switch 0
	tempo 101
	volume 7, 7
	duty_cycle 3
	pitch_offset 2
	vibrato 16, 1, 5
	note_type 12, 11, 2
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
gbs_rocketbattle_Ch1.loop1:
	volume_envelope 11, 2
	octave 3
	note C_, 6
	note C_, 4
	note E_, 2
	volume_envelope 11, 7
	note D_, 4
	sound_loop 3, gbs_rocketbattle_Ch1.loop1
	volume_envelope 11, 2
	note C_, 6
	note C_, 6
	volume_envelope 11, 7
	note D_, 4
gbs_rocketbattle_Ch1.loop2:
	volume_envelope 11, 2
	octave 4
	note E_, 6
	note E_, 4
	note G_, 2
	volume_envelope 11, 7
	note F_, 4
	sound_loop 3, gbs_rocketbattle_Ch1.loop2
	volume_envelope 11, 2
	note E_, 6
	note E_, 4
	volume_envelope 11, 7
	note D_, 2
	note Ds, 4
	volume_envelope 11, 3
	octave 4
	note C_, 2
	octave 3
	note E_, 2
	note E_, 2
	note As, 2
	note F_, 2
	note F_, 2
	note A_, 2
	note D_, 2
	note D_, 2
	octave 4
	note C_, 2
	octave 3
	note E_, 2
	note E_, 2
	note A_, 2
	note E_, 2
	note D_, 2
	note E_, 2
	note F_, 2
	note E_, 2
	note F_, 2
	volume_envelope 11, 5
	note G_, 4
	volume_envelope 11, 3
	note G_, 2
	note F_, 2
	note Ds, 2
	note D_, 2
	note Cs, 2
	note D_, 2
	volume_envelope 11, 5
	note Ds, 4
	volume_envelope 11, 3
	note Ds, 2
	note D_, 2
	note F_, 2
gbs_rocketbattle_Ch1.mainloop:
	octave 4
	note E_, 2
	octave 3
	note E_, 2
	note E_, 2
	octave 4
	note D_, 2
	octave 3
	note F_, 2
	note F_, 2
	octave 4
	note C_, 2
	octave 3
	note D_, 2
	note D_, 2
	octave 4
	note E_, 2
	octave 3
	note E_, 2
	note E_, 2
	octave 4
	note D_, 2
	octave 3
	note E_, 2
	note D_, 2
	note E_, 2
	note F_, 2
	note E_, 2
	note F_, 2
	volume_envelope 11, 5
	note G_, 4
	volume_envelope 11, 3
	note G_, 2
	note F_, 2
	octave 4
	note C_, 2
	note D_, 2
	note C_, 2
	note D_, 2
	volume_envelope 11, 5
	note F_, 4
	volume_envelope 11, 2
	octave 3
	note F_, 2
	note G_, 2
	note Gs, 4
	volume_envelope 11, 5
	note D_, 4
	note C_, 4
	note D_, 4
	note E_, 2
	volume_envelope 11, 2
	note F_, 2
	note A_, 4
	volume_envelope 11, 7
	note A_, 4
	volume_envelope 11, 5
	note A_, 2
	note G_, 2
	note F_, 4
	note D_, 4
	note C_, 4
	note D_, 4
	note E_, 2
	note F_, 2
	note E_, 2
	note D_, 2
	note C_, 2
	note As, 2
	note G_, 2
	note A_, 2
	note As, 2
	volume_envelope 11, 7
	octave 4
	note E_, 6
	note D_, 4
	octave 3
	note G_, 2
	note As, 4
	note A_, 6
	note G_, 4
	note E_, 2
	note F_, 4
	note E_, 6
	note D_, 6
	note Ds, 4
	volume_envelope 10, 0
	note E_, 8
	volume_envelope 10, 7
	note E_, 8
	volume_envelope 11, 7
	octave 2
	note A_, 8
	note G_, 8
	note A_, 8
	note As, 8
	note A_, 8
	note G_, 8
	note A_, 8
	octave 3
	note Cs, 8
	note D_, 8
	note Cs, 8
	octave 2
	note As, 8
	note A_, 8
	octave 3
	note D_, 8
	note Cs, 8
	note D_, 8
	note E_, 8
	octave 2
	note As, 6
	octave 3
	note D_, 6
	note C_, 4
	volume_envelope 11, 5
	octave 2
	note As, 2
	octave 3
	note C_, 2
	note D_, 2
	note E_, 2
	note F_, 2
	note G_, 2
	note A_, 2
	note As, 2
	note A_, 2
	note E_, 2
	note A_, 2
	note As, 2
	note A_, 2
	note E_, 2
	note D_, 2
	note E_, 2
	note A_, 2
	note E_, 2
	note A_, 2
	octave 4
	note Cs, 2
	note D_, 2
	note Cs, 2
	octave 3
	note As, 2
	note G_, 2
	volume_envelope 11, 2
	note E_, 6
	note E_, 6
	note E_, 4
	note E_, 6
	note E_, 4
	volume_envelope 11, 7
	note G_, 2
	note F_, 4
	volume_envelope 11, 2
	note E_, 6
	note E_, 4
	volume_envelope 11, 7
	note G_, 2
	note F_, 4
	volume_envelope 11, 2
	note E_, 6
	octave 4
	note D_, 1
	note Ds, 1
	volume_envelope 10, 0
	note E_, 8
	volume_envelope 11, 2
	octave 3
	note F_, 6
	note F_, 4
	volume_envelope 11, 7
	note As, 2
	note G_, 4
gbs_rocketbattle_Ch1.loop3:
	volume_envelope 11, 2
	note F_, 6
	note F_, 4
	volume_envelope 11, 7
	note A_, 2
	note G_, 4
	sound_loop 2, gbs_rocketbattle_Ch1.loop3
	volume_envelope 11, 2
	note F_, 6
	octave 4
	note D_, 1
	note E_, 1
	volume_envelope 10, 0
	note F_, 8
	volume_envelope 11, 3
	note D_, 2
	octave 3
	note A_, 2
	note E_, 2
	note A_, 4
	note A_, 2
	volume_envelope 11, 7
	octave 4
	note D_, 4
	volume_envelope 11, 3
	note Ds, 2
	octave 3
	note As, 2
	note G_, 2
	note As, 4
	note As, 2
	volume_envelope 11, 7
	octave 4
	note D_, 4
	volume_envelope 11, 3
	note E_, 2
	note C_, 2
	octave 3
	note A_, 2
	octave 4
	note C_, 4
	note C_, 2
	volume_envelope 11, 7
	note Ds, 4
	volume_envelope 10, 0
	note E_, 4
	volume_envelope 10, 7
	note E_, 6
	volume_envelope 10, 0
	octave 3
	note Gs, 6
	volume_envelope 11, 3
	note C_, 2
	note E_, 2
	note E_, 2
	octave 2
	note As, 2
	octave 3
	note F_, 2
	note F_, 2
	octave 2
	note A_, 2
	octave 3
	note D_, 2
	note D_, 2
	note C_, 2
	note E_, 2
	note E_, 2
	octave 2
	note A_, 2
	octave 3
	note E_, 2
	note D_, 2
	note C_, 2
	note C_, 2
	octave 2
	note As, 2
	octave 3
	note C_, 2
	volume_envelope 11, 5
	note D_, 4
	volume_envelope 11, 3
	note D_, 2
	note C_, 2
	octave 2
	note As, 2
	octave 3
	note D_, 2
	note Cs, 2
	note D_, 2
	volume_envelope 11, 5
	note Ds, 4
	volume_envelope 11, 3
	note Ds, 2
	note D_, 2
	note F_, 2
	sound_loop 0, gbs_rocketbattle_Ch1.mainloop

gbs_rocketbattle_Ch2:
	gbs_switch 1
	duty_cycle 3
	vibrato 8, 3, 6
	pitch_offset 1
	note_type 12, 11, 2
	octave 4
	note A_, 4
	note As, 4
	note B_, 4
	octave 5
	note C_, 1
	volume_envelope 8, 2
	octave 4
	note Gs, 1
	note A_, 1
	note Gs, 1
	volume_envelope 12, 2
	octave 5
	note Cs, 1
	volume_envelope 9, 2
	octave 4
	note Gs, 1
	note A_, 1
	note Gs, 1
	volume_envelope 12, 2
	octave 5
	note D_, 1
	volume_envelope 10, 2
	octave 4
	note Gs, 1
	note A_, 1
	note Gs, 1
	volume_envelope 12, 2
	octave 5
	note Ds, 1
	volume_envelope 11, 2
	octave 4
	note Gs, 1
	note A_, 1
	note Gs, 1
	volume_envelope 12, 2
	octave 5
	note E_, 1
	octave 4
	note Gs, 1
	note A_, 1
	note Gs, 1
gbs_rocketbattle_Ch2.loop1:
	volume_envelope 12, 2
	octave 3
	note A_, 6
	note A_, 4
	octave 4
	note C_, 2
	volume_envelope 12, 7
	octave 3
	note As, 4
	sound_loop 3, gbs_rocketbattle_Ch2.loop1
	volume_envelope 12, 2
	note A_, 6
	note A_, 6
	volume_envelope 4, -2
	note Gs, 4
gbs_rocketbattle_Ch2.loop2:
	volume_envelope 12, 2
	octave 4
	note A_, 6
	note A_, 4
	octave 5
	note C_, 2
	volume_envelope 12, 7
	octave 4
	note As, 4
	sound_loop 3, gbs_rocketbattle_Ch2.loop2
	volume_envelope 12, 2
	note A_, 6
	note A_, 4
	volume_envelope 12, 7
	note G_, 2
	note Gs, 4
	sound_call gbs_rocketbattle_Ch2.sub1
	volume_envelope 11, 0
	note F_, 16
	volume_envelope 11, 7
	note F_, 16
gbs_rocketbattle_Ch2.mainloop:
	sound_call gbs_rocketbattle_Ch2.sub1
	volume_envelope 11, 0
	note F_, 8
	volume_envelope 11, 7
	note F_, 8
	volume_envelope 11, 0
	note As, 8
	volume_envelope 11, 7
	note As, 8
	volume_envelope 12, 4
	octave 3
	note A_, 2
	note G_, 2
	note A_, 2
	volume_envelope 12, 7
	octave 4
	note C_, 4
	octave 3
	note As, 2
	note A_, 2
	note G_, 2
	volume_envelope 12, 2
	note A_, 2
	octave 4
	note C_, 4
	volume_envelope 11, 0
	note C_, 6
	volume_envelope 11, 7
	note C_, 4
	volume_envelope 12, 4
	octave 3
	note As, 2
	note A_, 2
	note As, 2
	volume_envelope 12, 7
	octave 4
	note D_, 4
	note C_, 2
	octave 3
	note As, 2
	note A_, 2
	volume_envelope 12, 2
	note As, 2
	octave 4
	note D_, 4
	volume_envelope 11, 0
	note D_, 4
	volume_envelope 11, 7
	note D_, 6
	volume_envelope 4, -7
	note A_, 6
	volume_envelope 10, 0
	note G_, 6
	note F_, 4
	note E_, 6
	note F_, 6
	note G_, 4
	note A_, 6
	note As, 6
	note Gs, 4
	note A_, 6
	volume_envelope 10, 7
	note A_, 10
	volume_envelope 3, -7
	octave 3
	note D_, 8
	volume_envelope 11, 7
	note D_, 8
	volume_envelope 3, -7
	note Cs, 8
	volume_envelope 11, 7
	note Cs, 8
	volume_envelope 3, -7
	note D_, 8
	volume_envelope 11, 7
	note D_, 8
	volume_envelope 3, -7
	note E_, 8
	volume_envelope 11, 7
	note E_, 8
	volume_envelope 4, -6
	note F_, 8
	volume_envelope 10, 0
	note F_, 8
	note E_, 16
	note F_, 16
	note A_, 16
	volume_envelope 3, -7
	note F_, 16
	volume_envelope 12, 7
	octave 4
	note D_, 8
	note Cs, 8
	volume_envelope 11, 0
	note E_, 8
	volume_envelope 11, 7
	note E_, 8
	volume_envelope 3, -4
	note A_, 6
	volume_envelope 12, 7
	note A_, 10
	volume_envelope 12, 2
	octave 3
	note A_, 6
	note A_, 6
	note A_, 4
	note A_, 6
	note A_, 4
	volume_envelope 12, 7
	octave 4
	note C_, 2
	octave 3
	note As, 4
	volume_envelope 12, 2
	note A_, 6
	note A_, 4
	volume_envelope 12, 7
	octave 4
	note C_, 2
	octave 3
	note As, 4
	volume_envelope 12, 2
	note A_, 6
	volume_envelope 12, 7
	octave 4
	note G_, 1
	note Gs, 1
	note A_, 8
gbs_rocketbattle_Ch2.loop3:
	volume_envelope 12, 2
	octave 3
	note As, 6
	note As, 4
	volume_envelope 12, 7
	octave 4
	note D_, 2
	note C_, 4
	sound_loop 3, gbs_rocketbattle_Ch2.loop3
	volume_envelope 12, 2
	octave 3
	note As, 6
	volume_envelope 12, 7
	octave 4
	note G_, 1
	note A_, 1
	note As, 8
	volume_envelope 12, 7
	note A_, 6
	note G_, 6
	note A_, 4
	note As, 6
	octave 5
	note D_, 6
	octave 4
	note As, 4
	note A_, 6
	note G_, 6
	volume_envelope 12, 5
	note A_, 4
	volume_envelope 11, 0
	note A_, 8
	volume_envelope 11, 7
	note A_, 8
	volume_envelope 12, 6
	octave 3
	note A_, 6
	note Gs, 6
	note E_, 4
	note A_, 6
	note Gs, 6
	note E_, 4
	volume_envelope 11, 0
	note F_, 8
	volume_envelope 11, 7
	note F_, 8
	volume_envelope 3, -5
	note As, 8
	volume_envelope 12, 7
	note As, 8
	sound_loop 0, gbs_rocketbattle_Ch2.mainloop

gbs_rocketbattle_Ch2.sub1:
	volume_envelope 12, 6
	octave 4
	note A_, 6
	note Gs, 6
	note E_, 4
	note A_, 6
	note Gs, 6
	note E_, 4
	sound_ret

gbs_rocketbattle_Ch3:
	gbs_switch 2
	note_type 12, 1, 9
	octave 3
	note A_, 2
	octave 4
	note E_, 2
	octave 3
	note Gs, 2
	octave 4
	note E_, 2
	octave 3
	note G_, 2
	octave 4
	note E_, 2
	octave 3
	note Fs, 2
	octave 4
	note E_, 2
	octave 3
	note F_, 2
	octave 4
	note E_, 2
	octave 3
	note E_, 2
	octave 4
	note E_, 2
	octave 2
	note B_, 2
	octave 3
	note C_, 2
	octave 2
	note B_, 2
	note As, 2
gbs_rocketbattle_Ch3.loop1:
	sound_call gbs_rocketbattle_Ch3.sub1
	sound_loop 3, gbs_rocketbattle_Ch3.loop1
	octave 2
	note A_, 2
	octave 3
	note E_, 2
	note D_, 2
	octave 2
	note A_, 2
	octave 3
	note G_, 2
	note F_, 2
	note E_, 2
	note D_, 2
gbs_rocketbattle_Ch3.loop2:
	sound_call gbs_rocketbattle_Ch3.sub1
	sound_loop 3, gbs_rocketbattle_Ch3.loop2
	octave 2
	note A_, 2
	octave 3
	note E_, 2
	note D_, 2
	octave 2
	note A_, 2
	octave 3
	note G_, 2
	octave 2
	note G_, 2
	note A_, 2
	note As, 2
	sound_call gbs_rocketbattle_Ch3.sub2
	sound_call gbs_rocketbattle_Ch3.sub3
	octave 3
	note F_, 2
	sound_call gbs_rocketbattle_Ch3.sub4
gbs_rocketbattle_Ch3.mainloop:
	sound_call gbs_rocketbattle_Ch3.sub2
	sound_call gbs_rocketbattle_Ch3.sub3
	octave 3
	note As, 2
	octave 2
	note As, 2
	octave 3
	note F_, 2
	octave 2
	note As, 2
	octave 3
	note F_, 2
	octave 2
	note As, 2
	octave 3
	note F_, 2
	note E_, 2
	note D_, 2
	sound_call gbs_rocketbattle_Ch3.sub5
	octave 2
	note A_, 2
	octave 3
	note E_, 2
	note A_, 2
	octave 2
	note A_, 2
	octave 3
	note E_, 2
	note A_, 2
	octave 2
	note A_, 2
	octave 3
	note E_, 2
gbs_rocketbattle_Ch3.loop3:
	octave 2
	note As, 2
	octave 3
	note F_, 2
	sound_loop 5, gbs_rocketbattle_Ch3.loop3
	note As, 2
	octave 2
	note As, 2
	octave 3
	note F_, 2
	note As, 2
	octave 2
	note As, 2
	octave 3
	note As, 2
	sound_call gbs_rocketbattle_Ch3.sub5
	octave 2
	note A_, 2
	octave 3
	note E_, 2
	octave 2
	note A_, 2
	octave 3
	note E_, 2
	octave 2
	note A_, 2
	octave 3
	note F_, 2
	note E_, 2
	note D_, 2
	sound_call gbs_rocketbattle_Ch3.sub5
	sound_call gbs_rocketbattle_Ch3.sub5
gbs_rocketbattle_Ch3.loop4:
	octave 2
	note A_, 2
	octave 3
	note E_, 2
	note D_, 2
	octave 2
	note As, 2
	note A_, 2
	octave 3
	note D_, 2
	note G_, 2
	note F_, 2
	sound_loop 7, gbs_rocketbattle_Ch3.loop4
	octave 2
	note A_, 2
	octave 3
	note E_, 2
	note D_, 2
	octave 2
	note As, 2
	note A_, 2
	octave 3
	note A_, 2
	note G_, 2
	note F_, 2
gbs_rocketbattle_Ch3.loop5:
	octave 2
	note As, 2
	octave 3
	note F_, 2
	sound_loop 4, gbs_rocketbattle_Ch3.loop5
	octave 2
	note As, 2
	octave 3
	note F_, 2
	note G_, 2
	note F_, 2
	note E_, 2
	note D_, 2
	note Cs, 2
	note D_, 2
gbs_rocketbattle_Ch3.loop6:
	octave 2
	note A_, 2
	octave 3
	note E_, 2
	sound_loop 13, gbs_rocketbattle_Ch3.loop6
	octave 2
	note A_, 2
	octave 3
	note E_, 4
	note D_, 2
	note C_, 2
	octave 2
	note As, 2
gbs_rocketbattle_Ch3.loop7:
	octave 2
	note A_, 2
	octave 3
	note E_, 2
	sound_loop 4, gbs_rocketbattle_Ch3.loop7
	octave 2
	note A_, 2
	octave 4
	note D_, 2
	octave 3
	note A_, 2
	note As, 4
	note A_, 2
	note G_, 2
	note As, 2
gbs_rocketbattle_Ch3.loop8:
	octave 2
	note As, 2
	octave 3
	note F_, 2
	sound_loop 7, gbs_rocketbattle_Ch3.loop8
	note E_, 2
	note F_, 2
gbs_rocketbattle_Ch3.loop9:
	octave 2
	note As, 2
	octave 3
	note F_, 2
	sound_loop 5, gbs_rocketbattle_Ch3.loop9
	octave 3
	note As, 2
	octave 4
	note D_, 4
	note C_, 2
	octave 3
	note As, 2
	note G_, 2
	sound_call gbs_rocketbattle_Ch3.sub6
	octave 3
	note E_, 2
	sound_call gbs_rocketbattle_Ch3.sub3
	octave 3
	note F_, 2
	sound_call gbs_rocketbattle_Ch3.sub6
	octave 3
	note A_, 2
	octave 2
	note A_, 2
	octave 3
	note E_, 2
	octave 2
	note A_, 2
	octave 3
	note E_, 2
	octave 2
	note A_, 2
	octave 3
	note E_, 2
	octave 2
	note A_, 2
	octave 3
	note E_, 2
	sound_call gbs_rocketbattle_Ch3.sub2
	sound_call gbs_rocketbattle_Ch3.sub3
	octave 3
	note F_, 2
	sound_call gbs_rocketbattle_Ch3.sub4
	sound_loop 0, gbs_rocketbattle_Ch3.mainloop

gbs_rocketbattle_Ch3.sub1:
	octave 2
	note A_, 2
	octave 3
	note E_, 2
	note D_, 2
	octave 2
	note A_, 2
	note As, 2
	octave 3
	note E_, 2
	note G_, 2
	note F_, 2
	sound_ret

gbs_rocketbattle_Ch3.sub2:
	octave 2
	note A_, 2
	octave 3
	note E_, 2
	octave 2
	note A_, 2
	octave 3
	note E_, 2
	octave 2
	note A_, 2
	octave 3
	note E_, 2
	note Ds, 2
	note E_, 2
	octave 2
	note A_, 2
	octave 3
	note E_, 2
	octave 2
	note A_, 2
	octave 3
	note E_, 2
	octave 2
	note A_, 2
	octave 3
	note E_, 2
	note Ds, 2
	note D_, 2
	sound_ret

gbs_rocketbattle_Ch3.sub3:
	octave 2
	note As, 2
	octave 3
	note F_, 2
	note As, 2
	octave 2
	note As, 2
	octave 3
	note F_, 2
	note As, 2
	octave 2
	note As, 2
	sound_ret

gbs_rocketbattle_Ch3.sub4:
	octave 2
	note As, 2
	octave 3
	note F_, 2
	note As, 2
	note F_, 2
	note As, 2
	note F_, 2
	octave 2
	note As, 2
	octave 3
	note F_, 2
	sound_ret

gbs_rocketbattle_Ch3.sub5:
gbs_rocketbattle_Ch3.sub5loop1:
	octave 2
	note A_, 2
	octave 3
	note E_, 2
	sound_loop 4, gbs_rocketbattle_Ch3.sub5loop1
	sound_ret

gbs_rocketbattle_Ch3.sub6:
	octave 2
	note A_, 2
	octave 3
	note E_, 2
	note A_, 2
	octave 2
	note A_, 2
	octave 3
	note E_, 2
	note A_, 2
	octave 2
	note A_, 2
	sound_ret

	.align 4
	.global gbs_rocketbattle_Header
gbs_rocketbattle_Header:
	.byte 3	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_rocketbattle_Ch1
	.int gbs_rocketbattle_Ch2
	.int gbs_rocketbattle_Ch3
