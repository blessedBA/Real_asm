;:================================================
;: 1-Nasm+Ld.asm                       (c)Ded,2012
;:================================================

; nasm + ld + WinAPI

; nasm    "1-Nasm+Ld.asm" -f win32 -l "1-Nasm+Ld.lst"
; ld      "1-Nasm+Ld.obj" -o "1-Nasm+Ld.exe" libkernel32.a libuser32.a -e __start
; ndisasm "1-Nasm+Ld.exe" -b 32 -e 512 > "1-Nasm+Ld.disasm"

extern _GetStdHandle@4                  ; kernel32.dll
extern _WriteConsoleA@20                ; kernel32.dll
extern _ExitProcess@4                   ; kernel32.dll
extern _MessageBoxA@16                  ; user32.dll

global __start

section .text

__start:        push dword -11          ; STD_OUTPUT_HANDLE = -11
                call _GetStdHandle@4    ; stdout = GetStdHandle (-11)
                
                xor edx, edx
                push edx                ; Resvd = 0
                push edx                ; Ptr to number of chars written = NULL
                push 5                  ; strlen ("Text\n")
                push dword MsgText
                push eax                ; stdout = GetStdHandle (STD_OUTPUT_HANDLE) 
                call _WriteConsoleA@20  ; WriteConsole (stdout, msg, 5, NULL, 0)

                xor eax, eax
                push eax                ; MB_* flags = 0
                push dword MsgTitle
                push dword MsgText
                push eax                ; Parent HWND = NULL
                call _MessageBoxA@16    ; MessageBoxA (NULL, MsgText, MsgTitle, 0)

                xor eax, eax
                push eax                ; ExitCode = 0
                call _ExitProcess@4     ; ExitProcess (0)

MsgTitle        db "Title", 0ah, 0
MsgText         db "Text",  0ah, 0

