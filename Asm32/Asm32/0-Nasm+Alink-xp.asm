;:================================================
;: 0-Nasm+Alink-xp.asm                 (c)Ded,2012
;:================================================

; nasm    "0-Nasm+Alink-xp.asm" -f obj -l "0-Nasm+Alink-xp.lst"
; alink   "0-Nasm+Alink-xp.obj" -oPE -c -subsys console
; ndisasm "0-Nasm+Alink-xp.exe" -b 32 -e 512 > "0-Nasm+Alink-xp.disasm"

; Hardcoded addrs are valid for Microsoft Windows XP [Версия 5.1.2600] ONLY

section .code use32

..start:        push -11                ; STD_OUTPUT_HANDLE = -11
                mov eax, 7c810c89h      ; GetStdHandle
                call eax                ; eax = stdout = GetStdHandle (STD_OUTPUT_HANDLE = -11)

                xor edx, edx
                push edx                ; Resvd = 0
                push edx                ; Ptr to number of chars written = NULL
                push 5                  ; sizeof ("Text\n")
                push dword MsgText
                push eax                ; stdout = GetStdHandle (STD_OUTPUT_HANDLE) 
                mov eax, 7c81d355h      ; WriteConsoleA
                call eax                ; WriteConsoleA (stdout, MsgText, 5, NULL, 0)

                push 7c81d20ah          ; ExitProcess
                ret                     ; he-he

MsgText         db "Text", 0ah

 