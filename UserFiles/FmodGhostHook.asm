OPTION CASEMAP:NONE

EXTERN g_fmodGhostOriginal:QWORD
EXTERN FmodGhostAfterCall:PROC

.code

FmodGhostDetour PROC
    ; Entry RSP is 8 mod 16. Subtracting 168h makes it 16-byte aligned
    ; for all nested calls while leaving room for shadow space and saves.
    sub     rsp, 168h

    mov     [rsp + 020h], rcx
    mov     [rsp + 028h], rdx
    mov     [rsp + 030h], r8
    mov     [rsp + 038h], r9

    movdqu  xmmword ptr [rsp + 040h], xmm0
    movdqu  xmmword ptr [rsp + 050h], xmm1
    movdqu  xmmword ptr [rsp + 060h], xmm2
    movdqu  xmmword ptr [rsp + 070h], xmm3
    movdqu  xmmword ptr [rsp + 080h], xmm4
    movdqu  xmmword ptr [rsp + 090h], xmm5

    ; Restore the incoming volatile ABI state before calling the trampoline.
    mov     rcx, [rsp + 020h]
    mov     rdx, [rsp + 028h]
    mov     r8,  [rsp + 030h]
    mov     r9,  [rsp + 038h]
    movdqu  xmm0, xmmword ptr [rsp + 040h]
    movdqu  xmm1, xmmword ptr [rsp + 050h]
    movdqu  xmm2, xmmword ptr [rsp + 060h]
    movdqu  xmm3, xmmword ptr [rsp + 070h]
    movdqu  xmm4, xmmword ptr [rsp + 080h]
    movdqu  xmm5, xmmword ptr [rsp + 090h]
    call    qword ptr [g_fmodGhostOriginal]

    ; Preserve both common return paths before running C++ diagnostics.
    mov     [rsp + 0A0h], rax
    mov     [rsp + 0A8h], rdx
    movdqu  xmmword ptr [rsp + 0B0h], xmm0
    movdqu  xmmword ptr [rsp + 0C0h], xmm1

    mov     rcx, [rsp + 020h]
    mov     rdx, [rsp + 028h]
    mov     r8,  [rsp + 030h]
    mov     r9,  [rsp + 038h]
    call    FmodGhostAfterCall

    mov     rax, [rsp + 0A0h]
    mov     rdx, [rsp + 0A8h]
    movdqu  xmm0, xmmword ptr [rsp + 0B0h]
    movdqu  xmm1, xmmword ptr [rsp + 0C0h]

    add     rsp, 168h
    ret
FmodGhostDetour ENDP

END
