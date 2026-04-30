	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_mobileadaptermenu_Ch1:
	gbs_switch 0
	tempo 168
	volume 7, 7
	pitch_offset 1
	stereo_panning FALSE, TRUE
	duty_cycle 2
	note_type 12, 6, 6
	rest 2
gbs_mobileadaptermenu_Ch1.mainloop:
	sound_call gbs_mobileadaptermenu_Ch1.sub1
	sound_call gbs_mobileadaptermenu_Ch1.sub2
	octave 3
	note Fs, 4
	note B_, 4
	note Fs, 2
	note B_, 1
	rest 1
	note Ds, 4
	sound_call gbs_mobileadaptermenu_Ch1.sub2
	octave 3
	note Fs, 2
	octave 2
	note B_, 2
	octave 3
	note Ds, 3
	note E_, 1
	note Ds, 8
	sound_call gbs_mobileadaptermenu_Ch1.sub1
	sound_loop 0, gbs_mobileadaptermenu_Ch1.mainloop

gbs_mobileadaptermenu_Ch1.sub1:
	octave 3
	note Gs, 7
	octave 4
	note E_, 1
	note Ds, 1
	rest 1
	octave 3
	note B_, 1
	rest 1
	note Fs, 4
	note E_, 8
	note Ds, 1
	rest 1
	note Cs, 1
	rest 1
	note Ds, 4
	note Gs, 7
	octave 4
	note E_, 1
	note Ds, 1
	rest 1
	octave 3
	note B_, 1
	rest 1
	note Fs, 4
	note A_, 2
	note E_, 2
	note A_, 3
	note A_, 1
	note Gs, 8
	sound_ret

gbs_mobileadaptermenu_Ch1.sub2:
	note E_, 1
	rest 1
	note A_, 1
	rest 1
	octave 4
	note Cs, 3
	octave 3
	note B_, 1
	note A_, 2
	octave 4
	note E_, 1
	rest 1
	note Cs, 4
	sound_ret

gbs_mobileadaptermenu_Ch2:
	gbs_switch 1
	stereo_panning TRUE, FALSE
	note_type 12, 8, 4
	duty_cycle 2
	octave 4
	note E_, 1
	note Gs, 1
gbs_mobileadaptermenu_Ch2.mainloop:
	sound_call gbs_mobileadaptermenu_Ch2.sub1
	note E_, 8
	sound_call gbs_mobileadaptermenu_Ch2.sub2
	note Ds, 2
	note Cs, 2
	note Ds, 3
	note E_, 1
	note Fs, 8
	sound_call gbs_mobileadaptermenu_Ch2.sub2
	note Ds, 2
	note E_, 2
	note Fs, 3
	note Gs, 1
	note Fs, 6
	note E_, 1
	note Gs, 1
	sound_call gbs_mobileadaptermenu_Ch2.sub1
	note E_, 6
	note E_, 1
	note Gs, 1
	sound_loop 0, gbs_mobileadaptermenu_Ch2.mainloop

gbs_mobileadaptermenu_Ch2.sub1:
	octave 4
	note B_, 1
	rest 1
	note B_, 1
	rest 1
	note A_, 3
	note Gs, 1
	note Fs, 1
	rest 1
	note Ds, 1
	rest 1
	octave 3
	note B_, 4
	octave 4
	note Cs, 2
	note Ds, 2
	note E_, 3
	note Gs, 1
	note Fs, 6
	note E_, 1
	note Gs, 1
	note B_, 1
	rest 1
	note B_, 1
	rest 1
	note A_, 3
	note Gs, 1
	note Fs, 1
	rest 1
	note Ds, 1
	rest 1
	octave 3
	note B_, 4
	octave 4
	note Cs, 2
	octave 3
	note B_, 2
	octave 4
	note Cs, 3
	note Ds, 1
	sound_ret

gbs_mobileadaptermenu_Ch2.sub2:
	note A_, 1
	rest 1
	note A_, 1
	rest 1
	note Gs, 3
	note Fs, 1
	note E_, 2
	note A_, 1
	rest 1
	note E_, 4
	sound_ret

gbs_mobileadaptermenu_Ch3:
	gbs_switch 2
	vibrato 8, 3, 4
	note_type 12, 2, 5
	rest 2
gbs_mobileadaptermenu_Ch3.mainloop:
	sound_call gbs_mobileadaptermenu_Ch3.sub1
	octave 2
	note B_, 1
	note Gs, 1
	sound_call gbs_mobileadaptermenu_Ch3.sub2
	octave 2
	note B_, 2
	rest 2
	octave 3
	note Fs, 2
	rest 1
	note Ds, 1
	note Fs, 2
	note Ds, 1
	rest 1
	octave 2
	note B_, 2
	note Fs, 1
	note Gs, 1
	sound_call gbs_mobileadaptermenu_Ch3.sub2
	octave 2
	note B_, 2
	rest 2
	octave 3
	note Fs, 2
	rest 1
	note Ds, 1
	octave 2
	note B_, 1
	rest 1
	octave 3
	note Ds, 1
	rest 1
	note Fs, 4
	sound_call gbs_mobileadaptermenu_Ch3.sub1
	rest 2
	sound_loop 0, gbs_mobileadaptermenu_Ch3.mainloop

gbs_mobileadaptermenu_Ch3.sub1:
	octave 3
	note E_, 2
	rest 2
	note B_, 2
	rest 1
	note Gs, 1
	note Ds, 1
	rest 1
	note B_, 1
	rest 1
	note Ds, 4
	note Cs, 2
	rest 2
	note A_, 2
	rest 1
	note Fs, 1
	octave 2
	note B_, 1
	rest 1
	octave 3
	note Ds, 1
	rest 1
	note Fs, 4
	note E_, 2
	rest 2
	note B_, 2
	rest 1
	note Gs, 1
	note Ds, 1
	rest 1
	note B_, 1
	rest 1
	note Ds, 4
	note Cs, 2
	rest 2
	note A_, 2
	rest 1
	note Cs, 1
	note E_, 3
	volume_envelope 3, 5
	note E_, 3
	volume_envelope 2, 5
	sound_ret

gbs_mobileadaptermenu_Ch3.sub2:
	note A_, 2
	rest 2
	octave 3
	note A_, 2
	rest 1
	note Cs, 1
	note A_, 2
	octave 4
	note Cs, 1
	rest 1
	octave 3
	note A_, 4
	sound_ret

	.align 4
	.global gbs_mobileadaptermenu_Header
gbs_mobileadaptermenu_Header:
	.byte 3	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_mobileadaptermenu_Ch1
	.int gbs_mobileadaptermenu_Ch2
	.int gbs_mobileadaptermenu_Ch3
