;:================================================
;: 1-Nasm+Alink.asm                    (c)Ded,2012
;:================================================

; nasm + alink + WinAPI

; nasm    "1-Nasm+Alink.asm" -f obj -l "1-Nasm+Alink.lst"
; alink   "1-Nasm+Alink.obj" -oPE -c -subsys console
; ndisasm "1-Nasm+Alink.exe" -b 32 -e 512 > "1-Nasm+Alink.disasm"

extern GetStdHandle
import GetStdHandle  kernel32.dll

extern WriteConsoleA
import WriteConsoleA kernel32.dll

extern ExitProcess
import ExitProcess   kernel32.dll

extern MessageBoxA
import MessageBoxA   user32.dll

section .code use32

..start:        push dword -11          ; STD_OUTPUT_HANDLE = -11
                call [GetStdHandle]     ; stdout = eax = GetStdHandle (STD_OUTPUT_HANDLE = -11)
                
                xor edx, edx
                push edx                ; Resvd = 0
                push edx                ; Ptr to number of chars written = NULL
                push 5                  ; strlen ("Text\n")
                push dword MsgText
                push eax                ; stdout = GetStdHandle (STD_OUTPUT_HANDLE) 
                call [WriteConsoleA]    ; WriteConsole (stdout, MsgText, 5, NULL, 0)

                xor eax, eax
                push eax                ; MB_* flags = 0
                push dword MsgTitle
                push dword MsgText
                push eax                ; Parent HWND = NULL
                call [MessageBoxA]      ; MessageBoxA (NULL, MsgText, MsgTitle, 0)

                xor eax, eax
                push eax                ; ExitCode = 0
                call [ExitProcess]      ; ExitProcess (0)

MsgTitle        db "Title", 0ah, 0
MsgText         db "Text",  0ah, 0

