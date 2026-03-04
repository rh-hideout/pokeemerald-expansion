    .section .rodata.ctf, "a", %progbits
    .align  2

    .global gCtfSecretPngMarkerStart
gCtfSecretPngMarkerStart:
    .asciz  "TEAM_ROCKET_NOTE_LETTER_START"

    .global gCtfSecretPng
gCtfSecretPng:
    .incbin "data/ctf/secret.png"

    .global gCtfSecretPngMarkerEnd
gCtfSecretPngMarkerEnd:
    .asciz  "TEAM_ROCKET_NOTE_LETTER_END"

    .align 2
