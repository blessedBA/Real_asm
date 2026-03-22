;:================================================
;: 1-ML+Link(1).asm                    (c)Ded,2012
;:================================================

; masm + link + WinAPI

; ml /c "1-ML+Link(1).asm" /Fl /Sa /Cp /Zi
; link  "1-ML+Link(1).obj" kernel32.lib user32.lib /subsystem:console

.model flat, stdcall
option casemap: none

;includelib kernel32.lib
GetStdHandle  proto :dword
WriteConsoleA proto :dword, :dword, :dword, :dword, :dword
ExitProcess   proto :dword

STD_OUTPUT_HANDLE equ -11d

;includelib user32.lib
MessageBoxA proto :dword, :dword, :dword, :dword

.code

Start:
;               invoke GetStdHandle, STD_OUTPUT_HANDLE

                push STD_OUTPUT_HANDLE  ; STD_OUTPUT_HANDLE = -11
                call GetStdHandle       ; eax = stdout = GetStdHandle (STD_OUTPUT_HANDLE = -11)

;               invoke WriteConsoleA, eax, offset MsgText, 5, 0, 0

                xor edx, edx
                push edx                ; Resvd = 0
                push edx                ; Ptr to number of chars written = NULL
                push 5                  ; strlen ("Text\n")
                push offset MsgText
                push eax                ; stdout = GetStdHandle (STD_OUTPUT_HANDLE) 
                call WriteConsoleA      ; WriteConsole (stdout, MsgText, 5, NULL, 0)
              
;               invoke MessageBoxA, 0, offset MsgText, offset MsgTitle, 0

                xor eax, eax
                push eax                ; MB_* flags = 0
                push offset MsgTitle
                push offset MsgText                  
                push eax                ; Parent HWND = NULL
                call MessageBoxA        ; MessageBoxA (NULL, MsgText, MsgTitle, 0)

;               invoke ExitProcess, 0

                xor eax, eax
                push eax                ; ExitCode = 0
                call ExitProcess        ; ExitProcess (0)

.data

MsgTitle        db "Title", 0ah, 0
MsgText         db "Text",  0ah, 0

end Start
