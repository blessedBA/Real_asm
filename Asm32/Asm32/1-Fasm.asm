;:================================================
;: 1-Fasm.asm                          (c)Ded,2012
;:================================================

; fasm + WinAPI + hand-made IAT

; fasm "1-Fasm.asm"

;:------------------------------------------------

format PE CONSOLE 4.0

entry Start

;:------------------------------------------------

macro           NOPs n { rept n \{ nop \} }

;:------------------------------------------------

STD_OUTPUT_HANDLE equ -11d

section '.text' data readable writeable executable
                    
Start:          NOPs 8

;               invoke GetStdHandle, STD_OUTPUT_HANDLE

                push STD_OUTPUT_HANDLE  ; STD_OUTPUT_HANDLE = -11
                call [GetStdHandle]     ; eax = stdout = GetStdHandle (STD_OUTPUT_HANDLE = -11)

;               invoke WriteConsoleA, eax, offset MsgText, 5, 0, 0

                xor edx, edx
                push edx                ; Resvd = 0
                push edx                ; Ptr to number of chars written = NULL
                push MsgTextLen         ; strlen (MsgText)
                push MsgText
                push eax                ; stdout = GetStdHandle (STD_OUTPUT_HANDLE) 
                call [WriteConsoleA]    ; WriteConsole (stdout, MsgText, 5, NULL, 0)
              
;               invoke MessageBoxA, 0, offset MsgText, offset MsgTitle, 0

                push 40h                ; MB_ICONINFORMATION
                push MsgTitle
                push MsgText                  
                push 0                  ; Parent HWND = NULL
                call [MessageBoxA]      ; MessageBoxA (NULL, MsgText, MsgTitle, 0)

;               invoke ExitProcess, 0

                xor eax, eax
                push eax                ; ExitCode = 0
                call [ExitProcess]      ; ExitProcess (0)

MsgTitle        db "MEOW", 0Ah, 0
MsgText         db 0Ah, "Cats forever!!!", 0Ah, 0
MsgTextLen      = $ - MsgText

                NOPs 8
                
;:================================================
;: IAT

section '.idata' import data readable writeable

                dd RVA Kernel32OrigFirstThunk, 0, 0, RVA Kernel32Name, RVA Kernel32FirstThunk
                dd RVA User32OrigFirstThunk,   0, 0, RVA User32Name,   RVA User32FirstThunk
                dd 0, 0, 0, 0, 0
               
;:------------------------------------------------

Kernel32Name    db 'KERNEL32.DLL',  0
User32Name      db 'USER32.DLL',    0

;:------------------------------------------------
Kernel32FirstThunk:

ExitProcess     dd RVA ExitProcessImp
GetStdHandle    dd RVA GetStdHandleImp
WriteConsoleA   dd RVA WriteConsoleAmp
                dd 0

Kernel32OrigFirstThunk:

ExitProcessTD   dd RVA ExitProcessImp
GetStdHandleTD  dd RVA GetStdHandleImp
WriteConsoleATD dd RVA WriteConsoleAmp
                dd 0

ExitProcessImp  dw 0
                db 'ExitProcess',   0

GetStdHandleImp dw 0
                db 'GetStdHandle',  0

WriteConsoleAmp dw 0
                db 'WriteConsoleA', 0

;:------------------------------------------------
User32FirstThunk:

MessageBoxA     dd RVA MessageBoxAImp
                dd 0
                              
User32OrigFirstThunk:

MessageBoxATD   dd RVA MessageBoxAImp
                dd 0

MessageBoxAImp  dw 0
                db 'MessageBoxA',   0

