;:================================================
;: 0-Nasm+Alink-w8.asm                 (c)Ded,2012
;:================================================

; nasm    "0-Nasm+Alink-w8.asm" -f obj -l "0-Nasm+Alink-w8.lst"
; alink   "0-Nasm+Alink-w8.obj" -oPE -c -subsys console
; ndisasm "0-Nasm+Alink-w8.exe" -b 32 -e 512 > "0-Nasm+Alink-w8.disasm"

; Hardcoded addrs are valid for Microsoft Windows [Version 6.2.8250] ONLY

section .code use32

..start:        push -11                ; STD_OUTPUT_HANDLE = -11
                mov eax, 7659a610h      ; GetStdHandle
                call eax                ; eax = stdout = GetStdHandle (STD_OUTPUT_HANDLE = -11)

                xor edx, edx
                push edx                ; Resvd = 0
                push edx                ; Ptr to number of chars written = NULL
                push 5                  ; sizeof ("Text\n")
                push dword MsgText
                push eax                ; stdout = GetStdHandle (STD_OUTPUT_HANDLE) 
                mov eax, 765ec780h      ; WriteConsoleA
                call eax                ; WriteConsoleA (stdout, MsgText, 5, NULL, 0)

                push 765990a2h          ; ExitProcess
                ret                     ; he-he

MsgText         db "Text", 0ah

 