	.include "asm/macros.inc"

	.section .rodata
	.align 1


gbs_dancinghall_Ch1:
	gbs_switch 0
	tempo 208
	volume 7, 7
	stereo_panning FALSE, TRUE
	note_type 6, 11, 7
	rest 3
	duty_cycle 0
gbs_dancinghall_Ch1.mainloop:
	note_type 12, 11, 7
	sound_call gbs_dancinghall_Ch1.sub1
	rest 16
	sound_call gbs_dancinghall_Ch1.sub1
	rest 16
	rest 16
	rest 16
	volume_envelope 11, 1
	octave 2
	note B_, 1
	octave 3
	note D_, 1
	note F_, 1
	note A_, 1
	note B_, 1
	note A_, 1
	note B_, 1
	octave 4
	note D_, 1
	note F_, 2
	note_type 8, 11, 1
	note D_, 1
	note E_, 1
	note D_, 1
	octave 3
	note B_, 3
	note A_, 3
	note_type 12, 11, 1
	note B_, 1
	note A_, 1
	note D_, 1
	note E_, 1
	octave 4
	note F_, 2
	note_type 8, 11, 1
	octave 3
	note B_, 1
	octave 4
	note D_, 1
	octave 3
	note B_, 1
	note_type 12, 11, 5
	note A_, 1
	rest 1
	note B_, 1
	note B_, 1
	note A_, 1
	rest 1
	note F_, 2
	sound_loop 0, gbs_dancinghall_Ch1.mainloop

gbs_dancinghall_Ch1.sub1:
	octave 3
	note B_, 1
	rest 1
	note A_, 1
	rest 1
	note B_, 1
	rest 1
	note A_, 1
	rest 1
	octave 4
	note E_, 1
	rest 1
	note D_, 1
	rest 1
	octave 3
	note B_, 1
	rest 1
	octave 4
	note D_, 1
	rest 1
	sound_ret

gbs_dancinghall_Ch2:
	gbs_switch 1
	stereo_panning TRUE, FALSE
	note_type 6, 10, 1
	duty_cycle 0
	vibrato 16, 2, 4
	rest 3
gbs_dancinghall_Ch2.mainloop:
	note_type 6, 10, 2
	sound_call gbs_dancinghall_Ch2.sub1
	sound_call gbs_dancinghall_Ch2.sub1
	volume_envelope 10, 7
	octave 2
	note D_, 16
	note F_, 16
	note_type 12, 10, 7
	note E_, 16
	octave 3
	note F_, 1
	note A_, 1
	note B_, 1
	octave 4
	note D_, 1
	note E_, 1
	note D_, 1
	note E_, 1
	note A_, 1
	note B_, 2
	note_type 8, 10, 7
	note A_, 1
	note B_, 1
	note A_, 1
	note F_, 3
	note D_, 3
	note_type 12, 10, 7
	note E_, 1
	note D_, 1
	octave 3
	note A_, 1
	note B_, 1
	octave 4
	note A_, 2
	note_type 8, 10, 7
	note F_, 1
	note A_, 1
	note F_, 1
	note_type 12, 10, 7
	note E_, 1
	rest 1
	note F_, 1
	note F_, 1
	note E_, 1
	rest 1
	note D_, 2
	sound_loop 0, gbs_dancinghall_Ch2.mainloop

gbs_dancinghall_Ch2.sub1:
	volume_envelope 10, 1
	octave 4
	note E_, 4
	octave 2
	note E_, 4
	octave 4
	note E_, 4
	octave 2
	note E_, 4
	octave 4
	note B_, 4
	note A_, 4
	note F_, 4
	note A_, 4
	volume_envelope 3, 3
	note D_, 1
	note F_, 1
	volume_envelope 6, 3
	note D_, 1
	note F_, 1
	volume_envelope 9, 3
	note D_, 1
	note F_, 1
	volume_envelope 12, 3
	note D_, 1
	note F_, 1
	volume_envelope 14, 3
	note D_, 1
	note F_, 1
	volume_envelope 10, 3
	note D_, 1
	note F_, 1
	volume_envelope 8, 3
	note D_, 1
	note F_, 1
	volume_envelope 5, 3
	note D_, 1
	note F_, 1
	volume_envelope 7, 3
	octave 3
	note B_, 1
	octave 4
	note E_, 1
	volume_envelope 10, 3
	octave 3
	note B_, 1
	octave 4
	note E_, 1
	volume_envelope 11, 3
	octave 3
	note A_, 1
	octave 4
	note D_, 1
	volume_envelope 12, 3
	octave 3
	note A_, 1
	octave 4
	note D_, 1
	volume_envelope 13, 3
	octave 3
	note E_, 1
	note B_, 1
	volume_envelope 14, 3
	note E_, 1
	note B_, 1
	volume_envelope 15, 3
	note A_, 1
	octave 4
	note D_, 1
	volume_envelope 15, 3
	octave 3
	note A_, 1
	octave 4
	note D_, 1
	sound_ret

gbs_dancinghall_Ch3:
	gbs_switch 2
	stereo_panning TRUE, TRUE
	vibrato 22, 2, 4
	note_type 6, 1, 0
	octave 5
	note A_, 1
	note B_, 1
	octave 6
	note D_, 1
gbs_dancinghall_Ch3.mainloop:
	note E_, 13
	note D_, 1
	note E_, 1
	note A_, 1
	note B_, 16
	volume_envelope 1, 4
	octave 3
	note F_, 16
	note E_, 14
	volume_envelope 1, 0
	octave 6
	note E_, 1
	note F_, 1
	note E_, 13
	note D_, 1
	note E_, 1
	note A_, 1
	note B_, 16
	volume_envelope 1, 4
	octave 3
	note F_, 16
	note E_, 16
	volume_envelope 1, 3
	octave 4
	note F_, 2
	note A_, 2
	note B_, 2
	octave 5
	note D_, 2
	note E_, 2
	note D_, 2
	note E_, 2
	note A_, 2
	note As, 1
	note B_, 3
	note_type 8, 1, 3
	note A_, 1
	note B_, 1
	note A_, 1
	note F_, 3
	note D_, 3
	note_type 12, 1, 3
	note E_, 1
	note D_, 1
	octave 4
	note A_, 1
	note B_, 1
	octave 5
	note A_, 2
	note_type 8, 1, 3
	note F_, 1
	note A_, 1
	note F_, 1
	note_type 6, 1, 3
	note Ds, 1
	note E_, 3
	note D_, 4
	octave 4
	note B_, 4
	octave 5
	note D_, 4
	volume_envelope 1, 4
	octave 3
	note D_, 16
	note F_, 16
	note E_, 16
	note E_, 13
	volume_envelope 1, 0
	octave 5
	note A_, 1
	note B_, 1
	octave 6
	note D_, 1
	sound_loop 0, gbs_dancinghall_Ch3.mainloop

	.align 4
	.global gbs_dancinghall_Header
gbs_dancinghall_Header:
	.byte 3	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_dancinghall_Ch1
	.int gbs_dancinghall_Ch2
	.int gbs_dancinghall_Ch3
